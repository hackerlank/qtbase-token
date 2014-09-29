begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2014 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia. For licensing terms and ** conditions see http://qt.digia.com/licensing. For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights. These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtTest/QtTest>
end_include
begin_include
include|#
directive|include
file|<qwineventnotifier.h>
end_include
begin_include
include|#
directive|include
file|<qtimer.h>
end_include
begin_include
include|#
directive|include
file|<qt_windows.h>
end_include
begin_class
DECL|class|tst_QWinEventNotifier
class|class
name|tst_QWinEventNotifier
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
protected|protected
name|slots
protected|:
name|void
name|simple_activated
parameter_list|()
function_decl|;
name|void
name|simple_timerSet
parameter_list|()
function_decl|;
private|private
name|slots
private|:
name|void
name|simple
parameter_list|()
function_decl|;
private|private:
DECL|member|simpleHEvent
name|HANDLE
name|simpleHEvent
decl_stmt|;
DECL|member|simpleActivated
name|bool
name|simpleActivated
decl_stmt|;
block|}
class|;
end_class
begin_function
DECL|function|simple_activated
name|void
name|tst_QWinEventNotifier
operator|::
name|simple_activated
parameter_list|()
block|{
name|simpleActivated
operator|=
literal|true
expr_stmt|;
name|ResetEvent
argument_list|(
operator|(
name|HANDLE
operator|)
name|simpleHEvent
argument_list|)
expr_stmt|;
name|QTestEventLoop
operator|::
name|instance
argument_list|()
operator|.
name|exitLoop
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|simple_timerSet
name|void
name|tst_QWinEventNotifier
operator|::
name|simple_timerSet
parameter_list|()
block|{
name|SetEvent
argument_list|(
operator|(
name|HANDLE
operator|)
name|simpleHEvent
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|simple
name|void
name|tst_QWinEventNotifier
operator|::
name|simple
parameter_list|()
block|{
name|simpleHEvent
operator|=
name|CreateEvent
argument_list|(
literal|0
argument_list|,
literal|true
argument_list|,
literal|false
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|simpleHEvent
argument_list|)
expr_stmt|;
name|QWinEventNotifier
name|n
argument_list|(
name|simpleHEvent
argument_list|)
decl_stmt|;
name|QObject
operator|::
name|connect
argument_list|(
operator|&
name|n
argument_list|,
name|SIGNAL
argument_list|(
name|activated
argument_list|(
name|HANDLE
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|simple_activated
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|simpleActivated
operator|=
literal|false
expr_stmt|;
name|SetEvent
argument_list|(
operator|(
name|HANDLE
operator|)
name|simpleHEvent
argument_list|)
expr_stmt|;
name|QTestEventLoop
operator|::
name|instance
argument_list|()
operator|.
name|enterLoop
argument_list|(
literal|30
argument_list|)
expr_stmt|;
if|if
condition|(
name|QTestEventLoop
operator|::
name|instance
argument_list|()
operator|.
name|timeout
argument_list|()
condition|)
name|QFAIL
argument_list|(
literal|"Timed out"
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|simpleActivated
argument_list|)
expr_stmt|;
name|simpleActivated
operator|=
literal|false
expr_stmt|;
name|QTimer
operator|::
name|singleShot
argument_list|(
literal|3000
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|simple_timerSet
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|QTestEventLoop
operator|::
name|instance
argument_list|()
operator|.
name|enterLoop
argument_list|(
literal|30
argument_list|)
expr_stmt|;
if|if
condition|(
name|QTestEventLoop
operator|::
name|instance
argument_list|()
operator|.
name|timeout
argument_list|()
condition|)
name|QFAIL
argument_list|(
literal|"Timed out"
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|simpleActivated
argument_list|)
expr_stmt|;
block|}
end_function
begin_macro
name|QTEST_MAIN
argument_list|(
argument|tst_QWinEventNotifier
argument_list|)
end_macro
begin_include
include|#
directive|include
file|"tst_qwineventnotifier.moc"
end_include
end_unit
