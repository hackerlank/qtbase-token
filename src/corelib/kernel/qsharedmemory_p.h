begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QSHAREDMEMORY_P_H
end_ifndef
begin_define
DECL|macro|QSHAREDMEMORY_P_H
define|#
directive|define
name|QSHAREDMEMORY_P_H
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
file|"qsharedmemory.h"
end_include
begin_ifdef
ifdef|#
directive|ifdef
name|QT_NO_SHAREDMEMORY
end_ifdef
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_SYSTEMSEMAPHORE
end_ifndef
begin_decl_stmt
name|namespace
name|QSharedMemoryPrivate
block|{
name|int
name|createUnixKeyFile
parameter_list|(
specifier|const
name|QString
modifier|&
name|fileName
parameter_list|)
function_decl|;
name|QString
name|makePlatformSafeKey
parameter_list|(
specifier|const
name|QString
modifier|&
name|key
parameter_list|,
specifier|const
name|QString
modifier|&
name|prefix
init|=
name|QLatin1String
argument_list|(
literal|"qipc_sharedmemory_"
argument_list|)
parameter_list|)
function_decl|;
block|}
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_else
else|#
directive|else
end_else
begin_include
include|#
directive|include
file|"qsystemsemaphore.h"
end_include
begin_include
include|#
directive|include
file|"private/qobject_p.h"
end_include
begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|Q_OS_WIN
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|Q_OS_ANDROID
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|Q_OS_INTEGRITY
argument_list|)
end_if
begin_include
include|#
directive|include
file|<sys/sem.h>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
ifndef|#
directive|ifndef
name|QT_NO_SYSTEMSEMAPHORE
comment|/*!   Helper class   */
name|class
name|QSharedMemoryLocker
block|{
name|public
label|:
specifier|inline
name|QSharedMemoryLocker
argument_list|(
name|QSharedMemory
operator|*
name|sharedMemory
argument_list|)
operator|:
name|q_sm
argument_list|(
argument|sharedMemory
argument_list|)
block|{
name|Q_ASSERT
argument_list|(
name|q_sm
argument_list|)
block|;     }
specifier|inline
operator|~
name|QSharedMemoryLocker
argument_list|()
block|{
if|if
condition|(
name|q_sm
condition|)
name|q_sm
operator|->
name|unlock
argument_list|()
expr_stmt|;
block|}
specifier|inline
name|bool
name|lock
parameter_list|()
block|{
if|if
condition|(
name|q_sm
operator|&&
name|q_sm
operator|->
name|lock
argument_list|()
condition|)
return|return
name|true
return|;
name|q_sm
operator|=
literal|0
expr_stmt|;
return|return
name|false
return|;
block|}
name|private
label|:
name|QSharedMemory
modifier|*
name|q_sm
decl_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_SYSTEMSEMAPHORE
end_comment
begin_decl_stmt
name|class
name|Q_AUTOTEST_EXPORT
name|QSharedMemoryPrivate
range|:
name|public
name|QObjectPrivate
block|{
name|Q_DECLARE_PUBLIC
argument_list|(
argument|QSharedMemory
argument_list|)
name|public
operator|:
name|QSharedMemoryPrivate
argument_list|()
block|;
name|void
operator|*
name|memory
block|;
name|int
name|size
block|;
name|QString
name|key
block|;
name|QString
name|nativeKey
block|;
name|QSharedMemory
operator|::
name|SharedMemoryError
name|error
block|;
name|QString
name|errorString
block|;
ifndef|#
directive|ifndef
name|QT_NO_SYSTEMSEMAPHORE
name|QSystemSemaphore
name|systemSemaphore
block|;
name|bool
name|lockedByMe
block|;
endif|#
directive|endif
specifier|static
name|int
name|createUnixKeyFile
argument_list|(
specifier|const
name|QString
operator|&
name|fileName
argument_list|)
block|;
specifier|static
name|QString
name|makePlatformSafeKey
argument_list|(
specifier|const
name|QString
operator|&
name|key
argument_list|,
specifier|const
name|QString
operator|&
name|prefix
operator|=
name|QLatin1String
argument_list|(
literal|"qipc_sharedmemory_"
argument_list|)
argument_list|)
block|;
ifdef|#
directive|ifdef
name|Q_OS_WIN
name|Qt
operator|::
name|HANDLE
name|handle
argument_list|()
block|;
elif|#
directive|elif
name|defined
argument_list|(
name|QT_POSIX_IPC
argument_list|)
name|int
name|handle
argument_list|()
block|;
else|#
directive|else
name|key_t
name|handle
argument_list|()
block|;
endif|#
directive|endif
name|bool
name|initKey
argument_list|()
block|;
name|bool
name|cleanHandle
argument_list|()
block|;
name|bool
name|create
argument_list|(
argument|int size
argument_list|)
block|;
name|bool
name|attach
argument_list|(
argument|QSharedMemory::AccessMode mode
argument_list|)
block|;
name|bool
name|detach
argument_list|()
block|;
name|void
name|setErrorString
argument_list|(
argument|QLatin1String function
argument_list|)
block|;
ifndef|#
directive|ifndef
name|QT_NO_SYSTEMSEMAPHORE
name|bool
name|tryLocker
argument_list|(
argument|QSharedMemoryLocker *locker
argument_list|,
argument|const QString&function
argument_list|)
block|{
if|if
condition|(
operator|!
name|locker
operator|->
name|lock
argument_list|()
condition|)
block|{
name|errorString
operator|=
name|QSharedMemory
operator|::
name|tr
argument_list|(
literal|"%1: unable to lock"
argument_list|)
operator|.
name|arg
argument_list|(
name|function
argument_list|)
expr_stmt|;
name|error
operator|=
name|QSharedMemory
operator|::
name|LockError
expr_stmt|;
return|return
name|false
return|;
block|}
return|return
name|true
return|;
block|}
endif|#
directive|endif
comment|// QT_NO_SYSTEMSEMAPHORE
name|private
operator|:
ifdef|#
directive|ifdef
name|Q_OS_WIN
name|Qt
operator|::
name|HANDLE
name|hand
block|;
elif|#
directive|elif
name|defined
argument_list|(
name|QT_POSIX_IPC
argument_list|)
name|int
name|hand
block|;
else|#
directive|else
name|key_t
name|unix_key
block|;
endif|#
directive|endif
block|}
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
comment|// QT_NO_SHAREDMEMORY
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QSHAREDMEMORY_P_H
end_comment
end_unit
