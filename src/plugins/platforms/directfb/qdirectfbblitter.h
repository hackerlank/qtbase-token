begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QDIRECTFBBLITTER_H
end_ifndef
begin_define
DECL|macro|QDIRECTFBBLITTER_H
define|#
directive|define
name|QDIRECTFBBLITTER_H
end_define
begin_include
include|#
directive|include
file|"qdirectfbconvenience.h"
end_include
begin_include
include|#
directive|include
file|<private/qblittable_p.h>
end_include
begin_include
include|#
directive|include
file|<directfb.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
name|class
name|QDirectFbBlitter
range|:
name|public
name|QBlittable
block|{
name|public
operator|:
name|QDirectFbBlitter
argument_list|(
specifier|const
name|QSize
operator|&
name|size
argument_list|,
name|IDirectFBSurface
operator|*
name|surface
argument_list|)
block|;
name|QDirectFbBlitter
argument_list|(
argument|const QSize&size
argument_list|,
argument|bool alpha
argument_list|)
block|;
name|virtual
operator|~
name|QDirectFbBlitter
argument_list|()
block|;
name|virtual
name|void
name|fillRect
argument_list|(
specifier|const
name|QRectF
operator|&
name|rect
argument_list|,
specifier|const
name|QColor
operator|&
name|color
argument_list|)
block|;
name|virtual
name|void
name|drawPixmap
argument_list|(
specifier|const
name|QRectF
operator|&
name|rect
argument_list|,
specifier|const
name|QPixmap
operator|&
name|pixmap
argument_list|,
specifier|const
name|QRectF
operator|&
name|subrect
argument_list|)
block|;
name|void
name|alphaFillRect
argument_list|(
argument|const QRectF&rect
argument_list|,
argument|const QColor&color
argument_list|,
argument|QPainter::CompositionMode cmode
argument_list|)
block|;
name|void
name|drawPixmapOpacity
argument_list|(
argument|const QRectF&rect
argument_list|,
argument|const QPixmap&pixmap
argument_list|,
argument|const QRectF&subrect
argument_list|,
argument|QPainter::CompositionMode cmode
argument_list|,
argument|qreal opacity
argument_list|)
block|;
name|IDirectFBSurface
operator|*
name|dfbSurface
argument_list|()
specifier|const
block|;
specifier|static
name|DFBSurfacePixelFormat
name|alphaPixmapFormat
argument_list|()
block|;
specifier|static
name|DFBSurfacePixelFormat
name|pixmapFormat
argument_list|()
block|;
specifier|static
name|DFBSurfacePixelFormat
name|selectPixmapFormat
argument_list|(
argument|bool withAlpha
argument_list|)
block|;
name|protected
operator|:
name|virtual
name|QImage
operator|*
name|doLock
argument_list|()
block|;
name|virtual
name|void
name|doUnlock
argument_list|()
block|;
name|QDirectFBPointer
operator|<
name|IDirectFBSurface
operator|>
name|m_surface
block|;
name|QImage
name|m_image
block|;
name|friend
name|class
name|QDirectFbConvenience
block|;
name|private
operator|:
name|bool
name|m_premult
block|; }
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QDirectFbBlitterPlatformPixmap
range|:
name|public
name|QBlittablePlatformPixmap
block|{
name|public
operator|:
name|QBlittable
operator|*
name|createBlittable
argument_list|(
argument|const QSize&size
argument_list|,
argument|bool alpha
argument_list|)
specifier|const
block|;
name|QDirectFbBlitter
operator|*
name|dfbBlitter
argument_list|()
specifier|const
block|;
name|virtual
name|bool
name|fromFile
argument_list|(
argument|const QString&filename
argument_list|,
argument|const char *format
argument_list|,
argument|Qt::ImageConversionFlags flags
argument_list|)
block|;
name|private
operator|:
name|bool
name|fromDataBufferDescription
argument_list|(
specifier|const
name|DFBDataBufferDescription
operator|&
argument_list|)
block|; }
decl_stmt|;
end_decl_stmt
begin_expr_stmt
DECL|function|createBlittable
specifier|inline
name|QBlittable
operator|*
name|QDirectFbBlitterPlatformPixmap
operator|::
name|createBlittable
argument_list|(
argument|const QSize& size
argument_list|,
argument|bool alpha
argument_list|)
specifier|const
block|{
return|return
name|new
name|QDirectFbBlitter
argument_list|(
name|size
argument_list|,
name|alpha
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|dfbBlitter
specifier|inline
name|QDirectFbBlitter
operator|*
name|QDirectFbBlitterPlatformPixmap
operator|::
name|dfbBlitter
argument_list|()
specifier|const
block|{
return|return
name|static_cast
operator|<
name|QDirectFbBlitter
operator|*
operator|>
operator|(
name|blittable
argument_list|()
operator|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|dfbSurface
specifier|inline
name|IDirectFBSurface
operator|*
name|QDirectFbBlitter
operator|::
name|dfbSurface
argument_list|()
specifier|const
block|{
return|return
name|m_surface
operator|.
name|data
argument_list|()
return|;
block|}
end_expr_stmt
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QDIRECTFBBLITTER_H
end_comment
end_unit
