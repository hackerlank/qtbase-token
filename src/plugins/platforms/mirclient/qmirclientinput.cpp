begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2014-2015 Canonical, Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL3$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPLv3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or later as published by the Free ** Software Foundation and appearing in the file LICENSE.GPL included in ** the packaging of this file. Please review the following information to ** ensure the GNU General Public License version 2.0 requirements will be ** met: http://www.gnu.org/licenses/gpl-2.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_comment
comment|// Local
end_comment
begin_include
include|#
directive|include
file|"qmirclientinput.h"
end_include
begin_include
include|#
directive|include
file|"qmirclientintegration.h"
end_include
begin_include
include|#
directive|include
file|"qmirclientnativeinterface.h"
end_include
begin_include
include|#
directive|include
file|"qmirclientscreen.h"
end_include
begin_include
include|#
directive|include
file|"qmirclientwindow.h"
end_include
begin_include
include|#
directive|include
file|"qmirclientlogging.h"
end_include
begin_include
include|#
directive|include
file|"qmirclientorientationchangeevent_p.h"
end_include
begin_comment
comment|// Qt
end_comment
begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|QT_NO_DEBUG
argument_list|)
end_if
begin_include
include|#
directive|include
file|<QtCore/QThread>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_include
include|#
directive|include
file|<QtCore/qglobal.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/QCoreApplication>
end_include
begin_include
include|#
directive|include
file|<private/qguiapplication_p.h>
end_include
begin_include
include|#
directive|include
file|<qpa/qplatforminputcontext.h>
end_include
begin_include
include|#
directive|include
file|<qpa/qwindowsysteminterface.h>
end_include
begin_include
include|#
directive|include
file|<xkbcommon/xkbcommon.h>
end_include
begin_include
include|#
directive|include
file|<xkbcommon/xkbcommon-keysyms.h>
end_include
begin_include
include|#
directive|include
file|<mir_toolkit/mir_client_library.h>
end_include
begin_define
DECL|macro|LOG_EVENTS
define|#
directive|define
name|LOG_EVENTS
value|0
end_define
begin_comment
comment|// XKB Keysyms which do not map directly to Qt types (i.e. Unicode points)
end_comment
begin_decl_stmt
DECL|variable|KeyTable
specifier|static
specifier|const
name|uint32_t
name|KeyTable
index|[]
init|=
block|{
name|XKB_KEY_Escape
block|,
name|Qt
operator|::
name|Key_Escape
block|,
name|XKB_KEY_Tab
block|,
name|Qt
operator|::
name|Key_Tab
block|,
name|XKB_KEY_ISO_Left_Tab
block|,
name|Qt
operator|::
name|Key_Backtab
block|,
name|XKB_KEY_BackSpace
block|,
name|Qt
operator|::
name|Key_Backspace
block|,
name|XKB_KEY_Return
block|,
name|Qt
operator|::
name|Key_Return
block|,
name|XKB_KEY_Insert
block|,
name|Qt
operator|::
name|Key_Insert
block|,
name|XKB_KEY_Delete
block|,
name|Qt
operator|::
name|Key_Delete
block|,
name|XKB_KEY_Clear
block|,
name|Qt
operator|::
name|Key_Delete
block|,
name|XKB_KEY_Pause
block|,
name|Qt
operator|::
name|Key_Pause
block|,
name|XKB_KEY_Print
block|,
name|Qt
operator|::
name|Key_Print
block|,
name|XKB_KEY_Home
block|,
name|Qt
operator|::
name|Key_Home
block|,
name|XKB_KEY_End
block|,
name|Qt
operator|::
name|Key_End
block|,
name|XKB_KEY_Left
block|,
name|Qt
operator|::
name|Key_Left
block|,
name|XKB_KEY_Up
block|,
name|Qt
operator|::
name|Key_Up
block|,
name|XKB_KEY_Right
block|,
name|Qt
operator|::
name|Key_Right
block|,
name|XKB_KEY_Down
block|,
name|Qt
operator|::
name|Key_Down
block|,
name|XKB_KEY_Prior
block|,
name|Qt
operator|::
name|Key_PageUp
block|,
name|XKB_KEY_Next
block|,
name|Qt
operator|::
name|Key_PageDown
block|,
name|XKB_KEY_Shift_L
block|,
name|Qt
operator|::
name|Key_Shift
block|,
name|XKB_KEY_Shift_R
block|,
name|Qt
operator|::
name|Key_Shift
block|,
name|XKB_KEY_Shift_Lock
block|,
name|Qt
operator|::
name|Key_Shift
block|,
name|XKB_KEY_Control_L
block|,
name|Qt
operator|::
name|Key_Control
block|,
name|XKB_KEY_Control_R
block|,
name|Qt
operator|::
name|Key_Control
block|,
name|XKB_KEY_Meta_L
block|,
name|Qt
operator|::
name|Key_Meta
block|,
name|XKB_KEY_Meta_R
block|,
name|Qt
operator|::
name|Key_Meta
block|,
name|XKB_KEY_Alt_L
block|,
name|Qt
operator|::
name|Key_Alt
block|,
name|XKB_KEY_Alt_R
block|,
name|Qt
operator|::
name|Key_Alt
block|,
name|XKB_KEY_Caps_Lock
block|,
name|Qt
operator|::
name|Key_CapsLock
block|,
name|XKB_KEY_Num_Lock
block|,
name|Qt
operator|::
name|Key_NumLock
block|,
name|XKB_KEY_Scroll_Lock
block|,
name|Qt
operator|::
name|Key_ScrollLock
block|,
name|XKB_KEY_Super_L
block|,
name|Qt
operator|::
name|Key_Super_L
block|,
name|XKB_KEY_Super_R
block|,
name|Qt
operator|::
name|Key_Super_R
block|,
name|XKB_KEY_Menu
block|,
name|Qt
operator|::
name|Key_Menu
block|,
name|XKB_KEY_Hyper_L
block|,
name|Qt
operator|::
name|Key_Hyper_L
block|,
name|XKB_KEY_Hyper_R
block|,
name|Qt
operator|::
name|Key_Hyper_R
block|,
name|XKB_KEY_Help
block|,
name|Qt
operator|::
name|Key_Help
block|,
name|XKB_KEY_KP_Space
block|,
name|Qt
operator|::
name|Key_Space
block|,
name|XKB_KEY_KP_Tab
block|,
name|Qt
operator|::
name|Key_Tab
block|,
name|XKB_KEY_KP_Enter
block|,
name|Qt
operator|::
name|Key_Enter
block|,
name|XKB_KEY_KP_Home
block|,
name|Qt
operator|::
name|Key_Home
block|,
name|XKB_KEY_KP_Left
block|,
name|Qt
operator|::
name|Key_Left
block|,
name|XKB_KEY_KP_Up
block|,
name|Qt
operator|::
name|Key_Up
block|,
name|XKB_KEY_KP_Right
block|,
name|Qt
operator|::
name|Key_Right
block|,
name|XKB_KEY_KP_Down
block|,
name|Qt
operator|::
name|Key_Down
block|,
name|XKB_KEY_KP_Prior
block|,
name|Qt
operator|::
name|Key_PageUp
block|,
name|XKB_KEY_KP_Next
block|,
name|Qt
operator|::
name|Key_PageDown
block|,
name|XKB_KEY_KP_End
block|,
name|Qt
operator|::
name|Key_End
block|,
name|XKB_KEY_KP_Begin
block|,
name|Qt
operator|::
name|Key_Clear
block|,
name|XKB_KEY_KP_Insert
block|,
name|Qt
operator|::
name|Key_Insert
block|,
name|XKB_KEY_KP_Delete
block|,
name|Qt
operator|::
name|Key_Delete
block|,
name|XKB_KEY_KP_Equal
block|,
name|Qt
operator|::
name|Key_Equal
block|,
name|XKB_KEY_KP_Multiply
block|,
name|Qt
operator|::
name|Key_Asterisk
block|,
name|XKB_KEY_KP_Add
block|,
name|Qt
operator|::
name|Key_Plus
block|,
name|XKB_KEY_KP_Separator
block|,
name|Qt
operator|::
name|Key_Comma
block|,
name|XKB_KEY_KP_Subtract
block|,
name|Qt
operator|::
name|Key_Minus
block|,
name|XKB_KEY_KP_Decimal
block|,
name|Qt
operator|::
name|Key_Period
block|,
name|XKB_KEY_KP_Divide
block|,
name|Qt
operator|::
name|Key_Slash
block|,
name|XKB_KEY_ISO_Level3_Shift
block|,
name|Qt
operator|::
name|Key_AltGr
block|,
name|XKB_KEY_Multi_key
block|,
name|Qt
operator|::
name|Key_Multi_key
block|,
name|XKB_KEY_Codeinput
block|,
name|Qt
operator|::
name|Key_Codeinput
block|,
name|XKB_KEY_SingleCandidate
block|,
name|Qt
operator|::
name|Key_SingleCandidate
block|,
name|XKB_KEY_MultipleCandidate
block|,
name|Qt
operator|::
name|Key_MultipleCandidate
block|,
name|XKB_KEY_PreviousCandidate
block|,
name|Qt
operator|::
name|Key_PreviousCandidate
block|,
name|XKB_KEY_Mode_switch
block|,
name|Qt
operator|::
name|Key_Mode_switch
block|,
name|XKB_KEY_script_switch
block|,
name|Qt
operator|::
name|Key_Mode_switch
block|,
name|XKB_KEY_XF86AudioRaiseVolume
block|,
name|Qt
operator|::
name|Key_VolumeUp
block|,
name|XKB_KEY_XF86AudioLowerVolume
block|,
name|Qt
operator|::
name|Key_VolumeDown
block|,
name|XKB_KEY_XF86PowerOff
block|,
name|Qt
operator|::
name|Key_PowerOff
block|,
name|XKB_KEY_XF86PowerDown
block|,
name|Qt
operator|::
name|Key_PowerDown
block|,
literal|0
block|,
literal|0
block|}
decl_stmt|;
end_decl_stmt
begin_class
DECL|class|QMirClientEvent
class|class
name|QMirClientEvent
super|:
specifier|public
name|QEvent
block|{
public|public:
DECL|function|QMirClientEvent
name|QMirClientEvent
parameter_list|(
name|QMirClientWindow
modifier|*
name|window
parameter_list|,
specifier|const
name|MirEvent
modifier|*
name|event
parameter_list|,
name|QEvent
operator|::
name|Type
name|type
parameter_list|)
member_init_list|:
name|QEvent
argument_list|(
name|type
argument_list|)
member_init_list|,
name|window
argument_list|(
name|window
argument_list|)
block|{
name|nativeEvent
operator|=
name|mir_event_ref
argument_list|(
name|event
argument_list|)
expr_stmt|;
block|}
DECL|function|~QMirClientEvent
name|~
name|QMirClientEvent
parameter_list|()
block|{
name|mir_event_unref
argument_list|(
name|nativeEvent
argument_list|)
expr_stmt|;
block|}
DECL|member|window
name|QPointer
argument_list|<
name|QMirClientWindow
argument_list|>
name|window
decl_stmt|;
DECL|member|nativeEvent
specifier|const
name|MirEvent
modifier|*
name|nativeEvent
decl_stmt|;
block|}
class|;
end_class
begin_constructor
DECL|function|QMirClientInput
name|QMirClientInput
operator|::
name|QMirClientInput
parameter_list|(
name|QMirClientClientIntegration
modifier|*
name|integration
parameter_list|)
member_init_list|:
name|QObject
argument_list|(
literal|nullptr
argument_list|)
member_init_list|,
name|mIntegration
argument_list|(
name|integration
argument_list|)
member_init_list|,
name|mEventFilterType
argument_list|(
cast|static_cast
argument_list|<
name|QMirClientNativeInterface
operator|*
argument_list|>
argument_list|(
name|integration
operator|->
name|nativeInterface
argument_list|()
argument_list|)
operator|->
name|genericEventFilterType
argument_list|()
argument_list|)
member_init_list|,
name|mEventType
argument_list|(
cast|static_cast
argument_list|<
name|QEvent
operator|::
name|Type
argument_list|>
argument_list|(
name|QEvent
operator|::
name|registerEventType
argument_list|()
argument_list|)
argument_list|)
block|{
comment|// Initialize touch device.
name|mTouchDevice
operator|=
operator|new
name|QTouchDevice
expr_stmt|;
name|mTouchDevice
operator|->
name|setType
argument_list|(
name|QTouchDevice
operator|::
name|TouchScreen
argument_list|)
expr_stmt|;
name|mTouchDevice
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
name|mTouchDevice
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_destructor
DECL|function|~QMirClientInput
name|QMirClientInput
operator|::
name|~
name|QMirClientInput
parameter_list|()
block|{
comment|// Qt will take care of deleting mTouchDevice.
block|}
end_destructor
begin_if
if|#
directive|if
operator|(
name|LOG_EVENTS
operator|!=
literal|0
operator|)
end_if
begin_function
DECL|function|nativeEventTypeToStr
specifier|static
specifier|const
name|char
modifier|*
name|nativeEventTypeToStr
parameter_list|(
name|MirEventType
name|t
parameter_list|)
block|{
switch|switch
condition|(
name|t
condition|)
block|{
case|case
name|mir_event_type_key
case|:
return|return
literal|"mir_event_type_key"
return|;
case|case
name|mir_event_type_motion
case|:
return|return
literal|"mir_event_type_motion"
return|;
case|case
name|mir_event_type_surface
case|:
return|return
literal|"mir_event_type_surface"
return|;
case|case
name|mir_event_type_resize
case|:
return|return
literal|"mir_event_type_resize"
return|;
case|case
name|mir_event_type_prompt_session_state_change
case|:
return|return
literal|"mir_event_type_prompt_session_state_change"
return|;
case|case
name|mir_event_type_orientation
case|:
return|return
literal|"mir_event_type_orientation"
return|;
case|case
name|mir_event_type_close_surface
case|:
return|return
literal|"mir_event_type_close_surface"
return|;
case|case
name|mir_event_type_input
case|:
return|return
literal|"mir_event_type_input"
return|;
default|default:
name|DLOG
argument_list|(
literal|"Invalid event type %d"
argument_list|,
name|t
argument_list|)
expr_stmt|;
return|return
literal|"invalid"
return|;
block|}
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// LOG_EVENTS != 0
end_comment
begin_function
DECL|function|customEvent
name|void
name|QMirClientInput
operator|::
name|customEvent
parameter_list|(
name|QEvent
modifier|*
name|event
parameter_list|)
block|{
name|DASSERT
argument_list|(
name|QThread
operator|::
name|currentThread
argument_list|()
operator|==
name|thread
argument_list|()
argument_list|)
expr_stmt|;
name|QMirClientEvent
modifier|*
name|ubuntuEvent
init|=
cast|static_cast
argument_list|<
name|QMirClientEvent
operator|*
argument_list|>
argument_list|(
name|event
argument_list|)
decl_stmt|;
specifier|const
name|MirEvent
modifier|*
name|nativeEvent
init|=
name|ubuntuEvent
operator|->
name|nativeEvent
decl_stmt|;
if|if
condition|(
operator|(
name|ubuntuEvent
operator|->
name|window
operator|==
literal|nullptr
operator|)
operator|||
operator|(
name|ubuntuEvent
operator|->
name|window
operator|->
name|window
argument_list|()
operator|==
literal|nullptr
operator|)
condition|)
block|{
name|qWarning
argument_list|()
operator|<<
literal|"Attempted to deliver an event to a non-existent window, ignoring."
expr_stmt|;
return|return;
block|}
comment|// Event filtering.
name|long
name|result
decl_stmt|;
if|if
condition|(
name|QWindowSystemInterface
operator|::
name|handleNativeEvent
argument_list|(
name|ubuntuEvent
operator|->
name|window
operator|->
name|window
argument_list|()
argument_list|,
name|mEventFilterType
argument_list|,
cast|const_cast
argument_list|<
name|void
operator|*
argument_list|>
argument_list|(
cast|static_cast
argument_list|<
specifier|const
name|void
operator|*
argument_list|>
argument_list|(
name|nativeEvent
argument_list|)
argument_list|)
argument_list|,
operator|&
name|result
argument_list|)
operator|==
literal|true
condition|)
block|{
name|DLOG
argument_list|(
literal|"event filtered out by native interface"
argument_list|)
expr_stmt|;
return|return;
block|}
if|#
directive|if
operator|(
name|LOG_EVENTS
operator|!=
literal|0
operator|)
name|LOG
argument_list|(
literal|"QMirClientInput::customEvent(type=%s)"
argument_list|,
name|nativeEventTypeToStr
argument_list|(
name|mir_event_get_type
argument_list|(
name|nativeEvent
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|// Event dispatching.
switch|switch
condition|(
name|mir_event_get_type
argument_list|(
name|nativeEvent
argument_list|)
condition|)
block|{
case|case
name|mir_event_type_input
case|:
name|dispatchInputEvent
argument_list|(
name|ubuntuEvent
operator|->
name|window
operator|->
name|window
argument_list|()
argument_list|,
name|mir_event_get_input_event
argument_list|(
name|nativeEvent
argument_list|)
argument_list|)
expr_stmt|;
break|break;
case|case
name|mir_event_type_resize
case|:
block|{
name|Q_ASSERT
argument_list|(
name|ubuntuEvent
operator|->
name|window
operator|->
name|screen
argument_list|()
operator|==
name|mIntegration
operator|->
name|screen
argument_list|()
argument_list|)
expr_stmt|;
name|auto
name|resizeEvent
init|=
name|mir_event_get_resize_event
argument_list|(
name|nativeEvent
argument_list|)
decl_stmt|;
name|mIntegration
operator|->
name|screen
argument_list|()
operator|->
name|handleWindowSurfaceResize
argument_list|(
name|mir_resize_event_get_width
argument_list|(
name|resizeEvent
argument_list|)
argument_list|,
name|mir_resize_event_get_height
argument_list|(
name|resizeEvent
argument_list|)
argument_list|)
expr_stmt|;
name|ubuntuEvent
operator|->
name|window
operator|->
name|handleSurfaceResize
argument_list|(
name|mir_resize_event_get_width
argument_list|(
name|resizeEvent
argument_list|)
argument_list|,
name|mir_resize_event_get_height
argument_list|(
name|resizeEvent
argument_list|)
argument_list|)
expr_stmt|;
break|break;
block|}
case|case
name|mir_event_type_surface
case|:
block|{
name|auto
name|surfaceEvent
init|=
name|mir_event_get_surface_event
argument_list|(
name|nativeEvent
argument_list|)
decl_stmt|;
if|if
condition|(
name|mir_surface_event_get_attribute
argument_list|(
name|surfaceEvent
argument_list|)
operator|==
name|mir_surface_attrib_focus
condition|)
block|{
name|ubuntuEvent
operator|->
name|window
operator|->
name|handleSurfaceFocusChange
argument_list|(
name|mir_surface_event_get_attribute_value
argument_list|(
name|surfaceEvent
argument_list|)
operator|==
name|mir_surface_focused
argument_list|)
expr_stmt|;
block|}
break|break;
block|}
case|case
name|mir_event_type_orientation
case|:
name|dispatchOrientationEvent
argument_list|(
name|ubuntuEvent
operator|->
name|window
operator|->
name|window
argument_list|()
argument_list|,
name|mir_event_get_orientation_event
argument_list|(
name|nativeEvent
argument_list|)
argument_list|)
expr_stmt|;
break|break;
case|case
name|mir_event_type_close_surface
case|:
name|QWindowSystemInterface
operator|::
name|handleCloseEvent
argument_list|(
name|ubuntuEvent
operator|->
name|window
operator|->
name|window
argument_list|()
argument_list|)
expr_stmt|;
break|break;
default|default:
name|DLOG
argument_list|(
literal|"unhandled event type: %d"
argument_list|,
cast|static_cast
argument_list|<
name|int
argument_list|>
argument_list|(
name|mir_event_get_type
argument_list|(
name|nativeEvent
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|postEvent
name|void
name|QMirClientInput
operator|::
name|postEvent
parameter_list|(
name|QMirClientWindow
modifier|*
name|platformWindow
parameter_list|,
specifier|const
name|MirEvent
modifier|*
name|event
parameter_list|)
block|{
name|QWindow
modifier|*
name|window
init|=
name|platformWindow
operator|->
name|window
argument_list|()
decl_stmt|;
name|QCoreApplication
operator|::
name|postEvent
argument_list|(
name|this
argument_list|,
operator|new
name|QMirClientEvent
argument_list|(
name|platformWindow
argument_list|,
name|event
argument_list|,
name|mEventType
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
operator|(
name|window
operator|->
name|flags
argument_list|()
operator|.
name|testFlag
argument_list|(
name|Qt
operator|::
name|WindowTransparentForInput
argument_list|)
operator|)
operator|&&
name|window
operator|->
name|parent
argument_list|()
condition|)
block|{
name|QCoreApplication
operator|::
name|postEvent
argument_list|(
name|this
argument_list|,
operator|new
name|QMirClientEvent
argument_list|(
cast|static_cast
argument_list|<
name|QMirClientWindow
operator|*
argument_list|>
argument_list|(
name|platformWindow
operator|->
name|QPlatformWindow
operator|::
name|parent
argument_list|()
argument_list|)
argument_list|,
name|event
argument_list|,
name|mEventType
argument_list|)
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|dispatchInputEvent
name|void
name|QMirClientInput
operator|::
name|dispatchInputEvent
parameter_list|(
name|QWindow
modifier|*
name|window
parameter_list|,
specifier|const
name|MirInputEvent
modifier|*
name|ev
parameter_list|)
block|{
switch|switch
condition|(
name|mir_input_event_get_type
argument_list|(
name|ev
argument_list|)
condition|)
block|{
case|case
name|mir_input_event_type_key
case|:
name|dispatchKeyEvent
argument_list|(
name|window
argument_list|,
name|ev
argument_list|)
expr_stmt|;
break|break;
case|case
name|mir_input_event_type_touch
case|:
name|dispatchTouchEvent
argument_list|(
name|window
argument_list|,
name|ev
argument_list|)
expr_stmt|;
break|break;
case|case
name|mir_input_event_type_pointer
case|:
name|dispatchPointerEvent
argument_list|(
name|window
argument_list|,
name|ev
argument_list|)
expr_stmt|;
break|break;
default|default:
break|break;
block|}
block|}
end_function
begin_function
DECL|function|dispatchTouchEvent
name|void
name|QMirClientInput
operator|::
name|dispatchTouchEvent
parameter_list|(
name|QWindow
modifier|*
name|window
parameter_list|,
specifier|const
name|MirInputEvent
modifier|*
name|ev
parameter_list|)
block|{
specifier|const
name|MirTouchEvent
modifier|*
name|tev
init|=
name|mir_input_event_get_touch_event
argument_list|(
name|ev
argument_list|)
decl_stmt|;
comment|// FIXME(loicm) Max pressure is device specific. That one is for the Samsung Galaxy Nexus. That
comment|//     needs to be fixed as soon as the compat input lib adds query support.
specifier|const
name|float
name|kMaxPressure
init|=
literal|1.28
decl_stmt|;
specifier|const
name|QRect
name|kWindowGeometry
init|=
name|window
operator|->
name|geometry
argument_list|()
decl_stmt|;
name|QList
argument_list|<
name|QWindowSystemInterface
operator|::
name|TouchPoint
argument_list|>
name|touchPoints
decl_stmt|;
comment|// TODO: Is it worth setting the Qt::TouchPointStationary ones? Currently they are left
comment|//       as Qt::TouchPointMoved
specifier|const
name|unsigned
name|int
name|kPointerCount
init|=
name|mir_touch_event_point_count
argument_list|(
name|tev
argument_list|)
decl_stmt|;
for|for
control|(
name|unsigned
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|kPointerCount
condition|;
operator|++
name|i
control|)
block|{
name|QWindowSystemInterface
operator|::
name|TouchPoint
name|touchPoint
decl_stmt|;
specifier|const
name|float
name|kX
init|=
name|mir_touch_event_axis_value
argument_list|(
name|tev
argument_list|,
name|i
argument_list|,
name|mir_touch_axis_x
argument_list|)
operator|+
name|kWindowGeometry
operator|.
name|x
argument_list|()
decl_stmt|;
specifier|const
name|float
name|kY
init|=
name|mir_touch_event_axis_value
argument_list|(
name|tev
argument_list|,
name|i
argument_list|,
name|mir_touch_axis_y
argument_list|)
operator|+
name|kWindowGeometry
operator|.
name|y
argument_list|()
decl_stmt|;
comment|// see bug lp:1346633 workaround comments elsewhere
specifier|const
name|float
name|kW
init|=
name|mir_touch_event_axis_value
argument_list|(
name|tev
argument_list|,
name|i
argument_list|,
name|mir_touch_axis_touch_major
argument_list|)
decl_stmt|;
specifier|const
name|float
name|kH
init|=
name|mir_touch_event_axis_value
argument_list|(
name|tev
argument_list|,
name|i
argument_list|,
name|mir_touch_axis_touch_minor
argument_list|)
decl_stmt|;
specifier|const
name|float
name|kP
init|=
name|mir_touch_event_axis_value
argument_list|(
name|tev
argument_list|,
name|i
argument_list|,
name|mir_touch_axis_pressure
argument_list|)
decl_stmt|;
name|touchPoint
operator|.
name|id
operator|=
name|mir_touch_event_id
argument_list|(
name|tev
argument_list|,
name|i
argument_list|)
expr_stmt|;
name|touchPoint
operator|.
name|normalPosition
operator|=
name|QPointF
argument_list|(
name|kX
operator|/
name|kWindowGeometry
operator|.
name|width
argument_list|()
argument_list|,
name|kY
operator|/
name|kWindowGeometry
operator|.
name|height
argument_list|()
argument_list|)
expr_stmt|;
name|touchPoint
operator|.
name|area
operator|=
name|QRectF
argument_list|(
name|kX
operator|-
operator|(
name|kW
operator|/
literal|2.0
operator|)
argument_list|,
name|kY
operator|-
operator|(
name|kH
operator|/
literal|2.0
operator|)
argument_list|,
name|kW
argument_list|,
name|kH
argument_list|)
expr_stmt|;
name|touchPoint
operator|.
name|pressure
operator|=
name|kP
operator|/
name|kMaxPressure
expr_stmt|;
name|MirTouchAction
name|touch_action
init|=
name|mir_touch_event_action
argument_list|(
name|tev
argument_list|,
name|i
argument_list|)
decl_stmt|;
switch|switch
condition|(
name|touch_action
condition|)
block|{
case|case
name|mir_touch_action_down
case|:
name|touchPoint
operator|.
name|state
operator|=
name|Qt
operator|::
name|TouchPointPressed
expr_stmt|;
break|break;
case|case
name|mir_touch_action_up
case|:
name|touchPoint
operator|.
name|state
operator|=
name|Qt
operator|::
name|TouchPointReleased
expr_stmt|;
break|break;
case|case
name|mir_touch_action_change
case|:
default|default:
name|touchPoint
operator|.
name|state
operator|=
name|Qt
operator|::
name|TouchPointMoved
expr_stmt|;
block|}
name|touchPoints
operator|.
name|append
argument_list|(
name|touchPoint
argument_list|)
expr_stmt|;
block|}
name|ulong
name|timestamp
init|=
name|mir_input_event_get_event_time
argument_list|(
name|ev
argument_list|)
operator|/
literal|1000000
decl_stmt|;
name|QWindowSystemInterface
operator|::
name|handleTouchEvent
argument_list|(
name|window
argument_list|,
name|timestamp
argument_list|,
name|mTouchDevice
argument_list|,
name|touchPoints
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|translateKeysym
specifier|static
name|uint32_t
name|translateKeysym
parameter_list|(
name|uint32_t
name|sym
parameter_list|,
name|char
modifier|*
name|string
parameter_list|,
name|size_t
name|size
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
name|size
argument_list|)
expr_stmt|;
name|string
index|[
literal|0
index|]
operator|=
literal|'\0'
expr_stmt|;
if|if
condition|(
name|sym
operator|>=
name|XKB_KEY_F1
operator|&&
name|sym
operator|<=
name|XKB_KEY_F35
condition|)
return|return
name|Qt
operator|::
name|Key_F1
operator|+
operator|(
name|int
argument_list|(
name|sym
argument_list|)
operator|-
name|XKB_KEY_F1
operator|)
return|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|KeyTable
index|[
name|i
index|]
condition|;
name|i
operator|+=
literal|2
control|)
block|{
if|if
condition|(
name|sym
operator|==
name|KeyTable
index|[
name|i
index|]
condition|)
return|return
name|KeyTable
index|[
name|i
operator|+
literal|1
index|]
return|;
block|}
name|string
index|[
literal|0
index|]
operator|=
name|sym
expr_stmt|;
name|string
index|[
literal|1
index|]
operator|=
literal|'\0'
expr_stmt|;
return|return
name|toupper
argument_list|(
name|sym
argument_list|)
return|;
block|}
end_function
begin_namespace
namespace|namespace
block|{
DECL|function|qt_modifiers_from_mir
name|Qt
operator|::
name|KeyboardModifiers
name|qt_modifiers_from_mir
parameter_list|(
name|MirInputEventModifiers
name|modifiers
parameter_list|)
block|{
name|Qt
operator|::
name|KeyboardModifiers
name|q_modifiers
init|=
name|Qt
operator|::
name|NoModifier
decl_stmt|;
if|if
condition|(
name|modifiers
operator|&
name|mir_input_event_modifier_shift
condition|)
block|{
name|q_modifiers
operator||=
name|Qt
operator|::
name|ShiftModifier
expr_stmt|;
block|}
if|if
condition|(
name|modifiers
operator|&
name|mir_input_event_modifier_ctrl
condition|)
block|{
name|q_modifiers
operator||=
name|Qt
operator|::
name|ControlModifier
expr_stmt|;
block|}
if|if
condition|(
name|modifiers
operator|&
name|mir_input_event_modifier_alt
condition|)
block|{
name|q_modifiers
operator||=
name|Qt
operator|::
name|AltModifier
expr_stmt|;
block|}
if|if
condition|(
name|modifiers
operator|&
name|mir_input_event_modifier_meta
condition|)
block|{
name|q_modifiers
operator||=
name|Qt
operator|::
name|MetaModifier
expr_stmt|;
block|}
return|return
name|q_modifiers
return|;
block|}
block|}
end_namespace
begin_function
DECL|function|dispatchKeyEvent
name|void
name|QMirClientInput
operator|::
name|dispatchKeyEvent
parameter_list|(
name|QWindow
modifier|*
name|window
parameter_list|,
specifier|const
name|MirInputEvent
modifier|*
name|event
parameter_list|)
block|{
specifier|const
name|MirKeyboardEvent
modifier|*
name|key_event
init|=
name|mir_input_event_get_keyboard_event
argument_list|(
name|event
argument_list|)
decl_stmt|;
name|ulong
name|timestamp
init|=
name|mir_input_event_get_event_time
argument_list|(
name|event
argument_list|)
operator|/
literal|1000000
decl_stmt|;
name|xkb_keysym_t
name|xk_sym
init|=
name|mir_keyboard_event_key_code
argument_list|(
name|key_event
argument_list|)
decl_stmt|;
comment|// Key modifier and unicode index mapping.
name|auto
name|modifiers
init|=
name|qt_modifiers_from_mir
argument_list|(
name|mir_keyboard_event_modifiers
argument_list|(
name|key_event
argument_list|)
argument_list|)
decl_stmt|;
name|MirKeyboardAction
name|action
init|=
name|mir_keyboard_event_action
argument_list|(
name|key_event
argument_list|)
decl_stmt|;
name|QEvent
operator|::
name|Type
name|keyType
init|=
name|action
operator|==
name|mir_keyboard_action_up
condition|?
name|QEvent
operator|::
name|KeyRelease
else|:
name|QEvent
operator|::
name|KeyPress
decl_stmt|;
name|char
name|s
index|[
literal|2
index|]
decl_stmt|;
name|int
name|sym
init|=
name|translateKeysym
argument_list|(
name|xk_sym
argument_list|,
name|s
argument_list|,
sizeof|sizeof
argument_list|(
name|s
argument_list|)
argument_list|)
decl_stmt|;
name|QString
name|text
init|=
name|QString
operator|::
name|fromLatin1
argument_list|(
name|s
argument_list|)
decl_stmt|;
name|bool
name|is_auto_rep
init|=
name|action
operator|==
name|mir_keyboard_action_repeat
decl_stmt|;
name|QPlatformInputContext
modifier|*
name|context
init|=
name|QGuiApplicationPrivate
operator|::
name|platformIntegration
argument_list|()
operator|->
name|inputContext
argument_list|()
decl_stmt|;
if|if
condition|(
name|context
condition|)
block|{
name|QKeyEvent
name|qKeyEvent
argument_list|(
name|keyType
argument_list|,
name|sym
argument_list|,
name|modifiers
argument_list|,
name|text
argument_list|,
name|is_auto_rep
argument_list|)
decl_stmt|;
name|qKeyEvent
operator|.
name|setTimestamp
argument_list|(
name|timestamp
argument_list|)
expr_stmt|;
if|if
condition|(
name|context
operator|->
name|filterEvent
argument_list|(
operator|&
name|qKeyEvent
argument_list|)
condition|)
block|{
name|DLOG
argument_list|(
literal|"key event filtered out by input context"
argument_list|)
expr_stmt|;
return|return;
block|}
block|}
name|QWindowSystemInterface
operator|::
name|handleKeyEvent
argument_list|(
name|window
argument_list|,
name|timestamp
argument_list|,
name|keyType
argument_list|,
name|sym
argument_list|,
name|modifiers
argument_list|,
name|text
argument_list|,
name|is_auto_rep
argument_list|)
expr_stmt|;
block|}
end_function
begin_namespace
namespace|namespace
block|{
DECL|function|extract_buttons
name|Qt
operator|::
name|MouseButtons
name|extract_buttons
parameter_list|(
specifier|const
name|MirPointerEvent
modifier|*
name|pev
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
name|mir_pointer_event_button_state
argument_list|(
name|pev
argument_list|,
name|mir_pointer_button_primary
argument_list|)
condition|)
name|buttons
operator||=
name|Qt
operator|::
name|LeftButton
expr_stmt|;
if|if
condition|(
name|mir_pointer_event_button_state
argument_list|(
name|pev
argument_list|,
name|mir_pointer_button_secondary
argument_list|)
condition|)
name|buttons
operator||=
name|Qt
operator|::
name|RightButton
expr_stmt|;
if|if
condition|(
name|mir_pointer_event_button_state
argument_list|(
name|pev
argument_list|,
name|mir_pointer_button_tertiary
argument_list|)
condition|)
name|buttons
operator||=
name|Qt
operator|::
name|MidButton
expr_stmt|;
comment|// TODO: Should mir back and forward buttons exist?
comment|// should they be Qt::X button 1 and 2?
return|return
name|buttons
return|;
block|}
block|}
end_namespace
begin_function
DECL|function|dispatchPointerEvent
name|void
name|QMirClientInput
operator|::
name|dispatchPointerEvent
parameter_list|(
name|QWindow
modifier|*
name|window
parameter_list|,
specifier|const
name|MirInputEvent
modifier|*
name|ev
parameter_list|)
block|{
name|auto
name|timestamp
init|=
name|mir_input_event_get_event_time
argument_list|(
name|ev
argument_list|)
operator|/
literal|1000000
decl_stmt|;
name|auto
name|pev
init|=
name|mir_input_event_get_pointer_event
argument_list|(
name|ev
argument_list|)
decl_stmt|;
name|auto
name|modifiers
init|=
name|qt_modifiers_from_mir
argument_list|(
name|mir_pointer_event_modifiers
argument_list|(
name|pev
argument_list|)
argument_list|)
decl_stmt|;
name|auto
name|buttons
init|=
name|extract_buttons
argument_list|(
name|pev
argument_list|)
decl_stmt|;
name|auto
name|local_point
init|=
name|QPointF
argument_list|(
name|mir_pointer_event_axis_value
argument_list|(
name|pev
argument_list|,
name|mir_pointer_axis_x
argument_list|)
argument_list|,
name|mir_pointer_event_axis_value
argument_list|(
name|pev
argument_list|,
name|mir_pointer_axis_y
argument_list|)
argument_list|)
decl_stmt|;
name|QWindowSystemInterface
operator|::
name|handleMouseEvent
argument_list|(
name|window
argument_list|,
name|timestamp
argument_list|,
name|local_point
argument_list|,
name|local_point
comment|/* Should we omit global point instead? */
argument_list|,
name|buttons
argument_list|,
name|modifiers
argument_list|)
expr_stmt|;
block|}
end_function
begin_if
if|#
directive|if
operator|(
name|LOG_EVENTS
operator|!=
literal|0
operator|)
end_if
begin_function
DECL|function|nativeOrientationDirectionToStr
specifier|static
specifier|const
name|char
modifier|*
name|nativeOrientationDirectionToStr
parameter_list|(
name|MirOrientation
name|orientation
parameter_list|)
block|{
switch|switch
condition|(
name|orientation
condition|)
block|{
case|case
name|mir_orientation_normal
case|:
return|return
literal|"Normal"
return|;
break|break;
case|case
name|mir_orientation_left
case|:
return|return
literal|"Left"
return|;
break|break;
case|case
name|mir_orientation_inverted
case|:
return|return
literal|"Inverted"
return|;
break|break;
case|case
name|mir_orientation_right
case|:
return|return
literal|"Right"
return|;
break|break;
default|default:
return|return
literal|"INVALID!"
return|;
block|}
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_function
DECL|function|dispatchOrientationEvent
name|void
name|QMirClientInput
operator|::
name|dispatchOrientationEvent
parameter_list|(
name|QWindow
modifier|*
name|window
parameter_list|,
specifier|const
name|MirOrientationEvent
modifier|*
name|event
parameter_list|)
block|{
name|MirOrientation
name|mir_orientation
init|=
name|mir_orientation_event_get_direction
argument_list|(
name|event
argument_list|)
decl_stmt|;
if|#
directive|if
operator|(
name|LOG_EVENTS
operator|!=
literal|0
operator|)
comment|// Orientation event logging.
name|LOG
argument_list|(
literal|"ORIENTATION direction: %s"
argument_list|,
name|nativeOrientationDirectionToStr
argument_list|(
name|mir_orientation
argument_list|)
argument_list|)
expr_stmt|;
endif|#
directive|endif
if|if
condition|(
operator|!
name|window
operator|->
name|screen
argument_list|()
condition|)
block|{
name|DLOG
argument_list|(
literal|"Window has no associated screen, dropping orientation event"
argument_list|)
expr_stmt|;
return|return;
block|}
name|OrientationChangeEvent
operator|::
name|Orientation
name|orientation
decl_stmt|;
switch|switch
condition|(
name|mir_orientation
condition|)
block|{
case|case
name|mir_orientation_normal
case|:
name|orientation
operator|=
name|OrientationChangeEvent
operator|::
name|TopUp
expr_stmt|;
break|break;
case|case
name|mir_orientation_left
case|:
name|orientation
operator|=
name|OrientationChangeEvent
operator|::
name|LeftUp
expr_stmt|;
break|break;
case|case
name|mir_orientation_inverted
case|:
name|orientation
operator|=
name|OrientationChangeEvent
operator|::
name|TopDown
expr_stmt|;
break|break;
case|case
name|mir_orientation_right
case|:
name|orientation
operator|=
name|OrientationChangeEvent
operator|::
name|RightUp
expr_stmt|;
break|break;
default|default:
name|DLOG
argument_list|(
literal|"No such orientation %d"
argument_list|,
name|mir_orientation
argument_list|)
expr_stmt|;
return|return;
block|}
comment|// Dispatch orientation event to [Platform]Screen, as that is where Qt reads it. Screen will handle
comment|// notifying Qt of the actual orientation change - done to prevent multiple Windows each creating
comment|// an identical orientation change event and passing it directly to Qt.
comment|// [Platform]Screen can also factor in the native orientation.
name|QCoreApplication
operator|::
name|postEvent
argument_list|(
cast|static_cast
argument_list|<
name|QMirClientScreen
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
argument_list|,
operator|new
name|OrientationChangeEvent
argument_list|(
name|OrientationChangeEvent
operator|::
name|mType
argument_list|,
name|orientation
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
end_unit
