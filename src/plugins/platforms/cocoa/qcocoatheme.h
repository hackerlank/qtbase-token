begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2014 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia. For licensing terms and ** conditions see http://qt.digia.com/licensing. For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights. These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QPLATFORMTHEME_COCOA_H
end_ifndef
begin_define
DECL|macro|QPLATFORMTHEME_COCOA_H
define|#
directive|define
name|QPLATFORMTHEME_COCOA_H
end_define
begin_include
include|#
directive|include
file|<QtCore/QHash>
end_include
begin_include
include|#
directive|include
file|<qpa/qplatformtheme.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QPalette
name|class
name|QPalette
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QCocoaTheme
range|:
name|public
name|QPlatformTheme
block|{
name|public
operator|:
name|QCocoaTheme
argument_list|()
block|;
operator|~
name|QCocoaTheme
argument_list|()
block|;
name|virtual
name|QPlatformMenuItem
operator|*
name|createPlatformMenuItem
argument_list|()
specifier|const
block|;
name|virtual
name|QPlatformMenu
operator|*
name|createPlatformMenu
argument_list|()
specifier|const
block|;
name|virtual
name|QPlatformMenuBar
operator|*
name|createPlatformMenuBar
argument_list|()
specifier|const
block|;
ifndef|#
directive|ifndef
name|QT_NO_SYSTEMTRAYICON
name|QPlatformSystemTrayIcon
operator|*
name|createPlatformSystemTrayIcon
argument_list|()
specifier|const
block|;
endif|#
directive|endif
name|bool
name|usePlatformNativeDialog
argument_list|(
argument|DialogType dialogType
argument_list|)
specifier|const
block|;
name|QPlatformDialogHelper
operator|*
name|createPlatformDialogHelper
argument_list|(
argument|DialogType dialogType
argument_list|)
specifier|const
block|;
specifier|const
name|QPalette
operator|*
name|palette
argument_list|(
argument|Palette type = SystemPalette
argument_list|)
specifier|const
block|;
specifier|const
name|QFont
operator|*
name|font
argument_list|(
argument|Font type = SystemFont
argument_list|)
specifier|const
block|;
name|QPixmap
name|standardPixmap
argument_list|(
argument|StandardPixmap sp
argument_list|,
argument|const QSizeF&size
argument_list|)
specifier|const
block|;
name|QPixmap
name|fileIconPixmap
argument_list|(
argument|const QFileInfo&fileInfo
argument_list|,
argument|const QSizeF&size
argument_list|,
argument|QPlatformTheme::IconOptions options =
literal|0
argument_list|)
specifier|const
block|;
name|QVariant
name|themeHint
argument_list|(
argument|ThemeHint hint
argument_list|)
specifier|const
block|;
name|QString
name|standardButtonText
argument_list|(
argument|int button
argument_list|)
specifier|const
name|Q_DECL_OVERRIDE
block|;
specifier|static
specifier|const
name|char
operator|*
name|name
block|;
name|private
operator|:
name|mutable
name|QPalette
operator|*
name|m_systemPalette
block|;
name|mutable
name|QHash
operator|<
name|QPlatformTheme
operator|::
name|Palette
block|,
name|QPalette
operator|*
operator|>
name|m_palettes
block|;
name|mutable
name|QHash
operator|<
name|QPlatformTheme
operator|::
name|Font
block|,
name|QFont
operator|*
operator|>
name|m_fonts
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
