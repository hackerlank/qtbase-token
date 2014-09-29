begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2014 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia. For licensing terms and ** conditions see http://qt.digia.com/licensing. For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights. These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<private/qpaintengine_preview_p.h>
end_include
begin_include
include|#
directive|include
file|<private/qpainter_p.h>
end_include
begin_include
include|#
directive|include
file|<private/qpaintengine_p.h>
end_include
begin_include
include|#
directive|include
file|<private/qpicture_p.h>
end_include
begin_include
include|#
directive|include
file|<QtPrintSupport/qprintengine.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/qpainter.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/qpicture.h>
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_PRINTPREVIEWWIDGET
end_ifndef
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_class
DECL|class|QPreviewPaintEnginePrivate
class|class
name|QPreviewPaintEnginePrivate
super|:
specifier|public
name|QPaintEnginePrivate
block|{
name|Q_DECLARE_PUBLIC
parameter_list|(
name|QPreviewPaintEngine
parameter_list|)
specifier|public
private|:
DECL|function|QPreviewPaintEnginePrivate
name|QPreviewPaintEnginePrivate
parameter_list|()
member_init_list|:
name|state
argument_list|(
name|QPrinter
operator|::
name|Idle
argument_list|)
block|{}
DECL|function|~QPreviewPaintEnginePrivate
name|~
name|QPreviewPaintEnginePrivate
parameter_list|()
block|{}
DECL|member|pages
name|QList
argument_list|<
specifier|const
name|QPicture
modifier|*
argument_list|>
name|pages
decl_stmt|;
DECL|member|engine
name|QPaintEngine
modifier|*
name|engine
decl_stmt|;
DECL|member|painter
name|QPainter
modifier|*
name|painter
decl_stmt|;
DECL|member|state
name|QPrinter
operator|::
name|PrinterState
name|state
decl_stmt|;
DECL|member|proxy_paint_engine
name|QPaintEngine
modifier|*
name|proxy_paint_engine
decl_stmt|;
DECL|member|proxy_print_engine
name|QPrintEngine
modifier|*
name|proxy_print_engine
decl_stmt|;
block|}
class|;
end_class
begin_constructor
DECL|function|QPreviewPaintEngine
name|QPreviewPaintEngine
operator|::
name|QPreviewPaintEngine
parameter_list|()
member_init_list|:
name|QPaintEngine
argument_list|(
operator|*
operator|(
operator|new
name|QPreviewPaintEnginePrivate
operator|)
argument_list|,
name|PaintEngineFeatures
argument_list|(
name|AllFeatures
operator|&
operator|~
name|ObjectBoundingModeGradients
argument_list|)
argument_list|)
block|{
name|Q_D
argument_list|(
name|QPreviewPaintEngine
argument_list|)
expr_stmt|;
name|d
operator|->
name|proxy_print_engine
operator|=
literal|0
expr_stmt|;
name|d
operator|->
name|proxy_paint_engine
operator|=
literal|0
expr_stmt|;
block|}
end_constructor
begin_destructor
DECL|function|~QPreviewPaintEngine
name|QPreviewPaintEngine
operator|::
name|~
name|QPreviewPaintEngine
parameter_list|()
block|{
name|Q_D
argument_list|(
name|QPreviewPaintEngine
argument_list|)
expr_stmt|;
name|qDeleteAll
argument_list|(
name|d
operator|->
name|pages
argument_list|)
expr_stmt|;
block|}
end_destructor
begin_function
DECL|function|begin
name|bool
name|QPreviewPaintEngine
operator|::
name|begin
parameter_list|(
name|QPaintDevice
modifier|*
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QPreviewPaintEngine
argument_list|)
expr_stmt|;
name|qDeleteAll
argument_list|(
name|d
operator|->
name|pages
argument_list|)
expr_stmt|;
name|d
operator|->
name|pages
operator|.
name|clear
argument_list|()
expr_stmt|;
name|QPicture
modifier|*
name|page
init|=
operator|new
name|QPicture
decl_stmt|;
name|page
operator|->
name|d_func
argument_list|()
operator|->
name|in_memory_only
operator|=
literal|true
expr_stmt|;
name|d
operator|->
name|painter
operator|=
operator|new
name|QPainter
argument_list|(
name|page
argument_list|)
expr_stmt|;
name|d
operator|->
name|engine
operator|=
name|d
operator|->
name|painter
operator|->
name|paintEngine
argument_list|()
expr_stmt|;
operator|*
name|d
operator|->
name|painter
operator|->
name|d_func
argument_list|()
operator|->
name|state
operator|=
operator|*
name|painter
argument_list|()
operator|->
name|d_func
argument_list|()
operator|->
name|state
expr_stmt|;
name|d
operator|->
name|pages
operator|.
name|append
argument_list|(
name|page
argument_list|)
expr_stmt|;
name|d
operator|->
name|state
operator|=
name|QPrinter
operator|::
name|Active
expr_stmt|;
return|return
literal|true
return|;
block|}
end_function
begin_function
DECL|function|end
name|bool
name|QPreviewPaintEngine
operator|::
name|end
parameter_list|()
block|{
name|Q_D
argument_list|(
name|QPreviewPaintEngine
argument_list|)
expr_stmt|;
operator|delete
name|d
operator|->
name|painter
expr_stmt|;
name|d
operator|->
name|painter
operator|=
literal|0
expr_stmt|;
name|d
operator|->
name|engine
operator|=
literal|0
expr_stmt|;
name|d
operator|->
name|state
operator|=
name|QPrinter
operator|::
name|Idle
expr_stmt|;
return|return
literal|true
return|;
block|}
end_function
begin_function
DECL|function|updateState
name|void
name|QPreviewPaintEngine
operator|::
name|updateState
parameter_list|(
specifier|const
name|QPaintEngineState
modifier|&
name|state
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QPreviewPaintEngine
argument_list|)
expr_stmt|;
name|d
operator|->
name|engine
operator|->
name|updateState
argument_list|(
name|state
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|drawPath
name|void
name|QPreviewPaintEngine
operator|::
name|drawPath
parameter_list|(
specifier|const
name|QPainterPath
modifier|&
name|path
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QPreviewPaintEngine
argument_list|)
expr_stmt|;
name|d
operator|->
name|engine
operator|->
name|drawPath
argument_list|(
name|path
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|drawPolygon
name|void
name|QPreviewPaintEngine
operator|::
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
block|{
name|Q_D
argument_list|(
name|QPreviewPaintEngine
argument_list|)
expr_stmt|;
name|d
operator|->
name|engine
operator|->
name|drawPolygon
argument_list|(
name|points
argument_list|,
name|pointCount
argument_list|,
name|mode
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|drawTextItem
name|void
name|QPreviewPaintEngine
operator|::
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
block|{
name|Q_D
argument_list|(
name|QPreviewPaintEngine
argument_list|)
expr_stmt|;
name|d
operator|->
name|engine
operator|->
name|drawTextItem
argument_list|(
name|p
argument_list|,
name|textItem
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|drawPixmap
name|void
name|QPreviewPaintEngine
operator|::
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
block|{
name|Q_D
argument_list|(
name|QPreviewPaintEngine
argument_list|)
expr_stmt|;
name|d
operator|->
name|engine
operator|->
name|drawPixmap
argument_list|(
name|r
argument_list|,
name|pm
argument_list|,
name|sr
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|drawTiledPixmap
name|void
name|QPreviewPaintEngine
operator|::
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
name|pm
parameter_list|,
specifier|const
name|QPointF
modifier|&
name|p
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QPreviewPaintEngine
argument_list|)
expr_stmt|;
name|d
operator|->
name|engine
operator|->
name|drawTiledPixmap
argument_list|(
name|r
argument_list|,
name|pm
argument_list|,
name|p
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|newPage
name|bool
name|QPreviewPaintEngine
operator|::
name|newPage
parameter_list|()
block|{
name|Q_D
argument_list|(
name|QPreviewPaintEngine
argument_list|)
expr_stmt|;
name|QPicture
modifier|*
name|page
init|=
operator|new
name|QPicture
decl_stmt|;
name|page
operator|->
name|d_func
argument_list|()
operator|->
name|in_memory_only
operator|=
literal|true
expr_stmt|;
name|QPainter
modifier|*
name|tmp_painter
init|=
operator|new
name|QPainter
argument_list|(
name|page
argument_list|)
decl_stmt|;
name|QPaintEngine
modifier|*
name|tmp_engine
init|=
name|tmp_painter
operator|->
name|paintEngine
argument_list|()
decl_stmt|;
comment|// copy the painter state from the original painter
name|Q_ASSERT
argument_list|(
name|painter
argument_list|()
operator|->
name|d_func
argument_list|()
operator|->
name|state
operator|&&
name|tmp_painter
operator|->
name|d_func
argument_list|()
operator|->
name|state
argument_list|)
expr_stmt|;
operator|*
name|tmp_painter
operator|->
name|d_func
argument_list|()
operator|->
name|state
operator|=
operator|*
name|painter
argument_list|()
operator|->
name|d_func
argument_list|()
operator|->
name|state
expr_stmt|;
comment|// composition modes aren't supported on a QPrinter and yields a
comment|// warning, so ignore it for now
name|tmp_engine
operator|->
name|setDirty
argument_list|(
name|DirtyFlags
argument_list|(
name|AllDirty
operator|&
operator|~
name|DirtyCompositionMode
argument_list|)
argument_list|)
expr_stmt|;
name|tmp_engine
operator|->
name|syncState
argument_list|()
expr_stmt|;
operator|delete
name|d
operator|->
name|painter
expr_stmt|;
name|d
operator|->
name|painter
operator|=
name|tmp_painter
expr_stmt|;
name|d
operator|->
name|pages
operator|.
name|append
argument_list|(
name|page
argument_list|)
expr_stmt|;
name|d
operator|->
name|engine
operator|=
name|tmp_engine
expr_stmt|;
return|return
literal|true
return|;
block|}
end_function
begin_function
DECL|function|abort
name|bool
name|QPreviewPaintEngine
operator|::
name|abort
parameter_list|()
block|{
name|Q_D
argument_list|(
name|QPreviewPaintEngine
argument_list|)
expr_stmt|;
name|end
argument_list|()
expr_stmt|;
name|qDeleteAll
argument_list|(
name|d
operator|->
name|pages
argument_list|)
expr_stmt|;
name|d
operator|->
name|state
operator|=
name|QPrinter
operator|::
name|Aborted
expr_stmt|;
return|return
literal|true
return|;
block|}
end_function
begin_function
DECL|function|pages
name|QList
argument_list|<
specifier|const
name|QPicture
modifier|*
argument_list|>
name|QPreviewPaintEngine
operator|::
name|pages
parameter_list|()
block|{
name|Q_D
argument_list|(
name|QPreviewPaintEngine
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|pages
return|;
block|}
end_function
begin_function
DECL|function|setProxyEngines
name|void
name|QPreviewPaintEngine
operator|::
name|setProxyEngines
parameter_list|(
name|QPrintEngine
modifier|*
name|printEngine
parameter_list|,
name|QPaintEngine
modifier|*
name|paintEngine
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QPreviewPaintEngine
argument_list|)
expr_stmt|;
name|d
operator|->
name|proxy_print_engine
operator|=
name|printEngine
expr_stmt|;
name|d
operator|->
name|proxy_paint_engine
operator|=
name|paintEngine
expr_stmt|;
block|}
end_function
begin_function
DECL|function|setProperty
name|void
name|QPreviewPaintEngine
operator|::
name|setProperty
parameter_list|(
name|PrintEnginePropertyKey
name|key
parameter_list|,
specifier|const
name|QVariant
modifier|&
name|value
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QPreviewPaintEngine
argument_list|)
expr_stmt|;
name|d
operator|->
name|proxy_print_engine
operator|->
name|setProperty
argument_list|(
name|key
argument_list|,
name|value
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|property
name|QVariant
name|QPreviewPaintEngine
operator|::
name|property
parameter_list|(
name|PrintEnginePropertyKey
name|key
parameter_list|)
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QPreviewPaintEngine
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|proxy_print_engine
operator|->
name|property
argument_list|(
name|key
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|metric
name|int
name|QPreviewPaintEngine
operator|::
name|metric
parameter_list|(
name|QPaintDevice
operator|::
name|PaintDeviceMetric
name|id
parameter_list|)
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QPreviewPaintEngine
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|proxy_print_engine
operator|->
name|metric
argument_list|(
name|id
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|printerState
name|QPrinter
operator|::
name|PrinterState
name|QPreviewPaintEngine
operator|::
name|printerState
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QPreviewPaintEngine
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|state
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
end_unit
