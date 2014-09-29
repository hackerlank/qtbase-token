begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Research In Motion ** Contact: http://www.qt-project.org/legal ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia. For licensing terms and ** conditions see http://qt.digia.com/licensing. For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights. These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QBBENGINE_H
end_ifndef
begin_define
DECL|macro|QBBENGINE_H
define|#
directive|define
name|QBBENGINE_H
end_define
begin_include
include|#
directive|include
file|"../qbearerengine_impl.h"
end_include
begin_include
include|#
directive|include
file|<QAbstractEventDispatcher>
end_include
begin_include
include|#
directive|include
file|<QAbstractNativeEventFilter>
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_BEARERMANAGEMENT
end_ifndef
begin_struct_decl
struct_decl|struct
name|bps_event_t
struct_decl|;
end_struct_decl
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QNetworkConfigurationPrivate
name|class
name|QNetworkConfigurationPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QNetworkSessionPrivate
name|class
name|QNetworkSessionPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QBearerEngineImpl
name|class
name|QBBEngine
range|:
name|public
name|QBearerEngineImpl
decl_stmt|,
name|public
name|QAbstractNativeEventFilter
block|{
name|Q_OBJECT
name|public
range|:
name|explicit
name|QBBEngine
argument_list|(
name|QObject
operator|*
name|parent
operator|=
literal|0
argument_list|)
decl_stmt|;
operator|~
name|QBBEngine
argument_list|()
expr_stmt|;
name|QString
name|getInterfaceFromId
argument_list|(
specifier|const
name|QString
operator|&
name|id
argument_list|)
name|Q_DECL_OVERRIDE
decl_stmt|;
name|bool
name|hasIdentifier
argument_list|(
specifier|const
name|QString
operator|&
name|id
argument_list|)
name|Q_DECL_OVERRIDE
decl_stmt|;
name|void
name|connectToId
argument_list|(
specifier|const
name|QString
operator|&
name|id
argument_list|)
name|Q_DECL_OVERRIDE
decl_stmt|;
name|void
name|disconnectFromId
argument_list|(
specifier|const
name|QString
operator|&
name|id
argument_list|)
name|Q_DECL_OVERRIDE
decl_stmt|;
name|Q_INVOKABLE
name|void
name|initialize
argument_list|()
name|Q_DECL_OVERRIDE
expr_stmt|;
name|Q_INVOKABLE
name|void
name|requestUpdate
argument_list|()
name|Q_DECL_OVERRIDE
expr_stmt|;
name|QNetworkSession
operator|::
name|State
name|sessionStateForId
argument_list|(
argument|const QString&id
argument_list|)
name|Q_DECL_OVERRIDE
expr_stmt|;
name|QNetworkConfigurationManager
operator|::
name|Capabilities
name|capabilities
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
expr_stmt|;
name|QNetworkSessionPrivate
operator|*
name|createSessionBackend
argument_list|()
name|Q_DECL_OVERRIDE
expr_stmt|;
name|QNetworkConfigurationPrivatePointer
name|defaultConfiguration
argument_list|()
name|Q_DECL_OVERRIDE
expr_stmt|;
name|bool
name|requiresPolling
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
expr_stmt|;
name|bool
name|nativeEventFilter
argument_list|(
specifier|const
name|QByteArray
operator|&
name|eventType
argument_list|,
name|void
operator|*
name|message
argument_list|,
name|long
operator|*
name|result
argument_list|)
name|Q_DECL_OVERRIDE
decl_stmt|;
name|protected
label|:
name|void
name|updateConfiguration
parameter_list|(
specifier|const
name|char
modifier|*
name|interface
parameter_list|)
function_decl|;
name|void
name|removeConfiguration
parameter_list|(
specifier|const
name|QString
modifier|&
name|id
parameter_list|)
function_decl|;
name|private
name|Q_SLOTS
range|:
name|void
name|doRequestUpdate
argument_list|()
decl_stmt|;
name|private
label|:
name|QHash
operator|<
name|QString
operator|,
name|QString
operator|>
name|configurationInterface
expr_stmt|;
name|mutable
name|QMutex
name|pollingMutex
decl_stmt|;
name|bool
name|pollingRequired
decl_stmt|;
name|bool
name|initialized
decl_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
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
begin_comment
comment|// QBBENGINE_H
end_comment
end_unit
