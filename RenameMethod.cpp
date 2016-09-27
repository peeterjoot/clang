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
#include <unordered_map>

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
   renameAndAddParamModifier(Replacements *Replace, const int n, const std::string & replacement, const std::string & insertion )
      : Replace(Replace),
        InsertAfterParam{n},
        ReplacementFunctionName{replacement},
        InsertionText{insertion}
   {}

   // This method is called every time the registered matcher matches
   // on the AST.
   virtual void run(const MatchFinder::MatchResult &Result) {
      const CallExpr *M = Result.Nodes.getStmtAs<CallExpr>("y");
//      M->dump() ;
      const Expr * a = M->getArg( InsertAfterParam ) ;

      std::string replacement = decl2str( a, Result.SourceManager ) ; 

      if ( replacement.length() )
      {
//std::cerr << replacement << '\n' ;
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
   Replacements * Replace;

   int InsertAfterParam ;

   std::string ReplacementFunctionName ;
   std::string InsertionText ;
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

   std::unordered_map<std::string, int> replaceBaseNames {
      {"lz_mutex_lock", 0},       {"lz_mutex_unlock", 0},
      {"lz_mutex_trylock", 0},    {"lz_mutex_destroy", 0},
      {"lz_mutex_consistent", 0}, {"lz_cond_wait", 1},
      {"lz_cond_timedwait", 2},   {"lz_cond_broadcast", 0},
      {"lz_cond_destroy", 0},     {"lz_cond_init", 1},
      {"lz_cond_signal", 0}
   } ;

   using pRename = std::unique_ptr<renameAndAddParamModifier> ;

   // can't let the storage for these MatchCallback objects go out of scope 
   std::vector<pRename> callbacks ;

   for ( const auto & p : replaceBaseNames )
   {
      const auto & s = p.first ;
      const int n = p.second ;

      std::string e = s + "_extended" ;

      pRename r1( new renameAndAddParamModifier(&Tool.getReplacements(), n, e, ", LZ_OP_ABORT_ON_ERROR" ) ) ;

      Finder.addMatcher(
               callExpr( callee(functionDecl(hasName( s + "_or_abort" ))) ).bind("y"),
         r1.get());

      callbacks.push_back( std::move( r1 ) ) ;



      pRename r2( new renameAndAddParamModifier(&Tool.getReplacements(), n, e, ", 0" ) ) ;

      Finder.addMatcher(
               callExpr( callee(functionDecl(hasName( s ))) ).bind("y"),
         r2.get());

      callbacks.push_back( std::move( r2 ) ) ;
   }

   return Tool.runAndSave(newFrontendActionFactory(&Finder).get());
}
