begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QGraphicsWidget>
end_include
begin_include
include|#
directive|include
file|<QPainter>
end_include
begin_include
include|#
directive|include
file|<QGraphicsSceneMouseEvent>
end_include
begin_include
include|#
directive|include
file|<QDebug>
end_include
begin_include
include|#
directive|include
file|"scrollbar.h"
end_include
begin_include
include|#
directive|include
file|"theme.h"
end_include
begin_class
DECL|class|ScrollBarPrivate
class|class
name|ScrollBarPrivate
block|{
name|Q_DECLARE_PUBLIC
parameter_list|(
name|ScrollBar
parameter_list|)
specifier|public
private|:
DECL|function|ScrollBarPrivate
name|ScrollBarPrivate
parameter_list|(
name|Qt
operator|::
name|Orientation
name|orientation
parameter_list|,
name|ScrollBar
modifier|*
name|scrollBar
parameter_list|)
member_init_list|:
name|orientation
argument_list|(
name|orientation
argument_list|)
member_init_list|,
name|sliderPosition
argument_list|(
literal|0.0
argument_list|)
member_init_list|,
name|sliderSize
argument_list|(
literal|0.0
argument_list|)
member_init_list|,
name|sliderDown
argument_list|(
literal|false
argument_list|)
member_init_list|,
name|q_ptr
argument_list|(
name|scrollBar
argument_list|)
block|{
name|construct
argument_list|()
expr_stmt|;
block|}
DECL|function|themeChange
name|void
name|themeChange
parameter_list|()
block|{
name|construct
argument_list|()
expr_stmt|;
name|updateSlider
argument_list|()
expr_stmt|;
block|}
DECL|function|construct
name|void
name|construct
parameter_list|()
block|{
name|scrollerPixmap
operator|=
name|Theme
operator|::
name|p
argument_list|()
operator|->
name|pixmap
argument_list|(
literal|"scroll.svg"
argument_list|)
expr_stmt|;
name|scrollBarPixmap
operator|=
name|Theme
operator|::
name|p
argument_list|()
operator|->
name|pixmap
argument_list|(
literal|"scrollbar.svg"
argument_list|)
expr_stmt|;
if|if
condition|(
name|orientation
operator|==
name|Qt
operator|::
name|Horizontal
condition|)
block|{
name|scrollerPixmap
operator|=
name|scrollerPixmap
operator|.
name|transformed
argument_list|(
name|QTransform
argument_list|()
operator|.
name|rotate
argument_list|(
literal|90
argument_list|)
argument_list|)
expr_stmt|;
name|scrollBarPixmap
operator|=
name|scrollBarPixmap
operator|.
name|transformed
argument_list|(
name|QTransform
argument_list|()
operator|.
name|rotate
argument_list|(
literal|90
argument_list|)
argument_list|)
expr_stmt|;
block|}
block|}
DECL|function|setSliderPosition
name|void
name|setSliderPosition
parameter_list|(
name|qreal
name|pos
parameter_list|)
block|{
if|if
condition|(
name|pos
operator|<
literal|0.0
condition|)
name|pos
operator|=
literal|0.0
expr_stmt|;
if|if
condition|(
name|pos
operator|>
name|sliderSize
condition|)
name|pos
operator|=
name|sliderSize
expr_stmt|;
name|sliderPosition
operator|=
name|pos
expr_stmt|;
if|if
condition|(
operator|!
name|qFuzzyCompare
argument_list|(
name|pos
argument_list|,
name|sliderPosition
argument_list|)
condition|)
name|updateSlider
argument_list|()
expr_stmt|;
block|}
DECL|function|updateSlider
name|void
name|updateSlider
parameter_list|()
block|{
name|QRectF
name|oldSlider
init|=
name|slider
decl_stmt|;
name|slider
operator|=
name|q_func
argument_list|()
operator|->
name|boundingRect
argument_list|()
expr_stmt|;
name|qreal
name|x
init|=
literal|0
decl_stmt|;
name|qreal
name|y
init|=
literal|0
decl_stmt|;
name|qreal
name|w
init|=
name|scrollerPixmap
operator|.
name|width
argument_list|()
decl_stmt|;
name|qreal
name|h
init|=
name|scrollerPixmap
operator|.
name|height
argument_list|()
decl_stmt|;
comment|//Adjust the scrollBar in relation to the scroller
if|if
condition|(
name|orientation
operator|==
name|Qt
operator|::
name|Horizontal
condition|)
block|{
name|qreal
name|scrollBarHeight
init|=
name|scrollBarPixmap
operator|.
name|height
argument_list|()
decl_stmt|;
if|if
condition|(
name|h
operator|>
name|scrollBarHeight
condition|)
block|{
name|slider
operator|.
name|setTop
argument_list|(
operator|(
name|h
operator|-
name|scrollBarHeight
operator|)
operator|/
literal|2.0
argument_list|)
expr_stmt|;
name|slider
operator|.
name|setHeight
argument_list|(
name|scrollBarHeight
argument_list|)
expr_stmt|;
block|}
block|}
else|else
block|{
name|qreal
name|scrollBarWidth
init|=
name|scrollBarPixmap
operator|.
name|width
argument_list|()
decl_stmt|;
if|if
condition|(
name|w
operator|>
name|scrollBarWidth
condition|)
block|{
name|slider
operator|.
name|setLeft
argument_list|(
operator|(
name|w
operator|-
name|scrollBarWidth
operator|)
operator|/
literal|2.0
argument_list|)
expr_stmt|;
block|}
name|slider
operator|.
name|setWidth
argument_list|(
name|scrollBarWidth
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|oldSlider
operator|!=
name|slider
operator|&&
operator|(
name|slider
operator|.
name|size
argument_list|()
operator|.
name|width
argument_list|()
operator|>
literal|0
operator|&&
name|slider
operator|.
name|size
argument_list|()
operator|.
name|height
argument_list|()
operator|>
literal|0
operator|)
condition|)
block|{
name|scrollBarPixmap
operator|=
name|Theme
operator|::
name|p
argument_list|()
operator|->
name|pixmap
argument_list|(
literal|"scrollbar.svg"
argument_list|,
name|slider
operator|.
name|size
argument_list|()
operator|.
name|toSize
argument_list|()
argument_list|)
expr_stmt|;
block|}
name|cursor
operator|=
name|QRectF
argument_list|(
name|x
argument_list|,
name|y
argument_list|,
name|w
argument_list|,
name|h
argument_list|)
expr_stmt|;
if|if
condition|(
name|orientation
operator|==
name|Qt
operator|::
name|Horizontal
condition|)
block|{
name|qreal
name|dx
init|=
name|qreal
argument_list|(
name|int
argument_list|(
name|sliderPosition
argument_list|)
argument_list|)
operator|*
operator|(
name|slider
operator|.
name|width
argument_list|()
operator|-
name|cursor
operator|.
name|width
argument_list|()
operator|)
operator|/
name|sliderSize
decl_stmt|;
name|cursor
operator|.
name|translate
argument_list|(
name|dx
argument_list|,
literal|0.0
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|qreal
name|dy
init|=
name|qreal
argument_list|(
name|int
argument_list|(
name|sliderPosition
argument_list|)
argument_list|)
operator|*
operator|(
name|slider
operator|.
name|height
argument_list|()
operator|-
name|cursor
operator|.
name|height
argument_list|()
operator|)
operator|/
name|sliderSize
decl_stmt|;
name|cursor
operator|.
name|translate
argument_list|(
literal|0.0
argument_list|,
name|dy
argument_list|)
expr_stmt|;
block|}
block|}
DECL|member|orientation
name|Qt
operator|::
name|Orientation
name|orientation
decl_stmt|;
DECL|member|sliderPosition
name|qreal
name|sliderPosition
decl_stmt|;
DECL|member|sliderSize
name|qreal
name|sliderSize
decl_stmt|;
DECL|member|pressPos
name|QPointF
name|pressPos
decl_stmt|;
DECL|member|sliderDown
name|bool
name|sliderDown
decl_stmt|;
DECL|member|slider
name|QRectF
name|slider
decl_stmt|;
DECL|member|cursor
name|QRectF
name|cursor
decl_stmt|;
DECL|member|scrollerPixmap
name|QPixmap
name|scrollerPixmap
decl_stmt|;
DECL|member|scrollBarPixmap
name|QPixmap
name|scrollBarPixmap
decl_stmt|;
DECL|member|q_ptr
name|ScrollBar
modifier|*
name|q_ptr
decl_stmt|;
block|}
class|;
end_class
begin_constructor
DECL|function|ScrollBar
name|ScrollBar
operator|::
name|ScrollBar
parameter_list|(
name|Qt
operator|::
name|Orientation
name|orientation
parameter_list|,
name|QGraphicsWidget
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QGraphicsWidget
argument_list|(
name|parent
argument_list|)
member_init_list|,
name|d_ptr
argument_list|(
operator|new
name|ScrollBarPrivate
argument_list|(
name|orientation
argument_list|,
name|this
argument_list|)
argument_list|)
block|{
name|setSizePolicy
argument_list|(
name|QSizePolicy
operator|::
name|Fixed
argument_list|,
name|QSizePolicy
operator|::
name|MinimumExpanding
argument_list|)
expr_stmt|;
name|setContentsMargins
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|Theme
operator|::
name|p
argument_list|()
argument_list|,
name|SIGNAL
argument_list|(
name|themeChanged
argument_list|()
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|themeChange
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_destructor
DECL|function|~ScrollBar
name|ScrollBar
operator|::
name|~
name|ScrollBar
parameter_list|()
block|{
operator|delete
name|d_ptr
expr_stmt|;
block|}
end_destructor
begin_function
DECL|function|sliderSize
name|qreal
name|ScrollBar
operator|::
name|sliderSize
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|ScrollBar
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|sliderSize
return|;
block|}
end_function
begin_function
DECL|function|setSliderSize
name|void
name|ScrollBar
operator|::
name|setSliderSize
parameter_list|(
specifier|const
name|qreal
name|s
parameter_list|)
block|{
name|Q_D
argument_list|(
name|ScrollBar
argument_list|)
expr_stmt|;
name|d
operator|->
name|sliderSize
operator|=
name|s
expr_stmt|;
block|}
end_function
begin_function
DECL|function|setSliderPosition
name|void
name|ScrollBar
operator|::
name|setSliderPosition
parameter_list|(
name|qreal
name|pos
parameter_list|)
block|{
name|Q_D
argument_list|(
name|ScrollBar
argument_list|)
expr_stmt|;
name|d
operator|->
name|setSliderPosition
argument_list|(
name|pos
argument_list|)
expr_stmt|;
name|prepareGeometryChange
argument_list|()
expr_stmt|;
emit|emit
name|sliderPositionChange
argument_list|(
name|d
operator|->
name|sliderPosition
argument_list|)
emit|;
block|}
end_function
begin_function
DECL|function|sliderPosition
name|qreal
name|ScrollBar
operator|::
name|sliderPosition
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|ScrollBar
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|sliderPosition
return|;
block|}
end_function
begin_function
DECL|function|sliderDown
name|bool
name|ScrollBar
operator|::
name|sliderDown
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|ScrollBar
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|sliderDown
return|;
block|}
end_function
begin_function
DECL|function|paint
name|void
name|ScrollBar
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
name|widget
parameter_list|)
block|{
name|Q_D
argument_list|(
name|ScrollBar
argument_list|)
expr_stmt|;
name|Q_UNUSED
argument_list|(
name|widget
argument_list|)
expr_stmt|;
name|Q_UNUSED
argument_list|(
name|option
argument_list|)
expr_stmt|;
name|d
operator|->
name|updateSlider
argument_list|()
expr_stmt|;
name|QRect
name|sliderRect
init|=
name|d
operator|->
name|slider
operator|.
name|toRect
argument_list|()
decl_stmt|;
name|painter
operator|->
name|drawPixmap
argument_list|(
name|sliderRect
operator|.
name|topLeft
argument_list|()
argument_list|,
name|d
operator|->
name|scrollBarPixmap
argument_list|)
expr_stmt|;
name|QRect
name|cursorRect
init|=
name|d
operator|->
name|cursor
operator|.
name|toRect
argument_list|()
decl_stmt|;
name|painter
operator|->
name|drawPixmap
argument_list|(
name|cursorRect
operator|.
name|topLeft
argument_list|()
argument_list|,
name|d
operator|->
name|scrollerPixmap
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|sizeHint
name|QSizeF
name|ScrollBar
operator|::
name|sizeHint
parameter_list|(
name|Qt
operator|::
name|SizeHint
name|which
parameter_list|,
specifier|const
name|QSizeF
modifier|&
name|constraint
parameter_list|)
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|ScrollBar
argument_list|)
expr_stmt|;
name|QSizeF
name|s
decl_stmt|;
if|if
condition|(
name|d
operator|->
name|orientation
operator|==
name|Qt
operator|::
name|Horizontal
condition|)
name|s
operator|=
name|QSizeF
argument_list|(
operator|-
literal|1
argument_list|,
name|qMax
argument_list|(
name|d
operator|->
name|scrollBarPixmap
operator|.
name|height
argument_list|()
argument_list|,
name|d
operator|->
name|scrollerPixmap
operator|.
name|height
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
else|else
name|s
operator|=
name|QSizeF
argument_list|(
name|qMax
argument_list|(
name|d
operator|->
name|scrollBarPixmap
operator|.
name|width
argument_list|()
argument_list|,
name|d
operator|->
name|scrollerPixmap
operator|.
name|width
argument_list|()
argument_list|)
argument_list|,
operator|-
literal|1
argument_list|)
expr_stmt|;
switch|switch
condition|(
name|which
condition|)
block|{
case|case
name|Qt
operator|::
name|MinimumSize
case|:
return|return
name|s
return|;
case|case
name|Qt
operator|::
name|MaximumSize
case|:
return|return
name|s
return|;
default|default:
return|return
name|QGraphicsWidget
operator|::
name|sizeHint
argument_list|(
name|which
argument_list|,
name|constraint
argument_list|)
return|;
block|}
block|}
end_function
begin_function
DECL|function|mousePressEvent
name|void
name|ScrollBar
operator|::
name|mousePressEvent
parameter_list|(
name|QGraphicsSceneMouseEvent
modifier|*
name|event
parameter_list|)
block|{
name|Q_D
argument_list|(
name|ScrollBar
argument_list|)
expr_stmt|;
name|d
operator|->
name|updateSlider
argument_list|()
expr_stmt|;
if|if
condition|(
name|d
operator|->
name|cursor
operator|.
name|contains
argument_list|(
name|event
operator|->
name|pos
argument_list|()
argument_list|)
condition|)
block|{
name|d
operator|->
name|sliderDown
operator|=
literal|true
expr_stmt|;
name|d
operator|->
name|pressPos
operator|=
name|event
operator|->
name|pos
argument_list|()
expr_stmt|;
emit|emit
name|sliderPressed
argument_list|()
emit|;
block|}
block|}
end_function
begin_function
DECL|function|mouseReleaseEvent
name|void
name|ScrollBar
operator|::
name|mouseReleaseEvent
parameter_list|(
name|QGraphicsSceneMouseEvent
modifier|*
name|event
parameter_list|)
block|{
name|Q_D
argument_list|(
name|ScrollBar
argument_list|)
expr_stmt|;
name|Q_UNUSED
argument_list|(
name|event
argument_list|)
expr_stmt|;
name|d
operator|->
name|sliderDown
operator|=
literal|false
expr_stmt|;
block|}
end_function
begin_function
DECL|function|mouseMoveEvent
name|void
name|ScrollBar
operator|::
name|mouseMoveEvent
parameter_list|(
name|QGraphicsSceneMouseEvent
modifier|*
name|event
parameter_list|)
block|{
name|Q_D
argument_list|(
name|ScrollBar
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|d
operator|->
name|sliderDown
condition|)
return|return;
if|if
condition|(
name|d
operator|->
name|orientation
operator|==
name|Qt
operator|::
name|Horizontal
condition|)
block|{
name|qreal
name|f
init|=
operator|(
name|event
operator|->
name|pos
argument_list|()
operator|.
name|x
argument_list|()
operator|-
name|d
operator|->
name|pressPos
operator|.
name|x
argument_list|()
operator|)
operator|/
operator|(
name|d
operator|->
name|slider
operator|.
name|width
argument_list|()
operator|-
name|d
operator|->
name|cursor
operator|.
name|width
argument_list|()
operator|)
decl_stmt|;
name|qreal
name|dx
init|=
name|f
operator|*
name|d
operator|->
name|sliderSize
decl_stmt|;
name|d
operator|->
name|setSliderPosition
argument_list|(
name|d
operator|->
name|sliderPosition
operator|+
name|dx
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|qreal
name|f
init|=
operator|(
name|event
operator|->
name|pos
argument_list|()
operator|.
name|y
argument_list|()
operator|-
name|d
operator|->
name|pressPos
operator|.
name|y
argument_list|()
operator|)
operator|/
operator|(
name|d
operator|->
name|slider
operator|.
name|height
argument_list|()
operator|-
name|d
operator|->
name|cursor
operator|.
name|height
argument_list|()
operator|)
decl_stmt|;
name|qreal
name|dy
init|=
name|f
operator|*
name|d
operator|->
name|sliderSize
decl_stmt|;
name|d
operator|->
name|setSliderPosition
argument_list|(
name|d
operator|->
name|sliderPosition
operator|+
name|dy
argument_list|)
expr_stmt|;
block|}
name|d
operator|->
name|pressPos
operator|=
name|event
operator|->
name|pos
argument_list|()
expr_stmt|;
name|prepareGeometryChange
argument_list|()
expr_stmt|;
emit|emit
name|sliderPositionChange
argument_list|(
name|d
operator|->
name|sliderPosition
argument_list|)
emit|;
block|}
end_function
begin_function
DECL|function|resizeEvent
name|void
name|ScrollBar
operator|::
name|resizeEvent
parameter_list|(
name|QGraphicsSceneResizeEvent
modifier|*
name|event
parameter_list|)
block|{
name|QGraphicsWidget
operator|::
name|resizeEvent
argument_list|(
name|event
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|themeChange
name|void
name|ScrollBar
operator|::
name|themeChange
parameter_list|()
block|{
name|Q_D
argument_list|(
name|ScrollBar
argument_list|)
expr_stmt|;
name|d
operator|->
name|themeChange
argument_list|()
expr_stmt|;
block|}
end_function
end_unit
