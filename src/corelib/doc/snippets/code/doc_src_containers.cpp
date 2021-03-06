begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the documentation of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** BSD License Usage ** Alternatively, you may use this file under the terms of the BSD license ** as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of The Qt Company Ltd nor the names of its **     contributors may be used to endorse or promote products derived **     from this software without specific prior written permission. ** ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_comment
comment|//! [0]
end_comment
begin_class
DECL|class|Employee
class|class
name|Employee
block|{
public|public:
DECL|function|Employee
name|Employee
parameter_list|()
block|{}
name|Employee
parameter_list|(
specifier|const
name|Employee
modifier|&
name|other
parameter_list|)
constructor_decl|;
name|Employee
modifier|&
name|operator
name|=
parameter_list|(
specifier|const
name|Employee
modifier|&
name|other
parameter_list|)
function_decl|;
private|private:
DECL|member|myName
name|QString
name|myName
decl_stmt|;
DECL|member|myDateOfBirth
name|QDate
name|myDateOfBirth
decl_stmt|;
block|}
class|;
end_class
begin_comment
comment|//! [0]
end_comment
begin_comment
comment|//! [1]
end_comment
begin_decl_stmt
DECL|variable|list
name|QList
argument_list|<
name|QString
argument_list|>
name|list
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|list
operator|<<
literal|"A"
operator|<<
literal|"B"
operator|<<
literal|"C"
operator|<<
literal|"D"
expr_stmt|;
end_expr_stmt
begin_function_decl
name|QListIterator
argument_list|<
name|QString
argument_list|>
name|i
parameter_list|(
name|list
parameter_list|)
function_decl|;
end_function_decl
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
comment|//! [1]
end_comment
begin_comment
comment|//! [2]
end_comment
begin_function_decl
name|QListIterator
argument_list|<
name|QString
argument_list|>
name|i
parameter_list|(
name|list
parameter_list|)
function_decl|;
end_function_decl
begin_expr_stmt
name|i
operator|.
name|toBack
argument_list|()
expr_stmt|;
end_expr_stmt
begin_while
while|while
condition|(
name|i
operator|.
name|hasPrevious
argument_list|()
condition|)
name|qDebug
argument_list|()
operator|<<
name|i
operator|.
name|previous
argument_list|()
expr_stmt|;
end_while
begin_comment
comment|//! [2]
end_comment
begin_comment
comment|//! [3]
end_comment
begin_function_decl
name|QMutableListIterator
argument_list|<
name|int
argument_list|>
name|i
parameter_list|(
name|list
parameter_list|)
function_decl|;
end_function_decl
begin_while
while|while
condition|(
name|i
operator|.
name|hasNext
argument_list|()
condition|)
block|{
if|if
condition|(
name|i
operator|.
name|next
argument_list|()
operator|%
literal|2
operator|!=
literal|0
condition|)
name|i
operator|.
name|remove
argument_list|()
expr_stmt|;
block|}
end_while
begin_comment
comment|//! [3]
end_comment
begin_comment
comment|//! [4]
end_comment
begin_function_decl
name|QMutableListIterator
argument_list|<
name|int
argument_list|>
name|i
parameter_list|(
name|list
parameter_list|)
function_decl|;
end_function_decl
begin_expr_stmt
name|i
operator|.
name|toBack
argument_list|()
expr_stmt|;
end_expr_stmt
begin_while
while|while
condition|(
name|i
operator|.
name|hasPrevious
argument_list|()
condition|)
block|{
if|if
condition|(
name|i
operator|.
name|previous
argument_list|()
operator|%
literal|2
operator|!=
literal|0
condition|)
name|i
operator|.
name|remove
argument_list|()
expr_stmt|;
block|}
end_while
begin_comment
comment|//! [4]
end_comment
begin_comment
comment|//! [5]
end_comment
begin_function_decl
name|QMutableListIterator
argument_list|<
name|int
argument_list|>
name|i
parameter_list|(
name|list
parameter_list|)
function_decl|;
end_function_decl
begin_while
while|while
condition|(
name|i
operator|.
name|hasNext
argument_list|()
condition|)
block|{
if|if
condition|(
name|i
operator|.
name|next
argument_list|()
operator|>
literal|128
condition|)
name|i
operator|.
name|setValue
argument_list|(
literal|128
argument_list|)
expr_stmt|;
block|}
end_while
begin_comment
comment|//! [5]
end_comment
begin_comment
comment|//! [6]
end_comment
begin_function_decl
name|QMutableListIterator
argument_list|<
name|int
argument_list|>
name|i
parameter_list|(
name|list
parameter_list|)
function_decl|;
end_function_decl
begin_while
while|while
condition|(
name|i
operator|.
name|hasNext
argument_list|()
condition|)
name|i
operator|.
name|next
argument_list|()
operator|*=
literal|2
expr_stmt|;
end_while
begin_comment
comment|//! [6]
end_comment
begin_comment
comment|//! [7]
end_comment
begin_decl_stmt
DECL|variable|map
name|QMap
argument_list|<
name|QString
argument_list|,
name|QString
argument_list|>
name|map
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|map
operator|.
name|insert
argument_list|(
literal|"Paris"
argument_list|,
literal|"France"
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|map
operator|.
name|insert
argument_list|(
literal|"Guatemala City"
argument_list|,
literal|"Guatemala"
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|map
operator|.
name|insert
argument_list|(
literal|"Mexico City"
argument_list|,
literal|"Mexico"
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|map
operator|.
name|insert
argument_list|(
literal|"Moscow"
argument_list|,
literal|"Russia"
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
operator|...
name|QMutableMapIterator
argument_list|<
name|QString
argument_list|,
name|QString
argument_list|>
name|i
argument_list|(
name|map
argument_list|)
expr_stmt|;
end_expr_stmt
begin_while
while|while
condition|(
name|i
operator|.
name|hasNext
argument_list|()
condition|)
block|{
if|if
condition|(
name|i
operator|.
name|next
argument_list|()
operator|.
name|key
argument_list|()
operator|.
name|endsWith
argument_list|(
literal|"City"
argument_list|)
condition|)
name|i
operator|.
name|remove
argument_list|()
expr_stmt|;
block|}
end_while
begin_comment
comment|//! [7]
end_comment
begin_comment
comment|//! [8]
end_comment
begin_decl_stmt
DECL|variable|map
name|QMap
argument_list|<
name|int
argument_list|,
name|QWidget
modifier|*
argument_list|>
name|map
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|hash
name|QHash
argument_list|<
name|int
argument_list|,
name|QWidget
modifier|*
argument_list|>
name|hash
decl_stmt|;
end_decl_stmt
begin_function_decl
name|QMapIterator
argument_list|<
name|int
argument_list|,
name|QWidget
modifier|*
argument_list|>
name|i
parameter_list|(
name|map
parameter_list|)
function_decl|;
end_function_decl
begin_while
while|while
condition|(
name|i
operator|.
name|hasNext
argument_list|()
condition|)
block|{
name|i
operator|.
name|next
argument_list|()
expr_stmt|;
name|hash
operator|.
name|insert
argument_list|(
name|i
operator|.
name|key
argument_list|()
argument_list|,
name|i
operator|.
name|value
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_while
begin_comment
comment|//! [8]
end_comment
begin_comment
comment|//! [9]
end_comment
begin_function_decl
name|QMutableMapIterator
argument_list|<
name|int
argument_list|,
name|QWidget
modifier|*
argument_list|>
name|i
parameter_list|(
name|map
parameter_list|)
function_decl|;
end_function_decl
begin_while
while|while
condition|(
name|i
operator|.
name|findNext
argument_list|(
name|widget
argument_list|)
condition|)
name|i
operator|.
name|remove
argument_list|()
expr_stmt|;
end_while
begin_comment
comment|//! [9]
end_comment
begin_comment
comment|//! [10]
end_comment
begin_decl_stmt
DECL|variable|list
name|QList
argument_list|<
name|QString
argument_list|>
name|list
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|list
operator|<<
literal|"A"
operator|<<
literal|"B"
operator|<<
literal|"C"
operator|<<
literal|"D"
expr_stmt|;
end_expr_stmt
begin_decl_stmt
DECL|variable|i
name|QList
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
name|list
operator|.
name|begin
argument_list|()
init|;
name|i
operator|!=
name|list
operator|.
name|end
argument_list|()
condition|;
operator|++
name|i
control|)
operator|*
name|i
operator|=
operator|(
operator|*
name|i
operator|)
operator|.
name|toLower
argument_list|()
expr_stmt|;
end_for
begin_comment
comment|//! [10]
end_comment
begin_comment
comment|//! [11]
end_comment
begin_decl_stmt
DECL|variable|list
name|QList
argument_list|<
name|QString
argument_list|>
name|list
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|list
operator|<<
literal|"A"
operator|<<
literal|"B"
operator|<<
literal|"C"
operator|<<
literal|"D"
expr_stmt|;
end_expr_stmt
begin_decl_stmt
DECL|variable|i
name|QList
argument_list|<
name|QString
argument_list|>
operator|::
name|reverse_iterator
name|i
decl_stmt|;
end_decl_stmt
begin_for
for|for
control|(
name|i
operator|=
name|list
operator|.
name|rbegin
argument_list|()
init|;
name|i
operator|!=
name|list
operator|.
name|rend
argument_list|()
condition|;
operator|++
name|i
control|)
operator|*
name|i
operator|=
name|i
operator|->
name|toLower
argument_list|()
expr_stmt|;
end_for
begin_comment
unit|}
comment|//! [11]
end_comment
begin_comment
comment|//! [12]
end_comment
begin_expr_stmt
unit|QList
operator|<
name|QString
operator|>
operator|::
name|const_iterator
name|i
expr_stmt|;
end_expr_stmt
begin_for
for|for
control|(
name|i
operator|=
name|list
operator|.
name|constBegin
argument_list|()
init|;
name|i
operator|!=
name|list
operator|.
name|constEnd
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
comment|//! [12]
end_comment
begin_comment
comment|//! [13]
end_comment
begin_decl_stmt
name|QMap
argument_list|<
name|int
argument_list|,
name|int
argument_list|>
name|map
decl_stmt|;
end_decl_stmt
begin_expr_stmt
operator|...
name|QMap
argument_list|<
name|int
argument_list|,
name|int
argument_list|>
operator|::
name|const_iterator
name|i
expr_stmt|;
end_expr_stmt
begin_for
for|for
control|(
name|i
operator|=
name|map
operator|.
name|constBegin
argument_list|()
init|;
name|i
operator|!=
name|map
operator|.
name|constEnd
argument_list|()
condition|;
operator|++
name|i
control|)
name|qDebug
argument_list|()
operator|<<
name|i
operator|.
name|key
argument_list|()
operator|<<
literal|':'
operator|<<
name|i
operator|.
name|value
argument_list|()
expr_stmt|;
end_for
begin_comment
comment|//! [13]
end_comment
begin_comment
comment|//! [14]
end_comment
begin_comment
comment|// RIGHT
end_comment
begin_decl_stmt
specifier|const
name|QList
argument_list|<
name|int
argument_list|>
name|sizes
init|=
name|splitter
operator|->
name|sizes
argument_list|()
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QList
argument_list|<
name|int
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
name|sizes
operator|.
name|begin
argument_list|()
init|;
name|i
operator|!=
name|sizes
operator|.
name|end
argument_list|()
condition|;
operator|++
name|i
control|)
operator|...
comment|// WRONG
name|QList
argument_list|<
name|int
argument_list|>
operator|::
name|const_iterator
name|i
expr_stmt|;
end_for
begin_for
for|for
control|(
name|i
operator|=
name|splitter
operator|->
name|sizes
argument_list|()
operator|.
name|begin
argument_list|()
init|;
name|i
operator|!=
name|splitter
operator|->
name|sizes
argument_list|()
operator|.
name|end
argument_list|()
condition|;
operator|++
name|i
control|)
operator|...
comment|//! [14]
comment|//! [15]
name|QLinkedList
argument_list|<
name|QString
argument_list|>
name|list
expr_stmt|;
end_for
begin_expr_stmt
operator|...
name|QString
name|str
expr_stmt|;
end_expr_stmt
begin_foreach
foreach|foreach
control|(
name|str
init|,
name|list
control|)
name|qDebug
argument_list|()
operator|<<
name|str
expr_stmt|;
end_foreach
begin_comment
comment|//! [15]
end_comment
begin_comment
comment|//! [16]
end_comment
begin_decl_stmt
name|QLinkedList
argument_list|<
name|QString
argument_list|>
name|list
decl_stmt|;
end_decl_stmt
begin_expr_stmt
operator|...
name|QLinkedListIterator
argument_list|<
name|QString
argument_list|>
name|i
argument_list|(
name|list
argument_list|)
expr_stmt|;
end_expr_stmt
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
comment|//! [16]
end_comment
begin_comment
comment|//! [17]
end_comment
begin_decl_stmt
name|QLinkedList
argument_list|<
name|QString
argument_list|>
name|list
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
name|str
decl|,
name|list
control|)
name|qDebug
argument_list|()
operator|<<
name|str
expr_stmt|;
end_foreach
begin_comment
comment|//! [17]
end_comment
begin_comment
comment|//! [18]
end_comment
begin_decl_stmt
name|QLinkedList
argument_list|<
name|QString
argument_list|>
name|list
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
name|str
decl|,
name|list
control|)
block|{
if|if
condition|(
name|str
operator|.
name|isEmpty
argument_list|()
condition|)
break|break;
name|qDebug
argument_list|()
operator|<<
name|str
expr_stmt|;
block|}
end_foreach
begin_comment
comment|//! [18]
end_comment
begin_comment
comment|//! [19]
end_comment
begin_decl_stmt
name|QMap
argument_list|<
name|QString
argument_list|,
name|int
argument_list|>
name|map
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
name|str
decl|,
name|map
operator|.
name|keys
argument_list|()
control|)
name|qDebug
argument_list|()
operator|<<
name|str
operator|<<
literal|':'
operator|<<
name|map
operator|.
name|value
argument_list|(
name|str
argument_list|)
expr_stmt|;
end_foreach
begin_comment
comment|//! [19]
end_comment
begin_comment
comment|//! [20]
end_comment
begin_decl_stmt
name|QMultiMap
argument_list|<
name|QString
argument_list|,
name|int
argument_list|>
name|map
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
name|str
decl|,
name|map
operator|.
name|uniqueKeys
argument_list|()
control|)
block|{
foreach|foreach
control|(
name|int
name|i
decl|,
name|map
operator|.
name|values
argument_list|(
name|str
argument_list|)
control|)
name|qDebug
argument_list|()
operator|<<
name|str
operator|<<
literal|':'
operator|<<
name|i
expr_stmt|;
block|}
end_foreach
begin_comment
comment|//! [20]
end_comment
begin_comment
comment|//! [21]
end_comment
begin_forever
forever|forever
block|{
operator|...
block|}
end_forever
begin_comment
comment|//! [21]
end_comment
begin_comment
comment|//! [22]
end_comment
begin_expr_stmt
name|CONFIG
operator|+=
name|no_keywords
comment|//! [22]
comment|//! [23]
name|QString
name|onlyLetters
argument_list|(
argument|const QString&in
argument_list|)
block|{
name|QString
name|out
block|;
for|for
control|(
name|int
name|j
init|=
literal|0
init|;
name|j
operator|<
name|in
operator|.
name|size
argument_list|()
condition|;
operator|++
name|j
control|)
block|{
if|if
condition|(
name|in
index|[
name|j
index|]
operator|.
name|isLetter
argument_list|()
condition|)
name|out
operator|+=
name|in
index|[
name|j
index|]
expr_stmt|;
block|}
end_expr_stmt
begin_return
return|return
name|out
return|;
end_return
begin_comment
unit|}
comment|//! [23]
end_comment
begin_comment
comment|//! [24]
end_comment
begin_expr_stmt
unit|QVector
operator|<
name|int
operator|>
name|a
operator|,
name|b
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|a
operator|.
name|resize
argument_list|(
literal|100000
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|// make a big vector filled with 0.
end_comment
begin_decl_stmt
name|QVector
argument_list|<
name|int
argument_list|>
operator|::
name|iterator
name|i
init|=
name|a
operator|.
name|begin
argument_list|()
decl_stmt|;
end_decl_stmt
begin_comment
comment|// WRONG way of using the iterator i:
end_comment
begin_expr_stmt
name|b
operator|=
name|a
expr_stmt|;
end_expr_stmt
begin_comment
comment|/*     Now we should be careful with iterator i since it will point to shared data     If we do *i = 4 then we would change the shared instance (both vectors)     The behavior differs from STL containers. Avoid doing such things in Qt. */
end_comment
begin_expr_stmt
name|a
index|[
literal|0
index|]
operator|=
literal|5
expr_stmt|;
end_expr_stmt
begin_comment
comment|/*     Container a is now detached from the shared data,     and even though i was an iterator from the container a, it now works as an iterator in b.     Here the situation is that (*i) == 0. */
end_comment
begin_expr_stmt
name|b
operator|.
name|clear
argument_list|()
expr_stmt|;
end_expr_stmt
begin_comment
comment|// Now the iterator i is completely invalid.
end_comment
begin_decl_stmt
name|int
name|j
init|=
operator|*
name|i
decl_stmt|;
end_decl_stmt
begin_comment
comment|// Undefined behavior!
end_comment
begin_comment
comment|/*     The data from b (which i pointed to) is gone.     This would be well-defined with STL containers (and (*i) == 5),     but with QVector this is likely to crash. */
end_comment
begin_comment
comment|//! [24]
end_comment
end_unit
