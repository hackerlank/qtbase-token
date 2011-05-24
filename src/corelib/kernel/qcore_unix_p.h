begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QCORE_UNIX_P_H
end_ifndef
begin_define
DECL|macro|QCORE_UNIX_P_H
define|#
directive|define
name|QCORE_UNIX_P_H
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
comment|// of Qt code on Unix. This header file may change from version to
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
file|"qplatformdefs.h"
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|Q_OS_UNIX
end_ifndef
begin_error
error|#
directive|error
literal|"qcore_unix_p.h included on a non-Unix system"
end_error
begin_endif
endif|#
directive|endif
end_endif
begin_include
include|#
directive|include
file|<sys/types.h>
end_include
begin_include
include|#
directive|include
file|<sys/stat.h>
end_include
begin_include
include|#
directive|include
file|<unistd.h>
end_include
begin_include
include|#
directive|include
file|<sys/wait.h>
end_include
begin_include
include|#
directive|include
file|<errno.h>
end_include
begin_include
include|#
directive|include
file|<fcntl.h>
end_include
begin_if
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_VXWORKS
argument_list|)
end_if
begin_include
include|#
directive|include
file|<ioLib.h>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_struct_decl
struct_decl|struct
name|sockaddr
struct_decl|;
end_struct_decl
begin_if
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_LINUX
argument_list|)
operator|&&
name|defined
argument_list|(
name|O_CLOEXEC
argument_list|)
end_if
begin_define
DECL|macro|QT_UNIX_SUPPORTS_THREADSAFE_CLOEXEC
define|#
directive|define
name|QT_UNIX_SUPPORTS_THREADSAFE_CLOEXEC
value|1
end_define
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
name|namespace
name|QtLibcSupplement
block|{
specifier|inline
name|int
name|accept4
parameter_list|(
name|int
parameter_list|,
name|sockaddr
modifier|*
parameter_list|,
name|QT_SOCKLEN_T
modifier|*
parameter_list|,
name|int
parameter_list|)
block|{
name|errno
operator|=
name|ENOSYS
expr_stmt|;
return|return
operator|-
literal|1
return|;
block|}
specifier|inline
name|int
name|dup3
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
block|{
name|errno
operator|=
name|ENOSYS
expr_stmt|;
return|return
operator|-
literal|1
return|;
block|}
specifier|inline
name|int
name|pipe2
parameter_list|(
name|int
index|[]
parameter_list|,
name|int
parameter_list|)
block|{
name|errno
operator|=
name|ENOSYS
expr_stmt|;
return|return
operator|-
literal|1
return|;
block|}
block|}
end_decl_stmt
begin_function_decl
name|QT_END_NAMESPACE
name|using
name|namespace
name|QT_PREPEND_NAMESPACE
parameter_list|(
name|QtLibcSupplement
parameter_list|)
function_decl|;
end_function_decl
begin_else
else|#
directive|else
end_else
begin_define
DECL|macro|QT_UNIX_SUPPORTS_THREADSAFE_CLOEXEC
define|#
directive|define
name|QT_UNIX_SUPPORTS_THREADSAFE_CLOEXEC
value|0
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_define
DECL|macro|EINTR_LOOP
define|#
directive|define
name|EINTR_LOOP
parameter_list|(
name|var
parameter_list|,
name|cmd
parameter_list|)
define|\
value|do {                                        \         var = cmd;                              \     } while (var == -1&& errno == EINTR)
end_define
begin_function
name|QT_BEGIN_NAMESPACE
comment|// Internal operator functions for timevals
DECL|function|normalizedTimeval
specifier|inline
name|timeval
modifier|&
name|normalizedTimeval
parameter_list|(
name|timeval
modifier|&
name|t
parameter_list|)
block|{
while|while
condition|(
name|t
operator|.
name|tv_usec
operator|>
literal|1000000l
condition|)
block|{
operator|++
name|t
operator|.
name|tv_sec
expr_stmt|;
name|t
operator|.
name|tv_usec
operator|-=
literal|1000000l
expr_stmt|;
block|}
while|while
condition|(
name|t
operator|.
name|tv_usec
operator|<
literal|0l
condition|)
block|{
operator|--
name|t
operator|.
name|tv_sec
expr_stmt|;
name|t
operator|.
name|tv_usec
operator|+=
literal|1000000l
expr_stmt|;
block|}
return|return
name|t
return|;
block|}
end_function
begin_expr_stmt
DECL|function|operator
specifier|inline
name|bool
name|operator
operator|<
operator|(
specifier|const
name|timeval
operator|&
name|t1
operator|,
specifier|const
name|timeval
operator|&
name|t2
operator|)
block|{
return|return
name|t1
operator|.
name|tv_sec
operator|<
name|t2
operator|.
name|tv_sec
operator|||
operator|(
name|t1
operator|.
name|tv_sec
operator|==
name|t2
operator|.
name|tv_sec
operator|&&
name|t1
operator|.
name|tv_usec
operator|<
name|t2
operator|.
name|tv_usec
operator|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|operator
specifier|inline
name|bool
name|operator
operator|==
operator|(
specifier|const
name|timeval
operator|&
name|t1
operator|,
specifier|const
name|timeval
operator|&
name|t2
operator|)
block|{
return|return
name|t1
operator|.
name|tv_sec
operator|==
name|t2
operator|.
name|tv_sec
operator|&&
name|t1
operator|.
name|tv_usec
operator|==
name|t2
operator|.
name|tv_usec
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|variable|operator
specifier|inline
name|timeval
operator|&
name|operator
operator|+=
operator|(
name|timeval
operator|&
name|t1
operator|,
specifier|const
name|timeval
operator|&
name|t2
operator|)
block|{
name|t1
operator|.
name|tv_sec
operator|+=
name|t2
operator|.
name|tv_sec
block|;
name|t1
operator|.
name|tv_usec
operator|+=
name|t2
operator|.
name|tv_usec
block|;
return|return
name|normalizedTimeval
argument_list|(
name|t1
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
name|timeval
name|operator
operator|+
operator|(
specifier|const
name|timeval
operator|&
name|t1
operator|,
specifier|const
name|timeval
operator|&
name|t2
operator|)
block|{
name|timeval
name|tmp
block|;
name|tmp
operator|.
name|tv_sec
operator|=
name|t1
operator|.
name|tv_sec
operator|+
name|t2
operator|.
name|tv_sec
block|;
name|tmp
operator|.
name|tv_usec
operator|=
name|t1
operator|.
name|tv_usec
operator|+
name|t2
operator|.
name|tv_usec
block|;
return|return
name|normalizedTimeval
argument_list|(
name|tmp
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
name|timeval
name|operator
operator|-
operator|(
specifier|const
name|timeval
operator|&
name|t1
operator|,
specifier|const
name|timeval
operator|&
name|t2
operator|)
block|{
name|timeval
name|tmp
block|;
name|tmp
operator|.
name|tv_sec
operator|=
name|t1
operator|.
name|tv_sec
operator|-
operator|(
name|t2
operator|.
name|tv_sec
operator|-
literal|1
operator|)
block|;
name|tmp
operator|.
name|tv_usec
operator|=
name|t1
operator|.
name|tv_usec
operator|-
operator|(
name|t2
operator|.
name|tv_usec
operator|+
literal|1000000
operator|)
block|;
return|return
name|normalizedTimeval
argument_list|(
name|tmp
argument_list|)
return|;
block|}
end_expr_stmt
begin_function
specifier|inline
name|timeval
name|operator
modifier|*
parameter_list|(
specifier|const
name|timeval
modifier|&
name|t1
parameter_list|,
name|int
name|mul
parameter_list|)
block|{
name|timeval
name|tmp
decl_stmt|;
name|tmp
operator|.
name|tv_sec
operator|=
name|t1
operator|.
name|tv_sec
operator|*
name|mul
expr_stmt|;
name|tmp
operator|.
name|tv_usec
operator|=
name|t1
operator|.
name|tv_usec
operator|*
name|mul
expr_stmt|;
return|return
name|normalizedTimeval
argument_list|(
name|tmp
argument_list|)
return|;
block|}
end_function
begin_comment
comment|// don't call QT_OPEN or ::open
end_comment
begin_comment
comment|// call qt_safe_open
end_comment
begin_function
specifier|static
specifier|inline
name|int
name|qt_safe_open
parameter_list|(
specifier|const
name|char
modifier|*
name|pathname
parameter_list|,
name|int
name|flags
parameter_list|,
name|mode_t
name|mode
init|=
literal|0777
parameter_list|)
block|{
ifdef|#
directive|ifdef
name|O_CLOEXEC
name|flags
operator||=
name|O_CLOEXEC
expr_stmt|;
endif|#
directive|endif
specifier|register
name|int
name|fd
decl_stmt|;
name|EINTR_LOOP
argument_list|(
name|fd
argument_list|,
name|QT_OPEN
argument_list|(
name|pathname
argument_list|,
name|flags
argument_list|,
name|mode
argument_list|)
argument_list|)
expr_stmt|;
comment|// unknown flags are ignored, so we have no way of verifying if
comment|// O_CLOEXEC was accepted
if|if
condition|(
name|fd
operator|!=
operator|-
literal|1
condition|)
operator|::
name|fcntl
argument_list|(
name|fd
argument_list|,
name|F_SETFD
argument_list|,
name|FD_CLOEXEC
argument_list|)
expr_stmt|;
return|return
name|fd
return|;
block|}
end_function
begin_undef
DECL|macro|QT_OPEN
undef|#
directive|undef
name|QT_OPEN
end_undef
begin_define
DECL|macro|QT_OPEN
define|#
directive|define
name|QT_OPEN
value|qt_safe_open
end_define
begin_ifndef
ifndef|#
directive|ifndef
name|Q_OS_VXWORKS
end_ifndef
begin_comment
comment|// no POSIX pipes in VxWorks
end_comment
begin_comment
comment|// don't call ::pipe
end_comment
begin_comment
comment|// call qt_safe_pipe
end_comment
begin_function
specifier|static
specifier|inline
name|int
name|qt_safe_pipe
parameter_list|(
name|int
name|pipefd
index|[
literal|2
index|]
parameter_list|,
name|int
name|flags
init|=
literal|0
parameter_list|)
block|{
ifdef|#
directive|ifdef
name|O_CLOEXEC
name|Q_ASSERT
argument_list|(
operator|(
name|flags
operator|&
operator|~
operator|(
name|O_CLOEXEC
operator||
name|O_NONBLOCK
operator|)
operator|)
operator|==
literal|0
argument_list|)
expr_stmt|;
else|#
directive|else
name|Q_ASSERT
argument_list|(
operator|(
name|flags
operator|&
operator|~
name|O_NONBLOCK
operator|)
operator|==
literal|0
argument_list|)
expr_stmt|;
endif|#
directive|endif
specifier|register
name|int
name|ret
decl_stmt|;
if|#
directive|if
name|QT_UNIX_SUPPORTS_THREADSAFE_CLOEXEC
operator|&&
name|defined
argument_list|(
name|O_CLOEXEC
argument_list|)
comment|// use pipe2
name|flags
operator||=
name|O_CLOEXEC
expr_stmt|;
name|ret
operator|=
operator|::
name|pipe2
argument_list|(
name|pipefd
argument_list|,
name|flags
argument_list|)
expr_stmt|;
comment|// pipe2 is Linux-specific and is documented not to return EINTR
if|if
condition|(
name|ret
operator|==
literal|0
operator|||
name|errno
operator|!=
name|ENOSYS
condition|)
return|return
name|ret
return|;
endif|#
directive|endif
name|ret
operator|=
operator|::
name|pipe
argument_list|(
name|pipefd
argument_list|)
expr_stmt|;
if|if
condition|(
name|ret
operator|==
operator|-
literal|1
condition|)
return|return
operator|-
literal|1
return|;
operator|::
name|fcntl
argument_list|(
name|pipefd
index|[
literal|0
index|]
argument_list|,
name|F_SETFD
argument_list|,
name|FD_CLOEXEC
argument_list|)
expr_stmt|;
operator|::
name|fcntl
argument_list|(
name|pipefd
index|[
literal|1
index|]
argument_list|,
name|F_SETFD
argument_list|,
name|FD_CLOEXEC
argument_list|)
expr_stmt|;
comment|// set non-block too?
if|if
condition|(
name|flags
operator|&
name|O_NONBLOCK
condition|)
block|{
operator|::
name|fcntl
argument_list|(
name|pipefd
index|[
literal|0
index|]
argument_list|,
name|F_SETFL
argument_list|,
operator|::
name|fcntl
argument_list|(
name|pipefd
index|[
literal|0
index|]
argument_list|,
name|F_GETFL
argument_list|)
operator||
name|O_NONBLOCK
argument_list|)
expr_stmt|;
operator|::
name|fcntl
argument_list|(
name|pipefd
index|[
literal|1
index|]
argument_list|,
name|F_SETFL
argument_list|,
operator|::
name|fcntl
argument_list|(
name|pipefd
index|[
literal|1
index|]
argument_list|,
name|F_GETFL
argument_list|)
operator||
name|O_NONBLOCK
argument_list|)
expr_stmt|;
block|}
return|return
literal|0
return|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// Q_OS_VXWORKS
end_comment
begin_comment
comment|// don't call dup or fcntl(F_DUPFD)
end_comment
begin_function
specifier|static
specifier|inline
name|int
name|qt_safe_dup
parameter_list|(
name|int
name|oldfd
parameter_list|,
name|int
name|atleast
init|=
literal|0
parameter_list|,
name|int
name|flags
init|=
name|FD_CLOEXEC
parameter_list|)
block|{
name|Q_ASSERT
argument_list|(
name|flags
operator|==
name|FD_CLOEXEC
operator|||
name|flags
operator|==
literal|0
argument_list|)
expr_stmt|;
specifier|register
name|int
name|ret
decl_stmt|;
ifdef|#
directive|ifdef
name|F_DUPFD_CLOEXEC
comment|// use this fcntl
if|if
condition|(
name|flags
operator|&
name|FD_CLOEXEC
condition|)
block|{
name|ret
operator|=
operator|::
name|fcntl
argument_list|(
name|oldfd
argument_list|,
name|F_DUPFD_CLOEXEC
argument_list|,
name|atleast
argument_list|)
expr_stmt|;
if|if
condition|(
name|ret
operator|!=
operator|-
literal|1
operator|||
name|errno
operator|!=
name|EINVAL
condition|)
return|return
name|ret
return|;
block|}
endif|#
directive|endif
comment|// use F_DUPFD
name|ret
operator|=
operator|::
name|fcntl
argument_list|(
name|oldfd
argument_list|,
name|F_DUPFD
argument_list|,
name|atleast
argument_list|)
expr_stmt|;
if|if
condition|(
name|flags
operator|&&
name|ret
operator|!=
operator|-
literal|1
condition|)
operator|::
name|fcntl
argument_list|(
name|ret
argument_list|,
name|F_SETFD
argument_list|,
name|flags
argument_list|)
expr_stmt|;
return|return
name|ret
return|;
block|}
end_function
begin_comment
comment|// don't call dup2
end_comment
begin_comment
comment|// call qt_safe_dup2
end_comment
begin_function
specifier|static
specifier|inline
name|int
name|qt_safe_dup2
parameter_list|(
name|int
name|oldfd
parameter_list|,
name|int
name|newfd
parameter_list|,
name|int
name|flags
init|=
name|FD_CLOEXEC
parameter_list|)
block|{
name|Q_ASSERT
argument_list|(
name|flags
operator|==
name|FD_CLOEXEC
operator|||
name|flags
operator|==
literal|0
argument_list|)
expr_stmt|;
specifier|register
name|int
name|ret
decl_stmt|;
if|#
directive|if
name|QT_UNIX_SUPPORTS_THREADSAFE_CLOEXEC
operator|&&
name|defined
argument_list|(
name|O_CLOEXEC
argument_list|)
comment|// use dup3
if|if
condition|(
name|flags
operator|&
name|FD_CLOEXEC
condition|)
block|{
name|EINTR_LOOP
argument_list|(
name|ret
argument_list|,
operator|::
name|dup3
argument_list|(
name|oldfd
argument_list|,
name|newfd
argument_list|,
name|O_CLOEXEC
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|ret
operator|==
literal|0
operator|||
name|errno
operator|!=
name|ENOSYS
condition|)
return|return
name|ret
return|;
block|}
endif|#
directive|endif
name|EINTR_LOOP
argument_list|(
name|ret
argument_list|,
operator|::
name|dup2
argument_list|(
name|oldfd
argument_list|,
name|newfd
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|ret
operator|==
operator|-
literal|1
condition|)
return|return
operator|-
literal|1
return|;
if|if
condition|(
name|flags
condition|)
operator|::
name|fcntl
argument_list|(
name|newfd
argument_list|,
name|F_SETFD
argument_list|,
name|flags
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function
begin_function
specifier|static
specifier|inline
name|qint64
name|qt_safe_read
parameter_list|(
name|int
name|fd
parameter_list|,
name|void
modifier|*
name|data
parameter_list|,
name|qint64
name|maxlen
parameter_list|)
block|{
name|qint64
name|ret
init|=
literal|0
decl_stmt|;
name|EINTR_LOOP
argument_list|(
name|ret
argument_list|,
name|QT_READ
argument_list|(
name|fd
argument_list|,
name|data
argument_list|,
name|maxlen
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|ret
return|;
block|}
end_function
begin_undef
DECL|macro|QT_READ
undef|#
directive|undef
name|QT_READ
end_undef
begin_define
DECL|macro|QT_READ
define|#
directive|define
name|QT_READ
value|qt_safe_read
end_define
begin_function
specifier|static
specifier|inline
name|qint64
name|qt_safe_write
parameter_list|(
name|int
name|fd
parameter_list|,
specifier|const
name|void
modifier|*
name|data
parameter_list|,
name|qint64
name|len
parameter_list|)
block|{
name|qint64
name|ret
init|=
literal|0
decl_stmt|;
name|EINTR_LOOP
argument_list|(
name|ret
argument_list|,
name|QT_WRITE
argument_list|(
name|fd
argument_list|,
name|data
argument_list|,
name|len
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|ret
return|;
block|}
end_function
begin_undef
DECL|macro|QT_WRITE
undef|#
directive|undef
name|QT_WRITE
end_undef
begin_define
DECL|macro|QT_WRITE
define|#
directive|define
name|QT_WRITE
value|qt_safe_write
end_define
begin_function
specifier|static
specifier|inline
name|int
name|qt_safe_close
parameter_list|(
name|int
name|fd
parameter_list|)
block|{
specifier|register
name|int
name|ret
decl_stmt|;
name|EINTR_LOOP
argument_list|(
name|ret
argument_list|,
name|QT_CLOSE
argument_list|(
name|fd
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|ret
return|;
block|}
end_function
begin_undef
DECL|macro|QT_CLOSE
undef|#
directive|undef
name|QT_CLOSE
end_undef
begin_define
DECL|macro|QT_CLOSE
define|#
directive|define
name|QT_CLOSE
value|qt_safe_close
end_define
begin_comment
comment|// - Open C does not (yet?) implement these on Symbian OS
end_comment
begin_comment
comment|// - VxWorks doesn't have processes
end_comment
begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|Q_OS_SYMBIAN
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|Q_OS_VXWORKS
argument_list|)
end_if
begin_function
specifier|static
specifier|inline
name|int
name|qt_safe_execve
parameter_list|(
specifier|const
name|char
modifier|*
name|filename
parameter_list|,
name|char
modifier|*
specifier|const
name|argv
index|[]
parameter_list|,
name|char
modifier|*
specifier|const
name|envp
index|[]
parameter_list|)
block|{
specifier|register
name|int
name|ret
decl_stmt|;
name|EINTR_LOOP
argument_list|(
name|ret
argument_list|,
operator|::
name|execve
argument_list|(
name|filename
argument_list|,
name|argv
argument_list|,
name|envp
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|ret
return|;
block|}
end_function
begin_function
specifier|static
specifier|inline
name|int
name|qt_safe_execv
parameter_list|(
specifier|const
name|char
modifier|*
name|path
parameter_list|,
name|char
modifier|*
specifier|const
name|argv
index|[]
parameter_list|)
block|{
specifier|register
name|int
name|ret
decl_stmt|;
name|EINTR_LOOP
argument_list|(
name|ret
argument_list|,
operator|::
name|execv
argument_list|(
name|path
argument_list|,
name|argv
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|ret
return|;
block|}
end_function
begin_function
specifier|static
specifier|inline
name|int
name|qt_safe_execvp
parameter_list|(
specifier|const
name|char
modifier|*
name|file
parameter_list|,
name|char
modifier|*
specifier|const
name|argv
index|[]
parameter_list|)
block|{
specifier|register
name|int
name|ret
decl_stmt|;
name|EINTR_LOOP
argument_list|(
name|ret
argument_list|,
operator|::
name|execvp
argument_list|(
name|file
argument_list|,
name|argv
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|ret
return|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|Q_OS_VXWORKS
end_ifndef
begin_comment
comment|// no processes on VxWorks
end_comment
begin_function
specifier|static
specifier|inline
name|pid_t
name|qt_safe_waitpid
parameter_list|(
name|pid_t
name|pid
parameter_list|,
name|int
modifier|*
name|status
parameter_list|,
name|int
name|options
parameter_list|)
block|{
specifier|register
name|int
name|ret
decl_stmt|;
name|EINTR_LOOP
argument_list|(
name|ret
argument_list|,
operator|::
name|waitpid
argument_list|(
name|pid
argument_list|,
name|status
argument_list|,
name|options
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|ret
return|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// Q_OS_VXWORKS
end_comment
begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|_POSIX_MONOTONIC_CLOCK
argument_list|)
end_if
begin_define
DECL|macro|_POSIX_MONOTONIC_CLOCK
define|#
directive|define
name|_POSIX_MONOTONIC_CLOCK
value|-1
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_function_decl
name|timeval
name|qt_gettime
parameter_list|()
function_decl|;
end_function_decl
begin_comment
comment|// in qelapsedtimer_mac.cpp or qtimestamp_unix.cpp
end_comment
begin_function_decl
name|Q_CORE_EXPORT
name|int
name|qt_safe_select
parameter_list|(
name|int
name|nfds
parameter_list|,
name|fd_set
modifier|*
name|fdread
parameter_list|,
name|fd_set
modifier|*
name|fdwrite
parameter_list|,
name|fd_set
modifier|*
name|fdexcept
parameter_list|,
specifier|const
name|struct
name|timeval
modifier|*
name|tv
parameter_list|)
function_decl|;
end_function_decl
begin_comment
comment|// according to X/OPEN we have to define semun ourselves
end_comment
begin_comment
comment|// we use prefix as on some systems sem.h will have it
end_comment
begin_struct_decl
struct_decl|struct
name|semid_ds
struct_decl|;
end_struct_decl
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
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
end_unit
