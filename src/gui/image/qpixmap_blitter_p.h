begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QPIXMAP_BLITTER_P_H
end_ifndef
begin_define
DECL|macro|QPIXMAP_BLITTER_P_H
define|#
directive|define
name|QPIXMAP_BLITTER_P_H
end_define
begin_include
include|#
directive|include
file|<qpa/qplatformpixmap.h>
end_include
begin_include
include|#
directive|include
file|<private/qpaintengine_blitter_p.h>
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_BLITTABLE
end_ifndef
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
name|class
name|Q_GUI_EXPORT
name|QBlittablePlatformPixmap
range|:
name|public
name|QPlatformPixmap
block|{
comment|//     Q_DECLARE_PRIVATE(QBlittablePlatformPixmap);
name|public
operator|:
name|QBlittablePlatformPixmap
argument_list|()
block|;
operator|~
name|QBlittablePlatformPixmap
argument_list|()
block|;
name|virtual
name|QBlittable
operator|*
name|createBlittable
argument_list|(
argument|const QSize&size
argument_list|,
argument|bool alpha
argument_list|)
specifier|const
operator|=
literal|0
block|;
name|QBlittable
operator|*
name|blittable
argument_list|()
specifier|const
block|;
name|void
name|setBlittable
argument_list|(
name|QBlittable
operator|*
name|blittable
argument_list|)
block|;
name|void
name|resize
argument_list|(
argument|int width
argument_list|,
argument|int height
argument_list|)
block|;
name|int
name|metric
argument_list|(
argument|QPaintDevice::PaintDeviceMetric metric
argument_list|)
specifier|const
block|;
name|void
name|fill
argument_list|(
specifier|const
name|QColor
operator|&
name|color
argument_list|)
block|;
name|QImage
operator|*
name|buffer
argument_list|()
block|;
name|QImage
name|toImage
argument_list|()
specifier|const
block|;
name|bool
name|hasAlphaChannel
argument_list|()
specifier|const
block|;
name|void
name|fromImage
argument_list|(
argument|const QImage&image
argument_list|,
argument|Qt::ImageConversionFlags flags
argument_list|)
block|;
name|qreal
name|devicePixelRatio
argument_list|()
specifier|const
block|;
name|void
name|setDevicePixelRatio
argument_list|(
argument|qreal scaleFactor
argument_list|)
block|;
name|QPaintEngine
operator|*
name|paintEngine
argument_list|()
specifier|const
block|;
name|void
name|markRasterOverlay
argument_list|(
specifier|const
name|QRectF
operator|&
argument_list|)
block|;
name|void
name|markRasterOverlay
argument_list|(
specifier|const
name|QPointF
operator|&
argument_list|,
specifier|const
name|QTextItem
operator|&
argument_list|)
block|;
name|void
name|markRasterOverlay
argument_list|(
specifier|const
name|QVectorPath
operator|&
argument_list|)
block|;
name|void
name|markRasterOverlay
argument_list|(
specifier|const
name|QPainterPath
operator|&
argument_list|)
block|;
name|void
name|markRasterOverlay
argument_list|(
argument|const QRect *rects
argument_list|,
argument|int rectCount
argument_list|)
block|;
name|void
name|markRasterOverlay
argument_list|(
argument|const QRectF *rects
argument_list|,
argument|int rectCount
argument_list|)
block|;
name|void
name|markRasterOverlay
argument_list|(
argument|const QPointF *points
argument_list|,
argument|int pointCount
argument_list|)
block|;
name|void
name|markRasterOverlay
argument_list|(
argument|const QPoint *points
argument_list|,
argument|int pointCount
argument_list|)
block|;
name|void
name|unmarkRasterOverlay
argument_list|(
specifier|const
name|QRectF
operator|&
argument_list|)
block|;
ifdef|#
directive|ifdef
name|QT_BLITTER_RASTEROVERLAY
name|void
name|mergeOverlay
argument_list|()
block|;
name|void
name|unmergeOverlay
argument_list|()
block|;
name|QImage
operator|*
name|overlay
argument_list|()
block|;
endif|#
directive|endif
comment|//QT_BLITTER_RASTEROVERLAY
name|protected
operator|:
name|QScopedPointer
operator|<
name|QBlitterPaintEngine
operator|>
name|m_engine
block|;
name|QScopedPointer
operator|<
name|QBlittable
operator|>
name|m_blittable
block|;
name|bool
name|m_alpha
block|;
name|qreal
name|m_devicePixelRatio
block|;
ifdef|#
directive|ifdef
name|QT_BLITTER_RASTEROVERLAY
name|QImage
operator|*
name|m_rasterOverlay
block|;
name|QImage
operator|*
name|m_unmergedCopy
block|;
name|QColor
name|m_overlayColor
block|;
name|void
name|markRasterOverlayImpl
argument_list|(
specifier|const
name|QRectF
operator|&
argument_list|)
block|;
name|void
name|unmarkRasterOverlayImpl
argument_list|(
specifier|const
name|QRectF
operator|&
argument_list|)
block|;
name|QRectF
name|clipAndTransformRect
argument_list|(
argument|const QRectF&
argument_list|)
specifier|const
block|;
endif|#
directive|endif
comment|//QT_BLITTER_RASTEROVERLAY
block|}
decl_stmt|;
end_decl_stmt
begin_expr_stmt
DECL|function|markRasterOverlay
specifier|inline
name|void
name|QBlittablePlatformPixmap
operator|::
name|markRasterOverlay
argument_list|(
argument|const QRectF&rect
argument_list|)
block|{
ifdef|#
directive|ifdef
name|QT_BLITTER_RASTEROVERLAY
name|markRasterOverlayImpl
argument_list|(
name|rect
argument_list|)
block|;
else|#
directive|else
name|Q_UNUSED
argument_list|(
argument|rect
argument_list|)
endif|#
directive|endif
block|}
DECL|function|markRasterOverlay
specifier|inline
name|void
name|QBlittablePlatformPixmap
operator|::
name|markRasterOverlay
argument_list|(
argument|const QVectorPath&path
argument_list|)
block|{
ifdef|#
directive|ifdef
name|QT_BLITTER_RASTEROVERLAY
name|markRasterOverlayImpl
argument_list|(
name|path
operator|.
name|convertToPainterPath
argument_list|()
operator|.
name|boundingRect
argument_list|()
argument_list|)
block|;
else|#
directive|else
name|Q_UNUSED
argument_list|(
argument|path
argument_list|)
endif|#
directive|endif
block|}
DECL|function|markRasterOverlay
specifier|inline
name|void
name|QBlittablePlatformPixmap
operator|::
name|markRasterOverlay
argument_list|(
argument|const QPointF&pos
argument_list|,
argument|const QTextItem&ti
argument_list|)
block|{
ifdef|#
directive|ifdef
name|QT_BLITTER_RASTEROVERLAY
name|QFontMetricsF
name|fm
argument_list|(
name|ti
operator|.
name|font
argument_list|()
argument_list|)
block|;
name|QRectF
name|rect
operator|=
name|fm
operator|.
name|tightBoundingRect
argument_list|(
name|ti
operator|.
name|text
argument_list|()
argument_list|)
block|;
name|rect
operator|.
name|moveBottomLeft
argument_list|(
name|pos
argument_list|)
block|;
name|markRasterOverlay
argument_list|(
name|rect
argument_list|)
block|;
else|#
directive|else
name|Q_UNUSED
argument_list|(
argument|pos
argument_list|)
name|Q_UNUSED
argument_list|(
argument|ti
argument_list|)
endif|#
directive|endif
block|}
DECL|function|markRasterOverlay
specifier|inline
name|void
name|QBlittablePlatformPixmap
operator|::
name|markRasterOverlay
argument_list|(
argument|const QRect *rects
argument_list|,
argument|int rectCount
argument_list|)
block|{
ifdef|#
directive|ifdef
name|QT_BLITTER_RASTEROVERLAY
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|rectCount
condition|;
name|i
operator|++
control|)
block|{
name|markRasterOverlay
argument_list|(
name|rects
index|[
name|i
index|]
argument_list|)
expr_stmt|;
block|}
else|#
directive|else
name|Q_UNUSED
argument_list|(
argument|rects
argument_list|)
name|Q_UNUSED
argument_list|(
argument|rectCount
argument_list|)
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_expr_stmt
unit|} inline
DECL|function|markRasterOverlay
name|void
name|QBlittablePlatformPixmap
operator|::
name|markRasterOverlay
argument_list|(
argument|const QRectF *rects
argument_list|,
argument|int rectCount
argument_list|)
block|{
ifdef|#
directive|ifdef
name|QT_BLITTER_RASTEROVERLAY
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|rectCount
condition|;
name|i
operator|++
control|)
block|{
name|markRasterOverlay
argument_list|(
name|rects
index|[
name|i
index|]
argument_list|)
expr_stmt|;
block|}
else|#
directive|else
name|Q_UNUSED
argument_list|(
argument|rects
argument_list|)
name|Q_UNUSED
argument_list|(
argument|rectCount
argument_list|)
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_expr_stmt
unit|}  inline
DECL|function|markRasterOverlay
name|void
name|QBlittablePlatformPixmap
operator|::
name|markRasterOverlay
argument_list|(
argument|const QPointF *points
argument_list|,
argument|int pointCount
argument_list|)
block|{
ifdef|#
directive|ifdef
name|QT_BLITTER_RASTEROVERLAY
error|#
directive|error
literal|"not ported yet"
else|#
directive|else
name|Q_UNUSED
argument_list|(
name|points
argument_list|)
block|;
name|Q_UNUSED
argument_list|(
name|pointCount
argument_list|)
block|;
endif|#
directive|endif
block|}
DECL|function|markRasterOverlay
specifier|inline
name|void
name|QBlittablePlatformPixmap
operator|::
name|markRasterOverlay
argument_list|(
argument|const QPoint *points
argument_list|,
argument|int pointCount
argument_list|)
block|{
ifdef|#
directive|ifdef
name|QT_BLITTER_RASTEROVERLAY
error|#
directive|error
literal|"not ported yet"
else|#
directive|else
name|Q_UNUSED
argument_list|(
name|points
argument_list|)
block|;
name|Q_UNUSED
argument_list|(
name|pointCount
argument_list|)
block|;
endif|#
directive|endif
block|}
DECL|function|markRasterOverlay
specifier|inline
name|void
name|QBlittablePlatformPixmap
operator|::
name|markRasterOverlay
argument_list|(
argument|const QPainterPath& path
argument_list|)
block|{
ifdef|#
directive|ifdef
name|QT_BLITTER_RASTEROVERLAY
error|#
directive|error
literal|"not ported yet"
else|#
directive|else
name|Q_UNUSED
argument_list|(
name|path
argument_list|)
block|;
endif|#
directive|endif
block|}
DECL|function|unmarkRasterOverlay
specifier|inline
name|void
name|QBlittablePlatformPixmap
operator|::
name|unmarkRasterOverlay
argument_list|(
argument|const QRectF&rect
argument_list|)
block|{
ifdef|#
directive|ifdef
name|QT_BLITTER_RASTEROVERLAY
name|unmarkRasterOverlayImpl
argument_list|(
name|rect
argument_list|)
block|;
else|#
directive|else
name|Q_UNUSED
argument_list|(
argument|rect
argument_list|)
endif|#
directive|endif
block|}
name|QT_END_NAMESPACE
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_BLITTABLE
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QPIXMAP_BLITTER_P_H
end_comment
end_unit
