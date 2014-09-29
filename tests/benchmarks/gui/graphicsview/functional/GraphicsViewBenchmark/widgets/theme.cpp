begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2014 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia. For licensing terms and ** conditions see http://qt.digia.com/licensing. For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights. These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QDebug>
end_include
begin_include
include|#
directive|include
file|<QPainter>
end_include
begin_include
include|#
directive|include
file|<QPixmapCache>
end_include
begin_include
include|#
directive|include
file|<QSvgRenderer>
end_include
begin_include
include|#
directive|include
file|"theme.h"
end_include
begin_macro
name|Q_DECLARE_METATYPE
argument_list|(
argument|Theme::Themes*
argument_list|)
end_macro
begin_constructor
DECL|function|Theme
name|Theme
operator|::
name|Theme
parameter_list|(
name|QObject
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QObject
argument_list|(
name|parent
argument_list|)
member_init_list|,
name|m_currentTheme
argument_list|()
member_init_list|,
name|m_availableThemes
argument_list|()
member_init_list|,
name|m_fonts
argument_list|()
member_init_list|,
name|m_pixmapPath
argument_list|()
member_init_list|,
name|m_listItemBackgroundBrushEven
argument_list|()
member_init_list|,
name|m_listItemBackgroundOpacityEven
argument_list|()
member_init_list|,
name|m_listItemBackgroundBrushOdd
argument_list|()
member_init_list|,
name|m_listItemBackgroundOpacityOdd
argument_list|()
member_init_list|,
name|m_listItemBorderPen
argument_list|(
name|QPen
argument_list|()
argument_list|)
member_init_list|,
name|m_listItemRounding
argument_list|()
member_init_list|,
name|m_iconOpacityEffectEnabled
argument_list|()
member_init_list|,
name|m_iconRotation
argument_list|()
member_init_list|,
name|m_iconSmoothTransformation
argument_list|()
block|{
name|m_availableThemes
operator|<<
literal|"Blue"
operator|<<
literal|"Lime"
expr_stmt|;
comment|// Set blue theme as a default theme without emiting themeChanged() signal
name|setBlueTheme
argument_list|()
expr_stmt|;
block|}
end_constructor
begin_destructor
DECL|function|~Theme
name|Theme
operator|::
name|~
name|Theme
parameter_list|()
block|{ }
end_destructor
begin_function
DECL|function|p
name|Theme
modifier|*
name|Theme
operator|::
name|p
parameter_list|()
block|{
specifier|static
name|Theme
name|t
decl_stmt|;
return|return
operator|&
name|t
return|;
block|}
end_function
begin_function
DECL|function|setTheme
name|void
name|Theme
operator|::
name|setTheme
parameter_list|(
specifier|const
name|QString
name|theme
parameter_list|)
block|{
if|if
condition|(
name|theme
operator|.
name|compare
argument_list|(
literal|"blue"
argument_list|,
name|Qt
operator|::
name|CaseInsensitive
argument_list|)
operator|==
literal|0
condition|)
block|{
name|setTheme
argument_list|(
name|Theme
operator|::
name|Blue
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|theme
operator|.
name|compare
argument_list|(
literal|"lime"
argument_list|,
name|Qt
operator|::
name|CaseInsensitive
argument_list|)
operator|==
literal|0
condition|)
block|{
name|setTheme
argument_list|(
name|Theme
operator|::
name|Lime
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|qDebug
argument_list|()
operator|<<
literal|"Unknown theme"
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|setTheme
name|void
name|Theme
operator|::
name|setTheme
parameter_list|(
specifier|const
name|Themes
name|theme
parameter_list|)
block|{
if|if
condition|(
name|m_currentTheme
operator|==
name|theme
condition|)
return|return;
switch|switch
condition|(
name|theme
condition|)
block|{
case|case
name|Theme
operator|::
name|Blue
case|:
name|setBlueTheme
argument_list|()
expr_stmt|;
emit|emit
name|themeChanged
argument_list|()
emit|;
break|break;
case|case
name|Theme
operator|::
name|Lime
case|:
name|setLimeTheme
argument_list|()
expr_stmt|;
emit|emit
name|themeChanged
argument_list|()
emit|;
break|break;
block|}
block|}
end_function
begin_function
DECL|function|setBlueTheme
name|void
name|Theme
operator|::
name|setBlueTheme
parameter_list|()
block|{
name|m_currentTheme
operator|=
name|Theme
operator|::
name|Blue
expr_stmt|;
name|m_fonts
index|[
name|ContactName
index|]
operator|.
name|setFamily
argument_list|(
literal|"Arial"
argument_list|)
expr_stmt|;
name|m_fonts
index|[
name|ContactName
index|]
operator|.
name|setPixelSize
argument_list|(
literal|16
argument_list|)
expr_stmt|;
name|m_fonts
index|[
name|ContactName
index|]
operator|.
name|setStyle
argument_list|(
name|QFont
operator|::
name|StyleNormal
argument_list|)
expr_stmt|;
name|m_fonts
index|[
name|ContactName
index|]
operator|.
name|setWeight
argument_list|(
name|QFont
operator|::
name|Normal
argument_list|)
expr_stmt|;
name|m_fonts
index|[
name|ContactNumber
index|]
operator|.
name|setFamily
argument_list|(
literal|"Arial"
argument_list|)
expr_stmt|;
name|m_fonts
index|[
name|ContactNumber
index|]
operator|.
name|setPixelSize
argument_list|(
literal|14
argument_list|)
expr_stmt|;
name|m_fonts
index|[
name|ContactNumber
index|]
operator|.
name|setStyle
argument_list|(
name|QFont
operator|::
name|StyleNormal
argument_list|)
expr_stmt|;
name|m_fonts
index|[
name|ContactEmail
index|]
operator|.
name|setFamily
argument_list|(
literal|"Arial"
argument_list|)
expr_stmt|;
name|m_fonts
index|[
name|ContactEmail
index|]
operator|.
name|setPixelSize
argument_list|(
literal|14
argument_list|)
expr_stmt|;
name|m_fonts
index|[
name|ContactEmail
index|]
operator|.
name|setStyle
argument_list|(
name|QFont
operator|::
name|StyleNormal
argument_list|)
expr_stmt|;
name|m_fonts
index|[
name|TitleBar
index|]
operator|.
name|setFamily
argument_list|(
literal|"Arial"
argument_list|)
expr_stmt|;
name|m_fonts
index|[
name|TitleBar
index|]
operator|.
name|setPixelSize
argument_list|(
literal|36
argument_list|)
expr_stmt|;
name|m_fonts
index|[
name|TitleBar
index|]
operator|.
name|setStyle
argument_list|(
name|QFont
operator|::
name|StyleNormal
argument_list|)
expr_stmt|;
name|m_fonts
index|[
name|StatusBar
index|]
operator|.
name|setFamily
argument_list|(
literal|"Arial"
argument_list|)
expr_stmt|;
name|m_fonts
index|[
name|StatusBar
index|]
operator|.
name|setPixelSize
argument_list|(
literal|16
argument_list|)
expr_stmt|;
name|m_fonts
index|[
name|StatusBar
index|]
operator|.
name|setStyle
argument_list|(
name|QFont
operator|::
name|StyleNormal
argument_list|)
expr_stmt|;
name|m_fonts
index|[
name|MenuItem
index|]
operator|.
name|setFamily
argument_list|(
literal|"Arial"
argument_list|)
expr_stmt|;
name|m_fonts
index|[
name|MenuItem
index|]
operator|.
name|setPixelSize
argument_list|(
literal|14
argument_list|)
expr_stmt|;
name|m_fonts
index|[
name|MenuItem
index|]
operator|.
name|setStyle
argument_list|(
name|QFont
operator|::
name|StyleNormal
argument_list|)
expr_stmt|;
name|m_pixmapPath
operator|=
literal|":/themes/blue/"
expr_stmt|;
name|m_listItemBackgroundBrushEven
operator|=
name|QBrush
argument_list|(
name|Qt
operator|::
name|NoBrush
argument_list|)
expr_stmt|;
name|m_listItemBackgroundOpacityEven
operator|=
literal|1.0
expr_stmt|;
name|m_listItemBackgroundBrushOdd
operator|=
name|QBrush
argument_list|(
name|QColor
argument_list|(
literal|44
argument_list|,
literal|214
argument_list|,
literal|250
argument_list|)
argument_list|,
name|Qt
operator|::
name|SolidPattern
argument_list|)
expr_stmt|;
name|m_listItemBackgroundOpacityOdd
operator|=
literal|1.0
expr_stmt|;
name|m_listItemBorderPen
operator|=
name|QPen
argument_list|(
name|Qt
operator|::
name|NoPen
argument_list|)
expr_stmt|;
name|m_listItemRounding
operator|=
name|QSize
argument_list|(
literal|0.0
argument_list|,
literal|0.0
argument_list|)
expr_stmt|;
name|m_iconOpacityEffectEnabled
index|[
name|ListItem
operator|::
name|LeftIcon
index|]
operator|=
literal|false
expr_stmt|;
name|m_iconOpacityEffectEnabled
index|[
name|ListItem
operator|::
name|RightIcon
index|]
operator|=
literal|false
expr_stmt|;
name|m_iconRotation
index|[
name|ListItem
operator|::
name|LeftIcon
index|]
operator|=
literal|0.0
expr_stmt|;
name|m_iconRotation
index|[
name|ListItem
operator|::
name|RightIcon
index|]
operator|=
literal|0.0
expr_stmt|;
name|m_iconSmoothTransformation
index|[
name|ListItem
operator|::
name|LeftIcon
index|]
operator|=
literal|false
expr_stmt|;
name|m_iconSmoothTransformation
index|[
name|ListItem
operator|::
name|RightIcon
index|]
operator|=
literal|false
expr_stmt|;
block|}
end_function
begin_function
DECL|function|setLimeTheme
name|void
name|Theme
operator|::
name|setLimeTheme
parameter_list|()
block|{
name|m_currentTheme
operator|=
name|Theme
operator|::
name|Lime
expr_stmt|;
name|m_fonts
index|[
name|ContactName
index|]
operator|.
name|setFamily
argument_list|(
literal|"Arial"
argument_list|)
expr_stmt|;
name|m_fonts
index|[
name|ContactName
index|]
operator|.
name|setPixelSize
argument_list|(
literal|16
argument_list|)
expr_stmt|;
name|m_fonts
index|[
name|ContactName
index|]
operator|.
name|setStyle
argument_list|(
name|QFont
operator|::
name|StyleItalic
argument_list|)
expr_stmt|;
name|m_fonts
index|[
name|ContactName
index|]
operator|.
name|setWeight
argument_list|(
name|QFont
operator|::
name|Bold
argument_list|)
expr_stmt|;
name|m_fonts
index|[
name|ContactNumber
index|]
operator|.
name|setFamily
argument_list|(
literal|"Arial"
argument_list|)
expr_stmt|;
name|m_fonts
index|[
name|ContactNumber
index|]
operator|.
name|setPixelSize
argument_list|(
literal|14
argument_list|)
expr_stmt|;
name|m_fonts
index|[
name|ContactNumber
index|]
operator|.
name|setStyle
argument_list|(
name|QFont
operator|::
name|StyleItalic
argument_list|)
expr_stmt|;
name|m_fonts
index|[
name|ContactEmail
index|]
operator|.
name|setFamily
argument_list|(
literal|"Arial"
argument_list|)
expr_stmt|;
name|m_fonts
index|[
name|ContactEmail
index|]
operator|.
name|setPixelSize
argument_list|(
literal|14
argument_list|)
expr_stmt|;
name|m_fonts
index|[
name|ContactEmail
index|]
operator|.
name|setStyle
argument_list|(
name|QFont
operator|::
name|StyleItalic
argument_list|)
expr_stmt|;
name|m_fonts
index|[
name|TitleBar
index|]
operator|.
name|setFamily
argument_list|(
literal|"Arial"
argument_list|)
expr_stmt|;
name|m_fonts
index|[
name|TitleBar
index|]
operator|.
name|setPixelSize
argument_list|(
literal|36
argument_list|)
expr_stmt|;
name|m_fonts
index|[
name|TitleBar
index|]
operator|.
name|setStyle
argument_list|(
name|QFont
operator|::
name|StyleItalic
argument_list|)
expr_stmt|;
name|m_fonts
index|[
name|StatusBar
index|]
operator|.
name|setFamily
argument_list|(
literal|"Arial"
argument_list|)
expr_stmt|;
name|m_fonts
index|[
name|StatusBar
index|]
operator|.
name|setPixelSize
argument_list|(
literal|16
argument_list|)
expr_stmt|;
name|m_fonts
index|[
name|StatusBar
index|]
operator|.
name|setStyle
argument_list|(
name|QFont
operator|::
name|StyleItalic
argument_list|)
expr_stmt|;
name|m_fonts
index|[
name|MenuItem
index|]
operator|.
name|setFamily
argument_list|(
literal|"Arial"
argument_list|)
expr_stmt|;
name|m_fonts
index|[
name|MenuItem
index|]
operator|.
name|setPixelSize
argument_list|(
literal|14
argument_list|)
expr_stmt|;
name|m_fonts
index|[
name|MenuItem
index|]
operator|.
name|setStyle
argument_list|(
name|QFont
operator|::
name|StyleItalic
argument_list|)
expr_stmt|;
name|m_pixmapPath
operator|=
literal|":/themes/lime/"
expr_stmt|;
name|m_listItemBackgroundBrushEven
operator|=
name|QBrush
argument_list|(
name|QPixmap
argument_list|(
literal|":/avatars/avatar_014.png"
argument_list|)
argument_list|)
expr_stmt|;
name|m_listItemBackgroundOpacityEven
operator|=
literal|0.05
expr_stmt|;
name|m_listItemBackgroundBrushOdd
operator|=
name|QBrush
argument_list|(
name|QPixmap
argument_list|(
literal|":/avatars/avatar_012.png"
argument_list|)
argument_list|)
expr_stmt|;
name|m_listItemBackgroundOpacityOdd
operator|=
literal|0.15
expr_stmt|;
name|m_listItemBorderPen
operator|=
name|QPen
argument_list|(
name|QColor
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|55
argument_list|)
argument_list|,
literal|3
argument_list|,
name|Qt
operator|::
name|SolidLine
argument_list|)
expr_stmt|;
name|m_listItemRounding
operator|=
name|QSize
argument_list|(
literal|12.0
argument_list|,
literal|12.0
argument_list|)
expr_stmt|;
name|m_iconOpacityEffectEnabled
index|[
name|ListItem
operator|::
name|LeftIcon
index|]
operator|=
literal|true
expr_stmt|;
name|m_iconOpacityEffectEnabled
index|[
name|ListItem
operator|::
name|RightIcon
index|]
operator|=
literal|false
expr_stmt|;
name|m_iconRotation
index|[
name|ListItem
operator|::
name|LeftIcon
index|]
operator|=
operator|-
literal|4.0
expr_stmt|;
name|m_iconRotation
index|[
name|ListItem
operator|::
name|RightIcon
index|]
operator|=
literal|0.0
expr_stmt|;
name|m_iconSmoothTransformation
index|[
name|ListItem
operator|::
name|LeftIcon
index|]
operator|=
literal|true
expr_stmt|;
name|m_iconSmoothTransformation
index|[
name|ListItem
operator|::
name|RightIcon
index|]
operator|=
literal|false
expr_stmt|;
block|}
end_function
begin_function
DECL|function|pixmap
name|QPixmap
name|Theme
operator|::
name|pixmap
parameter_list|(
specifier|const
name|QString
name|filename
parameter_list|,
name|QSize
name|size
parameter_list|)
block|{
if|if
condition|(
name|filename
operator|.
name|endsWith
argument_list|(
literal|".svg"
argument_list|,
name|Qt
operator|::
name|CaseInsensitive
argument_list|)
condition|)
block|{
name|QSvgRenderer
name|doc
argument_list|(
name|m_pixmapPath
operator|+
name|filename
argument_list|)
decl_stmt|;
if|if
condition|(
name|size
operator|==
name|QSize
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
condition|)
name|size
operator|=
name|doc
operator|.
name|defaultSize
argument_list|()
expr_stmt|;
name|QPixmap
name|pix
argument_list|(
name|size
operator|.
name|width
argument_list|()
argument_list|,
name|size
operator|.
name|height
argument_list|()
argument_list|)
decl_stmt|;
name|pix
operator|.
name|fill
argument_list|(
name|Qt
operator|::
name|transparent
argument_list|)
expr_stmt|;
name|QPainter
name|painter
argument_list|(
operator|&
name|pix
argument_list|)
decl_stmt|;
name|painter
operator|.
name|setViewport
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
name|size
operator|.
name|width
argument_list|()
argument_list|,
name|size
operator|.
name|height
argument_list|()
argument_list|)
expr_stmt|;
name|doc
operator|.
name|render
argument_list|(
operator|&
name|painter
argument_list|)
expr_stmt|;
return|return
name|pix
return|;
block|}
else|else
block|{
name|QPixmap
name|pix
argument_list|(
name|m_pixmapPath
operator|+
name|filename
argument_list|)
decl_stmt|;
return|return
name|pix
operator|.
name|scaled
argument_list|(
name|size
argument_list|)
return|;
block|}
block|}
end_function
end_unit
