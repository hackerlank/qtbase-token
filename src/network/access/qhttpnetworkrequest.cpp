begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtNetwork module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qhttpnetworkrequest_p.h"
end_include
begin_include
include|#
directive|include
file|"private/qnoncontiguousbytedevice_p.h"
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_HTTP
end_ifndef
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_constructor
DECL|function|QHttpNetworkRequestPrivate
name|QHttpNetworkRequestPrivate
operator|::
name|QHttpNetworkRequestPrivate
parameter_list|(
name|QHttpNetworkRequest
operator|::
name|Operation
name|op
parameter_list|,
name|QHttpNetworkRequest
operator|::
name|Priority
name|pri
parameter_list|,
specifier|const
name|QUrl
modifier|&
name|newUrl
parameter_list|)
member_init_list|:
name|QHttpNetworkHeaderPrivate
argument_list|(
name|newUrl
argument_list|)
member_init_list|,
name|operation
argument_list|(
name|op
argument_list|)
member_init_list|,
name|priority
argument_list|(
name|pri
argument_list|)
member_init_list|,
name|uploadByteDevice
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|autoDecompress
argument_list|(
literal|false
argument_list|)
member_init_list|,
name|pipeliningAllowed
argument_list|(
literal|false
argument_list|)
member_init_list|,
name|withCredentials
argument_list|(
literal|true
argument_list|)
block|{ }
end_constructor
begin_constructor
DECL|function|QHttpNetworkRequestPrivate
name|QHttpNetworkRequestPrivate
operator|::
name|QHttpNetworkRequestPrivate
parameter_list|(
specifier|const
name|QHttpNetworkRequestPrivate
modifier|&
name|other
parameter_list|)
member_init_list|:
name|QHttpNetworkHeaderPrivate
argument_list|(
name|other
argument_list|)
block|{
name|operation
operator|=
name|other
operator|.
name|operation
expr_stmt|;
name|priority
operator|=
name|other
operator|.
name|priority
expr_stmt|;
name|uploadByteDevice
operator|=
name|other
operator|.
name|uploadByteDevice
expr_stmt|;
name|autoDecompress
operator|=
name|other
operator|.
name|autoDecompress
expr_stmt|;
name|pipeliningAllowed
operator|=
name|other
operator|.
name|pipeliningAllowed
expr_stmt|;
name|customVerb
operator|=
name|other
operator|.
name|customVerb
expr_stmt|;
name|withCredentials
operator|=
name|other
operator|.
name|withCredentials
expr_stmt|;
name|ssl
operator|=
name|other
operator|.
name|ssl
expr_stmt|;
block|}
end_constructor
begin_destructor
DECL|function|~QHttpNetworkRequestPrivate
name|QHttpNetworkRequestPrivate
operator|::
name|~
name|QHttpNetworkRequestPrivate
parameter_list|()
block|{ }
end_destructor
begin_function
DECL|function|operator ==
name|bool
name|QHttpNetworkRequestPrivate
operator|::
name|operator
name|==
parameter_list|(
specifier|const
name|QHttpNetworkRequestPrivate
modifier|&
name|other
parameter_list|)
specifier|const
block|{
return|return
name|QHttpNetworkHeaderPrivate
operator|::
name|operator
name|==
argument_list|(
name|other
argument_list|)
operator|&&
operator|(
name|operation
operator|==
name|other
operator|.
name|operation
operator|)
operator|&&
operator|(
name|ssl
operator|==
name|other
operator|.
name|ssl
operator|)
operator|&&
operator|(
name|uploadByteDevice
operator|==
name|other
operator|.
name|uploadByteDevice
operator|)
return|;
block|}
end_function
begin_function
DECL|function|methodName
name|QByteArray
name|QHttpNetworkRequestPrivate
operator|::
name|methodName
parameter_list|()
specifier|const
block|{
switch|switch
condition|(
name|operation
condition|)
block|{
case|case
name|QHttpNetworkRequest
operator|::
name|Get
case|:
return|return
literal|"GET"
return|;
break|break;
case|case
name|QHttpNetworkRequest
operator|::
name|Head
case|:
return|return
literal|"HEAD"
return|;
break|break;
case|case
name|QHttpNetworkRequest
operator|::
name|Post
case|:
return|return
literal|"POST"
return|;
break|break;
case|case
name|QHttpNetworkRequest
operator|::
name|Options
case|:
return|return
literal|"OPTIONS"
return|;
break|break;
case|case
name|QHttpNetworkRequest
operator|::
name|Put
case|:
return|return
literal|"PUT"
return|;
break|break;
case|case
name|QHttpNetworkRequest
operator|::
name|Delete
case|:
return|return
literal|"DELETE"
return|;
break|break;
case|case
name|QHttpNetworkRequest
operator|::
name|Trace
case|:
return|return
literal|"TRACE"
return|;
break|break;
case|case
name|QHttpNetworkRequest
operator|::
name|Connect
case|:
return|return
literal|"CONNECT"
return|;
break|break;
case|case
name|QHttpNetworkRequest
operator|::
name|Custom
case|:
return|return
name|customVerb
return|;
break|break;
default|default:
break|break;
block|}
return|return
name|QByteArray
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|uri
name|QByteArray
name|QHttpNetworkRequestPrivate
operator|::
name|uri
parameter_list|(
name|bool
name|throughProxy
parameter_list|)
specifier|const
block|{
name|QUrl
operator|::
name|FormattingOptions
name|format
argument_list|(
name|QUrl
operator|::
name|RemoveFragment
operator||
name|QUrl
operator|::
name|RemoveUserInfo
operator||
name|QUrl
operator|::
name|FullyEncoded
argument_list|)
decl_stmt|;
comment|// for POST, query data is send as content
if|if
condition|(
name|operation
operator|==
name|QHttpNetworkRequest
operator|::
name|Post
operator|&&
operator|!
name|uploadByteDevice
condition|)
name|format
operator||=
name|QUrl
operator|::
name|RemoveQuery
expr_stmt|;
comment|// for requests through proxy, the Request-URI contains full url
if|if
condition|(
operator|!
name|throughProxy
condition|)
name|format
operator||=
name|QUrl
operator|::
name|RemoveScheme
operator||
name|QUrl
operator|::
name|RemoveAuthority
expr_stmt|;
name|QUrl
name|copy
init|=
name|url
decl_stmt|;
if|if
condition|(
name|copy
operator|.
name|path
argument_list|()
operator|.
name|isEmpty
argument_list|()
condition|)
name|copy
operator|.
name|setPath
argument_list|(
name|QStringLiteral
argument_list|(
literal|"/"
argument_list|)
argument_list|)
expr_stmt|;
name|QByteArray
name|uri
init|=
name|copy
operator|.
name|toEncoded
argument_list|(
name|format
argument_list|)
decl_stmt|;
return|return
name|uri
return|;
block|}
end_function
begin_function
DECL|function|header
name|QByteArray
name|QHttpNetworkRequestPrivate
operator|::
name|header
parameter_list|(
specifier|const
name|QHttpNetworkRequest
modifier|&
name|request
parameter_list|,
name|bool
name|throughProxy
parameter_list|)
block|{
name|QList
argument_list|<
name|QPair
argument_list|<
name|QByteArray
argument_list|,
name|QByteArray
argument_list|>
argument_list|>
name|fields
init|=
name|request
operator|.
name|header
argument_list|()
decl_stmt|;
name|QByteArray
name|ba
decl_stmt|;
name|ba
operator|.
name|reserve
argument_list|(
literal|40
operator|+
name|fields
operator|.
name|length
argument_list|()
operator|*
literal|25
argument_list|)
expr_stmt|;
comment|// very rough lower bound estimation
name|ba
operator|+=
name|request
operator|.
name|d
operator|->
name|methodName
argument_list|()
expr_stmt|;
name|ba
operator|+=
literal|' '
expr_stmt|;
name|ba
operator|+=
name|request
operator|.
name|d
operator|->
name|uri
argument_list|(
name|throughProxy
argument_list|)
expr_stmt|;
name|ba
operator|+=
literal|" HTTP/"
expr_stmt|;
name|ba
operator|+=
name|QByteArray
operator|::
name|number
argument_list|(
name|request
operator|.
name|majorVersion
argument_list|()
argument_list|)
expr_stmt|;
name|ba
operator|+=
literal|'.'
expr_stmt|;
name|ba
operator|+=
name|QByteArray
operator|::
name|number
argument_list|(
name|request
operator|.
name|minorVersion
argument_list|()
argument_list|)
expr_stmt|;
name|ba
operator|+=
literal|"\r\n"
expr_stmt|;
name|QList
argument_list|<
name|QPair
argument_list|<
name|QByteArray
argument_list|,
name|QByteArray
argument_list|>
argument_list|>
operator|::
name|const_iterator
name|it
init|=
name|fields
operator|.
name|constBegin
argument_list|()
decl_stmt|;
name|QList
argument_list|<
name|QPair
argument_list|<
name|QByteArray
argument_list|,
name|QByteArray
argument_list|>
argument_list|>
operator|::
name|const_iterator
name|endIt
init|=
name|fields
operator|.
name|constEnd
argument_list|()
decl_stmt|;
for|for
control|(
init|;
name|it
operator|!=
name|endIt
condition|;
operator|++
name|it
control|)
block|{
name|ba
operator|+=
name|it
operator|->
name|first
expr_stmt|;
name|ba
operator|+=
literal|": "
expr_stmt|;
name|ba
operator|+=
name|it
operator|->
name|second
expr_stmt|;
name|ba
operator|+=
literal|"\r\n"
expr_stmt|;
block|}
if|if
condition|(
name|request
operator|.
name|d
operator|->
name|operation
operator|==
name|QHttpNetworkRequest
operator|::
name|Post
condition|)
block|{
comment|// add content type, if not set in the request
if|if
condition|(
name|request
operator|.
name|headerField
argument_list|(
literal|"content-type"
argument_list|)
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|qWarning
argument_list|(
literal|"content-type missing in HTTP POST, defaulting to application/octet-stream"
argument_list|)
expr_stmt|;
name|ba
operator|+=
literal|"Content-Type: application/octet-stream\r\n"
expr_stmt|;
block|}
if|if
condition|(
operator|!
name|request
operator|.
name|d
operator|->
name|uploadByteDevice
operator|&&
name|request
operator|.
name|d
operator|->
name|url
operator|.
name|hasQuery
argument_list|()
condition|)
block|{
name|QByteArray
name|query
init|=
name|request
operator|.
name|d
operator|->
name|url
operator|.
name|query
argument_list|(
name|QUrl
operator|::
name|FullyEncoded
argument_list|)
operator|.
name|toLatin1
argument_list|()
decl_stmt|;
name|ba
operator|+=
literal|"Content-Length: "
expr_stmt|;
name|ba
operator|+=
name|QByteArray
operator|::
name|number
argument_list|(
name|query
operator|.
name|size
argument_list|()
argument_list|)
expr_stmt|;
name|ba
operator|+=
literal|"\r\n\r\n"
expr_stmt|;
name|ba
operator|+=
name|query
expr_stmt|;
block|}
else|else
block|{
name|ba
operator|+=
literal|"\r\n"
expr_stmt|;
block|}
block|}
else|else
block|{
name|ba
operator|+=
literal|"\r\n"
expr_stmt|;
block|}
return|return
name|ba
return|;
block|}
end_function
begin_comment
comment|// QHttpNetworkRequest
end_comment
begin_constructor
DECL|function|QHttpNetworkRequest
name|QHttpNetworkRequest
operator|::
name|QHttpNetworkRequest
parameter_list|(
specifier|const
name|QUrl
modifier|&
name|url
parameter_list|,
name|Operation
name|operation
parameter_list|,
name|Priority
name|priority
parameter_list|)
member_init_list|:
name|d
argument_list|(
operator|new
name|QHttpNetworkRequestPrivate
argument_list|(
name|operation
argument_list|,
name|priority
argument_list|,
name|url
argument_list|)
argument_list|)
block|{ }
end_constructor
begin_constructor
DECL|function|QHttpNetworkRequest
name|QHttpNetworkRequest
operator|::
name|QHttpNetworkRequest
parameter_list|(
specifier|const
name|QHttpNetworkRequest
modifier|&
name|other
parameter_list|)
member_init_list|:
name|QHttpNetworkHeader
argument_list|(
name|other
argument_list|)
member_init_list|,
name|d
argument_list|(
name|other
operator|.
name|d
argument_list|)
block|{ }
end_constructor
begin_destructor
DECL|function|~QHttpNetworkRequest
name|QHttpNetworkRequest
operator|::
name|~
name|QHttpNetworkRequest
parameter_list|()
block|{ }
end_destructor
begin_function
DECL|function|url
name|QUrl
name|QHttpNetworkRequest
operator|::
name|url
parameter_list|()
specifier|const
block|{
return|return
name|d
operator|->
name|url
return|;
block|}
end_function
begin_function
DECL|function|setUrl
name|void
name|QHttpNetworkRequest
operator|::
name|setUrl
parameter_list|(
specifier|const
name|QUrl
modifier|&
name|url
parameter_list|)
block|{
name|d
operator|->
name|url
operator|=
name|url
expr_stmt|;
block|}
end_function
begin_function
DECL|function|isSsl
name|bool
name|QHttpNetworkRequest
operator|::
name|isSsl
parameter_list|()
specifier|const
block|{
return|return
name|d
operator|->
name|ssl
return|;
block|}
end_function
begin_function
DECL|function|setSsl
name|void
name|QHttpNetworkRequest
operator|::
name|setSsl
parameter_list|(
name|bool
name|s
parameter_list|)
block|{
name|d
operator|->
name|ssl
operator|=
name|s
expr_stmt|;
block|}
end_function
begin_function
DECL|function|contentLength
name|qint64
name|QHttpNetworkRequest
operator|::
name|contentLength
parameter_list|()
specifier|const
block|{
return|return
name|d
operator|->
name|contentLength
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|setContentLength
name|void
name|QHttpNetworkRequest
operator|::
name|setContentLength
parameter_list|(
name|qint64
name|length
parameter_list|)
block|{
name|d
operator|->
name|setContentLength
argument_list|(
name|length
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|header
name|QList
argument_list|<
name|QPair
argument_list|<
name|QByteArray
argument_list|,
name|QByteArray
argument_list|>
argument_list|>
name|QHttpNetworkRequest
operator|::
name|header
parameter_list|()
specifier|const
block|{
return|return
name|d
operator|->
name|fields
return|;
block|}
end_function
begin_function
DECL|function|headerField
name|QByteArray
name|QHttpNetworkRequest
operator|::
name|headerField
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|name
parameter_list|,
specifier|const
name|QByteArray
modifier|&
name|defaultValue
parameter_list|)
specifier|const
block|{
return|return
name|d
operator|->
name|headerField
argument_list|(
name|name
argument_list|,
name|defaultValue
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|setHeaderField
name|void
name|QHttpNetworkRequest
operator|::
name|setHeaderField
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|name
parameter_list|,
specifier|const
name|QByteArray
modifier|&
name|data
parameter_list|)
block|{
name|d
operator|->
name|setHeaderField
argument_list|(
name|name
argument_list|,
name|data
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|operator =
name|QHttpNetworkRequest
modifier|&
name|QHttpNetworkRequest
operator|::
name|operator
name|=
parameter_list|(
specifier|const
name|QHttpNetworkRequest
modifier|&
name|other
parameter_list|)
block|{
name|d
operator|=
name|other
operator|.
name|d
expr_stmt|;
return|return
operator|*
name|this
return|;
block|}
end_function
begin_function
DECL|function|operator ==
name|bool
name|QHttpNetworkRequest
operator|::
name|operator
name|==
parameter_list|(
specifier|const
name|QHttpNetworkRequest
modifier|&
name|other
parameter_list|)
specifier|const
block|{
return|return
name|d
operator|->
name|operator
name|==
argument_list|(
operator|*
name|other
operator|.
name|d
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|operation
name|QHttpNetworkRequest
operator|::
name|Operation
name|QHttpNetworkRequest
operator|::
name|operation
parameter_list|()
specifier|const
block|{
return|return
name|d
operator|->
name|operation
return|;
block|}
end_function
begin_function
DECL|function|setOperation
name|void
name|QHttpNetworkRequest
operator|::
name|setOperation
parameter_list|(
name|Operation
name|operation
parameter_list|)
block|{
name|d
operator|->
name|operation
operator|=
name|operation
expr_stmt|;
block|}
end_function
begin_function
DECL|function|customVerb
name|QByteArray
name|QHttpNetworkRequest
operator|::
name|customVerb
parameter_list|()
specifier|const
block|{
return|return
name|d
operator|->
name|customVerb
return|;
block|}
end_function
begin_function
DECL|function|setCustomVerb
name|void
name|QHttpNetworkRequest
operator|::
name|setCustomVerb
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|customVerb
parameter_list|)
block|{
name|d
operator|->
name|customVerb
operator|=
name|customVerb
expr_stmt|;
block|}
end_function
begin_function
DECL|function|priority
name|QHttpNetworkRequest
operator|::
name|Priority
name|QHttpNetworkRequest
operator|::
name|priority
parameter_list|()
specifier|const
block|{
return|return
name|d
operator|->
name|priority
return|;
block|}
end_function
begin_function
DECL|function|setPriority
name|void
name|QHttpNetworkRequest
operator|::
name|setPriority
parameter_list|(
name|Priority
name|priority
parameter_list|)
block|{
name|d
operator|->
name|priority
operator|=
name|priority
expr_stmt|;
block|}
end_function
begin_function
DECL|function|isPipeliningAllowed
name|bool
name|QHttpNetworkRequest
operator|::
name|isPipeliningAllowed
parameter_list|()
specifier|const
block|{
return|return
name|d
operator|->
name|pipeliningAllowed
return|;
block|}
end_function
begin_function
DECL|function|setPipeliningAllowed
name|void
name|QHttpNetworkRequest
operator|::
name|setPipeliningAllowed
parameter_list|(
name|bool
name|b
parameter_list|)
block|{
name|d
operator|->
name|pipeliningAllowed
operator|=
name|b
expr_stmt|;
block|}
end_function
begin_function
DECL|function|withCredentials
name|bool
name|QHttpNetworkRequest
operator|::
name|withCredentials
parameter_list|()
specifier|const
block|{
return|return
name|d
operator|->
name|withCredentials
return|;
block|}
end_function
begin_function
DECL|function|setWithCredentials
name|void
name|QHttpNetworkRequest
operator|::
name|setWithCredentials
parameter_list|(
name|bool
name|b
parameter_list|)
block|{
name|d
operator|->
name|withCredentials
operator|=
name|b
expr_stmt|;
block|}
end_function
begin_function
DECL|function|setUploadByteDevice
name|void
name|QHttpNetworkRequest
operator|::
name|setUploadByteDevice
parameter_list|(
name|QNonContiguousByteDevice
modifier|*
name|bd
parameter_list|)
block|{
name|d
operator|->
name|uploadByteDevice
operator|=
name|bd
expr_stmt|;
block|}
end_function
begin_function
DECL|function|uploadByteDevice
name|QNonContiguousByteDevice
modifier|*
name|QHttpNetworkRequest
operator|::
name|uploadByteDevice
parameter_list|()
specifier|const
block|{
return|return
name|d
operator|->
name|uploadByteDevice
return|;
block|}
end_function
begin_function
DECL|function|majorVersion
name|int
name|QHttpNetworkRequest
operator|::
name|majorVersion
parameter_list|()
specifier|const
block|{
return|return
literal|1
return|;
block|}
end_function
begin_function
DECL|function|minorVersion
name|int
name|QHttpNetworkRequest
operator|::
name|minorVersion
parameter_list|()
specifier|const
block|{
return|return
literal|1
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
end_unit
