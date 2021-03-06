begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 David Faure<david.faure@kdab.com> ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:GPL-EXCEPT$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3 as published by the Free Software ** Foundation with exceptions as appearing in the file LICENSE.GPL3-EXCEPT ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<qtest.h>
end_include
begin_include
include|#
directive|include
file|<QtCore>
end_include
begin_class
DECL|class|tst_QThreadPool
class|class
name|tst_QThreadPool
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
public|public:
name|tst_QThreadPool
parameter_list|()
constructor_decl|;
name|~
name|tst_QThreadPool
parameter_list|()
destructor_decl|;
private|private
name|slots
private|:
name|void
name|startRunnables
parameter_list|()
function_decl|;
name|void
name|activeThreadCount
parameter_list|()
function_decl|;
block|}
class|;
end_class
begin_constructor
DECL|function|tst_QThreadPool
name|tst_QThreadPool
operator|::
name|tst_QThreadPool
parameter_list|()
block|{ }
end_constructor
begin_destructor
DECL|function|~tst_QThreadPool
name|tst_QThreadPool
operator|::
name|~
name|tst_QThreadPool
parameter_list|()
block|{ }
end_destructor
begin_class
DECL|class|NoOpRunnable
class|class
name|NoOpRunnable
super|:
specifier|public
name|QRunnable
block|{
public|public:
name|void
name|run
parameter_list|()
name|Q_DECL_OVERRIDE
block|{     }
block|}
class|;
end_class
begin_function
DECL|function|startRunnables
name|void
name|tst_QThreadPool
operator|::
name|startRunnables
parameter_list|()
block|{
name|QThreadPool
name|threadPool
decl_stmt|;
name|threadPool
operator|.
name|setMaxThreadCount
argument_list|(
literal|10
argument_list|)
expr_stmt|;
name|QBENCHMARK
block|{
name|threadPool
operator|.
name|start
argument_list|(
operator|new
name|NoOpRunnable
argument_list|()
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|activeThreadCount
name|void
name|tst_QThreadPool
operator|::
name|activeThreadCount
parameter_list|()
block|{
name|QThreadPool
name|threadPool
decl_stmt|;
name|threadPool
operator|.
name|start
argument_list|(
operator|new
name|NoOpRunnable
argument_list|()
argument_list|)
expr_stmt|;
name|QBENCHMARK
block|{
name|QVERIFY
argument_list|(
name|threadPool
operator|.
name|activeThreadCount
argument_list|()
operator|<=
literal|10
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_macro
name|QTEST_MAIN
argument_list|(
argument|tst_QThreadPool
argument_list|)
end_macro
begin_include
include|#
directive|include
file|"tst_qthreadpool.moc"
end_include
end_unit
