begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** BSD License Usage ** Alternatively, you may use this file under the terms of the BSD license ** as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of The Qt Company Ltd nor the names of its **     contributors may be used to endorse or promote products derived **     from this software without specific prior written permission. ** ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"highlighter.h"
end_include
begin_comment
comment|//! [0]
end_comment
begin_constructor
DECL|function|Highlighter
name|Highlighter
operator|::
name|Highlighter
parameter_list|(
name|QTextDocument
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QSyntaxHighlighter
argument_list|(
name|parent
argument_list|)
block|{
name|HighlightingRule
name|rule
decl_stmt|;
name|keywordFormat
operator|.
name|setForeground
argument_list|(
name|Qt
operator|::
name|darkBlue
argument_list|)
expr_stmt|;
name|keywordFormat
operator|.
name|setFontWeight
argument_list|(
name|QFont
operator|::
name|Bold
argument_list|)
expr_stmt|;
name|QStringList
name|keywordPatterns
decl_stmt|;
name|keywordPatterns
operator|<<
literal|"\\bchar\\b"
operator|<<
literal|"\\bclass\\b"
operator|<<
literal|"\\bconst\\b"
operator|<<
literal|"\\bdouble\\b"
operator|<<
literal|"\\benum\\b"
operator|<<
literal|"\\bexplicit\\b"
operator|<<
literal|"\\bfriend\\b"
operator|<<
literal|"\\binline\\b"
operator|<<
literal|"\\bint\\b"
operator|<<
literal|"\\blong\\b"
operator|<<
literal|"\\bnamespace\\b"
operator|<<
literal|"\\boperator\\b"
operator|<<
literal|"\\bprivate\\b"
operator|<<
literal|"\\bprotected\\b"
operator|<<
literal|"\\bpublic\\b"
operator|<<
literal|"\\bshort\\b"
operator|<<
literal|"\\bsignals\\b"
operator|<<
literal|"\\bsigned\\b"
operator|<<
literal|"\\bslots\\b"
operator|<<
literal|"\\bstatic\\b"
operator|<<
literal|"\\bstruct\\b"
operator|<<
literal|"\\btemplate\\b"
operator|<<
literal|"\\btypedef\\b"
operator|<<
literal|"\\btypename\\b"
operator|<<
literal|"\\bunion\\b"
operator|<<
literal|"\\bunsigned\\b"
operator|<<
literal|"\\bvirtual\\b"
operator|<<
literal|"\\bvoid\\b"
operator|<<
literal|"\\bvolatile\\b"
expr_stmt|;
foreach|foreach
control|(
specifier|const
name|QString
modifier|&
name|pattern
decl|,
name|keywordPatterns
control|)
block|{
name|rule
operator|.
name|pattern
operator|=
name|QRegExp
argument_list|(
name|pattern
argument_list|)
expr_stmt|;
name|rule
operator|.
name|format
operator|=
name|keywordFormat
expr_stmt|;
name|highlightingRules
operator|.
name|append
argument_list|(
name|rule
argument_list|)
expr_stmt|;
comment|//! [0] //! [1]
block|}
comment|//! [1]
comment|//! [2]
name|classFormat
operator|.
name|setFontWeight
argument_list|(
name|QFont
operator|::
name|Bold
argument_list|)
expr_stmt|;
name|classFormat
operator|.
name|setForeground
argument_list|(
name|Qt
operator|::
name|darkMagenta
argument_list|)
expr_stmt|;
name|rule
operator|.
name|pattern
operator|=
name|QRegExp
argument_list|(
literal|"\\bQ[A-Za-z]+\\b"
argument_list|)
expr_stmt|;
name|rule
operator|.
name|format
operator|=
name|classFormat
expr_stmt|;
name|highlightingRules
operator|.
name|append
argument_list|(
name|rule
argument_list|)
expr_stmt|;
comment|//! [2]
comment|//! [3]
name|singleLineCommentFormat
operator|.
name|setForeground
argument_list|(
name|Qt
operator|::
name|red
argument_list|)
expr_stmt|;
name|rule
operator|.
name|pattern
operator|=
name|QRegExp
argument_list|(
literal|"//[^\n]*"
argument_list|)
expr_stmt|;
name|rule
operator|.
name|format
operator|=
name|singleLineCommentFormat
expr_stmt|;
name|highlightingRules
operator|.
name|append
argument_list|(
name|rule
argument_list|)
expr_stmt|;
name|multiLineCommentFormat
operator|.
name|setForeground
argument_list|(
name|Qt
operator|::
name|red
argument_list|)
expr_stmt|;
comment|//! [3]
comment|//! [4]
name|quotationFormat
operator|.
name|setForeground
argument_list|(
name|Qt
operator|::
name|darkGreen
argument_list|)
expr_stmt|;
name|rule
operator|.
name|pattern
operator|=
name|QRegExp
argument_list|(
literal|"\".*\""
argument_list|)
expr_stmt|;
name|rule
operator|.
name|format
operator|=
name|quotationFormat
expr_stmt|;
name|highlightingRules
operator|.
name|append
argument_list|(
name|rule
argument_list|)
expr_stmt|;
comment|//! [4]
comment|//! [5]
name|functionFormat
operator|.
name|setFontItalic
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|functionFormat
operator|.
name|setForeground
argument_list|(
name|Qt
operator|::
name|blue
argument_list|)
expr_stmt|;
name|rule
operator|.
name|pattern
operator|=
name|QRegExp
argument_list|(
literal|"\\b[A-Za-z0-9_]+(?=\\()"
argument_list|)
expr_stmt|;
name|rule
operator|.
name|format
operator|=
name|functionFormat
expr_stmt|;
name|highlightingRules
operator|.
name|append
argument_list|(
name|rule
argument_list|)
expr_stmt|;
comment|//! [5]
comment|//! [6]
name|commentStartExpression
operator|=
name|QRegExp
argument_list|(
literal|"/\\*"
argument_list|)
expr_stmt|;
name|commentEndExpression
operator|=
name|QRegExp
argument_list|(
literal|"\\*/"
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_comment
comment|//! [6]
end_comment
begin_comment
comment|//! [7]
end_comment
begin_function
DECL|function|highlightBlock
name|void
name|Highlighter
operator|::
name|highlightBlock
parameter_list|(
specifier|const
name|QString
modifier|&
name|text
parameter_list|)
block|{
foreach|foreach
control|(
specifier|const
name|HighlightingRule
modifier|&
name|rule
decl|,
name|highlightingRules
control|)
block|{
name|QRegExp
name|expression
argument_list|(
name|rule
operator|.
name|pattern
argument_list|)
decl_stmt|;
name|int
name|index
init|=
name|expression
operator|.
name|indexIn
argument_list|(
name|text
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
name|rule
operator|.
name|format
argument_list|)
expr_stmt|;
name|index
operator|=
name|expression
operator|.
name|indexIn
argument_list|(
name|text
argument_list|,
name|index
operator|+
name|length
argument_list|)
expr_stmt|;
block|}
block|}
comment|//! [7] //! [8]
name|setCurrentBlockState
argument_list|(
literal|0
argument_list|)
expr_stmt|;
comment|//! [8]
comment|//! [9]
name|int
name|startIndex
init|=
literal|0
decl_stmt|;
if|if
condition|(
name|previousBlockState
argument_list|()
operator|!=
literal|1
condition|)
name|startIndex
operator|=
name|commentStartExpression
operator|.
name|indexIn
argument_list|(
name|text
argument_list|)
expr_stmt|;
comment|//! [9] //! [10]
while|while
condition|(
name|startIndex
operator|>=
literal|0
condition|)
block|{
comment|//! [10] //! [11]
name|int
name|endIndex
init|=
name|commentEndExpression
operator|.
name|indexIn
argument_list|(
name|text
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
name|commentEndExpression
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
name|commentStartExpression
operator|.
name|indexIn
argument_list|(
name|text
argument_list|,
name|startIndex
operator|+
name|commentLength
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_comment
comment|//! [11]
end_comment
end_unit
