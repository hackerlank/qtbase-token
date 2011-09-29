begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QMUTEX_P_H
end_ifndef
begin_define
DECL|macro|QMUTEX_P_H
define|#
directive|define
name|QMUTEX_P_H
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
comment|// of qmutex.cpp, qmutex_unix.cpp, and qmutex_win.cpp.  This header
end_comment
begin_comment
comment|// file may change from version to version without notice, or even be
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
begin_include
include|#
directive|include
file|<QtCore/qglobal.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qnamespace.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qmutex.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qatomic.h>
end_include
begin_if
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_MAC
argument_list|)
end_if
begin_include
include|#
directive|include
file|<mach/semaphore.h>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
name|class
name|QMutexPrivate
block|{
name|public
label|:
operator|~
name|QMutexPrivate
argument_list|()
expr_stmt|;
name|QMutexPrivate
argument_list|(
argument|QMutex::RecursionMode mode = QMutex::NonRecursive
argument_list|)
empty_stmt|;
name|bool
name|wait
parameter_list|(
name|int
name|timeout
init|=
operator|-
literal|1
parameter_list|)
function_decl|;
name|void
name|wakeUp
parameter_list|()
function_decl|;
if|#
directive|if
operator|!
name|defined
argument_list|(
name|Q_OS_LINUX
argument_list|)
comment|// Conrol the lifetime of the privates
name|QAtomicInt
name|refCount
decl_stmt|;
name|int
name|id
decl_stmt|;
name|bool
name|ref
parameter_list|()
block|{
name|Q_ASSERT
argument_list|(
name|refCount
operator|.
name|load
argument_list|()
operator|>=
literal|0
argument_list|)
expr_stmt|;
name|int
name|c
decl_stmt|;
do|do
block|{
name|c
operator|=
name|refCount
operator|.
name|load
argument_list|()
expr_stmt|;
if|if
condition|(
name|c
operator|==
literal|0
condition|)
return|return
name|false
return|;
block|}
do|while
condition|(
operator|!
name|refCount
operator|.
name|testAndSetRelaxed
argument_list|(
name|c
argument_list|,
name|c
operator|+
literal|1
argument_list|)
condition|)
do|;
name|Q_ASSERT
argument_list|(
name|refCount
operator|.
name|load
argument_list|()
operator|>=
literal|0
argument_list|)
expr_stmt|;
return|return
name|true
return|;
block|}
name|void
name|deref
parameter_list|()
block|{
name|Q_ASSERT
argument_list|(
name|refCount
operator|.
name|load
argument_list|()
operator|>=
literal|0
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|refCount
operator|.
name|deref
argument_list|()
condition|)
name|release
argument_list|()
expr_stmt|;
name|Q_ASSERT
argument_list|(
name|refCount
operator|.
name|load
argument_list|()
operator|>=
literal|0
argument_list|)
expr_stmt|;
block|}
name|void
name|release
parameter_list|()
function_decl|;
specifier|static
name|QMutexPrivate
modifier|*
name|allocate
parameter_list|()
function_decl|;
name|QAtomicInt
name|waiters
decl_stmt|;
comment|//number of thread waiting
name|QAtomicInt
name|possiblyUnlocked
decl_stmt|;
comment|//bool saying that a timed wait timed out
enum|enum
block|{
name|BigNumber
init|=
literal|0x100000
block|}
enum|;
comment|//Must be bigger than the possible number of waiters (number of threads)
name|void
name|derefWaiters
parameter_list|(
name|int
name|value
parameter_list|)
function_decl|;
endif|#
directive|endif
comment|// handle recursive mutex
name|bool
name|recursive
decl_stmt|;
comment|//platform specific stuff
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_MAC
argument_list|)
name|semaphore_t
name|mach_semaphore
decl_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|Q_OS_UNIX
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|Q_OS_LINUX
argument_list|)
name|bool
name|wakeup
decl_stmt|;
name|pthread_mutex_t
name|mutex
decl_stmt|;
name|pthread_cond_t
name|cond
decl_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|Q_OS_WIN32
argument_list|)
operator|||
name|defined
argument_list|(
name|Q_OS_WINCE
argument_list|)
name|HANDLE
name|event
decl_stmt|;
endif|#
directive|endif
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_decl_stmt
name|class
name|QRecursiveMutexPrivate
range|:
name|public
name|QMutexPrivate
block|{
name|public
operator|:
name|QRecursiveMutexPrivate
argument_list|()
operator|:
name|QMutexPrivate
argument_list|(
name|QMutex
operator|::
name|Recursive
argument_list|)
block|,
name|owner
argument_list|(
literal|0
argument_list|)
block|,
name|count
argument_list|(
literal|0
argument_list|)
block|{}
name|Qt
operator|::
name|HANDLE
name|owner
block|;
name|uint
name|count
block|;
name|QMutex
name|mutex
block|;
name|bool
name|lock
argument_list|(
argument|int timeout
argument_list|)
block|;
name|void
name|unlock
argument_list|()
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
comment|// QMUTEX_P_H
end_comment
end_unit
