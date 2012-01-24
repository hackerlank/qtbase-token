begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the documentation of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of Nokia Corporation and its Subsidiary(-ies) nor **     the names of its contributors may be used to endorse or promote **     products derived from this software without specific prior written **     permission. ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_comment
comment|//! [0]
end_comment
begin_function
DECL|function|initSocket
name|void
name|Server
operator|::
name|initSocket
parameter_list|()
block|{
name|udpSocket
operator|=
operator|new
name|QUdpSocket
argument_list|(
name|this
argument_list|)
expr_stmt|;
name|udpSocket
operator|->
name|bind
argument_list|(
name|QHostAddress
operator|::
name|LocalHost
argument_list|,
literal|7755
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|udpSocket
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
name|readPendingDatagrams
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|readPendingDatagrams
name|void
name|Server
operator|::
name|readPendingDatagrams
parameter_list|()
block|{
while|while
condition|(
name|udpSocket
operator|->
name|hasPendingDatagrams
argument_list|()
condition|)
block|{
name|QByteArray
name|datagram
decl_stmt|;
name|datagram
operator|.
name|resize
argument_list|(
name|udpSocket
operator|->
name|pendingDatagramSize
argument_list|()
argument_list|)
expr_stmt|;
name|QHostAddress
name|sender
decl_stmt|;
name|quint16
name|senderPort
decl_stmt|;
name|udpSocket
operator|->
name|readDatagram
argument_list|(
name|datagram
operator|.
name|data
argument_list|()
argument_list|,
name|datagram
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
name|processTheDatagram
argument_list|(
name|datagram
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_comment
comment|//! [0]
end_comment
end_unit
