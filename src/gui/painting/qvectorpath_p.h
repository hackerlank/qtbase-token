begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2014 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia. For licensing terms and ** conditions see http://qt.digia.com/licensing. For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights. These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QVECTORPATH_P_H
end_ifndef
begin_define
DECL|macro|QVECTORPATH_P_H
define|#
directive|define
name|QVECTORPATH_P_H
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
file|<QtGui/qpaintengine.h>
end_include
begin_include
include|#
directive|include
file|<private/qpaintengine_p.h>
end_include
begin_include
include|#
directive|include
file|<private/qstroker_p.h>
end_include
begin_include
include|#
directive|include
file|<private/qpainter_p.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QPaintEngineEx
name|class
name|QPaintEngineEx
decl_stmt|;
end_decl_stmt
begin_typedef
DECL|typedef|qvectorpath_cache_cleanup
typedef|typedef
name|void
function_decl|(
modifier|*
name|qvectorpath_cache_cleanup
function_decl|)
parameter_list|(
name|QPaintEngineEx
modifier|*
name|engine
parameter_list|,
name|void
modifier|*
name|data
parameter_list|)
function_decl|;
end_typedef
begin_struct
DECL|struct|QRealRect
struct|struct
name|QRealRect
block|{
DECL|member|x1
DECL|member|y1
DECL|member|x2
DECL|member|y2
name|qreal
name|x1
decl_stmt|,
name|y1
decl_stmt|,
name|x2
decl_stmt|,
name|y2
decl_stmt|;
block|}
struct|;
end_struct
begin_decl_stmt
name|class
name|Q_GUI_EXPORT
name|QVectorPath
block|{
name|public
label|:
enum|enum
name|Hint
block|{
comment|// Shape hints, in 0x000000ff, access using shape()
name|AreaShapeMask
init|=
literal|0x0001
block|,
comment|// shape covers an area
name|NonConvexShapeMask
init|=
literal|0x0002
block|,
comment|// shape is not convex
name|CurvedShapeMask
init|=
literal|0x0004
block|,
comment|// shape contains curves...
name|LinesShapeMask
init|=
literal|0x0008
block|,
name|RectangleShapeMask
init|=
literal|0x0010
block|,
name|ShapeMask
init|=
literal|0x001f
block|,
comment|// Shape hints merged into basic shapes..
name|LinesHint
init|=
name|LinesShapeMask
block|,
name|RectangleHint
init|=
name|AreaShapeMask
operator||
name|RectangleShapeMask
block|,
name|EllipseHint
init|=
name|AreaShapeMask
operator||
name|CurvedShapeMask
block|,
name|ConvexPolygonHint
init|=
name|AreaShapeMask
block|,
name|PolygonHint
init|=
name|AreaShapeMask
operator||
name|NonConvexShapeMask
block|,
name|RoundedRectHint
init|=
name|AreaShapeMask
operator||
name|CurvedShapeMask
block|,
name|ArbitraryShapeHint
init|=
name|AreaShapeMask
operator||
name|NonConvexShapeMask
operator||
name|CurvedShapeMask
block|,
comment|// Other hints
name|IsCachedHint
init|=
literal|0x0100
block|,
comment|// Set if the cache hint is set
name|ShouldUseCacheHint
init|=
literal|0x0200
block|,
comment|// Set if the path should be cached when possible..
name|ControlPointRect
init|=
literal|0x0400
block|,
comment|// Set if the control point rect has been calculated...
comment|// Shape rendering specifiers...
name|OddEvenFill
init|=
literal|0x1000
block|,
name|WindingFill
init|=
literal|0x2000
block|,
name|ImplicitClose
init|=
literal|0x4000
block|}
enum|;
comment|// ### Falcon: introduca a struct XY for points so lars is not so confused...
name|QVectorPath
argument_list|(
argument|const qreal *points
argument_list|,
argument|int count
argument_list|,
argument|const QPainterPath::ElementType *elements =
literal|0
argument_list|,
argument|uint hints = ArbitraryShapeHint
argument_list|)
block|:
name|m_elements
argument_list|(
name|elements
argument_list|)
operator|,
name|m_points
argument_list|(
name|points
argument_list|)
operator|,
name|m_count
argument_list|(
name|count
argument_list|)
operator|,
name|m_hints
argument_list|(
argument|hints
argument_list|)
block|{     }
operator|~
name|QVectorPath
argument_list|()
expr_stmt|;
name|QRectF
name|controlPointRect
argument_list|()
specifier|const
expr_stmt|;
specifier|inline
name|Hint
name|shape
argument_list|()
specifier|const
block|{
return|return
call|(
name|Hint
call|)
argument_list|(
name|m_hints
operator|&
name|ShapeMask
argument_list|)
return|;
block|}
specifier|inline
name|bool
name|isConvex
argument_list|()
specifier|const
block|{
return|return
operator|(
name|m_hints
operator|&
name|NonConvexShapeMask
operator|)
operator|==
literal|0
return|;
block|}
specifier|inline
name|bool
name|isCurved
argument_list|()
specifier|const
block|{
return|return
name|m_hints
operator|&
name|CurvedShapeMask
return|;
block|}
specifier|inline
name|bool
name|isCacheable
argument_list|()
specifier|const
block|{
return|return
name|m_hints
operator|&
name|ShouldUseCacheHint
return|;
block|}
specifier|inline
name|bool
name|hasImplicitClose
argument_list|()
specifier|const
block|{
return|return
name|m_hints
operator|&
name|ImplicitClose
return|;
block|}
specifier|inline
name|bool
name|hasWindingFill
argument_list|()
specifier|const
block|{
return|return
name|m_hints
operator|&
name|WindingFill
return|;
block|}
specifier|inline
name|void
name|makeCacheable
argument_list|()
specifier|const
block|{
name|m_hints
operator||=
name|ShouldUseCacheHint
block|;
name|m_cache
operator|=
literal|0
block|; }
specifier|inline
name|uint
name|hints
argument_list|()
specifier|const
block|{
return|return
name|m_hints
return|;
block|}
specifier|inline
specifier|const
name|QPainterPath
operator|::
name|ElementType
operator|*
name|elements
argument_list|()
specifier|const
block|{
return|return
name|m_elements
return|;
block|}
specifier|inline
specifier|const
name|qreal
operator|*
name|points
argument_list|()
specifier|const
block|{
return|return
name|m_points
return|;
block|}
specifier|inline
name|bool
name|isEmpty
argument_list|()
specifier|const
block|{
return|return
name|m_points
operator|==
literal|0
return|;
block|}
specifier|inline
name|int
name|elementCount
argument_list|()
specifier|const
block|{
return|return
name|m_count
return|;
block|}
specifier|inline
specifier|const
name|QPainterPath
name|convertToPainterPath
argument_list|()
specifier|const
expr_stmt|;
specifier|static
specifier|inline
name|uint
name|polygonFlags
argument_list|(
name|QPaintEngine
operator|::
name|PolygonDrawMode
name|mode
argument_list|)
block|{
switch|switch
condition|(
name|mode
condition|)
block|{
case|case
name|QPaintEngine
operator|::
name|ConvexMode
case|:
return|return
name|ConvexPolygonHint
operator||
name|ImplicitClose
return|;
case|case
name|QPaintEngine
operator|::
name|OddEvenMode
case|:
return|return
name|PolygonHint
operator||
name|OddEvenFill
operator||
name|ImplicitClose
return|;
case|case
name|QPaintEngine
operator|::
name|WindingMode
case|:
return|return
name|PolygonHint
operator||
name|WindingFill
operator||
name|ImplicitClose
return|;
case|case
name|QPaintEngine
operator|::
name|PolylineMode
case|:
return|return
name|PolygonHint
return|;
default|default:
return|return
literal|0
return|;
block|}
block|}
struct|struct
name|CacheEntry
block|{
name|QPaintEngineEx
modifier|*
name|engine
decl_stmt|;
name|void
modifier|*
name|data
decl_stmt|;
name|qvectorpath_cache_cleanup
name|cleanup
decl_stmt|;
name|CacheEntry
modifier|*
name|next
decl_stmt|;
block|}
struct|;
name|CacheEntry
modifier|*
name|addCacheData
argument_list|(
name|QPaintEngineEx
operator|*
name|engine
argument_list|,
name|void
operator|*
name|data
argument_list|,
name|qvectorpath_cache_cleanup
name|cleanup
argument_list|)
decl|const
decl_stmt|;
specifier|inline
name|CacheEntry
modifier|*
name|lookupCacheData
argument_list|(
name|QPaintEngineEx
operator|*
name|engine
argument_list|)
decl|const
block|{
name|Q_ASSERT
argument_list|(
name|m_hints
operator|&
name|ShouldUseCacheHint
argument_list|)
expr_stmt|;
name|CacheEntry
modifier|*
name|e
init|=
name|m_cache
decl_stmt|;
while|while
condition|(
name|e
condition|)
block|{
if|if
condition|(
name|e
operator|->
name|engine
operator|==
name|engine
condition|)
return|return
name|e
return|;
name|e
operator|=
name|e
operator|->
name|next
expr_stmt|;
block|}
return|return
literal|0
return|;
block|}
name|template
operator|<
name|typename
name|T
operator|>
specifier|static
specifier|inline
name|bool
name|isRect
argument_list|(
argument|const T *pts
argument_list|,
argument|int elementCount
argument_list|)
block|{
return|return
operator|(
name|elementCount
operator|==
literal|5
comment|// 5-point polygon, check for closed rect
operator|&&
name|pts
index|[
literal|0
index|]
operator|==
name|pts
index|[
literal|8
index|]
operator|&&
name|pts
index|[
literal|1
index|]
operator|==
name|pts
index|[
literal|9
index|]
comment|// last point == first point
operator|&&
name|pts
index|[
literal|0
index|]
operator|==
name|pts
index|[
literal|6
index|]
operator|&&
name|pts
index|[
literal|2
index|]
operator|==
name|pts
index|[
literal|4
index|]
comment|// x values equal
operator|&&
name|pts
index|[
literal|1
index|]
operator|==
name|pts
index|[
literal|3
index|]
operator|&&
name|pts
index|[
literal|5
index|]
operator|==
name|pts
index|[
literal|7
index|]
comment|// y values equal...
operator|&&
name|pts
index|[
literal|0
index|]
operator|<
name|pts
index|[
literal|4
index|]
operator|&&
name|pts
index|[
literal|1
index|]
operator|<
name|pts
index|[
literal|5
index|]
operator|)
operator|||
operator|(
name|elementCount
operator|==
literal|4
comment|// 4-point polygon, check for unclosed rect
operator|&&
name|pts
index|[
literal|0
index|]
operator|==
name|pts
index|[
literal|6
index|]
operator|&&
name|pts
index|[
literal|2
index|]
operator|==
name|pts
index|[
literal|4
index|]
comment|// x values equal
operator|&&
name|pts
index|[
literal|1
index|]
operator|==
name|pts
index|[
literal|3
index|]
operator|&&
name|pts
index|[
literal|5
index|]
operator|==
name|pts
index|[
literal|7
index|]
comment|// y values equal...
operator|&&
name|pts
index|[
literal|0
index|]
operator|<
name|pts
index|[
literal|4
index|]
operator|&&
name|pts
index|[
literal|1
index|]
operator|<
name|pts
index|[
literal|5
index|]
operator|)
return|;
block|}
specifier|inline
name|bool
name|isRect
argument_list|()
specifier|const
block|{
specifier|const
name|QPainterPath
operator|::
name|ElementType
operator|*
specifier|const
name|types
operator|=
name|elements
argument_list|()
block|;
return|return
operator|(
name|shape
argument_list|()
operator|==
name|QVectorPath
operator|::
name|RectangleHint
operator|)
operator|||
operator|(
name|isRect
argument_list|(
name|points
argument_list|()
argument_list|,
name|elementCount
argument_list|()
argument_list|)
operator|&&
operator|(
operator|!
name|types
operator|||
operator|(
name|types
index|[
literal|0
index|]
operator|==
name|QPainterPath
operator|::
name|MoveToElement
operator|&&
name|types
index|[
literal|1
index|]
operator|==
name|QPainterPath
operator|::
name|LineToElement
operator|&&
name|types
index|[
literal|2
index|]
operator|==
name|QPainterPath
operator|::
name|LineToElement
operator|&&
name|types
index|[
literal|3
index|]
operator|==
name|QPainterPath
operator|::
name|LineToElement
operator|)
operator|)
operator|)
return|;
block|}
name|private
label|:
name|Q_DISABLE_COPY
argument_list|(
argument|QVectorPath
argument_list|)
specifier|const
name|QPainterPath
operator|::
name|ElementType
operator|*
name|m_elements
expr_stmt|;
specifier|const
name|qreal
modifier|*
name|m_points
decl_stmt|;
specifier|const
name|int
name|m_count
decl_stmt|;
name|mutable
name|uint
name|m_hints
decl_stmt|;
name|mutable
name|QRealRect
name|m_cp_rect
decl_stmt|;
name|mutable
name|CacheEntry
modifier|*
name|m_cache
decl_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_function_decl
name|Q_GUI_EXPORT
specifier|const
name|QVectorPath
modifier|&
name|qtVectorPathForPath
parameter_list|(
specifier|const
name|QPainterPath
modifier|&
name|path
parameter_list|)
function_decl|;
end_function_decl
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
end_unit
