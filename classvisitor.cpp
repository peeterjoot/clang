//-------------------------------------------------------------------------
//
// classvisitor.cpp: AST visitor code to get info about structure fields with Clang
//
// Based on Eli Bendersky's rewritersample.cpp
//
#include <string>
#include <vector>
#include <iostream>
#include <getopt.h> // gnu getopt assumed.
#include <cstdio>
#include <cstdlib>  // exit

#include "clang/AST/ASTConsumer.h"
#include "clang/AST/RecursiveASTVisitor.h"
#include "clang/Basic/Diagnostic.h"
#include "clang/Basic/FileManager.h"
#include "clang/Basic/SourceManager.h"
#include "clang/Basic/TargetOptions.h"
#include "clang/Basic/TargetInfo.h"
#include "clang/Basic/LangOptions.h"
#include "clang/Frontend/CompilerInstance.h"
#include "clang/Lex/Preprocessor.h"
#include "clang/Parse/ParseAST.h"
#include "llvm/Support/Host.h"
#include "llvm/Support/raw_ostream.h"
#include "clang/Frontend/TextDiagnosticPrinter.h"
#include "clang/Lex/HeaderSearch.h"
#include "clang/AST/ASTContext.h"
#include "clang/Frontend/Utils.h" // InitializePreprocessor

using namespace clang ;
using namespace std ;

inline QualType getQualTypeForDecl( DeclaratorDecl * f )
{
   TypeSourceInfo * pThisFieldSourceInfo = f->getTypeSourceInfo() ;

   TypeLoc thisFieldTypeLoc = pThisFieldSourceInfo->getTypeLoc() ;

   // don't care if it's an array, just want the basic underlying type of the array.
   if ( const ArrayTypeLoc * pTypeLocIfArray = dyn_cast<ArrayTypeLoc>( &thisFieldTypeLoc ) )
   {
      thisFieldTypeLoc = pTypeLocIfArray->getElementLoc() ;
   }

   return thisFieldTypeLoc.getType() ;
}

// By implementing RecursiveASTVisitor, we can specify which AST nodes
// we're interested in by overriding relevant methods.
class MyASTVisitor : public RecursiveASTVisitor<MyASTVisitor>
{
   CompilerInstance & ci ;

public:
   MyASTVisitor( CompilerInstance & ci_ ) : ci(ci_)
   {}

#if 0
   bool VisitCXXConstructorDecl( CXXConstructorDecl * c )
   {
      cout 
         << "GLOBAL: " 
         << c->getName().str() 
         << endl ;
         //<< " : " << q.getAsString()

      return true ;
   }
#endif

   bool VisitVarDecl( VarDecl * v )
   {
      if ( v->hasGlobalStorage() )
      {
         QualType q = getQualTypeForDecl( v ) ;

         cout 
            << "GLOBAL: " 
            << v->getName().str() << " : " << q.getAsString() << endl ;
      }

      return true ;
   }

   // Find typedefs:
   bool VisitTypedefDecl( TypedefDecl * t )
   {
      const QualType & q = t->getUnderlyingType() ;

      cout << t->getName().str() << " : " << q.getAsString() << endl ;

      return true ;
   }

   // Find class/struct/unions:
   bool VisitCXXRecordDecl( CXXRecordDecl* r )
   {
      if ( r->isThisDeclarationADefinition() )
      {
         //cout << "VisitCXXRecordDecl:: CLASS: " << r->getName().str() << endl ;

         if ( 
              r->hasConstCopyConstructor() ||
              r->hasUserDeclaredConstructor() ||
              r->hasUserProvidedDefaultConstructor() ||
              r->hasUserDeclaredCopyConstructor() ||
              r->hasNonTrivialDefaultConstructor() ||
              r->hasConstexprDefaultConstructor() ||
              r->hasNonTrivialCopyConstructor() ||
              r->hasUserDeclaredMoveConstructor()  ||
              r->hasFailedImplicitMoveConstructor()  ||
              r->hasConstexprNonCopyMoveConstructor()  ||
              r->hasNonTrivialMoveConstructor()  ||
              //r->hasTrivialMoveConstructor()  ||
              //r->hasDefaultConstructor() ||
              //r->hasCopyConstructorWithConstParam() ||
              //r->hasMoveConstructor() ||
              //r->hasTrivialDefaultConstructor() ||
              //r->hasTrivialCopyConstructor() ||
              0 )
         {
            cout << r->getName().str() << " : CONSTRUCTOR" << endl ;
         }

#if 0
if ( r->hasDefaultConstructor() ) { cout << r->getName().str() << " : CONSTRUCTOR: hasDefaultConstructor" << endl ; }
if ( r->hasConstCopyConstructor() ) { cout << r->getName().str() << " : CONSTRUCTOR: hasConstCopyConstructor" << endl ; }
if ( r->hasUserDeclaredConstructor() ) { cout << r->getName().str() << " : CONSTRUCTOR: hasUserDeclaredConstructor" << endl ; }
if ( r->hasUserProvidedDefaultConstructor() ) { cout << r->getName().str() << " : CONSTRUCTOR: hasUserProvidedDefaultConstructor" << endl ; }
if ( r->hasUserDeclaredCopyConstructor() ) { cout << r->getName().str() << " : CONSTRUCTOR: hasUserDeclaredCopyConstructor" << endl ; }
if ( r->hasCopyConstructorWithConstParam() ) { cout << r->getName().str() << " : CONSTRUCTOR: hasCopyConstructorWithConstParam" << endl ; }
if ( r->hasMoveConstructor() ) { cout << r->getName().str() << " : CONSTRUCTOR: hasMoveConstructor" << endl ; }
if ( r->hasTrivialDefaultConstructor() ) { cout << r->getName().str() << " : CONSTRUCTOR: hasTrivialDefaultConstructor" << endl ; }
if ( r->hasNonTrivialDefaultConstructor() ) { cout << r->getName().str() << " : CONSTRUCTOR: hasNonTrivialDefaultConstructor" << endl ; }
if ( r->hasConstexprDefaultConstructor() ) { cout << r->getName().str() << " : CONSTRUCTOR: hasConstexprDefaultConstructor" << endl ; }
if ( r->hasTrivialCopyConstructor() ) { cout << r->getName().str() << " : CONSTRUCTOR: hasTrivialCopyConstructor" << endl ; }
if ( r->hasNonTrivialCopyConstructor() ) { cout << r->getName().str() << " : CONSTRUCTOR: hasNonTrivialCopyConstructor" << endl ; }
if ( r->hasUserDeclaredMoveConstructor() ) { cout << r->getName().str() << " : CONSTRUCTOR: hasUserDeclaredMoveConstructor" << endl ; }
if ( r->hasFailedImplicitMoveConstructor() ) { cout << r->getName().str() << " : CONSTRUCTOR: hasFailedImplicitMoveConstructor" << endl ; }
if ( r->hasConstexprNonCopyMoveConstructor() ) { cout << r->getName().str() << " : CONSTRUCTOR: hasConstexprNonCopyMoveConstructor" << endl ; }
if ( r->hasTrivialMoveConstructor() ) { cout << r->getName().str() << " : CONSTRUCTOR: hasTrivialMoveConstructor" << endl ; }
if ( r->hasNonTrivialMoveConstructor() ) { cout << r->getName().str() << " : CONSTRUCTOR: hasNonTrivialMoveConstructor" << endl ; }
#endif

         for ( CXXRecordDecl::base_class_iterator b = r->bases_begin(), e = r->bases_end() ;
               b != e ; ++b )
         {
            CXXBaseSpecifier & a = *b ;

            const QualType & q = a.getType() ;

            cout 
               //<< "CLASS: " << r->getName().str() << " : "
               << r->getName().str() << " : " << q.getAsString() << endl ;

   //         cout << "BASE CLASS: " << q.getAsString() << endl ;
         }
      }

      return true ;
   }

   // Member's within class/struct/union:
   bool VisitFieldDecl( FieldDecl * f )
   {
      RecordDecl * r = f->getParent() ; //->getDefinition() ;
//      cout << "CLASS: " << r->getName().str() << endl ;
//      cout << "MEMBER: " << f->getName().str() << " ( " ;

      const QualType & thisFieldQualType = getQualTypeForDecl( f ) ;
//      cout << "TYPE: " << thisFieldQualType.getAsString() << " )" << endl ;

      string s = r->getName().str() ;
      // Deal with anonymous structures:
      //if ( r->isAnonymousStructOrUnion() ) // doesn't work
      if ( "" == s )
      {
         const Type * RT = r->getTypeForDecl() ;

         QualType QT = RT->getCanonicalTypeInternal() ;

         s = QT.getAsString() ;
      }

      cout 
         //<< "MEMBER: " << f->getName().str() 
         << s
         << " : " << thisFieldQualType.getAsString() << endl ;

// Think this pruned the struct/union/class:
#if 0
      const QualType & qu = thisFieldQualType.getDesugaredType( ci.getASTContext() ) ;
      cout << "TYPE: " << qu.getAsString() << " )" << endl ;
#endif

      return true ;
   }
} ;

// Implementation of the ASTConsumer interface for reading an AST produced
// by the Clang parser.
class MyASTConsumer : public ASTConsumer
{
public:
   MyASTConsumer( CompilerInstance & ci_ ) : Visitor(ci_) {}

   // Override the method that gets called for each parsed top-level
   // declaration.
   virtual bool HandleTopLevelDecl(DeclGroupRef DR)
   {
      for (DeclGroupRef::iterator b = DR.begin(), e = DR.end() ;
          b != e ; ++b)
      {
         // Traverse the declaration using our AST visitor.
         Visitor.TraverseDecl(*b) ;
      }

      return true ;
   }

private:
   MyASTVisitor Visitor ;
} ;

void printUsageAndExit( const char * argv0 )
{
   printf( "%s [-Ipath | --include=path] [-Dval | --define=val] [-h | --help] filename.cpp\n"
           "\n"
           "\tExample: %s x.cpp -Ipath1 -Dfoo -Dhoo --include=path2\n"
           , argv0
           , argv0 ) ;

   exit( 1 ) ;
}

// preprocessor driver based on https://github.com/loarabia/Clang-tutorial/blob/master/tutorial6.cpp
int main( int argc, char * argv[] )
{
   struct option options[] =
   {
       {"include", 1, 0, 'I'}
      ,{"define", 1, 0, 'D'}
      ,{"undef", 1, 0, 'U'}
      ,{"help", 1, 0, 'h'}
   } ;

   int c = 0 ;
   int optindex = 0 ;

   llvm::IntrusiveRefCntPtr<PreprocessorOptions> pOpts( new PreprocessorOptions() ) ;
   llvm::IntrusiveRefCntPtr<HeaderSearchOptions> headerSearchOptions( new HeaderSearchOptions() ) ;

   for ( ; c != EOF ; )
   {
      c = getopt_long( argc,
                       argv,
                       "I:" // -Ipath | --include=path
                       "D:" // -Dval | --define=val
                       "U:" // -Uval | --undef=val
                       "h"  // -h (this driver help)
                       /* option compatibility with actual compilers: */
                       "c"  // -c
                       "W:" // -Wformat ...
                       "O:" // -O2 -O0 ...
                       "m:" // -msse4.2 ...
                       "f:" // -fcheck-new ...
                       "g"  // -g
                       "",
                       options,
                       &optindex ) ;
            /* dummy args: */ 

      switch (c)
      {
         case 'W':
         case 'c':
         case 'O':
         case 'm':
         case 'f':
         case 'g':
         {
            /* no-op */

            break ;
         }
         case 'I':
         {
            //printf( "-I : %s\n", optarg ) ;
            headerSearchOptions->AddPath( optarg,
                                          frontend::Quoted,
                                          true,
                                          false,
                                          false ) ;

            break ;
         }
         case 'D':
         {
            //printf( "-D : %s\n", optarg ) ;
            pOpts->addMacroDef( optarg ) ;

            break ;
         }
         case 'U':
         {
            //printf( "-U : %s\n", optarg ) ;
            pOpts->addMacroUndef( optarg ) ;

            break ;
         }

         case EOF:
         {
            break ;
         }
         case 'h':
         default:
         {
            printUsageAndExit( argv[0] ) ;
         }
      }
   }

   if ( optind != (argc - 1) )
   {
      printUsageAndExit( argv[0] ) ;
   }
 
   DiagnosticOptions diagnosticOptions ;

   TextDiagnosticPrinter * pTextDiagnosticPrinter 
      = new TextDiagnosticPrinter( llvm::outs(),
                                   &diagnosticOptions ) ;

   llvm::IntrusiveRefCntPtr<DiagnosticIDs> pDiagIDs ;

   DiagnosticsEngine * pDiagnosticsEngine 
      = new DiagnosticsEngine( pDiagIDs,
                               &diagnosticOptions,
                               pTextDiagnosticPrinter ) ;

   LangOptions languageOptions ;

   // Allow C++ code (https://github.com/loarabia/Clang-tutorial/blob/master/CIrewriter.cpp)
   languageOptions.GNUMode = 1 ;
   languageOptions.CXXExceptions = 1 ;
   languageOptions.RTTI = 1 ;
   languageOptions.Bool = 1 ;
   languageOptions.CPlusPlus = 1 ;

   FileSystemOptions fileSystemOptions ;

   FileManager fileManager( fileSystemOptions ) ;

   SourceManager sourceManager( *pDiagnosticsEngine,
                                fileManager ) ;

   TargetOptions targetOptions ;

   targetOptions.Triple = llvm::sys::getDefaultTargetTriple() ;

   TargetInfo * pTargetInfo = TargetInfo::CreateTargetInfo( *pDiagnosticsEngine,
                                                            &targetOptions ) ;

   HeaderSearch headerSearch( headerSearchOptions,
                              fileManager,
                              *pDiagnosticsEngine,
                              languageOptions,
                              pTargetInfo ) ;

   CompilerInstance compInst ;

   Preprocessor preprocessor( pOpts,
                              *pDiagnosticsEngine,
                              languageOptions,
                              pTargetInfo,
                              sourceManager,
                              headerSearch,
                              compInst ) ;

   FrontendOptions frontendOptions ;
   //frontendOptions.SkipFunctionBodies = 1 ;

   InitializePreprocessor( preprocessor,
                           *pOpts,
                           *headerSearchOptions,
                           frontendOptions ) ;
       
   const FileEntry * pFile = fileManager.getFile( argv[optind] ) ;
   
   if ( pFile )
   {
      sourceManager.createMainFileID( pFile ) ;

      IdentifierTable identifierTable( languageOptions ) ;

      SelectorTable selectorTable ;

      Builtin::Context builtinContext ;

      builtinContext.InitializeTarget( *pTargetInfo ) ;

      ASTContext astContext( languageOptions,
                             sourceManager,
                             pTargetInfo,
                             identifierTable,
                             selectorTable,
                             builtinContext,
                             0 /* size_reserve*/ ) ;

      MyASTConsumer astConsumer( compInst ) ;

      pTextDiagnosticPrinter->BeginSourceFile( languageOptions, &preprocessor ) ;

      ParseAST( preprocessor, &astConsumer, astContext ) ;

      pTextDiagnosticPrinter->EndSourceFile() ;
   }

   return 0 ;
}
