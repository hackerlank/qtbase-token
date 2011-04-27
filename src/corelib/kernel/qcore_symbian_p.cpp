begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** No Commercial Usage ** This file contains pre-release code and may not be distributed. ** You may use this file in accordance with the terms and conditions ** contained in the Technology Preview License Agreement accompanying ** this package. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights.  These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** If you have questions regarding the use of this file, please contact ** Nokia at qt-info@nokia.com. ** ** ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<exception>
end_include
begin_include
include|#
directive|include
file|<e32base.h>
end_include
begin_include
include|#
directive|include
file|<e32uid.h>
end_include
begin_include
include|#
directive|include
file|"qcore_symbian_p.h"
end_include
begin_include
include|#
directive|include
file|<string>
end_include
begin_include
include|#
directive|include
file|<in_sock.h>
end_include
begin_function
name|QT_BEGIN_NAMESPACE
comment|/*     Helper function for calling into Symbian classes that expect a TDes&.     This function converts a QString to a TDes by allocating memory that     must be deleted by the caller. */
DECL|function|qt_QString2HBufC
name|Q_CORE_EXPORT
name|HBufC
modifier|*
name|qt_QString2HBufC
parameter_list|(
specifier|const
name|QString
modifier|&
name|aString
parameter_list|)
block|{
name|HBufC
modifier|*
name|buffer
decl_stmt|;
ifdef|#
directive|ifdef
name|QT_NO_UNICODE
name|TPtrC8
name|ptr
argument_list|(
cast|reinterpret_cast
argument_list|<
specifier|const
name|TUint8
operator|*
argument_list|>
argument_list|(
name|aString
operator|.
name|toLocal8Bit
argument_list|()
operator|.
name|constData
argument_list|()
argument_list|)
argument_list|)
decl_stmt|;
else|#
directive|else
name|TPtrC16
name|ptr
argument_list|(
name|qt_QString2TPtrC
argument_list|(
name|aString
argument_list|)
argument_list|)
decl_stmt|;
endif|#
directive|endif
name|buffer
operator|=
name|HBufC
operator|::
name|New
argument_list|(
name|ptr
operator|.
name|Length
argument_list|()
argument_list|)
expr_stmt|;
name|Q_CHECK_PTR
argument_list|(
name|buffer
argument_list|)
expr_stmt|;
name|buffer
operator|->
name|Des
argument_list|()
operator|.
name|Copy
argument_list|(
name|ptr
argument_list|)
expr_stmt|;
return|return
name|buffer
return|;
block|}
end_function
begin_function
DECL|function|qt_TDesC2QString
name|Q_CORE_EXPORT
name|QString
name|qt_TDesC2QString
parameter_list|(
specifier|const
name|TDesC
modifier|&
name|aDescriptor
parameter_list|)
block|{
ifdef|#
directive|ifdef
name|QT_NO_UNICODE
return|return
name|QString
operator|::
name|fromLocal8Bit
argument_list|(
name|aDescriptor
operator|.
name|Ptr
argument_list|()
argument_list|,
name|aDescriptor
operator|.
name|Length
argument_list|()
argument_list|)
return|;
else|#
directive|else
return|return
name|QString
argument_list|(
cast|reinterpret_cast
argument_list|<
specifier|const
name|QChar
operator|*
argument_list|>
argument_list|(
name|aDescriptor
operator|.
name|Ptr
argument_list|()
argument_list|)
argument_list|,
name|aDescriptor
operator|.
name|Length
argument_list|()
argument_list|)
return|;
endif|#
directive|endif
block|}
end_function
begin_constructor
DECL|function|QHBufC
name|QHBufC
operator|::
name|QHBufC
parameter_list|()
member_init_list|:
name|m_hBufC
argument_list|(
literal|0
argument_list|)
block|{ }
end_constructor
begin_constructor
DECL|function|QHBufC
name|QHBufC
operator|::
name|QHBufC
parameter_list|(
specifier|const
name|QHBufC
modifier|&
name|src
parameter_list|)
member_init_list|:
name|m_hBufC
argument_list|(
name|src
operator|.
name|m_hBufC
operator|->
name|Alloc
argument_list|()
argument_list|)
block|{
name|Q_CHECK_PTR
argument_list|(
name|m_hBufC
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_comment
comment|/*!   \internal   Constructs a QHBufC from an HBufC. Note that the QHBufC instance takes   ownership of the HBufC. */
end_comment
begin_constructor
DECL|function|QHBufC
name|QHBufC
operator|::
name|QHBufC
parameter_list|(
name|HBufC
modifier|*
name|src
parameter_list|)
member_init_list|:
name|m_hBufC
argument_list|(
name|src
argument_list|)
block|{ }
end_constructor
begin_constructor
DECL|function|QHBufC
name|QHBufC
operator|::
name|QHBufC
parameter_list|(
specifier|const
name|QString
modifier|&
name|src
parameter_list|)
block|{
name|m_hBufC
operator|=
name|qt_QString2HBufC
argument_list|(
name|src
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_destructor
DECL|function|~QHBufC
name|QHBufC
operator|::
name|~
name|QHBufC
parameter_list|()
block|{
if|if
condition|(
name|m_hBufC
condition|)
operator|delete
name|m_hBufC
expr_stmt|;
block|}
end_destructor
begin_class
DECL|class|QS60PluginResolver
class|class
name|QS60PluginResolver
block|{
public|public:
DECL|function|QS60PluginResolver
name|QS60PluginResolver
parameter_list|()
member_init_list|:
name|initTried
argument_list|(
literal|false
argument_list|)
block|{}
DECL|function|~QS60PluginResolver
name|~
name|QS60PluginResolver
parameter_list|()
block|{
name|lib
operator|.
name|Close
argument_list|()
expr_stmt|;
block|}
DECL|function|resolve
name|TLibraryFunction
name|resolve
parameter_list|(
name|int
name|ordinal
parameter_list|)
block|{
if|if
condition|(
operator|!
name|initTried
condition|)
block|{
name|init
argument_list|()
expr_stmt|;
name|initTried
operator|=
literal|true
expr_stmt|;
block|}
if|if
condition|(
name|lib
operator|.
name|Handle
argument_list|()
condition|)
return|return
name|lib
operator|.
name|Lookup
argument_list|(
name|ordinal
argument_list|)
return|;
else|else
return|return
cast|reinterpret_cast
argument_list|<
name|TLibraryFunction
argument_list|>
argument_list|(
name|NULL
argument_list|)
return|;
block|}
private|private:
DECL|function|init
name|void
name|init
parameter_list|()
block|{
name|_LIT
argument_list|(
name|KLibName_3_1
argument_list|,
literal|"qts60plugin_3_1"
name|QT_LIBINFIX_UNICODE
literal|L".dll"
argument_list|)
expr_stmt|;
name|_LIT
argument_list|(
name|KLibName_3_2
argument_list|,
literal|"qts60plugin_3_2"
name|QT_LIBINFIX_UNICODE
literal|L".dll"
argument_list|)
expr_stmt|;
name|_LIT
argument_list|(
name|KLibName_5_0
argument_list|,
literal|"qts60plugin_5_0"
name|QT_LIBINFIX_UNICODE
literal|L".dll"
argument_list|)
expr_stmt|;
name|TPtrC
name|libName
decl_stmt|;
name|TInt
name|uidValue
decl_stmt|;
switch|switch
condition|(
name|QSysInfo
operator|::
name|s60Version
argument_list|()
condition|)
block|{
case|case
name|QSysInfo
operator|::
name|SV_S60_3_1
case|:
name|libName
operator|.
name|Set
argument_list|(
name|KLibName_3_1
argument_list|)
expr_stmt|;
name|uidValue
operator|=
literal|0x2001E620
expr_stmt|;
break|break;
case|case
name|QSysInfo
operator|::
name|SV_S60_3_2
case|:
name|libName
operator|.
name|Set
argument_list|(
name|KLibName_3_2
argument_list|)
expr_stmt|;
name|uidValue
operator|=
literal|0x2001E621
expr_stmt|;
break|break;
case|case
name|QSysInfo
operator|::
name|SV_S60_5_0
case|:
comment|// Fall through to default
default|default:
comment|// Default to 5.0 version, as any unknown platform is likely to be newer than that
name|libName
operator|.
name|Set
argument_list|(
name|KLibName_5_0
argument_list|)
expr_stmt|;
name|uidValue
operator|=
literal|0x2001E622
expr_stmt|;
break|break;
block|}
name|TUidType
name|libUid
argument_list|(
name|KDynamicLibraryUid
argument_list|,
name|KSharedLibraryUid
argument_list|,
name|TUid
operator|::
name|Uid
argument_list|(
name|uidValue
argument_list|)
argument_list|)
decl_stmt|;
name|lib
operator|.
name|Load
argument_list|(
name|libName
argument_list|,
name|libUid
argument_list|)
expr_stmt|;
comment|// Duplicate lib handle to enable process wide access to it. Since Duplicate overwrites
comment|// existing handle without closing it, store original for subsequent closing.
name|RLibrary
name|origHandleCloser
init|=
name|lib
decl_stmt|;
name|lib
operator|.
name|Duplicate
argument_list|(
name|RThread
argument_list|()
argument_list|,
name|EOwnerProcess
argument_list|)
expr_stmt|;
name|origHandleCloser
operator|.
name|Close
argument_list|()
expr_stmt|;
block|}
DECL|member|lib
name|RLibrary
name|lib
decl_stmt|;
DECL|member|initTried
name|bool
name|initTried
decl_stmt|;
block|}
class|;
end_class
begin_expr_stmt
name|Q_GLOBAL_STATIC
argument_list|(
name|QS60PluginResolver
argument_list|,
name|qt_s60_plugin_resolver
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|/*!   \internal   Resolves a platform version specific function from S60 plugin.   If plugin is missing or resolving fails for another reason, NULL is returned. */
end_comment
begin_function
DECL|function|qt_resolveS60PluginFunc
name|Q_CORE_EXPORT
name|TLibraryFunction
name|qt_resolveS60PluginFunc
parameter_list|(
name|int
name|ordinal
parameter_list|)
block|{
return|return
name|qt_s60_plugin_resolver
argument_list|()
operator|->
name|resolve
argument_list|(
name|ordinal
argument_list|)
return|;
block|}
end_function
begin_class
DECL|class|QS60RFsSession
class|class
name|QS60RFsSession
block|{
public|public:
DECL|function|QS60RFsSession
name|QS60RFsSession
parameter_list|()
block|{
name|qt_symbian_throwIfError
argument_list|(
name|iFs
operator|.
name|Connect
argument_list|()
argument_list|)
expr_stmt|;
name|qt_symbian_throwIfError
argument_list|(
name|iFs
operator|.
name|ShareProtected
argument_list|()
argument_list|)
expr_stmt|;
block|}
DECL|function|~QS60RFsSession
name|~
name|QS60RFsSession
parameter_list|()
block|{
name|iFs
operator|.
name|Close
argument_list|()
expr_stmt|;
block|}
DECL|function|GetRFs
name|RFs
modifier|&
name|GetRFs
parameter_list|()
block|{
return|return
name|iFs
return|;
block|}
private|private:
DECL|member|iFs
name|RFs
name|iFs
decl_stmt|;
block|}
class|;
end_class
begin_function
DECL|function|qHash
name|uint
name|qHash
parameter_list|(
specifier|const
name|RSubSessionBase
modifier|&
name|key
parameter_list|)
block|{
return|return
name|qHash
argument_list|(
name|key
operator|.
name|SubSessionHandle
argument_list|()
argument_list|)
return|;
block|}
end_function
begin_expr_stmt
name|Q_GLOBAL_STATIC
argument_list|(
name|QS60RFsSession
argument_list|,
name|qt_s60_RFsSession
argument_list|)
expr_stmt|;
end_expr_stmt
begin_function
DECL|function|qt_s60GetRFs
name|Q_CORE_EXPORT
name|RFs
modifier|&
name|qt_s60GetRFs
parameter_list|()
block|{
return|return
name|qt_s60_RFsSession
argument_list|()
operator|->
name|GetRFs
argument_list|()
return|;
block|}
end_function
begin_constructor
DECL|function|QSymbianSocketManager
name|QSymbianSocketManager
operator|::
name|QSymbianSocketManager
parameter_list|()
member_init_list|:
name|iNextSocket
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|iDefaultConnection
argument_list|(
literal|0
argument_list|)
block|{
name|TSessionPref
name|preferences
decl_stmt|;
comment|// ### In future this could be changed to KAfInet6 when that is more common than IPv4
name|preferences
operator|.
name|iAddrFamily
operator|=
name|KAfInet
expr_stmt|;
name|preferences
operator|.
name|iProtocol
operator|=
name|KProtocolInetIp
expr_stmt|;
comment|//use global message pool, as we do not know how many sockets app will use
comment|//TODO: is this the right choice?
name|qt_symbian_throwIfError
argument_list|(
name|iSocketServ
operator|.
name|Connect
argument_list|(
name|preferences
argument_list|,
operator|-
literal|1
argument_list|)
argument_list|)
expr_stmt|;
name|qt_symbian_throwIfError
argument_list|(
name|iSocketServ
operator|.
name|ShareAuto
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_destructor
DECL|function|~QSymbianSocketManager
name|QSymbianSocketManager
operator|::
name|~
name|QSymbianSocketManager
parameter_list|()
block|{
name|iSocketServ
operator|.
name|Close
argument_list|()
expr_stmt|;
if|if
condition|(
operator|!
name|socketMap
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|qWarning
argument_list|(
literal|"leaked %d sockets on exit"
argument_list|,
name|socketMap
operator|.
name|count
argument_list|()
argument_list|)
expr_stmt|;
block|}
block|}
end_destructor
begin_function
DECL|function|getSocketServer
name|RSocketServ
modifier|&
name|QSymbianSocketManager
operator|::
name|getSocketServer
parameter_list|()
block|{
return|return
name|iSocketServ
return|;
block|}
end_function
begin_function
DECL|function|addSocket
name|int
name|QSymbianSocketManager
operator|::
name|addSocket
parameter_list|(
specifier|const
name|RSocket
modifier|&
name|socket
parameter_list|)
block|{
name|QHashableSocket
name|sock
argument_list|(
cast|static_cast
argument_list|<
specifier|const
name|QHashableSocket
operator|&
argument_list|>
argument_list|(
name|socket
argument_list|)
argument_list|)
decl_stmt|;
name|QMutexLocker
name|l
argument_list|(
operator|&
name|iMutex
argument_list|)
decl_stmt|;
name|Q_ASSERT
argument_list|(
operator|!
name|socketMap
operator|.
name|contains
argument_list|(
name|sock
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|socketMap
operator|.
name|contains
argument_list|(
name|sock
argument_list|)
condition|)
return|return
name|socketMap
operator|.
name|value
argument_list|(
name|sock
argument_list|)
return|;
comment|// allocate socket number
name|int
name|guard
init|=
literal|0
decl_stmt|;
while|while
condition|(
name|reverseSocketMap
operator|.
name|contains
argument_list|(
name|iNextSocket
argument_list|)
condition|)
block|{
name|iNextSocket
operator|++
expr_stmt|;
name|iNextSocket
operator|%=
name|max_sockets
expr_stmt|;
name|guard
operator|++
expr_stmt|;
if|if
condition|(
name|guard
operator|>
name|max_sockets
condition|)
return|return
operator|-
literal|1
return|;
block|}
name|int
name|id
init|=
name|iNextSocket
decl_stmt|;
name|socketMap
index|[
name|sock
index|]
operator|=
name|id
expr_stmt|;
name|reverseSocketMap
index|[
name|id
index|]
operator|=
name|sock
expr_stmt|;
return|return
name|id
operator|+
name|socket_offset
return|;
block|}
end_function
begin_function
DECL|function|removeSocket
name|bool
name|QSymbianSocketManager
operator|::
name|removeSocket
parameter_list|(
specifier|const
name|RSocket
modifier|&
name|socket
parameter_list|)
block|{
name|QHashableSocket
name|sock
argument_list|(
cast|static_cast
argument_list|<
specifier|const
name|QHashableSocket
operator|&
argument_list|>
argument_list|(
name|socket
argument_list|)
argument_list|)
decl_stmt|;
name|QMutexLocker
name|l
argument_list|(
operator|&
name|iMutex
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|socketMap
operator|.
name|contains
argument_list|(
name|sock
argument_list|)
condition|)
return|return
literal|false
return|;
name|int
name|id
init|=
name|socketMap
operator|.
name|value
argument_list|(
name|sock
argument_list|)
decl_stmt|;
name|socketMap
operator|.
name|remove
argument_list|(
name|sock
argument_list|)
expr_stmt|;
name|reverseSocketMap
operator|.
name|remove
argument_list|(
name|id
argument_list|)
expr_stmt|;
return|return
literal|true
return|;
block|}
end_function
begin_function
DECL|function|lookupSocket
name|int
name|QSymbianSocketManager
operator|::
name|lookupSocket
parameter_list|(
specifier|const
name|RSocket
modifier|&
name|socket
parameter_list|)
specifier|const
block|{
name|QHashableSocket
name|sock
argument_list|(
cast|static_cast
argument_list|<
specifier|const
name|QHashableSocket
operator|&
argument_list|>
argument_list|(
name|socket
argument_list|)
argument_list|)
decl_stmt|;
name|QMutexLocker
name|l
argument_list|(
operator|&
name|iMutex
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|socketMap
operator|.
name|contains
argument_list|(
name|sock
argument_list|)
condition|)
return|return
operator|-
literal|1
return|;
name|int
name|id
init|=
name|socketMap
operator|.
name|value
argument_list|(
name|sock
argument_list|)
decl_stmt|;
return|return
name|id
operator|+
name|socket_offset
return|;
block|}
end_function
begin_function
DECL|function|lookupSocket
name|bool
name|QSymbianSocketManager
operator|::
name|lookupSocket
parameter_list|(
name|int
name|fd
parameter_list|,
name|RSocket
modifier|&
name|socket
parameter_list|)
specifier|const
block|{
name|QMutexLocker
name|l
argument_list|(
operator|&
name|iMutex
argument_list|)
decl_stmt|;
name|int
name|id
init|=
name|fd
operator|-
name|socket_offset
decl_stmt|;
if|if
condition|(
operator|!
name|reverseSocketMap
operator|.
name|contains
argument_list|(
name|id
argument_list|)
condition|)
return|return
literal|false
return|;
name|socket
operator|=
name|reverseSocketMap
operator|.
name|value
argument_list|(
name|id
argument_list|)
expr_stmt|;
return|return
literal|true
return|;
block|}
end_function
begin_function
DECL|function|setDefaultConnection
name|void
name|QSymbianSocketManager
operator|::
name|setDefaultConnection
parameter_list|(
name|RConnection
modifier|*
name|con
parameter_list|)
block|{
name|iDefaultConnection
operator|=
name|con
expr_stmt|;
block|}
end_function
begin_function
DECL|function|defaultConnection
name|RConnection
modifier|*
name|QSymbianSocketManager
operator|::
name|defaultConnection
parameter_list|()
specifier|const
block|{
return|return
name|iDefaultConnection
return|;
block|}
end_function
begin_expr_stmt
name|Q_GLOBAL_STATIC
argument_list|(
name|QSymbianSocketManager
argument_list|,
name|qt_symbianSocketManager
argument_list|)
expr_stmt|;
end_expr_stmt
begin_function
DECL|function|instance
name|QSymbianSocketManager
modifier|&
name|QSymbianSocketManager
operator|::
name|instance
parameter_list|()
block|{
return|return
operator|*
operator|(
name|qt_symbianSocketManager
argument_list|()
operator|)
return|;
block|}
end_function
begin_function
DECL|function|qt_symbianGetSocketServer
name|Q_CORE_EXPORT
name|RSocketServ
modifier|&
name|qt_symbianGetSocketServer
parameter_list|()
block|{
return|return
name|QSymbianSocketManager
operator|::
name|instance
argument_list|()
operator|.
name|getSocketServer
argument_list|()
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
