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
file|<QIODevice>
end_include
begin_include
include|#
directive|include
file|<QLabel>
end_include
begin_include
include|#
directive|include
file|<QMovie>
end_include
begin_class
DECL|class|tst_QMovie
class|class
name|tst_QMovie
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
public|public:
name|tst_QMovie
parameter_list|()
constructor_decl|;
specifier|virtual
name|~
name|tst_QMovie
parameter_list|()
destructor_decl|;
public|public
name|slots
public|:
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
name|exitLoopSlot
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
name|construction
parameter_list|()
function_decl|;
name|void
name|playMovie_data
parameter_list|()
function_decl|;
name|void
name|playMovie
parameter_list|()
function_decl|;
name|void
name|jumpToFrame_data
parameter_list|()
function_decl|;
name|void
name|jumpToFrame
parameter_list|()
function_decl|;
name|void
name|changeMovieFile
parameter_list|()
function_decl|;
name|void
name|infiniteLoop
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
name|tst_QMovie
operator|::
name|getSetCheck
parameter_list|()
block|{
name|QMovie
name|obj1
decl_stmt|;
comment|// QIODevice * QMovie::device()
comment|// void QMovie::setDevice(QIODevice *)
name|QFile
modifier|*
name|var1
init|=
operator|new
name|QFile
decl_stmt|;
name|obj1
operator|.
name|setDevice
argument_list|(
name|var1
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|obj1
operator|.
name|device
argument_list|()
argument_list|,
operator|(
name|QIODevice
operator|*
operator|)
name|var1
argument_list|)
expr_stmt|;
name|obj1
operator|.
name|setDevice
argument_list|(
operator|(
name|QIODevice
operator|*
operator|)
literal|0
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|obj1
operator|.
name|device
argument_list|()
argument_list|,
operator|(
name|QIODevice
operator|*
operator|)
literal|0
argument_list|)
expr_stmt|;
operator|delete
name|var1
expr_stmt|;
comment|// CacheMode QMovie::cacheMode()
comment|// void QMovie::setCacheMode(CacheMode)
name|obj1
operator|.
name|setCacheMode
argument_list|(
name|QMovie
operator|::
name|CacheMode
argument_list|(
name|QMovie
operator|::
name|CacheNone
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|QMovie
operator|::
name|CacheMode
argument_list|(
name|QMovie
operator|::
name|CacheNone
argument_list|)
argument_list|,
name|obj1
operator|.
name|cacheMode
argument_list|()
argument_list|)
expr_stmt|;
name|obj1
operator|.
name|setCacheMode
argument_list|(
name|QMovie
operator|::
name|CacheMode
argument_list|(
name|QMovie
operator|::
name|CacheAll
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|QMovie
operator|::
name|CacheMode
argument_list|(
name|QMovie
operator|::
name|CacheAll
argument_list|)
argument_list|,
name|obj1
operator|.
name|cacheMode
argument_list|()
argument_list|)
expr_stmt|;
comment|// int QMovie::speed()
comment|// void QMovie::setSpeed(int)
name|obj1
operator|.
name|setSpeed
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
name|speed
argument_list|()
argument_list|)
expr_stmt|;
name|obj1
operator|.
name|setSpeed
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
name|speed
argument_list|()
argument_list|)
expr_stmt|;
name|obj1
operator|.
name|setSpeed
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
name|speed
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_constructor
DECL|function|tst_QMovie
name|tst_QMovie
operator|::
name|tst_QMovie
parameter_list|()
block|{ }
end_constructor
begin_destructor
DECL|function|~tst_QMovie
name|tst_QMovie
operator|::
name|~
name|tst_QMovie
parameter_list|()
block|{  }
end_destructor
begin_function
DECL|function|init
name|void
name|tst_QMovie
operator|::
name|init
parameter_list|()
block|{ }
end_function
begin_function
DECL|function|cleanup
name|void
name|tst_QMovie
operator|::
name|cleanup
parameter_list|()
block|{ }
end_function
begin_function
DECL|function|exitLoopSlot
name|void
name|tst_QMovie
operator|::
name|exitLoopSlot
parameter_list|()
block|{
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
DECL|function|construction
name|void
name|tst_QMovie
operator|::
name|construction
parameter_list|()
block|{
name|QMovie
name|movie
decl_stmt|;
name|QCOMPARE
argument_list|(
name|movie
operator|.
name|device
argument_list|()
argument_list|,
operator|(
name|QIODevice
operator|*
operator|)
literal|0
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|movie
operator|.
name|fileName
argument_list|()
argument_list|,
name|QString
argument_list|()
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|movie
operator|.
name|state
argument_list|()
argument_list|,
name|QMovie
operator|::
name|NotRunning
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|playMovie_data
name|void
name|tst_QMovie
operator|::
name|playMovie_data
parameter_list|()
block|{
name|QTest
operator|::
name|addColumn
argument_list|<
name|QString
argument_list|>
argument_list|(
literal|"fileName"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|int
argument_list|>
argument_list|(
literal|"frameCount"
argument_list|)
expr_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|QTEST_HAVE_MNG
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|Q_OS_WINCE
argument_list|)
comment|// Qt/WinCE runs out of memory for this one...
name|QTest
operator|::
name|newRow
argument_list|(
literal|"home"
argument_list|)
operator|<<
name|QString
argument_list|(
literal|"animations/dutch.mng"
argument_list|)
operator|<<
literal|10
expr_stmt|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|QTEST_HAVE_GIF
name|QTest
operator|::
name|newRow
argument_list|(
literal|"comicsecard"
argument_list|)
operator|<<
name|QString
argument_list|(
literal|"animations/comicsecard.gif"
argument_list|)
operator|<<
literal|5
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"trolltech"
argument_list|)
operator|<<
name|QString
argument_list|(
literal|"animations/trolltech.gif"
argument_list|)
operator|<<
literal|34
expr_stmt|;
endif|#
directive|endif
block|}
end_function
begin_function
DECL|function|playMovie
name|void
name|tst_QMovie
operator|::
name|playMovie
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|QString
argument_list|,
name|fileName
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|int
argument_list|,
name|frameCount
argument_list|)
expr_stmt|;
name|QMovie
name|movie
argument_list|(
name|QFINDTESTDATA
argument_list|(
name|fileName
argument_list|)
argument_list|)
decl_stmt|;
name|QCOMPARE
argument_list|(
name|movie
operator|.
name|state
argument_list|()
argument_list|,
name|QMovie
operator|::
name|NotRunning
argument_list|)
expr_stmt|;
name|movie
operator|.
name|setSpeed
argument_list|(
literal|1000
argument_list|)
expr_stmt|;
name|movie
operator|.
name|start
argument_list|()
expr_stmt|;
name|QCOMPARE
argument_list|(
name|movie
operator|.
name|state
argument_list|()
argument_list|,
name|QMovie
operator|::
name|Running
argument_list|)
expr_stmt|;
name|movie
operator|.
name|setPaused
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|movie
operator|.
name|state
argument_list|()
argument_list|,
name|QMovie
operator|::
name|Paused
argument_list|)
expr_stmt|;
name|movie
operator|.
name|start
argument_list|()
expr_stmt|;
name|QCOMPARE
argument_list|(
name|movie
operator|.
name|state
argument_list|()
argument_list|,
name|QMovie
operator|::
name|Running
argument_list|)
expr_stmt|;
name|movie
operator|.
name|stop
argument_list|()
expr_stmt|;
name|QCOMPARE
argument_list|(
name|movie
operator|.
name|state
argument_list|()
argument_list|,
name|QMovie
operator|::
name|NotRunning
argument_list|)
expr_stmt|;
name|movie
operator|.
name|jumpToFrame
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|movie
operator|.
name|state
argument_list|()
argument_list|,
name|QMovie
operator|::
name|NotRunning
argument_list|)
expr_stmt|;
name|movie
operator|.
name|start
argument_list|()
expr_stmt|;
name|QCOMPARE
argument_list|(
name|movie
operator|.
name|state
argument_list|()
argument_list|,
name|QMovie
operator|::
name|Running
argument_list|)
expr_stmt|;
name|connect
argument_list|(
operator|&
name|movie
argument_list|,
name|SIGNAL
argument_list|(
name|finished
argument_list|()
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|exitLoopSlot
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|QLabel
name|label
decl_stmt|;
name|label
operator|.
name|setMovie
argument_list|(
operator|&
name|movie
argument_list|)
expr_stmt|;
name|label
operator|.
name|show
argument_list|()
expr_stmt|;
name|QTestEventLoop
operator|::
name|instance
argument_list|()
operator|.
name|enterLoop
argument_list|(
literal|20
argument_list|)
expr_stmt|;
name|QVERIFY2
argument_list|(
operator|!
name|QTestEventLoop
operator|::
name|instance
argument_list|()
operator|.
name|timeout
argument_list|()
argument_list|,
literal|"Timed out while waiting for finished() signal"
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|movie
operator|.
name|state
argument_list|()
argument_list|,
name|QMovie
operator|::
name|NotRunning
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|movie
operator|.
name|frameCount
argument_list|()
argument_list|,
name|frameCount
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|jumpToFrame_data
name|void
name|tst_QMovie
operator|::
name|jumpToFrame_data
parameter_list|()
block|{
name|playMovie_data
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|jumpToFrame
name|void
name|tst_QMovie
operator|::
name|jumpToFrame
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|QString
argument_list|,
name|fileName
argument_list|)
expr_stmt|;
name|QMovie
name|movie
argument_list|(
name|fileName
argument_list|)
decl_stmt|;
name|movie
operator|.
name|start
argument_list|()
expr_stmt|;
name|movie
operator|.
name|stop
argument_list|()
expr_stmt|;
name|QVERIFY
argument_list|(
name|movie
operator|.
name|jumpToFrame
argument_list|(
operator|-
literal|1
argument_list|)
operator|==
literal|false
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|movie
operator|.
name|currentFrameNumber
argument_list|()
operator|==
literal|0
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|changeMovieFile
name|void
name|tst_QMovie
operator|::
name|changeMovieFile
parameter_list|()
block|{
name|QMovie
name|movie
argument_list|(
literal|"animations/comicsecard.gif"
argument_list|)
decl_stmt|;
name|movie
operator|.
name|start
argument_list|()
expr_stmt|;
name|movie
operator|.
name|stop
argument_list|()
expr_stmt|;
name|movie
operator|.
name|setFileName
argument_list|(
literal|"animations/trolltech.gif"
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|movie
operator|.
name|currentFrameNumber
argument_list|()
operator|==
operator|-
literal|1
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|infiniteLoop
name|void
name|tst_QMovie
operator|::
name|infiniteLoop
parameter_list|()
block|{
name|QLabel
name|label
decl_stmt|;
name|label
operator|.
name|show
argument_list|()
expr_stmt|;
name|QMovie
modifier|*
name|movie
init|=
operator|new
name|QMovie
argument_list|(
name|QLatin1String
argument_list|(
literal|":animations/corrupt.gif"
argument_list|)
argument_list|,
name|QByteArray
argument_list|()
argument_list|,
operator|&
name|label
argument_list|)
decl_stmt|;
name|label
operator|.
name|setMovie
argument_list|(
name|movie
argument_list|)
expr_stmt|;
name|movie
operator|->
name|start
argument_list|()
expr_stmt|;
name|QTestEventLoop
operator|::
name|instance
argument_list|()
operator|.
name|enterLoop
argument_list|(
literal|1
argument_list|)
expr_stmt|;
name|QTestEventLoop
operator|::
name|instance
argument_list|()
operator|.
name|timeout
argument_list|()
expr_stmt|;
block|}
end_function
begin_macro
name|QTEST_MAIN
argument_list|(
argument|tst_QMovie
argument_list|)
end_macro
begin_include
include|#
directive|include
file|"tst_qmovie.moc"
end_include
end_unit
