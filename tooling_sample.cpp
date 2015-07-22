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

//#define MEMBERDUMPER
#define CLASSVISITOR
//#define DUMPER
//#define GLOBALVISITOR

#if defined CLASSVISITOR
   #include "depmap.h"
#elif defined MEMBERDUMPER || defined GLOBALVISITOR
   #include <iostream>
#endif

using namespace clang;
using namespace clang::driver;
using namespace clang::tooling;

static llvm::cl::OptionCategory ToolingSampleCategory("Tooling Sample");

#if defined CLASSVISITOR || defined GLOBALVISITOR

#if 0
   #include <fstream>

   const char *   g_symbolfile = NULL ;
   string         g_typeSuppressed( "<>" ) ;
   ofstream       g_outFile ;

   ostream *      g_out  = &cout ;
#endif

inline QualType getQualTypeForDecl( DeclaratorDecl * f )
{
   TypeSourceInfo * pThisFieldSourceInfo = f->getTypeSourceInfo() ;

   TypeLoc thisFieldTypeLoc = pThisFieldSourceInfo->getTypeLoc() ;

   // don't care if it's an array, just want the basic underlying type of the array.
   for ( ; ; )
   {
      if ( ArrayTypeLoc TypeLocIfArray = thisFieldTypeLoc.getAs<ArrayTypeLoc>() )
      {
         thisFieldTypeLoc = TypeLocIfArray.getElementLoc() ;
      }
      else
      {
         break ;
      }
   }

   return thisFieldTypeLoc.getType() ;
}

static QualType returnUnderlyingTypeIfArray( QualType q )
{
   const Type *   tUnderlying = q.getTypePtr() ;

   if ( tUnderlying->isArrayType() )
   {
      while ( tUnderlying->isArrayType() )
      {
         //tUnderlying->dump() ;

         tUnderlying = tUnderlying->getBaseElementTypeUnsafe() ;
      }

      q = tUnderlying->getLocallyUnqualifiedSingleStepDesugaredType() ;
   }

   return q ;
}
#endif

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
#if defined CLASSVISITOR
     m_depMap.dump() ;
#endif
  }

#if defined CLASSVISITOR
  // this file is embedded into the class decl of a MyASTVisitor

  void insertIntoMap( const std::string & theTypeName, const QualType & q, const std::string * pAsString = NULL )
  {
     const Type * t = q.getTypePtr() ;

  #if 0
     if ( g_quietDeps )
     {
        if ( t->isArithmeticType() ||
             t->isPointerType() ||
             t->isReferenceType() ||
             0 )
        {
           //
           // This is a hack, so that there is at least one fake dependency for each type, since any type is only put
           // into the dependency tree implicitly.
           //
           pAsString = &g_typeSuppressed ;
        }
     }
  #endif

     if ( pAsString )
     {
        m_depMap.insertDependency( theTypeName, *pAsString ) ;
     }
     else
     {
        m_depMap.insertDependency( theTypeName, q.getAsString( m_pp ) ) ;
     }
  }

  // Find typedefs:
  bool VisitTypedefDecl( TypedefDecl * dtDecl )
  {
     QualType       qtUnderLying         = returnUnderlyingTypeIfArray( dtDecl->getUnderlyingType() ) ;
     const Type *   tUnderlying          = qtUnderLying.getTypePtr() ;
     std::string         theUnderlyingType    = qtUnderLying.getAsString( ) ;
     std::string         typeDefinitionName   = dtDecl->getName().str() ;
     std::string *       pName                = NULL ;

     if ( tUnderlying->isStructureType() )
     {
        theUnderlyingType = theUnderlyingType.substr(strlen("struct ")) ;
        pName = &theUnderlyingType ;
     }
     else if ( tUnderlying->isClassType() )
     {
        theUnderlyingType = theUnderlyingType.substr(strlen("class ")) ;
        pName = &theUnderlyingType ;
     }
     else if ( tUnderlying->isUnionType() )
     {
        theUnderlyingType = theUnderlyingType.substr(strlen("union ")) ;
        pName = &theUnderlyingType ;
     }
     else if ( tUnderlying->isEnumeralType() )
     {
        theUnderlyingType = theUnderlyingType.substr(strlen("enum ")) ;
        pName = &theUnderlyingType ;
     }

     if ( typeDefinitionName != theUnderlyingType )
     {
        insertIntoMap( typeDefinitionName, qtUnderLying, pName ) ;
     }

     return true ;
  }

  // Find class/struct/unions:
  bool VisitCXXRecordDecl( CXXRecordDecl * r )
  {
     if ( r->isThisDeclarationADefinition() )
     {
        for ( CXXRecordDecl::base_class_iterator b = r->bases_begin(), e = r->bases_end() ;
              b != e ; ++b )
        {
           CXXBaseSpecifier & a = *b ;

           const QualType & q = a.getType() ;

           insertIntoMap( r->getName().str(), q ) ;
        }
     }

  #if 0
     // debug:
     llvm::outs() << "r: " << r->getName().str() << "\n" ;
  #endif

     return true ;
  }

  #if 0
  bool VisitFunctionDecl( FunctionDecl * f )
  {
     // Only function definitions (with bodies), not declarations.
     if ( f->hasBody() )
     {
        DeclarationName DeclName = f->getNameInfo().getName() ;
        std::string FuncName = DeclName.getAsString() ;

        llvm::outs() << "f: " << FuncName << "\n" ;
     }

     return true ;
  }
  #endif

  // Member's within class/struct/union:
  bool VisitFieldDecl( FieldDecl * f )
  {
     RecordDecl * r = f->getParent() ;
     const QualType & theMembersClassType = m_context.getRecordType( r ) ;
     const QualType & thisFieldQualType = returnUnderlyingTypeIfArray( getQualTypeForDecl( f ).getDesugaredType( m_context ) ) ;

     const std::string & s = theMembersClassType.getAsString( m_pp ) ;

  #if 0
     if ( (s == "stmmShmHeader") || (s == "OSSVLatchInternals") )
     {
        llvm::outs() << "xx\n" ;
     }
  #endif
  #if 0
     llvm::outs() << "s: " << s << "\n" ;
  #endif

     insertIntoMap( s, thisFieldQualType ) ;

     return true ;
  }
#elif defined MEMBERDUMPER
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
#elif defined DUMPER

  #include "dumper.h"

#elif defined GLOBALVISITOR

  static std::string subMemberString( const std::string & prefix, const std::string & field )
  {
     std::string s = prefix ;

     if ( "" != prefix )
     {
        s += "." ;
     }

     s += field ;

     return s ;
  }

  //
  // 1.  Look at the constructor: getConstructor().
  // 2.  Check whether it's a implicitly-defined default constructor: isDefaultConstructor(), isImplicitlyDefined().  If not, you've found your problem right there.
  // 3.  Iterate over the initializers: init_begin(), init_end().
  // 4.  I believe the expression for each initializer should always be a CXXConstructExpr.  Recurse.
  //
  void recurseOverConstructorDecls( CXXConstructorDecl * c, std::string subobject )
  {
     for ( CXXConstructorDecl::init_iterator b = c->init_begin(), e = c->init_end() ;
           b != e ; ++b )
     {
        CXXCtorInitializer *    i        = *b ;
        FieldDecl *             f        = i->getMember() ;
        Expr *                  Init     = i->getInit() ;
        std::string             subfield = subMemberString( subobject, f->getName().str() ) ;

        const QualType &        ftype    = getQualTypeForDecl( f ) ; // type of the field.  Now check if that type has a constructor.

        if ( const CXXConstructExpr * r = dyn_cast<CXXConstructExpr>( Init ) )
        {
           CXXConstructorDecl * cInner   = r->getConstructor() ;
           CXXRecordDecl *      frec     = ftype->getAsCXXRecordDecl() ;

  #if 0
           if ( frec->hasDefaultConstructor() ) { llvm::outs() << frec->getName().str() << " : CONSTRUCTOR: hasDefaultConstructor" << "\n" ; }
           if ( frec->hasConstCopyConstructor() ) { llvm::outs() << frec->getName().str() << " : CONSTRUCTOR: hasConstCopyConstructor" << "\n" ; }
           if ( frec->hasUserDeclaredConstructor() ) { llvm::outs() << frec->getName().str() << " : CONSTRUCTOR: hasUserDeclaredConstructor" << "\n" ; }
           if ( frec->hasUserProvidedDefaultConstructor() ) { llvm::outs() << frec->getName().str() << " : CONSTRUCTOR: hasUserProvidedDefaultConstructor" << "\n" ; }
           if ( frec->hasUserDeclaredCopyConstructor() ) { llvm::outs() << frec->getName().str() << " : CONSTRUCTOR: hasUserDeclaredCopyConstructor" << "\n" ; }
           if ( frec->hasCopyConstructorWithConstParam() ) { llvm::outs() << frec->getName().str() << " : CONSTRUCTOR: hasCopyConstructorWithConstParam" << "\n" ; }
           if ( frec->hasMoveConstructor() ) { llvm::outs() << frec->getName().str() << " : CONSTRUCTOR: hasMoveConstructor" << "\n" ; }
           if ( frec->hasTrivialDefaultConstructor() ) { llvm::outs() << frec->getName().str() << " : CONSTRUCTOR: hasTrivialDefaultConstructor" << "\n" ; }
           if ( frec->hasNonTrivialDefaultConstructor() ) { llvm::outs() << frec->getName().str() << " : CONSTRUCTOR: hasNonTrivialDefaultConstructor" << "\n" ; }
           if ( frec->hasConstexprDefaultConstructor() ) { llvm::outs() << frec->getName().str() << " : CONSTRUCTOR: hasConstexprDefaultConstructor" << "\n" ; }
           if ( frec->hasTrivialCopyConstructor() ) { llvm::outs() << frec->getName().str() << " : CONSTRUCTOR: hasTrivialCopyConstructor" << "\n" ; }
           if ( frec->hasNonTrivialCopyConstructor() ) { llvm::outs() << frec->getName().str() << " : CONSTRUCTOR: hasNonTrivialCopyConstructor" << "\n" ; }
           if ( frec->hasUserDeclaredMoveConstructor() ) { llvm::outs() << frec->getName().str() << " : CONSTRUCTOR: hasUserDeclaredMoveConstructor" << "\n" ; }
           if ( frec->hasFailedImplicitMoveConstructor() ) { llvm::outs() << frec->getName().str() << " : CONSTRUCTOR: hasFailedImplicitMoveConstructor" << "\n" ; }
           if ( frec->hasConstexprNonCopyMoveConstructor() ) { llvm::outs() << frec->getName().str() << " : CONSTRUCTOR: hasConstexprNonCopyMoveConstructor" << "\n" ; }
           if ( frec->hasTrivialMoveConstructor() ) { llvm::outs() << frec->getName().str() << " : CONSTRUCTOR: hasTrivialMoveConstructor" << "\n" ; }
           if ( frec->hasNonTrivialMoveConstructor() ) { llvm::outs() << frec->getName().str() << " : CONSTRUCTOR: hasNonTrivialMoveConstructor" << "\n" ; }
  #endif

           if ( cInner->isExplicitSpecified() &&
                ( frec->hasUserDeclaredConstructor() ||
                  frec->hasUserProvidedDefaultConstructor() ||
                  frec->hasUserDeclaredCopyConstructor() ||
                  frec->hasNonTrivialDefaultConstructor() ||
                  frec->hasConstexprDefaultConstructor() ||
                  frec->hasNonTrivialCopyConstructor() ||
                  frec->hasUserDeclaredMoveConstructor()  ||
                  //frec->hasFailedImplicitMoveConstructor()  || // not in clang 3.4?
                  frec->hasConstexprNonCopyMoveConstructor()  ||
                  frec->hasNonTrivialMoveConstructor()  ||
                  //frec->hasConstCopyConstructor() ||
                  //frec->hasTrivialMoveConstructor()  ||
                  //frec->hasDefaultConstructor() ||
                  //frec->hasCopyConstructorWithConstParam() ||
                  //frec->hasMoveConstructor() ||
                  //frec->hasTrivialDefaultConstructor() ||
                  //frec->hasTrivialCopyConstructor() ||
                  0 )
              )
           {
              llvm::outs()
                 << "Global subobject requires constructor: "
                 << subfield
                 << " : "
                 << ftype.getAsString()
                 << "\n" ;

              recurseOverConstructorDecls( cInner, subfield ) ;
           }
        }
     }
  }

  bool VisitVarDecl( VarDecl * var )
  {
     // modified from Eli's email "Here's the code used to implement -Wglobal-constructor:"
     Expr *         Init     = var->getInit() ;
     bool           IsGlobal = var->hasGlobalStorage() && !var->isStaticLocal() ;
     QualType       type     = var->getType();
     QualType       baseType = m_context.getBaseElementType( type ) ;

     if ( !var->getDeclContext()->isDependentContext() && Init && !Init->isValueDependent() )
     {
        if ( IsGlobal && !var->isConstexpr() &&
             !Init->isConstantInitializer( m_context, baseType->isReferenceType() ) )
        {
           if ( const CXXConstructExpr * r = dyn_cast<CXXConstructExpr>( Init ) )
           {
              CXXConstructorDecl * c = r->getConstructor() ;

              recurseOverConstructorDecls( c, var->getName().str() ) ;
           }
        }
     }

     return true ;
  }
#endif

private:
  Rewriter &                    TheRewriter;
  CompilerInstance &            CI ;

  ASTContext &                  m_context ;
  PrintingPolicy                m_pp ;

#if defined CLASSVISITOR
  dependencyMap                 m_depMap ;
#endif
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

  ASTConsumer *CreateASTConsumer(CompilerInstance &CI,
                                 StringRef file) override {
    llvm::errs() << "** Creating AST consumer for: " << file << "\n";
    TheRewriter.setSourceMgr(CI.getSourceManager(), CI.getLangOpts());
    return new MyASTConsumer(TheRewriter, CI);
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
