begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
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
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_SYSTEMTRAYICON
end_ifndef
begin_decl_stmt
DECL|variable|QDBusTrayIcon
name|class
name|QDBusTrayIcon
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_SYSTEMTRAYICON
end_comment
begin_decl_stmt
name|class
name|QDBusMenuConnection
range|:
name|public
name|QObject
block|{
name|Q_OBJECT
name|public
operator|:
name|QDBusMenuConnection
argument_list|(
name|QObject
operator|*
name|parent
operator|=
literal|0
argument_list|,
specifier|const
name|QString
operator|&
name|serviceName
operator|=
name|QString
argument_list|()
argument_list|)
block|;
name|QDBusConnection
name|connection
argument_list|()
specifier|const
block|{
return|return
name|m_connection
return|;
block|}
name|bool
name|isStatusNotifierHostRegistered
argument_list|()
specifier|const
block|{
return|return
name|m_statusNotifierHostRegistered
return|;
block|}
ifndef|#
directive|ifndef
name|QT_NO_SYSTEMTRAYICON
name|bool
name|registerTrayIconMenu
argument_list|(
name|QDBusTrayIcon
operator|*
name|item
argument_list|)
block|;
name|bool
name|registerTrayIcon
argument_list|(
name|QDBusTrayIcon
operator|*
name|item
argument_list|)
block|;
name|bool
name|unregisterTrayIcon
argument_list|(
name|QDBusTrayIcon
operator|*
name|item
argument_list|)
block|;
endif|#
directive|endif
comment|// QT_NO_SYSTEMTRAYICON
name|Q_SIGNALS
operator|:
ifndef|#
directive|ifndef
name|QT_NO_SYSTEMTRAYICON
name|void
name|trayIconRegistered
argument_list|()
block|;
endif|#
directive|endif
comment|// QT_NO_SYSTEMTRAYICON
name|private
name|Q_SLOTS
operator|:
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
name|QDBusConnection
name|m_connection
block|;
name|QDBusServiceWatcher
operator|*
name|m_dbusWatcher
block|;
name|bool
name|m_statusNotifierHostRegistered
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
