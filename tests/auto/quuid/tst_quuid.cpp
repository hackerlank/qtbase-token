begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** No Commercial Usage ** This file contains pre-release code and may not be distributed. ** You may use this file in accordance with the terms and conditions ** contained in the Technology Preview License Agreement accompanying ** this package. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights.  These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** If you have questions regarding the use of this file, please contact ** Nokia at qt-info@nokia.com. ** ** ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
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
file|<quuid.h>
end_include
begin_include
include|#
directive|include
file|<quuid.h>
end_include
begin_comment
comment|//TESTED_CLASS=
end_comment
begin_comment
comment|//TESTED_FILES=
end_comment
begin_class
DECL|class|tst_QUuid
class|class
name|tst_QUuid
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
public|public:
name|tst_QUuid
parameter_list|()
constructor_decl|;
private|private
name|slots
private|:
name|void
name|toString
parameter_list|()
function_decl|;
name|void
name|isNull
parameter_list|()
function_decl|;
name|void
name|equal
parameter_list|()
function_decl|;
name|void
name|notEqual
parameter_list|()
function_decl|;
comment|// Only in Qt> 3.2.x
name|void
name|generate
parameter_list|()
function_decl|;
name|void
name|less
parameter_list|()
function_decl|;
name|void
name|more
parameter_list|()
function_decl|;
name|void
name|variants
parameter_list|()
function_decl|;
name|void
name|versions
parameter_list|()
function_decl|;
name|void
name|threadUniqueness
parameter_list|()
function_decl|;
name|void
name|processUniqueness
parameter_list|()
function_decl|;
public|public:
comment|// Variables
DECL|member|uuidA
name|QUuid
name|uuidA
decl_stmt|;
DECL|member|uuidB
name|QUuid
name|uuidB
decl_stmt|;
block|}
class|;
end_class
begin_constructor
DECL|function|tst_QUuid
name|tst_QUuid
operator|::
name|tst_QUuid
parameter_list|()
block|{
name|uuidA
operator|=
literal|"{fc69b59e-cc34-4436-a43c-ee95d128b8c5}"
expr_stmt|;
name|uuidB
operator|=
literal|"{1ab6e93a-b1cb-4a87-ba47-ec7e99039a7b}"
expr_stmt|;
block|}
end_constructor
begin_function
DECL|function|toString
name|void
name|tst_QUuid
operator|::
name|toString
parameter_list|()
block|{
name|QCOMPARE
argument_list|(
name|uuidA
operator|.
name|toString
argument_list|()
argument_list|,
name|QString
argument_list|(
literal|"{fc69b59e-cc34-4436-a43c-ee95d128b8c5}"
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|isNull
name|void
name|tst_QUuid
operator|::
name|isNull
parameter_list|()
block|{
name|QVERIFY
argument_list|(
operator|!
name|uuidA
operator|.
name|isNull
argument_list|()
argument_list|)
expr_stmt|;
name|QUuid
name|should_be_null_uuid
decl_stmt|;
name|QVERIFY
argument_list|(
name|should_be_null_uuid
operator|.
name|isNull
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|equal
name|void
name|tst_QUuid
operator|::
name|equal
parameter_list|()
block|{
name|QVERIFY
argument_list|(
operator|!
operator|(
name|uuidA
operator|==
name|uuidB
operator|)
argument_list|)
expr_stmt|;
name|QUuid
name|copy
argument_list|(
name|uuidA
argument_list|)
decl_stmt|;
name|QVERIFY
argument_list|(
name|uuidA
operator|==
name|copy
argument_list|)
expr_stmt|;
name|QUuid
name|assigned
decl_stmt|;
name|assigned
operator|=
name|uuidA
expr_stmt|;
name|QVERIFY
argument_list|(
name|uuidA
operator|==
name|assigned
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|notEqual
name|void
name|tst_QUuid
operator|::
name|notEqual
parameter_list|()
block|{
name|QVERIFY
argument_list|(
name|uuidA
operator|!=
name|uuidB
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|generate
name|void
name|tst_QUuid
operator|::
name|generate
parameter_list|()
block|{
name|QUuid
name|shouldnt_be_null_uuidA
init|=
name|QUuid
operator|::
name|createUuid
argument_list|()
decl_stmt|;
name|QUuid
name|shouldnt_be_null_uuidB
init|=
name|QUuid
operator|::
name|createUuid
argument_list|()
decl_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|shouldnt_be_null_uuidA
operator|.
name|isNull
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|shouldnt_be_null_uuidB
operator|.
name|isNull
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|shouldnt_be_null_uuidA
operator|!=
name|shouldnt_be_null_uuidB
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|less
name|void
name|tst_QUuid
operator|::
name|less
parameter_list|()
block|{
name|QVERIFY
argument_list|(
operator|!
operator|(
name|uuidA
operator|<
name|uuidB
operator|)
argument_list|)
expr_stmt|;
name|QUuid
name|null_uuid
decl_stmt|;
name|QVERIFY
argument_list|(
name|null_uuid
operator|<
name|uuidA
argument_list|)
expr_stmt|;
comment|// Null uuid is always less than a valid one
block|}
end_function
begin_function
DECL|function|more
name|void
name|tst_QUuid
operator|::
name|more
parameter_list|()
block|{
name|QVERIFY
argument_list|(
name|uuidA
operator|>
name|uuidB
argument_list|)
expr_stmt|;
name|QUuid
name|null_uuid
decl_stmt|;
name|QVERIFY
argument_list|(
operator|!
operator|(
name|null_uuid
operator|>
name|uuidA
operator|)
argument_list|)
expr_stmt|;
comment|// Null uuid is always less than a valid one
block|}
end_function
begin_function
DECL|function|variants
name|void
name|tst_QUuid
operator|::
name|variants
parameter_list|()
block|{
name|QVERIFY
argument_list|(
name|uuidA
operator|.
name|variant
argument_list|()
operator|==
name|QUuid
operator|::
name|DCE
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|uuidB
operator|.
name|variant
argument_list|()
operator|==
name|QUuid
operator|::
name|DCE
argument_list|)
expr_stmt|;
name|QUuid
name|NCS
init|=
literal|"{3a2f883c-4000-000d-0000-00fb40000000}"
decl_stmt|;
name|QVERIFY
argument_list|(
name|NCS
operator|.
name|variant
argument_list|()
operator|==
name|QUuid
operator|::
name|NCS
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|versions
name|void
name|tst_QUuid
operator|::
name|versions
parameter_list|()
block|{
name|QVERIFY
argument_list|(
name|uuidA
operator|.
name|version
argument_list|()
operator|==
name|QUuid
operator|::
name|Random
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|uuidB
operator|.
name|version
argument_list|()
operator|==
name|QUuid
operator|::
name|Random
argument_list|)
expr_stmt|;
name|QUuid
name|DCE_time
init|=
literal|"{406c45a0-3b7e-11d0-80a3-0000c08810a7}"
decl_stmt|;
name|QVERIFY
argument_list|(
name|DCE_time
operator|.
name|version
argument_list|()
operator|==
name|QUuid
operator|::
name|Time
argument_list|)
expr_stmt|;
name|QUuid
name|NCS
init|=
literal|"{3a2f883c-4000-000d-0000-00fb40000000}"
decl_stmt|;
name|QVERIFY
argument_list|(
name|NCS
operator|.
name|version
argument_list|()
operator|==
name|QUuid
operator|::
name|VerUnknown
argument_list|)
expr_stmt|;
block|}
end_function
begin_class
DECL|class|UuidThread
class|class
name|UuidThread
super|:
specifier|public
name|QThread
block|{
public|public:
DECL|member|uuid
name|QUuid
name|uuid
decl_stmt|;
DECL|function|run
name|void
name|run
parameter_list|()
block|{
name|uuid
operator|=
name|QUuid
operator|::
name|createUuid
argument_list|()
expr_stmt|;
block|}
block|}
class|;
end_class
begin_function
DECL|function|threadUniqueness
name|void
name|tst_QUuid
operator|::
name|threadUniqueness
parameter_list|()
block|{
name|QVector
argument_list|<
name|UuidThread
modifier|*
argument_list|>
name|threads
argument_list|(
name|qMax
argument_list|(
literal|2
argument_list|,
name|QThread
operator|::
name|idealThreadCount
argument_list|()
argument_list|)
argument_list|)
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
name|threads
operator|.
name|count
argument_list|()
condition|;
operator|++
name|i
control|)
name|threads
index|[
name|i
index|]
operator|=
operator|new
name|UuidThread
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
name|threads
operator|.
name|count
argument_list|()
condition|;
operator|++
name|i
control|)
name|threads
index|[
name|i
index|]
operator|->
name|start
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
name|threads
operator|.
name|count
argument_list|()
condition|;
operator|++
name|i
control|)
name|QVERIFY
argument_list|(
name|threads
index|[
name|i
index|]
operator|->
name|wait
argument_list|(
literal|1000
argument_list|)
argument_list|)
expr_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|1
init|;
name|i
operator|<
name|threads
operator|.
name|count
argument_list|()
condition|;
operator|++
name|i
control|)
name|QVERIFY
argument_list|(
name|threads
index|[
literal|0
index|]
operator|->
name|uuid
operator|!=
name|threads
index|[
name|i
index|]
operator|->
name|uuid
argument_list|)
expr_stmt|;
name|qDeleteAll
argument_list|(
name|threads
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|processUniqueness
name|void
name|tst_QUuid
operator|::
name|processUniqueness
parameter_list|()
block|{
name|QProcess
name|process
decl_stmt|;
name|QString
name|processOneOutput
decl_stmt|;
name|QString
name|processTwoOutput
decl_stmt|;
comment|// Start it once
ifdef|#
directive|ifdef
name|Q_OS_MAC
name|process
operator|.
name|start
argument_list|(
literal|"testProcessUniqueness/testProcessUniqueness.app"
argument_list|)
expr_stmt|;
else|#
directive|else
name|process
operator|.
name|start
argument_list|(
literal|"testProcessUniqueness/testProcessUniqueness"
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|QVERIFY
argument_list|(
name|process
operator|.
name|waitForFinished
argument_list|()
argument_list|)
expr_stmt|;
name|processOneOutput
operator|=
name|process
operator|.
name|readAllStandardOutput
argument_list|()
expr_stmt|;
comment|// Start it twice
ifdef|#
directive|ifdef
name|Q_OS_MAC
name|process
operator|.
name|start
argument_list|(
literal|"testProcessUniqueness/testProcessUniqueness.app"
argument_list|)
expr_stmt|;
else|#
directive|else
name|process
operator|.
name|start
argument_list|(
literal|"testProcessUniqueness/testProcessUniqueness"
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|QVERIFY
argument_list|(
name|process
operator|.
name|waitForFinished
argument_list|()
argument_list|)
expr_stmt|;
name|processTwoOutput
operator|=
name|process
operator|.
name|readAllStandardOutput
argument_list|()
expr_stmt|;
comment|// They should be *different*!
name|QVERIFY
argument_list|(
name|processOneOutput
operator|!=
name|processTwoOutput
argument_list|)
expr_stmt|;
block|}
end_function
begin_macro
name|QTEST_MAIN
argument_list|(
argument|tst_QUuid
argument_list|)
end_macro
begin_include
include|#
directive|include
file|"tst_quuid.moc"
end_include
end_unit
