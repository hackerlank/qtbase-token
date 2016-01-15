begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qsemaphore.h"
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_THREAD
end_ifndef
begin_include
include|#
directive|include
file|"qmutex.h"
end_include
begin_include
include|#
directive|include
file|"qwaitcondition.h"
end_include
begin_include
include|#
directive|include
file|"qelapsedtimer.h"
end_include
begin_include
include|#
directive|include
file|"qdatetime.h"
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_comment
comment|/*!     \class QSemaphore     \inmodule QtCore     \brief The QSemaphore class provides a general counting semaphore.      \threadsafe      \ingroup thread      A semaphore is a generalization of a mutex. While a mutex can     only be locked once, it's possible to acquire a semaphore     multiple times. Semaphores are typically used to protect a     certain number of identical resources.      Semaphores support two fundamental operations, acquire() and     release():      \list     \li acquire(\e{n}) tries to acquire \e n resources. If there aren't        that many resources available, the call will block until this        is the case.     \li release(\e{n}) releases \e n resources.     \endlist      There's also a tryAcquire() function that returns immediately if     it cannot acquire the resources, and an available() function that     returns the number of available resources at any time.      Example:      \snippet code/src_corelib_thread_qsemaphore.cpp 0      A typical application of semaphores is for controlling access to     a circular buffer shared by a producer thread and a consumer     thread. The \l{Semaphores Example} shows how     to use QSemaphore to solve that problem.      A non-computing example of a semaphore would be dining at a     restaurant. A semaphore is initialized with the number of chairs     in the restaurant. As people arrive, they want a seat. As seats     are filled, available() is decremented. As people leave, the     available() is incremented, allowing more people to enter. If a     party of 10 people want to be seated, but there are only 9 seats,     those 10 people will wait, but a party of 4 people would be     seated (taking the available seats to 5, making the party of 10     people wait longer).      \sa QMutex, QWaitCondition, QThread, {Semaphores Example} */
end_comment
begin_class
DECL|class|QSemaphorePrivate
class|class
name|QSemaphorePrivate
block|{
public|public:
DECL|function|QSemaphorePrivate
specifier|inline
name|QSemaphorePrivate
parameter_list|(
name|int
name|n
parameter_list|)
member_init_list|:
name|avail
argument_list|(
name|n
argument_list|)
block|{ }
DECL|member|mutex
name|QMutex
name|mutex
decl_stmt|;
DECL|member|cond
name|QWaitCondition
name|cond
decl_stmt|;
DECL|member|avail
name|int
name|avail
decl_stmt|;
block|}
class|;
end_class
begin_comment
comment|/*!     Creates a new semaphore and initializes the number of resources     it guards to \a n (by default, 0).      \sa release(), available() */
end_comment
begin_constructor
DECL|function|QSemaphore
name|QSemaphore
operator|::
name|QSemaphore
parameter_list|(
name|int
name|n
parameter_list|)
block|{
name|Q_ASSERT_X
argument_list|(
name|n
operator|>=
literal|0
argument_list|,
literal|"QSemaphore"
argument_list|,
literal|"parameter 'n' must be non-negative"
argument_list|)
expr_stmt|;
name|d
operator|=
operator|new
name|QSemaphorePrivate
argument_list|(
name|n
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_comment
comment|/*!     Destroys the semaphore.      \warning Destroying a semaphore that is in use may result in     undefined behavior. */
end_comment
begin_destructor
DECL|function|~QSemaphore
name|QSemaphore
operator|::
name|~
name|QSemaphore
parameter_list|()
block|{
operator|delete
name|d
expr_stmt|;
block|}
end_destructor
begin_comment
comment|/*!     Tries to acquire \c n resources guarded by the semaphore. If \a n> available(), this call will block until enough resources are     available.      \sa release(), available(), tryAcquire() */
end_comment
begin_function
DECL|function|acquire
name|void
name|QSemaphore
operator|::
name|acquire
parameter_list|(
name|int
name|n
parameter_list|)
block|{
name|Q_ASSERT_X
argument_list|(
name|n
operator|>=
literal|0
argument_list|,
literal|"QSemaphore::acquire"
argument_list|,
literal|"parameter 'n' must be non-negative"
argument_list|)
expr_stmt|;
name|QMutexLocker
name|locker
argument_list|(
operator|&
name|d
operator|->
name|mutex
argument_list|)
decl_stmt|;
while|while
condition|(
name|n
operator|>
name|d
operator|->
name|avail
condition|)
name|d
operator|->
name|cond
operator|.
name|wait
argument_list|(
name|locker
operator|.
name|mutex
argument_list|()
argument_list|)
expr_stmt|;
name|d
operator|->
name|avail
operator|-=
name|n
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     Releases \a n resources guarded by the semaphore.      This function can be used to "create" resources as well. For     example:      \snippet code/src_corelib_thread_qsemaphore.cpp 1      \sa acquire(), available() */
end_comment
begin_function
DECL|function|release
name|void
name|QSemaphore
operator|::
name|release
parameter_list|(
name|int
name|n
parameter_list|)
block|{
name|Q_ASSERT_X
argument_list|(
name|n
operator|>=
literal|0
argument_list|,
literal|"QSemaphore::release"
argument_list|,
literal|"parameter 'n' must be non-negative"
argument_list|)
expr_stmt|;
name|QMutexLocker
name|locker
argument_list|(
operator|&
name|d
operator|->
name|mutex
argument_list|)
decl_stmt|;
name|d
operator|->
name|avail
operator|+=
name|n
expr_stmt|;
name|d
operator|->
name|cond
operator|.
name|wakeAll
argument_list|()
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     Returns the number of resources currently available to the     semaphore. This number can never be negative.      \sa acquire(), release() */
end_comment
begin_function
DECL|function|available
name|int
name|QSemaphore
operator|::
name|available
parameter_list|()
specifier|const
block|{
name|QMutexLocker
name|locker
argument_list|(
operator|&
name|d
operator|->
name|mutex
argument_list|)
decl_stmt|;
return|return
name|d
operator|->
name|avail
return|;
block|}
end_function
begin_comment
comment|/*!     Tries to acquire \c n resources guarded by the semaphore and     returns \c true on success. If available()< \a n, this call     immediately returns \c false without acquiring any resources.      Example:      \snippet code/src_corelib_thread_qsemaphore.cpp 2      \sa acquire() */
end_comment
begin_function
DECL|function|tryAcquire
name|bool
name|QSemaphore
operator|::
name|tryAcquire
parameter_list|(
name|int
name|n
parameter_list|)
block|{
name|Q_ASSERT_X
argument_list|(
name|n
operator|>=
literal|0
argument_list|,
literal|"QSemaphore::tryAcquire"
argument_list|,
literal|"parameter 'n' must be non-negative"
argument_list|)
expr_stmt|;
name|QMutexLocker
name|locker
argument_list|(
operator|&
name|d
operator|->
name|mutex
argument_list|)
decl_stmt|;
if|if
condition|(
name|n
operator|>
name|d
operator|->
name|avail
condition|)
return|return
literal|false
return|;
name|d
operator|->
name|avail
operator|-=
name|n
expr_stmt|;
return|return
literal|true
return|;
block|}
end_function
begin_comment
comment|/*!     Tries to acquire \c n resources guarded by the semaphore and     returns \c true on success. If available()< \a n, this call will     wait for at most \a timeout milliseconds for resources to become     available.      Note: Passing a negative number as the \a timeout is equivalent to     calling acquire(), i.e. this function will wait forever for     resources to become available if \a timeout is negative.      Example:      \snippet code/src_corelib_thread_qsemaphore.cpp 3      \sa acquire() */
end_comment
begin_function
DECL|function|tryAcquire
name|bool
name|QSemaphore
operator|::
name|tryAcquire
parameter_list|(
name|int
name|n
parameter_list|,
name|int
name|timeout
parameter_list|)
block|{
name|Q_ASSERT_X
argument_list|(
name|n
operator|>=
literal|0
argument_list|,
literal|"QSemaphore::tryAcquire"
argument_list|,
literal|"parameter 'n' must be non-negative"
argument_list|)
expr_stmt|;
name|QMutexLocker
name|locker
argument_list|(
operator|&
name|d
operator|->
name|mutex
argument_list|)
decl_stmt|;
if|if
condition|(
name|timeout
operator|<
literal|0
condition|)
block|{
while|while
condition|(
name|n
operator|>
name|d
operator|->
name|avail
condition|)
name|d
operator|->
name|cond
operator|.
name|wait
argument_list|(
name|locker
operator|.
name|mutex
argument_list|()
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|QElapsedTimer
name|timer
decl_stmt|;
name|timer
operator|.
name|start
argument_list|()
expr_stmt|;
while|while
condition|(
name|n
operator|>
name|d
operator|->
name|avail
condition|)
block|{
specifier|const
name|qint64
name|elapsed
init|=
name|timer
operator|.
name|elapsed
argument_list|()
decl_stmt|;
if|if
condition|(
name|timeout
operator|-
name|elapsed
operator|<=
literal|0
operator|||
operator|!
name|d
operator|->
name|cond
operator|.
name|wait
argument_list|(
name|locker
operator|.
name|mutex
argument_list|()
argument_list|,
name|timeout
operator|-
name|elapsed
argument_list|)
condition|)
return|return
literal|false
return|;
block|}
block|}
name|d
operator|->
name|avail
operator|-=
name|n
expr_stmt|;
return|return
literal|true
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_THREAD
end_comment
end_unit
