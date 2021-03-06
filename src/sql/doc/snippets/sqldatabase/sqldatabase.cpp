begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the documentation of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** BSD License Usage ** Alternatively, you may use this file under the terms of the BSD license ** as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of The Qt Company Ltd nor the names of its **     contributors may be used to endorse or promote products derived **     from this software without specific prior written permission. ** ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtGui>
end_include
begin_include
include|#
directive|include
file|<QtSql>
end_include
begin_include
include|#
directive|include
file|<iostream>
end_include
begin_using
using|using
namespace|namespace
name|std
namespace|;
end_using
begin_function
DECL|function|tr
name|QString
name|tr
parameter_list|(
specifier|const
name|char
modifier|*
name|text
parameter_list|)
block|{
return|return
name|QApplication
operator|::
name|translate
argument_list|(
name|text
argument_list|,
name|text
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|QSqlDatabase_snippets
name|void
name|QSqlDatabase_snippets
parameter_list|()
block|{
block|{
comment|//! [0]
name|QSqlDatabase
name|db
init|=
name|QSqlDatabase
operator|::
name|addDatabase
argument_list|(
literal|"QPSQL"
argument_list|)
decl_stmt|;
name|db
operator|.
name|setHostName
argument_list|(
literal|"acidalia"
argument_list|)
expr_stmt|;
name|db
operator|.
name|setDatabaseName
argument_list|(
literal|"customdb"
argument_list|)
expr_stmt|;
name|db
operator|.
name|setUserName
argument_list|(
literal|"mojito"
argument_list|)
expr_stmt|;
name|db
operator|.
name|setPassword
argument_list|(
literal|"J0a1m8"
argument_list|)
expr_stmt|;
name|bool
name|ok
init|=
name|db
operator|.
name|open
argument_list|()
decl_stmt|;
comment|//! [0]
name|Q_UNUSED
argument_list|(
name|ok
argument_list|)
expr_stmt|;
block|}
block|{
comment|//! [1]
name|QSqlDatabase
name|db
init|=
name|QSqlDatabase
operator|::
name|database
argument_list|()
decl_stmt|;
comment|//! [1]
block|}
block|}
end_function
begin_function
DECL|function|QSqlField_snippets
name|void
name|QSqlField_snippets
parameter_list|()
block|{
if|#
directive|if
literal|0
block|{
comment|//! [2]
block|QSqlField field("age", QVariant::Int);     field.setValue(QPixmap());
comment|// WRONG
comment|//! [2]
block|}
endif|#
directive|endif
block|{
comment|//! [3]
name|QSqlField
name|field
argument_list|(
literal|"age"
argument_list|,
name|QVariant
operator|::
name|Int
argument_list|)
decl_stmt|;
name|field
operator|.
name|setValue
argument_list|(
name|QString
argument_list|(
literal|"123"
argument_list|)
argument_list|)
expr_stmt|;
comment|// casts QString to int
comment|//! [3]
block|}
block|{
comment|//! [4]
name|QSqlQuery
name|query
decl_stmt|;
comment|//! [4] //! [5]
name|QSqlRecord
name|record
init|=
name|query
operator|.
name|record
argument_list|()
decl_stmt|;
comment|//! [5] //! [6]
name|QSqlField
name|field
init|=
name|record
operator|.
name|field
argument_list|(
literal|"country"
argument_list|)
decl_stmt|;
comment|//! [6]
block|}
block|}
end_function
begin_function
DECL|function|doSomething
name|void
name|doSomething
parameter_list|(
specifier|const
name|QString
modifier|&
parameter_list|)
block|{ }
end_function
begin_function
DECL|function|QSqlQuery_snippets
name|void
name|QSqlQuery_snippets
parameter_list|()
block|{
block|{
comment|// typical loop
comment|//! [7]
name|QSqlQuery
name|query
argument_list|(
literal|"SELECT country FROM artist"
argument_list|)
decl_stmt|;
while|while
condition|(
name|query
operator|.
name|next
argument_list|()
condition|)
block|{
name|QString
name|country
init|=
name|query
operator|.
name|value
argument_list|(
literal|0
argument_list|)
operator|.
name|toString
argument_list|()
decl_stmt|;
name|doSomething
argument_list|(
name|country
argument_list|)
expr_stmt|;
block|}
comment|//! [7]
block|}
block|{
comment|// field index lookup
comment|//! [8]
name|QSqlQuery
name|query
argument_list|(
literal|"SELECT * FROM artist"
argument_list|)
decl_stmt|;
name|int
name|fieldNo
init|=
name|query
operator|.
name|record
argument_list|()
operator|.
name|indexOf
argument_list|(
literal|"country"
argument_list|)
decl_stmt|;
while|while
condition|(
name|query
operator|.
name|next
argument_list|()
condition|)
block|{
name|QString
name|country
init|=
name|query
operator|.
name|value
argument_list|(
name|fieldNo
argument_list|)
operator|.
name|toString
argument_list|()
decl_stmt|;
name|doSomething
argument_list|(
name|country
argument_list|)
expr_stmt|;
block|}
comment|//! [8]
block|}
block|{
comment|// named with named
comment|//! [9]
name|QSqlQuery
name|query
decl_stmt|;
name|query
operator|.
name|prepare
argument_list|(
literal|"INSERT INTO person (id, forename, surname) "
literal|"VALUES (:id, :forename, :surname)"
argument_list|)
expr_stmt|;
name|query
operator|.
name|bindValue
argument_list|(
literal|":id"
argument_list|,
literal|1001
argument_list|)
expr_stmt|;
name|query
operator|.
name|bindValue
argument_list|(
literal|":forename"
argument_list|,
literal|"Bart"
argument_list|)
expr_stmt|;
name|query
operator|.
name|bindValue
argument_list|(
literal|":surname"
argument_list|,
literal|"Simpson"
argument_list|)
expr_stmt|;
name|query
operator|.
name|exec
argument_list|()
expr_stmt|;
comment|//! [9]
block|}
block|{
comment|// positional with named
comment|//! [10]
name|QSqlQuery
name|query
decl_stmt|;
name|query
operator|.
name|prepare
argument_list|(
literal|"INSERT INTO person (id, forename, surname) "
literal|"VALUES (:id, :forename, :surname)"
argument_list|)
expr_stmt|;
name|query
operator|.
name|bindValue
argument_list|(
literal|0
argument_list|,
literal|1001
argument_list|)
expr_stmt|;
name|query
operator|.
name|bindValue
argument_list|(
literal|1
argument_list|,
literal|"Bart"
argument_list|)
expr_stmt|;
name|query
operator|.
name|bindValue
argument_list|(
literal|2
argument_list|,
literal|"Simpson"
argument_list|)
expr_stmt|;
name|query
operator|.
name|exec
argument_list|()
expr_stmt|;
comment|//! [10]
block|}
block|{
comment|// positional 1
comment|//! [11]
name|QSqlQuery
name|query
decl_stmt|;
name|query
operator|.
name|prepare
argument_list|(
literal|"INSERT INTO person (id, forename, surname) "
literal|"VALUES (?, ?, ?)"
argument_list|)
expr_stmt|;
name|query
operator|.
name|bindValue
argument_list|(
literal|0
argument_list|,
literal|1001
argument_list|)
expr_stmt|;
name|query
operator|.
name|bindValue
argument_list|(
literal|1
argument_list|,
literal|"Bart"
argument_list|)
expr_stmt|;
name|query
operator|.
name|bindValue
argument_list|(
literal|2
argument_list|,
literal|"Simpson"
argument_list|)
expr_stmt|;
name|query
operator|.
name|exec
argument_list|()
expr_stmt|;
comment|//! [11]
block|}
block|{
comment|// positional 2
comment|//! [12]
name|QSqlQuery
name|query
decl_stmt|;
name|query
operator|.
name|prepare
argument_list|(
literal|"INSERT INTO person (id, forename, surname) "
literal|"VALUES (?, ?, ?)"
argument_list|)
expr_stmt|;
name|query
operator|.
name|addBindValue
argument_list|(
literal|1001
argument_list|)
expr_stmt|;
name|query
operator|.
name|addBindValue
argument_list|(
literal|"Bart"
argument_list|)
expr_stmt|;
name|query
operator|.
name|addBindValue
argument_list|(
literal|"Simpson"
argument_list|)
expr_stmt|;
name|query
operator|.
name|exec
argument_list|()
expr_stmt|;
comment|//! [12]
block|}
block|{
comment|// stored
comment|//! [13]
name|QSqlQuery
name|query
decl_stmt|;
name|query
operator|.
name|prepare
argument_list|(
literal|"CALL AsciiToInt(?, ?)"
argument_list|)
expr_stmt|;
name|query
operator|.
name|bindValue
argument_list|(
literal|0
argument_list|,
literal|"A"
argument_list|)
expr_stmt|;
name|query
operator|.
name|bindValue
argument_list|(
literal|1
argument_list|,
literal|0
argument_list|,
name|QSql
operator|::
name|Out
argument_list|)
expr_stmt|;
name|query
operator|.
name|exec
argument_list|()
expr_stmt|;
name|int
name|i
init|=
name|query
operator|.
name|boundValue
argument_list|(
literal|1
argument_list|)
operator|.
name|toInt
argument_list|()
decl_stmt|;
comment|// i is 65
comment|//! [13]
name|Q_UNUSED
argument_list|(
name|i
argument_list|)
expr_stmt|;
block|}
name|QSqlQuery
name|query
decl_stmt|;
block|{
comment|// examine with named binding
comment|//! [14]
name|QMapIterator
argument_list|<
name|QString
argument_list|,
name|QVariant
argument_list|>
name|i
argument_list|(
name|query
operator|.
name|boundValues
argument_list|()
argument_list|)
decl_stmt|;
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
name|cout
operator|<<
name|i
operator|.
name|key
argument_list|()
operator|.
name|toUtf8
argument_list|()
operator|.
name|data
argument_list|()
operator|<<
literal|": "
operator|<<
name|i
operator|.
name|value
argument_list|()
operator|.
name|toString
argument_list|()
operator|.
name|toUtf8
argument_list|()
operator|.
name|data
argument_list|()
operator|<<
name|endl
expr_stmt|;
block|}
comment|//! [14]
block|}
block|{
comment|// examine with positional binding
comment|//! [15]
name|QList
argument_list|<
name|QVariant
argument_list|>
name|list
init|=
name|query
operator|.
name|boundValues
argument_list|()
operator|.
name|values
argument_list|()
decl_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|list
operator|.
name|size
argument_list|()
condition|;
operator|++
name|i
control|)
name|cout
operator|<<
name|i
operator|<<
literal|": "
operator|<<
name|list
operator|.
name|at
argument_list|(
name|i
argument_list|)
operator|.
name|toString
argument_list|()
operator|.
name|toUtf8
argument_list|()
operator|.
name|data
argument_list|()
operator|<<
name|endl
expr_stmt|;
comment|//! [15]
block|}
block|}
end_function
begin_function
DECL|function|QSqlQueryModel_snippets
name|void
name|QSqlQueryModel_snippets
parameter_list|()
block|{
block|{
comment|//! [16]
name|QSqlQueryModel
modifier|*
name|model
init|=
operator|new
name|QSqlQueryModel
decl_stmt|;
name|model
operator|->
name|setQuery
argument_list|(
literal|"SELECT name, salary FROM employee"
argument_list|)
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
literal|"Name"
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
literal|"Salary"
argument_list|)
argument_list|)
expr_stmt|;
comment|//! [17]
name|QTableView
modifier|*
name|view
init|=
operator|new
name|QTableView
decl_stmt|;
comment|//! [17] //! [18]
name|view
operator|->
name|setModel
argument_list|(
name|model
argument_list|)
expr_stmt|;
comment|//! [18] //! [19]
name|view
operator|->
name|show
argument_list|()
expr_stmt|;
comment|//! [16] //! [19] //! [20]
name|view
operator|->
name|setEditTriggers
argument_list|(
name|QAbstractItemView
operator|::
name|NoEditTriggers
argument_list|)
expr_stmt|;
comment|//! [20]
block|}
comment|//! [21]
name|QSqlTableModel
name|model
decl_stmt|;
name|model
operator|.
name|setTable
argument_list|(
literal|"employee"
argument_list|)
expr_stmt|;
name|model
operator|.
name|select
argument_list|()
expr_stmt|;
name|int
name|salary
init|=
name|model
operator|.
name|record
argument_list|(
literal|4
argument_list|)
operator|.
name|value
argument_list|(
literal|"salary"
argument_list|)
operator|.
name|toInt
argument_list|()
decl_stmt|;
comment|//! [21]
name|Q_UNUSED
argument_list|(
name|salary
argument_list|)
expr_stmt|;
block|{
comment|//! [22]
name|int
name|salary
init|=
name|model
operator|.
name|data
argument_list|(
name|model
operator|.
name|index
argument_list|(
literal|4
argument_list|,
literal|2
argument_list|)
argument_list|)
operator|.
name|toInt
argument_list|()
decl_stmt|;
comment|//! [22]
name|Q_UNUSED
argument_list|(
name|salary
argument_list|)
expr_stmt|;
block|}
for|for
control|(
name|int
name|row
init|=
literal|0
init|;
name|row
operator|<
name|model
operator|.
name|rowCount
argument_list|()
condition|;
operator|++
name|row
control|)
block|{
for|for
control|(
name|int
name|col
init|=
literal|0
init|;
name|col
operator|<
name|model
operator|.
name|columnCount
argument_list|()
condition|;
operator|++
name|col
control|)
block|{
name|qDebug
argument_list|()
operator|<<
name|model
operator|.
name|data
argument_list|(
name|model
operator|.
name|index
argument_list|(
name|row
argument_list|,
name|col
argument_list|)
argument_list|)
expr_stmt|;
block|}
block|}
block|}
end_function
begin_class
DECL|class|MyModel
class|class
name|MyModel
super|:
specifier|public
name|QSqlQueryModel
block|{
public|public:
name|QVariant
name|data
parameter_list|(
specifier|const
name|QModelIndex
modifier|&
name|item
parameter_list|,
name|int
name|role
parameter_list|)
specifier|const
function_decl|;
DECL|member|m_specialColumnNo
name|int
name|m_specialColumnNo
decl_stmt|;
block|}
class|;
end_class
begin_comment
comment|//! [23]
end_comment
begin_function
DECL|function|data
name|QVariant
name|MyModel
operator|::
name|data
parameter_list|(
specifier|const
name|QModelIndex
modifier|&
name|item
parameter_list|,
name|int
name|role
parameter_list|)
specifier|const
block|{
if|if
condition|(
name|item
operator|.
name|column
argument_list|()
operator|==
name|m_specialColumnNo
condition|)
block|{
comment|// handle column separately
block|}
return|return
name|QSqlQueryModel
operator|::
name|data
argument_list|(
name|item
argument_list|,
name|role
argument_list|)
return|;
block|}
end_function
begin_comment
comment|//! [23]
end_comment
begin_function
DECL|function|QSqlTableModel_snippets
name|void
name|QSqlTableModel_snippets
parameter_list|()
block|{
comment|//! [24]
name|QSqlTableModel
modifier|*
name|model
init|=
operator|new
name|QSqlTableModel
argument_list|(
name|parentObject
argument_list|,
name|database
argument_list|)
decl_stmt|;
name|model
operator|->
name|setTable
argument_list|(
literal|"employee"
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
literal|"Name"
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
literal|"Salary"
argument_list|)
argument_list|)
expr_stmt|;
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
name|hideColumn
argument_list|(
literal|0
argument_list|)
expr_stmt|;
comment|// don't show the ID
name|view
operator|->
name|show
argument_list|()
expr_stmt|;
comment|//! [24]
block|{
comment|//! [25]
name|QSqlTableModel
name|model
decl_stmt|;
name|model
operator|.
name|setTable
argument_list|(
literal|"employee"
argument_list|)
expr_stmt|;
name|QString
name|name
init|=
name|model
operator|.
name|record
argument_list|(
literal|4
argument_list|)
operator|.
name|value
argument_list|(
literal|"name"
argument_list|)
operator|.
name|toString
argument_list|()
decl_stmt|;
comment|//! [25]
block|}
block|}
end_function
begin_function
DECL|function|sql_intro_snippets
name|void
name|sql_intro_snippets
parameter_list|()
block|{
block|{
comment|//! [26]
name|QSqlDatabase
name|db
init|=
name|QSqlDatabase
operator|::
name|addDatabase
argument_list|(
literal|"QMYSQL"
argument_list|)
decl_stmt|;
name|db
operator|.
name|setHostName
argument_list|(
literal|"bigblue"
argument_list|)
expr_stmt|;
name|db
operator|.
name|setDatabaseName
argument_list|(
literal|"flightdb"
argument_list|)
expr_stmt|;
name|db
operator|.
name|setUserName
argument_list|(
literal|"acarlson"
argument_list|)
expr_stmt|;
name|db
operator|.
name|setPassword
argument_list|(
literal|"1uTbSbAs"
argument_list|)
expr_stmt|;
name|bool
name|ok
init|=
name|db
operator|.
name|open
argument_list|()
decl_stmt|;
comment|//! [26]
name|Q_UNUSED
argument_list|(
name|ok
argument_list|)
expr_stmt|;
block|}
block|{
comment|//! [27]
name|QSqlDatabase
name|firstDB
init|=
name|QSqlDatabase
operator|::
name|addDatabase
argument_list|(
literal|"QMYSQL"
argument_list|,
literal|"first"
argument_list|)
decl_stmt|;
name|QSqlDatabase
name|secondDB
init|=
name|QSqlDatabase
operator|::
name|addDatabase
argument_list|(
literal|"QMYSQL"
argument_list|,
literal|"second"
argument_list|)
decl_stmt|;
comment|//! [27]
block|}
block|{
comment|//! [28]
name|QSqlDatabase
name|defaultDB
init|=
name|QSqlDatabase
operator|::
name|database
argument_list|()
decl_stmt|;
comment|//! [28] //! [29]
name|QSqlDatabase
name|firstDB
init|=
name|QSqlDatabase
operator|::
name|database
argument_list|(
literal|"first"
argument_list|)
decl_stmt|;
comment|//! [29] //! [30]
name|QSqlDatabase
name|secondDB
init|=
name|QSqlDatabase
operator|::
name|database
argument_list|(
literal|"second"
argument_list|)
decl_stmt|;
comment|//! [30]
block|}
block|{
comment|// SELECT1
comment|//! [31]
name|QSqlQuery
name|query
decl_stmt|;
name|query
operator|.
name|exec
argument_list|(
literal|"SELECT name, salary FROM employee WHERE salary> 50000"
argument_list|)
expr_stmt|;
comment|//! [31]
comment|//! [32]
while|while
condition|(
name|query
operator|.
name|next
argument_list|()
condition|)
block|{
name|QString
name|name
init|=
name|query
operator|.
name|value
argument_list|(
literal|0
argument_list|)
operator|.
name|toString
argument_list|()
decl_stmt|;
name|int
name|salary
init|=
name|query
operator|.
name|value
argument_list|(
literal|1
argument_list|)
operator|.
name|toInt
argument_list|()
decl_stmt|;
name|qDebug
argument_list|()
operator|<<
name|name
operator|<<
name|salary
expr_stmt|;
block|}
comment|//! [32]
block|}
block|{
comment|// FEATURE
comment|//! [33]
name|QSqlQuery
name|query
decl_stmt|;
name|int
name|numRows
decl_stmt|;
name|query
operator|.
name|exec
argument_list|(
literal|"SELECT name, salary FROM employee WHERE salary> 50000"
argument_list|)
expr_stmt|;
name|QSqlDatabase
name|defaultDB
init|=
name|QSqlDatabase
operator|::
name|database
argument_list|()
decl_stmt|;
if|if
condition|(
name|defaultDB
operator|.
name|driver
argument_list|()
operator|->
name|hasFeature
argument_list|(
name|QSqlDriver
operator|::
name|QuerySize
argument_list|)
condition|)
block|{
name|numRows
operator|=
name|query
operator|.
name|size
argument_list|()
expr_stmt|;
block|}
else|else
block|{
comment|// this can be very slow
name|query
operator|.
name|last
argument_list|()
expr_stmt|;
name|numRows
operator|=
name|query
operator|.
name|at
argument_list|()
operator|+
literal|1
expr_stmt|;
block|}
comment|//! [33]
block|}
block|{
comment|// INSERT1
comment|//! [34]
name|QSqlQuery
name|query
decl_stmt|;
name|query
operator|.
name|exec
argument_list|(
literal|"INSERT INTO employee (id, name, salary) "
literal|"VALUES (1001, 'Thad Beaumont', 65000)"
argument_list|)
expr_stmt|;
comment|//! [34]
block|}
block|{
comment|// NAMED BINDING
comment|//! [35]
name|QSqlQuery
name|query
decl_stmt|;
name|query
operator|.
name|prepare
argument_list|(
literal|"INSERT INTO employee (id, name, salary) "
literal|"VALUES (:id, :name, :salary)"
argument_list|)
expr_stmt|;
name|query
operator|.
name|bindValue
argument_list|(
literal|":id"
argument_list|,
literal|1001
argument_list|)
expr_stmt|;
name|query
operator|.
name|bindValue
argument_list|(
literal|":name"
argument_list|,
literal|"Thad Beaumont"
argument_list|)
expr_stmt|;
name|query
operator|.
name|bindValue
argument_list|(
literal|":salary"
argument_list|,
literal|65000
argument_list|)
expr_stmt|;
name|query
operator|.
name|exec
argument_list|()
expr_stmt|;
comment|//! [35]
block|}
block|{
comment|// POSITIONAL BINDING
comment|//! [36]
name|QSqlQuery
name|query
decl_stmt|;
name|query
operator|.
name|prepare
argument_list|(
literal|"INSERT INTO employee (id, name, salary) "
literal|"VALUES (?, ?, ?)"
argument_list|)
expr_stmt|;
name|query
operator|.
name|addBindValue
argument_list|(
literal|1001
argument_list|)
expr_stmt|;
name|query
operator|.
name|addBindValue
argument_list|(
literal|"Thad Beaumont"
argument_list|)
expr_stmt|;
name|query
operator|.
name|addBindValue
argument_list|(
literal|65000
argument_list|)
expr_stmt|;
name|query
operator|.
name|exec
argument_list|()
expr_stmt|;
comment|//! [36]
block|}
block|{
comment|// UPDATE1
comment|//! [37]
name|QSqlQuery
name|query
decl_stmt|;
name|query
operator|.
name|exec
argument_list|(
literal|"UPDATE employee SET salary = 70000 WHERE id = 1003"
argument_list|)
expr_stmt|;
comment|//! [37]
block|}
block|{
comment|// DELETE1
comment|//! [38]
name|QSqlQuery
name|query
decl_stmt|;
name|query
operator|.
name|exec
argument_list|(
literal|"DELETE FROM employee WHERE id = 1007"
argument_list|)
expr_stmt|;
comment|//! [38]
block|}
block|{
comment|// TRANSACTION
comment|//! [39]
name|QSqlDatabase
operator|::
name|database
argument_list|()
operator|.
name|transaction
argument_list|()
expr_stmt|;
name|QSqlQuery
name|query
decl_stmt|;
name|query
operator|.
name|exec
argument_list|(
literal|"SELECT id FROM employee WHERE name = 'Torild Halvorsen'"
argument_list|)
expr_stmt|;
if|if
condition|(
name|query
operator|.
name|next
argument_list|()
condition|)
block|{
name|int
name|employeeId
init|=
name|query
operator|.
name|value
argument_list|(
literal|0
argument_list|)
operator|.
name|toInt
argument_list|()
decl_stmt|;
name|query
operator|.
name|exec
argument_list|(
literal|"INSERT INTO project (id, name, ownerid) "
literal|"VALUES (201, 'Manhattan Project', "
operator|+
name|QString
operator|::
name|number
argument_list|(
name|employeeId
argument_list|)
operator|+
literal|')'
argument_list|)
expr_stmt|;
block|}
name|QSqlDatabase
operator|::
name|database
argument_list|()
operator|.
name|commit
argument_list|()
expr_stmt|;
comment|//! [39]
block|}
block|{
comment|// SQLQUERYMODEL1
comment|//! [40]
name|QSqlQueryModel
name|model
decl_stmt|;
name|model
operator|.
name|setQuery
argument_list|(
literal|"SELECT * FROM employee"
argument_list|)
expr_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|model
operator|.
name|rowCount
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
name|int
name|id
init|=
name|model
operator|.
name|record
argument_list|(
name|i
argument_list|)
operator|.
name|value
argument_list|(
literal|"id"
argument_list|)
operator|.
name|toInt
argument_list|()
decl_stmt|;
name|QString
name|name
init|=
name|model
operator|.
name|record
argument_list|(
name|i
argument_list|)
operator|.
name|value
argument_list|(
literal|"name"
argument_list|)
operator|.
name|toString
argument_list|()
decl_stmt|;
name|qDebug
argument_list|()
operator|<<
name|id
operator|<<
name|name
expr_stmt|;
block|}
comment|//! [40]
block|}
block|{
comment|// SQLTABLEMODEL1
comment|//! [41]
name|QSqlTableModel
name|model
decl_stmt|;
name|model
operator|.
name|setTable
argument_list|(
literal|"employee"
argument_list|)
expr_stmt|;
name|model
operator|.
name|setFilter
argument_list|(
literal|"salary> 50000"
argument_list|)
expr_stmt|;
name|model
operator|.
name|setSort
argument_list|(
literal|2
argument_list|,
name|Qt
operator|::
name|DescendingOrder
argument_list|)
expr_stmt|;
name|model
operator|.
name|select
argument_list|()
expr_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|model
operator|.
name|rowCount
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
name|QString
name|name
init|=
name|model
operator|.
name|record
argument_list|(
name|i
argument_list|)
operator|.
name|value
argument_list|(
literal|"name"
argument_list|)
operator|.
name|toString
argument_list|()
decl_stmt|;
name|int
name|salary
init|=
name|model
operator|.
name|record
argument_list|(
name|i
argument_list|)
operator|.
name|value
argument_list|(
literal|"salary"
argument_list|)
operator|.
name|toInt
argument_list|()
decl_stmt|;
name|qDebug
argument_list|()
operator|<<
name|name
operator|<<
name|salary
expr_stmt|;
block|}
comment|//! [41]
block|}
block|{
comment|// SQLTABLEMODEL2
name|QSqlTableModel
name|model
decl_stmt|;
name|model
operator|.
name|setTable
argument_list|(
literal|"employee"
argument_list|)
expr_stmt|;
comment|//! [42]
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|model
operator|.
name|rowCount
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
name|QSqlRecord
name|record
init|=
name|model
operator|.
name|record
argument_list|(
name|i
argument_list|)
decl_stmt|;
name|double
name|salary
init|=
name|record
operator|.
name|value
argument_list|(
literal|"salary"
argument_list|)
operator|.
name|toInt
argument_list|()
decl_stmt|;
name|salary
operator|*=
literal|1.1
expr_stmt|;
name|record
operator|.
name|setValue
argument_list|(
literal|"salary"
argument_list|,
name|salary
argument_list|)
expr_stmt|;
name|model
operator|.
name|setRecord
argument_list|(
name|i
argument_list|,
name|record
argument_list|)
expr_stmt|;
block|}
name|model
operator|.
name|submitAll
argument_list|()
expr_stmt|;
comment|//! [42]
comment|// SQLTABLEMODEL3
name|int
name|row
init|=
literal|1
decl_stmt|;
name|int
name|column
init|=
literal|2
decl_stmt|;
comment|//! [43]
name|model
operator|.
name|setData
argument_list|(
name|model
operator|.
name|index
argument_list|(
name|row
argument_list|,
name|column
argument_list|)
argument_list|,
literal|75000
argument_list|)
expr_stmt|;
name|model
operator|.
name|submitAll
argument_list|()
expr_stmt|;
comment|//! [43]
comment|// SQLTABLEMODEL4
comment|//! [44]
name|model
operator|.
name|insertRows
argument_list|(
name|row
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|model
operator|.
name|setData
argument_list|(
name|model
operator|.
name|index
argument_list|(
name|row
argument_list|,
literal|0
argument_list|)
argument_list|,
literal|1013
argument_list|)
expr_stmt|;
name|model
operator|.
name|setData
argument_list|(
name|model
operator|.
name|index
argument_list|(
name|row
argument_list|,
literal|1
argument_list|)
argument_list|,
literal|"Peter Gordon"
argument_list|)
expr_stmt|;
name|model
operator|.
name|setData
argument_list|(
name|model
operator|.
name|index
argument_list|(
name|row
argument_list|,
literal|2
argument_list|)
argument_list|,
literal|68500
argument_list|)
expr_stmt|;
name|model
operator|.
name|submitAll
argument_list|()
expr_stmt|;
comment|//! [44]
comment|//! [45]
name|model
operator|.
name|removeRows
argument_list|(
name|row
argument_list|,
literal|5
argument_list|)
expr_stmt|;
comment|//! [45] //! [46]
name|model
operator|.
name|submitAll
argument_list|()
expr_stmt|;
comment|//! [46]
block|}
block|}
end_function
begin_comment
comment|//! [47]
end_comment
begin_class
DECL|class|XyzResult
class|class
name|XyzResult
super|:
specifier|public
name|QSqlResult
block|{
public|public:
DECL|function|XyzResult
name|XyzResult
parameter_list|(
specifier|const
name|QSqlDriver
modifier|*
name|driver
parameter_list|)
member_init_list|:
name|QSqlResult
argument_list|(
name|driver
argument_list|)
block|{}
DECL|function|~XyzResult
name|~
name|XyzResult
parameter_list|()
block|{}
protected|protected:
DECL|function|data
name|QVariant
name|data
parameter_list|(
name|int
comment|/* index */
parameter_list|)
block|{
return|return
name|QVariant
argument_list|()
return|;
block|}
DECL|function|isNull
name|bool
name|isNull
parameter_list|(
name|int
comment|/* index */
parameter_list|)
block|{
return|return
literal|false
return|;
block|}
DECL|function|reset
name|bool
name|reset
parameter_list|(
specifier|const
name|QString
modifier|&
comment|/* query */
parameter_list|)
block|{
return|return
literal|false
return|;
block|}
DECL|function|fetch
name|bool
name|fetch
parameter_list|(
name|int
comment|/* index */
parameter_list|)
block|{
return|return
literal|false
return|;
block|}
DECL|function|fetchFirst
name|bool
name|fetchFirst
parameter_list|()
block|{
return|return
literal|false
return|;
block|}
DECL|function|fetchLast
name|bool
name|fetchLast
parameter_list|()
block|{
return|return
literal|false
return|;
block|}
DECL|function|size
name|int
name|size
parameter_list|()
block|{
return|return
literal|0
return|;
block|}
DECL|function|numRowsAffected
name|int
name|numRowsAffected
parameter_list|()
block|{
return|return
literal|0
return|;
block|}
DECL|function|record
name|QSqlRecord
name|record
parameter_list|()
specifier|const
block|{
return|return
name|QSqlRecord
argument_list|()
return|;
block|}
block|}
class|;
end_class
begin_comment
comment|//! [47]
end_comment
begin_comment
comment|//! [48]
end_comment
begin_class
DECL|class|XyzDriver
class|class
name|XyzDriver
super|:
specifier|public
name|QSqlDriver
block|{
public|public:
DECL|function|XyzDriver
name|XyzDriver
parameter_list|()
block|{}
DECL|function|~XyzDriver
name|~
name|XyzDriver
parameter_list|()
block|{}
DECL|function|hasFeature
name|bool
name|hasFeature
parameter_list|(
name|DriverFeature
comment|/* feature */
parameter_list|)
specifier|const
block|{
return|return
literal|false
return|;
block|}
DECL|function|open
name|bool
name|open
parameter_list|(
specifier|const
name|QString
modifier|&
comment|/* db */
parameter_list|,
specifier|const
name|QString
modifier|&
comment|/* user */
parameter_list|,
specifier|const
name|QString
modifier|&
comment|/* password */
parameter_list|,
specifier|const
name|QString
modifier|&
comment|/* host */
parameter_list|,
name|int
comment|/* port */
parameter_list|,
specifier|const
name|QString
modifier|&
comment|/* options */
parameter_list|)
block|{
return|return
literal|false
return|;
block|}
DECL|function|close
name|void
name|close
parameter_list|()
block|{}
DECL|function|createResult
name|QSqlResult
modifier|*
name|createResult
parameter_list|()
specifier|const
block|{
return|return
operator|new
name|XyzResult
argument_list|(
name|this
argument_list|)
return|;
block|}
block|}
class|;
end_class
begin_comment
comment|//! [48]
end_comment
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
modifier|*
name|argv
parameter_list|)
block|{
name|QApplication
name|app
argument_list|(
name|argc
argument_list|,
name|argv
argument_list|)
decl_stmt|;
name|QSqlDatabase_snippets
argument_list|()
expr_stmt|;
name|QSqlField_snippets
argument_list|()
expr_stmt|;
name|QSqlQuery_snippets
argument_list|()
expr_stmt|;
name|QSqlQueryModel_snippets
argument_list|()
expr_stmt|;
name|QSqlTableModel_snippets
argument_list|()
expr_stmt|;
name|XyzDriver
name|driver
decl_stmt|;
name|XyzResult
name|result
argument_list|(
operator|&
name|driver
argument_list|)
decl_stmt|;
block|}
end_function
end_unit
