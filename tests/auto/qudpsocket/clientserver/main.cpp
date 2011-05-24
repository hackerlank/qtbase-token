begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtNetwork>
end_include
begin_class
DECL|class|ClientServer
class|class
name|ClientServer
super|:
specifier|public
name|QUdpSocket
block|{
name|Q_OBJECT
public|public:
DECL|enum|Type
enum|enum
name|Type
block|{
DECL|enumerator|ConnectedClient
name|ConnectedClient
block|,
DECL|enumerator|UnconnectedClient
name|UnconnectedClient
block|,
DECL|enumerator|Server
name|Server
block|}
enum|;
DECL|function|ClientServer
name|ClientServer
parameter_list|(
name|Type
name|type
parameter_list|,
specifier|const
name|QString
modifier|&
name|host
parameter_list|,
name|quint16
name|port
parameter_list|)
member_init_list|:
name|type
argument_list|(
name|type
argument_list|)
block|{
switch|switch
condition|(
name|type
condition|)
block|{
case|case
name|Server
case|:
if|if
condition|(
name|bind
argument_list|(
literal|0
argument_list|,
name|ShareAddress
operator||
name|ReuseAddressHint
argument_list|)
condition|)
block|{
name|printf
argument_list|(
literal|"%d\n"
argument_list|,
name|localPort
argument_list|()
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|printf
argument_list|(
literal|"XXX\n"
argument_list|)
expr_stmt|;
block|}
break|break;
case|case
name|ConnectedClient
case|:
name|connectToHost
argument_list|(
name|host
argument_list|,
name|port
argument_list|)
expr_stmt|;
name|startTimer
argument_list|(
literal|250
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"ok\n"
argument_list|)
expr_stmt|;
break|break;
case|case
name|UnconnectedClient
case|:
name|peerAddress
operator|=
name|host
expr_stmt|;
name|peerPort
operator|=
name|port
expr_stmt|;
if|if
condition|(
name|bind
argument_list|(
name|QHostAddress
operator|::
name|Any
argument_list|,
name|port
operator|+
literal|1
argument_list|,
name|ShareAddress
operator||
name|ReuseAddressHint
argument_list|)
condition|)
block|{
name|startTimer
argument_list|(
literal|250
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"ok\n"
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|printf
argument_list|(
literal|"XXX\n"
argument_list|)
expr_stmt|;
block|}
break|break;
block|}
name|fflush
argument_list|(
name|stdout
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|this
argument_list|,
name|SIGNAL
argument_list|(
name|readyRead
argument_list|()
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|readData
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
block|}
protected|protected:
DECL|function|timerEvent
name|void
name|timerEvent
parameter_list|(
name|QTimerEvent
modifier|*
name|event
parameter_list|)
block|{
specifier|static
name|int
name|n
init|=
literal|0
decl_stmt|;
switch|switch
condition|(
name|type
condition|)
block|{
case|case
name|ConnectedClient
case|:
name|write
argument_list|(
name|QByteArray
operator|::
name|number
argument_list|(
name|n
operator|++
argument_list|)
argument_list|)
expr_stmt|;
break|break;
case|case
name|UnconnectedClient
case|:
name|writeDatagram
argument_list|(
name|QByteArray
operator|::
name|number
argument_list|(
name|n
operator|++
argument_list|)
argument_list|,
name|peerAddress
argument_list|,
name|peerPort
argument_list|)
expr_stmt|;
break|break;
default|default:
break|break;
block|}
name|QUdpSocket
operator|::
name|timerEvent
argument_list|(
name|event
argument_list|)
expr_stmt|;
block|}
private|private
name|slots
private|:
DECL|function|readData
name|void
name|readData
parameter_list|()
block|{
name|printf
argument_list|(
literal|"readData()\n"
argument_list|)
expr_stmt|;
switch|switch
condition|(
name|type
condition|)
block|{
case|case
name|ConnectedClient
case|:
block|{
while|while
condition|(
name|bytesAvailable
argument_list|()
operator|||
name|hasPendingDatagrams
argument_list|()
condition|)
block|{
name|QByteArray
name|data
init|=
name|readAll
argument_list|()
decl_stmt|;
name|printf
argument_list|(
literal|"got %d\n"
argument_list|,
name|data
operator|.
name|toInt
argument_list|()
argument_list|)
expr_stmt|;
block|}
break|break;
block|}
case|case
name|UnconnectedClient
case|:
block|{
while|while
condition|(
name|hasPendingDatagrams
argument_list|()
condition|)
block|{
name|QByteArray
name|data
decl_stmt|;
name|data
operator|.
name|resize
argument_list|(
name|pendingDatagramSize
argument_list|()
argument_list|)
expr_stmt|;
name|readDatagram
argument_list|(
name|data
operator|.
name|data
argument_list|()
argument_list|,
name|data
operator|.
name|size
argument_list|()
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"got %d\n"
argument_list|,
name|data
operator|.
name|toInt
argument_list|()
argument_list|)
expr_stmt|;
block|}
break|break;
block|}
case|case
name|Server
case|:
block|{
while|while
condition|(
name|hasPendingDatagrams
argument_list|()
condition|)
block|{
name|QHostAddress
name|sender
decl_stmt|;
name|quint16
name|senderPort
decl_stmt|;
name|QByteArray
name|data
decl_stmt|;
name|data
operator|.
name|resize
argument_list|(
name|pendingDatagramSize
argument_list|()
argument_list|)
expr_stmt|;
name|readDatagram
argument_list|(
name|data
operator|.
name|data
argument_list|()
argument_list|,
name|data
operator|.
name|size
argument_list|()
argument_list|,
operator|&
name|sender
argument_list|,
operator|&
name|senderPort
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"got %d\n"
argument_list|,
name|data
operator|.
name|toInt
argument_list|()
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"sending %d\n"
argument_list|,
name|data
operator|.
name|toInt
argument_list|()
operator|*
literal|2
argument_list|)
expr_stmt|;
name|writeDatagram
argument_list|(
name|QByteArray
operator|::
name|number
argument_list|(
name|data
operator|.
name|toInt
argument_list|()
operator|*
literal|2
argument_list|)
argument_list|,
name|sender
argument_list|,
name|senderPort
argument_list|)
expr_stmt|;
block|}
break|break;
block|}
block|}
name|fflush
argument_list|(
name|stdout
argument_list|)
expr_stmt|;
block|}
private|private:
DECL|member|type
name|Type
name|type
decl_stmt|;
DECL|member|peerAddress
name|QHostAddress
name|peerAddress
decl_stmt|;
DECL|member|peerPort
name|quint16
name|peerPort
decl_stmt|;
block|}
class|;
end_class
begin_function
DECL|function|main
name|int
name|main
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
modifier|*
name|argv
parameter_list|)
block|{
name|QCoreApplication
name|app
argument_list|(
name|argc
argument_list|,
name|argv
argument_list|)
decl_stmt|;
name|ClientServer
operator|::
name|Type
name|type
decl_stmt|;
if|if
condition|(
name|app
operator|.
name|arguments
argument_list|()
operator|.
name|size
argument_list|()
operator|<
literal|4
condition|)
block|{
name|qDebug
argument_list|(
literal|"usage: ./%s [ConnectedClient<server><port>|UnconnectedClient<server><port>|Server]"
argument_list|,
name|argv
index|[
literal|0
index|]
argument_list|)
expr_stmt|;
return|return
literal|1
return|;
block|}
name|QString
name|arg
init|=
name|app
operator|.
name|arguments
argument_list|()
operator|.
name|at
argument_list|(
literal|1
argument_list|)
operator|.
name|trimmed
argument_list|()
operator|.
name|toLower
argument_list|()
decl_stmt|;
if|if
condition|(
name|arg
operator|==
literal|"connectedclient"
condition|)
name|type
operator|=
name|ClientServer
operator|::
name|ConnectedClient
expr_stmt|;
elseif|else
if|if
condition|(
name|arg
operator|==
literal|"unconnectedclient"
condition|)
name|type
operator|=
name|ClientServer
operator|::
name|UnconnectedClient
expr_stmt|;
elseif|else
if|if
condition|(
name|arg
operator|==
literal|"server"
condition|)
name|type
operator|=
name|ClientServer
operator|::
name|Server
expr_stmt|;
name|ClientServer
name|clientServer
argument_list|(
name|type
argument_list|,
name|app
operator|.
name|arguments
argument_list|()
operator|.
name|at
argument_list|(
literal|2
argument_list|)
argument_list|,
name|app
operator|.
name|arguments
argument_list|()
operator|.
name|at
argument_list|(
literal|3
argument_list|)
operator|.
name|toInt
argument_list|()
argument_list|)
decl_stmt|;
return|return
name|app
operator|.
name|exec
argument_list|()
return|;
block|}
end_function
begin_include
include|#
directive|include
file|"main.moc"
end_include
end_unit
