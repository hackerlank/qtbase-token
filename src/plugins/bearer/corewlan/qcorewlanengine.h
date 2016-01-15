begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QCOREWLANENGINE_H
end_ifndef
begin_define
DECL|macro|QCOREWLANENGINE_H
define|#
directive|define
name|QCOREWLANENGINE_H
end_define
begin_include
include|#
directive|include
file|"../qbearerengine_impl.h"
end_include
begin_include
include|#
directive|include
file|<QMap>
end_include
begin_include
include|#
directive|include
file|<QTimer>
end_include
begin_include
include|#
directive|include
file|<SystemConfiguration/SystemConfiguration.h>
end_include
begin_include
include|#
directive|include
file|<QThread>
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_BEARERMANAGEMENT
end_ifndef
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QNetworkConfigurationPrivate
name|class
name|QNetworkConfigurationPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QScanThread
name|class
name|QScanThread
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QCoreWlanEngine
range|:
name|public
name|QBearerEngineImpl
block|{
name|friend
name|class
name|QScanThread
block|;
name|Q_OBJECT
name|public
operator|:
name|QCoreWlanEngine
argument_list|(
name|QObject
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
operator|~
name|QCoreWlanEngine
argument_list|()
block|;
name|QString
name|getInterfaceFromId
argument_list|(
specifier|const
name|QString
operator|&
name|id
argument_list|)
block|;
name|bool
name|hasIdentifier
argument_list|(
specifier|const
name|QString
operator|&
name|id
argument_list|)
block|;
name|void
name|connectToId
argument_list|(
specifier|const
name|QString
operator|&
name|id
argument_list|)
block|;
name|void
name|disconnectFromId
argument_list|(
specifier|const
name|QString
operator|&
name|id
argument_list|)
block|;
name|Q_INVOKABLE
name|void
name|initialize
argument_list|()
block|;
name|Q_INVOKABLE
name|void
name|requestUpdate
argument_list|()
block|;
name|QNetworkSession
operator|::
name|State
name|sessionStateForId
argument_list|(
specifier|const
name|QString
operator|&
name|id
argument_list|)
block|;
name|quint64
name|bytesWritten
argument_list|(
specifier|const
name|QString
operator|&
name|id
argument_list|)
block|;
name|quint64
name|bytesReceived
argument_list|(
specifier|const
name|QString
operator|&
name|id
argument_list|)
block|;
name|quint64
name|startTime
argument_list|(
specifier|const
name|QString
operator|&
name|id
argument_list|)
block|;
name|QNetworkConfigurationManager
operator|::
name|Capabilities
name|capabilities
argument_list|()
specifier|const
block|;
name|QNetworkSessionPrivate
operator|*
name|createSessionBackend
argument_list|()
block|;
name|QNetworkConfigurationPrivatePointer
name|defaultConfiguration
argument_list|()
block|;
name|bool
name|requiresPolling
argument_list|()
specifier|const
block|;
name|private
name|Q_SLOTS
operator|:
name|void
name|doRequestUpdate
argument_list|()
block|;
name|void
name|networksChanged
argument_list|()
block|;
name|void
name|checkDisconnect
argument_list|()
block|;
name|private
operator|:
name|bool
name|isWifiReady
argument_list|(
specifier|const
name|QString
operator|&
name|dev
argument_list|)
block|;
name|QList
operator|<
name|QNetworkConfigurationPrivate
operator|*
operator|>
name|foundConfigurations
block|;
name|SCDynamicStoreRef
name|storeSession
block|;
name|CFRunLoopSourceRef
name|runloopSource
block|;
name|bool
name|hasWifi
block|;
name|bool
name|scanning
block|;
name|QScanThread
operator|*
name|scanThread
block|;
name|quint64
name|getBytes
argument_list|(
argument|const QString&interfaceName
argument_list|,
argument|bool b
argument_list|)
block|;
name|QString
name|disconnectedInterfaceString
block|;
name|protected
operator|:
name|void
name|startNetworkChangeLoop
argument_list|()
block|;  }
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QScanThread
range|:
name|public
name|QThread
block|{
name|Q_OBJECT
name|public
operator|:
name|QScanThread
argument_list|(
name|QObject
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
operator|~
name|QScanThread
argument_list|()
block|;
name|void
name|quit
argument_list|()
block|;
name|QList
operator|<
name|QNetworkConfigurationPrivate
operator|*
operator|>
name|getConfigurations
argument_list|()
block|;
name|QString
name|interfaceName
block|;
name|QMap
operator|<
name|QString
block|,
name|QString
operator|>
name|configurationInterface
block|;
name|void
name|getUserConfigurations
argument_list|()
block|;
name|QString
name|getNetworkNameFromSsid
argument_list|(
specifier|const
name|QString
operator|&
name|ssid
argument_list|)
block|;
name|QString
name|getSsidFromNetworkName
argument_list|(
specifier|const
name|QString
operator|&
name|name
argument_list|)
block|;
name|bool
name|isKnownSsid
argument_list|(
specifier|const
name|QString
operator|&
name|ssid
argument_list|)
block|;
name|QMap
operator|<
name|QString
block|,
name|QMap
operator|<
name|QString
block|,
name|QString
operator|>
expr|>
name|userProfiles
block|;
name|signals
operator|:
name|void
name|networksChanged
argument_list|()
block|;
name|protected
operator|:
name|void
name|run
argument_list|()
block|;
name|private
operator|:
name|QList
operator|<
name|QNetworkConfigurationPrivate
operator|*
operator|>
name|fetchedConfigurations
block|;
name|QMutex
name|mutex
block|;
name|QStringList
name|foundNetwork
argument_list|(
argument|const QString&id
argument_list|,
argument|const QString&ssid
argument_list|,
argument|const QNetworkConfiguration::StateFlags state
argument_list|,
argument|const QString&interfaceName
argument_list|,
argument|const QNetworkConfiguration::Purpose purpose
argument_list|)
block|;  }
decl_stmt|;
end_decl_stmt
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_BEARERMANAGEMENT
end_comment
begin_endif
endif|#
directive|endif
end_endif
end_unit
