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
file|"xbelreader.h"
end_include
begin_comment
comment|//! [0]
end_comment
begin_constructor
DECL|function|XbelReader
name|XbelReader
operator|::
name|XbelReader
parameter_list|(
name|QTreeWidget
modifier|*
name|treeWidget
parameter_list|)
member_init_list|:
name|treeWidget
argument_list|(
name|treeWidget
argument_list|)
block|{
name|QStyle
modifier|*
name|style
init|=
name|treeWidget
operator|->
name|style
argument_list|()
decl_stmt|;
name|folderIcon
operator|.
name|addPixmap
argument_list|(
name|style
operator|->
name|standardPixmap
argument_list|(
name|QStyle
operator|::
name|SP_DirClosedIcon
argument_list|)
argument_list|,
name|QIcon
operator|::
name|Normal
argument_list|,
name|QIcon
operator|::
name|Off
argument_list|)
expr_stmt|;
name|folderIcon
operator|.
name|addPixmap
argument_list|(
name|style
operator|->
name|standardPixmap
argument_list|(
name|QStyle
operator|::
name|SP_DirOpenIcon
argument_list|)
argument_list|,
name|QIcon
operator|::
name|Normal
argument_list|,
name|QIcon
operator|::
name|On
argument_list|)
expr_stmt|;
name|bookmarkIcon
operator|.
name|addPixmap
argument_list|(
name|style
operator|->
name|standardPixmap
argument_list|(
name|QStyle
operator|::
name|SP_FileIcon
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_comment
comment|//! [0]
end_comment
begin_comment
comment|//! [1]
end_comment
begin_function
DECL|function|read
name|bool
name|XbelReader
operator|::
name|read
parameter_list|(
name|QIODevice
modifier|*
name|device
parameter_list|)
block|{
name|xml
operator|.
name|setDevice
argument_list|(
name|device
argument_list|)
expr_stmt|;
if|if
condition|(
name|xml
operator|.
name|readNextStartElement
argument_list|()
condition|)
block|{
if|if
condition|(
name|xml
operator|.
name|name
argument_list|()
operator|==
literal|"xbel"
operator|&&
name|xml
operator|.
name|attributes
argument_list|()
operator|.
name|value
argument_list|(
literal|"version"
argument_list|)
operator|==
literal|"1.0"
condition|)
name|readXBEL
argument_list|()
expr_stmt|;
else|else
name|xml
operator|.
name|raiseError
argument_list|(
name|QObject
operator|::
name|tr
argument_list|(
literal|"The file is not an XBEL version 1.0 file."
argument_list|)
argument_list|)
expr_stmt|;
block|}
return|return
operator|!
name|xml
operator|.
name|error
argument_list|()
return|;
block|}
end_function
begin_comment
comment|//! [1]
end_comment
begin_comment
comment|//! [2]
end_comment
begin_function
DECL|function|errorString
name|QString
name|XbelReader
operator|::
name|errorString
parameter_list|()
specifier|const
block|{
return|return
name|QObject
operator|::
name|tr
argument_list|(
literal|"%1\nLine %2, column %3"
argument_list|)
operator|.
name|arg
argument_list|(
name|xml
operator|.
name|errorString
argument_list|()
argument_list|)
operator|.
name|arg
argument_list|(
name|xml
operator|.
name|lineNumber
argument_list|()
argument_list|)
operator|.
name|arg
argument_list|(
name|xml
operator|.
name|columnNumber
argument_list|()
argument_list|)
return|;
block|}
end_function
begin_comment
comment|//! [2]
end_comment
begin_comment
comment|//! [3]
end_comment
begin_function
DECL|function|readXBEL
name|void
name|XbelReader
operator|::
name|readXBEL
parameter_list|()
block|{
name|Q_ASSERT
argument_list|(
name|xml
operator|.
name|isStartElement
argument_list|()
operator|&&
name|xml
operator|.
name|name
argument_list|()
operator|==
literal|"xbel"
argument_list|)
expr_stmt|;
while|while
condition|(
name|xml
operator|.
name|readNextStartElement
argument_list|()
condition|)
block|{
if|if
condition|(
name|xml
operator|.
name|name
argument_list|()
operator|==
literal|"folder"
condition|)
name|readFolder
argument_list|(
literal|0
argument_list|)
expr_stmt|;
elseif|else
if|if
condition|(
name|xml
operator|.
name|name
argument_list|()
operator|==
literal|"bookmark"
condition|)
name|readBookmark
argument_list|(
literal|0
argument_list|)
expr_stmt|;
elseif|else
if|if
condition|(
name|xml
operator|.
name|name
argument_list|()
operator|==
literal|"separator"
condition|)
name|readSeparator
argument_list|(
literal|0
argument_list|)
expr_stmt|;
else|else
name|xml
operator|.
name|skipCurrentElement
argument_list|()
expr_stmt|;
block|}
block|}
end_function
begin_comment
comment|//! [3]
end_comment
begin_comment
comment|//! [4]
end_comment
begin_function
DECL|function|readTitle
name|void
name|XbelReader
operator|::
name|readTitle
parameter_list|(
name|QTreeWidgetItem
modifier|*
name|item
parameter_list|)
block|{
name|Q_ASSERT
argument_list|(
name|xml
operator|.
name|isStartElement
argument_list|()
operator|&&
name|xml
operator|.
name|name
argument_list|()
operator|==
literal|"title"
argument_list|)
expr_stmt|;
name|QString
name|title
init|=
name|xml
operator|.
name|readElementText
argument_list|()
decl_stmt|;
name|item
operator|->
name|setText
argument_list|(
literal|0
argument_list|,
name|title
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [4]
end_comment
begin_comment
comment|//! [5]
end_comment
begin_function
DECL|function|readSeparator
name|void
name|XbelReader
operator|::
name|readSeparator
parameter_list|(
name|QTreeWidgetItem
modifier|*
name|item
parameter_list|)
block|{
name|Q_ASSERT
argument_list|(
name|xml
operator|.
name|isStartElement
argument_list|()
operator|&&
name|xml
operator|.
name|name
argument_list|()
operator|==
literal|"separator"
argument_list|)
expr_stmt|;
name|QTreeWidgetItem
modifier|*
name|separator
init|=
name|createChildItem
argument_list|(
name|item
argument_list|)
decl_stmt|;
name|separator
operator|->
name|setFlags
argument_list|(
name|item
operator|->
name|flags
argument_list|()
operator|&
operator|~
name|Qt
operator|::
name|ItemIsSelectable
argument_list|)
expr_stmt|;
name|separator
operator|->
name|setText
argument_list|(
literal|0
argument_list|,
name|QString
argument_list|(
literal|30
argument_list|,
literal|0xB7
argument_list|)
argument_list|)
expr_stmt|;
name|xml
operator|.
name|skipCurrentElement
argument_list|()
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [5]
end_comment
begin_function
DECL|function|readFolder
name|void
name|XbelReader
operator|::
name|readFolder
parameter_list|(
name|QTreeWidgetItem
modifier|*
name|item
parameter_list|)
block|{
name|Q_ASSERT
argument_list|(
name|xml
operator|.
name|isStartElement
argument_list|()
operator|&&
name|xml
operator|.
name|name
argument_list|()
operator|==
literal|"folder"
argument_list|)
expr_stmt|;
name|QTreeWidgetItem
modifier|*
name|folder
init|=
name|createChildItem
argument_list|(
name|item
argument_list|)
decl_stmt|;
name|bool
name|folded
init|=
operator|(
name|xml
operator|.
name|attributes
argument_list|()
operator|.
name|value
argument_list|(
literal|"folded"
argument_list|)
operator|!=
literal|"no"
operator|)
decl_stmt|;
name|treeWidget
operator|->
name|setItemExpanded
argument_list|(
name|folder
argument_list|,
operator|!
name|folded
argument_list|)
expr_stmt|;
while|while
condition|(
name|xml
operator|.
name|readNextStartElement
argument_list|()
condition|)
block|{
if|if
condition|(
name|xml
operator|.
name|name
argument_list|()
operator|==
literal|"title"
condition|)
name|readTitle
argument_list|(
name|folder
argument_list|)
expr_stmt|;
elseif|else
if|if
condition|(
name|xml
operator|.
name|name
argument_list|()
operator|==
literal|"folder"
condition|)
name|readFolder
argument_list|(
name|folder
argument_list|)
expr_stmt|;
elseif|else
if|if
condition|(
name|xml
operator|.
name|name
argument_list|()
operator|==
literal|"bookmark"
condition|)
name|readBookmark
argument_list|(
name|folder
argument_list|)
expr_stmt|;
elseif|else
if|if
condition|(
name|xml
operator|.
name|name
argument_list|()
operator|==
literal|"separator"
condition|)
name|readSeparator
argument_list|(
name|folder
argument_list|)
expr_stmt|;
else|else
name|xml
operator|.
name|skipCurrentElement
argument_list|()
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|readBookmark
name|void
name|XbelReader
operator|::
name|readBookmark
parameter_list|(
name|QTreeWidgetItem
modifier|*
name|item
parameter_list|)
block|{
name|Q_ASSERT
argument_list|(
name|xml
operator|.
name|isStartElement
argument_list|()
operator|&&
name|xml
operator|.
name|name
argument_list|()
operator|==
literal|"bookmark"
argument_list|)
expr_stmt|;
name|QTreeWidgetItem
modifier|*
name|bookmark
init|=
name|createChildItem
argument_list|(
name|item
argument_list|)
decl_stmt|;
name|bookmark
operator|->
name|setFlags
argument_list|(
name|bookmark
operator|->
name|flags
argument_list|()
operator||
name|Qt
operator|::
name|ItemIsEditable
argument_list|)
expr_stmt|;
name|bookmark
operator|->
name|setIcon
argument_list|(
literal|0
argument_list|,
name|bookmarkIcon
argument_list|)
expr_stmt|;
name|bookmark
operator|->
name|setText
argument_list|(
literal|0
argument_list|,
name|QObject
operator|::
name|tr
argument_list|(
literal|"Unknown title"
argument_list|)
argument_list|)
expr_stmt|;
name|bookmark
operator|->
name|setText
argument_list|(
literal|1
argument_list|,
name|xml
operator|.
name|attributes
argument_list|()
operator|.
name|value
argument_list|(
literal|"href"
argument_list|)
operator|.
name|toString
argument_list|()
argument_list|)
expr_stmt|;
while|while
condition|(
name|xml
operator|.
name|readNextStartElement
argument_list|()
condition|)
block|{
if|if
condition|(
name|xml
operator|.
name|name
argument_list|()
operator|==
literal|"title"
condition|)
name|readTitle
argument_list|(
name|bookmark
argument_list|)
expr_stmt|;
else|else
name|xml
operator|.
name|skipCurrentElement
argument_list|()
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|createChildItem
name|QTreeWidgetItem
modifier|*
name|XbelReader
operator|::
name|createChildItem
parameter_list|(
name|QTreeWidgetItem
modifier|*
name|item
parameter_list|)
block|{
name|QTreeWidgetItem
modifier|*
name|childItem
decl_stmt|;
if|if
condition|(
name|item
condition|)
block|{
name|childItem
operator|=
operator|new
name|QTreeWidgetItem
argument_list|(
name|item
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|childItem
operator|=
operator|new
name|QTreeWidgetItem
argument_list|(
name|treeWidget
argument_list|)
expr_stmt|;
block|}
name|childItem
operator|->
name|setData
argument_list|(
literal|0
argument_list|,
name|Qt
operator|::
name|UserRole
argument_list|,
name|xml
operator|.
name|name
argument_list|()
operator|.
name|toString
argument_list|()
argument_list|)
expr_stmt|;
return|return
name|childItem
return|;
block|}
end_function
end_unit
