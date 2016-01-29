begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QEGLPLATFORMCONTEXT_H
end_ifndef
begin_define
DECL|macro|QEGLPLATFORMCONTEXT_H
define|#
directive|define
name|QEGLPLATFORMCONTEXT_H
end_define
begin_comment
comment|//
end_comment
begin_comment
comment|//  W A R N I N G
end_comment
begin_comment
comment|//  -------------
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|// This file is not part of the Qt API.  It exists purely as an
end_comment
begin_comment
comment|// implementation detail.  This header file may change from version to
end_comment
begin_comment
comment|// version without notice, or even be removed.
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|// We mean it.
end_comment
begin_comment
comment|//
end_comment
begin_include
include|#
directive|include
file|<QtCore/qtextstream.h>
end_include
begin_include
include|#
directive|include
file|<qpa/qplatformwindow.h>
end_include
begin_include
include|#
directive|include
file|<qpa/qplatformopenglcontext.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/QVariant>
end_include
begin_include
include|#
directive|include
file|<EGL/egl.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
name|class
name|QEGLPlatformContext
range|:
name|public
name|QPlatformOpenGLContext
block|{
name|public
operator|:
expr|enum
name|Flag
block|{
name|NoSurfaceless
operator|=
literal|0x01
block|}
block|;
name|Q_DECLARE_FLAGS
argument_list|(
argument|Flags
argument_list|,
argument|Flag
argument_list|)
name|QEGLPlatformContext
argument_list|(
argument|const QSurfaceFormat&format
argument_list|,
argument|QPlatformOpenGLContext *share
argument_list|,
argument|EGLDisplay display
argument_list|,
argument|EGLConfig *config =
literal|0
argument_list|,
argument|const QVariant&nativeHandle = QVariant()
argument_list|,
argument|Flags flags =
literal|0
argument_list|)
block|;
operator|~
name|QEGLPlatformContext
argument_list|()
block|;
name|void
name|initialize
argument_list|()
name|Q_DECL_OVERRIDE
block|;
name|bool
name|makeCurrent
argument_list|(
argument|QPlatformSurface *surface
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|void
name|doneCurrent
argument_list|()
name|Q_DECL_OVERRIDE
block|;
name|void
name|swapBuffers
argument_list|(
argument|QPlatformSurface *surface
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|QFunctionPointer
name|getProcAddress
argument_list|(
argument|const char *procName
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|QSurfaceFormat
name|format
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|bool
name|isSharing
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|{
return|return
name|m_shareContext
operator|!=
name|EGL_NO_CONTEXT
return|;
block|}
name|bool
name|isValid
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|{
return|return
name|m_eglContext
operator|!=
name|EGL_NO_CONTEXT
return|;
block|}
name|EGLContext
name|eglContext
argument_list|()
specifier|const
block|;
name|EGLDisplay
name|eglDisplay
argument_list|()
specifier|const
block|;
name|EGLConfig
name|eglConfig
argument_list|()
specifier|const
block|;
name|protected
operator|:
name|virtual
name|EGLSurface
name|eglSurfaceForPlatformSurface
argument_list|(
name|QPlatformSurface
operator|*
name|surface
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|EGLSurface
name|createTemporaryOffscreenSurface
argument_list|()
block|;
name|virtual
name|void
name|destroyTemporaryOffscreenSurface
argument_list|(
argument|EGLSurface surface
argument_list|)
block|;
name|virtual
name|void
name|runGLChecks
argument_list|()
block|;
name|private
operator|:
name|void
name|init
argument_list|(
specifier|const
name|QSurfaceFormat
operator|&
name|format
argument_list|,
name|QPlatformOpenGLContext
operator|*
name|share
argument_list|)
block|;
name|void
name|adopt
argument_list|(
specifier|const
name|QVariant
operator|&
name|nativeHandle
argument_list|,
name|QPlatformOpenGLContext
operator|*
name|share
argument_list|)
block|;
name|void
name|updateFormatFromGL
argument_list|()
block|;
name|EGLContext
name|m_eglContext
block|;
name|EGLContext
name|m_shareContext
block|;
name|EGLDisplay
name|m_eglDisplay
block|;
name|EGLConfig
name|m_eglConfig
block|;
name|QSurfaceFormat
name|m_format
block|;
name|EGLenum
name|m_api
block|;
name|int
name|m_swapInterval
block|;
name|bool
name|m_swapIntervalEnvChecked
block|;
name|int
name|m_swapIntervalFromEnv
block|;
name|Flags
name|m_flags
block|;
name|bool
name|m_ownsContext
block|;
name|QVector
operator|<
name|EGLint
operator|>
name|m_contextAttrs
block|; }
decl_stmt|;
end_decl_stmt
begin_macro
name|Q_DECLARE_OPERATORS_FOR_FLAGS
argument_list|(
argument|QEGLPlatformContext::Flags
argument_list|)
end_macro
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|//QEGLPLATFORMCONTEXT_H
end_comment
end_unit
