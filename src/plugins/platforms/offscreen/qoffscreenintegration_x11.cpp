begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qoffscreenintegration_x11.h"
end_include
begin_include
include|#
directive|include
file|<QByteArray>
end_include
begin_include
include|#
directive|include
file|<QOpenGLContext>
end_include
begin_include
include|#
directive|include
file|<X11/Xlib.h>
end_include
begin_include
include|#
directive|include
file|<GL/glx.h>
end_include
begin_include
include|#
directive|include
file|<QtPlatformSupport/private/qglxconvenience_p.h>
end_include
begin_include
include|#
directive|include
file|<qpa/qplatformsurface.h>
end_include
begin_include
include|#
directive|include
file|<qsurface.h>
end_include
begin_function
name|QT_BEGIN_NAMESPACE
DECL|function|createOffscreenIntegration
name|QOffscreenIntegration
modifier|*
name|QOffscreenIntegration
operator|::
name|createOffscreenIntegration
parameter_list|()
block|{
return|return
operator|new
name|QOffscreenX11Integration
return|;
block|}
end_function
begin_function
DECL|function|hasCapability
name|bool
name|QOffscreenX11Integration
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
switch|switch
condition|(
name|cap
condition|)
block|{
case|case
name|OpenGL
case|:
return|return
literal|true
return|;
case|case
name|ThreadedOpenGL
case|:
return|return
literal|true
return|;
default|default:
return|return
name|QOffscreenIntegration
operator|::
name|hasCapability
argument_list|(
name|cap
argument_list|)
return|;
block|}
block|}
end_function
begin_function
DECL|function|createPlatformOpenGLContext
name|QPlatformOpenGLContext
modifier|*
name|QOffscreenX11Integration
operator|::
name|createPlatformOpenGLContext
parameter_list|(
name|QOpenGLContext
modifier|*
name|context
parameter_list|)
specifier|const
block|{
if|if
condition|(
operator|!
name|m_connection
condition|)
name|m_connection
operator|.
name|reset
argument_list|(
operator|new
name|QOffscreenX11Connection
argument_list|)
expr_stmt|;
return|return
operator|new
name|QOffscreenX11GLXContext
argument_list|(
name|m_connection
operator|->
name|x11Info
argument_list|()
argument_list|,
name|context
argument_list|)
return|;
block|}
end_function
begin_constructor
DECL|function|QOffscreenX11Connection
name|QOffscreenX11Connection
operator|::
name|QOffscreenX11Connection
parameter_list|()
block|{
name|XInitThreads
argument_list|()
expr_stmt|;
name|QByteArray
name|displayName
init|=
name|qgetenv
argument_list|(
literal|"DISPLAY"
argument_list|)
decl_stmt|;
name|Display
modifier|*
name|display
init|=
name|XOpenDisplay
argument_list|(
name|displayName
operator|.
name|constData
argument_list|()
argument_list|)
decl_stmt|;
name|m_display
operator|=
name|display
expr_stmt|;
name|m_screenNumber
operator|=
name|DefaultScreen
argument_list|(
name|display
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_destructor
DECL|function|~QOffscreenX11Connection
name|QOffscreenX11Connection
operator|::
name|~
name|QOffscreenX11Connection
parameter_list|()
block|{
name|XCloseDisplay
argument_list|(
operator|(
name|Display
operator|*
operator|)
name|m_display
argument_list|)
expr_stmt|;
block|}
end_destructor
begin_class
DECL|class|QOffscreenX11Info
class|class
name|QOffscreenX11Info
block|{
public|public:
DECL|function|QOffscreenX11Info
name|QOffscreenX11Info
parameter_list|(
name|QOffscreenX11Connection
modifier|*
name|connection
parameter_list|)
member_init_list|:
name|m_connection
argument_list|(
name|connection
argument_list|)
block|{     }
DECL|function|display
name|Display
modifier|*
name|display
parameter_list|()
specifier|const
block|{
return|return
operator|(
name|Display
operator|*
operator|)
name|m_connection
operator|->
name|display
argument_list|()
return|;
block|}
DECL|function|root
name|Window
name|root
parameter_list|()
specifier|const
block|{
return|return
name|DefaultRootWindow
argument_list|(
name|display
argument_list|()
argument_list|)
return|;
block|}
DECL|function|screenNumber
name|int
name|screenNumber
parameter_list|()
specifier|const
block|{
return|return
name|m_connection
operator|->
name|screenNumber
argument_list|()
return|;
block|}
private|private:
DECL|member|m_connection
name|QOffscreenX11Connection
modifier|*
name|m_connection
decl_stmt|;
block|}
class|;
end_class
begin_function
DECL|function|x11Info
name|QOffscreenX11Info
modifier|*
name|QOffscreenX11Connection
operator|::
name|x11Info
parameter_list|()
block|{
if|if
condition|(
operator|!
name|m_x11Info
condition|)
name|m_x11Info
operator|.
name|reset
argument_list|(
operator|new
name|QOffscreenX11Info
argument_list|(
name|this
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|m_x11Info
operator|.
name|data
argument_list|()
return|;
block|}
end_function
begin_class
DECL|class|QOffscreenX11GLXContextData
class|class
name|QOffscreenX11GLXContextData
block|{
public|public:
DECL|member|x11
name|QOffscreenX11Info
modifier|*
name|x11
decl_stmt|;
DECL|member|format
name|QSurfaceFormat
name|format
decl_stmt|;
DECL|member|context
name|GLXContext
name|context
decl_stmt|;
DECL|member|shareContext
name|GLXContext
name|shareContext
decl_stmt|;
DECL|member|window
name|Window
name|window
decl_stmt|;
block|}
class|;
end_class
begin_function
DECL|function|createDummyWindow
specifier|static
name|Window
name|createDummyWindow
parameter_list|(
name|QOffscreenX11Info
modifier|*
name|x11
parameter_list|,
name|XVisualInfo
modifier|*
name|visualInfo
parameter_list|)
block|{
name|Colormap
name|cmap
init|=
name|XCreateColormap
argument_list|(
name|x11
operator|->
name|display
argument_list|()
argument_list|,
name|x11
operator|->
name|root
argument_list|()
argument_list|,
name|visualInfo
operator|->
name|visual
argument_list|,
name|AllocNone
argument_list|)
decl_stmt|;
name|XSetWindowAttributes
name|a
decl_stmt|;
name|a
operator|.
name|background_pixel
operator|=
name|WhitePixel
argument_list|(
name|x11
operator|->
name|display
argument_list|()
argument_list|,
name|x11
operator|->
name|screenNumber
argument_list|()
argument_list|)
expr_stmt|;
name|a
operator|.
name|border_pixel
operator|=
name|BlackPixel
argument_list|(
name|x11
operator|->
name|display
argument_list|()
argument_list|,
name|x11
operator|->
name|screenNumber
argument_list|()
argument_list|)
expr_stmt|;
name|a
operator|.
name|colormap
operator|=
name|cmap
expr_stmt|;
name|Window
name|window
init|=
name|XCreateWindow
argument_list|(
name|x11
operator|->
name|display
argument_list|()
argument_list|,
name|x11
operator|->
name|root
argument_list|()
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|100
argument_list|,
literal|100
argument_list|,
literal|0
argument_list|,
name|visualInfo
operator|->
name|depth
argument_list|,
name|InputOutput
argument_list|,
name|visualInfo
operator|->
name|visual
argument_list|,
name|CWBackPixel
operator||
name|CWBorderPixel
operator||
name|CWColormap
argument_list|,
operator|&
name|a
argument_list|)
decl_stmt|;
name|XFreeColormap
argument_list|(
name|x11
operator|->
name|display
argument_list|()
argument_list|,
name|cmap
argument_list|)
expr_stmt|;
return|return
name|window
return|;
block|}
end_function
begin_function
DECL|function|createDummyWindow
specifier|static
name|Window
name|createDummyWindow
parameter_list|(
name|QOffscreenX11Info
modifier|*
name|x11
parameter_list|,
name|GLXFBConfig
name|config
parameter_list|)
block|{
name|XVisualInfo
modifier|*
name|visualInfo
init|=
name|glXGetVisualFromFBConfig
argument_list|(
name|x11
operator|->
name|display
argument_list|()
argument_list|,
name|config
argument_list|)
decl_stmt|;
if|if
condition|(
name|Q_UNLIKELY
argument_list|(
operator|!
name|visualInfo
argument_list|)
condition|)
name|qFatal
argument_list|(
literal|"Could not initialize GLX"
argument_list|)
expr_stmt|;
name|Window
name|window
init|=
name|createDummyWindow
argument_list|(
name|x11
argument_list|,
name|visualInfo
argument_list|)
decl_stmt|;
name|XFree
argument_list|(
name|visualInfo
argument_list|)
expr_stmt|;
return|return
name|window
return|;
block|}
end_function
begin_constructor
DECL|function|QOffscreenX11GLXContext
name|QOffscreenX11GLXContext
operator|::
name|QOffscreenX11GLXContext
parameter_list|(
name|QOffscreenX11Info
modifier|*
name|x11
parameter_list|,
name|QOpenGLContext
modifier|*
name|context
parameter_list|)
member_init_list|:
name|d
argument_list|(
operator|new
name|QOffscreenX11GLXContextData
argument_list|)
block|{
name|d
operator|->
name|x11
operator|=
name|x11
expr_stmt|;
name|d
operator|->
name|format
operator|=
name|context
operator|->
name|format
argument_list|()
expr_stmt|;
name|d
operator|->
name|shareContext
operator|=
literal|0
expr_stmt|;
if|if
condition|(
name|context
operator|->
name|shareHandle
argument_list|()
condition|)
name|d
operator|->
name|shareContext
operator|=
cast|static_cast
argument_list|<
name|QOffscreenX11GLXContext
operator|*
argument_list|>
argument_list|(
name|context
operator|->
name|shareHandle
argument_list|()
argument_list|)
operator|->
name|d
operator|->
name|context
expr_stmt|;
name|GLXFBConfig
name|config
init|=
name|qglx_findConfig
argument_list|(
name|x11
operator|->
name|display
argument_list|()
argument_list|,
name|x11
operator|->
name|screenNumber
argument_list|()
argument_list|,
name|d
operator|->
name|format
argument_list|)
decl_stmt|;
if|if
condition|(
name|config
condition|)
block|{
name|d
operator|->
name|context
operator|=
name|glXCreateNewContext
argument_list|(
name|x11
operator|->
name|display
argument_list|()
argument_list|,
name|config
argument_list|,
name|GLX_RGBA_TYPE
argument_list|,
name|d
operator|->
name|shareContext
argument_list|,
literal|true
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|d
operator|->
name|context
operator|&&
name|d
operator|->
name|shareContext
condition|)
block|{
name|d
operator|->
name|shareContext
operator|=
literal|0
expr_stmt|;
comment|// re-try without a shared glx context
name|d
operator|->
name|context
operator|=
name|glXCreateNewContext
argument_list|(
name|x11
operator|->
name|display
argument_list|()
argument_list|,
name|config
argument_list|,
name|GLX_RGBA_TYPE
argument_list|,
literal|0
argument_list|,
literal|true
argument_list|)
expr_stmt|;
block|}
comment|// Get the basic surface format details
if|if
condition|(
name|d
operator|->
name|context
condition|)
name|qglx_surfaceFormatFromGLXFBConfig
argument_list|(
operator|&
name|d
operator|->
name|format
argument_list|,
name|x11
operator|->
name|display
argument_list|()
argument_list|,
name|config
argument_list|)
expr_stmt|;
comment|// Create a temporary window so that we can make the new context current
name|d
operator|->
name|window
operator|=
name|createDummyWindow
argument_list|(
name|x11
argument_list|,
name|config
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|XVisualInfo
modifier|*
name|visualInfo
init|=
name|qglx_findVisualInfo
argument_list|(
name|x11
operator|->
name|display
argument_list|()
argument_list|,
literal|0
argument_list|,
operator|&
name|d
operator|->
name|format
argument_list|)
decl_stmt|;
if|if
condition|(
name|Q_UNLIKELY
argument_list|(
operator|!
name|visualInfo
argument_list|)
condition|)
name|qFatal
argument_list|(
literal|"Could not initialize GLX"
argument_list|)
expr_stmt|;
name|d
operator|->
name|context
operator|=
name|glXCreateContext
argument_list|(
name|x11
operator|->
name|display
argument_list|()
argument_list|,
name|visualInfo
argument_list|,
name|d
operator|->
name|shareContext
argument_list|,
literal|true
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|d
operator|->
name|context
operator|&&
name|d
operator|->
name|shareContext
condition|)
block|{
comment|// re-try without a shared glx context
name|d
operator|->
name|shareContext
operator|=
literal|0
expr_stmt|;
name|d
operator|->
name|context
operator|=
name|glXCreateContext
argument_list|(
name|x11
operator|->
name|display
argument_list|()
argument_list|,
name|visualInfo
argument_list|,
literal|0
argument_list|,
literal|true
argument_list|)
expr_stmt|;
block|}
name|d
operator|->
name|window
operator|=
name|createDummyWindow
argument_list|(
name|x11
argument_list|,
name|visualInfo
argument_list|)
expr_stmt|;
name|XFree
argument_list|(
name|visualInfo
argument_list|)
expr_stmt|;
block|}
block|}
end_constructor
begin_destructor
DECL|function|~QOffscreenX11GLXContext
name|QOffscreenX11GLXContext
operator|::
name|~
name|QOffscreenX11GLXContext
parameter_list|()
block|{
name|glXDestroyContext
argument_list|(
name|d
operator|->
name|x11
operator|->
name|display
argument_list|()
argument_list|,
name|d
operator|->
name|context
argument_list|)
expr_stmt|;
name|XDestroyWindow
argument_list|(
name|d
operator|->
name|x11
operator|->
name|display
argument_list|()
argument_list|,
name|d
operator|->
name|window
argument_list|)
expr_stmt|;
block|}
end_destructor
begin_function
DECL|function|makeCurrent
name|bool
name|QOffscreenX11GLXContext
operator|::
name|makeCurrent
parameter_list|(
name|QPlatformSurface
modifier|*
name|surface
parameter_list|)
block|{
name|QSize
name|size
init|=
name|surface
operator|->
name|surface
argument_list|()
operator|->
name|size
argument_list|()
decl_stmt|;
name|XResizeWindow
argument_list|(
name|d
operator|->
name|x11
operator|->
name|display
argument_list|()
argument_list|,
name|d
operator|->
name|window
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
argument_list|)
expr_stmt|;
name|XSync
argument_list|(
name|d
operator|->
name|x11
operator|->
name|display
argument_list|()
argument_list|,
literal|true
argument_list|)
expr_stmt|;
if|if
condition|(
name|glXMakeCurrent
argument_list|(
name|d
operator|->
name|x11
operator|->
name|display
argument_list|()
argument_list|,
name|d
operator|->
name|window
argument_list|,
name|d
operator|->
name|context
argument_list|)
condition|)
block|{
name|glViewport
argument_list|(
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
argument_list|)
expr_stmt|;
return|return
literal|true
return|;
block|}
return|return
literal|false
return|;
block|}
end_function
begin_function
DECL|function|doneCurrent
name|void
name|QOffscreenX11GLXContext
operator|::
name|doneCurrent
parameter_list|()
block|{
name|glXMakeCurrent
argument_list|(
name|d
operator|->
name|x11
operator|->
name|display
argument_list|()
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|swapBuffers
name|void
name|QOffscreenX11GLXContext
operator|::
name|swapBuffers
parameter_list|(
name|QPlatformSurface
modifier|*
parameter_list|)
block|{ }
end_function
begin_macro
DECL|function|getProcAddress
name|void
argument_list|(
argument|*QOffscreenX11GLXContext::getProcAddress(const QByteArray&procName)
argument_list|)
end_macro
begin_expr_stmt
DECL|function|getProcAddress
operator|(
operator|)
block|{
return|return
operator|(
name|void
argument_list|(
operator|*
argument_list|)
argument_list|()
operator|)
name|glXGetProcAddressARB
argument_list|(
cast|reinterpret_cast
argument_list|<
specifier|const
name|GLubyte
operator|*
argument_list|>
argument_list|(
name|procName
operator|.
name|constData
argument_list|()
argument_list|)
argument_list|)
return|;
block|}
end_expr_stmt
begin_function
DECL|function|format
name|QSurfaceFormat
name|QOffscreenX11GLXContext
operator|::
name|format
parameter_list|()
specifier|const
block|{
return|return
name|d
operator|->
name|format
return|;
block|}
end_function
begin_function
DECL|function|isSharing
name|bool
name|QOffscreenX11GLXContext
operator|::
name|isSharing
parameter_list|()
specifier|const
block|{
return|return
name|d
operator|->
name|shareContext
return|;
block|}
end_function
begin_function
DECL|function|isValid
name|bool
name|QOffscreenX11GLXContext
operator|::
name|isValid
parameter_list|()
specifier|const
block|{
return|return
name|d
operator|->
name|context
operator|&&
name|d
operator|->
name|window
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
