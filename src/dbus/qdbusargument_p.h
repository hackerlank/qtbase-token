begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2014 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtDBus module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia. For licensing terms and ** conditions see http://qt.digia.com/licensing. For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights. These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QDBUSARGUMENT_P_H
end_ifndef
begin_define
DECL|macro|QDBUSARGUMENT_P_H
define|#
directive|define
name|QDBUSARGUMENT_P_H
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
comment|// of the QLibrary class.  This header file may change from
end_comment
begin_comment
comment|// version to version without notice, or even be removed.
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
begin_include
include|#
directive|include
file|<qdbusargument.h>
end_include
begin_include
include|#
directive|include
file|"qdbusunixfiledescriptor.h"
end_include
begin_include
include|#
directive|include
file|"qdbus_symbols_p.h"
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
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QDBusMarshaller
name|class
name|QDBusMarshaller
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QDBusDemarshaller
name|class
name|QDBusDemarshaller
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QDBusArgumentPrivate
block|{
name|public
label|:
specifier|inline
name|QDBusArgumentPrivate
argument_list|(
argument|int flags =
literal|0
argument_list|)
operator|:
name|message
argument_list|(
literal|0
argument_list|)
operator|,
name|ref
argument_list|(
literal|1
argument_list|)
operator|,
name|capabilities
argument_list|(
argument|flags
argument_list|)
block|{ }
operator|~
name|QDBusArgumentPrivate
argument_list|()
expr_stmt|;
specifier|static
name|bool
name|checkRead
parameter_list|(
name|QDBusArgumentPrivate
modifier|*
name|d
parameter_list|)
function_decl|;
specifier|static
name|bool
name|checkReadAndDetach
parameter_list|(
name|QDBusArgumentPrivate
modifier|*
modifier|&
name|d
parameter_list|)
function_decl|;
specifier|static
name|bool
name|checkWrite
parameter_list|(
name|QDBusArgumentPrivate
modifier|*
modifier|&
name|d
parameter_list|)
function_decl|;
name|QDBusMarshaller
modifier|*
name|marshaller
parameter_list|()
function_decl|;
name|QDBusDemarshaller
modifier|*
name|demarshaller
parameter_list|()
function_decl|;
specifier|static
name|QByteArray
name|createSignature
parameter_list|(
name|int
name|id
parameter_list|)
function_decl|;
specifier|static
specifier|inline
name|QDBusArgument
name|create
parameter_list|(
name|QDBusArgumentPrivate
modifier|*
name|d
parameter_list|)
block|{
name|QDBusArgument
name|q
argument_list|(
name|d
argument_list|)
decl_stmt|;
return|return
name|q
return|;
block|}
specifier|static
specifier|inline
name|QDBusArgumentPrivate
modifier|*
name|d
parameter_list|(
name|QDBusArgument
modifier|&
name|q
parameter_list|)
block|{
return|return
name|q
operator|.
name|d
return|;
block|}
name|public
label|:
name|DBusMessage
modifier|*
name|message
decl_stmt|;
name|QAtomicInt
name|ref
decl_stmt|;
name|int
name|capabilities
decl_stmt|;
enum|enum
name|Direction
block|{
name|Marshalling
block|,
name|Demarshalling
block|}
name|direction
enum|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_decl_stmt
name|class
name|QDBusMarshaller
range|:
name|public
name|QDBusArgumentPrivate
block|{
name|public
operator|:
name|QDBusMarshaller
argument_list|(
argument|int flags
argument_list|)
operator|:
name|QDBusArgumentPrivate
argument_list|(
name|flags
argument_list|)
block|,
name|parent
argument_list|(
literal|0
argument_list|)
block|,
name|ba
argument_list|(
literal|0
argument_list|)
block|,
name|closeCode
argument_list|(
literal|0
argument_list|)
block|,
name|ok
argument_list|(
argument|true
argument_list|)
block|{
name|direction
operator|=
name|Marshalling
block|; }
operator|~
name|QDBusMarshaller
argument_list|()
block|;
name|QString
name|currentSignature
argument_list|()
block|;
name|void
name|append
argument_list|(
argument|uchar arg
argument_list|)
block|;
name|void
name|append
argument_list|(
argument|bool arg
argument_list|)
block|;
name|void
name|append
argument_list|(
argument|short arg
argument_list|)
block|;
name|void
name|append
argument_list|(
argument|ushort arg
argument_list|)
block|;
name|void
name|append
argument_list|(
argument|int arg
argument_list|)
block|;
name|void
name|append
argument_list|(
argument|uint arg
argument_list|)
block|;
name|void
name|append
argument_list|(
argument|qlonglong arg
argument_list|)
block|;
name|void
name|append
argument_list|(
argument|qulonglong arg
argument_list|)
block|;
name|void
name|append
argument_list|(
argument|double arg
argument_list|)
block|;
name|void
name|append
argument_list|(
specifier|const
name|QString
operator|&
name|arg
argument_list|)
block|;
name|void
name|append
argument_list|(
specifier|const
name|QDBusObjectPath
operator|&
name|arg
argument_list|)
block|;
name|void
name|append
argument_list|(
specifier|const
name|QDBusSignature
operator|&
name|arg
argument_list|)
block|;
name|void
name|append
argument_list|(
specifier|const
name|QDBusUnixFileDescriptor
operator|&
name|arg
argument_list|)
block|;
name|void
name|append
argument_list|(
specifier|const
name|QStringList
operator|&
name|arg
argument_list|)
block|;
name|void
name|append
argument_list|(
specifier|const
name|QByteArray
operator|&
name|arg
argument_list|)
block|;
name|bool
name|append
argument_list|(
specifier|const
name|QDBusVariant
operator|&
name|arg
argument_list|)
block|;
comment|// this one can fail
name|QDBusMarshaller
operator|*
name|beginStructure
argument_list|()
block|;
name|QDBusMarshaller
operator|*
name|endStructure
argument_list|()
block|;
name|QDBusMarshaller
operator|*
name|beginArray
argument_list|(
argument|int id
argument_list|)
block|;
name|QDBusMarshaller
operator|*
name|endArray
argument_list|()
block|;
name|QDBusMarshaller
operator|*
name|beginMap
argument_list|(
argument|int kid
argument_list|,
argument|int vid
argument_list|)
block|;
name|QDBusMarshaller
operator|*
name|endMap
argument_list|()
block|;
name|QDBusMarshaller
operator|*
name|beginMapEntry
argument_list|()
block|;
name|QDBusMarshaller
operator|*
name|endMapEntry
argument_list|()
block|;
name|QDBusMarshaller
operator|*
name|beginCommon
argument_list|(
argument|int code
argument_list|,
argument|const char *signature
argument_list|)
block|;
name|QDBusMarshaller
operator|*
name|endCommon
argument_list|()
block|;
name|void
name|open
argument_list|(
argument|QDBusMarshaller&sub
argument_list|,
argument|int code
argument_list|,
argument|const char *signature
argument_list|)
block|;
name|void
name|close
argument_list|()
block|;
name|void
name|error
argument_list|(
specifier|const
name|QString
operator|&
name|message
argument_list|)
block|;
name|bool
name|appendVariantInternal
argument_list|(
specifier|const
name|QVariant
operator|&
name|arg
argument_list|)
block|;
name|bool
name|appendRegisteredType
argument_list|(
specifier|const
name|QVariant
operator|&
name|arg
argument_list|)
block|;
name|bool
name|appendCrossMarshalling
argument_list|(
name|QDBusDemarshaller
operator|*
name|arg
argument_list|)
block|;
name|public
operator|:
name|DBusMessageIter
name|iterator
block|;
name|QDBusMarshaller
operator|*
name|parent
block|;
name|QByteArray
operator|*
name|ba
block|;
name|QString
name|errorString
block|;
name|char
name|closeCode
block|;
name|bool
name|ok
block|;
name|private
operator|:
name|Q_DISABLE_COPY
argument_list|(
argument|QDBusMarshaller
argument_list|)
block|}
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QDBusDemarshaller
range|:
name|public
name|QDBusArgumentPrivate
block|{
name|public
operator|:
specifier|inline
name|QDBusDemarshaller
argument_list|(
argument|int flags
argument_list|)
operator|:
name|QDBusArgumentPrivate
argument_list|(
name|flags
argument_list|)
block|,
name|parent
argument_list|(
literal|0
argument_list|)
block|{
name|direction
operator|=
name|Demarshalling
block|; }
operator|~
name|QDBusDemarshaller
argument_list|()
block|;
name|QString
name|currentSignature
argument_list|()
block|;
name|uchar
name|toByte
argument_list|()
block|;
name|bool
name|toBool
argument_list|()
block|;
name|ushort
name|toUShort
argument_list|()
block|;
name|short
name|toShort
argument_list|()
block|;
name|int
name|toInt
argument_list|()
block|;
name|uint
name|toUInt
argument_list|()
block|;
name|qlonglong
name|toLongLong
argument_list|()
block|;
name|qulonglong
name|toULongLong
argument_list|()
block|;
name|double
name|toDouble
argument_list|()
block|;
name|QString
name|toString
argument_list|()
block|;
name|QDBusObjectPath
name|toObjectPath
argument_list|()
block|;
name|QDBusSignature
name|toSignature
argument_list|()
block|;
name|QDBusUnixFileDescriptor
name|toUnixFileDescriptor
argument_list|()
block|;
name|QDBusVariant
name|toVariant
argument_list|()
block|;
name|QStringList
name|toStringList
argument_list|()
block|;
name|QByteArray
name|toByteArray
argument_list|()
block|;
name|QDBusDemarshaller
operator|*
name|beginStructure
argument_list|()
block|;
name|QDBusDemarshaller
operator|*
name|endStructure
argument_list|()
block|;
name|QDBusDemarshaller
operator|*
name|beginArray
argument_list|()
block|;
name|QDBusDemarshaller
operator|*
name|endArray
argument_list|()
block|;
name|QDBusDemarshaller
operator|*
name|beginMap
argument_list|()
block|;
name|QDBusDemarshaller
operator|*
name|endMap
argument_list|()
block|;
name|QDBusDemarshaller
operator|*
name|beginMapEntry
argument_list|()
block|;
name|QDBusDemarshaller
operator|*
name|endMapEntry
argument_list|()
block|;
name|QDBusDemarshaller
operator|*
name|beginCommon
argument_list|()
block|;
name|QDBusDemarshaller
operator|*
name|endCommon
argument_list|()
block|;
name|QDBusArgument
name|duplicate
argument_list|()
block|;
specifier|inline
name|void
name|close
argument_list|()
block|{ }
name|bool
name|atEnd
argument_list|()
block|;
name|QVariant
name|toVariantInternal
argument_list|()
block|;
name|QDBusArgument
operator|::
name|ElementType
name|currentType
argument_list|()
block|;
name|bool
name|isCurrentTypeStringLike
argument_list|()
block|;
name|public
operator|:
name|DBusMessageIter
name|iterator
block|;
name|QDBusDemarshaller
operator|*
name|parent
block|;
name|private
operator|:
name|Q_DISABLE_COPY
argument_list|(
argument|QDBusDemarshaller
argument_list|)
name|QString
name|toStringUnchecked
argument_list|()
block|;
name|QDBusObjectPath
name|toObjectPathUnchecked
argument_list|()
block|;
name|QDBusSignature
name|toSignatureUnchecked
argument_list|()
block|;
name|QStringList
name|toStringListUnchecked
argument_list|()
block|;
name|QByteArray
name|toByteArrayUnchecked
argument_list|()
block|; }
decl_stmt|;
end_decl_stmt
begin_expr_stmt
DECL|function|marshaller
specifier|inline
name|QDBusMarshaller
operator|*
name|QDBusArgumentPrivate
operator|::
name|marshaller
argument_list|()
block|{
return|return
name|static_cast
operator|<
name|QDBusMarshaller
operator|*
operator|>
operator|(
name|this
operator|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|demarshaller
specifier|inline
name|QDBusDemarshaller
operator|*
name|QDBusArgumentPrivate
operator|::
name|demarshaller
argument_list|()
block|{
return|return
name|static_cast
operator|<
name|QDBusDemarshaller
operator|*
operator|>
operator|(
name|this
operator|)
return|;
block|}
end_expr_stmt
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
begin_endif
endif|#
directive|endif
end_endif
end_unit
