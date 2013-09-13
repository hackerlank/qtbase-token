begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qeglfscursor.h"
end_include
begin_include
include|#
directive|include
file|"qeglfsscreen.h"
end_include
begin_include
include|#
directive|include
file|"qeglfswindow.h"
end_include
begin_include
include|#
directive|include
file|"qeglfshooks.h"
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_constructor
DECL|function|QEglFSScreen
name|QEglFSScreen
operator|::
name|QEglFSScreen
parameter_list|(
name|EGLDisplay
name|dpy
parameter_list|)
member_init_list|:
name|m_dpy
argument_list|(
name|dpy
argument_list|)
member_init_list|,
name|m_surface
argument_list|(
name|EGL_NO_SURFACE
argument_list|)
member_init_list|,
name|m_cursor
argument_list|(
literal|0
argument_list|)
block|{
ifdef|#
directive|ifdef
name|QEGL_EXTRA_DEBUG
name|qWarning
argument_list|(
literal|"QEglScreen %p\n"
argument_list|,
name|this
argument_list|)
expr_stmt|;
endif|#
directive|endif
specifier|static
name|int
name|hideCursor
init|=
name|qgetenv
argument_list|(
literal|"QT_QPA_EGLFS_HIDECURSOR"
argument_list|)
operator|.
name|toInt
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
name|hideCursor
condition|)
name|m_cursor
operator|=
name|QEglFSHooks
operator|::
name|hooks
argument_list|()
operator|->
name|createCursor
argument_list|(
name|this
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_destructor
DECL|function|~QEglFSScreen
name|QEglFSScreen
operator|::
name|~
name|QEglFSScreen
parameter_list|()
block|{
operator|delete
name|m_cursor
expr_stmt|;
block|}
end_destructor
begin_function
DECL|function|geometry
name|QRect
name|QEglFSScreen
operator|::
name|geometry
parameter_list|()
specifier|const
block|{
return|return
name|QRect
argument_list|(
name|QPoint
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
argument_list|,
name|QEglFSHooks
operator|::
name|hooks
argument_list|()
operator|->
name|screenSize
argument_list|()
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|depth
name|int
name|QEglFSScreen
operator|::
name|depth
parameter_list|()
specifier|const
block|{
return|return
name|QEglFSHooks
operator|::
name|hooks
argument_list|()
operator|->
name|screenDepth
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|format
name|QImage
operator|::
name|Format
name|QEglFSScreen
operator|::
name|format
parameter_list|()
specifier|const
block|{
return|return
name|QEglFSHooks
operator|::
name|hooks
argument_list|()
operator|->
name|screenFormat
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|physicalSize
name|QSizeF
name|QEglFSScreen
operator|::
name|physicalSize
parameter_list|()
specifier|const
block|{
return|return
name|QEglFSHooks
operator|::
name|hooks
argument_list|()
operator|->
name|physicalScreenSize
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|logicalDpi
name|QDpi
name|QEglFSScreen
operator|::
name|logicalDpi
parameter_list|()
specifier|const
block|{
return|return
name|QEglFSHooks
operator|::
name|hooks
argument_list|()
operator|->
name|logicalDpi
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|nativeOrientation
name|Qt
operator|::
name|ScreenOrientation
name|QEglFSScreen
operator|::
name|nativeOrientation
parameter_list|()
specifier|const
block|{
return|return
name|QEglFSHooks
operator|::
name|hooks
argument_list|()
operator|->
name|nativeOrientation
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|orientation
name|Qt
operator|::
name|ScreenOrientation
name|QEglFSScreen
operator|::
name|orientation
parameter_list|()
specifier|const
block|{
return|return
name|QEglFSHooks
operator|::
name|hooks
argument_list|()
operator|->
name|orientation
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|cursor
name|QPlatformCursor
modifier|*
name|QEglFSScreen
operator|::
name|cursor
parameter_list|()
specifier|const
block|{
return|return
name|m_cursor
return|;
block|}
end_function
begin_function
DECL|function|setPrimarySurface
name|void
name|QEglFSScreen
operator|::
name|setPrimarySurface
parameter_list|(
name|EGLSurface
name|surface
parameter_list|)
block|{
name|m_surface
operator|=
name|surface
expr_stmt|;
block|}
end_function
begin_function
DECL|function|addWindow
name|void
name|QEglFSScreen
operator|::
name|addWindow
parameter_list|(
name|QEglFSWindow
modifier|*
name|window
parameter_list|)
block|{
if|if
condition|(
operator|!
name|m_windows
operator|.
name|contains
argument_list|(
name|window
argument_list|)
condition|)
name|m_windows
operator|.
name|append
argument_list|(
name|window
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|removeWindow
name|void
name|QEglFSScreen
operator|::
name|removeWindow
parameter_list|(
name|QEglFSWindow
modifier|*
name|window
parameter_list|)
block|{
name|m_windows
operator|.
name|removeOne
argument_list|(
name|window
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|rootWindow
name|QEglFSWindow
modifier|*
name|QEglFSScreen
operator|::
name|rootWindow
parameter_list|()
block|{
name|Q_FOREACH
argument_list|(
argument|QEglFSWindow *window
argument_list|,
argument|m_windows
argument_list|)
block|{
if|if
condition|(
name|window
operator|->
name|isRasterRoot
argument_list|()
condition|)
return|return
name|window
return|;
block|}
return|return
literal|0
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
