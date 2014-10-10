begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2014 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia. For licensing terms and ** conditions see http://qt.digia.com/licensing. For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights. These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qeglfscontext.h"
end_include
begin_include
include|#
directive|include
file|"qeglfswindow.h"
end_include
begin_include
include|#
directive|include
file|"qeglfshooks.h"
end_include
begin_include
include|#
directive|include
file|<QtPlatformSupport/private/qeglconvenience_p.h>
end_include
begin_include
include|#
directive|include
file|<QtPlatformSupport/private/qeglpbuffer_p.h>
end_include
begin_include
include|#
directive|include
file|<QtPlatformSupport/private/qeglplatformcursor_p.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/QSurface>
end_include
begin_include
include|#
directive|include
file|<QtDebug>
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_constructor
DECL|function|QEglFSContext
name|QEglFSContext
operator|::
name|QEglFSContext
parameter_list|(
specifier|const
name|QSurfaceFormat
modifier|&
name|format
parameter_list|,
name|QPlatformOpenGLContext
modifier|*
name|share
parameter_list|,
name|EGLDisplay
name|display
parameter_list|,
name|EGLConfig
modifier|*
name|config
parameter_list|,
specifier|const
name|QVariant
modifier|&
name|nativeHandle
parameter_list|)
member_init_list|:
name|QEGLPlatformContext
argument_list|(
name|format
argument_list|,
name|share
argument_list|,
name|display
argument_list|,
name|config
argument_list|,
name|nativeHandle
argument_list|)
member_init_list|,
name|m_tempWindow
argument_list|(
literal|0
argument_list|)
block|{ }
end_constructor
begin_function
DECL|function|eglSurfaceForPlatformSurface
name|EGLSurface
name|QEglFSContext
operator|::
name|eglSurfaceForPlatformSurface
parameter_list|(
name|QPlatformSurface
modifier|*
name|surface
parameter_list|)
block|{
if|if
condition|(
name|surface
operator|->
name|surface
argument_list|()
operator|->
name|surfaceClass
argument_list|()
operator|==
name|QSurface
operator|::
name|Window
condition|)
return|return
cast|static_cast
argument_list|<
name|QEglFSWindow
operator|*
argument_list|>
argument_list|(
name|surface
argument_list|)
operator|->
name|surface
argument_list|()
return|;
else|else
return|return
cast|static_cast
argument_list|<
name|QEGLPbuffer
operator|*
argument_list|>
argument_list|(
name|surface
argument_list|)
operator|->
name|pbuffer
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|createTemporaryOffscreenSurface
name|EGLSurface
name|QEglFSContext
operator|::
name|createTemporaryOffscreenSurface
parameter_list|()
block|{
if|if
condition|(
name|qt_egl_device_integration
argument_list|()
operator|->
name|supportsPBuffers
argument_list|()
condition|)
return|return
name|QEGLPlatformContext
operator|::
name|createTemporaryOffscreenSurface
argument_list|()
return|;
if|if
condition|(
operator|!
name|m_tempWindow
condition|)
block|{
name|m_tempWindow
operator|=
name|qt_egl_device_integration
argument_list|()
operator|->
name|createNativeOffscreenWindow
argument_list|(
name|format
argument_list|()
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|m_tempWindow
condition|)
block|{
name|qWarning
argument_list|(
literal|"QEglFSContext: Failed to create temporary native window"
argument_list|)
expr_stmt|;
return|return
name|EGL_NO_SURFACE
return|;
block|}
block|}
name|EGLConfig
name|config
init|=
name|q_configFromGLFormat
argument_list|(
name|eglDisplay
argument_list|()
argument_list|,
name|format
argument_list|()
argument_list|)
decl_stmt|;
return|return
name|eglCreateWindowSurface
argument_list|(
name|eglDisplay
argument_list|()
argument_list|,
name|config
argument_list|,
name|m_tempWindow
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|destroyTemporaryOffscreenSurface
name|void
name|QEglFSContext
operator|::
name|destroyTemporaryOffscreenSurface
parameter_list|(
name|EGLSurface
name|surface
parameter_list|)
block|{
if|if
condition|(
name|qt_egl_device_integration
argument_list|()
operator|->
name|supportsPBuffers
argument_list|()
condition|)
block|{
name|QEGLPlatformContext
operator|::
name|destroyTemporaryOffscreenSurface
argument_list|(
name|surface
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|eglDestroySurface
argument_list|(
name|eglDisplay
argument_list|()
argument_list|,
name|surface
argument_list|)
expr_stmt|;
name|qt_egl_device_integration
argument_list|()
operator|->
name|destroyNativeWindow
argument_list|(
name|m_tempWindow
argument_list|)
expr_stmt|;
name|m_tempWindow
operator|=
literal|0
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|swapBuffers
name|void
name|QEglFSContext
operator|::
name|swapBuffers
parameter_list|(
name|QPlatformSurface
modifier|*
name|surface
parameter_list|)
block|{
comment|// draw the cursor
if|if
condition|(
name|surface
operator|->
name|surface
argument_list|()
operator|->
name|surfaceClass
argument_list|()
operator|==
name|QSurface
operator|::
name|Window
condition|)
block|{
name|QPlatformWindow
modifier|*
name|window
init|=
cast|static_cast
argument_list|<
name|QPlatformWindow
operator|*
argument_list|>
argument_list|(
name|surface
argument_list|)
decl_stmt|;
if|if
condition|(
name|QEGLPlatformCursor
modifier|*
name|cursor
init|=
name|qobject_cast
argument_list|<
name|QEGLPlatformCursor
operator|*
argument_list|>
argument_list|(
name|window
operator|->
name|screen
argument_list|()
operator|->
name|cursor
argument_list|()
argument_list|)
condition|)
name|cursor
operator|->
name|paintOnScreen
argument_list|()
expr_stmt|;
block|}
name|qt_egl_device_integration
argument_list|()
operator|->
name|waitForVSync
argument_list|(
name|surface
argument_list|)
expr_stmt|;
name|QEGLPlatformContext
operator|::
name|swapBuffers
argument_list|(
name|surface
argument_list|)
expr_stmt|;
name|qt_egl_device_integration
argument_list|()
operator|->
name|presentBuffer
argument_list|(
name|surface
argument_list|)
expr_stmt|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
