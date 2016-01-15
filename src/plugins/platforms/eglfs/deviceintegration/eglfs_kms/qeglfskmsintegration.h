begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 Pier Luigi Fiorini<pierluigi.fiorini@gmail.com> ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QEGLFSKMSINTEGRATION_H
end_ifndef
begin_define
DECL|macro|QEGLFSKMSINTEGRATION_H
define|#
directive|define
name|QEGLFSKMSINTEGRATION_H
end_define
begin_include
include|#
directive|include
file|"qeglfsdeviceintegration.h"
end_include
begin_include
include|#
directive|include
file|<QtCore/QMap>
end_include
begin_include
include|#
directive|include
file|<QtCore/QVariant>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QEglFSKmsDevice
name|class
name|QEglFSKmsDevice
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QEglFSKmsIntegration
range|:
name|public
name|QEGLDeviceIntegration
block|{
name|public
operator|:
name|QEglFSKmsIntegration
argument_list|()
block|;
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
name|bool
name|usesDefaultScreen
argument_list|()
name|Q_DECL_OVERRIDE
block|;
name|void
name|screenInit
argument_list|()
name|Q_DECL_OVERRIDE
block|;
name|QSurfaceFormat
name|surfaceFormatFor
argument_list|(
argument|const QSurfaceFormat&inputFormat
argument_list|)
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|EGLNativeWindowType
name|createNativeWindow
argument_list|(
argument|QPlatformWindow *platformWindow
argument_list|,
argument|const QSize&size
argument_list|,
argument|const QSurfaceFormat&format
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|EGLNativeWindowType
name|createNativeOffscreenWindow
argument_list|(
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
name|QPlatformCursor
operator|*
name|createCursor
argument_list|(
argument|QPlatformScreen *screen
argument_list|)
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|void
name|waitForVSync
argument_list|(
argument|QPlatformSurface *surface
argument_list|)
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|void
name|presentBuffer
argument_list|(
argument|QPlatformSurface *surface
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|bool
name|supportsPBuffers
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|bool
name|hwCursor
argument_list|()
specifier|const
block|;
name|bool
name|separateScreens
argument_list|()
specifier|const
block|;
name|QMap
operator|<
name|QString
block|,
name|QVariantMap
operator|>
name|outputSettings
argument_list|()
specifier|const
block|;
name|private
operator|:
name|void
name|loadConfig
argument_list|()
block|;
name|QEglFSKmsDevice
operator|*
name|m_device
block|;
name|bool
name|m_hwCursor
block|;
name|bool
name|m_pbuffers
block|;
name|bool
name|m_separateScreens
block|;
name|QString
name|m_devicePath
block|;
name|QMap
operator|<
name|QString
block|,
name|QVariantMap
operator|>
name|m_outputSettings
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
