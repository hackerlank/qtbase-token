begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QEGLCONTEXT_P_H
end_ifndef
begin_define
DECL|macro|QEGLCONTEXT_P_H
define|#
directive|define
name|QEGLCONTEXT_P_H
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
comment|// This file is not part of the Qt API.  It exists for the convenience of
end_comment
begin_comment
comment|// the QtOpenGL and QtOpenVG modules.  This header file may change from
end_comment
begin_comment
comment|// version to version without notice, or even be removed.
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
file|<QtCore/qsize.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/qimage.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/private/qegl_p.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/private/qeglproperties_p.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
name|class
name|Q_GUI_EXPORT
name|QEglContext
block|{
name|public
label|:
name|QEglContext
argument_list|()
expr_stmt|;
operator|~
name|QEglContext
argument_list|()
expr_stmt|;
name|bool
name|isValid
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|isCurrent
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|isSharing
argument_list|()
specifier|const
block|{
return|return
name|sharing
return|;
block|}
name|QEgl
operator|::
name|API
name|api
argument_list|()
specifier|const
block|{
return|return
name|apiType
return|;
block|}
name|void
name|setApi
argument_list|(
name|QEgl
operator|::
name|API
name|api
argument_list|)
block|{
name|apiType
operator|=
name|api
expr_stmt|;
block|}
name|bool
name|chooseConfig
argument_list|(
specifier|const
name|QEglProperties
operator|&
name|properties
argument_list|,
name|QEgl
operator|::
name|PixelFormatMatch
name|match
operator|=
name|QEgl
operator|::
name|ExactPixelFormat
argument_list|)
decl_stmt|;
name|bool
name|createContext
parameter_list|(
name|QEglContext
modifier|*
name|shareContext
init|=
literal|0
parameter_list|,
specifier|const
name|QEglProperties
modifier|*
name|properties
init|=
literal|0
parameter_list|)
function_decl|;
name|void
name|destroyContext
parameter_list|()
function_decl|;
name|EGLSurface
name|createSurface
parameter_list|(
name|QPaintDevice
modifier|*
name|device
parameter_list|,
specifier|const
name|QEglProperties
modifier|*
name|properties
init|=
literal|0
parameter_list|)
function_decl|;
name|void
name|destroySurface
parameter_list|(
name|EGLSurface
name|surface
parameter_list|)
function_decl|;
name|bool
name|makeCurrent
parameter_list|(
name|EGLSurface
name|surface
parameter_list|)
function_decl|;
name|bool
name|doneCurrent
parameter_list|()
function_decl|;
name|bool
name|lazyDoneCurrent
parameter_list|()
function_decl|;
name|bool
name|swapBuffers
parameter_list|(
name|EGLSurface
name|surface
parameter_list|)
function_decl|;
name|bool
name|swapBuffersRegion2NOK
parameter_list|(
name|EGLSurface
name|surface
parameter_list|,
specifier|const
name|QRegion
modifier|*
name|region
parameter_list|)
function_decl|;
name|int
name|configAttrib
argument_list|(
name|int
name|name
argument_list|)
decl|const
decl_stmt|;
name|EGLContext
name|context
argument_list|()
specifier|const
block|{
return|return
name|ctx
return|;
block|}
name|void
name|setContext
parameter_list|(
name|EGLContext
name|context
parameter_list|)
block|{
name|ctx
operator|=
name|context
expr_stmt|;
name|ownsContext
operator|=
name|false
expr_stmt|;
block|}
name|EGLDisplay
name|display
parameter_list|()
block|{
return|return
name|QEgl
operator|::
name|display
argument_list|()
return|;
block|}
name|EGLConfig
name|config
argument_list|()
specifier|const
block|{
return|return
name|cfg
return|;
block|}
name|void
name|setConfig
parameter_list|(
name|EGLConfig
name|config
parameter_list|)
block|{
name|cfg
operator|=
name|config
expr_stmt|;
block|}
name|private
label|:
name|QEgl
operator|::
name|API
name|apiType
expr_stmt|;
name|EGLContext
name|ctx
decl_stmt|;
name|EGLConfig
name|cfg
decl_stmt|;
name|EGLSurface
name|currentSurface
decl_stmt|;
name|bool
name|current
decl_stmt|;
name|bool
name|ownsContext
decl_stmt|;
name|bool
name|sharing
decl_stmt|;
specifier|static
name|QEglContext
modifier|*
name|currentContext
argument_list|(
name|QEgl
operator|::
name|API
name|api
argument_list|)
decl_stmt|;
specifier|static
name|void
name|setCurrentContext
argument_list|(
name|QEgl
operator|::
name|API
name|api
argument_list|,
name|QEglContext
operator|*
name|context
argument_list|)
decl_stmt|;
name|friend
name|class
name|QMeeGoGraphicsSystem
decl_stmt|;
name|friend
name|class
name|QMeeGoPlatformPixmap
decl_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QEGLCONTEXT_P_H
end_comment
end_unit
