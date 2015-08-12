begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the QtNetwork module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_define
DECL|macro|WIN32_LEAN_AND_MEAN
define|#
directive|define
name|WIN32_LEAN_AND_MEAN
value|1
end_define
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
file|<qhostinfo.h>
end_include
begin_include
include|#
directive|include
file|<qhash.h>
end_include
begin_include
include|#
directive|include
file|<qurl.h>
end_include
begin_comment
comment|// Since we need to include winsock2.h, we need to define WIN32_LEAN_AND_MEAN
end_comment
begin_comment
comment|// (above) so windows.h won't include winsock.h.
end_comment
begin_comment
comment|// In addition, we need to include winsock2.h before iphlpapi.h and we need
end_comment
begin_comment
comment|// to include ws2ipdef.h to work around an MinGW-w64 bug
end_comment
begin_comment
comment|// (http://sourceforge.net/p/mingw-w64/mailman/message/32935366/)
end_comment
begin_include
include|#
directive|include
file|<winsock2.h>
end_include
begin_include
include|#
directive|include
file|<ws2ipdef.h>
end_include
begin_include
include|#
directive|include
file|<iphlpapi.h>
end_include
begin_include
include|#
directive|include
file|<ws2tcpip.h>
end_include
begin_include
include|#
directive|include
file|<qt_windows.h>
end_include
begin_function
name|QT_BEGIN_NAMESPACE
DECL|function|resolveLibs
specifier|static
name|void
name|resolveLibs
parameter_list|()
block|{
comment|// try to find the functions we need from Iphlpapi.dll
specifier|static
name|bool
name|done
init|=
literal|false
decl_stmt|;
if|if
condition|(
operator|!
name|done
condition|)
block|{
name|HINSTANCE
name|iphlpapiHnd
init|=
name|GetModuleHandle
argument_list|(
literal|L"iphlpapi"
argument_list|)
decl_stmt|;
name|Q_ASSERT
argument_list|(
name|iphlpapiHnd
argument_list|)
expr_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_WINCE
argument_list|)
else|#
directive|else
endif|#
directive|endif
name|done
operator|=
literal|true
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|addressFromSockaddr
specifier|static
name|QHostAddress
name|addressFromSockaddr
parameter_list|(
name|sockaddr
modifier|*
name|sa
parameter_list|)
block|{
name|QHostAddress
name|address
decl_stmt|;
if|if
condition|(
operator|!
name|sa
condition|)
return|return
name|address
return|;
if|if
condition|(
name|sa
operator|->
name|sa_family
operator|==
name|AF_INET
condition|)
name|address
operator|.
name|setAddress
argument_list|(
name|htonl
argument_list|(
operator|(
operator|(
name|sockaddr_in
operator|*
operator|)
name|sa
operator|)
operator|->
name|sin_addr
operator|.
name|s_addr
argument_list|)
argument_list|)
expr_stmt|;
elseif|else
if|if
condition|(
name|sa
operator|->
name|sa_family
operator|==
name|AF_INET6
condition|)
block|{
name|address
operator|.
name|setAddress
argument_list|(
operator|(
operator|(
name|sockaddr_in6
operator|*
operator|)
name|sa
operator|)
operator|->
name|sin6_addr
operator|.
name|s6_addr
argument_list|)
expr_stmt|;
name|int
name|scope
init|=
operator|(
operator|(
name|sockaddr_in6
operator|*
operator|)
name|sa
operator|)
operator|->
name|sin6_scope_id
decl_stmt|;
if|if
condition|(
name|scope
condition|)
name|address
operator|.
name|setScopeId
argument_list|(
name|QString
operator|::
name|number
argument_list|(
name|scope
argument_list|)
argument_list|)
expr_stmt|;
block|}
else|else
name|qWarning
argument_list|(
literal|"Got unknown socket family %d"
argument_list|,
name|sa
operator|->
name|sa_family
argument_list|)
expr_stmt|;
return|return
name|address
return|;
block|}
end_function
begin_function
DECL|function|ipv4Netmasks
specifier|static
name|QHash
argument_list|<
name|QHostAddress
argument_list|,
name|QHostAddress
argument_list|>
name|ipv4Netmasks
parameter_list|()
block|{
comment|//Retrieve all the IPV4 addresses& netmasks
name|IP_ADAPTER_INFO
name|staticBuf
index|[
literal|2
index|]
decl_stmt|;
comment|// 2 is arbitrary
name|PIP_ADAPTER_INFO
name|pAdapter
init|=
name|staticBuf
decl_stmt|;
name|ULONG
name|bufSize
init|=
sizeof|sizeof
name|staticBuf
decl_stmt|;
name|QHash
argument_list|<
name|QHostAddress
argument_list|,
name|QHostAddress
argument_list|>
name|ipv4netmasks
decl_stmt|;
name|DWORD
name|retval
init|=
name|GetAdaptersInfo
argument_list|(
name|pAdapter
argument_list|,
operator|&
name|bufSize
argument_list|)
decl_stmt|;
if|if
condition|(
name|retval
operator|==
name|ERROR_BUFFER_OVERFLOW
condition|)
block|{
comment|// need more memory
name|pAdapter
operator|=
operator|(
name|IP_ADAPTER_INFO
operator|*
operator|)
name|malloc
argument_list|(
name|bufSize
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|pAdapter
condition|)
return|return
name|ipv4netmasks
return|;
comment|// try again
if|if
condition|(
name|GetAdaptersInfo
argument_list|(
name|pAdapter
argument_list|,
operator|&
name|bufSize
argument_list|)
operator|!=
name|ERROR_SUCCESS
condition|)
block|{
name|free
argument_list|(
name|pAdapter
argument_list|)
expr_stmt|;
return|return
name|ipv4netmasks
return|;
block|}
block|}
elseif|else
if|if
condition|(
name|retval
operator|!=
name|ERROR_SUCCESS
condition|)
block|{
comment|// error
return|return
name|ipv4netmasks
return|;
block|}
comment|// iterate over the list and add the entries to our listing
for|for
control|(
name|PIP_ADAPTER_INFO
name|ptr
init|=
name|pAdapter
init|;
name|ptr
condition|;
name|ptr
operator|=
name|ptr
operator|->
name|Next
control|)
block|{
for|for
control|(
name|PIP_ADDR_STRING
name|addr
init|=
operator|&
name|ptr
operator|->
name|IpAddressList
init|;
name|addr
condition|;
name|addr
operator|=
name|addr
operator|->
name|Next
control|)
block|{
name|QHostAddress
name|address
argument_list|(
name|QLatin1String
argument_list|(
name|addr
operator|->
name|IpAddress
operator|.
name|String
argument_list|)
argument_list|)
decl_stmt|;
name|QHostAddress
name|mask
argument_list|(
name|QLatin1String
argument_list|(
name|addr
operator|->
name|IpMask
operator|.
name|String
argument_list|)
argument_list|)
decl_stmt|;
name|ipv4netmasks
index|[
name|address
index|]
operator|=
name|mask
expr_stmt|;
block|}
block|}
if|if
condition|(
name|pAdapter
operator|!=
name|staticBuf
condition|)
name|free
argument_list|(
name|pAdapter
argument_list|)
expr_stmt|;
return|return
name|ipv4netmasks
return|;
block|}
end_function
begin_function
DECL|function|interfaceListingWinXP
specifier|static
name|QList
argument_list|<
name|QNetworkInterfacePrivate
modifier|*
argument_list|>
name|interfaceListingWinXP
parameter_list|()
block|{
name|QList
argument_list|<
name|QNetworkInterfacePrivate
modifier|*
argument_list|>
name|interfaces
decl_stmt|;
name|IP_ADAPTER_ADDRESSES
name|staticBuf
index|[
literal|2
index|]
decl_stmt|;
comment|// 2 is arbitrary
name|PIP_ADAPTER_ADDRESSES
name|pAdapter
init|=
name|staticBuf
decl_stmt|;
name|ULONG
name|bufSize
init|=
sizeof|sizeof
name|staticBuf
decl_stmt|;
specifier|const
name|QHash
argument_list|<
name|QHostAddress
argument_list|,
name|QHostAddress
argument_list|>
modifier|&
name|ipv4netmasks
init|=
name|ipv4Netmasks
argument_list|()
decl_stmt|;
name|ULONG
name|flags
init|=
name|GAA_FLAG_INCLUDE_PREFIX
operator||
name|GAA_FLAG_SKIP_DNS_SERVER
operator||
name|GAA_FLAG_SKIP_MULTICAST
decl_stmt|;
name|ULONG
name|retval
init|=
name|GetAdaptersAddresses
argument_list|(
name|AF_UNSPEC
argument_list|,
name|flags
argument_list|,
name|NULL
argument_list|,
name|pAdapter
argument_list|,
operator|&
name|bufSize
argument_list|)
decl_stmt|;
if|if
condition|(
name|retval
operator|==
name|ERROR_BUFFER_OVERFLOW
condition|)
block|{
comment|// need more memory
name|pAdapter
operator|=
operator|(
name|IP_ADAPTER_ADDRESSES
operator|*
operator|)
name|malloc
argument_list|(
name|bufSize
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|pAdapter
condition|)
return|return
name|interfaces
return|;
comment|// try again
if|if
condition|(
name|GetAdaptersAddresses
argument_list|(
name|AF_UNSPEC
argument_list|,
name|flags
argument_list|,
name|NULL
argument_list|,
name|pAdapter
argument_list|,
operator|&
name|bufSize
argument_list|)
operator|!=
name|ERROR_SUCCESS
condition|)
block|{
name|free
argument_list|(
name|pAdapter
argument_list|)
expr_stmt|;
return|return
name|interfaces
return|;
block|}
block|}
elseif|else
if|if
condition|(
name|retval
operator|!=
name|ERROR_SUCCESS
condition|)
block|{
comment|// error
return|return
name|interfaces
return|;
block|}
comment|// iterate over the list and add the entries to our listing
for|for
control|(
name|PIP_ADAPTER_ADDRESSES
name|ptr
init|=
name|pAdapter
init|;
name|ptr
condition|;
name|ptr
operator|=
name|ptr
operator|->
name|Next
control|)
block|{
name|QNetworkInterfacePrivate
modifier|*
name|iface
init|=
operator|new
name|QNetworkInterfacePrivate
decl_stmt|;
name|interfaces
operator|<<
name|iface
expr_stmt|;
name|iface
operator|->
name|index
operator|=
literal|0
expr_stmt|;
if|if
condition|(
name|ptr
operator|->
name|Length
operator|>=
name|offsetof
argument_list|(
name|IP_ADAPTER_ADDRESSES
argument_list|,
name|Ipv6IfIndex
argument_list|)
operator|&&
name|ptr
operator|->
name|Ipv6IfIndex
operator|!=
literal|0
condition|)
name|iface
operator|->
name|index
operator|=
name|ptr
operator|->
name|Ipv6IfIndex
expr_stmt|;
elseif|else
if|if
condition|(
name|ptr
operator|->
name|IfIndex
operator|!=
literal|0
condition|)
name|iface
operator|->
name|index
operator|=
name|ptr
operator|->
name|IfIndex
expr_stmt|;
name|iface
operator|->
name|flags
operator|=
name|QNetworkInterface
operator|::
name|CanBroadcast
expr_stmt|;
if|if
condition|(
name|ptr
operator|->
name|OperStatus
operator|==
name|IfOperStatusUp
condition|)
name|iface
operator|->
name|flags
operator||=
name|QNetworkInterface
operator|::
name|IsUp
operator||
name|QNetworkInterface
operator|::
name|IsRunning
expr_stmt|;
if|if
condition|(
operator|(
name|ptr
operator|->
name|Flags
operator|&
name|IP_ADAPTER_NO_MULTICAST
operator|)
operator|==
literal|0
condition|)
name|iface
operator|->
name|flags
operator||=
name|QNetworkInterface
operator|::
name|CanMulticast
expr_stmt|;
if|if
condition|(
name|ptr
operator|->
name|IfType
operator|==
name|IF_TYPE_PPP
condition|)
name|iface
operator|->
name|flags
operator||=
name|QNetworkInterface
operator|::
name|IsPointToPoint
expr_stmt|;
name|iface
operator|->
name|name
operator|=
name|QString
operator|::
name|fromLocal8Bit
argument_list|(
name|ptr
operator|->
name|AdapterName
argument_list|)
expr_stmt|;
name|iface
operator|->
name|friendlyName
operator|=
name|QString
operator|::
name|fromWCharArray
argument_list|(
name|ptr
operator|->
name|FriendlyName
argument_list|)
expr_stmt|;
if|if
condition|(
name|ptr
operator|->
name|PhysicalAddressLength
condition|)
name|iface
operator|->
name|hardwareAddress
operator|=
name|iface
operator|->
name|makeHwAddress
argument_list|(
name|ptr
operator|->
name|PhysicalAddressLength
argument_list|,
name|ptr
operator|->
name|PhysicalAddress
argument_list|)
expr_stmt|;
else|else
comment|// loopback if it has no address
name|iface
operator|->
name|flags
operator||=
name|QNetworkInterface
operator|::
name|IsLoopBack
expr_stmt|;
comment|// The GetAdaptersAddresses call has an interesting semantic:
comment|// It can return a number N of addresses and a number M of prefixes.
comment|// But if you have IPv6 addresses, generally N> M.
comment|// I cannot find a way to relate the Address to the Prefix, aside from stopping
comment|// the iteration at the last Prefix entry and assume that it applies to all addresses
comment|// from that point on.
name|PIP_ADAPTER_PREFIX
name|pprefix
init|=
literal|0
decl_stmt|;
if|if
condition|(
name|ptr
operator|->
name|Length
operator|>=
name|offsetof
argument_list|(
name|IP_ADAPTER_ADDRESSES
argument_list|,
name|FirstPrefix
argument_list|)
condition|)
name|pprefix
operator|=
name|ptr
operator|->
name|FirstPrefix
expr_stmt|;
for|for
control|(
name|PIP_ADAPTER_UNICAST_ADDRESS
name|addr
init|=
name|ptr
operator|->
name|FirstUnicastAddress
init|;
name|addr
condition|;
name|addr
operator|=
name|addr
operator|->
name|Next
control|)
block|{
name|QNetworkAddressEntry
name|entry
decl_stmt|;
name|entry
operator|.
name|setIp
argument_list|(
name|addressFromSockaddr
argument_list|(
name|addr
operator|->
name|Address
operator|.
name|lpSockaddr
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|pprefix
condition|)
block|{
if|if
condition|(
name|entry
operator|.
name|ip
argument_list|()
operator|.
name|protocol
argument_list|()
operator|==
name|QAbstractSocket
operator|::
name|IPv4Protocol
condition|)
block|{
name|entry
operator|.
name|setNetmask
argument_list|(
name|ipv4netmasks
index|[
name|entry
operator|.
name|ip
argument_list|()
index|]
argument_list|)
expr_stmt|;
comment|// broadcast address is set on postProcess()
block|}
else|else
block|{
comment|//IPV6
name|entry
operator|.
name|setPrefixLength
argument_list|(
name|pprefix
operator|->
name|PrefixLength
argument_list|)
expr_stmt|;
block|}
name|pprefix
operator|=
name|pprefix
operator|->
name|Next
condition|?
name|pprefix
operator|->
name|Next
else|:
name|pprefix
expr_stmt|;
block|}
name|iface
operator|->
name|addressEntries
operator|<<
name|entry
expr_stmt|;
block|}
block|}
if|if
condition|(
name|pAdapter
operator|!=
name|staticBuf
condition|)
name|free
argument_list|(
name|pAdapter
argument_list|)
expr_stmt|;
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
name|resolveLibs
argument_list|()
expr_stmt|;
return|return
name|interfaceListingWinXP
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
name|resolveLibs
argument_list|()
expr_stmt|;
name|FIXED_INFO
name|info
decl_stmt|,
modifier|*
name|pinfo
decl_stmt|;
name|ULONG
name|bufSize
init|=
sizeof|sizeof
name|info
decl_stmt|;
name|pinfo
operator|=
operator|&
name|info
expr_stmt|;
if|if
condition|(
name|GetNetworkParams
argument_list|(
name|pinfo
argument_list|,
operator|&
name|bufSize
argument_list|)
operator|==
name|ERROR_BUFFER_OVERFLOW
condition|)
block|{
name|pinfo
operator|=
operator|(
name|FIXED_INFO
operator|*
operator|)
name|malloc
argument_list|(
name|bufSize
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|pinfo
condition|)
return|return
name|QString
argument_list|()
return|;
comment|// try again
if|if
condition|(
name|GetNetworkParams
argument_list|(
name|pinfo
argument_list|,
operator|&
name|bufSize
argument_list|)
operator|!=
name|ERROR_SUCCESS
condition|)
block|{
name|free
argument_list|(
name|pinfo
argument_list|)
expr_stmt|;
return|return
name|QString
argument_list|()
return|;
comment|// error
block|}
block|}
name|QString
name|domainName
init|=
name|QUrl
operator|::
name|fromAce
argument_list|(
name|pinfo
operator|->
name|DomainName
argument_list|)
decl_stmt|;
if|if
condition|(
name|pinfo
operator|!=
operator|&
name|info
condition|)
name|free
argument_list|(
name|pinfo
argument_list|)
expr_stmt|;
return|return
name|domainName
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
