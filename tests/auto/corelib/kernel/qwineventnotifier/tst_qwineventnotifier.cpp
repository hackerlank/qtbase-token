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
file|<private/qwineventnotifier_p.h>
end_include
begin_include
include|#
directive|include
file|<qtimer.h>
end_include
begin_comment
comment|//TESTED_CLASS=
end_comment
begin_comment
comment|//TESTED_FILES=
end_comment
begin_class
DECL|class|tst_QWinEventNotifier
class|class
name|tst_QWinEventNotifier
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
public|public:
name|tst_QWinEventNotifier
parameter_list|()
constructor_decl|;
name|~
name|tst_QWinEventNotifier
parameter_list|()
destructor_decl|;
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
begin_constructor
DECL|function|tst_QWinEventNotifier
name|tst_QWinEventNotifier
operator|::
name|tst_QWinEventNotifier
parameter_list|()
block|{}
end_constructor
begin_destructor
DECL|function|~tst_QWinEventNotifier
name|tst_QWinEventNotifier
operator|::
name|~
name|tst_QWinEventNotifier
parameter_list|()
block|{ }
end_destructor
begin_function
DECL|function|initTestCase
name|void
name|tst_QWinEventNotifier
operator|::
name|initTestCase
parameter_list|()
block|{ }
end_function
begin_function
DECL|function|cleanupTestCase
name|void
name|tst_QWinEventNotifier
operator|::
name|cleanupTestCase
parameter_list|()
block|{ }
end_function
begin_function
DECL|function|init
name|void
name|tst_QWinEventNotifier
operator|::
name|init
parameter_list|()
block|{ }
end_function
begin_function
DECL|function|cleanup
name|void
name|tst_QWinEventNotifier
operator|::
name|cleanup
parameter_list|()
block|{ }
end_function
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
name|TRUE
argument_list|,
name|FALSE
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
