begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QSIZE_H
end_ifndef
begin_define
DECL|macro|QSIZE_H
define|#
directive|define
name|QSIZE_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qnamespace.h>
end_include
begin_function
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
DECL|function|QT_MODULE
name|QT_MODULE
parameter_list|(
name|Core
parameter_list|)
name|class
name|Q_CORE_EXPORT
name|QSize
decl_stmt|{ public:     QSize(
end_function
begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt
begin_macro
name|QSize
argument_list|(
argument|int w
argument_list|,
argument|int h
argument_list|)
end_macro
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_expr_stmt
name|bool
name|isNull
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|bool
name|isEmpty
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|bool
name|isValid
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|int
name|width
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|int
name|height
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_function_decl
name|void
name|setWidth
parameter_list|(
name|int
name|w
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|setHeight
parameter_list|(
name|int
name|h
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|transpose
parameter_list|()
function_decl|;
end_function_decl
begin_decl_stmt
name|void
name|scale
argument_list|(
name|int
name|w
argument_list|,
name|int
name|h
argument_list|,
name|Qt
operator|::
name|AspectRatioMode
name|mode
argument_list|)
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|void
name|scale
argument_list|(
specifier|const
name|QSize
operator|&
name|s
argument_list|,
name|Qt
operator|::
name|AspectRatioMode
name|mode
argument_list|)
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QSize
name|expandedTo
argument_list|(
specifier|const
name|QSize
operator|&
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QSize
name|boundedTo
argument_list|(
specifier|const
name|QSize
operator|&
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt
begin_function_decl
name|int
modifier|&
name|rwidth
parameter_list|()
function_decl|;
end_function_decl
begin_function_decl
name|int
modifier|&
name|rheight
parameter_list|()
function_decl|;
end_function_decl
begin_expr_stmt
name|QSize
operator|&
name|operator
operator|+=
operator|(
specifier|const
name|QSize
operator|&
operator|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|QSize
operator|&
name|operator
operator|-=
operator|(
specifier|const
name|QSize
operator|&
operator|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|QSize
operator|&
name|operator
operator|*=
operator|(
name|qreal
name|c
operator|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|QSize
operator|&
name|operator
operator|/=
operator|(
name|qreal
name|c
operator|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|friend
specifier|inline
name|bool
name|operator
operator|==
operator|(
specifier|const
name|QSize
operator|&
operator|,
specifier|const
name|QSize
operator|&
operator|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|friend
specifier|inline
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|QSize
operator|&
operator|,
specifier|const
name|QSize
operator|&
operator|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|friend
specifier|inline
specifier|const
name|QSize
name|operator
operator|+
operator|(
specifier|const
name|QSize
operator|&
operator|,
specifier|const
name|QSize
operator|&
operator|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|friend
specifier|inline
specifier|const
name|QSize
name|operator
operator|-
operator|(
specifier|const
name|QSize
operator|&
operator|,
specifier|const
name|QSize
operator|&
operator|)
expr_stmt|;
end_expr_stmt
begin_function_decl
name|friend
specifier|inline
specifier|const
name|QSize
name|operator
modifier|*
parameter_list|(
specifier|const
name|QSize
modifier|&
parameter_list|,
name|qreal
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|friend
specifier|inline
specifier|const
name|QSize
name|operator
modifier|*
parameter_list|(
name|qreal
parameter_list|,
specifier|const
name|QSize
modifier|&
parameter_list|)
function_decl|;
end_function_decl
begin_expr_stmt
name|friend
specifier|inline
specifier|const
name|QSize
name|operator
operator|/
operator|(
specifier|const
name|QSize
operator|&
operator|,
name|qreal
operator|)
expr_stmt|;
end_expr_stmt
begin_label
name|private
label|:
end_label
begin_decl_stmt
name|int
name|wd
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|int
name|ht
decl_stmt|;
end_decl_stmt
begin_expr_stmt
unit|};
name|Q_DECLARE_TYPEINFO
argument_list|(
name|QSize
argument_list|,
name|Q_MOVABLE_TYPE
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|/*****************************************************************************   QSize stream functions  *****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_DATASTREAM
end_ifndef
begin_expr_stmt
name|Q_CORE_EXPORT
name|QDataStream
operator|&
name|operator
operator|<<
operator|(
name|QDataStream
operator|&
operator|,
specifier|const
name|QSize
operator|&
operator|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|Q_CORE_EXPORT
name|QDataStream
operator|&
name|operator
operator|>>
operator|(
name|QDataStream
operator|&
operator|,
name|QSize
operator|&
operator|)
expr_stmt|;
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/*****************************************************************************   QSize inline functions  *****************************************************************************/
end_comment
begin_expr_stmt
DECL|function|QSize
specifier|inline
name|QSize
operator|::
name|QSize
argument_list|()
block|{
name|wd
operator|=
name|ht
operator|=
operator|-
literal|1
block|; }
DECL|function|QSize
specifier|inline
name|QSize
operator|::
name|QSize
argument_list|(
argument|int w
argument_list|,
argument|int h
argument_list|)
block|{
name|wd
operator|=
name|w
block|;
name|ht
operator|=
name|h
block|; }
DECL|function|isNull
specifier|inline
name|bool
name|QSize
operator|::
name|isNull
argument_list|()
specifier|const
block|{
return|return
name|wd
operator|==
literal|0
operator|&&
name|ht
operator|==
literal|0
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|isEmpty
specifier|inline
name|bool
name|QSize
operator|::
name|isEmpty
argument_list|()
specifier|const
block|{
return|return
name|wd
operator|<
literal|1
operator|||
name|ht
operator|<
literal|1
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|isValid
specifier|inline
name|bool
name|QSize
operator|::
name|isValid
argument_list|()
specifier|const
block|{
return|return
name|wd
operator|>=
literal|0
operator|&&
name|ht
operator|>=
literal|0
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|width
specifier|inline
name|int
name|QSize
operator|::
name|width
argument_list|()
specifier|const
block|{
return|return
name|wd
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|height
specifier|inline
name|int
name|QSize
operator|::
name|height
argument_list|()
specifier|const
block|{
return|return
name|ht
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|setWidth
specifier|inline
name|void
name|QSize
operator|::
name|setWidth
argument_list|(
argument|int w
argument_list|)
block|{
name|wd
operator|=
name|w
block|; }
DECL|function|setHeight
specifier|inline
name|void
name|QSize
operator|::
name|setHeight
argument_list|(
argument|int h
argument_list|)
block|{
name|ht
operator|=
name|h
block|; }
DECL|function|scale
specifier|inline
name|void
name|QSize
operator|::
name|scale
argument_list|(
argument|int w
argument_list|,
argument|int h
argument_list|,
argument|Qt::AspectRatioMode mode
argument_list|)
block|{
name|scale
argument_list|(
name|QSize
argument_list|(
name|w
argument_list|,
name|h
argument_list|)
argument_list|,
name|mode
argument_list|)
block|; }
DECL|function|rwidth
specifier|inline
name|int
operator|&
name|QSize
operator|::
name|rwidth
argument_list|()
block|{
return|return
name|wd
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|rheight
specifier|inline
name|int
operator|&
name|QSize
operator|::
name|rheight
argument_list|()
block|{
return|return
name|ht
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|member|operator
specifier|inline
name|QSize
operator|&
name|QSize
operator|::
name|operator
operator|+=
operator|(
specifier|const
name|QSize
operator|&
name|s
operator|)
block|{
name|wd
operator|+=
name|s
operator|.
name|wd
block|;
name|ht
operator|+=
name|s
operator|.
name|ht
block|;
return|return
operator|*
name|this
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
name|QSize
operator|&
name|QSize
operator|::
name|operator
operator|-=
operator|(
specifier|const
name|QSize
operator|&
name|s
operator|)
block|{
name|wd
operator|-=
name|s
operator|.
name|wd
block|;
name|ht
operator|-=
name|s
operator|.
name|ht
block|;
return|return
operator|*
name|this
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
name|QSize
operator|&
name|QSize
operator|::
name|operator
operator|*=
operator|(
name|qreal
name|c
operator|)
block|{
name|wd
operator|=
name|qRound
argument_list|(
name|wd
operator|*
name|c
argument_list|)
block|;
name|ht
operator|=
name|qRound
argument_list|(
name|ht
operator|*
name|c
argument_list|)
block|;
return|return
operator|*
name|this
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
name|bool
name|operator
operator|==
operator|(
specifier|const
name|QSize
operator|&
name|s1
operator|,
specifier|const
name|QSize
operator|&
name|s2
operator|)
block|{
return|return
name|s1
operator|.
name|wd
operator|==
name|s2
operator|.
name|wd
operator|&&
name|s1
operator|.
name|ht
operator|==
name|s2
operator|.
name|ht
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|QSize
operator|&
name|s1
operator|,
specifier|const
name|QSize
operator|&
name|s2
operator|)
block|{
return|return
name|s1
operator|.
name|wd
operator|!=
name|s2
operator|.
name|wd
operator|||
name|s1
operator|.
name|ht
operator|!=
name|s2
operator|.
name|ht
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
specifier|const
name|QSize
name|operator
operator|+
operator|(
specifier|const
name|QSize
operator|&
name|s1
operator|,
specifier|const
name|QSize
operator|&
name|s2
operator|)
block|{
return|return
name|QSize
argument_list|(
name|s1
operator|.
name|wd
operator|+
name|s2
operator|.
name|wd
argument_list|,
name|s1
operator|.
name|ht
operator|+
name|s2
operator|.
name|ht
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
specifier|const
name|QSize
name|operator
operator|-
operator|(
specifier|const
name|QSize
operator|&
name|s1
operator|,
specifier|const
name|QSize
operator|&
name|s2
operator|)
block|{
return|return
name|QSize
argument_list|(
name|s1
operator|.
name|wd
operator|-
name|s2
operator|.
name|wd
argument_list|,
name|s1
operator|.
name|ht
operator|-
name|s2
operator|.
name|ht
argument_list|)
return|;
block|}
end_expr_stmt
begin_function
specifier|inline
specifier|const
name|QSize
name|operator
modifier|*
parameter_list|(
specifier|const
name|QSize
modifier|&
name|s
parameter_list|,
name|qreal
name|c
parameter_list|)
block|{
return|return
name|QSize
argument_list|(
name|qRound
argument_list|(
name|s
operator|.
name|wd
operator|*
name|c
argument_list|)
argument_list|,
name|qRound
argument_list|(
name|s
operator|.
name|ht
operator|*
name|c
argument_list|)
argument_list|)
return|;
block|}
end_function
begin_function
specifier|inline
specifier|const
name|QSize
name|operator
modifier|*
parameter_list|(
name|qreal
name|c
parameter_list|,
specifier|const
name|QSize
modifier|&
name|s
parameter_list|)
block|{
return|return
name|QSize
argument_list|(
name|qRound
argument_list|(
name|s
operator|.
name|wd
operator|*
name|c
argument_list|)
argument_list|,
name|qRound
argument_list|(
name|s
operator|.
name|ht
operator|*
name|c
argument_list|)
argument_list|)
return|;
block|}
end_function
begin_expr_stmt
specifier|inline
name|QSize
operator|&
name|QSize
operator|::
name|operator
operator|/=
operator|(
name|qreal
name|c
operator|)
block|{
name|Q_ASSERT
argument_list|(
operator|!
name|qFuzzyIsNull
argument_list|(
name|c
argument_list|)
argument_list|)
block|;
name|wd
operator|=
name|qRound
argument_list|(
name|wd
operator|/
name|c
argument_list|)
block|;
name|ht
operator|=
name|qRound
argument_list|(
name|ht
operator|/
name|c
argument_list|)
block|;
return|return
operator|*
name|this
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
specifier|const
name|QSize
name|operator
operator|/
operator|(
specifier|const
name|QSize
operator|&
name|s
operator|,
name|qreal
name|c
operator|)
block|{
name|Q_ASSERT
argument_list|(
operator|!
name|qFuzzyIsNull
argument_list|(
name|c
argument_list|)
argument_list|)
block|;
return|return
name|QSize
argument_list|(
name|qRound
argument_list|(
name|s
operator|.
name|wd
operator|/
name|c
argument_list|)
argument_list|,
name|qRound
argument_list|(
name|s
operator|.
name|ht
operator|/
name|c
argument_list|)
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
name|QSize
name|QSize
operator|::
name|expandedTo
argument_list|(
argument|const QSize& otherSize
argument_list|)
specifier|const
block|{
return|return
name|QSize
argument_list|(
name|qMax
argument_list|(
name|wd
argument_list|,
name|otherSize
operator|.
name|wd
argument_list|)
argument_list|,
name|qMax
argument_list|(
name|ht
argument_list|,
name|otherSize
operator|.
name|ht
argument_list|)
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
name|QSize
name|QSize
operator|::
name|boundedTo
argument_list|(
argument|const QSize& otherSize
argument_list|)
specifier|const
block|{
return|return
name|QSize
argument_list|(
name|qMin
argument_list|(
name|wd
argument_list|,
name|otherSize
operator|.
name|wd
argument_list|)
argument_list|,
name|qMin
argument_list|(
name|ht
argument_list|,
name|otherSize
operator|.
name|ht
argument_list|)
argument_list|)
return|;
block|}
end_expr_stmt
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_DEBUG_STREAM
end_ifndef
begin_expr_stmt
name|Q_CORE_EXPORT
name|QDebug
name|operator
operator|<<
operator|(
name|QDebug
operator|,
specifier|const
name|QSize
operator|&
operator|)
expr_stmt|;
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_decl_stmt
name|class
name|Q_CORE_EXPORT
name|QSizeF
block|{
name|public
label|:
name|QSizeF
argument_list|()
expr_stmt|;
name|QSizeF
argument_list|(
specifier|const
name|QSize
operator|&
name|sz
argument_list|)
expr_stmt|;
name|QSizeF
argument_list|(
argument|qreal w
argument_list|,
argument|qreal h
argument_list|)
empty_stmt|;
name|bool
name|isNull
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|isEmpty
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|isValid
argument_list|()
specifier|const
expr_stmt|;
name|qreal
name|width
argument_list|()
specifier|const
expr_stmt|;
name|qreal
name|height
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setWidth
parameter_list|(
name|qreal
name|w
parameter_list|)
function_decl|;
name|void
name|setHeight
parameter_list|(
name|qreal
name|h
parameter_list|)
function_decl|;
name|void
name|transpose
parameter_list|()
function_decl|;
name|void
name|scale
argument_list|(
name|qreal
name|w
argument_list|,
name|qreal
name|h
argument_list|,
name|Qt
operator|::
name|AspectRatioMode
name|mode
argument_list|)
decl_stmt|;
name|void
name|scale
argument_list|(
specifier|const
name|QSizeF
operator|&
name|s
argument_list|,
name|Qt
operator|::
name|AspectRatioMode
name|mode
argument_list|)
decl_stmt|;
name|QSizeF
name|expandedTo
argument_list|(
specifier|const
name|QSizeF
operator|&
argument_list|)
decl|const
decl_stmt|;
name|QSizeF
name|boundedTo
argument_list|(
specifier|const
name|QSizeF
operator|&
argument_list|)
decl|const
decl_stmt|;
name|qreal
modifier|&
name|rwidth
parameter_list|()
function_decl|;
name|qreal
modifier|&
name|rheight
parameter_list|()
function_decl|;
name|QSizeF
operator|&
name|operator
operator|+=
operator|(
specifier|const
name|QSizeF
operator|&
operator|)
expr_stmt|;
name|QSizeF
operator|&
name|operator
operator|-=
operator|(
specifier|const
name|QSizeF
operator|&
operator|)
expr_stmt|;
name|QSizeF
operator|&
name|operator
operator|*=
operator|(
name|qreal
name|c
operator|)
expr_stmt|;
name|QSizeF
operator|&
name|operator
operator|/=
operator|(
name|qreal
name|c
operator|)
expr_stmt|;
name|friend
specifier|inline
name|bool
name|operator
operator|==
operator|(
specifier|const
name|QSizeF
operator|&
operator|,
specifier|const
name|QSizeF
operator|&
operator|)
expr_stmt|;
name|friend
specifier|inline
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|QSizeF
operator|&
operator|,
specifier|const
name|QSizeF
operator|&
operator|)
expr_stmt|;
name|friend
specifier|inline
specifier|const
name|QSizeF
name|operator
operator|+
operator|(
specifier|const
name|QSizeF
operator|&
operator|,
specifier|const
name|QSizeF
operator|&
operator|)
expr_stmt|;
name|friend
specifier|inline
specifier|const
name|QSizeF
name|operator
operator|-
operator|(
specifier|const
name|QSizeF
operator|&
operator|,
specifier|const
name|QSizeF
operator|&
operator|)
expr_stmt|;
name|friend
specifier|inline
specifier|const
name|QSizeF
name|operator
modifier|*
parameter_list|(
specifier|const
name|QSizeF
modifier|&
parameter_list|,
name|qreal
parameter_list|)
function_decl|;
name|friend
specifier|inline
specifier|const
name|QSizeF
name|operator
modifier|*
parameter_list|(
name|qreal
parameter_list|,
specifier|const
name|QSizeF
modifier|&
parameter_list|)
function_decl|;
name|friend
specifier|inline
specifier|const
name|QSizeF
name|operator
operator|/
operator|(
specifier|const
name|QSizeF
operator|&
operator|,
name|qreal
operator|)
expr_stmt|;
specifier|inline
name|QSize
name|toSize
argument_list|()
specifier|const
expr_stmt|;
name|private
label|:
name|qreal
name|wd
decl_stmt|;
name|qreal
name|ht
decl_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_expr_stmt
name|Q_DECLARE_TYPEINFO
argument_list|(
name|QSizeF
argument_list|,
name|Q_MOVABLE_TYPE
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|/*****************************************************************************   QSizeF stream functions  *****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_DATASTREAM
end_ifndef
begin_expr_stmt
name|Q_CORE_EXPORT
name|QDataStream
operator|&
name|operator
operator|<<
operator|(
name|QDataStream
operator|&
operator|,
specifier|const
name|QSizeF
operator|&
operator|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|Q_CORE_EXPORT
name|QDataStream
operator|&
name|operator
operator|>>
operator|(
name|QDataStream
operator|&
operator|,
name|QSizeF
operator|&
operator|)
expr_stmt|;
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/*****************************************************************************   QSizeF inline functions  *****************************************************************************/
end_comment
begin_expr_stmt
DECL|function|QSizeF
specifier|inline
name|QSizeF
operator|::
name|QSizeF
argument_list|()
block|{
name|wd
operator|=
name|ht
operator|=
operator|-
literal|1.
block|; }
DECL|function|QSizeF
specifier|inline
name|QSizeF
operator|::
name|QSizeF
argument_list|(
specifier|const
name|QSize
operator|&
name|sz
argument_list|)
operator|:
name|wd
argument_list|(
name|sz
operator|.
name|width
argument_list|()
argument_list|)
operator|,
name|ht
argument_list|(
argument|sz.height()
argument_list|)
block|{ }
DECL|function|QSizeF
specifier|inline
name|QSizeF
operator|::
name|QSizeF
argument_list|(
argument|qreal w
argument_list|,
argument|qreal h
argument_list|)
block|{
name|wd
operator|=
name|w
block|;
name|ht
operator|=
name|h
block|; }
DECL|function|isNull
specifier|inline
name|bool
name|QSizeF
operator|::
name|isNull
argument_list|()
specifier|const
block|{
return|return
name|qIsNull
argument_list|(
name|wd
argument_list|)
operator|&&
name|qIsNull
argument_list|(
name|ht
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|isEmpty
specifier|inline
name|bool
name|QSizeF
operator|::
name|isEmpty
argument_list|()
specifier|const
block|{
return|return
name|wd
operator|<=
literal|0.
operator|||
name|ht
operator|<=
literal|0.
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|isValid
specifier|inline
name|bool
name|QSizeF
operator|::
name|isValid
argument_list|()
specifier|const
block|{
return|return
name|wd
operator|>=
literal|0.
operator|&&
name|ht
operator|>=
literal|0.
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|width
specifier|inline
name|qreal
name|QSizeF
operator|::
name|width
argument_list|()
specifier|const
block|{
return|return
name|wd
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|height
specifier|inline
name|qreal
name|QSizeF
operator|::
name|height
argument_list|()
specifier|const
block|{
return|return
name|ht
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|setWidth
specifier|inline
name|void
name|QSizeF
operator|::
name|setWidth
argument_list|(
argument|qreal w
argument_list|)
block|{
name|wd
operator|=
name|w
block|; }
DECL|function|setHeight
specifier|inline
name|void
name|QSizeF
operator|::
name|setHeight
argument_list|(
argument|qreal h
argument_list|)
block|{
name|ht
operator|=
name|h
block|; }
DECL|function|scale
specifier|inline
name|void
name|QSizeF
operator|::
name|scale
argument_list|(
argument|qreal w
argument_list|,
argument|qreal h
argument_list|,
argument|Qt::AspectRatioMode mode
argument_list|)
block|{
name|scale
argument_list|(
name|QSizeF
argument_list|(
name|w
argument_list|,
name|h
argument_list|)
argument_list|,
name|mode
argument_list|)
block|; }
DECL|function|rwidth
specifier|inline
name|qreal
operator|&
name|QSizeF
operator|::
name|rwidth
argument_list|()
block|{
return|return
name|wd
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|rheight
specifier|inline
name|qreal
operator|&
name|QSizeF
operator|::
name|rheight
argument_list|()
block|{
return|return
name|ht
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|member|operator
specifier|inline
name|QSizeF
operator|&
name|QSizeF
operator|::
name|operator
operator|+=
operator|(
specifier|const
name|QSizeF
operator|&
name|s
operator|)
block|{
name|wd
operator|+=
name|s
operator|.
name|wd
block|;
name|ht
operator|+=
name|s
operator|.
name|ht
block|;
return|return
operator|*
name|this
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
name|QSizeF
operator|&
name|QSizeF
operator|::
name|operator
operator|-=
operator|(
specifier|const
name|QSizeF
operator|&
name|s
operator|)
block|{
name|wd
operator|-=
name|s
operator|.
name|wd
block|;
name|ht
operator|-=
name|s
operator|.
name|ht
block|;
return|return
operator|*
name|this
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
name|QSizeF
operator|&
name|QSizeF
operator|::
name|operator
operator|*=
operator|(
name|qreal
name|c
operator|)
block|{
name|wd
operator|*=
name|c
block|;
name|ht
operator|*=
name|c
block|;
return|return
operator|*
name|this
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
name|bool
name|operator
operator|==
operator|(
specifier|const
name|QSizeF
operator|&
name|s1
operator|,
specifier|const
name|QSizeF
operator|&
name|s2
operator|)
block|{
return|return
name|qFuzzyCompare
argument_list|(
name|s1
operator|.
name|wd
argument_list|,
name|s2
operator|.
name|wd
argument_list|)
operator|&&
name|qFuzzyCompare
argument_list|(
name|s1
operator|.
name|ht
argument_list|,
name|s2
operator|.
name|ht
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|QSizeF
operator|&
name|s1
operator|,
specifier|const
name|QSizeF
operator|&
name|s2
operator|)
block|{
return|return
operator|!
name|qFuzzyCompare
argument_list|(
name|s1
operator|.
name|wd
argument_list|,
name|s2
operator|.
name|wd
argument_list|)
operator|||
operator|!
name|qFuzzyCompare
argument_list|(
name|s1
operator|.
name|ht
argument_list|,
name|s2
operator|.
name|ht
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
specifier|const
name|QSizeF
name|operator
operator|+
operator|(
specifier|const
name|QSizeF
operator|&
name|s1
operator|,
specifier|const
name|QSizeF
operator|&
name|s2
operator|)
block|{
return|return
name|QSizeF
argument_list|(
name|s1
operator|.
name|wd
operator|+
name|s2
operator|.
name|wd
argument_list|,
name|s1
operator|.
name|ht
operator|+
name|s2
operator|.
name|ht
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
specifier|const
name|QSizeF
name|operator
operator|-
operator|(
specifier|const
name|QSizeF
operator|&
name|s1
operator|,
specifier|const
name|QSizeF
operator|&
name|s2
operator|)
block|{
return|return
name|QSizeF
argument_list|(
name|s1
operator|.
name|wd
operator|-
name|s2
operator|.
name|wd
argument_list|,
name|s1
operator|.
name|ht
operator|-
name|s2
operator|.
name|ht
argument_list|)
return|;
block|}
end_expr_stmt
begin_function
specifier|inline
specifier|const
name|QSizeF
name|operator
modifier|*
parameter_list|(
specifier|const
name|QSizeF
modifier|&
name|s
parameter_list|,
name|qreal
name|c
parameter_list|)
block|{
return|return
name|QSizeF
argument_list|(
name|s
operator|.
name|wd
operator|*
name|c
argument_list|,
name|s
operator|.
name|ht
operator|*
name|c
argument_list|)
return|;
block|}
end_function
begin_function
specifier|inline
specifier|const
name|QSizeF
name|operator
modifier|*
parameter_list|(
name|qreal
name|c
parameter_list|,
specifier|const
name|QSizeF
modifier|&
name|s
parameter_list|)
block|{
return|return
name|QSizeF
argument_list|(
name|s
operator|.
name|wd
operator|*
name|c
argument_list|,
name|s
operator|.
name|ht
operator|*
name|c
argument_list|)
return|;
block|}
end_function
begin_expr_stmt
specifier|inline
name|QSizeF
operator|&
name|QSizeF
operator|::
name|operator
operator|/=
operator|(
name|qreal
name|c
operator|)
block|{
name|Q_ASSERT
argument_list|(
operator|!
name|qFuzzyIsNull
argument_list|(
name|c
argument_list|)
argument_list|)
block|;
name|wd
operator|=
name|wd
operator|/
name|c
block|;
name|ht
operator|=
name|ht
operator|/
name|c
block|;
return|return
operator|*
name|this
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
specifier|const
name|QSizeF
name|operator
operator|/
operator|(
specifier|const
name|QSizeF
operator|&
name|s
operator|,
name|qreal
name|c
operator|)
block|{
name|Q_ASSERT
argument_list|(
operator|!
name|qFuzzyIsNull
argument_list|(
name|c
argument_list|)
argument_list|)
block|;
return|return
name|QSizeF
argument_list|(
name|s
operator|.
name|wd
operator|/
name|c
argument_list|,
name|s
operator|.
name|ht
operator|/
name|c
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
name|QSizeF
name|QSizeF
operator|::
name|expandedTo
argument_list|(
argument|const QSizeF& otherSize
argument_list|)
specifier|const
block|{
return|return
name|QSizeF
argument_list|(
name|qMax
argument_list|(
name|wd
argument_list|,
name|otherSize
operator|.
name|wd
argument_list|)
argument_list|,
name|qMax
argument_list|(
name|ht
argument_list|,
name|otherSize
operator|.
name|ht
argument_list|)
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
name|QSizeF
name|QSizeF
operator|::
name|boundedTo
argument_list|(
argument|const QSizeF& otherSize
argument_list|)
specifier|const
block|{
return|return
name|QSizeF
argument_list|(
name|qMin
argument_list|(
name|wd
argument_list|,
name|otherSize
operator|.
name|wd
argument_list|)
argument_list|,
name|qMin
argument_list|(
name|ht
argument_list|,
name|otherSize
operator|.
name|ht
argument_list|)
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
name|QSize
name|QSizeF
operator|::
name|toSize
argument_list|()
specifier|const
block|{
return|return
name|QSize
argument_list|(
name|qRound
argument_list|(
name|wd
argument_list|)
argument_list|,
name|qRound
argument_list|(
name|ht
argument_list|)
argument_list|)
return|;
block|}
end_expr_stmt
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_DEBUG_STREAM
end_ifndef
begin_expr_stmt
name|Q_CORE_EXPORT
name|QDebug
name|operator
operator|<<
operator|(
name|QDebug
operator|,
specifier|const
name|QSizeF
operator|&
operator|)
expr_stmt|;
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_expr_stmt
name|QT_END_NAMESPACE
name|QT_END_HEADER
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QSIZE_H
end_comment
end_unit
