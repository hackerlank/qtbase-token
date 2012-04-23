begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QOFONOSERVICE_H
end_ifndef
begin_define
DECL|macro|QOFONOSERVICE_H
define|#
directive|define
name|QOFONOSERVICE_H
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
begin_define
DECL|macro|OFONO_SERVICE
define|#
directive|define
name|OFONO_SERVICE
value|"org.ofono"
end_define
begin_define
DECL|macro|OFONO_MANAGER_INTERFACE
define|#
directive|define
name|OFONO_MANAGER_INTERFACE
value|"org.ofono.Manager"
end_define
begin_define
DECL|macro|OFONO_MANAGER_PATH
define|#
directive|define
name|OFONO_MANAGER_PATH
value|"/"
end_define
begin_define
DECL|macro|OFONO_MODEM_INTERFACE
define|#
directive|define
name|OFONO_MODEM_INTERFACE
value|"org.ofono.Modem"
end_define
begin_define
DECL|macro|OFONO_NETWORK_REGISTRATION_INTERFACE
define|#
directive|define
name|OFONO_NETWORK_REGISTRATION_INTERFACE
value|"org.ofono.NetworkRegistration"
end_define
begin_define
DECL|macro|OFONO_NETWORK_OPERATOR_INTERFACE
define|#
directive|define
name|OFONO_NETWORK_OPERATOR_INTERFACE
value|"org.ofono.NetworkOperator"
end_define
begin_define
DECL|macro|OFONO_DATA_CONNECTION_MANAGER_INTERFACE
define|#
directive|define
name|OFONO_DATA_CONNECTION_MANAGER_INTERFACE
value|"org.ofono.DataConnectionManager"
end_define
begin_define
DECL|macro|OFONO_SIM_MANAGER_INTERFACE
define|#
directive|define
name|OFONO_SIM_MANAGER_INTERFACE
value|"org.ofono.SimManager"
end_define
begin_define
DECL|macro|OFONO_DATA_CONTEXT_INTERFACE
define|#
directive|define
name|OFONO_DATA_CONTEXT_INTERFACE
value|"org.ofono.PrimaryDataContext"
end_define
begin_define
DECL|macro|OFONO_SMS_MANAGER_INTERFACE
define|#
directive|define
name|OFONO_SMS_MANAGER_INTERFACE
value|"org.ofono.SmsManager"
end_define
begin_define
DECL|macro|OFONO_PHONEBOOK_INTERFACE
define|#
directive|define
name|OFONO_PHONEBOOK_INTERFACE
value|"org.ofono.Phonebook"
end_define
begin_define
DECL|macro|OFONO_MESSAGE_WAITING_INTERFACE
define|#
directive|define
name|OFONO_MESSAGE_WAITING_INTERFACE
value|"org.ofono.MessageWaiting"
end_define
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
name|QT_END_NAMESPACE
name|QT_BEGIN_NAMESPACE
name|class
name|QOfonoManagerInterface
range|:
name|public
name|QDBusAbstractInterface
block|{
name|Q_OBJECT
name|public
operator|:
name|QOfonoManagerInterface
argument_list|(
name|QObject
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
operator|~
name|QOfonoManagerInterface
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
name|bool
name|setProperty
argument_list|(
specifier|const
name|QString
operator|&
name|name
argument_list|,
specifier|const
name|QDBusVariant
operator|&
name|value
argument_list|)
block|;
name|QList
operator|<
name|QDBusObjectPath
operator|>
name|getModems
argument_list|()
block|;
name|QDBusObjectPath
name|currentModem
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
name|void
name|disconnectNotify
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
block|;  }
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QObject
name|class
name|QOfonoDBusHelper
range|:
name|public
name|QObject
decl_stmt|,
name|protected
name|QDBusContext
block|{
name|Q_OBJECT
name|public
range|:
name|QOfonoDBusHelper
argument_list|(
name|QObject
operator|*
name|parent
operator|=
literal|0
argument_list|)
decl_stmt|;
operator|~
name|QOfonoDBusHelper
argument_list|()
expr_stmt|;
name|public
name|slots
range|:
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
argument_list|)
decl_stmt|;
name|Q_SIGNALS
label|:
name|void
name|propertyChangedContext
parameter_list|(
specifier|const
name|QString
modifier|&
parameter_list|,
specifier|const
name|QString
modifier|&
parameter_list|,
specifier|const
name|QDBusVariant
modifier|&
parameter_list|)
function_decl|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_decl_stmt
name|class
name|QOfonoModemInterface
range|:
name|public
name|QDBusAbstractInterface
block|{
name|Q_OBJECT
name|public
operator|:
name|QOfonoModemInterface
argument_list|(
specifier|const
name|QString
operator|&
name|dbusModemPathName
argument_list|,
name|QObject
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
operator|~
name|QOfonoModemInterface
argument_list|()
block|;
name|QVariantMap
name|getProperties
argument_list|()
block|;
comment|//properties
name|bool
name|isPowered
argument_list|()
block|;
name|bool
name|isOnline
argument_list|()
block|;
name|QString
name|getName
argument_list|()
block|;
name|QString
name|getManufacturer
argument_list|()
block|;
name|QString
name|getModel
argument_list|()
block|;
name|QString
name|getRevision
argument_list|()
block|;
name|QString
name|getSerial
argument_list|()
block|;
name|QStringList
name|getFeatures
argument_list|()
block|;
comment|//sms, sim
name|QStringList
name|getInterfaces
argument_list|()
block|;
name|QString
name|defaultInterface
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
name|void
name|disconnectNotify
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
block|; }
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QOfonoNetworkRegistrationInterface
range|:
name|public
name|QDBusAbstractInterface
block|{
name|Q_OBJECT
name|public
operator|:
name|QOfonoNetworkRegistrationInterface
argument_list|(
specifier|const
name|QString
operator|&
name|dbusModemPathName
argument_list|,
name|QObject
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
operator|~
name|QOfonoNetworkRegistrationInterface
argument_list|()
block|;
name|QVariantMap
name|getProperties
argument_list|()
block|;
comment|//properties
name|QString
name|getStatus
argument_list|()
block|;
name|quint16
name|getLac
argument_list|()
block|;
name|quint32
name|getCellId
argument_list|()
block|;
name|QString
name|getTechnology
argument_list|()
block|;
name|QString
name|getOperatorName
argument_list|()
block|;
name|int
name|getSignalStrength
argument_list|()
block|;
name|QString
name|getBaseStation
argument_list|()
block|;
name|QList
operator|<
name|QDBusObjectPath
operator|>
name|getOperators
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
name|void
name|disconnectNotify
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
block|;  }
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QOfonoNetworkOperatorInterface
range|:
name|public
name|QDBusAbstractInterface
block|{
name|Q_OBJECT
name|public
operator|:
comment|//modem or operator paths
name|QOfonoNetworkOperatorInterface
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
name|QOfonoNetworkOperatorInterface
argument_list|()
block|;
name|QVariantMap
name|getProperties
argument_list|()
block|;
comment|//properties
name|QString
name|getName
argument_list|()
block|;
name|QString
name|getStatus
argument_list|()
block|;
comment|// "unknown", "available", "current" and "forbidden"
name|QString
name|getMcc
argument_list|()
block|;
name|QString
name|getMnc
argument_list|()
block|;
name|QStringList
name|getTechnologies
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
name|void
name|disconnectNotify
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
block|; }
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QOfonoSimInterface
range|:
name|public
name|QDBusAbstractInterface
block|{
name|Q_OBJECT
name|public
operator|:
name|QOfonoSimInterface
argument_list|(
specifier|const
name|QString
operator|&
name|dbusModemPathName
argument_list|,
name|QObject
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
operator|~
name|QOfonoSimInterface
argument_list|()
block|;
name|QVariantMap
name|getProperties
argument_list|()
block|;
comment|//properties
name|bool
name|isPresent
argument_list|()
block|;
name|QString
name|getHomeMcc
argument_list|()
block|;
name|QString
name|getHomeMnc
argument_list|()
block|;
comment|//    QStringList subscriberNumbers();
comment|//    QMap<QString,QString> serviceNumbers();
name|QString
name|pinRequired
argument_list|()
block|;
name|QString
name|lockedPins
argument_list|()
block|;
name|QString
name|cardIdentifier
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
name|void
name|disconnectNotify
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
block|; }
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QOfonoDataConnectionManagerInterface
range|:
name|public
name|QDBusAbstractInterface
block|{
name|Q_OBJECT
name|public
operator|:
name|QOfonoDataConnectionManagerInterface
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
name|QOfonoDataConnectionManagerInterface
argument_list|()
block|;
name|QVariantMap
name|getProperties
argument_list|()
block|;
comment|//properties
name|QList
operator|<
name|QDBusObjectPath
operator|>
name|getPrimaryContexts
argument_list|()
block|;
name|bool
name|isAttached
argument_list|()
block|;
name|bool
name|isRoamingAllowed
argument_list|()
block|;
name|bool
name|isPowered
argument_list|()
block|;
name|bool
name|setPower
argument_list|(
argument|bool on
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
name|void
name|disconnectNotify
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
block|; }
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QOfonoPrimaryDataContextInterface
range|:
name|public
name|QDBusAbstractInterface
block|{
name|Q_OBJECT
name|public
operator|:
name|QOfonoPrimaryDataContextInterface
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
name|QOfonoPrimaryDataContextInterface
argument_list|()
block|;
name|QVariantMap
name|getProperties
argument_list|()
block|;
comment|//properties
name|bool
name|isActive
argument_list|()
block|;
name|QString
name|getApName
argument_list|()
block|;
name|QString
name|getType
argument_list|()
block|;
name|QString
name|getName
argument_list|()
block|;
name|QVariantMap
name|getSettings
argument_list|()
block|;
name|QString
name|getInterface
argument_list|()
block|;
name|QString
name|getAddress
argument_list|()
block|;
name|bool
name|setActive
argument_list|(
argument|bool on
argument_list|)
block|;
name|bool
name|setApn
argument_list|(
specifier|const
name|QString
operator|&
name|name
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
name|void
name|disconnectNotify
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
name|bool
name|setProp
argument_list|(
specifier|const
name|QString
operator|&
argument_list|,
specifier|const
name|QVariant
operator|&
name|var
argument_list|)
block|; }
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QOfonoSmsInterface
range|:
name|public
name|QDBusAbstractInterface
block|{
name|Q_OBJECT
name|public
operator|:
name|QOfonoSmsInterface
argument_list|(
specifier|const
name|QString
operator|&
name|dbusModemPathName
argument_list|,
name|QObject
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
operator|~
name|QOfonoSmsInterface
argument_list|()
block|;
name|QVariantMap
name|getProperties
argument_list|()
block|;
name|void
name|sendMessage
argument_list|(
specifier|const
name|QString
operator|&
name|to
argument_list|,
specifier|const
name|QString
operator|&
name|message
argument_list|)
block|;
comment|//properties
name|QString
name|serviceCenterAddress
argument_list|()
block|;
name|bool
name|useDeliveryReports
argument_list|()
block|;
name|QString
name|bearer
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
name|void
name|disconnectNotify
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
name|immediateMessage
argument_list|(
specifier|const
name|QString
operator|&
name|message
argument_list|,
specifier|const
name|QVariantMap
operator|&
name|info
argument_list|)
block|;
name|void
name|incomingMessage
argument_list|(
specifier|const
name|QString
operator|&
name|message
argument_list|,
specifier|const
name|QVariantMap
operator|&
name|info
argument_list|)
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
comment|//QOFONOSERVICE_H
end_comment
end_unit
