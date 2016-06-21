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

// original RenameMethod.cpp callbacks:
#if 0
// Implements a callback that replaces the calls for the AST
// nodes we matched.
class CallRenamer : public MatchFinder::MatchCallback {
   const char * inputName ;
   const char * replacementName ;
public:
   CallRenamer(Replacements *Replace, const char * const srcName, const char * const repName) : Replace(Replace), inputName(srcName), replacementName(repName) {}

   // This method is called every time the registered matcher matches
   // on the AST.
   virtual void run(const MatchFinder::MatchResult &Result) {
      const CallExpr *M = Result.Nodes.getStmtAs<CallExpr>(inputName);
      // We can assume M is non-null, because the ast matchers guarantee
      // that a node with this type was bound, as the matcher would otherwise
      // not match.

      if ( M )
      {
      Replace->insert(
         // Replacements are a source manager independent way to express
         // transformation on the source.
         Replacement(*Result.SourceManager,
                           // Replace the range of the member name...
                           CharSourceRange::getTokenRange(
                              SourceRange(M->getLocStart())),
                           // ... with:
                           replacementName));
      }
   }

private:
   // Replacements are the RefactoringTool's way to keep track of code
   // transformations, deduplicate them and apply them to the code when
   // the tool has finished with all translation units.
   Replacements *Replace;
};

// Implements a callback that replaces the decls for the AST
// nodes we matched.
class DeclRenamer : public MatchFinder::MatchCallback {
public:
   DeclRenamer(Replacements *Replace) : Replace(Replace) {}

   // This method is called every time the registered matcher matches
   // on the AST.
   virtual void run(const MatchFinder::MatchResult &Result) {
      const CXXMethodDecl *D = Result.Nodes.getDeclAs<CXXMethodDecl>("method");
      // We can assume D is non-null, because the ast matchers guarantee
      // that a node with this type was bound, as the matcher would otherwise
      // not match.

      Replace->insert(
         // Replacements are a source manager independent way to express
         // transformation on the source.
         Replacement(*Result.SourceManager,
                           // Replace the range of the declarator identifier...
                           CharSourceRange::getTokenRange(
                              SourceRange(D->getLocation())),
                           // ... with "Front".
                           "Front"));
   }

private:
   // Replacements are the RefactoringTool's way to keep track of code
   // transformations, deduplicate them and apply them to the code when
   // the tool has finished with all translation units.
   Replacements *Replace;
};
#endif

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
         replacement = InsertionText + replacement ;

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

#if 0
   voidPPCastStrippingModifier voidppCallBack(&Tool.getReplacements());
   Finder.addMatcher(
            callExpr( callee(functionDecl(hasName("sqlogmblk"))) ).bind("x"),
      &voidppCallBack);

#endif

   renameAndAddParamModifier renamerCallBack(&Tool.getReplacements(), 0, "lz_mutex_lock_extended", "0" );
   Finder.addMatcher(
            callExpr( callee(functionDecl(hasName("lz_mutex_lock"))) ).bind("y"),
      &renamerCallBack);

// original RenameMethod.cpp matchers (modified for current clang source):
#if 0
   Finder.addMatcher(
      // Match calls...
      memberCallExpr(
         // Where the callee is a method called "Get"...
         callee(methodDecl(hasName("Get"))),
         // ... and the class on which the method is called is derived
         // from ElementsBase ...
         thisPointerType(recordDecl(
            isDerivedFrom("ElementsBase"))),
         // ... and bind the member expression to the ID "member", under which
         // it can later be found in the callback.
         callee(id("member", memberExpr()))),
      &CallCallback);

   DeclRenamer DeclCallback(&Tool.getReplacements());
   Finder.addMatcher(
      // Match declarations...
      id("method", methodDecl(hasName("Get"),
                                    ofClass(isDerivedFrom("ElementsBase")))),
      &DeclCallback);

   Finder.addMatcher(
      // Match calls...
      memberCallExpr(
         // Where the callee is a method called "Get"...
         callee(methodDecl(hasName("Get"))),
         // ... and the class on which the method is called is derived
         // from ElementsBase ...
         thisPointerType(recordDecl(
            isDerivedFrom("ElementsBase"))),
         // ... and bind the member expression to the ID "member", under which
         // it can later be found in the callback.
         callee(id("member", memberExpr()))),
      &CallCallback);
#endif

   return Tool.runAndSave(newFrontendActionFactory(&Finder).get());
}
