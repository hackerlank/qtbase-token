begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qnativewifiengine.h"
end_include
begin_include
include|#
directive|include
file|"platformdefs.h"
end_include
begin_include
include|#
directive|include
file|<QtCore/qmutex.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qlibrary.h>
end_include
begin_include
include|#
directive|include
file|<QtNetwork/private/qbearerplugin_p.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qdebug.h>
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_BEARERMANAGEMENT
end_ifndef
begin_function
name|QT_BEGIN_NAMESPACE
DECL|function|resolveLibraryInternal
specifier|static
name|bool
name|resolveLibraryInternal
parameter_list|()
block|{
name|QLibrary
name|wlanapiLib
argument_list|(
name|QLatin1String
argument_list|(
literal|"wlanapi"
argument_list|)
argument_list|)
decl_stmt|;
name|local_WlanOpenHandle
operator|=
operator|(
name|WlanOpenHandleProto
operator|)
name|wlanapiLib
operator|.
name|resolve
argument_list|(
literal|"WlanOpenHandle"
argument_list|)
expr_stmt|;
name|local_WlanRegisterNotification
operator|=
operator|(
name|WlanRegisterNotificationProto
operator|)
name|wlanapiLib
operator|.
name|resolve
argument_list|(
literal|"WlanRegisterNotification"
argument_list|)
expr_stmt|;
name|local_WlanEnumInterfaces
operator|=
operator|(
name|WlanEnumInterfacesProto
operator|)
name|wlanapiLib
operator|.
name|resolve
argument_list|(
literal|"WlanEnumInterfaces"
argument_list|)
expr_stmt|;
name|local_WlanGetAvailableNetworkList
operator|=
operator|(
name|WlanGetAvailableNetworkListProto
operator|)
name|wlanapiLib
operator|.
name|resolve
argument_list|(
literal|"WlanGetAvailableNetworkList"
argument_list|)
expr_stmt|;
name|local_WlanQueryInterface
operator|=
operator|(
name|WlanQueryInterfaceProto
operator|)
name|wlanapiLib
operator|.
name|resolve
argument_list|(
literal|"WlanQueryInterface"
argument_list|)
expr_stmt|;
name|local_WlanConnect
operator|=
operator|(
name|WlanConnectProto
operator|)
name|wlanapiLib
operator|.
name|resolve
argument_list|(
literal|"WlanConnect"
argument_list|)
expr_stmt|;
name|local_WlanDisconnect
operator|=
operator|(
name|WlanDisconnectProto
operator|)
name|wlanapiLib
operator|.
name|resolve
argument_list|(
literal|"WlanDisconnect"
argument_list|)
expr_stmt|;
name|local_WlanScan
operator|=
operator|(
name|WlanScanProto
operator|)
name|wlanapiLib
operator|.
name|resolve
argument_list|(
literal|"WlanScan"
argument_list|)
expr_stmt|;
name|local_WlanFreeMemory
operator|=
operator|(
name|WlanFreeMemoryProto
operator|)
name|wlanapiLib
operator|.
name|resolve
argument_list|(
literal|"WlanFreeMemory"
argument_list|)
expr_stmt|;
name|local_WlanCloseHandle
operator|=
operator|(
name|WlanCloseHandleProto
operator|)
name|wlanapiLib
operator|.
name|resolve
argument_list|(
literal|"WlanCloseHandle"
argument_list|)
expr_stmt|;
return|return
literal|true
return|;
block|}
end_function
begin_macro
name|Q_GLOBAL_STATIC_WITH_ARGS
argument_list|(
argument|bool
argument_list|,
argument|resolveLibrary
argument_list|,
argument|(resolveLibraryInternal())
argument_list|)
end_macro
begin_class
DECL|class|QNativeWifiEnginePlugin
class|class
name|QNativeWifiEnginePlugin
super|:
specifier|public
name|QBearerEnginePlugin
block|{
name|Q_OBJECT
name|Q_PLUGIN_METADATA
argument_list|(
name|IID
literal|"org.qt-project.Qt.QBearerEngineFactoryInterface"
name|FILE
literal|"nativewifi.json"
argument_list|)
decl|public
range|:
name|QNativeWifiEnginePlugin
argument_list|()
decl_stmt|;
name|~
name|QNativeWifiEnginePlugin
parameter_list|()
destructor_decl|;
name|QBearerEngine
modifier|*
name|create
parameter_list|(
specifier|const
name|QString
modifier|&
name|key
parameter_list|)
specifier|const
function_decl|;
block|}
class|;
end_class
begin_constructor
DECL|function|QNativeWifiEnginePlugin
name|QNativeWifiEnginePlugin
operator|::
name|QNativeWifiEnginePlugin
parameter_list|()
block|{ }
end_constructor
begin_destructor
DECL|function|~QNativeWifiEnginePlugin
name|QNativeWifiEnginePlugin
operator|::
name|~
name|QNativeWifiEnginePlugin
parameter_list|()
block|{ }
end_destructor
begin_function
DECL|function|create
name|QBearerEngine
modifier|*
name|QNativeWifiEnginePlugin
operator|::
name|create
parameter_list|(
specifier|const
name|QString
modifier|&
name|key
parameter_list|)
specifier|const
block|{
if|if
condition|(
name|key
operator|!=
name|QLatin1String
argument_list|(
literal|"nativewifi"
argument_list|)
condition|)
return|return
literal|0
return|;
name|resolveLibrary
argument_list|()
expr_stmt|;
comment|// native wifi dll not available
if|if
condition|(
operator|!
name|local_WlanOpenHandle
condition|)
return|return
literal|0
return|;
name|QNativeWifiEngine
modifier|*
name|engine
init|=
operator|new
name|QNativeWifiEngine
decl_stmt|;
comment|// could not initialise subsystem
if|if
condition|(
name|engine
operator|&&
operator|!
name|engine
operator|->
name|available
argument_list|()
condition|)
block|{
operator|delete
name|engine
expr_stmt|;
return|return
literal|0
return|;
block|}
return|return
name|engine
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
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_BEARERMANAGEMENT
end_comment
end_unit
