begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QOBJECT_P_H
end_ifndef
begin_define
DECL|macro|QOBJECT_P_H
define|#
directive|define
name|QOBJECT_P_H
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
comment|// This file is not part of the Qt API.  It exists for the convenience
end_comment
begin_comment
comment|// of qapplication_*.cpp, qwidget*.cpp and qfiledialog.cpp.  This header
end_comment
begin_comment
comment|// file may change from version to version without notice, or even be removed.
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
file|"QtCore/qobject.h"
end_include
begin_include
include|#
directive|include
file|"QtCore/qpointer.h"
end_include
begin_include
include|#
directive|include
file|"QtCore/qsharedpointer.h"
end_include
begin_include
include|#
directive|include
file|"QtCore/qcoreevent.h"
end_include
begin_include
include|#
directive|include
file|"QtCore/qlist.h"
end_include
begin_include
include|#
directive|include
file|"QtCore/qvector.h"
end_include
begin_include
include|#
directive|include
file|"QtCore/qvariant.h"
end_include
begin_include
include|#
directive|include
file|"QtCore/qreadwritelock.h"
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QVariant
name|class
name|QVariant
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QThreadData
name|class
name|QThreadData
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QObjectConnectionListVector
name|class
name|QObjectConnectionListVector
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|namespace
name|QtSharedPointer
block|{
struct_decl|struct
name|ExternalRefCountData
struct_decl|;
block|}
end_decl_stmt
begin_comment
comment|/* for Qt Test */
end_comment
begin_struct
DECL|struct|QSignalSpyCallbackSet
struct|struct
name|QSignalSpyCallbackSet
block|{
DECL|typedef|BeginCallback
typedef|typedef
name|void
function_decl|(
modifier|*
name|BeginCallback
function_decl|)
parameter_list|(
name|QObject
modifier|*
name|caller
parameter_list|,
name|int
name|signal_or_method_index
parameter_list|,
name|void
modifier|*
modifier|*
name|argv
parameter_list|)
function_decl|;
DECL|typedef|EndCallback
typedef|typedef
name|void
function_decl|(
modifier|*
name|EndCallback
function_decl|)
parameter_list|(
name|QObject
modifier|*
name|caller
parameter_list|,
name|int
name|signal_or_method_index
parameter_list|)
function_decl|;
DECL|member|signal_begin_callback
name|BeginCallback
name|signal_begin_callback
decl_stmt|,
DECL|member|slot_begin_callback
name|slot_begin_callback
decl_stmt|;
DECL|member|signal_end_callback
name|EndCallback
name|signal_end_callback
decl_stmt|,
DECL|member|slot_end_callback
name|slot_end_callback
decl_stmt|;
block|}
struct|;
end_struct
begin_function_decl
name|void
name|Q_CORE_EXPORT
name|qt_register_signal_spy_callbacks
parameter_list|(
specifier|const
name|QSignalSpyCallbackSet
modifier|&
name|callback_set
parameter_list|)
function_decl|;
end_function_decl
begin_decl_stmt
specifier|extern
name|QSignalSpyCallbackSet
name|Q_CORE_EXPORT
name|qt_signal_spy_callback_set
decl_stmt|;
end_decl_stmt
begin_enum
DECL|enumerator|QObjectPrivateVersion
enum|enum
block|{
name|QObjectPrivateVersion
init|=
name|QT_VERSION
block|}
enum|;
end_enum
begin_decl_stmt
name|class
name|Q_CORE_EXPORT
name|QAbstractDeclarativeData
block|{
name|public
label|:
specifier|static
name|void
function_decl|(
modifier|*
name|destroyed
function_decl|)
parameter_list|(
name|QAbstractDeclarativeData
modifier|*
parameter_list|,
name|QObject
modifier|*
parameter_list|)
function_decl|;
specifier|static
name|void
function_decl|(
modifier|*
name|parentChanged
function_decl|)
parameter_list|(
name|QAbstractDeclarativeData
modifier|*
parameter_list|,
name|QObject
modifier|*
parameter_list|,
name|QObject
modifier|*
parameter_list|)
function_decl|;
specifier|static
name|void
function_decl|(
modifier|*
name|signalEmitted
function_decl|)
parameter_list|(
name|QAbstractDeclarativeData
modifier|*
parameter_list|,
name|QObject
modifier|*
parameter_list|,
name|int
parameter_list|,
name|void
modifier|*
modifier|*
parameter_list|)
function_decl|;
specifier|static
name|int
function_decl|(
modifier|*
name|receivers
function_decl|)
parameter_list|(
name|QAbstractDeclarativeData
modifier|*
parameter_list|,
specifier|const
name|QObject
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
specifier|static
name|bool
function_decl|(
modifier|*
name|isSignalConnected
function_decl|)
parameter_list|(
name|QAbstractDeclarativeData
modifier|*
parameter_list|,
specifier|const
name|QObject
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_decl_stmt
name|class
name|Q_CORE_EXPORT
name|QObjectPrivate
range|:
name|public
name|QObjectData
block|{
name|Q_DECLARE_PUBLIC
argument_list|(
argument|QObject
argument_list|)
name|public
operator|:
expr|struct
name|ExtraData
block|{
name|ExtraData
argument_list|()
block|{}
ifndef|#
directive|ifndef
name|QT_NO_USERDATA
name|QVector
operator|<
name|QObjectUserData
operator|*
operator|>
name|userData
block|;
endif|#
directive|endif
name|QList
operator|<
name|QByteArray
operator|>
name|propertyNames
block|;
name|QList
operator|<
name|QVariant
operator|>
name|propertyValues
block|;
name|QVector
operator|<
name|int
operator|>
name|runningTimers
block|;
name|QList
operator|<
name|QPointer
operator|<
name|QObject
operator|>
expr|>
name|eventFilters
block|;
name|QString
name|objectName
block|;     }
block|;
typedef|typedef
name|void
argument_list|(
operator|*
name|StaticMetaCallFunction
argument_list|)
argument_list|(
name|QObject
operator|*
argument_list|,
name|QMetaObject
operator|::
name|Call
argument_list|,
name|int
argument_list|,
name|void
operator|*
operator|*
argument_list|)
expr_stmt|;
block|struct
name|Connection
block|{
name|QObject
operator|*
name|sender
block|;
name|QObject
operator|*
name|receiver
block|;
expr|union
block|{
name|StaticMetaCallFunction
name|callFunction
block|;
name|QtPrivate
operator|::
name|QSlotObjectBase
operator|*
name|slotObj
block|;         }
block|;
comment|// The next pointer for the singly-linked ConnectionList
name|Connection
operator|*
name|nextConnectionList
block|;
comment|//senders linked list
name|Connection
operator|*
name|next
block|;
name|Connection
operator|*
operator|*
name|prev
block|;
name|QAtomicPointer
operator|<
specifier|const
name|int
operator|>
name|argumentTypes
block|;
name|QAtomicInt
name|ref_
block|;
name|ushort
name|method_offset
block|;
name|ushort
name|method_relative
block|;
name|uint
name|signal_index
operator|:
literal|27
block|;
comment|// In signal range (see QObjectPrivate::signalIndex())
name|ushort
name|connectionType
operator|:
literal|3
block|;
comment|// 0 == auto, 1 == direct, 2 == queued, 4 == blocking
name|ushort
name|isSlotObject
operator|:
literal|1
block|;
name|ushort
name|ownArgumentTypes
operator|:
literal|1
block|;
name|Connection
argument_list|()
operator|:
name|nextConnectionList
argument_list|(
literal|0
argument_list|)
block|,
name|ref_
argument_list|(
literal|2
argument_list|)
block|,
name|ownArgumentTypes
argument_list|(
argument|true
argument_list|)
block|{
comment|//ref_ is 2 for the use in the internal lists, and for the use in QMetaObject::Connection
block|}
operator|~
name|Connection
argument_list|()
block|;
name|int
name|method
argument_list|()
specifier|const
block|{
return|return
name|method_offset
operator|+
name|method_relative
return|;
block|}
name|void
name|ref
argument_list|()
block|{
name|ref_
operator|.
name|ref
argument_list|()
block|; }
name|void
name|deref
argument_list|()
block|{
if|if
condition|(
operator|!
name|ref_
operator|.
name|deref
argument_list|()
condition|)
block|{
name|Q_ASSERT
argument_list|(
operator|!
name|receiver
argument_list|)
expr_stmt|;
name|delete
name|this
decl_stmt|;
block|}
block|}
expr|}
block|;
comment|// ConnectionList is a singly-linked list
block|struct
name|ConnectionList
block|{
name|ConnectionList
argument_list|()
operator|:
name|first
argument_list|(
literal|0
argument_list|)
block|,
name|last
argument_list|(
literal|0
argument_list|)
block|{}
name|Connection
operator|*
name|first
block|;
name|Connection
operator|*
name|last
block|;     }
block|;      struct
name|Sender
block|{
name|QObject
operator|*
name|sender
block|;
name|int
name|signal
block|;
name|int
name|ref
block|;     }
block|;
name|QObjectPrivate
argument_list|(
argument|int version = QObjectPrivateVersion
argument_list|)
block|;
name|virtual
operator|~
name|QObjectPrivate
argument_list|()
block|;
name|void
name|deleteChildren
argument_list|()
block|;
name|void
name|setParent_helper
argument_list|(
name|QObject
operator|*
argument_list|)
block|;
name|void
name|moveToThread_helper
argument_list|()
block|;
name|void
name|setThreadData_helper
argument_list|(
name|QThreadData
operator|*
name|currentData
argument_list|,
name|QThreadData
operator|*
name|targetData
argument_list|)
block|;
name|void
name|_q_reregisterTimers
argument_list|(
name|void
operator|*
name|pointer
argument_list|)
block|;
name|bool
name|isSender
argument_list|(
argument|const QObject *receiver
argument_list|,
argument|const char *signal
argument_list|)
specifier|const
block|;
name|QObjectList
name|receiverList
argument_list|(
argument|const char *signal
argument_list|)
specifier|const
block|;
name|QObjectList
name|senderList
argument_list|()
specifier|const
block|;
name|void
name|addConnection
argument_list|(
argument|int signal
argument_list|,
argument|Connection *c
argument_list|)
block|;
name|void
name|cleanConnectionLists
argument_list|()
block|;
specifier|static
specifier|inline
name|Sender
operator|*
name|setCurrentSender
argument_list|(
name|QObject
operator|*
name|receiver
argument_list|,
name|Sender
operator|*
name|sender
argument_list|)
block|;
specifier|static
specifier|inline
name|void
name|resetCurrentSender
argument_list|(
name|QObject
operator|*
name|receiver
argument_list|,
name|Sender
operator|*
name|currentSender
argument_list|,
name|Sender
operator|*
name|previousSender
argument_list|)
block|;
specifier|static
name|QObjectPrivate
operator|*
name|get
argument_list|(
argument|QObject *o
argument_list|)
block|{
return|return
name|o
operator|->
name|d_func
argument_list|()
return|;
block|}
name|int
name|senderSignalIndex
argument_list|()
specifier|const
block|;
name|int
name|signalIndex
argument_list|(
argument|const char *signalName
argument_list|,
argument|const QMetaObject **meta =
literal|0
argument_list|)
specifier|const
block|;
specifier|inline
name|bool
name|isSignalConnected
argument_list|(
argument|uint signalIdx
argument_list|)
specifier|const
block|;
comment|// To allow abitrary objects to call connectNotify()/disconnectNotify() without making
comment|// the API public in QObject. This is used by QQmlNotifierEndpoint.
specifier|inline
name|void
name|connectNotify
argument_list|(
specifier|const
name|QMetaMethod
operator|&
name|signal
argument_list|)
block|;
specifier|inline
name|void
name|disconnectNotify
argument_list|(
specifier|const
name|QMetaMethod
operator|&
name|signal
argument_list|)
block|;
name|public
operator|:
name|ExtraData
operator|*
name|extraData
block|;
comment|// extra data set by the user
name|QThreadData
operator|*
name|threadData
block|;
comment|// id of the thread that owns the object
name|QObjectConnectionListVector
operator|*
name|connectionLists
block|;
name|Connection
operator|*
name|senders
block|;
comment|// linked list of connections connected to this object
name|Sender
operator|*
name|currentSender
block|;
comment|// object currently activating the object
name|mutable
name|quint32
name|connectedSignals
index|[
literal|2
index|]
block|;
expr|union
block|{
name|QObject
operator|*
name|currentChildBeingDeleted
block|;
name|QAbstractDeclarativeData
operator|*
name|declarativeData
block|;
comment|//extra data used by the declarative module
block|}
block|;
comment|// these objects are all used to indicate that a QObject was deleted
comment|// plus QPointer, which keeps a separate list
name|QAtomicPointer
operator|<
name|QtSharedPointer
operator|::
name|ExternalRefCountData
operator|>
name|sharedRefcount
block|; }
decl_stmt|;
end_decl_stmt
begin_comment
comment|/*! \internal    Returns true if the signal with index \a signal_index from object \a sender is connected.   Signals with indices above a certain range are always considered connected (see connectedSignals   in QObjectPrivate). If a signal spy is installed, all signals are considered connected.    \a signal_index must be the index returned by QObjectPrivate::signalIndex; */
end_comment
begin_expr_stmt
DECL|function|isSignalConnected
specifier|inline
name|bool
name|QObjectPrivate
operator|::
name|isSignalConnected
argument_list|(
argument|uint signal_index
argument_list|)
specifier|const
block|{
return|return
name|signal_index
operator|>=
sizeof|sizeof
argument_list|(
name|connectedSignals
argument_list|)
operator|*
literal|8
operator|||
operator|(
name|connectedSignals
index|[
name|signal_index
operator|>>
literal|5
index|]
operator|&
operator|(
literal|1
operator|<<
operator|(
name|signal_index
operator|&
literal|0x1f
operator|)
operator|)
operator|||
operator|(
name|declarativeData
operator|&&
name|QAbstractDeclarativeData
operator|::
name|isSignalConnected
operator|&&
name|QAbstractDeclarativeData
operator|::
name|isSignalConnected
argument_list|(
name|declarativeData
argument_list|,
name|q_func
argument_list|()
argument_list|,
name|signal_index
argument_list|)
operator|)
operator|||
name|qt_signal_spy_callback_set
operator|.
name|signal_begin_callback
operator|||
name|qt_signal_spy_callback_set
operator|.
name|signal_end_callback
operator|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|setCurrentSender
specifier|inline
name|QObjectPrivate
operator|::
name|Sender
operator|*
name|QObjectPrivate
operator|::
name|setCurrentSender
argument_list|(
argument|QObject *receiver
argument_list|,
argument|Sender *sender
argument_list|)
block|{
name|Sender
operator|*
name|previousSender
operator|=
name|receiver
operator|->
name|d_func
argument_list|()
operator|->
name|currentSender
block|;
name|receiver
operator|->
name|d_func
argument_list|()
operator|->
name|currentSender
operator|=
name|sender
block|;
return|return
name|previousSender
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|resetCurrentSender
specifier|inline
name|void
name|QObjectPrivate
operator|::
name|resetCurrentSender
argument_list|(
argument|QObject *receiver
argument_list|,
argument|Sender *currentSender
argument_list|,
argument|Sender *previousSender
argument_list|)
block|{
comment|// ref is set to zero when this object is deleted during the metacall
if|if
condition|(
name|currentSender
operator|->
name|ref
operator|==
literal|1
condition|)
name|receiver
operator|->
name|d_func
argument_list|()
operator|->
name|currentSender
operator|=
name|previousSender
expr_stmt|;
end_expr_stmt
begin_comment
comment|// if we've recursed, we need to tell the caller about the objects deletion
end_comment
begin_if
if|if
condition|(
name|previousSender
condition|)
name|previousSender
operator|->
name|ref
operator|=
name|currentSender
operator|->
name|ref
expr_stmt|;
end_if
begin_expr_stmt
unit|}  inline
DECL|function|connectNotify
name|void
name|QObjectPrivate
operator|::
name|connectNotify
argument_list|(
argument|const QMetaMethod&signal
argument_list|)
block|{
name|q_ptr
operator|->
name|connectNotify
argument_list|(
name|signal
argument_list|)
block|; }
DECL|function|disconnectNotify
specifier|inline
name|void
name|QObjectPrivate
operator|::
name|disconnectNotify
argument_list|(
argument|const QMetaMethod&signal
argument_list|)
block|{
name|q_ptr
operator|->
name|disconnectNotify
argument_list|(
name|signal
argument_list|)
block|; }
name|Q_DECLARE_TYPEINFO
argument_list|(
name|QObjectPrivate
operator|::
name|Connection
argument_list|,
name|Q_MOVABLE_TYPE
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|Q_DECLARE_TYPEINFO
argument_list|(
name|QObjectPrivate
operator|::
name|Sender
argument_list|,
name|Q_MOVABLE_TYPE
argument_list|)
expr_stmt|;
end_expr_stmt
begin_decl_stmt
DECL|variable|QSemaphore
name|class
name|QSemaphore
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_CORE_EXPORT
name|QMetaCallEvent
range|:
name|public
name|QEvent
block|{
name|public
operator|:
name|QMetaCallEvent
argument_list|(
argument|ushort method_offset
argument_list|,
argument|ushort method_relative
argument_list|,
argument|QObjectPrivate::StaticMetaCallFunction callFunction
argument_list|,
argument|const QObject *sender
argument_list|,
argument|int signalId
argument_list|,
argument|int nargs =
literal|0
argument_list|,
argument|int *types =
literal|0
argument_list|,
argument|void **args =
literal|0
argument_list|,
argument|QSemaphore *semaphore =
literal|0
argument_list|)
block|;
comment|/*! \internal         \a signalId is in the signal index range (see QObjectPrivate::signalIndex()).     */
name|QMetaCallEvent
argument_list|(
argument|QtPrivate::QSlotObjectBase *slotObj
argument_list|,
argument|const QObject *sender
argument_list|,
argument|int signalId
argument_list|,
argument|int nargs =
literal|0
argument_list|,
argument|int *types =
literal|0
argument_list|,
argument|void **args =
literal|0
argument_list|,
argument|QSemaphore *semaphore =
literal|0
argument_list|)
block|;
operator|~
name|QMetaCallEvent
argument_list|()
block|;
specifier|inline
name|int
name|id
argument_list|()
specifier|const
block|{
return|return
name|method_offset_
operator|+
name|method_relative_
return|;
block|}
specifier|inline
specifier|const
name|QObject
operator|*
name|sender
argument_list|()
specifier|const
block|{
return|return
name|sender_
return|;
block|}
specifier|inline
name|int
name|signalId
argument_list|()
specifier|const
block|{
return|return
name|signalId_
return|;
block|}
specifier|inline
name|void
operator|*
operator|*
name|args
argument_list|()
specifier|const
block|{
return|return
name|args_
return|;
block|}
name|virtual
name|void
name|placeMetaCall
argument_list|(
name|QObject
operator|*
name|object
argument_list|)
block|;
name|private
operator|:
name|QtPrivate
operator|::
name|QSlotObjectBase
operator|*
name|slotObj_
block|;
specifier|const
name|QObject
operator|*
name|sender_
block|;
name|int
name|signalId_
block|;
name|int
name|nargs_
block|;
name|int
operator|*
name|types_
block|;
name|void
operator|*
operator|*
name|args_
block|;
name|QSemaphore
operator|*
name|semaphore_
block|;
name|QObjectPrivate
operator|::
name|StaticMetaCallFunction
name|callFunction_
block|;
name|ushort
name|method_offset_
block|;
name|ushort
name|method_relative_
block|; }
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QBoolBlocker
block|{
name|Q_DISABLE_COPY
argument_list|(
argument|QBoolBlocker
argument_list|)
name|public
label|:
name|explicit
specifier|inline
name|QBoolBlocker
argument_list|(
argument|bool&b
argument_list|,
argument|bool value=true
argument_list|)
operator|:
name|block
argument_list|(
name|b
argument_list|)
operator|,
name|reset
argument_list|(
argument|b
argument_list|)
block|{
name|block
operator|=
name|value
block|;}
specifier|inline
operator|~
name|QBoolBlocker
argument_list|()
block|{
name|block
operator|=
name|reset
block|; }
name|private
operator|:
name|bool
operator|&
name|block
expr_stmt|;
name|bool
name|reset
decl_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_function_decl
name|void
name|Q_CORE_EXPORT
name|qDeleteInEventHandler
parameter_list|(
name|QObject
modifier|*
name|o
parameter_list|)
function_decl|;
end_function_decl
begin_struct_decl
struct_decl|struct
name|QAbstractDynamicMetaObject
struct_decl|;
end_struct_decl
begin_struct
DECL|struct|QDynamicMetaObjectData
struct|struct
name|Q_CORE_EXPORT
name|QDynamicMetaObjectData
block|{
DECL|function|~QDynamicMetaObjectData
name|virtual
operator|~
name|QDynamicMetaObjectData
argument_list|()
block|{}
DECL|function|objectDestroyed
name|virtual
name|void
name|objectDestroyed
argument_list|(
argument|QObject *
argument_list|)
block|{
name|delete
name|this
block|; }
name|virtual
name|QAbstractDynamicMetaObject
operator|*
name|toDynamicMetaObject
argument_list|(
name|QObject
operator|*
argument_list|)
operator|=
literal|0
expr_stmt|;
name|virtual
name|int
name|metaCall
argument_list|(
name|QObject
operator|*
argument_list|,
name|QMetaObject
operator|::
name|Call
argument_list|,
name|int
name|_id
argument_list|,
name|void
operator|*
operator|*
argument_list|)
init|=
literal|0
decl_stmt|;
block|}
struct|;
end_struct
begin_decl_stmt
DECL|variable|QDynamicMetaObjectData
DECL|struct|QMetaObject
name|struct
name|Q_CORE_EXPORT
name|QAbstractDynamicMetaObject
range|:
name|public
name|QDynamicMetaObjectData
decl_stmt|,
name|public
name|QMetaObject
block|{
DECL|function|toDynamicMetaObject
name|virtual
name|QAbstractDynamicMetaObject
modifier|*
name|toDynamicMetaObject
parameter_list|(
name|QObject
modifier|*
parameter_list|)
block|{
return|return
name|this
return|;
block|}
DECL|function|createProperty
name|virtual
name|int
name|createProperty
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
block|{
return|return
operator|-
literal|1
return|;
block|}
DECL|function|metaCall
name|virtual
name|int
name|metaCall
argument_list|(
name|QObject
operator|*
argument_list|,
name|QMetaObject
operator|::
name|Call
name|c
argument_list|,
name|int
name|_id
argument_list|,
name|void
operator|*
operator|*
name|a
argument_list|)
block|{
return|return
name|metaCall
argument_list|(
name|c
argument_list|,
name|_id
argument_list|,
name|a
argument_list|)
return|;
block|}
DECL|function|metaCall
name|virtual
name|int
name|metaCall
argument_list|(
name|QMetaObject
operator|::
name|Call
argument_list|,
name|int
name|_id
argument_list|,
name|void
operator|*
operator|*
argument_list|)
block|{
return|return
name|_id
return|;
block|}
comment|// Compat overload
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QOBJECT_P_H
end_comment
end_unit
