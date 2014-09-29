begin_unit
begin_comment
comment|/*************************************************************************** ** ** Copyright (C) 2012 Research In Motion ** Contact: http://www.qt-project.org/legal ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia. For licensing terms and ** conditions see http://qt.digia.com/licensing. For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights. These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qqnxfiledialoghelper.h"
end_include
begin_include
include|#
directive|include
file|"qqnxbpseventfilter.h"
end_include
begin_include
include|#
directive|include
file|"qqnxscreen.h"
end_include
begin_include
include|#
directive|include
file|"qqnxintegration.h"
end_include
begin_include
include|#
directive|include
file|<QDebug>
end_include
begin_include
include|#
directive|include
file|<QEventLoop>
end_include
begin_include
include|#
directive|include
file|<QScreen>
end_include
begin_include
include|#
directive|include
file|<QTimer>
end_include
begin_include
include|#
directive|include
file|<QWindow>
end_include
begin_if
if|#
directive|if
name|defined
argument_list|(
name|QQNXFILEDIALOGHELPER_DEBUG
argument_list|)
end_if
begin_define
DECL|macro|qFileDialogHelperDebug
define|#
directive|define
name|qFileDialogHelperDebug
value|qDebug
end_define
begin_else
else|#
directive|else
end_else
begin_define
DECL|macro|qFileDialogHelperDebug
define|#
directive|define
name|qFileDialogHelperDebug
value|QT_NO_QDEBUG_MACRO
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_constructor
DECL|function|QQnxFileDialogHelper
name|QQnxFileDialogHelper
operator|::
name|QQnxFileDialogHelper
parameter_list|(
specifier|const
name|QQnxIntegration
modifier|*
name|integration
parameter_list|)
member_init_list|:
name|QPlatformFileDialogHelper
argument_list|()
member_init_list|,
name|m_integration
argument_list|(
name|integration
argument_list|)
member_init_list|,
name|m_dialog
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|m_acceptMode
argument_list|(
name|QFileDialogOptions
operator|::
name|AcceptOpen
argument_list|)
member_init_list|,
name|m_selectedFilter
argument_list|()
member_init_list|,
name|m_result
argument_list|(
name|QPlatformDialogHelper
operator|::
name|Rejected
argument_list|)
member_init_list|,
name|m_paths
argument_list|()
block|{ }
end_constructor
begin_destructor
DECL|function|~QQnxFileDialogHelper
name|QQnxFileDialogHelper
operator|::
name|~
name|QQnxFileDialogHelper
parameter_list|()
block|{
if|if
condition|(
name|m_dialog
condition|)
name|dialog_destroy
argument_list|(
name|m_dialog
argument_list|)
expr_stmt|;
block|}
end_destructor
begin_function
DECL|function|handleEvent
name|bool
name|QQnxFileDialogHelper
operator|::
name|handleEvent
parameter_list|(
name|bps_event_t
modifier|*
name|event
parameter_list|)
block|{
name|qFileDialogHelperDebug
argument_list|()
operator|<<
name|Q_FUNC_INFO
expr_stmt|;
comment|// Check dialog event response type (OK vs CANCEL)
comment|// CANCEL => index = 0
comment|//     OK => index = 1
name|int
name|index
init|=
name|dialog_event_get_selected_index
argument_list|(
name|event
argument_list|)
decl_stmt|;
name|qFileDialogHelperDebug
argument_list|()
operator|<<
literal|"Index ="
operator|<<
name|index
expr_stmt|;
if|if
condition|(
name|index
operator|==
literal|1
condition|)
block|{
name|m_result
operator|=
name|QPlatformDialogHelper
operator|::
name|Accepted
expr_stmt|;
if|if
condition|(
name|m_acceptMode
operator|==
name|QFileDialogOptions
operator|::
name|AcceptOpen
condition|)
block|{
comment|// File open dialog
comment|// ###TODO Check that this actually gets multiple paths and cleans up properly
name|char
modifier|*
modifier|*
name|filePaths
init|=
literal|0
decl_stmt|;
name|int
name|pathCount
init|=
literal|0
decl_stmt|;
name|int
name|result
init|=
name|dialog_event_get_filebrowse_filepaths
argument_list|(
name|event
argument_list|,
operator|&
name|filePaths
argument_list|,
operator|&
name|pathCount
argument_list|)
decl_stmt|;
if|if
condition|(
name|result
operator|!=
name|BPS_SUCCESS
condition|)
block|{
name|qWarning
argument_list|()
operator|<<
literal|"Could not get paths from native file dialog"
expr_stmt|;
return|return
literal|false
return|;
block|}
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|pathCount
condition|;
operator|++
name|i
control|)
block|{
name|QString
name|path
init|=
name|QFile
operator|::
name|decodeName
argument_list|(
name|filePaths
index|[
name|i
index|]
argument_list|)
decl_stmt|;
name|m_paths
operator|.
name|append
argument_list|(
name|QUrl
operator|::
name|fromLocalFile
argument_list|(
name|path
argument_list|)
argument_list|)
expr_stmt|;
name|qFileDialogHelperDebug
argument_list|()
operator|<<
literal|"path ="
operator|<<
name|path
expr_stmt|;
block|}
name|bps_free
argument_list|(
name|filePaths
argument_list|)
expr_stmt|;
block|}
else|else
block|{
comment|// File save dialog
specifier|const
name|char
modifier|*
name|filePath
init|=
name|dialog_event_get_filesave_filepath
argument_list|(
name|event
argument_list|)
decl_stmt|;
name|QString
name|path
init|=
name|QFile
operator|::
name|decodeName
argument_list|(
name|filePath
argument_list|)
decl_stmt|;
name|qFileDialogHelperDebug
argument_list|()
operator|<<
literal|"path ="
operator|<<
name|path
expr_stmt|;
name|m_paths
operator|.
name|append
argument_list|(
name|QUrl
operator|::
name|fromLocalFile
argument_list|(
name|path
argument_list|)
argument_list|)
expr_stmt|;
block|}
block|}
else|else
block|{
comment|// Cancel
name|m_result
operator|=
name|QPlatformDialogHelper
operator|::
name|Rejected
expr_stmt|;
block|}
name|Q_EMIT
name|dialogClosed
argument_list|()
decl_stmt|;
return|return
literal|true
return|;
block|}
end_function
begin_function
DECL|function|exec
name|void
name|QQnxFileDialogHelper
operator|::
name|exec
parameter_list|()
block|{
name|qFileDialogHelperDebug
argument_list|()
operator|<<
name|Q_FUNC_INFO
expr_stmt|;
comment|// Clear any previous results
name|m_paths
operator|.
name|clear
argument_list|()
expr_stmt|;
name|QEventLoop
name|loop
decl_stmt|;
name|connect
argument_list|(
name|this
argument_list|,
name|SIGNAL
argument_list|(
name|dialogClosed
argument_list|()
argument_list|)
argument_list|,
operator|&
name|loop
argument_list|,
name|SLOT
argument_list|(
name|quit
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|loop
operator|.
name|exec
argument_list|()
expr_stmt|;
if|if
condition|(
name|m_result
operator|==
name|QPlatformDialogHelper
operator|::
name|Accepted
condition|)
name|Q_EMIT
name|accept
argument_list|()
decl_stmt|;
else|else
name|Q_EMIT
name|reject
argument_list|()
decl_stmt|;
block|}
end_function
begin_function
DECL|function|show
name|bool
name|QQnxFileDialogHelper
operator|::
name|show
parameter_list|(
name|Qt
operator|::
name|WindowFlags
name|flags
parameter_list|,
name|Qt
operator|::
name|WindowModality
name|modality
parameter_list|,
name|QWindow
modifier|*
name|parent
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
name|flags
argument_list|)
expr_stmt|;
name|qFileDialogHelperDebug
argument_list|()
operator|<<
name|Q_FUNC_INFO
expr_stmt|;
name|QQnxBpsEventFilter
modifier|*
name|eventFilter
init|=
name|m_integration
operator|->
name|bpsEventFilter
argument_list|()
decl_stmt|;
comment|// We *really* need the bps event filter ;)
if|if
condition|(
operator|!
name|eventFilter
condition|)
return|return
literal|false
return|;
comment|// Native dialogs can only handle application modal use cases so far
if|if
condition|(
name|modality
operator|!=
name|Qt
operator|::
name|ApplicationModal
condition|)
return|return
literal|false
return|;
comment|// Tear down any existing dialog and start again as dialog mode may have changed
if|if
condition|(
name|m_dialog
condition|)
block|{
name|dialog_destroy
argument_list|(
name|m_dialog
argument_list|)
expr_stmt|;
name|m_dialog
operator|=
literal|0
expr_stmt|;
block|}
comment|// Create dialog
specifier|const
name|QSharedPointer
argument_list|<
name|QFileDialogOptions
argument_list|>
modifier|&
name|opts
init|=
name|options
argument_list|()
decl_stmt|;
if|if
condition|(
name|opts
operator|->
name|acceptMode
argument_list|()
operator|==
name|QFileDialogOptions
operator|::
name|AcceptOpen
condition|)
block|{
if|if
condition|(
name|dialog_create_filebrowse
argument_list|(
operator|&
name|m_dialog
argument_list|)
operator|!=
name|BPS_SUCCESS
condition|)
block|{
name|qWarning
argument_list|(
literal|"dialog_create_filebrowse failed"
argument_list|)
expr_stmt|;
return|return
literal|false
return|;
block|}
comment|// Select one or many files?
name|bool
name|multiSelect
init|=
operator|(
name|opts
operator|->
name|fileMode
argument_list|()
operator|==
name|QFileDialogOptions
operator|::
name|ExistingFiles
operator|)
decl_stmt|;
name|dialog_set_filebrowse_multiselect
argument_list|(
name|m_dialog
argument_list|,
name|multiSelect
argument_list|)
expr_stmt|;
comment|// Set the actual list of extensions
if|if
condition|(
operator|!
name|opts
operator|->
name|nameFilters
argument_list|()
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|qFileDialogHelperDebug
argument_list|()
operator|<<
literal|"nameFilters ="
operator|<<
name|opts
operator|->
name|nameFilters
argument_list|()
expr_stmt|;
name|setNameFilter
argument_list|(
name|opts
operator|->
name|nameFilters
argument_list|()
operator|.
name|first
argument_list|()
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|QString
name|defaultNameFilter
init|=
name|QStringLiteral
argument_list|(
literal|"*.*"
argument_list|)
decl_stmt|;
name|setNameFilter
argument_list|(
name|defaultNameFilter
argument_list|)
expr_stmt|;
block|}
block|}
else|else
block|{
if|if
condition|(
name|dialog_create_filesave
argument_list|(
operator|&
name|m_dialog
argument_list|)
operator|!=
name|BPS_SUCCESS
condition|)
block|{
name|qWarning
argument_list|(
literal|"dialog_create_filesave failed"
argument_list|)
expr_stmt|;
return|return
literal|false
return|;
block|}
comment|// Maybe pre-select a filename
if|if
condition|(
operator|!
name|opts
operator|->
name|initiallySelectedFiles
argument_list|()
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|QString
name|fileName
init|=
name|opts
operator|->
name|initiallySelectedFiles
argument_list|()
operator|.
name|first
argument_list|()
operator|.
name|toLocalFile
argument_list|()
decl_stmt|;
name|dialog_set_filesave_filename
argument_list|(
name|m_dialog
argument_list|,
name|QFile
operator|::
name|encodeName
argument_list|(
name|fileName
argument_list|)
operator|.
name|constData
argument_list|()
argument_list|)
expr_stmt|;
block|}
comment|// Add OK and Cancel buttons. We add the buttons in the order "CANCEL" followed by "OK
comment|// such that they have indices matching the buttons on the file open dialog which
comment|// is automatically populated with buttons.
if|if
condition|(
name|dialog_add_button
argument_list|(
name|m_dialog
argument_list|,
name|tr
argument_list|(
literal|"CANCEL"
argument_list|)
operator|.
name|toLocal8Bit
argument_list|()
operator|.
name|constData
argument_list|()
argument_list|,
literal|true
argument_list|,
literal|0
argument_list|,
literal|true
argument_list|)
operator|!=
name|BPS_SUCCESS
condition|)
block|{
name|qWarning
argument_list|(
literal|"dialog_add_button failed"
argument_list|)
expr_stmt|;
return|return
literal|false
return|;
block|}
if|if
condition|(
name|dialog_add_button
argument_list|(
name|m_dialog
argument_list|,
name|tr
argument_list|(
literal|"OK"
argument_list|)
operator|.
name|toLocal8Bit
argument_list|()
operator|.
name|constData
argument_list|()
argument_list|,
literal|true
argument_list|,
literal|0
argument_list|,
literal|true
argument_list|)
operator|!=
name|BPS_SUCCESS
condition|)
block|{
name|qWarning
argument_list|(
literal|"dialog_add_button failed"
argument_list|)
expr_stmt|;
return|return
literal|false
return|;
block|}
block|}
comment|// Cache the accept mode so we know which functions to use to get the results back
name|m_acceptMode
operator|=
name|opts
operator|->
name|acceptMode
argument_list|()
expr_stmt|;
comment|// Set the libscreen window group and common properties
name|QQnxScreen
modifier|*
name|nativeScreen
init|=
name|parent
condition|?
cast|static_cast
argument_list|<
name|QQnxScreen
operator|*
argument_list|>
argument_list|(
name|parent
operator|->
name|screen
argument_list|()
operator|->
name|handle
argument_list|()
argument_list|)
else|:
name|m_integration
operator|->
name|primaryDisplay
argument_list|()
decl_stmt|;
name|Q_ASSERT
argument_list|(
name|nativeScreen
argument_list|)
expr_stmt|;
name|dialog_set_group_id
argument_list|(
name|m_dialog
argument_list|,
name|nativeScreen
operator|->
name|windowGroupName
argument_list|()
argument_list|)
expr_stmt|;
name|dialog_set_title_text
argument_list|(
name|m_dialog
argument_list|,
name|opts
operator|->
name|windowTitle
argument_list|()
operator|.
name|toLocal8Bit
argument_list|()
operator|.
name|constData
argument_list|()
argument_list|)
expr_stmt|;
comment|// Register ourselves for dialog domain events from bps
name|eventFilter
operator|->
name|registerForDialogEvents
argument_list|(
name|this
argument_list|)
expr_stmt|;
comment|// Show the dialog
name|dialog_show
argument_list|(
name|m_dialog
argument_list|)
expr_stmt|;
return|return
literal|true
return|;
block|}
end_function
begin_function
DECL|function|hide
name|void
name|QQnxFileDialogHelper
operator|::
name|hide
parameter_list|()
block|{
name|qFileDialogHelperDebug
argument_list|()
operator|<<
name|Q_FUNC_INFO
expr_stmt|;
if|if
condition|(
operator|!
name|m_dialog
condition|)
return|return;
name|dialog_cancel
argument_list|(
name|m_dialog
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|defaultNameFilterDisables
name|bool
name|QQnxFileDialogHelper
operator|::
name|defaultNameFilterDisables
parameter_list|()
specifier|const
block|{
name|qFileDialogHelperDebug
argument_list|()
operator|<<
name|Q_FUNC_INFO
expr_stmt|;
return|return
literal|false
return|;
block|}
end_function
begin_function
DECL|function|setDirectory
name|void
name|QQnxFileDialogHelper
operator|::
name|setDirectory
parameter_list|(
specifier|const
name|QUrl
modifier|&
name|directory
parameter_list|)
block|{
name|qFileDialogHelperDebug
argument_list|()
operator|<<
name|Q_FUNC_INFO
operator|<<
literal|"directory ="
operator|<<
name|directory
expr_stmt|;
comment|// No native API for setting the directory(!). The best we can do is to
comment|// set it as the file name but even then only with a file save dialog.
if|if
condition|(
name|m_dialog
operator|&&
name|m_acceptMode
operator|==
name|QFileDialogOptions
operator|::
name|AcceptSave
condition|)
name|dialog_set_filesave_filename
argument_list|(
name|m_dialog
argument_list|,
name|QFile
operator|::
name|encodeName
argument_list|(
name|directory
operator|.
name|toLocalFile
argument_list|()
argument_list|)
operator|.
name|constData
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|directory
name|QUrl
name|QQnxFileDialogHelper
operator|::
name|directory
parameter_list|()
specifier|const
block|{
name|qFileDialogHelperDebug
argument_list|()
operator|<<
name|Q_FUNC_INFO
expr_stmt|;
return|return
name|m_paths
operator|.
name|first
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|selectFile
name|void
name|QQnxFileDialogHelper
operator|::
name|selectFile
parameter_list|(
specifier|const
name|QUrl
modifier|&
name|fileName
parameter_list|)
block|{
name|qFileDialogHelperDebug
argument_list|()
operator|<<
name|Q_FUNC_INFO
operator|<<
literal|"filename ="
operator|<<
name|fileName
expr_stmt|;
if|if
condition|(
name|m_dialog
operator|&&
name|m_acceptMode
operator|==
name|QFileDialogOptions
operator|::
name|AcceptSave
condition|)
name|dialog_set_filesave_filename
argument_list|(
name|m_dialog
argument_list|,
name|QFile
operator|::
name|encodeName
argument_list|(
name|fileName
operator|.
name|toLocalFile
argument_list|()
argument_list|)
operator|.
name|constData
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|selectedFiles
name|QList
argument_list|<
name|QUrl
argument_list|>
name|QQnxFileDialogHelper
operator|::
name|selectedFiles
parameter_list|()
specifier|const
block|{
name|qFileDialogHelperDebug
argument_list|()
operator|<<
name|Q_FUNC_INFO
expr_stmt|;
return|return
name|m_paths
return|;
block|}
end_function
begin_function
DECL|function|setFilter
name|void
name|QQnxFileDialogHelper
operator|::
name|setFilter
parameter_list|()
block|{
comment|// No native api to support setting a filter from QDir::Filters
name|qFileDialogHelperDebug
argument_list|()
operator|<<
name|Q_FUNC_INFO
expr_stmt|;
block|}
end_function
begin_function
DECL|function|selectNameFilter
name|void
name|QQnxFileDialogHelper
operator|::
name|selectNameFilter
parameter_list|(
specifier|const
name|QString
modifier|&
name|filter
parameter_list|)
block|{
name|qFileDialogHelperDebug
argument_list|()
operator|<<
name|Q_FUNC_INFO
operator|<<
literal|"filter ="
operator|<<
name|filter
expr_stmt|;
name|setNameFilter
argument_list|(
name|filter
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|selectedNameFilter
name|QString
name|QQnxFileDialogHelper
operator|::
name|selectedNameFilter
parameter_list|()
specifier|const
block|{
comment|// For now there is no way for the user to change the selected filter
comment|// so this just reflects what the developer has set programmatically.
name|qFileDialogHelperDebug
argument_list|()
operator|<<
name|Q_FUNC_INFO
expr_stmt|;
return|return
name|m_selectedFilter
return|;
block|}
end_function
begin_function
DECL|function|setNameFilter
name|void
name|QQnxFileDialogHelper
operator|::
name|setNameFilter
parameter_list|(
specifier|const
name|QString
modifier|&
name|filter
parameter_list|)
block|{
name|qFileDialogHelperDebug
argument_list|()
operator|<<
name|Q_FUNC_INFO
operator|<<
literal|"filter ="
operator|<<
name|filter
expr_stmt|;
name|setNameFilters
argument_list|(
name|QPlatformFileDialogHelper
operator|::
name|cleanFilterList
argument_list|(
name|filter
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|setNameFilters
name|void
name|QQnxFileDialogHelper
operator|::
name|setNameFilters
parameter_list|(
specifier|const
name|QStringList
modifier|&
name|filters
parameter_list|)
block|{
name|qFileDialogHelperDebug
argument_list|()
operator|<<
name|Q_FUNC_INFO
operator|<<
literal|"filters ="
operator|<<
name|filters
expr_stmt|;
name|Q_ASSERT
argument_list|(
operator|!
name|filters
operator|.
name|isEmpty
argument_list|()
argument_list|)
expr_stmt|;
name|char
modifier|*
modifier|*
name|globs
init|=
operator|new
name|char
operator|*
index|[
name|filters
operator|.
name|size
argument_list|()
index|]
decl_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|filters
operator|.
name|size
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
name|QByteArray
name|glob
init|=
name|filters
operator|.
name|at
argument_list|(
name|i
argument_list|)
operator|.
name|toLocal8Bit
argument_list|()
decl_stmt|;
name|globs
index|[
name|i
index|]
operator|=
operator|new
name|char
index|[
name|glob
operator|.
name|length
argument_list|()
index|]
expr_stmt|;
name|strcpy
argument_list|(
name|globs
index|[
name|i
index|]
argument_list|,
name|glob
operator|.
name|constData
argument_list|()
argument_list|)
expr_stmt|;
block|}
comment|// Set the filters
name|dialog_set_filebrowse_filter
argument_list|(
name|m_dialog
argument_list|,
cast|const_cast
argument_list|<
specifier|const
name|char
operator|*
operator|*
argument_list|>
argument_list|(
name|globs
argument_list|)
argument_list|,
name|filters
operator|.
name|size
argument_list|()
argument_list|)
expr_stmt|;
name|m_selectedFilter
operator|=
name|filters
operator|.
name|first
argument_list|()
expr_stmt|;
comment|// Cleanup
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|filters
operator|.
name|size
argument_list|()
condition|;
operator|++
name|i
control|)
operator|delete
index|[]
name|globs
index|[
name|i
index|]
expr_stmt|;
operator|delete
index|[]
name|globs
expr_stmt|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
