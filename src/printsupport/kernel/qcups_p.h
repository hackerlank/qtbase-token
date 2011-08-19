begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QCUPS_P_H
end_ifndef
begin_define
DECL|macro|QCUPS_P_H
define|#
directive|define
name|QCUPS_P_H
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
file|"QtCore/qstring.h"
end_include
begin_include
include|#
directive|include
file|"QtCore/qstringlist.h"
end_include
begin_include
include|#
directive|include
file|"QtCore/qpair.h"
end_include
begin_include
include|#
directive|include
file|"QtPrintSupport/qprinter.h"
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_CUPS
end_ifndef
begin_include
include|#
directive|include
file|<QtCore/qlibrary.h>
end_include
begin_include
include|#
directive|include
file|<cups/cups.h>
end_include
begin_include
include|#
directive|include
file|<cups/ppd.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
name|Q_DECLARE_TYPEINFO
argument_list|(
name|cups_option_t
argument_list|,
name|Q_MOVABLE_TYPE
operator||
name|Q_PRIMITIVE_TYPE
argument_list|)
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_PRINTSUPPORT_EXPORT
name|QCUPSSupport
block|{
name|public
label|:
struct|struct
name|Printer
block|{
name|Printer
argument_list|(
specifier|const
name|QString
operator|&
name|name
operator|=
name|QString
argument_list|()
argument_list|)
expr_stmt|;
name|QString
name|name
decl_stmt|;
name|bool
name|isDefault
decl_stmt|;
name|int
name|cupsPrinterIndex
decl_stmt|;
block|}
struct|;
name|QCUPSSupport
argument_list|()
expr_stmt|;
operator|~
name|QCUPSSupport
argument_list|()
expr_stmt|;
specifier|static
name|bool
name|isAvailable
parameter_list|()
function_decl|;
specifier|static
name|int
name|cupsVersion
parameter_list|()
block|{
return|return
name|isAvailable
argument_list|()
condition|?
name|CUPS_VERSION_MAJOR
operator|*
literal|10000
operator|+
name|CUPS_VERSION_MINOR
operator|*
literal|100
operator|+
name|CUPS_VERSION_PATCH
else|:
literal|0
return|;
block|}
name|int
name|availablePrintersCount
argument_list|()
specifier|const
expr_stmt|;
specifier|const
name|cups_dest_t
operator|*
name|availablePrinters
argument_list|()
specifier|const
expr_stmt|;
name|int
name|currentPrinterIndex
argument_list|()
specifier|const
expr_stmt|;
specifier|const
name|ppd_file_t
modifier|*
name|setCurrentPrinter
parameter_list|(
name|int
name|index
parameter_list|)
function_decl|;
specifier|const
name|ppd_file_t
operator|*
name|currentPPD
argument_list|()
specifier|const
expr_stmt|;
specifier|const
name|ppd_option_t
modifier|*
name|ppdOption
argument_list|(
specifier|const
name|char
operator|*
name|key
argument_list|)
decl|const
decl_stmt|;
specifier|const
name|cups_option_t
modifier|*
name|printerOption
argument_list|(
specifier|const
name|QString
operator|&
name|key
argument_list|)
decl|const
decl_stmt|;
specifier|const
name|ppd_option_t
operator|*
name|pageSizes
argument_list|()
specifier|const
expr_stmt|;
name|int
name|markOption
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|,
specifier|const
name|char
modifier|*
name|value
parameter_list|)
function_decl|;
name|void
name|saveOptions
argument_list|(
name|QList
operator|<
specifier|const
name|ppd_option_t
operator|*
operator|>
name|options
argument_list|,
name|QList
operator|<
specifier|const
name|char
operator|*
operator|>
name|markedOptions
argument_list|)
decl_stmt|;
name|QRect
name|paperRect
argument_list|(
specifier|const
name|char
operator|*
name|choice
argument_list|)
decl|const
decl_stmt|;
name|QRect
name|pageRect
argument_list|(
specifier|const
name|char
operator|*
name|choice
argument_list|)
decl|const
decl_stmt|;
name|QStringList
name|options
argument_list|()
specifier|const
expr_stmt|;
specifier|static
name|bool
name|printerHasPPD
parameter_list|(
specifier|const
name|char
modifier|*
name|printerName
parameter_list|)
function_decl|;
name|QString
name|unicodeString
parameter_list|(
specifier|const
name|char
modifier|*
name|s
parameter_list|)
function_decl|;
name|QPair
operator|<
name|int
operator|,
name|QString
operator|>
name|tempFd
argument_list|()
expr_stmt|;
name|int
name|printFile
parameter_list|(
specifier|const
name|char
modifier|*
name|printerName
parameter_list|,
specifier|const
name|char
modifier|*
name|filename
parameter_list|,
specifier|const
name|char
modifier|*
name|title
parameter_list|,
name|int
name|num_options
parameter_list|,
name|cups_option_t
modifier|*
name|options
parameter_list|)
function_decl|;
specifier|static
name|QList
operator|<
name|Printer
operator|>
name|availableUnixPrinters
argument_list|()
expr_stmt|;
specifier|static
name|QList
operator|<
name|QPrinter
operator|::
name|PaperSize
operator|>
name|getCupsPrinterPaperSizes
argument_list|(
argument|int cupsPrinterIndex
argument_list|)
expr_stmt|;
name|private
label|:
name|void
name|collectMarkedOptions
argument_list|(
name|QStringList
operator|&
name|list
argument_list|,
specifier|const
name|ppd_group_t
operator|*
name|group
operator|=
literal|0
argument_list|)
decl|const
decl_stmt|;
name|void
name|collectMarkedOptionsHelper
argument_list|(
name|QStringList
operator|&
name|list
argument_list|,
specifier|const
name|ppd_group_t
operator|*
name|group
argument_list|)
decl|const
decl_stmt|;
name|int
name|prnCount
decl_stmt|;
name|cups_dest_t
modifier|*
name|printers
decl_stmt|;
specifier|const
name|ppd_option_t
modifier|*
name|page_sizes
decl_stmt|;
name|int
name|currPrinterIndex
decl_stmt|;
name|ppd_file_t
modifier|*
name|currPPD
decl_stmt|;
ifndef|#
directive|ifndef
name|QT_NO_TEXTCODEC
name|QTextCodec
modifier|*
name|codec
decl_stmt|;
endif|#
directive|endif
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
comment|// QT_NO_CUPS
end_comment
begin_endif
endif|#
directive|endif
end_endif
end_unit
