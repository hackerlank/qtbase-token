begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QWINDOWSINTEGRATION_H
end_ifndef
begin_define
DECL|macro|QWINDOWSINTEGRATION_H
define|#
directive|define
name|QWINDOWSINTEGRATION_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qconfig.h>
end_include
begin_include
include|#
directive|include
file|<qpa/qplatformintegration.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/QScopedPointer>
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_struct_decl
struct_decl|struct
name|QWindowsIntegrationPrivate
struct_decl|;
end_struct_decl
begin_decl_stmt
name|class
name|QWindowsIntegration
range|:
name|public
name|QPlatformIntegration
block|{
name|public
operator|:
expr|enum
name|Options
block|{
comment|// Options to be passed on command line.
name|FontDatabaseFreeType
operator|=
literal|0x1
block|,
name|FontDatabaseNative
operator|=
literal|0x2
block|,
name|DisableArb
operator|=
literal|0x4
block|,
name|NoNativeDialogs
operator|=
literal|0x8
block|,
name|XpNativeDialogs
operator|=
literal|0x10
block|}
block|;
name|explicit
name|QWindowsIntegration
argument_list|(
specifier|const
name|QStringList
operator|&
name|paramList
argument_list|)
block|;
name|virtual
operator|~
name|QWindowsIntegration
argument_list|()
block|;
name|bool
name|hasCapability
argument_list|(
argument|QPlatformIntegration::Capability cap
argument_list|)
specifier|const
block|;
name|virtual
name|QPlatformPixmap
operator|*
name|createPlatformPixmap
argument_list|(
argument|QPlatformPixmap::PixelType type
argument_list|)
specifier|const
block|;
name|QPlatformWindow
operator|*
name|createPlatformWindow
argument_list|(
argument|QWindow *window
argument_list|)
specifier|const
block|;
name|QPlatformBackingStore
operator|*
name|createPlatformBackingStore
argument_list|(
argument|QWindow *window
argument_list|)
specifier|const
block|;
ifndef|#
directive|ifndef
name|QT_NO_OPENGL
name|virtual
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
name|virtual
name|QAbstractEventDispatcher
operator|*
name|guiThreadEventDispatcher
argument_list|()
specifier|const
block|;
ifndef|#
directive|ifndef
name|QT_NO_CLIPBOARD
name|virtual
name|QPlatformClipboard
operator|*
name|clipboard
argument_list|()
specifier|const
block|;
ifndef|#
directive|ifndef
name|QT_NO_DRAGANDDROP
name|virtual
name|QPlatformDrag
operator|*
name|drag
argument_list|()
specifier|const
block|;
endif|#
directive|endif
endif|#
directive|endif
endif|!QT_NO_CLIPBOARD
name|virtual
name|QPlatformInputContext
operator|*
name|inputContext
argument_list|()
specifier|const
block|;
ifndef|#
directive|ifndef
name|QT_NO_ACCESSIBILITY
name|virtual
name|QPlatformAccessibility
operator|*
name|accessibility
argument_list|()
specifier|const
block|;
endif|#
directive|endif
name|virtual
name|QPlatformNativeInterface
operator|*
name|nativeInterface
argument_list|()
specifier|const
block|;
name|virtual
name|QPlatformFontDatabase
operator|*
name|fontDatabase
argument_list|()
specifier|const
block|;
name|virtual
name|QStringList
name|themeNames
argument_list|()
specifier|const
block|;
name|virtual
name|QPlatformTheme
operator|*
name|createPlatformTheme
argument_list|(
argument|const QString&name
argument_list|)
specifier|const
block|;
name|QPlatformServices
operator|*
name|services
argument_list|()
specifier|const
block|;
name|virtual
name|QVariant
name|styleHint
argument_list|(
argument|StyleHint hint
argument_list|)
specifier|const
block|;
name|virtual
name|Qt
operator|::
name|KeyboardModifiers
name|queryKeyboardModifiers
argument_list|()
specifier|const
block|;
name|virtual
name|QList
operator|<
name|int
operator|>
name|possibleKeys
argument_list|(
argument|const QKeyEvent *e
argument_list|)
specifier|const
block|;
specifier|static
name|QWindowsIntegration
operator|*
name|instance
argument_list|()
block|;
specifier|inline
name|void
name|emitScreenAdded
argument_list|(
argument|QPlatformScreen *s
argument_list|)
block|{
name|screenAdded
argument_list|(
name|s
argument_list|)
block|; }
name|unsigned
name|options
argument_list|()
specifier|const
block|;
name|private
operator|:
name|QScopedPointer
operator|<
name|QWindowsIntegrationPrivate
operator|>
name|d
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
end_unit
