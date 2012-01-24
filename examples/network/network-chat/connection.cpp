begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of Nokia Corporation and its Subsidiary(-ies) nor **     the names of its contributors may be used to endorse or promote **     products derived from this software without specific prior written **     permission. ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"connection.h"
end_include
begin_include
include|#
directive|include
file|<QtNetwork>
end_include
begin_decl_stmt
DECL|variable|TransferTimeout
specifier|static
specifier|const
name|int
name|TransferTimeout
init|=
literal|30
operator|*
literal|1000
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|PongTimeout
specifier|static
specifier|const
name|int
name|PongTimeout
init|=
literal|60
operator|*
literal|1000
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|PingInterval
specifier|static
specifier|const
name|int
name|PingInterval
init|=
literal|5
operator|*
literal|1000
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|SeparatorToken
specifier|static
specifier|const
name|char
name|SeparatorToken
init|=
literal|' '
decl_stmt|;
end_decl_stmt
begin_constructor
DECL|function|Connection
name|Connection
operator|::
name|Connection
parameter_list|(
name|QObject
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QTcpSocket
argument_list|(
name|parent
argument_list|)
block|{
name|greetingMessage
operator|=
name|tr
argument_list|(
literal|"undefined"
argument_list|)
expr_stmt|;
name|username
operator|=
name|tr
argument_list|(
literal|"unknown"
argument_list|)
expr_stmt|;
name|state
operator|=
name|WaitingForGreeting
expr_stmt|;
name|currentDataType
operator|=
name|Undefined
expr_stmt|;
name|numBytesForCurrentDataType
operator|=
operator|-
literal|1
expr_stmt|;
name|transferTimerId
operator|=
literal|0
expr_stmt|;
name|isGreetingMessageSent
operator|=
literal|false
expr_stmt|;
name|pingTimer
operator|.
name|setInterval
argument_list|(
name|PingInterval
argument_list|)
expr_stmt|;
name|QObject
operator|::
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
name|processReadyRead
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|QObject
operator|::
name|connect
argument_list|(
name|this
argument_list|,
name|SIGNAL
argument_list|(
name|disconnected
argument_list|()
argument_list|)
argument_list|,
operator|&
name|pingTimer
argument_list|,
name|SLOT
argument_list|(
name|stop
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|QObject
operator|::
name|connect
argument_list|(
operator|&
name|pingTimer
argument_list|,
name|SIGNAL
argument_list|(
name|timeout
argument_list|()
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|sendPing
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|QObject
operator|::
name|connect
argument_list|(
name|this
argument_list|,
name|SIGNAL
argument_list|(
name|connected
argument_list|()
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|sendGreetingMessage
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_function
DECL|function|name
name|QString
name|Connection
operator|::
name|name
parameter_list|()
specifier|const
block|{
return|return
name|username
return|;
block|}
end_function
begin_function
DECL|function|setGreetingMessage
name|void
name|Connection
operator|::
name|setGreetingMessage
parameter_list|(
specifier|const
name|QString
modifier|&
name|message
parameter_list|)
block|{
name|greetingMessage
operator|=
name|message
expr_stmt|;
block|}
end_function
begin_function
DECL|function|sendMessage
name|bool
name|Connection
operator|::
name|sendMessage
parameter_list|(
specifier|const
name|QString
modifier|&
name|message
parameter_list|)
block|{
if|if
condition|(
name|message
operator|.
name|isEmpty
argument_list|()
condition|)
return|return
literal|false
return|;
name|QByteArray
name|msg
init|=
name|message
operator|.
name|toUtf8
argument_list|()
decl_stmt|;
name|QByteArray
name|data
init|=
literal|"MESSAGE "
operator|+
name|QByteArray
operator|::
name|number
argument_list|(
name|msg
operator|.
name|size
argument_list|()
argument_list|)
operator|+
literal|' '
operator|+
name|msg
decl_stmt|;
return|return
name|write
argument_list|(
name|data
argument_list|)
operator|==
name|data
operator|.
name|size
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|timerEvent
name|void
name|Connection
operator|::
name|timerEvent
parameter_list|(
name|QTimerEvent
modifier|*
name|timerEvent
parameter_list|)
block|{
if|if
condition|(
name|timerEvent
operator|->
name|timerId
argument_list|()
operator|==
name|transferTimerId
condition|)
block|{
name|abort
argument_list|()
expr_stmt|;
name|killTimer
argument_list|(
name|transferTimerId
argument_list|)
expr_stmt|;
name|transferTimerId
operator|=
literal|0
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|processReadyRead
name|void
name|Connection
operator|::
name|processReadyRead
parameter_list|()
block|{
if|if
condition|(
name|state
operator|==
name|WaitingForGreeting
condition|)
block|{
if|if
condition|(
operator|!
name|readProtocolHeader
argument_list|()
condition|)
return|return;
if|if
condition|(
name|currentDataType
operator|!=
name|Greeting
condition|)
block|{
name|abort
argument_list|()
expr_stmt|;
return|return;
block|}
name|state
operator|=
name|ReadingGreeting
expr_stmt|;
block|}
if|if
condition|(
name|state
operator|==
name|ReadingGreeting
condition|)
block|{
if|if
condition|(
operator|!
name|hasEnoughData
argument_list|()
condition|)
return|return;
name|buffer
operator|=
name|read
argument_list|(
name|numBytesForCurrentDataType
argument_list|)
expr_stmt|;
if|if
condition|(
name|buffer
operator|.
name|size
argument_list|()
operator|!=
name|numBytesForCurrentDataType
condition|)
block|{
name|abort
argument_list|()
expr_stmt|;
return|return;
block|}
name|username
operator|=
name|QString
argument_list|(
name|buffer
argument_list|)
operator|+
literal|'@'
operator|+
name|peerAddress
argument_list|()
operator|.
name|toString
argument_list|()
operator|+
literal|':'
operator|+
name|QString
operator|::
name|number
argument_list|(
name|peerPort
argument_list|()
argument_list|)
expr_stmt|;
name|currentDataType
operator|=
name|Undefined
expr_stmt|;
name|numBytesForCurrentDataType
operator|=
literal|0
expr_stmt|;
name|buffer
operator|.
name|clear
argument_list|()
expr_stmt|;
if|if
condition|(
operator|!
name|isValid
argument_list|()
condition|)
block|{
name|abort
argument_list|()
expr_stmt|;
return|return;
block|}
if|if
condition|(
operator|!
name|isGreetingMessageSent
condition|)
name|sendGreetingMessage
argument_list|()
expr_stmt|;
name|pingTimer
operator|.
name|start
argument_list|()
expr_stmt|;
name|pongTime
operator|.
name|start
argument_list|()
expr_stmt|;
name|state
operator|=
name|ReadyForUse
expr_stmt|;
emit|emit
name|readyForUse
argument_list|()
emit|;
block|}
do|do
block|{
if|if
condition|(
name|currentDataType
operator|==
name|Undefined
condition|)
block|{
if|if
condition|(
operator|!
name|readProtocolHeader
argument_list|()
condition|)
return|return;
block|}
if|if
condition|(
operator|!
name|hasEnoughData
argument_list|()
condition|)
return|return;
name|processData
argument_list|()
expr_stmt|;
block|}
do|while
condition|(
name|bytesAvailable
argument_list|()
operator|>
literal|0
condition|)
do|;
block|}
end_function
begin_function
DECL|function|sendPing
name|void
name|Connection
operator|::
name|sendPing
parameter_list|()
block|{
if|if
condition|(
name|pongTime
operator|.
name|elapsed
argument_list|()
operator|>
name|PongTimeout
condition|)
block|{
name|abort
argument_list|()
expr_stmt|;
return|return;
block|}
name|write
argument_list|(
literal|"PING 1 p"
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|sendGreetingMessage
name|void
name|Connection
operator|::
name|sendGreetingMessage
parameter_list|()
block|{
name|QByteArray
name|greeting
init|=
name|greetingMessage
operator|.
name|toUtf8
argument_list|()
decl_stmt|;
name|QByteArray
name|data
init|=
literal|"GREETING "
operator|+
name|QByteArray
operator|::
name|number
argument_list|(
name|greeting
operator|.
name|size
argument_list|()
argument_list|)
operator|+
literal|' '
operator|+
name|greeting
decl_stmt|;
if|if
condition|(
name|write
argument_list|(
name|data
argument_list|)
operator|==
name|data
operator|.
name|size
argument_list|()
condition|)
name|isGreetingMessageSent
operator|=
literal|true
expr_stmt|;
block|}
end_function
begin_function
DECL|function|readDataIntoBuffer
name|int
name|Connection
operator|::
name|readDataIntoBuffer
parameter_list|(
name|int
name|maxSize
parameter_list|)
block|{
if|if
condition|(
name|maxSize
operator|>
name|MaxBufferSize
condition|)
return|return
literal|0
return|;
name|int
name|numBytesBeforeRead
init|=
name|buffer
operator|.
name|size
argument_list|()
decl_stmt|;
if|if
condition|(
name|numBytesBeforeRead
operator|==
name|MaxBufferSize
condition|)
block|{
name|abort
argument_list|()
expr_stmt|;
return|return
literal|0
return|;
block|}
while|while
condition|(
name|bytesAvailable
argument_list|()
operator|>
literal|0
operator|&&
name|buffer
operator|.
name|size
argument_list|()
operator|<
name|maxSize
condition|)
block|{
name|buffer
operator|.
name|append
argument_list|(
name|read
argument_list|(
literal|1
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|buffer
operator|.
name|endsWith
argument_list|(
name|SeparatorToken
argument_list|)
condition|)
break|break;
block|}
return|return
name|buffer
operator|.
name|size
argument_list|()
operator|-
name|numBytesBeforeRead
return|;
block|}
end_function
begin_function
DECL|function|dataLengthForCurrentDataType
name|int
name|Connection
operator|::
name|dataLengthForCurrentDataType
parameter_list|()
block|{
if|if
condition|(
name|bytesAvailable
argument_list|()
operator|<=
literal|0
operator|||
name|readDataIntoBuffer
argument_list|()
operator|<=
literal|0
operator|||
operator|!
name|buffer
operator|.
name|endsWith
argument_list|(
name|SeparatorToken
argument_list|)
condition|)
return|return
literal|0
return|;
name|buffer
operator|.
name|chop
argument_list|(
literal|1
argument_list|)
expr_stmt|;
name|int
name|number
init|=
name|buffer
operator|.
name|toInt
argument_list|()
decl_stmt|;
name|buffer
operator|.
name|clear
argument_list|()
expr_stmt|;
return|return
name|number
return|;
block|}
end_function
begin_function
DECL|function|readProtocolHeader
name|bool
name|Connection
operator|::
name|readProtocolHeader
parameter_list|()
block|{
if|if
condition|(
name|transferTimerId
condition|)
block|{
name|killTimer
argument_list|(
name|transferTimerId
argument_list|)
expr_stmt|;
name|transferTimerId
operator|=
literal|0
expr_stmt|;
block|}
if|if
condition|(
name|readDataIntoBuffer
argument_list|()
operator|<=
literal|0
condition|)
block|{
name|transferTimerId
operator|=
name|startTimer
argument_list|(
name|TransferTimeout
argument_list|)
expr_stmt|;
return|return
literal|false
return|;
block|}
if|if
condition|(
name|buffer
operator|==
literal|"PING "
condition|)
block|{
name|currentDataType
operator|=
name|Ping
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|buffer
operator|==
literal|"PONG "
condition|)
block|{
name|currentDataType
operator|=
name|Pong
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|buffer
operator|==
literal|"MESSAGE "
condition|)
block|{
name|currentDataType
operator|=
name|PlainText
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|buffer
operator|==
literal|"GREETING "
condition|)
block|{
name|currentDataType
operator|=
name|Greeting
expr_stmt|;
block|}
else|else
block|{
name|currentDataType
operator|=
name|Undefined
expr_stmt|;
name|abort
argument_list|()
expr_stmt|;
return|return
literal|false
return|;
block|}
name|buffer
operator|.
name|clear
argument_list|()
expr_stmt|;
name|numBytesForCurrentDataType
operator|=
name|dataLengthForCurrentDataType
argument_list|()
expr_stmt|;
return|return
literal|true
return|;
block|}
end_function
begin_function
DECL|function|hasEnoughData
name|bool
name|Connection
operator|::
name|hasEnoughData
parameter_list|()
block|{
if|if
condition|(
name|transferTimerId
condition|)
block|{
name|QObject
operator|::
name|killTimer
argument_list|(
name|transferTimerId
argument_list|)
expr_stmt|;
name|transferTimerId
operator|=
literal|0
expr_stmt|;
block|}
if|if
condition|(
name|numBytesForCurrentDataType
operator|<=
literal|0
condition|)
name|numBytesForCurrentDataType
operator|=
name|dataLengthForCurrentDataType
argument_list|()
expr_stmt|;
if|if
condition|(
name|bytesAvailable
argument_list|()
operator|<
name|numBytesForCurrentDataType
operator|||
name|numBytesForCurrentDataType
operator|<=
literal|0
condition|)
block|{
name|transferTimerId
operator|=
name|startTimer
argument_list|(
name|TransferTimeout
argument_list|)
expr_stmt|;
return|return
literal|false
return|;
block|}
return|return
literal|true
return|;
block|}
end_function
begin_function
DECL|function|processData
name|void
name|Connection
operator|::
name|processData
parameter_list|()
block|{
name|buffer
operator|=
name|read
argument_list|(
name|numBytesForCurrentDataType
argument_list|)
expr_stmt|;
if|if
condition|(
name|buffer
operator|.
name|size
argument_list|()
operator|!=
name|numBytesForCurrentDataType
condition|)
block|{
name|abort
argument_list|()
expr_stmt|;
return|return;
block|}
switch|switch
condition|(
name|currentDataType
condition|)
block|{
case|case
name|PlainText
case|:
emit|emit
name|newMessage
argument_list|(
name|username
argument_list|,
name|QString
operator|::
name|fromUtf8
argument_list|(
name|buffer
argument_list|)
argument_list|)
emit|;
break|break;
case|case
name|Ping
case|:
name|write
argument_list|(
literal|"PONG 1 p"
argument_list|)
expr_stmt|;
break|break;
case|case
name|Pong
case|:
name|pongTime
operator|.
name|restart
argument_list|()
expr_stmt|;
break|break;
default|default:
break|break;
block|}
name|currentDataType
operator|=
name|Undefined
expr_stmt|;
name|numBytesForCurrentDataType
operator|=
literal|0
expr_stmt|;
name|buffer
operator|.
name|clear
argument_list|()
expr_stmt|;
block|}
end_function
end_unit
