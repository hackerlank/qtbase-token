begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the QtNetwork module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QNETWORKCONFIGURATION_H
end_ifndef
begin_define
DECL|macro|QNETWORKCONFIGURATION_H
define|#
directive|define
name|QNETWORKCONFIGURATION_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qglobal.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qshareddata.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qstring.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qlist.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qmetatype.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QNetworkConfigurationPrivate
name|class
name|QNetworkConfigurationPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_NETWORK_EXPORT
name|QNetworkConfiguration
block|{
name|public
label|:
name|QNetworkConfiguration
argument_list|()
expr_stmt|;
name|QNetworkConfiguration
argument_list|(
specifier|const
name|QNetworkConfiguration
operator|&
name|other
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|Q_COMPILER_RVALUE_REFS
name|QNetworkConfiguration
modifier|&
name|operator
init|=
operator|(
name|QNetworkConfiguration
operator|&&
name|other
operator|)
name|Q_DECL_NOTHROW
block|{
name|swap
argument_list|(
name|other
argument_list|)
block|;
return|return
operator|*
name|this
return|;
block|}
endif|#
directive|endif
name|QNetworkConfiguration
modifier|&
name|operator
init|=
operator|(
specifier|const
name|QNetworkConfiguration
operator|&
name|other
operator|)
decl_stmt|;
operator|~
name|QNetworkConfiguration
argument_list|()
expr_stmt|;
name|void
name|swap
parameter_list|(
name|QNetworkConfiguration
modifier|&
name|other
parameter_list|)
function|Q_DECL_NOTHROW
block|{
name|qSwap
argument_list|(
name|d
argument_list|,
name|other
operator|.
name|d
argument_list|)
expr_stmt|;
block|}
name|bool
name|operator
operator|==
operator|(
specifier|const
name|QNetworkConfiguration
operator|&
name|other
operator|)
specifier|const
expr_stmt|;
specifier|inline
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|QNetworkConfiguration
operator|&
name|other
operator|)
specifier|const
block|{
return|return
operator|!
name|operator
operator|==
operator|(
name|other
operator|)
return|;
block|}
enum|enum
name|Type
block|{
name|InternetAccessPoint
init|=
literal|0
block|,
name|ServiceNetwork
block|,
name|UserChoice
block|,
name|Invalid
block|}
enum|;
enum|enum
name|Purpose
block|{
name|UnknownPurpose
init|=
literal|0
block|,
name|PublicPurpose
block|,
name|PrivatePurpose
block|,
name|ServiceSpecificPurpose
block|}
enum|;
enum|enum
name|StateFlag
block|{
name|Undefined
init|=
literal|0x0000001
block|,
name|Defined
init|=
literal|0x0000002
block|,
name|Discovered
init|=
literal|0x0000006
block|,
name|Active
init|=
literal|0x000000e
block|}
enum|;
name|Q_DECLARE_FLAGS
argument_list|(
name|StateFlags
argument_list|,
name|StateFlag
argument_list|)
expr|enum
name|BearerType
block|{
name|BearerUnknown
block|,
name|BearerEthernet
block|,
name|BearerWLAN
block|,
name|Bearer2G
block|,
name|BearerCDMA2000
block|,
name|BearerWCDMA
block|,
name|BearerHSPA
block|,
name|BearerBluetooth
block|,
name|BearerWiMAX
block|,
name|BearerEVDO
block|,
name|BearerLTE
block|,
name|Bearer3G
block|,
name|Bearer4G
block|}
expr_stmt|;
name|StateFlags
name|state
argument_list|()
specifier|const
expr_stmt|;
name|Type
name|type
argument_list|()
specifier|const
expr_stmt|;
name|Purpose
name|purpose
argument_list|()
specifier|const
expr_stmt|;
name|BearerType
name|bearerType
argument_list|()
specifier|const
expr_stmt|;
name|BearerType
name|bearerTypeFamily
argument_list|()
specifier|const
expr_stmt|;
name|QString
name|bearerTypeName
argument_list|()
specifier|const
expr_stmt|;
name|QString
name|identifier
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|isRoamingAvailable
argument_list|()
specifier|const
expr_stmt|;
name|QList
operator|<
name|QNetworkConfiguration
operator|>
name|children
argument_list|()
specifier|const
expr_stmt|;
name|QString
name|name
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|isValid
argument_list|()
specifier|const
expr_stmt|;
name|private
label|:
name|friend
name|class
name|QNetworkConfigurationPrivate
decl_stmt|;
name|friend
name|class
name|QNetworkConfigurationManager
decl_stmt|;
name|friend
name|class
name|QNetworkConfigurationManagerPrivate
decl_stmt|;
name|friend
name|class
name|QNetworkSessionPrivate
decl_stmt|;
name|QExplicitlySharedDataPointer
operator|<
name|QNetworkConfigurationPrivate
operator|>
name|d
expr_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_macro
name|Q_DECLARE_SHARED
argument_list|(
argument|QNetworkConfiguration
argument_list|)
end_macro
begin_decl_stmt
name|QT_END_NAMESPACE
name|Q_DECLARE_METATYPE
argument_list|(
name|QNetworkConfiguration
argument_list|)
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QNETWORKCONFIGURATION_H
end_comment
end_unit
