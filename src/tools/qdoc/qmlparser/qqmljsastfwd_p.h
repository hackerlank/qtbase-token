begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtQml module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QQMLJSAST_FWD_P_H
end_ifndef
begin_define
DECL|macro|QQMLJSAST_FWD_P_H
define|#
directive|define
name|QQMLJSAST_FWD_P_H
end_define
begin_include
include|#
directive|include
file|"qqmljsglobal_p.h"
end_include
begin_include
include|#
directive|include
file|<QtCore/qglobal.h>
end_include
begin_comment
comment|//
end_comment
begin_comment
comment|//  W A R N I N G
end_comment
begin_comment
comment|//  -------------
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|// This file is not part of the Qt API.  It exists purely as an
end_comment
begin_comment
comment|// implementation detail.  This header file may change from version to
end_comment
begin_comment
comment|// version without notice, or even be removed.
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|// We mean it.
end_comment
begin_comment
comment|//
end_comment
begin_decl_stmt
name|QT_QML_BEGIN_NAMESPACE
name|namespace
name|QQmlJS
block|{
name|namespace
name|AST
block|{
name|class
name|SourceLocation
block|{
name|public
label|:
name|SourceLocation
argument_list|(
argument|quint32 offset =
literal|0
argument_list|,
argument|quint32 length =
literal|0
argument_list|,
argument|quint32 line =
literal|0
argument_list|,
argument|quint32 column =
literal|0
argument_list|)
block|:
name|offset
argument_list|(
name|offset
argument_list|)
operator|,
name|length
argument_list|(
name|length
argument_list|)
operator|,
name|startLine
argument_list|(
name|line
argument_list|)
operator|,
name|startColumn
argument_list|(
argument|column
argument_list|)
block|{ }
name|bool
name|isValid
argument_list|()
specifier|const
block|{
return|return
name|length
operator|!=
literal|0
return|;
block|}
name|quint32
name|begin
argument_list|()
specifier|const
block|{
return|return
name|offset
return|;
block|}
name|quint32
name|end
argument_list|()
specifier|const
block|{
return|return
name|offset
operator|+
name|length
return|;
block|}
comment|// attributes
comment|// ### encode
name|quint32
name|offset
decl_stmt|;
name|quint32
name|length
decl_stmt|;
name|quint32
name|startLine
decl_stmt|;
name|quint32
name|startColumn
decl_stmt|;
block|}
empty_stmt|;
name|class
name|Visitor
decl_stmt|;
name|class
name|Node
decl_stmt|;
name|class
name|ExpressionNode
decl_stmt|;
name|class
name|Statement
decl_stmt|;
name|class
name|ThisExpression
decl_stmt|;
name|class
name|IdentifierExpression
decl_stmt|;
name|class
name|NullExpression
decl_stmt|;
name|class
name|TrueLiteral
decl_stmt|;
name|class
name|FalseLiteral
decl_stmt|;
name|class
name|NumericLiteral
decl_stmt|;
name|class
name|StringLiteral
decl_stmt|;
name|class
name|RegExpLiteral
decl_stmt|;
name|class
name|ArrayLiteral
decl_stmt|;
name|class
name|ObjectLiteral
decl_stmt|;
name|class
name|ElementList
decl_stmt|;
name|class
name|Elision
decl_stmt|;
name|class
name|PropertyAssignmentList
decl_stmt|;
name|class
name|PropertyGetterSetter
decl_stmt|;
name|class
name|PropertyNameAndValue
decl_stmt|;
name|class
name|PropertyName
decl_stmt|;
name|class
name|IdentifierPropertyName
decl_stmt|;
name|class
name|StringLiteralPropertyName
decl_stmt|;
name|class
name|NumericLiteralPropertyName
decl_stmt|;
name|class
name|ArrayMemberExpression
decl_stmt|;
name|class
name|FieldMemberExpression
decl_stmt|;
name|class
name|NewMemberExpression
decl_stmt|;
name|class
name|NewExpression
decl_stmt|;
name|class
name|CallExpression
decl_stmt|;
name|class
name|ArgumentList
decl_stmt|;
name|class
name|PostIncrementExpression
decl_stmt|;
name|class
name|PostDecrementExpression
decl_stmt|;
name|class
name|DeleteExpression
decl_stmt|;
name|class
name|VoidExpression
decl_stmt|;
name|class
name|TypeOfExpression
decl_stmt|;
name|class
name|PreIncrementExpression
decl_stmt|;
name|class
name|PreDecrementExpression
decl_stmt|;
name|class
name|UnaryPlusExpression
decl_stmt|;
name|class
name|UnaryMinusExpression
decl_stmt|;
name|class
name|TildeExpression
decl_stmt|;
name|class
name|NotExpression
decl_stmt|;
name|class
name|BinaryExpression
decl_stmt|;
name|class
name|ConditionalExpression
decl_stmt|;
name|class
name|Expression
decl_stmt|;
comment|// ### rename
name|class
name|Block
decl_stmt|;
name|class
name|StatementList
decl_stmt|;
name|class
name|VariableStatement
decl_stmt|;
name|class
name|VariableDeclarationList
decl_stmt|;
name|class
name|VariableDeclaration
decl_stmt|;
name|class
name|EmptyStatement
decl_stmt|;
name|class
name|ExpressionStatement
decl_stmt|;
name|class
name|IfStatement
decl_stmt|;
name|class
name|DoWhileStatement
decl_stmt|;
name|class
name|WhileStatement
decl_stmt|;
name|class
name|ForStatement
decl_stmt|;
name|class
name|LocalForStatement
decl_stmt|;
name|class
name|ForEachStatement
decl_stmt|;
name|class
name|LocalForEachStatement
decl_stmt|;
name|class
name|ContinueStatement
decl_stmt|;
name|class
name|BreakStatement
decl_stmt|;
name|class
name|ReturnStatement
decl_stmt|;
name|class
name|WithStatement
decl_stmt|;
name|class
name|SwitchStatement
decl_stmt|;
name|class
name|CaseBlock
decl_stmt|;
name|class
name|CaseClauses
decl_stmt|;
name|class
name|CaseClause
decl_stmt|;
name|class
name|DefaultClause
decl_stmt|;
name|class
name|LabelledStatement
decl_stmt|;
name|class
name|ThrowStatement
decl_stmt|;
name|class
name|TryStatement
decl_stmt|;
name|class
name|Catch
decl_stmt|;
name|class
name|Finally
decl_stmt|;
name|class
name|FunctionDeclaration
decl_stmt|;
name|class
name|FunctionExpression
decl_stmt|;
name|class
name|FormalParameterList
decl_stmt|;
name|class
name|FunctionBody
decl_stmt|;
name|class
name|Program
decl_stmt|;
name|class
name|SourceElements
decl_stmt|;
name|class
name|SourceElement
decl_stmt|;
name|class
name|FunctionSourceElement
decl_stmt|;
name|class
name|StatementSourceElement
decl_stmt|;
name|class
name|DebuggerStatement
decl_stmt|;
name|class
name|NestedExpression
decl_stmt|;
comment|// ui elements
name|class
name|UiProgram
decl_stmt|;
name|class
name|UiPragma
decl_stmt|;
name|class
name|UiImport
decl_stmt|;
name|class
name|UiPublicMember
decl_stmt|;
name|class
name|UiParameterList
decl_stmt|;
name|class
name|UiObjectDefinition
decl_stmt|;
name|class
name|UiObjectInitializer
decl_stmt|;
name|class
name|UiObjectBinding
decl_stmt|;
name|class
name|UiScriptBinding
decl_stmt|;
name|class
name|UiSourceElement
decl_stmt|;
name|class
name|UiArrayBinding
decl_stmt|;
name|class
name|UiObjectMember
decl_stmt|;
name|class
name|UiObjectMemberList
decl_stmt|;
name|class
name|UiArrayMemberList
decl_stmt|;
name|class
name|UiQualifiedId
decl_stmt|;
name|class
name|UiQualifiedPragmaId
decl_stmt|;
name|class
name|UiHeaderItemList
decl_stmt|;
block|}
block|}
end_decl_stmt
begin_comment
comment|// namespace AST
end_comment
begin_macro
name|QT_QML_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
end_unit
