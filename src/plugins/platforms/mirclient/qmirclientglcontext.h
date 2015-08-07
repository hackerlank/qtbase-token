begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2014 Canonical, Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL3$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPLv3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or later as published by the Free ** Software Foundation and appearing in the file LICENSE.GPL included in ** the packaging of this file. Please review the following information to ** ensure the GNU General Public License version 2.0 requirements will be ** met: http://www.gnu.org/licenses/gpl-2.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QMIRCLIENTGLCONTEXT_H
end_ifndef
begin_define
DECL|macro|QMIRCLIENTGLCONTEXT_H
define|#
directive|define
name|QMIRCLIENTGLCONTEXT_H
end_define
begin_include
include|#
directive|include
file|<qpa/qplatformopenglcontext.h>
end_include
begin_include
include|#
directive|include
file|"qmirclientscreen.h"
end_include
begin_decl_stmt
name|class
name|QMirClientOpenGLContext
range|:
name|public
name|QPlatformOpenGLContext
block|{
name|public
operator|:
name|QMirClientOpenGLContext
argument_list|(
name|QMirClientScreen
operator|*
name|screen
argument_list|,
name|QMirClientOpenGLContext
operator|*
name|share
argument_list|)
block|;
name|virtual
operator|~
name|QMirClientOpenGLContext
argument_list|()
block|;
comment|// QPlatformOpenGLContext methods.
name|QSurfaceFormat
name|format
argument_list|()
specifier|const
name|override
block|{
return|return
name|mScreen
operator|->
name|surfaceFormat
argument_list|()
return|;
block|}
name|void
name|swapBuffers
argument_list|(
argument|QPlatformSurface* surface
argument_list|)
name|override
block|;
name|bool
name|makeCurrent
argument_list|(
argument|QPlatformSurface* surface
argument_list|)
name|override
block|;
name|void
name|doneCurrent
argument_list|()
name|override
block|;
name|bool
name|isValid
argument_list|()
specifier|const
name|override
block|{
return|return
name|mEglContext
operator|!=
name|EGL_NO_CONTEXT
return|;
block|}
name|void
argument_list|(
operator|*
name|getProcAddress
argument_list|(
specifier|const
name|QByteArray
operator|&
name|procName
argument_list|)
argument_list|)
argument_list|()
block|;
name|EGLContext
name|eglContext
argument_list|()
specifier|const
block|{
return|return
name|mEglContext
return|;
block|}
name|private
operator|:
name|QMirClientScreen
operator|*
name|mScreen
block|;
name|EGLContext
name|mEglContext
block|;
name|EGLDisplay
name|mEglDisplay
block|; }
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QMIRCLIENTGLCONTEXT_H
end_comment
end_unit
