begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** No Commercial Usage ** This file contains pre-release code and may not be distributed. ** You may use this file in accordance with the terms and conditions ** contained in the Technology Preview License Agreement accompanying ** this package. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights.  These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** If you have questions regarding the use of this file, please contact ** Nokia at qt-info@nokia.com. ** ** ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QDRAWHELPER_ARM_SIMD_P_H
end_ifndef
begin_define
DECL|macro|QDRAWHELPER_ARM_SIMD_P_H
define|#
directive|define
name|QDRAWHELPER_ARM_SIMD_P_H
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
file|<private/qdrawhelper_p.h>
end_include
begin_function_decl
name|QT_BEGIN_NAMESPACE
if|#
directive|if
name|defined
argument_list|(
name|QT_HAVE_ARM_SIMD
argument_list|)
name|void
name|qt_blend_argb32_on_argb32_arm_simd
parameter_list|(
name|uchar
modifier|*
name|destPixels
parameter_list|,
name|int
name|dbpl
parameter_list|,
specifier|const
name|uchar
modifier|*
name|srcPixels
parameter_list|,
name|int
name|sbpl
parameter_list|,
name|int
name|w
parameter_list|,
name|int
name|h
parameter_list|,
name|int
name|const_alpha
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|qt_blend_rgb32_on_rgb32_arm_simd
parameter_list|(
name|uchar
modifier|*
name|destPixels
parameter_list|,
name|int
name|dbpl
parameter_list|,
specifier|const
name|uchar
modifier|*
name|srcPixels
parameter_list|,
name|int
name|sbpl
parameter_list|,
name|int
name|w
parameter_list|,
name|int
name|h
parameter_list|,
name|int
name|const_alpha
parameter_list|)
function_decl|;
end_function_decl
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_HAVE_ARM_SIMD
end_comment
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QDRAWHELPER_ARM_SIMD_P_H
end_comment
end_unit
