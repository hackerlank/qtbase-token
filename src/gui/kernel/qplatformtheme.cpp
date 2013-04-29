begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qplatformtheme.h"
end_include
begin_include
include|#
directive|include
file|"qplatformtheme_p.h"
end_include
begin_include
include|#
directive|include
file|<QtCore/QVariant>
end_include
begin_include
include|#
directive|include
file|<QtCore/QStringList>
end_include
begin_include
include|#
directive|include
file|<QtCore/qfileinfo.h>
end_include
begin_include
include|#
directive|include
file|<qpalette.h>
end_include
begin_include
include|#
directive|include
file|<qtextformat.h>
end_include
begin_include
include|#
directive|include
file|<qiconloader_p.h>
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_comment
comment|/*!     \class QPlatformTheme     \since 5.0     \internal     \preliminary     \ingroup qpa     \brief The QPlatformTheme class allows customizing the UI based on themes.  */
end_comment
begin_comment
comment|/*!     \enum QPlatformTheme::ThemeHint      This enum describes the available theme hints.      \value CursorFlashTime (int) Cursor flash time in ms, overriding                                  QPlatformIntegration::styleHint.      \value KeyboardInputInterval (int) Keyboard input interval in ms, overriding                                  QPlatformIntegration::styleHint.      \value MouseDoubleClickInterval (int) Mouse double click interval in ms,                                     overriding QPlatformIntegration::styleHint.      \value StartDragDistance (int) Start drag distance,                              overriding QPlatformIntegration::styleHint.      \value StartDragTime (int) Start drag time in ms,                                overriding QPlatformIntegration::styleHint.      \value KeyboardAutoRepeatRate (int) Keyboard auto repeat rate,                                   overriding QPlatformIntegration::styleHint.      \value PasswordMaskDelay (int) Pass word mask delay in ms,                                    overriding QPlatformIntegration::styleHint.      \value StartDragVelocity (int) Velocity of a drag,                                    overriding QPlatformIntegration::styleHint.      \value TextCursorWidth  (int) Determines the width of the text cursor.      \value DropShadow       (bool) Determines whether the drop shadow effect for                             tooltips or whatsthis is enabled.      \value MaximumScrollBarDragDistance (int) Determines the value returned by                             QStyle::pixelMetric(PM_MaximumDragDistance)      \value ToolButtonStyle (int) A value representing a Qt::ToolButtonStyle.      \value ToolBarIconSize Icon size for tool bars.      \value SystemIconThemeName (QString) Name of the icon theme.      \value SystemIconFallbackThemeName (QString) Name of the fallback icon theme.      \value IconThemeSearchPaths (QStringList) Search paths for icons.      \value ItemViewActivateItemOnSingleClick (bool) Activate items by single click.      \value StyleNames (QStringList) A list of preferred style names.      \value WindowAutoPlacement (bool) A boolean value indicating whether Windows                                (particularly dialogs) are placed by the system                                (see _NET_WM_FULL_PLACEMENT in X11).      \value DialogButtonBoxLayout (int) An integer representing a                                  QDialogButtonBox::ButtonLayout value.      \value DialogButtonBoxButtonsHaveIcons (bool) A boolean value indicating whether                                             the buttons of a QDialogButtonBox should have icons.      \value UseFullScreenForPopupMenu (bool) Pop menus can cover the full screen including task bar.      \value KeyboardScheme (int) An integer value (enum KeyboardSchemes) specifying the                            keyboard scheme.      \value UiEffects (int) A flag value consisting of UiEffect values specifying the enabled UI animations.      \value SpellCheckUnderlineStyle (int) A QTextCharFormat::UnderlineStyle specifying                                     the underline style used misspelled words when spell checking.      \value TabAllWidgets (bool) Whether tab navigation should go through all the widgets or components,                          or just through text boxes and list views. This is mostly a Mac feature.      \sa themeHint(), QStyle::pixelMetric() */
end_comment
begin_constructor
DECL|function|QPlatformThemePrivate
name|QPlatformThemePrivate
operator|::
name|QPlatformThemePrivate
parameter_list|()
member_init_list|:
name|systemPalette
argument_list|(
literal|0
argument_list|)
block|{ }
end_constructor
begin_destructor
DECL|function|~QPlatformThemePrivate
name|QPlatformThemePrivate
operator|::
name|~
name|QPlatformThemePrivate
parameter_list|()
block|{
operator|delete
name|systemPalette
expr_stmt|;
block|}
end_destructor
begin_function_decl
name|Q_GUI_EXPORT
name|QPalette
name|qt_fusionPalette
parameter_list|()
function_decl|;
end_function_decl
begin_function
DECL|function|initializeSystemPalette
name|void
name|QPlatformThemePrivate
operator|::
name|initializeSystemPalette
parameter_list|()
block|{
name|Q_ASSERT
argument_list|(
operator|!
name|systemPalette
argument_list|)
expr_stmt|;
name|systemPalette
operator|=
operator|new
name|QPalette
argument_list|(
name|qt_fusionPalette
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_constructor
DECL|function|QPlatformTheme
name|QPlatformTheme
operator|::
name|QPlatformTheme
parameter_list|()
member_init_list|:
name|d_ptr
argument_list|(
operator|new
name|QPlatformThemePrivate
argument_list|)
block|{  }
end_constructor
begin_constructor
DECL|function|QPlatformTheme
name|QPlatformTheme
operator|::
name|QPlatformTheme
parameter_list|(
name|QPlatformThemePrivate
modifier|*
name|priv
parameter_list|)
member_init_list|:
name|d_ptr
argument_list|(
name|priv
argument_list|)
block|{ }
end_constructor
begin_destructor
DECL|function|~QPlatformTheme
name|QPlatformTheme
operator|::
name|~
name|QPlatformTheme
parameter_list|()
block|{  }
end_destructor
begin_function
DECL|function|usePlatformNativeDialog
name|bool
name|QPlatformTheme
operator|::
name|usePlatformNativeDialog
parameter_list|(
name|DialogType
name|type
parameter_list|)
specifier|const
block|{
name|Q_UNUSED
argument_list|(
name|type
argument_list|)
expr_stmt|;
return|return
literal|false
return|;
block|}
end_function
begin_function
DECL|function|createPlatformDialogHelper
name|QPlatformDialogHelper
modifier|*
name|QPlatformTheme
operator|::
name|createPlatformDialogHelper
parameter_list|(
name|DialogType
name|type
parameter_list|)
specifier|const
block|{
name|Q_UNUSED
argument_list|(
name|type
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function
begin_function
DECL|function|palette
specifier|const
name|QPalette
modifier|*
name|QPlatformTheme
operator|::
name|palette
parameter_list|(
name|Palette
name|type
parameter_list|)
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QPlatformTheme
argument_list|)
expr_stmt|;
if|if
condition|(
name|type
operator|==
name|QPlatformTheme
operator|::
name|SystemPalette
condition|)
block|{
if|if
condition|(
operator|!
name|d
operator|->
name|systemPalette
condition|)
cast|const_cast
argument_list|<
name|QPlatformTheme
operator|*
argument_list|>
argument_list|(
name|this
argument_list|)
operator|->
name|d_ptr
operator|->
name|initializeSystemPalette
argument_list|()
expr_stmt|;
return|return
name|d
operator|->
name|systemPalette
return|;
block|}
return|return
literal|0
return|;
block|}
end_function
begin_function
DECL|function|font
specifier|const
name|QFont
modifier|*
name|QPlatformTheme
operator|::
name|font
parameter_list|(
name|Font
name|type
parameter_list|)
specifier|const
block|{
name|Q_UNUSED
argument_list|(
argument|type
argument_list|)
return|return
literal|0
return|;
block|}
end_function
begin_function
DECL|function|standardPixmap
name|QPixmap
name|QPlatformTheme
operator|::
name|standardPixmap
parameter_list|(
name|StandardPixmap
name|sp
parameter_list|,
specifier|const
name|QSizeF
modifier|&
name|size
parameter_list|)
specifier|const
block|{
name|Q_UNUSED
argument_list|(
name|sp
argument_list|)
expr_stmt|;
name|Q_UNUSED
argument_list|(
name|size
argument_list|)
expr_stmt|;
comment|// TODO Should return QCommonStyle pixmaps?
return|return
name|QPixmap
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|fileIconPixmap
name|QPixmap
name|QPlatformTheme
operator|::
name|fileIconPixmap
parameter_list|(
specifier|const
name|QFileInfo
modifier|&
name|fileInfo
parameter_list|,
specifier|const
name|QSizeF
modifier|&
name|size
parameter_list|,
name|QPlatformTheme
operator|::
name|IconOptions
name|iconOptions
parameter_list|)
specifier|const
block|{
name|Q_UNUSED
argument_list|(
name|fileInfo
argument_list|)
expr_stmt|;
name|Q_UNUSED
argument_list|(
name|size
argument_list|)
expr_stmt|;
name|Q_UNUSED
argument_list|(
name|iconOptions
argument_list|)
expr_stmt|;
comment|// TODO Should return QCommonStyle pixmaps?
return|return
name|QPixmap
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|themeHint
name|QVariant
name|QPlatformTheme
operator|::
name|themeHint
parameter_list|(
name|ThemeHint
name|hint
parameter_list|)
specifier|const
block|{
return|return
name|QPlatformTheme
operator|::
name|defaultThemeHint
argument_list|(
name|hint
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|defaultThemeHint
name|QVariant
name|QPlatformTheme
operator|::
name|defaultThemeHint
parameter_list|(
name|ThemeHint
name|hint
parameter_list|)
block|{
switch|switch
condition|(
name|hint
condition|)
block|{
case|case
name|QPlatformTheme
operator|::
name|CursorFlashTime
case|:
return|return
name|QVariant
argument_list|(
literal|1000
argument_list|)
return|;
case|case
name|QPlatformTheme
operator|::
name|KeyboardInputInterval
case|:
return|return
name|QVariant
argument_list|(
literal|400
argument_list|)
return|;
case|case
name|QPlatformTheme
operator|::
name|KeyboardAutoRepeatRate
case|:
return|return
name|QVariant
argument_list|(
literal|30
argument_list|)
return|;
case|case
name|QPlatformTheme
operator|::
name|MouseDoubleClickInterval
case|:
return|return
name|QVariant
argument_list|(
literal|400
argument_list|)
return|;
case|case
name|QPlatformTheme
operator|::
name|StartDragDistance
case|:
return|return
name|QVariant
argument_list|(
literal|10
argument_list|)
return|;
case|case
name|QPlatformTheme
operator|::
name|StartDragTime
case|:
return|return
name|QVariant
argument_list|(
literal|500
argument_list|)
return|;
case|case
name|QPlatformTheme
operator|::
name|PasswordMaskDelay
case|:
return|return
name|QVariant
argument_list|(
name|int
argument_list|(
literal|0
argument_list|)
argument_list|)
return|;
case|case
name|QPlatformTheme
operator|::
name|PasswordMaskCharacter
case|:
return|return
name|QVariant
argument_list|(
name|QChar
argument_list|(
literal|0x25CF
argument_list|)
argument_list|)
return|;
case|case
name|QPlatformTheme
operator|::
name|StartDragVelocity
case|:
return|return
name|QVariant
argument_list|(
name|int
argument_list|(
literal|0
argument_list|)
argument_list|)
return|;
comment|// no limit
case|case
name|QPlatformTheme
operator|::
name|UseFullScreenForPopupMenu
case|:
return|return
name|QVariant
argument_list|(
literal|false
argument_list|)
return|;
case|case
name|QPlatformTheme
operator|::
name|WindowAutoPlacement
case|:
return|return
name|QVariant
argument_list|(
literal|false
argument_list|)
return|;
case|case
name|QPlatformTheme
operator|::
name|DialogButtonBoxLayout
case|:
return|return
name|QVariant
argument_list|(
name|int
argument_list|(
literal|0
argument_list|)
argument_list|)
return|;
case|case
name|QPlatformTheme
operator|::
name|DialogButtonBoxButtonsHaveIcons
case|:
return|return
name|QVariant
argument_list|(
literal|false
argument_list|)
return|;
case|case
name|QPlatformTheme
operator|::
name|ItemViewActivateItemOnSingleClick
case|:
return|return
name|QVariant
argument_list|(
literal|false
argument_list|)
return|;
case|case
name|QPlatformTheme
operator|::
name|ToolButtonStyle
case|:
return|return
name|QVariant
argument_list|(
name|int
argument_list|(
name|Qt
operator|::
name|ToolButtonIconOnly
argument_list|)
argument_list|)
return|;
case|case
name|QPlatformTheme
operator|::
name|ToolBarIconSize
case|:
return|return
name|QVariant
argument_list|(
name|int
argument_list|(
literal|0
argument_list|)
argument_list|)
return|;
case|case
name|QPlatformTheme
operator|::
name|SystemIconThemeName
case|:
case|case
name|QPlatformTheme
operator|::
name|SystemIconFallbackThemeName
case|:
return|return
name|QVariant
argument_list|(
name|QString
argument_list|()
argument_list|)
return|;
case|case
name|QPlatformTheme
operator|::
name|IconThemeSearchPaths
case|:
return|return
name|QVariant
argument_list|(
name|QStringList
argument_list|()
argument_list|)
return|;
case|case
name|QPlatformTheme
operator|::
name|StyleNames
case|:
return|return
name|QVariant
argument_list|(
name|QStringList
argument_list|()
argument_list|)
return|;
case|case
name|TextCursorWidth
case|:
return|return
name|QVariant
argument_list|(
literal|1
argument_list|)
return|;
case|case
name|DropShadow
case|:
return|return
name|QVariant
argument_list|(
literal|false
argument_list|)
return|;
case|case
name|MaximumScrollBarDragDistance
case|:
return|return
name|QVariant
argument_list|(
operator|-
literal|1
argument_list|)
return|;
case|case
name|KeyboardScheme
case|:
return|return
name|QVariant
argument_list|(
name|int
argument_list|(
name|WindowsKeyboardScheme
argument_list|)
argument_list|)
return|;
case|case
name|UiEffects
case|:
return|return
name|QVariant
argument_list|(
name|int
argument_list|(
literal|0
argument_list|)
argument_list|)
return|;
case|case
name|SpellCheckUnderlineStyle
case|:
return|return
name|QVariant
argument_list|(
name|int
argument_list|(
name|QTextCharFormat
operator|::
name|SpellCheckUnderline
argument_list|)
argument_list|)
return|;
case|case
name|TabAllWidgets
case|:
return|return
name|QVariant
argument_list|(
literal|true
argument_list|)
return|;
case|case
name|IconPixmapSizes
case|:
return|return
name|QVariant
operator|::
name|fromValue
argument_list|(
name|QList
argument_list|<
name|int
argument_list|>
argument_list|()
argument_list|)
return|;
block|}
return|return
name|QVariant
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|createPlatformMenuItem
name|QPlatformMenuItem
modifier|*
name|QPlatformTheme
operator|::
name|createPlatformMenuItem
parameter_list|()
specifier|const
block|{
return|return
literal|0
return|;
block|}
end_function
begin_function
DECL|function|createPlatformMenu
name|QPlatformMenu
modifier|*
name|QPlatformTheme
operator|::
name|createPlatformMenu
parameter_list|()
specifier|const
block|{
return|return
literal|0
return|;
block|}
end_function
begin_function
DECL|function|createPlatformMenuBar
name|QPlatformMenuBar
modifier|*
name|QPlatformTheme
operator|::
name|createPlatformMenuBar
parameter_list|()
specifier|const
block|{
return|return
literal|0
return|;
block|}
end_function
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_SYSTEMTRAYICON
end_ifndef
begin_comment
comment|/*!    Factory function for QSystemTrayIcon. This function will return 0 if the platform    integration does not support creating any system tray icon. */
end_comment
begin_function
DECL|function|createPlatformSystemTrayIcon
name|QPlatformSystemTrayIcon
modifier|*
name|QPlatformTheme
operator|::
name|createPlatformSystemTrayIcon
parameter_list|()
specifier|const
block|{
return|return
literal|0
return|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/*!    Factory function for the QIconEngine used by QIcon::fromTheme(). By default this    function returns a QIconLoaderEngine, but subclasses can reimplement it to    provide their own.     It is especially useful to benefit from some platform specific facilities or    optimizations like an inter-process cache in systems mostly built with Qt.     \since 5.1 */
end_comment
begin_function
DECL|function|createIconEngine
name|QIconEngine
modifier|*
name|QPlatformTheme
operator|::
name|createIconEngine
parameter_list|(
specifier|const
name|QString
modifier|&
name|iconName
parameter_list|)
specifier|const
block|{
return|return
operator|new
name|QIconLoaderEngine
argument_list|(
name|iconName
argument_list|)
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
