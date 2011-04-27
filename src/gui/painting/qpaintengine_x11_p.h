begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** No Commercial Usage ** This file contains pre-release code and may not be distributed. ** You may use this file in accordance with the terms and conditions ** contained in the Technology Preview License Agreement accompanying ** this package. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights.  These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** If you have questions regarding the use of this file, please contact ** Nokia at qt-info@nokia.com. ** ** ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QPAINTENGINE_X11_P_H
end_ifndef
begin_define
DECL|macro|QPAINTENGINE_X11_P_H
define|#
directive|define
name|QPAINTENGINE_X11_P_H
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
comment|// This file is not part of the Qt API.  It exists purely as an
end_comment
begin_comment
comment|// implementation detail.  This header file may change from version to
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
file|"QtGui/qpaintengine.h"
end_include
begin_include
include|#
directive|include
file|"QtGui/qregion.h"
end_include
begin_include
include|#
directive|include
file|"QtGui/qpen.h"
end_include
begin_include
include|#
directive|include
file|"QtCore/qpoint.h"
end_include
begin_include
include|#
directive|include
file|"private/qpaintengine_p.h"
end_include
begin_include
include|#
directive|include
file|"private/qpainter_p.h"
end_include
begin_include
include|#
directive|include
file|"private/qpolygonclipper_p.h"
end_include
begin_typedef
DECL|typedef|Picture
typedef|typedef
name|unsigned
name|long
name|Picture
typedef|;
end_typedef
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QX11PaintEnginePrivate
name|class
name|QX11PaintEnginePrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QFontEngineFT
name|class
name|QFontEngineFT
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QXRenderTessellator
name|class
name|QXRenderTessellator
decl_stmt|;
end_decl_stmt
begin_struct
DECL|struct|qt_float_point
struct|struct
name|qt_float_point
block|{
DECL|member|x
DECL|member|y
name|qreal
name|x
decl_stmt|,
name|y
decl_stmt|;
block|}
struct|;
end_struct
begin_decl_stmt
name|class
name|QX11PaintEngine
range|:
name|public
name|QPaintEngine
block|{
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QX11PaintEngine
argument_list|)
name|public
operator|:
name|QX11PaintEngine
argument_list|()
block|;
operator|~
name|QX11PaintEngine
argument_list|()
block|;
name|bool
name|begin
argument_list|(
name|QPaintDevice
operator|*
name|pdev
argument_list|)
block|;
name|bool
name|end
argument_list|()
block|;
name|void
name|updateState
argument_list|(
specifier|const
name|QPaintEngineState
operator|&
name|state
argument_list|)
block|;
name|void
name|updatePen
argument_list|(
specifier|const
name|QPen
operator|&
name|pen
argument_list|)
block|;
name|void
name|updateBrush
argument_list|(
specifier|const
name|QBrush
operator|&
name|brush
argument_list|,
specifier|const
name|QPointF
operator|&
name|pt
argument_list|)
block|;
name|void
name|updateRenderHints
argument_list|(
argument|QPainter::RenderHints hints
argument_list|)
block|;
name|void
name|updateFont
argument_list|(
specifier|const
name|QFont
operator|&
name|font
argument_list|)
block|;
name|void
name|updateMatrix
argument_list|(
specifier|const
name|QTransform
operator|&
name|matrix
argument_list|)
block|;
name|void
name|updateClipRegion_dev
argument_list|(
argument|const QRegion&region
argument_list|,
argument|Qt::ClipOperation op
argument_list|)
block|;
name|void
name|drawLines
argument_list|(
argument|const QLine *lines
argument_list|,
argument|int lineCount
argument_list|)
block|;
name|void
name|drawLines
argument_list|(
argument|const QLineF *lines
argument_list|,
argument|int lineCount
argument_list|)
block|;
name|void
name|drawRects
argument_list|(
argument|const QRect *rects
argument_list|,
argument|int rectCount
argument_list|)
block|;
name|void
name|drawRects
argument_list|(
argument|const QRectF *rects
argument_list|,
argument|int rectCount
argument_list|)
block|;
name|void
name|drawPoints
argument_list|(
argument|const QPoint *points
argument_list|,
argument|int pointCount
argument_list|)
block|;
name|void
name|drawPoints
argument_list|(
argument|const QPointF *points
argument_list|,
argument|int pointCount
argument_list|)
block|;
name|void
name|drawEllipse
argument_list|(
specifier|const
name|QRect
operator|&
name|r
argument_list|)
block|;
name|void
name|drawEllipse
argument_list|(
specifier|const
name|QRectF
operator|&
name|r
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
specifier|inline
name|void
name|drawPolygon
argument_list|(
argument|const QPoint *points
argument_list|,
argument|int pointCount
argument_list|,
argument|PolygonDrawMode mode
argument_list|)
block|{
name|QPaintEngine
operator|::
name|drawPolygon
argument_list|(
name|points
argument_list|,
name|pointCount
argument_list|,
name|mode
argument_list|)
block|; }
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
name|void
name|drawPath
argument_list|(
specifier|const
name|QPainterPath
operator|&
name|path
argument_list|)
block|;
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
name|void
name|drawImage
argument_list|(
argument|const QRectF&r
argument_list|,
argument|const QImage&img
argument_list|,
argument|const QRectF&sr
argument_list|,
argument|Qt::ImageConversionFlags flags = Qt::AutoColor
argument_list|)
block|;
name|virtual
name|Qt
operator|::
name|HANDLE
name|handle
argument_list|()
specifier|const
block|;
specifier|inline
name|Type
name|type
argument_list|()
specifier|const
block|{
return|return
name|QPaintEngine
operator|::
name|X11
return|;
block|}
name|QPainter
operator|::
name|RenderHints
name|supportedRenderHints
argument_list|()
specifier|const
block|;
name|protected
operator|:
name|QX11PaintEngine
argument_list|(
name|QX11PaintEnginePrivate
operator|&
name|dptr
argument_list|)
block|;
name|void
name|drawXLFD
argument_list|(
specifier|const
name|QPointF
operator|&
name|p
argument_list|,
specifier|const
name|QTextItemInt
operator|&
name|si
argument_list|)
block|;
ifndef|#
directive|ifndef
name|QT_NO_FONTCONFIG
name|void
name|drawFreetype
argument_list|(
specifier|const
name|QPointF
operator|&
name|p
argument_list|,
specifier|const
name|QTextItemInt
operator|&
name|si
argument_list|)
block|;
endif|#
directive|endif
name|friend
name|class
name|QPixmap
block|;
name|friend
name|class
name|QFontEngineBox
block|;
name|friend
name|Q_GUI_EXPORT
name|GC
name|qt_x11_get_pen_gc
argument_list|(
name|QPainter
operator|*
argument_list|)
block|;
name|friend
name|Q_GUI_EXPORT
name|GC
name|qt_x11_get_brush_gc
argument_list|(
name|QPainter
operator|*
argument_list|)
block|;
name|private
operator|:
name|Q_DISABLE_COPY
argument_list|(
argument|QX11PaintEngine
argument_list|)
block|}
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QX11PaintEnginePrivate
range|:
name|public
name|QPaintEnginePrivate
block|{
name|Q_DECLARE_PUBLIC
argument_list|(
argument|QX11PaintEngine
argument_list|)
name|public
operator|:
name|QX11PaintEnginePrivate
argument_list|()
block|{
name|scrn
operator|=
operator|-
literal|1
block|;
name|hd
operator|=
literal|0
block|;
name|picture
operator|=
literal|0
block|;
name|gc
operator|=
name|gc_brush
operator|=
literal|0
block|;
name|dpy
operator|=
literal|0
block|;
name|xinfo
operator|=
literal|0
block|;
name|txop
operator|=
name|QTransform
operator|::
name|TxNone
block|;
name|has_clipping
operator|=
name|false
block|;
name|render_hints
operator|=
literal|0
block|;
name|xform_scale
operator|=
literal|1
block|;
ifndef|#
directive|ifndef
name|QT_NO_XRENDER
name|tessellator
operator|=
literal|0
block|;
endif|#
directive|endif
block|}
expr|enum
name|GCMode
block|{
name|PenGC
block|,
name|BrushGC
block|}
block|;
name|void
name|init
argument_list|()
block|;
name|void
name|fillPolygon_translated
argument_list|(
argument|const QPointF *points
argument_list|,
argument|int pointCount
argument_list|,
argument|GCMode gcMode
argument_list|,
argument|QPaintEngine::PolygonDrawMode mode
argument_list|)
block|;
name|void
name|fillPolygon_dev
argument_list|(
argument|const QPointF *points
argument_list|,
argument|int pointCount
argument_list|,
argument|GCMode gcMode
argument_list|,
argument|QPaintEngine::PolygonDrawMode mode
argument_list|)
block|;
name|void
name|fillPath
argument_list|(
argument|const QPainterPath&path
argument_list|,
argument|GCMode gcmode
argument_list|,
argument|bool transform
argument_list|)
block|;
name|void
name|strokePolygon_dev
argument_list|(
argument|const QPointF *points
argument_list|,
argument|int pointCount
argument_list|,
argument|bool close
argument_list|)
block|;
name|void
name|strokePolygon_translated
argument_list|(
argument|const QPointF *points
argument_list|,
argument|int pointCount
argument_list|,
argument|bool close
argument_list|)
block|;
name|void
name|setupAdaptedOrigin
argument_list|(
specifier|const
name|QPoint
operator|&
name|p
argument_list|)
block|;
name|void
name|resetAdaptedOrigin
argument_list|()
block|;
name|void
name|decidePathFallback
argument_list|()
block|{
name|use_path_fallback
operator|=
name|has_alpha_brush
operator|||
name|has_alpha_pen
operator|||
name|has_custom_pen
operator|||
name|has_complex_xform
operator|||
operator|(
name|render_hints
operator|&
name|QPainter
operator|::
name|Antialiasing
operator|)
block|;     }
name|void
name|decideCoordAdjust
argument_list|()
block|{
name|adjust_coords
operator|=
operator|!
operator|(
name|render_hints
operator|&
name|QPainter
operator|::
name|Antialiasing
operator|)
operator|&&
operator|(
name|has_alpha_pen
operator|||
operator|(
name|has_alpha_brush
operator|&&
name|has_pen
operator|&&
operator|!
name|has_alpha_pen
operator|)
operator|||
operator|(
name|cpen
operator|.
name|style
argument_list|()
operator|>
name|Qt
operator|::
name|SolidLine
operator|)
operator|)
block|;     }
name|void
name|clipPolygon_dev
argument_list|(
specifier|const
name|QPolygonF
operator|&
name|poly
argument_list|,
name|QPolygonF
operator|*
name|clipped_poly
argument_list|)
block|;
name|void
name|systemStateChanged
argument_list|()
block|;
name|Display
operator|*
name|dpy
block|;
name|int
name|scrn
block|;
name|int
name|pdev_depth
block|;
name|Qt
operator|::
name|HANDLE
name|hd
block|;
name|QPixmap
name|brush_pm
block|;
if|#
directive|if
operator|!
name|defined
argument_list|(
name|QT_NO_XRENDER
argument_list|)
name|Qt
operator|::
name|HANDLE
name|picture
block|;
name|Qt
operator|::
name|HANDLE
name|current_brush
block|;
name|QPixmap
name|bitmap_texture
block|;
name|int
name|composition_mode
block|;
else|#
directive|else
name|Qt
operator|::
name|HANDLE
name|picture
block|;
endif|#
directive|endif
name|GC
name|gc
block|;
name|GC
name|gc_brush
block|;
name|QPen
name|cpen
block|;
name|QBrush
name|cbrush
block|;
name|QRegion
name|crgn
block|;
name|QTransform
name|matrix
block|;
name|qreal
name|opacity
block|;
name|uint
name|has_complex_xform
operator|:
literal|1
block|;
name|uint
name|has_scaling_xform
operator|:
literal|1
block|;
name|uint
name|has_non_scaling_xform
operator|:
literal|1
block|;
name|uint
name|has_custom_pen
operator|:
literal|1
block|;
name|uint
name|use_path_fallback
operator|:
literal|1
block|;
name|uint
name|adjust_coords
operator|:
literal|1
block|;
name|uint
name|has_clipping
operator|:
literal|1
block|;
name|uint
name|adapted_brush_origin
operator|:
literal|1
block|;
name|uint
name|adapted_pen_origin
operator|:
literal|1
block|;
name|uint
name|has_pen
operator|:
literal|1
block|;
name|uint
name|has_brush
operator|:
literal|1
block|;
name|uint
name|has_texture
operator|:
literal|1
block|;
name|uint
name|has_alpha_texture
operator|:
literal|1
block|;
name|uint
name|has_pattern
operator|:
literal|1
block|;
name|uint
name|has_alpha_pen
operator|:
literal|1
block|;
name|uint
name|has_alpha_brush
operator|:
literal|1
block|;
name|uint
name|render_hints
block|;
specifier|const
name|QX11Info
operator|*
name|xinfo
block|;
name|QPointF
name|bg_origin
block|;
name|QTransform
operator|::
name|TransformationType
name|txop
block|;
name|qreal
name|xform_scale
block|;
name|QPolygonClipper
operator|<
name|qt_float_point
block|,
name|qt_float_point
block|,
name|float
operator|>
name|polygonClipper
block|;
name|int
name|xlibMaxLinePoints
block|;
ifndef|#
directive|ifndef
name|QT_NO_XRENDER
name|QXRenderTessellator
operator|*
name|tessellator
block|;
endif|#
directive|endif
block|}
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
comment|// QPAINTENGINE_X11_P_H
end_comment
end_unit
