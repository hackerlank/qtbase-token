begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2014 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia. For licensing terms and ** conditions see http://qt.digia.com/licensing. For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights. These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QPLATFORMDIALOGHELPER_H
end_ifndef
begin_define
DECL|macro|QPLATFORMDIALOGHELPER_H
define|#
directive|define
name|QPLATFORMDIALOGHELPER_H
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
file|<QtCore/QObject>
end_include
begin_include
include|#
directive|include
file|<QtCore/QList>
end_include
begin_include
include|#
directive|include
file|<QtCore/QSharedDataPointer>
end_include
begin_include
include|#
directive|include
file|<QtCore/QSharedPointer>
end_include
begin_include
include|#
directive|include
file|<QtCore/QDir>
end_include
begin_include
include|#
directive|include
file|<QtCore/QUrl>
end_include
begin_include
include|#
directive|include
file|<QtGui/QRgb>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QString
name|class
name|QString
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QColor
name|class
name|QColor
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QFont
name|class
name|QFont
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QWindow
name|class
name|QWindow
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QVariant
name|class
name|QVariant
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QUrl
name|class
name|QUrl
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QColorDialogOptionsPrivate
name|class
name|QColorDialogOptionsPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QFontDialogOptionsPrivate
name|class
name|QFontDialogOptionsPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QFileDialogOptionsPrivate
name|class
name|QFileDialogOptionsPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QMessageDialogOptionsPrivate
name|class
name|QMessageDialogOptionsPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_GUI_EXPORT
name|QPlatformDialogHelper
range|:
name|public
name|QObject
block|{
name|Q_OBJECT
name|public
operator|:
expr|enum
name|StyleHint
block|{     }
block|;     enum
name|DialogCode
block|{
name|Rejected
block|,
name|Accepted
block|}
block|;      enum
name|StandardButton
block|{
comment|// keep this in sync with QDialogButtonBox::StandardButton and QMessageBox::StandardButton
name|NoButton
operator|=
literal|0x00000000
block|,
name|Ok
operator|=
literal|0x00000400
block|,
name|Save
operator|=
literal|0x00000800
block|,
name|SaveAll
operator|=
literal|0x00001000
block|,
name|Open
operator|=
literal|0x00002000
block|,
name|Yes
operator|=
literal|0x00004000
block|,
name|YesToAll
operator|=
literal|0x00008000
block|,
name|No
operator|=
literal|0x00010000
block|,
name|NoToAll
operator|=
literal|0x00020000
block|,
name|Abort
operator|=
literal|0x00040000
block|,
name|Retry
operator|=
literal|0x00080000
block|,
name|Ignore
operator|=
literal|0x00100000
block|,
name|Close
operator|=
literal|0x00200000
block|,
name|Cancel
operator|=
literal|0x00400000
block|,
name|Discard
operator|=
literal|0x00800000
block|,
name|Help
operator|=
literal|0x01000000
block|,
name|Apply
operator|=
literal|0x02000000
block|,
name|Reset
operator|=
literal|0x04000000
block|,
name|RestoreDefaults
operator|=
literal|0x08000000
block|,
name|FirstButton
operator|=
name|Ok
block|,
comment|// internal
name|LastButton
operator|=
name|RestoreDefaults
block|,
comment|// internal
name|LowestBit
operator|=
literal|10
block|,
comment|// internal: log2(FirstButton)
name|HighestBit
operator|=
literal|27
comment|// internal: log2(LastButton)
block|}
block|;
name|Q_DECLARE_FLAGS
argument_list|(
name|StandardButtons
argument_list|,
name|StandardButton
argument_list|)
expr|enum
name|ButtonRole
block|{
comment|// keep this in sync with QDialogButtonBox::ButtonRole and QMessageBox::ButtonRole
comment|// TODO Qt 6: make the enum copies explicit, and make InvalidRole == 0 so that
comment|// AcceptRole can be or'ed with flags, and EOL can be the same as InvalidRole (null-termination)
name|InvalidRole
operator|=
operator|-
literal|1
block|,
name|AcceptRole
block|,
name|RejectRole
block|,
name|DestructiveRole
block|,
name|ActionRole
block|,
name|HelpRole
block|,
name|YesRole
block|,
name|NoRole
block|,
name|ResetRole
block|,
name|ApplyRole
block|,
name|NRoles
block|,
name|RoleMask
operator|=
literal|0x0FFFFFFF
block|,
name|AlternateRole
operator|=
literal|0x10000000
block|,
name|Stretch
operator|=
literal|0x20000000
block|,
name|Reverse
operator|=
literal|0x40000000
block|,
name|EOL
operator|=
name|InvalidRole
block|}
block|;      enum
name|ButtonLayout
block|{
comment|// keep this in sync with QDialogButtonBox::ButtonLayout and QMessageBox::ButtonLayout
name|UnknownLayout
operator|=
operator|-
literal|1
block|,
name|WinLayout
block|,
name|MacLayout
block|,
name|KdeLayout
block|,
name|GnomeLayout
block|,
name|MacModelessLayout
block|}
block|;
name|QPlatformDialogHelper
argument_list|()
block|;
name|virtual
operator|~
name|QPlatformDialogHelper
argument_list|()
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
name|void
name|exec
argument_list|()
operator|=
literal|0
block|;
name|virtual
name|bool
name|show
argument_list|(
argument|Qt::WindowFlags windowFlags
argument_list|,
argument|Qt::WindowModality windowModality
argument_list|,
argument|QWindow *parent
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|void
name|hide
argument_list|()
operator|=
literal|0
block|;
specifier|static
name|QVariant
name|defaultStyleHint
argument_list|(
argument|QPlatformDialogHelper::StyleHint hint
argument_list|)
block|;
specifier|static
specifier|const
name|int
operator|*
name|buttonLayout
argument_list|(
argument|Qt::Orientation orientation = Qt::Horizontal
argument_list|,
argument|ButtonLayout policy = UnknownLayout
argument_list|)
block|;
specifier|static
name|ButtonRole
name|buttonRole
argument_list|(
argument|StandardButton button
argument_list|)
block|;
name|Q_SIGNALS
operator|:
name|void
name|accept
argument_list|()
block|;
name|void
name|reject
argument_list|()
block|; }
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_GUI_EXPORT
name|QColorDialogOptions
block|{
name|public
label|:
enum|enum
name|ColorDialogOption
block|{
name|ShowAlphaChannel
init|=
literal|0x00000001
block|,
name|NoButtons
init|=
literal|0x00000002
block|,
name|DontUseNativeDialog
init|=
literal|0x00000004
block|}
enum|;
name|Q_DECLARE_FLAGS
argument_list|(
argument|ColorDialogOptions
argument_list|,
argument|ColorDialogOption
argument_list|)
name|QColorDialogOptions
argument_list|()
expr_stmt|;
name|QColorDialogOptions
argument_list|(
specifier|const
name|QColorDialogOptions
operator|&
name|rhs
argument_list|)
expr_stmt|;
name|QColorDialogOptions
modifier|&
name|operator
init|=
operator|(
specifier|const
name|QColorDialogOptions
operator|&
name|rhs
operator|)
decl_stmt|;
operator|~
name|QColorDialogOptions
argument_list|()
expr_stmt|;
name|void
name|swap
parameter_list|(
name|QColorDialogOptions
modifier|&
name|other
parameter_list|)
block|{
name|qSwap
argument_list|(
name|d
argument_list|,
name|other
operator|.
name|d
argument_list|)
expr_stmt|;
block|}
name|QString
name|windowTitle
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setWindowTitle
parameter_list|(
specifier|const
name|QString
modifier|&
parameter_list|)
function_decl|;
name|void
name|setOption
parameter_list|(
name|ColorDialogOption
name|option
parameter_list|,
name|bool
name|on
init|=
name|true
parameter_list|)
function_decl|;
name|bool
name|testOption
argument_list|(
name|ColorDialogOption
name|option
argument_list|)
decl|const
decl_stmt|;
name|void
name|setOptions
parameter_list|(
name|ColorDialogOptions
name|options
parameter_list|)
function_decl|;
name|ColorDialogOptions
name|options
argument_list|()
specifier|const
expr_stmt|;
specifier|static
name|int
name|customColorCount
parameter_list|()
function_decl|;
specifier|static
name|QRgb
name|customColor
parameter_list|(
name|int
name|index
parameter_list|)
function_decl|;
specifier|static
name|QRgb
modifier|*
name|customColors
parameter_list|()
function_decl|;
specifier|static
name|void
name|setCustomColor
parameter_list|(
name|int
name|index
parameter_list|,
name|QRgb
name|color
parameter_list|)
function_decl|;
specifier|static
name|QRgb
modifier|*
name|standardColors
parameter_list|()
function_decl|;
specifier|static
name|QRgb
name|standardColor
parameter_list|(
name|int
name|index
parameter_list|)
function_decl|;
specifier|static
name|void
name|setStandardColor
parameter_list|(
name|int
name|index
parameter_list|,
name|QRgb
name|color
parameter_list|)
function_decl|;
name|private
label|:
name|QSharedDataPointer
operator|<
name|QColorDialogOptionsPrivate
operator|>
name|d
expr_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_macro
DECL|function|Q_DECLARE_SHARED
name|Q_DECLARE_SHARED
argument_list|(
argument|QColorDialogOptions
argument_list|)
end_macro
begin_decl_stmt
name|class
name|Q_GUI_EXPORT
name|QPlatformColorDialogHelper
range|:
name|public
name|QPlatformDialogHelper
block|{
name|Q_OBJECT
name|public
operator|:
specifier|const
name|QSharedPointer
operator|<
name|QColorDialogOptions
operator|>
operator|&
name|options
argument_list|()
specifier|const
block|;
name|void
name|setOptions
argument_list|(
specifier|const
name|QSharedPointer
operator|<
name|QColorDialogOptions
operator|>
operator|&
name|options
argument_list|)
block|;
name|virtual
name|void
name|setCurrentColor
argument_list|(
specifier|const
name|QColor
operator|&
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|QColor
name|currentColor
argument_list|()
specifier|const
operator|=
literal|0
block|;
name|Q_SIGNALS
operator|:
name|void
name|currentColorChanged
argument_list|(
specifier|const
name|QColor
operator|&
name|color
argument_list|)
block|;
name|void
name|colorSelected
argument_list|(
specifier|const
name|QColor
operator|&
name|color
argument_list|)
block|;
name|private
operator|:
name|QSharedPointer
operator|<
name|QColorDialogOptions
operator|>
name|m_options
block|; }
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_GUI_EXPORT
name|QFontDialogOptions
block|{
name|public
label|:
enum|enum
name|FontDialogOption
block|{
name|NoButtons
init|=
literal|0x00000001
block|,
name|DontUseNativeDialog
init|=
literal|0x00000002
block|,
name|ScalableFonts
init|=
literal|0x00000004
block|,
name|NonScalableFonts
init|=
literal|0x00000008
block|,
name|MonospacedFonts
init|=
literal|0x00000010
block|,
name|ProportionalFonts
init|=
literal|0x00000020
block|}
enum|;
name|Q_DECLARE_FLAGS
argument_list|(
argument|FontDialogOptions
argument_list|,
argument|FontDialogOption
argument_list|)
name|QFontDialogOptions
argument_list|()
expr_stmt|;
name|QFontDialogOptions
argument_list|(
specifier|const
name|QFontDialogOptions
operator|&
name|rhs
argument_list|)
expr_stmt|;
name|QFontDialogOptions
modifier|&
name|operator
init|=
operator|(
specifier|const
name|QFontDialogOptions
operator|&
name|rhs
operator|)
decl_stmt|;
operator|~
name|QFontDialogOptions
argument_list|()
expr_stmt|;
name|void
name|swap
parameter_list|(
name|QFontDialogOptions
modifier|&
name|other
parameter_list|)
block|{
name|qSwap
argument_list|(
name|d
argument_list|,
name|other
operator|.
name|d
argument_list|)
expr_stmt|;
block|}
name|QString
name|windowTitle
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setWindowTitle
parameter_list|(
specifier|const
name|QString
modifier|&
parameter_list|)
function_decl|;
name|void
name|setOption
parameter_list|(
name|FontDialogOption
name|option
parameter_list|,
name|bool
name|on
init|=
name|true
parameter_list|)
function_decl|;
name|bool
name|testOption
argument_list|(
name|FontDialogOption
name|option
argument_list|)
decl|const
decl_stmt|;
name|void
name|setOptions
parameter_list|(
name|FontDialogOptions
name|options
parameter_list|)
function_decl|;
name|FontDialogOptions
name|options
argument_list|()
specifier|const
expr_stmt|;
name|private
label|:
name|QSharedDataPointer
operator|<
name|QFontDialogOptionsPrivate
operator|>
name|d
expr_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_macro
DECL|function|Q_DECLARE_SHARED
name|Q_DECLARE_SHARED
argument_list|(
argument|QFontDialogOptions
argument_list|)
end_macro
begin_decl_stmt
name|class
name|Q_GUI_EXPORT
name|QPlatformFontDialogHelper
range|:
name|public
name|QPlatformDialogHelper
block|{
name|Q_OBJECT
name|public
operator|:
name|virtual
name|void
name|setCurrentFont
argument_list|(
specifier|const
name|QFont
operator|&
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|QFont
name|currentFont
argument_list|()
specifier|const
operator|=
literal|0
block|;
specifier|const
name|QSharedPointer
operator|<
name|QFontDialogOptions
operator|>
operator|&
name|options
argument_list|()
specifier|const
block|;
name|void
name|setOptions
argument_list|(
specifier|const
name|QSharedPointer
operator|<
name|QFontDialogOptions
operator|>
operator|&
name|options
argument_list|)
block|;
name|Q_SIGNALS
operator|:
name|void
name|currentFontChanged
argument_list|(
specifier|const
name|QFont
operator|&
name|font
argument_list|)
block|;
name|void
name|fontSelected
argument_list|(
specifier|const
name|QFont
operator|&
name|font
argument_list|)
block|;
name|private
operator|:
name|QSharedPointer
operator|<
name|QFontDialogOptions
operator|>
name|m_options
block|; }
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_GUI_EXPORT
name|QFileDialogOptions
block|{
name|public
label|:
enum|enum
name|ViewMode
block|{
name|Detail
block|,
name|List
block|}
enum|;
enum|enum
name|FileMode
block|{
name|AnyFile
block|,
name|ExistingFile
block|,
name|Directory
block|,
name|ExistingFiles
block|,
name|DirectoryOnly
block|}
enum|;
enum|enum
name|AcceptMode
block|{
name|AcceptOpen
block|,
name|AcceptSave
block|}
enum|;
enum|enum
name|DialogLabel
block|{
name|LookIn
block|,
name|FileName
block|,
name|FileType
block|,
name|Accept
block|,
name|Reject
block|,
name|DialogLabelCount
block|}
enum|;
enum|enum
name|FileDialogOption
block|{
name|ShowDirsOnly
init|=
literal|0x00000001
block|,
name|DontResolveSymlinks
init|=
literal|0x00000002
block|,
name|DontConfirmOverwrite
init|=
literal|0x00000004
block|,
name|DontUseSheet
init|=
literal|0x00000008
block|,
name|DontUseNativeDialog
init|=
literal|0x00000010
block|,
name|ReadOnly
init|=
literal|0x00000020
block|,
name|HideNameFilterDetails
init|=
literal|0x00000040
block|,
name|DontUseCustomDirectoryIcons
init|=
literal|0x00000080
block|}
enum|;
name|Q_DECLARE_FLAGS
argument_list|(
argument|FileDialogOptions
argument_list|,
argument|FileDialogOption
argument_list|)
name|QFileDialogOptions
argument_list|()
expr_stmt|;
name|QFileDialogOptions
argument_list|(
specifier|const
name|QFileDialogOptions
operator|&
name|rhs
argument_list|)
expr_stmt|;
name|QFileDialogOptions
modifier|&
name|operator
init|=
operator|(
specifier|const
name|QFileDialogOptions
operator|&
name|rhs
operator|)
decl_stmt|;
operator|~
name|QFileDialogOptions
argument_list|()
expr_stmt|;
name|void
name|swap
parameter_list|(
name|QFileDialogOptions
modifier|&
name|other
parameter_list|)
block|{
name|qSwap
argument_list|(
name|d
argument_list|,
name|other
operator|.
name|d
argument_list|)
expr_stmt|;
block|}
name|QString
name|windowTitle
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setWindowTitle
parameter_list|(
specifier|const
name|QString
modifier|&
parameter_list|)
function_decl|;
name|void
name|setOption
parameter_list|(
name|FileDialogOption
name|option
parameter_list|,
name|bool
name|on
init|=
name|true
parameter_list|)
function_decl|;
name|bool
name|testOption
argument_list|(
name|FileDialogOption
name|option
argument_list|)
decl|const
decl_stmt|;
name|void
name|setOptions
parameter_list|(
name|FileDialogOptions
name|options
parameter_list|)
function_decl|;
name|FileDialogOptions
name|options
argument_list|()
specifier|const
expr_stmt|;
name|QDir
operator|::
name|Filters
name|filter
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setFilter
argument_list|(
name|QDir
operator|::
name|Filters
name|filters
argument_list|)
decl_stmt|;
name|void
name|setViewMode
parameter_list|(
name|ViewMode
name|mode
parameter_list|)
function_decl|;
name|ViewMode
name|viewMode
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setFileMode
parameter_list|(
name|FileMode
name|mode
parameter_list|)
function_decl|;
name|FileMode
name|fileMode
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setAcceptMode
parameter_list|(
name|AcceptMode
name|mode
parameter_list|)
function_decl|;
name|AcceptMode
name|acceptMode
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setSidebarUrls
argument_list|(
specifier|const
name|QList
operator|<
name|QUrl
operator|>
operator|&
name|urls
argument_list|)
decl_stmt|;
name|QList
operator|<
name|QUrl
operator|>
name|sidebarUrls
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setNameFilters
parameter_list|(
specifier|const
name|QStringList
modifier|&
name|filters
parameter_list|)
function_decl|;
name|QStringList
name|nameFilters
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setMimeTypeFilters
parameter_list|(
specifier|const
name|QStringList
modifier|&
name|filters
parameter_list|)
function_decl|;
name|QStringList
name|mimeTypeFilters
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setDefaultSuffix
parameter_list|(
specifier|const
name|QString
modifier|&
name|suffix
parameter_list|)
function_decl|;
name|QString
name|defaultSuffix
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setHistory
parameter_list|(
specifier|const
name|QStringList
modifier|&
name|paths
parameter_list|)
function_decl|;
name|QStringList
name|history
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setLabelText
parameter_list|(
name|DialogLabel
name|label
parameter_list|,
specifier|const
name|QString
modifier|&
name|text
parameter_list|)
function_decl|;
name|QString
name|labelText
argument_list|(
name|DialogLabel
name|label
argument_list|)
decl|const
decl_stmt|;
name|bool
name|isLabelExplicitlySet
parameter_list|(
name|DialogLabel
name|label
parameter_list|)
function_decl|;
name|QUrl
name|initialDirectory
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setInitialDirectory
parameter_list|(
specifier|const
name|QUrl
modifier|&
parameter_list|)
function_decl|;
name|QString
name|initiallySelectedNameFilter
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setInitiallySelectedNameFilter
parameter_list|(
specifier|const
name|QString
modifier|&
parameter_list|)
function_decl|;
name|QList
operator|<
name|QUrl
operator|>
name|initiallySelectedFiles
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setInitiallySelectedFiles
argument_list|(
specifier|const
name|QList
operator|<
name|QUrl
operator|>
operator|&
argument_list|)
decl_stmt|;
name|private
label|:
name|QSharedDataPointer
operator|<
name|QFileDialogOptionsPrivate
operator|>
name|d
expr_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_macro
DECL|function|Q_DECLARE_SHARED
name|Q_DECLARE_SHARED
argument_list|(
argument|QFileDialogOptions
argument_list|)
end_macro
begin_decl_stmt
name|class
name|Q_GUI_EXPORT
name|QPlatformFileDialogHelper
range|:
name|public
name|QPlatformDialogHelper
block|{
name|Q_OBJECT
name|public
operator|:
name|virtual
name|bool
name|defaultNameFilterDisables
argument_list|()
specifier|const
operator|=
literal|0
block|;
name|virtual
name|void
name|setDirectory
argument_list|(
specifier|const
name|QUrl
operator|&
name|directory
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|QUrl
name|directory
argument_list|()
specifier|const
operator|=
literal|0
block|;
name|virtual
name|void
name|selectFile
argument_list|(
specifier|const
name|QUrl
operator|&
name|filename
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|QList
operator|<
name|QUrl
operator|>
name|selectedFiles
argument_list|()
specifier|const
operator|=
literal|0
block|;
name|virtual
name|void
name|setFilter
argument_list|()
operator|=
literal|0
block|;
name|virtual
name|void
name|selectNameFilter
argument_list|(
specifier|const
name|QString
operator|&
name|filter
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|QString
name|selectedNameFilter
argument_list|()
specifier|const
operator|=
literal|0
block|;
name|virtual
name|bool
name|isSupportedUrl
argument_list|(
argument|const QUrl&url
argument_list|)
specifier|const
block|;
specifier|const
name|QSharedPointer
operator|<
name|QFileDialogOptions
operator|>
operator|&
name|options
argument_list|()
specifier|const
block|;
name|void
name|setOptions
argument_list|(
specifier|const
name|QSharedPointer
operator|<
name|QFileDialogOptions
operator|>
operator|&
name|options
argument_list|)
block|;
specifier|static
name|QStringList
name|cleanFilterList
argument_list|(
specifier|const
name|QString
operator|&
name|filter
argument_list|)
block|;
specifier|static
specifier|const
name|char
operator|*
name|filterRegExp
block|;
name|Q_SIGNALS
operator|:
name|void
name|fileSelected
argument_list|(
specifier|const
name|QUrl
operator|&
name|file
argument_list|)
block|;
name|void
name|filesSelected
argument_list|(
specifier|const
name|QList
operator|<
name|QUrl
operator|>
operator|&
name|files
argument_list|)
block|;
name|void
name|currentChanged
argument_list|(
specifier|const
name|QUrl
operator|&
name|path
argument_list|)
block|;
name|void
name|directoryEntered
argument_list|(
specifier|const
name|QUrl
operator|&
name|directory
argument_list|)
block|;
name|void
name|filterSelected
argument_list|(
specifier|const
name|QString
operator|&
name|filter
argument_list|)
block|;
name|private
operator|:
name|QSharedPointer
operator|<
name|QFileDialogOptions
operator|>
name|m_options
block|; }
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_GUI_EXPORT
name|QMessageDialogOptions
block|{
name|public
label|:
comment|// Keep in sync with QMessageBox::Icon
enum|enum
name|Icon
block|{
name|NoIcon
block|,
name|Information
block|,
name|Warning
block|,
name|Critical
block|,
name|Question
block|}
enum|;
name|QMessageDialogOptions
argument_list|()
expr_stmt|;
name|QMessageDialogOptions
argument_list|(
specifier|const
name|QMessageDialogOptions
operator|&
name|rhs
argument_list|)
expr_stmt|;
name|QMessageDialogOptions
modifier|&
name|operator
init|=
operator|(
specifier|const
name|QMessageDialogOptions
operator|&
name|rhs
operator|)
decl_stmt|;
operator|~
name|QMessageDialogOptions
argument_list|()
expr_stmt|;
name|void
name|swap
parameter_list|(
name|QMessageDialogOptions
modifier|&
name|other
parameter_list|)
block|{
name|qSwap
argument_list|(
name|d
argument_list|,
name|other
operator|.
name|d
argument_list|)
expr_stmt|;
block|}
name|QString
name|windowTitle
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setWindowTitle
parameter_list|(
specifier|const
name|QString
modifier|&
parameter_list|)
function_decl|;
name|void
name|setIcon
parameter_list|(
name|Icon
name|icon
parameter_list|)
function_decl|;
name|Icon
name|icon
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setText
parameter_list|(
specifier|const
name|QString
modifier|&
name|text
parameter_list|)
function_decl|;
name|QString
name|text
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setInformativeText
parameter_list|(
specifier|const
name|QString
modifier|&
name|text
parameter_list|)
function_decl|;
name|QString
name|informativeText
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setDetailedText
parameter_list|(
specifier|const
name|QString
modifier|&
name|text
parameter_list|)
function_decl|;
name|QString
name|detailedText
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setStandardButtons
argument_list|(
name|QPlatformDialogHelper
operator|::
name|StandardButtons
name|buttons
argument_list|)
decl_stmt|;
name|QPlatformDialogHelper
operator|::
name|StandardButtons
name|standardButtons
argument_list|()
specifier|const
expr_stmt|;
name|private
label|:
name|QSharedDataPointer
operator|<
name|QMessageDialogOptionsPrivate
operator|>
name|d
expr_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_macro
DECL|function|Q_DECLARE_SHARED
name|Q_DECLARE_SHARED
argument_list|(
argument|QMessageDialogOptions
argument_list|)
end_macro
begin_decl_stmt
name|class
name|Q_GUI_EXPORT
name|QPlatformMessageDialogHelper
range|:
name|public
name|QPlatformDialogHelper
block|{
name|Q_OBJECT
name|public
operator|:
specifier|const
name|QSharedPointer
operator|<
name|QMessageDialogOptions
operator|>
operator|&
name|options
argument_list|()
specifier|const
block|;
name|void
name|setOptions
argument_list|(
specifier|const
name|QSharedPointer
operator|<
name|QMessageDialogOptions
operator|>
operator|&
name|options
argument_list|)
block|;
name|Q_SIGNALS
operator|:
name|void
name|clicked
argument_list|(
argument|QPlatformDialogHelper::StandardButton button
argument_list|,
argument|QPlatformDialogHelper::ButtonRole role
argument_list|)
block|;
name|private
operator|:
name|QSharedPointer
operator|<
name|QMessageDialogOptions
operator|>
name|m_options
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
begin_comment
comment|// QPLATFORMDIALOGHELPER_H
end_comment
end_unit
