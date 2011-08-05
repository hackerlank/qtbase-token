begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qeglfsintegration.h"
end_include
begin_include
include|#
directive|include
file|"qeglfswindow.h"
end_include
begin_include
include|#
directive|include
file|"qeglfsbackingstore.h"
end_include
begin_include
include|#
directive|include
file|<QtPlatformSupport/private/qgenericunixfontdatabase_p.h>
end_include
begin_include
include|#
directive|include
file|<QtPlatformSupport/private/qgenericunixeventdispatcher_p.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/QPlatformWindow>
end_include
begin_include
include|#
directive|include
file|<QtGui/QSurfaceFormat>
end_include
begin_include
include|#
directive|include
file|<QtGui/QGuiGLContext>
end_include
begin_include
include|#
directive|include
file|<QtGui/QScreen>
end_include
begin_include
include|#
directive|include
file|<EGL/egl.h>
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_constructor
DECL|function|QEglFSIntegration
name|QEglFSIntegration
operator|::
name|QEglFSIntegration
parameter_list|()
member_init_list|:
name|mFontDb
argument_list|(
operator|new
name|QGenericUnixFontDatabase
argument_list|()
argument_list|)
block|{
name|screenAdded
argument_list|(
operator|new
name|QEglFSScreen
argument_list|(
name|EGL_DEFAULT_DISPLAY
argument_list|)
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|QEGL_EXTRA_DEBUG
name|qWarning
argument_list|(
literal|"QEglIntegration\n"
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
end_constructor
begin_function
DECL|function|hasCapability
name|bool
name|QEglFSIntegration
operator|::
name|hasCapability
parameter_list|(
name|QPlatformIntegration
operator|::
name|Capability
name|cap
parameter_list|)
specifier|const
block|{
switch|switch
condition|(
name|cap
condition|)
block|{
case|case
name|ThreadedPixmaps
case|:
return|return
literal|true
return|;
default|default:
return|return
name|QPlatformIntegration
operator|::
name|hasCapability
argument_list|(
name|cap
argument_list|)
return|;
block|}
block|}
end_function
begin_function
DECL|function|createPlatformWindow
name|QPlatformWindow
modifier|*
name|QEglFSIntegration
operator|::
name|createPlatformWindow
parameter_list|(
name|QWindow
modifier|*
name|window
parameter_list|)
specifier|const
block|{
ifdef|#
directive|ifdef
name|QEGL_EXTRA_DEBUG
name|qWarning
argument_list|(
literal|"QEglIntegration::createPlatformWindow %p\n"
argument_list|,
name|window
argument_list|)
expr_stmt|;
endif|#
directive|endif
return|return
operator|new
name|QEglFSWindow
argument_list|(
name|window
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|createPlatformBackingStore
name|QPlatformBackingStore
modifier|*
name|QEglFSIntegration
operator|::
name|createPlatformBackingStore
parameter_list|(
name|QWindow
modifier|*
name|window
parameter_list|)
specifier|const
block|{
ifdef|#
directive|ifdef
name|QEGL_EXTRA_DEBUG
name|qWarning
argument_list|(
literal|"QEglIntegration::createWindowSurface %p\n"
argument_list|,
name|widget
argument_list|)
expr_stmt|;
endif|#
directive|endif
return|return
operator|new
name|QEglFSBackingStore
argument_list|(
name|window
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|createPlatformGLContext
name|QPlatformGLContext
modifier|*
name|QEglFSIntegration
operator|::
name|createPlatformGLContext
parameter_list|(
name|QGuiGLContext
modifier|*
name|context
parameter_list|)
specifier|const
block|{
return|return
cast|static_cast
argument_list|<
name|QEglFSScreen
operator|*
argument_list|>
argument_list|(
name|context
operator|->
name|screen
argument_list|()
operator|->
name|handle
argument_list|()
argument_list|)
operator|->
name|platformContext
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|fontDatabase
name|QPlatformFontDatabase
modifier|*
name|QEglFSIntegration
operator|::
name|fontDatabase
parameter_list|()
specifier|const
block|{
return|return
name|mFontDb
return|;
block|}
end_function
begin_function
DECL|function|guiThreadEventDispatcher
name|QAbstractEventDispatcher
modifier|*
name|QEglFSIntegration
operator|::
name|guiThreadEventDispatcher
parameter_list|()
specifier|const
block|{
return|return
name|createUnixEventDispatcher
argument_list|()
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
