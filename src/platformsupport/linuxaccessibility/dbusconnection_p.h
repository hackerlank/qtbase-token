begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|DBUSCONNECTION_H
end_ifndef
begin_define
DECL|macro|DBUSCONNECTION_H
define|#
directive|define
name|DBUSCONNECTION_H
end_define
begin_include
include|#
directive|include
file|<QtCore/QString>
end_include
begin_include
include|#
directive|include
file|<QtDBus/QDBusConnection>
end_include
begin_include
include|#
directive|include
file|<QtDBus/QDBusVariant>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QDBusServiceWatcher
name|class
name|QDBusServiceWatcher
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|DBusConnection
range|:
name|public
name|QObject
block|{
name|Q_OBJECT
name|public
operator|:
name|DBusConnection
argument_list|(
name|QObject
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
name|QDBusConnection
name|connection
argument_list|()
specifier|const
block|;
name|bool
name|isEnabled
argument_list|()
specifier|const
block|{
return|return
name|m_enabled
return|;
block|}
name|Q_SIGNALS
operator|:
comment|// Emitted when the global accessibility status changes to enabled
name|void
name|enabledChanged
argument_list|(
argument|bool enabled
argument_list|)
block|;
name|private
name|Q_SLOTS
operator|:
name|void
name|serviceRegistered
argument_list|()
block|;
name|void
name|serviceUnregistered
argument_list|()
block|;
name|void
name|enabledStateCallback
argument_list|(
specifier|const
name|QDBusVariant
operator|&
name|enabled
argument_list|)
block|;
comment|//    void enabledStateChanged(const QDBusVariant&);
name|void
name|connectA11yBus
argument_list|(
specifier|const
name|QString
operator|&
name|address
argument_list|)
block|;
name|void
name|dbusError
argument_list|(
specifier|const
name|QDBusError
operator|&
name|error
argument_list|)
block|;
name|private
operator|:
name|QString
name|getAccessibilityBusAddress
argument_list|()
specifier|const
block|;
name|QDBusServiceWatcher
operator|*
name|dbusWatcher
block|;
name|QDBusConnection
name|m_a11yConnection
block|;
name|bool
name|m_enabled
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
comment|// DBUSCONNECTION_H
end_comment
end_unit
