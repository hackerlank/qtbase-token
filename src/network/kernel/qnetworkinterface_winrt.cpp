begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the QtNetwork module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qnetworkinterface.h"
end_include
begin_include
include|#
directive|include
file|"qnetworkinterface_p.h"
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_NETWORKINTERFACE
end_ifndef
begin_include
include|#
directive|include
file|<qfunctions_winrt.h>
end_include
begin_include
include|#
directive|include
file|<wrl.h>
end_include
begin_include
include|#
directive|include
file|<windows.foundation.h>
end_include
begin_include
include|#
directive|include
file|<windows.foundation.collections.h>
end_include
begin_include
include|#
directive|include
file|<windows.networking.h>
end_include
begin_include
include|#
directive|include
file|<windows.networking.connectivity.h>
end_include
begin_using
using|using
namespace|namespace
name|Microsoft
operator|::
name|WRL
namespace|;
end_using
begin_using
using|using
namespace|namespace
name|Microsoft
operator|::
name|WRL
operator|::
name|Wrappers
namespace|;
end_using
begin_using
using|using
namespace|namespace
name|ABI
operator|::
name|Windows
operator|::
name|Foundation
namespace|;
end_using
begin_using
using|using
namespace|namespace
name|ABI
operator|::
name|Windows
operator|::
name|Foundation
operator|::
name|Collections
namespace|;
end_using
begin_using
using|using
namespace|namespace
name|ABI
operator|::
name|Windows
operator|::
name|Networking
namespace|;
end_using
begin_using
using|using
namespace|namespace
name|ABI
operator|::
name|Windows
operator|::
name|Networking
operator|::
name|Connectivity
namespace|;
end_using
begin_include
include|#
directive|include
file|<qhostinfo.h>
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_struct
DECL|struct|HostNameInfo
struct|struct
name|HostNameInfo
block|{
DECL|member|adapterId
name|GUID
name|adapterId
decl_stmt|;
DECL|member|prefixLength
name|unsigned
name|char
name|prefixLength
decl_stmt|;
DECL|member|address
name|QString
name|address
decl_stmt|;
block|}
struct|;
end_struct
begin_function
DECL|function|interfaceIndexFromName
name|uint
name|QNetworkInterfaceManager
operator|::
name|interfaceIndexFromName
parameter_list|(
specifier|const
name|QString
modifier|&
name|name
parameter_list|)
block|{
comment|// TBD - may not be possible
name|Q_UNUSED
argument_list|(
name|name
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function
begin_function
DECL|function|interfaceNameFromIndex
name|QString
name|QNetworkInterfaceManager
operator|::
name|interfaceNameFromIndex
parameter_list|(
name|uint
name|index
parameter_list|)
block|{
comment|// TBD - may not be possible
return|return
name|QString
operator|::
name|number
argument_list|(
name|index
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|interfaceFromProfile
specifier|static
name|QNetworkInterfacePrivate
modifier|*
name|interfaceFromProfile
parameter_list|(
name|IConnectionProfile
modifier|*
name|profile
parameter_list|,
name|QList
argument_list|<
name|HostNameInfo
argument_list|>
modifier|*
name|hostList
parameter_list|)
block|{
if|if
condition|(
operator|!
name|profile
condition|)
return|return
literal|0
return|;
name|QNetworkInterfacePrivate
modifier|*
name|iface
init|=
operator|new
name|QNetworkInterfacePrivate
decl_stmt|;
name|NetworkConnectivityLevel
name|connectivityLevel
decl_stmt|;
name|HRESULT
name|hr
init|=
name|profile
operator|->
name|GetNetworkConnectivityLevel
argument_list|(
operator|&
name|connectivityLevel
argument_list|)
decl_stmt|;
name|Q_ASSERT_SUCCEEDED
argument_list|(
name|hr
argument_list|)
expr_stmt|;
if|if
condition|(
name|connectivityLevel
operator|!=
name|NetworkConnectivityLevel_None
condition|)
name|iface
operator|->
name|flags
operator|=
name|QNetworkInterface
operator|::
name|IsUp
operator||
name|QNetworkInterface
operator|::
name|IsRunning
expr_stmt|;
name|iface
operator|->
name|flags
operator||=
name|QNetworkInterface
operator|::
name|CanBroadcast
expr_stmt|;
name|ComPtr
argument_list|<
name|INetworkAdapter
argument_list|>
name|adapter
decl_stmt|;
name|hr
operator|=
name|profile
operator|->
name|get_NetworkAdapter
argument_list|(
operator|&
name|adapter
argument_list|)
expr_stmt|;
comment|// Indicates that no internet connection is available/the device is in airplane mode
if|if
condition|(
name|hr
operator|==
name|E_INVALIDARG
condition|)
return|return
literal|0
return|;
name|Q_ASSERT_SUCCEEDED
argument_list|(
name|hr
argument_list|)
expr_stmt|;
name|UINT32
name|type
decl_stmt|;
name|hr
operator|=
name|adapter
operator|->
name|get_IanaInterfaceType
argument_list|(
operator|&
name|type
argument_list|)
expr_stmt|;
name|Q_ASSERT_SUCCEEDED
argument_list|(
name|hr
argument_list|)
expr_stmt|;
if|if
condition|(
name|type
operator|==
literal|23
condition|)
name|iface
operator|->
name|flags
operator||=
name|QNetworkInterface
operator|::
name|IsPointToPoint
expr_stmt|;
name|GUID
name|id
decl_stmt|;
name|hr
operator|=
name|adapter
operator|->
name|get_NetworkAdapterId
argument_list|(
operator|&
name|id
argument_list|)
expr_stmt|;
name|Q_ASSERT_SUCCEEDED
argument_list|(
name|hr
argument_list|)
expr_stmt|;
name|OLECHAR
name|adapterName
index|[
literal|39
index|]
init|=
block|{
literal|0
block|}
decl_stmt|;
name|StringFromGUID2
argument_list|(
name|id
argument_list|,
name|adapterName
argument_list|,
literal|39
argument_list|)
expr_stmt|;
name|iface
operator|->
name|name
operator|=
name|QString
operator|::
name|fromWCharArray
argument_list|(
name|adapterName
argument_list|)
expr_stmt|;
comment|// According to http://stackoverflow.com/questions/12936193/how-unique-is-the-ethernet-network-adapter-id-in-winrt-it-is-derived-from-the-m
comment|// obtaining the MAC address using WinRT API is impossible
comment|// iface->hardwareAddress = ?
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|hostList
operator|->
name|length
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
specifier|const
name|HostNameInfo
name|hostInfo
init|=
name|hostList
operator|->
name|at
argument_list|(
name|i
argument_list|)
decl_stmt|;
if|if
condition|(
name|id
operator|!=
name|hostInfo
operator|.
name|adapterId
condition|)
continue|continue;
name|QNetworkAddressEntry
name|entry
decl_stmt|;
name|entry
operator|.
name|setIp
argument_list|(
name|QHostAddress
argument_list|(
name|hostInfo
operator|.
name|address
argument_list|)
argument_list|)
expr_stmt|;
name|entry
operator|.
name|setPrefixLength
argument_list|(
name|hostInfo
operator|.
name|prefixLength
argument_list|)
expr_stmt|;
name|iface
operator|->
name|addressEntries
operator|<<
name|entry
expr_stmt|;
name|hostList
operator|->
name|takeAt
argument_list|(
name|i
argument_list|)
expr_stmt|;
operator|--
name|i
expr_stmt|;
block|}
return|return
name|iface
return|;
block|}
end_function
begin_function
DECL|function|interfaceListing
specifier|static
name|QList
argument_list|<
name|QNetworkInterfacePrivate
modifier|*
argument_list|>
name|interfaceListing
parameter_list|()
block|{
name|QList
argument_list|<
name|QNetworkInterfacePrivate
modifier|*
argument_list|>
name|interfaces
decl_stmt|;
name|QList
argument_list|<
name|HostNameInfo
argument_list|>
name|hostList
decl_stmt|;
name|ComPtr
argument_list|<
name|INetworkInformationStatics
argument_list|>
name|hostNameStatics
decl_stmt|;
name|HRESULT
name|hr
init|=
name|GetActivationFactory
argument_list|(
name|HString
operator|::
name|MakeReference
argument_list|(
name|RuntimeClass_Windows_Networking_Connectivity_NetworkInformation
argument_list|)
operator|.
name|Get
argument_list|()
argument_list|,
operator|&
name|hostNameStatics
argument_list|)
decl_stmt|;
name|Q_ASSERT_SUCCEEDED
argument_list|(
name|hr
argument_list|)
expr_stmt|;
name|ComPtr
argument_list|<
name|IVectorView
argument_list|<
name|HostName
modifier|*
argument_list|>
argument_list|>
name|hostNames
decl_stmt|;
name|hr
operator|=
name|hostNameStatics
operator|->
name|GetHostNames
argument_list|(
operator|&
name|hostNames
argument_list|)
expr_stmt|;
name|Q_ASSERT_SUCCEEDED
argument_list|(
name|hr
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|hostNames
condition|)
return|return
name|interfaces
return|;
name|unsigned
name|int
name|hostNameCount
decl_stmt|;
name|hr
operator|=
name|hostNames
operator|->
name|get_Size
argument_list|(
operator|&
name|hostNameCount
argument_list|)
expr_stmt|;
name|Q_ASSERT_SUCCEEDED
argument_list|(
name|hr
argument_list|)
expr_stmt|;
for|for
control|(
name|unsigned
name|i
init|=
literal|0
init|;
name|i
operator|<
name|hostNameCount
condition|;
operator|++
name|i
control|)
block|{
name|HostNameInfo
name|hostInfo
decl_stmt|;
name|ComPtr
argument_list|<
name|IHostName
argument_list|>
name|hostName
decl_stmt|;
name|hr
operator|=
name|hostNames
operator|->
name|GetAt
argument_list|(
name|i
argument_list|,
operator|&
name|hostName
argument_list|)
expr_stmt|;
name|Q_ASSERT_SUCCEEDED
argument_list|(
name|hr
argument_list|)
expr_stmt|;
name|HostNameType
name|type
decl_stmt|;
name|hr
operator|=
name|hostName
operator|->
name|get_Type
argument_list|(
operator|&
name|type
argument_list|)
expr_stmt|;
name|Q_ASSERT_SUCCEEDED
argument_list|(
name|hr
argument_list|)
expr_stmt|;
if|if
condition|(
name|type
operator|==
name|HostNameType_DomainName
condition|)
continue|continue;
name|ComPtr
argument_list|<
name|IIPInformation
argument_list|>
name|ipInformation
decl_stmt|;
name|hr
operator|=
name|hostName
operator|->
name|get_IPInformation
argument_list|(
operator|&
name|ipInformation
argument_list|)
expr_stmt|;
name|Q_ASSERT_SUCCEEDED
argument_list|(
name|hr
argument_list|)
expr_stmt|;
name|ComPtr
argument_list|<
name|INetworkAdapter
argument_list|>
name|currentAdapter
decl_stmt|;
name|hr
operator|=
name|ipInformation
operator|->
name|get_NetworkAdapter
argument_list|(
operator|&
name|currentAdapter
argument_list|)
expr_stmt|;
name|Q_ASSERT_SUCCEEDED
argument_list|(
name|hr
argument_list|)
expr_stmt|;
name|hr
operator|=
name|currentAdapter
operator|->
name|get_NetworkAdapterId
argument_list|(
operator|&
name|hostInfo
operator|.
name|adapterId
argument_list|)
expr_stmt|;
name|Q_ASSERT_SUCCEEDED
argument_list|(
name|hr
argument_list|)
expr_stmt|;
name|ComPtr
argument_list|<
name|IReference
argument_list|<
name|unsigned
name|char
argument_list|>
argument_list|>
name|prefixLengthReference
decl_stmt|;
name|hr
operator|=
name|ipInformation
operator|->
name|get_PrefixLength
argument_list|(
operator|&
name|prefixLengthReference
argument_list|)
expr_stmt|;
name|Q_ASSERT_SUCCEEDED
argument_list|(
name|hr
argument_list|)
expr_stmt|;
name|hr
operator|=
name|prefixLengthReference
operator|->
name|get_Value
argument_list|(
operator|&
name|hostInfo
operator|.
name|prefixLength
argument_list|)
expr_stmt|;
name|Q_ASSERT_SUCCEEDED
argument_list|(
name|hr
argument_list|)
expr_stmt|;
comment|// invalid prefixes
if|if
condition|(
operator|(
name|type
operator|==
name|HostNameType_Ipv4
operator|&&
name|hostInfo
operator|.
name|prefixLength
operator|>
literal|32
operator|)
operator|||
operator|(
name|type
operator|==
name|HostNameType_Ipv6
operator|&&
name|hostInfo
operator|.
name|prefixLength
operator|>
literal|128
operator|)
condition|)
continue|continue;
name|HString
name|name
decl_stmt|;
name|hr
operator|=
name|hostName
operator|->
name|get_CanonicalName
argument_list|(
name|name
operator|.
name|GetAddressOf
argument_list|()
argument_list|)
expr_stmt|;
name|Q_ASSERT_SUCCEEDED
argument_list|(
name|hr
argument_list|)
expr_stmt|;
name|UINT32
name|length
decl_stmt|;
name|PCWSTR
name|rawString
init|=
name|name
operator|.
name|GetRawBuffer
argument_list|(
operator|&
name|length
argument_list|)
decl_stmt|;
name|hostInfo
operator|.
name|address
operator|=
name|QString
operator|::
name|fromWCharArray
argument_list|(
name|rawString
argument_list|,
name|length
argument_list|)
expr_stmt|;
name|hostList
operator|<<
name|hostInfo
expr_stmt|;
block|}
name|INetworkInformationStatics
modifier|*
name|networkInfoStatics
decl_stmt|;
name|hr
operator|=
name|GetActivationFactory
argument_list|(
name|HString
operator|::
name|MakeReference
argument_list|(
name|RuntimeClass_Windows_Networking_Connectivity_NetworkInformation
argument_list|)
operator|.
name|Get
argument_list|()
argument_list|,
operator|&
name|networkInfoStatics
argument_list|)
expr_stmt|;
name|Q_ASSERT_SUCCEEDED
argument_list|(
name|hr
argument_list|)
expr_stmt|;
name|ComPtr
argument_list|<
name|IConnectionProfile
argument_list|>
name|connectionProfile
decl_stmt|;
name|hr
operator|=
name|networkInfoStatics
operator|->
name|GetInternetConnectionProfile
argument_list|(
operator|&
name|connectionProfile
argument_list|)
expr_stmt|;
name|Q_ASSERT_SUCCEEDED
argument_list|(
name|hr
argument_list|)
expr_stmt|;
name|QNetworkInterfacePrivate
modifier|*
name|iface
init|=
name|interfaceFromProfile
argument_list|(
name|connectionProfile
operator|.
name|Get
argument_list|()
argument_list|,
operator|&
name|hostList
argument_list|)
decl_stmt|;
if|if
condition|(
name|iface
condition|)
block|{
name|iface
operator|->
name|index
operator|=
literal|0
expr_stmt|;
name|interfaces
operator|<<
name|iface
expr_stmt|;
block|}
name|ComPtr
argument_list|<
name|IVectorView
argument_list|<
name|ConnectionProfile
modifier|*
argument_list|>
argument_list|>
name|connectionProfiles
decl_stmt|;
name|hr
operator|=
name|networkInfoStatics
operator|->
name|GetConnectionProfiles
argument_list|(
operator|&
name|connectionProfiles
argument_list|)
expr_stmt|;
name|Q_ASSERT_SUCCEEDED
argument_list|(
name|hr
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|connectionProfiles
condition|)
return|return
name|interfaces
return|;
name|unsigned
name|int
name|size
decl_stmt|;
name|hr
operator|=
name|connectionProfiles
operator|->
name|get_Size
argument_list|(
operator|&
name|size
argument_list|)
expr_stmt|;
name|Q_ASSERT_SUCCEEDED
argument_list|(
name|hr
argument_list|)
expr_stmt|;
for|for
control|(
name|unsigned
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|size
condition|;
operator|++
name|i
control|)
block|{
name|ComPtr
argument_list|<
name|IConnectionProfile
argument_list|>
name|profile
decl_stmt|;
name|hr
operator|=
name|connectionProfiles
operator|->
name|GetAt
argument_list|(
name|i
argument_list|,
operator|&
name|profile
argument_list|)
expr_stmt|;
name|Q_ASSERT_SUCCEEDED
argument_list|(
name|hr
argument_list|)
expr_stmt|;
name|iface
operator|=
name|interfaceFromProfile
argument_list|(
name|profile
operator|.
name|Get
argument_list|()
argument_list|,
operator|&
name|hostList
argument_list|)
expr_stmt|;
if|if
condition|(
name|iface
condition|)
block|{
name|iface
operator|->
name|index
operator|=
name|i
operator|+
literal|1
expr_stmt|;
name|interfaces
operator|<<
name|iface
expr_stmt|;
block|}
block|}
return|return
name|interfaces
return|;
block|}
end_function
begin_function
DECL|function|scan
name|QList
argument_list|<
name|QNetworkInterfacePrivate
modifier|*
argument_list|>
name|QNetworkInterfaceManager
operator|::
name|scan
parameter_list|()
block|{
return|return
name|interfaceListing
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|localDomainName
name|QString
name|QHostInfo
operator|::
name|localDomainName
parameter_list|()
block|{
return|return
name|QString
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
comment|// QT_NO_NETWORKINTERFACE
end_comment
end_unit
