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
file|<QtGui>
end_include
begin_class
DECL|class|tst_QSound
class|class
name|tst_QSound
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
public|public:
DECL|function|tst_QSound
name|tst_QSound
parameter_list|(
name|QObject
modifier|*
name|parent
init|=
literal|0
parameter_list|)
member_init_list|:
name|QObject
argument_list|(
name|parent
argument_list|)
block|{}
private|private
name|slots
private|:
name|void
name|checkFinished
parameter_list|()
function_decl|;
comment|// Manual tests
name|void
name|staticPlay
parameter_list|()
function_decl|;
block|}
class|;
end_class
begin_function
DECL|function|checkFinished
name|void
name|tst_QSound
operator|::
name|checkFinished
parameter_list|()
block|{
if|#
directive|if
name|defined
argument_list|(
name|Q_WS_QPA
argument_list|)
name|QSKIP
argument_list|(
literal|"QSound is not implemented on Lighthouse"
argument_list|,
name|SkipAll
argument_list|)
expr_stmt|;
else|#
directive|else
name|QSound
name|sound
argument_list|(
name|SRCDIR
literal|"4.wav"
argument_list|)
decl_stmt|;
name|sound
operator|.
name|setLoops
argument_list|(
literal|3
argument_list|)
expr_stmt|;
name|sound
operator|.
name|play
argument_list|()
expr_stmt|;
name|QTest
operator|::
name|qWait
argument_list|(
literal|5000
argument_list|)
expr_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|Q_WS_QWS
argument_list|)
name|QEXPECT_FAIL
argument_list|(
literal|""
argument_list|,
literal|"QSound buggy on embedded (task QTBUG-157)"
argument_list|,
name|Abort
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|QVERIFY
argument_list|(
name|sound
operator|.
name|isFinished
argument_list|()
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
end_function
begin_function
DECL|function|staticPlay
name|void
name|tst_QSound
operator|::
name|staticPlay
parameter_list|()
block|{
name|QSKIP
argument_list|(
literal|"Test disabled -- only for manual purposes"
argument_list|,
name|SkipAll
argument_list|)
expr_stmt|;
if|#
directive|if
operator|!
name|defined
argument_list|(
name|Q_WS_QPA
argument_list|)
comment|// Check that you hear sound with static play also.
name|QSound
operator|::
name|play
argument_list|(
name|SRCDIR
literal|"4.wav"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|qWait
argument_list|(
literal|2000
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
end_function
begin_expr_stmt
DECL|variable|tst_QSound
name|QTEST_MAIN
argument_list|(
name|tst_QSound
argument_list|)
expr_stmt|;
end_expr_stmt
begin_include
include|#
directive|include
file|"tst_qsound.moc"
end_include
end_unit
