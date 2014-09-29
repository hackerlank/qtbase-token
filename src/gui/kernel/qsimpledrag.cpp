begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2014 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia. For licensing terms and ** conditions see http://qt.digia.com/licensing. For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights. These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qsimpledrag_p.h"
end_include
begin_include
include|#
directive|include
file|"qbitmap.h"
end_include
begin_include
include|#
directive|include
file|"qdrag.h"
end_include
begin_include
include|#
directive|include
file|"qpixmap.h"
end_include
begin_include
include|#
directive|include
file|"qevent.h"
end_include
begin_include
include|#
directive|include
file|"qfile.h"
end_include
begin_include
include|#
directive|include
file|"qtextcodec.h"
end_include
begin_include
include|#
directive|include
file|"qguiapplication.h"
end_include
begin_include
include|#
directive|include
file|"qpoint.h"
end_include
begin_include
include|#
directive|include
file|"qbuffer.h"
end_include
begin_include
include|#
directive|include
file|"qimage.h"
end_include
begin_include
include|#
directive|include
file|"qregexp.h"
end_include
begin_include
include|#
directive|include
file|"qdir.h"
end_include
begin_include
include|#
directive|include
file|"qimagereader.h"
end_include
begin_include
include|#
directive|include
file|"qimagewriter.h"
end_include
begin_include
include|#
directive|include
file|<QtCore/QEventLoop>
end_include
begin_include
include|#
directive|include
file|<QtCore/QDebug>
end_include
begin_include
include|#
directive|include
file|<private/qguiapplication_p.h>
end_include
begin_include
include|#
directive|include
file|<private/qdnd_p.h>
end_include
begin_include
include|#
directive|include
file|<private/qshapedpixmapdndwindow_p.h>
end_include
begin_function
name|QT_BEGIN_NAMESPACE
ifndef|#
directive|ifndef
name|QT_NO_DRAGANDDROP
DECL|function|topLevelAt
specifier|static
name|QWindow
modifier|*
name|topLevelAt
parameter_list|(
specifier|const
name|QPoint
modifier|&
name|pos
parameter_list|)
block|{
name|QWindowList
name|list
init|=
name|QGuiApplication
operator|::
name|topLevelWindows
argument_list|()
decl_stmt|;
for|for
control|(
name|int
name|i
init|=
name|list
operator|.
name|count
argument_list|()
operator|-
literal|1
init|;
name|i
operator|>=
literal|0
condition|;
operator|--
name|i
control|)
block|{
name|QWindow
modifier|*
name|w
init|=
name|list
operator|.
name|at
argument_list|(
name|i
argument_list|)
decl_stmt|;
if|if
condition|(
name|w
operator|->
name|isVisible
argument_list|()
operator|&&
name|w
operator|->
name|geometry
argument_list|()
operator|.
name|contains
argument_list|(
name|pos
argument_list|)
operator|&&
operator|!
name|qobject_cast
argument_list|<
name|QShapedPixmapWindow
operator|*
argument_list|>
argument_list|(
name|w
argument_list|)
condition|)
return|return
name|w
return|;
block|}
return|return
literal|0
return|;
block|}
end_function
begin_comment
comment|/*!     \class QBasicDrag     \brief QBasicDrag is a base class for implementing platform drag and drop.     \since 5.0     \internal     \ingroup qpa      QBasicDrag implements QPlatformDrag::drag() by running a local event loop in which     it tracks mouse movements and moves the drag icon (QShapedPixmapWindow) accordingly.     It provides new virtuals allowing for querying whether the receiving window     (within the Qt application or outside) accepts the drag and sets the state accordingly. */
end_comment
begin_constructor
DECL|function|QBasicDrag
name|QBasicDrag
operator|::
name|QBasicDrag
parameter_list|()
member_init_list|:
name|m_restoreCursor
argument_list|(
literal|false
argument_list|)
member_init_list|,
name|m_eventLoop
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|m_executed_drop_action
argument_list|(
name|Qt
operator|::
name|IgnoreAction
argument_list|)
member_init_list|,
name|m_can_drop
argument_list|(
literal|false
argument_list|)
member_init_list|,
name|m_drag
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|m_drag_icon_window
argument_list|(
literal|0
argument_list|)
block|{ }
end_constructor
begin_destructor
DECL|function|~QBasicDrag
name|QBasicDrag
operator|::
name|~
name|QBasicDrag
parameter_list|()
block|{
operator|delete
name|m_drag_icon_window
expr_stmt|;
block|}
end_destructor
begin_function
DECL|function|enableEventFilter
name|void
name|QBasicDrag
operator|::
name|enableEventFilter
parameter_list|()
block|{
name|qApp
operator|->
name|installEventFilter
argument_list|(
name|this
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|disableEventFilter
name|void
name|QBasicDrag
operator|::
name|disableEventFilter
parameter_list|()
block|{
name|qApp
operator|->
name|removeEventFilter
argument_list|(
name|this
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|eventFilter
name|bool
name|QBasicDrag
operator|::
name|eventFilter
parameter_list|(
name|QObject
modifier|*
name|o
parameter_list|,
name|QEvent
modifier|*
name|e
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
name|o
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|m_drag
condition|)
block|{
if|if
condition|(
name|e
operator|->
name|type
argument_list|()
operator|==
name|QEvent
operator|::
name|KeyRelease
operator|&&
cast|static_cast
argument_list|<
name|QKeyEvent
operator|*
argument_list|>
argument_list|(
name|e
argument_list|)
operator|->
name|key
argument_list|()
operator|==
name|Qt
operator|::
name|Key_Escape
condition|)
block|{
name|disableEventFilter
argument_list|()
expr_stmt|;
name|exitDndEventLoop
argument_list|()
expr_stmt|;
return|return
literal|true
return|;
comment|// block the key release
block|}
return|return
literal|false
return|;
block|}
switch|switch
condition|(
name|e
operator|->
name|type
argument_list|()
condition|)
block|{
case|case
name|QEvent
operator|::
name|ShortcutOverride
case|:
comment|// prevent accelerators from firing while dragging
name|e
operator|->
name|accept
argument_list|()
expr_stmt|;
return|return
literal|true
return|;
case|case
name|QEvent
operator|::
name|KeyPress
case|:
case|case
name|QEvent
operator|::
name|KeyRelease
case|:
block|{
name|QKeyEvent
modifier|*
name|ke
init|=
cast|static_cast
argument_list|<
name|QKeyEvent
operator|*
argument_list|>
argument_list|(
name|e
argument_list|)
decl_stmt|;
if|if
condition|(
name|ke
operator|->
name|key
argument_list|()
operator|==
name|Qt
operator|::
name|Key_Escape
operator|&&
name|e
operator|->
name|type
argument_list|()
operator|==
name|QEvent
operator|::
name|KeyPress
condition|)
block|{
name|cancel
argument_list|()
expr_stmt|;
name|disableEventFilter
argument_list|()
expr_stmt|;
name|exitDndEventLoop
argument_list|()
expr_stmt|;
block|}
return|return
literal|true
return|;
comment|// Eat all key events
block|}
case|case
name|QEvent
operator|::
name|MouseMove
case|:
name|move
argument_list|(
cast|static_cast
argument_list|<
name|QMouseEvent
operator|*
argument_list|>
argument_list|(
name|e
argument_list|)
argument_list|)
expr_stmt|;
return|return
literal|true
return|;
comment|// Eat all mouse events
case|case
name|QEvent
operator|::
name|MouseButtonRelease
case|:
name|disableEventFilter
argument_list|()
expr_stmt|;
if|if
condition|(
name|canDrop
argument_list|()
condition|)
block|{
name|drop
argument_list|(
cast|static_cast
argument_list|<
name|QMouseEvent
operator|*
argument_list|>
argument_list|(
name|e
argument_list|)
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|cancel
argument_list|()
expr_stmt|;
block|}
name|exitDndEventLoop
argument_list|()
expr_stmt|;
return|return
literal|true
return|;
comment|// Eat all mouse events
case|case
name|QEvent
operator|::
name|MouseButtonPress
case|:
case|case
name|QEvent
operator|::
name|MouseButtonDblClick
case|:
case|case
name|QEvent
operator|::
name|Wheel
case|:
return|return
literal|true
return|;
default|default:
break|break;
block|}
return|return
literal|false
return|;
block|}
end_function
begin_function
DECL|function|drag
name|Qt
operator|::
name|DropAction
name|QBasicDrag
operator|::
name|drag
parameter_list|(
name|QDrag
modifier|*
name|o
parameter_list|)
block|{
name|m_drag
operator|=
name|o
expr_stmt|;
name|m_executed_drop_action
operator|=
name|Qt
operator|::
name|IgnoreAction
expr_stmt|;
name|m_can_drop
operator|=
literal|false
expr_stmt|;
name|m_restoreCursor
operator|=
literal|true
expr_stmt|;
ifndef|#
directive|ifndef
name|QT_NO_CURSOR
name|qApp
operator|->
name|setOverrideCursor
argument_list|(
name|Qt
operator|::
name|DragCopyCursor
argument_list|)
expr_stmt|;
name|updateCursor
argument_list|(
name|m_executed_drop_action
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|startDrag
argument_list|()
expr_stmt|;
name|m_eventLoop
operator|=
operator|new
name|QEventLoop
expr_stmt|;
name|m_eventLoop
operator|->
name|exec
argument_list|()
expr_stmt|;
operator|delete
name|m_eventLoop
expr_stmt|;
name|m_eventLoop
operator|=
literal|0
expr_stmt|;
name|m_drag
operator|=
literal|0
expr_stmt|;
name|endDrag
argument_list|()
expr_stmt|;
return|return
name|m_executed_drop_action
return|;
block|}
end_function
begin_function
DECL|function|restoreCursor
name|void
name|QBasicDrag
operator|::
name|restoreCursor
parameter_list|()
block|{
if|if
condition|(
name|m_restoreCursor
condition|)
block|{
ifndef|#
directive|ifndef
name|QT_NO_CURSOR
name|QGuiApplication
operator|::
name|restoreOverrideCursor
argument_list|()
expr_stmt|;
endif|#
directive|endif
name|m_restoreCursor
operator|=
literal|false
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|startDrag
name|void
name|QBasicDrag
operator|::
name|startDrag
parameter_list|()
block|{
comment|// ### TODO Check if its really necessary to have m_drag_icon_window
comment|// when QDrag is used without a pixmap - QDrag::setPixmap()
if|if
condition|(
operator|!
name|m_drag_icon_window
condition|)
name|m_drag_icon_window
operator|=
operator|new
name|QShapedPixmapWindow
argument_list|()
expr_stmt|;
name|m_drag_icon_window
operator|->
name|setPixmap
argument_list|(
name|m_drag
operator|->
name|pixmap
argument_list|()
argument_list|)
expr_stmt|;
name|m_drag_icon_window
operator|->
name|setHotspot
argument_list|(
name|m_drag
operator|->
name|hotSpot
argument_list|()
argument_list|)
expr_stmt|;
name|m_drag_icon_window
operator|->
name|updateGeometry
argument_list|()
expr_stmt|;
name|m_drag_icon_window
operator|->
name|setVisible
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|enableEventFilter
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|endDrag
name|void
name|QBasicDrag
operator|::
name|endDrag
parameter_list|()
block|{ }
end_function
begin_function
DECL|function|cancel
name|void
name|QBasicDrag
operator|::
name|cancel
parameter_list|()
block|{
name|disableEventFilter
argument_list|()
expr_stmt|;
name|restoreCursor
argument_list|()
expr_stmt|;
name|m_drag_icon_window
operator|->
name|setVisible
argument_list|(
literal|false
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|move
name|void
name|QBasicDrag
operator|::
name|move
parameter_list|(
specifier|const
name|QMouseEvent
modifier|*
parameter_list|)
block|{
if|if
condition|(
name|m_drag
condition|)
name|m_drag_icon_window
operator|->
name|updateGeometry
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|drop
name|void
name|QBasicDrag
operator|::
name|drop
parameter_list|(
specifier|const
name|QMouseEvent
modifier|*
parameter_list|)
block|{
name|disableEventFilter
argument_list|()
expr_stmt|;
name|restoreCursor
argument_list|()
expr_stmt|;
name|m_drag_icon_window
operator|->
name|setVisible
argument_list|(
literal|false
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|exitDndEventLoop
name|void
name|QBasicDrag
operator|::
name|exitDndEventLoop
parameter_list|()
block|{
if|if
condition|(
name|m_eventLoop
operator|&&
name|m_eventLoop
operator|->
name|isRunning
argument_list|()
condition|)
name|m_eventLoop
operator|->
name|exit
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|updateCursor
name|void
name|QBasicDrag
operator|::
name|updateCursor
parameter_list|(
name|Qt
operator|::
name|DropAction
name|action
parameter_list|)
block|{
ifndef|#
directive|ifndef
name|QT_NO_CURSOR
name|Qt
operator|::
name|CursorShape
name|cursorShape
init|=
name|Qt
operator|::
name|ForbiddenCursor
decl_stmt|;
if|if
condition|(
name|canDrop
argument_list|()
condition|)
block|{
switch|switch
condition|(
name|action
condition|)
block|{
case|case
name|Qt
operator|::
name|CopyAction
case|:
name|cursorShape
operator|=
name|Qt
operator|::
name|DragCopyCursor
expr_stmt|;
break|break;
case|case
name|Qt
operator|::
name|LinkAction
case|:
name|cursorShape
operator|=
name|Qt
operator|::
name|DragLinkCursor
expr_stmt|;
break|break;
default|default:
name|cursorShape
operator|=
name|Qt
operator|::
name|DragMoveCursor
expr_stmt|;
break|break;
block|}
block|}
name|QCursor
modifier|*
name|cursor
init|=
name|qApp
operator|->
name|overrideCursor
argument_list|()
decl_stmt|;
name|QPixmap
name|pixmap
init|=
name|m_drag
operator|->
name|dragCursor
argument_list|(
name|action
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|cursor
condition|)
block|{
name|qApp
operator|->
name|changeOverrideCursor
argument_list|(
operator|(
name|pixmap
operator|.
name|isNull
argument_list|()
operator|)
condition|?
name|QCursor
argument_list|(
name|cursorShape
argument_list|)
else|:
name|QCursor
argument_list|(
name|pixmap
argument_list|)
argument_list|)
expr_stmt|;
block|}
else|else
block|{
if|if
condition|(
operator|!
name|pixmap
operator|.
name|isNull
argument_list|()
condition|)
block|{
if|if
condition|(
operator|(
name|cursor
operator|->
name|pixmap
argument_list|()
operator|.
name|cacheKey
argument_list|()
operator|!=
name|pixmap
operator|.
name|cacheKey
argument_list|()
operator|)
condition|)
block|{
name|qApp
operator|->
name|changeOverrideCursor
argument_list|(
name|QCursor
argument_list|(
name|pixmap
argument_list|)
argument_list|)
expr_stmt|;
block|}
block|}
else|else
block|{
if|if
condition|(
name|cursorShape
operator|!=
name|cursor
operator|->
name|shape
argument_list|()
condition|)
block|{
name|qApp
operator|->
name|changeOverrideCursor
argument_list|(
name|QCursor
argument_list|(
name|cursorShape
argument_list|)
argument_list|)
expr_stmt|;
block|}
block|}
block|}
endif|#
directive|endif
name|updateAction
argument_list|(
name|action
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     \class QSimpleDrag     \brief QSimpleDrag implements QBasicDrag for Drag and Drop operations within the Qt Application itself.     \since 5.0     \internal     \ingroup qpa      The class checks whether the receiving window is a window of the Qt application     and sets the state accordingly. It does not take windows of other applications     into account. */
end_comment
begin_constructor
DECL|function|QSimpleDrag
name|QSimpleDrag
operator|::
name|QSimpleDrag
parameter_list|()
member_init_list|:
name|m_current_window
argument_list|(
literal|0
argument_list|)
block|{ }
end_constructor
begin_function
DECL|function|platformDropData
name|QMimeData
modifier|*
name|QSimpleDrag
operator|::
name|platformDropData
parameter_list|()
block|{
if|if
condition|(
name|drag
argument_list|()
condition|)
return|return
name|drag
argument_list|()
operator|->
name|mimeData
argument_list|()
return|;
return|return
literal|0
return|;
block|}
end_function
begin_function
DECL|function|startDrag
name|void
name|QSimpleDrag
operator|::
name|startDrag
parameter_list|()
block|{
name|QBasicDrag
operator|::
name|startDrag
argument_list|()
expr_stmt|;
name|m_current_window
operator|=
name|topLevelAt
argument_list|(
name|QCursor
operator|::
name|pos
argument_list|()
argument_list|)
expr_stmt|;
if|if
condition|(
name|m_current_window
condition|)
block|{
name|QPlatformDragQtResponse
name|response
init|=
name|QWindowSystemInterface
operator|::
name|handleDrag
argument_list|(
name|m_current_window
argument_list|,
name|drag
argument_list|()
operator|->
name|mimeData
argument_list|()
argument_list|,
name|QCursor
operator|::
name|pos
argument_list|()
argument_list|,
name|drag
argument_list|()
operator|->
name|supportedActions
argument_list|()
argument_list|)
decl_stmt|;
name|setCanDrop
argument_list|(
name|response
operator|.
name|isAccepted
argument_list|()
argument_list|)
expr_stmt|;
name|updateCursor
argument_list|(
name|response
operator|.
name|acceptedAction
argument_list|()
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|setCanDrop
argument_list|(
literal|false
argument_list|)
expr_stmt|;
name|updateCursor
argument_list|(
name|Qt
operator|::
name|IgnoreAction
argument_list|)
expr_stmt|;
block|}
name|setExecutedDropAction
argument_list|(
name|Qt
operator|::
name|IgnoreAction
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|cancel
name|void
name|QSimpleDrag
operator|::
name|cancel
parameter_list|()
block|{
name|QBasicDrag
operator|::
name|cancel
argument_list|()
expr_stmt|;
if|if
condition|(
name|drag
argument_list|()
operator|&&
name|m_current_window
condition|)
block|{
name|QWindowSystemInterface
operator|::
name|handleDrag
argument_list|(
name|m_current_window
argument_list|,
literal|0
argument_list|,
name|QPoint
argument_list|()
argument_list|,
name|Qt
operator|::
name|IgnoreAction
argument_list|)
expr_stmt|;
name|m_current_window
operator|=
literal|0
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|move
name|void
name|QSimpleDrag
operator|::
name|move
parameter_list|(
specifier|const
name|QMouseEvent
modifier|*
name|me
parameter_list|)
block|{
name|QBasicDrag
operator|::
name|move
argument_list|(
name|me
argument_list|)
expr_stmt|;
name|QWindow
modifier|*
name|window
init|=
name|topLevelAt
argument_list|(
name|me
operator|->
name|globalPos
argument_list|()
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|window
condition|)
return|return;
specifier|const
name|QPoint
name|pos
init|=
name|me
operator|->
name|globalPos
argument_list|()
operator|-
name|window
operator|->
name|geometry
argument_list|()
operator|.
name|topLeft
argument_list|()
decl_stmt|;
specifier|const
name|QPlatformDragQtResponse
name|qt_response
init|=
name|QWindowSystemInterface
operator|::
name|handleDrag
argument_list|(
name|window
argument_list|,
name|drag
argument_list|()
operator|->
name|mimeData
argument_list|()
argument_list|,
name|pos
argument_list|,
name|drag
argument_list|()
operator|->
name|supportedActions
argument_list|()
argument_list|)
decl_stmt|;
name|updateCursor
argument_list|(
name|qt_response
operator|.
name|acceptedAction
argument_list|()
argument_list|)
expr_stmt|;
name|setCanDrop
argument_list|(
name|qt_response
operator|.
name|isAccepted
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|drop
name|void
name|QSimpleDrag
operator|::
name|drop
parameter_list|(
specifier|const
name|QMouseEvent
modifier|*
name|me
parameter_list|)
block|{
name|QBasicDrag
operator|::
name|drop
argument_list|(
name|me
argument_list|)
expr_stmt|;
name|QWindow
modifier|*
name|window
init|=
name|topLevelAt
argument_list|(
name|me
operator|->
name|globalPos
argument_list|()
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|window
condition|)
return|return;
specifier|const
name|QPoint
name|pos
init|=
name|me
operator|->
name|globalPos
argument_list|()
operator|-
name|window
operator|->
name|geometry
argument_list|()
operator|.
name|topLeft
argument_list|()
decl_stmt|;
specifier|const
name|QPlatformDropQtResponse
name|response
init|=
name|QWindowSystemInterface
operator|::
name|handleDrop
argument_list|(
name|window
argument_list|,
name|drag
argument_list|()
operator|->
name|mimeData
argument_list|()
argument_list|,
name|pos
argument_list|,
name|drag
argument_list|()
operator|->
name|supportedActions
argument_list|()
argument_list|)
decl_stmt|;
if|if
condition|(
name|response
operator|.
name|isAccepted
argument_list|()
condition|)
block|{
name|setExecutedDropAction
argument_list|(
name|response
operator|.
name|acceptedAction
argument_list|()
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|setExecutedDropAction
argument_list|(
name|Qt
operator|::
name|IgnoreAction
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_DRAGANDDROP
end_comment
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
