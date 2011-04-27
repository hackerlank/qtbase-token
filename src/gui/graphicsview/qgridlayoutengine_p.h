begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** No Commercial Usage ** This file contains pre-release code and may not be distributed. ** You may use this file in accordance with the terms and conditions ** contained in the Technology Preview License Agreement accompanying ** this package. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights.  These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** If you have questions regarding the use of this file, please contact ** Nokia at qt-info@nokia.com. ** ** ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QGRIDLAYOUTENGINE_P_H
end_ifndef
begin_define
DECL|macro|QGRIDLAYOUTENGINE_P_H
define|#
directive|define
name|QGRIDLAYOUTENGINE_P_H
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
comment|// of the graphics view layout classes.  This header
end_comment
begin_comment
comment|// file may change from version to version without notice, or even be removed.
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
file|"qalgorithms.h"
end_include
begin_include
include|#
directive|include
file|"qbitarray.h"
end_include
begin_include
include|#
directive|include
file|"qlist.h"
end_include
begin_include
include|#
directive|include
file|"qmap.h"
end_include
begin_include
include|#
directive|include
file|"qpair.h"
end_include
begin_include
include|#
directive|include
file|"qvector.h"
end_include
begin_include
include|#
directive|include
file|"qgraphicslayout_p.h"
end_include
begin_include
include|#
directive|include
file|<float.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QGraphicsLayoutItem
name|class
name|QGraphicsLayoutItem
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QStyle
name|class
name|QStyle
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QWidget
name|class
name|QWidget
decl_stmt|;
end_decl_stmt
begin_comment
comment|// ### deal with Descent in a similar way
end_comment
begin_enum
enum|enum
block|{
DECL|enumerator|MinimumSize
name|MinimumSize
init|=
name|Qt
operator|::
name|MinimumSize
block|,
DECL|enumerator|PreferredSize
name|PreferredSize
init|=
name|Qt
operator|::
name|PreferredSize
block|,
DECL|enumerator|MaximumSize
name|MaximumSize
init|=
name|Qt
operator|::
name|MaximumSize
block|,
DECL|enumerator|NSizes
name|NSizes
block|}
enum|;
end_enum
begin_comment
comment|// do not reorder
end_comment
begin_enum
enum|enum
block|{
DECL|enumerator|Hor
name|Hor
block|,
DECL|enumerator|Ver
name|Ver
block|,
DECL|enumerator|NOrientations
name|NOrientations
block|}
enum|;
end_enum
begin_comment
comment|// do not reorder
end_comment
begin_enum
DECL|enum|LayoutSide
enum|enum
name|LayoutSide
block|{
DECL|enumerator|Left
name|Left
block|,
DECL|enumerator|Top
name|Top
block|,
DECL|enumerator|Right
name|Right
block|,
DECL|enumerator|Bottom
name|Bottom
block|}
enum|;
end_enum
begin_enum
enum|enum
block|{
DECL|enumerator|NoConstraint
name|NoConstraint
block|,
DECL|enumerator|HorizontalConstraint
name|HorizontalConstraint
block|,
comment|// Width depends on the height
DECL|enumerator|VerticalConstraint
name|VerticalConstraint
block|,
comment|// Height depends on the width
DECL|enumerator|UnknownConstraint
name|UnknownConstraint
block|,
comment|// need to update cache
DECL|enumerator|UnfeasibleConstraint
name|UnfeasibleConstraint
comment|// not feasible, it be has some items with Vertical and others with Horizontal constraints
block|}
enum|;
end_enum
begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
name|class
name|QLayoutParameter
block|{
name|public
operator|:
expr|enum
name|State
block|{
name|Default
block|,
name|User
block|,
name|Cached
block|}
block|;
specifier|inline
name|QLayoutParameter
argument_list|()
operator|:
name|q_value
argument_list|(
name|T
argument_list|()
argument_list|)
block|,
name|q_state
argument_list|(
argument|Default
argument_list|)
block|{}
specifier|inline
name|QLayoutParameter
argument_list|(
argument|T value
argument_list|,
argument|State state = Default
argument_list|)
operator|:
name|q_value
argument_list|(
name|value
argument_list|)
block|,
name|q_state
argument_list|(
argument|state
argument_list|)
block|{}
specifier|inline
name|void
name|setUserValue
argument_list|(
argument|T value
argument_list|)
block|{
name|q_value
operator|=
name|value
block|;
name|q_state
operator|=
name|User
block|;     }
specifier|inline
name|void
name|setCachedValue
argument_list|(
argument|T value
argument_list|)
specifier|const
block|{
if|if
condition|(
name|q_state
operator|!=
name|User
condition|)
block|{
name|q_value
operator|=
name|value
expr_stmt|;
name|q_state
operator|=
name|Cached
expr_stmt|;
block|}
block|}
specifier|inline
name|T
name|value
argument_list|()
specifier|const
block|{
return|return
name|q_value
return|;
block|}
end_expr_stmt
begin_decl_stmt
specifier|inline
name|T
name|value
argument_list|(
name|T
name|defaultValue
argument_list|)
decl|const
block|{
return|return
name|isUser
argument_list|()
condition|?
name|q_value
else|:
name|defaultValue
return|;
block|}
end_decl_stmt
begin_expr_stmt
specifier|inline
name|bool
name|isDefault
argument_list|()
specifier|const
block|{
return|return
name|q_state
operator|==
name|Default
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
name|bool
name|isUser
argument_list|()
specifier|const
block|{
return|return
name|q_state
operator|==
name|User
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
name|bool
name|isCached
argument_list|()
specifier|const
block|{
return|return
name|q_state
operator|==
name|Cached
return|;
block|}
end_expr_stmt
begin_label
name|private
label|:
end_label
begin_decl_stmt
name|mutable
name|T
name|q_value
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|mutable
name|State
name|q_state
decl_stmt|;
end_decl_stmt
begin_decl_stmt
unit|};
name|class
name|QStretchParameter
range|:
name|public
name|QLayoutParameter
operator|<
name|int
operator|>
block|{
name|public
operator|:
name|QStretchParameter
argument_list|()
operator|:
name|QLayoutParameter
operator|<
name|int
operator|>
operator|(
operator|-
literal|1
operator|)
block|{}
block|}
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QGridLayoutBox
block|{
name|public
label|:
specifier|inline
name|QGridLayoutBox
argument_list|()
operator|:
name|q_minimumSize
argument_list|(
literal|0
argument_list|)
operator|,
name|q_preferredSize
argument_list|(
literal|0
argument_list|)
operator|,
name|q_maximumSize
argument_list|(
name|FLT_MAX
argument_list|)
operator|,
name|q_minimumDescent
argument_list|(
operator|-
literal|1
argument_list|)
operator|,
name|q_minimumAscent
argument_list|(
argument|-
literal|1
argument_list|)
block|{}
name|void
name|add
argument_list|(
argument|const QGridLayoutBox&other
argument_list|,
argument|int stretch
argument_list|,
argument|qreal spacing
argument_list|)
expr_stmt|;
name|void
name|combine
parameter_list|(
specifier|const
name|QGridLayoutBox
modifier|&
name|other
parameter_list|)
function_decl|;
name|void
name|normalize
parameter_list|()
function_decl|;
ifdef|#
directive|ifdef
name|QT_DEBUG
name|void
name|dump
argument_list|(
name|int
name|indent
operator|=
literal|0
argument_list|)
decl|const
decl_stmt|;
endif|#
directive|endif
comment|// This code could use the union-struct-array trick, but a compiler
comment|// bug prevents this from working.
name|qreal
name|q_minimumSize
decl_stmt|;
name|qreal
name|q_preferredSize
decl_stmt|;
name|qreal
name|q_maximumSize
decl_stmt|;
name|qreal
name|q_minimumDescent
decl_stmt|;
name|qreal
name|q_minimumAscent
decl_stmt|;
specifier|inline
name|qreal
modifier|&
name|q_sizes
parameter_list|(
name|int
name|which
parameter_list|)
block|{
name|qreal
modifier|*
name|t
decl_stmt|;
switch|switch
condition|(
name|which
condition|)
block|{
case|case
name|Qt
operator|::
name|MinimumSize
case|:
name|t
operator|=
operator|&
name|q_minimumSize
expr_stmt|;
break|break;
case|case
name|Qt
operator|::
name|PreferredSize
case|:
name|t
operator|=
operator|&
name|q_preferredSize
expr_stmt|;
break|break;
case|case
name|Qt
operator|::
name|MaximumSize
case|:
name|t
operator|=
operator|&
name|q_maximumSize
expr_stmt|;
break|break;
case|case
name|Qt
operator|::
name|MinimumDescent
case|:
name|t
operator|=
operator|&
name|q_minimumDescent
expr_stmt|;
break|break;
case|case
operator|(
name|Qt
operator|::
name|MinimumDescent
operator|+
literal|1
operator|)
case|:
name|t
operator|=
operator|&
name|q_minimumAscent
expr_stmt|;
break|break;
default|default:
name|t
operator|=
literal|0
expr_stmt|;
break|break;
block|}
return|return
operator|*
name|t
return|;
block|}
specifier|inline
specifier|const
name|qreal
modifier|&
name|q_sizes
argument_list|(
name|int
name|which
argument_list|)
decl|const
block|{
specifier|const
name|qreal
modifier|*
name|t
decl_stmt|;
switch|switch
condition|(
name|which
condition|)
block|{
case|case
name|Qt
operator|::
name|MinimumSize
case|:
name|t
operator|=
operator|&
name|q_minimumSize
expr_stmt|;
break|break;
case|case
name|Qt
operator|::
name|PreferredSize
case|:
name|t
operator|=
operator|&
name|q_preferredSize
expr_stmt|;
break|break;
case|case
name|Qt
operator|::
name|MaximumSize
case|:
name|t
operator|=
operator|&
name|q_maximumSize
expr_stmt|;
break|break;
case|case
name|Qt
operator|::
name|MinimumDescent
case|:
name|t
operator|=
operator|&
name|q_minimumDescent
expr_stmt|;
break|break;
case|case
operator|(
name|Qt
operator|::
name|MinimumDescent
operator|+
literal|1
operator|)
case|:
name|t
operator|=
operator|&
name|q_minimumAscent
expr_stmt|;
break|break;
default|default:
name|t
operator|=
literal|0
expr_stmt|;
break|break;
block|}
return|return
operator|*
name|t
return|;
block|}
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_expr_stmt
name|bool
name|operator
operator|==
operator|(
specifier|const
name|QGridLayoutBox
operator|&
name|box1
operator|,
specifier|const
name|QGridLayoutBox
operator|&
name|box2
operator|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
DECL|function|operator
specifier|inline
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|QGridLayoutBox
operator|&
name|box1
operator|,
specifier|const
name|QGridLayoutBox
operator|&
name|box2
operator|)
block|{
return|return
operator|!
name|operator
operator|==
operator|(
name|box1
operator|,
name|box2
operator|)
return|;
block|}
end_expr_stmt
begin_decl_stmt
name|class
name|QGridLayoutMultiCellData
block|{
name|public
label|:
specifier|inline
name|QGridLayoutMultiCellData
argument_list|()
operator|:
name|q_stretch
argument_list|(
argument|-
literal|1
argument_list|)
block|{}
name|QGridLayoutBox
name|q_box
expr_stmt|;
name|int
name|q_stretch
decl_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_typedef
DECL|typedef|MultiCellMap
typedef|typedef
name|QMap
operator|<
name|QPair
operator|<
name|int
operator|,
name|int
operator|>
operator|,
name|QGridLayoutMultiCellData
operator|>
name|MultiCellMap
expr_stmt|;
end_typedef
begin_decl_stmt
DECL|variable|QGridLayoutRowInfo
name|class
name|QGridLayoutRowInfo
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QGridLayoutRowData
block|{
name|public
label|:
name|void
name|reset
parameter_list|(
name|int
name|count
parameter_list|)
function_decl|;
name|void
name|distributeMultiCells
parameter_list|(
specifier|const
name|QGridLayoutRowInfo
modifier|&
name|rowInfo
parameter_list|)
function_decl|;
name|void
name|calculateGeometries
parameter_list|(
name|int
name|start
parameter_list|,
name|int
name|end
parameter_list|,
name|qreal
name|targetSize
parameter_list|,
name|qreal
modifier|*
name|positions
parameter_list|,
name|qreal
modifier|*
name|sizes
parameter_list|,
name|qreal
modifier|*
name|descents
parameter_list|,
specifier|const
name|QGridLayoutBox
modifier|&
name|totalBox
parameter_list|,
specifier|const
name|QGridLayoutRowInfo
modifier|&
name|rowInfo
parameter_list|)
function_decl|;
name|QGridLayoutBox
name|totalBox
argument_list|(
name|int
name|start
argument_list|,
name|int
name|end
argument_list|)
decl|const
decl_stmt|;
name|void
name|stealBox
parameter_list|(
name|int
name|start
parameter_list|,
name|int
name|end
parameter_list|,
name|int
name|which
parameter_list|,
name|qreal
modifier|*
name|positions
parameter_list|,
name|qreal
modifier|*
name|sizes
parameter_list|)
function_decl|;
ifdef|#
directive|ifdef
name|QT_DEBUG
name|void
name|dump
argument_list|(
name|int
name|indent
operator|=
literal|0
argument_list|)
decl|const
decl_stmt|;
endif|#
directive|endif
name|QBitArray
name|ignore
decl_stmt|;
comment|// ### rename q_
name|QVector
operator|<
name|QGridLayoutBox
operator|>
name|boxes
expr_stmt|;
name|MultiCellMap
name|multiCellMap
decl_stmt|;
name|QVector
operator|<
name|int
operator|>
name|stretches
expr_stmt|;
name|QVector
operator|<
name|qreal
operator|>
name|spacings
expr_stmt|;
name|bool
name|hasIgnoreFlag
decl_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_decl_stmt
DECL|variable|QGridLayoutEngine
name|class
name|QGridLayoutEngine
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QGridLayoutItem
block|{
name|public
label|:
name|QGridLayoutItem
argument_list|(
argument|QGridLayoutEngine *engine
argument_list|,
argument|QGraphicsLayoutItem *layoutItem
argument_list|,
argument|int row
argument_list|,
argument|int column
argument_list|,
argument|int rowSpan =
literal|1
argument_list|,
argument|int columnSpan =
literal|1
argument_list|,
argument|Qt::Alignment alignment =
literal|0
argument_list|,
argument|int itemAtIndex = -
literal|1
argument_list|)
empty_stmt|;
specifier|inline
name|int
name|firstRow
argument_list|()
specifier|const
block|{
return|return
name|q_firstRows
index|[
name|Ver
index|]
return|;
block|}
specifier|inline
name|int
name|firstColumn
argument_list|()
specifier|const
block|{
return|return
name|q_firstRows
index|[
name|Hor
index|]
return|;
block|}
specifier|inline
name|int
name|rowSpan
argument_list|()
specifier|const
block|{
return|return
name|q_rowSpans
index|[
name|Ver
index|]
return|;
block|}
specifier|inline
name|int
name|columnSpan
argument_list|()
specifier|const
block|{
return|return
name|q_rowSpans
index|[
name|Hor
index|]
return|;
block|}
specifier|inline
name|int
name|lastRow
argument_list|()
specifier|const
block|{
return|return
name|firstRow
argument_list|()
operator|+
name|rowSpan
argument_list|()
operator|-
literal|1
return|;
block|}
specifier|inline
name|int
name|lastColumn
argument_list|()
specifier|const
block|{
return|return
name|firstColumn
argument_list|()
operator|+
name|columnSpan
argument_list|()
operator|-
literal|1
return|;
block|}
name|int
name|firstRow
argument_list|(
name|Qt
operator|::
name|Orientation
name|orientation
argument_list|)
decl|const
decl_stmt|;
name|int
name|firstColumn
argument_list|(
name|Qt
operator|::
name|Orientation
name|orientation
argument_list|)
decl|const
decl_stmt|;
name|int
name|lastRow
argument_list|(
name|Qt
operator|::
name|Orientation
name|orientation
argument_list|)
decl|const
decl_stmt|;
name|int
name|lastColumn
argument_list|(
name|Qt
operator|::
name|Orientation
name|orientation
argument_list|)
decl|const
decl_stmt|;
name|int
name|rowSpan
argument_list|(
name|Qt
operator|::
name|Orientation
name|orientation
argument_list|)
decl|const
decl_stmt|;
name|int
name|columnSpan
argument_list|(
name|Qt
operator|::
name|Orientation
name|orientation
argument_list|)
decl|const
decl_stmt|;
name|void
name|setFirstRow
argument_list|(
name|int
name|row
argument_list|,
name|Qt
operator|::
name|Orientation
name|orientation
operator|=
name|Qt
operator|::
name|Vertical
argument_list|)
decl_stmt|;
name|void
name|setRowSpan
argument_list|(
name|int
name|rowSpan
argument_list|,
name|Qt
operator|::
name|Orientation
name|orientation
operator|=
name|Qt
operator|::
name|Vertical
argument_list|)
decl_stmt|;
name|int
name|stretchFactor
argument_list|(
name|Qt
operator|::
name|Orientation
name|orientation
argument_list|)
decl|const
decl_stmt|;
name|void
name|setStretchFactor
argument_list|(
name|int
name|stretch
argument_list|,
name|Qt
operator|::
name|Orientation
name|orientation
argument_list|)
decl_stmt|;
specifier|inline
name|Qt
operator|::
name|Alignment
name|alignment
argument_list|()
specifier|const
block|{
return|return
name|q_alignment
return|;
block|}
specifier|inline
name|void
name|setAlignment
argument_list|(
name|Qt
operator|::
name|Alignment
name|alignment
argument_list|)
block|{
name|q_alignment
operator|=
name|alignment
expr_stmt|;
block|}
name|QSizePolicy
operator|::
name|Policy
name|sizePolicy
argument_list|(
argument|Qt::Orientation orientation
argument_list|)
specifier|const
expr_stmt|;
name|bool
name|hasDynamicConstraint
argument_list|()
specifier|const
expr_stmt|;
name|Qt
operator|::
name|Orientation
name|dynamicConstraintOrientation
argument_list|()
specifier|const
expr_stmt|;
name|QSizePolicy
operator|::
name|ControlTypes
name|controlTypes
argument_list|(
argument|LayoutSide side
argument_list|)
specifier|const
expr_stmt|;
name|QSizeF
name|sizeHint
argument_list|(
name|Qt
operator|::
name|SizeHint
name|which
argument_list|,
specifier|const
name|QSizeF
operator|&
name|constraint
operator|=
name|QSizeF
argument_list|()
argument_list|)
decl|const
decl_stmt|;
name|QGridLayoutBox
name|box
argument_list|(
name|Qt
operator|::
name|Orientation
name|orientation
argument_list|,
name|qreal
name|constraint
operator|=
operator|-
literal|1.0
argument_list|)
decl|const
decl_stmt|;
name|QRectF
name|geometryWithin
argument_list|(
name|qreal
name|x
argument_list|,
name|qreal
name|y
argument_list|,
name|qreal
name|width
argument_list|,
name|qreal
name|height
argument_list|,
name|qreal
name|rowDescent
argument_list|)
decl|const
decl_stmt|;
name|QGraphicsLayoutItem
operator|*
name|layoutItem
argument_list|()
specifier|const
block|{
return|return
name|q_layoutItem
return|;
block|}
name|void
name|setGeometry
parameter_list|(
specifier|const
name|QRectF
modifier|&
name|rect
parameter_list|)
function_decl|;
name|void
name|transpose
parameter_list|()
function_decl|;
name|void
name|insertOrRemoveRows
argument_list|(
name|int
name|row
argument_list|,
name|int
name|delta
argument_list|,
name|Qt
operator|::
name|Orientation
name|orientation
operator|=
name|Qt
operator|::
name|Vertical
argument_list|)
decl_stmt|;
name|QSizeF
name|effectiveMaxSize
argument_list|(
specifier|const
name|QSizeF
operator|&
name|constraint
argument_list|)
decl|const
decl_stmt|;
ifdef|#
directive|ifdef
name|QT_DEBUG
name|void
name|dump
argument_list|(
name|int
name|indent
operator|=
literal|0
argument_list|)
decl|const
decl_stmt|;
endif|#
directive|endif
name|private
label|:
name|QGridLayoutEngine
modifier|*
name|q_engine
decl_stmt|;
comment|// ### needed?
name|QGraphicsLayoutItem
modifier|*
name|q_layoutItem
decl_stmt|;
name|int
name|q_firstRows
index|[
name|NOrientations
index|]
decl_stmt|;
name|int
name|q_rowSpans
index|[
name|NOrientations
index|]
decl_stmt|;
name|int
name|q_stretches
index|[
name|NOrientations
index|]
decl_stmt|;
name|Qt
operator|::
name|Alignment
name|q_alignment
expr_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_decl_stmt
name|class
name|QGridLayoutRowInfo
block|{
name|public
label|:
specifier|inline
name|QGridLayoutRowInfo
argument_list|()
operator|:
name|count
argument_list|(
literal|0
argument_list|)
block|{}
name|void
name|insertOrRemoveRows
argument_list|(
argument|int row
argument_list|,
argument|int delta
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|QT_DEBUG
name|void
name|dump
argument_list|(
name|int
name|indent
operator|=
literal|0
argument_list|)
decl|const
decl_stmt|;
endif|#
directive|endif
name|int
name|count
decl_stmt|;
name|QVector
operator|<
name|QStretchParameter
operator|>
name|stretches
expr_stmt|;
name|QVector
operator|<
name|QLayoutParameter
operator|<
name|qreal
operator|>
expr|>
name|spacings
expr_stmt|;
name|QVector
operator|<
name|Qt
operator|::
name|Alignment
operator|>
name|alignments
expr_stmt|;
name|QVector
operator|<
name|QGridLayoutBox
operator|>
name|boxes
expr_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_decl_stmt
name|class
name|QGridLayoutEngine
block|{
name|public
label|:
name|QGridLayoutEngine
argument_list|()
expr_stmt|;
specifier|inline
operator|~
name|QGridLayoutEngine
argument_list|()
block|{
name|qDeleteAll
argument_list|(
name|q_items
argument_list|)
block|; }
name|int
name|rowCount
argument_list|(
argument|Qt::Orientation orientation
argument_list|)
specifier|const
expr_stmt|;
name|int
name|columnCount
argument_list|(
name|Qt
operator|::
name|Orientation
name|orientation
argument_list|)
decl|const
decl_stmt|;
specifier|inline
name|int
name|rowCount
argument_list|()
specifier|const
block|{
return|return
name|q_infos
index|[
name|Ver
index|]
operator|.
name|count
return|;
block|}
specifier|inline
name|int
name|columnCount
argument_list|()
specifier|const
block|{
return|return
name|q_infos
index|[
name|Hor
index|]
operator|.
name|count
return|;
block|}
comment|// returns the number of items inserted, which may be less than (rowCount * columnCount)
name|int
name|itemCount
argument_list|()
specifier|const
expr_stmt|;
name|QGridLayoutItem
modifier|*
name|itemAt
argument_list|(
name|int
name|index
argument_list|)
decl|const
decl_stmt|;
name|int
name|indexOf
argument_list|(
name|QGraphicsLayoutItem
operator|*
name|item
argument_list|)
decl|const
decl_stmt|;
name|int
name|effectiveFirstRow
argument_list|(
name|Qt
operator|::
name|Orientation
name|orientation
operator|=
name|Qt
operator|::
name|Vertical
argument_list|)
decl|const
decl_stmt|;
name|int
name|effectiveLastRow
argument_list|(
name|Qt
operator|::
name|Orientation
name|orientation
operator|=
name|Qt
operator|::
name|Vertical
argument_list|)
decl|const
decl_stmt|;
name|void
name|setSpacing
argument_list|(
name|qreal
name|spacing
argument_list|,
name|Qt
operator|::
name|Orientations
name|orientations
argument_list|)
decl_stmt|;
name|qreal
name|spacing
argument_list|(
specifier|const
name|QLayoutStyleInfo
operator|&
name|styleInfo
argument_list|,
name|Qt
operator|::
name|Orientation
name|orientation
argument_list|)
decl|const
decl_stmt|;
comment|// ### setSpacingAfterRow(), spacingAfterRow()
name|void
name|setRowSpacing
argument_list|(
name|int
name|row
argument_list|,
name|qreal
name|spacing
argument_list|,
name|Qt
operator|::
name|Orientation
name|orientation
operator|=
name|Qt
operator|::
name|Vertical
argument_list|)
decl_stmt|;
name|qreal
name|rowSpacing
argument_list|(
name|int
name|row
argument_list|,
name|Qt
operator|::
name|Orientation
name|orientation
operator|=
name|Qt
operator|::
name|Vertical
argument_list|)
decl|const
decl_stmt|;
name|void
name|setRowStretchFactor
argument_list|(
name|int
name|row
argument_list|,
name|int
name|stretch
argument_list|,
name|Qt
operator|::
name|Orientation
name|orientation
operator|=
name|Qt
operator|::
name|Vertical
argument_list|)
decl_stmt|;
name|int
name|rowStretchFactor
argument_list|(
name|int
name|row
argument_list|,
name|Qt
operator|::
name|Orientation
name|orientation
operator|=
name|Qt
operator|::
name|Vertical
argument_list|)
decl|const
decl_stmt|;
name|void
name|setStretchFactor
argument_list|(
name|QGraphicsLayoutItem
operator|*
name|layoutItem
argument_list|,
name|int
name|stretch
argument_list|,
name|Qt
operator|::
name|Orientation
name|orientation
argument_list|)
decl_stmt|;
name|int
name|stretchFactor
argument_list|(
name|QGraphicsLayoutItem
operator|*
name|layoutItem
argument_list|,
name|Qt
operator|::
name|Orientation
name|orientation
argument_list|)
decl|const
decl_stmt|;
name|void
name|setRowSizeHint
argument_list|(
name|Qt
operator|::
name|SizeHint
name|which
argument_list|,
name|int
name|row
argument_list|,
name|qreal
name|size
argument_list|,
name|Qt
operator|::
name|Orientation
name|orientation
operator|=
name|Qt
operator|::
name|Vertical
argument_list|)
decl_stmt|;
name|qreal
name|rowSizeHint
argument_list|(
name|Qt
operator|::
name|SizeHint
name|which
argument_list|,
name|int
name|row
argument_list|,
name|Qt
operator|::
name|Orientation
name|orientation
operator|=
name|Qt
operator|::
name|Vertical
argument_list|)
decl|const
decl_stmt|;
name|void
name|setRowAlignment
argument_list|(
name|int
name|row
argument_list|,
name|Qt
operator|::
name|Alignment
name|alignment
argument_list|,
name|Qt
operator|::
name|Orientation
name|orientation
argument_list|)
decl_stmt|;
name|Qt
operator|::
name|Alignment
name|rowAlignment
argument_list|(
argument|int row
argument_list|,
argument|Qt::Orientation orientation
argument_list|)
specifier|const
expr_stmt|;
name|void
name|setAlignment
argument_list|(
name|QGraphicsLayoutItem
operator|*
name|layoutItem
argument_list|,
name|Qt
operator|::
name|Alignment
name|alignment
argument_list|)
decl_stmt|;
name|Qt
operator|::
name|Alignment
name|alignment
argument_list|(
argument|QGraphicsLayoutItem *layoutItem
argument_list|)
specifier|const
expr_stmt|;
name|Qt
operator|::
name|Alignment
name|effectiveAlignment
argument_list|(
argument|const QGridLayoutItem *layoutItem
argument_list|)
specifier|const
expr_stmt|;
name|void
name|insertItem
parameter_list|(
name|QGridLayoutItem
modifier|*
name|item
parameter_list|,
name|int
name|index
parameter_list|)
function_decl|;
name|void
name|addItem
parameter_list|(
name|QGridLayoutItem
modifier|*
name|item
parameter_list|)
function_decl|;
name|void
name|removeItem
parameter_list|(
name|QGridLayoutItem
modifier|*
name|item
parameter_list|)
function_decl|;
name|QGridLayoutItem
modifier|*
name|findLayoutItem
argument_list|(
name|QGraphicsLayoutItem
operator|*
name|layoutItem
argument_list|)
decl|const
decl_stmt|;
name|QGridLayoutItem
modifier|*
name|itemAt
argument_list|(
name|int
name|row
argument_list|,
name|int
name|column
argument_list|,
name|Qt
operator|::
name|Orientation
name|orientation
operator|=
name|Qt
operator|::
name|Vertical
argument_list|)
decl|const
decl_stmt|;
specifier|inline
name|void
name|insertRow
argument_list|(
name|int
name|row
argument_list|,
name|Qt
operator|::
name|Orientation
name|orientation
operator|=
name|Qt
operator|::
name|Vertical
argument_list|)
block|{
name|insertOrRemoveRows
argument_list|(
name|row
argument_list|,
operator|+
literal|1
argument_list|,
name|orientation
argument_list|)
expr_stmt|;
block|}
specifier|inline
name|void
name|removeRows
argument_list|(
name|int
name|row
argument_list|,
name|int
name|count
argument_list|,
name|Qt
operator|::
name|Orientation
name|orientation
argument_list|)
block|{
name|insertOrRemoveRows
argument_list|(
name|row
argument_list|,
operator|-
name|count
argument_list|,
name|orientation
argument_list|)
expr_stmt|;
block|}
name|void
name|invalidate
parameter_list|()
function_decl|;
name|void
name|setGeometries
parameter_list|(
specifier|const
name|QLayoutStyleInfo
modifier|&
name|styleInfo
parameter_list|,
specifier|const
name|QRectF
modifier|&
name|contentsGeometry
parameter_list|)
function_decl|;
name|QRectF
name|cellRect
argument_list|(
specifier|const
name|QLayoutStyleInfo
operator|&
name|styleInfo
argument_list|,
specifier|const
name|QRectF
operator|&
name|contentsGeometry
argument_list|,
name|int
name|row
argument_list|,
name|int
name|column
argument_list|,
name|int
name|rowSpan
argument_list|,
name|int
name|columnSpan
argument_list|)
decl|const
decl_stmt|;
name|QSizeF
name|sizeHint
argument_list|(
specifier|const
name|QLayoutStyleInfo
operator|&
name|styleInfo
argument_list|,
name|Qt
operator|::
name|SizeHint
name|which
argument_list|,
specifier|const
name|QSizeF
operator|&
name|constraint
argument_list|)
decl|const
decl_stmt|;
comment|// heightForWidth / widthForHeight support
name|QSizeF
name|dynamicallyConstrainedSizeHint
argument_list|(
name|Qt
operator|::
name|SizeHint
name|which
argument_list|,
specifier|const
name|QSizeF
operator|&
name|constraint
argument_list|)
decl|const
decl_stmt|;
name|bool
name|ensureDynamicConstraint
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|hasDynamicConstraint
argument_list|()
specifier|const
expr_stmt|;
name|Qt
operator|::
name|Orientation
name|constraintOrientation
argument_list|()
specifier|const
expr_stmt|;
name|QSizePolicy
operator|::
name|ControlTypes
name|controlTypes
argument_list|(
argument|LayoutSide side
argument_list|)
specifier|const
expr_stmt|;
name|void
name|transpose
parameter_list|()
function_decl|;
name|void
name|setVisualDirection
argument_list|(
name|Qt
operator|::
name|LayoutDirection
name|direction
argument_list|)
decl_stmt|;
name|Qt
operator|::
name|LayoutDirection
name|visualDirection
argument_list|()
specifier|const
expr_stmt|;
ifdef|#
directive|ifdef
name|QT_DEBUG
name|void
name|dump
argument_list|(
name|int
name|indent
operator|=
literal|0
argument_list|)
decl|const
decl_stmt|;
endif|#
directive|endif
name|private
label|:
specifier|static
name|int
name|grossRoundUp
parameter_list|(
name|int
name|n
parameter_list|)
block|{
return|return
operator|(
operator|(
name|n
operator|+
literal|2
operator|)
operator||
literal|0x3
operator|)
operator|-
literal|2
return|;
block|}
name|void
name|maybeExpandGrid
argument_list|(
name|int
name|row
argument_list|,
name|int
name|column
argument_list|,
name|Qt
operator|::
name|Orientation
name|orientation
operator|=
name|Qt
operator|::
name|Vertical
argument_list|)
decl_stmt|;
name|void
name|regenerateGrid
parameter_list|()
function_decl|;
specifier|inline
name|int
name|internalGridRowCount
argument_list|()
specifier|const
block|{
return|return
name|grossRoundUp
argument_list|(
name|rowCount
argument_list|()
argument_list|)
return|;
block|}
specifier|inline
name|int
name|internalGridColumnCount
argument_list|()
specifier|const
block|{
return|return
name|grossRoundUp
argument_list|(
name|columnCount
argument_list|()
argument_list|)
return|;
block|}
name|void
name|setItemAt
parameter_list|(
name|int
name|row
parameter_list|,
name|int
name|column
parameter_list|,
name|QGridLayoutItem
modifier|*
name|item
parameter_list|)
function_decl|;
name|void
name|insertOrRemoveRows
argument_list|(
name|int
name|row
argument_list|,
name|int
name|delta
argument_list|,
name|Qt
operator|::
name|Orientation
name|orientation
operator|=
name|Qt
operator|::
name|Vertical
argument_list|)
decl_stmt|;
name|void
name|fillRowData
argument_list|(
name|QGridLayoutRowData
operator|*
name|rowData
argument_list|,
specifier|const
name|QLayoutStyleInfo
operator|&
name|styleInfo
argument_list|,
name|qreal
operator|*
name|colPositions
argument_list|,
name|qreal
operator|*
name|colSizes
argument_list|,
name|Qt
operator|::
name|Orientation
name|orientation
operator|=
name|Qt
operator|::
name|Vertical
argument_list|)
decl|const
decl_stmt|;
name|void
name|ensureEffectiveFirstAndLastRows
argument_list|()
specifier|const
expr_stmt|;
name|void
name|ensureColumnAndRowData
argument_list|(
name|QGridLayoutRowData
operator|*
name|rowData
argument_list|,
name|QGridLayoutBox
operator|*
name|totalBox
argument_list|,
specifier|const
name|QLayoutStyleInfo
operator|&
name|styleInfo
argument_list|,
name|qreal
operator|*
name|colPositions
argument_list|,
name|qreal
operator|*
name|colSizes
argument_list|,
name|Qt
operator|::
name|Orientation
name|orientation
argument_list|)
decl|const
decl_stmt|;
name|void
name|ensureGeometries
argument_list|(
specifier|const
name|QLayoutStyleInfo
operator|&
name|styleInfo
argument_list|,
specifier|const
name|QSizeF
operator|&
name|size
argument_list|)
decl|const
decl_stmt|;
comment|// User input
name|QVector
operator|<
name|QGridLayoutItem
operator|*
operator|>
name|q_grid
expr_stmt|;
name|QList
operator|<
name|QGridLayoutItem
operator|*
operator|>
name|q_items
expr_stmt|;
name|QLayoutParameter
operator|<
name|qreal
operator|>
name|q_defaultSpacings
index|[
name|NOrientations
index|]
expr_stmt|;
name|QGridLayoutRowInfo
name|q_infos
index|[
name|NOrientations
index|]
decl_stmt|;
name|Qt
operator|::
name|LayoutDirection
name|m_visualDirection
expr_stmt|;
comment|// Lazily computed from the above user input
name|mutable
name|int
name|q_cachedEffectiveFirstRows
index|[
name|NOrientations
index|]
decl_stmt|;
name|mutable
name|int
name|q_cachedEffectiveLastRows
index|[
name|NOrientations
index|]
decl_stmt|;
name|mutable
name|quint8
name|q_cachedConstraintOrientation
range|:
literal|3
decl_stmt|;
comment|// Layout item input
name|mutable
name|QLayoutStyleInfo
name|q_cachedDataForStyleInfo
decl_stmt|;
name|mutable
name|QGridLayoutRowData
name|q_columnData
decl_stmt|;
name|mutable
name|QGridLayoutRowData
name|q_rowData
decl_stmt|;
name|mutable
name|QGridLayoutBox
name|q_totalBoxes
index|[
name|NOrientations
index|]
decl_stmt|;
comment|// Output
name|mutable
name|QSizeF
name|q_cachedSize
decl_stmt|;
name|mutable
name|QVector
operator|<
name|qreal
operator|>
name|q_xx
expr_stmt|;
name|mutable
name|QVector
operator|<
name|qreal
operator|>
name|q_yy
expr_stmt|;
name|mutable
name|QVector
operator|<
name|qreal
operator|>
name|q_widths
expr_stmt|;
name|mutable
name|QVector
operator|<
name|qreal
operator|>
name|q_heights
expr_stmt|;
name|mutable
name|QVector
operator|<
name|qreal
operator|>
name|q_descents
expr_stmt|;
name|friend
name|class
name|QGridLayoutItem
decl_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
end_unit
