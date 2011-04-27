begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the documentation of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of Nokia Corporation and its Subsidiary(-ies) nor **     the names of its contributors may be used to endorse or promote **     products derived from this software without specific prior written **     permission. ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_comment
comment|//! [0]
end_comment
begin_decl_stmt
DECL|variable|integerVector
name|QVector
argument_list|<
name|int
argument_list|>
name|integerVector
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|stringVector
name|QVector
argument_list|<
name|QString
argument_list|>
name|stringVector
decl_stmt|;
end_decl_stmt
begin_comment
comment|//! [0]
end_comment
begin_comment
comment|//! [1]
end_comment
begin_decl_stmt
name|QVector
argument_list|<
name|QString
argument_list|>
name|vector
argument_list|(
literal|200
argument_list|)
decl_stmt|;
end_decl_stmt
begin_comment
comment|//! [1]
end_comment
begin_comment
comment|//! [2]
end_comment
begin_decl_stmt
name|QVector
argument_list|<
name|QString
argument_list|>
name|vector
argument_list|(
literal|200
argument_list|,
literal|"Pass"
argument_list|)
decl_stmt|;
end_decl_stmt
begin_comment
comment|//! [2]
end_comment
begin_comment
comment|//! [3]
end_comment
begin_if
if|if
condition|(
name|vector
index|[
literal|0
index|]
operator|==
literal|"Liz"
condition|)
name|vector
index|[
literal|0
index|]
operator|=
literal|"Elizabeth"
expr_stmt|;
end_if
begin_comment
comment|//! [3]
end_comment
begin_comment
comment|//! [4]
end_comment
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
name|vector
operator|.
name|size
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
if|if
condition|(
name|vector
operator|.
name|at
argument_list|(
name|i
argument_list|)
operator|==
literal|"Alfonso"
condition|)
name|cout
operator|<<
literal|"Found Alfonso at position "
operator|<<
name|i
operator|<<
name|endl
expr_stmt|;
block|}
end_for
begin_comment
comment|//! [4]
end_comment
begin_comment
comment|//! [5]
end_comment
begin_decl_stmt
DECL|variable|i
name|int
name|i
init|=
name|vector
operator|.
name|indexOf
argument_list|(
literal|"Harumi"
argument_list|)
decl_stmt|;
end_decl_stmt
begin_if
if|if
condition|(
name|i
operator|!=
operator|-
literal|1
condition|)
DECL|variable|endl
name|cout
operator|<<
literal|"First occurrence of Harumi is at position "
operator|<<
name|i
operator|<<
name|endl
expr_stmt|;
end_if
begin_comment
comment|//! [5]
end_comment
begin_comment
comment|//! [6]
end_comment
begin_decl_stmt
name|QVector
argument_list|<
name|int
argument_list|>
name|vector
argument_list|(
literal|10
argument_list|)
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|data
name|int
modifier|*
name|data
init|=
name|vector
operator|.
name|data
argument_list|()
decl_stmt|;
end_decl_stmt
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
literal|10
condition|;
operator|++
name|i
control|)
name|data
index|[
name|i
index|]
operator|=
literal|2
operator|*
name|i
expr_stmt|;
end_for
begin_comment
comment|//! [6]
end_comment
begin_comment
comment|//! [7]
end_comment
begin_decl_stmt
name|QVector
argument_list|<
name|QString
argument_list|>
name|vector
argument_list|(
literal|0
argument_list|)
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|vector
operator|.
name|append
argument_list|(
literal|"one"
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|vector
operator|.
name|append
argument_list|(
literal|"two"
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|vector
operator|.
name|append
argument_list|(
literal|"three"
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|// vector: ["one", "two", "three"]
end_comment
begin_comment
comment|//! [7]
end_comment
begin_comment
comment|//! [8]
end_comment
begin_decl_stmt
DECL|variable|vector
name|QVector
argument_list|<
name|QString
argument_list|>
name|vector
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|vector
operator|.
name|prepend
argument_list|(
literal|"one"
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|vector
operator|.
name|prepend
argument_list|(
literal|"two"
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|vector
operator|.
name|prepend
argument_list|(
literal|"three"
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|// vector: ["three", "two", "one"]
end_comment
begin_comment
comment|//! [8]
end_comment
begin_comment
comment|//! [9]
end_comment
begin_decl_stmt
DECL|variable|vector
name|QVector
argument_list|<
name|QString
argument_list|>
name|vector
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|vector
operator|<<
literal|"alpha"
operator|<<
literal|"beta"
operator|<<
literal|"delta"
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|vector
operator|.
name|insert
argument_list|(
literal|2
argument_list|,
literal|"gamma"
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|// vector: ["alpha", "beta", "gamma", "delta"]
end_comment
begin_comment
comment|//! [9]
end_comment
begin_comment
comment|//! [10]
end_comment
begin_decl_stmt
DECL|variable|vector
name|QVector
argument_list|<
name|double
argument_list|>
name|vector
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|vector
operator|<<
literal|2.718
operator|<<
literal|1.442
operator|<<
literal|0.4342
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|vector
operator|.
name|insert
argument_list|(
literal|1
argument_list|,
literal|3
argument_list|,
literal|9.9
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|// vector: [2.718, 9.9, 9.9, 9.9, 1.442, 0.4342]
end_comment
begin_comment
comment|//! [10]
end_comment
begin_comment
comment|//! [11]
end_comment
begin_decl_stmt
name|QVector
argument_list|<
name|QString
argument_list|>
name|vector
argument_list|(
literal|3
argument_list|)
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|vector
operator|.
name|fill
argument_list|(
literal|"Yes"
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|// vector: ["Yes", "Yes", "Yes"]
end_comment
begin_expr_stmt
name|vector
operator|.
name|fill
argument_list|(
literal|"oh"
argument_list|,
literal|5
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|// vector: ["oh", "oh", "oh", "oh", "oh"]
end_comment
begin_comment
comment|//! [11]
end_comment
begin_comment
comment|//! [12]
end_comment
begin_decl_stmt
DECL|variable|vector
name|QVector
argument_list|<
name|QString
argument_list|>
name|vector
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|vector
operator|<<
literal|"A"
operator|<<
literal|"B"
operator|<<
literal|"C"
operator|<<
literal|"B"
operator|<<
literal|"A"
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|vector
operator|.
name|indexOf
argument_list|(
literal|"B"
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|// returns 1
end_comment
begin_expr_stmt
name|vector
operator|.
name|indexOf
argument_list|(
literal|"B"
argument_list|,
literal|1
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|// returns 1
end_comment
begin_expr_stmt
name|vector
operator|.
name|indexOf
argument_list|(
literal|"B"
argument_list|,
literal|2
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|// returns 3
end_comment
begin_expr_stmt
name|vector
operator|.
name|indexOf
argument_list|(
literal|"X"
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|// returns -1
end_comment
begin_comment
comment|//! [12]
end_comment
begin_comment
comment|//! [13]
end_comment
begin_decl_stmt
DECL|variable|vector
name|QList
argument_list|<
name|QString
argument_list|>
name|vector
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|vector
operator|<<
literal|"A"
operator|<<
literal|"B"
operator|<<
literal|"C"
operator|<<
literal|"B"
operator|<<
literal|"A"
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|vector
operator|.
name|lastIndexOf
argument_list|(
literal|"B"
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|// returns 3
end_comment
begin_expr_stmt
name|vector
operator|.
name|lastIndexOf
argument_list|(
literal|"B"
argument_list|,
literal|3
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|// returns 3
end_comment
begin_expr_stmt
name|vector
operator|.
name|lastIndexOf
argument_list|(
literal|"B"
argument_list|,
literal|2
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|// returns 1
end_comment
begin_expr_stmt
name|vector
operator|.
name|lastIndexOf
argument_list|(
literal|"X"
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|// returns -1
end_comment
begin_comment
comment|//! [13]
end_comment
begin_comment
comment|//! [14]
end_comment
begin_decl_stmt
DECL|variable|vect
name|QVector
argument_list|<
name|double
argument_list|>
name|vect
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|vect
operator|<<
literal|"red"
operator|<<
literal|"green"
operator|<<
literal|"blue"
operator|<<
literal|"black"
expr_stmt|;
end_expr_stmt
begin_decl_stmt
DECL|variable|list
name|QList
argument_list|<
name|double
argument_list|>
name|list
init|=
name|vect
operator|.
name|toList
argument_list|()
decl_stmt|;
end_decl_stmt
begin_comment
comment|// list: ["red", "green", "blue", "black"]
end_comment
begin_comment
comment|//! [14]
end_comment
begin_comment
comment|//! [15]
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
literal|"Sven"
operator|<<
literal|"Kim"
operator|<<
literal|"Ola"
expr_stmt|;
end_expr_stmt
begin_decl_stmt
DECL|variable|vect
name|QVector
argument_list|<
name|QString
argument_list|>
name|vect
init|=
name|QVector
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
begin_comment
comment|// vect: ["Sven", "Kim", "Ola"]
end_comment
begin_comment
comment|//! [15]
end_comment
begin_comment
comment|//! [16]
end_comment
begin_decl_stmt
DECL|variable|stdvector
name|std
operator|::
name|vector
argument_list|<
name|double
argument_list|>
name|stdvector
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|vector
operator|.
name|push_back
argument_list|(
literal|1.2
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|vector
operator|.
name|push_back
argument_list|(
literal|0.5
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|vector
operator|.
name|push_back
argument_list|(
literal|3.14
argument_list|)
expr_stmt|;
end_expr_stmt
begin_decl_stmt
DECL|variable|vector
name|QVector
argument_list|<
name|double
argument_list|>
name|vector
init|=
name|QVector
argument_list|<
name|double
argument_list|>
operator|::
name|fromStdVector
argument_list|(
name|stdvector
argument_list|)
decl_stmt|;
end_decl_stmt
begin_comment
comment|//! [16]
end_comment
begin_comment
comment|//! [17]
end_comment
begin_decl_stmt
DECL|variable|vector
name|QVector
argument_list|<
name|double
argument_list|>
name|vector
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|vector
operator|<<
literal|1.2
operator|<<
literal|0.5
operator|<<
literal|3.14
expr_stmt|;
end_expr_stmt
begin_decl_stmt
DECL|variable|stdvector
name|std
operator|::
name|vector
argument_list|<
name|double
argument_list|>
name|stdvector
init|=
name|vector
operator|.
name|toStdVector
argument_list|()
decl_stmt|;
end_decl_stmt
begin_comment
comment|//! [17]
end_comment
end_unit
