begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** No Commercial Usage ** This file contains pre-release code and may not be distributed. ** You may use this file in accordance with the terms and conditions ** contained in the Technology Preview License Agreement accompanying ** this package. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights.  These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** If you have questions regarding the use of this file, please contact ** Nokia at qt-info@nokia.com. ** ** ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qwaylandshmsurface.h"
end_include
begin_include
include|#
directive|include
file|<QtCore/qdebug.h>
end_include
begin_include
include|#
directive|include
file|"qwaylanddisplay.h"
end_include
begin_include
include|#
directive|include
file|"qwaylandshmwindow.h"
end_include
begin_include
include|#
directive|include
file|"qwaylandscreen.h"
end_include
begin_include
include|#
directive|include
file|<wayland-client.h>
end_include
begin_include
include|#
directive|include
file|<unistd.h>
end_include
begin_include
include|#
directive|include
file|<fcntl.h>
end_include
begin_include
include|#
directive|include
file|<errno.h>
end_include
begin_include
include|#
directive|include
file|<sys/mman.h>
end_include
begin_function
name|QT_BEGIN_NAMESPACE
DECL|function|QWaylandShmBuffer
name|QWaylandShmBuffer
operator|::
name|QWaylandShmBuffer
parameter_list|(
name|QWaylandDisplay
modifier|*
name|display
parameter_list|,
specifier|const
name|QSize
modifier|&
name|size
parameter_list|,
name|QImage
operator|::
name|Format
name|format
parameter_list|)
block|{
name|int
name|stride
init|=
name|size
operator|.
name|width
argument_list|()
operator|*
literal|4
decl_stmt|;
name|int
name|alloc
init|=
name|stride
operator|*
name|size
operator|.
name|height
argument_list|()
decl_stmt|;
name|char
name|filename
index|[]
init|=
literal|"/tmp/wayland-shm-XXXXXX"
decl_stmt|;
name|int
name|fd
init|=
name|mkstemp
argument_list|(
name|filename
argument_list|)
decl_stmt|;
if|if
condition|(
name|fd
operator|<
literal|0
condition|)
name|qWarning
argument_list|(
literal|"open %s failed: %s"
argument_list|,
name|filename
argument_list|,
name|strerror
argument_list|(
name|errno
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|ftruncate
argument_list|(
name|fd
argument_list|,
name|alloc
argument_list|)
operator|<
literal|0
condition|)
block|{
name|qWarning
argument_list|(
literal|"ftruncate failed: %s"
argument_list|,
name|strerror
argument_list|(
name|errno
argument_list|)
argument_list|)
expr_stmt|;
name|close
argument_list|(
name|fd
argument_list|)
expr_stmt|;
return|return;
block|}
name|uchar
modifier|*
name|data
init|=
operator|(
name|uchar
operator|*
operator|)
name|mmap
argument_list|(
name|NULL
argument_list|,
name|alloc
argument_list|,
name|PROT_READ
operator||
name|PROT_WRITE
argument_list|,
name|MAP_SHARED
argument_list|,
name|fd
argument_list|,
literal|0
argument_list|)
decl_stmt|;
name|unlink
argument_list|(
name|filename
argument_list|)
expr_stmt|;
if|if
condition|(
name|data
operator|==
operator|(
name|uchar
operator|*
operator|)
name|MAP_FAILED
condition|)
block|{
name|qWarning
argument_list|(
literal|"mmap /dev/zero failed: %s"
argument_list|,
name|strerror
argument_list|(
name|errno
argument_list|)
argument_list|)
expr_stmt|;
name|close
argument_list|(
name|fd
argument_list|)
expr_stmt|;
return|return;
block|}
name|mImage
operator|=
name|QImage
argument_list|(
name|data
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
argument_list|,
name|stride
argument_list|,
name|format
argument_list|)
expr_stmt|;
name|mBuffer
operator|=
name|display
operator|->
name|createShmBuffer
argument_list|(
name|fd
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
argument_list|,
name|stride
argument_list|,
name|display
operator|->
name|argbVisual
argument_list|()
argument_list|)
expr_stmt|;
name|close
argument_list|(
name|fd
argument_list|)
expr_stmt|;
block|}
end_function
begin_destructor
DECL|function|~QWaylandShmBuffer
name|QWaylandShmBuffer
operator|::
name|~
name|QWaylandShmBuffer
parameter_list|(
name|void
parameter_list|)
block|{
name|munmap
argument_list|(
operator|(
name|void
operator|*
operator|)
name|mImage
operator|.
name|constBits
argument_list|()
argument_list|,
name|mImage
operator|.
name|byteCount
argument_list|()
argument_list|)
expr_stmt|;
name|wl_buffer_destroy
argument_list|(
name|mBuffer
argument_list|)
expr_stmt|;
block|}
end_destructor
begin_constructor
DECL|function|QWaylandShmWindowSurface
name|QWaylandShmWindowSurface
operator|::
name|QWaylandShmWindowSurface
parameter_list|(
name|QWindow
modifier|*
name|window
parameter_list|)
member_init_list|:
name|QWindowSurface
argument_list|(
name|window
argument_list|)
member_init_list|,
name|mBuffer
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|mDisplay
argument_list|(
name|QWaylandScreen
operator|::
name|waylandScreenFromWindow
argument_list|(
name|window
argument_list|)
operator|->
name|display
argument_list|()
argument_list|)
block|{ }
end_constructor
begin_destructor
DECL|function|~QWaylandShmWindowSurface
name|QWaylandShmWindowSurface
operator|::
name|~
name|QWaylandShmWindowSurface
parameter_list|()
block|{ }
end_destructor
begin_function
DECL|function|paintDevice
name|QPaintDevice
modifier|*
name|QWaylandShmWindowSurface
operator|::
name|paintDevice
parameter_list|()
block|{
return|return
name|mBuffer
operator|->
name|image
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|beginPaint
name|void
name|QWaylandShmWindowSurface
operator|::
name|beginPaint
parameter_list|(
specifier|const
name|QRegion
modifier|&
parameter_list|)
block|{
name|QWaylandShmWindow
modifier|*
name|waylandWindow
init|=
cast|static_cast
argument_list|<
name|QWaylandShmWindow
operator|*
argument_list|>
argument_list|(
name|window
argument_list|()
operator|->
name|handle
argument_list|()
argument_list|)
decl_stmt|;
name|Q_ASSERT
argument_list|(
name|waylandWindow
operator|->
name|windowType
argument_list|()
operator|==
name|QWaylandWindow
operator|::
name|Shm
argument_list|)
expr_stmt|;
name|waylandWindow
operator|->
name|waitForFrameSync
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|flush
name|void
name|QWaylandShmWindowSurface
operator|::
name|flush
parameter_list|(
name|QWindow
modifier|*
name|window
parameter_list|,
specifier|const
name|QRegion
modifier|&
name|region
parameter_list|,
specifier|const
name|QPoint
modifier|&
name|offset
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
name|window
argument_list|)
expr_stmt|;
name|Q_UNUSED
argument_list|(
name|offset
argument_list|)
expr_stmt|;
name|QWaylandShmWindow
modifier|*
name|waylandWindow
init|=
cast|static_cast
argument_list|<
name|QWaylandShmWindow
operator|*
argument_list|>
argument_list|(
name|window
operator|->
name|handle
argument_list|()
argument_list|)
decl_stmt|;
name|Q_ASSERT
argument_list|(
name|waylandWindow
operator|->
name|windowType
argument_list|()
operator|==
name|QWaylandWindow
operator|::
name|Shm
argument_list|)
expr_stmt|;
name|waylandWindow
operator|->
name|damage
argument_list|(
name|region
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|resize
name|void
name|QWaylandShmWindowSurface
operator|::
name|resize
parameter_list|(
specifier|const
name|QSize
modifier|&
name|size
parameter_list|)
block|{
name|QWaylandShmWindow
modifier|*
name|waylandWindow
init|=
cast|static_cast
argument_list|<
name|QWaylandShmWindow
operator|*
argument_list|>
argument_list|(
name|window
argument_list|()
operator|->
name|handle
argument_list|()
argument_list|)
decl_stmt|;
name|Q_ASSERT
argument_list|(
name|waylandWindow
operator|->
name|windowType
argument_list|()
operator|==
name|QWaylandWindow
operator|::
name|Shm
argument_list|)
expr_stmt|;
name|QWindowSurface
operator|::
name|resize
argument_list|(
name|size
argument_list|)
expr_stmt|;
name|QImage
operator|::
name|Format
name|format
init|=
name|QPlatformScreen
operator|::
name|platformScreenForWindow
argument_list|(
name|window
argument_list|()
argument_list|)
operator|->
name|format
argument_list|()
decl_stmt|;
if|if
condition|(
name|mBuffer
operator|!=
name|NULL
operator|&&
name|mBuffer
operator|->
name|size
argument_list|()
operator|==
name|size
condition|)
return|return;
if|if
condition|(
name|mBuffer
operator|!=
name|NULL
condition|)
operator|delete
name|mBuffer
expr_stmt|;
name|mBuffer
operator|=
operator|new
name|QWaylandShmBuffer
argument_list|(
name|mDisplay
argument_list|,
name|size
argument_list|,
name|format
argument_list|)
expr_stmt|;
name|waylandWindow
operator|->
name|attach
argument_list|(
name|mBuffer
argument_list|)
expr_stmt|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
