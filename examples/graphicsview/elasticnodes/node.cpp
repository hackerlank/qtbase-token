begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of Nokia Corporation and its Subsidiary(-ies) nor **     the names of its contributors may be used to endorse or promote **     products derived from this software without specific prior written **     permission. ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QGraphicsScene>
end_include
begin_include
include|#
directive|include
file|<QGraphicsSceneMouseEvent>
end_include
begin_include
include|#
directive|include
file|<QPainter>
end_include
begin_include
include|#
directive|include
file|<QStyleOption>
end_include
begin_include
include|#
directive|include
file|"edge.h"
end_include
begin_include
include|#
directive|include
file|"node.h"
end_include
begin_include
include|#
directive|include
file|"graphwidget.h"
end_include
begin_comment
comment|//! [0]
end_comment
begin_constructor
DECL|function|Node
name|Node
operator|::
name|Node
parameter_list|(
name|GraphWidget
modifier|*
name|graphWidget
parameter_list|)
member_init_list|:
name|graph
argument_list|(
name|graphWidget
argument_list|)
block|{
name|setFlag
argument_list|(
name|ItemIsMovable
argument_list|)
expr_stmt|;
name|setFlag
argument_list|(
name|ItemSendsGeometryChanges
argument_list|)
expr_stmt|;
name|setCacheMode
argument_list|(
name|DeviceCoordinateCache
argument_list|)
expr_stmt|;
name|setZValue
argument_list|(
operator|-
literal|1
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_comment
comment|//! [0]
end_comment
begin_comment
comment|//! [1]
end_comment
begin_function
DECL|function|addEdge
name|void
name|Node
operator|::
name|addEdge
parameter_list|(
name|Edge
modifier|*
name|edge
parameter_list|)
block|{
name|edgeList
operator|<<
name|edge
expr_stmt|;
name|edge
operator|->
name|adjust
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|edges
name|QList
argument_list|<
name|Edge
modifier|*
argument_list|>
name|Node
operator|::
name|edges
parameter_list|()
specifier|const
block|{
return|return
name|edgeList
return|;
block|}
end_function
begin_comment
comment|//! [1]
end_comment
begin_comment
comment|//! [2]
end_comment
begin_function
DECL|function|calculateForces
name|void
name|Node
operator|::
name|calculateForces
parameter_list|()
block|{
if|if
condition|(
operator|!
name|scene
argument_list|()
operator|||
name|scene
argument_list|()
operator|->
name|mouseGrabberItem
argument_list|()
operator|==
name|this
condition|)
block|{
name|newPos
operator|=
name|pos
argument_list|()
expr_stmt|;
return|return;
block|}
comment|//! [2]
comment|//! [3]
comment|// Sum up all forces pushing this item away
name|qreal
name|xvel
init|=
literal|0
decl_stmt|;
name|qreal
name|yvel
init|=
literal|0
decl_stmt|;
foreach|foreach
control|(
name|QGraphicsItem
modifier|*
name|item
decl|,
name|scene
argument_list|()
operator|->
name|items
argument_list|()
control|)
block|{
name|Node
modifier|*
name|node
init|=
name|qgraphicsitem_cast
argument_list|<
name|Node
operator|*
argument_list|>
argument_list|(
name|item
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|node
condition|)
continue|continue;
name|QPointF
name|vec
init|=
name|mapToItem
argument_list|(
name|node
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
decl_stmt|;
name|qreal
name|dx
init|=
name|vec
operator|.
name|x
argument_list|()
decl_stmt|;
name|qreal
name|dy
init|=
name|vec
operator|.
name|y
argument_list|()
decl_stmt|;
name|double
name|l
init|=
literal|2.0
operator|*
operator|(
name|dx
operator|*
name|dx
operator|+
name|dy
operator|*
name|dy
operator|)
decl_stmt|;
if|if
condition|(
name|l
operator|>
literal|0
condition|)
block|{
name|xvel
operator|+=
operator|(
name|dx
operator|*
literal|150.0
operator|)
operator|/
name|l
expr_stmt|;
name|yvel
operator|+=
operator|(
name|dy
operator|*
literal|150.0
operator|)
operator|/
name|l
expr_stmt|;
block|}
block|}
comment|//! [3]
comment|//! [4]
comment|// Now subtract all forces pulling items together
name|double
name|weight
init|=
operator|(
name|edgeList
operator|.
name|size
argument_list|()
operator|+
literal|1
operator|)
operator|*
literal|10
decl_stmt|;
foreach|foreach
control|(
name|Edge
modifier|*
name|edge
decl|,
name|edgeList
control|)
block|{
name|QPointF
name|vec
decl_stmt|;
if|if
condition|(
name|edge
operator|->
name|sourceNode
argument_list|()
operator|==
name|this
condition|)
name|vec
operator|=
name|mapToItem
argument_list|(
name|edge
operator|->
name|destNode
argument_list|()
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
else|else
name|vec
operator|=
name|mapToItem
argument_list|(
name|edge
operator|->
name|sourceNode
argument_list|()
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|xvel
operator|-=
name|vec
operator|.
name|x
argument_list|()
operator|/
name|weight
expr_stmt|;
name|yvel
operator|-=
name|vec
operator|.
name|y
argument_list|()
operator|/
name|weight
expr_stmt|;
block|}
comment|//! [4]
comment|//! [5]
if|if
condition|(
name|qAbs
argument_list|(
name|xvel
argument_list|)
operator|<
literal|0.1
operator|&&
name|qAbs
argument_list|(
name|yvel
argument_list|)
operator|<
literal|0.1
condition|)
name|xvel
operator|=
name|yvel
operator|=
literal|0
expr_stmt|;
comment|//! [5]
comment|//! [6]
name|QRectF
name|sceneRect
init|=
name|scene
argument_list|()
operator|->
name|sceneRect
argument_list|()
decl_stmt|;
name|newPos
operator|=
name|pos
argument_list|()
operator|+
name|QPointF
argument_list|(
name|xvel
argument_list|,
name|yvel
argument_list|)
expr_stmt|;
name|newPos
operator|.
name|setX
argument_list|(
name|qMin
argument_list|(
name|qMax
argument_list|(
name|newPos
operator|.
name|x
argument_list|()
argument_list|,
name|sceneRect
operator|.
name|left
argument_list|()
operator|+
literal|10
argument_list|)
argument_list|,
name|sceneRect
operator|.
name|right
argument_list|()
operator|-
literal|10
argument_list|)
argument_list|)
expr_stmt|;
name|newPos
operator|.
name|setY
argument_list|(
name|qMin
argument_list|(
name|qMax
argument_list|(
name|newPos
operator|.
name|y
argument_list|()
argument_list|,
name|sceneRect
operator|.
name|top
argument_list|()
operator|+
literal|10
argument_list|)
argument_list|,
name|sceneRect
operator|.
name|bottom
argument_list|()
operator|-
literal|10
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [6]
end_comment
begin_comment
comment|//! [7]
end_comment
begin_function
DECL|function|advance
name|bool
name|Node
operator|::
name|advance
parameter_list|()
block|{
if|if
condition|(
name|newPos
operator|==
name|pos
argument_list|()
condition|)
return|return
literal|false
return|;
name|setPos
argument_list|(
name|newPos
argument_list|)
expr_stmt|;
return|return
literal|true
return|;
block|}
end_function
begin_comment
comment|//! [7]
end_comment
begin_comment
comment|//! [8]
end_comment
begin_function
DECL|function|boundingRect
name|QRectF
name|Node
operator|::
name|boundingRect
parameter_list|()
specifier|const
block|{
name|qreal
name|adjust
init|=
literal|2
decl_stmt|;
return|return
name|QRectF
argument_list|(
operator|-
literal|10
operator|-
name|adjust
argument_list|,
operator|-
literal|10
operator|-
name|adjust
argument_list|,
literal|23
operator|+
name|adjust
argument_list|,
literal|23
operator|+
name|adjust
argument_list|)
return|;
block|}
end_function
begin_comment
comment|//! [8]
end_comment
begin_comment
comment|//! [9]
end_comment
begin_function
DECL|function|shape
name|QPainterPath
name|Node
operator|::
name|shape
parameter_list|()
specifier|const
block|{
name|QPainterPath
name|path
decl_stmt|;
name|path
operator|.
name|addEllipse
argument_list|(
operator|-
literal|10
argument_list|,
operator|-
literal|10
argument_list|,
literal|20
argument_list|,
literal|20
argument_list|)
expr_stmt|;
return|return
name|path
return|;
block|}
end_function
begin_comment
comment|//! [9]
end_comment
begin_comment
comment|//! [10]
end_comment
begin_function
DECL|function|paint
name|void
name|Node
operator|::
name|paint
parameter_list|(
name|QPainter
modifier|*
name|painter
parameter_list|,
specifier|const
name|QStyleOptionGraphicsItem
modifier|*
name|option
parameter_list|,
name|QWidget
modifier|*
parameter_list|)
block|{
name|painter
operator|->
name|setPen
argument_list|(
name|Qt
operator|::
name|NoPen
argument_list|)
expr_stmt|;
name|painter
operator|->
name|setBrush
argument_list|(
name|Qt
operator|::
name|darkGray
argument_list|)
expr_stmt|;
name|painter
operator|->
name|drawEllipse
argument_list|(
operator|-
literal|7
argument_list|,
operator|-
literal|7
argument_list|,
literal|20
argument_list|,
literal|20
argument_list|)
expr_stmt|;
name|QRadialGradient
name|gradient
argument_list|(
operator|-
literal|3
argument_list|,
operator|-
literal|3
argument_list|,
literal|10
argument_list|)
decl_stmt|;
if|if
condition|(
name|option
operator|->
name|state
operator|&
name|QStyle
operator|::
name|State_Sunken
condition|)
block|{
name|gradient
operator|.
name|setCenter
argument_list|(
literal|3
argument_list|,
literal|3
argument_list|)
expr_stmt|;
name|gradient
operator|.
name|setFocalPoint
argument_list|(
literal|3
argument_list|,
literal|3
argument_list|)
expr_stmt|;
name|gradient
operator|.
name|setColorAt
argument_list|(
literal|1
argument_list|,
name|QColor
argument_list|(
name|Qt
operator|::
name|yellow
argument_list|)
operator|.
name|light
argument_list|(
literal|120
argument_list|)
argument_list|)
expr_stmt|;
name|gradient
operator|.
name|setColorAt
argument_list|(
literal|0
argument_list|,
name|QColor
argument_list|(
name|Qt
operator|::
name|darkYellow
argument_list|)
operator|.
name|light
argument_list|(
literal|120
argument_list|)
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|gradient
operator|.
name|setColorAt
argument_list|(
literal|0
argument_list|,
name|Qt
operator|::
name|yellow
argument_list|)
expr_stmt|;
name|gradient
operator|.
name|setColorAt
argument_list|(
literal|1
argument_list|,
name|Qt
operator|::
name|darkYellow
argument_list|)
expr_stmt|;
block|}
name|painter
operator|->
name|setBrush
argument_list|(
name|gradient
argument_list|)
expr_stmt|;
name|painter
operator|->
name|setPen
argument_list|(
name|QPen
argument_list|(
name|Qt
operator|::
name|black
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
name|painter
operator|->
name|drawEllipse
argument_list|(
operator|-
literal|10
argument_list|,
operator|-
literal|10
argument_list|,
literal|20
argument_list|,
literal|20
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [10]
end_comment
begin_comment
comment|//! [11]
end_comment
begin_function
DECL|function|itemChange
name|QVariant
name|Node
operator|::
name|itemChange
parameter_list|(
name|GraphicsItemChange
name|change
parameter_list|,
specifier|const
name|QVariant
modifier|&
name|value
parameter_list|)
block|{
switch|switch
condition|(
name|change
condition|)
block|{
case|case
name|ItemPositionHasChanged
case|:
foreach|foreach
control|(
name|Edge
modifier|*
name|edge
decl|,
name|edgeList
control|)
name|edge
operator|->
name|adjust
argument_list|()
expr_stmt|;
name|graph
operator|->
name|itemMoved
argument_list|()
expr_stmt|;
break|break;
default|default:
break|break;
block|}
empty_stmt|;
return|return
name|QGraphicsItem
operator|::
name|itemChange
argument_list|(
name|change
argument_list|,
name|value
argument_list|)
return|;
block|}
end_function
begin_comment
comment|//! [11]
end_comment
begin_comment
comment|//! [12]
end_comment
begin_function
DECL|function|mousePressEvent
name|void
name|Node
operator|::
name|mousePressEvent
parameter_list|(
name|QGraphicsSceneMouseEvent
modifier|*
name|event
parameter_list|)
block|{
name|update
argument_list|()
expr_stmt|;
name|QGraphicsItem
operator|::
name|mousePressEvent
argument_list|(
name|event
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|mouseReleaseEvent
name|void
name|Node
operator|::
name|mouseReleaseEvent
parameter_list|(
name|QGraphicsSceneMouseEvent
modifier|*
name|event
parameter_list|)
block|{
name|update
argument_list|()
expr_stmt|;
name|QGraphicsItem
operator|::
name|mouseReleaseEvent
argument_list|(
name|event
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [12]
end_comment
end_unit
