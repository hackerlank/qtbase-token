begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the qmake spec of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qeglfshooks.h"
end_include
begin_include
include|#
directive|include
file|<ui/DisplayInfo.h>
end_include
begin_include
include|#
directive|include
file|<ui/FramebufferNativeWindow.h>
end_include
begin_include
include|#
directive|include
file|<fcntl.h>
end_include
begin_include
include|#
directive|include
file|<unistd.h>
end_include
begin_include
include|#
directive|include
file|<linux/fb.h>
end_include
begin_include
include|#
directive|include
file|<sys/ioctl.h>
end_include
begin_if
if|#
directive|if
name|Q_ANDROID_VERSION_MAJOR
operator|>
literal|4
operator|||
operator|(
name|Q_ANDROID_VERSION_MAJOR
operator|==
literal|4
operator|&&
name|Q_ANDROID_VERSION_MINOR
operator|>=
literal|1
operator|)
end_if
begin_include
include|#
directive|include
file|<gui/SurfaceComposerClient.h>
end_include
begin_else
else|#
directive|else
end_else
begin_include
include|#
directive|include
file|<surfaceflinger/SurfaceComposerClient.h>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_using
using|using
namespace|namespace
name|android
namespace|;
end_using
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_class
DECL|class|QEglFSPandaHooks
class|class
name|QEglFSPandaHooks
super|:
specifier|public
name|QEglFSHooks
block|{
public|public:
name|QEglFSPandaHooks
parameter_list|()
constructor_decl|;
specifier|virtual
name|EGLNativeWindowType
name|createNativeWindow
parameter_list|(
specifier|const
name|QSize
modifier|&
name|size
parameter_list|,
specifier|const
name|QSurfaceFormat
modifier|&
name|format
parameter_list|)
function_decl|;
specifier|virtual
name|QSize
name|screenSize
parameter_list|()
specifier|const
function_decl|;
specifier|virtual
name|int
name|screenDepth
parameter_list|()
specifier|const
function_decl|;
specifier|virtual
name|bool
name|filterConfig
parameter_list|(
name|EGLDisplay
name|display
parameter_list|,
name|EGLConfig
name|config
parameter_list|)
specifier|const
function_decl|;
private|private:
name|EGLNativeWindowType
name|createNativeWindowSurfaceFlinger
parameter_list|(
specifier|const
name|QSize
modifier|&
name|size
parameter_list|,
specifier|const
name|QSurfaceFormat
modifier|&
name|format
parameter_list|)
function_decl|;
name|EGLNativeWindowType
name|createNativeWindowFramebuffer
parameter_list|(
specifier|const
name|QSize
modifier|&
name|size
parameter_list|,
specifier|const
name|QSurfaceFormat
modifier|&
name|format
parameter_list|)
function_decl|;
name|void
name|ensureFramebufferNativeWindowCreated
parameter_list|()
function_decl|;
comment|// androidy things
DECL|member|mSession
name|sp
argument_list|<
name|android
operator|::
name|SurfaceComposerClient
argument_list|>
name|mSession
decl_stmt|;
DECL|member|mControl
name|sp
argument_list|<
name|android
operator|::
name|SurfaceControl
argument_list|>
name|mControl
decl_stmt|;
DECL|member|mAndroidSurface
name|sp
argument_list|<
name|android
operator|::
name|Surface
argument_list|>
name|mAndroidSurface
decl_stmt|;
DECL|member|mFramebufferNativeWindow
name|sp
argument_list|<
name|android
operator|::
name|FramebufferNativeWindow
argument_list|>
name|mFramebufferNativeWindow
decl_stmt|;
DECL|member|mFramebufferVisualId
name|EGLint
name|mFramebufferVisualId
decl_stmt|;
DECL|member|mUseFramebuffer
name|bool
name|mUseFramebuffer
decl_stmt|;
block|}
class|;
end_class
begin_constructor
DECL|function|QEglFSPandaHooks
name|QEglFSPandaHooks
operator|::
name|QEglFSPandaHooks
parameter_list|()
member_init_list|:
name|mFramebufferVisualId
argument_list|(
name|EGL_DONT_CARE
argument_list|)
block|{
name|mUseFramebuffer
operator|=
name|qgetenv
argument_list|(
literal|"QT_QPA_EGLFS_NO_SURFACEFLINGER"
argument_list|)
operator|.
name|toInt
argument_list|()
expr_stmt|;
block|}
end_constructor
begin_function
DECL|function|ensureFramebufferNativeWindowCreated
name|void
name|QEglFSPandaHooks
operator|::
name|ensureFramebufferNativeWindowCreated
parameter_list|()
block|{
if|if
condition|(
name|mFramebufferNativeWindow
operator|.
name|get
argument_list|()
condition|)
return|return;
name|mFramebufferNativeWindow
operator|=
operator|new
name|FramebufferNativeWindow
argument_list|()
expr_stmt|;
name|framebuffer_device_t
specifier|const
modifier|*
name|fbDev
init|=
name|mFramebufferNativeWindow
operator|->
name|getDevice
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
name|fbDev
condition|)
name|qFatal
argument_list|(
literal|"Failed to get valid FramebufferNativeWindow, no way to create EGL surfaces"
argument_list|)
expr_stmt|;
name|ANativeWindow
modifier|*
name|window
init|=
name|mFramebufferNativeWindow
operator|.
name|get
argument_list|()
decl_stmt|;
name|window
operator|->
name|query
argument_list|(
name|window
argument_list|,
name|NATIVE_WINDOW_FORMAT
argument_list|,
operator|&
name|mFramebufferVisualId
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|createNativeWindow
name|EGLNativeWindowType
name|QEglFSPandaHooks
operator|::
name|createNativeWindow
parameter_list|(
specifier|const
name|QSize
modifier|&
name|size
parameter_list|,
specifier|const
name|QSurfaceFormat
modifier|&
name|format
parameter_list|)
block|{
return|return
name|mUseFramebuffer
condition|?
name|createNativeWindowFramebuffer
argument_list|(
name|size
argument_list|,
name|format
argument_list|)
else|:
name|createNativeWindowSurfaceFlinger
argument_list|(
name|size
argument_list|,
name|format
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|createNativeWindowFramebuffer
name|EGLNativeWindowType
name|QEglFSPandaHooks
operator|::
name|createNativeWindowFramebuffer
parameter_list|(
specifier|const
name|QSize
modifier|&
name|size
parameter_list|,
specifier|const
name|QSurfaceFormat
modifier|&
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
name|size
argument_list|)
expr_stmt|;
name|ensureFramebufferNativeWindowCreated
argument_list|()
expr_stmt|;
return|return
name|mFramebufferNativeWindow
operator|.
name|get
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|createNativeWindowSurfaceFlinger
name|EGLNativeWindowType
name|QEglFSPandaHooks
operator|::
name|createNativeWindowSurfaceFlinger
parameter_list|(
specifier|const
name|QSize
modifier|&
name|size
parameter_list|,
specifier|const
name|QSurfaceFormat
modifier|&
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
name|size
argument_list|)
expr_stmt|;
name|mSession
operator|=
operator|new
name|SurfaceComposerClient
argument_list|()
expr_stmt|;
name|DisplayInfo
name|dinfo
decl_stmt|;
name|int
name|status
init|=
literal|0
decl_stmt|;
name|status
operator|=
name|mSession
operator|->
name|getDisplayInfo
argument_list|(
literal|0
argument_list|,
operator|&
name|dinfo
argument_list|)
expr_stmt|;
name|mControl
operator|=
name|mSession
operator|->
name|createSurface
argument_list|(
literal|0
argument_list|,
name|dinfo
operator|.
name|w
argument_list|,
name|dinfo
operator|.
name|h
argument_list|,
name|PIXEL_FORMAT_RGB_888
argument_list|)
expr_stmt|;
name|SurfaceComposerClient
operator|::
name|openGlobalTransaction
argument_list|()
expr_stmt|;
name|mControl
operator|->
name|setLayer
argument_list|(
literal|0x40000000
argument_list|)
expr_stmt|;
comment|//    mControl->setAlpha(1);
name|SurfaceComposerClient
operator|::
name|closeGlobalTransaction
argument_list|()
expr_stmt|;
name|mAndroidSurface
operator|=
name|mControl
operator|->
name|getSurface
argument_list|()
expr_stmt|;
name|EGLNativeWindowType
name|eglWindow
init|=
name|mAndroidSurface
operator|.
name|get
argument_list|()
decl_stmt|;
return|return
name|eglWindow
return|;
block|}
end_function
begin_function
DECL|function|filterConfig
name|bool
name|QEglFSPandaHooks
operator|::
name|filterConfig
parameter_list|(
name|EGLDisplay
name|display
parameter_list|,
name|EGLConfig
name|config
parameter_list|)
specifier|const
block|{
if|if
condition|(
operator|!
name|mUseFramebuffer
condition|)
return|return
literal|true
return|;
cast|const_cast
argument_list|<
name|QEglFSPandaHooks
operator|*
argument_list|>
argument_list|(
name|this
argument_list|)
operator|->
name|ensureFramebufferNativeWindowCreated
argument_list|()
expr_stmt|;
if|if
condition|(
name|mFramebufferVisualId
operator|==
name|EGL_DONT_CARE
condition|)
return|return
literal|true
return|;
name|EGLint
name|nativeVisualId
init|=
literal|0
decl_stmt|;
name|eglGetConfigAttrib
argument_list|(
name|display
argument_list|,
name|config
argument_list|,
name|EGL_NATIVE_VISUAL_ID
argument_list|,
operator|&
name|nativeVisualId
argument_list|)
expr_stmt|;
return|return
name|nativeVisualId
operator|==
name|mFramebufferVisualId
return|;
block|}
end_function
begin_function
DECL|function|screenSize
name|QSize
name|QEglFSPandaHooks
operator|::
name|screenSize
parameter_list|()
specifier|const
block|{
specifier|static
name|QSize
name|size
decl_stmt|;
if|if
condition|(
name|size
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|int
name|width
init|=
name|qgetenv
argument_list|(
literal|"QT_QPA_EGLFS_WIDTH"
argument_list|)
operator|.
name|toInt
argument_list|()
decl_stmt|;
name|int
name|height
init|=
name|qgetenv
argument_list|(
literal|"QT_QPA_EGLFS_HEIGHT"
argument_list|)
operator|.
name|toInt
argument_list|()
decl_stmt|;
if|if
condition|(
name|width
operator|&&
name|height
condition|)
block|{
comment|// no need to read fb0
name|size
operator|.
name|setWidth
argument_list|(
name|width
argument_list|)
expr_stmt|;
name|size
operator|.
name|setHeight
argument_list|(
name|height
argument_list|)
expr_stmt|;
return|return
name|size
return|;
block|}
name|struct
name|fb_var_screeninfo
name|vinfo
decl_stmt|;
name|int
name|fd
init|=
name|open
argument_list|(
literal|"/dev/graphics/fb0"
argument_list|,
name|O_RDONLY
argument_list|)
decl_stmt|;
if|if
condition|(
name|fd
operator|!=
operator|-
literal|1
condition|)
block|{
if|if
condition|(
name|ioctl
argument_list|(
name|fd
argument_list|,
name|FBIOGET_VSCREENINFO
argument_list|,
operator|&
name|vinfo
argument_list|)
operator|==
operator|-
literal|1
condition|)
name|qWarning
argument_list|(
literal|"Could not query variable screen info."
argument_list|)
expr_stmt|;
else|else
name|size
operator|=
name|QSize
argument_list|(
name|vinfo
operator|.
name|xres
argument_list|,
name|vinfo
operator|.
name|yres
argument_list|)
expr_stmt|;
name|close
argument_list|(
name|fd
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|qWarning
argument_list|(
literal|"Failed to open /dev/graphics/fb0 to detect screen resolution."
argument_list|)
expr_stmt|;
block|}
comment|// override fb0 from environment var setting
if|if
condition|(
name|width
condition|)
name|size
operator|.
name|setWidth
argument_list|(
name|width
argument_list|)
expr_stmt|;
if|if
condition|(
name|height
condition|)
name|size
operator|.
name|setHeight
argument_list|(
name|height
argument_list|)
expr_stmt|;
block|}
return|return
name|size
return|;
block|}
end_function
begin_function
DECL|function|screenDepth
name|int
name|QEglFSPandaHooks
operator|::
name|screenDepth
parameter_list|()
specifier|const
block|{
specifier|static
name|int
name|depth
init|=
name|qgetenv
argument_list|(
literal|"QT_QPA_EGLFS_DEPTH"
argument_list|)
operator|.
name|toInt
argument_list|()
decl_stmt|;
if|if
condition|(
name|depth
operator|==
literal|0
condition|)
block|{
name|struct
name|fb_var_screeninfo
name|vinfo
decl_stmt|;
name|int
name|fd
init|=
name|open
argument_list|(
literal|"/dev/graphics/fb0"
argument_list|,
name|O_RDONLY
argument_list|)
decl_stmt|;
if|if
condition|(
name|fd
operator|!=
operator|-
literal|1
condition|)
block|{
if|if
condition|(
name|ioctl
argument_list|(
name|fd
argument_list|,
name|FBIOGET_VSCREENINFO
argument_list|,
operator|&
name|vinfo
argument_list|)
operator|==
operator|-
literal|1
condition|)
name|qWarning
argument_list|(
literal|"Could not query variable screen info."
argument_list|)
expr_stmt|;
else|else
name|depth
operator|=
name|vinfo
operator|.
name|bits_per_pixel
expr_stmt|;
name|close
argument_list|(
name|fd
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|qWarning
argument_list|(
literal|"Failed to open /dev/graphics/fb0 to detect screen depth."
argument_list|)
expr_stmt|;
block|}
block|}
return|return
name|depth
operator|==
literal|0
condition|?
literal|32
else|:
name|depth
return|;
block|}
end_function
begin_decl_stmt
DECL|variable|eglFSPandaHooks
specifier|static
name|QEglFSPandaHooks
name|eglFSPandaHooks
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|platformHooks
name|QEglFSHooks
modifier|*
name|platformHooks
init|=
operator|&
name|eglFSPandaHooks
decl_stmt|;
end_decl_stmt
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
