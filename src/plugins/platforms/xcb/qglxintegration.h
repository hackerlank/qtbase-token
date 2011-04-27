begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** No Commercial Usage ** This file contains pre-release code and may not be distributed. ** You may use this file in accordance with the terms and conditions ** contained in the Technology Preview License Agreement accompanying ** this package. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights.  These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** If you have questions regarding the use of this file, please contact ** Nokia at qt-info@nokia.com. ** ** ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QGLXINTEGRATION_H
end_ifndef
begin_define
DECL|macro|QGLXINTEGRATION_H
define|#
directive|define
name|QGLXINTEGRATION_H
end_define
begin_include
include|#
directive|include
file|"qxcbwindow.h"
end_include
begin_include
include|#
directive|include
file|<QtGui/QPlatformGLContext>
end_include
begin_include
include|#
directive|include
file|<QtGui/QPlatformWindowFormat>
end_include
begin_include
include|#
directive|include
file|<QtCore/QMutex>
end_include
begin_include
include|#
directive|include
file|<GL/glx.h>
end_include
begin_decl_stmt
name|class
name|QGLXContext
range|:
name|public
name|QPlatformGLContext
block|{
name|public
operator|:
name|QGLXContext
argument_list|(
argument|Window window
argument_list|,
argument|QXcbScreen *xd
argument_list|,
argument|const QPlatformWindowFormat&format
argument_list|)
block|;
operator|~
name|QGLXContext
argument_list|()
block|;
name|virtual
name|void
name|makeCurrent
argument_list|()
block|;
name|virtual
name|void
name|doneCurrent
argument_list|()
block|;
name|virtual
name|void
name|swapBuffers
argument_list|()
block|;
name|virtual
name|void
operator|*
name|getProcAddress
argument_list|(
specifier|const
name|QString
operator|&
name|procName
argument_list|)
block|;
name|GLXContext
name|glxContext
argument_list|()
specifier|const
block|{
return|return
name|m_context
return|;
block|}
name|QPlatformWindowFormat
name|platformWindowFormat
argument_list|()
specifier|const
block|;
name|private
operator|:
name|QXcbScreen
operator|*
name|m_screen
block|;
name|Drawable
name|m_drawable
block|;
name|GLXContext
name|m_context
block|;
name|QPlatformWindowFormat
name|m_windowFormat
block|;
name|QGLXContext
argument_list|(
argument|QXcbScreen *screen
argument_list|,
argument|Drawable drawable
argument_list|,
argument|GLXContext context
argument_list|)
block|; }
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
end_unit
