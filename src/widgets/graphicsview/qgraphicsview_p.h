begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the QtWidgets module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QGRAPHICSVIEW_P_H
end_ifndef
begin_define
DECL|macro|QGRAPHICSVIEW_P_H
define|#
directive|define
name|QGRAPHICSVIEW_P_H
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
file|"qgraphicsview.h"
end_include
begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|QT_NO_GRAPHICSVIEW
argument_list|)
end_if
begin_include
include|#
directive|include
file|<QtGui/qevent.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qcoreapplication.h>
end_include
begin_include
include|#
directive|include
file|"qgraphicssceneevent.h"
end_include
begin_include
include|#
directive|include
file|<QtWidgets/qstyleoption.h>
end_include
begin_include
include|#
directive|include
file|<private/qabstractscrollarea_p.h>
end_include
begin_include
include|#
directive|include
file|<private/qapplication_p.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
name|class
name|Q_WIDGETS_EXPORT
name|QGraphicsViewPrivate
range|:
name|public
name|QAbstractScrollAreaPrivate
block|{
name|Q_DECLARE_PUBLIC
argument_list|(
argument|QGraphicsView
argument_list|)
name|public
operator|:
name|QGraphicsViewPrivate
argument_list|()
block|;
operator|~
name|QGraphicsViewPrivate
argument_list|()
block|;
name|void
name|recalculateContentSize
argument_list|()
block|;
name|void
name|centerView
argument_list|(
argument|QGraphicsView::ViewportAnchor anchor
argument_list|)
block|;
name|QPainter
operator|::
name|RenderHints
name|renderHints
block|;
name|QGraphicsView
operator|::
name|DragMode
name|dragMode
block|;
name|quint32
name|sceneInteractionAllowed
operator|:
literal|1
block|;
name|quint32
name|hasSceneRect
operator|:
literal|1
block|;
name|quint32
name|connectedToScene
operator|:
literal|1
block|;
name|quint32
name|useLastMouseEvent
operator|:
literal|1
block|;
name|quint32
name|identityMatrix
operator|:
literal|1
block|;
name|quint32
name|dirtyScroll
operator|:
literal|1
block|;
name|quint32
name|accelerateScrolling
operator|:
literal|1
block|;
name|quint32
name|keepLastCenterPoint
operator|:
literal|1
block|;
name|quint32
name|transforming
operator|:
literal|1
block|;
name|quint32
name|handScrolling
operator|:
literal|1
block|;
name|quint32
name|mustAllocateStyleOptions
operator|:
literal|1
block|;
name|quint32
name|mustResizeBackgroundPixmap
operator|:
literal|1
block|;
name|quint32
name|fullUpdatePending
operator|:
literal|1
block|;
name|quint32
name|hasUpdateClip
operator|:
literal|1
block|;
name|quint32
name|padding
operator|:
literal|18
block|;
name|QRectF
name|sceneRect
block|;
name|void
name|updateLastCenterPoint
argument_list|()
block|;
name|qint64
name|horizontalScroll
argument_list|()
specifier|const
block|;
name|qint64
name|verticalScroll
argument_list|()
specifier|const
block|;
name|QRectF
name|mapRectToScene
argument_list|(
argument|const QRect&rect
argument_list|)
specifier|const
block|;
name|QRectF
name|mapRectFromScene
argument_list|(
argument|const QRectF&rect
argument_list|)
specifier|const
block|;
name|QRect
name|updateClip
block|;
name|QPointF
name|mousePressItemPoint
block|;
name|QPointF
name|mousePressScenePoint
block|;
name|QPoint
name|mousePressViewPoint
block|;
name|QPoint
name|mousePressScreenPoint
block|;
name|QPointF
name|lastMouseMoveScenePoint
block|;
name|QPointF
name|lastRubberbandScenePoint
block|;
name|QPoint
name|lastMouseMoveScreenPoint
block|;
name|QPoint
name|dirtyScrollOffset
block|;
name|Qt
operator|::
name|MouseButton
name|mousePressButton
block|;
name|QTransform
name|matrix
block|;
name|qint64
name|scrollX
block|,
name|scrollY
block|;
name|void
name|updateScroll
argument_list|()
block|;
name|qreal
name|leftIndent
block|;
name|qreal
name|topIndent
block|;
comment|// Replaying mouse events
name|QMouseEvent
name|lastMouseEvent
block|;
name|void
name|replayLastMouseEvent
argument_list|()
block|;
name|void
name|storeMouseEvent
argument_list|(
name|QMouseEvent
operator|*
name|event
argument_list|)
block|;
name|void
name|mouseMoveEventHandler
argument_list|(
name|QMouseEvent
operator|*
name|event
argument_list|)
block|;
name|QPointF
name|lastCenterPoint
block|;
name|Qt
operator|::
name|Alignment
name|alignment
block|;
name|QGraphicsView
operator|::
name|ViewportAnchor
name|transformationAnchor
block|;
name|QGraphicsView
operator|::
name|ViewportAnchor
name|resizeAnchor
block|;
name|QGraphicsView
operator|::
name|ViewportUpdateMode
name|viewportUpdateMode
block|;
name|QGraphicsView
operator|::
name|OptimizationFlags
name|optimizationFlags
block|;
name|QPointer
operator|<
name|QGraphicsScene
operator|>
name|scene
block|;
ifndef|#
directive|ifndef
name|QT_NO_RUBBERBAND
name|QRect
name|rubberBandRect
block|;
name|QRegion
name|rubberBandRegion
argument_list|(
argument|const QWidget *widget
argument_list|,
argument|const QRect&rect
argument_list|)
specifier|const
block|;
name|void
name|updateRubberBand
argument_list|(
specifier|const
name|QMouseEvent
operator|*
name|event
argument_list|)
block|;
name|bool
name|rubberBanding
block|;
name|Qt
operator|::
name|ItemSelectionMode
name|rubberBandSelectionMode
block|;
name|Qt
operator|::
name|ItemSelectionOperation
name|rubberBandSelectionOperation
block|;
endif|#
directive|endif
name|int
name|handScrollMotions
block|;
name|QGraphicsView
operator|::
name|CacheMode
name|cacheMode
block|;
name|QVector
operator|<
name|QStyleOptionGraphicsItem
operator|>
name|styleOptions
block|;
name|QStyleOptionGraphicsItem
operator|*
name|allocStyleOptionsArray
argument_list|(
argument|int numItems
argument_list|)
block|;
name|void
name|freeStyleOptionsArray
argument_list|(
name|QStyleOptionGraphicsItem
operator|*
name|array
argument_list|)
block|;
name|QBrush
name|backgroundBrush
block|;
name|QBrush
name|foregroundBrush
block|;
name|QPixmap
name|backgroundPixmap
block|;
name|QRegion
name|backgroundPixmapExposed
block|;
ifndef|#
directive|ifndef
name|QT_NO_CURSOR
name|QCursor
name|originalCursor
block|;
name|bool
name|hasStoredOriginalCursor
block|;
name|void
name|_q_setViewportCursor
argument_list|(
specifier|const
name|QCursor
operator|&
name|cursor
argument_list|)
block|;
name|void
name|_q_unsetViewportCursor
argument_list|()
block|;
endif|#
directive|endif
name|QGraphicsSceneDragDropEvent
operator|*
name|lastDragDropEvent
block|;
name|void
name|storeDragDropEvent
argument_list|(
specifier|const
name|QGraphicsSceneDragDropEvent
operator|*
name|event
argument_list|)
block|;
name|void
name|populateSceneDragDropEvent
argument_list|(
name|QGraphicsSceneDragDropEvent
operator|*
name|dest
argument_list|,
name|QDropEvent
operator|*
name|source
argument_list|)
block|;
name|QRect
name|mapToViewRect
argument_list|(
argument|const QGraphicsItem *item
argument_list|,
argument|const QRectF&rect
argument_list|)
specifier|const
block|;
name|QRegion
name|mapToViewRegion
argument_list|(
argument|const QGraphicsItem *item
argument_list|,
argument|const QRectF&rect
argument_list|)
specifier|const
block|;
name|QRegion
name|dirtyRegion
block|;
name|QRect
name|dirtyBoundingRect
block|;
name|void
name|processPendingUpdates
argument_list|()
block|;
specifier|inline
name|void
name|updateAll
argument_list|()
block|{
name|viewport
operator|->
name|update
argument_list|()
block|;
name|fullUpdatePending
operator|=
name|true
block|;
name|dirtyBoundingRect
operator|=
name|QRect
argument_list|()
block|;
name|dirtyRegion
operator|=
name|QRegion
argument_list|()
block|;     }
specifier|inline
name|void
name|dispatchPendingUpdateRequests
argument_list|()
block|{
ifdef|#
directive|ifdef
name|Q_DEAD_CODE_FROM_QT4_MAC
comment|// QWidget::update() works slightly different on the Mac without the raster engine;
comment|// it's not part of our backing store so it needs special threatment.
if|if
condition|(
name|QApplicationPrivate
operator|::
name|graphics_system_name
operator|!=
name|QLatin1String
argument_list|(
literal|"raster"
argument_list|)
condition|)
block|{
comment|// At this point either HIViewSetNeedsDisplay (Carbon) or setNeedsDisplay: YES (Cocoa)
comment|// is called, which means there's a pending update request. We want to dispatch it
comment|// now because otherwise graphics view updates would require two
comment|// round-trips in the event loop before the item is painted.
specifier|extern
name|void
name|qt_mac_dispatchPendingUpdateRequests
parameter_list|(
name|QWidget
modifier|*
parameter_list|)
function_decl|;
name|qt_mac_dispatchPendingUpdateRequests
argument_list|(
name|viewport
operator|->
name|window
argument_list|()
argument_list|)
expr_stmt|;
block|}
else|else
endif|#
directive|endif
comment|// !Q_DEAD_CODE_FROM_QT4_MAC
block|{
if|if
condition|(
name|qt_widget_private
argument_list|(
name|viewport
argument_list|)
operator|->
name|paintOnScreen
argument_list|()
condition|)
name|QCoreApplication
operator|::
name|sendPostedEvents
argument_list|(
name|viewport
argument_list|,
name|QEvent
operator|::
name|UpdateRequest
argument_list|)
expr_stmt|;
else|else
name|QCoreApplication
operator|::
name|sendPostedEvents
argument_list|(
name|viewport
operator|->
name|window
argument_list|()
argument_list|,
name|QEvent
operator|::
name|UpdateRequest
argument_list|)
expr_stmt|;
block|}
block|}
name|void
name|setUpdateClip
argument_list|(
name|QGraphicsItem
operator|*
argument_list|)
block|;
specifier|inline
name|bool
name|updateRectF
argument_list|(
argument|const QRectF&rect
argument_list|)
block|{
if|if
condition|(
name|rect
operator|.
name|isEmpty
argument_list|()
condition|)
return|return
name|false
return|;
if|if
condition|(
name|optimizationFlags
operator|&
name|QGraphicsView
operator|::
name|DontAdjustForAntialiasing
condition|)
return|return
name|updateRect
argument_list|(
name|rect
operator|.
name|toAlignedRect
argument_list|()
operator|.
name|adjusted
argument_list|(
operator|-
literal|1
argument_list|,
operator|-
literal|1
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|)
argument_list|)
return|;
end_decl_stmt
begin_return
return|return
name|updateRect
argument_list|(
name|rect
operator|.
name|toAlignedRect
argument_list|()
operator|.
name|adjusted
argument_list|(
operator|-
literal|2
argument_list|,
operator|-
literal|2
argument_list|,
literal|2
argument_list|,
literal|2
argument_list|)
argument_list|)
return|;
end_return
begin_expr_stmt
unit|}      bool
name|updateRect
argument_list|(
specifier|const
name|QRect
operator|&
name|rect
argument_list|)
expr_stmt|;
end_expr_stmt
begin_function_decl
name|bool
name|updateRegion
parameter_list|(
specifier|const
name|QRectF
modifier|&
name|rect
parameter_list|,
specifier|const
name|QTransform
modifier|&
name|xform
parameter_list|)
function_decl|;
end_function_decl
begin_decl_stmt
name|bool
name|updateSceneSlotReimplementedChecked
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QRegion
name|exposedRegion
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|QList
operator|<
name|QGraphicsItem
operator|*
operator|>
name|findItems
argument_list|(
argument|const QRegion&exposedRegion
argument_list|,
argument|bool *allItems
argument_list|,
argument|const QTransform&viewTransform
argument_list|)
specifier|const
expr_stmt|;
end_expr_stmt
begin_decl_stmt
name|QPointF
name|mapToScene
argument_list|(
specifier|const
name|QPointF
operator|&
name|point
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QRectF
name|mapToScene
argument_list|(
specifier|const
name|QRectF
operator|&
name|rect
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt
begin_function_decl
specifier|static
name|void
name|translateTouchEvent
parameter_list|(
name|QGraphicsViewPrivate
modifier|*
name|d
parameter_list|,
name|QTouchEvent
modifier|*
name|touchEvent
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|updateInputMethodSensitivity
parameter_list|()
function_decl|;
end_function_decl
begin_macro
unit|};
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_GRAPHICSVIEW
end_comment
begin_endif
endif|#
directive|endif
end_endif
end_unit
