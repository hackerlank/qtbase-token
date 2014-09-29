begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2014 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia. For licensing terms and ** conditions see http://qt.digia.com/licensing. For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights. These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qwinrtwindow.h"
end_include
begin_include
include|#
directive|include
file|"qwinrtscreen.h"
end_include
begin_include
include|#
directive|include
file|<qpa/qwindowsysteminterface.h>
end_include
begin_include
include|#
directive|include
file|<qpa/qplatformscreen.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/QGuiApplication>
end_include
begin_include
include|#
directive|include
file|<QtGui/QWindow>
end_include
begin_include
include|#
directive|include
file|<QtGui/QOpenGLContext>
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_constructor
DECL|function|QWinRTWindow
name|QWinRTWindow
operator|::
name|QWinRTWindow
parameter_list|(
name|QWindow
modifier|*
name|window
parameter_list|)
member_init_list|:
name|QPlatformWindow
argument_list|(
name|window
argument_list|)
member_init_list|,
name|m_screen
argument_list|(
cast|static_cast
argument_list|<
name|QWinRTScreen
operator|*
argument_list|>
argument_list|(
name|screen
argument_list|()
argument_list|)
argument_list|)
block|{
name|setWindowFlags
argument_list|(
name|window
operator|->
name|flags
argument_list|()
argument_list|)
expr_stmt|;
name|setWindowState
argument_list|(
name|window
operator|->
name|windowState
argument_list|()
argument_list|)
expr_stmt|;
name|handleContentOrientationChange
argument_list|(
name|window
operator|->
name|contentOrientation
argument_list|()
argument_list|)
expr_stmt|;
name|setGeometry
argument_list|(
name|window
operator|->
name|geometry
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_destructor
DECL|function|~QWinRTWindow
name|QWinRTWindow
operator|::
name|~
name|QWinRTWindow
parameter_list|()
block|{
name|m_screen
operator|->
name|removeWindow
argument_list|(
name|window
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_destructor
begin_function
DECL|function|format
name|QSurfaceFormat
name|QWinRTWindow
operator|::
name|format
parameter_list|()
specifier|const
block|{
return|return
name|m_screen
operator|->
name|surfaceFormat
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|isActive
name|bool
name|QWinRTWindow
operator|::
name|isActive
parameter_list|()
specifier|const
block|{
return|return
name|m_screen
operator|->
name|topWindow
argument_list|()
operator|==
name|window
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|isExposed
name|bool
name|QWinRTWindow
operator|::
name|isExposed
parameter_list|()
specifier|const
block|{
specifier|const
name|bool
name|exposed
init|=
name|isActive
argument_list|()
decl_stmt|;
return|return
name|exposed
return|;
block|}
end_function
begin_function
DECL|function|setGeometry
name|void
name|QWinRTWindow
operator|::
name|setGeometry
parameter_list|(
specifier|const
name|QRect
modifier|&
name|rect
parameter_list|)
block|{
if|if
condition|(
name|window
argument_list|()
operator|->
name|isTopLevel
argument_list|()
condition|)
block|{
name|QPlatformWindow
operator|::
name|setGeometry
argument_list|(
name|m_screen
operator|->
name|geometry
argument_list|()
argument_list|)
expr_stmt|;
name|QWindowSystemInterface
operator|::
name|handleGeometryChange
argument_list|(
name|window
argument_list|()
argument_list|,
name|geometry
argument_list|()
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|QPlatformWindow
operator|::
name|setGeometry
argument_list|(
name|rect
argument_list|)
expr_stmt|;
name|QWindowSystemInterface
operator|::
name|handleGeometryChange
argument_list|(
name|window
argument_list|()
argument_list|,
name|rect
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|setVisible
name|void
name|QWinRTWindow
operator|::
name|setVisible
parameter_list|(
name|bool
name|visible
parameter_list|)
block|{
if|if
condition|(
operator|!
name|window
argument_list|()
operator|->
name|isTopLevel
argument_list|()
condition|)
return|return;
if|if
condition|(
name|visible
condition|)
name|m_screen
operator|->
name|addWindow
argument_list|(
name|window
argument_list|()
argument_list|)
expr_stmt|;
else|else
name|m_screen
operator|->
name|removeWindow
argument_list|(
name|window
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|raise
name|void
name|QWinRTWindow
operator|::
name|raise
parameter_list|()
block|{
if|if
condition|(
operator|!
name|window
argument_list|()
operator|->
name|isTopLevel
argument_list|()
condition|)
return|return;
name|m_screen
operator|->
name|raise
argument_list|(
name|window
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|lower
name|void
name|QWinRTWindow
operator|::
name|lower
parameter_list|()
block|{
if|if
condition|(
operator|!
name|window
argument_list|()
operator|->
name|isTopLevel
argument_list|()
condition|)
return|return;
name|m_screen
operator|->
name|lower
argument_list|(
name|window
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|devicePixelRatio
name|qreal
name|QWinRTWindow
operator|::
name|devicePixelRatio
parameter_list|()
specifier|const
block|{
return|return
name|screen
argument_list|()
operator|->
name|devicePixelRatio
argument_list|()
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
