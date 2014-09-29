begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2014 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia. For licensing terms and ** conditions see http://qt.digia.com/licensing. For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights. These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtTest/QTest>
end_include
begin_include
include|#
directive|include
file|<QtWidgets/QApplication>
end_include
begin_include
include|#
directive|include
file|<QtWidgets/QWidget>
end_include
begin_include
include|#
directive|include
file|<QtWidgets/QGestureEvent>
end_include
begin_include
include|#
directive|include
file|<QtGui/QScreen>
end_include
begin_include
include|#
directive|include
file|<QtGui/QTouchDevice>
end_include
begin_include
include|#
directive|include
file|<QtCore/QVector>
end_include
begin_include
include|#
directive|include
file|<QtCore/QString>
end_include
begin_include
include|#
directive|include
file|<QtCore/QHash>
end_include
begin_include
include|#
directive|include
file|<QtCore/QDebug>
end_include
begin_include
include|#
directive|include
file|<qpa/qwindowsysteminterface.h>
end_include
begin_class
DECL|class|tst_QGestureRecognizer
class|class
name|tst_QGestureRecognizer
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
public|public:
name|tst_QGestureRecognizer
parameter_list|()
constructor_decl|;
private|private
name|Q_SLOTS
private|:
name|void
name|initTestCase
parameter_list|()
function_decl|;
ifndef|#
directive|ifndef
name|QT_NO_GESTURES
name|void
name|panGesture_data
parameter_list|()
function_decl|;
name|void
name|panGesture
parameter_list|()
function_decl|;
name|void
name|pinchGesture_data
parameter_list|()
function_decl|;
name|void
name|pinchGesture
parameter_list|()
function_decl|;
name|void
name|swipeGesture_data
parameter_list|()
function_decl|;
name|void
name|swipeGesture
parameter_list|()
function_decl|;
endif|#
directive|endif
comment|// !QT_NO_GESTURES
private|private:
DECL|member|m_fingerDistance
specifier|const
name|int
name|m_fingerDistance
decl_stmt|;
DECL|member|m_touchDevice
name|QTouchDevice
modifier|*
name|m_touchDevice
decl_stmt|;
block|}
class|;
end_class
begin_constructor
DECL|function|tst_QGestureRecognizer
name|tst_QGestureRecognizer
operator|::
name|tst_QGestureRecognizer
parameter_list|()
member_init_list|:
name|m_fingerDistance
argument_list|(
name|qRound
argument_list|(
name|QGuiApplication
operator|::
name|primaryScreen
argument_list|()
operator|->
name|physicalDotsPerInch
argument_list|()
operator|/
literal|2.0
argument_list|)
argument_list|)
member_init_list|,
name|m_touchDevice
argument_list|(
operator|new
name|QTouchDevice
argument_list|)
block|{ }
end_constructor
begin_function
DECL|function|initTestCase
name|void
name|tst_QGestureRecognizer
operator|::
name|initTestCase
parameter_list|()
block|{
name|m_touchDevice
operator|->
name|setType
argument_list|(
name|QTouchDevice
operator|::
name|TouchScreen
argument_list|)
expr_stmt|;
name|QWindowSystemInterface
operator|::
name|registerTouchDevice
argument_list|(
name|m_touchDevice
argument_list|)
expr_stmt|;
block|}
end_function
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_GESTURES
end_ifndef
begin_typedef
DECL|typedef|GestureTypeVector
typedef|typedef
name|QVector
argument_list|<
name|Qt
operator|::
name|GestureType
argument_list|>
name|GestureTypeVector
typedef|;
end_typedef
begin_class
DECL|class|TestWidget
class|class
name|TestWidget
super|:
specifier|public
name|QWidget
block|{
public|public:
specifier|explicit
name|TestWidget
parameter_list|(
specifier|const
name|GestureTypeVector
modifier|&
name|gestureTypes
parameter_list|)
constructor_decl|;
DECL|function|gestureReceived
name|bool
name|gestureReceived
parameter_list|(
name|Qt
operator|::
name|GestureType
name|gestureType
parameter_list|)
specifier|const
block|{
return|return
name|m_receivedGestures
operator|.
name|value
argument_list|(
name|gestureType
argument_list|)
return|;
block|}
protected|protected:
DECL|member|Q_DECL_OVERRIDE
name|bool
name|event
parameter_list|(
name|QEvent
modifier|*
name|event
parameter_list|)
name|Q_DECL_OVERRIDE
function_decl|;
private|private:
DECL|typedef|GestureTypeHash
typedef|typedef
name|QHash
argument_list|<
name|Qt
operator|::
name|GestureType
argument_list|,
name|bool
argument_list|>
name|GestureTypeHash
typedef|;
DECL|member|m_receivedGestures
name|GestureTypeHash
name|m_receivedGestures
decl_stmt|;
block|}
class|;
end_class
begin_constructor
DECL|function|TestWidget
name|TestWidget
operator|::
name|TestWidget
parameter_list|(
specifier|const
name|GestureTypeVector
modifier|&
name|gestureTypes
parameter_list|)
block|{
name|setAttribute
argument_list|(
name|Qt
operator|::
name|WA_AcceptTouchEvents
argument_list|)
expr_stmt|;
foreach|foreach
control|(
name|Qt
operator|::
name|GestureType
name|gestureType
decl|,
name|gestureTypes
control|)
block|{
name|grabGesture
argument_list|(
name|gestureType
argument_list|)
expr_stmt|;
name|m_receivedGestures
operator|.
name|insert
argument_list|(
name|gestureType
argument_list|,
literal|false
argument_list|)
expr_stmt|;
block|}
specifier|const
name|QRect
name|geometry
init|=
name|QGuiApplication
operator|::
name|primaryScreen
argument_list|()
operator|->
name|availableGeometry
argument_list|()
decl_stmt|;
specifier|const
name|QSize
name|size
init|=
name|geometry
operator|.
name|size
argument_list|()
operator|/
literal|2
decl_stmt|;
name|resize
argument_list|(
name|size
argument_list|)
expr_stmt|;
name|move
argument_list|(
name|geometry
operator|.
name|center
argument_list|()
operator|-
name|QPoint
argument_list|(
name|size
operator|.
name|width
argument_list|()
operator|/
literal|2
argument_list|,
name|size
operator|.
name|height
argument_list|()
operator|/
literal|2
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_function
DECL|function|event
name|bool
name|TestWidget
operator|::
name|event
parameter_list|(
name|QEvent
modifier|*
name|event
parameter_list|)
block|{
switch|switch
condition|(
name|event
operator|->
name|type
argument_list|()
condition|)
block|{
case|case
name|QEvent
operator|::
name|Gesture
case|:
block|{
specifier|const
name|QGestureEvent
modifier|*
name|gestureEvent
init|=
cast|static_cast
argument_list|<
name|QGestureEvent
operator|*
argument_list|>
argument_list|(
name|event
argument_list|)
decl_stmt|;
specifier|const
name|GestureTypeHash
operator|::
name|iterator
name|hend
init|=
name|m_receivedGestures
operator|.
name|end
argument_list|()
decl_stmt|;
for|for
control|(
name|GestureTypeHash
operator|::
name|iterator
name|it
init|=
name|m_receivedGestures
operator|.
name|begin
argument_list|()
init|;
name|it
operator|!=
name|hend
condition|;
operator|++
name|it
control|)
block|{
if|if
condition|(
specifier|const
name|QGesture
modifier|*
name|gesture
init|=
name|gestureEvent
operator|->
name|gesture
argument_list|(
name|it
operator|.
name|key
argument_list|()
argument_list|)
condition|)
block|{
if|if
condition|(
name|gesture
operator|->
name|state
argument_list|()
operator|==
name|Qt
operator|::
name|GestureFinished
condition|)
name|it
operator|.
name|value
argument_list|()
operator|=
literal|true
expr_stmt|;
block|}
block|}
block|}
break|break;
default|default:
break|break;
block|}
return|return
name|QWidget
operator|::
name|event
argument_list|(
name|event
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|pressSequence
specifier|static
name|void
name|pressSequence
parameter_list|(
name|QTest
operator|::
name|QTouchEventSequence
modifier|&
name|sequence
parameter_list|,
name|QVector
argument_list|<
name|QPoint
argument_list|>
modifier|&
name|points
parameter_list|,
name|QWidget
modifier|*
name|widget
parameter_list|)
block|{
specifier|const
name|int
name|pointCount
init|=
name|points
operator|.
name|size
argument_list|()
decl_stmt|;
for|for
control|(
name|int
name|p
init|=
literal|0
init|;
name|p
operator|<
name|pointCount
condition|;
operator|++
name|p
control|)
name|sequence
operator|.
name|press
argument_list|(
name|p
argument_list|,
name|points
operator|.
name|at
argument_list|(
name|p
argument_list|)
argument_list|,
name|widget
argument_list|)
expr_stmt|;
name|sequence
operator|.
name|commit
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|linearSequence
specifier|static
name|void
name|linearSequence
parameter_list|(
name|int
name|n
parameter_list|,
specifier|const
name|QPoint
modifier|&
name|delta
parameter_list|,
name|QTest
operator|::
name|QTouchEventSequence
modifier|&
name|sequence
parameter_list|,
name|QVector
argument_list|<
name|QPoint
argument_list|>
modifier|&
name|points
parameter_list|,
name|QWidget
modifier|*
name|widget
parameter_list|)
block|{
specifier|const
name|int
name|pointCount
init|=
name|points
operator|.
name|size
argument_list|()
decl_stmt|;
for|for
control|(
name|int
name|s
init|=
literal|0
init|;
name|s
operator|<
name|n
condition|;
operator|++
name|s
control|)
block|{
for|for
control|(
name|int
name|p
init|=
literal|0
init|;
name|p
operator|<
name|pointCount
condition|;
operator|++
name|p
control|)
block|{
name|points
index|[
name|p
index|]
operator|+=
name|delta
expr_stmt|;
name|sequence
operator|.
name|move
argument_list|(
name|p
argument_list|,
name|points
index|[
name|p
index|]
argument_list|,
name|widget
argument_list|)
expr_stmt|;
block|}
name|sequence
operator|.
name|commit
argument_list|()
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|releaseSequence
specifier|static
name|void
name|releaseSequence
parameter_list|(
name|QTest
operator|::
name|QTouchEventSequence
modifier|&
name|sequence
parameter_list|,
name|QVector
argument_list|<
name|QPoint
argument_list|>
modifier|&
name|points
parameter_list|,
name|QWidget
modifier|*
name|widget
parameter_list|)
block|{
specifier|const
name|int
name|pointCount
init|=
name|points
operator|.
name|size
argument_list|()
decl_stmt|;
for|for
control|(
name|int
name|p
init|=
literal|0
init|;
name|p
operator|<
name|pointCount
condition|;
operator|++
name|p
control|)
name|sequence
operator|.
name|release
argument_list|(
name|p
argument_list|,
name|points
index|[
name|p
index|]
argument_list|,
name|widget
argument_list|)
expr_stmt|;
name|sequence
operator|.
name|commit
argument_list|()
expr_stmt|;
block|}
end_function
begin_comment
comment|// --- Pan
end_comment
begin_enum
DECL|enum|PanSubTest
enum|enum
name|PanSubTest
block|{
DECL|enumerator|TwoFingerPanSubTest
name|TwoFingerPanSubTest
block|}
enum|;
end_enum
begin_function
DECL|function|panGesture_data
name|void
name|tst_QGestureRecognizer
operator|::
name|panGesture_data
parameter_list|()
block|{
name|QTest
operator|::
name|addColumn
argument_list|<
name|int
argument_list|>
argument_list|(
literal|"panSubTest"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|bool
argument_list|>
argument_list|(
literal|"gestureExpected"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"Two finger"
argument_list|)
operator|<<
name|int
argument_list|(
name|TwoFingerPanSubTest
argument_list|)
operator|<<
literal|true
expr_stmt|;
block|}
end_function
begin_function
DECL|function|panGesture
name|void
name|tst_QGestureRecognizer
operator|::
name|panGesture
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|int
argument_list|,
name|panSubTest
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|bool
argument_list|,
name|gestureExpected
argument_list|)
expr_stmt|;
name|Q_UNUSED
argument_list|(
argument|panSubTest
argument_list|)
comment|// Single finger pan will be added later.
specifier|const
name|int
name|panPoints
init|=
literal|2
decl_stmt|;
specifier|const
name|Qt
operator|::
name|GestureType
name|gestureType
init|=
name|Qt
operator|::
name|PanGesture
decl_stmt|;
name|TestWidget
name|widget
argument_list|(
name|GestureTypeVector
argument_list|(
literal|1
argument_list|,
name|gestureType
argument_list|)
argument_list|)
decl_stmt|;
name|widget
operator|.
name|setWindowTitle
argument_list|(
name|QTest
operator|::
name|currentTestFunction
argument_list|()
argument_list|)
expr_stmt|;
name|widget
operator|.
name|show
argument_list|()
expr_stmt|;
name|QVERIFY
argument_list|(
name|QTest
operator|::
name|qWaitForWindowExposed
argument_list|(
operator|&
name|widget
argument_list|)
argument_list|)
expr_stmt|;
name|QVector
argument_list|<
name|QPoint
argument_list|>
name|points
decl_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|panPoints
condition|;
operator|++
name|i
control|)
name|points
operator|.
name|append
argument_list|(
name|QPoint
argument_list|(
literal|10
operator|+
name|i
operator|*
literal|20
argument_list|,
literal|10
operator|+
name|i
operator|*
literal|20
argument_list|)
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|QTouchEventSequence
name|panSequence
init|=
name|QTest
operator|::
name|touchEvent
argument_list|(
operator|&
name|widget
argument_list|,
name|m_touchDevice
argument_list|)
decl_stmt|;
name|pressSequence
argument_list|(
name|panSequence
argument_list|,
name|points
argument_list|,
operator|&
name|widget
argument_list|)
expr_stmt|;
name|linearSequence
argument_list|(
literal|5
argument_list|,
name|QPoint
argument_list|(
literal|20
argument_list|,
literal|20
argument_list|)
argument_list|,
name|panSequence
argument_list|,
name|points
argument_list|,
operator|&
name|widget
argument_list|)
expr_stmt|;
name|releaseSequence
argument_list|(
name|panSequence
argument_list|,
name|points
argument_list|,
operator|&
name|widget
argument_list|)
expr_stmt|;
if|if
condition|(
name|gestureExpected
condition|)
block|{
name|QTRY_VERIFY
argument_list|(
name|widget
operator|.
name|gestureReceived
argument_list|(
name|gestureType
argument_list|)
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|QCoreApplication
operator|::
name|processEvents
argument_list|()
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|widget
operator|.
name|gestureReceived
argument_list|(
name|gestureType
argument_list|)
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_comment
comment|// --- Pinch
end_comment
begin_enum
DECL|enum|PinchSubTest
enum|enum
name|PinchSubTest
block|{
DECL|enumerator|StandardPinchSubTest
name|StandardPinchSubTest
block|}
enum|;
end_enum
begin_function
DECL|function|pinchGesture_data
name|void
name|tst_QGestureRecognizer
operator|::
name|pinchGesture_data
parameter_list|()
block|{
name|QTest
operator|::
name|addColumn
argument_list|<
name|int
argument_list|>
argument_list|(
literal|"pinchSubTest"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|bool
argument_list|>
argument_list|(
literal|"gestureExpected"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"Standard"
argument_list|)
operator|<<
name|int
argument_list|(
name|StandardPinchSubTest
argument_list|)
operator|<<
literal|true
expr_stmt|;
block|}
end_function
begin_function
DECL|function|pinchGesture
name|void
name|tst_QGestureRecognizer
operator|::
name|pinchGesture
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|int
argument_list|,
name|pinchSubTest
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|bool
argument_list|,
name|gestureExpected
argument_list|)
expr_stmt|;
name|Q_UNUSED
argument_list|(
argument|pinchSubTest
argument_list|)
specifier|const
name|Qt
operator|::
name|GestureType
name|gestureType
init|=
name|Qt
operator|::
name|PinchGesture
decl_stmt|;
name|TestWidget
name|widget
argument_list|(
name|GestureTypeVector
argument_list|(
literal|1
argument_list|,
name|gestureType
argument_list|)
argument_list|)
decl_stmt|;
name|widget
operator|.
name|setWindowTitle
argument_list|(
name|QTest
operator|::
name|currentTestFunction
argument_list|()
argument_list|)
expr_stmt|;
name|widget
operator|.
name|show
argument_list|()
expr_stmt|;
name|QVERIFY
argument_list|(
name|QTest
operator|::
name|qWaitForWindowExposed
argument_list|(
operator|&
name|widget
argument_list|)
argument_list|)
expr_stmt|;
name|QVector
argument_list|<
name|QPoint
argument_list|>
name|points
decl_stmt|;
name|points
operator|.
name|append
argument_list|(
name|widget
operator|.
name|rect
argument_list|()
operator|.
name|center
argument_list|()
argument_list|)
expr_stmt|;
name|points
operator|.
name|append
argument_list|(
name|points
operator|.
name|front
argument_list|()
operator|+
name|QPoint
argument_list|(
literal|0
argument_list|,
literal|20
argument_list|)
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|QTouchEventSequence
name|pinchSequence
init|=
name|QTest
operator|::
name|touchEvent
argument_list|(
operator|&
name|widget
argument_list|,
name|m_touchDevice
argument_list|)
decl_stmt|;
name|pressSequence
argument_list|(
name|pinchSequence
argument_list|,
name|points
argument_list|,
operator|&
name|widget
argument_list|)
expr_stmt|;
for|for
control|(
name|int
name|s
init|=
literal|0
init|;
name|s
operator|<
literal|5
condition|;
operator|++
name|s
control|)
block|{
name|points
index|[
literal|0
index|]
operator|+=
name|QPoint
argument_list|(
literal|5
argument_list|,
literal|30
argument_list|)
expr_stmt|;
name|pinchSequence
operator|.
name|move
argument_list|(
literal|0
argument_list|,
name|points
index|[
literal|0
index|]
argument_list|,
operator|&
name|widget
argument_list|)
expr_stmt|;
name|points
index|[
literal|1
index|]
operator|+=
name|QPoint
argument_list|(
literal|5
argument_list|,
operator|-
literal|30
argument_list|)
expr_stmt|;
name|pinchSequence
operator|.
name|move
argument_list|(
literal|1
argument_list|,
name|points
index|[
literal|1
index|]
argument_list|,
operator|&
name|widget
argument_list|)
expr_stmt|;
name|pinchSequence
operator|.
name|commit
argument_list|()
expr_stmt|;
block|}
name|releaseSequence
argument_list|(
name|pinchSequence
argument_list|,
name|points
argument_list|,
operator|&
name|widget
argument_list|)
expr_stmt|;
if|if
condition|(
name|gestureExpected
condition|)
block|{
name|QTRY_VERIFY
argument_list|(
name|widget
operator|.
name|gestureReceived
argument_list|(
name|gestureType
argument_list|)
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|QCoreApplication
operator|::
name|processEvents
argument_list|()
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|widget
operator|.
name|gestureReceived
argument_list|(
name|gestureType
argument_list|)
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_comment
comment|// --- Swipe
end_comment
begin_enum
DECL|enum|SwipeSubTest
enum|enum
name|SwipeSubTest
block|{
DECL|enumerator|SwipeLineSubTest
name|SwipeLineSubTest
block|, }
enum|;
end_enum
begin_function
DECL|function|swipeGesture_data
name|void
name|tst_QGestureRecognizer
operator|::
name|swipeGesture_data
parameter_list|()
block|{
name|QTest
operator|::
name|addColumn
argument_list|<
name|int
argument_list|>
argument_list|(
literal|"swipeSubTest"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|bool
argument_list|>
argument_list|(
literal|"gestureExpected"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"Line"
argument_list|)
operator|<<
name|int
argument_list|(
name|SwipeLineSubTest
argument_list|)
operator|<<
literal|true
expr_stmt|;
block|}
end_function
begin_function
DECL|function|swipeGesture
name|void
name|tst_QGestureRecognizer
operator|::
name|swipeGesture
parameter_list|()
block|{
enum|enum
block|{
name|swipePoints
init|=
literal|3
block|}
enum|;
name|QFETCH
argument_list|(
name|int
argument_list|,
name|swipeSubTest
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|bool
argument_list|,
name|gestureExpected
argument_list|)
expr_stmt|;
specifier|const
name|Qt
operator|::
name|GestureType
name|gestureType
init|=
name|Qt
operator|::
name|SwipeGesture
decl_stmt|;
name|TestWidget
name|widget
argument_list|(
name|GestureTypeVector
argument_list|(
literal|1
argument_list|,
name|gestureType
argument_list|)
argument_list|)
decl_stmt|;
name|widget
operator|.
name|setWindowTitle
argument_list|(
name|QTest
operator|::
name|currentTestFunction
argument_list|()
argument_list|)
expr_stmt|;
name|widget
operator|.
name|show
argument_list|()
expr_stmt|;
name|QVERIFY
argument_list|(
name|QTest
operator|::
name|qWaitForWindowExposed
argument_list|(
operator|&
name|widget
argument_list|)
argument_list|)
expr_stmt|;
comment|// Start a swipe sequence with 2 points (QTBUG-15768)
specifier|const
name|QPoint
name|fingerDistance
argument_list|(
name|m_fingerDistance
argument_list|,
name|m_fingerDistance
argument_list|)
decl_stmt|;
name|QVector
argument_list|<
name|QPoint
argument_list|>
name|points
decl_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|swipePoints
operator|-
literal|1
condition|;
operator|++
name|i
control|)
name|points
operator|.
name|append
argument_list|(
name|fingerDistance
operator|+
name|i
operator|*
name|fingerDistance
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|QTouchEventSequence
name|swipeSequence
init|=
name|QTest
operator|::
name|touchEvent
argument_list|(
operator|&
name|widget
argument_list|,
name|m_touchDevice
argument_list|)
decl_stmt|;
name|pressSequence
argument_list|(
name|swipeSequence
argument_list|,
name|points
argument_list|,
operator|&
name|widget
argument_list|)
expr_stmt|;
comment|// Press point #3
name|points
operator|.
name|append
argument_list|(
name|points
operator|.
name|last
argument_list|()
operator|+
name|fingerDistance
argument_list|)
expr_stmt|;
name|swipeSequence
operator|.
name|press
argument_list|(
name|points
operator|.
name|size
argument_list|()
operator|-
literal|1
argument_list|,
name|points
operator|.
name|last
argument_list|()
argument_list|,
operator|&
name|widget
argument_list|)
expr_stmt|;
name|swipeSequence
operator|.
name|commit
argument_list|()
expr_stmt|;
name|Q_ASSERT
argument_list|(
name|points
operator|.
name|size
argument_list|()
operator|==
name|swipePoints
argument_list|)
expr_stmt|;
comment|// Move.
specifier|const
name|QPoint
name|moveDelta
argument_list|(
literal|60
argument_list|,
literal|20
argument_list|)
decl_stmt|;
switch|switch
condition|(
name|swipeSubTest
condition|)
block|{
case|case
name|SwipeLineSubTest
case|:
name|linearSequence
argument_list|(
literal|5
argument_list|,
name|moveDelta
argument_list|,
name|swipeSequence
argument_list|,
name|points
argument_list|,
operator|&
name|widget
argument_list|)
expr_stmt|;
break|break;
block|}
name|releaseSequence
argument_list|(
name|swipeSequence
argument_list|,
name|points
argument_list|,
operator|&
name|widget
argument_list|)
expr_stmt|;
if|if
condition|(
name|gestureExpected
condition|)
block|{
name|QTRY_VERIFY
argument_list|(
name|widget
operator|.
name|gestureReceived
argument_list|(
name|gestureType
argument_list|)
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|QCoreApplication
operator|::
name|processEvents
argument_list|()
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|widget
operator|.
name|gestureReceived
argument_list|(
name|gestureType
argument_list|)
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// !QT_NO_GESTURES
end_comment
begin_macro
name|QTEST_MAIN
argument_list|(
argument|tst_QGestureRecognizer
argument_list|)
end_macro
begin_include
include|#
directive|include
file|"tst_qgesturerecognizer.moc"
end_include
end_unit
