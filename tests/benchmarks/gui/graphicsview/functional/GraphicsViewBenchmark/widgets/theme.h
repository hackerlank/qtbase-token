begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|THEME_H
end_ifndef
begin_define
DECL|macro|THEME_H
define|#
directive|define
name|THEME_H
end_define
begin_include
include|#
directive|include
file|<QPen>
end_include
begin_include
include|#
directive|include
file|<QPainter>
end_include
begin_include
include|#
directive|include
file|"gvbwidget.h"
end_include
begin_include
include|#
directive|include
file|"listitem.h"
end_include
begin_decl_stmt
name|class
name|Theme
range|:
name|public
name|QObject
block|{
name|Q_OBJECT
name|public
operator|:
expr|enum
name|Themes
block|{
name|Blue
operator|=
literal|0
block|,
name|Lime
operator|=
literal|1
block|,     }
block|;      enum
name|Fonts
block|{
name|ContactName
block|,
name|ContactNumber
block|,
name|ContactEmail
block|,
name|TitleBar
block|,
name|StatusBar
block|,
name|MenuItem
block|,     }
block|;
name|virtual
operator|~
name|Theme
argument_list|()
block|;
specifier|static
name|Theme
operator|*
name|p
argument_list|()
block|;
name|void
name|setTheme
argument_list|(
argument|const QString theme
argument_list|)
block|;
name|void
name|setTheme
argument_list|(
argument|const Themes theme
argument_list|)
block|;
name|Themes
name|theme
argument_list|()
specifier|const
block|{
return|return
name|m_currentTheme
return|;
block|}
name|QString
name|currentThemeName
argument_list|()
block|{
return|return
name|m_availableThemes
operator|.
name|at
argument_list|(
name|m_currentTheme
argument_list|)
return|;
block|}
name|QStringList
name|themes
argument_list|()
specifier|const
block|{
return|return
name|m_availableThemes
return|;
block|}
name|int
name|themesCount
argument_list|()
specifier|const
block|{
return|return
name|m_availableThemes
operator|.
name|count
argument_list|()
return|;
block|}
name|QPixmap
name|pixmap
argument_list|(
argument|const QString filename =
literal|""
argument_list|,
argument|QSize size = QSize(
literal|0
argument|,
literal|0
argument|)
argument_list|)
block|;
name|QFont
name|font
argument_list|(
argument|Fonts type
argument_list|)
specifier|const
block|{
return|return
name|m_fonts
index|[
name|type
index|]
return|;
block|}
name|QString
name|pixmapPath
argument_list|()
specifier|const
block|{
return|return
name|m_pixmapPath
return|;
block|}
name|QBrush
name|listItemBackgroundBrushEven
argument_list|()
specifier|const
block|{
return|return
name|m_listItemBackgroundBrushEven
return|;
block|}
name|QBrush
name|listItemBackgroundBrushOdd
argument_list|()
specifier|const
block|{
return|return
name|m_listItemBackgroundBrushOdd
return|;
block|}
name|qreal
name|listItemBackgroundOpacityEven
argument_list|()
specifier|const
block|{
return|return
name|m_listItemBackgroundOpacityEven
return|;
block|}
name|qreal
name|listItemBackgroundOpacityOdd
argument_list|()
specifier|const
block|{
return|return
name|m_listItemBackgroundOpacityOdd
return|;
block|}
name|QPen
name|listItemBorderPen
argument_list|()
specifier|const
block|{
return|return
name|m_listItemBorderPen
return|;
block|}
name|QSize
name|listItemRounding
argument_list|()
specifier|const
block|{
return|return
name|m_listItemRounding
return|;
block|}
name|bool
name|isIconOpacityEffectEnabled
argument_list|(
argument|const ListItem::IconItemPos iconPos
argument_list|)
specifier|const
block|{
return|return
name|m_iconOpacityEffectEnabled
index|[
name|iconPos
index|]
return|;
block|}
name|qreal
name|iconRotation
argument_list|(
argument|const ListItem::IconItemPos iconPos
argument_list|)
specifier|const
block|{
return|return
name|m_iconRotation
index|[
name|iconPos
index|]
return|;
block|}
name|bool
name|isIconSmoothTransformationEnabled
argument_list|(
argument|const ListItem::IconItemPos iconPos
argument_list|)
specifier|const
block|{
return|return
name|m_iconSmoothTransformation
index|[
name|iconPos
index|]
return|;
block|}
name|signals
operator|:
name|void
name|themeChanged
argument_list|()
block|;
name|private
operator|:
name|Theme
argument_list|(
name|QObject
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
name|void
name|setBlueTheme
argument_list|()
block|;
name|void
name|setLimeTheme
argument_list|()
block|;
name|private
operator|:
name|Q_DISABLE_COPY
argument_list|(
argument|Theme
argument_list|)
name|Themes
name|m_currentTheme
block|;
name|QStringList
name|m_availableThemes
block|;
name|QHash
operator|<
name|Fonts
block|,
name|QFont
operator|>
name|m_fonts
block|;
name|QString
name|m_pixmapPath
block|;
name|QBrush
name|m_listItemBackgroundBrushEven
block|;
name|qreal
name|m_listItemBackgroundOpacityEven
block|;
name|QBrush
name|m_listItemBackgroundBrushOdd
block|;
name|qreal
name|m_listItemBackgroundOpacityOdd
block|;
name|QPen
name|m_listItemBorderPen
block|;
name|QSize
name|m_listItemRounding
block|;
name|QHash
operator|<
name|ListItem
operator|::
name|IconItemPos
block|,
name|bool
operator|>
name|m_iconOpacityEffectEnabled
block|;
name|QHash
operator|<
name|ListItem
operator|::
name|IconItemPos
block|,
name|qreal
operator|>
name|m_iconRotation
block|;
name|QHash
operator|<
name|ListItem
operator|::
name|IconItemPos
block|,
name|bool
operator|>
name|m_iconSmoothTransformation
block|; }
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// THEME_H
end_comment
end_unit
