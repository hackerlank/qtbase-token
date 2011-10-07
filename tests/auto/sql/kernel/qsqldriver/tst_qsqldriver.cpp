begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtTest/QtTest>
end_include
begin_include
include|#
directive|include
file|<QtSql/QtSql>
end_include
begin_include
include|#
directive|include
file|"../qsqldatabase/tst_databases.h"
end_include
begin_comment
comment|//TESTED_CLASS=
end_comment
begin_comment
comment|//TESTED_FILES=
end_comment
begin_class
DECL|class|tst_QSqlDriver
class|class
name|tst_QSqlDriver
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
public|public:
name|void
name|recreateTestTables
parameter_list|(
name|QSqlDatabase
parameter_list|)
function_decl|;
DECL|member|dbs
name|tst_Databases
name|dbs
decl_stmt|;
public|public
name|slots
public|:
name|void
name|initTestCase_data
parameter_list|()
function_decl|;
name|void
name|initTestCase
parameter_list|()
function_decl|;
name|void
name|cleanupTestCase
parameter_list|()
function_decl|;
name|void
name|init
parameter_list|()
function_decl|;
name|void
name|cleanup
parameter_list|()
function_decl|;
private|private
name|slots
private|:
name|void
name|record
parameter_list|()
function_decl|;
name|void
name|primaryIndex
parameter_list|()
function_decl|;
block|}
class|;
end_class
begin_function
DECL|function|initTestCase_data
name|void
name|tst_QSqlDriver
operator|::
name|initTestCase_data
parameter_list|()
block|{
name|dbs
operator|.
name|open
argument_list|()
expr_stmt|;
if|if
condition|(
name|dbs
operator|.
name|fillTestTable
argument_list|()
operator|==
literal|0
condition|)
name|QSKIP
argument_list|(
literal|"No database drivers are available in this Qt configuration"
argument_list|,
name|SkipAll
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|recreateTestTables
name|void
name|tst_QSqlDriver
operator|::
name|recreateTestTables
parameter_list|(
name|QSqlDatabase
name|db
parameter_list|)
block|{
name|QSqlQuery
name|q
argument_list|(
name|db
argument_list|)
decl_stmt|;
specifier|const
name|QString
name|relTEST1
argument_list|(
name|qTableName
argument_list|(
literal|"relTEST1"
argument_list|,
name|__FILE__
argument_list|)
argument_list|)
decl_stmt|;
if|if
condition|(
name|tst_Databases
operator|::
name|isPostgreSQL
argument_list|(
name|db
argument_list|)
condition|)
name|QVERIFY_SQL
argument_list|(
name|q
argument_list|,
name|exec
argument_list|(
literal|"set client_min_messages='warning'"
argument_list|)
argument_list|)
expr_stmt|;
name|tst_Databases
operator|::
name|safeDropTable
argument_list|(
name|db
argument_list|,
name|relTEST1
argument_list|)
expr_stmt|;
name|QVERIFY_SQL
argument_list|(
name|q
argument_list|,
name|exec
argument_list|(
literal|"create table "
operator|+
name|relTEST1
operator|+
literal|" (id int not null primary key, name varchar(20), title_key int, another_title_key int)"
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY_SQL
argument_list|(
name|q
argument_list|,
name|exec
argument_list|(
literal|"insert into "
operator|+
name|relTEST1
operator|+
literal|" values(1, 'harry', 1, 2)"
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY_SQL
argument_list|(
name|q
argument_list|,
name|exec
argument_list|(
literal|"insert into "
operator|+
name|relTEST1
operator|+
literal|" values(2, 'trond', 2, 1)"
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY_SQL
argument_list|(
name|q
argument_list|,
name|exec
argument_list|(
literal|"insert into "
operator|+
name|relTEST1
operator|+
literal|" values(3, 'vohi', 1, 2)"
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY_SQL
argument_list|(
name|q
argument_list|,
name|exec
argument_list|(
literal|"insert into "
operator|+
name|relTEST1
operator|+
literal|" values(4, 'boris', 2, 2)"
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|initTestCase
name|void
name|tst_QSqlDriver
operator|::
name|initTestCase
parameter_list|()
block|{
foreach|foreach
control|(
specifier|const
name|QString
modifier|&
name|dbname
decl|,
name|dbs
operator|.
name|dbNames
control|)
name|recreateTestTables
argument_list|(
name|QSqlDatabase
operator|::
name|database
argument_list|(
name|dbname
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|cleanupTestCase
name|void
name|tst_QSqlDriver
operator|::
name|cleanupTestCase
parameter_list|()
block|{
foreach|foreach
control|(
specifier|const
name|QString
modifier|&
name|dbName
decl|,
name|dbs
operator|.
name|dbNames
control|)
block|{
name|QSqlDatabase
name|db
init|=
name|QSqlDatabase
operator|::
name|database
argument_list|(
name|dbName
argument_list|)
decl_stmt|;
name|tst_Databases
operator|::
name|safeDropTable
argument_list|(
name|db
argument_list|,
name|qTableName
argument_list|(
literal|"relTEST1"
argument_list|,
name|__FILE__
argument_list|)
argument_list|)
expr_stmt|;
block|}
name|dbs
operator|.
name|close
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|init
name|void
name|tst_QSqlDriver
operator|::
name|init
parameter_list|()
block|{ }
end_function
begin_function
DECL|function|cleanup
name|void
name|tst_QSqlDriver
operator|::
name|cleanup
parameter_list|()
block|{ }
end_function
begin_function
DECL|function|record
name|void
name|tst_QSqlDriver
operator|::
name|record
parameter_list|()
block|{
name|QFETCH_GLOBAL
argument_list|(
name|QString
argument_list|,
name|dbName
argument_list|)
expr_stmt|;
name|QSqlDatabase
name|db
init|=
name|QSqlDatabase
operator|::
name|database
argument_list|(
name|dbName
argument_list|)
decl_stmt|;
name|CHECK_DATABASE
argument_list|(
name|db
argument_list|)
expr_stmt|;
name|QString
name|tablename
argument_list|(
name|qTableName
argument_list|(
literal|"relTEST1"
argument_list|,
name|__FILE__
argument_list|)
argument_list|)
decl_stmt|;
name|QStringList
name|fields
decl_stmt|;
name|fields
operator|<<
literal|"id"
operator|<<
literal|"name"
operator|<<
literal|"title_key"
operator|<<
literal|"another_title_key"
expr_stmt|;
comment|//check we can get records using an unquoted mixed case table name
name|QSqlRecord
name|rec
init|=
name|db
operator|.
name|driver
argument_list|()
operator|->
name|record
argument_list|(
name|tablename
argument_list|)
decl_stmt|;
name|QCOMPARE
argument_list|(
name|rec
operator|.
name|count
argument_list|()
argument_list|,
literal|4
argument_list|)
expr_stmt|;
if|if
condition|(
name|db
operator|.
name|driverName
argument_list|()
operator|.
name|startsWith
argument_list|(
literal|"QIBASE"
argument_list|)
operator|||
name|db
operator|.
name|driverName
argument_list|()
operator|.
name|startsWith
argument_list|(
literal|"QOCI"
argument_list|)
operator|||
name|db
operator|.
name|driverName
argument_list|()
operator|.
name|startsWith
argument_list|(
literal|"QDB2"
argument_list|)
condition|)
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|fields
operator|.
name|count
argument_list|()
condition|;
operator|++
name|i
control|)
name|fields
index|[
name|i
index|]
operator|=
name|fields
index|[
name|i
index|]
operator|.
name|toUpper
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
name|fields
operator|.
name|count
argument_list|()
condition|;
operator|++
name|i
control|)
name|QCOMPARE
argument_list|(
name|rec
operator|.
name|fieldName
argument_list|(
name|i
argument_list|)
argument_list|,
name|fields
index|[
name|i
index|]
argument_list|)
expr_stmt|;
if|if
condition|(
name|db
operator|.
name|driverName
argument_list|()
operator|.
name|startsWith
argument_list|(
literal|"QIBASE"
argument_list|)
operator|||
name|db
operator|.
name|driverName
argument_list|()
operator|.
name|startsWith
argument_list|(
literal|"QOCI"
argument_list|)
operator|||
name|db
operator|.
name|driverName
argument_list|()
operator|.
name|startsWith
argument_list|(
literal|"QDB2"
argument_list|)
condition|)
name|tablename
operator|=
name|tablename
operator|.
name|toUpper
argument_list|()
expr_stmt|;
elseif|else
if|if
condition|(
name|db
operator|.
name|driverName
argument_list|()
operator|.
name|startsWith
argument_list|(
literal|"QPSQL"
argument_list|)
condition|)
name|tablename
operator|=
name|tablename
operator|.
name|toLower
argument_list|()
expr_stmt|;
if|if
condition|(
operator|!
name|db
operator|.
name|driverName
argument_list|()
operator|.
name|startsWith
argument_list|(
literal|"QODBC"
argument_list|)
operator|&&
operator|!
name|db
operator|.
name|databaseName
argument_list|()
operator|.
name|contains
argument_list|(
literal|"PostgreSql"
argument_list|)
condition|)
block|{
comment|//check we can get records using a properly quoted table name
name|rec
operator|=
name|db
operator|.
name|driver
argument_list|()
operator|->
name|record
argument_list|(
name|db
operator|.
name|driver
argument_list|()
operator|->
name|escapeIdentifier
argument_list|(
name|tablename
argument_list|,
name|QSqlDriver
operator|::
name|TableName
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|rec
operator|.
name|count
argument_list|()
argument_list|,
literal|4
argument_list|)
expr_stmt|;
block|}
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|fields
operator|.
name|count
argument_list|()
condition|;
operator|++
name|i
control|)
name|QCOMPARE
argument_list|(
name|rec
operator|.
name|fieldName
argument_list|(
name|i
argument_list|)
argument_list|,
name|fields
index|[
name|i
index|]
argument_list|)
expr_stmt|;
if|if
condition|(
name|db
operator|.
name|driverName
argument_list|()
operator|.
name|startsWith
argument_list|(
literal|"QIBASE"
argument_list|)
operator|||
name|db
operator|.
name|driverName
argument_list|()
operator|.
name|startsWith
argument_list|(
literal|"QOCI"
argument_list|)
operator|||
name|db
operator|.
name|driverName
argument_list|()
operator|.
name|startsWith
argument_list|(
literal|"QDB2"
argument_list|)
condition|)
name|tablename
operator|=
name|tablename
operator|.
name|toLower
argument_list|()
expr_stmt|;
elseif|else
if|if
condition|(
name|db
operator|.
name|driverName
argument_list|()
operator|.
name|startsWith
argument_list|(
literal|"QPSQL"
argument_list|)
condition|)
name|tablename
operator|=
name|tablename
operator|.
name|toUpper
argument_list|()
expr_stmt|;
comment|//check that we can't get records using incorrect tablename casing that's been quoted
name|rec
operator|=
name|db
operator|.
name|driver
argument_list|()
operator|->
name|record
argument_list|(
name|db
operator|.
name|driver
argument_list|()
operator|->
name|escapeIdentifier
argument_list|(
name|tablename
argument_list|,
name|QSqlDriver
operator|::
name|TableName
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|tst_Databases
operator|::
name|isMySQL
argument_list|(
name|db
argument_list|)
operator|||
name|db
operator|.
name|driverName
argument_list|()
operator|.
name|startsWith
argument_list|(
literal|"QSQLITE"
argument_list|)
operator|||
name|db
operator|.
name|driverName
argument_list|()
operator|.
name|startsWith
argument_list|(
literal|"QTDS"
argument_list|)
operator|||
name|tst_Databases
operator|::
name|isSqlServer
argument_list|(
name|db
argument_list|)
operator|||
name|tst_Databases
operator|::
name|isMSAccess
argument_list|(
name|db
argument_list|)
condition|)
name|QCOMPARE
argument_list|(
name|rec
operator|.
name|count
argument_list|()
argument_list|,
literal|4
argument_list|)
expr_stmt|;
comment|//mysql, sqlite and tds will match
else|else
name|QCOMPARE
argument_list|(
name|rec
operator|.
name|count
argument_list|()
argument_list|,
literal|0
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|primaryIndex
name|void
name|tst_QSqlDriver
operator|::
name|primaryIndex
parameter_list|()
block|{
name|QFETCH_GLOBAL
argument_list|(
name|QString
argument_list|,
name|dbName
argument_list|)
expr_stmt|;
name|QSqlDatabase
name|db
init|=
name|QSqlDatabase
operator|::
name|database
argument_list|(
name|dbName
argument_list|)
decl_stmt|;
name|CHECK_DATABASE
argument_list|(
name|db
argument_list|)
expr_stmt|;
name|QString
name|tablename
argument_list|(
name|qTableName
argument_list|(
literal|"relTEST1"
argument_list|,
name|__FILE__
argument_list|)
argument_list|)
decl_stmt|;
comment|//check that we can get primary index using unquoted mixed case table name
name|QSqlIndex
name|index
init|=
name|db
operator|.
name|driver
argument_list|()
operator|->
name|primaryIndex
argument_list|(
name|tablename
argument_list|)
decl_stmt|;
name|QCOMPARE
argument_list|(
name|index
operator|.
name|count
argument_list|()
argument_list|,
literal|1
argument_list|)
expr_stmt|;
if|if
condition|(
name|db
operator|.
name|driverName
argument_list|()
operator|.
name|startsWith
argument_list|(
literal|"QIBASE"
argument_list|)
operator|||
name|db
operator|.
name|driverName
argument_list|()
operator|.
name|startsWith
argument_list|(
literal|"QOCI"
argument_list|)
operator|||
name|db
operator|.
name|driverName
argument_list|()
operator|.
name|startsWith
argument_list|(
literal|"QDB2"
argument_list|)
condition|)
name|QCOMPARE
argument_list|(
name|index
operator|.
name|fieldName
argument_list|(
literal|0
argument_list|)
argument_list|,
name|QString
operator|::
name|fromLatin1
argument_list|(
literal|"ID"
argument_list|)
argument_list|)
expr_stmt|;
else|else
name|QCOMPARE
argument_list|(
name|index
operator|.
name|fieldName
argument_list|(
literal|0
argument_list|)
argument_list|,
name|QString
operator|::
name|fromLatin1
argument_list|(
literal|"id"
argument_list|)
argument_list|)
expr_stmt|;
comment|//check that we can get the primary index using a quoted tablename
if|if
condition|(
name|db
operator|.
name|driverName
argument_list|()
operator|.
name|startsWith
argument_list|(
literal|"QIBASE"
argument_list|)
operator|||
name|db
operator|.
name|driverName
argument_list|()
operator|.
name|startsWith
argument_list|(
literal|"QOCI"
argument_list|)
operator|||
name|db
operator|.
name|driverName
argument_list|()
operator|.
name|startsWith
argument_list|(
literal|"QDB2"
argument_list|)
condition|)
name|tablename
operator|=
name|tablename
operator|.
name|toUpper
argument_list|()
expr_stmt|;
elseif|else
if|if
condition|(
name|db
operator|.
name|driverName
argument_list|()
operator|.
name|startsWith
argument_list|(
literal|"QPSQL"
argument_list|)
condition|)
name|tablename
operator|=
name|tablename
operator|.
name|toLower
argument_list|()
expr_stmt|;
if|if
condition|(
operator|!
name|db
operator|.
name|driverName
argument_list|()
operator|.
name|startsWith
argument_list|(
literal|"QODBC"
argument_list|)
operator|&&
operator|!
name|db
operator|.
name|databaseName
argument_list|()
operator|.
name|contains
argument_list|(
literal|"PostgreSql"
argument_list|)
condition|)
block|{
name|index
operator|=
name|db
operator|.
name|driver
argument_list|()
operator|->
name|primaryIndex
argument_list|(
name|db
operator|.
name|driver
argument_list|()
operator|->
name|escapeIdentifier
argument_list|(
name|tablename
argument_list|,
name|QSqlDriver
operator|::
name|TableName
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|index
operator|.
name|count
argument_list|()
argument_list|,
literal|1
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|db
operator|.
name|driverName
argument_list|()
operator|.
name|startsWith
argument_list|(
literal|"QIBASE"
argument_list|)
operator|||
name|db
operator|.
name|driverName
argument_list|()
operator|.
name|startsWith
argument_list|(
literal|"QOCI"
argument_list|)
operator|||
name|db
operator|.
name|driverName
argument_list|()
operator|.
name|startsWith
argument_list|(
literal|"QDB2"
argument_list|)
condition|)
name|QCOMPARE
argument_list|(
name|index
operator|.
name|fieldName
argument_list|(
literal|0
argument_list|)
argument_list|,
name|QString
operator|::
name|fromLatin1
argument_list|(
literal|"ID"
argument_list|)
argument_list|)
expr_stmt|;
else|else
name|QCOMPARE
argument_list|(
name|index
operator|.
name|fieldName
argument_list|(
literal|0
argument_list|)
argument_list|,
name|QString
operator|::
name|fromLatin1
argument_list|(
literal|"id"
argument_list|)
argument_list|)
expr_stmt|;
comment|//check that we can not get the primary index using a quoted but incorrect table name casing
if|if
condition|(
name|db
operator|.
name|driverName
argument_list|()
operator|.
name|startsWith
argument_list|(
literal|"QIBASE"
argument_list|)
operator|||
name|db
operator|.
name|driverName
argument_list|()
operator|.
name|startsWith
argument_list|(
literal|"QOCI"
argument_list|)
operator|||
name|db
operator|.
name|driverName
argument_list|()
operator|.
name|startsWith
argument_list|(
literal|"QDB2"
argument_list|)
condition|)
name|tablename
operator|=
name|tablename
operator|.
name|toLower
argument_list|()
expr_stmt|;
elseif|else
if|if
condition|(
name|db
operator|.
name|driverName
argument_list|()
operator|.
name|startsWith
argument_list|(
literal|"QPSQL"
argument_list|)
condition|)
name|tablename
operator|=
name|tablename
operator|.
name|toUpper
argument_list|()
expr_stmt|;
name|index
operator|=
name|db
operator|.
name|driver
argument_list|()
operator|->
name|primaryIndex
argument_list|(
name|db
operator|.
name|driver
argument_list|()
operator|->
name|escapeIdentifier
argument_list|(
name|tablename
argument_list|,
name|QSqlDriver
operator|::
name|TableName
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|tst_Databases
operator|::
name|isMySQL
argument_list|(
name|db
argument_list|)
operator|||
name|db
operator|.
name|driverName
argument_list|()
operator|.
name|startsWith
argument_list|(
literal|"QSQLITE"
argument_list|)
operator|||
name|db
operator|.
name|driverName
argument_list|()
operator|.
name|startsWith
argument_list|(
literal|"QTDS"
argument_list|)
operator|||
name|tst_Databases
operator|::
name|isSqlServer
argument_list|(
name|db
argument_list|)
operator|||
name|tst_Databases
operator|::
name|isMSAccess
argument_list|(
name|db
argument_list|)
condition|)
name|QCOMPARE
argument_list|(
name|index
operator|.
name|count
argument_list|()
argument_list|,
literal|1
argument_list|)
expr_stmt|;
comment|//mysql will always find the table name regardless of casing
else|else
name|QCOMPARE
argument_list|(
name|index
operator|.
name|count
argument_list|()
argument_list|,
literal|0
argument_list|)
expr_stmt|;
block|}
end_function
begin_macro
name|QTEST_MAIN
argument_list|(
argument|tst_QSqlDriver
argument_list|)
end_macro
begin_include
include|#
directive|include
file|"tst_qsqldriver.moc"
end_include
end_unit
