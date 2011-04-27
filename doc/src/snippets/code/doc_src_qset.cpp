begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the documentation of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of Nokia Corporation and its Subsidiary(-ies) nor **     the names of its contributors may be used to endorse or promote **     products derived from this software without specific prior written **     permission. ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_comment
comment|//! [0]
end_comment
begin_decl_stmt
DECL|variable|set
name|QSet
argument_list|<
name|QString
argument_list|>
name|set
decl_stmt|;
end_decl_stmt
begin_comment
comment|//! [0]
end_comment
begin_comment
comment|//! [1]
end_comment
begin_expr_stmt
name|set
operator|.
name|insert
argument_list|(
literal|"one"
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|set
operator|.
name|insert
argument_list|(
literal|"three"
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|set
operator|.
name|insert
argument_list|(
literal|"seven"
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|//! [1]
end_comment
begin_comment
comment|//! [2]
end_comment
begin_expr_stmt
name|set
operator|<<
literal|"twelve"
operator|<<
literal|"fifteen"
operator|<<
literal|"nineteen"
expr_stmt|;
end_expr_stmt
begin_comment
comment|//! [2]
end_comment
begin_comment
comment|//! [3]
end_comment
begin_if
if|if
condition|(
operator|!
name|set
operator|.
name|contains
argument_list|(
literal|"ninety-nine"
argument_list|)
condition|)
operator|...
comment|//! [3]
comment|//! [4]
name|QSetIterator
argument_list|<
name|QWidget
operator|*
argument_list|>
name|i
argument_list|(
name|set
argument_list|)
expr_stmt|;
end_if
begin_while
while|while
condition|(
name|i
operator|.
name|hasNext
argument_list|()
condition|)
name|qDebug
argument_list|()
operator|<<
name|i
operator|.
name|next
argument_list|()
expr_stmt|;
end_while
begin_comment
comment|//! [4]
end_comment
begin_comment
comment|//! [5]
end_comment
begin_decl_stmt
DECL|variable|i
name|QSet
argument_list|<
name|QWidget
modifier|*
argument_list|>
operator|::
name|const_iterator
name|i
init|=
name|set
operator|.
name|constBegin
argument_list|()
decl_stmt|;
end_decl_stmt
begin_while
while|while
condition|(
name|i
operator|!=
name|set
operator|.
name|constEnd
argument_list|()
condition|)
block|{
name|qDebug
argument_list|()
operator|<<
operator|*
name|i
expr_stmt|;
operator|++
name|i
expr_stmt|;
block|}
end_while
begin_comment
comment|//! [5]
end_comment
begin_comment
comment|//! [6]
end_comment
begin_decl_stmt
DECL|variable|set
name|QSet
argument_list|<
name|QString
argument_list|>
name|set
decl_stmt|;
end_decl_stmt
begin_expr_stmt
operator|...
end_expr_stmt
begin_foreach
foreach|foreach
control|(
specifier|const
name|QString
modifier|&
name|value
decl|,
name|set
control|)
name|qDebug
argument_list|()
operator|<<
name|value
expr_stmt|;
end_foreach
begin_comment
comment|//! [6]
end_comment
begin_comment
comment|//! [7]
end_comment
begin_decl_stmt
DECL|variable|set
name|QSet
argument_list|<
name|QString
argument_list|>
name|set
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|set
operator|.
name|reserve
argument_list|(
literal|20000
argument_list|)
expr_stmt|;
end_expr_stmt
begin_for
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
literal|20000
condition|;
operator|++
name|i
control|)
name|set
operator|.
name|insert
argument_list|(
name|values
index|[
name|i
index|]
argument_list|)
expr_stmt|;
end_for
begin_comment
comment|//! [7]
end_comment
begin_comment
comment|//! [8]
end_comment
begin_decl_stmt
DECL|variable|set
name|QSet
argument_list|<
name|QString
argument_list|>
name|set
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|set
operator|<<
literal|"January"
operator|<<
literal|"February"
operator|<<
operator|...
operator|<<
literal|"December"
expr_stmt|;
end_expr_stmt
begin_decl_stmt
DECL|variable|i
name|QSet
argument_list|<
name|QString
argument_list|>
operator|::
name|iterator
name|i
decl_stmt|;
end_decl_stmt
begin_for
for|for
control|(
name|i
operator|=
name|set
operator|.
name|begin
argument_list|()
init|;
name|i
operator|!=
name|set
operator|.
name|end
argument_list|()
condition|;
operator|++
name|i
control|)
name|qDebug
argument_list|()
operator|<<
operator|*
name|i
expr_stmt|;
end_for
begin_comment
comment|//! [8]
end_comment
begin_comment
comment|//! [9]
end_comment
begin_decl_stmt
DECL|variable|set
name|QSet
argument_list|<
name|QString
argument_list|>
name|set
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|set
operator|<<
literal|"January"
operator|<<
literal|"February"
operator|<<
operator|...
operator|<<
literal|"December"
expr_stmt|;
end_expr_stmt
begin_decl_stmt
DECL|variable|i
name|QSet
argument_list|<
name|QString
argument_list|>
operator|::
name|iterator
name|i
init|=
name|set
operator|.
name|begin
argument_list|()
decl_stmt|;
end_decl_stmt
begin_while
while|while
condition|(
name|i
operator|!=
name|set
operator|.
name|end
argument_list|()
condition|)
block|{
if|if
condition|(
operator|(
operator|*
name|i
operator|)
operator|.
name|startsWith
argument_list|(
literal|'J'
argument_list|)
condition|)
block|{
name|i
operator|=
name|set
operator|.
name|erase
argument_list|(
name|i
argument_list|)
expr_stmt|;
block|}
else|else
block|{
operator|++
name|i
expr_stmt|;
block|}
block|}
end_while
begin_comment
comment|//! [9]
end_comment
begin_comment
comment|//! [10]
end_comment
begin_decl_stmt
DECL|variable|set
name|QSet
argument_list|<
name|QString
argument_list|>
name|set
decl_stmt|;
end_decl_stmt
begin_expr_stmt
operator|...
name|QSet
argument_list|<
name|QString
argument_list|>
operator|::
name|iterator
name|it
operator|=
name|qFind
argument_list|(
name|set
operator|.
name|begin
argument_list|()
argument_list|,
name|set
operator|.
name|end
argument_list|()
argument_list|,
literal|"Jeanette"
argument_list|)
expr_stmt|;
end_expr_stmt
begin_if
if|if
condition|(
name|it
operator|!=
name|set
operator|.
name|end
argument_list|()
condition|)
DECL|variable|endl
name|cout
operator|<<
literal|"Found Jeanette"
operator|<<
name|endl
expr_stmt|;
end_if
begin_comment
comment|//! [10]
end_comment
begin_comment
comment|//! [11]
end_comment
begin_decl_stmt
DECL|variable|set
name|QSet
argument_list|<
name|QString
argument_list|>
name|set
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|set
operator|<<
literal|"January"
operator|<<
literal|"February"
operator|<<
operator|...
operator|<<
literal|"December"
expr_stmt|;
end_expr_stmt
begin_decl_stmt
DECL|variable|i
name|QSet
argument_list|<
name|QString
argument_list|>
operator|::
name|const_iterator
name|i
decl_stmt|;
end_decl_stmt
begin_for
for|for
control|(
name|i
operator|=
name|set
operator|.
name|begin
argument_list|()
init|;
name|i
operator|!=
name|set
operator|.
name|end
argument_list|()
condition|;
operator|++
name|i
control|)
name|qDebug
argument_list|()
operator|<<
operator|*
name|i
expr_stmt|;
end_for
begin_comment
comment|//! [11]
end_comment
begin_comment
comment|//! [12]
end_comment
begin_decl_stmt
DECL|variable|set
name|QSet
argument_list|<
name|QString
argument_list|>
name|set
decl_stmt|;
end_decl_stmt
begin_expr_stmt
operator|...
name|QSet
argument_list|<
name|QString
argument_list|>
operator|::
name|iterator
name|it
operator|=
name|qFind
argument_list|(
name|set
operator|.
name|begin
argument_list|()
argument_list|,
name|set
operator|.
name|end
argument_list|()
argument_list|,
literal|"Jeanette"
argument_list|)
expr_stmt|;
end_expr_stmt
begin_if
if|if
condition|(
name|it
operator|!=
name|set
operator|.
name|constEnd
argument_list|()
condition|)
DECL|variable|endl
name|cout
operator|<<
literal|"Found Jeanette"
operator|<<
name|endl
expr_stmt|;
end_if
begin_comment
comment|//! [12]
end_comment
begin_comment
comment|//! [13]
end_comment
begin_decl_stmt
DECL|variable|set
name|QSet
argument_list|<
name|QString
argument_list|>
name|set
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|set
operator|<<
literal|"red"
operator|<<
literal|"green"
operator|<<
literal|"blue"
operator|<<
operator|...
operator|<<
literal|"black"
expr_stmt|;
end_expr_stmt
begin_decl_stmt
DECL|variable|list
name|QList
argument_list|<
name|QString
argument_list|>
name|list
init|=
name|set
operator|.
name|toList
argument_list|()
decl_stmt|;
end_decl_stmt
begin_expr_stmt
DECL|variable|list
name|qSort
argument_list|(
name|list
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|//! [13]
end_comment
begin_comment
comment|//! [14]
end_comment
begin_decl_stmt
DECL|variable|list
name|QStringList
name|list
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|list
operator|<<
literal|"Julia"
operator|<<
literal|"Mike"
operator|<<
literal|"Mike"
operator|<<
literal|"Julia"
operator|<<
literal|"Julia"
expr_stmt|;
end_expr_stmt
begin_decl_stmt
DECL|variable|set
name|QSet
argument_list|<
name|QString
argument_list|>
name|set
init|=
name|QSet
argument_list|<
name|QString
argument_list|>
operator|::
name|fromList
argument_list|(
name|list
argument_list|)
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|set
operator|.
name|contains
argument_list|(
literal|"Julia"
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|// returns true
end_comment
begin_expr_stmt
name|set
operator|.
name|contains
argument_list|(
literal|"Mike"
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|// returns true
end_comment
begin_expr_stmt
name|set
operator|.
name|size
argument_list|()
expr_stmt|;
end_expr_stmt
begin_comment
comment|// returns 2
end_comment
begin_comment
comment|//! [14]
end_comment
end_unit
