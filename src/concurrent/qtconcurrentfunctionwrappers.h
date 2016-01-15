begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QTCONCURRENT_FUNCTIONWRAPPERS_H
end_ifndef
begin_define
DECL|macro|QTCONCURRENT_FUNCTIONWRAPPERS_H
define|#
directive|define
name|QTCONCURRENT_FUNCTIONWRAPPERS_H
end_define
begin_include
include|#
directive|include
file|<QtConcurrent/qtconcurrentcompilertest.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/QStringList>
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_CONCURRENT
end_ifndef
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
ifndef|#
directive|ifndef
name|Q_QDOC
name|namespace
name|QtConcurrent
block|{
name|template
operator|<
name|typename
name|T
operator|>
name|class
name|FunctionWrapper0
block|{
name|public
operator|:
typedef|typedef
name|T
function_decl|(
modifier|*
name|FunctionPointerType
function_decl|)
parameter_list|()
function_decl|;
typedef|typedef
name|T
name|result_type
typedef|;
specifier|inline
name|FunctionWrapper0
argument_list|(
argument|FunctionPointerType _functionPointer
argument_list|)
operator|:
name|functionPointer
argument_list|(
argument|_functionPointer
argument_list|)
block|{ }
specifier|inline
name|T
name|operator
argument_list|()
operator|(
operator|)
block|{
return|return
name|functionPointer
argument_list|()
return|;
block|}
name|private
label|:
name|FunctionPointerType
name|functionPointer
decl_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|,
name|typename
name|U
operator|>
name|class
name|FunctionWrapper1
block|{
name|public
operator|:
typedef|typedef
name|T
function_decl|(
modifier|*
name|FunctionPointerType
function_decl|)
parameter_list|(
name|U
name|u
parameter_list|)
function_decl|;
end_expr_stmt
begin_typedef
typedef|typedef
name|T
name|result_type
typedef|;
end_typedef
begin_expr_stmt
specifier|inline
name|FunctionWrapper1
argument_list|(
argument|FunctionPointerType _functionPointer
argument_list|)
operator|:
name|functionPointer
argument_list|(
argument|_functionPointer
argument_list|)
block|{ }
specifier|inline
name|T
name|operator
argument_list|()
operator|(
name|U
name|u
operator|)
block|{
return|return
name|functionPointer
argument_list|(
name|u
argument_list|)
return|;
block|}
end_expr_stmt
begin_label
name|private
label|:
end_label
begin_decl_stmt
name|FunctionPointerType
name|functionPointer
decl_stmt|;
end_decl_stmt
begin_expr_stmt
unit|};
name|template
operator|<
name|typename
name|T
operator|,
name|typename
name|U
operator|,
name|typename
name|V
operator|>
name|class
name|FunctionWrapper2
block|{
name|public
operator|:
typedef|typedef
name|T
function_decl|(
modifier|*
name|FunctionPointerType
function_decl|)
parameter_list|(
name|U
name|u
parameter_list|,
name|V
name|v
parameter_list|)
function_decl|;
end_expr_stmt
begin_typedef
typedef|typedef
name|T
name|result_type
typedef|;
end_typedef
begin_expr_stmt
specifier|inline
name|FunctionWrapper2
argument_list|(
argument|FunctionPointerType _functionPointer
argument_list|)
operator|:
name|functionPointer
argument_list|(
argument|_functionPointer
argument_list|)
block|{ }
specifier|inline
name|T
name|operator
argument_list|()
operator|(
name|U
name|u
operator|,
name|V
name|v
operator|)
block|{
return|return
name|functionPointer
argument_list|(
name|u
argument_list|,
name|v
argument_list|)
return|;
block|}
end_expr_stmt
begin_label
name|private
label|:
end_label
begin_decl_stmt
name|FunctionPointerType
name|functionPointer
decl_stmt|;
end_decl_stmt
begin_expr_stmt
unit|};
name|template
operator|<
name|typename
name|T
operator|,
name|typename
name|C
operator|>
name|class
name|MemberFunctionWrapper
block|{
name|public
operator|:
typedef|typedef
name|T
argument_list|(
name|C
operator|::
operator|*
name|FunctionPointerType
argument_list|)
argument_list|()
expr_stmt|;
end_expr_stmt
begin_typedef
typedef|typedef
name|T
name|result_type
typedef|;
end_typedef
begin_expr_stmt
specifier|inline
name|MemberFunctionWrapper
argument_list|(
argument|FunctionPointerType _functionPointer
argument_list|)
operator|:
name|functionPointer
argument_list|(
argument|_functionPointer
argument_list|)
block|{ }
specifier|inline
name|T
name|operator
argument_list|()
operator|(
name|C
operator|&
name|c
operator|)
block|{
return|return
operator|(
name|c
operator|.*
name|functionPointer
operator|)
operator|(
operator|)
return|;
block|}
end_expr_stmt
begin_label
name|private
label|:
end_label
begin_decl_stmt
name|FunctionPointerType
name|functionPointer
decl_stmt|;
end_decl_stmt
begin_expr_stmt
unit|};
name|template
operator|<
name|typename
name|T
operator|,
name|typename
name|C
operator|,
name|typename
name|U
operator|>
name|class
name|MemberFunctionWrapper1
block|{
name|public
operator|:
typedef|typedef
name|T
argument_list|(
name|C
operator|::
operator|*
name|FunctionPointerType
argument_list|)
argument_list|(
name|U
argument_list|)
expr_stmt|;
end_expr_stmt
begin_typedef
typedef|typedef
name|T
name|result_type
typedef|;
end_typedef
begin_expr_stmt
specifier|inline
name|MemberFunctionWrapper1
argument_list|(
argument|FunctionPointerType _functionPointer
argument_list|)
operator|:
name|functionPointer
argument_list|(
argument|_functionPointer
argument_list|)
block|{ }
specifier|inline
name|T
name|operator
argument_list|()
operator|(
name|C
operator|&
name|c
operator|,
name|U
name|u
operator|)
block|{
return|return
operator|(
name|c
operator|.*
name|functionPointer
operator|)
operator|(
name|u
operator|)
return|;
block|}
end_expr_stmt
begin_label
name|private
label|:
end_label
begin_decl_stmt
name|FunctionPointerType
name|functionPointer
decl_stmt|;
end_decl_stmt
begin_expr_stmt
unit|};
name|template
operator|<
name|typename
name|T
operator|,
name|typename
name|C
operator|>
name|class
name|ConstMemberFunctionWrapper
block|{
name|public
operator|:
typedef|typedef
name|T
argument_list|(
argument|C::*FunctionPointerType
argument_list|)
operator|(
operator|)
specifier|const
expr_stmt|;
end_expr_stmt
begin_typedef
typedef|typedef
name|T
name|result_type
typedef|;
end_typedef
begin_expr_stmt
specifier|inline
name|ConstMemberFunctionWrapper
argument_list|(
argument|FunctionPointerType _functionPointer
argument_list|)
operator|:
name|functionPointer
argument_list|(
argument|_functionPointer
argument_list|)
block|{ }
specifier|inline
name|T
name|operator
argument_list|()
operator|(
specifier|const
name|C
operator|&
name|c
operator|)
specifier|const
block|{
return|return
operator|(
name|c
operator|.*
name|functionPointer
operator|)
operator|(
operator|)
return|;
block|}
end_expr_stmt
begin_label
name|private
label|:
end_label
begin_decl_stmt
name|FunctionPointerType
name|functionPointer
decl_stmt|;
end_decl_stmt
begin_comment
unit|};  }
comment|// namespace QtConcurrent.
end_comment
begin_macro
unit|namespace
name|QtPrivate
end_macro
begin_block
block|{
name|template
operator|<
name|typename
name|T
operator|>
specifier|const
name|T
operator|&
name|createFunctionWrapper
argument_list|(
argument|const T& t
argument_list|)
block|{
return|return
name|t
return|;
block|}
name|template
operator|<
name|typename
name|T
operator|,
name|typename
name|U
operator|>
name|QtConcurrent
operator|::
name|FunctionWrapper1
operator|<
name|T
operator|,
name|U
operator|>
name|createFunctionWrapper
argument_list|(
argument|T (*func)(U)
argument_list|)
block|{
return|return
name|QtConcurrent
operator|::
name|FunctionWrapper1
operator|<
name|T
operator|,
name|U
operator|>
operator|(
name|func
operator|)
return|;
block|}
name|template
operator|<
name|typename
name|T
operator|,
name|typename
name|C
operator|>
name|QtConcurrent
operator|::
name|MemberFunctionWrapper
operator|<
name|T
operator|,
name|C
operator|>
name|createFunctionWrapper
argument_list|(
argument|T (C::*func)()
argument_list|)
block|{
return|return
name|QtConcurrent
operator|::
name|MemberFunctionWrapper
operator|<
name|T
operator|,
name|C
operator|>
operator|(
name|func
operator|)
return|;
block|}
name|template
operator|<
name|typename
name|T
operator|,
name|typename
name|C
operator|,
name|typename
name|U
operator|>
name|QtConcurrent
operator|::
name|MemberFunctionWrapper1
operator|<
name|T
operator|,
name|C
operator|,
name|U
operator|>
name|createFunctionWrapper
argument_list|(
argument|T (C::*func)(U)
argument_list|)
block|{
return|return
name|QtConcurrent
operator|::
name|MemberFunctionWrapper1
operator|<
name|T
operator|,
name|C
operator|,
name|U
operator|>
operator|(
name|func
operator|)
return|;
block|}
name|template
operator|<
name|typename
name|T
operator|,
name|typename
name|C
operator|>
name|QtConcurrent
operator|::
name|ConstMemberFunctionWrapper
operator|<
name|T
operator|,
name|C
operator|>
name|createFunctionWrapper
argument_list|(
argument|T (C::*func)() const
argument_list|)
block|{
return|return
name|QtConcurrent
operator|::
name|ConstMemberFunctionWrapper
operator|<
name|T
operator|,
name|C
operator|>
operator|(
name|func
operator|)
return|;
block|}
struct|struct
name|PushBackWrapper
block|{
typedef|typedef
name|void
name|result_type
typedef|;
name|template
operator|<
name|class
name|C
operator|,
name|class
name|U
operator|>
specifier|inline
name|void
name|operator
argument_list|()
operator|(
name|C
operator|&
name|c
operator|,
specifier|const
name|U
operator|&
name|u
operator|)
specifier|const
block|{
return|return
name|c
operator|.
name|push_back
argument_list|(
name|u
argument_list|)
return|;
block|}
ifdef|#
directive|ifdef
name|Q_COMPILER_RVALUE_REFS
name|template
operator|<
name|class
name|C
operator|,
name|class
name|U
operator|>
specifier|inline
name|void
name|operator
argument_list|()
operator|(
name|C
operator|&
name|c
operator|,
name|U
operator|&&
name|u
operator|)
specifier|const
block|{
return|return
name|c
operator|.
name|push_back
argument_list|(
name|u
argument_list|)
return|;
block|}
endif|#
directive|endif
block|}
struct|;
name|template
operator|<
name|typename
name|Functor
operator|,
name|bool
name|foo
operator|=
name|HasResultType
operator|<
name|Functor
operator|>
operator|::
name|Value
operator|>
expr|struct
name|LazyResultType
block|{
typedef|typedef
name|typename
name|Functor
operator|::
name|result_type
name|Type
expr_stmt|;
block|}
empty_stmt|;
name|template
operator|<
name|typename
name|Functor
operator|>
expr|struct
name|LazyResultType
operator|<
name|Functor
operator|,
name|false
operator|>
block|{
typedef|typedef
name|void
name|Type
typedef|;
block|}
empty_stmt|;
name|template
operator|<
name|class
name|T
operator|>
expr|struct
name|ReduceResultType
expr_stmt|;
name|template
operator|<
name|class
name|U
operator|,
name|class
name|V
operator|>
expr|struct
name|ReduceResultType
operator|<
name|void
argument_list|(
operator|*
argument_list|)
argument_list|(
name|U
operator|&
argument_list|,
name|V
argument_list|)
operator|>
block|{
typedef|typedef
name|U
name|ResultType
typedef|;
block|}
empty_stmt|;
name|template
operator|<
name|class
name|T
operator|,
name|class
name|C
operator|,
name|class
name|U
operator|>
expr|struct
name|ReduceResultType
operator|<
name|T
argument_list|(
name|C
operator|::
operator|*
argument_list|)
argument_list|(
name|U
argument_list|)
operator|>
block|{
typedef|typedef
name|C
name|ResultType
typedef|;
block|}
empty_stmt|;
name|template
operator|<
name|class
name|InputSequence
operator|,
name|class
name|MapFunctor
operator|>
expr|struct
name|MapResultType
block|{
typedef|typedef
name|typename
name|LazyResultType
operator|<
name|MapFunctor
operator|>
operator|::
name|Type
name|ResultType
expr_stmt|;
block|}
empty_stmt|;
name|template
operator|<
name|class
name|U
operator|,
name|class
name|V
operator|>
expr|struct
name|MapResultType
operator|<
name|void
operator|,
name|U
argument_list|(
operator|*
argument_list|)
argument_list|(
name|V
argument_list|)
operator|>
block|{
typedef|typedef
name|U
name|ResultType
typedef|;
block|}
empty_stmt|;
name|template
operator|<
name|class
name|T
operator|,
name|class
name|C
operator|>
expr|struct
name|MapResultType
operator|<
name|void
operator|,
name|T
argument_list|(
argument|C::*
argument_list|)
operator|(
operator|)
specifier|const
operator|>
block|{
typedef|typedef
name|T
name|ResultType
typedef|;
block|}
empty_stmt|;
ifndef|#
directive|ifndef
name|QT_NO_TEMPLATE_TEMPLATE_PARAMETERS
name|template
operator|<
name|template
operator|<
name|typename
operator|>
name|class
name|InputSequence
operator|,
name|typename
name|MapFunctor
operator|,
name|typename
name|T
operator|>
expr|struct
name|MapResultType
operator|<
name|InputSequence
operator|<
name|T
operator|>
operator|,
name|MapFunctor
operator|>
block|{
typedef|typedef
name|InputSequence
operator|<
name|typename
name|LazyResultType
operator|<
name|MapFunctor
operator|>
operator|::
name|Type
operator|>
name|ResultType
expr_stmt|;
block|}
empty_stmt|;
name|template
operator|<
name|template
operator|<
name|typename
operator|>
name|class
name|InputSequence
operator|,
name|class
name|T
operator|,
name|class
name|U
operator|,
name|class
name|V
operator|>
expr|struct
name|MapResultType
operator|<
name|InputSequence
operator|<
name|T
operator|>
operator|,
name|U
argument_list|(
operator|*
argument_list|)
argument_list|(
name|V
argument_list|)
operator|>
block|{
typedef|typedef
name|InputSequence
operator|<
name|U
operator|>
name|ResultType
expr_stmt|;
block|}
empty_stmt|;
name|template
operator|<
name|template
operator|<
name|typename
operator|>
name|class
name|InputSequence
operator|,
name|class
name|T
operator|,
name|class
name|U
operator|,
name|class
name|C
operator|>
expr|struct
name|MapResultType
operator|<
name|InputSequence
operator|<
name|T
operator|>
operator|,
name|U
argument_list|(
argument|C::*
argument_list|)
operator|(
operator|)
specifier|const
operator|>
block|{
typedef|typedef
name|InputSequence
operator|<
name|U
operator|>
name|ResultType
expr_stmt|;
block|}
empty_stmt|;
endif|#
directive|endif
comment|// QT_NO_TEMPLATE_TEMPLATE_PARAMETER
name|template
operator|<
name|class
name|MapFunctor
operator|>
expr|struct
name|MapResultType
operator|<
name|QStringList
operator|,
name|MapFunctor
operator|>
block|{
typedef|typedef
name|QList
operator|<
name|typename
name|LazyResultType
operator|<
name|MapFunctor
operator|>
operator|::
name|Type
operator|>
name|ResultType
expr_stmt|;
block|}
empty_stmt|;
name|template
operator|<
name|class
name|U
operator|,
name|class
name|V
operator|>
expr|struct
name|MapResultType
operator|<
name|QStringList
operator|,
name|U
argument_list|(
operator|*
argument_list|)
argument_list|(
name|V
argument_list|)
operator|>
block|{
typedef|typedef
name|QList
operator|<
name|U
operator|>
name|ResultType
expr_stmt|;
block|}
empty_stmt|;
name|template
operator|<
name|class
name|U
operator|,
name|class
name|C
operator|>
expr|struct
name|MapResultType
operator|<
name|QStringList
operator|,
name|U
argument_list|(
argument|C::*
argument_list|)
operator|(
operator|)
specifier|const
operator|>
block|{
typedef|typedef
name|QList
operator|<
name|U
operator|>
name|ResultType
expr_stmt|;
block|}
empty_stmt|;
block|}
end_block
begin_comment
comment|// namespace QtPrivate.
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|//Q_QDOC
end_comment
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_CONCURRENT
end_comment
begin_endif
endif|#
directive|endif
end_endif
end_unit
