begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QEGLFSHOOKS_H
end_ifndef
begin_define
DECL|macro|QEGLFSHOOKS_H
define|#
directive|define
name|QEGLFSHOOKS_H
end_define
begin_include
include|#
directive|include
file|<qpa/qplatformintegration.h>
end_include
begin_include
include|#
directive|include
file|<EGL/egl.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QEglFSCursor
name|class
name|QEglFSCursor
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QEglFSScreen
name|class
name|QEglFSScreen
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QEglFSHooks
block|{
name|public
label|:
name|virtual
name|void
name|platformInit
parameter_list|()
function_decl|;
name|virtual
name|void
name|platformDestroy
parameter_list|()
function_decl|;
name|virtual
name|EGLNativeDisplayType
name|platformDisplay
argument_list|()
specifier|const
expr_stmt|;
name|virtual
name|QSize
name|screenSize
argument_list|()
specifier|const
expr_stmt|;
name|virtual
name|EGLNativeWindowType
name|createNativeWindow
parameter_list|(
specifier|const
name|QSize
modifier|&
name|size
parameter_list|)
function_decl|;
name|virtual
name|void
name|destroyNativeWindow
parameter_list|(
name|EGLNativeWindowType
name|window
parameter_list|)
function_decl|;
name|virtual
name|bool
name|hasCapability
argument_list|(
name|QPlatformIntegration
operator|::
name|Capability
name|cap
argument_list|)
decl|const
decl_stmt|;
name|virtual
name|QEglFSCursor
modifier|*
name|createCursor
argument_list|(
name|QEglFSScreen
operator|*
name|screen
argument_list|)
decl|const
decl_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_ifdef
ifdef|#
directive|ifdef
name|EGLFS_PLATFORM_HOOKS
end_ifdef
begin_decl_stmt
specifier|extern
name|QEglFSHooks
modifier|*
name|platformHooks
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|hooks
specifier|static
name|QEglFSHooks
modifier|*
name|hooks
init|=
name|platformHooks
decl_stmt|;
end_decl_stmt
begin_else
else|#
directive|else
end_else
begin_decl_stmt
specifier|extern
name|QEglFSHooks
name|stubHooks
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|hooks
specifier|static
name|QEglFSHooks
modifier|*
name|hooks
init|=
operator|&
name|stubHooks
decl_stmt|;
end_decl_stmt
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
comment|// QEGLFSHOOKS_H
end_comment
end_unit
