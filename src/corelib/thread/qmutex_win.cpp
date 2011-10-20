begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<qt_windows.h>
end_include
begin_include
include|#
directive|include
file|"qmutex.h"
end_include
begin_include
include|#
directive|include
file|<qatomic.h>
end_include
begin_include
include|#
directive|include
file|"qmutex_p.h"
end_include
begin_function
name|QT_BEGIN_NAMESPACE
DECL|function|QMutexPrivate
name|QMutexPrivate
operator|::
name|QMutexPrivate
parameter_list|()
block|{
name|event
operator|=
name|CreateEvent
argument_list|(
literal|0
argument_list|,
name|FALSE
argument_list|,
name|FALSE
argument_list|,
literal|0
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|event
condition|)
name|qWarning
argument_list|(
literal|"QMutexData::QMutexData: Cannot create event"
argument_list|)
expr_stmt|;
block|}
end_function
begin_destructor
DECL|function|~QMutexPrivate
name|QMutexPrivate
operator|::
name|~
name|QMutexPrivate
parameter_list|()
block|{
name|CloseHandle
argument_list|(
name|event
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
return|return
operator|(
name|WaitForSingleObject
argument_list|(
name|event
argument_list|,
name|timeout
operator|<
literal|0
condition|?
name|INFINITE
else|:
name|timeout
argument_list|)
operator|==
name|WAIT_OBJECT_0
operator|)
return|;
block|}
end_function
begin_function
DECL|function|wakeUp
name|void
name|QMutexPrivate
operator|::
name|wakeUp
parameter_list|()
block|{
name|SetEvent
argument_list|(
name|event
argument_list|)
expr_stmt|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
