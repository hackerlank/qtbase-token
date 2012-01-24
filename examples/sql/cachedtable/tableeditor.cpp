begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of Nokia Corporation and its Subsidiary(-ies) nor **     the names of its contributors may be used to endorse or promote **     products derived from this software without specific prior written **     permission. ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtWidgets>
end_include
begin_include
include|#
directive|include
file|<QtSql>
end_include
begin_include
include|#
directive|include
file|"tableeditor.h"
end_include
begin_comment
comment|//! [0]
end_comment
begin_constructor
DECL|function|TableEditor
name|TableEditor
operator|::
name|TableEditor
parameter_list|(
specifier|const
name|QString
modifier|&
name|tableName
parameter_list|,
name|QWidget
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QWidget
argument_list|(
name|parent
argument_list|)
block|{
name|model
operator|=
operator|new
name|QSqlTableModel
argument_list|(
name|this
argument_list|)
expr_stmt|;
name|model
operator|->
name|setTable
argument_list|(
name|tableName
argument_list|)
expr_stmt|;
name|model
operator|->
name|setEditStrategy
argument_list|(
name|QSqlTableModel
operator|::
name|OnManualSubmit
argument_list|)
expr_stmt|;
name|model
operator|->
name|select
argument_list|()
expr_stmt|;
name|model
operator|->
name|setHeaderData
argument_list|(
literal|0
argument_list|,
name|Qt
operator|::
name|Horizontal
argument_list|,
name|tr
argument_list|(
literal|"ID"
argument_list|)
argument_list|)
expr_stmt|;
name|model
operator|->
name|setHeaderData
argument_list|(
literal|1
argument_list|,
name|Qt
operator|::
name|Horizontal
argument_list|,
name|tr
argument_list|(
literal|"First name"
argument_list|)
argument_list|)
expr_stmt|;
name|model
operator|->
name|setHeaderData
argument_list|(
literal|2
argument_list|,
name|Qt
operator|::
name|Horizontal
argument_list|,
name|tr
argument_list|(
literal|"Last name"
argument_list|)
argument_list|)
expr_stmt|;
comment|//! [0] //! [1]
name|QTableView
modifier|*
name|view
init|=
operator|new
name|QTableView
decl_stmt|;
name|view
operator|->
name|setModel
argument_list|(
name|model
argument_list|)
expr_stmt|;
name|view
operator|->
name|resizeColumnsToContents
argument_list|()
expr_stmt|;
comment|//! [1]
comment|//! [2]
name|submitButton
operator|=
operator|new
name|QPushButton
argument_list|(
name|tr
argument_list|(
literal|"Submit"
argument_list|)
argument_list|)
expr_stmt|;
name|submitButton
operator|->
name|setDefault
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|revertButton
operator|=
operator|new
name|QPushButton
argument_list|(
name|tr
argument_list|(
literal|"&Revert"
argument_list|)
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
argument_list|(
name|Qt
operator|::
name|Vertical
argument_list|)
expr_stmt|;
name|buttonBox
operator|->
name|addButton
argument_list|(
name|submitButton
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
name|revertButton
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
comment|//! [2]
comment|//! [3]
name|connect
argument_list|(
name|submitButton
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
name|submit
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|revertButton
argument_list|,
name|SIGNAL
argument_list|(
name|clicked
argument_list|()
argument_list|)
argument_list|,
name|model
argument_list|,
name|SLOT
argument_list|(
name|revertAll
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
comment|//! [3]
comment|//! [4]
name|QHBoxLayout
modifier|*
name|mainLayout
init|=
operator|new
name|QHBoxLayout
decl_stmt|;
name|mainLayout
operator|->
name|addWidget
argument_list|(
name|view
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
literal|"Cached Table"
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_comment
comment|//! [4]
end_comment
begin_comment
comment|//! [5]
end_comment
begin_function
DECL|function|submit
name|void
name|TableEditor
operator|::
name|submit
parameter_list|()
block|{
name|model
operator|->
name|database
argument_list|()
operator|.
name|transaction
argument_list|()
expr_stmt|;
if|if
condition|(
name|model
operator|->
name|submitAll
argument_list|()
condition|)
block|{
name|model
operator|->
name|database
argument_list|()
operator|.
name|commit
argument_list|()
expr_stmt|;
block|}
else|else
block|{
name|model
operator|->
name|database
argument_list|()
operator|.
name|rollback
argument_list|()
expr_stmt|;
name|QMessageBox
operator|::
name|warning
argument_list|(
name|this
argument_list|,
name|tr
argument_list|(
literal|"Cached Table"
argument_list|)
argument_list|,
name|tr
argument_list|(
literal|"The database reported an error: %1"
argument_list|)
operator|.
name|arg
argument_list|(
name|model
operator|->
name|lastError
argument_list|()
operator|.
name|text
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_comment
comment|//! [5]
end_comment
end_unit
