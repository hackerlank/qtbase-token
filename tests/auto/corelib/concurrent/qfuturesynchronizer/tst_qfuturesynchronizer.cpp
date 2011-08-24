begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtTest>
end_include
begin_include
include|#
directive|include
file|<QtCore/qfuturesynchronizer.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qfuture.h>
end_include
begin_class
DECL|class|tst_QFutureSynchronizer
class|class
name|tst_QFutureSynchronizer
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
private|private
name|Q_SLOTS
private|:
name|void
name|construction
parameter_list|()
function_decl|;
name|void
name|addFuture
parameter_list|()
function_decl|;
name|void
name|cancelOnWait
parameter_list|()
function_decl|;
name|void
name|clearFutures
parameter_list|()
function_decl|;
name|void
name|futures
parameter_list|()
function_decl|;
name|void
name|setFuture
parameter_list|()
function_decl|;
name|void
name|waitForFinished
parameter_list|()
function_decl|;
block|}
class|;
end_class
begin_function
DECL|function|construction
name|void
name|tst_QFutureSynchronizer
operator|::
name|construction
parameter_list|()
block|{
name|QFuture
argument_list|<
name|void
argument_list|>
name|future
decl_stmt|;
name|QFutureSynchronizer
argument_list|<
name|void
argument_list|>
name|synchronizer
decl_stmt|;
name|QFutureSynchronizer
argument_list|<
name|void
argument_list|>
name|synchronizerWithFuture
argument_list|(
name|future
argument_list|)
decl_stmt|;
name|QCOMPARE
argument_list|(
name|synchronizer
operator|.
name|futures
argument_list|()
operator|.
name|size
argument_list|()
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|synchronizerWithFuture
operator|.
name|futures
argument_list|()
operator|.
name|size
argument_list|()
argument_list|,
literal|1
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|addFuture
name|void
name|tst_QFutureSynchronizer
operator|::
name|addFuture
parameter_list|()
block|{
name|QFutureSynchronizer
argument_list|<
name|void
argument_list|>
name|synchronizer
decl_stmt|;
name|synchronizer
operator|.
name|addFuture
argument_list|(
name|QFuture
argument_list|<
name|void
argument_list|>
argument_list|()
argument_list|)
expr_stmt|;
name|QFuture
argument_list|<
name|void
argument_list|>
name|future
decl_stmt|;
name|synchronizer
operator|.
name|addFuture
argument_list|(
name|future
argument_list|)
expr_stmt|;
name|synchronizer
operator|.
name|addFuture
argument_list|(
name|future
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|synchronizer
operator|.
name|futures
argument_list|()
operator|.
name|size
argument_list|()
argument_list|,
literal|3
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|cancelOnWait
name|void
name|tst_QFutureSynchronizer
operator|::
name|cancelOnWait
parameter_list|()
block|{
name|QFutureSynchronizer
argument_list|<
name|void
argument_list|>
name|synchronizer
decl_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|synchronizer
operator|.
name|cancelOnWait
argument_list|()
argument_list|)
expr_stmt|;
name|synchronizer
operator|.
name|setCancelOnWait
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|synchronizer
operator|.
name|cancelOnWait
argument_list|()
argument_list|)
expr_stmt|;
name|synchronizer
operator|.
name|setCancelOnWait
argument_list|(
literal|false
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|synchronizer
operator|.
name|cancelOnWait
argument_list|()
argument_list|)
expr_stmt|;
name|synchronizer
operator|.
name|setCancelOnWait
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|synchronizer
operator|.
name|cancelOnWait
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|clearFutures
name|void
name|tst_QFutureSynchronizer
operator|::
name|clearFutures
parameter_list|()
block|{
name|QFutureSynchronizer
argument_list|<
name|void
argument_list|>
name|synchronizer
decl_stmt|;
name|synchronizer
operator|.
name|clearFutures
argument_list|()
expr_stmt|;
name|QVERIFY
argument_list|(
name|synchronizer
operator|.
name|futures
argument_list|()
operator|.
name|isEmpty
argument_list|()
argument_list|)
expr_stmt|;
name|synchronizer
operator|.
name|addFuture
argument_list|(
name|QFuture
argument_list|<
name|void
argument_list|>
argument_list|()
argument_list|)
expr_stmt|;
name|QFuture
argument_list|<
name|void
argument_list|>
name|future
decl_stmt|;
name|synchronizer
operator|.
name|addFuture
argument_list|(
name|future
argument_list|)
expr_stmt|;
name|synchronizer
operator|.
name|addFuture
argument_list|(
name|future
argument_list|)
expr_stmt|;
name|synchronizer
operator|.
name|clearFutures
argument_list|()
expr_stmt|;
name|QVERIFY
argument_list|(
name|synchronizer
operator|.
name|futures
argument_list|()
operator|.
name|isEmpty
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|futures
name|void
name|tst_QFutureSynchronizer
operator|::
name|futures
parameter_list|()
block|{
name|QFutureSynchronizer
argument_list|<
name|void
argument_list|>
name|synchronizer
decl_stmt|;
name|QList
argument_list|<
name|QFuture
argument_list|<
name|void
argument_list|>
argument_list|>
name|futures
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
literal|100
condition|;
name|i
operator|++
control|)
block|{
name|QFuture
argument_list|<
name|void
argument_list|>
name|future
decl_stmt|;
name|futures
operator|.
name|append
argument_list|(
name|future
argument_list|)
expr_stmt|;
name|synchronizer
operator|.
name|addFuture
argument_list|(
name|future
argument_list|)
expr_stmt|;
block|}
name|QCOMPARE
argument_list|(
name|futures
argument_list|,
name|synchronizer
operator|.
name|futures
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|setFuture
name|void
name|tst_QFutureSynchronizer
operator|::
name|setFuture
parameter_list|()
block|{
name|QFutureSynchronizer
argument_list|<
name|void
argument_list|>
name|synchronizer
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
literal|100
condition|;
name|i
operator|++
control|)
block|{
name|synchronizer
operator|.
name|addFuture
argument_list|(
name|QFuture
argument_list|<
name|void
argument_list|>
argument_list|()
argument_list|)
expr_stmt|;
block|}
name|QCOMPARE
argument_list|(
name|synchronizer
operator|.
name|futures
argument_list|()
operator|.
name|size
argument_list|()
argument_list|,
literal|100
argument_list|)
expr_stmt|;
name|QFuture
argument_list|<
name|void
argument_list|>
name|future
decl_stmt|;
name|synchronizer
operator|.
name|setFuture
argument_list|(
name|future
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|synchronizer
operator|.
name|futures
argument_list|()
operator|.
name|size
argument_list|()
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|synchronizer
operator|.
name|futures
argument_list|()
operator|.
name|first
argument_list|()
argument_list|,
name|future
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|waitForFinished
name|void
name|tst_QFutureSynchronizer
operator|::
name|waitForFinished
parameter_list|()
block|{
name|QFutureSynchronizer
argument_list|<
name|void
argument_list|>
name|synchronizer
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
literal|100
condition|;
name|i
operator|++
control|)
block|{
name|synchronizer
operator|.
name|addFuture
argument_list|(
name|QFuture
argument_list|<
name|void
argument_list|>
argument_list|()
argument_list|)
expr_stmt|;
block|}
name|synchronizer
operator|.
name|waitForFinished
argument_list|()
expr_stmt|;
specifier|const
name|QList
argument_list|<
name|QFuture
argument_list|<
name|void
argument_list|>
argument_list|>
name|futures
init|=
name|synchronizer
operator|.
name|futures
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
literal|100
condition|;
name|i
operator|++
control|)
block|{
name|QVERIFY
argument_list|(
name|futures
operator|.
name|at
argument_list|(
name|i
argument_list|)
operator|.
name|isFinished
argument_list|()
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_macro
name|QTEST_MAIN
argument_list|(
argument|tst_QFutureSynchronizer
argument_list|)
end_macro
begin_include
include|#
directive|include
file|"tst_qfuturesynchronizer.moc"
end_include
end_unit
