begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** No Commercial Usage ** This file contains pre-release code and may not be distributed. ** You may use this file in accordance with the terms and conditions ** contained in the Technology Preview License Agreement accompanying ** this package. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights.  These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** If you have questions regarding the use of this file, please contact ** Nokia at qt-info@nokia.com. ** ** ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QMUTEX_H
end_ifndef
begin_define
DECL|macro|QMUTEX_H
define|#
directive|define
name|QMUTEX_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qglobal.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qatomic.h>
end_include
begin_include
include|#
directive|include
file|<new>
end_include
begin_function
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
name|QT_MODULE
parameter_list|(
name|Core
parameter_list|)
ifndef|#
directive|ifndef
name|QT_NO_THREAD
name|class
name|QAtomicInt
decl_stmt|;
DECL|variable|QMutexData
name|class
name|QMutexData
decl_stmt|;
name|class
name|Q_CORE_EXPORT
name|QMutex
decl_stmt|{     friend class QWaitCondition;
end_function
begin_decl_stmt
name|friend
name|class
name|QWaitConditionPrivate
decl_stmt|;
end_decl_stmt
begin_label
name|public
label|:
end_label
begin_enum
enum|enum
name|RecursionMode
block|{
name|NonRecursive
block|,
name|Recursive
block|}
enum|;
end_enum
begin_function_decl
name|explicit
name|QMutex
parameter_list|(
name|RecursionMode
name|mode
init|=
name|NonRecursive
parameter_list|)
function_decl|;
end_function_decl
begin_expr_stmt
operator|~
name|QMutex
argument_list|()
expr_stmt|;
end_expr_stmt
begin_function_decl
name|void
name|lock
parameter_list|()
function_decl|;
end_function_decl
begin_comment
comment|//### Qt5: make inline;
end_comment
begin_function_decl
specifier|inline
name|void
name|lockInline
parameter_list|()
function_decl|;
end_function_decl
begin_function_decl
name|bool
name|tryLock
parameter_list|()
function_decl|;
end_function_decl
begin_comment
comment|//### Qt5: make inline;
end_comment
begin_function_decl
name|bool
name|tryLock
parameter_list|(
name|int
name|timeout
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
specifier|inline
name|bool
name|tryLockInline
parameter_list|()
function_decl|;
end_function_decl
begin_function_decl
name|void
name|unlock
parameter_list|()
function_decl|;
end_function_decl
begin_comment
comment|//### Qt5: make inline;
end_comment
begin_function_decl
specifier|inline
name|void
name|unlockInline
parameter_list|()
function_decl|;
end_function_decl
begin_if
if|#
directive|if
name|defined
argument_list|(
name|QT3_SUPPORT
argument_list|)
end_if
begin_function
specifier|inline
name|QT3_SUPPORT
name|bool
name|locked
parameter_list|()
block|{
if|if
condition|(
operator|!
name|tryLock
argument_list|()
condition|)
return|return
name|true
return|;
name|unlock
argument_list|()
expr_stmt|;
return|return
name|false
return|;
block|}
end_function
begin_function
specifier|inline
name|QT3_SUPPORT_CONSTRUCTOR
name|QMutex
parameter_list|(
name|bool
name|recursive
parameter_list|)
block|{
name|new
argument_list|(
argument|this
argument_list|)
name|QMutex
argument_list|(
name|recursive
condition|?
name|Recursive
else|:
name|NonRecursive
argument_list|)
expr_stmt|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_label
name|private
label|:
end_label
begin_function_decl
name|void
name|lockInternal
parameter_list|()
function_decl|;
end_function_decl
begin_function_decl
name|void
name|unlockInternal
parameter_list|()
function_decl|;
end_function_decl
begin_macro
name|Q_DISABLE_COPY
argument_list|(
argument|QMutex
argument_list|)
end_macro
begin_decl_stmt
name|QMutexData
modifier|*
name|d
decl_stmt|;
end_decl_stmt
begin_decl_stmt
unit|};
name|class
name|Q_CORE_EXPORT
name|QMutexLocker
block|{
name|public
label|:
specifier|inline
name|explicit
name|QMutexLocker
parameter_list|(
name|QMutex
modifier|*
name|m
parameter_list|)
block|{
name|Q_ASSERT_X
argument_list|(
operator|(
name|reinterpret_cast
operator|<
name|quintptr
operator|>
operator|(
name|m
operator|)
operator|&
name|quintptr
argument_list|(
literal|1u
argument_list|)
operator|)
operator|==
name|quintptr
argument_list|(
literal|0
argument_list|)
argument_list|,
literal|"QMutexLocker"
argument_list|,
literal|"QMutex pointer is misaligned"
argument_list|)
expr_stmt|;
if|if
condition|(
name|m
condition|)
block|{
name|m
operator|->
name|lockInline
argument_list|()
expr_stmt|;
name|val
operator|=
name|reinterpret_cast
operator|<
name|quintptr
operator|>
operator|(
name|m
operator|)
operator||
name|quintptr
argument_list|(
literal|1u
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|val
operator|=
literal|0
expr_stmt|;
block|}
block|}
specifier|inline
operator|~
name|QMutexLocker
argument_list|()
block|{
name|unlock
argument_list|()
block|; }
specifier|inline
name|void
name|unlock
argument_list|()
block|{
if|if
condition|(
operator|(
name|val
operator|&
name|quintptr
argument_list|(
literal|1u
argument_list|)
operator|)
operator|==
name|quintptr
argument_list|(
literal|1u
argument_list|)
condition|)
block|{
name|val
operator|&=
operator|~
name|quintptr
argument_list|(
literal|1u
argument_list|)
expr_stmt|;
name|mutex
argument_list|()
operator|->
name|unlockInline
argument_list|()
expr_stmt|;
block|}
block|}
specifier|inline
name|void
name|relock
argument_list|()
block|{
if|if
condition|(
name|val
condition|)
block|{
if|if
condition|(
operator|(
name|val
operator|&
name|quintptr
argument_list|(
literal|1u
argument_list|)
operator|)
operator|==
name|quintptr
argument_list|(
literal|0u
argument_list|)
condition|)
block|{
name|mutex
argument_list|()
operator|->
name|lockInline
argument_list|()
expr_stmt|;
name|val
operator||=
name|quintptr
argument_list|(
literal|1u
argument_list|)
expr_stmt|;
block|}
block|}
block|}
if|#
directive|if
name|defined
argument_list|(
name|Q_CC_MSVC
argument_list|)
pragma|#
directive|pragma
name|warning
name|(
name|push
name|)
pragma|#
directive|pragma
name|warning
name|(
name|disable
name|:
name|4312
name|)
comment|// ignoring the warning from /Wp64
endif|#
directive|endif
specifier|inline
name|QMutex
operator|*
name|mutex
argument_list|()
specifier|const
block|{
return|return
name|reinterpret_cast
operator|<
name|QMutex
operator|*
operator|>
operator|(
name|val
operator|&
operator|~
name|quintptr
argument_list|(
literal|1u
argument_list|)
operator|)
return|;
block|}
if|#
directive|if
name|defined
argument_list|(
name|Q_CC_MSVC
argument_list|)
pragma|#
directive|pragma
name|warning
name|(
name|pop
name|)
endif|#
directive|endif
name|private
label|:
name|Q_DISABLE_COPY
argument_list|(
argument|QMutexLocker
argument_list|)
name|quintptr
name|val
decl_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_decl_stmt
name|class
name|QMutexData
block|{
name|public
label|:
name|QAtomicInt
name|contenders
decl_stmt|;
specifier|const
name|uint
name|recursive
range|:
literal|1
decl_stmt|;
name|uint
name|reserved
range|:
literal|31
decl_stmt|;
name|protected
label|:
name|QMutexData
argument_list|(
argument|QMutex::RecursionMode mode
argument_list|)
empty_stmt|;
operator|~
name|QMutexData
argument_list|()
expr_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_ifdef
ifdef|#
directive|ifdef
name|QT_NO_DEBUG
end_ifdef
begin_expr_stmt
DECL|function|unlockInline
specifier|inline
name|void
name|QMutex
operator|::
name|unlockInline
argument_list|()
block|{
if|if
condition|(
name|d
operator|->
name|recursive
condition|)
block|{
name|unlock
argument_list|()
expr_stmt|;
block|}
end_expr_stmt
begin_elseif
elseif|else
if|if
condition|(
operator|!
name|d
operator|->
name|contenders
operator|.
name|testAndSetRelease
argument_list|(
literal|1
argument_list|,
literal|0
argument_list|)
condition|)
block|{
name|unlockInternal
argument_list|()
expr_stmt|;
block|}
end_elseif
begin_expr_stmt
unit|}  inline
DECL|function|tryLockInline
name|bool
name|QMutex
operator|::
name|tryLockInline
argument_list|()
block|{
if|if
condition|(
name|d
operator|->
name|recursive
condition|)
block|{
return|return
name|tryLock
argument_list|()
return|;
block|}
end_expr_stmt
begin_else
else|else
block|{
return|return
name|d
operator|->
name|contenders
operator|.
name|testAndSetAcquire
argument_list|(
literal|0
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_else
begin_expr_stmt
unit|}  inline
DECL|function|lockInline
name|void
name|QMutex
operator|::
name|lockInline
argument_list|()
block|{
if|if
condition|(
name|d
operator|->
name|recursive
condition|)
block|{
name|lock
argument_list|()
expr_stmt|;
block|}
end_expr_stmt
begin_elseif
elseif|else
if|if
condition|(
operator|!
name|tryLockInline
argument_list|()
condition|)
block|{
name|lockInternal
argument_list|()
expr_stmt|;
block|}
end_elseif
begin_else
unit|}
else|#
directive|else
end_else
begin_comment
comment|// QT_NO_DEBUG
end_comment
begin_comment
comment|//in debug we do not use inline calls in order to allow debugging tools
end_comment
begin_comment
comment|// to hook the mutex locking functions.
end_comment
begin_expr_stmt
unit|inline
DECL|function|unlockInline
name|void
name|QMutex
operator|::
name|unlockInline
argument_list|()
block|{
name|unlock
argument_list|()
block|; }
DECL|function|tryLockInline
specifier|inline
name|bool
name|QMutex
operator|::
name|tryLockInline
argument_list|()
block|{
return|return
name|tryLock
argument_list|()
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|lockInline
specifier|inline
name|void
name|QMutex
operator|::
name|lockInline
argument_list|()
block|{
name|lock
argument_list|()
block|; }
endif|#
directive|endif
comment|// QT_NO_DEBUG
else|#
directive|else
comment|// QT_NO_THREAD
name|class
name|Q_CORE_EXPORT
name|QMutex
block|{
name|public
operator|:
expr|enum
name|RecursionMode
block|{
name|NonRecursive
block|,
name|Recursive
block|}
block|;
specifier|inline
name|explicit
name|QMutex
argument_list|(
argument|RecursionMode mode = NonRecursive
argument_list|)
block|{
name|Q_UNUSED
argument_list|(
name|mode
argument_list|)
block|; }
specifier|inline
operator|~
name|QMutex
argument_list|()
block|{}
specifier|static
specifier|inline
name|void
name|lock
argument_list|()
block|{}
specifier|static
specifier|inline
name|void
name|lockInline
argument_list|()
block|{}
specifier|static
specifier|inline
name|bool
name|tryLock
argument_list|(
argument|int timeout =
literal|0
argument_list|)
block|{
name|Q_UNUSED
argument_list|(
name|timeout
argument_list|)
block|;
return|return
name|true
return|;
block|}
specifier|static
specifier|inline
name|bool
name|tryLockInline
argument_list|()
block|{
return|return
name|true
return|;
block|}
end_expr_stmt
begin_function
specifier|static
specifier|inline
name|void
name|unlock
parameter_list|()
block|{}
end_function
begin_function
specifier|static
specifier|inline
name|void
name|unlockInline
parameter_list|()
block|{}
end_function
begin_if
if|#
directive|if
name|defined
argument_list|(
name|QT3_SUPPORT
argument_list|)
end_if
begin_function
specifier|static
specifier|inline
name|QT3_SUPPORT
name|bool
name|locked
parameter_list|()
block|{
return|return
name|false
return|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_label
name|private
label|:
end_label
begin_macro
name|Q_DISABLE_COPY
argument_list|(
argument|QMutex
argument_list|)
end_macro
begin_decl_stmt
unit|};
name|class
name|Q_CORE_EXPORT
name|QMutexLocker
block|{
name|public
label|:
specifier|inline
name|explicit
name|QMutexLocker
parameter_list|(
name|QMutex
modifier|*
parameter_list|)
block|{}
specifier|inline
operator|~
name|QMutexLocker
argument_list|()
block|{}
specifier|static
specifier|inline
name|void
name|unlock
argument_list|()
block|{}
specifier|static
name|void
name|relock
argument_list|()
block|{}
specifier|static
specifier|inline
name|QMutex
operator|*
name|mutex
argument_list|()
block|{
return|return
literal|0
return|;
block|}
name|private
label|:
name|Q_DISABLE_COPY
argument_list|(
argument|QMutexLocker
argument_list|)
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
begin_expr_stmt
name|QT_END_NAMESPACE
name|QT_END_HEADER
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QMUTEX_H
end_comment
end_unit
