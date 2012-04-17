begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Jeremy LainÃ©<jeremy.laine@m4x.org> ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtNetwork module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<winsock2.h>
end_include
begin_include
include|#
directive|include
file|"qdnslookup_p.h"
end_include
begin_include
include|#
directive|include
file|<qurl.h>
end_include
begin_include
include|#
directive|include
file|<private/qmutexpool_p.h>
end_include
begin_include
include|#
directive|include
file|<private/qsystemerror_p.h>
end_include
begin_include
include|#
directive|include
file|<qt_windows.h>
end_include
begin_include
include|#
directive|include
file|<windns.h>
end_include
begin_function
name|QT_BEGIN_NAMESPACE
DECL|function|query
name|void
name|QDnsLookupRunnable
operator|::
name|query
parameter_list|(
specifier|const
name|int
name|requestType
parameter_list|,
specifier|const
name|QByteArray
modifier|&
name|requestName
parameter_list|,
name|QDnsLookupReply
modifier|*
name|reply
parameter_list|)
block|{
comment|// Perform DNS query.
name|PDNS_RECORD
name|dns_records
init|=
literal|0
decl_stmt|;
specifier|const
name|QString
name|requestNameUtf16
init|=
name|QString
operator|::
name|fromUtf8
argument_list|(
name|requestName
operator|.
name|data
argument_list|()
argument_list|,
name|requestName
operator|.
name|size
argument_list|()
argument_list|)
decl_stmt|;
specifier|const
name|DNS_STATUS
name|status
init|=
name|DnsQuery_W
argument_list|(
cast|reinterpret_cast
argument_list|<
specifier|const
name|wchar_t
operator|*
argument_list|>
argument_list|(
name|requestNameUtf16
operator|.
name|utf16
argument_list|()
argument_list|)
argument_list|,
name|requestType
argument_list|,
name|DNS_QUERY_STANDARD
argument_list|,
name|NULL
argument_list|,
operator|&
name|dns_records
argument_list|,
name|NULL
argument_list|)
decl_stmt|;
switch|switch
condition|(
name|status
condition|)
block|{
case|case
name|ERROR_SUCCESS
case|:
break|break;
case|case
name|DNS_ERROR_RCODE_FORMAT_ERROR
case|:
name|reply
operator|->
name|error
operator|=
name|QDnsLookup
operator|::
name|InvalidRequestError
expr_stmt|;
name|reply
operator|->
name|errorString
operator|=
name|tr
argument_list|(
literal|"Server could not process query"
argument_list|)
expr_stmt|;
return|return;
case|case
name|DNS_ERROR_RCODE_SERVER_FAILURE
case|:
name|reply
operator|->
name|error
operator|=
name|QDnsLookup
operator|::
name|ServerFailureError
expr_stmt|;
name|reply
operator|->
name|errorString
operator|=
name|tr
argument_list|(
literal|"Server failure"
argument_list|)
expr_stmt|;
return|return;
case|case
name|DNS_ERROR_RCODE_NAME_ERROR
case|:
name|reply
operator|->
name|error
operator|=
name|QDnsLookup
operator|::
name|NotFoundError
expr_stmt|;
name|reply
operator|->
name|errorString
operator|=
name|tr
argument_list|(
literal|"Non existent domain"
argument_list|)
expr_stmt|;
return|return;
case|case
name|DNS_ERROR_RCODE_REFUSED
case|:
name|reply
operator|->
name|error
operator|=
name|QDnsLookup
operator|::
name|ServerRefusedError
expr_stmt|;
name|reply
operator|->
name|errorString
operator|=
name|tr
argument_list|(
literal|"Server refused to answer"
argument_list|)
expr_stmt|;
return|return;
default|default:
name|reply
operator|->
name|error
operator|=
name|QDnsLookup
operator|::
name|InvalidReplyError
expr_stmt|;
name|reply
operator|->
name|errorString
operator|=
name|QSystemError
argument_list|(
name|status
argument_list|,
name|QSystemError
operator|::
name|NativeError
argument_list|)
operator|.
name|toString
argument_list|()
expr_stmt|;
return|return;
block|}
comment|// Extract results.
for|for
control|(
name|PDNS_RECORD
name|ptr
init|=
name|dns_records
init|;
name|ptr
operator|!=
name|NULL
condition|;
name|ptr
operator|=
name|ptr
operator|->
name|pNext
control|)
block|{
specifier|const
name|QString
name|name
init|=
name|QUrl
operator|::
name|fromAce
argument_list|(
name|QString
operator|::
name|fromWCharArray
argument_list|(
name|ptr
operator|->
name|pName
argument_list|)
operator|.
name|toLatin1
argument_list|()
argument_list|)
decl_stmt|;
if|if
condition|(
name|ptr
operator|->
name|wType
operator|==
name|QDnsLookup
operator|::
name|A
condition|)
block|{
name|QDnsHostAddressRecord
name|record
decl_stmt|;
name|record
operator|.
name|d
operator|->
name|name
operator|=
name|name
expr_stmt|;
name|record
operator|.
name|d
operator|->
name|timeToLive
operator|=
name|ptr
operator|->
name|dwTtl
expr_stmt|;
name|record
operator|.
name|d
operator|->
name|value
operator|=
name|QHostAddress
argument_list|(
name|ntohl
argument_list|(
name|ptr
operator|->
name|Data
operator|.
name|A
operator|.
name|IpAddress
argument_list|)
argument_list|)
expr_stmt|;
name|reply
operator|->
name|hostAddressRecords
operator|.
name|append
argument_list|(
name|record
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|ptr
operator|->
name|wType
operator|==
name|QDnsLookup
operator|::
name|AAAA
condition|)
block|{
name|Q_IPV6ADDR
name|addr
decl_stmt|;
name|memcpy
argument_list|(
operator|&
name|addr
argument_list|,
operator|&
name|ptr
operator|->
name|Data
operator|.
name|AAAA
operator|.
name|Ip6Address
argument_list|,
sizeof|sizeof
argument_list|(
name|Q_IPV6ADDR
argument_list|)
argument_list|)
expr_stmt|;
name|QDnsHostAddressRecord
name|record
decl_stmt|;
name|record
operator|.
name|d
operator|->
name|name
operator|=
name|name
expr_stmt|;
name|record
operator|.
name|d
operator|->
name|timeToLive
operator|=
name|ptr
operator|->
name|dwTtl
expr_stmt|;
name|record
operator|.
name|d
operator|->
name|value
operator|=
name|QHostAddress
argument_list|(
name|addr
argument_list|)
expr_stmt|;
name|reply
operator|->
name|hostAddressRecords
operator|.
name|append
argument_list|(
name|record
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|ptr
operator|->
name|wType
operator|==
name|QDnsLookup
operator|::
name|CNAME
condition|)
block|{
name|QDnsDomainNameRecord
name|record
decl_stmt|;
name|record
operator|.
name|d
operator|->
name|name
operator|=
name|name
expr_stmt|;
name|record
operator|.
name|d
operator|->
name|timeToLive
operator|=
name|ptr
operator|->
name|dwTtl
expr_stmt|;
name|record
operator|.
name|d
operator|->
name|value
operator|=
name|QUrl
operator|::
name|fromAce
argument_list|(
name|QString
operator|::
name|fromWCharArray
argument_list|(
name|ptr
operator|->
name|Data
operator|.
name|Cname
operator|.
name|pNameHost
argument_list|)
operator|.
name|toLatin1
argument_list|()
argument_list|)
expr_stmt|;
name|reply
operator|->
name|canonicalNameRecords
operator|.
name|append
argument_list|(
name|record
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|ptr
operator|->
name|wType
operator|==
name|QDnsLookup
operator|::
name|MX
condition|)
block|{
name|QDnsMailExchangeRecord
name|record
decl_stmt|;
name|record
operator|.
name|d
operator|->
name|name
operator|=
name|name
expr_stmt|;
name|record
operator|.
name|d
operator|->
name|exchange
operator|=
name|QUrl
operator|::
name|fromAce
argument_list|(
name|QString
operator|::
name|fromWCharArray
argument_list|(
name|ptr
operator|->
name|Data
operator|.
name|Mx
operator|.
name|pNameExchange
argument_list|)
operator|.
name|toLatin1
argument_list|()
argument_list|)
expr_stmt|;
name|record
operator|.
name|d
operator|->
name|preference
operator|=
name|ptr
operator|->
name|Data
operator|.
name|Mx
operator|.
name|wPreference
expr_stmt|;
name|record
operator|.
name|d
operator|->
name|timeToLive
operator|=
name|ptr
operator|->
name|dwTtl
expr_stmt|;
name|reply
operator|->
name|mailExchangeRecords
operator|.
name|append
argument_list|(
name|record
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|ptr
operator|->
name|wType
operator|==
name|QDnsLookup
operator|::
name|NS
condition|)
block|{
name|QDnsDomainNameRecord
name|record
decl_stmt|;
name|record
operator|.
name|d
operator|->
name|name
operator|=
name|name
expr_stmt|;
name|record
operator|.
name|d
operator|->
name|timeToLive
operator|=
name|ptr
operator|->
name|dwTtl
expr_stmt|;
name|record
operator|.
name|d
operator|->
name|value
operator|=
name|QUrl
operator|::
name|fromAce
argument_list|(
name|QString
operator|::
name|fromWCharArray
argument_list|(
name|ptr
operator|->
name|Data
operator|.
name|Ns
operator|.
name|pNameHost
argument_list|)
operator|.
name|toLatin1
argument_list|()
argument_list|)
expr_stmt|;
name|reply
operator|->
name|nameServerRecords
operator|.
name|append
argument_list|(
name|record
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|ptr
operator|->
name|wType
operator|==
name|QDnsLookup
operator|::
name|PTR
condition|)
block|{
name|QDnsDomainNameRecord
name|record
decl_stmt|;
name|record
operator|.
name|d
operator|->
name|name
operator|=
name|name
expr_stmt|;
name|record
operator|.
name|d
operator|->
name|timeToLive
operator|=
name|ptr
operator|->
name|dwTtl
expr_stmt|;
name|record
operator|.
name|d
operator|->
name|value
operator|=
name|QUrl
operator|::
name|fromAce
argument_list|(
name|QString
operator|::
name|fromWCharArray
argument_list|(
name|ptr
operator|->
name|Data
operator|.
name|Ptr
operator|.
name|pNameHost
argument_list|)
operator|.
name|toLatin1
argument_list|()
argument_list|)
expr_stmt|;
name|reply
operator|->
name|pointerRecords
operator|.
name|append
argument_list|(
name|record
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|ptr
operator|->
name|wType
operator|==
name|QDnsLookup
operator|::
name|SRV
condition|)
block|{
name|QDnsServiceRecord
name|record
decl_stmt|;
name|record
operator|.
name|d
operator|->
name|name
operator|=
name|name
expr_stmt|;
name|record
operator|.
name|d
operator|->
name|target
operator|=
name|QUrl
operator|::
name|fromAce
argument_list|(
name|QString
operator|::
name|fromWCharArray
argument_list|(
name|ptr
operator|->
name|Data
operator|.
name|Srv
operator|.
name|pNameTarget
argument_list|)
operator|.
name|toLatin1
argument_list|()
argument_list|)
expr_stmt|;
name|record
operator|.
name|d
operator|->
name|port
operator|=
name|ptr
operator|->
name|Data
operator|.
name|Srv
operator|.
name|wPort
expr_stmt|;
name|record
operator|.
name|d
operator|->
name|priority
operator|=
name|ptr
operator|->
name|Data
operator|.
name|Srv
operator|.
name|wPriority
expr_stmt|;
name|record
operator|.
name|d
operator|->
name|timeToLive
operator|=
name|ptr
operator|->
name|dwTtl
expr_stmt|;
name|record
operator|.
name|d
operator|->
name|weight
operator|=
name|ptr
operator|->
name|Data
operator|.
name|Srv
operator|.
name|wWeight
expr_stmt|;
name|reply
operator|->
name|serviceRecords
operator|.
name|append
argument_list|(
name|record
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|ptr
operator|->
name|wType
operator|==
name|QDnsLookup
operator|::
name|TXT
condition|)
block|{
name|QDnsTextRecord
name|record
decl_stmt|;
name|record
operator|.
name|d
operator|->
name|name
operator|=
name|name
expr_stmt|;
name|record
operator|.
name|d
operator|->
name|timeToLive
operator|=
name|ptr
operator|->
name|dwTtl
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
name|ptr
operator|->
name|Data
operator|.
name|Txt
operator|.
name|dwStringCount
condition|;
operator|++
name|i
control|)
block|{
name|record
operator|.
name|d
operator|->
name|values
operator|<<
name|QString
operator|::
name|fromWCharArray
argument_list|(
operator|(
name|ptr
operator|->
name|Data
operator|.
name|Txt
operator|.
name|pStringArray
index|[
name|i
index|]
operator|)
argument_list|)
operator|.
name|toLatin1
argument_list|()
expr_stmt|;
empty_stmt|;
block|}
name|reply
operator|->
name|textRecords
operator|.
name|append
argument_list|(
name|record
argument_list|)
expr_stmt|;
block|}
block|}
name|DnsRecordListFree
argument_list|(
name|dns_records
argument_list|,
name|DnsFreeRecordList
argument_list|)
expr_stmt|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
