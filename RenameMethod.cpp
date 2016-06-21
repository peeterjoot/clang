// forked basic infrastructure for a "renamer"
//
// from: http://llvm.org/svn/llvm-project/cfe/branches/tooling/examples/rename-method/RenameMethod.cpp
//
//=- examples/rename-method/RenameMethod.cpp ------------------------------===//
//
//===----------------------------------------------------------------------===//
//
// A small example tool that uses AST matchers to find calls to the Get() method
// in subclasses of ElementsBase and replaces them with calls to Front().
//
//===----------------------------------------------------------------------===//

#include "clang/ASTMatchers/ASTMatchers.h"
#include "clang/ASTMatchers/ASTMatchFinder.h"
#include "clang/Tooling/CompilationDatabase.h"
#include "clang/Tooling/Refactoring.h"
#include "llvm/Support/CommandLine.h"
#include "clang/Basic/SourceManager.h"
#include "clang/Lex/Lexer.h"
#include <iostream>

using namespace clang;
using namespace clang::ast_matchers;
using namespace clang::tooling;
using namespace llvm;

cl::opt<std::string> BuildPath(
   cl::Positional,
   cl::desc("<build-path>"));

cl::list<std::string> SourcePaths(
   cl::Positional,
   cl::desc("<source0> [... <sourceN>]"),
   cl::OneOrMore);


// http://stackoverflow.com/a/11154162/189270
std::string decl2str( const Expr *d, const SourceManager *sm )
{
   std::string r ;
   SourceLocation _b(d->getLocStart()), _e(d->getLocEnd());

   if ( _b.isValid() && _e.isValid() )
   {
      // This is the default LangOptions... not sure how to get the LangOptions that must have
      // been supplied in newFrontendActionFactory() somewhere along the way
      LangOptions lopt;

      SourceLocation b(clang::Lexer::GetBeginningOfToken(_b, *sm, lopt));
      SourceLocation e(clang::Lexer::getLocForEndOfToken(_e, 0, *sm, lopt));
  
      const char * bs ;
      const char * es ;
      ptrdiff_t d ;

      if ( b.isValid() && e.isValid() )
      {
         bs = sm->getCharacterData(b) ;
         es = sm->getCharacterData(e) ;
         d = es - bs ;
      }
      else
      {
         bs = sm->getCharacterData(_b) ;
         es = sm->getCharacterData(_e) ;
         d = es - bs + 1 ;
      }

      r = std::string( bs, d ) ;
  
      //std::cout << "e: " << r << std::endl ;
      //d->dump() ;
   }
   else if ( 0 )
   {
      std::cout << "x: " << r << std::endl ;
      d->dump() ;
      abort() ;
   }

   return r ;
}

class renameAndAddParamModifier : public MatchFinder::MatchCallback
{
public:
   renameAndAddParamModifier(Replacements *Replace, const int n, const char * replacement, const char * insertion )
      : Replace(Replace),
        InsertAfterParam{n},
        ReplacementFunctionName{replacement},
        InsertionText{insertion}
   {}

   // This method is called every time the registered matcher matches
   // on the AST.
   virtual void run(const MatchFinder::MatchResult &Result) {
      const CallExpr *M = Result.Nodes.getStmtAs<CallExpr>("y");
      M->dump() ;
      const Expr * a = M->getArg( InsertAfterParam ) ;

      std::string replacement = decl2str( a, Result.SourceManager ) ; 

      if ( replacement.length() )
      {
std::cerr << replacement << '\n' ;
         replacement = replacement + InsertionText ;

         // rename the function:
         Replace->insert(
            Replacement(*Result.SourceManager,
                              CharSourceRange::getTokenRange(
                                 SourceRange(M->getLocStart())),
                              ReplacementFunctionName));

         // and insert the additional param
         std::string orig = decl2str( a, Result.SourceManager ) ;

         Replace->insert(
            Replacement(*Result.SourceManager,
                              a->getLocStart(),
                              orig.length(),
                              replacement)
            ) ;
      }
   }

private:
   // Replacements are the RefactoringTool's way to keep track of code
   // transformations, deduplicate them and apply them to the code when
   // the tool has finished with all translation units.
   Replacements *Replace;

   int InsertAfterParam ;

   const char * ReplacementFunctionName ;
   const char * InsertionText ;
} ;


int main(int argc, const char **argv) 
{
   // First see if we can create the compile command line from the
   // positional parameters after "--".
   std::unique_ptr<CompilationDatabase> Compilations(
      FixedCompilationDatabase::loadFromCommandLine(argc, argv));

   // Do normal command line handling from the rest of the arguments.
   cl::ParseCommandLineOptions(argc, argv);

   if (!Compilations) {
      // If the caller didn't specify a compile command line to use, try to
      // load it from a build directory. For example when running cmake, use
      // CMAKE_EXPORT_COMPILE_COMMANDS=ON to prepare your build directory to
      // be useable with clang tools.
      std::string ErrorMessage;
      std::unique_ptr< CompilationDatabase > c{ CompilationDatabase::loadFromDirectory(BuildPath, ErrorMessage) } ;
      Compilations.swap( c ) ;
      if (!Compilations)
         llvm::report_fatal_error(ErrorMessage);
   }

   RefactoringTool Tool(*Compilations, SourcePaths);
   ast_matchers::MatchFinder Finder;

   renameAndAddParamModifier renamerCallBack(&Tool.getReplacements(), 0, "lz_mutex_lock_extended", ", 0" );
   Finder.addMatcher(
            callExpr( callee(functionDecl(hasName("lz_mutex_lock"))) ).bind("y"),
      &renamerCallBack);

   return Tool.runAndSave(newFrontendActionFactory(&Finder).get());
}
