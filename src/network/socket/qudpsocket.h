begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the QtNetwork module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QUDPSOCKET_H
end_ifndef
begin_define
DECL|macro|QUDPSOCKET_H
define|#
directive|define
name|QUDPSOCKET_H
end_define
begin_include
include|#
directive|include
file|<QtNetwork/qabstractsocket.h>
end_include
begin_include
include|#
directive|include
file|<QtNetwork/qhostaddress.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
ifndef|#
directive|ifndef
name|QT_NO_UDPSOCKET
DECL|variable|QNetworkInterface
name|class
name|QNetworkInterface
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QUdpSocketPrivate
name|class
name|QUdpSocketPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_NETWORK_EXPORT
name|QUdpSocket
range|:
name|public
name|QAbstractSocket
block|{
name|Q_OBJECT
name|public
operator|:
name|explicit
name|QUdpSocket
argument_list|(
name|QObject
operator|*
name|parent
operator|=
name|Q_NULLPTR
argument_list|)
block|;
name|virtual
operator|~
name|QUdpSocket
argument_list|()
block|;
ifndef|#
directive|ifndef
name|QT_NO_NETWORKINTERFACE
name|bool
name|joinMulticastGroup
argument_list|(
specifier|const
name|QHostAddress
operator|&
name|groupAddress
argument_list|)
block|;
name|bool
name|joinMulticastGroup
argument_list|(
specifier|const
name|QHostAddress
operator|&
name|groupAddress
argument_list|,
specifier|const
name|QNetworkInterface
operator|&
name|iface
argument_list|)
block|;
name|bool
name|leaveMulticastGroup
argument_list|(
specifier|const
name|QHostAddress
operator|&
name|groupAddress
argument_list|)
block|;
name|bool
name|leaveMulticastGroup
argument_list|(
specifier|const
name|QHostAddress
operator|&
name|groupAddress
argument_list|,
specifier|const
name|QNetworkInterface
operator|&
name|iface
argument_list|)
block|;
name|QNetworkInterface
name|multicastInterface
argument_list|()
specifier|const
block|;
name|void
name|setMulticastInterface
argument_list|(
specifier|const
name|QNetworkInterface
operator|&
name|iface
argument_list|)
block|;
endif|#
directive|endif
name|bool
name|hasPendingDatagrams
argument_list|()
specifier|const
block|;
name|qint64
name|pendingDatagramSize
argument_list|()
specifier|const
block|;
name|qint64
name|readDatagram
argument_list|(
argument|char *data
argument_list|,
argument|qint64 maxlen
argument_list|,
argument|QHostAddress *host = Q_NULLPTR
argument_list|,
argument|quint16 *port = Q_NULLPTR
argument_list|)
block|;
name|qint64
name|writeDatagram
argument_list|(
argument|const char *data
argument_list|,
argument|qint64 len
argument_list|,
argument|const QHostAddress&host
argument_list|,
argument|quint16 port
argument_list|)
block|;
specifier|inline
name|qint64
name|writeDatagram
argument_list|(
argument|const QByteArray&datagram
argument_list|,
argument|const QHostAddress&host
argument_list|,
argument|quint16 port
argument_list|)
block|{
return|return
name|writeDatagram
argument_list|(
name|datagram
operator|.
name|constData
argument_list|()
argument_list|,
name|datagram
operator|.
name|size
argument_list|()
argument_list|,
name|host
argument_list|,
name|port
argument_list|)
return|;
block|}
name|private
operator|:
name|Q_DISABLE_COPY
argument_list|(
argument|QUdpSocket
argument_list|)
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QUdpSocket
argument_list|)
expr|}
block|;
endif|#
directive|endif
comment|// QT_NO_UDPSOCKET
name|QT_END_NAMESPACE
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QUDPSOCKET_H
end_comment
end_unit
