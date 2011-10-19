begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of Nokia Corporation and its Subsidiary(-ies) nor **     the names of its contributors may be used to endorse or promote **     products derived from this software without specific prior written **     permission. ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** $QT_END_LICENSE$ ** ****************************************************************************/
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
file|"ftpwindow.h"
end_include
begin_constructor
DECL|function|FtpWindow
name|FtpWindow
operator|::
name|FtpWindow
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
name|ftp
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|networkSession
argument_list|(
literal|0
argument_list|)
block|{
name|ftpServerLabel
operator|=
operator|new
name|QLabel
argument_list|(
name|tr
argument_list|(
literal|"Ftp&server:"
argument_list|)
argument_list|)
expr_stmt|;
name|ftpServerLineEdit
operator|=
operator|new
name|QLineEdit
argument_list|(
literal|"ftp.qt.nokia.com"
argument_list|)
expr_stmt|;
name|ftpServerLabel
operator|->
name|setBuddy
argument_list|(
name|ftpServerLineEdit
argument_list|)
expr_stmt|;
name|statusLabel
operator|=
operator|new
name|QLabel
argument_list|(
name|tr
argument_list|(
literal|"Please enter the name of an FTP server."
argument_list|)
argument_list|)
expr_stmt|;
name|fileList
operator|=
operator|new
name|QTreeWidget
expr_stmt|;
name|fileList
operator|->
name|setEnabled
argument_list|(
literal|false
argument_list|)
expr_stmt|;
name|fileList
operator|->
name|setRootIsDecorated
argument_list|(
literal|false
argument_list|)
expr_stmt|;
name|fileList
operator|->
name|setHeaderLabels
argument_list|(
name|QStringList
argument_list|()
operator|<<
name|tr
argument_list|(
literal|"Name"
argument_list|)
operator|<<
name|tr
argument_list|(
literal|"Size"
argument_list|)
operator|<<
name|tr
argument_list|(
literal|"Owner"
argument_list|)
operator|<<
name|tr
argument_list|(
literal|"Group"
argument_list|)
operator|<<
name|tr
argument_list|(
literal|"Time"
argument_list|)
argument_list|)
expr_stmt|;
name|fileList
operator|->
name|header
argument_list|()
operator|->
name|setStretchLastSection
argument_list|(
literal|false
argument_list|)
expr_stmt|;
name|connectButton
operator|=
operator|new
name|QPushButton
argument_list|(
name|tr
argument_list|(
literal|"Connect"
argument_list|)
argument_list|)
expr_stmt|;
name|connectButton
operator|->
name|setDefault
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|cdToParentButton
operator|=
operator|new
name|QPushButton
expr_stmt|;
name|cdToParentButton
operator|->
name|setIcon
argument_list|(
name|QPixmap
argument_list|(
literal|":/images/cdtoparent.png"
argument_list|)
argument_list|)
expr_stmt|;
name|cdToParentButton
operator|->
name|setEnabled
argument_list|(
literal|false
argument_list|)
expr_stmt|;
name|downloadButton
operator|=
operator|new
name|QPushButton
argument_list|(
name|tr
argument_list|(
literal|"Download"
argument_list|)
argument_list|)
expr_stmt|;
name|downloadButton
operator|->
name|setEnabled
argument_list|(
literal|false
argument_list|)
expr_stmt|;
name|quitButton
operator|=
operator|new
name|QPushButton
argument_list|(
name|tr
argument_list|(
literal|"Quit"
argument_list|)
argument_list|)
expr_stmt|;
name|buttonBox
operator|=
operator|new
name|QDialogButtonBox
expr_stmt|;
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
name|progressDialog
operator|=
operator|new
name|QProgressDialog
argument_list|(
name|this
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|fileList
argument_list|,
name|SIGNAL
argument_list|(
name|itemActivated
argument_list|(
name|QTreeWidgetItem
operator|*
argument_list|,
name|int
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|processItem
argument_list|(
name|QTreeWidgetItem
operator|*
argument_list|,
name|int
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|fileList
argument_list|,
name|SIGNAL
argument_list|(
name|currentItemChanged
argument_list|(
name|QTreeWidgetItem
operator|*
argument_list|,
name|QTreeWidgetItem
operator|*
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|enableDownloadButton
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|progressDialog
argument_list|,
name|SIGNAL
argument_list|(
name|canceled
argument_list|()
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|cancelDownload
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|connectButton
argument_list|,
name|SIGNAL
argument_list|(
name|clicked
argument_list|()
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|connectOrDisconnect
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|cdToParentButton
argument_list|,
name|SIGNAL
argument_list|(
name|clicked
argument_list|()
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|cdToParent
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|downloadButton
argument_list|,
name|SIGNAL
argument_list|(
name|clicked
argument_list|()
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|downloadFile
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|quitButton
argument_list|,
name|SIGNAL
argument_list|(
name|clicked
argument_list|()
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|close
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|QHBoxLayout
modifier|*
name|topLayout
init|=
operator|new
name|QHBoxLayout
decl_stmt|;
name|topLayout
operator|->
name|addWidget
argument_list|(
name|ftpServerLabel
argument_list|)
expr_stmt|;
name|topLayout
operator|->
name|addWidget
argument_list|(
name|ftpServerLineEdit
argument_list|)
expr_stmt|;
name|topLayout
operator|->
name|addWidget
argument_list|(
name|cdToParentButton
argument_list|)
expr_stmt|;
name|topLayout
operator|->
name|addWidget
argument_list|(
name|connectButton
argument_list|)
expr_stmt|;
name|QVBoxLayout
modifier|*
name|mainLayout
init|=
operator|new
name|QVBoxLayout
decl_stmt|;
name|mainLayout
operator|->
name|addLayout
argument_list|(
name|topLayout
argument_list|)
expr_stmt|;
name|mainLayout
operator|->
name|addWidget
argument_list|(
name|fileList
argument_list|)
expr_stmt|;
name|mainLayout
operator|->
name|addWidget
argument_list|(
name|statusLabel
argument_list|)
expr_stmt|;
name|mainLayout
operator|->
name|addWidget
argument_list|(
name|buttonBox
argument_list|)
expr_stmt|;
name|setLayout
argument_list|(
name|mainLayout
argument_list|)
expr_stmt|;
name|setWindowTitle
argument_list|(
name|tr
argument_list|(
literal|"FTP"
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_function
DECL|function|sizeHint
name|QSize
name|FtpWindow
operator|::
name|sizeHint
parameter_list|()
specifier|const
block|{
return|return
name|QSize
argument_list|(
literal|500
argument_list|,
literal|300
argument_list|)
return|;
block|}
end_function
begin_comment
comment|//![0]
end_comment
begin_function
DECL|function|connectOrDisconnect
name|void
name|FtpWindow
operator|::
name|connectOrDisconnect
parameter_list|()
block|{
if|if
condition|(
name|ftp
condition|)
block|{
name|ftp
operator|->
name|abort
argument_list|()
expr_stmt|;
name|ftp
operator|->
name|deleteLater
argument_list|()
expr_stmt|;
name|ftp
operator|=
literal|0
expr_stmt|;
comment|//![0]
name|fileList
operator|->
name|setEnabled
argument_list|(
literal|false
argument_list|)
expr_stmt|;
name|cdToParentButton
operator|->
name|setEnabled
argument_list|(
literal|false
argument_list|)
expr_stmt|;
name|downloadButton
operator|->
name|setEnabled
argument_list|(
literal|false
argument_list|)
expr_stmt|;
name|connectButton
operator|->
name|setEnabled
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|connectButton
operator|->
name|setText
argument_list|(
name|tr
argument_list|(
literal|"Connect"
argument_list|)
argument_list|)
expr_stmt|;
ifndef|#
directive|ifndef
name|QT_NO_CURSOR
name|setCursor
argument_list|(
name|Qt
operator|::
name|ArrowCursor
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|statusLabel
operator|->
name|setText
argument_list|(
name|tr
argument_list|(
literal|"Please enter the name of an FTP server."
argument_list|)
argument_list|)
expr_stmt|;
return|return;
block|}
ifndef|#
directive|ifndef
name|QT_NO_CURSOR
name|setCursor
argument_list|(
name|Qt
operator|::
name|WaitCursor
argument_list|)
expr_stmt|;
endif|#
directive|endif
if|if
condition|(
operator|!
name|networkSession
operator|||
operator|!
name|networkSession
operator|->
name|isOpen
argument_list|()
condition|)
block|{
if|if
condition|(
name|manager
operator|.
name|capabilities
argument_list|()
operator|&
name|QNetworkConfigurationManager
operator|::
name|NetworkSessionRequired
condition|)
block|{
if|if
condition|(
operator|!
name|networkSession
condition|)
block|{
comment|// Get saved network configuration
name|QSettings
name|settings
argument_list|(
name|QSettings
operator|::
name|UserScope
argument_list|,
name|QLatin1String
argument_list|(
literal|"Trolltech"
argument_list|)
argument_list|)
decl_stmt|;
name|settings
operator|.
name|beginGroup
argument_list|(
name|QLatin1String
argument_list|(
literal|"QtNetwork"
argument_list|)
argument_list|)
expr_stmt|;
specifier|const
name|QString
name|id
init|=
name|settings
operator|.
name|value
argument_list|(
name|QLatin1String
argument_list|(
literal|"DefaultNetworkConfiguration"
argument_list|)
argument_list|)
operator|.
name|toString
argument_list|()
decl_stmt|;
name|settings
operator|.
name|endGroup
argument_list|()
expr_stmt|;
comment|// If the saved network configuration is not currently discovered use the system default
name|QNetworkConfiguration
name|config
init|=
name|manager
operator|.
name|configurationFromIdentifier
argument_list|(
name|id
argument_list|)
decl_stmt|;
if|if
condition|(
operator|(
name|config
operator|.
name|state
argument_list|()
operator|&
name|QNetworkConfiguration
operator|::
name|Discovered
operator|)
operator|!=
name|QNetworkConfiguration
operator|::
name|Discovered
condition|)
block|{
name|config
operator|=
name|manager
operator|.
name|defaultConfiguration
argument_list|()
expr_stmt|;
block|}
name|networkSession
operator|=
operator|new
name|QNetworkSession
argument_list|(
name|config
argument_list|,
name|this
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|networkSession
argument_list|,
name|SIGNAL
argument_list|(
name|opened
argument_list|()
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|connectToFtp
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|networkSession
argument_list|,
name|SIGNAL
argument_list|(
name|error
argument_list|(
name|QNetworkSession
operator|::
name|SessionError
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|enableConnectButton
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
block|}
name|connectButton
operator|->
name|setEnabled
argument_list|(
literal|false
argument_list|)
expr_stmt|;
name|statusLabel
operator|->
name|setText
argument_list|(
name|tr
argument_list|(
literal|"Opening network session."
argument_list|)
argument_list|)
expr_stmt|;
name|networkSession
operator|->
name|open
argument_list|()
expr_stmt|;
return|return;
block|}
block|}
name|connectToFtp
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|connectToFtp
name|void
name|FtpWindow
operator|::
name|connectToFtp
parameter_list|()
block|{
comment|//![1]
name|ftp
operator|=
operator|new
name|QFtp
argument_list|(
name|this
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|ftp
argument_list|,
name|SIGNAL
argument_list|(
name|commandFinished
argument_list|(
name|int
argument_list|,
name|bool
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|ftpCommandFinished
argument_list|(
name|int
argument_list|,
name|bool
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|ftp
argument_list|,
name|SIGNAL
argument_list|(
name|listInfo
argument_list|(
name|QUrlInfo
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|addToList
argument_list|(
name|QUrlInfo
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|ftp
argument_list|,
name|SIGNAL
argument_list|(
name|dataTransferProgress
argument_list|(
name|qint64
argument_list|,
name|qint64
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|updateDataTransferProgress
argument_list|(
name|qint64
argument_list|,
name|qint64
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|fileList
operator|->
name|clear
argument_list|()
expr_stmt|;
name|currentPath
operator|.
name|clear
argument_list|()
expr_stmt|;
name|isDirectory
operator|.
name|clear
argument_list|()
expr_stmt|;
comment|//![1]
comment|//![2]
name|QUrl
name|url
argument_list|(
name|ftpServerLineEdit
operator|->
name|text
argument_list|()
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|url
operator|.
name|isValid
argument_list|()
operator|||
name|url
operator|.
name|scheme
argument_list|()
operator|.
name|toLower
argument_list|()
operator|!=
name|QLatin1String
argument_list|(
literal|"ftp"
argument_list|)
condition|)
block|{
name|ftp
operator|->
name|connectToHost
argument_list|(
name|ftpServerLineEdit
operator|->
name|text
argument_list|()
argument_list|,
literal|21
argument_list|)
expr_stmt|;
name|ftp
operator|->
name|login
argument_list|()
expr_stmt|;
block|}
else|else
block|{
name|ftp
operator|->
name|connectToHost
argument_list|(
name|url
operator|.
name|host
argument_list|()
argument_list|,
name|url
operator|.
name|port
argument_list|(
literal|21
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|url
operator|.
name|userName
argument_list|()
operator|.
name|isEmpty
argument_list|()
condition|)
name|ftp
operator|->
name|login
argument_list|(
name|QUrl
operator|::
name|fromPercentEncoding
argument_list|(
name|url
operator|.
name|userName
argument_list|()
operator|.
name|toLatin1
argument_list|()
argument_list|)
argument_list|,
name|url
operator|.
name|password
argument_list|()
argument_list|)
expr_stmt|;
else|else
name|ftp
operator|->
name|login
argument_list|()
expr_stmt|;
if|if
condition|(
operator|!
name|url
operator|.
name|path
argument_list|()
operator|.
name|isEmpty
argument_list|()
condition|)
name|ftp
operator|->
name|cd
argument_list|(
name|url
operator|.
name|path
argument_list|()
argument_list|)
expr_stmt|;
block|}
comment|//![2]
name|fileList
operator|->
name|setEnabled
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|connectButton
operator|->
name|setEnabled
argument_list|(
literal|false
argument_list|)
expr_stmt|;
name|connectButton
operator|->
name|setText
argument_list|(
name|tr
argument_list|(
literal|"Disconnect"
argument_list|)
argument_list|)
expr_stmt|;
name|statusLabel
operator|->
name|setText
argument_list|(
name|tr
argument_list|(
literal|"Connecting to FTP server %1..."
argument_list|)
operator|.
name|arg
argument_list|(
name|ftpServerLineEdit
operator|->
name|text
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|//![3]
end_comment
begin_function
DECL|function|downloadFile
name|void
name|FtpWindow
operator|::
name|downloadFile
parameter_list|()
block|{
name|QString
name|fileName
init|=
name|fileList
operator|->
name|currentItem
argument_list|()
operator|->
name|text
argument_list|(
literal|0
argument_list|)
decl_stmt|;
comment|//![3]
comment|//
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
name|QMessageBox
operator|::
name|information
argument_list|(
name|this
argument_list|,
name|tr
argument_list|(
literal|"FTP"
argument_list|)
argument_list|,
name|tr
argument_list|(
literal|"There already exists a file called %1 in "
literal|"the current directory."
argument_list|)
operator|.
name|arg
argument_list|(
name|fileName
argument_list|)
argument_list|)
expr_stmt|;
return|return;
block|}
comment|//![4]
name|file
operator|=
operator|new
name|QFile
argument_list|(
name|fileName
argument_list|)
expr_stmt|;
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
literal|"FTP"
argument_list|)
argument_list|,
name|tr
argument_list|(
literal|"Unable to save the file %1: %2."
argument_list|)
operator|.
name|arg
argument_list|(
name|fileName
argument_list|)
operator|.
name|arg
argument_list|(
name|file
operator|->
name|errorString
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
operator|delete
name|file
expr_stmt|;
return|return;
block|}
name|ftp
operator|->
name|get
argument_list|(
name|fileList
operator|->
name|currentItem
argument_list|()
operator|->
name|text
argument_list|(
literal|0
argument_list|)
argument_list|,
name|file
argument_list|)
expr_stmt|;
name|progressDialog
operator|->
name|setLabelText
argument_list|(
name|tr
argument_list|(
literal|"Downloading %1..."
argument_list|)
operator|.
name|arg
argument_list|(
name|fileName
argument_list|)
argument_list|)
expr_stmt|;
name|downloadButton
operator|->
name|setEnabled
argument_list|(
literal|false
argument_list|)
expr_stmt|;
name|progressDialog
operator|->
name|exec
argument_list|()
expr_stmt|;
block|}
end_function
begin_comment
comment|//![4]
end_comment
begin_comment
comment|//![5]
end_comment
begin_function
DECL|function|cancelDownload
name|void
name|FtpWindow
operator|::
name|cancelDownload
parameter_list|()
block|{
name|ftp
operator|->
name|abort
argument_list|()
expr_stmt|;
if|if
condition|(
name|file
operator|->
name|exists
argument_list|()
condition|)
block|{
name|file
operator|->
name|close
argument_list|()
expr_stmt|;
name|file
operator|->
name|remove
argument_list|()
expr_stmt|;
block|}
operator|delete
name|file
expr_stmt|;
block|}
end_function
begin_comment
comment|//![5]
end_comment
begin_comment
comment|//![6]
end_comment
begin_function
DECL|function|ftpCommandFinished
name|void
name|FtpWindow
operator|::
name|ftpCommandFinished
parameter_list|(
name|int
parameter_list|,
name|bool
name|error
parameter_list|)
block|{
ifndef|#
directive|ifndef
name|QT_NO_CURSOR
name|setCursor
argument_list|(
name|Qt
operator|::
name|ArrowCursor
argument_list|)
expr_stmt|;
endif|#
directive|endif
if|if
condition|(
name|ftp
operator|->
name|currentCommand
argument_list|()
operator|==
name|QFtp
operator|::
name|ConnectToHost
condition|)
block|{
if|if
condition|(
name|error
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
literal|"FTP"
argument_list|)
argument_list|,
name|tr
argument_list|(
literal|"Unable to connect to the FTP server "
literal|"at %1. Please check that the host "
literal|"name is correct."
argument_list|)
operator|.
name|arg
argument_list|(
name|ftpServerLineEdit
operator|->
name|text
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|connectOrDisconnect
argument_list|()
expr_stmt|;
return|return;
block|}
name|statusLabel
operator|->
name|setText
argument_list|(
name|tr
argument_list|(
literal|"Logged onto %1."
argument_list|)
operator|.
name|arg
argument_list|(
name|ftpServerLineEdit
operator|->
name|text
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|fileList
operator|->
name|setFocus
argument_list|()
expr_stmt|;
name|downloadButton
operator|->
name|setDefault
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|connectButton
operator|->
name|setEnabled
argument_list|(
literal|true
argument_list|)
expr_stmt|;
return|return;
block|}
comment|//![6]
comment|//![7]
if|if
condition|(
name|ftp
operator|->
name|currentCommand
argument_list|()
operator|==
name|QFtp
operator|::
name|Login
condition|)
name|ftp
operator|->
name|list
argument_list|()
expr_stmt|;
comment|//![7]
comment|//![8]
if|if
condition|(
name|ftp
operator|->
name|currentCommand
argument_list|()
operator|==
name|QFtp
operator|::
name|Get
condition|)
block|{
if|if
condition|(
name|error
condition|)
block|{
name|statusLabel
operator|->
name|setText
argument_list|(
name|tr
argument_list|(
literal|"Canceled download of %1."
argument_list|)
operator|.
name|arg
argument_list|(
name|file
operator|->
name|fileName
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|file
operator|->
name|close
argument_list|()
expr_stmt|;
name|file
operator|->
name|remove
argument_list|()
expr_stmt|;
block|}
else|else
block|{
name|statusLabel
operator|->
name|setText
argument_list|(
name|tr
argument_list|(
literal|"Downloaded %1 to current directory."
argument_list|)
operator|.
name|arg
argument_list|(
name|file
operator|->
name|fileName
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|file
operator|->
name|close
argument_list|()
expr_stmt|;
block|}
operator|delete
name|file
expr_stmt|;
name|enableDownloadButton
argument_list|()
expr_stmt|;
name|progressDialog
operator|->
name|hide
argument_list|()
expr_stmt|;
comment|//![8]
comment|//![9]
block|}
elseif|else
if|if
condition|(
name|ftp
operator|->
name|currentCommand
argument_list|()
operator|==
name|QFtp
operator|::
name|List
condition|)
block|{
if|if
condition|(
name|isDirectory
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|fileList
operator|->
name|addTopLevelItem
argument_list|(
operator|new
name|QTreeWidgetItem
argument_list|(
name|QStringList
argument_list|()
operator|<<
name|tr
argument_list|(
literal|"<empty>"
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|fileList
operator|->
name|setEnabled
argument_list|(
literal|false
argument_list|)
expr_stmt|;
block|}
block|}
comment|//![9]
block|}
end_function
begin_comment
comment|//![10]
end_comment
begin_function
DECL|function|addToList
name|void
name|FtpWindow
operator|::
name|addToList
parameter_list|(
specifier|const
name|QUrlInfo
modifier|&
name|urlInfo
parameter_list|)
block|{
name|QTreeWidgetItem
modifier|*
name|item
init|=
operator|new
name|QTreeWidgetItem
decl_stmt|;
name|item
operator|->
name|setText
argument_list|(
literal|0
argument_list|,
name|urlInfo
operator|.
name|name
argument_list|()
argument_list|)
expr_stmt|;
name|item
operator|->
name|setText
argument_list|(
literal|1
argument_list|,
name|QString
operator|::
name|number
argument_list|(
name|urlInfo
operator|.
name|size
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|item
operator|->
name|setText
argument_list|(
literal|2
argument_list|,
name|urlInfo
operator|.
name|owner
argument_list|()
argument_list|)
expr_stmt|;
name|item
operator|->
name|setText
argument_list|(
literal|3
argument_list|,
name|urlInfo
operator|.
name|group
argument_list|()
argument_list|)
expr_stmt|;
name|item
operator|->
name|setText
argument_list|(
literal|4
argument_list|,
name|urlInfo
operator|.
name|lastModified
argument_list|()
operator|.
name|toString
argument_list|(
literal|"MMM dd yyyy"
argument_list|)
argument_list|)
expr_stmt|;
name|QPixmap
name|pixmap
argument_list|(
name|urlInfo
operator|.
name|isDir
argument_list|()
condition|?
literal|":/images/dir.png"
else|:
literal|":/images/file.png"
argument_list|)
decl_stmt|;
name|item
operator|->
name|setIcon
argument_list|(
literal|0
argument_list|,
name|pixmap
argument_list|)
expr_stmt|;
name|isDirectory
index|[
name|urlInfo
operator|.
name|name
argument_list|()
index|]
operator|=
name|urlInfo
operator|.
name|isDir
argument_list|()
expr_stmt|;
name|fileList
operator|->
name|addTopLevelItem
argument_list|(
name|item
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|fileList
operator|->
name|currentItem
argument_list|()
condition|)
block|{
name|fileList
operator|->
name|setCurrentItem
argument_list|(
name|fileList
operator|->
name|topLevelItem
argument_list|(
literal|0
argument_list|)
argument_list|)
expr_stmt|;
name|fileList
operator|->
name|setEnabled
argument_list|(
literal|true
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_comment
comment|//![10]
end_comment
begin_comment
comment|//![11]
end_comment
begin_function
DECL|function|processItem
name|void
name|FtpWindow
operator|::
name|processItem
parameter_list|(
name|QTreeWidgetItem
modifier|*
name|item
parameter_list|,
name|int
comment|/*column*/
parameter_list|)
block|{
name|QString
name|name
init|=
name|item
operator|->
name|text
argument_list|(
literal|0
argument_list|)
decl_stmt|;
if|if
condition|(
name|isDirectory
operator|.
name|value
argument_list|(
name|name
argument_list|)
condition|)
block|{
name|fileList
operator|->
name|clear
argument_list|()
expr_stmt|;
name|isDirectory
operator|.
name|clear
argument_list|()
expr_stmt|;
name|currentPath
operator|+=
literal|'/'
expr_stmt|;
name|currentPath
operator|+=
name|name
expr_stmt|;
name|ftp
operator|->
name|cd
argument_list|(
name|name
argument_list|)
expr_stmt|;
name|ftp
operator|->
name|list
argument_list|()
expr_stmt|;
name|cdToParentButton
operator|->
name|setEnabled
argument_list|(
literal|true
argument_list|)
expr_stmt|;
ifndef|#
directive|ifndef
name|QT_NO_CURSOR
name|setCursor
argument_list|(
name|Qt
operator|::
name|WaitCursor
argument_list|)
expr_stmt|;
endif|#
directive|endif
return|return;
block|}
block|}
end_function
begin_comment
comment|//![11]
end_comment
begin_comment
comment|//![12]
end_comment
begin_function
DECL|function|cdToParent
name|void
name|FtpWindow
operator|::
name|cdToParent
parameter_list|()
block|{
ifndef|#
directive|ifndef
name|QT_NO_CURSOR
name|setCursor
argument_list|(
name|Qt
operator|::
name|WaitCursor
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|fileList
operator|->
name|clear
argument_list|()
expr_stmt|;
name|isDirectory
operator|.
name|clear
argument_list|()
expr_stmt|;
name|currentPath
operator|=
name|currentPath
operator|.
name|left
argument_list|(
name|currentPath
operator|.
name|lastIndexOf
argument_list|(
literal|'/'
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|currentPath
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|cdToParentButton
operator|->
name|setEnabled
argument_list|(
literal|false
argument_list|)
expr_stmt|;
name|ftp
operator|->
name|cd
argument_list|(
literal|"/"
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|ftp
operator|->
name|cd
argument_list|(
name|currentPath
argument_list|)
expr_stmt|;
block|}
name|ftp
operator|->
name|list
argument_list|()
expr_stmt|;
block|}
end_function
begin_comment
comment|//![12]
end_comment
begin_comment
comment|//![13]
end_comment
begin_function
DECL|function|updateDataTransferProgress
name|void
name|FtpWindow
operator|::
name|updateDataTransferProgress
parameter_list|(
name|qint64
name|readBytes
parameter_list|,
name|qint64
name|totalBytes
parameter_list|)
block|{
name|progressDialog
operator|->
name|setMaximum
argument_list|(
name|totalBytes
argument_list|)
expr_stmt|;
name|progressDialog
operator|->
name|setValue
argument_list|(
name|readBytes
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|//![13]
end_comment
begin_comment
comment|//![14]
end_comment
begin_function
DECL|function|enableDownloadButton
name|void
name|FtpWindow
operator|::
name|enableDownloadButton
parameter_list|()
block|{
name|QTreeWidgetItem
modifier|*
name|current
init|=
name|fileList
operator|->
name|currentItem
argument_list|()
decl_stmt|;
if|if
condition|(
name|current
condition|)
block|{
name|QString
name|currentFile
init|=
name|current
operator|->
name|text
argument_list|(
literal|0
argument_list|)
decl_stmt|;
name|downloadButton
operator|->
name|setEnabled
argument_list|(
operator|!
name|isDirectory
operator|.
name|value
argument_list|(
name|currentFile
argument_list|)
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|downloadButton
operator|->
name|setEnabled
argument_list|(
literal|false
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_comment
comment|//![14]
end_comment
begin_function
DECL|function|enableConnectButton
name|void
name|FtpWindow
operator|::
name|enableConnectButton
parameter_list|()
block|{
comment|// Save the used configuration
name|QNetworkConfiguration
name|config
init|=
name|networkSession
operator|->
name|configuration
argument_list|()
decl_stmt|;
name|QString
name|id
decl_stmt|;
if|if
condition|(
name|config
operator|.
name|type
argument_list|()
operator|==
name|QNetworkConfiguration
operator|::
name|UserChoice
condition|)
name|id
operator|=
name|networkSession
operator|->
name|sessionProperty
argument_list|(
name|QLatin1String
argument_list|(
literal|"UserChoiceConfiguration"
argument_list|)
argument_list|)
operator|.
name|toString
argument_list|()
expr_stmt|;
else|else
name|id
operator|=
name|config
operator|.
name|identifier
argument_list|()
expr_stmt|;
name|QSettings
name|settings
argument_list|(
name|QSettings
operator|::
name|UserScope
argument_list|,
name|QLatin1String
argument_list|(
literal|"Trolltech"
argument_list|)
argument_list|)
decl_stmt|;
name|settings
operator|.
name|beginGroup
argument_list|(
name|QLatin1String
argument_list|(
literal|"QtNetwork"
argument_list|)
argument_list|)
expr_stmt|;
name|settings
operator|.
name|setValue
argument_list|(
name|QLatin1String
argument_list|(
literal|"DefaultNetworkConfiguration"
argument_list|)
argument_list|,
name|id
argument_list|)
expr_stmt|;
name|settings
operator|.
name|endGroup
argument_list|()
expr_stmt|;
name|connectButton
operator|->
name|setEnabled
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|statusLabel
operator|->
name|setText
argument_list|(
name|tr
argument_list|(
literal|"Please enter the name of an FTP server."
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
end_unit
