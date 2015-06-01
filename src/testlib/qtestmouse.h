begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the QtTest module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QTESTMOUSE_H
end_ifndef
begin_define
DECL|macro|QTESTMOUSE_H
define|#
directive|define
name|QTESTMOUSE_H
end_define
begin_if
if|#
directive|if
literal|0
end_if
begin_comment
comment|// inform syncqt
end_comment
begin_pragma
pragma|#
directive|pragma
name|qt_no_master_include
end_pragma
begin_endif
endif|#
directive|endif
end_endif
begin_include
include|#
directive|include
file|<QtTest/qtest_global.h>
end_include
begin_include
include|#
directive|include
file|<QtTest/qtestassert.h>
end_include
begin_include
include|#
directive|include
file|<QtTest/qtestsystem.h>
end_include
begin_include
include|#
directive|include
file|<QtTest/qtestspontaneevent.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qpoint.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qstring.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qpointer.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/qevent.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/qwindow.h>
end_include
begin_ifdef
ifdef|#
directive|ifdef
name|QT_WIDGETS_LIB
end_ifdef
begin_include
include|#
directive|include
file|<QtWidgets/qapplication.h>
end_include
begin_include
include|#
directive|include
file|<QtWidgets/qwidget.h>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_include
include|#
directive|include
file|<QtCore/QDebug>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
name|Q_GUI_EXPORT
name|void
name|qt_handleMouseEvent
argument_list|(
name|QWindow
operator|*
name|w
argument_list|,
specifier|const
name|QPointF
operator|&
name|local
argument_list|,
specifier|const
name|QPointF
operator|&
name|global
argument_list|,
name|Qt
operator|::
name|MouseButtons
name|b
argument_list|,
name|Qt
operator|::
name|KeyboardModifiers
name|mods
argument_list|,
name|int
name|timestamp
argument_list|)
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|namespace
name|QTest
block|{
enum|enum
name|MouseAction
block|{
name|MousePress
block|,
name|MouseRelease
block|,
name|MouseClick
block|,
name|MouseDClick
block|,
name|MouseMove
block|}
enum|;
extern|extern Q_TESTLIB_EXPORT Qt::MouseButton lastMouseButton;
specifier|extern
name|Q_TESTLIB_EXPORT
name|int
name|lastMouseTimestamp
decl_stmt|;
specifier|static
name|void
name|waitForEvents
parameter_list|()
block|{
ifdef|#
directive|ifdef
name|Q_OS_MAC
name|QTest
operator|::
name|qWait
argument_list|(
literal|20
argument_list|)
expr_stmt|;
else|#
directive|else
name|qApp
operator|->
name|processEvents
argument_list|()
expr_stmt|;
endif|#
directive|endif
block|}
specifier|static
name|void
name|mouseEvent
argument_list|(
name|MouseAction
name|action
argument_list|,
name|QWindow
operator|*
name|window
argument_list|,
name|Qt
operator|::
name|MouseButton
name|button
argument_list|,
name|Qt
operator|::
name|KeyboardModifiers
name|stateKey
argument_list|,
name|QPoint
name|pos
argument_list|,
name|int
name|delay
operator|=
operator|-
literal|1
argument_list|)
block|{
name|QTEST_ASSERT
argument_list|(
name|window
argument_list|)
expr_stmt|;
specifier|extern
name|int
name|Q_TESTLIB_EXPORT
name|defaultMouseDelay
parameter_list|()
function_decl|;
comment|// pos is in window local coordinates
if|if
condition|(
name|window
operator|->
name|geometry
argument_list|()
operator|.
name|width
argument_list|()
operator|<=
name|pos
operator|.
name|x
argument_list|()
operator|||
name|window
operator|->
name|geometry
argument_list|()
operator|.
name|height
argument_list|()
operator|<=
name|pos
operator|.
name|y
argument_list|()
condition|)
block|{
name|QTest
operator|::
name|qWarn
argument_list|(
literal|"Mouse event occurs outside of target window."
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|delay
operator|==
operator|-
literal|1
operator|||
name|delay
operator|<
name|defaultMouseDelay
argument_list|()
condition|)
name|delay
operator|=
name|defaultMouseDelay
argument_list|()
expr_stmt|;
if|if
condition|(
name|delay
operator|>
literal|0
condition|)
name|QTest
operator|::
name|qWait
argument_list|(
name|delay
argument_list|)
expr_stmt|;
if|if
condition|(
name|pos
operator|.
name|isNull
argument_list|()
condition|)
name|pos
operator|=
name|window
operator|->
name|geometry
argument_list|()
operator|.
name|center
argument_list|()
expr_stmt|;
name|QTEST_ASSERT
argument_list|(
name|uint
argument_list|(
name|stateKey
argument_list|)
operator|==
literal|0
operator|||
name|stateKey
operator|&
name|Qt
operator|::
name|KeyboardModifierMask
argument_list|)
expr_stmt|;
name|stateKey
operator|&=
name|static_cast
operator|<
name|unsigned
name|int
operator|>
operator|(
name|Qt
operator|::
name|KeyboardModifierMask
operator|)
expr_stmt|;
name|QPointF
name|global
init|=
name|window
operator|->
name|mapToGlobal
argument_list|(
name|pos
argument_list|)
decl_stmt|;
name|QPointer
operator|<
name|QWindow
operator|>
name|w
argument_list|(
name|window
argument_list|)
expr_stmt|;
switch|switch
condition|(
name|action
condition|)
block|{
case|case
name|MouseDClick
case|:
name|qt_handleMouseEvent
argument_list|(
name|w
argument_list|,
name|pos
argument_list|,
name|global
argument_list|,
name|button
argument_list|,
name|stateKey
argument_list|,
name|lastMouseTimestamp
argument_list|)
expr_stmt|;
name|qt_handleMouseEvent
argument_list|(
name|w
argument_list|,
name|pos
argument_list|,
name|global
argument_list|,
name|Qt
operator|::
name|NoButton
argument_list|,
name|stateKey
argument_list|,
operator|++
name|lastMouseTimestamp
argument_list|)
expr_stmt|;
comment|// fall through
case|case
name|MousePress
case|:
case|case
name|MouseClick
case|:
name|qt_handleMouseEvent
argument_list|(
name|w
argument_list|,
name|pos
argument_list|,
name|global
argument_list|,
name|button
argument_list|,
name|stateKey
argument_list|,
operator|++
name|lastMouseTimestamp
argument_list|)
expr_stmt|;
name|lastMouseButton
operator|=
name|button
expr_stmt|;
if|if
condition|(
name|action
operator|==
name|MousePress
condition|)
break|break;
comment|// fall through
case|case
name|MouseRelease
case|:
name|qt_handleMouseEvent
argument_list|(
name|w
argument_list|,
name|pos
argument_list|,
name|global
argument_list|,
name|Qt
operator|::
name|NoButton
argument_list|,
name|stateKey
argument_list|,
operator|++
name|lastMouseTimestamp
argument_list|)
expr_stmt|;
name|lastMouseTimestamp
operator|+=
literal|500
expr_stmt|;
comment|// avoid double clicks being generated
name|lastMouseButton
operator|=
name|Qt
operator|::
name|NoButton
expr_stmt|;
break|break;
case|case
name|MouseMove
case|:
name|qt_handleMouseEvent
argument_list|(
name|w
argument_list|,
name|pos
argument_list|,
name|global
argument_list|,
name|lastMouseButton
argument_list|,
name|stateKey
argument_list|,
operator|++
name|lastMouseTimestamp
argument_list|)
expr_stmt|;
comment|// No QCursor::setPos() call here. That could potentially result in mouse events sent by the windowing system
comment|// which is highly undesired here. Tests must avoid relying on QCursor.
break|break;
default|default:
name|QTEST_ASSERT
argument_list|(
name|false
argument_list|)
expr_stmt|;
block|}
name|waitForEvents
argument_list|()
expr_stmt|;
block|}
specifier|inline
name|void
name|mousePress
argument_list|(
name|QWindow
operator|*
name|window
argument_list|,
name|Qt
operator|::
name|MouseButton
name|button
argument_list|,
name|Qt
operator|::
name|KeyboardModifiers
name|stateKey
operator|=
literal|0
argument_list|,
name|QPoint
name|pos
operator|=
name|QPoint
argument_list|()
argument_list|,
name|int
name|delay
operator|=
operator|-
literal|1
argument_list|)
block|{
name|mouseEvent
argument_list|(
name|MousePress
argument_list|,
name|window
argument_list|,
name|button
argument_list|,
name|stateKey
argument_list|,
name|pos
argument_list|,
name|delay
argument_list|)
expr_stmt|;
block|}
specifier|inline
name|void
name|mouseRelease
argument_list|(
name|QWindow
operator|*
name|window
argument_list|,
name|Qt
operator|::
name|MouseButton
name|button
argument_list|,
name|Qt
operator|::
name|KeyboardModifiers
name|stateKey
operator|=
literal|0
argument_list|,
name|QPoint
name|pos
operator|=
name|QPoint
argument_list|()
argument_list|,
name|int
name|delay
operator|=
operator|-
literal|1
argument_list|)
block|{
name|mouseEvent
argument_list|(
name|MouseRelease
argument_list|,
name|window
argument_list|,
name|button
argument_list|,
name|stateKey
argument_list|,
name|pos
argument_list|,
name|delay
argument_list|)
expr_stmt|;
block|}
specifier|inline
name|void
name|mouseClick
argument_list|(
name|QWindow
operator|*
name|window
argument_list|,
name|Qt
operator|::
name|MouseButton
name|button
argument_list|,
name|Qt
operator|::
name|KeyboardModifiers
name|stateKey
operator|=
literal|0
argument_list|,
name|QPoint
name|pos
operator|=
name|QPoint
argument_list|()
argument_list|,
name|int
name|delay
operator|=
operator|-
literal|1
argument_list|)
block|{
name|mouseEvent
argument_list|(
name|MouseClick
argument_list|,
name|window
argument_list|,
name|button
argument_list|,
name|stateKey
argument_list|,
name|pos
argument_list|,
name|delay
argument_list|)
expr_stmt|;
block|}
specifier|inline
name|void
name|mouseDClick
argument_list|(
name|QWindow
operator|*
name|window
argument_list|,
name|Qt
operator|::
name|MouseButton
name|button
argument_list|,
name|Qt
operator|::
name|KeyboardModifiers
name|stateKey
operator|=
literal|0
argument_list|,
name|QPoint
name|pos
operator|=
name|QPoint
argument_list|()
argument_list|,
name|int
name|delay
operator|=
operator|-
literal|1
argument_list|)
block|{
name|mouseEvent
argument_list|(
name|MouseDClick
argument_list|,
name|window
argument_list|,
name|button
argument_list|,
name|stateKey
argument_list|,
name|pos
argument_list|,
name|delay
argument_list|)
expr_stmt|;
block|}
specifier|inline
name|void
name|mouseMove
parameter_list|(
name|QWindow
modifier|*
name|window
parameter_list|,
name|QPoint
name|pos
init|=
name|QPoint
argument_list|()
parameter_list|,
name|int
name|delay
init|=
operator|-
literal|1
parameter_list|)
block|{
name|mouseEvent
argument_list|(
name|MouseMove
argument_list|,
name|window
argument_list|,
name|Qt
operator|::
name|NoButton
argument_list|,
literal|0
argument_list|,
name|pos
argument_list|,
name|delay
argument_list|)
expr_stmt|;
block|}
ifdef|#
directive|ifdef
name|QT_WIDGETS_LIB
specifier|static
name|void
name|mouseEvent
argument_list|(
name|MouseAction
name|action
argument_list|,
name|QWidget
operator|*
name|widget
argument_list|,
name|Qt
operator|::
name|MouseButton
name|button
argument_list|,
name|Qt
operator|::
name|KeyboardModifiers
name|stateKey
argument_list|,
name|QPoint
name|pos
argument_list|,
name|int
name|delay
operator|=
operator|-
literal|1
argument_list|)
block|{
name|QTEST_ASSERT
argument_list|(
name|widget
argument_list|)
expr_stmt|;
if|if
condition|(
name|pos
operator|.
name|isNull
argument_list|()
condition|)
name|pos
operator|=
name|widget
operator|->
name|rect
argument_list|()
operator|.
name|center
argument_list|()
expr_stmt|;
ifdef|#
directive|ifdef
name|QTEST_QPA_MOUSE_HANDLING
name|QWindow
modifier|*
name|w
init|=
name|widget
operator|->
name|window
argument_list|()
operator|->
name|windowHandle
argument_list|()
decl_stmt|;
name|QTEST_ASSERT
argument_list|(
name|w
argument_list|)
expr_stmt|;
name|mouseEvent
argument_list|(
name|action
argument_list|,
name|w
argument_list|,
name|button
argument_list|,
name|stateKey
argument_list|,
name|w
operator|->
name|mapFromGlobal
argument_list|(
name|widget
operator|->
name|mapToGlobal
argument_list|(
name|pos
argument_list|)
argument_list|)
argument_list|,
name|delay
argument_list|)
expr_stmt|;
else|#
directive|else
specifier|extern
name|int
name|Q_TESTLIB_EXPORT
name|defaultMouseDelay
parameter_list|()
function_decl|;
if|if
condition|(
name|delay
operator|==
operator|-
literal|1
operator|||
name|delay
operator|<
name|defaultMouseDelay
argument_list|()
condition|)
name|delay
operator|=
name|defaultMouseDelay
argument_list|()
expr_stmt|;
if|if
condition|(
name|delay
operator|>
literal|0
condition|)
name|QTest
operator|::
name|qWait
argument_list|(
name|delay
argument_list|)
expr_stmt|;
if|if
condition|(
name|action
operator|==
name|MouseClick
condition|)
block|{
name|mouseEvent
argument_list|(
name|MousePress
argument_list|,
name|widget
argument_list|,
name|button
argument_list|,
name|stateKey
argument_list|,
name|pos
argument_list|)
expr_stmt|;
name|mouseEvent
argument_list|(
name|MouseRelease
argument_list|,
name|widget
argument_list|,
name|button
argument_list|,
name|stateKey
argument_list|,
name|pos
argument_list|)
expr_stmt|;
return|return;
block|}
name|QTEST_ASSERT
argument_list|(
name|stateKey
operator|==
literal|0
operator|||
name|stateKey
operator|&
name|Qt
operator|::
name|KeyboardModifierMask
argument_list|)
expr_stmt|;
name|stateKey
operator|&=
name|static_cast
operator|<
name|unsigned
name|int
operator|>
operator|(
name|Qt
operator|::
name|KeyboardModifierMask
operator|)
expr_stmt|;
name|QMouseEvent
name|me
argument_list|(
name|QEvent
operator|::
name|User
argument_list|,
name|QPoint
argument_list|()
argument_list|,
name|Qt
operator|::
name|LeftButton
argument_list|,
name|button
argument_list|,
name|stateKey
argument_list|)
decl_stmt|;
switch|switch
condition|(
name|action
condition|)
block|{
case|case
name|MousePress
case|:
name|me
operator|=
name|QMouseEvent
argument_list|(
name|QEvent
operator|::
name|MouseButtonPress
argument_list|,
name|pos
argument_list|,
name|widget
operator|->
name|mapToGlobal
argument_list|(
name|pos
argument_list|)
argument_list|,
name|button
argument_list|,
name|button
argument_list|,
name|stateKey
argument_list|)
expr_stmt|;
break|break;
case|case
name|MouseRelease
case|:
name|me
operator|=
name|QMouseEvent
argument_list|(
name|QEvent
operator|::
name|MouseButtonRelease
argument_list|,
name|pos
argument_list|,
name|widget
operator|->
name|mapToGlobal
argument_list|(
name|pos
argument_list|)
argument_list|,
name|button
argument_list|,
literal|0
argument_list|,
name|stateKey
argument_list|)
expr_stmt|;
break|break;
case|case
name|MouseDClick
case|:
name|me
operator|=
name|QMouseEvent
argument_list|(
name|QEvent
operator|::
name|MouseButtonDblClick
argument_list|,
name|pos
argument_list|,
name|widget
operator|->
name|mapToGlobal
argument_list|(
name|pos
argument_list|)
argument_list|,
name|button
argument_list|,
name|button
argument_list|,
name|stateKey
argument_list|)
expr_stmt|;
break|break;
case|case
name|MouseMove
case|:
name|QCursor
operator|::
name|setPos
argument_list|(
name|widget
operator|->
name|mapToGlobal
argument_list|(
name|pos
argument_list|)
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|Q_OS_MAC
name|QTest
operator|::
name|qWait
argument_list|(
literal|20
argument_list|)
expr_stmt|;
else|#
directive|else
name|qApp
operator|->
name|processEvents
argument_list|()
expr_stmt|;
endif|#
directive|endif
return|return;
default|default:
name|QTEST_ASSERT
argument_list|(
name|false
argument_list|)
expr_stmt|;
block|}
name|QSpontaneKeyEvent
operator|::
name|setSpontaneous
argument_list|(
operator|&
name|me
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|qApp
operator|->
name|notify
argument_list|(
name|widget
argument_list|,
operator|&
name|me
argument_list|)
condition|)
block|{
specifier|static
specifier|const
name|char
modifier|*
name|mouseActionNames
index|[]
init|=
block|{
literal|"MousePress"
block|,
literal|"MouseRelease"
block|,
literal|"MouseClick"
block|,
literal|"MouseDClick"
block|,
literal|"MouseMove"
block|}
decl_stmt|;
name|QString
name|warning
init|=
name|QString
operator|::
name|fromLatin1
argument_list|(
literal|"Mouse event \"%1\" not accepted by receiving widget"
argument_list|)
decl_stmt|;
name|QTest
operator|::
name|qWarn
argument_list|(
name|warning
operator|.
name|arg
argument_list|(
name|QString
operator|::
name|fromLatin1
argument_list|(
name|mouseActionNames
index|[
name|static_cast
operator|<
name|int
operator|>
operator|(
name|action
operator|)
index|]
argument_list|)
argument_list|)
operator|.
name|toLatin1
argument_list|()
operator|.
name|data
argument_list|()
argument_list|)
expr_stmt|;
block|}
endif|#
directive|endif
block|}
specifier|inline
name|void
name|mousePress
argument_list|(
name|QWidget
operator|*
name|widget
argument_list|,
name|Qt
operator|::
name|MouseButton
name|button
argument_list|,
name|Qt
operator|::
name|KeyboardModifiers
name|stateKey
operator|=
literal|0
argument_list|,
name|QPoint
name|pos
operator|=
name|QPoint
argument_list|()
argument_list|,
name|int
name|delay
operator|=
operator|-
literal|1
argument_list|)
block|{
name|mouseEvent
argument_list|(
name|MousePress
argument_list|,
name|widget
argument_list|,
name|button
argument_list|,
name|stateKey
argument_list|,
name|pos
argument_list|,
name|delay
argument_list|)
expr_stmt|;
block|}
specifier|inline
name|void
name|mouseRelease
argument_list|(
name|QWidget
operator|*
name|widget
argument_list|,
name|Qt
operator|::
name|MouseButton
name|button
argument_list|,
name|Qt
operator|::
name|KeyboardModifiers
name|stateKey
operator|=
literal|0
argument_list|,
name|QPoint
name|pos
operator|=
name|QPoint
argument_list|()
argument_list|,
name|int
name|delay
operator|=
operator|-
literal|1
argument_list|)
block|{
name|mouseEvent
argument_list|(
name|MouseRelease
argument_list|,
name|widget
argument_list|,
name|button
argument_list|,
name|stateKey
argument_list|,
name|pos
argument_list|,
name|delay
argument_list|)
expr_stmt|;
block|}
specifier|inline
name|void
name|mouseClick
argument_list|(
name|QWidget
operator|*
name|widget
argument_list|,
name|Qt
operator|::
name|MouseButton
name|button
argument_list|,
name|Qt
operator|::
name|KeyboardModifiers
name|stateKey
operator|=
literal|0
argument_list|,
name|QPoint
name|pos
operator|=
name|QPoint
argument_list|()
argument_list|,
name|int
name|delay
operator|=
operator|-
literal|1
argument_list|)
block|{
name|mouseEvent
argument_list|(
name|MouseClick
argument_list|,
name|widget
argument_list|,
name|button
argument_list|,
name|stateKey
argument_list|,
name|pos
argument_list|,
name|delay
argument_list|)
expr_stmt|;
block|}
specifier|inline
name|void
name|mouseDClick
argument_list|(
name|QWidget
operator|*
name|widget
argument_list|,
name|Qt
operator|::
name|MouseButton
name|button
argument_list|,
name|Qt
operator|::
name|KeyboardModifiers
name|stateKey
operator|=
literal|0
argument_list|,
name|QPoint
name|pos
operator|=
name|QPoint
argument_list|()
argument_list|,
name|int
name|delay
operator|=
operator|-
literal|1
argument_list|)
block|{
name|mouseEvent
argument_list|(
name|MouseDClick
argument_list|,
name|widget
argument_list|,
name|button
argument_list|,
name|stateKey
argument_list|,
name|pos
argument_list|,
name|delay
argument_list|)
expr_stmt|;
block|}
specifier|inline
name|void
name|mouseMove
parameter_list|(
name|QWidget
modifier|*
name|widget
parameter_list|,
name|QPoint
name|pos
init|=
name|QPoint
argument_list|()
parameter_list|,
name|int
name|delay
init|=
operator|-
literal|1
parameter_list|)
block|{
name|mouseEvent
argument_list|(
name|MouseMove
argument_list|,
name|widget
argument_list|,
name|Qt
operator|::
name|NoButton
argument_list|,
literal|0
argument_list|,
name|pos
argument_list|,
name|delay
argument_list|)
expr_stmt|;
block|}
endif|#
directive|endif
comment|// QT_WIDGETS_LIB
block|}
end_decl_stmt
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QTESTMOUSE_H
end_comment
end_unit
