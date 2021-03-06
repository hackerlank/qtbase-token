begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QPAINTENGINE_ALPHA_P_H
end_ifndef
begin_define
DECL|macro|QPAINTENGINE_ALPHA_P_H
define|#
directive|define
name|QPAINTENGINE_ALPHA_P_H
end_define
begin_comment
comment|//
end_comment
begin_comment
comment|//  W A R N I N G
end_comment
begin_comment
comment|//  -------------
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|// This file is not part of the Qt API.  It exists for the convenience
end_comment
begin_comment
comment|// of other Qt classes.  This header file may change from version to
end_comment
begin_comment
comment|// version without notice, or even be removed.
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|// We mean it.
end_comment
begin_comment
comment|//
end_comment
begin_include
include|#
directive|include
file|<QtCore/qglobal.h>
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_PRINTER
end_ifndef
begin_include
include|#
directive|include
file|"private/qpaintengine_p.h"
end_include
begin_include
include|#
directive|include
file|<QtPrintSupport/qtprintsupportglobal.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QAlphaPaintEnginePrivate
name|class
name|QAlphaPaintEnginePrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_PRINTSUPPORT_EXPORT
name|QAlphaPaintEngine
range|:
name|public
name|QPaintEngine
block|{
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QAlphaPaintEngine
argument_list|)
name|public
operator|:
operator|~
name|QAlphaPaintEngine
argument_list|()
block|;
name|virtual
name|bool
name|begin
argument_list|(
name|QPaintDevice
operator|*
name|pdev
argument_list|)
block|;
name|virtual
name|bool
name|end
argument_list|()
block|;
name|virtual
name|void
name|updateState
argument_list|(
specifier|const
name|QPaintEngineState
operator|&
name|state
argument_list|)
block|;
name|virtual
name|void
name|drawPath
argument_list|(
specifier|const
name|QPainterPath
operator|&
name|path
argument_list|)
block|;
name|virtual
name|void
name|drawPolygon
argument_list|(
argument|const QPointF *points
argument_list|,
argument|int pointCount
argument_list|,
argument|PolygonDrawMode mode
argument_list|)
block|;
name|virtual
name|void
name|drawPixmap
argument_list|(
specifier|const
name|QRectF
operator|&
name|r
argument_list|,
specifier|const
name|QPixmap
operator|&
name|pm
argument_list|,
specifier|const
name|QRectF
operator|&
name|sr
argument_list|)
block|;
name|virtual
name|void
name|drawTextItem
argument_list|(
specifier|const
name|QPointF
operator|&
name|p
argument_list|,
specifier|const
name|QTextItem
operator|&
name|textItem
argument_list|)
block|;
name|virtual
name|void
name|drawTiledPixmap
argument_list|(
specifier|const
name|QRectF
operator|&
name|r
argument_list|,
specifier|const
name|QPixmap
operator|&
name|pixmap
argument_list|,
specifier|const
name|QPointF
operator|&
name|s
argument_list|)
block|;
name|protected
operator|:
name|QAlphaPaintEngine
argument_list|(
argument|QAlphaPaintEnginePrivate&data
argument_list|,
argument|PaintEngineFeatures devcaps =
literal|0
argument_list|)
block|;
name|QRegion
name|alphaClipping
argument_list|()
specifier|const
block|;
name|bool
name|continueCall
argument_list|()
specifier|const
block|;
name|void
name|flushAndInit
argument_list|(
argument|bool init = true
argument_list|)
block|;
name|void
name|cleanUp
argument_list|()
block|; }
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QAlphaPaintEnginePrivate
range|:
name|public
name|QPaintEnginePrivate
block|{
name|Q_DECLARE_PUBLIC
argument_list|(
argument|QAlphaPaintEngine
argument_list|)
name|public
operator|:
name|QAlphaPaintEnginePrivate
argument_list|()
block|;
operator|~
name|QAlphaPaintEnginePrivate
argument_list|()
block|;
name|int
name|m_pass
block|;
name|QPicture
operator|*
name|m_pic
block|;
name|QPaintEngine
operator|*
name|m_picengine
block|;
name|QPainter
operator|*
name|m_picpainter
block|;
name|QPaintEngine
operator|::
name|PaintEngineFeatures
name|m_savedcaps
block|;
name|QPaintDevice
operator|*
name|m_pdev
block|;
name|QRegion
name|m_alphargn
block|;
name|QRegion
name|m_cliprgn
block|;
name|mutable
name|QRegion
name|m_cachedDirtyRgn
block|;
name|mutable
name|int
name|m_numberOfCachedRects
block|;
name|QVector
operator|<
name|QRect
operator|>
name|m_dirtyRects
block|;
name|bool
name|m_hasalpha
block|;
name|bool
name|m_alphaPen
block|;
name|bool
name|m_alphaBrush
block|;
name|bool
name|m_alphaOpacity
block|;
name|bool
name|m_advancedPen
block|;
name|bool
name|m_advancedBrush
block|;
name|bool
name|m_complexTransform
block|;
name|bool
name|m_emulateProjectiveTransforms
block|;
name|bool
name|m_continueCall
block|;
name|QTransform
name|m_transform
block|;
name|QPen
name|m_pen
block|;
name|void
name|addAlphaRect
argument_list|(
specifier|const
name|QRectF
operator|&
name|rect
argument_list|)
block|;
name|void
name|addDirtyRect
argument_list|(
argument|const QRectF&rect
argument_list|)
block|{
name|m_dirtyRects
operator|.
name|append
argument_list|(
name|rect
operator|.
name|toAlignedRect
argument_list|()
argument_list|)
block|; }
name|bool
name|canSeeTroughBackground
argument_list|(
argument|bool somethingInRectHasAlpha
argument_list|,
argument|const QRectF&rect
argument_list|)
specifier|const
block|;
name|QRectF
name|addPenWidth
argument_list|(
specifier|const
name|QPainterPath
operator|&
name|path
argument_list|)
block|;
name|void
name|drawAlphaImage
argument_list|(
specifier|const
name|QRectF
operator|&
name|rect
argument_list|)
block|;
name|QRect
name|toRect
argument_list|(
argument|const QRectF&rect
argument_list|)
specifier|const
block|;
name|bool
name|fullyContained
argument_list|(
argument|const QRectF&rect
argument_list|)
specifier|const
block|;
name|void
name|resetState
argument_list|(
name|QPainter
operator|*
name|p
argument_list|)
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
begin_comment
comment|// QT_NO_PRINTER
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QPAINTENGINE_ALPHA_P_H
end_comment
end_unit
