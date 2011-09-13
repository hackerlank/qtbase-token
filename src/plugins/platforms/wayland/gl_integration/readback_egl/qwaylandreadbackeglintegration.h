begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QWAYLANDREADBACKEGLINTEGRATION_H
end_ifndef
begin_define
DECL|macro|QWAYLANDREADBACKEGLINTEGRATION_H
define|#
directive|define
name|QWAYLANDREADBACKEGLINTEGRATION_H
end_define
begin_include
include|#
directive|include
file|"gl_integration/qwaylandglintegration.h"
end_include
begin_include
include|#
directive|include
file|<QtCore/QTextStream>
end_include
begin_include
include|#
directive|include
file|<QtCore/QDataStream>
end_include
begin_include
include|#
directive|include
file|<QtCore/QMetaType>
end_include
begin_include
include|#
directive|include
file|<QtCore/QVariant>
end_include
begin_include
include|#
directive|include
file|<QtCore/QEvent>
end_include
begin_include
include|#
directive|include
file|<QtGui/QCursor>
end_include
begin_include
include|#
directive|include
file|<X11/Xlib.h>
end_include
begin_include
include|#
directive|include
file|<EGL/egl.h>
end_include
begin_decl_stmt
name|class
name|QWaylandReadbackEglIntegration
range|:
name|public
name|QWaylandGLIntegration
block|{
name|public
operator|:
name|QWaylandReadbackEglIntegration
argument_list|(
name|QWaylandDisplay
operator|*
name|display
argument_list|)
block|;
operator|~
name|QWaylandReadbackEglIntegration
argument_list|()
block|;
name|void
name|initialize
argument_list|()
block|;
name|QWaylandWindow
operator|*
name|createEglWindow
argument_list|(
name|QWindow
operator|*
name|window
argument_list|)
block|;
name|QPlatformOpenGLContext
operator|*
name|createPlatformOpenGLContext
argument_list|(
argument|const QSurfaceFormat&glFormat
argument_list|,
argument|QPlatformOpenGLContext *share
argument_list|)
specifier|const
block|;
name|QWaylandDisplay
operator|*
name|waylandDisplay
argument_list|()
specifier|const
block|;
name|Display
operator|*
name|xDisplay
argument_list|()
specifier|const
block|;
name|Window
name|rootWindow
argument_list|()
specifier|const
block|;
name|int
name|depth
argument_list|()
specifier|const
block|;
name|EGLDisplay
name|eglDisplay
argument_list|()
block|;
name|private
operator|:
name|QWaylandDisplay
operator|*
name|mWaylandDisplay
block|;
name|Display
operator|*
name|mDisplay
block|;
name|int
name|mScreen
block|;
name|Window
name|mRootWindow
block|;
name|EGLDisplay
name|mEglDisplay
block|;  }
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QWAYLANDREADBACKEGLINTEGRATION_H
end_comment
end_unit
