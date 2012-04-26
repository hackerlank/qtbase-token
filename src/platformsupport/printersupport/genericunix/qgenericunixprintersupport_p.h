begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QGENERICUNIXPRINTINGSUPPORT_H
end_ifndef
begin_define
DECL|macro|QGENERICUNIXPRINTINGSUPPORT_H
define|#
directive|define
name|QGENERICUNIXPRINTINGSUPPORT_H
end_define
begin_include
include|#
directive|include
file|<qpa/qplatformprintersupport.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
name|class
name|QGenericUnixPrinterSupport
range|:
name|public
name|QPlatformPrinterSupport
block|{
name|public
operator|:
name|virtual
name|QList
operator|<
name|QPrinter
operator|::
name|PaperSize
operator|>
name|supportedPaperSizes
argument_list|(
argument|const QPrinterInfo&
argument_list|)
specifier|const
block|;
name|virtual
name|QList
operator|<
name|QPrinterInfo
operator|>
name|availablePrinters
argument_list|()
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
comment|// QGENERICUNIXPRINTINGSUPPORT_H
end_comment
end_unit
