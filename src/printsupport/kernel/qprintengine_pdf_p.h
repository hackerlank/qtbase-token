begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
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
DECL|variable|QPdfPrintEngine
name|class
name|QPdfPrintEngine
decl_stmt|;
end_decl_stmt
begin_define
DECL|macro|PPK_CupsOptions
define|#
directive|define
name|PPK_CupsOptions
value|QPrintEngine::PrintEnginePropertyKey(0xfe00)
end_define
begin_define
DECL|macro|PPK_CupsPageRect
define|#
directive|define
name|PPK_CupsPageRect
value|QPrintEngine::PrintEnginePropertyKey(0xfe01)
end_define
begin_define
DECL|macro|PPK_CupsPaperRect
define|#
directive|define
name|PPK_CupsPaperRect
value|QPrintEngine::PrintEnginePropertyKey(0xfe02)
end_define
begin_define
DECL|macro|PPK_CupsStringPageSize
define|#
directive|define
name|PPK_CupsStringPageSize
value|QPrintEngine::PrintEnginePropertyKey(0xfe03)
end_define
begin_decl_stmt
name|namespace
name|QPdf
block|{
struct|struct
name|PaperSize
block|{
name|int
name|width
decl_stmt|,
name|height
decl_stmt|;
comment|// in postscript points
block|}
struct|;
name|Q_PRINTSUPPORT_EXPORT
name|PaperSize
name|paperSize
argument_list|(
name|QPrinter
operator|::
name|PaperSize
name|paperSize
argument_list|)
decl_stmt|;
name|Q_PRINTSUPPORT_EXPORT
specifier|const
name|char
modifier|*
name|paperSizeToString
argument_list|(
name|QPrinter
operator|::
name|PaperSize
name|paperSize
argument_list|)
decl_stmt|;
block|}
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
comment|// end reimplementations QPrintEngine
name|QPrinter
operator|::
name|PrinterState
name|state
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
name|bool
name|openPrintDevice
argument_list|()
block|;
name|void
name|closePrintDevice
argument_list|()
block|;
name|void
name|updatePaperSize
argument_list|()
block|;
name|private
operator|:
name|Q_DISABLE_COPY
argument_list|(
argument|QPdfPrintEnginePrivate
argument_list|)
name|QString
name|printerName
block|;
name|QString
name|printProgram
block|;
name|QString
name|selectionOption
block|;
name|QStringList
name|cupsOptions
block|;
name|QString
name|cupsStringPageSize
block|;
name|QPrinter
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
name|QPrinter
operator|::
name|PaperSize
name|printerPaperSize
block|;
name|QRect
name|cupsPaperRect
block|;
name|QRect
name|cupsPageRect
block|;
name|QSizeF
name|customPaperSize
block|;
comment|// in postscript points
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
