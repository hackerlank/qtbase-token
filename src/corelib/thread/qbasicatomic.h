begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Thiago Macieira<thiago@kde.org> ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QBASICATOMIC_H
end_ifndef
begin_define
DECL|macro|QBASICATOMIC_H
define|#
directive|define
name|QBASICATOMIC_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qglobal.h>
end_include
begin_define
DECL|macro|QT_OLD_ATOMICS
define|#
directive|define
name|QT_OLD_ATOMICS
end_define
begin_ifdef
ifdef|#
directive|ifdef
name|QT_OLD_ATOMICS
end_ifdef
begin_include
include|#
directive|include
file|"qoldbasicatomic.h"
end_include
begin_undef
DECL|macro|QT_OLD_ATOMICS
undef|#
directive|undef
name|QT_OLD_ATOMICS
end_undef
begin_else
else|#
directive|else
end_else
begin_decl_stmt
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
DECL|function|QT_MODULE
name|QT_MODULE
argument_list|(
name|Core
argument_list|)
if|#
directive|if
literal|0
pragma|#
directive|pragma
name|qt_no_master_include
pragma|#
directive|pragma
name|qt_sync_stop_processing
endif|#
directive|endif
comment|// New atomics
name|template
decl|<
name|typename
name|T
decl|>
name|class
name|QBasicAtomicInteger
block|{
name|public
label|:
typedef|typedef
name|QAtomicOps
operator|<
name|T
operator|>
name|Ops
expr_stmt|;
comment|// static check that this is a valid integer
typedef|typedef
name|char
name|PermittedIntegerType
index|[
name|QAtomicIntegerTraits
operator|<
name|T
operator|>
operator|::
name|IsInteger
condition|?
literal|1
else|:
operator|-
literal|1
index|]
typedef|;
name|typename
name|Ops
operator|::
name|Type
name|_q_value
expr_stmt|;
comment|// Non-atomic API
name|T
name|load
argument_list|()
specifier|const
block|{
return|return
name|Ops
operator|::
name|load
argument_list|(
name|_q_value
argument_list|)
return|;
block|}
name|void
name|store
parameter_list|(
name|T
name|newValue
parameter_list|)
block|{
name|Ops
operator|::
name|store
argument_list|(
name|_q_value
argument_list|,
name|newValue
argument_list|)
expr_stmt|;
block|}
comment|// Atomic API, implemented in qatomic_XXX.h
name|T
name|loadAcquire
parameter_list|()
block|{
return|return
name|Ops
operator|::
name|loadAcquire
argument_list|(
name|_q_value
argument_list|)
return|;
block|}
name|void
name|storeRelease
parameter_list|(
name|T
name|newValue
parameter_list|)
block|{
name|Ops
operator|::
name|storeRelease
argument_list|(
name|_q_value
argument_list|,
name|newValue
argument_list|)
expr_stmt|;
block|}
specifier|static
name|bool
name|isReferenceCountingNative
parameter_list|()
block|{
return|return
name|Ops
operator|::
name|isReferenceCountingNative
argument_list|()
return|;
block|}
specifier|static
name|bool
name|isReferenceCountingWaitFree
parameter_list|()
block|{
return|return
name|Ops
operator|::
name|isReferenceCountingWaitFree
argument_list|()
return|;
block|}
name|bool
name|ref
parameter_list|()
block|{
return|return
name|Ops
operator|::
name|ref
argument_list|(
name|_q_value
argument_list|)
return|;
block|}
name|bool
name|deref
parameter_list|()
block|{
return|return
name|Ops
operator|::
name|deref
argument_list|(
name|_q_value
argument_list|)
return|;
block|}
specifier|static
name|bool
name|isTestAndSetNative
parameter_list|()
block|{
return|return
name|Ops
operator|::
name|isTestAndSetNative
argument_list|()
return|;
block|}
specifier|static
name|bool
name|isTestAndSetWaitFree
parameter_list|()
block|{
return|return
name|Ops
operator|::
name|isTestAndSetWaitFree
argument_list|()
return|;
block|}
name|bool
name|testAndSetRelaxed
parameter_list|(
name|T
name|expectedValue
parameter_list|,
name|T
name|newValue
parameter_list|)
block|{
return|return
name|Ops
operator|::
name|testAndSetRelaxed
argument_list|(
name|_q_value
argument_list|,
name|expectedValue
argument_list|,
name|newValue
argument_list|)
return|;
block|}
name|bool
name|testAndSetAcquire
parameter_list|(
name|T
name|expectedValue
parameter_list|,
name|T
name|newValue
parameter_list|)
block|{
return|return
name|Ops
operator|::
name|testAndSetAcquire
argument_list|(
name|_q_value
argument_list|,
name|expectedValue
argument_list|,
name|newValue
argument_list|)
return|;
block|}
name|bool
name|testAndSetRelease
parameter_list|(
name|T
name|expectedValue
parameter_list|,
name|T
name|newValue
parameter_list|)
block|{
return|return
name|Ops
operator|::
name|testAndSetRelease
argument_list|(
name|_q_value
argument_list|,
name|expectedValue
argument_list|,
name|newValue
argument_list|)
return|;
block|}
name|bool
name|testAndSetOrdered
parameter_list|(
name|T
name|expectedValue
parameter_list|,
name|T
name|newValue
parameter_list|)
block|{
return|return
name|Ops
operator|::
name|testAndSetOrdered
argument_list|(
name|_q_value
argument_list|,
name|expectedValue
argument_list|,
name|newValue
argument_list|)
return|;
block|}
specifier|static
name|bool
name|isFetchAndStoreNative
parameter_list|()
block|{
return|return
name|Ops
operator|::
name|isFetchAndStoreNative
argument_list|()
return|;
block|}
specifier|static
name|bool
name|isFetchAndStoreWaitFree
parameter_list|()
block|{
return|return
name|Ops
operator|::
name|isFetchAndStoreWaitFree
argument_list|()
return|;
block|}
name|T
name|fetchAndStoreRelaxed
parameter_list|(
name|T
name|newValue
parameter_list|)
block|{
return|return
name|Ops
operator|::
name|fetchAndStoreRelaxed
argument_list|(
name|_q_value
argument_list|,
name|newValue
argument_list|)
return|;
block|}
name|T
name|fetchAndStoreAcquire
parameter_list|(
name|T
name|newValue
parameter_list|)
block|{
return|return
name|Ops
operator|::
name|fetchAndStoreAcquire
argument_list|(
name|_q_value
argument_list|,
name|newValue
argument_list|)
return|;
block|}
name|T
name|fetchAndStoreRelease
parameter_list|(
name|T
name|newValue
parameter_list|)
block|{
return|return
name|Ops
operator|::
name|fetchAndStoreRelease
argument_list|(
name|_q_value
argument_list|,
name|newValue
argument_list|)
return|;
block|}
name|T
name|fetchAndStoreOrdered
parameter_list|(
name|T
name|newValue
parameter_list|)
block|{
return|return
name|Ops
operator|::
name|fetchAndStoreOrdered
argument_list|(
name|_q_value
argument_list|,
name|newValue
argument_list|)
return|;
block|}
specifier|static
name|bool
name|isFetchAndAddNative
parameter_list|()
block|{
return|return
name|Ops
operator|::
name|isFetchAndAddNative
argument_list|()
return|;
block|}
specifier|static
name|bool
name|isFetchAndAddWaitFree
parameter_list|()
block|{
return|return
name|Ops
operator|::
name|isFetchAndAddWaitFree
argument_list|()
return|;
block|}
name|T
name|fetchAndAddRelaxed
parameter_list|(
name|T
name|valueToAdd
parameter_list|)
block|{
return|return
name|Ops
operator|::
name|fetchAndAddRelaxed
argument_list|(
name|_q_value
argument_list|,
name|valueToAdd
argument_list|)
return|;
block|}
name|T
name|fetchAndAddAcquire
parameter_list|(
name|T
name|valueToAdd
parameter_list|)
block|{
return|return
name|Ops
operator|::
name|fetchAndAddAcquire
argument_list|(
name|_q_value
argument_list|,
name|valueToAdd
argument_list|)
return|;
block|}
name|T
name|fetchAndAddRelease
parameter_list|(
name|T
name|valueToAdd
parameter_list|)
block|{
return|return
name|Ops
operator|::
name|fetchAndAddRelease
argument_list|(
name|_q_value
argument_list|,
name|valueToAdd
argument_list|)
return|;
block|}
name|T
name|fetchAndAddOrdered
parameter_list|(
name|T
name|valueToAdd
parameter_list|)
block|{
return|return
name|Ops
operator|::
name|fetchAndAddOrdered
argument_list|(
name|_q_value
argument_list|,
name|valueToAdd
argument_list|)
return|;
block|}
if|#
directive|if
name|defined
argument_list|(
name|Q_COMPILER_CONSTEXPR
argument_list|)
operator|&&
name|defined
argument_list|(
name|Q_COMPILER_DEFAULT_DELETE_MEMBERS
argument_list|)
name|QBasicAtomicInteger
argument_list|()
operator|=
expr|default
expr_stmt|;
name|constexpr
name|QBasicAtomicInteger
argument_list|(
argument|T value
argument_list|)
block|:
name|_q_value
argument_list|(
argument|value
argument_list|)
block|{}
name|QBasicAtomicInteger
argument_list|(
specifier|const
name|QBasicAtomicInteger
operator|&
argument_list|)
operator|=
name|delete
expr_stmt|;
name|QBasicAtomicInteger
modifier|&
name|operator
init|=
operator|(
specifier|const
name|QBasicAtomicInteger
operator|&
operator|)
operator|=
name|delete
decl_stmt|;
name|QBasicAtomicInteger
modifier|&
name|operator
init|=
operator|(
specifier|const
name|QBasicAtomicInteger
operator|&
operator|)
specifier|volatile
operator|=
name|delete
decl_stmt|;
endif|#
directive|endif
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_typedef
DECL|typedef|QBasicAtomicInt
typedef|typedef
name|QBasicAtomicInteger
operator|<
name|int
operator|>
name|QBasicAtomicInt
expr_stmt|;
end_typedef
begin_expr_stmt
name|template
operator|<
name|typename
name|X
operator|>
name|class
name|QBasicAtomicPointer
block|{
name|public
operator|:
typedef|typedef
name|X
modifier|*
name|Type
typedef|;
end_expr_stmt
begin_typedef
typedef|typedef
name|QAtomicOps
operator|<
name|Type
operator|>
name|Ops
expr_stmt|;
end_typedef
begin_typedef
typedef|typedef
name|typename
name|Ops
operator|::
name|Type
name|AtomicType
expr_stmt|;
end_typedef
begin_decl_stmt
name|AtomicType
name|_q_value
decl_stmt|;
end_decl_stmt
begin_comment
comment|// Non-atomic API
end_comment
begin_expr_stmt
name|Type
name|load
argument_list|()
specifier|const
block|{
return|return
name|_q_value
return|;
block|}
end_expr_stmt
begin_function
name|void
name|store
parameter_list|(
name|Type
name|newValue
parameter_list|)
block|{
name|_q_value
operator|=
name|newValue
expr_stmt|;
block|}
end_function
begin_comment
comment|// Atomic API, implemented in qatomic_XXX.h
end_comment
begin_function
name|Type
name|loadAcquire
parameter_list|()
block|{
return|return
name|Ops
operator|::
name|loadAcquire
argument_list|(
name|_q_value
argument_list|)
return|;
block|}
end_function
begin_function
name|void
name|storeRelease
parameter_list|(
name|Type
name|newValue
parameter_list|)
block|{
name|Ops
operator|::
name|storeRelease
argument_list|(
name|_q_value
argument_list|,
name|newValue
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
specifier|static
name|bool
name|isTestAndSetNative
parameter_list|()
block|{
return|return
name|Ops
operator|::
name|isTestAndSetNative
argument_list|()
return|;
block|}
end_function
begin_function
specifier|static
name|bool
name|isTestAndSetWaitFree
parameter_list|()
block|{
return|return
name|Ops
operator|::
name|isTestAndSetWaitFree
argument_list|()
return|;
block|}
end_function
begin_function
name|bool
name|testAndSetRelaxed
parameter_list|(
name|Type
name|expectedValue
parameter_list|,
name|Type
name|newValue
parameter_list|)
block|{
return|return
name|Ops
operator|::
name|testAndSetRelaxed
argument_list|(
name|_q_value
argument_list|,
name|expectedValue
argument_list|,
name|newValue
argument_list|)
return|;
block|}
end_function
begin_function
name|bool
name|testAndSetAcquire
parameter_list|(
name|Type
name|expectedValue
parameter_list|,
name|Type
name|newValue
parameter_list|)
block|{
return|return
name|Ops
operator|::
name|testAndSetAcquire
argument_list|(
name|_q_value
argument_list|,
name|expectedValue
argument_list|,
name|newValue
argument_list|)
return|;
block|}
end_function
begin_function
name|bool
name|testAndSetRelease
parameter_list|(
name|Type
name|expectedValue
parameter_list|,
name|Type
name|newValue
parameter_list|)
block|{
return|return
name|Ops
operator|::
name|testAndSetRelease
argument_list|(
name|_q_value
argument_list|,
name|expectedValue
argument_list|,
name|newValue
argument_list|)
return|;
block|}
end_function
begin_function
name|bool
name|testAndSetOrdered
parameter_list|(
name|Type
name|expectedValue
parameter_list|,
name|Type
name|newValue
parameter_list|)
block|{
return|return
name|Ops
operator|::
name|testAndSetOrdered
argument_list|(
name|_q_value
argument_list|,
name|expectedValue
argument_list|,
name|newValue
argument_list|)
return|;
block|}
end_function
begin_function
specifier|static
name|bool
name|isFetchAndStoreNative
parameter_list|()
block|{
return|return
name|Ops
operator|::
name|isFetchAndStoreNative
argument_list|()
return|;
block|}
end_function
begin_function
specifier|static
name|bool
name|isFetchAndStoreWaitFree
parameter_list|()
block|{
return|return
name|Ops
operator|::
name|isFetchAndStoreWaitFree
argument_list|()
return|;
block|}
end_function
begin_function
name|Type
name|fetchAndStoreRelaxed
parameter_list|(
name|Type
name|newValue
parameter_list|)
block|{
return|return
name|Ops
operator|::
name|fetchAndStoreRelaxed
argument_list|(
name|_q_value
argument_list|,
name|newValue
argument_list|)
return|;
block|}
end_function
begin_function
name|Type
name|fetchAndStoreAcquire
parameter_list|(
name|Type
name|newValue
parameter_list|)
block|{
return|return
name|Ops
operator|::
name|fetchAndStoreAcquire
argument_list|(
name|_q_value
argument_list|,
name|newValue
argument_list|)
return|;
block|}
end_function
begin_function
name|Type
name|fetchAndStoreRelease
parameter_list|(
name|Type
name|newValue
parameter_list|)
block|{
return|return
name|Ops
operator|::
name|fetchAndStoreRelease
argument_list|(
name|_q_value
argument_list|,
name|newValue
argument_list|)
return|;
block|}
end_function
begin_function
name|Type
name|fetchAndStoreOrdered
parameter_list|(
name|Type
name|newValue
parameter_list|)
block|{
return|return
name|Ops
operator|::
name|fetchAndStoreOrdered
argument_list|(
name|_q_value
argument_list|,
name|newValue
argument_list|)
return|;
block|}
end_function
begin_function
specifier|static
name|bool
name|isFetchAndAddNative
parameter_list|()
block|{
return|return
name|Ops
operator|::
name|isFetchAndAddNative
argument_list|()
return|;
block|}
end_function
begin_function
specifier|static
name|bool
name|isFetchAndAddWaitFree
parameter_list|()
block|{
return|return
name|Ops
operator|::
name|isFetchAndAddWaitFree
argument_list|()
return|;
block|}
end_function
begin_function
name|Type
name|fetchAndAddRelaxed
parameter_list|(
name|qptrdiff
name|valueToAdd
parameter_list|)
block|{
return|return
name|Ops
operator|::
name|fetchAndAddRelaxed
argument_list|(
name|_q_value
argument_list|,
name|valueToAdd
argument_list|)
return|;
block|}
end_function
begin_function
name|Type
name|fetchAndAddAcquire
parameter_list|(
name|qptrdiff
name|valueToAdd
parameter_list|)
block|{
return|return
name|Ops
operator|::
name|fetchAndAddAcquire
argument_list|(
name|_q_value
argument_list|,
name|valueToAdd
argument_list|)
return|;
block|}
end_function
begin_function
name|Type
name|fetchAndAddRelease
parameter_list|(
name|qptrdiff
name|valueToAdd
parameter_list|)
block|{
return|return
name|Ops
operator|::
name|fetchAndAddRelease
argument_list|(
name|_q_value
argument_list|,
name|valueToAdd
argument_list|)
return|;
block|}
end_function
begin_function
name|Type
name|fetchAndAddOrdered
parameter_list|(
name|qptrdiff
name|valueToAdd
parameter_list|)
block|{
return|return
name|Ops
operator|::
name|fetchAndAddOrdered
argument_list|(
name|_q_value
argument_list|,
name|valueToAdd
argument_list|)
return|;
block|}
end_function
begin_if
if|#
directive|if
name|defined
argument_list|(
name|Q_COMPILER_CONSTEXPR
argument_list|)
operator|&&
name|defined
argument_list|(
name|Q_COMPILER_DEFAULT_DELETE_MEMBERS
argument_list|)
end_if
begin_expr_stmt
name|QBasicAtomicPointer
argument_list|()
operator|=
expr|default
expr_stmt|;
end_expr_stmt
begin_macro
name|constexpr
end_macro
begin_macro
name|QBasicAtomicPointer
argument_list|(
argument|Type value
argument_list|)
end_macro
begin_macro
unit|:
name|_q_value
argument_list|(
argument|value
argument_list|)
end_macro
begin_block
block|{}
end_block
begin_expr_stmt
name|QBasicAtomicPointer
argument_list|(
specifier|const
name|QBasicAtomicPointer
operator|&
argument_list|)
operator|=
name|delete
expr_stmt|;
end_expr_stmt
begin_decl_stmt
name|QBasicAtomicPointer
modifier|&
name|operator
init|=
operator|(
specifier|const
name|QBasicAtomicPointer
operator|&
operator|)
operator|=
name|delete
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QBasicAtomicPointer
modifier|&
name|operator
init|=
operator|(
specifier|const
name|QBasicAtomicPointer
operator|&
operator|)
specifier|volatile
operator|=
name|delete
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
unit|};
ifndef|#
directive|ifndef
name|Q_BASIC_ATOMIC_INITIALIZER
end_ifndef
begin_define
DECL|macro|Q_BASIC_ATOMIC_INITIALIZER
define|#
directive|define
name|Q_BASIC_ATOMIC_INITIALIZER
parameter_list|(
name|a
parameter_list|)
value|{ (a) }
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_expr_stmt
name|QT_END_NAMESPACE
name|QT_END_HEADER
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_OLD_ATOMICS
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QBASIC_ATOMIC
end_comment
end_unit
