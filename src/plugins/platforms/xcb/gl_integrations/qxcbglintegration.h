begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QXCBGLINTEGRATION_H
end_ifndef
begin_include
include|#
directive|include
file|"qxcbexport.h"
end_include
begin_include
include|#
directive|include
file|"qxcbwindow.h"
end_include
begin_include
include|#
directive|include
file|<QtCore/QLoggingCategory>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QPlatformOffscreenSurface
name|class
name|QPlatformOffscreenSurface
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QOffscreenSurface
name|class
name|QOffscreenSurface
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QXcbNativeInterfaceHandler
name|class
name|QXcbNativeInterfaceHandler
decl_stmt|;
end_decl_stmt
begin_function
DECL|function|Q_DECLARE_LOGGING_CATEGORY
name|Q_XCB_EXPORT
name|Q_DECLARE_LOGGING_CATEGORY
parameter_list|(
name|QT_XCB_GLINTEGRATION
parameter_list|)
name|class
name|Q_XCB_EXPORT
name|QXcbGlIntegration
decl_stmt|{ public:     QXcbGlIntegration(
end_function
begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt
begin_expr_stmt
name|virtual
operator|~
name|QXcbGlIntegration
argument_list|()
expr_stmt|;
end_expr_stmt
begin_function_decl
name|virtual
name|bool
name|initialize
parameter_list|(
name|QXcbConnection
modifier|*
name|connection
parameter_list|)
init|=
literal|0
function_decl|;
end_function_decl
begin_expr_stmt
name|virtual
name|bool
name|supportsThreadedOpenGL
argument_list|()
specifier|const
block|{
return|return
name|false
return|;
block|}
end_expr_stmt
begin_function_decl
name|virtual
name|bool
name|handleXcbEvent
parameter_list|(
name|xcb_generic_event_t
modifier|*
name|event
parameter_list|,
name|uint
name|responseType
parameter_list|)
function_decl|;
end_function_decl
begin_decl_stmt
name|virtual
name|QXcbWindow
modifier|*
name|createWindow
argument_list|(
name|QWindow
operator|*
name|window
argument_list|)
decl|const
init|=
literal|0
decl_stmt|;
end_decl_stmt
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_OPENGL
end_ifndef
begin_decl_stmt
name|virtual
name|QPlatformOpenGLContext
modifier|*
name|createPlatformOpenGLContext
argument_list|(
name|QOpenGLContext
operator|*
name|context
argument_list|)
decl|const
init|=
literal|0
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_decl_stmt
name|virtual
name|QPlatformOffscreenSurface
modifier|*
name|createPlatformOffscreenSurface
argument_list|(
name|QOffscreenSurface
operator|*
name|surface
argument_list|)
decl|const
init|=
literal|0
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|virtual
name|QXcbNativeInterfaceHandler
operator|*
name|nativeInterfaceHandler
argument_list|()
specifier|const
block|{
return|return
name|Q_NULLPTR
return|;
block|}
end_expr_stmt
begin_macro
unit|};
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|//QXCBGLINTEGRATION_H
end_comment
end_unit
