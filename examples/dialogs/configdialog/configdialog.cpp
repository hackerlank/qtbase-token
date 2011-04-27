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
file|"configdialog.h"
end_include
begin_include
include|#
directive|include
file|"pages.h"
end_include
begin_constructor
DECL|function|ConfigDialog
name|ConfigDialog
operator|::
name|ConfigDialog
parameter_list|()
block|{
name|contentsWidget
operator|=
operator|new
name|QListWidget
expr_stmt|;
name|contentsWidget
operator|->
name|setViewMode
argument_list|(
name|QListView
operator|::
name|IconMode
argument_list|)
expr_stmt|;
name|contentsWidget
operator|->
name|setIconSize
argument_list|(
name|QSize
argument_list|(
literal|96
argument_list|,
literal|84
argument_list|)
argument_list|)
expr_stmt|;
name|contentsWidget
operator|->
name|setMovement
argument_list|(
name|QListView
operator|::
name|Static
argument_list|)
expr_stmt|;
name|contentsWidget
operator|->
name|setMaximumWidth
argument_list|(
literal|128
argument_list|)
expr_stmt|;
name|contentsWidget
operator|->
name|setSpacing
argument_list|(
literal|12
argument_list|)
expr_stmt|;
name|pagesWidget
operator|=
operator|new
name|QStackedWidget
expr_stmt|;
name|pagesWidget
operator|->
name|addWidget
argument_list|(
operator|new
name|ConfigurationPage
argument_list|)
expr_stmt|;
name|pagesWidget
operator|->
name|addWidget
argument_list|(
operator|new
name|UpdatePage
argument_list|)
expr_stmt|;
name|pagesWidget
operator|->
name|addWidget
argument_list|(
operator|new
name|QueryPage
argument_list|)
expr_stmt|;
name|QPushButton
modifier|*
name|closeButton
init|=
operator|new
name|QPushButton
argument_list|(
name|tr
argument_list|(
literal|"Close"
argument_list|)
argument_list|)
decl_stmt|;
name|createIcons
argument_list|()
expr_stmt|;
name|contentsWidget
operator|->
name|setCurrentRow
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|closeButton
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
name|horizontalLayout
init|=
operator|new
name|QHBoxLayout
decl_stmt|;
name|horizontalLayout
operator|->
name|addWidget
argument_list|(
name|contentsWidget
argument_list|)
expr_stmt|;
name|horizontalLayout
operator|->
name|addWidget
argument_list|(
name|pagesWidget
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|QHBoxLayout
modifier|*
name|buttonsLayout
init|=
operator|new
name|QHBoxLayout
decl_stmt|;
name|buttonsLayout
operator|->
name|addStretch
argument_list|(
literal|1
argument_list|)
expr_stmt|;
name|buttonsLayout
operator|->
name|addWidget
argument_list|(
name|closeButton
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
name|horizontalLayout
argument_list|)
expr_stmt|;
name|mainLayout
operator|->
name|addStretch
argument_list|(
literal|1
argument_list|)
expr_stmt|;
name|mainLayout
operator|->
name|addSpacing
argument_list|(
literal|12
argument_list|)
expr_stmt|;
name|mainLayout
operator|->
name|addLayout
argument_list|(
name|buttonsLayout
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
literal|"Config Dialog"
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_function
DECL|function|createIcons
name|void
name|ConfigDialog
operator|::
name|createIcons
parameter_list|()
block|{
name|QListWidgetItem
modifier|*
name|configButton
init|=
operator|new
name|QListWidgetItem
argument_list|(
name|contentsWidget
argument_list|)
decl_stmt|;
name|configButton
operator|->
name|setIcon
argument_list|(
name|QIcon
argument_list|(
literal|":/images/config.png"
argument_list|)
argument_list|)
expr_stmt|;
name|configButton
operator|->
name|setText
argument_list|(
name|tr
argument_list|(
literal|"Configuration"
argument_list|)
argument_list|)
expr_stmt|;
name|configButton
operator|->
name|setTextAlignment
argument_list|(
name|Qt
operator|::
name|AlignHCenter
argument_list|)
expr_stmt|;
name|configButton
operator|->
name|setFlags
argument_list|(
name|Qt
operator|::
name|ItemIsSelectable
operator||
name|Qt
operator|::
name|ItemIsEnabled
argument_list|)
expr_stmt|;
name|QListWidgetItem
modifier|*
name|updateButton
init|=
operator|new
name|QListWidgetItem
argument_list|(
name|contentsWidget
argument_list|)
decl_stmt|;
name|updateButton
operator|->
name|setIcon
argument_list|(
name|QIcon
argument_list|(
literal|":/images/update.png"
argument_list|)
argument_list|)
expr_stmt|;
name|updateButton
operator|->
name|setText
argument_list|(
name|tr
argument_list|(
literal|"Update"
argument_list|)
argument_list|)
expr_stmt|;
name|updateButton
operator|->
name|setTextAlignment
argument_list|(
name|Qt
operator|::
name|AlignHCenter
argument_list|)
expr_stmt|;
name|updateButton
operator|->
name|setFlags
argument_list|(
name|Qt
operator|::
name|ItemIsSelectable
operator||
name|Qt
operator|::
name|ItemIsEnabled
argument_list|)
expr_stmt|;
name|QListWidgetItem
modifier|*
name|queryButton
init|=
operator|new
name|QListWidgetItem
argument_list|(
name|contentsWidget
argument_list|)
decl_stmt|;
name|queryButton
operator|->
name|setIcon
argument_list|(
name|QIcon
argument_list|(
literal|":/images/query.png"
argument_list|)
argument_list|)
expr_stmt|;
name|queryButton
operator|->
name|setText
argument_list|(
name|tr
argument_list|(
literal|"Query"
argument_list|)
argument_list|)
expr_stmt|;
name|queryButton
operator|->
name|setTextAlignment
argument_list|(
name|Qt
operator|::
name|AlignHCenter
argument_list|)
expr_stmt|;
name|queryButton
operator|->
name|setFlags
argument_list|(
name|Qt
operator|::
name|ItemIsSelectable
operator||
name|Qt
operator|::
name|ItemIsEnabled
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|contentsWidget
argument_list|,
name|SIGNAL
argument_list|(
name|currentItemChanged
argument_list|(
name|QListWidgetItem
operator|*
argument_list|,
name|QListWidgetItem
operator|*
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|changePage
argument_list|(
name|QListWidgetItem
operator|*
argument_list|,
name|QListWidgetItem
operator|*
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|changePage
name|void
name|ConfigDialog
operator|::
name|changePage
parameter_list|(
name|QListWidgetItem
modifier|*
name|current
parameter_list|,
name|QListWidgetItem
modifier|*
name|previous
parameter_list|)
block|{
if|if
condition|(
operator|!
name|current
condition|)
name|current
operator|=
name|previous
expr_stmt|;
name|pagesWidget
operator|->
name|setCurrentIndex
argument_list|(
name|contentsWidget
operator|->
name|row
argument_list|(
name|current
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
end_unit
