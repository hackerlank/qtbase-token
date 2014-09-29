begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2014 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia. For licensing terms and ** conditions see http://qt.digia.com/licensing. For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights. These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QPAINTENGINE_PREVIEW_P_H
end_ifndef
begin_define
DECL|macro|QPAINTENGINE_PREVIEW_P_H
define|#
directive|define
name|QPAINTENGINE_PREVIEW_P_H
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
comment|// of QPreviewPrinter and friends.  This header file may change from
end_comment
begin_comment
comment|// version to version without notice, or even be removed.
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
file|<QtPrintSupport/qprintengine.h>
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_PRINTPREVIEWWIDGET
end_ifndef
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QPreviewPaintEnginePrivate
name|class
name|QPreviewPaintEnginePrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QPaintEngine
name|class
name|QPreviewPaintEngine
range|:
name|public
name|QPaintEngine
decl_stmt|,
name|public
name|QPrintEngine
block|{
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QPreviewPaintEngine
argument_list|)
name|public
label|:
name|QPreviewPaintEngine
argument_list|()
expr_stmt|;
operator|~
name|QPreviewPaintEngine
argument_list|()
expr_stmt|;
name|bool
name|begin
parameter_list|(
name|QPaintDevice
modifier|*
name|dev
parameter_list|)
function_decl|;
name|bool
name|end
parameter_list|()
function_decl|;
name|void
name|updateState
parameter_list|(
specifier|const
name|QPaintEngineState
modifier|&
name|state
parameter_list|)
function_decl|;
name|void
name|drawPath
parameter_list|(
specifier|const
name|QPainterPath
modifier|&
name|path
parameter_list|)
function_decl|;
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
function_decl|;
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
name|pm
parameter_list|,
specifier|const
name|QPointF
modifier|&
name|p
parameter_list|)
function_decl|;
name|QList
operator|<
specifier|const
name|QPicture
operator|*
operator|>
name|pages
argument_list|()
expr_stmt|;
name|QPaintEngine
operator|::
name|Type
name|type
argument_list|()
specifier|const
block|{
return|return
name|Picture
return|;
block|}
name|void
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
function_decl|;
name|void
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
function_decl|;
name|QVariant
name|property
argument_list|(
name|PrintEnginePropertyKey
name|key
argument_list|)
decl|const
decl_stmt|;
name|bool
name|newPage
parameter_list|()
function_decl|;
name|bool
name|abort
parameter_list|()
function_decl|;
name|int
name|metric
argument_list|(
name|QPaintDevice
operator|::
name|PaintDeviceMetric
argument_list|)
decl|const
decl_stmt|;
name|QPrinter
operator|::
name|PrinterState
name|printerState
argument_list|()
specifier|const
expr_stmt|;
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
begin_comment
comment|// QT_NO_PRINTPREVIEWWIDGET
end_comment
begin_endif
endif|#
directive|endif
end_endif
end_unit
