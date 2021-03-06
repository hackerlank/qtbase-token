begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qplatformprintersupport.h"
end_include
begin_include
include|#
directive|include
file|"qplatformprintdevice.h"
end_include
begin_include
include|#
directive|include
file|<QtGui/qpagesize.h>
end_include
begin_include
include|#
directive|include
file|<QtPrintSupport/qprinterinfo.h>
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
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_PRINTER
end_ifndef
begin_function
name|QT_BEGIN_NAMESPACE
comment|/*!     \class QPlatformPrinterSupport     \since 5.0     \internal     \preliminary     \ingroup qpa      \brief The QPlatformPrinterSupport class provides an abstraction for print support.  */
DECL|function|QPlatformPrinterSupport
name|QPlatformPrinterSupport
operator|::
name|QPlatformPrinterSupport
parameter_list|()
block|{ }
end_function
begin_destructor
DECL|function|~QPlatformPrinterSupport
name|QPlatformPrinterSupport
operator|::
name|~
name|QPlatformPrinterSupport
parameter_list|()
block|{ }
end_destructor
begin_function
DECL|function|createNativePrintEngine
name|QPrintEngine
modifier|*
name|QPlatformPrinterSupport
operator|::
name|createNativePrintEngine
parameter_list|(
name|QPrinter
operator|::
name|PrinterMode
parameter_list|)
block|{
return|return
literal|0
return|;
block|}
end_function
begin_function
DECL|function|createPaintEngine
name|QPaintEngine
modifier|*
name|QPlatformPrinterSupport
operator|::
name|createPaintEngine
parameter_list|(
name|QPrintEngine
modifier|*
parameter_list|,
name|QPrinter
operator|::
name|PrinterMode
parameter_list|)
block|{
return|return
literal|0
return|;
block|}
end_function
begin_function
DECL|function|createPrintDevice
name|QPrintDevice
name|QPlatformPrinterSupport
operator|::
name|createPrintDevice
parameter_list|(
name|QPlatformPrintDevice
modifier|*
name|device
parameter_list|)
block|{
return|return
name|QPrintDevice
argument_list|(
name|device
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|createPrintDevice
name|QPrintDevice
name|QPlatformPrinterSupport
operator|::
name|createPrintDevice
parameter_list|(
specifier|const
name|QString
modifier|&
name|id
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
argument|id
argument_list|)
return|return
name|QPrintDevice
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|createDefaultPrintDevice
name|QPrintDevice
name|QPlatformPrinterSupport
operator|::
name|createDefaultPrintDevice
parameter_list|()
block|{
return|return
name|createPrintDevice
argument_list|(
name|defaultPrintDeviceId
argument_list|()
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|availablePrintDeviceIds
name|QStringList
name|QPlatformPrinterSupport
operator|::
name|availablePrintDeviceIds
parameter_list|()
specifier|const
block|{
return|return
name|QStringList
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|defaultPrintDeviceId
name|QString
name|QPlatformPrinterSupport
operator|::
name|defaultPrintDeviceId
parameter_list|()
specifier|const
block|{
return|return
name|QString
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|createPageSize
name|QPageSize
name|QPlatformPrinterSupport
operator|::
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
block|{
name|Q_UNUSED
argument_list|(
argument|id
argument_list|)
name|Q_UNUSED
argument_list|(
argument|size
argument_list|)
name|Q_UNUSED
argument_list|(
argument|localizedName
argument_list|)
return|return
name|QPageSize
argument_list|()
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
