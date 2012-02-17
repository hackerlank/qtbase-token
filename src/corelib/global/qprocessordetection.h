begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QPROCESSORDETECTION_H
end_ifndef
begin_define
DECL|macro|QPROCESSORDETECTION_H
define|#
directive|define
name|QPROCESSORDETECTION_H
end_define
begin_comment
comment|/*     This file uses preprocessor #defines to set various Q_PROCESSOR_* #defines     based on the following patterns:      Q_PROCESSOR_{FAMILY}     Q_PROCESSOR_{FAMILY}_{VARIANT}     Q_PROCESSOR_{FAMILY}_{REVISION}      The first is always defined. Defines for the various revisions/variants are     optional and usually dependent on how the compiler was invoked. Variants     that are a superset of another should have a define for the superset. */
end_comment
begin_comment
comment|/*     Alpha family, no revisions or variants */
end_comment
begin_comment
comment|// #elif defined(__alpha__) || defined(_M_ALPHA)
end_comment
begin_comment
comment|// #  define Q_PROCESSOR_ALPHA
end_comment
begin_comment
comment|/*   ARM family, known revisions: V5, V6, and V7 */
end_comment
begin_if
if|#
directive|if
name|defined
argument_list|(
name|__arm__
argument_list|)
operator|||
name|defined
argument_list|(
name|__TARGET_ARCH_ARM
argument_list|)
end_if
begin_define
DECL|macro|Q_PROCESSOR_ARM
define|#
directive|define
name|Q_PROCESSOR_ARM
end_define
begin_if
if|#
directive|if
name|defined
argument_list|(
name|__ARM_ARCH_7__
argument_list|)
expr|\
operator|||
name|defined
argument_list|(
name|__ARM_ARCH_7A__
argument_list|)
expr|\
operator|||
name|defined
argument_list|(
name|__ARM_ARCH_7R__
argument_list|)
expr|\
operator|||
name|defined
argument_list|(
name|__ARM_ARCH_7M__
argument_list|)
expr|\
operator|||
operator|(
name|__TARGET_ARCH_ARM
operator|-
literal|0
operator|>=
literal|7
operator|)
end_if
begin_define
DECL|macro|Q_PROCESSOR_ARM_V7
define|#
directive|define
name|Q_PROCESSOR_ARM_V7
end_define
begin_define
DECL|macro|Q_PROCESSOR_ARM_V6
define|#
directive|define
name|Q_PROCESSOR_ARM_V6
end_define
begin_define
DECL|macro|Q_PROCESSOR_ARM_V5
define|#
directive|define
name|Q_PROCESSOR_ARM_V5
end_define
begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__ARM_ARCH_6__
argument_list|)
expr|\
operator|||
name|defined
argument_list|(
name|__ARM_ARCH_6J__
argument_list|)
expr|\
operator|||
name|defined
argument_list|(
name|__ARM_ARCH_6T2__
argument_list|)
expr|\
operator|||
name|defined
argument_list|(
name|__ARM_ARCH_6Z__
argument_list|)
expr|\
operator|||
name|defined
argument_list|(
name|__ARM_ARCH_6K__
argument_list|)
expr|\
operator|||
name|defined
argument_list|(
name|__ARM_ARCH_6ZK__
argument_list|)
expr|\
operator|||
name|defined
argument_list|(
name|__ARM_ARCH_6M__
argument_list|)
expr|\
operator|||
operator|(
name|__TARGET_ARCH_ARM
operator|-
literal|0
operator|>=
literal|6
operator|)
end_elif
begin_define
DECL|macro|Q_PROCESSOR_ARM_V6
define|#
directive|define
name|Q_PROCESSOR_ARM_V6
end_define
begin_define
DECL|macro|Q_PROCESSOR_ARM_V5
define|#
directive|define
name|Q_PROCESSOR_ARM_V5
end_define
begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__ARM_ARCH_5TEJ__
argument_list|)
expr|\
operator|||
operator|(
name|__TARGET_ARCH_ARM
operator|-
literal|0
operator|>=
literal|5
operator|)
end_elif
begin_define
DECL|macro|Q_PROCESSOR_ARM_V5
define|#
directive|define
name|Q_PROCESSOR_ARM_V5
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/*     AVR32 family, no revisions or variants */
end_comment
begin_comment
comment|// #elif defined(__avr32__)
end_comment
begin_comment
comment|// #  define Q_PROCESSOR_AVR32
end_comment
begin_comment
comment|/*     Blackfin family, no revisions or variants */
end_comment
begin_comment
comment|// #elif defined(__bfin__)
end_comment
begin_comment
comment|// #  define Q_PROCESSOR_BLACKFIN
end_comment
begin_comment
comment|/*     X86 family, known variants: 32- and 64-bit */
end_comment
begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__i386
argument_list|)
operator|||
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
begin_define
DECL|macro|Q_PROCESSOR_X86
define|#
directive|define
name|Q_PROCESSOR_X86
end_define
begin_define
DECL|macro|Q_PROCESSOR_X86_32
define|#
directive|define
name|Q_PROCESSOR_X86_32
end_define
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
name|__x86_64__
argument_list|)
operator|||
name|defined
argument_list|(
name|__amd64
argument_list|)
operator|||
name|defined
argument_list|(
name|_M_X64
argument_list|)
end_elif
begin_define
DECL|macro|Q_PROCESSOR_X86
define|#
directive|define
name|Q_PROCESSOR_X86
end_define
begin_define
DECL|macro|Q_PROCESSOR_X86_64
define|#
directive|define
name|Q_PROCESSOR_X86_64
end_define
begin_comment
comment|/*     Itanium (IA-64) family, no revisions or variants */
end_comment
begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__ia64
argument_list|)
operator|||
name|defined
argument_list|(
name|__ia64__
argument_list|)
operator|||
name|defined
argument_list|(
name|_M_IA64
argument_list|)
end_elif
begin_define
DECL|macro|Q_PROCESSOR_IA64
define|#
directive|define
name|Q_PROCESSOR_IA64
end_define
begin_comment
comment|/*     MIPS family, known revisions: I, II, III, IV, 32, 64 */
end_comment
begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__mips
argument_list|)
operator|||
name|defined
argument_list|(
name|__mips__
argument_list|)
operator|||
name|defined
argument_list|(
name|_M_MRX000
argument_list|)
end_elif
begin_define
DECL|macro|Q_PROCESSOR_MIPS
define|#
directive|define
name|Q_PROCESSOR_MIPS
end_define
begin_if
if|#
directive|if
name|defined
argument_list|(
name|_MIPS_ARCH_MIPS1
argument_list|)
operator|||
operator|(
name|defined
argument_list|(
name|__mips
argument_list|)
operator|&&
name|__mips
operator|-
literal|0
operator|>=
literal|1
operator|)
end_if
begin_define
DECL|macro|Q_PROCESSOR_MIPS_I
define|#
directive|define
name|Q_PROCESSOR_MIPS_I
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_if
if|#
directive|if
name|defined
argument_list|(
name|_MIPS_ARCH_MIPS2
argument_list|)
operator|||
operator|(
name|defined
argument_list|(
name|__mips
argument_list|)
operator|&&
name|__mips
operator|-
literal|0
operator|>=
literal|2
operator|)
end_if
begin_define
DECL|macro|Q_PROCESSOR_MIPS_II
define|#
directive|define
name|Q_PROCESSOR_MIPS_II
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_if
if|#
directive|if
name|defined
argument_list|(
name|_MIPS_ARCH_MIPS32
argument_list|)
operator|||
name|defined
argument_list|(
name|__mips32
argument_list|)
end_if
begin_define
DECL|macro|Q_PROCESSOR_MIPS_32
define|#
directive|define
name|Q_PROCESSOR_MIPS_32
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_if
if|#
directive|if
name|defined
argument_list|(
name|_MIPS_ARCH_MIPS3
argument_list|)
operator|||
operator|(
name|defined
argument_list|(
name|__mips
argument_list|)
operator|&&
name|__mips
operator|-
literal|0
operator|>=
literal|3
operator|)
end_if
begin_define
DECL|macro|Q_PROCESSOR_MIPS_III
define|#
directive|define
name|Q_PROCESSOR_MIPS_III
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_if
if|#
directive|if
name|defined
argument_list|(
name|_MIPS_ARCH_MIPS4
argument_list|)
operator|||
operator|(
name|defined
argument_list|(
name|__mips
argument_list|)
operator|&&
name|__mips
operator|-
literal|0
operator|>=
literal|4
operator|)
end_if
begin_define
DECL|macro|Q_PROCESSOR_MIPS_IV
define|#
directive|define
name|Q_PROCESSOR_MIPS_IV
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_if
if|#
directive|if
name|defined
argument_list|(
name|_MIPS_ARCH_MIPS5
argument_list|)
operator|||
operator|(
name|defined
argument_list|(
name|__mips
argument_list|)
operator|&&
name|__mips
operator|-
literal|0
operator|>=
literal|5
operator|)
end_if
begin_define
DECL|macro|Q_PROCESSOR_MIPS_V
define|#
directive|define
name|Q_PROCESSOR_MIPS_V
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_if
if|#
directive|if
name|defined
argument_list|(
name|_MIPS_ARCH_MIPS64
argument_list|)
operator|||
name|defined
argument_list|(
name|__mips64
argument_list|)
end_if
begin_define
DECL|macro|Q_PROCESSOR_MIPS_64
define|#
directive|define
name|Q_PROCESSOR_MIPS_64
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/*     POWER family, optional variant: 64-bit      There are many more known variants/revisions that we do not handle/detect.     See http://en.wikipedia.org/wiki/Power_Architecture     and http://en.wikipedia.org/wiki/File:PowerISA-evolution.svg */
end_comment
begin_comment
comment|// #elif defined(__powerpc__) || defined(__ppc__) || defined(_M_MPPC) || defined(_M_PPC)
end_comment
begin_comment
comment|// #  define Q_PROCESSOR_POWERPC
end_comment
begin_comment
comment|// #  if defined(__64BIT__) || defined(__powerpc64__) || defined(__ppc64__)
end_comment
begin_comment
comment|// #    define Q_PROCESSOR_POWERPC_64
end_comment
begin_comment
comment|// #  endif
end_comment
begin_comment
comment|/*     S390 family, known variant: S390X (64-bit) */
end_comment
begin_comment
comment|// #elif defined(__s390__)
end_comment
begin_comment
comment|// #  define Q_PROCESSOR_S390
end_comment
begin_comment
comment|// #  if defined(__s390x__)
end_comment
begin_comment
comment|// #    define Q_PROCESSOR_S390_X
end_comment
begin_comment
comment|// #  endif
end_comment
begin_comment
comment|/*     SuperH family, optional revision: SH-4A */
end_comment
begin_comment
comment|// #elif defined(__sh__)
end_comment
begin_comment
comment|// #  define Q_PROCESSOR_SH
end_comment
begin_comment
comment|// #  if defined(__sh4a__)
end_comment
begin_comment
comment|// #    define Q_PROCESSOR_SH_4A
end_comment
begin_comment
comment|// #  endif
end_comment
begin_comment
comment|/*     SPARC family, optional revision: V9 */
end_comment
begin_comment
comment|// #elif defined(__sparc__)
end_comment
begin_comment
comment|// #  define Q_PROCESSOR_SPARC
end_comment
begin_comment
comment|// #  if defined(__sparc_v9__)
end_comment
begin_comment
comment|// #    define Q_PROCESSOR_SPARC_V9
end_comment
begin_comment
comment|// #  endif
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QPROCESSORDETECTION_H
end_comment
end_unit
