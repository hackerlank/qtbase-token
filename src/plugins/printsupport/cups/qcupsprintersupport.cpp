begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2014 Digia Plc and/or its subsidiary(-ies). ** Copyright (C) 2014 John Layt<jlayt@kde.org> ** Contact: http://www.qt-project.org/legal ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia. For licensing terms and ** conditions see http://qt.digia.com/licensing. For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights. These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qcupsprintersupport_p.h"
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_PRINTER
end_ifndef
begin_include
include|#
directive|include
file|"qcupsprintengine_p.h"
end_include
begin_include
include|#
directive|include
file|"qppdprintdevice.h"
end_include
begin_include
include|#
directive|include
file|<private/qprinterinfo_p.h>
end_include
begin_include
include|#
directive|include
file|<private/qprintdevice_p.h>
end_include
begin_include
include|#
directive|include
file|<QtPrintSupport/QPrinterInfo>
end_include
begin_include
include|#
directive|include
file|<cups/ppd.h>
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_LINUXBASE
end_ifndef
begin_comment
comment|// LSB merges everything into cups.h
end_comment
begin_include
include|#
directive|include
file|<cups/language.h>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_constructor
DECL|function|QCupsPrinterSupport
name|QCupsPrinterSupport
operator|::
name|QCupsPrinterSupport
parameter_list|()
member_init_list|:
name|QPlatformPrinterSupport
argument_list|()
block|{ }
end_constructor
begin_destructor
DECL|function|~QCupsPrinterSupport
name|QCupsPrinterSupport
operator|::
name|~
name|QCupsPrinterSupport
parameter_list|()
block|{ }
end_destructor
begin_function
DECL|function|createNativePrintEngine
name|QPrintEngine
modifier|*
name|QCupsPrinterSupport
operator|::
name|createNativePrintEngine
parameter_list|(
name|QPrinter
operator|::
name|PrinterMode
name|printerMode
parameter_list|)
block|{
return|return
operator|new
name|QCupsPrintEngine
argument_list|(
name|printerMode
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|createPaintEngine
name|QPaintEngine
modifier|*
name|QCupsPrinterSupport
operator|::
name|createPaintEngine
parameter_list|(
name|QPrintEngine
modifier|*
name|engine
parameter_list|,
name|QPrinter
operator|::
name|PrinterMode
name|printerMode
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
argument|printerMode
argument_list|)
return|return
cast|static_cast
argument_list|<
name|QCupsPrintEngine
operator|*
argument_list|>
argument_list|(
name|engine
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|createPrintDevice
name|QPrintDevice
name|QCupsPrinterSupport
operator|::
name|createPrintDevice
parameter_list|(
specifier|const
name|QString
modifier|&
name|id
parameter_list|)
block|{
return|return
name|QPlatformPrinterSupport
operator|::
name|createPrintDevice
argument_list|(
operator|new
name|QPpdPrintDevice
argument_list|(
name|id
argument_list|)
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|availablePrintDeviceIds
name|QStringList
name|QCupsPrinterSupport
operator|::
name|availablePrintDeviceIds
parameter_list|()
specifier|const
block|{
name|QStringList
name|list
decl_stmt|;
name|cups_dest_t
modifier|*
name|dests
decl_stmt|;
name|int
name|count
init|=
name|cupsGetDests
argument_list|(
operator|&
name|dests
argument_list|)
decl_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|count
condition|;
operator|++
name|i
control|)
block|{
name|QString
name|printerId
init|=
name|QString
operator|::
name|fromLocal8Bit
argument_list|(
name|dests
index|[
name|i
index|]
operator|.
name|name
argument_list|)
decl_stmt|;
if|if
condition|(
name|dests
index|[
name|i
index|]
operator|.
name|instance
condition|)
name|printerId
operator|+=
name|QLatin1Char
argument_list|(
literal|'/'
argument_list|)
operator|+
name|QString
operator|::
name|fromLocal8Bit
argument_list|(
name|dests
index|[
name|i
index|]
operator|.
name|instance
argument_list|)
expr_stmt|;
name|list
operator|.
name|append
argument_list|(
name|printerId
argument_list|)
expr_stmt|;
block|}
name|cupsFreeDests
argument_list|(
name|count
argument_list|,
name|dests
argument_list|)
expr_stmt|;
return|return
name|list
return|;
block|}
end_function
begin_function
DECL|function|defaultPrintDeviceId
name|QString
name|QCupsPrinterSupport
operator|::
name|defaultPrintDeviceId
parameter_list|()
specifier|const
block|{
name|QString
name|printerId
decl_stmt|;
name|cups_dest_t
modifier|*
name|dests
decl_stmt|;
name|int
name|count
init|=
name|cupsGetDests
argument_list|(
operator|&
name|dests
argument_list|)
decl_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|count
condition|;
operator|++
name|i
control|)
block|{
if|if
condition|(
name|dests
index|[
name|i
index|]
operator|.
name|is_default
condition|)
block|{
name|printerId
operator|=
name|QString
operator|::
name|fromLocal8Bit
argument_list|(
name|dests
index|[
name|i
index|]
operator|.
name|name
argument_list|)
expr_stmt|;
if|if
condition|(
name|dests
index|[
name|i
index|]
operator|.
name|instance
condition|)
block|{
name|printerId
operator|+=
name|QLatin1Char
argument_list|(
literal|'/'
argument_list|)
operator|+
name|QString
operator|::
name|fromLocal8Bit
argument_list|(
name|dests
index|[
name|i
index|]
operator|.
name|instance
argument_list|)
expr_stmt|;
break|break;
block|}
block|}
block|}
name|cupsFreeDests
argument_list|(
name|count
argument_list|,
name|dests
argument_list|)
expr_stmt|;
return|return
name|printerId
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
begin_comment
comment|// QT_NO_PRINTER
end_comment
end_unit
