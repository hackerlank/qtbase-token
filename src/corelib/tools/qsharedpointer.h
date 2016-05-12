begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QSHAREDPOINTER_H
end_ifndef
begin_define
DECL|macro|QSHAREDPOINTER_H
define|#
directive|define
name|QSHAREDPOINTER_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qglobal.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qatomic.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qshareddata.h>
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|Q_QDOC
end_ifndef
begin_include
include|#
directive|include
file|<QtCore/qsharedpointer_impl.h>
end_include
begin_else
else|#
directive|else
end_else
begin_expr_stmt
name|QT_BEGIN_NAMESPACE
comment|// These classes are here to fool qdoc into generating a better documentation
name|template
operator|<
name|class
name|T
operator|>
name|class
name|QSharedPointer
block|{
name|public
operator|:
comment|// basic accessor functions
name|T
operator|*
name|data
argument_list|()
specifier|const
block|;
name|bool
name|isNull
argument_list|()
specifier|const
block|;
name|operator
name|bool
argument_list|()
specifier|const
block|;
name|bool
name|operator
operator|!
operator|(
operator|)
specifier|const
block|;
name|T
operator|&
name|operator
operator|*
operator|(
operator|)
specifier|const
block|;
name|T
operator|*
name|operator
operator|->
expr|(
block|)
specifier|const
expr_stmt|;
end_expr_stmt
begin_comment
comment|// constructors
end_comment
begin_expr_stmt
name|QSharedPointer
argument_list|()
expr_stmt|;
end_expr_stmt
begin_function_decl
name|explicit
name|QSharedPointer
parameter_list|(
name|T
modifier|*
name|ptr
parameter_list|)
function_decl|;
end_function_decl
begin_macro
name|QSharedPointer
argument_list|(
argument|T *ptr
argument_list|,
argument|Deleter d
argument_list|)
end_macro
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_expr_stmt
name|QSharedPointer
argument_list|(
specifier|const
name|QSharedPointer
operator|<
name|T
operator|>
operator|&
name|other
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|QSharedPointer
argument_list|(
specifier|const
name|QWeakPointer
operator|<
name|T
operator|>
operator|&
name|other
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
operator|~
name|QSharedPointer
argument_list|()
block|{ }
name|QSharedPointer
operator|<
name|T
operator|>
operator|&
name|operator
operator|=
operator|(
specifier|const
name|QSharedPointer
operator|<
name|T
operator|>
operator|&
name|other
operator|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|QSharedPointer
operator|<
name|T
operator|>
operator|&
name|operator
operator|=
operator|(
specifier|const
name|QWeakPointer
operator|<
name|T
operator|>
operator|&
name|other
operator|)
expr_stmt|;
end_expr_stmt
begin_decl_stmt
name|void
name|swap
argument_list|(
name|QSharedPointer
operator|<
name|T
operator|>
operator|&
name|other
argument_list|)
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|QWeakPointer
operator|<
name|T
operator|>
name|toWeakRef
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_function_decl
name|void
name|clear
parameter_list|()
function_decl|;
end_function_decl
begin_function_decl
name|void
name|reset
parameter_list|()
function_decl|;
end_function_decl
begin_function_decl
name|void
name|reset
parameter_list|(
name|T
modifier|*
name|t
parameter_list|)
function_decl|;
end_function_decl
begin_expr_stmt
name|template
operator|<
name|typename
name|Deleter
operator|>
name|void
name|reset
argument_list|(
argument|T *t
argument_list|,
argument|Deleter deleter
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|// casts:
end_comment
begin_expr_stmt
name|template
operator|<
name|class
name|X
operator|>
name|QSharedPointer
operator|<
name|X
operator|>
name|staticCast
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|template
operator|<
name|class
name|X
operator|>
name|QSharedPointer
operator|<
name|X
operator|>
name|dynamicCast
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|template
operator|<
name|class
name|X
operator|>
name|QSharedPointer
operator|<
name|X
operator|>
name|constCast
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|template
operator|<
name|class
name|X
operator|>
name|QSharedPointer
operator|<
name|X
operator|>
name|objectCast
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_expr_stmt
specifier|static
specifier|inline
name|QSharedPointer
operator|<
name|T
operator|>
name|create
argument_list|()
expr_stmt|;
end_expr_stmt
begin_expr_stmt
specifier|static
specifier|inline
name|QSharedPointer
operator|<
name|T
operator|>
name|create
argument_list|(
operator|...
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
unit|};
name|template
operator|<
name|class
name|T
operator|>
name|class
name|QWeakPointer
block|{
name|public
operator|:
comment|// basic accessor functions
name|bool
name|isNull
argument_list|()
specifier|const
block|;
name|operator
name|bool
argument_list|()
specifier|const
block|;
name|bool
name|operator
operator|!
operator|(
operator|)
specifier|const
block|;
comment|// constructors:
name|QWeakPointer
argument_list|()
block|;
name|QWeakPointer
argument_list|(
specifier|const
name|QWeakPointer
operator|<
name|T
operator|>
operator|&
name|other
argument_list|)
block|;
name|QWeakPointer
argument_list|(
specifier|const
name|QSharedPointer
operator|<
name|T
operator|>
operator|&
name|other
argument_list|)
block|;
operator|~
name|QWeakPointer
argument_list|()
block|;
name|QWeakPointer
operator|<
name|T
operator|>
operator|&
name|operator
operator|=
operator|(
specifier|const
name|QWeakPointer
operator|<
name|T
operator|>
operator|&
name|other
operator|)
block|;
name|QWeakPointer
operator|<
name|T
operator|>
operator|&
name|operator
operator|=
operator|(
specifier|const
name|QSharedPointer
operator|<
name|T
operator|>
operator|&
name|other
operator|)
block|;
name|QWeakPointer
argument_list|(
specifier|const
name|QObject
operator|*
name|other
argument_list|)
block|;
name|QWeakPointer
operator|<
name|T
operator|>
operator|&
name|operator
operator|=
operator|(
specifier|const
name|QObject
operator|*
name|other
operator|)
block|;
name|void
name|swap
argument_list|(
name|QWeakPointer
operator|<
name|T
operator|>
operator|&
name|other
argument_list|)
block|;
name|T
operator|*
name|data
argument_list|()
specifier|const
block|;
name|void
name|clear
argument_list|()
block|;
name|QSharedPointer
operator|<
name|T
operator|>
name|toStrongRef
argument_list|()
specifier|const
block|;
name|QSharedPointer
operator|<
name|T
operator|>
name|lock
argument_list|()
specifier|const
block|; }
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|template
operator|<
name|class
name|T
operator|>
name|class
name|QEnableSharedFromThis
block|{
name|public
operator|:
name|QSharedPointer
operator|<
name|T
operator|>
name|sharedFromThis
argument_list|()
block|;
name|QSharedPointer
operator|<
specifier|const
name|T
operator|>
name|sharedFromThis
argument_list|()
specifier|const
block|; }
expr_stmt|;
end_expr_stmt
begin_expr_stmt
DECL|variable|T
name|template
operator|<
name|class
name|T
operator|,
name|class
name|X
operator|>
name|bool
name|operator
operator|==
operator|(
specifier|const
name|QSharedPointer
operator|<
name|T
operator|>
operator|&
name|ptr1
operator|,
specifier|const
name|QSharedPointer
operator|<
name|X
operator|>
operator|&
name|ptr2
operator|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
DECL|variable|T
name|template
operator|<
name|class
name|T
operator|,
name|class
name|X
operator|>
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|QSharedPointer
operator|<
name|T
operator|>
operator|&
name|ptr1
operator|,
specifier|const
name|QSharedPointer
operator|<
name|X
operator|>
operator|&
name|ptr2
operator|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
DECL|variable|T
name|template
operator|<
name|class
name|T
operator|,
name|class
name|X
operator|>
name|bool
name|operator
operator|==
operator|(
specifier|const
name|QSharedPointer
operator|<
name|T
operator|>
operator|&
name|ptr1
operator|,
specifier|const
name|X
operator|*
name|ptr2
operator|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
DECL|variable|T
name|template
operator|<
name|class
name|T
operator|,
name|class
name|X
operator|>
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|QSharedPointer
operator|<
name|T
operator|>
operator|&
name|ptr1
operator|,
specifier|const
name|X
operator|*
name|ptr2
operator|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
DECL|variable|T
name|template
operator|<
name|class
name|T
operator|,
name|class
name|X
operator|>
name|bool
name|operator
operator|==
operator|(
specifier|const
name|T
operator|*
name|ptr1
operator|,
specifier|const
name|QSharedPointer
operator|<
name|X
operator|>
operator|&
name|ptr2
operator|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
DECL|variable|T
name|template
operator|<
name|class
name|T
operator|,
name|class
name|X
operator|>
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|T
operator|*
name|ptr1
operator|,
specifier|const
name|QSharedPointer
operator|<
name|X
operator|>
operator|&
name|ptr2
operator|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
DECL|variable|T
name|template
operator|<
name|class
name|T
operator|,
name|class
name|X
operator|>
name|bool
name|operator
operator|==
operator|(
specifier|const
name|QWeakPointer
operator|<
name|T
operator|>
operator|&
name|ptr1
operator|,
specifier|const
name|QSharedPointer
operator|<
name|X
operator|>
operator|&
name|ptr2
operator|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
DECL|variable|T
name|template
operator|<
name|class
name|T
operator|,
name|class
name|X
operator|>
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|QWeakPointer
operator|<
name|T
operator|>
operator|&
name|ptr1
operator|,
specifier|const
name|QSharedPointer
operator|<
name|X
operator|>
operator|&
name|ptr2
operator|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
DECL|variable|T
name|template
operator|<
name|class
name|T
operator|,
name|class
name|X
operator|>
name|bool
name|operator
operator|==
operator|(
specifier|const
name|QSharedPointer
operator|<
name|T
operator|>
operator|&
name|ptr1
operator|,
specifier|const
name|QWeakPointer
operator|<
name|X
operator|>
operator|&
name|ptr2
operator|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
DECL|variable|T
name|template
operator|<
name|class
name|T
operator|,
name|class
name|X
operator|>
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|QSharedPointer
operator|<
name|T
operator|>
operator|&
name|ptr1
operator|,
specifier|const
name|QWeakPointer
operator|<
name|X
operator|>
operator|&
name|ptr2
operator|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
DECL|variable|X
name|template
operator|<
name|class
name|X
operator|,
name|class
name|T
operator|>
name|QSharedPointer
operator|<
name|X
operator|>
name|qSharedPointerCast
argument_list|(
specifier|const
name|QSharedPointer
operator|<
name|T
operator|>
operator|&
name|other
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
DECL|variable|X
name|template
operator|<
name|class
name|X
operator|,
name|class
name|T
operator|>
name|QSharedPointer
operator|<
name|X
operator|>
name|qSharedPointerCast
argument_list|(
specifier|const
name|QWeakPointer
operator|<
name|T
operator|>
operator|&
name|other
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
DECL|variable|X
name|template
operator|<
name|class
name|X
operator|,
name|class
name|T
operator|>
name|QSharedPointer
operator|<
name|X
operator|>
name|qSharedPointerDynamicCast
argument_list|(
specifier|const
name|QSharedPointer
operator|<
name|T
operator|>
operator|&
name|src
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
DECL|variable|X
name|template
operator|<
name|class
name|X
operator|,
name|class
name|T
operator|>
name|QSharedPointer
operator|<
name|X
operator|>
name|qSharedPointerDynamicCast
argument_list|(
specifier|const
name|QWeakPointer
operator|<
name|T
operator|>
operator|&
name|src
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
DECL|variable|X
name|template
operator|<
name|class
name|X
operator|,
name|class
name|T
operator|>
name|QSharedPointer
operator|<
name|X
operator|>
name|qSharedPointerConstCast
argument_list|(
specifier|const
name|QSharedPointer
operator|<
name|T
operator|>
operator|&
name|src
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
DECL|variable|X
name|template
operator|<
name|class
name|X
operator|,
name|class
name|T
operator|>
name|QSharedPointer
operator|<
name|X
operator|>
name|qSharedPointerConstCast
argument_list|(
specifier|const
name|QWeakPointer
operator|<
name|T
operator|>
operator|&
name|src
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
DECL|variable|X
name|template
operator|<
name|class
name|X
operator|,
name|class
name|T
operator|>
name|QSharedPointer
operator|<
name|X
operator|>
name|qSharedPointerObjectCast
argument_list|(
specifier|const
name|QSharedPointer
operator|<
name|T
operator|>
operator|&
name|src
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
DECL|variable|X
name|template
operator|<
name|class
name|X
operator|,
name|class
name|T
operator|>
name|QSharedPointer
operator|<
name|X
operator|>
name|qSharedPointerObjectCast
argument_list|(
specifier|const
name|QWeakPointer
operator|<
name|T
operator|>
operator|&
name|src
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
DECL|variable|X
name|template
operator|<
name|class
name|X
operator|,
name|class
name|T
operator|>
name|QWeakPointer
operator|<
name|X
operator|>
name|qWeakPointerCast
argument_list|(
specifier|const
name|QWeakPointer
operator|<
name|T
operator|>
operator|&
name|src
argument_list|)
expr_stmt|;
end_expr_stmt
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// Q_QDOC
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QSHAREDPOINTER_H
end_comment
end_unit
