begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QXCBSYSTEMTRAYTRACKER_H
end_ifndef
begin_define
DECL|macro|QXCBSYSTEMTRAYTRACKER_H
define|#
directive|define
name|QXCBSYSTEMTRAYTRACKER_H
end_define
begin_include
include|#
directive|include
file|"qxcbconnection.h"
end_include
begin_include
include|#
directive|include
file|<xcb/xcb.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QXcbConnection
name|class
name|QXcbConnection
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QScreen
name|class
name|QScreen
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QObject
name|class
name|QXcbSystemTrayTracker
range|:
name|public
name|QObject
decl_stmt|,
name|public
name|QXcbWindowEventListener
block|{
name|Q_OBJECT
name|public
range|:
specifier|static
name|QXcbSystemTrayTracker
operator|*
name|create
argument_list|(
name|QXcbConnection
operator|*
name|connection
argument_list|)
decl_stmt|;
name|xcb_window_t
name|trayWindow
parameter_list|()
function_decl|;
name|void
name|requestSystemTrayWindowDock
argument_list|(
name|xcb_window_t
name|window
argument_list|)
decl|const
decl_stmt|;
name|QRect
name|systemTrayWindowGlobalGeometry
argument_list|(
name|xcb_window_t
name|window
argument_list|)
decl|const
decl_stmt|;
name|void
name|notifyManagerClientMessageEvent
parameter_list|(
specifier|const
name|xcb_client_message_event_t
modifier|*
parameter_list|)
function_decl|;
name|void
name|handleDestroyNotifyEvent
argument_list|(
specifier|const
name|xcb_destroy_notify_event_t
operator|*
argument_list|)
name|Q_DECL_OVERRIDE
decl_stmt|;
name|bool
name|visualHasAlphaChannel
parameter_list|()
function_decl|;
name|signals
label|:
name|void
name|systemTrayWindowChanged
parameter_list|(
name|QScreen
modifier|*
name|screen
parameter_list|)
function_decl|;
name|private
label|:
name|explicit
name|QXcbSystemTrayTracker
parameter_list|(
name|QXcbConnection
modifier|*
name|connection
parameter_list|,
name|xcb_atom_t
name|trayAtom
parameter_list|,
name|xcb_atom_t
name|selection
parameter_list|)
function_decl|;
specifier|static
name|xcb_window_t
name|locateTrayWindow
parameter_list|(
specifier|const
name|QXcbConnection
modifier|*
name|connection
parameter_list|,
name|xcb_atom_t
name|selection
parameter_list|)
function_decl|;
name|void
name|emitSystemTrayWindowChanged
parameter_list|()
function_decl|;
specifier|const
name|xcb_atom_t
name|m_selection
decl_stmt|;
specifier|const
name|xcb_atom_t
name|m_trayAtom
decl_stmt|;
name|QXcbConnection
modifier|*
name|m_connection
decl_stmt|;
name|xcb_window_t
name|m_trayWindow
decl_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QXCBSYSTEMTRAYTRACKER_H
end_comment
end_unit
