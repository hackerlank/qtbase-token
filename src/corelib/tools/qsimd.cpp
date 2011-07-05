begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qsimd_p.h"
end_include
begin_include
include|#
directive|include
file|<QByteArray>
end_include
begin_include
include|#
directive|include
file|<stdio.h>
end_include
begin_if
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_WINCE
argument_list|)
end_if
begin_include
include|#
directive|include
file|<windows.h>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_if
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_WIN64
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|Q_CC_GNU
argument_list|)
end_if
begin_include
include|#
directive|include
file|<intrin.h>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_if
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_LINUX
argument_list|)
operator|&&
name|defined
argument_list|(
name|__arm__
argument_list|)
end_if
begin_include
include|#
directive|include
file|"private/qcore_unix_p.h"
end_include
begin_comment
comment|// the kernel header definitions for HWCAP_*
end_comment
begin_comment
comment|// (the ones we need/may need anyway)
end_comment
begin_comment
comment|// copied from<asm/hwcap.h> (ARM)
end_comment
begin_define
DECL|macro|HWCAP_IWMMXT
define|#
directive|define
name|HWCAP_IWMMXT
value|512
end_define
begin_define
DECL|macro|HWCAP_CRUNCH
define|#
directive|define
name|HWCAP_CRUNCH
value|1024
end_define
begin_define
DECL|macro|HWCAP_THUMBEE
define|#
directive|define
name|HWCAP_THUMBEE
value|2048
end_define
begin_define
DECL|macro|HWCAP_NEON
define|#
directive|define
name|HWCAP_NEON
value|4096
end_define
begin_define
DECL|macro|HWCAP_VFPv3
define|#
directive|define
name|HWCAP_VFPv3
value|8192
end_define
begin_define
DECL|macro|HWCAP_VFPv3D16
define|#
directive|define
name|HWCAP_VFPv3D16
value|16384
end_define
begin_comment
comment|// copied from<linux/auxvec.h>
end_comment
begin_define
DECL|macro|AT_HWCAP
define|#
directive|define
name|AT_HWCAP
value|16
end_define
begin_comment
DECL|macro|AT_HWCAP
comment|/* arch dependent hints at CPU capabilities */
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_function
name|QT_BEGIN_NAMESPACE
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_NACL
argument_list|)
DECL|function|detectProcessorFeatures
specifier|static
specifier|inline
name|uint
name|detectProcessorFeatures
parameter_list|()
block|{
return|return
literal|0
return|;
block|}
end_function
begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|Q_OS_WINCE
argument_list|)
end_elif
begin_function
specifier|static
specifier|inline
name|uint
name|detectProcessorFeatures
parameter_list|()
block|{
name|uint
name|features
init|=
literal|0
decl_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|ARM
argument_list|)
if|if
condition|(
name|IsProcessorFeaturePresent
argument_list|(
name|PF_ARM_INTEL_WMMX
argument_list|)
condition|)
block|{
name|features
operator|=
name|IWMMXT
expr_stmt|;
return|return
name|features
return|;
block|}
elif|#
directive|elif
name|defined
argument_list|(
name|_X86_
argument_list|)
name|features
operator|=
literal|0
expr_stmt|;
if|#
directive|if
name|defined
name|QT_HAVE_MMX
if|if
condition|(
name|IsProcessorFeaturePresent
argument_list|(
name|PF_MMX_INSTRUCTIONS_AVAILABLE
argument_list|)
condition|)
name|features
operator||=
name|MMX
expr_stmt|;
endif|#
directive|endif
if|#
directive|if
name|defined
name|QT_HAVE_3DNOW
if|if
condition|(
name|IsProcessorFeaturePresent
argument_list|(
name|PF_3DNOW_INSTRUCTIONS_AVAILABLE
argument_list|)
condition|)
name|features
operator||=
name|MMX3DNOW
expr_stmt|;
endif|#
directive|endif
return|return
name|features
return|;
endif|#
directive|endif
name|features
operator|=
literal|0
expr_stmt|;
return|return
name|features
return|;
block|}
end_function
begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__arm__
argument_list|)
operator|||
name|defined
argument_list|(
name|__arm
argument_list|)
operator|||
name|defined
argument_list|(
name|QT_HAVE_IWMMXT
argument_list|)
operator|||
name|defined
argument_list|(
name|QT_HAVE_NEON
argument_list|)
end_elif
begin_function
specifier|static
specifier|inline
name|uint
name|detectProcessorFeatures
parameter_list|()
block|{
name|uint
name|features
init|=
literal|0
decl_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_LINUX
argument_list|)
name|int
name|auxv
init|=
operator|::
name|qt_safe_open
argument_list|(
literal|"/proc/self/auxv"
argument_list|,
name|O_RDONLY
argument_list|)
decl_stmt|;
if|if
condition|(
name|auxv
operator|!=
operator|-
literal|1
condition|)
block|{
name|unsigned
name|long
name|vector
index|[
literal|64
index|]
decl_stmt|;
name|int
name|nread
decl_stmt|;
while|while
condition|(
name|features
operator|==
literal|0
condition|)
block|{
name|nread
operator|=
operator|::
name|qt_safe_read
argument_list|(
name|auxv
argument_list|,
operator|(
name|char
operator|*
operator|)
name|vector
argument_list|,
sizeof|sizeof
name|vector
argument_list|)
expr_stmt|;
if|if
condition|(
name|nread
operator|<=
literal|0
condition|)
block|{
comment|// EOF or error
break|break;
block|}
name|int
name|max
init|=
name|nread
operator|/
operator|(
sizeof|sizeof
name|vector
index|[
literal|0
index|]
operator|)
decl_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|max
condition|;
name|i
operator|+=
literal|2
control|)
if|if
condition|(
name|vector
index|[
name|i
index|]
operator|==
name|AT_HWCAP
condition|)
block|{
if|if
condition|(
name|vector
index|[
name|i
operator|+
literal|1
index|]
operator|&
name|HWCAP_IWMMXT
condition|)
name|features
operator||=
name|IWMMXT
expr_stmt|;
if|if
condition|(
name|vector
index|[
name|i
operator|+
literal|1
index|]
operator|&
name|HWCAP_NEON
condition|)
name|features
operator||=
name|NEON
expr_stmt|;
break|break;
block|}
block|}
operator|::
name|qt_safe_close
argument_list|(
name|auxv
argument_list|)
expr_stmt|;
return|return
name|features
return|;
block|}
comment|// fall back if /proc/self/auxv wasn't found
endif|#
directive|endif
if|#
directive|if
name|defined
argument_list|(
name|QT_HAVE_IWMMXT
argument_list|)
comment|// runtime detection only available when running as a previlegied process
name|features
operator|=
name|IWMMXT
expr_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|QT_ALWAYS_HAVE_NEON
argument_list|)
name|features
operator|=
name|NEON
expr_stmt|;
endif|#
directive|endif
return|return
name|features
return|;
block|}
end_function
begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__i386__
argument_list|)
operator|||
name|defined
argument_list|(
name|_M_IX86
argument_list|)
end_elif
begin_function
specifier|static
specifier|inline
name|uint
name|detectProcessorFeatures
parameter_list|()
block|{
name|uint
name|features
init|=
literal|0
decl_stmt|;
name|unsigned
name|int
name|extended_result
init|=
literal|0
decl_stmt|;
name|unsigned
name|int
name|feature_result
init|=
literal|0
decl_stmt|;
name|uint
name|result
init|=
literal|0
decl_stmt|;
comment|/* see p. 118 of amd64 instruction set manual Vol3 */
if|#
directive|if
name|defined
argument_list|(
name|Q_CC_GNU
argument_list|)
name|long
name|cpuid_supported
decl_stmt|,
name|tmp1
decl_stmt|;
asm|asm ("pushf\n"          "pop %0\n"          "mov %0, %1\n"          "xor $0x00200000, %0\n"          "push %0\n"          "popf\n"          "pushf\n"          "pop %0\n"          "xor %1, %0\n"
comment|// %eax is now 0 if CPUID is not supported
asm|: "=a" (cpuid_supported), "=r" (tmp1)          );
if|if
condition|(
name|cpuid_supported
condition|)
block|{
asm|asm ("xchg %%ebx, %2\n"              "cpuid\n"              "xchg %%ebx, %2\n"             : "=c" (feature_result), "=d" (result), "=&r" (tmp1)             : "a" (1));
asm|asm ("xchg %%ebx, %1\n"              "cpuid\n"              "cmp $0x80000000, %%eax\n"              "jnbe 1f\n"              "xor %0, %0\n"              "jmp 2f\n"              "1:\n"              "mov $0x80000001, %%eax\n"              "cpuid\n"              "2:\n"              "xchg %%ebx, %1\n"             : "=d" (extended_result), "=&r" (tmp1)             : "a" (0x80000000)             : "%ecx"             );
block|}
elif|#
directive|elif
name|defined
argument_list|(
name|Q_OS_WIN
argument_list|)
name|_asm
block|{
name|push
name|eax
name|push
name|ebx
name|push
name|ecx
name|push
name|edx
name|pushfd
name|pop
name|eax
name|mov
name|ebx
decl_stmt|,
name|eax
decl|xor
name|eax
decl_stmt|, 00200000h
name|push
name|eax
name|popfd
name|pushfd
name|pop
name|eax
name|mov
name|edx
decl_stmt|, 0         xor
name|eax
decl_stmt|,
name|ebx
name|jz
name|skip
name|mov
name|eax
decl_stmt|, 1
name|cpuid
name|mov
name|result
decl_stmt|,
name|edx
name|mov
name|feature_result
decl_stmt|,
name|ecx
name|skip
range|:
name|pop
name|edx
name|pop
name|ecx
name|pop
name|ebx
name|pop
name|eax
block|}
name|_asm
block|{
name|push
name|eax
name|push
name|ebx
name|push
name|ecx
name|push
name|edx
name|pushfd
name|pop
name|eax
name|mov
name|ebx
decl_stmt|,
name|eax
decl|xor
name|eax
decl_stmt|, 00200000h
name|push
name|eax
name|popfd
name|pushfd
name|pop
name|eax
name|mov
name|edx
decl_stmt|, 0         xor
name|eax
decl_stmt|,
name|ebx
name|jz
name|skip2
name|mov
name|eax
decl_stmt|, 80000000h
name|cpuid
name|cmp
name|eax
decl_stmt|, 80000000h
name|jbe
name|skip2
name|mov
name|eax
decl_stmt|, 80000001h
name|cpuid
name|mov
name|extended_result
decl_stmt|,
name|edx
name|skip2
range|:
name|pop
name|edx
name|pop
name|ecx
name|pop
name|ebx
name|pop
name|eax
block|}
endif|#
directive|endif
comment|// result now contains the standard feature bits
if|if
condition|(
name|result
operator|&
operator|(
literal|1u
operator|<<
literal|15
operator|)
condition|)
name|features
operator||=
name|CMOV
expr_stmt|;
if|if
condition|(
name|result
operator|&
operator|(
literal|1u
operator|<<
literal|23
operator|)
condition|)
name|features
operator||=
name|MMX
expr_stmt|;
if|if
condition|(
name|extended_result
operator|&
operator|(
literal|1u
operator|<<
literal|22
operator|)
condition|)
name|features
operator||=
name|MMXEXT
expr_stmt|;
if|if
condition|(
name|extended_result
operator|&
operator|(
literal|1u
operator|<<
literal|31
operator|)
condition|)
name|features
operator||=
name|MMX3DNOW
expr_stmt|;
if|if
condition|(
name|extended_result
operator|&
operator|(
literal|1u
operator|<<
literal|30
operator|)
condition|)
name|features
operator||=
name|MMX3DNOWEXT
expr_stmt|;
if|if
condition|(
name|result
operator|&
operator|(
literal|1u
operator|<<
literal|25
operator|)
condition|)
name|features
operator||=
name|SSE
expr_stmt|;
if|if
condition|(
name|result
operator|&
operator|(
literal|1u
operator|<<
literal|26
operator|)
condition|)
name|features
operator||=
name|SSE2
expr_stmt|;
if|if
condition|(
name|feature_result
operator|&
operator|(
literal|1u
operator|)
condition|)
name|features
operator||=
name|SSE3
expr_stmt|;
if|if
condition|(
name|feature_result
operator|&
operator|(
literal|1u
operator|<<
literal|9
operator|)
condition|)
name|features
operator||=
name|SSSE3
expr_stmt|;
if|if
condition|(
name|feature_result
operator|&
operator|(
literal|1u
operator|<<
literal|19
operator|)
condition|)
name|features
operator||=
name|SSE4_1
expr_stmt|;
if|if
condition|(
name|feature_result
operator|&
operator|(
literal|1u
operator|<<
literal|20
operator|)
condition|)
name|features
operator||=
name|SSE4_2
expr_stmt|;
if|if
condition|(
name|feature_result
operator|&
operator|(
literal|1u
operator|<<
literal|28
operator|)
condition|)
name|features
operator||=
name|AVX
expr_stmt|;
return|return
name|features
return|;
block|}
end_function
begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__x86_64
argument_list|)
operator|||
name|defined
argument_list|(
name|Q_OS_WIN64
argument_list|)
end_elif
begin_function
specifier|static
specifier|inline
name|uint
name|detectProcessorFeatures
parameter_list|()
block|{
name|uint
name|features
init|=
name|MMX
operator||
name|SSE
operator||
name|SSE2
operator||
name|CMOV
decl_stmt|;
name|uint
name|feature_result
init|=
literal|0
decl_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_WIN64
argument_list|)
block|{
name|int
name|info
index|[
literal|4
index|]
decl_stmt|;
name|__cpuid
argument_list|(
name|info
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|feature_result
operator|=
name|info
index|[
literal|2
index|]
expr_stmt|;
block|}
elif|#
directive|elif
name|defined
argument_list|(
name|Q_CC_GNU
argument_list|)
name|quint64
name|tmp
decl_stmt|;
asm|asm ("xchg %%rbx, %1\n"          "cpuid\n"          "xchg %%rbx, %1\n"         : "=c" (feature_result), "=&r" (tmp)         : "a" (1)         : "%edx"         );
endif|#
directive|endif
if|if
condition|(
name|feature_result
operator|&
operator|(
literal|1u
operator|)
condition|)
name|features
operator||=
name|SSE3
expr_stmt|;
if|if
condition|(
name|feature_result
operator|&
operator|(
literal|1u
operator|<<
literal|9
operator|)
condition|)
name|features
operator||=
name|SSSE3
expr_stmt|;
if|if
condition|(
name|feature_result
operator|&
operator|(
literal|1u
operator|<<
literal|19
operator|)
condition|)
name|features
operator||=
name|SSE4_1
expr_stmt|;
if|if
condition|(
name|feature_result
operator|&
operator|(
literal|1u
operator|<<
literal|20
operator|)
condition|)
name|features
operator||=
name|SSE4_2
expr_stmt|;
if|if
condition|(
name|feature_result
operator|&
operator|(
literal|1u
operator|<<
literal|28
operator|)
condition|)
name|features
operator||=
name|AVX
expr_stmt|;
return|return
name|features
return|;
block|}
end_function
begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__ia64__
argument_list|)
end_elif
begin_function
specifier|static
specifier|inline
name|uint
name|detectProcessorFeatures
parameter_list|()
block|{
return|return
name|MMX
operator||
name|SSE
operator||
name|SSE2
return|;
block|}
end_function
begin_else
else|#
directive|else
end_else
begin_function
specifier|static
specifier|inline
name|uint
name|detectProcessorFeatures
parameter_list|()
block|{
return|return
literal|0
return|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/*  * Use kdesdk/scripts/generate_string_table.pl to update the table below.  * Here's the data (don't forget the ONE leading space):  mmx  mmxext  mmx3dnow  mmx3dnowext  sse  sse2  cmov  iwmmxt  neon  sse3  ssse3  sse4.1  sse4.2  avx   */
end_comment
begin_comment
comment|// begin generated
end_comment
begin_decl_stmt
DECL|variable|features_string
specifier|static
specifier|const
name|char
name|features_string
index|[]
init|=
literal|" mmx\0"
literal|" mmxext\0"
literal|" mmx3dnow\0"
literal|" mmx3dnowext\0"
literal|" sse\0"
literal|" sse2\0"
literal|" cmov\0"
literal|" iwmmxt\0"
literal|" neon\0"
literal|" sse3\0"
literal|" ssse3\0"
literal|" sse4.1\0"
literal|" sse4.2\0"
literal|" avx\0"
literal|"\0"
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|features_indices
specifier|static
specifier|const
name|int
name|features_indices
index|[]
init|=
block|{
literal|0
block|,
literal|5
block|,
literal|13
block|,
literal|23
block|,
literal|36
block|,
literal|41
block|,
literal|47
block|,
literal|53
block|,
literal|61
block|,
literal|67
block|,
literal|73
block|,
literal|80
block|,
literal|88
block|,
literal|96
block|,
operator|-
literal|1
block|}
decl_stmt|;
end_decl_stmt
begin_comment
comment|// end generated
end_comment
begin_decl_stmt
DECL|variable|features_count
specifier|const
name|int
name|features_count
init|=
operator|(
sizeof|sizeof
name|features_indices
operator|-
literal|1
operator|)
operator|/
operator|(
sizeof|sizeof
name|features_indices
index|[
literal|0
index|]
operator|)
decl_stmt|;
end_decl_stmt
begin_function
DECL|function|qDetectCPUFeatures
name|uint
name|qDetectCPUFeatures
parameter_list|()
block|{
specifier|static
name|QBasicAtomicInt
name|features
init|=
name|Q_BASIC_ATOMIC_INITIALIZER
argument_list|(
operator|-
literal|1
argument_list|)
decl_stmt|;
if|if
condition|(
name|features
operator|.
name|load
argument_list|()
operator|!=
operator|-
literal|1
condition|)
return|return
name|features
operator|.
name|load
argument_list|()
return|;
name|uint
name|f
init|=
name|detectProcessorFeatures
argument_list|()
decl_stmt|;
name|QByteArray
name|disable
init|=
name|qgetenv
argument_list|(
literal|"QT_NO_CPU_FEATURE"
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|disable
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|disable
operator|.
name|prepend
argument_list|(
literal|' '
argument_list|)
expr_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|features_count
condition|;
operator|++
name|i
control|)
block|{
if|if
condition|(
name|disable
operator|.
name|contains
argument_list|(
name|features_string
operator|+
name|features_indices
index|[
name|i
index|]
argument_list|)
condition|)
name|f
operator|&=
operator|~
operator|(
literal|1
operator|<<
name|i
operator|)
expr_stmt|;
block|}
block|}
name|features
operator|.
name|store
argument_list|(
name|f
argument_list|)
expr_stmt|;
return|return
name|f
return|;
block|}
end_function
begin_function
DECL|function|qDumpCPUFeatures
name|void
name|qDumpCPUFeatures
parameter_list|()
block|{
name|uint
name|features
init|=
name|qDetectCPUFeatures
argument_list|()
decl_stmt|;
name|printf
argument_list|(
literal|"Processor features: "
argument_list|)
expr_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|features_count
condition|;
operator|++
name|i
control|)
block|{
if|if
condition|(
name|features
operator|&
operator|(
literal|1
operator|<<
name|i
operator|)
condition|)
name|printf
argument_list|(
literal|"%s"
argument_list|,
name|features_string
operator|+
name|features_indices
index|[
name|i
index|]
argument_list|)
expr_stmt|;
block|}
name|puts
argument_list|(
literal|""
argument_list|)
expr_stmt|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
