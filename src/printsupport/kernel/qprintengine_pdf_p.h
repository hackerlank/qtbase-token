begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2014 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia. For licensing terms and ** conditions see http://qt.digia.com/licensing. For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights. These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QPRINTENGINE_PDF_P_H
end_ifndef
begin_define
DECL|macro|QPRINTENGINE_PDF_P_H
define|#
directive|define
name|QPRINTENGINE_PDF_P_H
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
file|"QtPrintSupport/qprintengine.h"
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_PRINTER
end_ifndef
begin_include
include|#
directive|include
file|"QtCore/qmap.h"
end_include
begin_include
include|#
directive|include
file|"QtGui/qmatrix.h"
end_include
begin_include
include|#
directive|include
file|"QtCore/qstring.h"
end_include
begin_include
include|#
directive|include
file|"QtCore/qvector.h"
end_include
begin_include
include|#
directive|include
file|"QtGui/qpaintengine.h"
end_include
begin_include
include|#
directive|include
file|"QtGui/qpainterpath.h"
end_include
begin_include
include|#
directive|include
file|"QtCore/qdatastream.h"
end_include
begin_include
include|#
directive|include
file|"private/qfontengine_p.h"
end_include
begin_include
include|#
directive|include
file|"private/qpdf_p.h"
end_include
begin_include
include|#
directive|include
file|"private/qpaintengine_p.h"
end_include
begin_include
include|#
directive|include
file|"qprintengine.h"
end_include
begin_include
include|#
directive|include
file|"qprint_p.h"
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QImage
name|class
name|QImage
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QDataStream
name|class
name|QDataStream
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QPen
name|class
name|QPen
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QPointF
name|class
name|QPointF
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QRegion
name|class
name|QRegion
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QFile
name|class
name|QFile
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QPdfPrintEnginePrivate
name|class
name|QPdfPrintEnginePrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QPdfEngine
name|class
name|Q_PRINTSUPPORT_EXPORT
name|QPdfPrintEngine
range|:
name|public
name|QPdfEngine
decl_stmt|,
name|public
name|QPrintEngine
block|{
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QPdfPrintEngine
argument_list|)
name|public
label|:
name|QPdfPrintEngine
argument_list|(
argument|QPrinter::PrinterMode m
argument_list|)
empty_stmt|;
name|virtual
operator|~
name|QPdfPrintEngine
argument_list|()
expr_stmt|;
comment|// reimplementations QPaintEngine
name|bool
name|begin
parameter_list|(
name|QPaintDevice
modifier|*
name|pdev
parameter_list|)
function_decl|;
name|bool
name|end
parameter_list|()
function_decl|;
comment|// end reimplementations QPaintEngine
comment|// reimplementations QPrintEngine
name|bool
name|abort
parameter_list|()
block|{
return|return
name|false
return|;
block|}
name|QPrinter
operator|::
name|PrinterState
name|printerState
argument_list|()
specifier|const
block|{
return|return
name|state
return|;
block|}
name|bool
name|newPage
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
name|virtual
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
name|virtual
name|QVariant
name|property
argument_list|(
name|PrintEnginePropertyKey
name|key
argument_list|)
decl|const
decl_stmt|;
comment|// end reimplementations QPrintEngine
name|QPrinter
operator|::
name|PrinterState
name|state
expr_stmt|;
name|protected
label|:
name|QPdfPrintEngine
argument_list|(
name|QPdfPrintEnginePrivate
operator|&
name|p
argument_list|)
expr_stmt|;
name|private
label|:
name|Q_DISABLE_COPY
argument_list|(
argument|QPdfPrintEngine
argument_list|)
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_decl_stmt
name|class
name|Q_PRINTSUPPORT_EXPORT
name|QPdfPrintEnginePrivate
range|:
name|public
name|QPdfEnginePrivate
block|{
name|Q_DECLARE_PUBLIC
argument_list|(
argument|QPdfPrintEngine
argument_list|)
name|public
operator|:
name|QPdfPrintEnginePrivate
argument_list|(
argument|QPrinter::PrinterMode m
argument_list|)
block|;
operator|~
name|QPdfPrintEnginePrivate
argument_list|()
block|;
name|virtual
name|bool
name|openPrintDevice
argument_list|()
block|;
name|virtual
name|void
name|closePrintDevice
argument_list|()
block|;
name|private
operator|:
name|Q_DISABLE_COPY
argument_list|(
argument|QPdfPrintEnginePrivate
argument_list|)
name|friend
name|class
name|QCupsPrintEngine
block|;
name|friend
name|class
name|QCupsPrintEnginePrivate
block|;
name|QString
name|printerName
block|;
name|QString
name|printProgram
block|;
name|QString
name|selectionOption
block|;
name|QPrint
operator|::
name|DuplexMode
name|duplex
block|;
name|bool
name|collate
block|;
name|int
name|copies
block|;
name|QPrinter
operator|::
name|PageOrder
name|pageOrder
block|;
name|QPrinter
operator|::
name|PaperSource
name|paperSource
block|;
name|int
name|fd
block|; }
decl_stmt|;
end_decl_stmt
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_PRINTER
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QPRINTENGINE_PDF_P_H
end_comment
end_unit
