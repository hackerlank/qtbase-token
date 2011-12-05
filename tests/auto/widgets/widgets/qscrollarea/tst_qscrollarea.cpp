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
file|<qcoreapplication.h>
end_include
begin_include
include|#
directive|include
file|<qdebug.h>
end_include
begin_include
include|#
directive|include
file|<qscrollarea.h>
end_include
begin_include
include|#
directive|include
file|<qlayout.h>
end_include
begin_class
DECL|class|tst_QScrollArea
class|class
name|tst_QScrollArea
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
public|public:
name|tst_QScrollArea
parameter_list|()
constructor_decl|;
specifier|virtual
name|~
name|tst_QScrollArea
parameter_list|()
destructor_decl|;
private|private
name|slots
private|:
name|void
name|getSetCheck
parameter_list|()
function_decl|;
name|void
name|ensureMicroFocusVisible_Task_167838
parameter_list|()
function_decl|;
name|void
name|checkHFW_Task_197736
parameter_list|()
function_decl|;
block|}
class|;
end_class
begin_constructor
DECL|function|tst_QScrollArea
name|tst_QScrollArea
operator|::
name|tst_QScrollArea
parameter_list|()
block|{ }
end_constructor
begin_destructor
DECL|function|~tst_QScrollArea
name|tst_QScrollArea
operator|::
name|~
name|tst_QScrollArea
parameter_list|()
block|{ }
end_destructor
begin_comment
comment|// Testing get/set functions
end_comment
begin_function
DECL|function|getSetCheck
name|void
name|tst_QScrollArea
operator|::
name|getSetCheck
parameter_list|()
block|{
name|QScrollArea
name|obj1
decl_stmt|;
comment|// QWidget * QScrollArea::widget()
comment|// void QScrollArea::setWidget(QWidget *)
name|QWidget
modifier|*
name|var1
init|=
operator|new
name|QWidget
argument_list|()
decl_stmt|;
name|obj1
operator|.
name|setWidget
argument_list|(
name|var1
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|var1
argument_list|,
name|obj1
operator|.
name|widget
argument_list|()
argument_list|)
expr_stmt|;
name|obj1
operator|.
name|setWidget
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
name|var1
argument_list|,
name|obj1
operator|.
name|widget
argument_list|()
argument_list|)
expr_stmt|;
comment|// Cannot set a 0-widget. Old widget returned
comment|// delete var1; // No delete, since QScrollArea takes ownership
comment|// bool QScrollArea::widgetResizable()
comment|// void QScrollArea::setWidgetResizable(bool)
name|obj1
operator|.
name|setWidgetResizable
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
name|widgetResizable
argument_list|()
argument_list|)
expr_stmt|;
name|obj1
operator|.
name|setWidgetResizable
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
name|widgetResizable
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_class
DECL|class|WidgetWithMicroFocus
class|class
name|WidgetWithMicroFocus
super|:
specifier|public
name|QWidget
block|{
public|public:
DECL|function|WidgetWithMicroFocus
name|WidgetWithMicroFocus
parameter_list|(
name|QWidget
modifier|*
name|parent
init|=
literal|0
parameter_list|)
member_init_list|:
name|QWidget
argument_list|(
name|parent
argument_list|)
block|{
name|setBackgroundRole
argument_list|(
name|QPalette
operator|::
name|Dark
argument_list|)
expr_stmt|;
block|}
protected|protected:
DECL|function|inputMethodQuery
name|QVariant
name|inputMethodQuery
parameter_list|(
name|Qt
operator|::
name|InputMethodQuery
name|query
parameter_list|)
specifier|const
block|{
if|if
condition|(
name|query
operator|==
name|Qt
operator|::
name|ImMicroFocus
condition|)
return|return
name|QRect
argument_list|(
name|width
argument_list|()
operator|/
literal|2
argument_list|,
name|height
argument_list|()
operator|/
literal|2
argument_list|,
literal|5
argument_list|,
literal|5
argument_list|)
return|;
return|return
name|QWidget
operator|::
name|inputMethodQuery
argument_list|(
name|query
argument_list|)
return|;
block|}
comment|//     void paintEvent(QPaintEvent *event)
comment|//     {
comment|//         QPainter painter(this);
comment|//         painter.fillRect(rect(), QBrush(Qt::red));
comment|//     }
block|}
class|;
end_class
begin_function
DECL|function|ensureMicroFocusVisible_Task_167838
name|void
name|tst_QScrollArea
operator|::
name|ensureMicroFocusVisible_Task_167838
parameter_list|()
block|{
name|QScrollArea
name|scrollArea
decl_stmt|;
name|scrollArea
operator|.
name|resize
argument_list|(
literal|100
argument_list|,
literal|100
argument_list|)
expr_stmt|;
name|scrollArea
operator|.
name|show
argument_list|()
expr_stmt|;
name|QWidget
modifier|*
name|parent
init|=
operator|new
name|QWidget
decl_stmt|;
name|parent
operator|->
name|setLayout
argument_list|(
operator|new
name|QVBoxLayout
argument_list|)
expr_stmt|;
name|QWidget
modifier|*
name|child
init|=
operator|new
name|WidgetWithMicroFocus
decl_stmt|;
name|parent
operator|->
name|layout
argument_list|()
operator|->
name|addWidget
argument_list|(
name|child
argument_list|)
expr_stmt|;
name|parent
operator|->
name|resize
argument_list|(
literal|300
argument_list|,
literal|300
argument_list|)
expr_stmt|;
name|scrollArea
operator|.
name|setWidget
argument_list|(
name|parent
argument_list|)
expr_stmt|;
name|scrollArea
operator|.
name|ensureWidgetVisible
argument_list|(
name|child
argument_list|,
literal|10
argument_list|,
literal|10
argument_list|)
expr_stmt|;
name|QRect
name|microFocus
init|=
name|child
operator|->
name|inputMethodQuery
argument_list|(
name|Qt
operator|::
name|ImMicroFocus
argument_list|)
operator|.
name|toRect
argument_list|()
decl_stmt|;
name|QPoint
name|p
init|=
name|child
operator|->
name|mapTo
argument_list|(
name|scrollArea
operator|.
name|viewport
argument_list|()
argument_list|,
name|microFocus
operator|.
name|topLeft
argument_list|()
argument_list|)
decl_stmt|;
name|microFocus
operator|.
name|translate
argument_list|(
name|p
operator|-
name|microFocus
operator|.
name|topLeft
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|scrollArea
operator|.
name|viewport
argument_list|()
operator|->
name|rect
argument_list|()
operator|.
name|contains
argument_list|(
name|microFocus
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_class
DECL|class|HFWWidget
class|class
name|HFWWidget
super|:
specifier|public
name|QWidget
block|{
public|public:
name|HFWWidget
parameter_list|()
constructor_decl|;
name|int
name|heightForWidth
parameter_list|(
name|int
name|w
parameter_list|)
specifier|const
function_decl|;
block|}
class|;
end_class
begin_constructor
DECL|function|HFWWidget
name|HFWWidget
operator|::
name|HFWWidget
parameter_list|()
member_init_list|:
name|QWidget
argument_list|()
block|{
name|setMinimumSize
argument_list|(
name|QSize
argument_list|(
literal|100
argument_list|,
literal|50
argument_list|)
argument_list|)
expr_stmt|;
name|QSizePolicy
name|s
init|=
name|sizePolicy
argument_list|()
decl_stmt|;
name|s
operator|.
name|setHeightForWidth
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|setSizePolicy
argument_list|(
name|s
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_function
DECL|function|heightForWidth
name|int
name|HFWWidget
operator|::
name|heightForWidth
parameter_list|(
name|int
name|w
parameter_list|)
specifier|const
block|{
comment|// Mimic a label - the narrower we are, the taller we have to be
if|if
condition|(
name|w
operator|>
literal|0
condition|)
return|return
literal|40000
operator|/
name|w
return|;
else|else
return|return
literal|40000
return|;
block|}
end_function
begin_function
DECL|function|checkHFW_Task_197736
name|void
name|tst_QScrollArea
operator|::
name|checkHFW_Task_197736
parameter_list|()
block|{
name|QScrollArea
name|scrollArea
decl_stmt|;
name|HFWWidget
modifier|*
name|w
init|=
operator|new
name|HFWWidget
decl_stmt|;
name|scrollArea
operator|.
name|resize
argument_list|(
literal|200
argument_list|,
literal|100
argument_list|)
expr_stmt|;
name|scrollArea
operator|.
name|show
argument_list|()
expr_stmt|;
name|scrollArea
operator|.
name|setWidgetResizable
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|scrollArea
operator|.
name|setWidget
argument_list|(
name|w
argument_list|)
expr_stmt|;
comment|// at 200x100px, we expect HFW to be 200px tall, not 100px
name|QVERIFY
argument_list|(
name|w
operator|->
name|height
argument_list|()
operator|>=
literal|200
argument_list|)
expr_stmt|;
comment|// at 200x300px, we expect HFW to be 300px tall (the heightForWidth is a min, not prescribed)
name|scrollArea
operator|.
name|resize
argument_list|(
name|QSize
argument_list|(
literal|200
argument_list|,
literal|300
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|w
operator|->
name|height
argument_list|()
operator|>=
literal|250
argument_list|)
expr_stmt|;
comment|// 50px for a fudge factor (size of frame margins/scrollbars etc)
comment|// make sure this only happens with widget resizable
name|scrollArea
operator|.
name|setWidgetResizable
argument_list|(
literal|false
argument_list|)
expr_stmt|;
name|scrollArea
operator|.
name|resize
argument_list|(
name|QSize
argument_list|(
literal|100
argument_list|,
literal|100
argument_list|)
argument_list|)
expr_stmt|;
name|w
operator|->
name|resize
argument_list|(
name|QSize
argument_list|(
literal|200
argument_list|,
literal|200
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|w
operator|->
name|width
argument_list|()
operator|==
literal|200
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|w
operator|->
name|height
argument_list|()
operator|==
literal|200
argument_list|)
expr_stmt|;
block|}
end_function
begin_macro
name|QTEST_MAIN
argument_list|(
argument|tst_QScrollArea
argument_list|)
end_macro
begin_include
include|#
directive|include
file|"tst_qscrollarea.moc"
end_include
end_unit
