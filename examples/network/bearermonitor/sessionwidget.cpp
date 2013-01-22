begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of Digia Plc and its Subsidiary(-ies) nor the names **     of its contributors may be used to endorse or promote products derived **     from this software without specific prior written permission. ** ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"sessionwidget.h"
end_include
begin_include
include|#
directive|include
file|"qnetworkconfigmanager.h"
end_include
begin_constructor
DECL|function|SessionWidget
name|SessionWidget
operator|::
name|SessionWidget
parameter_list|(
specifier|const
name|QNetworkConfiguration
modifier|&
name|config
parameter_list|,
name|QWidget
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QWidget
argument_list|(
name|parent
argument_list|)
member_init_list|,
name|statsTimer
argument_list|(
operator|-
literal|1
argument_list|)
block|{
name|setupUi
argument_list|(
name|this
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|QT_NO_NETWORKINTERFACE
name|interfaceName
operator|->
name|setVisible
argument_list|(
literal|false
argument_list|)
expr_stmt|;
name|interfaceNameLabel
operator|->
name|setVisible
argument_list|(
literal|false
argument_list|)
expr_stmt|;
name|interfaceGuid
operator|->
name|setVisible
argument_list|(
literal|false
argument_list|)
expr_stmt|;
name|interfaceGuidLabel
operator|->
name|setVisible
argument_list|(
literal|false
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|session
operator|=
operator|new
name|QNetworkSession
argument_list|(
name|config
argument_list|,
name|this
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|session
argument_list|,
name|SIGNAL
argument_list|(
name|stateChanged
argument_list|(
name|QNetworkSession
operator|::
name|State
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|updateSession
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|session
argument_list|,
name|SIGNAL
argument_list|(
name|error
argument_list|(
name|QNetworkSession
operator|::
name|SessionError
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|updateSessionError
argument_list|(
name|QNetworkSession
operator|::
name|SessionError
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|updateSession
argument_list|()
expr_stmt|;
name|sessionId
operator|->
name|setText
argument_list|(
name|QString
argument_list|(
literal|"0x%1"
argument_list|)
operator|.
name|arg
argument_list|(
name|qulonglong
argument_list|(
name|session
argument_list|)
argument_list|,
literal|8
argument_list|,
literal|16
argument_list|,
name|QChar
argument_list|(
literal|'0'
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|configuration
operator|->
name|setText
argument_list|(
name|session
operator|->
name|configuration
argument_list|()
operator|.
name|name
argument_list|()
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|openSessionButton
argument_list|,
name|SIGNAL
argument_list|(
name|clicked
argument_list|()
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|openSession
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|openSyncSessionButton
argument_list|,
name|SIGNAL
argument_list|(
name|clicked
argument_list|()
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|openSyncSession
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|closeSessionButton
argument_list|,
name|SIGNAL
argument_list|(
name|clicked
argument_list|()
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|closeSession
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|stopSessionButton
argument_list|,
name|SIGNAL
argument_list|(
name|clicked
argument_list|()
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|stopSession
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|MAEMO_UI
name|connect
argument_list|(
name|deleteSessionButton
argument_list|,
name|SIGNAL
argument_list|(
name|clicked
argument_list|()
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|deleteSession
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
end_constructor
begin_destructor
DECL|function|~SessionWidget
name|SessionWidget
operator|::
name|~
name|SessionWidget
parameter_list|()
block|{
operator|delete
name|session
expr_stmt|;
block|}
end_destructor
begin_function
DECL|function|timerEvent
name|void
name|SessionWidget
operator|::
name|timerEvent
parameter_list|(
name|QTimerEvent
modifier|*
name|e
parameter_list|)
block|{
if|if
condition|(
name|e
operator|->
name|timerId
argument_list|()
operator|==
name|statsTimer
condition|)
block|{
name|rxData
operator|->
name|setText
argument_list|(
name|QString
operator|::
name|number
argument_list|(
name|session
operator|->
name|bytesReceived
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|txData
operator|->
name|setText
argument_list|(
name|QString
operator|::
name|number
argument_list|(
name|session
operator|->
name|bytesWritten
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|activeTime
operator|->
name|setText
argument_list|(
name|QString
operator|::
name|number
argument_list|(
name|session
operator|->
name|activeTime
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_ifdef
ifdef|#
directive|ifdef
name|MAEMO_UI
end_ifdef
begin_function
DECL|function|deleteSession
name|void
name|SessionWidget
operator|::
name|deleteSession
parameter_list|()
block|{
operator|delete
name|this
expr_stmt|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_function
DECL|function|updateSession
name|void
name|SessionWidget
operator|::
name|updateSession
parameter_list|()
block|{
name|updateSessionState
argument_list|(
name|session
operator|->
name|state
argument_list|()
argument_list|)
expr_stmt|;
if|if
condition|(
name|session
operator|->
name|state
argument_list|()
operator|==
name|QNetworkSession
operator|::
name|Connected
condition|)
name|statsTimer
operator|=
name|startTimer
argument_list|(
literal|1000
argument_list|)
expr_stmt|;
elseif|else
if|if
condition|(
name|statsTimer
operator|!=
operator|-
literal|1
condition|)
name|killTimer
argument_list|(
name|statsTimer
argument_list|)
expr_stmt|;
if|if
condition|(
name|session
operator|->
name|configuration
argument_list|()
operator|.
name|type
argument_list|()
operator|==
name|QNetworkConfiguration
operator|::
name|InternetAccessPoint
condition|)
name|bearer
operator|->
name|setText
argument_list|(
name|session
operator|->
name|configuration
argument_list|()
operator|.
name|bearerTypeName
argument_list|()
argument_list|)
expr_stmt|;
else|else
block|{
name|QNetworkConfigurationManager
name|mgr
decl_stmt|;
name|QNetworkConfiguration
name|c
init|=
name|mgr
operator|.
name|configurationFromIdentifier
argument_list|(
name|session
operator|->
name|sessionProperty
argument_list|(
literal|"ActiveConfiguration"
argument_list|)
operator|.
name|toString
argument_list|()
argument_list|)
decl_stmt|;
name|bearer
operator|->
name|setText
argument_list|(
name|c
operator|.
name|bearerTypeName
argument_list|()
argument_list|)
expr_stmt|;
block|}
ifndef|#
directive|ifndef
name|QT_NO_NETWORKINTERFACE
name|interfaceName
operator|->
name|setText
argument_list|(
name|session
operator|->
name|interface
argument_list|()
operator|.
name|humanReadableName
argument_list|()
argument_list|)
expr_stmt|;
name|interfaceGuid
operator|->
name|setText
argument_list|(
name|session
operator|->
name|interface
argument_list|()
operator|.
name|name
argument_list|()
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
end_function
begin_function
DECL|function|openSession
name|void
name|SessionWidget
operator|::
name|openSession
parameter_list|()
block|{
name|clearError
argument_list|()
expr_stmt|;
name|session
operator|->
name|open
argument_list|()
expr_stmt|;
name|updateSession
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|openSyncSession
name|void
name|SessionWidget
operator|::
name|openSyncSession
parameter_list|()
block|{
name|clearError
argument_list|()
expr_stmt|;
name|session
operator|->
name|open
argument_list|()
expr_stmt|;
name|session
operator|->
name|waitForOpened
argument_list|()
expr_stmt|;
name|updateSession
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|closeSession
name|void
name|SessionWidget
operator|::
name|closeSession
parameter_list|()
block|{
name|clearError
argument_list|()
expr_stmt|;
name|session
operator|->
name|close
argument_list|()
expr_stmt|;
name|updateSession
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|stopSession
name|void
name|SessionWidget
operator|::
name|stopSession
parameter_list|()
block|{
name|clearError
argument_list|()
expr_stmt|;
name|session
operator|->
name|stop
argument_list|()
expr_stmt|;
name|updateSession
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|updateSessionState
name|void
name|SessionWidget
operator|::
name|updateSessionState
parameter_list|(
name|QNetworkSession
operator|::
name|State
name|state
parameter_list|)
block|{
name|QString
name|s
init|=
name|tr
argument_list|(
literal|"%1 (%2)"
argument_list|)
decl_stmt|;
switch|switch
condition|(
name|state
condition|)
block|{
case|case
name|QNetworkSession
operator|::
name|Invalid
case|:
name|s
operator|=
name|s
operator|.
name|arg
argument_list|(
name|tr
argument_list|(
literal|"Invalid"
argument_list|)
argument_list|)
expr_stmt|;
break|break;
case|case
name|QNetworkSession
operator|::
name|NotAvailable
case|:
name|s
operator|=
name|s
operator|.
name|arg
argument_list|(
name|tr
argument_list|(
literal|"Not Available"
argument_list|)
argument_list|)
expr_stmt|;
break|break;
case|case
name|QNetworkSession
operator|::
name|Connecting
case|:
name|s
operator|=
name|s
operator|.
name|arg
argument_list|(
name|tr
argument_list|(
literal|"Connecting"
argument_list|)
argument_list|)
expr_stmt|;
break|break;
case|case
name|QNetworkSession
operator|::
name|Connected
case|:
name|s
operator|=
name|s
operator|.
name|arg
argument_list|(
name|tr
argument_list|(
literal|"Connected"
argument_list|)
argument_list|)
expr_stmt|;
break|break;
case|case
name|QNetworkSession
operator|::
name|Closing
case|:
name|s
operator|=
name|s
operator|.
name|arg
argument_list|(
name|tr
argument_list|(
literal|"Closing"
argument_list|)
argument_list|)
expr_stmt|;
break|break;
case|case
name|QNetworkSession
operator|::
name|Disconnected
case|:
name|s
operator|=
name|s
operator|.
name|arg
argument_list|(
name|tr
argument_list|(
literal|"Disconnected"
argument_list|)
argument_list|)
expr_stmt|;
break|break;
case|case
name|QNetworkSession
operator|::
name|Roaming
case|:
name|s
operator|=
name|s
operator|.
name|arg
argument_list|(
name|tr
argument_list|(
literal|"Roaming"
argument_list|)
argument_list|)
expr_stmt|;
break|break;
default|default:
name|s
operator|=
name|s
operator|.
name|arg
argument_list|(
name|tr
argument_list|(
literal|"Unknown"
argument_list|)
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|session
operator|->
name|isOpen
argument_list|()
condition|)
name|s
operator|=
name|s
operator|.
name|arg
argument_list|(
name|tr
argument_list|(
literal|"Open"
argument_list|)
argument_list|)
expr_stmt|;
else|else
name|s
operator|=
name|s
operator|.
name|arg
argument_list|(
name|tr
argument_list|(
literal|"Closed"
argument_list|)
argument_list|)
expr_stmt|;
name|sessionState
operator|->
name|setText
argument_list|(
name|s
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|updateSessionError
name|void
name|SessionWidget
operator|::
name|updateSessionError
parameter_list|(
name|QNetworkSession
operator|::
name|SessionError
name|error
parameter_list|)
block|{
name|lastError
operator|->
name|setText
argument_list|(
name|QString
operator|::
name|number
argument_list|(
name|error
argument_list|)
argument_list|)
expr_stmt|;
name|errorString
operator|->
name|setText
argument_list|(
name|session
operator|->
name|errorString
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|clearError
name|void
name|SessionWidget
operator|::
name|clearError
parameter_list|()
block|{
name|lastError
operator|->
name|clear
argument_list|()
expr_stmt|;
name|errorString
operator|->
name|clear
argument_list|()
expr_stmt|;
block|}
end_function
end_unit
