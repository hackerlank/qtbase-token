begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qsystemlock.h"
end_include
begin_include
include|#
directive|include
file|"qsystemlock_p.h"
end_include
begin_include
include|#
directive|include
file|<qdebug.h>
end_include
begin_include
include|#
directive|include
file|<qfile.h>
end_include
begin_include
include|#
directive|include
file|<sys/types.h>
end_include
begin_include
include|#
directive|include
file|<sys/ipc.h>
end_include
begin_include
include|#
directive|include
file|<fcntl.h>
end_include
begin_include
include|#
directive|include
file|<errno.h>
end_include
begin_include
include|#
directive|include
file|<sys/shm.h>
end_include
begin_include
include|#
directive|include
file|<unistd.h>
end_include
begin_include
include|#
directive|include
file|<sys/sem.h>
end_include
begin_comment
comment|// We have to define this as on some sem.h will have it
end_comment
begin_union
DECL|union|qt_semun
union|union
name|qt_semun
block|{
DECL|member|val
name|int
name|val
decl_stmt|;
comment|/* value for SETVAL */
DECL|member|buf
name|struct
name|semid_ds
modifier|*
name|buf
decl_stmt|;
comment|/* buffer for IPC_STAT, IPC_SET */
DECL|member|array
name|unsigned
name|short
modifier|*
name|array
decl_stmt|;
comment|/* array for GETALL, SETALL */
block|}
union|;
end_union
begin_define
DECL|macro|tr
define|#
directive|define
name|tr
parameter_list|(
name|x
parameter_list|)
value|QT_TRANSLATE_NOOP(QLatin1String("QSystemLock"), (x))
end_define
begin_constructor
DECL|function|QSystemLockPrivate
name|QSystemLockPrivate
operator|::
name|QSystemLockPrivate
parameter_list|()
member_init_list|:
name|semaphore
argument_list|(
operator|-
literal|1
argument_list|)
member_init_list|,
name|lockCount
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|error
argument_list|(
name|QSystemLock
operator|::
name|NoError
argument_list|)
member_init_list|,
name|unix_key
argument_list|(
operator|-
literal|1
argument_list|)
member_init_list|,
name|createdFile
argument_list|(
literal|false
argument_list|)
member_init_list|,
name|createdSemaphore
argument_list|(
literal|false
argument_list|)
block|{ }
end_constructor
begin_function
DECL|function|setErrorString
name|void
name|QSystemLockPrivate
operator|::
name|setErrorString
parameter_list|(
specifier|const
name|QString
modifier|&
name|function
parameter_list|)
block|{
switch|switch
condition|(
name|errno
condition|)
block|{
case|case
name|EIDRM
case|:
name|errorString
operator|=
name|function
operator|+
name|QLatin1String
argument_list|(
literal|": "
argument_list|)
operator|+
name|tr
argument_list|(
literal|"The semaphore set was removed"
argument_list|)
expr_stmt|;
name|error
operator|=
name|QSystemLock
operator|::
name|UnknownError
expr_stmt|;
break|break;
default|default:
name|errorString
operator|=
name|function
operator|+
name|QLatin1String
argument_list|(
literal|": "
argument_list|)
operator|+
name|tr
argument_list|(
literal|"unknown error"
argument_list|)
expr_stmt|;
name|error
operator|=
name|QSystemLock
operator|::
name|UnknownError
expr_stmt|;
name|qWarning
argument_list|()
operator|<<
name|errorString
operator|<<
literal|"key"
operator|<<
name|key
operator|<<
literal|"errno"
operator|<<
name|errno
operator|<<
name|ERANGE
operator|<<
name|ENOMEM
operator|<<
name|EINVAL
operator|<<
name|EINTR
operator|<<
name|EFBIG
operator|<<
name|EFAULT
operator|<<
name|EAGAIN
operator|<<
name|EACCES
operator|<<
name|E2BIG
expr_stmt|;
block|}
block|}
end_function
begin_comment
comment|/*!     \internal      Setup unix_key  */
end_comment
begin_function
DECL|function|handle
name|key_t
name|QSystemLockPrivate
operator|::
name|handle
parameter_list|()
block|{
if|if
condition|(
name|key
operator|.
name|isEmpty
argument_list|()
condition|)
return|return
operator|-
literal|1
return|;
comment|// ftok requires that an actual file exists somewhere
comment|// If we have already made at some point in the past,
comment|// double check that it is still there.
if|if
condition|(
operator|-
literal|1
operator|!=
name|unix_key
condition|)
block|{
name|int
name|aNewunix_key
init|=
name|ftok
argument_list|(
name|QFile
operator|::
name|encodeName
argument_list|(
name|fileName
argument_list|)
operator|.
name|constData
argument_list|()
argument_list|,
literal|'Q'
argument_list|)
decl_stmt|;
if|if
condition|(
name|aNewunix_key
operator|!=
name|unix_key
condition|)
block|{
name|cleanHandle
argument_list|()
expr_stmt|;
block|}
else|else
block|{
return|return
name|unix_key
return|;
block|}
block|}
comment|// Create the file needed for ftok
name|int
name|built
init|=
name|QSharedMemoryPrivate
operator|::
name|createUnixKeyFile
argument_list|(
name|fileName
argument_list|)
decl_stmt|;
if|if
condition|(
operator|-
literal|1
operator|==
name|built
condition|)
return|return
operator|-
literal|1
return|;
name|createdFile
operator|=
operator|(
literal|1
operator|==
name|built
operator|)
expr_stmt|;
comment|// Get the unix key for the created file
name|unix_key
operator|=
name|ftok
argument_list|(
name|QFile
operator|::
name|encodeName
argument_list|(
name|fileName
argument_list|)
operator|.
name|constData
argument_list|()
argument_list|,
literal|'Q'
argument_list|)
expr_stmt|;
if|if
condition|(
operator|-
literal|1
operator|==
name|unix_key
condition|)
block|{
name|setErrorString
argument_list|(
name|QLatin1String
argument_list|(
literal|"QSystemLock::handle ftok"
argument_list|)
argument_list|)
expr_stmt|;
return|return
operator|-
literal|1
return|;
block|}
comment|// Get semaphore
name|semaphore
operator|=
name|semget
argument_list|(
name|unix_key
argument_list|,
literal|1
argument_list|,
literal|0666
operator||
name|IPC_CREAT
operator||
name|IPC_EXCL
argument_list|)
expr_stmt|;
if|if
condition|(
operator|-
literal|1
operator|==
name|semaphore
condition|)
block|{
if|if
condition|(
name|errno
operator|==
name|EEXIST
condition|)
name|semaphore
operator|=
name|semget
argument_list|(
name|unix_key
argument_list|,
literal|1
argument_list|,
literal|0666
operator||
name|IPC_CREAT
argument_list|)
expr_stmt|;
if|if
condition|(
operator|-
literal|1
operator|==
name|semaphore
condition|)
block|{
name|setErrorString
argument_list|(
name|QLatin1String
argument_list|(
literal|"QSystemLock::handle semget"
argument_list|)
argument_list|)
expr_stmt|;
name|cleanHandle
argument_list|()
expr_stmt|;
return|return
operator|-
literal|1
return|;
block|}
block|}
else|else
block|{
comment|// Created semaphore, initialize value.
name|createdSemaphore
operator|=
literal|true
expr_stmt|;
name|qt_semun
name|init_op
decl_stmt|;
name|init_op
operator|.
name|val
operator|=
name|MAX_LOCKS
expr_stmt|;
if|if
condition|(
operator|-
literal|1
operator|==
name|semctl
argument_list|(
name|semaphore
argument_list|,
literal|0
argument_list|,
name|SETVAL
argument_list|,
name|init_op
argument_list|)
condition|)
block|{
name|setErrorString
argument_list|(
name|QLatin1String
argument_list|(
literal|"QSystemLock::handle semctl"
argument_list|)
argument_list|)
expr_stmt|;
name|cleanHandle
argument_list|()
expr_stmt|;
return|return
operator|-
literal|1
return|;
block|}
block|}
return|return
name|unix_key
return|;
block|}
end_function
begin_comment
comment|/*!     \internal      Cleanup the unix_key  */
end_comment
begin_function
DECL|function|cleanHandle
name|void
name|QSystemLockPrivate
operator|::
name|cleanHandle
parameter_list|()
block|{
name|unix_key
operator|=
operator|-
literal|1
expr_stmt|;
comment|// remove the file if we made it
if|if
condition|(
name|createdFile
condition|)
block|{
if|if
condition|(
operator|!
name|QFile
operator|::
name|remove
argument_list|(
name|fileName
argument_list|)
condition|)
name|setErrorString
argument_list|(
name|QLatin1String
argument_list|(
literal|"QSystemLock::cleanHandle QFile::remove"
argument_list|)
argument_list|)
expr_stmt|;
name|createdFile
operator|=
literal|false
expr_stmt|;
block|}
if|if
condition|(
name|createdSemaphore
condition|)
block|{
if|if
condition|(
operator|-
literal|1
operator|!=
name|semaphore
condition|)
block|{
if|if
condition|(
operator|-
literal|1
operator|==
name|semctl
argument_list|(
name|semaphore
argument_list|,
literal|0
argument_list|,
name|IPC_RMID
argument_list|)
condition|)
block|{
name|setErrorString
argument_list|(
name|QLatin1String
argument_list|(
literal|"QSystemLock::cleanHandle semctl"
argument_list|)
argument_list|)
expr_stmt|;
block|}
name|semaphore
operator|=
operator|-
literal|1
expr_stmt|;
block|}
name|createdSemaphore
operator|=
literal|false
expr_stmt|;
block|}
block|}
end_function
begin_comment
comment|/*!     \internal      modifySemaphore generates operation.sem_op and handles recursive behavior.  */
end_comment
begin_function
DECL|function|modifySemaphore
name|bool
name|QSystemLockPrivate
operator|::
name|modifySemaphore
parameter_list|(
name|QSystemLockPrivate
operator|::
name|Operation
name|op
parameter_list|,
name|QSystemLock
operator|::
name|LockMode
name|mode
parameter_list|)
block|{
if|if
condition|(
operator|-
literal|1
operator|==
name|handle
argument_list|()
condition|)
return|return
literal|false
return|;
if|if
condition|(
operator|(
name|lockCount
operator|==
literal|0
operator|&&
name|op
operator|==
name|Lock
operator|)
operator|||
operator|(
name|lockCount
operator|>
literal|0
operator|&&
name|op
operator|==
name|Unlock
operator|)
condition|)
block|{
if|if
condition|(
name|op
operator|==
name|Unlock
condition|)
block|{
operator|--
name|lockCount
expr_stmt|;
if|if
condition|(
name|lockCount
operator|<
literal|0
condition|)
name|qFatal
argument_list|(
literal|"%s: lockCount must not be negative"
argument_list|,
name|Q_FUNC_INFO
argument_list|)
expr_stmt|;
if|if
condition|(
name|lockCount
operator|>
literal|0
condition|)
return|return
literal|true
return|;
block|}
name|struct
name|sembuf
name|operation
decl_stmt|;
name|operation
operator|.
name|sem_num
operator|=
literal|0
expr_stmt|;
name|operation
operator|.
name|sem_op
operator|=
operator|(
name|mode
operator|==
name|QSystemLock
operator|::
name|ReadWrite
operator|)
condition|?
name|MAX_LOCKS
else|:
literal|1
expr_stmt|;
if|if
condition|(
name|op
operator|==
name|Lock
condition|)
name|operation
operator|.
name|sem_op
operator|*=
operator|-
literal|1
expr_stmt|;
name|operation
operator|.
name|sem_flg
operator|=
name|SEM_UNDO
expr_stmt|;
if|if
condition|(
operator|-
literal|1
operator|==
name|semop
argument_list|(
name|semaphore
argument_list|,
operator|&
name|operation
argument_list|,
literal|1
argument_list|)
condition|)
block|{
name|setErrorString
argument_list|(
name|QLatin1String
argument_list|(
literal|"QSystemLock::modify"
argument_list|)
argument_list|)
expr_stmt|;
return|return
literal|false
return|;
block|}
name|lockedMode
operator|=
name|mode
expr_stmt|;
block|}
if|if
condition|(
name|op
operator|==
name|Lock
condition|)
name|lockCount
operator|++
expr_stmt|;
return|return
literal|true
return|;
block|}
end_function
end_unit
