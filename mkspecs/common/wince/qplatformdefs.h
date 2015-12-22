begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the qmake spec of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
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
begin_include
include|#
directive|include
file|"qfunctions_wince.h"
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
file|<stdio.h>
end_include
begin_include
include|#
directive|include
file|<stdlib.h>
end_include
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
value|struct stat
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
value|struct stat
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
value|::qt_wince_stat
end_define
begin_define
DECL|macro|QT_FSTAT
define|#
directive|define
name|QT_FSTAT
value|::qt_wince__fstat
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
value|::qt_wince___fileno
end_define
begin_define
DECL|macro|QT_OPEN
define|#
directive|define
name|QT_OPEN
value|::qt_wince_open
end_define
begin_define
DECL|macro|QT_CLOSE
define|#
directive|define
name|QT_CLOSE
value|::qt_wince__close
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
value|::qt_wince__lseek
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
value|::qt_wince__read
end_define
begin_define
DECL|macro|QT_WRITE
define|#
directive|define
name|QT_WRITE
value|::qt_wince__write
end_define
begin_define
DECL|macro|QT_ACCESS
define|#
directive|define
name|QT_ACCESS
value|::qt_wince__access
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
value|::qt_wince__mkdir
end_define
begin_define
DECL|macro|QT_RMDIR
define|#
directive|define
name|QT_RMDIR
value|::qt_wince__rmdir
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
begin_define
DECL|macro|QT_FOPEN
define|#
directive|define
name|QT_FOPEN
value|::fopen
end_define
begin_define
DECL|macro|QT_FSEEK
define|#
directive|define
name|QT_FSEEK
value|::fseek
end_define
begin_define
DECL|macro|QT_FTELL
define|#
directive|define
name|QT_FTELL
value|::ftell
end_define
begin_define
DECL|macro|QT_FGETPOS
define|#
directive|define
name|QT_FGETPOS
value|::fgetpos
end_define
begin_define
DECL|macro|QT_FSETPOS
define|#
directive|define
name|QT_FSETPOS
value|::fsetpos
end_define
begin_define
DECL|macro|QT_MMAP
define|#
directive|define
name|QT_MMAP
value|::mmap
end_define
begin_define
DECL|macro|QT_FPOS_T
define|#
directive|define
name|QT_FPOS_T
value|fpos_t
end_define
begin_define
DECL|macro|QT_OFF_T
define|#
directive|define
name|QT_OFF_T
value|long
end_define
begin_define
DECL|macro|QT_SIGNAL_ARGS
define|#
directive|define
name|QT_SIGNAL_ARGS
value|int
end_define
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
value|_vsnprintf(buffer, count, format, arg)
end_define
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
