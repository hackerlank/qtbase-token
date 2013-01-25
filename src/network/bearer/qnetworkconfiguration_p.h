begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtNetwork module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QNETWORKCONFIGURATIONPRIVATE_H
end_ifndef
begin_define
DECL|macro|QNETWORKCONFIGURATIONPRIVATE_H
define|#
directive|define
name|QNETWORKCONFIGURATIONPRIVATE_H
end_define
begin_comment
comment|//
end_comment
begin_comment
comment|//  W A R N I N G
end_comment
begin_comment
comment|//  -------------
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|// This file is not part of the Qt API.  It exists purely as an
end_comment
begin_comment
comment|// implementation detail.  This header file may change from version to
end_comment
begin_comment
comment|// version without notice, or even be removed.
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|// We mean it.
end_comment
begin_comment
comment|//
end_comment
begin_include
include|#
directive|include
file|"qnetworkconfiguration.h"
end_include
begin_include
include|#
directive|include
file|<QtCore/qshareddata.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qmutex.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qmap.h>
end_include
begin_ifdef
ifdef|#
directive|ifdef
name|Q_OS_BLACKBERRY
end_ifdef
begin_include
include|#
directive|include
file|<bps/netstatus.h>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_typedef
DECL|typedef|QNetworkConfigurationPrivatePointer
typedef|typedef
name|QExplicitlySharedDataPointer
operator|<
name|QNetworkConfigurationPrivate
operator|>
name|QNetworkConfigurationPrivatePointer
expr_stmt|;
end_typedef
begin_decl_stmt
name|class
name|QNetworkConfigurationPrivate
range|:
name|public
name|QSharedData
block|{
name|public
operator|:
name|QNetworkConfigurationPrivate
argument_list|()
operator|:
name|mutex
argument_list|(
name|QMutex
operator|::
name|Recursive
argument_list|)
block|,
name|type
argument_list|(
name|QNetworkConfiguration
operator|::
name|Invalid
argument_list|)
block|,
name|purpose
argument_list|(
name|QNetworkConfiguration
operator|::
name|UnknownPurpose
argument_list|)
block|,
name|bearerType
argument_list|(
name|QNetworkConfiguration
operator|::
name|BearerUnknown
argument_list|)
block|,
ifdef|#
directive|ifdef
name|Q_OS_BLACKBERRY
name|oldIpStatus
argument_list|(
name|NETSTATUS_IP_STATUS_ERROR_UNKNOWN
argument_list|)
block|,
endif|#
directive|endif
name|isValid
argument_list|(
name|false
argument_list|)
block|,
name|roamingSupported
argument_list|(
argument|false
argument_list|)
block|{}
name|virtual
operator|~
name|QNetworkConfigurationPrivate
argument_list|()
block|{
comment|//release pointers to member configurations
name|serviceNetworkMembers
operator|.
name|clear
argument_list|()
block|;     }
name|QMap
operator|<
name|unsigned
name|int
block|,
name|QNetworkConfigurationPrivatePointer
operator|>
name|serviceNetworkMembers
block|;
name|mutable
name|QMutex
name|mutex
block|;
name|QString
name|name
block|;
name|QString
name|id
block|;
name|QNetworkConfiguration
operator|::
name|StateFlags
name|state
block|;
name|QNetworkConfiguration
operator|::
name|Type
name|type
block|;
name|QNetworkConfiguration
operator|::
name|Purpose
name|purpose
block|;
name|QNetworkConfiguration
operator|::
name|BearerType
name|bearerType
block|;
ifdef|#
directive|ifdef
name|Q_OS_BLACKBERRY
name|netstatus_ip_status_t
name|oldIpStatus
block|;
endif|#
directive|endif
name|bool
name|isValid
block|;
name|bool
name|roamingSupported
block|;
name|private
operator|:
name|Q_DISABLE_COPY
argument_list|(
argument|QNetworkConfigurationPrivate
argument_list|)
block|}
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QT_END_NAMESPACE
name|Q_DECLARE_METATYPE
argument_list|(
name|QNetworkConfigurationPrivatePointer
argument_list|)
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QNETWORKCONFIGURATIONPRIVATE_H
end_comment
end_unit
