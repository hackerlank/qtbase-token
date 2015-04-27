begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QPRINTERINFO_H
end_ifndef
begin_define
DECL|macro|QPRINTERINFO_H
define|#
directive|define
name|QPRINTERINFO_H
end_define
begin_include
include|#
directive|include
file|<QtPrintSupport/qprinter.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/QList>
end_include
begin_include
include|#
directive|include
file|<QtCore/QPair>
end_include
begin_include
include|#
directive|include
file|<QtGui/qpagesize.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
ifndef|#
directive|ifndef
name|QT_NO_PRINTER
DECL|variable|QPrinterInfoPrivate
name|class
name|QPrinterInfoPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QPrinterInfoPrivateDeleter
name|class
name|QPrinterInfoPrivateDeleter
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QDebug
name|class
name|QDebug
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_PRINTSUPPORT_EXPORT
name|QPrinterInfo
block|{
name|public
label|:
name|QPrinterInfo
argument_list|()
expr_stmt|;
name|QPrinterInfo
argument_list|(
specifier|const
name|QPrinterInfo
operator|&
name|other
argument_list|)
expr_stmt|;
name|explicit
name|QPrinterInfo
parameter_list|(
specifier|const
name|QPrinter
modifier|&
name|printer
parameter_list|)
function_decl|;
operator|~
name|QPrinterInfo
argument_list|()
expr_stmt|;
name|QPrinterInfo
modifier|&
name|operator
init|=
operator|(
specifier|const
name|QPrinterInfo
operator|&
name|other
operator|)
decl_stmt|;
name|QString
name|printerName
argument_list|()
specifier|const
expr_stmt|;
name|QString
name|description
argument_list|()
specifier|const
expr_stmt|;
name|QString
name|location
argument_list|()
specifier|const
expr_stmt|;
name|QString
name|makeAndModel
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|isNull
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|isDefault
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|isRemote
argument_list|()
specifier|const
expr_stmt|;
name|QPrinter
operator|::
name|PrinterState
name|state
argument_list|()
specifier|const
expr_stmt|;
name|QList
operator|<
name|QPageSize
operator|>
name|supportedPageSizes
argument_list|()
specifier|const
expr_stmt|;
name|QPageSize
name|defaultPageSize
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|supportsCustomPageSizes
argument_list|()
specifier|const
expr_stmt|;
name|QPageSize
name|minimumPhysicalPageSize
argument_list|()
specifier|const
expr_stmt|;
name|QPageSize
name|maximumPhysicalPageSize
argument_list|()
specifier|const
expr_stmt|;
if|#
directive|if
name|QT_DEPRECATED_SINCE
argument_list|(
literal|5
operator|,
literal|3
argument_list|)
name|QT_DEPRECATED
name|QList
operator|<
name|QPrinter
operator|::
name|PaperSize
operator|>
name|supportedPaperSizes
argument_list|()
specifier|const
expr_stmt|;
name|QT_DEPRECATED
name|QList
operator|<
name|QPair
operator|<
name|QString
operator|,
name|QSizeF
operator|>
expr|>
name|supportedSizesWithNames
argument_list|()
specifier|const
expr_stmt|;
endif|#
directive|endif
comment|// QT_DEPRECATED_SINCE(5,3)
name|QList
operator|<
name|int
operator|>
name|supportedResolutions
argument_list|()
specifier|const
expr_stmt|;
name|QPrinter
operator|::
name|DuplexMode
name|defaultDuplexMode
argument_list|()
specifier|const
expr_stmt|;
name|QList
operator|<
name|QPrinter
operator|::
name|DuplexMode
operator|>
name|supportedDuplexModes
argument_list|()
specifier|const
expr_stmt|;
specifier|static
name|QStringList
name|availablePrinterNames
parameter_list|()
function_decl|;
specifier|static
name|QList
operator|<
name|QPrinterInfo
operator|>
name|availablePrinters
argument_list|()
expr_stmt|;
specifier|static
name|QString
name|defaultPrinterName
parameter_list|()
function_decl|;
specifier|static
name|QPrinterInfo
name|defaultPrinter
parameter_list|()
function_decl|;
specifier|static
name|QPrinterInfo
name|printerInfo
parameter_list|(
specifier|const
name|QString
modifier|&
name|printerName
parameter_list|)
function_decl|;
name|private
label|:
name|explicit
name|QPrinterInfo
parameter_list|(
specifier|const
name|QString
modifier|&
name|name
parameter_list|)
function_decl|;
name|private
label|:
name|friend
name|class
name|QPlatformPrinterSupport
decl_stmt|;
ifndef|#
directive|ifndef
name|QT_NO_DEBUG_STREAM
name|friend
name|Q_PRINTSUPPORT_EXPORT
name|QDebug
name|operator
operator|<<
operator|(
name|QDebug
name|debug
operator|,
specifier|const
name|QPrinterInfo
operator|&
operator|)
expr_stmt|;
endif|#
directive|endif
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QPrinterInfo
argument_list|)
name|QScopedPointer
operator|<
name|QPrinterInfoPrivate
operator|,
name|QPrinterInfoPrivateDeleter
operator|>
name|d_ptr
expr_stmt|;
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
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QPRINTERINFO_H
end_comment
end_unit
