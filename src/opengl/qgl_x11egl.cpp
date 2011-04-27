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
file|<private/qt_x11_p.h>
end_include
begin_include
include|#
directive|include
file|<private/qpixmap_x11_p.h>
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
file|"qgl_egl_p.h"
end_include
begin_include
include|#
directive|include
file|"qcolormap.h"
end_include
begin_include
include|#
directive|include
file|<QDebug>
end_include
begin_include
include|#
directive|include
file|<QPixmap>
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_comment
comment|/*     QGLTemporaryContext implementation */
end_comment
begin_class
DECL|class|QGLTemporaryContextPrivate
class|class
name|QGLTemporaryContextPrivate
block|{
public|public:
DECL|member|initialized
name|bool
name|initialized
decl_stmt|;
DECL|member|window
name|Window
name|window
decl_stmt|;
DECL|member|context
name|EGLContext
name|context
decl_stmt|;
DECL|member|surface
name|EGLSurface
name|surface
decl_stmt|;
DECL|member|display
name|EGLDisplay
name|display
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
name|initialized
operator|=
literal|false
expr_stmt|;
name|d
operator|->
name|window
operator|=
literal|0
expr_stmt|;
name|d
operator|->
name|context
operator|=
literal|0
expr_stmt|;
name|d
operator|->
name|surface
operator|=
literal|0
expr_stmt|;
name|int
name|screen
init|=
literal|0
decl_stmt|;
name|d
operator|->
name|display
operator|=
name|QEgl
operator|::
name|display
argument_list|()
expr_stmt|;
name|EGLConfig
name|config
decl_stmt|;
name|int
name|numConfigs
init|=
literal|0
decl_stmt|;
name|EGLint
name|attribs
index|[]
init|=
block|{
name|EGL_SURFACE_TYPE
block|,
name|EGL_WINDOW_BIT
block|,
ifdef|#
directive|ifdef
name|QT_OPENGL_ES_2
name|EGL_RENDERABLE_TYPE
block|,
name|EGL_OPENGL_ES2_BIT
block|,
endif|#
directive|endif
name|EGL_NONE
block|}
decl_stmt|;
name|eglChooseConfig
argument_list|(
name|d
operator|->
name|display
argument_list|,
name|attribs
argument_list|,
operator|&
name|config
argument_list|,
literal|1
argument_list|,
operator|&
name|numConfigs
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|numConfigs
condition|)
block|{
name|qWarning
argument_list|(
literal|"QGLTemporaryContext: No EGL configurations available."
argument_list|)
expr_stmt|;
return|return;
block|}
name|XVisualInfo
name|visualInfo
decl_stmt|;
name|XVisualInfo
modifier|*
name|vi
decl_stmt|;
name|int
name|numVisuals
decl_stmt|;
name|visualInfo
operator|.
name|visualid
operator|=
name|QEgl
operator|::
name|getCompatibleVisualId
argument_list|(
name|config
argument_list|)
expr_stmt|;
name|vi
operator|=
name|XGetVisualInfo
argument_list|(
name|X11
operator|->
name|display
argument_list|,
name|VisualIDMask
argument_list|,
operator|&
name|visualInfo
argument_list|,
operator|&
name|numVisuals
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|vi
operator|||
name|numVisuals
operator|<
literal|1
condition|)
block|{
name|qWarning
argument_list|(
literal|"QGLTemporaryContext: Unable to get X11 visual info id."
argument_list|)
expr_stmt|;
return|return;
block|}
name|XSetWindowAttributes
name|attr
decl_stmt|;
name|unsigned
name|long
name|mask
decl_stmt|;
name|attr
operator|.
name|background_pixel
operator|=
literal|0
expr_stmt|;
name|attr
operator|.
name|border_pixel
operator|=
literal|0
expr_stmt|;
name|attr
operator|.
name|colormap
operator|=
name|XCreateColormap
argument_list|(
name|X11
operator|->
name|display
argument_list|,
name|DefaultRootWindow
argument_list|(
name|X11
operator|->
name|display
argument_list|)
argument_list|,
name|vi
operator|->
name|visual
argument_list|,
name|AllocNone
argument_list|)
expr_stmt|;
name|attr
operator|.
name|event_mask
operator|=
name|StructureNotifyMask
operator||
name|ExposureMask
expr_stmt|;
name|mask
operator|=
name|CWBackPixel
operator||
name|CWBorderPixel
operator||
name|CWColormap
operator||
name|CWEventMask
expr_stmt|;
name|d
operator|->
name|window
operator|=
name|XCreateWindow
argument_list|(
name|X11
operator|->
name|display
argument_list|,
name|RootWindow
argument_list|(
name|X11
operator|->
name|display
argument_list|,
name|screen
argument_list|)
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|,
literal|0
argument_list|,
name|vi
operator|->
name|depth
argument_list|,
name|InputOutput
argument_list|,
name|vi
operator|->
name|visual
argument_list|,
name|mask
argument_list|,
operator|&
name|attr
argument_list|)
expr_stmt|;
name|d
operator|->
name|surface
operator|=
name|eglCreateWindowSurface
argument_list|(
name|d
operator|->
name|display
argument_list|,
name|config
argument_list|,
operator|(
name|EGLNativeWindowType
operator|)
name|d
operator|->
name|window
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
if|if
condition|(
name|d
operator|->
name|surface
operator|==
name|EGL_NO_SURFACE
condition|)
block|{
name|qWarning
argument_list|(
literal|"QGLTemporaryContext: Error creating EGL surface."
argument_list|)
expr_stmt|;
name|XFree
argument_list|(
name|vi
argument_list|)
expr_stmt|;
name|XDestroyWindow
argument_list|(
name|X11
operator|->
name|display
argument_list|,
name|d
operator|->
name|window
argument_list|)
expr_stmt|;
return|return;
block|}
name|EGLint
name|contextAttribs
index|[]
init|=
block|{
ifdef|#
directive|ifdef
name|QT_OPENGL_ES_2
name|EGL_CONTEXT_CLIENT_VERSION
block|,
literal|2
block|,
endif|#
directive|endif
name|EGL_NONE
block|}
decl_stmt|;
name|d
operator|->
name|context
operator|=
name|eglCreateContext
argument_list|(
name|d
operator|->
name|display
argument_list|,
name|config
argument_list|,
literal|0
argument_list|,
name|contextAttribs
argument_list|)
expr_stmt|;
if|if
condition|(
name|d
operator|->
name|context
operator|!=
name|EGL_NO_CONTEXT
operator|&&
name|eglMakeCurrent
argument_list|(
name|d
operator|->
name|display
argument_list|,
name|d
operator|->
name|surface
argument_list|,
name|d
operator|->
name|surface
argument_list|,
name|d
operator|->
name|context
argument_list|)
condition|)
block|{
name|d
operator|->
name|initialized
operator|=
literal|true
expr_stmt|;
block|}
else|else
block|{
name|qWarning
argument_list|(
literal|"QGLTemporaryContext: Error creating EGL context."
argument_list|)
expr_stmt|;
name|eglDestroySurface
argument_list|(
name|d
operator|->
name|display
argument_list|,
name|d
operator|->
name|surface
argument_list|)
expr_stmt|;
name|XDestroyWindow
argument_list|(
name|X11
operator|->
name|display
argument_list|,
name|d
operator|->
name|window
argument_list|)
expr_stmt|;
block|}
name|XFree
argument_list|(
name|vi
argument_list|)
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
if|if
condition|(
name|d
operator|->
name|initialized
condition|)
block|{
name|eglMakeCurrent
argument_list|(
name|d
operator|->
name|display
argument_list|,
name|EGL_NO_SURFACE
argument_list|,
name|EGL_NO_SURFACE
argument_list|,
name|EGL_NO_CONTEXT
argument_list|)
expr_stmt|;
name|eglDestroyContext
argument_list|(
name|d
operator|->
name|display
argument_list|,
name|d
operator|->
name|context
argument_list|)
expr_stmt|;
name|eglDestroySurface
argument_list|(
name|d
operator|->
name|display
argument_list|,
name|d
operator|->
name|surface
argument_list|)
expr_stmt|;
name|XDestroyWindow
argument_list|(
name|X11
operator|->
name|display
argument_list|,
name|d
operator|->
name|window
argument_list|)
expr_stmt|;
block|}
block|}
end_destructor
begin_function
DECL|function|hasOpenGLOverlays
name|bool
name|QGLFormat
operator|::
name|hasOpenGLOverlays
parameter_list|()
block|{
return|return
literal|false
return|;
block|}
end_function
begin_comment
comment|// Chooses the EGL config and creates the EGL context
end_comment
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
name|QX11PixmapData
modifier|*
name|x11PixmapData
init|=
literal|0
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
name|QPixmapData
modifier|*
name|pmd
init|=
cast|static_cast
argument_list|<
name|QPixmap
operator|*
argument_list|>
argument_list|(
name|device
argument_list|()
argument_list|)
operator|->
name|data_ptr
argument_list|()
operator|.
name|data
argument_list|()
decl_stmt|;
if|if
condition|(
name|pmd
operator|->
name|classId
argument_list|()
operator|==
name|QPixmapData
operator|::
name|X11Class
condition|)
name|x11PixmapData
operator|=
cast|static_cast
argument_list|<
name|QX11PixmapData
operator|*
argument_list|>
argument_list|(
name|pmd
argument_list|)
expr_stmt|;
else|else
block|{
comment|// TODO: Replace the pixmap's data with a new QX11PixmapData
name|qWarning
argument_list|(
literal|"WARNING: Creating a QGLContext on a QPixmap is only supported for X11 pixmap backend"
argument_list|)
expr_stmt|;
return|return
literal|false
return|;
block|}
block|}
elseif|else
if|if
condition|(
operator|(
name|devType
operator|!=
name|QInternal
operator|::
name|Widget
operator|)
operator|&&
operator|(
name|devType
operator|!=
name|QInternal
operator|::
name|Pbuffer
operator|)
condition|)
block|{
name|qWarning
argument_list|(
literal|"WARNING: Creating a QGLContext not supported on device type %d"
argument_list|,
name|devType
argument_list|)
expr_stmt|;
return|return
literal|false
return|;
block|}
comment|// Only create the eglContext if we don't already have one:
if|if
condition|(
name|d
operator|->
name|eglContext
operator|==
literal|0
condition|)
block|{
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
comment|// If the device is a widget with WA_TranslucentBackground set, make sure the glFormat
comment|// has the alpha channel option set:
if|if
condition|(
name|devType
operator|==
name|QInternal
operator|::
name|Widget
condition|)
block|{
name|QWidget
modifier|*
name|widget
init|=
cast|static_cast
argument_list|<
name|QWidget
operator|*
argument_list|>
argument_list|(
name|device
argument_list|()
argument_list|)
decl_stmt|;
if|if
condition|(
name|widget
operator|->
name|testAttribute
argument_list|(
name|Qt
operator|::
name|WA_TranslucentBackground
argument_list|)
condition|)
name|d
operator|->
name|glFormat
operator|.
name|setAlpha
argument_list|(
literal|true
argument_list|)
expr_stmt|;
block|}
comment|// Construct the configuration we need for this surface.
name|QEglProperties
name|configProps
decl_stmt|;
name|configProps
operator|.
name|setDeviceType
argument_list|(
name|devType
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
name|qt_eglproperties_set_glformat
argument_list|(
name|configProps
argument_list|,
name|d
operator|->
name|glFormat
argument_list|)
expr_stmt|;
comment|// Set buffer preserved for regular QWidgets, QGLWidgets are ok with either preserved or destroyed:
if|if
condition|(
operator|(
name|devType
operator|==
name|QInternal
operator|::
name|Widget
operator|)
operator|&&
name|qobject_cast
argument_list|<
name|QGLWidget
operator|*
argument_list|>
argument_list|(
cast|static_cast
argument_list|<
name|QWidget
operator|*
argument_list|>
argument_list|(
name|device
argument_list|()
argument_list|)
argument_list|)
operator|==
literal|0
condition|)
name|configProps
operator|.
name|setValue
argument_list|(
name|EGL_SWAP_BEHAVIOR
argument_list|,
name|EGL_BUFFER_PRESERVED
argument_list|)
expr_stmt|;
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
argument_list|,
name|QEgl
operator|::
name|BestPixelFormat
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
comment|// Create a new context for the configuration.
name|QEglContext
modifier|*
name|eglSharedContext
init|=
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
decl_stmt|;
if|if
condition|(
operator|!
name|d
operator|->
name|eglContext
operator|->
name|createContext
argument_list|(
name|eglSharedContext
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
block|}
comment|// Inform the higher layers about the actual format properties
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
comment|// Do don't create the EGLSurface for everything.
comment|//    QWidget - yes, create the EGLSurface and store it in QGLContextPrivate::eglSurface
comment|//    QGLWidget - yes, create the EGLSurface and store it in QGLContextPrivate::eglSurface
comment|//    QPixmap - yes, create the EGLSurface but store it in QX11PixmapData::gl_surface
comment|//    QGLPixelBuffer - no, it creates the surface itself and stores it in QGLPixelBufferPrivate::pbuf
if|if
condition|(
name|devType
operator|==
name|QInternal
operator|::
name|Widget
condition|)
block|{
if|if
condition|(
name|d
operator|->
name|eglSurface
operator|!=
name|EGL_NO_SURFACE
condition|)
name|eglDestroySurface
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
name|eglSurface
argument_list|)
expr_stmt|;
comment|// extraWindowSurfaceCreationProps default to NULL unless were specifically set before
name|d
operator|->
name|eglSurface
operator|=
name|QEgl
operator|::
name|createSurface
argument_list|(
name|device
argument_list|()
argument_list|,
name|d
operator|->
name|eglContext
operator|->
name|config
argument_list|()
argument_list|,
name|d
operator|->
name|extraWindowSurfaceCreationProps
argument_list|)
expr_stmt|;
name|XFlush
argument_list|(
name|X11
operator|->
name|display
argument_list|)
expr_stmt|;
name|setWindowCreated
argument_list|(
literal|true
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|x11PixmapData
condition|)
block|{
comment|// TODO: Actually check to see if the existing surface can be re-used
if|if
condition|(
name|x11PixmapData
operator|->
name|gl_surface
condition|)
name|eglDestroySurface
argument_list|(
name|d
operator|->
name|eglContext
operator|->
name|display
argument_list|()
argument_list|,
operator|(
name|EGLSurface
operator|)
name|x11PixmapData
operator|->
name|gl_surface
argument_list|)
expr_stmt|;
name|x11PixmapData
operator|->
name|gl_surface
operator|=
operator|(
name|void
operator|*
operator|)
name|QEgl
operator|::
name|createSurface
argument_list|(
name|device
argument_list|()
argument_list|,
name|d
operator|->
name|eglContext
operator|->
name|config
argument_list|()
argument_list|)
expr_stmt|;
block|}
return|return
literal|true
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
operator|!
name|context
operator|->
name|deviceIsPixmap
argument_list|()
operator|&&
name|context
operator|->
name|device
argument_list|()
operator|!=
name|this
condition|)
block|{
name|qWarning
argument_list|(
literal|"QGLWidget::setContext: Context must refer to this widget"
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
name|bool
name|createFailed
init|=
literal|false
decl_stmt|;
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
block|{
comment|// Create the QGLContext here, which in turn chooses the EGL config
comment|// and creates the EGL context:
if|if
condition|(
operator|!
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
condition|)
name|createFailed
operator|=
literal|true
expr_stmt|;
block|}
if|if
condition|(
name|createFailed
condition|)
block|{
if|if
condition|(
name|deleteOldContext
condition|)
operator|delete
name|oldcx
expr_stmt|;
return|return;
block|}
name|d
operator|->
name|eglSurfaceWindowId
operator|=
name|winId
argument_list|()
expr_stmt|;
comment|// Remember the window id we created the surface for
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
begin_comment
comment|// Re-creates the EGL surface if the window ID has changed or if there isn't a surface
end_comment
begin_function
DECL|function|recreateEglSurface
name|void
name|QGLWidgetPrivate
operator|::
name|recreateEglSurface
parameter_list|()
block|{
name|Q_Q
argument_list|(
name|QGLWidget
argument_list|)
expr_stmt|;
name|Window
name|currentId
init|=
name|q
operator|->
name|winId
argument_list|()
decl_stmt|;
comment|// If the window ID has changed since the surface was created, we need to delete the
comment|// old surface before re-creating a new one. Note: This should not be the case as the
comment|// surface should be deleted before the old window id.
if|if
condition|(
name|glcx
operator|->
name|d_func
argument_list|()
operator|->
name|eglSurface
operator|!=
name|EGL_NO_SURFACE
operator|&&
operator|(
name|currentId
operator|!=
name|eglSurfaceWindowId
operator|)
condition|)
block|{
name|qWarning
argument_list|(
literal|"EGL surface for deleted window %lx was not destroyed"
argument_list|,
name|uint
argument_list|(
name|eglSurfaceWindowId
argument_list|)
argument_list|)
expr_stmt|;
name|glcx
operator|->
name|d_func
argument_list|()
operator|->
name|destroyEglSurfaceForDevice
argument_list|()
expr_stmt|;
block|}
if|if
condition|(
name|glcx
operator|->
name|d_func
argument_list|()
operator|->
name|eglSurface
operator|==
name|EGL_NO_SURFACE
condition|)
block|{
name|glcx
operator|->
name|d_func
argument_list|()
operator|->
name|eglSurface
operator|=
name|glcx
operator|->
name|d_func
argument_list|()
operator|->
name|eglContext
operator|->
name|createSurface
argument_list|(
name|q
argument_list|)
expr_stmt|;
name|eglSurfaceWindowId
operator|=
name|currentId
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|bindTextureFromNativePixmap
name|QGLTexture
modifier|*
name|QGLContextPrivate
operator|::
name|bindTextureFromNativePixmap
parameter_list|(
name|QPixmap
modifier|*
name|pixmap
parameter_list|,
specifier|const
name|qint64
name|key
parameter_list|,
name|QGLContext
operator|::
name|BindOptions
name|options
parameter_list|)
block|{
name|Q_Q
argument_list|(
name|QGLContext
argument_list|)
expr_stmt|;
comment|// The EGL texture_from_pixmap has no facility to invert the y coordinate
if|if
condition|(
operator|!
operator|(
name|options
operator|&
name|QGLContext
operator|::
name|CanFlipNativePixmapBindOption
operator|)
condition|)
return|return
literal|0
return|;
specifier|static
name|bool
name|checkedForTFP
init|=
literal|false
decl_stmt|;
specifier|static
name|bool
name|haveTFP
init|=
literal|false
decl_stmt|;
specifier|static
name|bool
name|checkedForEglImageTFP
init|=
literal|false
decl_stmt|;
specifier|static
name|bool
name|haveEglImageTFP
init|=
literal|false
decl_stmt|;
if|if
condition|(
operator|!
name|checkedForEglImageTFP
condition|)
block|{
name|checkedForEglImageTFP
operator|=
literal|true
expr_stmt|;
comment|// We need to be able to create an EGLImage from a native pixmap, which was split
comment|// into a separate EGL extension, EGL_KHR_image_pixmap. It is possible to have
comment|// eglCreateImageKHR& eglDestroyImageKHR without support for pixmaps, so we must
comment|// check we have the EGLImage from pixmap functionality.
if|if
condition|(
name|QEgl
operator|::
name|hasExtension
argument_list|(
literal|"EGL_KHR_image"
argument_list|)
operator|||
name|QEgl
operator|::
name|hasExtension
argument_list|(
literal|"EGL_KHR_image_pixmap"
argument_list|)
condition|)
block|{
comment|// Being able to create an EGLImage from a native pixmap is also pretty useless
comment|// without the ability to bind that EGLImage as a texture, which is provided by
comment|// the GL_OES_EGL_image extension, which we try to resolve here:
name|haveEglImageTFP
operator|=
name|qt_resolve_eglimage_gl_extensions
argument_list|(
name|q
argument_list|)
expr_stmt|;
if|if
condition|(
name|haveEglImageTFP
condition|)
name|qDebug
argument_list|(
literal|"Found EGL_KHR_image_pixmap& GL_OES_EGL_image extensions (preferred method)!"
argument_list|)
expr_stmt|;
block|}
block|}
if|if
condition|(
operator|!
name|checkedForTFP
condition|)
block|{
comment|// Check for texture_from_pixmap egl extension
name|checkedForTFP
operator|=
literal|true
expr_stmt|;
if|if
condition|(
name|QEgl
operator|::
name|hasExtension
argument_list|(
literal|"EGL_NOKIA_texture_from_pixmap"
argument_list|)
operator|||
name|QEgl
operator|::
name|hasExtension
argument_list|(
literal|"EGL_EXT_texture_from_pixmap"
argument_list|)
condition|)
block|{
name|qDebug
argument_list|(
literal|"Found texture_from_pixmap EGL extension!"
argument_list|)
expr_stmt|;
name|haveTFP
operator|=
literal|true
expr_stmt|;
block|}
block|}
if|if
condition|(
operator|!
name|haveTFP
operator|&&
operator|!
name|haveEglImageTFP
condition|)
return|return
literal|0
return|;
name|QX11PixmapData
modifier|*
name|pixmapData
init|=
cast|static_cast
argument_list|<
name|QX11PixmapData
operator|*
argument_list|>
argument_list|(
name|pixmap
operator|->
name|data_ptr
argument_list|()
operator|.
name|data
argument_list|()
argument_list|)
decl_stmt|;
name|Q_ASSERT
argument_list|(
name|pixmapData
operator|->
name|classId
argument_list|()
operator|==
name|QPixmapData
operator|::
name|X11Class
argument_list|)
expr_stmt|;
name|bool
name|hasAlpha
init|=
name|pixmapData
operator|->
name|hasAlphaChannel
argument_list|()
decl_stmt|;
name|bool
name|pixmapHasValidSurface
init|=
literal|false
decl_stmt|;
name|bool
name|textureIsBound
init|=
literal|false
decl_stmt|;
name|GLuint
name|textureId
decl_stmt|;
name|glGenTextures
argument_list|(
literal|1
argument_list|,
operator|&
name|textureId
argument_list|)
expr_stmt|;
name|glBindTexture
argument_list|(
name|GL_TEXTURE_2D
argument_list|,
name|textureId
argument_list|)
expr_stmt|;
if|if
condition|(
name|haveTFP
operator|&&
name|pixmapData
operator|->
name|gl_surface
operator|&&
name|hasAlpha
operator|==
operator|(
name|pixmapData
operator|->
name|flags
operator|&
name|QX11PixmapData
operator|::
name|GlSurfaceCreatedWithAlpha
operator|)
condition|)
block|{
name|pixmapHasValidSurface
operator|=
literal|true
expr_stmt|;
block|}
comment|// If we already have a valid EGL surface for the pixmap, we should use it
if|if
condition|(
name|pixmapHasValidSurface
condition|)
block|{
name|EGLBoolean
name|success
decl_stmt|;
name|success
operator|=
name|eglBindTexImage
argument_list|(
name|QEgl
operator|::
name|display
argument_list|()
argument_list|,
operator|(
name|EGLSurface
operator|)
name|pixmapData
operator|->
name|gl_surface
argument_list|,
name|EGL_BACK_BUFFER
argument_list|)
expr_stmt|;
if|if
condition|(
name|success
operator|==
name|EGL_FALSE
condition|)
block|{
name|qWarning
argument_list|()
operator|<<
literal|"eglBindTexImage() failed:"
operator|<<
name|QEgl
operator|::
name|errorString
argument_list|()
expr_stmt|;
name|eglDestroySurface
argument_list|(
name|QEgl
operator|::
name|display
argument_list|()
argument_list|,
operator|(
name|EGLSurface
operator|)
name|pixmapData
operator|->
name|gl_surface
argument_list|)
expr_stmt|;
name|pixmapData
operator|->
name|gl_surface
operator|=
operator|(
name|void
operator|*
operator|)
name|EGL_NO_SURFACE
expr_stmt|;
block|}
else|else
name|textureIsBound
operator|=
literal|true
expr_stmt|;
block|}
comment|// If the pixmap doesn't already have a valid surface, try binding it via EGLImage
comment|// first, as going through EGLImage should be faster and better supported:
if|if
condition|(
operator|!
name|textureIsBound
operator|&&
name|haveEglImageTFP
condition|)
block|{
name|EGLImageKHR
name|eglImage
decl_stmt|;
name|EGLint
name|attribs
index|[]
init|=
block|{
name|EGL_IMAGE_PRESERVED_KHR
block|,
name|EGL_TRUE
block|,
name|EGL_NONE
block|}
decl_stmt|;
name|eglImage
operator|=
name|QEgl
operator|::
name|eglCreateImageKHR
argument_list|(
name|QEgl
operator|::
name|display
argument_list|()
argument_list|,
name|EGL_NO_CONTEXT
argument_list|,
name|EGL_NATIVE_PIXMAP_KHR
argument_list|,
operator|(
name|EGLClientBuffer
operator|)
name|QEgl
operator|::
name|nativePixmap
argument_list|(
name|pixmap
argument_list|)
argument_list|,
name|attribs
argument_list|)
expr_stmt|;
name|QGLContext
modifier|*
name|ctx
init|=
name|q
decl_stmt|;
name|glEGLImageTargetTexture2DOES
argument_list|(
name|GL_TEXTURE_2D
argument_list|,
name|eglImage
argument_list|)
expr_stmt|;
name|GLint
name|err
init|=
name|glGetError
argument_list|()
decl_stmt|;
if|if
condition|(
name|err
operator|==
name|GL_NO_ERROR
condition|)
name|textureIsBound
operator|=
literal|true
expr_stmt|;
comment|// Once the egl image is bound, the texture becomes a new sibling image and we can safely
comment|// destroy the EGLImage we created for the pixmap:
if|if
condition|(
name|eglImage
operator|!=
name|EGL_NO_IMAGE_KHR
condition|)
name|QEgl
operator|::
name|eglDestroyImageKHR
argument_list|(
name|QEgl
operator|::
name|display
argument_list|()
argument_list|,
name|eglImage
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
operator|!
name|textureIsBound
operator|&&
name|haveTFP
condition|)
block|{
comment|// Check to see if the surface is still valid
if|if
condition|(
name|pixmapData
operator|->
name|gl_surface
operator|&&
name|hasAlpha
operator|!=
operator|(
name|pixmapData
operator|->
name|flags
operator|&
name|QX11PixmapData
operator|::
name|GlSurfaceCreatedWithAlpha
operator|)
condition|)
block|{
comment|// Surface is invalid!
name|destroyGlSurfaceForPixmap
argument_list|(
name|pixmapData
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|pixmapData
operator|->
name|gl_surface
operator|==
literal|0
condition|)
block|{
name|EGLConfig
name|config
init|=
name|QEgl
operator|::
name|defaultConfig
argument_list|(
name|QInternal
operator|::
name|Pixmap
argument_list|,
name|QEgl
operator|::
name|OpenGL
argument_list|,
name|hasAlpha
condition|?
name|QEgl
operator|::
name|Translucent
else|:
name|QEgl
operator|::
name|NoOptions
argument_list|)
decl_stmt|;
name|pixmapData
operator|->
name|gl_surface
operator|=
operator|(
name|void
operator|*
operator|)
name|QEgl
operator|::
name|createSurface
argument_list|(
name|pixmap
argument_list|,
name|config
argument_list|)
expr_stmt|;
if|if
condition|(
name|pixmapData
operator|->
name|gl_surface
operator|==
operator|(
name|void
operator|*
operator|)
name|EGL_NO_SURFACE
condition|)
return|return
literal|false
return|;
block|}
name|EGLBoolean
name|success
decl_stmt|;
name|success
operator|=
name|eglBindTexImage
argument_list|(
name|QEgl
operator|::
name|display
argument_list|()
argument_list|,
operator|(
name|EGLSurface
operator|)
name|pixmapData
operator|->
name|gl_surface
argument_list|,
name|EGL_BACK_BUFFER
argument_list|)
expr_stmt|;
if|if
condition|(
name|success
operator|==
name|EGL_FALSE
condition|)
block|{
name|qWarning
argument_list|()
operator|<<
literal|"eglBindTexImage() failed:"
operator|<<
name|QEgl
operator|::
name|errorString
argument_list|()
expr_stmt|;
name|eglDestroySurface
argument_list|(
name|QEgl
operator|::
name|display
argument_list|()
argument_list|,
operator|(
name|EGLSurface
operator|)
name|pixmapData
operator|->
name|gl_surface
argument_list|)
expr_stmt|;
name|pixmapData
operator|->
name|gl_surface
operator|=
operator|(
name|void
operator|*
operator|)
name|EGL_NO_SURFACE
expr_stmt|;
name|haveTFP
operator|=
literal|false
expr_stmt|;
comment|// If TFP isn't working, disable it's use
block|}
else|else
name|textureIsBound
operator|=
literal|true
expr_stmt|;
block|}
name|QGLTexture
modifier|*
name|texture
init|=
literal|0
decl_stmt|;
if|if
condition|(
name|textureIsBound
condition|)
block|{
name|texture
operator|=
operator|new
name|QGLTexture
argument_list|(
name|q
argument_list|,
name|textureId
argument_list|,
name|GL_TEXTURE_2D
argument_list|,
name|options
argument_list|)
expr_stmt|;
name|pixmapData
operator|->
name|flags
operator||=
name|QX11PixmapData
operator|::
name|InvertedWhenBoundToTexture
expr_stmt|;
comment|// We assume the cost of bound pixmaps is zero
name|QGLTextureCache
operator|::
name|instance
argument_list|()
operator|->
name|insert
argument_list|(
name|q
argument_list|,
name|key
argument_list|,
name|texture
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|glBindTexture
argument_list|(
name|GL_TEXTURE_2D
argument_list|,
name|textureId
argument_list|)
expr_stmt|;
block|}
else|else
name|glDeleteTextures
argument_list|(
literal|1
argument_list|,
operator|&
name|textureId
argument_list|)
expr_stmt|;
return|return
name|texture
return|;
block|}
end_function
begin_function
DECL|function|destroyGlSurfaceForPixmap
name|void
name|QGLContextPrivate
operator|::
name|destroyGlSurfaceForPixmap
parameter_list|(
name|QPixmapData
modifier|*
name|pmd
parameter_list|)
block|{
name|Q_ASSERT
argument_list|(
name|pmd
operator|->
name|classId
argument_list|()
operator|==
name|QPixmapData
operator|::
name|X11Class
argument_list|)
expr_stmt|;
name|QX11PixmapData
modifier|*
name|pixmapData
init|=
cast|static_cast
argument_list|<
name|QX11PixmapData
operator|*
argument_list|>
argument_list|(
name|pmd
argument_list|)
decl_stmt|;
if|if
condition|(
name|pixmapData
operator|->
name|gl_surface
condition|)
block|{
name|EGLBoolean
name|success
decl_stmt|;
name|success
operator|=
name|eglDestroySurface
argument_list|(
name|QEgl
operator|::
name|display
argument_list|()
argument_list|,
operator|(
name|EGLSurface
operator|)
name|pixmapData
operator|->
name|gl_surface
argument_list|)
expr_stmt|;
if|if
condition|(
name|success
operator|==
name|EGL_FALSE
condition|)
block|{
name|qWarning
argument_list|()
operator|<<
literal|"destroyGlSurfaceForPixmap() - Error deleting surface: "
operator|<<
name|QEgl
operator|::
name|errorString
argument_list|()
expr_stmt|;
block|}
name|pixmapData
operator|->
name|gl_surface
operator|=
literal|0
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|unbindPixmapFromTexture
name|void
name|QGLContextPrivate
operator|::
name|unbindPixmapFromTexture
parameter_list|(
name|QPixmapData
modifier|*
name|pmd
parameter_list|)
block|{
name|Q_ASSERT
argument_list|(
name|pmd
operator|->
name|classId
argument_list|()
operator|==
name|QPixmapData
operator|::
name|X11Class
argument_list|)
expr_stmt|;
name|QX11PixmapData
modifier|*
name|pixmapData
init|=
cast|static_cast
argument_list|<
name|QX11PixmapData
operator|*
argument_list|>
argument_list|(
name|pmd
argument_list|)
decl_stmt|;
if|if
condition|(
name|pixmapData
operator|->
name|gl_surface
condition|)
block|{
name|EGLBoolean
name|success
decl_stmt|;
name|success
operator|=
name|eglReleaseTexImage
argument_list|(
name|QEgl
operator|::
name|display
argument_list|()
argument_list|,
operator|(
name|EGLSurface
operator|)
name|pixmapData
operator|->
name|gl_surface
argument_list|,
name|EGL_BACK_BUFFER
argument_list|)
expr_stmt|;
if|if
condition|(
name|success
operator|==
name|EGL_FALSE
condition|)
block|{
name|qWarning
argument_list|()
operator|<<
literal|"unbindPixmapFromTexture() - Unable to release bound texture: "
operator|<<
name|QEgl
operator|::
name|errorString
argument_list|()
expr_stmt|;
block|}
block|}
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
