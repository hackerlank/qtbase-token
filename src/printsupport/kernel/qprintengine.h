begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QPRINTENGINE_H
end_ifndef
begin_define
DECL|macro|QPRINTENGINE_H
define|#
directive|define
name|QPRINTENGINE_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qvariant.h>
end_include
begin_include
include|#
directive|include
file|<QtPrintSupport/qprinter.h>
end_include
begin_decl_stmt
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
ifndef|#
directive|ifndef
name|QT_NO_PRINTER
name|class
name|Q_PRINTSUPPORT_EXPORT
name|QPrintEngine
block|{
name|public
label|:
name|virtual
operator|~
name|QPrintEngine
argument_list|()
block|{}
expr|enum
name|PrintEnginePropertyKey
block|{
name|PPK_CollateCopies
block|,
name|PPK_ColorMode
block|,
name|PPK_Creator
block|,
name|PPK_DocumentName
block|,
name|PPK_FullPage
block|,
name|PPK_NumberOfCopies
block|,
name|PPK_Orientation
block|,
name|PPK_OutputFileName
block|,
name|PPK_PageOrder
block|,
name|PPK_PageRect
block|,
name|PPK_PageSize
block|,
name|PPK_PaperRect
block|,
name|PPK_PaperSource
block|,
name|PPK_PrinterName
block|,
name|PPK_PrinterProgram
block|,
name|PPK_Resolution
block|,
name|PPK_SelectionOption
block|,
name|PPK_SupportedResolutions
block|,
name|PPK_WindowsPageSize
block|,
name|PPK_FontEmbedding
block|,
name|PPK_SuppressSystemPrintStatus
block|,
name|PPK_Duplex
block|,
name|PPK_PaperSources
block|,
name|PPK_CustomPaperSize
block|,
name|PPK_PageMargins
block|,
name|PPK_CopyCount
block|,
name|PPK_SupportsMultipleCopies
block|,
name|PPK_PaperSize
operator|=
name|PPK_PageSize
block|,
name|PPK_CustomBase
operator|=
literal|0xff00
block|}
expr_stmt|;
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
init|=
literal|0
function_decl|;
name|virtual
name|QVariant
name|property
argument_list|(
name|PrintEnginePropertyKey
name|key
argument_list|)
decl|const
init|=
literal|0
decl_stmt|;
name|virtual
name|bool
name|newPage
parameter_list|()
init|=
literal|0
function_decl|;
name|virtual
name|bool
name|abort
parameter_list|()
init|=
literal|0
function_decl|;
name|virtual
name|int
name|metric
argument_list|(
name|QPaintDevice
operator|::
name|PaintDeviceMetric
argument_list|)
decl|const
init|=
literal|0
decl_stmt|;
name|virtual
name|QPrinter
operator|::
name|PrinterState
name|printerState
argument_list|()
specifier|const
operator|=
literal|0
expr_stmt|;
ifdef|#
directive|ifdef
name|Q_WS_WIN
name|virtual
name|HDC
name|getPrinterDC
argument_list|()
specifier|const
block|{
return|return
literal|0
return|;
block|}
name|virtual
name|void
name|releasePrinterDC
argument_list|(
name|HDC
argument_list|)
decl|const
block|{ }
endif|#
directive|endif
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_PRINTER
end_comment
begin_expr_stmt
name|QT_END_NAMESPACE
name|QT_END_HEADER
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QPRINTENGINE_H
end_comment
end_unit
