begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of Nokia Corporation and its Subsidiary(-ies) nor **     the names of its contributors may be used to endorse or promote **     products derived from this software without specific prior written **     permission. ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtGui>
end_include
begin_include
include|#
directive|include
file|"xbeltree.h"
end_include
begin_constructor
DECL|function|XbelTree
name|XbelTree
operator|::
name|XbelTree
parameter_list|(
name|QWidget
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QTreeWidget
argument_list|(
name|parent
argument_list|)
block|{
name|QStringList
name|labels
decl_stmt|;
name|labels
operator|<<
name|tr
argument_list|(
literal|"Title"
argument_list|)
operator|<<
name|tr
argument_list|(
literal|"Location"
argument_list|)
expr_stmt|;
name|header
argument_list|()
operator|->
name|setResizeMode
argument_list|(
name|QHeaderView
operator|::
name|Stretch
argument_list|)
expr_stmt|;
name|setHeaderLabels
argument_list|(
name|labels
argument_list|)
expr_stmt|;
name|folderIcon
operator|.
name|addPixmap
argument_list|(
name|style
argument_list|()
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
argument_list|()
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
argument_list|()
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
begin_function
DECL|function|read
name|bool
name|XbelTree
operator|::
name|read
parameter_list|(
name|QIODevice
modifier|*
name|device
parameter_list|)
block|{
name|QString
name|errorStr
decl_stmt|;
name|int
name|errorLine
decl_stmt|;
name|int
name|errorColumn
decl_stmt|;
if|if
condition|(
operator|!
name|domDocument
operator|.
name|setContent
argument_list|(
name|device
argument_list|,
literal|true
argument_list|,
operator|&
name|errorStr
argument_list|,
operator|&
name|errorLine
argument_list|,
operator|&
name|errorColumn
argument_list|)
condition|)
block|{
name|QMessageBox
operator|::
name|information
argument_list|(
name|window
argument_list|()
argument_list|,
name|tr
argument_list|(
literal|"DOM Bookmarks"
argument_list|)
argument_list|,
name|tr
argument_list|(
literal|"Parse error at line %1, column %2:\n%3"
argument_list|)
operator|.
name|arg
argument_list|(
name|errorLine
argument_list|)
operator|.
name|arg
argument_list|(
name|errorColumn
argument_list|)
operator|.
name|arg
argument_list|(
name|errorStr
argument_list|)
argument_list|)
expr_stmt|;
return|return
literal|false
return|;
block|}
name|QDomElement
name|root
init|=
name|domDocument
operator|.
name|documentElement
argument_list|()
decl_stmt|;
if|if
condition|(
name|root
operator|.
name|tagName
argument_list|()
operator|!=
literal|"xbel"
condition|)
block|{
name|QMessageBox
operator|::
name|information
argument_list|(
name|window
argument_list|()
argument_list|,
name|tr
argument_list|(
literal|"DOM Bookmarks"
argument_list|)
argument_list|,
name|tr
argument_list|(
literal|"The file is not an XBEL file."
argument_list|)
argument_list|)
expr_stmt|;
return|return
literal|false
return|;
block|}
elseif|else
if|if
condition|(
name|root
operator|.
name|hasAttribute
argument_list|(
literal|"version"
argument_list|)
operator|&&
name|root
operator|.
name|attribute
argument_list|(
literal|"version"
argument_list|)
operator|!=
literal|"1.0"
condition|)
block|{
name|QMessageBox
operator|::
name|information
argument_list|(
name|window
argument_list|()
argument_list|,
name|tr
argument_list|(
literal|"DOM Bookmarks"
argument_list|)
argument_list|,
name|tr
argument_list|(
literal|"The file is not an XBEL version 1.0 "
literal|"file."
argument_list|)
argument_list|)
expr_stmt|;
return|return
literal|false
return|;
block|}
name|clear
argument_list|()
expr_stmt|;
name|disconnect
argument_list|(
name|this
argument_list|,
name|SIGNAL
argument_list|(
name|itemChanged
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
name|updateDomElement
argument_list|(
name|QTreeWidgetItem
operator|*
argument_list|,
name|int
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|QDomElement
name|child
init|=
name|root
operator|.
name|firstChildElement
argument_list|(
literal|"folder"
argument_list|)
decl_stmt|;
while|while
condition|(
operator|!
name|child
operator|.
name|isNull
argument_list|()
condition|)
block|{
name|parseFolderElement
argument_list|(
name|child
argument_list|)
expr_stmt|;
name|child
operator|=
name|child
operator|.
name|nextSiblingElement
argument_list|(
literal|"folder"
argument_list|)
expr_stmt|;
block|}
name|connect
argument_list|(
name|this
argument_list|,
name|SIGNAL
argument_list|(
name|itemChanged
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
name|updateDomElement
argument_list|(
name|QTreeWidgetItem
operator|*
argument_list|,
name|int
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
return|return
literal|true
return|;
block|}
end_function
begin_function
DECL|function|write
name|bool
name|XbelTree
operator|::
name|write
parameter_list|(
name|QIODevice
modifier|*
name|device
parameter_list|)
block|{
specifier|const
name|int
name|IndentSize
init|=
literal|4
decl_stmt|;
name|QTextStream
name|out
argument_list|(
name|device
argument_list|)
decl_stmt|;
name|domDocument
operator|.
name|save
argument_list|(
name|out
argument_list|,
name|IndentSize
argument_list|)
expr_stmt|;
return|return
literal|true
return|;
block|}
end_function
begin_function
DECL|function|updateDomElement
name|void
name|XbelTree
operator|::
name|updateDomElement
parameter_list|(
name|QTreeWidgetItem
modifier|*
name|item
parameter_list|,
name|int
name|column
parameter_list|)
block|{
name|QDomElement
name|element
init|=
name|domElementForItem
operator|.
name|value
argument_list|(
name|item
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|element
operator|.
name|isNull
argument_list|()
condition|)
block|{
if|if
condition|(
name|column
operator|==
literal|0
condition|)
block|{
name|QDomElement
name|oldTitleElement
init|=
name|element
operator|.
name|firstChildElement
argument_list|(
literal|"title"
argument_list|)
decl_stmt|;
name|QDomElement
name|newTitleElement
init|=
name|domDocument
operator|.
name|createElement
argument_list|(
literal|"title"
argument_list|)
decl_stmt|;
name|QDomText
name|newTitleText
init|=
name|domDocument
operator|.
name|createTextNode
argument_list|(
name|item
operator|->
name|text
argument_list|(
literal|0
argument_list|)
argument_list|)
decl_stmt|;
name|newTitleElement
operator|.
name|appendChild
argument_list|(
name|newTitleText
argument_list|)
expr_stmt|;
name|element
operator|.
name|replaceChild
argument_list|(
name|newTitleElement
argument_list|,
name|oldTitleElement
argument_list|)
expr_stmt|;
block|}
else|else
block|{
if|if
condition|(
name|element
operator|.
name|tagName
argument_list|()
operator|==
literal|"bookmark"
condition|)
name|element
operator|.
name|setAttribute
argument_list|(
literal|"href"
argument_list|,
name|item
operator|->
name|text
argument_list|(
literal|1
argument_list|)
argument_list|)
expr_stmt|;
block|}
block|}
block|}
end_function
begin_function
DECL|function|parseFolderElement
name|void
name|XbelTree
operator|::
name|parseFolderElement
parameter_list|(
specifier|const
name|QDomElement
modifier|&
name|element
parameter_list|,
name|QTreeWidgetItem
modifier|*
name|parentItem
parameter_list|)
block|{
name|QTreeWidgetItem
modifier|*
name|item
init|=
name|createItem
argument_list|(
name|element
argument_list|,
name|parentItem
argument_list|)
decl_stmt|;
name|QString
name|title
init|=
name|element
operator|.
name|firstChildElement
argument_list|(
literal|"title"
argument_list|)
operator|.
name|text
argument_list|()
decl_stmt|;
if|if
condition|(
name|title
operator|.
name|isEmpty
argument_list|()
condition|)
name|title
operator|=
name|QObject
operator|::
name|tr
argument_list|(
literal|"Folder"
argument_list|)
expr_stmt|;
name|item
operator|->
name|setFlags
argument_list|(
name|item
operator|->
name|flags
argument_list|()
operator||
name|Qt
operator|::
name|ItemIsEditable
argument_list|)
expr_stmt|;
name|item
operator|->
name|setIcon
argument_list|(
literal|0
argument_list|,
name|folderIcon
argument_list|)
expr_stmt|;
name|item
operator|->
name|setText
argument_list|(
literal|0
argument_list|,
name|title
argument_list|)
expr_stmt|;
name|bool
name|folded
init|=
operator|(
name|element
operator|.
name|attribute
argument_list|(
literal|"folded"
argument_list|)
operator|!=
literal|"no"
operator|)
decl_stmt|;
name|setItemExpanded
argument_list|(
name|item
argument_list|,
operator|!
name|folded
argument_list|)
expr_stmt|;
name|QDomElement
name|child
init|=
name|element
operator|.
name|firstChildElement
argument_list|()
decl_stmt|;
while|while
condition|(
operator|!
name|child
operator|.
name|isNull
argument_list|()
condition|)
block|{
if|if
condition|(
name|child
operator|.
name|tagName
argument_list|()
operator|==
literal|"folder"
condition|)
block|{
name|parseFolderElement
argument_list|(
name|child
argument_list|,
name|item
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|child
operator|.
name|tagName
argument_list|()
operator|==
literal|"bookmark"
condition|)
block|{
name|QTreeWidgetItem
modifier|*
name|childItem
init|=
name|createItem
argument_list|(
name|child
argument_list|,
name|item
argument_list|)
decl_stmt|;
name|QString
name|title
init|=
name|child
operator|.
name|firstChildElement
argument_list|(
literal|"title"
argument_list|)
operator|.
name|text
argument_list|()
decl_stmt|;
if|if
condition|(
name|title
operator|.
name|isEmpty
argument_list|()
condition|)
name|title
operator|=
name|QObject
operator|::
name|tr
argument_list|(
literal|"Folder"
argument_list|)
expr_stmt|;
name|childItem
operator|->
name|setFlags
argument_list|(
name|item
operator|->
name|flags
argument_list|()
operator||
name|Qt
operator|::
name|ItemIsEditable
argument_list|)
expr_stmt|;
name|childItem
operator|->
name|setIcon
argument_list|(
literal|0
argument_list|,
name|bookmarkIcon
argument_list|)
expr_stmt|;
name|childItem
operator|->
name|setText
argument_list|(
literal|0
argument_list|,
name|title
argument_list|)
expr_stmt|;
name|childItem
operator|->
name|setText
argument_list|(
literal|1
argument_list|,
name|child
operator|.
name|attribute
argument_list|(
literal|"href"
argument_list|)
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|child
operator|.
name|tagName
argument_list|()
operator|==
literal|"separator"
condition|)
block|{
name|QTreeWidgetItem
modifier|*
name|childItem
init|=
name|createItem
argument_list|(
name|child
argument_list|,
name|item
argument_list|)
decl_stmt|;
name|childItem
operator|->
name|setFlags
argument_list|(
name|item
operator|->
name|flags
argument_list|()
operator|&
operator|~
operator|(
name|Qt
operator|::
name|ItemIsSelectable
operator||
name|Qt
operator|::
name|ItemIsEditable
operator|)
argument_list|)
expr_stmt|;
name|childItem
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
block|}
name|child
operator|=
name|child
operator|.
name|nextSiblingElement
argument_list|()
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|createItem
name|QTreeWidgetItem
modifier|*
name|XbelTree
operator|::
name|createItem
parameter_list|(
specifier|const
name|QDomElement
modifier|&
name|element
parameter_list|,
name|QTreeWidgetItem
modifier|*
name|parentItem
parameter_list|)
block|{
name|QTreeWidgetItem
modifier|*
name|item
decl_stmt|;
if|if
condition|(
name|parentItem
condition|)
block|{
name|item
operator|=
operator|new
name|QTreeWidgetItem
argument_list|(
name|parentItem
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|item
operator|=
operator|new
name|QTreeWidgetItem
argument_list|(
name|this
argument_list|)
expr_stmt|;
block|}
name|domElementForItem
operator|.
name|insert
argument_list|(
name|item
argument_list|,
name|element
argument_list|)
expr_stmt|;
return|return
name|item
return|;
block|}
end_function
end_unit
