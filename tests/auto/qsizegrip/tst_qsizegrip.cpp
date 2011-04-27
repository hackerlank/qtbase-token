begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** No Commercial Usage ** This file contains pre-release code and may not be distributed. ** You may use this file in accordance with the terms and conditions ** contained in the Technology Preview License Agreement accompanying ** this package. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights.  These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** If you have questions regarding the use of this file, please contact ** Nokia at qt-info@nokia.com. ** ** ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtTest/QtTest>
end_include
begin_include
include|#
directive|include
file|<QSizeGrip>
end_include
begin_include
include|#
directive|include
file|<QEvent>
end_include
begin_include
include|#
directive|include
file|<QLineEdit>
end_include
begin_include
include|#
directive|include
file|<QVBoxLayout>
end_include
begin_include
include|#
directive|include
file|<QLabel>
end_include
begin_function
DECL|function|sizeGripCorner
specifier|static
specifier|inline
name|Qt
operator|::
name|Corner
name|sizeGripCorner
parameter_list|(
name|QWidget
modifier|*
name|parent
parameter_list|,
name|QSizeGrip
modifier|*
name|sizeGrip
parameter_list|)
block|{
if|if
condition|(
operator|!
name|parent
operator|||
operator|!
name|sizeGrip
condition|)
return|return
name|Qt
operator|::
name|TopLeftCorner
return|;
specifier|const
name|QPoint
name|sizeGripPos
init|=
name|sizeGrip
operator|->
name|mapTo
argument_list|(
name|parent
argument_list|,
name|QPoint
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
argument_list|)
decl_stmt|;
name|bool
name|isAtBottom
init|=
name|sizeGripPos
operator|.
name|y
argument_list|()
operator|>=
name|parent
operator|->
name|height
argument_list|()
operator|/
literal|2
decl_stmt|;
name|bool
name|isAtLeft
init|=
name|sizeGripPos
operator|.
name|x
argument_list|()
operator|<=
name|parent
operator|->
name|width
argument_list|()
operator|/
literal|2
decl_stmt|;
if|if
condition|(
name|isAtLeft
condition|)
return|return
name|isAtBottom
condition|?
name|Qt
operator|::
name|BottomLeftCorner
else|:
name|Qt
operator|::
name|TopLeftCorner
return|;
else|else
return|return
name|isAtBottom
condition|?
name|Qt
operator|::
name|BottomRightCorner
else|:
name|Qt
operator|::
name|TopRightCorner
return|;
block|}
end_function
begin_comment
comment|//TESTED_CLASS=
end_comment
begin_comment
comment|//TESTED_FILES=
end_comment
begin_expr_stmt
DECL|variable|WindowType
name|Q_DECLARE_METATYPE
argument_list|(
name|Qt
operator|::
name|WindowType
argument_list|)
expr_stmt|;
end_expr_stmt
begin_class
DECL|class|tst_QSizeGrip
class|class
name|tst_QSizeGrip
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
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
name|hideAndShowOnWindowStateChange_data
parameter_list|()
function_decl|;
name|void
name|hideAndShowOnWindowStateChange
parameter_list|()
function_decl|;
name|void
name|orientation
parameter_list|()
function_decl|;
private|private:
DECL|member|dummyWidget
name|QLineEdit
modifier|*
name|dummyWidget
decl_stmt|;
block|}
class|;
end_class
begin_class
DECL|class|TestWidget
class|class
name|TestWidget
super|:
specifier|public
name|QWidget
block|{
public|public:
DECL|function|TestWidget
name|TestWidget
parameter_list|(
name|QWidget
modifier|*
name|parent
init|=
literal|0
parameter_list|,
name|Qt
operator|::
name|WindowFlags
name|flags
init|=
literal|0
parameter_list|)
member_init_list|:
name|QWidget
argument_list|(
name|parent
argument_list|,
name|flags
argument_list|)
block|{}
DECL|function|sizeHint
name|QSize
name|sizeHint
parameter_list|()
specifier|const
block|{
return|return
name|QSize
argument_list|(
literal|300
argument_list|,
literal|200
argument_list|)
return|;
block|}
DECL|function|changeEvent
name|void
name|changeEvent
parameter_list|(
name|QEvent
modifier|*
name|event
parameter_list|)
block|{
name|QWidget
operator|::
name|changeEvent
argument_list|(
name|event
argument_list|)
expr_stmt|;
if|if
condition|(
name|isWindow
argument_list|()
operator|&&
name|event
operator|->
name|type
argument_list|()
operator|==
name|QEvent
operator|::
name|WindowStateChange
condition|)
block|{
ifdef|#
directive|ifdef
name|Q_WS_X11
name|qt_x11_wait_for_window_manager
argument_list|(
name|this
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
block|}
block|}
class|;
end_class
begin_function
DECL|function|initTestCase
name|void
name|tst_QSizeGrip
operator|::
name|initTestCase
parameter_list|()
block|{
name|dummyWidget
operator|=
operator|new
name|QLineEdit
expr_stmt|;
name|dummyWidget
operator|->
name|show
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|cleanupTestCase
name|void
name|tst_QSizeGrip
operator|::
name|cleanupTestCase
parameter_list|()
block|{
operator|delete
name|dummyWidget
expr_stmt|;
name|dummyWidget
operator|=
literal|0
expr_stmt|;
block|}
end_function
begin_function
DECL|function|hideAndShowOnWindowStateChange_data
name|void
name|tst_QSizeGrip
operator|::
name|hideAndShowOnWindowStateChange_data
parameter_list|()
block|{
name|QTest
operator|::
name|addColumn
argument_list|<
name|Qt
operator|::
name|WindowType
argument_list|>
argument_list|(
literal|"windowType"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"Qt::Window"
argument_list|)
operator|<<
name|Qt
operator|::
name|Window
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"Qt::SubWindow"
argument_list|)
operator|<<
name|Qt
operator|::
name|SubWindow
expr_stmt|;
block|}
end_function
begin_function
DECL|function|hideAndShowOnWindowStateChange
name|void
name|tst_QSizeGrip
operator|::
name|hideAndShowOnWindowStateChange
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|Qt
operator|::
name|WindowType
argument_list|,
name|windowType
argument_list|)
expr_stmt|;
name|QWidget
modifier|*
name|parentWidget
init|=
name|windowType
operator|==
name|Qt
operator|::
name|Window
condition|?
literal|0
else|:
operator|new
name|QWidget
decl_stmt|;
name|TestWidget
modifier|*
name|widget
init|=
operator|new
name|TestWidget
argument_list|(
name|parentWidget
argument_list|,
name|Qt
operator|::
name|WindowFlags
argument_list|(
name|windowType
argument_list|)
argument_list|)
decl_stmt|;
name|QSizeGrip
modifier|*
name|sizeGrip
init|=
operator|new
name|QSizeGrip
argument_list|(
name|widget
argument_list|)
decl_stmt|;
comment|// Normal.
if|if
condition|(
name|parentWidget
condition|)
name|parentWidget
operator|->
name|show
argument_list|()
expr_stmt|;
else|else
name|widget
operator|->
name|show
argument_list|()
expr_stmt|;
name|QVERIFY
argument_list|(
name|sizeGrip
operator|->
name|isVisible
argument_list|()
argument_list|)
expr_stmt|;
name|widget
operator|->
name|showFullScreen
argument_list|()
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|sizeGrip
operator|->
name|isVisible
argument_list|()
argument_list|)
expr_stmt|;
name|widget
operator|->
name|showNormal
argument_list|()
expr_stmt|;
name|QVERIFY
argument_list|(
name|sizeGrip
operator|->
name|isVisible
argument_list|()
argument_list|)
expr_stmt|;
name|widget
operator|->
name|showMaximized
argument_list|()
expr_stmt|;
ifndef|#
directive|ifndef
name|Q_WS_MAC
name|QVERIFY
argument_list|(
operator|!
name|sizeGrip
operator|->
name|isVisible
argument_list|()
argument_list|)
expr_stmt|;
else|#
directive|else
name|QVERIFY
argument_list|(
name|sizeGrip
operator|->
name|isVisible
argument_list|()
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|widget
operator|->
name|showNormal
argument_list|()
expr_stmt|;
name|QVERIFY
argument_list|(
name|sizeGrip
operator|->
name|isVisible
argument_list|()
argument_list|)
expr_stmt|;
name|sizeGrip
operator|->
name|hide
argument_list|()
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|sizeGrip
operator|->
name|isVisible
argument_list|()
argument_list|)
expr_stmt|;
name|widget
operator|->
name|showFullScreen
argument_list|()
expr_stmt|;
name|widget
operator|->
name|showNormal
argument_list|()
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|sizeGrip
operator|->
name|isVisible
argument_list|()
argument_list|)
expr_stmt|;
name|widget
operator|->
name|showMaximized
argument_list|()
expr_stmt|;
name|widget
operator|->
name|showNormal
argument_list|()
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|sizeGrip
operator|->
name|isVisible
argument_list|()
argument_list|)
expr_stmt|;
operator|delete
name|widget
expr_stmt|;
operator|delete
name|parentWidget
expr_stmt|;
block|}
end_function
begin_function
DECL|function|orientation
name|void
name|tst_QSizeGrip
operator|::
name|orientation
parameter_list|()
block|{
name|TestWidget
name|widget
decl_stmt|;
name|widget
operator|.
name|setLayout
argument_list|(
operator|new
name|QVBoxLayout
argument_list|)
expr_stmt|;
name|QSizeGrip
modifier|*
name|sizeGrip
init|=
operator|new
name|QSizeGrip
argument_list|(
operator|&
name|widget
argument_list|)
decl_stmt|;
name|sizeGrip
operator|->
name|setFixedSize
argument_list|(
name|sizeGrip
operator|->
name|sizeHint
argument_list|()
argument_list|)
expr_stmt|;
name|widget
operator|.
name|layout
argument_list|()
operator|->
name|addWidget
argument_list|(
name|sizeGrip
argument_list|)
expr_stmt|;
name|widget
operator|.
name|layout
argument_list|()
operator|->
name|setAlignment
argument_list|(
name|sizeGrip
argument_list|,
name|Qt
operator|::
name|AlignBottom
operator||
name|Qt
operator|::
name|AlignRight
argument_list|)
expr_stmt|;
name|widget
operator|.
name|show
argument_list|()
expr_stmt|;
name|QCOMPARE
argument_list|(
name|sizeGripCorner
argument_list|(
operator|&
name|widget
argument_list|,
name|sizeGrip
argument_list|)
argument_list|,
name|Qt
operator|::
name|BottomRightCorner
argument_list|)
expr_stmt|;
name|widget
operator|.
name|setLayoutDirection
argument_list|(
name|Qt
operator|::
name|RightToLeft
argument_list|)
expr_stmt|;
name|qApp
operator|->
name|processEvents
argument_list|()
expr_stmt|;
name|QCOMPARE
argument_list|(
name|sizeGripCorner
argument_list|(
operator|&
name|widget
argument_list|,
name|sizeGrip
argument_list|)
argument_list|,
name|Qt
operator|::
name|BottomLeftCorner
argument_list|)
expr_stmt|;
name|widget
operator|.
name|unsetLayoutDirection
argument_list|()
expr_stmt|;
name|qApp
operator|->
name|processEvents
argument_list|()
expr_stmt|;
name|QCOMPARE
argument_list|(
name|sizeGripCorner
argument_list|(
operator|&
name|widget
argument_list|,
name|sizeGrip
argument_list|)
argument_list|,
name|Qt
operator|::
name|BottomRightCorner
argument_list|)
expr_stmt|;
name|widget
operator|.
name|layout
argument_list|()
operator|->
name|setAlignment
argument_list|(
name|sizeGrip
argument_list|,
name|Qt
operator|::
name|AlignTop
operator||
name|Qt
operator|::
name|AlignRight
argument_list|)
expr_stmt|;
name|qApp
operator|->
name|processEvents
argument_list|()
expr_stmt|;
name|QCOMPARE
argument_list|(
name|sizeGripCorner
argument_list|(
operator|&
name|widget
argument_list|,
name|sizeGrip
argument_list|)
argument_list|,
name|Qt
operator|::
name|TopRightCorner
argument_list|)
expr_stmt|;
name|widget
operator|.
name|setLayoutDirection
argument_list|(
name|Qt
operator|::
name|RightToLeft
argument_list|)
expr_stmt|;
name|qApp
operator|->
name|processEvents
argument_list|()
expr_stmt|;
name|QCOMPARE
argument_list|(
name|sizeGripCorner
argument_list|(
operator|&
name|widget
argument_list|,
name|sizeGrip
argument_list|)
argument_list|,
name|Qt
operator|::
name|TopLeftCorner
argument_list|)
expr_stmt|;
name|widget
operator|.
name|unsetLayoutDirection
argument_list|()
expr_stmt|;
name|qApp
operator|->
name|processEvents
argument_list|()
expr_stmt|;
name|QCOMPARE
argument_list|(
name|sizeGripCorner
argument_list|(
operator|&
name|widget
argument_list|,
name|sizeGrip
argument_list|)
argument_list|,
name|Qt
operator|::
name|TopRightCorner
argument_list|)
expr_stmt|;
block|}
end_function
begin_macro
name|QTEST_MAIN
argument_list|(
argument|tst_QSizeGrip
argument_list|)
end_macro
begin_include
include|#
directive|include
file|"tst_qsizegrip.moc"
end_include
end_unit
