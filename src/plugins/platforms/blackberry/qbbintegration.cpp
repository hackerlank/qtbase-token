begin_unit
begin_comment
comment|/*************************************************************************** ** ** Copyright (C) 2011 - 2012 Research In Motion ** Contact: http://www.qt-project.org/ ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qbbintegration.h"
end_include
begin_include
include|#
directive|include
file|"qbbeventthread.h"
end_include
begin_include
include|#
directive|include
file|"qbbglbackingstore.h"
end_include
begin_include
include|#
directive|include
file|"qbbglcontext.h"
end_include
begin_include
include|#
directive|include
file|"qbbnavigatorthread.h"
end_include
begin_include
include|#
directive|include
file|"qbbrasterbackingstore.h"
end_include
begin_include
include|#
directive|include
file|"qbbscreen.h"
end_include
begin_include
include|#
directive|include
file|"qbbwindow.h"
end_include
begin_include
include|#
directive|include
file|"qbbvirtualkeyboard.h"
end_include
begin_include
include|#
directive|include
file|"qbbclipboard.h"
end_include
begin_include
include|#
directive|include
file|"qbbglcontext.h"
end_include
begin_if
if|#
directive|if
name|defined
argument_list|(
name|QBB_IMF
argument_list|)
end_if
begin_include
include|#
directive|include
file|"qbbinputcontext_imf.h"
end_include
begin_else
else|#
directive|else
end_else
begin_include
include|#
directive|include
file|"qbbinputcontext_noimf.h"
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_include
include|#
directive|include
file|"private/qgenericunixfontdatabase_p.h"
end_include
begin_include
include|#
directive|include
file|"private/qgenericunixeventdispatcher_p.h"
end_include
begin_include
include|#
directive|include
file|<QtGui/QPlatformWindow>
end_include
begin_include
include|#
directive|include
file|<QtGui/QWindowSystemInterface>
end_include
begin_include
include|#
directive|include
file|<QtGui/QOpenGLContext>
end_include
begin_include
include|#
directive|include
file|<QtCore/QDebug>
end_include
begin_include
include|#
directive|include
file|<QtCore/QHash>
end_include
begin_include
include|#
directive|include
file|<errno.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|member|ms_windowMapper
name|QBBWindowMapper
name|QBBIntegration
operator|::
name|ms_windowMapper
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|member|ms_windowMapperMutex
name|QMutex
name|QBBIntegration
operator|::
name|ms_windowMapperMutex
decl_stmt|;
end_decl_stmt
begin_constructor
DECL|function|QBBIntegration
name|QBBIntegration
operator|::
name|QBBIntegration
parameter_list|()
member_init_list|:
name|QPlatformIntegration
argument_list|()
member_init_list|,
name|m_eventThread
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|m_navigatorThread
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|m_inputContext
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|m_fontDatabase
argument_list|(
operator|new
name|QGenericUnixFontDatabase
argument_list|()
argument_list|)
member_init_list|,
name|m_paintUsingOpenGL
argument_list|(
literal|false
argument_list|)
member_init_list|,
name|m_eventDispatcher
argument_list|(
name|createUnixEventDispatcher
argument_list|()
argument_list|)
ifndef|#
directive|ifndef
name|QT_NO_CLIPBOARD
member_init_list|,
name|m_clipboard
argument_list|(
literal|0
argument_list|)
endif|#
directive|endif
block|{
if|#
directive|if
name|defined
argument_list|(
name|QBBINTEGRATION_DEBUG
argument_list|)
name|qDebug
argument_list|()
operator|<<
name|Q_FUNC_INFO
expr_stmt|;
endif|#
directive|endif
comment|// Open connection to QNX composition manager
name|errno
operator|=
literal|0
expr_stmt|;
name|int
name|result
init|=
name|screen_create_context
argument_list|(
operator|&
name|m_screenContext
argument_list|,
name|SCREEN_APPLICATION_CONTEXT
argument_list|)
decl_stmt|;
if|if
condition|(
name|result
operator|!=
literal|0
condition|)
block|{
name|qFatal
argument_list|(
literal|"QBB: failed to connect to composition manager, errno=%d"
argument_list|,
name|errno
argument_list|)
expr_stmt|;
block|}
comment|// Create displays for all possible screens (which may not be attached)
name|QBBScreen
operator|::
name|createDisplays
argument_list|(
name|m_screenContext
argument_list|)
expr_stmt|;
name|Q_FOREACH
argument_list|(
argument|QPlatformScreen *screen
argument_list|,
argument|QBBScreen::screens()
argument_list|)
block|{
name|screenAdded
argument_list|(
name|screen
argument_list|)
expr_stmt|;
block|}
comment|// Initialize global OpenGL resources
name|QBBGLContext
operator|::
name|initialize
argument_list|()
expr_stmt|;
comment|// Create/start event thread
name|m_eventThread
operator|=
operator|new
name|QBBEventThread
argument_list|(
name|m_screenContext
argument_list|,
operator|*
name|QBBScreen
operator|::
name|primaryDisplay
argument_list|()
argument_list|)
expr_stmt|;
name|m_eventThread
operator|->
name|start
argument_list|()
expr_stmt|;
comment|// Create/start navigator thread
name|m_navigatorThread
operator|=
operator|new
name|QBBNavigatorThread
argument_list|(
operator|*
name|QBBScreen
operator|::
name|primaryDisplay
argument_list|()
argument_list|)
expr_stmt|;
name|m_navigatorThread
operator|->
name|start
argument_list|()
expr_stmt|;
comment|// Create/start the keyboard class.
name|QBBVirtualKeyboard
operator|::
name|instance
argument_list|()
expr_stmt|;
comment|// Set up the input context
name|m_inputContext
operator|=
operator|new
name|QBBInputContext
expr_stmt|;
block|}
end_constructor
begin_destructor
DECL|function|~QBBIntegration
name|QBBIntegration
operator|::
name|~
name|QBBIntegration
parameter_list|()
block|{
if|#
directive|if
name|defined
argument_list|(
name|QBBINTEGRATION_DEBUG
argument_list|)
name|qDebug
argument_list|()
operator|<<
literal|"QBB: platform plugin shutdown begin"
expr_stmt|;
endif|#
directive|endif
comment|// Destroy the keyboard class.
name|QBBVirtualKeyboard
operator|::
name|destroy
argument_list|()
expr_stmt|;
ifndef|#
directive|ifndef
name|QT_NO_CLIPBOARD
comment|// Delete the clipboard
operator|delete
name|m_clipboard
expr_stmt|;
endif|#
directive|endif
comment|// Stop/destroy event thread
operator|delete
name|m_eventThread
expr_stmt|;
comment|// Stop/destroy navigator thread
operator|delete
name|m_navigatorThread
expr_stmt|;
comment|// Destroy all displays
name|QBBScreen
operator|::
name|destroyDisplays
argument_list|()
expr_stmt|;
comment|// Close connection to QNX composition manager
name|screen_destroy_context
argument_list|(
name|m_screenContext
argument_list|)
expr_stmt|;
comment|// Cleanup global OpenGL resources
name|QBBGLContext
operator|::
name|shutdown
argument_list|()
expr_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|QBBINTEGRATION_DEBUG
argument_list|)
name|qDebug
argument_list|()
operator|<<
literal|"QBB: platform plugin shutdown end"
expr_stmt|;
endif|#
directive|endif
block|}
end_destructor
begin_function
DECL|function|hasCapability
name|bool
name|QBBIntegration
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
if|#
directive|if
name|defined
argument_list|(
name|QBBINTEGRATION_DEBUG
argument_list|)
name|qDebug
argument_list|()
operator|<<
name|Q_FUNC_INFO
expr_stmt|;
endif|#
directive|endif
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
if|#
directive|if
name|defined
argument_list|(
name|QT_OPENGL_ES
argument_list|)
case|case
name|OpenGL
case|:
return|return
literal|true
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
DECL|function|createPlatformWindow
name|QPlatformWindow
modifier|*
name|QBBIntegration
operator|::
name|createPlatformWindow
parameter_list|(
name|QWindow
modifier|*
name|window
parameter_list|)
specifier|const
block|{
if|#
directive|if
name|defined
argument_list|(
name|QBBINTEGRATION_DEBUG
argument_list|)
name|qDebug
argument_list|()
operator|<<
name|Q_FUNC_INFO
expr_stmt|;
endif|#
directive|endif
comment|// New windows are created on the primary display.
return|return
operator|new
name|QBBWindow
argument_list|(
name|window
argument_list|,
name|m_screenContext
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|createPlatformBackingStore
name|QPlatformBackingStore
modifier|*
name|QBBIntegration
operator|::
name|createPlatformBackingStore
parameter_list|(
name|QWindow
modifier|*
name|window
parameter_list|)
specifier|const
block|{
if|#
directive|if
name|defined
argument_list|(
name|QBBINTEGRATION_DEBUG
argument_list|)
name|qDebug
argument_list|()
operator|<<
name|Q_FUNC_INFO
expr_stmt|;
endif|#
directive|endif
if|if
condition|(
name|paintUsingOpenGL
argument_list|()
condition|)
return|return
operator|new
name|QBBGLBackingStore
argument_list|(
name|window
argument_list|)
return|;
else|else
return|return
operator|new
name|QBBRasterBackingStore
argument_list|(
name|window
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|createPlatformOpenGLContext
name|QPlatformOpenGLContext
modifier|*
name|QBBIntegration
operator|::
name|createPlatformOpenGLContext
parameter_list|(
name|QOpenGLContext
modifier|*
name|context
parameter_list|)
specifier|const
block|{
if|#
directive|if
name|defined
argument_list|(
name|QBBINTEGRATION_DEBUG
argument_list|)
name|qDebug
argument_list|()
operator|<<
name|Q_FUNC_INFO
expr_stmt|;
endif|#
directive|endif
return|return
operator|new
name|QBBGLContext
argument_list|(
name|context
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|inputContext
name|QPlatformInputContext
modifier|*
name|QBBIntegration
operator|::
name|inputContext
parameter_list|()
specifier|const
block|{
if|#
directive|if
name|defined
argument_list|(
name|QBBINTEGRATION_DEBUG
argument_list|)
name|qDebug
argument_list|()
operator|<<
name|Q_FUNC_INFO
expr_stmt|;
endif|#
directive|endif
return|return
name|m_inputContext
return|;
block|}
end_function
begin_function
DECL|function|moveToScreen
name|void
name|QBBIntegration
operator|::
name|moveToScreen
parameter_list|(
name|QWindow
modifier|*
name|window
parameter_list|,
name|int
name|screen
parameter_list|)
block|{
if|#
directive|if
name|defined
argument_list|(
name|QBBINTEGRATION_DEBUG
argument_list|)
name|qDebug
argument_list|()
operator|<<
literal|"QBBIntegration::moveToScreen - w="
operator|<<
name|window
operator|<<
literal|", s="
operator|<<
name|screen
expr_stmt|;
endif|#
directive|endif
comment|// get platform window used by widget
name|QBBWindow
modifier|*
name|platformWindow
init|=
cast|static_cast
argument_list|<
name|QBBWindow
operator|*
argument_list|>
argument_list|(
name|window
operator|->
name|handle
argument_list|()
argument_list|)
decl_stmt|;
comment|// lookup platform screen by index
name|QBBScreen
modifier|*
name|platformScreen
init|=
cast|static_cast
argument_list|<
name|QBBScreen
operator|*
argument_list|>
argument_list|(
name|QBBScreen
operator|::
name|screens
argument_list|()
operator|.
name|at
argument_list|(
name|screen
argument_list|)
argument_list|)
decl_stmt|;
comment|// move the platform window to the platform screen
name|platformWindow
operator|->
name|setScreen
argument_list|(
name|platformScreen
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|screens
name|QList
argument_list|<
name|QPlatformScreen
modifier|*
argument_list|>
name|QBBIntegration
operator|::
name|screens
parameter_list|()
specifier|const
block|{
if|#
directive|if
name|defined
argument_list|(
name|QBBINTEGRATION_DEBUG
argument_list|)
name|qDebug
argument_list|()
operator|<<
name|Q_FUNC_INFO
expr_stmt|;
endif|#
directive|endif
return|return
name|QBBScreen
operator|::
name|screens
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|guiThreadEventDispatcher
name|QAbstractEventDispatcher
modifier|*
name|QBBIntegration
operator|::
name|guiThreadEventDispatcher
parameter_list|()
specifier|const
block|{
if|#
directive|if
name|defined
argument_list|(
name|QBBINTEGRATION_DEBUG
argument_list|)
name|qDebug
argument_list|()
operator|<<
name|Q_FUNC_INFO
expr_stmt|;
endif|#
directive|endif
return|return
name|m_eventDispatcher
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
name|QBBIntegration
operator|::
name|clipboard
parameter_list|()
specifier|const
block|{
if|#
directive|if
name|defined
argument_list|(
name|QBBINTEGRATION_DEBUG
argument_list|)
name|qDebug
argument_list|()
operator|<<
name|Q_FUNC_INFO
expr_stmt|;
endif|#
directive|endif
if|if
condition|(
operator|!
name|m_clipboard
condition|)
block|{
name|m_clipboard
operator|=
operator|new
name|QBBClipboard
expr_stmt|;
block|}
return|return
name|m_clipboard
return|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_function
DECL|function|styleHint
name|QVariant
name|QBBIntegration
operator|::
name|styleHint
parameter_list|(
name|QPlatformIntegration
operator|::
name|StyleHint
name|hint
parameter_list|)
specifier|const
block|{
if|#
directive|if
name|defined
argument_list|(
name|QBBINTEGRATION_DEBUG
argument_list|)
name|qDebug
argument_list|()
operator|<<
name|Q_FUNC_INFO
expr_stmt|;
endif|#
directive|endif
if|if
condition|(
name|hint
operator|==
name|ShowIsFullScreen
condition|)
return|return
literal|true
return|;
return|return
name|QPlatformIntegration
operator|::
name|styleHint
argument_list|(
name|hint
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|window
name|QWindow
modifier|*
name|QBBIntegration
operator|::
name|window
parameter_list|(
name|screen_window_t
name|qnxWindow
parameter_list|)
block|{
if|#
directive|if
name|defined
argument_list|(
name|QBBINTEGRATION_DEBUG
argument_list|)
name|qDebug
argument_list|()
operator|<<
name|Q_FUNC_INFO
expr_stmt|;
endif|#
directive|endif
name|QMutexLocker
name|locker
argument_list|(
operator|&
name|ms_windowMapperMutex
argument_list|)
decl_stmt|;
name|Q_UNUSED
argument_list|(
name|locker
argument_list|)
expr_stmt|;
return|return
name|ms_windowMapper
operator|.
name|value
argument_list|(
name|qnxWindow
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|addWindow
name|void
name|QBBIntegration
operator|::
name|addWindow
parameter_list|(
name|screen_window_t
name|qnxWindow
parameter_list|,
name|QWindow
modifier|*
name|window
parameter_list|)
block|{
if|#
directive|if
name|defined
argument_list|(
name|QBBINTEGRATION_DEBUG
argument_list|)
name|qDebug
argument_list|()
operator|<<
name|Q_FUNC_INFO
expr_stmt|;
endif|#
directive|endif
name|QMutexLocker
name|locker
argument_list|(
operator|&
name|ms_windowMapperMutex
argument_list|)
decl_stmt|;
name|Q_UNUSED
argument_list|(
name|locker
argument_list|)
expr_stmt|;
name|ms_windowMapper
operator|.
name|insert
argument_list|(
name|qnxWindow
argument_list|,
name|window
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|removeWindow
name|void
name|QBBIntegration
operator|::
name|removeWindow
parameter_list|(
name|screen_window_t
name|qnxWindow
parameter_list|)
block|{
if|#
directive|if
name|defined
argument_list|(
name|QBBINTEGRATION_DEBUG
argument_list|)
name|qDebug
argument_list|()
operator|<<
name|Q_FUNC_INFO
expr_stmt|;
endif|#
directive|endif
name|QMutexLocker
name|locker
argument_list|(
operator|&
name|ms_windowMapperMutex
argument_list|)
decl_stmt|;
name|Q_UNUSED
argument_list|(
name|locker
argument_list|)
expr_stmt|;
name|ms_windowMapper
operator|.
name|remove
argument_list|(
name|qnxWindow
argument_list|)
expr_stmt|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
