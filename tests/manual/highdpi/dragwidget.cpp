begin_unit
begin_comment
comment|/****************************************************************************  **  ** Copyright (C) 2015 The Qt Company Ltd.  ** Contact: http://www.qt.io/licensing/  **  ** This file is part of the test suite of the Qt Toolkit.  **  ** $QT_BEGIN_LICENSE:LGPL21$  ** Commercial License Usage  ** Licensees holding valid commercial Qt licenses may use this file in  ** accordance with the commercial license agreement provided with the  ** Software or, alternatively, in accordance with the terms contained in  ** a written agreement between you and The Qt Company. For licensing terms  ** and conditions see http://www.qt.io/terms-conditions. For further  ** information use the contact form at http://www.qt.io/contact-us.  **  ** GNU Lesser General Public License Usage  ** Alternatively, this file may be used under the terms of the GNU Lesser  ** General Public License version 2.1 or version 3 as published by the Free  ** Software Foundation and appearing in the file LICENSE.LGPLv21 and  ** LICENSE.LGPLv3 included in the packaging of this file. Please review the  ** following information to ensure the GNU Lesser General Public License  ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and  ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.  **  ** As a special exception, The Qt Company gives you certain additional  ** rights. These rights are described in The Qt Company LGPL Exception  ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package.  **  ** $QT_END_LICENSE$  **  ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtWidgets>
end_include
begin_include
include|#
directive|include
file|"dragwidget.h"
end_include
begin_class
DECL|class|FramedLabel
class|class
name|FramedLabel
super|:
specifier|public
name|QLabel
block|{
public|public:
DECL|function|FramedLabel
name|FramedLabel
parameter_list|(
specifier|const
name|QString
modifier|&
name|text
parameter_list|,
name|QWidget
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QLabel
argument_list|(
name|text
argument_list|,
name|parent
argument_list|)
block|{
name|setAutoFillBackground
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|setFrameShape
argument_list|(
name|QFrame
operator|::
name|Panel
argument_list|)
expr_stmt|;
name|setFrameShadow
argument_list|(
name|QFrame
operator|::
name|Raised
argument_list|)
expr_stmt|;
block|}
block|}
class|;
end_class
begin_constructor
DECL|function|DragWidget
name|DragWidget
operator|::
name|DragWidget
parameter_list|(
name|QString
name|text
parameter_list|,
name|QWidget
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QWidget
argument_list|(
name|parent
argument_list|)
member_init_list|,
name|otherWindow
argument_list|(
literal|0
argument_list|)
block|{
name|int
name|x
init|=
literal|5
decl_stmt|;
name|int
name|y
init|=
literal|5
decl_stmt|;
name|bool
name|createChildWindow
init|=
name|text
operator|.
name|isEmpty
argument_list|()
decl_stmt|;
comment|// OK, yes this is a hack...
if|if
condition|(
name|text
operator|.
name|isEmpty
argument_list|()
condition|)
name|text
operator|=
literal|"You can drag from this window and drop text here"
expr_stmt|;
name|QStringList
name|words
init|=
name|text
operator|.
name|split
argument_list|(
literal|' '
argument_list|)
decl_stmt|;
foreach|foreach
control|(
name|QString
name|word
decl|,
name|words
control|)
block|{
if|if
condition|(
operator|!
name|word
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|FramedLabel
modifier|*
name|wordLabel
init|=
operator|new
name|FramedLabel
argument_list|(
name|word
argument_list|,
name|this
argument_list|)
decl_stmt|;
name|wordLabel
operator|->
name|move
argument_list|(
name|x
argument_list|,
name|y
argument_list|)
expr_stmt|;
name|wordLabel
operator|->
name|show
argument_list|()
expr_stmt|;
name|x
operator|+=
name|wordLabel
operator|->
name|width
argument_list|()
operator|+
literal|2
expr_stmt|;
if|if
condition|(
name|x
operator|>=
literal|245
condition|)
block|{
name|x
operator|=
literal|5
expr_stmt|;
name|y
operator|+=
name|wordLabel
operator|->
name|height
argument_list|()
operator|+
literal|2
expr_stmt|;
block|}
block|}
block|}
comment|/*     QPalette newPalette = palette();     newPalette.setColor(QPalette::Window, Qt::white);     setPalette(newPalette);     */
name|setAcceptDrops
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|setMinimumSize
argument_list|(
literal|400
argument_list|,
name|qMax
argument_list|(
literal|200
argument_list|,
name|y
argument_list|)
argument_list|)
expr_stmt|;
name|setWindowTitle
argument_list|(
name|tr
argument_list|(
literal|"Draggable Text Window %1"
argument_list|)
operator|.
name|arg
argument_list|(
name|createChildWindow
condition|?
literal|1
else|:
literal|2
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|createChildWindow
condition|)
name|otherWindow
operator|=
operator|new
name|DragWidget
argument_list|(
literal|"Here is a second window that accepts drops"
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_function
DECL|function|dragEnterEvent
name|void
name|DragWidget
operator|::
name|dragEnterEvent
parameter_list|(
name|QDragEnterEvent
modifier|*
name|event
parameter_list|)
block|{
if|if
condition|(
name|event
operator|->
name|mimeData
argument_list|()
operator|->
name|hasText
argument_list|()
condition|)
block|{
if|if
condition|(
name|event
operator|->
name|source
argument_list|()
operator|==
name|this
condition|)
block|{
name|event
operator|->
name|setDropAction
argument_list|(
name|Qt
operator|::
name|MoveAction
argument_list|)
expr_stmt|;
name|event
operator|->
name|accept
argument_list|()
expr_stmt|;
block|}
else|else
block|{
name|event
operator|->
name|acceptProposedAction
argument_list|()
expr_stmt|;
block|}
block|}
else|else
block|{
name|event
operator|->
name|ignore
argument_list|()
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|dragMoveEvent
name|void
name|DragWidget
operator|::
name|dragMoveEvent
parameter_list|(
name|QDragMoveEvent
modifier|*
name|event
parameter_list|)
block|{
name|dragPos
operator|=
name|event
operator|->
name|pos
argument_list|()
expr_stmt|;
name|dragTimer
operator|.
name|start
argument_list|(
literal|500
argument_list|,
name|this
argument_list|)
expr_stmt|;
name|update
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|dragLeaveEvent
name|void
name|DragWidget
operator|::
name|dragLeaveEvent
parameter_list|(
name|QDragLeaveEvent
modifier|*
parameter_list|)
block|{
name|dragTimer
operator|.
name|stop
argument_list|()
expr_stmt|;
name|update
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|dropEvent
name|void
name|DragWidget
operator|::
name|dropEvent
parameter_list|(
name|QDropEvent
modifier|*
name|event
parameter_list|)
block|{
if|if
condition|(
name|event
operator|->
name|mimeData
argument_list|()
operator|->
name|hasText
argument_list|()
condition|)
block|{
specifier|const
name|QMimeData
modifier|*
name|mime
init|=
name|event
operator|->
name|mimeData
argument_list|()
decl_stmt|;
name|QStringList
name|pieces
init|=
name|mime
operator|->
name|text
argument_list|()
operator|.
name|split
argument_list|(
name|QRegExp
argument_list|(
literal|"\\s+"
argument_list|)
argument_list|,
name|QString
operator|::
name|SkipEmptyParts
argument_list|)
decl_stmt|;
name|QPoint
name|position
init|=
name|event
operator|->
name|pos
argument_list|()
decl_stmt|;
name|QPoint
name|hotSpot
decl_stmt|;
name|QList
argument_list|<
name|QByteArray
argument_list|>
name|hotSpotPos
init|=
name|mime
operator|->
name|data
argument_list|(
literal|"application/x-hotspot"
argument_list|)
operator|.
name|split
argument_list|(
literal|' '
argument_list|)
decl_stmt|;
if|if
condition|(
name|hotSpotPos
operator|.
name|size
argument_list|()
operator|==
literal|2
condition|)
block|{
name|hotSpot
operator|.
name|setX
argument_list|(
name|hotSpotPos
operator|.
name|first
argument_list|()
operator|.
name|toInt
argument_list|()
argument_list|)
expr_stmt|;
name|hotSpot
operator|.
name|setY
argument_list|(
name|hotSpotPos
operator|.
name|last
argument_list|()
operator|.
name|toInt
argument_list|()
argument_list|)
expr_stmt|;
block|}
name|dropPos
operator|=
name|position
operator|-
name|hotSpot
expr_stmt|;
name|dropTimer
operator|.
name|start
argument_list|(
literal|500
argument_list|,
name|this
argument_list|)
expr_stmt|;
name|update
argument_list|()
expr_stmt|;
foreach|foreach
control|(
name|QString
name|piece
decl|,
name|pieces
control|)
block|{
name|FramedLabel
modifier|*
name|newLabel
init|=
operator|new
name|FramedLabel
argument_list|(
name|piece
argument_list|,
name|this
argument_list|)
decl_stmt|;
name|newLabel
operator|->
name|move
argument_list|(
name|position
operator|-
name|hotSpot
argument_list|)
expr_stmt|;
name|newLabel
operator|->
name|show
argument_list|()
expr_stmt|;
name|position
operator|+=
name|QPoint
argument_list|(
name|newLabel
operator|->
name|width
argument_list|()
argument_list|,
literal|0
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|event
operator|->
name|source
argument_list|()
operator|==
name|this
condition|)
block|{
name|event
operator|->
name|setDropAction
argument_list|(
name|Qt
operator|::
name|MoveAction
argument_list|)
expr_stmt|;
name|event
operator|->
name|accept
argument_list|()
expr_stmt|;
block|}
else|else
block|{
name|event
operator|->
name|acceptProposedAction
argument_list|()
expr_stmt|;
block|}
block|}
else|else
block|{
name|event
operator|->
name|ignore
argument_list|()
expr_stmt|;
block|}
foreach|foreach
control|(
name|QObject
modifier|*
name|child
decl|,
name|children
argument_list|()
control|)
block|{
if|if
condition|(
name|child
operator|->
name|inherits
argument_list|(
literal|"QWidget"
argument_list|)
condition|)
block|{
name|QWidget
modifier|*
name|widget
init|=
cast|static_cast
argument_list|<
name|QWidget
operator|*
argument_list|>
argument_list|(
name|child
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|widget
operator|->
name|isVisible
argument_list|()
condition|)
name|widget
operator|->
name|deleteLater
argument_list|()
expr_stmt|;
block|}
block|}
block|}
end_function
begin_function
DECL|function|mousePressEvent
name|void
name|DragWidget
operator|::
name|mousePressEvent
parameter_list|(
name|QMouseEvent
modifier|*
name|event
parameter_list|)
block|{
name|QLabel
modifier|*
name|child
init|=
cast|static_cast
argument_list|<
name|QLabel
operator|*
argument_list|>
argument_list|(
name|childAt
argument_list|(
name|event
operator|->
name|pos
argument_list|()
argument_list|)
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|child
condition|)
return|return;
name|QPoint
name|hotSpot
init|=
name|event
operator|->
name|pos
argument_list|()
operator|-
name|child
operator|->
name|pos
argument_list|()
decl_stmt|;
name|QMimeData
modifier|*
name|mimeData
init|=
operator|new
name|QMimeData
decl_stmt|;
name|mimeData
operator|->
name|setText
argument_list|(
name|child
operator|->
name|text
argument_list|()
argument_list|)
expr_stmt|;
name|mimeData
operator|->
name|setData
argument_list|(
literal|"application/x-hotspot"
argument_list|,
name|QByteArray
operator|::
name|number
argument_list|(
name|hotSpot
operator|.
name|x
argument_list|()
argument_list|)
operator|+
literal|' '
operator|+
name|QByteArray
operator|::
name|number
argument_list|(
name|hotSpot
operator|.
name|y
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|QPixmap
name|pixmap
argument_list|(
name|child
operator|->
name|size
argument_list|()
argument_list|)
decl_stmt|;
name|child
operator|->
name|render
argument_list|(
operator|&
name|pixmap
argument_list|)
expr_stmt|;
name|QDrag
modifier|*
name|drag
init|=
operator|new
name|QDrag
argument_list|(
name|this
argument_list|)
decl_stmt|;
name|drag
operator|->
name|setMimeData
argument_list|(
name|mimeData
argument_list|)
expr_stmt|;
name|drag
operator|->
name|setPixmap
argument_list|(
name|pixmap
argument_list|)
expr_stmt|;
name|drag
operator|->
name|setHotSpot
argument_list|(
name|hotSpot
argument_list|)
expr_stmt|;
name|Qt
operator|::
name|DropAction
name|dropAction
init|=
name|drag
operator|->
name|exec
argument_list|(
name|Qt
operator|::
name|CopyAction
operator||
name|Qt
operator|::
name|MoveAction
argument_list|,
name|Qt
operator|::
name|CopyAction
argument_list|)
decl_stmt|;
if|if
condition|(
name|dropAction
operator|==
name|Qt
operator|::
name|MoveAction
condition|)
name|child
operator|->
name|close
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|timerEvent
name|void
name|DragWidget
operator|::
name|timerEvent
parameter_list|(
name|QTimerEvent
modifier|*
name|e
parameter_list|)
block|{
if|if
condition|(
name|e
operator|->
name|timerId
argument_list|()
operator|==
name|dragTimer
operator|.
name|timerId
argument_list|()
condition|)
name|dragTimer
operator|.
name|stop
argument_list|()
expr_stmt|;
if|if
condition|(
name|e
operator|->
name|timerId
argument_list|()
operator|==
name|dropTimer
operator|.
name|timerId
argument_list|()
condition|)
name|dropTimer
operator|.
name|stop
argument_list|()
expr_stmt|;
name|update
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|paintEvent
name|void
name|DragWidget
operator|::
name|paintEvent
parameter_list|(
name|QPaintEvent
modifier|*
parameter_list|)
block|{
name|QPainter
name|p
argument_list|(
name|this
argument_list|)
decl_stmt|;
name|p
operator|.
name|fillRect
argument_list|(
name|rect
argument_list|()
argument_list|,
name|Qt
operator|::
name|white
argument_list|)
expr_stmt|;
if|if
condition|(
name|dropTimer
operator|.
name|isActive
argument_list|()
condition|)
block|{
name|p
operator|.
name|setBrush
argument_list|(
name|Qt
operator|::
name|red
argument_list|)
expr_stmt|;
name|p
operator|.
name|drawEllipse
argument_list|(
name|dropPos
argument_list|,
literal|50
argument_list|,
literal|50
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|dragTimer
operator|.
name|isActive
argument_list|()
condition|)
block|{
name|p
operator|.
name|setPen
argument_list|(
name|QPen
argument_list|(
name|Qt
operator|::
name|blue
argument_list|,
literal|5
argument_list|)
argument_list|)
expr_stmt|;
name|QPoint
name|p1
init|=
operator|(
name|rect
argument_list|()
operator|.
name|topLeft
argument_list|()
operator|*
literal|3
operator|+
name|rect
argument_list|()
operator|.
name|bottomRight
argument_list|()
operator|)
operator|/
literal|4
decl_stmt|;
name|QPoint
name|p2
init|=
operator|(
name|rect
argument_list|()
operator|.
name|topLeft
argument_list|()
operator|+
name|rect
argument_list|()
operator|.
name|bottomRight
argument_list|()
operator|*
literal|3
operator|)
operator|/
literal|4
decl_stmt|;
name|p
operator|.
name|drawLine
argument_list|(
name|p1
argument_list|,
name|dragPos
argument_list|)
expr_stmt|;
name|p
operator|.
name|drawLine
argument_list|(
name|p2
argument_list|,
name|dragPos
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|showEvent
name|void
name|DragWidget
operator|::
name|showEvent
parameter_list|(
name|QShowEvent
modifier|*
parameter_list|)
block|{
if|if
condition|(
name|otherWindow
condition|)
name|otherWindow
operator|->
name|show
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|hideEvent
name|void
name|DragWidget
operator|::
name|hideEvent
parameter_list|(
name|QHideEvent
modifier|*
parameter_list|)
block|{
if|if
condition|(
name|otherWindow
condition|)
name|otherWindow
operator|->
name|hide
argument_list|()
expr_stmt|;
block|}
end_function
end_unit
