begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** No Commercial Usage ** This file contains pre-release code and may not be distributed. ** You may use this file in accordance with the terms and conditions ** contained in the Technology Preview License Agreement accompanying ** this package. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights.  These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** If you have questions regarding the use of this file, please contact ** Nokia at qt-info@nokia.com. ** ** ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QATOMIC_SH_H
end_ifndef
begin_define
DECL|macro|QATOMIC_SH_H
define|#
directive|define
name|QATOMIC_SH_H
end_define
begin_expr_stmt
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
DECL|macro|Q_ATOMIC_INT_REFERENCE_COUNTING_IS_NOT_NATIVE
define|#
directive|define
name|Q_ATOMIC_INT_REFERENCE_COUNTING_IS_NOT_NATIVE
DECL|function|isReferenceCountingNative
specifier|inline
name|bool
name|QBasicAtomicInt
operator|::
name|isReferenceCountingNative
argument_list|()
block|{
return|return
name|false
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|isReferenceCountingWaitFree
specifier|inline
name|bool
name|QBasicAtomicInt
operator|::
name|isReferenceCountingWaitFree
argument_list|()
block|{
return|return
name|false
return|;
block|}
end_expr_stmt
begin_define
DECL|macro|Q_ATOMIC_INT_TEST_AND_SET_IS_NOT_NATIVE
define|#
directive|define
name|Q_ATOMIC_INT_TEST_AND_SET_IS_NOT_NATIVE
end_define
begin_expr_stmt
DECL|function|isTestAndSetNative
specifier|inline
name|bool
name|QBasicAtomicInt
operator|::
name|isTestAndSetNative
argument_list|()
block|{
return|return
name|false
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|isTestAndSetWaitFree
specifier|inline
name|bool
name|QBasicAtomicInt
operator|::
name|isTestAndSetWaitFree
argument_list|()
block|{
return|return
name|false
return|;
block|}
end_expr_stmt
begin_define
DECL|macro|Q_ATOMIC_INT_FETCH_AND_STORE_IS_NOT_NATIVE
define|#
directive|define
name|Q_ATOMIC_INT_FETCH_AND_STORE_IS_NOT_NATIVE
end_define
begin_expr_stmt
DECL|function|isFetchAndStoreNative
specifier|inline
name|bool
name|QBasicAtomicInt
operator|::
name|isFetchAndStoreNative
argument_list|()
block|{
return|return
name|false
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|isFetchAndStoreWaitFree
specifier|inline
name|bool
name|QBasicAtomicInt
operator|::
name|isFetchAndStoreWaitFree
argument_list|()
block|{
return|return
name|false
return|;
block|}
end_expr_stmt
begin_define
DECL|macro|Q_ATOMIC_INT_FETCH_AND_ADD_IS_NOT_NATIVE
define|#
directive|define
name|Q_ATOMIC_INT_FETCH_AND_ADD_IS_NOT_NATIVE
end_define
begin_expr_stmt
DECL|function|isFetchAndAddNative
specifier|inline
name|bool
name|QBasicAtomicInt
operator|::
name|isFetchAndAddNative
argument_list|()
block|{
return|return
name|false
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|isFetchAndAddWaitFree
specifier|inline
name|bool
name|QBasicAtomicInt
operator|::
name|isFetchAndAddWaitFree
argument_list|()
block|{
return|return
name|false
return|;
block|}
end_expr_stmt
begin_define
DECL|macro|Q_ATOMIC_POINTER_TEST_AND_SET_IS_NOT_NATIVE
define|#
directive|define
name|Q_ATOMIC_POINTER_TEST_AND_SET_IS_NOT_NATIVE
end_define
begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
DECL|function|isTestAndSetNative
name|Q_INLINE_TEMPLATE
name|bool
name|QBasicAtomicPointer
operator|<
name|T
operator|>
operator|::
name|isTestAndSetNative
argument_list|()
block|{
return|return
name|false
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
DECL|function|isTestAndSetWaitFree
name|Q_INLINE_TEMPLATE
name|bool
name|QBasicAtomicPointer
operator|<
name|T
operator|>
operator|::
name|isTestAndSetWaitFree
argument_list|()
block|{
return|return
name|false
return|;
block|}
end_expr_stmt
begin_define
DECL|macro|Q_ATOMIC_POINTER_FETCH_AND_STORE_IS_NOT_NATIVE
define|#
directive|define
name|Q_ATOMIC_POINTER_FETCH_AND_STORE_IS_NOT_NATIVE
end_define
begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
DECL|function|isFetchAndStoreNative
name|Q_INLINE_TEMPLATE
name|bool
name|QBasicAtomicPointer
operator|<
name|T
operator|>
operator|::
name|isFetchAndStoreNative
argument_list|()
block|{
return|return
name|false
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
DECL|function|isFetchAndStoreWaitFree
name|Q_INLINE_TEMPLATE
name|bool
name|QBasicAtomicPointer
operator|<
name|T
operator|>
operator|::
name|isFetchAndStoreWaitFree
argument_list|()
block|{
return|return
name|false
return|;
block|}
end_expr_stmt
begin_define
DECL|macro|Q_ATOMIC_POINTER_FETCH_AND_ADD_IS_NOT_NATIVE
define|#
directive|define
name|Q_ATOMIC_POINTER_FETCH_AND_ADD_IS_NOT_NATIVE
end_define
begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
DECL|function|isFetchAndAddNative
name|Q_INLINE_TEMPLATE
name|bool
name|QBasicAtomicPointer
operator|<
name|T
operator|>
operator|::
name|isFetchAndAddNative
argument_list|()
block|{
return|return
name|false
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
DECL|function|isFetchAndAddWaitFree
name|Q_INLINE_TEMPLATE
name|bool
name|QBasicAtomicPointer
operator|<
name|T
operator|>
operator|::
name|isFetchAndAddWaitFree
argument_list|()
block|{
return|return
name|false
return|;
block|}
end_expr_stmt
begin_decl_stmt
specifier|extern
name|Q_CORE_EXPORT
specifier|volatile
name|char
name|qt_atomic_lock
decl_stmt|;
end_decl_stmt
begin_function_decl
name|Q_CORE_EXPORT
name|void
name|qt_atomic_yield
parameter_list|(
name|int
modifier|*
name|count
parameter_list|)
function_decl|;
end_function_decl
begin_function
DECL|function|qt_atomic_tasb
specifier|inline
name|int
name|qt_atomic_tasb
parameter_list|(
specifier|volatile
name|char
modifier|*
name|ptr
parameter_list|)
block|{
specifier|register
name|int
name|ret
decl_stmt|;
asm|asm
specifier|volatile
asm|("tas.b @%2\n"                  "movt  %0"                  : "=&r"(ret), "=m"(*ptr)                  : "r"(ptr)                  : "cc", "memory");
return|return
name|ret
return|;
block|}
end_function
begin_comment
comment|// Reference counting
end_comment
begin_expr_stmt
DECL|function|ref
specifier|inline
name|bool
name|QBasicAtomicInt
operator|::
name|ref
argument_list|()
block|{
name|int
name|count
operator|=
literal|0
block|;
while|while
condition|(
name|qt_atomic_tasb
argument_list|(
operator|&
name|qt_atomic_lock
argument_list|)
operator|==
literal|0
condition|)
name|qt_atomic_yield
argument_list|(
operator|&
name|count
argument_list|)
expr_stmt|;
name|int
name|originalValue
operator|=
name|_q_value
operator|++
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|qt_atomic_lock
operator|=
literal|0
expr_stmt|;
end_expr_stmt
begin_return
return|return
name|originalValue
operator|!=
operator|-
literal|1
return|;
end_return
begin_expr_stmt
unit|}  inline
DECL|function|deref
name|bool
name|QBasicAtomicInt
operator|::
name|deref
argument_list|()
block|{
name|int
name|count
operator|=
literal|0
block|;
while|while
condition|(
name|qt_atomic_tasb
argument_list|(
operator|&
name|qt_atomic_lock
argument_list|)
operator|==
literal|0
condition|)
name|qt_atomic_yield
argument_list|(
operator|&
name|count
argument_list|)
expr_stmt|;
name|int
name|originalValue
operator|=
name|_q_value
operator|--
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|qt_atomic_lock
operator|=
literal|0
expr_stmt|;
end_expr_stmt
begin_return
return|return
name|originalValue
operator|!=
literal|1
return|;
end_return
begin_comment
unit|}
comment|// Test and set for integers
end_comment
begin_expr_stmt
unit|inline
DECL|function|testAndSetOrdered
name|bool
name|QBasicAtomicInt
operator|::
name|testAndSetOrdered
argument_list|(
argument|int expectedValue
argument_list|,
argument|int newValue
argument_list|)
block|{
name|bool
name|returnValue
operator|=
name|false
block|;
name|int
name|count
operator|=
literal|0
block|;
while|while
condition|(
name|qt_atomic_tasb
argument_list|(
operator|&
name|qt_atomic_lock
argument_list|)
operator|==
literal|0
condition|)
name|qt_atomic_yield
argument_list|(
operator|&
name|count
argument_list|)
expr_stmt|;
end_expr_stmt
begin_if
if|if
condition|(
name|_q_value
operator|==
name|expectedValue
condition|)
block|{
name|_q_value
operator|=
name|newValue
expr_stmt|;
name|returnValue
operator|=
name|true
expr_stmt|;
block|}
end_if
begin_expr_stmt
name|qt_atomic_lock
operator|=
literal|0
expr_stmt|;
end_expr_stmt
begin_return
return|return
name|returnValue
return|;
end_return
begin_expr_stmt
unit|}  inline
DECL|function|testAndSetRelaxed
name|bool
name|QBasicAtomicInt
operator|::
name|testAndSetRelaxed
argument_list|(
argument|int expectedValue
argument_list|,
argument|int newValue
argument_list|)
block|{
return|return
name|testAndSetOrdered
argument_list|(
name|expectedValue
argument_list|,
name|newValue
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|testAndSetAcquire
specifier|inline
name|bool
name|QBasicAtomicInt
operator|::
name|testAndSetAcquire
argument_list|(
argument|int expectedValue
argument_list|,
argument|int newValue
argument_list|)
block|{
return|return
name|testAndSetOrdered
argument_list|(
name|expectedValue
argument_list|,
name|newValue
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|testAndSetRelease
specifier|inline
name|bool
name|QBasicAtomicInt
operator|::
name|testAndSetRelease
argument_list|(
argument|int expectedValue
argument_list|,
argument|int newValue
argument_list|)
block|{
return|return
name|testAndSetOrdered
argument_list|(
name|expectedValue
argument_list|,
name|newValue
argument_list|)
return|;
block|}
end_expr_stmt
begin_comment
comment|// Fetch and store for integers
end_comment
begin_expr_stmt
DECL|function|fetchAndStoreOrdered
specifier|inline
name|int
name|QBasicAtomicInt
operator|::
name|fetchAndStoreOrdered
argument_list|(
argument|int newValue
argument_list|)
block|{
name|int
name|count
operator|=
literal|0
block|;
while|while
condition|(
name|qt_atomic_tasb
argument_list|(
operator|&
name|qt_atomic_lock
argument_list|)
operator|==
literal|0
condition|)
name|qt_atomic_yield
argument_list|(
operator|&
name|count
argument_list|)
expr_stmt|;
name|int
name|originalValue
operator|=
name|_q_value
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|_q_value
operator|=
name|newValue
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|qt_atomic_lock
operator|=
literal|0
expr_stmt|;
end_expr_stmt
begin_return
return|return
name|originalValue
return|;
end_return
begin_expr_stmt
unit|}  inline
DECL|function|fetchAndStoreRelaxed
name|int
name|QBasicAtomicInt
operator|::
name|fetchAndStoreRelaxed
argument_list|(
argument|int newValue
argument_list|)
block|{
return|return
name|fetchAndStoreOrdered
argument_list|(
name|newValue
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|fetchAndStoreAcquire
specifier|inline
name|int
name|QBasicAtomicInt
operator|::
name|fetchAndStoreAcquire
argument_list|(
argument|int newValue
argument_list|)
block|{
return|return
name|fetchAndStoreOrdered
argument_list|(
name|newValue
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|fetchAndStoreRelease
specifier|inline
name|int
name|QBasicAtomicInt
operator|::
name|fetchAndStoreRelease
argument_list|(
argument|int newValue
argument_list|)
block|{
return|return
name|fetchAndStoreOrdered
argument_list|(
name|newValue
argument_list|)
return|;
block|}
end_expr_stmt
begin_comment
comment|// Fetch and add for integers
end_comment
begin_expr_stmt
DECL|function|fetchAndAddOrdered
specifier|inline
name|int
name|QBasicAtomicInt
operator|::
name|fetchAndAddOrdered
argument_list|(
argument|int valueToAdd
argument_list|)
block|{
name|int
name|count
operator|=
literal|0
block|;
while|while
condition|(
name|qt_atomic_tasb
argument_list|(
operator|&
name|qt_atomic_lock
argument_list|)
operator|==
literal|0
condition|)
name|qt_atomic_yield
argument_list|(
operator|&
name|count
argument_list|)
expr_stmt|;
name|int
name|originalValue
operator|=
name|_q_value
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|_q_value
operator|+=
name|valueToAdd
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|qt_atomic_lock
operator|=
literal|0
expr_stmt|;
end_expr_stmt
begin_return
return|return
name|originalValue
return|;
end_return
begin_expr_stmt
unit|}  inline
DECL|function|fetchAndAddRelaxed
name|int
name|QBasicAtomicInt
operator|::
name|fetchAndAddRelaxed
argument_list|(
argument|int valueToAdd
argument_list|)
block|{
return|return
name|fetchAndAddOrdered
argument_list|(
name|valueToAdd
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|fetchAndAddAcquire
specifier|inline
name|int
name|QBasicAtomicInt
operator|::
name|fetchAndAddAcquire
argument_list|(
argument|int valueToAdd
argument_list|)
block|{
return|return
name|fetchAndAddOrdered
argument_list|(
name|valueToAdd
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|fetchAndAddRelease
specifier|inline
name|int
name|QBasicAtomicInt
operator|::
name|fetchAndAddRelease
argument_list|(
argument|int valueToAdd
argument_list|)
block|{
return|return
name|fetchAndAddOrdered
argument_list|(
name|valueToAdd
argument_list|)
return|;
block|}
end_expr_stmt
begin_comment
comment|// Test and set for pointers
end_comment
begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
DECL|function|testAndSetOrdered
name|Q_INLINE_TEMPLATE
name|bool
name|QBasicAtomicPointer
operator|<
name|T
operator|>
operator|::
name|testAndSetOrdered
argument_list|(
argument|T *expectedValue
argument_list|,
argument|T *newValue
argument_list|)
block|{
name|bool
name|returnValue
operator|=
name|false
block|;
name|int
name|count
operator|=
literal|0
block|;
while|while
condition|(
name|qt_atomic_tasb
argument_list|(
operator|&
name|qt_atomic_lock
argument_list|)
operator|==
literal|0
condition|)
name|qt_atomic_yield
argument_list|(
operator|&
name|count
argument_list|)
expr_stmt|;
end_expr_stmt
begin_if
if|if
condition|(
name|_q_value
operator|==
name|expectedValue
condition|)
block|{
name|_q_value
operator|=
name|newValue
expr_stmt|;
name|returnValue
operator|=
name|true
expr_stmt|;
block|}
end_if
begin_expr_stmt
name|qt_atomic_lock
operator|=
literal|0
expr_stmt|;
end_expr_stmt
begin_return
return|return
name|returnValue
return|;
end_return
begin_expr_stmt
unit|}  template
operator|<
name|typename
name|T
operator|>
DECL|function|testAndSetRelaxed
name|Q_INLINE_TEMPLATE
name|bool
name|QBasicAtomicPointer
operator|<
name|T
operator|>
operator|::
name|testAndSetRelaxed
argument_list|(
argument|T *expectedValue
argument_list|,
argument|T *newValue
argument_list|)
block|{
return|return
name|testAndSetOrdered
argument_list|(
name|expectedValue
argument_list|,
name|newValue
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
DECL|function|testAndSetAcquire
name|Q_INLINE_TEMPLATE
name|bool
name|QBasicAtomicPointer
operator|<
name|T
operator|>
operator|::
name|testAndSetAcquire
argument_list|(
argument|T *expectedValue
argument_list|,
argument|T *newValue
argument_list|)
block|{
return|return
name|testAndSetOrdered
argument_list|(
name|expectedValue
argument_list|,
name|newValue
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
DECL|function|testAndSetRelease
name|Q_INLINE_TEMPLATE
name|bool
name|QBasicAtomicPointer
operator|<
name|T
operator|>
operator|::
name|testAndSetRelease
argument_list|(
argument|T *expectedValue
argument_list|,
argument|T *newValue
argument_list|)
block|{
return|return
name|testAndSetOrdered
argument_list|(
name|expectedValue
argument_list|,
name|newValue
argument_list|)
return|;
block|}
end_expr_stmt
begin_comment
comment|// Fetch and store for pointers
end_comment
begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
DECL|function|fetchAndStoreOrdered
name|Q_INLINE_TEMPLATE
name|T
operator|*
name|QBasicAtomicPointer
operator|<
name|T
operator|>
operator|::
name|fetchAndStoreOrdered
argument_list|(
argument|T *newValue
argument_list|)
block|{
name|int
name|count
operator|=
literal|0
block|;
while|while
condition|(
name|qt_atomic_tasb
argument_list|(
operator|&
name|qt_atomic_lock
argument_list|)
operator|==
literal|0
condition|)
name|qt_atomic_yield
argument_list|(
operator|&
name|count
argument_list|)
expr_stmt|;
name|T
operator|*
name|originalValue
operator|=
name|_q_value
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|_q_value
operator|=
name|newValue
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|qt_atomic_lock
operator|=
literal|0
expr_stmt|;
end_expr_stmt
begin_return
return|return
name|originalValue
return|;
end_return
begin_expr_stmt
unit|}  template
operator|<
name|typename
name|T
operator|>
DECL|function|fetchAndStoreRelaxed
name|Q_INLINE_TEMPLATE
name|T
operator|*
name|QBasicAtomicPointer
operator|<
name|T
operator|>
operator|::
name|fetchAndStoreRelaxed
argument_list|(
argument|T *newValue
argument_list|)
block|{
return|return
name|fetchAndStoreOrdered
argument_list|(
name|newValue
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
DECL|function|fetchAndStoreAcquire
name|Q_INLINE_TEMPLATE
name|T
operator|*
name|QBasicAtomicPointer
operator|<
name|T
operator|>
operator|::
name|fetchAndStoreAcquire
argument_list|(
argument|T *newValue
argument_list|)
block|{
return|return
name|fetchAndStoreOrdered
argument_list|(
name|newValue
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
DECL|function|fetchAndStoreRelease
name|Q_INLINE_TEMPLATE
name|T
operator|*
name|QBasicAtomicPointer
operator|<
name|T
operator|>
operator|::
name|fetchAndStoreRelease
argument_list|(
argument|T *newValue
argument_list|)
block|{
return|return
name|fetchAndStoreOrdered
argument_list|(
name|newValue
argument_list|)
return|;
block|}
end_expr_stmt
begin_comment
comment|// Fetch and add for pointers
end_comment
begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
DECL|function|fetchAndAddOrdered
name|Q_INLINE_TEMPLATE
name|T
operator|*
name|QBasicAtomicPointer
operator|<
name|T
operator|>
operator|::
name|fetchAndAddOrdered
argument_list|(
argument|qptrdiff valueToAdd
argument_list|)
block|{
name|int
name|count
operator|=
literal|0
block|;
while|while
condition|(
name|qt_atomic_tasb
argument_list|(
operator|&
name|qt_atomic_lock
argument_list|)
operator|==
literal|0
condition|)
name|qt_atomic_yield
argument_list|(
operator|&
name|count
argument_list|)
expr_stmt|;
name|T
operator|*
name|originalValue
operator|=
operator|(
name|_q_value
operator|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|_q_value
operator|+=
name|valueToAdd
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|qt_atomic_lock
operator|=
literal|0
expr_stmt|;
end_expr_stmt
begin_return
return|return
name|originalValue
return|;
end_return
begin_expr_stmt
unit|}  template
operator|<
name|typename
name|T
operator|>
DECL|function|fetchAndAddRelaxed
name|Q_INLINE_TEMPLATE
name|T
operator|*
name|QBasicAtomicPointer
operator|<
name|T
operator|>
operator|::
name|fetchAndAddRelaxed
argument_list|(
argument|qptrdiff valueToAdd
argument_list|)
block|{
return|return
name|fetchAndAddOrdered
argument_list|(
name|valueToAdd
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
DECL|function|fetchAndAddAcquire
name|Q_INLINE_TEMPLATE
name|T
operator|*
name|QBasicAtomicPointer
operator|<
name|T
operator|>
operator|::
name|fetchAndAddAcquire
argument_list|(
argument|qptrdiff valueToAdd
argument_list|)
block|{
return|return
name|fetchAndAddOrdered
argument_list|(
name|valueToAdd
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
DECL|function|fetchAndAddRelease
name|Q_INLINE_TEMPLATE
name|T
operator|*
name|QBasicAtomicPointer
operator|<
name|T
operator|>
operator|::
name|fetchAndAddRelease
argument_list|(
argument|qptrdiff valueToAdd
argument_list|)
block|{
return|return
name|fetchAndAddOrdered
argument_list|(
name|valueToAdd
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|QT_END_NAMESPACE
name|QT_END_HEADER
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QATOMIC_SH_H
end_comment
end_unit
