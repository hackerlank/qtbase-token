begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QKMSDEVICE_H
end_ifndef
begin_define
DECL|macro|QKMSDEVICE_H
define|#
directive|define
name|QKMSDEVICE_H
end_define
begin_extern
extern|extern
literal|"C"
block|{
include|#
directive|include
file|<gbm.h>
block|}
end_extern
begin_include
include|#
directive|include
file|<EGL/egl.h>
end_include
begin_include
include|#
directive|include
file|<QObject>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|gbm_device
name|class
name|gbm_device
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QKmsIntegration
name|class
name|QKmsIntegration
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QKmsDevice
range|:
name|public
name|QObject
block|{
name|Q_OBJECT
name|public
operator|:
name|explicit
name|QKmsDevice
argument_list|(
specifier|const
name|QString
operator|&
name|path
argument_list|,
name|QKmsIntegration
operator|*
name|parent
argument_list|)
block|;
operator|~
name|QKmsDevice
argument_list|()
block|;
name|EGLDisplay
name|eglDisplay
argument_list|()
block|{
return|return
name|m_eglDisplay
return|;
block|}
name|gbm_device
operator|*
name|gbmDevice
argument_list|()
block|{
return|return
name|m_graphicsBufferManager
return|;
block|}
name|EGLContext
name|eglContext
argument_list|()
block|{
return|return
name|m_eglContext
return|;
block|}
name|int
name|fd
argument_list|()
specifier|const
block|{
return|return
name|m_fd
return|;
block|}
specifier|static
name|void
name|pageFlipHandler
argument_list|(
argument|int fd
argument_list|,
argument|unsigned int frame
argument_list|,
argument|unsigned int sec
argument_list|,
argument|unsigned int usec
argument_list|,
argument|void *data
argument_list|)
block|;
name|public
name|slots
operator|:
name|void
name|handlePageFlipCompleted
argument_list|()
block|;
name|private
operator|:
name|void
name|createScreens
argument_list|()
block|;
name|QKmsIntegration
operator|*
name|m_integration
block|;
name|EGLDisplay
name|m_eglDisplay
block|;
name|EGLContext
name|m_eglContext
block|;
name|gbm_device
operator|*
name|m_graphicsBufferManager
block|;
name|int
name|m_fd
block|; }
decl_stmt|;
end_decl_stmt
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QKMSDEVICE_H
end_comment
end_unit
