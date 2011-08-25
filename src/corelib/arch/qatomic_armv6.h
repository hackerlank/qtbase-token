begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QATOMIC_ARMV6_H
end_ifndef
begin_define
DECL|macro|QATOMIC_ARMV6_H
define|#
directive|define
name|QATOMIC_ARMV6_H
end_define
begin_expr_stmt
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
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
begin_ifndef
ifndef|#
directive|ifndef
name|Q_CC_RVCT
end_ifndef
begin_ifndef
ifndef|#
directive|ifndef
name|Q_DATA_MEMORY_BARRIER
end_ifndef
begin_define
DECL|macro|Q_DATA_MEMORY_BARRIER
define|#
directive|define
name|Q_DATA_MEMORY_BARRIER
value|asm volatile("":::"memory")
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|Q_COMPILER_MEMORY_BARRIER
end_ifndef
begin_define
DECL|macro|Q_COMPILER_MEMORY_BARRIER
define|#
directive|define
name|Q_COMPILER_MEMORY_BARRIER
value|asm volatile("":::"memory")
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_expr_stmt
DECL|function|ref
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
block|;
specifier|register
name|int
name|result
block|;
name|asm
specifier|volatile
operator|(
literal|"0:\n"
literal|"ldrex %[newValue], [%[_q_value]]\n"
literal|"add %[newValue], %[newValue], #1\n"
literal|"strex %[result], %[newValue], [%[_q_value]]\n"
literal|"teq %[result], #0\n"
literal|"bne 0b\n"
operator|:
index|[
name|newValue
index|]
literal|"=&r"
operator|(
name|newValue
operator|)
operator|,
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
operator|:
literal|"cc"
operator|,
literal|"memory"
operator|)
block|;
return|return
name|newValue
operator|!=
literal|0
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|deref
specifier|inline
name|bool
name|QBasicAtomicInt
operator|::
name|deref
argument_list|()
block|{
specifier|register
name|int
name|newValue
block|;
specifier|register
name|int
name|result
block|;
name|asm
specifier|volatile
operator|(
literal|"0:\n"
literal|"ldrex %[newValue], [%[_q_value]]\n"
literal|"sub %[newValue], %[newValue], #1\n"
literal|"strex %[result], %[newValue], [%[_q_value]]\n"
literal|"teq %[result], #0\n"
literal|"bne 0b\n"
operator|:
index|[
name|newValue
index|]
literal|"=&r"
operator|(
name|newValue
operator|)
operator|,
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
operator|:
literal|"cc"
operator|,
literal|"memory"
operator|)
block|;
return|return
name|newValue
operator|!=
literal|0
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|testAndSetRelaxed
specifier|inline
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
literal|"ldrex %[result], [%[_q_value]]\n"
literal|"eors %[result], %[result], %[expectedValue]\n"
literal|"itt eq\n"
literal|"strexeq %[result], %[newValue], [%[_q_value]]\n"
literal|"teqeq %[result], #1\n"
literal|"beq 0b\n"
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
operator|,
index|[
name|_q_value
index|]
literal|"r"
operator|(
operator|&
name|_q_value
operator|)
operator|:
literal|"cc"
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
DECL|function|fetchAndStoreRelaxed
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
specifier|register
name|int
name|result
block|;
name|asm
specifier|volatile
operator|(
literal|"0:\n"
literal|"ldrex %[originalValue], [%[_q_value]]\n"
literal|"strex %[result], %[newValue], [%[_q_value]]\n"
literal|"teq %[result], #0\n"
literal|"bne 0b\n"
operator|:
index|[
name|originalValue
index|]
literal|"=&r"
operator|(
name|originalValue
operator|)
operator|,
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
name|newValue
index|]
literal|"r"
operator|(
name|newValue
operator|)
operator|,
index|[
name|_q_value
index|]
literal|"r"
operator|(
operator|&
name|_q_value
operator|)
operator|:
literal|"cc"
operator|)
block|;
return|return
name|originalValue
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|fetchAndAddRelaxed
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
specifier|register
name|int
name|newValue
block|;
specifier|register
name|int
name|result
block|;
name|asm
specifier|volatile
operator|(
literal|"0:\n"
literal|"ldrex %[originalValue], [%[_q_value]]\n"
literal|"add %[newValue], %[originalValue], %[valueToAdd]\n"
literal|"strex %[result], %[newValue], [%[_q_value]]\n"
literal|"teq %[result], #0\n"
literal|"bne 0b\n"
operator|:
index|[
name|originalValue
index|]
literal|"=&r"
operator|(
name|originalValue
operator|)
operator|,
index|[
name|newValue
index|]
literal|"=&r"
operator|(
name|newValue
operator|)
operator|,
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
name|valueToAdd
index|]
literal|"r"
operator|(
name|valueToAdd
operator|)
operator|,
index|[
name|_q_value
index|]
literal|"r"
operator|(
operator|&
name|_q_value
operator|)
operator|:
literal|"cc"
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
specifier|register
name|T
operator|*
name|result
block|;
name|asm
specifier|volatile
operator|(
literal|"0:\n"
literal|"ldrex %[result], [%[_q_value]]\n"
literal|"eors %[result], %[result], %[expectedValue]\n"
literal|"itt eq\n"
literal|"strexeq %[result], %[newValue], [%[_q_value]]\n"
literal|"teqeq %[result], #1\n"
literal|"beq 0b\n"
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
operator|,
index|[
name|_q_value
index|]
literal|"r"
operator|(
operator|&
name|_q_value
operator|)
operator|:
literal|"cc"
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
specifier|register
name|T
operator|*
name|originalValue
block|;
specifier|register
name|int
name|result
block|;
name|asm
specifier|volatile
operator|(
literal|"0:\n"
literal|"ldrex %[originalValue], [%[_q_value]]\n"
literal|"strex %[result], %[newValue], [%[_q_value]]\n"
literal|"teq %[result], #0\n"
literal|"bne 0b\n"
operator|:
index|[
name|originalValue
index|]
literal|"=&r"
operator|(
name|originalValue
operator|)
operator|,
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
name|newValue
index|]
literal|"r"
operator|(
name|newValue
operator|)
operator|,
index|[
name|_q_value
index|]
literal|"r"
operator|(
operator|&
name|_q_value
operator|)
operator|:
literal|"cc"
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
specifier|register
name|T
operator|*
name|originalValue
block|;
specifier|register
name|T
operator|*
name|newValue
block|;
specifier|register
name|int
name|result
block|;
name|asm
specifier|volatile
operator|(
literal|"0:\n"
literal|"ldrex %[originalValue], [%[_q_value]]\n"
literal|"add %[newValue], %[originalValue], %[valueToAdd]\n"
literal|"strex %[result], %[newValue], [%[_q_value]]\n"
literal|"teq %[result], #0\n"
literal|"bne 0b\n"
operator|:
index|[
name|originalValue
index|]
literal|"=&r"
operator|(
name|originalValue
operator|)
operator|,
index|[
name|newValue
index|]
literal|"=&r"
operator|(
name|newValue
operator|)
operator|,
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
operator|,
index|[
name|_q_value
index|]
literal|"r"
operator|(
operator|&
name|_q_value
operator|)
operator|:
literal|"cc"
operator|)
block|;
return|return
name|originalValue
return|;
block|}
end_expr_stmt
begin_else
else|#
directive|else
end_else
begin_comment
comment|// This is Q_CC_RVCT
end_comment
begin_comment
comment|// RVCT inline assembly documentation:
end_comment
begin_comment
comment|// http://www.keil.com/support/man/docs/armcc/armcc_chdcffdb.htm
end_comment
begin_comment
comment|// RVCT embedded assembly documentation:
end_comment
begin_comment
comment|// http://www.keil.com/support/man/docs/armcc/armcc_chddbeib.htm
end_comment
begin_if
if|#
directive|if
name|__TARGET_ARCH_THUMB
operator|-
literal|0
operator|<
literal|4
end_if
begin_comment
comment|// save our pragma state and switch to ARM mode (unless using Thumb2)
end_comment
begin_pragma
pragma|#
directive|pragma
name|push
end_pragma
begin_pragma
pragma|#
directive|pragma
name|arm
end_pragma
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|Q_DATA_MEMORY_BARRIER
end_ifndef
begin_define
DECL|macro|Q_DATA_MEMORY_BARRIER
define|#
directive|define
name|Q_DATA_MEMORY_BARRIER
value|__schedule_barrier()
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|Q_COMPILER_MEMORY_BARRIER
end_ifndef
begin_define
DECL|macro|Q_COMPILER_MEMORY_BARRIER
define|#
directive|define
name|Q_COMPILER_MEMORY_BARRIER
value|__schedule_barrier()
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_expr_stmt
DECL|function|ref
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
block|;
specifier|register
name|int
name|result
block|;
name|retry
operator|:
asm|__asm {
asm|ldrex   newValue, [&_q_value]
asm|add     newValue, newValue, #1
asm|strex   result, newValue, [&_q_value]
asm|teq     result, #0
asm|bne     retry
asm|}
return|return
name|newValue
operator|!=
literal|0
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|deref
specifier|inline
name|bool
name|QBasicAtomicInt
operator|::
name|deref
argument_list|()
block|{
specifier|register
name|int
name|newValue
block|;
specifier|register
name|int
name|result
block|;
name|retry
operator|:
asm|__asm {
asm|ldrex   newValue, [&_q_value]
asm|sub     newValue, newValue, #1
asm|strex   result, newValue, [&_q_value]
asm|teq     result, #0
asm|bne     retry
asm|}
return|return
name|newValue
operator|!=
literal|0
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|testAndSetRelaxed
specifier|inline
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
name|retry
operator|:
asm|__asm {
asm|ldrex   result, [&_q_value]
asm|eors    result, result, expectedValue
asm|strexeq result, newValue, [&_q_value]
asm|teqeq   result, #1
asm|beq     retry
asm|}
return|return
name|result
operator|==
literal|0
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|fetchAndStoreRelaxed
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
specifier|register
name|int
name|result
block|;
name|retry
operator|:
asm|__asm {
asm|ldrex   originalValue, [&_q_value]
asm|strex   result, newValue, [&_q_value]
asm|teq     result, #0
asm|bne     retry
asm|}
return|return
name|originalValue
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|fetchAndAddRelaxed
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
specifier|register
name|int
name|newValue
block|;
specifier|register
name|int
name|result
block|;
name|retry
operator|:
asm|__asm {
asm|ldrex   originalValue, [&_q_value]
asm|add     newValue, originalValue, valueToAdd
asm|strex   result, newValue, [&_q_value]
asm|teq     result, #0
asm|bne     retry
asm|}
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
specifier|register
name|T
operator|*
name|result
block|;
name|retry
operator|:
asm|__asm {
asm|ldrex   result, [&_q_value]
asm|eors    result, result, expectedValue
asm|strexeq result, newValue, [&_q_value]
asm|teqeq   result, #1
asm|beq     retry
asm|}
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
specifier|register
name|T
operator|*
name|originalValue
block|;
specifier|register
name|int
name|result
block|;
name|retry
operator|:
asm|__asm {
asm|ldrex   originalValue, [&_q_value]
asm|strex   result, newValue, [&_q_value]
asm|teq     result, #0
asm|bne     retry
asm|}
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
specifier|register
name|T
operator|*
name|originalValue
block|;
specifier|register
name|T
operator|*
name|newValue
block|;
specifier|register
name|int
name|result
block|;
name|retry
operator|:
asm|__asm {
asm|ldrex   originalValue, [&_q_value]
asm|add     newValue, originalValue, valueToAdd * sizeof(T)
asm|strex   result, newValue, [&_q_value]
asm|teq     result, #0
asm|bne     retry
asm|}
return|return
name|originalValue
return|;
block|}
end_expr_stmt
begin_if
if|#
directive|if
name|__TARGET_ARCH_THUMB
operator|-
literal|0
operator|<
literal|4
end_if
begin_pragma
pragma|#
directive|pragma
name|pop
end_pragma
begin_endif
endif|#
directive|endif
end_endif
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// common code
end_comment
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
name|bool
name|returnValue
operator|=
name|testAndSetRelaxed
argument_list|(
name|expectedValue
argument_list|,
name|newValue
argument_list|)
block|;
name|Q_DATA_MEMORY_BARRIER
block|;
return|return
name|returnValue
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
name|Q_DATA_MEMORY_BARRIER
block|;
return|return
name|testAndSetRelaxed
argument_list|(
name|expectedValue
argument_list|,
name|newValue
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|testAndSetOrdered
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
name|Q_DATA_MEMORY_BARRIER
block|;
name|bool
name|returnValue
operator|=
name|testAndSetRelaxed
argument_list|(
name|expectedValue
argument_list|,
name|newValue
argument_list|)
block|;
name|Q_COMPILER_MEMORY_BARRIER
block|;
return|return
name|returnValue
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
name|int
name|returnValue
operator|=
name|fetchAndStoreRelaxed
argument_list|(
name|newValue
argument_list|)
block|;
name|Q_DATA_MEMORY_BARRIER
block|;
return|return
name|returnValue
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
name|Q_DATA_MEMORY_BARRIER
block|;
return|return
name|fetchAndStoreRelaxed
argument_list|(
name|newValue
argument_list|)
return|;
block|}
end_expr_stmt
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
name|Q_DATA_MEMORY_BARRIER
block|;
name|int
name|returnValue
operator|=
name|fetchAndStoreRelaxed
argument_list|(
name|newValue
argument_list|)
block|;
name|Q_COMPILER_MEMORY_BARRIER
block|;
return|return
name|returnValue
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
name|int
name|returnValue
operator|=
name|fetchAndAddRelaxed
argument_list|(
name|valueToAdd
argument_list|)
block|;
name|Q_DATA_MEMORY_BARRIER
block|;
return|return
name|returnValue
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
name|Q_DATA_MEMORY_BARRIER
block|;
return|return
name|fetchAndAddRelaxed
argument_list|(
name|valueToAdd
argument_list|)
return|;
block|}
end_expr_stmt
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
name|Q_DATA_MEMORY_BARRIER
block|;
name|int
name|returnValue
operator|=
name|fetchAndAddRelaxed
argument_list|(
name|valueToAdd
argument_list|)
block|;
name|Q_COMPILER_MEMORY_BARRIER
block|;
return|return
name|returnValue
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
name|bool
name|returnValue
operator|=
name|testAndSetRelaxed
argument_list|(
name|expectedValue
argument_list|,
name|newValue
argument_list|)
block|;
name|Q_DATA_MEMORY_BARRIER
block|;
return|return
name|returnValue
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
name|Q_DATA_MEMORY_BARRIER
block|;
return|return
name|testAndSetRelaxed
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
name|Q_DATA_MEMORY_BARRIER
block|;
name|bool
name|returnValue
operator|=
name|testAndSetAcquire
argument_list|(
name|expectedValue
argument_list|,
name|newValue
argument_list|)
block|;
name|Q_COMPILER_MEMORY_BARRIER
block|;
return|return
name|returnValue
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
name|T
operator|*
name|returnValue
operator|=
name|fetchAndStoreRelaxed
argument_list|(
name|newValue
argument_list|)
block|;
name|Q_DATA_MEMORY_BARRIER
block|;
return|return
name|returnValue
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
name|Q_DATA_MEMORY_BARRIER
block|;
return|return
name|fetchAndStoreRelaxed
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
name|Q_DATA_MEMORY_BARRIER
block|;
name|T
operator|*
name|returnValue
operator|=
name|fetchAndStoreRelaxed
argument_list|(
name|newValue
argument_list|)
block|;
name|Q_COMPILER_MEMORY_BARRIER
block|;
return|return
name|returnValue
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
name|T
operator|*
name|returnValue
operator|=
name|fetchAndAddRelaxed
argument_list|(
name|valueToAdd
argument_list|)
block|;
name|Q_DATA_MEMORY_BARRIER
block|;
return|return
name|returnValue
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
name|Q_DATA_MEMORY_BARRIER
block|;
return|return
name|fetchAndAddRelaxed
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
name|Q_DATA_MEMORY_BARRIER
block|;
name|T
operator|*
name|returnValue
operator|=
name|fetchAndAddRelaxed
argument_list|(
name|valueToAdd
argument_list|)
block|;
name|Q_COMPILER_MEMORY_BARRIER
block|;
return|return
name|returnValue
return|;
block|}
end_expr_stmt
begin_undef
DECL|macro|Q_DATA_MEMORY_BARRIER
undef|#
directive|undef
name|Q_DATA_MEMORY_BARRIER
end_undef
begin_undef
DECL|macro|Q_COMPILER_MEMORY_BARRIER
undef|#
directive|undef
name|Q_COMPILER_MEMORY_BARRIER
end_undef
begin_expr_stmt
name|QT_END_NAMESPACE
name|QT_END_HEADER
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QATOMIC_ARMV6_H
end_comment
end_unit
