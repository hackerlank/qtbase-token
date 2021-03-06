begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QPLATFORMINTEGRATION_UIKIT_H
end_ifndef
begin_define
DECL|macro|QPLATFORMINTEGRATION_UIKIT_H
define|#
directive|define
name|QPLATFORMINTEGRATION_UIKIT_H
end_define
begin_include
include|#
directive|include
file|<qpa/qplatformintegration.h>
end_include
begin_include
include|#
directive|include
file|<qpa/qplatformnativeinterface.h>
end_include
begin_include
include|#
directive|include
file|<qpa/qwindowsysteminterface.h>
end_include
begin_include
include|#
directive|include
file|"qiosapplicationstate.h"
end_include
begin_include
include|#
directive|include
file|"qiosfileenginefactory.h"
end_include
begin_include
include|#
directive|include
file|"qiostextinputoverlay.h"
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QIOSServices
name|class
name|QIOSServices
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QPlatformNativeInterface
name|class
name|QIOSIntegration
range|:
name|public
name|QPlatformNativeInterface
decl_stmt|,
name|public
name|QPlatformIntegration
block|{
name|Q_OBJECT
name|Q_PROPERTY
parameter_list|(
name|bool
name|debugWindowManagement
name|READ
name|debugWindowManagement
name|WRITE
name|setDebugWindowManagement
parameter_list|)
function_decl|;
name|public
label|:
name|QIOSIntegration
argument_list|()
expr_stmt|;
operator|~
name|QIOSIntegration
argument_list|()
expr_stmt|;
name|bool
name|hasCapability
argument_list|(
name|Capability
name|cap
argument_list|)
decl|const
name|Q_DECL_OVERRIDE
decl_stmt|;
name|QPlatformWindow
modifier|*
name|createPlatformWindow
argument_list|(
name|QWindow
operator|*
name|window
argument_list|)
decl|const
name|Q_DECL_OVERRIDE
decl_stmt|;
name|QPlatformBackingStore
modifier|*
name|createPlatformBackingStore
argument_list|(
name|QWindow
operator|*
name|window
argument_list|)
decl|const
name|Q_DECL_OVERRIDE
decl_stmt|;
name|QPlatformOpenGLContext
modifier|*
name|createPlatformOpenGLContext
argument_list|(
name|QOpenGLContext
operator|*
name|context
argument_list|)
decl|const
name|Q_DECL_OVERRIDE
decl_stmt|;
name|QPlatformOffscreenSurface
modifier|*
name|createPlatformOffscreenSurface
argument_list|(
name|QOffscreenSurface
operator|*
name|surface
argument_list|)
decl|const
name|Q_DECL_OVERRIDE
decl_stmt|;
name|QPlatformFontDatabase
operator|*
name|fontDatabase
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
expr_stmt|;
name|QPlatformClipboard
operator|*
name|clipboard
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
expr_stmt|;
name|QPlatformInputContext
operator|*
name|inputContext
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
expr_stmt|;
name|QPlatformServices
operator|*
name|services
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
expr_stmt|;
name|QVariant
name|styleHint
argument_list|(
name|StyleHint
name|hint
argument_list|)
decl|const
name|Q_DECL_OVERRIDE
decl_stmt|;
name|QStringList
name|themeNames
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
expr_stmt|;
name|QPlatformTheme
modifier|*
name|createPlatformTheme
argument_list|(
specifier|const
name|QString
operator|&
name|name
argument_list|)
decl|const
name|Q_DECL_OVERRIDE
decl_stmt|;
name|QAbstractEventDispatcher
operator|*
name|createEventDispatcher
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
expr_stmt|;
name|QPlatformNativeInterface
operator|*
name|nativeInterface
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
expr_stmt|;
name|QTouchDevice
modifier|*
name|touchDevice
parameter_list|()
function_decl|;
name|QPlatformAccessibility
operator|*
name|accessibility
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
expr_stmt|;
comment|// Called from Objective-C class QIOSScreenTracker, which can't be friended
name|void
name|addScreen
parameter_list|(
name|QPlatformScreen
modifier|*
name|screen
parameter_list|)
block|{
name|screenAdded
argument_list|(
name|screen
argument_list|)
expr_stmt|;
block|}
name|void
name|destroyScreen
parameter_list|(
name|QPlatformScreen
modifier|*
name|screen
parameter_list|)
block|{
name|QPlatformIntegration
operator|::
name|destroyScreen
argument_list|(
name|screen
argument_list|)
expr_stmt|;
block|}
name|void
name|beep
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
expr_stmt|;
specifier|static
name|QIOSIntegration
modifier|*
name|instance
parameter_list|()
function_decl|;
comment|// -- QPlatformNativeInterface --
name|void
modifier|*
name|nativeResourceForWindow
argument_list|(
specifier|const
name|QByteArray
operator|&
name|resource
argument_list|,
name|QWindow
operator|*
name|window
argument_list|)
name|Q_DECL_OVERRIDE
decl_stmt|;
name|void
name|setDebugWindowManagement
parameter_list|(
name|bool
parameter_list|)
function_decl|;
name|bool
name|debugWindowManagement
argument_list|()
specifier|const
expr_stmt|;
name|private
label|:
name|QPlatformFontDatabase
modifier|*
name|m_fontDatabase
decl_stmt|;
name|QPlatformClipboard
modifier|*
name|m_clipboard
decl_stmt|;
name|QPlatformInputContext
modifier|*
name|m_inputContext
decl_stmt|;
name|QTouchDevice
modifier|*
name|m_touchDevice
decl_stmt|;
name|QIOSApplicationState
name|m_applicationState
decl_stmt|;
name|QIOSServices
modifier|*
name|m_platformServices
decl_stmt|;
name|mutable
name|QPlatformAccessibility
modifier|*
name|m_accessibility
decl_stmt|;
name|QIOSFileEngineFactory
name|m_fileEngineFactory
decl_stmt|;
name|QIOSTextInputOverlay
name|m_textInputOverlay
decl_stmt|;
name|bool
name|m_debugWindowManagement
decl_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
end_unit
