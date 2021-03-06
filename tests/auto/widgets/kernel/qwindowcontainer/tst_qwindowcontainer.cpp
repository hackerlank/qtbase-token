begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:GPL-EXCEPT$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3 as published by the Free Software ** Foundation with exceptions as appearing in the file LICENSE.GPL3-EXCEPT ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtTest/QtTest>
end_include
begin_include
include|#
directive|include
file|<qapplication.h>
end_include
begin_include
include|#
directive|include
file|<qwindow.h>
end_include
begin_include
include|#
directive|include
file|<qwidget.h>
end_include
begin_include
include|#
directive|include
file|<qdockwidget.h>
end_include
begin_include
include|#
directive|include
file|<qmainwindow.h>
end_include
begin_include
include|#
directive|include
file|<qscreen.h>
end_include
begin_include
include|#
directive|include
file|<qscopedpointer.h>
end_include
begin_class
DECL|class|Window
class|class
name|Window
super|:
specifier|public
name|QWindow
block|{
public|public:
DECL|function|Window
name|Window
parameter_list|()
member_init_list|:
name|numberOfExposes
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|numberOfObscures
argument_list|(
literal|0
argument_list|)
block|{     }
DECL|function|exposeEvent
name|void
name|exposeEvent
parameter_list|(
name|QExposeEvent
modifier|*
parameter_list|)
block|{
if|if
condition|(
name|isExposed
argument_list|()
condition|)
operator|++
name|numberOfExposes
expr_stmt|;
else|else
operator|++
name|numberOfObscures
expr_stmt|;
block|}
DECL|member|numberOfExposes
name|int
name|numberOfExposes
decl_stmt|;
DECL|member|numberOfObscures
name|int
name|numberOfObscures
decl_stmt|;
block|}
class|;
end_class
begin_class
DECL|class|tst_QWindowContainer
class|class
name|tst_QWindowContainer
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
public|public:
DECL|function|tst_QWindowContainer
name|tst_QWindowContainer
parameter_list|()
member_init_list|:
name|m_availableGeometry
argument_list|(
name|QGuiApplication
operator|::
name|primaryScreen
argument_list|()
operator|->
name|availableGeometry
argument_list|()
argument_list|)
block|{}
private|private
name|slots
private|:
name|void
name|testShow
parameter_list|()
function_decl|;
name|void
name|testPositionAndSize
parameter_list|()
function_decl|;
name|void
name|testExposeObscure
parameter_list|()
function_decl|;
name|void
name|testOwnership
parameter_list|()
function_decl|;
name|void
name|testBehindTheScenesDeletion
parameter_list|()
function_decl|;
name|void
name|testUnparenting
parameter_list|()
function_decl|;
name|void
name|testActivation
parameter_list|()
function_decl|;
name|void
name|testAncestorChange
parameter_list|()
function_decl|;
name|void
name|testDockWidget
parameter_list|()
function_decl|;
name|void
name|testNativeContainerParent
parameter_list|()
function_decl|;
name|void
name|cleanup
parameter_list|()
function_decl|;
private|private:
DECL|member|m_availableGeometry
specifier|const
name|QRect
name|m_availableGeometry
decl_stmt|;
block|}
class|;
end_class
begin_function
DECL|function|cleanup
name|void
name|tst_QWindowContainer
operator|::
name|cleanup
parameter_list|()
block|{
name|QVERIFY
argument_list|(
name|QGuiApplication
operator|::
name|topLevelWindows
argument_list|()
operator|.
name|isEmpty
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|testShow
name|void
name|tst_QWindowContainer
operator|::
name|testShow
parameter_list|()
block|{
name|QWidget
name|root
decl_stmt|;
name|root
operator|.
name|setWindowTitle
argument_list|(
name|QTest
operator|::
name|currentTestFunction
argument_list|()
argument_list|)
expr_stmt|;
name|root
operator|.
name|setGeometry
argument_list|(
name|m_availableGeometry
operator|.
name|x
argument_list|()
operator|+
literal|100
argument_list|,
name|m_availableGeometry
operator|.
name|y
argument_list|()
operator|+
literal|100
argument_list|,
literal|400
argument_list|,
literal|400
argument_list|)
expr_stmt|;
name|Window
modifier|*
name|window
init|=
operator|new
name|Window
argument_list|()
decl_stmt|;
name|QWidget
modifier|*
name|container
init|=
name|QWidget
operator|::
name|createWindowContainer
argument_list|(
name|window
argument_list|,
operator|&
name|root
argument_list|)
decl_stmt|;
name|container
operator|->
name|setGeometry
argument_list|(
literal|50
argument_list|,
literal|50
argument_list|,
literal|200
argument_list|,
literal|200
argument_list|)
expr_stmt|;
name|root
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
name|window
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|testPositionAndSize
name|void
name|tst_QWindowContainer
operator|::
name|testPositionAndSize
parameter_list|()
block|{
name|QWindow
modifier|*
name|window
init|=
operator|new
name|QWindow
argument_list|()
decl_stmt|;
name|window
operator|->
name|setGeometry
argument_list|(
name|m_availableGeometry
operator|.
name|x
argument_list|()
operator|+
literal|300
argument_list|,
name|m_availableGeometry
operator|.
name|y
argument_list|()
operator|+
literal|400
argument_list|,
literal|500
argument_list|,
literal|600
argument_list|)
expr_stmt|;
name|QScopedPointer
argument_list|<
name|QWidget
argument_list|>
name|container
argument_list|(
name|QWidget
operator|::
name|createWindowContainer
argument_list|(
name|window
argument_list|)
argument_list|)
decl_stmt|;
name|container
operator|->
name|setWindowTitle
argument_list|(
name|QTest
operator|::
name|currentTestFunction
argument_list|()
argument_list|)
expr_stmt|;
name|container
operator|->
name|setGeometry
argument_list|(
literal|50
argument_list|,
literal|50
argument_list|,
literal|200
argument_list|,
literal|200
argument_list|)
expr_stmt|;
name|container
operator|->
name|show
argument_list|()
expr_stmt|;
name|QVERIFY
argument_list|(
name|QTest
operator|::
name|qWaitForWindowExposed
argument_list|(
name|container
operator|.
name|data
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|window
operator|->
name|x
argument_list|()
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|window
operator|->
name|y
argument_list|()
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|window
operator|->
name|width
argument_list|()
argument_list|,
name|container
operator|->
name|width
argument_list|()
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|window
operator|->
name|height
argument_list|()
argument_list|,
name|container
operator|->
name|height
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|testExposeObscure
name|void
name|tst_QWindowContainer
operator|::
name|testExposeObscure
parameter_list|()
block|{
name|Window
modifier|*
name|window
init|=
operator|new
name|Window
argument_list|()
decl_stmt|;
name|QScopedPointer
argument_list|<
name|QWidget
argument_list|>
name|container
argument_list|(
name|QWidget
operator|::
name|createWindowContainer
argument_list|(
name|window
argument_list|)
argument_list|)
decl_stmt|;
name|container
operator|->
name|setWindowTitle
argument_list|(
name|QTest
operator|::
name|currentTestFunction
argument_list|()
argument_list|)
expr_stmt|;
name|container
operator|->
name|setGeometry
argument_list|(
name|m_availableGeometry
operator|.
name|x
argument_list|()
operator|+
literal|50
argument_list|,
name|m_availableGeometry
operator|.
name|y
argument_list|()
operator|+
literal|50
argument_list|,
literal|200
argument_list|,
literal|200
argument_list|)
expr_stmt|;
name|container
operator|->
name|show
argument_list|()
expr_stmt|;
name|QVERIFY
argument_list|(
name|QTest
operator|::
name|qWaitForWindowExposed
argument_list|(
name|container
operator|.
name|data
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|QTest
operator|::
name|qWaitForWindowExposed
argument_list|(
name|window
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|window
operator|->
name|numberOfExposes
operator|>
literal|0
argument_list|)
expr_stmt|;
name|container
operator|->
name|hide
argument_list|()
expr_stmt|;
name|QElapsedTimer
name|timer
decl_stmt|;
name|timer
operator|.
name|start
argument_list|()
expr_stmt|;
while|while
condition|(
name|window
operator|->
name|numberOfObscures
operator|==
literal|0
operator|&&
name|timer
operator|.
name|elapsed
argument_list|()
operator|<
literal|5000
condition|)
block|{
name|QTest
operator|::
name|qWait
argument_list|(
literal|10
argument_list|)
expr_stmt|;
block|}
name|QVERIFY
argument_list|(
name|window
operator|->
name|numberOfObscures
operator|>
literal|0
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|testOwnership
name|void
name|tst_QWindowContainer
operator|::
name|testOwnership
parameter_list|()
block|{
name|QPointer
argument_list|<
name|QWindow
argument_list|>
name|window
argument_list|(
operator|new
name|QWindow
argument_list|()
argument_list|)
decl_stmt|;
name|QWidget
modifier|*
name|container
init|=
name|QWidget
operator|::
name|createWindowContainer
argument_list|(
name|window
argument_list|)
decl_stmt|;
operator|delete
name|container
expr_stmt|;
name|QCOMPARE
argument_list|(
name|window
operator|.
name|data
argument_list|()
argument_list|,
operator|(
name|QWindow
operator|*
operator|)
literal|0
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|testBehindTheScenesDeletion
name|void
name|tst_QWindowContainer
operator|::
name|testBehindTheScenesDeletion
parameter_list|()
block|{
name|QWindow
modifier|*
name|window
init|=
operator|new
name|QWindow
argument_list|()
decl_stmt|;
name|QWidget
modifier|*
name|container
init|=
name|QWidget
operator|::
name|createWindowContainer
argument_list|(
name|window
argument_list|)
decl_stmt|;
operator|delete
name|window
expr_stmt|;
comment|// The child got removed, showing not should not have any side effects,
comment|// such as for instance, crashing...
name|container
operator|->
name|show
argument_list|()
expr_stmt|;
name|QVERIFY
argument_list|(
name|QTest
operator|::
name|qWaitForWindowExposed
argument_list|(
name|container
argument_list|)
argument_list|)
expr_stmt|;
operator|delete
name|container
expr_stmt|;
block|}
end_function
begin_function
DECL|function|testActivation
name|void
name|tst_QWindowContainer
operator|::
name|testActivation
parameter_list|()
block|{
name|QWidget
name|root
decl_stmt|;
name|root
operator|.
name|setWindowTitle
argument_list|(
name|QTest
operator|::
name|currentTestFunction
argument_list|()
argument_list|)
expr_stmt|;
name|QWindow
modifier|*
name|window
init|=
operator|new
name|QWindow
argument_list|()
decl_stmt|;
name|QWidget
modifier|*
name|container
init|=
name|QWidget
operator|::
name|createWindowContainer
argument_list|(
name|window
argument_list|,
operator|&
name|root
argument_list|)
decl_stmt|;
name|container
operator|->
name|setGeometry
argument_list|(
literal|100
argument_list|,
literal|100
argument_list|,
literal|200
argument_list|,
literal|100
argument_list|)
expr_stmt|;
name|root
operator|.
name|setGeometry
argument_list|(
name|m_availableGeometry
operator|.
name|x
argument_list|()
operator|+
literal|100
argument_list|,
name|m_availableGeometry
operator|.
name|y
argument_list|()
operator|+
literal|100
argument_list|,
literal|400
argument_list|,
literal|300
argument_list|)
expr_stmt|;
name|root
operator|.
name|show
argument_list|()
expr_stmt|;
name|root
operator|.
name|activateWindow
argument_list|()
expr_stmt|;
name|QVERIFY
argument_list|(
name|QTest
operator|::
name|qWaitForWindowExposed
argument_list|(
operator|&
name|root
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|QTest
operator|::
name|qWaitForWindowActive
argument_list|(
name|root
operator|.
name|windowHandle
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|QGuiApplication
operator|::
name|focusWindow
argument_list|()
argument_list|,
name|root
operator|.
name|windowHandle
argument_list|()
argument_list|)
expr_stmt|;
comment|// Verify that all states in the root widget indicate it is active
name|QVERIFY
argument_list|(
name|root
operator|.
name|windowHandle
argument_list|()
operator|->
name|isActive
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|root
operator|.
name|isActiveWindow
argument_list|()
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|root
operator|.
name|palette
argument_list|()
operator|.
name|currentColorGroup
argument_list|()
argument_list|,
name|QPalette
operator|::
name|Active
argument_list|)
expr_stmt|;
comment|// Under KDE (ubuntu 12.10), we experience that doing two activateWindow in a row
comment|// does not work. The second gets ignored by the window manager, even though the
comment|// timestamp in the xcb connection is unique for both.
if|if
condition|(
operator|!
name|QGuiApplication
operator|::
name|platformName
argument_list|()
operator|.
name|compare
argument_list|(
name|QLatin1String
argument_list|(
literal|"xcb"
argument_list|)
argument_list|,
name|Qt
operator|::
name|CaseInsensitive
argument_list|)
condition|)
name|QTest
operator|::
name|qWait
argument_list|(
literal|100
argument_list|)
expr_stmt|;
name|window
operator|->
name|requestActivate
argument_list|()
expr_stmt|;
name|QTRY_COMPARE
argument_list|(
name|QGuiApplication
operator|::
name|focusWindow
argument_list|()
argument_list|,
name|window
argument_list|)
expr_stmt|;
comment|// Verify that all states in the root widget still indicate it is active
name|QVERIFY
argument_list|(
name|root
operator|.
name|windowHandle
argument_list|()
operator|->
name|isActive
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|root
operator|.
name|isActiveWindow
argument_list|()
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|root
operator|.
name|palette
argument_list|()
operator|.
name|currentColorGroup
argument_list|()
argument_list|,
name|QPalette
operator|::
name|Active
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|testUnparenting
name|void
name|tst_QWindowContainer
operator|::
name|testUnparenting
parameter_list|()
block|{
name|QWindow
modifier|*
name|window
init|=
operator|new
name|QWindow
argument_list|()
decl_stmt|;
name|QScopedPointer
argument_list|<
name|QWidget
argument_list|>
name|container
argument_list|(
name|QWidget
operator|::
name|createWindowContainer
argument_list|(
name|window
argument_list|)
argument_list|)
decl_stmt|;
name|container
operator|->
name|setWindowTitle
argument_list|(
name|QTest
operator|::
name|currentTestFunction
argument_list|()
argument_list|)
expr_stmt|;
name|container
operator|->
name|setGeometry
argument_list|(
name|m_availableGeometry
operator|.
name|x
argument_list|()
operator|+
literal|100
argument_list|,
name|m_availableGeometry
operator|.
name|y
argument_list|()
operator|+
literal|100
argument_list|,
literal|200
argument_list|,
literal|100
argument_list|)
expr_stmt|;
name|window
operator|->
name|setParent
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|container
operator|->
name|show
argument_list|()
expr_stmt|;
name|QVERIFY
argument_list|(
name|QTest
operator|::
name|qWaitForWindowExposed
argument_list|(
name|container
operator|.
name|data
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
comment|// Window should not be made visible by container..
name|QVERIFY
argument_list|(
operator|!
name|window
operator|->
name|isVisible
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|testAncestorChange
name|void
name|tst_QWindowContainer
operator|::
name|testAncestorChange
parameter_list|()
block|{
name|QWidget
name|root
decl_stmt|;
name|root
operator|.
name|setWindowTitle
argument_list|(
name|QStringLiteral
argument_list|(
literal|"Root "
argument_list|)
operator|+
name|QTest
operator|::
name|currentTestFunction
argument_list|()
argument_list|)
expr_stmt|;
name|QWidget
modifier|*
name|left
init|=
operator|new
name|QWidget
argument_list|(
operator|&
name|root
argument_list|)
decl_stmt|;
name|QWidget
modifier|*
name|right
init|=
operator|new
name|QWidget
argument_list|(
operator|&
name|root
argument_list|)
decl_stmt|;
name|root
operator|.
name|setGeometry
argument_list|(
name|m_availableGeometry
operator|.
name|x
argument_list|()
operator|+
literal|50
argument_list|,
name|m_availableGeometry
operator|.
name|y
argument_list|()
operator|+
literal|50
argument_list|,
literal|200
argument_list|,
literal|100
argument_list|)
expr_stmt|;
name|left
operator|->
name|setGeometry
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|100
argument_list|,
literal|100
argument_list|)
expr_stmt|;
name|right
operator|->
name|setGeometry
argument_list|(
literal|100
argument_list|,
literal|0
argument_list|,
literal|100
argument_list|,
literal|100
argument_list|)
expr_stmt|;
name|QWindow
modifier|*
name|window
init|=
operator|new
name|QWindow
argument_list|()
decl_stmt|;
name|QWidget
modifier|*
name|container
init|=
name|QWidget
operator|::
name|createWindowContainer
argument_list|(
name|window
argument_list|,
name|left
argument_list|)
decl_stmt|;
name|container
operator|->
name|setGeometry
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|100
argument_list|,
literal|100
argument_list|)
expr_stmt|;
comment|//      Root
comment|//      + left
comment|//      | + container
comment|//      |   + window
comment|//      + right
name|root
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
name|root
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|window
operator|->
name|geometry
argument_list|()
argument_list|,
name|QRect
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|100
argument_list|,
literal|100
argument_list|)
argument_list|)
expr_stmt|;
name|container
operator|->
name|setParent
argument_list|(
name|right
argument_list|)
expr_stmt|;
comment|//      Root
comment|//      + left
comment|//      + right
comment|//        + container
comment|//          + window
name|QCOMPARE
argument_list|(
name|window
operator|->
name|geometry
argument_list|()
argument_list|,
name|QRect
argument_list|(
literal|100
argument_list|,
literal|0
argument_list|,
literal|100
argument_list|,
literal|100
argument_list|)
argument_list|)
expr_stmt|;
name|QWidget
modifier|*
name|newRoot
init|=
operator|new
name|QWidget
argument_list|(
operator|&
name|root
argument_list|)
decl_stmt|;
name|newRoot
operator|->
name|setWindowTitle
argument_list|(
name|QStringLiteral
argument_list|(
literal|"newRoot "
argument_list|)
operator|+
name|QTest
operator|::
name|currentTestFunction
argument_list|()
argument_list|)
expr_stmt|;
name|newRoot
operator|->
name|setGeometry
argument_list|(
literal|50
argument_list|,
literal|50
argument_list|,
literal|200
argument_list|,
literal|200
argument_list|)
expr_stmt|;
name|right
operator|->
name|setParent
argument_list|(
name|newRoot
argument_list|)
expr_stmt|;
comment|//      Root
comment|//      + left
comment|//      + newRoot
comment|//        + right
comment|//          + container
comment|//            + window
name|QCOMPARE
argument_list|(
name|window
operator|->
name|geometry
argument_list|()
argument_list|,
name|QRect
argument_list|(
literal|150
argument_list|,
literal|50
argument_list|,
literal|100
argument_list|,
literal|100
argument_list|)
argument_list|)
expr_stmt|;
name|newRoot
operator|->
name|move
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|window
operator|->
name|geometry
argument_list|()
argument_list|,
name|QRect
argument_list|(
literal|100
argument_list|,
literal|0
argument_list|,
literal|100
argument_list|,
literal|100
argument_list|)
argument_list|)
expr_stmt|;
name|newRoot
operator|->
name|setParent
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|QScopedPointer
argument_list|<
name|QWidget
argument_list|>
name|newRootGuard
argument_list|(
name|newRoot
argument_list|)
decl_stmt|;
name|newRoot
operator|->
name|setGeometry
argument_list|(
name|m_availableGeometry
operator|.
name|x
argument_list|()
operator|+
literal|100
argument_list|,
name|m_availableGeometry
operator|.
name|y
argument_list|()
operator|+
literal|100
argument_list|,
literal|200
argument_list|,
literal|200
argument_list|)
expr_stmt|;
name|newRoot
operator|->
name|show
argument_list|()
expr_stmt|;
name|QVERIFY
argument_list|(
name|QTest
operator|::
name|qWaitForWindowExposed
argument_list|(
name|newRoot
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|newRoot
operator|->
name|windowHandle
argument_list|()
argument_list|,
name|window
operator|->
name|parent
argument_list|()
argument_list|)
expr_stmt|;
comment|//      newRoot
comment|//      + right
comment|//        + container
comment|//          + window
name|QCOMPARE
argument_list|(
name|window
operator|->
name|geometry
argument_list|()
argument_list|,
name|QRect
argument_list|(
literal|100
argument_list|,
literal|0
argument_list|,
literal|100
argument_list|,
literal|100
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|testDockWidget
name|void
name|tst_QWindowContainer
operator|::
name|testDockWidget
parameter_list|()
block|{
name|QMainWindow
name|mainWindow
decl_stmt|;
name|mainWindow
operator|.
name|setWindowTitle
argument_list|(
name|QTest
operator|::
name|currentTestFunction
argument_list|()
argument_list|)
expr_stmt|;
name|mainWindow
operator|.
name|resize
argument_list|(
literal|200
argument_list|,
literal|200
argument_list|)
expr_stmt|;
name|mainWindow
operator|.
name|move
argument_list|(
name|m_availableGeometry
operator|.
name|center
argument_list|()
operator|-
name|QPoint
argument_list|(
literal|100
argument_list|,
literal|100
argument_list|)
argument_list|)
expr_stmt|;
name|QDockWidget
modifier|*
name|dock
init|=
operator|new
name|QDockWidget
argument_list|(
name|QStringLiteral
argument_list|(
literal|"Dock "
argument_list|)
operator|+
name|QTest
operator|::
name|currentTestFunction
argument_list|()
argument_list|)
decl_stmt|;
name|QWindow
modifier|*
name|window
init|=
operator|new
name|QWindow
argument_list|()
decl_stmt|;
name|QWidget
modifier|*
name|container
init|=
name|QWidget
operator|::
name|createWindowContainer
argument_list|(
name|window
argument_list|)
decl_stmt|;
name|dock
operator|->
name|setWidget
argument_list|(
name|container
argument_list|)
expr_stmt|;
name|mainWindow
operator|.
name|addDockWidget
argument_list|(
name|Qt
operator|::
name|RightDockWidgetArea
argument_list|,
name|dock
argument_list|)
expr_stmt|;
name|mainWindow
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
name|mainWindow
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|window
operator|->
name|parent
argument_list|()
argument_list|,
name|mainWindow
operator|.
name|window
argument_list|()
operator|->
name|windowHandle
argument_list|()
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|qWait
argument_list|(
literal|1000
argument_list|)
expr_stmt|;
name|dock
operator|->
name|setFloating
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|QTRY_VERIFY
argument_list|(
name|window
operator|->
name|parent
argument_list|()
operator|!=
name|mainWindow
operator|.
name|window
argument_list|()
operator|->
name|windowHandle
argument_list|()
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|qWait
argument_list|(
literal|1000
argument_list|)
expr_stmt|;
name|dock
operator|->
name|setFloating
argument_list|(
literal|false
argument_list|)
expr_stmt|;
name|QTRY_COMPARE
argument_list|(
name|window
operator|->
name|parent
argument_list|()
argument_list|,
name|mainWindow
operator|.
name|window
argument_list|()
operator|->
name|windowHandle
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|testNativeContainerParent
name|void
name|tst_QWindowContainer
operator|::
name|testNativeContainerParent
parameter_list|()
block|{
name|QWidget
name|root
decl_stmt|;
name|root
operator|.
name|setWindowTitle
argument_list|(
name|QTest
operator|::
name|currentTestFunction
argument_list|()
argument_list|)
expr_stmt|;
name|root
operator|.
name|setGeometry
argument_list|(
name|m_availableGeometry
operator|.
name|x
argument_list|()
operator|+
literal|50
argument_list|,
name|m_availableGeometry
operator|.
name|y
argument_list|()
operator|+
literal|50
argument_list|,
literal|200
argument_list|,
literal|200
argument_list|)
expr_stmt|;
name|Window
modifier|*
name|window
init|=
operator|new
name|Window
argument_list|()
decl_stmt|;
name|QWidget
modifier|*
name|container
init|=
name|QWidget
operator|::
name|createWindowContainer
argument_list|(
name|window
argument_list|,
operator|&
name|root
argument_list|)
decl_stmt|;
name|container
operator|->
name|setAttribute
argument_list|(
name|Qt
operator|::
name|WA_NativeWindow
argument_list|)
expr_stmt|;
name|container
operator|->
name|setGeometry
argument_list|(
literal|50
argument_list|,
literal|50
argument_list|,
literal|150
argument_list|,
literal|150
argument_list|)
expr_stmt|;
name|root
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
name|window
argument_list|)
argument_list|)
expr_stmt|;
name|QTRY_COMPARE
argument_list|(
name|window
operator|->
name|parent
argument_list|()
argument_list|,
name|container
operator|->
name|windowHandle
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_macro
name|QTEST_MAIN
argument_list|(
argument|tst_QWindowContainer
argument_list|)
end_macro
begin_include
include|#
directive|include
file|"tst_qwindowcontainer.moc"
end_include
end_unit
