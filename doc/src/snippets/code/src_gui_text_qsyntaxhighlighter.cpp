begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the documentation of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of Nokia Corporation and its Subsidiary(-ies) nor **     the names of its contributors may be used to endorse or promote **     products derived from this software without specific prior written **     permission. ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_comment
comment|//! [0]
end_comment
begin_decl_stmt
DECL|variable|editor
name|QTextEdit
modifier|*
name|editor
init|=
operator|new
name|QTextEdit
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|highlighter
name|MyHighlighter
modifier|*
name|highlighter
init|=
operator|new
name|MyHighlighter
argument_list|(
name|editor
operator|->
name|document
argument_list|()
argument_list|)
decl_stmt|;
end_decl_stmt
begin_comment
comment|//! [0]
end_comment
begin_comment
comment|//! [1]
end_comment
begin_function
DECL|function|highlightBlock
name|void
name|MyHighlighter
operator|::
name|highlightBlock
parameter_list|(
specifier|const
name|QString
modifier|&
name|text
parameter_list|)
block|{
name|QTextCharFormat
name|myClassFormat
decl_stmt|;
name|myClassFormat
operator|.
name|setFontWeight
argument_list|(
name|QFont
operator|::
name|Bold
argument_list|)
expr_stmt|;
name|myClassFormat
operator|.
name|setForeground
argument_list|(
name|Qt
operator|::
name|darkMagenta
argument_list|)
expr_stmt|;
name|QString
name|pattern
init|=
literal|"\\bMy[A-Za-z]+\\b"
decl_stmt|;
name|QRegExp
name|expression
argument_list|(
name|pattern
argument_list|)
decl_stmt|;
name|int
name|index
init|=
name|text
operator|.
name|indexOf
argument_list|(
name|expression
argument_list|)
decl_stmt|;
while|while
condition|(
name|index
operator|>=
literal|0
condition|)
block|{
name|int
name|length
init|=
name|expression
operator|.
name|matchedLength
argument_list|()
decl_stmt|;
name|setFormat
argument_list|(
name|index
argument_list|,
name|length
argument_list|,
name|myClassFormat
argument_list|)
expr_stmt|;
name|index
operator|=
name|text
operator|.
name|indexOf
argument_list|(
name|expression
argument_list|,
name|index
operator|+
name|length
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_comment
comment|//! [1]
end_comment
begin_comment
comment|//! [2]
end_comment
begin_decl_stmt
DECL|variable|multiLineCommentFormat
name|QTextCharFormat
name|multiLineCommentFormat
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|multiLineCommentFormat
operator|.
name|setForeground
argument_list|(
name|Qt
operator|::
name|red
argument_list|)
expr_stmt|;
end_expr_stmt
begin_decl_stmt
name|QRegExp
name|startExpression
argument_list|(
literal|"/\\*"
argument_list|)
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QRegExp
name|endExpression
argument_list|(
literal|"\\*/"
argument_list|)
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|setCurrentBlockState
argument_list|(
literal|0
argument_list|)
expr_stmt|;
end_expr_stmt
begin_decl_stmt
DECL|variable|startIndex
name|int
name|startIndex
init|=
literal|0
decl_stmt|;
end_decl_stmt
begin_if
if|if
condition|(
name|previousBlockState
argument_list|()
operator|!=
literal|1
condition|)
name|startIndex
operator|=
name|text
operator|.
name|indexOf
argument_list|(
name|startExpression
argument_list|)
expr_stmt|;
end_if
begin_while
while|while
condition|(
name|startIndex
operator|>=
literal|0
condition|)
block|{
name|int
name|endIndex
init|=
name|text
operator|.
name|indexOf
argument_list|(
name|endExpression
argument_list|,
name|startIndex
argument_list|)
decl_stmt|;
name|int
name|commentLength
decl_stmt|;
if|if
condition|(
name|endIndex
operator|==
operator|-
literal|1
condition|)
block|{
name|setCurrentBlockState
argument_list|(
literal|1
argument_list|)
expr_stmt|;
name|commentLength
operator|=
name|text
operator|.
name|length
argument_list|()
operator|-
name|startIndex
expr_stmt|;
block|}
else|else
block|{
name|commentLength
operator|=
name|endIndex
operator|-
name|startIndex
operator|+
name|endExpression
operator|.
name|matchedLength
argument_list|()
expr_stmt|;
block|}
name|setFormat
argument_list|(
name|startIndex
argument_list|,
name|commentLength
argument_list|,
name|multiLineCommentFormat
argument_list|)
expr_stmt|;
name|startIndex
operator|=
name|text
operator|.
name|indexOf
argument_list|(
name|startExpression
argument_list|,
name|startIndex
operator|+
name|commentLength
argument_list|)
expr_stmt|;
block|}
end_while
begin_comment
comment|//! [2]
end_comment
begin_comment
comment|//! [3]
end_comment
begin_function
DECL|function|highlightBlock
name|void
name|MyHighlighter
operator|::
name|highlightBlock
parameter_list|(
specifier|const
name|QString
modifier|&
name|text
parameter_list|)
block|{
name|QTextCharFormat
name|myClassFormat
decl_stmt|;
name|myClassFormat
operator|.
name|setFontWeight
argument_list|(
name|QFont
operator|::
name|Bold
argument_list|)
expr_stmt|;
name|myClassFormat
operator|.
name|setForeground
argument_list|(
name|Qt
operator|::
name|darkMagenta
argument_list|)
expr_stmt|;
name|QString
name|pattern
init|=
literal|"\\bMy[A-Za-z]+\\b"
decl_stmt|;
name|QRegExp
name|expression
argument_list|(
name|pattern
argument_list|)
decl_stmt|;
name|int
name|index
init|=
name|text
operator|.
name|indexOf
argument_list|(
name|expression
argument_list|)
decl_stmt|;
while|while
condition|(
name|index
operator|>=
literal|0
condition|)
block|{
name|int
name|length
init|=
name|expression
operator|.
name|matchedLength
argument_list|()
decl_stmt|;
name|setFormat
argument_list|(
name|index
argument_list|,
name|length
argument_list|,
name|myClassFormat
argument_list|)
expr_stmt|;
name|index
operator|=
name|text
operator|.
name|indexOf
argument_list|(
name|expression
argument_list|,
name|index
operator|+
name|length
argument_list|)
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
begin_struct
DECL|struct|ParenthesisInfo
struct|struct
name|ParenthesisInfo
block|{
name|QChar
name|char
decl_stmt|;
DECL|member|position
name|int
name|position
decl_stmt|;
block|}
struct|;
end_struct
begin_struct
DECL|struct|BlockData
struct|struct
name|BlockData
super|:
specifier|public
name|QTextBlockUserData
block|{
DECL|member|parentheses
name|QVector
argument_list|<
name|ParenthesisInfo
argument_list|>
name|parentheses
decl_stmt|;
block|}
struct|;
end_struct
begin_comment
comment|//! [4]
end_comment
end_unit
