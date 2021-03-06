begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QFUNCTIONS_NACL_H
end_ifndef
begin_define
DECL|macro|QFUNCTIONS_NACL_H
define|#
directive|define
name|QFUNCTIONS_NACL_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qglobal.h>
end_include
begin_ifdef
ifdef|#
directive|ifdef
name|Q_OS_NACL
end_ifdef
begin_include
include|#
directive|include
file|<sys/types.h>
end_include
begin_comment
comment|// pthread
end_comment
begin_include
include|#
directive|include
file|<pthread.h>
end_include
begin_define
DECL|macro|PTHREAD_CANCEL_DISABLE
define|#
directive|define
name|PTHREAD_CANCEL_DISABLE
value|1
end_define
begin_define
DECL|macro|PTHREAD_CANCEL_ENABLE
define|#
directive|define
name|PTHREAD_CANCEL_ENABLE
value|2
end_define
begin_define
DECL|macro|PTHREAD_INHERIT_SCHED
define|#
directive|define
name|PTHREAD_INHERIT_SCHED
value|3
end_define
begin_expr_stmt
name|QT_BEGIN_NAMESPACE
specifier|extern
literal|"C"
block|{
name|void
name|pthread_cleanup_push
argument_list|(
name|void
argument_list|(
operator|*
name|handler
argument_list|)
argument_list|(
name|void
operator|*
argument_list|)
argument_list|,
name|void
operator|*
name|arg
argument_list|)
block|;
name|void
name|pthread_cleanup_pop
argument_list|(
argument|int execute
argument_list|)
block|;
name|int
name|pthread_setcancelstate
argument_list|(
argument|int state
argument_list|,
argument|int *oldstate
argument_list|)
block|;
name|int
name|pthread_setcanceltype
argument_list|(
argument|int type
argument_list|,
argument|int *oldtype
argument_list|)
block|;
name|void
name|pthread_testcancel
argument_list|(
name|void
argument_list|)
block|;
name|int
name|pthread_cancel
argument_list|(
argument|pthread_t thread
argument_list|)
block|;
name|int
name|pthread_attr_setinheritsched
argument_list|(
argument|pthread_attr_t *attr
argument_list|,
argument|int inheritsched
argument_list|)
block|;
name|int
name|pthread_attr_getinheritsched
argument_list|(
specifier|const
name|pthread_attr_t
operator|*
name|attr
argument_list|,
name|int
operator|*
name|inheritsched
argument_list|)
block|;
comment|// event dispatcher, select
comment|//struct fd_set;
comment|//struct timeval;
name|int
name|fcntl
argument_list|(
argument|int fildes
argument_list|,
argument|int cmd
argument_list|,
argument|...
argument_list|)
block|;
name|int
name|sigaction
argument_list|(
argument|int sig
argument_list|,
argument|const struct sigaction * act
argument_list|,
argument|struct sigaction * oact
argument_list|)
block|;
DECL|typedef|off64_t
typedef|typedef
name|long
name|off64_t
typedef|;
name|off64_t
name|ftello64
argument_list|(
name|void
operator|*
name|stream
argument_list|)
expr_stmt|;
end_expr_stmt
begin_function_decl
name|off64_t
name|lseek64
parameter_list|(
name|int
name|fildes
parameter_list|,
name|off_t
name|offset
parameter_list|,
name|int
name|whence
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|int
name|open64
parameter_list|(
specifier|const
name|char
modifier|*
name|path
parameter_list|,
name|int
name|oflag
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl
begin_macro
unit|}  int
name|select
argument_list|(
argument|int nfds
argument_list|,
argument|fd_set * readfds
argument_list|,
argument|fd_set * writefds
argument_list|,
argument|fd_set * errorfds
argument_list|,
argument|struct timeval * timeout
argument_list|)
end_macro
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|//Q_OS_NACL
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|//QFUNCTIONS_NACL_H
end_comment
end_unit
