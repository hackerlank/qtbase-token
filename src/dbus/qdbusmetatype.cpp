begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtDBus module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** No Commercial Usage ** This file contains pre-release code and may not be distributed. ** You may use this file in accordance with the terms and conditions ** contained in the Technology Preview License Agreement accompanying ** this package. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights.  These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** If you have questions regarding the use of this file, please contact ** Nokia at qt-info@nokia.com. ** ** ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qdbusmetatype.h"
end_include
begin_include
include|#
directive|include
file|<string.h>
end_include
begin_include
include|#
directive|include
file|"qdbus_symbols_p.h"
end_include
begin_include
include|#
directive|include
file|<qbytearray.h>
end_include
begin_include
include|#
directive|include
file|<qglobal.h>
end_include
begin_include
include|#
directive|include
file|<qreadwritelock.h>
end_include
begin_include
include|#
directive|include
file|<qvector.h>
end_include
begin_include
include|#
directive|include
file|"qdbusmessage.h"
end_include
begin_include
include|#
directive|include
file|"qdbusunixfiledescriptor.h"
end_include
begin_include
include|#
directive|include
file|"qdbusutil_p.h"
end_include
begin_include
include|#
directive|include
file|"qdbusmetatype_p.h"
end_include
begin_include
include|#
directive|include
file|"qdbusargument_p.h"
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_DBUS
end_ifndef
begin_ifndef
ifndef|#
directive|ifndef
name|DBUS_TYPE_UNIX_FD
end_ifndef
begin_define
DECL|macro|DBUS_TYPE_UNIX_FD
define|#
directive|define
name|DBUS_TYPE_UNIX_FD
value|int('h')
end_define
begin_define
DECL|macro|DBUS_TYPE_UNIX_FD_AS_STRING
define|#
directive|define
name|DBUS_TYPE_UNIX_FD_AS_STRING
value|"h"
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_macro
name|Q_DECLARE_METATYPE
argument_list|(
argument|QList<bool>
argument_list|)
end_macro
begin_macro
name|Q_DECLARE_METATYPE
argument_list|(
argument|QList<short>
argument_list|)
end_macro
begin_macro
name|Q_DECLARE_METATYPE
argument_list|(
argument|QList<ushort>
argument_list|)
end_macro
begin_macro
name|Q_DECLARE_METATYPE
argument_list|(
argument|QList<int>
argument_list|)
end_macro
begin_macro
name|Q_DECLARE_METATYPE
argument_list|(
argument|QList<uint>
argument_list|)
end_macro
begin_macro
name|Q_DECLARE_METATYPE
argument_list|(
argument|QList<qlonglong>
argument_list|)
end_macro
begin_macro
name|Q_DECLARE_METATYPE
argument_list|(
argument|QList<qulonglong>
argument_list|)
end_macro
begin_macro
name|Q_DECLARE_METATYPE
argument_list|(
argument|QList<double>
argument_list|)
end_macro
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_class
DECL|class|QDBusCustomTypeInfo
class|class
name|QDBusCustomTypeInfo
block|{
public|public:
DECL|function|QDBusCustomTypeInfo
name|QDBusCustomTypeInfo
parameter_list|()
member_init_list|:
name|signature
argument_list|(
literal|0
argument_list|,
literal|'\0'
argument_list|)
member_init_list|,
name|marshall
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|demarshall
argument_list|(
literal|0
argument_list|)
block|{ }
comment|// Suggestion:
comment|// change 'signature' to char* and make QDBusCustomTypeInfo a Movable type
DECL|member|signature
name|QByteArray
name|signature
decl_stmt|;
DECL|member|marshall
name|QDBusMetaType
operator|::
name|MarshallFunction
name|marshall
decl_stmt|;
DECL|member|demarshall
name|QDBusMetaType
operator|::
name|DemarshallFunction
name|demarshall
decl_stmt|;
block|}
class|;
end_class
begin_function
template|template
parameter_list|<
name|typename
name|T
parameter_list|>
DECL|function|registerHelper
specifier|inline
specifier|static
name|void
name|registerHelper
parameter_list|(
name|T
modifier|*
init|=
literal|0
parameter_list|)
block|{
name|void
function_decl|(
modifier|*
name|mf
function_decl|)
parameter_list|(
name|QDBusArgument
modifier|&
parameter_list|,
specifier|const
name|T
modifier|*
parameter_list|)
init|=
name|qDBusMarshallHelper
argument_list|<
name|T
argument_list|>
function_decl|;
name|void
function_decl|(
modifier|*
name|df
function_decl|)
parameter_list|(
specifier|const
name|QDBusArgument
modifier|&
parameter_list|,
name|T
modifier|*
parameter_list|)
init|=
name|qDBusDemarshallHelper
argument_list|<
name|T
argument_list|>
function_decl|;
name|QDBusMetaType
operator|::
name|registerMarshallOperators
argument_list|(
name|qMetaTypeId
argument_list|<
name|T
argument_list|>
argument_list|()
argument_list|,
cast|reinterpret_cast
argument_list|<
name|QDBusMetaType
operator|::
name|MarshallFunction
argument_list|>
argument_list|(
name|mf
argument_list|)
argument_list|,
cast|reinterpret_cast
argument_list|<
name|QDBusMetaType
operator|::
name|DemarshallFunction
argument_list|>
argument_list|(
name|df
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_decl_stmt
DECL|member|message
name|int
name|QDBusMetaTypeId
operator|::
name|message
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|member|argument
name|int
name|QDBusMetaTypeId
operator|::
name|argument
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|member|variant
name|int
name|QDBusMetaTypeId
operator|::
name|variant
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|member|objectpath
name|int
name|QDBusMetaTypeId
operator|::
name|objectpath
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|member|signature
name|int
name|QDBusMetaTypeId
operator|::
name|signature
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|member|error
name|int
name|QDBusMetaTypeId
operator|::
name|error
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|member|unixfd
name|int
name|QDBusMetaTypeId
operator|::
name|unixfd
decl_stmt|;
end_decl_stmt
begin_function
DECL|function|init
name|void
name|QDBusMetaTypeId
operator|::
name|init
parameter_list|()
block|{
specifier|static
specifier|volatile
name|bool
name|initialized
init|=
literal|false
decl_stmt|;
comment|// reentrancy is not a problem since everything else is locked on their own
comment|// set the guard variable at the end
if|if
condition|(
operator|!
name|initialized
condition|)
block|{
comment|// register our types with QtCore
name|message
operator|=
name|qRegisterMetaType
argument_list|<
name|QDBusMessage
argument_list|>
argument_list|(
literal|"QDBusMessage"
argument_list|)
expr_stmt|;
name|argument
operator|=
name|qRegisterMetaType
argument_list|<
name|QDBusArgument
argument_list|>
argument_list|(
literal|"QDBusArgument"
argument_list|)
expr_stmt|;
name|variant
operator|=
name|qRegisterMetaType
argument_list|<
name|QDBusVariant
argument_list|>
argument_list|(
literal|"QDBusVariant"
argument_list|)
expr_stmt|;
name|objectpath
operator|=
name|qRegisterMetaType
argument_list|<
name|QDBusObjectPath
argument_list|>
argument_list|(
literal|"QDBusObjectPath"
argument_list|)
expr_stmt|;
name|signature
operator|=
name|qRegisterMetaType
argument_list|<
name|QDBusSignature
argument_list|>
argument_list|(
literal|"QDBusSignature"
argument_list|)
expr_stmt|;
name|error
operator|=
name|qRegisterMetaType
argument_list|<
name|QDBusError
argument_list|>
argument_list|(
literal|"QDBusError"
argument_list|)
expr_stmt|;
name|unixfd
operator|=
name|qRegisterMetaType
argument_list|<
name|QDBusUnixFileDescriptor
argument_list|>
argument_list|(
literal|"QDBusUnixFileDescriptor"
argument_list|)
expr_stmt|;
ifndef|#
directive|ifndef
name|QDBUS_NO_SPECIALTYPES
comment|// and register QtCore's with us
name|registerHelper
argument_list|<
name|QDate
argument_list|>
argument_list|()
expr_stmt|;
name|registerHelper
argument_list|<
name|QTime
argument_list|>
argument_list|()
expr_stmt|;
name|registerHelper
argument_list|<
name|QDateTime
argument_list|>
argument_list|()
expr_stmt|;
name|registerHelper
argument_list|<
name|QRect
argument_list|>
argument_list|()
expr_stmt|;
name|registerHelper
argument_list|<
name|QRectF
argument_list|>
argument_list|()
expr_stmt|;
name|registerHelper
argument_list|<
name|QSize
argument_list|>
argument_list|()
expr_stmt|;
name|registerHelper
argument_list|<
name|QSizeF
argument_list|>
argument_list|()
expr_stmt|;
name|registerHelper
argument_list|<
name|QPoint
argument_list|>
argument_list|()
expr_stmt|;
name|registerHelper
argument_list|<
name|QPointF
argument_list|>
argument_list|()
expr_stmt|;
name|registerHelper
argument_list|<
name|QLine
argument_list|>
argument_list|()
expr_stmt|;
name|registerHelper
argument_list|<
name|QLineF
argument_list|>
argument_list|()
expr_stmt|;
name|registerHelper
argument_list|<
name|QVariantList
argument_list|>
argument_list|()
expr_stmt|;
name|registerHelper
argument_list|<
name|QVariantMap
argument_list|>
argument_list|()
expr_stmt|;
name|registerHelper
argument_list|<
name|QVariantHash
argument_list|>
argument_list|()
expr_stmt|;
name|qDBusRegisterMetaType
argument_list|<
name|QList
argument_list|<
name|bool
argument_list|>
argument_list|>
argument_list|()
expr_stmt|;
name|qDBusRegisterMetaType
argument_list|<
name|QList
argument_list|<
name|short
argument_list|>
argument_list|>
argument_list|()
expr_stmt|;
name|qDBusRegisterMetaType
argument_list|<
name|QList
argument_list|<
name|ushort
argument_list|>
argument_list|>
argument_list|()
expr_stmt|;
name|qDBusRegisterMetaType
argument_list|<
name|QList
argument_list|<
name|int
argument_list|>
argument_list|>
argument_list|()
expr_stmt|;
name|qDBusRegisterMetaType
argument_list|<
name|QList
argument_list|<
name|uint
argument_list|>
argument_list|>
argument_list|()
expr_stmt|;
name|qDBusRegisterMetaType
argument_list|<
name|QList
argument_list|<
name|qlonglong
argument_list|>
argument_list|>
argument_list|()
expr_stmt|;
name|qDBusRegisterMetaType
argument_list|<
name|QList
argument_list|<
name|qulonglong
argument_list|>
argument_list|>
argument_list|()
expr_stmt|;
name|qDBusRegisterMetaType
argument_list|<
name|QList
argument_list|<
name|double
argument_list|>
argument_list|>
argument_list|()
expr_stmt|;
name|qDBusRegisterMetaType
argument_list|<
name|QList
argument_list|<
name|QDBusObjectPath
argument_list|>
argument_list|>
argument_list|()
expr_stmt|;
name|qDBusRegisterMetaType
argument_list|<
name|QList
argument_list|<
name|QDBusSignature
argument_list|>
argument_list|>
argument_list|()
expr_stmt|;
name|qDBusRegisterMetaType
argument_list|<
name|QList
argument_list|<
name|QDBusUnixFileDescriptor
argument_list|>
argument_list|>
argument_list|()
expr_stmt|;
endif|#
directive|endif
name|initialized
operator|=
literal|true
expr_stmt|;
block|}
block|}
end_function
begin_macro
name|Q_GLOBAL_STATIC
argument_list|(
argument|QVector<QDBusCustomTypeInfo>
argument_list|,
argument|customTypes
argument_list|)
end_macro
begin_macro
name|Q_GLOBAL_STATIC
argument_list|(
argument|QReadWriteLock
argument_list|,
argument|customTypesLock
argument_list|)
end_macro
begin_comment
comment|/*!     \class QDBusMetaType     \brief Meta-type registration system for the QtDBus module.     \internal      The QDBusMetaType class allows you to register class types for     marshalling and demarshalling over D-Bus. D-Bus supports a very     limited set of primitive types, but allows one to extend the type     system by creating compound types, such as arrays (lists) and     structs. In order to use them with QtDBus, those types must be     registered.      See \l {qdbustypesystem.html}{QtDBus type system} for more     information on the type system and how to register additional     types.      \sa {qdbustypesystem.html}{QtDBus type system},     qDBusRegisterMetaType(), QMetaType, QVariant, QDBusArgument */
end_comment
begin_comment
comment|/*!     \fn int qDBusRegisterMetaType()     \relates QDBusArgument     \threadsafe     \since 4.2      Registers \c{T} with the     \l {qdbustypesystem.html}{QtDBus type system} and the Qt \l     {QMetaType}{meta-type system}, if it's not already registered.      To register a type, it must be declared as a meta-type with the     Q_DECLARE_METATYPE() macro, and then registered as in the     following example:      \snippet doc/src/snippets/code/src_qdbus_qdbusmetatype.cpp 0      If \c{T} isn't a type derived from one of     Qt's \l{container classes}, the \c{operator<<} and     \c{operator>>} streaming operators between \c{T} and QDBusArgument     must be already declared. See the \l {qdbustypesystem.html}{QtDBus     type system} page for more information on how to declare such     types.      This function returns the Qt meta type id for the type (the same     value that is returned from qRegisterMetaType()).      \sa {qdbustypesystem.html}{QtDBus type system}, qRegisterMetaType(), QMetaType */
end_comment
begin_comment
comment|/*!     \typedef QDBusMetaType::MarshallFunction     \internal */
end_comment
begin_comment
comment|/*!     \typedef QDBusMetaType::DemarshallFunction     \internal */
end_comment
begin_comment
comment|/*!     \internal     Registers the marshalling and demarshalling functions for meta     type \a id. */
end_comment
begin_function
DECL|function|registerMarshallOperators
name|void
name|QDBusMetaType
operator|::
name|registerMarshallOperators
parameter_list|(
name|int
name|id
parameter_list|,
name|MarshallFunction
name|mf
parameter_list|,
name|DemarshallFunction
name|df
parameter_list|)
block|{
name|QByteArray
name|var
decl_stmt|;
name|QVector
argument_list|<
name|QDBusCustomTypeInfo
argument_list|>
modifier|*
name|ct
init|=
name|customTypes
argument_list|()
decl_stmt|;
if|if
condition|(
name|id
operator|<
literal|0
operator|||
operator|!
name|mf
operator|||
operator|!
name|df
operator|||
operator|!
name|ct
condition|)
return|return;
comment|// error!
name|QWriteLocker
name|locker
argument_list|(
name|customTypesLock
argument_list|()
argument_list|)
decl_stmt|;
if|if
condition|(
name|id
operator|>=
name|ct
operator|->
name|size
argument_list|()
condition|)
name|ct
operator|->
name|resize
argument_list|(
name|id
operator|+
literal|1
argument_list|)
expr_stmt|;
name|QDBusCustomTypeInfo
modifier|&
name|info
init|=
operator|(
operator|*
name|ct
operator|)
index|[
name|id
index|]
decl_stmt|;
name|info
operator|.
name|marshall
operator|=
name|mf
expr_stmt|;
name|info
operator|.
name|demarshall
operator|=
name|df
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     \internal     Executes the marshalling of type \a id (whose data is contained in     \a data) to the D-Bus marshalling argument \a arg. Returns true if     the marshalling succeeded, or false if an error occurred. */
end_comment
begin_function
DECL|function|marshall
name|bool
name|QDBusMetaType
operator|::
name|marshall
parameter_list|(
name|QDBusArgument
modifier|&
name|arg
parameter_list|,
name|int
name|id
parameter_list|,
specifier|const
name|void
modifier|*
name|data
parameter_list|)
block|{
name|QDBusMetaTypeId
operator|::
name|init
argument_list|()
expr_stmt|;
name|MarshallFunction
name|mf
decl_stmt|;
block|{
name|QReadLocker
name|locker
argument_list|(
name|customTypesLock
argument_list|()
argument_list|)
decl_stmt|;
name|QVector
argument_list|<
name|QDBusCustomTypeInfo
argument_list|>
modifier|*
name|ct
init|=
name|customTypes
argument_list|()
decl_stmt|;
if|if
condition|(
name|id
operator|>=
name|ct
operator|->
name|size
argument_list|()
condition|)
return|return
literal|false
return|;
comment|// non-existent
specifier|const
name|QDBusCustomTypeInfo
modifier|&
name|info
init|=
operator|(
operator|*
name|ct
operator|)
operator|.
name|at
argument_list|(
name|id
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|info
operator|.
name|marshall
condition|)
block|{
name|mf
operator|=
literal|0
expr_stmt|;
comment|// make gcc happy
return|return
literal|false
return|;
block|}
else|else
name|mf
operator|=
name|info
operator|.
name|marshall
expr_stmt|;
block|}
name|mf
argument_list|(
name|arg
argument_list|,
name|data
argument_list|)
expr_stmt|;
return|return
literal|true
return|;
block|}
end_function
begin_comment
comment|/*!     \internal     Executes the demarshalling of type \a id (whose data will be placed in     \a data) from the D-Bus marshalling argument \a arg. Returns true if     the demarshalling succeeded, or false if an error occurred. */
end_comment
begin_function
DECL|function|demarshall
name|bool
name|QDBusMetaType
operator|::
name|demarshall
parameter_list|(
specifier|const
name|QDBusArgument
modifier|&
name|arg
parameter_list|,
name|int
name|id
parameter_list|,
name|void
modifier|*
name|data
parameter_list|)
block|{
name|QDBusMetaTypeId
operator|::
name|init
argument_list|()
expr_stmt|;
name|DemarshallFunction
name|df
decl_stmt|;
block|{
name|QReadLocker
name|locker
argument_list|(
name|customTypesLock
argument_list|()
argument_list|)
decl_stmt|;
name|QVector
argument_list|<
name|QDBusCustomTypeInfo
argument_list|>
modifier|*
name|ct
init|=
name|customTypes
argument_list|()
decl_stmt|;
if|if
condition|(
name|id
operator|>=
name|ct
operator|->
name|size
argument_list|()
condition|)
return|return
literal|false
return|;
comment|// non-existent
specifier|const
name|QDBusCustomTypeInfo
modifier|&
name|info
init|=
operator|(
operator|*
name|ct
operator|)
operator|.
name|at
argument_list|(
name|id
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|info
operator|.
name|demarshall
condition|)
block|{
name|df
operator|=
literal|0
expr_stmt|;
comment|// make gcc happy
return|return
literal|false
return|;
block|}
else|else
name|df
operator|=
name|info
operator|.
name|demarshall
expr_stmt|;
block|}
name|QDBusArgument
name|copy
init|=
name|arg
decl_stmt|;
name|df
argument_list|(
name|copy
argument_list|,
name|data
argument_list|)
expr_stmt|;
return|return
literal|true
return|;
block|}
end_function
begin_comment
comment|/*!     \fn QDBusMetaType::signatureToType(const char *signature)     \internal      Returns the Qt meta type id for the given D-Bus signature for exactly one full type, given     by \a signature.      Note: this function only handles the basic D-Bus types.      \sa QDBusUtil::isValidSingleSignature(), typeToSignature(),         QVariant::type(), QVariant::userType() */
end_comment
begin_function
DECL|function|signatureToType
name|int
name|QDBusMetaType
operator|::
name|signatureToType
parameter_list|(
specifier|const
name|char
modifier|*
name|signature
parameter_list|)
block|{
if|if
condition|(
operator|!
name|signature
condition|)
return|return
name|QVariant
operator|::
name|Invalid
return|;
name|QDBusMetaTypeId
operator|::
name|init
argument_list|()
expr_stmt|;
switch|switch
condition|(
name|signature
index|[
literal|0
index|]
condition|)
block|{
case|case
name|DBUS_TYPE_BOOLEAN
case|:
return|return
name|QVariant
operator|::
name|Bool
return|;
case|case
name|DBUS_TYPE_BYTE
case|:
return|return
name|QMetaType
operator|::
name|UChar
return|;
case|case
name|DBUS_TYPE_INT16
case|:
return|return
name|QMetaType
operator|::
name|Short
return|;
case|case
name|DBUS_TYPE_UINT16
case|:
return|return
name|QMetaType
operator|::
name|UShort
return|;
case|case
name|DBUS_TYPE_INT32
case|:
return|return
name|QVariant
operator|::
name|Int
return|;
case|case
name|DBUS_TYPE_UINT32
case|:
return|return
name|QVariant
operator|::
name|UInt
return|;
case|case
name|DBUS_TYPE_INT64
case|:
return|return
name|QVariant
operator|::
name|LongLong
return|;
case|case
name|DBUS_TYPE_UINT64
case|:
return|return
name|QVariant
operator|::
name|ULongLong
return|;
case|case
name|DBUS_TYPE_DOUBLE
case|:
return|return
name|QVariant
operator|::
name|Double
return|;
case|case
name|DBUS_TYPE_STRING
case|:
return|return
name|QVariant
operator|::
name|String
return|;
case|case
name|DBUS_TYPE_OBJECT_PATH
case|:
return|return
name|QDBusMetaTypeId
operator|::
name|objectpath
return|;
case|case
name|DBUS_TYPE_SIGNATURE
case|:
return|return
name|QDBusMetaTypeId
operator|::
name|signature
return|;
case|case
name|DBUS_TYPE_UNIX_FD
case|:
return|return
name|QDBusMetaTypeId
operator|::
name|unixfd
return|;
case|case
name|DBUS_TYPE_VARIANT
case|:
return|return
name|QDBusMetaTypeId
operator|::
name|variant
return|;
case|case
name|DBUS_TYPE_ARRAY
case|:
comment|// special case
switch|switch
condition|(
name|signature
index|[
literal|1
index|]
condition|)
block|{
case|case
name|DBUS_TYPE_BYTE
case|:
return|return
name|QVariant
operator|::
name|ByteArray
return|;
case|case
name|DBUS_TYPE_STRING
case|:
return|return
name|QVariant
operator|::
name|StringList
return|;
case|case
name|DBUS_TYPE_VARIANT
case|:
return|return
name|QVariant
operator|::
name|List
return|;
case|case
name|DBUS_TYPE_OBJECT_PATH
case|:
return|return
name|qMetaTypeId
argument_list|<
name|QList
argument_list|<
name|QDBusObjectPath
argument_list|>
argument_list|>
argument_list|()
return|;
case|case
name|DBUS_TYPE_SIGNATURE
case|:
return|return
name|qMetaTypeId
argument_list|<
name|QList
argument_list|<
name|QDBusSignature
argument_list|>
argument_list|>
argument_list|()
return|;
block|}
comment|// fall through
default|default:
return|return
name|QVariant
operator|::
name|Invalid
return|;
block|}
block|}
end_function
begin_comment
comment|/*!     \fn QDBusMetaType::typeToSignature(int type)     \internal       Returns the D-Bus signature equivalent to the supplied meta type id \a type.      More types can be registered with the qDBusRegisterMetaType() function.      \sa QDBusUtil::isValidSingleSignature(), signatureToType(),         QVariant::type(), QVariant::userType() */
end_comment
begin_function
DECL|function|typeToSignature
specifier|const
name|char
modifier|*
name|QDBusMetaType
operator|::
name|typeToSignature
parameter_list|(
name|int
name|type
parameter_list|)
block|{
comment|// check if it's a static type
switch|switch
condition|(
name|type
condition|)
block|{
case|case
name|QMetaType
operator|::
name|UChar
case|:
return|return
name|DBUS_TYPE_BYTE_AS_STRING
return|;
case|case
name|QVariant
operator|::
name|Bool
case|:
return|return
name|DBUS_TYPE_BOOLEAN_AS_STRING
return|;
case|case
name|QMetaType
operator|::
name|Short
case|:
return|return
name|DBUS_TYPE_INT16_AS_STRING
return|;
case|case
name|QMetaType
operator|::
name|UShort
case|:
return|return
name|DBUS_TYPE_UINT16_AS_STRING
return|;
case|case
name|QVariant
operator|::
name|Int
case|:
return|return
name|DBUS_TYPE_INT32_AS_STRING
return|;
case|case
name|QVariant
operator|::
name|UInt
case|:
return|return
name|DBUS_TYPE_UINT32_AS_STRING
return|;
case|case
name|QVariant
operator|::
name|LongLong
case|:
return|return
name|DBUS_TYPE_INT64_AS_STRING
return|;
case|case
name|QVariant
operator|::
name|ULongLong
case|:
return|return
name|DBUS_TYPE_UINT64_AS_STRING
return|;
case|case
name|QVariant
operator|::
name|Double
case|:
return|return
name|DBUS_TYPE_DOUBLE_AS_STRING
return|;
case|case
name|QVariant
operator|::
name|String
case|:
return|return
name|DBUS_TYPE_STRING_AS_STRING
return|;
case|case
name|QVariant
operator|::
name|StringList
case|:
return|return
name|DBUS_TYPE_ARRAY_AS_STRING
name|DBUS_TYPE_STRING_AS_STRING
return|;
comment|// as
case|case
name|QVariant
operator|::
name|ByteArray
case|:
return|return
name|DBUS_TYPE_ARRAY_AS_STRING
name|DBUS_TYPE_BYTE_AS_STRING
return|;
comment|// ay
block|}
name|QDBusMetaTypeId
operator|::
name|init
argument_list|()
expr_stmt|;
if|if
condition|(
name|type
operator|==
name|QDBusMetaTypeId
operator|::
name|variant
condition|)
return|return
name|DBUS_TYPE_VARIANT_AS_STRING
return|;
elseif|else
if|if
condition|(
name|type
operator|==
name|QDBusMetaTypeId
operator|::
name|objectpath
condition|)
return|return
name|DBUS_TYPE_OBJECT_PATH_AS_STRING
return|;
elseif|else
if|if
condition|(
name|type
operator|==
name|QDBusMetaTypeId
operator|::
name|signature
condition|)
return|return
name|DBUS_TYPE_SIGNATURE_AS_STRING
return|;
elseif|else
if|if
condition|(
name|type
operator|==
name|QDBusMetaTypeId
operator|::
name|unixfd
condition|)
return|return
name|DBUS_TYPE_UNIX_FD_AS_STRING
return|;
comment|// try the database
name|QVector
argument_list|<
name|QDBusCustomTypeInfo
argument_list|>
modifier|*
name|ct
init|=
name|customTypes
argument_list|()
decl_stmt|;
block|{
name|QReadLocker
name|locker
argument_list|(
name|customTypesLock
argument_list|()
argument_list|)
decl_stmt|;
if|if
condition|(
name|type
operator|>=
name|ct
operator|->
name|size
argument_list|()
condition|)
return|return
literal|0
return|;
comment|// type not registered with us
specifier|const
name|QDBusCustomTypeInfo
modifier|&
name|info
init|=
operator|(
operator|*
name|ct
operator|)
operator|.
name|at
argument_list|(
name|type
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|info
operator|.
name|signature
operator|.
name|isNull
argument_list|()
condition|)
return|return
name|info
operator|.
name|signature
return|;
if|if
condition|(
operator|!
name|info
operator|.
name|marshall
condition|)
return|return
literal|0
return|;
comment|// type not registered with us
block|}
comment|// call to user code to construct the signature type
name|QDBusCustomTypeInfo
modifier|*
name|info
decl_stmt|;
block|{
comment|// createSignature will never return a null QByteArray
comment|// if there was an error, it'll return ""
name|QByteArray
name|signature
init|=
name|QDBusArgumentPrivate
operator|::
name|createSignature
argument_list|(
name|type
argument_list|)
decl_stmt|;
comment|// re-acquire lock
name|QWriteLocker
name|locker
argument_list|(
name|customTypesLock
argument_list|()
argument_list|)
decl_stmt|;
name|info
operator|=
operator|&
operator|(
operator|*
name|ct
operator|)
index|[
name|type
index|]
expr_stmt|;
name|info
operator|->
name|signature
operator|=
name|signature
expr_stmt|;
block|}
return|return
name|info
operator|->
name|signature
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
