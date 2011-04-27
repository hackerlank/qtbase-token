begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtOpenGL module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** No Commercial Usage ** This file contains pre-release code and may not be distributed. ** You may use this file in accordance with the terms and conditions ** contained in the Technology Preview License Agreement accompanying ** this package. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights.  These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** If you have questions regarding the use of this file, please contact ** Nokia at qt-info@nokia.com. ** ** ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QPLATFORM_GL_CONTEXT_H
end_ifndef
begin_define
DECL|macro|QPLATFORM_GL_CONTEXT_H
define|#
directive|define
name|QPLATFORM_GL_CONTEXT_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qnamespace.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/QPlatformWindowFormat>
end_include
begin_function
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
name|QT_MODULE
parameter_list|(
name|Gui
parameter_list|)
name|class
name|QPlatformGLContextPrivate
decl_stmt|;
name|class
name|Q_OPENGL_EXPORT
name|QPlatformGLContext
decl_stmt|{ Q_DECLARE_PRIVATE(QPlatformGLContext
end_function
begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt
begin_label
name|public
label|:
end_label
begin_function_decl
name|explicit
name|QPlatformGLContext
parameter_list|()
function_decl|;
end_function_decl
begin_expr_stmt
name|virtual
operator|~
name|QPlatformGLContext
argument_list|()
expr_stmt|;
end_expr_stmt
begin_function_decl
name|virtual
name|void
name|makeCurrent
parameter_list|()
function_decl|;
end_function_decl
begin_function_decl
name|virtual
name|void
name|doneCurrent
parameter_list|()
function_decl|;
end_function_decl
begin_function_decl
name|virtual
name|void
name|swapBuffers
parameter_list|()
init|=
literal|0
function_decl|;
end_function_decl
begin_function_decl
name|virtual
name|void
modifier|*
name|getProcAddress
parameter_list|(
specifier|const
name|QString
modifier|&
name|procName
parameter_list|)
init|=
literal|0
function_decl|;
end_function_decl
begin_expr_stmt
name|virtual
name|QPlatformWindowFormat
name|platformWindowFormat
argument_list|()
specifier|const
operator|=
literal|0
expr_stmt|;
end_expr_stmt
begin_function_decl
specifier|const
specifier|static
name|QPlatformGLContext
modifier|*
name|currentContext
parameter_list|()
function_decl|;
end_function_decl
begin_label
name|protected
label|:
end_label
begin_expr_stmt
name|QScopedPointer
operator|<
name|QPlatformGLContextPrivate
operator|>
name|d_ptr
expr_stmt|;
end_expr_stmt
begin_label
name|private
label|:
end_label
begin_comment
comment|//hack to make it work with QGLContext::CurrentContext
end_comment
begin_decl_stmt
name|friend
name|class
name|QGLContext
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|friend
name|class
name|QWidgetPrivate
decl_stmt|;
end_decl_stmt
begin_function_decl
name|void
modifier|*
name|qGLContextHandle
parameter_list|()
function_decl|const;
end_function_decl
begin_function_decl
name|void
name|setQGLContextHandle
parameter_list|(
name|void
modifier|*
name|handle
parameter_list|,
name|void
function_decl|(
modifier|*
name|qGLContextDeleteFunction
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|deleteQGLContext
parameter_list|()
function_decl|;
end_function_decl
begin_expr_stmt
name|Q_DISABLE_COPY
argument_list|(
name|QPlatformGLContext
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
unit|};
name|QT_END_NAMESPACE
name|QT_END_HEADER
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QPLATFORM_GL_INTEGRATION_P_H
end_comment
end_unit
