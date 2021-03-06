begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the utils of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:GPL-EXCEPT$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3 as published by the Free Software ** Foundation with exceptions as appearing in the file LICENSE.GPL3-EXCEPT ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|GENERATOR_H
end_ifndef
begin_define
DECL|macro|GENERATOR_H
define|#
directive|define
name|GENERATOR_H
end_define
begin_include
include|#
directive|include
file|<QTextStream>
end_include
begin_include
include|#
directive|include
file|<QStringList>
end_include
begin_include
include|#
directive|include
file|"nfa.h"
end_include
begin_decl_stmt
name|class
name|LineStream
block|{
name|private
label|:
struct|struct
name|SharedStream
block|{
name|int
name|ref
decl_stmt|;
name|QTextStream
modifier|*
name|stream
decl_stmt|;
block|}
struct|;
name|public
label|:
name|LineStream
argument_list|(
argument|QTextStream *textStream
argument_list|)
block|{
name|shared
operator|=
name|new
name|SharedStream
expr_stmt|;
name|shared
operator|->
name|ref
operator|=
literal|1
expr_stmt|;
name|shared
operator|->
name|stream
operator|=
name|textStream
expr_stmt|;
block|}
name|LineStream
argument_list|(
argument|const LineStream&other
argument_list|)
block|{
name|shared
operator|=
name|other
operator|.
name|shared
expr_stmt|;
name|shared
operator|->
name|ref
operator|++
expr_stmt|;
block|}
name|LineStream
modifier|&
name|operator
init|=
operator|(
specifier|const
name|LineStream
operator|&
name|other
operator|)
block|{
if|if
condition|(
name|this
operator|==
operator|&
name|other
condition|)
return|return
operator|*
name|this
return|;
name|LineStream
name|copy
argument_list|(
name|other
argument_list|)
decl_stmt|;
comment|// keep refcount up
name|qSwap
argument_list|(
operator|*
name|shared
argument_list|,
operator|*
name|other
operator|.
name|shared
argument_list|)
expr_stmt|;
return|return
operator|*
name|this
return|;
block|}
end_decl_stmt
begin_expr_stmt
operator|~
name|LineStream
argument_list|()
block|{
if|if
condition|(
operator|!
operator|--
name|shared
operator|->
name|ref
condition|)
block|{
operator|(
operator|*
name|shared
operator|->
name|stream
operator|)
operator|<<
name|endl
expr_stmt|;
name|delete
name|shared
decl_stmt|;
block|}
end_expr_stmt
begin_expr_stmt
unit|}      template
operator|<
name|typename
name|T
operator|>
name|LineStream
operator|&
name|operator
operator|<<
operator|(
specifier|const
name|T
operator|&
name|value
operator|)
block|{
operator|(
operator|*
name|shared
operator|->
name|stream
operator|)
operator|<<
name|value
block|;
return|return
operator|*
name|this
return|;
block|}
end_expr_stmt
begin_decl_stmt
name|SharedStream
modifier|*
name|shared
decl_stmt|;
end_decl_stmt
begin_decl_stmt
unit|};
name|class
name|CodeBlock
block|{
name|public
label|:
specifier|inline
name|CodeBlock
argument_list|()
block|{
name|stream
operator|.
name|setString
argument_list|(
operator|&
name|output
argument_list|,
name|QIODevice
operator|::
name|WriteOnly
argument_list|)
block|; }
specifier|inline
name|void
name|indent
argument_list|()
block|{
name|indentStr
operator|+=
name|QLatin1String
argument_list|(
literal|"    "
argument_list|)
block|; }
specifier|inline
name|void
name|outdent
argument_list|()
block|{
name|indentStr
operator|.
name|remove
argument_list|(
literal|0
argument_list|,
literal|4
argument_list|)
block|; }
name|template
operator|<
name|typename
name|T
operator|>
name|LineStream
name|operator
operator|<<
operator|(
specifier|const
name|T
operator|&
name|value
operator|)
block|{
name|stream
operator|<<
name|indentStr
block|;
name|stream
operator|<<
name|value
block|;
return|return
name|LineStream
argument_list|(
operator|&
name|stream
argument_list|)
return|;
block|}
specifier|inline
name|void
name|addNewLine
parameter_list|()
block|{
name|stream
operator|<<
name|endl
expr_stmt|;
block|}
specifier|inline
name|QString
name|toString
argument_list|()
specifier|const
block|{
name|stream
operator|.
name|flush
argument_list|()
block|;
return|return
name|output
return|;
block|}
name|private
label|:
name|QString
name|output
decl_stmt|;
name|mutable
name|QTextStream
name|stream
decl_stmt|;
name|QString
name|indentStr
decl_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_decl_stmt
name|class
name|Function
block|{
name|public
label|:
specifier|inline
name|Function
argument_list|(
specifier|const
name|QString
operator|&
name|returnType
argument_list|,
specifier|const
name|QString
operator|&
name|name
argument_list|)
operator|:
name|rtype
argument_list|(
name|returnType
argument_list|)
operator|,
name|fname
argument_list|(
name|name
argument_list|)
operator|,
name|iline
argument_list|(
name|false
argument_list|)
operator|,
name|cnst
argument_list|(
argument|false
argument_list|)
block|{}
specifier|inline
name|Function
argument_list|()
operator|:
name|iline
argument_list|(
name|false
argument_list|)
operator|,
name|cnst
argument_list|(
argument|false
argument_list|)
block|{}
specifier|inline
name|void
name|setName
argument_list|(
argument|const QString&name
argument_list|)
block|{
name|fname
operator|=
name|name
block|; }
specifier|inline
name|QString
name|name
argument_list|()
specifier|const
block|{
return|return
name|fname
return|;
block|}
specifier|inline
name|void
name|setInline
parameter_list|(
name|bool
name|i
parameter_list|)
block|{
name|iline
operator|=
name|i
expr_stmt|;
block|}
specifier|inline
name|bool
name|isInline
argument_list|()
specifier|const
block|{
return|return
name|iline
return|;
block|}
specifier|inline
name|void
name|setReturnType
parameter_list|(
specifier|const
name|QString
modifier|&
name|type
parameter_list|)
block|{
name|rtype
operator|=
name|type
expr_stmt|;
block|}
specifier|inline
name|QString
name|returnType
argument_list|()
specifier|const
block|{
return|return
name|rtype
return|;
block|}
specifier|inline
name|void
name|addBody
parameter_list|(
specifier|const
name|QString
modifier|&
name|_body
parameter_list|)
block|{
name|body
operator|+=
name|_body
expr_stmt|;
block|}
specifier|inline
name|void
name|addBody
parameter_list|(
specifier|const
name|CodeBlock
modifier|&
name|block
parameter_list|)
block|{
name|body
operator|+=
name|block
operator|.
name|toString
argument_list|()
expr_stmt|;
block|}
specifier|inline
name|bool
name|hasBody
argument_list|()
specifier|const
block|{
return|return
operator|!
name|body
operator|.
name|isEmpty
argument_list|()
return|;
block|}
specifier|inline
name|void
name|setConst
parameter_list|(
name|bool
name|konst
parameter_list|)
block|{
name|cnst
operator|=
name|konst
expr_stmt|;
block|}
specifier|inline
name|bool
name|isConst
argument_list|()
specifier|const
block|{
return|return
name|cnst
return|;
block|}
name|void
name|printDeclaration
argument_list|(
name|CodeBlock
operator|&
name|block
argument_list|,
specifier|const
name|QString
operator|&
name|funcNamePrefix
operator|=
name|QString
argument_list|()
argument_list|)
decl|const
decl_stmt|;
name|QString
name|definition
argument_list|()
specifier|const
expr_stmt|;
name|private
label|:
name|QString
name|signature
argument_list|(
specifier|const
name|QString
operator|&
name|funcNamePrefix
operator|=
name|QString
argument_list|()
argument_list|)
decl|const
decl_stmt|;
name|QString
name|rtype
decl_stmt|;
name|QString
name|fname
decl_stmt|;
name|QString
name|body
decl_stmt|;
name|bool
name|iline
decl_stmt|;
name|bool
name|cnst
decl_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_decl_stmt
name|class
name|Class
block|{
name|public
label|:
enum|enum
name|Access
block|{
name|PublicMember
block|,
name|ProtectedMember
block|,
name|PrivateMember
block|}
enum|;
specifier|inline
name|Class
argument_list|(
specifier|const
name|QString
operator|&
name|name
argument_list|)
operator|:
name|cname
argument_list|(
argument|name
argument_list|)
block|{}
specifier|inline
name|void
name|setName
argument_list|(
argument|const QString&name
argument_list|)
block|{
name|cname
operator|=
name|name
block|; }
specifier|inline
name|QString
name|name
argument_list|()
specifier|const
block|{
return|return
name|cname
return|;
block|}
specifier|inline
name|void
name|addMember
parameter_list|(
name|Access
name|access
parameter_list|,
specifier|const
name|QString
modifier|&
name|name
parameter_list|)
block|{
name|sections
index|[
name|access
index|]
operator|.
name|variables
operator|.
name|append
argument_list|(
name|name
argument_list|)
expr_stmt|;
block|}
specifier|inline
name|void
name|addMember
parameter_list|(
name|Access
name|access
parameter_list|,
specifier|const
name|Function
modifier|&
name|func
parameter_list|)
block|{
name|sections
index|[
name|access
index|]
operator|.
name|functions
operator|.
name|append
argument_list|(
name|func
argument_list|)
expr_stmt|;
block|}
name|void
name|addConstructor
parameter_list|(
name|Access
name|access
parameter_list|,
specifier|const
name|QString
modifier|&
name|body
parameter_list|,
specifier|const
name|QString
modifier|&
name|args
init|=
name|QString
argument_list|()
parameter_list|)
function_decl|;
specifier|inline
name|void
name|addConstructor
parameter_list|(
name|Access
name|access
parameter_list|,
specifier|const
name|CodeBlock
modifier|&
name|body
parameter_list|,
specifier|const
name|QString
modifier|&
name|args
init|=
name|QString
argument_list|()
parameter_list|)
block|{
name|addConstructor
argument_list|(
name|access
argument_list|,
name|body
operator|.
name|toString
argument_list|()
argument_list|,
name|args
argument_list|)
expr_stmt|;
block|}
name|QString
name|declaration
argument_list|()
specifier|const
expr_stmt|;
name|QString
name|definition
argument_list|()
specifier|const
expr_stmt|;
name|private
label|:
name|QString
name|cname
decl_stmt|;
struct|struct
name|Section
block|{
name|QVector
operator|<
name|Function
operator|>
name|functions
expr_stmt|;
name|QStringList
name|variables
decl_stmt|;
name|QVector
operator|<
name|Function
operator|>
name|constructors
expr_stmt|;
specifier|inline
name|bool
name|isEmpty
argument_list|()
specifier|const
block|{
return|return
name|functions
operator|.
name|isEmpty
argument_list|()
operator|&&
name|variables
operator|.
name|isEmpty
argument_list|()
operator|&&
name|constructors
operator|.
name|isEmpty
argument_list|()
return|;
block|}
name|void
name|printDeclaration
argument_list|(
specifier|const
name|Class
operator|*
name|klass
argument_list|,
name|CodeBlock
operator|&
name|block
argument_list|)
decl|const
decl_stmt|;
name|QString
name|definition
argument_list|(
specifier|const
name|Class
operator|*
name|klass
argument_list|)
decl|const
decl_stmt|;
block|}
struct|;
name|Section
name|sections
index|[
literal|3
index|]
decl_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_decl_stmt
name|class
name|Generator
block|{
name|public
label|:
name|Generator
argument_list|(
specifier|const
name|DFA
operator|&
name|dfa
argument_list|,
specifier|const
name|Config
operator|&
name|config
argument_list|)
expr_stmt|;
name|QString
name|generate
parameter_list|()
function_decl|;
name|private
label|:
name|void
name|generateTransitions
parameter_list|(
name|CodeBlock
modifier|&
name|body
parameter_list|,
specifier|const
name|TransitionMap
modifier|&
name|transitions
parameter_list|)
function_decl|;
name|bool
name|isSingleReferencedFinalState
argument_list|(
name|int
name|i
argument_list|)
decl|const
decl_stmt|;
name|DFA
name|dfa
decl_stmt|;
name|Config
name|cfg
decl_stmt|;
name|InputType
name|minInput
decl_stmt|;
name|InputType
name|maxInput
decl_stmt|;
name|QHash
operator|<
name|int
operator|,
name|int
operator|>
name|backReferenceMap
expr_stmt|;
name|QString
name|headerFileName
decl_stmt|;
name|public
label|:
struct|struct
name|TransitionSequence
block|{
specifier|inline
name|TransitionSequence
argument_list|()
operator|:
name|first
argument_list|(
operator|-
literal|1
argument_list|)
operator|,
name|last
argument_list|(
operator|-
literal|1
argument_list|)
operator|,
name|transition
argument_list|(
argument|-
literal|1
argument_list|)
block|{}
name|InputType
name|first
expr_stmt|;
name|InputType
name|last
decl_stmt|;
name|int
name|transition
decl_stmt|;
name|QString
name|testFunction
decl_stmt|;
block|}
struct|;
name|private
label|:
name|QVector
operator|<
name|TransitionSequence
operator|>
name|charFunctionRanges
expr_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_endif
endif|#
directive|endif
end_endif
end_unit
