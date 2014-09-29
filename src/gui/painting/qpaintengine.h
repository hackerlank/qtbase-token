begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2014 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia. For licensing terms and ** conditions see http://qt.digia.com/licensing. For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights. These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QPAINTENGINE_H
end_ifndef
begin_define
DECL|macro|QPAINTENGINE_H
define|#
directive|define
name|QPAINTENGINE_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qnamespace.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qobjectdefs.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qscopedpointer.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/qpainter.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QFontEngine
name|class
name|QFontEngine
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QLineF
name|class
name|QLineF
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QPaintDevice
name|class
name|QPaintDevice
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QPaintEnginePrivate
name|class
name|QPaintEnginePrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QPainterPath
name|class
name|QPainterPath
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QPointF
name|class
name|QPointF
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QPolygonF
name|class
name|QPolygonF
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QRectF
name|class
name|QRectF
decl_stmt|;
end_decl_stmt
begin_struct_decl
struct_decl|struct
name|QGlyphLayout
struct_decl|;
end_struct_decl
begin_decl_stmt
DECL|variable|QTextItemInt
name|class
name|QTextItemInt
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QPaintEngineState
name|class
name|QPaintEngineState
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_GUI_EXPORT
name|QTextItem
block|{
name|public
label|:
enum|enum
name|RenderFlag
block|{
name|RightToLeft
init|=
literal|0x1
block|,
name|Overline
init|=
literal|0x10
block|,
name|Underline
init|=
literal|0x20
block|,
name|StrikeOut
init|=
literal|0x40
block|,
name|Dummy
init|=
literal|0xffffffff
block|}
enum|;
name|Q_DECLARE_FLAGS
argument_list|(
argument|RenderFlags
argument_list|,
argument|RenderFlag
argument_list|)
name|qreal
name|descent
argument_list|()
specifier|const
expr_stmt|;
name|qreal
name|ascent
argument_list|()
specifier|const
expr_stmt|;
name|qreal
name|width
argument_list|()
specifier|const
expr_stmt|;
name|RenderFlags
name|renderFlags
argument_list|()
specifier|const
expr_stmt|;
name|QString
name|text
argument_list|()
specifier|const
expr_stmt|;
name|QFont
name|font
argument_list|()
specifier|const
expr_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_expr_stmt
name|Q_DECLARE_TYPEINFO
argument_list|(
name|QTextItem
argument_list|,
name|Q_PRIMITIVE_TYPE
argument_list|)
expr_stmt|;
end_expr_stmt
begin_decl_stmt
name|class
name|Q_GUI_EXPORT
name|QPaintEngine
block|{
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QPaintEngine
argument_list|)
name|public
label|:
enum|enum
name|PaintEngineFeature
block|{
name|PrimitiveTransform
init|=
literal|0x00000001
block|,
comment|// Can transform primitives brushes
name|PatternTransform
init|=
literal|0x00000002
block|,
comment|// Can transform pattern brushes
name|PixmapTransform
init|=
literal|0x00000004
block|,
comment|// Can transform pixmaps
name|PatternBrush
init|=
literal|0x00000008
block|,
comment|// Can fill with pixmaps and standard patterns
name|LinearGradientFill
init|=
literal|0x00000010
block|,
comment|// Can fill gradient areas
name|RadialGradientFill
init|=
literal|0x00000020
block|,
comment|// Can render radial gradients
name|ConicalGradientFill
init|=
literal|0x00000040
block|,
comment|// Can render conical gradients
name|AlphaBlend
init|=
literal|0x00000080
block|,
comment|// Can do source over alpha blend
name|PorterDuff
init|=
literal|0x00000100
block|,
comment|// Can do general porter duff compositions
name|PainterPaths
init|=
literal|0x00000200
block|,
comment|// Can fill, outline and clip paths
name|Antialiasing
init|=
literal|0x00000400
block|,
comment|// Can antialias lines
name|BrushStroke
init|=
literal|0x00000800
block|,
comment|// Can render brush based pens
name|ConstantOpacity
init|=
literal|0x00001000
block|,
comment|// Can render at constant opacity
name|MaskedBrush
init|=
literal|0x00002000
block|,
comment|// Can fill with textures that has an alpha channel or mask
name|PerspectiveTransform
init|=
literal|0x00004000
block|,
comment|// Can do perspective transformations
name|BlendModes
init|=
literal|0x00008000
block|,
comment|// Can do extended Porter&Duff composition
name|ObjectBoundingModeGradients
init|=
literal|0x00010000
block|,
comment|// Can do object bounding mode gradients
name|RasterOpModes
init|=
literal|0x00020000
block|,
comment|// Can do logical raster operations
name|PaintOutsidePaintEvent
init|=
literal|0x20000000
block|,
comment|// Engine is capable of painting outside paint events
comment|/*                          0x10000000, // Used for emulating                                     QGradient::StretchToDevice,                                     defined in qpainter.cpp                                      0x40000000, // Used internally for emulating opaque backgrounds         */
name|AllFeatures
init|=
literal|0xffffffff
comment|// For convenience
block|}
enum|;
name|Q_DECLARE_FLAGS
argument_list|(
name|PaintEngineFeatures
argument_list|,
name|PaintEngineFeature
argument_list|)
expr|enum
name|DirtyFlag
block|{
name|DirtyPen
operator|=
literal|0x0001
block|,
name|DirtyBrush
operator|=
literal|0x0002
block|,
name|DirtyBrushOrigin
operator|=
literal|0x0004
block|,
name|DirtyFont
operator|=
literal|0x0008
block|,
name|DirtyBackground
operator|=
literal|0x0010
block|,
name|DirtyBackgroundMode
operator|=
literal|0x0020
block|,
name|DirtyTransform
operator|=
literal|0x0040
block|,
name|DirtyClipRegion
operator|=
literal|0x0080
block|,
name|DirtyClipPath
operator|=
literal|0x0100
block|,
name|DirtyHints
operator|=
literal|0x0200
block|,
name|DirtyCompositionMode
operator|=
literal|0x0400
block|,
name|DirtyClipEnabled
operator|=
literal|0x0800
block|,
name|DirtyOpacity
operator|=
literal|0x1000
block|,
name|AllDirty
operator|=
literal|0xffff
block|}
expr_stmt|;
name|Q_DECLARE_FLAGS
argument_list|(
name|DirtyFlags
argument_list|,
name|DirtyFlag
argument_list|)
expr|enum
name|PolygonDrawMode
block|{
name|OddEvenMode
block|,
name|WindingMode
block|,
name|ConvexMode
block|,
name|PolylineMode
block|}
expr_stmt|;
name|explicit
name|QPaintEngine
parameter_list|(
name|PaintEngineFeatures
name|features
init|=
literal|0
parameter_list|)
function_decl|;
name|virtual
operator|~
name|QPaintEngine
argument_list|()
expr_stmt|;
name|bool
name|isActive
argument_list|()
specifier|const
block|{
return|return
name|active
return|;
block|}
name|void
name|setActive
parameter_list|(
name|bool
name|newState
parameter_list|)
block|{
name|active
operator|=
name|newState
expr_stmt|;
block|}
name|virtual
name|bool
name|begin
parameter_list|(
name|QPaintDevice
modifier|*
name|pdev
parameter_list|)
init|=
literal|0
function_decl|;
name|virtual
name|bool
name|end
parameter_list|()
init|=
literal|0
function_decl|;
name|virtual
name|void
name|updateState
parameter_list|(
specifier|const
name|QPaintEngineState
modifier|&
name|state
parameter_list|)
init|=
literal|0
function_decl|;
name|virtual
name|void
name|drawRects
parameter_list|(
specifier|const
name|QRect
modifier|*
name|rects
parameter_list|,
name|int
name|rectCount
parameter_list|)
function_decl|;
name|virtual
name|void
name|drawRects
parameter_list|(
specifier|const
name|QRectF
modifier|*
name|rects
parameter_list|,
name|int
name|rectCount
parameter_list|)
function_decl|;
name|virtual
name|void
name|drawLines
parameter_list|(
specifier|const
name|QLine
modifier|*
name|lines
parameter_list|,
name|int
name|lineCount
parameter_list|)
function_decl|;
name|virtual
name|void
name|drawLines
parameter_list|(
specifier|const
name|QLineF
modifier|*
name|lines
parameter_list|,
name|int
name|lineCount
parameter_list|)
function_decl|;
name|virtual
name|void
name|drawEllipse
parameter_list|(
specifier|const
name|QRectF
modifier|&
name|r
parameter_list|)
function_decl|;
name|virtual
name|void
name|drawEllipse
parameter_list|(
specifier|const
name|QRect
modifier|&
name|r
parameter_list|)
function_decl|;
name|virtual
name|void
name|drawPath
parameter_list|(
specifier|const
name|QPainterPath
modifier|&
name|path
parameter_list|)
function_decl|;
name|virtual
name|void
name|drawPoints
parameter_list|(
specifier|const
name|QPointF
modifier|*
name|points
parameter_list|,
name|int
name|pointCount
parameter_list|)
function_decl|;
name|virtual
name|void
name|drawPoints
parameter_list|(
specifier|const
name|QPoint
modifier|*
name|points
parameter_list|,
name|int
name|pointCount
parameter_list|)
function_decl|;
name|virtual
name|void
name|drawPolygon
parameter_list|(
specifier|const
name|QPointF
modifier|*
name|points
parameter_list|,
name|int
name|pointCount
parameter_list|,
name|PolygonDrawMode
name|mode
parameter_list|)
function_decl|;
name|virtual
name|void
name|drawPolygon
parameter_list|(
specifier|const
name|QPoint
modifier|*
name|points
parameter_list|,
name|int
name|pointCount
parameter_list|,
name|PolygonDrawMode
name|mode
parameter_list|)
function_decl|;
name|virtual
name|void
name|drawPixmap
parameter_list|(
specifier|const
name|QRectF
modifier|&
name|r
parameter_list|,
specifier|const
name|QPixmap
modifier|&
name|pm
parameter_list|,
specifier|const
name|QRectF
modifier|&
name|sr
parameter_list|)
init|=
literal|0
function_decl|;
name|virtual
name|void
name|drawTextItem
parameter_list|(
specifier|const
name|QPointF
modifier|&
name|p
parameter_list|,
specifier|const
name|QTextItem
modifier|&
name|textItem
parameter_list|)
function_decl|;
name|virtual
name|void
name|drawTiledPixmap
parameter_list|(
specifier|const
name|QRectF
modifier|&
name|r
parameter_list|,
specifier|const
name|QPixmap
modifier|&
name|pixmap
parameter_list|,
specifier|const
name|QPointF
modifier|&
name|s
parameter_list|)
function_decl|;
name|virtual
name|void
name|drawImage
argument_list|(
specifier|const
name|QRectF
operator|&
name|r
argument_list|,
specifier|const
name|QImage
operator|&
name|pm
argument_list|,
specifier|const
name|QRectF
operator|&
name|sr
argument_list|,
name|Qt
operator|::
name|ImageConversionFlags
name|flags
operator|=
name|Qt
operator|::
name|AutoColor
argument_list|)
decl_stmt|;
name|void
name|setPaintDevice
parameter_list|(
name|QPaintDevice
modifier|*
name|device
parameter_list|)
function_decl|;
name|QPaintDevice
operator|*
name|paintDevice
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setSystemClip
parameter_list|(
specifier|const
name|QRegion
modifier|&
name|baseClip
parameter_list|)
function_decl|;
name|QRegion
name|systemClip
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setSystemRect
parameter_list|(
specifier|const
name|QRect
modifier|&
name|rect
parameter_list|)
function_decl|;
name|QRect
name|systemRect
argument_list|()
specifier|const
expr_stmt|;
name|virtual
name|QPoint
name|coordinateOffset
argument_list|()
specifier|const
expr_stmt|;
enum|enum
name|Type
block|{
name|X11
block|,
name|Windows
block|,
name|QuickDraw
block|,
name|CoreGraphics
block|,
name|MacPrinter
block|,
name|QWindowSystem
block|,
name|PostScript
block|,
comment|// ### Qt 6: Remove, update documentation
name|OpenGL
block|,
name|Picture
block|,
name|SVG
block|,
name|Raster
block|,
name|Direct3D
block|,
name|Pdf
block|,
name|OpenVG
block|,
name|OpenGL2
block|,
name|PaintBuffer
block|,
name|Blitter
block|,
name|Direct2D
block|,
name|User
init|=
literal|50
block|,
comment|// first user type id
name|MaxUser
init|=
literal|100
comment|// last user type id
block|}
enum|;
name|virtual
name|Type
name|type
argument_list|()
specifier|const
operator|=
literal|0
expr_stmt|;
specifier|inline
name|void
name|fix_neg_rect
parameter_list|(
name|int
modifier|*
name|x
parameter_list|,
name|int
modifier|*
name|y
parameter_list|,
name|int
modifier|*
name|w
parameter_list|,
name|int
modifier|*
name|h
parameter_list|)
function_decl|;
specifier|inline
name|bool
name|testDirty
parameter_list|(
name|DirtyFlags
name|df
parameter_list|)
function_decl|;
specifier|inline
name|void
name|setDirty
parameter_list|(
name|DirtyFlags
name|df
parameter_list|)
function_decl|;
specifier|inline
name|void
name|clearDirty
parameter_list|(
name|DirtyFlags
name|df
parameter_list|)
function_decl|;
name|bool
name|hasFeature
argument_list|(
name|PaintEngineFeatures
name|feature
argument_list|)
decl|const
block|{
return|return
operator|(
name|gccaps
operator|&
name|feature
operator|)
operator|!=
literal|0
return|;
block|}
name|QPainter
operator|*
name|painter
argument_list|()
specifier|const
expr_stmt|;
name|void
name|syncState
parameter_list|()
function_decl|;
specifier|inline
name|bool
name|isExtended
argument_list|()
specifier|const
block|{
return|return
name|extended
return|;
block|}
name|protected
label|:
name|QPaintEngine
argument_list|(
argument|QPaintEnginePrivate&data
argument_list|,
argument|PaintEngineFeatures devcaps=
literal|0
argument_list|)
empty_stmt|;
name|QPaintEngineState
modifier|*
name|state
decl_stmt|;
name|PaintEngineFeatures
name|gccaps
decl_stmt|;
name|uint
name|active
range|:
literal|1
decl_stmt|;
name|uint
name|selfDestruct
range|:
literal|1
decl_stmt|;
name|uint
name|extended
range|:
literal|1
decl_stmt|;
name|QScopedPointer
operator|<
name|QPaintEnginePrivate
operator|>
name|d_ptr
expr_stmt|;
name|private
label|:
name|void
name|setAutoDestruct
parameter_list|(
name|bool
name|autoDestr
parameter_list|)
block|{
name|selfDestruct
operator|=
name|autoDestr
expr_stmt|;
block|}
name|bool
name|autoDestruct
argument_list|()
specifier|const
block|{
return|return
name|selfDestruct
return|;
block|}
name|Q_DISABLE_COPY
argument_list|(
argument|QPaintEngine
argument_list|)
name|friend
name|class
name|QPainterReplayer
decl_stmt|;
name|friend
name|class
name|QFontEngineBox
decl_stmt|;
name|friend
name|class
name|QFontEngineMac
decl_stmt|;
name|friend
name|class
name|QFontEngineWin
decl_stmt|;
name|friend
name|class
name|QMacPrintEngine
decl_stmt|;
name|friend
name|class
name|QMacPrintEnginePrivate
decl_stmt|;
name|friend
name|class
name|QFontEngineQPF2
decl_stmt|;
name|friend
name|class
name|QPainter
decl_stmt|;
name|friend
name|class
name|QPainterPrivate
decl_stmt|;
name|friend
name|class
name|QWidget
decl_stmt|;
name|friend
name|class
name|QWidgetPrivate
decl_stmt|;
name|friend
name|class
name|QWin32PaintEngine
decl_stmt|;
name|friend
name|class
name|QWin32PaintEnginePrivate
decl_stmt|;
name|friend
name|class
name|QMacCGContext
decl_stmt|;
name|friend
name|class
name|QPreviewPaintEngine
decl_stmt|;
name|friend
name|class
name|QX11GLPlatformPixmap
decl_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_decl_stmt
name|class
name|Q_GUI_EXPORT
name|QPaintEngineState
block|{
name|public
label|:
name|QPaintEngine
operator|::
name|DirtyFlags
name|state
argument_list|()
specifier|const
block|{
return|return
name|dirtyFlags
return|;
block|}
name|QPen
name|pen
argument_list|()
specifier|const
expr_stmt|;
name|QBrush
name|brush
argument_list|()
specifier|const
expr_stmt|;
name|QPointF
name|brushOrigin
argument_list|()
specifier|const
expr_stmt|;
name|QBrush
name|backgroundBrush
argument_list|()
specifier|const
expr_stmt|;
name|Qt
operator|::
name|BGMode
name|backgroundMode
argument_list|()
specifier|const
expr_stmt|;
name|QFont
name|font
argument_list|()
specifier|const
expr_stmt|;
name|QMatrix
name|matrix
argument_list|()
specifier|const
expr_stmt|;
name|QTransform
name|transform
argument_list|()
specifier|const
expr_stmt|;
name|Qt
operator|::
name|ClipOperation
name|clipOperation
argument_list|()
specifier|const
expr_stmt|;
name|QRegion
name|clipRegion
argument_list|()
specifier|const
expr_stmt|;
name|QPainterPath
name|clipPath
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|isClipEnabled
argument_list|()
specifier|const
expr_stmt|;
name|QPainter
operator|::
name|RenderHints
name|renderHints
argument_list|()
specifier|const
expr_stmt|;
name|QPainter
operator|::
name|CompositionMode
name|compositionMode
argument_list|()
specifier|const
expr_stmt|;
name|qreal
name|opacity
argument_list|()
specifier|const
expr_stmt|;
name|QPainter
operator|*
name|painter
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|brushNeedsResolving
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|penNeedsResolving
argument_list|()
specifier|const
expr_stmt|;
name|protected
label|:
name|friend
name|class
name|QPaintEngine
decl_stmt|;
name|friend
name|class
name|QRasterPaintEngine
decl_stmt|;
name|friend
name|class
name|QWidget
decl_stmt|;
name|friend
name|class
name|QPainter
decl_stmt|;
name|friend
name|class
name|QPainterPrivate
decl_stmt|;
name|friend
name|class
name|QMacPrintEnginePrivate
decl_stmt|;
name|QPaintEngine
operator|::
name|DirtyFlags
name|dirtyFlags
expr_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_comment
comment|//
end_comment
begin_comment
comment|// inline functions
end_comment
begin_comment
comment|//
end_comment
begin_expr_stmt
DECL|function|fix_neg_rect
specifier|inline
name|void
name|QPaintEngine
operator|::
name|fix_neg_rect
argument_list|(
argument|int *x
argument_list|,
argument|int *y
argument_list|,
argument|int *w
argument_list|,
argument|int *h
argument_list|)
block|{
if|if
condition|(
operator|*
name|w
operator|<
literal|0
condition|)
block|{
operator|*
name|w
operator|=
operator|-
operator|*
name|w
expr_stmt|;
operator|*
name|x
operator|-=
operator|*
name|w
operator|-
literal|1
expr_stmt|;
block|}
end_expr_stmt
begin_if
if|if
condition|(
operator|*
name|h
operator|<
literal|0
condition|)
block|{
operator|*
name|h
operator|=
operator|-
operator|*
name|h
expr_stmt|;
operator|*
name|y
operator|-=
operator|*
name|h
operator|-
literal|1
expr_stmt|;
block|}
end_if
begin_expr_stmt
unit|}  inline
DECL|function|testDirty
name|bool
name|QPaintEngine
operator|::
name|testDirty
argument_list|(
argument|DirtyFlags df
argument_list|)
block|{
name|Q_ASSERT
argument_list|(
name|state
argument_list|)
block|;
return|return
operator|(
operator|(
name|state
operator|->
name|dirtyFlags
operator|&
name|df
operator|)
operator|!=
literal|0
operator|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|setDirty
specifier|inline
name|void
name|QPaintEngine
operator|::
name|setDirty
argument_list|(
argument|DirtyFlags df
argument_list|)
block|{
name|Q_ASSERT
argument_list|(
name|state
argument_list|)
block|;
name|state
operator|->
name|dirtyFlags
operator||=
name|df
block|; }
DECL|function|clearDirty
specifier|inline
name|void
name|QPaintEngine
operator|::
name|clearDirty
argument_list|(
argument|DirtyFlags df
argument_list|)
block|{
name|Q_ASSERT
argument_list|(
name|state
argument_list|)
block|;
name|state
operator|->
name|dirtyFlags
operator|&=
operator|~
name|static_cast
operator|<
name|uint
operator|>
operator|(
name|df
operator|)
block|; }
name|Q_DECLARE_OPERATORS_FOR_FLAGS
argument_list|(
argument|QTextItem::RenderFlags
argument_list|)
name|Q_DECLARE_OPERATORS_FOR_FLAGS
argument_list|(
argument|QPaintEngine::PaintEngineFeatures
argument_list|)
name|Q_DECLARE_OPERATORS_FOR_FLAGS
argument_list|(
argument|QPaintEngine::DirtyFlags
argument_list|)
name|QT_END_NAMESPACE
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QPAINTENGINE_H
end_comment
end_unit
