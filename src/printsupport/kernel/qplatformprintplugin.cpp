begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qplatformprintplugin.h"
end_include
begin_include
include|#
directive|include
file|"qplatformprintersupport.h"
end_include
begin_include
include|#
directive|include
file|"qprinterinfo.h"
end_include
begin_include
include|#
directive|include
file|"private/qfactoryloader_p.h"
end_include
begin_include
include|#
directive|include
file|<qcoreapplication.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
ifndef|#
directive|ifndef
name|QT_NO_LIBRARY
name|Q_GLOBAL_STATIC_WITH_ARGS
argument_list|(
name|QFactoryLoader
argument_list|,
name|loader
argument_list|,
operator|(
name|QPlatformPrinterSupportFactoryInterface_iid
operator|,
name|QLatin1String
argument_list|(
literal|"/printsupport"
argument_list|)
operator|,
name|Qt
operator|::
name|CaseInsensitive
operator|)
argument_list|)
endif|#
directive|endif
DECL|function|QPlatformPrinterSupportPlugin
name|QPlatformPrinterSupportPlugin
operator|::
name|QPlatformPrinterSupportPlugin
argument_list|(
name|QObject
operator|*
name|parent
argument_list|)
range|:
name|QObject
argument_list|(
argument|parent
argument_list|)
block|{ }
DECL|function|~QPlatformPrinterSupportPlugin
name|QPlatformPrinterSupportPlugin
operator|::
name|~
name|QPlatformPrinterSupportPlugin
operator|(
operator|)
block|{ }
DECL|variable|printerSupport
specifier|static
name|QPlatformPrinterSupport
operator|*
name|printerSupport
operator|=
literal|0
decl_stmt|;
end_decl_stmt
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_LIBRARY
end_ifndef
begin_function
DECL|function|cleanupPrinterSupport
specifier|static
name|void
name|cleanupPrinterSupport
parameter_list|()
block|{
ifndef|#
directive|ifndef
name|QT_NO_PRINTER
operator|delete
name|printerSupport
expr_stmt|;
endif|#
directive|endif
name|printerSupport
operator|=
literal|0
expr_stmt|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// !QT_NO_LIBRARY
end_comment
begin_comment
comment|/*!     \internal      Returns a lazily-initialized singleton. Ownership is granted to the     QPlatformPrinterSupportPlugin, which is never unloaded or destroyed until     application exit, i.e. you can expect this pointer to always be valid and     multiple calls to this function will always return the same pointer. */
end_comment
begin_function
DECL|function|get
name|QPlatformPrinterSupport
modifier|*
name|QPlatformPrinterSupportPlugin
operator|::
name|get
parameter_list|()
block|{
ifndef|#
directive|ifndef
name|QT_NO_LIBRARY
if|if
condition|(
operator|!
name|printerSupport
condition|)
block|{
specifier|const
name|QMultiMap
argument_list|<
name|int
argument_list|,
name|QString
argument_list|>
name|keyMap
init|=
name|loader
argument_list|()
operator|->
name|keyMap
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
name|keyMap
operator|.
name|isEmpty
argument_list|()
condition|)
name|printerSupport
operator|=
name|qLoadPlugin
argument_list|<
name|QPlatformPrinterSupport
argument_list|,
name|QPlatformPrinterSupportPlugin
argument_list|>
argument_list|(
name|loader
argument_list|()
argument_list|,
name|keyMap
operator|.
name|constBegin
argument_list|()
operator|.
name|value
argument_list|()
argument_list|)
expr_stmt|;
if|if
condition|(
name|printerSupport
condition|)
name|qAddPostRoutine
argument_list|(
name|cleanupPrinterSupport
argument_list|)
expr_stmt|;
block|}
endif|#
directive|endif
comment|// !QT_NO_LIBRARY
return|return
name|printerSupport
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
