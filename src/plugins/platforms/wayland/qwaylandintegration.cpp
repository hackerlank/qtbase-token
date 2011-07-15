begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the config.tests of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qwaylandintegration.h"
end_include
begin_include
include|#
directive|include
file|"qwaylanddisplay.h"
end_include
begin_include
include|#
directive|include
file|"qwaylandshmbackingstore.h"
end_include
begin_include
include|#
directive|include
file|"qwaylandshmwindow.h"
end_include
begin_include
include|#
directive|include
file|"qwaylandnativeinterface.h"
end_include
begin_include
include|#
directive|include
file|"qwaylandclipboard.h"
end_include
begin_include
include|#
directive|include
file|"QtPlatformSupport/private/qgenericunixfontdatabase_p.h"
end_include
begin_include
include|#
directive|include
file|<QtPlatformSupport/private/qgenericunixeventdispatcher_p.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/QWindowSystemInterface>
end_include
begin_include
include|#
directive|include
file|<QtGui/QPlatformCursor>
end_include
begin_include
include|#
directive|include
file|<QtGui/QSurfaceFormat>
end_include
begin_include
include|#
directive|include
file|<QtGui/private/qpixmap_raster_p.h>
end_include
begin_ifdef
ifdef|#
directive|ifdef
name|QT_WAYLAND_GL_SUPPORT
end_ifdef
begin_include
include|#
directive|include
file|"gl_integration/qwaylandglintegration.h"
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_constructor
DECL|function|QWaylandIntegration
name|QWaylandIntegration
operator|::
name|QWaylandIntegration
parameter_list|()
member_init_list|:
name|mFontDb
argument_list|(
operator|new
name|QGenericUnixFontDatabase
argument_list|()
argument_list|)
member_init_list|,
name|mDisplay
argument_list|(
operator|new
name|QWaylandDisplay
argument_list|()
argument_list|)
member_init_list|,
name|mNativeInterface
argument_list|(
operator|new
name|QWaylandNativeInterface
argument_list|)
block|{ }
end_constructor
begin_function
DECL|function|nativeInterface
name|QPlatformNativeInterface
modifier|*
name|QWaylandIntegration
operator|::
name|nativeInterface
parameter_list|()
specifier|const
block|{
return|return
name|mNativeInterface
return|;
block|}
end_function
begin_function
name|QList
argument_list|<
name|QPlatformScreen
modifier|*
argument_list|>
DECL|function|screens
name|QWaylandIntegration
operator|::
name|screens
parameter_list|()
specifier|const
block|{
return|return
name|mDisplay
operator|->
name|screens
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|hasCapability
name|bool
name|QWaylandIntegration
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
case|case
name|OpenGL
case|:
ifdef|#
directive|ifdef
name|QT_WAYLAND_GL_SUPPORT
return|return
literal|true
return|;
else|#
directive|else
return|return
literal|false
return|;
endif|#
directive|endif
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
DECL|function|createPlatformPixmap
name|QPlatformPixmap
modifier|*
name|QWaylandIntegration
operator|::
name|createPlatformPixmap
parameter_list|(
name|QPlatformPixmap
operator|::
name|PixelType
name|type
parameter_list|)
specifier|const
block|{
return|return
operator|new
name|QRasterPlatformPixmap
argument_list|(
name|type
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|createPlatformWindow
name|QPlatformWindow
modifier|*
name|QWaylandIntegration
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
name|QT_WAYLAND_GL_SUPPORT
if|if
condition|(
name|window
operator|->
name|surfaceType
argument_list|()
operator|==
name|QWindow
operator|::
name|OpenGLSurface
condition|)
return|return
name|mDisplay
operator|->
name|eglIntegration
argument_list|()
operator|->
name|createEglWindow
argument_list|(
name|window
argument_list|)
return|;
endif|#
directive|endif
return|return
operator|new
name|QWaylandShmWindow
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
name|QWaylandIntegration
operator|::
name|createPlatformGLContext
parameter_list|(
specifier|const
name|QSurfaceFormat
modifier|&
name|glFormat
parameter_list|,
name|QPlatformGLContext
modifier|*
name|share
parameter_list|)
specifier|const
block|{
ifdef|#
directive|ifdef
name|QT_WAYLAND_GL_SUPPORT
return|return
name|mDisplay
operator|->
name|eglIntegration
argument_list|()
operator|->
name|createPlatformGLContext
argument_list|(
name|glFormat
argument_list|,
name|share
argument_list|)
return|;
else|#
directive|else
name|Q_UNUSED
argument_list|(
name|glFormat
argument_list|)
expr_stmt|;
name|Q_UNUSED
argument_list|(
name|share
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
endif|#
directive|endif
block|}
end_function
begin_function
DECL|function|createPlatformBackingStore
name|QPlatformBackingStore
modifier|*
name|QWaylandIntegration
operator|::
name|createPlatformBackingStore
parameter_list|(
name|QWindow
modifier|*
name|window
parameter_list|)
specifier|const
block|{
return|return
operator|new
name|QWaylandShmBackingStore
argument_list|(
name|window
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|createEventDispatcher
name|QAbstractEventDispatcher
modifier|*
name|QWaylandIntegration
operator|::
name|createEventDispatcher
parameter_list|()
specifier|const
block|{
name|QAbstractEventDispatcher
modifier|*
name|dispatcher
init|=
name|createUnixEventDispatcher
argument_list|()
decl_stmt|;
name|mDisplay
operator|->
name|eventDispatcherCreated
argument_list|(
name|dispatcher
argument_list|)
expr_stmt|;
return|return
name|dispatcher
return|;
block|}
end_function
begin_function
DECL|function|fontDatabase
name|QPlatformFontDatabase
modifier|*
name|QWaylandIntegration
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
DECL|function|clipboard
name|QPlatformClipboard
modifier|*
name|QWaylandIntegration
operator|::
name|clipboard
parameter_list|()
specifier|const
block|{
return|return
name|QWaylandClipboard
operator|::
name|instance
argument_list|(
name|mDisplay
argument_list|)
return|;
block|}
end_function
end_unit
