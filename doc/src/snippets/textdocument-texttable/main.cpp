begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the documentation of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of Nokia Corporation and its Subsidiary(-ies) nor **     the names of its contributors may be used to endorse or promote **     products derived from this software without specific prior written **     permission. ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtGui>
end_include
begin_function
DECL|function|main
name|int
name|main
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
name|argv
index|[]
parameter_list|)
block|{
name|int
name|rows
init|=
literal|6
decl_stmt|;
name|int
name|columns
init|=
literal|2
decl_stmt|;
name|QApplication
name|app
argument_list|(
name|argc
argument_list|,
name|argv
argument_list|)
decl_stmt|;
name|QTextEdit
modifier|*
name|textEdit
init|=
operator|new
name|QTextEdit
decl_stmt|;
name|QTextCursor
name|cursor
argument_list|(
name|textEdit
operator|->
name|textCursor
argument_list|()
argument_list|)
decl_stmt|;
name|cursor
operator|.
name|movePosition
argument_list|(
name|QTextCursor
operator|::
name|Start
argument_list|)
expr_stmt|;
name|QTextTableFormat
name|tableFormat
decl_stmt|;
name|tableFormat
operator|.
name|setAlignment
argument_list|(
name|Qt
operator|::
name|AlignHCenter
argument_list|)
expr_stmt|;
name|tableFormat
operator|.
name|setCellPadding
argument_list|(
literal|2
argument_list|)
expr_stmt|;
name|tableFormat
operator|.
name|setCellSpacing
argument_list|(
literal|2
argument_list|)
expr_stmt|;
name|QTextTable
modifier|*
name|table
init|=
name|cursor
operator|.
name|insertTable
argument_list|(
name|rows
argument_list|,
name|columns
argument_list|)
decl_stmt|;
name|table
operator|->
name|setFormat
argument_list|(
name|tableFormat
argument_list|)
expr_stmt|;
name|QTextCharFormat
name|boldFormat
decl_stmt|;
name|boldFormat
operator|.
name|setFontWeight
argument_list|(
name|QFont
operator|::
name|Bold
argument_list|)
expr_stmt|;
name|QTextBlockFormat
name|centerFormat
decl_stmt|;
name|centerFormat
operator|.
name|setAlignment
argument_list|(
name|Qt
operator|::
name|AlignHCenter
argument_list|)
expr_stmt|;
name|cursor
operator|.
name|mergeBlockFormat
argument_list|(
name|centerFormat
argument_list|)
expr_stmt|;
name|cursor
operator|=
name|table
operator|->
name|cellAt
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
operator|.
name|firstCursorPosition
argument_list|()
expr_stmt|;
name|cursor
operator|.
name|insertText
argument_list|(
operator|(
literal|"Details"
operator|)
argument_list|,
name|boldFormat
argument_list|)
expr_stmt|;
name|cursor
operator|=
name|table
operator|->
name|cellAt
argument_list|(
literal|1
argument_list|,
literal|0
argument_list|)
operator|.
name|firstCursorPosition
argument_list|()
expr_stmt|;
name|cursor
operator|.
name|insertText
argument_list|(
literal|"Alan"
argument_list|)
expr_stmt|;
name|cursor
operator|=
name|table
operator|->
name|cellAt
argument_list|(
literal|1
argument_list|,
literal|1
argument_list|)
operator|.
name|firstCursorPosition
argument_list|()
expr_stmt|;
name|cursor
operator|.
name|insertText
argument_list|(
literal|"5, Pickety Street"
argument_list|)
expr_stmt|;
comment|//! [0]
name|table
operator|->
name|mergeCells
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|1
argument_list|,
literal|2
argument_list|)
expr_stmt|;
comment|//! [0] //! [1]
name|table
operator|->
name|splitCell
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|)
expr_stmt|;
comment|//! [1]
name|textEdit
operator|->
name|show
argument_list|()
expr_stmt|;
return|return
name|app
operator|.
name|exec
argument_list|()
return|;
block|}
end_function
end_unit
