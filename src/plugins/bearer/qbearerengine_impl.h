begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QBEARERENGINE_IMPL_H
end_ifndef
begin_define
DECL|macro|QBEARERENGINE_IMPL_H
define|#
directive|define
name|QBEARERENGINE_IMPL_H
end_define
begin_include
include|#
directive|include
file|<QtNetwork/private/qbearerengine_p.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
name|class
name|QBearerEngineImpl
range|:
name|public
name|QBearerEngine
block|{
name|Q_OBJECT
name|public
operator|:
expr|enum
name|ConnectionError
block|{
name|InterfaceLookupError
operator|=
literal|0
block|,
name|ConnectError
block|,
name|OperationNotSupported
block|,
name|DisconnectionError
block|,     }
block|;
name|QBearerEngineImpl
argument_list|(
name|QObject
operator|*
name|parent
operator|=
literal|0
argument_list|)
operator|:
name|QBearerEngine
argument_list|(
argument|parent
argument_list|)
block|{}
operator|~
name|QBearerEngineImpl
argument_list|()
block|{}
name|virtual
name|void
name|connectToId
argument_list|(
specifier|const
name|QString
operator|&
name|id
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|void
name|disconnectFromId
argument_list|(
specifier|const
name|QString
operator|&
name|id
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|QString
name|getInterfaceFromId
argument_list|(
specifier|const
name|QString
operator|&
name|id
argument_list|)
operator|=
literal|0
block|;
name|virtual
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
operator|=
literal|0
block|;
name|virtual
name|quint64
name|bytesWritten
argument_list|(
argument|const QString&
argument_list|)
block|{
return|return
name|Q_UINT64_C
argument_list|(
literal|0
argument_list|)
return|;
block|}
name|virtual
name|quint64
name|bytesReceived
argument_list|(
argument|const QString&
argument_list|)
block|{
return|return
name|Q_UINT64_C
argument_list|(
literal|0
argument_list|)
return|;
block|}
name|virtual
name|quint64
name|startTime
argument_list|(
argument|const QString&
argument_list|)
block|{
return|return
name|Q_UINT64_C
argument_list|(
literal|0
argument_list|)
return|;
block|}
name|Q_SIGNALS
operator|:
name|void
name|connectionError
argument_list|(
argument|const QString&id
argument_list|,
argument|QBearerEngineImpl::ConnectionError error
argument_list|)
block|; }
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QT_END_NAMESPACE
name|Q_DECLARE_METATYPE
argument_list|(
name|QBearerEngineImpl
operator|::
name|ConnectionError
argument_list|)
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QBEARERENGINE_IMPL_H
end_comment
end_unit
