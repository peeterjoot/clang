//------------------------------------------------------------------------------
// The main() for this code, and the MyASTConsumer, ASTConsumer classes that drive the underlying AST methods
// were forked from:{
//------------------------------------------------------------------------------
   //------------------------------------------------------------------------------
   // Tooling sample. Demonstrates:
   //
   // * How to write a simple source tool using libTooling.
   // * How to use RecursiveASTVisitor to find interesting AST nodes.
   // * How to use the Rewriter API to rewrite the source code.
   //
   // Eli Bendersky (eliben@gmail.com)
   // This code is in the public domain
   //------------------------------------------------------------------------------
#include <sstream>
#include <string>
#include <memory>
#include <iostream>

#include "clang/AST/AST.h"
#include "clang/AST/ASTConsumer.h"
#include "clang/AST/RecursiveASTVisitor.h"
#include "clang/Frontend/ASTConsumers.h"
#include "clang/Frontend/FrontendActions.h"
#include "clang/Frontend/CompilerInstance.h"
#include "clang/Tooling/CommonOptionsParser.h"
#include "clang/Tooling/Tooling.h"
#include "clang/Rewrite/Core/Rewriter.h"
#include "llvm/Support/raw_ostream.h"

using namespace clang;
using namespace clang::driver;
using namespace clang::tooling;

static llvm::cl::OptionCategory ToolingSampleCategory("Tooling Sample");

// By implementing RecursiveASTVisitor, we can specify which AST nodes
// we're interested in by overriding relevant methods.
class MyASTVisitor : public RecursiveASTVisitor<MyASTVisitor> {
public:
  MyASTVisitor(Rewriter &R, CompilerInstance & CI_) :
        TheRewriter( R ), CI( CI_ ), m_context( CI.getASTContext() ), m_pp( m_context.getLangOpts() )
  {
    m_pp.SuppressTagKeyword = 1 ;
  }

  ~MyASTVisitor()
  {
  }

  bool myVisitFieldDecl( const std::string & classname, FieldDecl * f )
  {
  //   f = f->getDefinition() ;

     const TypeSourceInfo * pThisFieldSourceInfo = f->getTypeSourceInfo() ;
     TypeLoc thisFieldTypeLoc = pThisFieldSourceInfo->getTypeLoc() ;
     const QualType & thisFieldQualType = thisFieldTypeLoc.getType() ;

     const Type * t = thisFieldTypeLoc.getTypePtr() ;

     if ( !t->isIncompleteType() && !t->isDependentType() )
     {
        size_t szInBits = m_context.getTypeSize( thisFieldQualType ) ;
        size_t offsetInBits = m_context.getFieldOffset( f ) ;

        llvm::outs()
           << "[" << offsetInBits/8 << "]:\t"
           << classname << "::"
           << thisFieldQualType.getAsString( m_pp ) << "\t" << f->getNameAsString()
           << "\tsize: " << szInBits/8 << "\n" ;
           ;
     }

     return true ;
  }

  bool VisitCXXRecordDecl( CXXRecordDecl * r )
  {
  //   r->dump() ;
  //   r = r->getDefinition() ;

     if ( r && r->getDescribedClassTemplate() )
     {
        r = r->getInstantiatedFromMemberClass() ;
     }

     if ( r && r->isThisDeclarationADefinition() )
     {
        const QualType & theMembersClassType = m_context.getRecordType( r ) ;

  #if 0
        for ( CXXRecordDecl::base_class_iterator b = r->bases_begin(), e = r->bases_end() ;
              b != e ; ++b )
        {
           CXXBaseSpecifier & a = *b ;

           const QualType & q = a.getType() ;

           insertIntoMap( r->getName().str(), q ) ;
        }
  #endif

        std::string classname = theMembersClassType.getAsString( m_pp ) ;

        for ( CXXRecordDecl::field_iterator b = r->field_begin(), e = r->field_end() ;
              b != e ; ++b )
        {
           FieldDecl * a = *b ;

           myVisitFieldDecl( classname, a ) ;
        }
     }

     return true ;
  }

private:
  Rewriter &                    TheRewriter;
  CompilerInstance &            CI ;

  ASTContext &                  m_context ;
  PrintingPolicy                m_pp ;
};

// Implementation of the ASTConsumer interface for reading an AST produced
// by the Clang parser.
class MyASTConsumer : public ASTConsumer {
public:
  MyASTConsumer(Rewriter &R, CompilerInstance &CI_) : Visitor(R, CI_) {}

  // Override the method that gets called for each parsed top-level
  // declaration.
  bool HandleTopLevelDecl(DeclGroupRef DR) override {
    for (DeclGroupRef::iterator b = DR.begin(), e = DR.end(); b != e; ++b) {
      // Traverse the declaration using our AST visitor.
      Visitor.TraverseDecl(*b);
//      (*b)->dump();
    }
    return true;
  }

private:
  MyASTVisitor Visitor;
};

// For each source file provided to the tool, a new FrontendAction is created.
class MyFrontendAction : public ASTFrontendAction {
public:
  MyFrontendAction() {}
  void EndSourceFileAction() override {
    SourceManager &SM = TheRewriter.getSourceMgr();
    llvm::errs() << "** EndSourceFileAction for: "
                 << SM.getFileEntryForID(SM.getMainFileID())->getName() << "\n";

    // Now emit the rewritten buffer.
    TheRewriter.getEditBuffer(SM.getMainFileID()).write(llvm::outs());
  }

  // This now assumes clang >= 3.8
  std::unique_ptr<clang::ASTConsumer> CreateASTConsumer(CompilerInstance &CI,
                                 StringRef file) override {
    llvm::errs() << "** Creating AST consumer for: " << file << "\n";
    TheRewriter.setSourceMgr(CI.getSourceManager(), CI.getLangOpts());
    return llvm::make_unique< MyASTConsumer >(TheRewriter, CI);
  }

private:
  Rewriter TheRewriter;
};

int main(int argc, const char **argv) {
  CommonOptionsParser op(argc, argv, ToolingSampleCategory);
  ClangTool Tool(op.getCompilations(), op.getSourcePathList());

  // ClangTool::run accepts a FrontendActionFactory, which is then used to
  // create new objects implementing the FrontendAction interface. Here we use
  // the helper newFrontendActionFactory to create a default factory that will
  // return a new MyFrontendAction object every time.
  // To further customize this, we could create our own factory class.
  return Tool.run(newFrontendActionFactory<MyFrontendAction>().get());
}
