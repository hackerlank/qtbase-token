begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QPAINTERPATH_P_H
end_ifndef
begin_define
DECL|macro|QPAINTERPATH_P_H
define|#
directive|define
name|QPAINTERPATH_P_H
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
file|"QtGui/qpainterpath.h"
end_include
begin_include
include|#
directive|include
file|"QtGui/qregion.h"
end_include
begin_include
include|#
directive|include
file|"QtCore/qlist.h"
end_include
begin_include
include|#
directive|include
file|"QtCore/qvarlengtharray.h"
end_include
begin_include
include|#
directive|include
file|<qdebug.h>
end_include
begin_include
include|#
directive|include
file|<private/qvectorpath_p.h>
end_include
begin_include
include|#
directive|include
file|<private/qstroker_p.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
name|class
name|QPainterPathPrivate
block|{
name|public
label|:
name|friend
name|class
name|QPainterPath
decl_stmt|;
name|friend
name|class
name|QPainterPathData
decl_stmt|;
name|friend
name|class
name|QPainterPathStroker
decl_stmt|;
name|friend
name|class
name|QPainterPathStrokerPrivate
decl_stmt|;
name|friend
name|class
name|QMatrix
decl_stmt|;
name|friend
name|class
name|QTransform
decl_stmt|;
name|friend
name|class
name|QVectorPath
decl_stmt|;
name|friend
struct_decl|struct
name|QPainterPathPrivateDeleter
struct_decl|;
ifndef|#
directive|ifndef
name|QT_NO_DATASTREAM
name|friend
name|Q_GUI_EXPORT
name|QDataStream
operator|&
name|operator
operator|<<
operator|(
name|QDataStream
operator|&
operator|,
specifier|const
name|QPainterPath
operator|&
operator|)
expr_stmt|;
name|friend
name|Q_GUI_EXPORT
name|QDataStream
operator|&
name|operator
operator|>>
operator|(
name|QDataStream
operator|&
operator|,
name|QPainterPath
operator|&
operator|)
expr_stmt|;
endif|#
directive|endif
name|QPainterPathPrivate
argument_list|()
operator|:
name|ref
argument_list|(
literal|1
argument_list|)
block|{}
name|private
operator|:
name|QAtomicInt
name|ref
expr_stmt|;
name|QVector
operator|<
name|QPainterPath
operator|::
name|Element
operator|>
name|elements
expr_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_decl_stmt
name|class
name|QPainterPathStrokerPrivate
block|{
name|public
label|:
name|QPainterPathStrokerPrivate
argument_list|()
expr_stmt|;
name|QStroker
name|stroker
decl_stmt|;
name|QVector
operator|<
name|qfixed
operator|>
name|dashPattern
expr_stmt|;
name|qreal
name|dashOffset
decl_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_decl_stmt
DECL|variable|QPolygonF
name|class
name|QPolygonF
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QVectorPathConverter
name|class
name|QVectorPathConverter
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QVectorPathConverter
block|{
name|public
label|:
name|QVectorPathConverter
argument_list|(
argument|const QVector<QPainterPath::Element>&path
argument_list|,
argument|uint fillRule
argument_list|,
argument|bool convex
argument_list|)
block|:
name|pathData
argument_list|(
name|path
argument_list|,
name|fillRule
argument_list|,
name|convex
argument_list|)
operator|,
name|path
argument_list|(
argument|pathData.points.data()
argument_list|,
argument|path.size()
argument_list|,
argument|pathData.elements.data()
argument_list|,
argument|pathData.flags
argument_list|)
block|{}
specifier|const
name|QVectorPath
operator|&
name|vectorPath
argument_list|()
block|{
return|return
name|path
return|;
block|}
struct|struct
name|QVectorPathData
block|{
name|QVectorPathData
argument_list|(
argument|const QVector<QPainterPath::Element>&path
argument_list|,
argument|uint fillRule
argument_list|,
argument|bool convex
argument_list|)
block|:
name|elements
argument_list|(
name|path
operator|.
name|size
argument_list|()
argument_list|)
operator|,
name|points
argument_list|(
name|path
operator|.
name|size
argument_list|()
operator|*
literal|2
argument_list|)
operator|,
name|flags
argument_list|(
literal|0
argument_list|)
block|{
name|int
name|ptsPos
operator|=
literal|0
block|;
name|bool
name|isLines
operator|=
name|true
block|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|path
operator|.
name|size
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
specifier|const
name|QPainterPath
operator|::
name|Element
operator|&
name|e
operator|=
name|path
operator|.
name|at
argument_list|(
name|i
argument_list|)
expr_stmt|;
name|elements
index|[
name|i
index|]
operator|=
name|e
operator|.
name|type
expr_stmt|;
name|points
index|[
name|ptsPos
operator|++
index|]
operator|=
name|e
operator|.
name|x
expr_stmt|;
name|points
index|[
name|ptsPos
operator|++
index|]
operator|=
name|e
operator|.
name|y
expr_stmt|;
if|if
condition|(
name|e
operator|.
name|type
operator|==
name|QPainterPath
operator|::
name|CurveToElement
condition|)
name|flags
operator||=
name|QVectorPath
operator|::
name|CurvedShapeMask
expr_stmt|;
comment|// This is to check if the path contains only alternating lineTo/moveTo,
comment|// in which case we can set the LinesHint in the path. MoveTo is 0 and
comment|// LineTo is 1 so the i%2 gets us what we want cheaply.
name|isLines
operator|=
name|isLines
operator|&&
name|e
operator|.
name|type
operator|==
operator|(
name|QPainterPath
operator|::
name|ElementType
operator|)
operator|(
name|i
operator|%
literal|2
operator|)
expr_stmt|;
block|}
if|if
condition|(
name|fillRule
operator|==
name|Qt
operator|::
name|WindingFill
condition|)
name|flags
operator||=
name|QVectorPath
operator|::
name|WindingFill
expr_stmt|;
else|else
name|flags
operator||=
name|QVectorPath
operator|::
name|OddEvenFill
expr_stmt|;
if|if
condition|(
name|isLines
condition|)
name|flags
operator||=
name|QVectorPath
operator|::
name|LinesShapeMask
expr_stmt|;
else|else
block|{
name|flags
operator||=
name|QVectorPath
operator|::
name|AreaShapeMask
expr_stmt|;
if|if
condition|(
operator|!
name|convex
condition|)
name|flags
operator||=
name|QVectorPath
operator|::
name|NonConvexShapeMask
expr_stmt|;
block|}
block|}
name|QVarLengthArray
decl|<
name|QPainterPath
decl|::
name|ElementType
decl|>
name|elements
struct|;
name|QVarLengthArray
operator|<
name|qreal
operator|>
name|points
expr_stmt|;
name|uint
name|flags
decl_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_decl_stmt
name|QVectorPathData
name|pathData
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QVectorPath
name|path
decl_stmt|;
end_decl_stmt
begin_label
name|private
label|:
end_label
begin_macro
name|Q_DISABLE_COPY
argument_list|(
argument|QVectorPathConverter
argument_list|)
end_macro
begin_decl_stmt
unit|};
name|class
name|QPainterPathData
range|:
name|public
name|QPainterPathPrivate
block|{
name|public
operator|:
name|QPainterPathData
argument_list|()
operator|:
name|cStart
argument_list|(
literal|0
argument_list|)
block|,
name|fillRule
argument_list|(
name|Qt
operator|::
name|OddEvenFill
argument_list|)
block|,
name|dirtyBounds
argument_list|(
name|false
argument_list|)
block|,
name|dirtyControlBounds
argument_list|(
name|false
argument_list|)
block|,
name|pathConverter
argument_list|(
literal|0
argument_list|)
block|{
name|require_moveTo
operator|=
name|false
block|;
name|convex
operator|=
name|false
block|;     }
name|QPainterPathData
argument_list|(
specifier|const
name|QPainterPathData
operator|&
name|other
argument_list|)
operator|:
name|QPainterPathPrivate
argument_list|()
block|,
name|cStart
argument_list|(
name|other
operator|.
name|cStart
argument_list|)
block|,
name|fillRule
argument_list|(
name|other
operator|.
name|fillRule
argument_list|)
block|,
name|bounds
argument_list|(
name|other
operator|.
name|bounds
argument_list|)
block|,
name|controlBounds
argument_list|(
name|other
operator|.
name|controlBounds
argument_list|)
block|,
name|dirtyBounds
argument_list|(
name|other
operator|.
name|dirtyBounds
argument_list|)
block|,
name|dirtyControlBounds
argument_list|(
name|other
operator|.
name|dirtyControlBounds
argument_list|)
block|,
name|convex
argument_list|(
name|other
operator|.
name|convex
argument_list|)
block|,
name|pathConverter
argument_list|(
literal|0
argument_list|)
block|{
name|require_moveTo
operator|=
name|false
block|;
name|elements
operator|=
name|other
operator|.
name|elements
block|;     }
operator|~
name|QPainterPathData
argument_list|()
block|{
name|delete
name|pathConverter
block|;     }
specifier|inline
name|bool
name|isClosed
argument_list|()
specifier|const
block|;
specifier|inline
name|void
name|close
argument_list|()
block|;
specifier|inline
name|void
name|maybeMoveTo
argument_list|()
block|;
specifier|const
name|QVectorPath
operator|&
name|vectorPath
argument_list|()
block|{
if|if
condition|(
operator|!
name|pathConverter
condition|)
name|pathConverter
operator|=
name|new
name|QVectorPathConverter
argument_list|(
name|elements
argument_list|,
name|fillRule
argument_list|,
name|convex
argument_list|)
expr_stmt|;
return|return
name|pathConverter
operator|->
name|path
return|;
block|}
end_decl_stmt
begin_decl_stmt
name|int
name|cStart
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|Qt
operator|::
name|FillRule
name|fillRule
expr_stmt|;
end_expr_stmt
begin_decl_stmt
name|QRectF
name|bounds
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QRectF
name|controlBounds
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|uint
name|require_moveTo
range|:
literal|1
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|uint
name|dirtyBounds
range|:
literal|1
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|uint
name|dirtyControlBounds
range|:
literal|1
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|uint
name|convex
range|:
literal|1
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QVectorPathConverter
modifier|*
name|pathConverter
decl_stmt|;
end_decl_stmt
begin_expr_stmt
unit|};
DECL|function|convertToPainterPath
specifier|inline
specifier|const
name|QPainterPath
name|QVectorPath
operator|::
name|convertToPainterPath
argument_list|()
specifier|const
block|{
name|QPainterPath
name|path
block|;
name|path
operator|.
name|ensureData
argument_list|()
block|;
name|QPainterPathData
operator|*
name|data
operator|=
name|path
operator|.
name|d_func
argument_list|()
block|;
name|data
operator|->
name|elements
operator|.
name|reserve
argument_list|(
name|m_count
argument_list|)
block|;
name|int
name|index
operator|=
literal|0
block|;
name|data
operator|->
name|elements
index|[
literal|0
index|]
operator|.
name|x
operator|=
name|m_points
index|[
name|index
operator|++
index|]
block|;
name|data
operator|->
name|elements
index|[
literal|0
index|]
operator|.
name|y
operator|=
name|m_points
index|[
name|index
operator|++
index|]
block|;
if|if
condition|(
name|m_elements
condition|)
block|{
name|data
operator|->
name|elements
index|[
literal|0
index|]
operator|.
name|type
operator|=
name|m_elements
index|[
literal|0
index|]
expr_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|1
init|;
name|i
operator|<
name|m_count
condition|;
operator|++
name|i
control|)
block|{
name|QPainterPath
operator|::
name|Element
name|element
expr_stmt|;
name|element
operator|.
name|x
operator|=
name|m_points
index|[
name|index
operator|++
index|]
expr_stmt|;
name|element
operator|.
name|y
operator|=
name|m_points
index|[
name|index
operator|++
index|]
expr_stmt|;
name|element
operator|.
name|type
operator|=
name|m_elements
index|[
name|i
index|]
expr_stmt|;
name|data
operator|->
name|elements
operator|<<
name|element
expr_stmt|;
block|}
end_expr_stmt
begin_block
unit|} else
block|{
name|data
operator|->
name|elements
index|[
literal|0
index|]
operator|.
name|type
operator|=
name|QPainterPath
operator|::
name|MoveToElement
expr_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|1
init|;
name|i
operator|<
name|m_count
condition|;
operator|++
name|i
control|)
block|{
name|QPainterPath
operator|::
name|Element
name|element
expr_stmt|;
name|element
operator|.
name|x
operator|=
name|m_points
index|[
name|index
operator|++
index|]
expr_stmt|;
name|element
operator|.
name|y
operator|=
name|m_points
index|[
name|index
operator|++
index|]
expr_stmt|;
name|element
operator|.
name|type
operator|=
name|QPainterPath
operator|::
name|LineToElement
expr_stmt|;
name|data
operator|->
name|elements
operator|<<
name|element
expr_stmt|;
block|}
block|}
end_block
begin_if
if|if
condition|(
name|m_hints
operator|&
name|OddEvenFill
condition|)
name|data
operator|->
name|fillRule
operator|=
name|Qt
operator|::
name|OddEvenFill
expr_stmt|;
else|else
name|data
operator|->
name|fillRule
operator|=
name|Qt
operator|::
name|WindingFill
expr_stmt|;
end_if
begin_return
return|return
name|path
return|;
end_return
begin_function_decl
unit|}  void
name|Q_GUI_EXPORT
name|qt_find_ellipse_coords
parameter_list|(
specifier|const
name|QRectF
modifier|&
name|r
parameter_list|,
name|qreal
name|angle
parameter_list|,
name|qreal
name|length
parameter_list|,
name|QPointF
modifier|*
name|startPoint
parameter_list|,
name|QPointF
modifier|*
name|endPoint
parameter_list|)
function_decl|;
end_function_decl
begin_expr_stmt
DECL|function|isClosed
specifier|inline
name|bool
name|QPainterPathData
operator|::
name|isClosed
argument_list|()
specifier|const
block|{
specifier|const
name|QPainterPath
operator|::
name|Element
operator|&
name|first
operator|=
name|elements
operator|.
name|at
argument_list|(
name|cStart
argument_list|)
block|;
specifier|const
name|QPainterPath
operator|::
name|Element
operator|&
name|last
operator|=
name|elements
operator|.
name|last
argument_list|()
block|;
return|return
name|first
operator|.
name|x
operator|==
name|last
operator|.
name|x
operator|&&
name|first
operator|.
name|y
operator|==
name|last
operator|.
name|y
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|close
specifier|inline
name|void
name|QPainterPathData
operator|::
name|close
argument_list|()
block|{
name|Q_ASSERT
argument_list|(
name|ref
operator|.
name|load
argument_list|()
operator|==
literal|1
argument_list|)
block|;
name|require_moveTo
operator|=
name|true
block|;
specifier|const
name|QPainterPath
operator|::
name|Element
operator|&
name|first
operator|=
name|elements
operator|.
name|at
argument_list|(
name|cStart
argument_list|)
block|;
name|QPainterPath
operator|::
name|Element
operator|&
name|last
operator|=
name|elements
operator|.
name|last
argument_list|()
block|;
if|if
condition|(
name|first
operator|.
name|x
operator|!=
name|last
operator|.
name|x
operator|||
name|first
operator|.
name|y
operator|!=
name|last
operator|.
name|y
condition|)
block|{
if|if
condition|(
name|qFuzzyCompare
argument_list|(
name|first
operator|.
name|x
argument_list|,
name|last
operator|.
name|x
argument_list|)
operator|&&
name|qFuzzyCompare
argument_list|(
name|first
operator|.
name|y
argument_list|,
name|last
operator|.
name|y
argument_list|)
condition|)
block|{
name|last
operator|.
name|x
operator|=
name|first
operator|.
name|x
expr_stmt|;
name|last
operator|.
name|y
operator|=
name|first
operator|.
name|y
expr_stmt|;
block|}
end_expr_stmt
begin_else
else|else
block|{
name|QPainterPath
operator|::
name|Element
name|e
operator|=
block|{
name|first
operator|.
name|x
block|,
name|first
operator|.
name|y
block|,
name|QPainterPath
operator|::
name|LineToElement
block|}
expr_stmt|;
name|elements
operator|<<
name|e
expr_stmt|;
block|}
end_else
begin_expr_stmt
unit|} }
DECL|function|maybeMoveTo
specifier|inline
name|void
name|QPainterPathData
operator|::
name|maybeMoveTo
argument_list|()
block|{
if|if
condition|(
name|require_moveTo
condition|)
block|{
name|QPainterPath
operator|::
name|Element
name|e
operator|=
name|elements
operator|.
name|last
argument_list|()
expr_stmt|;
name|e
operator|.
name|type
operator|=
name|QPainterPath
operator|::
name|MoveToElement
expr_stmt|;
name|elements
operator|.
name|append
argument_list|(
name|e
argument_list|)
expr_stmt|;
name|require_moveTo
operator|=
name|false
expr_stmt|;
block|}
end_expr_stmt
begin_define
DECL|macro|KAPPA
unit|}
define|#
directive|define
name|KAPPA
value|qreal(0.5522847498)
end_define
begin_endif
unit|QT_END_NAMESPACE
endif|#
directive|endif
end_endif
begin_comment
comment|// QPAINTERPATH_P_H
end_comment
end_unit
