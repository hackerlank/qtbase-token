begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** No Commercial Usage ** This file contains pre-release code and may not be distributed. ** You may use this file in accordance with the terms and conditions ** contained in the Technology Preview License Agreement accompanying ** this package. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights.  These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** If you have questions regarding the use of this file, please contact ** Nokia at qt-info@nokia.com. ** ** ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtGui/QtGui>
end_include
begin_include
include|#
directive|include
file|<QtTest/QtTest>
end_include
begin_class
DECL|class|tst_QDataWidgetMapper
class|class
name|tst_QDataWidgetMapper
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
private|private
name|slots
private|:
name|void
name|setModel
parameter_list|()
function_decl|;
name|void
name|navigate
parameter_list|()
function_decl|;
name|void
name|addMapping
parameter_list|()
function_decl|;
name|void
name|currentIndexChanged
parameter_list|()
function_decl|;
name|void
name|changingValues
parameter_list|()
function_decl|;
name|void
name|setData
parameter_list|()
function_decl|;
name|void
name|mappedWidgetAt
parameter_list|()
function_decl|;
name|void
name|comboBox
parameter_list|()
function_decl|;
block|}
class|;
end_class
begin_function
DECL|function|testModel
specifier|static
name|QStandardItemModel
modifier|*
name|testModel
parameter_list|(
name|QObject
modifier|*
name|parent
init|=
literal|0
parameter_list|)
block|{
name|QStandardItemModel
modifier|*
name|model
init|=
operator|new
name|QStandardItemModel
argument_list|(
literal|10
argument_list|,
literal|10
argument_list|,
name|parent
argument_list|)
decl_stmt|;
for|for
control|(
name|int
name|row
init|=
literal|0
init|;
name|row
operator|<
literal|10
condition|;
operator|++
name|row
control|)
block|{
for|for
control|(
name|int
name|col
init|=
literal|0
init|;
name|col
operator|<
literal|10
condition|;
operator|++
name|col
control|)
name|model
operator|->
name|setData
argument_list|(
name|model
operator|->
name|index
argument_list|(
name|row
argument_list|,
name|col
argument_list|)
argument_list|,
name|QString
argument_list|(
literal|"item %1 %2"
argument_list|)
operator|.
name|arg
argument_list|(
name|row
argument_list|)
operator|.
name|arg
argument_list|(
name|col
argument_list|)
argument_list|)
expr_stmt|;
block|}
return|return
name|model
return|;
block|}
end_function
begin_function
DECL|function|setModel
name|void
name|tst_QDataWidgetMapper
operator|::
name|setModel
parameter_list|()
block|{
name|QDataWidgetMapper
name|mapper
decl_stmt|;
name|QCOMPARE
argument_list|(
name|mapper
operator|.
name|model
argument_list|()
argument_list|,
operator|(
name|QAbstractItemModel
operator|*
operator|)
literal|0
argument_list|)
expr_stmt|;
block|{
comment|// let the model go out of scope firstma
name|QStandardItemModel
name|model
decl_stmt|;
name|mapper
operator|.
name|setModel
argument_list|(
operator|&
name|model
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|mapper
operator|.
name|model
argument_list|()
argument_list|,
cast|static_cast
argument_list|<
name|QAbstractItemModel
operator|*
argument_list|>
argument_list|(
operator|&
name|model
argument_list|)
argument_list|)
expr_stmt|;
block|}
name|QCOMPARE
argument_list|(
name|mapper
operator|.
name|model
argument_list|()
argument_list|,
operator|(
name|QAbstractItemModel
operator|*
operator|)
literal|0
argument_list|)
expr_stmt|;
block|{
comment|// let the mapper go out of scope first
name|QStandardItemModel
name|model2
decl_stmt|;
name|QDataWidgetMapper
name|mapper2
decl_stmt|;
name|mapper2
operator|.
name|setModel
argument_list|(
operator|&
name|model2
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|navigate
name|void
name|tst_QDataWidgetMapper
operator|::
name|navigate
parameter_list|()
block|{
name|QDataWidgetMapper
name|mapper
decl_stmt|;
name|QAbstractItemModel
modifier|*
name|model
init|=
name|testModel
argument_list|(
operator|&
name|mapper
argument_list|)
decl_stmt|;
name|mapper
operator|.
name|setModel
argument_list|(
name|model
argument_list|)
expr_stmt|;
name|QLineEdit
name|edit1
decl_stmt|;
name|QLineEdit
name|edit2
decl_stmt|;
name|QLineEdit
name|edit3
decl_stmt|;
name|mapper
operator|.
name|addMapping
argument_list|(
operator|&
name|edit1
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|mapper
operator|.
name|toFirst
argument_list|()
expr_stmt|;
name|mapper
operator|.
name|addMapping
argument_list|(
operator|&
name|edit2
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|mapper
operator|.
name|addMapping
argument_list|(
operator|&
name|edit3
argument_list|,
literal|2
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|edit1
operator|.
name|text
argument_list|()
argument_list|,
name|QString
argument_list|(
literal|"item 0 0"
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|edit2
operator|.
name|text
argument_list|()
operator|.
name|isEmpty
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|edit3
operator|.
name|text
argument_list|()
operator|.
name|isEmpty
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|mapper
operator|.
name|submit
argument_list|()
argument_list|)
expr_stmt|;
name|edit2
operator|.
name|setText
argument_list|(
name|QString
argument_list|(
literal|"item 0 1"
argument_list|)
argument_list|)
expr_stmt|;
name|edit3
operator|.
name|setText
argument_list|(
name|QString
argument_list|(
literal|"item 0 2"
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|mapper
operator|.
name|submit
argument_list|()
argument_list|)
expr_stmt|;
name|mapper
operator|.
name|toFirst
argument_list|()
expr_stmt|;
comment|//this will repopulate
name|QCOMPARE
argument_list|(
name|edit1
operator|.
name|text
argument_list|()
argument_list|,
name|QString
argument_list|(
literal|"item 0 0"
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|edit2
operator|.
name|text
argument_list|()
argument_list|,
name|QString
argument_list|(
literal|"item 0 1"
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|edit3
operator|.
name|text
argument_list|()
argument_list|,
name|QString
argument_list|(
literal|"item 0 2"
argument_list|)
argument_list|)
expr_stmt|;
name|mapper
operator|.
name|toFirst
argument_list|()
expr_stmt|;
name|QCOMPARE
argument_list|(
name|edit1
operator|.
name|text
argument_list|()
argument_list|,
name|QString
argument_list|(
literal|"item 0 0"
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|edit2
operator|.
name|text
argument_list|()
argument_list|,
name|QString
argument_list|(
literal|"item 0 1"
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|edit3
operator|.
name|text
argument_list|()
argument_list|,
name|QString
argument_list|(
literal|"item 0 2"
argument_list|)
argument_list|)
expr_stmt|;
name|mapper
operator|.
name|toPrevious
argument_list|()
expr_stmt|;
comment|// should do nothing
name|QCOMPARE
argument_list|(
name|edit1
operator|.
name|text
argument_list|()
argument_list|,
name|QString
argument_list|(
literal|"item 0 0"
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|edit2
operator|.
name|text
argument_list|()
argument_list|,
name|QString
argument_list|(
literal|"item 0 1"
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|edit3
operator|.
name|text
argument_list|()
argument_list|,
name|QString
argument_list|(
literal|"item 0 2"
argument_list|)
argument_list|)
expr_stmt|;
name|mapper
operator|.
name|toNext
argument_list|()
expr_stmt|;
name|QCOMPARE
argument_list|(
name|edit1
operator|.
name|text
argument_list|()
argument_list|,
name|QString
argument_list|(
literal|"item 1 0"
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|edit2
operator|.
name|text
argument_list|()
argument_list|,
name|QString
argument_list|(
literal|"item 1 1"
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|edit3
operator|.
name|text
argument_list|()
argument_list|,
name|QString
argument_list|(
literal|"item 1 2"
argument_list|)
argument_list|)
expr_stmt|;
name|mapper
operator|.
name|toLast
argument_list|()
expr_stmt|;
name|QCOMPARE
argument_list|(
name|edit1
operator|.
name|text
argument_list|()
argument_list|,
name|QString
argument_list|(
literal|"item 9 0"
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|edit2
operator|.
name|text
argument_list|()
argument_list|,
name|QString
argument_list|(
literal|"item 9 1"
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|edit3
operator|.
name|text
argument_list|()
argument_list|,
name|QString
argument_list|(
literal|"item 9 2"
argument_list|)
argument_list|)
expr_stmt|;
name|mapper
operator|.
name|toNext
argument_list|()
expr_stmt|;
comment|// should do nothing
name|QCOMPARE
argument_list|(
name|edit1
operator|.
name|text
argument_list|()
argument_list|,
name|QString
argument_list|(
literal|"item 9 0"
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|edit2
operator|.
name|text
argument_list|()
argument_list|,
name|QString
argument_list|(
literal|"item 9 1"
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|edit3
operator|.
name|text
argument_list|()
argument_list|,
name|QString
argument_list|(
literal|"item 9 2"
argument_list|)
argument_list|)
expr_stmt|;
name|mapper
operator|.
name|setCurrentIndex
argument_list|(
literal|4
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|edit1
operator|.
name|text
argument_list|()
argument_list|,
name|QString
argument_list|(
literal|"item 4 0"
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|edit2
operator|.
name|text
argument_list|()
argument_list|,
name|QString
argument_list|(
literal|"item 4 1"
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|edit3
operator|.
name|text
argument_list|()
argument_list|,
name|QString
argument_list|(
literal|"item 4 2"
argument_list|)
argument_list|)
expr_stmt|;
name|mapper
operator|.
name|setCurrentIndex
argument_list|(
operator|-
literal|1
argument_list|)
expr_stmt|;
comment|// should do nothing
name|QCOMPARE
argument_list|(
name|edit1
operator|.
name|text
argument_list|()
argument_list|,
name|QString
argument_list|(
literal|"item 4 0"
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|edit2
operator|.
name|text
argument_list|()
argument_list|,
name|QString
argument_list|(
literal|"item 4 1"
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|edit3
operator|.
name|text
argument_list|()
argument_list|,
name|QString
argument_list|(
literal|"item 4 2"
argument_list|)
argument_list|)
expr_stmt|;
name|mapper
operator|.
name|setCurrentIndex
argument_list|(
literal|10
argument_list|)
expr_stmt|;
comment|// should do nothing
name|QCOMPARE
argument_list|(
name|edit1
operator|.
name|text
argument_list|()
argument_list|,
name|QString
argument_list|(
literal|"item 4 0"
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|edit2
operator|.
name|text
argument_list|()
argument_list|,
name|QString
argument_list|(
literal|"item 4 1"
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|edit3
operator|.
name|text
argument_list|()
argument_list|,
name|QString
argument_list|(
literal|"item 4 2"
argument_list|)
argument_list|)
expr_stmt|;
name|mapper
operator|.
name|setCurrentModelIndex
argument_list|(
name|QModelIndex
argument_list|()
argument_list|)
expr_stmt|;
comment|// should do nothing
name|QCOMPARE
argument_list|(
name|edit1
operator|.
name|text
argument_list|()
argument_list|,
name|QString
argument_list|(
literal|"item 4 0"
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|edit2
operator|.
name|text
argument_list|()
argument_list|,
name|QString
argument_list|(
literal|"item 4 1"
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|edit3
operator|.
name|text
argument_list|()
argument_list|,
name|QString
argument_list|(
literal|"item 4 2"
argument_list|)
argument_list|)
expr_stmt|;
name|mapper
operator|.
name|setCurrentModelIndex
argument_list|(
name|model
operator|->
name|index
argument_list|(
literal|6
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|edit1
operator|.
name|text
argument_list|()
argument_list|,
name|QString
argument_list|(
literal|"item 6 0"
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|edit2
operator|.
name|text
argument_list|()
argument_list|,
name|QString
argument_list|(
literal|"item 6 1"
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|edit3
operator|.
name|text
argument_list|()
argument_list|,
name|QString
argument_list|(
literal|"item 6 2"
argument_list|)
argument_list|)
expr_stmt|;
comment|/* now try vertical navigation */
name|mapper
operator|.
name|setOrientation
argument_list|(
name|Qt
operator|::
name|Vertical
argument_list|)
expr_stmt|;
name|mapper
operator|.
name|addMapping
argument_list|(
operator|&
name|edit1
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|mapper
operator|.
name|addMapping
argument_list|(
operator|&
name|edit2
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|mapper
operator|.
name|addMapping
argument_list|(
operator|&
name|edit3
argument_list|,
literal|2
argument_list|)
expr_stmt|;
name|mapper
operator|.
name|toFirst
argument_list|()
expr_stmt|;
name|QCOMPARE
argument_list|(
name|edit1
operator|.
name|text
argument_list|()
argument_list|,
name|QString
argument_list|(
literal|"item 0 0"
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|edit2
operator|.
name|text
argument_list|()
argument_list|,
name|QString
argument_list|(
literal|"item 1 0"
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|edit3
operator|.
name|text
argument_list|()
argument_list|,
name|QString
argument_list|(
literal|"item 2 0"
argument_list|)
argument_list|)
expr_stmt|;
name|mapper
operator|.
name|toPrevious
argument_list|()
expr_stmt|;
comment|// should do nothing
name|QCOMPARE
argument_list|(
name|edit1
operator|.
name|text
argument_list|()
argument_list|,
name|QString
argument_list|(
literal|"item 0 0"
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|edit2
operator|.
name|text
argument_list|()
argument_list|,
name|QString
argument_list|(
literal|"item 1 0"
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|edit3
operator|.
name|text
argument_list|()
argument_list|,
name|QString
argument_list|(
literal|"item 2 0"
argument_list|)
argument_list|)
expr_stmt|;
name|mapper
operator|.
name|toNext
argument_list|()
expr_stmt|;
name|QCOMPARE
argument_list|(
name|edit1
operator|.
name|text
argument_list|()
argument_list|,
name|QString
argument_list|(
literal|"item 0 1"
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|edit2
operator|.
name|text
argument_list|()
argument_list|,
name|QString
argument_list|(
literal|"item 1 1"
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|edit3
operator|.
name|text
argument_list|()
argument_list|,
name|QString
argument_list|(
literal|"item 2 1"
argument_list|)
argument_list|)
expr_stmt|;
name|mapper
operator|.
name|toLast
argument_list|()
expr_stmt|;
name|QCOMPARE
argument_list|(
name|edit1
operator|.
name|text
argument_list|()
argument_list|,
name|QString
argument_list|(
literal|"item 0 9"
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|edit2
operator|.
name|text
argument_list|()
argument_list|,
name|QString
argument_list|(
literal|"item 1 9"
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|edit3
operator|.
name|text
argument_list|()
argument_list|,
name|QString
argument_list|(
literal|"item 2 9"
argument_list|)
argument_list|)
expr_stmt|;
name|mapper
operator|.
name|toNext
argument_list|()
expr_stmt|;
comment|// should do nothing
name|QCOMPARE
argument_list|(
name|edit1
operator|.
name|text
argument_list|()
argument_list|,
name|QString
argument_list|(
literal|"item 0 9"
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|edit2
operator|.
name|text
argument_list|()
argument_list|,
name|QString
argument_list|(
literal|"item 1 9"
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|edit3
operator|.
name|text
argument_list|()
argument_list|,
name|QString
argument_list|(
literal|"item 2 9"
argument_list|)
argument_list|)
expr_stmt|;
name|mapper
operator|.
name|setCurrentIndex
argument_list|(
literal|4
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|edit1
operator|.
name|text
argument_list|()
argument_list|,
name|QString
argument_list|(
literal|"item 0 4"
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|edit2
operator|.
name|text
argument_list|()
argument_list|,
name|QString
argument_list|(
literal|"item 1 4"
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|edit3
operator|.
name|text
argument_list|()
argument_list|,
name|QString
argument_list|(
literal|"item 2 4"
argument_list|)
argument_list|)
expr_stmt|;
name|mapper
operator|.
name|setCurrentIndex
argument_list|(
operator|-
literal|1
argument_list|)
expr_stmt|;
comment|// should do nothing
name|QCOMPARE
argument_list|(
name|edit1
operator|.
name|text
argument_list|()
argument_list|,
name|QString
argument_list|(
literal|"item 0 4"
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|edit2
operator|.
name|text
argument_list|()
argument_list|,
name|QString
argument_list|(
literal|"item 1 4"
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|edit3
operator|.
name|text
argument_list|()
argument_list|,
name|QString
argument_list|(
literal|"item 2 4"
argument_list|)
argument_list|)
expr_stmt|;
name|mapper
operator|.
name|setCurrentIndex
argument_list|(
literal|10
argument_list|)
expr_stmt|;
comment|// should do nothing
name|QCOMPARE
argument_list|(
name|edit1
operator|.
name|text
argument_list|()
argument_list|,
name|QString
argument_list|(
literal|"item 0 4"
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|edit2
operator|.
name|text
argument_list|()
argument_list|,
name|QString
argument_list|(
literal|"item 1 4"
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|edit3
operator|.
name|text
argument_list|()
argument_list|,
name|QString
argument_list|(
literal|"item 2 4"
argument_list|)
argument_list|)
expr_stmt|;
name|mapper
operator|.
name|setCurrentModelIndex
argument_list|(
name|QModelIndex
argument_list|()
argument_list|)
expr_stmt|;
comment|// should do nothing
name|QCOMPARE
argument_list|(
name|edit1
operator|.
name|text
argument_list|()
argument_list|,
name|QString
argument_list|(
literal|"item 0 4"
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|edit2
operator|.
name|text
argument_list|()
argument_list|,
name|QString
argument_list|(
literal|"item 1 4"
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|edit3
operator|.
name|text
argument_list|()
argument_list|,
name|QString
argument_list|(
literal|"item 2 4"
argument_list|)
argument_list|)
expr_stmt|;
name|mapper
operator|.
name|setCurrentModelIndex
argument_list|(
name|model
operator|->
name|index
argument_list|(
literal|0
argument_list|,
literal|6
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|edit1
operator|.
name|text
argument_list|()
argument_list|,
name|QString
argument_list|(
literal|"item 0 6"
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|edit2
operator|.
name|text
argument_list|()
argument_list|,
name|QString
argument_list|(
literal|"item 1 6"
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|edit3
operator|.
name|text
argument_list|()
argument_list|,
name|QString
argument_list|(
literal|"item 2 6"
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|addMapping
name|void
name|tst_QDataWidgetMapper
operator|::
name|addMapping
parameter_list|()
block|{
name|QDataWidgetMapper
name|mapper
decl_stmt|;
name|QAbstractItemModel
modifier|*
name|model
init|=
name|testModel
argument_list|(
operator|&
name|mapper
argument_list|)
decl_stmt|;
name|mapper
operator|.
name|setModel
argument_list|(
name|model
argument_list|)
expr_stmt|;
name|QLineEdit
name|edit1
decl_stmt|;
name|mapper
operator|.
name|addMapping
argument_list|(
operator|&
name|edit1
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|mapper
operator|.
name|toFirst
argument_list|()
expr_stmt|;
name|QCOMPARE
argument_list|(
name|edit1
operator|.
name|text
argument_list|()
argument_list|,
name|QString
argument_list|(
literal|"item 0 0"
argument_list|)
argument_list|)
expr_stmt|;
name|mapper
operator|.
name|addMapping
argument_list|(
operator|&
name|edit1
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|mapper
operator|.
name|toFirst
argument_list|()
expr_stmt|;
name|QCOMPARE
argument_list|(
name|edit1
operator|.
name|text
argument_list|()
argument_list|,
name|QString
argument_list|(
literal|"item 0 1"
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|mapper
operator|.
name|mappedSection
argument_list|(
operator|&
name|edit1
argument_list|)
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|edit1
operator|.
name|clear
argument_list|()
expr_stmt|;
name|mapper
operator|.
name|removeMapping
argument_list|(
operator|&
name|edit1
argument_list|)
expr_stmt|;
name|mapper
operator|.
name|toFirst
argument_list|()
expr_stmt|;
name|QCOMPARE
argument_list|(
name|edit1
operator|.
name|text
argument_list|()
argument_list|,
name|QString
argument_list|()
argument_list|)
expr_stmt|;
block|{
name|QLineEdit
name|edit2
decl_stmt|;
name|mapper
operator|.
name|addMapping
argument_list|(
operator|&
name|edit2
argument_list|,
literal|2
argument_list|)
expr_stmt|;
name|mapper
operator|.
name|toFirst
argument_list|()
expr_stmt|;
name|QCOMPARE
argument_list|(
name|edit2
operator|.
name|text
argument_list|()
argument_list|,
name|QString
argument_list|(
literal|"item 0 2"
argument_list|)
argument_list|)
expr_stmt|;
block|}
comment|// let the edit go out of scope
name|QCOMPARE
argument_list|(
name|mapper
operator|.
name|mappedWidgetAt
argument_list|(
literal|2
argument_list|)
argument_list|,
operator|(
name|QWidget
operator|*
operator|)
literal|0
argument_list|)
expr_stmt|;
name|mapper
operator|.
name|toLast
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|currentIndexChanged
name|void
name|tst_QDataWidgetMapper
operator|::
name|currentIndexChanged
parameter_list|()
block|{
name|QDataWidgetMapper
name|mapper
decl_stmt|;
name|QAbstractItemModel
modifier|*
name|model
init|=
name|testModel
argument_list|(
operator|&
name|mapper
argument_list|)
decl_stmt|;
name|mapper
operator|.
name|setModel
argument_list|(
name|model
argument_list|)
expr_stmt|;
name|QSignalSpy
name|spy
argument_list|(
operator|&
name|mapper
argument_list|,
name|SIGNAL
argument_list|(
name|currentIndexChanged
argument_list|(
name|int
argument_list|)
argument_list|)
argument_list|)
decl_stmt|;
name|mapper
operator|.
name|toFirst
argument_list|()
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
name|spy
operator|.
name|takeFirst
argument_list|()
operator|.
name|at
argument_list|(
literal|0
argument_list|)
operator|.
name|toInt
argument_list|()
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|mapper
operator|.
name|toNext
argument_list|()
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
name|spy
operator|.
name|takeFirst
argument_list|()
operator|.
name|at
argument_list|(
literal|0
argument_list|)
operator|.
name|toInt
argument_list|()
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|mapper
operator|.
name|setCurrentIndex
argument_list|(
literal|7
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
name|spy
operator|.
name|takeFirst
argument_list|()
operator|.
name|at
argument_list|(
literal|0
argument_list|)
operator|.
name|toInt
argument_list|()
argument_list|,
literal|7
argument_list|)
expr_stmt|;
name|mapper
operator|.
name|setCurrentIndex
argument_list|(
operator|-
literal|1
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|spy
operator|.
name|count
argument_list|()
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|mapper
operator|.
name|setCurrentIndex
argument_list|(
literal|42
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|spy
operator|.
name|count
argument_list|()
argument_list|,
literal|0
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|changingValues
name|void
name|tst_QDataWidgetMapper
operator|::
name|changingValues
parameter_list|()
block|{
name|QDataWidgetMapper
name|mapper
decl_stmt|;
name|QAbstractItemModel
modifier|*
name|model
init|=
name|testModel
argument_list|(
operator|&
name|mapper
argument_list|)
decl_stmt|;
name|mapper
operator|.
name|setModel
argument_list|(
name|model
argument_list|)
expr_stmt|;
name|QLineEdit
name|edit1
decl_stmt|;
name|mapper
operator|.
name|addMapping
argument_list|(
operator|&
name|edit1
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|mapper
operator|.
name|toFirst
argument_list|()
expr_stmt|;
name|QCOMPARE
argument_list|(
name|edit1
operator|.
name|text
argument_list|()
argument_list|,
name|QString
argument_list|(
literal|"item 0 0"
argument_list|)
argument_list|)
expr_stmt|;
name|QLineEdit
name|edit2
decl_stmt|;
name|mapper
operator|.
name|addMapping
argument_list|(
operator|&
name|edit2
argument_list|,
literal|0
argument_list|,
literal|"text"
argument_list|)
expr_stmt|;
name|mapper
operator|.
name|toFirst
argument_list|()
expr_stmt|;
name|QCOMPARE
argument_list|(
name|edit2
operator|.
name|text
argument_list|()
argument_list|,
name|QString
argument_list|(
literal|"item 0 0"
argument_list|)
argument_list|)
expr_stmt|;
name|model
operator|->
name|setData
argument_list|(
name|model
operator|->
name|index
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
argument_list|,
name|QString
argument_list|(
literal|"changed"
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|edit1
operator|.
name|text
argument_list|()
argument_list|,
name|QString
argument_list|(
literal|"changed"
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|edit2
operator|.
name|text
argument_list|()
argument_list|,
name|QString
argument_list|(
literal|"changed"
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|setData
name|void
name|tst_QDataWidgetMapper
operator|::
name|setData
parameter_list|()
block|{
name|QDataWidgetMapper
name|mapper
decl_stmt|;
name|QAbstractItemModel
modifier|*
name|model
init|=
name|testModel
argument_list|(
operator|&
name|mapper
argument_list|)
decl_stmt|;
name|mapper
operator|.
name|setModel
argument_list|(
name|model
argument_list|)
expr_stmt|;
name|QLineEdit
name|edit1
decl_stmt|;
name|QLineEdit
name|edit2
decl_stmt|;
name|QLineEdit
name|edit3
decl_stmt|;
name|mapper
operator|.
name|addMapping
argument_list|(
operator|&
name|edit1
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|mapper
operator|.
name|addMapping
argument_list|(
operator|&
name|edit2
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|mapper
operator|.
name|addMapping
argument_list|(
operator|&
name|edit3
argument_list|,
literal|0
argument_list|,
literal|"text"
argument_list|)
expr_stmt|;
name|mapper
operator|.
name|toFirst
argument_list|()
expr_stmt|;
name|QCOMPARE
argument_list|(
name|edit1
operator|.
name|text
argument_list|()
argument_list|,
name|QString
argument_list|(
literal|"item 0 0"
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|edit2
operator|.
name|text
argument_list|()
argument_list|,
name|QString
argument_list|(
literal|"item 0 1"
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|edit3
operator|.
name|text
argument_list|()
argument_list|,
name|QString
argument_list|(
literal|"item 0 0"
argument_list|)
argument_list|)
expr_stmt|;
name|edit1
operator|.
name|setText
argument_list|(
literal|"new text"
argument_list|)
expr_stmt|;
name|mapper
operator|.
name|submit
argument_list|()
expr_stmt|;
name|QCOMPARE
argument_list|(
name|model
operator|->
name|data
argument_list|(
name|model
operator|->
name|index
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
argument_list|)
operator|.
name|toString
argument_list|()
argument_list|,
name|QString
argument_list|(
literal|"new text"
argument_list|)
argument_list|)
expr_stmt|;
name|edit3
operator|.
name|setText
argument_list|(
literal|"more text"
argument_list|)
expr_stmt|;
name|mapper
operator|.
name|submit
argument_list|()
expr_stmt|;
name|QCOMPARE
argument_list|(
name|model
operator|->
name|data
argument_list|(
name|model
operator|->
name|index
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
argument_list|)
operator|.
name|toString
argument_list|()
argument_list|,
name|QString
argument_list|(
literal|"more text"
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|comboBox
name|void
name|tst_QDataWidgetMapper
operator|::
name|comboBox
parameter_list|()
block|{
name|QDataWidgetMapper
name|mapper
decl_stmt|;
name|QAbstractItemModel
modifier|*
name|model
init|=
name|testModel
argument_list|(
operator|&
name|mapper
argument_list|)
decl_stmt|;
name|mapper
operator|.
name|setModel
argument_list|(
name|model
argument_list|)
expr_stmt|;
name|mapper
operator|.
name|setSubmitPolicy
argument_list|(
name|QDataWidgetMapper
operator|::
name|ManualSubmit
argument_list|)
expr_stmt|;
name|QComboBox
name|readOnlyBox
decl_stmt|;
name|readOnlyBox
operator|.
name|setEditable
argument_list|(
literal|false
argument_list|)
expr_stmt|;
name|readOnlyBox
operator|.
name|addItem
argument_list|(
literal|"read only item 0"
argument_list|)
expr_stmt|;
name|readOnlyBox
operator|.
name|addItem
argument_list|(
literal|"read only item 1"
argument_list|)
expr_stmt|;
name|readOnlyBox
operator|.
name|addItem
argument_list|(
literal|"read only item 2"
argument_list|)
expr_stmt|;
name|QComboBox
name|readWriteBox
decl_stmt|;
name|readWriteBox
operator|.
name|setEditable
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|readWriteBox
operator|.
name|addItem
argument_list|(
literal|"read write item 0"
argument_list|)
expr_stmt|;
name|readWriteBox
operator|.
name|addItem
argument_list|(
literal|"read write item 1"
argument_list|)
expr_stmt|;
name|readWriteBox
operator|.
name|addItem
argument_list|(
literal|"read write item 2"
argument_list|)
expr_stmt|;
comment|// populat the combo boxes with data
name|mapper
operator|.
name|addMapping
argument_list|(
operator|&
name|readOnlyBox
argument_list|,
literal|0
argument_list|,
literal|"currentIndex"
argument_list|)
expr_stmt|;
name|mapper
operator|.
name|addMapping
argument_list|(
operator|&
name|readWriteBox
argument_list|,
literal|1
argument_list|,
literal|"currentText"
argument_list|)
expr_stmt|;
name|mapper
operator|.
name|toFirst
argument_list|()
expr_stmt|;
name|QCOMPARE
argument_list|(
name|readOnlyBox
operator|.
name|currentText
argument_list|()
argument_list|,
name|QString
argument_list|(
literal|"read only item 0"
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|readWriteBox
operator|.
name|currentText
argument_list|()
argument_list|,
name|QString
argument_list|(
literal|"read write item 0"
argument_list|)
argument_list|)
expr_stmt|;
comment|// set some new values on the boxes
name|readOnlyBox
operator|.
name|setCurrentIndex
argument_list|(
literal|1
argument_list|)
expr_stmt|;
name|readWriteBox
operator|.
name|setEditText
argument_list|(
literal|"read write item y"
argument_list|)
expr_stmt|;
name|mapper
operator|.
name|submit
argument_list|()
expr_stmt|;
comment|// make sure the new values are in the model
name|QCOMPARE
argument_list|(
name|model
operator|->
name|data
argument_list|(
name|model
operator|->
name|index
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
argument_list|)
operator|.
name|toInt
argument_list|()
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|model
operator|->
name|data
argument_list|(
name|model
operator|->
name|index
argument_list|(
literal|0
argument_list|,
literal|1
argument_list|)
argument_list|)
operator|.
name|toString
argument_list|()
argument_list|,
name|QString
argument_list|(
literal|"read write item y"
argument_list|)
argument_list|)
expr_stmt|;
comment|// now test updating of the widgets
name|model
operator|->
name|setData
argument_list|(
name|model
operator|->
name|index
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
argument_list|,
literal|2
argument_list|,
name|Qt
operator|::
name|EditRole
argument_list|)
expr_stmt|;
name|model
operator|->
name|setData
argument_list|(
name|model
operator|->
name|index
argument_list|(
literal|0
argument_list|,
literal|1
argument_list|)
argument_list|,
name|QString
argument_list|(
literal|"read write item z"
argument_list|)
argument_list|,
name|Qt
operator|::
name|EditRole
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|readOnlyBox
operator|.
name|currentIndex
argument_list|()
argument_list|,
literal|2
argument_list|)
expr_stmt|;
name|QEXPECT_FAIL
argument_list|(
literal|""
argument_list|,
literal|"See task 125493 and QTBUG-428"
argument_list|,
name|Abort
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|readWriteBox
operator|.
name|currentText
argument_list|()
argument_list|,
name|QString
argument_list|(
literal|"read write item z"
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|mappedWidgetAt
name|void
name|tst_QDataWidgetMapper
operator|::
name|mappedWidgetAt
parameter_list|()
block|{
name|QDataWidgetMapper
name|mapper
decl_stmt|;
name|QAbstractItemModel
modifier|*
name|model
init|=
name|testModel
argument_list|(
operator|&
name|mapper
argument_list|)
decl_stmt|;
name|mapper
operator|.
name|setModel
argument_list|(
name|model
argument_list|)
expr_stmt|;
name|QLineEdit
name|lineEdit1
decl_stmt|;
name|QLineEdit
name|lineEdit2
decl_stmt|;
name|QCOMPARE
argument_list|(
name|mapper
operator|.
name|mappedWidgetAt
argument_list|(
literal|432312
argument_list|)
argument_list|,
operator|(
name|QWidget
operator|*
operator|)
literal|0
argument_list|)
expr_stmt|;
name|mapper
operator|.
name|addMapping
argument_list|(
operator|&
name|lineEdit1
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|mapper
operator|.
name|addMapping
argument_list|(
operator|&
name|lineEdit2
argument_list|,
literal|2
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|mapper
operator|.
name|mappedWidgetAt
argument_list|(
literal|1
argument_list|)
argument_list|,
cast|static_cast
argument_list|<
name|QWidget
operator|*
argument_list|>
argument_list|(
operator|&
name|lineEdit1
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|mapper
operator|.
name|mappedWidgetAt
argument_list|(
literal|2
argument_list|)
argument_list|,
cast|static_cast
argument_list|<
name|QWidget
operator|*
argument_list|>
argument_list|(
operator|&
name|lineEdit2
argument_list|)
argument_list|)
expr_stmt|;
name|mapper
operator|.
name|addMapping
argument_list|(
operator|&
name|lineEdit2
argument_list|,
literal|4242
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|mapper
operator|.
name|mappedWidgetAt
argument_list|(
literal|2
argument_list|)
argument_list|,
operator|(
name|QWidget
operator|*
operator|)
literal|0
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|mapper
operator|.
name|mappedWidgetAt
argument_list|(
literal|4242
argument_list|)
argument_list|,
cast|static_cast
argument_list|<
name|QWidget
operator|*
argument_list|>
argument_list|(
operator|&
name|lineEdit2
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_macro
name|QTEST_MAIN
argument_list|(
argument|tst_QDataWidgetMapper
argument_list|)
end_macro
begin_include
include|#
directive|include
file|"tst_qdatawidgetmapper.moc"
end_include
end_unit
