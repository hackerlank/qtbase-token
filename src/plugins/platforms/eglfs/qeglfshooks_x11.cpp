begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the qmake spec of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qeglfshooks.h"
end_include
begin_include
include|#
directive|include
file|<qpa/qwindowsysteminterface.h>
end_include
begin_include
include|#
directive|include
file|<qpa/qplatformwindow.h>
end_include
begin_include
include|#
directive|include
file|<QThread>
end_include
begin_include
include|#
directive|include
file|<X11/Xlib.h>
end_include
begin_include
include|#
directive|include
file|<X11/Xlib-xcb.h>
end_include
begin_include
include|#
directive|include
file|<xcb/xcb.h>
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_class_decl
class_decl|class
name|QEglFSX11Hooks
class_decl|;
end_class_decl
begin_class
DECL|class|EventReader
class|class
name|EventReader
super|:
specifier|public
name|QThread
block|{
public|public:
DECL|function|EventReader
name|EventReader
parameter_list|(
name|QEglFSX11Hooks
modifier|*
name|hooks
parameter_list|)
member_init_list|:
name|m_hooks
argument_list|(
name|hooks
argument_list|)
block|{ }
name|void
name|run
parameter_list|()
function_decl|;
private|private:
DECL|member|m_hooks
name|QEglFSX11Hooks
modifier|*
name|m_hooks
decl_stmt|;
block|}
class|;
end_class
begin_namespace
DECL|namespace|Atoms
namespace|namespace
name|Atoms
block|{
enum|enum
block|{
DECL|enumerator|_NET_WM_NAME
name|_NET_WM_NAME
init|=
literal|0
block|,
DECL|enumerator|UTF8_STRING
name|UTF8_STRING
block|,
DECL|enumerator|WM_PROTOCOLS
name|WM_PROTOCOLS
block|,
DECL|enumerator|WM_DELETE_WINDOW
name|WM_DELETE_WINDOW
block|,
DECL|enumerator|_NET_WM_STATE
name|_NET_WM_STATE
block|,
DECL|enumerator|_NET_WM_STATE_FULLSCREEN
name|_NET_WM_STATE_FULLSCREEN
block|,
DECL|enumerator|N_ATOMS
name|N_ATOMS
block|}
enum|;
block|}
end_namespace
begin_class
DECL|class|QEglFSX11Hooks
class|class
name|QEglFSX11Hooks
super|:
specifier|public
name|QEglFSHooks
block|{
public|public:
DECL|function|QEglFSX11Hooks
name|QEglFSX11Hooks
parameter_list|()
member_init_list|:
name|m_connection
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|m_window
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|m_eventReader
argument_list|(
literal|0
argument_list|)
block|{}
specifier|virtual
name|void
name|platformInit
parameter_list|()
function_decl|;
specifier|virtual
name|void
name|platformDestroy
parameter_list|()
function_decl|;
specifier|virtual
name|EGLNativeDisplayType
name|platformDisplay
parameter_list|()
specifier|const
function_decl|;
specifier|virtual
name|QSize
name|screenSize
parameter_list|()
specifier|const
function_decl|;
specifier|virtual
name|EGLNativeWindowType
name|createNativeWindow
parameter_list|(
name|QPlatformWindow
modifier|*
name|window
parameter_list|,
specifier|const
name|QSize
modifier|&
name|size
parameter_list|,
specifier|const
name|QSurfaceFormat
modifier|&
name|format
parameter_list|)
function_decl|;
specifier|virtual
name|void
name|destroyNativeWindow
parameter_list|(
name|EGLNativeWindowType
name|window
parameter_list|)
function_decl|;
specifier|virtual
name|bool
name|hasCapability
parameter_list|(
name|QPlatformIntegration
operator|::
name|Capability
name|cap
parameter_list|)
specifier|const
function_decl|;
DECL|function|connection
name|xcb_connection_t
modifier|*
name|connection
parameter_list|()
block|{
return|return
name|m_connection
return|;
block|}
DECL|function|atoms
specifier|const
name|xcb_atom_t
modifier|*
name|atoms
parameter_list|()
specifier|const
block|{
return|return
name|m_atoms
return|;
block|}
DECL|function|platformWindow
name|QPlatformWindow
modifier|*
name|platformWindow
parameter_list|()
block|{
return|return
name|m_platformWindow
return|;
block|}
private|private:
name|void
name|sendConnectionEvent
parameter_list|(
name|xcb_atom_t
name|a
parameter_list|)
function_decl|;
DECL|member|m_display
name|Display
modifier|*
name|m_display
decl_stmt|;
DECL|member|m_connection
name|xcb_connection_t
modifier|*
name|m_connection
decl_stmt|;
DECL|member|m_atoms
name|xcb_atom_t
name|m_atoms
index|[
name|Atoms
operator|::
name|N_ATOMS
index|]
decl_stmt|;
DECL|member|m_window
name|xcb_window_t
name|m_window
decl_stmt|;
DECL|member|m_eventReader
name|EventReader
modifier|*
name|m_eventReader
decl_stmt|;
DECL|member|m_connectionEventListener
name|xcb_window_t
name|m_connectionEventListener
decl_stmt|;
DECL|member|m_platformWindow
name|QPlatformWindow
modifier|*
name|m_platformWindow
decl_stmt|;
DECL|member|m_screenSize
specifier|mutable
name|QSize
name|m_screenSize
decl_stmt|;
block|}
class|;
end_class
begin_decl_stmt
DECL|variable|running
name|QAtomicInt
name|running
decl_stmt|;
end_decl_stmt
begin_function
DECL|function|translateMouseButtons
specifier|static
name|Qt
operator|::
name|MouseButtons
name|translateMouseButtons
parameter_list|(
name|int
name|s
parameter_list|)
block|{
name|Qt
operator|::
name|MouseButtons
name|ret
init|=
literal|0
decl_stmt|;
if|if
condition|(
name|s
operator|&
name|XCB_BUTTON_MASK_1
condition|)
name|ret
operator||=
name|Qt
operator|::
name|LeftButton
expr_stmt|;
if|if
condition|(
name|s
operator|&
name|XCB_BUTTON_MASK_2
condition|)
name|ret
operator||=
name|Qt
operator|::
name|MidButton
expr_stmt|;
if|if
condition|(
name|s
operator|&
name|XCB_BUTTON_MASK_3
condition|)
name|ret
operator||=
name|Qt
operator|::
name|RightButton
expr_stmt|;
return|return
name|ret
return|;
block|}
end_function
begin_function
DECL|function|translateMouseButton
specifier|static
name|Qt
operator|::
name|MouseButton
name|translateMouseButton
parameter_list|(
name|xcb_button_t
name|s
parameter_list|)
block|{
switch|switch
condition|(
name|s
condition|)
block|{
case|case
literal|1
case|:
return|return
name|Qt
operator|::
name|LeftButton
return|;
case|case
literal|2
case|:
return|return
name|Qt
operator|::
name|MidButton
return|;
case|case
literal|3
case|:
return|return
name|Qt
operator|::
name|RightButton
return|;
comment|// Button values 4-7 were already handled as Wheel events, and won't occur here.
case|case
literal|8
case|:
return|return
name|Qt
operator|::
name|BackButton
return|;
comment|// Also known as Qt::ExtraButton1
case|case
literal|9
case|:
return|return
name|Qt
operator|::
name|ForwardButton
return|;
comment|// Also known as Qt::ExtraButton2
case|case
literal|10
case|:
return|return
name|Qt
operator|::
name|ExtraButton3
return|;
case|case
literal|11
case|:
return|return
name|Qt
operator|::
name|ExtraButton4
return|;
case|case
literal|12
case|:
return|return
name|Qt
operator|::
name|ExtraButton5
return|;
case|case
literal|13
case|:
return|return
name|Qt
operator|::
name|ExtraButton6
return|;
case|case
literal|14
case|:
return|return
name|Qt
operator|::
name|ExtraButton7
return|;
case|case
literal|15
case|:
return|return
name|Qt
operator|::
name|ExtraButton8
return|;
case|case
literal|16
case|:
return|return
name|Qt
operator|::
name|ExtraButton9
return|;
case|case
literal|17
case|:
return|return
name|Qt
operator|::
name|ExtraButton10
return|;
case|case
literal|18
case|:
return|return
name|Qt
operator|::
name|ExtraButton11
return|;
case|case
literal|19
case|:
return|return
name|Qt
operator|::
name|ExtraButton12
return|;
case|case
literal|20
case|:
return|return
name|Qt
operator|::
name|ExtraButton13
return|;
case|case
literal|21
case|:
return|return
name|Qt
operator|::
name|ExtraButton14
return|;
case|case
literal|22
case|:
return|return
name|Qt
operator|::
name|ExtraButton15
return|;
case|case
literal|23
case|:
return|return
name|Qt
operator|::
name|ExtraButton16
return|;
case|case
literal|24
case|:
return|return
name|Qt
operator|::
name|ExtraButton17
return|;
case|case
literal|25
case|:
return|return
name|Qt
operator|::
name|ExtraButton18
return|;
case|case
literal|26
case|:
return|return
name|Qt
operator|::
name|ExtraButton19
return|;
case|case
literal|27
case|:
return|return
name|Qt
operator|::
name|ExtraButton20
return|;
case|case
literal|28
case|:
return|return
name|Qt
operator|::
name|ExtraButton21
return|;
case|case
literal|29
case|:
return|return
name|Qt
operator|::
name|ExtraButton22
return|;
case|case
literal|30
case|:
return|return
name|Qt
operator|::
name|ExtraButton23
return|;
case|case
literal|31
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
DECL|function|run
name|void
name|EventReader
operator|::
name|run
parameter_list|()
block|{
name|Qt
operator|::
name|MouseButtons
name|buttons
decl_stmt|;
name|xcb_generic_event_t
modifier|*
name|event
decl_stmt|;
while|while
condition|(
name|running
operator|.
name|load
argument_list|()
operator|&&
operator|(
name|event
operator|=
name|xcb_wait_for_event
argument_list|(
name|m_hooks
operator|->
name|connection
argument_list|()
argument_list|)
operator|)
condition|)
block|{
name|uint
name|response_type
init|=
name|event
operator|->
name|response_type
operator|&
operator|~
literal|0x80
decl_stmt|;
switch|switch
condition|(
name|response_type
condition|)
block|{
case|case
name|XCB_BUTTON_PRESS
case|:
block|{
name|xcb_button_press_event_t
modifier|*
name|press
init|=
operator|(
name|xcb_button_press_event_t
operator|*
operator|)
name|event
decl_stmt|;
name|QPoint
name|p
argument_list|(
name|press
operator|->
name|event_x
argument_list|,
name|press
operator|->
name|event_y
argument_list|)
decl_stmt|;
name|buttons
operator|=
operator|(
name|buttons
operator|&
operator|~
literal|0x7
operator|)
operator||
name|translateMouseButtons
argument_list|(
name|press
operator|->
name|state
argument_list|)
expr_stmt|;
name|buttons
operator||=
name|translateMouseButton
argument_list|(
name|press
operator|->
name|detail
argument_list|)
expr_stmt|;
name|QWindowSystemInterface
operator|::
name|handleMouseEvent
argument_list|(
literal|0
argument_list|,
name|press
operator|->
name|time
argument_list|,
name|p
argument_list|,
name|p
argument_list|,
name|buttons
argument_list|)
expr_stmt|;
break|break;
block|}
case|case
name|XCB_BUTTON_RELEASE
case|:
block|{
name|xcb_button_release_event_t
modifier|*
name|release
init|=
operator|(
name|xcb_button_release_event_t
operator|*
operator|)
name|event
decl_stmt|;
name|QPoint
name|p
argument_list|(
name|release
operator|->
name|event_x
argument_list|,
name|release
operator|->
name|event_y
argument_list|)
decl_stmt|;
name|buttons
operator|=
operator|(
name|buttons
operator|&
operator|~
literal|0x7
operator|)
operator||
name|translateMouseButtons
argument_list|(
name|release
operator|->
name|state
argument_list|)
expr_stmt|;
name|buttons
operator|&=
operator|~
name|translateMouseButton
argument_list|(
name|release
operator|->
name|detail
argument_list|)
expr_stmt|;
name|QWindowSystemInterface
operator|::
name|handleMouseEvent
argument_list|(
literal|0
argument_list|,
name|release
operator|->
name|time
argument_list|,
name|p
argument_list|,
name|p
argument_list|,
name|buttons
argument_list|)
expr_stmt|;
break|break;
block|}
case|case
name|XCB_MOTION_NOTIFY
case|:
block|{
name|xcb_motion_notify_event_t
modifier|*
name|motion
init|=
operator|(
name|xcb_motion_notify_event_t
operator|*
operator|)
name|event
decl_stmt|;
name|QPoint
name|p
argument_list|(
name|motion
operator|->
name|event_x
argument_list|,
name|motion
operator|->
name|event_y
argument_list|)
decl_stmt|;
name|QWindowSystemInterface
operator|::
name|handleMouseEvent
argument_list|(
literal|0
argument_list|,
name|motion
operator|->
name|time
argument_list|,
name|p
argument_list|,
name|p
argument_list|,
name|buttons
argument_list|)
expr_stmt|;
break|break;
block|}
case|case
name|XCB_CLIENT_MESSAGE
case|:
block|{
name|xcb_client_message_event_t
modifier|*
name|client
init|=
operator|(
name|xcb_client_message_event_t
operator|*
operator|)
name|event
decl_stmt|;
specifier|const
name|xcb_atom_t
modifier|*
name|atoms
init|=
name|m_hooks
operator|->
name|atoms
argument_list|()
decl_stmt|;
if|if
condition|(
name|client
operator|->
name|format
operator|==
literal|32
operator|&&
name|client
operator|->
name|type
operator|==
name|atoms
index|[
name|Atoms
operator|::
name|WM_PROTOCOLS
index|]
operator|&&
name|client
operator|->
name|data
operator|.
name|data32
index|[
literal|0
index|]
operator|==
name|atoms
index|[
name|Atoms
operator|::
name|WM_DELETE_WINDOW
index|]
condition|)
name|QWindowSystemInterface
operator|::
name|handleCloseEvent
argument_list|(
name|m_hooks
operator|->
name|platformWindow
argument_list|()
operator|->
name|window
argument_list|()
argument_list|)
expr_stmt|;
break|break;
block|}
default|default:
break|break;
block|}
block|}
block|}
end_function
begin_function
DECL|function|sendConnectionEvent
name|void
name|QEglFSX11Hooks
operator|::
name|sendConnectionEvent
parameter_list|(
name|xcb_atom_t
name|a
parameter_list|)
block|{
name|xcb_client_message_event_t
name|event
decl_stmt|;
name|memset
argument_list|(
operator|&
name|event
argument_list|,
literal|0
argument_list|,
sizeof|sizeof
argument_list|(
name|event
argument_list|)
argument_list|)
expr_stmt|;
name|event
operator|.
name|response_type
operator|=
name|XCB_CLIENT_MESSAGE
expr_stmt|;
name|event
operator|.
name|format
operator|=
literal|32
expr_stmt|;
name|event
operator|.
name|sequence
operator|=
literal|0
expr_stmt|;
name|event
operator|.
name|window
operator|=
name|m_connectionEventListener
expr_stmt|;
name|event
operator|.
name|type
operator|=
name|a
expr_stmt|;
name|xcb_send_event
argument_list|(
name|m_connection
argument_list|,
literal|false
argument_list|,
name|m_connectionEventListener
argument_list|,
name|XCB_EVENT_MASK_NO_EVENT
argument_list|,
operator|(
specifier|const
name|char
operator|*
operator|)
operator|&
name|event
argument_list|)
expr_stmt|;
name|xcb_flush
argument_list|(
name|m_connection
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|platformInit
name|void
name|QEglFSX11Hooks
operator|::
name|platformInit
parameter_list|()
block|{
name|m_display
operator|=
name|XOpenDisplay
argument_list|(
literal|0
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|m_display
condition|)
name|qFatal
argument_list|(
literal|"Could not open display"
argument_list|)
expr_stmt|;
name|XSetEventQueueOwner
argument_list|(
name|m_display
argument_list|,
name|XCBOwnsEventQueue
argument_list|)
expr_stmt|;
name|m_connection
operator|=
name|XGetXCBConnection
argument_list|(
name|m_display
argument_list|)
expr_stmt|;
name|running
operator|.
name|ref
argument_list|()
expr_stmt|;
name|xcb_screen_iterator_t
name|it
init|=
name|xcb_setup_roots_iterator
argument_list|(
name|xcb_get_setup
argument_list|(
name|m_connection
argument_list|)
argument_list|)
decl_stmt|;
name|m_connectionEventListener
operator|=
name|xcb_generate_id
argument_list|(
name|m_connection
argument_list|)
expr_stmt|;
name|xcb_create_window
argument_list|(
name|m_connection
argument_list|,
name|XCB_COPY_FROM_PARENT
argument_list|,
name|m_connectionEventListener
argument_list|,
name|it
operator|.
name|data
operator|->
name|root
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|,
literal|0
argument_list|,
name|XCB_WINDOW_CLASS_INPUT_ONLY
argument_list|,
name|it
operator|.
name|data
operator|->
name|root_visual
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|m_eventReader
operator|=
operator|new
name|EventReader
argument_list|(
name|this
argument_list|)
expr_stmt|;
name|m_eventReader
operator|->
name|start
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|platformDestroy
name|void
name|QEglFSX11Hooks
operator|::
name|platformDestroy
parameter_list|()
block|{
name|running
operator|.
name|deref
argument_list|()
expr_stmt|;
name|sendConnectionEvent
argument_list|(
name|XCB_ATOM_NONE
argument_list|)
expr_stmt|;
name|m_eventReader
operator|->
name|wait
argument_list|()
expr_stmt|;
operator|delete
name|m_eventReader
expr_stmt|;
name|m_eventReader
operator|=
literal|0
expr_stmt|;
name|XCloseDisplay
argument_list|(
name|m_display
argument_list|)
expr_stmt|;
name|m_display
operator|=
literal|0
expr_stmt|;
name|m_connection
operator|=
literal|0
expr_stmt|;
block|}
end_function
begin_function
DECL|function|platformDisplay
name|EGLNativeDisplayType
name|QEglFSX11Hooks
operator|::
name|platformDisplay
parameter_list|()
specifier|const
block|{
return|return
name|m_display
return|;
block|}
end_function
begin_function
DECL|function|screenSize
name|QSize
name|QEglFSX11Hooks
operator|::
name|screenSize
parameter_list|()
specifier|const
block|{
if|if
condition|(
name|m_screenSize
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|QList
argument_list|<
name|QByteArray
argument_list|>
name|env
init|=
name|qgetenv
argument_list|(
literal|"EGLFS_X11_SIZE"
argument_list|)
operator|.
name|split
argument_list|(
literal|'x'
argument_list|)
decl_stmt|;
if|if
condition|(
name|env
operator|.
name|length
argument_list|()
operator|==
literal|2
condition|)
block|{
name|m_screenSize
operator|=
name|QSize
argument_list|(
name|env
operator|.
name|at
argument_list|(
literal|0
argument_list|)
operator|.
name|toInt
argument_list|()
argument_list|,
name|env
operator|.
name|at
argument_list|(
literal|1
argument_list|)
operator|.
name|toInt
argument_list|()
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|m_screenSize
operator|=
name|QSize
argument_list|(
literal|640
argument_list|,
literal|480
argument_list|)
expr_stmt|;
name|qDebug
argument_list|(
literal|"EGLFS_X11_SIZE not set, falling back to 640x480"
argument_list|)
expr_stmt|;
block|}
block|}
return|return
name|m_screenSize
return|;
block|}
end_function
begin_function
DECL|function|createNativeWindow
name|EGLNativeWindowType
name|QEglFSX11Hooks
operator|::
name|createNativeWindow
parameter_list|(
name|QPlatformWindow
modifier|*
name|platformWindow
parameter_list|,
specifier|const
name|QSize
modifier|&
name|size
parameter_list|,
specifier|const
name|QSurfaceFormat
modifier|&
name|format
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
name|format
argument_list|)
expr_stmt|;
name|m_platformWindow
operator|=
name|platformWindow
expr_stmt|;
name|xcb_screen_iterator_t
name|it
init|=
name|xcb_setup_roots_iterator
argument_list|(
name|xcb_get_setup
argument_list|(
name|m_connection
argument_list|)
argument_list|)
decl_stmt|;
name|m_window
operator|=
name|xcb_generate_id
argument_list|(
name|m_connection
argument_list|)
expr_stmt|;
name|xcb_create_window
argument_list|(
name|m_connection
argument_list|,
name|XCB_COPY_FROM_PARENT
argument_list|,
name|m_window
argument_list|,
name|it
operator|.
name|data
operator|->
name|root
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
name|size
operator|.
name|width
argument_list|()
argument_list|,
name|size
operator|.
name|height
argument_list|()
argument_list|,
literal|0
argument_list|,
name|XCB_WINDOW_CLASS_INPUT_OUTPUT
argument_list|,
name|it
operator|.
name|data
operator|->
name|root_visual
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|xcb_map_window
argument_list|(
name|m_connection
argument_list|,
name|m_window
argument_list|)
expr_stmt|;
name|xcb_intern_atom_cookie_t
name|cookies
index|[
name|Atoms
operator|::
name|N_ATOMS
index|]
decl_stmt|;
specifier|static
specifier|const
name|char
modifier|*
name|atomNames
index|[
name|Atoms
operator|::
name|N_ATOMS
index|]
init|=
block|{
literal|"_NET_WM_NAME"
block|,
literal|"UTF8_STRING"
block|,
literal|"WM_PROTOCOLS"
block|,
literal|"WM_DELETE_WINDOW"
block|,
literal|"_NET_WM_STATE"
block|,
literal|"_NET_WM_STATE_FULLSCREEN"
block|}
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
name|Atoms
operator|::
name|N_ATOMS
condition|;
operator|++
name|i
control|)
block|{
name|cookies
index|[
name|i
index|]
operator|=
name|xcb_intern_atom
argument_list|(
name|m_connection
argument_list|,
literal|false
argument_list|,
name|strlen
argument_list|(
name|atomNames
index|[
name|i
index|]
argument_list|)
argument_list|,
name|atomNames
index|[
name|i
index|]
argument_list|)
expr_stmt|;
name|xcb_intern_atom_reply_t
modifier|*
name|reply
init|=
name|xcb_intern_atom_reply
argument_list|(
name|m_connection
argument_list|,
name|cookies
index|[
name|i
index|]
argument_list|,
literal|0
argument_list|)
decl_stmt|;
name|m_atoms
index|[
name|i
index|]
operator|=
name|reply
operator|->
name|atom
expr_stmt|;
name|free
argument_list|(
name|reply
argument_list|)
expr_stmt|;
block|}
comment|// Set window title
name|xcb_change_property
argument_list|(
name|m_connection
argument_list|,
name|XCB_PROP_MODE_REPLACE
argument_list|,
name|m_window
argument_list|,
name|m_atoms
index|[
name|Atoms
operator|::
name|_NET_WM_NAME
index|]
argument_list|,
name|m_atoms
index|[
name|Atoms
operator|::
name|UTF8_STRING
index|]
argument_list|,
literal|8
argument_list|,
literal|5
argument_list|,
literal|"EGLFS"
argument_list|)
expr_stmt|;
comment|// Enable WM_DELETE_WINDOW
name|xcb_change_property
argument_list|(
name|m_connection
argument_list|,
name|XCB_PROP_MODE_REPLACE
argument_list|,
name|m_window
argument_list|,
name|m_atoms
index|[
name|Atoms
operator|::
name|WM_PROTOCOLS
index|]
argument_list|,
name|XCB_ATOM_ATOM
argument_list|,
literal|32
argument_list|,
literal|1
argument_list|,
operator|&
name|m_atoms
index|[
name|Atoms
operator|::
name|WM_DELETE_WINDOW
index|]
argument_list|)
expr_stmt|;
if|if
condition|(
name|qgetenv
argument_list|(
literal|"EGLFS_X11_FULLSCREEN"
argument_list|)
operator|.
name|toInt
argument_list|()
condition|)
block|{
comment|// Go fullscreen. The QScreen and QWindow size is controlled by EGLFS_X11_SIZE regardless,
comment|// this is just the native window.
name|xcb_change_property
argument_list|(
name|m_connection
argument_list|,
name|XCB_PROP_MODE_REPLACE
argument_list|,
name|m_window
argument_list|,
name|m_atoms
index|[
name|Atoms
operator|::
name|_NET_WM_STATE
index|]
argument_list|,
name|XCB_ATOM_ATOM
argument_list|,
literal|32
argument_list|,
literal|1
argument_list|,
operator|&
name|m_atoms
index|[
name|Atoms
operator|::
name|_NET_WM_STATE_FULLSCREEN
index|]
argument_list|)
expr_stmt|;
block|}
name|xcb_flush
argument_list|(
name|m_connection
argument_list|)
expr_stmt|;
return|return
name|m_window
return|;
block|}
end_function
begin_function
DECL|function|destroyNativeWindow
name|void
name|QEglFSX11Hooks
operator|::
name|destroyNativeWindow
parameter_list|(
name|EGLNativeWindowType
name|window
parameter_list|)
block|{
name|xcb_destroy_window
argument_list|(
name|m_connection
argument_list|,
name|window
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|hasCapability
name|bool
name|QEglFSX11Hooks
operator|::
name|hasCapability
parameter_list|(
name|QPlatformIntegration
operator|::
name|Capability
name|cap
parameter_list|)
specifier|const
block|{
name|Q_UNUSED
argument_list|(
name|cap
argument_list|)
expr_stmt|;
return|return
literal|false
return|;
block|}
end_function
begin_decl_stmt
DECL|variable|eglFSX11Hooks
specifier|static
name|QEglFSX11Hooks
name|eglFSX11Hooks
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|platformHooks
name|QEglFSHooks
modifier|*
name|platformHooks
init|=
operator|&
name|eglFSX11Hooks
decl_stmt|;
end_decl_stmt
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
