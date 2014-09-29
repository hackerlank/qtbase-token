begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2014 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtDBus module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia. For licensing terms and ** conditions see http://qt.digia.com/licensing. For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights. These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qdbusreply.h"
end_include
begin_include
include|#
directive|include
file|"qdbusmetatype.h"
end_include
begin_include
include|#
directive|include
file|"qdbusmetatype_p.h"
end_include
begin_include
include|#
directive|include
file|<QDebug>
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_DBUS
end_ifndef
begin_function
name|QT_BEGIN_NAMESPACE
comment|/*!     \class QDBusReply     \inmodule QtDBus     \since 4.2      \brief The QDBusReply class stores the reply for a method call to a remote object.      A QDBusReply object is a subset of the QDBusMessage object that represents a method call's     reply. It contains only the first output argument or the error code and is used by     QDBusInterface-derived classes to allow returning the error code as the function's return     argument.      It can be used in the following manner:     \snippet code/src_qdbus_qdbusreply.cpp 0      If the remote method call cannot fail, you can skip the error checking:     \snippet code/src_qdbus_qdbusreply.cpp 1      However, if it does fail under those conditions, the value returned by QDBusReply::value() is     a default-constructed value. It may be indistinguishable from a valid return value.      QDBusReply objects are used for remote calls that have no output     arguments or return values (i.e., they have a "void" return     type). Use the isValid() function to test if the reply succeeded.      \sa QDBusMessage, QDBusInterface */
comment|/*!     \fn QDBusReply::QDBusReply(const QDBusMessage&reply)     Automatically construct a QDBusReply object from the reply message \a reply, extracting the     first return value from it if it is a success reply. */
comment|/*!     \fn QDBusReply::QDBusReply(const QDBusPendingReply<T>&reply)     Constructs a QDBusReply object from the pending reply message, \a reply. */
comment|/*!     \fn QDBusReply::QDBusReply(const QDBusPendingCall&pcall)     Automatically construct a QDBusReply object from the asynchronous     pending call \a pcall. If the call isn't finished yet, QDBusReply     will call QDBusPendingCall::waitForFinished(), which is a blocking     operation.      If the return types patch, QDBusReply will extract the first     return argument from the reply. */
comment|/*!     \fn QDBusReply::QDBusReply(const QDBusError&error)     Constructs an error reply from the D-Bus error code given by \a error. */
comment|/*!     \fn QDBusReply::operator=(const QDBusReply&other)     Makes this object be a copy of the object \a other. */
comment|/*!     \fn QDBusReply::operator=(const QDBusError&error)     Sets this object to contain the error code given by \a error. You     can later access it with error(). */
comment|/*!     \fn QDBusReply::operator=(const QDBusMessage&message)      Makes this object contain the reply specified by message \a     message. If \a message is an error message, this function will     copy the error code and message into this object      If \a message is a standard reply message and contains at least     one parameter, it will be copied into this object, as long as it     is of the correct type. If it's not of the same type as this     QDBusError object, this function will instead set an error code     indicating a type mismatch. */
comment|/*!     \fn QDBusReply::operator=(const QDBusPendingCall&pcall)      Makes this object contain the reply specified by the pending     asynchronous call \a pcall. If the call is not finished yet, this     function will call QDBusPendingCall::waitForFinished() to block     until the reply arrives.      If \a pcall finishes with an error message, this function will     copy the error code and message into this object      If \a pcall finished with a standard reply message and contains at     least one parameter, it will be copied into this object, as long     as it is of the correct type. If it's not of the same type as this     QDBusError object, this function will instead set an error code     indicating a type mismatch. */
comment|/*!     \fn bool QDBusReply::isValid() const      Returns \c true if no error occurred; otherwise, returns \c false.      \sa error() */
comment|/*!     \fn const QDBusError& QDBusReply::error() const      Returns the error code that was returned from the remote function call. If the remote call did     not return an error (i.e., if it succeeded), then the QDBusError object that is returned will     not be a valid error code (QDBusError::isValid() will return false).      \sa isValid() */
comment|/*!     \fn const QDBusError& QDBusReply::error()     \overload */
comment|/*!     \fn QDBusReply::value() const     Returns the remote function's calls return value. If the remote call returned with an error,     the return value of this function is undefined and may be undistinguishable from a valid return     value.      This function is not available if the remote call returns \c void. */
comment|/*!     \fn QDBusReply::operator Type() const     Returns the same as value().      This function is not available if the remote call returns \c void. */
comment|/*!     \internal     Fills in the QDBusReply data \a error and \a data from the reply message \a reply. */
DECL|function|qDBusReplyFill
name|void
name|qDBusReplyFill
parameter_list|(
specifier|const
name|QDBusMessage
modifier|&
name|reply
parameter_list|,
name|QDBusError
modifier|&
name|error
parameter_list|,
name|QVariant
modifier|&
name|data
parameter_list|)
block|{
name|error
operator|=
name|QDBusError
argument_list|(
name|reply
argument_list|)
expr_stmt|;
if|if
condition|(
name|error
operator|.
name|isValid
argument_list|()
condition|)
block|{
name|data
operator|=
name|QVariant
argument_list|()
expr_stmt|;
comment|// clear it
return|return;
block|}
if|if
condition|(
name|reply
operator|.
name|arguments
argument_list|()
operator|.
name|count
argument_list|()
operator|>=
literal|1
operator|&&
name|reply
operator|.
name|arguments
argument_list|()
operator|.
name|at
argument_list|(
literal|0
argument_list|)
operator|.
name|userType
argument_list|()
operator|==
name|data
operator|.
name|userType
argument_list|()
condition|)
block|{
name|data
operator|=
name|reply
operator|.
name|arguments
argument_list|()
operator|.
name|at
argument_list|(
literal|0
argument_list|)
expr_stmt|;
return|return;
block|}
specifier|const
name|char
modifier|*
name|expectedSignature
init|=
name|QDBusMetaType
operator|::
name|typeToSignature
argument_list|(
name|data
operator|.
name|userType
argument_list|()
argument_list|)
decl_stmt|;
specifier|const
name|char
modifier|*
name|receivedType
init|=
literal|0
decl_stmt|;
name|QByteArray
name|receivedSignature
decl_stmt|;
if|if
condition|(
name|reply
operator|.
name|arguments
argument_list|()
operator|.
name|count
argument_list|()
operator|>=
literal|1
condition|)
block|{
if|if
condition|(
name|reply
operator|.
name|arguments
argument_list|()
operator|.
name|at
argument_list|(
literal|0
argument_list|)
operator|.
name|userType
argument_list|()
operator|==
name|QDBusMetaTypeId
operator|::
name|argument
argument_list|()
condition|)
block|{
comment|// compare signatures instead
name|QDBusArgument
name|arg
init|=
name|qvariant_cast
argument_list|<
name|QDBusArgument
argument_list|>
argument_list|(
name|reply
operator|.
name|arguments
argument_list|()
operator|.
name|at
argument_list|(
literal|0
argument_list|)
argument_list|)
decl_stmt|;
name|receivedSignature
operator|=
name|arg
operator|.
name|currentSignature
argument_list|()
operator|.
name|toLatin1
argument_list|()
expr_stmt|;
if|if
condition|(
name|receivedSignature
operator|==
name|expectedSignature
condition|)
block|{
comment|// matched. Demarshall it
name|QDBusMetaType
operator|::
name|demarshall
argument_list|(
name|arg
argument_list|,
name|data
operator|.
name|userType
argument_list|()
argument_list|,
name|data
operator|.
name|data
argument_list|()
argument_list|)
expr_stmt|;
return|return;
block|}
block|}
else|else
block|{
comment|// not an argument and doesn't match?
name|int
name|type
init|=
name|reply
operator|.
name|arguments
argument_list|()
operator|.
name|at
argument_list|(
literal|0
argument_list|)
operator|.
name|userType
argument_list|()
decl_stmt|;
name|receivedType
operator|=
name|QMetaType
operator|::
name|typeName
argument_list|(
name|type
argument_list|)
expr_stmt|;
name|receivedSignature
operator|=
name|QDBusMetaType
operator|::
name|typeToSignature
argument_list|(
name|type
argument_list|)
expr_stmt|;
block|}
block|}
comment|// error
if|if
condition|(
name|receivedSignature
operator|.
name|isEmpty
argument_list|()
condition|)
name|receivedSignature
operator|=
literal|"no signature"
expr_stmt|;
name|QString
name|errorMsg
decl_stmt|;
if|if
condition|(
name|receivedType
condition|)
block|{
name|errorMsg
operator|=
name|QString
operator|::
name|fromLatin1
argument_list|(
literal|"Unexpected reply signature: got \"%1\" (%4), "
literal|"expected \"%2\" (%3)"
argument_list|)
operator|.
name|arg
argument_list|(
name|QLatin1String
argument_list|(
name|receivedSignature
argument_list|)
argument_list|,
name|QLatin1String
argument_list|(
name|expectedSignature
argument_list|)
argument_list|,
name|QLatin1String
argument_list|(
name|data
operator|.
name|typeName
argument_list|()
argument_list|)
argument_list|,
name|QLatin1String
argument_list|(
name|receivedType
argument_list|)
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|errorMsg
operator|=
name|QString
operator|::
name|fromLatin1
argument_list|(
literal|"Unexpected reply signature: got \"%1\", "
literal|"expected \"%2\" (%3)"
argument_list|)
operator|.
name|arg
argument_list|(
name|QLatin1String
argument_list|(
name|receivedSignature
argument_list|)
argument_list|,
name|QLatin1String
argument_list|(
name|expectedSignature
argument_list|)
argument_list|,
name|QLatin1String
argument_list|(
name|data
operator|.
name|typeName
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
block|}
name|error
operator|=
name|QDBusError
argument_list|(
name|QDBusError
operator|::
name|InvalidSignature
argument_list|,
name|errorMsg
argument_list|)
expr_stmt|;
name|data
operator|=
name|QVariant
argument_list|()
expr_stmt|;
comment|// clear it
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
