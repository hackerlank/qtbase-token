begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QPLATFORMTHEME_H
end_ifndef
begin_define
DECL|macro|QPLATFORMTHEME_H
define|#
directive|define
name|QPLATFORMTHEME_H
end_define
begin_comment
comment|//
end_comment
begin_comment
comment|//  W A R N I N G
end_comment
begin_comment
comment|//  -------------
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|// This file is part of the QPA API and is not meant to be used
end_comment
begin_comment
comment|// in applications. Usage of this API may make your code
end_comment
begin_comment
comment|// source and binary incompatible with future versions of Qt.
end_comment
begin_comment
comment|//
end_comment
begin_include
include|#
directive|include
file|<QtCore/QtGlobal>
end_include
begin_include
include|#
directive|include
file|<QtCore/QScopedPointer>
end_include
begin_include
include|#
directive|include
file|<QtGui/QKeySequence>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QIconEngine
name|class
name|QIconEngine
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QMenu
name|class
name|QMenu
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QMenuBar
name|class
name|QMenuBar
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QPlatformMenuItem
name|class
name|QPlatformMenuItem
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QPlatformMenu
name|class
name|QPlatformMenu
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QPlatformMenuBar
name|class
name|QPlatformMenuBar
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QPlatformDialogHelper
name|class
name|QPlatformDialogHelper
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QPlatformSystemTrayIcon
name|class
name|QPlatformSystemTrayIcon
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QPlatformThemePrivate
name|class
name|QPlatformThemePrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QVariant
name|class
name|QVariant
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QPalette
name|class
name|QPalette
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QFont
name|class
name|QFont
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QPixmap
name|class
name|QPixmap
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QSizeF
name|class
name|QSizeF
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QFileInfo
name|class
name|QFileInfo
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_GUI_EXPORT
name|QPlatformTheme
block|{
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QPlatformTheme
argument_list|)
name|public
label|:
enum|enum
name|ThemeHint
block|{
name|CursorFlashTime
block|,
name|KeyboardInputInterval
block|,
name|MouseDoubleClickInterval
block|,
name|StartDragDistance
block|,
name|StartDragTime
block|,
name|KeyboardAutoRepeatRate
block|,
name|PasswordMaskDelay
block|,
name|StartDragVelocity
block|,
name|TextCursorWidth
block|,
name|DropShadow
block|,
name|MaximumScrollBarDragDistance
block|,
name|ToolButtonStyle
block|,
name|ToolBarIconSize
block|,
name|ItemViewActivateItemOnSingleClick
block|,
name|SystemIconThemeName
block|,
name|SystemIconFallbackThemeName
block|,
name|IconThemeSearchPaths
block|,
name|StyleNames
block|,
name|WindowAutoPlacement
block|,
name|DialogButtonBoxLayout
block|,
name|DialogButtonBoxButtonsHaveIcons
block|,
name|UseFullScreenForPopupMenu
block|,
name|KeyboardScheme
block|,
name|UiEffects
block|,
name|SpellCheckUnderlineStyle
block|,
name|TabAllWidgets
block|,
name|IconPixmapSizes
block|,
name|PasswordMaskCharacter
block|,
name|DialogSnapToDefaultButton
block|}
enum|;
enum|enum
name|DialogType
block|{
name|FileDialog
block|,
name|ColorDialog
block|,
name|FontDialog
block|}
enum|;
enum|enum
name|Palette
block|{
name|SystemPalette
block|,
name|ToolTipPalette
block|,
name|ToolButtonPalette
block|,
name|ButtonPalette
block|,
name|CheckBoxPalette
block|,
name|RadioButtonPalette
block|,
name|HeaderPalette
block|,
name|ComboBoxPalette
block|,
name|ItemViewPalette
block|,
name|MessageBoxLabelPelette
block|,
name|TabBarPalette
block|,
name|LabelPalette
block|,
name|GroupBoxPalette
block|,
name|MenuPalette
block|,
name|MenuBarPalette
block|,
name|TextEditPalette
block|,
name|TextLineEditPalette
block|,
name|NPalettes
block|}
enum|;
enum|enum
name|Font
block|{
name|SystemFont
block|,
name|MenuFont
block|,
name|MenuBarFont
block|,
name|MenuItemFont
block|,
name|MessageBoxFont
block|,
name|LabelFont
block|,
name|TipLabelFont
block|,
name|StatusBarFont
block|,
name|TitleBarFont
block|,
name|MdiSubWindowTitleFont
block|,
name|DockWidgetTitleFont
block|,
name|PushButtonFont
block|,
name|CheckBoxFont
block|,
name|RadioButtonFont
block|,
name|ToolButtonFont
block|,
name|ItemViewFont
block|,
name|ListViewFont
block|,
name|HeaderViewFont
block|,
name|ListBoxFont
block|,
name|ComboMenuItemFont
block|,
name|ComboLineEditFont
block|,
name|SmallFont
block|,
name|MiniFont
block|,
name|FixedFont
block|,
name|NFonts
block|}
enum|;
enum|enum
name|StandardPixmap
block|{
comment|// Keep in sync with QStyle::StandardPixmap
name|TitleBarMenuButton
block|,
name|TitleBarMinButton
block|,
name|TitleBarMaxButton
block|,
name|TitleBarCloseButton
block|,
name|TitleBarNormalButton
block|,
name|TitleBarShadeButton
block|,
name|TitleBarUnshadeButton
block|,
name|TitleBarContextHelpButton
block|,
name|DockWidgetCloseButton
block|,
name|MessageBoxInformation
block|,
name|MessageBoxWarning
block|,
name|MessageBoxCritical
block|,
name|MessageBoxQuestion
block|,
name|DesktopIcon
block|,
name|TrashIcon
block|,
name|ComputerIcon
block|,
name|DriveFDIcon
block|,
name|DriveHDIcon
block|,
name|DriveCDIcon
block|,
name|DriveDVDIcon
block|,
name|DriveNetIcon
block|,
name|DirOpenIcon
block|,
name|DirClosedIcon
block|,
name|DirLinkIcon
block|,
name|DirLinkOpenIcon
block|,
name|FileIcon
block|,
name|FileLinkIcon
block|,
name|ToolBarHorizontalExtensionButton
block|,
name|ToolBarVerticalExtensionButton
block|,
name|FileDialogStart
block|,
name|FileDialogEnd
block|,
name|FileDialogToParent
block|,
name|FileDialogNewFolder
block|,
name|FileDialogDetailedView
block|,
name|FileDialogInfoView
block|,
name|FileDialogContentsView
block|,
name|FileDialogListView
block|,
name|FileDialogBack
block|,
name|DirIcon
block|,
name|DialogOkButton
block|,
name|DialogCancelButton
block|,
name|DialogHelpButton
block|,
name|DialogOpenButton
block|,
name|DialogSaveButton
block|,
name|DialogCloseButton
block|,
name|DialogApplyButton
block|,
name|DialogResetButton
block|,
name|DialogDiscardButton
block|,
name|DialogYesButton
block|,
name|DialogNoButton
block|,
name|ArrowUp
block|,
name|ArrowDown
block|,
name|ArrowLeft
block|,
name|ArrowRight
block|,
name|ArrowBack
block|,
name|ArrowForward
block|,
name|DirHomeIcon
block|,
name|CommandLink
block|,
name|VistaShield
block|,
name|BrowserReload
block|,
name|BrowserStop
block|,
name|MediaPlay
block|,
name|MediaStop
block|,
name|MediaPause
block|,
name|MediaSkipForward
block|,
name|MediaSkipBackward
block|,
name|MediaSeekForward
block|,
name|MediaSeekBackward
block|,
name|MediaVolume
block|,
name|MediaVolumeMuted
block|,
comment|// do not add any values below/greater than this
name|CustomBase
init|=
literal|0xf0000000
block|}
enum|;
enum|enum
name|KeyboardSchemes
block|{
name|WindowsKeyboardScheme
block|,
name|MacKeyboardScheme
block|,
name|X11KeyboardScheme
block|,
name|KdeKeyboardScheme
block|,
name|GnomeKeyboardScheme
block|,
name|CdeKeyboardScheme
block|}
enum|;
enum|enum
name|UiEffect
block|{
name|GeneralUiEffect
init|=
literal|0x1
block|,
name|AnimateMenuUiEffect
init|=
literal|0x2
block|,
name|FadeMenuUiEffect
init|=
literal|0x4
block|,
name|AnimateComboUiEffect
init|=
literal|0x8
block|,
name|AnimateTooltipUiEffect
init|=
literal|0x10
block|,
name|FadeTooltipUiEffect
init|=
literal|0x20
block|,
name|AnimateToolBoxUiEffect
init|=
literal|0x40
block|}
enum|;
enum|enum
name|IconOption
block|{
name|DontUseCustomDirectoryIcons
init|=
literal|0x01
block|}
enum|;
name|Q_DECLARE_FLAGS
argument_list|(
argument|IconOptions
argument_list|,
argument|IconOption
argument_list|)
name|explicit
name|QPlatformTheme
parameter_list|()
function_decl|;
name|virtual
operator|~
name|QPlatformTheme
argument_list|()
expr_stmt|;
name|virtual
name|QPlatformMenuItem
operator|*
name|createPlatformMenuItem
argument_list|()
specifier|const
expr_stmt|;
name|virtual
name|QPlatformMenu
operator|*
name|createPlatformMenu
argument_list|()
specifier|const
expr_stmt|;
name|virtual
name|QPlatformMenuBar
operator|*
name|createPlatformMenuBar
argument_list|()
specifier|const
expr_stmt|;
name|virtual
name|bool
name|usePlatformNativeDialog
argument_list|(
name|DialogType
name|type
argument_list|)
decl|const
decl_stmt|;
name|virtual
name|QPlatformDialogHelper
modifier|*
name|createPlatformDialogHelper
argument_list|(
name|DialogType
name|type
argument_list|)
decl|const
decl_stmt|;
ifndef|#
directive|ifndef
name|QT_NO_SYSTEMTRAYICON
name|virtual
name|QPlatformSystemTrayIcon
operator|*
name|createPlatformSystemTrayIcon
argument_list|()
specifier|const
expr_stmt|;
endif|#
directive|endif
name|virtual
specifier|const
name|QPalette
modifier|*
name|palette
argument_list|(
name|Palette
name|type
operator|=
name|SystemPalette
argument_list|)
decl|const
decl_stmt|;
name|virtual
specifier|const
name|QFont
modifier|*
name|font
argument_list|(
name|Font
name|type
operator|=
name|SystemFont
argument_list|)
decl|const
decl_stmt|;
name|virtual
name|QVariant
name|themeHint
argument_list|(
name|ThemeHint
name|hint
argument_list|)
decl|const
decl_stmt|;
name|virtual
name|QPixmap
name|standardPixmap
argument_list|(
name|StandardPixmap
name|sp
argument_list|,
specifier|const
name|QSizeF
operator|&
name|size
argument_list|)
decl|const
decl_stmt|;
name|virtual
name|QPixmap
name|fileIconPixmap
argument_list|(
specifier|const
name|QFileInfo
operator|&
name|fileInfo
argument_list|,
specifier|const
name|QSizeF
operator|&
name|size
argument_list|,
name|QPlatformTheme
operator|::
name|IconOptions
name|iconOptions
operator|=
literal|0
argument_list|)
decl|const
decl_stmt|;
name|virtual
name|QIconEngine
modifier|*
name|createIconEngine
argument_list|(
specifier|const
name|QString
operator|&
name|iconName
argument_list|)
decl|const
decl_stmt|;
name|virtual
name|QList
operator|<
name|QKeySequence
operator|>
name|keyBindings
argument_list|(
argument|QKeySequence::StandardKey key
argument_list|)
specifier|const
expr_stmt|;
specifier|static
name|QVariant
name|defaultThemeHint
parameter_list|(
name|ThemeHint
name|hint
parameter_list|)
function_decl|;
name|protected
label|:
name|explicit
name|QPlatformTheme
parameter_list|(
name|QPlatformThemePrivate
modifier|*
name|priv
parameter_list|)
function_decl|;
name|QScopedPointer
operator|<
name|QPlatformThemePrivate
operator|>
name|d_ptr
expr_stmt|;
name|private
label|:
name|Q_DISABLE_COPY
argument_list|(
argument|QPlatformTheme
argument_list|)
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
begin_comment
comment|// QPLATFORMTHEME_H
end_comment
end_unit
