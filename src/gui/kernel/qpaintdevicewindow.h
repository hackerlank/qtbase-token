begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2014 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia. For licensing terms and ** conditions see http://qt.digia.com/licensing. For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights. These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QPAINTDEVICEWINDOW_H
end_ifndef
begin_define
DECL|macro|QPAINTDEVICEWINDOW_H
define|#
directive|define
name|QPAINTDEVICEWINDOW_H
end_define
begin_include
include|#
directive|include
file|<QtGui/QWindow>
end_include
begin_include
include|#
directive|include
file|<QtGui/QPaintDevice>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QPaintDeviceWindowPrivate
name|class
name|QPaintDeviceWindowPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QPaintEvent
name|class
name|QPaintEvent
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QWindow
name|class
name|Q_GUI_EXPORT
name|QPaintDeviceWindow
range|:
name|public
name|QWindow
decl_stmt|,
name|public
name|QPaintDevice
block|{
name|Q_OBJECT
name|Q_DECLARE_PRIVATE
argument_list|(
name|QPaintDeviceWindow
argument_list|)
name|public
range|:
name|void
name|update
argument_list|(
specifier|const
name|QRect
operator|&
name|rect
argument_list|)
decl_stmt|;
name|void
name|update
parameter_list|(
specifier|const
name|QRegion
modifier|&
name|region
parameter_list|)
function_decl|;
name|using
name|QWindow
operator|::
name|width
expr_stmt|;
name|using
name|QWindow
operator|::
name|height
expr_stmt|;
name|using
name|QWindow
operator|::
name|devicePixelRatio
expr_stmt|;
name|public
name|Q_SLOTS
range|:
name|void
name|update
argument_list|()
decl_stmt|;
name|protected
label|:
name|virtual
name|void
name|paintEvent
parameter_list|(
name|QPaintEvent
modifier|*
name|event
parameter_list|)
function_decl|;
name|int
name|metric
argument_list|(
name|PaintDeviceMetric
name|metric
argument_list|)
decl|const
name|Q_DECL_OVERRIDE
decl_stmt|;
name|void
name|exposeEvent
argument_list|(
name|QExposeEvent
operator|*
argument_list|)
name|Q_DECL_OVERRIDE
decl_stmt|;
name|bool
name|event
argument_list|(
name|QEvent
operator|*
name|event
argument_list|)
name|Q_DECL_OVERRIDE
decl_stmt|;
name|QPaintDeviceWindow
argument_list|(
name|QPaintDeviceWindowPrivate
operator|&
name|dd
argument_list|,
name|QWindow
operator|*
name|parent
argument_list|)
expr_stmt|;
name|private
label|:
name|QPaintEngine
operator|*
name|paintEngine
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
expr_stmt|;
name|Q_DISABLE_COPY
argument_list|(
argument|QPaintDeviceWindow
argument_list|)
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
