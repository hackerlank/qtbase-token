begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QGENERICUNIXTHEMES_H
end_ifndef
begin_define
DECL|macro|QGENERICUNIXTHEMES_H
define|#
directive|define
name|QGENERICUNIXTHEMES_H
end_define
begin_include
include|#
directive|include
file|<qpa/qplatformtheme.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/QString>
end_include
begin_include
include|#
directive|include
file|<QtCore/QStringList>
end_include
begin_include
include|#
directive|include
file|<QtGui/QFont>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
name|class
name|ResourceHelper
block|{
name|public
label|:
name|ResourceHelper
argument_list|()
expr_stmt|;
operator|~
name|ResourceHelper
argument_list|()
block|{
name|clear
argument_list|()
block|; }
name|void
name|clear
argument_list|()
expr_stmt|;
name|QPalette
modifier|*
name|palettes
index|[
name|QPlatformTheme
operator|::
name|NPalettes
index|]
decl_stmt|;
name|QFont
modifier|*
name|fonts
index|[
name|QPlatformTheme
operator|::
name|NFonts
index|]
decl_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_decl_stmt
name|class
name|QGenericUnixTheme
range|:
name|public
name|QPlatformTheme
block|{
name|public
operator|:
name|QGenericUnixTheme
argument_list|()
block|;
specifier|static
name|QPlatformTheme
operator|*
name|createUnixTheme
argument_list|(
specifier|const
name|QString
operator|&
name|name
argument_list|)
block|;
specifier|static
name|QStringList
name|themeNames
argument_list|()
block|;
name|virtual
specifier|const
name|QFont
operator|*
name|font
argument_list|(
argument|Font type
argument_list|)
specifier|const
block|;
name|virtual
name|QVariant
name|themeHint
argument_list|(
argument|ThemeHint hint
argument_list|)
specifier|const
block|;
specifier|static
name|QStringList
name|xdgIconThemePaths
argument_list|()
block|;
specifier|static
specifier|const
name|char
operator|*
name|name
block|;
name|private
operator|:
specifier|const
name|QFont
name|m_systemFont
block|; }
decl_stmt|;
end_decl_stmt
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_SETTINGS
end_ifndef
begin_decl_stmt
name|class
name|QKdeTheme
range|:
name|public
name|QPlatformTheme
block|{
name|QKdeTheme
argument_list|(
argument|const QString&kdeHome
argument_list|,
argument|int kdeVersion
argument_list|)
block|;
name|public
operator|:
specifier|static
name|QPlatformTheme
operator|*
name|createKdeTheme
argument_list|()
block|;
name|virtual
name|QVariant
name|themeHint
argument_list|(
argument|ThemeHint hint
argument_list|)
specifier|const
block|;
name|virtual
specifier|const
name|QPalette
operator|*
name|palette
argument_list|(
argument|Palette type = SystemPalette
argument_list|)
specifier|const
block|{
return|return
name|m_resources
operator|.
name|palettes
index|[
name|type
index|]
return|;
block|}
name|virtual
specifier|const
name|QFont
operator|*
name|font
argument_list|(
argument|Font type
argument_list|)
specifier|const
block|{
return|return
name|m_resources
operator|.
name|fonts
index|[
name|type
index|]
return|;
block|}
specifier|static
specifier|const
name|char
operator|*
name|name
block|;
name|private
operator|:
name|QString
name|globalSettingsFile
argument_list|()
specifier|const
block|;
name|void
name|refresh
argument_list|()
block|;
specifier|const
name|QString
name|m_kdeHome
block|;
specifier|const
name|int
name|m_kdeVersion
block|;
name|ResourceHelper
name|m_resources
block|;
name|QString
name|m_iconThemeName
block|;
name|QString
name|m_iconFallbackThemeName
block|;
name|QStringList
name|m_styleNames
block|;
name|int
name|m_toolButtonStyle
block|;
name|int
name|m_toolBarIconSize
block|; }
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_SETTINGS
end_comment
begin_decl_stmt
name|class
name|QGnomeTheme
range|:
name|public
name|QPlatformTheme
block|{
name|public
operator|:
name|QGnomeTheme
argument_list|()
block|;
name|virtual
name|QVariant
name|themeHint
argument_list|(
argument|ThemeHint hint
argument_list|)
specifier|const
block|;
name|virtual
specifier|const
name|QFont
operator|*
name|font
argument_list|(
argument|Font type
argument_list|)
specifier|const
block|;
specifier|static
specifier|const
name|char
operator|*
name|name
block|;
name|private
operator|:
specifier|const
name|QFont
name|m_systemFont
block|; }
decl_stmt|;
end_decl_stmt
begin_function_decl
name|QPlatformTheme
modifier|*
name|qt_createUnixTheme
parameter_list|()
function_decl|;
end_function_decl
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QGENERICUNIXTHEMES_H
end_comment
end_unit
