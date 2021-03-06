begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qdirectfbconvenience.h"
end_include
begin_include
include|#
directive|include
file|"qdirectfbblitter.h"
end_include
begin_include
include|#
directive|include
file|"qdirectfbscreen.h"
end_include
begin_include
include|#
directive|include
file|<private/qpixmap_blitter_p.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/QWindow>
end_include
begin_include
include|#
directive|include
file|<QtGui/QScreen>
end_include
begin_function
name|QT_BEGIN_NAMESPACE
DECL|function|dfbInterface
name|IDirectFB
modifier|*
name|QDirectFbConvenience
operator|::
name|dfbInterface
parameter_list|()
block|{
specifier|static
name|IDirectFB
modifier|*
name|dfb
init|=
literal|0
decl_stmt|;
if|if
condition|(
operator|!
name|dfb
condition|)
block|{
name|DFBResult
name|result
init|=
name|DirectFBCreate
argument_list|(
operator|&
name|dfb
argument_list|)
decl_stmt|;
if|if
condition|(
name|result
operator|!=
name|DFB_OK
condition|)
block|{
name|DirectFBErrorFatal
argument_list|(
literal|"QDirectFBConvenience: error creating DirectFB interface"
argument_list|,
name|result
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
block|}
return|return
name|dfb
return|;
block|}
end_function
begin_function
DECL|function|dfbDisplayLayer
name|IDirectFBDisplayLayer
modifier|*
name|QDirectFbConvenience
operator|::
name|dfbDisplayLayer
parameter_list|(
name|int
name|display
parameter_list|)
block|{
name|IDirectFBDisplayLayer
modifier|*
name|layer
decl_stmt|;
name|DFBResult
name|result
init|=
name|QDirectFbConvenience
operator|::
name|dfbInterface
argument_list|()
operator|->
name|GetDisplayLayer
argument_list|(
name|QDirectFbConvenience
operator|::
name|dfbInterface
argument_list|()
argument_list|,
name|display
argument_list|,
operator|&
name|layer
argument_list|)
decl_stmt|;
if|if
condition|(
name|result
operator|!=
name|DFB_OK
condition|)
name|DirectFBErrorFatal
argument_list|(
literal|"QDirectFbConvenience: "
literal|"Unable to get primary display layer!"
argument_list|,
name|result
argument_list|)
expr_stmt|;
return|return
name|layer
return|;
block|}
end_function
begin_function
DECL|function|imageFormatFromSurfaceFormat
name|QImage
operator|::
name|Format
name|QDirectFbConvenience
operator|::
name|imageFormatFromSurfaceFormat
parameter_list|(
specifier|const
name|DFBSurfacePixelFormat
name|format
parameter_list|,
specifier|const
name|DFBSurfaceCapabilities
name|caps
parameter_list|)
block|{
switch|switch
condition|(
name|format
condition|)
block|{
case|case
name|DSPF_LUT8
case|:
return|return
name|QImage
operator|::
name|Format_Indexed8
return|;
case|case
name|DSPF_RGB24
case|:
return|return
name|QImage
operator|::
name|Format_RGB888
return|;
case|case
name|DSPF_ARGB4444
case|:
return|return
name|QImage
operator|::
name|Format_ARGB4444_Premultiplied
return|;
case|case
name|DSPF_RGB444
case|:
return|return
name|QImage
operator|::
name|Format_RGB444
return|;
case|case
name|DSPF_RGB555
case|:
case|case
name|DSPF_ARGB1555
case|:
return|return
name|QImage
operator|::
name|Format_RGB555
return|;
case|case
name|DSPF_RGB16
case|:
return|return
name|QImage
operator|::
name|Format_RGB16
return|;
case|case
name|DSPF_ARGB6666
case|:
return|return
name|QImage
operator|::
name|Format_ARGB6666_Premultiplied
return|;
case|case
name|DSPF_RGB18
case|:
return|return
name|QImage
operator|::
name|Format_RGB666
return|;
case|case
name|DSPF_RGB32
case|:
return|return
name|QImage
operator|::
name|Format_RGB32
return|;
case|case
name|DSPF_ARGB
case|:
block|{
if|if
condition|(
name|caps
operator|&
name|DSCAPS_PREMULTIPLIED
condition|)
return|return
name|QImage
operator|::
name|Format_ARGB32_Premultiplied
return|;
else|else
return|return
name|QImage
operator|::
name|Format_ARGB32
return|;
block|}
default|default:
break|break;
block|}
return|return
name|QImage
operator|::
name|Format_Invalid
return|;
block|}
end_function
begin_function
DECL|function|colorDepthForSurface
name|int
name|QDirectFbConvenience
operator|::
name|colorDepthForSurface
parameter_list|(
specifier|const
name|DFBSurfacePixelFormat
name|format
parameter_list|)
block|{
return|return
operator|(
operator|(
literal|0x1f
operator|<<
literal|7
operator|)
operator|&
name|format
operator|)
operator|>>
literal|7
return|;
block|}
end_function
begin_comment
comment|/**  * This is borrowing the reference of the QDirectFbBlitter. You may not store this  * pointer as a class member but must only use it locally.  */
end_comment
begin_function
DECL|function|dfbSurfaceForPlatformPixmap
name|IDirectFBSurface
modifier|*
name|QDirectFbConvenience
operator|::
name|dfbSurfaceForPlatformPixmap
parameter_list|(
name|QPlatformPixmap
modifier|*
name|handle
parameter_list|)
block|{
name|QBlittablePlatformPixmap
modifier|*
name|blittablePmData
init|=
cast|static_cast
argument_list|<
name|QBlittablePlatformPixmap
operator|*
argument_list|>
argument_list|(
name|handle
argument_list|)
decl_stmt|;
if|if
condition|(
name|blittablePmData
condition|)
block|{
name|QBlittable
modifier|*
name|blittable
init|=
name|blittablePmData
operator|->
name|blittable
argument_list|()
decl_stmt|;
name|QDirectFbBlitter
modifier|*
name|dfbBlitter
init|=
cast|static_cast
argument_list|<
name|QDirectFbBlitter
operator|*
argument_list|>
argument_list|(
name|blittable
argument_list|)
decl_stmt|;
return|return
name|dfbBlitter
operator|->
name|m_surface
operator|.
name|data
argument_list|()
return|;
block|}
return|return
literal|0
return|;
block|}
end_function
begin_function
DECL|function|mouseButton
name|Qt
operator|::
name|MouseButton
name|QDirectFbConvenience
operator|::
name|mouseButton
parameter_list|(
name|DFBInputDeviceButtonIdentifier
name|identifier
parameter_list|)
block|{
comment|// The Enum contains values for DIBI_FIRST (= DIBI_LEFT), DIBI_LAST (= 0x1f,) and
comment|// just 3 enumerated Mouse Buttons. To convert into *ALL* possible Qt::MoueButton values,
comment|// the parameter is cast as integer.
switch|switch
condition|(
name|int
argument_list|(
name|identifier
argument_list|)
condition|)
block|{
case|case
name|DIBI_LEFT
case|:
comment|// value is 0x00
return|return
name|Qt
operator|::
name|LeftButton
return|;
case|case
name|DIBI_RIGHT
case|:
comment|// value is 0x01
return|return
name|Qt
operator|::
name|RightButton
return|;
case|case
name|DIBI_MIDDLE
case|:
comment|// value is 0x02
return|return
name|Qt
operator|::
name|MidButton
return|;
case|case
literal|0x03
case|:
return|return
name|Qt
operator|::
name|BackButton
return|;
case|case
literal|0x04
case|:
return|return
name|Qt
operator|::
name|ForwardButton
return|;
case|case
literal|0x05
case|:
return|return
name|Qt
operator|::
name|ExtraButton3
return|;
case|case
literal|0x06
case|:
return|return
name|Qt
operator|::
name|ExtraButton4
return|;
case|case
literal|0x07
case|:
return|return
name|Qt
operator|::
name|ExtraButton5
return|;
case|case
literal|0x08
case|:
return|return
name|Qt
operator|::
name|ExtraButton6
return|;
case|case
literal|0x09
case|:
return|return
name|Qt
operator|::
name|ExtraButton7
return|;
case|case
literal|0x0a
case|:
return|return
name|Qt
operator|::
name|ExtraButton8
return|;
case|case
literal|0x0b
case|:
return|return
name|Qt
operator|::
name|ExtraButton9
return|;
case|case
literal|0x0c
case|:
return|return
name|Qt
operator|::
name|ExtraButton10
return|;
case|case
literal|0x0d
case|:
return|return
name|Qt
operator|::
name|ExtraButton11
return|;
case|case
literal|0x0e
case|:
return|return
name|Qt
operator|::
name|ExtraButton12
return|;
case|case
literal|0x0f
case|:
return|return
name|Qt
operator|::
name|ExtraButton13
return|;
case|case
literal|0x10
case|:
return|return
name|Qt
operator|::
name|ExtraButton14
return|;
case|case
literal|0x11
case|:
return|return
name|Qt
operator|::
name|ExtraButton15
return|;
case|case
literal|0x12
case|:
return|return
name|Qt
operator|::
name|ExtraButton16
return|;
case|case
literal|0x13
case|:
return|return
name|Qt
operator|::
name|ExtraButton17
return|;
case|case
literal|0x14
case|:
return|return
name|Qt
operator|::
name|ExtraButton18
return|;
case|case
literal|0x15
case|:
return|return
name|Qt
operator|::
name|ExtraButton19
return|;
case|case
literal|0x16
case|:
return|return
name|Qt
operator|::
name|ExtraButton20
return|;
case|case
literal|0x17
case|:
return|return
name|Qt
operator|::
name|ExtraButton21
return|;
case|case
literal|0x18
case|:
return|return
name|Qt
operator|::
name|ExtraButton22
return|;
case|case
literal|0x19
case|:
return|return
name|Qt
operator|::
name|ExtraButton23
return|;
case|case
literal|0x1a
case|:
return|return
name|Qt
operator|::
name|ExtraButton24
return|;
default|default:
return|return
name|Qt
operator|::
name|NoButton
return|;
block|}
block|}
end_function
begin_function
DECL|function|mouseButtons
name|Qt
operator|::
name|MouseButtons
name|QDirectFbConvenience
operator|::
name|mouseButtons
parameter_list|(
name|DFBInputDeviceButtonMask
name|mask
parameter_list|)
block|{
name|Qt
operator|::
name|MouseButtons
name|buttons
init|=
name|Qt
operator|::
name|NoButton
decl_stmt|;
if|if
condition|(
name|mask
operator|&
name|DIBM_LEFT
condition|)
block|{
name|buttons
operator||=
name|Qt
operator|::
name|LeftButton
expr_stmt|;
block|}
if|if
condition|(
name|mask
operator|&
name|DIBM_MIDDLE
condition|)
block|{
name|buttons
operator||=
name|Qt
operator|::
name|MidButton
expr_stmt|;
block|}
if|if
condition|(
name|mask
operator|&
name|DIBM_RIGHT
condition|)
block|{
name|buttons
operator||=
name|Qt
operator|::
name|RightButton
expr_stmt|;
block|}
return|return
name|buttons
return|;
block|}
end_function
begin_function
DECL|function|keyboardModifiers
name|Qt
operator|::
name|KeyboardModifiers
name|QDirectFbConvenience
operator|::
name|keyboardModifiers
parameter_list|(
name|DFBInputDeviceModifierMask
name|mask
parameter_list|)
block|{
name|Qt
operator|::
name|KeyboardModifiers
name|modifiers
init|=
name|Qt
operator|::
name|NoModifier
decl_stmt|;
if|if
condition|(
name|mask
operator|&
name|DIMM_SHIFT
condition|)
block|{
name|modifiers
operator||=
name|Qt
operator|::
name|ShiftModifier
expr_stmt|;
block|}
if|if
condition|(
name|mask
operator|&
name|DIMM_ALT
condition|)
block|{
name|modifiers
operator||=
name|Qt
operator|::
name|AltModifier
expr_stmt|;
block|}
if|if
condition|(
name|mask
operator|&
name|DIMM_ALTGR
condition|)
block|{
name|modifiers
operator||=
name|Qt
operator|::
name|MetaModifier
expr_stmt|;
block|}
if|if
condition|(
name|mask
operator|&
name|DIMM_CONTROL
condition|)
block|{
name|modifiers
operator||=
name|Qt
operator|::
name|ControlModifier
expr_stmt|;
block|}
if|if
condition|(
name|mask
operator|&
name|DIMM_META
condition|)
block|{
name|modifiers
operator||=
name|Qt
operator|::
name|MetaModifier
expr_stmt|;
block|}
return|return
name|modifiers
return|;
block|}
end_function
begin_function
DECL|function|eventType
name|QEvent
operator|::
name|Type
name|QDirectFbConvenience
operator|::
name|eventType
parameter_list|(
name|DFBWindowEventType
name|type
parameter_list|)
block|{
switch|switch
condition|(
name|type
condition|)
block|{
case|case
name|DWET_BUTTONDOWN
case|:
return|return
name|QEvent
operator|::
name|MouseButtonPress
return|;
case|case
name|DWET_BUTTONUP
case|:
return|return
name|QEvent
operator|::
name|MouseButtonRelease
return|;
case|case
name|DWET_MOTION
case|:
return|return
name|QEvent
operator|::
name|MouseMove
return|;
case|case
name|DWET_WHEEL
case|:
return|return
name|QEvent
operator|::
name|Wheel
return|;
case|case
name|DWET_KEYDOWN
case|:
return|return
name|QEvent
operator|::
name|KeyPress
return|;
case|case
name|DWET_KEYUP
case|:
return|return
name|QEvent
operator|::
name|KeyRelease
return|;
default|default:
return|return
name|QEvent
operator|::
name|None
return|;
block|}
block|}
end_function
begin_decl_stmt
DECL|member|dfbKeymap
name|QDirectFbKeyMap
modifier|*
name|QDirectFbConvenience
operator|::
name|dfbKeymap
init|=
literal|0
decl_stmt|;
end_decl_stmt
begin_function
DECL|function|keyMap
name|QDirectFbKeyMap
modifier|*
name|QDirectFbConvenience
operator|::
name|keyMap
parameter_list|()
block|{
if|if
condition|(
operator|!
name|dfbKeymap
condition|)
name|dfbKeymap
operator|=
operator|new
name|QDirectFbKeyMap
argument_list|()
expr_stmt|;
return|return
name|dfbKeymap
return|;
block|}
end_function
begin_constructor
DECL|function|QDirectFbKeyMap
name|QDirectFbKeyMap
operator|::
name|QDirectFbKeyMap
parameter_list|()
block|{
name|insert
argument_list|(
name|DIKS_BACKSPACE
argument_list|,
name|Qt
operator|::
name|Key_Backspace
argument_list|)
expr_stmt|;
name|insert
argument_list|(
name|DIKS_TAB
argument_list|,
name|Qt
operator|::
name|Key_Tab
argument_list|)
expr_stmt|;
name|insert
argument_list|(
name|DIKS_RETURN
argument_list|,
name|Qt
operator|::
name|Key_Return
argument_list|)
expr_stmt|;
name|insert
argument_list|(
name|DIKS_ESCAPE
argument_list|,
name|Qt
operator|::
name|Key_Escape
argument_list|)
expr_stmt|;
name|insert
argument_list|(
name|DIKS_DELETE
argument_list|,
name|Qt
operator|::
name|Key_Delete
argument_list|)
expr_stmt|;
name|insert
argument_list|(
name|DIKS_CURSOR_LEFT
argument_list|,
name|Qt
operator|::
name|Key_Left
argument_list|)
expr_stmt|;
name|insert
argument_list|(
name|DIKS_CURSOR_RIGHT
argument_list|,
name|Qt
operator|::
name|Key_Right
argument_list|)
expr_stmt|;
name|insert
argument_list|(
name|DIKS_CURSOR_UP
argument_list|,
name|Qt
operator|::
name|Key_Up
argument_list|)
expr_stmt|;
name|insert
argument_list|(
name|DIKS_CURSOR_DOWN
argument_list|,
name|Qt
operator|::
name|Key_Down
argument_list|)
expr_stmt|;
name|insert
argument_list|(
name|DIKS_INSERT
argument_list|,
name|Qt
operator|::
name|Key_Insert
argument_list|)
expr_stmt|;
name|insert
argument_list|(
name|DIKS_HOME
argument_list|,
name|Qt
operator|::
name|Key_Home
argument_list|)
expr_stmt|;
name|insert
argument_list|(
name|DIKS_END
argument_list|,
name|Qt
operator|::
name|Key_End
argument_list|)
expr_stmt|;
name|insert
argument_list|(
name|DIKS_PAGE_UP
argument_list|,
name|Qt
operator|::
name|Key_PageUp
argument_list|)
expr_stmt|;
name|insert
argument_list|(
name|DIKS_PAGE_DOWN
argument_list|,
name|Qt
operator|::
name|Key_PageDown
argument_list|)
expr_stmt|;
name|insert
argument_list|(
name|DIKS_PRINT
argument_list|,
name|Qt
operator|::
name|Key_Print
argument_list|)
expr_stmt|;
name|insert
argument_list|(
name|DIKS_PAUSE
argument_list|,
name|Qt
operator|::
name|Key_Pause
argument_list|)
expr_stmt|;
name|insert
argument_list|(
name|DIKS_SELECT
argument_list|,
name|Qt
operator|::
name|Key_Select
argument_list|)
expr_stmt|;
name|insert
argument_list|(
name|DIKS_GOTO
argument_list|,
name|Qt
operator|::
name|Key_OpenUrl
argument_list|)
expr_stmt|;
name|insert
argument_list|(
name|DIKS_CLEAR
argument_list|,
name|Qt
operator|::
name|Key_Clear
argument_list|)
expr_stmt|;
name|insert
argument_list|(
name|DIKS_MENU
argument_list|,
name|Qt
operator|::
name|Key_Menu
argument_list|)
expr_stmt|;
name|insert
argument_list|(
name|DIKS_HELP
argument_list|,
name|Qt
operator|::
name|Key_Help
argument_list|)
expr_stmt|;
name|insert
argument_list|(
name|DIKS_INFO
argument_list|,
name|Qt
operator|::
name|Key_Info
argument_list|)
expr_stmt|;
name|insert
argument_list|(
name|DIKS_EXIT
argument_list|,
name|Qt
operator|::
name|Key_Exit
argument_list|)
expr_stmt|;
name|insert
argument_list|(
name|DIKS_SETUP
argument_list|,
name|Qt
operator|::
name|Key_Settings
argument_list|)
expr_stmt|;
name|insert
argument_list|(
name|DIKS_CD
argument_list|,
name|Qt
operator|::
name|Key_CD
argument_list|)
expr_stmt|;
name|insert
argument_list|(
name|DIKS_INTERNET
argument_list|,
name|Qt
operator|::
name|Key_HomePage
argument_list|)
expr_stmt|;
name|insert
argument_list|(
name|DIKS_MAIL
argument_list|,
name|Qt
operator|::
name|Key_LaunchMail
argument_list|)
expr_stmt|;
name|insert
argument_list|(
name|DIKS_FAVORITES
argument_list|,
name|Qt
operator|::
name|Key_Favorites
argument_list|)
expr_stmt|;
name|insert
argument_list|(
name|DIKS_PHONE
argument_list|,
name|Qt
operator|::
name|Key_Phone
argument_list|)
expr_stmt|;
name|insert
argument_list|(
name|DIKS_PROGRAM
argument_list|,
name|Qt
operator|::
name|Key_Guide
argument_list|)
expr_stmt|;
name|insert
argument_list|(
name|DIKS_TIME
argument_list|,
name|Qt
operator|::
name|Key_Time
argument_list|)
expr_stmt|;
name|insert
argument_list|(
name|DIKS_RED
argument_list|,
name|Qt
operator|::
name|Key_Red
argument_list|)
expr_stmt|;
name|insert
argument_list|(
name|DIKS_GREEN
argument_list|,
name|Qt
operator|::
name|Key_Green
argument_list|)
expr_stmt|;
name|insert
argument_list|(
name|DIKS_YELLOW
argument_list|,
name|Qt
operator|::
name|Key_Yellow
argument_list|)
expr_stmt|;
name|insert
argument_list|(
name|DIKS_BLUE
argument_list|,
name|Qt
operator|::
name|Key_Blue
argument_list|)
expr_stmt|;
name|insert
argument_list|(
name|DIKS_CHANNEL_UP
argument_list|,
name|Qt
operator|::
name|Key_ChannelUp
argument_list|)
expr_stmt|;
name|insert
argument_list|(
name|DIKS_CHANNEL_DOWN
argument_list|,
name|Qt
operator|::
name|Key_ChannelDown
argument_list|)
expr_stmt|;
name|insert
argument_list|(
name|DIKS_BACK
argument_list|,
name|Qt
operator|::
name|Key_Back
argument_list|)
expr_stmt|;
name|insert
argument_list|(
name|DIKS_FORWARD
argument_list|,
name|Qt
operator|::
name|Key_Forward
argument_list|)
expr_stmt|;
name|insert
argument_list|(
name|DIKS_VOLUME_UP
argument_list|,
name|Qt
operator|::
name|Key_VolumeUp
argument_list|)
expr_stmt|;
name|insert
argument_list|(
name|DIKS_VOLUME_DOWN
argument_list|,
name|Qt
operator|::
name|Key_VolumeDown
argument_list|)
expr_stmt|;
name|insert
argument_list|(
name|DIKS_MUTE
argument_list|,
name|Qt
operator|::
name|Key_VolumeMute
argument_list|)
expr_stmt|;
name|insert
argument_list|(
name|DIKS_PLAYPAUSE
argument_list|,
name|Qt
operator|::
name|Key_MediaTogglePlayPause
argument_list|)
expr_stmt|;
name|insert
argument_list|(
name|DIKS_PLAY
argument_list|,
name|Qt
operator|::
name|Key_MediaPlay
argument_list|)
expr_stmt|;
name|insert
argument_list|(
name|DIKS_STOP
argument_list|,
name|Qt
operator|::
name|Key_MediaStop
argument_list|)
expr_stmt|;
name|insert
argument_list|(
name|DIKS_RECORD
argument_list|,
name|Qt
operator|::
name|Key_MediaRecord
argument_list|)
expr_stmt|;
name|insert
argument_list|(
name|DIKS_PREVIOUS
argument_list|,
name|Qt
operator|::
name|Key_MediaPrevious
argument_list|)
expr_stmt|;
name|insert
argument_list|(
name|DIKS_NEXT
argument_list|,
name|Qt
operator|::
name|Key_MediaNext
argument_list|)
expr_stmt|;
name|insert
argument_list|(
name|DIKS_REWIND
argument_list|,
name|Qt
operator|::
name|Key_AudioRewind
argument_list|)
expr_stmt|;
name|insert
argument_list|(
name|DIKS_FASTFORWARD
argument_list|,
name|Qt
operator|::
name|Key_AudioForward
argument_list|)
expr_stmt|;
name|insert
argument_list|(
name|DIKS_SUBTITLE
argument_list|,
name|Qt
operator|::
name|Key_Subtitle
argument_list|)
expr_stmt|;
name|insert
argument_list|(
name|DIKS_F1
argument_list|,
name|Qt
operator|::
name|Key_F1
argument_list|)
expr_stmt|;
name|insert
argument_list|(
name|DIKS_F2
argument_list|,
name|Qt
operator|::
name|Key_F2
argument_list|)
expr_stmt|;
name|insert
argument_list|(
name|DIKS_F3
argument_list|,
name|Qt
operator|::
name|Key_F3
argument_list|)
expr_stmt|;
name|insert
argument_list|(
name|DIKS_F4
argument_list|,
name|Qt
operator|::
name|Key_F4
argument_list|)
expr_stmt|;
name|insert
argument_list|(
name|DIKS_F5
argument_list|,
name|Qt
operator|::
name|Key_F5
argument_list|)
expr_stmt|;
name|insert
argument_list|(
name|DIKS_F6
argument_list|,
name|Qt
operator|::
name|Key_F6
argument_list|)
expr_stmt|;
name|insert
argument_list|(
name|DIKS_F7
argument_list|,
name|Qt
operator|::
name|Key_F7
argument_list|)
expr_stmt|;
name|insert
argument_list|(
name|DIKS_F8
argument_list|,
name|Qt
operator|::
name|Key_F8
argument_list|)
expr_stmt|;
name|insert
argument_list|(
name|DIKS_F9
argument_list|,
name|Qt
operator|::
name|Key_F9
argument_list|)
expr_stmt|;
name|insert
argument_list|(
name|DIKS_F10
argument_list|,
name|Qt
operator|::
name|Key_F10
argument_list|)
expr_stmt|;
name|insert
argument_list|(
name|DIKS_F11
argument_list|,
name|Qt
operator|::
name|Key_F11
argument_list|)
expr_stmt|;
name|insert
argument_list|(
name|DIKS_F12
argument_list|,
name|Qt
operator|::
name|Key_F12
argument_list|)
expr_stmt|;
name|insert
argument_list|(
name|DIKS_SHIFT
argument_list|,
name|Qt
operator|::
name|Key_Shift
argument_list|)
expr_stmt|;
name|insert
argument_list|(
name|DIKS_CONTROL
argument_list|,
name|Qt
operator|::
name|Key_Control
argument_list|)
expr_stmt|;
name|insert
argument_list|(
name|DIKS_ALT
argument_list|,
name|Qt
operator|::
name|Key_Alt
argument_list|)
expr_stmt|;
name|insert
argument_list|(
name|DIKS_ALTGR
argument_list|,
name|Qt
operator|::
name|Key_AltGr
argument_list|)
expr_stmt|;
name|insert
argument_list|(
name|DIKS_META
argument_list|,
name|Qt
operator|::
name|Key_Meta
argument_list|)
expr_stmt|;
name|insert
argument_list|(
name|DIKS_SUPER
argument_list|,
name|Qt
operator|::
name|Key_Super_L
argument_list|)
expr_stmt|;
comment|// ???
name|insert
argument_list|(
name|DIKS_HYPER
argument_list|,
name|Qt
operator|::
name|Key_Hyper_L
argument_list|)
expr_stmt|;
comment|// ???
name|insert
argument_list|(
name|DIKS_CAPS_LOCK
argument_list|,
name|Qt
operator|::
name|Key_CapsLock
argument_list|)
expr_stmt|;
name|insert
argument_list|(
name|DIKS_NUM_LOCK
argument_list|,
name|Qt
operator|::
name|Key_NumLock
argument_list|)
expr_stmt|;
name|insert
argument_list|(
name|DIKS_SCROLL_LOCK
argument_list|,
name|Qt
operator|::
name|Key_ScrollLock
argument_list|)
expr_stmt|;
name|insert
argument_list|(
name|DIKS_DEAD_ABOVEDOT
argument_list|,
name|Qt
operator|::
name|Key_Dead_Abovedot
argument_list|)
expr_stmt|;
name|insert
argument_list|(
name|DIKS_DEAD_ABOVERING
argument_list|,
name|Qt
operator|::
name|Key_Dead_Abovering
argument_list|)
expr_stmt|;
name|insert
argument_list|(
name|DIKS_DEAD_ACUTE
argument_list|,
name|Qt
operator|::
name|Key_Dead_Acute
argument_list|)
expr_stmt|;
name|insert
argument_list|(
name|DIKS_DEAD_BREVE
argument_list|,
name|Qt
operator|::
name|Key_Dead_Breve
argument_list|)
expr_stmt|;
name|insert
argument_list|(
name|DIKS_DEAD_CARON
argument_list|,
name|Qt
operator|::
name|Key_Dead_Caron
argument_list|)
expr_stmt|;
name|insert
argument_list|(
name|DIKS_DEAD_CEDILLA
argument_list|,
name|Qt
operator|::
name|Key_Dead_Cedilla
argument_list|)
expr_stmt|;
name|insert
argument_list|(
name|DIKS_DEAD_CIRCUMFLEX
argument_list|,
name|Qt
operator|::
name|Key_Dead_Circumflex
argument_list|)
expr_stmt|;
name|insert
argument_list|(
name|DIKS_DEAD_DIAERESIS
argument_list|,
name|Qt
operator|::
name|Key_Dead_Diaeresis
argument_list|)
expr_stmt|;
name|insert
argument_list|(
name|DIKS_DEAD_DOUBLEACUTE
argument_list|,
name|Qt
operator|::
name|Key_Dead_Doubleacute
argument_list|)
expr_stmt|;
name|insert
argument_list|(
name|DIKS_DEAD_GRAVE
argument_list|,
name|Qt
operator|::
name|Key_Dead_Grave
argument_list|)
expr_stmt|;
name|insert
argument_list|(
name|DIKS_DEAD_IOTA
argument_list|,
name|Qt
operator|::
name|Key_Dead_Iota
argument_list|)
expr_stmt|;
name|insert
argument_list|(
name|DIKS_DEAD_MACRON
argument_list|,
name|Qt
operator|::
name|Key_Dead_Macron
argument_list|)
expr_stmt|;
name|insert
argument_list|(
name|DIKS_DEAD_OGONEK
argument_list|,
name|Qt
operator|::
name|Key_Dead_Ogonek
argument_list|)
expr_stmt|;
name|insert
argument_list|(
name|DIKS_DEAD_SEMIVOICED_SOUND
argument_list|,
name|Qt
operator|::
name|Key_Dead_Semivoiced_Sound
argument_list|)
expr_stmt|;
name|insert
argument_list|(
name|DIKS_DEAD_TILDE
argument_list|,
name|Qt
operator|::
name|Key_Dead_Tilde
argument_list|)
expr_stmt|;
name|insert
argument_list|(
name|DIKS_DEAD_VOICED_SOUND
argument_list|,
name|Qt
operator|::
name|Key_Dead_Voiced_Sound
argument_list|)
expr_stmt|;
name|insert
argument_list|(
name|DIKS_SPACE
argument_list|,
name|Qt
operator|::
name|Key_Space
argument_list|)
expr_stmt|;
name|insert
argument_list|(
name|DIKS_EXCLAMATION_MARK
argument_list|,
name|Qt
operator|::
name|Key_Exclam
argument_list|)
expr_stmt|;
name|insert
argument_list|(
name|DIKS_QUOTATION
argument_list|,
name|Qt
operator|::
name|Key_QuoteDbl
argument_list|)
expr_stmt|;
name|insert
argument_list|(
name|DIKS_NUMBER_SIGN
argument_list|,
name|Qt
operator|::
name|Key_NumberSign
argument_list|)
expr_stmt|;
name|insert
argument_list|(
name|DIKS_DOLLAR_SIGN
argument_list|,
name|Qt
operator|::
name|Key_Dollar
argument_list|)
expr_stmt|;
name|insert
argument_list|(
name|DIKS_PERCENT_SIGN
argument_list|,
name|Qt
operator|::
name|Key_Percent
argument_list|)
expr_stmt|;
name|insert
argument_list|(
name|DIKS_AMPERSAND
argument_list|,
name|Qt
operator|::
name|Key_Ampersand
argument_list|)
expr_stmt|;
name|insert
argument_list|(
name|DIKS_APOSTROPHE
argument_list|,
name|Qt
operator|::
name|Key_Apostrophe
argument_list|)
expr_stmt|;
name|insert
argument_list|(
name|DIKS_PARENTHESIS_LEFT
argument_list|,
name|Qt
operator|::
name|Key_ParenLeft
argument_list|)
expr_stmt|;
name|insert
argument_list|(
name|DIKS_PARENTHESIS_RIGHT
argument_list|,
name|Qt
operator|::
name|Key_ParenRight
argument_list|)
expr_stmt|;
name|insert
argument_list|(
name|DIKS_ASTERISK
argument_list|,
name|Qt
operator|::
name|Key_Asterisk
argument_list|)
expr_stmt|;
name|insert
argument_list|(
name|DIKS_PLUS_SIGN
argument_list|,
name|Qt
operator|::
name|Key_Plus
argument_list|)
expr_stmt|;
name|insert
argument_list|(
name|DIKS_COMMA
argument_list|,
name|Qt
operator|::
name|Key_Comma
argument_list|)
expr_stmt|;
name|insert
argument_list|(
name|DIKS_MINUS_SIGN
argument_list|,
name|Qt
operator|::
name|Key_Minus
argument_list|)
expr_stmt|;
name|insert
argument_list|(
name|DIKS_PERIOD
argument_list|,
name|Qt
operator|::
name|Key_Period
argument_list|)
expr_stmt|;
name|insert
argument_list|(
name|DIKS_SLASH
argument_list|,
name|Qt
operator|::
name|Key_Slash
argument_list|)
expr_stmt|;
name|insert
argument_list|(
name|DIKS_0
argument_list|,
name|Qt
operator|::
name|Key_0
argument_list|)
expr_stmt|;
name|insert
argument_list|(
name|DIKS_1
argument_list|,
name|Qt
operator|::
name|Key_1
argument_list|)
expr_stmt|;
name|insert
argument_list|(
name|DIKS_2
argument_list|,
name|Qt
operator|::
name|Key_2
argument_list|)
expr_stmt|;
name|insert
argument_list|(
name|DIKS_3
argument_list|,
name|Qt
operator|::
name|Key_3
argument_list|)
expr_stmt|;
name|insert
argument_list|(
name|DIKS_4
argument_list|,
name|Qt
operator|::
name|Key_4
argument_list|)
expr_stmt|;
name|insert
argument_list|(
name|DIKS_5
argument_list|,
name|Qt
operator|::
name|Key_5
argument_list|)
expr_stmt|;
name|insert
argument_list|(
name|DIKS_6
argument_list|,
name|Qt
operator|::
name|Key_6
argument_list|)
expr_stmt|;
name|insert
argument_list|(
name|DIKS_7
argument_list|,
name|Qt
operator|::
name|Key_7
argument_list|)
expr_stmt|;
name|insert
argument_list|(
name|DIKS_8
argument_list|,
name|Qt
operator|::
name|Key_8
argument_list|)
expr_stmt|;
name|insert
argument_list|(
name|DIKS_9
argument_list|,
name|Qt
operator|::
name|Key_9
argument_list|)
expr_stmt|;
name|insert
argument_list|(
name|DIKS_COLON
argument_list|,
name|Qt
operator|::
name|Key_Colon
argument_list|)
expr_stmt|;
name|insert
argument_list|(
name|DIKS_SEMICOLON
argument_list|,
name|Qt
operator|::
name|Key_Semicolon
argument_list|)
expr_stmt|;
name|insert
argument_list|(
name|DIKS_LESS_THAN_SIGN
argument_list|,
name|Qt
operator|::
name|Key_Less
argument_list|)
expr_stmt|;
name|insert
argument_list|(
name|DIKS_EQUALS_SIGN
argument_list|,
name|Qt
operator|::
name|Key_Equal
argument_list|)
expr_stmt|;
name|insert
argument_list|(
name|DIKS_GREATER_THAN_SIGN
argument_list|,
name|Qt
operator|::
name|Key_Greater
argument_list|)
expr_stmt|;
name|insert
argument_list|(
name|DIKS_QUESTION_MARK
argument_list|,
name|Qt
operator|::
name|Key_Question
argument_list|)
expr_stmt|;
name|insert
argument_list|(
name|DIKS_AT
argument_list|,
name|Qt
operator|::
name|Key_At
argument_list|)
expr_stmt|;
name|insert
argument_list|(
name|DIKS_CAPITAL_A
argument_list|,
name|Qt
operator|::
name|Key_A
argument_list|)
expr_stmt|;
name|insert
argument_list|(
name|DIKS_CAPITAL_B
argument_list|,
name|Qt
operator|::
name|Key_B
argument_list|)
expr_stmt|;
name|insert
argument_list|(
name|DIKS_CAPITAL_C
argument_list|,
name|Qt
operator|::
name|Key_C
argument_list|)
expr_stmt|;
name|insert
argument_list|(
name|DIKS_CAPITAL_D
argument_list|,
name|Qt
operator|::
name|Key_D
argument_list|)
expr_stmt|;
name|insert
argument_list|(
name|DIKS_CAPITAL_E
argument_list|,
name|Qt
operator|::
name|Key_E
argument_list|)
expr_stmt|;
name|insert
argument_list|(
name|DIKS_CAPITAL_F
argument_list|,
name|Qt
operator|::
name|Key_F
argument_list|)
expr_stmt|;
name|insert
argument_list|(
name|DIKS_CAPITAL_G
argument_list|,
name|Qt
operator|::
name|Key_G
argument_list|)
expr_stmt|;
name|insert
argument_list|(
name|DIKS_CAPITAL_H
argument_list|,
name|Qt
operator|::
name|Key_H
argument_list|)
expr_stmt|;
name|insert
argument_list|(
name|DIKS_CAPITAL_I
argument_list|,
name|Qt
operator|::
name|Key_I
argument_list|)
expr_stmt|;
name|insert
argument_list|(
name|DIKS_CAPITAL_J
argument_list|,
name|Qt
operator|::
name|Key_J
argument_list|)
expr_stmt|;
name|insert
argument_list|(
name|DIKS_CAPITAL_K
argument_list|,
name|Qt
operator|::
name|Key_K
argument_list|)
expr_stmt|;
name|insert
argument_list|(
name|DIKS_CAPITAL_L
argument_list|,
name|Qt
operator|::
name|Key_L
argument_list|)
expr_stmt|;
name|insert
argument_list|(
name|DIKS_CAPITAL_M
argument_list|,
name|Qt
operator|::
name|Key_M
argument_list|)
expr_stmt|;
name|insert
argument_list|(
name|DIKS_CAPITAL_N
argument_list|,
name|Qt
operator|::
name|Key_N
argument_list|)
expr_stmt|;
name|insert
argument_list|(
name|DIKS_CAPITAL_O
argument_list|,
name|Qt
operator|::
name|Key_O
argument_list|)
expr_stmt|;
name|insert
argument_list|(
name|DIKS_CAPITAL_P
argument_list|,
name|Qt
operator|::
name|Key_P
argument_list|)
expr_stmt|;
name|insert
argument_list|(
name|DIKS_CAPITAL_Q
argument_list|,
name|Qt
operator|::
name|Key_Q
argument_list|)
expr_stmt|;
name|insert
argument_list|(
name|DIKS_CAPITAL_R
argument_list|,
name|Qt
operator|::
name|Key_R
argument_list|)
expr_stmt|;
name|insert
argument_list|(
name|DIKS_CAPITAL_S
argument_list|,
name|Qt
operator|::
name|Key_S
argument_list|)
expr_stmt|;
name|insert
argument_list|(
name|DIKS_CAPITAL_T
argument_list|,
name|Qt
operator|::
name|Key_T
argument_list|)
expr_stmt|;
name|insert
argument_list|(
name|DIKS_CAPITAL_U
argument_list|,
name|Qt
operator|::
name|Key_U
argument_list|)
expr_stmt|;
name|insert
argument_list|(
name|DIKS_CAPITAL_V
argument_list|,
name|Qt
operator|::
name|Key_V
argument_list|)
expr_stmt|;
name|insert
argument_list|(
name|DIKS_CAPITAL_W
argument_list|,
name|Qt
operator|::
name|Key_W
argument_list|)
expr_stmt|;
name|insert
argument_list|(
name|DIKS_CAPITAL_X
argument_list|,
name|Qt
operator|::
name|Key_X
argument_list|)
expr_stmt|;
name|insert
argument_list|(
name|DIKS_CAPITAL_Y
argument_list|,
name|Qt
operator|::
name|Key_Y
argument_list|)
expr_stmt|;
name|insert
argument_list|(
name|DIKS_CAPITAL_Z
argument_list|,
name|Qt
operator|::
name|Key_Z
argument_list|)
expr_stmt|;
name|insert
argument_list|(
name|DIKS_SQUARE_BRACKET_LEFT
argument_list|,
name|Qt
operator|::
name|Key_BracketLeft
argument_list|)
expr_stmt|;
name|insert
argument_list|(
name|DIKS_BACKSLASH
argument_list|,
name|Qt
operator|::
name|Key_Backslash
argument_list|)
expr_stmt|;
name|insert
argument_list|(
name|DIKS_SQUARE_BRACKET_RIGHT
argument_list|,
name|Qt
operator|::
name|Key_BracketRight
argument_list|)
expr_stmt|;
name|insert
argument_list|(
name|DIKS_CIRCUMFLEX_ACCENT
argument_list|,
name|Qt
operator|::
name|Key_AsciiCircum
argument_list|)
expr_stmt|;
name|insert
argument_list|(
name|DIKS_UNDERSCORE
argument_list|,
name|Qt
operator|::
name|Key_Underscore
argument_list|)
expr_stmt|;
name|insert
argument_list|(
name|DIKS_SMALL_A
argument_list|,
name|Qt
operator|::
name|Key_A
argument_list|)
expr_stmt|;
name|insert
argument_list|(
name|DIKS_SMALL_B
argument_list|,
name|Qt
operator|::
name|Key_B
argument_list|)
expr_stmt|;
name|insert
argument_list|(
name|DIKS_SMALL_C
argument_list|,
name|Qt
operator|::
name|Key_C
argument_list|)
expr_stmt|;
name|insert
argument_list|(
name|DIKS_SMALL_D
argument_list|,
name|Qt
operator|::
name|Key_D
argument_list|)
expr_stmt|;
name|insert
argument_list|(
name|DIKS_SMALL_E
argument_list|,
name|Qt
operator|::
name|Key_E
argument_list|)
expr_stmt|;
name|insert
argument_list|(
name|DIKS_SMALL_F
argument_list|,
name|Qt
operator|::
name|Key_F
argument_list|)
expr_stmt|;
name|insert
argument_list|(
name|DIKS_SMALL_G
argument_list|,
name|Qt
operator|::
name|Key_G
argument_list|)
expr_stmt|;
name|insert
argument_list|(
name|DIKS_SMALL_H
argument_list|,
name|Qt
operator|::
name|Key_H
argument_list|)
expr_stmt|;
name|insert
argument_list|(
name|DIKS_SMALL_I
argument_list|,
name|Qt
operator|::
name|Key_I
argument_list|)
expr_stmt|;
name|insert
argument_list|(
name|DIKS_SMALL_J
argument_list|,
name|Qt
operator|::
name|Key_J
argument_list|)
expr_stmt|;
name|insert
argument_list|(
name|DIKS_SMALL_K
argument_list|,
name|Qt
operator|::
name|Key_K
argument_list|)
expr_stmt|;
name|insert
argument_list|(
name|DIKS_SMALL_L
argument_list|,
name|Qt
operator|::
name|Key_L
argument_list|)
expr_stmt|;
name|insert
argument_list|(
name|DIKS_SMALL_M
argument_list|,
name|Qt
operator|::
name|Key_M
argument_list|)
expr_stmt|;
name|insert
argument_list|(
name|DIKS_SMALL_N
argument_list|,
name|Qt
operator|::
name|Key_N
argument_list|)
expr_stmt|;
name|insert
argument_list|(
name|DIKS_SMALL_O
argument_list|,
name|Qt
operator|::
name|Key_O
argument_list|)
expr_stmt|;
name|insert
argument_list|(
name|DIKS_SMALL_P
argument_list|,
name|Qt
operator|::
name|Key_P
argument_list|)
expr_stmt|;
name|insert
argument_list|(
name|DIKS_SMALL_Q
argument_list|,
name|Qt
operator|::
name|Key_Q
argument_list|)
expr_stmt|;
name|insert
argument_list|(
name|DIKS_SMALL_R
argument_list|,
name|Qt
operator|::
name|Key_R
argument_list|)
expr_stmt|;
name|insert
argument_list|(
name|DIKS_SMALL_S
argument_list|,
name|Qt
operator|::
name|Key_S
argument_list|)
expr_stmt|;
name|insert
argument_list|(
name|DIKS_SMALL_T
argument_list|,
name|Qt
operator|::
name|Key_T
argument_list|)
expr_stmt|;
name|insert
argument_list|(
name|DIKS_SMALL_U
argument_list|,
name|Qt
operator|::
name|Key_U
argument_list|)
expr_stmt|;
name|insert
argument_list|(
name|DIKS_SMALL_V
argument_list|,
name|Qt
operator|::
name|Key_V
argument_list|)
expr_stmt|;
name|insert
argument_list|(
name|DIKS_SMALL_W
argument_list|,
name|Qt
operator|::
name|Key_W
argument_list|)
expr_stmt|;
name|insert
argument_list|(
name|DIKS_SMALL_X
argument_list|,
name|Qt
operator|::
name|Key_X
argument_list|)
expr_stmt|;
name|insert
argument_list|(
name|DIKS_SMALL_Y
argument_list|,
name|Qt
operator|::
name|Key_Y
argument_list|)
expr_stmt|;
name|insert
argument_list|(
name|DIKS_SMALL_Z
argument_list|,
name|Qt
operator|::
name|Key_Z
argument_list|)
expr_stmt|;
name|insert
argument_list|(
name|DIKS_CURLY_BRACKET_LEFT
argument_list|,
name|Qt
operator|::
name|Key_BraceLeft
argument_list|)
expr_stmt|;
name|insert
argument_list|(
name|DIKS_VERTICAL_BAR
argument_list|,
name|Qt
operator|::
name|Key_Bar
argument_list|)
expr_stmt|;
name|insert
argument_list|(
name|DIKS_CURLY_BRACKET_RIGHT
argument_list|,
name|Qt
operator|::
name|Key_BraceRight
argument_list|)
expr_stmt|;
name|insert
argument_list|(
name|DIKS_TILDE
argument_list|,
name|Qt
operator|::
name|Key_AsciiTilde
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_function
DECL|function|toDfbScreen
name|QDirectFbScreen
modifier|*
name|toDfbScreen
parameter_list|(
name|QWindow
modifier|*
name|window
parameter_list|)
block|{
return|return
cast|static_cast
argument_list|<
name|QDirectFbScreen
operator|*
argument_list|>
argument_list|(
name|window
operator|->
name|screen
argument_list|()
operator|->
name|handle
argument_list|()
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|toDfbLayer
name|IDirectFBDisplayLayer
modifier|*
name|toDfbLayer
parameter_list|(
name|QPlatformScreen
modifier|*
name|screen
parameter_list|)
block|{
return|return
cast|static_cast
argument_list|<
name|QDirectFbScreen
operator|*
argument_list|>
argument_list|(
name|screen
argument_list|)
operator|->
name|dfbLayer
argument_list|()
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
