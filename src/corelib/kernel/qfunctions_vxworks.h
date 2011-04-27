begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** No Commercial Usage ** This file contains pre-release code and may not be distributed. ** You may use this file in accordance with the terms and conditions ** contained in the Technology Preview License Agreement accompanying ** this package. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights.  These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** If you have questions regarding the use of this file, please contact ** Nokia at qt-info@nokia.com. ** ** ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QFUNCTIONS_VXWORKS_H
end_ifndef
begin_define
DECL|macro|QFUNCTIONS_VXWORKS_H
define|#
directive|define
name|QFUNCTIONS_VXWORKS_H
end_define
begin_ifdef
ifdef|#
directive|ifdef
name|Q_OS_VXWORKS
end_ifdef
begin_include
include|#
directive|include
file|<unistd.h>
end_include
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
file|<signal.h>
end_include
begin_include
include|#
directive|include
file|<string.h>
end_include
begin_include
include|#
directive|include
file|<strings.h>
end_include
begin_include
include|#
directive|include
file|<errno.h>
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
file|<sys/times.h>
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
begin_decl_stmt
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
ifdef|#
directive|ifdef
name|QT_BUILD_CORE_LIB
name|QT_MODULE
argument_list|(
name|Core
argument_list|)
endif|#
directive|endif
name|QT_END_NAMESPACE
name|QT_END_HEADER
ifndef|#
directive|ifndef
name|RTLD_LOCAL
DECL|macro|RTLD_LOCAL
define|#
directive|define
name|RTLD_LOCAL
value|0
endif|#
directive|endif
ifndef|#
directive|ifndef
name|NSIG
DECL|macro|NSIG
define|#
directive|define
name|NSIG
value|_NSIGS
endif|#
directive|endif
ifdef|#
directive|ifdef
name|__cplusplus
decl|extern "C"
block|{
endif|#
directive|endif
comment|// isascii is missing (sometimes!!)
ifndef|#
directive|ifndef
name|isascii
DECL|function|isascii
specifier|inline
name|int
name|isascii
parameter_list|(
name|int
name|c
parameter_list|)
block|{
return|return
operator|(
name|c
operator|&
literal|0x7f
operator|)
return|;
block|}
endif|#
directive|endif
comment|// no lfind() - used by the TIF image format
name|void
modifier|*
name|lfind
parameter_list|(
specifier|const
name|void
modifier|*
name|key
parameter_list|,
specifier|const
name|void
modifier|*
name|base
parameter_list|,
name|size_t
modifier|*
name|elements
parameter_list|,
name|size_t
name|size
parameter_list|,
name|int
function_decl|(
modifier|*
name|compare
function_decl|)
parameter_list|(
specifier|const
name|void
modifier|*
parameter_list|,
specifier|const
name|void
modifier|*
parameter_list|)
parameter_list|)
function_decl|;
comment|// no rand_r(), but rand()
comment|// NOTE: this implementation is wrong for multi threaded applications,
comment|// but there is no way to get it right on VxWorks (in kernel mode)
name|int
name|rand_r
parameter_list|(
name|unsigned
name|int
modifier|*
comment|/*seedp*/
parameter_list|)
function_decl|;
comment|// no usleep() support
name|int
name|usleep
parameter_list|(
name|unsigned
name|int
parameter_list|)
function_decl|;
comment|// gettimeofday() is declared, but is missing from the library.
comment|// It IS however defined in the Curtis-Wright X11 libraries, so
comment|// we have to make the symbol 'weak'
name|int
name|gettimeofday
parameter_list|(
name|struct
name|timeval
modifier|*
name|tv
parameter_list|,
name|void
comment|/*struct timezone*/
modifier|*
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(weak
block|)
decl_stmt|);
end_decl_stmt
begin_comment
comment|// neither getpagesize() or sysconf(_SC_PAGESIZE) are available
end_comment
begin_function_decl
name|int
name|getpagesize
parameter_list|()
function_decl|;
end_function_decl
begin_comment
comment|// symlinks are not supported (lstat is now just a call to stat - see qplatformdefs.h)
end_comment
begin_function_decl
name|int
name|symlink
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|ssize_t
name|readlink
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl
begin_comment
comment|// there's no truncate(), but ftruncate() support...
end_comment
begin_function_decl
name|int
name|truncate
parameter_list|(
specifier|const
name|char
modifier|*
name|path
parameter_list|,
name|off_t
name|length
parameter_list|)
function_decl|;
end_function_decl
begin_comment
comment|// VxWorks doesn't know about passwd& friends.
end_comment
begin_comment
comment|// in order to avoid patching the unix fs path everywhere
end_comment
begin_comment
comment|// we introduce some dummy functions that simulate a single
end_comment
begin_comment
comment|// 'root' user on the system.
end_comment
begin_function_decl
name|uid_t
name|getuid
parameter_list|()
function_decl|;
end_function_decl
begin_function_decl
name|gid_t
name|getgid
parameter_list|()
function_decl|;
end_function_decl
begin_function_decl
name|uid_t
name|geteuid
parameter_list|()
function_decl|;
end_function_decl
begin_struct
DECL|struct|passwd
struct|struct
name|passwd
block|{
DECL|member|pw_name
name|char
modifier|*
name|pw_name
decl_stmt|;
comment|/* user name */
DECL|member|pw_passwd
name|char
modifier|*
name|pw_passwd
decl_stmt|;
comment|/* user password */
DECL|member|pw_uid
name|uid_t
name|pw_uid
decl_stmt|;
comment|/* user ID */
DECL|member|pw_gid
name|gid_t
name|pw_gid
decl_stmt|;
comment|/* group ID */
DECL|member|pw_gecos
name|char
modifier|*
name|pw_gecos
decl_stmt|;
comment|/* real name */
DECL|member|pw_dir
name|char
modifier|*
name|pw_dir
decl_stmt|;
comment|/* home directory */
DECL|member|pw_shell
name|char
modifier|*
name|pw_shell
decl_stmt|;
comment|/* shell program */
block|}
struct|;
end_struct
begin_struct
DECL|struct|group
struct|struct
name|group
block|{
DECL|member|gr_name
name|char
modifier|*
name|gr_name
decl_stmt|;
comment|/* group name */
DECL|member|gr_passwd
name|char
modifier|*
name|gr_passwd
decl_stmt|;
comment|/* group password */
DECL|member|gr_gid
name|gid_t
name|gr_gid
decl_stmt|;
comment|/* group ID */
DECL|member|gr_mem
name|char
modifier|*
modifier|*
name|gr_mem
decl_stmt|;
comment|/* group members */
block|}
struct|;
end_struct
begin_function_decl
name|struct
name|passwd
modifier|*
name|getpwuid
parameter_list|(
name|uid_t
name|uid
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|struct
name|group
modifier|*
name|getgrgid
parameter_list|(
name|gid_t
name|gid
parameter_list|)
function_decl|;
end_function_decl
begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef
begin_comment
unit|}
comment|// extern "C"
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// Q_OS_VXWORKS
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QFUNCTIONS_VXWORKS_H
end_comment
end_unit
