begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of The Qt Company Ltd nor the names of its **     contributors may be used to endorse or promote products derived **     from this software without specific prior written permission. ** ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtWidgets>
end_include
begin_include
include|#
directive|include
file|<QtNetwork>
end_include
begin_include
include|#
directive|include
file|<QUrl>
end_include
begin_include
include|#
directive|include
file|"httpwindow.h"
end_include
begin_include
include|#
directive|include
file|"ui_authenticationdialog.h"
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_SSL
end_ifndef
begin_decl_stmt
DECL|variable|defaultUrl
specifier|static
specifier|const
name|char
name|defaultUrl
index|[]
init|=
literal|"https://www.qt.io/"
decl_stmt|;
end_decl_stmt
begin_else
else|#
directive|else
end_else
begin_decl_stmt
DECL|variable|defaultUrl
specifier|static
specifier|const
name|char
name|defaultUrl
index|[]
init|=
literal|"http://www.qt.io/"
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_decl_stmt
DECL|variable|defaultFileName
specifier|static
specifier|const
name|char
name|defaultFileName
index|[]
init|=
literal|"index.html"
decl_stmt|;
end_decl_stmt
begin_constructor
DECL|function|ProgressDialog
name|ProgressDialog
operator|::
name|ProgressDialog
parameter_list|(
specifier|const
name|QUrl
modifier|&
name|url
parameter_list|,
name|QWidget
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QProgressDialog
argument_list|(
name|parent
argument_list|)
block|{
name|setWindowTitle
argument_list|(
name|tr
argument_list|(
literal|"Download Progress"
argument_list|)
argument_list|)
expr_stmt|;
name|setWindowFlags
argument_list|(
name|windowFlags
argument_list|()
operator|&
operator|~
name|Qt
operator|::
name|WindowContextHelpButtonHint
argument_list|)
expr_stmt|;
name|setLabelText
argument_list|(
name|tr
argument_list|(
literal|"Downloading %1."
argument_list|)
operator|.
name|arg
argument_list|(
name|url
operator|.
name|toDisplayString
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|setMinimum
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|setValue
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|setMinimumDuration
argument_list|(
literal|0
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_function
DECL|function|networkReplyProgress
name|void
name|ProgressDialog
operator|::
name|networkReplyProgress
parameter_list|(
name|qint64
name|bytesRead
parameter_list|,
name|qint64
name|totalBytes
parameter_list|)
block|{
name|setMaximum
argument_list|(
name|totalBytes
argument_list|)
expr_stmt|;
name|setValue
argument_list|(
name|bytesRead
argument_list|)
expr_stmt|;
block|}
end_function
begin_constructor
DECL|function|HttpWindow
name|HttpWindow
operator|::
name|HttpWindow
parameter_list|(
name|QWidget
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QDialog
argument_list|(
name|parent
argument_list|)
member_init_list|,
name|statusLabel
argument_list|(
operator|new
name|QLabel
argument_list|(
name|tr
argument_list|(
literal|"Please enter the URL of a file you want to download.\n\n"
argument_list|)
argument_list|,
name|this
argument_list|)
argument_list|)
member_init_list|,
name|urlLineEdit
argument_list|(
operator|new
name|QLineEdit
argument_list|(
name|defaultUrl
argument_list|)
argument_list|)
member_init_list|,
name|downloadButton
argument_list|(
operator|new
name|QPushButton
argument_list|(
name|tr
argument_list|(
literal|"Download"
argument_list|)
argument_list|)
argument_list|)
member_init_list|,
name|launchCheckBox
argument_list|(
operator|new
name|QCheckBox
argument_list|(
literal|"Launch file"
argument_list|)
argument_list|)
member_init_list|,
name|defaultFileLineEdit
argument_list|(
operator|new
name|QLineEdit
argument_list|(
name|defaultFileName
argument_list|)
argument_list|)
member_init_list|,
name|downloadDirectoryLineEdit
argument_list|(
operator|new
name|QLineEdit
argument_list|)
member_init_list|,
name|reply
argument_list|(
name|Q_NULLPTR
argument_list|)
member_init_list|,
name|file
argument_list|(
name|Q_NULLPTR
argument_list|)
member_init_list|,
name|httpRequestAborted
argument_list|(
literal|false
argument_list|)
block|{
name|setWindowFlags
argument_list|(
name|windowFlags
argument_list|()
operator|&
operator|~
name|Qt
operator|::
name|WindowContextHelpButtonHint
argument_list|)
expr_stmt|;
name|setWindowTitle
argument_list|(
name|tr
argument_list|(
literal|"HTTP"
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
operator|&
name|qnam
argument_list|,
operator|&
name|QNetworkAccessManager
operator|::
name|authenticationRequired
argument_list|,
name|this
argument_list|,
operator|&
name|HttpWindow
operator|::
name|slotAuthenticationRequired
argument_list|)
expr_stmt|;
ifndef|#
directive|ifndef
name|QT_NO_SSL
name|connect
argument_list|(
operator|&
name|qnam
argument_list|,
operator|&
name|QNetworkAccessManager
operator|::
name|sslErrors
argument_list|,
name|this
argument_list|,
operator|&
name|HttpWindow
operator|::
name|sslErrors
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|QFormLayout
modifier|*
name|formLayout
init|=
operator|new
name|QFormLayout
decl_stmt|;
name|urlLineEdit
operator|->
name|setClearButtonEnabled
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|urlLineEdit
argument_list|,
operator|&
name|QLineEdit
operator|::
name|textChanged
argument_list|,
name|this
argument_list|,
operator|&
name|HttpWindow
operator|::
name|enableDownloadButton
argument_list|)
expr_stmt|;
name|formLayout
operator|->
name|addRow
argument_list|(
name|tr
argument_list|(
literal|"&URL:"
argument_list|)
argument_list|,
name|urlLineEdit
argument_list|)
expr_stmt|;
name|QString
name|downloadDirectory
init|=
name|QStandardPaths
operator|::
name|writableLocation
argument_list|(
name|QStandardPaths
operator|::
name|TempLocation
argument_list|)
decl_stmt|;
if|if
condition|(
name|downloadDirectory
operator|.
name|isEmpty
argument_list|()
operator|||
operator|!
name|QFileInfo
argument_list|(
name|downloadDirectory
argument_list|)
operator|.
name|isDir
argument_list|()
condition|)
name|downloadDirectory
operator|=
name|QDir
operator|::
name|currentPath
argument_list|()
expr_stmt|;
name|downloadDirectoryLineEdit
operator|->
name|setText
argument_list|(
name|QDir
operator|::
name|toNativeSeparators
argument_list|(
name|downloadDirectory
argument_list|)
argument_list|)
expr_stmt|;
name|formLayout
operator|->
name|addRow
argument_list|(
name|tr
argument_list|(
literal|"&Download directory:"
argument_list|)
argument_list|,
name|downloadDirectoryLineEdit
argument_list|)
expr_stmt|;
name|formLayout
operator|->
name|addRow
argument_list|(
name|tr
argument_list|(
literal|"Default&file:"
argument_list|)
argument_list|,
name|defaultFileLineEdit
argument_list|)
expr_stmt|;
name|launchCheckBox
operator|->
name|setChecked
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|formLayout
operator|->
name|addRow
argument_list|(
name|launchCheckBox
argument_list|)
expr_stmt|;
name|QVBoxLayout
modifier|*
name|mainLayout
init|=
operator|new
name|QVBoxLayout
argument_list|(
name|this
argument_list|)
decl_stmt|;
name|mainLayout
operator|->
name|addLayout
argument_list|(
name|formLayout
argument_list|)
expr_stmt|;
name|mainLayout
operator|->
name|addItem
argument_list|(
operator|new
name|QSpacerItem
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
name|QSizePolicy
operator|::
name|Ignored
argument_list|,
name|QSizePolicy
operator|::
name|MinimumExpanding
argument_list|)
argument_list|)
expr_stmt|;
name|statusLabel
operator|->
name|setWordWrap
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|mainLayout
operator|->
name|addWidget
argument_list|(
name|statusLabel
argument_list|)
expr_stmt|;
name|downloadButton
operator|->
name|setDefault
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|downloadButton
argument_list|,
operator|&
name|QAbstractButton
operator|::
name|clicked
argument_list|,
name|this
argument_list|,
operator|&
name|HttpWindow
operator|::
name|downloadFile
argument_list|)
expr_stmt|;
name|QPushButton
modifier|*
name|quitButton
init|=
operator|new
name|QPushButton
argument_list|(
name|tr
argument_list|(
literal|"Quit"
argument_list|)
argument_list|)
decl_stmt|;
name|quitButton
operator|->
name|setAutoDefault
argument_list|(
literal|false
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|quitButton
argument_list|,
operator|&
name|QAbstractButton
operator|::
name|clicked
argument_list|,
name|this
argument_list|,
operator|&
name|QWidget
operator|::
name|close
argument_list|)
expr_stmt|;
name|QDialogButtonBox
modifier|*
name|buttonBox
init|=
operator|new
name|QDialogButtonBox
decl_stmt|;
name|buttonBox
operator|->
name|addButton
argument_list|(
name|downloadButton
argument_list|,
name|QDialogButtonBox
operator|::
name|ActionRole
argument_list|)
expr_stmt|;
name|buttonBox
operator|->
name|addButton
argument_list|(
name|quitButton
argument_list|,
name|QDialogButtonBox
operator|::
name|RejectRole
argument_list|)
expr_stmt|;
name|mainLayout
operator|->
name|addWidget
argument_list|(
name|buttonBox
argument_list|)
expr_stmt|;
name|urlLineEdit
operator|->
name|setFocus
argument_list|()
expr_stmt|;
block|}
end_constructor
begin_function
DECL|function|startRequest
name|void
name|HttpWindow
operator|::
name|startRequest
parameter_list|(
specifier|const
name|QUrl
modifier|&
name|requestedUrl
parameter_list|)
block|{
name|url
operator|=
name|requestedUrl
expr_stmt|;
name|httpRequestAborted
operator|=
literal|false
expr_stmt|;
name|reply
operator|=
name|qnam
operator|.
name|get
argument_list|(
name|QNetworkRequest
argument_list|(
name|url
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|reply
argument_list|,
operator|&
name|QNetworkReply
operator|::
name|finished
argument_list|,
name|this
argument_list|,
operator|&
name|HttpWindow
operator|::
name|httpFinished
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|reply
argument_list|,
operator|&
name|QIODevice
operator|::
name|readyRead
argument_list|,
name|this
argument_list|,
operator|&
name|HttpWindow
operator|::
name|httpReadyRead
argument_list|)
expr_stmt|;
name|ProgressDialog
modifier|*
name|progressDialog
init|=
operator|new
name|ProgressDialog
argument_list|(
name|url
argument_list|,
name|this
argument_list|)
decl_stmt|;
name|progressDialog
operator|->
name|setAttribute
argument_list|(
name|Qt
operator|::
name|WA_DeleteOnClose
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|progressDialog
argument_list|,
operator|&
name|QProgressDialog
operator|::
name|canceled
argument_list|,
name|this
argument_list|,
operator|&
name|HttpWindow
operator|::
name|cancelDownload
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|reply
argument_list|,
operator|&
name|QNetworkReply
operator|::
name|downloadProgress
argument_list|,
name|progressDialog
argument_list|,
operator|&
name|ProgressDialog
operator|::
name|networkReplyProgress
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|reply
argument_list|,
operator|&
name|QNetworkReply
operator|::
name|finished
argument_list|,
name|progressDialog
argument_list|,
operator|&
name|ProgressDialog
operator|::
name|hide
argument_list|)
expr_stmt|;
name|progressDialog
operator|->
name|show
argument_list|()
expr_stmt|;
name|statusLabel
operator|->
name|setText
argument_list|(
name|tr
argument_list|(
literal|"Downloading %1..."
argument_list|)
operator|.
name|arg
argument_list|(
name|url
operator|.
name|toString
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|downloadFile
name|void
name|HttpWindow
operator|::
name|downloadFile
parameter_list|()
block|{
specifier|const
name|QString
name|urlSpec
init|=
name|urlLineEdit
operator|->
name|text
argument_list|()
operator|.
name|trimmed
argument_list|()
decl_stmt|;
if|if
condition|(
name|urlSpec
operator|.
name|isEmpty
argument_list|()
condition|)
return|return;
specifier|const
name|QUrl
name|newUrl
init|=
name|QUrl
operator|::
name|fromUserInput
argument_list|(
name|urlSpec
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|newUrl
operator|.
name|isValid
argument_list|()
condition|)
block|{
name|QMessageBox
operator|::
name|information
argument_list|(
name|this
argument_list|,
name|tr
argument_list|(
literal|"Error"
argument_list|)
argument_list|,
name|tr
argument_list|(
literal|"Invalid URL: %1: %2"
argument_list|)
operator|.
name|arg
argument_list|(
name|urlSpec
argument_list|,
name|newUrl
operator|.
name|errorString
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
return|return;
block|}
name|QString
name|fileName
init|=
name|newUrl
operator|.
name|fileName
argument_list|()
decl_stmt|;
if|if
condition|(
name|fileName
operator|.
name|isEmpty
argument_list|()
condition|)
name|fileName
operator|=
name|defaultFileLineEdit
operator|->
name|text
argument_list|()
operator|.
name|trimmed
argument_list|()
expr_stmt|;
if|if
condition|(
name|fileName
operator|.
name|isEmpty
argument_list|()
condition|)
name|fileName
operator|=
name|defaultFileName
expr_stmt|;
name|QString
name|downloadDirectory
init|=
name|QDir
operator|::
name|cleanPath
argument_list|(
name|downloadDirectoryLineEdit
operator|->
name|text
argument_list|()
operator|.
name|trimmed
argument_list|()
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|downloadDirectory
operator|.
name|isEmpty
argument_list|()
operator|&&
name|QFileInfo
argument_list|(
name|downloadDirectory
argument_list|)
operator|.
name|isDir
argument_list|()
condition|)
name|fileName
operator|.
name|prepend
argument_list|(
name|downloadDirectory
operator|+
literal|'/'
argument_list|)
expr_stmt|;
if|if
condition|(
name|QFile
operator|::
name|exists
argument_list|(
name|fileName
argument_list|)
condition|)
block|{
if|if
condition|(
name|QMessageBox
operator|::
name|question
argument_list|(
name|this
argument_list|,
name|tr
argument_list|(
literal|"Overwrite Existing File"
argument_list|)
argument_list|,
name|tr
argument_list|(
literal|"There already exists a file called %1 in "
literal|"the current directory. Overwrite?"
argument_list|)
operator|.
name|arg
argument_list|(
name|fileName
argument_list|)
argument_list|,
name|QMessageBox
operator|::
name|Yes
operator||
name|QMessageBox
operator|::
name|No
argument_list|,
name|QMessageBox
operator|::
name|No
argument_list|)
operator|==
name|QMessageBox
operator|::
name|No
condition|)
return|return;
name|QFile
operator|::
name|remove
argument_list|(
name|fileName
argument_list|)
expr_stmt|;
block|}
name|file
operator|=
name|openFileForWrite
argument_list|(
name|fileName
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|file
condition|)
return|return;
name|downloadButton
operator|->
name|setEnabled
argument_list|(
literal|false
argument_list|)
expr_stmt|;
comment|// schedule the request
name|startRequest
argument_list|(
name|newUrl
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|openFileForWrite
name|QFile
modifier|*
name|HttpWindow
operator|::
name|openFileForWrite
parameter_list|(
specifier|const
name|QString
modifier|&
name|fileName
parameter_list|)
block|{
name|QScopedPointer
argument_list|<
name|QFile
argument_list|>
name|file
argument_list|(
operator|new
name|QFile
argument_list|(
name|fileName
argument_list|)
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|file
operator|->
name|open
argument_list|(
name|QIODevice
operator|::
name|WriteOnly
argument_list|)
condition|)
block|{
name|QMessageBox
operator|::
name|information
argument_list|(
name|this
argument_list|,
name|tr
argument_list|(
literal|"Error"
argument_list|)
argument_list|,
name|tr
argument_list|(
literal|"Unable to save the file %1: %2."
argument_list|)
operator|.
name|arg
argument_list|(
name|QDir
operator|::
name|toNativeSeparators
argument_list|(
name|fileName
argument_list|)
argument_list|,
name|file
operator|->
name|errorString
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|Q_NULLPTR
return|;
block|}
return|return
name|file
operator|.
name|take
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|cancelDownload
name|void
name|HttpWindow
operator|::
name|cancelDownload
parameter_list|()
block|{
name|statusLabel
operator|->
name|setText
argument_list|(
name|tr
argument_list|(
literal|"Download canceled."
argument_list|)
argument_list|)
expr_stmt|;
name|httpRequestAborted
operator|=
literal|true
expr_stmt|;
name|reply
operator|->
name|abort
argument_list|()
expr_stmt|;
name|downloadButton
operator|->
name|setEnabled
argument_list|(
literal|true
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|httpFinished
name|void
name|HttpWindow
operator|::
name|httpFinished
parameter_list|()
block|{
name|QFileInfo
name|fi
decl_stmt|;
if|if
condition|(
name|file
condition|)
block|{
name|fi
operator|.
name|setFile
argument_list|(
name|file
operator|->
name|fileName
argument_list|()
argument_list|)
expr_stmt|;
name|file
operator|->
name|close
argument_list|()
expr_stmt|;
operator|delete
name|file
expr_stmt|;
name|file
operator|=
name|Q_NULLPTR
expr_stmt|;
block|}
if|if
condition|(
name|httpRequestAborted
condition|)
block|{
name|reply
operator|->
name|deleteLater
argument_list|()
expr_stmt|;
name|reply
operator|=
name|Q_NULLPTR
expr_stmt|;
return|return;
block|}
if|if
condition|(
name|reply
operator|->
name|error
argument_list|()
condition|)
block|{
name|QFile
operator|::
name|remove
argument_list|(
name|fi
operator|.
name|absoluteFilePath
argument_list|()
argument_list|)
expr_stmt|;
name|statusLabel
operator|->
name|setText
argument_list|(
name|tr
argument_list|(
literal|"Download failed:\n%1."
argument_list|)
operator|.
name|arg
argument_list|(
name|reply
operator|->
name|errorString
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|downloadButton
operator|->
name|setEnabled
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|reply
operator|->
name|deleteLater
argument_list|()
expr_stmt|;
name|reply
operator|=
name|Q_NULLPTR
expr_stmt|;
return|return;
block|}
specifier|const
name|QVariant
name|redirectionTarget
init|=
name|reply
operator|->
name|attribute
argument_list|(
name|QNetworkRequest
operator|::
name|RedirectionTargetAttribute
argument_list|)
decl_stmt|;
name|reply
operator|->
name|deleteLater
argument_list|()
expr_stmt|;
name|reply
operator|=
name|Q_NULLPTR
expr_stmt|;
if|if
condition|(
operator|!
name|redirectionTarget
operator|.
name|isNull
argument_list|()
condition|)
block|{
specifier|const
name|QUrl
name|redirectedUrl
init|=
name|url
operator|.
name|resolved
argument_list|(
name|redirectionTarget
operator|.
name|toUrl
argument_list|()
argument_list|)
decl_stmt|;
if|if
condition|(
name|QMessageBox
operator|::
name|question
argument_list|(
name|this
argument_list|,
name|tr
argument_list|(
literal|"Redirect"
argument_list|)
argument_list|,
name|tr
argument_list|(
literal|"Redirect to %1 ?"
argument_list|)
operator|.
name|arg
argument_list|(
name|redirectedUrl
operator|.
name|toString
argument_list|()
argument_list|)
argument_list|,
name|QMessageBox
operator|::
name|Yes
operator||
name|QMessageBox
operator|::
name|No
argument_list|)
operator|==
name|QMessageBox
operator|::
name|No
condition|)
block|{
name|downloadButton
operator|->
name|setEnabled
argument_list|(
literal|true
argument_list|)
expr_stmt|;
return|return;
block|}
name|file
operator|=
name|openFileForWrite
argument_list|(
name|fi
operator|.
name|absoluteFilePath
argument_list|()
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|file
condition|)
block|{
name|downloadButton
operator|->
name|setEnabled
argument_list|(
literal|true
argument_list|)
expr_stmt|;
return|return;
block|}
name|startRequest
argument_list|(
name|redirectedUrl
argument_list|)
expr_stmt|;
return|return;
block|}
name|statusLabel
operator|->
name|setText
argument_list|(
name|tr
argument_list|(
literal|"Downloaded %1 bytes to %2\nin\n%3"
argument_list|)
operator|.
name|arg
argument_list|(
name|fi
operator|.
name|size
argument_list|()
argument_list|)
operator|.
name|arg
argument_list|(
name|fi
operator|.
name|fileName
argument_list|()
argument_list|,
name|QDir
operator|::
name|toNativeSeparators
argument_list|(
name|fi
operator|.
name|absolutePath
argument_list|()
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|launchCheckBox
operator|->
name|isChecked
argument_list|()
condition|)
name|QDesktopServices
operator|::
name|openUrl
argument_list|(
name|QUrl
operator|::
name|fromLocalFile
argument_list|(
name|fi
operator|.
name|absoluteFilePath
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|downloadButton
operator|->
name|setEnabled
argument_list|(
literal|true
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|httpReadyRead
name|void
name|HttpWindow
operator|::
name|httpReadyRead
parameter_list|()
block|{
comment|// this slot gets called every time the QNetworkReply has new data.
comment|// We read all of its new data and write it into the file.
comment|// That way we use less RAM than when reading it at the finished()
comment|// signal of the QNetworkReply
if|if
condition|(
name|file
condition|)
name|file
operator|->
name|write
argument_list|(
name|reply
operator|->
name|readAll
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|enableDownloadButton
name|void
name|HttpWindow
operator|::
name|enableDownloadButton
parameter_list|()
block|{
name|downloadButton
operator|->
name|setEnabled
argument_list|(
operator|!
name|urlLineEdit
operator|->
name|text
argument_list|()
operator|.
name|isEmpty
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|slotAuthenticationRequired
name|void
name|HttpWindow
operator|::
name|slotAuthenticationRequired
parameter_list|(
name|QNetworkReply
modifier|*
parameter_list|,
name|QAuthenticator
modifier|*
name|authenticator
parameter_list|)
block|{
name|QDialog
name|authenticationDialog
decl_stmt|;
name|Ui
operator|::
name|Dialog
name|ui
decl_stmt|;
name|ui
operator|.
name|setupUi
argument_list|(
operator|&
name|authenticationDialog
argument_list|)
expr_stmt|;
name|authenticationDialog
operator|.
name|adjustSize
argument_list|()
expr_stmt|;
name|ui
operator|.
name|siteDescription
operator|->
name|setText
argument_list|(
name|tr
argument_list|(
literal|"%1 at %2"
argument_list|)
operator|.
name|arg
argument_list|(
name|authenticator
operator|->
name|realm
argument_list|()
argument_list|,
name|url
operator|.
name|host
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
comment|// Did the URL have information? Fill the UI
comment|// This is only relevant if the URL-supplied credentials were wrong
name|ui
operator|.
name|userEdit
operator|->
name|setText
argument_list|(
name|url
operator|.
name|userName
argument_list|()
argument_list|)
expr_stmt|;
name|ui
operator|.
name|passwordEdit
operator|->
name|setText
argument_list|(
name|url
operator|.
name|password
argument_list|()
argument_list|)
expr_stmt|;
if|if
condition|(
name|authenticationDialog
operator|.
name|exec
argument_list|()
operator|==
name|QDialog
operator|::
name|Accepted
condition|)
block|{
name|authenticator
operator|->
name|setUser
argument_list|(
name|ui
operator|.
name|userEdit
operator|->
name|text
argument_list|()
argument_list|)
expr_stmt|;
name|authenticator
operator|->
name|setPassword
argument_list|(
name|ui
operator|.
name|passwordEdit
operator|->
name|text
argument_list|()
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_SSL
end_ifndef
begin_function
DECL|function|sslErrors
name|void
name|HttpWindow
operator|::
name|sslErrors
parameter_list|(
name|QNetworkReply
modifier|*
parameter_list|,
specifier|const
name|QList
argument_list|<
name|QSslError
argument_list|>
modifier|&
name|errors
parameter_list|)
block|{
name|QString
name|errorString
decl_stmt|;
foreach|foreach
control|(
specifier|const
name|QSslError
modifier|&
name|error
decl|,
name|errors
control|)
block|{
if|if
condition|(
operator|!
name|errorString
operator|.
name|isEmpty
argument_list|()
condition|)
name|errorString
operator|+=
literal|'\n'
expr_stmt|;
name|errorString
operator|+=
name|error
operator|.
name|errorString
argument_list|()
expr_stmt|;
block|}
if|if
condition|(
name|QMessageBox
operator|::
name|warning
argument_list|(
name|this
argument_list|,
name|tr
argument_list|(
literal|"SSL Errors"
argument_list|)
argument_list|,
name|tr
argument_list|(
literal|"One or more SSL errors has occurred:\n%1"
argument_list|)
operator|.
name|arg
argument_list|(
name|errorString
argument_list|)
argument_list|,
name|QMessageBox
operator|::
name|Ignore
operator||
name|QMessageBox
operator|::
name|Abort
argument_list|)
operator|==
name|QMessageBox
operator|::
name|Ignore
condition|)
block|{
name|reply
operator|->
name|ignoreSslErrors
argument_list|()
expr_stmt|;
block|}
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
end_unit
