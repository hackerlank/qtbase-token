begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2014 BogDan Vatra<bogdan@kde.org> ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qandroideventdispatcher.h"
end_include
begin_include
include|#
directive|include
file|"androidjnimain.h"
end_include
begin_include
include|#
directive|include
file|"androiddeadlockprotector.h"
end_include
begin_constructor
DECL|function|QAndroidEventDispatcher
name|QAndroidEventDispatcher
operator|::
name|QAndroidEventDispatcher
parameter_list|(
name|QObject
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QUnixEventDispatcherQPA
argument_list|(
name|parent
argument_list|)
block|{
if|if
condition|(
name|QtAndroid
operator|::
name|blockEventLoopsWhenSuspended
argument_list|()
condition|)
name|QAndroidEventDispatcherStopper
operator|::
name|instance
argument_list|()
operator|->
name|addEventDispatcher
argument_list|(
name|this
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_destructor
DECL|function|~QAndroidEventDispatcher
name|QAndroidEventDispatcher
operator|::
name|~
name|QAndroidEventDispatcher
parameter_list|()
block|{
if|if
condition|(
name|QtAndroid
operator|::
name|blockEventLoopsWhenSuspended
argument_list|()
condition|)
name|QAndroidEventDispatcherStopper
operator|::
name|instance
argument_list|()
operator|->
name|removeEventDispatcher
argument_list|(
name|this
argument_list|)
expr_stmt|;
block|}
end_destructor
begin_enum
DECL|enum|States
DECL|enumerator|Running
DECL|enumerator|StopRequest
DECL|enumerator|Stopping
enum|enum
name|States
block|{
name|Running
init|=
literal|0
block|,
name|StopRequest
init|=
literal|1
block|,
name|Stopping
init|=
literal|2
block|}
enum|;
end_enum
begin_function
DECL|function|start
name|void
name|QAndroidEventDispatcher
operator|::
name|start
parameter_list|()
block|{
name|int
name|prevState
init|=
name|m_stopRequest
operator|.
name|fetchAndStoreAcquire
argument_list|(
name|Running
argument_list|)
decl_stmt|;
if|if
condition|(
name|prevState
operator|==
name|Stopping
condition|)
block|{
name|m_semaphore
operator|.
name|release
argument_list|()
expr_stmt|;
name|wakeUp
argument_list|()
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|prevState
operator|==
name|Running
condition|)
block|{
name|qWarning
argument_list|(
literal|"Error: start without corresponding stop"
argument_list|)
expr_stmt|;
block|}
comment|//else if prevState == StopRequest, no action needed
block|}
end_function
begin_function
DECL|function|stop
name|void
name|QAndroidEventDispatcher
operator|::
name|stop
parameter_list|()
block|{
if|if
condition|(
name|m_stopRequest
operator|.
name|testAndSetAcquire
argument_list|(
name|Running
argument_list|,
name|StopRequest
argument_list|)
condition|)
name|wakeUp
argument_list|()
expr_stmt|;
else|else
name|qWarning
argument_list|(
literal|"Error: start/stop out of sync"
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|goingToStop
name|void
name|QAndroidEventDispatcher
operator|::
name|goingToStop
parameter_list|(
name|bool
name|stop
parameter_list|)
block|{
name|m_goingToStop
operator|.
name|store
argument_list|(
name|stop
condition|?
literal|1
else|:
literal|0
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|stop
condition|)
name|wakeUp
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|processEvents
name|bool
name|QAndroidEventDispatcher
operator|::
name|processEvents
parameter_list|(
name|QEventLoop
operator|::
name|ProcessEventsFlags
name|flags
parameter_list|)
block|{
if|if
condition|(
name|m_goingToStop
operator|.
name|load
argument_list|()
condition|)
name|flags
operator||=
name|QEventLoop
operator|::
name|ExcludeSocketNotifiers
operator||
name|QEventLoop
operator|::
name|X11ExcludeTimers
expr_stmt|;
block|{
name|AndroidDeadlockProtector
name|protector
decl_stmt|;
if|if
condition|(
name|protector
operator|.
name|acquire
argument_list|()
operator|&&
name|m_stopRequest
operator|.
name|testAndSetAcquire
argument_list|(
name|StopRequest
argument_list|,
name|Stopping
argument_list|)
condition|)
block|{
name|m_semaphore
operator|.
name|acquire
argument_list|()
expr_stmt|;
name|wakeUp
argument_list|()
expr_stmt|;
block|}
block|}
return|return
name|QUnixEventDispatcherQPA
operator|::
name|processEvents
argument_list|(
name|flags
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|instance
name|QAndroidEventDispatcherStopper
modifier|*
name|QAndroidEventDispatcherStopper
operator|::
name|instance
parameter_list|()
block|{
specifier|static
name|QAndroidEventDispatcherStopper
name|androidEventDispatcherStopper
decl_stmt|;
return|return
operator|&
name|androidEventDispatcherStopper
return|;
block|}
end_function
begin_function
DECL|function|startAll
name|void
name|QAndroidEventDispatcherStopper
operator|::
name|startAll
parameter_list|()
block|{
name|QMutexLocker
name|lock
argument_list|(
operator|&
name|m_mutex
argument_list|)
decl_stmt|;
if|if
condition|(
name|started
condition|)
return|return;
name|started
operator|=
literal|true
expr_stmt|;
for|for
control|(
name|QAndroidEventDispatcher
modifier|*
name|d
range|:
name|qAsConst
argument_list|(
name|m_dispatchers
argument_list|)
control|)
name|d
operator|->
name|start
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|stopAll
name|void
name|QAndroidEventDispatcherStopper
operator|::
name|stopAll
parameter_list|()
block|{
name|QMutexLocker
name|lock
argument_list|(
operator|&
name|m_mutex
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|started
condition|)
return|return;
name|started
operator|=
literal|false
expr_stmt|;
for|for
control|(
name|QAndroidEventDispatcher
modifier|*
name|d
range|:
name|qAsConst
argument_list|(
name|m_dispatchers
argument_list|)
control|)
name|d
operator|->
name|stop
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|addEventDispatcher
name|void
name|QAndroidEventDispatcherStopper
operator|::
name|addEventDispatcher
parameter_list|(
name|QAndroidEventDispatcher
modifier|*
name|dispatcher
parameter_list|)
block|{
name|QMutexLocker
name|lock
argument_list|(
operator|&
name|m_mutex
argument_list|)
decl_stmt|;
name|m_dispatchers
operator|.
name|push_back
argument_list|(
name|dispatcher
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|removeEventDispatcher
name|void
name|QAndroidEventDispatcherStopper
operator|::
name|removeEventDispatcher
parameter_list|(
name|QAndroidEventDispatcher
modifier|*
name|dispatcher
parameter_list|)
block|{
name|QMutexLocker
name|lock
argument_list|(
operator|&
name|m_mutex
argument_list|)
decl_stmt|;
name|m_dispatchers
operator|.
name|erase
argument_list|(
name|std
operator|::
name|find
argument_list|(
name|m_dispatchers
operator|.
name|begin
argument_list|()
argument_list|,
name|m_dispatchers
operator|.
name|end
argument_list|()
argument_list|,
name|dispatcher
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|goingToStop
name|void
name|QAndroidEventDispatcherStopper
operator|::
name|goingToStop
parameter_list|(
name|bool
name|stop
parameter_list|)
block|{
name|QMutexLocker
name|lock
argument_list|(
operator|&
name|m_mutex
argument_list|)
decl_stmt|;
for|for
control|(
name|QAndroidEventDispatcher
modifier|*
name|d
range|:
name|qAsConst
argument_list|(
name|m_dispatchers
argument_list|)
control|)
name|d
operator|->
name|goingToStop
argument_list|(
name|stop
argument_list|)
expr_stmt|;
block|}
end_function
end_unit
