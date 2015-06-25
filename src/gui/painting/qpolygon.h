begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QPOLYGON_H
end_ifndef
begin_define
DECL|macro|QPOLYGON_H
define|#
directive|define
name|QPOLYGON_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qvector.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qpoint.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qrect.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QMatrix
name|class
name|QMatrix
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QTransform
name|class
name|QTransform
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QRect
name|class
name|QRect
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QVariant
name|class
name|QVariant
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_GUI_EXPORT
name|QPolygon
range|:
name|public
name|QVector
operator|<
name|QPoint
operator|>
block|{
name|public
operator|:
specifier|inline
name|QPolygon
argument_list|()
block|{}
specifier|inline
operator|~
name|QPolygon
argument_list|()
block|{}
specifier|inline
name|explicit
name|QPolygon
argument_list|(
argument|int size
argument_list|)
block|;
specifier|inline
name|QPolygon
argument_list|(
specifier|const
name|QPolygon
operator|&
name|a
argument_list|)
operator|:
name|QVector
operator|<
name|QPoint
operator|>
operator|(
name|a
operator|)
block|{}
specifier|inline
comment|/*implicit*/
name|QPolygon
argument_list|(
specifier|const
name|QVector
operator|<
name|QPoint
operator|>
operator|&
name|v
argument_list|)
operator|:
name|QVector
operator|<
name|QPoint
operator|>
operator|(
name|v
operator|)
block|{}
name|QPolygon
argument_list|(
argument|const QRect&r
argument_list|,
argument|bool closed=false
argument_list|)
block|;
name|QPolygon
argument_list|(
argument|int nPoints
argument_list|,
argument|const int *points
argument_list|)
block|;
ifdef|#
directive|ifdef
name|Q_COMPILER_RVALUE_REFS
name|QPolygon
operator|&
name|operator
operator|=
operator|(
name|QPolygon
operator|&&
name|other
operator|)
name|Q_DECL_NOTHROW
block|{
name|swap
argument_list|(
name|other
argument_list|)
block|;
return|return
operator|*
name|this
return|;
block|}
endif|#
directive|endif
name|QPolygon
operator|&
name|operator
operator|=
operator|(
specifier|const
name|QPolygon
operator|&
name|other
operator|)
block|{
name|QVector
operator|<
name|QPoint
operator|>
operator|::
name|operator
operator|=
operator|(
name|other
operator|)
block|;
return|return
operator|*
name|this
return|;
block|}
name|void
name|swap
argument_list|(
argument|QPolygon&other
argument_list|)
name|Q_DECL_NOTHROW
block|{
name|QVector
operator|<
name|QPoint
operator|>
operator|::
name|swap
argument_list|(
name|other
argument_list|)
block|; }
comment|// prevent QVector<QPoint><->QPolygon swaps
name|operator
name|QVariant
argument_list|()
specifier|const
block|;
name|void
name|translate
argument_list|(
argument|int dx
argument_list|,
argument|int dy
argument_list|)
block|;
name|void
name|translate
argument_list|(
specifier|const
name|QPoint
operator|&
name|offset
argument_list|)
block|;
name|QPolygon
name|translated
argument_list|(
argument|int dx
argument_list|,
argument|int dy
argument_list|)
specifier|const
name|Q_REQUIRED_RESULT
block|;
specifier|inline
name|QPolygon
name|translated
argument_list|(
argument|const QPoint&offset
argument_list|)
specifier|const
name|Q_REQUIRED_RESULT
block|;
name|QRect
name|boundingRect
argument_list|()
specifier|const
block|;
name|void
name|point
argument_list|(
argument|int i
argument_list|,
argument|int *x
argument_list|,
argument|int *y
argument_list|)
specifier|const
block|;
name|QPoint
name|point
argument_list|(
argument|int i
argument_list|)
specifier|const
block|;
name|void
name|setPoint
argument_list|(
argument|int index
argument_list|,
argument|int x
argument_list|,
argument|int y
argument_list|)
block|;
name|void
name|setPoint
argument_list|(
argument|int index
argument_list|,
argument|const QPoint&p
argument_list|)
block|;
name|void
name|setPoints
argument_list|(
argument|int nPoints
argument_list|,
argument|const int *points
argument_list|)
block|;
name|void
name|setPoints
argument_list|(
argument|int nPoints
argument_list|,
argument|int firstx
argument_list|,
argument|int firsty
argument_list|,
argument|...
argument_list|)
block|;
name|void
name|putPoints
argument_list|(
argument|int index
argument_list|,
argument|int nPoints
argument_list|,
argument|const int *points
argument_list|)
block|;
name|void
name|putPoints
argument_list|(
argument|int index
argument_list|,
argument|int nPoints
argument_list|,
argument|int firstx
argument_list|,
argument|int firsty
argument_list|,
argument|...
argument_list|)
block|;
name|void
name|putPoints
argument_list|(
argument|int index
argument_list|,
argument|int nPoints
argument_list|,
argument|const QPolygon& from
argument_list|,
argument|int fromIndex=
literal|0
argument_list|)
block|;
name|bool
name|containsPoint
argument_list|(
argument|const QPoint&pt
argument_list|,
argument|Qt::FillRule fillRule
argument_list|)
specifier|const
block|;
name|QPolygon
name|united
argument_list|(
argument|const QPolygon&r
argument_list|)
specifier|const
name|Q_REQUIRED_RESULT
block|;
name|QPolygon
name|intersected
argument_list|(
argument|const QPolygon&r
argument_list|)
specifier|const
name|Q_REQUIRED_RESULT
block|;
name|QPolygon
name|subtracted
argument_list|(
argument|const QPolygon&r
argument_list|)
specifier|const
name|Q_REQUIRED_RESULT
block|; }
decl_stmt|;
end_decl_stmt
begin_expr_stmt
DECL|function|QPolygon
specifier|inline
name|QPolygon
operator|::
name|QPolygon
argument_list|(
argument|int asize
argument_list|)
operator|:
name|QVector
operator|<
name|QPoint
operator|>
operator|(
name|asize
operator|)
block|{}
ifndef|#
directive|ifndef
name|QT_NO_DEBUG_STREAM
name|Q_GUI_EXPORT
name|QDebug
name|operator
operator|<<
operator|(
name|QDebug
operator|,
specifier|const
name|QPolygon
operator|&
operator|)
expr_stmt|;
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/*****************************************************************************   QPolygon stream functions  *****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_DATASTREAM
end_ifndef
begin_expr_stmt
name|Q_GUI_EXPORT
name|QDataStream
operator|&
name|operator
operator|<<
operator|(
name|QDataStream
operator|&
name|stream
operator|,
specifier|const
name|QPolygon
operator|&
name|polygon
operator|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|Q_GUI_EXPORT
name|QDataStream
operator|&
name|operator
operator|>>
operator|(
name|QDataStream
operator|&
name|stream
operator|,
name|QPolygon
operator|&
name|polygon
operator|)
expr_stmt|;
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/*****************************************************************************   Misc. QPolygon functions  *****************************************************************************/
end_comment
begin_expr_stmt
DECL|function|setPoint
specifier|inline
name|void
name|QPolygon
operator|::
name|setPoint
argument_list|(
argument|int index
argument_list|,
argument|const QPoint&pt
argument_list|)
block|{
operator|(
operator|*
name|this
operator|)
index|[
name|index
index|]
operator|=
name|pt
block|; }
DECL|function|setPoint
specifier|inline
name|void
name|QPolygon
operator|::
name|setPoint
argument_list|(
argument|int index
argument_list|,
argument|int x
argument_list|,
argument|int y
argument_list|)
block|{
operator|(
operator|*
name|this
operator|)
index|[
name|index
index|]
operator|=
name|QPoint
argument_list|(
name|x
argument_list|,
name|y
argument_list|)
block|; }
DECL|function|point
specifier|inline
name|QPoint
name|QPolygon
operator|::
name|point
argument_list|(
argument|int index
argument_list|)
specifier|const
block|{
return|return
name|at
argument_list|(
name|index
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|translate
specifier|inline
name|void
name|QPolygon
operator|::
name|translate
argument_list|(
argument|const QPoint&offset
argument_list|)
block|{
name|translate
argument_list|(
name|offset
operator|.
name|x
argument_list|()
argument_list|,
name|offset
operator|.
name|y
argument_list|()
argument_list|)
block|; }
DECL|function|translated
specifier|inline
name|QPolygon
name|QPolygon
operator|::
name|translated
argument_list|(
argument|const QPoint&offset
argument_list|)
specifier|const
block|{
return|return
name|translated
argument_list|(
name|offset
operator|.
name|x
argument_list|()
argument_list|,
name|offset
operator|.
name|y
argument_list|()
argument_list|)
return|;
block|}
end_expr_stmt
begin_decl_stmt
DECL|variable|QRectF
name|class
name|QRectF
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_GUI_EXPORT
name|QPolygonF
range|:
name|public
name|QVector
operator|<
name|QPointF
operator|>
block|{
name|public
operator|:
specifier|inline
name|QPolygonF
argument_list|()
block|{}
specifier|inline
operator|~
name|QPolygonF
argument_list|()
block|{}
specifier|inline
name|explicit
name|QPolygonF
argument_list|(
argument|int size
argument_list|)
block|;
specifier|inline
name|QPolygonF
argument_list|(
specifier|const
name|QPolygonF
operator|&
name|a
argument_list|)
operator|:
name|QVector
operator|<
name|QPointF
operator|>
operator|(
name|a
operator|)
block|{}
specifier|inline
comment|/*implicit*/
name|QPolygonF
argument_list|(
specifier|const
name|QVector
operator|<
name|QPointF
operator|>
operator|&
name|v
argument_list|)
operator|:
name|QVector
operator|<
name|QPointF
operator|>
operator|(
name|v
operator|)
block|{}
name|QPolygonF
argument_list|(
specifier|const
name|QRectF
operator|&
name|r
argument_list|)
block|;
comment|/*implicit*/
name|QPolygonF
argument_list|(
specifier|const
name|QPolygon
operator|&
name|a
argument_list|)
block|;
ifdef|#
directive|ifdef
name|Q_COMPILER_RVALUE_REFS
name|QPolygonF
operator|&
name|operator
operator|=
operator|(
name|QPolygonF
operator|&&
name|other
operator|)
name|Q_DECL_NOTHROW
block|{
name|swap
argument_list|(
name|other
argument_list|)
block|;
return|return
operator|*
name|this
return|;
block|}
endif|#
directive|endif
name|QPolygonF
operator|&
name|operator
operator|=
operator|(
specifier|const
name|QPolygonF
operator|&
name|other
operator|)
block|{
name|QVector
operator|<
name|QPointF
operator|>
operator|::
name|operator
operator|=
operator|(
name|other
operator|)
block|;
return|return
operator|*
name|this
return|;
block|}
specifier|inline
name|void
name|swap
argument_list|(
argument|QPolygonF&other
argument_list|)
block|{
name|QVector
operator|<
name|QPointF
operator|>
operator|::
name|swap
argument_list|(
name|other
argument_list|)
block|; }
comment|// prevent QVector<QPointF><->QPolygonF swaps
name|operator
name|QVariant
argument_list|()
specifier|const
block|;
specifier|inline
name|void
name|translate
argument_list|(
argument|qreal dx
argument_list|,
argument|qreal dy
argument_list|)
block|;
name|void
name|translate
argument_list|(
specifier|const
name|QPointF
operator|&
name|offset
argument_list|)
block|;
specifier|inline
name|QPolygonF
name|translated
argument_list|(
argument|qreal dx
argument_list|,
argument|qreal dy
argument_list|)
specifier|const
block|;
name|QPolygonF
name|translated
argument_list|(
argument|const QPointF&offset
argument_list|)
specifier|const
name|Q_REQUIRED_RESULT
block|;
name|QPolygon
name|toPolygon
argument_list|()
specifier|const
block|;
name|bool
name|isClosed
argument_list|()
specifier|const
block|{
return|return
operator|!
name|isEmpty
argument_list|()
operator|&&
name|first
argument_list|()
operator|==
name|last
argument_list|()
return|;
block|}
name|QRectF
name|boundingRect
argument_list|()
specifier|const
block|;
name|bool
name|containsPoint
argument_list|(
argument|const QPointF&pt
argument_list|,
argument|Qt::FillRule fillRule
argument_list|)
specifier|const
block|;
name|QPolygonF
name|united
argument_list|(
argument|const QPolygonF&r
argument_list|)
specifier|const
name|Q_REQUIRED_RESULT
block|;
name|QPolygonF
name|intersected
argument_list|(
argument|const QPolygonF&r
argument_list|)
specifier|const
name|Q_REQUIRED_RESULT
block|;
name|QPolygonF
name|subtracted
argument_list|(
argument|const QPolygonF&r
argument_list|)
specifier|const
name|Q_REQUIRED_RESULT
block|; }
decl_stmt|;
end_decl_stmt
begin_expr_stmt
DECL|function|QPolygonF
specifier|inline
name|QPolygonF
operator|::
name|QPolygonF
argument_list|(
argument|int asize
argument_list|)
operator|:
name|QVector
operator|<
name|QPointF
operator|>
operator|(
name|asize
operator|)
block|{}
ifndef|#
directive|ifndef
name|QT_NO_DEBUG_STREAM
name|Q_GUI_EXPORT
name|QDebug
name|operator
operator|<<
operator|(
name|QDebug
operator|,
specifier|const
name|QPolygonF
operator|&
operator|)
expr_stmt|;
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/*****************************************************************************   QPolygonF stream functions  *****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_DATASTREAM
end_ifndef
begin_expr_stmt
name|Q_GUI_EXPORT
name|QDataStream
operator|&
name|operator
operator|<<
operator|(
name|QDataStream
operator|&
name|stream
operator|,
specifier|const
name|QPolygonF
operator|&
name|array
operator|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|Q_GUI_EXPORT
name|QDataStream
operator|&
name|operator
operator|>>
operator|(
name|QDataStream
operator|&
name|stream
operator|,
name|QPolygonF
operator|&
name|array
operator|)
expr_stmt|;
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_expr_stmt
DECL|function|translate
specifier|inline
name|void
name|QPolygonF
operator|::
name|translate
argument_list|(
argument|qreal dx
argument_list|,
argument|qreal dy
argument_list|)
block|{
name|translate
argument_list|(
name|QPointF
argument_list|(
name|dx
argument_list|,
name|dy
argument_list|)
argument_list|)
block|; }
DECL|function|translated
specifier|inline
name|QPolygonF
name|QPolygonF
operator|::
name|translated
argument_list|(
argument|qreal dx
argument_list|,
argument|qreal dy
argument_list|)
specifier|const
block|{
return|return
name|translated
argument_list|(
name|QPointF
argument_list|(
name|dx
argument_list|,
name|dy
argument_list|)
argument_list|)
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
comment|// QPOLYGON_H
end_comment
end_unit
