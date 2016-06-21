
class voidPPCastStrippingModifier : public MatchFinder::MatchCallback
{
public:
   voidPPCastStrippingModifier(Replacements *Replace) : Replace(Replace) {}

   // This method is called every time the registered matcher matches
   // on the AST.
   virtual void run(const MatchFinder::MatchResult &Result) {
      const CallExpr *M = Result.Nodes.getStmtAs<CallExpr>("x");
      const Expr * a = M->getArg( 3 ) ;

      // strip out the (presumed 'void **' casting) in XXgmblk calls.
      if ( const CStyleCastExpr * v = dyn_cast<CStyleCastExpr>( a ) )
      {
#if 0
std::cout << "M: " << decl2str( M, Result.SourceManager ) << std::endl ;
      M->dump() ;
std::cout << "a: " << decl2str( a, Result.SourceManager ) << std::endl ;
      a->dump() ;
std::cout << "v: " << decl2str( v, Result.SourceManager ) << std::endl ;
      v->dump() ;
#endif
         const Expr * theCastedValue = v->getSubExprAsWritten() ;
         //theCastedValue->dump() ;
         //std::cout << v->getCastKindName() << std::endl ; // -> CK_BitCast 

         if ( theCastedValue )
         {
            std::string replacement = decl2str( theCastedValue, Result.SourceManager ) ; 
 
            if ( replacement.length() )
            {
               std::string orig = decl2str( a, Result.SourceManager ) ;
std::cout << "orig: '" << orig << "' -> '" << replacement << "'\n" ;

               Replace->insert(
                  Replacement(*Result.SourceManager,
                              a->getLocStart(),
                              orig.length(),
                              replacement)
                  ) ;
            } 
         }
      }
   }

private:
   // Replacements are the RefactoringTool's way to keep track of code
   // transformations, deduplicate them and apply them to the code when
   // the tool has finished with all translation units.
   Replacements *Replace;

};
