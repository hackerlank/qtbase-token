begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 Intel Corporation. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the QtDBus module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|DBUS_MINIMAL_P_H
end_ifndef
begin_define
DECL|macro|DBUS_MINIMAL_P_H
define|#
directive|define
name|DBUS_MINIMAL_P_H
end_define
begin_comment
comment|//
end_comment
begin_comment
comment|//  W A R N I N G
end_comment
begin_comment
comment|//  -------------
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|// This file is not part of the Qt API.  It exists for the convenience
end_comment
begin_comment
comment|// of other Qt classes.  This header file may change from version to
end_comment
begin_comment
comment|// version without notice, or even be removed.
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|// We mean it.
end_comment
begin_comment
comment|//
end_comment
begin_extern
extern|extern
literal|"C"
block|{
comment|// Equivalent to dbus-arch-deps.h
DECL|typedef|dbus_int64_t
typedef|typedef
name|qint64
name|dbus_int64_t
typedef|;
DECL|typedef|dbus_uint64_t
typedef|typedef
name|quint64
name|dbus_uint64_t
typedef|;
DECL|typedef|dbus_int32_t
typedef|typedef
name|qint32
name|dbus_int32_t
typedef|;
DECL|typedef|dbus_uint32_t
typedef|typedef
name|quint32
name|dbus_uint32_t
typedef|;
DECL|typedef|dbus_int16_t
typedef|typedef
name|qint16
name|dbus_int16_t
typedef|;
DECL|typedef|dbus_uint16_t
typedef|typedef
name|quint16
name|dbus_uint16_t
typedef|;
comment|// simulate minimum version we support
DECL|macro|DBUS_MAJOR_VERSION
define|#
directive|define
name|DBUS_MAJOR_VERSION
value|1
DECL|macro|DBUS_MINOR_VERSION
define|#
directive|define
name|DBUS_MINOR_VERSION
value|2
DECL|macro|DBUS_VERSION
define|#
directive|define
name|DBUS_VERSION
value|((1<< 16) | (2<< 8))
comment|// forward declaration to opaque types we use
struct_decl|struct
name|DBusConnection
struct_decl|;
struct_decl|struct
name|DBusMessage
struct_decl|;
struct_decl|struct
name|DBusPendingCall
struct_decl|;
struct_decl|struct
name|DBusServer
struct_decl|;
struct_decl|struct
name|DBusTimeout
struct_decl|;
struct_decl|struct
name|DBusWatch
struct_decl|;
comment|// This file contains constants and typedefs from libdbus-1 headers,
comment|// which carry the following copyright:
comment|/*  * Copyright (C) 2002, 2003  CodeFactory AB  * Copyright (C) 2004, 2005 Red Hat, Inc.  *  * Licensed under the Academic Free License version 2.1  *  * This program is free software; you can redistribute it and/or modify  * it under the terms of the GNU General Public License as published by  * the Free Software Foundation; either version 2 of the License, or  * (at your option) any later version.  *  * This program is distributed in the hope that it will be useful,  * but WITHOUT ANY WARRANTY; without even the implied warranty of  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the  * GNU General Public License for more details.  *  * You should have received a copy of the GNU General Public License  * along with this program; if not, write to the Free Software  * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA  *  */
comment|/* dbus-types.h */
DECL|typedef|dbus_unichar_t
typedef|typedef
name|dbus_uint32_t
name|dbus_unichar_t
typedef|;
DECL|typedef|dbus_bool_t
typedef|typedef
name|dbus_uint32_t
name|dbus_bool_t
typedef|;
comment|/* dbus-shared.h */
DECL|macro|DBUS_SERVICE_DBUS
define|#
directive|define
name|DBUS_SERVICE_DBUS
value|"org.freedesktop.DBus"
DECL|macro|DBUS_PATH_DBUS
define|#
directive|define
name|DBUS_PATH_DBUS
value|"/org/freedesktop/DBus"
DECL|macro|DBUS_PATH_LOCAL
define|#
directive|define
name|DBUS_PATH_LOCAL
value|"/org/freedesktop/DBus/Local"
DECL|macro|DBUS_INTERFACE_DBUS
define|#
directive|define
name|DBUS_INTERFACE_DBUS
value|"org.freedesktop.DBus"
DECL|macro|DBUS_INTERFACE_INTROSPECTABLE
define|#
directive|define
name|DBUS_INTERFACE_INTROSPECTABLE
value|"org.freedesktop.DBus.Introspectable"
DECL|macro|DBUS_INTERFACE_PROPERTIES
define|#
directive|define
name|DBUS_INTERFACE_PROPERTIES
value|"org.freedesktop.DBus.Properties"
DECL|macro|DBUS_INTERFACE_LOCAL
define|#
directive|define
name|DBUS_INTERFACE_LOCAL
value|"org.freedesktop.DBus.Local"
DECL|macro|DBUS_NAME_FLAG_ALLOW_REPLACEMENT
define|#
directive|define
name|DBUS_NAME_FLAG_ALLOW_REPLACEMENT
value|0x1
comment|/**< Allow another service to become the primary owner if requested */
DECL|macro|DBUS_NAME_FLAG_REPLACE_EXISTING
define|#
directive|define
name|DBUS_NAME_FLAG_REPLACE_EXISTING
value|0x2
comment|/**< Request to replace the current primary owner */
DECL|macro|DBUS_NAME_FLAG_DO_NOT_QUEUE
define|#
directive|define
name|DBUS_NAME_FLAG_DO_NOT_QUEUE
value|0x4
comment|/**< If we can not become the primary owner do not place us in the queue */
DECL|macro|DBUS_REQUEST_NAME_REPLY_PRIMARY_OWNER
define|#
directive|define
name|DBUS_REQUEST_NAME_REPLY_PRIMARY_OWNER
value|1
comment|/**< Service has become the primary owner of the requested name */
DECL|macro|DBUS_REQUEST_NAME_REPLY_IN_QUEUE
define|#
directive|define
name|DBUS_REQUEST_NAME_REPLY_IN_QUEUE
value|2
comment|/**< Service could not become the primary owner and has been placed in the queue */
DECL|macro|DBUS_REQUEST_NAME_REPLY_EXISTS
define|#
directive|define
name|DBUS_REQUEST_NAME_REPLY_EXISTS
value|3
comment|/**< Service is already in the queue */
DECL|macro|DBUS_REQUEST_NAME_REPLY_ALREADY_OWNER
define|#
directive|define
name|DBUS_REQUEST_NAME_REPLY_ALREADY_OWNER
value|4
comment|/**< Service is already the primary owner */
DECL|macro|DBUS_RELEASE_NAME_REPLY_RELEASED
define|#
directive|define
name|DBUS_RELEASE_NAME_REPLY_RELEASED
value|1
comment|/**< Service was released from the given name */
DECL|macro|DBUS_RELEASE_NAME_REPLY_NON_EXISTENT
define|#
directive|define
name|DBUS_RELEASE_NAME_REPLY_NON_EXISTENT
value|2
comment|/**< The given name does not exist on the bus */
DECL|macro|DBUS_RELEASE_NAME_REPLY_NOT_OWNER
define|#
directive|define
name|DBUS_RELEASE_NAME_REPLY_NOT_OWNER
value|3
comment|/**< Service is not an owner of the given name */
typedef|typedef
enum|enum
block|{
DECL|enumerator|DBUS_BUS_SESSION
name|DBUS_BUS_SESSION
block|,
comment|/**< The login session bus */
DECL|enumerator|DBUS_BUS_SYSTEM
name|DBUS_BUS_SYSTEM
block|,
comment|/**< The systemwide bus */
DECL|enumerator|DBUS_BUS_STARTER
name|DBUS_BUS_STARTER
comment|/**< The bus that started us, if any */
block|}
DECL|typedef|DBusBusType
name|DBusBusType
typedef|;
typedef|typedef
enum|enum
block|{
DECL|enumerator|DBUS_HANDLER_RESULT_HANDLED
name|DBUS_HANDLER_RESULT_HANDLED
block|,
comment|/**< Message has had its effect - no need to run more handlers. */
DECL|enumerator|DBUS_HANDLER_RESULT_NOT_YET_HANDLED
name|DBUS_HANDLER_RESULT_NOT_YET_HANDLED
block|,
comment|/**< Message has not had any effect - see if other handlers want it. */
DECL|enumerator|DBUS_HANDLER_RESULT_NEED_MEMORY
name|DBUS_HANDLER_RESULT_NEED_MEMORY
comment|/**< Need more memory in order to return #DBUS_HANDLER_RESULT_HANDLED or #DBUS_HANDLER_RESULT_NOT_YET_HANDLED. Please try again later with more memory. */
block|}
DECL|typedef|DBusHandlerResult
name|DBusHandlerResult
typedef|;
comment|/* dbus-memory.h */
DECL|typedef|DBusFreeFunction
typedef|typedef
name|void
function_decl|(
modifier|*
name|DBusFreeFunction
function_decl|)
parameter_list|(
name|void
modifier|*
name|memory
parameter_list|)
function_decl|;
comment|/* dbus-connection.h */
typedef|typedef
enum|enum
block|{
DECL|enumerator|DBUS_WATCH_READABLE
name|DBUS_WATCH_READABLE
init|=
literal|1
operator|<<
literal|0
block|,
comment|/**< As in POLLIN */
DECL|enumerator|DBUS_WATCH_WRITABLE
name|DBUS_WATCH_WRITABLE
init|=
literal|1
operator|<<
literal|1
block|,
comment|/**< As in POLLOUT */
DECL|enumerator|DBUS_WATCH_ERROR
name|DBUS_WATCH_ERROR
init|=
literal|1
operator|<<
literal|2
block|,
comment|/**< As in POLLERR (can't watch for                                  *   this, but can be present in                                  *   current state passed to                                  *   dbus_watch_handle()).                                  */
DECL|enumerator|DBUS_WATCH_HANGUP
name|DBUS_WATCH_HANGUP
init|=
literal|1
operator|<<
literal|3
comment|/**< As in POLLHUP (can't watch for                                  *   it, but can be present in current                                  *   state passed to                                  *   dbus_watch_handle()).                                  */
comment|/* Internal to libdbus, there is also _DBUS_WATCH_NVAL in dbus-watch.h */
block|}
DECL|typedef|DBusWatchFlags
name|DBusWatchFlags
typedef|;
typedef|typedef
enum|enum
block|{
DECL|enumerator|DBUS_DISPATCH_DATA_REMAINS
name|DBUS_DISPATCH_DATA_REMAINS
block|,
comment|/**< There is more data to potentially convert to messages. */
DECL|enumerator|DBUS_DISPATCH_COMPLETE
name|DBUS_DISPATCH_COMPLETE
block|,
comment|/**< All currently available data has been processed. */
DECL|enumerator|DBUS_DISPATCH_NEED_MEMORY
name|DBUS_DISPATCH_NEED_MEMORY
comment|/**< More memory is needed to continue. */
block|}
DECL|typedef|DBusDispatchStatus
name|DBusDispatchStatus
typedef|;
DECL|typedef|DBusAddWatchFunction
typedef|typedef
name|dbus_bool_t
function_decl|(
modifier|*
name|DBusAddWatchFunction
function_decl|)
parameter_list|(
name|DBusWatch
modifier|*
name|watch
parameter_list|,
name|void
modifier|*
name|data
parameter_list|)
function_decl|;
DECL|typedef|DBusWatchToggledFunction
typedef|typedef
name|void
function_decl|(
modifier|*
name|DBusWatchToggledFunction
function_decl|)
parameter_list|(
name|DBusWatch
modifier|*
name|watch
parameter_list|,
name|void
modifier|*
name|data
parameter_list|)
function_decl|;
DECL|typedef|DBusRemoveWatchFunction
typedef|typedef
name|void
function_decl|(
modifier|*
name|DBusRemoveWatchFunction
function_decl|)
parameter_list|(
name|DBusWatch
modifier|*
name|watch
parameter_list|,
name|void
modifier|*
name|data
parameter_list|)
function_decl|;
DECL|typedef|DBusAddTimeoutFunction
typedef|typedef
name|dbus_bool_t
function_decl|(
modifier|*
name|DBusAddTimeoutFunction
function_decl|)
parameter_list|(
name|DBusTimeout
modifier|*
name|timeout
parameter_list|,
name|void
modifier|*
name|data
parameter_list|)
function_decl|;
DECL|typedef|DBusTimeoutToggledFunction
typedef|typedef
name|void
function_decl|(
modifier|*
name|DBusTimeoutToggledFunction
function_decl|)
parameter_list|(
name|DBusTimeout
modifier|*
name|timeout
parameter_list|,
name|void
modifier|*
name|data
parameter_list|)
function_decl|;
DECL|typedef|DBusRemoveTimeoutFunction
typedef|typedef
name|void
function_decl|(
modifier|*
name|DBusRemoveTimeoutFunction
function_decl|)
parameter_list|(
name|DBusTimeout
modifier|*
name|timeout
parameter_list|,
name|void
modifier|*
name|data
parameter_list|)
function_decl|;
DECL|typedef|DBusDispatchStatusFunction
typedef|typedef
name|void
function_decl|(
modifier|*
name|DBusDispatchStatusFunction
function_decl|)
parameter_list|(
name|DBusConnection
modifier|*
name|connection
parameter_list|,
name|DBusDispatchStatus
name|new_status
parameter_list|,
name|void
modifier|*
name|data
parameter_list|)
function_decl|;
DECL|typedef|DBusWakeupMainFunction
typedef|typedef
name|void
function_decl|(
modifier|*
name|DBusWakeupMainFunction
function_decl|)
parameter_list|(
name|void
modifier|*
name|data
parameter_list|)
function_decl|;
DECL|typedef|DBusPendingCallNotifyFunction
typedef|typedef
name|void
function_decl|(
modifier|*
name|DBusPendingCallNotifyFunction
function_decl|)
parameter_list|(
name|DBusPendingCall
modifier|*
name|pending
parameter_list|,
name|void
modifier|*
name|user_data
parameter_list|)
function_decl|;
DECL|typedef|DBusHandleMessageFunction
typedef|typedef
name|DBusHandlerResult
function_decl|(
modifier|*
name|DBusHandleMessageFunction
function_decl|)
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
name|user_data
parameter_list|)
function_decl|;
comment|/* dbus-errors.h */
DECL|struct|DBusError
struct|struct
name|DBusError
block|{
DECL|member|name
specifier|const
name|char
modifier|*
name|name
decl_stmt|;
comment|/**< public error name field */
DECL|member|message
specifier|const
name|char
modifier|*
name|message
decl_stmt|;
comment|/**< public error message field */
DECL|member|dummy1
name|unsigned
name|int
name|dummy1
range|:
literal|1
decl_stmt|;
comment|/**< placeholder */
DECL|member|dummy2
name|unsigned
name|int
name|dummy2
range|:
literal|1
decl_stmt|;
comment|/**< placeholder */
DECL|member|dummy3
name|unsigned
name|int
name|dummy3
range|:
literal|1
decl_stmt|;
comment|/**< placeholder */
DECL|member|dummy4
name|unsigned
name|int
name|dummy4
range|:
literal|1
decl_stmt|;
comment|/**< placeholder */
DECL|member|dummy5
name|unsigned
name|int
name|dummy5
range|:
literal|1
decl_stmt|;
comment|/**< placeholder */
DECL|member|padding1
name|void
modifier|*
name|padding1
decl_stmt|;
comment|/**< placeholder */
block|}
struct|;
comment|/* dbus-message.h */
DECL|struct|DBusMessageIter
struct|struct
name|DBusMessageIter
block|{
DECL|member|dummy1
name|void
modifier|*
name|dummy1
decl_stmt|;
comment|/**< Don't use this */
DECL|member|dummy2
name|void
modifier|*
name|dummy2
decl_stmt|;
comment|/**< Don't use this */
DECL|member|dummy3
name|dbus_uint32_t
name|dummy3
decl_stmt|;
comment|/**< Don't use this */
DECL|member|dummy4
name|int
name|dummy4
decl_stmt|;
comment|/**< Don't use this */
DECL|member|dummy5
name|int
name|dummy5
decl_stmt|;
comment|/**< Don't use this */
DECL|member|dummy6
name|int
name|dummy6
decl_stmt|;
comment|/**< Don't use this */
DECL|member|dummy7
name|int
name|dummy7
decl_stmt|;
comment|/**< Don't use this */
DECL|member|dummy8
name|int
name|dummy8
decl_stmt|;
comment|/**< Don't use this */
DECL|member|dummy9
name|int
name|dummy9
decl_stmt|;
comment|/**< Don't use this */
DECL|member|dummy10
name|int
name|dummy10
decl_stmt|;
comment|/**< Don't use this */
DECL|member|dummy11
name|int
name|dummy11
decl_stmt|;
comment|/**< Don't use this */
DECL|member|pad1
name|int
name|pad1
decl_stmt|;
comment|/**< Don't use this */
DECL|member|pad2
name|int
name|pad2
decl_stmt|;
comment|/**< Don't use this */
DECL|member|pad3
name|void
modifier|*
name|pad3
decl_stmt|;
comment|/**< Don't use this */
block|}
struct|;
comment|/* dbus-protocol.h */
DECL|macro|DBUS_TYPE_INVALID
define|#
directive|define
name|DBUS_TYPE_INVALID
value|((int) '\0')
DECL|macro|DBUS_TYPE_INVALID_AS_STRING
define|#
directive|define
name|DBUS_TYPE_INVALID_AS_STRING
value|"\0"
DECL|macro|DBUS_TYPE_BYTE
define|#
directive|define
name|DBUS_TYPE_BYTE
value|((int) 'y')
DECL|macro|DBUS_TYPE_BYTE_AS_STRING
define|#
directive|define
name|DBUS_TYPE_BYTE_AS_STRING
value|"y"
DECL|macro|DBUS_TYPE_BOOLEAN
define|#
directive|define
name|DBUS_TYPE_BOOLEAN
value|((int) 'b')
DECL|macro|DBUS_TYPE_BOOLEAN_AS_STRING
define|#
directive|define
name|DBUS_TYPE_BOOLEAN_AS_STRING
value|"b"
DECL|macro|DBUS_TYPE_INT16
define|#
directive|define
name|DBUS_TYPE_INT16
value|((int) 'n')
DECL|macro|DBUS_TYPE_INT16_AS_STRING
define|#
directive|define
name|DBUS_TYPE_INT16_AS_STRING
value|"n"
DECL|macro|DBUS_TYPE_UINT16
define|#
directive|define
name|DBUS_TYPE_UINT16
value|((int) 'q')
DECL|macro|DBUS_TYPE_UINT16_AS_STRING
define|#
directive|define
name|DBUS_TYPE_UINT16_AS_STRING
value|"q"
DECL|macro|DBUS_TYPE_INT32
define|#
directive|define
name|DBUS_TYPE_INT32
value|((int) 'i')
DECL|macro|DBUS_TYPE_INT32_AS_STRING
define|#
directive|define
name|DBUS_TYPE_INT32_AS_STRING
value|"i"
DECL|macro|DBUS_TYPE_UINT32
define|#
directive|define
name|DBUS_TYPE_UINT32
value|((int) 'u')
DECL|macro|DBUS_TYPE_UINT32_AS_STRING
define|#
directive|define
name|DBUS_TYPE_UINT32_AS_STRING
value|"u"
DECL|macro|DBUS_TYPE_INT64
define|#
directive|define
name|DBUS_TYPE_INT64
value|((int) 'x')
DECL|macro|DBUS_TYPE_INT64_AS_STRING
define|#
directive|define
name|DBUS_TYPE_INT64_AS_STRING
value|"x"
DECL|macro|DBUS_TYPE_UINT64
define|#
directive|define
name|DBUS_TYPE_UINT64
value|((int) 't')
DECL|macro|DBUS_TYPE_UINT64_AS_STRING
define|#
directive|define
name|DBUS_TYPE_UINT64_AS_STRING
value|"t"
DECL|macro|DBUS_TYPE_DOUBLE
define|#
directive|define
name|DBUS_TYPE_DOUBLE
value|((int) 'd')
DECL|macro|DBUS_TYPE_DOUBLE_AS_STRING
define|#
directive|define
name|DBUS_TYPE_DOUBLE_AS_STRING
value|"d"
DECL|macro|DBUS_TYPE_STRING
define|#
directive|define
name|DBUS_TYPE_STRING
value|((int) 's')
DECL|macro|DBUS_TYPE_STRING_AS_STRING
define|#
directive|define
name|DBUS_TYPE_STRING_AS_STRING
value|"s"
DECL|macro|DBUS_TYPE_OBJECT_PATH
define|#
directive|define
name|DBUS_TYPE_OBJECT_PATH
value|((int) 'o')
DECL|macro|DBUS_TYPE_OBJECT_PATH_AS_STRING
define|#
directive|define
name|DBUS_TYPE_OBJECT_PATH_AS_STRING
value|"o"
DECL|macro|DBUS_TYPE_SIGNATURE
define|#
directive|define
name|DBUS_TYPE_SIGNATURE
value|((int) 'g')
DECL|macro|DBUS_TYPE_SIGNATURE_AS_STRING
define|#
directive|define
name|DBUS_TYPE_SIGNATURE_AS_STRING
value|"g"
DECL|macro|DBUS_TYPE_UNIX_FD
define|#
directive|define
name|DBUS_TYPE_UNIX_FD
value|((int) 'h')
DECL|macro|DBUS_TYPE_UNIX_FD_AS_STRING
define|#
directive|define
name|DBUS_TYPE_UNIX_FD_AS_STRING
value|"h"
DECL|macro|DBUS_TYPE_ARRAY
define|#
directive|define
name|DBUS_TYPE_ARRAY
value|((int) 'a')
DECL|macro|DBUS_TYPE_ARRAY_AS_STRING
define|#
directive|define
name|DBUS_TYPE_ARRAY_AS_STRING
value|"a"
DECL|macro|DBUS_TYPE_VARIANT
define|#
directive|define
name|DBUS_TYPE_VARIANT
value|((int) 'v')
DECL|macro|DBUS_TYPE_VARIANT_AS_STRING
define|#
directive|define
name|DBUS_TYPE_VARIANT_AS_STRING
value|"v"
DECL|macro|DBUS_TYPE_STRUCT
define|#
directive|define
name|DBUS_TYPE_STRUCT
value|((int) 'r')
DECL|macro|DBUS_TYPE_STRUCT_AS_STRING
define|#
directive|define
name|DBUS_TYPE_STRUCT_AS_STRING
value|"r"
DECL|macro|DBUS_TYPE_DICT_ENTRY
define|#
directive|define
name|DBUS_TYPE_DICT_ENTRY
value|((int) 'e')
DECL|macro|DBUS_TYPE_DICT_ENTRY_AS_STRING
define|#
directive|define
name|DBUS_TYPE_DICT_ENTRY_AS_STRING
value|"e"
DECL|macro|DBUS_STRUCT_BEGIN_CHAR
define|#
directive|define
name|DBUS_STRUCT_BEGIN_CHAR
value|((int) '(')
DECL|macro|DBUS_STRUCT_BEGIN_CHAR_AS_STRING
define|#
directive|define
name|DBUS_STRUCT_BEGIN_CHAR_AS_STRING
value|"("
DECL|macro|DBUS_STRUCT_END_CHAR
define|#
directive|define
name|DBUS_STRUCT_END_CHAR
value|((int) ')')
DECL|macro|DBUS_STRUCT_END_CHAR_AS_STRING
define|#
directive|define
name|DBUS_STRUCT_END_CHAR_AS_STRING
value|")"
DECL|macro|DBUS_DICT_ENTRY_BEGIN_CHAR
define|#
directive|define
name|DBUS_DICT_ENTRY_BEGIN_CHAR
value|((int) '{')
DECL|macro|DBUS_DICT_ENTRY_BEGIN_CHAR_AS_STRING
define|#
directive|define
name|DBUS_DICT_ENTRY_BEGIN_CHAR_AS_STRING
value|"{"
DECL|macro|DBUS_DICT_ENTRY_END_CHAR
define|#
directive|define
name|DBUS_DICT_ENTRY_END_CHAR
value|((int) '}')
DECL|macro|DBUS_DICT_ENTRY_END_CHAR_AS_STRING
define|#
directive|define
name|DBUS_DICT_ENTRY_END_CHAR_AS_STRING
value|"}"
DECL|macro|DBUS_MESSAGE_TYPE_INVALID
define|#
directive|define
name|DBUS_MESSAGE_TYPE_INVALID
value|0
DECL|macro|DBUS_MESSAGE_TYPE_METHOD_CALL
define|#
directive|define
name|DBUS_MESSAGE_TYPE_METHOD_CALL
value|1
DECL|macro|DBUS_MESSAGE_TYPE_METHOD_RETURN
define|#
directive|define
name|DBUS_MESSAGE_TYPE_METHOD_RETURN
value|2
DECL|macro|DBUS_MESSAGE_TYPE_ERROR
define|#
directive|define
name|DBUS_MESSAGE_TYPE_ERROR
value|3
DECL|macro|DBUS_MESSAGE_TYPE_SIGNAL
define|#
directive|define
name|DBUS_MESSAGE_TYPE_SIGNAL
value|4
DECL|macro|DBUS_MAXIMUM_NAME_LENGTH
define|#
directive|define
name|DBUS_MAXIMUM_NAME_LENGTH
value|255
DECL|macro|DBUS_INTROSPECT_1_0_XML_NAMESPACE
define|#
directive|define
name|DBUS_INTROSPECT_1_0_XML_NAMESPACE
value|"http://www.freedesktop.org/standards/dbus"
DECL|macro|DBUS_INTROSPECT_1_0_XML_PUBLIC_IDENTIFIER
define|#
directive|define
name|DBUS_INTROSPECT_1_0_XML_PUBLIC_IDENTIFIER
value|"-//freedesktop//DTD D-BUS Object Introspection 1.0//EN"
DECL|macro|DBUS_INTROSPECT_1_0_XML_SYSTEM_IDENTIFIER
define|#
directive|define
name|DBUS_INTROSPECT_1_0_XML_SYSTEM_IDENTIFIER
value|"http://www.freedesktop.org/standards/dbus/1.0/introspect.dtd"
DECL|macro|DBUS_INTROSPECT_1_0_XML_DOCTYPE_DECL_NODE
define|#
directive|define
name|DBUS_INTROSPECT_1_0_XML_DOCTYPE_DECL_NODE
value|"<!DOCTYPE node PUBLIC \"" DBUS_INTROSPECT_1_0_XML_PUBLIC_IDENTIFIER "\"\n\"" DBUS_INTROSPECT_1_0_XML_SYSTEM_IDENTIFIER "\">\n"
comment|/* dbus-server.h */
DECL|typedef|DBusNewConnectionFunction
typedef|typedef
name|void
function_decl|(
modifier|*
name|DBusNewConnectionFunction
function_decl|)
parameter_list|(
name|DBusServer
modifier|*
name|server
parameter_list|,
name|DBusConnection
modifier|*
name|new_connection
parameter_list|,
name|void
modifier|*
name|data
parameter_list|)
function_decl|;
block|}
end_extern
begin_comment
comment|// extern "C"
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// DBUS_MINIMAL_P_H
end_comment
end_unit
