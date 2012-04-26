begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
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
comment|// This file is not part of the Qt API.  It exists purely as an
end_comment
begin_comment
comment|// implementation detail.  This header file may change from version to
end_comment
begin_comment
comment|// version without notice, or even be removed.
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|// We mean it.
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
file|<QtGui/QRgb>
end_include
begin_decl_stmt
name|QT_BEGIN_HEADER
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
block|{
name|SnapToDefaultButton
block|}
block|;     enum
name|DialogCode
block|{
name|Rejected
block|,
name|Accepted
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
name|platformNativeDialogModalHelp
argument_list|()
operator|=
literal|0
block|;
name|virtual
name|void
name|_q_platformRunNativeAppModalPanel
argument_list|()
operator|=
literal|0
block|;
name|virtual
name|void
name|deleteNativeDialog_sys
argument_list|()
operator|=
literal|0
block|;
name|virtual
name|bool
name|show_sys
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
name|hide_sys
argument_list|()
operator|=
literal|0
block|;
name|virtual
name|DialogCode
name|dialogResultCode_sys
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
name|Q_SIGNALS
operator|:
name|void
name|launchNativeAppModalPanel
argument_list|()
block|;
name|void
name|accept
argument_list|()
block|;
name|void
name|reject
argument_list|()
block|;
name|protected
name|Q_SLOTS
operator|:
name|void
name|emitLaunchNativeAppModalPanel
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
name|setCurrentColor_sys
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
name|currentColor_sys
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
name|setCurrentFont_sys
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
name|currentFont_sys
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
name|QString
name|initialDirectory
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setInitialDirectory
parameter_list|(
specifier|const
name|QString
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
name|QStringList
name|initiallySelectedFiles
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setInitiallySelectedFiles
parameter_list|(
specifier|const
name|QStringList
modifier|&
parameter_list|)
function_decl|;
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
name|setDirectory_sys
argument_list|(
specifier|const
name|QString
operator|&
name|directory
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|QString
name|directory_sys
argument_list|()
specifier|const
operator|=
literal|0
block|;
name|virtual
name|void
name|selectFile_sys
argument_list|(
specifier|const
name|QString
operator|&
name|filename
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|QStringList
name|selectedFiles_sys
argument_list|()
specifier|const
operator|=
literal|0
block|;
name|virtual
name|void
name|setFilter_sys
argument_list|()
operator|=
literal|0
block|;
name|virtual
name|void
name|selectNameFilter_sys
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
name|selectedNameFilter_sys
argument_list|()
specifier|const
operator|=
literal|0
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
name|Q_SIGNALS
operator|:
name|void
name|fileSelected
argument_list|(
specifier|const
name|QString
operator|&
name|file
argument_list|)
block|;
name|void
name|filesSelected
argument_list|(
specifier|const
name|QStringList
operator|&
name|files
argument_list|)
block|;
name|void
name|currentChanged
argument_list|(
specifier|const
name|QString
operator|&
name|path
argument_list|)
block|;
name|void
name|directoryEntered
argument_list|(
specifier|const
name|QString
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
begin_expr_stmt
name|QT_END_NAMESPACE
name|QT_END_HEADER
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QPLATFORMDIALOGHELPER_H
end_comment
end_unit
