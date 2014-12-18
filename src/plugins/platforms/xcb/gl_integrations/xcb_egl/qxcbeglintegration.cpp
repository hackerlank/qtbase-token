begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2014 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qxcbeglintegration.h"
end_include
begin_include
include|#
directive|include
file|"qxcbeglcontext.h"
end_include
begin_include
include|#
directive|include
file|<QtGui/QOffscreenSurface>
end_include
begin_include
include|#
directive|include
file|"qxcbeglnativeinterfacehandler.h"
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_constructor
DECL|function|QXcbEglIntegration
name|QXcbEglIntegration
operator|::
name|QXcbEglIntegration
parameter_list|()
member_init_list|:
name|m_connection
argument_list|(
name|Q_NULLPTR
argument_list|)
member_init_list|,
name|m_egl_display
argument_list|(
name|EGL_NO_DISPLAY
argument_list|)
block|{
name|qCDebug
argument_list|(
name|QT_XCB_GLINTEGRATION
argument_list|)
operator|<<
literal|"Xcb EGL gl-integration created"
expr_stmt|;
block|}
end_constructor
begin_destructor
DECL|function|~QXcbEglIntegration
name|QXcbEglIntegration
operator|::
name|~
name|QXcbEglIntegration
parameter_list|()
block|{
if|if
condition|(
name|m_egl_display
operator|!=
name|EGL_NO_DISPLAY
condition|)
name|eglTerminate
argument_list|(
name|m_egl_display
argument_list|)
expr_stmt|;
block|}
end_destructor
begin_function
DECL|function|initialize
name|bool
name|QXcbEglIntegration
operator|::
name|initialize
parameter_list|(
name|QXcbConnection
modifier|*
name|connection
parameter_list|)
block|{
name|m_connection
operator|=
name|connection
expr_stmt|;
name|Display
modifier|*
name|dpy
init|=
operator|(
name|Display
operator|*
operator|)
name|m_connection
operator|->
name|xlib_display
argument_list|()
decl_stmt|;
name|m_egl_display
operator|=
name|eglGetDisplay
argument_list|(
name|dpy
argument_list|)
expr_stmt|;
name|EGLint
name|major
decl_stmt|,
name|minor
decl_stmt|;
name|bool
name|success
init|=
name|eglInitialize
argument_list|(
name|m_egl_display
argument_list|,
operator|&
name|major
argument_list|,
operator|&
name|minor
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|success
condition|)
block|{
name|m_egl_display
operator|=
name|eglGetDisplay
argument_list|(
name|EGL_DEFAULT_DISPLAY
argument_list|)
expr_stmt|;
name|qCDebug
argument_list|(
name|QT_XCB_GLINTEGRATION
argument_list|)
operator|<<
literal|"Xcb EGL gl-integration retrying with display"
operator|<<
name|m_egl_display
expr_stmt|;
name|success
operator|=
name|eglInitialize
argument_list|(
name|m_egl_display
argument_list|,
operator|&
name|major
argument_list|,
operator|&
name|minor
argument_list|)
expr_stmt|;
block|}
name|m_native_interface_handler
operator|.
name|reset
argument_list|(
operator|new
name|QXcbEglNativeInterfaceHandler
argument_list|(
name|connection
operator|->
name|nativeInterface
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|qCDebug
argument_list|(
name|QT_XCB_GLINTEGRATION
argument_list|)
operator|<<
literal|"Xcb EGL gl-integration successfully initialized"
expr_stmt|;
return|return
name|success
return|;
block|}
end_function
begin_function
DECL|function|createWindow
name|QXcbWindow
modifier|*
name|QXcbEglIntegration
operator|::
name|createWindow
parameter_list|(
name|QWindow
modifier|*
name|window
parameter_list|)
specifier|const
block|{
return|return
operator|new
name|QXcbEglWindow
argument_list|(
name|window
argument_list|,
cast|const_cast
argument_list|<
name|QXcbEglIntegration
operator|*
argument_list|>
argument_list|(
name|this
argument_list|)
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|createPlatformOpenGLContext
name|QPlatformOpenGLContext
modifier|*
name|QXcbEglIntegration
operator|::
name|createPlatformOpenGLContext
parameter_list|(
name|QOpenGLContext
modifier|*
name|context
parameter_list|)
specifier|const
block|{
name|QXcbScreen
modifier|*
name|screen
init|=
cast|static_cast
argument_list|<
name|QXcbScreen
operator|*
argument_list|>
argument_list|(
name|context
operator|->
name|screen
argument_list|()
operator|->
name|handle
argument_list|()
argument_list|)
decl_stmt|;
name|QXcbEglContext
modifier|*
name|platformContext
init|=
operator|new
name|QXcbEglContext
argument_list|(
name|context
operator|->
name|format
argument_list|()
argument_list|,
name|context
operator|->
name|shareHandle
argument_list|()
argument_list|,
name|eglDisplay
argument_list|()
argument_list|,
name|screen
operator|->
name|connection
argument_list|()
argument_list|,
name|context
operator|->
name|nativeHandle
argument_list|()
argument_list|)
decl_stmt|;
name|context
operator|->
name|setNativeHandle
argument_list|(
name|platformContext
operator|->
name|nativeHandle
argument_list|()
argument_list|)
expr_stmt|;
return|return
name|platformContext
return|;
block|}
end_function
begin_function
DECL|function|createPlatformOffscreenSurface
name|QPlatformOffscreenSurface
modifier|*
name|QXcbEglIntegration
operator|::
name|createPlatformOffscreenSurface
parameter_list|(
name|QOffscreenSurface
modifier|*
name|surface
parameter_list|)
specifier|const
block|{
return|return
operator|new
name|QEGLPbuffer
argument_list|(
name|eglDisplay
argument_list|()
argument_list|,
name|surface
operator|->
name|requestedFormat
argument_list|()
argument_list|,
name|surface
argument_list|)
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit