begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the documentation of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of Nokia Corporation and its Subsidiary(-ies) nor **     the names of its contributors may be used to endorse or promote **     products derived from this software without specific prior written **     permission. ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_comment
comment|//! [0]
end_comment
begin_decl_stmt
DECL|variable|q
name|QSqlQuery
name|q
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|q
operator|.
name|prepare
argument_list|(
literal|"insert into test (i1, i2, s) values (?, ?, ?)"
argument_list|)
expr_stmt|;
end_expr_stmt
begin_decl_stmt
DECL|variable|col1
name|QVariantList
name|col1
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|col2
name|QVariantList
name|col2
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|col3
name|QVariantList
name|col3
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|col1
operator|<<
literal|1
operator|<<
literal|3
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|col2
operator|<<
literal|2
operator|<<
literal|4
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|col3
operator|<<
literal|"hello"
operator|<<
literal|"world"
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|q
operator|.
name|bindValue
argument_list|(
literal|0
argument_list|,
name|col1
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|q
operator|.
name|bindValue
argument_list|(
literal|1
argument_list|,
name|col2
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|q
operator|.
name|bindValue
argument_list|(
literal|2
argument_list|,
name|col3
argument_list|)
expr_stmt|;
end_expr_stmt
begin_if
if|if
condition|(
operator|!
name|q
operator|.
name|execBatch
argument_list|()
condition|)
name|qDebug
argument_list|()
operator|<<
name|q
operator|.
name|lastError
argument_list|()
expr_stmt|;
end_if
begin_comment
comment|//! [0]
end_comment
begin_comment
comment|//! [1]
end_comment
begin_decl_stmt
DECL|variable|query
name|QSqlQuery
name|query
init|=
operator|...
name|QVariant
name|v
operator|=
name|query
operator|.
name|result
argument_list|()
operator|->
name|handle
argument_list|()
decl_stmt|;
end_decl_stmt
begin_if
if|if
condition|(
name|v
operator|.
name|isValid
argument_list|()
operator|&&
name|qstrcmp
argument_list|(
name|v
operator|.
name|typeName
argument_list|()
argument_list|,
literal|"sqlite3_stmt*"
argument_list|)
condition|)
block|{
comment|// v.data() returns a pointer to the handle
name|sqlite3_stmt
modifier|*
name|handle
init|=
operator|*
cast|static_cast
argument_list|<
name|sqlite3_stmt
operator|*
operator|*
argument_list|>
argument_list|(
name|v
operator|.
name|data
argument_list|()
argument_list|)
decl_stmt|;
if|if
condition|(
name|handle
operator|!=
literal|0
condition|)
block|{
comment|// check that it is not NULL
operator|...
block|}
block|}
end_if
begin_comment
comment|//! [1]
end_comment
begin_comment
comment|//! [2]
end_comment
begin_if
if|if
condition|(
name|v
operator|.
name|typeName
argument_list|()
operator|==
literal|"PGresult*"
condition|)
block|{
name|PGresult
modifier|*
name|handle
init|=
operator|*
cast|static_cast
argument_list|<
name|PGresult
operator|*
operator|*
argument_list|>
argument_list|(
name|v
operator|.
name|data
argument_list|()
argument_list|)
decl_stmt|;
if|if
condition|(
name|handle
operator|!=
literal|0
condition|)
operator|...
block|}
end_if
begin_if
if|if
condition|(
name|v
operator|.
name|typeName
argument_list|()
operator|==
literal|"MYSQL_STMT*"
condition|)
block|{
name|MYSQL_STMT
modifier|*
name|handle
init|=
operator|*
cast|static_cast
argument_list|<
name|MYSQL_STMT
operator|*
operator|*
argument_list|>
argument_list|(
name|v
operator|.
name|data
argument_list|()
argument_list|)
decl_stmt|;
if|if
condition|(
name|handle
operator|!=
literal|0
condition|)
operator|...
block|}
end_if
begin_comment
comment|//! [2]
end_comment
end_unit
