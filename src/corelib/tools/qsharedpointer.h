begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
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
begin_decl_stmt
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
DECL|function|QT_MODULE
name|QT_MODULE
argument_list|(
name|Core
argument_list|)
comment|// These classes are here to fool qdoc into generating a better documentation
name|template
decl|<
name|class
name|T
decl|>
name|class
name|QSharedPointer
block|{
name|public
label|:
comment|// basic accessor functions
name|T
operator|*
name|data
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|isNull
argument_list|()
specifier|const
expr_stmt|;
name|operator
name|bool
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|operator
operator|!
operator|(
operator|)
specifier|const
expr_stmt|;
name|T
operator|&
name|operator
operator|*
operator|(
operator|)
specifier|const
expr_stmt|;
name|T
operator|*
name|operator
operator|->
expr|(
block|)
decl|const
decl_stmt|;
end_decl_stmt
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
name|operator
operator|=
operator|(
specifier|const
name|QObject
operator|*
name|other
operator|)
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
begin_expr_stmt
name|QT_END_NAMESPACE
name|QT_END_HEADER
end_expr_stmt
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
