begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtQml module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
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
begin_comment
comment|//
end_comment
begin_comment
comment|// This file is automatically generated from qmljs.g.
end_comment
begin_comment
comment|// Changes will be lost.
end_comment
begin_comment
comment|//
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QQMLJSPARSER_P_H
end_ifndef
begin_define
DECL|macro|QQMLJSPARSER_P_H
define|#
directive|define
name|QQMLJSPARSER_P_H
end_define
begin_include
include|#
directive|include
file|"qqmljsglobal_p.h"
end_include
begin_include
include|#
directive|include
file|"qqmljsgrammar_p.h"
end_include
begin_include
include|#
directive|include
file|"qqmljsast_p.h"
end_include
begin_include
include|#
directive|include
file|"qqmljsengine_p.h"
end_include
begin_include
include|#
directive|include
file|<qlist.h>
end_include
begin_include
include|#
directive|include
file|<qstring.h>
end_include
begin_decl_stmt
name|QT_QML_BEGIN_NAMESPACE
name|namespace
name|QQmlJS
block|{
name|class
name|Engine
decl_stmt|;
name|class
name|QML_PARSER_EXPORT
name|Parser
range|:
name|protected
name|QQmlJSGrammar
block|{
name|public
operator|:
expr|union
name|Value
block|{
name|int
name|ival
block|;
name|double
name|dval
block|;
name|AST
operator|::
name|ArgumentList
operator|*
name|ArgumentList
block|;
name|AST
operator|::
name|CaseBlock
operator|*
name|CaseBlock
block|;
name|AST
operator|::
name|CaseClause
operator|*
name|CaseClause
block|;
name|AST
operator|::
name|CaseClauses
operator|*
name|CaseClauses
block|;
name|AST
operator|::
name|Catch
operator|*
name|Catch
block|;
name|AST
operator|::
name|DefaultClause
operator|*
name|DefaultClause
block|;
name|AST
operator|::
name|ElementList
operator|*
name|ElementList
block|;
name|AST
operator|::
name|Elision
operator|*
name|Elision
block|;
name|AST
operator|::
name|ExpressionNode
operator|*
name|Expression
block|;
name|AST
operator|::
name|Finally
operator|*
name|Finally
block|;
name|AST
operator|::
name|FormalParameterList
operator|*
name|FormalParameterList
block|;
name|AST
operator|::
name|FunctionBody
operator|*
name|FunctionBody
block|;
name|AST
operator|::
name|FunctionDeclaration
operator|*
name|FunctionDeclaration
block|;
name|AST
operator|::
name|Node
operator|*
name|Node
block|;
name|AST
operator|::
name|PropertyName
operator|*
name|PropertyName
block|;
name|AST
operator|::
name|PropertyNameAndValueList
operator|*
name|PropertyNameAndValueList
block|;
name|AST
operator|::
name|SourceElement
operator|*
name|SourceElement
block|;
name|AST
operator|::
name|SourceElements
operator|*
name|SourceElements
block|;
name|AST
operator|::
name|Statement
operator|*
name|Statement
block|;
name|AST
operator|::
name|StatementList
operator|*
name|StatementList
block|;
name|AST
operator|::
name|Block
operator|*
name|Block
block|;
name|AST
operator|::
name|VariableDeclaration
operator|*
name|VariableDeclaration
block|;
name|AST
operator|::
name|VariableDeclarationList
operator|*
name|VariableDeclarationList
block|;
name|AST
operator|::
name|UiProgram
operator|*
name|UiProgram
block|;
name|AST
operator|::
name|UiImportList
operator|*
name|UiImportList
block|;
name|AST
operator|::
name|UiImport
operator|*
name|UiImport
block|;
name|AST
operator|::
name|UiParameterList
operator|*
name|UiParameterList
block|;
name|AST
operator|::
name|UiPublicMember
operator|*
name|UiPublicMember
block|;
name|AST
operator|::
name|UiObjectDefinition
operator|*
name|UiObjectDefinition
block|;
name|AST
operator|::
name|UiObjectInitializer
operator|*
name|UiObjectInitializer
block|;
name|AST
operator|::
name|UiObjectBinding
operator|*
name|UiObjectBinding
block|;
name|AST
operator|::
name|UiScriptBinding
operator|*
name|UiScriptBinding
block|;
name|AST
operator|::
name|UiArrayBinding
operator|*
name|UiArrayBinding
block|;
name|AST
operator|::
name|UiObjectMember
operator|*
name|UiObjectMember
block|;
name|AST
operator|::
name|UiObjectMemberList
operator|*
name|UiObjectMemberList
block|;
name|AST
operator|::
name|UiArrayMemberList
operator|*
name|UiArrayMemberList
block|;
name|AST
operator|::
name|UiQualifiedId
operator|*
name|UiQualifiedId
block|;     }
block|;
name|public
operator|:
name|Parser
argument_list|(
name|Engine
operator|*
name|engine
argument_list|)
block|;
operator|~
name|Parser
argument_list|()
block|;
comment|// parse a UI program
name|bool
name|parse
argument_list|()
block|{
return|return
name|parse
argument_list|(
name|T_FEED_UI_PROGRAM
argument_list|)
return|;
block|}
name|bool
name|parseStatement
argument_list|()
block|{
return|return
name|parse
argument_list|(
name|T_FEED_JS_STATEMENT
argument_list|)
return|;
block|}
name|bool
name|parseExpression
argument_list|()
block|{
return|return
name|parse
argument_list|(
name|T_FEED_JS_EXPRESSION
argument_list|)
return|;
block|}
name|bool
name|parseSourceElement
argument_list|()
block|{
return|return
name|parse
argument_list|(
name|T_FEED_JS_SOURCE_ELEMENT
argument_list|)
return|;
block|}
name|bool
name|parseUiObjectMember
argument_list|()
block|{
return|return
name|parse
argument_list|(
name|T_FEED_UI_OBJECT_MEMBER
argument_list|)
return|;
block|}
name|bool
name|parseProgram
argument_list|()
block|{
return|return
name|parse
argument_list|(
name|T_FEED_JS_PROGRAM
argument_list|)
return|;
block|}
name|AST
operator|::
name|UiProgram
operator|*
name|ast
argument_list|()
specifier|const
block|{
return|return
name|AST
operator|::
name|cast
operator|<
name|AST
operator|::
name|UiProgram
operator|*
operator|>
operator|(
name|program
operator|)
return|;
block|}
name|AST
operator|::
name|Statement
operator|*
name|statement
argument_list|()
specifier|const
block|{
if|if
condition|(
operator|!
name|program
condition|)
return|return
literal|0
return|;
return|return
name|program
operator|->
name|statementCast
argument_list|()
return|;
block|}
name|AST
operator|::
name|ExpressionNode
operator|*
name|expression
argument_list|()
specifier|const
block|{
if|if
condition|(
operator|!
name|program
condition|)
return|return
literal|0
return|;
return|return
name|program
operator|->
name|expressionCast
argument_list|()
return|;
block|}
end_decl_stmt
begin_expr_stmt
name|AST
operator|::
name|UiObjectMember
operator|*
name|uiObjectMember
argument_list|()
specifier|const
block|{
if|if
condition|(
operator|!
name|program
condition|)
return|return
literal|0
return|;
end_expr_stmt
begin_return
return|return
name|program
operator|->
name|uiObjectMemberCast
argument_list|()
return|;
end_return
begin_expr_stmt
unit|}      AST
operator|::
name|Node
operator|*
name|rootNode
argument_list|()
specifier|const
block|{
return|return
name|program
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|QList
operator|<
name|DiagnosticMessage
operator|>
name|diagnosticMessages
argument_list|()
specifier|const
block|{
return|return
name|diagnostic_messages
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
name|DiagnosticMessage
name|diagnosticMessage
argument_list|()
specifier|const
block|{
name|foreach
argument_list|(
argument|const DiagnosticMessage&d
argument_list|,
argument|diagnostic_messages
argument_list|)
block|{
if|if
condition|(
operator|!
name|d
operator|.
name|kind
operator|==
name|DiagnosticMessage
operator|::
name|Warning
condition|)
return|return
name|d
return|;
block|}
end_expr_stmt
begin_return
return|return
name|DiagnosticMessage
argument_list|()
return|;
end_return
begin_expr_stmt
unit|}      inline
name|QString
name|errorMessage
argument_list|()
specifier|const
block|{
return|return
name|diagnosticMessage
argument_list|()
operator|.
name|message
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
name|int
name|errorLineNumber
argument_list|()
specifier|const
block|{
return|return
name|diagnosticMessage
argument_list|()
operator|.
name|loc
operator|.
name|startLine
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
name|int
name|errorColumnNumber
argument_list|()
specifier|const
block|{
return|return
name|diagnosticMessage
argument_list|()
operator|.
name|loc
operator|.
name|startColumn
return|;
block|}
end_expr_stmt
begin_label
name|protected
label|:
end_label
begin_function_decl
name|bool
name|parse
parameter_list|(
name|int
name|startToken
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|reallocateStack
parameter_list|()
function_decl|;
end_function_decl
begin_function
specifier|inline
name|Value
modifier|&
name|sym
parameter_list|(
name|int
name|index
parameter_list|)
block|{
return|return
name|sym_stack
index|[
name|tos
operator|+
name|index
operator|-
literal|1
index|]
return|;
block|}
end_function
begin_function
specifier|inline
name|QStringRef
modifier|&
name|stringRef
parameter_list|(
name|int
name|index
parameter_list|)
block|{
return|return
name|string_stack
index|[
name|tos
operator|+
name|index
operator|-
literal|1
index|]
return|;
block|}
end_function
begin_expr_stmt
specifier|inline
name|AST
operator|::
name|SourceLocation
operator|&
name|loc
argument_list|(
argument|int index
argument_list|)
block|{
return|return
name|location_stack
index|[
name|tos
operator|+
name|index
operator|-
literal|1
index|]
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|AST
operator|::
name|UiQualifiedId
operator|*
name|reparseAsQualifiedId
argument_list|(
name|AST
operator|::
name|ExpressionNode
operator|*
name|expr
argument_list|)
expr_stmt|;
end_expr_stmt
begin_label
name|protected
label|:
end_label
begin_decl_stmt
name|Engine
modifier|*
name|driver
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|MemoryPool
modifier|*
name|pool
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|int
name|tos
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|int
name|stack_size
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|Value
modifier|*
name|sym_stack
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|int
modifier|*
name|state_stack
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|AST
operator|::
name|SourceLocation
operator|*
name|location_stack
expr_stmt|;
end_expr_stmt
begin_decl_stmt
name|QStringRef
modifier|*
name|string_stack
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|AST
operator|::
name|Node
operator|*
name|program
expr_stmt|;
end_expr_stmt
begin_comment
comment|// error recovery
end_comment
begin_enum
enum|enum
block|{
name|TOKEN_BUFFER_SIZE
init|=
literal|3
block|}
enum|;
end_enum
begin_struct
struct|struct
name|SavedToken
block|{
name|int
name|token
decl_stmt|;
name|double
name|dval
decl_stmt|;
name|AST
operator|::
name|SourceLocation
name|loc
expr_stmt|;
name|QStringRef
name|spell
decl_stmt|;
block|}
struct|;
end_struct
begin_decl_stmt
name|double
name|yylval
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QStringRef
name|yytokenspell
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|AST
operator|::
name|SourceLocation
name|yylloc
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|AST
operator|::
name|SourceLocation
name|yyprevlloc
expr_stmt|;
end_expr_stmt
begin_decl_stmt
name|SavedToken
name|token_buffer
index|[
name|TOKEN_BUFFER_SIZE
index|]
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|SavedToken
modifier|*
name|first_token
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|SavedToken
modifier|*
name|last_token
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|QList
operator|<
name|DiagnosticMessage
operator|>
name|diagnostic_messages
expr_stmt|;
end_expr_stmt
begin_comment
unit|};  }
comment|// end of namespace QQmlJS
end_comment
begin_define
DECL|macro|J_SCRIPT_REGEXPLITERAL_RULE1
define|#
directive|define
name|J_SCRIPT_REGEXPLITERAL_RULE1
value|79
end_define
begin_define
DECL|macro|J_SCRIPT_REGEXPLITERAL_RULE2
define|#
directive|define
name|J_SCRIPT_REGEXPLITERAL_RULE2
value|80
end_define
begin_endif
unit|QT_QML_END_NAMESPACE
endif|#
directive|endif
end_endif
begin_comment
comment|// QQMLJSPARSER_P_H
end_comment
end_unit
