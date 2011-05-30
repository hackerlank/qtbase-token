begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<qwindowsprintersupport.h>
end_include
begin_include
include|#
directive|include
file|<qprintengine_win_p.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/QPrinterInfo>
end_include
begin_include
include|#
directive|include
file|<QtCore/QStringList>
end_include
begin_include
include|#
directive|include
file|<QtCore/qt_windows.h>
end_include
begin_function
name|QT_BEGIN_NAMESPACE
DECL|function|createNativePrintEngine
name|QPrintEngine
modifier|*
name|QWindowsPrinterSupport
operator|::
name|createNativePrintEngine
parameter_list|(
name|QPrinter
operator|::
name|PrinterMode
name|mode
parameter_list|)
block|{
return|return
operator|new
name|QWin32PrintEngine
argument_list|(
name|mode
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|createPaintEngine
name|QPaintEngine
modifier|*
name|QWindowsPrinterSupport
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
parameter_list|)
block|{
return|return
cast|static_cast
argument_list|<
name|QWin32PrintEngine
operator|*
argument_list|>
argument_list|(
name|engine
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|supportedPaperSizes
name|QList
argument_list|<
name|QPrinter
operator|::
name|PaperSize
argument_list|>
name|QWindowsPrinterSupport
operator|::
name|supportedPaperSizes
parameter_list|(
specifier|const
name|QPrinterInfo
modifier|&
name|printerInfo
parameter_list|)
specifier|const
block|{
name|QList
argument_list|<
name|QPrinter
operator|::
name|PaperSize
argument_list|>
name|paperSizes
decl_stmt|;
specifier|const
name|QString
name|printerName
init|=
name|printerInfo
operator|.
name|printerName
argument_list|()
decl_stmt|;
specifier|const
name|wchar_t
modifier|*
name|nameUtf16
init|=
cast|reinterpret_cast
argument_list|<
specifier|const
name|wchar_t
operator|*
argument_list|>
argument_list|(
name|printerName
operator|.
name|utf16
argument_list|()
argument_list|)
decl_stmt|;
name|DWORD
name|size
init|=
name|DeviceCapabilities
argument_list|(
name|nameUtf16
argument_list|,
name|NULL
argument_list|,
name|DC_PAPERS
argument_list|,
name|NULL
argument_list|,
name|NULL
argument_list|)
decl_stmt|;
if|if
condition|(
operator|(
name|int
operator|)
name|size
operator|!=
operator|-
literal|1
condition|)
block|{
name|wchar_t
modifier|*
name|papers
init|=
operator|new
name|wchar_t
index|[
name|size
index|]
decl_stmt|;
name|size
operator|=
name|DeviceCapabilities
argument_list|(
name|nameUtf16
argument_list|,
name|NULL
argument_list|,
name|DC_PAPERS
argument_list|,
name|papers
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
for|for
control|(
name|int
name|c
init|=
literal|0
init|;
name|c
operator|<
operator|(
name|int
operator|)
name|size
condition|;
operator|++
name|c
control|)
name|paperSizes
operator|.
name|append
argument_list|(
name|mapDevmodePaperSize
argument_list|(
name|papers
index|[
name|c
index|]
argument_list|)
argument_list|)
expr_stmt|;
operator|delete
index|[]
name|papers
expr_stmt|;
block|}
return|return
name|paperSizes
return|;
block|}
end_function
begin_function
DECL|function|availablePrinters
name|QList
argument_list|<
name|QPrinterInfo
argument_list|>
name|QWindowsPrinterSupport
operator|::
name|availablePrinters
parameter_list|()
block|{
name|QList
argument_list|<
name|QPrinterInfo
argument_list|>
name|printers
decl_stmt|;
name|DWORD
name|needed
init|=
literal|0
decl_stmt|;
name|DWORD
name|returned
init|=
literal|0
decl_stmt|;
if|if
condition|(
operator|!
name|EnumPrinters
argument_list|(
name|PRINTER_ENUM_LOCAL
operator||
name|PRINTER_ENUM_CONNECTIONS
argument_list|,
name|NULL
argument_list|,
literal|4
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
operator|&
name|needed
argument_list|,
operator|&
name|returned
argument_list|)
condition|)
block|{
name|LPBYTE
name|buffer
init|=
operator|new
name|BYTE
index|[
name|needed
index|]
decl_stmt|;
if|if
condition|(
name|EnumPrinters
argument_list|(
name|PRINTER_ENUM_LOCAL
operator||
name|PRINTER_ENUM_CONNECTIONS
argument_list|,
name|NULL
argument_list|,
literal|4
argument_list|,
name|buffer
argument_list|,
name|needed
argument_list|,
operator|&
name|needed
argument_list|,
operator|&
name|returned
argument_list|)
condition|)
block|{
name|PPRINTER_INFO_4
name|infoList
init|=
cast|reinterpret_cast
argument_list|<
name|PPRINTER_INFO_4
argument_list|>
argument_list|(
name|buffer
argument_list|)
decl_stmt|;
name|QPrinterInfo
name|defPrn
init|=
name|defaultPrinter
argument_list|()
decl_stmt|;
for|for
control|(
name|uint
name|i
init|=
literal|0
init|;
name|i
operator|<
name|returned
condition|;
operator|++
name|i
control|)
block|{
specifier|const
name|QString
name|printerName
argument_list|(
name|QString
operator|::
name|fromWCharArray
argument_list|(
name|infoList
index|[
name|i
index|]
operator|.
name|pPrinterName
argument_list|)
argument_list|)
decl_stmt|;
specifier|const
name|bool
name|isDefault
init|=
name|printerName
operator|==
name|defPrn
operator|.
name|printerName
argument_list|()
decl_stmt|;
name|printers
operator|.
name|append
argument_list|(
name|QPlatformPrinterSupport
operator|::
name|printerInfo
argument_list|(
name|printerName
argument_list|,
name|isDefault
argument_list|)
argument_list|)
expr_stmt|;
block|}
block|}
operator|delete
index|[]
name|buffer
expr_stmt|;
block|}
return|return
name|printers
return|;
block|}
end_function
begin_function
DECL|function|defaultPrinter
name|QPrinterInfo
name|QWindowsPrinterSupport
operator|::
name|defaultPrinter
parameter_list|()
block|{
name|QString
name|noPrinters
argument_list|(
name|QLatin1String
argument_list|(
literal|"qt_no_printers"
argument_list|)
argument_list|)
decl_stmt|;
name|wchar_t
name|buffer
index|[
literal|256
index|]
decl_stmt|;
name|GetProfileString
argument_list|(
literal|L"windows"
argument_list|,
literal|L"device"
argument_list|,
operator|(
name|wchar_t
operator|*
operator|)
name|noPrinters
operator|.
name|utf16
argument_list|()
argument_list|,
name|buffer
argument_list|,
literal|256
argument_list|)
expr_stmt|;
name|QString
name|output
init|=
name|QString
operator|::
name|fromWCharArray
argument_list|(
name|buffer
argument_list|)
decl_stmt|;
if|if
condition|(
name|output
operator|!=
name|noPrinters
condition|)
block|{
comment|// Filter out the name of the printer, which should be everything before a comma.
specifier|const
name|QString
name|printerName
init|=
name|output
operator|.
name|split
argument_list|(
name|QLatin1Char
argument_list|(
literal|','
argument_list|)
argument_list|)
operator|.
name|value
argument_list|(
literal|0
argument_list|)
decl_stmt|;
return|return
name|QPlatformPrinterSupport
operator|::
name|printerInfo
argument_list|(
name|printerName
argument_list|,
literal|true
argument_list|)
return|;
block|}
return|return
name|QPrinterInfo
argument_list|()
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
