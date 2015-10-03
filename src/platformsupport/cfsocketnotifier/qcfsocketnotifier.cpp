begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qcfsocketnotifier_p.h"
end_include
begin_include
include|#
directive|include
file|<QtGui/qguiapplication.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qsocketnotifier.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qthread.h>
end_include
begin_comment
comment|/**************************************************************************     Socket Notifiers  *************************************************************************/
end_comment
begin_function
DECL|function|qt_mac_socket_callback
name|void
name|qt_mac_socket_callback
parameter_list|(
name|CFSocketRef
name|s
parameter_list|,
name|CFSocketCallBackType
name|callbackType
parameter_list|,
name|CFDataRef
parameter_list|,
specifier|const
name|void
modifier|*
parameter_list|,
name|void
modifier|*
name|info
parameter_list|)
block|{
name|QCFSocketNotifier
modifier|*
name|cfSocketNotifier
init|=
cast|static_cast
argument_list|<
name|QCFSocketNotifier
operator|*
argument_list|>
argument_list|(
name|info
argument_list|)
decl_stmt|;
name|int
name|nativeSocket
init|=
name|CFSocketGetNative
argument_list|(
name|s
argument_list|)
decl_stmt|;
name|MacSocketInfo
modifier|*
name|socketInfo
init|=
name|cfSocketNotifier
operator|->
name|macSockets
operator|.
name|value
argument_list|(
name|nativeSocket
argument_list|)
decl_stmt|;
name|QEvent
name|notifierEvent
argument_list|(
name|QEvent
operator|::
name|SockAct
argument_list|)
decl_stmt|;
comment|// There is a race condition that happen where we disable the notifier and
comment|// the kernel still has a notification to pass on. We then get this
comment|// notification after we've successfully disabled the CFSocket, but our Qt
comment|// notifier is now gone. The upshot is we have to check the notifier
comment|// every time.
if|if
condition|(
name|callbackType
operator|==
name|kCFSocketReadCallBack
condition|)
block|{
if|if
condition|(
name|socketInfo
operator|->
name|readNotifier
condition|)
name|QGuiApplication
operator|::
name|sendEvent
argument_list|(
name|socketInfo
operator|->
name|readNotifier
argument_list|,
operator|&
name|notifierEvent
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|callbackType
operator|==
name|kCFSocketWriteCallBack
condition|)
block|{
if|if
condition|(
name|socketInfo
operator|->
name|writeNotifier
condition|)
name|QGuiApplication
operator|::
name|sendEvent
argument_list|(
name|socketInfo
operator|->
name|writeNotifier
argument_list|,
operator|&
name|notifierEvent
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|cfSocketNotifier
operator|->
name|maybeCancelWaitForMoreEvents
condition|)
name|cfSocketNotifier
operator|->
name|maybeCancelWaitForMoreEvents
argument_list|(
name|cfSocketNotifier
operator|->
name|eventDispatcher
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*     Adds a loop source for the given socket to the current run loop. */
end_comment
begin_function
DECL|function|qt_mac_add_socket_to_runloop
name|CFRunLoopSourceRef
name|qt_mac_add_socket_to_runloop
parameter_list|(
specifier|const
name|CFSocketRef
name|socket
parameter_list|)
block|{
name|CFRunLoopSourceRef
name|loopSource
init|=
name|CFSocketCreateRunLoopSource
argument_list|(
name|kCFAllocatorDefault
argument_list|,
name|socket
argument_list|,
literal|0
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|loopSource
condition|)
return|return
literal|0
return|;
name|CFRunLoopAddSource
argument_list|(
name|CFRunLoopGetMain
argument_list|()
argument_list|,
name|loopSource
argument_list|,
name|kCFRunLoopCommonModes
argument_list|)
expr_stmt|;
return|return
name|loopSource
return|;
block|}
end_function
begin_comment
comment|/*     Removes the loop source for the given socket from the current run loop. */
end_comment
begin_function
DECL|function|qt_mac_remove_socket_from_runloop
name|void
name|qt_mac_remove_socket_from_runloop
parameter_list|(
specifier|const
name|CFSocketRef
name|socket
parameter_list|,
name|CFRunLoopSourceRef
name|runloop
parameter_list|)
block|{
name|Q_ASSERT
argument_list|(
name|runloop
argument_list|)
expr_stmt|;
name|CFRunLoopRemoveSource
argument_list|(
name|CFRunLoopGetMain
argument_list|()
argument_list|,
name|runloop
argument_list|,
name|kCFRunLoopCommonModes
argument_list|)
expr_stmt|;
name|CFSocketDisableCallBacks
argument_list|(
name|socket
argument_list|,
name|kCFSocketReadCallBack
argument_list|)
expr_stmt|;
name|CFSocketDisableCallBacks
argument_list|(
name|socket
argument_list|,
name|kCFSocketWriteCallBack
argument_list|)
expr_stmt|;
name|CFRunLoopSourceInvalidate
argument_list|(
name|runloop
argument_list|)
expr_stmt|;
block|}
end_function
begin_constructor
DECL|function|QCFSocketNotifier
name|QCFSocketNotifier
operator|::
name|QCFSocketNotifier
parameter_list|()
member_init_list|:
name|eventDispatcher
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|maybeCancelWaitForMoreEvents
argument_list|(
literal|0
argument_list|)
block|{  }
end_constructor
begin_destructor
DECL|function|~QCFSocketNotifier
name|QCFSocketNotifier
operator|::
name|~
name|QCFSocketNotifier
parameter_list|()
block|{  }
end_destructor
begin_function
DECL|function|setHostEventDispatcher
name|void
name|QCFSocketNotifier
operator|::
name|setHostEventDispatcher
parameter_list|(
name|QAbstractEventDispatcher
modifier|*
name|hostEventDispacher
parameter_list|)
block|{
name|eventDispatcher
operator|=
name|hostEventDispacher
expr_stmt|;
block|}
end_function
begin_function
DECL|function|setMaybeCancelWaitForMoreEventsCallback
name|void
name|QCFSocketNotifier
operator|::
name|setMaybeCancelWaitForMoreEventsCallback
parameter_list|(
name|MaybeCancelWaitForMoreEventsFn
name|callBack
parameter_list|)
block|{
name|maybeCancelWaitForMoreEvents
operator|=
name|callBack
expr_stmt|;
block|}
end_function
begin_function
DECL|function|registerSocketNotifier
name|void
name|QCFSocketNotifier
operator|::
name|registerSocketNotifier
parameter_list|(
name|QSocketNotifier
modifier|*
name|notifier
parameter_list|)
block|{
name|Q_ASSERT
argument_list|(
name|notifier
argument_list|)
expr_stmt|;
name|int
name|nativeSocket
init|=
name|notifier
operator|->
name|socket
argument_list|()
decl_stmt|;
name|int
name|type
init|=
name|notifier
operator|->
name|type
argument_list|()
decl_stmt|;
ifndef|#
directive|ifndef
name|QT_NO_DEBUG
if|if
condition|(
name|nativeSocket
argument_list|<
literal|0
operator|||
name|nativeSocket
argument_list|>
name|FD_SETSIZE
condition|)
block|{
name|qWarning
argument_list|(
literal|"QSocketNotifier: Internal error"
argument_list|)
expr_stmt|;
return|return;
block|}
elseif|else
if|if
condition|(
name|notifier
operator|->
name|thread
argument_list|()
operator|!=
name|eventDispatcher
operator|->
name|thread
argument_list|()
operator|||
name|eventDispatcher
operator|->
name|thread
argument_list|()
operator|!=
name|QThread
operator|::
name|currentThread
argument_list|()
condition|)
block|{
name|qWarning
argument_list|(
literal|"QSocketNotifier: socket notifiers cannot be enabled from another thread"
argument_list|)
expr_stmt|;
return|return;
block|}
endif|#
directive|endif
if|if
condition|(
name|type
operator|==
name|QSocketNotifier
operator|::
name|Exception
condition|)
block|{
name|qWarning
argument_list|(
literal|"QSocketNotifier::Exception is not supported on iOS"
argument_list|)
expr_stmt|;
return|return;
block|}
comment|// Check if we have a CFSocket for the native socket, create one if not.
name|MacSocketInfo
modifier|*
name|socketInfo
init|=
name|macSockets
operator|.
name|value
argument_list|(
name|nativeSocket
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|socketInfo
condition|)
block|{
name|socketInfo
operator|=
operator|new
name|MacSocketInfo
argument_list|()
expr_stmt|;
comment|// Create CFSocket, specify that we want both read and write callbacks (the callbacks
comment|// are enabled/disabled later on).
specifier|const
name|int
name|callbackTypes
init|=
name|kCFSocketReadCallBack
operator||
name|kCFSocketWriteCallBack
decl_stmt|;
name|CFSocketContext
name|context
init|=
block|{
literal|0
block|,
name|this
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|}
decl_stmt|;
name|socketInfo
operator|->
name|socket
operator|=
name|CFSocketCreateWithNative
argument_list|(
name|kCFAllocatorDefault
argument_list|,
name|nativeSocket
argument_list|,
name|callbackTypes
argument_list|,
name|qt_mac_socket_callback
argument_list|,
operator|&
name|context
argument_list|)
expr_stmt|;
if|if
condition|(
name|CFSocketIsValid
argument_list|(
name|socketInfo
operator|->
name|socket
argument_list|)
operator|==
literal|false
condition|)
block|{
name|qWarning
argument_list|(
literal|"QEventDispatcherMac::registerSocketNotifier: Failed to create CFSocket"
argument_list|)
expr_stmt|;
return|return;
block|}
name|CFOptionFlags
name|flags
init|=
name|CFSocketGetSocketFlags
argument_list|(
name|socketInfo
operator|->
name|socket
argument_list|)
decl_stmt|;
name|flags
operator||=
name|kCFSocketAutomaticallyReenableWriteCallBack
expr_stmt|;
comment|//QSocketNotifier stays enabled after a write
name|flags
operator|&=
operator|~
name|kCFSocketCloseOnInvalidate
expr_stmt|;
comment|//QSocketNotifier doesn't close the socket upon destruction/invalidation
name|CFSocketSetSocketFlags
argument_list|(
name|socketInfo
operator|->
name|socket
argument_list|,
name|flags
argument_list|)
expr_stmt|;
comment|// Add CFSocket to runloop.
if|if
condition|(
operator|!
operator|(
name|socketInfo
operator|->
name|runloop
operator|=
name|qt_mac_add_socket_to_runloop
argument_list|(
name|socketInfo
operator|->
name|socket
argument_list|)
operator|)
condition|)
block|{
name|qWarning
argument_list|(
literal|"QEventDispatcherMac::registerSocketNotifier: Failed to add CFSocket to runloop"
argument_list|)
expr_stmt|;
name|CFSocketInvalidate
argument_list|(
name|socketInfo
operator|->
name|socket
argument_list|)
expr_stmt|;
name|CFRelease
argument_list|(
name|socketInfo
operator|->
name|socket
argument_list|)
expr_stmt|;
return|return;
block|}
comment|// Disable both callback types by default. This must be done after
comment|// we add the CFSocket to the runloop, or else these calls will have
comment|// no effect.
name|CFSocketDisableCallBacks
argument_list|(
name|socketInfo
operator|->
name|socket
argument_list|,
name|kCFSocketReadCallBack
argument_list|)
expr_stmt|;
name|CFSocketDisableCallBacks
argument_list|(
name|socketInfo
operator|->
name|socket
argument_list|,
name|kCFSocketWriteCallBack
argument_list|)
expr_stmt|;
name|macSockets
operator|.
name|insert
argument_list|(
name|nativeSocket
argument_list|,
name|socketInfo
argument_list|)
expr_stmt|;
block|}
comment|// Increment read/write counters and select enable callbacks if necessary.
if|if
condition|(
name|type
operator|==
name|QSocketNotifier
operator|::
name|Read
condition|)
block|{
name|Q_ASSERT
argument_list|(
name|socketInfo
operator|->
name|readNotifier
operator|==
literal|0
argument_list|)
expr_stmt|;
name|socketInfo
operator|->
name|readNotifier
operator|=
name|notifier
expr_stmt|;
name|CFSocketEnableCallBacks
argument_list|(
name|socketInfo
operator|->
name|socket
argument_list|,
name|kCFSocketReadCallBack
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|type
operator|==
name|QSocketNotifier
operator|::
name|Write
condition|)
block|{
name|Q_ASSERT
argument_list|(
name|socketInfo
operator|->
name|writeNotifier
operator|==
literal|0
argument_list|)
expr_stmt|;
name|socketInfo
operator|->
name|writeNotifier
operator|=
name|notifier
expr_stmt|;
name|CFSocketEnableCallBacks
argument_list|(
name|socketInfo
operator|->
name|socket
argument_list|,
name|kCFSocketWriteCallBack
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|unregisterSocketNotifier
name|void
name|QCFSocketNotifier
operator|::
name|unregisterSocketNotifier
parameter_list|(
name|QSocketNotifier
modifier|*
name|notifier
parameter_list|)
block|{
name|Q_ASSERT
argument_list|(
name|notifier
argument_list|)
expr_stmt|;
name|int
name|nativeSocket
init|=
name|notifier
operator|->
name|socket
argument_list|()
decl_stmt|;
name|int
name|type
init|=
name|notifier
operator|->
name|type
argument_list|()
decl_stmt|;
ifndef|#
directive|ifndef
name|QT_NO_DEBUG
if|if
condition|(
name|nativeSocket
argument_list|<
literal|0
operator|||
name|nativeSocket
argument_list|>
name|FD_SETSIZE
condition|)
block|{
name|qWarning
argument_list|(
literal|"QSocketNotifier: Internal error"
argument_list|)
expr_stmt|;
return|return;
block|}
elseif|else
if|if
condition|(
name|notifier
operator|->
name|thread
argument_list|()
operator|!=
name|eventDispatcher
operator|->
name|thread
argument_list|()
operator|||
name|eventDispatcher
operator|->
name|thread
argument_list|()
operator|!=
name|QThread
operator|::
name|currentThread
argument_list|()
condition|)
block|{
name|qWarning
argument_list|(
literal|"QSocketNotifier: socket notifiers cannot be disabled from another thread"
argument_list|)
expr_stmt|;
return|return;
block|}
endif|#
directive|endif
if|if
condition|(
name|type
operator|==
name|QSocketNotifier
operator|::
name|Exception
condition|)
block|{
name|qWarning
argument_list|(
literal|"QSocketNotifier::Exception is not supported on iOS"
argument_list|)
expr_stmt|;
return|return;
block|}
name|MacSocketInfo
modifier|*
name|socketInfo
init|=
name|macSockets
operator|.
name|value
argument_list|(
name|nativeSocket
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|socketInfo
condition|)
block|{
name|qWarning
argument_list|(
literal|"QEventDispatcherMac::unregisterSocketNotifier: Tried to unregister a not registered notifier"
argument_list|)
expr_stmt|;
return|return;
block|}
comment|// Decrement read/write counters and disable callbacks if necessary.
if|if
condition|(
name|type
operator|==
name|QSocketNotifier
operator|::
name|Read
condition|)
block|{
name|Q_ASSERT
argument_list|(
name|notifier
operator|==
name|socketInfo
operator|->
name|readNotifier
argument_list|)
expr_stmt|;
name|socketInfo
operator|->
name|readNotifier
operator|=
literal|0
expr_stmt|;
name|CFSocketDisableCallBacks
argument_list|(
name|socketInfo
operator|->
name|socket
argument_list|,
name|kCFSocketReadCallBack
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|type
operator|==
name|QSocketNotifier
operator|::
name|Write
condition|)
block|{
name|Q_ASSERT
argument_list|(
name|notifier
operator|==
name|socketInfo
operator|->
name|writeNotifier
argument_list|)
expr_stmt|;
name|socketInfo
operator|->
name|writeNotifier
operator|=
literal|0
expr_stmt|;
name|CFSocketDisableCallBacks
argument_list|(
name|socketInfo
operator|->
name|socket
argument_list|,
name|kCFSocketWriteCallBack
argument_list|)
expr_stmt|;
block|}
comment|// Remove CFSocket from runloop if this was the last QSocketNotifier.
if|if
condition|(
name|socketInfo
operator|->
name|readNotifier
operator|==
literal|0
operator|&&
name|socketInfo
operator|->
name|writeNotifier
operator|==
literal|0
condition|)
block|{
if|if
condition|(
name|CFSocketIsValid
argument_list|(
name|socketInfo
operator|->
name|socket
argument_list|)
condition|)
name|qt_mac_remove_socket_from_runloop
argument_list|(
name|socketInfo
operator|->
name|socket
argument_list|,
name|socketInfo
operator|->
name|runloop
argument_list|)
expr_stmt|;
name|CFRunLoopSourceInvalidate
argument_list|(
name|socketInfo
operator|->
name|runloop
argument_list|)
expr_stmt|;
name|CFRelease
argument_list|(
name|socketInfo
operator|->
name|runloop
argument_list|)
expr_stmt|;
name|CFSocketInvalidate
argument_list|(
name|socketInfo
operator|->
name|socket
argument_list|)
expr_stmt|;
name|CFRelease
argument_list|(
name|socketInfo
operator|->
name|socket
argument_list|)
expr_stmt|;
operator|delete
name|socketInfo
expr_stmt|;
name|macSockets
operator|.
name|remove
argument_list|(
name|nativeSocket
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|removeSocketNotifiers
name|void
name|QCFSocketNotifier
operator|::
name|removeSocketNotifiers
parameter_list|()
block|{
comment|// Remove CFSockets from the runloop.
for|for
control|(
name|MacSocketHash
operator|::
name|ConstIterator
name|it
init|=
name|macSockets
operator|.
name|constBegin
argument_list|()
init|;
name|it
operator|!=
name|macSockets
operator|.
name|constEnd
argument_list|()
condition|;
operator|++
name|it
control|)
block|{
name|MacSocketInfo
modifier|*
name|socketInfo
init|=
operator|(
operator|*
name|it
operator|)
decl_stmt|;
if|if
condition|(
name|CFSocketIsValid
argument_list|(
name|socketInfo
operator|->
name|socket
argument_list|)
condition|)
block|{
name|qt_mac_remove_socket_from_runloop
argument_list|(
name|socketInfo
operator|->
name|socket
argument_list|,
name|socketInfo
operator|->
name|runloop
argument_list|)
expr_stmt|;
name|CFRunLoopSourceInvalidate
argument_list|(
name|socketInfo
operator|->
name|runloop
argument_list|)
expr_stmt|;
name|CFRelease
argument_list|(
name|socketInfo
operator|->
name|runloop
argument_list|)
expr_stmt|;
name|CFSocketInvalidate
argument_list|(
name|socketInfo
operator|->
name|socket
argument_list|)
expr_stmt|;
name|CFRelease
argument_list|(
name|socketInfo
operator|->
name|socket
argument_list|)
expr_stmt|;
block|}
block|}
block|}
end_function
end_unit
