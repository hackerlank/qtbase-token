begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** No Commercial Usage ** This file contains pre-release code and may not be distributed. ** You may use this file in accordance with the terms and conditions ** contained in the Technology Preview License Agreement accompanying ** this package. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights.  These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** If you have questions regarding the use of this file, please contact ** Nokia at qt-info@nokia.com. ** ** ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|MLIVEPIXMAPDATA_H
end_ifndef
begin_define
DECL|macro|MLIVEPIXMAPDATA_H
define|#
directive|define
name|MLIVEPIXMAPDATA_H
end_define
begin_include
include|#
directive|include
file|<QLinkedList>
end_include
begin_include
include|#
directive|include
file|<private/qpixmapdata_gl_p.h>
end_include
begin_include
include|#
directive|include
file|"qmeegoextensions.h"
end_include
begin_decl_stmt
DECL|variable|QMeeGoLivePixmapData
name|class
name|QMeeGoLivePixmapData
decl_stmt|;
end_decl_stmt
begin_typedef
DECL|typedef|QMeeGoLivePixmapDataList
typedef|typedef
name|QLinkedList
operator|<
name|QMeeGoLivePixmapData
operator|*
operator|>
name|QMeeGoLivePixmapDataList
expr_stmt|;
end_typedef
begin_decl_stmt
name|class
name|QMeeGoLivePixmapData
range|:
name|public
name|QGLPixmapData
block|{
name|public
operator|:
name|QMeeGoLivePixmapData
argument_list|(
argument|int w
argument_list|,
argument|int h
argument_list|,
argument|QImage::Format format
argument_list|)
block|;
name|QMeeGoLivePixmapData
argument_list|(
argument|Qt::HANDLE h
argument_list|)
block|;
operator|~
name|QMeeGoLivePixmapData
argument_list|()
block|;
name|QPixmapData
operator|*
name|createCompatiblePixmapData
argument_list|()
specifier|const
block|;
name|bool
name|scroll
argument_list|(
argument|int dx
argument_list|,
argument|int dy
argument_list|,
argument|const QRect&rect
argument_list|)
block|;
name|void
name|initializeThroughEGLImage
argument_list|()
block|;
name|QImage
operator|*
name|lock
argument_list|(
argument|EGLSyncKHR fenceSync
argument_list|)
block|;
name|bool
name|release
argument_list|(
name|QImage
operator|*
name|img
argument_list|)
block|;
name|Qt
operator|::
name|HANDLE
name|handle
argument_list|()
block|;
name|EGLSurface
name|getSurfaceForBackingPixmap
argument_list|()
block|;
name|void
name|destroySurfaceForPixmapData
argument_list|(
name|QPixmapData
operator|*
name|pmd
argument_list|)
block|;
name|QPixmap
operator|*
name|backingX11Pixmap
block|;
name|QImage
name|lockedImage
block|;
name|QMeeGoLivePixmapDataList
operator|::
name|Iterator
name|pos
block|;
specifier|static
name|void
name|invalidateSurfaces
argument_list|()
block|; }
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
end_unit
