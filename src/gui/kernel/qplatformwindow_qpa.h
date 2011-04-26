begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** No Commercial Usage ** This file contains pre-release code and may not be distributed. ** You may use this file in accordance with the terms and conditions ** contained in the Technology Preview License Agreement accompanying ** this package. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights.  These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** If you have questions regarding the use of this file, please contact ** Nokia at qt-info@nokia.com. ** ** ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QPLATFORMWINDOW_H
end_ifndef
begin_define
DECL|macro|QPLATFORMWINDOW_H
define|#
directive|define
name|QPLATFORMWINDOW_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qscopedpointer.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qrect.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qstring.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/qwindowdefs.h>
end_include
begin_function
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
name|QT_MODULE
parameter_list|(
name|Gui
parameter_list|)
name|class
name|QPlatformWindowPrivate
decl_stmt|;
DECL|variable|QWindow
name|class
name|QWindow
decl_stmt|;
DECL|variable|QPlatformGLContext
name|class
name|QPlatformGLContext
decl_stmt|;
name|class
name|Q_GUI_EXPORT
name|QPlatformWindow
decl_stmt|{     Q_DECLARE_PRIVATE(QPlatformWindow
end_function
begin_label
unit|)
name|public
label|:
end_label
begin_expr_stmt
name|QPlatformWindow
argument_list|(
name|QWindow
operator|*
name|window
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|virtual
operator|~
name|QPlatformWindow
argument_list|()
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|QWindow
operator|*
name|window
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_function_decl
name|virtual
name|void
name|setGeometry
parameter_list|(
specifier|const
name|QRect
modifier|&
name|rect
parameter_list|)
function_decl|;
end_function_decl
begin_expr_stmt
name|virtual
name|QRect
name|geometry
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_function_decl
name|virtual
name|void
name|setVisible
parameter_list|(
name|bool
name|visible
parameter_list|)
function_decl|;
end_function_decl
begin_expr_stmt
name|virtual
name|Qt
operator|::
name|WindowFlags
name|setWindowFlags
argument_list|(
argument|Qt::WindowFlags flags
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|virtual
name|Qt
operator|::
name|WindowFlags
name|windowFlags
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|virtual
name|WId
name|winId
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_function_decl
name|virtual
name|void
name|setParent
parameter_list|(
specifier|const
name|QPlatformWindow
modifier|*
name|window
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|virtual
name|void
name|setWindowTitle
parameter_list|(
specifier|const
name|QString
modifier|&
name|title
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|virtual
name|void
name|raise
parameter_list|()
function_decl|;
end_function_decl
begin_function_decl
name|virtual
name|void
name|lower
parameter_list|()
function_decl|;
end_function_decl
begin_function_decl
name|virtual
name|void
name|setOpacity
parameter_list|(
name|qreal
name|level
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|virtual
name|void
name|requestActivateWindow
parameter_list|()
function_decl|;
end_function_decl
begin_expr_stmt
name|virtual
name|QPlatformGLContext
operator|*
name|glContext
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_label
name|protected
label|:
end_label
begin_expr_stmt
name|QScopedPointer
operator|<
name|QPlatformWindowPrivate
operator|>
name|d_ptr
expr_stmt|;
end_expr_stmt
begin_label
name|private
label|:
end_label
begin_macro
name|Q_DISABLE_COPY
argument_list|(
argument|QPlatformWindow
argument_list|)
end_macro
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
comment|//QPLATFORMWINDOW_H
end_comment
end_unit
