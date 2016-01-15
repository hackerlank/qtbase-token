begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtCore/qglobal.h>
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QISENUM_H
end_ifndef
begin_define
DECL|macro|QISENUM_H
define|#
directive|define
name|QISENUM_H
end_define
begin_ifndef
ifndef|#
directive|ifndef
name|Q_IS_ENUM
end_ifndef
begin_if
if|#
directive|if
name|defined
argument_list|(
name|Q_CC_GNU
argument_list|)
operator|&&
operator|(
name|__GNUC__
operator|>
literal|4
operator|||
operator|(
name|__GNUC__
operator|==
literal|4
operator|&&
name|__GNUC_MINOR__
operator|>=
literal|3
operator|)
operator|)
end_if
begin_define
DECL|macro|Q_IS_ENUM
define|#
directive|define
name|Q_IS_ENUM
parameter_list|(
name|x
parameter_list|)
value|__is_enum(x)
end_define
begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|Q_CC_MSVC
argument_list|)
operator|&&
name|defined
argument_list|(
name|_MSC_FULL_VER
argument_list|)
operator|&&
operator|(
name|_MSC_FULL_VER
operator|>=
literal|140050215
operator|)
end_elif
begin_define
DECL|macro|Q_IS_ENUM
define|#
directive|define
name|Q_IS_ENUM
parameter_list|(
name|x
parameter_list|)
value|__is_enum(x)
end_define
begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|Q_CC_CLANG
argument_list|)
end_elif
begin_if
if|#
directive|if
name|__has_extension
argument_list|(
name|is_enum
argument_list|)
end_if
begin_define
DECL|macro|Q_IS_ENUM
define|#
directive|define
name|Q_IS_ENUM
parameter_list|(
name|x
parameter_list|)
value|__is_enum(x)
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
begin_ifndef
ifndef|#
directive|ifndef
name|Q_IS_ENUM
end_ifndef
begin_include
include|#
directive|include
file|<QtCore/qtypetraits.h>
end_include
begin_define
DECL|macro|Q_IS_ENUM
define|#
directive|define
name|Q_IS_ENUM
parameter_list|(
name|x
parameter_list|)
value|QtPrivate::is_enum<x>::value
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// shut up syncqt
end_comment
begin_expr_stmt
name|QT_BEGIN_NAMESPACE
name|QT_END_NAMESPACE
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QISENUM_H
end_comment
end_unit
