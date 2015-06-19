begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the QtPrintSupport module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtCore/QMetaMethod>
end_include
begin_include
include|#
directive|include
file|<QtGui/QGuiApplication>
end_include
begin_include
include|#
directive|include
file|<qpa/qplatformnativeinterface.h>
end_include
begin_include
include|#
directive|include
file|<qpa/qplatformprintplugin.h>
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_class
DECL|class|QCocoaPrinterSupportPlugin
class|class
name|QCocoaPrinterSupportPlugin
super|:
specifier|public
name|QPlatformPrinterSupportPlugin
block|{
name|Q_OBJECT
name|Q_PLUGIN_METADATA
argument_list|(
name|IID
name|QPlatformPrinterSupportFactoryInterface_iid
name|FILE
literal|"cocoa.json"
argument_list|)
decl|public
range|:
name|QPlatformPrinterSupport
operator|*
name|create
argument_list|(
specifier|const
name|QString
operator|&
argument_list|)
decl_stmt|;
block|}
class|;
end_class
begin_function
DECL|function|create
name|QPlatformPrinterSupport
modifier|*
name|QCocoaPrinterSupportPlugin
operator|::
name|create
parameter_list|(
specifier|const
name|QString
modifier|&
name|key
parameter_list|)
block|{
if|if
condition|(
name|key
operator|.
name|compare
argument_list|(
name|key
argument_list|,
name|QStringLiteral
argument_list|(
literal|"cocoaprintersupport"
argument_list|)
argument_list|,
name|Qt
operator|::
name|CaseInsensitive
argument_list|)
operator|!=
literal|0
condition|)
return|return
literal|0
return|;
name|QGuiApplication
modifier|*
name|app
init|=
name|qobject_cast
argument_list|<
name|QGuiApplication
operator|*
argument_list|>
argument_list|(
name|QCoreApplication
operator|::
name|instance
argument_list|()
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|app
condition|)
return|return
literal|0
return|;
name|QPlatformNativeInterface
modifier|*
name|platformNativeInterface
init|=
name|app
operator|->
name|platformNativeInterface
argument_list|()
decl_stmt|;
name|int
name|at
init|=
name|platformNativeInterface
operator|->
name|metaObject
argument_list|()
operator|->
name|indexOfMethod
argument_list|(
literal|"createPlatformPrinterSupport()"
argument_list|)
decl_stmt|;
if|if
condition|(
name|at
operator|==
operator|-
literal|1
condition|)
return|return
literal|0
return|;
name|QMetaMethod
name|createPlatformPrinterSupport
init|=
name|platformNativeInterface
operator|->
name|metaObject
argument_list|()
operator|->
name|method
argument_list|(
name|at
argument_list|)
decl_stmt|;
name|QPlatformPrinterSupport
modifier|*
name|platformPrinterSupport
init|=
literal|0
decl_stmt|;
if|if
condition|(
operator|!
name|createPlatformPrinterSupport
operator|.
name|invoke
argument_list|(
name|platformNativeInterface
argument_list|,
name|Q_RETURN_ARG
argument_list|(
name|QPlatformPrinterSupport
operator|*
argument_list|,
name|platformPrinterSupport
argument_list|)
argument_list|)
condition|)
return|return
literal|0
return|;
return|return
name|platformPrinterSupport
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_include
include|#
directive|include
file|"main.moc"
end_include
end_unit
