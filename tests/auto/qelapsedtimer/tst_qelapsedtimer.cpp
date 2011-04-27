begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** No Commercial Usage ** This file contains pre-release code and may not be distributed. ** You may use this file in accordance with the terms and conditions ** contained in the Technology Preview License Agreement accompanying ** this package. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights.  These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** If you have questions regarding the use of this file, please contact ** Nokia at qt-info@nokia.com. ** ** ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtCore/QString>
end_include
begin_include
include|#
directive|include
file|<QtCore/QTime>
end_include
begin_include
include|#
directive|include
file|<QtCore/QElapsedTimer>
end_include
begin_include
include|#
directive|include
file|<QtTest/QtTest>
end_include
begin_decl_stmt
DECL|variable|minResolution
specifier|static
specifier|const
name|int
name|minResolution
init|=
literal|50
decl_stmt|;
end_decl_stmt
begin_comment
DECL|variable|minResolution
comment|// the minimum resolution for the tests
end_comment
begin_function
DECL|function|operator <<
name|QDebug
name|operator
name|<<
parameter_list|(
name|QDebug
name|s
parameter_list|,
specifier|const
name|QElapsedTimer
modifier|&
name|t
parameter_list|)
block|{
union|union
block|{
name|QElapsedTimer
name|t
decl_stmt|;
struct|struct
block|{
name|qint64
name|t1
decl_stmt|,
name|t2
decl_stmt|;
block|}
name|i
struct|;
block|}
name|copy
union|;
name|copy
operator|.
name|t
operator|=
name|t
expr_stmt|;
name|s
operator|.
name|nospace
argument_list|()
operator|<<
literal|"("
operator|<<
name|copy
operator|.
name|i
operator|.
name|t1
operator|<<
literal|", "
operator|<<
name|copy
operator|.
name|i
operator|.
name|t2
operator|<<
literal|")"
expr_stmt|;
return|return
name|s
operator|.
name|space
argument_list|()
return|;
block|}
end_function
begin_class
DECL|class|tst_QElapsedTimer
class|class
name|tst_QElapsedTimer
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
private|private
name|Q_SLOTS
private|:
name|void
name|statics
parameter_list|()
function_decl|;
name|void
name|validity
parameter_list|()
function_decl|;
name|void
name|basics
parameter_list|()
function_decl|;
name|void
name|elapsed
parameter_list|()
function_decl|;
block|}
class|;
end_class
begin_function
DECL|function|statics
name|void
name|tst_QElapsedTimer
operator|::
name|statics
parameter_list|()
block|{
name|qDebug
argument_list|()
operator|<<
literal|"Clock type is"
operator|<<
name|QElapsedTimer
operator|::
name|clockType
argument_list|()
expr_stmt|;
name|qDebug
argument_list|()
operator|<<
literal|"Said clock is"
operator|<<
operator|(
name|QElapsedTimer
operator|::
name|isMonotonic
argument_list|()
condition|?
literal|"monotonic"
else|:
literal|"not monotonic"
operator|)
expr_stmt|;
name|QElapsedTimer
name|t
decl_stmt|;
name|t
operator|.
name|start
argument_list|()
expr_stmt|;
name|qDebug
argument_list|()
operator|<<
literal|"Current time is"
operator|<<
name|t
operator|.
name|msecsSinceReference
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|validity
name|void
name|tst_QElapsedTimer
operator|::
name|validity
parameter_list|()
block|{
name|QElapsedTimer
name|t
decl_stmt|;
name|t
operator|.
name|invalidate
argument_list|()
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|t
operator|.
name|isValid
argument_list|()
argument_list|)
expr_stmt|;
name|t
operator|.
name|start
argument_list|()
expr_stmt|;
name|QVERIFY
argument_list|(
name|t
operator|.
name|isValid
argument_list|()
argument_list|)
expr_stmt|;
name|t
operator|.
name|invalidate
argument_list|()
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|t
operator|.
name|isValid
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|basics
name|void
name|tst_QElapsedTimer
operator|::
name|basics
parameter_list|()
block|{
name|QElapsedTimer
name|t1
decl_stmt|;
name|t1
operator|.
name|start
argument_list|()
expr_stmt|;
name|QVERIFY
argument_list|(
name|t1
operator|.
name|msecsSinceReference
argument_list|()
operator|!=
literal|0
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|t1
argument_list|,
name|t1
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
operator|(
name|t1
operator|!=
name|t1
operator|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
operator|(
name|t1
operator|<
name|t1
operator|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|t1
operator|.
name|msecsTo
argument_list|(
name|t1
argument_list|)
argument_list|,
name|qint64
argument_list|(
literal|0
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|t1
operator|.
name|secsTo
argument_list|(
name|t1
argument_list|)
argument_list|,
name|qint64
argument_list|(
literal|0
argument_list|)
argument_list|)
expr_stmt|;
comment|//    QCOMPARE(t1 + 0, t1);
comment|//    QCOMPARE(t1 - 0, t1);
if|#
directive|if
literal|0
block|QElapsedTimer t2 = t1;     t2 += 1000;
comment|// so we can use secsTo
block|QVERIFY(t1 != t2);     QVERIFY(!(t1 == t2));     QVERIFY(t1< t2);     QVERIFY(!(t2< t1));     QCOMPARE(t1.msecsTo(t2), qint64(1000));     QCOMPARE(t1.secsTo(t2), qint64(1));
comment|//    QCOMPARE(t2 - t1, qint64(1000));
comment|//    QCOMPARE(t1 - t2, qint64(-1000));
endif|#
directive|endif
name|quint64
name|value1
init|=
name|t1
operator|.
name|msecsSinceReference
argument_list|()
decl_stmt|;
name|qDebug
argument_list|()
operator|<<
name|value1
operator|<<
name|t1
expr_stmt|;
name|qint64
name|nsecs
init|=
name|t1
operator|.
name|nsecsElapsed
argument_list|()
decl_stmt|;
name|qint64
name|elapsed
init|=
name|t1
operator|.
name|restart
argument_list|()
decl_stmt|;
name|QVERIFY
argument_list|(
name|elapsed
operator|<
name|minResolution
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|nsecs
operator|/
literal|1000000
operator|<
name|minResolution
argument_list|)
expr_stmt|;
name|quint64
name|value2
init|=
name|t1
operator|.
name|msecsSinceReference
argument_list|()
decl_stmt|;
name|qDebug
argument_list|()
operator|<<
name|value2
operator|<<
name|t1
operator|<<
name|elapsed
operator|<<
name|nsecs
expr_stmt|;
comment|// in theory, elapsed == value2 - value1
comment|// However, since QElapsedTimer keeps internally the full resolution,
comment|// we have here a rounding error due to integer division
name|QVERIFY
argument_list|(
name|qAbs
argument_list|(
name|elapsed
operator|-
name|qint64
argument_list|(
name|value2
operator|-
name|value1
argument_list|)
argument_list|)
operator|<=
literal|1
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|elapsed
name|void
name|tst_QElapsedTimer
operator|::
name|elapsed
parameter_list|()
block|{
name|QElapsedTimer
name|t1
decl_stmt|;
name|t1
operator|.
name|start
argument_list|()
expr_stmt|;
name|QTest
operator|::
name|qSleep
argument_list|(
literal|4
operator|*
name|minResolution
argument_list|)
expr_stmt|;
name|QElapsedTimer
name|t2
decl_stmt|;
name|t2
operator|.
name|start
argument_list|()
expr_stmt|;
name|QVERIFY
argument_list|(
name|t1
operator|!=
name|t2
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
operator|(
name|t1
operator|==
name|t2
operator|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|t1
operator|<
name|t2
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|t1
operator|.
name|msecsTo
argument_list|(
name|t2
argument_list|)
operator|>
literal|0
argument_list|)
expr_stmt|;
comment|// don't check: t1.secsTo(t2)
comment|//    QVERIFY(t1 - t2< 0);
name|QVERIFY
argument_list|(
name|t1
operator|.
name|nsecsElapsed
argument_list|()
operator|>
literal|0
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|t1
operator|.
name|elapsed
argument_list|()
operator|>
literal|0
argument_list|)
expr_stmt|;
comment|// the number of elapsed nanoseconds and milliseconds should match
name|QVERIFY
argument_list|(
name|t1
operator|.
name|nsecsElapsed
argument_list|()
operator|-
name|t1
operator|.
name|elapsed
argument_list|()
operator|*
literal|1000000
operator|<
literal|1000000
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|t1
operator|.
name|hasExpired
argument_list|(
name|minResolution
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|t1
operator|.
name|hasExpired
argument_list|(
literal|8
operator|*
name|minResolution
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|t2
operator|.
name|hasExpired
argument_list|(
name|minResolution
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|t1
operator|.
name|hasExpired
argument_list|(
operator|-
literal|1
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|t2
operator|.
name|hasExpired
argument_list|(
operator|-
literal|1
argument_list|)
argument_list|)
expr_stmt|;
name|qint64
name|elapsed
init|=
name|t1
operator|.
name|restart
argument_list|()
decl_stmt|;
name|QVERIFY
argument_list|(
name|elapsed
operator|>
literal|3
operator|*
name|minResolution
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|elapsed
operator|<
literal|5
operator|*
name|minResolution
argument_list|)
expr_stmt|;
name|qint64
name|diff
init|=
name|t2
operator|.
name|msecsTo
argument_list|(
name|t1
argument_list|)
decl_stmt|;
name|QVERIFY
argument_list|(
name|diff
operator|<
name|minResolution
argument_list|)
expr_stmt|;
block|}
end_function
begin_expr_stmt
DECL|variable|tst_QElapsedTimer
name|QTEST_MAIN
argument_list|(
name|tst_QElapsedTimer
argument_list|)
expr_stmt|;
end_expr_stmt
begin_include
include|#
directive|include
file|"tst_qelapsedtimer.moc"
end_include
end_unit
