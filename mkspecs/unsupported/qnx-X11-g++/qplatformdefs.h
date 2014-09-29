begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2014 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the qmake spec of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia. For licensing terms and ** conditions see http://qt.digia.com/licensing. For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights. These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QPLATFORMDEFS_H
end_ifndef
begin_define
DECL|macro|QPLATFORMDEFS_H
define|#
directive|define
name|QPLATFORMDEFS_H
end_define
begin_comment
comment|// Get Qt defines/settings
end_comment
begin_include
include|#
directive|include
file|"qglobal.h"
end_include
begin_comment
comment|// Set any POSIX/XOPEN defines at the top of this file to turn on specific APIs
end_comment
begin_include
include|#
directive|include
file|<unistd.h>
end_include
begin_comment
comment|// We are hot - unistd.h should have turned on the specific APIs we requested
end_comment
begin_include
include|#
directive|include
file|<pthread.h>
end_include
begin_include
include|#
directive|include
file|<dirent.h>
end_include
begin_include
include|#
directive|include
file|<fcntl.h>
end_include
begin_include
include|#
directive|include
file|<grp.h>
end_include
begin_include
include|#
directive|include
file|<pwd.h>
end_include
begin_include
include|#
directive|include
file|<signal.h>
end_include
begin_include
include|#
directive|include
file|<sys/types.h>
end_include
begin_include
include|#
directive|include
file|<sys/ioctl.h>
end_include
begin_include
include|#
directive|include
file|<sys/ipc.h>
end_include
begin_include
include|#
directive|include
file|<sys/time.h>
end_include
begin_comment
comment|// QNX doesn't have the System V<sys/shm.h> header. This is not a standard
end_comment
begin_comment
comment|// POSIX header, it's only documented in the Single UNIX Specification.
end_comment
begin_comment
comment|// The preferred POSIX compliant way to share memory is to use the functions
end_comment
begin_comment
comment|// in<sys/mman.h> that comply with the POSIX Real Time Interface (1003.1b).
end_comment
begin_include
include|#
directive|include
file|<sys/mman.h>
end_include
begin_include
include|#
directive|include
file|<sys/socket.h>
end_include
begin_include
include|#
directive|include
file|<sys/stat.h>
end_include
begin_include
include|#
directive|include
file|<sys/wait.h>
end_include
begin_include
include|#
directive|include
file|<netinet/in.h>
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_IPV6IFNAME
end_ifndef
begin_include
include|#
directive|include
file|<net/if.h>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// for htonl
end_comment
begin_include
include|#
directive|include
file|<arpa/inet.h>
end_include
begin_define
DECL|macro|QT_USE_XOPEN_LFS_EXTENSIONS
define|#
directive|define
name|QT_USE_XOPEN_LFS_EXTENSIONS
end_define
begin_include
include|#
directive|include
file|"../../common/posix/qplatformdefs.h"
end_include
begin_define
DECL|macro|QT_SNPRINTF
define|#
directive|define
name|QT_SNPRINTF
value|::snprintf
end_define
begin_define
DECL|macro|QT_VSNPRINTF
define|#
directive|define
name|QT_VSNPRINTF
value|::vsnprintf
end_define
begin_comment
comment|// QNX6 doesn't have getpagesize()
end_comment
begin_function
DECL|function|getpagesize
specifier|inline
name|int
name|getpagesize
parameter_list|()
block|{
return|return
operator|::
name|sysconf
argument_list|(
name|_SC_PAGESIZE
argument_list|)
return|;
block|}
end_function
begin_include
include|#
directive|include
file|<stdlib.h>
end_include
begin_comment
comment|// QNX6 doesn't have strtof - use strtod instead
end_comment
begin_function
DECL|function|strtof
specifier|inline
name|float
name|strtof
parameter_list|(
specifier|const
name|char
modifier|*
name|b
parameter_list|,
name|char
modifier|*
modifier|*
name|e
parameter_list|)
block|{
return|return
name|float
argument_list|(
name|strtod
argument_list|(
name|b
argument_list|,
name|e
argument_list|)
argument_list|)
return|;
block|}
end_function
begin_define
DECL|macro|QT_QWS_TEMP_DIR
define|#
directive|define
name|QT_QWS_TEMP_DIR
value|QString::fromLatin1(qgetenv("TMP"))
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QPLATFORMDEFS_H
end_comment
end_unit
