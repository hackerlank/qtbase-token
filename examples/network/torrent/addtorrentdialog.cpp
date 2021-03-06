begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** BSD License Usage ** Alternatively, you may use this file under the terms of the BSD license ** as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of The Qt Company Ltd nor the names of its **     contributors may be used to endorse or promote products derived **     from this software without specific prior written permission. ** ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"addtorrentdialog.h"
end_include
begin_include
include|#
directive|include
file|"metainfo.h"
end_include
begin_include
include|#
directive|include
file|<QFile>
end_include
begin_include
include|#
directive|include
file|<QFileDialog>
end_include
begin_include
include|#
directive|include
file|<QLineEdit>
end_include
begin_include
include|#
directive|include
file|<QMetaObject>
end_include
begin_function
DECL|function|stringNumber
specifier|static
name|QString
name|stringNumber
parameter_list|(
name|qint64
name|number
parameter_list|)
block|{
if|if
condition|(
name|number
operator|>
operator|(
literal|1024
operator|*
literal|1024
operator|*
literal|1024
operator|)
condition|)
return|return
name|QString
operator|::
name|asprintf
argument_list|(
literal|"%.2fGB"
argument_list|,
name|number
operator|/
operator|(
literal|1024.0
operator|*
literal|1024.0
operator|*
literal|1024.0
operator|)
argument_list|)
return|;
elseif|else
if|if
condition|(
name|number
operator|>
operator|(
literal|1024
operator|*
literal|1024
operator|)
condition|)
return|return
name|QString
operator|::
name|asprintf
argument_list|(
literal|"%.2fMB"
argument_list|,
name|number
operator|/
operator|(
literal|1024.0
operator|*
literal|1024.0
operator|)
argument_list|)
return|;
elseif|else
if|if
condition|(
name|number
operator|>
operator|(
literal|1024
operator|)
condition|)
return|return
name|QString
operator|::
name|asprintf
argument_list|(
literal|"%.2fKB"
argument_list|,
name|number
operator|/
operator|(
literal|1024.0
operator|)
argument_list|)
return|;
else|else
return|return
name|QString
operator|::
name|asprintf
argument_list|(
literal|"%d bytes"
argument_list|,
name|int
argument_list|(
name|number
argument_list|)
argument_list|)
return|;
block|}
end_function
begin_constructor
DECL|function|AddTorrentDialog
name|AddTorrentDialog
operator|::
name|AddTorrentDialog
parameter_list|(
name|QWidget
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QDialog
argument_list|(
name|parent
argument_list|,
name|Qt
operator|::
name|Sheet
argument_list|)
block|{
name|ui
operator|.
name|setupUi
argument_list|(
name|this
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|ui
operator|.
name|browseTorrents
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
name|selectTorrent
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|ui
operator|.
name|browseDestination
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
name|selectDestination
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|ui
operator|.
name|torrentFile
argument_list|,
name|SIGNAL
argument_list|(
name|textChanged
argument_list|(
name|QString
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|setTorrent
argument_list|(
name|QString
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|ui
operator|.
name|destinationFolder
operator|->
name|setText
argument_list|(
name|destinationDirectory
operator|=
name|QDir
operator|::
name|current
argument_list|()
operator|.
name|path
argument_list|()
argument_list|)
expr_stmt|;
name|ui
operator|.
name|torrentFile
operator|->
name|setFocus
argument_list|()
expr_stmt|;
block|}
end_constructor
begin_function
DECL|function|selectTorrent
name|void
name|AddTorrentDialog
operator|::
name|selectTorrent
parameter_list|()
block|{
name|QString
name|fileName
init|=
name|QFileDialog
operator|::
name|getOpenFileName
argument_list|(
name|this
argument_list|,
name|tr
argument_list|(
literal|"Choose a torrent file"
argument_list|)
argument_list|,
name|lastDirectory
argument_list|,
name|tr
argument_list|(
literal|"Torrents (*.torrent);; All files (*.*)"
argument_list|)
argument_list|)
decl_stmt|;
if|if
condition|(
name|fileName
operator|.
name|isEmpty
argument_list|()
condition|)
return|return;
name|lastDirectory
operator|=
name|QFileInfo
argument_list|(
name|fileName
argument_list|)
operator|.
name|absolutePath
argument_list|()
expr_stmt|;
name|setTorrent
argument_list|(
name|fileName
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|selectDestination
name|void
name|AddTorrentDialog
operator|::
name|selectDestination
parameter_list|()
block|{
name|QString
name|dir
init|=
name|QFileDialog
operator|::
name|getExistingDirectory
argument_list|(
name|this
argument_list|,
name|tr
argument_list|(
literal|"Choose a destination directory"
argument_list|)
argument_list|,
name|lastDestinationDirectory
argument_list|)
decl_stmt|;
if|if
condition|(
name|dir
operator|.
name|isEmpty
argument_list|()
condition|)
return|return;
name|lastDestinationDirectory
operator|=
name|destinationDirectory
operator|=
name|dir
expr_stmt|;
name|ui
operator|.
name|destinationFolder
operator|->
name|setText
argument_list|(
name|destinationDirectory
argument_list|)
expr_stmt|;
name|enableOkButton
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|enableOkButton
name|void
name|AddTorrentDialog
operator|::
name|enableOkButton
parameter_list|()
block|{
name|ui
operator|.
name|okButton
operator|->
name|setEnabled
argument_list|(
operator|!
name|ui
operator|.
name|destinationFolder
operator|->
name|text
argument_list|()
operator|.
name|isEmpty
argument_list|()
operator|&&
operator|!
name|ui
operator|.
name|torrentFile
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
DECL|function|setTorrent
name|void
name|AddTorrentDialog
operator|::
name|setTorrent
parameter_list|(
specifier|const
name|QString
modifier|&
name|torrentFile
parameter_list|)
block|{
if|if
condition|(
name|torrentFile
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|enableOkButton
argument_list|()
expr_stmt|;
return|return;
block|}
name|ui
operator|.
name|torrentFile
operator|->
name|setText
argument_list|(
name|torrentFile
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|torrentFile
operator|.
name|isEmpty
argument_list|()
condition|)
name|lastDirectory
operator|=
name|QFileInfo
argument_list|(
name|torrentFile
argument_list|)
operator|.
name|absolutePath
argument_list|()
expr_stmt|;
if|if
condition|(
name|lastDestinationDirectory
operator|.
name|isEmpty
argument_list|()
condition|)
name|lastDestinationDirectory
operator|=
name|lastDirectory
expr_stmt|;
name|MetaInfo
name|metaInfo
decl_stmt|;
name|QFile
name|torrent
argument_list|(
name|torrentFile
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|torrent
operator|.
name|open
argument_list|(
name|QFile
operator|::
name|ReadOnly
argument_list|)
operator|||
operator|!
name|metaInfo
operator|.
name|parse
argument_list|(
name|torrent
operator|.
name|readAll
argument_list|()
argument_list|)
condition|)
block|{
name|enableOkButton
argument_list|()
expr_stmt|;
return|return;
block|}
name|ui
operator|.
name|torrentFile
operator|->
name|setText
argument_list|(
name|torrentFile
argument_list|)
expr_stmt|;
name|ui
operator|.
name|announceUrl
operator|->
name|setText
argument_list|(
name|metaInfo
operator|.
name|announceUrl
argument_list|()
argument_list|)
expr_stmt|;
if|if
condition|(
name|metaInfo
operator|.
name|comment
argument_list|()
operator|.
name|isEmpty
argument_list|()
condition|)
name|ui
operator|.
name|commentLabel
operator|->
name|setText
argument_list|(
literal|"<unknown>"
argument_list|)
expr_stmt|;
else|else
name|ui
operator|.
name|commentLabel
operator|->
name|setText
argument_list|(
name|metaInfo
operator|.
name|comment
argument_list|()
argument_list|)
expr_stmt|;
if|if
condition|(
name|metaInfo
operator|.
name|createdBy
argument_list|()
operator|.
name|isEmpty
argument_list|()
condition|)
name|ui
operator|.
name|creatorLabel
operator|->
name|setText
argument_list|(
literal|"<unknown>"
argument_list|)
expr_stmt|;
else|else
name|ui
operator|.
name|creatorLabel
operator|->
name|setText
argument_list|(
name|metaInfo
operator|.
name|createdBy
argument_list|()
argument_list|)
expr_stmt|;
name|ui
operator|.
name|sizeLabel
operator|->
name|setText
argument_list|(
name|stringNumber
argument_list|(
name|metaInfo
operator|.
name|totalSize
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|metaInfo
operator|.
name|fileForm
argument_list|()
operator|==
name|MetaInfo
operator|::
name|SingleFileForm
condition|)
block|{
name|ui
operator|.
name|torrentContents
operator|->
name|setHtml
argument_list|(
name|metaInfo
operator|.
name|singleFile
argument_list|()
operator|.
name|name
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|QString
name|html
decl_stmt|;
foreach|foreach
control|(
name|MetaInfoMultiFile
name|file
decl|,
name|metaInfo
operator|.
name|multiFiles
argument_list|()
control|)
block|{
name|QString
name|name
init|=
name|metaInfo
operator|.
name|name
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
name|name
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|html
operator|+=
name|name
expr_stmt|;
if|if
condition|(
operator|!
name|name
operator|.
name|endsWith
argument_list|(
literal|'/'
argument_list|)
condition|)
name|html
operator|+=
literal|'/'
expr_stmt|;
block|}
name|html
operator|+=
name|file
operator|.
name|path
operator|+
literal|"<br>"
expr_stmt|;
block|}
name|ui
operator|.
name|torrentContents
operator|->
name|setHtml
argument_list|(
name|html
argument_list|)
expr_stmt|;
block|}
name|QFileInfo
name|info
argument_list|(
name|torrentFile
argument_list|)
decl_stmt|;
name|ui
operator|.
name|destinationFolder
operator|->
name|setText
argument_list|(
name|info
operator|.
name|absolutePath
argument_list|()
argument_list|)
expr_stmt|;
name|enableOkButton
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|torrentFileName
name|QString
name|AddTorrentDialog
operator|::
name|torrentFileName
parameter_list|()
specifier|const
block|{
return|return
name|ui
operator|.
name|torrentFile
operator|->
name|text
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|destinationFolder
name|QString
name|AddTorrentDialog
operator|::
name|destinationFolder
parameter_list|()
specifier|const
block|{
return|return
name|ui
operator|.
name|destinationFolder
operator|->
name|text
argument_list|()
return|;
block|}
end_function
end_unit
