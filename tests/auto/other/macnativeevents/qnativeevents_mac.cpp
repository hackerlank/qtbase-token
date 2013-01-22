begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qnativeevents.h"
end_include
begin_include
include|#
directive|include
file|<Carbon/Carbon.h>
end_include
begin_include
include|#
directive|include
file|<QtCore>
end_include
begin_comment
comment|//  ************************************************************
end_comment
begin_comment
comment|//  Quartz
end_comment
begin_comment
comment|//  ************************************************************
end_comment
begin_function
DECL|function|getModifiersFromQuartzEvent
specifier|static
name|Qt
operator|::
name|KeyboardModifiers
name|getModifiersFromQuartzEvent
parameter_list|(
name|CGEventRef
name|inEvent
parameter_list|)
block|{
name|Qt
operator|::
name|KeyboardModifiers
name|m
decl_stmt|;
name|CGEventFlags
name|flags
init|=
name|CGEventGetFlags
argument_list|(
name|inEvent
argument_list|)
decl_stmt|;
if|if
condition|(
name|flags
operator|&
name|kCGEventFlagMaskShift
operator|||
name|flags
operator|&
name|kCGEventFlagMaskAlphaShift
condition|)
name|m
operator||=
name|Qt
operator|::
name|ShiftModifier
expr_stmt|;
if|if
condition|(
name|flags
operator|&
name|kCGEventFlagMaskControl
condition|)
name|m
operator||=
name|Qt
operator|::
name|ControlModifier
expr_stmt|;
if|if
condition|(
name|flags
operator|&
name|kCGEventFlagMaskAlternate
condition|)
name|m
operator||=
name|Qt
operator|::
name|AltModifier
expr_stmt|;
if|if
condition|(
name|flags
operator|&
name|kCGEventFlagMaskCommand
condition|)
name|m
operator||=
name|Qt
operator|::
name|MetaModifier
expr_stmt|;
return|return
name|m
return|;
block|}
end_function
begin_function
DECL|function|setModifiersFromQNativeEvent
specifier|static
name|void
name|setModifiersFromQNativeEvent
parameter_list|(
name|CGEventRef
name|inEvent
parameter_list|,
specifier|const
name|QNativeEvent
modifier|&
name|event
parameter_list|)
block|{
name|CGEventFlags
name|flags
init|=
literal|0
decl_stmt|;
if|if
condition|(
name|event
operator|.
name|modifiers
operator|.
name|testFlag
argument_list|(
name|Qt
operator|::
name|ShiftModifier
argument_list|)
condition|)
name|flags
operator||=
name|kCGEventFlagMaskShift
expr_stmt|;
if|if
condition|(
name|event
operator|.
name|modifiers
operator|.
name|testFlag
argument_list|(
name|Qt
operator|::
name|ControlModifier
argument_list|)
condition|)
name|flags
operator||=
name|kCGEventFlagMaskControl
expr_stmt|;
if|if
condition|(
name|event
operator|.
name|modifiers
operator|.
name|testFlag
argument_list|(
name|Qt
operator|::
name|AltModifier
argument_list|)
condition|)
name|flags
operator||=
name|kCGEventFlagMaskAlternate
expr_stmt|;
if|if
condition|(
name|event
operator|.
name|modifiers
operator|.
name|testFlag
argument_list|(
name|Qt
operator|::
name|MetaModifier
argument_list|)
condition|)
name|flags
operator||=
name|kCGEventFlagMaskCommand
expr_stmt|;
name|CGEventSetFlags
argument_list|(
name|inEvent
argument_list|,
name|flags
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|getMouseLocationFromQuartzEvent
specifier|static
name|QPoint
name|getMouseLocationFromQuartzEvent
parameter_list|(
name|CGEventRef
name|inEvent
parameter_list|)
block|{
name|CGPoint
name|pos
init|=
name|CGEventGetLocation
argument_list|(
name|inEvent
argument_list|)
decl_stmt|;
name|QPoint
name|tmp
decl_stmt|;
name|tmp
operator|.
name|setX
argument_list|(
name|pos
operator|.
name|x
argument_list|)
expr_stmt|;
name|tmp
operator|.
name|setY
argument_list|(
name|pos
operator|.
name|y
argument_list|)
expr_stmt|;
return|return
name|tmp
return|;
block|}
end_function
begin_function
DECL|function|getCharFromQuartzEvent
specifier|static
name|QChar
name|getCharFromQuartzEvent
parameter_list|(
name|CGEventRef
name|inEvent
parameter_list|)
block|{
name|UniCharCount
name|count
init|=
literal|0
decl_stmt|;
name|UniChar
name|c
decl_stmt|;
name|CGEventKeyboardGetUnicodeString
argument_list|(
name|inEvent
argument_list|,
literal|1
argument_list|,
operator|&
name|count
argument_list|,
operator|&
name|c
argument_list|)
expr_stmt|;
return|return
name|QChar
argument_list|(
name|c
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|EventHandler_Quartz
specifier|static
name|CGEventRef
name|EventHandler_Quartz
parameter_list|(
name|CGEventTapProxy
name|proxy
parameter_list|,
name|CGEventType
name|type
parameter_list|,
name|CGEventRef
name|inEvent
parameter_list|,
name|void
modifier|*
name|refCon
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
name|proxy
argument_list|)
expr_stmt|;
name|QNativeInput
modifier|*
name|nativeInput
init|=
cast|static_cast
argument_list|<
name|QNativeInput
operator|*
argument_list|>
argument_list|(
name|refCon
argument_list|)
decl_stmt|;
switch|switch
condition|(
name|type
condition|)
block|{
case|case
name|kCGEventKeyDown
case|:
block|{
name|QNativeKeyEvent
name|e
decl_stmt|;
name|e
operator|.
name|modifiers
operator|=
name|getModifiersFromQuartzEvent
argument_list|(
name|inEvent
argument_list|)
expr_stmt|;
name|e
operator|.
name|nativeKeyCode
operator|=
name|CGEventGetIntegerValueField
argument_list|(
name|inEvent
argument_list|,
name|kCGKeyboardEventKeycode
argument_list|)
expr_stmt|;
name|e
operator|.
name|character
operator|=
name|getCharFromQuartzEvent
argument_list|(
name|inEvent
argument_list|)
expr_stmt|;
name|e
operator|.
name|press
operator|=
literal|true
expr_stmt|;
name|nativeInput
operator|->
name|notify
argument_list|(
operator|&
name|e
argument_list|)
expr_stmt|;
break|break;
block|}
case|case
name|kCGEventKeyUp
case|:
block|{
name|QNativeKeyEvent
name|e
decl_stmt|;
name|e
operator|.
name|modifiers
operator|=
name|getModifiersFromQuartzEvent
argument_list|(
name|inEvent
argument_list|)
expr_stmt|;
name|e
operator|.
name|nativeKeyCode
operator|=
name|CGEventGetIntegerValueField
argument_list|(
name|inEvent
argument_list|,
name|kCGKeyboardEventKeycode
argument_list|)
expr_stmt|;
name|e
operator|.
name|character
operator|=
name|getCharFromQuartzEvent
argument_list|(
name|inEvent
argument_list|)
expr_stmt|;
name|e
operator|.
name|press
operator|=
literal|false
expr_stmt|;
name|nativeInput
operator|->
name|notify
argument_list|(
operator|&
name|e
argument_list|)
expr_stmt|;
break|break;
block|}
case|case
name|kCGEventLeftMouseDown
case|:
block|{
name|QNativeMouseButtonEvent
name|e
decl_stmt|;
name|e
operator|.
name|modifiers
operator|=
name|getModifiersFromQuartzEvent
argument_list|(
name|inEvent
argument_list|)
expr_stmt|;
name|e
operator|.
name|globalPos
operator|=
name|getMouseLocationFromQuartzEvent
argument_list|(
name|inEvent
argument_list|)
expr_stmt|;
name|e
operator|.
name|clickCount
operator|=
name|CGEventGetIntegerValueField
argument_list|(
name|inEvent
argument_list|,
name|kCGMouseEventClickState
argument_list|)
expr_stmt|;
name|e
operator|.
name|button
operator|=
name|Qt
operator|::
name|LeftButton
expr_stmt|;
name|nativeInput
operator|->
name|notify
argument_list|(
operator|&
name|e
argument_list|)
expr_stmt|;
break|break;
block|}
case|case
name|kCGEventLeftMouseUp
case|:
block|{
name|QNativeMouseButtonEvent
name|e
decl_stmt|;
name|e
operator|.
name|modifiers
operator|=
name|getModifiersFromQuartzEvent
argument_list|(
name|inEvent
argument_list|)
expr_stmt|;
name|e
operator|.
name|globalPos
operator|=
name|getMouseLocationFromQuartzEvent
argument_list|(
name|inEvent
argument_list|)
expr_stmt|;
name|e
operator|.
name|clickCount
operator|=
literal|0
expr_stmt|;
name|e
operator|.
name|button
operator|=
name|Qt
operator|::
name|LeftButton
expr_stmt|;
name|nativeInput
operator|->
name|notify
argument_list|(
operator|&
name|e
argument_list|)
expr_stmt|;
break|break;
block|}
case|case
name|kCGEventRightMouseDown
case|:
block|{
name|QNativeMouseButtonEvent
name|e
decl_stmt|;
name|e
operator|.
name|modifiers
operator|=
name|getModifiersFromQuartzEvent
argument_list|(
name|inEvent
argument_list|)
expr_stmt|;
name|e
operator|.
name|globalPos
operator|=
name|getMouseLocationFromQuartzEvent
argument_list|(
name|inEvent
argument_list|)
expr_stmt|;
name|e
operator|.
name|clickCount
operator|=
name|CGEventGetIntegerValueField
argument_list|(
name|inEvent
argument_list|,
name|kCGMouseEventClickState
argument_list|)
expr_stmt|;
name|e
operator|.
name|button
operator|=
name|Qt
operator|::
name|RightButton
expr_stmt|;
name|nativeInput
operator|->
name|notify
argument_list|(
operator|&
name|e
argument_list|)
expr_stmt|;
break|break;
block|}
case|case
name|kCGEventRightMouseUp
case|:
block|{
name|QNativeMouseButtonEvent
name|e
decl_stmt|;
name|e
operator|.
name|modifiers
operator|=
name|getModifiersFromQuartzEvent
argument_list|(
name|inEvent
argument_list|)
expr_stmt|;
name|e
operator|.
name|globalPos
operator|=
name|getMouseLocationFromQuartzEvent
argument_list|(
name|inEvent
argument_list|)
expr_stmt|;
name|e
operator|.
name|clickCount
operator|=
literal|0
expr_stmt|;
name|e
operator|.
name|button
operator|=
name|Qt
operator|::
name|RightButton
expr_stmt|;
name|nativeInput
operator|->
name|notify
argument_list|(
operator|&
name|e
argument_list|)
expr_stmt|;
break|break;
block|}
case|case
name|kCGEventMouseMoved
case|:
block|{
name|QNativeMouseMoveEvent
name|e
decl_stmt|;
name|e
operator|.
name|modifiers
operator|=
name|getModifiersFromQuartzEvent
argument_list|(
name|inEvent
argument_list|)
expr_stmt|;
name|e
operator|.
name|globalPos
operator|=
name|getMouseLocationFromQuartzEvent
argument_list|(
name|inEvent
argument_list|)
expr_stmt|;
name|nativeInput
operator|->
name|notify
argument_list|(
operator|&
name|e
argument_list|)
expr_stmt|;
break|break;
block|}
case|case
name|kCGEventLeftMouseDragged
case|:
block|{
name|QNativeMouseDragEvent
name|e
decl_stmt|;
name|e
operator|.
name|modifiers
operator|=
name|getModifiersFromQuartzEvent
argument_list|(
name|inEvent
argument_list|)
expr_stmt|;
name|e
operator|.
name|globalPos
operator|=
name|getMouseLocationFromQuartzEvent
argument_list|(
name|inEvent
argument_list|)
expr_stmt|;
name|e
operator|.
name|clickCount
operator|=
name|CGEventGetIntegerValueField
argument_list|(
name|inEvent
argument_list|,
name|kCGMouseEventClickState
argument_list|)
expr_stmt|;
name|e
operator|.
name|button
operator|=
name|Qt
operator|::
name|LeftButton
expr_stmt|;
name|nativeInput
operator|->
name|notify
argument_list|(
operator|&
name|e
argument_list|)
expr_stmt|;
break|break;
block|}
case|case
name|kCGEventScrollWheel
case|:
block|{
name|QNativeMouseWheelEvent
name|e
decl_stmt|;
name|e
operator|.
name|modifiers
operator|=
name|getModifiersFromQuartzEvent
argument_list|(
name|inEvent
argument_list|)
expr_stmt|;
name|e
operator|.
name|delta
operator|=
name|CGEventGetIntegerValueField
argument_list|(
name|inEvent
argument_list|,
name|kCGScrollWheelEventDeltaAxis1
argument_list|)
expr_stmt|;
name|e
operator|.
name|globalPos
operator|=
name|getMouseLocationFromQuartzEvent
argument_list|(
name|inEvent
argument_list|)
expr_stmt|;
name|nativeInput
operator|->
name|notify
argument_list|(
operator|&
name|e
argument_list|)
expr_stmt|;
break|break;
block|}
case|case
name|kCGEventFlagsChanged
case|:
block|{
name|QNativeModifierEvent
name|e
decl_stmt|;
name|e
operator|.
name|modifiers
operator|=
name|getModifiersFromQuartzEvent
argument_list|(
name|inEvent
argument_list|)
expr_stmt|;
name|e
operator|.
name|nativeKeyCode
operator|=
name|CGEventGetIntegerValueField
argument_list|(
name|inEvent
argument_list|,
name|kCGKeyboardEventKeycode
argument_list|)
expr_stmt|;
name|nativeInput
operator|->
name|notify
argument_list|(
operator|&
name|e
argument_list|)
expr_stmt|;
break|break;
block|}
block|}
return|return
name|inEvent
return|;
block|}
end_function
begin_function
DECL|function|insertEventHandler_Quartz
name|Qt
operator|::
name|Native
operator|::
name|Status
name|insertEventHandler_Quartz
parameter_list|(
name|QNativeInput
modifier|*
name|nativeInput
parameter_list|,
name|int
name|pid
init|=
literal|0
parameter_list|)
block|{
name|uid_t
name|uid
init|=
name|geteuid
argument_list|()
decl_stmt|;
if|if
condition|(
name|uid
operator|!=
literal|0
condition|)
name|qWarning
argument_list|(
literal|"MacNativeEvents: You must be root to listen for key events!"
argument_list|)
expr_stmt|;
name|CFMachPortRef
name|port
decl_stmt|;
if|if
condition|(
operator|!
name|pid
condition|)
block|{
name|port
operator|=
name|CGEventTapCreate
argument_list|(
name|kCGHIDEventTap
argument_list|,
name|kCGHeadInsertEventTap
argument_list|,
name|kCGEventTapOptionListenOnly
argument_list|,
name|kCGEventMaskForAllEvents
argument_list|,
name|EventHandler_Quartz
argument_list|,
name|nativeInput
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|ProcessSerialNumber
name|psn
decl_stmt|;
name|GetProcessForPID
argument_list|(
name|pid
argument_list|,
operator|&
name|psn
argument_list|)
expr_stmt|;
name|port
operator|=
name|CGEventTapCreateForPSN
argument_list|(
operator|&
name|psn
argument_list|,
name|kCGHeadInsertEventTap
argument_list|,
name|kCGEventTapOptionListenOnly
argument_list|,
name|kCGEventMaskForAllEvents
argument_list|,
name|EventHandler_Quartz
argument_list|,
name|nativeInput
argument_list|)
expr_stmt|;
block|}
name|CFRunLoopSourceRef
name|eventSrc
init|=
name|CFMachPortCreateRunLoopSource
argument_list|(
name|NULL
argument_list|,
name|port
argument_list|,
literal|0
argument_list|)
decl_stmt|;
name|CFRunLoopAddSource
argument_list|(
operator|(
name|CFRunLoopRef
operator|)
name|GetCFRunLoopFromEventLoop
argument_list|(
name|GetMainEventLoop
argument_list|()
argument_list|)
argument_list|,
name|eventSrc
argument_list|,
name|kCFRunLoopCommonModes
argument_list|)
expr_stmt|;
return|return
name|Qt
operator|::
name|Native
operator|::
name|Success
return|;
block|}
end_function
begin_function
DECL|function|removeEventHandler_Quartz
name|Qt
operator|::
name|Native
operator|::
name|Status
name|removeEventHandler_Quartz
parameter_list|()
block|{
return|return
name|Qt
operator|::
name|Native
operator|::
name|Success
return|;
comment|// ToDo:
block|}
end_function
begin_function
DECL|function|sendNativeKeyEventToProcess_Quartz
name|Qt
operator|::
name|Native
operator|::
name|Status
name|sendNativeKeyEventToProcess_Quartz
parameter_list|(
specifier|const
name|QNativeKeyEvent
modifier|&
name|event
parameter_list|,
name|int
name|pid
parameter_list|)
block|{
name|ProcessSerialNumber
name|psn
decl_stmt|;
name|GetProcessForPID
argument_list|(
name|pid
argument_list|,
operator|&
name|psn
argument_list|)
expr_stmt|;
name|CGEventRef
name|e
init|=
name|CGEventCreateKeyboardEvent
argument_list|(
literal|0
argument_list|,
operator|(
name|uint
operator|)
name|event
operator|.
name|nativeKeyCode
argument_list|,
name|event
operator|.
name|press
argument_list|)
decl_stmt|;
name|setModifiersFromQNativeEvent
argument_list|(
name|e
argument_list|,
name|event
argument_list|)
expr_stmt|;
name|SetFrontProcess
argument_list|(
operator|&
name|psn
argument_list|)
expr_stmt|;
name|CGEventPostToPSN
argument_list|(
operator|&
name|psn
argument_list|,
name|e
argument_list|)
expr_stmt|;
name|CFRelease
argument_list|(
name|e
argument_list|)
expr_stmt|;
return|return
name|Qt
operator|::
name|Native
operator|::
name|Success
return|;
block|}
end_function
begin_function
DECL|function|sendNativeKeyEvent_Quartz
name|Qt
operator|::
name|Native
operator|::
name|Status
name|sendNativeKeyEvent_Quartz
parameter_list|(
specifier|const
name|QNativeKeyEvent
modifier|&
name|event
parameter_list|)
block|{
name|CGEventRef
name|e
init|=
name|CGEventCreateKeyboardEvent
argument_list|(
literal|0
argument_list|,
operator|(
name|uint
operator|)
name|event
operator|.
name|nativeKeyCode
argument_list|,
name|event
operator|.
name|press
argument_list|)
decl_stmt|;
name|setModifiersFromQNativeEvent
argument_list|(
name|e
argument_list|,
name|event
argument_list|)
expr_stmt|;
name|CGEventPost
argument_list|(
name|kCGHIDEventTap
argument_list|,
name|e
argument_list|)
expr_stmt|;
name|CFRelease
argument_list|(
name|e
argument_list|)
expr_stmt|;
return|return
name|Qt
operator|::
name|Native
operator|::
name|Success
return|;
block|}
end_function
begin_function
DECL|function|sendNativeMouseMoveEvent_Quartz
name|Qt
operator|::
name|Native
operator|::
name|Status
name|sendNativeMouseMoveEvent_Quartz
parameter_list|(
specifier|const
name|QNativeMouseMoveEvent
modifier|&
name|event
parameter_list|)
block|{
name|CGPoint
name|pos
decl_stmt|;
name|pos
operator|.
name|x
operator|=
name|event
operator|.
name|globalPos
operator|.
name|x
argument_list|()
expr_stmt|;
name|pos
operator|.
name|y
operator|=
name|event
operator|.
name|globalPos
operator|.
name|y
argument_list|()
expr_stmt|;
name|CGEventRef
name|e
init|=
name|CGEventCreateMouseEvent
argument_list|(
literal|0
argument_list|,
name|kCGEventMouseMoved
argument_list|,
name|pos
argument_list|,
literal|0
argument_list|)
decl_stmt|;
name|setModifiersFromQNativeEvent
argument_list|(
name|e
argument_list|,
name|event
argument_list|)
expr_stmt|;
name|CGEventPost
argument_list|(
name|kCGHIDEventTap
argument_list|,
name|e
argument_list|)
expr_stmt|;
name|CFRelease
argument_list|(
name|e
argument_list|)
expr_stmt|;
return|return
name|Qt
operator|::
name|Native
operator|::
name|Success
return|;
block|}
end_function
begin_function
DECL|function|sendNativeMouseButtonEvent_Quartz
name|Qt
operator|::
name|Native
operator|::
name|Status
name|sendNativeMouseButtonEvent_Quartz
parameter_list|(
specifier|const
name|QNativeMouseButtonEvent
modifier|&
name|event
parameter_list|)
block|{
name|CGPoint
name|pos
decl_stmt|;
name|pos
operator|.
name|x
operator|=
name|event
operator|.
name|globalPos
operator|.
name|x
argument_list|()
expr_stmt|;
name|pos
operator|.
name|y
operator|=
name|event
operator|.
name|globalPos
operator|.
name|y
argument_list|()
expr_stmt|;
name|CGEventType
name|type
init|=
literal|0
decl_stmt|;
if|if
condition|(
name|event
operator|.
name|button
operator|==
name|Qt
operator|::
name|LeftButton
condition|)
name|type
operator|=
operator|(
name|event
operator|.
name|clickCount
operator|>
literal|0
operator|)
condition|?
name|kCGEventLeftMouseDown
else|:
name|kCGEventLeftMouseUp
expr_stmt|;
elseif|else
if|if
condition|(
name|event
operator|.
name|button
operator|==
name|Qt
operator|::
name|RightButton
condition|)
name|type
operator|=
operator|(
name|event
operator|.
name|clickCount
operator|>
literal|0
operator|)
condition|?
name|kCGEventRightMouseDown
else|:
name|kCGEventRightMouseUp
expr_stmt|;
else|else
name|type
operator|=
operator|(
name|event
operator|.
name|clickCount
operator|>
literal|0
operator|)
condition|?
name|kCGEventOtherMouseDown
else|:
name|kCGEventOtherMouseUp
expr_stmt|;
name|CGEventRef
name|e
init|=
name|CGEventCreateMouseEvent
argument_list|(
literal|0
argument_list|,
name|type
argument_list|,
name|pos
argument_list|,
name|event
operator|.
name|button
argument_list|)
decl_stmt|;
name|setModifiersFromQNativeEvent
argument_list|(
name|e
argument_list|,
name|event
argument_list|)
expr_stmt|;
name|CGEventSetIntegerValueField
argument_list|(
name|e
argument_list|,
name|kCGMouseEventClickState
argument_list|,
name|event
operator|.
name|clickCount
argument_list|)
expr_stmt|;
name|CGEventPost
argument_list|(
name|kCGHIDEventTap
argument_list|,
name|e
argument_list|)
expr_stmt|;
name|CFRelease
argument_list|(
name|e
argument_list|)
expr_stmt|;
return|return
name|Qt
operator|::
name|Native
operator|::
name|Success
return|;
block|}
end_function
begin_function
DECL|function|sendNativeMouseDragEvent_Quartz
name|Qt
operator|::
name|Native
operator|::
name|Status
name|sendNativeMouseDragEvent_Quartz
parameter_list|(
specifier|const
name|QNativeMouseDragEvent
modifier|&
name|event
parameter_list|)
block|{
name|CGPoint
name|pos
decl_stmt|;
name|pos
operator|.
name|x
operator|=
name|event
operator|.
name|globalPos
operator|.
name|x
argument_list|()
expr_stmt|;
name|pos
operator|.
name|y
operator|=
name|event
operator|.
name|globalPos
operator|.
name|y
argument_list|()
expr_stmt|;
name|CGEventType
name|type
init|=
literal|0
decl_stmt|;
if|if
condition|(
name|event
operator|.
name|button
operator|==
name|Qt
operator|::
name|LeftButton
condition|)
name|type
operator|=
name|kCGEventLeftMouseDragged
expr_stmt|;
elseif|else
if|if
condition|(
name|event
operator|.
name|button
operator|==
name|Qt
operator|::
name|RightButton
condition|)
name|type
operator|=
name|kCGEventRightMouseDragged
expr_stmt|;
else|else
name|type
operator|=
name|kCGEventOtherMouseDragged
expr_stmt|;
name|CGEventRef
name|e
init|=
name|CGEventCreateMouseEvent
argument_list|(
literal|0
argument_list|,
name|type
argument_list|,
name|pos
argument_list|,
name|event
operator|.
name|button
argument_list|)
decl_stmt|;
name|setModifiersFromQNativeEvent
argument_list|(
name|e
argument_list|,
name|event
argument_list|)
expr_stmt|;
name|CGEventPost
argument_list|(
name|kCGHIDEventTap
argument_list|,
name|e
argument_list|)
expr_stmt|;
name|CFRelease
argument_list|(
name|e
argument_list|)
expr_stmt|;
return|return
name|Qt
operator|::
name|Native
operator|::
name|Success
return|;
block|}
end_function
begin_function
DECL|function|sendNativeMouseWheelEvent_Quartz
name|Qt
operator|::
name|Native
operator|::
name|Status
name|sendNativeMouseWheelEvent_Quartz
parameter_list|(
specifier|const
name|QNativeMouseWheelEvent
modifier|&
name|event
parameter_list|)
block|{
name|CGPoint
name|pos
decl_stmt|;
name|pos
operator|.
name|x
operator|=
name|event
operator|.
name|globalPos
operator|.
name|x
argument_list|()
expr_stmt|;
name|pos
operator|.
name|y
operator|=
name|event
operator|.
name|globalPos
operator|.
name|y
argument_list|()
expr_stmt|;
name|CGEventRef
name|e
init|=
name|CGEventCreateScrollWheelEvent
argument_list|(
literal|0
argument_list|,
name|kCGScrollEventUnitPixel
argument_list|,
literal|1
argument_list|,
literal|0
argument_list|)
decl_stmt|;
name|CGEventSetIntegerValueField
argument_list|(
name|e
argument_list|,
name|kCGScrollWheelEventDeltaAxis1
argument_list|,
name|event
operator|.
name|delta
argument_list|)
expr_stmt|;
name|CGEventSetLocation
argument_list|(
name|e
argument_list|,
name|pos
argument_list|)
expr_stmt|;
name|setModifiersFromQNativeEvent
argument_list|(
name|e
argument_list|,
name|event
argument_list|)
expr_stmt|;
name|CGEventPost
argument_list|(
name|kCGHIDEventTap
argument_list|,
name|e
argument_list|)
expr_stmt|;
name|CFRelease
argument_list|(
name|e
argument_list|)
expr_stmt|;
return|return
name|Qt
operator|::
name|Native
operator|::
name|Success
return|;
block|}
end_function
begin_function
DECL|function|sendNativeModifierEvent_Quartz
name|Qt
operator|::
name|Native
operator|::
name|Status
name|sendNativeModifierEvent_Quartz
parameter_list|(
specifier|const
name|QNativeModifierEvent
modifier|&
name|event
parameter_list|)
block|{
name|CGEventRef
name|e
init|=
name|CGEventCreateKeyboardEvent
argument_list|(
literal|0
argument_list|,
operator|(
name|uint
operator|)
name|event
operator|.
name|nativeKeyCode
argument_list|,
literal|0
argument_list|)
decl_stmt|;
name|CGEventSetType
argument_list|(
name|e
argument_list|,
name|kCGEventFlagsChanged
argument_list|)
expr_stmt|;
name|setModifiersFromQNativeEvent
argument_list|(
name|e
argument_list|,
name|event
argument_list|)
expr_stmt|;
name|CGEventPost
argument_list|(
name|kCGHIDEventTap
argument_list|,
name|e
argument_list|)
expr_stmt|;
name|CFRelease
argument_list|(
name|e
argument_list|)
expr_stmt|;
return|return
name|Qt
operator|::
name|Native
operator|::
name|Success
return|;
block|}
end_function
begin_comment
comment|//  ************************************************************
end_comment
begin_comment
comment|//  QNativeInput methods:
end_comment
begin_comment
comment|//  ************************************************************
end_comment
begin_function
DECL|function|sendNativeMouseButtonEvent
name|Qt
operator|::
name|Native
operator|::
name|Status
name|QNativeInput
operator|::
name|sendNativeMouseButtonEvent
parameter_list|(
specifier|const
name|QNativeMouseButtonEvent
modifier|&
name|event
parameter_list|)
block|{
return|return
name|sendNativeMouseButtonEvent_Quartz
argument_list|(
name|event
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|sendNativeMouseMoveEvent
name|Qt
operator|::
name|Native
operator|::
name|Status
name|QNativeInput
operator|::
name|sendNativeMouseMoveEvent
parameter_list|(
specifier|const
name|QNativeMouseMoveEvent
modifier|&
name|event
parameter_list|)
block|{
return|return
name|sendNativeMouseMoveEvent_Quartz
argument_list|(
name|event
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|sendNativeMouseDragEvent
name|Qt
operator|::
name|Native
operator|::
name|Status
name|QNativeInput
operator|::
name|sendNativeMouseDragEvent
parameter_list|(
specifier|const
name|QNativeMouseDragEvent
modifier|&
name|event
parameter_list|)
block|{
return|return
name|sendNativeMouseDragEvent_Quartz
argument_list|(
name|event
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|sendNativeMouseWheelEvent
name|Qt
operator|::
name|Native
operator|::
name|Status
name|QNativeInput
operator|::
name|sendNativeMouseWheelEvent
parameter_list|(
specifier|const
name|QNativeMouseWheelEvent
modifier|&
name|event
parameter_list|)
block|{
return|return
name|sendNativeMouseWheelEvent_Quartz
argument_list|(
name|event
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|sendNativeKeyEvent
name|Qt
operator|::
name|Native
operator|::
name|Status
name|QNativeInput
operator|::
name|sendNativeKeyEvent
parameter_list|(
specifier|const
name|QNativeKeyEvent
modifier|&
name|event
parameter_list|,
name|int
name|pid
parameter_list|)
block|{
if|if
condition|(
operator|!
name|pid
condition|)
return|return
name|sendNativeKeyEvent_Quartz
argument_list|(
name|event
argument_list|)
return|;
else|else
return|return
name|sendNativeKeyEventToProcess_Quartz
argument_list|(
name|event
argument_list|,
name|pid
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|sendNativeModifierEvent
name|Qt
operator|::
name|Native
operator|::
name|Status
name|QNativeInput
operator|::
name|sendNativeModifierEvent
parameter_list|(
specifier|const
name|QNativeModifierEvent
modifier|&
name|event
parameter_list|)
block|{
return|return
name|sendNativeModifierEvent_Quartz
argument_list|(
name|event
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|subscribeForNativeEvents
name|Qt
operator|::
name|Native
operator|::
name|Status
name|QNativeInput
operator|::
name|subscribeForNativeEvents
parameter_list|()
block|{
return|return
name|insertEventHandler_Quartz
argument_list|(
name|this
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|unsubscribeForNativeEvents
name|Qt
operator|::
name|Native
operator|::
name|Status
name|QNativeInput
operator|::
name|unsubscribeForNativeEvents
parameter_list|()
block|{
return|return
name|removeEventHandler_Quartz
argument_list|()
return|;
block|}
end_function
begin_comment
comment|// Some Qt to Mac mappings:
end_comment
begin_decl_stmt
DECL|member|Key_A
name|int
name|QNativeKeyEvent
operator|::
name|Key_A
init|=
literal|0
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|member|Key_B
name|int
name|QNativeKeyEvent
operator|::
name|Key_B
init|=
literal|11
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|member|Key_C
name|int
name|QNativeKeyEvent
operator|::
name|Key_C
init|=
literal|8
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|member|Key_1
name|int
name|QNativeKeyEvent
operator|::
name|Key_1
init|=
literal|18
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|member|Key_Backspace
name|int
name|QNativeKeyEvent
operator|::
name|Key_Backspace
init|=
literal|51
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|member|Key_Enter
name|int
name|QNativeKeyEvent
operator|::
name|Key_Enter
init|=
literal|36
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|member|Key_Del
name|int
name|QNativeKeyEvent
operator|::
name|Key_Del
init|=
literal|117
decl_stmt|;
end_decl_stmt
end_unit
