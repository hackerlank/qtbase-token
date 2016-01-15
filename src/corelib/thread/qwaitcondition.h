begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QWAITCONDITION_H
end_ifndef
begin_define
DECL|macro|QWAITCONDITION_H
define|#
directive|define
name|QWAITCONDITION_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qglobal.h>
end_include
begin_include
include|#
directive|include
file|<limits.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
ifndef|#
directive|ifndef
name|QT_NO_THREAD
DECL|variable|QWaitConditionPrivate
name|class
name|QWaitConditionPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QMutex
name|class
name|QMutex
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QReadWriteLock
name|class
name|QReadWriteLock
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_CORE_EXPORT
name|QWaitCondition
block|{
name|public
label|:
name|QWaitCondition
argument_list|()
expr_stmt|;
operator|~
name|QWaitCondition
argument_list|()
expr_stmt|;
name|bool
name|wait
parameter_list|(
name|QMutex
modifier|*
name|lockedMutex
parameter_list|,
name|unsigned
name|long
name|time
init|=
name|ULONG_MAX
parameter_list|)
function_decl|;
name|bool
name|wait
parameter_list|(
name|QReadWriteLock
modifier|*
name|lockedReadWriteLock
parameter_list|,
name|unsigned
name|long
name|time
init|=
name|ULONG_MAX
parameter_list|)
function_decl|;
name|void
name|wakeOne
parameter_list|()
function_decl|;
name|void
name|wakeAll
parameter_list|()
function_decl|;
name|private
label|:
name|Q_DISABLE_COPY
argument_list|(
argument|QWaitCondition
argument_list|)
name|QWaitConditionPrivate
modifier|*
name|d
decl_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_else
else|#
directive|else
end_else
begin_decl_stmt
name|class
name|QMutex
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_CORE_EXPORT
name|QWaitCondition
block|{
name|public
label|:
name|QWaitCondition
argument_list|()
block|{}
operator|~
name|QWaitCondition
argument_list|()
block|{}
name|bool
name|wait
argument_list|(
argument|QMutex *mutex
argument_list|,
argument|unsigned long time = ULONG_MAX
argument_list|)
block|{
name|Q_UNUSED
argument_list|(
name|mutex
argument_list|)
block|;
name|Q_UNUSED
argument_list|(
name|time
argument_list|)
block|;
return|return
name|true
return|;
block|}
name|void
name|wakeOne
parameter_list|()
block|{}
name|void
name|wakeAll
parameter_list|()
block|{}
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_THREAD
end_comment
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QWAITCONDITION_H
end_comment
end_unit
