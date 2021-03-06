begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QMEMROTATE_P_H
end_ifndef
begin_define
DECL|macro|QMEMROTATE_P_H
define|#
directive|define
name|QMEMROTATE_P_H
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
file|"private/qdrawhelper_p.h"
end_include
begin_function_decl
name|QT_BEGIN_NAMESPACE
DECL|macro|QT_ROTATION_CACHEDREAD
define|#
directive|define
name|QT_ROTATION_CACHEDREAD
value|1
DECL|macro|QT_ROTATION_CACHEDWRITE
define|#
directive|define
name|QT_ROTATION_CACHEDWRITE
value|2
DECL|macro|QT_ROTATION_PACKING
define|#
directive|define
name|QT_ROTATION_PACKING
value|3
DECL|macro|QT_ROTATION_TILED
define|#
directive|define
name|QT_ROTATION_TILED
value|4
ifndef|#
directive|ifndef
name|QT_ROTATION_ALGORITHM
if|#
directive|if
name|Q_BYTE_ORDER
operator|==
name|Q_LITTLE_ENDIAN
DECL|macro|QT_ROTATION_ALGORITHM
define|#
directive|define
name|QT_ROTATION_ALGORITHM
value|QT_ROTATION_TILED
else|#
directive|else
define|#
directive|define
name|QT_ROTATION_ALGORITHM
value|QT_ROTATION_CACHEDREAD
endif|#
directive|endif
endif|#
directive|endif
DECL|macro|QT_DECL_MEMROTATE
define|#
directive|define
name|QT_DECL_MEMROTATE
parameter_list|(
name|type
parameter_list|)
define|\
value|void Q_GUI_EXPORT qt_memrotate90(const type*, int, int, int, type*, int); \     void Q_GUI_EXPORT qt_memrotate180(const type*, int, int, int, type*, int); \     void Q_GUI_EXPORT qt_memrotate270(const type*, int, int, int, type*, int)
name|QT_DECL_MEMROTATE
parameter_list|(
name|quint32
parameter_list|)
function_decl|;
end_function_decl
begin_expr_stmt
DECL|variable|quint16
name|QT_DECL_MEMROTATE
argument_list|(
name|quint16
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
DECL|variable|quint24
name|QT_DECL_MEMROTATE
argument_list|(
name|quint24
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
DECL|variable|quint8
name|QT_DECL_MEMROTATE
argument_list|(
name|quint8
argument_list|)
expr_stmt|;
end_expr_stmt
begin_undef
DECL|macro|QT_DECL_MEMROTATE
undef|#
directive|undef
name|QT_DECL_MEMROTATE
end_undef
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QMEMROTATE_P_H
end_comment
end_unit
