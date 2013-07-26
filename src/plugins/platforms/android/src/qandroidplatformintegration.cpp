begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 BogDan Vatra<bogdan@kde.org> ** Contact: http://www.qt-project.org/legal ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qandroidplatformintegration.h"
end_include
begin_include
include|#
directive|include
file|"qabstracteventdispatcher.h"
end_include
begin_include
include|#
directive|include
file|"androidjnimain.h"
end_include
begin_include
include|#
directive|include
file|<QtGui/private/qpixmap_raster_p.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/qguiapplication.h>
end_include
begin_include
include|#
directive|include
file|<qpa/qwindowsysteminterface.h>
end_include
begin_include
include|#
directive|include
file|<QThread>
end_include
begin_include
include|#
directive|include
file|<qpa/qplatformwindow.h>
end_include
begin_include
include|#
directive|include
file|"qandroidplatformservices.h"
end_include
begin_include
include|#
directive|include
file|"qandroidplatformfontdatabase.h"
end_include
begin_include
include|#
directive|include
file|"qandroidplatformclipboard.h"
end_include
begin_include
include|#
directive|include
file|"qandroidplatformaccessibility.h"
end_include
begin_include
include|#
directive|include
file|<QtPlatformSupport/private/qgenericunixeventdispatcher_p.h>
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|ANDROID_PLUGIN_OPENGL
end_ifndef
begin_include
include|#
directive|include
file|"qandroidplatformscreen.h"
end_include
begin_include
include|#
directive|include
file|"qandroidplatformwindow.h"
end_include
begin_include
include|#
directive|include
file|<QtPlatformSupport/private/qfbbackingstore_p.h>
end_include
begin_else
else|#
directive|else
end_else
begin_include
include|#
directive|include
file|"qeglfswindow.h"
end_include
begin_include
include|#
directive|include
file|"androidjnimenu.h"
end_include
begin_include
include|#
directive|include
file|"qandroidopenglcontext.h"
end_include
begin_include
include|#
directive|include
file|"qandroidopenglplatformwindow.h"
end_include
begin_include
include|#
directive|include
file|"qeglfshooks.h"
end_include
begin_include
include|#
directive|include
file|<QtGui/qopenglcontext.h>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_include
include|#
directive|include
file|"qandroidplatformtheme.h"
end_include
begin_include
include|#
directive|include
file|"qandroidsystemlocale.h"
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|member|m_defaultGeometryWidth
name|int
name|QAndroidPlatformIntegration
operator|::
name|m_defaultGeometryWidth
init|=
literal|320
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|member|m_defaultGeometryHeight
name|int
name|QAndroidPlatformIntegration
operator|::
name|m_defaultGeometryHeight
init|=
literal|455
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|member|m_defaultPhysicalSizeWidth
name|int
name|QAndroidPlatformIntegration
operator|::
name|m_defaultPhysicalSizeWidth
init|=
literal|50
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|member|m_defaultPhysicalSizeHeight
name|int
name|QAndroidPlatformIntegration
operator|::
name|m_defaultPhysicalSizeHeight
init|=
literal|71
decl_stmt|;
end_decl_stmt
begin_function
DECL|function|nativeResourceForIntegration
name|void
modifier|*
name|QAndroidPlatformNativeInterface
operator|::
name|nativeResourceForIntegration
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|resource
parameter_list|)
block|{
if|if
condition|(
name|resource
operator|==
literal|"JavaVM"
condition|)
return|return
name|QtAndroid
operator|::
name|javaVM
argument_list|()
return|;
if|if
condition|(
name|resource
operator|==
literal|"QtActivity"
condition|)
return|return
name|QtAndroid
operator|::
name|activity
argument_list|()
return|;
return|return
literal|0
return|;
block|}
end_function
begin_constructor
DECL|function|QAndroidPlatformIntegration
name|QAndroidPlatformIntegration
operator|::
name|QAndroidPlatformIntegration
parameter_list|(
specifier|const
name|QStringList
modifier|&
name|paramList
parameter_list|)
member_init_list|:
name|m_touchDevice
argument_list|(
literal|0
argument_list|)
ifndef|#
directive|ifndef
name|QT_NO_ACCESSIBILITY
member_init_list|,
name|m_accessibility
argument_list|(
literal|0
argument_list|)
endif|#
directive|endif
block|{
name|Q_UNUSED
argument_list|(
name|paramList
argument_list|)
expr_stmt|;
ifndef|#
directive|ifndef
name|ANDROID_PLUGIN_OPENGL
name|m_eventDispatcher
operator|=
name|createUnixEventDispatcher
argument_list|()
expr_stmt|;
endif|#
directive|endif
name|m_androidPlatformNativeInterface
operator|=
operator|new
name|QAndroidPlatformNativeInterface
argument_list|()
expr_stmt|;
ifndef|#
directive|ifndef
name|ANDROID_PLUGIN_OPENGL
name|m_primaryScreen
operator|=
operator|new
name|QAndroidPlatformScreen
argument_list|()
expr_stmt|;
name|screenAdded
argument_list|(
name|m_primaryScreen
argument_list|)
expr_stmt|;
name|m_primaryScreen
operator|->
name|setPhysicalSize
argument_list|(
name|QSize
argument_list|(
name|m_defaultPhysicalSizeWidth
argument_list|,
name|m_defaultPhysicalSizeHeight
argument_list|)
argument_list|)
expr_stmt|;
name|m_primaryScreen
operator|->
name|setGeometry
argument_list|(
name|QRect
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
name|m_defaultGeometryWidth
argument_list|,
name|m_defaultGeometryHeight
argument_list|)
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|m_mainThread
operator|=
name|QThread
operator|::
name|currentThread
argument_list|()
expr_stmt|;
name|QtAndroid
operator|::
name|setAndroidPlatformIntegration
argument_list|(
name|this
argument_list|)
expr_stmt|;
name|m_androidFDB
operator|=
operator|new
name|QAndroidPlatformFontDatabase
argument_list|()
expr_stmt|;
name|m_androidPlatformServices
operator|=
operator|new
name|QAndroidPlatformServices
argument_list|()
expr_stmt|;
name|m_androidPlatformClipboard
operator|=
operator|new
name|QAndroidPlatformClipboard
argument_list|()
expr_stmt|;
name|m_androidSystemLocale
operator|=
operator|new
name|QAndroidSystemLocale
expr_stmt|;
block|}
end_constructor
begin_function
DECL|function|hasCapability
name|bool
name|QAndroidPlatformIntegration
operator|::
name|hasCapability
parameter_list|(
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
name|NonFullScreenWindows
case|:
return|return
literal|false
return|;
case|case
name|NativeWidgets
case|:
return|return
literal|false
return|;
default|default:
ifndef|#
directive|ifndef
name|ANDROID_PLUGIN_OPENGL
return|return
name|QPlatformIntegration
operator|::
name|hasCapability
argument_list|(
name|cap
argument_list|)
return|;
else|#
directive|else
return|return
name|QEglFSIntegration
operator|::
name|hasCapability
argument_list|(
name|cap
argument_list|)
return|;
endif|#
directive|endif
block|}
block|}
end_function
begin_ifndef
ifndef|#
directive|ifndef
name|ANDROID_PLUGIN_OPENGL
end_ifndef
begin_function
DECL|function|createPlatformBackingStore
name|QPlatformBackingStore
modifier|*
name|QAndroidPlatformIntegration
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
name|QFbBackingStore
argument_list|(
name|window
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|createPlatformWindow
name|QPlatformWindow
modifier|*
name|QAndroidPlatformIntegration
operator|::
name|createPlatformWindow
parameter_list|(
name|QWindow
modifier|*
name|window
parameter_list|)
specifier|const
block|{
return|return
operator|new
name|QAndroidPlatformWindow
argument_list|(
name|window
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|guiThreadEventDispatcher
name|QAbstractEventDispatcher
modifier|*
name|QAndroidPlatformIntegration
operator|::
name|guiThreadEventDispatcher
parameter_list|()
specifier|const
block|{
return|return
name|m_eventDispatcher
return|;
block|}
end_function
begin_else
else|#
directive|else
end_else
begin_comment
comment|// !ANDROID_PLUGIN_OPENGL
end_comment
begin_function
DECL|function|createPlatformWindow
name|QPlatformWindow
modifier|*
name|QAndroidPlatformIntegration
operator|::
name|createPlatformWindow
parameter_list|(
name|QWindow
modifier|*
name|window
parameter_list|)
specifier|const
block|{
name|QAndroidOpenGLPlatformWindow
modifier|*
name|platformWindow
init|=
operator|new
name|QAndroidOpenGLPlatformWindow
argument_list|(
name|window
argument_list|)
decl_stmt|;
name|platformWindow
operator|->
name|create
argument_list|()
expr_stmt|;
name|platformWindow
operator|->
name|requestActivateWindow
argument_list|()
expr_stmt|;
name|QtAndroidMenu
operator|::
name|setActiveTopLevelWindow
argument_list|(
name|window
argument_list|)
expr_stmt|;
return|return
name|platformWindow
return|;
block|}
end_function
begin_function
DECL|function|invalidateNativeSurface
name|void
name|QAndroidPlatformIntegration
operator|::
name|invalidateNativeSurface
parameter_list|()
block|{
foreach|foreach
control|(
name|QWindow
modifier|*
name|w
decl|,
name|QGuiApplication
operator|::
name|topLevelWindows
argument_list|()
control|)
block|{
name|QAndroidOpenGLPlatformWindow
modifier|*
name|window
init|=
cast|static_cast
argument_list|<
name|QAndroidOpenGLPlatformWindow
operator|*
argument_list|>
argument_list|(
name|w
operator|->
name|handle
argument_list|()
argument_list|)
decl_stmt|;
if|if
condition|(
name|window
operator|!=
literal|0
condition|)
name|window
operator|->
name|invalidateSurface
argument_list|()
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|surfaceChanged
name|void
name|QAndroidPlatformIntegration
operator|::
name|surfaceChanged
parameter_list|()
block|{
foreach|foreach
control|(
name|QWindow
modifier|*
name|w
decl|,
name|QGuiApplication
operator|::
name|topLevelWindows
argument_list|()
control|)
block|{
name|QAndroidOpenGLPlatformWindow
modifier|*
name|window
init|=
cast|static_cast
argument_list|<
name|QAndroidOpenGLPlatformWindow
operator|*
argument_list|>
argument_list|(
name|w
operator|->
name|handle
argument_list|()
argument_list|)
decl_stmt|;
if|if
condition|(
name|window
operator|!=
literal|0
condition|)
name|window
operator|->
name|resetSurface
argument_list|()
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|createPlatformOpenGLContext
name|QPlatformOpenGLContext
modifier|*
name|QAndroidPlatformIntegration
operator|::
name|createPlatformOpenGLContext
parameter_list|(
name|QOpenGLContext
modifier|*
name|context
parameter_list|)
specifier|const
block|{
return|return
operator|new
name|QAndroidOpenGLContext
argument_list|(
name|this
argument_list|,
name|QEglFSHooks
operator|::
name|hooks
argument_list|()
operator|->
name|surfaceFormatFor
argument_list|(
name|context
operator|->
name|format
argument_list|()
argument_list|)
argument_list|,
name|context
operator|->
name|shareHandle
argument_list|()
argument_list|,
name|display
argument_list|()
argument_list|)
return|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// ANDROID_PLUGIN_OPENGL
end_comment
begin_destructor
DECL|function|~QAndroidPlatformIntegration
name|QAndroidPlatformIntegration
operator|::
name|~
name|QAndroidPlatformIntegration
parameter_list|()
block|{
operator|delete
name|m_androidPlatformNativeInterface
expr_stmt|;
operator|delete
name|m_androidFDB
expr_stmt|;
operator|delete
name|m_androidSystemLocale
expr_stmt|;
name|QtAndroid
operator|::
name|setAndroidPlatformIntegration
argument_list|(
name|NULL
argument_list|)
expr_stmt|;
block|}
end_destructor
begin_function
DECL|function|fontDatabase
name|QPlatformFontDatabase
modifier|*
name|QAndroidPlatformIntegration
operator|::
name|fontDatabase
parameter_list|()
specifier|const
block|{
return|return
name|m_androidFDB
return|;
block|}
end_function
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_CLIPBOARD
end_ifndef
begin_function
DECL|function|clipboard
name|QPlatformClipboard
modifier|*
name|QAndroidPlatformIntegration
operator|::
name|clipboard
parameter_list|()
specifier|const
block|{
specifier|static
name|QAndroidPlatformClipboard
modifier|*
name|clipboard
init|=
literal|0
decl_stmt|;
if|if
condition|(
operator|!
name|clipboard
condition|)
name|clipboard
operator|=
operator|new
name|QAndroidPlatformClipboard
expr_stmt|;
return|return
name|clipboard
return|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_function
DECL|function|inputContext
name|QPlatformInputContext
modifier|*
name|QAndroidPlatformIntegration
operator|::
name|inputContext
parameter_list|()
specifier|const
block|{
return|return
operator|&
name|m_platformInputContext
return|;
block|}
end_function
begin_function
DECL|function|nativeInterface
name|QPlatformNativeInterface
modifier|*
name|QAndroidPlatformIntegration
operator|::
name|nativeInterface
parameter_list|()
specifier|const
block|{
return|return
name|m_androidPlatformNativeInterface
return|;
block|}
end_function
begin_function
DECL|function|services
name|QPlatformServices
modifier|*
name|QAndroidPlatformIntegration
operator|::
name|services
parameter_list|()
specifier|const
block|{
return|return
name|m_androidPlatformServices
return|;
block|}
end_function
begin_function
DECL|function|styleHint
name|QVariant
name|QAndroidPlatformIntegration
operator|::
name|styleHint
parameter_list|(
name|StyleHint
name|hint
parameter_list|)
specifier|const
block|{
switch|switch
condition|(
name|hint
condition|)
block|{
case|case
name|ShowIsFullScreen
case|:
return|return
literal|true
return|;
default|default:
return|return
name|QPlatformIntegration
operator|::
name|styleHint
argument_list|(
name|hint
argument_list|)
return|;
block|}
block|}
end_function
begin_decl_stmt
specifier|static
specifier|const
name|QLatin1String
name|androidThemeName
argument_list|(
literal|"android"
argument_list|)
decl_stmt|;
end_decl_stmt
begin_function
DECL|function|themeNames
name|QStringList
name|QAndroidPlatformIntegration
operator|::
name|themeNames
parameter_list|()
specifier|const
block|{
return|return
name|QStringList
argument_list|(
name|QString
argument_list|(
name|androidThemeName
argument_list|)
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|createPlatformTheme
name|QPlatformTheme
modifier|*
name|QAndroidPlatformIntegration
operator|::
name|createPlatformTheme
parameter_list|(
specifier|const
name|QString
modifier|&
name|name
parameter_list|)
specifier|const
block|{
if|if
condition|(
name|androidThemeName
operator|==
name|name
condition|)
return|return
operator|new
name|QAndroidPlatformTheme
return|;
return|return
literal|0
return|;
block|}
end_function
begin_function
DECL|function|setDefaultDisplayMetrics
name|void
name|QAndroidPlatformIntegration
operator|::
name|setDefaultDisplayMetrics
parameter_list|(
name|int
name|gw
parameter_list|,
name|int
name|gh
parameter_list|,
name|int
name|sw
parameter_list|,
name|int
name|sh
parameter_list|)
block|{
name|m_defaultGeometryWidth
operator|=
name|gw
expr_stmt|;
name|m_defaultGeometryHeight
operator|=
name|gh
expr_stmt|;
name|m_defaultPhysicalSizeWidth
operator|=
name|sw
expr_stmt|;
name|m_defaultPhysicalSizeHeight
operator|=
name|sh
expr_stmt|;
block|}
end_function
begin_function
DECL|function|setDefaultDesktopSize
name|void
name|QAndroidPlatformIntegration
operator|::
name|setDefaultDesktopSize
parameter_list|(
name|int
name|gw
parameter_list|,
name|int
name|gh
parameter_list|)
block|{
name|m_defaultGeometryWidth
operator|=
name|gw
expr_stmt|;
name|m_defaultGeometryHeight
operator|=
name|gh
expr_stmt|;
block|}
end_function
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_ACCESSIBILITY
end_ifndef
begin_function
DECL|function|accessibility
name|QPlatformAccessibility
modifier|*
name|QAndroidPlatformIntegration
operator|::
name|accessibility
parameter_list|()
specifier|const
block|{
if|if
condition|(
operator|!
name|m_accessibility
condition|)
name|m_accessibility
operator|=
operator|new
name|QAndroidPlatformAccessibility
argument_list|()
expr_stmt|;
return|return
name|m_accessibility
return|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|ANDROID_PLUGIN_OPENGL
end_ifndef
begin_function
DECL|function|setDesktopSize
name|void
name|QAndroidPlatformIntegration
operator|::
name|setDesktopSize
parameter_list|(
name|int
name|width
parameter_list|,
name|int
name|height
parameter_list|)
block|{
if|if
condition|(
name|m_primaryScreen
condition|)
name|QMetaObject
operator|::
name|invokeMethod
argument_list|(
name|m_primaryScreen
argument_list|,
literal|"setGeometry"
argument_list|,
name|Qt
operator|::
name|AutoConnection
argument_list|,
name|Q_ARG
argument_list|(
name|QRect
argument_list|,
name|QRect
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
name|width
argument_list|,
name|height
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|setDisplayMetrics
name|void
name|QAndroidPlatformIntegration
operator|::
name|setDisplayMetrics
parameter_list|(
name|int
name|width
parameter_list|,
name|int
name|height
parameter_list|)
block|{
if|if
condition|(
name|m_primaryScreen
condition|)
name|QMetaObject
operator|::
name|invokeMethod
argument_list|(
name|m_primaryScreen
argument_list|,
literal|"setPhysicalSize"
argument_list|,
name|Qt
operator|::
name|AutoConnection
argument_list|,
name|Q_ARG
argument_list|(
name|QSize
argument_list|,
name|QSize
argument_list|(
name|width
argument_list|,
name|height
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_else
else|#
directive|else
end_else
begin_function
DECL|function|setDesktopSize
name|void
name|QAndroidPlatformIntegration
operator|::
name|setDesktopSize
parameter_list|(
name|int
name|width
parameter_list|,
name|int
name|height
parameter_list|)
block|{
name|m_defaultGeometryWidth
operator|=
name|width
expr_stmt|;
name|m_defaultGeometryHeight
operator|=
name|height
expr_stmt|;
block|}
end_function
begin_function
DECL|function|setDisplayMetrics
name|void
name|QAndroidPlatformIntegration
operator|::
name|setDisplayMetrics
parameter_list|(
name|int
name|width
parameter_list|,
name|int
name|height
parameter_list|)
block|{
name|m_defaultPhysicalSizeWidth
operator|=
name|width
expr_stmt|;
name|m_defaultPhysicalSizeHeight
operator|=
name|height
expr_stmt|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_function
DECL|function|pauseApp
name|void
name|QAndroidPlatformIntegration
operator|::
name|pauseApp
parameter_list|()
block|{
if|if
condition|(
name|QAbstractEventDispatcher
operator|::
name|instance
argument_list|(
name|m_mainThread
argument_list|)
condition|)
name|QAbstractEventDispatcher
operator|::
name|instance
argument_list|(
name|m_mainThread
argument_list|)
operator|->
name|interrupt
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|resumeApp
name|void
name|QAndroidPlatformIntegration
operator|::
name|resumeApp
parameter_list|()
block|{
if|if
condition|(
name|QAbstractEventDispatcher
operator|::
name|instance
argument_list|(
name|m_mainThread
argument_list|)
condition|)
name|QAbstractEventDispatcher
operator|::
name|instance
argument_list|(
name|m_mainThread
argument_list|)
operator|->
name|wakeUp
argument_list|()
expr_stmt|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
