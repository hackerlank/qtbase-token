begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of Nokia Corporation and its Subsidiary(-ies) nor **     the names of its contributors may be used to endorse or promote **     products derived from this software without specific prior written **     permission. ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"lighting.h"
end_include
begin_include
include|#
directive|include
file|<QtWidgets>
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|M_PI
end_ifndef
begin_define
DECL|macro|M_PI
define|#
directive|define
name|M_PI
value|3.14159265358979323846
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_constructor
DECL|function|Lighting
name|Lighting
operator|::
name|Lighting
parameter_list|(
name|QWidget
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QGraphicsView
argument_list|(
name|parent
argument_list|)
member_init_list|,
name|angle
argument_list|(
literal|0.0
argument_list|)
block|{
name|setScene
argument_list|(
operator|&
name|m_scene
argument_list|)
expr_stmt|;
name|setupScene
argument_list|()
expr_stmt|;
name|QTimer
modifier|*
name|timer
init|=
operator|new
name|QTimer
argument_list|(
name|this
argument_list|)
decl_stmt|;
name|connect
argument_list|(
name|timer
argument_list|,
name|SIGNAL
argument_list|(
name|timeout
argument_list|()
argument_list|)
argument_list|,
name|SLOT
argument_list|(
name|animate
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|timer
operator|->
name|setInterval
argument_list|(
literal|30
argument_list|)
expr_stmt|;
name|timer
operator|->
name|start
argument_list|()
expr_stmt|;
name|setRenderHint
argument_list|(
name|QPainter
operator|::
name|Antialiasing
argument_list|,
literal|true
argument_list|)
expr_stmt|;
name|setFrameStyle
argument_list|(
name|QFrame
operator|::
name|NoFrame
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_function
DECL|function|setupScene
name|void
name|Lighting
operator|::
name|setupScene
parameter_list|()
block|{
name|m_scene
operator|.
name|setSceneRect
argument_list|(
operator|-
literal|300
argument_list|,
operator|-
literal|200
argument_list|,
literal|600
argument_list|,
literal|460
argument_list|)
expr_stmt|;
name|QLinearGradient
name|linearGrad
argument_list|(
name|QPointF
argument_list|(
operator|-
literal|100
argument_list|,
operator|-
literal|100
argument_list|)
argument_list|,
name|QPointF
argument_list|(
literal|100
argument_list|,
literal|100
argument_list|)
argument_list|)
decl_stmt|;
name|linearGrad
operator|.
name|setColorAt
argument_list|(
literal|0
argument_list|,
name|QColor
argument_list|(
literal|255
argument_list|,
literal|255
argument_list|,
literal|255
argument_list|)
argument_list|)
expr_stmt|;
name|linearGrad
operator|.
name|setColorAt
argument_list|(
literal|1
argument_list|,
name|QColor
argument_list|(
literal|192
argument_list|,
literal|192
argument_list|,
literal|255
argument_list|)
argument_list|)
expr_stmt|;
name|setBackgroundBrush
argument_list|(
name|linearGrad
argument_list|)
expr_stmt|;
name|QRadialGradient
name|radialGrad
argument_list|(
literal|30
argument_list|,
literal|30
argument_list|,
literal|30
argument_list|)
decl_stmt|;
name|radialGrad
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
name|radialGrad
operator|.
name|setColorAt
argument_list|(
literal|0.2
argument_list|,
name|Qt
operator|::
name|yellow
argument_list|)
expr_stmt|;
name|radialGrad
operator|.
name|setColorAt
argument_list|(
literal|1
argument_list|,
name|Qt
operator|::
name|transparent
argument_list|)
expr_stmt|;
name|QPixmap
name|pixmap
argument_list|(
literal|60
argument_list|,
literal|60
argument_list|)
decl_stmt|;
name|pixmap
operator|.
name|fill
argument_list|(
name|Qt
operator|::
name|transparent
argument_list|)
expr_stmt|;
name|QPainter
name|painter
argument_list|(
operator|&
name|pixmap
argument_list|)
decl_stmt|;
name|painter
operator|.
name|setPen
argument_list|(
name|Qt
operator|::
name|NoPen
argument_list|)
expr_stmt|;
name|painter
operator|.
name|setBrush
argument_list|(
name|radialGrad
argument_list|)
expr_stmt|;
name|painter
operator|.
name|drawEllipse
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|60
argument_list|,
literal|60
argument_list|)
expr_stmt|;
name|painter
operator|.
name|end
argument_list|()
expr_stmt|;
name|m_lightSource
operator|=
name|m_scene
operator|.
name|addPixmap
argument_list|(
name|pixmap
argument_list|)
expr_stmt|;
name|m_lightSource
operator|->
name|setZValue
argument_list|(
literal|2
argument_list|)
expr_stmt|;
for|for
control|(
name|int
name|i
init|=
operator|-
literal|2
init|;
name|i
operator|<
literal|3
condition|;
operator|++
name|i
control|)
for|for
control|(
name|int
name|j
init|=
operator|-
literal|2
init|;
name|j
operator|<
literal|3
condition|;
operator|++
name|j
control|)
block|{
name|QAbstractGraphicsShapeItem
modifier|*
name|item
decl_stmt|;
if|if
condition|(
operator|(
name|i
operator|+
name|j
operator|)
operator|&
literal|1
condition|)
name|item
operator|=
operator|new
name|QGraphicsEllipseItem
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|50
argument_list|,
literal|50
argument_list|)
expr_stmt|;
else|else
name|item
operator|=
operator|new
name|QGraphicsRectItem
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|50
argument_list|,
literal|50
argument_list|)
expr_stmt|;
name|item
operator|->
name|setPen
argument_list|(
name|QPen
argument_list|(
name|Qt
operator|::
name|black
argument_list|,
literal|1
argument_list|)
argument_list|)
expr_stmt|;
name|item
operator|->
name|setBrush
argument_list|(
name|QBrush
argument_list|(
name|Qt
operator|::
name|white
argument_list|)
argument_list|)
expr_stmt|;
name|QGraphicsDropShadowEffect
modifier|*
name|effect
init|=
operator|new
name|QGraphicsDropShadowEffect
decl_stmt|;
name|effect
operator|->
name|setBlurRadius
argument_list|(
literal|8
argument_list|)
expr_stmt|;
name|item
operator|->
name|setGraphicsEffect
argument_list|(
name|effect
argument_list|)
expr_stmt|;
name|item
operator|->
name|setZValue
argument_list|(
literal|1
argument_list|)
expr_stmt|;
name|item
operator|->
name|setPos
argument_list|(
name|i
operator|*
literal|80
argument_list|,
name|j
operator|*
literal|80
argument_list|)
expr_stmt|;
name|m_scene
operator|.
name|addItem
argument_list|(
name|item
argument_list|)
expr_stmt|;
name|m_items
operator|<<
name|item
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|animate
name|void
name|Lighting
operator|::
name|animate
parameter_list|()
block|{
name|angle
operator|+=
operator|(
name|M_PI
operator|/
literal|30
operator|)
expr_stmt|;
name|qreal
name|xs
init|=
literal|200
operator|*
name|sin
argument_list|(
name|angle
argument_list|)
operator|-
literal|40
operator|+
literal|25
decl_stmt|;
name|qreal
name|ys
init|=
literal|200
operator|*
name|cos
argument_list|(
name|angle
argument_list|)
operator|-
literal|40
operator|+
literal|25
decl_stmt|;
name|m_lightSource
operator|->
name|setPos
argument_list|(
name|xs
argument_list|,
name|ys
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
name|m_items
operator|.
name|size
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
name|QGraphicsItem
modifier|*
name|item
init|=
name|m_items
operator|.
name|at
argument_list|(
name|i
argument_list|)
decl_stmt|;
name|Q_ASSERT
argument_list|(
name|item
argument_list|)
expr_stmt|;
name|QGraphicsDropShadowEffect
modifier|*
name|effect
init|=
cast|static_cast
argument_list|<
name|QGraphicsDropShadowEffect
operator|*
argument_list|>
argument_list|(
name|item
operator|->
name|graphicsEffect
argument_list|()
argument_list|)
decl_stmt|;
name|Q_ASSERT
argument_list|(
name|effect
argument_list|)
expr_stmt|;
name|QPointF
name|delta
argument_list|(
name|item
operator|->
name|x
argument_list|()
operator|-
name|xs
argument_list|,
name|item
operator|->
name|y
argument_list|()
operator|-
name|ys
argument_list|)
decl_stmt|;
name|effect
operator|->
name|setOffset
argument_list|(
name|delta
operator|.
name|toPoint
argument_list|()
operator|/
literal|30
argument_list|)
expr_stmt|;
name|qreal
name|dx
init|=
name|delta
operator|.
name|x
argument_list|()
decl_stmt|;
name|qreal
name|dy
init|=
name|delta
operator|.
name|y
argument_list|()
decl_stmt|;
name|qreal
name|dd
init|=
name|sqrt
argument_list|(
name|dx
operator|*
name|dx
operator|+
name|dy
operator|*
name|dy
argument_list|)
decl_stmt|;
name|QColor
name|color
init|=
name|effect
operator|->
name|color
argument_list|()
decl_stmt|;
name|color
operator|.
name|setAlphaF
argument_list|(
name|qBound
argument_list|(
literal|0.4
argument_list|,
literal|1
operator|-
name|dd
operator|/
literal|200.0
argument_list|,
literal|0.7
argument_list|)
argument_list|)
expr_stmt|;
name|effect
operator|->
name|setColor
argument_list|(
name|color
argument_list|)
expr_stmt|;
block|}
name|m_scene
operator|.
name|update
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|resizeEvent
name|void
name|Lighting
operator|::
name|resizeEvent
parameter_list|(
name|QResizeEvent
modifier|*
comment|/*event*/
parameter_list|)
block|{ }
end_function
end_unit
