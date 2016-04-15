begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 David Faure<faure+bluesystems@kde.org> ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"private/qlockfile_p.h"
end_include
begin_include
include|#
directive|include
file|"QtCore/qtemporaryfile.h"
end_include
begin_include
include|#
directive|include
file|"QtCore/qcoreapplication.h"
end_include
begin_include
include|#
directive|include
file|"QtCore/qfileinfo.h"
end_include
begin_include
include|#
directive|include
file|"QtCore/qdebug.h"
end_include
begin_include
include|#
directive|include
file|"QtCore/qdatetime.h"
end_include
begin_include
include|#
directive|include
file|"QtCore/qfileinfo.h"
end_include
begin_include
include|#
directive|include
file|"QtCore/qcache.h"
end_include
begin_include
include|#
directive|include
file|"QtCore/qglobalstatic.h"
end_include
begin_include
include|#
directive|include
file|"QtCore/qmutex.h"
end_include
begin_include
include|#
directive|include
file|"private/qcore_unix_p.h"
end_include
begin_comment
comment|// qt_safe_open
end_comment
begin_include
include|#
directive|include
file|"private/qabstractfileengine_p.h"
end_include
begin_include
include|#
directive|include
file|"private/qtemporaryfile_p.h"
end_include
begin_include
include|#
directive|include
file|<sys/file.h>
end_include
begin_comment
comment|// flock
end_comment
begin_include
include|#
directive|include
file|<sys/types.h>
end_include
begin_comment
comment|// kill
end_comment
begin_include
include|#
directive|include
file|<signal.h>
end_include
begin_comment
comment|// kill
end_comment
begin_include
include|#
directive|include
file|<unistd.h>
end_include
begin_comment
comment|// gethostname
end_comment
begin_if
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_OSX
argument_list|)
end_if
begin_include
include|#
directive|include
file|<libproc.h>
end_include
begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|Q_OS_LINUX
argument_list|)
end_elif
begin_include
include|#
directive|include
file|<unistd.h>
end_include
begin_include
include|#
directive|include
file|<cstdio>
end_include
begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|Q_OS_BSD4
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|Q_OS_IOS
argument_list|)
end_elif
begin_include
include|#
directive|include
file|<sys/user.h>
end_include
begin_if
if|#
directive|if
name|defined
argument_list|(
name|__GLIBC__
argument_list|)
operator|&&
name|defined
argument_list|(
name|__FreeBSD_kernel__
argument_list|)
end_if
begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include
begin_include
include|#
directive|include
file|<sys/param.h>
end_include
begin_include
include|#
directive|include
file|<sys/sysctl.h>
end_include
begin_else
else|#
directive|else
end_else
begin_include
include|#
directive|include
file|<libutil.h>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_endif
endif|#
directive|endif
end_endif
begin_function
name|QT_BEGIN_NAMESPACE
DECL|function|localHostName
specifier|static
name|QByteArray
name|localHostName
parameter_list|()
comment|// from QHostInfo::localHostName(), modified to return a QByteArray
block|{
name|QByteArray
name|hostName
argument_list|(
literal|512
argument_list|,
name|Qt
operator|::
name|Uninitialized
argument_list|)
decl_stmt|;
if|if
condition|(
name|gethostname
argument_list|(
name|hostName
operator|.
name|data
argument_list|()
argument_list|,
name|hostName
operator|.
name|size
argument_list|()
argument_list|)
operator|==
operator|-
literal|1
condition|)
return|return
name|QByteArray
argument_list|()
return|;
name|hostName
operator|.
name|truncate
argument_list|(
name|strlen
argument_list|(
name|hostName
operator|.
name|data
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|hostName
return|;
block|}
end_function
begin_comment
comment|// ### merge into qt_safe_write?
end_comment
begin_function
DECL|function|qt_write_loop
specifier|static
name|qint64
name|qt_write_loop
parameter_list|(
name|int
name|fd
parameter_list|,
specifier|const
name|char
modifier|*
name|data
parameter_list|,
name|qint64
name|len
parameter_list|)
block|{
name|qint64
name|pos
init|=
literal|0
decl_stmt|;
while|while
condition|(
name|pos
operator|<
name|len
condition|)
block|{
specifier|const
name|qint64
name|ret
init|=
name|qt_safe_write
argument_list|(
name|fd
argument_list|,
name|data
operator|+
name|pos
argument_list|,
name|len
operator|-
name|pos
argument_list|)
decl_stmt|;
if|if
condition|(
name|ret
operator|==
operator|-
literal|1
condition|)
comment|// e.g. partition full
return|return
name|pos
return|;
name|pos
operator|+=
name|ret
expr_stmt|;
block|}
return|return
name|pos
return|;
block|}
end_function
begin_function
DECL|function|checkFcntlWorksAfterFlock
name|int
name|QLockFilePrivate
operator|::
name|checkFcntlWorksAfterFlock
parameter_list|(
specifier|const
name|QString
modifier|&
name|fn
parameter_list|)
block|{
ifndef|#
directive|ifndef
name|QT_NO_TEMPORARYFILE
name|QTemporaryFile
name|file
argument_list|(
name|fn
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|file
operator|.
name|open
argument_list|()
condition|)
return|return
literal|0
return|;
specifier|const
name|int
name|fd
init|=
name|file
operator|.
name|d_func
argument_list|()
operator|->
name|engine
argument_list|()
operator|->
name|handle
argument_list|()
decl_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|LOCK_EX
argument_list|)
operator|&&
name|defined
argument_list|(
name|LOCK_NB
argument_list|)
if|if
condition|(
name|flock
argument_list|(
name|fd
argument_list|,
name|LOCK_EX
operator||
name|LOCK_NB
argument_list|)
operator|==
operator|-
literal|1
condition|)
comment|// other threads, and other processes on a local fs
return|return
literal|0
return|;
endif|#
directive|endif
name|struct
name|flock
name|flockData
decl_stmt|;
name|flockData
operator|.
name|l_type
operator|=
name|F_WRLCK
expr_stmt|;
name|flockData
operator|.
name|l_whence
operator|=
name|SEEK_SET
expr_stmt|;
name|flockData
operator|.
name|l_start
operator|=
literal|0
expr_stmt|;
name|flockData
operator|.
name|l_len
operator|=
literal|0
expr_stmt|;
comment|// 0 = entire file
name|flockData
operator|.
name|l_pid
operator|=
name|getpid
argument_list|()
expr_stmt|;
if|if
condition|(
name|fcntl
argument_list|(
name|fd
argument_list|,
name|F_SETLK
argument_list|,
operator|&
name|flockData
argument_list|)
operator|==
operator|-
literal|1
condition|)
comment|// for networked filesystems
return|return
literal|0
return|;
return|return
literal|1
return|;
else|#
directive|else
return|return
literal|0
return|;
endif|#
directive|endif
block|}
end_function
begin_comment
comment|// Cache the result of checkFcntlWorksAfterFlock for each directory a lock
end_comment
begin_comment
comment|// file is created in because in some filesystems, like NFS, both locks
end_comment
begin_comment
comment|// are the same.  This does not take into account a filesystem changing.
end_comment
begin_comment
comment|// QCache is set to hold a maximum of 10 entries, this is to avoid unbounded
end_comment
begin_comment
comment|// growth, this is caching directories of files and it is assumed a low number
end_comment
begin_comment
comment|// will be sufficient.
end_comment
begin_typedef
DECL|typedef|CacheType
typedef|typedef
name|QCache
argument_list|<
name|QString
argument_list|,
name|bool
argument_list|>
name|CacheType
typedef|;
end_typedef
begin_expr_stmt
name|Q_GLOBAL_STATIC_WITH_ARGS
argument_list|(
name|CacheType
argument_list|,
name|fcntlOK
argument_list|,
operator|(
literal|10
operator|)
argument_list|)
expr_stmt|;
end_expr_stmt
begin_decl_stmt
DECL|variable|fcntlLock
specifier|static
name|QBasicMutex
name|fcntlLock
decl_stmt|;
end_decl_stmt
begin_comment
comment|/*!   \internal   Checks that the OS isn't using POSIX locks to emulate flock().   OS X is one of those. */
end_comment
begin_function
DECL|function|fcntlWorksAfterFlock
specifier|static
name|bool
name|fcntlWorksAfterFlock
parameter_list|(
specifier|const
name|QString
modifier|&
name|fn
parameter_list|)
block|{
name|QMutexLocker
name|lock
argument_list|(
operator|&
name|fcntlLock
argument_list|)
decl_stmt|;
if|if
condition|(
name|fcntlOK
operator|.
name|isDestroyed
argument_list|()
condition|)
return|return
name|QLockFilePrivate
operator|::
name|checkFcntlWorksAfterFlock
argument_list|(
name|fn
argument_list|)
return|;
name|bool
modifier|*
name|worksPtr
init|=
name|fcntlOK
operator|->
name|object
argument_list|(
name|fn
argument_list|)
decl_stmt|;
if|if
condition|(
name|worksPtr
condition|)
return|return
operator|*
name|worksPtr
return|;
specifier|const
name|bool
name|val
init|=
name|QLockFilePrivate
operator|::
name|checkFcntlWorksAfterFlock
argument_list|(
name|fn
argument_list|)
decl_stmt|;
name|worksPtr
operator|=
operator|new
name|bool
argument_list|(
name|val
argument_list|)
expr_stmt|;
name|fcntlOK
operator|->
name|insert
argument_list|(
name|fn
argument_list|,
name|worksPtr
argument_list|)
expr_stmt|;
return|return
name|val
return|;
block|}
end_function
begin_function
DECL|function|setNativeLocks
specifier|static
name|bool
name|setNativeLocks
parameter_list|(
specifier|const
name|QString
modifier|&
name|fileName
parameter_list|,
name|int
name|fd
parameter_list|)
block|{
if|#
directive|if
name|defined
argument_list|(
name|LOCK_EX
argument_list|)
operator|&&
name|defined
argument_list|(
name|LOCK_NB
argument_list|)
if|if
condition|(
name|flock
argument_list|(
name|fd
argument_list|,
name|LOCK_EX
operator||
name|LOCK_NB
argument_list|)
operator|==
operator|-
literal|1
condition|)
comment|// other threads, and other processes on a local fs
return|return
literal|false
return|;
endif|#
directive|endif
name|struct
name|flock
name|flockData
decl_stmt|;
name|flockData
operator|.
name|l_type
operator|=
name|F_WRLCK
expr_stmt|;
name|flockData
operator|.
name|l_whence
operator|=
name|SEEK_SET
expr_stmt|;
name|flockData
operator|.
name|l_start
operator|=
literal|0
expr_stmt|;
name|flockData
operator|.
name|l_len
operator|=
literal|0
expr_stmt|;
comment|// 0 = entire file
name|flockData
operator|.
name|l_pid
operator|=
name|getpid
argument_list|()
expr_stmt|;
if|if
condition|(
name|fcntlWorksAfterFlock
argument_list|(
name|QDir
operator|::
name|cleanPath
argument_list|(
name|QFileInfo
argument_list|(
name|fileName
argument_list|)
operator|.
name|absolutePath
argument_list|()
argument_list|)
operator|+
name|QString
argument_list|(
literal|'/'
argument_list|)
argument_list|)
operator|&&
name|fcntl
argument_list|(
name|fd
argument_list|,
name|F_SETLK
argument_list|,
operator|&
name|flockData
argument_list|)
operator|==
operator|-
literal|1
condition|)
block|{
comment|// for networked filesystems
return|return
literal|false
return|;
block|}
return|return
literal|true
return|;
block|}
end_function
begin_function
DECL|function|tryLock_sys
name|QLockFile
operator|::
name|LockError
name|QLockFilePrivate
operator|::
name|tryLock_sys
parameter_list|()
block|{
comment|// Assemble data, to write in a single call to write
comment|// (otherwise we'd have to check every write call)
comment|// Use operator% from the fast builder to avoid multiple memory allocations.
name|QByteArray
name|fileData
init|=
name|QByteArray
operator|::
name|number
argument_list|(
name|QCoreApplication
operator|::
name|applicationPid
argument_list|()
argument_list|)
operator|%
literal|'\n'
operator|%
name|QCoreApplication
operator|::
name|applicationName
argument_list|()
operator|.
name|toUtf8
argument_list|()
operator|%
literal|'\n'
operator|%
name|localHostName
argument_list|()
operator|%
literal|'\n'
decl_stmt|;
specifier|const
name|QByteArray
name|lockFileName
init|=
name|QFile
operator|::
name|encodeName
argument_list|(
name|fileName
argument_list|)
decl_stmt|;
specifier|const
name|int
name|fd
init|=
name|qt_safe_open
argument_list|(
name|lockFileName
operator|.
name|constData
argument_list|()
argument_list|,
name|O_WRONLY
operator||
name|O_CREAT
operator||
name|O_EXCL
argument_list|,
literal|0644
argument_list|)
decl_stmt|;
if|if
condition|(
name|fd
operator|<
literal|0
condition|)
block|{
switch|switch
condition|(
name|errno
condition|)
block|{
case|case
name|EEXIST
case|:
return|return
name|QLockFile
operator|::
name|LockFailedError
return|;
case|case
name|EACCES
case|:
case|case
name|EROFS
case|:
return|return
name|QLockFile
operator|::
name|PermissionError
return|;
default|default:
return|return
name|QLockFile
operator|::
name|UnknownError
return|;
block|}
block|}
comment|// Ensure nobody else can delete the file while we have it
if|if
condition|(
operator|!
name|setNativeLocks
argument_list|(
name|fileName
argument_list|,
name|fd
argument_list|)
condition|)
block|{
specifier|const
name|int
name|errnoSaved
init|=
name|errno
decl_stmt|;
name|qWarning
argument_list|()
operator|<<
literal|"setNativeLocks failed:"
operator|<<
name|qt_error_string
argument_list|(
name|errnoSaved
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|qt_write_loop
argument_list|(
name|fd
argument_list|,
name|fileData
operator|.
name|constData
argument_list|()
argument_list|,
name|fileData
operator|.
name|size
argument_list|()
argument_list|)
operator|<
name|fileData
operator|.
name|size
argument_list|()
condition|)
block|{
name|close
argument_list|(
name|fd
argument_list|)
expr_stmt|;
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
name|qWarning
argument_list|(
literal|"QLockFile: Could not remove our own lock file %s."
argument_list|,
name|qPrintable
argument_list|(
name|fileName
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|QLockFile
operator|::
name|UnknownError
return|;
comment|// partition full
block|}
comment|// We hold the lock, continue.
name|fileHandle
operator|=
name|fd
expr_stmt|;
comment|// Sync to disk if possible. Ignore errors (e.g. not supported).
if|#
directive|if
name|defined
argument_list|(
name|_POSIX_SYNCHRONIZED_IO
argument_list|)
operator|&&
name|_POSIX_SYNCHRONIZED_IO
operator|>
literal|0
name|fdatasync
argument_list|(
name|fileHandle
argument_list|)
expr_stmt|;
else|#
directive|else
name|fsync
argument_list|(
name|fileHandle
argument_list|)
expr_stmt|;
endif|#
directive|endif
return|return
name|QLockFile
operator|::
name|NoError
return|;
block|}
end_function
begin_function
DECL|function|removeStaleLock
name|bool
name|QLockFilePrivate
operator|::
name|removeStaleLock
parameter_list|()
block|{
specifier|const
name|QByteArray
name|lockFileName
init|=
name|QFile
operator|::
name|encodeName
argument_list|(
name|fileName
argument_list|)
decl_stmt|;
specifier|const
name|int
name|fd
init|=
name|qt_safe_open
argument_list|(
name|lockFileName
operator|.
name|constData
argument_list|()
argument_list|,
name|O_WRONLY
argument_list|,
literal|0644
argument_list|)
decl_stmt|;
if|if
condition|(
name|fd
operator|<
literal|0
condition|)
comment|// gone already?
return|return
literal|false
return|;
name|bool
name|success
init|=
name|setNativeLocks
argument_list|(
name|fileName
argument_list|,
name|fd
argument_list|)
operator|&&
operator|(
operator|::
name|unlink
argument_list|(
name|lockFileName
argument_list|)
operator|==
literal|0
operator|)
decl_stmt|;
name|close
argument_list|(
name|fd
argument_list|)
expr_stmt|;
return|return
name|success
return|;
block|}
end_function
begin_function
DECL|function|isApparentlyStale
name|bool
name|QLockFilePrivate
operator|::
name|isApparentlyStale
parameter_list|()
specifier|const
block|{
name|qint64
name|pid
decl_stmt|;
name|QString
name|hostname
decl_stmt|,
name|appname
decl_stmt|;
if|if
condition|(
name|getLockInfo
argument_list|(
operator|&
name|pid
argument_list|,
operator|&
name|hostname
argument_list|,
operator|&
name|appname
argument_list|)
condition|)
block|{
if|if
condition|(
name|hostname
operator|.
name|isEmpty
argument_list|()
operator|||
name|hostname
operator|==
name|QString
operator|::
name|fromLocal8Bit
argument_list|(
name|localHostName
argument_list|()
argument_list|)
condition|)
block|{
if|if
condition|(
operator|::
name|kill
argument_list|(
name|pid
argument_list|,
literal|0
argument_list|)
operator|==
operator|-
literal|1
operator|&&
name|errno
operator|==
name|ESRCH
condition|)
return|return
literal|true
return|;
comment|// PID doesn't exist anymore
specifier|const
name|QString
name|processName
init|=
name|processNameByPid
argument_list|(
name|pid
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|processName
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|QFileInfo
name|fi
argument_list|(
name|appname
argument_list|)
decl_stmt|;
if|if
condition|(
name|fi
operator|.
name|isSymLink
argument_list|()
condition|)
name|fi
operator|.
name|setFile
argument_list|(
name|fi
operator|.
name|symLinkTarget
argument_list|()
argument_list|)
expr_stmt|;
if|if
condition|(
name|processName
operator|!=
name|fi
operator|.
name|fileName
argument_list|()
condition|)
return|return
literal|true
return|;
comment|// PID got reused by a different application.
block|}
block|}
block|}
specifier|const
name|qint64
name|age
init|=
name|QFileInfo
argument_list|(
name|fileName
argument_list|)
operator|.
name|lastModified
argument_list|()
operator|.
name|msecsTo
argument_list|(
name|QDateTime
operator|::
name|currentDateTime
argument_list|()
argument_list|)
decl_stmt|;
return|return
name|staleLockTime
operator|>
literal|0
operator|&&
name|age
operator|>
name|staleLockTime
return|;
block|}
end_function
begin_function
DECL|function|processNameByPid
name|QString
name|QLockFilePrivate
operator|::
name|processNameByPid
parameter_list|(
name|qint64
name|pid
parameter_list|)
block|{
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_OSX
argument_list|)
name|char
name|name
index|[
literal|1024
index|]
decl_stmt|;
name|proc_name
argument_list|(
name|pid
argument_list|,
name|name
argument_list|,
sizeof|sizeof
argument_list|(
name|name
argument_list|)
operator|/
sizeof|sizeof
argument_list|(
name|char
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|QFile
operator|::
name|decodeName
argument_list|(
name|name
argument_list|)
return|;
elif|#
directive|elif
name|defined
argument_list|(
name|Q_OS_LINUX
argument_list|)
if|if
condition|(
operator|!
name|QFile
operator|::
name|exists
argument_list|(
name|QStringLiteral
argument_list|(
literal|"/proc/version"
argument_list|)
argument_list|)
condition|)
return|return
name|QString
argument_list|()
return|;
name|char
name|exePath
index|[
literal|64
index|]
decl_stmt|;
name|char
name|buf
index|[
name|PATH_MAX
operator|+
literal|1
index|]
decl_stmt|;
name|sprintf
argument_list|(
name|exePath
argument_list|,
literal|"/proc/%lld/exe"
argument_list|,
name|pid
argument_list|)
expr_stmt|;
name|size_t
name|len
init|=
operator|(
name|size_t
operator|)
name|readlink
argument_list|(
name|exePath
argument_list|,
name|buf
argument_list|,
sizeof|sizeof
argument_list|(
name|buf
argument_list|)
argument_list|)
decl_stmt|;
if|if
condition|(
name|len
operator|>=
sizeof|sizeof
argument_list|(
name|buf
argument_list|)
condition|)
block|{
comment|// The pid is gone. Return some invalid process name to fail the test.
return|return
name|QStringLiteral
argument_list|(
literal|"/ERROR/"
argument_list|)
return|;
block|}
name|buf
index|[
name|len
index|]
operator|=
literal|0
expr_stmt|;
return|return
name|QFileInfo
argument_list|(
name|QFile
operator|::
name|decodeName
argument_list|(
name|buf
argument_list|)
argument_list|)
operator|.
name|fileName
argument_list|()
return|;
elif|#
directive|elif
name|defined
argument_list|(
name|Q_OS_BSD4
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|Q_OS_IOS
argument_list|)
if|#
directive|if
name|defined
argument_list|(
name|__GLIBC__
argument_list|)
operator|&&
name|defined
argument_list|(
name|__FreeBSD_kernel__
argument_list|)
name|int
name|mib
index|[
literal|4
index|]
init|=
block|{
name|CTL_KERN
block|,
name|KERN_PROC
block|,
name|KERN_PROC_PID
block|,
name|pid
block|}
decl_stmt|;
name|size_t
name|len
init|=
literal|0
decl_stmt|;
if|if
condition|(
name|sysctl
argument_list|(
name|mib
argument_list|,
literal|4
argument_list|,
name|NULL
argument_list|,
operator|&
name|len
argument_list|,
name|NULL
argument_list|,
literal|0
argument_list|)
operator|<
literal|0
condition|)
return|return
name|QString
argument_list|()
return|;
name|kinfo_proc
modifier|*
name|proc
init|=
cast|static_cast
argument_list|<
name|kinfo_proc
operator|*
argument_list|>
argument_list|(
name|malloc
argument_list|(
name|len
argument_list|)
argument_list|)
decl_stmt|;
else|#
directive|else
name|kinfo_proc
modifier|*
name|proc
init|=
name|kinfo_getproc
argument_list|(
name|pid
argument_list|)
decl_stmt|;
endif|#
directive|endif
if|if
condition|(
operator|!
name|proc
condition|)
return|return
name|QString
argument_list|()
return|;
if|#
directive|if
name|defined
argument_list|(
name|__GLIBC__
argument_list|)
operator|&&
name|defined
argument_list|(
name|__FreeBSD_kernel__
argument_list|)
if|if
condition|(
name|sysctl
argument_list|(
name|mib
argument_list|,
literal|4
argument_list|,
name|proc
argument_list|,
operator|&
name|len
argument_list|,
name|NULL
argument_list|,
literal|0
argument_list|)
operator|<
literal|0
condition|)
block|{
name|free
argument_list|(
name|proc
argument_list|)
expr_stmt|;
return|return
name|QString
argument_list|()
return|;
block|}
if|if
condition|(
name|proc
operator|->
name|ki_pid
operator|!=
name|pid
condition|)
block|{
name|free
argument_list|(
name|proc
argument_list|)
expr_stmt|;
return|return
name|QString
argument_list|()
return|;
block|}
endif|#
directive|endif
name|QString
name|name
init|=
name|QFile
operator|::
name|decodeName
argument_list|(
name|proc
operator|->
name|ki_comm
argument_list|)
decl_stmt|;
name|free
argument_list|(
name|proc
argument_list|)
expr_stmt|;
return|return
name|name
return|;
else|#
directive|else
name|Q_UNUSED
argument_list|(
name|pid
argument_list|)
expr_stmt|;
return|return
name|QString
argument_list|()
return|;
endif|#
directive|endif
block|}
end_function
begin_function
DECL|function|unlock
name|void
name|QLockFile
operator|::
name|unlock
parameter_list|()
block|{
name|Q_D
argument_list|(
name|QLockFile
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|d
operator|->
name|isLocked
condition|)
return|return;
name|close
argument_list|(
name|d
operator|->
name|fileHandle
argument_list|)
expr_stmt|;
name|d
operator|->
name|fileHandle
operator|=
operator|-
literal|1
expr_stmt|;
if|if
condition|(
operator|!
name|QFile
operator|::
name|remove
argument_list|(
name|d
operator|->
name|fileName
argument_list|)
condition|)
block|{
name|qWarning
argument_list|()
operator|<<
literal|"Could not remove our own lock file"
operator|<<
name|d
operator|->
name|fileName
operator|<<
literal|"maybe permissions changed meanwhile?"
expr_stmt|;
comment|// This is bad because other users of this lock file will now have to wait for the stale-lock-timeout...
block|}
name|d
operator|->
name|lockError
operator|=
name|QLockFile
operator|::
name|NoError
expr_stmt|;
name|d
operator|->
name|isLocked
operator|=
literal|false
expr_stmt|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
