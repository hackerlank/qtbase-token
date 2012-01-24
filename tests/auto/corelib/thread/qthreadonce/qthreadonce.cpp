begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qplatformdefs.h"
end_include
begin_include
include|#
directive|include
file|"qthreadonce.h"
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_THREAD
end_ifndef
begin_include
include|#
directive|include
file|"qmutex.h"
end_include
begin_expr_stmt
name|Q_GLOBAL_STATIC_WITH_ARGS
argument_list|(
name|QMutex
argument_list|,
name|onceInitializationMutex
argument_list|,
operator|(
name|QMutex
operator|::
name|Recursive
operator|)
argument_list|)
expr|enum
DECL|enum|QOnceExtra
name|QOnceExtra
block|{
DECL|enumerator|MustRunCode
name|MustRunCode
operator|=
literal|0x01
block|,
DECL|enumerator|MustUnlockMutex
name|MustUnlockMutex
operator|=
literal|0x02
block|}
expr_stmt|;
end_expr_stmt
begin_comment
comment|/*!     \internal     Initialize the Q_ONCE structure.      Q_ONCE consists of two variables:      - a static POD QOnceControl::ControlVariable (it's a QBasicAtomicInt)      - an automatic QOnceControl that controls the former      The POD is initialized to 0.      When QOnceControl's constructor starts, it'll lock the global     initialization mutex. It'll then check if it's the first to up     the control variable and will take note.      The QOnceControl's destructor will unlock the global     initialization mutex. */
end_comment
begin_constructor
DECL|function|QOnceControl
name|QOnceControl
operator|::
name|QOnceControl
parameter_list|(
name|QBasicAtomicInt
modifier|*
name|control
parameter_list|)
block|{
name|d
operator|=
literal|0
expr_stmt|;
name|gv
operator|=
name|control
expr_stmt|;
comment|// check if code has already run once
if|if
condition|(
name|gv
operator|->
name|loadAcquire
argument_list|()
operator|==
literal|2
condition|)
block|{
comment|// uncontended case: it has already initialized
comment|// no waiting
return|return;
block|}
comment|// acquire the path
name|onceInitializationMutex
argument_list|()
operator|->
name|lock
argument_list|()
expr_stmt|;
name|extra
operator|=
name|MustUnlockMutex
expr_stmt|;
if|if
condition|(
name|gv
operator|->
name|testAndSetAcquire
argument_list|(
literal|0
argument_list|,
literal|1
argument_list|)
condition|)
block|{
comment|// path acquired, we're the first
name|extra
operator||=
name|MustRunCode
expr_stmt|;
block|}
block|}
end_constructor
begin_destructor
DECL|function|~QOnceControl
name|QOnceControl
operator|::
name|~
name|QOnceControl
parameter_list|()
block|{
if|if
condition|(
name|mustRunCode
argument_list|()
condition|)
comment|// code wasn't run!
name|gv
operator|->
name|testAndSetRelease
argument_list|(
literal|1
argument_list|,
literal|0
argument_list|)
expr_stmt|;
else|else
name|gv
operator|->
name|testAndSetRelease
argument_list|(
literal|1
argument_list|,
literal|2
argument_list|)
expr_stmt|;
if|if
condition|(
name|extra
operator|&
name|MustUnlockMutex
condition|)
name|onceInitializationMutex
argument_list|()
operator|->
name|unlock
argument_list|()
expr_stmt|;
block|}
end_destructor
begin_comment
comment|/*!     \internal     Returns true if the initialization code must be run.      Obviously, the initialization code must be run only once... */
end_comment
begin_function
DECL|function|mustRunCode
name|bool
name|QOnceControl
operator|::
name|mustRunCode
parameter_list|()
block|{
return|return
name|extra
operator|&
name|MustRunCode
return|;
block|}
end_function
begin_function
DECL|function|done
name|void
name|QOnceControl
operator|::
name|done
parameter_list|()
block|{
name|extra
operator|&=
operator|~
name|MustRunCode
expr_stmt|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_THREAD
end_comment
end_unit
