begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 BogDan Vatra<bogdan@kde.org> ** Contact: http://www.qt-project.org/legal ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"androidjniinput.h"
end_include
begin_include
include|#
directive|include
file|"androidjnimain.h"
end_include
begin_include
include|#
directive|include
file|"qandroidplatformintegration.h"
end_include
begin_include
include|#
directive|include
file|<qpa/qwindowsysteminterface.h>
end_include
begin_include
include|#
directive|include
file|<QTouchEvent>
end_include
begin_include
include|#
directive|include
file|<QPointer>
end_include
begin_using
using|using
namespace|namespace
name|QtAndroid
namespace|;
end_using
begin_namespace
DECL|namespace|QtAndroidInput
namespace|namespace
name|QtAndroidInput
block|{
DECL|member|m_showSoftwareKeyboardMethodID
specifier|static
name|jmethodID
name|m_showSoftwareKeyboardMethodID
init|=
literal|0
decl_stmt|;
DECL|member|m_resetSoftwareKeyboardMethodID
specifier|static
name|jmethodID
name|m_resetSoftwareKeyboardMethodID
init|=
literal|0
decl_stmt|;
DECL|member|m_hideSoftwareKeyboardMethodID
specifier|static
name|jmethodID
name|m_hideSoftwareKeyboardMethodID
init|=
literal|0
decl_stmt|;
DECL|member|m_isSoftwareKeyboardVisibleMethodID
specifier|static
name|jmethodID
name|m_isSoftwareKeyboardVisibleMethodID
init|=
literal|0
decl_stmt|;
DECL|member|m_updateSelectionMethodID
specifier|static
name|jmethodID
name|m_updateSelectionMethodID
init|=
literal|0
decl_stmt|;
DECL|member|m_ignoreMouseEvents
specifier|static
name|bool
name|m_ignoreMouseEvents
init|=
literal|false
decl_stmt|;
DECL|member|m_touchPoints
specifier|static
name|QList
argument_list|<
name|QWindowSystemInterface
operator|::
name|TouchPoint
argument_list|>
name|m_touchPoints
decl_stmt|;
DECL|member|m_mouseGrabber
specifier|static
name|QPointer
argument_list|<
name|QWindow
argument_list|>
name|m_mouseGrabber
decl_stmt|;
DECL|function|updateSelection
name|void
name|updateSelection
parameter_list|(
name|int
name|selStart
parameter_list|,
name|int
name|selEnd
parameter_list|,
name|int
name|candidatesStart
parameter_list|,
name|int
name|candidatesEnd
parameter_list|)
block|{
name|AttachedJNIEnv
name|env
decl_stmt|;
if|if
condition|(
operator|!
name|env
operator|.
name|jniEnv
condition|)
return|return;
name|env
operator|.
name|jniEnv
operator|->
name|CallStaticVoidMethod
argument_list|(
name|applicationClass
argument_list|()
argument_list|,
name|m_updateSelectionMethodID
argument_list|,
name|selStart
argument_list|,
name|selEnd
argument_list|,
name|candidatesStart
argument_list|,
name|candidatesEnd
argument_list|)
expr_stmt|;
block|}
DECL|function|showSoftwareKeyboard
name|void
name|showSoftwareKeyboard
parameter_list|(
name|int
name|left
parameter_list|,
name|int
name|top
parameter_list|,
name|int
name|width
parameter_list|,
name|int
name|height
parameter_list|,
name|int
name|inputHints
parameter_list|)
block|{
name|AttachedJNIEnv
name|env
decl_stmt|;
if|if
condition|(
operator|!
name|env
operator|.
name|jniEnv
condition|)
return|return;
name|env
operator|.
name|jniEnv
operator|->
name|CallStaticVoidMethod
argument_list|(
name|applicationClass
argument_list|()
argument_list|,
name|m_showSoftwareKeyboardMethodID
argument_list|,
name|left
argument_list|,
name|top
argument_list|,
name|width
argument_list|,
name|height
argument_list|,
name|inputHints
argument_list|)
expr_stmt|;
block|}
DECL|function|resetSoftwareKeyboard
name|void
name|resetSoftwareKeyboard
parameter_list|()
block|{
name|AttachedJNIEnv
name|env
decl_stmt|;
if|if
condition|(
operator|!
name|env
operator|.
name|jniEnv
condition|)
return|return;
name|env
operator|.
name|jniEnv
operator|->
name|CallStaticVoidMethod
argument_list|(
name|applicationClass
argument_list|()
argument_list|,
name|m_resetSoftwareKeyboardMethodID
argument_list|)
expr_stmt|;
block|}
DECL|function|hideSoftwareKeyboard
name|void
name|hideSoftwareKeyboard
parameter_list|()
block|{
name|AttachedJNIEnv
name|env
decl_stmt|;
if|if
condition|(
operator|!
name|env
operator|.
name|jniEnv
condition|)
return|return;
name|env
operator|.
name|jniEnv
operator|->
name|CallStaticVoidMethod
argument_list|(
name|applicationClass
argument_list|()
argument_list|,
name|m_hideSoftwareKeyboardMethodID
argument_list|)
expr_stmt|;
block|}
DECL|function|isSoftwareKeyboardVisible
name|bool
name|isSoftwareKeyboardVisible
parameter_list|()
block|{
name|AttachedJNIEnv
name|env
decl_stmt|;
if|if
condition|(
operator|!
name|env
operator|.
name|jniEnv
condition|)
return|return
literal|false
return|;
return|return
name|env
operator|.
name|jniEnv
operator|->
name|CallStaticBooleanMethod
argument_list|(
name|applicationClass
argument_list|()
argument_list|,
name|m_isSoftwareKeyboardVisibleMethodID
argument_list|)
return|;
block|}
DECL|function|mouseDown
specifier|static
name|void
name|mouseDown
parameter_list|(
name|JNIEnv
modifier|*
comment|/*env*/
parameter_list|,
name|jobject
comment|/*thiz*/
parameter_list|,
name|jint
comment|/*winId*/
parameter_list|,
name|jint
name|x
parameter_list|,
name|jint
name|y
parameter_list|)
block|{
if|if
condition|(
name|m_ignoreMouseEvents
condition|)
return|return;
name|QPoint
name|globalPos
argument_list|(
name|x
argument_list|,
name|y
argument_list|)
decl_stmt|;
name|QWindow
modifier|*
name|tlw
init|=
name|topLevelWindowAt
argument_list|(
name|globalPos
argument_list|)
decl_stmt|;
name|m_mouseGrabber
operator|=
name|tlw
expr_stmt|;
name|QPoint
name|localPos
init|=
name|tlw
condition|?
operator|(
name|globalPos
operator|-
name|tlw
operator|->
name|position
argument_list|()
operator|)
else|:
name|globalPos
decl_stmt|;
name|QWindowSystemInterface
operator|::
name|handleMouseEvent
argument_list|(
name|tlw
argument_list|,
name|localPos
argument_list|,
name|globalPos
argument_list|,
name|Qt
operator|::
name|MouseButtons
argument_list|(
name|Qt
operator|::
name|LeftButton
argument_list|)
argument_list|)
expr_stmt|;
block|}
DECL|function|mouseUp
specifier|static
name|void
name|mouseUp
parameter_list|(
name|JNIEnv
modifier|*
comment|/*env*/
parameter_list|,
name|jobject
comment|/*thiz*/
parameter_list|,
name|jint
comment|/*winId*/
parameter_list|,
name|jint
name|x
parameter_list|,
name|jint
name|y
parameter_list|)
block|{
name|QPoint
name|globalPos
argument_list|(
name|x
argument_list|,
name|y
argument_list|)
decl_stmt|;
name|QWindow
modifier|*
name|tlw
init|=
name|m_mouseGrabber
operator|.
name|data
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
name|tlw
condition|)
name|tlw
operator|=
name|topLevelWindowAt
argument_list|(
name|globalPos
argument_list|)
expr_stmt|;
name|QPoint
name|localPos
init|=
name|tlw
condition|?
operator|(
name|globalPos
operator|-
name|tlw
operator|->
name|position
argument_list|()
operator|)
else|:
name|globalPos
decl_stmt|;
name|QWindowSystemInterface
operator|::
name|handleMouseEvent
argument_list|(
name|tlw
argument_list|,
name|localPos
argument_list|,
name|globalPos
argument_list|,
name|Qt
operator|::
name|MouseButtons
argument_list|(
name|Qt
operator|::
name|NoButton
argument_list|)
argument_list|)
expr_stmt|;
name|m_ignoreMouseEvents
operator|=
literal|false
expr_stmt|;
name|m_mouseGrabber
operator|=
literal|0
expr_stmt|;
block|}
DECL|function|mouseMove
specifier|static
name|void
name|mouseMove
parameter_list|(
name|JNIEnv
modifier|*
comment|/*env*/
parameter_list|,
name|jobject
comment|/*thiz*/
parameter_list|,
name|jint
comment|/*winId*/
parameter_list|,
name|jint
name|x
parameter_list|,
name|jint
name|y
parameter_list|)
block|{
if|if
condition|(
name|m_ignoreMouseEvents
condition|)
return|return;
name|QPoint
name|globalPos
argument_list|(
name|x
argument_list|,
name|y
argument_list|)
decl_stmt|;
name|QWindow
modifier|*
name|tlw
init|=
name|m_mouseGrabber
operator|.
name|data
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
name|tlw
condition|)
name|tlw
operator|=
name|topLevelWindowAt
argument_list|(
name|globalPos
argument_list|)
expr_stmt|;
name|QPoint
name|localPos
init|=
name|tlw
condition|?
operator|(
name|globalPos
operator|-
name|tlw
operator|->
name|position
argument_list|()
operator|)
else|:
name|globalPos
decl_stmt|;
name|QWindowSystemInterface
operator|::
name|handleMouseEvent
argument_list|(
name|tlw
argument_list|,
name|localPos
argument_list|,
name|globalPos
argument_list|,
name|Qt
operator|::
name|MouseButtons
argument_list|(
name|Qt
operator|::
name|LeftButton
argument_list|)
argument_list|)
expr_stmt|;
block|}
DECL|function|longPress
specifier|static
name|void
name|longPress
parameter_list|(
name|JNIEnv
modifier|*
comment|/*env*/
parameter_list|,
name|jobject
comment|/*thiz*/
parameter_list|,
name|jint
comment|/*winId*/
parameter_list|,
name|jint
name|x
parameter_list|,
name|jint
name|y
parameter_list|)
block|{
comment|//### TODO: add proper API for Qt 5.2
specifier|static
name|bool
name|rightMouseFromLongPress
init|=
name|qgetenv
argument_list|(
literal|"QT_NECESSITAS_COMPATIBILITY_LONG_PRESS"
argument_list|)
operator|.
name|toInt
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
name|rightMouseFromLongPress
condition|)
return|return;
name|m_ignoreMouseEvents
operator|=
literal|true
expr_stmt|;
name|QPoint
name|globalPos
argument_list|(
name|x
argument_list|,
name|y
argument_list|)
decl_stmt|;
name|QWindow
modifier|*
name|tlw
init|=
name|topLevelWindowAt
argument_list|(
name|globalPos
argument_list|)
decl_stmt|;
name|QPoint
name|localPos
init|=
name|tlw
condition|?
operator|(
name|globalPos
operator|-
name|tlw
operator|->
name|position
argument_list|()
operator|)
else|:
name|globalPos
decl_stmt|;
comment|// Release left button
name|QWindowSystemInterface
operator|::
name|handleMouseEvent
argument_list|(
name|tlw
argument_list|,
name|localPos
argument_list|,
name|globalPos
argument_list|,
name|Qt
operator|::
name|MouseButtons
argument_list|(
name|Qt
operator|::
name|NoButton
argument_list|)
argument_list|)
expr_stmt|;
comment|// Press right button
name|QWindowSystemInterface
operator|::
name|handleMouseEvent
argument_list|(
name|tlw
argument_list|,
name|localPos
argument_list|,
name|globalPos
argument_list|,
name|Qt
operator|::
name|MouseButtons
argument_list|(
name|Qt
operator|::
name|RightButton
argument_list|)
argument_list|)
expr_stmt|;
block|}
DECL|function|touchBegin
specifier|static
name|void
name|touchBegin
parameter_list|(
name|JNIEnv
modifier|*
comment|/*env*/
parameter_list|,
name|jobject
comment|/*thiz*/
parameter_list|,
name|jint
comment|/*winId*/
parameter_list|)
block|{
name|m_touchPoints
operator|.
name|clear
argument_list|()
expr_stmt|;
block|}
DECL|function|touchAdd
specifier|static
name|void
name|touchAdd
parameter_list|(
name|JNIEnv
modifier|*
comment|/*env*/
parameter_list|,
name|jobject
comment|/*thiz*/
parameter_list|,
name|jint
comment|/*winId*/
parameter_list|,
name|jint
name|id
parameter_list|,
name|jint
name|action
parameter_list|,
name|jboolean
comment|/*primary*/
parameter_list|,
name|jint
name|x
parameter_list|,
name|jint
name|y
parameter_list|,
name|jfloat
name|size
parameter_list|,
name|jfloat
name|pressure
parameter_list|)
block|{
name|Qt
operator|::
name|TouchPointState
name|state
init|=
name|Qt
operator|::
name|TouchPointStationary
decl_stmt|;
switch|switch
condition|(
name|action
condition|)
block|{
case|case
literal|0
case|:
name|state
operator|=
name|Qt
operator|::
name|TouchPointPressed
expr_stmt|;
break|break;
case|case
literal|1
case|:
name|state
operator|=
name|Qt
operator|::
name|TouchPointMoved
expr_stmt|;
break|break;
case|case
literal|2
case|:
name|state
operator|=
name|Qt
operator|::
name|TouchPointStationary
expr_stmt|;
break|break;
case|case
literal|3
case|:
name|state
operator|=
name|Qt
operator|::
name|TouchPointReleased
expr_stmt|;
break|break;
block|}
specifier|const
name|int
name|dw
init|=
name|desktopWidthPixels
argument_list|()
decl_stmt|;
specifier|const
name|int
name|dh
init|=
name|desktopHeightPixels
argument_list|()
decl_stmt|;
name|QWindowSystemInterface
operator|::
name|TouchPoint
name|touchPoint
decl_stmt|;
name|touchPoint
operator|.
name|id
operator|=
name|id
expr_stmt|;
name|touchPoint
operator|.
name|pressure
operator|=
name|pressure
expr_stmt|;
name|touchPoint
operator|.
name|normalPosition
operator|=
name|QPointF
argument_list|(
name|double
argument_list|(
name|x
operator|/
name|dw
argument_list|)
argument_list|,
name|double
argument_list|(
name|y
operator|/
name|dh
argument_list|)
argument_list|)
expr_stmt|;
name|touchPoint
operator|.
name|state
operator|=
name|state
expr_stmt|;
name|touchPoint
operator|.
name|area
operator|=
name|QRectF
argument_list|(
name|x
operator|-
name|double
argument_list|(
name|dw
operator|*
name|size
argument_list|)
operator|/
literal|2.0
argument_list|,
name|y
operator|-
name|double
argument_list|(
name|dh
operator|*
name|size
argument_list|)
operator|/
literal|2.0
argument_list|,
name|double
argument_list|(
name|dw
operator|*
name|size
argument_list|)
argument_list|,
name|double
argument_list|(
name|dh
operator|*
name|size
argument_list|)
argument_list|)
expr_stmt|;
name|m_touchPoints
operator|.
name|push_back
argument_list|(
name|touchPoint
argument_list|)
expr_stmt|;
block|}
DECL|function|touchEnd
specifier|static
name|void
name|touchEnd
parameter_list|(
name|JNIEnv
modifier|*
comment|/*env*/
parameter_list|,
name|jobject
comment|/*thiz*/
parameter_list|,
name|jint
comment|/*winId*/
parameter_list|,
name|jint
comment|/*action*/
parameter_list|)
block|{
if|if
condition|(
name|m_touchPoints
operator|.
name|isEmpty
argument_list|()
condition|)
return|return;
name|QAndroidPlatformIntegration
modifier|*
name|platformIntegration
init|=
name|QtAndroid
operator|::
name|androidPlatformIntegration
argument_list|()
decl_stmt|;
name|QTouchDevice
modifier|*
name|touchDevice
init|=
name|platformIntegration
operator|->
name|touchDevice
argument_list|()
decl_stmt|;
if|if
condition|(
name|touchDevice
operator|==
literal|0
condition|)
block|{
name|touchDevice
operator|=
operator|new
name|QTouchDevice
expr_stmt|;
name|touchDevice
operator|->
name|setType
argument_list|(
name|QTouchDevice
operator|::
name|TouchScreen
argument_list|)
expr_stmt|;
name|touchDevice
operator|->
name|setCapabilities
argument_list|(
name|QTouchDevice
operator|::
name|Position
operator||
name|QTouchDevice
operator|::
name|Area
operator||
name|QTouchDevice
operator|::
name|Pressure
operator||
name|QTouchDevice
operator|::
name|NormalizedPosition
argument_list|)
expr_stmt|;
name|QWindowSystemInterface
operator|::
name|registerTouchDevice
argument_list|(
name|touchDevice
argument_list|)
expr_stmt|;
name|platformIntegration
operator|->
name|setTouchDevice
argument_list|(
name|touchDevice
argument_list|)
expr_stmt|;
block|}
name|QWindow
modifier|*
name|window
init|=
name|QtAndroid
operator|::
name|topLevelWindowAt
argument_list|(
name|m_touchPoints
operator|.
name|at
argument_list|(
literal|0
argument_list|)
operator|.
name|area
operator|.
name|center
argument_list|()
operator|.
name|toPoint
argument_list|()
argument_list|)
decl_stmt|;
name|QWindowSystemInterface
operator|::
name|handleTouchEvent
argument_list|(
name|window
argument_list|,
name|touchDevice
argument_list|,
name|m_touchPoints
argument_list|)
expr_stmt|;
block|}
DECL|function|mapAndroidKey
specifier|static
name|int
name|mapAndroidKey
parameter_list|(
name|int
name|key
parameter_list|)
block|{
comment|// 0--9        0x00000007 -- 0x00000010
if|if
condition|(
name|key
operator|>=
literal|0x00000007
operator|&&
name|key
operator|<=
literal|0x00000010
condition|)
return|return
name|Qt
operator|::
name|Key_0
operator|+
name|key
operator|-
literal|0x00000007
return|;
comment|// A--Z        0x0000001d -- 0x00000036
if|if
condition|(
name|key
operator|>=
literal|0x0000001d
operator|&&
name|key
operator|<=
literal|0x00000036
condition|)
return|return
name|Qt
operator|::
name|Key_A
operator|+
name|key
operator|-
literal|0x0000001d
return|;
switch|switch
condition|(
name|key
condition|)
block|{
case|case
literal|0x00000039
case|:
case|case
literal|0x0000003a
case|:
return|return
name|Qt
operator|::
name|Key_Alt
return|;
case|case
literal|0x0000004b
case|:
return|return
name|Qt
operator|::
name|Key_Apostrophe
return|;
case|case
literal|0x00000004
case|:
comment|// KEYCODE_BACK
return|return
name|Qt
operator|::
name|Key_Back
return|;
case|case
literal|0x00000049
case|:
return|return
name|Qt
operator|::
name|Key_Backslash
return|;
case|case
literal|0x00000005
case|:
return|return
name|Qt
operator|::
name|Key_Call
return|;
case|case
literal|0x0000001b
case|:
return|return
name|Qt
operator|::
name|Key_WebCam
return|;
case|case
literal|0x0000001c
case|:
return|return
name|Qt
operator|::
name|Key_Clear
return|;
case|case
literal|0x00000037
case|:
return|return
name|Qt
operator|::
name|Key_Comma
return|;
case|case
literal|0x00000043
case|:
return|return
name|Qt
operator|::
name|Key_Backspace
return|;
case|case
literal|0x00000017
case|:
comment|// KEYCODE_DPAD_CENTER
return|return
name|Qt
operator|::
name|Key_Enter
return|;
case|case
literal|0x00000014
case|:
comment|// KEYCODE_DPAD_DOWN
return|return
name|Qt
operator|::
name|Key_Down
return|;
case|case
literal|0x00000015
case|:
comment|//KEYCODE_DPAD_LEFT
return|return
name|Qt
operator|::
name|Key_Left
return|;
case|case
literal|0x00000016
case|:
comment|//KEYCODE_DPAD_RIGHT
return|return
name|Qt
operator|::
name|Key_Right
return|;
case|case
literal|0x00000013
case|:
comment|//KEYCODE_DPAD_UP
return|return
name|Qt
operator|::
name|Key_Up
return|;
case|case
literal|0x00000006
case|:
comment|//KEYCODE_ENDCALL
return|return
name|Qt
operator|::
name|Key_Hangup
return|;
case|case
literal|0x00000042
case|:
return|return
name|Qt
operator|::
name|Key_Return
return|;
case|case
literal|0x00000041
case|:
comment|//KEYCODE_ENVELOPE
return|return
name|Qt
operator|::
name|Key_LaunchMail
return|;
case|case
literal|0x00000046
case|:
return|return
name|Qt
operator|::
name|Key_Equal
return|;
case|case
literal|0x00000040
case|:
return|return
name|Qt
operator|::
name|Key_Explorer
return|;
case|case
literal|0x00000003
case|:
return|return
name|Qt
operator|::
name|Key_Home
return|;
case|case
literal|0x00000047
case|:
return|return
name|Qt
operator|::
name|Key_BracketLeft
return|;
case|case
literal|0x0000005a
case|:
comment|// KEYCODE_MEDIA_FAST_FORWARD
return|return
name|Qt
operator|::
name|Key_AudioForward
return|;
case|case
literal|0x00000057
case|:
return|return
name|Qt
operator|::
name|Key_MediaNext
return|;
case|case
literal|0x00000055
case|:
return|return
name|Qt
operator|::
name|Key_MediaPlay
return|;
case|case
literal|0x00000058
case|:
return|return
name|Qt
operator|::
name|Key_MediaPrevious
return|;
case|case
literal|0x00000059
case|:
comment|// KEYCODE_MEDIA_REWIND
return|return
name|Qt
operator|::
name|Key_AudioRewind
return|;
case|case
literal|0x00000056
case|:
return|return
name|Qt
operator|::
name|Key_MediaStop
return|;
case|case
literal|0x00000052
case|:
comment|//KEYCODE_MENU
return|return
name|Qt
operator|::
name|Key_Menu
return|;
case|case
literal|0x00000045
case|:
return|return
name|Qt
operator|::
name|Key_Minus
return|;
case|case
literal|0x0000005b
case|:
comment|// KEYCODE_MUTE
return|return
name|Qt
operator|::
name|Key_MicMute
return|;
case|case
literal|0x0000004e
case|:
return|return
name|Qt
operator|::
name|Key_NumLock
return|;
case|case
literal|0x00000038
case|:
return|return
name|Qt
operator|::
name|Key_Period
return|;
case|case
literal|0x00000051
case|:
return|return
name|Qt
operator|::
name|Key_Plus
return|;
case|case
literal|0x0000001a
case|:
return|return
name|Qt
operator|::
name|Key_PowerOff
return|;
case|case
literal|0x00000048
case|:
return|return
name|Qt
operator|::
name|Key_BracketRight
return|;
case|case
literal|0x00000054
case|:
return|return
name|Qt
operator|::
name|Key_Search
return|;
case|case
literal|0x0000004a
case|:
return|return
name|Qt
operator|::
name|Key_Semicolon
return|;
case|case
literal|0x0000003b
case|:
case|case
literal|0x0000003c
case|:
return|return
name|Qt
operator|::
name|Key_Shift
return|;
case|case
literal|0x0000004c
case|:
return|return
name|Qt
operator|::
name|Key_Slash
return|;
case|case
literal|0x00000001
case|:
return|return
name|Qt
operator|::
name|Key_Left
return|;
case|case
literal|0x00000002
case|:
return|return
name|Qt
operator|::
name|Key_Right
return|;
case|case
literal|0x0000003e
case|:
return|return
name|Qt
operator|::
name|Key_Space
return|;
case|case
literal|0x0000003f
case|:
comment|// KEYCODE_SYM
return|return
name|Qt
operator|::
name|Key_Meta
return|;
case|case
literal|0x0000003d
case|:
return|return
name|Qt
operator|::
name|Key_Tab
return|;
case|case
literal|0x00000019
case|:
return|return
name|Qt
operator|::
name|Key_VolumeDown
return|;
case|case
literal|0x000000a4
case|:
comment|// KEYCODE_VOLUME_MUTE
return|return
name|Qt
operator|::
name|Key_VolumeMute
return|;
case|case
literal|0x00000018
case|:
return|return
name|Qt
operator|::
name|Key_VolumeUp
return|;
case|case
literal|0x000000b7
case|:
comment|// KEYCODE_PROG_RED
return|return
name|Qt
operator|::
name|Key_Red
return|;
case|case
literal|0x000000b8
case|:
comment|// KEYCODE_PROG_GREEN
return|return
name|Qt
operator|::
name|Key_Green
return|;
case|case
literal|0x000000b9
case|:
comment|// KEYCODE_PROG_YELLOW
return|return
name|Qt
operator|::
name|Key_Yellow
return|;
case|case
literal|0x000000ba
case|:
comment|// KEYCODE_PROG_BLUE
return|return
name|Qt
operator|::
name|Key_Blue
return|;
case|case
literal|0x000000a6
case|:
comment|// KEYCODE_CHANNEL_UP
return|return
name|Qt
operator|::
name|Key_ChannelUp
return|;
case|case
literal|0x000000a7
case|:
comment|// KEYCODE_CHANNEL_DOWN
return|return
name|Qt
operator|::
name|Key_ChannelDown
return|;
case|case
literal|0x00000000
case|:
comment|// KEYCODE_UNKNOWN
case|case
literal|0x00000011
case|:
comment|// KEYCODE_STAR ?!?!?
case|case
literal|0x00000012
case|:
comment|// KEYCODE_POUND ?!?!?
case|case
literal|0x00000053
case|:
comment|// KEYCODE_NOTIFICATION ?!?!?
case|case
literal|0x0000004f
case|:
comment|// KEYCODE_HEADSETHOOK ?!?!?
case|case
literal|0x00000044
case|:
comment|// KEYCODE_GRAVE ?!?!?
case|case
literal|0x00000050
case|:
comment|// KEYCODE_FOCUS ?!?!?
return|return
name|Qt
operator|::
name|Key_Any
return|;
default|default:
return|return
literal|0
return|;
block|}
block|}
DECL|function|keyDown
specifier|static
name|void
name|keyDown
parameter_list|(
name|JNIEnv
modifier|*
comment|/*env*/
parameter_list|,
name|jobject
comment|/*thiz*/
parameter_list|,
name|jint
name|key
parameter_list|,
name|jint
name|unicode
parameter_list|,
name|jint
name|modifier
parameter_list|)
block|{
name|Qt
operator|::
name|KeyboardModifiers
name|modifiers
decl_stmt|;
if|if
condition|(
name|modifier
operator|&
literal|1
condition|)
name|modifiers
operator||=
name|Qt
operator|::
name|ShiftModifier
expr_stmt|;
if|if
condition|(
name|modifier
operator|&
literal|2
condition|)
name|modifiers
operator||=
name|Qt
operator|::
name|AltModifier
expr_stmt|;
if|if
condition|(
name|modifier
operator|&
literal|4
condition|)
name|modifiers
operator||=
name|Qt
operator|::
name|MetaModifier
expr_stmt|;
name|QWindowSystemInterface
operator|::
name|handleKeyEvent
argument_list|(
literal|0
argument_list|,
name|QEvent
operator|::
name|KeyPress
argument_list|,
name|mapAndroidKey
argument_list|(
name|key
argument_list|)
argument_list|,
name|modifiers
argument_list|,
name|QChar
argument_list|(
name|unicode
argument_list|)
argument_list|,
literal|true
argument_list|)
expr_stmt|;
block|}
DECL|function|keyUp
specifier|static
name|void
name|keyUp
parameter_list|(
name|JNIEnv
modifier|*
comment|/*env*/
parameter_list|,
name|jobject
comment|/*thiz*/
parameter_list|,
name|jint
name|key
parameter_list|,
name|jint
name|unicode
parameter_list|,
name|jint
name|modifier
parameter_list|)
block|{
name|Qt
operator|::
name|KeyboardModifiers
name|modifiers
decl_stmt|;
if|if
condition|(
name|modifier
operator|&
literal|1
condition|)
name|modifiers
operator||=
name|Qt
operator|::
name|ShiftModifier
expr_stmt|;
if|if
condition|(
name|modifier
operator|&
literal|2
condition|)
name|modifiers
operator||=
name|Qt
operator|::
name|AltModifier
expr_stmt|;
if|if
condition|(
name|modifier
operator|&
literal|4
condition|)
name|modifiers
operator||=
name|Qt
operator|::
name|MetaModifier
expr_stmt|;
name|QWindowSystemInterface
operator|::
name|handleKeyEvent
argument_list|(
literal|0
argument_list|,
name|QEvent
operator|::
name|KeyRelease
argument_list|,
name|mapAndroidKey
argument_list|(
name|key
argument_list|)
argument_list|,
name|modifiers
argument_list|,
name|QChar
argument_list|(
name|unicode
argument_list|)
argument_list|,
literal|true
argument_list|)
expr_stmt|;
block|}
DECL|member|methods
specifier|static
name|JNINativeMethod
name|methods
index|[]
init|=
block|{
block|{
literal|"touchBegin"
block|,
literal|"(I)V"
block|,
operator|(
name|void
operator|*
operator|)
name|touchBegin
block|}
block|,
block|{
literal|"touchAdd"
block|,
literal|"(IIIZIIFF)V"
block|,
operator|(
name|void
operator|*
operator|)
name|touchAdd
block|}
block|,
block|{
literal|"touchEnd"
block|,
literal|"(II)V"
block|,
operator|(
name|void
operator|*
operator|)
name|touchEnd
block|}
block|,
block|{
literal|"mouseDown"
block|,
literal|"(III)V"
block|,
operator|(
name|void
operator|*
operator|)
name|mouseDown
block|}
block|,
block|{
literal|"mouseUp"
block|,
literal|"(III)V"
block|,
operator|(
name|void
operator|*
operator|)
name|mouseUp
block|}
block|,
block|{
literal|"mouseMove"
block|,
literal|"(III)V"
block|,
operator|(
name|void
operator|*
operator|)
name|mouseMove
block|}
block|,
block|{
literal|"longPress"
block|,
literal|"(III)V"
block|,
operator|(
name|void
operator|*
operator|)
name|longPress
block|}
block|,
block|{
literal|"keyDown"
block|,
literal|"(III)V"
block|,
operator|(
name|void
operator|*
operator|)
name|keyDown
block|}
block|,
block|{
literal|"keyUp"
block|,
literal|"(III)V"
block|,
operator|(
name|void
operator|*
operator|)
name|keyUp
block|}
block|}
decl_stmt|;
DECL|macro|GET_AND_CHECK_STATIC_METHOD
define|#
directive|define
name|GET_AND_CHECK_STATIC_METHOD
parameter_list|(
name|VAR
parameter_list|,
name|CLASS
parameter_list|,
name|METHOD_NAME
parameter_list|,
name|METHOD_SIGNATURE
parameter_list|)
define|\
value|VAR = env->GetStaticMethodID(CLASS, METHOD_NAME, METHOD_SIGNATURE); \     if (!VAR) { \         __android_log_print(ANDROID_LOG_FATAL, qtTagText(), methodErrorMsgFmt(), METHOD_NAME, METHOD_SIGNATURE); \         return false; \     }
DECL|function|registerNatives
name|bool
name|registerNatives
parameter_list|(
name|JNIEnv
modifier|*
name|env
parameter_list|)
block|{
name|jclass
name|appClass
init|=
name|QtAndroid
operator|::
name|applicationClass
argument_list|()
decl_stmt|;
if|if
condition|(
name|env
operator|->
name|RegisterNatives
argument_list|(
name|appClass
argument_list|,
name|methods
argument_list|,
sizeof|sizeof
argument_list|(
name|methods
argument_list|)
operator|/
sizeof|sizeof
argument_list|(
name|methods
index|[
literal|0
index|]
argument_list|)
argument_list|)
operator|<
literal|0
condition|)
block|{
name|__android_log_print
argument_list|(
name|ANDROID_LOG_FATAL
argument_list|,
literal|"Qt"
argument_list|,
literal|"RegisterNatives failed"
argument_list|)
expr_stmt|;
return|return
literal|false
return|;
block|}
name|GET_AND_CHECK_STATIC_METHOD
argument_list|(
name|m_showSoftwareKeyboardMethodID
argument_list|,
name|appClass
argument_list|,
literal|"showSoftwareKeyboard"
argument_list|,
literal|"(IIIII)V"
argument_list|)
expr_stmt|;
name|GET_AND_CHECK_STATIC_METHOD
argument_list|(
name|m_resetSoftwareKeyboardMethodID
argument_list|,
name|appClass
argument_list|,
literal|"resetSoftwareKeyboard"
argument_list|,
literal|"()V"
argument_list|)
expr_stmt|;
name|GET_AND_CHECK_STATIC_METHOD
argument_list|(
name|m_hideSoftwareKeyboardMethodID
argument_list|,
name|appClass
argument_list|,
literal|"hideSoftwareKeyboard"
argument_list|,
literal|"()V"
argument_list|)
expr_stmt|;
name|GET_AND_CHECK_STATIC_METHOD
argument_list|(
name|m_isSoftwareKeyboardVisibleMethodID
argument_list|,
name|appClass
argument_list|,
literal|"isSoftwareKeyboardVisible"
argument_list|,
literal|"()Z"
argument_list|)
expr_stmt|;
name|GET_AND_CHECK_STATIC_METHOD
argument_list|(
name|m_updateSelectionMethodID
argument_list|,
name|appClass
argument_list|,
literal|"updateSelection"
argument_list|,
literal|"(IIII)V"
argument_list|)
expr_stmt|;
return|return
literal|true
return|;
block|}
block|}
end_namespace
end_unit
