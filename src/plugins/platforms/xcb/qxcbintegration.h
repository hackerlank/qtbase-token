begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QXCBINTEGRATION_H
end_ifndef
begin_define
DECL|macro|QXCBINTEGRATION_H
define|#
directive|define
name|QXCBINTEGRATION_H
end_define
begin_include
include|#
directive|include
file|<qpa/qplatformintegration.h>
end_include
begin_include
include|#
directive|include
file|<qpa/qplatformscreen.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QXcbConnection
name|class
name|QXcbConnection
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QAbstractEventDispatcher
name|class
name|QAbstractEventDispatcher
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QXcbNativeInterface
name|class
name|QXcbNativeInterface
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QXcbScreen
name|class
name|QXcbScreen
decl_stmt|;
end_decl_stmt
begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|QT_NO_OPENGL
argument_list|)
operator|&&
name|defined
argument_list|(
name|XCB_USE_GLX
argument_list|)
end_if
begin_decl_stmt
DECL|variable|QOpenGLDefaultContextInfo
name|class
name|QOpenGLDefaultContextInfo
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_decl_stmt
name|class
name|QXcbIntegration
range|:
name|public
name|QPlatformIntegration
block|{
name|public
operator|:
name|QXcbIntegration
argument_list|(
specifier|const
name|QStringList
operator|&
name|parameters
argument_list|)
block|;
operator|~
name|QXcbIntegration
argument_list|()
block|;
name|QPlatformWindow
operator|*
name|createPlatformWindow
argument_list|(
argument|QWindow *window
argument_list|)
specifier|const
block|;
ifndef|#
directive|ifndef
name|QT_NO_OPENGL
name|QPlatformOpenGLContext
operator|*
name|createPlatformOpenGLContext
argument_list|(
argument|QOpenGLContext *context
argument_list|)
specifier|const
block|;
endif|#
directive|endif
name|QPlatformBackingStore
operator|*
name|createPlatformBackingStore
argument_list|(
argument|QWindow *window
argument_list|)
specifier|const
block|;
name|bool
name|hasCapability
argument_list|(
argument|Capability cap
argument_list|)
specifier|const
block|;
name|QAbstractEventDispatcher
operator|*
name|guiThreadEventDispatcher
argument_list|()
specifier|const
block|;
name|void
name|moveToScreen
argument_list|(
argument|QWindow *window
argument_list|,
argument|int screen
argument_list|)
block|;
name|QPlatformFontDatabase
operator|*
name|fontDatabase
argument_list|()
specifier|const
block|;
name|QPlatformNativeInterface
operator|*
name|nativeInterface
argument_list|()
specifier|const
block|;
ifndef|#
directive|ifndef
name|QT_NO_CLIPBOARD
name|QPlatformClipboard
operator|*
name|clipboard
argument_list|()
specifier|const
block|;
endif|#
directive|endif
ifndef|#
directive|ifndef
name|QT_NO_DRAGANDDROP
name|QPlatformDrag
operator|*
name|drag
argument_list|()
specifier|const
block|;
endif|#
directive|endif
name|QPlatformInputContext
operator|*
name|inputContext
argument_list|()
specifier|const
block|;
ifndef|#
directive|ifndef
name|QT_NO_ACCESSIBILITY
name|QPlatformAccessibility
operator|*
name|accessibility
argument_list|()
specifier|const
block|;
endif|#
directive|endif
name|QPlatformServices
operator|*
name|services
argument_list|()
specifier|const
block|;
name|Qt
operator|::
name|KeyboardModifiers
name|queryKeyboardModifiers
argument_list|()
specifier|const
block|;
name|QStringList
name|themeNames
argument_list|()
specifier|const
block|;
name|QPlatformTheme
operator|*
name|createPlatformTheme
argument_list|(
argument|const QString&name
argument_list|)
specifier|const
block|;
name|void
name|removeDefaultOpenGLContextInfo
argument_list|(
name|QXcbScreen
operator|*
name|screen
argument_list|)
block|;
name|private
operator|:
name|QList
operator|<
name|QXcbConnection
operator|*
operator|>
name|m_connections
block|;
name|QScopedPointer
operator|<
name|QPlatformFontDatabase
operator|>
name|m_fontDatabase
block|;
name|QScopedPointer
operator|<
name|QXcbNativeInterface
operator|>
name|m_nativeInterface
block|;
name|QScopedPointer
operator|<
name|QPlatformInputContext
operator|>
name|m_inputContext
block|;
name|QAbstractEventDispatcher
operator|*
name|m_eventDispatcher
block|;
if|#
directive|if
operator|!
name|defined
argument_list|(
name|QT_NO_OPENGL
argument_list|)
operator|&&
name|defined
argument_list|(
name|XCB_USE_GLX
argument_list|)
name|mutable
name|QHash
operator|<
name|QXcbScreen
operator|*
block|,
name|QOpenGLDefaultContextInfo
operator|*
operator|>
name|m_defaultContextInfos
block|;
endif|#
directive|endif
ifndef|#
directive|ifndef
name|QT_NO_ACCESSIBILITY
name|QScopedPointer
operator|<
name|QPlatformAccessibility
operator|>
name|m_accessibility
block|;
endif|#
directive|endif
name|QScopedPointer
operator|<
name|QPlatformServices
operator|>
name|m_services
block|;
name|friend
name|class
name|QXcbConnection
block|;
comment|// access QPlatformIntegration::screenAdded()
block|}
decl_stmt|;
end_decl_stmt
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
end_unit
