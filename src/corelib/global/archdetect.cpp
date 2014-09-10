begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Copyright (C) 2014 Intel Corporation ** Contact: http://www.qt-project.org/legal ** ** This file is part of the FOO module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qprocessordetection.h"
end_include
begin_comment
comment|// main part: processor type
end_comment
begin_if
if|#
directive|if
name|defined
argument_list|(
name|Q_PROCESSOR_ALPHA
argument_list|)
end_if
begin_define
DECL|macro|ARCH_PROCESSOR
define|#
directive|define
name|ARCH_PROCESSOR
value|"alpha"
end_define
begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|Q_PROCESSOR_ARM_32
argument_list|)
end_elif
begin_define
DECL|macro|ARCH_PROCESSOR
define|#
directive|define
name|ARCH_PROCESSOR
value|"arm"
end_define
begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|Q_PROCESSOR_ARM_64
argument_list|)
end_elif
begin_define
DECL|macro|ARCH_PROCESSOR
define|#
directive|define
name|ARCH_PROCESSOR
value|"arm64"
end_define
begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|Q_PROCESSOR_AVR32
argument_list|)
end_elif
begin_define
DECL|macro|ARCH_PROCESSOR
define|#
directive|define
name|ARCH_PROCESSOR
value|"avr32"
end_define
begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|Q_PROCESSOR_BLACKFIN
argument_list|)
end_elif
begin_define
DECL|macro|ARCH_PROCESSOR
define|#
directive|define
name|ARCH_PROCESSOR
value|"bfin"
end_define
begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|Q_PROCESSOR_X86_32
argument_list|)
end_elif
begin_define
DECL|macro|ARCH_PROCESSOR
define|#
directive|define
name|ARCH_PROCESSOR
value|"i386"
end_define
begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|Q_PROCESSOR_X86_64
argument_list|)
end_elif
begin_define
DECL|macro|ARCH_PROCESSOR
define|#
directive|define
name|ARCH_PROCESSOR
value|"x86_64"
end_define
begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|Q_PROCESSOR_IA64
argument_list|)
end_elif
begin_define
DECL|macro|ARCH_PROCESSOR
define|#
directive|define
name|ARCH_PROCESSOR
value|"ia64"
end_define
begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|Q_PROCESSOR_MIPS_64
argument_list|)
end_elif
begin_define
DECL|macro|ARCH_PROCESSOR
define|#
directive|define
name|ARCH_PROCESSOR
value|"mips64"
end_define
begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|Q_PROCESSOR_MIPS
argument_list|)
end_elif
begin_define
DECL|macro|ARCH_PROCESSOR
define|#
directive|define
name|ARCH_PROCESSOR
value|"mips"
end_define
begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|Q_PROCESSOR_POWER_32
argument_list|)
end_elif
begin_define
DECL|macro|ARCH_PROCESSOR
define|#
directive|define
name|ARCH_PROCESSOR
value|"power"
end_define
begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|Q_PROCESSOR_POWER_64
argument_list|)
end_elif
begin_define
DECL|macro|ARCH_PROCESSOR
define|#
directive|define
name|ARCH_PROCESSOR
value|"power64"
end_define
begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|Q_PROCESSOR_S390_X
argument_list|)
end_elif
begin_define
DECL|macro|ARCH_PROCESSOR
define|#
directive|define
name|ARCH_PROCESSOR
value|"s390x"
end_define
begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|Q_PROCESSOR_S390
argument_list|)
end_elif
begin_define
DECL|macro|ARCH_PROCESSOR
define|#
directive|define
name|ARCH_PROCESSOR
value|"s390"
end_define
begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|Q_PROCESSOR_SH
argument_list|)
end_elif
begin_define
DECL|macro|ARCH_PROCESSOR
define|#
directive|define
name|ARCH_PROCESSOR
value|"sh"
end_define
begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|Q_PROCESSORS_SPARC_64
argument_list|)
end_elif
begin_define
DECL|macro|ARCH_PROCESSOR
define|#
directive|define
name|ARCH_PROCESSOR
value|"sparc64"
end_define
begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|Q_PROCESSOR_SPARC_V9
argument_list|)
end_elif
begin_define
DECL|macro|ARCH_PROCESSOR
define|#
directive|define
name|ARCH_PROCESSOR
value|"sparcv9"
end_define
begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|Q_PROCESSOR_SPARC
argument_list|)
end_elif
begin_define
DECL|macro|ARCH_PROCESSOR
define|#
directive|define
name|ARCH_PROCESSOR
value|"sparc"
end_define
begin_else
else|#
directive|else
end_else
begin_define
DECL|macro|ARCH_PROCESSOR
define|#
directive|define
name|ARCH_PROCESSOR
value|"unknown"
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// endianness
end_comment
begin_if
if|#
directive|if
name|Q_BYTE_ORDER
operator|==
name|Q_LITTLE_ENDIAN
end_if
begin_define
DECL|macro|ARCH_ENDIANNESS
define|#
directive|define
name|ARCH_ENDIANNESS
value|"little_endian"
end_define
begin_elif
elif|#
directive|elif
name|Q_BYTE_ORDER
operator|==
name|Q_BIG_ENDIAN
end_elif
begin_define
DECL|macro|ARCH_ENDIANNESS
define|#
directive|define
name|ARCH_ENDIANNESS
value|"big_endian"
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// pointer type
end_comment
begin_if
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_WIN64
argument_list|)
operator|||
operator|(
name|defined
argument_list|(
name|Q_OS_WINRT
argument_list|)
operator|&&
name|defined
argument_list|(
name|_M_X64
argument_list|)
operator|)
end_if
begin_define
DECL|macro|ARCH_POINTER
define|#
directive|define
name|ARCH_POINTER
value|"llp64"
end_define
begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__LP64__
argument_list|)
operator|||
name|QT_POINTER_SIZE
operator|-
literal|0
operator|==
literal|8
end_elif
begin_define
DECL|macro|ARCH_POINTER
define|#
directive|define
name|ARCH_POINTER
value|"lp64"
end_define
begin_else
else|#
directive|else
end_else
begin_define
DECL|macro|ARCH_POINTER
define|#
directive|define
name|ARCH_POINTER
value|"ilp32"
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// qreal type, if not double (includes the dash)
end_comment
begin_ifdef
ifdef|#
directive|ifdef
name|QT_COORD_TYPE_STRING
end_ifdef
begin_define
DECL|macro|ARCH_COORD_TYPE
define|#
directive|define
name|ARCH_COORD_TYPE
value|"-qreal_" QT_COORD_TYPE_STRING
end_define
begin_else
else|#
directive|else
end_else
begin_define
DECL|macro|ARCH_COORD_TYPE
define|#
directive|define
name|ARCH_COORD_TYPE
value|""
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// secondary: ABI string (includes the dash)
end_comment
begin_if
if|#
directive|if
name|defined
argument_list|(
name|__ARM_EABI__
argument_list|)
operator|||
name|defined
argument_list|(
name|__mips_eabi
argument_list|)
end_if
begin_define
DECL|macro|ARCH_ABI1
define|#
directive|define
name|ARCH_ABI1
value|"-eabi"
end_define
begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|_MIPS_SIM
argument_list|)
end_elif
begin_if
if|#
directive|if
name|_MIPS_SIM
operator|==
name|_ABIO32
end_if
begin_define
DECL|macro|ARCH_ABI1
define|#
directive|define
name|ARCH_ABI1
value|"-o32"
end_define
begin_elif
elif|#
directive|elif
name|_MIPS_SIM
operator|==
name|_ABIN32
end_elif
begin_define
DECL|macro|ARCH_ABI1
define|#
directive|define
name|ARCH_ABI1
value|"-n32"
end_define
begin_elif
elif|#
directive|elif
name|_MIPS_SIM
operator|==
name|_ABI64
end_elif
begin_define
DECL|macro|ARCH_ABI1
define|#
directive|define
name|ARCH_ABI1
value|"-n64"
end_define
begin_elif
elif|#
directive|elif
name|_MIPS_SIM
operator|==
name|_ABIO64
end_elif
begin_define
DECL|macro|ARCH_ABI1
define|#
directive|define
name|ARCH_ABI1
value|"-o64"
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
DECL|macro|ARCH_ABI1
define|#
directive|define
name|ARCH_ABI1
value|""
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
name|__ARM_PCS_VFP
argument_list|)
operator|||
name|defined
argument_list|(
name|__mips_hard_float
argument_list|)
end_if
begin_define
DECL|macro|ARCH_ABI2
define|#
directive|define
name|ARCH_ABI2
value|"-hardfloat"
end_define
begin_else
else|#
directive|else
end_else
begin_define
DECL|macro|ARCH_ABI2
define|#
directive|define
name|ARCH_ABI2
value|""
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_define
DECL|macro|ARCH_ABI
define|#
directive|define
name|ARCH_ABI
value|ARCH_ABI1 ARCH_ABI2
end_define
begin_define
DECL|macro|ARCH_FULL
define|#
directive|define
name|ARCH_FULL
value|ARCH_PROCESSOR "-" ARCH_ENDIANNESS "-" ARCH_POINTER ARCH_COORD_TYPE ARCH_ABI
end_define
end_unit
