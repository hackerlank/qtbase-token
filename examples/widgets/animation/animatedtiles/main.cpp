begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of The Qt Company Ltd nor the names of its **     contributors may be used to endorse or promote products derived **     from this software without specific prior written permission. ** ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtWidgets>
end_include
begin_include
include|#
directive|include
file|<QtCore/qmath.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qstate.h>
end_include
begin_class
DECL|class|Pixmap
class|class
name|Pixmap
super|:
specifier|public
name|QObject
super|,
specifier|public
name|QGraphicsPixmapItem
block|{
name|Q_OBJECT
name|Q_PROPERTY
parameter_list|(
name|QPointF
name|pos
name|READ
name|pos
name|WRITE
name|setPos
parameter_list|)
specifier|public
private|:
DECL|function|Pixmap
name|Pixmap
parameter_list|(
specifier|const
name|QPixmap
modifier|&
name|pix
parameter_list|)
member_init_list|:
name|QObject
argument_list|()
member_init_list|,
name|QGraphicsPixmapItem
argument_list|(
name|pix
argument_list|)
block|{
name|setCacheMode
argument_list|(
name|DeviceCoordinateCache
argument_list|)
expr_stmt|;
block|}
block|}
class|;
end_class
begin_class
DECL|class|Button
class|class
name|Button
super|:
specifier|public
name|QGraphicsWidget
block|{
name|Q_OBJECT
public|public:
DECL|function|Button
name|Button
parameter_list|(
specifier|const
name|QPixmap
modifier|&
name|pixmap
parameter_list|,
name|QGraphicsItem
modifier|*
name|parent
init|=
literal|0
parameter_list|)
member_init_list|:
name|QGraphicsWidget
argument_list|(
name|parent
argument_list|)
member_init_list|,
name|_pix
argument_list|(
name|pixmap
argument_list|)
block|{
name|setAcceptHoverEvents
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|setCacheMode
argument_list|(
name|DeviceCoordinateCache
argument_list|)
expr_stmt|;
block|}
name|QRectF
name|boundingRect
parameter_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|{
return|return
name|QRectF
argument_list|(
operator|-
literal|65
argument_list|,
operator|-
literal|65
argument_list|,
literal|130
argument_list|,
literal|130
argument_list|)
return|;
block|}
name|QPainterPath
name|shape
parameter_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|{
name|QPainterPath
name|path
decl_stmt|;
name|path
operator|.
name|addEllipse
argument_list|(
name|boundingRect
argument_list|()
argument_list|)
expr_stmt|;
return|return
name|path
return|;
block|}
name|void
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
name|Q_DECL_OVERRIDE
block|{
name|bool
name|down
init|=
name|option
operator|->
name|state
operator|&
name|QStyle
operator|::
name|State_Sunken
decl_stmt|;
name|QRectF
name|r
init|=
name|boundingRect
argument_list|()
decl_stmt|;
name|QLinearGradient
name|grad
argument_list|(
name|r
operator|.
name|topLeft
argument_list|()
argument_list|,
name|r
operator|.
name|bottomRight
argument_list|()
argument_list|)
decl_stmt|;
name|grad
operator|.
name|setColorAt
argument_list|(
name|down
condition|?
literal|1
else|:
literal|0
argument_list|,
name|option
operator|->
name|state
operator|&
name|QStyle
operator|::
name|State_MouseOver
condition|?
name|Qt
operator|::
name|white
else|:
name|Qt
operator|::
name|lightGray
argument_list|)
expr_stmt|;
name|grad
operator|.
name|setColorAt
argument_list|(
name|down
condition|?
literal|0
else|:
literal|1
argument_list|,
name|Qt
operator|::
name|darkGray
argument_list|)
expr_stmt|;
name|painter
operator|->
name|setPen
argument_list|(
name|Qt
operator|::
name|darkGray
argument_list|)
expr_stmt|;
name|painter
operator|->
name|setBrush
argument_list|(
name|grad
argument_list|)
expr_stmt|;
name|painter
operator|->
name|drawEllipse
argument_list|(
name|r
argument_list|)
expr_stmt|;
name|QLinearGradient
name|grad2
argument_list|(
name|r
operator|.
name|topLeft
argument_list|()
argument_list|,
name|r
operator|.
name|bottomRight
argument_list|()
argument_list|)
decl_stmt|;
name|grad
operator|.
name|setColorAt
argument_list|(
name|down
condition|?
literal|1
else|:
literal|0
argument_list|,
name|Qt
operator|::
name|darkGray
argument_list|)
expr_stmt|;
name|grad
operator|.
name|setColorAt
argument_list|(
name|down
condition|?
literal|0
else|:
literal|1
argument_list|,
name|Qt
operator|::
name|lightGray
argument_list|)
expr_stmt|;
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
name|grad
argument_list|)
expr_stmt|;
if|if
condition|(
name|down
condition|)
name|painter
operator|->
name|translate
argument_list|(
literal|2
argument_list|,
literal|2
argument_list|)
expr_stmt|;
name|painter
operator|->
name|drawEllipse
argument_list|(
name|r
operator|.
name|adjusted
argument_list|(
literal|5
argument_list|,
literal|5
argument_list|,
operator|-
literal|5
argument_list|,
operator|-
literal|5
argument_list|)
argument_list|)
expr_stmt|;
name|painter
operator|->
name|drawPixmap
argument_list|(
operator|-
name|_pix
operator|.
name|width
argument_list|()
operator|/
literal|2
argument_list|,
operator|-
name|_pix
operator|.
name|height
argument_list|()
operator|/
literal|2
argument_list|,
name|_pix
argument_list|)
expr_stmt|;
block|}
signals|signals:
name|void
name|pressed
parameter_list|()
function_decl|;
protected|protected:
name|void
name|mousePressEvent
parameter_list|(
name|QGraphicsSceneMouseEvent
modifier|*
parameter_list|)
name|Q_DECL_OVERRIDE
block|{
emit|emit
name|pressed
argument_list|()
emit|;
name|update
argument_list|()
expr_stmt|;
block|}
name|void
name|mouseReleaseEvent
parameter_list|(
name|QGraphicsSceneMouseEvent
modifier|*
parameter_list|)
name|Q_DECL_OVERRIDE
block|{
name|update
argument_list|()
expr_stmt|;
block|}
private|private:
DECL|member|_pix
name|QPixmap
name|_pix
decl_stmt|;
block|}
class|;
end_class
begin_class
DECL|class|View
class|class
name|View
super|:
specifier|public
name|QGraphicsView
block|{
public|public:
DECL|function|View
name|View
parameter_list|(
name|QGraphicsScene
modifier|*
name|scene
parameter_list|)
member_init_list|:
name|QGraphicsView
argument_list|(
name|scene
argument_list|)
block|{ }
protected|protected:
name|void
name|resizeEvent
parameter_list|(
name|QResizeEvent
modifier|*
name|event
parameter_list|)
name|Q_DECL_OVERRIDE
block|{
name|QGraphicsView
operator|::
name|resizeEvent
argument_list|(
name|event
argument_list|)
expr_stmt|;
name|fitInView
argument_list|(
name|sceneRect
argument_list|()
argument_list|,
name|Qt
operator|::
name|KeepAspectRatio
argument_list|)
expr_stmt|;
block|}
block|}
class|;
end_class
begin_function
DECL|function|main
name|int
name|main
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
modifier|*
name|argv
parameter_list|)
block|{
name|Q_INIT_RESOURCE
argument_list|(
name|animatedtiles
argument_list|)
expr_stmt|;
name|QApplication
name|app
argument_list|(
name|argc
argument_list|,
name|argv
argument_list|)
decl_stmt|;
name|QPixmap
name|kineticPix
argument_list|(
literal|":/images/kinetic.png"
argument_list|)
decl_stmt|;
name|QPixmap
name|bgPix
argument_list|(
literal|":/images/Time-For-Lunch-2.jpg"
argument_list|)
decl_stmt|;
name|QGraphicsScene
name|scene
argument_list|(
operator|-
literal|350
argument_list|,
operator|-
literal|350
argument_list|,
literal|700
argument_list|,
literal|700
argument_list|)
decl_stmt|;
name|QList
argument_list|<
name|Pixmap
modifier|*
argument_list|>
name|items
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
literal|64
condition|;
operator|++
name|i
control|)
block|{
name|Pixmap
modifier|*
name|item
init|=
operator|new
name|Pixmap
argument_list|(
name|kineticPix
argument_list|)
decl_stmt|;
name|item
operator|->
name|setOffset
argument_list|(
operator|-
name|kineticPix
operator|.
name|width
argument_list|()
operator|/
literal|2
argument_list|,
operator|-
name|kineticPix
operator|.
name|height
argument_list|()
operator|/
literal|2
argument_list|)
expr_stmt|;
name|item
operator|->
name|setZValue
argument_list|(
name|i
argument_list|)
expr_stmt|;
name|items
operator|<<
name|item
expr_stmt|;
name|scene
operator|.
name|addItem
argument_list|(
name|item
argument_list|)
expr_stmt|;
block|}
comment|// Buttons
name|QGraphicsItem
modifier|*
name|buttonParent
init|=
operator|new
name|QGraphicsRectItem
decl_stmt|;
name|Button
modifier|*
name|ellipseButton
init|=
operator|new
name|Button
argument_list|(
name|QPixmap
argument_list|(
literal|":/images/ellipse.png"
argument_list|)
argument_list|,
name|buttonParent
argument_list|)
decl_stmt|;
name|Button
modifier|*
name|figure8Button
init|=
operator|new
name|Button
argument_list|(
name|QPixmap
argument_list|(
literal|":/images/figure8.png"
argument_list|)
argument_list|,
name|buttonParent
argument_list|)
decl_stmt|;
name|Button
modifier|*
name|randomButton
init|=
operator|new
name|Button
argument_list|(
name|QPixmap
argument_list|(
literal|":/images/random.png"
argument_list|)
argument_list|,
name|buttonParent
argument_list|)
decl_stmt|;
name|Button
modifier|*
name|tiledButton
init|=
operator|new
name|Button
argument_list|(
name|QPixmap
argument_list|(
literal|":/images/tile.png"
argument_list|)
argument_list|,
name|buttonParent
argument_list|)
decl_stmt|;
name|Button
modifier|*
name|centeredButton
init|=
operator|new
name|Button
argument_list|(
name|QPixmap
argument_list|(
literal|":/images/centered.png"
argument_list|)
argument_list|,
name|buttonParent
argument_list|)
decl_stmt|;
name|ellipseButton
operator|->
name|setPos
argument_list|(
operator|-
literal|100
argument_list|,
operator|-
literal|100
argument_list|)
expr_stmt|;
name|figure8Button
operator|->
name|setPos
argument_list|(
literal|100
argument_list|,
operator|-
literal|100
argument_list|)
expr_stmt|;
name|randomButton
operator|->
name|setPos
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|tiledButton
operator|->
name|setPos
argument_list|(
operator|-
literal|100
argument_list|,
literal|100
argument_list|)
expr_stmt|;
name|centeredButton
operator|->
name|setPos
argument_list|(
literal|100
argument_list|,
literal|100
argument_list|)
expr_stmt|;
name|scene
operator|.
name|addItem
argument_list|(
name|buttonParent
argument_list|)
expr_stmt|;
name|buttonParent
operator|->
name|setTransform
argument_list|(
name|QTransform
operator|::
name|fromScale
argument_list|(
literal|0.75
argument_list|,
literal|0.75
argument_list|)
argument_list|,
literal|true
argument_list|)
expr_stmt|;
name|buttonParent
operator|->
name|setPos
argument_list|(
literal|200
argument_list|,
literal|200
argument_list|)
expr_stmt|;
name|buttonParent
operator|->
name|setZValue
argument_list|(
literal|65
argument_list|)
expr_stmt|;
comment|// States
name|QState
modifier|*
name|rootState
init|=
operator|new
name|QState
decl_stmt|;
name|QState
modifier|*
name|ellipseState
init|=
operator|new
name|QState
argument_list|(
name|rootState
argument_list|)
decl_stmt|;
name|QState
modifier|*
name|figure8State
init|=
operator|new
name|QState
argument_list|(
name|rootState
argument_list|)
decl_stmt|;
name|QState
modifier|*
name|randomState
init|=
operator|new
name|QState
argument_list|(
name|rootState
argument_list|)
decl_stmt|;
name|QState
modifier|*
name|tiledState
init|=
operator|new
name|QState
argument_list|(
name|rootState
argument_list|)
decl_stmt|;
name|QState
modifier|*
name|centeredState
init|=
operator|new
name|QState
argument_list|(
name|rootState
argument_list|)
decl_stmt|;
comment|// Values
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|items
operator|.
name|count
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
name|Pixmap
modifier|*
name|item
init|=
name|items
operator|.
name|at
argument_list|(
name|i
argument_list|)
decl_stmt|;
comment|// Ellipse
name|ellipseState
operator|->
name|assignProperty
argument_list|(
name|item
argument_list|,
literal|"pos"
argument_list|,
name|QPointF
argument_list|(
name|qCos
argument_list|(
operator|(
name|i
operator|/
literal|63.0
operator|)
operator|*
literal|6.28
argument_list|)
operator|*
literal|250
argument_list|,
name|qSin
argument_list|(
operator|(
name|i
operator|/
literal|63.0
operator|)
operator|*
literal|6.28
argument_list|)
operator|*
literal|250
argument_list|)
argument_list|)
expr_stmt|;
comment|// Figure 8
name|figure8State
operator|->
name|assignProperty
argument_list|(
name|item
argument_list|,
literal|"pos"
argument_list|,
name|QPointF
argument_list|(
name|qSin
argument_list|(
operator|(
name|i
operator|/
literal|63.0
operator|)
operator|*
literal|6.28
argument_list|)
operator|*
literal|250
argument_list|,
name|qSin
argument_list|(
operator|(
operator|(
name|i
operator|*
literal|2
operator|)
operator|/
literal|63.0
operator|)
operator|*
literal|6.28
argument_list|)
operator|*
literal|250
argument_list|)
argument_list|)
expr_stmt|;
comment|// Random
name|randomState
operator|->
name|assignProperty
argument_list|(
name|item
argument_list|,
literal|"pos"
argument_list|,
name|QPointF
argument_list|(
operator|-
literal|250
operator|+
name|qrand
argument_list|()
operator|%
literal|500
argument_list|,
operator|-
literal|250
operator|+
name|qrand
argument_list|()
operator|%
literal|500
argument_list|)
argument_list|)
expr_stmt|;
comment|// Tiled
name|tiledState
operator|->
name|assignProperty
argument_list|(
name|item
argument_list|,
literal|"pos"
argument_list|,
name|QPointF
argument_list|(
operator|(
operator|(
name|i
operator|%
literal|8
operator|)
operator|-
literal|4
operator|)
operator|*
name|kineticPix
operator|.
name|width
argument_list|()
operator|+
name|kineticPix
operator|.
name|width
argument_list|()
operator|/
literal|2
argument_list|,
operator|(
operator|(
name|i
operator|/
literal|8
operator|)
operator|-
literal|4
operator|)
operator|*
name|kineticPix
operator|.
name|height
argument_list|()
operator|+
name|kineticPix
operator|.
name|height
argument_list|()
operator|/
literal|2
argument_list|)
argument_list|)
expr_stmt|;
comment|// Centered
name|centeredState
operator|->
name|assignProperty
argument_list|(
name|item
argument_list|,
literal|"pos"
argument_list|,
name|QPointF
argument_list|()
argument_list|)
expr_stmt|;
block|}
comment|// Ui
name|View
modifier|*
name|view
init|=
operator|new
name|View
argument_list|(
operator|&
name|scene
argument_list|)
decl_stmt|;
name|view
operator|->
name|setWindowTitle
argument_list|(
name|QT_TRANSLATE_NOOP
argument_list|(
name|QGraphicsView
argument_list|,
literal|"Animated Tiles"
argument_list|)
argument_list|)
expr_stmt|;
name|view
operator|->
name|setViewportUpdateMode
argument_list|(
name|QGraphicsView
operator|::
name|BoundingRectViewportUpdate
argument_list|)
expr_stmt|;
name|view
operator|->
name|setBackgroundBrush
argument_list|(
name|bgPix
argument_list|)
expr_stmt|;
name|view
operator|->
name|setCacheMode
argument_list|(
name|QGraphicsView
operator|::
name|CacheBackground
argument_list|)
expr_stmt|;
name|view
operator|->
name|setRenderHints
argument_list|(
name|QPainter
operator|::
name|Antialiasing
operator||
name|QPainter
operator|::
name|SmoothPixmapTransform
argument_list|)
expr_stmt|;
name|view
operator|->
name|show
argument_list|()
expr_stmt|;
name|QStateMachine
name|states
decl_stmt|;
name|states
operator|.
name|addState
argument_list|(
name|rootState
argument_list|)
expr_stmt|;
name|states
operator|.
name|setInitialState
argument_list|(
name|rootState
argument_list|)
expr_stmt|;
name|rootState
operator|->
name|setInitialState
argument_list|(
name|centeredState
argument_list|)
expr_stmt|;
name|QParallelAnimationGroup
modifier|*
name|group
init|=
operator|new
name|QParallelAnimationGroup
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
name|items
operator|.
name|count
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
name|QPropertyAnimation
modifier|*
name|anim
init|=
operator|new
name|QPropertyAnimation
argument_list|(
name|items
index|[
name|i
index|]
argument_list|,
literal|"pos"
argument_list|)
decl_stmt|;
name|anim
operator|->
name|setDuration
argument_list|(
literal|750
operator|+
name|i
operator|*
literal|25
argument_list|)
expr_stmt|;
name|anim
operator|->
name|setEasingCurve
argument_list|(
name|QEasingCurve
operator|::
name|InOutBack
argument_list|)
expr_stmt|;
name|group
operator|->
name|addAnimation
argument_list|(
name|anim
argument_list|)
expr_stmt|;
block|}
name|QAbstractTransition
modifier|*
name|trans
init|=
name|rootState
operator|->
name|addTransition
argument_list|(
name|ellipseButton
argument_list|,
name|SIGNAL
argument_list|(
name|pressed
argument_list|()
argument_list|)
argument_list|,
name|ellipseState
argument_list|)
decl_stmt|;
name|trans
operator|->
name|addAnimation
argument_list|(
name|group
argument_list|)
expr_stmt|;
name|trans
operator|=
name|rootState
operator|->
name|addTransition
argument_list|(
name|figure8Button
argument_list|,
name|SIGNAL
argument_list|(
name|pressed
argument_list|()
argument_list|)
argument_list|,
name|figure8State
argument_list|)
expr_stmt|;
name|trans
operator|->
name|addAnimation
argument_list|(
name|group
argument_list|)
expr_stmt|;
name|trans
operator|=
name|rootState
operator|->
name|addTransition
argument_list|(
name|randomButton
argument_list|,
name|SIGNAL
argument_list|(
name|pressed
argument_list|()
argument_list|)
argument_list|,
name|randomState
argument_list|)
expr_stmt|;
name|trans
operator|->
name|addAnimation
argument_list|(
name|group
argument_list|)
expr_stmt|;
name|trans
operator|=
name|rootState
operator|->
name|addTransition
argument_list|(
name|tiledButton
argument_list|,
name|SIGNAL
argument_list|(
name|pressed
argument_list|()
argument_list|)
argument_list|,
name|tiledState
argument_list|)
expr_stmt|;
name|trans
operator|->
name|addAnimation
argument_list|(
name|group
argument_list|)
expr_stmt|;
name|trans
operator|=
name|rootState
operator|->
name|addTransition
argument_list|(
name|centeredButton
argument_list|,
name|SIGNAL
argument_list|(
name|pressed
argument_list|()
argument_list|)
argument_list|,
name|centeredState
argument_list|)
expr_stmt|;
name|trans
operator|->
name|addAnimation
argument_list|(
name|group
argument_list|)
expr_stmt|;
name|QTimer
name|timer
decl_stmt|;
name|timer
operator|.
name|start
argument_list|(
literal|125
argument_list|)
expr_stmt|;
name|timer
operator|.
name|setSingleShot
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|trans
operator|=
name|rootState
operator|->
name|addTransition
argument_list|(
operator|&
name|timer
argument_list|,
name|SIGNAL
argument_list|(
name|timeout
argument_list|()
argument_list|)
argument_list|,
name|ellipseState
argument_list|)
expr_stmt|;
name|trans
operator|->
name|addAnimation
argument_list|(
name|group
argument_list|)
expr_stmt|;
name|states
operator|.
name|start
argument_list|()
expr_stmt|;
ifdef|#
directive|ifdef
name|QT_KEYPAD_NAVIGATION
name|QApplication
operator|::
name|setNavigationMode
argument_list|(
name|Qt
operator|::
name|NavigationModeCursorAuto
argument_list|)
expr_stmt|;
endif|#
directive|endif
return|return
name|app
operator|.
name|exec
argument_list|()
return|;
block|}
end_function
begin_include
include|#
directive|include
file|"main.moc"
end_include
end_unit
