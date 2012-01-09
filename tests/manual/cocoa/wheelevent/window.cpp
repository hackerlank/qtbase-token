begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"window.h"
end_include
begin_include
include|#
directive|include
file|<private/qguiapplication_p.h>
end_include
begin_include
include|#
directive|include
file|<QBackingStore>
end_include
begin_include
include|#
directive|include
file|<QPainter>
end_include
begin_include
include|#
directive|include
file|<QtGui>
end_include
begin_decl_stmt
DECL|variable|colorIndexId
specifier|static
name|int
name|colorIndexId
init|=
literal|0
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|colorTable
name|QColor
name|colorTable
index|[]
init|=
block|{
name|QColor
argument_list|(
literal|"#f09f8f"
argument_list|)
block|,
name|QColor
argument_list|(
literal|"#a2bff2"
argument_list|)
block|,
name|QColor
argument_list|(
literal|"#c0ef8f"
argument_list|)
block|}
decl_stmt|;
end_decl_stmt
begin_constructor
DECL|function|Window
name|Window
operator|::
name|Window
parameter_list|(
name|QScreen
modifier|*
name|screen
parameter_list|)
member_init_list|:
name|QWindow
argument_list|(
name|screen
argument_list|)
member_init_list|,
name|m_backgroundColorIndex
argument_list|(
name|colorIndexId
operator|++
argument_list|)
block|{
name|initialize
argument_list|()
expr_stmt|;
block|}
end_constructor
begin_constructor
DECL|function|Window
name|Window
operator|::
name|Window
parameter_list|(
name|QWindow
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QWindow
argument_list|(
name|parent
argument_list|)
member_init_list|,
name|m_backgroundColorIndex
argument_list|(
name|colorIndexId
operator|++
argument_list|)
block|{
name|initialize
argument_list|()
expr_stmt|;
block|}
end_constructor
begin_function
DECL|function|initialize
name|void
name|Window
operator|::
name|initialize
parameter_list|()
block|{
if|if
condition|(
name|parent
argument_list|()
condition|)
name|setGeometry
argument_list|(
name|QRect
argument_list|(
literal|160
argument_list|,
literal|120
argument_list|,
literal|320
argument_list|,
literal|240
argument_list|)
argument_list|)
expr_stmt|;
else|else
block|{
name|setGeometry
argument_list|(
name|QRect
argument_list|(
literal|10
argument_list|,
literal|10
argument_list|,
literal|640
argument_list|,
literal|480
argument_list|)
argument_list|)
expr_stmt|;
name|setSizeIncrement
argument_list|(
name|QSize
argument_list|(
literal|10
argument_list|,
literal|10
argument_list|)
argument_list|)
expr_stmt|;
name|setBaseSize
argument_list|(
name|QSize
argument_list|(
literal|640
argument_list|,
literal|480
argument_list|)
argument_list|)
expr_stmt|;
name|setMinimumSize
argument_list|(
name|QSize
argument_list|(
literal|240
argument_list|,
literal|160
argument_list|)
argument_list|)
expr_stmt|;
name|setMaximumSize
argument_list|(
name|QSize
argument_list|(
literal|800
argument_list|,
literal|600
argument_list|)
argument_list|)
expr_stmt|;
block|}
name|create
argument_list|()
expr_stmt|;
name|m_backingStore
operator|=
operator|new
name|QBackingStore
argument_list|(
name|this
argument_list|)
expr_stmt|;
name|m_image
operator|=
name|QImage
argument_list|(
name|geometry
argument_list|()
operator|.
name|size
argument_list|()
argument_list|,
name|QImage
operator|::
name|Format_RGB32
argument_list|)
expr_stmt|;
name|m_image
operator|.
name|fill
argument_list|(
name|colorTable
index|[
name|m_backgroundColorIndex
operator|%
operator|(
sizeof|sizeof
argument_list|(
name|colorTable
argument_list|)
operator|/
sizeof|sizeof
argument_list|(
name|colorTable
index|[
literal|0
index|]
argument_list|)
operator|)
index|]
operator|.
name|rgba
argument_list|()
argument_list|)
expr_stmt|;
name|m_lastPos
operator|=
name|QPoint
argument_list|(
operator|-
literal|1
argument_list|,
operator|-
literal|1
argument_list|)
expr_stmt|;
name|m_renderTimer
operator|=
literal|0
expr_stmt|;
block|}
end_function
begin_function
DECL|function|mousePressEvent
name|void
name|Window
operator|::
name|mousePressEvent
parameter_list|(
name|QMouseEvent
modifier|*
name|event
parameter_list|)
block|{
name|m_lastPos
operator|=
name|event
operator|->
name|pos
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|mouseMoveEvent
name|void
name|Window
operator|::
name|mouseMoveEvent
parameter_list|(
name|QMouseEvent
modifier|*
name|event
parameter_list|)
block|{
if|if
condition|(
name|m_lastPos
operator|!=
name|QPoint
argument_list|(
operator|-
literal|1
argument_list|,
operator|-
literal|1
argument_list|)
condition|)
block|{
name|QPainter
name|p
argument_list|(
operator|&
name|m_image
argument_list|)
decl_stmt|;
name|p
operator|.
name|setRenderHint
argument_list|(
name|QPainter
operator|::
name|Antialiasing
argument_list|)
expr_stmt|;
name|p
operator|.
name|drawLine
argument_list|(
name|m_lastPos
argument_list|,
name|event
operator|->
name|pos
argument_list|()
argument_list|)
expr_stmt|;
name|m_lastPos
operator|=
name|event
operator|->
name|pos
argument_list|()
expr_stmt|;
block|}
name|scheduleRender
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|wheelEvent
name|void
name|Window
operator|::
name|wheelEvent
parameter_list|(
name|QWheelEvent
modifier|*
name|event
parameter_list|)
block|{
name|qDebug
argument_list|()
operator|<<
literal|"wheelEvent delta"
operator|<<
name|event
operator|->
name|delta
argument_list|()
operator|<<
literal|"orientation"
operator|<<
name|event
operator|->
name|orientation
argument_list|()
expr_stmt|;
name|qDebug
argument_list|()
operator|<<
literal|"wheelEvent pixelDelta"
operator|<<
name|event
operator|->
name|pixelDelta
argument_list|()
expr_stmt|;
name|qDebug
argument_list|()
operator|<<
literal|"wheelEvent angleDelta"
operator|<<
name|event
operator|->
name|angleDelta
argument_list|()
expr_stmt|;
specifier|const
name|bool
name|useQt4API
init|=
literal|false
decl_stmt|;
if|if
condition|(
name|useQt4API
condition|)
block|{
if|if
condition|(
name|event
operator|->
name|orientation
argument_list|()
operator|==
name|Qt
operator|::
name|Horizontal
condition|)
name|scrollOffset
operator|.
name|setX
argument_list|(
name|scrollOffset
operator|.
name|x
argument_list|()
operator|+
name|event
operator|->
name|delta
argument_list|()
argument_list|)
expr_stmt|;
else|else
name|scrollOffset
operator|.
name|setY
argument_list|(
name|scrollOffset
operator|.
name|y
argument_list|()
operator|+
name|event
operator|->
name|delta
argument_list|()
argument_list|)
expr_stmt|;
name|scheduleRender
argument_list|()
expr_stmt|;
block|}
else|else
block|{
if|if
condition|(
operator|!
name|event
operator|->
name|pixelDelta
argument_list|()
operator|.
name|isNull
argument_list|()
condition|)
block|{
name|scrollOffset
operator|+=
name|event
operator|->
name|pixelDelta
argument_list|()
expr_stmt|;
name|scheduleRender
argument_list|()
expr_stmt|;
block|}
block|}
block|}
end_function
begin_function
DECL|function|mouseReleaseEvent
name|void
name|Window
operator|::
name|mouseReleaseEvent
parameter_list|(
name|QMouseEvent
modifier|*
name|event
parameter_list|)
block|{
if|if
condition|(
name|m_lastPos
operator|!=
name|QPoint
argument_list|(
operator|-
literal|1
argument_list|,
operator|-
literal|1
argument_list|)
condition|)
block|{
name|QPainter
name|p
argument_list|(
operator|&
name|m_image
argument_list|)
decl_stmt|;
name|p
operator|.
name|setRenderHint
argument_list|(
name|QPainter
operator|::
name|Antialiasing
argument_list|)
expr_stmt|;
name|p
operator|.
name|drawLine
argument_list|(
name|m_lastPos
argument_list|,
name|event
operator|->
name|pos
argument_list|()
argument_list|)
expr_stmt|;
name|m_lastPos
operator|=
name|QPoint
argument_list|(
operator|-
literal|1
argument_list|,
operator|-
literal|1
argument_list|)
expr_stmt|;
block|}
name|scheduleRender
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|exposeEvent
name|void
name|Window
operator|::
name|exposeEvent
parameter_list|(
name|QExposeEvent
modifier|*
parameter_list|)
block|{
name|scheduleRender
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|resizeEvent
name|void
name|Window
operator|::
name|resizeEvent
parameter_list|(
name|QResizeEvent
modifier|*
parameter_list|)
block|{
name|QImage
name|old
init|=
name|m_image
decl_stmt|;
comment|//qDebug()<< "Window::resizeEvent"<< width<< height;
name|int
name|width
init|=
name|qMax
argument_list|(
name|geometry
argument_list|()
operator|.
name|width
argument_list|()
argument_list|,
name|old
operator|.
name|width
argument_list|()
argument_list|)
decl_stmt|;
name|int
name|height
init|=
name|qMax
argument_list|(
name|geometry
argument_list|()
operator|.
name|height
argument_list|()
argument_list|,
name|old
operator|.
name|height
argument_list|()
argument_list|)
decl_stmt|;
if|if
condition|(
name|width
operator|>
name|old
operator|.
name|width
argument_list|()
operator|||
name|height
operator|>
name|old
operator|.
name|height
argument_list|()
condition|)
block|{
name|m_image
operator|=
name|QImage
argument_list|(
name|width
argument_list|,
name|height
argument_list|,
name|QImage
operator|::
name|Format_RGB32
argument_list|)
expr_stmt|;
name|m_image
operator|.
name|fill
argument_list|(
name|colorTable
index|[
operator|(
name|m_backgroundColorIndex
operator|)
operator|%
operator|(
sizeof|sizeof
argument_list|(
name|colorTable
argument_list|)
operator|/
sizeof|sizeof
argument_list|(
name|colorTable
index|[
literal|0
index|]
argument_list|)
operator|)
index|]
operator|.
name|rgba
argument_list|()
argument_list|)
expr_stmt|;
name|QPainter
name|p
argument_list|(
operator|&
name|m_image
argument_list|)
decl_stmt|;
name|p
operator|.
name|drawImage
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
name|old
argument_list|)
expr_stmt|;
block|}
name|render
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|keyPressEvent
name|void
name|Window
operator|::
name|keyPressEvent
parameter_list|(
name|QKeyEvent
modifier|*
name|event
parameter_list|)
block|{
switch|switch
condition|(
name|event
operator|->
name|key
argument_list|()
condition|)
block|{
case|case
name|Qt
operator|::
name|Key_Backspace
case|:
name|m_text
operator|.
name|chop
argument_list|(
literal|1
argument_list|)
expr_stmt|;
break|break;
case|case
name|Qt
operator|::
name|Key_Enter
case|:
case|case
name|Qt
operator|::
name|Key_Return
case|:
name|m_text
operator|.
name|append
argument_list|(
literal|'\n'
argument_list|)
expr_stmt|;
break|break;
default|default:
name|m_text
operator|.
name|append
argument_list|(
name|event
operator|->
name|text
argument_list|()
argument_list|)
expr_stmt|;
break|break;
block|}
name|scheduleRender
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|scheduleRender
name|void
name|Window
operator|::
name|scheduleRender
parameter_list|()
block|{
if|if
condition|(
operator|!
name|m_renderTimer
condition|)
name|m_renderTimer
operator|=
name|startTimer
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|timerEvent
name|void
name|Window
operator|::
name|timerEvent
parameter_list|(
name|QTimerEvent
modifier|*
parameter_list|)
block|{
name|render
argument_list|()
expr_stmt|;
name|killTimer
argument_list|(
name|m_renderTimer
argument_list|)
expr_stmt|;
name|m_renderTimer
operator|=
literal|0
expr_stmt|;
block|}
end_function
begin_function
DECL|function|render
name|void
name|Window
operator|::
name|render
parameter_list|()
block|{
name|QRect
name|rect
argument_list|(
name|QPoint
argument_list|()
argument_list|,
name|geometry
argument_list|()
operator|.
name|size
argument_list|()
argument_list|)
decl_stmt|;
name|m_backingStore
operator|->
name|resize
argument_list|(
name|rect
operator|.
name|size
argument_list|()
argument_list|)
expr_stmt|;
name|m_backingStore
operator|->
name|beginPaint
argument_list|(
name|rect
argument_list|)
expr_stmt|;
name|QPaintDevice
modifier|*
name|device
init|=
name|m_backingStore
operator|->
name|paintDevice
argument_list|()
decl_stmt|;
name|QPainter
name|p
argument_list|(
name|device
argument_list|)
decl_stmt|;
name|p
operator|.
name|drawImage
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
name|m_image
argument_list|)
expr_stmt|;
name|QFont
name|font
decl_stmt|;
name|font
operator|.
name|setPixelSize
argument_list|(
literal|32
argument_list|)
expr_stmt|;
name|p
operator|.
name|setFont
argument_list|(
name|font
argument_list|)
expr_stmt|;
name|p
operator|.
name|drawText
argument_list|(
name|rect
argument_list|,
literal|0
argument_list|,
name|m_text
argument_list|)
expr_stmt|;
comment|// draw grid:
name|int
name|gridSpace
init|=
literal|80
decl_stmt|;
for|for
control|(
name|int
name|y
init|=
literal|0
init|;
name|y
operator|<
name|geometry
argument_list|()
operator|.
name|height
argument_list|()
operator|+
name|gridSpace
condition|;
name|y
operator|+=
name|gridSpace
control|)
block|{
name|int
name|offset
init|=
name|scrollOffset
operator|.
name|y
argument_list|()
operator|%
name|gridSpace
decl_stmt|;
comment|//int color = ((y + offset) %255);// + scrollOffset.y()) % 255);
name|p
operator|.
name|drawLine
argument_list|(
literal|0
argument_list|,
name|y
operator|+
name|offset
argument_list|,
name|geometry
argument_list|()
operator|.
name|width
argument_list|()
argument_list|,
name|y
operator|+
name|offset
argument_list|)
expr_stmt|;
comment|//p.setBrush(QColor(color,0, 0));
comment|//p.fillRect(0, y + offset, geometry().width(), gridSpace,QColor(color,0, 0));
block|}
for|for
control|(
name|int
name|x
init|=
literal|0
init|;
name|x
operator|<
name|geometry
argument_list|()
operator|.
name|width
argument_list|()
operator|+
name|gridSpace
condition|;
name|x
operator|+=
name|gridSpace
control|)
block|{
name|p
operator|.
name|drawLine
argument_list|(
name|x
operator|+
name|scrollOffset
operator|.
name|x
argument_list|()
operator|%
name|gridSpace
argument_list|,
literal|0
argument_list|,
name|x
operator|+
name|scrollOffset
operator|.
name|x
argument_list|()
operator|%
name|gridSpace
argument_list|,
name|geometry
argument_list|()
operator|.
name|height
argument_list|()
argument_list|)
expr_stmt|;
block|}
name|m_backingStore
operator|->
name|endPaint
argument_list|()
expr_stmt|;
name|m_backingStore
operator|->
name|flush
argument_list|(
name|rect
argument_list|)
expr_stmt|;
block|}
end_function
end_unit
