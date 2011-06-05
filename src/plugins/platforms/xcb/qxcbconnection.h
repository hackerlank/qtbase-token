begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QXCBCONNECTION_H
end_ifndef
begin_define
DECL|macro|QXCBCONNECTION_H
define|#
directive|define
name|QXCBCONNECTION_H
end_define
begin_include
include|#
directive|include
file|<xcb/xcb.h>
end_include
begin_include
include|#
directive|include
file|<QHash>
end_include
begin_include
include|#
directive|include
file|<QList>
end_include
begin_include
include|#
directive|include
file|<QObject>
end_include
begin_include
include|#
directive|include
file|<QVector>
end_include
begin_define
DECL|macro|Q_XCB_DEBUG
define|#
directive|define
name|Q_XCB_DEBUG
end_define
begin_decl_stmt
DECL|variable|QXcbScreen
name|class
name|QXcbScreen
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QXcbWindow
name|class
name|QXcbWindow
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QXcbDrag
name|class
name|QXcbDrag
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QXcbKeyboard
name|class
name|QXcbKeyboard
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QXcbClipboard
name|class
name|QXcbClipboard
decl_stmt|;
end_decl_stmt
begin_typedef
DECL|typedef|xcb_window_t
DECL|typedef|WindowMapper
typedef|typedef
name|QHash
operator|<
name|xcb_window_t
operator|,
name|QXcbWindow
operator|*
operator|>
name|WindowMapper
expr_stmt|;
end_typedef
begin_decl_stmt
name|namespace
name|QXcbAtom
block|{
specifier|static
specifier|const
name|xcb_atom_t
name|XA_PRIMARY
init|=
literal|1
decl_stmt|;
specifier|static
specifier|const
name|xcb_atom_t
name|XA_SECONDARY
init|=
literal|2
decl_stmt|;
specifier|static
specifier|const
name|xcb_atom_t
name|XA_ATOM
init|=
literal|4
decl_stmt|;
specifier|static
specifier|const
name|xcb_atom_t
name|XA_PIXMAP
init|=
literal|20
decl_stmt|;
specifier|static
specifier|const
name|xcb_atom_t
name|XA_BITMAP
init|=
literal|5
decl_stmt|;
specifier|static
specifier|const
name|xcb_atom_t
name|XA_STRING
init|=
literal|32
decl_stmt|;
specifier|static
specifier|const
name|xcb_atom_t
name|XA_WINDOW
init|=
literal|33
decl_stmt|;
enum|enum
name|Atom
block|{
comment|// window-manager<-> client protocols
name|WM_PROTOCOLS
block|,
name|WM_DELETE_WINDOW
block|,
name|WM_TAKE_FOCUS
block|,
name|_NET_WM_PING
block|,
name|_NET_WM_CONTEXT_HELP
block|,
name|_NET_WM_SYNC_REQUEST
block|,
name|_NET_WM_SYNC_REQUEST_COUNTER
block|,
comment|// ICCCM window state
name|WM_STATE
block|,
name|WM_CHANGE_STATE
block|,
comment|// Session management
name|WM_CLIENT_LEADER
block|,
name|WM_WINDOW_ROLE
block|,
name|SM_CLIENT_ID
block|,
comment|// Clipboard
name|CLIPBOARD
block|,
name|INCR
block|,
name|TARGETS
block|,
name|MULTIPLE
block|,
name|TIMESTAMP
block|,
name|SAVE_TARGETS
block|,
name|CLIP_TEMPORARY
block|,
name|_QT_SELECTION
block|,
name|_QT_CLIPBOARD_SENTINEL
block|,
name|_QT_SELECTION_SENTINEL
block|,
name|CLIPBOARD_MANAGER
block|,
name|RESOURCE_MANAGER
block|,
name|_XSETROOT_ID
block|,
name|_QT_SCROLL_DONE
block|,
name|_QT_INPUT_ENCODING
block|,
name|_MOTIF_WM_HINTS
block|,
name|DTWM_IS_RUNNING
block|,
name|ENLIGHTENMENT_DESKTOP
block|,
name|_DT_SAVE_MODE
block|,
name|_SGI_DESKS_MANAGER
block|,
comment|// EWMH (aka NETWM)
name|_NET_SUPPORTED
block|,
name|_NET_VIRTUAL_ROOTS
block|,
name|_NET_WORKAREA
block|,
name|_NET_MOVERESIZE_WINDOW
block|,
name|_NET_WM_MOVERESIZE
block|,
name|_NET_WM_NAME
block|,
name|_NET_WM_ICON_NAME
block|,
name|_NET_WM_ICON
block|,
name|_NET_WM_PID
block|,
name|_NET_WM_WINDOW_OPACITY
block|,
name|_NET_WM_STATE
block|,
name|_NET_WM_STATE_ABOVE
block|,
name|_NET_WM_STATE_BELOW
block|,
name|_NET_WM_STATE_FULLSCREEN
block|,
name|_NET_WM_STATE_MAXIMIZED_HORZ
block|,
name|_NET_WM_STATE_MAXIMIZED_VERT
block|,
name|_NET_WM_STATE_MODAL
block|,
name|_NET_WM_STATE_STAYS_ON_TOP
block|,
name|_NET_WM_STATE_DEMANDS_ATTENTION
block|,
name|_NET_WM_USER_TIME
block|,
name|_NET_WM_USER_TIME_WINDOW
block|,
name|_NET_WM_FULL_PLACEMENT
block|,
name|_NET_WM_WINDOW_TYPE
block|,
name|_NET_WM_WINDOW_TYPE_DESKTOP
block|,
name|_NET_WM_WINDOW_TYPE_DOCK
block|,
name|_NET_WM_WINDOW_TYPE_TOOLBAR
block|,
name|_NET_WM_WINDOW_TYPE_MENU
block|,
name|_NET_WM_WINDOW_TYPE_UTILITY
block|,
name|_NET_WM_WINDOW_TYPE_SPLASH
block|,
name|_NET_WM_WINDOW_TYPE_DIALOG
block|,
name|_NET_WM_WINDOW_TYPE_DROPDOWN_MENU
block|,
name|_NET_WM_WINDOW_TYPE_POPUP_MENU
block|,
name|_NET_WM_WINDOW_TYPE_TOOLTIP
block|,
name|_NET_WM_WINDOW_TYPE_NOTIFICATION
block|,
name|_NET_WM_WINDOW_TYPE_COMBO
block|,
name|_NET_WM_WINDOW_TYPE_DND
block|,
name|_NET_WM_WINDOW_TYPE_NORMAL
block|,
name|_KDE_NET_WM_WINDOW_TYPE_OVERRIDE
block|,
name|_KDE_NET_WM_FRAME_STRUT
block|,
name|_NET_STARTUP_INFO
block|,
name|_NET_STARTUP_INFO_BEGIN
block|,
name|_NET_SUPPORTING_WM_CHECK
block|,
name|_NET_WM_CM_S0
block|,
name|_NET_SYSTEM_TRAY_VISUAL
block|,
name|_NET_ACTIVE_WINDOW
block|,
comment|// Property formats
name|TEXT
block|,
name|UTF8_STRING
block|,
comment|// Xdnd
name|XdndEnter
block|,
name|XdndPosition
block|,
name|XdndStatus
block|,
name|XdndLeave
block|,
name|XdndDrop
block|,
name|XdndFinished
block|,
name|XdndTypelist
block|,
name|XdndActionList
block|,
name|XdndSelection
block|,
name|XdndAware
block|,
name|XdndProxy
block|,
name|XdndActionCopy
block|,
name|XdndActionLink
block|,
name|XdndActionMove
block|,
name|XdndActionPrivate
block|,
comment|// Motif DND
name|_MOTIF_DRAG_AND_DROP_MESSAGE
block|,
name|_MOTIF_DRAG_INITIATOR_INFO
block|,
name|_MOTIF_DRAG_RECEIVER_INFO
block|,
name|_MOTIF_DRAG_WINDOW
block|,
name|_MOTIF_DRAG_TARGETS
block|,
name|XmTRANSFER_SUCCESS
block|,
name|XmTRANSFER_FAILURE
block|,
comment|// Xkb
name|_XKB_RULES_NAMES
block|,
comment|// XEMBED
name|_XEMBED
block|,
name|_XEMBED_INFO
block|,
name|XWacomStylus
block|,
name|XWacomCursor
block|,
name|XWacomEraser
block|,
name|XTabletStylus
block|,
name|XTabletEraser
block|,
name|NPredefinedAtoms
block|,
name|_QT_SETTINGS_TIMESTAMP
init|=
name|NPredefinedAtoms
block|,
name|NAtoms
block|}
enum|;
block|}
end_decl_stmt
begin_decl_stmt
name|class
name|QXcbConnection
range|:
name|public
name|QObject
block|{
name|Q_OBJECT
name|public
operator|:
name|QXcbConnection
argument_list|(
specifier|const
name|char
operator|*
name|displayName
operator|=
literal|0
argument_list|)
block|;
operator|~
name|QXcbConnection
argument_list|()
block|;
name|QXcbConnection
operator|*
name|connection
argument_list|()
specifier|const
block|{
return|return
name|const_cast
operator|<
name|QXcbConnection
operator|*
operator|>
operator|(
name|this
operator|)
return|;
block|}
specifier|const
name|QList
operator|<
name|QXcbScreen
operator|*
operator|>
operator|&
name|screens
argument_list|()
specifier|const
block|{
return|return
name|m_screens
return|;
block|}
name|int
name|primaryScreen
argument_list|()
specifier|const
block|{
return|return
name|m_primaryScreen
return|;
block|}
name|xcb_atom_t
name|atom
argument_list|(
argument|QXcbAtom::Atom atom
argument_list|)
block|;
name|xcb_atom_t
name|internAtom
argument_list|(
specifier|const
name|char
operator|*
name|name
argument_list|)
block|;
name|QByteArray
name|atomName
argument_list|(
argument|xcb_atom_t atom
argument_list|)
block|;
specifier|const
name|char
operator|*
name|displayName
argument_list|()
specifier|const
block|{
return|return
name|m_displayName
operator|.
name|constData
argument_list|()
return|;
block|}
name|xcb_connection_t
operator|*
name|xcb_connection
argument_list|()
specifier|const
block|{
return|return
name|m_connection
return|;
block|}
specifier|const
name|xcb_setup_t
operator|*
name|setup
argument_list|()
specifier|const
block|{
return|return
name|m_setup
return|;
block|}
specifier|const
name|xcb_format_t
operator|*
name|formatForDepth
argument_list|(
argument|uint8_t depth
argument_list|)
specifier|const
block|;
name|QXcbKeyboard
operator|*
name|keyboard
argument_list|()
specifier|const
block|{
return|return
name|m_keyboard
return|;
block|}
name|QXcbClipboard
operator|*
name|clipboard
argument_list|()
specifier|const
block|{
return|return
name|m_clipboard
return|;
block|}
name|QXcbDrag
operator|*
name|drag
argument_list|()
specifier|const
block|{
return|return
name|m_drag
return|;
block|}
ifdef|#
directive|ifdef
name|XCB_USE_XLIB
name|void
operator|*
name|xlib_display
argument_list|()
specifier|const
block|{
return|return
name|m_xlib_display
return|;
block|}
endif|#
directive|endif
ifdef|#
directive|ifdef
name|XCB_USE_DRI2
name|bool
name|hasSupportForDri2
argument_list|()
specifier|const
block|;
name|QByteArray
name|dri2DeviceName
argument_list|()
specifier|const
block|{
return|return
name|m_dri2_device_name
return|;
block|}
endif|#
directive|endif
ifdef|#
directive|ifdef
name|XCB_USE_EGL
name|bool
name|hasEgl
argument_list|()
specifier|const
block|;
endif|#
directive|endif
if|#
directive|if
name|defined
argument_list|(
name|XCB_USE_EGL
argument_list|)
operator|||
name|defined
argument_list|(
name|XCB_USE_DRI2
argument_list|)
name|void
operator|*
name|egl_display
argument_list|()
specifier|const
block|{
return|return
name|m_egl_display
return|;
block|}
endif|#
directive|endif
name|void
name|sync
argument_list|()
block|;
name|void
name|flush
argument_list|()
block|{
name|xcb_flush
argument_list|(
name|m_connection
argument_list|)
block|; }
name|void
name|handleXcbError
argument_list|(
name|xcb_generic_error_t
operator|*
name|error
argument_list|)
block|;
name|void
name|handleXcbEvent
argument_list|(
name|xcb_generic_event_t
operator|*
name|event
argument_list|)
block|;
name|void
name|addWindow
argument_list|(
argument|xcb_window_t id
argument_list|,
argument|QXcbWindow *window
argument_list|)
block|;
name|void
name|removeWindow
argument_list|(
argument|xcb_window_t id
argument_list|)
block|;
name|QXcbWindow
operator|*
name|platformWindowFromId
argument_list|(
argument|xcb_window_t id
argument_list|)
block|;
name|xcb_generic_event_t
operator|*
name|checkEvent
argument_list|(
argument|int type
argument_list|)
block|;
name|template
operator|<
name|typename
name|T
operator|>
specifier|inline
name|xcb_generic_event_t
operator|*
name|checkEvent
argument_list|(
specifier|const
name|T
operator|&
name|checker
argument_list|)
block|;
name|QXcbWindow
operator|*
name|platformWindowFromId
argument_list|(
argument|xcb_window_t id
argument_list|)
block|;
typedef|typedef
name|bool
function_decl|(
modifier|*
name|PeekFunc
function_decl|)
parameter_list|(
name|xcb_generic_event_t
modifier|*
parameter_list|)
function_decl|;
name|void
name|addPeekFunc
argument_list|(
argument|PeekFunc f
argument_list|)
decl_stmt|;
end_decl_stmt
begin_expr_stmt
specifier|inline
name|xcb_timestamp_t
name|time
argument_list|()
specifier|const
block|{
return|return
name|m_time
return|;
block|}
end_expr_stmt
begin_function
specifier|inline
name|void
name|setTime
parameter_list|(
name|xcb_timestamp_t
name|t
parameter_list|)
block|{
if|if
condition|(
name|t
operator|>
name|m_time
condition|)
name|m_time
operator|=
name|t
expr_stmt|;
block|}
end_function
begin_decl_stmt
name|private
name|slots
range|:
name|void
name|processXcbEvents
argument_list|()
decl_stmt|;
end_decl_stmt
begin_label
name|private
label|:
end_label
begin_function_decl
name|void
name|initializeAllAtoms
parameter_list|()
function_decl|;
end_function_decl
begin_decl_stmt
name|void
name|sendConnectionEvent
argument_list|(
name|QXcbAtom
operator|::
name|Atom
name|atom
argument_list|,
name|uint
name|id
operator|=
literal|0
argument_list|)
decl_stmt|;
end_decl_stmt
begin_ifdef
ifdef|#
directive|ifdef
name|XCB_USE_DRI2
end_ifdef
begin_function_decl
name|void
name|initializeDri2
parameter_list|()
function_decl|;
end_function_decl
begin_endif
endif|#
directive|endif
end_endif
begin_function_decl
name|void
name|handleClientMessageEvent
parameter_list|(
specifier|const
name|xcb_client_message_event_t
modifier|*
name|event
parameter_list|)
function_decl|;
end_function_decl
begin_decl_stmt
name|xcb_connection_t
modifier|*
name|m_connection
decl_stmt|;
end_decl_stmt
begin_decl_stmt
specifier|const
name|xcb_setup_t
modifier|*
name|m_setup
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|QList
operator|<
name|QXcbScreen
operator|*
operator|>
name|m_screens
expr_stmt|;
end_expr_stmt
begin_decl_stmt
name|int
name|m_primaryScreen
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|xcb_atom_t
name|m_allAtoms
index|[
name|QXcbAtom
operator|::
name|NAtoms
index|]
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|xcb_timestamp_t
name|m_time
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QByteArray
name|m_displayName
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QXcbKeyboard
modifier|*
name|m_keyboard
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QXcbClipboard
modifier|*
name|m_clipboard
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QXcbDrag
modifier|*
name|m_drag
decl_stmt|;
end_decl_stmt
begin_if
if|#
directive|if
name|defined
argument_list|(
name|XCB_USE_XLIB
argument_list|)
end_if
begin_decl_stmt
name|void
modifier|*
name|m_xlib_display
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_ifdef
ifdef|#
directive|ifdef
name|XCB_USE_DRI2
end_ifdef
begin_decl_stmt
name|uint32_t
name|m_dri2_major
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|uint32_t
name|m_dri2_minor
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|bool
name|m_dri2_support_probed
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|bool
name|m_has_support_for_dri2
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QByteArray
name|m_dri2_device_name
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_if
if|#
directive|if
name|defined
argument_list|(
name|XCB_USE_EGL
argument_list|)
operator|||
name|defined
argument_list|(
name|XCB_USE_DRI2
argument_list|)
end_if
begin_decl_stmt
name|void
modifier|*
name|m_egl_display
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|bool
name|m_has_egl
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_ifdef
ifdef|#
directive|ifdef
name|Q_XCB_DEBUG
end_ifdef
begin_struct
struct|struct
name|CallInfo
block|{
name|int
name|sequence
decl_stmt|;
name|QByteArray
name|file
decl_stmt|;
name|int
name|line
decl_stmt|;
block|}
struct|;
end_struct
begin_expr_stmt
name|QVector
operator|<
name|CallInfo
operator|>
name|m_callLog
expr_stmt|;
end_expr_stmt
begin_function_decl
name|void
name|log
parameter_list|(
specifier|const
name|char
modifier|*
name|file
parameter_list|,
name|int
name|line
parameter_list|,
name|int
name|sequence
parameter_list|)
function_decl|;
end_function_decl
begin_expr_stmt
name|template
operator|<
name|typename
name|cookie_t
operator|>
name|friend
name|cookie_t
name|q_xcb_call_template
argument_list|(
argument|const cookie_t&cookie
argument_list|,
argument|QXcbConnection *connection
argument_list|,
argument|const char *file
argument_list|,
argument|int line
argument_list|)
expr_stmt|;
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_expr_stmt
name|QVector
operator|<
name|xcb_generic_event_t
operator|*
operator|>
name|eventqueue
expr_stmt|;
end_expr_stmt
begin_decl_stmt
name|WindowMapper
name|m_mapper
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|QVector
operator|<
name|PeekFunc
operator|>
name|m_peekFuncs
expr_stmt|;
end_expr_stmt
begin_define
DECL|macro|DISPLAY_FROM_XCB
unit|};
define|#
directive|define
name|DISPLAY_FROM_XCB
parameter_list|(
name|object
parameter_list|)
value|((Display *)(object->connection()->xlib_display()))
end_define
begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
DECL|function|checkEvent
name|xcb_generic_event_t
operator|*
name|QXcbConnection
operator|::
name|checkEvent
argument_list|(
argument|const T&checker
argument_list|)
block|{
while|while
condition|(
name|xcb_generic_event_t
modifier|*
name|event
init|=
name|xcb_poll_for_event
argument_list|(
name|xcb_connection
argument_list|()
argument_list|)
condition|)
name|eventqueue
operator|.
name|append
argument_list|(
name|event
argument_list|)
expr_stmt|;
end_expr_stmt
begin_for
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|eventqueue
operator|.
name|size
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
name|xcb_generic_event_t
modifier|*
name|event
init|=
name|eventqueue
operator|.
name|at
argument_list|(
name|i
argument_list|)
decl_stmt|;
if|if
condition|(
name|checker
operator|.
name|check
argument_list|(
name|event
argument_list|)
condition|)
block|{
name|eventqueue
index|[
name|i
index|]
operator|=
literal|0
expr_stmt|;
return|return
name|event
return|;
block|}
block|}
end_for
begin_return
return|return
literal|0
return|;
end_return
begin_ifdef
unit|}
ifdef|#
directive|ifdef
name|Q_XCB_DEBUG
end_ifdef
begin_expr_stmt
unit|template
operator|<
name|typename
name|cookie_t
operator|>
DECL|function|q_xcb_call_template
name|cookie_t
name|q_xcb_call_template
argument_list|(
argument|const cookie_t&cookie
argument_list|,
argument|QXcbConnection *connection
argument_list|,
argument|const char *file
argument_list|,
argument|int line
argument_list|)
block|{
name|connection
operator|->
name|log
argument_list|(
name|file
argument_list|,
name|line
argument_list|,
name|cookie
operator|.
name|sequence
argument_list|)
block|;
return|return
name|cookie
return|;
block|}
end_expr_stmt
begin_define
DECL|macro|Q_XCB_CALL
define|#
directive|define
name|Q_XCB_CALL
parameter_list|(
name|x
parameter_list|)
value|q_xcb_call_template(x, connection(), __FILE__, __LINE__)
end_define
begin_define
DECL|macro|Q_XCB_CALL2
define|#
directive|define
name|Q_XCB_CALL2
parameter_list|(
name|x
parameter_list|,
name|connection
parameter_list|)
value|q_xcb_call_template(x, connection, __FILE__, __LINE__)
end_define
begin_define
DECL|macro|Q_XCB_NOOP
define|#
directive|define
name|Q_XCB_NOOP
parameter_list|(
name|c
parameter_list|)
value|q_xcb_call_template(xcb_no_operation(c->xcb_connection()), c, __FILE__, __LINE__);
end_define
begin_else
else|#
directive|else
end_else
begin_define
DECL|macro|Q_XCB_CALL
define|#
directive|define
name|Q_XCB_CALL
parameter_list|(
name|x
parameter_list|)
value|x
end_define
begin_define
DECL|macro|Q_XCB_CALL2
define|#
directive|define
name|Q_XCB_CALL2
parameter_list|(
name|x
parameter_list|,
name|connection
parameter_list|)
value|x
end_define
begin_define
DECL|macro|Q_XCB_NOOP
define|#
directive|define
name|Q_XCB_NOOP
parameter_list|(
name|c
parameter_list|)
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_if
if|#
directive|if
name|defined
argument_list|(
name|XCB_USE_DRI2
argument_list|)
operator|||
name|defined
argument_list|(
name|XCB_USE_EGL
argument_list|)
end_if
begin_define
DECL|macro|EGL_DISPLAY_FROM_XCB
define|#
directive|define
name|EGL_DISPLAY_FROM_XCB
parameter_list|(
name|object
parameter_list|)
value|((EGLDisplay)(object->connection()->egl_display()))
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|//endifXCB_USE_DRI2
end_comment
begin_endif
endif|#
directive|endif
end_endif
end_unit
