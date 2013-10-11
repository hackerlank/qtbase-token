begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QEGLFSSCREEN_H
end_ifndef
begin_define
DECL|macro|QEGLFSSCREEN_H
define|#
directive|define
name|QEGLFSSCREEN_H
end_define
begin_include
include|#
directive|include
file|<qpa/qplatformscreen.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/QTextStream>
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
DECL|variable|QEglFSWindow
name|class
name|QEglFSWindow
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QOpenGLContext
name|class
name|QOpenGLContext
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QEglFSScreen
range|:
name|public
name|QPlatformScreen
block|{
name|public
operator|:
name|QEglFSScreen
argument_list|(
argument|EGLDisplay display
argument_list|)
block|;
operator|~
name|QEglFSScreen
argument_list|()
block|;
name|QRect
name|geometry
argument_list|()
specifier|const
block|;
name|int
name|depth
argument_list|()
specifier|const
block|;
name|QImage
operator|::
name|Format
name|format
argument_list|()
specifier|const
block|;
name|QSizeF
name|physicalSize
argument_list|()
specifier|const
block|;
name|QDpi
name|logicalDpi
argument_list|()
specifier|const
block|;
name|Qt
operator|::
name|ScreenOrientation
name|nativeOrientation
argument_list|()
specifier|const
block|;
name|Qt
operator|::
name|ScreenOrientation
name|orientation
argument_list|()
specifier|const
block|;
name|QPlatformCursor
operator|*
name|cursor
argument_list|()
specifier|const
block|;
name|EGLDisplay
name|display
argument_list|()
specifier|const
block|{
return|return
name|m_dpy
return|;
block|}
name|EGLSurface
name|primarySurface
argument_list|()
specifier|const
block|{
return|return
name|m_surface
return|;
block|}
name|QList
operator|<
name|QEglFSWindow
operator|*
operator|>
name|windows
argument_list|()
specifier|const
block|{
return|return
name|m_windows
return|;
block|}
name|void
name|addWindow
argument_list|(
name|QEglFSWindow
operator|*
name|window
argument_list|)
block|;
name|void
name|removeWindow
argument_list|(
name|QEglFSWindow
operator|*
name|window
argument_list|)
block|;
name|void
name|moveToTop
argument_list|(
name|QEglFSWindow
operator|*
name|window
argument_list|)
block|;
name|void
name|changeWindowIndex
argument_list|(
argument|QEglFSWindow *window
argument_list|,
argument|int newIdx
argument_list|)
block|;
name|QEglFSWindow
operator|*
name|rootWindow
argument_list|()
block|;
name|QOpenGLContext
operator|*
name|rootContext
argument_list|()
block|{
return|return
name|m_rootContext
return|;
block|}
name|void
name|setRootContext
argument_list|(
argument|QOpenGLContext *context
argument_list|)
block|{
name|m_rootContext
operator|=
name|context
block|; }
name|protected
operator|:
name|void
name|setPrimarySurface
argument_list|(
argument|EGLSurface surface
argument_list|)
block|;
name|private
operator|:
name|friend
name|class
name|QEglFSWindow
block|;
name|EGLDisplay
name|m_dpy
block|;
name|EGLSurface
name|m_surface
block|;
name|QEglFSCursor
operator|*
name|m_cursor
block|;
name|QList
operator|<
name|QEglFSWindow
operator|*
operator|>
name|m_windows
block|;
name|QOpenGLContext
operator|*
name|m_rootContext
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
comment|// QEGLFSSCREEN_H
end_comment
end_unit
