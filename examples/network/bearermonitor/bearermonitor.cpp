begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of Digia Plc and its Subsidiary(-ies) nor the names **     of its contributors may be used to endorse or promote products derived **     from this software without specific prior written permission. ** ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"bearermonitor.h"
end_include
begin_include
include|#
directive|include
file|"sessionwidget.h"
end_include
begin_include
include|#
directive|include
file|<QtCore/QDebug>
end_include
begin_ifdef
ifdef|#
directive|ifdef
name|Q_OS_WIN
end_ifdef
begin_include
include|#
directive|include
file|<winsock2.h>
end_include
begin_undef
DECL|macro|interface
undef|#
directive|undef
name|interface
end_undef
begin_ifndef
ifndef|#
directive|ifndef
name|NS_NLA
end_ifndef
begin_define
DECL|macro|NS_NLA
define|#
directive|define
name|NS_NLA
value|15
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_endif
endif|#
directive|endif
end_endif
begin_constructor
DECL|function|BearerMonitor
name|BearerMonitor
operator|::
name|BearerMonitor
parameter_list|(
name|QWidget
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QWidget
argument_list|(
name|parent
argument_list|)
block|{
name|setupUi
argument_list|(
name|this
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|MAEMO_UI
name|newSessionButton
operator|->
name|hide
argument_list|()
expr_stmt|;
name|deleteSessionButton
operator|->
name|hide
argument_list|()
expr_stmt|;
else|#
directive|else
operator|delete
name|tabWidget
operator|->
name|currentWidget
argument_list|()
expr_stmt|;
name|sessionGroup
operator|->
name|hide
argument_list|()
expr_stmt|;
endif|#
directive|endif
name|updateConfigurations
argument_list|()
expr_stmt|;
name|onlineStateChanged
argument_list|(
operator|!
name|manager
operator|.
name|allConfigurations
argument_list|(
name|QNetworkConfiguration
operator|::
name|Active
argument_list|)
operator|.
name|isEmpty
argument_list|()
argument_list|)
expr_stmt|;
name|QNetworkConfiguration
name|defaultConfiguration
init|=
name|manager
operator|.
name|defaultConfiguration
argument_list|()
decl_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|treeWidget
operator|->
name|topLevelItemCount
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
name|QTreeWidgetItem
modifier|*
name|item
init|=
name|treeWidget
operator|->
name|topLevelItem
argument_list|(
name|i
argument_list|)
decl_stmt|;
if|if
condition|(
name|item
operator|->
name|data
argument_list|(
literal|0
argument_list|,
name|Qt
operator|::
name|UserRole
argument_list|)
operator|.
name|toString
argument_list|()
operator|==
name|defaultConfiguration
operator|.
name|identifier
argument_list|()
condition|)
block|{
name|treeWidget
operator|->
name|setCurrentItem
argument_list|(
name|item
argument_list|)
expr_stmt|;
name|showConfigurationFor
argument_list|(
name|item
argument_list|)
expr_stmt|;
break|break;
block|}
block|}
name|connect
argument_list|(
operator|&
name|manager
argument_list|,
name|SIGNAL
argument_list|(
name|onlineStateChanged
argument_list|(
name|bool
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|onlineStateChanged
argument_list|(
name|bool
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
operator|&
name|manager
argument_list|,
name|SIGNAL
argument_list|(
name|configurationAdded
argument_list|(
specifier|const
name|QNetworkConfiguration
operator|&
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|configurationAdded
argument_list|(
specifier|const
name|QNetworkConfiguration
operator|&
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
operator|&
name|manager
argument_list|,
name|SIGNAL
argument_list|(
name|configurationRemoved
argument_list|(
specifier|const
name|QNetworkConfiguration
operator|&
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|configurationRemoved
argument_list|(
specifier|const
name|QNetworkConfiguration
operator|&
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
operator|&
name|manager
argument_list|,
name|SIGNAL
argument_list|(
name|configurationChanged
argument_list|(
specifier|const
name|QNetworkConfiguration
operator|&
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|configurationChanged
argument_list|(
specifier|const
name|QNetworkConfiguration
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
operator|&
name|manager
argument_list|,
name|SIGNAL
argument_list|(
name|updateCompleted
argument_list|()
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|updateConfigurations
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_WIN
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|Q_OS_WINRT
argument_list|)
name|connect
argument_list|(
name|registerButton
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
name|registerNetwork
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|unregisterButton
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
name|unregisterNetwork
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
else|#
directive|else
comment|// Q_OS_WIN&& !Q_OS_WINRT
name|nlaGroup
operator|->
name|hide
argument_list|()
expr_stmt|;
endif|#
directive|endif
name|connect
argument_list|(
name|treeWidget
argument_list|,
name|SIGNAL
argument_list|(
name|itemActivated
argument_list|(
name|QTreeWidgetItem
operator|*
argument_list|,
name|int
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|createSessionFor
argument_list|(
name|QTreeWidgetItem
operator|*
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|treeWidget
argument_list|,
name|SIGNAL
argument_list|(
name|currentItemChanged
argument_list|(
name|QTreeWidgetItem
operator|*
argument_list|,
name|QTreeWidgetItem
operator|*
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|showConfigurationFor
argument_list|(
name|QTreeWidgetItem
operator|*
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|newSessionButton
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
name|createNewSession
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
ifndef|#
directive|ifndef
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
name|connect
argument_list|(
name|scanButton
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
name|performScan
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
comment|// Just in case update all configurations so that all
comment|// configurations are up to date.
name|manager
operator|.
name|updateConfigurations
argument_list|()
expr_stmt|;
block|}
end_constructor
begin_destructor
DECL|function|~BearerMonitor
name|BearerMonitor
operator|::
name|~
name|BearerMonitor
parameter_list|()
block|{ }
end_destructor
begin_function
DECL|function|updateItem
specifier|static
name|void
name|updateItem
parameter_list|(
name|QTreeWidgetItem
modifier|*
name|item
parameter_list|,
specifier|const
name|QNetworkConfiguration
modifier|&
name|config
parameter_list|)
block|{
name|item
operator|->
name|setText
argument_list|(
literal|0
argument_list|,
name|config
operator|.
name|name
argument_list|()
argument_list|)
expr_stmt|;
name|item
operator|->
name|setData
argument_list|(
literal|0
argument_list|,
name|Qt
operator|::
name|UserRole
argument_list|,
name|config
operator|.
name|identifier
argument_list|()
argument_list|)
expr_stmt|;
name|QFont
name|font
init|=
name|item
operator|->
name|font
argument_list|(
literal|1
argument_list|)
decl_stmt|;
name|font
operator|.
name|setBold
argument_list|(
operator|(
name|config
operator|.
name|state
argument_list|()
operator|&
name|QNetworkConfiguration
operator|::
name|Active
operator|)
operator|==
name|QNetworkConfiguration
operator|::
name|Active
argument_list|)
expr_stmt|;
name|item
operator|->
name|setFont
argument_list|(
literal|0
argument_list|,
name|font
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|configurationAdded
name|void
name|BearerMonitor
operator|::
name|configurationAdded
parameter_list|(
specifier|const
name|QNetworkConfiguration
modifier|&
name|config
parameter_list|,
name|QTreeWidgetItem
modifier|*
name|parent
parameter_list|)
block|{
name|QTreeWidgetItem
modifier|*
name|item
init|=
operator|new
name|QTreeWidgetItem
decl_stmt|;
name|updateItem
argument_list|(
name|item
argument_list|,
name|config
argument_list|)
expr_stmt|;
if|if
condition|(
name|parent
condition|)
name|parent
operator|->
name|addChild
argument_list|(
name|item
argument_list|)
expr_stmt|;
else|else
name|treeWidget
operator|->
name|addTopLevelItem
argument_list|(
name|item
argument_list|)
expr_stmt|;
if|if
condition|(
name|config
operator|.
name|type
argument_list|()
operator|==
name|QNetworkConfiguration
operator|::
name|ServiceNetwork
condition|)
block|{
foreach|foreach
control|(
specifier|const
name|QNetworkConfiguration
modifier|&
name|child
decl|,
name|config
operator|.
name|children
argument_list|()
control|)
name|configurationAdded
argument_list|(
name|child
argument_list|,
name|item
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|configurationRemoved
name|void
name|BearerMonitor
operator|::
name|configurationRemoved
parameter_list|(
specifier|const
name|QNetworkConfiguration
modifier|&
name|config
parameter_list|)
block|{
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|treeWidget
operator|->
name|topLevelItemCount
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
name|QTreeWidgetItem
modifier|*
name|item
init|=
name|treeWidget
operator|->
name|topLevelItem
argument_list|(
name|i
argument_list|)
decl_stmt|;
if|if
condition|(
name|item
operator|->
name|data
argument_list|(
literal|0
argument_list|,
name|Qt
operator|::
name|UserRole
argument_list|)
operator|.
name|toString
argument_list|()
operator|==
name|config
operator|.
name|identifier
argument_list|()
condition|)
block|{
operator|delete
name|item
expr_stmt|;
break|break;
block|}
block|}
block|}
end_function
begin_function
DECL|function|configurationChanged
name|void
name|BearerMonitor
operator|::
name|configurationChanged
parameter_list|(
specifier|const
name|QNetworkConfiguration
modifier|&
name|config
parameter_list|)
block|{
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|treeWidget
operator|->
name|topLevelItemCount
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
name|QTreeWidgetItem
modifier|*
name|item
init|=
name|treeWidget
operator|->
name|topLevelItem
argument_list|(
name|i
argument_list|)
decl_stmt|;
if|if
condition|(
name|item
operator|->
name|data
argument_list|(
literal|0
argument_list|,
name|Qt
operator|::
name|UserRole
argument_list|)
operator|.
name|toString
argument_list|()
operator|==
name|config
operator|.
name|identifier
argument_list|()
condition|)
block|{
name|updateItem
argument_list|(
name|item
argument_list|,
name|config
argument_list|)
expr_stmt|;
if|if
condition|(
name|config
operator|.
name|type
argument_list|()
operator|==
name|QNetworkConfiguration
operator|::
name|ServiceNetwork
condition|)
name|updateSnapConfiguration
argument_list|(
name|item
argument_list|,
name|config
argument_list|)
expr_stmt|;
if|if
condition|(
name|item
operator|==
name|treeWidget
operator|->
name|currentItem
argument_list|()
condition|)
name|showConfigurationFor
argument_list|(
name|item
argument_list|)
expr_stmt|;
break|break;
block|}
block|}
block|}
end_function
begin_function
DECL|function|updateSnapConfiguration
name|void
name|BearerMonitor
operator|::
name|updateSnapConfiguration
parameter_list|(
name|QTreeWidgetItem
modifier|*
name|parent
parameter_list|,
specifier|const
name|QNetworkConfiguration
modifier|&
name|snap
parameter_list|)
block|{
name|QMap
argument_list|<
name|QString
argument_list|,
name|QTreeWidgetItem
modifier|*
argument_list|>
name|itemMap
decl_stmt|;
foreach|foreach
control|(
name|QTreeWidgetItem
modifier|*
name|item
decl|,
name|parent
operator|->
name|takeChildren
argument_list|()
control|)
name|itemMap
operator|.
name|insert
argument_list|(
name|item
operator|->
name|data
argument_list|(
literal|0
argument_list|,
name|Qt
operator|::
name|UserRole
argument_list|)
operator|.
name|toString
argument_list|()
argument_list|,
name|item
argument_list|)
expr_stmt|;
name|QList
argument_list|<
name|QNetworkConfiguration
argument_list|>
name|allConfigurations
init|=
name|snap
operator|.
name|children
argument_list|()
decl_stmt|;
while|while
condition|(
operator|!
name|allConfigurations
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|QNetworkConfiguration
name|config
init|=
name|allConfigurations
operator|.
name|takeFirst
argument_list|()
decl_stmt|;
name|QTreeWidgetItem
modifier|*
name|item
init|=
name|itemMap
operator|.
name|take
argument_list|(
name|config
operator|.
name|identifier
argument_list|()
argument_list|)
decl_stmt|;
if|if
condition|(
name|item
condition|)
block|{
name|updateItem
argument_list|(
name|item
argument_list|,
name|config
argument_list|)
expr_stmt|;
name|parent
operator|->
name|addChild
argument_list|(
name|item
argument_list|)
expr_stmt|;
if|if
condition|(
name|config
operator|.
name|type
argument_list|()
operator|==
name|QNetworkConfiguration
operator|::
name|ServiceNetwork
condition|)
name|updateSnapConfiguration
argument_list|(
name|item
argument_list|,
name|config
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|configurationAdded
argument_list|(
name|config
argument_list|,
name|parent
argument_list|)
expr_stmt|;
block|}
block|}
name|qDeleteAll
argument_list|(
name|itemMap
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|updateConfigurations
name|void
name|BearerMonitor
operator|::
name|updateConfigurations
parameter_list|()
block|{
name|progressBar
operator|->
name|hide
argument_list|()
expr_stmt|;
name|scanButton
operator|->
name|show
argument_list|()
expr_stmt|;
comment|// Just in case update online state, on Symbian platform
comment|// WLAN scan needs to be triggered initially to have their true state.
name|onlineStateChanged
argument_list|(
name|manager
operator|.
name|isOnline
argument_list|()
argument_list|)
expr_stmt|;
name|QList
argument_list|<
name|QTreeWidgetItem
modifier|*
argument_list|>
name|items
init|=
name|treeWidget
operator|->
name|findItems
argument_list|(
name|QLatin1String
argument_list|(
literal|"*"
argument_list|)
argument_list|,
name|Qt
operator|::
name|MatchWildcard
argument_list|)
decl_stmt|;
name|QMap
argument_list|<
name|QString
argument_list|,
name|QTreeWidgetItem
modifier|*
argument_list|>
name|itemMap
decl_stmt|;
while|while
condition|(
operator|!
name|items
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|QTreeWidgetItem
modifier|*
name|item
init|=
name|items
operator|.
name|takeFirst
argument_list|()
decl_stmt|;
name|itemMap
operator|.
name|insert
argument_list|(
name|item
operator|->
name|data
argument_list|(
literal|0
argument_list|,
name|Qt
operator|::
name|UserRole
argument_list|)
operator|.
name|toString
argument_list|()
argument_list|,
name|item
argument_list|)
expr_stmt|;
block|}
name|QNetworkConfiguration
name|defaultConfiguration
init|=
name|manager
operator|.
name|defaultConfiguration
argument_list|()
decl_stmt|;
name|QTreeWidgetItem
modifier|*
name|defaultItem
init|=
name|itemMap
operator|.
name|take
argument_list|(
name|defaultConfiguration
operator|.
name|identifier
argument_list|()
argument_list|)
decl_stmt|;
if|if
condition|(
name|defaultItem
condition|)
block|{
name|updateItem
argument_list|(
name|defaultItem
argument_list|,
name|defaultConfiguration
argument_list|)
expr_stmt|;
if|if
condition|(
name|defaultConfiguration
operator|.
name|type
argument_list|()
operator|==
name|QNetworkConfiguration
operator|::
name|ServiceNetwork
condition|)
name|updateSnapConfiguration
argument_list|(
name|defaultItem
argument_list|,
name|defaultConfiguration
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|configurationAdded
argument_list|(
name|defaultConfiguration
argument_list|)
expr_stmt|;
block|}
name|QList
argument_list|<
name|QNetworkConfiguration
argument_list|>
name|allConfigurations
init|=
name|manager
operator|.
name|allConfigurations
argument_list|()
decl_stmt|;
while|while
condition|(
operator|!
name|allConfigurations
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|QNetworkConfiguration
name|config
init|=
name|allConfigurations
operator|.
name|takeFirst
argument_list|()
decl_stmt|;
if|if
condition|(
name|config
operator|.
name|identifier
argument_list|()
operator|==
name|defaultConfiguration
operator|.
name|identifier
argument_list|()
condition|)
continue|continue;
name|QTreeWidgetItem
modifier|*
name|item
init|=
name|itemMap
operator|.
name|take
argument_list|(
name|config
operator|.
name|identifier
argument_list|()
argument_list|)
decl_stmt|;
if|if
condition|(
name|item
condition|)
block|{
name|updateItem
argument_list|(
name|item
argument_list|,
name|config
argument_list|)
expr_stmt|;
if|if
condition|(
name|config
operator|.
name|type
argument_list|()
operator|==
name|QNetworkConfiguration
operator|::
name|ServiceNetwork
condition|)
name|updateSnapConfiguration
argument_list|(
name|item
argument_list|,
name|config
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|configurationAdded
argument_list|(
name|config
argument_list|)
expr_stmt|;
block|}
block|}
name|qDeleteAll
argument_list|(
name|itemMap
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|onlineStateChanged
name|void
name|BearerMonitor
operator|::
name|onlineStateChanged
parameter_list|(
name|bool
name|isOnline
parameter_list|)
block|{
if|if
condition|(
name|isOnline
condition|)
name|onlineState
operator|->
name|setText
argument_list|(
name|tr
argument_list|(
literal|"Online"
argument_list|)
argument_list|)
expr_stmt|;
else|else
name|onlineState
operator|->
name|setText
argument_list|(
name|tr
argument_list|(
literal|"Offline"
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_if
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_WIN
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|Q_OS_WINRT
argument_list|)
end_if
begin_function
DECL|function|registerNetwork
name|void
name|BearerMonitor
operator|::
name|registerNetwork
parameter_list|()
block|{
name|QTreeWidgetItem
modifier|*
name|item
init|=
name|treeWidget
operator|->
name|currentItem
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
name|item
condition|)
return|return;
name|QNetworkConfiguration
name|configuration
init|=
name|manager
operator|.
name|configurationFromIdentifier
argument_list|(
name|item
operator|->
name|data
argument_list|(
literal|0
argument_list|,
name|Qt
operator|::
name|UserRole
argument_list|)
operator|.
name|toString
argument_list|()
argument_list|)
decl_stmt|;
specifier|const
name|QString
name|name
init|=
name|configuration
operator|.
name|name
argument_list|()
decl_stmt|;
name|qDebug
argument_list|()
operator|<<
literal|"Registering"
operator|<<
name|name
operator|<<
literal|"with system"
expr_stmt|;
name|WSAQUERYSET
name|networkInfo
decl_stmt|;
name|memset
argument_list|(
operator|&
name|networkInfo
argument_list|,
literal|0
argument_list|,
sizeof|sizeof
argument_list|(
name|networkInfo
argument_list|)
argument_list|)
expr_stmt|;
name|networkInfo
operator|.
name|dwSize
operator|=
sizeof|sizeof
argument_list|(
name|networkInfo
argument_list|)
expr_stmt|;
name|networkInfo
operator|.
name|lpszServiceInstanceName
operator|=
operator|(
name|LPWSTR
operator|)
name|name
operator|.
name|utf16
argument_list|()
expr_stmt|;
name|networkInfo
operator|.
name|dwNameSpace
operator|=
name|NS_NLA
expr_stmt|;
if|if
condition|(
name|WSASetService
argument_list|(
operator|&
name|networkInfo
argument_list|,
name|RNRSERVICE_REGISTER
argument_list|,
literal|0
argument_list|)
operator|==
name|SOCKET_ERROR
condition|)
name|qDebug
argument_list|()
operator|<<
literal|"WSASetService(RNRSERVICE_REGISTER) returned"
operator|<<
name|WSAGetLastError
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|unregisterNetwork
name|void
name|BearerMonitor
operator|::
name|unregisterNetwork
parameter_list|()
block|{
name|QTreeWidgetItem
modifier|*
name|item
init|=
name|treeWidget
operator|->
name|currentItem
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
name|item
condition|)
return|return;
name|QNetworkConfiguration
name|configuration
init|=
name|manager
operator|.
name|configurationFromIdentifier
argument_list|(
name|item
operator|->
name|data
argument_list|(
literal|0
argument_list|,
name|Qt
operator|::
name|UserRole
argument_list|)
operator|.
name|toString
argument_list|()
argument_list|)
decl_stmt|;
specifier|const
name|QString
name|name
init|=
name|configuration
operator|.
name|name
argument_list|()
decl_stmt|;
name|qDebug
argument_list|()
operator|<<
literal|"Unregistering"
operator|<<
name|name
operator|<<
literal|"with system"
expr_stmt|;
name|WSAQUERYSET
name|networkInfo
decl_stmt|;
name|memset
argument_list|(
operator|&
name|networkInfo
argument_list|,
literal|0
argument_list|,
sizeof|sizeof
argument_list|(
name|networkInfo
argument_list|)
argument_list|)
expr_stmt|;
name|networkInfo
operator|.
name|dwSize
operator|=
sizeof|sizeof
argument_list|(
name|networkInfo
argument_list|)
expr_stmt|;
name|networkInfo
operator|.
name|lpszServiceInstanceName
operator|=
operator|(
name|LPWSTR
operator|)
name|name
operator|.
name|utf16
argument_list|()
expr_stmt|;
name|networkInfo
operator|.
name|dwNameSpace
operator|=
name|NS_NLA
expr_stmt|;
if|if
condition|(
name|WSASetService
argument_list|(
operator|&
name|networkInfo
argument_list|,
name|RNRSERVICE_DELETE
argument_list|,
literal|0
argument_list|)
operator|==
name|SOCKET_ERROR
condition|)
name|qDebug
argument_list|()
operator|<<
literal|"WSASetService(RNRSERVICE_DELETE) returned"
operator|<<
name|WSAGetLastError
argument_list|()
expr_stmt|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// Q_OS_WIN&& !Q_OS_WINRT
end_comment
begin_function
DECL|function|showConfigurationFor
name|void
name|BearerMonitor
operator|::
name|showConfigurationFor
parameter_list|(
name|QTreeWidgetItem
modifier|*
name|item
parameter_list|)
block|{
name|QString
name|identifier
decl_stmt|;
if|if
condition|(
name|item
condition|)
name|identifier
operator|=
name|item
operator|->
name|data
argument_list|(
literal|0
argument_list|,
name|Qt
operator|::
name|UserRole
argument_list|)
operator|.
name|toString
argument_list|()
expr_stmt|;
name|QNetworkConfiguration
name|conf
init|=
name|manager
operator|.
name|configurationFromIdentifier
argument_list|(
name|identifier
argument_list|)
decl_stmt|;
switch|switch
condition|(
name|conf
operator|.
name|state
argument_list|()
condition|)
block|{
case|case
name|QNetworkConfiguration
operator|::
name|Active
case|:
name|configurationState
operator|->
name|setText
argument_list|(
name|tr
argument_list|(
literal|"Active"
argument_list|)
argument_list|)
expr_stmt|;
break|break;
case|case
name|QNetworkConfiguration
operator|::
name|Discovered
case|:
name|configurationState
operator|->
name|setText
argument_list|(
name|tr
argument_list|(
literal|"Discovered"
argument_list|)
argument_list|)
expr_stmt|;
break|break;
case|case
name|QNetworkConfiguration
operator|::
name|Defined
case|:
name|configurationState
operator|->
name|setText
argument_list|(
name|tr
argument_list|(
literal|"Defined"
argument_list|)
argument_list|)
expr_stmt|;
break|break;
case|case
name|QNetworkConfiguration
operator|::
name|Undefined
case|:
name|configurationState
operator|->
name|setText
argument_list|(
name|tr
argument_list|(
literal|"Undefined"
argument_list|)
argument_list|)
expr_stmt|;
break|break;
default|default:
name|configurationState
operator|->
name|setText
argument_list|(
name|QString
argument_list|()
argument_list|)
expr_stmt|;
block|}
switch|switch
condition|(
name|conf
operator|.
name|type
argument_list|()
condition|)
block|{
case|case
name|QNetworkConfiguration
operator|::
name|InternetAccessPoint
case|:
name|configurationType
operator|->
name|setText
argument_list|(
name|tr
argument_list|(
literal|"Internet Access Point"
argument_list|)
argument_list|)
expr_stmt|;
break|break;
case|case
name|QNetworkConfiguration
operator|::
name|ServiceNetwork
case|:
name|configurationType
operator|->
name|setText
argument_list|(
name|tr
argument_list|(
literal|"Service Network"
argument_list|)
argument_list|)
expr_stmt|;
break|break;
case|case
name|QNetworkConfiguration
operator|::
name|UserChoice
case|:
name|configurationType
operator|->
name|setText
argument_list|(
name|tr
argument_list|(
literal|"User Choice"
argument_list|)
argument_list|)
expr_stmt|;
break|break;
case|case
name|QNetworkConfiguration
operator|::
name|Invalid
case|:
name|configurationType
operator|->
name|setText
argument_list|(
name|tr
argument_list|(
literal|"Invalid"
argument_list|)
argument_list|)
expr_stmt|;
break|break;
default|default:
name|configurationType
operator|->
name|setText
argument_list|(
name|QString
argument_list|()
argument_list|)
expr_stmt|;
block|}
switch|switch
condition|(
name|conf
operator|.
name|purpose
argument_list|()
condition|)
block|{
case|case
name|QNetworkConfiguration
operator|::
name|UnknownPurpose
case|:
name|configurationPurpose
operator|->
name|setText
argument_list|(
name|tr
argument_list|(
literal|"Unknown"
argument_list|)
argument_list|)
expr_stmt|;
break|break;
case|case
name|QNetworkConfiguration
operator|::
name|PublicPurpose
case|:
name|configurationPurpose
operator|->
name|setText
argument_list|(
name|tr
argument_list|(
literal|"Public"
argument_list|)
argument_list|)
expr_stmt|;
break|break;
case|case
name|QNetworkConfiguration
operator|::
name|PrivatePurpose
case|:
name|configurationPurpose
operator|->
name|setText
argument_list|(
name|tr
argument_list|(
literal|"Private"
argument_list|)
argument_list|)
expr_stmt|;
break|break;
case|case
name|QNetworkConfiguration
operator|::
name|ServiceSpecificPurpose
case|:
name|configurationPurpose
operator|->
name|setText
argument_list|(
name|tr
argument_list|(
literal|"Service Specific"
argument_list|)
argument_list|)
expr_stmt|;
break|break;
default|default:
name|configurationPurpose
operator|->
name|setText
argument_list|(
name|QString
argument_list|()
argument_list|)
expr_stmt|;
block|}
name|configurationIdentifier
operator|->
name|setText
argument_list|(
name|conf
operator|.
name|identifier
argument_list|()
argument_list|)
expr_stmt|;
name|configurationRoaming
operator|->
name|setText
argument_list|(
name|conf
operator|.
name|isRoamingAvailable
argument_list|()
condition|?
name|tr
argument_list|(
literal|"Available"
argument_list|)
else|:
name|tr
argument_list|(
literal|"Not available"
argument_list|)
argument_list|)
expr_stmt|;
name|configurationChildren
operator|->
name|setText
argument_list|(
name|QString
operator|::
name|number
argument_list|(
name|conf
operator|.
name|children
argument_list|()
operator|.
name|count
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|configurationName
operator|->
name|setText
argument_list|(
name|conf
operator|.
name|name
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|createSessionFor
name|void
name|BearerMonitor
operator|::
name|createSessionFor
parameter_list|(
name|QTreeWidgetItem
modifier|*
name|item
parameter_list|)
block|{
specifier|const
name|QString
name|identifier
init|=
name|item
operator|->
name|data
argument_list|(
literal|0
argument_list|,
name|Qt
operator|::
name|UserRole
argument_list|)
operator|.
name|toString
argument_list|()
decl_stmt|;
name|QNetworkConfiguration
name|conf
init|=
name|manager
operator|.
name|configurationFromIdentifier
argument_list|(
name|identifier
argument_list|)
decl_stmt|;
name|SessionWidget
modifier|*
name|session
init|=
operator|new
name|SessionWidget
argument_list|(
name|conf
argument_list|)
decl_stmt|;
name|tabWidget
operator|->
name|addTab
argument_list|(
name|session
argument_list|,
name|conf
operator|.
name|name
argument_list|()
argument_list|)
expr_stmt|;
ifndef|#
directive|ifndef
name|MAEMO_UI
name|sessionGroup
operator|->
name|show
argument_list|()
expr_stmt|;
endif|#
directive|endif
name|sessionWidgets
operator|.
name|append
argument_list|(
name|session
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|createNewSession
name|void
name|BearerMonitor
operator|::
name|createNewSession
parameter_list|()
block|{
name|QTreeWidgetItem
modifier|*
name|item
init|=
name|treeWidget
operator|->
name|currentItem
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
name|item
condition|)
return|return;
name|createSessionFor
argument_list|(
name|item
argument_list|)
expr_stmt|;
block|}
end_function
begin_ifndef
ifndef|#
directive|ifndef
name|MAEMO_UI
end_ifndef
begin_function
DECL|function|deleteSession
name|void
name|BearerMonitor
operator|::
name|deleteSession
parameter_list|()
block|{
name|SessionWidget
modifier|*
name|session
init|=
name|qobject_cast
argument_list|<
name|SessionWidget
operator|*
argument_list|>
argument_list|(
name|tabWidget
operator|->
name|currentWidget
argument_list|()
argument_list|)
decl_stmt|;
if|if
condition|(
name|session
condition|)
block|{
name|sessionWidgets
operator|.
name|removeAll
argument_list|(
name|session
argument_list|)
expr_stmt|;
operator|delete
name|session
expr_stmt|;
if|if
condition|(
name|tabWidget
operator|->
name|count
argument_list|()
operator|==
literal|0
condition|)
name|sessionGroup
operator|->
name|hide
argument_list|()
expr_stmt|;
block|}
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_function
DECL|function|performScan
name|void
name|BearerMonitor
operator|::
name|performScan
parameter_list|()
block|{
name|scanButton
operator|->
name|hide
argument_list|()
expr_stmt|;
name|progressBar
operator|->
name|show
argument_list|()
expr_stmt|;
name|manager
operator|.
name|updateConfigurations
argument_list|()
expr_stmt|;
block|}
end_function
end_unit
