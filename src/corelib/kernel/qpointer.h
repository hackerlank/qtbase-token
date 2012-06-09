begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QPOINTER_H
end_ifndef
begin_define
DECL|macro|QPOINTER_H
define|#
directive|define
name|QPOINTER_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qsharedpointer.h>
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_QOBJECT
end_ifndef
begin_decl_stmt
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
DECL|variable|QVariant
name|class
name|QVariant
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QPointerBase
block|{
name|QWeakPointer
operator|<
name|QObject
operator|>
name|wp
expr_stmt|;
name|protected
label|:
specifier|inline
name|QPointerBase
argument_list|()
operator|:
name|wp
argument_list|()
block|{ }
specifier|inline
name|QPointerBase
argument_list|(
name|QObject
operator|*
name|p
argument_list|)
operator|:
name|wp
argument_list|(
argument|p
argument_list|,
argument|true
argument_list|)
block|{ }
comment|// compiler-generated copy/move ctor/assignment operators are fine! (even though public)
specifier|inline
operator|~
name|QPointerBase
argument_list|()
block|{ }
specifier|inline
name|QObject
operator|*
name|data
argument_list|()
specifier|const
block|{
return|return
name|wp
operator|.
name|data
argument_list|()
return|;
block|}
specifier|inline
name|void
name|assign
parameter_list|(
name|QObject
modifier|*
name|p
parameter_list|)
block|{
name|wp
operator|.
name|assign
argument_list|(
name|p
argument_list|)
expr_stmt|;
block|}
specifier|inline
name|bool
name|isNull
argument_list|()
specifier|const
block|{
return|return
name|wp
operator|.
name|isNull
argument_list|()
return|;
block|}
specifier|inline
name|void
name|clear
parameter_list|()
block|{
name|wp
operator|.
name|clear
argument_list|()
expr_stmt|;
block|}
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_expr_stmt
name|template
operator|<
name|class
name|T
operator|>
name|class
name|QPointer
operator|:
name|private
name|QPointerBase
block|{
name|public
operator|:
specifier|inline
name|QPointer
argument_list|()
block|{ }
specifier|inline
name|QPointer
argument_list|(
name|T
operator|*
name|p
argument_list|)
operator|:
name|QPointerBase
argument_list|(
argument|p
argument_list|)
block|{ }
comment|// compiler-generated copy/move ctor/assignment operators are fine!
specifier|inline
operator|~
name|QPointer
argument_list|()
block|{ }
specifier|inline
name|QPointer
operator|<
name|T
operator|>
operator|&
name|operator
operator|=
operator|(
name|T
operator|*
name|p
operator|)
block|{
name|QPointerBase
operator|::
name|assign
argument_list|(
name|p
argument_list|)
block|;
return|return
operator|*
name|this
return|;
block|}
specifier|inline
name|T
operator|*
name|data
argument_list|()
specifier|const
block|{
return|return
name|static_cast
operator|<
name|T
operator|*
operator|>
operator|(
name|QPointerBase
operator|::
name|data
argument_list|()
operator|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
name|T
operator|*
name|operator
operator|->
expr|(
end_expr_stmt
begin_expr_stmt
unit|)
specifier|const
block|{
return|return
name|data
argument_list|()
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
name|T
operator|&
name|operator
operator|*
operator|(
operator|)
specifier|const
block|{
return|return
operator|*
name|data
argument_list|()
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
name|operator
name|T
operator|*
operator|(
operator|)
specifier|const
block|{
return|return
name|data
argument_list|()
return|;
block|}
end_expr_stmt
begin_ifdef
ifdef|#
directive|ifdef
name|qdoc
end_ifdef
begin_expr_stmt
specifier|inline
name|bool
name|isNull
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_expr_stmt
specifier|inline
name|void
name|clear
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_else
else|#
directive|else
end_else
begin_expr_stmt
name|using
name|QPointerBase
operator|::
name|isNull
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|using
name|QPointerBase
operator|::
name|clear
expr_stmt|;
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_expr_stmt
unit|};
name|template
operator|<
name|class
name|T
operator|>
name|Q_DECLARE_TYPEINFO_BODY
argument_list|(
name|QPointer
operator|<
name|T
operator|>
argument_list|,
name|Q_MOVABLE_TYPE
argument_list|)
expr_stmt|;
end_expr_stmt
begin_if
if|#
directive|if
operator|(
operator|!
name|defined
argument_list|(
name|Q_CC_SUN
argument_list|)
operator|||
operator|(
name|__SUNPRO_CC
operator|>=
literal|0x580
operator|)
operator|)
end_if
begin_comment
comment|// ambiguity between const T * and T *
end_comment
begin_expr_stmt
name|template
operator|<
name|class
name|T
operator|>
DECL|function|operator
specifier|inline
name|bool
name|operator
operator|==
operator|(
specifier|const
name|T
operator|*
name|o
operator|,
specifier|const
name|QPointer
operator|<
name|T
operator|>
operator|&
name|p
operator|)
block|{
return|return
name|o
operator|==
name|p
operator|.
name|operator
operator|->
expr|(
block|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
unit|}  template
operator|<
name|class
name|T
operator|>
specifier|inline
name|bool
name|operator
operator|==
operator|(
specifier|const
name|QPointer
operator|<
name|T
operator|>
operator|&
name|p
operator|,
specifier|const
name|T
operator|*
name|o
operator|)
block|{
return|return
name|p
operator|.
name|operator
operator|->
expr|(
block|)
operator|==
name|o
expr_stmt|;
end_expr_stmt
begin_else
unit|}
else|#
directive|else
end_else
begin_expr_stmt
unit|template
operator|<
name|class
name|T
operator|>
DECL|function|operator
specifier|inline
name|bool
name|operator
operator|==
operator|(
specifier|const
name|void
operator|*
name|o
operator|,
specifier|const
name|QPointer
operator|<
name|T
operator|>
operator|&
name|p
operator|)
block|{
return|return
name|o
operator|==
name|p
operator|.
name|operator
operator|->
expr|(
block|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
unit|}  template
operator|<
name|class
name|T
operator|>
specifier|inline
name|bool
name|operator
operator|==
operator|(
specifier|const
name|QPointer
operator|<
name|T
operator|>
operator|&
name|p
operator|,
specifier|const
name|void
operator|*
name|o
operator|)
block|{
return|return
name|p
operator|.
name|operator
operator|->
expr|(
block|)
operator|==
name|o
expr_stmt|;
end_expr_stmt
begin_endif
unit|}
endif|#
directive|endif
end_endif
begin_expr_stmt
unit|template
operator|<
name|class
name|T
operator|>
DECL|function|operator
specifier|inline
name|bool
name|operator
operator|==
operator|(
name|T
operator|*
name|o
operator|,
specifier|const
name|QPointer
operator|<
name|T
operator|>
operator|&
name|p
operator|)
block|{
return|return
name|o
operator|==
name|p
operator|.
name|operator
operator|->
expr|(
block|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
unit|}  template
operator|<
name|class
name|T
operator|>
specifier|inline
name|bool
name|operator
operator|==
operator|(
specifier|const
name|QPointer
operator|<
name|T
operator|>
operator|&
name|p
operator|,
name|T
operator|*
name|o
operator|)
block|{
return|return
name|p
operator|.
name|operator
operator|->
expr|(
block|)
operator|==
name|o
expr_stmt|;
end_expr_stmt
begin_expr_stmt
unit|}  template
operator|<
name|class
name|T
operator|>
specifier|inline
name|bool
name|operator
operator|==
operator|(
specifier|const
name|QPointer
operator|<
name|T
operator|>
operator|&
name|p1
operator|,
specifier|const
name|QPointer
operator|<
name|T
operator|>
operator|&
name|p2
operator|)
block|{
return|return
name|p1
operator|.
name|operator
operator|->
expr|(
block|)
operator|==
name|p2
operator|.
name|operator
operator|->
block|()
expr_stmt|;
end_expr_stmt
begin_if
unit|}
if|#
directive|if
operator|(
operator|!
name|defined
argument_list|(
name|Q_CC_SUN
argument_list|)
operator|||
operator|(
name|__SUNPRO_CC
operator|>=
literal|0x580
operator|)
operator|)
end_if
begin_comment
comment|// ambiguity between const T * and T *
end_comment
begin_expr_stmt
unit|template
operator|<
name|class
name|T
operator|>
DECL|function|operator
specifier|inline
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|T
operator|*
name|o
operator|,
specifier|const
name|QPointer
operator|<
name|T
operator|>
operator|&
name|p
operator|)
block|{
return|return
name|o
operator|!=
name|p
operator|.
name|operator
operator|->
expr|(
block|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
unit|}  template
operator|<
name|class
name|T
operator|>
specifier|inline
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|QPointer
operator|<
name|T
operator|>
operator|&
name|p
operator|,
specifier|const
name|T
operator|*
name|o
operator|)
block|{
return|return
name|p
operator|.
name|operator
operator|->
expr|(
block|)
operator|!=
name|o
expr_stmt|;
end_expr_stmt
begin_else
unit|}
else|#
directive|else
end_else
begin_expr_stmt
unit|template
operator|<
name|class
name|T
operator|>
DECL|function|operator
specifier|inline
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|void
operator|*
name|o
operator|,
specifier|const
name|QPointer
operator|<
name|T
operator|>
operator|&
name|p
operator|)
block|{
return|return
name|o
operator|!=
name|p
operator|.
name|operator
operator|->
expr|(
block|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
unit|}  template
operator|<
name|class
name|T
operator|>
specifier|inline
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|QPointer
operator|<
name|T
operator|>
operator|&
name|p
operator|,
specifier|const
name|void
operator|*
name|o
operator|)
block|{
return|return
name|p
operator|.
name|operator
operator|->
expr|(
block|)
operator|!=
name|o
expr_stmt|;
end_expr_stmt
begin_endif
unit|}
endif|#
directive|endif
end_endif
begin_expr_stmt
unit|template
operator|<
name|class
name|T
operator|>
DECL|function|operator
specifier|inline
name|bool
name|operator
operator|!=
operator|(
name|T
operator|*
name|o
operator|,
specifier|const
name|QPointer
operator|<
name|T
operator|>
operator|&
name|p
operator|)
block|{
return|return
name|o
operator|!=
name|p
operator|.
name|operator
operator|->
expr|(
block|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
unit|}  template
operator|<
name|class
name|T
operator|>
specifier|inline
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|QPointer
operator|<
name|T
operator|>
operator|&
name|p
operator|,
name|T
operator|*
name|o
operator|)
block|{
return|return
name|p
operator|.
name|operator
operator|->
expr|(
block|)
operator|!=
name|o
expr_stmt|;
end_expr_stmt
begin_expr_stmt
unit|}  template
operator|<
name|class
name|T
operator|>
specifier|inline
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|QPointer
operator|<
name|T
operator|>
operator|&
name|p1
operator|,
specifier|const
name|QPointer
operator|<
name|T
operator|>
operator|&
name|p2
operator|)
block|{
return|return
name|p1
operator|.
name|operator
operator|->
expr|(
block|)
operator|!=
name|p2
operator|.
name|operator
operator|->
block|()
expr_stmt|;
end_expr_stmt
begin_comment
unit|}
comment|// Make MSVC< 1400 (2005) handle "if (NULL == p)" syntax
end_comment
begin_if
if|#
directive|if
name|defined
argument_list|(
name|Q_CC_MSVC
argument_list|)
operator|&&
operator|(
name|_MSC_VER
operator|<
literal|1400
operator|)
end_if
begin_expr_stmt
unit|template
operator|<
name|class
name|T
operator|>
DECL|function|operator
specifier|inline
name|bool
name|operator
operator|==
operator|(
name|int
name|i
operator|,
specifier|const
name|QPointer
operator|<
name|T
operator|>
operator|&
name|p
operator|)
block|{
name|Q_ASSERT
argument_list|(
name|i
operator|==
literal|0
argument_list|)
block|;
return|return
operator|!
name|i
operator|&&
name|p
operator|.
name|isNull
argument_list|()
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|template
operator|<
name|class
name|T
operator|>
DECL|function|operator
specifier|inline
name|bool
name|operator
operator|!=
operator|(
name|int
name|i
operator|,
specifier|const
name|QPointer
operator|<
name|T
operator|>
operator|&
name|p
operator|)
block|{
name|Q_ASSERT
argument_list|(
name|i
operator|==
literal|0
argument_list|)
block|;
return|return
operator|!
name|i
operator|&&
operator|!
name|p
operator|.
name|isNull
argument_list|()
return|;
block|}
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
name|QPointer
operator|<
name|T
operator|>
DECL|function|qPointerFromVariant
name|qPointerFromVariant
argument_list|(
argument|const QVariant&variant
argument_list|)
block|{
return|return
name|QPointer
operator|<
name|T
operator|>
operator|(
name|qobject_cast
operator|<
name|T
operator|*
operator|>
operator|(
name|QtSharedPointer
operator|::
name|weakPointerFromVariant_internal
argument_list|(
name|variant
argument_list|)
operator|.
name|data
argument_list|()
operator|)
operator|)
return|;
block|}
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
comment|// QT_NO_QOBJECT
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QPOINTER_H
end_comment
end_unit
