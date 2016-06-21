
// original RenameMethod.cpp callbacks:


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

// main:
// original RenameMethod.cpp matchers (modified for current clang source):
//
//
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
