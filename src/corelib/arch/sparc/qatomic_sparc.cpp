begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtCore/qatomic.h>
end_include
begin_include
include|#
directive|include
file|<limits.h>
end_include
begin_include
include|#
directive|include
file|<sched.h>
end_include
begin_extern
extern|extern
literal|"C"
block|{
name|int
name|q_atomic_trylock_int
parameter_list|(
specifier|volatile
name|int
modifier|*
name|addr
parameter_list|)
function_decl|;
name|int
name|q_atomic_trylock_ptr
parameter_list|(
specifier|volatile
name|void
modifier|*
name|addr
parameter_list|)
function_decl|;
DECL|function|q_atomic_lock_int
name|Q_CORE_EXPORT
name|int
name|q_atomic_lock_int
parameter_list|(
specifier|volatile
name|int
modifier|*
name|addr
parameter_list|)
block|{
name|int
name|returnValue
init|=
name|q_atomic_trylock_int
argument_list|(
name|addr
argument_list|)
decl_stmt|;
if|if
condition|(
name|returnValue
operator|==
name|INT_MIN
condition|)
block|{
do|do
block|{
comment|// spin until we think we can succeed
do|do
block|{
name|sched_yield
argument_list|()
expr_stmt|;
name|returnValue
operator|=
operator|*
name|addr
expr_stmt|;
block|}
do|while
condition|(
name|returnValue
operator|==
name|INT_MIN
condition|)
do|;
comment|// try again
name|returnValue
operator|=
name|q_atomic_trylock_int
argument_list|(
name|addr
argument_list|)
expr_stmt|;
block|}
do|while
condition|(
name|returnValue
operator|==
name|INT_MIN
condition|)
do|;
block|}
return|return
name|returnValue
return|;
block|}
DECL|function|q_atomic_lock_ptr
name|Q_CORE_EXPORT
name|int
name|q_atomic_lock_ptr
parameter_list|(
specifier|volatile
name|void
modifier|*
name|addr
parameter_list|)
block|{
name|int
name|returnValue
init|=
name|q_atomic_trylock_ptr
argument_list|(
name|addr
argument_list|)
decl_stmt|;
if|if
condition|(
name|returnValue
operator|==
operator|-
literal|1
condition|)
block|{
do|do
block|{
comment|// spin until we think we can succeed
do|do
block|{
name|sched_yield
argument_list|()
expr_stmt|;
name|returnValue
operator|=
operator|*
cast|reinterpret_cast
argument_list|<
specifier|volatile
name|int
operator|*
argument_list|>
argument_list|(
name|addr
argument_list|)
expr_stmt|;
block|}
do|while
condition|(
name|returnValue
operator|==
operator|-
literal|1
condition|)
do|;
comment|// try again
name|returnValue
operator|=
name|q_atomic_trylock_ptr
argument_list|(
name|addr
argument_list|)
expr_stmt|;
block|}
do|while
condition|(
name|returnValue
operator|==
operator|-
literal|1
condition|)
do|;
block|}
return|return
name|returnValue
return|;
block|}
block|}
end_extern
begin_comment
comment|// extern "C"
end_comment
end_unit
