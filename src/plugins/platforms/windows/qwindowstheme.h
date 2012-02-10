begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QWINDOWSTHEME_H
end_ifndef
begin_define
DECL|macro|QWINDOWSTHEME_H
define|#
directive|define
name|QWINDOWSTHEME_H
end_define
begin_include
include|#
directive|include
file|<QtGui/QPlatformTheme>
end_include
begin_include
include|#
directive|include
file|<QtGui/QColor>
end_include
begin_include
include|#
directive|include
file|"qtwindows_additional.h"
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QWindow
name|class
name|QWindow
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QWindowsTheme
range|:
name|public
name|QPlatformTheme
block|{
name|public
operator|:
name|QWindowsTheme
argument_list|()
block|;
operator|~
name|QWindowsTheme
argument_list|()
block|;
specifier|static
name|QWindowsTheme
operator|*
name|instance
argument_list|()
block|;
name|virtual
name|bool
name|usePlatformNativeDialog
argument_list|(
argument|DialogType type
argument_list|)
specifier|const
block|;
name|virtual
name|QPlatformDialogHelper
operator|*
name|createPlatformDialogHelper
argument_list|(
argument|DialogType type
argument_list|)
specifier|const
block|;
name|virtual
name|QVariant
name|themeHint
argument_list|(
argument|ThemeHint
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
name|m_palettes
index|[
name|type
index|]
return|;
block|}
name|void
name|windowsThemeChanged
argument_list|(
name|QWindow
operator|*
name|window
argument_list|)
block|;
name|private
operator|:
name|void
name|refresh
argument_list|()
block|;
name|void
name|clearPalettes
argument_list|()
block|;
name|QPalette
operator|*
name|m_palettes
index|[
name|NPalettes
index|]
block|; }
decl_stmt|;
end_decl_stmt
begin_function
DECL|function|qColorToCOLORREF
specifier|static
specifier|inline
name|COLORREF
name|qColorToCOLORREF
parameter_list|(
specifier|const
name|QColor
modifier|&
name|color
parameter_list|)
block|{
return|return
name|RGB
argument_list|(
name|color
operator|.
name|red
argument_list|()
argument_list|,
name|color
operator|.
name|green
argument_list|()
argument_list|,
name|color
operator|.
name|blue
argument_list|()
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|COLORREFToQColor
specifier|static
specifier|inline
name|QColor
name|COLORREFToQColor
parameter_list|(
name|COLORREF
name|cr
parameter_list|)
block|{
return|return
name|QColor
argument_list|(
name|GetRValue
argument_list|(
name|cr
argument_list|)
argument_list|,
name|GetGValue
argument_list|(
name|cr
argument_list|)
argument_list|,
name|GetBValue
argument_list|(
name|cr
argument_list|)
argument_list|)
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QWINDOWSTHEME_H
end_comment
end_unit
