begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Copyright (C) 2011 Thiago Macieira<thiago@kde.org> ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QATOMIC_X86_64_H
end_ifndef
begin_define
DECL|macro|QATOMIC_X86_64_H
define|#
directive|define
name|QATOMIC_X86_64_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qgenericatomic.h>
end_include
begin_expr_stmt
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
if|#
directive|if
literal|0
pragma|#
directive|pragma
name|qt_sync_stop_processing
endif|#
directive|endif
DECL|macro|Q_ATOMIC_INT_REFERENCE_COUNTING_IS_ALWAYS_NATIVE
define|#
directive|define
name|Q_ATOMIC_INT_REFERENCE_COUNTING_IS_ALWAYS_NATIVE
DECL|macro|Q_ATOMIC_INT_REFERENCE_COUNTING_IS_WAIT_FREE
define|#
directive|define
name|Q_ATOMIC_INT_REFERENCE_COUNTING_IS_WAIT_FREE
DECL|macro|Q_ATOMIC_INT_TEST_AND_SET_IS_ALWAYS_NATIVE
define|#
directive|define
name|Q_ATOMIC_INT_TEST_AND_SET_IS_ALWAYS_NATIVE
DECL|macro|Q_ATOMIC_INT_TEST_AND_SET_IS_WAIT_FREE
define|#
directive|define
name|Q_ATOMIC_INT_TEST_AND_SET_IS_WAIT_FREE
DECL|macro|Q_ATOMIC_INT_FETCH_AND_STORE_IS_ALWAYS_NATIVE
define|#
directive|define
name|Q_ATOMIC_INT_FETCH_AND_STORE_IS_ALWAYS_NATIVE
DECL|macro|Q_ATOMIC_INT_FETCH_AND_STORE_IS_WAIT_FREE
define|#
directive|define
name|Q_ATOMIC_INT_FETCH_AND_STORE_IS_WAIT_FREE
DECL|macro|Q_ATOMIC_INT_FETCH_AND_ADD_IS_ALWAYS_NATIVE
define|#
directive|define
name|Q_ATOMIC_INT_FETCH_AND_ADD_IS_ALWAYS_NATIVE
DECL|macro|Q_ATOMIC_INT_FETCH_AND_ADD_IS_WAIT_FREE
define|#
directive|define
name|Q_ATOMIC_INT_FETCH_AND_ADD_IS_WAIT_FREE
DECL|macro|Q_ATOMIC_INT32_IS_SUPPORTED
define|#
directive|define
name|Q_ATOMIC_INT32_IS_SUPPORTED
DECL|macro|Q_ATOMIC_INT32_REFERENCE_COUNTING_IS_ALWAYS_NATIVE
define|#
directive|define
name|Q_ATOMIC_INT32_REFERENCE_COUNTING_IS_ALWAYS_NATIVE
DECL|macro|Q_ATOMIC_INT32_REFERENCE_COUNTING_IS_WAIT_FREE
define|#
directive|define
name|Q_ATOMIC_INT32_REFERENCE_COUNTING_IS_WAIT_FREE
DECL|macro|Q_ATOMIC_INT32_TEST_AND_SET_IS_ALWAYS_NATIVE
define|#
directive|define
name|Q_ATOMIC_INT32_TEST_AND_SET_IS_ALWAYS_NATIVE
DECL|macro|Q_ATOMIC_INT32_TEST_AND_SET_IS_WAIT_FREE
define|#
directive|define
name|Q_ATOMIC_INT32_TEST_AND_SET_IS_WAIT_FREE
DECL|macro|Q_ATOMIC_INT32_FETCH_AND_STORE_IS_ALWAYS_NATIVE
define|#
directive|define
name|Q_ATOMIC_INT32_FETCH_AND_STORE_IS_ALWAYS_NATIVE
DECL|macro|Q_ATOMIC_INT32_FETCH_AND_STORE_IS_WAIT_FREE
define|#
directive|define
name|Q_ATOMIC_INT32_FETCH_AND_STORE_IS_WAIT_FREE
DECL|macro|Q_ATOMIC_INT32_FETCH_AND_ADD_IS_ALWAYS_NATIVE
define|#
directive|define
name|Q_ATOMIC_INT32_FETCH_AND_ADD_IS_ALWAYS_NATIVE
DECL|macro|Q_ATOMIC_INT32_FETCH_AND_ADD_IS_WAIT_FREE
define|#
directive|define
name|Q_ATOMIC_INT32_FETCH_AND_ADD_IS_WAIT_FREE
DECL|macro|Q_ATOMIC_POINTER_TEST_AND_SET_IS_ALWAYS_NATIVE
define|#
directive|define
name|Q_ATOMIC_POINTER_TEST_AND_SET_IS_ALWAYS_NATIVE
DECL|macro|Q_ATOMIC_POINTER_TEST_AND_SET_IS_WAIT_FREE
define|#
directive|define
name|Q_ATOMIC_POINTER_TEST_AND_SET_IS_WAIT_FREE
DECL|macro|Q_ATOMIC_POINTER_FETCH_AND_STORE_IS_ALWAYS_NATIVE
define|#
directive|define
name|Q_ATOMIC_POINTER_FETCH_AND_STORE_IS_ALWAYS_NATIVE
DECL|macro|Q_ATOMIC_POINTER_FETCH_AND_STORE_IS_WAIT_FREE
define|#
directive|define
name|Q_ATOMIC_POINTER_FETCH_AND_STORE_IS_WAIT_FREE
DECL|macro|Q_ATOMIC_POINTER_FETCH_AND_ADD_IS_ALWAYS_NATIVE
define|#
directive|define
name|Q_ATOMIC_POINTER_FETCH_AND_ADD_IS_ALWAYS_NATIVE
DECL|macro|Q_ATOMIC_POINTER_FETCH_AND_ADD_IS_WAIT_FREE
define|#
directive|define
name|Q_ATOMIC_POINTER_FETCH_AND_ADD_IS_WAIT_FREE
name|template
operator|<
operator|>
expr|struct
name|QAtomicIntegerTraits
operator|<
name|int
operator|>
block|{ enum
block|{
name|IsInteger
operator|=
literal|1
block|}
block|; }
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|template
operator|<
operator|>
expr|struct
name|QAtomicIntegerTraits
operator|<
name|unsigned
name|int
operator|>
block|{ enum
block|{
name|IsInteger
operator|=
literal|1
block|}
block|; }
expr_stmt|;
end_expr_stmt
begin_expr_stmt
DECL|struct|size
name|template
operator|<
name|int
name|size
operator|>
expr|struct
name|QBasicAtomicOps
operator|:
name|QGenericAtomicOps
operator|<
name|QBasicAtomicOps
operator|<
name|size
operator|>
expr|>
block|{
DECL|function|isReferenceCountingNative
specifier|static
specifier|inline
name|bool
name|isReferenceCountingNative
argument_list|()
block|{
return|return
name|true
return|;
block|}
DECL|function|isReferenceCountingWaitFree
specifier|static
specifier|inline
name|bool
name|isReferenceCountingWaitFree
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
specifier|static
name|bool
name|ref
argument_list|(
name|T
operator|&
name|_q_value
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
specifier|static
name|bool
name|deref
argument_list|(
name|T
operator|&
name|_q_value
argument_list|)
expr_stmt|;
end_expr_stmt
begin_function
DECL|function|isTestAndSetNative
specifier|static
specifier|inline
name|bool
name|isTestAndSetNative
parameter_list|()
block|{
return|return
name|true
return|;
block|}
end_function
begin_function
DECL|function|isTestAndSetWaitFree
specifier|static
specifier|inline
name|bool
name|isTestAndSetWaitFree
parameter_list|()
block|{
return|return
name|true
return|;
block|}
end_function
begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
specifier|static
name|bool
name|testAndSetRelaxed
argument_list|(
argument|T&_q_value
argument_list|,
argument|T expectedValue
argument_list|,
argument|T newValue
argument_list|)
expr_stmt|;
end_expr_stmt
begin_function
DECL|function|isFetchAndStoreNative
specifier|static
specifier|inline
name|bool
name|isFetchAndStoreNative
parameter_list|()
block|{
return|return
name|true
return|;
block|}
end_function
begin_function
DECL|function|isFetchAndStoreWaitFree
specifier|static
specifier|inline
name|bool
name|isFetchAndStoreWaitFree
parameter_list|()
block|{
return|return
name|true
return|;
block|}
end_function
begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
specifier|static
name|T
name|fetchAndStoreRelaxed
argument_list|(
argument|T&_q_value
argument_list|,
argument|T newValue
argument_list|)
expr_stmt|;
end_expr_stmt
begin_function
DECL|function|isFetchAndAddNative
specifier|static
specifier|inline
name|bool
name|isFetchAndAddNative
parameter_list|()
block|{
return|return
name|true
return|;
block|}
end_function
begin_function
DECL|function|isFetchAndAddWaitFree
specifier|static
specifier|inline
name|bool
name|isFetchAndAddWaitFree
parameter_list|()
block|{
return|return
name|true
return|;
block|}
end_function
begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
specifier|static
name|T
name|fetchAndAddRelaxed
argument_list|(
argument|T&_q_value
argument_list|,
argument|typename QAtomicAdditiveType<T>::AdditiveT valueToAdd
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
unit|};
DECL|function|sizeof
name|template
operator|<
name|typename
name|T
operator|>
expr|struct
name|QAtomicOps
operator|:
name|QBasicAtomicOps
operator|<
sizeof|sizeof
argument_list|(
name|T
argument_list|)
operator|>
block|{
typedef|typedef
name|T
name|Type
typedef|;
block|}
end_expr_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_if
if|#
directive|if
name|defined
argument_list|(
name|Q_CC_GNU
argument_list|)
operator|||
name|defined
argument_list|(
name|Q_CC_INTEL
argument_list|)
end_if
begin_expr_stmt
name|template
operator|<
operator|>
expr|struct
name|QAtomicIntegerTraits
operator|<
name|char
operator|>
block|{ enum
block|{
name|IsInteger
operator|=
literal|1
block|}
block|; }
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|template
operator|<
operator|>
expr|struct
name|QAtomicIntegerTraits
operator|<
name|signed
name|char
operator|>
block|{ enum
block|{
name|IsInteger
operator|=
literal|1
block|}
block|; }
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|template
operator|<
operator|>
expr|struct
name|QAtomicIntegerTraits
operator|<
name|unsigned
name|char
operator|>
block|{ enum
block|{
name|IsInteger
operator|=
literal|1
block|}
block|; }
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|template
operator|<
operator|>
expr|struct
name|QAtomicIntegerTraits
operator|<
name|short
operator|>
block|{ enum
block|{
name|IsInteger
operator|=
literal|1
block|}
block|; }
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|template
operator|<
operator|>
expr|struct
name|QAtomicIntegerTraits
operator|<
name|unsigned
name|short
operator|>
block|{ enum
block|{
name|IsInteger
operator|=
literal|1
block|}
block|; }
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|template
operator|<
operator|>
expr|struct
name|QAtomicIntegerTraits
operator|<
name|long
operator|>
block|{ enum
block|{
name|IsInteger
operator|=
literal|1
block|}
block|; }
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|template
operator|<
operator|>
expr|struct
name|QAtomicIntegerTraits
operator|<
name|unsigned
name|long
operator|>
block|{ enum
block|{
name|IsInteger
operator|=
literal|1
block|}
block|; }
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|template
operator|<
operator|>
expr|struct
name|QAtomicIntegerTraits
operator|<
name|long
name|long
operator|>
block|{ enum
block|{
name|IsInteger
operator|=
literal|1
block|}
block|; }
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|template
operator|<
operator|>
expr|struct
name|QAtomicIntegerTraits
operator|<
name|unsigned
name|long
name|long
operator|>
block|{ enum
block|{
name|IsInteger
operator|=
literal|1
block|}
block|; }
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|template
operator|<
operator|>
name|template
operator|<
name|typename
name|T
operator|>
specifier|inline
DECL|function|ref
name|bool
name|QBasicAtomicOps
operator|<
literal|1
operator|>
operator|::
name|ref
argument_list|(
argument|T&_q_value
argument_list|)
block|{
name|unsigned
name|char
name|ret
block|;
name|asm
specifier|volatile
operator|(
literal|"lock\n"
literal|"incb %0\n"
literal|"setne %1"
operator|:
literal|"=m"
operator|(
name|_q_value
operator|)
operator|,
literal|"=qm"
operator|(
name|ret
operator|)
operator|:
literal|"m"
operator|(
name|_q_value
operator|)
operator|:
literal|"memory"
operator|)
block|;
return|return
name|ret
operator|!=
literal|0
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|template
operator|<
operator|>
name|template
operator|<
name|typename
name|T
operator|>
specifier|inline
DECL|function|ref
name|bool
name|QBasicAtomicOps
operator|<
literal|2
operator|>
operator|::
name|ref
argument_list|(
argument|T&_q_value
argument_list|)
block|{
name|unsigned
name|char
name|ret
block|;
name|asm
specifier|volatile
operator|(
literal|"lock\n"
literal|"incw %0\n"
literal|"setne %1"
operator|:
literal|"=m"
operator|(
name|_q_value
operator|)
operator|,
literal|"=qm"
operator|(
name|ret
operator|)
operator|:
literal|"m"
operator|(
name|_q_value
operator|)
operator|:
literal|"memory"
operator|)
block|;
return|return
name|ret
operator|!=
literal|0
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|template
operator|<
operator|>
name|template
operator|<
name|typename
name|T
operator|>
specifier|inline
DECL|function|ref
name|bool
name|QBasicAtomicOps
operator|<
literal|4
operator|>
operator|::
name|ref
argument_list|(
argument|T&_q_value
argument_list|)
block|{
name|unsigned
name|char
name|ret
block|;
name|asm
specifier|volatile
operator|(
literal|"lock\n"
literal|"incl %0\n"
literal|"setne %1"
operator|:
literal|"=m"
operator|(
name|_q_value
operator|)
operator|,
literal|"=qm"
operator|(
name|ret
operator|)
operator|:
literal|"m"
operator|(
name|_q_value
operator|)
operator|:
literal|"memory"
operator|)
block|;
return|return
name|ret
operator|!=
literal|0
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|template
operator|<
operator|>
name|template
operator|<
name|typename
name|T
operator|>
specifier|inline
DECL|function|ref
name|bool
name|QBasicAtomicOps
operator|<
literal|8
operator|>
operator|::
name|ref
argument_list|(
argument|T&_q_value
argument_list|)
block|{
name|unsigned
name|char
name|ret
block|;
name|asm
specifier|volatile
operator|(
literal|"lock\n"
literal|"incq %0\n"
literal|"setne %1"
operator|:
literal|"=m"
operator|(
name|_q_value
operator|)
operator|,
literal|"=qm"
operator|(
name|ret
operator|)
operator|:
literal|"m"
operator|(
name|_q_value
operator|)
operator|:
literal|"memory"
operator|)
block|;
return|return
name|ret
operator|!=
literal|0
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|template
operator|<
operator|>
name|template
operator|<
name|typename
name|T
operator|>
specifier|inline
DECL|function|deref
name|bool
name|QBasicAtomicOps
operator|<
literal|1
operator|>
operator|::
name|deref
argument_list|(
argument|T&_q_value
argument_list|)
block|{
name|unsigned
name|char
name|ret
block|;
name|asm
specifier|volatile
operator|(
literal|"lock\n"
literal|"decb %0\n"
literal|"setne %1"
operator|:
literal|"=m"
operator|(
name|_q_value
operator|)
operator|,
literal|"=qm"
operator|(
name|ret
operator|)
operator|:
literal|"m"
operator|(
name|_q_value
operator|)
operator|:
literal|"memory"
operator|)
block|;
return|return
name|ret
operator|!=
literal|0
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|template
operator|<
operator|>
name|template
operator|<
name|typename
name|T
operator|>
specifier|inline
DECL|function|deref
name|bool
name|QBasicAtomicOps
operator|<
literal|2
operator|>
operator|::
name|deref
argument_list|(
argument|T&_q_value
argument_list|)
block|{
name|unsigned
name|char
name|ret
block|;
name|asm
specifier|volatile
operator|(
literal|"lock\n"
literal|"decw %0\n"
literal|"setne %1"
operator|:
literal|"=m"
operator|(
name|_q_value
operator|)
operator|,
literal|"=qm"
operator|(
name|ret
operator|)
operator|:
literal|"m"
operator|(
name|_q_value
operator|)
operator|:
literal|"memory"
operator|)
block|;
return|return
name|ret
operator|!=
literal|0
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|template
operator|<
operator|>
name|template
operator|<
name|typename
name|T
operator|>
specifier|inline
DECL|function|deref
name|bool
name|QBasicAtomicOps
operator|<
literal|4
operator|>
operator|::
name|deref
argument_list|(
argument|T&_q_value
argument_list|)
block|{
name|unsigned
name|char
name|ret
block|;
name|asm
specifier|volatile
operator|(
literal|"lock\n"
literal|"decl %0\n"
literal|"setne %1"
operator|:
literal|"=m"
operator|(
name|_q_value
operator|)
operator|,
literal|"=qm"
operator|(
name|ret
operator|)
operator|:
literal|"m"
operator|(
name|_q_value
operator|)
operator|:
literal|"memory"
operator|)
block|;
return|return
name|ret
operator|!=
literal|0
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|template
operator|<
operator|>
name|template
operator|<
name|typename
name|T
operator|>
specifier|inline
DECL|function|deref
name|bool
name|QBasicAtomicOps
operator|<
literal|8
operator|>
operator|::
name|deref
argument_list|(
argument|T&_q_value
argument_list|)
block|{
name|unsigned
name|char
name|ret
block|;
name|asm
specifier|volatile
operator|(
literal|"lock\n"
literal|"decq %0\n"
literal|"setne %1"
operator|:
literal|"=m"
operator|(
name|_q_value
operator|)
operator|,
literal|"=qm"
operator|(
name|ret
operator|)
operator|:
literal|"m"
operator|(
name|_q_value
operator|)
operator|:
literal|"memory"
operator|)
block|;
return|return
name|ret
operator|!=
literal|0
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|template
operator|<
name|int
name|size
operator|>
name|template
operator|<
name|typename
name|T
operator|>
specifier|inline
DECL|function|testAndSetRelaxed
name|bool
name|QBasicAtomicOps
operator|<
name|size
operator|>
operator|::
name|testAndSetRelaxed
argument_list|(
argument|T&_q_value
argument_list|,
argument|T expectedValue
argument_list|,
argument|T newValue
argument_list|)
block|{
name|unsigned
name|char
name|ret
block|;
name|asm
specifier|volatile
operator|(
literal|"lock\n"
literal|"cmpxchg %3,%2\n"
literal|"sete %1\n"
operator|:
literal|"=a"
operator|(
name|newValue
operator|)
operator|,
literal|"=qm"
operator|(
name|ret
operator|)
operator|,
literal|"+m"
operator|(
name|_q_value
operator|)
operator|:
literal|"r"
operator|(
name|newValue
operator|)
operator|,
literal|"0"
operator|(
name|expectedValue
operator|)
operator|:
literal|"memory"
operator|)
block|;
return|return
name|ret
operator|!=
literal|0
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|template
operator|<
operator|>
name|template
operator|<
name|typename
name|T
operator|>
specifier|inline
DECL|function|testAndSetRelaxed
name|bool
name|QBasicAtomicOps
operator|<
literal|1
operator|>
operator|::
name|testAndSetRelaxed
argument_list|(
argument|T&_q_value
argument_list|,
argument|T expectedValue
argument_list|,
argument|T newValue
argument_list|)
block|{
name|unsigned
name|char
name|ret
block|;
name|asm
specifier|volatile
operator|(
literal|"lock\n"
literal|"cmpxchg %3,%2\n"
literal|"sete %1\n"
operator|:
literal|"=a"
operator|(
name|newValue
operator|)
operator|,
literal|"=qm"
operator|(
name|ret
operator|)
operator|,
literal|"+m"
operator|(
name|_q_value
operator|)
operator|:
literal|"q"
operator|(
name|newValue
operator|)
operator|,
literal|"0"
operator|(
name|expectedValue
operator|)
operator|:
literal|"memory"
operator|)
block|;
return|return
name|ret
operator|!=
literal|0
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|template
operator|<
name|int
name|size
operator|>
name|template
operator|<
name|typename
name|T
operator|>
specifier|inline
DECL|function|fetchAndStoreRelaxed
name|T
name|QBasicAtomicOps
operator|<
name|size
operator|>
operator|::
name|fetchAndStoreRelaxed
argument_list|(
argument|T&_q_value
argument_list|,
argument|T newValue
argument_list|)
block|{
name|asm
specifier|volatile
operator|(
literal|"xchg %0,%1"
operator|:
literal|"=r"
operator|(
name|newValue
operator|)
operator|,
literal|"+m"
operator|(
name|_q_value
operator|)
operator|:
literal|"0"
operator|(
name|newValue
operator|)
operator|:
literal|"memory"
operator|)
block|;
return|return
name|newValue
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|template
operator|<
operator|>
name|template
operator|<
name|typename
name|T
operator|>
specifier|inline
DECL|function|fetchAndStoreRelaxed
name|T
name|QBasicAtomicOps
operator|<
literal|1
operator|>
operator|::
name|fetchAndStoreRelaxed
argument_list|(
argument|T&_q_value
argument_list|,
argument|T newValue
argument_list|)
block|{
name|asm
specifier|volatile
operator|(
literal|"xchg %0,%1"
operator|:
literal|"=q"
operator|(
name|newValue
operator|)
operator|,
literal|"+m"
operator|(
name|_q_value
operator|)
operator|:
literal|"0"
operator|(
name|newValue
operator|)
operator|:
literal|"memory"
operator|)
block|;
return|return
name|newValue
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|template
operator|<
name|int
name|size
operator|>
name|template
operator|<
name|typename
name|T
operator|>
specifier|inline
DECL|function|fetchAndAddRelaxed
name|T
name|QBasicAtomicOps
operator|<
name|size
operator|>
operator|::
name|fetchAndAddRelaxed
argument_list|(
argument|T&_q_value
argument_list|,
argument|typename QAtomicAdditiveType<T>::AdditiveT valueToAdd
argument_list|)
block|{
name|T
name|result
block|;
name|asm
specifier|volatile
operator|(
literal|"lock\n"
literal|"xadd %0,%1"
operator|:
literal|"=r"
operator|(
name|result
operator|)
operator|,
literal|"+m"
operator|(
name|_q_value
operator|)
operator|:
literal|"0"
operator|(
name|T
argument_list|(
name|valueToAdd
operator|*
name|QAtomicAdditiveType
operator|<
name|T
operator|>
operator|::
name|AddScale
argument_list|)
operator|)
operator|:
literal|"memory"
operator|)
block|;
return|return
name|result
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|template
operator|<
operator|>
name|template
operator|<
name|typename
name|T
operator|>
specifier|inline
DECL|function|fetchAndAddRelaxed
name|T
name|QBasicAtomicOps
operator|<
literal|1
operator|>
operator|::
name|fetchAndAddRelaxed
argument_list|(
argument|T&_q_value
argument_list|,
argument|typename QAtomicAdditiveType<T>::AdditiveT valueToAdd
argument_list|)
block|{
name|T
name|result
block|;
name|asm
specifier|volatile
operator|(
literal|"lock\n"
literal|"xadd %0,%1"
operator|:
literal|"=q"
operator|(
name|result
operator|)
operator|,
literal|"+m"
operator|(
name|_q_value
operator|)
operator|:
literal|"0"
operator|(
name|T
argument_list|(
name|valueToAdd
operator|*
name|QAtomicAdditiveType
operator|<
name|T
operator|>
operator|::
name|AddScale
argument_list|)
operator|)
operator|:
literal|"memory"
operator|)
block|;
return|return
name|result
return|;
block|}
end_expr_stmt
begin_define
DECL|macro|Q_ATOMIC_INT8_IS_SUPPORTED
define|#
directive|define
name|Q_ATOMIC_INT8_IS_SUPPORTED
end_define
begin_define
DECL|macro|Q_ATOMIC_INT8_REFERENCE_COUNTING_IS_ALWAYS_NATIVE
define|#
directive|define
name|Q_ATOMIC_INT8_REFERENCE_COUNTING_IS_ALWAYS_NATIVE
end_define
begin_define
DECL|macro|Q_ATOMIC_INT8_REFERENCE_COUNTING_IS_WAIT_FREE
define|#
directive|define
name|Q_ATOMIC_INT8_REFERENCE_COUNTING_IS_WAIT_FREE
end_define
begin_define
DECL|macro|Q_ATOMIC_INT8_TEST_AND_SET_IS_ALWAYS_NATIVE
define|#
directive|define
name|Q_ATOMIC_INT8_TEST_AND_SET_IS_ALWAYS_NATIVE
end_define
begin_define
DECL|macro|Q_ATOMIC_INT8_TEST_AND_SET_IS_WAIT_FREE
define|#
directive|define
name|Q_ATOMIC_INT8_TEST_AND_SET_IS_WAIT_FREE
end_define
begin_define
DECL|macro|Q_ATOMIC_INT8_FETCH_AND_STORE_IS_ALWAYS_NATIVE
define|#
directive|define
name|Q_ATOMIC_INT8_FETCH_AND_STORE_IS_ALWAYS_NATIVE
end_define
begin_define
DECL|macro|Q_ATOMIC_INT8_FETCH_AND_STORE_IS_WAIT_FREE
define|#
directive|define
name|Q_ATOMIC_INT8_FETCH_AND_STORE_IS_WAIT_FREE
end_define
begin_define
DECL|macro|Q_ATOMIC_INT8_FETCH_AND_ADD_IS_ALWAYS_NATIVE
define|#
directive|define
name|Q_ATOMIC_INT8_FETCH_AND_ADD_IS_ALWAYS_NATIVE
end_define
begin_define
DECL|macro|Q_ATOMIC_INT8_FETCH_AND_ADD_IS_WAIT_FREE
define|#
directive|define
name|Q_ATOMIC_INT8_FETCH_AND_ADD_IS_WAIT_FREE
end_define
begin_define
DECL|macro|Q_ATOMIC_INT16_IS_SUPPORTED
define|#
directive|define
name|Q_ATOMIC_INT16_IS_SUPPORTED
end_define
begin_define
DECL|macro|Q_ATOMIC_INT16_REFERENCE_COUNTING_IS_ALWAYS_NATIVE
define|#
directive|define
name|Q_ATOMIC_INT16_REFERENCE_COUNTING_IS_ALWAYS_NATIVE
end_define
begin_define
DECL|macro|Q_ATOMIC_INT16_REFERENCE_COUNTING_IS_WAIT_FREE
define|#
directive|define
name|Q_ATOMIC_INT16_REFERENCE_COUNTING_IS_WAIT_FREE
end_define
begin_define
DECL|macro|Q_ATOMIC_INT16_TEST_AND_SET_IS_ALWAYS_NATIVE
define|#
directive|define
name|Q_ATOMIC_INT16_TEST_AND_SET_IS_ALWAYS_NATIVE
end_define
begin_define
DECL|macro|Q_ATOMIC_INT16_TEST_AND_SET_IS_WAIT_FREE
define|#
directive|define
name|Q_ATOMIC_INT16_TEST_AND_SET_IS_WAIT_FREE
end_define
begin_define
DECL|macro|Q_ATOMIC_INT16_FETCH_AND_STORE_IS_ALWAYS_NATIVE
define|#
directive|define
name|Q_ATOMIC_INT16_FETCH_AND_STORE_IS_ALWAYS_NATIVE
end_define
begin_define
DECL|macro|Q_ATOMIC_INT16_FETCH_AND_STORE_IS_WAIT_FREE
define|#
directive|define
name|Q_ATOMIC_INT16_FETCH_AND_STORE_IS_WAIT_FREE
end_define
begin_define
DECL|macro|Q_ATOMIC_INT16_FETCH_AND_ADD_IS_ALWAYS_NATIVE
define|#
directive|define
name|Q_ATOMIC_INT16_FETCH_AND_ADD_IS_ALWAYS_NATIVE
end_define
begin_define
DECL|macro|Q_ATOMIC_INT16_FETCH_AND_ADD_IS_WAIT_FREE
define|#
directive|define
name|Q_ATOMIC_INT16_FETCH_AND_ADD_IS_WAIT_FREE
end_define
begin_define
DECL|macro|Q_ATOMIC_INT64_IS_SUPPORTED
define|#
directive|define
name|Q_ATOMIC_INT64_IS_SUPPORTED
end_define
begin_define
DECL|macro|Q_ATOMIC_INT64_REFERENCE_COUNTING_IS_ALWAYS_NATIVE
define|#
directive|define
name|Q_ATOMIC_INT64_REFERENCE_COUNTING_IS_ALWAYS_NATIVE
end_define
begin_define
DECL|macro|Q_ATOMIC_INT64_REFERENCE_COUNTING_IS_WAIT_FREE
define|#
directive|define
name|Q_ATOMIC_INT64_REFERENCE_COUNTING_IS_WAIT_FREE
end_define
begin_define
DECL|macro|Q_ATOMIC_INT64_TEST_AND_SET_IS_ALWAYS_NATIVE
define|#
directive|define
name|Q_ATOMIC_INT64_TEST_AND_SET_IS_ALWAYS_NATIVE
end_define
begin_define
DECL|macro|Q_ATOMIC_INT64_TEST_AND_SET_IS_WAIT_FREE
define|#
directive|define
name|Q_ATOMIC_INT64_TEST_AND_SET_IS_WAIT_FREE
end_define
begin_define
DECL|macro|Q_ATOMIC_INT64_FETCH_AND_STORE_IS_ALWAYS_NATIVE
define|#
directive|define
name|Q_ATOMIC_INT64_FETCH_AND_STORE_IS_ALWAYS_NATIVE
end_define
begin_define
DECL|macro|Q_ATOMIC_INT64_FETCH_AND_STORE_IS_WAIT_FREE
define|#
directive|define
name|Q_ATOMIC_INT64_FETCH_AND_STORE_IS_WAIT_FREE
end_define
begin_define
DECL|macro|Q_ATOMIC_INT64_FETCH_AND_ADD_IS_ALWAYS_NATIVE
define|#
directive|define
name|Q_ATOMIC_INT64_FETCH_AND_ADD_IS_ALWAYS_NATIVE
end_define
begin_define
DECL|macro|Q_ATOMIC_INT64_FETCH_AND_ADD_IS_WAIT_FREE
define|#
directive|define
name|Q_ATOMIC_INT64_FETCH_AND_ADD_IS_WAIT_FREE
end_define
begin_else
else|#
directive|else
end_else
begin_comment
comment|// !Q_CC_INTEL&& !Q_CC_GNU
end_comment
begin_extern
extern|extern
literal|"C"
block|{
name|Q_CORE_EXPORT
name|int
name|q_atomic_test_and_set_int
parameter_list|(
specifier|volatile
name|int
modifier|*
name|ptr
parameter_list|,
name|int
name|expected
parameter_list|,
name|int
name|newval
parameter_list|)
function_decl|;
name|Q_CORE_EXPORT
name|int
name|q_atomic_test_and_set_ptr
parameter_list|(
specifier|volatile
name|void
modifier|*
name|ptr
parameter_list|,
name|void
modifier|*
name|expected
parameter_list|,
name|void
modifier|*
name|newval
parameter_list|)
function_decl|;
name|Q_CORE_EXPORT
name|int
name|q_atomic_increment
parameter_list|(
specifier|volatile
name|int
modifier|*
name|ptr
parameter_list|)
function_decl|;
name|Q_CORE_EXPORT
name|int
name|q_atomic_decrement
parameter_list|(
specifier|volatile
name|int
modifier|*
name|ptr
parameter_list|)
function_decl|;
name|Q_CORE_EXPORT
name|int
name|q_atomic_set_int
parameter_list|(
specifier|volatile
name|int
modifier|*
name|ptr
parameter_list|,
name|int
name|newval
parameter_list|)
function_decl|;
name|Q_CORE_EXPORT
name|void
modifier|*
name|q_atomic_set_ptr
parameter_list|(
specifier|volatile
name|void
modifier|*
name|ptr
parameter_list|,
name|void
modifier|*
name|newval
parameter_list|)
function_decl|;
name|Q_CORE_EXPORT
name|int
name|q_atomic_fetch_and_add_int
parameter_list|(
specifier|volatile
name|int
modifier|*
name|ptr
parameter_list|,
name|int
name|value
parameter_list|)
function_decl|;
name|Q_CORE_EXPORT
name|void
modifier|*
name|q_atomic_fetch_and_add_ptr
parameter_list|(
specifier|volatile
name|void
modifier|*
name|ptr
parameter_list|,
name|qptrdiff
name|value
parameter_list|)
function_decl|;
block|}
end_extern
begin_comment
comment|// extern "C"
end_comment
begin_expr_stmt
name|template
operator|<
operator|>
name|template
operator|<
name|typename
name|T
operator|>
specifier|inline
DECL|function|ref
name|bool
name|QBasicAtomicOps
operator|<
literal|4
operator|>
operator|::
name|ref
argument_list|(
argument|T&_q_value
argument_list|)
block|{
return|return
name|q_atomic_increment
argument_list|(
operator|(
name|int
operator|*
operator|)
operator|&
name|_q_value
argument_list|)
operator|!=
literal|0
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|template
operator|<
operator|>
name|template
operator|<
name|typename
name|T
operator|>
specifier|inline
DECL|function|deref
name|bool
name|QBasicAtomicOps
operator|<
literal|4
operator|>
operator|::
name|deref
argument_list|(
argument|T&_q_value
argument_list|)
block|{
return|return
name|q_atomic_decrement
argument_list|(
operator|(
name|int
operator|*
operator|)
operator|&
name|_q_value
argument_list|)
operator|!=
literal|0
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|template
operator|<
operator|>
name|template
operator|<
name|typename
name|T
operator|>
specifier|inline
DECL|function|testAndSetRelaxed
name|bool
name|QBasicAtomicOps
operator|<
literal|4
operator|>
operator|::
name|testAndSetRelaxed
argument_list|(
argument|T&_q_value
argument_list|,
argument|T expectedValue
argument_list|,
argument|T newValue
argument_list|)
block|{
return|return
name|q_atomic_test_and_set_int
argument_list|(
operator|(
name|int
operator|*
operator|)
operator|&
name|_q_value
argument_list|,
name|int
argument_list|(
name|expectedValue
argument_list|)
argument_list|,
name|int
argument_list|(
name|newValue
argument_list|)
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|template
operator|<
operator|>
name|template
operator|<
name|typename
name|T
operator|>
specifier|inline
DECL|function|fetchAndStoreRelaxed
name|T
name|QBasicAtomicOps
operator|<
literal|4
operator|>
operator|::
name|fetchAndStoreRelaxed
argument_list|(
argument|T&_q_value
argument_list|,
argument|T newValue
argument_list|)
block|{
return|return
name|T
argument_list|(
argument|q_atomic_set_int((int*)&_q_value, int(newValue)); }  template<> template<typename T> inline T QBasicAtomicOps<
DECL|function|fetchAndAddRelaxed
literal|4
argument|>::fetchAndAddRelaxed(T&_q_value, typename QAtomicAdditiveType<T>::AdditiveT valueToAdd) {     return T(q_atomic_fetch_and_add_int((int *)&_q_value, valueToAdd * QAtomicAdditiveType<T>::AddScale)); }  template<> template<typename T> inline bool QBasicAtomicOps<
DECL|function|testAndSetRelaxed
literal|8
argument|>::testAndSetRelaxed(T&_q_value, T expectedValue, T newValue) {     return q_atomic_test_and_set_ptr(&_q_value, (void*)expectedValue, (void*)newValue); }  template<> template<typename T> inline T QBasicAtomicOps<
DECL|function|fetchAndStoreRelaxed
literal|8
argument|>::fetchAndStoreRelaxed(T&_q_value, T newValue) {     return T(q_atomic_set_ptr(&_q_value, (void*)newValue); }  template<> template<typename T> inline T QBasicAtomicOps<
DECL|function|fetchAndAddRelaxed
literal|8
argument|>::fetchAndAddRelaxed(T&_q_value, typename QAtomicAdditiveType<T>::AdditiveT valueToAdd) {     return T(q_atomic_fetch_and_add_int(&_q_value, valueToAdd * QAtomicAdditiveType<T>::AddScale)); }
endif|#
directive|endif
comment|// Q_CC_GNU || Q_CC_INTEL
argument|QT_END_NAMESPACE  QT_END_HEADER
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QATOMIC_X86_64_H
end_comment
end_unit
