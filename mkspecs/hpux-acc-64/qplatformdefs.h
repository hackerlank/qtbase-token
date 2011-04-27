begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the qmake spec of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** No Commercial Usage ** This file contains pre-release code and may not be distributed. ** You may use this file in accordance with the terms and conditions ** contained in the Technology Preview License Agreement accompanying ** this package. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights.  These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** If you have questions regarding the use of this file, please contact ** Nokia at qt-info@nokia.com. ** ** ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
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
file|<sys/pstat.h>
end_include
begin_define
DECL|macro|_REENTRANT
define|#
directive|define
name|_REENTRANT
end_define
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
file|<dlfcn.h>
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
begin_include
include|#
directive|include
file|<sys/shm.h>
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
begin_define
DECL|macro|QT_USE_XOPEN_LFS_EXTENSIONS
define|#
directive|define
name|QT_USE_XOPEN_LFS_EXTENSIONS
end_define
begin_define
DECL|macro|QT_NO_READDIR64
define|#
directive|define
name|QT_NO_READDIR64
end_define
begin_include
include|#
directive|include
file|"../common/posix/qplatformdefs.h"
end_include
begin_undef
DECL|macro|QT_OPEN_LARGEFILE
undef|#
directive|undef
name|QT_OPEN_LARGEFILE
end_undef
begin_undef
DECL|macro|QT_SOCKLEN_T
undef|#
directive|undef
name|QT_SOCKLEN_T
end_undef
begin_define
DECL|macro|QT_OPEN_LARGEFILE
define|#
directive|define
name|QT_OPEN_LARGEFILE
value|0
end_define
begin_define
DECL|macro|QT_SOCKLEN_T
define|#
directive|define
name|QT_SOCKLEN_T
value|int
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QPLATFORMDEFS_H
end_comment
end_unit
