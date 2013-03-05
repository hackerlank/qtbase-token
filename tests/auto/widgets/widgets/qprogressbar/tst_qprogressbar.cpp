begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtTest/QtTest>
end_include
begin_include
include|#
directive|include
file|"qprogressbar.h"
end_include
begin_include
include|#
directive|include
file|<qlocale.h>
end_include
begin_include
include|#
directive|include
file|<qapplication.h>
end_include
begin_include
include|#
directive|include
file|<qstyleoption.h>
end_include
begin_include
include|#
directive|include
file|<qdebug.h>
end_include
begin_include
include|#
directive|include
file|<qtimer.h>
end_include
begin_include
include|#
directive|include
file|<QStyleFactory>
end_include
begin_class
DECL|class|tst_QProgressBar
class|class
name|tst_QProgressBar
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
private|private
name|slots
private|:
name|void
name|getSetCheck
parameter_list|()
function_decl|;
name|void
name|minMaxSameValue
parameter_list|()
function_decl|;
name|void
name|destroyIndeterminate
parameter_list|()
function_decl|;
name|void
name|text
parameter_list|()
function_decl|;
name|void
name|format
parameter_list|()
function_decl|;
name|void
name|setValueRepaint
parameter_list|()
function_decl|;
ifndef|#
directive|ifndef
name|Q_OS_MAC
name|void
name|setMinMaxRepaint
parameter_list|()
function_decl|;
endif|#
directive|endif
name|void
name|sizeHint
parameter_list|()
function_decl|;
name|void
name|formatedText_data
parameter_list|()
function_decl|;
name|void
name|formatedText
parameter_list|()
function_decl|;
name|void
name|localizedFormattedText
parameter_list|()
function_decl|;
name|void
name|task245201_testChangeStyleAndDelete_data
parameter_list|()
function_decl|;
name|void
name|task245201_testChangeStyleAndDelete
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
name|tst_QProgressBar
operator|::
name|getSetCheck
parameter_list|()
block|{
name|QProgressBar
name|obj1
decl_stmt|;
comment|// bool QProgressBar::invertedAppearance()
comment|// void QProgressBar::setInvertedAppearance(bool)
name|obj1
operator|.
name|setInvertedAppearance
argument_list|(
literal|false
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
literal|false
argument_list|,
name|obj1
operator|.
name|invertedAppearance
argument_list|()
argument_list|)
expr_stmt|;
name|obj1
operator|.
name|setInvertedAppearance
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
literal|true
argument_list|,
name|obj1
operator|.
name|invertedAppearance
argument_list|()
argument_list|)
expr_stmt|;
comment|// int QProgressBar::minimum()
comment|// void QProgressBar::setMinimum(int)
name|obj1
operator|.
name|setMinimum
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
literal|0
argument_list|,
name|obj1
operator|.
name|minimum
argument_list|()
argument_list|)
expr_stmt|;
name|obj1
operator|.
name|setMinimum
argument_list|(
name|INT_MAX
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|INT_MAX
argument_list|,
name|obj1
operator|.
name|minimum
argument_list|()
argument_list|)
expr_stmt|;
name|obj1
operator|.
name|setMinimum
argument_list|(
name|INT_MIN
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|INT_MIN
argument_list|,
name|obj1
operator|.
name|minimum
argument_list|()
argument_list|)
expr_stmt|;
comment|// int QProgressBar::maximum()
comment|// void QProgressBar::setMaximum(int)
name|obj1
operator|.
name|setMaximum
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
literal|0
argument_list|,
name|obj1
operator|.
name|maximum
argument_list|()
argument_list|)
expr_stmt|;
name|obj1
operator|.
name|setMaximum
argument_list|(
name|INT_MIN
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|INT_MIN
argument_list|,
name|obj1
operator|.
name|maximum
argument_list|()
argument_list|)
expr_stmt|;
name|obj1
operator|.
name|setMaximum
argument_list|(
name|INT_MAX
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|INT_MAX
argument_list|,
name|obj1
operator|.
name|maximum
argument_list|()
argument_list|)
expr_stmt|;
comment|// int QProgressBar::value()
comment|// void QProgressBar::setValue(int)
name|obj1
operator|.
name|setValue
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
literal|0
argument_list|,
name|obj1
operator|.
name|value
argument_list|()
argument_list|)
expr_stmt|;
name|obj1
operator|.
name|setValue
argument_list|(
name|INT_MIN
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|INT_MIN
argument_list|,
name|obj1
operator|.
name|value
argument_list|()
argument_list|)
expr_stmt|;
name|obj1
operator|.
name|setValue
argument_list|(
name|INT_MAX
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|INT_MAX
argument_list|,
name|obj1
operator|.
name|value
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|minMaxSameValue
name|void
name|tst_QProgressBar
operator|::
name|minMaxSameValue
parameter_list|()
block|{
name|QProgressBar
name|bar
decl_stmt|;
name|bar
operator|.
name|setRange
argument_list|(
literal|10
argument_list|,
literal|10
argument_list|)
expr_stmt|;
name|bar
operator|.
name|setValue
argument_list|(
literal|10
argument_list|)
expr_stmt|;
name|bar
operator|.
name|move
argument_list|(
literal|300
argument_list|,
literal|300
argument_list|)
expr_stmt|;
name|bar
operator|.
name|show
argument_list|()
expr_stmt|;
name|QVERIFY
argument_list|(
name|QTest
operator|::
name|qWaitForWindowExposed
argument_list|(
operator|&
name|bar
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|destroyIndeterminate
name|void
name|tst_QProgressBar
operator|::
name|destroyIndeterminate
parameter_list|()
block|{
comment|// This test crashes on styles that animate indeterminate / busy
comment|// progressbars, and forget to remove the bars from internal logics when
comment|// it's deleted.
name|QPointer
argument_list|<
name|QProgressBar
argument_list|>
name|bar
init|=
operator|new
name|QProgressBar
decl_stmt|;
name|bar
operator|->
name|setMaximum
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|bar
operator|->
name|move
argument_list|(
literal|300
argument_list|,
literal|300
argument_list|)
expr_stmt|;
name|bar
operator|->
name|show
argument_list|()
expr_stmt|;
name|QVERIFY
argument_list|(
name|QTest
operator|::
name|qWaitForWindowExposed
argument_list|(
name|bar
operator|.
name|data
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|QEventLoop
name|loop
decl_stmt|;
name|QTimer
operator|::
name|singleShot
argument_list|(
literal|500
argument_list|,
name|bar
argument_list|,
name|SLOT
argument_list|(
name|deleteLater
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|QTimer
operator|::
name|singleShot
argument_list|(
literal|3000
argument_list|,
operator|&
name|loop
argument_list|,
name|SLOT
argument_list|(
name|quit
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|loop
operator|.
name|exec
argument_list|()
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|bar
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|text
name|void
name|tst_QProgressBar
operator|::
name|text
parameter_list|()
block|{
name|QProgressBar
name|bar
decl_stmt|;
name|bar
operator|.
name|setRange
argument_list|(
literal|10
argument_list|,
literal|10
argument_list|)
expr_stmt|;
name|bar
operator|.
name|setValue
argument_list|(
literal|10
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|bar
operator|.
name|text
argument_list|()
argument_list|,
name|QString
argument_list|(
literal|"100%"
argument_list|)
argument_list|)
expr_stmt|;
name|bar
operator|.
name|setRange
argument_list|(
literal|0
argument_list|,
literal|10
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|bar
operator|.
name|text
argument_list|()
argument_list|,
name|QString
argument_list|(
literal|"100%"
argument_list|)
argument_list|)
expr_stmt|;
name|bar
operator|.
name|setValue
argument_list|(
literal|5
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|bar
operator|.
name|text
argument_list|()
argument_list|,
name|QString
argument_list|(
literal|"50%"
argument_list|)
argument_list|)
expr_stmt|;
name|bar
operator|.
name|setRange
argument_list|(
literal|0
argument_list|,
literal|5
argument_list|)
expr_stmt|;
name|bar
operator|.
name|setValue
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|bar
operator|.
name|setRange
argument_list|(
literal|5
argument_list|,
literal|5
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|bar
operator|.
name|text
argument_list|()
argument_list|,
name|QString
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_class
DECL|class|ProgressBar
class|class
name|ProgressBar
super|:
specifier|public
name|QProgressBar
block|{
DECL|function|paintEvent
name|void
name|paintEvent
parameter_list|(
name|QPaintEvent
modifier|*
name|event
parameter_list|)
block|{
name|repainted
operator|=
literal|true
expr_stmt|;
name|QProgressBar
operator|::
name|paintEvent
argument_list|(
name|event
argument_list|)
expr_stmt|;
block|}
public|public:
DECL|member|repainted
name|bool
name|repainted
decl_stmt|;
using|using
name|QProgressBar
operator|::
name|initStyleOption
using|;
block|}
class|;
end_class
begin_function
DECL|function|format
name|void
name|tst_QProgressBar
operator|::
name|format
parameter_list|()
block|{
name|ProgressBar
name|bar
decl_stmt|;
name|bar
operator|.
name|setRange
argument_list|(
literal|0
argument_list|,
literal|10
argument_list|)
expr_stmt|;
name|bar
operator|.
name|setValue
argument_list|(
literal|1
argument_list|)
expr_stmt|;
name|bar
operator|.
name|move
argument_list|(
literal|300
argument_list|,
literal|300
argument_list|)
expr_stmt|;
name|bar
operator|.
name|show
argument_list|()
expr_stmt|;
name|QVERIFY
argument_list|(
name|QTest
operator|::
name|qWaitForWindowExposed
argument_list|(
operator|&
name|bar
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|QTest
operator|::
name|qWaitForWindowExposed
argument_list|(
operator|&
name|bar
argument_list|)
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|qWait
argument_list|(
literal|20
argument_list|)
expr_stmt|;
name|bar
operator|.
name|repainted
operator|=
literal|false
expr_stmt|;
name|bar
operator|.
name|setFormat
argument_list|(
literal|"%v of %m (%p%)"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|qWait
argument_list|(
literal|20
argument_list|)
expr_stmt|;
name|QTRY_VERIFY
argument_list|(
name|bar
operator|.
name|repainted
argument_list|)
expr_stmt|;
name|bar
operator|.
name|repainted
operator|=
literal|false
expr_stmt|;
name|bar
operator|.
name|setFormat
argument_list|(
literal|"%v of %m (%p%)"
argument_list|)
expr_stmt|;
name|qApp
operator|->
name|processEvents
argument_list|()
expr_stmt|;
ifndef|#
directive|ifndef
name|Q_OS_MAC
comment|// Animated scroll bars get paint events all the time
ifdef|#
directive|ifdef
name|Q_OS_WIN
if|if
condition|(
name|QSysInfo
operator|::
name|WindowsVersion
operator|<
name|QSysInfo
operator|::
name|WV_VISTA
condition|)
endif|#
directive|endif
name|QVERIFY
argument_list|(
operator|!
name|bar
operator|.
name|repainted
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|QCOMPARE
argument_list|(
name|bar
operator|.
name|text
argument_list|()
argument_list|,
name|QString
argument_list|(
literal|"1 of 10 (10%)"
argument_list|)
argument_list|)
expr_stmt|;
name|bar
operator|.
name|setRange
argument_list|(
literal|5
argument_list|,
literal|5
argument_list|)
expr_stmt|;
name|bar
operator|.
name|setValue
argument_list|(
literal|5
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|bar
operator|.
name|text
argument_list|()
argument_list|,
name|QString
argument_list|(
literal|"5 of 0 (100%)"
argument_list|)
argument_list|)
expr_stmt|;
name|bar
operator|.
name|setRange
argument_list|(
literal|0
argument_list|,
literal|5
argument_list|)
expr_stmt|;
name|bar
operator|.
name|setValue
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|bar
operator|.
name|setRange
argument_list|(
literal|5
argument_list|,
literal|5
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|bar
operator|.
name|text
argument_list|()
argument_list|,
name|QString
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|setValueRepaint
name|void
name|tst_QProgressBar
operator|::
name|setValueRepaint
parameter_list|()
block|{
name|ProgressBar
name|pbar
decl_stmt|;
name|pbar
operator|.
name|setMinimum
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|pbar
operator|.
name|setMaximum
argument_list|(
literal|10
argument_list|)
expr_stmt|;
name|pbar
operator|.
name|setFormat
argument_list|(
literal|"%v"
argument_list|)
expr_stmt|;
name|pbar
operator|.
name|move
argument_list|(
literal|300
argument_list|,
literal|300
argument_list|)
expr_stmt|;
name|pbar
operator|.
name|show
argument_list|()
expr_stmt|;
name|QVERIFY
argument_list|(
name|QTest
operator|::
name|qWaitForWindowExposed
argument_list|(
operator|&
name|pbar
argument_list|)
argument_list|)
expr_stmt|;
name|QApplication
operator|::
name|processEvents
argument_list|()
expr_stmt|;
for|for
control|(
name|int
name|i
init|=
name|pbar
operator|.
name|minimum
argument_list|()
init|;
name|i
operator|<
name|pbar
operator|.
name|maximum
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
name|pbar
operator|.
name|repainted
operator|=
literal|false
expr_stmt|;
name|pbar
operator|.
name|setValue
argument_list|(
name|i
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|qWait
argument_list|(
literal|50
argument_list|)
expr_stmt|;
name|QTRY_VERIFY
argument_list|(
name|pbar
operator|.
name|repainted
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_comment
comment|// This test is invalid on Mac, since progressbars
end_comment
begin_comment
comment|// are animated there
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|Q_OS_MAC
end_ifndef
begin_function
DECL|function|setMinMaxRepaint
name|void
name|tst_QProgressBar
operator|::
name|setMinMaxRepaint
parameter_list|()
block|{
name|ProgressBar
name|pbar
decl_stmt|;
name|pbar
operator|.
name|setMinimum
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|pbar
operator|.
name|setMaximum
argument_list|(
literal|10
argument_list|)
expr_stmt|;
name|pbar
operator|.
name|setFormat
argument_list|(
literal|"%v"
argument_list|)
expr_stmt|;
name|pbar
operator|.
name|move
argument_list|(
literal|300
argument_list|,
literal|300
argument_list|)
expr_stmt|;
name|pbar
operator|.
name|show
argument_list|()
expr_stmt|;
name|qApp
operator|->
name|setActiveWindow
argument_list|(
operator|&
name|pbar
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|QTest
operator|::
name|qWaitForWindowActive
argument_list|(
operator|&
name|pbar
argument_list|)
argument_list|)
expr_stmt|;
comment|// No repaint when setting minimum to the current minimum
name|pbar
operator|.
name|repainted
operator|=
literal|false
expr_stmt|;
name|pbar
operator|.
name|setMinimum
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|qWait
argument_list|(
literal|50
argument_list|)
expr_stmt|;
name|QTRY_VERIFY
argument_list|(
operator|!
name|pbar
operator|.
name|repainted
argument_list|)
expr_stmt|;
comment|// No repaint when setting maximum to the current maximum
name|pbar
operator|.
name|repainted
operator|=
literal|false
expr_stmt|;
name|pbar
operator|.
name|setMaximum
argument_list|(
literal|10
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|qWait
argument_list|(
literal|50
argument_list|)
expr_stmt|;
name|QTRY_VERIFY
argument_list|(
operator|!
name|pbar
operator|.
name|repainted
argument_list|)
expr_stmt|;
comment|// Repaint when setting minimum
for|for
control|(
name|int
name|i
init|=
literal|9
init|;
name|i
operator|>=
literal|0
condition|;
name|i
operator|--
control|)
block|{
name|pbar
operator|.
name|repainted
operator|=
literal|false
expr_stmt|;
name|pbar
operator|.
name|setMinimum
argument_list|(
name|i
argument_list|)
expr_stmt|;
name|QTRY_VERIFY
argument_list|(
name|pbar
operator|.
name|repainted
argument_list|)
expr_stmt|;
block|}
comment|// Repaint when setting maximum
for|for
control|(
name|int
name|i
init|=
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
name|pbar
operator|.
name|repainted
operator|=
literal|false
expr_stmt|;
name|pbar
operator|.
name|setMaximum
argument_list|(
name|i
argument_list|)
expr_stmt|;
name|QTRY_VERIFY
argument_list|(
name|pbar
operator|.
name|repainted
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|//Q_OS_MAC
end_comment
begin_function
DECL|function|sizeHint
name|void
name|tst_QProgressBar
operator|::
name|sizeHint
parameter_list|()
block|{
name|ProgressBar
name|bar
decl_stmt|;
name|bar
operator|.
name|setMinimum
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|bar
operator|.
name|setMaximum
argument_list|(
literal|10
argument_list|)
expr_stmt|;
name|bar
operator|.
name|setValue
argument_list|(
literal|5
argument_list|)
expr_stmt|;
comment|//test if the sizeHint is big enough
name|QFontMetrics
name|fm
init|=
name|bar
operator|.
name|fontMetrics
argument_list|()
decl_stmt|;
name|QStyleOptionProgressBarV2
name|opt
decl_stmt|;
name|bar
operator|.
name|initStyleOption
argument_list|(
operator|&
name|opt
argument_list|)
expr_stmt|;
name|QSize
name|size
init|=
name|QSize
argument_list|(
literal|9
operator|*
literal|7
operator|+
name|fm
operator|.
name|width
argument_list|(
name|QLatin1Char
argument_list|(
literal|'0'
argument_list|)
argument_list|)
operator|*
literal|4
argument_list|,
name|fm
operator|.
name|height
argument_list|()
operator|+
literal|8
argument_list|)
decl_stmt|;
name|size
operator|=
name|bar
operator|.
name|style
argument_list|()
operator|->
name|sizeFromContents
argument_list|(
name|QStyle
operator|::
name|CT_ProgressBar
argument_list|,
operator|&
name|opt
argument_list|,
name|size
argument_list|,
operator|&
name|bar
argument_list|)
expr_stmt|;
name|QSize
name|barSize
init|=
name|bar
operator|.
name|sizeHint
argument_list|()
decl_stmt|;
name|QVERIFY
argument_list|(
name|barSize
operator|.
name|width
argument_list|()
operator|>=
name|size
operator|.
name|width
argument_list|()
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|barSize
operator|.
name|height
argument_list|()
argument_list|,
name|size
operator|.
name|height
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|formatedText_data
name|void
name|tst_QProgressBar
operator|::
name|formatedText_data
parameter_list|()
block|{
name|QTest
operator|::
name|addColumn
argument_list|<
name|int
argument_list|>
argument_list|(
literal|"minimum"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|int
argument_list|>
argument_list|(
literal|"maximum"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|int
argument_list|>
argument_list|(
literal|"value"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|QString
argument_list|>
argument_list|(
literal|"format"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|QString
argument_list|>
argument_list|(
literal|"text"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"1"
argument_list|)
operator|<<
operator|-
literal|100
operator|<<
literal|100
operator|<<
literal|0
operator|<<
name|QString
operator|::
name|fromLatin1
argument_list|(
literal|" %p - %v - %m "
argument_list|)
operator|<<
name|QString
operator|::
name|fromLatin1
argument_list|(
literal|" 50 - 0 - 200 "
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"2"
argument_list|)
operator|<<
operator|-
literal|100
operator|<<
literal|0
operator|<<
operator|-
literal|25
operator|<<
name|QString
operator|::
name|fromLatin1
argument_list|(
literal|" %p - %v - %m "
argument_list|)
operator|<<
name|QString
operator|::
name|fromLatin1
argument_list|(
literal|" 75 - -25 - 100 "
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"3"
argument_list|)
operator|<<
literal|10
operator|<<
literal|10
operator|<<
literal|10
operator|<<
name|QString
operator|::
name|fromLatin1
argument_list|(
literal|" %p - %v - %m "
argument_list|)
operator|<<
name|QString
operator|::
name|fromLatin1
argument_list|(
literal|" 100 - 10 - 0 "
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"task152227"
argument_list|)
operator|<<
name|INT_MIN
operator|<<
name|INT_MAX
operator|<<
literal|42
operator|<<
name|QString
operator|::
name|fromLatin1
argument_list|(
literal|" %p - %v - %m "
argument_list|)
operator|<<
name|QString
operator|::
name|fromLatin1
argument_list|(
literal|" 50 - 42 - 4294967295 "
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|formatedText
name|void
name|tst_QProgressBar
operator|::
name|formatedText
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|int
argument_list|,
name|minimum
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|int
argument_list|,
name|maximum
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|int
argument_list|,
name|value
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|QString
argument_list|,
name|format
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|QString
argument_list|,
name|text
argument_list|)
expr_stmt|;
name|QProgressBar
name|bar
decl_stmt|;
name|bar
operator|.
name|setRange
argument_list|(
name|minimum
argument_list|,
name|maximum
argument_list|)
expr_stmt|;
name|bar
operator|.
name|setValue
argument_list|(
name|value
argument_list|)
expr_stmt|;
name|bar
operator|.
name|setFormat
argument_list|(
name|format
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|bar
operator|.
name|text
argument_list|()
argument_list|,
name|text
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|localizedFormattedText
name|void
name|tst_QProgressBar
operator|::
name|localizedFormattedText
parameter_list|()
comment|// QTBUG-28751
block|{
name|QProgressBar
name|bar
decl_stmt|;
specifier|const
name|int
name|value
init|=
literal|42
decl_stmt|;
name|bar
operator|.
name|setValue
argument_list|(
name|value
argument_list|)
expr_stmt|;
specifier|const
name|QString
name|defaultExpectedNumber
init|=
name|QString
operator|::
name|number
argument_list|(
name|value
argument_list|)
decl_stmt|;
specifier|const
name|QString
name|defaultExpectedValue
init|=
name|defaultExpectedNumber
operator|+
name|QLatin1Char
argument_list|(
literal|'%'
argument_list|)
decl_stmt|;
name|QCOMPARE
argument_list|(
name|bar
operator|.
name|text
argument_list|()
argument_list|,
name|defaultExpectedValue
argument_list|)
expr_stmt|;
comment|// Temporarily switch to Egyptian, which has a different percent sign and number formatting
name|QLocale
name|egypt
argument_list|(
name|QLocale
operator|::
name|Arabic
argument_list|,
name|QLocale
operator|::
name|Egypt
argument_list|)
decl_stmt|;
name|bar
operator|.
name|setLocale
argument_list|(
name|egypt
argument_list|)
expr_stmt|;
specifier|const
name|QString
name|egyptianExpectedNumber
init|=
name|egypt
operator|.
name|toString
argument_list|(
name|value
argument_list|)
decl_stmt|;
specifier|const
name|QString
name|egyptianExpectedValue
init|=
name|egyptianExpectedNumber
operator|+
name|egypt
operator|.
name|percent
argument_list|()
decl_stmt|;
if|if
condition|(
name|egyptianExpectedValue
operator|==
name|defaultExpectedValue
condition|)
name|QSKIP
argument_list|(
literal|"Egyptian locale does not work on this system."
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|bar
operator|.
name|text
argument_list|()
argument_list|,
name|egyptianExpectedValue
argument_list|)
expr_stmt|;
name|bar
operator|.
name|setLocale
argument_list|(
name|QLocale
argument_list|()
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|bar
operator|.
name|text
argument_list|()
argument_list|,
name|defaultExpectedValue
argument_list|)
expr_stmt|;
comment|// Set a custom format containing only the number
name|bar
operator|.
name|setFormat
argument_list|(
name|QStringLiteral
argument_list|(
literal|"%p"
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|bar
operator|.
name|text
argument_list|()
argument_list|,
name|defaultExpectedNumber
argument_list|)
expr_stmt|;
name|bar
operator|.
name|setLocale
argument_list|(
name|egypt
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|bar
operator|.
name|text
argument_list|()
argument_list|,
name|egyptianExpectedNumber
argument_list|)
expr_stmt|;
comment|// Clear the format
name|bar
operator|.
name|resetFormat
argument_list|()
expr_stmt|;
name|QCOMPARE
argument_list|(
name|bar
operator|.
name|text
argument_list|()
argument_list|,
name|egyptianExpectedValue
argument_list|)
expr_stmt|;
name|bar
operator|.
name|setLocale
argument_list|(
name|QLocale
argument_list|()
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|bar
operator|.
name|text
argument_list|()
argument_list|,
name|defaultExpectedValue
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|task245201_testChangeStyleAndDelete_data
name|void
name|tst_QProgressBar
operator|::
name|task245201_testChangeStyleAndDelete_data
parameter_list|()
block|{
name|QTest
operator|::
name|addColumn
argument_list|<
name|QString
argument_list|>
argument_list|(
literal|"style1_str"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|QString
argument_list|>
argument_list|(
literal|"style2_str"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"fusion-windows"
argument_list|)
operator|<<
name|QString
operator|::
name|fromLatin1
argument_list|(
literal|"fusion"
argument_list|)
operator|<<
name|QString
operator|::
name|fromLatin1
argument_list|(
literal|"windows"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"gtk-fusion"
argument_list|)
operator|<<
name|QString
operator|::
name|fromLatin1
argument_list|(
literal|"gtk"
argument_list|)
operator|<<
name|QString
operator|::
name|fromLatin1
argument_list|(
literal|"fusion"
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|task245201_testChangeStyleAndDelete
name|void
name|tst_QProgressBar
operator|::
name|task245201_testChangeStyleAndDelete
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|QString
argument_list|,
name|style1_str
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|QString
argument_list|,
name|style2_str
argument_list|)
expr_stmt|;
name|QProgressBar
modifier|*
name|bar
init|=
operator|new
name|QProgressBar
decl_stmt|;
name|QStyle
modifier|*
name|style
init|=
name|QStyleFactory
operator|::
name|create
argument_list|(
name|style1_str
argument_list|)
decl_stmt|;
name|bar
operator|->
name|setStyle
argument_list|(
name|style
argument_list|)
expr_stmt|;
name|bar
operator|->
name|move
argument_list|(
literal|300
argument_list|,
literal|300
argument_list|)
expr_stmt|;
name|bar
operator|->
name|show
argument_list|()
expr_stmt|;
name|QVERIFY
argument_list|(
name|QTest
operator|::
name|qWaitForWindowExposed
argument_list|(
name|bar
argument_list|)
argument_list|)
expr_stmt|;
name|QStyle
modifier|*
name|style2
init|=
name|QStyleFactory
operator|::
name|create
argument_list|(
name|style2_str
argument_list|)
decl_stmt|;
name|bar
operator|->
name|setStyle
argument_list|(
name|style2
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|qWait
argument_list|(
literal|10
argument_list|)
expr_stmt|;
operator|delete
name|bar
expr_stmt|;
name|QTest
operator|::
name|qWait
argument_list|(
literal|100
argument_list|)
expr_stmt|;
comment|//should not crash
operator|delete
name|style
expr_stmt|;
operator|delete
name|style2
expr_stmt|;
block|}
end_function
begin_macro
name|QTEST_MAIN
argument_list|(
argument|tst_QProgressBar
argument_list|)
end_macro
begin_include
include|#
directive|include
file|"tst_qprogressbar.moc"
end_include
end_unit
