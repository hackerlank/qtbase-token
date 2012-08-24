begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtDBus module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
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
comment|// This file is not part of the public API.  This header file may
end_comment
begin_comment
comment|// change from version to version without notice, or even be
end_comment
begin_comment
comment|// removed.
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
begin_comment
comment|//
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QDBUSPENDINGCALL_P_H
end_ifndef
begin_define
DECL|macro|QDBUSPENDINGCALL_P_H
define|#
directive|define
name|QDBUSPENDINGCALL_P_H
end_define
begin_include
include|#
directive|include
file|<qshareddata.h>
end_include
begin_include
include|#
directive|include
file|<qpointer.h>
end_include
begin_include
include|#
directive|include
file|<qvector.h>
end_include
begin_include
include|#
directive|include
file|<qmutex.h>
end_include
begin_include
include|#
directive|include
file|<qwaitcondition.h>
end_include
begin_include
include|#
directive|include
file|"qdbusmessage.h"
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
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QDBusPendingCall
name|class
name|QDBusPendingCall
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QDBusPendingCallWatcher
name|class
name|QDBusPendingCallWatcher
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QDBusPendingCallWatcherHelper
name|class
name|QDBusPendingCallWatcherHelper
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QDBusConnectionPrivate
name|class
name|QDBusConnectionPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QDBusPendingCallPrivate
range|:
name|public
name|QSharedData
block|{
name|public
operator|:
comment|// {
comment|//     set only during construction:
specifier|const
name|QDBusMessage
name|sentMessage
block|;
name|QDBusConnectionPrivate
operator|*
specifier|const
name|connection
block|;
comment|// for the callback mechanism (see setReplyCallback and QDBusConnectionPrivate::sendWithReplyAsync)
name|QPointer
operator|<
name|QObject
operator|>
name|receiver
block|;
name|QVector
operator|<
name|int
operator|>
name|metaTypes
block|;
name|int
name|methodIdx
block|;
name|bool
name|autoDelete
block|;
comment|// }
name|mutable
name|QMutex
name|mutex
block|;
name|QWaitCondition
name|waitForFinishedCondition
block|;
comment|// {
comment|//    protected by the mutex above:
name|QDBusPendingCallWatcherHelper
operator|*
name|watcherHelper
block|;
name|QDBusMessage
name|replyMessage
block|;
name|DBusPendingCall
operator|*
name|pending
block|;
name|QString
name|expectedReplySignature
block|;
name|int
name|expectedReplyCount
block|;
name|bool
name|waitingForFinished
block|;
comment|// }
name|QDBusPendingCallPrivate
argument_list|(
specifier|const
name|QDBusMessage
operator|&
name|sent
argument_list|,
name|QDBusConnectionPrivate
operator|*
name|connection
argument_list|)
operator|:
name|sentMessage
argument_list|(
name|sent
argument_list|)
block|,
name|connection
argument_list|(
name|connection
argument_list|)
block|,
name|autoDelete
argument_list|(
name|false
argument_list|)
block|,
name|watcherHelper
argument_list|(
literal|0
argument_list|)
block|,
name|pending
argument_list|(
literal|0
argument_list|)
block|,
name|waitingForFinished
argument_list|(
argument|false
argument_list|)
block|{ }
operator|~
name|QDBusPendingCallPrivate
argument_list|()
block|;
name|bool
name|setReplyCallback
argument_list|(
name|QObject
operator|*
name|target
argument_list|,
specifier|const
name|char
operator|*
name|member
argument_list|)
block|;
name|void
name|waitForFinished
argument_list|()
block|;
name|void
name|setMetaTypes
argument_list|(
argument|int count
argument_list|,
argument|const int *types
argument_list|)
block|;
name|void
name|checkReceivedSignature
argument_list|()
block|;
specifier|static
name|QDBusPendingCall
name|fromMessage
argument_list|(
specifier|const
name|QDBusMessage
operator|&
name|msg
argument_list|)
block|; }
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QDBusPendingCallWatcherHelper
range|:
name|public
name|QObject
block|{
name|Q_OBJECT
name|public
operator|:
name|void
name|add
argument_list|(
name|QDBusPendingCallWatcher
operator|*
name|watcher
argument_list|)
block|;
name|void
name|emitSignals
argument_list|(
argument|const QDBusMessage&replyMessage
argument_list|,
argument|const QDBusMessage&sentMessage
argument_list|)
block|{
if|if
condition|(
name|replyMessage
operator|.
name|type
argument_list|()
operator|==
name|QDBusMessage
operator|::
name|ReplyMessage
condition|)
name|emit
name|reply
parameter_list|(
name|replyMessage
parameter_list|)
function_decl|;
else|else
name|emit
name|error
argument_list|(
name|QDBusError
argument_list|(
name|replyMessage
argument_list|)
argument_list|,
name|sentMessage
argument_list|)
decl_stmt|;
name|emit
name|finished
argument_list|()
block|;     }
name|Q_SIGNALS
operator|:
name|void
name|finished
argument_list|()
decl_stmt|;
end_decl_stmt
begin_function_decl
name|void
name|reply
parameter_list|(
specifier|const
name|QDBusMessage
modifier|&
name|msg
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|error
parameter_list|(
specifier|const
name|QDBusError
modifier|&
name|error
parameter_list|,
specifier|const
name|QDBusMessage
modifier|&
name|msg
parameter_list|)
function_decl|;
end_function_decl
begin_macro
unit|};
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
