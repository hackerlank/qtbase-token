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
begin_ifdef
ifdef|#
directive|ifdef
name|UNICODE
end_ifdef
begin_ifndef
ifndef|#
directive|ifndef
name|_UNICODE
end_ifndef
begin_define
DECL|macro|_UNICODE
define|#
directive|define
name|_UNICODE
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// Get Qt defines/settings
end_comment
begin_include
include|#
directive|include
file|"qglobal.h"
end_include
begin_define
DECL|macro|_POSIX_
define|#
directive|define
name|_POSIX_
end_define
begin_include
include|#
directive|include
file|<limits.h>
end_include
begin_undef
DECL|macro|_POSIX_
undef|#
directive|undef
name|_POSIX_
end_undef
begin_include
include|#
directive|include
file|<tchar.h>
end_include
begin_include
include|#
directive|include
file|<io.h>
end_include
begin_include
include|#
directive|include
file|<direct.h>
end_include
begin_include
include|#
directive|include
file|<stdio.h>
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
file|<sys/stat.h>
end_include
begin_include
include|#
directive|include
file|<stdlib.h>
end_include
begin_include
include|#
directive|include
file|<windows.h>
end_include
begin_define
DECL|macro|Q_FS_FAT
define|#
directive|define
name|Q_FS_FAT
end_define
begin_ifdef
ifdef|#
directive|ifdef
name|QT_LARGEFILE_SUPPORT
end_ifdef
begin_define
DECL|macro|QT_STATBUF
define|#
directive|define
name|QT_STATBUF
value|struct _stati64
end_define
begin_comment
DECL|macro|QT_STATBUF
comment|// non-ANSI defs
end_comment
begin_define
DECL|macro|QT_STATBUF4TSTAT
define|#
directive|define
name|QT_STATBUF4TSTAT
value|struct _stati64
end_define
begin_comment
DECL|macro|QT_STATBUF4TSTAT
comment|// non-ANSI defs
end_comment
begin_define
DECL|macro|QT_STAT
define|#
directive|define
name|QT_STAT
value|::_stati64
end_define
begin_define
DECL|macro|QT_FSTAT
define|#
directive|define
name|QT_FSTAT
value|::_fstati64
end_define
begin_else
else|#
directive|else
end_else
begin_define
DECL|macro|QT_STATBUF
define|#
directive|define
name|QT_STATBUF
value|struct _stat
end_define
begin_comment
DECL|macro|QT_STATBUF
comment|// non-ANSI defs
end_comment
begin_define
DECL|macro|QT_STATBUF4TSTAT
define|#
directive|define
name|QT_STATBUF4TSTAT
value|struct _stat
end_define
begin_comment
DECL|macro|QT_STATBUF4TSTAT
comment|// non-ANSI defs
end_comment
begin_define
DECL|macro|QT_STAT
define|#
directive|define
name|QT_STAT
value|::_stat
end_define
begin_define
DECL|macro|QT_FSTAT
define|#
directive|define
name|QT_FSTAT
value|::_fstat
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_define
DECL|macro|QT_STAT_REG
define|#
directive|define
name|QT_STAT_REG
value|_S_IFREG
end_define
begin_define
DECL|macro|QT_STAT_DIR
define|#
directive|define
name|QT_STAT_DIR
value|_S_IFDIR
end_define
begin_define
DECL|macro|QT_STAT_MASK
define|#
directive|define
name|QT_STAT_MASK
value|_S_IFMT
end_define
begin_if
if|#
directive|if
name|defined
argument_list|(
name|_S_IFLNK
argument_list|)
end_if
begin_define
DECL|macro|QT_STAT_LNK
define|#
directive|define
name|QT_STAT_LNK
value|_S_IFLNK
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_define
DECL|macro|QT_FILENO
define|#
directive|define
name|QT_FILENO
value|_fileno
end_define
begin_define
DECL|macro|QT_OPEN
define|#
directive|define
name|QT_OPEN
value|::_open
end_define
begin_define
DECL|macro|QT_CLOSE
define|#
directive|define
name|QT_CLOSE
value|::_close
end_define
begin_ifdef
ifdef|#
directive|ifdef
name|QT_LARGEFILE_SUPPORT
end_ifdef
begin_define
DECL|macro|QT_LSEEK
define|#
directive|define
name|QT_LSEEK
value|::_lseeki64
end_define
begin_define
DECL|macro|QT_TSTAT
define|#
directive|define
name|QT_TSTAT
value|::_tstati64
end_define
begin_else
else|#
directive|else
end_else
begin_define
DECL|macro|QT_LSEEK
define|#
directive|define
name|QT_LSEEK
value|::_lseek
end_define
begin_define
DECL|macro|QT_TSTAT
define|#
directive|define
name|QT_TSTAT
value|::_tstat
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_define
DECL|macro|QT_READ
define|#
directive|define
name|QT_READ
value|::_read
end_define
begin_define
DECL|macro|QT_WRITE
define|#
directive|define
name|QT_WRITE
value|::_write
end_define
begin_define
DECL|macro|QT_ACCESS
define|#
directive|define
name|QT_ACCESS
value|::_access
end_define
begin_define
DECL|macro|QT_GETCWD
define|#
directive|define
name|QT_GETCWD
value|::_getcwd
end_define
begin_define
DECL|macro|QT_CHDIR
define|#
directive|define
name|QT_CHDIR
value|::_chdir
end_define
begin_define
DECL|macro|QT_MKDIR
define|#
directive|define
name|QT_MKDIR
value|::_mkdir
end_define
begin_define
DECL|macro|QT_RMDIR
define|#
directive|define
name|QT_RMDIR
value|::_rmdir
end_define
begin_define
DECL|macro|QT_OPEN_LARGEFILE
define|#
directive|define
name|QT_OPEN_LARGEFILE
value|0
end_define
begin_define
DECL|macro|QT_OPEN_RDONLY
define|#
directive|define
name|QT_OPEN_RDONLY
value|_O_RDONLY
end_define
begin_define
DECL|macro|QT_OPEN_WRONLY
define|#
directive|define
name|QT_OPEN_WRONLY
value|_O_WRONLY
end_define
begin_define
DECL|macro|QT_OPEN_RDWR
define|#
directive|define
name|QT_OPEN_RDWR
value|_O_RDWR
end_define
begin_define
DECL|macro|QT_OPEN_CREAT
define|#
directive|define
name|QT_OPEN_CREAT
value|_O_CREAT
end_define
begin_define
DECL|macro|QT_OPEN_TRUNC
define|#
directive|define
name|QT_OPEN_TRUNC
value|_O_TRUNC
end_define
begin_define
DECL|macro|QT_OPEN_APPEND
define|#
directive|define
name|QT_OPEN_APPEND
value|_O_APPEND
end_define
begin_if
if|#
directive|if
name|defined
argument_list|(
name|O_TEXT
argument_list|)
end_if
begin_define
DECL|macro|QT_OPEN_TEXT
define|#
directive|define
name|QT_OPEN_TEXT
value|_O_TEXT
end_define
begin_define
DECL|macro|QT_OPEN_BINARY
define|#
directive|define
name|QT_OPEN_BINARY
value|_O_BINARY
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_include
include|#
directive|include
file|"../common/c89/qplatformdefs.h"
end_include
begin_if
if|#
directive|if
name|defined
argument_list|(
name|QT_LARGEFILE_SUPPORT
argument_list|)
operator|&&
name|_MSC_VER
operator|>
literal|1310
end_if
begin_undef
DECL|macro|QT_FSEEK
undef|#
directive|undef
name|QT_FSEEK
end_undef
begin_undef
DECL|macro|QT_FTELL
undef|#
directive|undef
name|QT_FTELL
end_undef
begin_define
DECL|macro|QT_FSEEK
define|#
directive|define
name|QT_FSEEK
value|::_fseeki64
end_define
begin_define
DECL|macro|QT_FTELL
define|#
directive|define
name|QT_FTELL
value|::_ftelli64
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_if
if|#
directive|if
name|defined
argument_list|(
name|QT_LARGEFILE_SUPPORT
argument_list|)
end_if
begin_undef
DECL|macro|QT_OFF_T
undef|#
directive|undef
name|QT_OFF_T
end_undef
begin_define
DECL|macro|QT_OFF_T
define|#
directive|define
name|QT_OFF_T
value|__int64
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_define
DECL|macro|QT_SIGNAL_ARGS
define|#
directive|define
name|QT_SIGNAL_ARGS
value|int
end_define
begin_if
if|#
directive|if
name|_MSC_VER
operator|>=
literal|1400
end_if
begin_define
DECL|macro|QT_VSNPRINTF
define|#
directive|define
name|QT_VSNPRINTF
parameter_list|(
name|buffer
parameter_list|,
name|count
parameter_list|,
name|format
parameter_list|,
name|arg
parameter_list|)
define|\
value|::vsnprintf_s(buffer, count, count-1, format, arg)
end_define
begin_else
else|#
directive|else
end_else
begin_define
DECL|macro|QT_VSNPRINTF
define|#
directive|define
name|QT_VSNPRINTF
value|::_vsnprintf
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_define
DECL|macro|QT_SNPRINTF
define|#
directive|define
name|QT_SNPRINTF
value|::_snprintf
end_define
begin_define
DECL|macro|F_OK
define|#
directive|define
name|F_OK
value|0
end_define
begin_define
DECL|macro|X_OK
define|#
directive|define
name|X_OK
value|1
end_define
begin_define
DECL|macro|W_OK
define|#
directive|define
name|W_OK
value|2
end_define
begin_define
DECL|macro|R_OK
define|#
directive|define
name|R_OK
value|4
end_define
begin_typedef
DECL|typedef|mode_t
typedef|typedef
name|int
name|mode_t
typedef|;
end_typedef
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QPLATFORMDEFS_H
end_comment
end_unit
