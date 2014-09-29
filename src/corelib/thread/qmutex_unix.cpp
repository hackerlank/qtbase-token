begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2014 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia. For licensing terms and ** conditions see http://qt.digia.com/licensing. For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights. These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qplatformdefs.h"
end_include
begin_include
include|#
directive|include
file|"qmutex.h"
end_include
begin_include
include|#
directive|include
file|"qstring.h"
end_include
begin_include
include|#
directive|include
file|"qelapsedtimer.h"
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_THREAD
end_ifndef
begin_include
include|#
directive|include
file|"qatomic.h"
end_include
begin_include
include|#
directive|include
file|"qmutex_p.h"
end_include
begin_include
include|#
directive|include
file|<errno.h>
end_include
begin_include
include|#
directive|include
file|<sys/time.h>
end_include
begin_include
include|#
directive|include
file|<time.h>
end_include
begin_if
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_VXWORKS
argument_list|)
operator|&&
name|defined
argument_list|(
name|wakeup
argument_list|)
end_if
begin_undef
DECL|macro|wakeup
undef|#
directive|undef
name|wakeup
end_undef
begin_endif
endif|#
directive|endif
end_endif
begin_function
name|QT_BEGIN_NAMESPACE
DECL|function|report_error
specifier|static
name|void
name|report_error
parameter_list|(
name|int
name|code
parameter_list|,
specifier|const
name|char
modifier|*
name|where
parameter_list|,
specifier|const
name|char
modifier|*
name|what
parameter_list|)
block|{
if|if
condition|(
name|code
operator|!=
literal|0
condition|)
name|qWarning
argument_list|(
literal|"%s: %s failure: %s"
argument_list|,
name|where
argument_list|,
name|what
argument_list|,
name|qPrintable
argument_list|(
name|qt_error_string
argument_list|(
name|code
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_constructor
DECL|function|QMutexPrivate
name|QMutexPrivate
operator|::
name|QMutexPrivate
parameter_list|()
member_init_list|:
name|wakeup
argument_list|(
literal|false
argument_list|)
block|{
name|report_error
argument_list|(
name|pthread_mutex_init
argument_list|(
operator|&
name|mutex
argument_list|,
name|NULL
argument_list|)
argument_list|,
literal|"QMutex"
argument_list|,
literal|"mutex init"
argument_list|)
expr_stmt|;
name|qt_initialize_pthread_cond
argument_list|(
operator|&
name|cond
argument_list|,
literal|"QMutex"
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_destructor
DECL|function|~QMutexPrivate
name|QMutexPrivate
operator|::
name|~
name|QMutexPrivate
parameter_list|()
block|{
name|report_error
argument_list|(
name|pthread_cond_destroy
argument_list|(
operator|&
name|cond
argument_list|)
argument_list|,
literal|"QMutex"
argument_list|,
literal|"cv destroy"
argument_list|)
expr_stmt|;
name|report_error
argument_list|(
name|pthread_mutex_destroy
argument_list|(
operator|&
name|mutex
argument_list|)
argument_list|,
literal|"QMutex"
argument_list|,
literal|"mutex destroy"
argument_list|)
expr_stmt|;
block|}
end_destructor
begin_function
DECL|function|wait
name|bool
name|QMutexPrivate
operator|::
name|wait
parameter_list|(
name|int
name|timeout
parameter_list|)
block|{
name|report_error
argument_list|(
name|pthread_mutex_lock
argument_list|(
operator|&
name|mutex
argument_list|)
argument_list|,
literal|"QMutex::lock"
argument_list|,
literal|"mutex lock"
argument_list|)
expr_stmt|;
name|int
name|errorCode
init|=
literal|0
decl_stmt|;
while|while
condition|(
operator|!
name|wakeup
condition|)
block|{
if|if
condition|(
name|timeout
operator|<
literal|0
condition|)
block|{
name|errorCode
operator|=
name|pthread_cond_wait
argument_list|(
operator|&
name|cond
argument_list|,
operator|&
name|mutex
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|timespec
name|ti
decl_stmt|;
name|qt_abstime_for_timeout
argument_list|(
operator|&
name|ti
argument_list|,
name|timeout
argument_list|)
expr_stmt|;
name|errorCode
operator|=
name|pthread_cond_timedwait
argument_list|(
operator|&
name|cond
argument_list|,
operator|&
name|mutex
argument_list|,
operator|&
name|ti
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|errorCode
condition|)
block|{
if|if
condition|(
name|errorCode
operator|==
name|ETIMEDOUT
condition|)
block|{
if|if
condition|(
name|wakeup
condition|)
name|errorCode
operator|=
literal|0
expr_stmt|;
break|break;
block|}
name|report_error
argument_list|(
name|errorCode
argument_list|,
literal|"QMutex::lock()"
argument_list|,
literal|"cv wait"
argument_list|)
expr_stmt|;
block|}
block|}
name|bool
name|ret
init|=
name|wakeup
decl_stmt|;
name|wakeup
operator|=
literal|false
expr_stmt|;
name|report_error
argument_list|(
name|pthread_mutex_unlock
argument_list|(
operator|&
name|mutex
argument_list|)
argument_list|,
literal|"QMutex::lock"
argument_list|,
literal|"mutex unlock"
argument_list|)
expr_stmt|;
return|return
name|ret
return|;
block|}
end_function
begin_function
name|void
name|QMutexPrivate
operator|::
name|wakeUp
parameter_list|()
name|Q_DECL_NOTHROW
block|{
name|report_error
argument_list|(
name|pthread_mutex_lock
argument_list|(
operator|&
name|mutex
argument_list|)
argument_list|,
literal|"QMutex::unlock"
argument_list|,
literal|"mutex lock"
argument_list|)
expr_stmt|;
name|wakeup
operator|=
literal|true
expr_stmt|;
name|report_error
argument_list|(
name|pthread_cond_signal
argument_list|(
operator|&
name|cond
argument_list|)
argument_list|,
literal|"QMutex::unlock"
argument_list|,
literal|"cv signal"
argument_list|)
expr_stmt|;
name|report_error
argument_list|(
name|pthread_mutex_unlock
argument_list|(
operator|&
name|mutex
argument_list|)
argument_list|,
literal|"QMutex::unlock"
argument_list|,
literal|"mutex unlock"
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
comment|// QT_NO_THREAD
end_comment
end_unit
