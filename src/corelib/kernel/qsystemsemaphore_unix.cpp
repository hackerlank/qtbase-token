begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qsystemsemaphore.h"
end_include
begin_include
include|#
directive|include
file|"qsystemsemaphore_p.h"
end_include
begin_include
include|#
directive|include
file|<qdebug.h>
end_include
begin_include
include|#
directive|include
file|<qcoreapplication.h>
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_SYSTEMSEMAPHORE
end_ifndef
begin_include
include|#
directive|include
file|<sys/types.h>
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_POSIX_IPC
end_ifndef
begin_include
include|#
directive|include
file|<sys/ipc.h>
end_include
begin_include
include|#
directive|include
file|<sys/sem.h>
end_include
begin_endif
endif|#
directive|endif
end_endif
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
file|"private/qcore_unix_p.h"
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_constructor
DECL|function|QSystemSemaphorePrivate
name|QSystemSemaphorePrivate
operator|::
name|QSystemSemaphorePrivate
parameter_list|()
member_init_list|:
ifndef|#
directive|ifndef
name|QT_POSIX_IPC
name|unix_key
argument_list|(
operator|-
literal|1
argument_list|)
member_init_list|,
name|semaphore
argument_list|(
operator|-
literal|1
argument_list|)
member_init_list|,
name|createdFile
argument_list|(
literal|false
argument_list|)
member_init_list|,
else|#
directive|else
name|semaphore
argument_list|(
name|SEM_FAILED
argument_list|)
member_init_list|,
endif|#
directive|endif
comment|// QT_POSIX_IPC
name|createdSemaphore
argument_list|(
literal|false
argument_list|)
member_init_list|,
name|error
argument_list|(
name|QSystemSemaphore
operator|::
name|NoError
argument_list|)
block|{ }
end_constructor
begin_function
DECL|function|setErrorString
name|void
name|QSystemSemaphorePrivate
operator|::
name|setErrorString
parameter_list|(
specifier|const
name|QString
modifier|&
name|function
parameter_list|)
block|{
comment|// EINVAL is handled in functions so they can give better error strings
switch|switch
condition|(
name|errno
condition|)
block|{
case|case
name|EPERM
case|:
case|case
name|EACCES
case|:
name|errorString
operator|=
name|QCoreApplication
operator|::
name|translate
argument_list|(
literal|"QSystemSemaphore"
argument_list|,
literal|"%1: permission denied"
argument_list|)
operator|.
name|arg
argument_list|(
name|function
argument_list|)
expr_stmt|;
name|error
operator|=
name|QSystemSemaphore
operator|::
name|PermissionDenied
expr_stmt|;
break|break;
case|case
name|EEXIST
case|:
name|errorString
operator|=
name|QCoreApplication
operator|::
name|translate
argument_list|(
literal|"QSystemSemaphore"
argument_list|,
literal|"%1: already exists"
argument_list|)
operator|.
name|arg
argument_list|(
name|function
argument_list|)
expr_stmt|;
name|error
operator|=
name|QSystemSemaphore
operator|::
name|AlreadyExists
expr_stmt|;
break|break;
case|case
name|ENOENT
case|:
name|errorString
operator|=
name|QCoreApplication
operator|::
name|translate
argument_list|(
literal|"QSystemSemaphore"
argument_list|,
literal|"%1: does not exist"
argument_list|)
operator|.
name|arg
argument_list|(
name|function
argument_list|)
expr_stmt|;
name|error
operator|=
name|QSystemSemaphore
operator|::
name|NotFound
expr_stmt|;
break|break;
case|case
name|ERANGE
case|:
case|case
name|ENOSPC
case|:
name|errorString
operator|=
name|QCoreApplication
operator|::
name|translate
argument_list|(
literal|"QSystemSemaphore"
argument_list|,
literal|"%1: out of resources"
argument_list|)
operator|.
name|arg
argument_list|(
name|function
argument_list|)
expr_stmt|;
name|error
operator|=
name|QSystemSemaphore
operator|::
name|OutOfResources
expr_stmt|;
break|break;
default|default:
name|errorString
operator|=
name|QCoreApplication
operator|::
name|translate
argument_list|(
literal|"QSystemSemaphore"
argument_list|,
literal|"%1: unknown error %2"
argument_list|)
operator|.
name|arg
argument_list|(
name|function
argument_list|)
operator|.
name|arg
argument_list|(
name|errno
argument_list|)
expr_stmt|;
name|error
operator|=
name|QSystemSemaphore
operator|::
name|UnknownError
expr_stmt|;
if|#
directive|if
name|defined
name|QSYSTEMSEMAPHORE_DEBUG
name|qDebug
argument_list|()
operator|<<
name|errorString
operator|<<
literal|"key"
operator|<<
name|key
operator|<<
literal|"errno"
operator|<<
name|errno
operator|<<
name|EINVAL
expr_stmt|;
endif|#
directive|endif
block|}
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
comment|// QT_NO_SYSTEMSEMAPHORE
end_comment
end_unit
