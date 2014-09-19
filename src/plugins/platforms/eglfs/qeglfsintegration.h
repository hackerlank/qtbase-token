begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2014 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia. For licensing terms and ** conditions see http://qt.digia.com/licensing. For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights. These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QEGLFSINTEGRATION_H
end_ifndef
begin_define
DECL|macro|QEGLFSINTEGRATION_H
define|#
directive|define
name|QEGLFSINTEGRATION_H
end_define
begin_include
include|#
directive|include
file|<QtPlatformSupport/private/qeglplatformintegration_p.h>
end_include
begin_include
include|#
directive|include
file|<qpa/qplatformscreen.h>
end_include
begin_include
include|#
directive|include
file|<EGL/egl.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
name|class
name|QEglFSIntegration
range|:
name|public
name|QEGLPlatformIntegration
block|{
name|public
operator|:
name|QEglFSIntegration
argument_list|()
block|;
name|void
name|initialize
argument_list|()
name|Q_DECL_OVERRIDE
block|;
name|void
name|destroy
argument_list|()
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
name|QVariant
name|styleHint
argument_list|(
argument|QPlatformIntegration::StyleHint hint
argument_list|)
specifier|const
name|Q_DECL_OVERRIDE
block|;
specifier|static
name|EGLConfig
name|chooseConfig
argument_list|(
argument|EGLDisplay display
argument_list|,
argument|const QSurfaceFormat&format
argument_list|)
block|;
name|protected
operator|:
name|QEGLPlatformScreen
operator|*
name|createScreen
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|QEGLPlatformWindow
operator|*
name|createWindow
argument_list|(
argument|QWindow *window
argument_list|)
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|QEGLPlatformContext
operator|*
name|createContext
argument_list|(
argument|const QSurfaceFormat&format
argument_list|,
argument|QPlatformOpenGLContext *shareContext
argument_list|,
argument|EGLDisplay display
argument_list|,
argument|QVariant *nativeHandle
argument_list|)
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|QPlatformOffscreenSurface
operator|*
name|createOffscreenSurface
argument_list|(
argument|EGLDisplay display
argument_list|,
argument|const QSurfaceFormat&format
argument_list|,
argument|QOffscreenSurface *surface
argument_list|)
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|EGLNativeDisplayType
name|nativeDisplay
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|private
operator|:
name|bool
name|mDisableInputHandlers
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
comment|// QEGLFSINTEGRATION_H
end_comment
end_unit
