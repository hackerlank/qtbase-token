begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qfunctions_nacl.h"
end_include
begin_include
include|#
directive|include
file|<pthread.h>
end_include
begin_include
include|#
directive|include
file|<qglobal.h>
end_include
begin_comment
comment|/*     The purpose of this file is to stub out certain functions     that are not provided by the Native Client SDK. This is     done as an alterative to sprinkling the Qt sources with     NACL ifdefs.      There are two main classes of functions:      - Functions that are called but can have no effect:     For these we simply give an empty implementation      - Functions that are referenced in the source code, but     is not/must not be called at run-time:     These we either leave undefined or implement with a     qFatal.      This is a work in progress. */
end_comment
begin_extern
extern|extern
literal|"C"
block|{
DECL|function|pthread_cleanup_push
name|void
name|pthread_cleanup_push
parameter_list|(
name|void
function_decl|(
modifier|*
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
parameter_list|,
name|void
modifier|*
parameter_list|)
block|{  }
DECL|function|pthread_cleanup_pop
name|void
name|pthread_cleanup_pop
parameter_list|(
name|int
parameter_list|)
block|{  }
DECL|function|pthread_setcancelstate
name|int
name|pthread_setcancelstate
parameter_list|(
name|int
parameter_list|,
name|int
modifier|*
parameter_list|)
block|{
return|return
literal|0
return|;
block|}
DECL|function|pthread_setcanceltype
name|int
name|pthread_setcanceltype
parameter_list|(
name|int
parameter_list|,
name|int
modifier|*
parameter_list|)
block|{
return|return
literal|0
return|;
block|}
DECL|function|pthread_testcancel
name|void
name|pthread_testcancel
parameter_list|(
name|void
parameter_list|)
block|{  }
DECL|function|pthread_cancel
name|int
name|pthread_cancel
parameter_list|(
name|pthread_t
parameter_list|)
block|{
return|return
literal|0
return|;
block|}
DECL|function|pthread_attr_setinheritsched
name|int
name|pthread_attr_setinheritsched
parameter_list|(
name|pthread_attr_t
modifier|*
parameter_list|,
name|int
parameter_list|)
block|{
return|return
literal|0
return|;
block|}
DECL|function|pthread_attr_getinheritsched
name|int
name|pthread_attr_getinheritsched
parameter_list|(
specifier|const
name|pthread_attr_t
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|)
block|{
return|return
literal|0
return|;
block|}
comment|// event dispatcher, select
comment|//struct fd_set;
comment|//struct timeval;
DECL|function|fcntl
name|int
name|fcntl
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|,
modifier|...
parameter_list|)
block|{
return|return
literal|0
return|;
block|}
DECL|function|sigaction
name|int
name|sigaction
parameter_list|(
name|int
parameter_list|,
specifier|const
name|struct
name|sigaction
modifier|*
parameter_list|,
name|struct
name|sigaction
modifier|*
parameter_list|)
block|{
return|return
literal|0
return|;
block|}
DECL|function|open
name|int
name|open
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
modifier|...
parameter_list|)
block|{
return|return
literal|0
return|;
block|}
DECL|function|open64
name|int
name|open64
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
modifier|...
parameter_list|)
block|{
return|return
literal|0
return|;
block|}
DECL|function|access
name|int
name|access
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
block|{
return|return
literal|0
return|;
block|}
DECL|typedef|off64_t
typedef|typedef
name|long
name|off64_t
typedef|;
DECL|function|ftello64
name|off64_t
name|ftello64
parameter_list|(
name|void
modifier|*
parameter_list|)
block|{
name|qFatal
argument_list|(
literal|"ftello64 called"
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
DECL|function|lseek64
name|off64_t
name|lseek64
parameter_list|(
name|int
parameter_list|,
name|off_t
parameter_list|,
name|int
parameter_list|)
block|{
name|qFatal
argument_list|(
literal|"lseek64 called"
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
block|}
end_extern
begin_comment
comment|// Extern C
end_comment
begin_function
DECL|function|select
name|int
name|select
parameter_list|(
name|int
parameter_list|,
name|fd_set
modifier|*
parameter_list|,
name|fd_set
modifier|*
parameter_list|,
name|fd_set
modifier|*
parameter_list|,
name|struct
name|timeval
modifier|*
parameter_list|)
block|{
return|return
literal|0
return|;
block|}
end_function
end_unit
