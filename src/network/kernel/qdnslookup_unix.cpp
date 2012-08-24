begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Jeremy LainÃ©<jeremy.laine@m4x.org> ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtNetwork module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qdnslookup_p.h"
end_include
begin_include
include|#
directive|include
file|<qlibrary.h>
end_include
begin_include
include|#
directive|include
file|<qscopedpointer.h>
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
file|<sys/types.h>
end_include
begin_include
include|#
directive|include
file|<netinet/in.h>
end_include
begin_include
include|#
directive|include
file|<arpa/nameser.h>
end_include
begin_include
include|#
directive|include
file|<arpa/nameser_compat.h>
end_include
begin_include
include|#
directive|include
file|<resolv.h>
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_LIBRARY
end_ifndef
begin_typedef
DECL|typedef|dn_expand_proto
typedef|typedef
name|int
function_decl|(
modifier|*
name|dn_expand_proto
function_decl|)
parameter_list|(
specifier|const
name|unsigned
name|char
modifier|*
parameter_list|,
specifier|const
name|unsigned
name|char
modifier|*
parameter_list|,
specifier|const
name|unsigned
name|char
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_typedef
begin_decl_stmt
DECL|variable|local_dn_expand
specifier|static
name|dn_expand_proto
name|local_dn_expand
init|=
literal|0
decl_stmt|;
end_decl_stmt
begin_typedef
DECL|typedef|res_nclose_proto
typedef|typedef
name|void
function_decl|(
modifier|*
name|res_nclose_proto
function_decl|)
parameter_list|(
name|res_state
parameter_list|)
function_decl|;
end_typedef
begin_decl_stmt
DECL|variable|local_res_nclose
specifier|static
name|res_nclose_proto
name|local_res_nclose
init|=
literal|0
decl_stmt|;
end_decl_stmt
begin_typedef
DECL|typedef|res_ninit_proto
typedef|typedef
name|int
function_decl|(
modifier|*
name|res_ninit_proto
function_decl|)
parameter_list|(
name|res_state
parameter_list|)
function_decl|;
end_typedef
begin_decl_stmt
DECL|variable|local_res_ninit
specifier|static
name|res_ninit_proto
name|local_res_ninit
init|=
literal|0
decl_stmt|;
end_decl_stmt
begin_typedef
DECL|typedef|res_nquery_proto
typedef|typedef
name|int
function_decl|(
modifier|*
name|res_nquery_proto
function_decl|)
parameter_list|(
name|res_state
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|unsigned
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_typedef
begin_decl_stmt
DECL|variable|local_res_nquery
specifier|static
name|res_nquery_proto
name|local_res_nquery
init|=
literal|0
decl_stmt|;
end_decl_stmt
begin_comment
comment|// Custom deleter to close resolver state.
end_comment
begin_struct
DECL|struct|QDnsLookupStateDeleter
struct|struct
name|QDnsLookupStateDeleter
block|{
DECL|function|cleanup
specifier|static
specifier|inline
name|void
name|cleanup
parameter_list|(
name|struct
name|__res_state
modifier|*
name|pointer
parameter_list|)
block|{
name|local_res_nclose
argument_list|(
name|pointer
argument_list|)
expr_stmt|;
block|}
block|}
struct|;
end_struct
begin_function
DECL|function|resolveLibrary
specifier|static
name|void
name|resolveLibrary
parameter_list|()
block|{
name|QLibrary
name|lib
argument_list|(
name|QLatin1String
argument_list|(
literal|"resolv"
argument_list|)
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|lib
operator|.
name|load
argument_list|()
condition|)
return|return;
name|local_dn_expand
operator|=
name|dn_expand_proto
argument_list|(
name|lib
operator|.
name|resolve
argument_list|(
literal|"__dn_expand"
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|local_dn_expand
condition|)
name|local_dn_expand
operator|=
name|dn_expand_proto
argument_list|(
name|lib
operator|.
name|resolve
argument_list|(
literal|"dn_expand"
argument_list|)
argument_list|)
expr_stmt|;
name|local_res_nclose
operator|=
name|res_nclose_proto
argument_list|(
name|lib
operator|.
name|resolve
argument_list|(
literal|"__res_nclose"
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|local_res_nclose
condition|)
name|local_res_nclose
operator|=
name|res_nclose_proto
argument_list|(
name|lib
operator|.
name|resolve
argument_list|(
literal|"res_9_nclose"
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|local_res_nclose
condition|)
name|local_res_nclose
operator|=
name|res_nclose_proto
argument_list|(
name|lib
operator|.
name|resolve
argument_list|(
literal|"res_nclose"
argument_list|)
argument_list|)
expr_stmt|;
name|local_res_ninit
operator|=
name|res_ninit_proto
argument_list|(
name|lib
operator|.
name|resolve
argument_list|(
literal|"__res_ninit"
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|local_res_ninit
condition|)
name|local_res_ninit
operator|=
name|res_ninit_proto
argument_list|(
name|lib
operator|.
name|resolve
argument_list|(
literal|"res_9_ninit"
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|local_res_ninit
condition|)
name|local_res_ninit
operator|=
name|res_ninit_proto
argument_list|(
name|lib
operator|.
name|resolve
argument_list|(
literal|"res_ninit"
argument_list|)
argument_list|)
expr_stmt|;
name|local_res_nquery
operator|=
name|res_nquery_proto
argument_list|(
name|lib
operator|.
name|resolve
argument_list|(
literal|"__res_nquery"
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|local_res_nquery
condition|)
name|local_res_nquery
operator|=
name|res_nquery_proto
argument_list|(
name|lib
operator|.
name|resolve
argument_list|(
literal|"res_9_nquery"
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|local_res_nquery
condition|)
name|local_res_nquery
operator|=
name|res_nquery_proto
argument_list|(
name|lib
operator|.
name|resolve
argument_list|(
literal|"res_nquery"
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
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
comment|// Load dn_expand, res_ninit and res_nquery on demand.
specifier|static
name|QBasicAtomicInt
name|triedResolve
init|=
name|Q_BASIC_ATOMIC_INITIALIZER
argument_list|(
literal|false
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|triedResolve
operator|.
name|loadAcquire
argument_list|()
condition|)
block|{
name|QMutexLocker
name|locker
argument_list|(
name|QMutexPool
operator|::
name|globalInstanceGet
argument_list|(
operator|&
name|local_res_ninit
argument_list|)
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|triedResolve
operator|.
name|load
argument_list|()
condition|)
block|{
name|resolveLibrary
argument_list|()
expr_stmt|;
name|triedResolve
operator|.
name|storeRelease
argument_list|(
literal|true
argument_list|)
expr_stmt|;
block|}
block|}
comment|// If dn_expand, res_ninit or res_nquery is missing, fail.
if|if
condition|(
operator|!
name|local_dn_expand
operator|||
operator|!
name|local_res_nclose
operator|||
operator|!
name|local_res_ninit
operator|||
operator|!
name|local_res_nquery
condition|)
block|{
name|reply
operator|->
name|error
operator|=
name|QDnsLookup
operator|::
name|ResolverError
expr_stmt|;
name|reply
operator|->
name|errorString
operator|=
name|tr
argument_list|(
literal|"Resolver functions not found"
argument_list|)
expr_stmt|;
return|return;
block|}
comment|// Initialize state.
name|struct
name|__res_state
name|state
decl_stmt|;
name|memset
argument_list|(
operator|&
name|state
argument_list|,
literal|0
argument_list|,
sizeof|sizeof
argument_list|(
name|state
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|local_res_ninit
argument_list|(
operator|&
name|state
argument_list|)
operator|<
literal|0
condition|)
block|{
name|reply
operator|->
name|error
operator|=
name|QDnsLookup
operator|::
name|ResolverError
expr_stmt|;
name|reply
operator|->
name|errorString
operator|=
name|tr
argument_list|(
literal|"Resolver initialization failed"
argument_list|)
expr_stmt|;
return|return;
block|}
ifdef|#
directive|ifdef
name|QDNSLOOKUP_DEBUG
name|state
operator|.
name|options
operator||=
name|RES_DEBUG
expr_stmt|;
endif|#
directive|endif
name|QScopedPointer
argument_list|<
expr|struct
name|__res_state
argument_list|,
name|QDnsLookupStateDeleter
argument_list|>
name|state_ptr
argument_list|(
operator|&
name|state
argument_list|)
decl_stmt|;
comment|// Perform DNS query.
name|unsigned
name|char
name|response
index|[
name|PACKETSZ
index|]
decl_stmt|;
name|memset
argument_list|(
name|response
argument_list|,
literal|0
argument_list|,
sizeof|sizeof
argument_list|(
name|response
argument_list|)
argument_list|)
expr_stmt|;
specifier|const
name|int
name|responseLength
init|=
name|local_res_nquery
argument_list|(
operator|&
name|state
argument_list|,
name|requestName
argument_list|,
name|C_IN
argument_list|,
name|requestType
argument_list|,
name|response
argument_list|,
sizeof|sizeof
argument_list|(
name|response
argument_list|)
argument_list|)
decl_stmt|;
comment|// Check the response header.
name|HEADER
modifier|*
name|header
init|=
operator|(
name|HEADER
operator|*
operator|)
name|response
decl_stmt|;
specifier|const
name|int
name|answerCount
init|=
name|ntohs
argument_list|(
name|header
operator|->
name|ancount
argument_list|)
decl_stmt|;
switch|switch
condition|(
name|header
operator|->
name|rcode
condition|)
block|{
case|case
name|NOERROR
case|:
break|break;
case|case
name|FORMERR
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
name|SERVFAIL
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
name|NXDOMAIN
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
name|REFUSED
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
name|tr
argument_list|(
literal|"Invalid reply received"
argument_list|)
expr_stmt|;
return|return;
block|}
comment|// Check the reply is valid.
if|if
condition|(
name|responseLength
operator|<
name|int
argument_list|(
sizeof|sizeof
argument_list|(
name|HEADER
argument_list|)
argument_list|)
condition|)
block|{
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
name|tr
argument_list|(
literal|"Invalid reply received"
argument_list|)
expr_stmt|;
return|return;
block|}
comment|// Skip the query host, type (2 bytes) and class (2 bytes).
name|char
name|host
index|[
name|PACKETSZ
index|]
decl_stmt|,
name|answer
index|[
name|PACKETSZ
index|]
decl_stmt|;
name|unsigned
name|char
modifier|*
name|p
init|=
name|response
operator|+
sizeof|sizeof
argument_list|(
name|HEADER
argument_list|)
decl_stmt|;
name|int
name|status
init|=
name|local_dn_expand
argument_list|(
name|response
argument_list|,
name|response
operator|+
name|responseLength
argument_list|,
name|p
argument_list|,
name|host
argument_list|,
sizeof|sizeof
argument_list|(
name|host
argument_list|)
argument_list|)
decl_stmt|;
if|if
condition|(
name|status
operator|<
literal|0
condition|)
block|{
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
name|tr
argument_list|(
literal|"Could not expand domain name"
argument_list|)
expr_stmt|;
return|return;
block|}
name|p
operator|+=
name|status
operator|+
literal|4
expr_stmt|;
comment|// Extract results.
name|int
name|answerIndex
init|=
literal|0
decl_stmt|;
while|while
condition|(
operator|(
name|p
operator|<
name|response
operator|+
name|responseLength
operator|)
operator|&&
operator|(
name|answerIndex
operator|<
name|answerCount
operator|)
condition|)
block|{
name|status
operator|=
name|local_dn_expand
argument_list|(
name|response
argument_list|,
name|response
operator|+
name|responseLength
argument_list|,
name|p
argument_list|,
name|host
argument_list|,
sizeof|sizeof
argument_list|(
name|host
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|status
operator|<
literal|0
condition|)
block|{
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
name|tr
argument_list|(
literal|"Could not expand domain name"
argument_list|)
expr_stmt|;
return|return;
block|}
specifier|const
name|QString
name|name
init|=
name|QUrl
operator|::
name|fromAce
argument_list|(
name|host
argument_list|)
decl_stmt|;
name|p
operator|+=
name|status
expr_stmt|;
specifier|const
name|quint16
name|type
init|=
operator|(
name|p
index|[
literal|0
index|]
operator|<<
literal|8
operator|)
operator||
name|p
index|[
literal|1
index|]
decl_stmt|;
name|p
operator|+=
literal|2
expr_stmt|;
comment|// RR type
name|p
operator|+=
literal|2
expr_stmt|;
comment|// RR class
specifier|const
name|quint32
name|ttl
init|=
operator|(
name|p
index|[
literal|0
index|]
operator|<<
literal|24
operator|)
operator||
operator|(
name|p
index|[
literal|1
index|]
operator|<<
literal|16
operator|)
operator||
operator|(
name|p
index|[
literal|2
index|]
operator|<<
literal|8
operator|)
operator||
name|p
index|[
literal|3
index|]
decl_stmt|;
name|p
operator|+=
literal|4
expr_stmt|;
specifier|const
name|quint16
name|size
init|=
operator|(
name|p
index|[
literal|0
index|]
operator|<<
literal|8
operator|)
operator||
name|p
index|[
literal|1
index|]
decl_stmt|;
name|p
operator|+=
literal|2
expr_stmt|;
if|if
condition|(
name|type
operator|==
name|QDnsLookup
operator|::
name|A
condition|)
block|{
if|if
condition|(
name|size
operator|!=
literal|4
condition|)
block|{
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
name|tr
argument_list|(
literal|"Invalid IPv4 address record"
argument_list|)
expr_stmt|;
return|return;
block|}
specifier|const
name|quint32
name|addr
init|=
operator|(
name|p
index|[
literal|0
index|]
operator|<<
literal|24
operator|)
operator||
operator|(
name|p
index|[
literal|1
index|]
operator|<<
literal|16
operator|)
operator||
operator|(
name|p
index|[
literal|2
index|]
operator|<<
literal|8
operator|)
operator||
name|p
index|[
literal|3
index|]
decl_stmt|;
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
name|ttl
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
name|type
operator|==
name|QDnsLookup
operator|::
name|AAAA
condition|)
block|{
if|if
condition|(
name|size
operator|!=
literal|16
condition|)
block|{
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
name|tr
argument_list|(
literal|"Invalid IPv6 address record"
argument_list|)
expr_stmt|;
return|return;
block|}
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
name|ttl
expr_stmt|;
name|record
operator|.
name|d
operator|->
name|value
operator|=
name|QHostAddress
argument_list|(
name|p
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
name|type
operator|==
name|QDnsLookup
operator|::
name|CNAME
condition|)
block|{
name|status
operator|=
name|local_dn_expand
argument_list|(
name|response
argument_list|,
name|response
operator|+
name|responseLength
argument_list|,
name|p
argument_list|,
name|answer
argument_list|,
sizeof|sizeof
argument_list|(
name|answer
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|status
operator|<
literal|0
condition|)
block|{
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
name|tr
argument_list|(
literal|"Invalid canonical name record"
argument_list|)
expr_stmt|;
return|return;
block|}
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
name|ttl
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
name|answer
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
name|type
operator|==
name|QDnsLookup
operator|::
name|NS
condition|)
block|{
name|status
operator|=
name|local_dn_expand
argument_list|(
name|response
argument_list|,
name|response
operator|+
name|responseLength
argument_list|,
name|p
argument_list|,
name|answer
argument_list|,
sizeof|sizeof
argument_list|(
name|answer
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|status
operator|<
literal|0
condition|)
block|{
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
name|tr
argument_list|(
literal|"Invalid name server record"
argument_list|)
expr_stmt|;
return|return;
block|}
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
name|ttl
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
name|answer
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
name|type
operator|==
name|QDnsLookup
operator|::
name|PTR
condition|)
block|{
name|status
operator|=
name|local_dn_expand
argument_list|(
name|response
argument_list|,
name|response
operator|+
name|responseLength
argument_list|,
name|p
argument_list|,
name|answer
argument_list|,
sizeof|sizeof
argument_list|(
name|answer
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|status
operator|<
literal|0
condition|)
block|{
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
name|tr
argument_list|(
literal|"Invalid pointer record"
argument_list|)
expr_stmt|;
return|return;
block|}
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
name|ttl
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
name|answer
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
name|type
operator|==
name|QDnsLookup
operator|::
name|MX
condition|)
block|{
specifier|const
name|quint16
name|preference
init|=
operator|(
name|p
index|[
literal|0
index|]
operator|<<
literal|8
operator|)
operator||
name|p
index|[
literal|1
index|]
decl_stmt|;
name|status
operator|=
name|local_dn_expand
argument_list|(
name|response
argument_list|,
name|response
operator|+
name|responseLength
argument_list|,
name|p
operator|+
literal|2
argument_list|,
name|answer
argument_list|,
sizeof|sizeof
argument_list|(
name|answer
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|status
operator|<
literal|0
condition|)
block|{
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
name|tr
argument_list|(
literal|"Invalid mail exchange record"
argument_list|)
expr_stmt|;
return|return;
block|}
name|QDnsMailExchangeRecord
name|record
decl_stmt|;
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
name|answer
argument_list|)
expr_stmt|;
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
name|preference
operator|=
name|preference
expr_stmt|;
name|record
operator|.
name|d
operator|->
name|timeToLive
operator|=
name|ttl
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
name|type
operator|==
name|QDnsLookup
operator|::
name|SRV
condition|)
block|{
specifier|const
name|quint16
name|priority
init|=
operator|(
name|p
index|[
literal|0
index|]
operator|<<
literal|8
operator|)
operator||
name|p
index|[
literal|1
index|]
decl_stmt|;
specifier|const
name|quint16
name|weight
init|=
operator|(
name|p
index|[
literal|2
index|]
operator|<<
literal|8
operator|)
operator||
name|p
index|[
literal|3
index|]
decl_stmt|;
specifier|const
name|quint16
name|port
init|=
operator|(
name|p
index|[
literal|4
index|]
operator|<<
literal|8
operator|)
operator||
name|p
index|[
literal|5
index|]
decl_stmt|;
name|status
operator|=
name|local_dn_expand
argument_list|(
name|response
argument_list|,
name|response
operator|+
name|responseLength
argument_list|,
name|p
operator|+
literal|6
argument_list|,
name|answer
argument_list|,
sizeof|sizeof
argument_list|(
name|answer
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|status
operator|<
literal|0
condition|)
block|{
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
name|tr
argument_list|(
literal|"Invalid service record"
argument_list|)
expr_stmt|;
return|return;
block|}
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
name|answer
argument_list|)
expr_stmt|;
name|record
operator|.
name|d
operator|->
name|port
operator|=
name|port
expr_stmt|;
name|record
operator|.
name|d
operator|->
name|priority
operator|=
name|priority
expr_stmt|;
name|record
operator|.
name|d
operator|->
name|timeToLive
operator|=
name|ttl
expr_stmt|;
name|record
operator|.
name|d
operator|->
name|weight
operator|=
name|weight
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
name|type
operator|==
name|QDnsLookup
operator|::
name|TXT
condition|)
block|{
name|unsigned
name|char
modifier|*
name|txt
init|=
name|p
decl_stmt|;
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
name|ttl
expr_stmt|;
while|while
condition|(
name|txt
operator|<
name|p
operator|+
name|size
condition|)
block|{
specifier|const
name|unsigned
name|char
name|length
init|=
operator|*
name|txt
decl_stmt|;
name|txt
operator|++
expr_stmt|;
if|if
condition|(
name|txt
operator|+
name|length
operator|>
name|p
operator|+
name|size
condition|)
block|{
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
name|tr
argument_list|(
literal|"Invalid text record"
argument_list|)
expr_stmt|;
return|return;
block|}
name|record
operator|.
name|d
operator|->
name|values
operator|<<
name|QByteArray
argument_list|(
operator|(
name|char
operator|*
operator|)
name|txt
argument_list|,
name|length
argument_list|)
expr_stmt|;
name|txt
operator|+=
name|length
expr_stmt|;
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
name|p
operator|+=
name|size
expr_stmt|;
name|answerIndex
operator|++
expr_stmt|;
block|}
block|}
end_function
begin_else
else|#
directive|else
end_else
begin_function
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
name|Q_UNUSED
argument_list|(
argument|requestType
argument_list|)
name|Q_UNUSED
argument_list|(
argument|requestName
argument_list|)
name|reply
operator|->
name|error
operator|=
name|QDnsLookup
operator|::
name|ResolverError
expr_stmt|;
name|reply
operator|->
name|errorString
operator|=
name|tr
argument_list|(
literal|"Resolver library can't be loaded: No runtime library loading support"
argument_list|)
expr_stmt|;
return|return;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* ifndef QT_NO_LIBRARY */
end_comment
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
