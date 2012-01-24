begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QATOMIC_SH4A_H
end_ifndef
begin_define
DECL|macro|QATOMIC_SH4A_H
define|#
directive|define
name|QATOMIC_SH4A_H
end_define
begin_expr_stmt
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
name|QT_END_NAMESPACE
name|QT_END_HEADER
DECL|macro|Q_ATOMIC_INT_REFERENCE_COUNTING_IS_ALWAYS_NATIVE
define|#
directive|define
name|Q_ATOMIC_INT_REFERENCE_COUNTING_IS_ALWAYS_NATIVE
DECL|function|isReferenceCountingNative
specifier|inline
name|bool
name|QBasicAtomicInt
operator|::
name|isReferenceCountingNative
argument_list|()
block|{
return|return
name|true
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
DECL|macro|Q_ATOMIC_INT_TEST_AND_SET_IS_ALWAYS_NATIVE
define|#
directive|define
name|Q_ATOMIC_INT_TEST_AND_SET_IS_ALWAYS_NATIVE
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
name|true
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
DECL|macro|Q_ATOMIC_INT_FETCH_AND_STORE_IS_ALWAYS_NATIVE
define|#
directive|define
name|Q_ATOMIC_INT_FETCH_AND_STORE_IS_ALWAYS_NATIVE
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
name|true
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
DECL|macro|Q_ATOMIC_INT_FETCH_AND_ADD_IS_ALWAYS_NATIVE
define|#
directive|define
name|Q_ATOMIC_INT_FETCH_AND_ADD_IS_ALWAYS_NATIVE
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
name|true
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
DECL|macro|Q_ATOMIC_POINTER_TEST_AND_SET_IS_ALWAYS_NATIVE
define|#
directive|define
name|Q_ATOMIC_POINTER_TEST_AND_SET_IS_ALWAYS_NATIVE
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
name|true
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
DECL|macro|Q_ATOMIC_POINTER_FETCH_AND_STORE_IS_ALWAYS_NATIVE
define|#
directive|define
name|Q_ATOMIC_POINTER_FETCH_AND_STORE_IS_ALWAYS_NATIVE
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
name|true
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
DECL|macro|Q_ATOMIC_POINTER_FETCH_AND_ADD_IS_ALWAYS_NATIVE
define|#
directive|define
name|Q_ATOMIC_POINTER_FETCH_AND_ADD_IS_ALWAYS_NATIVE
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
name|true
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
begin_expr_stmt
name|QT_BEGIN_NAMESPACE
if|#
directive|if
operator|!
name|defined
argument_list|(
name|Q_CC_GNU
argument_list|)
error|#
directive|error
literal|"SH-4A support has not been added for this compiler"
else|#
directive|else
specifier|inline
name|bool
name|QBasicAtomicInt
operator|::
name|ref
argument_list|()
block|{
specifier|register
name|int
name|newValue
asm|asm("r0");
end_expr_stmt
begin_asm
asm|asm
specifier|volatile
asm|("0:\n"                  "movli.l @%[_q_value], %[newValue]\n"                  "add #1,%[newValue]\n"                  "movco.l %[newValue], @%[_q_value]\n"                  "bf 0b\n"                  : [newValue] "=&r" (newValue),                    "+m" (_q_value)                  : [_q_value] "r" (&_q_value)                  : "cc", "memory");
end_asm
begin_return
return|return
name|newValue
operator|!=
literal|0
return|;
end_return
begin_expr_stmt
unit|}  inline
name|bool
name|QBasicAtomicInt
operator|::
name|deref
argument_list|()
block|{
specifier|register
name|int
name|newValue
asm|asm("r0");
end_expr_stmt
begin_asm
asm|asm
specifier|volatile
asm|("0:\n"                  "movli.l @%[_q_value], %[newValue]\n"                  "add #-1,%[newValue]\n"                  "movco.l %[newValue], @%[_q_value]\n"                  "bf 0b\n"                  : [newValue] "=&r" (newValue),                    "+m" (_q_value)                  : [_q_value] "r" (&_q_value)                  : "cc", "memory");
end_asm
begin_return
return|return
name|newValue
operator|!=
literal|0
return|;
end_return
begin_expr_stmt
unit|}  inline
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
specifier|register
name|int
name|result
block|;
name|asm
specifier|volatile
operator|(
literal|"0:\n"
literal|"movli.l @%[_q_value], r0\n"
literal|"xor %[expectedValue], r0\n"
literal|"cmp/eq #0, r0\n"
literal|"bf/s 0f\n"
literal|"mov r0, %[result]\n"
literal|"mov %[newValue], r0\n"
literal|"movco.l r0, @%[_q_value]\n"
literal|"bf 0b\n"
literal|"0:\n"
operator|:
index|[
name|result
index|]
literal|"=&r"
operator|(
name|result
operator|)
operator|,
literal|"+m"
operator|(
name|_q_value
operator|)
operator|:
index|[
name|_q_value
index|]
literal|"r"
operator|(
operator|&
name|_q_value
operator|)
operator|,
index|[
name|expectedValue
index|]
literal|"r"
operator|(
name|expectedValue
operator|)
operator|,
index|[
name|newValue
index|]
literal|"r"
operator|(
name|newValue
operator|)
operator|:
literal|"r0"
operator|,
literal|"cc"
operator|,
literal|"memory"
operator|)
block|;
return|return
name|result
operator|==
literal|0
return|;
block|}
end_expr_stmt
begin_expr_stmt
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
specifier|register
name|int
name|result
block|;
name|asm
specifier|volatile
operator|(
literal|"0:\n"
literal|"movli.l @%[_q_value], r0\n"
literal|"xor %[expectedValue], r0\n"
literal|"cmp/eq #0, r0\n"
literal|"bf/s 0f\n"
literal|"mov r0, %[result]\n"
literal|"mov %[newValue], r0\n"
literal|"movco.l r0, @%[_q_value]\n"
literal|"bf 0b\n"
literal|"synco\n"
literal|"0:\n"
operator|:
index|[
name|result
index|]
literal|"=&r"
operator|(
name|result
operator|)
operator|,
literal|"+m"
operator|(
name|_q_value
operator|)
operator|:
index|[
name|_q_value
index|]
literal|"r"
operator|(
operator|&
name|_q_value
operator|)
operator|,
index|[
name|expectedValue
index|]
literal|"r"
operator|(
name|expectedValue
operator|)
operator|,
index|[
name|newValue
index|]
literal|"r"
operator|(
name|newValue
operator|)
operator|:
literal|"r0"
operator|,
literal|"cc"
operator|,
literal|"memory"
operator|)
block|;
return|return
name|result
operator|==
literal|0
return|;
block|}
end_expr_stmt
begin_expr_stmt
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
specifier|register
name|int
name|result
block|;
name|asm
specifier|volatile
operator|(
literal|"synco\n"
literal|"0:\n"
literal|"movli.l @%[_q_value], r0\n"
literal|"xor %[expectedValue], r0\n"
literal|"cmp/eq #0, r0\n"
literal|"bf/s 0f\n"
literal|"mov r0, %[result]\n"
literal|"mov %[newValue], r0\n"
literal|"movco.l r0, @%[_q_value]\n"
literal|"bf 0b\n"
literal|"0:\n"
operator|:
index|[
name|result
index|]
literal|"=&r"
operator|(
name|result
operator|)
operator|,
literal|"+m"
operator|(
name|_q_value
operator|)
operator|:
index|[
name|_q_value
index|]
literal|"r"
operator|(
operator|&
name|_q_value
operator|)
operator|,
index|[
name|expectedValue
index|]
literal|"r"
operator|(
name|expectedValue
operator|)
operator|,
index|[
name|newValue
index|]
literal|"r"
operator|(
name|newValue
operator|)
operator|:
literal|"r0"
operator|,
literal|"cc"
operator|,
literal|"memory"
operator|)
block|;
return|return
name|result
operator|==
literal|0
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
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
return|return
name|testAndSetAcquire
argument_list|(
name|expectedValue
argument_list|,
name|newValue
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
name|int
name|QBasicAtomicInt
operator|::
name|fetchAndStoreRelaxed
argument_list|(
argument|int newValue
argument_list|)
block|{
specifier|register
name|int
name|originalValue
block|;
name|asm
specifier|volatile
operator|(
literal|"0:\n"
literal|"movli.l @%[_q_value], r0\n"
literal|"mov r0, %[originalValue]\n"
literal|"mov %[newValue], r0\n"
literal|"movco.l r0, @%[_q_value]\n"
literal|"bf 0b\n"
operator|:
index|[
name|originalValue
index|]
literal|"=&r"
operator|(
name|originalValue
operator|)
operator|,
literal|"+m"
operator|(
name|_q_value
operator|)
operator|:
index|[
name|_q_value
index|]
literal|"r"
operator|(
operator|&
name|_q_value
operator|)
operator|,
index|[
name|newValue
index|]
literal|"r"
operator|(
name|newValue
operator|)
operator|:
literal|"r0"
operator|,
literal|"cc"
operator|,
literal|"memory"
operator|)
block|;
return|return
name|originalValue
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
name|int
name|QBasicAtomicInt
operator|::
name|fetchAndStoreAcquire
argument_list|(
argument|int newValue
argument_list|)
block|{
specifier|register
name|int
name|originalValue
block|;
name|asm
specifier|volatile
operator|(
literal|"0:\n"
literal|"movli.l @%[_q_value], r0\n"
literal|"mov r0, %[originalValue]\n"
literal|"mov %[newValue], r0\n"
literal|"movco.l r0, @%[_q_value]\n"
literal|"bf 0b\n"
literal|"synco\n"
operator|:
index|[
name|originalValue
index|]
literal|"=&r"
operator|(
name|originalValue
operator|)
operator|,
literal|"+m"
operator|(
name|_q_value
operator|)
operator|:
index|[
name|_q_value
index|]
literal|"r"
operator|(
operator|&
name|_q_value
operator|)
operator|,
index|[
name|newValue
index|]
literal|"r"
operator|(
name|newValue
operator|)
operator|:
literal|"r0"
operator|,
literal|"cc"
operator|,
literal|"memory"
operator|)
block|;
return|return
name|originalValue
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
name|int
name|QBasicAtomicInt
operator|::
name|fetchAndStoreRelease
argument_list|(
argument|int newValue
argument_list|)
block|{
specifier|register
name|int
name|originalValue
block|;
name|asm
specifier|volatile
operator|(
literal|"synco\n"
literal|"0:\n"
literal|"movli.l @%[_q_value], r0\n"
literal|"mov r0, %[originalValue]\n"
literal|"mov %[newValue], r0\n"
literal|"movco.l r0, @%[_q_value]\n"
literal|"bf 0b\n"
operator|:
index|[
name|originalValue
index|]
literal|"=&r"
operator|(
name|originalValue
operator|)
operator|,
literal|"+m"
operator|(
name|_q_value
operator|)
operator|:
index|[
name|_q_value
index|]
literal|"r"
operator|(
operator|&
name|_q_value
operator|)
operator|,
index|[
name|newValue
index|]
literal|"r"
operator|(
name|newValue
operator|)
operator|:
literal|"r0"
operator|,
literal|"cc"
operator|,
literal|"memory"
operator|)
block|;
return|return
name|originalValue
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
name|int
name|QBasicAtomicInt
operator|::
name|fetchAndStoreOrdered
argument_list|(
argument|int newValue
argument_list|)
block|{
return|return
name|fetchAndStoreAcquire
argument_list|(
name|newValue
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
name|int
name|QBasicAtomicInt
operator|::
name|fetchAndAddRelaxed
argument_list|(
argument|int valueToAdd
argument_list|)
block|{
specifier|register
name|int
name|originalValue
block|;
name|asm
specifier|volatile
operator|(
literal|"0:\n"
literal|"movli.l @%[_q_value], r0\n"
literal|"mov r0, %[originalValue]\n"
literal|"add %[valueToAdd], r0\n"
literal|"movco.l r0, @%[_q_value]\n"
literal|"bf 0b\n"
operator|:
index|[
name|originalValue
index|]
literal|"=&r"
operator|(
name|originalValue
operator|)
operator|,
literal|"+m"
operator|(
name|_q_value
operator|)
operator|:
index|[
name|_q_value
index|]
literal|"r"
operator|(
operator|&
name|_q_value
operator|)
operator|,
index|[
name|valueToAdd
index|]
literal|"r"
operator|(
name|valueToAdd
operator|)
operator|:
literal|"r0"
operator|,
literal|"cc"
operator|,
literal|"memory"
operator|)
block|;
return|return
name|originalValue
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
name|int
name|QBasicAtomicInt
operator|::
name|fetchAndAddAcquire
argument_list|(
argument|int valueToAdd
argument_list|)
block|{
specifier|register
name|int
name|originalValue
block|;
name|asm
specifier|volatile
operator|(
literal|"0:\n"
literal|"movli.l @%[_q_value], r0\n"
literal|"mov r0, %[originalValue]\n"
literal|"add %[valueToAdd], r0\n"
literal|"movco.l r0, @%[_q_value]\n"
literal|"bf 0b\n"
literal|"synco\n"
operator|:
index|[
name|originalValue
index|]
literal|"=&r"
operator|(
name|originalValue
operator|)
operator|,
literal|"+m"
operator|(
name|_q_value
operator|)
operator|:
index|[
name|_q_value
index|]
literal|"r"
operator|(
operator|&
name|_q_value
operator|)
operator|,
index|[
name|valueToAdd
index|]
literal|"r"
operator|(
name|valueToAdd
operator|)
operator|:
literal|"r0"
operator|,
literal|"cc"
operator|,
literal|"memory"
operator|)
block|;
return|return
name|originalValue
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
name|int
name|QBasicAtomicInt
operator|::
name|fetchAndAddRelease
argument_list|(
argument|int valueToAdd
argument_list|)
block|{
specifier|register
name|int
name|originalValue
block|;
name|asm
specifier|volatile
operator|(
literal|"synco\n"
literal|"0:\n"
literal|"movli.l @%[_q_value], r0\n"
literal|"mov r0, %[originalValue]\n"
literal|"add %[valueToAdd], r0\n"
literal|"movco.l r0, @%[_q_value]\n"
literal|"bf 0b\n"
operator|:
index|[
name|originalValue
index|]
literal|"=&r"
operator|(
name|originalValue
operator|)
operator|,
literal|"+m"
operator|(
name|_q_value
operator|)
operator|:
index|[
name|_q_value
index|]
literal|"r"
operator|(
operator|&
name|_q_value
operator|)
operator|,
index|[
name|valueToAdd
index|]
literal|"r"
operator|(
name|valueToAdd
operator|)
operator|:
literal|"r0"
operator|,
literal|"cc"
operator|,
literal|"memory"
operator|)
block|;
return|return
name|originalValue
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
name|int
name|QBasicAtomicInt
operator|::
name|fetchAndAddOrdered
argument_list|(
argument|int valueToAdd
argument_list|)
block|{
return|return
name|fetchAndAddAcquire
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
specifier|register
name|T
operator|*
name|result
block|;
name|asm
specifier|volatile
operator|(
literal|"0:\n"
literal|"movli.l @%[_q_value], r0\n"
literal|"xor %[expectedValue], r0\n"
literal|"cmp/eq #0, r0\n"
literal|"bf/s 0f\n"
literal|"mov r0, %[result]\n"
literal|"mov %[newValue], r0\n"
literal|"movco.l r0, @%[_q_value]\n"
literal|"bf 0b\n"
literal|"0:\n"
operator|:
index|[
name|result
index|]
literal|"=&r"
operator|(
name|result
operator|)
operator|,
literal|"+m"
operator|(
name|_q_value
operator|)
operator|:
index|[
name|_q_value
index|]
literal|"r"
operator|(
operator|&
name|_q_value
operator|)
operator|,
index|[
name|expectedValue
index|]
literal|"r"
operator|(
name|expectedValue
operator|)
operator|,
index|[
name|newValue
index|]
literal|"r"
operator|(
name|newValue
operator|)
operator|:
literal|"r0"
operator|,
literal|"cc"
operator|,
literal|"memory"
operator|)
block|;
return|return
name|result
operator|==
literal|0
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
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
specifier|register
name|T
operator|*
name|result
block|;
name|asm
specifier|volatile
operator|(
literal|"0:\n"
literal|"movli.l @%[_q_value], r0\n"
literal|"xor %[expectedValue], r0\n"
literal|"cmp/eq #0, r0\n"
literal|"bf/s 0f\n"
literal|"mov r0, %[result]\n"
literal|"mov %[newValue], r0\n"
literal|"movco.l r0, @%[_q_value]\n"
literal|"bf 0b\n"
literal|"synco\n"
literal|"0:\n"
operator|:
index|[
name|result
index|]
literal|"=&r"
operator|(
name|result
operator|)
operator|,
literal|"+m"
operator|(
name|_q_value
operator|)
operator|:
index|[
name|_q_value
index|]
literal|"r"
operator|(
operator|&
name|_q_value
operator|)
operator|,
index|[
name|expectedValue
index|]
literal|"r"
operator|(
name|expectedValue
operator|)
operator|,
index|[
name|newValue
index|]
literal|"r"
operator|(
name|newValue
operator|)
operator|:
literal|"r0"
operator|,
literal|"cc"
operator|,
literal|"memory"
operator|)
block|;
return|return
name|result
operator|==
literal|0
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
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
specifier|register
name|T
operator|*
name|result
block|;
name|asm
specifier|volatile
operator|(
literal|"synco\n"
literal|"0:\n"
literal|"movli.l @%[_q_value], r0\n"
literal|"xor %[expectedValue], r0\n"
literal|"cmp/eq #0, r0\n"
literal|"bf/s 0f\n"
literal|"mov r0, %[result]\n"
literal|"mov %[newValue], r0\n"
literal|"movco.l r0, @%[_q_value]\n"
literal|"bf 0b\n"
literal|"0:\n"
operator|:
index|[
name|result
index|]
literal|"=&r"
operator|(
name|result
operator|)
operator|,
literal|"+m"
operator|(
name|_q_value
operator|)
operator|:
index|[
name|_q_value
index|]
literal|"r"
operator|(
operator|&
name|_q_value
operator|)
operator|,
index|[
name|expectedValue
index|]
literal|"r"
operator|(
name|expectedValue
operator|)
operator|,
index|[
name|newValue
index|]
literal|"r"
operator|(
name|newValue
operator|)
operator|:
literal|"r0"
operator|,
literal|"cc"
operator|,
literal|"memory"
operator|)
block|;
return|return
name|result
operator|==
literal|0
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
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
return|return
name|testAndSetAcquire
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
specifier|register
name|T
operator|*
name|originalValue
block|;
name|asm
specifier|volatile
operator|(
literal|"0:\n"
literal|"movli.l @%[_q_value], r0\n"
literal|"mov r0, %[originalValue]\n"
literal|"mov %[newValue], r0\n"
literal|"movco.l r0, @%[_q_value]\n"
literal|"bf 0b\n"
operator|:
index|[
name|originalValue
index|]
literal|"=&r"
operator|(
name|originalValue
operator|)
operator|,
literal|"+m"
operator|(
name|_q_value
operator|)
operator|:
index|[
name|_q_value
index|]
literal|"r"
operator|(
operator|&
name|_q_value
operator|)
operator|,
index|[
name|newValue
index|]
literal|"r"
operator|(
name|newValue
operator|)
operator|:
literal|"r0"
operator|,
literal|"cc"
operator|,
literal|"memory"
operator|)
block|;
return|return
name|originalValue
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
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
specifier|register
name|T
operator|*
name|originalValue
block|;
name|asm
specifier|volatile
operator|(
literal|"0:\n"
literal|"movli.l @%[_q_value], r0\n"
literal|"mov r0, %[originalValue]\n"
literal|"mov %[newValue], r0\n"
literal|"movco.l r0, @%[_q_value]\n"
literal|"bf 0b\n"
literal|"synco\n"
operator|:
index|[
name|originalValue
index|]
literal|"=&r"
operator|(
name|originalValue
operator|)
operator|,
literal|"+m"
operator|(
name|_q_value
operator|)
operator|:
index|[
name|_q_value
index|]
literal|"r"
operator|(
operator|&
name|_q_value
operator|)
operator|,
index|[
name|newValue
index|]
literal|"r"
operator|(
name|newValue
operator|)
operator|:
literal|"r0"
operator|,
literal|"cc"
operator|,
literal|"memory"
operator|)
block|;
return|return
name|originalValue
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
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
specifier|register
name|T
operator|*
name|originalValue
block|;
name|asm
specifier|volatile
operator|(
literal|"synco\n"
literal|"0:\n"
literal|"movli.l @%[_q_value], r0\n"
literal|"mov r0, %[originalValue]\n"
literal|"mov %[newValue], r0\n"
literal|"movco.l r0, @%[_q_value]\n"
literal|"bf 0b\n"
operator|:
index|[
name|originalValue
index|]
literal|"=&r"
operator|(
name|originalValue
operator|)
operator|,
literal|"+m"
operator|(
name|_q_value
operator|)
operator|:
index|[
name|_q_value
index|]
literal|"r"
operator|(
operator|&
name|_q_value
operator|)
operator|,
index|[
name|newValue
index|]
literal|"r"
operator|(
name|newValue
operator|)
operator|:
literal|"r0"
operator|,
literal|"cc"
operator|,
literal|"memory"
operator|)
block|;
return|return
name|originalValue
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
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
return|return
name|fetchAndStoreAcquire
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
specifier|register
name|T
operator|*
name|originalValue
block|;
name|asm
specifier|volatile
operator|(
literal|"0:\n"
literal|"movli.l @%[_q_value], r0\n"
literal|"mov r0, %[originalValue]\n"
literal|"add %[valueToAdd], r0\n"
literal|"movco.l r0, @%[_q_value]\n"
literal|"bf 0b\n"
operator|:
index|[
name|originalValue
index|]
literal|"=&r"
operator|(
name|originalValue
operator|)
operator|,
literal|"+m"
operator|(
name|_q_value
operator|)
operator|:
index|[
name|_q_value
index|]
literal|"r"
operator|(
operator|&
name|_q_value
operator|)
operator|,
index|[
name|valueToAdd
index|]
literal|"r"
operator|(
name|valueToAdd
operator|*
sizeof|sizeof
argument_list|(
name|T
argument_list|)
operator|)
operator|:
literal|"r0"
operator|,
literal|"cc"
operator|,
literal|"memory"
operator|)
block|;
return|return
name|originalValue
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
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
specifier|register
name|T
operator|*
name|originalValue
block|;
name|asm
specifier|volatile
operator|(
literal|"0:\n"
literal|"movli.l @%[_q_value], r0\n"
literal|"mov r0, %[originalValue]\n"
literal|"add %[valueToAdd], r0\n"
literal|"movco.l r0, @%[_q_value]\n"
literal|"bf 0b\n"
literal|"synco\n"
operator|:
index|[
name|originalValue
index|]
literal|"=&r"
operator|(
name|originalValue
operator|)
operator|,
literal|"+m"
operator|(
name|_q_value
operator|)
operator|:
index|[
name|_q_value
index|]
literal|"r"
operator|(
operator|&
name|_q_value
operator|)
operator|,
index|[
name|valueToAdd
index|]
literal|"r"
operator|(
name|valueToAdd
operator|*
sizeof|sizeof
argument_list|(
name|T
argument_list|)
operator|)
operator|:
literal|"r0"
operator|,
literal|"cc"
operator|,
literal|"memory"
operator|)
block|;
return|return
name|originalValue
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
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
specifier|register
name|T
operator|*
name|originalValue
block|;
name|asm
specifier|volatile
operator|(
literal|"synco\n"
literal|"0:\n"
literal|"movli.l @%[_q_value], r0\n"
literal|"mov r0, %[originalValue]\n"
literal|"add %[valueToAdd], r0\n"
literal|"movco.l r0, @%[_q_value]\n"
literal|"bf 0b\n"
operator|:
index|[
name|originalValue
index|]
literal|"=&r"
operator|(
name|originalValue
operator|)
operator|,
literal|"+m"
operator|(
name|_q_value
operator|)
operator|:
index|[
name|_q_value
index|]
literal|"r"
operator|(
operator|&
name|_q_value
operator|)
operator|,
index|[
name|valueToAdd
index|]
literal|"r"
operator|(
name|valueToAdd
operator|*
sizeof|sizeof
argument_list|(
name|T
argument_list|)
operator|)
operator|:
literal|"r0"
operator|,
literal|"cc"
operator|,
literal|"memory"
operator|)
block|;
return|return
name|originalValue
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
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
return|return
name|fetchAndAddAcquire
argument_list|(
name|valueToAdd
argument_list|)
return|;
block|}
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// Q_CC_GNU
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QATOMIC_SH4A_H
end_comment
end_unit
