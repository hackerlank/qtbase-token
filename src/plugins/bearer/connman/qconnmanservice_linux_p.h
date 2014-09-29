begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2014 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia. For licensing terms and ** conditions see http://qt.digia.com/licensing. For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights. These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QCONNMANSERVICE_H
end_ifndef
begin_define
DECL|macro|QCONNMANSERVICE_H
define|#
directive|define
name|QCONNMANSERVICE_H
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
file|<QtDBus/QtDBus>
end_include
begin_include
include|#
directive|include
file|<QtDBus/QDBusConnection>
end_include
begin_include
include|#
directive|include
file|<QtDBus/QDBusError>
end_include
begin_include
include|#
directive|include
file|<QtDBus/QDBusInterface>
end_include
begin_include
include|#
directive|include
file|<QtDBus/QDBusMessage>
end_include
begin_include
include|#
directive|include
file|<QtDBus/QDBusReply>
end_include
begin_include
include|#
directive|include
file|<QtDBus/QDBusArgument>
end_include
begin_include
include|#
directive|include
file|<QtDBus/QDBusPendingCallWatcher>
end_include
begin_include
include|#
directive|include
file|<QtDBus/QDBusObjectPath>
end_include
begin_include
include|#
directive|include
file|<QtDBus/QDBusContext>
end_include
begin_include
include|#
directive|include
file|<QMap>
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_BEARERMANAGEMENT
end_ifndef
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_DBUS
end_ifndef
begin_ifndef
ifndef|#
directive|ifndef
name|__CONNMAN_DBUS_H
end_ifndef
begin_define
DECL|macro|CONNMAN_SERVICE
define|#
directive|define
name|CONNMAN_SERVICE
value|"net.connman"
end_define
begin_define
DECL|macro|CONNMAN_PATH
define|#
directive|define
name|CONNMAN_PATH
value|"/net/connman"
end_define
begin_define
DECL|macro|CONNMAN_MANAGER_INTERFACE
define|#
directive|define
name|CONNMAN_MANAGER_INTERFACE
value|CONNMAN_SERVICE ".Manager"
end_define
begin_define
DECL|macro|CONNMAN_MANAGER_PATH
define|#
directive|define
name|CONNMAN_MANAGER_PATH
value|"/"
end_define
begin_define
DECL|macro|CONNMAN_SERVICE_INTERFACE
define|#
directive|define
name|CONNMAN_SERVICE_INTERFACE
value|CONNMAN_SERVICE ".Service"
end_define
begin_define
DECL|macro|CONNMAN_TECHNOLOGY_INTERFACE
define|#
directive|define
name|CONNMAN_TECHNOLOGY_INTERFACE
value|CONNMAN_SERVICE ".Technology"
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_struct
DECL|struct|ConnmanMap
struct|struct
name|ConnmanMap
block|{
DECL|member|objectPath
name|QDBusObjectPath
name|objectPath
decl_stmt|;
DECL|member|propertyMap
name|QVariantMap
name|propertyMap
decl_stmt|;
block|}
struct|;
end_struct
begin_typedef
DECL|typedef|ConnmanMapList
typedef|typedef
name|QList
operator|<
name|ConnmanMap
operator|>
name|ConnmanMapList
expr_stmt|;
end_typedef
begin_decl_stmt
name|QT_END_NAMESPACE
name|Q_DECLARE_METATYPE
argument_list|(
name|QT_PREPEND_NAMESPACE
argument_list|(
name|ConnmanMap
argument_list|)
argument_list|)
name|Q_DECLARE_METATYPE
argument_list|(
name|QT_PREPEND_NAMESPACE
argument_list|(
name|ConnmanMapList
argument_list|)
argument_list|)
name|QT_BEGIN_NAMESPACE
name|QDBusArgument
modifier|&
name|operator
decl|<<
argument_list|(
name|QDBusArgument
operator|&
name|argument
argument_list|,
specifier|const
name|ConnmanMap
operator|&
name|obj
argument_list|)
decl_stmt|;
end_decl_stmt
begin_expr_stmt
DECL|variable|operator
specifier|const
name|QDBusArgument
operator|&
name|operator
operator|>>
operator|(
specifier|const
name|QDBusArgument
operator|&
name|argument
operator|,
name|ConnmanMap
operator|&
name|obj
operator|)
expr_stmt|;
end_expr_stmt
begin_decl_stmt
DECL|variable|QConnmanTechnologyInterface
name|class
name|QConnmanTechnologyInterface
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QConnmanServiceInterface
name|class
name|QConnmanServiceInterface
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QConnmanManagerInterface
range|:
name|public
name|QDBusAbstractInterface
block|{
name|Q_OBJECT
name|public
operator|:
name|QConnmanManagerInterface
argument_list|(
name|QObject
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
operator|~
name|QConnmanManagerInterface
argument_list|()
block|;
name|QDBusObjectPath
name|path
argument_list|()
specifier|const
block|;
name|QVariantMap
name|getProperties
argument_list|()
block|;
name|QString
name|getState
argument_list|()
block|;
name|bool
name|getOfflineMode
argument_list|()
block|;
name|QStringList
name|getTechnologies
argument_list|()
block|;
name|QStringList
name|getServices
argument_list|()
block|;
name|void
name|requestScan
argument_list|(
specifier|const
name|QString
operator|&
name|type
argument_list|)
block|;
name|QHash
operator|<
name|QString
block|,
name|QConnmanTechnologyInterface
operator|*
operator|>
name|technologiesMap
block|;
name|Q_SIGNALS
operator|:
name|void
name|propertyChanged
argument_list|(
specifier|const
name|QString
operator|&
argument_list|,
specifier|const
name|QDBusVariant
operator|&
name|value
argument_list|)
block|;
name|void
name|stateChanged
argument_list|(
specifier|const
name|QString
operator|&
argument_list|)
block|;
name|void
name|propertyChangedContext
argument_list|(
specifier|const
name|QString
operator|&
argument_list|,
specifier|const
name|QString
operator|&
argument_list|,
specifier|const
name|QDBusVariant
operator|&
argument_list|)
block|;
name|void
name|servicesChanged
argument_list|(
specifier|const
name|ConnmanMapList
operator|&
argument_list|,
specifier|const
name|QList
operator|<
name|QDBusObjectPath
operator|>
operator|&
argument_list|)
block|;
name|void
name|servicesReady
argument_list|(
specifier|const
name|QStringList
operator|&
argument_list|)
block|;
name|void
name|scanFinished
argument_list|()
block|;
name|protected
operator|:
name|void
name|connectNotify
argument_list|(
specifier|const
name|QMetaMethod
operator|&
name|signal
argument_list|)
block|;
name|QVariant
name|getProperty
argument_list|(
specifier|const
name|QString
operator|&
argument_list|)
block|;
name|private
operator|:
name|QVariantMap
name|propertiesCacheMap
block|;
name|QStringList
name|servicesList
block|;
name|QStringList
name|technologiesList
block|;
name|private
name|slots
operator|:
name|void
name|onServicesChanged
argument_list|(
specifier|const
name|ConnmanMapList
operator|&
argument_list|,
specifier|const
name|QList
operator|<
name|QDBusObjectPath
operator|>
operator|&
argument_list|)
block|;
name|void
name|changedProperty
argument_list|(
specifier|const
name|QString
operator|&
argument_list|,
specifier|const
name|QDBusVariant
operator|&
name|value
argument_list|)
block|;
name|void
name|propertiesReply
argument_list|(
name|QDBusPendingCallWatcher
operator|*
name|call
argument_list|)
block|;
name|void
name|servicesReply
argument_list|(
name|QDBusPendingCallWatcher
operator|*
name|call
argument_list|)
block|;
name|void
name|technologyAdded
argument_list|(
specifier|const
name|QDBusObjectPath
operator|&
name|technology
argument_list|,
specifier|const
name|QVariantMap
operator|&
name|properties
argument_list|)
block|;
name|void
name|technologyRemoved
argument_list|(
specifier|const
name|QDBusObjectPath
operator|&
name|technology
argument_list|)
block|;  }
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QConnmanServiceInterface
range|:
name|public
name|QDBusAbstractInterface
block|{
name|Q_OBJECT
name|public
operator|:
name|explicit
name|QConnmanServiceInterface
argument_list|(
specifier|const
name|QString
operator|&
name|dbusPathName
argument_list|,
name|QObject
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
operator|~
name|QConnmanServiceInterface
argument_list|()
block|;
name|QVariantMap
name|getProperties
argument_list|()
block|;
comment|// clearProperty
name|void
name|connect
argument_list|()
block|;
name|void
name|disconnect
argument_list|()
block|;
name|void
name|remove
argument_list|()
block|;
comment|// properties
name|QString
name|state
argument_list|()
block|;
name|QString
name|lastError
argument_list|()
block|;
name|QString
name|name
argument_list|()
block|;
name|QString
name|type
argument_list|()
block|;
name|QString
name|security
argument_list|()
block|;
name|bool
name|favorite
argument_list|()
block|;
name|bool
name|autoConnect
argument_list|()
block|;
name|bool
name|roaming
argument_list|()
block|;
name|QVariantMap
name|ethernet
argument_list|()
block|;
name|QString
name|serviceInterface
argument_list|()
block|;
name|bool
name|isOfflineMode
argument_list|()
block|;
name|QStringList
name|services
argument_list|()
block|;
name|Q_SIGNALS
operator|:
name|void
name|propertyChanged
argument_list|(
specifier|const
name|QString
operator|&
argument_list|,
specifier|const
name|QDBusVariant
operator|&
name|value
argument_list|)
block|;
name|void
name|propertyChangedContext
argument_list|(
specifier|const
name|QString
operator|&
argument_list|,
specifier|const
name|QString
operator|&
argument_list|,
specifier|const
name|QDBusVariant
operator|&
argument_list|)
block|;
name|void
name|propertiesReady
argument_list|()
block|;
name|void
name|stateChanged
argument_list|(
specifier|const
name|QString
operator|&
name|state
argument_list|)
block|;
name|protected
operator|:
name|void
name|connectNotify
argument_list|(
specifier|const
name|QMetaMethod
operator|&
name|signal
argument_list|)
block|;
name|QVariant
name|getProperty
argument_list|(
specifier|const
name|QString
operator|&
argument_list|)
block|;
name|private
operator|:
name|QVariantMap
name|propertiesCacheMap
block|;
name|private
name|slots
operator|:
name|void
name|propertiesReply
argument_list|(
name|QDBusPendingCallWatcher
operator|*
name|call
argument_list|)
block|;
name|void
name|changedProperty
argument_list|(
specifier|const
name|QString
operator|&
argument_list|,
specifier|const
name|QDBusVariant
operator|&
name|value
argument_list|)
block|;  }
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QConnmanTechnologyInterface
range|:
name|public
name|QDBusAbstractInterface
block|{
name|Q_OBJECT
name|public
operator|:
name|explicit
name|QConnmanTechnologyInterface
argument_list|(
specifier|const
name|QString
operator|&
name|dbusPathName
argument_list|,
name|QObject
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
operator|~
name|QConnmanTechnologyInterface
argument_list|()
block|;
name|QString
name|type
argument_list|()
block|;
name|void
name|scan
argument_list|()
block|;
name|Q_SIGNALS
operator|:
name|void
name|propertyChanged
argument_list|(
specifier|const
name|QString
operator|&
argument_list|,
specifier|const
name|QDBusVariant
operator|&
name|value
argument_list|)
block|;
name|void
name|propertyChangedContext
argument_list|(
specifier|const
name|QString
operator|&
argument_list|,
specifier|const
name|QString
operator|&
argument_list|,
specifier|const
name|QDBusVariant
operator|&
argument_list|)
block|;
name|void
name|scanFinished
argument_list|()
block|;
name|protected
operator|:
name|void
name|connectNotify
argument_list|(
specifier|const
name|QMetaMethod
operator|&
name|signal
argument_list|)
block|;
name|QVariant
name|getProperty
argument_list|(
specifier|const
name|QString
operator|&
argument_list|)
block|;
name|private
operator|:
name|QVariantMap
name|properties
argument_list|()
block|;
name|QVariantMap
name|propertiesMap
block|;
name|void
name|scanReply
argument_list|(
name|QDBusPendingCallWatcher
operator|*
name|call
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
comment|// QT_NO_DBUS
end_comment
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
comment|//QCONNMANSERVICE_H
end_comment
end_unit
