begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QPAINTER_P_H
end_ifndef
begin_define
DECL|macro|QPAINTER_P_H
define|#
directive|define
name|QPAINTER_P_H
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
file|"QtGui/qbrush.h"
end_include
begin_include
include|#
directive|include
file|"QtGui/qfont.h"
end_include
begin_include
include|#
directive|include
file|"QtGui/qpen.h"
end_include
begin_include
include|#
directive|include
file|"QtGui/qregion.h"
end_include
begin_include
include|#
directive|include
file|"QtGui/qmatrix.h"
end_include
begin_include
include|#
directive|include
file|"QtGui/qpainter.h"
end_include
begin_include
include|#
directive|include
file|"QtGui/qpainterpath.h"
end_include
begin_include
include|#
directive|include
file|"QtGui/qpaintengine.h"
end_include
begin_include
include|#
directive|include
file|<private/qpen_p.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QPaintEngine
name|class
name|QPaintEngine
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QEmulationPaintEngine
name|class
name|QEmulationPaintEngine
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QPaintEngineEx
name|class
name|QPaintEngineEx
decl_stmt|;
end_decl_stmt
begin_struct_decl
struct_decl|struct
name|QFixedPoint
struct_decl|;
end_struct_decl
begin_struct_decl
struct_decl|struct
name|QTLWExtra
struct_decl|;
end_struct_decl
begin_struct
DECL|struct|DataPtrContainer
struct|struct
name|DataPtrContainer
block|{
DECL|member|ptr
name|void
modifier|*
name|ptr
decl_stmt|;
block|}
struct|;
end_struct
begin_function
DECL|function|data_ptr
specifier|inline
specifier|const
name|void
modifier|*
name|data_ptr
parameter_list|(
specifier|const
name|QTransform
modifier|&
name|t
parameter_list|)
block|{
return|return
operator|(
specifier|const
name|DataPtrContainer
operator|*
operator|)
operator|&
name|t
return|;
block|}
end_function
begin_function
DECL|function|qtransform_fast_equals
specifier|inline
name|bool
name|qtransform_fast_equals
parameter_list|(
specifier|const
name|QTransform
modifier|&
name|a
parameter_list|,
specifier|const
name|QTransform
modifier|&
name|b
parameter_list|)
block|{
return|return
name|data_ptr
argument_list|(
name|a
argument_list|)
operator|==
name|data_ptr
argument_list|(
name|b
argument_list|)
return|;
block|}
end_function
begin_comment
comment|// QPen inline functions...
end_comment
begin_expr_stmt
DECL|function|data_ptr
specifier|inline
name|QPen
operator|::
name|DataPtr
operator|&
name|data_ptr
argument_list|(
argument|const QPen&p
argument_list|)
block|{
return|return
name|const_cast
operator|<
name|QPen
operator|&
operator|>
operator|(
name|p
operator|)
operator|.
name|data_ptr
argument_list|()
return|;
block|}
end_expr_stmt
begin_function
DECL|function|qpen_fast_equals
specifier|inline
name|bool
name|qpen_fast_equals
parameter_list|(
specifier|const
name|QPen
modifier|&
name|a
parameter_list|,
specifier|const
name|QPen
modifier|&
name|b
parameter_list|)
block|{
return|return
name|data_ptr
argument_list|(
name|a
argument_list|)
operator|==
name|data_ptr
argument_list|(
name|b
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|qpen_brush
specifier|inline
name|QBrush
name|qpen_brush
parameter_list|(
specifier|const
name|QPen
modifier|&
name|p
parameter_list|)
block|{
return|return
name|data_ptr
argument_list|(
name|p
argument_list|)
operator|->
name|brush
return|;
block|}
end_function
begin_function
DECL|function|qpen_widthf
specifier|inline
name|qreal
name|qpen_widthf
parameter_list|(
specifier|const
name|QPen
modifier|&
name|p
parameter_list|)
block|{
return|return
name|data_ptr
argument_list|(
name|p
argument_list|)
operator|->
name|width
return|;
block|}
end_function
begin_expr_stmt
DECL|function|qpen_style
specifier|inline
name|Qt
operator|::
name|PenStyle
name|qpen_style
argument_list|(
argument|const QPen&p
argument_list|)
block|{
return|return
name|data_ptr
argument_list|(
name|p
argument_list|)
operator|->
name|style
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|qpen_capStyle
specifier|inline
name|Qt
operator|::
name|PenCapStyle
name|qpen_capStyle
argument_list|(
argument|const QPen&p
argument_list|)
block|{
return|return
name|data_ptr
argument_list|(
name|p
argument_list|)
operator|->
name|capStyle
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|qpen_joinStyle
specifier|inline
name|Qt
operator|::
name|PenJoinStyle
name|qpen_joinStyle
argument_list|(
argument|const QPen&p
argument_list|)
block|{
return|return
name|data_ptr
argument_list|(
name|p
argument_list|)
operator|->
name|joinStyle
return|;
block|}
end_expr_stmt
begin_comment
comment|// QBrush inline functions...
end_comment
begin_expr_stmt
DECL|function|data_ptr
specifier|inline
name|QBrush
operator|::
name|DataPtr
operator|&
name|data_ptr
argument_list|(
argument|const QBrush&p
argument_list|)
block|{
return|return
name|const_cast
operator|<
name|QBrush
operator|&
operator|>
operator|(
name|p
operator|)
operator|.
name|data_ptr
argument_list|()
return|;
block|}
end_expr_stmt
begin_function
DECL|function|qbrush_fast_equals
specifier|inline
name|bool
name|qbrush_fast_equals
parameter_list|(
specifier|const
name|QBrush
modifier|&
name|a
parameter_list|,
specifier|const
name|QBrush
modifier|&
name|b
parameter_list|)
block|{
return|return
name|data_ptr
argument_list|(
name|a
argument_list|)
operator|==
name|data_ptr
argument_list|(
name|b
argument_list|)
return|;
block|}
end_function
begin_expr_stmt
DECL|function|qbrush_style
specifier|inline
name|Qt
operator|::
name|BrushStyle
name|qbrush_style
argument_list|(
argument|const QBrush&b
argument_list|)
block|{
return|return
name|data_ptr
argument_list|(
name|b
argument_list|)
operator|->
name|style
return|;
block|}
end_expr_stmt
begin_function
DECL|function|qbrush_color
specifier|inline
specifier|const
name|QColor
modifier|&
name|qbrush_color
parameter_list|(
specifier|const
name|QBrush
modifier|&
name|b
parameter_list|)
block|{
return|return
name|data_ptr
argument_list|(
name|b
argument_list|)
operator|->
name|color
return|;
block|}
end_function
begin_function
DECL|function|qbrush_has_transform
specifier|inline
name|bool
name|qbrush_has_transform
parameter_list|(
specifier|const
name|QBrush
modifier|&
name|b
parameter_list|)
block|{
return|return
name|data_ptr
argument_list|(
name|b
argument_list|)
operator|->
name|transform
operator|.
name|type
argument_list|()
operator|>
name|QTransform
operator|::
name|TxNone
return|;
block|}
end_function
begin_decl_stmt
name|class
name|QPainterClipInfo
block|{
name|public
label|:
enum|enum
name|ClipType
block|{
name|RegionClip
block|,
name|PathClip
block|,
name|RectClip
block|,
name|RectFClip
block|}
enum|;
name|QPainterClipInfo
argument_list|(
argument|const QPainterPath&p
argument_list|,
argument|Qt::ClipOperation op
argument_list|,
argument|const QTransform&m
argument_list|)
block|:
name|clipType
argument_list|(
name|PathClip
argument_list|)
operator|,
name|matrix
argument_list|(
name|m
argument_list|)
operator|,
name|operation
argument_list|(
name|op
argument_list|)
operator|,
name|path
argument_list|(
argument|p
argument_list|)
block|{ }
name|QPainterClipInfo
argument_list|(
argument|const QRegion&r
argument_list|,
argument|Qt::ClipOperation op
argument_list|,
argument|const QTransform&m
argument_list|)
operator|:
name|clipType
argument_list|(
name|RegionClip
argument_list|)
operator|,
name|matrix
argument_list|(
name|m
argument_list|)
operator|,
name|operation
argument_list|(
name|op
argument_list|)
operator|,
name|region
argument_list|(
argument|r
argument_list|)
block|{ }
name|QPainterClipInfo
argument_list|(
argument|const QRect&r
argument_list|,
argument|Qt::ClipOperation op
argument_list|,
argument|const QTransform&m
argument_list|)
operator|:
name|clipType
argument_list|(
name|RectClip
argument_list|)
operator|,
name|matrix
argument_list|(
name|m
argument_list|)
operator|,
name|operation
argument_list|(
name|op
argument_list|)
operator|,
name|rect
argument_list|(
argument|r
argument_list|)
block|{ }
name|QPainterClipInfo
argument_list|(
argument|const QRectF&r
argument_list|,
argument|Qt::ClipOperation op
argument_list|,
argument|const QTransform&m
argument_list|)
operator|:
name|clipType
argument_list|(
name|RectFClip
argument_list|)
operator|,
name|matrix
argument_list|(
name|m
argument_list|)
operator|,
name|operation
argument_list|(
name|op
argument_list|)
operator|,
name|rectf
argument_list|(
argument|r
argument_list|)
block|{ }
name|ClipType
name|clipType
expr_stmt|;
name|QTransform
name|matrix
decl_stmt|;
name|Qt
operator|::
name|ClipOperation
name|operation
expr_stmt|;
name|QPainterPath
name|path
decl_stmt|;
name|QRegion
name|region
decl_stmt|;
name|QRect
name|rect
decl_stmt|;
name|QRectF
name|rectf
decl_stmt|;
comment|// ###
comment|//     union {
comment|//         QRegionData *d;
comment|//         QPainterPathPrivate *pathData;
comment|//         struct {
comment|//             int x, y, w, h;
comment|//         } rectData;
comment|//         struct {
comment|//             qreal x, y, w, h;
comment|//         } rectFData;
comment|//     };
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_decl_stmt
name|class
name|Q_GUI_EXPORT
name|QPainterState
range|:
name|public
name|QPaintEngineState
block|{
name|public
operator|:
name|QPainterState
argument_list|()
block|;
name|QPainterState
argument_list|(
specifier|const
name|QPainterState
operator|*
name|s
argument_list|)
block|;
name|virtual
operator|~
name|QPainterState
argument_list|()
block|;
name|void
name|init
argument_list|(
name|QPainter
operator|*
name|p
argument_list|)
block|;
name|QPointF
name|brushOrigin
block|;
name|QFont
name|font
block|;
name|QFont
name|deviceFont
block|;
name|QPen
name|pen
block|;
name|QBrush
name|brush
block|;
name|QBrush
name|bgBrush
block|;
comment|// background brush
name|QRegion
name|clipRegion
block|;
name|QPainterPath
name|clipPath
block|;
name|Qt
operator|::
name|ClipOperation
name|clipOperation
block|;
name|QPainter
operator|::
name|RenderHints
name|renderHints
block|;
name|QList
operator|<
name|QPainterClipInfo
operator|>
name|clipInfo
block|;
comment|// ### Make me smaller and faster to copy around...
name|QTransform
name|worldMatrix
block|;
comment|// World transformation matrix, not window and viewport
name|QTransform
name|matrix
block|;
comment|// Complete transformation matrix,
name|QTransform
name|redirectionMatrix
block|;
name|int
name|wx
block|,
name|wy
block|,
name|ww
block|,
name|wh
block|;
comment|// window rectangle
name|int
name|vx
block|,
name|vy
block|,
name|vw
block|,
name|vh
block|;
comment|// viewport rectangle
name|qreal
name|opacity
block|;
name|uint
name|WxF
operator|:
literal|1
block|;
comment|// World transformation
name|uint
name|VxF
operator|:
literal|1
block|;
comment|// View transformation
name|uint
name|clipEnabled
operator|:
literal|1
block|;
name|Qt
operator|::
name|BGMode
name|bgMode
block|;
name|QPainter
operator|*
name|painter
block|;
name|Qt
operator|::
name|LayoutDirection
name|layoutDirection
block|;
name|QPainter
operator|::
name|CompositionMode
name|composition_mode
block|;
name|uint
name|emulationSpecifier
block|;
name|uint
name|changeFlags
block|; }
decl_stmt|;
end_decl_stmt
begin_struct
DECL|struct|QPainterDummyState
struct|struct
name|QPainterDummyState
block|{
DECL|member|font
name|QFont
name|font
decl_stmt|;
DECL|member|pen
name|QPen
name|pen
decl_stmt|;
DECL|member|brush
name|QBrush
name|brush
decl_stmt|;
DECL|member|transform
name|QTransform
name|transform
decl_stmt|;
block|}
struct|;
end_struct
begin_decl_stmt
DECL|variable|QRawFont
name|class
name|QRawFont
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QPainterPrivate
block|{
name|Q_DECLARE_PUBLIC
argument_list|(
argument|QPainter
argument_list|)
name|public
label|:
name|QPainterPrivate
argument_list|(
name|QPainter
operator|*
name|painter
argument_list|)
operator|:
name|q_ptr
argument_list|(
name|painter
argument_list|)
operator|,
name|d_ptrs
argument_list|(
literal|0
argument_list|)
operator|,
name|state
argument_list|(
literal|0
argument_list|)
operator|,
name|dummyState
argument_list|(
literal|0
argument_list|)
operator|,
name|txinv
argument_list|(
literal|0
argument_list|)
operator|,
name|inDestructor
argument_list|(
name|false
argument_list|)
operator|,
name|d_ptrs_size
argument_list|(
literal|0
argument_list|)
operator|,
name|refcount
argument_list|(
literal|1
argument_list|)
operator|,
name|device
argument_list|(
literal|0
argument_list|)
operator|,
name|original_device
argument_list|(
literal|0
argument_list|)
operator|,
name|helper_device
argument_list|(
literal|0
argument_list|)
operator|,
name|engine
argument_list|(
literal|0
argument_list|)
operator|,
name|emulationEngine
argument_list|(
literal|0
argument_list|)
operator|,
name|extended
argument_list|(
literal|0
argument_list|)
block|{     }
operator|~
name|QPainterPrivate
argument_list|()
expr_stmt|;
name|QPainter
modifier|*
name|q_ptr
decl_stmt|;
name|QPainterPrivate
modifier|*
modifier|*
name|d_ptrs
decl_stmt|;
name|QPainterState
modifier|*
name|state
decl_stmt|;
name|QVector
operator|<
name|QPainterState
operator|*
operator|>
name|states
expr_stmt|;
name|mutable
name|QPainterDummyState
modifier|*
name|dummyState
decl_stmt|;
name|QTransform
name|invMatrix
decl_stmt|;
name|uint
name|txinv
range|:
literal|1
decl_stmt|;
name|uint
name|inDestructor
range|:
literal|1
decl_stmt|;
name|uint
name|d_ptrs_size
decl_stmt|;
name|uint
name|refcount
decl_stmt|;
enum|enum
name|DrawOperation
block|{
name|StrokeDraw
init|=
literal|0x1
block|,
name|FillDraw
init|=
literal|0x2
block|,
name|StrokeAndFillDraw
init|=
literal|0x3
block|}
enum|;
name|QPainterDummyState
operator|*
name|fakeState
argument_list|()
specifier|const
block|{
if|if
condition|(
operator|!
name|dummyState
condition|)
name|dummyState
operator|=
name|new
name|QPainterDummyState
argument_list|()
expr_stmt|;
return|return
name|dummyState
return|;
block|}
end_decl_stmt
begin_function_decl
name|void
name|updateEmulationSpecifier
parameter_list|(
name|QPainterState
modifier|*
name|s
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|updateStateImpl
parameter_list|(
name|QPainterState
modifier|*
name|state
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|updateState
parameter_list|(
name|QPainterState
modifier|*
name|state
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|draw_helper
parameter_list|(
specifier|const
name|QPainterPath
modifier|&
name|path
parameter_list|,
name|DrawOperation
name|operation
init|=
name|StrokeAndFillDraw
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|drawStretchedGradient
parameter_list|(
specifier|const
name|QPainterPath
modifier|&
name|path
parameter_list|,
name|DrawOperation
name|operation
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|drawOpaqueBackground
parameter_list|(
specifier|const
name|QPainterPath
modifier|&
name|path
parameter_list|,
name|DrawOperation
name|operation
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
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
name|_ti
parameter_list|,
name|QTextEngine
modifier|*
name|textEngine
parameter_list|)
function_decl|;
end_function_decl
begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|QT_NO_RAWFONT
argument_list|)
end_if
begin_function_decl
name|void
name|drawGlyphs
parameter_list|(
specifier|const
name|quint32
modifier|*
name|glyphArray
parameter_list|,
name|QFixedPoint
modifier|*
name|positionArray
parameter_list|,
name|int
name|glyphCount
parameter_list|,
name|QFontEngine
modifier|*
name|fontEngine
parameter_list|,
name|bool
name|overline
init|=
name|false
parameter_list|,
name|bool
name|underline
init|=
name|false
parameter_list|,
name|bool
name|strikeOut
init|=
name|false
parameter_list|)
function_decl|;
end_function_decl
begin_endif
endif|#
directive|endif
end_endif
begin_function_decl
name|void
name|updateMatrix
parameter_list|()
function_decl|;
end_function_decl
begin_function_decl
name|void
name|updateInvMatrix
parameter_list|()
function_decl|;
end_function_decl
begin_function_decl
name|void
name|checkEmulation
parameter_list|()
function_decl|;
end_function_decl
begin_function
specifier|static
name|QPainterPrivate
modifier|*
name|get
parameter_list|(
name|QPainter
modifier|*
name|painter
parameter_list|)
block|{
return|return
name|painter
operator|->
name|d_ptr
operator|.
name|data
argument_list|()
return|;
block|}
end_function
begin_expr_stmt
name|QTransform
name|viewTransform
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|qreal
name|effectiveDevicePixelRatio
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|QTransform
name|hidpiScaleTransform
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_function_decl
specifier|static
name|bool
name|attachPainterPrivate
parameter_list|(
name|QPainter
modifier|*
name|q
parameter_list|,
name|QPaintDevice
modifier|*
name|pdev
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|detachPainterPrivate
parameter_list|(
name|QPainter
modifier|*
name|q
parameter_list|)
function_decl|;
end_function_decl
begin_decl_stmt
name|QPaintDevice
modifier|*
name|device
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QPaintDevice
modifier|*
name|original_device
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QPaintDevice
modifier|*
name|helper_device
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QPaintEngine
modifier|*
name|engine
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QEmulationPaintEngine
modifier|*
name|emulationEngine
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QPaintEngineEx
modifier|*
name|extended
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QBrush
name|colorBrush
decl_stmt|;
end_decl_stmt
begin_comment
comment|// for fill with solid color
end_comment
begin_decl_stmt
unit|};
name|Q_GUI_EXPORT
name|void
name|qt_draw_helper
argument_list|(
name|QPainterPrivate
operator|*
name|p
argument_list|,
specifier|const
name|QPainterPath
operator|&
name|path
argument_list|,
name|QPainterPrivate
operator|::
name|DrawOperation
name|operation
argument_list|)
decl_stmt|;
end_decl_stmt
begin_function_decl
name|QString
name|qt_generate_brush_key
parameter_list|(
specifier|const
name|QBrush
modifier|&
name|brush
parameter_list|)
function_decl|;
end_function_decl
begin_decl_stmt
DECL|function|qt_pen_is_cosmetic
specifier|inline
name|bool
name|qt_pen_is_cosmetic
argument_list|(
specifier|const
name|QPen
operator|&
name|pen
argument_list|,
name|QPainter
operator|::
name|RenderHints
name|hints
argument_list|)
block|{
return|return
name|pen
operator|.
name|isCosmetic
argument_list|()
operator|||
operator|(
name|const_cast
operator|<
name|QPen
operator|&
operator|>
operator|(
name|pen
operator|)
operator|.
name|data_ptr
argument_list|()
operator|->
name|defaultWidth
operator|&&
operator|(
name|hints
operator|&
name|QPainter
operator|::
name|Qt4CompatiblePainting
operator|)
operator|)
return|;
block|}
end_decl_stmt
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QPAINTER_P_H
end_comment
end_unit
