begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtDBus module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<string.h>
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_BOOTSTRAPPED
end_ifndef
begin_include
include|#
directive|include
file|<QtCore/qcoreapplication.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qvariant.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qmetaobject.h>
end_include
begin_include
include|#
directive|include
file|"qdbusutil_p.h"
end_include
begin_include
include|#
directive|include
file|"qdbusconnection_p.h"
end_include
begin_include
include|#
directive|include
file|"qdbusabstractadaptor_p.h"
end_include
begin_comment
comment|// for QCLASSINFO_DBUS_*
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_include
include|#
directive|include
file|"qdbusmetatype_p.h"
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_DBUS
end_ifndef
begin_function
name|QT_BEGIN_NAMESPACE
DECL|function|qDBusCheckAsyncTag
name|bool
name|qDBusCheckAsyncTag
parameter_list|(
specifier|const
name|char
modifier|*
name|tag
parameter_list|)
block|{
specifier|static
specifier|const
name|char
name|noReplyTag
index|[]
init|=
literal|"Q_NOREPLY"
decl_stmt|;
if|if
condition|(
operator|!
name|tag
operator|||
operator|!
operator|*
name|tag
condition|)
return|return
literal|false
return|;
specifier|const
name|char
modifier|*
name|p
init|=
name|strstr
argument_list|(
name|tag
argument_list|,
name|noReplyTag
argument_list|)
decl_stmt|;
if|if
condition|(
name|p
operator|!=
name|NULL
operator|&&
operator|(
name|p
operator|==
name|tag
operator|||
operator|*
operator|(
name|p
operator|-
literal|1
operator|)
operator|==
literal|' '
operator|)
operator|&&
operator|(
name|p
index|[
sizeof|sizeof
name|noReplyTag
operator|-
literal|1
index|]
operator|==
literal|'\0'
operator|||
name|p
index|[
sizeof|sizeof
name|noReplyTag
operator|-
literal|1
index|]
operator|==
literal|' '
operator|)
condition|)
return|return
literal|true
return|;
return|return
literal|false
return|;
block|}
end_function
begin_ifndef
ifndef|#
directive|ifndef
name|QT_BOOTSTRAPPED
end_ifndef
begin_function
DECL|function|qDBusInterfaceFromMetaObject
name|QString
name|qDBusInterfaceFromMetaObject
parameter_list|(
specifier|const
name|QMetaObject
modifier|*
name|mo
parameter_list|)
block|{
name|QString
name|interface
decl_stmt|;
name|int
name|idx
init|=
name|mo
operator|->
name|indexOfClassInfo
argument_list|(
name|QCLASSINFO_DBUS_INTERFACE
argument_list|)
decl_stmt|;
if|if
condition|(
name|idx
operator|>=
name|mo
operator|->
name|classInfoOffset
argument_list|()
condition|)
block|{
name|interface
operator|=
name|QLatin1String
argument_list|(
name|mo
operator|->
name|classInfo
argument_list|(
name|idx
argument_list|)
operator|.
name|value
argument_list|()
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|interface
operator|=
name|QLatin1String
argument_list|(
name|mo
operator|->
name|className
argument_list|()
argument_list|)
expr_stmt|;
name|interface
operator|.
name|replace
argument_list|(
name|QLatin1String
argument_list|(
literal|"::"
argument_list|)
argument_list|,
name|QLatin1String
argument_list|(
literal|"."
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|interface
operator|.
name|startsWith
argument_list|(
name|QLatin1String
argument_list|(
literal|"QDBus"
argument_list|)
argument_list|)
condition|)
block|{
name|interface
operator|.
name|prepend
argument_list|(
name|QLatin1String
argument_list|(
literal|"com.trolltech.QtDBus."
argument_list|)
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|interface
operator|.
name|startsWith
argument_list|(
name|QLatin1Char
argument_list|(
literal|'Q'
argument_list|)
argument_list|)
operator|&&
name|interface
operator|.
name|length
argument_list|()
operator|>=
literal|2
operator|&&
name|interface
operator|.
name|at
argument_list|(
literal|1
argument_list|)
operator|.
name|isUpper
argument_list|()
condition|)
block|{
comment|// assume it's Qt
name|interface
operator|.
name|prepend
argument_list|(
name|QLatin1String
argument_list|(
literal|"com.trolltech.Qt."
argument_list|)
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
operator|!
name|QCoreApplication
operator|::
name|instance
argument_list|()
operator|||
name|QCoreApplication
operator|::
name|instance
argument_list|()
operator|->
name|applicationName
argument_list|()
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|interface
operator|.
name|prepend
argument_list|(
name|QLatin1String
argument_list|(
literal|"local."
argument_list|)
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|interface
operator|.
name|prepend
argument_list|(
name|QLatin1Char
argument_list|(
literal|'.'
argument_list|)
argument_list|)
operator|.
name|prepend
argument_list|(
name|QCoreApplication
operator|::
name|instance
argument_list|()
operator|->
name|applicationName
argument_list|()
argument_list|)
expr_stmt|;
name|QStringList
name|domainName
init|=
name|QCoreApplication
operator|::
name|instance
argument_list|()
operator|->
name|organizationDomain
argument_list|()
operator|.
name|split
argument_list|(
name|QLatin1Char
argument_list|(
literal|'.'
argument_list|)
argument_list|,
name|QString
operator|::
name|SkipEmptyParts
argument_list|)
decl_stmt|;
if|if
condition|(
name|domainName
operator|.
name|isEmpty
argument_list|()
condition|)
name|interface
operator|.
name|prepend
argument_list|(
name|QLatin1String
argument_list|(
literal|"local."
argument_list|)
argument_list|)
expr_stmt|;
else|else
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|domainName
operator|.
name|count
argument_list|()
condition|;
operator|++
name|i
control|)
name|interface
operator|.
name|prepend
argument_list|(
name|QLatin1Char
argument_list|(
literal|'.'
argument_list|)
argument_list|)
operator|.
name|prepend
argument_list|(
name|domainName
operator|.
name|at
argument_list|(
name|i
argument_list|)
argument_list|)
expr_stmt|;
block|}
block|}
return|return
name|interface
return|;
block|}
end_function
begin_function
DECL|function|qDBusInterfaceInObject
name|bool
name|qDBusInterfaceInObject
parameter_list|(
name|QObject
modifier|*
name|obj
parameter_list|,
specifier|const
name|QString
modifier|&
name|interface_name
parameter_list|)
block|{
specifier|const
name|QMetaObject
modifier|*
name|mo
init|=
name|obj
operator|->
name|metaObject
argument_list|()
decl_stmt|;
for|for
control|(
init|;
name|mo
operator|!=
operator|&
name|QObject
operator|::
name|staticMetaObject
condition|;
name|mo
operator|=
name|mo
operator|->
name|superClass
argument_list|()
control|)
if|if
condition|(
name|interface_name
operator|==
name|qDBusInterfaceFromMetaObject
argument_list|(
name|mo
argument_list|)
condition|)
return|return
literal|true
return|;
return|return
literal|false
return|;
block|}
end_function
begin_comment
comment|// calculates the metatypes for the method
end_comment
begin_comment
comment|// the slot must have the parameters in the following form:
end_comment
begin_comment
comment|//  - zero or more value or const-ref parameters of any kind
end_comment
begin_comment
comment|//  - zero or one const ref of QDBusMessage
end_comment
begin_comment
comment|//  - zero or more non-const ref parameters
end_comment
begin_comment
comment|// No parameter may be a template.
end_comment
begin_comment
comment|// this function returns -1 if the parameters don't match the above form
end_comment
begin_comment
comment|// this function returns the number of *input* parameters, including the QDBusMessage one if any
end_comment
begin_comment
comment|// this function does not check the return type, so metaTypes[0] is always 0 and always present
end_comment
begin_comment
comment|// metaTypes.count()>= retval + 1 in all cases
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|// sig must be the normalised signature for the method
end_comment
begin_function
DECL|function|qDBusParametersForMethod
name|int
name|qDBusParametersForMethod
parameter_list|(
specifier|const
name|QMetaMethod
modifier|&
name|mm
parameter_list|,
name|QList
argument_list|<
name|int
argument_list|>
modifier|&
name|metaTypes
parameter_list|)
block|{
return|return
name|qDBusParametersForMethod
argument_list|(
name|mm
operator|.
name|parameterTypes
argument_list|()
argument_list|,
name|metaTypes
argument_list|)
return|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_BOOTSTRAPPED
end_comment
begin_function
DECL|function|qDBusParametersForMethod
name|int
name|qDBusParametersForMethod
parameter_list|(
specifier|const
name|QList
argument_list|<
name|QByteArray
argument_list|>
modifier|&
name|parameterTypes
parameter_list|,
name|QList
argument_list|<
name|int
argument_list|>
modifier|&
name|metaTypes
parameter_list|)
block|{
name|QDBusMetaTypeId
operator|::
name|init
argument_list|()
expr_stmt|;
name|metaTypes
operator|.
name|clear
argument_list|()
expr_stmt|;
name|metaTypes
operator|.
name|append
argument_list|(
literal|0
argument_list|)
expr_stmt|;
comment|// return type
name|int
name|inputCount
init|=
literal|0
decl_stmt|;
name|bool
name|seenMessage
init|=
literal|false
decl_stmt|;
name|QList
argument_list|<
name|QByteArray
argument_list|>
operator|::
name|ConstIterator
name|it
init|=
name|parameterTypes
operator|.
name|constBegin
argument_list|()
decl_stmt|;
name|QList
argument_list|<
name|QByteArray
argument_list|>
operator|::
name|ConstIterator
name|end
init|=
name|parameterTypes
operator|.
name|constEnd
argument_list|()
decl_stmt|;
for|for
control|(
init|;
name|it
operator|!=
name|end
condition|;
operator|++
name|it
control|)
block|{
specifier|const
name|QByteArray
modifier|&
name|type
init|=
operator|*
name|it
decl_stmt|;
if|if
condition|(
name|type
operator|.
name|endsWith
argument_list|(
literal|'*'
argument_list|)
condition|)
block|{
comment|//qWarning("Could not parse the method '%s'", mm.methodSignature().constData());
comment|// pointer?
return|return
operator|-
literal|1
return|;
block|}
if|if
condition|(
name|type
operator|.
name|endsWith
argument_list|(
literal|'&'
argument_list|)
condition|)
block|{
name|QByteArray
name|basictype
init|=
name|type
decl_stmt|;
name|basictype
operator|.
name|truncate
argument_list|(
name|type
operator|.
name|length
argument_list|()
operator|-
literal|1
argument_list|)
expr_stmt|;
name|int
name|id
init|=
name|QMetaType
operator|::
name|type
argument_list|(
name|basictype
argument_list|)
decl_stmt|;
if|if
condition|(
name|id
operator|==
literal|0
condition|)
block|{
comment|//qWarning("Could not parse the method '%s'", mm.methodSignature().constData());
comment|// invalid type in method parameter list
return|return
operator|-
literal|1
return|;
block|}
elseif|else
if|if
condition|(
name|QDBusMetaType
operator|::
name|typeToSignature
argument_list|(
name|id
argument_list|)
operator|==
literal|0
condition|)
return|return
operator|-
literal|1
return|;
name|metaTypes
operator|.
name|append
argument_list|(
name|id
argument_list|)
expr_stmt|;
name|seenMessage
operator|=
literal|true
expr_stmt|;
comment|// it cannot appear anymore anyways
continue|continue;
block|}
if|if
condition|(
name|seenMessage
condition|)
block|{
comment|//&& !type.endsWith('&')
comment|//qWarning("Could not parse the method '%s'", mm.methodSignature().constData());
comment|// non-output parameters after message or after output params
return|return
operator|-
literal|1
return|;
comment|// not allowed
block|}
name|int
name|id
init|=
name|QMetaType
operator|::
name|type
argument_list|(
name|type
argument_list|)
decl_stmt|;
if|if
condition|(
name|id
operator|==
name|QMetaType
operator|::
name|UnknownType
condition|)
block|{
comment|//qWarning("Could not parse the method '%s'", mm.methodSignature().constData());
comment|// invalid type in method parameter list
return|return
operator|-
literal|1
return|;
block|}
if|if
condition|(
name|id
operator|==
name|QDBusMetaTypeId
operator|::
name|message
condition|)
name|seenMessage
operator|=
literal|true
expr_stmt|;
elseif|else
if|if
condition|(
name|QDBusMetaType
operator|::
name|typeToSignature
argument_list|(
name|id
argument_list|)
operator|==
literal|0
condition|)
return|return
operator|-
literal|1
return|;
name|metaTypes
operator|.
name|append
argument_list|(
name|id
argument_list|)
expr_stmt|;
operator|++
name|inputCount
expr_stmt|;
block|}
return|return
name|inputCount
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
comment|// QT_NO_DBUS
end_comment
end_unit
