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
file|<QtGui/QtGui>
end_include
begin_include
include|#
directive|include
file|<qeventloop.h>
end_include
begin_include
include|#
directive|include
file|<qlist.h>
end_include
begin_include
include|#
directive|include
file|<qlistwidget.h>
end_include
begin_ifdef
ifdef|#
directive|ifdef
name|Q_WS_X11
end_ifdef
begin_include
include|#
directive|include
file|<X11/Xlib.h>
end_include
begin_include
include|#
directive|include
file|<QX11Info>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// Q_WS_X11
end_comment
begin_class
DECL|class|tst_QWidget_window
class|class
name|tst_QWidget_window
super|:
specifier|public
name|QWidget
block|{
name|Q_OBJECT
public|public:
DECL|function|tst_QWidget_window
name|tst_QWidget_window
parameter_list|()
block|{}
empty_stmt|;
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
private|private
name|slots
private|:
name|void
name|tst_move_show
parameter_list|()
function_decl|;
name|void
name|tst_show_move
parameter_list|()
function_decl|;
name|void
name|tst_show_move_hide_show
parameter_list|()
function_decl|;
name|void
name|tst_resize_show
parameter_list|()
function_decl|;
name|void
name|tst_show_resize
parameter_list|()
function_decl|;
name|void
name|tst_show_resize_hide_show
parameter_list|()
function_decl|;
name|void
name|tst_windowFilePathAndwindowTitle_data
parameter_list|()
function_decl|;
name|void
name|tst_windowFilePathAndwindowTitle
parameter_list|()
function_decl|;
name|void
name|tst_windowFilePath_data
parameter_list|()
function_decl|;
name|void
name|tst_windowFilePath
parameter_list|()
function_decl|;
name|void
name|tst_showWithoutActivating
parameter_list|()
function_decl|;
name|void
name|tst_paintEventOnSecondShow
parameter_list|()
function_decl|;
block|}
class|;
end_class
begin_function
DECL|function|initTestCase
name|void
name|tst_QWidget_window
operator|::
name|initTestCase
parameter_list|()
block|{ }
end_function
begin_function
DECL|function|cleanupTestCase
name|void
name|tst_QWidget_window
operator|::
name|cleanupTestCase
parameter_list|()
block|{ }
end_function
begin_function
DECL|function|tst_move_show
name|void
name|tst_QWidget_window
operator|::
name|tst_move_show
parameter_list|()
block|{
ifdef|#
directive|ifdef
name|Q_OS_WIN
name|QSKIP
argument_list|(
literal|"QTBUG-25331"
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|QWidget
name|w
decl_stmt|;
name|w
operator|.
name|move
argument_list|(
literal|100
argument_list|,
literal|100
argument_list|)
expr_stmt|;
name|w
operator|.
name|show
argument_list|()
expr_stmt|;
name|QCOMPARE
argument_list|(
name|w
operator|.
name|pos
argument_list|()
argument_list|,
name|QPoint
argument_list|(
literal|100
argument_list|,
literal|100
argument_list|)
argument_list|)
expr_stmt|;
comment|//    QCoreApplication::processEvents(QEventLoop::AllEvents, 3000);
block|}
end_function
begin_function
DECL|function|tst_show_move
name|void
name|tst_QWidget_window
operator|::
name|tst_show_move
parameter_list|()
block|{
name|QWidget
name|w
decl_stmt|;
name|w
operator|.
name|show
argument_list|()
expr_stmt|;
name|w
operator|.
name|move
argument_list|(
literal|100
argument_list|,
literal|100
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|w
operator|.
name|pos
argument_list|()
argument_list|,
name|QPoint
argument_list|(
literal|100
argument_list|,
literal|100
argument_list|)
argument_list|)
expr_stmt|;
comment|//    QCoreApplication::processEvents(QEventLoop::AllEvents, 1000);
block|}
end_function
begin_function
DECL|function|tst_show_move_hide_show
name|void
name|tst_QWidget_window
operator|::
name|tst_show_move_hide_show
parameter_list|()
block|{
name|QWidget
name|w
decl_stmt|;
name|w
operator|.
name|show
argument_list|()
expr_stmt|;
name|w
operator|.
name|move
argument_list|(
literal|100
argument_list|,
literal|100
argument_list|)
expr_stmt|;
name|w
operator|.
name|hide
argument_list|()
expr_stmt|;
name|w
operator|.
name|show
argument_list|()
expr_stmt|;
name|QCOMPARE
argument_list|(
name|w
operator|.
name|pos
argument_list|()
argument_list|,
name|QPoint
argument_list|(
literal|100
argument_list|,
literal|100
argument_list|)
argument_list|)
expr_stmt|;
comment|//    QCoreApplication::processEvents(QEventLoop::AllEvents, 1000);
block|}
end_function
begin_function
DECL|function|tst_resize_show
name|void
name|tst_QWidget_window
operator|::
name|tst_resize_show
parameter_list|()
block|{
name|QWidget
name|w
decl_stmt|;
name|w
operator|.
name|resize
argument_list|(
literal|200
argument_list|,
literal|200
argument_list|)
expr_stmt|;
name|w
operator|.
name|show
argument_list|()
expr_stmt|;
name|QCOMPARE
argument_list|(
name|w
operator|.
name|size
argument_list|()
argument_list|,
name|QSize
argument_list|(
literal|200
argument_list|,
literal|200
argument_list|)
argument_list|)
expr_stmt|;
comment|//    QCoreApplication::processEvents(QEventLoop::AllEvents, 1000);
block|}
end_function
begin_function
DECL|function|tst_show_resize
name|void
name|tst_QWidget_window
operator|::
name|tst_show_resize
parameter_list|()
block|{
name|QWidget
name|w
decl_stmt|;
name|w
operator|.
name|show
argument_list|()
expr_stmt|;
name|w
operator|.
name|resize
argument_list|(
literal|200
argument_list|,
literal|200
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|w
operator|.
name|size
argument_list|()
argument_list|,
name|QSize
argument_list|(
literal|200
argument_list|,
literal|200
argument_list|)
argument_list|)
expr_stmt|;
comment|//    QCoreApplication::processEvents(QEventLoop::AllEvents, 1000);
block|}
end_function
begin_function
DECL|function|tst_show_resize_hide_show
name|void
name|tst_QWidget_window
operator|::
name|tst_show_resize_hide_show
parameter_list|()
block|{
name|QWidget
name|w
decl_stmt|;
name|w
operator|.
name|show
argument_list|()
expr_stmt|;
name|w
operator|.
name|resize
argument_list|(
literal|200
argument_list|,
literal|200
argument_list|)
expr_stmt|;
name|w
operator|.
name|hide
argument_list|()
expr_stmt|;
name|w
operator|.
name|show
argument_list|()
expr_stmt|;
name|QCOMPARE
argument_list|(
name|w
operator|.
name|size
argument_list|()
argument_list|,
name|QSize
argument_list|(
literal|200
argument_list|,
literal|200
argument_list|)
argument_list|)
expr_stmt|;
comment|//    QCoreApplication::processEvents(QEventLoop::AllEvents, 1000);
block|}
end_function
begin_class
DECL|class|TestWidget
class|class
name|TestWidget
super|:
specifier|public
name|QWidget
block|{
public|public:
DECL|member|m_first
DECL|member|m_next
name|int
name|m_first
decl_stmt|,
name|m_next
decl_stmt|;
DECL|member|paintEventReceived
name|bool
name|paintEventReceived
decl_stmt|;
DECL|function|reset
name|void
name|reset
parameter_list|()
block|{
name|m_first
operator|=
name|m_next
operator|=
literal|0
expr_stmt|;
name|paintEventReceived
operator|=
literal|false
expr_stmt|;
block|}
DECL|function|event
name|bool
name|event
parameter_list|(
name|QEvent
modifier|*
name|event
parameter_list|)
block|{
switch|switch
condition|(
name|event
operator|->
name|type
argument_list|()
condition|)
block|{
case|case
name|QEvent
operator|::
name|WindowActivate
case|:
case|case
name|QEvent
operator|::
name|WindowDeactivate
case|:
case|case
name|QEvent
operator|::
name|Hide
case|:
case|case
name|QEvent
operator|::
name|Show
case|:
if|if
condition|(
name|m_first
condition|)
name|m_next
operator|=
name|event
operator|->
name|type
argument_list|()
expr_stmt|;
else|else
name|m_first
operator|=
name|event
operator|->
name|type
argument_list|()
expr_stmt|;
break|break;
case|case
name|QEvent
operator|::
name|Paint
case|:
name|paintEventReceived
operator|=
literal|true
expr_stmt|;
break|break;
default|default:
break|break;
block|}
return|return
name|QWidget
operator|::
name|event
argument_list|(
name|event
argument_list|)
return|;
block|}
block|}
class|;
end_class
begin_function
DECL|function|tst_windowFilePathAndwindowTitle_data
name|void
name|tst_QWidget_window
operator|::
name|tst_windowFilePathAndwindowTitle_data
parameter_list|()
block|{
name|QTest
operator|::
name|addColumn
argument_list|<
name|bool
argument_list|>
argument_list|(
literal|"setWindowTitleBefore"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|bool
argument_list|>
argument_list|(
literal|"setWindowTitleAfter"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|QString
argument_list|>
argument_list|(
literal|"filePath"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|QString
argument_list|>
argument_list|(
literal|"applicationName"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|QString
argument_list|>
argument_list|(
literal|"indyWindowTitle"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|QString
argument_list|>
argument_list|(
literal|"finalTitleBefore"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|QString
argument_list|>
argument_list|(
literal|"finalTitleAfter"
argument_list|)
expr_stmt|;
name|QString
name|validPath
init|=
name|QApplication
operator|::
name|applicationFilePath
argument_list|()
decl_stmt|;
name|QString
name|appName
init|=
name|QLatin1String
argument_list|(
literal|"Killer App"
argument_list|)
decl_stmt|;
name|QString
name|fileNameOnly
init|=
name|QFileInfo
argument_list|(
name|validPath
argument_list|)
operator|.
name|fileName
argument_list|()
operator|+
name|QLatin1String
argument_list|(
literal|"[*]"
argument_list|)
decl_stmt|;
name|QString
name|fileAndApp
init|=
name|fileNameOnly
operator|+
name|QLatin1String
argument_list|(
literal|" "
argument_list|)
operator|+
name|QChar
argument_list|(
literal|0x2014
argument_list|)
operator|+
name|QLatin1String
argument_list|(
literal|" "
argument_list|)
operator|+
name|appName
decl_stmt|;
name|QString
name|windowTitle
init|=
name|QLatin1String
argument_list|(
literal|"Here is a Window Title"
argument_list|)
decl_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"never Set Title nor AppName"
argument_list|)
operator|<<
literal|false
operator|<<
literal|false
operator|<<
name|validPath
operator|<<
name|QString
argument_list|()
operator|<<
name|windowTitle
operator|<<
name|fileNameOnly
operator|<<
name|fileNameOnly
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"set title after only, but no AppName"
argument_list|)
operator|<<
literal|false
operator|<<
literal|true
operator|<<
name|validPath
operator|<<
name|QString
argument_list|()
operator|<<
name|windowTitle
operator|<<
name|fileNameOnly
operator|<<
name|windowTitle
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"set title before only, not AppName"
argument_list|)
operator|<<
literal|true
operator|<<
literal|false
operator|<<
name|validPath
operator|<<
name|QString
argument_list|()
operator|<<
name|windowTitle
operator|<<
name|windowTitle
operator|<<
name|windowTitle
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"always set title, not appName"
argument_list|)
operator|<<
literal|true
operator|<<
literal|true
operator|<<
name|validPath
operator|<<
name|QString
argument_list|()
operator|<<
name|windowTitle
operator|<<
name|windowTitle
operator|<<
name|windowTitle
expr_stmt|;
name|QString
name|platString
init|=
ifdef|#
directive|ifdef
name|Q_OS_MAC
name|fileNameOnly
decl_stmt|;
else|#
directive|else
name|fileAndApp
expr_stmt|;
endif|#
directive|endif
name|QTest
operator|::
name|newRow
argument_list|(
literal|"never Set Title, yes AppName"
argument_list|)
operator|<<
literal|false
operator|<<
literal|false
operator|<<
name|validPath
operator|<<
name|appName
operator|<<
name|windowTitle
operator|<<
name|platString
operator|<<
name|platString
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"set title after only, yes AppName"
argument_list|)
operator|<<
literal|false
operator|<<
literal|true
operator|<<
name|validPath
operator|<<
name|appName
operator|<<
name|windowTitle
operator|<<
name|platString
operator|<<
name|windowTitle
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"set title before only, yes AppName"
argument_list|)
operator|<<
literal|true
operator|<<
literal|false
operator|<<
name|validPath
operator|<<
name|appName
operator|<<
name|windowTitle
operator|<<
name|windowTitle
operator|<<
name|windowTitle
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"always set title, yes appName"
argument_list|)
operator|<<
literal|true
operator|<<
literal|true
operator|<<
name|validPath
operator|<<
name|appName
operator|<<
name|windowTitle
operator|<<
name|windowTitle
operator|<<
name|windowTitle
expr_stmt|;
block|}
end_function
begin_function
DECL|function|tst_windowFilePathAndwindowTitle
name|void
name|tst_QWidget_window
operator|::
name|tst_windowFilePathAndwindowTitle
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|bool
argument_list|,
name|setWindowTitleBefore
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|bool
argument_list|,
name|setWindowTitleAfter
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|QString
argument_list|,
name|filePath
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|QString
argument_list|,
name|applicationName
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|QString
argument_list|,
name|indyWindowTitle
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|QString
argument_list|,
name|finalTitleBefore
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|QString
argument_list|,
name|finalTitleAfter
argument_list|)
expr_stmt|;
name|QWidget
name|widget
decl_stmt|;
name|QCOMPARE
argument_list|(
name|widget
operator|.
name|windowFilePath
argument_list|()
argument_list|,
name|QString
argument_list|()
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|applicationName
operator|.
name|isEmpty
argument_list|()
condition|)
name|qApp
operator|->
name|setApplicationName
argument_list|(
name|applicationName
argument_list|)
expr_stmt|;
else|else
name|qApp
operator|->
name|setApplicationName
argument_list|(
name|QString
argument_list|()
argument_list|)
expr_stmt|;
if|if
condition|(
name|setWindowTitleBefore
condition|)
block|{
name|widget
operator|.
name|setWindowTitle
argument_list|(
name|indyWindowTitle
argument_list|)
expr_stmt|;
block|}
name|widget
operator|.
name|setWindowFilePath
argument_list|(
name|filePath
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|Q_OS_MAC
name|QEXPECT_FAIL
argument_list|(
literal|"never Set Title, yes AppName"
argument_list|,
literal|"QTBUG-23682"
argument_list|,
name|Continue
argument_list|)
expr_stmt|;
name|QEXPECT_FAIL
argument_list|(
literal|"set title after only, yes AppName"
argument_list|,
literal|"QTBUG-23682"
argument_list|,
name|Continue
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|QCOMPARE
argument_list|(
name|finalTitleBefore
argument_list|,
name|widget
operator|.
name|windowTitle
argument_list|()
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|widget
operator|.
name|windowFilePath
argument_list|()
argument_list|,
name|filePath
argument_list|)
expr_stmt|;
if|if
condition|(
name|setWindowTitleAfter
condition|)
block|{
name|widget
operator|.
name|setWindowTitle
argument_list|(
name|indyWindowTitle
argument_list|)
expr_stmt|;
block|}
ifdef|#
directive|ifdef
name|Q_OS_MAC
name|QEXPECT_FAIL
argument_list|(
literal|"never Set Title, yes AppName"
argument_list|,
literal|"QTBUG-23682"
argument_list|,
name|Continue
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|QCOMPARE
argument_list|(
name|finalTitleAfter
argument_list|,
name|widget
operator|.
name|windowTitle
argument_list|()
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|widget
operator|.
name|windowFilePath
argument_list|()
argument_list|,
name|filePath
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|tst_windowFilePath_data
name|void
name|tst_QWidget_window
operator|::
name|tst_windowFilePath_data
parameter_list|()
block|{
name|QTest
operator|::
name|addColumn
argument_list|<
name|QString
argument_list|>
argument_list|(
literal|"filePath"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|QString
argument_list|>
argument_list|(
literal|"result"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|bool
argument_list|>
argument_list|(
literal|"again"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|QString
argument_list|>
argument_list|(
literal|"filePath2"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|QString
argument_list|>
argument_list|(
literal|"result2"
argument_list|)
expr_stmt|;
name|QString
name|validPath
init|=
name|QApplication
operator|::
name|applicationFilePath
argument_list|()
decl_stmt|;
name|QString
name|invalidPath
init|=
name|QLatin1String
argument_list|(
literal|"::**Never a Real Path**::"
argument_list|)
decl_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"never Set Path"
argument_list|)
operator|<<
name|QString
argument_list|()
operator|<<
name|QString
argument_list|()
operator|<<
literal|false
operator|<<
name|QString
argument_list|()
operator|<<
name|QString
argument_list|()
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"never EVER Set Path"
argument_list|)
operator|<<
name|QString
argument_list|()
operator|<<
name|QString
argument_list|()
operator|<<
literal|true
operator|<<
name|QString
argument_list|()
operator|<<
name|QString
argument_list|()
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"Valid Path"
argument_list|)
operator|<<
name|validPath
operator|<<
name|validPath
operator|<<
literal|false
operator|<<
name|QString
argument_list|()
operator|<<
name|QString
argument_list|()
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"invalid Path"
argument_list|)
operator|<<
name|invalidPath
operator|<<
name|invalidPath
operator|<<
literal|false
operator|<<
name|QString
argument_list|()
operator|<<
name|QString
argument_list|()
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"Valid Path then empty"
argument_list|)
operator|<<
name|validPath
operator|<<
name|validPath
operator|<<
literal|true
operator|<<
name|QString
argument_list|()
operator|<<
name|QString
argument_list|()
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"invalid Path then empty"
argument_list|)
operator|<<
name|invalidPath
operator|<<
name|invalidPath
operator|<<
literal|true
operator|<<
name|QString
argument_list|()
operator|<<
name|QString
argument_list|()
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"invalid Path then valid"
argument_list|)
operator|<<
name|invalidPath
operator|<<
name|invalidPath
operator|<<
literal|true
operator|<<
name|validPath
operator|<<
name|validPath
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"valid Path then invalid"
argument_list|)
operator|<<
name|validPath
operator|<<
name|validPath
operator|<<
literal|true
operator|<<
name|invalidPath
operator|<<
name|invalidPath
expr_stmt|;
block|}
end_function
begin_function
DECL|function|tst_windowFilePath
name|void
name|tst_QWidget_window
operator|::
name|tst_windowFilePath
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|QString
argument_list|,
name|filePath
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|QString
argument_list|,
name|result
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|bool
argument_list|,
name|again
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|QString
argument_list|,
name|filePath2
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|QString
argument_list|,
name|result2
argument_list|)
expr_stmt|;
name|QWidget
name|widget
decl_stmt|;
name|QCOMPARE
argument_list|(
name|widget
operator|.
name|windowFilePath
argument_list|()
argument_list|,
name|QString
argument_list|()
argument_list|)
expr_stmt|;
name|widget
operator|.
name|setWindowFilePath
argument_list|(
name|filePath
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|widget
operator|.
name|windowFilePath
argument_list|()
argument_list|,
name|result
argument_list|)
expr_stmt|;
if|if
condition|(
name|again
condition|)
block|{
name|widget
operator|.
name|setWindowFilePath
argument_list|(
name|filePath2
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|widget
operator|.
name|windowFilePath
argument_list|()
argument_list|,
name|result2
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|tst_showWithoutActivating
name|void
name|tst_QWidget_window
operator|::
name|tst_showWithoutActivating
parameter_list|()
block|{
ifndef|#
directive|ifndef
name|Q_WS_X11
name|QSKIP
argument_list|(
literal|"This test is X11-only."
argument_list|)
expr_stmt|;
else|#
directive|else
name|QWidget
name|w
decl_stmt|;
name|w
operator|.
name|show
argument_list|()
expr_stmt|;
name|QTest
operator|::
name|qWaitForWindowShown
argument_list|(
operator|&
name|w
argument_list|)
expr_stmt|;
name|QApplication
operator|::
name|processEvents
argument_list|()
expr_stmt|;
name|QApplication
operator|::
name|clipboard
argument_list|()
expr_stmt|;
name|QLineEdit
modifier|*
name|lineEdit
init|=
operator|new
name|QLineEdit
decl_stmt|;
name|lineEdit
operator|->
name|setAttribute
argument_list|(
name|Qt
operator|::
name|WA_ShowWithoutActivating
argument_list|,
literal|true
argument_list|)
expr_stmt|;
name|lineEdit
operator|->
name|show
argument_list|()
expr_stmt|;
name|lineEdit
operator|->
name|setAttribute
argument_list|(
name|Qt
operator|::
name|WA_ShowWithoutActivating
argument_list|,
literal|false
argument_list|)
expr_stmt|;
name|lineEdit
operator|->
name|raise
argument_list|()
expr_stmt|;
name|lineEdit
operator|->
name|activateWindow
argument_list|()
expr_stmt|;
name|Window
name|window
decl_stmt|;
name|int
name|revertto
decl_stmt|;
name|QTRY_COMPARE
argument_list|(
name|lineEdit
operator|->
name|winId
argument_list|()
argument_list|,
operator|(
name|XGetInputFocus
argument_list|(
name|QX11Info
operator|::
name|display
argument_list|()
argument_list|,
operator|&
name|window
argument_list|,
operator|&
name|revertto
argument_list|)
operator|,
name|window
operator|)
argument_list|)
expr_stmt|;
comment|// Note the use of the , before window because we want the XGetInputFocus to be re-executed
comment|//     in each iteration of the inside loop of the QTRY_COMPARE macro
endif|#
directive|endif
comment|// Q_WS_X11
block|}
end_function
begin_function
DECL|function|tst_paintEventOnSecondShow
name|void
name|tst_QWidget_window
operator|::
name|tst_paintEventOnSecondShow
parameter_list|()
block|{
name|TestWidget
name|w
decl_stmt|;
name|w
operator|.
name|show
argument_list|()
expr_stmt|;
name|w
operator|.
name|hide
argument_list|()
expr_stmt|;
name|w
operator|.
name|reset
argument_list|()
expr_stmt|;
name|w
operator|.
name|show
argument_list|()
expr_stmt|;
name|QTest
operator|::
name|qWaitForWindowShown
argument_list|(
operator|&
name|w
argument_list|)
expr_stmt|;
name|QApplication
operator|::
name|processEvents
argument_list|()
expr_stmt|;
name|QTRY_VERIFY
argument_list|(
name|w
operator|.
name|paintEventReceived
argument_list|)
expr_stmt|;
block|}
end_function
begin_macro
name|QTEST_MAIN
argument_list|(
argument|tst_QWidget_window
argument_list|)
end_macro
begin_include
include|#
directive|include
file|"tst_qwidget_window.moc"
end_include
end_unit
