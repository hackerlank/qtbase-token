begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QLINE_H
end_ifndef
begin_define
DECL|macro|QLINE_H
define|#
directive|define
name|QLINE_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qpoint.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
comment|/*******************************************************************************  * class QLine  *******************************************************************************/
name|class
name|Q_CORE_EXPORT
name|QLine
block|{
name|public
label|:
name|Q_DECL_CONSTEXPR
specifier|inline
name|QLine
parameter_list|()
function_decl|;
name|Q_DECL_CONSTEXPR
specifier|inline
name|QLine
parameter_list|(
specifier|const
name|QPoint
modifier|&
name|pt1
parameter_list|,
specifier|const
name|QPoint
modifier|&
name|pt2
parameter_list|)
function_decl|;
name|Q_DECL_CONSTEXPR
specifier|inline
name|QLine
parameter_list|(
name|int
name|x1
parameter_list|,
name|int
name|y1
parameter_list|,
name|int
name|x2
parameter_list|,
name|int
name|y2
parameter_list|)
function_decl|;
name|Q_DECL_CONSTEXPR
specifier|inline
name|bool
name|isNull
argument_list|()
specifier|const
expr_stmt|;
name|Q_DECL_CONSTEXPR
specifier|inline
name|QPoint
name|p1
argument_list|()
specifier|const
expr_stmt|;
name|Q_DECL_CONSTEXPR
specifier|inline
name|QPoint
name|p2
argument_list|()
specifier|const
expr_stmt|;
name|Q_DECL_CONSTEXPR
specifier|inline
name|int
name|x1
argument_list|()
specifier|const
expr_stmt|;
name|Q_DECL_CONSTEXPR
specifier|inline
name|int
name|y1
argument_list|()
specifier|const
expr_stmt|;
name|Q_DECL_CONSTEXPR
specifier|inline
name|int
name|x2
argument_list|()
specifier|const
expr_stmt|;
name|Q_DECL_CONSTEXPR
specifier|inline
name|int
name|y2
argument_list|()
specifier|const
expr_stmt|;
name|Q_DECL_CONSTEXPR
specifier|inline
name|int
name|dx
argument_list|()
specifier|const
expr_stmt|;
name|Q_DECL_CONSTEXPR
specifier|inline
name|int
name|dy
argument_list|()
specifier|const
expr_stmt|;
specifier|inline
name|void
name|translate
parameter_list|(
specifier|const
name|QPoint
modifier|&
name|p
parameter_list|)
function_decl|;
specifier|inline
name|void
name|translate
parameter_list|(
name|int
name|dx
parameter_list|,
name|int
name|dy
parameter_list|)
function_decl|;
name|Q_DECL_CONSTEXPR
specifier|inline
name|QLine
name|translated
argument_list|(
specifier|const
name|QPoint
operator|&
name|p
argument_list|)
decl|const
decl_stmt|;
name|Q_DECL_CONSTEXPR
specifier|inline
name|QLine
name|translated
argument_list|(
name|int
name|dx
argument_list|,
name|int
name|dy
argument_list|)
decl|const
decl_stmt|;
specifier|inline
name|void
name|setP1
parameter_list|(
specifier|const
name|QPoint
modifier|&
name|p1
parameter_list|)
function_decl|;
specifier|inline
name|void
name|setP2
parameter_list|(
specifier|const
name|QPoint
modifier|&
name|p2
parameter_list|)
function_decl|;
specifier|inline
name|void
name|setPoints
parameter_list|(
specifier|const
name|QPoint
modifier|&
name|p1
parameter_list|,
specifier|const
name|QPoint
modifier|&
name|p2
parameter_list|)
function_decl|;
specifier|inline
name|void
name|setLine
parameter_list|(
name|int
name|x1
parameter_list|,
name|int
name|y1
parameter_list|,
name|int
name|x2
parameter_list|,
name|int
name|y2
parameter_list|)
function_decl|;
name|Q_DECL_CONSTEXPR
specifier|inline
name|bool
name|operator
operator|==
operator|(
specifier|const
name|QLine
operator|&
name|d
operator|)
specifier|const
expr_stmt|;
name|Q_DECL_CONSTEXPR
specifier|inline
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|QLine
operator|&
name|d
operator|)
specifier|const
block|{
return|return
operator|!
operator|(
operator|*
name|this
operator|==
name|d
operator|)
return|;
block|}
name|private
label|:
name|QPoint
name|pt1
decl_stmt|,
name|pt2
decl_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_expr_stmt
name|Q_DECLARE_TYPEINFO
argument_list|(
name|QLine
argument_list|,
name|Q_MOVABLE_TYPE
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|/*******************************************************************************  * class QLine inline members  *******************************************************************************/
end_comment
begin_expr_stmt
DECL|function|QLine
name|Q_DECL_CONSTEXPR
specifier|inline
name|QLine
operator|::
name|QLine
argument_list|()
block|{ }
DECL|function|QLine
name|Q_DECL_CONSTEXPR
specifier|inline
name|QLine
operator|::
name|QLine
argument_list|(
specifier|const
name|QPoint
operator|&
name|pt1_
argument_list|,
specifier|const
name|QPoint
operator|&
name|pt2_
argument_list|)
operator|:
name|pt1
argument_list|(
name|pt1_
argument_list|)
operator|,
name|pt2
argument_list|(
argument|pt2_
argument_list|)
block|{ }
DECL|function|QLine
name|Q_DECL_CONSTEXPR
specifier|inline
name|QLine
operator|::
name|QLine
argument_list|(
argument|int x1pos
argument_list|,
argument|int y1pos
argument_list|,
argument|int x2pos
argument_list|,
argument|int y2pos
argument_list|)
operator|:
name|pt1
argument_list|(
name|QPoint
argument_list|(
name|x1pos
argument_list|,
name|y1pos
argument_list|)
argument_list|)
operator|,
name|pt2
argument_list|(
argument|QPoint(x2pos, y2pos)
argument_list|)
block|{ }
DECL|function|isNull
name|Q_DECL_CONSTEXPR
specifier|inline
name|bool
name|QLine
operator|::
name|isNull
argument_list|()
specifier|const
block|{
return|return
name|pt1
operator|==
name|pt2
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|x1
name|Q_DECL_CONSTEXPR
specifier|inline
name|int
name|QLine
operator|::
name|x1
argument_list|()
specifier|const
block|{
return|return
name|pt1
operator|.
name|x
argument_list|()
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|y1
name|Q_DECL_CONSTEXPR
specifier|inline
name|int
name|QLine
operator|::
name|y1
argument_list|()
specifier|const
block|{
return|return
name|pt1
operator|.
name|y
argument_list|()
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|x2
name|Q_DECL_CONSTEXPR
specifier|inline
name|int
name|QLine
operator|::
name|x2
argument_list|()
specifier|const
block|{
return|return
name|pt2
operator|.
name|x
argument_list|()
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|y2
name|Q_DECL_CONSTEXPR
specifier|inline
name|int
name|QLine
operator|::
name|y2
argument_list|()
specifier|const
block|{
return|return
name|pt2
operator|.
name|y
argument_list|()
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|p1
name|Q_DECL_CONSTEXPR
specifier|inline
name|QPoint
name|QLine
operator|::
name|p1
argument_list|()
specifier|const
block|{
return|return
name|pt1
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|p2
name|Q_DECL_CONSTEXPR
specifier|inline
name|QPoint
name|QLine
operator|::
name|p2
argument_list|()
specifier|const
block|{
return|return
name|pt2
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|dx
name|Q_DECL_CONSTEXPR
specifier|inline
name|int
name|QLine
operator|::
name|dx
argument_list|()
specifier|const
block|{
return|return
name|pt2
operator|.
name|x
argument_list|()
operator|-
name|pt1
operator|.
name|x
argument_list|()
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|dy
name|Q_DECL_CONSTEXPR
specifier|inline
name|int
name|QLine
operator|::
name|dy
argument_list|()
specifier|const
block|{
return|return
name|pt2
operator|.
name|y
argument_list|()
operator|-
name|pt1
operator|.
name|y
argument_list|()
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|translate
specifier|inline
name|void
name|QLine
operator|::
name|translate
argument_list|(
argument|const QPoint&point
argument_list|)
block|{
name|pt1
operator|+=
name|point
block|;
name|pt2
operator|+=
name|point
block|; }
DECL|function|translate
specifier|inline
name|void
name|QLine
operator|::
name|translate
argument_list|(
argument|int adx
argument_list|,
argument|int ady
argument_list|)
block|{
name|this
operator|->
name|translate
argument_list|(
name|QPoint
argument_list|(
name|adx
argument_list|,
name|ady
argument_list|)
argument_list|)
block|; }
DECL|function|translated
name|Q_DECL_CONSTEXPR
specifier|inline
name|QLine
name|QLine
operator|::
name|translated
argument_list|(
argument|const QPoint&p
argument_list|)
specifier|const
block|{
return|return
name|QLine
argument_list|(
name|pt1
operator|+
name|p
argument_list|,
name|pt2
operator|+
name|p
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|translated
name|Q_DECL_CONSTEXPR
specifier|inline
name|QLine
name|QLine
operator|::
name|translated
argument_list|(
argument|int adx
argument_list|,
argument|int ady
argument_list|)
specifier|const
block|{
return|return
name|translated
argument_list|(
name|QPoint
argument_list|(
name|adx
argument_list|,
name|ady
argument_list|)
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|setP1
specifier|inline
name|void
name|QLine
operator|::
name|setP1
argument_list|(
argument|const QPoint&aP1
argument_list|)
block|{
name|pt1
operator|=
name|aP1
block|; }
DECL|function|setP2
specifier|inline
name|void
name|QLine
operator|::
name|setP2
argument_list|(
argument|const QPoint&aP2
argument_list|)
block|{
name|pt2
operator|=
name|aP2
block|; }
DECL|function|setPoints
specifier|inline
name|void
name|QLine
operator|::
name|setPoints
argument_list|(
argument|const QPoint&aP1
argument_list|,
argument|const QPoint&aP2
argument_list|)
block|{
name|pt1
operator|=
name|aP1
block|;
name|pt2
operator|=
name|aP2
block|; }
DECL|function|setLine
specifier|inline
name|void
name|QLine
operator|::
name|setLine
argument_list|(
argument|int aX1
argument_list|,
argument|int aY1
argument_list|,
argument|int aX2
argument_list|,
argument|int aY2
argument_list|)
block|{
name|pt1
operator|=
name|QPoint
argument_list|(
name|aX1
argument_list|,
name|aY1
argument_list|)
block|;
name|pt2
operator|=
name|QPoint
argument_list|(
name|aX2
argument_list|,
name|aY2
argument_list|)
block|; }
DECL|function|operator
name|Q_DECL_CONSTEXPR
specifier|inline
name|bool
name|QLine
operator|::
name|operator
operator|==
operator|(
specifier|const
name|QLine
operator|&
name|d
operator|)
specifier|const
block|{
return|return
name|pt1
operator|==
name|d
operator|.
name|pt1
operator|&&
name|pt2
operator|==
name|d
operator|.
name|pt2
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
name|QLine
operator|&
name|p
operator|)
expr_stmt|;
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
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
name|QLine
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
name|QLine
operator|&
operator|)
expr_stmt|;
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/*******************************************************************************  * class QLineF  *******************************************************************************/
end_comment
begin_decl_stmt
name|class
name|Q_CORE_EXPORT
name|QLineF
block|{
name|public
label|:
enum|enum
name|IntersectType
block|{
name|NoIntersection
block|,
name|BoundedIntersection
block|,
name|UnboundedIntersection
block|}
enum|;
name|Q_DECL_CONSTEXPR
specifier|inline
name|QLineF
parameter_list|()
function_decl|;
name|Q_DECL_CONSTEXPR
specifier|inline
name|QLineF
parameter_list|(
specifier|const
name|QPointF
modifier|&
name|pt1
parameter_list|,
specifier|const
name|QPointF
modifier|&
name|pt2
parameter_list|)
function_decl|;
name|Q_DECL_CONSTEXPR
specifier|inline
name|QLineF
parameter_list|(
name|qreal
name|x1
parameter_list|,
name|qreal
name|y1
parameter_list|,
name|qreal
name|x2
parameter_list|,
name|qreal
name|y2
parameter_list|)
function_decl|;
name|Q_DECL_CONSTEXPR
specifier|inline
name|QLineF
argument_list|(
specifier|const
name|QLine
operator|&
name|line
argument_list|)
operator|:
name|pt1
argument_list|(
name|line
operator|.
name|p1
argument_list|()
argument_list|)
operator|,
name|pt2
argument_list|(
argument|line.p2()
argument_list|)
block|{ }
specifier|static
name|QLineF
name|fromPolar
argument_list|(
argument|qreal length
argument_list|,
argument|qreal angle
argument_list|)
expr_stmt|;
name|Q_DECL_CONSTEXPR
name|bool
name|isNull
argument_list|()
specifier|const
expr_stmt|;
name|Q_DECL_CONSTEXPR
specifier|inline
name|QPointF
name|p1
argument_list|()
specifier|const
expr_stmt|;
name|Q_DECL_CONSTEXPR
specifier|inline
name|QPointF
name|p2
argument_list|()
specifier|const
expr_stmt|;
name|Q_DECL_CONSTEXPR
specifier|inline
name|qreal
name|x1
argument_list|()
specifier|const
expr_stmt|;
name|Q_DECL_CONSTEXPR
specifier|inline
name|qreal
name|y1
argument_list|()
specifier|const
expr_stmt|;
name|Q_DECL_CONSTEXPR
specifier|inline
name|qreal
name|x2
argument_list|()
specifier|const
expr_stmt|;
name|Q_DECL_CONSTEXPR
specifier|inline
name|qreal
name|y2
argument_list|()
specifier|const
expr_stmt|;
name|Q_DECL_CONSTEXPR
specifier|inline
name|qreal
name|dx
argument_list|()
specifier|const
expr_stmt|;
name|Q_DECL_CONSTEXPR
specifier|inline
name|qreal
name|dy
argument_list|()
specifier|const
expr_stmt|;
name|qreal
name|length
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setLength
parameter_list|(
name|qreal
name|len
parameter_list|)
function_decl|;
name|qreal
name|angle
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setAngle
parameter_list|(
name|qreal
name|angle
parameter_list|)
function_decl|;
name|qreal
name|angleTo
argument_list|(
specifier|const
name|QLineF
operator|&
name|l
argument_list|)
decl|const
decl_stmt|;
name|QLineF
name|unitVector
argument_list|()
specifier|const
expr_stmt|;
name|Q_DECL_CONSTEXPR
specifier|inline
name|QLineF
name|normalVector
argument_list|()
specifier|const
expr_stmt|;
comment|// ### Qt 6: rename intersects() or intersection() and rename IntersectType IntersectionType
name|IntersectType
name|intersect
argument_list|(
specifier|const
name|QLineF
operator|&
name|l
argument_list|,
name|QPointF
operator|*
name|intersectionPoint
argument_list|)
decl|const
decl_stmt|;
name|qreal
name|angle
argument_list|(
specifier|const
name|QLineF
operator|&
name|l
argument_list|)
decl|const
decl_stmt|;
name|Q_DECL_CONSTEXPR
specifier|inline
name|QPointF
name|pointAt
argument_list|(
name|qreal
name|t
argument_list|)
decl|const
decl_stmt|;
specifier|inline
name|void
name|translate
parameter_list|(
specifier|const
name|QPointF
modifier|&
name|p
parameter_list|)
function_decl|;
specifier|inline
name|void
name|translate
parameter_list|(
name|qreal
name|dx
parameter_list|,
name|qreal
name|dy
parameter_list|)
function_decl|;
name|Q_DECL_CONSTEXPR
specifier|inline
name|QLineF
name|translated
argument_list|(
specifier|const
name|QPointF
operator|&
name|p
argument_list|)
decl|const
decl_stmt|;
name|Q_DECL_CONSTEXPR
specifier|inline
name|QLineF
name|translated
argument_list|(
name|qreal
name|dx
argument_list|,
name|qreal
name|dy
argument_list|)
decl|const
decl_stmt|;
specifier|inline
name|void
name|setP1
parameter_list|(
specifier|const
name|QPointF
modifier|&
name|p1
parameter_list|)
function_decl|;
specifier|inline
name|void
name|setP2
parameter_list|(
specifier|const
name|QPointF
modifier|&
name|p2
parameter_list|)
function_decl|;
specifier|inline
name|void
name|setPoints
parameter_list|(
specifier|const
name|QPointF
modifier|&
name|p1
parameter_list|,
specifier|const
name|QPointF
modifier|&
name|p2
parameter_list|)
function_decl|;
specifier|inline
name|void
name|setLine
parameter_list|(
name|qreal
name|x1
parameter_list|,
name|qreal
name|y1
parameter_list|,
name|qreal
name|x2
parameter_list|,
name|qreal
name|y2
parameter_list|)
function_decl|;
name|Q_DECL_CONSTEXPR
specifier|inline
name|bool
name|operator
operator|==
operator|(
specifier|const
name|QLineF
operator|&
name|d
operator|)
specifier|const
expr_stmt|;
name|Q_DECL_CONSTEXPR
specifier|inline
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|QLineF
operator|&
name|d
operator|)
specifier|const
block|{
return|return
operator|!
operator|(
operator|*
name|this
operator|==
name|d
operator|)
return|;
block|}
name|Q_DECL_CONSTEXPR
name|QLine
name|toLine
argument_list|()
specifier|const
expr_stmt|;
name|private
label|:
name|QPointF
name|pt1
decl_stmt|,
name|pt2
decl_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_expr_stmt
name|Q_DECLARE_TYPEINFO
argument_list|(
name|QLineF
argument_list|,
name|Q_MOVABLE_TYPE
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|/*******************************************************************************  * class QLineF inline members  *******************************************************************************/
end_comment
begin_expr_stmt
DECL|function|QLineF
name|Q_DECL_CONSTEXPR
specifier|inline
name|QLineF
operator|::
name|QLineF
argument_list|()
block|{ }
DECL|function|QLineF
name|Q_DECL_CONSTEXPR
specifier|inline
name|QLineF
operator|::
name|QLineF
argument_list|(
specifier|const
name|QPointF
operator|&
name|apt1
argument_list|,
specifier|const
name|QPointF
operator|&
name|apt2
argument_list|)
operator|:
name|pt1
argument_list|(
name|apt1
argument_list|)
operator|,
name|pt2
argument_list|(
argument|apt2
argument_list|)
block|{ }
DECL|function|QLineF
name|Q_DECL_CONSTEXPR
specifier|inline
name|QLineF
operator|::
name|QLineF
argument_list|(
argument|qreal x1pos
argument_list|,
argument|qreal y1pos
argument_list|,
argument|qreal x2pos
argument_list|,
argument|qreal y2pos
argument_list|)
operator|:
name|pt1
argument_list|(
name|x1pos
argument_list|,
name|y1pos
argument_list|)
operator|,
name|pt2
argument_list|(
argument|x2pos
argument_list|,
argument|y2pos
argument_list|)
block|{ }
DECL|function|x1
name|Q_DECL_CONSTEXPR
specifier|inline
name|qreal
name|QLineF
operator|::
name|x1
argument_list|()
specifier|const
block|{
return|return
name|pt1
operator|.
name|x
argument_list|()
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|y1
name|Q_DECL_CONSTEXPR
specifier|inline
name|qreal
name|QLineF
operator|::
name|y1
argument_list|()
specifier|const
block|{
return|return
name|pt1
operator|.
name|y
argument_list|()
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|x2
name|Q_DECL_CONSTEXPR
specifier|inline
name|qreal
name|QLineF
operator|::
name|x2
argument_list|()
specifier|const
block|{
return|return
name|pt2
operator|.
name|x
argument_list|()
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|y2
name|Q_DECL_CONSTEXPR
specifier|inline
name|qreal
name|QLineF
operator|::
name|y2
argument_list|()
specifier|const
block|{
return|return
name|pt2
operator|.
name|y
argument_list|()
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|isNull
name|Q_DECL_CONSTEXPR
specifier|inline
name|bool
name|QLineF
operator|::
name|isNull
argument_list|()
specifier|const
block|{
return|return
name|qFuzzyCompare
argument_list|(
name|pt1
operator|.
name|x
argument_list|()
argument_list|,
name|pt2
operator|.
name|x
argument_list|()
argument_list|)
operator|&&
name|qFuzzyCompare
argument_list|(
name|pt1
operator|.
name|y
argument_list|()
argument_list|,
name|pt2
operator|.
name|y
argument_list|()
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|p1
name|Q_DECL_CONSTEXPR
specifier|inline
name|QPointF
name|QLineF
operator|::
name|p1
argument_list|()
specifier|const
block|{
return|return
name|pt1
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|p2
name|Q_DECL_CONSTEXPR
specifier|inline
name|QPointF
name|QLineF
operator|::
name|p2
argument_list|()
specifier|const
block|{
return|return
name|pt2
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|dx
name|Q_DECL_CONSTEXPR
specifier|inline
name|qreal
name|QLineF
operator|::
name|dx
argument_list|()
specifier|const
block|{
return|return
name|pt2
operator|.
name|x
argument_list|()
operator|-
name|pt1
operator|.
name|x
argument_list|()
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|dy
name|Q_DECL_CONSTEXPR
specifier|inline
name|qreal
name|QLineF
operator|::
name|dy
argument_list|()
specifier|const
block|{
return|return
name|pt2
operator|.
name|y
argument_list|()
operator|-
name|pt1
operator|.
name|y
argument_list|()
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|normalVector
name|Q_DECL_CONSTEXPR
specifier|inline
name|QLineF
name|QLineF
operator|::
name|normalVector
argument_list|()
specifier|const
block|{
return|return
name|QLineF
argument_list|(
name|p1
argument_list|()
argument_list|,
name|p1
argument_list|()
operator|+
name|QPointF
argument_list|(
name|dy
argument_list|()
argument_list|,
operator|-
name|dx
argument_list|()
argument_list|)
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|translate
specifier|inline
name|void
name|QLineF
operator|::
name|translate
argument_list|(
argument|const QPointF&point
argument_list|)
block|{
name|pt1
operator|+=
name|point
block|;
name|pt2
operator|+=
name|point
block|; }
DECL|function|translate
specifier|inline
name|void
name|QLineF
operator|::
name|translate
argument_list|(
argument|qreal adx
argument_list|,
argument|qreal ady
argument_list|)
block|{
name|this
operator|->
name|translate
argument_list|(
name|QPointF
argument_list|(
name|adx
argument_list|,
name|ady
argument_list|)
argument_list|)
block|; }
DECL|function|translated
name|Q_DECL_CONSTEXPR
specifier|inline
name|QLineF
name|QLineF
operator|::
name|translated
argument_list|(
argument|const QPointF&p
argument_list|)
specifier|const
block|{
return|return
name|QLineF
argument_list|(
name|pt1
operator|+
name|p
argument_list|,
name|pt2
operator|+
name|p
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|translated
name|Q_DECL_CONSTEXPR
specifier|inline
name|QLineF
name|QLineF
operator|::
name|translated
argument_list|(
argument|qreal adx
argument_list|,
argument|qreal ady
argument_list|)
specifier|const
block|{
return|return
name|translated
argument_list|(
name|QPointF
argument_list|(
name|adx
argument_list|,
name|ady
argument_list|)
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|setLength
specifier|inline
name|void
name|QLineF
operator|::
name|setLength
argument_list|(
argument|qreal len
argument_list|)
block|{
if|if
condition|(
name|isNull
argument_list|()
condition|)
return|return;
name|QLineF
name|v
operator|=
name|unitVector
argument_list|()
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|pt2
operator|=
name|QPointF
argument_list|(
name|pt1
operator|.
name|x
argument_list|()
operator|+
name|v
operator|.
name|dx
argument_list|()
operator|*
name|len
argument_list|,
name|pt1
operator|.
name|y
argument_list|()
operator|+
name|v
operator|.
name|dy
argument_list|()
operator|*
name|len
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
unit|}  Q_DECL_CONSTEXPR
DECL|function|pointAt
specifier|inline
name|QPointF
name|QLineF
operator|::
name|pointAt
argument_list|(
argument|qreal t
argument_list|)
specifier|const
block|{
return|return
name|QPointF
argument_list|(
name|pt1
operator|.
name|x
argument_list|()
operator|+
operator|(
name|pt2
operator|.
name|x
argument_list|()
operator|-
name|pt1
operator|.
name|x
argument_list|()
operator|)
operator|*
name|t
argument_list|,
name|pt1
operator|.
name|y
argument_list|()
operator|+
operator|(
name|pt2
operator|.
name|y
argument_list|()
operator|-
name|pt1
operator|.
name|y
argument_list|()
operator|)
operator|*
name|t
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|toLine
name|Q_DECL_CONSTEXPR
specifier|inline
name|QLine
name|QLineF
operator|::
name|toLine
argument_list|()
specifier|const
block|{
return|return
name|QLine
argument_list|(
name|pt1
operator|.
name|toPoint
argument_list|()
argument_list|,
name|pt2
operator|.
name|toPoint
argument_list|()
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|setP1
specifier|inline
name|void
name|QLineF
operator|::
name|setP1
argument_list|(
argument|const QPointF&aP1
argument_list|)
block|{
name|pt1
operator|=
name|aP1
block|; }
DECL|function|setP2
specifier|inline
name|void
name|QLineF
operator|::
name|setP2
argument_list|(
argument|const QPointF&aP2
argument_list|)
block|{
name|pt2
operator|=
name|aP2
block|; }
DECL|function|setPoints
specifier|inline
name|void
name|QLineF
operator|::
name|setPoints
argument_list|(
argument|const QPointF&aP1
argument_list|,
argument|const QPointF&aP2
argument_list|)
block|{
name|pt1
operator|=
name|aP1
block|;
name|pt2
operator|=
name|aP2
block|; }
DECL|function|setLine
specifier|inline
name|void
name|QLineF
operator|::
name|setLine
argument_list|(
argument|qreal aX1
argument_list|,
argument|qreal aY1
argument_list|,
argument|qreal aX2
argument_list|,
argument|qreal aY2
argument_list|)
block|{
name|pt1
operator|=
name|QPointF
argument_list|(
name|aX1
argument_list|,
name|aY1
argument_list|)
block|;
name|pt2
operator|=
name|QPointF
argument_list|(
name|aX2
argument_list|,
name|aY2
argument_list|)
block|; }
DECL|function|operator
name|Q_DECL_CONSTEXPR
specifier|inline
name|bool
name|QLineF
operator|::
name|operator
operator|==
operator|(
specifier|const
name|QLineF
operator|&
name|d
operator|)
specifier|const
block|{
return|return
name|pt1
operator|==
name|d
operator|.
name|pt1
operator|&&
name|pt2
operator|==
name|d
operator|.
name|pt2
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
name|QLineF
operator|&
name|p
operator|)
expr_stmt|;
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
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
name|QLineF
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
name|QLineF
operator|&
operator|)
expr_stmt|;
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QLINE_H
end_comment
end_unit
