begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QWINDOWSURFACE_WAYLAND_H
end_ifndef
begin_define
DECL|macro|QWINDOWSURFACE_WAYLAND_H
define|#
directive|define
name|QWINDOWSURFACE_WAYLAND_H
end_define
begin_include
include|#
directive|include
file|"qwaylandbuffer.h"
end_include
begin_include
include|#
directive|include
file|<QtGui/private/qwindowsurface_p.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/QImage>
end_include
begin_include
include|#
directive|include
file|<QtGui/QPlatformWindow>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QWaylandDisplay
name|class
name|QWaylandDisplay
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QWaylandShmBuffer
range|:
name|public
name|QWaylandBuffer
block|{
name|public
operator|:
name|QWaylandShmBuffer
argument_list|(
argument|QWaylandDisplay *display
argument_list|,
argument|const QSize&size
argument_list|,
argument|QImage::Format format
argument_list|)
block|;
operator|~
name|QWaylandShmBuffer
argument_list|()
block|;
name|QSize
name|size
argument_list|()
specifier|const
block|{
return|return
name|mImage
operator|.
name|size
argument_list|()
return|;
block|}
name|QImage
operator|*
name|image
argument_list|()
block|{
return|return
operator|&
name|mImage
return|;
block|}
name|private
operator|:
name|QImage
name|mImage
block|; }
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QWaylandShmWindowSurface
range|:
name|public
name|QWindowSurface
block|{
name|public
operator|:
name|QWaylandShmWindowSurface
argument_list|(
name|QWindow
operator|*
name|window
argument_list|)
block|;
operator|~
name|QWaylandShmWindowSurface
argument_list|()
block|;
name|QPaintDevice
operator|*
name|paintDevice
argument_list|()
block|;
name|void
name|flush
argument_list|(
name|QWindow
operator|*
name|window
argument_list|,
specifier|const
name|QRegion
operator|&
name|region
argument_list|,
specifier|const
name|QPoint
operator|&
name|offset
argument_list|)
block|;
name|void
name|resize
argument_list|(
specifier|const
name|QSize
operator|&
name|size
argument_list|)
block|;
name|void
name|beginPaint
argument_list|(
specifier|const
name|QRegion
operator|&
argument_list|)
block|;
name|private
operator|:
name|QWaylandShmBuffer
operator|*
name|mBuffer
block|;
name|QWaylandDisplay
operator|*
name|mDisplay
block|; }
decl_stmt|;
end_decl_stmt
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
end_unit
