begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2014 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtNetwork module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia. For licensing terms and ** conditions see http://qt.digia.com/licensing. For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights. These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QLOCALSERVER_H
end_ifndef
begin_define
DECL|macro|QLOCALSERVER_H
define|#
directive|define
name|QLOCALSERVER_H
end_define
begin_include
include|#
directive|include
file|<QtNetwork/qabstractsocket.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
ifndef|#
directive|ifndef
name|QT_NO_LOCALSERVER
DECL|variable|QLocalSocket
name|class
name|QLocalSocket
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QLocalServerPrivate
name|class
name|QLocalServerPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_NETWORK_EXPORT
name|QLocalServer
range|:
name|public
name|QObject
block|{
name|Q_OBJECT
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QLocalServer
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|SocketOptions socketOptions READ socketOptions WRITE setSocketOptions
argument_list|)
name|Q_FLAGS
argument_list|(
argument|SocketOption SocketOptions
argument_list|)
name|Q_SIGNALS
operator|:
name|void
name|newConnection
argument_list|()
block|;
name|public
operator|:
expr|enum
name|SocketOption
block|{
name|NoOptions
operator|=
literal|0x0
block|,
name|UserAccessOption
operator|=
literal|0x01
block|,
name|GroupAccessOption
operator|=
literal|0x2
block|,
name|OtherAccessOption
operator|=
literal|0x4
block|,
name|WorldAccessOption
operator|=
literal|0x7
block|}
block|;
name|Q_DECLARE_FLAGS
argument_list|(
argument|SocketOptions
argument_list|,
argument|SocketOption
argument_list|)
name|explicit
name|QLocalServer
argument_list|(
name|QObject
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
operator|~
name|QLocalServer
argument_list|()
block|;
name|void
name|close
argument_list|()
block|;
name|QString
name|errorString
argument_list|()
specifier|const
block|;
name|virtual
name|bool
name|hasPendingConnections
argument_list|()
specifier|const
block|;
name|bool
name|isListening
argument_list|()
specifier|const
block|;
name|bool
name|listen
argument_list|(
specifier|const
name|QString
operator|&
name|name
argument_list|)
block|;
name|bool
name|listen
argument_list|(
argument|qintptr socketDescriptor
argument_list|)
block|;
name|int
name|maxPendingConnections
argument_list|()
specifier|const
block|;
name|virtual
name|QLocalSocket
operator|*
name|nextPendingConnection
argument_list|()
block|;
name|QString
name|serverName
argument_list|()
specifier|const
block|;
name|QString
name|fullServerName
argument_list|()
specifier|const
block|;
specifier|static
name|bool
name|removeServer
argument_list|(
specifier|const
name|QString
operator|&
name|name
argument_list|)
block|;
name|QAbstractSocket
operator|::
name|SocketError
name|serverError
argument_list|()
specifier|const
block|;
name|void
name|setMaxPendingConnections
argument_list|(
argument|int numConnections
argument_list|)
block|;
name|bool
name|waitForNewConnection
argument_list|(
argument|int msec =
literal|0
argument_list|,
argument|bool *timedOut =
literal|0
argument_list|)
block|;
name|void
name|setSocketOptions
argument_list|(
argument|SocketOptions options
argument_list|)
block|;
name|SocketOptions
name|socketOptions
argument_list|()
specifier|const
block|;
name|protected
operator|:
name|virtual
name|void
name|incomingConnection
argument_list|(
argument|quintptr socketDescriptor
argument_list|)
block|;
name|private
operator|:
name|Q_DISABLE_COPY
argument_list|(
argument|QLocalServer
argument_list|)
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_onNewConnection()
argument_list|)
block|}
decl_stmt|;
end_decl_stmt
begin_macro
name|Q_DECLARE_OPERATORS_FOR_FLAGS
argument_list|(
argument|QLocalServer::SocketOptions
argument_list|)
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_LOCALSERVER
end_comment
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QLOCALSERVER_H
end_comment
end_unit
