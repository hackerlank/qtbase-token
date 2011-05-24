begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QPOINT_H
end_ifndef
begin_define
DECL|macro|QPOINT_H
define|#
directive|define
name|QPOINT_H
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
name|QPoint
decl_stmt|{ public:     QPoint(
end_function
begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt
begin_macro
name|QPoint
argument_list|(
argument|int xpos
argument_list|,
argument|int ypos
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
name|int
name|x
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|int
name|y
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_function_decl
name|void
name|setX
parameter_list|(
name|int
name|x
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|setY
parameter_list|(
name|int
name|y
parameter_list|)
function_decl|;
end_function_decl
begin_expr_stmt
name|int
name|manhattanLength
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_function_decl
name|int
modifier|&
name|rx
parameter_list|()
function_decl|;
end_function_decl
begin_function_decl
name|int
modifier|&
name|ry
parameter_list|()
function_decl|;
end_function_decl
begin_expr_stmt
name|QPoint
operator|&
name|operator
operator|+=
operator|(
specifier|const
name|QPoint
operator|&
name|p
operator|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|QPoint
operator|&
name|operator
operator|-=
operator|(
specifier|const
name|QPoint
operator|&
name|p
operator|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|QPoint
operator|&
name|operator
operator|*=
operator|(
name|float
name|c
operator|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|QPoint
operator|&
name|operator
operator|*=
operator|(
name|double
name|c
operator|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|QPoint
operator|&
name|operator
operator|*=
operator|(
name|int
name|c
operator|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|QPoint
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
name|QPoint
operator|&
operator|,
specifier|const
name|QPoint
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
name|QPoint
operator|&
operator|,
specifier|const
name|QPoint
operator|&
operator|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|friend
specifier|inline
specifier|const
name|QPoint
name|operator
operator|+
operator|(
specifier|const
name|QPoint
operator|&
operator|,
specifier|const
name|QPoint
operator|&
operator|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|friend
specifier|inline
specifier|const
name|QPoint
name|operator
operator|-
operator|(
specifier|const
name|QPoint
operator|&
operator|,
specifier|const
name|QPoint
operator|&
operator|)
expr_stmt|;
end_expr_stmt
begin_function_decl
name|friend
specifier|inline
specifier|const
name|QPoint
name|operator
modifier|*
parameter_list|(
specifier|const
name|QPoint
modifier|&
parameter_list|,
name|float
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|friend
specifier|inline
specifier|const
name|QPoint
name|operator
modifier|*
parameter_list|(
name|float
parameter_list|,
specifier|const
name|QPoint
modifier|&
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|friend
specifier|inline
specifier|const
name|QPoint
name|operator
modifier|*
parameter_list|(
specifier|const
name|QPoint
modifier|&
parameter_list|,
name|double
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|friend
specifier|inline
specifier|const
name|QPoint
name|operator
modifier|*
parameter_list|(
name|double
parameter_list|,
specifier|const
name|QPoint
modifier|&
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|friend
specifier|inline
specifier|const
name|QPoint
name|operator
modifier|*
parameter_list|(
specifier|const
name|QPoint
modifier|&
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|friend
specifier|inline
specifier|const
name|QPoint
name|operator
modifier|*
parameter_list|(
name|int
parameter_list|,
specifier|const
name|QPoint
modifier|&
parameter_list|)
function_decl|;
end_function_decl
begin_expr_stmt
name|friend
specifier|inline
specifier|const
name|QPoint
name|operator
operator|-
operator|(
specifier|const
name|QPoint
operator|&
operator|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|friend
specifier|inline
specifier|const
name|QPoint
name|operator
operator|/
operator|(
specifier|const
name|QPoint
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
name|friend
name|class
name|QTransform
decl_stmt|;
end_decl_stmt
begin_comment
comment|// ### Qt 5;  remove the ifdef and just have the same order on all platforms.
end_comment
begin_if
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_MAC
argument_list|)
end_if
begin_decl_stmt
name|int
name|yp
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|int
name|xp
decl_stmt|;
end_decl_stmt
begin_else
else|#
directive|else
end_else
begin_decl_stmt
name|int
name|xp
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|int
name|yp
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_expr_stmt
unit|};
name|Q_DECLARE_TYPEINFO
argument_list|(
name|QPoint
argument_list|,
name|Q_MOVABLE_TYPE
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|/*****************************************************************************   QPoint stream functions  *****************************************************************************/
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
name|QPoint
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
name|QPoint
operator|&
operator|)
expr_stmt|;
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/*****************************************************************************   QPoint inline functions  *****************************************************************************/
end_comment
begin_expr_stmt
DECL|function|QPoint
specifier|inline
name|QPoint
operator|::
name|QPoint
argument_list|()
block|{
name|xp
operator|=
literal|0
block|;
name|yp
operator|=
literal|0
block|; }
DECL|function|QPoint
specifier|inline
name|QPoint
operator|::
name|QPoint
argument_list|(
argument|int xpos
argument_list|,
argument|int ypos
argument_list|)
block|{
name|xp
operator|=
name|xpos
block|;
name|yp
operator|=
name|ypos
block|; }
DECL|function|isNull
specifier|inline
name|bool
name|QPoint
operator|::
name|isNull
argument_list|()
specifier|const
block|{
return|return
name|xp
operator|==
literal|0
operator|&&
name|yp
operator|==
literal|0
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|x
specifier|inline
name|int
name|QPoint
operator|::
name|x
argument_list|()
specifier|const
block|{
return|return
name|xp
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|y
specifier|inline
name|int
name|QPoint
operator|::
name|y
argument_list|()
specifier|const
block|{
return|return
name|yp
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|setX
specifier|inline
name|void
name|QPoint
operator|::
name|setX
argument_list|(
argument|int xpos
argument_list|)
block|{
name|xp
operator|=
name|xpos
block|; }
DECL|function|setY
specifier|inline
name|void
name|QPoint
operator|::
name|setY
argument_list|(
argument|int ypos
argument_list|)
block|{
name|yp
operator|=
name|ypos
block|; }
DECL|function|rx
specifier|inline
name|int
operator|&
name|QPoint
operator|::
name|rx
argument_list|()
block|{
return|return
name|xp
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|ry
specifier|inline
name|int
operator|&
name|QPoint
operator|::
name|ry
argument_list|()
block|{
return|return
name|yp
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|member|operator
specifier|inline
name|QPoint
operator|&
name|QPoint
operator|::
name|operator
operator|+=
operator|(
specifier|const
name|QPoint
operator|&
name|p
operator|)
block|{
name|xp
operator|+=
name|p
operator|.
name|xp
block|;
name|yp
operator|+=
name|p
operator|.
name|yp
block|;
return|return
operator|*
name|this
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
name|QPoint
operator|&
name|QPoint
operator|::
name|operator
operator|-=
operator|(
specifier|const
name|QPoint
operator|&
name|p
operator|)
block|{
name|xp
operator|-=
name|p
operator|.
name|xp
block|;
name|yp
operator|-=
name|p
operator|.
name|yp
block|;
return|return
operator|*
name|this
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
name|QPoint
operator|&
name|QPoint
operator|::
name|operator
operator|*=
operator|(
name|float
name|c
operator|)
block|{
name|xp
operator|=
name|qRound
argument_list|(
name|xp
operator|*
name|c
argument_list|)
block|;
name|yp
operator|=
name|qRound
argument_list|(
name|yp
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
name|QPoint
operator|&
name|QPoint
operator|::
name|operator
operator|*=
operator|(
name|double
name|c
operator|)
block|{
name|xp
operator|=
name|qRound
argument_list|(
name|xp
operator|*
name|c
argument_list|)
block|;
name|yp
operator|=
name|qRound
argument_list|(
name|yp
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
name|QPoint
operator|&
name|QPoint
operator|::
name|operator
operator|*=
operator|(
name|int
name|c
operator|)
block|{
name|xp
operator|=
name|xp
operator|*
name|c
block|;
name|yp
operator|=
name|yp
operator|*
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
name|QPoint
operator|&
name|p1
operator|,
specifier|const
name|QPoint
operator|&
name|p2
operator|)
block|{
return|return
name|p1
operator|.
name|xp
operator|==
name|p2
operator|.
name|xp
operator|&&
name|p1
operator|.
name|yp
operator|==
name|p2
operator|.
name|yp
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
name|QPoint
operator|&
name|p1
operator|,
specifier|const
name|QPoint
operator|&
name|p2
operator|)
block|{
return|return
name|p1
operator|.
name|xp
operator|!=
name|p2
operator|.
name|xp
operator|||
name|p1
operator|.
name|yp
operator|!=
name|p2
operator|.
name|yp
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
specifier|const
name|QPoint
name|operator
operator|+
operator|(
specifier|const
name|QPoint
operator|&
name|p1
operator|,
specifier|const
name|QPoint
operator|&
name|p2
operator|)
block|{
return|return
name|QPoint
argument_list|(
name|p1
operator|.
name|xp
operator|+
name|p2
operator|.
name|xp
argument_list|,
name|p1
operator|.
name|yp
operator|+
name|p2
operator|.
name|yp
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
specifier|const
name|QPoint
name|operator
operator|-
operator|(
specifier|const
name|QPoint
operator|&
name|p1
operator|,
specifier|const
name|QPoint
operator|&
name|p2
operator|)
block|{
return|return
name|QPoint
argument_list|(
name|p1
operator|.
name|xp
operator|-
name|p2
operator|.
name|xp
argument_list|,
name|p1
operator|.
name|yp
operator|-
name|p2
operator|.
name|yp
argument_list|)
return|;
block|}
end_expr_stmt
begin_function
specifier|inline
specifier|const
name|QPoint
name|operator
modifier|*
parameter_list|(
specifier|const
name|QPoint
modifier|&
name|p
parameter_list|,
name|float
name|c
parameter_list|)
block|{
return|return
name|QPoint
argument_list|(
name|qRound
argument_list|(
name|p
operator|.
name|xp
operator|*
name|c
argument_list|)
argument_list|,
name|qRound
argument_list|(
name|p
operator|.
name|yp
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
name|QPoint
name|operator
modifier|*
parameter_list|(
specifier|const
name|QPoint
modifier|&
name|p
parameter_list|,
name|double
name|c
parameter_list|)
block|{
return|return
name|QPoint
argument_list|(
name|qRound
argument_list|(
name|p
operator|.
name|xp
operator|*
name|c
argument_list|)
argument_list|,
name|qRound
argument_list|(
name|p
operator|.
name|yp
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
name|QPoint
name|operator
modifier|*
parameter_list|(
specifier|const
name|QPoint
modifier|&
name|p
parameter_list|,
name|int
name|c
parameter_list|)
block|{
return|return
name|QPoint
argument_list|(
name|p
operator|.
name|xp
operator|*
name|c
argument_list|,
name|p
operator|.
name|yp
operator|*
name|c
argument_list|)
return|;
block|}
end_function
begin_function
specifier|inline
specifier|const
name|QPoint
name|operator
modifier|*
parameter_list|(
name|float
name|c
parameter_list|,
specifier|const
name|QPoint
modifier|&
name|p
parameter_list|)
block|{
return|return
name|QPoint
argument_list|(
name|qRound
argument_list|(
name|p
operator|.
name|xp
operator|*
name|c
argument_list|)
argument_list|,
name|qRound
argument_list|(
name|p
operator|.
name|yp
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
name|QPoint
name|operator
modifier|*
parameter_list|(
name|double
name|c
parameter_list|,
specifier|const
name|QPoint
modifier|&
name|p
parameter_list|)
block|{
return|return
name|QPoint
argument_list|(
name|qRound
argument_list|(
name|p
operator|.
name|xp
operator|*
name|c
argument_list|)
argument_list|,
name|qRound
argument_list|(
name|p
operator|.
name|yp
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
name|QPoint
name|operator
modifier|*
parameter_list|(
name|int
name|c
parameter_list|,
specifier|const
name|QPoint
modifier|&
name|p
parameter_list|)
block|{
return|return
name|QPoint
argument_list|(
name|p
operator|.
name|xp
operator|*
name|c
argument_list|,
name|p
operator|.
name|yp
operator|*
name|c
argument_list|)
return|;
block|}
end_function
begin_expr_stmt
specifier|inline
specifier|const
name|QPoint
name|operator
operator|-
operator|(
specifier|const
name|QPoint
operator|&
name|p
operator|)
block|{
return|return
name|QPoint
argument_list|(
operator|-
name|p
operator|.
name|xp
argument_list|,
operator|-
name|p
operator|.
name|yp
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
name|QPoint
operator|&
name|QPoint
operator|::
name|operator
operator|/=
operator|(
name|qreal
name|c
operator|)
block|{
name|xp
operator|=
name|qRound
argument_list|(
name|xp
operator|/
name|c
argument_list|)
block|;
name|yp
operator|=
name|qRound
argument_list|(
name|yp
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
name|QPoint
name|operator
operator|/
operator|(
specifier|const
name|QPoint
operator|&
name|p
operator|,
name|qreal
name|c
operator|)
block|{
return|return
name|QPoint
argument_list|(
name|qRound
argument_list|(
name|p
operator|.
name|xp
operator|/
name|c
argument_list|)
argument_list|,
name|qRound
argument_list|(
name|p
operator|.
name|yp
operator|/
name|c
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
name|QPoint
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
name|QPointF
block|{
name|public
label|:
name|QPointF
argument_list|()
expr_stmt|;
name|QPointF
argument_list|(
specifier|const
name|QPoint
operator|&
name|p
argument_list|)
expr_stmt|;
name|QPointF
argument_list|(
argument|qreal xpos
argument_list|,
argument|qreal ypos
argument_list|)
empty_stmt|;
name|qreal
name|manhattanLength
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|isNull
argument_list|()
specifier|const
expr_stmt|;
name|qreal
name|x
argument_list|()
specifier|const
expr_stmt|;
name|qreal
name|y
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setX
parameter_list|(
name|qreal
name|x
parameter_list|)
function_decl|;
name|void
name|setY
parameter_list|(
name|qreal
name|y
parameter_list|)
function_decl|;
name|qreal
modifier|&
name|rx
parameter_list|()
function_decl|;
name|qreal
modifier|&
name|ry
parameter_list|()
function_decl|;
name|QPointF
operator|&
name|operator
operator|+=
operator|(
specifier|const
name|QPointF
operator|&
name|p
operator|)
expr_stmt|;
name|QPointF
operator|&
name|operator
operator|-=
operator|(
specifier|const
name|QPointF
operator|&
name|p
operator|)
expr_stmt|;
name|QPointF
operator|&
name|operator
operator|*=
operator|(
name|qreal
name|c
operator|)
expr_stmt|;
name|QPointF
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
name|QPointF
operator|&
operator|,
specifier|const
name|QPointF
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
name|QPointF
operator|&
operator|,
specifier|const
name|QPointF
operator|&
operator|)
expr_stmt|;
name|friend
specifier|inline
specifier|const
name|QPointF
name|operator
operator|+
operator|(
specifier|const
name|QPointF
operator|&
operator|,
specifier|const
name|QPointF
operator|&
operator|)
expr_stmt|;
name|friend
specifier|inline
specifier|const
name|QPointF
name|operator
operator|-
operator|(
specifier|const
name|QPointF
operator|&
operator|,
specifier|const
name|QPointF
operator|&
operator|)
expr_stmt|;
name|friend
specifier|inline
specifier|const
name|QPointF
name|operator
modifier|*
parameter_list|(
name|qreal
parameter_list|,
specifier|const
name|QPointF
modifier|&
parameter_list|)
function_decl|;
name|friend
specifier|inline
specifier|const
name|QPointF
name|operator
modifier|*
parameter_list|(
specifier|const
name|QPointF
modifier|&
parameter_list|,
name|qreal
parameter_list|)
function_decl|;
name|friend
specifier|inline
specifier|const
name|QPointF
name|operator
operator|-
operator|(
specifier|const
name|QPointF
operator|&
operator|)
expr_stmt|;
name|friend
specifier|inline
specifier|const
name|QPointF
name|operator
operator|/
operator|(
specifier|const
name|QPointF
operator|&
operator|,
name|qreal
operator|)
expr_stmt|;
name|QPoint
name|toPoint
argument_list|()
specifier|const
expr_stmt|;
name|private
label|:
name|friend
name|class
name|QMatrix
decl_stmt|;
name|friend
name|class
name|QTransform
decl_stmt|;
name|qreal
name|xp
decl_stmt|;
name|qreal
name|yp
decl_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_expr_stmt
name|Q_DECLARE_TYPEINFO
argument_list|(
name|QPointF
argument_list|,
name|Q_MOVABLE_TYPE
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|/*****************************************************************************   QPointF stream functions  *****************************************************************************/
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
name|QPointF
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
name|QPointF
operator|&
operator|)
expr_stmt|;
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/*****************************************************************************   QPointF inline functions  *****************************************************************************/
end_comment
begin_expr_stmt
DECL|function|QPointF
specifier|inline
name|QPointF
operator|::
name|QPointF
argument_list|()
operator|:
name|xp
argument_list|(
literal|0
argument_list|)
operator|,
name|yp
argument_list|(
literal|0
argument_list|)
block|{ }
DECL|function|QPointF
specifier|inline
name|QPointF
operator|::
name|QPointF
argument_list|(
argument|qreal xpos
argument_list|,
argument|qreal ypos
argument_list|)
operator|:
name|xp
argument_list|(
name|xpos
argument_list|)
operator|,
name|yp
argument_list|(
argument|ypos
argument_list|)
block|{ }
DECL|function|QPointF
specifier|inline
name|QPointF
operator|::
name|QPointF
argument_list|(
specifier|const
name|QPoint
operator|&
name|p
argument_list|)
operator|:
name|xp
argument_list|(
name|p
operator|.
name|x
argument_list|()
argument_list|)
operator|,
name|yp
argument_list|(
argument|p.y()
argument_list|)
block|{ }
DECL|function|isNull
specifier|inline
name|bool
name|QPointF
operator|::
name|isNull
argument_list|()
specifier|const
block|{
return|return
name|qIsNull
argument_list|(
name|xp
argument_list|)
operator|&&
name|qIsNull
argument_list|(
name|yp
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|x
specifier|inline
name|qreal
name|QPointF
operator|::
name|x
argument_list|()
specifier|const
block|{
return|return
name|xp
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|y
specifier|inline
name|qreal
name|QPointF
operator|::
name|y
argument_list|()
specifier|const
block|{
return|return
name|yp
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|setX
specifier|inline
name|void
name|QPointF
operator|::
name|setX
argument_list|(
argument|qreal xpos
argument_list|)
block|{
name|xp
operator|=
name|xpos
block|; }
DECL|function|setY
specifier|inline
name|void
name|QPointF
operator|::
name|setY
argument_list|(
argument|qreal ypos
argument_list|)
block|{
name|yp
operator|=
name|ypos
block|; }
DECL|function|rx
specifier|inline
name|qreal
operator|&
name|QPointF
operator|::
name|rx
argument_list|()
block|{
return|return
name|xp
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|ry
specifier|inline
name|qreal
operator|&
name|QPointF
operator|::
name|ry
argument_list|()
block|{
return|return
name|yp
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|member|operator
specifier|inline
name|QPointF
operator|&
name|QPointF
operator|::
name|operator
operator|+=
operator|(
specifier|const
name|QPointF
operator|&
name|p
operator|)
block|{
name|xp
operator|+=
name|p
operator|.
name|xp
block|;
name|yp
operator|+=
name|p
operator|.
name|yp
block|;
return|return
operator|*
name|this
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
name|QPointF
operator|&
name|QPointF
operator|::
name|operator
operator|-=
operator|(
specifier|const
name|QPointF
operator|&
name|p
operator|)
block|{
name|xp
operator|-=
name|p
operator|.
name|xp
block|;
name|yp
operator|-=
name|p
operator|.
name|yp
block|;
return|return
operator|*
name|this
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
name|QPointF
operator|&
name|QPointF
operator|::
name|operator
operator|*=
operator|(
name|qreal
name|c
operator|)
block|{
name|xp
operator|*=
name|c
block|;
name|yp
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
name|QPointF
operator|&
name|p1
operator|,
specifier|const
name|QPointF
operator|&
name|p2
operator|)
block|{
return|return
name|qFuzzyIsNull
argument_list|(
name|p1
operator|.
name|xp
operator|-
name|p2
operator|.
name|xp
argument_list|)
operator|&&
name|qFuzzyIsNull
argument_list|(
name|p1
operator|.
name|yp
operator|-
name|p2
operator|.
name|yp
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
name|QPointF
operator|&
name|p1
operator|,
specifier|const
name|QPointF
operator|&
name|p2
operator|)
block|{
return|return
operator|!
name|qFuzzyIsNull
argument_list|(
name|p1
operator|.
name|xp
operator|-
name|p2
operator|.
name|xp
argument_list|)
operator|||
operator|!
name|qFuzzyIsNull
argument_list|(
name|p1
operator|.
name|yp
operator|-
name|p2
operator|.
name|yp
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
specifier|const
name|QPointF
name|operator
operator|+
operator|(
specifier|const
name|QPointF
operator|&
name|p1
operator|,
specifier|const
name|QPointF
operator|&
name|p2
operator|)
block|{
return|return
name|QPointF
argument_list|(
name|p1
operator|.
name|xp
operator|+
name|p2
operator|.
name|xp
argument_list|,
name|p1
operator|.
name|yp
operator|+
name|p2
operator|.
name|yp
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
specifier|const
name|QPointF
name|operator
operator|-
operator|(
specifier|const
name|QPointF
operator|&
name|p1
operator|,
specifier|const
name|QPointF
operator|&
name|p2
operator|)
block|{
return|return
name|QPointF
argument_list|(
name|p1
operator|.
name|xp
operator|-
name|p2
operator|.
name|xp
argument_list|,
name|p1
operator|.
name|yp
operator|-
name|p2
operator|.
name|yp
argument_list|)
return|;
block|}
end_expr_stmt
begin_function
specifier|inline
specifier|const
name|QPointF
name|operator
modifier|*
parameter_list|(
specifier|const
name|QPointF
modifier|&
name|p
parameter_list|,
name|qreal
name|c
parameter_list|)
block|{
return|return
name|QPointF
argument_list|(
name|p
operator|.
name|xp
operator|*
name|c
argument_list|,
name|p
operator|.
name|yp
operator|*
name|c
argument_list|)
return|;
block|}
end_function
begin_function
specifier|inline
specifier|const
name|QPointF
name|operator
modifier|*
parameter_list|(
name|qreal
name|c
parameter_list|,
specifier|const
name|QPointF
modifier|&
name|p
parameter_list|)
block|{
return|return
name|QPointF
argument_list|(
name|p
operator|.
name|xp
operator|*
name|c
argument_list|,
name|p
operator|.
name|yp
operator|*
name|c
argument_list|)
return|;
block|}
end_function
begin_expr_stmt
specifier|inline
specifier|const
name|QPointF
name|operator
operator|-
operator|(
specifier|const
name|QPointF
operator|&
name|p
operator|)
block|{
return|return
name|QPointF
argument_list|(
operator|-
name|p
operator|.
name|xp
argument_list|,
operator|-
name|p
operator|.
name|yp
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
name|QPointF
operator|&
name|QPointF
operator|::
name|operator
operator|/=
operator|(
name|qreal
name|c
operator|)
block|{
name|xp
operator|/=
name|c
block|;
name|yp
operator|/=
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
name|QPointF
name|operator
operator|/
operator|(
specifier|const
name|QPointF
operator|&
name|p
operator|,
name|qreal
name|c
operator|)
block|{
return|return
name|QPointF
argument_list|(
name|p
operator|.
name|xp
operator|/
name|c
argument_list|,
name|p
operator|.
name|yp
operator|/
name|c
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
name|QPoint
name|QPointF
operator|::
name|toPoint
argument_list|()
specifier|const
block|{
return|return
name|QPoint
argument_list|(
name|qRound
argument_list|(
name|xp
argument_list|)
argument_list|,
name|qRound
argument_list|(
name|yp
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
name|d
operator|,
specifier|const
name|QPointF
operator|&
name|p
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
comment|// QPOINT_H
end_comment
end_unit
