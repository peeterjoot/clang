// 
// Generated from nm output of classvisitor, looking for ::Visit symbols.  Then in vim:
//
// :,$ s/bool \(.*\)/&Z{Z   std::cout << '\n' << "&" << '\n' ;ZZ   v->dump() ;ZZ   return true ;Z}ZZ/
// :,$ !tr Z '\n'
//
// Since the XML AST dumper that apparently once existed has been deleted, this provides a poor man's version, also implicitly
// showing what ASTVisitor methods one would wish to override to find the desired source code info.
//

bool VisitAbstractConditionalOperator( AbstractConditionalOperator * v )
{
   std::cout << '\n' << "bool VisitAbstractConditionalOperator( AbstractConditionalOperator * v )" << '\n' ;

   v->dump() ;

   return true ;
}


bool VisitAccessSpecDecl( AccessSpecDecl * v )
{
   std::cout << '\n' << "bool VisitAccessSpecDecl( AccessSpecDecl * v )" << '\n' ;

   v->dump() ;

   return true ;
}


bool VisitAddrLabelExpr( AddrLabelExpr * v )
{
   std::cout << '\n' << "bool VisitAddrLabelExpr( AddrLabelExpr * v )" << '\n' ;

   v->dump() ;

   return true ;
}


bool VisitArraySubscriptExpr( ArraySubscriptExpr * v )
{
   std::cout << '\n' << "bool VisitArraySubscriptExpr( ArraySubscriptExpr * v )" << '\n' ;

   v->dump() ;

   return true ;
}


bool VisitArrayType( ArrayType * v )
{
   std::cout << '\n' << "bool VisitArrayType( ArrayType * v )" << '\n' ;

   v->dump() ;

   return true ;
}


bool VisitArrayTypeTraitExpr( ArrayTypeTraitExpr * v )
{
   std::cout << '\n' << "bool VisitArrayTypeTraitExpr( ArrayTypeTraitExpr * v )" << '\n' ;

   v->dump() ;

   return true ;
}


bool VisitAsmStmt( AsmStmt * v )
{
   std::cout << '\n' << "bool VisitAsmStmt( AsmStmt * v )" << '\n' ;

   v->dump() ;

   return true ;
}


bool VisitAsTypeExpr( AsTypeExpr * v )
{
   std::cout << '\n' << "bool VisitAsTypeExpr( AsTypeExpr * v )" << '\n' ;

   v->dump() ;

   return true ;
}


bool VisitAtomicExpr( AtomicExpr * v )
{
   std::cout << '\n' << "bool VisitAtomicExpr( AtomicExpr * v )" << '\n' ;

   v->dump() ;

   return true ;
}


bool VisitAtomicType( AtomicType * v )
{
   std::cout << '\n' << "bool VisitAtomicType( AtomicType * v )" << '\n' ;

   v->dump() ;

   return true ;
}


bool VisitAttributedStmt( AttributedStmt * v )
{
   std::cout << '\n' << "bool VisitAttributedStmt( AttributedStmt * v )" << '\n' ;

   v->dump() ;

   return true ;
}


bool VisitAttributedType( AttributedType * v )
{
   std::cout << '\n' << "bool VisitAttributedType( AttributedType * v )" << '\n' ;

   v->dump() ;

   return true ;
}


bool VisitAutoType( AutoType * v )
{
   std::cout << '\n' << "bool VisitAutoType( AutoType * v )" << '\n' ;

   v->dump() ;

   return true ;
}


bool VisitBinAddAssign( CompoundAssignOperator * v )
{
   std::cout << '\n' << "bool VisitBinAddAssign( CompoundAssignOperator * v )" << '\n' ;

   v->dump() ;

   return true ;
}


bool VisitBinAdd( BinaryOperator * v )
{
   std::cout << '\n' << "bool VisitBinAdd( BinaryOperator * v )" << '\n' ;

   v->dump() ;

   return true ;
}


bool VisitBinAndAssign( CompoundAssignOperator * v )
{
   std::cout << '\n' << "bool VisitBinAndAssign( CompoundAssignOperator * v )" << '\n' ;

   v->dump() ;

   return true ;
}


bool VisitBinAnd( BinaryOperator * v )
{
   std::cout << '\n' << "bool VisitBinAnd( BinaryOperator * v )" << '\n' ;

   v->dump() ;

   return true ;
}


bool VisitBinaryConditionalOperator( BinaryConditionalOperator * v )
{
   std::cout << '\n' << "bool VisitBinaryConditionalOperator( BinaryConditionalOperator * v )" << '\n' ;

   v->dump() ;

   return true ;
}


bool VisitBinaryOperator( BinaryOperator * v )
{
   std::cout << '\n' << "bool VisitBinaryOperator( BinaryOperator * v )" << '\n' ;

   v->dump() ;

   return true ;
}

#if 0
bool VisitBinaryTypeTraitExpr( BinaryTypeTraitExpr * v )
{
   std::cout << '\n' << "bool VisitBinaryTypeTraitExpr( BinaryTypeTraitExpr * v )" << '\n' ;

   v->dump() ;

   return true ;
}
#endif

bool VisitBinAssign( BinaryOperator * v )
{
   std::cout << '\n' << "bool VisitBinAssign( BinaryOperator * v )" << '\n' ;

   v->dump() ;

   return true ;
}


bool VisitBinComma( BinaryOperator * v )
{
   std::cout << '\n' << "bool VisitBinComma( BinaryOperator * v )" << '\n' ;

   v->dump() ;

   return true ;
}


bool VisitBinDivAssign( CompoundAssignOperator * v )
{
   std::cout << '\n' << "bool VisitBinDivAssign( CompoundAssignOperator * v )" << '\n' ;

   v->dump() ;

   return true ;
}


bool VisitBinDiv( BinaryOperator * v )
{
   std::cout << '\n' << "bool VisitBinDiv( BinaryOperator * v )" << '\n' ;

   v->dump() ;

   return true ;
}


bool VisitBinEQ( BinaryOperator * v )
{
   std::cout << '\n' << "bool VisitBinEQ( BinaryOperator * v )" << '\n' ;

   v->dump() ;

   return true ;
}


bool VisitBinGE( BinaryOperator * v )
{
   std::cout << '\n' << "bool VisitBinGE( BinaryOperator * v )" << '\n' ;

   v->dump() ;

   return true ;
}


bool VisitBinGT( BinaryOperator * v )
{
   std::cout << '\n' << "bool VisitBinGT( BinaryOperator * v )" << '\n' ;

   v->dump() ;

   return true ;
}


bool VisitBinLAnd( BinaryOperator * v )
{
   std::cout << '\n' << "bool VisitBinLAnd( BinaryOperator * v )" << '\n' ;

   v->dump() ;

   return true ;
}


bool VisitBinLE( BinaryOperator * v )
{
   std::cout << '\n' << "bool VisitBinLE( BinaryOperator * v )" << '\n' ;

   v->dump() ;

   return true ;
}


bool VisitBinLOr( BinaryOperator * v )
{
   std::cout << '\n' << "bool VisitBinLOr( BinaryOperator * v )" << '\n' ;

   v->dump() ;

   return true ;
}


bool VisitBinLT( BinaryOperator * v )
{
   std::cout << '\n' << "bool VisitBinLT( BinaryOperator * v )" << '\n' ;

   v->dump() ;

   return true ;
}


bool VisitBinMulAssign( CompoundAssignOperator * v )
{
   std::cout << '\n' << "bool VisitBinMulAssign( CompoundAssignOperator * v )" << '\n' ;

   v->dump() ;

   return true ;
}


bool VisitBinMul( BinaryOperator * v )
{
   std::cout << '\n' << "bool VisitBinMul( BinaryOperator * v )" << '\n' ;

   v->dump() ;

   return true ;
}


bool VisitBinNE( BinaryOperator * v )
{
   std::cout << '\n' << "bool VisitBinNE( BinaryOperator * v )" << '\n' ;

   v->dump() ;

   return true ;
}


bool VisitBinOrAssign( CompoundAssignOperator * v )
{
   std::cout << '\n' << "bool VisitBinOrAssign( CompoundAssignOperator * v )" << '\n' ;

   v->dump() ;

   return true ;
}


bool VisitBinOr( BinaryOperator * v )
{
   std::cout << '\n' << "bool VisitBinOr( BinaryOperator * v )" << '\n' ;

   v->dump() ;

   return true ;
}


bool VisitBinPtrMemD( BinaryOperator * v )
{
   std::cout << '\n' << "bool VisitBinPtrMemD( BinaryOperator * v )" << '\n' ;

   v->dump() ;

   return true ;
}


bool VisitBinPtrMemI( BinaryOperator * v )
{
   std::cout << '\n' << "bool VisitBinPtrMemI( BinaryOperator * v )" << '\n' ;

   v->dump() ;

   return true ;
}


bool VisitBinRemAssign( CompoundAssignOperator * v )
{
   std::cout << '\n' << "bool VisitBinRemAssign( CompoundAssignOperator * v )" << '\n' ;

   v->dump() ;

   return true ;
}


bool VisitBinRem( BinaryOperator * v )
{
   std::cout << '\n' << "bool VisitBinRem( BinaryOperator * v )" << '\n' ;

   v->dump() ;

   return true ;
}


bool VisitBinShlAssign( CompoundAssignOperator * v )
{
   std::cout << '\n' << "bool VisitBinShlAssign( CompoundAssignOperator * v )" << '\n' ;

   v->dump() ;

   return true ;
}


bool VisitBinShl( BinaryOperator * v )
{
   std::cout << '\n' << "bool VisitBinShl( BinaryOperator * v )" << '\n' ;

   v->dump() ;

   return true ;
}


bool VisitBinShrAssign( CompoundAssignOperator * v )
{
   std::cout << '\n' << "bool VisitBinShrAssign( CompoundAssignOperator * v )" << '\n' ;

   v->dump() ;

   return true ;
}


bool VisitBinShr( BinaryOperator * v )
{
   std::cout << '\n' << "bool VisitBinShr( BinaryOperator * v )" << '\n' ;

   v->dump() ;

   return true ;
}


bool VisitBinSubAssign( CompoundAssignOperator * v )
{
   std::cout << '\n' << "bool VisitBinSubAssign( CompoundAssignOperator * v )" << '\n' ;

   v->dump() ;

   return true ;
}


bool VisitBinSub( BinaryOperator * v )
{
   std::cout << '\n' << "bool VisitBinSub( BinaryOperator * v )" << '\n' ;

   v->dump() ;

   return true ;
}


bool VisitBinXorAssign( CompoundAssignOperator * v )
{
   std::cout << '\n' << "bool VisitBinXorAssign( CompoundAssignOperator * v )" << '\n' ;

   v->dump() ;

   return true ;
}


bool VisitBinXor( BinaryOperator * v )
{
   std::cout << '\n' << "bool VisitBinXor( BinaryOperator * v )" << '\n' ;

   v->dump() ;

   return true ;
}


bool VisitBlockDecl( BlockDecl * v )
{
   std::cout << '\n' << "bool VisitBlockDecl( BlockDecl * v )" << '\n' ;

   v->dump() ;

   return true ;
}


bool VisitBlockExpr( BlockExpr * v )
{
   std::cout << '\n' << "bool VisitBlockExpr( BlockExpr * v )" << '\n' ;

   v->dump() ;

   return true ;
}


bool VisitBlockPointerType( BlockPointerType * v )
{
   std::cout << '\n' << "bool VisitBlockPointerType( BlockPointerType * v )" << '\n' ;

   v->dump() ;

   return true ;
}


bool VisitBreakStmt( BreakStmt * v )
{
   std::cout << '\n' << "bool VisitBreakStmt( BreakStmt * v )" << '\n' ;

   v->dump() ;

   return true ;
}


bool VisitBuiltinType( BuiltinType * v )
{
   std::cout << '\n' << "bool VisitBuiltinType( BuiltinType * v )" << '\n' ;

   v->dump() ;

   return true ;
}


bool VisitCallExpr( CallExpr * v )
{
   std::cout << '\n' << "bool VisitCallExpr( CallExpr * v )" << '\n' ;

   v->dump() ;

   return true ;
}


bool VisitCaseStmt( CaseStmt * v )
{
   std::cout << '\n' << "bool VisitCaseStmt( CaseStmt * v )" << '\n' ;

   v->dump() ;

   return true ;
}


bool VisitCastExpr( CastExpr * v )
{
   std::cout << '\n' << "bool VisitCastExpr( CastExpr * v )" << '\n' ;

   v->dump() ;

   return true ;
}


bool VisitCharacterLiteral( CharacterLiteral * v )
{
   std::cout << '\n' << "bool VisitCharacterLiteral( CharacterLiteral * v )" << '\n' ;

   v->dump() ;

   return true ;
}


bool VisitChooseExpr( ChooseExpr * v )
{
   std::cout << '\n' << "bool VisitChooseExpr( ChooseExpr * v )" << '\n' ;

   v->dump() ;

   return true ;
}


bool VisitClassScopeFunctionSpecializationDecl( ClassScopeFunctionSpecializationDecl * v )
{
   std::cout << '\n' << "bool VisitClassScopeFunctionSpecializationDecl( ClassScopeFunctionSpecializationDecl * v )" << '\n' ;

   v->dump() ;

   return true ;
}


bool VisitClassTemplateDecl( ClassTemplateDecl * v )
{
   std::cout << '\n' << "bool VisitClassTemplateDecl( ClassTemplateDecl * v )" << '\n' ;

   v->dump() ;

   return true ;
}


bool VisitClassTemplatePartialSpecializationDecl( ClassTemplatePartialSpecializationDecl * v )
{
   std::cout << '\n' << "bool VisitClassTemplatePartialSpecializationDecl( ClassTemplatePartialSpecializationDecl * v )" << '\n' ;

   v->dump() ;

   return true ;
}


bool VisitClassTemplateSpecializationDecl( ClassTemplateSpecializationDecl * v )
{
   std::cout << '\n' << "bool VisitClassTemplateSpecializationDecl( ClassTemplateSpecializationDecl * v )" << '\n' ;

   v->dump() ;

   return true ;
}


bool VisitComplexType( ComplexType * v )
{
   std::cout << '\n' << "bool VisitComplexType( ComplexType * v )" << '\n' ;

   v->dump() ;

   return true ;
}


bool VisitCompoundAssignOperator( CompoundAssignOperator * v )
{
   std::cout << '\n' << "bool VisitCompoundAssignOperator( CompoundAssignOperator * v )" << '\n' ;

   v->dump() ;

   return true ;
}


bool VisitCompoundLiteralExpr( CompoundLiteralExpr * v )
{
   std::cout << '\n' << "bool VisitCompoundLiteralExpr( CompoundLiteralExpr * v )" << '\n' ;

   v->dump() ;

   return true ;
}


bool VisitCompoundStmt( CompoundStmt * v )
{
   std::cout << '\n' << "bool VisitCompoundStmt( CompoundStmt * v )" << '\n' ;

   v->dump() ;

   return true ;
}


bool VisitConditionalOperator( ConditionalOperator * v )
{
   std::cout << '\n' << "bool VisitConditionalOperator( ConditionalOperator * v )" << '\n' ;

   v->dump() ;

   return true ;
}


bool VisitConstantArrayType( ConstantArrayType * v )
{
   std::cout << '\n' << "bool VisitConstantArrayType( ConstantArrayType * v )" << '\n' ;

   v->dump() ;

   return true ;
}


bool VisitContinueStmt( ContinueStmt * v )
{
   std::cout << '\n' << "bool VisitContinueStmt( ContinueStmt * v )" << '\n' ;

   v->dump() ;

   return true ;
}


bool VisitCStyleCastExpr( CStyleCastExpr * v )
{
   std::cout << '\n' << "bool VisitCStyleCastExpr( CStyleCastExpr * v )" << '\n' ;

   v->dump() ;

   return true ;
}


bool VisitCUDAKernelCallExpr( CUDAKernelCallExpr * v )
{
   std::cout << '\n' << "bool VisitCUDAKernelCallExpr( CUDAKernelCallExpr * v )" << '\n' ;

   v->dump() ;

   return true ;
}


bool VisitCXXBindTemporaryExpr( CXXBindTemporaryExpr * v )
{
   std::cout << '\n' << "bool VisitCXXBindTemporaryExpr( CXXBindTemporaryExpr * v )" << '\n' ;

   v->dump() ;

   return true ;
}


bool VisitCXXBoolLiteralExpr( CXXBoolLiteralExpr * v )
{
   std::cout << '\n' << "bool VisitCXXBoolLiteralExpr( CXXBoolLiteralExpr * v )" << '\n' ;

   v->dump() ;

   return true ;
}


bool VisitCXXCatchStmt( CXXCatchStmt * v )
{
   std::cout << '\n' << "bool VisitCXXCatchStmt( CXXCatchStmt * v )" << '\n' ;

   v->dump() ;

   return true ;
}


bool VisitCXXConstCastExpr( CXXConstCastExpr * v )
{
   std::cout << '\n' << "bool VisitCXXConstCastExpr( CXXConstCastExpr * v )" << '\n' ;

   v->dump() ;

   return true ;
}


bool VisitCXXConstructExpr( CXXConstructExpr * v )
{
   std::cout << '\n' << "bool VisitCXXConstructExpr( CXXConstructExpr * v )" << '\n' ;

   v->dump() ;

   return true ;
}


bool VisitCXXConstructorDecl( CXXConstructorDecl * v )
{
   std::cout << '\n' << "bool VisitCXXConstructorDecl( CXXConstructorDecl * v )" << '\n' ;

   v->dump() ;

   return true ;
}


bool VisitCXXConversionDecl( CXXConversionDecl * v )
{
   std::cout << '\n' << "bool VisitCXXConversionDecl( CXXConversionDecl * v )" << '\n' ;

   v->dump() ;

   return true ;
}


bool VisitCXXDefaultArgExpr( CXXDefaultArgExpr * v )
{
   std::cout << '\n' << "bool VisitCXXDefaultArgExpr( CXXDefaultArgExpr * v )" << '\n' ;

   v->dump() ;

   return true ;
}


bool VisitCXXDeleteExpr( CXXDeleteExpr * v )
{
   std::cout << '\n' << "bool VisitCXXDeleteExpr( CXXDeleteExpr * v )" << '\n' ;

   v->dump() ;

   return true ;
}


bool VisitCXXDependentScopeMemberExpr( CXXDependentScopeMemberExpr * v )
{
   std::cout << '\n' << "bool VisitCXXDependentScopeMemberExpr( CXXDependentScopeMemberExpr * v )" << '\n' ;

   v->dump() ;

   return true ;
}


bool VisitCXXDestructorDecl( CXXDestructorDecl * v )
{
   std::cout << '\n' << "bool VisitCXXDestructorDecl( CXXDestructorDecl * v )" << '\n' ;

   v->dump() ;

   return true ;
}


bool VisitCXXDynamicCastExpr( CXXDynamicCastExpr * v )
{
   std::cout << '\n' << "bool VisitCXXDynamicCastExpr( CXXDynamicCastExpr * v )" << '\n' ;

   v->dump() ;

   return true ;
}


bool VisitCXXForRangeStmt( CXXForRangeStmt * v )
{
   std::cout << '\n' << "bool VisitCXXForRangeStmt( CXXForRangeStmt * v )" << '\n' ;

   v->dump() ;

   return true ;
}


bool VisitCXXFunctionalCastExpr( CXXFunctionalCastExpr * v )
{
   std::cout << '\n' << "bool VisitCXXFunctionalCastExpr( CXXFunctionalCastExpr * v )" << '\n' ;

   v->dump() ;

   return true ;
}


bool VisitCXXMemberCallExpr( CXXMemberCallExpr * v )
{
   std::cout << '\n' << "bool VisitCXXMemberCallExpr( CXXMemberCallExpr * v )" << '\n' ;

   v->dump() ;

   return true ;
}


bool VisitCXXMethodDecl( CXXMethodDecl * v )
{
   std::cout << '\n' << "bool VisitCXXMethodDecl( CXXMethodDecl * v )" << '\n' ;

   v->dump() ;

   return true ;
}


bool VisitCXXNamedCastExpr( CXXNamedCastExpr * v )
{
   std::cout << '\n' << "bool VisitCXXNamedCastExpr( CXXNamedCastExpr * v )" << '\n' ;

   v->dump() ;

   return true ;
}


bool VisitCXXNewExpr( CXXNewExpr * v )
{
   std::cout << '\n' << "bool VisitCXXNewExpr( CXXNewExpr * v )" << '\n' ;

   v->dump() ;

   return true ;
}


bool VisitCXXNoexceptExpr( CXXNoexceptExpr * v )
{
   std::cout << '\n' << "bool VisitCXXNoexceptExpr( CXXNoexceptExpr * v )" << '\n' ;

   v->dump() ;

   return true ;
}


bool VisitCXXNullPtrLiteralExpr( CXXNullPtrLiteralExpr * v )
{
   std::cout << '\n' << "bool VisitCXXNullPtrLiteralExpr( CXXNullPtrLiteralExpr * v )" << '\n' ;

   v->dump() ;

   return true ;
}


bool VisitCXXOperatorCallExpr( CXXOperatorCallExpr * v )
{
   std::cout << '\n' << "bool VisitCXXOperatorCallExpr( CXXOperatorCallExpr * v )" << '\n' ;

   v->dump() ;

   return true ;
}


bool VisitCXXPseudoDestructorExpr( CXXPseudoDestructorExpr * v )
{
   std::cout << '\n' << "bool VisitCXXPseudoDestructorExpr( CXXPseudoDestructorExpr * v )" << '\n' ;

   v->dump() ;

   return true ;
}


bool VisitCXXReinterpretCastExpr( CXXReinterpretCastExpr * v )
{
   std::cout << '\n' << "bool VisitCXXReinterpretCastExpr( CXXReinterpretCastExpr * v )" << '\n' ;

   v->dump() ;

   return true ;
}


bool VisitCXXScalarValueInitExpr( CXXScalarValueInitExpr * v )
{
   std::cout << '\n' << "bool VisitCXXScalarValueInitExpr( CXXScalarValueInitExpr * v )" << '\n' ;

   v->dump() ;

   return true ;
}


bool VisitCXXStaticCastExpr( CXXStaticCastExpr * v )
{
   std::cout << '\n' << "bool VisitCXXStaticCastExpr( CXXStaticCastExpr * v )" << '\n' ;

   v->dump() ;

   return true ;
}


bool VisitCXXTemporaryObjectExpr( CXXTemporaryObjectExpr * v )
{
   std::cout << '\n' << "bool VisitCXXTemporaryObjectExpr( CXXTemporaryObjectExpr * v )" << '\n' ;

   v->dump() ;

   return true ;
}


bool VisitCXXThisExpr( CXXThisExpr * v )
{
   std::cout << '\n' << "bool VisitCXXThisExpr( CXXThisExpr * v )" << '\n' ;

   v->dump() ;

   return true ;
}


bool VisitCXXThrowExpr( CXXThrowExpr * v )
{
   std::cout << '\n' << "bool VisitCXXThrowExpr( CXXThrowExpr * v )" << '\n' ;

   v->dump() ;

   return true ;
}


bool VisitCXXTryStmt( CXXTryStmt * v )
{
   std::cout << '\n' << "bool VisitCXXTryStmt( CXXTryStmt * v )" << '\n' ;

   v->dump() ;

   return true ;
}


bool VisitCXXTypeidExpr( CXXTypeidExpr * v )
{
   std::cout << '\n' << "bool VisitCXXTypeidExpr( CXXTypeidExpr * v )" << '\n' ;

   v->dump() ;

   return true ;
}


bool VisitCXXUnresolvedConstructExpr( CXXUnresolvedConstructExpr * v )
{
   std::cout << '\n' << "bool VisitCXXUnresolvedConstructExpr( CXXUnresolvedConstructExpr * v )" << '\n' ;

   v->dump() ;

   return true ;
}


bool VisitCXXUuidofExpr( CXXUuidofExpr * v )
{
   std::cout << '\n' << "bool VisitCXXUuidofExpr( CXXUuidofExpr * v )" << '\n' ;

   v->dump() ;

   return true ;
}


bool VisitDeclaratorDecl( DeclaratorDecl * v )
{
   std::cout << '\n' << "bool VisitDeclaratorDecl( DeclaratorDecl * v )" << '\n' ;

   v->dump() ;

   return true ;
}


bool VisitDecl( Decl * v )
{
   std::cout << '\n' << "bool VisitDecl( Decl * v )" << '\n' ;

   v->dump() ;

   return true ;
}


bool VisitDeclRefExpr( DeclRefExpr * v )
{
   std::cout << '\n' << "bool VisitDeclRefExpr( DeclRefExpr * v )" << '\n' ;

   v->dump() ;

   return true ;
}


bool VisitDeclStmt( DeclStmt * v )
{
   std::cout << '\n' << "bool VisitDeclStmt( DeclStmt * v )" << '\n' ;

   v->dump() ;

   return true ;
}


bool VisitDecltypeType( DecltypeType * v )
{
   std::cout << '\n' << "bool VisitDecltypeType( DecltypeType * v )" << '\n' ;

   v->dump() ;

   return true ;
}


bool VisitDefaultStmt( DefaultStmt * v )
{
   std::cout << '\n' << "bool VisitDefaultStmt( DefaultStmt * v )" << '\n' ;

   v->dump() ;

   return true ;
}


bool VisitDependentNameType( DependentNameType * v )
{
   std::cout << '\n' << "bool VisitDependentNameType( DependentNameType * v )" << '\n' ;

   v->dump() ;

   return true ;
}


bool VisitDependentScopeDeclRefExpr( DependentScopeDeclRefExpr * v )
{
   std::cout << '\n' << "bool VisitDependentScopeDeclRefExpr( DependentScopeDeclRefExpr * v )" << '\n' ;

   v->dump() ;

   return true ;
}


bool VisitDependentSizedArrayType( DependentSizedArrayType * v )
{
   std::cout << '\n' << "bool VisitDependentSizedArrayType( DependentSizedArrayType * v )" << '\n' ;

   v->dump() ;

   return true ;
}


bool VisitDependentSizedExtVectorType( DependentSizedExtVectorType * v )
{
   std::cout << '\n' << "bool VisitDependentSizedExtVectorType( DependentSizedExtVectorType * v )" << '\n' ;

   v->dump() ;

   return true ;
}


bool VisitDependentTemplateSpecializationType( DependentTemplateSpecializationType * v )
{
   std::cout << '\n' << "bool VisitDependentTemplateSpecializationType( DependentTemplateSpecializationType * v )" << '\n' ;

   v->dump() ;

   return true ;
}


bool VisitDesignatedInitExpr( DesignatedInitExpr * v )
{
   std::cout << '\n' << "bool VisitDesignatedInitExpr( DesignatedInitExpr * v )" << '\n' ;

   v->dump() ;

   return true ;
}


bool VisitDoStmt( DoStmt * v )
{
   std::cout << '\n' << "bool VisitDoStmt( DoStmt * v )" << '\n' ;

   v->dump() ;

   return true ;
}


bool VisitElaboratedType( ElaboratedType * v )
{
   std::cout << '\n' << "bool VisitElaboratedType( ElaboratedType * v )" << '\n' ;

   v->dump() ;

   return true ;
}


bool VisitEnumConstantDecl( EnumConstantDecl * v )
{
   std::cout << '\n' << "bool VisitEnumConstantDecl( EnumConstantDecl * v )" << '\n' ;

   v->dump() ;

   return true ;
}


bool VisitEnumDecl( EnumDecl * v )
{
   std::cout << '\n' << "bool VisitEnumDecl( EnumDecl * v )" << '\n' ;

   v->dump() ;

   return true ;
}


bool VisitEnumType( EnumType * v )
{
   std::cout << '\n' << "bool VisitEnumType( EnumType * v )" << '\n' ;

   v->dump() ;

   return true ;
}


bool VisitExplicitCastExpr( ExplicitCastExpr * v )
{
   std::cout << '\n' << "bool VisitExplicitCastExpr( ExplicitCastExpr * v )" << '\n' ;

   v->dump() ;

   return true ;
}


bool VisitExpressionTraitExpr( ExpressionTraitExpr * v )
{
   std::cout << '\n' << "bool VisitExpressionTraitExpr( ExpressionTraitExpr * v )" << '\n' ;

   v->dump() ;

   return true ;
}


bool VisitExpr( Expr * v )
{
   std::cout << '\n' << "bool VisitExpr( Expr * v )" << '\n' ;

   v->dump() ;

   return true ;
}


bool VisitExprWithCleanups( ExprWithCleanups * v )
{
   std::cout << '\n' << "bool VisitExprWithCleanups( ExprWithCleanups * v )" << '\n' ;

   v->dump() ;

   return true ;
}


bool VisitExtVectorElementExpr( ExtVectorElementExpr * v )
{
   std::cout << '\n' << "bool VisitExtVectorElementExpr( ExtVectorElementExpr * v )" << '\n' ;

   v->dump() ;

   return true ;
}


bool VisitExtVectorType( ExtVectorType * v )
{
   std::cout << '\n' << "bool VisitExtVectorType( ExtVectorType * v )" << '\n' ;

   v->dump() ;

   return true ;
}


bool VisitFileScopeAsmDecl( FileScopeAsmDecl * v )
{
   std::cout << '\n' << "bool VisitFileScopeAsmDecl( FileScopeAsmDecl * v )" << '\n' ;

   v->dump() ;

   return true ;
}


bool VisitFloatingLiteral( FloatingLiteral * v )
{
   std::cout << '\n' << "bool VisitFloatingLiteral( FloatingLiteral * v )" << '\n' ;

   v->dump() ;

   return true ;
}


bool VisitForStmt( ForStmt * v )
{
   std::cout << '\n' << "bool VisitForStmt( ForStmt * v )" << '\n' ;

   v->dump() ;

   return true ;
}


bool VisitFriendDecl( FriendDecl * v )
{
   std::cout << '\n' << "bool VisitFriendDecl( FriendDecl * v )" << '\n' ;

   v->dump() ;

   return true ;
}


bool VisitFriendTemplateDecl( FriendTemplateDecl * v )
{
   std::cout << '\n' << "bool VisitFriendTemplateDecl( FriendTemplateDecl * v )" << '\n' ;

   v->dump() ;

   return true ;
}


bool VisitFunctionDecl( FunctionDecl * v )
{
   std::cout << '\n' << "bool VisitFunctionDecl( FunctionDecl * v )" << '\n' ;

   v->dump() ;

   return true ;
}


bool VisitFunctionNoProtoType( FunctionNoProtoType * v )
{
   std::cout << '\n' << "bool VisitFunctionNoProtoType( FunctionNoProtoType * v )" << '\n' ;

   v->dump() ;

   return true ;
}


bool VisitFunctionParmPackExpr( FunctionParmPackExpr * v )
{
   std::cout << '\n' << "bool VisitFunctionParmPackExpr( FunctionParmPackExpr * v )" << '\n' ;

   v->dump() ;

   return true ;
}


bool VisitFunctionProtoType( FunctionProtoType * v )
{
   std::cout << '\n' << "bool VisitFunctionProtoType( FunctionProtoType * v )" << '\n' ;

   v->dump() ;

   return true ;
}


bool VisitFunctionTemplateDecl( FunctionTemplateDecl * v )
{
   std::cout << '\n' << "bool VisitFunctionTemplateDecl( FunctionTemplateDecl * v )" << '\n' ;

   v->dump() ;

   return true ;
}


bool VisitFunctionType( FunctionType * v )
{
   std::cout << '\n' << "bool VisitFunctionType( FunctionType * v )" << '\n' ;

   v->dump() ;

   return true ;
}


bool VisitGCCAsmStmt( GCCAsmStmt * v )
{
   std::cout << '\n' << "bool VisitGCCAsmStmt( GCCAsmStmt * v )" << '\n' ;

   v->dump() ;

   return true ;
}


bool VisitGenericSelectionExpr( GenericSelectionExpr * v )
{
   std::cout << '\n' << "bool VisitGenericSelectionExpr( GenericSelectionExpr * v )" << '\n' ;

   v->dump() ;

   return true ;
}


bool VisitGNUNullExpr( GNUNullExpr * v )
{
   std::cout << '\n' << "bool VisitGNUNullExpr( GNUNullExpr * v )" << '\n' ;

   v->dump() ;

   return true ;
}


bool VisitGotoStmt( GotoStmt * v )
{
   std::cout << '\n' << "bool VisitGotoStmt( GotoStmt * v )" << '\n' ;

   v->dump() ;

   return true ;
}


bool VisitIfStmt( IfStmt * v )
{
   std::cout << '\n' << "bool VisitIfStmt( IfStmt * v )" << '\n' ;

   v->dump() ;

   return true ;
}


bool VisitImaginaryLiteral( ImaginaryLiteral * v )
{
   std::cout << '\n' << "bool VisitImaginaryLiteral( ImaginaryLiteral * v )" << '\n' ;

   v->dump() ;

   return true ;
}


bool VisitImplicitCastExpr( ImplicitCastExpr * v )
{
   std::cout << '\n' << "bool VisitImplicitCastExpr( ImplicitCastExpr * v )" << '\n' ;

   v->dump() ;

   return true ;
}


bool VisitImplicitParamDecl( ImplicitParamDecl * v )
{
   std::cout << '\n' << "bool VisitImplicitParamDecl( ImplicitParamDecl * v )" << '\n' ;

   v->dump() ;

   return true ;
}


bool VisitImplicitValueInitExpr( ImplicitValueInitExpr * v )
{
   std::cout << '\n' << "bool VisitImplicitValueInitExpr( ImplicitValueInitExpr * v )" << '\n' ;

   v->dump() ;

   return true ;
}


bool VisitImportDecl( ImportDecl * v )
{
   std::cout << '\n' << "bool VisitImportDecl( ImportDecl * v )" << '\n' ;

   v->dump() ;

   return true ;
}


bool VisitIncompleteArrayType( IncompleteArrayType * v )
{
   std::cout << '\n' << "bool VisitIncompleteArrayType( IncompleteArrayType * v )" << '\n' ;

   v->dump() ;

   return true ;
}


bool VisitIndirectFieldDecl( IndirectFieldDecl * v )
{
   std::cout << '\n' << "bool VisitIndirectFieldDecl( IndirectFieldDecl * v )" << '\n' ;

   v->dump() ;

   return true ;
}


bool VisitIndirectGotoStmt( IndirectGotoStmt * v )
{
   std::cout << '\n' << "bool VisitIndirectGotoStmt( IndirectGotoStmt * v )" << '\n' ;

   v->dump() ;

   return true ;
}


bool VisitInitListExpr( InitListExpr * v )
{
   std::cout << '\n' << "bool VisitInitListExpr( InitListExpr * v )" << '\n' ;

   v->dump() ;

   return true ;
}


bool VisitInjectedClassNameType( InjectedClassNameType * v )
{
   std::cout << '\n' << "bool VisitInjectedClassNameType( InjectedClassNameType * v )" << '\n' ;

   v->dump() ;

   return true ;
}


bool VisitIntegerLiteral( IntegerLiteral * v )
{
   std::cout << '\n' << "bool VisitIntegerLiteral( IntegerLiteral * v )" << '\n' ;

   v->dump() ;

   return true ;
}


bool VisitLabelDecl( LabelDecl * v )
{
   std::cout << '\n' << "bool VisitLabelDecl( LabelDecl * v )" << '\n' ;

   v->dump() ;

   return true ;
}


bool VisitLabelStmt( LabelStmt * v )
{
   std::cout << '\n' << "bool VisitLabelStmt( LabelStmt * v )" << '\n' ;

   v->dump() ;

   return true ;
}


bool VisitLambdaExpr( LambdaExpr * v )
{
   std::cout << '\n' << "bool VisitLambdaExpr( LambdaExpr * v )" << '\n' ;

   v->dump() ;

   return true ;
}


bool VisitLinkageSpecDecl( LinkageSpecDecl * v )
{
   std::cout << '\n' << "bool VisitLinkageSpecDecl( LinkageSpecDecl * v )" << '\n' ;

   v->dump() ;

   return true ;
}


bool VisitLValueReferenceType( LValueReferenceType * v )
{
   std::cout << '\n' << "bool VisitLValueReferenceType( LValueReferenceType * v )" << '\n' ;

   v->dump() ;

   return true ;
}


bool VisitMaterializeTemporaryExpr( MaterializeTemporaryExpr * v )
{
   std::cout << '\n' << "bool VisitMaterializeTemporaryExpr( MaterializeTemporaryExpr * v )" << '\n' ;

   v->dump() ;

   return true ;
}


bool VisitMemberExpr( MemberExpr * v )
{
   std::cout << '\n' << "bool VisitMemberExpr( MemberExpr * v )" << '\n' ;

   v->dump() ;

   return true ;
}


bool VisitMemberPointerType( MemberPointerType * v )
{
   std::cout << '\n' << "bool VisitMemberPointerType( MemberPointerType * v )" << '\n' ;

   v->dump() ;

   return true ;
}


bool VisitMSAsmStmt( MSAsmStmt * v )
{
   std::cout << '\n' << "bool VisitMSAsmStmt( MSAsmStmt * v )" << '\n' ;

   v->dump() ;

   return true ;
}


bool VisitMSDependentExistsStmt( MSDependentExistsStmt * v )
{
   std::cout << '\n' << "bool VisitMSDependentExistsStmt( MSDependentExistsStmt * v )" << '\n' ;

   v->dump() ;

   return true ;
}


bool VisitNamedDecl( NamedDecl * v )
{
   std::cout << '\n' << "bool VisitNamedDecl( NamedDecl * v )" << '\n' ;

   v->dump() ;

   return true ;
}


bool VisitNamespaceAliasDecl( NamespaceAliasDecl * v )
{
   std::cout << '\n' << "bool VisitNamespaceAliasDecl( NamespaceAliasDecl * v )" << '\n' ;

   v->dump() ;

   return true ;
}


bool VisitNamespaceDecl( NamespaceDecl * v )
{
   std::cout << '\n' << "bool VisitNamespaceDecl( NamespaceDecl * v )" << '\n' ;

   v->dump() ;

   return true ;
}


bool VisitNonTypeTemplateParmDecl( NonTypeTemplateParmDecl * v )
{
   std::cout << '\n' << "bool VisitNonTypeTemplateParmDecl( NonTypeTemplateParmDecl * v )" << '\n' ;

   v->dump() ;

   return true ;
}


bool VisitNullStmt( NullStmt * v )
{
   std::cout << '\n' << "bool VisitNullStmt( NullStmt * v )" << '\n' ;

   v->dump() ;

   return true ;
}


bool VisitObjCArrayLiteral( ObjCArrayLiteral * v )
{
   std::cout << '\n' << "bool VisitObjCArrayLiteral( ObjCArrayLiteral * v )" << '\n' ;

   v->dump() ;

   return true ;
}


bool VisitObjCAtCatchStmt( ObjCAtCatchStmt * v )
{
   std::cout << '\n' << "bool VisitObjCAtCatchStmt( ObjCAtCatchStmt * v )" << '\n' ;

   v->dump() ;

   return true ;
}


bool VisitObjCAtDefsFieldDecl( ObjCAtDefsFieldDecl * v )
{
   std::cout << '\n' << "bool VisitObjCAtDefsFieldDecl( ObjCAtDefsFieldDecl * v )" << '\n' ;

   v->dump() ;

   return true ;
}


bool VisitObjCAtFinallyStmt( ObjCAtFinallyStmt * v )
{
   std::cout << '\n' << "bool VisitObjCAtFinallyStmt( ObjCAtFinallyStmt * v )" << '\n' ;

   v->dump() ;

   return true ;
}


bool VisitObjCAtSynchronizedStmt( ObjCAtSynchronizedStmt * v )
{
   std::cout << '\n' << "bool VisitObjCAtSynchronizedStmt( ObjCAtSynchronizedStmt * v )" << '\n' ;

   v->dump() ;

   return true ;
}


bool VisitObjCAtThrowStmt( ObjCAtThrowStmt * v )
{
   std::cout << '\n' << "bool VisitObjCAtThrowStmt( ObjCAtThrowStmt * v )" << '\n' ;

   v->dump() ;

   return true ;
}


bool VisitObjCAtTryStmt( ObjCAtTryStmt * v )
{
   std::cout << '\n' << "bool VisitObjCAtTryStmt( ObjCAtTryStmt * v )" << '\n' ;

   v->dump() ;

   return true ;
}


bool VisitObjCAutoreleasePoolStmt( ObjCAutoreleasePoolStmt * v )
{
   std::cout << '\n' << "bool VisitObjCAutoreleasePoolStmt( ObjCAutoreleasePoolStmt * v )" << '\n' ;

   v->dump() ;

   return true ;
}


bool VisitObjCBoolLiteralExpr( ObjCBoolLiteralExpr * v )
{
   std::cout << '\n' << "bool VisitObjCBoolLiteralExpr( ObjCBoolLiteralExpr * v )" << '\n' ;

   v->dump() ;

   return true ;
}


bool VisitObjCBoxedExpr( ObjCBoxedExpr * v )
{
   std::cout << '\n' << "bool VisitObjCBoxedExpr( ObjCBoxedExpr * v )" << '\n' ;

   v->dump() ;

   return true ;
}


bool VisitObjCBridgedCastExpr( ObjCBridgedCastExpr * v )
{
   std::cout << '\n' << "bool VisitObjCBridgedCastExpr( ObjCBridgedCastExpr * v )" << '\n' ;

   v->dump() ;

   return true ;
}


bool VisitObjCCategoryDecl( ObjCCategoryDecl * v )
{
   std::cout << '\n' << "bool VisitObjCCategoryDecl( ObjCCategoryDecl * v )" << '\n' ;

   v->dump() ;

   return true ;
}


bool VisitObjCCategoryImplDecl( ObjCCategoryImplDecl * v )
{
   std::cout << '\n' << "bool VisitObjCCategoryImplDecl( ObjCCategoryImplDecl * v )" << '\n' ;

   v->dump() ;

   return true ;
}


bool VisitObjCCompatibleAliasDecl( ObjCCompatibleAliasDecl * v )
{
   std::cout << '\n' << "bool VisitObjCCompatibleAliasDecl( ObjCCompatibleAliasDecl * v )" << '\n' ;

   v->dump() ;

   return true ;
}


bool VisitObjCContainerDecl( ObjCContainerDecl * v )
{
   std::cout << '\n' << "bool VisitObjCContainerDecl( ObjCContainerDecl * v )" << '\n' ;

   v->dump() ;

   return true ;
}


bool VisitObjCDictionaryLiteral( ObjCDictionaryLiteral * v )
{
   std::cout << '\n' << "bool VisitObjCDictionaryLiteral( ObjCDictionaryLiteral * v )" << '\n' ;

   v->dump() ;

   return true ;
}


bool VisitObjCEncodeExpr( ObjCEncodeExpr * v )
{
   std::cout << '\n' << "bool VisitObjCEncodeExpr( ObjCEncodeExpr * v )" << '\n' ;

   v->dump() ;

   return true ;
}


bool VisitObjCForCollectionStmt( ObjCForCollectionStmt * v )
{
   std::cout << '\n' << "bool VisitObjCForCollectionStmt( ObjCForCollectionStmt * v )" << '\n' ;

   v->dump() ;

   return true ;
}


bool VisitObjCImplDecl( ObjCImplDecl * v )
{
   std::cout << '\n' << "bool VisitObjCImplDecl( ObjCImplDecl * v )" << '\n' ;

   v->dump() ;

   return true ;
}


bool VisitObjCImplementationDecl( ObjCImplementationDecl * v )
{
   std::cout << '\n' << "bool VisitObjCImplementationDecl( ObjCImplementationDecl * v )" << '\n' ;

   v->dump() ;

   return true ;
}


bool VisitObjCIndirectCopyRestoreExpr( ObjCIndirectCopyRestoreExpr * v )
{
   std::cout << '\n' << "bool VisitObjCIndirectCopyRestoreExpr( ObjCIndirectCopyRestoreExpr * v )" << '\n' ;

   v->dump() ;

   return true ;
}


bool VisitObjCInterfaceDecl( ObjCInterfaceDecl * v )
{
   std::cout << '\n' << "bool VisitObjCInterfaceDecl( ObjCInterfaceDecl * v )" << '\n' ;

   v->dump() ;

   return true ;
}


bool VisitObjCInterfaceType( ObjCInterfaceType * v )
{
   std::cout << '\n' << "bool VisitObjCInterfaceType( ObjCInterfaceType * v )" << '\n' ;

   v->dump() ;

   return true ;
}


bool VisitObjCIsaExpr( ObjCIsaExpr * v )
{
   std::cout << '\n' << "bool VisitObjCIsaExpr( ObjCIsaExpr * v )" << '\n' ;

   v->dump() ;

   return true ;
}


bool VisitObjCIvarDecl( ObjCIvarDecl * v )
{
   std::cout << '\n' << "bool VisitObjCIvarDecl( ObjCIvarDecl * v )" << '\n' ;

   v->dump() ;

   return true ;
}


bool VisitObjCIvarRefExpr( ObjCIvarRefExpr * v )
{
   std::cout << '\n' << "bool VisitObjCIvarRefExpr( ObjCIvarRefExpr * v )" << '\n' ;

   v->dump() ;

   return true ;
}


bool VisitObjCMessageExpr( ObjCMessageExpr * v )
{
   std::cout << '\n' << "bool VisitObjCMessageExpr( ObjCMessageExpr * v )" << '\n' ;

   v->dump() ;

   return true ;
}


bool VisitObjCMethodDecl( ObjCMethodDecl * v )
{
   std::cout << '\n' << "bool VisitObjCMethodDecl( ObjCMethodDecl * v )" << '\n' ;

   v->dump() ;

   return true ;
}


bool VisitObjCObjectPointerType( ObjCObjectPointerType * v )
{
   std::cout << '\n' << "bool VisitObjCObjectPointerType( ObjCObjectPointerType * v )" << '\n' ;

   v->dump() ;

   return true ;
}


bool VisitObjCObjectType( ObjCObjectType * v )
{
   std::cout << '\n' << "bool VisitObjCObjectType( ObjCObjectType * v )" << '\n' ;

   v->dump() ;

   return true ;
}


bool VisitObjCPropertyDecl( ObjCPropertyDecl * v )
{
   std::cout << '\n' << "bool VisitObjCPropertyDecl( ObjCPropertyDecl * v )" << '\n' ;

   v->dump() ;

   return true ;
}


bool VisitObjCPropertyImplDecl( ObjCPropertyImplDecl * v )
{
   std::cout << '\n' << "bool VisitObjCPropertyImplDecl( ObjCPropertyImplDecl * v )" << '\n' ;

   v->dump() ;

   return true ;
}


bool VisitObjCPropertyRefExpr( ObjCPropertyRefExpr * v )
{
   std::cout << '\n' << "bool VisitObjCPropertyRefExpr( ObjCPropertyRefExpr * v )" << '\n' ;

   v->dump() ;

   return true ;
}


bool VisitObjCProtocolDecl( ObjCProtocolDecl * v )
{
   std::cout << '\n' << "bool VisitObjCProtocolDecl( ObjCProtocolDecl * v )" << '\n' ;

   v->dump() ;

   return true ;
}


bool VisitObjCProtocolExpr( ObjCProtocolExpr * v )
{
   std::cout << '\n' << "bool VisitObjCProtocolExpr( ObjCProtocolExpr * v )" << '\n' ;

   v->dump() ;

   return true ;
}


bool VisitObjCSelectorExpr( ObjCSelectorExpr * v )
{
   std::cout << '\n' << "bool VisitObjCSelectorExpr( ObjCSelectorExpr * v )" << '\n' ;

   v->dump() ;

   return true ;
}


bool VisitObjCStringLiteral( ObjCStringLiteral * v )
{
   std::cout << '\n' << "bool VisitObjCStringLiteral( ObjCStringLiteral * v )" << '\n' ;

   v->dump() ;

   return true ;
}


bool VisitObjCSubscriptRefExpr( ObjCSubscriptRefExpr * v )
{
   std::cout << '\n' << "bool VisitObjCSubscriptRefExpr( ObjCSubscriptRefExpr * v )" << '\n' ;

   v->dump() ;

   return true ;
}


bool VisitOffsetOfExpr( OffsetOfExpr * v )
{
   std::cout << '\n' << "bool VisitOffsetOfExpr( OffsetOfExpr * v )" << '\n' ;

   v->dump() ;

   return true ;
}


bool VisitOpaqueValueExpr( OpaqueValueExpr * v )
{
   std::cout << '\n' << "bool VisitOpaqueValueExpr( OpaqueValueExpr * v )" << '\n' ;

   v->dump() ;

   return true ;
}


bool VisitOverloadExpr( OverloadExpr * v )
{
   std::cout << '\n' << "bool VisitOverloadExpr( OverloadExpr * v )" << '\n' ;

   v->dump() ;

   return true ;
}


bool VisitPackExpansionExpr( PackExpansionExpr * v )
{
   std::cout << '\n' << "bool VisitPackExpansionExpr( PackExpansionExpr * v )" << '\n' ;

   v->dump() ;

   return true ;
}


bool VisitPackExpansionType( PackExpansionType * v )
{
   std::cout << '\n' << "bool VisitPackExpansionType( PackExpansionType * v )" << '\n' ;

   v->dump() ;

   return true ;
}


bool VisitParenExpr( ParenExpr * v )
{
   std::cout << '\n' << "bool VisitParenExpr( ParenExpr * v )" << '\n' ;

   v->dump() ;

   return true ;
}


bool VisitParenListExpr( ParenListExpr * v )
{
   std::cout << '\n' << "bool VisitParenListExpr( ParenListExpr * v )" << '\n' ;

   v->dump() ;

   return true ;
}


bool VisitParenType( ParenType * v )
{
   std::cout << '\n' << "bool VisitParenType( ParenType * v )" << '\n' ;

   v->dump() ;

   return true ;
}


bool VisitParmVarDecl( ParmVarDecl * v )
{
   std::cout << '\n' << "bool VisitParmVarDecl( ParmVarDecl * v )" << '\n' ;

   v->dump() ;

   return true ;
}


bool VisitPointerType( PointerType * v )
{
   std::cout << '\n' << "bool VisitPointerType( PointerType * v )" << '\n' ;

   v->dump() ;

   return true ;
}


bool VisitPredefinedExpr( PredefinedExpr * v )
{
   std::cout << '\n' << "bool VisitPredefinedExpr( PredefinedExpr * v )" << '\n' ;

   v->dump() ;

   return true ;
}


bool VisitPseudoObjectExpr( PseudoObjectExpr * v )
{
   std::cout << '\n' << "bool VisitPseudoObjectExpr( PseudoObjectExpr * v )" << '\n' ;

   v->dump() ;

   return true ;
}


bool VisitRecordDecl( RecordDecl * v )
{
   std::cout << '\n' << "bool VisitRecordDecl( RecordDecl * v )" << '\n' ;

   v->dump() ;

   return true ;
}


bool VisitRecordType( RecordType * v )
{
   std::cout << '\n' << "bool VisitRecordType( RecordType * v )" << '\n' ;

   v->dump() ;

   return true ;
}


bool VisitRedeclarableTemplateDecl( RedeclarableTemplateDecl * v )
{
   std::cout << '\n' << "bool VisitRedeclarableTemplateDecl( RedeclarableTemplateDecl * v )" << '\n' ;

   v->dump() ;

   return true ;
}


bool VisitReferenceType( ReferenceType * v )
{
   std::cout << '\n' << "bool VisitReferenceType( ReferenceType * v )" << '\n' ;

   v->dump() ;

   return true ;
}


bool VisitReturnStmt( ReturnStmt * v )
{
   std::cout << '\n' << "bool VisitReturnStmt( ReturnStmt * v )" << '\n' ;

   v->dump() ;

   return true ;
}


bool VisitRValueReferenceType( RValueReferenceType * v )
{
   std::cout << '\n' << "bool VisitRValueReferenceType( RValueReferenceType * v )" << '\n' ;

   v->dump() ;

   return true ;
}


bool VisitSEHExceptStmt( SEHExceptStmt * v )
{
   std::cout << '\n' << "bool VisitSEHExceptStmt( SEHExceptStmt * v )" << '\n' ;

   v->dump() ;

   return true ;
}


bool VisitSEHFinallyStmt( SEHFinallyStmt * v )
{
   std::cout << '\n' << "bool VisitSEHFinallyStmt( SEHFinallyStmt * v )" << '\n' ;

   v->dump() ;

   return true ;
}


bool VisitSEHTryStmt( SEHTryStmt * v )
{
   std::cout << '\n' << "bool VisitSEHTryStmt( SEHTryStmt * v )" << '\n' ;

   v->dump() ;

   return true ;
}


bool VisitShuffleVectorExpr( ShuffleVectorExpr * v )
{
   std::cout << '\n' << "bool VisitShuffleVectorExpr( ShuffleVectorExpr * v )" << '\n' ;

   v->dump() ;

   return true ;
}


bool VisitSizeOfPackExpr( SizeOfPackExpr * v )
{
   std::cout << '\n' << "bool VisitSizeOfPackExpr( SizeOfPackExpr * v )" << '\n' ;

   v->dump() ;

   return true ;
}


bool VisitStaticAssertDecl( StaticAssertDecl * v )
{
   std::cout << '\n' << "bool VisitStaticAssertDecl( StaticAssertDecl * v )" << '\n' ;

   v->dump() ;

   return true ;
}


bool VisitStmtExpr( StmtExpr * v )
{
   std::cout << '\n' << "bool VisitStmtExpr( StmtExpr * v )" << '\n' ;

   v->dump() ;

   return true ;
}


bool VisitStmt( Stmt * v )
{
   std::cout << '\n' << "bool VisitStmt( Stmt * v )" << '\n' ;

   v->dump() ;

   return true ;
}


bool VisitStringLiteral( StringLiteral * v )
{
   std::cout << '\n' << "bool VisitStringLiteral( StringLiteral * v )" << '\n' ;

   v->dump() ;

   return true ;
}


bool VisitSubstNonTypeTemplateParmExpr( SubstNonTypeTemplateParmExpr * v )
{
   std::cout << '\n' << "bool VisitSubstNonTypeTemplateParmExpr( SubstNonTypeTemplateParmExpr * v )" << '\n' ;

   v->dump() ;

   return true ;
}


bool VisitSubstNonTypeTemplateParmPackExpr( SubstNonTypeTemplateParmPackExpr * v )
{
   std::cout << '\n' << "bool VisitSubstNonTypeTemplateParmPackExpr( SubstNonTypeTemplateParmPackExpr * v )" << '\n' ;

   v->dump() ;

   return true ;
}


bool VisitSubstTemplateTypeParmPackType( SubstTemplateTypeParmPackType * v )
{
   std::cout << '\n' << "bool VisitSubstTemplateTypeParmPackType( SubstTemplateTypeParmPackType * v )" << '\n' ;

   v->dump() ;

   return true ;
}


bool VisitSubstTemplateTypeParmType( SubstTemplateTypeParmType * v )
{
   std::cout << '\n' << "bool VisitSubstTemplateTypeParmType( SubstTemplateTypeParmType * v )" << '\n' ;

   v->dump() ;

   return true ;
}


bool VisitSwitchCase( SwitchCase * v )
{
   std::cout << '\n' << "bool VisitSwitchCase( SwitchCase * v )" << '\n' ;

   v->dump() ;

   return true ;
}


bool VisitSwitchStmt( SwitchStmt * v )
{
   std::cout << '\n' << "bool VisitSwitchStmt( SwitchStmt * v )" << '\n' ;

   v->dump() ;

   return true ;
}


bool VisitTagDecl( TagDecl * v )
{
   std::cout << '\n' << "bool VisitTagDecl( TagDecl * v )" << '\n' ;

   v->dump() ;

   return true ;
}


bool VisitTagType( TagType * v )
{
   std::cout << '\n' << "bool VisitTagType( TagType * v )" << '\n' ;

   v->dump() ;

   return true ;
}


bool VisitTemplateDecl( TemplateDecl * v )
{
   std::cout << '\n' << "bool VisitTemplateDecl( TemplateDecl * v )" << '\n' ;

   v->dump() ;

   return true ;
}


bool VisitTemplateSpecializationType( TemplateSpecializationType * v )
{
   std::cout << '\n' << "bool VisitTemplateSpecializationType( TemplateSpecializationType * v )" << '\n' ;

   v->dump() ;

   return true ;
}


bool VisitTemplateTemplateParmDecl( TemplateTemplateParmDecl * v )
{
   std::cout << '\n' << "bool VisitTemplateTemplateParmDecl( TemplateTemplateParmDecl * v )" << '\n' ;

   v->dump() ;

   return true ;
}


bool VisitTemplateTypeParmDecl( TemplateTypeParmDecl * v )
{
   std::cout << '\n' << "bool VisitTemplateTypeParmDecl( TemplateTypeParmDecl * v )" << '\n' ;

   v->dump() ;

   return true ;
}


bool VisitTemplateTypeParmType( TemplateTypeParmType * v )
{
   std::cout << '\n' << "bool VisitTemplateTypeParmType( TemplateTypeParmType * v )" << '\n' ;

   v->dump() ;

   return true ;
}


bool VisitTranslationUnitDecl( TranslationUnitDecl * v )
{
   std::cout << '\n' << "bool VisitTranslationUnitDecl( TranslationUnitDecl * v )" << '\n' ;

   v->dump() ;

   return true ;
}


bool VisitTypeAliasDecl( TypeAliasDecl * v )
{
   std::cout << '\n' << "bool VisitTypeAliasDecl( TypeAliasDecl * v )" << '\n' ;

   v->dump() ;

   return true ;
}


bool VisitTypeAliasTemplateDecl( TypeAliasTemplateDecl * v )
{
   std::cout << '\n' << "bool VisitTypeAliasTemplateDecl( TypeAliasTemplateDecl * v )" << '\n' ;

   v->dump() ;

   return true ;
}


bool VisitTypeDecl( TypeDecl * v )
{
   std::cout << '\n' << "bool VisitTypeDecl( TypeDecl * v )" << '\n' ;

   v->dump() ;

   return true ;
}


bool VisitTypedefNameDecl( TypedefNameDecl * v )
{
   std::cout << '\n' << "bool VisitTypedefNameDecl( TypedefNameDecl * v )" << '\n' ;

   v->dump() ;

   return true ;
}


bool VisitTypedefType( TypedefType * v )
{
   std::cout << '\n' << "bool VisitTypedefType( TypedefType * v )" << '\n' ;

   v->dump() ;

   return true ;
}


bool VisitTypeOfExprType( TypeOfExprType * v )
{
   std::cout << '\n' << "bool VisitTypeOfExprType( TypeOfExprType * v )" << '\n' ;

   v->dump() ;

   return true ;
}


bool VisitTypeOfType( TypeOfType * v )
{
   std::cout << '\n' << "bool VisitTypeOfType( TypeOfType * v )" << '\n' ;

   v->dump() ;

   return true ;
}


bool VisitTypeTraitExpr( TypeTraitExpr * v )
{
   std::cout << '\n' << "bool VisitTypeTraitExpr( TypeTraitExpr * v )" << '\n' ;

   v->dump() ;

   return true ;
}


bool VisitType( Type * v )
{
   std::cout << '\n' << "bool VisitType( Type * v )" << '\n' ;

   v->dump() ;

   return true ;
}


bool VisitUnaryAddrOf( UnaryOperator * v )
{
   std::cout << '\n' << "bool VisitUnaryAddrOf( UnaryOperator * v )" << '\n' ;

   v->dump() ;

   return true ;
}


bool VisitUnaryDeref( UnaryOperator * v )
{
   std::cout << '\n' << "bool VisitUnaryDeref( UnaryOperator * v )" << '\n' ;

   v->dump() ;

   return true ;
}


bool VisitUnaryExprOrTypeTraitExpr( UnaryExprOrTypeTraitExpr * v )
{
   std::cout << '\n' << "bool VisitUnaryExprOrTypeTraitExpr( UnaryExprOrTypeTraitExpr * v )" << '\n' ;

   v->dump() ;

   return true ;
}


bool VisitUnaryExtension( UnaryOperator * v )
{
   std::cout << '\n' << "bool VisitUnaryExtension( UnaryOperator * v )" << '\n' ;

   v->dump() ;

   return true ;
}


bool VisitUnaryImag( UnaryOperator * v )
{
   std::cout << '\n' << "bool VisitUnaryImag( UnaryOperator * v )" << '\n' ;

   v->dump() ;

   return true ;
}


bool VisitUnaryLNot( UnaryOperator * v )
{
   std::cout << '\n' << "bool VisitUnaryLNot( UnaryOperator * v )" << '\n' ;

   v->dump() ;

   return true ;
}


bool VisitUnaryMinus( UnaryOperator * v )
{
   std::cout << '\n' << "bool VisitUnaryMinus( UnaryOperator * v )" << '\n' ;

   v->dump() ;

   return true ;
}


bool VisitUnaryNot( UnaryOperator * v )
{
   std::cout << '\n' << "bool VisitUnaryNot( UnaryOperator * v )" << '\n' ;

   v->dump() ;

   return true ;
}


bool VisitUnaryOperator( UnaryOperator * v )
{
   std::cout << '\n' << "bool VisitUnaryOperator( UnaryOperator * v )" << '\n' ;

   v->dump() ;

   return true ;
}


bool VisitUnaryPlus( UnaryOperator * v )
{
   std::cout << '\n' << "bool VisitUnaryPlus( UnaryOperator * v )" << '\n' ;

   v->dump() ;

   return true ;
}


bool VisitUnaryPostDec( UnaryOperator * v )
{
   std::cout << '\n' << "bool VisitUnaryPostDec( UnaryOperator * v )" << '\n' ;

   v->dump() ;

   return true ;
}


bool VisitUnaryPostInc( UnaryOperator * v )
{
   std::cout << '\n' << "bool VisitUnaryPostInc( UnaryOperator * v )" << '\n' ;

   v->dump() ;

   return true ;
}


bool VisitUnaryPreDec( UnaryOperator * v )
{
   std::cout << '\n' << "bool VisitUnaryPreDec( UnaryOperator * v )" << '\n' ;

   v->dump() ;

   return true ;
}


bool VisitUnaryPreInc( UnaryOperator * v )
{
   std::cout << '\n' << "bool VisitUnaryPreInc( UnaryOperator * v )" << '\n' ;

   v->dump() ;

   return true ;
}


bool VisitUnaryReal( UnaryOperator * v )
{
   std::cout << '\n' << "bool VisitUnaryReal( UnaryOperator * v )" << '\n' ;

   v->dump() ;

   return true ;
}


bool VisitUnaryTransformType( UnaryTransformType * v )
{
   std::cout << '\n' << "bool VisitUnaryTransformType( UnaryTransformType * v )" << '\n' ;

   v->dump() ;

   return true ;
}

#if 0
bool VisitUnaryTypeTraitExpr( UnaryTypeTraitExpr * v )
{
   std::cout << '\n' << "bool VisitUnaryTypeTraitExpr( UnaryTypeTraitExpr * v )" << '\n' ;

   v->dump() ;

   return true ;
}
#endif

bool VisitUnresolvedLookupExpr( UnresolvedLookupExpr * v )
{
   std::cout << '\n' << "bool VisitUnresolvedLookupExpr( UnresolvedLookupExpr * v )" << '\n' ;

   v->dump() ;

   return true ;
}


bool VisitUnresolvedMemberExpr( UnresolvedMemberExpr * v )
{
   std::cout << '\n' << "bool VisitUnresolvedMemberExpr( UnresolvedMemberExpr * v )" << '\n' ;

   v->dump() ;

   return true ;
}


bool VisitUnresolvedUsingTypenameDecl( UnresolvedUsingTypenameDecl * v )
{
   std::cout << '\n' << "bool VisitUnresolvedUsingTypenameDecl( UnresolvedUsingTypenameDecl * v )" << '\n' ;

   v->dump() ;

   return true ;
}


bool VisitUnresolvedUsingType( UnresolvedUsingType * v )
{
   std::cout << '\n' << "bool VisitUnresolvedUsingType( UnresolvedUsingType * v )" << '\n' ;

   v->dump() ;

   return true ;
}


bool VisitUnresolvedUsingValueDecl( UnresolvedUsingValueDecl * v )
{
   std::cout << '\n' << "bool VisitUnresolvedUsingValueDecl( UnresolvedUsingValueDecl * v )" << '\n' ;

   v->dump() ;

   return true ;
}


bool VisitUserDefinedLiteral( UserDefinedLiteral * v )
{
   std::cout << '\n' << "bool VisitUserDefinedLiteral( UserDefinedLiteral * v )" << '\n' ;

   v->dump() ;

   return true ;
}


bool VisitUsingDecl( UsingDecl * v )
{
   std::cout << '\n' << "bool VisitUsingDecl( UsingDecl * v )" << '\n' ;

   v->dump() ;

   return true ;
}


bool VisitUsingDirectiveDecl( UsingDirectiveDecl * v )
{
   std::cout << '\n' << "bool VisitUsingDirectiveDecl( UsingDirectiveDecl * v )" << '\n' ;

   v->dump() ;

   return true ;
}


bool VisitUsingShadowDecl( UsingShadowDecl * v )
{
   std::cout << '\n' << "bool VisitUsingShadowDecl( UsingShadowDecl * v )" << '\n' ;

   v->dump() ;

   return true ;
}


bool VisitVAArgExpr( VAArgExpr * v )
{
   std::cout << '\n' << "bool VisitVAArgExpr( VAArgExpr * v )" << '\n' ;

   v->dump() ;

   return true ;
}


bool VisitValueDecl( ValueDecl * v )
{
   std::cout << '\n' << "bool VisitValueDecl( ValueDecl * v )" << '\n' ;

   v->dump() ;

   return true ;
}


bool VisitVarDecl( VarDecl * v )
{
   std::cout << '\n' << "bool VisitVarDecl( VarDecl * v )" << '\n' ;

   v->dump() ;

   return true ;
}


bool VisitVariableArrayType( VariableArrayType * v )
{
   std::cout << '\n' << "bool VisitVariableArrayType( VariableArrayType * v )" << '\n' ;

   v->dump() ;

   return true ;
}


bool VisitVectorType( VectorType * v )
{
   std::cout << '\n' << "bool VisitVectorType( VectorType * v )" << '\n' ;

   v->dump() ;

   return true ;
}


bool VisitWhileStmt( WhileStmt * v )
{
   std::cout << '\n' << "bool VisitWhileStmt( WhileStmt * v )" << '\n' ;

   v->dump() ;

   return true ;
}


