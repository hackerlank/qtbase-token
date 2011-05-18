begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** No Commercial Usage ** This file contains pre-release code and may not be distributed. ** You may use this file in accordance with the terms and conditions ** contained in the Technology Preview License Agreement accompanying ** this package. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights.  These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** If you have questions regarding the use of this file, please contact ** Nokia at qt-info@nokia.com. ** ** ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"oldtessellator.h"
end_include
begin_include
include|#
directive|include
file|<QPointF>
end_include
begin_include
include|#
directive|include
file|<QVector>
end_include
begin_include
include|#
directive|include
file|<QList>
end_include
begin_include
include|#
directive|include
file|<QVariant>
end_include
begin_include
include|#
directive|include
file|<QVarLengthArray>
end_include
begin_include
include|#
directive|include
file|<qdebug.h>
end_include
begin_include
include|#
directive|include
file|"limits.h"
end_include
begin_include
include|#
directive|include
file|"utils.h"
end_include
begin_include
include|#
directive|include
file|"qnum.h"
end_include
begin_include
include|#
directive|include
file|"XrenderFake.h"
end_include
begin_comment
comment|/*  * Polygon tesselator - can probably be optimized a bit more  */
end_comment
begin_comment
comment|//#define QT_DEBUG_TESSELATOR
end_comment
begin_define
DECL|macro|FloatToXFixed
define|#
directive|define
name|FloatToXFixed
parameter_list|(
name|i
parameter_list|)
value|(int)((i) * 65536)
end_define
begin_define
DECL|macro|IntToXFixed
define|#
directive|define
name|IntToXFixed
parameter_list|(
name|i
parameter_list|)
value|((i)<< 16)
end_define
begin_comment
comment|//inline int qrealToXFixed(qreal f)
end_comment
begin_comment
comment|//{ return f<< 8; }
end_comment
begin_struct
DECL|struct|QEdge
struct|struct
name|QEdge
block|{
DECL|function|QEdge
specifier|inline
name|QEdge
parameter_list|()
block|{}
DECL|function|QEdge
specifier|inline
name|QEdge
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
block|{
name|p1
operator|.
name|x
operator|=
name|XDoubleToFixed
argument_list|(
name|pt1
operator|.
name|x
argument_list|()
argument_list|)
expr_stmt|;
name|p1
operator|.
name|y
operator|=
name|XDoubleToFixed
argument_list|(
name|pt1
operator|.
name|y
argument_list|()
argument_list|)
expr_stmt|;
name|p2
operator|.
name|x
operator|=
name|XDoubleToFixed
argument_list|(
name|pt2
operator|.
name|x
argument_list|()
argument_list|)
expr_stmt|;
name|p2
operator|.
name|y
operator|=
name|XDoubleToFixed
argument_list|(
name|pt2
operator|.
name|y
argument_list|()
argument_list|)
expr_stmt|;
name|m
operator|=
operator|(
name|pt1
operator|.
name|x
argument_list|()
operator|-
name|pt2
operator|.
name|x
argument_list|()
operator|)
condition|?
operator|(
name|pt1
operator|.
name|y
argument_list|()
operator|-
name|pt2
operator|.
name|y
argument_list|()
operator|)
operator|/
operator|(
name|pt1
operator|.
name|x
argument_list|()
operator|-
name|pt2
operator|.
name|x
argument_list|()
operator|)
else|:
literal|0
expr_stmt|;
name|im
operator|=
name|m
condition|?
literal|1
operator|/
name|m
else|:
literal|0
expr_stmt|;
name|b
operator|=
name|pt1
operator|.
name|y
argument_list|()
operator|-
name|m
operator|*
name|pt1
operator|.
name|x
argument_list|()
expr_stmt|;
name|vertical
operator|=
name|p1
operator|.
name|x
operator|==
name|p2
operator|.
name|x
expr_stmt|;
name|horizontal
operator|=
name|p1
operator|.
name|y
operator|==
name|p2
operator|.
name|y
expr_stmt|;
block|}
DECL|member|pf1
DECL|member|pf2
name|QPointF
name|pf1
decl_stmt|,
name|pf2
decl_stmt|;
DECL|member|p1
DECL|member|p2
name|XPointFixed
name|p1
decl_stmt|,
name|p2
decl_stmt|;
DECL|member|m
name|qreal
name|m
decl_stmt|;
DECL|member|im
name|qreal
name|im
decl_stmt|;
DECL|member|b
name|qreal
name|b
decl_stmt|;
DECL|member|intersection
name|qreal
name|intersection
decl_stmt|;
DECL|member|winding
name|signed
name|short
name|winding
decl_stmt|;
DECL|member|vertical
name|bool
name|vertical
decl_stmt|;
DECL|member|horizontal
name|bool
name|horizontal
decl_stmt|;
block|}
struct|;
end_struct
begin_struct
DECL|struct|QVrtx
struct|struct
name|QVrtx
block|{
DECL|typedef|Edges
typedef|typedef
name|QList
argument_list|<
name|QEdge
argument_list|>
name|Edges
typedef|;
DECL|member|coords
name|XPointFixed
name|coords
decl_stmt|;
DECL|member|startingEdges
name|Edges
name|startingEdges
decl_stmt|;
DECL|member|endingEdges
name|Edges
name|endingEdges
decl_stmt|;
DECL|member|intersectingEdges
name|Edges
name|intersectingEdges
decl_stmt|;
block|}
struct|;
end_struct
begin_struct
DECL|struct|QIntersectionPoint
struct|struct
name|QIntersectionPoint
block|{
DECL|member|x
name|qreal
name|x
decl_stmt|;
DECL|member|edge
specifier|const
name|QEdge
modifier|*
name|edge
decl_stmt|;
block|}
struct|;
end_struct
begin_function_decl
name|QT_BEGIN_NAMESPACE
name|Q_DECLARE_TYPEINFO
parameter_list|(
name|QEdge
parameter_list|,
name|Q_PRIMITIVE_TYPE
parameter_list|)
function_decl|;
end_function_decl
begin_expr_stmt
name|Q_DECLARE_TYPEINFO
argument_list|(
name|QVrtx
argument_list|,
name|Q_PRIMITIVE_TYPE
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|Q_DECLARE_TYPEINFO
argument_list|(
name|QIntersectionPoint
argument_list|,
name|Q_PRIMITIVE_TYPE
argument_list|)
expr_stmt|;
end_expr_stmt
begin_decl_stmt
name|QT_END_NAMESPACE
comment|// used by the edge point sort algorithm
DECL|variable|currentY
specifier|static
name|qreal
name|currentY
init|=
literal|0.f
decl_stmt|;
end_decl_stmt
begin_function
DECL|function|compareEdges
specifier|static
specifier|inline
name|bool
name|compareEdges
parameter_list|(
specifier|const
name|QEdge
modifier|*
name|e1
parameter_list|,
specifier|const
name|QEdge
modifier|*
name|e2
parameter_list|)
block|{
return|return
name|e1
operator|->
name|p1
operator|.
name|y
operator|<
name|e2
operator|->
name|p1
operator|.
name|y
return|;
block|}
end_function
begin_function
DECL|function|isEqual
specifier|static
specifier|inline
name|bool
name|isEqual
parameter_list|(
specifier|const
name|XPointFixed
modifier|&
name|p1
parameter_list|,
specifier|const
name|XPointFixed
modifier|&
name|p2
parameter_list|)
block|{
return|return
operator|(
operator|(
name|p1
operator|.
name|x
operator|==
name|p2
operator|.
name|x
operator|)
operator|&&
operator|(
name|p1
operator|.
name|y
operator|==
name|p2
operator|.
name|y
operator|)
operator|)
return|;
block|}
end_function
begin_function
DECL|function|compareIntersections
specifier|static
specifier|inline
name|bool
name|compareIntersections
parameter_list|(
specifier|const
name|QIntersectionPoint
modifier|&
name|i1
parameter_list|,
specifier|const
name|QIntersectionPoint
modifier|&
name|i2
parameter_list|)
block|{
if|if
condition|(
name|qAbs
argument_list|(
name|i1
operator|.
name|x
operator|-
name|i2
operator|.
name|x
argument_list|)
operator|>
literal|0.01
condition|)
block|{
comment|// x != other.x in 99% of the cases
return|return
name|i1
operator|.
name|x
operator|<
name|i2
operator|.
name|x
return|;
block|}
else|else
block|{
name|qreal
name|x1
init|=
operator|(
name|i1
operator|.
name|edge
operator|->
name|p1
operator|.
name|x
operator|!=
name|i1
operator|.
name|edge
operator|->
name|p2
operator|.
name|x
operator|)
condition|?
operator|(
operator|(
name|currentY
operator|+
literal|1
operator|-
name|i1
operator|.
name|edge
operator|->
name|b
operator|)
operator|*
name|i1
operator|.
name|edge
operator|->
name|m
operator|)
else|:
name|XFixedToDouble
argument_list|(
name|i1
operator|.
name|edge
operator|->
name|p1
operator|.
name|x
argument_list|)
decl_stmt|;
name|qreal
name|x2
init|=
operator|(
name|i2
operator|.
name|edge
operator|->
name|p1
operator|.
name|x
operator|!=
name|i2
operator|.
name|edge
operator|->
name|p2
operator|.
name|x
operator|)
condition|?
operator|(
operator|(
name|currentY
operator|+
literal|1
operator|-
name|i2
operator|.
name|edge
operator|->
name|b
operator|)
operator|*
name|i2
operator|.
name|edge
operator|->
name|m
operator|)
else|:
name|XFixedToDouble
argument_list|(
name|i2
operator|.
name|edge
operator|->
name|p1
operator|.
name|x
argument_list|)
decl_stmt|;
comment|//         qDebug()<< ">>>"<< currentY<< i1.edge<< i2.edge<< x1<< x2;
return|return
name|x1
operator|<
name|x2
return|;
block|}
block|}
end_function
begin_ifdef
ifdef|#
directive|ifdef
name|QT_USE_FIXED_POINT
end_ifdef
begin_function
DECL|function|qrealToXFixed
specifier|inline
name|int
name|qrealToXFixed
parameter_list|(
name|qreal
name|f
parameter_list|)
block|{
return|return
name|f
operator|.
name|value
argument_list|()
operator|<<
literal|8
return|;
block|}
end_function
begin_else
else|#
directive|else
end_else
begin_define
DECL|macro|qrealToXFixed
define|#
directive|define
name|qrealToXFixed
value|FloatToXFixed
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_function
DECL|function|toXTrapezoid
specifier|static
name|XTrapezoid
name|QT_FASTCALL
name|toXTrapezoid
parameter_list|(
name|XFixed
name|y1
parameter_list|,
name|XFixed
name|y2
parameter_list|,
specifier|const
name|QEdge
modifier|&
name|left
parameter_list|,
specifier|const
name|QEdge
modifier|&
name|right
parameter_list|)
block|{
name|XTrapezoid
name|trap
decl_stmt|;
name|trap
operator|.
name|top
operator|=
name|y1
expr_stmt|;
name|trap
operator|.
name|bottom
operator|=
name|y2
expr_stmt|;
name|trap
operator|.
name|left
operator|.
name|p1
operator|.
name|y
operator|=
name|left
operator|.
name|p1
operator|.
name|y
expr_stmt|;
name|trap
operator|.
name|left
operator|.
name|p2
operator|.
name|y
operator|=
name|left
operator|.
name|p2
operator|.
name|y
expr_stmt|;
name|trap
operator|.
name|right
operator|.
name|p1
operator|.
name|y
operator|=
name|right
operator|.
name|p1
operator|.
name|y
expr_stmt|;
name|trap
operator|.
name|right
operator|.
name|p2
operator|.
name|y
operator|=
name|right
operator|.
name|p2
operator|.
name|y
expr_stmt|;
name|trap
operator|.
name|left
operator|.
name|p1
operator|.
name|x
operator|=
name|left
operator|.
name|p1
operator|.
name|x
expr_stmt|;
name|trap
operator|.
name|left
operator|.
name|p2
operator|.
name|x
operator|=
name|left
operator|.
name|p2
operator|.
name|x
expr_stmt|;
name|trap
operator|.
name|right
operator|.
name|p1
operator|.
name|x
operator|=
name|right
operator|.
name|p1
operator|.
name|x
expr_stmt|;
name|trap
operator|.
name|right
operator|.
name|p2
operator|.
name|x
operator|=
name|right
operator|.
name|p2
operator|.
name|x
expr_stmt|;
return|return
name|trap
return|;
block|}
end_function
begin_ifdef
ifdef|#
directive|ifdef
name|QT_DEBUG_TESSELATOR
end_ifdef
begin_function
DECL|function|dump_edges
specifier|static
name|void
name|dump_edges
parameter_list|(
specifier|const
name|QList
argument_list|<
specifier|const
name|QEdge
modifier|*
argument_list|>
modifier|&
name|et
parameter_list|)
block|{
for|for
control|(
name|int
name|x
init|=
literal|0
init|;
name|x
operator|<
name|et
operator|.
name|size
argument_list|()
condition|;
operator|++
name|x
control|)
block|{
name|qDebug
argument_list|()
operator|<<
literal|"edge#"
operator|<<
name|x
operator|<<
name|et
operator|.
name|at
argument_list|(
name|x
argument_list|)
operator|<<
literal|"("
operator|<<
name|XFixedToDouble
argument_list|(
name|et
operator|.
name|at
argument_list|(
name|x
argument_list|)
operator|->
name|p1
operator|.
name|x
argument_list|)
operator|<<
name|XFixedToDouble
argument_list|(
name|et
operator|.
name|at
argument_list|(
name|x
argument_list|)
operator|->
name|p1
operator|.
name|y
argument_list|)
operator|<<
literal|") ("
operator|<<
name|XFixedToDouble
argument_list|(
name|et
operator|.
name|at
argument_list|(
name|x
argument_list|)
operator|->
name|p2
operator|.
name|x
argument_list|)
operator|<<
name|XFixedToDouble
argument_list|(
name|et
operator|.
name|at
argument_list|(
name|x
argument_list|)
operator|->
name|p2
operator|.
name|y
argument_list|)
operator|<<
literal|") b: "
operator|<<
name|et
operator|.
name|at
argument_list|(
name|x
argument_list|)
operator|->
name|b
operator|<<
literal|"m:"
operator|<<
name|et
operator|.
name|at
argument_list|(
name|x
argument_list|)
operator|->
name|m
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|dump_trap
specifier|static
name|void
name|dump_trap
parameter_list|(
specifier|const
name|XTrapezoid
modifier|&
name|t
parameter_list|)
block|{
name|qDebug
argument_list|()
operator|<<
literal|"trap# t="
operator|<<
name|t
operator|.
name|top
operator|/
literal|65536.0
operator|<<
literal|"b="
operator|<<
name|t
operator|.
name|bottom
operator|/
literal|65536.0
operator|<<
literal|"h="
operator|<<
name|XFixedToDouble
argument_list|(
name|t
operator|.
name|bottom
operator|-
name|t
operator|.
name|top
argument_list|)
operator|<<
literal|"\tleft p1: ("
operator|<<
name|XFixedToDouble
argument_list|(
name|t
operator|.
name|left
operator|.
name|p1
operator|.
name|x
argument_list|)
operator|<<
literal|","
operator|<<
name|XFixedToDouble
argument_list|(
name|t
operator|.
name|left
operator|.
name|p1
operator|.
name|y
argument_list|)
operator|<<
literal|")"
operator|<<
literal|"\tleft p2: ("
operator|<<
name|XFixedToDouble
argument_list|(
name|t
operator|.
name|left
operator|.
name|p2
operator|.
name|x
argument_list|)
operator|<<
literal|","
operator|<<
name|XFixedToDouble
argument_list|(
name|t
operator|.
name|left
operator|.
name|p2
operator|.
name|y
argument_list|)
operator|<<
literal|")"
operator|<<
literal|"\n\t\t\t\tright p1:("
operator|<<
name|XFixedToDouble
argument_list|(
name|t
operator|.
name|right
operator|.
name|p1
operator|.
name|x
argument_list|)
operator|<<
literal|","
operator|<<
name|XFixedToDouble
argument_list|(
name|t
operator|.
name|right
operator|.
name|p1
operator|.
name|y
argument_list|)
operator|<<
literal|")"
operator|<<
literal|"\tright p2:("
operator|<<
name|XFixedToDouble
argument_list|(
name|t
operator|.
name|right
operator|.
name|p2
operator|.
name|x
argument_list|)
operator|<<
literal|","
operator|<<
name|XFixedToDouble
argument_list|(
name|t
operator|.
name|right
operator|.
name|p2
operator|.
name|y
argument_list|)
operator|<<
literal|")"
expr_stmt|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_typedef
DECL|typedef|Q27Dot5
typedef|typedef
name|int
name|Q27Dot5
typedef|;
end_typedef
begin_define
DECL|macro|Q27Dot5ToDouble
define|#
directive|define
name|Q27Dot5ToDouble
parameter_list|(
name|i
parameter_list|)
value|(i/32.)
end_define
begin_define
DECL|macro|FloatToQ27Dot5
define|#
directive|define
name|FloatToQ27Dot5
parameter_list|(
name|i
parameter_list|)
value|(int)((i) * 32)
end_define
begin_define
DECL|macro|IntToQ27Dot5
define|#
directive|define
name|IntToQ27Dot5
parameter_list|(
name|i
parameter_list|)
value|((i)<< 5)
end_define
begin_define
DECL|macro|Q27Dot5ToXFixed
define|#
directive|define
name|Q27Dot5ToXFixed
parameter_list|(
name|i
parameter_list|)
value|((i)<< 11)
end_define
begin_define
DECL|macro|Q27Dot5Factor
define|#
directive|define
name|Q27Dot5Factor
value|32
end_define
begin_function
DECL|function|old_tesselate_polygon
name|void
name|old_tesselate_polygon
parameter_list|(
name|QVector
argument_list|<
name|XTrapezoid
argument_list|>
modifier|*
name|traps
parameter_list|,
specifier|const
name|QPointF
modifier|*
name|pg
parameter_list|,
name|int
name|pgSize
parameter_list|,
name|bool
name|winding
parameter_list|)
block|{
name|QVector
argument_list|<
name|QEdge
argument_list|>
name|edges
decl_stmt|;
name|edges
operator|.
name|reserve
argument_list|(
literal|128
argument_list|)
expr_stmt|;
name|qreal
name|ymin
argument_list|(
name|INT_MAX
operator|/
literal|256
argument_list|)
decl_stmt|;
name|qreal
name|ymax
argument_list|(
name|INT_MIN
operator|/
literal|256
argument_list|)
decl_stmt|;
comment|//painter.begin(pg, pgSize);
if|if
condition|(
name|pg
index|[
literal|0
index|]
operator|!=
name|pg
index|[
name|pgSize
operator|-
literal|1
index|]
condition|)
name|qWarning
argument_list|()
operator|<<
name|Q_FUNC_INFO
operator|<<
literal|"Malformed polygon (first and last points must be identical)"
expr_stmt|;
comment|// generate edge table
comment|//     qDebug()<< "POINTS:";
for|for
control|(
name|int
name|x
init|=
literal|0
init|;
name|x
operator|<
name|pgSize
operator|-
literal|1
condition|;
operator|++
name|x
control|)
block|{
name|QEdge
name|edge
decl_stmt|;
name|QPointF
name|p1
argument_list|(
name|Q27Dot5ToDouble
argument_list|(
name|FloatToQ27Dot5
argument_list|(
name|pg
index|[
name|x
index|]
operator|.
name|x
argument_list|()
argument_list|)
argument_list|)
argument_list|,
name|Q27Dot5ToDouble
argument_list|(
name|FloatToQ27Dot5
argument_list|(
name|pg
index|[
name|x
index|]
operator|.
name|y
argument_list|()
argument_list|)
argument_list|)
argument_list|)
decl_stmt|;
name|QPointF
name|p2
argument_list|(
name|Q27Dot5ToDouble
argument_list|(
name|FloatToQ27Dot5
argument_list|(
name|pg
index|[
name|x
operator|+
literal|1
index|]
operator|.
name|x
argument_list|()
argument_list|)
argument_list|)
argument_list|,
name|Q27Dot5ToDouble
argument_list|(
name|FloatToQ27Dot5
argument_list|(
name|pg
index|[
name|x
operator|+
literal|1
index|]
operator|.
name|y
argument_list|()
argument_list|)
argument_list|)
argument_list|)
decl_stmt|;
comment|//         qDebug()<< "    "
comment|//<< p1;
name|edge
operator|.
name|winding
operator|=
name|p1
operator|.
name|y
argument_list|()
operator|>
name|p2
operator|.
name|y
argument_list|()
condition|?
literal|1
else|:
operator|-
literal|1
expr_stmt|;
if|if
condition|(
name|edge
operator|.
name|winding
operator|>
literal|0
condition|)
name|qSwap
argument_list|(
name|p1
argument_list|,
name|p2
argument_list|)
expr_stmt|;
name|edge
operator|.
name|p1
operator|.
name|x
operator|=
name|XDoubleToFixed
argument_list|(
name|p1
operator|.
name|x
argument_list|()
argument_list|)
expr_stmt|;
name|edge
operator|.
name|p1
operator|.
name|y
operator|=
name|XDoubleToFixed
argument_list|(
name|p1
operator|.
name|y
argument_list|()
argument_list|)
expr_stmt|;
name|edge
operator|.
name|p2
operator|.
name|x
operator|=
name|XDoubleToFixed
argument_list|(
name|p2
operator|.
name|x
argument_list|()
argument_list|)
expr_stmt|;
name|edge
operator|.
name|p2
operator|.
name|y
operator|=
name|XDoubleToFixed
argument_list|(
name|p2
operator|.
name|y
argument_list|()
argument_list|)
expr_stmt|;
name|edge
operator|.
name|m
operator|=
operator|(
name|p1
operator|.
name|y
argument_list|()
operator|-
name|p2
operator|.
name|y
argument_list|()
operator|)
operator|/
operator|(
name|p1
operator|.
name|x
argument_list|()
operator|-
name|p2
operator|.
name|x
argument_list|()
operator|)
expr_stmt|;
comment|// line derivative
name|edge
operator|.
name|b
operator|=
name|p1
operator|.
name|y
argument_list|()
operator|-
name|edge
operator|.
name|m
operator|*
name|p1
operator|.
name|x
argument_list|()
expr_stmt|;
comment|// intersection with y axis
name|edge
operator|.
name|m
operator|=
name|edge
operator|.
name|m
operator|!=
literal|0.0
condition|?
literal|1.0
operator|/
name|edge
operator|.
name|m
else|:
literal|0.0
expr_stmt|;
comment|// inverted derivative
name|edges
operator|.
name|append
argument_list|(
name|edge
argument_list|)
expr_stmt|;
name|ymin
operator|=
name|qMin
argument_list|(
name|ymin
argument_list|,
name|qreal
argument_list|(
name|XFixedToDouble
argument_list|(
name|edge
operator|.
name|p1
operator|.
name|y
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|ymax
operator|=
name|qMax
argument_list|(
name|ymax
argument_list|,
name|qreal
argument_list|(
name|XFixedToDouble
argument_list|(
name|edge
operator|.
name|p2
operator|.
name|y
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
block|}
name|QList
argument_list|<
specifier|const
name|QEdge
modifier|*
argument_list|>
name|et
decl_stmt|;
comment|// edge list
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|edges
operator|.
name|size
argument_list|()
condition|;
operator|++
name|i
control|)
name|et
operator|.
name|append
argument_list|(
operator|&
name|edges
operator|.
name|at
argument_list|(
name|i
argument_list|)
argument_list|)
expr_stmt|;
comment|// sort edge table by min y value
name|qSort
argument_list|(
name|et
operator|.
name|begin
argument_list|()
argument_list|,
name|et
operator|.
name|end
argument_list|()
argument_list|,
name|compareEdges
argument_list|)
expr_stmt|;
comment|// eliminate shared edges
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|et
operator|.
name|size
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
for|for
control|(
name|int
name|k
init|=
name|i
operator|+
literal|1
init|;
name|k
operator|<
name|et
operator|.
name|size
argument_list|()
condition|;
operator|++
name|k
control|)
block|{
specifier|const
name|QEdge
modifier|*
name|edgeI
init|=
name|et
operator|.
name|at
argument_list|(
name|i
argument_list|)
decl_stmt|;
specifier|const
name|QEdge
modifier|*
name|edgeK
init|=
name|et
operator|.
name|at
argument_list|(
name|k
argument_list|)
decl_stmt|;
if|if
condition|(
name|edgeK
operator|->
name|p1
operator|.
name|y
operator|>
name|edgeI
operator|->
name|p1
operator|.
name|y
condition|)
break|break;
if|if
condition|(
name|edgeI
operator|->
name|winding
operator|!=
name|edgeK
operator|->
name|winding
operator|&&
name|isEqual
argument_list|(
name|edgeI
operator|->
name|p1
argument_list|,
name|edgeK
operator|->
name|p1
argument_list|)
operator|&&
name|isEqual
argument_list|(
name|edgeI
operator|->
name|p2
argument_list|,
name|edgeK
operator|->
name|p2
argument_list|)
condition|)
block|{
name|et
operator|.
name|removeAt
argument_list|(
name|k
argument_list|)
expr_stmt|;
name|et
operator|.
name|removeAt
argument_list|(
name|i
argument_list|)
expr_stmt|;
operator|--
name|i
expr_stmt|;
break|break;
block|}
block|}
block|}
if|if
condition|(
name|ymax
operator|<=
name|ymin
condition|)
return|return;
name|QList
argument_list|<
specifier|const
name|QEdge
modifier|*
argument_list|>
name|aet
decl_stmt|;
comment|// edges that intersects the current scanline
comment|//     if (ymin< 0)
comment|// 	ymin = 0;
comment|//     if (paintEventClipRegion) // don't scan more lines than we have to
comment|// 	ymax = paintEventClipRegion->boundingRect().height();
ifdef|#
directive|ifdef
name|QT_DEBUG_TESSELATOR
name|qDebug
argument_list|(
literal|"==> ymin = %f, ymax = %f"
argument_list|,
name|ymin
argument_list|,
name|ymax
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|// QT_DEBUG_TESSELATOR
name|currentY
operator|=
name|ymin
expr_stmt|;
comment|// used by the less than op
for|for
control|(
name|qreal
name|y
init|=
name|ymin
init|;
name|y
operator|<
name|ymax
condition|;
control|)
block|{
comment|// fill active edge table with edges that intersect the current line
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|et
operator|.
name|size
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
specifier|const
name|QEdge
modifier|*
name|edge
init|=
name|et
operator|.
name|at
argument_list|(
name|i
argument_list|)
decl_stmt|;
if|if
condition|(
name|edge
operator|->
name|p1
operator|.
name|y
operator|>
name|XDoubleToFixed
argument_list|(
name|y
argument_list|)
condition|)
break|break;
name|aet
operator|.
name|append
argument_list|(
name|edge
argument_list|)
expr_stmt|;
name|et
operator|.
name|removeAt
argument_list|(
name|i
argument_list|)
expr_stmt|;
operator|--
name|i
expr_stmt|;
block|}
comment|// remove processed edges from active edge table
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|aet
operator|.
name|size
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
if|if
condition|(
name|aet
operator|.
name|at
argument_list|(
name|i
argument_list|)
operator|->
name|p2
operator|.
name|y
operator|<=
name|XDoubleToFixed
argument_list|(
name|y
argument_list|)
condition|)
block|{
name|aet
operator|.
name|removeAt
argument_list|(
name|i
argument_list|)
expr_stmt|;
operator|--
name|i
expr_stmt|;
block|}
block|}
if|if
condition|(
name|aet
operator|.
name|size
argument_list|()
operator|%
literal|2
operator|!=
literal|0
condition|)
block|{
ifndef|#
directive|ifndef
name|QT_NO_DEBUG
name|qWarning
argument_list|(
literal|"QX11PaintEngine: aet out of sync - this should not happen."
argument_list|)
expr_stmt|;
endif|#
directive|endif
return|return;
block|}
comment|// done?
if|if
condition|(
operator|!
name|aet
operator|.
name|size
argument_list|()
condition|)
block|{
if|if
condition|(
operator|!
name|et
operator|.
name|size
argument_list|()
condition|)
block|{
break|break;
block|}
else|else
block|{
name|y
operator|=
name|currentY
operator|=
name|XFixedToDouble
argument_list|(
name|et
operator|.
name|at
argument_list|(
literal|0
argument_list|)
operator|->
name|p1
operator|.
name|y
argument_list|)
expr_stmt|;
continue|continue;
block|}
block|}
comment|// calculate the next y where we have to start a new set of trapezoids
name|qreal
name|next_y
argument_list|(
name|INT_MAX
operator|/
literal|256
argument_list|)
decl_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|aet
operator|.
name|size
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
specifier|const
name|QEdge
modifier|*
name|edge
init|=
name|aet
operator|.
name|at
argument_list|(
name|i
argument_list|)
decl_stmt|;
if|if
condition|(
name|XFixedToDouble
argument_list|(
name|edge
operator|->
name|p2
operator|.
name|y
argument_list|)
operator|<
name|next_y
condition|)
name|next_y
operator|=
name|XFixedToDouble
argument_list|(
name|edge
operator|->
name|p2
operator|.
name|y
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|et
operator|.
name|size
argument_list|()
operator|&&
name|next_y
operator|>
name|XFixedToDouble
argument_list|(
name|et
operator|.
name|at
argument_list|(
literal|0
argument_list|)
operator|->
name|p1
operator|.
name|y
argument_list|)
condition|)
name|next_y
operator|=
name|XFixedToDouble
argument_list|(
name|et
operator|.
name|at
argument_list|(
literal|0
argument_list|)
operator|->
name|p1
operator|.
name|y
argument_list|)
expr_stmt|;
name|int
name|aetSize
init|=
name|aet
operator|.
name|size
argument_list|()
decl_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|aetSize
condition|;
operator|++
name|i
control|)
block|{
for|for
control|(
name|int
name|k
init|=
name|i
operator|+
literal|1
init|;
name|k
operator|<
name|aetSize
condition|;
operator|++
name|k
control|)
block|{
specifier|const
name|QEdge
modifier|*
name|edgeI
init|=
name|aet
operator|.
name|at
argument_list|(
name|i
argument_list|)
decl_stmt|;
specifier|const
name|QEdge
modifier|*
name|edgeK
init|=
name|aet
operator|.
name|at
argument_list|(
name|k
argument_list|)
decl_stmt|;
name|qreal
name|m1
init|=
name|edgeI
operator|->
name|m
decl_stmt|;
name|qreal
name|b1
init|=
name|edgeI
operator|->
name|b
decl_stmt|;
name|qreal
name|m2
init|=
name|edgeK
operator|->
name|m
decl_stmt|;
name|qreal
name|b2
init|=
name|edgeK
operator|->
name|b
decl_stmt|;
if|if
condition|(
name|qAbs
argument_list|(
name|m1
operator|-
name|m2
argument_list|)
operator|<
literal|0.001
condition|)
continue|continue;
comment|// ### intersect is not calculated correctly when optimized with -O2 (gcc)
specifier|volatile
name|qreal
name|intersect
init|=
literal|0
decl_stmt|;
if|if
condition|(
operator|!
name|qIsFinite
argument_list|(
name|b1
argument_list|)
condition|)
name|intersect
operator|=
operator|(
literal|1.f
operator|/
name|m2
operator|)
operator|*
name|XFixedToDouble
argument_list|(
name|edgeI
operator|->
name|p1
operator|.
name|x
argument_list|)
operator|+
name|b2
expr_stmt|;
elseif|else
if|if
condition|(
operator|!
name|qIsFinite
argument_list|(
name|b2
argument_list|)
condition|)
name|intersect
operator|=
operator|(
literal|1.f
operator|/
name|m1
operator|)
operator|*
name|XFixedToDouble
argument_list|(
name|edgeK
operator|->
name|p1
operator|.
name|x
argument_list|)
operator|+
name|b1
expr_stmt|;
else|else
name|intersect
operator|=
operator|(
name|b1
operator|*
name|m1
operator|-
name|b2
operator|*
name|m2
operator|)
operator|/
operator|(
name|m1
operator|-
name|m2
operator|)
expr_stmt|;
if|if
condition|(
name|intersect
operator|>
name|y
operator|&&
name|intersect
operator|<
name|next_y
condition|)
name|next_y
operator|=
name|intersect
expr_stmt|;
block|}
block|}
name|XFixed
name|yf
decl_stmt|,
name|next_yf
decl_stmt|;
name|yf
operator|=
name|qrealToXFixed
argument_list|(
name|y
argument_list|)
expr_stmt|;
name|next_yf
operator|=
name|qrealToXFixed
argument_list|(
name|next_y
argument_list|)
expr_stmt|;
if|if
condition|(
name|yf
operator|==
name|next_yf
condition|)
block|{
name|y
operator|=
name|currentY
operator|=
name|next_y
expr_stmt|;
continue|continue;
block|}
ifdef|#
directive|ifdef
name|QT_DEBUG_TESSELATOR
name|qDebug
argument_list|(
literal|"###> y = %f, next_y = %f, %d active edges"
argument_list|,
name|y
argument_list|,
name|next_y
argument_list|,
name|aet
operator|.
name|size
argument_list|()
argument_list|)
expr_stmt|;
name|qDebug
argument_list|(
literal|"===> edges"
argument_list|)
expr_stmt|;
name|dump_edges
argument_list|(
name|et
argument_list|)
expr_stmt|;
name|qDebug
argument_list|(
literal|"===> active edges"
argument_list|)
expr_stmt|;
name|dump_edges
argument_list|(
name|aet
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|// calc intersection points
name|QVarLengthArray
argument_list|<
name|QIntersectionPoint
argument_list|>
name|isects
argument_list|(
name|aet
operator|.
name|size
argument_list|()
operator|+
literal|1
argument_list|)
decl_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|isects
operator|.
name|size
argument_list|()
operator|-
literal|1
condition|;
operator|++
name|i
control|)
block|{
specifier|const
name|QEdge
modifier|*
name|edge
init|=
name|aet
operator|.
name|at
argument_list|(
name|i
argument_list|)
decl_stmt|;
name|isects
index|[
name|i
index|]
operator|.
name|x
operator|=
operator|(
name|edge
operator|->
name|p1
operator|.
name|x
operator|!=
name|edge
operator|->
name|p2
operator|.
name|x
operator|)
condition|?
operator|(
operator|(
name|y
operator|-
name|edge
operator|->
name|b
operator|)
operator|*
name|edge
operator|->
name|m
operator|)
else|:
name|XFixedToDouble
argument_list|(
name|edge
operator|->
name|p1
operator|.
name|x
argument_list|)
expr_stmt|;
name|isects
index|[
name|i
index|]
operator|.
name|edge
operator|=
name|edge
expr_stmt|;
block|}
if|if
condition|(
name|isects
operator|.
name|size
argument_list|()
operator|%
literal|2
operator|!=
literal|1
condition|)
name|qFatal
argument_list|(
literal|"%s: number of intersection points must be odd"
argument_list|,
name|Q_FUNC_INFO
argument_list|)
expr_stmt|;
comment|// sort intersection points
name|qSort
argument_list|(
operator|&
name|isects
index|[
literal|0
index|]
argument_list|,
operator|&
name|isects
index|[
name|isects
operator|.
name|size
argument_list|()
operator|-
literal|1
index|]
argument_list|,
name|compareIntersections
argument_list|)
expr_stmt|;
comment|//         qDebug()<< "INTERSECTION_POINTS:";
comment|//  	for (int i = 0; i< isects.size(); ++i)
comment|//             qDebug()<< isects[i].edge<< isects[i].x;
if|if
condition|(
name|winding
condition|)
block|{
comment|// winding fill rule
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|isects
operator|.
name|size
argument_list|()
operator|-
literal|1
condition|;
control|)
block|{
name|int
name|winding
init|=
literal|0
decl_stmt|;
specifier|const
name|QEdge
modifier|*
name|left
init|=
name|isects
index|[
name|i
index|]
operator|.
name|edge
decl_stmt|;
specifier|const
name|QEdge
modifier|*
name|right
init|=
literal|0
decl_stmt|;
name|winding
operator|+=
name|isects
index|[
name|i
index|]
operator|.
name|edge
operator|->
name|winding
expr_stmt|;
for|for
control|(
operator|++
name|i
init|;
name|i
operator|<
name|isects
operator|.
name|size
argument_list|()
operator|-
literal|1
operator|&&
name|winding
operator|!=
literal|0
condition|;
operator|++
name|i
control|)
block|{
name|winding
operator|+=
name|isects
index|[
name|i
index|]
operator|.
name|edge
operator|->
name|winding
expr_stmt|;
name|right
operator|=
name|isects
index|[
name|i
index|]
operator|.
name|edge
expr_stmt|;
block|}
if|if
condition|(
operator|!
name|left
operator|||
operator|!
name|right
condition|)
break|break;
comment|//painter.addTrapezoid(&toXTrapezoid(yf, next_yf, *left, *right));
name|traps
operator|->
name|append
argument_list|(
name|toXTrapezoid
argument_list|(
name|yf
argument_list|,
name|next_yf
argument_list|,
operator|*
name|left
argument_list|,
operator|*
name|right
argument_list|)
argument_list|)
expr_stmt|;
block|}
block|}
else|else
block|{
comment|// odd-even fill rule
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|isects
operator|.
name|size
argument_list|()
operator|-
literal|2
condition|;
name|i
operator|+=
literal|2
control|)
block|{
comment|//painter.addTrapezoid(&toXTrapezoid(yf, next_yf, *isects[i].edge, *isects[i+1].edge));
name|traps
operator|->
name|append
argument_list|(
name|toXTrapezoid
argument_list|(
name|yf
argument_list|,
name|next_yf
argument_list|,
operator|*
name|isects
index|[
name|i
index|]
operator|.
name|edge
argument_list|,
operator|*
name|isects
index|[
name|i
operator|+
literal|1
index|]
operator|.
name|edge
argument_list|)
argument_list|)
expr_stmt|;
block|}
block|}
name|y
operator|=
name|currentY
operator|=
name|next_y
expr_stmt|;
block|}
ifdef|#
directive|ifdef
name|QT_DEBUG_TESSELATOR
name|qDebug
argument_list|(
literal|"==> number of trapezoids: %d - edge table size: %d\n"
argument_list|,
name|traps
operator|->
name|size
argument_list|()
argument_list|,
name|et
operator|.
name|size
argument_list|()
argument_list|)
expr_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|traps
operator|->
name|size
argument_list|()
condition|;
operator|++
name|i
control|)
name|dump_trap
argument_list|(
name|traps
operator|->
name|at
argument_list|(
name|i
argument_list|)
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|// optimize by unifying trapezoids that share left/right lines
comment|// and have a common top/bottom edge
comment|//     for (int i = 0; i< tps.size(); ++i) {
comment|// 	for (int k = i+1; k< tps.size(); ++k) {
comment|// 	    if (i != k&& tps.at(i).right == tps.at(k).right
comment|//&& tps.at(i).left == tps.at(k).left
comment|//&& (tps.at(i).top == tps.at(k).bottom
comment|// 		    || tps.at(i).bottom == tps.at(k).top))
comment|// 	    {
comment|// 		tps[i].bottom = tps.at(k).bottom;
comment|// 		tps.removeAt(k);
comment|//                 i = 0;
comment|// 		break;
comment|// 	    }
comment|// 	}
comment|//     }
comment|//static int i = 0;
comment|//QImage img = painter.end();
comment|//img.save(QString("res%1.png").arg(i++), "PNG");
block|}
end_function
end_unit
