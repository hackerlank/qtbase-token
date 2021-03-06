begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QGLXCONVENIENCE_H
end_ifndef
begin_define
DECL|macro|QGLXCONVENIENCE_H
define|#
directive|define
name|QGLXCONVENIENCE_H
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
file|<QSurfaceFormat>
end_include
begin_include
include|#
directive|include
file|<QVector>
end_include
begin_include
include|#
directive|include
file|<X11/Xlib.h>
end_include
begin_include
include|#
directive|include
file|<GL/glx.h>
end_include
begin_expr_stmt
name|QVector
operator|<
name|int
operator|>
name|qglx_buildSpec
argument_list|(
argument|const QSurfaceFormat&format
argument_list|,
argument|int drawableBit = GLX_WINDOW_BIT
argument_list|)
expr_stmt|;
end_expr_stmt
begin_function_decl
name|XVisualInfo
modifier|*
name|qglx_findVisualInfo
parameter_list|(
name|Display
modifier|*
name|display
parameter_list|,
name|int
name|screen
parameter_list|,
name|QSurfaceFormat
modifier|*
name|format
parameter_list|,
name|int
name|drawableBit
init|=
name|GLX_WINDOW_BIT
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|GLXFBConfig
name|qglx_findConfig
parameter_list|(
name|Display
modifier|*
name|display
parameter_list|,
name|int
name|screen
parameter_list|,
name|QSurfaceFormat
name|format
parameter_list|,
name|bool
name|highestPixelFormat
init|=
name|false
parameter_list|,
name|int
name|drawableBit
init|=
name|GLX_WINDOW_BIT
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|qglx_surfaceFormatFromGLXFBConfig
parameter_list|(
name|QSurfaceFormat
modifier|*
name|format
parameter_list|,
name|Display
modifier|*
name|display
parameter_list|,
name|GLXFBConfig
name|config
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|qglx_surfaceFormatFromVisualInfo
parameter_list|(
name|QSurfaceFormat
modifier|*
name|format
parameter_list|,
name|Display
modifier|*
name|display
parameter_list|,
name|XVisualInfo
modifier|*
name|visualInfo
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|bool
name|qglx_reduceFormat
parameter_list|(
name|QSurfaceFormat
modifier|*
name|format
parameter_list|)
function_decl|;
end_function_decl
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QGLXCONVENIENCE_H
end_comment
end_unit
