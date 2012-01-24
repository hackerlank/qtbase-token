begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtNetwork module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_comment
comment|//#define QTCPSOCKET_DEBUG
end_comment
begin_comment
comment|/*!      \class QTcpSocket      \brief The QTcpSocket class provides a TCP socket.      \reentrant     \ingroup network     \inmodule QtNetwork      TCP (Transmission Control Protocol) is a reliable,     stream-oriented, connection-oriented transport protocol. It is     especially well suited for continuous transmission of data.      QTcpSocket is a convenience subclass of QAbstractSocket that     allows you to establish a TCP connection and transfer streams of     data. See the QAbstractSocket documentation for details.      \bold{Note:} TCP sockets cannot be opened in QIODevice::Unbuffered mode.      \sa QTcpServer, QUdpSocket, QNetworkAccessManager,     {Fortune Server Example}, {Fortune Client Example},     {Threaded Fortune Server Example}, {Blocking Fortune Client Example},     {Loopback Example}, {Torrent Example} */
end_comment
begin_include
include|#
directive|include
file|"qlist.h"
end_include
begin_include
include|#
directive|include
file|"qtcpsocket_p.h"
end_include
begin_include
include|#
directive|include
file|"qtcpsocket.h"
end_include
begin_include
include|#
directive|include
file|"qhostaddress.h"
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_comment
comment|/*!     Creates a QTcpSocket object in state \c UnconnectedState.      \a parent is passed on to the QObject constructor.      \sa socketType() */
end_comment
begin_constructor
DECL|function|QTcpSocket
name|QTcpSocket
operator|::
name|QTcpSocket
parameter_list|(
name|QObject
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QAbstractSocket
argument_list|(
name|TcpSocket
argument_list|,
operator|*
operator|new
name|QTcpSocketPrivate
argument_list|,
name|parent
argument_list|)
block|{
if|#
directive|if
name|defined
argument_list|(
name|QTCPSOCKET_DEBUG
argument_list|)
name|qDebug
argument_list|(
literal|"QTcpSocket::QTcpSocket()"
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|d_func
argument_list|()
operator|->
name|isBuffered
operator|=
literal|true
expr_stmt|;
block|}
end_constructor
begin_comment
comment|/*!     Destroys the socket, closing the connection if necessary.      \sa close() */
end_comment
begin_destructor
DECL|function|~QTcpSocket
name|QTcpSocket
operator|::
name|~
name|QTcpSocket
parameter_list|()
block|{
if|#
directive|if
name|defined
argument_list|(
name|QTCPSOCKET_DEBUG
argument_list|)
name|qDebug
argument_list|(
literal|"QTcpSocket::~QTcpSocket()"
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
end_destructor
begin_comment
comment|/*!     \internal */
end_comment
begin_constructor
DECL|function|QTcpSocket
name|QTcpSocket
operator|::
name|QTcpSocket
parameter_list|(
name|QTcpSocketPrivate
modifier|&
name|dd
parameter_list|,
name|QObject
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QAbstractSocket
argument_list|(
name|TcpSocket
argument_list|,
name|dd
argument_list|,
name|parent
argument_list|)
block|{
name|d_func
argument_list|()
operator|->
name|isBuffered
operator|=
literal|true
expr_stmt|;
block|}
end_constructor
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
