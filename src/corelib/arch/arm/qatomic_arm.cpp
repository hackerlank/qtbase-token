begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** No Commercial Usage ** This file contains pre-release code and may not be distributed. ** You may use this file in accordance with the terms and conditions ** contained in the Technology Preview License Agreement accompanying ** this package. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights.  These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** If you have questions regarding the use of this file, please contact ** Nokia at qt-info@nokia.com. ** ** ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtCore/qglobal.h>
end_include
begin_include
include|#
directive|include
file|<unistd.h>
end_include
begin_ifdef
ifdef|#
directive|ifdef
name|_POSIX_PRIORITY_SCHEDULING
end_ifdef
begin_include
include|#
directive|include
file|<sched.h>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_include
include|#
directive|include
file|<time.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
name|QT_USE_NAMESPACE
DECL|variable|q_atomic_lock
name|Q_CORE_EXPORT
name|char
name|q_atomic_lock
init|=
literal|0
decl_stmt|;
end_decl_stmt
begin_function
DECL|function|qt_atomic_yield
name|Q_CORE_EXPORT
name|void
name|qt_atomic_yield
parameter_list|(
name|int
modifier|*
name|count
parameter_list|)
block|{
ifdef|#
directive|ifdef
name|_POSIX_PRIORITY_SCHEDULING
if|if
condition|(
operator|(
operator|*
name|count
operator|)
operator|++
operator|<
literal|50
condition|)
block|{
name|sched_yield
argument_list|()
expr_stmt|;
block|}
else|else
endif|#
directive|endif
block|{
name|struct
name|timespec
name|tm
decl_stmt|;
name|tm
operator|.
name|tv_sec
operator|=
literal|0
expr_stmt|;
name|tm
operator|.
name|tv_nsec
operator|=
literal|2000001
expr_stmt|;
name|nanosleep
argument_list|(
operator|&
name|tm
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
operator|*
name|count
operator|=
literal|0
expr_stmt|;
block|}
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
