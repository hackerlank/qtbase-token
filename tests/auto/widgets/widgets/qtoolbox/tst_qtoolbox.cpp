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
file|<qtoolbox.h>
end_include
begin_macro
name|QT_FORWARD_DECLARE_CLASS
argument_list|(
argument|QToolBox
argument_list|)
end_macro
begin_class_decl
class_decl|class
name|tst_QToolBoxPrivate
class_decl|;
end_class_decl
begin_class
DECL|class|tst_QToolBox
class|class
name|tst_QToolBox
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
public|public:
name|tst_QToolBox
parameter_list|()
constructor_decl|;
specifier|virtual
name|~
name|tst_QToolBox
parameter_list|()
destructor_decl|;
protected|protected
name|slots
protected|:
name|void
name|currentChanged
parameter_list|(
name|int
parameter_list|)
function_decl|;
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
name|populate
parameter_list|()
function_decl|;
name|void
name|change
parameter_list|()
function_decl|;
name|void
name|clear
parameter_list|()
function_decl|;
private|private:
DECL|member|testWidget
name|QToolBox
modifier|*
name|testWidget
decl_stmt|;
DECL|member|currentIndex
name|int
name|currentIndex
decl_stmt|;
DECL|member|d
name|tst_QToolBoxPrivate
modifier|*
name|d
decl_stmt|;
block|}
class|;
end_class
begin_comment
comment|// Testing get/set functions
end_comment
begin_function
DECL|function|getSetCheck
name|void
name|tst_QToolBox
operator|::
name|getSetCheck
parameter_list|()
block|{
name|QToolBox
name|obj1
decl_stmt|;
name|QWidget
modifier|*
name|w1
init|=
operator|new
name|QWidget
decl_stmt|;
name|QWidget
modifier|*
name|w2
init|=
operator|new
name|QWidget
decl_stmt|;
name|QWidget
modifier|*
name|w3
init|=
operator|new
name|QWidget
decl_stmt|;
name|QWidget
modifier|*
name|w4
init|=
operator|new
name|QWidget
decl_stmt|;
name|QWidget
modifier|*
name|w5
init|=
operator|new
name|QWidget
decl_stmt|;
name|obj1
operator|.
name|addItem
argument_list|(
name|w1
argument_list|,
literal|"Page1"
argument_list|)
expr_stmt|;
name|obj1
operator|.
name|addItem
argument_list|(
name|w2
argument_list|,
literal|"Page2"
argument_list|)
expr_stmt|;
name|obj1
operator|.
name|addItem
argument_list|(
name|w3
argument_list|,
literal|"Page3"
argument_list|)
expr_stmt|;
name|obj1
operator|.
name|addItem
argument_list|(
name|w4
argument_list|,
literal|"Page4"
argument_list|)
expr_stmt|;
name|obj1
operator|.
name|addItem
argument_list|(
name|w5
argument_list|,
literal|"Page5"
argument_list|)
expr_stmt|;
comment|// int QToolBox::currentIndex()
comment|// void QToolBox::setCurrentIndex(int)
name|obj1
operator|.
name|setCurrentIndex
argument_list|(
literal|3
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
literal|3
argument_list|,
name|obj1
operator|.
name|currentIndex
argument_list|()
argument_list|)
expr_stmt|;
name|obj1
operator|.
name|setCurrentIndex
argument_list|(
name|INT_MIN
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
literal|3
argument_list|,
name|obj1
operator|.
name|currentIndex
argument_list|()
argument_list|)
expr_stmt|;
name|obj1
operator|.
name|setCurrentIndex
argument_list|(
name|INT_MAX
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
literal|3
argument_list|,
name|obj1
operator|.
name|currentIndex
argument_list|()
argument_list|)
expr_stmt|;
name|obj1
operator|.
name|setCurrentIndex
argument_list|(
literal|4
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
literal|4
argument_list|,
name|obj1
operator|.
name|currentIndex
argument_list|()
argument_list|)
expr_stmt|;
comment|// QWidget * QToolBox::currentWidget()
comment|// void QToolBox::setCurrentWidget(QWidget *)
name|obj1
operator|.
name|setCurrentWidget
argument_list|(
name|w1
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|w1
argument_list|,
name|obj1
operator|.
name|currentWidget
argument_list|()
argument_list|)
expr_stmt|;
name|obj1
operator|.
name|setCurrentWidget
argument_list|(
name|w3
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|w3
argument_list|,
name|obj1
operator|.
name|currentWidget
argument_list|()
argument_list|)
expr_stmt|;
name|obj1
operator|.
name|setCurrentWidget
argument_list|(
operator|(
name|QWidget
operator|*
operator|)
literal|0
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|w3
argument_list|,
name|obj1
operator|.
name|currentWidget
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_constructor
DECL|function|tst_QToolBox
name|tst_QToolBox
operator|::
name|tst_QToolBox
parameter_list|()
block|{ }
end_constructor
begin_destructor
DECL|function|~tst_QToolBox
name|tst_QToolBox
operator|::
name|~
name|tst_QToolBox
parameter_list|()
block|{ }
end_destructor
begin_class
DECL|class|tst_QToolBoxPrivate
class|class
name|tst_QToolBoxPrivate
block|{
public|public:
DECL|member|count0
DECL|member|count1
DECL|member|count2
DECL|member|count3
DECL|member|count4
name|int
name|count0
decl_stmt|,
name|count1
decl_stmt|,
name|count2
decl_stmt|,
name|count3
decl_stmt|,
name|count4
decl_stmt|;
DECL|member|idx1
DECL|member|idx2
DECL|member|idx3
DECL|member|idx32
name|int
name|idx1
decl_stmt|,
name|idx2
decl_stmt|,
name|idx3
decl_stmt|,
name|idx32
decl_stmt|;
DECL|member|i0
DECL|member|i1
DECL|member|i2
DECL|member|i3
DECL|member|i4
name|int
name|i0
decl_stmt|,
name|i1
decl_stmt|,
name|i2
decl_stmt|,
name|i3
decl_stmt|,
name|i4
decl_stmt|;
DECL|member|ci0
DECL|member|ci1
DECL|member|ci2
DECL|member|ci3
DECL|member|ci4
name|int
name|ci0
decl_stmt|,
name|ci1
decl_stmt|,
name|ci2
decl_stmt|,
name|ci3
decl_stmt|,
name|ci4
decl_stmt|;
DECL|member|ci_correct
name|bool
name|ci_correct
decl_stmt|;
DECL|member|manual_count
name|int
name|manual_count
decl_stmt|;
block|}
class|;
end_class
begin_function
DECL|function|init
name|void
name|tst_QToolBox
operator|::
name|init
parameter_list|()
block|{
name|currentIndex
operator|=
operator|-
literal|1
expr_stmt|;
name|testWidget
operator|=
operator|new
name|QToolBox
expr_stmt|;
name|connect
argument_list|(
name|testWidget
argument_list|,
name|SIGNAL
argument_list|(
name|currentChanged
argument_list|(
name|int
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|currentChanged
argument_list|(
name|int
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|d
operator|=
operator|new
name|tst_QToolBoxPrivate
expr_stmt|;
name|d
operator|->
name|count0
operator|=
name|testWidget
operator|->
name|count
argument_list|()
expr_stmt|;
name|d
operator|->
name|ci0
operator|=
name|currentIndex
expr_stmt|;
name|QWidget
modifier|*
name|item1
init|=
operator|new
name|QWidget
argument_list|(
name|testWidget
argument_list|)
decl_stmt|;
name|testWidget
operator|->
name|addItem
argument_list|(
name|item1
argument_list|,
literal|"Item1"
argument_list|)
expr_stmt|;
name|d
operator|->
name|count1
operator|=
name|testWidget
operator|->
name|count
argument_list|()
expr_stmt|;
name|d
operator|->
name|idx1
operator|=
name|testWidget
operator|->
name|indexOf
argument_list|(
name|item1
argument_list|)
expr_stmt|;
name|d
operator|->
name|ci1
operator|=
name|currentIndex
expr_stmt|;
name|d
operator|->
name|ci_correct
operator|=
name|testWidget
operator|->
name|widget
argument_list|(
name|testWidget
operator|->
name|currentIndex
argument_list|()
argument_list|)
operator|==
name|item1
expr_stmt|;
name|currentIndex
operator|=
operator|-
literal|1
expr_stmt|;
comment|// reset to make sure signal doesn't fire
name|QWidget
modifier|*
name|item3
init|=
operator|new
name|QWidget
argument_list|(
name|testWidget
argument_list|)
decl_stmt|;
name|testWidget
operator|->
name|addItem
argument_list|(
name|item3
argument_list|,
literal|"Item3"
argument_list|)
expr_stmt|;
name|d
operator|->
name|count2
operator|=
name|testWidget
operator|->
name|count
argument_list|()
expr_stmt|;
name|d
operator|->
name|idx3
operator|=
name|testWidget
operator|->
name|indexOf
argument_list|(
name|item3
argument_list|)
expr_stmt|;
name|d
operator|->
name|ci2
operator|=
name|currentIndex
expr_stmt|;
name|QWidget
modifier|*
name|item2
init|=
operator|new
name|QWidget
argument_list|(
name|testWidget
argument_list|)
decl_stmt|;
name|testWidget
operator|->
name|insertItem
argument_list|(
literal|1
argument_list|,
name|item2
argument_list|,
literal|"Item2"
argument_list|)
expr_stmt|;
name|d
operator|->
name|count3
operator|=
name|testWidget
operator|->
name|count
argument_list|()
expr_stmt|;
name|d
operator|->
name|idx2
operator|=
name|testWidget
operator|->
name|indexOf
argument_list|(
name|item2
argument_list|)
expr_stmt|;
name|d
operator|->
name|idx32
operator|=
name|testWidget
operator|->
name|indexOf
argument_list|(
name|item3
argument_list|)
expr_stmt|;
name|d
operator|->
name|ci3
operator|=
name|currentIndex
expr_stmt|;
name|QWidget
modifier|*
name|item0
init|=
operator|new
name|QWidget
argument_list|(
name|testWidget
argument_list|)
decl_stmt|;
name|testWidget
operator|->
name|insertItem
argument_list|(
literal|0
argument_list|,
name|item0
argument_list|,
literal|"Item0"
argument_list|)
expr_stmt|;
name|d
operator|->
name|count4
operator|=
name|testWidget
operator|->
name|count
argument_list|()
expr_stmt|;
name|d
operator|->
name|i0
operator|=
name|testWidget
operator|->
name|indexOf
argument_list|(
name|item0
argument_list|)
expr_stmt|;
name|d
operator|->
name|i1
operator|=
name|testWidget
operator|->
name|indexOf
argument_list|(
name|item1
argument_list|)
expr_stmt|;
name|d
operator|->
name|i2
operator|=
name|testWidget
operator|->
name|indexOf
argument_list|(
name|item2
argument_list|)
expr_stmt|;
name|d
operator|->
name|i3
operator|=
name|testWidget
operator|->
name|indexOf
argument_list|(
name|item3
argument_list|)
expr_stmt|;
name|d
operator|->
name|ci4
operator|=
name|currentIndex
expr_stmt|;
name|d
operator|->
name|manual_count
operator|=
literal|4
expr_stmt|;
block|}
end_function
begin_function
DECL|function|cleanup
name|void
name|tst_QToolBox
operator|::
name|cleanup
parameter_list|()
block|{
operator|delete
name|testWidget
expr_stmt|;
operator|delete
name|d
expr_stmt|;
block|}
end_function
begin_function
DECL|function|initTestCase
name|void
name|tst_QToolBox
operator|::
name|initTestCase
parameter_list|()
block|{ }
end_function
begin_function
DECL|function|cleanupTestCase
name|void
name|tst_QToolBox
operator|::
name|cleanupTestCase
parameter_list|()
block|{ }
end_function
begin_function
DECL|function|currentChanged
name|void
name|tst_QToolBox
operator|::
name|currentChanged
parameter_list|(
name|int
name|index
parameter_list|)
block|{
name|currentIndex
operator|=
name|index
expr_stmt|;
block|}
end_function
begin_function
DECL|function|populate
name|void
name|tst_QToolBox
operator|::
name|populate
parameter_list|()
block|{
comment|// verify preconditions
name|QCOMPARE
argument_list|(
name|d
operator|->
name|count0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|d
operator|->
name|ci0
argument_list|,
operator|-
literal|1
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|d
operator|->
name|ci_correct
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|d
operator|->
name|count1
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|d
operator|->
name|idx1
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|d
operator|->
name|ci1
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|d
operator|->
name|count2
argument_list|,
literal|2
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|d
operator|->
name|idx3
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|d
operator|->
name|ci2
argument_list|,
operator|-
literal|1
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|d
operator|->
name|count3
argument_list|,
literal|3
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|d
operator|->
name|idx2
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|d
operator|->
name|idx32
argument_list|,
literal|2
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|d
operator|->
name|ci3
argument_list|,
operator|-
literal|1
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|d
operator|->
name|count4
argument_list|,
literal|4
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|d
operator|->
name|i0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|d
operator|->
name|i1
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|d
operator|->
name|i2
argument_list|,
literal|2
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|d
operator|->
name|i3
argument_list|,
literal|3
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|d
operator|->
name|ci4
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|testWidget
operator|->
name|count
argument_list|()
argument_list|,
name|d
operator|->
name|manual_count
argument_list|)
expr_stmt|;
name|int
name|oldcount
init|=
name|testWidget
operator|->
name|count
argument_list|()
decl_stmt|;
name|QWidget
modifier|*
name|item
init|=
operator|new
name|QWidget
argument_list|(
name|testWidget
argument_list|)
decl_stmt|;
name|testWidget
operator|->
name|addItem
argument_list|(
name|item
argument_list|,
literal|"Item"
argument_list|)
expr_stmt|;
name|d
operator|->
name|manual_count
operator|++
expr_stmt|;
name|QCOMPARE
argument_list|(
name|testWidget
operator|->
name|count
argument_list|()
argument_list|,
name|oldcount
operator|+
literal|1
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|testWidget
operator|->
name|indexOf
argument_list|(
name|item
argument_list|)
argument_list|,
name|oldcount
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|testWidget
operator|->
name|widget
argument_list|(
name|oldcount
argument_list|)
argument_list|,
name|item
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|change
name|void
name|tst_QToolBox
operator|::
name|change
parameter_list|()
block|{
name|QWidget
modifier|*
name|lastItem
init|=
name|testWidget
operator|->
name|widget
argument_list|(
name|testWidget
operator|->
name|count
argument_list|()
argument_list|)
decl_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|lastItem
argument_list|)
expr_stmt|;
name|lastItem
operator|=
name|testWidget
operator|->
name|widget
argument_list|(
name|testWidget
operator|->
name|count
argument_list|()
operator|-
literal|1
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|lastItem
argument_list|)
expr_stmt|;
for|for
control|(
name|int
name|c
init|=
literal|0
init|;
name|c
operator|<
name|testWidget
operator|->
name|count
argument_list|()
condition|;
operator|++
name|c
control|)
block|{
name|QString
name|label
init|=
literal|"Item "
operator|+
name|QString
operator|::
name|number
argument_list|(
name|c
argument_list|)
decl_stmt|;
name|testWidget
operator|->
name|setItemText
argument_list|(
name|c
argument_list|,
name|label
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|testWidget
operator|->
name|itemText
argument_list|(
name|c
argument_list|)
argument_list|,
name|label
argument_list|)
expr_stmt|;
block|}
name|testWidget
operator|->
name|setCurrentIndex
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|currentIndex
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|currentIndex
operator|=
operator|-
literal|1
expr_stmt|;
comment|// reset to make sure signal doesn't fire
name|testWidget
operator|->
name|setCurrentIndex
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|currentIndex
argument_list|,
operator|-
literal|1
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|testWidget
operator|->
name|currentIndex
argument_list|()
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|testWidget
operator|->
name|setCurrentIndex
argument_list|(
name|testWidget
operator|->
name|count
argument_list|()
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|currentIndex
argument_list|,
operator|-
literal|1
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|testWidget
operator|->
name|currentIndex
argument_list|()
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|testWidget
operator|->
name|setCurrentIndex
argument_list|(
literal|1
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|currentIndex
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|testWidget
operator|->
name|currentIndex
argument_list|()
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|testWidget
operator|->
name|setItemEnabled
argument_list|(
name|testWidget
operator|->
name|currentIndex
argument_list|()
argument_list|,
name|FALSE
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|currentIndex
argument_list|,
literal|2
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|testWidget
operator|->
name|currentIndex
argument_list|()
argument_list|,
literal|2
argument_list|)
expr_stmt|;
name|currentIndex
operator|=
operator|-
literal|1
expr_stmt|;
name|testWidget
operator|->
name|setItemEnabled
argument_list|(
name|testWidget
operator|->
name|indexOf
argument_list|(
name|lastItem
argument_list|)
argument_list|,
name|FALSE
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|currentIndex
argument_list|,
operator|-
literal|1
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|testWidget
operator|->
name|currentIndex
argument_list|()
argument_list|,
literal|2
argument_list|)
expr_stmt|;
name|testWidget
operator|->
name|setItemEnabled
argument_list|(
name|testWidget
operator|->
name|currentIndex
argument_list|()
argument_list|,
name|FALSE
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|currentIndex
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|currentIndex
operator|=
operator|-
literal|1
expr_stmt|;
name|testWidget
operator|->
name|setItemEnabled
argument_list|(
name|testWidget
operator|->
name|currentIndex
argument_list|()
argument_list|,
name|FALSE
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|currentIndex
argument_list|,
operator|-
literal|1
argument_list|)
expr_stmt|;
name|testWidget
operator|->
name|setItemEnabled
argument_list|(
literal|1
argument_list|,
name|TRUE
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|clear
name|void
name|tst_QToolBox
operator|::
name|clear
parameter_list|()
block|{
comment|// precondition: only item(1) is enabled
name|QCOMPARE
argument_list|(
name|testWidget
operator|->
name|count
argument_list|()
argument_list|,
literal|4
argument_list|)
expr_stmt|;
name|testWidget
operator|->
name|setCurrentIndex
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|currentIndex
operator|=
operator|-
literal|1
expr_stmt|;
comment|// delete current item(0)
name|QPointer
argument_list|<
name|QWidget
argument_list|>
name|item
init|=
name|testWidget
operator|->
name|widget
argument_list|(
name|testWidget
operator|->
name|currentIndex
argument_list|()
argument_list|)
decl_stmt|;
name|testWidget
operator|->
name|removeItem
argument_list|(
name|testWidget
operator|->
name|indexOf
argument_list|(
name|item
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|item
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|testWidget
operator|->
name|count
argument_list|()
argument_list|,
literal|3
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|testWidget
operator|->
name|indexOf
argument_list|(
name|item
argument_list|)
argument_list|,
operator|-
literal|1
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|testWidget
operator|->
name|currentIndex
argument_list|()
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|currentIndex
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|currentIndex
operator|=
operator|-
literal|1
expr_stmt|;
name|item
operator|=
name|testWidget
operator|->
name|widget
argument_list|(
literal|1
argument_list|)
expr_stmt|;
name|testWidget
operator|->
name|removeItem
argument_list|(
name|testWidget
operator|->
name|indexOf
argument_list|(
name|item
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|item
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|currentIndex
argument_list|,
operator|-
literal|1
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|testWidget
operator|->
name|currentIndex
argument_list|()
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|testWidget
operator|->
name|count
argument_list|()
argument_list|,
literal|2
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|testWidget
operator|->
name|indexOf
argument_list|(
name|item
argument_list|)
argument_list|,
operator|-
literal|1
argument_list|)
expr_stmt|;
name|item
operator|=
name|testWidget
operator|->
name|widget
argument_list|(
literal|1
argument_list|)
expr_stmt|;
operator|delete
name|item
expr_stmt|;
name|QCOMPARE
argument_list|(
name|testWidget
operator|->
name|count
argument_list|()
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|currentIndex
argument_list|,
operator|-
literal|1
argument_list|)
expr_stmt|;
name|currentIndex
operator|=
name|testWidget
operator|->
name|currentIndex
argument_list|()
expr_stmt|;
name|item
operator|=
name|testWidget
operator|->
name|widget
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|testWidget
operator|->
name|removeItem
argument_list|(
name|testWidget
operator|->
name|indexOf
argument_list|(
name|item
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|testWidget
operator|->
name|count
argument_list|()
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|currentIndex
argument_list|,
operator|-
literal|1
argument_list|)
expr_stmt|;
block|}
end_function
begin_macro
name|QTEST_MAIN
argument_list|(
argument|tst_QToolBox
argument_list|)
end_macro
begin_include
include|#
directive|include
file|"tst_qtoolbox.moc"
end_include
end_unit
