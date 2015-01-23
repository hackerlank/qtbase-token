begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the QtDBus module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QDBUSMESSAGE_H
end_ifndef
begin_define
DECL|macro|QDBUSMESSAGE_H
define|#
directive|define
name|QDBUSMESSAGE_H
end_define
begin_include
include|#
directive|include
file|<QtDBus/qdbusmacros.h>
end_include
begin_include
include|#
directive|include
file|<QtDBus/qdbuserror.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qlist.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qvariant.h>
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_DBUS
end_ifndef
begin_if
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_WIN
argument_list|)
operator|&&
name|defined
argument_list|(
name|interface
argument_list|)
end_if
begin_undef
DECL|macro|interface
undef|#
directive|undef
name|interface
end_undef
begin_endif
endif|#
directive|endif
end_endif
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QDBusMessagePrivate
name|class
name|QDBusMessagePrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_DBUS_EXPORT
name|QDBusMessage
block|{
name|public
label|:
enum|enum
name|MessageType
block|{
name|InvalidMessage
block|,
name|MethodCallMessage
block|,
name|ReplyMessage
block|,
name|ErrorMessage
block|,
name|SignalMessage
block|}
enum|;
name|QDBusMessage
argument_list|()
expr_stmt|;
name|QDBusMessage
argument_list|(
specifier|const
name|QDBusMessage
operator|&
name|other
argument_list|)
expr_stmt|;
name|QDBusMessage
modifier|&
name|operator
init|=
operator|(
specifier|const
name|QDBusMessage
operator|&
name|other
operator|)
decl_stmt|;
operator|~
name|QDBusMessage
argument_list|()
expr_stmt|;
specifier|static
name|QDBusMessage
name|createSignal
parameter_list|(
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
name|name
parameter_list|)
function_decl|;
specifier|static
name|QDBusMessage
name|createMethodCall
parameter_list|(
specifier|const
name|QString
modifier|&
name|destination
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
parameter_list|)
function_decl|;
specifier|static
name|QDBusMessage
name|createError
parameter_list|(
specifier|const
name|QString
modifier|&
name|name
parameter_list|,
specifier|const
name|QString
modifier|&
name|msg
parameter_list|)
function_decl|;
specifier|static
specifier|inline
name|QDBusMessage
name|createError
parameter_list|(
specifier|const
name|QDBusError
modifier|&
name|err
parameter_list|)
block|{
return|return
name|createError
argument_list|(
name|err
operator|.
name|name
argument_list|()
argument_list|,
name|err
operator|.
name|message
argument_list|()
argument_list|)
return|;
block|}
specifier|static
specifier|inline
name|QDBusMessage
name|createError
argument_list|(
name|QDBusError
operator|::
name|ErrorType
name|type
argument_list|,
specifier|const
name|QString
operator|&
name|msg
argument_list|)
block|{
return|return
name|createError
argument_list|(
name|QDBusError
operator|::
name|errorString
argument_list|(
name|type
argument_list|)
argument_list|,
name|msg
argument_list|)
return|;
block|}
name|QDBusMessage
name|createReply
argument_list|(
specifier|const
name|QList
operator|<
name|QVariant
operator|>
operator|&
name|arguments
operator|=
name|QList
operator|<
name|QVariant
operator|>
operator|(
operator|)
argument_list|)
decl|const
decl_stmt|;
specifier|inline
name|QDBusMessage
name|createReply
argument_list|(
specifier|const
name|QVariant
operator|&
name|argument
argument_list|)
decl|const
block|{
return|return
name|createReply
argument_list|(
name|QList
operator|<
name|QVariant
operator|>
operator|(
operator|)
operator|<<
name|argument
argument_list|)
return|;
block|}
if|#
directive|if
name|QT_VERSION
operator|>=
name|QT_VERSION_CHECK
argument_list|(
literal|6
operator|,
literal|0
operator|,
literal|0
argument_list|)
name|QDBusMessage
name|createErrorReply
argument_list|(
specifier|const
name|QString
operator|&
name|name
argument_list|,
specifier|const
name|QString
operator|&
name|msg
argument_list|)
decl|const
decl_stmt|;
else|#
directive|else
name|QDBusMessage
name|createErrorReply
argument_list|(
specifier|const
name|QString
name|name
argument_list|,
specifier|const
name|QString
operator|&
name|msg
argument_list|)
decl|const
decl_stmt|;
endif|#
directive|endif
specifier|inline
name|QDBusMessage
name|createErrorReply
argument_list|(
specifier|const
name|QDBusError
operator|&
name|err
argument_list|)
decl|const
block|{
return|return
name|createErrorReply
argument_list|(
name|err
operator|.
name|name
argument_list|()
argument_list|,
name|err
operator|.
name|message
argument_list|()
argument_list|)
return|;
block|}
name|QDBusMessage
name|createErrorReply
argument_list|(
name|QDBusError
operator|::
name|ErrorType
name|type
argument_list|,
specifier|const
name|QString
operator|&
name|msg
argument_list|)
decl|const
decl_stmt|;
comment|// there are no setters; if this changes, see qdbusmessage_p.h
name|QString
name|service
argument_list|()
specifier|const
expr_stmt|;
name|QString
name|path
argument_list|()
specifier|const
expr_stmt|;
name|QString
name|interface
argument_list|()
specifier|const
expr_stmt|;
name|QString
name|member
argument_list|()
specifier|const
expr_stmt|;
name|QString
name|errorName
argument_list|()
specifier|const
expr_stmt|;
name|QString
name|errorMessage
argument_list|()
specifier|const
expr_stmt|;
name|MessageType
name|type
argument_list|()
specifier|const
expr_stmt|;
name|QString
name|signature
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|isReplyRequired
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setDelayedReply
argument_list|(
name|bool
name|enable
argument_list|)
decl|const
decl_stmt|;
name|bool
name|isDelayedReply
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setAutoStartService
parameter_list|(
name|bool
name|enable
parameter_list|)
function_decl|;
name|bool
name|autoStartService
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setArguments
argument_list|(
specifier|const
name|QList
operator|<
name|QVariant
operator|>
operator|&
name|arguments
argument_list|)
decl_stmt|;
name|QList
operator|<
name|QVariant
operator|>
name|arguments
argument_list|()
specifier|const
expr_stmt|;
name|QDBusMessage
operator|&
name|operator
operator|<<
operator|(
specifier|const
name|QVariant
operator|&
name|arg
operator|)
expr_stmt|;
name|private
label|:
name|friend
name|class
name|QDBusMessagePrivate
decl_stmt|;
name|QDBusMessagePrivate
modifier|*
name|d_ptr
decl_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_DEBUG_STREAM
end_ifndef
begin_expr_stmt
name|Q_DBUS_EXPORT
name|QDebug
name|operator
operator|<<
operator|(
name|QDebug
operator|,
specifier|const
name|QDBusMessage
operator|&
operator|)
expr_stmt|;
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_decl_stmt
name|QT_END_NAMESPACE
name|Q_DECLARE_METATYPE
argument_list|(
name|QDBusMessage
argument_list|)
end_decl_stmt
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
