begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2014 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia. For licensing terms and ** conditions see http://qt.digia.com/licensing. For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights. These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QPLATFORMPRINTERSUPPORT_H
end_ifndef
begin_define
DECL|macro|QPLATFORMPRINTERSUPPORT_H
define|#
directive|define
name|QPLATFORMPRINTERSUPPORT_H
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
comment|// This file is part of the QPA API and is not meant to be used
end_comment
begin_comment
comment|// in applications. Usage of this API may make your code
end_comment
begin_comment
comment|// source and binary incompatible with future versions of Qt.
end_comment
begin_comment
comment|//
end_comment
begin_include
include|#
directive|include
file|<QtPrintSupport/qprinter.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qstringlist.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qlist.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qhash.h>
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_PRINTER
end_ifndef
begin_typedef
DECL|typedef|QString
DECL|typedef|PrinterOptions
typedef|typedef
name|QHash
operator|<
name|QString
operator|,
name|QString
operator|>
name|PrinterOptions
expr_stmt|;
end_typedef
begin_decl_stmt
DECL|variable|QPageSize
name|class
name|QPageSize
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QPlatformPrintDevice
name|class
name|QPlatformPrintDevice
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QPrintDevice
name|class
name|QPrintDevice
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QPrintEngine
name|class
name|QPrintEngine
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_PRINTSUPPORT_EXPORT
name|QPlatformPrinterSupport
block|{
name|public
label|:
name|QPlatformPrinterSupport
argument_list|()
expr_stmt|;
name|virtual
operator|~
name|QPlatformPrinterSupport
argument_list|()
expr_stmt|;
name|virtual
name|QPrintEngine
modifier|*
name|createNativePrintEngine
argument_list|(
name|QPrinter
operator|::
name|PrinterMode
name|printerMode
argument_list|)
decl_stmt|;
name|virtual
name|QPaintEngine
modifier|*
name|createPaintEngine
argument_list|(
name|QPrintEngine
operator|*
argument_list|,
name|QPrinter
operator|::
name|PrinterMode
name|printerMode
argument_list|)
decl_stmt|;
name|virtual
name|QPrintDevice
name|createPrintDevice
parameter_list|(
specifier|const
name|QString
modifier|&
name|id
parameter_list|)
function_decl|;
name|virtual
name|QPrintDevice
name|createDefaultPrintDevice
parameter_list|()
function_decl|;
name|virtual
name|QStringList
name|availablePrintDeviceIds
argument_list|()
specifier|const
expr_stmt|;
name|virtual
name|QString
name|defaultPrintDeviceId
argument_list|()
specifier|const
expr_stmt|;
name|protected
label|:
specifier|static
name|QPrintDevice
name|createPrintDevice
parameter_list|(
name|QPlatformPrintDevice
modifier|*
name|device
parameter_list|)
function_decl|;
specifier|static
name|QPageSize
name|createPageSize
parameter_list|(
specifier|const
name|QString
modifier|&
name|id
parameter_list|,
name|QSize
name|size
parameter_list|,
specifier|const
name|QString
modifier|&
name|localizedName
parameter_list|)
function_decl|;
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
comment|// QPLATFORMPRINTERSUPPORT_H
end_comment
end_unit
