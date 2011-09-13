begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of Nokia Corporation and its Subsidiary(-ies) nor **     the names of its contributors may be used to endorse or promote **     products derived from this software without specific prior written **     permission. ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** $QT_END_LICENSE$ ** ****************************************************************************/
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
file|"../connection.h"
end_include
begin_function
DECL|function|initializeModel
name|void
name|initializeModel
parameter_list|(
name|QSqlRelationalTableModel
modifier|*
name|model
parameter_list|)
block|{
comment|//! [0]
name|model
operator|->
name|setTable
argument_list|(
literal|"employee"
argument_list|)
expr_stmt|;
comment|//! [0]
name|model
operator|->
name|setEditStrategy
argument_list|(
name|QSqlTableModel
operator|::
name|OnManualSubmit
argument_list|)
expr_stmt|;
comment|//! [1]
name|model
operator|->
name|setRelation
argument_list|(
literal|2
argument_list|,
name|QSqlRelation
argument_list|(
literal|"city"
argument_list|,
literal|"id"
argument_list|,
literal|"name"
argument_list|)
argument_list|)
expr_stmt|;
comment|//! [1] //! [2]
name|model
operator|->
name|setRelation
argument_list|(
literal|3
argument_list|,
name|QSqlRelation
argument_list|(
literal|"country"
argument_list|,
literal|"id"
argument_list|,
literal|"name"
argument_list|)
argument_list|)
expr_stmt|;
comment|//! [2]
comment|//! [3]
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
name|QObject
operator|::
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
name|QObject
operator|::
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
literal|2
argument_list|,
name|Qt
operator|::
name|Horizontal
argument_list|,
name|QObject
operator|::
name|tr
argument_list|(
literal|"City"
argument_list|)
argument_list|)
expr_stmt|;
name|model
operator|->
name|setHeaderData
argument_list|(
literal|3
argument_list|,
name|Qt
operator|::
name|Horizontal
argument_list|,
name|QObject
operator|::
name|tr
argument_list|(
literal|"Country"
argument_list|)
argument_list|)
expr_stmt|;
comment|//! [3]
name|model
operator|->
name|select
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|createView
name|QTableView
modifier|*
name|createView
parameter_list|(
specifier|const
name|QString
modifier|&
name|title
parameter_list|,
name|QSqlTableModel
modifier|*
name|model
parameter_list|)
block|{
comment|//! [4]
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
name|setItemDelegate
argument_list|(
operator|new
name|QSqlRelationalDelegate
argument_list|(
name|view
argument_list|)
argument_list|)
expr_stmt|;
comment|//! [4]
name|view
operator|->
name|setWindowTitle
argument_list|(
name|title
argument_list|)
expr_stmt|;
return|return
name|view
return|;
block|}
end_function
begin_function
DECL|function|createRelationalTables
name|void
name|createRelationalTables
parameter_list|()
block|{
name|QSqlQuery
name|query
decl_stmt|;
name|query
operator|.
name|exec
argument_list|(
literal|"create table employee(id int primary key, name varchar(20), city int, country int)"
argument_list|)
expr_stmt|;
name|query
operator|.
name|exec
argument_list|(
literal|"insert into employee values(1, 'Espen', 5000, 47)"
argument_list|)
expr_stmt|;
name|query
operator|.
name|exec
argument_list|(
literal|"insert into employee values(2, 'Harald', 80000, 49)"
argument_list|)
expr_stmt|;
name|query
operator|.
name|exec
argument_list|(
literal|"insert into employee values(3, 'Sam', 100, 1)"
argument_list|)
expr_stmt|;
name|query
operator|.
name|exec
argument_list|(
literal|"create table city(id int, name varchar(20))"
argument_list|)
expr_stmt|;
name|query
operator|.
name|exec
argument_list|(
literal|"insert into city values(100, 'San Jose')"
argument_list|)
expr_stmt|;
name|query
operator|.
name|exec
argument_list|(
literal|"insert into city values(5000, 'Oslo')"
argument_list|)
expr_stmt|;
name|query
operator|.
name|exec
argument_list|(
literal|"insert into city values(80000, 'Munich')"
argument_list|)
expr_stmt|;
name|query
operator|.
name|exec
argument_list|(
literal|"create table country(id int, name varchar(20))"
argument_list|)
expr_stmt|;
name|query
operator|.
name|exec
argument_list|(
literal|"insert into country values(1, 'USA')"
argument_list|)
expr_stmt|;
name|query
operator|.
name|exec
argument_list|(
literal|"insert into country values(47, 'Norway')"
argument_list|)
expr_stmt|;
name|query
operator|.
name|exec
argument_list|(
literal|"insert into country values(49, 'Germany')"
argument_list|)
expr_stmt|;
block|}
end_function
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
name|QApplication
name|app
argument_list|(
name|argc
argument_list|,
name|argv
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|createConnection
argument_list|()
condition|)
return|return
literal|1
return|;
name|createRelationalTables
argument_list|()
expr_stmt|;
name|QSqlRelationalTableModel
name|model
decl_stmt|;
name|initializeModel
argument_list|(
operator|&
name|model
argument_list|)
expr_stmt|;
name|QTableView
modifier|*
name|view
init|=
name|createView
argument_list|(
name|QObject
operator|::
name|tr
argument_list|(
literal|"Relational Table Model"
argument_list|)
argument_list|,
operator|&
name|model
argument_list|)
decl_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_SYMBIAN
argument_list|)
name|view
operator|->
name|showMaximized
argument_list|()
expr_stmt|;
else|#
directive|else
name|view
operator|->
name|show
argument_list|()
expr_stmt|;
endif|#
directive|endif
return|return
name|app
operator|.
name|exec
argument_list|()
return|;
block|}
end_function
end_unit
