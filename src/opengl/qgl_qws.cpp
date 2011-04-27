begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtOpenGL module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** No Commercial Usage ** This file contains pre-release code and may not be distributed. ** You may use this file in accordance with the terms and conditions ** contained in the Technology Preview License Agreement accompanying ** this package. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights.  These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** If you have questions regarding the use of this file, please contact ** Nokia at qt-info@nokia.com. ** ** ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qgl.h"
end_include
begin_include
include|#
directive|include
file|"qgl_egl_p.h"
end_include
begin_include
include|#
directive|include
file|"qglpixelbuffer.h"
end_include
begin_include
include|#
directive|include
file|<qglscreen_qws.h>
end_include
begin_include
include|#
directive|include
file|<qscreenproxy_qws.h>
end_include
begin_include
include|#
directive|include
file|<private/qglwindowsurface_qws_p.h>
end_include
begin_include
include|#
directive|include
file|<private/qbackingstore_p.h>
end_include
begin_include
include|#
directive|include
file|<private/qfont_p.h>
end_include
begin_include
include|#
directive|include
file|<private/qfontengine_p.h>
end_include
begin_include
include|#
directive|include
file|<private/qgl_p.h>
end_include
begin_include
include|#
directive|include
file|<private/qpaintengine_opengl_p.h>
end_include
begin_include
include|#
directive|include
file|<qpixmap.h>
end_include
begin_include
include|#
directive|include
file|<qtimer.h>
end_include
begin_include
include|#
directive|include
file|<qapplication.h>
end_include
begin_include
include|#
directive|include
file|<qstack.h>
end_include
begin_include
include|#
directive|include
file|<qdesktopwidget.h>
end_include
begin_include
include|#
directive|include
file|<qdebug.h>
end_include
begin_include
include|#
directive|include
file|<qvarlengtharray.h>
end_include
begin_function
name|QT_BEGIN_NAMESPACE
DECL|function|glScreenForDevice
specifier|static
name|QGLScreen
modifier|*
name|glScreenForDevice
parameter_list|(
name|QPaintDevice
modifier|*
name|device
parameter_list|)
block|{
name|QScreen
modifier|*
name|screen
init|=
name|qt_screen
decl_stmt|;
if|if
condition|(
name|screen
operator|->
name|classId
argument_list|()
operator|==
name|QScreen
operator|::
name|MultiClass
condition|)
block|{
name|int
name|screenNumber
decl_stmt|;
if|if
condition|(
name|device
operator|&&
name|device
operator|->
name|devType
argument_list|()
operator|==
name|QInternal
operator|::
name|Widget
condition|)
name|screenNumber
operator|=
name|qApp
operator|->
name|desktop
argument_list|()
operator|->
name|screenNumber
argument_list|(
cast|static_cast
argument_list|<
name|QWidget
operator|*
argument_list|>
argument_list|(
name|device
argument_list|)
argument_list|)
expr_stmt|;
else|else
name|screenNumber
operator|=
literal|0
expr_stmt|;
name|screen
operator|=
name|screen
operator|->
name|subScreens
argument_list|()
index|[
name|screenNumber
index|]
expr_stmt|;
block|}
while|while
condition|(
name|screen
operator|->
name|classId
argument_list|()
operator|==
name|QScreen
operator|::
name|ProxyClass
operator|||
name|screen
operator|->
name|classId
argument_list|()
operator|==
name|QScreen
operator|::
name|TransformedClass
condition|)
block|{
name|screen
operator|=
cast|static_cast
argument_list|<
name|QProxyScreen
operator|*
argument_list|>
argument_list|(
name|screen
argument_list|)
operator|->
name|screen
argument_list|()
expr_stmt|;
block|}
if|if
condition|(
name|screen
operator|->
name|classId
argument_list|()
operator|==
name|QScreen
operator|::
name|GLClass
condition|)
return|return
cast|static_cast
argument_list|<
name|QGLScreen
operator|*
argument_list|>
argument_list|(
name|screen
argument_list|)
return|;
else|else
return|return
literal|0
return|;
block|}
end_function
begin_comment
comment|/*     QGLTemporaryContext implementation */
end_comment
begin_class
DECL|class|QGLTemporaryContextPrivate
class|class
name|QGLTemporaryContextPrivate
block|{
public|public:
DECL|member|widget
name|QGLWidget
modifier|*
name|widget
decl_stmt|;
block|}
class|;
end_class
begin_constructor
DECL|function|QGLTemporaryContext
name|QGLTemporaryContext
operator|::
name|QGLTemporaryContext
parameter_list|(
name|bool
parameter_list|,
name|QWidget
modifier|*
parameter_list|)
member_init_list|:
name|d
argument_list|(
operator|new
name|QGLTemporaryContextPrivate
argument_list|)
block|{
name|d
operator|->
name|widget
operator|=
operator|new
name|QGLWidget
expr_stmt|;
name|d
operator|->
name|widget
operator|->
name|makeCurrent
argument_list|()
expr_stmt|;
block|}
end_constructor
begin_destructor
DECL|function|~QGLTemporaryContext
name|QGLTemporaryContext
operator|::
name|~
name|QGLTemporaryContext
parameter_list|()
block|{
operator|delete
name|d
operator|->
name|widget
expr_stmt|;
block|}
end_destructor
begin_comment
comment|/*****************************************************************************   QOpenGL debug facilities  *****************************************************************************/
end_comment
begin_comment
comment|//#define DEBUG_OPENGL_REGION_UPDATE
end_comment
begin_function
DECL|function|hasOpenGLOverlays
name|bool
name|QGLFormat
operator|::
name|hasOpenGLOverlays
parameter_list|()
block|{
name|QGLScreen
modifier|*
name|glScreen
init|=
name|glScreenForDevice
argument_list|(
literal|0
argument_list|)
decl_stmt|;
if|if
condition|(
name|glScreen
condition|)
return|return
operator|(
name|glScreen
operator|->
name|options
argument_list|()
operator|&
name|QGLScreen
operator|::
name|Overlays
operator|)
return|;
else|else
return|return
literal|false
return|;
block|}
end_function
begin_function
DECL|function|qt_egl_create_surface
specifier|static
name|EGLSurface
name|qt_egl_create_surface
parameter_list|(
name|QEglContext
modifier|*
name|context
parameter_list|,
name|QPaintDevice
modifier|*
name|device
parameter_list|,
specifier|const
name|QEglProperties
modifier|*
name|properties
init|=
literal|0
parameter_list|)
block|{
comment|// Get the screen surface functions, which are used to create native ids.
name|QGLScreen
modifier|*
name|glScreen
init|=
name|glScreenForDevice
argument_list|(
name|device
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|glScreen
condition|)
return|return
name|EGL_NO_SURFACE
return|;
name|QGLScreenSurfaceFunctions
modifier|*
name|funcs
init|=
name|glScreen
operator|->
name|surfaceFunctions
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
name|funcs
condition|)
return|return
name|EGL_NO_SURFACE
return|;
comment|// Create the native drawable for the paint device.
name|int
name|devType
init|=
name|device
operator|->
name|devType
argument_list|()
decl_stmt|;
name|EGLNativePixmapType
name|pixmapDrawable
init|=
literal|0
decl_stmt|;
name|EGLNativeWindowType
name|windowDrawable
init|=
literal|0
decl_stmt|;
name|bool
name|ok
decl_stmt|;
if|if
condition|(
name|devType
operator|==
name|QInternal
operator|::
name|Pixmap
condition|)
block|{
name|ok
operator|=
name|funcs
operator|->
name|createNativePixmap
argument_list|(
cast|static_cast
argument_list|<
name|QPixmap
operator|*
argument_list|>
argument_list|(
name|device
argument_list|)
argument_list|,
operator|&
name|pixmapDrawable
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|devType
operator|==
name|QInternal
operator|::
name|Image
condition|)
block|{
name|ok
operator|=
name|funcs
operator|->
name|createNativeImage
argument_list|(
cast|static_cast
argument_list|<
name|QImage
operator|*
argument_list|>
argument_list|(
name|device
argument_list|)
argument_list|,
operator|&
name|pixmapDrawable
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|ok
operator|=
name|funcs
operator|->
name|createNativeWindow
argument_list|(
cast|static_cast
argument_list|<
name|QWidget
operator|*
argument_list|>
argument_list|(
name|device
argument_list|)
argument_list|,
operator|&
name|windowDrawable
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
operator|!
name|ok
condition|)
block|{
name|qWarning
argument_list|(
literal|"QEglContext::createSurface(): Cannot create the native EGL drawable"
argument_list|)
expr_stmt|;
return|return
name|EGL_NO_SURFACE
return|;
block|}
comment|// Create the EGL surface to draw into, based on the native drawable.
specifier|const
name|int
modifier|*
name|props
decl_stmt|;
if|if
condition|(
name|properties
condition|)
name|props
operator|=
name|properties
operator|->
name|properties
argument_list|()
expr_stmt|;
else|else
name|props
operator|=
literal|0
expr_stmt|;
name|EGLSurface
name|surf
decl_stmt|;
if|if
condition|(
name|devType
operator|==
name|QInternal
operator|::
name|Widget
condition|)
block|{
name|surf
operator|=
name|eglCreateWindowSurface
argument_list|(
name|context
operator|->
name|display
argument_list|()
argument_list|,
name|context
operator|->
name|config
argument_list|()
argument_list|,
name|windowDrawable
argument_list|,
name|props
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|surf
operator|=
name|eglCreatePixmapSurface
argument_list|(
name|context
operator|->
name|display
argument_list|()
argument_list|,
name|context
operator|->
name|config
argument_list|()
argument_list|,
name|pixmapDrawable
argument_list|,
name|props
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|surf
operator|==
name|EGL_NO_SURFACE
condition|)
name|qWarning
argument_list|(
literal|"QEglContext::createSurface(): Unable to create EGL surface, error = 0x%x"
argument_list|,
name|eglGetError
argument_list|()
argument_list|)
expr_stmt|;
return|return
name|surf
return|;
block|}
end_function
begin_function
DECL|function|chooseContext
name|bool
name|QGLContext
operator|::
name|chooseContext
parameter_list|(
specifier|const
name|QGLContext
modifier|*
name|shareContext
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QGLContext
argument_list|)
expr_stmt|;
comment|// Validate the device.
if|if
condition|(
operator|!
name|device
argument_list|()
condition|)
return|return
literal|false
return|;
name|int
name|devType
init|=
name|device
argument_list|()
operator|->
name|devType
argument_list|()
decl_stmt|;
if|if
condition|(
name|devType
operator|!=
name|QInternal
operator|::
name|Pixmap
operator|&&
name|devType
operator|!=
name|QInternal
operator|::
name|Image
operator|&&
name|devType
operator|!=
name|QInternal
operator|::
name|Widget
condition|)
block|{
name|qWarning
argument_list|(
literal|"QGLContext::chooseContext(): Cannot create QGLContext's for paint device type %d"
argument_list|,
name|devType
argument_list|)
expr_stmt|;
return|return
literal|false
return|;
block|}
comment|// Get the display and initialize it.
name|d
operator|->
name|eglContext
operator|=
operator|new
name|QEglContext
argument_list|()
expr_stmt|;
name|d
operator|->
name|ownsEglContext
operator|=
literal|true
expr_stmt|;
name|d
operator|->
name|eglContext
operator|->
name|setApi
argument_list|(
name|QEgl
operator|::
name|OpenGL
argument_list|)
expr_stmt|;
comment|// Construct the configuration we need for this surface.
name|QEglProperties
name|configProps
decl_stmt|;
name|qt_eglproperties_set_glformat
argument_list|(
name|configProps
argument_list|,
name|d
operator|->
name|glFormat
argument_list|)
expr_stmt|;
name|configProps
operator|.
name|setDeviceType
argument_list|(
name|devType
argument_list|)
expr_stmt|;
name|configProps
operator|.
name|setPaintDeviceFormat
argument_list|(
name|device
argument_list|()
argument_list|)
expr_stmt|;
name|configProps
operator|.
name|setRenderableType
argument_list|(
name|QEgl
operator|::
name|OpenGL
argument_list|)
expr_stmt|;
comment|// Search for a matching configuration, reducing the complexity
comment|// each time until we get something that matches.
if|if
condition|(
operator|!
name|d
operator|->
name|eglContext
operator|->
name|chooseConfig
argument_list|(
name|configProps
argument_list|)
condition|)
block|{
operator|delete
name|d
operator|->
name|eglContext
expr_stmt|;
name|d
operator|->
name|eglContext
operator|=
literal|0
expr_stmt|;
return|return
literal|false
return|;
block|}
comment|// Inform the higher layers about the actual format properties.
name|qt_glformat_from_eglconfig
argument_list|(
name|d
operator|->
name|glFormat
argument_list|,
name|d
operator|->
name|eglContext
operator|->
name|config
argument_list|()
argument_list|)
expr_stmt|;
comment|// Create a new context for the configuration.
if|if
condition|(
operator|!
name|d
operator|->
name|eglContext
operator|->
name|createContext
argument_list|(
name|shareContext
condition|?
name|shareContext
operator|->
name|d_func
argument_list|()
operator|->
name|eglContext
else|:
literal|0
argument_list|)
condition|)
block|{
operator|delete
name|d
operator|->
name|eglContext
expr_stmt|;
name|d
operator|->
name|eglContext
operator|=
literal|0
expr_stmt|;
return|return
literal|false
return|;
block|}
name|d
operator|->
name|sharing
operator|=
name|d
operator|->
name|eglContext
operator|->
name|isSharing
argument_list|()
expr_stmt|;
if|if
condition|(
name|d
operator|->
name|sharing
operator|&&
name|shareContext
condition|)
cast|const_cast
argument_list|<
name|QGLContext
operator|*
argument_list|>
argument_list|(
name|shareContext
argument_list|)
operator|->
name|d_func
argument_list|()
operator|->
name|sharing
operator|=
literal|true
expr_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|EGL_VERSION_1_1
argument_list|)
if|if
condition|(
name|d
operator|->
name|glFormat
operator|.
name|swapInterval
argument_list|()
operator|!=
operator|-
literal|1
operator|&&
name|devType
operator|==
name|QInternal
operator|::
name|Widget
condition|)
name|eglSwapInterval
argument_list|(
name|d
operator|->
name|eglContext
operator|->
name|display
argument_list|()
argument_list|,
name|d
operator|->
name|glFormat
operator|.
name|swapInterval
argument_list|()
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|// Create the EGL surface to draw into.  We cannot use
comment|// QEglContext::createSurface() because it does not have
comment|// access to the QGLScreen.
name|d
operator|->
name|eglSurface
operator|=
name|qt_egl_create_surface
argument_list|(
name|d
operator|->
name|eglContext
argument_list|,
name|device
argument_list|()
argument_list|)
expr_stmt|;
if|if
condition|(
name|d
operator|->
name|eglSurface
operator|==
name|EGL_NO_SURFACE
condition|)
block|{
operator|delete
name|d
operator|->
name|eglContext
expr_stmt|;
name|d
operator|->
name|eglContext
operator|=
literal|0
expr_stmt|;
return|return
literal|false
return|;
block|}
return|return
literal|true
return|;
block|}
end_function
begin_function
DECL|function|event
name|bool
name|QGLWidget
operator|::
name|event
parameter_list|(
name|QEvent
modifier|*
name|e
parameter_list|)
block|{
return|return
name|QWidget
operator|::
name|event
argument_list|(
name|e
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|resizeEvent
name|void
name|QGLWidget
operator|::
name|resizeEvent
parameter_list|(
name|QResizeEvent
modifier|*
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QGLWidget
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|isValid
argument_list|()
condition|)
return|return;
name|makeCurrent
argument_list|()
expr_stmt|;
if|if
condition|(
operator|!
name|d
operator|->
name|glcx
operator|->
name|initialized
argument_list|()
condition|)
name|glInit
argument_list|()
expr_stmt|;
name|resizeGL
argument_list|(
name|width
argument_list|()
argument_list|,
name|height
argument_list|()
argument_list|)
expr_stmt|;
comment|//handle overlay
block|}
end_function
begin_function
DECL|function|overlayContext
specifier|const
name|QGLContext
modifier|*
name|QGLWidget
operator|::
name|overlayContext
parameter_list|()
specifier|const
block|{
return|return
literal|0
return|;
block|}
end_function
begin_function
DECL|function|makeOverlayCurrent
name|void
name|QGLWidget
operator|::
name|makeOverlayCurrent
parameter_list|()
block|{
comment|//handle overlay
block|}
end_function
begin_function
DECL|function|updateOverlayGL
name|void
name|QGLWidget
operator|::
name|updateOverlayGL
parameter_list|()
block|{
comment|//handle overlay
block|}
end_function
begin_function
DECL|function|setContext
name|void
name|QGLWidget
operator|::
name|setContext
parameter_list|(
name|QGLContext
modifier|*
name|context
parameter_list|,
specifier|const
name|QGLContext
modifier|*
name|shareContext
parameter_list|,
name|bool
name|deleteOldContext
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QGLWidget
argument_list|)
expr_stmt|;
if|if
condition|(
name|context
operator|==
literal|0
condition|)
block|{
name|qWarning
argument_list|(
literal|"QGLWidget::setContext: Cannot set null context"
argument_list|)
expr_stmt|;
return|return;
block|}
if|if
condition|(
name|d
operator|->
name|glcx
condition|)
name|d
operator|->
name|glcx
operator|->
name|doneCurrent
argument_list|()
expr_stmt|;
name|QGLContext
modifier|*
name|oldcx
init|=
name|d
operator|->
name|glcx
decl_stmt|;
name|d
operator|->
name|glcx
operator|=
name|context
expr_stmt|;
if|if
condition|(
operator|!
name|d
operator|->
name|glcx
operator|->
name|isValid
argument_list|()
condition|)
name|d
operator|->
name|glcx
operator|->
name|create
argument_list|(
name|shareContext
condition|?
name|shareContext
else|:
name|oldcx
argument_list|)
expr_stmt|;
if|if
condition|(
name|deleteOldContext
condition|)
operator|delete
name|oldcx
expr_stmt|;
block|}
end_function
begin_function
DECL|function|init
name|void
name|QGLWidgetPrivate
operator|::
name|init
parameter_list|(
name|QGLContext
modifier|*
name|context
parameter_list|,
specifier|const
name|QGLWidget
modifier|*
name|shareWidget
parameter_list|)
block|{
name|Q_Q
argument_list|(
name|QGLWidget
argument_list|)
expr_stmt|;
name|QGLScreen
modifier|*
name|glScreen
init|=
name|glScreenForDevice
argument_list|(
name|q
argument_list|)
decl_stmt|;
if|if
condition|(
name|glScreen
condition|)
block|{
name|wsurf
operator|=
cast|static_cast
argument_list|<
name|QWSGLWindowSurface
operator|*
argument_list|>
argument_list|(
name|glScreen
operator|->
name|createSurface
argument_list|(
name|q
argument_list|)
argument_list|)
expr_stmt|;
name|q
operator|->
name|setWindowSurface
argument_list|(
name|wsurf
argument_list|)
expr_stmt|;
block|}
name|initContext
argument_list|(
name|context
argument_list|,
name|shareWidget
argument_list|)
expr_stmt|;
if|if
condition|(
name|q
operator|->
name|isValid
argument_list|()
operator|&&
name|glcx
operator|->
name|format
argument_list|()
operator|.
name|hasOverlay
argument_list|()
condition|)
block|{
comment|//no overlay
name|qWarning
argument_list|(
literal|"QtOpenGL ES doesn't currently support overlays"
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|cleanupColormaps
name|void
name|QGLWidgetPrivate
operator|::
name|cleanupColormaps
parameter_list|()
block|{ }
end_function
begin_function
DECL|function|colormap
specifier|const
name|QGLColormap
modifier|&
name|QGLWidget
operator|::
name|colormap
parameter_list|()
specifier|const
block|{
return|return
name|d_func
argument_list|()
operator|->
name|cmap
return|;
block|}
end_function
begin_function
DECL|function|setColormap
name|void
name|QGLWidget
operator|::
name|setColormap
parameter_list|(
specifier|const
name|QGLColormap
modifier|&
parameter_list|)
block|{ }
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
