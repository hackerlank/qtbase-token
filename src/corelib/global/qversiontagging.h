begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 Intel Corporation. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_comment
comment|// qglobal.h includes this header, so keep it outside of our include guards
end_comment
begin_include
include|#
directive|include
file|<QtCore/qglobal.h>
end_include
begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|QVERSIONTAGGING_H
argument_list|)
end_if
begin_define
DECL|macro|QVERSIONTAGGING_H
define|#
directive|define
name|QVERSIONTAGGING_H
end_define
begin_function_decl
name|QT_BEGIN_NAMESPACE
comment|/*  * Ugly hack warning and explanation:  *  * This file causes all ELF modules, be they libraries or applications, to use the  * qt_version_tag symbol that is present in QtCore. Such symbol is versioned,  * so the linker will automatically pull the current Qt version and add it to  * the ELF header of the library/application. The assembly produces one section  * called ".qtversion" containing two pointer-sized values. The first is a  * relocation to the qt_version_tag symbol (which is what causes the ELF  * version to get used). The second value is the current Qt version at the time  * of compilation.  *  * There will only be one copy of the section in the output library or application.  */
if|#
directive|if
name|defined
argument_list|(
name|QT_BUILD_CORE_LIB
argument_list|)
operator|||
name|defined
argument_list|(
name|QT_BOOTSTRAPPED
argument_list|)
operator|||
name|defined
argument_list|(
name|QT_NO_VERSION_TAGGING
argument_list|)
comment|// don't make tags in QtCore, bootstrapped systems or if the user asked not to
elif|#
directive|elif
name|defined
argument_list|(
name|Q_CC_GNU
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|Q_OS_ANDROID
argument_list|)
if|#
directive|if
name|defined
argument_list|(
name|Q_PROCESSOR_X86
argument_list|)
operator|&&
operator|(
name|defined
argument_list|(
name|Q_OS_LINUX
argument_list|)
operator|||
name|defined
argument_list|(
name|Q_OS_FREEBSD_KERNEL
argument_list|)
operator|)
ifdef|#
directive|ifdef
name|__LP64__
define|#
directive|define
name|QT_VERSION_TAG_RELOC
parameter_list|(
name|sym
parameter_list|)
value|".quad " QT_STRINGIFY(QT_MANGLE_NAMESPACE(sym)) "@GOTPCREL\n"
elif|#
directive|elif
name|defined
argument_list|(
name|Q_PROCESSOR_X86_64
argument_list|)
comment|// x32
define|#
directive|define
name|QT_VERSION_TAG_RELOC
parameter_list|(
name|sym
parameter_list|)
value|".long " QT_STRINGIFY(QT_MANGLE_NAMESPACE(sym)) "@GOTPCREL\n"
else|#
directive|else
comment|// x86
define|#
directive|define
name|QT_VERSION_TAG_RELOC
parameter_list|(
name|sym
parameter_list|)
value|".long " QT_STRINGIFY(QT_MANGLE_NAMESPACE(sym)) "@GOT\n"
endif|#
directive|endif
define|#
directive|define
name|QT_VERSION_TAG
parameter_list|(
name|sym
parameter_list|)
define|\
value|asm (   \     ".section .qtversion, \"aG\", @progbits, qt_version_tag, comdat\n" \     ".align 8\n" \     QT_VERSION_TAG_RELOC(sym) \     ".long " QT_STRINGIFY(QT_VERSION) "\n" \     ".align 8\n" \     ".previous" \     )
endif|#
directive|endif
endif|#
directive|endif
if|#
directive|if
name|defined
argument_list|(
name|QT_VERSION_TAG
argument_list|)
name|QT_VERSION_TAG
parameter_list|(
name|qt_version_tag
parameter_list|)
function_decl|;
end_function_decl
begin_endif
endif|#
directive|endif
end_endif
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QVERSIONTAGGING_H
end_comment
end_unit
