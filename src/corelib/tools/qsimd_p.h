begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QSIMD_P_H
end_ifndef
begin_define
DECL|macro|QSIMD_P_H
define|#
directive|define
name|QSIMD_P_H
end_define
begin_comment
comment|//
end_comment
begin_comment
comment|//  W A R N I N G
end_comment
begin_comment
comment|//  -------------
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|// This file is not part of the Qt API.  It exists purely as an
end_comment
begin_comment
comment|// implementation detail.  This header file may change from version to
end_comment
begin_comment
comment|// version without notice, or even be removed.
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|// We mean it.
end_comment
begin_comment
comment|//
end_comment
begin_include
include|#
directive|include
file|<qglobal.h>
end_include
begin_include
include|#
directive|include
file|<qatomic.h>
end_include
begin_comment
comment|/*  * qt_module_config.prf defines the QT_COMPILER_SUPPORTS_XXX macros.  * They mean the compiler supports the necessary flags and the headers  * for the x86 and ARM intrinsics:  *  - GCC: the -mXXX or march=YYY flag is necessary before #include  *    up to 4.8; GCC>= 4.9 can include unconditionally  *  - Intel CC: #include can happen unconditionally  *  - MSVC: #include can happen unconditionally  *  - RVCT: ???  *  * We will try to include all headers possible under this configuration.  *  * MSVC does not define __SSE2__& family, so we will define them. MSVC 2013&  * up do define __AVX__ if the -arch:AVX option is passed on the command-line.  *  * Supported XXX are:  *   Flag    | Arch |  GCC  | Intel CC |  MSVC  |  *  ARM_NEON | ARM  | I& C | None     |   ?    |  *  SSE2     | x86  | I& C | I& C    | I& C  |  *  SSE3     | x86  | I& C | I& C    | I only |  *  SSSE3    | x86  | I& C | I& C    | I only |  *  SSE4_1   | x86  | I& C | I& C    | I only |  *  SSE4_2   | x86  | I& C | I& C    | I only |  *  AVX      | x86  | I& C | I& C    | I& C  |  *  AVX2     | x86  | I& C | I& C    | I only |  *  AVX512xx | x86  | I& C | I& C    | I only |  * I = intrinsics; C = code generation  *  * Code can use the following constructs to determine compiler support& status:  * - #ifdef __XXX__      (e.g: #ifdef __AVX__  or #ifdef __ARM_NEON__)  *   If this test passes, then the compiler is already generating code for that  *   given sub-architecture. The intrinsics for that sub-architecture are  *   #included and can be used without restriction or runtime check.  *  * - #if QT_COMPILER_SUPPORTS(XXX)  *   If this test passes, then the compiler is able to generate code for that  *   given sub-architecture in another translation unit, given the right set of  *   flags. Use of the intrinsics is not guaranteed. This is useful with  *   runtime detection (see below).  *  * - #if QT_COMPILER_SUPPORTS_HERE(XXX)  *   If this test passes, then the compiler is able to generate code for that  *   given sub-architecture in this translation unit, even if it is not doing  *   that now (it might be). Individual functions may be tagged with  *   QT_FUNCTION_TARGET(XXX) to cause the compiler to generate code for that  *   sub-arch. Only inside such functions is the use of the intrisics  *   guaranteed to work. This is useful with runtime detection (see below).  *  * Runtime detection of a CPU sub-architecture can be done with the  * qCpuHasFeature(XXX) function. There are two strategies for generating  * optimized code like that:  *  * 1) place the optimized code in a different translation unit (C or assembly  * sources) and pass the correct flags to the compiler to enable support. Those  * sources must not include qglobal.h, which means they cannot include this  * file either. The dispatcher function would look like this:  *  *      void foo()  *      {  *      #if QT_COMPILER_SUPPORTS(XXX)  *          if (qCpuHasFeature(XXX)) {  *              foo_optimized_xxx();  *              return;  *          }  *      #endif  *          foo_plain();  *      }  *  * 2) place the optimized code in a function tagged with QT_FUNCTION_TARGET and  * surrounded by #if QT_COMPILER_SUPPORTS_HERE(XXX). That code can freely use  * other Qt code. The dispatcher function would look like this:  *  *      void foo()  *      {  *      #if QT_COMPILER_SUPPORTS_HERE(XXX)  *          if (qCpuHasFeature(XXX)) {  *              foo_optimized_xxx();  *              return;  *          }  *      #endif  *          foo_plain();  *      }  */
end_comment
begin_if
if|#
directive|if
name|defined
argument_list|(
name|__MINGW64_VERSION_MAJOR
argument_list|)
operator|||
operator|(
name|defined
argument_list|(
name|Q_CC_MSVC
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|Q_OS_WINCE
argument_list|)
operator|)
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
begin_define
DECL|macro|QT_COMPILER_SUPPORTS
define|#
directive|define
name|QT_COMPILER_SUPPORTS
parameter_list|(
name|x
parameter_list|)
value|(QT_COMPILER_SUPPORTS_ ## x - 0)
end_define
begin_if
if|#
directive|if
name|defined
argument_list|(
name|Q_PROCESSOR_ARM
argument_list|)
end_if
begin_define
DECL|macro|QT_COMPILER_SUPPORTS_HERE
define|#
directive|define
name|QT_COMPILER_SUPPORTS_HERE
parameter_list|(
name|x
parameter_list|)
value|(__ARM_FEATURE_ ## x)
end_define
begin_if
if|#
directive|if
name|defined
argument_list|(
name|Q_CC_GNU
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|Q_CC_INTEL
argument_list|)
operator|&&
name|Q_CC_GNU
operator|>=
literal|600
end_if
begin_comment
comment|/* GCC requires attributes for a function */
end_comment
begin_define
DECL|macro|QT_FUNCTION_TARGET
define|#
directive|define
name|QT_FUNCTION_TARGET
parameter_list|(
name|x
parameter_list|)
value|__attribute__((__target__(QT_FUNCTION_TARGET_STRING_ ## x)))
end_define
begin_else
else|#
directive|else
end_else
begin_define
DECL|macro|QT_FUNCTION_TARGET
define|#
directive|define
name|QT_FUNCTION_TARGET
parameter_list|(
name|x
parameter_list|)
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|__ARM_FEATURE_NEON
argument_list|)
operator|&&
name|defined
argument_list|(
name|__ARM_NEON__
argument_list|)
end_if
begin_define
DECL|macro|__ARM_FEATURE_NEON
define|#
directive|define
name|__ARM_FEATURE_NEON
end_define
begin_comment
DECL|macro|__ARM_FEATURE_NEON
comment|// also support QT_COMPILER_SUPPORTS_HERE(NEON)
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_elif
elif|#
directive|elif
operator|(
name|defined
argument_list|(
name|Q_CC_INTEL
argument_list|)
operator|||
name|defined
argument_list|(
name|Q_CC_MSVC
argument_list|)
expr|\
operator|||
operator|(
name|defined
argument_list|(
name|Q_CC_GNU
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|Q_CC_CLANG
argument_list|)
operator|&&
operator|(
name|__GNUC__
operator|-
literal|0
operator|)
operator|*
literal|100
operator|+
operator|(
name|__GNUC_MINOR__
operator|-
literal|0
operator|)
operator|>=
literal|409
operator|)
operator|)
expr|\
operator|&&
operator|!
name|defined
argument_list|(
name|QT_BOOTSTRAPPED
argument_list|)
end_elif
begin_define
DECL|macro|QT_COMPILER_SUPPORTS_SIMD_ALWAYS
define|#
directive|define
name|QT_COMPILER_SUPPORTS_SIMD_ALWAYS
end_define
begin_define
DECL|macro|QT_COMPILER_SUPPORTS_HERE
define|#
directive|define
name|QT_COMPILER_SUPPORTS_HERE
parameter_list|(
name|x
parameter_list|)
value|QT_COMPILER_SUPPORTS(x)
end_define
begin_if
if|#
directive|if
name|defined
argument_list|(
name|Q_CC_GNU
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|Q_CC_INTEL
argument_list|)
end_if
begin_comment
comment|/* GCC requires attributes for a function */
end_comment
begin_define
DECL|macro|QT_FUNCTION_TARGET
define|#
directive|define
name|QT_FUNCTION_TARGET
parameter_list|(
name|x
parameter_list|)
value|__attribute__((__target__(QT_FUNCTION_TARGET_STRING_ ## x)))
end_define
begin_else
else|#
directive|else
end_else
begin_define
DECL|macro|QT_FUNCTION_TARGET
define|#
directive|define
name|QT_FUNCTION_TARGET
parameter_list|(
name|x
parameter_list|)
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_else
else|#
directive|else
end_else
begin_define
DECL|macro|QT_COMPILER_SUPPORTS_HERE
define|#
directive|define
name|QT_COMPILER_SUPPORTS_HERE
parameter_list|(
name|x
parameter_list|)
value|(__ ## x ## __)
end_define
begin_define
DECL|macro|QT_FUNCTION_TARGET
define|#
directive|define
name|QT_FUNCTION_TARGET
parameter_list|(
name|x
parameter_list|)
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// SSE intrinsics
end_comment
begin_define
DECL|macro|QT_FUNCTION_TARGET_STRING_SSE2
define|#
directive|define
name|QT_FUNCTION_TARGET_STRING_SSE2
value|"sse2"
end_define
begin_if
if|#
directive|if
name|defined
argument_list|(
name|__SSE2__
argument_list|)
operator|||
operator|(
name|defined
argument_list|(
name|QT_COMPILER_SUPPORTS_SSE2
argument_list|)
operator|&&
name|defined
argument_list|(
name|QT_COMPILER_SUPPORTS_SIMD_ALWAYS
argument_list|)
operator|)
end_if
begin_if
if|#
directive|if
name|defined
argument_list|(
name|QT_LINUXBASE
argument_list|)
operator|||
name|defined
argument_list|(
name|Q_OS_ANDROID_NO_SDK
argument_list|)
end_if
begin_comment
comment|/// this is an evil hack - the posix_memalign declaration in LSB
end_comment
begin_comment
comment|/// is wrong - see http://bugs.linuxbase.org/show_bug.cgi?id=2431
end_comment
begin_define
DECL|macro|posix_memalign
define|#
directive|define
name|posix_memalign
value|_lsb_hack_posix_memalign
end_define
begin_include
include|#
directive|include
file|<emmintrin.h>
end_include
begin_undef
DECL|macro|posix_memalign
undef|#
directive|undef
name|posix_memalign
end_undef
begin_else
else|#
directive|else
end_else
begin_include
include|#
directive|include
file|<emmintrin.h>
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
name|Q_CC_MSVC
argument_list|)
operator|&&
operator|(
name|defined
argument_list|(
name|_M_X64
argument_list|)
operator|||
name|_M_IX86_FP
operator|>=
literal|2
operator|)
end_if
begin_define
DECL|macro|__SSE__
define|#
directive|define
name|__SSE__
value|1
end_define
begin_define
DECL|macro|__SSE2__
define|#
directive|define
name|__SSE2__
value|1
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// SSE3 intrinsics
end_comment
begin_define
DECL|macro|QT_FUNCTION_TARGET_STRING_SSE3
define|#
directive|define
name|QT_FUNCTION_TARGET_STRING_SSE3
value|"sse3"
end_define
begin_if
if|#
directive|if
name|defined
argument_list|(
name|__SSE3__
argument_list|)
operator|||
operator|(
name|defined
argument_list|(
name|QT_COMPILER_SUPPORTS_SSE3
argument_list|)
operator|&&
name|defined
argument_list|(
name|QT_COMPILER_SUPPORTS_SIMD_ALWAYS
argument_list|)
operator|)
end_if
begin_include
include|#
directive|include
file|<pmmintrin.h>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// SSSE3 intrinsics
end_comment
begin_define
DECL|macro|QT_FUNCTION_TARGET_STRING_SSSE3
define|#
directive|define
name|QT_FUNCTION_TARGET_STRING_SSSE3
value|"ssse3"
end_define
begin_if
if|#
directive|if
name|defined
argument_list|(
name|__SSSE3__
argument_list|)
operator|||
operator|(
name|defined
argument_list|(
name|QT_COMPILER_SUPPORTS_SSSE3
argument_list|)
operator|&&
name|defined
argument_list|(
name|QT_COMPILER_SUPPORTS_SIMD_ALWAYS
argument_list|)
operator|)
end_if
begin_include
include|#
directive|include
file|<tmmintrin.h>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// SSE4.1 intrinsics
end_comment
begin_define
DECL|macro|QT_FUNCTION_TARGET_STRING_SSE4_1
define|#
directive|define
name|QT_FUNCTION_TARGET_STRING_SSE4_1
value|"sse4.1"
end_define
begin_if
if|#
directive|if
name|defined
argument_list|(
name|__SSE4_1__
argument_list|)
operator|||
operator|(
name|defined
argument_list|(
name|QT_COMPILER_SUPPORTS_SSE4_1
argument_list|)
operator|&&
name|defined
argument_list|(
name|QT_COMPILER_SUPPORTS_SIMD_ALWAYS
argument_list|)
operator|)
end_if
begin_include
include|#
directive|include
file|<smmintrin.h>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// SSE4.2 intrinsics
end_comment
begin_define
DECL|macro|QT_FUNCTION_TARGET_STRING_SSE4_2
define|#
directive|define
name|QT_FUNCTION_TARGET_STRING_SSE4_2
value|"sse4.2"
end_define
begin_if
if|#
directive|if
name|defined
argument_list|(
name|__SSE4_2__
argument_list|)
operator|||
operator|(
name|defined
argument_list|(
name|QT_COMPILER_SUPPORTS_SSE4_2
argument_list|)
operator|&&
name|defined
argument_list|(
name|QT_COMPILER_SUPPORTS_SIMD_ALWAYS
argument_list|)
operator|)
end_if
begin_include
include|#
directive|include
file|<nmmintrin.h>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// AVX intrinsics
end_comment
begin_define
DECL|macro|QT_FUNCTION_TARGET_STRING_AVX
define|#
directive|define
name|QT_FUNCTION_TARGET_STRING_AVX
value|"avx"
end_define
begin_define
DECL|macro|QT_FUNCTION_TARGET_STRING_AVX2
define|#
directive|define
name|QT_FUNCTION_TARGET_STRING_AVX2
value|"avx2"
end_define
begin_if
if|#
directive|if
name|defined
argument_list|(
name|__AVX__
argument_list|)
operator|||
operator|(
name|defined
argument_list|(
name|QT_COMPILER_SUPPORTS_AVX
argument_list|)
operator|&&
name|defined
argument_list|(
name|QT_COMPILER_SUPPORTS_SIMD_ALWAYS
argument_list|)
operator|)
end_if
begin_comment
comment|// immintrin.h is the ultimate header, we don't need anything else after this
end_comment
begin_include
include|#
directive|include
file|<immintrin.h>
end_include
begin_if
if|#
directive|if
name|defined
argument_list|(
name|Q_CC_MSVC
argument_list|)
operator|&&
operator|(
name|defined
argument_list|(
name|_M_AVX
argument_list|)
operator|||
name|defined
argument_list|(
name|__AVX__
argument_list|)
operator|)
end_if
begin_comment
comment|// MS Visual Studio 2010 has no macro pre-defined to identify the use of /arch:AVX
end_comment
begin_comment
comment|// MS Visual Studio 2013 adds it: __AVX__
end_comment
begin_comment
comment|// See: http://connect.microsoft.com/VisualStudio/feedback/details/605858/arch-avx-should-define-a-predefined-macro-in-x64-and-set-a-unique-value-for-m-ix86-fp-in-win32
end_comment
begin_define
DECL|macro|__SSE3__
define|#
directive|define
name|__SSE3__
value|1
end_define
begin_define
DECL|macro|__SSSE3__
define|#
directive|define
name|__SSSE3__
value|1
end_define
begin_comment
comment|// no Intel CPU supports SSE4a, so don't define it
end_comment
begin_define
DECL|macro|__SSE4_1__
define|#
directive|define
name|__SSE4_1__
value|1
end_define
begin_define
DECL|macro|__SSE4_2__
define|#
directive|define
name|__SSE4_2__
value|1
end_define
begin_ifndef
ifndef|#
directive|ifndef
name|__AVX__
end_ifndef
begin_define
DECL|macro|__AVX__
define|#
directive|define
name|__AVX__
value|1
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_endif
endif|#
directive|endif
end_endif
begin_endif
endif|#
directive|endif
end_endif
begin_define
DECL|macro|QT_FUNCTION_TARGET_STRING_AVX512F
define|#
directive|define
name|QT_FUNCTION_TARGET_STRING_AVX512F
value|"avx512f"
end_define
begin_define
DECL|macro|QT_FUNCTION_TARGET_STRING_AVX512CD
define|#
directive|define
name|QT_FUNCTION_TARGET_STRING_AVX512CD
value|"avx512cd"
end_define
begin_define
DECL|macro|QT_FUNCTION_TARGET_STRING_AVX512ER
define|#
directive|define
name|QT_FUNCTION_TARGET_STRING_AVX512ER
value|"avx512er"
end_define
begin_define
DECL|macro|QT_FUNCTION_TARGET_STRING_AVX512PF
define|#
directive|define
name|QT_FUNCTION_TARGET_STRING_AVX512PF
value|"avx512pf"
end_define
begin_define
DECL|macro|QT_FUNCTION_TARGET_STRING_AVX512BW
define|#
directive|define
name|QT_FUNCTION_TARGET_STRING_AVX512BW
value|"avx512bw"
end_define
begin_define
DECL|macro|QT_FUNCTION_TARGET_STRING_AVX512DQ
define|#
directive|define
name|QT_FUNCTION_TARGET_STRING_AVX512DQ
value|"avx512dq"
end_define
begin_define
DECL|macro|QT_FUNCTION_TARGET_STRING_AVX512VL
define|#
directive|define
name|QT_FUNCTION_TARGET_STRING_AVX512VL
value|"avx512vl"
end_define
begin_define
DECL|macro|QT_FUNCTION_TARGET_STRING_AVX512IFMA
define|#
directive|define
name|QT_FUNCTION_TARGET_STRING_AVX512IFMA
value|"avx512ifma"
end_define
begin_define
DECL|macro|QT_FUNCTION_TARGET_STRING_AVX512VBMI
define|#
directive|define
name|QT_FUNCTION_TARGET_STRING_AVX512VBMI
value|"avx512vbmi"
end_define
begin_define
DECL|macro|QT_FUNCTION_TARGET_STRING_F16C
define|#
directive|define
name|QT_FUNCTION_TARGET_STRING_F16C
value|"f16c"
end_define
begin_define
DECL|macro|QT_FUNCTION_TARGET_STRING_RDRAND
define|#
directive|define
name|QT_FUNCTION_TARGET_STRING_RDRAND
value|"rdrnd"
end_define
begin_define
DECL|macro|QT_FUNCTION_TARGET_STRING_BMI
define|#
directive|define
name|QT_FUNCTION_TARGET_STRING_BMI
value|"bmi"
end_define
begin_define
DECL|macro|QT_FUNCTION_TARGET_STRING_BMI2
define|#
directive|define
name|QT_FUNCTION_TARGET_STRING_BMI2
value|"bmi2"
end_define
begin_define
DECL|macro|QT_FUNCTION_TARGET_STRING_RDSEED
define|#
directive|define
name|QT_FUNCTION_TARGET_STRING_RDSEED
value|"rdseed"
end_define
begin_define
DECL|macro|QT_FUNCTION_TARGET_STRING_SHA
define|#
directive|define
name|QT_FUNCTION_TARGET_STRING_SHA
value|"sha"
end_define
begin_comment
comment|// other x86 intrinsics
end_comment
begin_if
if|#
directive|if
name|defined
argument_list|(
name|Q_PROCESSOR_X86
argument_list|)
operator|&&
operator|(
operator|(
name|defined
argument_list|(
name|Q_CC_GNU
argument_list|)
operator|&&
operator|(
name|Q_CC_GNU
operator|>=
literal|404
operator|)
operator|)
expr|\
operator|||
operator|(
name|defined
argument_list|(
name|Q_CC_CLANG
argument_list|)
operator|&&
operator|(
name|Q_CC_CLANG
operator|>=
literal|208
operator|)
operator|)
expr|\
operator|||
name|defined
argument_list|(
name|Q_CC_INTEL
argument_list|)
operator|)
end_if
begin_define
DECL|macro|QT_COMPILER_SUPPORTS_X86INTRIN
define|#
directive|define
name|QT_COMPILER_SUPPORTS_X86INTRIN
end_define
begin_ifdef
ifdef|#
directive|ifdef
name|Q_CC_INTEL
end_ifdef
begin_comment
comment|// The Intel compiler has no<x86intrin.h> -- all intrinsics are in<immintrin.h>;
end_comment
begin_include
include|#
directive|include
file|<immintrin.h>
end_include
begin_else
else|#
directive|else
end_else
begin_comment
comment|// GCC 4.4 and Clang 2.8 added a few more intrinsics there
end_comment
begin_include
include|#
directive|include
file|<x86intrin.h>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// NEON intrinsics
end_comment
begin_comment
comment|// note: as of GCC 4.9, does not support function targets for ARM
end_comment
begin_if
if|#
directive|if
name|defined
argument_list|(
name|__ARM_NEON
argument_list|)
operator|||
name|defined
argument_list|(
name|__ARM_NEON__
argument_list|)
end_if
begin_include
include|#
directive|include
file|<arm_neon.h>
end_include
begin_define
DECL|macro|QT_FUNCTION_TARGET_STRING_NEON
define|#
directive|define
name|QT_FUNCTION_TARGET_STRING_NEON
value|"+neon"
end_define
begin_comment
DECL|macro|QT_FUNCTION_TARGET_STRING_NEON
comment|// unused: gcc doesn't support function targets on non-aarch64, and on Aarch64 NEON is always available.
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|__ARM_NEON__
end_ifndef
begin_comment
comment|// __ARM_NEON__ is not defined on AArch64, but we need it in our NEON detection.
end_comment
begin_define
DECL|macro|__ARM_NEON__
define|#
directive|define
name|__ARM_NEON__
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// AArch64/ARM64
end_comment
begin_if
if|#
directive|if
name|defined
argument_list|(
name|Q_PROCESSOR_ARM_V8
argument_list|)
end_if
begin_define
DECL|macro|QT_FUNCTION_TARGET_STRING_CRC32
define|#
directive|define
name|QT_FUNCTION_TARGET_STRING_CRC32
value|"+crc"
end_define
begin_include
include|#
directive|include
file|<arm_acle.h>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_undef
DECL|macro|QT_COMPILER_SUPPORTS_SIMD_ALWAYS
undef|#
directive|undef
name|QT_COMPILER_SUPPORTS_SIMD_ALWAYS
end_undef
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|enum|CPUFeatures
name|enum
name|CPUFeatures
block|{
if|#
directive|if
name|defined
argument_list|(
name|Q_PROCESSOR_ARM
argument_list|)
DECL|enumerator|CpuFeatureNEON
name|CpuFeatureNEON
operator|=
literal|0
operator|,
DECL|enumerator|CpuFeatureARM_NEON
name|CpuFeatureARM_NEON
operator|=
name|CpuFeatureNEON
operator|,
DECL|enumerator|CpuFeatureCRC32
name|CpuFeatureCRC32
operator|=
literal|1
operator|,
elif|#
directive|elif
name|defined
argument_list|(
name|Q_PROCESSOR_MIPS
argument_list|)
name|CpuFeatureDSP
operator|=
literal|0
operator|,
name|CpuFeatureDSPR2
operator|=
literal|1
operator|,
elif|#
directive|elif
name|defined
argument_list|(
name|Q_PROCESSOR_X86
argument_list|)
comment|// The order of the flags is jumbled so it matches most closely the bits in CPUID
comment|// Out of order:
name|CpuFeatureSSE2
operator|=
literal|1
operator|,
comment|// uses the bit for PCLMULQDQ
comment|// in level 1, ECX
name|CpuFeatureSSE3
operator|=
operator|(
literal|0
operator|+
literal|0
operator|)
operator|,
name|CpuFeatureSSSE3
operator|=
operator|(
literal|0
operator|+
literal|9
operator|)
operator|,
name|CpuFeatureSSE4_1
operator|=
operator|(
literal|0
operator|+
literal|19
operator|)
operator|,
name|CpuFeatureSSE4_2
operator|=
operator|(
literal|0
operator|+
literal|20
operator|)
operator|,
name|CpuFeatureMOVBE
operator|=
operator|(
literal|0
operator|+
literal|22
operator|)
operator|,
name|CpuFeaturePOPCNT
operator|=
operator|(
literal|0
operator|+
literal|23
operator|)
operator|,
name|CpuFeatureAES
operator|=
operator|(
literal|0
operator|+
literal|25
operator|)
operator|,
name|CpuFeatureAVX
operator|=
operator|(
literal|0
operator|+
literal|28
operator|)
operator|,
name|CpuFeatureF16C
operator|=
operator|(
literal|0
operator|+
literal|29
operator|)
operator|,
name|CpuFeatureRDRAND
operator|=
operator|(
literal|0
operator|+
literal|30
operator|)
operator|,
comment|// 31 is always zero and we've used it for the QSimdInitialized
comment|// in level 7, leaf 0, EBX
name|CpuFeatureBMI
operator|=
operator|(
literal|32
operator|+
literal|3
operator|)
operator|,
name|CpuFeatureHLE
operator|=
operator|(
literal|32
operator|+
literal|4
operator|)
operator|,
name|CpuFeatureAVX2
operator|=
operator|(
literal|32
operator|+
literal|5
operator|)
operator|,
name|CpuFeatureBMI2
operator|=
operator|(
literal|32
operator|+
literal|8
operator|)
operator|,
name|CpuFeatureRTM
operator|=
operator|(
literal|32
operator|+
literal|11
operator|)
operator|,
name|CpuFeatureAVX512F
operator|=
operator|(
literal|32
operator|+
literal|16
operator|)
operator|,
name|CpuFeatureAVX512DQ
operator|=
operator|(
literal|32
operator|+
literal|17
operator|)
operator|,
name|CpuFeatureRDSEED
operator|=
operator|(
literal|32
operator|+
literal|18
operator|)
operator|,
name|CpuFeatureAVX512IFMA
operator|=
operator|(
literal|32
operator|+
literal|21
operator|)
operator|,
name|CpuFeatureAVX512PF
operator|=
operator|(
literal|32
operator|+
literal|26
operator|)
operator|,
name|CpuFeatureAVX512ER
operator|=
operator|(
literal|32
operator|+
literal|27
operator|)
operator|,
name|CpuFeatureAVX512CD
operator|=
operator|(
literal|32
operator|+
literal|28
operator|)
operator|,
name|CpuFeatureSHA
operator|=
operator|(
literal|32
operator|+
literal|29
operator|)
operator|,
name|CpuFeatureAVX512BW
operator|=
operator|(
literal|32
operator|+
literal|30
operator|)
operator|,
name|CpuFeatureAVX512VL
operator|=
operator|(
literal|32
operator|+
literal|31
operator|)
operator|,
comment|// in level 7, leaf 0, ECX (out of order, for now)
name|CpuFeatureAVX512VBMI
operator|=
literal|2
operator|,
comment|// uses the bit for DTES64
endif|#
directive|endif
comment|// used only to indicate that the CPU detection was initialised
DECL|enumerator|QSimdInitialized
name|QSimdInitialized
operator|=
literal|0x80000000
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_decl_stmt
DECL|variable|qCompilerCpuFeatures
specifier|static
specifier|const
name|quint64
name|qCompilerCpuFeatures
init|=
literal|0
if|#
directive|if
name|defined
name|__SHA__
operator||
operator|(
name|Q_UINT64_C
argument_list|(
literal|1
argument_list|)
operator|<<
name|CpuFeatureSHA
operator|)
endif|#
directive|endif
if|#
directive|if
name|defined
name|__AES__
operator||
operator|(
name|Q_UINT64_C
argument_list|(
literal|1
argument_list|)
operator|<<
name|CpuFeatureAES
operator|)
endif|#
directive|endif
if|#
directive|if
name|defined
name|__RTM__
operator||
operator|(
name|Q_UINT64_C
argument_list|(
literal|1
argument_list|)
operator|<<
name|CpuFeatureRTM
operator|)
endif|#
directive|endif
ifdef|#
directive|ifdef
name|__RDRND__
operator||
operator|(
name|Q_UINT64_C
argument_list|(
literal|1
argument_list|)
operator|<<
name|CpuFeatureRDRAND
operator|)
endif|#
directive|endif
ifdef|#
directive|ifdef
name|__RDSEED__
operator||
operator|(
name|Q_UINT64_C
argument_list|(
literal|1
argument_list|)
operator|<<
name|CpuFeatureRDSEED
operator|)
endif|#
directive|endif
if|#
directive|if
name|defined
name|__BMI__
operator||
operator|(
name|Q_UINT64_C
argument_list|(
literal|1
argument_list|)
operator|<<
name|CpuFeatureBMI
operator|)
endif|#
directive|endif
if|#
directive|if
name|defined
name|__BMI2__
operator||
operator|(
name|Q_UINT64_C
argument_list|(
literal|1
argument_list|)
operator|<<
name|CpuFeatureBMI2
operator|)
endif|#
directive|endif
if|#
directive|if
name|defined
name|__F16C__
operator||
operator|(
name|Q_UINT64_C
argument_list|(
literal|1
argument_list|)
operator|<<
name|CpuFeatureF16C
operator|)
endif|#
directive|endif
if|#
directive|if
name|defined
name|__POPCNT__
operator||
operator|(
name|Q_UINT64_C
argument_list|(
literal|1
argument_list|)
operator|<<
name|CpuFeaturePOPCNT
operator|)
endif|#
directive|endif
if|#
directive|if
name|defined
name|__MOVBE__
comment|// GCC and Clang don't seem to define this
operator||
operator|(
name|Q_UINT64_C
argument_list|(
literal|1
argument_list|)
operator|<<
name|CpuFeatureMOVBE
operator|)
endif|#
directive|endif
if|#
directive|if
name|defined
name|__AVX512F__
operator||
operator|(
name|Q_UINT64_C
argument_list|(
literal|1
argument_list|)
operator|<<
name|CpuFeatureAVX512F
operator|)
endif|#
directive|endif
if|#
directive|if
name|defined
name|__AVX512CD__
operator||
operator|(
name|Q_UINT64_C
argument_list|(
literal|1
argument_list|)
operator|<<
name|CpuFeatureAVX512CD
operator|)
endif|#
directive|endif
if|#
directive|if
name|defined
name|__AVX512ER__
operator||
operator|(
name|Q_UINT64_C
argument_list|(
literal|1
argument_list|)
operator|<<
name|CpuFeatureAVX512ER
operator|)
endif|#
directive|endif
if|#
directive|if
name|defined
name|__AVX512PF__
operator||
operator|(
name|Q_UINT64_C
argument_list|(
literal|1
argument_list|)
operator|<<
name|CpuFeatureAVX512PF
operator|)
endif|#
directive|endif
if|#
directive|if
name|defined
name|__AVX512BW__
operator||
operator|(
name|Q_UINT64_C
argument_list|(
literal|1
argument_list|)
operator|<<
name|CpuFeatureAVX512BW
operator|)
endif|#
directive|endif
if|#
directive|if
name|defined
name|__AVX512DQ__
operator||
operator|(
name|Q_UINT64_C
argument_list|(
literal|1
argument_list|)
operator|<<
name|CpuFeatureAVX512DQ
operator|)
endif|#
directive|endif
if|#
directive|if
name|defined
name|__AVX512VL__
operator||
operator|(
name|Q_UINT64_C
argument_list|(
literal|1
argument_list|)
operator|<<
name|CpuFeatureAVX512VL
operator|)
endif|#
directive|endif
if|#
directive|if
name|defined
name|__AVX512IFMA__
operator||
operator|(
name|Q_UINT64_C
argument_list|(
literal|1
argument_list|)
operator|<<
name|CpuFeatureAVX512IFMA
operator|)
endif|#
directive|endif
if|#
directive|if
name|defined
name|__AVX512VBMI__
operator||
operator|(
name|Q_UINT64_C
argument_list|(
literal|1
argument_list|)
operator|<<
name|CpuFeatureAVX512VBMI
operator|)
endif|#
directive|endif
if|#
directive|if
name|defined
name|__AVX2__
operator||
operator|(
name|Q_UINT64_C
argument_list|(
literal|1
argument_list|)
operator|<<
name|CpuFeatureAVX2
operator|)
endif|#
directive|endif
if|#
directive|if
name|defined
name|__AVX__
operator||
operator|(
name|Q_UINT64_C
argument_list|(
literal|1
argument_list|)
operator|<<
name|CpuFeatureAVX
operator|)
endif|#
directive|endif
if|#
directive|if
name|defined
name|__SSE4_2__
operator||
operator|(
name|Q_UINT64_C
argument_list|(
literal|1
argument_list|)
operator|<<
name|CpuFeatureSSE4_2
operator|)
endif|#
directive|endif
if|#
directive|if
name|defined
name|__SSE4_1__
operator||
operator|(
name|Q_UINT64_C
argument_list|(
literal|1
argument_list|)
operator|<<
name|CpuFeatureSSE4_1
operator|)
endif|#
directive|endif
if|#
directive|if
name|defined
name|__SSSE3__
operator||
operator|(
name|Q_UINT64_C
argument_list|(
literal|1
argument_list|)
operator|<<
name|CpuFeatureSSSE3
operator|)
endif|#
directive|endif
if|#
directive|if
name|defined
name|__SSE3__
operator||
operator|(
name|Q_UINT64_C
argument_list|(
literal|1
argument_list|)
operator|<<
name|CpuFeatureSSE3
operator|)
endif|#
directive|endif
if|#
directive|if
name|defined
name|__SSE2__
operator||
operator|(
name|Q_UINT64_C
argument_list|(
literal|1
argument_list|)
operator|<<
name|CpuFeatureSSE2
operator|)
endif|#
directive|endif
if|#
directive|if
name|defined
name|__ARM_NEON__
operator||
operator|(
name|Q_UINT64_C
argument_list|(
literal|1
argument_list|)
operator|<<
name|CpuFeatureNEON
operator|)
endif|#
directive|endif
if|#
directive|if
name|defined
name|__ARM_FEATURE_CRC32
operator||
operator|(
name|Q_UINT64_C
argument_list|(
literal|1
argument_list|)
operator|<<
name|CpuFeatureCRC32
operator|)
endif|#
directive|endif
if|#
directive|if
name|defined
name|__mips_dsp
operator||
operator|(
name|Q_UINT64_C
argument_list|(
literal|1
argument_list|)
operator|<<
name|CpuFeatureDSP
operator|)
endif|#
directive|endif
if|#
directive|if
name|defined
name|__mips_dspr2
operator||
operator|(
name|Q_UINT64_C
argument_list|(
literal|1
argument_list|)
operator|<<
name|CpuFeatureDSPR2
operator|)
endif|#
directive|endif
decl_stmt|;
end_decl_stmt
begin_ifdef
ifdef|#
directive|ifdef
name|Q_ATOMIC_INT64_IS_SUPPORTED
end_ifdef
begin_extern
extern|extern Q_CORE_EXPORT QBasicAtomicInteger<quint64> qt_cpu_features[1];
end_extern
begin_else
else|#
directive|else
end_else
begin_extern
extern|extern Q_CORE_EXPORT QBasicAtomicInteger<unsigned> qt_cpu_features[2];
end_extern
begin_endif
endif|#
directive|endif
end_endif
begin_function_decl
name|Q_CORE_EXPORT
name|void
name|qDetectCpuFeatures
parameter_list|()
function_decl|;
end_function_decl
begin_function
DECL|function|qCpuFeatures
specifier|static
specifier|inline
name|quint64
name|qCpuFeatures
parameter_list|()
block|{
name|quint64
name|features
init|=
name|qt_cpu_features
index|[
literal|0
index|]
operator|.
name|load
argument_list|()
decl_stmt|;
ifndef|#
directive|ifndef
name|Q_ATOMIC_INT64_IS_SUPPORTED
name|features
operator||=
name|quint64
argument_list|(
name|qt_cpu_features
index|[
literal|1
index|]
operator|.
name|load
argument_list|()
argument_list|)
operator|<<
literal|32
expr_stmt|;
endif|#
directive|endif
if|if
condition|(
name|Q_UNLIKELY
argument_list|(
name|features
operator|==
literal|0
argument_list|)
condition|)
block|{
name|qDetectCpuFeatures
argument_list|()
expr_stmt|;
name|features
operator|=
name|qt_cpu_features
index|[
literal|0
index|]
operator|.
name|load
argument_list|()
expr_stmt|;
ifndef|#
directive|ifndef
name|Q_ATOMIC_INT64_IS_SUPPORTED
name|features
operator||=
name|quint64
argument_list|(
name|qt_cpu_features
index|[
literal|1
index|]
operator|.
name|load
argument_list|()
argument_list|)
operator|<<
literal|32
expr_stmt|;
endif|#
directive|endif
name|Q_ASSUME
argument_list|(
name|features
operator|!=
literal|0
argument_list|)
expr_stmt|;
block|}
return|return
name|features
return|;
block|}
end_function
begin_define
DECL|macro|qCpuHasFeature
define|#
directive|define
name|qCpuHasFeature
parameter_list|(
name|feature
parameter_list|)
value|((qCompilerCpuFeatures& (Q_UINT64_C(1)<< CpuFeature ## feature)) \                                      || (qCpuFeatures()& (Q_UINT64_C(1)<< CpuFeature ## feature)))
end_define
begin_if
if|#
directive|if
name|QT_HAS_BUILTIN
argument_list|(
name|__builtin_clz
argument_list|)
operator|&&
name|QT_HAS_BUILTIN
argument_list|(
name|__builtin_ctz
argument_list|)
operator|&&
name|defined
argument_list|(
name|Q_CC_CLANG
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|Q_CC_INTEL
argument_list|)
end_if
begin_function
DECL|function|_bit_scan_reverse
specifier|static
name|Q_ALWAYS_INLINE
name|unsigned
name|_bit_scan_reverse
parameter_list|(
name|unsigned
name|val
parameter_list|)
block|{
name|Q_ASSERT
argument_list|(
name|val
operator|!=
literal|0
argument_list|)
expr_stmt|;
comment|// if val==0, the result is undefined.
name|unsigned
name|result
init|=
name|static_cast
operator|<
name|unsigned
operator|>
operator|(
name|__builtin_clz
argument_list|(
name|val
argument_list|)
operator|)
decl_stmt|;
comment|// Count Leading Zeros
comment|// Now Invert the result: clz will count *down* from the msb to the lsb, so the msb index is 31
comment|// and the lsb inde is 0. The result for _bit_scan_reverse is expected to be the index when
comment|// counting up: msb index is 0 (because it starts there), and the lsb index is 31.
name|result
operator|^=
sizeof|sizeof
argument_list|(
name|unsigned
argument_list|)
operator|*
literal|8
operator|-
literal|1
expr_stmt|;
return|return
name|result
return|;
block|}
end_function
begin_function
DECL|function|_bit_scan_forward
specifier|static
name|Q_ALWAYS_INLINE
name|unsigned
name|_bit_scan_forward
parameter_list|(
name|unsigned
name|val
parameter_list|)
block|{
name|Q_ASSERT
argument_list|(
name|val
operator|!=
literal|0
argument_list|)
expr_stmt|;
comment|// if val==0, the result is undefined.
return|return
name|static_cast
operator|<
name|unsigned
operator|>
operator|(
name|__builtin_ctz
argument_list|(
name|val
argument_list|)
operator|)
return|;
comment|// Count Trailing Zeros
block|}
end_function
begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|Q_PROCESSOR_X86
argument_list|)
end_elif
begin_comment
comment|// Bit scan functions for x86
end_comment
begin_if
if|#
directive|if
name|defined
argument_list|(
name|Q_CC_MSVC
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|Q_OS_WINCE
argument_list|)
end_if
begin_comment
comment|// MSVC calls it _BitScanReverse and returns the carry flag, which we don't need
end_comment
begin_function
DECL|function|_bit_scan_reverse
specifier|static
name|__forceinline
name|unsigned
name|long
name|_bit_scan_reverse
parameter_list|(
name|uint
name|val
parameter_list|)
block|{
name|unsigned
name|long
name|result
decl_stmt|;
name|_BitScanReverse
argument_list|(
operator|&
name|result
argument_list|,
name|val
argument_list|)
expr_stmt|;
return|return
name|result
return|;
block|}
end_function
begin_function
DECL|function|_bit_scan_forward
specifier|static
name|__forceinline
name|unsigned
name|long
name|_bit_scan_forward
parameter_list|(
name|uint
name|val
parameter_list|)
block|{
name|unsigned
name|long
name|result
decl_stmt|;
name|_BitScanForward
argument_list|(
operator|&
name|result
argument_list|,
name|val
argument_list|)
expr_stmt|;
return|return
name|result
return|;
block|}
end_function
begin_elif
elif|#
directive|elif
operator|(
name|defined
argument_list|(
name|Q_CC_CLANG
argument_list|)
operator|||
operator|(
name|defined
argument_list|(
name|Q_CC_GNU
argument_list|)
operator|&&
name|Q_CC_GNU
operator|<
literal|405
operator|)
operator|)
expr|\
operator|&&
operator|!
name|defined
argument_list|(
name|Q_CC_INTEL
argument_list|)
end_elif
begin_comment
comment|// Clang is missing the intrinsic for _bit_scan_reverse
end_comment
begin_comment
comment|// GCC only added it in version 4.5
end_comment
begin_expr_stmt
specifier|static
specifier|inline
name|__attribute__
argument_list|(
argument|(always_inline)
argument_list|)
DECL|function|_bit_scan_reverse
name|unsigned
name|_bit_scan_reverse
argument_list|(
argument|unsigned val
argument_list|)
block|{
name|unsigned
name|result
block|;
name|asm
argument_list|(
literal|"bsr %1, %0"
operator|:
literal|"=r"
operator|(
name|result
operator|)
operator|:
literal|"r"
operator|(
name|val
operator|)
argument_list|)
block|;
return|return
name|result
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|static
specifier|inline
name|__attribute__
argument_list|(
argument|(always_inline)
argument_list|)
DECL|function|_bit_scan_forward
name|unsigned
name|_bit_scan_forward
argument_list|(
argument|unsigned val
argument_list|)
block|{
name|unsigned
name|result
block|;
name|asm
argument_list|(
literal|"bsf %1, %0"
operator|:
literal|"=r"
operator|(
name|result
operator|)
operator|:
literal|"r"
operator|(
name|val
operator|)
argument_list|)
block|;
return|return
name|result
return|;
block|}
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// Q_PROCESSOR_X86
end_comment
begin_define
DECL|macro|ALIGNMENT_PROLOGUE_16BYTES
define|#
directive|define
name|ALIGNMENT_PROLOGUE_16BYTES
parameter_list|(
name|ptr
parameter_list|,
name|i
parameter_list|,
name|length
parameter_list|)
define|\
value|for (; i< static_cast<int>(qMin(static_cast<quintptr>(length), ((4 - ((reinterpret_cast<quintptr>(ptr)>> 2)& 0x3))& 0x3))); ++i)
end_define
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QSIMD_P_H
end_comment
end_unit
