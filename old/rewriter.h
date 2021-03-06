#if 0
bool VisitStmt(Stmt * s)
{
   // Only care about If statements.
   if ( isa<IfStmt>( s ) )
   {
      IfStmt * IfStatement = cast<IfStmt>(s) ;
      Stmt * Then = IfStatement->getThen() ;

      m_re.InsertText( Then->getLocStart(),
                       "// the 'if' part\n",
                       true,
                       true ) ;

      Stmt * Else = IfStatement->getElse() ;

      if (Else)
      {
         m_re.InsertText( Else->getLocStart(),
                          "// the 'else' part\n",
                          true,
                          true ) ;
      }
   }

   return true ;
}

bool VisitFunctionDecl( FunctionDecl * f )
{
   // Only function definitions (with bodies), not declarations.
   if ( f->hasBody() )
   {
      Stmt * FuncBody = f->getBody() ;

      // Type name as string
      QualType QT = f->getResultType() ;
      string TypeStr = QT.getAsString() ;

      // Function name
      DeclarationName DeclName = f->getNameInfo().getName() ;
      string FuncName = DeclName.getAsString() ;

      // Add comment before
      stringstream SSBefore ;

      SSBefore << "// Begin function " 
               << FuncName 
               << " returning "
               << TypeStr << "\n" ;

      SourceLocation ST = f->getSourceRange().getBegin() ;

      m_re.InsertText( ST,
                       SSBefore.str(),
                       true,
                       true ) ;

      // And after
      stringstream SSAfter ;

      SSAfter << "\n// End function " 
              << FuncName 
              << "\n" ;

      ST = FuncBody->getLocEnd().getLocWithOffset(1) ;

      m_re.InsertText( ST,
                       SSAfter.str(),
                       true,
                       true ) ;
   }

   return true ;
}
#endif

// %s/sqlt_fnc_entry *( *[^,]\+ *, *\([^,]\+\) *)/pdTraceEntry( \1 )/c
// %s/sqlt_fnc_retcode *( *[^,]\+ *, *\([^,]\+\), *\([^,]\+\) *)/pdTraceExit( \1, \2 )/c
// %s/sqlt_fnc_data\> *( *[^,]\+ *, *\([^,]\+\) *, *\([^,]\+\) *, *strlen *( *\(.*\) *) *, *\3 *)/pdTraceData1( \1, \2, PD_STRING( \3 ) )/c
// %s/sqlt_fnc_data\> *( *[^,]\+ *, *\([^,]\+\) *, *\([^,]\+\) *, *\(sizeof *( *.* *)\) *, *\([^,]\+\) *)/pdTraceData1( \1, \2, PD_HEXDUMP( \4, \3 ) )/c
// %s/sqlt_fnc_data\> *( *[^,]\+ *, *\([^,]\+\) *, *\([^,]\+\) *, *sizeof *( *\(.*\) *) *, *& *\3 *)/pdTraceData1( \1, \2, PD_HEXDUMP_SIZEOF( \3 ) )/c
// %s/sqlt_fnc_data2\> *( *[^,]\+ *, *\([^,]\+\) *, *\([^,]\+\) *, *strlen *( *\(.*\) *) *, *\3, *strlen *( *\(.*\) *) *, *\4 *)/pdTraceData2( \1, \2, PD_STRING( \3 ), PD_STRING( \4 ) )/c
// %s/sqlt_fnc_data2\> *( *[^,]\+ *, *\([^,]\+\) *, *\([^,]\+\) *, *\(sizeof *( *.* *)\) *, *\([^,]\+\) *, *\(sizeof *( *.* *)\) *, *\([^,]\+\) )/pdTraceData2( \1, \2, PD_HEXDUMP( \4, \3 ), PD_HEXDUMP( \6, \5 ) )/c
// %s/\(sqlt_trace_error.*\)\/\*.*/\1/c
// %s/\(sqlt_trace_error.*\)\/\/.*/\1/c
// %s/sqlt_trace_error\> *( *[^,]\+ *, *\([^,]\+\) *, *\([^,]\+\) *, *sizeof *( *\(.*\) *) *, *& *\3 *)/pdTraceError( \1, \3, \2 )/c
// %s/sqlt_trace_error\> *( *[^,]\+ *, *\([^,]\+\) *, *\([^,]\+\) *, *sizeof *( *\("[^"]\+"\) *) *- *1 *, *( *void *\* *) *\3 *)/pdTraceError1( \1, 0, \2, PD_STRING(\3) )/c
// %s/sqlt_trace_error\> *( *[^,]\+ *, *\([^,]\+\) *, *\([^,]\+\) *, *strlen *( *\(.*\) *) *, *\3 *)/pdTraceError1( \1, 0, \2, PD_STRING(\3) )/c

#if 0
   c->dump() ;
   (CallExpr 0x13ad1c0 'void'
      (ImplicitCastExpr 0x13ad1a8 'void (*)(int, int, int)' <FunctionToPointerDecay>
           (DeclRefExpr 0x13ad158 'void (int, int, int)' lvalue Function 0x13acee0 'infinite' 'void (int, int, int)'))
        (IntegerLiteral 0x13ad028 'int' 5)
          (BinaryOperator 0x13ad0a8 'int' '-'
               (ImplicitCastExpr 0x13ad090 'int' <LValueToRValue>
                      (DeclRefExpr 0x13ad048 'int' lvalue ParmVar 0x13acd70 'y' 'int'))
                   (IntegerLiteral 0x13ad070 'int' 1))
            (BinaryOperator 0x13ad130 'int' '+'
                 (ImplicitCastExpr 0x13ad118 'int' <LValueToRValue>
                        (DeclRefExpr 0x13ad0d0 'int' lvalue ParmVar 0x13acde0 'x' 'int'))
                     (IntegerLiteral 0x13ad0f8 'int' 1)))
#endif
bool VisitCallExpr( CallExpr * c )
{
   Decl * d = c->getCalleeDecl() ;
   if ( d )
   {
      d->dump() ;

      // tools/clang/examples/PrintFunctionNames/PrintFunctionNames.cpp:
      if ( const NamedDecl * ND = dyn_cast<NamedDecl>( d ) )
      {
         // cout << ND->getNameAsString() << endl ;
         string thisFunctionName = ND->getNameAsString() ;

         if ( "sqlt_fnc_entry" == thisFunctionName )
         {
            string TypeS0 ;
            string TypeS1 ;

            llvm::raw_string_ostream s0( TypeS0 ) ;
            llvm::raw_string_ostream s1( TypeS1 ) ;

            c->getArg( 0 )->printPretty( s0, 0, m_pp ) ;
            c->getArg( 1 )->printPretty( s1, 0, m_pp ) ;

            cout << "pdTraceEntry( " << s0.str() << " )" << endl ;
            cout << "pdTraceEntry( " << s1.str() << " )" << endl ;
            cout << "TypeS: " << TypeS0 << endl ;
            cout << "TypeS: " << TypeS1 << endl ;
         }
      }

#if 0
      if ( const ImplicitCastExpr * r = dyn_cast<ImplicitCastExpr>( c ) )
      {
         r->dump() ;
   //      cout << r->getName().str() << endl ;
      }
      //if ( const DeclRefExpr * r = dyn_cast<DeclRefExpr>( c->getCallee() ) )
      if ( const DeclRefExpr * r = dyn_cast<DeclRefExpr>( c ) )
      {
         r->dump() ;
   //      cout << r->getName().str() << endl ;
      }
#endif

#if 0
      // This is the signature of the function.  Example: void (*)(int, int, int)
      Expr * e = c->getCallee() ;
      cout << e->getType().getAsString()
           << endl ;
#endif

      // http://stackoverflow.com/questions/9607852/print-arguments-of-a-function-using-clang-ast
      for ( int i = 0, j = c->getNumArgs() ; i < j ; i++ )
      {
          string TypeS ;

          llvm::raw_string_ostream s( TypeS ) ;

          Expr * p = c->getArg( i ) ;
          p->dump() ;

          if ( ParmVarDecl * v = dyn_cast<ParmVarDecl>( d ) )
          {
             cout << "v: \n" ;
             v->dump() ;
          }

          p->printPretty( s, 0, m_pp ) ;

          llvm::errs() << "arg: " << s.str() << "\n" ;
      }

      if ( d->getKind() == Decl::Function )
      {
         static IdentifierInfo * II_sqlt_fnc_entry = NULL ;

         if ( !II_sqlt_fnc_entry )
         {
             II_sqlt_fnc_entry = &m_context.Idents.get( "sqlt_fnc_entry" ) ;
         }

         if ( const NamedDecl * ND = dyn_cast<NamedDecl>( d ) )
         {
            IdentifierInfo * FunI = ND->getIdentifier();

            if ( FunI == II_sqlt_fnc_entry )
            {
               cout << "found II_sqlt_fnc_entry\n" ;
            }
         }
      }
   }

   return true ;
}
