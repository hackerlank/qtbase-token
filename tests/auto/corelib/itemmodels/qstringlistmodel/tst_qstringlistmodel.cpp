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
file|<qabstractitemmodel.h>
end_include
begin_include
include|#
directive|include
file|<qcoreapplication.h>
end_include
begin_include
include|#
directive|include
file|<qmap.h>
end_include
begin_include
include|#
directive|include
file|<qstringlistmodel.h>
end_include
begin_include
include|#
directive|include
file|<qstringlist.h>
end_include
begin_include
include|#
directive|include
file|"qmodellistener.h"
end_include
begin_include
include|#
directive|include
file|<qstringlistmodel.h>
end_include
begin_function
DECL|function|rowsAboutToBeRemovedOrInserted
name|void
name|QModelListener
operator|::
name|rowsAboutToBeRemovedOrInserted
parameter_list|(
specifier|const
name|QModelIndex
modifier|&
name|parent
parameter_list|,
name|int
name|start
parameter_list|,
name|int
name|end
parameter_list|)
block|{
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|start
operator|+
name|i
operator|<=
name|end
condition|;
name|i
operator|++
control|)
block|{
name|QModelIndex
name|mIndex
init|=
name|m_pModel
operator|->
name|index
argument_list|(
name|start
operator|+
name|i
argument_list|,
literal|0
argument_list|,
name|parent
argument_list|)
decl_stmt|;
name|QVariant
name|var
init|=
name|m_pModel
operator|->
name|data
argument_list|(
name|mIndex
argument_list|,
name|Qt
operator|::
name|DisplayRole
argument_list|)
decl_stmt|;
name|QString
name|str
init|=
name|var
operator|.
name|toString
argument_list|()
decl_stmt|;
name|QCOMPARE
argument_list|(
name|str
argument_list|,
name|m_pAboutToStringlist
operator|->
name|at
argument_list|(
name|i
argument_list|)
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|rowsRemovedOrInserted
name|void
name|QModelListener
operator|::
name|rowsRemovedOrInserted
parameter_list|(
specifier|const
name|QModelIndex
modifier|&
name|parent
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
block|{
comment|// Can the rows that *are* removed be iterated now ?
comment|// What about rowsAboutToBeInserted - what will the indices be?
comment|// will insertRow() overwrite existing, or insert (and conseq. grow the model?)
comment|// What will the item then contain? empty data?
comment|// RemoveColumn. Does that also fire the rowsRemoved-family signals?
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|m_pExpectedStringlist
operator|->
name|size
argument_list|()
condition|;
name|i
operator|++
control|)
block|{
name|QModelIndex
name|mIndex
init|=
name|m_pModel
operator|->
name|index
argument_list|(
name|i
argument_list|,
literal|0
argument_list|,
name|parent
argument_list|)
decl_stmt|;
name|QVariant
name|var
init|=
name|m_pModel
operator|->
name|data
argument_list|(
name|mIndex
argument_list|,
name|Qt
operator|::
name|DisplayRole
argument_list|)
decl_stmt|;
name|QString
name|str
init|=
name|var
operator|.
name|toString
argument_list|()
decl_stmt|;
name|QCOMPARE
argument_list|(
name|str
argument_list|,
name|m_pExpectedStringlist
operator|->
name|at
argument_list|(
name|i
argument_list|)
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_class
DECL|class|tst_QStringListModel
class|class
name|tst_QStringListModel
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
private|private
name|slots
private|:
name|void
name|rowsAboutToBeRemoved_rowsRemoved
parameter_list|()
function_decl|;
name|void
name|rowsAboutToBeRemoved_rowsRemoved_data
parameter_list|()
function_decl|;
name|void
name|rowsAboutToBeInserted_rowsInserted
parameter_list|()
function_decl|;
name|void
name|rowsAboutToBeInserted_rowsInserted_data
parameter_list|()
function_decl|;
block|}
class|;
end_class
begin_function
DECL|function|rowsAboutToBeRemoved_rowsRemoved_data
name|void
name|tst_QStringListModel
operator|::
name|rowsAboutToBeRemoved_rowsRemoved_data
parameter_list|()
block|{
name|QTest
operator|::
name|addColumn
argument_list|<
name|QStringList
argument_list|>
argument_list|(
literal|"input"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|int
argument_list|>
argument_list|(
literal|"row"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|int
argument_list|>
argument_list|(
literal|"count"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|QStringList
argument_list|>
argument_list|(
literal|"aboutto"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|QStringList
argument_list|>
argument_list|(
literal|"res"
argument_list|)
expr_stmt|;
name|QStringList
name|strings0
decl_stmt|;
name|strings0
operator|<<
literal|"One"
operator|<<
literal|"Two"
operator|<<
literal|"Three"
operator|<<
literal|"Four"
operator|<<
literal|"Five"
expr_stmt|;
name|QStringList
name|aboutto0
decl_stmt|;
name|aboutto0
operator|<<
literal|"Two"
operator|<<
literal|"Three"
expr_stmt|;
name|QStringList
name|res0
decl_stmt|;
name|res0
operator|<<
literal|"One"
operator|<<
literal|"Four"
operator|<<
literal|"Five"
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"data0"
argument_list|)
operator|<<
name|strings0
operator|<<
literal|1
operator|<<
literal|2
operator|<<
name|aboutto0
operator|<<
name|res0
expr_stmt|;
name|QStringList
name|strings1
decl_stmt|;
name|strings1
operator|<<
literal|"One"
operator|<<
literal|"Two"
operator|<<
literal|"Three"
operator|<<
literal|"Four"
operator|<<
literal|"Five"
expr_stmt|;
name|QStringList
name|aboutto1
decl_stmt|;
name|aboutto1
operator|<<
literal|"One"
operator|<<
literal|"Two"
expr_stmt|;
name|QStringList
name|res1
decl_stmt|;
name|res1
operator|<<
literal|"Three"
operator|<<
literal|"Four"
operator|<<
literal|"Five"
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"data1"
argument_list|)
operator|<<
name|strings1
operator|<<
literal|0
operator|<<
literal|2
operator|<<
name|aboutto1
operator|<<
name|res1
expr_stmt|;
name|QStringList
name|strings2
decl_stmt|;
name|strings2
operator|<<
literal|"One"
operator|<<
literal|"Two"
operator|<<
literal|"Three"
operator|<<
literal|"Four"
operator|<<
literal|"Five"
expr_stmt|;
name|QStringList
name|aboutto2
decl_stmt|;
name|aboutto2
operator|<<
literal|"Four"
operator|<<
literal|"Five"
expr_stmt|;
name|QStringList
name|res2
decl_stmt|;
name|res2
operator|<<
literal|"One"
operator|<<
literal|"Two"
operator|<<
literal|"Three"
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"data2"
argument_list|)
operator|<<
name|strings2
operator|<<
literal|3
operator|<<
literal|2
operator|<<
name|aboutto2
operator|<<
name|res2
expr_stmt|;
name|QStringList
name|strings3
decl_stmt|;
name|strings3
operator|<<
literal|"One"
operator|<<
literal|"Two"
operator|<<
literal|"Three"
operator|<<
literal|"Four"
operator|<<
literal|"Five"
expr_stmt|;
name|QStringList
name|aboutto3
decl_stmt|;
name|aboutto3
operator|<<
literal|"One"
operator|<<
literal|"Two"
operator|<<
literal|"Three"
operator|<<
literal|"Four"
operator|<<
literal|"Five"
expr_stmt|;
name|QStringList
name|res3
decl_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"data3"
argument_list|)
operator|<<
name|strings3
operator|<<
literal|0
operator|<<
literal|5
operator|<<
name|aboutto3
operator|<<
name|res3
expr_stmt|;
comment|/* Not sure if this is a valid test */
name|QStringList
name|strings4
decl_stmt|;
name|strings4
operator|<<
literal|"One"
operator|<<
literal|"Two"
operator|<<
literal|"Three"
operator|<<
literal|"Four"
operator|<<
literal|"Five"
expr_stmt|;
name|QStringList
name|aboutto4
decl_stmt|;
name|aboutto4
operator|<<
literal|"Five"
operator|<<
literal|""
expr_stmt|;
name|QStringList
name|res4
decl_stmt|;
name|res4
operator|<<
literal|"One"
operator|<<
literal|"Two"
operator|<<
literal|"Three"
operator|<<
literal|"Four"
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"data4"
argument_list|)
operator|<<
name|strings4
operator|<<
literal|4
operator|<<
literal|2
operator|<<
name|aboutto4
operator|<<
name|res4
expr_stmt|;
comment|/*      * Keep this, template to add more data     QStringList strings2;   strings2<< "One"<< "Two"<< "Three"<< "Four"<< "Five";     QStringList aboutto2;   aboutto2<< "One"<< "Two"<< "Three"<< "Four"<< "Five";     QStringList res2;       res2<< "One"<< "Two"<< "Three"<< "Four"<< "Five";     QTest::newRow( "data2" )<< strings2<< 0<< 5<< aboutto2<< res2; */
block|}
end_function
begin_function
DECL|function|rowsAboutToBeRemoved_rowsRemoved
name|void
name|tst_QStringListModel
operator|::
name|rowsAboutToBeRemoved_rowsRemoved
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|QStringList
argument_list|,
name|input
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|int
argument_list|,
name|row
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|int
argument_list|,
name|count
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|QStringList
argument_list|,
name|aboutto
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|QStringList
argument_list|,
name|res
argument_list|)
expr_stmt|;
name|QStringListModel
modifier|*
name|model
init|=
operator|new
name|QStringListModel
argument_list|(
name|input
argument_list|)
decl_stmt|;
name|QModelListener
modifier|*
name|pListener
init|=
operator|new
name|QModelListener
argument_list|(
operator|&
name|aboutto
argument_list|,
operator|&
name|res
argument_list|,
name|model
argument_list|)
decl_stmt|;
name|pListener
operator|->
name|connect
argument_list|(
name|model
argument_list|,
name|SIGNAL
argument_list|(
name|rowsAboutToBeRemoved
argument_list|(
name|QModelIndex
argument_list|,
name|int
argument_list|,
name|int
argument_list|)
argument_list|)
argument_list|,
name|pListener
argument_list|,
name|SLOT
argument_list|(
name|rowsAboutToBeRemovedOrInserted
argument_list|(
name|QModelIndex
argument_list|,
name|int
argument_list|,
name|int
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|pListener
operator|->
name|connect
argument_list|(
name|model
argument_list|,
name|SIGNAL
argument_list|(
name|rowsRemoved
argument_list|(
name|QModelIndex
argument_list|,
name|int
argument_list|,
name|int
argument_list|)
argument_list|)
argument_list|,
name|pListener
argument_list|,
name|SLOT
argument_list|(
name|rowsRemovedOrInserted
argument_list|(
name|QModelIndex
argument_list|,
name|int
argument_list|,
name|int
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|model
operator|->
name|removeRows
argument_list|(
name|row
argument_list|,
name|count
argument_list|)
expr_stmt|;
comment|// At this point, control goes to our connected slots inn this order:
comment|// 1. rowsAboutToBeRemovedOrInserted
comment|// 2. rowsRemovedOrInserted
comment|// Control returns here
operator|delete
name|pListener
expr_stmt|;
operator|delete
name|model
expr_stmt|;
block|}
end_function
begin_function
DECL|function|rowsAboutToBeInserted_rowsInserted_data
name|void
name|tst_QStringListModel
operator|::
name|rowsAboutToBeInserted_rowsInserted_data
parameter_list|()
block|{
name|QTest
operator|::
name|addColumn
argument_list|<
name|QStringList
argument_list|>
argument_list|(
literal|"input"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|int
argument_list|>
argument_list|(
literal|"row"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|int
argument_list|>
argument_list|(
literal|"count"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|QStringList
argument_list|>
argument_list|(
literal|"aboutto"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|QStringList
argument_list|>
argument_list|(
literal|"res"
argument_list|)
expr_stmt|;
name|QStringList
name|strings0
decl_stmt|;
name|strings0
operator|<<
literal|"One"
operator|<<
literal|"Two"
operator|<<
literal|"Three"
operator|<<
literal|"Four"
operator|<<
literal|"Five"
expr_stmt|;
name|QStringList
name|aboutto0
decl_stmt|;
name|aboutto0
operator|<<
literal|"Two"
operator|<<
literal|"Three"
expr_stmt|;
name|QStringList
name|res0
decl_stmt|;
name|res0
operator|<<
literal|"One"
operator|<<
literal|""
operator|<<
literal|""
operator|<<
literal|"Two"
operator|<<
literal|"Three"
operator|<<
literal|"Four"
operator|<<
literal|"Five"
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"data0"
argument_list|)
operator|<<
name|strings0
operator|<<
literal|1
operator|<<
literal|2
operator|<<
name|aboutto0
operator|<<
name|res0
expr_stmt|;
name|QStringList
name|strings1
decl_stmt|;
name|strings1
operator|<<
literal|"One"
operator|<<
literal|"Two"
operator|<<
literal|"Three"
operator|<<
literal|"Four"
operator|<<
literal|"Five"
expr_stmt|;
name|QStringList
name|aboutto1
decl_stmt|;
name|aboutto1
operator|<<
literal|"One"
operator|<<
literal|"Two"
expr_stmt|;
name|QStringList
name|res1
decl_stmt|;
name|res1
operator|<<
literal|""
operator|<<
literal|""
operator|<<
literal|"One"
operator|<<
literal|"Two"
operator|<<
literal|"Three"
operator|<<
literal|"Four"
operator|<<
literal|"Five"
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"data1"
argument_list|)
operator|<<
name|strings1
operator|<<
literal|0
operator|<<
literal|2
operator|<<
name|aboutto1
operator|<<
name|res1
expr_stmt|;
name|QStringList
name|strings2
decl_stmt|;
name|strings2
operator|<<
literal|"One"
operator|<<
literal|"Two"
operator|<<
literal|"Three"
operator|<<
literal|"Four"
operator|<<
literal|"Five"
expr_stmt|;
name|QStringList
name|aboutto2
decl_stmt|;
name|aboutto2
operator|<<
literal|"Four"
operator|<<
literal|"Five"
expr_stmt|;
name|QStringList
name|res2
decl_stmt|;
name|res2
operator|<<
literal|"One"
operator|<<
literal|"Two"
operator|<<
literal|"Three"
operator|<<
literal|""
operator|<<
literal|""
operator|<<
literal|"Four"
operator|<<
literal|"Five"
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"data2"
argument_list|)
operator|<<
name|strings2
operator|<<
literal|3
operator|<<
literal|2
operator|<<
name|aboutto2
operator|<<
name|res2
expr_stmt|;
name|QStringList
name|strings3
decl_stmt|;
name|strings3
operator|<<
literal|"One"
operator|<<
literal|"Two"
operator|<<
literal|"Three"
operator|<<
literal|"Four"
operator|<<
literal|"Five"
expr_stmt|;
name|QStringList
name|aboutto3
decl_stmt|;
name|aboutto3
operator|<<
literal|"One"
operator|<<
literal|"Two"
operator|<<
literal|"Three"
operator|<<
literal|"Four"
operator|<<
literal|"Five"
expr_stmt|;
name|QStringList
name|res3
decl_stmt|;
name|res3
operator|<<
literal|""
operator|<<
literal|""
operator|<<
literal|""
operator|<<
literal|""
operator|<<
literal|""
operator|<<
literal|"One"
operator|<<
literal|"Two"
operator|<<
literal|"Three"
operator|<<
literal|"Four"
operator|<<
literal|"Five"
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"data3"
argument_list|)
operator|<<
name|strings3
operator|<<
literal|0
operator|<<
literal|5
operator|<<
name|aboutto3
operator|<<
name|res3
expr_stmt|;
comment|/*      * Keep this, template to add more data     QStringList strings2;   strings2<< "One"<< "Two"<< "Three"<< "Four"<< "Five";     QStringList aboutto2;   aboutto2<< "One"<< "Two"<< "Three"<< "Four"<< "Five";     QStringList res2;       res2<< "One"<< "Two"<< "Three"<< "Four"<< "Five";     QTest::newRow( "data2" )<< strings2<< 0<< 5<< aboutto2<< res2; */
block|}
end_function
begin_function
DECL|function|rowsAboutToBeInserted_rowsInserted
name|void
name|tst_QStringListModel
operator|::
name|rowsAboutToBeInserted_rowsInserted
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|QStringList
argument_list|,
name|input
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|int
argument_list|,
name|row
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|int
argument_list|,
name|count
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|QStringList
argument_list|,
name|aboutto
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|QStringList
argument_list|,
name|res
argument_list|)
expr_stmt|;
name|QStringListModel
modifier|*
name|model
init|=
operator|new
name|QStringListModel
argument_list|(
name|input
argument_list|)
decl_stmt|;
name|QModelListener
modifier|*
name|pListener
init|=
operator|new
name|QModelListener
argument_list|(
operator|&
name|aboutto
argument_list|,
operator|&
name|res
argument_list|,
name|model
argument_list|)
decl_stmt|;
name|connect
argument_list|(
name|model
argument_list|,
name|SIGNAL
argument_list|(
name|rowsAboutToBeInserted
argument_list|(
name|QModelIndex
argument_list|,
name|int
argument_list|,
name|int
argument_list|)
argument_list|)
argument_list|,
name|pListener
argument_list|,
name|SLOT
argument_list|(
name|rowsAboutToBeRemovedOrInserted
argument_list|(
name|QModelIndex
argument_list|,
name|int
argument_list|,
name|int
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|model
argument_list|,
name|SIGNAL
argument_list|(
name|rowsInserted
argument_list|(
name|QModelIndex
argument_list|,
name|int
argument_list|,
name|int
argument_list|)
argument_list|)
argument_list|,
name|pListener
argument_list|,
name|SLOT
argument_list|(
name|rowsRemovedOrInserted
argument_list|(
name|QModelIndex
argument_list|,
name|int
argument_list|,
name|int
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|model
operator|->
name|insertRows
argument_list|(
name|row
argument_list|,
name|count
argument_list|)
expr_stmt|;
comment|// At this point, control goes to our connected slots inn this order:
comment|// 1. rowsAboutToBeRemovedOrInserted
comment|// 2. rowsRemovedOrInserted
comment|// Control returns here
operator|delete
name|pListener
expr_stmt|;
operator|delete
name|model
expr_stmt|;
block|}
end_function
begin_macro
name|QTEST_MAIN
argument_list|(
argument|tst_QStringListModel
argument_list|)
end_macro
begin_include
include|#
directive|include
file|"tst_qstringlistmodel.moc"
end_include
end_unit
