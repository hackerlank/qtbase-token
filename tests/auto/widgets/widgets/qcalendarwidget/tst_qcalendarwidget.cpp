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
file|<qcalendarwidget.h>
end_include
begin_include
include|#
directive|include
file|<qtoolbutton.h>
end_include
begin_include
include|#
directive|include
file|<qspinbox.h>
end_include
begin_include
include|#
directive|include
file|<qmenu.h>
end_include
begin_include
include|#
directive|include
file|<qdebug.h>
end_include
begin_include
include|#
directive|include
file|<qdatetime.h>
end_include
begin_include
include|#
directive|include
file|<qtextformat.h>
end_include
begin_class
DECL|class|tst_QCalendarWidget
class|class
name|tst_QCalendarWidget
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
public|public:
name|tst_QCalendarWidget
parameter_list|()
constructor_decl|;
specifier|virtual
name|~
name|tst_QCalendarWidget
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
name|getSetCheck
parameter_list|()
function_decl|;
name|void
name|buttonClickCheck
parameter_list|()
function_decl|;
name|void
name|setTextFormat
parameter_list|()
function_decl|;
name|void
name|resetTextFormat
parameter_list|()
function_decl|;
name|void
name|setWeekdayFormat
parameter_list|()
function_decl|;
name|void
name|showPrevNext_data
parameter_list|()
function_decl|;
name|void
name|showPrevNext
parameter_list|()
function_decl|;
block|}
class|;
end_class
begin_comment
comment|// Testing get/set functions
end_comment
begin_function
DECL|function|getSetCheck
name|void
name|tst_QCalendarWidget
operator|::
name|getSetCheck
parameter_list|()
block|{
name|QWidget
name|topLevel
decl_stmt|;
name|QCalendarWidget
name|object
argument_list|(
operator|&
name|topLevel
argument_list|)
decl_stmt|;
comment|//horizontal header formats
name|object
operator|.
name|setHorizontalHeaderFormat
argument_list|(
name|QCalendarWidget
operator|::
name|NoHorizontalHeader
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|QCalendarWidget
operator|::
name|NoHorizontalHeader
argument_list|,
name|object
operator|.
name|horizontalHeaderFormat
argument_list|()
argument_list|)
expr_stmt|;
name|object
operator|.
name|setHorizontalHeaderFormat
argument_list|(
name|QCalendarWidget
operator|::
name|SingleLetterDayNames
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|QCalendarWidget
operator|::
name|SingleLetterDayNames
argument_list|,
name|object
operator|.
name|horizontalHeaderFormat
argument_list|()
argument_list|)
expr_stmt|;
name|object
operator|.
name|setHorizontalHeaderFormat
argument_list|(
name|QCalendarWidget
operator|::
name|ShortDayNames
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|QCalendarWidget
operator|::
name|ShortDayNames
argument_list|,
name|object
operator|.
name|horizontalHeaderFormat
argument_list|()
argument_list|)
expr_stmt|;
name|object
operator|.
name|setHorizontalHeaderFormat
argument_list|(
name|QCalendarWidget
operator|::
name|LongDayNames
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|QCalendarWidget
operator|::
name|LongDayNames
argument_list|,
name|object
operator|.
name|horizontalHeaderFormat
argument_list|()
argument_list|)
expr_stmt|;
comment|//vertical header formats
name|object
operator|.
name|setVerticalHeaderFormat
argument_list|(
name|QCalendarWidget
operator|::
name|ISOWeekNumbers
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|QCalendarWidget
operator|::
name|ISOWeekNumbers
argument_list|,
name|object
operator|.
name|verticalHeaderFormat
argument_list|()
argument_list|)
expr_stmt|;
name|object
operator|.
name|setVerticalHeaderFormat
argument_list|(
name|QCalendarWidget
operator|::
name|NoVerticalHeader
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|QCalendarWidget
operator|::
name|NoVerticalHeader
argument_list|,
name|object
operator|.
name|verticalHeaderFormat
argument_list|()
argument_list|)
expr_stmt|;
comment|//maximum Date
name|QDate
name|maxDate
argument_list|(
literal|2006
argument_list|,
literal|7
argument_list|,
literal|3
argument_list|)
decl_stmt|;
name|object
operator|.
name|setMaximumDate
argument_list|(
name|maxDate
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|maxDate
argument_list|,
name|object
operator|.
name|maximumDate
argument_list|()
argument_list|)
expr_stmt|;
comment|//minimum date
name|QDate
name|minDate
argument_list|(
literal|2004
argument_list|,
literal|7
argument_list|,
literal|3
argument_list|)
decl_stmt|;
name|object
operator|.
name|setMinimumDate
argument_list|(
name|minDate
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|minDate
argument_list|,
name|object
operator|.
name|minimumDate
argument_list|()
argument_list|)
expr_stmt|;
comment|//day of week
name|object
operator|.
name|setFirstDayOfWeek
argument_list|(
name|Qt
operator|::
name|Thursday
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|Qt
operator|::
name|Thursday
argument_list|,
name|object
operator|.
name|firstDayOfWeek
argument_list|()
argument_list|)
expr_stmt|;
comment|//grid visible
name|object
operator|.
name|setGridVisible
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|object
operator|.
name|isGridVisible
argument_list|()
argument_list|)
expr_stmt|;
name|object
operator|.
name|setGridVisible
argument_list|(
literal|false
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|object
operator|.
name|isGridVisible
argument_list|()
argument_list|)
expr_stmt|;
comment|//header visible
name|object
operator|.
name|setNavigationBarVisible
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|object
operator|.
name|isNavigationBarVisible
argument_list|()
argument_list|)
expr_stmt|;
name|object
operator|.
name|setNavigationBarVisible
argument_list|(
literal|false
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|object
operator|.
name|isNavigationBarVisible
argument_list|()
argument_list|)
expr_stmt|;
comment|//selection mode
name|QCOMPARE
argument_list|(
name|QCalendarWidget
operator|::
name|SingleSelection
argument_list|,
name|object
operator|.
name|selectionMode
argument_list|()
argument_list|)
expr_stmt|;
name|object
operator|.
name|setSelectionMode
argument_list|(
name|QCalendarWidget
operator|::
name|NoSelection
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|QCalendarWidget
operator|::
name|NoSelection
argument_list|,
name|object
operator|.
name|selectionMode
argument_list|()
argument_list|)
expr_stmt|;
name|object
operator|.
name|setSelectionMode
argument_list|(
name|QCalendarWidget
operator|::
name|SingleSelection
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|QCalendarWidget
operator|::
name|SingleSelection
argument_list|,
name|object
operator|.
name|selectionMode
argument_list|()
argument_list|)
expr_stmt|;
comment|//selected date
name|QDate
name|selectedDate
argument_list|(
literal|2005
argument_list|,
literal|7
argument_list|,
literal|3
argument_list|)
decl_stmt|;
name|QSignalSpy
name|spy
argument_list|(
operator|&
name|object
argument_list|,
name|SIGNAL
argument_list|(
name|selectionChanged
argument_list|()
argument_list|)
argument_list|)
decl_stmt|;
name|object
operator|.
name|setSelectedDate
argument_list|(
name|selectedDate
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|spy
operator|.
name|count
argument_list|()
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|selectedDate
argument_list|,
name|object
operator|.
name|selectedDate
argument_list|()
argument_list|)
expr_stmt|;
comment|//month and year
name|object
operator|.
name|setCurrentPage
argument_list|(
literal|2004
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
literal|1
argument_list|,
name|object
operator|.
name|monthShown
argument_list|()
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
literal|2004
argument_list|,
name|object
operator|.
name|yearShown
argument_list|()
argument_list|)
expr_stmt|;
name|object
operator|.
name|showNextMonth
argument_list|()
expr_stmt|;
name|QCOMPARE
argument_list|(
literal|2
argument_list|,
name|object
operator|.
name|monthShown
argument_list|()
argument_list|)
expr_stmt|;
name|object
operator|.
name|showPreviousMonth
argument_list|()
expr_stmt|;
name|QCOMPARE
argument_list|(
literal|1
argument_list|,
name|object
operator|.
name|monthShown
argument_list|()
argument_list|)
expr_stmt|;
name|object
operator|.
name|showNextYear
argument_list|()
expr_stmt|;
name|QCOMPARE
argument_list|(
literal|2005
argument_list|,
name|object
operator|.
name|yearShown
argument_list|()
argument_list|)
expr_stmt|;
name|object
operator|.
name|showPreviousYear
argument_list|()
expr_stmt|;
name|QCOMPARE
argument_list|(
literal|2004
argument_list|,
name|object
operator|.
name|yearShown
argument_list|()
argument_list|)
expr_stmt|;
comment|//date range
name|minDate
operator|=
name|QDate
argument_list|(
literal|2006
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|maxDate
operator|=
name|QDate
argument_list|(
literal|2010
argument_list|,
literal|12
argument_list|,
literal|31
argument_list|)
expr_stmt|;
name|object
operator|.
name|setDateRange
argument_list|(
name|minDate
argument_list|,
name|maxDate
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|maxDate
argument_list|,
name|object
operator|.
name|maximumDate
argument_list|()
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|minDate
argument_list|,
name|object
operator|.
name|minimumDate
argument_list|()
argument_list|)
expr_stmt|;
comment|//date should not go beyond the minimum.
name|selectedDate
operator|=
name|minDate
operator|.
name|addDays
argument_list|(
operator|-
literal|10
argument_list|)
expr_stmt|;
name|object
operator|.
name|setSelectedDate
argument_list|(
name|selectedDate
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|minDate
argument_list|,
name|object
operator|.
name|selectedDate
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|selectedDate
operator|!=
name|object
operator|.
name|selectedDate
argument_list|()
argument_list|)
expr_stmt|;
comment|//date should not go beyond the maximum.
name|selectedDate
operator|=
name|maxDate
operator|.
name|addDays
argument_list|(
literal|10
argument_list|)
expr_stmt|;
name|object
operator|.
name|setSelectedDate
argument_list|(
name|selectedDate
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|maxDate
argument_list|,
name|object
operator|.
name|selectedDate
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|selectedDate
operator|!=
name|object
operator|.
name|selectedDate
argument_list|()
argument_list|)
expr_stmt|;
comment|//show today
name|QDate
name|today
init|=
name|QDate
operator|::
name|currentDate
argument_list|()
decl_stmt|;
name|object
operator|.
name|showToday
argument_list|()
expr_stmt|;
name|QCOMPARE
argument_list|(
name|today
operator|.
name|month
argument_list|()
argument_list|,
name|object
operator|.
name|monthShown
argument_list|()
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|today
operator|.
name|year
argument_list|()
argument_list|,
name|object
operator|.
name|yearShown
argument_list|()
argument_list|)
expr_stmt|;
comment|//slect a different date and move.
name|object
operator|.
name|setSelectedDate
argument_list|(
name|minDate
argument_list|)
expr_stmt|;
name|object
operator|.
name|showSelectedDate
argument_list|()
expr_stmt|;
name|QCOMPARE
argument_list|(
name|minDate
operator|.
name|month
argument_list|()
argument_list|,
name|object
operator|.
name|monthShown
argument_list|()
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|minDate
operator|.
name|year
argument_list|()
argument_list|,
name|object
operator|.
name|yearShown
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|buttonClickCheck
name|void
name|tst_QCalendarWidget
operator|::
name|buttonClickCheck
parameter_list|()
block|{
name|QCalendarWidget
name|object
decl_stmt|;
name|QSize
name|size
init|=
name|object
operator|.
name|sizeHint
argument_list|()
decl_stmt|;
name|object
operator|.
name|setGeometry
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
name|size
operator|.
name|width
argument_list|()
argument_list|,
name|size
operator|.
name|height
argument_list|()
argument_list|)
expr_stmt|;
name|object
operator|.
name|show
argument_list|()
expr_stmt|;
name|QDate
name|selectedDate
argument_list|(
literal|2005
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|)
decl_stmt|;
comment|//click on the month buttons
name|int
name|month
init|=
name|object
operator|.
name|monthShown
argument_list|()
decl_stmt|;
name|QToolButton
modifier|*
name|button
init|=
name|qFindChild
argument_list|<
name|QToolButton
operator|*
argument_list|>
argument_list|(
operator|&
name|object
argument_list|,
literal|"qt_calendar_prevmonth"
argument_list|)
decl_stmt|;
name|QTest
operator|::
name|mouseClick
argument_list|(
name|button
argument_list|,
name|Qt
operator|::
name|LeftButton
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|month
operator|>
literal|1
condition|?
name|month
operator|-
literal|1
else|:
literal|12
argument_list|,
name|object
operator|.
name|monthShown
argument_list|()
argument_list|)
expr_stmt|;
name|button
operator|=
name|qFindChild
argument_list|<
name|QToolButton
operator|*
argument_list|>
argument_list|(
operator|&
name|object
argument_list|,
literal|"qt_calendar_nextmonth"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|mouseClick
argument_list|(
name|button
argument_list|,
name|Qt
operator|::
name|LeftButton
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|month
argument_list|,
name|object
operator|.
name|monthShown
argument_list|()
argument_list|)
expr_stmt|;
name|button
operator|=
name|qFindChild
argument_list|<
name|QToolButton
operator|*
argument_list|>
argument_list|(
operator|&
name|object
argument_list|,
literal|"qt_calendar_yearbutton"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|mouseClick
argument_list|(
name|button
argument_list|,
name|Qt
operator|::
name|LeftButton
argument_list|,
name|Qt
operator|::
name|NoModifier
argument_list|,
name|button
operator|->
name|rect
argument_list|()
operator|.
name|center
argument_list|()
argument_list|,
literal|2
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|button
operator|->
name|isVisible
argument_list|()
argument_list|)
expr_stmt|;
name|QSpinBox
modifier|*
name|spinbox
init|=
name|qFindChild
argument_list|<
name|QSpinBox
operator|*
argument_list|>
argument_list|(
operator|&
name|object
argument_list|,
literal|"qt_calendar_yearedit"
argument_list|)
decl_stmt|;
name|QTest
operator|::
name|qWait
argument_list|(
literal|500
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|keyClick
argument_list|(
name|spinbox
argument_list|,
literal|'2'
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|keyClick
argument_list|(
name|spinbox
argument_list|,
literal|'0'
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|keyClick
argument_list|(
name|spinbox
argument_list|,
literal|'0'
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|keyClick
argument_list|(
name|spinbox
argument_list|,
literal|'6'
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|qWait
argument_list|(
literal|500
argument_list|)
expr_stmt|;
name|QWidget
modifier|*
name|widget
init|=
name|qFindChild
argument_list|<
name|QWidget
operator|*
argument_list|>
argument_list|(
operator|&
name|object
argument_list|,
literal|"qt_calendar_calendarview"
argument_list|)
decl_stmt|;
name|QTest
operator|::
name|mouseMove
argument_list|(
name|widget
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|mouseClick
argument_list|(
name|widget
argument_list|,
name|Qt
operator|::
name|LeftButton
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
literal|2006
argument_list|,
name|object
operator|.
name|yearShown
argument_list|()
argument_list|)
expr_stmt|;
name|object
operator|.
name|setSelectedDate
argument_list|(
name|selectedDate
argument_list|)
expr_stmt|;
name|object
operator|.
name|showSelectedDate
argument_list|()
expr_stmt|;
name|QTest
operator|::
name|keyClick
argument_list|(
name|widget
argument_list|,
name|Qt
operator|::
name|Key_Down
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|selectedDate
operator|!=
name|object
operator|.
name|selectedDate
argument_list|()
argument_list|)
expr_stmt|;
name|object
operator|.
name|setDateRange
argument_list|(
name|QDate
argument_list|(
literal|2006
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|)
argument_list|,
name|QDate
argument_list|(
literal|2006
argument_list|,
literal|2
argument_list|,
literal|28
argument_list|)
argument_list|)
expr_stmt|;
name|object
operator|.
name|setSelectedDate
argument_list|(
name|QDate
argument_list|(
literal|2006
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|)
argument_list|)
expr_stmt|;
name|object
operator|.
name|showSelectedDate
argument_list|()
expr_stmt|;
name|button
operator|=
name|qFindChild
argument_list|<
name|QToolButton
operator|*
argument_list|>
argument_list|(
operator|&
name|object
argument_list|,
literal|"qt_calendar_prevmonth"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|mouseClick
argument_list|(
name|button
argument_list|,
name|Qt
operator|::
name|LeftButton
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
literal|1
argument_list|,
name|object
operator|.
name|monthShown
argument_list|()
argument_list|)
expr_stmt|;
name|button
operator|=
name|qFindChild
argument_list|<
name|QToolButton
operator|*
argument_list|>
argument_list|(
operator|&
name|object
argument_list|,
literal|"qt_calendar_nextmonth"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|mouseClick
argument_list|(
name|button
argument_list|,
name|Qt
operator|::
name|LeftButton
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
literal|2
argument_list|,
name|object
operator|.
name|monthShown
argument_list|()
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|mouseClick
argument_list|(
name|button
argument_list|,
name|Qt
operator|::
name|LeftButton
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
literal|2
argument_list|,
name|object
operator|.
name|monthShown
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|setTextFormat
name|void
name|tst_QCalendarWidget
operator|::
name|setTextFormat
parameter_list|()
block|{
name|QCalendarWidget
name|calendar
decl_stmt|;
name|QTextCharFormat
name|format
decl_stmt|;
name|format
operator|.
name|setFontItalic
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|format
operator|.
name|setForeground
argument_list|(
name|Qt
operator|::
name|green
argument_list|)
expr_stmt|;
specifier|const
name|QDate
name|date
argument_list|(
literal|1984
argument_list|,
literal|10
argument_list|,
literal|20
argument_list|)
decl_stmt|;
name|calendar
operator|.
name|setDateTextFormat
argument_list|(
name|date
argument_list|,
name|format
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|calendar
operator|.
name|dateTextFormat
argument_list|(
name|date
argument_list|)
argument_list|,
name|format
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|resetTextFormat
name|void
name|tst_QCalendarWidget
operator|::
name|resetTextFormat
parameter_list|()
block|{
name|QCalendarWidget
name|calendar
decl_stmt|;
name|QTextCharFormat
name|format
decl_stmt|;
name|format
operator|.
name|setFontItalic
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|format
operator|.
name|setForeground
argument_list|(
name|Qt
operator|::
name|green
argument_list|)
expr_stmt|;
specifier|const
name|QDate
name|date
argument_list|(
literal|1984
argument_list|,
literal|10
argument_list|,
literal|20
argument_list|)
decl_stmt|;
name|calendar
operator|.
name|setDateTextFormat
argument_list|(
name|date
argument_list|,
name|format
argument_list|)
expr_stmt|;
name|calendar
operator|.
name|setDateTextFormat
argument_list|(
name|QDate
argument_list|()
argument_list|,
name|QTextCharFormat
argument_list|()
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|calendar
operator|.
name|dateTextFormat
argument_list|(
name|date
argument_list|)
argument_list|,
name|QTextCharFormat
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|setWeekdayFormat
name|void
name|tst_QCalendarWidget
operator|::
name|setWeekdayFormat
parameter_list|()
block|{
name|QCalendarWidget
name|calendar
decl_stmt|;
name|QTextCharFormat
name|format
decl_stmt|;
name|format
operator|.
name|setFontItalic
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|format
operator|.
name|setForeground
argument_list|(
name|Qt
operator|::
name|green
argument_list|)
expr_stmt|;
name|calendar
operator|.
name|setWeekdayTextFormat
argument_list|(
name|Qt
operator|::
name|Wednesday
argument_list|,
name|format
argument_list|)
expr_stmt|;
comment|// check the format of the a given month
for|for
control|(
name|int
name|i
init|=
literal|1
init|;
name|i
operator|<=
literal|31
condition|;
operator|++
name|i
control|)
block|{
specifier|const
name|QDate
name|date
argument_list|(
literal|1984
argument_list|,
literal|10
argument_list|,
name|i
argument_list|)
decl_stmt|;
specifier|const
name|Qt
operator|::
name|DayOfWeek
name|dayOfWeek
init|=
cast|static_cast
argument_list|<
name|Qt
operator|::
name|DayOfWeek
argument_list|>
argument_list|(
name|date
operator|.
name|dayOfWeek
argument_list|()
argument_list|)
decl_stmt|;
if|if
condition|(
name|dayOfWeek
operator|==
name|Qt
operator|::
name|Wednesday
condition|)
name|QCOMPARE
argument_list|(
name|calendar
operator|.
name|weekdayTextFormat
argument_list|(
name|dayOfWeek
argument_list|)
argument_list|,
name|format
argument_list|)
expr_stmt|;
else|else
name|QVERIFY
argument_list|(
name|calendar
operator|.
name|weekdayTextFormat
argument_list|(
name|dayOfWeek
argument_list|)
operator|!=
name|format
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_constructor
DECL|function|tst_QCalendarWidget
name|tst_QCalendarWidget
operator|::
name|tst_QCalendarWidget
parameter_list|()
block|{ }
end_constructor
begin_destructor
DECL|function|~tst_QCalendarWidget
name|tst_QCalendarWidget
operator|::
name|~
name|tst_QCalendarWidget
parameter_list|()
block|{ }
end_destructor
begin_function
DECL|function|initTestCase
name|void
name|tst_QCalendarWidget
operator|::
name|initTestCase
parameter_list|()
block|{ }
end_function
begin_function
DECL|function|cleanupTestCase
name|void
name|tst_QCalendarWidget
operator|::
name|cleanupTestCase
parameter_list|()
block|{ }
end_function
begin_function
DECL|function|init
name|void
name|tst_QCalendarWidget
operator|::
name|init
parameter_list|()
block|{ }
end_function
begin_function
DECL|function|cleanup
name|void
name|tst_QCalendarWidget
operator|::
name|cleanup
parameter_list|()
block|{ }
end_function
begin_typedef
DECL|typedef|ShowFunc
typedef|typedef
name|void
function_decl|(
name|QCalendarWidget
operator|::
modifier|*
name|ShowFunc
function_decl|)
parameter_list|()
function_decl|;
end_typedef
begin_macro
name|Q_DECLARE_METATYPE
argument_list|(
argument|ShowFunc
argument_list|)
end_macro
begin_function
DECL|function|showPrevNext_data
name|void
name|tst_QCalendarWidget
operator|::
name|showPrevNext_data
parameter_list|()
block|{
name|QTest
operator|::
name|addColumn
argument_list|<
name|ShowFunc
argument_list|>
argument_list|(
literal|"function"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|QDate
argument_list|>
argument_list|(
literal|"dateOrigin"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|QDate
argument_list|>
argument_list|(
literal|"expectedDate"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"showNextMonth"
argument_list|)
operator|<<
operator|&
name|QCalendarWidget
operator|::
name|showNextMonth
operator|<<
name|QDate
argument_list|(
literal|1984
argument_list|,
literal|7
argument_list|,
literal|30
argument_list|)
operator|<<
name|QDate
argument_list|(
literal|1984
argument_list|,
literal|8
argument_list|,
literal|30
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"showPrevMonth"
argument_list|)
operator|<<
operator|&
name|QCalendarWidget
operator|::
name|showPreviousMonth
operator|<<
name|QDate
argument_list|(
literal|1984
argument_list|,
literal|7
argument_list|,
literal|30
argument_list|)
operator|<<
name|QDate
argument_list|(
literal|1984
argument_list|,
literal|6
argument_list|,
literal|30
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"showNextYear"
argument_list|)
operator|<<
operator|&
name|QCalendarWidget
operator|::
name|showNextYear
operator|<<
name|QDate
argument_list|(
literal|1984
argument_list|,
literal|7
argument_list|,
literal|30
argument_list|)
operator|<<
name|QDate
argument_list|(
literal|1985
argument_list|,
literal|7
argument_list|,
literal|30
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"showPrevYear"
argument_list|)
operator|<<
operator|&
name|QCalendarWidget
operator|::
name|showPreviousYear
operator|<<
name|QDate
argument_list|(
literal|1984
argument_list|,
literal|7
argument_list|,
literal|30
argument_list|)
operator|<<
name|QDate
argument_list|(
literal|1983
argument_list|,
literal|7
argument_list|,
literal|30
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"showNextMonth limit"
argument_list|)
operator|<<
operator|&
name|QCalendarWidget
operator|::
name|showNextMonth
operator|<<
name|QDate
argument_list|(
literal|2007
argument_list|,
literal|12
argument_list|,
literal|4
argument_list|)
operator|<<
name|QDate
argument_list|(
literal|2008
argument_list|,
literal|1
argument_list|,
literal|4
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"showPreviousMonth limit"
argument_list|)
operator|<<
operator|&
name|QCalendarWidget
operator|::
name|showPreviousMonth
operator|<<
name|QDate
argument_list|(
literal|2006
argument_list|,
literal|1
argument_list|,
literal|23
argument_list|)
operator|<<
name|QDate
argument_list|(
literal|2005
argument_list|,
literal|12
argument_list|,
literal|23
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"showNextMonth now"
argument_list|)
operator|<<
operator|&
name|QCalendarWidget
operator|::
name|showNextMonth
operator|<<
name|QDate
argument_list|()
operator|<<
name|QDate
operator|::
name|currentDate
argument_list|()
operator|.
name|addMonths
argument_list|(
literal|1
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"showNextYear now"
argument_list|)
operator|<<
operator|&
name|QCalendarWidget
operator|::
name|showNextYear
operator|<<
name|QDate
argument_list|()
operator|<<
name|QDate
operator|::
name|currentDate
argument_list|()
operator|.
name|addYears
argument_list|(
literal|1
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"showPrevieousMonth now"
argument_list|)
operator|<<
operator|&
name|QCalendarWidget
operator|::
name|showPreviousMonth
operator|<<
name|QDate
argument_list|()
operator|<<
name|QDate
operator|::
name|currentDate
argument_list|()
operator|.
name|addMonths
argument_list|(
operator|-
literal|1
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"showPreviousYear now"
argument_list|)
operator|<<
operator|&
name|QCalendarWidget
operator|::
name|showPreviousYear
operator|<<
name|QDate
argument_list|()
operator|<<
name|QDate
operator|::
name|currentDate
argument_list|()
operator|.
name|addYears
argument_list|(
operator|-
literal|1
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"showToday now"
argument_list|)
operator|<<
operator|&
name|QCalendarWidget
operator|::
name|showToday
operator|<<
name|QDate
argument_list|(
literal|2000
argument_list|,
literal|1
argument_list|,
literal|31
argument_list|)
operator|<<
name|QDate
operator|::
name|currentDate
argument_list|()
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"showNextMonth 31"
argument_list|)
operator|<<
operator|&
name|QCalendarWidget
operator|::
name|showNextMonth
operator|<<
name|QDate
argument_list|(
literal|2000
argument_list|,
literal|1
argument_list|,
literal|31
argument_list|)
operator|<<
name|QDate
argument_list|(
literal|2000
argument_list|,
literal|2
argument_list|,
literal|28
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"selectedDate"
argument_list|)
operator|<<
operator|&
name|QCalendarWidget
operator|::
name|showSelectedDate
operator|<<
name|QDate
argument_list|(
literal|2008
argument_list|,
literal|2
argument_list|,
literal|29
argument_list|)
operator|<<
name|QDate
argument_list|(
literal|2008
argument_list|,
literal|2
argument_list|,
literal|29
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|showPrevNext
name|void
name|tst_QCalendarWidget
operator|::
name|showPrevNext
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|ShowFunc
argument_list|,
name|function
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|QDate
argument_list|,
name|dateOrigin
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|QDate
argument_list|,
name|expectedDate
argument_list|)
expr_stmt|;
name|QCalendarWidget
name|calWidget
decl_stmt|;
name|calWidget
operator|.
name|show
argument_list|()
expr_stmt|;
name|QTest
operator|::
name|qWaitForWindowShown
argument_list|(
operator|&
name|calWidget
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|dateOrigin
operator|.
name|isNull
argument_list|()
condition|)
block|{
name|calWidget
operator|.
name|setSelectedDate
argument_list|(
name|dateOrigin
argument_list|)
expr_stmt|;
name|calWidget
operator|.
name|setCurrentPage
argument_list|(
name|dateOrigin
operator|.
name|year
argument_list|()
argument_list|,
name|dateOrigin
operator|.
name|month
argument_list|()
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|calWidget
operator|.
name|yearShown
argument_list|()
argument_list|,
name|dateOrigin
operator|.
name|year
argument_list|()
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|calWidget
operator|.
name|monthShown
argument_list|()
argument_list|,
name|dateOrigin
operator|.
name|month
argument_list|()
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|QCOMPARE
argument_list|(
name|calWidget
operator|.
name|yearShown
argument_list|()
argument_list|,
name|QDate
operator|::
name|currentDate
argument_list|()
operator|.
name|year
argument_list|()
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|calWidget
operator|.
name|monthShown
argument_list|()
argument_list|,
name|QDate
operator|::
name|currentDate
argument_list|()
operator|.
name|month
argument_list|()
argument_list|)
expr_stmt|;
block|}
call|(
name|calWidget
operator|.*
name|function
call|)
argument_list|()
expr_stmt|;
name|QCOMPARE
argument_list|(
name|calWidget
operator|.
name|yearShown
argument_list|()
argument_list|,
name|expectedDate
operator|.
name|year
argument_list|()
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|calWidget
operator|.
name|monthShown
argument_list|()
argument_list|,
name|expectedDate
operator|.
name|month
argument_list|()
argument_list|)
expr_stmt|;
comment|// QTBUG-4058
name|QTest
operator|::
name|qWait
argument_list|(
literal|20
argument_list|)
expr_stmt|;
name|QToolButton
modifier|*
name|button
init|=
name|qFindChild
argument_list|<
name|QToolButton
operator|*
argument_list|>
argument_list|(
operator|&
name|calWidget
argument_list|,
literal|"qt_calendar_prevmonth"
argument_list|)
decl_stmt|;
name|QTest
operator|::
name|mouseClick
argument_list|(
name|button
argument_list|,
name|Qt
operator|::
name|LeftButton
argument_list|)
expr_stmt|;
name|expectedDate
operator|=
name|expectedDate
operator|.
name|addMonths
argument_list|(
operator|-
literal|1
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|calWidget
operator|.
name|yearShown
argument_list|()
argument_list|,
name|expectedDate
operator|.
name|year
argument_list|()
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|calWidget
operator|.
name|monthShown
argument_list|()
argument_list|,
name|expectedDate
operator|.
name|month
argument_list|()
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|dateOrigin
operator|.
name|isNull
argument_list|()
condition|)
block|{
comment|//the selectedDate should not have changed
name|QCOMPARE
argument_list|(
name|calWidget
operator|.
name|selectedDate
argument_list|()
argument_list|,
name|dateOrigin
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_macro
name|QTEST_MAIN
argument_list|(
argument|tst_QCalendarWidget
argument_list|)
end_macro
begin_include
include|#
directive|include
file|"tst_qcalendarwidget.moc"
end_include
end_unit
