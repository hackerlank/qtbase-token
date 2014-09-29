begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2014 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia. For licensing terms and ** conditions see http://qt.digia.com/licensing. For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights. These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QXCBNATIVEINTERFACE_H
end_ifndef
begin_define
DECL|macro|QXCBNATIVEINTERFACE_H
define|#
directive|define
name|QXCBNATIVEINTERFACE_H
end_define
begin_include
include|#
directive|include
file|<qpa/qplatformnativeinterface.h>
end_include
begin_include
include|#
directive|include
file|<xcb/xcb.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/QRect>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QWidget
name|class
name|QWidget
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QXcbScreen
name|class
name|QXcbScreen
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QXcbConnection
name|class
name|QXcbConnection
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QXcbNativeInterface
range|:
name|public
name|QPlatformNativeInterface
block|{
name|Q_OBJECT
name|public
operator|:
expr|enum
name|ResourceType
block|{
name|Display
block|,
name|EglDisplay
block|,
name|Connection
block|,
name|Screen
block|,
name|EglContext
block|,
name|EglConfig
block|,
name|GLXConfig
block|,
name|GLXContext
block|,
name|AppTime
block|,
name|AppUserTime
block|,
name|ScreenHintStyle
block|,
name|StartupId
block|,
name|TrayWindow
block|,
name|GetTimestamp
block|,
name|X11Screen
block|,
name|RootWindow
block|,
name|ScreenSubpixelType
block|,
name|ScreenAntialiasingEnabled
block|}
block|;
name|QXcbNativeInterface
argument_list|()
block|;
name|void
operator|*
name|nativeResourceForIntegration
argument_list|(
argument|const QByteArray&resource
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|void
operator|*
name|nativeResourceForContext
argument_list|(
argument|const QByteArray&resourceString
argument_list|,
argument|QOpenGLContext *context
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|void
operator|*
name|nativeResourceForScreen
argument_list|(
argument|const QByteArray&resource
argument_list|,
argument|QScreen *screen
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|void
operator|*
name|nativeResourceForWindow
argument_list|(
argument|const QByteArray&resourceString
argument_list|,
argument|QWindow *window
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|NativeResourceForIntegrationFunction
name|nativeResourceFunctionForIntegration
argument_list|(
argument|const QByteArray&resource
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|NativeResourceForContextFunction
name|nativeResourceFunctionForContext
argument_list|(
argument|const QByteArray&resource
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|NativeResourceForScreenFunction
name|nativeResourceFunctionForScreen
argument_list|(
argument|const QByteArray&resource
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|QFunctionPointer
name|platformFunction
argument_list|(
argument|const QByteArray&function
argument_list|)
specifier|const
name|Q_DECL_OVERRIDE
block|;
specifier|inline
specifier|const
name|QByteArray
operator|&
name|genericEventFilterType
argument_list|()
specifier|const
block|{
return|return
name|m_genericEventFilterType
return|;
block|}
name|void
operator|*
name|displayForWindow
argument_list|(
name|QWindow
operator|*
name|window
argument_list|)
block|;
name|void
operator|*
name|eglDisplayForWindow
argument_list|(
name|QWindow
operator|*
name|window
argument_list|)
block|;
name|void
operator|*
name|connectionForWindow
argument_list|(
name|QWindow
operator|*
name|window
argument_list|)
block|;
name|void
operator|*
name|screenForWindow
argument_list|(
name|QWindow
operator|*
name|window
argument_list|)
block|;
name|void
operator|*
name|appTime
argument_list|(
specifier|const
name|QXcbScreen
operator|*
name|screen
argument_list|)
block|;
name|void
operator|*
name|appUserTime
argument_list|(
specifier|const
name|QXcbScreen
operator|*
name|screen
argument_list|)
block|;
name|void
operator|*
name|getTimestamp
argument_list|(
specifier|const
name|QXcbScreen
operator|*
name|screen
argument_list|)
block|;
name|void
operator|*
name|startupId
argument_list|()
block|;
name|void
operator|*
name|x11Screen
argument_list|()
block|;
name|void
operator|*
name|rootWindow
argument_list|()
block|;
specifier|static
name|void
name|setStartupId
argument_list|(
specifier|const
name|char
operator|*
argument_list|)
block|;
specifier|static
name|void
name|setAppTime
argument_list|(
argument|QScreen *screen
argument_list|,
argument|xcb_timestamp_t time
argument_list|)
block|;
specifier|static
name|void
name|setAppUserTime
argument_list|(
argument|QScreen *screen
argument_list|,
argument|xcb_timestamp_t time
argument_list|)
block|;
specifier|static
name|void
operator|*
name|eglContextForContext
argument_list|(
name|QOpenGLContext
operator|*
name|context
argument_list|)
block|;
specifier|static
name|void
operator|*
name|eglConfigForContext
argument_list|(
name|QOpenGLContext
operator|*
name|context
argument_list|)
block|;
specifier|static
name|void
operator|*
name|glxContextForContext
argument_list|(
name|QOpenGLContext
operator|*
name|context
argument_list|)
block|;
specifier|static
name|void
operator|*
name|glxConfigForContext
argument_list|(
name|QOpenGLContext
operator|*
name|context
argument_list|)
block|;
name|Q_INVOKABLE
name|void
name|beep
argument_list|()
block|;
name|Q_INVOKABLE
name|bool
name|systemTrayAvailable
argument_list|(
argument|const QScreen *screen
argument_list|)
specifier|const
block|;
name|Q_INVOKABLE
name|void
name|clearRegion
argument_list|(
specifier|const
name|QWindow
operator|*
name|qwindow
argument_list|,
specifier|const
name|QRect
operator|&
name|rect
argument_list|)
block|;
name|Q_INVOKABLE
name|bool
name|systrayVisualHasAlphaChannel
argument_list|()
block|;
name|Q_INVOKABLE
name|bool
name|requestSystemTrayWindowDock
argument_list|(
specifier|const
name|QWindow
operator|*
name|window
argument_list|)
block|;
name|Q_INVOKABLE
name|QRect
name|systemTrayWindowGlobalGeometry
argument_list|(
specifier|const
name|QWindow
operator|*
name|window
argument_list|)
block|;
name|signals
operator|:
name|void
name|systemTrayWindowChanged
argument_list|(
name|QScreen
operator|*
name|screen
argument_list|)
block|;
name|private
operator|:
name|xcb_window_t
name|locateSystemTray
argument_list|(
name|xcb_connection_t
operator|*
name|conn
argument_list|,
specifier|const
name|QXcbScreen
operator|*
name|screen
argument_list|)
block|;
specifier|const
name|QByteArray
name|m_genericEventFilterType
block|;
name|xcb_atom_t
name|m_sysTraySelectionAtom
block|;
name|xcb_visualid_t
name|m_systrayVisualId
block|;
specifier|static
name|QXcbScreen
operator|*
name|qPlatformScreenForWindow
argument_list|(
name|QWindow
operator|*
name|window
argument_list|)
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
begin_comment
comment|// QXCBNATIVEINTERFACE_H
end_comment
end_unit
