begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2014 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia. For licensing terms and ** conditions see http://qt.digia.com/licensing. For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights. These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QEGLFSX11INTEGRATION_H
end_ifndef
begin_define
DECL|macro|QEGLFSX11INTEGRATION_H
define|#
directive|define
name|QEGLFSX11INTEGRATION_H
end_define
begin_include
include|#
directive|include
file|"qeglfsdeviceintegration.h"
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
file|<xcb/xcb.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
name|namespace
name|Atoms
block|{
enum|enum
block|{
name|_NET_WM_NAME
init|=
literal|0
block|,
name|UTF8_STRING
block|,
name|WM_PROTOCOLS
block|,
name|WM_DELETE_WINDOW
block|,
name|_NET_WM_STATE
block|,
name|_NET_WM_STATE_FULLSCREEN
block|,
name|N_ATOMS
block|}
enum|;
block|}
end_decl_stmt
begin_decl_stmt
DECL|variable|EventReader
name|class
name|EventReader
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QEglFSX11Integration
range|:
name|public
name|QEGLDeviceIntegration
block|{
name|public
operator|:
name|QEglFSX11Integration
argument_list|()
operator|:
name|m_connection
argument_list|(
literal|0
argument_list|)
block|,
name|m_window
argument_list|(
literal|0
argument_list|)
block|,
name|m_eventReader
argument_list|(
literal|0
argument_list|)
block|{}
name|void
name|platformInit
argument_list|()
name|Q_DECL_OVERRIDE
block|;
name|void
name|platformDestroy
argument_list|()
name|Q_DECL_OVERRIDE
block|;
name|EGLNativeDisplayType
name|platformDisplay
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|QSize
name|screenSize
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|EGLNativeWindowType
name|createNativeWindow
argument_list|(
argument|QPlatformWindow *window
argument_list|,
argument|const QSize&size
argument_list|,
argument|const QSurfaceFormat&format
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|void
name|destroyNativeWindow
argument_list|(
argument|EGLNativeWindowType window
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|bool
name|hasCapability
argument_list|(
argument|QPlatformIntegration::Capability cap
argument_list|)
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|xcb_connection_t
operator|*
name|connection
argument_list|()
block|{
return|return
name|m_connection
return|;
block|}
specifier|const
name|xcb_atom_t
operator|*
name|atoms
argument_list|()
specifier|const
block|{
return|return
name|m_atoms
return|;
block|}
name|QPlatformWindow
operator|*
name|platformWindow
argument_list|()
block|{
return|return
name|m_platformWindow
return|;
block|}
name|private
operator|:
name|void
name|sendConnectionEvent
argument_list|(
argument|xcb_atom_t a
argument_list|)
block|;
name|void
operator|*
name|m_display
block|;
name|xcb_connection_t
operator|*
name|m_connection
block|;
name|xcb_atom_t
name|m_atoms
index|[
name|Atoms
operator|::
name|N_ATOMS
index|]
block|;
name|xcb_window_t
name|m_window
block|;
name|EventReader
operator|*
name|m_eventReader
block|;
name|xcb_window_t
name|m_connectionEventListener
block|;
name|QPlatformWindow
operator|*
name|m_platformWindow
block|;
name|mutable
name|QSize
name|m_screenSize
block|; }
decl_stmt|;
end_decl_stmt
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
end_unit
