begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
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
file|"qcoreapplication.h"
end_include
begin_include
include|#
directive|include
file|<qdebug.h>
end_include
begin_include
include|#
directive|include
file|<qt_windows.h>
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_SYSTEMSEMAPHORE
end_ifndef
begin_constructor
DECL|function|QSystemSemaphorePrivate
name|QSystemSemaphorePrivate
operator|::
name|QSystemSemaphorePrivate
parameter_list|()
member_init_list|:
name|semaphore
argument_list|(
literal|0
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
name|BOOL
name|windowsError
init|=
name|GetLastError
argument_list|()
decl_stmt|;
if|if
condition|(
name|windowsError
operator|==
literal|0
condition|)
return|return;
switch|switch
condition|(
name|windowsError
condition|)
block|{
case|case
name|ERROR_NO_SYSTEM_RESOURCES
case|:
case|case
name|ERROR_NOT_ENOUGH_MEMORY
case|:
name|error
operator|=
name|QSystemSemaphore
operator|::
name|OutOfResources
expr_stmt|;
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
break|break;
case|case
name|ERROR_ACCESS_DENIED
case|:
name|error
operator|=
name|QSystemSemaphore
operator|::
name|PermissionDenied
expr_stmt|;
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
name|windowsError
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
expr_stmt|;
endif|#
directive|endif
block|}
block|}
end_function
begin_function
DECL|function|handle
name|HANDLE
name|QSystemSemaphorePrivate
operator|::
name|handle
parameter_list|(
name|QSystemSemaphore
operator|::
name|AccessMode
parameter_list|)
block|{
comment|// don't allow making handles on empty keys
if|if
condition|(
name|key
operator|.
name|isEmpty
argument_list|()
condition|)
return|return
literal|0
return|;
comment|// Create it if it doesn't already exists.
if|if
condition|(
name|semaphore
operator|==
literal|0
condition|)
block|{
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_WINRT
argument_list|)
name|semaphore
operator|=
name|CreateSemaphoreEx
argument_list|(
literal|0
argument_list|,
name|initialValue
argument_list|,
name|MAXLONG
argument_list|,
operator|(
name|wchar_t
operator|*
operator|)
name|fileName
operator|.
name|utf16
argument_list|()
argument_list|,
literal|0
argument_list|,
name|SEMAPHORE_ALL_ACCESS
argument_list|)
expr_stmt|;
else|#
directive|else
name|semaphore
operator|=
name|CreateSemaphore
argument_list|(
literal|0
argument_list|,
name|initialValue
argument_list|,
name|MAXLONG
argument_list|,
operator|(
name|wchar_t
operator|*
operator|)
name|fileName
operator|.
name|utf16
argument_list|()
argument_list|)
expr_stmt|;
endif|#
directive|endif
if|if
condition|(
name|semaphore
operator|==
name|NULL
condition|)
name|setErrorString
argument_list|(
name|QLatin1String
argument_list|(
literal|"QSystemSemaphore::handle"
argument_list|)
argument_list|)
expr_stmt|;
block|}
return|return
name|semaphore
return|;
block|}
end_function
begin_function
DECL|function|cleanHandle
name|void
name|QSystemSemaphorePrivate
operator|::
name|cleanHandle
parameter_list|()
block|{
if|if
condition|(
name|semaphore
operator|&&
operator|!
name|CloseHandle
argument_list|(
name|semaphore
argument_list|)
condition|)
block|{
if|#
directive|if
name|defined
name|QSYSTEMSEMAPHORE_DEBUG
name|qDebug
argument_list|()
operator|<<
name|QLatin1String
argument_list|(
literal|"QSystemSemaphorePrivate::CloseHandle: sem failed"
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
name|semaphore
operator|=
literal|0
expr_stmt|;
block|}
end_function
begin_function
DECL|function|modifySemaphore
name|bool
name|QSystemSemaphorePrivate
operator|::
name|modifySemaphore
parameter_list|(
name|int
name|count
parameter_list|)
block|{
if|if
condition|(
literal|0
operator|==
name|handle
argument_list|()
condition|)
return|return
literal|false
return|;
if|if
condition|(
name|count
operator|>
literal|0
condition|)
block|{
if|if
condition|(
literal|0
operator|==
name|ReleaseSemaphore
argument_list|(
name|semaphore
argument_list|,
name|count
argument_list|,
literal|0
argument_list|)
condition|)
block|{
name|setErrorString
argument_list|(
name|QLatin1String
argument_list|(
literal|"QSystemSemaphore::modifySemaphore"
argument_list|)
argument_list|)
expr_stmt|;
if|#
directive|if
name|defined
name|QSYSTEMSEMAPHORE_DEBUG
name|qDebug
argument_list|()
operator|<<
name|QLatin1String
argument_list|(
literal|"QSystemSemaphore::modifySemaphore ReleaseSemaphore failed"
argument_list|)
expr_stmt|;
endif|#
directive|endif
return|return
literal|false
return|;
block|}
block|}
else|else
block|{
if|#
directive|if
operator|!
name|defined
argument_list|(
name|Q_OS_WINCE
argument_list|)
if|if
condition|(
name|WAIT_OBJECT_0
operator|!=
name|WaitForSingleObjectEx
argument_list|(
name|semaphore
argument_list|,
name|INFINITE
argument_list|,
name|FALSE
argument_list|)
condition|)
block|{
else|#
directive|else
if|if
condition|(
name|WAIT_OBJECT_0
operator|!=
name|WaitForSingleObject
argument_list|(
name|semaphore
argument_list|,
name|INFINITE
argument_list|)
condition|)
block|{
endif|#
directive|endif
name|setErrorString
argument_list|(
name|QLatin1String
argument_list|(
literal|"QSystemSemaphore::modifySemaphore"
argument_list|)
argument_list|)
expr_stmt|;
if|#
directive|if
name|defined
name|QSYSTEMSEMAPHORE_DEBUG
name|qDebug
argument_list|()
operator|<<
name|QLatin1String
argument_list|(
literal|"QSystemSemaphore::modifySemaphore WaitForSingleObject failed"
argument_list|)
expr_stmt|;
endif|#
directive|endif
return|return
literal|false
return|;
block|}
block|}
name|clearError
argument_list|()
expr_stmt|;
return|return
literal|true
return|;
block|}
endif|#
directive|endif
comment|//QT_NO_SYSTEMSEMAPHORE
name|QT_END_NAMESPACE
end_function
end_unit
