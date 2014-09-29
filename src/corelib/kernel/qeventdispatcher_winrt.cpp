begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2014 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia. For licensing terms and ** conditions see http://qt.digia.com/licensing. For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights. These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qeventdispatcher_winrt_p.h"
end_include
begin_include
include|#
directive|include
file|<QtCore/QCoreApplication>
end_include
begin_include
include|#
directive|include
file|<QtCore/QThread>
end_include
begin_include
include|#
directive|include
file|<QtCore/QHash>
end_include
begin_include
include|#
directive|include
file|<QtCore/qfunctions_winrt.h>
end_include
begin_include
include|#
directive|include
file|<private/qabstracteventdispatcher_p.h>
end_include
begin_include
include|#
directive|include
file|<private/qcoreapplication_p.h>
end_include
begin_include
include|#
directive|include
file|<wrl.h>
end_include
begin_include
include|#
directive|include
file|<windows.foundation.h>
end_include
begin_include
include|#
directive|include
file|<windows.system.threading.h>
end_include
begin_include
include|#
directive|include
file|<windows.ui.core.h>
end_include
begin_include
include|#
directive|include
file|<windows.applicationmodel.core.h>
end_include
begin_using
using|using
namespace|namespace
name|Microsoft
operator|::
name|WRL
namespace|;
end_using
begin_using
using|using
namespace|namespace
name|Microsoft
operator|::
name|WRL
operator|::
name|Wrappers
namespace|;
end_using
begin_using
using|using
namespace|namespace
name|ABI
operator|::
name|Windows
operator|::
name|System
operator|::
name|Threading
namespace|;
end_using
begin_using
using|using
namespace|namespace
name|ABI
operator|::
name|Windows
operator|::
name|Foundation
namespace|;
end_using
begin_using
using|using
namespace|namespace
name|ABI
operator|::
name|Windows
operator|::
name|UI
operator|::
name|Core
namespace|;
end_using
begin_using
using|using
namespace|namespace
name|ABI
operator|::
name|Windows
operator|::
name|ApplicationModel
operator|::
name|Core
namespace|;
end_using
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_class
DECL|class|QZeroTimerEvent
class|class
name|QZeroTimerEvent
super|:
specifier|public
name|QTimerEvent
block|{
public|public:
DECL|function|QZeroTimerEvent
specifier|explicit
specifier|inline
name|QZeroTimerEvent
parameter_list|(
name|int
name|timerId
parameter_list|)
member_init_list|:
name|QTimerEvent
argument_list|(
name|timerId
argument_list|)
block|{
name|t
operator|=
name|QEvent
operator|::
name|ZeroTimerEvent
expr_stmt|;
block|}
block|}
class|;
end_class
begin_struct
DECL|struct|WinRTTimerInfo
struct|struct
name|WinRTTimerInfo
comment|// internal timer info
block|{
DECL|function|WinRTTimerInfo
name|WinRTTimerInfo
parameter_list|(
name|int
name|timerId
parameter_list|,
name|int
name|timerInterval
parameter_list|,
name|Qt
operator|::
name|TimerType
name|timerType
parameter_list|,
name|QObject
modifier|*
name|object
parameter_list|,
name|QEventDispatcherWinRT
modifier|*
name|dispatcher
parameter_list|)
member_init_list|:
name|isFinished
argument_list|(
literal|false
argument_list|)
member_init_list|,
name|id
argument_list|(
name|timerId
argument_list|)
member_init_list|,
name|interval
argument_list|(
name|timerInterval
argument_list|)
member_init_list|,
name|timerType
argument_list|(
name|timerType
argument_list|)
member_init_list|,
name|obj
argument_list|(
name|object
argument_list|)
member_init_list|,
name|inTimerEvent
argument_list|(
literal|false
argument_list|)
member_init_list|,
name|dispatcher
argument_list|(
name|dispatcher
argument_list|)
block|{     }
DECL|function|cancel
name|void
name|cancel
parameter_list|()
block|{
if|if
condition|(
name|isFinished
condition|)
block|{
operator|delete
name|this
expr_stmt|;
return|return;
block|}
name|isFinished
operator|=
literal|true
expr_stmt|;
if|if
condition|(
operator|!
name|timer
condition|)
return|return;
name|HRESULT
name|hr
init|=
name|timer
operator|->
name|Cancel
argument_list|()
decl_stmt|;
name|RETURN_VOID_IF_FAILED
argument_list|(
literal|"Failed to cancel timer"
argument_list|)
expr_stmt|;
block|}
DECL|function|timerExpired
name|HRESULT
name|timerExpired
parameter_list|(
name|IThreadPoolTimer
modifier|*
parameter_list|)
block|{
if|if
condition|(
name|isFinished
condition|)
return|return
name|S_OK
return|;
if|if
condition|(
name|dispatcher
condition|)
name|QCoreApplication
operator|::
name|postEvent
argument_list|(
name|dispatcher
argument_list|,
operator|new
name|QTimerEvent
argument_list|(
name|id
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|S_OK
return|;
block|}
DECL|function|timerDestroyed
name|HRESULT
name|timerDestroyed
parameter_list|(
name|IThreadPoolTimer
modifier|*
parameter_list|)
block|{
if|if
condition|(
name|isFinished
condition|)
operator|delete
name|this
expr_stmt|;
else|else
name|isFinished
operator|=
literal|true
expr_stmt|;
return|return
name|S_OK
return|;
block|}
DECL|member|isFinished
name|bool
name|isFinished
decl_stmt|;
DECL|member|id
name|int
name|id
decl_stmt|;
DECL|member|interval
name|int
name|interval
decl_stmt|;
DECL|member|timerType
name|Qt
operator|::
name|TimerType
name|timerType
decl_stmt|;
DECL|member|timeout
name|quint64
name|timeout
decl_stmt|;
comment|// - when to actually fire
DECL|member|obj
name|QObject
modifier|*
name|obj
decl_stmt|;
comment|// - object to receive events
DECL|member|inTimerEvent
name|bool
name|inTimerEvent
decl_stmt|;
DECL|member|timer
name|ComPtr
argument_list|<
name|IThreadPoolTimer
argument_list|>
name|timer
decl_stmt|;
DECL|member|dispatcher
name|QPointer
argument_list|<
name|QEventDispatcherWinRT
argument_list|>
name|dispatcher
decl_stmt|;
block|}
struct|;
end_struct
begin_class
DECL|class|QEventDispatcherWinRTPrivate
class|class
name|QEventDispatcherWinRTPrivate
super|:
specifier|public
name|QAbstractEventDispatcherPrivate
block|{
name|Q_DECLARE_PUBLIC
parameter_list|(
name|QEventDispatcherWinRT
parameter_list|)
specifier|public
private|:
name|QEventDispatcherWinRTPrivate
parameter_list|()
constructor_decl|;
name|~
name|QEventDispatcherWinRTPrivate
parameter_list|()
destructor_decl|;
private|private:
DECL|member|timerDict
name|QHash
argument_list|<
name|int
argument_list|,
name|WinRTTimerInfo
modifier|*
argument_list|>
name|timerDict
decl_stmt|;
DECL|member|timerFactory
name|ComPtr
argument_list|<
name|IThreadPoolTimerStatics
argument_list|>
name|timerFactory
decl_stmt|;
DECL|member|coreDispatcher
name|ComPtr
argument_list|<
name|ICoreDispatcher
argument_list|>
name|coreDispatcher
decl_stmt|;
DECL|member|thread
name|QPointer
argument_list|<
name|QThread
argument_list|>
name|thread
decl_stmt|;
DECL|member|interrupt
name|bool
name|interrupt
decl_stmt|;
DECL|function|fetchCoreDispatcher
name|void
name|fetchCoreDispatcher
parameter_list|()
block|{
name|ComPtr
argument_list|<
name|ICoreImmersiveApplication
argument_list|>
name|application
decl_stmt|;
name|HRESULT
name|hr
init|=
name|RoGetActivationFactory
argument_list|(
name|HString
operator|::
name|MakeReference
argument_list|(
name|RuntimeClass_Windows_ApplicationModel_Core_CoreApplication
argument_list|)
operator|.
name|Get
argument_list|()
argument_list|,
name|IID_PPV_ARGS
argument_list|(
operator|&
name|application
argument_list|)
argument_list|)
decl_stmt|;
name|RETURN_VOID_IF_FAILED
argument_list|(
literal|"Failed to get the application factory"
argument_list|)
expr_stmt|;
name|ComPtr
argument_list|<
name|ICoreApplicationView
argument_list|>
name|view
decl_stmt|;
name|hr
operator|=
name|application
operator|->
name|get_MainView
argument_list|(
operator|&
name|view
argument_list|)
expr_stmt|;
name|RETURN_VOID_IF_FAILED
argument_list|(
literal|"Failed to get the main view"
argument_list|)
expr_stmt|;
name|ComPtr
argument_list|<
name|ICoreApplicationView2
argument_list|>
name|view2
decl_stmt|;
name|hr
operator|=
name|view
operator|.
name|As
argument_list|(
operator|&
name|view2
argument_list|)
expr_stmt|;
name|RETURN_VOID_IF_FAILED
argument_list|(
literal|"Failed to cast the main view"
argument_list|)
expr_stmt|;
name|hr
operator|=
name|view2
operator|->
name|get_Dispatcher
argument_list|(
operator|&
name|coreDispatcher
argument_list|)
expr_stmt|;
if|if
condition|(
name|hr
operator|==
name|HRESULT_FROM_WIN32
argument_list|(
name|ERROR_NOT_FOUND
argument_list|)
condition|)
comment|// expected in thread pool cases
return|return;
name|RETURN_VOID_IF_FAILED
argument_list|(
literal|"Failed to get core dispatcher"
argument_list|)
expr_stmt|;
name|thread
operator|=
name|QThread
operator|::
name|currentThread
argument_list|()
expr_stmt|;
block|}
block|}
class|;
end_class
begin_constructor
DECL|function|QEventDispatcherWinRT
name|QEventDispatcherWinRT
operator|::
name|QEventDispatcherWinRT
parameter_list|(
name|QObject
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QAbstractEventDispatcher
argument_list|(
operator|*
operator|new
name|QEventDispatcherWinRTPrivate
argument_list|,
name|parent
argument_list|)
block|{
name|Q_D
argument_list|(
name|QEventDispatcherWinRT
argument_list|)
expr_stmt|;
comment|// Special treatment for the WinMain thread, as it is created before the UI
specifier|static
name|bool
name|firstThread
init|=
literal|true
decl_stmt|;
if|if
condition|(
name|firstThread
condition|)
block|{
name|firstThread
operator|=
literal|false
expr_stmt|;
return|return;
block|}
name|d
operator|->
name|fetchCoreDispatcher
argument_list|()
expr_stmt|;
block|}
end_constructor
begin_constructor
DECL|function|QEventDispatcherWinRT
name|QEventDispatcherWinRT
operator|::
name|QEventDispatcherWinRT
parameter_list|(
name|QEventDispatcherWinRTPrivate
modifier|&
name|dd
parameter_list|,
name|QObject
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QAbstractEventDispatcher
argument_list|(
name|dd
argument_list|,
name|parent
argument_list|)
block|{ }
end_constructor
begin_destructor
DECL|function|~QEventDispatcherWinRT
name|QEventDispatcherWinRT
operator|::
name|~
name|QEventDispatcherWinRT
parameter_list|()
block|{ }
end_destructor
begin_function
DECL|function|processEvents
name|bool
name|QEventDispatcherWinRT
operator|::
name|processEvents
parameter_list|(
name|QEventLoop
operator|::
name|ProcessEventsFlags
name|flags
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QEventDispatcherWinRT
argument_list|)
expr_stmt|;
if|if
condition|(
name|d
operator|->
name|thread
operator|&&
name|d
operator|->
name|thread
operator|!=
name|QThread
operator|::
name|currentThread
argument_list|()
condition|)
name|d
operator|->
name|fetchCoreDispatcher
argument_list|()
expr_stmt|;
name|bool
name|didProcess
init|=
literal|false
decl_stmt|;
forever|forever
block|{
comment|// Process native events
if|if
condition|(
name|d
operator|->
name|coreDispatcher
condition|)
block|{
name|boolean
name|hasThreadAccess
decl_stmt|;
name|HRESULT
name|hr
init|=
name|d
operator|->
name|coreDispatcher
operator|->
name|get_HasThreadAccess
argument_list|(
operator|&
name|hasThreadAccess
argument_list|)
decl_stmt|;
if|if
condition|(
name|SUCCEEDED
argument_list|(
name|hr
argument_list|)
operator|&&
name|hasThreadAccess
condition|)
block|{
name|hr
operator|=
name|d
operator|->
name|coreDispatcher
operator|->
name|ProcessEvents
argument_list|(
name|CoreProcessEventsOption_ProcessAllIfPresent
argument_list|)
expr_stmt|;
if|if
condition|(
name|FAILED
argument_list|(
name|hr
argument_list|)
condition|)
name|qErrnoWarning
argument_list|(
name|hr
argument_list|,
literal|"Failed to process events"
argument_list|)
expr_stmt|;
block|}
block|}
comment|// Dispatch accumulated user events
name|didProcess
operator|=
name|sendPostedEvents
argument_list|(
name|flags
argument_list|)
expr_stmt|;
if|if
condition|(
name|didProcess
condition|)
break|break;
if|if
condition|(
name|d
operator|->
name|interrupt
condition|)
break|break;
comment|// Short sleep if there is nothing to do
if|if
condition|(
operator|!
operator|(
name|flags
operator|&
name|QEventLoop
operator|::
name|WaitForMoreEvents
operator|)
condition|)
break|break;
emit|emit
name|aboutToBlock
argument_list|()
emit|;
name|WaitForSingleObjectEx
argument_list|(
name|GetCurrentThread
argument_list|()
argument_list|,
literal|1
argument_list|,
name|FALSE
argument_list|)
expr_stmt|;
emit|emit
name|awake
argument_list|()
emit|;
block|}
name|d
operator|->
name|interrupt
operator|=
literal|false
expr_stmt|;
return|return
name|didProcess
return|;
block|}
end_function
begin_function
DECL|function|sendPostedEvents
name|bool
name|QEventDispatcherWinRT
operator|::
name|sendPostedEvents
parameter_list|(
name|QEventLoop
operator|::
name|ProcessEventsFlags
name|flags
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
name|flags
argument_list|)
expr_stmt|;
if|if
condition|(
name|hasPendingEvents
argument_list|()
condition|)
block|{
name|QCoreApplication
operator|::
name|sendPostedEvents
argument_list|()
expr_stmt|;
return|return
literal|true
return|;
block|}
return|return
literal|false
return|;
block|}
end_function
begin_function
DECL|function|hasPendingEvents
name|bool
name|QEventDispatcherWinRT
operator|::
name|hasPendingEvents
parameter_list|()
block|{
return|return
name|qGlobalPostedEventsCount
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|registerSocketNotifier
name|void
name|QEventDispatcherWinRT
operator|::
name|registerSocketNotifier
parameter_list|(
name|QSocketNotifier
modifier|*
name|notifier
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
name|notifier
argument_list|)
expr_stmt|;
name|Q_UNIMPLEMENTED
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|unregisterSocketNotifier
name|void
name|QEventDispatcherWinRT
operator|::
name|unregisterSocketNotifier
parameter_list|(
name|QSocketNotifier
modifier|*
name|notifier
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
name|notifier
argument_list|)
expr_stmt|;
name|Q_UNIMPLEMENTED
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|registerTimer
name|void
name|QEventDispatcherWinRT
operator|::
name|registerTimer
parameter_list|(
name|int
name|timerId
parameter_list|,
name|int
name|interval
parameter_list|,
name|Qt
operator|::
name|TimerType
name|timerType
parameter_list|,
name|QObject
modifier|*
name|object
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
name|timerType
argument_list|)
expr_stmt|;
ifndef|#
directive|ifndef
name|QT_NO_DEBUG
if|if
condition|(
name|timerId
operator|<
literal|1
operator|||
name|interval
operator|<
literal|0
operator|||
operator|!
name|object
condition|)
block|{
name|qWarning
argument_list|(
literal|"QEventDispatcherWinRT::registerTimer: invalid arguments"
argument_list|)
expr_stmt|;
return|return;
block|}
elseif|else
if|if
condition|(
name|object
operator|->
name|thread
argument_list|()
operator|!=
name|thread
argument_list|()
operator|||
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
literal|"QEventDispatcherWinRT::registerTimer: timers cannot be started from another thread"
argument_list|)
expr_stmt|;
return|return;
block|}
endif|#
directive|endif
name|Q_D
argument_list|(
name|QEventDispatcherWinRT
argument_list|)
expr_stmt|;
name|WinRTTimerInfo
modifier|*
name|t
init|=
operator|new
name|WinRTTimerInfo
argument_list|(
name|timerId
argument_list|,
name|interval
argument_list|,
name|timerType
argument_list|,
name|object
argument_list|,
name|this
argument_list|)
decl_stmt|;
name|t
operator|->
name|timeout
operator|=
name|qt_msectime
argument_list|()
operator|+
name|interval
expr_stmt|;
name|d
operator|->
name|timerDict
operator|.
name|insert
argument_list|(
name|t
operator|->
name|id
argument_list|,
name|t
argument_list|)
expr_stmt|;
comment|// Don't use timer factory for zero-delay timers
if|if
condition|(
name|interval
operator|==
literal|0u
condition|)
block|{
name|QCoreApplication
operator|::
name|postEvent
argument_list|(
name|this
argument_list|,
operator|new
name|QZeroTimerEvent
argument_list|(
name|timerId
argument_list|)
argument_list|)
expr_stmt|;
return|return;
block|}
name|TimeSpan
name|period
decl_stmt|;
name|period
operator|.
name|Duration
operator|=
name|interval
condition|?
operator|(
name|interval
operator|*
literal|10000
operator|)
else|:
literal|1
expr_stmt|;
comment|// TimeSpan is based on 100-nanosecond units
name|HRESULT
name|hr
init|=
name|d
operator|->
name|timerFactory
operator|->
name|CreatePeriodicTimerWithCompletion
argument_list|(
name|Callback
argument_list|<
name|ITimerElapsedHandler
argument_list|>
argument_list|(
name|t
argument_list|,
operator|&
name|WinRTTimerInfo
operator|::
name|timerExpired
argument_list|)
operator|.
name|Get
argument_list|()
argument_list|,
name|period
argument_list|,
name|Callback
argument_list|<
name|ITimerDestroyedHandler
argument_list|>
argument_list|(
name|t
argument_list|,
operator|&
name|WinRTTimerInfo
operator|::
name|timerDestroyed
argument_list|)
operator|.
name|Get
argument_list|()
argument_list|,
operator|&
name|t
operator|->
name|timer
argument_list|)
decl_stmt|;
if|if
condition|(
name|FAILED
argument_list|(
name|hr
argument_list|)
condition|)
block|{
name|qErrnoWarning
argument_list|(
name|hr
argument_list|,
literal|"Failed to create periodic timer"
argument_list|)
expr_stmt|;
operator|delete
name|t
expr_stmt|;
name|d
operator|->
name|timerDict
operator|.
name|remove
argument_list|(
name|t
operator|->
name|id
argument_list|)
expr_stmt|;
return|return;
block|}
block|}
end_function
begin_function
DECL|function|unregisterTimer
name|bool
name|QEventDispatcherWinRT
operator|::
name|unregisterTimer
parameter_list|(
name|int
name|timerId
parameter_list|)
block|{
ifndef|#
directive|ifndef
name|QT_NO_DEBUG
if|if
condition|(
name|timerId
operator|<
literal|1
condition|)
block|{
name|qWarning
argument_list|(
literal|"QEventDispatcherWinRT::unregisterTimer: invalid argument"
argument_list|)
expr_stmt|;
return|return
literal|false
return|;
block|}
if|if
condition|(
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
literal|"QEventDispatcherWinRT::unregisterTimer: timers cannot be stopped from another thread"
argument_list|)
expr_stmt|;
return|return
literal|false
return|;
block|}
endif|#
directive|endif
name|Q_D
argument_list|(
name|QEventDispatcherWinRT
argument_list|)
expr_stmt|;
name|WinRTTimerInfo
modifier|*
name|t
init|=
name|d
operator|->
name|timerDict
operator|.
name|take
argument_list|(
name|timerId
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|t
condition|)
return|return
literal|false
return|;
name|t
operator|->
name|cancel
argument_list|()
expr_stmt|;
return|return
literal|true
return|;
block|}
end_function
begin_function
DECL|function|unregisterTimers
name|bool
name|QEventDispatcherWinRT
operator|::
name|unregisterTimers
parameter_list|(
name|QObject
modifier|*
name|object
parameter_list|)
block|{
ifndef|#
directive|ifndef
name|QT_NO_DEBUG
if|if
condition|(
operator|!
name|object
condition|)
block|{
name|qWarning
argument_list|(
literal|"QEventDispatcherWinRT::unregisterTimers: invalid argument"
argument_list|)
expr_stmt|;
return|return
literal|false
return|;
block|}
name|QThread
modifier|*
name|currentThread
init|=
name|QThread
operator|::
name|currentThread
argument_list|()
decl_stmt|;
if|if
condition|(
name|object
operator|->
name|thread
argument_list|()
operator|!=
name|thread
argument_list|()
operator|||
name|thread
argument_list|()
operator|!=
name|currentThread
condition|)
block|{
name|qWarning
argument_list|(
literal|"QEventDispatcherWinRT::unregisterTimers: timers cannot be stopped from another thread"
argument_list|)
expr_stmt|;
return|return
literal|false
return|;
block|}
endif|#
directive|endif
name|Q_D
argument_list|(
name|QEventDispatcherWinRT
argument_list|)
expr_stmt|;
for|for
control|(
name|QHash
argument_list|<
name|int
argument_list|,
name|WinRTTimerInfo
operator|*
argument_list|>
operator|::
name|iterator
name|it
init|=
name|d
operator|->
name|timerDict
operator|.
name|begin
argument_list|()
init|;
name|it
operator|!=
name|d
operator|->
name|timerDict
operator|.
name|end
argument_list|()
condition|;
control|)
block|{
if|if
condition|(
name|it
operator|.
name|value
argument_list|()
operator|->
name|obj
operator|==
name|object
condition|)
block|{
name|it
operator|.
name|value
argument_list|()
operator|->
name|cancel
argument_list|()
expr_stmt|;
name|it
operator|=
name|d
operator|->
name|timerDict
operator|.
name|erase
argument_list|(
name|it
argument_list|)
expr_stmt|;
continue|continue;
block|}
operator|++
name|it
expr_stmt|;
block|}
return|return
literal|true
return|;
block|}
end_function
begin_function
DECL|function|registeredTimers
name|QList
argument_list|<
name|QAbstractEventDispatcher
operator|::
name|TimerInfo
argument_list|>
name|QEventDispatcherWinRT
operator|::
name|registeredTimers
parameter_list|(
name|QObject
modifier|*
name|object
parameter_list|)
specifier|const
block|{
if|if
condition|(
operator|!
name|object
condition|)
block|{
name|qWarning
argument_list|(
literal|"QEventDispatcherWinRT:registeredTimers: invalid argument"
argument_list|)
expr_stmt|;
return|return
name|QList
argument_list|<
name|TimerInfo
argument_list|>
argument_list|()
return|;
block|}
name|Q_D
argument_list|(
specifier|const
name|QEventDispatcherWinRT
argument_list|)
expr_stmt|;
name|QList
argument_list|<
name|TimerInfo
argument_list|>
name|list
decl_stmt|;
foreach|foreach
control|(
specifier|const
name|WinRTTimerInfo
modifier|*
name|t
decl|,
name|d
operator|->
name|timerDict
control|)
block|{
if|if
condition|(
name|t
operator|->
name|obj
operator|==
name|object
condition|)
name|list
operator|.
name|append
argument_list|(
name|TimerInfo
argument_list|(
name|t
operator|->
name|id
argument_list|,
name|t
operator|->
name|interval
argument_list|,
name|t
operator|->
name|timerType
argument_list|)
argument_list|)
expr_stmt|;
block|}
return|return
name|list
return|;
block|}
end_function
begin_function
DECL|function|registerEventNotifier
name|bool
name|QEventDispatcherWinRT
operator|::
name|registerEventNotifier
parameter_list|(
name|QWinEventNotifier
modifier|*
name|notifier
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
name|notifier
argument_list|)
expr_stmt|;
name|Q_UNIMPLEMENTED
argument_list|()
expr_stmt|;
return|return
literal|false
return|;
block|}
end_function
begin_function
DECL|function|unregisterEventNotifier
name|void
name|QEventDispatcherWinRT
operator|::
name|unregisterEventNotifier
parameter_list|(
name|QWinEventNotifier
modifier|*
name|notifier
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
name|notifier
argument_list|)
expr_stmt|;
name|Q_UNIMPLEMENTED
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|remainingTime
name|int
name|QEventDispatcherWinRT
operator|::
name|remainingTime
parameter_list|(
name|int
name|timerId
parameter_list|)
block|{
ifndef|#
directive|ifndef
name|QT_NO_DEBUG
if|if
condition|(
name|timerId
operator|<
literal|1
condition|)
block|{
name|qWarning
argument_list|(
literal|"QEventDispatcherWinRT::remainingTime: invalid argument"
argument_list|)
expr_stmt|;
return|return
operator|-
literal|1
return|;
block|}
endif|#
directive|endif
name|Q_D
argument_list|(
name|QEventDispatcherWinRT
argument_list|)
expr_stmt|;
if|if
condition|(
name|WinRTTimerInfo
modifier|*
name|t
init|=
name|d
operator|->
name|timerDict
operator|.
name|value
argument_list|(
name|timerId
argument_list|)
condition|)
block|{
specifier|const
name|quint64
name|currentTime
init|=
name|qt_msectime
argument_list|()
decl_stmt|;
if|if
condition|(
name|currentTime
operator|<
name|t
operator|->
name|timeout
condition|)
block|{
comment|// time to wait
return|return
name|t
operator|->
name|timeout
operator|-
name|currentTime
return|;
block|}
else|else
block|{
return|return
literal|0
return|;
block|}
block|}
ifndef|#
directive|ifndef
name|QT_NO_DEBUG
name|qWarning
argument_list|(
literal|"QEventDispatcherWinRT::remainingTime: timer id %d not found"
argument_list|,
name|timerId
argument_list|)
expr_stmt|;
endif|#
directive|endif
return|return
operator|-
literal|1
return|;
block|}
end_function
begin_function
DECL|function|wakeUp
name|void
name|QEventDispatcherWinRT
operator|::
name|wakeUp
parameter_list|()
block|{ }
end_function
begin_function
DECL|function|interrupt
name|void
name|QEventDispatcherWinRT
operator|::
name|interrupt
parameter_list|()
block|{
name|Q_D
argument_list|(
name|QEventDispatcherWinRT
argument_list|)
expr_stmt|;
name|d
operator|->
name|interrupt
operator|=
literal|true
expr_stmt|;
block|}
end_function
begin_function
DECL|function|flush
name|void
name|QEventDispatcherWinRT
operator|::
name|flush
parameter_list|()
block|{ }
end_function
begin_function
DECL|function|startingUp
name|void
name|QEventDispatcherWinRT
operator|::
name|startingUp
parameter_list|()
block|{ }
end_function
begin_function
DECL|function|closingDown
name|void
name|QEventDispatcherWinRT
operator|::
name|closingDown
parameter_list|()
block|{
name|Q_D
argument_list|(
name|QEventDispatcherWinRT
argument_list|)
expr_stmt|;
name|d
operator|->
name|timerDict
operator|.
name|clear
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|event
name|bool
name|QEventDispatcherWinRT
operator|::
name|event
parameter_list|(
name|QEvent
modifier|*
name|e
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QEventDispatcherWinRT
argument_list|)
expr_stmt|;
name|bool
name|ret
init|=
literal|false
decl_stmt|;
switch|switch
condition|(
name|e
operator|->
name|type
argument_list|()
condition|)
block|{
case|case
name|QEvent
operator|::
name|ZeroTimerEvent
case|:
name|ret
operator|=
literal|true
expr_stmt|;
comment|// fall through
case|case
name|QEvent
operator|::
name|Timer
case|:
block|{
name|QTimerEvent
modifier|*
name|timerEvent
init|=
cast|static_cast
argument_list|<
name|QTimerEvent
operator|*
argument_list|>
argument_list|(
name|e
argument_list|)
decl_stmt|;
specifier|const
name|int
name|id
init|=
name|timerEvent
operator|->
name|timerId
argument_list|()
decl_stmt|;
if|if
condition|(
name|WinRTTimerInfo
modifier|*
name|t
init|=
name|d
operator|->
name|timerDict
operator|.
name|value
argument_list|(
name|id
argument_list|)
condition|)
block|{
if|if
condition|(
name|t
operator|->
name|inTimerEvent
condition|)
comment|// but don't allow event to recurse
break|break;
name|t
operator|->
name|inTimerEvent
operator|=
literal|true
expr_stmt|;
name|QTimerEvent
name|te
argument_list|(
name|id
argument_list|)
decl_stmt|;
name|QCoreApplication
operator|::
name|sendEvent
argument_list|(
name|t
operator|->
name|obj
argument_list|,
operator|&
name|te
argument_list|)
expr_stmt|;
if|if
condition|(
name|t
operator|=
name|d
operator|->
name|timerDict
operator|.
name|value
argument_list|(
name|id
argument_list|)
condition|)
block|{
if|if
condition|(
name|t
operator|->
name|interval
operator|==
literal|0
operator|&&
name|t
operator|->
name|inTimerEvent
condition|)
block|{
comment|// post the next zero timer event as long as the timer was not restarted
name|QCoreApplication
operator|::
name|postEvent
argument_list|(
name|this
argument_list|,
operator|new
name|QZeroTimerEvent
argument_list|(
name|id
argument_list|)
argument_list|)
expr_stmt|;
block|}
name|t
operator|->
name|inTimerEvent
operator|=
literal|false
expr_stmt|;
block|}
block|}
block|}
default|default:
break|break;
block|}
return|return
name|ret
condition|?
literal|true
else|:
name|QAbstractEventDispatcher
operator|::
name|event
argument_list|(
name|e
argument_list|)
return|;
block|}
end_function
begin_constructor
DECL|function|QEventDispatcherWinRTPrivate
name|QEventDispatcherWinRTPrivate
operator|::
name|QEventDispatcherWinRTPrivate
parameter_list|()
member_init_list|:
name|interrupt
argument_list|(
literal|false
argument_list|)
block|{
name|CoInitializeEx
argument_list|(
name|NULL
argument_list|,
name|COINIT_APARTMENTTHREADED
argument_list|)
expr_stmt|;
name|HRESULT
name|hr
init|=
name|GetActivationFactory
argument_list|(
name|HString
operator|::
name|MakeReference
argument_list|(
name|RuntimeClass_Windows_System_Threading_ThreadPoolTimer
argument_list|)
operator|.
name|Get
argument_list|()
argument_list|,
operator|&
name|timerFactory
argument_list|)
decl_stmt|;
if|if
condition|(
name|FAILED
argument_list|(
name|hr
argument_list|)
condition|)
name|qWarning
argument_list|(
literal|"QEventDispatcherWinRTPrivate::QEventDispatcherWinRTPrivate: Could not obtain timer factory: %lx"
argument_list|,
name|hr
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_destructor
DECL|function|~QEventDispatcherWinRTPrivate
name|QEventDispatcherWinRTPrivate
operator|::
name|~
name|QEventDispatcherWinRTPrivate
parameter_list|()
block|{
name|CoUninitialize
argument_list|()
expr_stmt|;
block|}
end_destructor
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
