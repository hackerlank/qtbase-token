begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
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
file|"../../../../auto/sql/kernel/qsqldatabase/tst_databases.h"
end_include
begin_decl_stmt
specifier|const
name|QString
name|qtest
argument_list|(
name|qTableName
argument_list|(
literal|"qtest"
argument_list|,
name|__FILE__
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt
begin_class
DECL|class|tst_QSqlQuery
class|class
name|tst_QSqlQuery
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
public|public:
name|tst_QSqlQuery
parameter_list|()
constructor_decl|;
specifier|virtual
name|~
name|tst_QSqlQuery
parameter_list|()
destructor_decl|;
public|public
name|slots
public|:
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
DECL|function|benchmark_data
name|void
name|benchmark_data
parameter_list|()
block|{
name|generic_data
argument_list|()
expr_stmt|;
block|}
name|void
name|benchmark
parameter_list|()
function_decl|;
private|private:
comment|// returns all database connections
name|void
name|generic_data
parameter_list|(
specifier|const
name|QString
modifier|&
name|engine
init|=
name|QString
argument_list|()
parameter_list|)
function_decl|;
name|void
name|dropTestTables
parameter_list|(
name|QSqlDatabase
name|db
parameter_list|)
function_decl|;
name|void
name|createTestTables
parameter_list|(
name|QSqlDatabase
name|db
parameter_list|)
function_decl|;
name|void
name|populateTestTables
parameter_list|(
name|QSqlDatabase
name|db
parameter_list|)
function_decl|;
DECL|member|dbs
name|tst_Databases
name|dbs
decl_stmt|;
block|}
class|;
end_class
begin_macro
name|QTEST_MAIN
argument_list|(
argument|tst_QSqlQuery
argument_list|)
end_macro
begin_constructor
DECL|function|tst_QSqlQuery
name|tst_QSqlQuery
operator|::
name|tst_QSqlQuery
parameter_list|()
block|{ }
end_constructor
begin_destructor
DECL|function|~tst_QSqlQuery
name|tst_QSqlQuery
operator|::
name|~
name|tst_QSqlQuery
parameter_list|()
block|{ }
end_destructor
begin_function
DECL|function|initTestCase
name|void
name|tst_QSqlQuery
operator|::
name|initTestCase
parameter_list|()
block|{
name|dbs
operator|.
name|open
argument_list|()
expr_stmt|;
for|for
control|(
name|QStringList
operator|::
name|ConstIterator
name|it
init|=
name|dbs
operator|.
name|dbNames
operator|.
name|begin
argument_list|()
init|;
name|it
operator|!=
name|dbs
operator|.
name|dbNames
operator|.
name|end
argument_list|()
condition|;
operator|++
name|it
control|)
block|{
name|QSqlDatabase
name|db
init|=
name|QSqlDatabase
operator|::
name|database
argument_list|(
operator|(
operator|*
name|it
operator|)
argument_list|)
decl_stmt|;
name|CHECK_DATABASE
argument_list|(
name|db
argument_list|)
expr_stmt|;
name|dropTestTables
argument_list|(
name|db
argument_list|)
expr_stmt|;
comment|//in case of leftovers
name|createTestTables
argument_list|(
name|db
argument_list|)
expr_stmt|;
name|populateTestTables
argument_list|(
name|db
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|cleanupTestCase
name|void
name|tst_QSqlQuery
operator|::
name|cleanupTestCase
parameter_list|()
block|{
for|for
control|(
name|QStringList
operator|::
name|ConstIterator
name|it
init|=
name|dbs
operator|.
name|dbNames
operator|.
name|begin
argument_list|()
init|;
name|it
operator|!=
name|dbs
operator|.
name|dbNames
operator|.
name|end
argument_list|()
condition|;
operator|++
name|it
control|)
block|{
name|QSqlDatabase
name|db
init|=
name|QSqlDatabase
operator|::
name|database
argument_list|(
operator|(
operator|*
name|it
operator|)
argument_list|)
decl_stmt|;
name|CHECK_DATABASE
argument_list|(
name|db
argument_list|)
expr_stmt|;
name|dropTestTables
argument_list|(
name|db
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
name|tst_QSqlQuery
operator|::
name|init
parameter_list|()
block|{ }
end_function
begin_function
DECL|function|cleanup
name|void
name|tst_QSqlQuery
operator|::
name|cleanup
parameter_list|()
block|{
name|QFETCH
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
if|if
condition|(
name|QTest
operator|::
name|currentTestFunction
argument_list|()
operator|==
name|QLatin1String
argument_list|(
literal|"numRowsAffected"
argument_list|)
operator|||
name|QTest
operator|::
name|currentTestFunction
argument_list|()
operator|==
name|QLatin1String
argument_list|(
literal|"transactions"
argument_list|)
operator|||
name|QTest
operator|::
name|currentTestFunction
argument_list|()
operator|==
name|QLatin1String
argument_list|(
literal|"size"
argument_list|)
operator|||
name|QTest
operator|::
name|currentTestFunction
argument_list|()
operator|==
name|QLatin1String
argument_list|(
literal|"isActive"
argument_list|)
operator|||
name|QTest
operator|::
name|currentTestFunction
argument_list|()
operator|==
name|QLatin1String
argument_list|(
literal|"lastInsertId"
argument_list|)
condition|)
block|{
name|populateTestTables
argument_list|(
name|db
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|QTest
operator|::
name|currentTestFailed
argument_list|()
operator|&&
operator|(
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
literal|"QODBC"
argument_list|)
operator|)
condition|)
block|{
comment|//since Oracle ODBC totally craps out on error, we init again
name|db
operator|.
name|close
argument_list|()
expr_stmt|;
name|db
operator|.
name|open
argument_list|()
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|generic_data
name|void
name|tst_QSqlQuery
operator|::
name|generic_data
parameter_list|(
specifier|const
name|QString
modifier|&
name|engine
parameter_list|)
block|{
if|if
condition|(
name|dbs
operator|.
name|fillTestTable
argument_list|(
name|engine
argument_list|)
operator|==
literal|0
condition|)
block|{
if|if
condition|(
name|engine
operator|.
name|isEmpty
argument_list|()
condition|)
name|QSKIP
argument_list|(
literal|"No database drivers are available in this Qt configuration"
argument_list|)
expr_stmt|;
else|else
name|QSKIP
argument_list|(
operator|(
name|QString
argument_list|(
literal|"No database drivers of type %1 are available in this Qt configuration"
argument_list|)
operator|.
name|arg
argument_list|(
name|engine
argument_list|)
operator|)
operator|.
name|toLocal8Bit
argument_list|()
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|dropTestTables
name|void
name|tst_QSqlQuery
operator|::
name|dropTestTables
parameter_list|(
name|QSqlDatabase
name|db
parameter_list|)
block|{
name|QStringList
name|tablenames
decl_stmt|;
comment|// drop all the table in case a testcase failed
name|tablenames
operator|<<
name|qtest
operator|<<
name|qTableName
argument_list|(
literal|"qtest_null"
argument_list|,
name|__FILE__
argument_list|)
operator|<<
name|qTableName
argument_list|(
literal|"qtest_blob"
argument_list|,
name|__FILE__
argument_list|)
operator|<<
name|qTableName
argument_list|(
literal|"qtest_bittest"
argument_list|,
name|__FILE__
argument_list|)
operator|<<
name|qTableName
argument_list|(
literal|"qtest_nullblob"
argument_list|,
name|__FILE__
argument_list|)
operator|<<
name|qTableName
argument_list|(
literal|"qtest_rawtest"
argument_list|,
name|__FILE__
argument_list|)
operator|<<
name|qTableName
argument_list|(
literal|"qtest_precision"
argument_list|,
name|__FILE__
argument_list|)
operator|<<
name|qTableName
argument_list|(
literal|"qtest_prepare"
argument_list|,
name|__FILE__
argument_list|)
operator|<<
name|qTableName
argument_list|(
literal|"qtestj1"
argument_list|,
name|__FILE__
argument_list|)
operator|<<
name|qTableName
argument_list|(
literal|"qtestj2"
argument_list|,
name|__FILE__
argument_list|)
operator|<<
name|qTableName
argument_list|(
literal|"char1Select"
argument_list|,
name|__FILE__
argument_list|)
operator|<<
name|qTableName
argument_list|(
literal|"char1SU"
argument_list|,
name|__FILE__
argument_list|)
operator|<<
name|qTableName
argument_list|(
literal|"qxmltest"
argument_list|,
name|__FILE__
argument_list|)
operator|<<
name|qTableName
argument_list|(
literal|"qtest_exerr"
argument_list|,
name|__FILE__
argument_list|)
operator|<<
name|qTableName
argument_list|(
literal|"qtest_empty"
argument_list|,
name|__FILE__
argument_list|)
operator|<<
name|qTableName
argument_list|(
literal|"clobby"
argument_list|,
name|__FILE__
argument_list|)
operator|<<
name|qTableName
argument_list|(
literal|"bindtest"
argument_list|,
name|__FILE__
argument_list|)
operator|<<
name|qTableName
argument_list|(
literal|"more_results"
argument_list|,
name|__FILE__
argument_list|)
operator|<<
name|qTableName
argument_list|(
literal|"blobstest"
argument_list|,
name|__FILE__
argument_list|)
operator|<<
name|qTableName
argument_list|(
literal|"oraRowId"
argument_list|,
name|__FILE__
argument_list|)
operator|<<
name|qTableName
argument_list|(
literal|"qtest_batch"
argument_list|,
name|__FILE__
argument_list|)
operator|<<
name|qTableName
argument_list|(
literal|"bug6421"
argument_list|,
name|__FILE__
argument_list|)
operator|.
name|toUpper
argument_list|()
operator|<<
name|qTableName
argument_list|(
literal|"bug5765"
argument_list|,
name|__FILE__
argument_list|)
operator|<<
name|qTableName
argument_list|(
literal|"bug6852"
argument_list|,
name|__FILE__
argument_list|)
operator|<<
name|qTableName
argument_list|(
literal|"qtest_lockedtable"
argument_list|,
name|__FILE__
argument_list|)
operator|<<
name|qTableName
argument_list|(
literal|"Planet"
argument_list|,
name|__FILE__
argument_list|)
operator|<<
name|qTableName
argument_list|(
literal|"task_250026"
argument_list|,
name|__FILE__
argument_list|)
operator|<<
name|qTableName
argument_list|(
literal|"task_234422"
argument_list|,
name|__FILE__
argument_list|)
operator|<<
name|qTableName
argument_list|(
literal|"test141895"
argument_list|,
name|__FILE__
argument_list|)
operator|<<
name|qTableName
argument_list|(
literal|"qtest_oraOCINumber"
argument_list|,
name|__FILE__
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
literal|"QPSQL"
argument_list|)
condition|)
name|tablenames
operator|<<
name|qTableName
argument_list|(
literal|"task_233829"
argument_list|,
name|__FILE__
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
literal|"QSQLITE"
argument_list|)
condition|)
name|tablenames
operator|<<
name|qTableName
argument_list|(
literal|"record_sqlite"
argument_list|,
name|__FILE__
argument_list|)
expr_stmt|;
if|if
condition|(
name|tst_Databases
operator|::
name|isSqlServer
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
literal|"QOCI"
argument_list|)
condition|)
name|tablenames
operator|<<
name|qTableName
argument_list|(
literal|"qtest_longstr"
argument_list|,
name|__FILE__
argument_list|)
expr_stmt|;
if|if
condition|(
name|tst_Databases
operator|::
name|isSqlServer
argument_list|(
name|db
argument_list|)
condition|)
name|db
operator|.
name|exec
argument_list|(
literal|"DROP PROCEDURE "
operator|+
name|qTableName
argument_list|(
literal|"test141895_proc"
argument_list|,
name|__FILE__
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
condition|)
name|db
operator|.
name|exec
argument_list|(
literal|"DROP PROCEDURE IF EXISTS "
operator|+
name|qTableName
argument_list|(
literal|"bug6852_proc"
argument_list|,
name|__FILE__
argument_list|)
argument_list|)
expr_stmt|;
name|tst_Databases
operator|::
name|safeDropTables
argument_list|(
name|db
argument_list|,
name|tablenames
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
literal|"QOCI"
argument_list|)
condition|)
block|{
name|QSqlQuery
name|q
argument_list|(
name|db
argument_list|)
decl_stmt|;
name|q
operator|.
name|exec
argument_list|(
literal|"DROP PACKAGE "
operator|+
name|qTableName
argument_list|(
literal|"pkg"
argument_list|,
name|__FILE__
argument_list|)
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|createTestTables
name|void
name|tst_QSqlQuery
operator|::
name|createTestTables
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
if|if
condition|(
name|db
operator|.
name|driverName
argument_list|()
operator|.
name|startsWith
argument_list|(
literal|"QMYSQL"
argument_list|)
condition|)
comment|// ### stupid workaround until we find a way to hardcode this
comment|// in the MySQL server startup script
name|q
operator|.
name|exec
argument_list|(
literal|"set table_type=innodb"
argument_list|)
expr_stmt|;
elseif|else
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
literal|"create table "
operator|+
name|qtest
operator|+
literal|" (id serial NOT NULL, t_varchar varchar(20), t_char char(20), primary key(id)) WITH OIDS"
argument_list|)
argument_list|)
expr_stmt|;
else|else
name|QVERIFY_SQL
argument_list|(
name|q
argument_list|,
name|exec
argument_list|(
literal|"create table "
operator|+
name|qtest
operator|+
literal|" (id int "
operator|+
name|tst_Databases
operator|::
name|autoFieldName
argument_list|(
name|db
argument_list|)
operator|+
literal|" NOT NULL, t_varchar varchar(20), t_char char(20), primary key(id))"
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|tst_Databases
operator|::
name|isSqlServer
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
literal|"QTDS"
argument_list|)
condition|)
name|QVERIFY_SQL
argument_list|(
name|q
argument_list|,
name|exec
argument_list|(
literal|"create table "
operator|+
name|qTableName
argument_list|(
literal|"qtest_null"
argument_list|,
name|__FILE__
argument_list|)
operator|+
literal|" (id int null, t_varchar varchar(20) null)"
argument_list|)
argument_list|)
expr_stmt|;
else|else
name|QVERIFY_SQL
argument_list|(
name|q
argument_list|,
name|exec
argument_list|(
literal|"create table "
operator|+
name|qTableName
argument_list|(
literal|"qtest_null"
argument_list|,
name|__FILE__
argument_list|)
operator|+
literal|" (id int, t_varchar varchar(20))"
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|populateTestTables
name|void
name|tst_QSqlQuery
operator|::
name|populateTestTables
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
name|qtest_null
argument_list|(
name|qTableName
argument_list|(
literal|"qtest_null"
argument_list|,
name|__FILE__
argument_list|)
argument_list|)
decl_stmt|;
name|q
operator|.
name|exec
argument_list|(
literal|"delete from "
operator|+
name|qtest
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
name|qtest
operator|+
literal|" values (1, 'VarChar1', 'Char1')"
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
name|qtest
operator|+
literal|" values (2, 'VarChar2', 'Char2')"
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
name|qtest
operator|+
literal|" values (3, 'VarChar3', 'Char3')"
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
name|qtest
operator|+
literal|" values (4, 'VarChar4', 'Char4')"
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
name|qtest
operator|+
literal|" values (5, 'VarChar5', 'Char5')"
argument_list|)
argument_list|)
expr_stmt|;
name|q
operator|.
name|exec
argument_list|(
literal|"delete from "
operator|+
name|qtest_null
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
name|qtest_null
operator|+
literal|" values (0, NULL)"
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
name|qtest_null
operator|+
literal|" values (1, 'n')"
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
name|qtest_null
operator|+
literal|" values (2, 'i')"
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
name|qtest_null
operator|+
literal|" values (3, NULL)"
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|benchmark
name|void
name|tst_QSqlQuery
operator|::
name|benchmark
parameter_list|()
block|{
name|QFETCH
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
if|if
condition|(
name|tst_Databases
operator|::
name|getMySqlVersion
argument_list|(
name|db
argument_list|)
operator|.
name|section
argument_list|(
name|QChar
argument_list|(
literal|'.'
argument_list|)
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
operator|.
name|toInt
argument_list|()
operator|<
literal|5
condition|)
name|QSKIP
argument_list|(
literal|"Test requires MySQL>= 5.0"
argument_list|)
expr_stmt|;
name|QSqlQuery
name|q
argument_list|(
name|db
argument_list|)
decl_stmt|;
specifier|const
name|QString
name|tableName
argument_list|(
name|qTableName
argument_list|(
literal|"benchmark"
argument_list|,
name|__FILE__
argument_list|)
argument_list|)
decl_stmt|;
name|tst_Databases
operator|::
name|safeDropTable
argument_list|(
name|db
argument_list|,
name|tableName
argument_list|)
expr_stmt|;
name|QVERIFY_SQL
argument_list|(
name|q
argument_list|,
name|exec
argument_list|(
literal|"CREATE TABLE "
operator|+
name|tableName
operator|+
literal|"(\n"
literal|"MainKey INT NOT NULL,\n"
literal|"OtherTextCol VARCHAR(45) NOT NULL,\n"
literal|"PRIMARY KEY(`MainKey`))"
argument_list|)
argument_list|)
expr_stmt|;
name|int
name|i
init|=
literal|1
decl_stmt|;
name|QBENCHMARK
block|{
name|QVERIFY_SQL
argument_list|(
name|q
argument_list|,
name|exec
argument_list|(
literal|"INSERT INTO "
operator|+
name|tableName
operator|+
literal|" VALUES("
operator|+
name|QString
operator|::
name|number
argument_list|(
name|i
argument_list|)
operator|+
literal|", \"Value"
operator|+
name|QString
operator|::
name|number
argument_list|(
name|i
argument_list|)
operator|+
literal|"\")"
argument_list|)
argument_list|)
expr_stmt|;
name|i
operator|++
expr_stmt|;
block|}
name|tst_Databases
operator|::
name|safeDropTable
argument_list|(
name|db
argument_list|,
name|tableName
argument_list|)
expr_stmt|;
block|}
end_function
begin_include
include|#
directive|include
file|"main.moc"
end_include
end_unit
