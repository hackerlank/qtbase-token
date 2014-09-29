begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2014 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia. For licensing terms and ** conditions see http://qt.digia.com/licensing. For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights. These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_comment
comment|/*************************************************************************  *  * stacktrace.c 1.2 1998/12/21  *  * Copyright (c) 1998 by Bjorn Reese<breese@imada.ou.dk>  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR IMPLIED  * WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED WARRANTIES OF  * MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE. THE AUTHORS AND  * CONTRIBUTORS ACCEPT NO RESPONSIBILITY IN ANY CONCEIVABLE MANNER.  *  ************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qplatformdefs.h"
end_include
begin_include
include|#
directive|include
file|"private/qcrashhandler_p.h"
end_include
begin_include
include|#
directive|include
file|"qbytearray.h"
end_include
begin_comment
comment|// for qvsnprintf()
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_CRASHHANDLER
end_ifndef
begin_include
include|#
directive|include
file|<stdio.h>
end_include
begin_include
include|#
directive|include
file|<signal.h>
end_include
begin_include
include|#
directive|include
file|<stdlib.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|member|callback
name|QtCrashHandler
name|QSegfaultHandler
operator|::
name|callback
init|=
literal|0
decl_stmt|;
end_decl_stmt
begin_if
if|#
directive|if
name|defined
argument_list|(
name|__GLIBC__
argument_list|)
operator|&&
operator|(
name|__GLIBC__
operator|>=
literal|2
operator|)
operator|&&
operator|!
name|defined
argument_list|(
name|__UCLIBC__
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|QT_LINUXBASE
argument_list|)
end_if
begin_function
name|QT_BEGIN_INCLUDE_NAMESPACE
include|#
directive|include
file|"qstring.h"
include|#
directive|include
file|<execinfo.h>
name|QT_END_INCLUDE_NAMESPACE
DECL|function|print_backtrace
specifier|static
name|void
name|print_backtrace
parameter_list|(
name|FILE
modifier|*
name|outb
parameter_list|)
block|{
name|void
modifier|*
name|stack
index|[
literal|128
index|]
decl_stmt|;
name|int
name|stack_size
init|=
name|backtrace
argument_list|(
name|stack
argument_list|,
sizeof|sizeof
argument_list|(
name|stack
argument_list|)
operator|/
sizeof|sizeof
argument_list|(
name|void
operator|*
argument_list|)
argument_list|)
decl_stmt|;
name|char
modifier|*
modifier|*
name|stack_symbols
init|=
name|backtrace_symbols
argument_list|(
name|stack
argument_list|,
name|stack_size
argument_list|)
decl_stmt|;
name|fprintf
argument_list|(
name|outb
argument_list|,
literal|"Stack [%d]:\n"
argument_list|,
name|stack_size
argument_list|)
expr_stmt|;
if|if
condition|(
name|FILE
modifier|*
name|cppfilt
init|=
name|popen
argument_list|(
literal|"c++filt"
argument_list|,
literal|"rw"
argument_list|)
condition|)
block|{
name|dup2
argument_list|(
name|fileno
argument_list|(
name|outb
argument_list|)
argument_list|,
name|fileno
argument_list|(
name|cppfilt
argument_list|)
argument_list|)
expr_stmt|;
for|for
control|(
name|int
name|i
init|=
name|stack_size
operator|-
literal|1
init|;
name|i
operator|>=
literal|0
condition|;
operator|--
name|i
control|)
name|fwrite
argument_list|(
name|stack_symbols
index|[
name|i
index|]
argument_list|,
literal|1
argument_list|,
name|strlen
argument_list|(
name|stack_symbols
index|[
name|i
index|]
argument_list|)
argument_list|,
name|cppfilt
argument_list|)
expr_stmt|;
name|pclose
argument_list|(
name|cppfilt
argument_list|)
expr_stmt|;
block|}
else|else
block|{
for|for
control|(
name|int
name|i
init|=
name|stack_size
operator|-
literal|1
init|;
name|i
operator|>=
literal|0
condition|;
operator|--
name|i
control|)
name|fprintf
argument_list|(
name|outb
argument_list|,
literal|"#%d  %p [%s]\n"
argument_list|,
name|i
argument_list|,
name|stack
index|[
name|i
index|]
argument_list|,
name|stack_symbols
index|[
name|i
index|]
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|init_backtrace
specifier|static
name|void
name|init_backtrace
parameter_list|(
name|char
modifier|*
modifier|*
parameter_list|,
name|int
parameter_list|)
block|{ }
end_function
begin_else
else|#
directive|else
end_else
begin_comment
comment|/* Don't use the GLIBC callback */
end_comment
begin_comment
comment|/* Code sourced from: */
end_comment
begin_decl_stmt
name|QT_BEGIN_INCLUDE_NAMESPACE
include|#
directive|include
file|<stdarg.h>
include|#
directive|include
file|<string.h>
include|#
directive|include
file|<errno.h>
include|#
directive|include
file|<sys/types.h>
include|#
directive|include
file|<sys/wait.h>
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_IRIX
argument_list|)
operator|&&
name|defined
argument_list|(
name|USE_LIBEXC
argument_list|)
include|#
directive|include
file|<libexc.h>
endif|#
directive|endif
name|QT_END_INCLUDE_NAMESPACE
DECL|variable|globalProgName
specifier|static
name|char
modifier|*
name|globalProgName
init|=
name|NULL
decl_stmt|;
end_decl_stmt
begin_function
DECL|function|backtrace_command
specifier|static
name|bool
name|backtrace_command
parameter_list|(
name|FILE
modifier|*
name|outb
parameter_list|,
specifier|const
name|char
modifier|*
name|format
parameter_list|,
modifier|...
parameter_list|)
block|{
name|bool
name|ret
init|=
literal|false
decl_stmt|;
name|char
name|buffer
index|[
literal|50
index|]
decl_stmt|;
comment|/*      * Please note that vsnprintf() is not ASync safe (ie. cannot safely      * be used from a signal handler.) If this proves to be a problem      * then the cmd string can be built by more basic functions such as      * strcpy, strcat, and a home-made integer-to-ascii function.      */
name|va_list
name|args
decl_stmt|;
name|char
name|cmd
index|[
literal|512
index|]
decl_stmt|;
name|va_start
argument_list|(
name|args
argument_list|,
name|format
argument_list|)
expr_stmt|;
name|qvsnprintf
argument_list|(
name|cmd
argument_list|,
literal|512
argument_list|,
name|format
argument_list|,
name|args
argument_list|)
expr_stmt|;
name|va_end
argument_list|(
name|args
argument_list|)
expr_stmt|;
name|char
modifier|*
name|foo
init|=
name|cmd
decl_stmt|;
if|#
directive|if
literal|0
block|foo = "echo hi";
endif|#
directive|endif
if|if
condition|(
name|FILE
modifier|*
name|inb
init|=
name|popen
argument_list|(
name|foo
argument_list|,
literal|"r"
argument_list|)
condition|)
block|{
while|while
condition|(
operator|!
name|feof
argument_list|(
name|inb
argument_list|)
condition|)
block|{
name|int
name|len
init|=
name|fread
argument_list|(
name|buffer
argument_list|,
literal|1
argument_list|,
sizeof|sizeof
argument_list|(
name|buffer
argument_list|)
argument_list|,
name|inb
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|len
condition|)
break|break;
if|if
condition|(
operator|!
name|ret
condition|)
block|{
name|fwrite
argument_list|(
literal|"Output from "
argument_list|,
literal|1
argument_list|,
name|strlen
argument_list|(
literal|"Output from "
argument_list|)
argument_list|,
name|outb
argument_list|)
expr_stmt|;
name|strtok
argument_list|(
name|cmd
argument_list|,
literal|" "
argument_list|)
expr_stmt|;
name|fwrite
argument_list|(
name|cmd
argument_list|,
literal|1
argument_list|,
name|strlen
argument_list|(
name|cmd
argument_list|)
argument_list|,
name|outb
argument_list|)
expr_stmt|;
name|fwrite
argument_list|(
literal|"\n"
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|,
name|outb
argument_list|)
expr_stmt|;
name|ret
operator|=
literal|true
expr_stmt|;
block|}
name|fwrite
argument_list|(
name|buffer
argument_list|,
literal|1
argument_list|,
name|len
argument_list|,
name|outb
argument_list|)
expr_stmt|;
block|}
name|fclose
argument_list|(
name|inb
argument_list|)
expr_stmt|;
block|}
return|return
name|ret
return|;
block|}
end_function
begin_function
DECL|function|init_backtrace
specifier|static
name|void
name|init_backtrace
parameter_list|(
name|char
modifier|*
modifier|*
name|argv
parameter_list|,
name|int
name|argc
parameter_list|)
block|{
if|if
condition|(
name|argc
operator|>=
literal|1
condition|)
name|globalProgName
operator|=
name|argv
index|[
literal|0
index|]
expr_stmt|;
block|}
end_function
begin_function
DECL|function|print_backtrace
specifier|static
name|void
name|print_backtrace
parameter_list|(
name|FILE
modifier|*
name|outb
parameter_list|)
block|{
comment|/*      * In general dbx seems to do a better job than gdb.      *      * Different dbx implementations require different flags/commands.      */
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_AIX
argument_list|)
if|if
condition|(
name|backtrace_command
argument_list|(
name|outb
argument_list|,
literal|"dbx -a %d 2>/dev/null<<EOF\n"
literal|"where\n"
literal|"detach\n"
literal|"EOF\n"
argument_list|,
operator|(
name|int
operator|)
name|getpid
argument_list|()
argument_list|)
condition|)
return|return;
if|if
condition|(
name|backtrace_command
argument_list|(
name|outb
argument_list|,
literal|"gdb -q %s %d 2>/dev/null<<EOF\n"
literal|"set prompt\n"
literal|"where\n"
literal|"detach\n"
literal|"quit\n"
literal|"EOF\n"
argument_list|,
name|globalProgName
argument_list|,
operator|(
name|int
operator|)
name|getpid
argument_list|()
argument_list|)
condition|)
return|return;
elif|#
directive|elif
name|defined
argument_list|(
name|Q_OS_FREEBSD
argument_list|)
comment|/*      * FreeBSD insists on sending a SIGSTOP to the process we      * attach to, so we let the debugger send a SIGCONT to that      * process after we have detached.      */
if|if
condition|(
name|backtrace_command
argument_list|(
name|outb
argument_list|,
literal|"gdb -q %s %d 2>/dev/null<<EOF\n"
literal|"set prompt\n"
literal|"where\n"
literal|"detach\n"
literal|"shell kill -CONT %d\n"
literal|"quit\n"
literal|"EOF\n"
argument_list|,
name|globalProgName
argument_list|,
operator|(
name|int
operator|)
name|getpid
argument_list|()
argument_list|,
operator|(
name|int
operator|)
name|getpid
argument_list|()
argument_list|)
condition|)
return|return;
elif|#
directive|elif
name|defined
argument_list|(
name|Q_OS_HPUX
argument_list|)
comment|/*      * HP decided to call their debugger xdb.      *      * This does not seem to work properly yet. The debugger says      * "Note: Stack traces may not be possible until you are      *  stopped in user code." on HP-UX 09.01      *      * -L = line-oriented interface.      * "T [depth]" gives a stacktrace with local variables.      * The final "y" is confirmation to the quit command.      */
if|if
condition|(
name|backtrace_command
argument_list|(
name|outb
argument_list|,
literal|"xdb -P %d -L %s 2>&1<<EOF\n"
literal|"T 50\n"
literal|"q\ny\n"
literal|"EOF\n"
argument_list|,
operator|(
name|int
operator|)
name|getpid
argument_list|()
argument_list|,
name|globalProgName
argument_list|)
condition|)
return|return;
if|if
condition|(
name|backtrace_command
argument_list|(
name|outb
argument_list|,
literal|"gdb -q %s %d 2>/dev/null<<EOF\n"
literal|"set prompt\n"
literal|"where\n"
literal|"detach\n"
literal|"quit\n"
literal|"EOF\n"
argument_list|,
name|globalProgName
argument_list|,
operator|(
name|int
operator|)
name|getpid
argument_list|()
argument_list|)
condition|)
return|return;
elif|#
directive|elif
name|defined
argument_list|(
name|Q_OS_IRIX
argument_list|)
comment|/*      * "set $page=0" drops hold mode      * "dump ." displays the contents of the variables      */
if|if
condition|(
name|backtrace_command
argument_list|(
name|outb
argument_list|,
literal|"dbx -p %d 2>/dev/null<<EOF\n"
literal|"set \\$page=0\n"
literal|"where\n"
if|#
directive|if
operator|!
name|defined
argument_list|(
name|__GNUC__
argument_list|)
comment|/* gcc does not generate this information */
literal|"dump .\n"
endif|#
directive|endif
literal|"detach\n"
literal|"EOF\n"
argument_list|,
operator|(
name|int
operator|)
name|getpid
argument_list|()
argument_list|)
condition|)
return|return;
if|#
directive|if
name|defined
argument_list|(
name|USE_LIBEXC
argument_list|)
if|if
condition|(
name|trace_back_stack_and_print
argument_list|()
condition|)
return|return;
endif|#
directive|endif
if|if
condition|(
name|backtrace_command
argument_list|(
name|outb
argument_list|,
literal|"gdb -q %s %d 2>/dev/null<<EOF\n"
literal|"set prompt\n"
literal|"where\n"
literal|"echo ---\\n\n"
literal|"frame 5\n"
comment|/* Skip signal handler frames */
literal|"set \\$x = 50\n"
literal|"while (\\$x)\n"
comment|/* Print local variables for each frame */
literal|"info locals\n"
literal|"up\n"
literal|"set \\$x--\n"
literal|"end\n"
literal|"echo ---\\n\n"
literal|"detach\n"
literal|"quit\n"
literal|"EOF\n"
argument_list|,
name|globalProgName
argument_list|,
operator|(
name|int
operator|)
name|getpid
argument_list|()
argument_list|)
condition|)
return|return;
elif|#
directive|elif
name|defined
argument_list|(
name|Q_OS_OSF
argument_list|)
if|if
condition|(
name|backtrace_command
argument_list|(
name|outb
argument_list|,
literal|"dbx -pid %d %s 2>/dev/null<<EOF\n"
literal|"where\n"
literal|"detach\n"
literal|"quit\n"
literal|"EOF\n"
argument_list|,
operator|(
name|int
operator|)
name|getpid
argument_list|()
argument_list|,
name|globalProgName
argument_list|)
condition|)
return|return;
if|if
condition|(
name|backtrace_command
argument_list|(
name|outb
argument_list|,
literal|"gdb -q %s %d 2>/dev/null<<EOF\n"
literal|"set prompt\n"
literal|"where\n"
literal|"detach\n"
literal|"quit\n"
literal|"EOF\n"
argument_list|,
name|globalProgName
argument_list|,
operator|(
name|int
operator|)
name|getpid
argument_list|()
argument_list|)
condition|)
return|return;
elif|#
directive|elif
name|defined
argument_list|(
name|Q_OS_SCO
argument_list|)
comment|/*      * SCO OpenServer dbx is like a catch-22. The 'detach' command      * depends on whether ptrace(S) support detaching or not. If it      * is supported then 'detach' must be used, otherwise the process      * will be killed upon dbx exit. If it isn't supported then 'detach'      * will cause the process to be killed. We do not want it to be      * killed.      *      * Out of two evils, the omission of 'detach' was chosen because      * it worked on our system.      */
if|if
condition|(
name|backtrace_command
argument_list|(
name|outb
argument_list|,
literal|"dbx %s %d 2>/dev/null<<EOF\n"
literal|"where\n"
literal|"quit\nEOF\n"
argument_list|,
name|globalProgName
argument_list|,
operator|(
name|int
operator|)
name|getpid
argument_list|()
argument_list|)
condition|)
return|return;
if|if
condition|(
name|backtrace_command
argument_list|(
name|outb
argument_list|,
literal|"gdb -q %s %d 2>/dev/null<<EOF\n"
literal|"set prompt\n"
literal|"where\n"
literal|"detach\n"
literal|"quit\n"
literal|"EOF\n"
argument_list|,
name|globalProgName
argument_list|,
operator|(
name|int
operator|)
name|getpid
argument_list|()
argument_list|)
condition|)
return|return;
elif|#
directive|elif
name|defined
argument_list|(
name|Q_OS_SOLARIS
argument_list|)
if|if
condition|(
name|backtrace_command
argument_list|(
name|outb
argument_list|,
literal|"dbx %s %d 2>/dev/null<<EOF\n"
literal|"where\n"
literal|"detach\n"
literal|"EOF\n"
argument_list|,
name|globalProgName
argument_list|,
operator|(
name|int
operator|)
name|getpid
argument_list|()
argument_list|)
condition|)
return|return;
if|if
condition|(
name|backtrace_command
argument_list|(
name|outb
argument_list|,
literal|"gdb -q %s %d 2>/dev/null<<EOF\n"
literal|"set prompt\n"
literal|"where\n"
literal|"echo ---\\n\n"
literal|"frame 5\n"
comment|/* Skip signal handler frames */
literal|"set \\$x = 50\n"
literal|"while (\\$x)\n"
comment|/* Print local variables for each frame */
literal|"info locals\n"
literal|"up\n"
literal|"set \\$x--\n"
literal|"end\n"
literal|"echo ---\\n\n"
literal|"detach\n"
literal|"quit\n"
literal|"EOF\n"
argument_list|,
name|globalProgName
argument_list|,
operator|(
name|int
operator|)
name|getpid
argument_list|()
argument_list|)
condition|)
return|return;
if|if
condition|(
name|backtrace_command
argument_list|(
name|outb
argument_list|,
literal|"/usr/proc/bin/pstack %d"
argument_list|,
operator|(
name|int
operator|)
name|getpid
argument_list|()
argument_list|)
condition|)
return|return;
comment|/*      * Other Unices (AIX, HPUX, SCO) also have adb, but      * they seem unable to attach to a running process.)      */
if|if
condition|(
name|backtrace_command
argument_list|(
name|outb
argument_list|,
literal|"adb %s 2>&1<<EOF\n"
literal|"0t%d:A\n"
comment|/* Attach to pid */
literal|"\\$c\n"
comment|/* print stacktrace */
literal|":R\n"
comment|/* Detach */
literal|"\\$q\n"
comment|/* Quit */
literal|"EOF\n"
argument_list|,
name|globalProgName
argument_list|,
operator|(
name|int
operator|)
name|getpid
argument_list|()
argument_list|)
condition|)
return|return;
elif|#
directive|elif
name|defined
argument_list|(
name|Q_OS_INTEGRITY
argument_list|)
comment|/* abort */
name|CheckSuccess
argument_list|(
name|Failure
argument_list|)
expr_stmt|;
else|#
directive|else
comment|/* All other platforms */
comment|/*      * TODO: SCO/UnixWare 7 must be something like (not tested)      *  debug -i c<pid><<EOF\nstack -f 4\nquit\nEOF\n      */
if|#
directive|if
operator|!
name|defined
argument_list|(
name|__GNUC__
argument_list|)
if|if
condition|(
name|backtrace_command
argument_list|(
name|outb
argument_list|,
literal|"dbx %s %d 2>/dev/null<<EOF\n"
literal|"where\n"
literal|"detach\n"
literal|"EOF\n"
argument_list|,
name|globalProgName
argument_list|,
operator|(
name|int
operator|)
name|getpid
argument_list|()
argument_list|)
condition|)
return|return;
endif|#
directive|endif
if|if
condition|(
name|backtrace_command
argument_list|(
name|outb
argument_list|,
literal|"gdb -q %s %d 2>/dev/null<<EOF\n"
literal|"set prompt\n"
literal|"where\n"
if|#
directive|if
literal|0
expr|"echo ---\\n\n"                          "frame 4\n"                          "set \\$x = 50\n"                          "while (\\$x)\n"                          "info locals\n"                          "up\n"                          "set \\$x--\n"                          "end\n"                          "echo ---\\n\n"
endif|#
directive|endif
literal|"detach\n"
literal|"quit\n"
literal|"EOF\n"
argument_list|,
name|globalProgName
argument_list|,
operator|(
name|int
operator|)
name|getpid
argument_list|()
argument_list|)
condition|)
return|return;
endif|#
directive|endif
specifier|const
name|char
name|debug_err
index|[]
init|=
literal|"No debugger found\n"
decl_stmt|;
name|fwrite
argument_list|(
name|debug_err
argument_list|,
name|strlen
argument_list|(
name|debug_err
argument_list|)
argument_list|,
literal|1
argument_list|,
name|outb
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/* end of copied code */
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_function
DECL|function|qt_signal_handler
name|void
name|qt_signal_handler
parameter_list|(
name|int
name|sig
parameter_list|)
block|{
name|signal
argument_list|(
name|sig
argument_list|,
name|SIG_DFL
argument_list|)
expr_stmt|;
if|if
condition|(
name|QSegfaultHandler
operator|::
name|callback
condition|)
block|{
call|(
modifier|*
name|QSegfaultHandler
operator|::
name|callback
call|)
argument_list|()
expr_stmt|;
name|_exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
name|FILE
modifier|*
name|outb
init|=
name|stderr
decl_stmt|;
if|if
condition|(
name|char
modifier|*
name|crash_loc
init|=
operator|::
name|getenv
argument_list|(
literal|"QT_CRASH_OUTPUT"
argument_list|)
condition|)
block|{
if|if
condition|(
name|FILE
modifier|*
name|new_outb
init|=
name|fopen
argument_list|(
name|crash_loc
argument_list|,
literal|"w"
argument_list|)
condition|)
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"Crash (backtrace written to %s)!!!\n"
argument_list|,
name|crash_loc
argument_list|)
expr_stmt|;
name|outb
operator|=
name|new_outb
expr_stmt|;
block|}
block|}
else|else
block|{
name|fprintf
argument_list|(
name|outb
argument_list|,
literal|"Crash!!!\n"
argument_list|)
expr_stmt|;
block|}
name|print_backtrace
argument_list|(
name|outb
argument_list|)
expr_stmt|;
if|if
condition|(
name|outb
operator|!=
name|stderr
condition|)
name|fclose
argument_list|(
name|outb
argument_list|)
expr_stmt|;
name|_exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
name|void
DECL|function|initialize
name|QSegfaultHandler
operator|::
name|initialize
parameter_list|(
name|char
modifier|*
modifier|*
name|argv
parameter_list|,
name|int
name|argc
parameter_list|)
block|{
name|init_backtrace
argument_list|(
name|argv
argument_list|,
name|argc
argument_list|)
expr_stmt|;
name|struct
name|sigaction
name|SignalAction
decl_stmt|;
name|SignalAction
operator|.
name|sa_flags
operator|=
literal|0
expr_stmt|;
name|SignalAction
operator|.
name|sa_handler
operator|=
name|qt_signal_handler
expr_stmt|;
name|sigemptyset
argument_list|(
operator|&
name|SignalAction
operator|.
name|sa_mask
argument_list|)
expr_stmt|;
name|sigaction
argument_list|(
name|SIGSEGV
argument_list|,
operator|&
name|SignalAction
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
name|sigaction
argument_list|(
name|SIGBUS
argument_list|,
operator|&
name|SignalAction
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
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
comment|// QT_NO_CRASHHANDLER
end_comment
end_unit
