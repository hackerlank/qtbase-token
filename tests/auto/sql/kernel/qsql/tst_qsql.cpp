begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2014 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtTest/QtTest>
end_include
begin_include
include|#
directive|include
file|<qcoreapplication.h>
end_include
begin_include
include|#
directive|include
file|<qsqldatabase.h>
end_include
begin_include
include|#
directive|include
file|<qsqlerror.h>
end_include
begin_include
include|#
directive|include
file|<qsqlquery.h>
end_include
begin_include
include|#
directive|include
file|<qsqlrecord.h>
end_include
begin_include
include|#
directive|include
file|<qsql.h>
end_include
begin_include
include|#
directive|include
file|<qsqlresult.h>
end_include
begin_include
include|#
directive|include
file|<qsqldriver.h>
end_include
begin_include
include|#
directive|include
file|<qdebug.h>
end_include
begin_include
include|#
directive|include
file|<private/qsqlnulldriver_p.h>
end_include
begin_include
include|#
directive|include
file|"../qsqldatabase/tst_databases.h"
end_include
begin_class
DECL|class|tst_QSql
class|class
name|tst_QSql
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
public|public:
name|tst_QSql
parameter_list|()
constructor_decl|;
specifier|virtual
name|~
name|tst_QSql
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
name|void
name|open
parameter_list|()
function_decl|;
name|void
name|openInvalid
parameter_list|()
function_decl|;
name|void
name|registerSqlDriver
parameter_list|()
function_decl|;
comment|// problem specific tests
name|void
name|openErrorRecovery
parameter_list|()
function_decl|;
name|void
name|concurrentAccess
parameter_list|()
function_decl|;
name|void
name|basicDriverTest
parameter_list|()
function_decl|;
block|}
class|;
end_class
begin_comment
comment|/****************** General Qt SQL Module tests *****************/
end_comment
begin_constructor
DECL|function|tst_QSql
name|tst_QSql
operator|::
name|tst_QSql
parameter_list|()
block|{ }
end_constructor
begin_destructor
DECL|function|~tst_QSql
name|tst_QSql
operator|::
name|~
name|tst_QSql
parameter_list|()
block|{ }
end_destructor
begin_function
DECL|function|initTestCase
name|void
name|tst_QSql
operator|::
name|initTestCase
parameter_list|()
block|{ }
end_function
begin_function
DECL|function|cleanupTestCase
name|void
name|tst_QSql
operator|::
name|cleanupTestCase
parameter_list|()
block|{ }
end_function
begin_function
DECL|function|init
name|void
name|tst_QSql
operator|::
name|init
parameter_list|()
block|{ }
end_function
begin_function
DECL|function|cleanup
name|void
name|tst_QSql
operator|::
name|cleanup
parameter_list|()
block|{ }
end_function
begin_comment
comment|// this is a very basic test for drivers that cannot create/delete tables
end_comment
begin_comment
comment|// it can be used while developing new drivers,
end_comment
begin_comment
comment|// it's original purpose is to test ODBC Text datasources that are basically
end_comment
begin_comment
comment|// to stupid to do anything more advanced than SELECT/INSERT/UPDATE/DELETE
end_comment
begin_comment
comment|// the datasource has to have a table called "qtest_basictest" consisting
end_comment
begin_comment
comment|// of a field "id"(integer) and "name"(char/varchar).
end_comment
begin_function
DECL|function|basicDriverTest
name|void
name|tst_QSql
operator|::
name|basicDriverTest
parameter_list|()
block|{
name|int
name|argc
init|=
literal|1
decl_stmt|;
name|char
modifier|*
name|argv
index|[]
init|=
block|{
expr|const_cast
operator|<
name|char
operator|*
operator|>
operator|(
name|QTest
operator|::
name|currentAppName
argument_list|()
operator|)
block|}
decl_stmt|;
name|QCoreApplication
name|app
argument_list|(
name|argc
argument_list|,
name|argv
argument_list|,
literal|false
argument_list|)
decl_stmt|;
name|tst_Databases
name|dbs
decl_stmt|;
name|QVERIFY
argument_list|(
name|dbs
operator|.
name|open
argument_list|()
argument_list|)
expr_stmt|;
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
name|QVERIFY_SQL
argument_list|(
name|db
argument_list|,
name|isValid
argument_list|()
argument_list|)
expr_stmt|;
name|QStringList
name|tables
init|=
name|db
operator|.
name|tables
argument_list|()
decl_stmt|;
name|QString
name|tableName
decl_stmt|;
if|if
condition|(
name|tables
operator|.
name|contains
argument_list|(
literal|"qtest_basictest.txt"
argument_list|)
condition|)
name|tableName
operator|=
literal|"qtest_basictest.txt"
expr_stmt|;
elseif|else
if|if
condition|(
name|tables
operator|.
name|contains
argument_list|(
literal|"qtest_basictest"
argument_list|)
condition|)
name|tableName
operator|=
literal|"qtest_basictest"
expr_stmt|;
elseif|else
if|if
condition|(
name|tables
operator|.
name|contains
argument_list|(
literal|"QTEST_BASICTEST"
argument_list|)
condition|)
name|tableName
operator|=
literal|"QTEST_BASICTEST"
expr_stmt|;
else|else
block|{
name|QVERIFY
argument_list|(
literal|1
argument_list|)
expr_stmt|;
continue|continue;
block|}
name|qDebug
argument_list|(
literal|"Testing: %s"
argument_list|,
name|qPrintable
argument_list|(
name|tst_Databases
operator|::
name|dbToString
argument_list|(
name|db
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|QSqlRecord
name|rInf
init|=
name|db
operator|.
name|record
argument_list|(
name|tableName
argument_list|)
decl_stmt|;
name|QCOMPARE
argument_list|(
name|rInf
operator|.
name|count
argument_list|()
argument_list|,
literal|2
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|rInf
operator|.
name|fieldName
argument_list|(
literal|0
argument_list|)
operator|.
name|toLower
argument_list|()
argument_list|,
name|QString
argument_list|(
literal|"id"
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|rInf
operator|.
name|fieldName
argument_list|(
literal|1
argument_list|)
operator|.
name|toLower
argument_list|()
argument_list|,
name|QString
argument_list|(
literal|"name"
argument_list|)
argument_list|)
expr_stmt|;
block|}
name|dbs
operator|.
name|close
argument_list|()
expr_stmt|;
name|QVERIFY
argument_list|(
literal|1
argument_list|)
expr_stmt|;
comment|// make sure the test doesn't fail if no database drivers are there
block|}
end_function
begin_comment
comment|// make sure that the static stuff will be deleted
end_comment
begin_comment
comment|// when using multiple QCoreApplication objects
end_comment
begin_function
DECL|function|open
name|void
name|tst_QSql
operator|::
name|open
parameter_list|()
block|{
name|int
name|i
decl_stmt|;
name|int
name|argc
init|=
literal|1
decl_stmt|;
name|char
modifier|*
name|argv
index|[]
init|=
block|{
expr|const_cast
operator|<
name|char
operator|*
operator|>
operator|(
name|QTest
operator|::
name|currentAppName
argument_list|()
operator|)
block|}
decl_stmt|;
name|int
name|count
init|=
operator|-
literal|1
decl_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
literal|10
condition|;
operator|++
name|i
control|)
block|{
name|QCoreApplication
name|app
argument_list|(
name|argc
argument_list|,
name|argv
argument_list|,
literal|false
argument_list|)
decl_stmt|;
name|tst_Databases
name|dbs
decl_stmt|;
name|QVERIFY
argument_list|(
name|dbs
operator|.
name|open
argument_list|()
argument_list|)
expr_stmt|;
if|if
condition|(
name|count
operator|==
operator|-
literal|1
condition|)
comment|// first iteration: see how many dbs are open
name|count
operator|=
operator|(
name|int
operator|)
name|dbs
operator|.
name|dbNames
operator|.
name|count
argument_list|()
expr_stmt|;
else|else
comment|// next iterations: make sure all are opened again
name|QCOMPARE
argument_list|(
name|count
argument_list|,
operator|(
name|int
operator|)
name|dbs
operator|.
name|dbNames
operator|.
name|count
argument_list|()
argument_list|)
expr_stmt|;
name|dbs
operator|.
name|close
argument_list|()
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|openInvalid
name|void
name|tst_QSql
operator|::
name|openInvalid
parameter_list|()
block|{
name|QSqlDatabase
name|db
decl_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|db
operator|.
name|open
argument_list|()
argument_list|)
expr_stmt|;
name|QSqlDatabase
name|db2
init|=
name|QSqlDatabase
operator|::
name|addDatabase
argument_list|(
literal|"doesnt_exist_will_never_exist"
argument_list|,
literal|"blah"
argument_list|)
decl_stmt|;
name|QFAIL_SQL
argument_list|(
name|db2
argument_list|,
name|open
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|concurrentAccess
name|void
name|tst_QSql
operator|::
name|concurrentAccess
parameter_list|()
block|{
name|int
name|argc
init|=
literal|1
decl_stmt|;
name|char
modifier|*
name|argv
index|[]
init|=
block|{
expr|const_cast
operator|<
name|char
operator|*
operator|>
operator|(
name|QTest
operator|::
name|currentAppName
argument_list|()
operator|)
block|}
decl_stmt|;
name|QCoreApplication
name|app
argument_list|(
name|argc
argument_list|,
name|argv
argument_list|,
literal|false
argument_list|)
decl_stmt|;
name|tst_Databases
name|dbs
decl_stmt|;
name|QVERIFY
argument_list|(
name|dbs
operator|.
name|open
argument_list|()
argument_list|)
expr_stmt|;
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
name|QVERIFY
argument_list|(
name|db
operator|.
name|isValid
argument_list|()
argument_list|)
expr_stmt|;
if|if
condition|(
name|tst_Databases
operator|::
name|isMSAccess
argument_list|(
name|db
argument_list|)
condition|)
continue|continue;
name|QSqlDatabase
name|ndb
init|=
name|QSqlDatabase
operator|::
name|addDatabase
argument_list|(
name|db
operator|.
name|driverName
argument_list|()
argument_list|,
literal|"tst_QSql::concurrentAccess"
argument_list|)
decl_stmt|;
name|ndb
operator|.
name|setDatabaseName
argument_list|(
name|db
operator|.
name|databaseName
argument_list|()
argument_list|)
expr_stmt|;
name|ndb
operator|.
name|setHostName
argument_list|(
name|db
operator|.
name|hostName
argument_list|()
argument_list|)
expr_stmt|;
name|ndb
operator|.
name|setPort
argument_list|(
name|db
operator|.
name|port
argument_list|()
argument_list|)
expr_stmt|;
name|ndb
operator|.
name|setUserName
argument_list|(
name|db
operator|.
name|userName
argument_list|()
argument_list|)
expr_stmt|;
name|ndb
operator|.
name|setPassword
argument_list|(
name|db
operator|.
name|password
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY_SQL
argument_list|(
name|ndb
argument_list|,
name|open
argument_list|()
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|db
operator|.
name|tables
argument_list|()
argument_list|,
name|ndb
operator|.
name|tables
argument_list|()
argument_list|)
expr_stmt|;
name|ndb
operator|.
name|close
argument_list|()
expr_stmt|;
block|}
comment|// no database servers installed - don't fail
name|QVERIFY
argument_list|(
literal|1
argument_list|)
expr_stmt|;
name|dbs
operator|.
name|close
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|openErrorRecovery
name|void
name|tst_QSql
operator|::
name|openErrorRecovery
parameter_list|()
block|{
name|int
name|argc
init|=
literal|1
decl_stmt|;
name|char
modifier|*
name|argv
index|[]
init|=
block|{
expr|const_cast
operator|<
name|char
operator|*
operator|>
operator|(
name|QTest
operator|::
name|currentAppName
argument_list|()
operator|)
block|}
decl_stmt|;
name|QCoreApplication
name|app
argument_list|(
name|argc
argument_list|,
name|argv
argument_list|,
literal|false
argument_list|)
decl_stmt|;
name|tst_Databases
name|dbs
decl_stmt|;
name|QVERIFY
argument_list|(
name|dbs
operator|.
name|addDbs
argument_list|()
argument_list|)
expr_stmt|;
if|if
condition|(
name|dbs
operator|.
name|dbNames
operator|.
name|isEmpty
argument_list|()
condition|)
name|QSKIP
argument_list|(
literal|"No database drivers installed"
argument_list|)
expr_stmt|;
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
argument_list|,
literal|false
argument_list|)
decl_stmt|;
name|CHECK_DATABASE
argument_list|(
name|db
argument_list|)
expr_stmt|;
name|QString
name|userName
init|=
name|db
operator|.
name|userName
argument_list|()
decl_stmt|;
name|QString
name|password
init|=
name|db
operator|.
name|password
argument_list|()
decl_stmt|;
comment|// force an open error
if|if
condition|(
name|db
operator|.
name|open
argument_list|(
literal|"dummy130977"
argument_list|,
literal|"doesnt_exist"
argument_list|)
condition|)
block|{
name|qDebug
argument_list|(
literal|"Promiscuous database server without access control - test skipped for %s"
argument_list|,
name|qPrintable
argument_list|(
name|tst_Databases
operator|::
name|dbToString
argument_list|(
name|db
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
literal|1
argument_list|)
expr_stmt|;
continue|continue;
block|}
name|QFAIL_SQL
argument_list|(
name|db
argument_list|,
name|isOpen
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY_SQL
argument_list|(
name|db
argument_list|,
name|isOpenError
argument_list|()
argument_list|)
expr_stmt|;
comment|// now open it
if|if
condition|(
operator|!
name|db
operator|.
name|open
argument_list|(
name|userName
argument_list|,
name|password
argument_list|)
condition|)
block|{
name|qDebug
argument_list|()
operator|<<
literal|"Could not open Database "
operator|<<
name|tst_Databases
operator|::
name|dbToString
argument_list|(
name|db
argument_list|)
operator|<<
literal|". Assuming DB is down, skipping... (Error: "
operator|<<
name|tst_Databases
operator|::
name|printError
argument_list|(
name|db
operator|.
name|lastError
argument_list|()
argument_list|)
operator|<<
literal|")"
expr_stmt|;
continue|continue;
block|}
name|QVERIFY_SQL
argument_list|(
name|db
argument_list|,
name|open
argument_list|(
name|userName
argument_list|,
name|password
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY_SQL
argument_list|(
name|db
argument_list|,
name|isOpen
argument_list|()
argument_list|)
expr_stmt|;
name|QFAIL_SQL
argument_list|(
name|db
argument_list|,
name|isOpenError
argument_list|()
argument_list|)
expr_stmt|;
name|db
operator|.
name|close
argument_list|()
expr_stmt|;
name|QFAIL_SQL
argument_list|(
name|db
argument_list|,
name|isOpen
argument_list|()
argument_list|)
expr_stmt|;
comment|// force another open error
name|QFAIL_SQL
argument_list|(
name|db
argument_list|,
name|open
argument_list|(
literal|"dummy130977"
argument_list|,
literal|"doesnt_exist"
argument_list|)
argument_list|)
expr_stmt|;
name|QFAIL_SQL
argument_list|(
name|db
argument_list|,
name|isOpen
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY_SQL
argument_list|(
name|db
argument_list|,
name|isOpenError
argument_list|()
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|registerSqlDriver
name|void
name|tst_QSql
operator|::
name|registerSqlDriver
parameter_list|()
block|{
name|int
name|argc
init|=
literal|1
decl_stmt|;
name|char
modifier|*
name|argv
index|[]
init|=
block|{
expr|const_cast
operator|<
name|char
operator|*
operator|>
operator|(
name|QTest
operator|::
name|currentAppName
argument_list|()
operator|)
block|}
decl_stmt|;
name|QCoreApplication
name|app
argument_list|(
name|argc
argument_list|,
name|argv
argument_list|,
literal|false
argument_list|)
decl_stmt|;
name|QSqlDatabase
operator|::
name|registerSqlDriver
argument_list|(
literal|"QSQLTESTDRIVER"
argument_list|,
operator|new
name|QSqlDriverCreator
argument_list|<
name|QSqlNullDriver
argument_list|>
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|QSqlDatabase
operator|::
name|drivers
argument_list|()
operator|.
name|contains
argument_list|(
literal|"QSQLTESTDRIVER"
argument_list|)
argument_list|)
expr_stmt|;
name|QSqlDatabase
name|db
init|=
name|QSqlDatabase
operator|::
name|addDatabase
argument_list|(
literal|"QSQLTESTDRIVER"
argument_list|)
decl_stmt|;
name|QVERIFY
argument_list|(
name|db
operator|.
name|isValid
argument_list|()
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|db
operator|.
name|tables
argument_list|()
argument_list|,
name|QStringList
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_macro
name|QTEST_APPLESS_MAIN
argument_list|(
argument|tst_QSql
argument_list|)
end_macro
begin_include
include|#
directive|include
file|"tst_qsql.moc"
end_include
end_unit
