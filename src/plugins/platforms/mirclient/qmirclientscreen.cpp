begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2014 Canonical, Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL3$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPLv3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or later as published by the Free ** Software Foundation and appearing in the file LICENSE.GPL included in ** the packaging of this file. Please review the following information to ** ensure the GNU General Public License version 2.0 requirements will be ** met: http://www.gnu.org/licenses/gpl-2.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<mir_toolkit/mir_client_library.h>
end_include
begin_comment
comment|// Qt
end_comment
begin_include
include|#
directive|include
file|<QCoreApplication>
end_include
begin_include
include|#
directive|include
file|<QtCore/qmath.h>
end_include
begin_include
include|#
directive|include
file|<QScreen>
end_include
begin_include
include|#
directive|include
file|<QThread>
end_include
begin_include
include|#
directive|include
file|<qpa/qwindowsysteminterface.h>
end_include
begin_include
include|#
directive|include
file|<QtPlatformSupport/private/qeglconvenience_p.h>
end_include
begin_comment
comment|// local
end_comment
begin_include
include|#
directive|include
file|"qmirclientscreen.h"
end_include
begin_include
include|#
directive|include
file|"qmirclientlogging.h"
end_include
begin_include
include|#
directive|include
file|"qmirclientorientationchangeevent_p.h"
end_include
begin_include
include|#
directive|include
file|"memory"
end_include
begin_decl_stmt
DECL|variable|kSwapInterval
specifier|static
specifier|const
name|int
name|kSwapInterval
init|=
literal|1
decl_stmt|;
end_decl_stmt
begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|QT_NO_DEBUG
argument_list|)
end_if
begin_function
DECL|function|orientationToStr
specifier|static
specifier|const
name|char
modifier|*
name|orientationToStr
parameter_list|(
name|Qt
operator|::
name|ScreenOrientation
name|orientation
parameter_list|)
block|{
switch|switch
condition|(
name|orientation
condition|)
block|{
case|case
name|Qt
operator|::
name|PrimaryOrientation
case|:
return|return
literal|"primary"
return|;
case|case
name|Qt
operator|::
name|PortraitOrientation
case|:
return|return
literal|"portrait"
return|;
case|case
name|Qt
operator|::
name|LandscapeOrientation
case|:
return|return
literal|"landscape"
return|;
case|case
name|Qt
operator|::
name|InvertedPortraitOrientation
case|:
return|return
literal|"inverted portrait"
return|;
case|case
name|Qt
operator|::
name|InvertedLandscapeOrientation
case|:
return|return
literal|"inverted landscape"
return|;
default|default:
return|return
literal|"INVALID!"
return|;
block|}
block|}
end_function
begin_function
DECL|function|printEglConfig
specifier|static
name|void
name|printEglConfig
parameter_list|(
name|EGLDisplay
name|display
parameter_list|,
name|EGLConfig
name|config
parameter_list|)
block|{
name|DASSERT
argument_list|(
name|display
operator|!=
name|EGL_NO_DISPLAY
argument_list|)
expr_stmt|;
name|DASSERT
argument_list|(
name|config
operator|!=
literal|nullptr
argument_list|)
expr_stmt|;
specifier|static
specifier|const
struct|struct
block|{
specifier|const
name|EGLint
name|attrib
decl_stmt|;
specifier|const
name|char
modifier|*
name|name
decl_stmt|;
block|}
name|kAttribs
index|[]
init|=
block|{
block|{
name|EGL_BUFFER_SIZE
block|,
literal|"EGL_BUFFER_SIZE"
block|}
block|,
block|{
name|EGL_ALPHA_SIZE
block|,
literal|"EGL_ALPHA_SIZE"
block|}
block|,
block|{
name|EGL_BLUE_SIZE
block|,
literal|"EGL_BLUE_SIZE"
block|}
block|,
block|{
name|EGL_GREEN_SIZE
block|,
literal|"EGL_GREEN_SIZE"
block|}
block|,
block|{
name|EGL_RED_SIZE
block|,
literal|"EGL_RED_SIZE"
block|}
block|,
block|{
name|EGL_DEPTH_SIZE
block|,
literal|"EGL_DEPTH_SIZE"
block|}
block|,
block|{
name|EGL_STENCIL_SIZE
block|,
literal|"EGL_STENCIL_SIZE"
block|}
block|,
block|{
name|EGL_CONFIG_CAVEAT
block|,
literal|"EGL_CONFIG_CAVEAT"
block|}
block|,
block|{
name|EGL_CONFIG_ID
block|,
literal|"EGL_CONFIG_ID"
block|}
block|,
block|{
name|EGL_LEVEL
block|,
literal|"EGL_LEVEL"
block|}
block|,
block|{
name|EGL_MAX_PBUFFER_HEIGHT
block|,
literal|"EGL_MAX_PBUFFER_HEIGHT"
block|}
block|,
block|{
name|EGL_MAX_PBUFFER_PIXELS
block|,
literal|"EGL_MAX_PBUFFER_PIXELS"
block|}
block|,
block|{
name|EGL_MAX_PBUFFER_WIDTH
block|,
literal|"EGL_MAX_PBUFFER_WIDTH"
block|}
block|,
block|{
name|EGL_NATIVE_RENDERABLE
block|,
literal|"EGL_NATIVE_RENDERABLE"
block|}
block|,
block|{
name|EGL_NATIVE_VISUAL_ID
block|,
literal|"EGL_NATIVE_VISUAL_ID"
block|}
block|,
block|{
name|EGL_NATIVE_VISUAL_TYPE
block|,
literal|"EGL_NATIVE_VISUAL_TYPE"
block|}
block|,
block|{
name|EGL_SAMPLES
block|,
literal|"EGL_SAMPLES"
block|}
block|,
block|{
name|EGL_SAMPLE_BUFFERS
block|,
literal|"EGL_SAMPLE_BUFFERS"
block|}
block|,
block|{
name|EGL_SURFACE_TYPE
block|,
literal|"EGL_SURFACE_TYPE"
block|}
block|,
block|{
name|EGL_TRANSPARENT_TYPE
block|,
literal|"EGL_TRANSPARENT_TYPE"
block|}
block|,
block|{
name|EGL_TRANSPARENT_BLUE_VALUE
block|,
literal|"EGL_TRANSPARENT_BLUE_VALUE"
block|}
block|,
block|{
name|EGL_TRANSPARENT_GREEN_VALUE
block|,
literal|"EGL_TRANSPARENT_GREEN_VALUE"
block|}
block|,
block|{
name|EGL_TRANSPARENT_RED_VALUE
block|,
literal|"EGL_TRANSPARENT_RED_VALUE"
block|}
block|,
block|{
name|EGL_BIND_TO_TEXTURE_RGB
block|,
literal|"EGL_BIND_TO_TEXTURE_RGB"
block|}
block|,
block|{
name|EGL_BIND_TO_TEXTURE_RGBA
block|,
literal|"EGL_BIND_TO_TEXTURE_RGBA"
block|}
block|,
block|{
name|EGL_MIN_SWAP_INTERVAL
block|,
literal|"EGL_MIN_SWAP_INTERVAL"
block|}
block|,
block|{
name|EGL_MAX_SWAP_INTERVAL
block|,
literal|"EGL_MAX_SWAP_INTERVAL"
block|}
block|,
block|{
operator|-
literal|1
block|,
name|NULL
block|}
block|}
struct|;
specifier|const
name|char
modifier|*
name|string
init|=
name|eglQueryString
argument_list|(
name|display
argument_list|,
name|EGL_VENDOR
argument_list|)
decl_stmt|;
name|LOG
argument_list|(
literal|"EGL vendor: %s"
argument_list|,
name|string
argument_list|)
expr_stmt|;
name|string
operator|=
name|eglQueryString
argument_list|(
name|display
argument_list|,
name|EGL_VERSION
argument_list|)
expr_stmt|;
name|LOG
argument_list|(
literal|"EGL version: %s"
argument_list|,
name|string
argument_list|)
expr_stmt|;
name|string
operator|=
name|eglQueryString
argument_list|(
name|display
argument_list|,
name|EGL_EXTENSIONS
argument_list|)
expr_stmt|;
name|LOG
argument_list|(
literal|"EGL extensions: %s"
argument_list|,
name|string
argument_list|)
expr_stmt|;
name|LOG
argument_list|(
literal|"EGL configuration attibutes:"
argument_list|)
expr_stmt|;
for|for
control|(
name|int
name|index
init|=
literal|0
init|;
name|kAttribs
index|[
name|index
index|]
operator|.
name|attrib
operator|!=
operator|-
literal|1
condition|;
name|index
operator|++
control|)
block|{
name|EGLint
name|value
decl_stmt|;
if|if
condition|(
name|eglGetConfigAttrib
argument_list|(
name|display
argument_list|,
name|config
argument_list|,
name|kAttribs
index|[
name|index
index|]
operator|.
name|attrib
argument_list|,
operator|&
name|value
argument_list|)
condition|)
name|LOG
argument_list|(
literal|"  %s: %d"
argument_list|,
name|kAttribs
index|[
name|index
index|]
operator|.
name|name
argument_list|,
cast|static_cast
argument_list|<
name|int
argument_list|>
argument_list|(
name|value
argument_list|)
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_decl_stmt
DECL|member|mType
specifier|const
name|QEvent
operator|::
name|Type
name|OrientationChangeEvent
operator|::
name|mType
init|=
cast|static_cast
argument_list|<
name|QEvent
operator|::
name|Type
argument_list|>
argument_list|(
name|QEvent
operator|::
name|registerEventType
argument_list|()
argument_list|)
decl_stmt|;
end_decl_stmt
begin_function
DECL|function|find_active_output
specifier|static
specifier|const
name|MirDisplayOutput
modifier|*
name|find_active_output
parameter_list|(
specifier|const
name|MirDisplayConfiguration
modifier|*
name|conf
parameter_list|)
block|{
specifier|const
name|MirDisplayOutput
modifier|*
name|output
init|=
name|NULL
decl_stmt|;
for|for
control|(
name|uint32_t
name|d
init|=
literal|0
init|;
name|d
operator|<
name|conf
operator|->
name|num_outputs
condition|;
name|d
operator|++
control|)
block|{
specifier|const
name|MirDisplayOutput
modifier|*
name|out
init|=
name|conf
operator|->
name|outputs
operator|+
name|d
decl_stmt|;
if|if
condition|(
name|out
operator|->
name|used
operator|&&
name|out
operator|->
name|connected
operator|&&
name|out
operator|->
name|num_modes
operator|&&
name|out
operator|->
name|current_mode
operator|<
name|out
operator|->
name|num_modes
condition|)
block|{
name|output
operator|=
name|out
expr_stmt|;
break|break;
block|}
block|}
return|return
name|output
return|;
block|}
end_function
begin_constructor
DECL|function|QMirClientScreen
name|QMirClientScreen
operator|::
name|QMirClientScreen
parameter_list|(
name|MirConnection
modifier|*
name|connection
parameter_list|)
member_init_list|:
name|mFormat
argument_list|(
name|QImage
operator|::
name|Format_RGB32
argument_list|)
member_init_list|,
name|mDepth
argument_list|(
literal|32
argument_list|)
member_init_list|,
name|mSurfaceFormat
argument_list|()
member_init_list|,
name|mEglDisplay
argument_list|(
name|EGL_NO_DISPLAY
argument_list|)
member_init_list|,
name|mEglConfig
argument_list|(
literal|nullptr
argument_list|)
block|{
comment|// Initialize EGL.
name|ASSERT
argument_list|(
name|eglBindAPI
argument_list|(
name|EGL_OPENGL_ES_API
argument_list|)
operator|==
name|EGL_TRUE
argument_list|)
expr_stmt|;
name|mEglNativeDisplay
operator|=
name|mir_connection_get_egl_native_display
argument_list|(
name|connection
argument_list|)
expr_stmt|;
name|ASSERT
argument_list|(
operator|(
name|mEglDisplay
operator|=
name|eglGetDisplay
argument_list|(
name|mEglNativeDisplay
argument_list|)
operator|)
operator|!=
name|EGL_NO_DISPLAY
argument_list|)
expr_stmt|;
name|ASSERT
argument_list|(
name|eglInitialize
argument_list|(
name|mEglDisplay
argument_list|,
literal|nullptr
argument_list|,
literal|nullptr
argument_list|)
operator|==
name|EGL_TRUE
argument_list|)
expr_stmt|;
comment|// Configure EGL buffers format.
name|mSurfaceFormat
operator|.
name|setRedBufferSize
argument_list|(
literal|8
argument_list|)
expr_stmt|;
name|mSurfaceFormat
operator|.
name|setGreenBufferSize
argument_list|(
literal|8
argument_list|)
expr_stmt|;
name|mSurfaceFormat
operator|.
name|setBlueBufferSize
argument_list|(
literal|8
argument_list|)
expr_stmt|;
name|mSurfaceFormat
operator|.
name|setAlphaBufferSize
argument_list|(
literal|8
argument_list|)
expr_stmt|;
name|mSurfaceFormat
operator|.
name|setDepthBufferSize
argument_list|(
literal|24
argument_list|)
expr_stmt|;
name|mSurfaceFormat
operator|.
name|setStencilBufferSize
argument_list|(
literal|8
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|qEnvironmentVariableIsEmpty
argument_list|(
literal|"QTUBUNTU_MULTISAMPLE"
argument_list|)
condition|)
block|{
name|mSurfaceFormat
operator|.
name|setSamples
argument_list|(
literal|4
argument_list|)
expr_stmt|;
name|DLOG
argument_list|(
literal|"ubuntumirclient: setting MSAA to 4 samples"
argument_list|)
expr_stmt|;
block|}
ifdef|#
directive|ifdef
name|QTUBUNTU_USE_OPENGL
name|mSurfaceFormat
operator|.
name|setRenderableType
argument_list|(
name|QSurfaceFormat
operator|::
name|OpenGL
argument_list|)
expr_stmt|;
else|#
directive|else
name|mSurfaceFormat
operator|.
name|setRenderableType
argument_list|(
name|QSurfaceFormat
operator|::
name|OpenGLES
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|mEglConfig
operator|=
name|q_configFromGLFormat
argument_list|(
name|mEglDisplay
argument_list|,
name|mSurfaceFormat
argument_list|,
literal|true
argument_list|)
expr_stmt|;
if|#
directive|if
operator|!
name|defined
argument_list|(
name|QT_NO_DEBUG
argument_list|)
name|printEglConfig
argument_list|(
name|mEglDisplay
argument_list|,
name|mEglConfig
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|// Set vblank swap interval.
name|int
name|swapInterval
init|=
name|kSwapInterval
decl_stmt|;
name|QByteArray
name|swapIntervalString
init|=
name|qgetenv
argument_list|(
literal|"QTUBUNTU_SWAPINTERVAL"
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|swapIntervalString
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|bool
name|ok
decl_stmt|;
name|swapInterval
operator|=
name|swapIntervalString
operator|.
name|toInt
argument_list|(
operator|&
name|ok
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|ok
condition|)
name|swapInterval
operator|=
name|kSwapInterval
expr_stmt|;
block|}
name|DLOG
argument_list|(
literal|"ubuntumirclient: setting swap interval to %d"
argument_list|,
name|swapInterval
argument_list|)
expr_stmt|;
name|eglSwapInterval
argument_list|(
name|mEglDisplay
argument_list|,
name|swapInterval
argument_list|)
expr_stmt|;
comment|// Get screen resolution.
name|auto
name|configDeleter
init|=
capture|[]
parameter_list|(
name|MirDisplayConfiguration
modifier|*
name|config
parameter_list|)
block|{
name|mir_display_config_destroy
argument_list|(
name|config
argument_list|)
expr_stmt|;
block|}
decl_stmt|;
using|using
name|configUp
init|=
name|std
operator|::
name|unique_ptr
argument_list|<
name|MirDisplayConfiguration
argument_list|,
decltype|decltype
argument_list|(
name|configDeleter
argument_list|)
argument_list|>
using|;
name|configUp
name|displayConfig
argument_list|(
name|mir_connection_create_display_config
argument_list|(
name|connection
argument_list|)
argument_list|,
name|configDeleter
argument_list|)
decl_stmt|;
name|ASSERT
argument_list|(
name|displayConfig
operator|!=
literal|nullptr
argument_list|)
expr_stmt|;
specifier|auto
specifier|const
name|displayOutput
init|=
name|find_active_output
argument_list|(
name|displayConfig
operator|.
name|get
argument_list|()
argument_list|)
decl_stmt|;
name|ASSERT
argument_list|(
name|displayOutput
operator|!=
literal|nullptr
argument_list|)
expr_stmt|;
specifier|const
name|MirDisplayMode
modifier|*
name|mode
init|=
operator|&
name|displayOutput
operator|->
name|modes
index|[
name|displayOutput
operator|->
name|current_mode
index|]
decl_stmt|;
specifier|const
name|int
name|kScreenWidth
init|=
name|mode
operator|->
name|horizontal_resolution
decl_stmt|;
specifier|const
name|int
name|kScreenHeight
init|=
name|mode
operator|->
name|vertical_resolution
decl_stmt|;
name|DASSERT
argument_list|(
name|kScreenWidth
operator|>
literal|0
operator|&&
name|kScreenHeight
operator|>
literal|0
argument_list|)
expr_stmt|;
name|DLOG
argument_list|(
literal|"ubuntumirclient: screen resolution: %dx%d"
argument_list|,
name|kScreenWidth
argument_list|,
name|kScreenHeight
argument_list|)
expr_stmt|;
name|mGeometry
operator|=
name|QRect
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
name|kScreenWidth
argument_list|,
name|kScreenHeight
argument_list|)
expr_stmt|;
name|DLOG
argument_list|(
literal|"QQMirClientScreen::QQMirClientScreen (this=%p)"
argument_list|,
name|this
argument_list|)
expr_stmt|;
comment|// Set the default orientation based on the initial screen dimmensions.
name|mNativeOrientation
operator|=
operator|(
name|mGeometry
operator|.
name|width
argument_list|()
operator|>=
name|mGeometry
operator|.
name|height
argument_list|()
operator|)
condition|?
name|Qt
operator|::
name|LandscapeOrientation
else|:
name|Qt
operator|::
name|PortraitOrientation
expr_stmt|;
comment|// If it's a landscape device (i.e. some tablets), start in landscape, otherwise portrait
name|mCurrentOrientation
operator|=
operator|(
name|mNativeOrientation
operator|==
name|Qt
operator|::
name|LandscapeOrientation
operator|)
condition|?
name|Qt
operator|::
name|LandscapeOrientation
else|:
name|Qt
operator|::
name|PortraitOrientation
expr_stmt|;
block|}
end_constructor
begin_destructor
DECL|function|~QMirClientScreen
name|QMirClientScreen
operator|::
name|~
name|QMirClientScreen
parameter_list|()
block|{
name|eglTerminate
argument_list|(
name|mEglDisplay
argument_list|)
expr_stmt|;
block|}
end_destructor
begin_function
DECL|function|customEvent
name|void
name|QMirClientScreen
operator|::
name|customEvent
parameter_list|(
name|QEvent
modifier|*
name|event
parameter_list|)
block|{
name|DASSERT
argument_list|(
name|QThread
operator|::
name|currentThread
argument_list|()
operator|==
name|thread
argument_list|()
argument_list|)
expr_stmt|;
name|OrientationChangeEvent
modifier|*
name|oReadingEvent
init|=
cast|static_cast
argument_list|<
name|OrientationChangeEvent
operator|*
argument_list|>
argument_list|(
name|event
argument_list|)
decl_stmt|;
switch|switch
condition|(
name|oReadingEvent
operator|->
name|mOrientation
condition|)
block|{
case|case
name|OrientationChangeEvent
operator|::
name|LeftUp
case|:
block|{
name|mCurrentOrientation
operator|=
operator|(
name|screen
argument_list|()
operator|->
name|primaryOrientation
argument_list|()
operator|==
name|Qt
operator|::
name|LandscapeOrientation
operator|)
condition|?
name|Qt
operator|::
name|InvertedPortraitOrientation
else|:
name|Qt
operator|::
name|LandscapeOrientation
expr_stmt|;
break|break;
block|}
case|case
name|OrientationChangeEvent
operator|::
name|TopUp
case|:
block|{
name|mCurrentOrientation
operator|=
operator|(
name|screen
argument_list|()
operator|->
name|primaryOrientation
argument_list|()
operator|==
name|Qt
operator|::
name|LandscapeOrientation
operator|)
condition|?
name|Qt
operator|::
name|LandscapeOrientation
else|:
name|Qt
operator|::
name|PortraitOrientation
expr_stmt|;
break|break;
block|}
case|case
name|OrientationChangeEvent
operator|::
name|RightUp
case|:
block|{
name|mCurrentOrientation
operator|=
operator|(
name|screen
argument_list|()
operator|->
name|primaryOrientation
argument_list|()
operator|==
name|Qt
operator|::
name|LandscapeOrientation
operator|)
condition|?
name|Qt
operator|::
name|PortraitOrientation
else|:
name|Qt
operator|::
name|InvertedLandscapeOrientation
expr_stmt|;
break|break;
block|}
case|case
name|OrientationChangeEvent
operator|::
name|TopDown
case|:
block|{
name|mCurrentOrientation
operator|=
operator|(
name|screen
argument_list|()
operator|->
name|primaryOrientation
argument_list|()
operator|==
name|Qt
operator|::
name|LandscapeOrientation
operator|)
condition|?
name|Qt
operator|::
name|InvertedLandscapeOrientation
else|:
name|Qt
operator|::
name|InvertedPortraitOrientation
expr_stmt|;
break|break;
block|}
default|default:
block|{
name|DLOG
argument_list|(
literal|"QMirClientScreen::customEvent - Unknown orientation."
argument_list|)
expr_stmt|;
return|return;
block|}
block|}
comment|// Raise the event signal so that client apps know the orientation changed
name|DLOG
argument_list|(
literal|"QMirClientScreen::customEvent - handling orientation change to %s"
argument_list|,
name|orientationToStr
argument_list|(
name|mCurrentOrientation
argument_list|)
argument_list|)
expr_stmt|;
name|QWindowSystemInterface
operator|::
name|handleScreenOrientationChange
argument_list|(
name|screen
argument_list|()
argument_list|,
name|mCurrentOrientation
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|handleWindowSurfaceResize
name|void
name|QMirClientScreen
operator|::
name|handleWindowSurfaceResize
parameter_list|(
name|int
name|windowWidth
parameter_list|,
name|int
name|windowHeight
parameter_list|)
block|{
if|if
condition|(
operator|(
name|windowWidth
operator|>
name|windowHeight
operator|&&
name|mGeometry
operator|.
name|width
argument_list|()
operator|<
name|mGeometry
operator|.
name|height
argument_list|()
operator|)
operator|||
operator|(
name|windowWidth
argument_list|<
name|windowHeight
operator|&&
name|mGeometry
operator|.
name|width
operator|(
operator|)
argument_list|>
name|mGeometry
operator|.
name|height
argument_list|()
operator|)
condition|)
block|{
comment|// The window aspect ratio differ's from the screen one. This means that
comment|// unity8 has rotated the window in its scene.
comment|// As there's no way to express window rotation in Qt's API, we have
comment|// Flip QScreen's dimensions so that orientation properties match
comment|// (primaryOrientation particularly).
comment|// FIXME: This assumes a phone scenario. Won't work, or make sense,
comment|//        on the desktop
name|QRect
name|currGeometry
init|=
name|mGeometry
decl_stmt|;
name|mGeometry
operator|.
name|setWidth
argument_list|(
name|currGeometry
operator|.
name|height
argument_list|()
argument_list|)
expr_stmt|;
name|mGeometry
operator|.
name|setHeight
argument_list|(
name|currGeometry
operator|.
name|width
argument_list|()
argument_list|)
expr_stmt|;
name|DLOG
argument_list|(
literal|"QMirClientScreen::handleWindowSurfaceResize - new screen geometry (w=%d, h=%d)"
argument_list|,
name|mGeometry
operator|.
name|width
argument_list|()
argument_list|,
name|mGeometry
operator|.
name|height
argument_list|()
argument_list|)
expr_stmt|;
name|QWindowSystemInterface
operator|::
name|handleScreenGeometryChange
argument_list|(
name|screen
argument_list|()
argument_list|,
name|mGeometry
comment|/* newGeometry */
argument_list|,
name|mGeometry
comment|/* newAvailableGeometry */
argument_list|)
expr_stmt|;
if|if
condition|(
name|mGeometry
operator|.
name|width
argument_list|()
operator|<
name|mGeometry
operator|.
name|height
argument_list|()
condition|)
block|{
name|mCurrentOrientation
operator|=
name|Qt
operator|::
name|PortraitOrientation
expr_stmt|;
block|}
else|else
block|{
name|mCurrentOrientation
operator|=
name|Qt
operator|::
name|LandscapeOrientation
expr_stmt|;
block|}
name|DLOG
argument_list|(
literal|"QMirClientScreen::handleWindowSurfaceResize - new orientation %s"
argument_list|,
name|orientationToStr
argument_list|(
name|mCurrentOrientation
argument_list|)
argument_list|)
expr_stmt|;
name|QWindowSystemInterface
operator|::
name|handleScreenOrientationChange
argument_list|(
name|screen
argument_list|()
argument_list|,
name|mCurrentOrientation
argument_list|)
expr_stmt|;
block|}
block|}
end_function
end_unit
