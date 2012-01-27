begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: http://www.qt-project.org/ ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|SERVERADDRESSPROXY_H
end_ifndef
begin_define
DECL|macro|SERVERADDRESSPROXY_H
define|#
directive|define
name|SERVERADDRESSPROXY_H
end_define
begin_include
include|#
directive|include
file|<QtCore/QObject>
end_include
begin_include
include|#
directive|include
file|<QtCore/QByteArray>
end_include
begin_include
include|#
directive|include
file|<QtCore/QList>
end_include
begin_include
include|#
directive|include
file|<QtCore/QMap>
end_include
begin_include
include|#
directive|include
file|<QtCore/QString>
end_include
begin_include
include|#
directive|include
file|<QtCore/QStringList>
end_include
begin_include
include|#
directive|include
file|<QtCore/QVariant>
end_include
begin_include
include|#
directive|include
file|<QtDBus/QtDBus>
end_include
begin_comment
comment|/*  * Proxy class for interface org.maliit.Server.Address  */
end_comment
begin_decl_stmt
name|class
name|OrgMaliitServerAddressInterface
range|:
name|public
name|QDBusAbstractInterface
block|{
name|Q_OBJECT
name|public
operator|:
specifier|static
specifier|inline
specifier|const
name|char
operator|*
name|staticInterfaceName
argument_list|()
block|{
return|return
literal|"org.maliit.Server.Address"
return|;
block|}
name|public
operator|:
name|OrgMaliitServerAddressInterface
argument_list|(
specifier|const
name|QString
operator|&
name|service
argument_list|,
specifier|const
name|QString
operator|&
name|path
argument_list|,
specifier|const
name|QDBusConnection
operator|&
name|connection
argument_list|,
name|QObject
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
operator|~
name|OrgMaliitServerAddressInterface
argument_list|()
block|;
name|Q_PROPERTY
argument_list|(
argument|QString address READ address
argument_list|)
specifier|inline
name|QString
name|address
argument_list|()
specifier|const
block|{
return|return
name|qvariant_cast
operator|<
name|QString
operator|>
operator|(
name|property
argument_list|(
literal|"address"
argument_list|)
operator|)
return|;
block|}
name|public
name|Q_SLOTS
operator|:
comment|// METHODS
name|Q_SIGNALS
operator|:
comment|// SIGNALS
expr|}
block|;
name|namespace
name|org
block|{
name|namespace
name|maliit
block|{
name|namespace
name|Server
block|{
typedef|typedef
operator|::
name|OrgMaliitServerAddressInterface
name|Address
expr_stmt|;
block|}
expr|} }
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
end_unit
