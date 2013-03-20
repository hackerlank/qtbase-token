begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtDBus module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
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
comment|// This file is not part of the public API.  This header file may
end_comment
begin_comment
comment|// change from version to version without notice, or even be
end_comment
begin_comment
comment|// removed.
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
begin_comment
comment|//
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QDBUSINTEGRATOR_P_H
end_ifndef
begin_define
DECL|macro|QDBUSINTEGRATOR_P_H
define|#
directive|define
name|QDBUSINTEGRATOR_P_H
end_define
begin_include
include|#
directive|include
file|"qdbus_symbols_p.h"
end_include
begin_include
include|#
directive|include
file|"qcoreevent.h"
end_include
begin_include
include|#
directive|include
file|"qeventloop.h"
end_include
begin_include
include|#
directive|include
file|"qhash.h"
end_include
begin_include
include|#
directive|include
file|"qobject.h"
end_include
begin_include
include|#
directive|include
file|"private/qobject_p.h"
end_include
begin_include
include|#
directive|include
file|"qlist.h"
end_include
begin_include
include|#
directive|include
file|"qpointer.h"
end_include
begin_include
include|#
directive|include
file|"qsemaphore.h"
end_include
begin_include
include|#
directive|include
file|"qdbusconnection.h"
end_include
begin_include
include|#
directive|include
file|"qdbusmessage.h"
end_include
begin_include
include|#
directive|include
file|"qdbusconnection_p.h"
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_DBUS
end_ifndef
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QDBusConnectionPrivate
name|class
name|QDBusConnectionPrivate
decl_stmt|;
end_decl_stmt
begin_comment
comment|// Really private structs used by qdbusintegrator.cpp
end_comment
begin_comment
comment|// Things that aren't used by any other file
end_comment
begin_struct
DECL|struct|QDBusSlotCache
struct|struct
name|QDBusSlotCache
block|{
DECL|struct|Data
struct|struct
name|Data
block|{
DECL|member|flags
name|int
name|flags
decl_stmt|;
DECL|member|slotIdx
name|int
name|slotIdx
decl_stmt|;
DECL|member|metaTypes
name|QVector
operator|<
name|int
operator|>
name|metaTypes
expr_stmt|;
block|}
struct|;
DECL|typedef|QString
DECL|typedef|Hash
typedef|typedef
name|QMultiHash
operator|<
name|QString
operator|,
name|Data
operator|>
name|Hash
expr_stmt|;
DECL|member|hash
name|Hash
name|hash
decl_stmt|;
block|}
struct|;
end_struct
begin_decl_stmt
name|class
name|QDBusCallDeliveryEvent
range|:
name|public
name|QMetaCallEvent
block|{
name|public
operator|:
name|QDBusCallDeliveryEvent
argument_list|(
argument|const QDBusConnection&c
argument_list|,
argument|int id
argument_list|,
argument|QObject *sender
argument_list|,
argument|const QDBusMessage&msg
argument_list|,
argument|const QVector<int>&types
argument_list|,
argument|int f =
literal|0
argument_list|)
operator|:
name|QMetaCallEvent
argument_list|(
literal|0
argument_list|,
name|id
argument_list|,
literal|0
argument_list|,
name|sender
argument_list|,
operator|-
literal|1
argument_list|)
block|,
name|connection
argument_list|(
name|c
argument_list|)
block|,
name|message
argument_list|(
name|msg
argument_list|)
block|,
name|metaTypes
argument_list|(
name|types
argument_list|)
block|,
name|flags
argument_list|(
argument|f
argument_list|)
block|{ }
name|void
name|placeMetaCall
argument_list|(
argument|QObject *object
argument_list|)
block|{
name|QDBusConnectionPrivate
operator|::
name|d
argument_list|(
name|connection
argument_list|)
operator|->
name|deliverCall
argument_list|(
name|object
argument_list|,
name|flags
argument_list|,
name|message
argument_list|,
name|metaTypes
argument_list|,
name|id
argument_list|()
argument_list|)
block|;     }
name|private
operator|:
name|QDBusConnection
name|connection
block|;
comment|// just for refcounting
name|QDBusMessage
name|message
block|;
name|QVector
operator|<
name|int
operator|>
name|metaTypes
block|;
name|int
name|flags
block|; }
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QDBusActivateObjectEvent
range|:
name|public
name|QMetaCallEvent
block|{
name|public
operator|:
name|QDBusActivateObjectEvent
argument_list|(
argument|const QDBusConnection&c
argument_list|,
argument|QObject *sender
argument_list|,
argument|const QDBusConnectionPrivate::ObjectTreeNode&n
argument_list|,
argument|int p
argument_list|,
argument|const QDBusMessage&m
argument_list|,
argument|QSemaphore *s =
literal|0
argument_list|)
operator|:
name|QMetaCallEvent
argument_list|(
literal|0
argument_list|,
name|ushort
argument_list|(
operator|-
literal|1
argument_list|)
argument_list|,
literal|0
argument_list|,
name|sender
argument_list|,
operator|-
literal|1
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
name|s
argument_list|)
block|,
name|connection
argument_list|(
name|c
argument_list|)
block|,
name|node
argument_list|(
name|n
argument_list|)
block|,
name|pathStartPos
argument_list|(
name|p
argument_list|)
block|,
name|message
argument_list|(
name|m
argument_list|)
block|,
name|handled
argument_list|(
argument|false
argument_list|)
block|{ }
operator|~
name|QDBusActivateObjectEvent
argument_list|()
block|;
name|void
name|placeMetaCall
argument_list|(
name|QObject
operator|*
argument_list|)
block|;
name|private
operator|:
name|QDBusConnection
name|connection
block|;
comment|// just for refcounting
name|QDBusConnectionPrivate
operator|::
name|ObjectTreeNode
name|node
block|;
name|int
name|pathStartPos
block|;
name|QDBusMessage
name|message
block|;
name|bool
name|handled
block|; }
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QDBusConnectionCallbackEvent
range|:
name|public
name|QEvent
block|{
name|public
operator|:
name|QDBusConnectionCallbackEvent
argument_list|()
operator|:
name|QEvent
argument_list|(
name|User
argument_list|)
block|,
name|subtype
argument_list|(
argument|Subtype(
literal|0
argument|)
argument_list|)
block|{ }
name|DBusWatch
operator|*
name|watch
block|;
expr|union
block|{
name|int
name|timerId
block|;
name|int
name|fd
block|;     }
block|;
name|int
name|extra
block|;      enum
name|Subtype
block|{
name|AddTimeout
operator|=
literal|0
block|,
name|KillTimer
block|,
name|AddWatch
block|,
comment|//RemoveWatch,
name|ToggleWatch
block|}
name|subtype
block|; }
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QT_END_NAMESPACE
name|Q_DECLARE_METATYPE
argument_list|(
name|QDBusSlotCache
argument_list|)
end_decl_stmt
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
end_unit
