begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QPDFWRITER_H
end_ifndef
begin_define
DECL|macro|QPDFWRITER_H
define|#
directive|define
name|QPDFWRITER_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qglobal.h>
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_PDF
end_ifndef
begin_include
include|#
directive|include
file|<QtCore/qobject.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/qpagedpaintdevice.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/qpagelayout.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QIODevice
name|class
name|QIODevice
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QPdfWriterPrivate
name|class
name|QPdfWriterPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QObject
name|class
name|Q_GUI_EXPORT
name|QPdfWriter
range|:
name|public
name|QObject
decl_stmt|,
name|public
name|QPagedPaintDevice
block|{
name|Q_OBJECT
name|public
range|:
name|explicit
name|QPdfWriter
argument_list|(
specifier|const
name|QString
operator|&
name|filename
argument_list|)
decl_stmt|;
name|explicit
name|QPdfWriter
parameter_list|(
name|QIODevice
modifier|*
name|device
parameter_list|)
function_decl|;
operator|~
name|QPdfWriter
argument_list|()
expr_stmt|;
name|QString
name|title
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setTitle
parameter_list|(
specifier|const
name|QString
modifier|&
name|title
parameter_list|)
function_decl|;
name|QString
name|creator
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setCreator
parameter_list|(
specifier|const
name|QString
modifier|&
name|creator
parameter_list|)
function_decl|;
name|bool
name|newPage
parameter_list|()
function_decl|;
name|void
name|setResolution
parameter_list|(
name|int
name|resolution
parameter_list|)
function_decl|;
name|int
name|resolution
argument_list|()
specifier|const
expr_stmt|;
ifdef|#
directive|ifdef
name|Q_QDOC
name|bool
name|setPageLayout
parameter_list|(
specifier|const
name|QPageLayout
modifier|&
name|pageLayout
parameter_list|)
function_decl|;
name|bool
name|setPageSize
parameter_list|(
specifier|const
name|QPageSize
modifier|&
name|pageSize
parameter_list|)
function_decl|;
name|bool
name|setPageOrientation
argument_list|(
name|QPageLayout
operator|::
name|Orientation
name|orientation
argument_list|)
decl_stmt|;
name|bool
name|setPageMargins
parameter_list|(
specifier|const
name|QMarginsF
modifier|&
name|margins
parameter_list|)
function_decl|;
name|bool
name|setPageMargins
argument_list|(
specifier|const
name|QMarginsF
operator|&
name|margins
argument_list|,
name|QPageLayout
operator|::
name|Unit
name|units
argument_list|)
decl_stmt|;
name|QPageLayout
name|pageLayout
argument_list|()
specifier|const
expr_stmt|;
else|#
directive|else
name|using
name|QPagedPaintDevice
operator|::
name|setPageSize
expr_stmt|;
endif|#
directive|endif
name|void
name|setPageSize
parameter_list|(
name|PageSize
name|size
parameter_list|)
function_decl|;
name|void
name|setPageSizeMM
parameter_list|(
specifier|const
name|QSizeF
modifier|&
name|size
parameter_list|)
function_decl|;
name|void
name|setMargins
parameter_list|(
specifier|const
name|Margins
modifier|&
name|m
parameter_list|)
function_decl|;
name|protected
label|:
name|QPaintEngine
operator|*
name|paintEngine
argument_list|()
specifier|const
expr_stmt|;
name|int
name|metric
argument_list|(
name|PaintDeviceMetric
name|id
argument_list|)
decl|const
decl_stmt|;
name|private
label|:
name|Q_DISABLE_COPY
argument_list|(
argument|QPdfWriter
argument_list|)
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QPdfWriter
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
begin_comment
comment|// QT_NO_PDF
end_comment
begin_endif
endif|#
directive|endif
end_endif
end_unit
