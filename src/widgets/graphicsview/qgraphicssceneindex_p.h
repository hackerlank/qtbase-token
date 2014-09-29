begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2014 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia. For licensing terms and ** conditions see http://qt.digia.com/licensing. For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights. These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QGRAPHICSSCENEINDEX_H
end_ifndef
begin_define
DECL|macro|QGRAPHICSSCENEINDEX_H
define|#
directive|define
name|QGRAPHICSSCENEINDEX_H
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
file|"qgraphicsscene_p.h"
end_include
begin_include
include|#
directive|include
file|"qgraphicsscene.h"
end_include
begin_include
include|#
directive|include
file|<private/qobject_p.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qnamespace.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qobject.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/qtransform.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
if|#
directive|if
operator|!
name|defined
argument_list|(
name|QT_NO_GRAPHICSVIEW
argument_list|)
DECL|variable|QGraphicsSceneIndexPrivate
name|class
name|QGraphicsSceneIndexPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QPointF
name|class
name|QPointF
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QRectF
name|class
name|QRectF
decl_stmt|;
end_decl_stmt
begin_expr_stmt
DECL|variable|QList
name|template
operator|<
name|typename
name|T
operator|>
name|class
name|QList
expr_stmt|;
end_expr_stmt
begin_typedef
DECL|typedef|QGraphicsSceneIndexIntersector
typedef|typedef
name|bool
argument_list|(
argument|*QGraphicsSceneIndexIntersector
argument_list|)
operator|(
specifier|const
name|QGraphicsItem
operator|*
name|item
operator|,
specifier|const
name|QRectF
operator|&
name|exposeRect
operator|,
name|Qt
operator|::
name|ItemSelectionMode
name|mode
operator|,
specifier|const
name|QTransform
operator|&
name|deviceTransform
operator|,
specifier|const
name|void
operator|*
name|data
operator|)
expr_stmt|;
end_typedef
begin_decl_stmt
name|class
name|Q_AUTOTEST_EXPORT
name|QGraphicsSceneIndex
range|:
name|public
name|QObject
block|{
name|Q_OBJECT
name|public
operator|:
name|QGraphicsSceneIndex
argument_list|(
name|QGraphicsScene
operator|*
name|scene
operator|=
literal|0
argument_list|)
block|;
name|virtual
operator|~
name|QGraphicsSceneIndex
argument_list|()
block|;
name|QGraphicsScene
operator|*
name|scene
argument_list|()
specifier|const
block|;
name|virtual
name|QList
operator|<
name|QGraphicsItem
operator|*
operator|>
name|items
argument_list|(
argument|Qt::SortOrder order = Qt::DescendingOrder
argument_list|)
specifier|const
operator|=
literal|0
block|;
name|virtual
name|QList
operator|<
name|QGraphicsItem
operator|*
operator|>
name|items
argument_list|(
argument|const QPointF&pos
argument_list|,
argument|Qt::ItemSelectionMode mode
argument_list|,
argument|Qt::SortOrder order
argument_list|,
argument|const QTransform&deviceTransform = QTransform()
argument_list|)
specifier|const
block|;
name|virtual
name|QList
operator|<
name|QGraphicsItem
operator|*
operator|>
name|items
argument_list|(
argument|const QRectF&rect
argument_list|,
argument|Qt::ItemSelectionMode mode
argument_list|,
argument|Qt::SortOrder order
argument_list|,
argument|const QTransform&deviceTransform = QTransform()
argument_list|)
specifier|const
block|;
name|virtual
name|QList
operator|<
name|QGraphicsItem
operator|*
operator|>
name|items
argument_list|(
argument|const QPolygonF&polygon
argument_list|,
argument|Qt::ItemSelectionMode mode
argument_list|,
argument|Qt::SortOrder order
argument_list|,
argument|const QTransform&deviceTransform = QTransform()
argument_list|)
specifier|const
block|;
name|virtual
name|QList
operator|<
name|QGraphicsItem
operator|*
operator|>
name|items
argument_list|(
argument|const QPainterPath&path
argument_list|,
argument|Qt::ItemSelectionMode mode
argument_list|,
argument|Qt::SortOrder order
argument_list|,
argument|const QTransform&deviceTransform = QTransform()
argument_list|)
specifier|const
block|;
name|virtual
name|QList
operator|<
name|QGraphicsItem
operator|*
operator|>
name|estimateItems
argument_list|(
argument|const QPointF&point
argument_list|,
argument|Qt::SortOrder order
argument_list|)
specifier|const
block|;
name|virtual
name|QList
operator|<
name|QGraphicsItem
operator|*
operator|>
name|estimateItems
argument_list|(
argument|const QRectF&rect
argument_list|,
argument|Qt::SortOrder order
argument_list|)
specifier|const
operator|=
literal|0
block|;
name|virtual
name|QList
operator|<
name|QGraphicsItem
operator|*
operator|>
name|estimateTopLevelItems
argument_list|(
argument|const QRectF&
argument_list|,
argument|Qt::SortOrder order
argument_list|)
specifier|const
block|;
name|protected
name|Q_SLOTS
operator|:
name|virtual
name|void
name|updateSceneRect
argument_list|(
specifier|const
name|QRectF
operator|&
name|rect
argument_list|)
block|;
name|protected
operator|:
name|virtual
name|void
name|clear
argument_list|()
block|;
name|virtual
name|void
name|addItem
argument_list|(
name|QGraphicsItem
operator|*
name|item
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|void
name|removeItem
argument_list|(
name|QGraphicsItem
operator|*
name|item
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|void
name|deleteItem
argument_list|(
name|QGraphicsItem
operator|*
name|item
argument_list|)
block|;
name|virtual
name|void
name|itemChange
argument_list|(
specifier|const
name|QGraphicsItem
operator|*
name|item
argument_list|,
name|QGraphicsItem
operator|::
name|GraphicsItemChange
argument_list|,
specifier|const
name|void
operator|*
specifier|const
name|value
argument_list|)
block|;
name|virtual
name|void
name|prepareBoundingRectChange
argument_list|(
specifier|const
name|QGraphicsItem
operator|*
name|item
argument_list|)
block|;
name|QGraphicsSceneIndex
argument_list|(
name|QGraphicsSceneIndexPrivate
operator|&
name|dd
argument_list|,
name|QGraphicsScene
operator|*
name|scene
argument_list|)
block|;
name|friend
name|class
name|QGraphicsScene
block|;
name|friend
name|class
name|QGraphicsScenePrivate
block|;
name|friend
name|class
name|QGraphicsItem
block|;
name|friend
name|class
name|QGraphicsItemPrivate
block|;
name|friend
name|class
name|QGraphicsSceneBspTreeIndex
block|;
name|private
operator|:
name|Q_DISABLE_COPY
argument_list|(
argument|QGraphicsSceneIndex
argument_list|)
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QGraphicsSceneIndex
argument_list|)
block|}
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QGraphicsSceneIndexPrivate
range|:
name|public
name|QObjectPrivate
block|{
name|Q_DECLARE_PUBLIC
argument_list|(
argument|QGraphicsSceneIndex
argument_list|)
name|public
operator|:
name|QGraphicsSceneIndexPrivate
argument_list|(
name|QGraphicsScene
operator|*
name|scene
argument_list|)
block|;
operator|~
name|QGraphicsSceneIndexPrivate
argument_list|()
block|;
name|void
name|init
argument_list|()
block|;
specifier|static
name|bool
name|itemCollidesWithPath
argument_list|(
argument|const QGraphicsItem *item
argument_list|,
argument|const QPainterPath&path
argument_list|,
argument|Qt::ItemSelectionMode mode
argument_list|)
block|;
name|void
name|recursive_items_helper
argument_list|(
argument|QGraphicsItem *item
argument_list|,
argument|QRectF exposeRect
argument_list|,
argument|QGraphicsSceneIndexIntersector intersect
argument_list|,
argument|QList<QGraphicsItem *> *items
argument_list|,
argument|const QTransform&viewTransform
argument_list|,
argument|Qt::ItemSelectionMode mode
argument_list|,
argument|qreal parentOpacity
argument_list|,
argument|const void *intersectData
argument_list|)
specifier|const
block|;
specifier|inline
name|void
name|items_helper
argument_list|(
argument|const QRectF&rect
argument_list|,
argument|QGraphicsSceneIndexIntersector intersect
argument_list|,
argument|QList<QGraphicsItem *> *items
argument_list|,
argument|const QTransform&viewTransform
argument_list|,
argument|Qt::ItemSelectionMode mode
argument_list|,
argument|Qt::SortOrder order
argument_list|,
argument|const void *intersectData
argument_list|)
specifier|const
block|;
name|QGraphicsScene
operator|*
name|scene
block|; }
decl_stmt|;
end_decl_stmt
begin_expr_stmt
DECL|function|items_helper
specifier|inline
name|void
name|QGraphicsSceneIndexPrivate
operator|::
name|items_helper
argument_list|(
argument|const QRectF&rect
argument_list|,
argument|QGraphicsSceneIndexIntersector intersect
argument_list|,
argument|QList<QGraphicsItem *> *items
argument_list|,
argument|const QTransform&viewTransform
argument_list|,
argument|Qt::ItemSelectionMode mode
argument_list|,
argument|Qt::SortOrder order
argument_list|,
argument|const void *intersectData
argument_list|)
specifier|const
block|{
name|Q_Q
argument_list|(
specifier|const
name|QGraphicsSceneIndex
argument_list|)
block|;
specifier|const
name|QList
operator|<
name|QGraphicsItem
operator|*
operator|>
name|tli
operator|=
name|q
operator|->
name|estimateTopLevelItems
argument_list|(
name|rect
argument_list|,
name|Qt
operator|::
name|AscendingOrder
argument_list|)
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
name|tli
operator|.
name|size
argument_list|()
condition|;
operator|++
name|i
control|)
name|recursive_items_helper
argument_list|(
name|tli
operator|.
name|at
argument_list|(
name|i
argument_list|)
argument_list|,
name|rect
argument_list|,
name|intersect
argument_list|,
name|items
argument_list|,
name|viewTransform
argument_list|,
name|mode
argument_list|,
literal|1.0
argument_list|,
name|intersectData
argument_list|)
expr_stmt|;
end_expr_stmt
begin_if
if|if
condition|(
name|order
operator|==
name|Qt
operator|::
name|DescendingOrder
condition|)
block|{
specifier|const
name|int
name|n
init|=
name|items
operator|->
name|size
argument_list|()
decl_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|n
operator|/
literal|2
condition|;
operator|++
name|i
control|)
name|items
operator|->
name|swap
argument_list|(
name|i
argument_list|,
name|n
operator|-
name|i
operator|-
literal|1
argument_list|)
expr_stmt|;
block|}
end_if
begin_endif
unit|}
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_GRAPHICSVIEW
end_comment
begin_endif
unit|QT_END_NAMESPACE
endif|#
directive|endif
end_endif
begin_comment
comment|// QGRAPHICSSCENEINDEX_H
end_comment
end_unit
