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
file|"qeglfscursor.h"
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
begin_include
include|#
directive|include
file|<private/qmath_p.h>
end_include
begin_include
include|#
directive|include
file|<private/qcore_unix_p.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
comment|// file descriptor for the frame buffer
comment|// this is a global static to keep the QEglFSHooks interface as clean as possible
DECL|variable|framebuffer
specifier|static
name|int
name|framebuffer
init|=
operator|-
literal|1
decl_stmt|;
end_decl_stmt
begin_function
DECL|function|fbDeviceName
specifier|const
name|char
modifier|*
name|QEglFSHooks
operator|::
name|fbDeviceName
parameter_list|()
specifier|const
block|{
return|return
literal|"/dev/fb0"
return|;
block|}
end_function
begin_function
DECL|function|platformInit
name|void
name|QEglFSHooks
operator|::
name|platformInit
parameter_list|()
block|{
name|framebuffer
operator|=
name|qt_safe_open
argument_list|(
name|fbDeviceName
argument_list|()
argument_list|,
name|O_RDONLY
argument_list|)
expr_stmt|;
if|if
condition|(
name|framebuffer
operator|==
operator|-
literal|1
condition|)
name|qWarning
argument_list|(
literal|"EGLFS: Failed to open %s"
argument_list|,
name|fbDeviceName
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|platformDestroy
name|void
name|QEglFSHooks
operator|::
name|platformDestroy
parameter_list|()
block|{
if|if
condition|(
name|framebuffer
operator|!=
operator|-
literal|1
condition|)
name|close
argument_list|(
name|framebuffer
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|platformDisplay
name|EGLNativeDisplayType
name|QEglFSHooks
operator|::
name|platformDisplay
parameter_list|()
specifier|const
block|{
return|return
name|EGL_DEFAULT_DISPLAY
return|;
block|}
end_function
begin_function
DECL|function|physicalScreenSize
name|QSizeF
name|QEglFSHooks
operator|::
name|physicalScreenSize
parameter_list|()
specifier|const
block|{
specifier|static
name|QSizeF
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
comment|// Note: in millimeters
name|int
name|width
init|=
name|qgetenv
argument_list|(
literal|"QT_QPA_EGLFS_PHYSICAL_WIDTH"
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
literal|"QT_QPA_EGLFS_PHYSICAL_HEIGHT"
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
name|w
init|=
operator|-
literal|1
decl_stmt|;
name|int
name|h
init|=
operator|-
literal|1
decl_stmt|;
if|if
condition|(
name|framebuffer
operator|!=
operator|-
literal|1
condition|)
block|{
if|if
condition|(
name|ioctl
argument_list|(
name|framebuffer
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
block|{
name|qWarning
argument_list|(
literal|"EGLFS: Could not query variable screen info."
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|w
operator|=
name|vinfo
operator|.
name|width
expr_stmt|;
name|h
operator|=
name|vinfo
operator|.
name|height
expr_stmt|;
block|}
block|}
specifier|const
name|int
name|defaultPhysicalDpi
init|=
literal|100
decl_stmt|;
name|size
operator|.
name|setWidth
argument_list|(
name|w
operator|<=
literal|0
condition|?
name|vinfo
operator|.
name|xres
operator|*
name|Q_MM_PER_INCH
operator|/
name|defaultPhysicalDpi
else|:
name|qreal
argument_list|(
name|w
argument_list|)
argument_list|)
expr_stmt|;
name|size
operator|.
name|setHeight
argument_list|(
name|h
operator|<=
literal|0
condition|?
name|vinfo
operator|.
name|yres
operator|*
name|Q_MM_PER_INCH
operator|/
name|defaultPhysicalDpi
else|:
name|qreal
argument_list|(
name|h
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|w
operator|<=
literal|0
operator|||
name|h
operator|<=
literal|0
condition|)
block|{
name|qWarning
argument_list|(
literal|"EGLFS: Unable to query physical screen size, defaulting to %d dpi.\n"
literal|"EGLFS: To override, set QT_QPA_EGLFS_PHYSICAL_WIDTH "
literal|"and QT_QPA_EGLFS_PHYSICAL_HEIGHT (in millimeters)."
argument_list|,
name|defaultPhysicalDpi
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
name|setWidth
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
DECL|function|screenSize
name|QSize
name|QEglFSHooks
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
name|xres
init|=
operator|-
literal|1
decl_stmt|;
name|int
name|yres
init|=
operator|-
literal|1
decl_stmt|;
if|if
condition|(
name|framebuffer
operator|!=
operator|-
literal|1
condition|)
block|{
if|if
condition|(
name|ioctl
argument_list|(
name|framebuffer
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
block|{
name|qWarning
argument_list|(
literal|"EGLFS: Could not query variable screen info."
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|xres
operator|=
name|vinfo
operator|.
name|xres
expr_stmt|;
name|yres
operator|=
name|vinfo
operator|.
name|yres
expr_stmt|;
block|}
block|}
specifier|const
name|int
name|defaultWidth
init|=
literal|800
decl_stmt|;
specifier|const
name|int
name|defaultHeight
init|=
literal|600
decl_stmt|;
name|size
operator|.
name|setWidth
argument_list|(
name|xres
operator|<=
literal|0
condition|?
name|defaultWidth
else|:
name|xres
argument_list|)
expr_stmt|;
name|size
operator|.
name|setHeight
argument_list|(
name|yres
operator|<=
literal|0
condition|?
name|defaultHeight
else|:
name|yres
argument_list|)
expr_stmt|;
if|if
condition|(
name|xres
operator|<=
literal|0
operator|||
name|yres
operator|<=
literal|0
condition|)
block|{
name|qWarning
argument_list|(
literal|"EGLFS: Unable to query screen resolution, defaulting to %dx%d.\n"
literal|"EGLFS: To override, set QT_QPA_EGLFS_WIDTH and QT_QPA_EGLFS_HEIGHT."
argument_list|,
name|defaultWidth
argument_list|,
name|defaultHeight
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
DECL|function|logicalDpi
name|QDpi
name|QEglFSHooks
operator|::
name|logicalDpi
parameter_list|()
specifier|const
block|{
name|QSizeF
name|ps
init|=
name|physicalScreenSize
argument_list|()
decl_stmt|;
name|QSize
name|s
init|=
name|screenSize
argument_list|()
decl_stmt|;
return|return
name|QDpi
argument_list|(
literal|25.4
operator|*
name|s
operator|.
name|width
argument_list|()
operator|/
name|ps
operator|.
name|width
argument_list|()
argument_list|,
literal|25.4
operator|*
name|s
operator|.
name|height
argument_list|()
operator|/
name|ps
operator|.
name|height
argument_list|()
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|screenDepth
name|int
name|QEglFSHooks
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
if|if
condition|(
name|framebuffer
operator|!=
operator|-
literal|1
condition|)
block|{
if|if
condition|(
name|ioctl
argument_list|(
name|framebuffer
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
literal|"EGLFS: Could not query variable screen info."
argument_list|)
expr_stmt|;
else|else
name|depth
operator|=
name|vinfo
operator|.
name|bits_per_pixel
expr_stmt|;
block|}
specifier|const
name|int
name|defaultDepth
init|=
literal|32
decl_stmt|;
if|if
condition|(
name|depth
operator|<=
literal|0
condition|)
block|{
name|depth
operator|=
name|defaultDepth
expr_stmt|;
name|qWarning
argument_list|(
literal|"EGLFS: Unable to query screen depth, defaulting to %d.\n"
literal|"EGLFS: To override, set QT_QPA_EGLFS_DEPTH."
argument_list|,
name|defaultDepth
argument_list|)
expr_stmt|;
block|}
block|}
return|return
name|depth
return|;
block|}
end_function
begin_function
DECL|function|screenFormat
name|QImage
operator|::
name|Format
name|QEglFSHooks
operator|::
name|screenFormat
parameter_list|()
specifier|const
block|{
return|return
name|screenDepth
argument_list|()
operator|==
literal|16
condition|?
name|QImage
operator|::
name|Format_RGB16
else|:
name|QImage
operator|::
name|Format_RGB32
return|;
block|}
end_function
begin_function
DECL|function|surfaceFormatFor
name|QSurfaceFormat
name|QEglFSHooks
operator|::
name|surfaceFormatFor
parameter_list|(
specifier|const
name|QSurfaceFormat
modifier|&
name|inputFormat
parameter_list|)
specifier|const
block|{
return|return
name|inputFormat
return|;
block|}
end_function
begin_function
DECL|function|filterConfig
name|bool
name|QEglFSHooks
operator|::
name|filterConfig
parameter_list|(
name|EGLDisplay
parameter_list|,
name|EGLConfig
parameter_list|)
specifier|const
block|{
return|return
literal|true
return|;
block|}
end_function
begin_function
DECL|function|createNativeWindow
name|EGLNativeWindowType
name|QEglFSHooks
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
name|Q_UNUSED
argument_list|(
name|size
argument_list|)
expr_stmt|;
name|Q_UNUSED
argument_list|(
name|format
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function
begin_function
DECL|function|destroyNativeWindow
name|void
name|QEglFSHooks
operator|::
name|destroyNativeWindow
parameter_list|(
name|EGLNativeWindowType
name|window
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
name|window
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|hasCapability
name|bool
name|QEglFSHooks
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
name|Q_UNUSED
argument_list|(
name|cap
argument_list|)
expr_stmt|;
return|return
literal|false
return|;
block|}
end_function
begin_function
DECL|function|createCursor
name|QEglFSCursor
modifier|*
name|QEglFSHooks
operator|::
name|createCursor
parameter_list|(
name|QEglFSScreen
modifier|*
name|screen
parameter_list|)
specifier|const
block|{
return|return
operator|new
name|QEglFSCursor
argument_list|(
name|screen
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|waitForVSync
name|void
name|QEglFSHooks
operator|::
name|waitForVSync
parameter_list|()
specifier|const
block|{
if|#
directive|if
name|defined
argument_list|(
name|FBIO_WAITFORVSYNC
argument_list|)
specifier|static
specifier|const
name|bool
name|forceSync
init|=
name|qgetenv
argument_list|(
literal|"QT_QPA_EGLFS_FORCEVSYNC"
argument_list|)
operator|.
name|toInt
argument_list|()
decl_stmt|;
if|if
condition|(
name|forceSync
operator|&&
name|framebuffer
operator|!=
operator|-
literal|1
condition|)
block|{
name|int
name|arg
init|=
literal|0
decl_stmt|;
if|if
condition|(
name|ioctl
argument_list|(
name|framebuffer
argument_list|,
name|FBIO_WAITFORVSYNC
argument_list|,
operator|&
name|arg
argument_list|)
operator|==
operator|-
literal|1
condition|)
name|qWarning
argument_list|(
literal|"Could not wait for vsync."
argument_list|)
expr_stmt|;
block|}
endif|#
directive|endif
block|}
end_function
begin_ifndef
ifndef|#
directive|ifndef
name|EGLFS_PLATFORM_HOOKS
end_ifndef
begin_decl_stmt
DECL|variable|stubHooks
name|QEglFSHooks
name|stubHooks
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
