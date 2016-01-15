begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QGENERICENGINE_H
end_ifndef
begin_define
DECL|macro|QGENERICENGINE_H
define|#
directive|define
name|QGENERICENGINE_H
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
name|class
name|QGenericEngine
range|:
name|public
name|QBearerEngineImpl
block|{
name|Q_OBJECT
name|public
operator|:
name|QGenericEngine
argument_list|(
name|QObject
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
operator|~
name|QGenericEngine
argument_list|()
block|;
name|QString
name|getInterfaceFromId
argument_list|(
argument|const QString&id
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|bool
name|hasIdentifier
argument_list|(
argument|const QString&id
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|void
name|connectToId
argument_list|(
argument|const QString&id
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|void
name|disconnectFromId
argument_list|(
argument|const QString&id
argument_list|)
name|Q_DECL_OVERRIDE
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
argument|const QString&id
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|QNetworkConfigurationManager
operator|::
name|Capabilities
name|capabilities
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|QNetworkSessionPrivate
operator|*
name|createSessionBackend
argument_list|()
name|Q_DECL_OVERRIDE
block|;
name|QNetworkConfigurationPrivatePointer
name|defaultConfiguration
argument_list|()
name|Q_DECL_OVERRIDE
block|;
name|bool
name|requiresPolling
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|private
name|Q_SLOTS
operator|:
name|void
name|doRequestUpdate
argument_list|()
block|;
name|private
operator|:
name|QMap
operator|<
name|QString
block|,
name|QString
operator|>
name|configurationInterface
block|; }
decl_stmt|;
end_decl_stmt
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
end_unit
