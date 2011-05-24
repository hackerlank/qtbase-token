begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QDebug>
end_include
begin_include
include|#
directive|include
file|<QtCore>
end_include
begin_include
include|#
directive|include
file|<poll.h>
end_include
begin_include
include|#
directive|include
file|<dbus/dbus.h>
end_include
begin_include
include|#
directive|include
file|<dbus/dbus-glib-lowlevel.h>
end_include
begin_include
include|#
directive|include
file|<glib.h>
end_include
begin_include
include|#
directive|include
file|"dbusdispatcher.h"
end_include
begin_namespace
DECL|namespace|Maemo
namespace|namespace
name|Maemo
block|{
comment|/*!     \class Maemo::DBusDispatcher      \brief DBusDispatcher is a class that can send DBUS method call     messages and receive unicast signals from DBUS objects. */
DECL|class|DBusDispatcherPrivate
class|class
name|DBusDispatcherPrivate
block|{
public|public:
DECL|function|DBusDispatcherPrivate
name|DBusDispatcherPrivate
parameter_list|(
specifier|const
name|QString
modifier|&
name|service
parameter_list|,
specifier|const
name|QString
modifier|&
name|path
parameter_list|,
specifier|const
name|QString
modifier|&
name|interface
parameter_list|,
specifier|const
name|QString
modifier|&
name|signalPath
parameter_list|)
member_init_list|:
name|service
argument_list|(
name|service
argument_list|)
member_init_list|,
name|path
argument_list|(
name|path
argument_list|)
member_init_list|,
name|interface
argument_list|(
name|interface
argument_list|)
member_init_list|,
name|signalPath
argument_list|(
name|signalPath
argument_list|)
member_init_list|,
name|connection
argument_list|(
literal|0
argument_list|)
block|{
name|memset
argument_list|(
operator|&
name|signal_vtable
argument_list|,
literal|0
argument_list|,
sizeof|sizeof
argument_list|(
name|signal_vtable
argument_list|)
argument_list|)
expr_stmt|;
block|}
DECL|function|~DBusDispatcherPrivate
name|~
name|DBusDispatcherPrivate
parameter_list|()
block|{
foreach|foreach
control|(
name|DBusPendingCall
modifier|*
name|call
decl|,
name|pending_calls
control|)
block|{
name|dbus_pending_call_cancel
argument_list|(
name|call
argument_list|)
expr_stmt|;
name|dbus_pending_call_unref
argument_list|(
name|call
argument_list|)
expr_stmt|;
block|}
block|}
DECL|member|service
name|QString
name|service
decl_stmt|;
DECL|member|path
name|QString
name|path
decl_stmt|;
DECL|member|interface
name|QString
name|interface
decl_stmt|;
DECL|member|signalPath
name|QString
name|signalPath
decl_stmt|;
DECL|member|connection
name|struct
name|DBusConnection
modifier|*
name|connection
decl_stmt|;
DECL|member|pending_calls
name|QList
argument_list|<
name|DBusPendingCall
modifier|*
argument_list|>
name|pending_calls
decl_stmt|;
DECL|member|signal_vtable
name|struct
name|DBusObjectPathVTable
name|signal_vtable
decl_stmt|;
block|}
class|;
DECL|function|constantVariantList
specifier|static
name|bool
name|constantVariantList
parameter_list|(
specifier|const
name|QVariantList
modifier|&
name|variantList
parameter_list|)
block|{
comment|// Special case, empty list == empty struct
if|if
condition|(
name|variantList
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
return|return
literal|false
return|;
block|}
else|else
block|{
name|QVariant
operator|::
name|Type
name|type
init|=
name|variantList
index|[
literal|0
index|]
operator|.
name|type
argument_list|()
decl_stmt|;
comment|// Iterate items in the list and check if they are same type
foreach|foreach
control|(
name|QVariant
name|variant
decl|,
name|variantList
control|)
block|{
if|if
condition|(
name|variant
operator|.
name|type
argument_list|()
operator|!=
name|type
condition|)
block|{
return|return
literal|false
return|;
block|}
block|}
block|}
return|return
literal|true
return|;
block|}
DECL|function|variantToSignature
specifier|static
name|QString
name|variantToSignature
parameter_list|(
specifier|const
name|QVariant
modifier|&
name|argument
parameter_list|,
name|bool
name|constantList
init|=
literal|true
parameter_list|)
block|{
switch|switch
condition|(
name|argument
operator|.
name|type
argument_list|()
condition|)
block|{
case|case
name|QVariant
operator|::
name|Bool
case|:
return|return
literal|"b"
return|;
case|case
name|QVariant
operator|::
name|ByteArray
case|:
return|return
literal|"ay"
return|;
case|case
name|QVariant
operator|::
name|Char
case|:
return|return
literal|"y"
return|;
case|case
name|QVariant
operator|::
name|Int
case|:
return|return
literal|"i"
return|;
case|case
name|QVariant
operator|::
name|UInt
case|:
return|return
literal|"u"
return|;
case|case
name|QVariant
operator|::
name|StringList
case|:
return|return
literal|"as"
return|;
case|case
name|QVariant
operator|::
name|String
case|:
return|return
literal|"s"
return|;
case|case
name|QVariant
operator|::
name|LongLong
case|:
return|return
literal|"x"
return|;
case|case
name|QVariant
operator|::
name|ULongLong
case|:
return|return
literal|"t"
return|;
case|case
name|QVariant
operator|::
name|List
case|:
block|{
name|QString
name|signature
decl_stmt|;
name|QVariantList
name|variantList
init|=
name|argument
operator|.
name|toList
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
name|constantList
condition|)
block|{
name|signature
operator|+=
name|DBUS_STRUCT_BEGIN_CHAR_AS_STRING
expr_stmt|;
foreach|foreach
control|(
name|QVariant
name|listItem
decl|,
name|variantList
control|)
block|{
name|signature
operator|+=
name|variantToSignature
argument_list|(
name|listItem
argument_list|)
expr_stmt|;
block|}
name|signature
operator|+=
name|DBUS_STRUCT_END_CHAR_AS_STRING
expr_stmt|;
block|}
else|else
block|{
if|if
condition|(
name|variantList
operator|.
name|isEmpty
argument_list|()
condition|)
return|return
literal|""
return|;
name|signature
operator|=
literal|"a"
operator|+
name|variantToSignature
argument_list|(
name|variantList
index|[
literal|0
index|]
argument_list|)
expr_stmt|;
block|}
return|return
name|signature
return|;
block|}
default|default:
name|qDebug
argument_list|()
operator|<<
literal|"Unsupported variant type: "
operator|<<
name|argument
operator|.
name|type
argument_list|()
expr_stmt|;
break|break;
block|}
return|return
literal|""
return|;
block|}
DECL|function|appendVariantToDBusMessage
specifier|static
name|bool
name|appendVariantToDBusMessage
parameter_list|(
specifier|const
name|QVariant
modifier|&
name|argument
parameter_list|,
name|DBusMessageIter
modifier|*
name|dbus_iter
parameter_list|)
block|{
name|int
name|idx
init|=
literal|0
decl_stmt|;
name|DBusMessageIter
name|array_iter
decl_stmt|;
name|QStringList
name|str_list
decl_stmt|;
name|dbus_bool_t
name|bool_data
decl_stmt|;
name|dbus_int32_t
name|int32_data
decl_stmt|;
name|dbus_uint32_t
name|uint32_data
decl_stmt|;
name|dbus_int64_t
name|int64_data
decl_stmt|;
name|dbus_uint64_t
name|uint64_data
decl_stmt|;
name|char
modifier|*
name|str_data
decl_stmt|;
name|char
name|char_data
decl_stmt|;
switch|switch
condition|(
name|argument
operator|.
name|type
argument_list|()
condition|)
block|{
case|case
name|QVariant
operator|::
name|Bool
case|:
name|bool_data
operator|=
name|argument
operator|.
name|toBool
argument_list|()
expr_stmt|;
name|dbus_message_iter_append_basic
argument_list|(
name|dbus_iter
argument_list|,
name|DBUS_TYPE_BOOLEAN
argument_list|,
operator|&
name|bool_data
argument_list|)
expr_stmt|;
break|break;
case|case
name|QVariant
operator|::
name|ByteArray
case|:
name|str_data
operator|=
name|argument
operator|.
name|toByteArray
argument_list|()
operator|.
name|data
argument_list|()
expr_stmt|;
name|dbus_message_iter_open_container
argument_list|(
name|dbus_iter
argument_list|,
name|DBUS_TYPE_ARRAY
argument_list|,
name|DBUS_TYPE_BYTE_AS_STRING
argument_list|,
operator|&
name|array_iter
argument_list|)
expr_stmt|;
name|dbus_message_iter_append_fixed_array
argument_list|(
operator|&
name|array_iter
argument_list|,
name|DBUS_TYPE_BYTE
argument_list|,
operator|&
name|str_data
argument_list|,
name|argument
operator|.
name|toByteArray
argument_list|()
operator|.
name|size
argument_list|()
argument_list|)
expr_stmt|;
name|dbus_message_iter_close_container
argument_list|(
name|dbus_iter
argument_list|,
operator|&
name|array_iter
argument_list|)
expr_stmt|;
break|break;
case|case
name|QVariant
operator|::
name|Char
case|:
name|char_data
operator|=
name|argument
operator|.
name|toChar
argument_list|()
operator|.
name|toAscii
argument_list|()
expr_stmt|;
name|dbus_message_iter_append_basic
argument_list|(
name|dbus_iter
argument_list|,
name|DBUS_TYPE_BYTE
argument_list|,
operator|&
name|char_data
argument_list|)
expr_stmt|;
break|break;
case|case
name|QVariant
operator|::
name|Int
case|:
name|int32_data
operator|=
name|argument
operator|.
name|toInt
argument_list|()
expr_stmt|;
name|dbus_message_iter_append_basic
argument_list|(
name|dbus_iter
argument_list|,
name|DBUS_TYPE_INT32
argument_list|,
operator|&
name|int32_data
argument_list|)
expr_stmt|;
break|break;
case|case
name|QVariant
operator|::
name|String
case|:
block|{
name|QByteArray
name|data
init|=
name|argument
operator|.
name|toString
argument_list|()
operator|.
name|toLatin1
argument_list|()
decl_stmt|;
name|str_data
operator|=
name|data
operator|.
name|data
argument_list|()
expr_stmt|;
name|dbus_message_iter_append_basic
argument_list|(
name|dbus_iter
argument_list|,
name|DBUS_TYPE_STRING
argument_list|,
operator|&
name|str_data
argument_list|)
expr_stmt|;
break|break;
block|}
case|case
name|QVariant
operator|::
name|StringList
case|:
name|str_list
operator|=
name|argument
operator|.
name|toStringList
argument_list|()
expr_stmt|;
name|dbus_message_iter_open_container
argument_list|(
name|dbus_iter
argument_list|,
name|DBUS_TYPE_ARRAY
argument_list|,
literal|"s"
argument_list|,
operator|&
name|array_iter
argument_list|)
expr_stmt|;
for|for
control|(
name|idx
operator|=
literal|0
init|;
name|idx
operator|<
name|str_list
operator|.
name|size
argument_list|()
condition|;
name|idx
operator|++
control|)
block|{
name|QByteArray
name|data
init|=
name|str_list
operator|.
name|at
argument_list|(
name|idx
argument_list|)
operator|.
name|toLatin1
argument_list|()
decl_stmt|;
name|str_data
operator|=
name|data
operator|.
name|data
argument_list|()
expr_stmt|;
name|dbus_message_iter_append_basic
argument_list|(
operator|&
name|array_iter
argument_list|,
name|DBUS_TYPE_STRING
argument_list|,
operator|&
name|str_data
argument_list|)
expr_stmt|;
block|}
name|dbus_message_iter_close_container
argument_list|(
name|dbus_iter
argument_list|,
operator|&
name|array_iter
argument_list|)
expr_stmt|;
break|break;
case|case
name|QVariant
operator|::
name|UInt
case|:
name|uint32_data
operator|=
name|argument
operator|.
name|toUInt
argument_list|()
expr_stmt|;
name|dbus_message_iter_append_basic
argument_list|(
name|dbus_iter
argument_list|,
name|DBUS_TYPE_UINT32
argument_list|,
operator|&
name|uint32_data
argument_list|)
expr_stmt|;
break|break;
case|case
name|QVariant
operator|::
name|ULongLong
case|:
name|uint64_data
operator|=
name|argument
operator|.
name|toULongLong
argument_list|()
expr_stmt|;
name|dbus_message_iter_append_basic
argument_list|(
name|dbus_iter
argument_list|,
name|DBUS_TYPE_UINT64
argument_list|,
operator|&
name|uint64_data
argument_list|)
expr_stmt|;
break|break;
case|case
name|QVariant
operator|::
name|LongLong
case|:
name|int64_data
operator|=
name|argument
operator|.
name|toLongLong
argument_list|()
expr_stmt|;
name|dbus_message_iter_append_basic
argument_list|(
name|dbus_iter
argument_list|,
name|DBUS_TYPE_INT64
argument_list|,
operator|&
name|int64_data
argument_list|)
expr_stmt|;
break|break;
case|case
name|QVariant
operator|::
name|List
case|:
block|{
name|QVariantList
name|variantList
init|=
name|argument
operator|.
name|toList
argument_list|()
decl_stmt|;
name|bool
name|constantList
init|=
name|constantVariantList
argument_list|(
name|variantList
argument_list|)
decl_stmt|;
name|DBusMessageIter
name|array_iter
decl_stmt|;
comment|// List is mapped either as an DBUS array (all items same type)
comment|// DBUS struct (variable types) depending on constantList
if|if
condition|(
name|constantList
condition|)
block|{
comment|// Resolve the signature for the first item
name|QString
name|signature
init|=
literal|""
decl_stmt|;
if|if
condition|(
operator|!
name|variantList
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|signature
operator|=
name|variantToSignature
argument_list|(
name|variantList
index|[
literal|0
index|]
argument_list|,
name|constantVariantList
argument_list|(
name|variantList
index|[
literal|0
index|]
operator|.
name|toList
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
block|}
comment|// Mapped as DBUS array
name|dbus_message_iter_open_container
argument_list|(
name|dbus_iter
argument_list|,
name|DBUS_TYPE_ARRAY
argument_list|,
name|signature
operator|.
name|toAscii
argument_list|()
argument_list|,
operator|&
name|array_iter
argument_list|)
expr_stmt|;
foreach|foreach
control|(
name|QVariant
name|listItem
decl|,
name|variantList
control|)
block|{
name|appendVariantToDBusMessage
argument_list|(
name|listItem
argument_list|,
operator|&
name|array_iter
argument_list|)
expr_stmt|;
block|}
name|dbus_message_iter_close_container
argument_list|(
name|dbus_iter
argument_list|,
operator|&
name|array_iter
argument_list|)
expr_stmt|;
block|}
else|else
block|{
comment|// Mapped as DBUS struct
name|dbus_message_iter_open_container
argument_list|(
name|dbus_iter
argument_list|,
name|DBUS_TYPE_STRUCT
argument_list|,
name|NULL
argument_list|,
operator|&
name|array_iter
argument_list|)
expr_stmt|;
foreach|foreach
control|(
name|QVariant
name|listItem
decl|,
name|variantList
control|)
block|{
name|appendVariantToDBusMessage
argument_list|(
name|listItem
argument_list|,
operator|&
name|array_iter
argument_list|)
expr_stmt|;
block|}
name|dbus_message_iter_close_container
argument_list|(
name|dbus_iter
argument_list|,
operator|&
name|array_iter
argument_list|)
expr_stmt|;
block|}
break|break;
block|}
default|default:
name|qDebug
argument_list|()
operator|<<
literal|"Unsupported variant type: "
operator|<<
name|argument
operator|.
name|type
argument_list|()
expr_stmt|;
break|break;
block|}
return|return
literal|true
return|;
block|}
DECL|function|getVariantFromDBusMessage
specifier|static
name|QVariant
name|getVariantFromDBusMessage
parameter_list|(
name|DBusMessageIter
modifier|*
name|iter
parameter_list|)
block|{
name|dbus_bool_t
name|bool_data
decl_stmt|;
name|dbus_int32_t
name|int32_data
decl_stmt|;
name|dbus_uint32_t
name|uint32_data
decl_stmt|;
name|dbus_int64_t
name|int64_data
decl_stmt|;
name|dbus_uint64_t
name|uint64_data
decl_stmt|;
name|char
modifier|*
name|str_data
decl_stmt|;
name|char
name|char_data
decl_stmt|;
name|int
name|argtype
init|=
name|dbus_message_iter_get_arg_type
argument_list|(
name|iter
argument_list|)
decl_stmt|;
switch|switch
condition|(
name|argtype
condition|)
block|{
case|case
name|DBUS_TYPE_BOOLEAN
case|:
block|{
name|dbus_message_iter_get_basic
argument_list|(
name|iter
argument_list|,
operator|&
name|bool_data
argument_list|)
expr_stmt|;
name|QVariant
name|variant
argument_list|(
operator|(
name|bool
operator|)
name|bool_data
argument_list|)
decl_stmt|;
return|return
name|variant
return|;
block|}
case|case
name|DBUS_TYPE_ARRAY
case|:
block|{
comment|// Handle all arrays here
name|int
name|elem_type
init|=
name|dbus_message_iter_get_element_type
argument_list|(
name|iter
argument_list|)
decl_stmt|;
name|DBusMessageIter
name|array_iter
decl_stmt|;
name|dbus_message_iter_recurse
argument_list|(
name|iter
argument_list|,
operator|&
name|array_iter
argument_list|)
expr_stmt|;
if|if
condition|(
name|elem_type
operator|==
name|DBUS_TYPE_BYTE
condition|)
block|{
name|QByteArray
name|byte_array
decl_stmt|;
do|do
block|{
name|dbus_message_iter_get_basic
argument_list|(
operator|&
name|array_iter
argument_list|,
operator|&
name|char_data
argument_list|)
expr_stmt|;
name|byte_array
operator|.
name|append
argument_list|(
name|char_data
argument_list|)
expr_stmt|;
block|}
do|while
condition|(
name|dbus_message_iter_next
argument_list|(
operator|&
name|array_iter
argument_list|)
condition|)
do|;
name|QVariant
name|variant
argument_list|(
name|byte_array
argument_list|)
decl_stmt|;
return|return
name|variant
return|;
block|}
elseif|else
if|if
condition|(
name|elem_type
operator|==
name|DBUS_TYPE_STRING
condition|)
block|{
name|QStringList
name|str_list
decl_stmt|;
do|do
block|{
name|dbus_message_iter_get_basic
argument_list|(
operator|&
name|array_iter
argument_list|,
operator|&
name|str_data
argument_list|)
expr_stmt|;
name|str_list
operator|.
name|append
argument_list|(
name|str_data
argument_list|)
expr_stmt|;
block|}
do|while
condition|(
name|dbus_message_iter_next
argument_list|(
operator|&
name|array_iter
argument_list|)
condition|)
do|;
name|QVariant
name|variant
argument_list|(
name|str_list
argument_list|)
decl_stmt|;
return|return
name|variant
return|;
block|}
else|else
block|{
name|QVariantList
name|variantList
decl_stmt|;
do|do
block|{
name|variantList
operator|<<
name|getVariantFromDBusMessage
argument_list|(
operator|&
name|array_iter
argument_list|)
expr_stmt|;
block|}
do|while
condition|(
name|dbus_message_iter_next
argument_list|(
operator|&
name|array_iter
argument_list|)
condition|)
do|;
name|QVariant
name|variant
argument_list|(
name|variantList
argument_list|)
decl_stmt|;
return|return
name|variant
return|;
block|}
break|break;
block|}
case|case
name|DBUS_TYPE_BYTE
case|:
block|{
name|dbus_message_iter_get_basic
argument_list|(
name|iter
argument_list|,
operator|&
name|char_data
argument_list|)
expr_stmt|;
name|QChar
name|ch
argument_list|(
name|char_data
argument_list|)
decl_stmt|;
name|QVariant
name|variant
argument_list|(
name|ch
argument_list|)
decl_stmt|;
return|return
name|variant
return|;
block|}
case|case
name|DBUS_TYPE_INT32
case|:
block|{
name|dbus_message_iter_get_basic
argument_list|(
name|iter
argument_list|,
operator|&
name|int32_data
argument_list|)
expr_stmt|;
name|QVariant
name|variant
argument_list|(
operator|(
name|int
operator|)
name|int32_data
argument_list|)
decl_stmt|;
return|return
name|variant
return|;
block|}
case|case
name|DBUS_TYPE_UINT32
case|:
block|{
name|dbus_message_iter_get_basic
argument_list|(
name|iter
argument_list|,
operator|&
name|uint32_data
argument_list|)
expr_stmt|;
name|QVariant
name|variant
argument_list|(
operator|(
name|uint
operator|)
name|uint32_data
argument_list|)
decl_stmt|;
return|return
name|variant
return|;
block|}
case|case
name|DBUS_TYPE_STRING
case|:
block|{
name|dbus_message_iter_get_basic
argument_list|(
name|iter
argument_list|,
operator|&
name|str_data
argument_list|)
expr_stmt|;
name|QString
name|str
argument_list|(
name|str_data
argument_list|)
decl_stmt|;
name|QVariant
name|variant
argument_list|(
name|str
argument_list|)
decl_stmt|;
return|return
name|variant
return|;
block|}
case|case
name|DBUS_TYPE_INT64
case|:
block|{
name|dbus_message_iter_get_basic
argument_list|(
name|iter
argument_list|,
operator|&
name|int64_data
argument_list|)
expr_stmt|;
name|QVariant
name|variant
argument_list|(
operator|(
name|qlonglong
operator|)
name|int64_data
argument_list|)
decl_stmt|;
return|return
name|variant
return|;
block|}
case|case
name|DBUS_TYPE_UINT64
case|:
block|{
name|dbus_message_iter_get_basic
argument_list|(
name|iter
argument_list|,
operator|&
name|uint64_data
argument_list|)
expr_stmt|;
name|QVariant
name|variant
argument_list|(
operator|(
name|qulonglong
operator|)
name|uint64_data
argument_list|)
decl_stmt|;
return|return
name|variant
return|;
block|}
case|case
name|DBUS_TYPE_STRUCT
case|:
block|{
comment|// Handle all structs here
name|DBusMessageIter
name|struct_iter
decl_stmt|;
name|dbus_message_iter_recurse
argument_list|(
name|iter
argument_list|,
operator|&
name|struct_iter
argument_list|)
expr_stmt|;
name|QVariantList
name|variantList
decl_stmt|;
do|do
block|{
name|variantList
operator|<<
name|getVariantFromDBusMessage
argument_list|(
operator|&
name|struct_iter
argument_list|)
expr_stmt|;
block|}
do|while
condition|(
name|dbus_message_iter_next
argument_list|(
operator|&
name|struct_iter
argument_list|)
condition|)
do|;
name|QVariant
name|variant
argument_list|(
name|variantList
argument_list|)
decl_stmt|;
return|return
name|variant
return|;
block|}
default|default:
name|qDebug
argument_list|()
operator|<<
literal|"Unsupported DBUS type: "
operator|<<
name|argtype
expr_stmt|;
block|}
return|return
name|QVariant
argument_list|()
return|;
block|}
DECL|function|signalHandler
specifier|static
name|DBusHandlerResult
name|signalHandler
parameter_list|(
name|DBusConnection
modifier|*
name|connection
parameter_list|,
name|DBusMessage
modifier|*
name|message
parameter_list|,
name|void
modifier|*
name|object_ref
parameter_list|)
block|{
operator|(
name|void
operator|)
name|connection
expr_stmt|;
name|QString
name|interface
decl_stmt|;
name|QString
name|signal
decl_stmt|;
name|DBusDispatcher
modifier|*
name|dispatcher
init|=
operator|(
name|DBusDispatcher
operator|*
operator|)
name|object_ref
decl_stmt|;
if|if
condition|(
name|dbus_message_get_type
argument_list|(
name|message
argument_list|)
operator|==
name|DBUS_MESSAGE_TYPE_SIGNAL
condition|)
block|{
name|interface
operator|=
name|dbus_message_get_interface
argument_list|(
name|message
argument_list|)
expr_stmt|;
name|signal
operator|=
name|dbus_message_get_member
argument_list|(
name|message
argument_list|)
expr_stmt|;
name|QList
argument_list|<
name|QVariant
argument_list|>
name|arglist
decl_stmt|;
name|DBusMessageIter
name|dbus_iter
decl_stmt|;
if|if
condition|(
name|dbus_message_iter_init
argument_list|(
name|message
argument_list|,
operator|&
name|dbus_iter
argument_list|)
condition|)
block|{
comment|// Read return arguments
while|while
condition|(
name|dbus_message_iter_get_arg_type
argument_list|(
operator|&
name|dbus_iter
argument_list|)
operator|!=
name|DBUS_TYPE_INVALID
condition|)
block|{
name|arglist
operator|<<
name|getVariantFromDBusMessage
argument_list|(
operator|&
name|dbus_iter
argument_list|)
expr_stmt|;
name|dbus_message_iter_next
argument_list|(
operator|&
name|dbus_iter
argument_list|)
expr_stmt|;
block|}
block|}
name|dispatcher
operator|->
name|emitSignalReceived
argument_list|(
name|interface
argument_list|,
name|signal
argument_list|,
name|arglist
argument_list|)
expr_stmt|;
return|return
name|DBUS_HANDLER_RESULT_HANDLED
return|;
block|}
operator|(
name|void
operator|)
name|message
expr_stmt|;
return|return
name|DBUS_HANDLER_RESULT_NOT_YET_HANDLED
return|;
block|}
DECL|function|DBusDispatcher
name|DBusDispatcher
operator|::
name|DBusDispatcher
parameter_list|(
specifier|const
name|QString
modifier|&
name|service
parameter_list|,
specifier|const
name|QString
modifier|&
name|path
parameter_list|,
specifier|const
name|QString
modifier|&
name|interface
parameter_list|,
name|QObject
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QObject
argument_list|(
name|parent
argument_list|)
member_init_list|,
name|d_ptr
argument_list|(
operator|new
name|DBusDispatcherPrivate
argument_list|(
name|service
argument_list|,
name|path
argument_list|,
name|interface
argument_list|,
name|path
argument_list|)
argument_list|)
block|{
name|setupDBus
argument_list|()
expr_stmt|;
block|}
DECL|function|DBusDispatcher
name|DBusDispatcher
operator|::
name|DBusDispatcher
parameter_list|(
specifier|const
name|QString
modifier|&
name|service
parameter_list|,
specifier|const
name|QString
modifier|&
name|path
parameter_list|,
specifier|const
name|QString
modifier|&
name|interface
parameter_list|,
specifier|const
name|QString
modifier|&
name|signalPath
parameter_list|,
name|QObject
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QObject
argument_list|(
name|parent
argument_list|)
member_init_list|,
name|d_ptr
argument_list|(
operator|new
name|DBusDispatcherPrivate
argument_list|(
name|service
argument_list|,
name|path
argument_list|,
name|interface
argument_list|,
name|signalPath
argument_list|)
argument_list|)
block|{
name|setupDBus
argument_list|()
expr_stmt|;
block|}
DECL|function|~DBusDispatcher
name|DBusDispatcher
operator|::
name|~
name|DBusDispatcher
parameter_list|()
block|{
if|if
condition|(
name|d_ptr
operator|->
name|connection
condition|)
block|{
name|dbus_connection_close
argument_list|(
name|d_ptr
operator|->
name|connection
argument_list|)
expr_stmt|;
name|dbus_connection_unref
argument_list|(
name|d_ptr
operator|->
name|connection
argument_list|)
expr_stmt|;
block|}
operator|delete
name|d_ptr
expr_stmt|;
block|}
DECL|function|setupDBus
name|void
name|DBusDispatcher
operator|::
name|setupDBus
parameter_list|()
block|{
name|d_ptr
operator|->
name|connection
operator|=
name|dbus_bus_get_private
argument_list|(
name|DBUS_BUS_SYSTEM
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
if|if
condition|(
name|d_ptr
operator|->
name|connection
operator|==
name|NULL
condition|)
name|qDebug
argument_list|()
operator|<<
literal|"Unable to get DBUS connection!"
expr_stmt|;
else|else
block|{
name|d_ptr
operator|->
name|signal_vtable
operator|.
name|message_function
operator|=
name|signalHandler
expr_stmt|;
name|dbus_connection_set_exit_on_disconnect
argument_list|(
name|d_ptr
operator|->
name|connection
argument_list|,
name|FALSE
argument_list|)
expr_stmt|;
name|dbus_connection_setup_with_g_main
argument_list|(
name|d_ptr
operator|->
name|connection
argument_list|,
name|g_main_context_get_thread_default
argument_list|()
argument_list|)
expr_stmt|;
name|dbus_connection_register_object_path
argument_list|(
name|d_ptr
operator|->
name|connection
argument_list|,
name|d_ptr
operator|->
name|signalPath
operator|.
name|toLatin1
argument_list|()
argument_list|,
operator|&
name|d_ptr
operator|->
name|signal_vtable
argument_list|,
name|this
argument_list|)
expr_stmt|;
block|}
block|}
DECL|function|prepareDBusCall
specifier|static
name|DBusMessage
modifier|*
name|prepareDBusCall
parameter_list|(
specifier|const
name|QString
modifier|&
name|service
parameter_list|,
specifier|const
name|QString
modifier|&
name|path
parameter_list|,
specifier|const
name|QString
modifier|&
name|interface
parameter_list|,
specifier|const
name|QString
modifier|&
name|method
parameter_list|,
specifier|const
name|QVariant
modifier|&
name|arg1
init|=
name|QVariant
argument_list|()
parameter_list|,
specifier|const
name|QVariant
modifier|&
name|arg2
init|=
name|QVariant
argument_list|()
parameter_list|,
specifier|const
name|QVariant
modifier|&
name|arg3
init|=
name|QVariant
argument_list|()
parameter_list|,
specifier|const
name|QVariant
modifier|&
name|arg4
init|=
name|QVariant
argument_list|()
parameter_list|,
specifier|const
name|QVariant
modifier|&
name|arg5
init|=
name|QVariant
argument_list|()
parameter_list|,
specifier|const
name|QVariant
modifier|&
name|arg6
init|=
name|QVariant
argument_list|()
parameter_list|,
specifier|const
name|QVariant
modifier|&
name|arg7
init|=
name|QVariant
argument_list|()
parameter_list|,
specifier|const
name|QVariant
modifier|&
name|arg8
init|=
name|QVariant
argument_list|()
parameter_list|)
block|{
name|DBusMessage
modifier|*
name|message
init|=
name|dbus_message_new_method_call
argument_list|(
name|service
operator|.
name|toLatin1
argument_list|()
argument_list|,
name|path
operator|.
name|toLatin1
argument_list|()
argument_list|,
name|interface
operator|.
name|toLatin1
argument_list|()
argument_list|,
name|method
operator|.
name|toLatin1
argument_list|()
argument_list|)
decl_stmt|;
name|DBusMessageIter
name|dbus_iter
decl_stmt|;
comment|// Append variants to DBUS message
name|QList
argument_list|<
name|QVariant
argument_list|>
name|arglist
decl_stmt|;
if|if
condition|(
name|arg1
operator|.
name|isValid
argument_list|()
condition|)
name|arglist
operator|<<
name|arg1
expr_stmt|;
if|if
condition|(
name|arg2
operator|.
name|isValid
argument_list|()
condition|)
name|arglist
operator|<<
name|arg2
expr_stmt|;
if|if
condition|(
name|arg3
operator|.
name|isValid
argument_list|()
condition|)
name|arglist
operator|<<
name|arg3
expr_stmt|;
if|if
condition|(
name|arg4
operator|.
name|isValid
argument_list|()
condition|)
name|arglist
operator|<<
name|arg4
expr_stmt|;
if|if
condition|(
name|arg5
operator|.
name|isValid
argument_list|()
condition|)
name|arglist
operator|<<
name|arg5
expr_stmt|;
if|if
condition|(
name|arg6
operator|.
name|isValid
argument_list|()
condition|)
name|arglist
operator|<<
name|arg6
expr_stmt|;
if|if
condition|(
name|arg7
operator|.
name|isValid
argument_list|()
condition|)
name|arglist
operator|<<
name|arg7
expr_stmt|;
if|if
condition|(
name|arg8
operator|.
name|isValid
argument_list|()
condition|)
name|arglist
operator|<<
name|arg8
expr_stmt|;
name|dbus_message_iter_init_append
argument_list|(
name|message
argument_list|,
operator|&
name|dbus_iter
argument_list|)
expr_stmt|;
while|while
condition|(
operator|!
name|arglist
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|QVariant
name|argument
init|=
name|arglist
operator|.
name|takeFirst
argument_list|()
decl_stmt|;
name|appendVariantToDBusMessage
argument_list|(
name|argument
argument_list|,
operator|&
name|dbus_iter
argument_list|)
expr_stmt|;
block|}
return|return
name|message
return|;
block|}
DECL|function|call
name|QList
argument_list|<
name|QVariant
argument_list|>
name|DBusDispatcher
operator|::
name|call
parameter_list|(
specifier|const
name|QString
modifier|&
name|method
parameter_list|,
specifier|const
name|QVariant
modifier|&
name|arg1
parameter_list|,
specifier|const
name|QVariant
modifier|&
name|arg2
parameter_list|,
specifier|const
name|QVariant
modifier|&
name|arg3
parameter_list|,
specifier|const
name|QVariant
modifier|&
name|arg4
parameter_list|,
specifier|const
name|QVariant
modifier|&
name|arg5
parameter_list|,
specifier|const
name|QVariant
modifier|&
name|arg6
parameter_list|,
specifier|const
name|QVariant
modifier|&
name|arg7
parameter_list|,
specifier|const
name|QVariant
modifier|&
name|arg8
parameter_list|)
block|{
name|DBusMessageIter
name|dbus_iter
decl_stmt|;
name|DBusMessage
modifier|*
name|message
init|=
name|prepareDBusCall
argument_list|(
name|d_ptr
operator|->
name|service
argument_list|,
name|d_ptr
operator|->
name|path
argument_list|,
name|d_ptr
operator|->
name|interface
argument_list|,
name|method
argument_list|,
name|arg1
argument_list|,
name|arg2
argument_list|,
name|arg3
argument_list|,
name|arg4
argument_list|,
name|arg5
argument_list|,
name|arg6
argument_list|,
name|arg7
argument_list|,
name|arg8
argument_list|)
decl_stmt|;
name|DBusMessage
modifier|*
name|reply
init|=
name|dbus_connection_send_with_reply_and_block
argument_list|(
name|d_ptr
operator|->
name|connection
argument_list|,
name|message
argument_list|,
operator|-
literal|1
argument_list|,
name|NULL
argument_list|)
decl_stmt|;
name|dbus_message_unref
argument_list|(
name|message
argument_list|)
expr_stmt|;
name|QList
argument_list|<
name|QVariant
argument_list|>
name|replylist
decl_stmt|;
if|if
condition|(
name|reply
operator|!=
name|NULL
operator|&&
name|dbus_message_iter_init
argument_list|(
name|reply
argument_list|,
operator|&
name|dbus_iter
argument_list|)
condition|)
block|{
comment|// Read return arguments
while|while
condition|(
name|dbus_message_iter_get_arg_type
argument_list|(
operator|&
name|dbus_iter
argument_list|)
operator|!=
name|DBUS_TYPE_INVALID
condition|)
block|{
name|replylist
operator|<<
name|getVariantFromDBusMessage
argument_list|(
operator|&
name|dbus_iter
argument_list|)
expr_stmt|;
name|dbus_message_iter_next
argument_list|(
operator|&
name|dbus_iter
argument_list|)
expr_stmt|;
block|}
block|}
if|if
condition|(
name|reply
operator|!=
name|NULL
condition|)
name|dbus_message_unref
argument_list|(
name|reply
argument_list|)
expr_stmt|;
return|return
name|replylist
return|;
block|}
DECL|class|PendingCallInfo
class|class
name|PendingCallInfo
block|{
public|public:
DECL|member|method
name|QString
name|method
decl_stmt|;
DECL|member|dispatcher
name|DBusDispatcher
modifier|*
name|dispatcher
decl_stmt|;
DECL|member|priv
name|DBusDispatcherPrivate
modifier|*
name|priv
decl_stmt|;
block|}
class|;
DECL|function|freePendingCallInfo
specifier|static
name|void
name|freePendingCallInfo
parameter_list|(
name|void
modifier|*
name|memory
parameter_list|)
block|{
name|PendingCallInfo
modifier|*
name|info
init|=
operator|(
name|PendingCallInfo
operator|*
operator|)
name|memory
decl_stmt|;
operator|delete
name|info
expr_stmt|;
block|}
DECL|function|pendingCallFunction
specifier|static
name|void
name|pendingCallFunction
parameter_list|(
name|DBusPendingCall
modifier|*
name|pending
parameter_list|,
name|void
modifier|*
name|memory
parameter_list|)
block|{
name|PendingCallInfo
modifier|*
name|info
init|=
operator|(
name|PendingCallInfo
operator|*
operator|)
name|memory
decl_stmt|;
name|QString
name|errorStr
decl_stmt|;
name|QList
argument_list|<
name|QVariant
argument_list|>
name|replyList
decl_stmt|;
name|DBusMessage
modifier|*
name|reply
init|=
name|dbus_pending_call_steal_reply
argument_list|(
name|pending
argument_list|)
decl_stmt|;
name|Q_ASSERT
argument_list|(
name|reply
operator|!=
name|NULL
argument_list|)
expr_stmt|;
if|if
condition|(
name|dbus_message_get_type
argument_list|(
name|reply
argument_list|)
operator|==
name|DBUS_MESSAGE_TYPE_ERROR
condition|)
block|{
name|errorStr
operator|=
name|dbus_message_get_error_name
argument_list|(
name|reply
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|DBusMessageIter
name|dbus_iter
decl_stmt|;
name|dbus_message_iter_init
argument_list|(
name|reply
argument_list|,
operator|&
name|dbus_iter
argument_list|)
expr_stmt|;
comment|// Read return arguments
while|while
condition|(
name|dbus_message_iter_get_arg_type
argument_list|(
operator|&
name|dbus_iter
argument_list|)
operator|!=
name|DBUS_TYPE_INVALID
condition|)
block|{
name|replyList
operator|<<
name|getVariantFromDBusMessage
argument_list|(
operator|&
name|dbus_iter
argument_list|)
expr_stmt|;
name|dbus_message_iter_next
argument_list|(
operator|&
name|dbus_iter
argument_list|)
expr_stmt|;
block|}
block|}
name|info
operator|->
name|priv
operator|->
name|pending_calls
operator|.
name|removeOne
argument_list|(
name|pending
argument_list|)
expr_stmt|;
name|info
operator|->
name|dispatcher
operator|->
name|emitCallReply
argument_list|(
name|info
operator|->
name|method
argument_list|,
name|replyList
argument_list|,
name|errorStr
argument_list|)
expr_stmt|;
name|dbus_message_unref
argument_list|(
name|reply
argument_list|)
expr_stmt|;
name|dbus_pending_call_unref
argument_list|(
name|pending
argument_list|)
expr_stmt|;
block|}
DECL|function|callAsynchronous
name|bool
name|DBusDispatcher
operator|::
name|callAsynchronous
parameter_list|(
specifier|const
name|QString
modifier|&
name|method
parameter_list|,
specifier|const
name|QVariant
modifier|&
name|arg1
parameter_list|,
specifier|const
name|QVariant
modifier|&
name|arg2
parameter_list|,
specifier|const
name|QVariant
modifier|&
name|arg3
parameter_list|,
specifier|const
name|QVariant
modifier|&
name|arg4
parameter_list|,
specifier|const
name|QVariant
modifier|&
name|arg5
parameter_list|,
specifier|const
name|QVariant
modifier|&
name|arg6
parameter_list|,
specifier|const
name|QVariant
modifier|&
name|arg7
parameter_list|,
specifier|const
name|QVariant
modifier|&
name|arg8
parameter_list|)
block|{
name|DBusMessage
modifier|*
name|message
init|=
name|prepareDBusCall
argument_list|(
name|d_ptr
operator|->
name|service
argument_list|,
name|d_ptr
operator|->
name|path
argument_list|,
name|d_ptr
operator|->
name|interface
argument_list|,
name|method
argument_list|,
name|arg1
argument_list|,
name|arg2
argument_list|,
name|arg3
argument_list|,
name|arg4
argument_list|,
name|arg5
argument_list|,
name|arg6
argument_list|,
name|arg7
argument_list|,
name|arg8
argument_list|)
decl_stmt|;
name|DBusPendingCall
modifier|*
name|call
init|=
name|NULL
decl_stmt|;
name|dbus_bool_t
name|ret
init|=
name|dbus_connection_send_with_reply
argument_list|(
name|d_ptr
operator|->
name|connection
argument_list|,
name|message
argument_list|,
operator|&
name|call
argument_list|,
operator|-
literal|1
argument_list|)
decl_stmt|;
name|PendingCallInfo
modifier|*
name|info
init|=
operator|new
name|PendingCallInfo
decl_stmt|;
name|info
operator|->
name|method
operator|=
name|method
expr_stmt|;
name|info
operator|->
name|dispatcher
operator|=
name|this
expr_stmt|;
name|info
operator|->
name|priv
operator|=
name|d_ptr
expr_stmt|;
name|dbus_pending_call_set_notify
argument_list|(
name|call
argument_list|,
name|pendingCallFunction
argument_list|,
name|info
argument_list|,
name|freePendingCallInfo
argument_list|)
expr_stmt|;
name|d_ptr
operator|->
name|pending_calls
operator|.
name|append
argument_list|(
name|call
argument_list|)
expr_stmt|;
return|return
operator|(
name|bool
operator|)
name|ret
return|;
block|}
DECL|function|emitSignalReceived
name|void
name|DBusDispatcher
operator|::
name|emitSignalReceived
parameter_list|(
specifier|const
name|QString
modifier|&
name|interface
parameter_list|,
specifier|const
name|QString
modifier|&
name|signal
parameter_list|,
specifier|const
name|QList
argument_list|<
name|QVariant
argument_list|>
modifier|&
name|args
parameter_list|)
block|{
emit|emit
name|signalReceived
argument_list|(
name|interface
argument_list|,
name|signal
argument_list|,
name|args
argument_list|)
emit|;
block|}
DECL|function|emitCallReply
name|void
name|DBusDispatcher
operator|::
name|emitCallReply
parameter_list|(
specifier|const
name|QString
modifier|&
name|method
parameter_list|,
specifier|const
name|QList
argument_list|<
name|QVariant
argument_list|>
modifier|&
name|args
parameter_list|,
specifier|const
name|QString
modifier|&
name|error
parameter_list|)
block|{
emit|emit
name|callReply
argument_list|(
name|method
argument_list|,
name|args
argument_list|,
name|error
argument_list|)
emit|;
block|}
DECL|function|synchronousDispatch
name|void
name|DBusDispatcher
operator|::
name|synchronousDispatch
parameter_list|(
name|int
name|timeout_ms
parameter_list|)
block|{
name|dbus_connection_read_write_dispatch
argument_list|(
name|d_ptr
operator|->
name|connection
argument_list|,
name|timeout_ms
argument_list|)
expr_stmt|;
block|}
block|}
end_namespace
begin_comment
comment|// Maemo namespace
end_comment
end_unit
