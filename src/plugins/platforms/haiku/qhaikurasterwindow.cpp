begin_unit
begin_comment
comment|/*************************************************************************** ** ** Copyright (C) 2015 KlarÃ¤lvdalens Datakonsult AB, a KDAB Group company, info@kdab.com, author Tobias Koenig<tobias.koenig@kdab.com> ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qhaikurasterwindow.h"
end_include
begin_include
include|#
directive|include
file|"qhaikukeymapper.h"
end_include
begin_include
include|#
directive|include
file|<View.h>
end_include
begin_include
include|#
directive|include
file|<Window.h>
end_include
begin_include
include|#
directive|include
file|<qpa/qwindowsysteminterface.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
name|Q_DECLARE_METATYPE
argument_list|(
name|QEvent
operator|::
name|Type
argument_list|)
name|Q_DECLARE_METATYPE
argument_list|(
name|Qt
operator|::
name|MouseButtons
argument_list|)
name|Q_DECLARE_METATYPE
argument_list|(
name|Qt
operator|::
name|MouseEventSource
argument_list|)
name|Q_DECLARE_METATYPE
argument_list|(
name|Qt
operator|::
name|KeyboardModifiers
argument_list|)
name|Q_DECLARE_METATYPE
argument_list|(
name|Qt
operator|::
name|Orientation
argument_list|)
DECL|function|HaikuViewProxy
name|HaikuViewProxy
operator|::
name|HaikuViewProxy
argument_list|(
name|BWindow
operator|*
name|window
argument_list|,
name|QObject
operator|*
name|parent
argument_list|)
range|:
name|QObject
argument_list|(
name|parent
argument_list|)
decl_stmt|,
name|BView
argument_list|(
name|BRect
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
name|window
operator|->
name|Bounds
argument_list|()
operator|.
name|right
argument_list|,
name|window
operator|->
name|Bounds
argument_list|()
operator|.
name|bottom
argument_list|)
argument_list|,
literal|0
argument_list|,
name|B_FOLLOW_ALL_SIDES
argument_list|,
name|B_WILL_DRAW
operator||
name|B_FRAME_EVENTS
argument_list|)
argument_list|{ }
DECL|function|MessageReceived
name|void
name|HaikuViewProxy
operator|::
name|MessageReceived
argument_list|(
name|BMessage
operator|*
name|message
argument_list|)
argument_list|{     switch
operator|(
name|message
operator|->
name|what
operator|)
block|{
case|case
name|B_MOUSE_WHEEL_CHANGED
case|:
block|{
name|float
name|deltaX
operator|=
literal|0
block|;
if|if
condition|(
name|message
operator|->
name|FindFloat
argument_list|(
literal|"be:wheel_delta_x"
argument_list|,
operator|&
name|deltaX
argument_list|)
operator|!=
name|B_OK
condition|)
name|deltaX
operator|=
literal|0
expr_stmt|;
name|float
name|deltaY
operator|=
literal|0
block|;
if|if
condition|(
name|message
operator|->
name|FindFloat
argument_list|(
literal|"be:wheel_delta_y"
argument_list|,
operator|&
name|deltaY
argument_list|)
operator|!=
name|B_OK
condition|)
name|deltaY
operator|=
literal|0
expr_stmt|;
if|if
condition|(
name|deltaX
operator|!=
literal|0
operator|||
name|deltaY
operator|!=
literal|0
condition|)
block|{
name|BPoint
name|localPos
block|;
name|uint32
name|keyState
operator|=
literal|0
expr_stmt|;
end_decl_stmt
begin_expr_stmt
name|GetMouse
argument_list|(
operator|&
name|localPos
argument_list|,
operator|&
name|keyState
argument_list|)
expr_stmt|;
end_expr_stmt
begin_decl_stmt
specifier|const
name|Qt
operator|::
name|KeyboardModifiers
name|keyboardModifiers
init|=
name|keyStateToModifiers
argument_list|(
name|modifiers
argument_list|()
argument_list|)
decl_stmt|;
end_decl_stmt
begin_decl_stmt
specifier|const
name|BPoint
name|globalPos
init|=
name|ConvertToScreen
argument_list|(
name|localPos
argument_list|)
decl_stmt|;
end_decl_stmt
begin_decl_stmt
specifier|const
name|QPoint
name|globalPosition
init|=
name|QPoint
argument_list|(
name|globalPos
operator|.
name|x
argument_list|,
name|globalPos
operator|.
name|y
argument_list|)
decl_stmt|;
end_decl_stmt
begin_decl_stmt
specifier|const
name|QPoint
name|localPosition
init|=
name|QPoint
argument_list|(
name|localPos
operator|.
name|x
argument_list|,
name|localPos
operator|.
name|y
argument_list|)
decl_stmt|;
end_decl_stmt
begin_if
if|if
condition|(
name|deltaX
operator|!=
literal|0
condition|)
name|Q_EMIT
name|wheelEvent
argument_list|(
name|localPosition
argument_list|,
name|globalPosition
argument_list|,
operator|(
name|deltaX
operator|*
operator|-
literal|120
operator|)
argument_list|,
name|Qt
operator|::
name|Horizontal
argument_list|,
name|keyboardModifiers
argument_list|)
decl_stmt|;
end_if
begin_if
if|if
condition|(
name|deltaY
operator|!=
literal|0
condition|)
name|Q_EMIT
name|wheelEvent
argument_list|(
name|localPosition
argument_list|,
name|globalPosition
argument_list|,
operator|(
name|deltaY
operator|*
operator|-
literal|120
operator|)
argument_list|,
name|Qt
operator|::
name|Vertical
argument_list|,
name|keyboardModifiers
argument_list|)
decl_stmt|;
end_if
begin_empty_stmt
unit|}              break
empty_stmt|;
end_empty_stmt
begin_expr_stmt
unit|}     default:
name|BView
operator|::
name|MessageReceived
argument_list|(
name|message
argument_list|)
expr_stmt|;
end_expr_stmt
begin_break
break|break;
end_break
begin_function
unit|}  }
DECL|function|Draw
name|void
name|HaikuViewProxy
operator|::
name|Draw
parameter_list|(
name|BRect
name|updateRect
parameter_list|)
block|{
name|BView
operator|::
name|Draw
argument_list|(
name|updateRect
argument_list|)
expr_stmt|;
name|Q_EMIT
name|drawRequest
argument_list|(
name|QRect
argument_list|(
name|updateRect
operator|.
name|left
argument_list|,
name|updateRect
operator|.
name|top
argument_list|,
name|updateRect
operator|.
name|Width
argument_list|()
argument_list|,
name|updateRect
operator|.
name|Height
argument_list|()
argument_list|)
argument_list|)
decl_stmt|;
block|}
end_function
begin_function
DECL|function|MouseDown
name|void
name|HaikuViewProxy
operator|::
name|MouseDown
parameter_list|(
name|BPoint
name|localPos
parameter_list|)
block|{
name|BPoint
name|dummyPos
decl_stmt|;
name|uint32
name|keyState
init|=
literal|0
decl_stmt|;
name|GetMouse
argument_list|(
operator|&
name|dummyPos
argument_list|,
operator|&
name|keyState
argument_list|)
expr_stmt|;
specifier|const
name|Qt
operator|::
name|MouseButtons
name|mouseButtons
init|=
name|keyStateToMouseButtons
argument_list|(
name|keyState
argument_list|)
decl_stmt|;
specifier|const
name|Qt
operator|::
name|KeyboardModifiers
name|keyboardModifiers
init|=
name|keyStateToModifiers
argument_list|(
name|modifiers
argument_list|()
argument_list|)
decl_stmt|;
specifier|const
name|Qt
operator|::
name|MouseEventSource
name|source
init|=
name|Qt
operator|::
name|MouseEventNotSynthesized
decl_stmt|;
specifier|const
name|BPoint
name|globalPos
init|=
name|ConvertToScreen
argument_list|(
name|localPos
argument_list|)
decl_stmt|;
specifier|const
name|QPoint
name|globalPosition
init|=
name|QPoint
argument_list|(
name|globalPos
operator|.
name|x
argument_list|,
name|globalPos
operator|.
name|y
argument_list|)
decl_stmt|;
specifier|const
name|QPoint
name|localPosition
init|=
name|QPoint
argument_list|(
name|localPos
operator|.
name|x
argument_list|,
name|localPos
operator|.
name|y
argument_list|)
decl_stmt|;
name|Q_EMIT
name|mouseEvent
argument_list|(
name|localPosition
argument_list|,
name|globalPosition
argument_list|,
name|mouseButtons
argument_list|,
name|keyboardModifiers
argument_list|,
name|source
argument_list|)
decl_stmt|;
block|}
end_function
begin_function
DECL|function|MouseUp
name|void
name|HaikuViewProxy
operator|::
name|MouseUp
parameter_list|(
name|BPoint
name|localPos
parameter_list|)
block|{
name|BPoint
name|dummyPos
decl_stmt|;
name|uint32
name|keyState
init|=
literal|0
decl_stmt|;
name|GetMouse
argument_list|(
operator|&
name|dummyPos
argument_list|,
operator|&
name|keyState
argument_list|)
expr_stmt|;
specifier|const
name|Qt
operator|::
name|MouseButtons
name|mouseButtons
init|=
name|keyStateToMouseButtons
argument_list|(
name|keyState
argument_list|)
decl_stmt|;
specifier|const
name|Qt
operator|::
name|KeyboardModifiers
name|keyboardModifiers
init|=
name|keyStateToModifiers
argument_list|(
name|modifiers
argument_list|()
argument_list|)
decl_stmt|;
specifier|const
name|Qt
operator|::
name|MouseEventSource
name|source
init|=
name|Qt
operator|::
name|MouseEventNotSynthesized
decl_stmt|;
specifier|const
name|BPoint
name|globalPos
init|=
name|ConvertToScreen
argument_list|(
name|localPos
argument_list|)
decl_stmt|;
specifier|const
name|QPoint
name|globalPosition
init|=
name|QPoint
argument_list|(
name|globalPos
operator|.
name|x
argument_list|,
name|globalPos
operator|.
name|y
argument_list|)
decl_stmt|;
specifier|const
name|QPoint
name|localPosition
init|=
name|QPoint
argument_list|(
name|localPos
operator|.
name|x
argument_list|,
name|localPos
operator|.
name|y
argument_list|)
decl_stmt|;
name|Q_EMIT
name|mouseEvent
argument_list|(
name|localPosition
argument_list|,
name|globalPosition
argument_list|,
name|mouseButtons
argument_list|,
name|keyboardModifiers
argument_list|,
name|source
argument_list|)
decl_stmt|;
block|}
end_function
begin_function
DECL|function|MouseMoved
name|void
name|HaikuViewProxy
operator|::
name|MouseMoved
parameter_list|(
name|BPoint
name|pos
parameter_list|,
name|uint32
name|code
parameter_list|,
specifier|const
name|BMessage
modifier|*
name|dragMessage
parameter_list|)
block|{
switch|switch
condition|(
name|code
condition|)
block|{
case|case
name|B_INSIDE_VIEW
case|:
block|{
name|BPoint
name|dummyPos
decl_stmt|;
name|uint32
name|keyState
init|=
literal|0
decl_stmt|;
name|GetMouse
argument_list|(
operator|&
name|dummyPos
argument_list|,
operator|&
name|keyState
argument_list|)
expr_stmt|;
specifier|const
name|Qt
operator|::
name|MouseButtons
name|mouseButtons
init|=
name|keyStateToMouseButtons
argument_list|(
name|keyState
argument_list|)
decl_stmt|;
specifier|const
name|Qt
operator|::
name|KeyboardModifiers
name|keyboardModifiers
init|=
name|keyStateToModifiers
argument_list|(
name|modifiers
argument_list|()
argument_list|)
decl_stmt|;
specifier|const
name|Qt
operator|::
name|MouseEventSource
name|source
init|=
name|Qt
operator|::
name|MouseEventNotSynthesized
decl_stmt|;
specifier|const
name|BPoint
name|globalPos
init|=
name|ConvertToScreen
argument_list|(
name|pos
argument_list|)
decl_stmt|;
specifier|const
name|QPoint
name|globalPosition
init|=
name|QPoint
argument_list|(
name|globalPos
operator|.
name|x
argument_list|,
name|globalPos
operator|.
name|y
argument_list|)
decl_stmt|;
specifier|const
name|QPoint
name|localPosition
init|=
name|QPoint
argument_list|(
name|pos
operator|.
name|x
argument_list|,
name|pos
operator|.
name|y
argument_list|)
decl_stmt|;
name|Q_EMIT
name|mouseEvent
argument_list|(
name|localPosition
argument_list|,
name|globalPosition
argument_list|,
name|mouseButtons
argument_list|,
name|keyboardModifiers
argument_list|,
name|source
argument_list|)
decl_stmt|;
block|}
break|break;
case|case
name|B_ENTERED_VIEW
case|:
name|Q_EMIT
name|enteredView
argument_list|()
decl_stmt|;
break|break;
case|case
name|B_EXITED_VIEW
case|:
name|Q_EMIT
name|exitedView
argument_list|()
decl_stmt|;
break|break;
block|}
name|BView
operator|::
name|MouseMoved
argument_list|(
name|pos
argument_list|,
name|code
argument_list|,
name|dragMessage
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|KeyDown
name|void
name|HaikuViewProxy
operator|::
name|KeyDown
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|int32
parameter_list|)
block|{
name|handleKeyEvent
argument_list|(
name|QEvent
operator|::
name|KeyPress
argument_list|,
name|Window
argument_list|()
operator|->
name|CurrentMessage
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|KeyUp
name|void
name|HaikuViewProxy
operator|::
name|KeyUp
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|int32
parameter_list|)
block|{
name|handleKeyEvent
argument_list|(
name|QEvent
operator|::
name|KeyRelease
argument_list|,
name|Window
argument_list|()
operator|->
name|CurrentMessage
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|keyStateToMouseButtons
name|Qt
operator|::
name|MouseButtons
name|HaikuViewProxy
operator|::
name|keyStateToMouseButtons
parameter_list|(
name|uint32
name|keyState
parameter_list|)
specifier|const
block|{
name|Qt
operator|::
name|MouseButtons
name|mouseButtons
argument_list|(
name|Qt
operator|::
name|NoButton
argument_list|)
decl_stmt|;
if|if
condition|(
name|keyState
operator|&
name|B_PRIMARY_MOUSE_BUTTON
condition|)
name|mouseButtons
operator||=
name|Qt
operator|::
name|LeftButton
expr_stmt|;
if|if
condition|(
name|keyState
operator|&
name|B_SECONDARY_MOUSE_BUTTON
condition|)
name|mouseButtons
operator||=
name|Qt
operator|::
name|RightButton
expr_stmt|;
if|if
condition|(
name|keyState
operator|&
name|B_TERTIARY_MOUSE_BUTTON
condition|)
name|mouseButtons
operator||=
name|Qt
operator|::
name|MiddleButton
expr_stmt|;
return|return
name|mouseButtons
return|;
block|}
end_function
begin_function
DECL|function|keyStateToModifiers
name|Qt
operator|::
name|KeyboardModifiers
name|HaikuViewProxy
operator|::
name|keyStateToModifiers
parameter_list|(
name|uint32
name|keyState
parameter_list|)
specifier|const
block|{
name|Qt
operator|::
name|KeyboardModifiers
name|modifiers
argument_list|(
name|Qt
operator|::
name|NoModifier
argument_list|)
decl_stmt|;
if|if
condition|(
name|keyState
operator|&
name|B_SHIFT_KEY
condition|)
name|modifiers
operator||=
name|Qt
operator|::
name|ShiftModifier
expr_stmt|;
if|if
condition|(
name|keyState
operator|&
name|B_CONTROL_KEY
condition|)
name|modifiers
operator||=
name|Qt
operator|::
name|AltModifier
expr_stmt|;
if|if
condition|(
name|keyState
operator|&
name|B_COMMAND_KEY
condition|)
name|modifiers
operator||=
name|Qt
operator|::
name|ControlModifier
expr_stmt|;
return|return
name|modifiers
return|;
block|}
end_function
begin_function
DECL|function|handleKeyEvent
name|void
name|HaikuViewProxy
operator|::
name|handleKeyEvent
parameter_list|(
name|QEvent
operator|::
name|Type
name|type
parameter_list|,
name|BMessage
modifier|*
name|message
parameter_list|)
block|{
name|int32
name|key
init|=
literal|0
decl_stmt|;
name|uint32
name|code
init|=
literal|0
decl_stmt|;
specifier|const
name|char
modifier|*
name|bytes
init|=
name|Q_NULLPTR
decl_stmt|;
name|QString
name|text
decl_stmt|;
if|if
condition|(
name|message
condition|)
block|{
if|if
condition|(
name|message
operator|->
name|FindString
argument_list|(
literal|"bytes"
argument_list|,
operator|&
name|bytes
argument_list|)
operator|==
name|B_OK
condition|)
block|{
name|text
operator|=
name|QString
operator|::
name|fromLocal8Bit
argument_list|(
name|bytes
argument_list|,
name|strlen
argument_list|(
name|bytes
argument_list|)
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|message
operator|->
name|FindInt32
argument_list|(
literal|"key"
argument_list|,
operator|&
name|key
argument_list|)
operator|==
name|B_OK
condition|)
block|{
name|code
operator|=
name|QHaikuKeyMapper
operator|::
name|translateKeyCode
argument_list|(
name|key
argument_list|,
operator|(
name|modifiers
argument_list|()
operator|&
name|B_NUM_LOCK
operator|)
argument_list|)
expr_stmt|;
block|}
block|}
specifier|const
name|Qt
operator|::
name|KeyboardModifiers
name|keyboardModifiers
init|=
name|keyStateToModifiers
argument_list|(
name|modifiers
argument_list|()
argument_list|)
decl_stmt|;
name|Q_EMIT
name|keyEvent
argument_list|(
name|type
argument_list|,
name|code
argument_list|,
name|keyboardModifiers
argument_list|,
name|text
argument_list|)
decl_stmt|;
block|}
end_function
begin_constructor
DECL|function|QHaikuRasterWindow
name|QHaikuRasterWindow
operator|::
name|QHaikuRasterWindow
parameter_list|(
name|QWindow
modifier|*
name|window
parameter_list|)
member_init_list|:
name|QHaikuWindow
argument_list|(
name|window
argument_list|)
block|{
name|qRegisterMetaType
argument_list|<
name|QEvent
operator|::
name|Type
argument_list|>
argument_list|()
expr_stmt|;
name|qRegisterMetaType
argument_list|<
name|Qt
operator|::
name|MouseButtons
argument_list|>
argument_list|()
expr_stmt|;
name|qRegisterMetaType
argument_list|<
name|Qt
operator|::
name|MouseEventSource
argument_list|>
argument_list|()
expr_stmt|;
name|qRegisterMetaType
argument_list|<
name|Qt
operator|::
name|KeyboardModifiers
argument_list|>
argument_list|()
expr_stmt|;
name|qRegisterMetaType
argument_list|<
name|Qt
operator|::
name|Orientation
argument_list|>
argument_list|()
expr_stmt|;
name|HaikuViewProxy
modifier|*
name|haikuView
init|=
operator|new
name|HaikuViewProxy
argument_list|(
name|m_window
argument_list|)
decl_stmt|;
name|connect
argument_list|(
name|haikuView
argument_list|,
name|SIGNAL
argument_list|(
name|mouseEvent
argument_list|(
name|QPoint
argument_list|,
name|QPoint
argument_list|,
name|Qt
operator|::
name|MouseButtons
argument_list|,
name|Qt
operator|::
name|KeyboardModifiers
argument_list|,
name|Qt
operator|::
name|MouseEventSource
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|haikuMouseEvent
argument_list|(
name|QPoint
argument_list|,
name|QPoint
argument_list|,
name|Qt
operator|::
name|MouseButtons
argument_list|,
name|Qt
operator|::
name|KeyboardModifiers
argument_list|,
name|Qt
operator|::
name|MouseEventSource
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|haikuView
argument_list|,
name|SIGNAL
argument_list|(
name|wheelEvent
argument_list|(
name|QPoint
argument_list|,
name|QPoint
argument_list|,
name|int
argument_list|,
name|Qt
operator|::
name|Orientation
argument_list|,
name|Qt
operator|::
name|KeyboardModifiers
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|haikuWheelEvent
argument_list|(
name|QPoint
argument_list|,
name|QPoint
argument_list|,
name|int
argument_list|,
name|Qt
operator|::
name|Orientation
argument_list|,
name|Qt
operator|::
name|KeyboardModifiers
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|haikuView
argument_list|,
name|SIGNAL
argument_list|(
name|keyEvent
argument_list|(
name|QEvent
operator|::
name|Type
argument_list|,
name|int
argument_list|,
name|Qt
operator|::
name|KeyboardModifiers
argument_list|,
name|QString
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|haikuKeyEvent
argument_list|(
name|QEvent
operator|::
name|Type
argument_list|,
name|int
argument_list|,
name|Qt
operator|::
name|KeyboardModifiers
argument_list|,
name|QString
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|haikuView
argument_list|,
name|SIGNAL
argument_list|(
name|enteredView
argument_list|()
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|haikuEnteredView
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|haikuView
argument_list|,
name|SIGNAL
argument_list|(
name|exitedView
argument_list|()
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|haikuExitedView
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|haikuView
argument_list|,
name|SIGNAL
argument_list|(
name|drawRequest
argument_list|(
name|QRect
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|haikuDrawRequest
argument_list|(
name|QRect
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|m_view
operator|=
name|haikuView
expr_stmt|;
name|m_window
operator|->
name|LockLooper
argument_list|()
expr_stmt|;
name|m_window
operator|->
name|AddChild
argument_list|(
name|m_view
argument_list|)
expr_stmt|;
name|m_view
operator|->
name|MakeFocus
argument_list|()
expr_stmt|;
name|m_window
operator|->
name|UnlockLooper
argument_list|()
expr_stmt|;
block|}
end_constructor
begin_destructor
DECL|function|~QHaikuRasterWindow
name|QHaikuRasterWindow
operator|::
name|~
name|QHaikuRasterWindow
parameter_list|()
block|{
name|m_window
operator|->
name|LockLooper
argument_list|()
expr_stmt|;
name|m_view
operator|->
name|RemoveSelf
argument_list|()
expr_stmt|;
name|m_window
operator|->
name|UnlockLooper
argument_list|()
expr_stmt|;
operator|delete
name|m_view
expr_stmt|;
name|m_view
operator|=
name|Q_NULLPTR
expr_stmt|;
block|}
end_destructor
begin_function
DECL|function|nativeViewHandle
name|BView
modifier|*
name|QHaikuRasterWindow
operator|::
name|nativeViewHandle
parameter_list|()
specifier|const
block|{
return|return
name|m_view
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
