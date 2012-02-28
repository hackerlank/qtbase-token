begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qwidgetresizehandler_p.h"
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_RESIZEHANDLER
end_ifndef
begin_include
include|#
directive|include
file|"qframe.h"
end_include
begin_include
include|#
directive|include
file|"qapplication.h"
end_include
begin_include
include|#
directive|include
file|"qdesktopwidget.h"
end_include
begin_include
include|#
directive|include
file|"qcursor.h"
end_include
begin_include
include|#
directive|include
file|"qsizegrip.h"
end_include
begin_include
include|#
directive|include
file|"qevent.h"
end_include
begin_include
include|#
directive|include
file|"qdebug.h"
end_include
begin_include
include|#
directive|include
file|"private/qlayoutengine_p.h"
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|macro|RANGE
define|#
directive|define
name|RANGE
value|4
DECL|variable|resizeHorizontalDirectionFixed
specifier|static
name|bool
name|resizeHorizontalDirectionFixed
init|=
literal|false
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|resizeVerticalDirectionFixed
specifier|static
name|bool
name|resizeVerticalDirectionFixed
init|=
literal|false
decl_stmt|;
end_decl_stmt
begin_constructor
DECL|function|QWidgetResizeHandler
name|QWidgetResizeHandler
operator|::
name|QWidgetResizeHandler
parameter_list|(
name|QWidget
modifier|*
name|parent
parameter_list|,
name|QWidget
modifier|*
name|cw
parameter_list|)
member_init_list|:
name|QObject
argument_list|(
name|parent
argument_list|)
member_init_list|,
name|widget
argument_list|(
name|parent
argument_list|)
member_init_list|,
name|childWidget
argument_list|(
name|cw
condition|?
name|cw
else|:
name|parent
argument_list|)
member_init_list|,
name|fw
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|extrahei
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|buttonDown
argument_list|(
literal|false
argument_list|)
member_init_list|,
name|moveResizeMode
argument_list|(
literal|false
argument_list|)
member_init_list|,
name|sizeprotect
argument_list|(
literal|true
argument_list|)
member_init_list|,
name|movingEnabled
argument_list|(
literal|true
argument_list|)
block|{
name|mode
operator|=
name|Nowhere
expr_stmt|;
name|widget
operator|->
name|setMouseTracking
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|QFrame
modifier|*
name|frame
init|=
name|qobject_cast
argument_list|<
name|QFrame
operator|*
argument_list|>
argument_list|(
name|widget
argument_list|)
decl_stmt|;
name|range
operator|=
name|frame
condition|?
name|frame
operator|->
name|frameWidth
argument_list|()
else|:
name|RANGE
expr_stmt|;
name|range
operator|=
name|qMax
argument_list|(
name|RANGE
argument_list|,
name|range
argument_list|)
expr_stmt|;
name|activeForMove
operator|=
name|activeForResize
operator|=
literal|true
expr_stmt|;
name|widget
operator|->
name|installEventFilter
argument_list|(
name|this
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_function
DECL|function|setActive
name|void
name|QWidgetResizeHandler
operator|::
name|setActive
parameter_list|(
name|Action
name|ac
parameter_list|,
name|bool
name|b
parameter_list|)
block|{
if|if
condition|(
name|ac
operator|&
name|Move
condition|)
name|activeForMove
operator|=
name|b
expr_stmt|;
if|if
condition|(
name|ac
operator|&
name|Resize
condition|)
name|activeForResize
operator|=
name|b
expr_stmt|;
if|if
condition|(
operator|!
name|isActive
argument_list|()
condition|)
name|setMouseCursor
argument_list|(
name|Nowhere
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|isActive
name|bool
name|QWidgetResizeHandler
operator|::
name|isActive
parameter_list|(
name|Action
name|ac
parameter_list|)
specifier|const
block|{
name|bool
name|b
init|=
literal|false
decl_stmt|;
if|if
condition|(
name|ac
operator|&
name|Move
condition|)
name|b
operator|=
name|activeForMove
expr_stmt|;
if|if
condition|(
name|ac
operator|&
name|Resize
condition|)
name|b
operator||=
name|activeForResize
expr_stmt|;
return|return
name|b
return|;
block|}
end_function
begin_function
DECL|function|eventFilter
name|bool
name|QWidgetResizeHandler
operator|::
name|eventFilter
parameter_list|(
name|QObject
modifier|*
name|o
parameter_list|,
name|QEvent
modifier|*
name|ee
parameter_list|)
block|{
if|if
condition|(
operator|!
name|isActive
argument_list|()
operator|||
operator|(
name|ee
operator|->
name|type
argument_list|()
operator|!=
name|QEvent
operator|::
name|MouseButtonPress
operator|&&
name|ee
operator|->
name|type
argument_list|()
operator|!=
name|QEvent
operator|::
name|MouseButtonRelease
operator|&&
name|ee
operator|->
name|type
argument_list|()
operator|!=
name|QEvent
operator|::
name|MouseMove
operator|&&
name|ee
operator|->
name|type
argument_list|()
operator|!=
name|QEvent
operator|::
name|KeyPress
operator|&&
name|ee
operator|->
name|type
argument_list|()
operator|!=
name|QEvent
operator|::
name|ShortcutOverride
operator|)
condition|)
return|return
literal|false
return|;
name|Q_ASSERT
argument_list|(
name|o
operator|==
name|widget
argument_list|)
expr_stmt|;
name|QWidget
modifier|*
name|w
init|=
name|widget
decl_stmt|;
if|if
condition|(
name|QApplication
operator|::
name|activePopupWidget
argument_list|()
condition|)
block|{
if|if
condition|(
name|buttonDown
operator|&&
name|ee
operator|->
name|type
argument_list|()
operator|==
name|QEvent
operator|::
name|MouseButtonRelease
condition|)
name|buttonDown
operator|=
literal|false
expr_stmt|;
return|return
literal|false
return|;
block|}
name|QMouseEvent
modifier|*
name|e
init|=
operator|(
name|QMouseEvent
operator|*
operator|)
name|ee
decl_stmt|;
switch|switch
condition|(
name|e
operator|->
name|type
argument_list|()
condition|)
block|{
case|case
name|QEvent
operator|::
name|MouseButtonPress
case|:
block|{
if|if
condition|(
name|w
operator|->
name|isMaximized
argument_list|()
condition|)
break|break;
if|if
condition|(
operator|!
name|widget
operator|->
name|rect
argument_list|()
operator|.
name|contains
argument_list|(
name|widget
operator|->
name|mapFromGlobal
argument_list|(
name|e
operator|->
name|globalPos
argument_list|()
argument_list|)
argument_list|)
condition|)
return|return
literal|false
return|;
if|if
condition|(
name|e
operator|->
name|button
argument_list|()
operator|==
name|Qt
operator|::
name|LeftButton
condition|)
block|{
if|#
directive|if
name|defined
argument_list|(
name|Q_WS_X11
argument_list|)
comment|/*                Implicit grabs do not stop the X server from changing                the cursor in children, which looks *really* bad when                doing resizingk, so we grab the cursor. Note that we do                not do this on Windows since double clicks are lost due                to the grab (see change 198463).             */
if|if
condition|(
name|e
operator|->
name|spontaneous
argument_list|()
condition|)
if|#
directive|if
operator|!
name|defined
argument_list|(
name|QT_NO_CURSOR
argument_list|)
name|widget
operator|->
name|grabMouse
argument_list|(
name|widget
operator|->
name|cursor
argument_list|()
argument_list|)
expr_stmt|;
else|#
directive|else
name|widget
operator|->
name|grabMouse
argument_list|()
expr_stmt|;
endif|#
directive|endif
comment|// QT_NO_CURSOR
endif|#
directive|endif
comment|// Q_WS_X11
name|buttonDown
operator|=
literal|false
expr_stmt|;
emit|emit
name|activate
argument_list|()
emit|;
name|bool
name|me
init|=
name|movingEnabled
decl_stmt|;
name|movingEnabled
operator|=
operator|(
name|me
operator|&&
name|o
operator|==
name|widget
operator|)
expr_stmt|;
name|mouseMoveEvent
argument_list|(
name|e
argument_list|)
expr_stmt|;
name|movingEnabled
operator|=
name|me
expr_stmt|;
name|buttonDown
operator|=
literal|true
expr_stmt|;
name|moveOffset
operator|=
name|widget
operator|->
name|mapFromGlobal
argument_list|(
name|e
operator|->
name|globalPos
argument_list|()
argument_list|)
expr_stmt|;
name|invertedMoveOffset
operator|=
name|widget
operator|->
name|rect
argument_list|()
operator|.
name|bottomRight
argument_list|()
operator|-
name|moveOffset
expr_stmt|;
if|if
condition|(
name|mode
operator|==
name|Center
condition|)
block|{
if|if
condition|(
name|movingEnabled
condition|)
return|return
literal|true
return|;
block|}
else|else
block|{
return|return
literal|true
return|;
block|}
block|}
block|}
break|break;
case|case
name|QEvent
operator|::
name|MouseButtonRelease
case|:
if|if
condition|(
name|w
operator|->
name|isMaximized
argument_list|()
condition|)
break|break;
if|if
condition|(
name|e
operator|->
name|button
argument_list|()
operator|==
name|Qt
operator|::
name|LeftButton
condition|)
block|{
name|moveResizeMode
operator|=
literal|false
expr_stmt|;
name|buttonDown
operator|=
literal|false
expr_stmt|;
name|widget
operator|->
name|releaseMouse
argument_list|()
expr_stmt|;
name|widget
operator|->
name|releaseKeyboard
argument_list|()
expr_stmt|;
if|if
condition|(
name|mode
operator|==
name|Center
condition|)
block|{
if|if
condition|(
name|movingEnabled
condition|)
return|return
literal|true
return|;
block|}
else|else
block|{
return|return
literal|true
return|;
block|}
block|}
break|break;
case|case
name|QEvent
operator|::
name|MouseMove
case|:
block|{
if|if
condition|(
name|w
operator|->
name|isMaximized
argument_list|()
condition|)
break|break;
name|buttonDown
operator|=
name|buttonDown
operator|&&
operator|(
name|e
operator|->
name|buttons
argument_list|()
operator|&
name|Qt
operator|::
name|LeftButton
operator|)
expr_stmt|;
comment|// safety, state machine broken!
name|bool
name|me
init|=
name|movingEnabled
decl_stmt|;
name|movingEnabled
operator|=
operator|(
name|me
operator|&&
name|o
operator|==
name|widget
operator|&&
operator|(
name|buttonDown
operator|||
name|moveResizeMode
operator|)
operator|)
expr_stmt|;
name|mouseMoveEvent
argument_list|(
name|e
argument_list|)
expr_stmt|;
name|movingEnabled
operator|=
name|me
expr_stmt|;
if|if
condition|(
name|mode
operator|==
name|Center
condition|)
block|{
if|if
condition|(
name|movingEnabled
condition|)
return|return
literal|true
return|;
block|}
else|else
block|{
return|return
literal|true
return|;
block|}
block|}
break|break;
case|case
name|QEvent
operator|::
name|KeyPress
case|:
name|keyPressEvent
argument_list|(
operator|(
name|QKeyEvent
operator|*
operator|)
name|e
argument_list|)
expr_stmt|;
break|break;
case|case
name|QEvent
operator|::
name|ShortcutOverride
case|:
if|if
condition|(
name|buttonDown
condition|)
block|{
operator|(
operator|(
name|QKeyEvent
operator|*
operator|)
name|ee
operator|)
operator|->
name|accept
argument_list|()
expr_stmt|;
return|return
literal|true
return|;
block|}
break|break;
default|default:
break|break;
block|}
return|return
literal|false
return|;
block|}
end_function
begin_function
DECL|function|mouseMoveEvent
name|void
name|QWidgetResizeHandler
operator|::
name|mouseMoveEvent
parameter_list|(
name|QMouseEvent
modifier|*
name|e
parameter_list|)
block|{
name|QPoint
name|pos
init|=
name|widget
operator|->
name|mapFromGlobal
argument_list|(
name|e
operator|->
name|globalPos
argument_list|()
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|moveResizeMode
operator|&&
operator|!
name|buttonDown
condition|)
block|{
if|if
condition|(
name|pos
operator|.
name|y
argument_list|()
operator|<=
name|range
operator|&&
name|pos
operator|.
name|x
argument_list|()
operator|<=
name|range
condition|)
name|mode
operator|=
name|TopLeft
expr_stmt|;
elseif|else
if|if
condition|(
name|pos
operator|.
name|y
argument_list|()
operator|>=
name|widget
operator|->
name|height
argument_list|()
operator|-
name|range
operator|&&
name|pos
operator|.
name|x
argument_list|()
operator|>=
name|widget
operator|->
name|width
argument_list|()
operator|-
name|range
condition|)
name|mode
operator|=
name|BottomRight
expr_stmt|;
elseif|else
if|if
condition|(
name|pos
operator|.
name|y
argument_list|()
operator|>=
name|widget
operator|->
name|height
argument_list|()
operator|-
name|range
operator|&&
name|pos
operator|.
name|x
argument_list|()
operator|<=
name|range
condition|)
name|mode
operator|=
name|BottomLeft
expr_stmt|;
elseif|else
if|if
condition|(
name|pos
operator|.
name|y
argument_list|()
operator|<=
name|range
operator|&&
name|pos
operator|.
name|x
argument_list|()
operator|>=
name|widget
operator|->
name|width
argument_list|()
operator|-
name|range
condition|)
name|mode
operator|=
name|TopRight
expr_stmt|;
elseif|else
if|if
condition|(
name|pos
operator|.
name|y
argument_list|()
operator|<=
name|range
condition|)
name|mode
operator|=
name|Top
expr_stmt|;
elseif|else
if|if
condition|(
name|pos
operator|.
name|y
argument_list|()
operator|>=
name|widget
operator|->
name|height
argument_list|()
operator|-
name|range
condition|)
name|mode
operator|=
name|Bottom
expr_stmt|;
elseif|else
if|if
condition|(
name|pos
operator|.
name|x
argument_list|()
operator|<=
name|range
condition|)
name|mode
operator|=
name|Left
expr_stmt|;
elseif|else
if|if
condition|(
name|pos
operator|.
name|x
argument_list|()
operator|>=
name|widget
operator|->
name|width
argument_list|()
operator|-
name|range
condition|)
name|mode
operator|=
name|Right
expr_stmt|;
elseif|else
if|if
condition|(
name|widget
operator|->
name|rect
argument_list|()
operator|.
name|contains
argument_list|(
name|pos
argument_list|)
condition|)
name|mode
operator|=
name|Center
expr_stmt|;
else|else
name|mode
operator|=
name|Nowhere
expr_stmt|;
if|if
condition|(
name|widget
operator|->
name|isMinimized
argument_list|()
operator|||
operator|!
name|isActive
argument_list|(
name|Resize
argument_list|)
condition|)
name|mode
operator|=
name|Center
expr_stmt|;
ifndef|#
directive|ifndef
name|QT_NO_CURSOR
name|setMouseCursor
argument_list|(
name|mode
argument_list|)
expr_stmt|;
endif|#
directive|endif
return|return;
block|}
if|if
condition|(
name|mode
operator|==
name|Center
operator|&&
operator|!
name|movingEnabled
condition|)
return|return;
if|if
condition|(
name|widget
operator|->
name|testAttribute
argument_list|(
name|Qt
operator|::
name|WA_WState_ConfigPending
argument_list|)
condition|)
return|return;
name|QPoint
name|globalPos
init|=
operator|(
operator|!
name|widget
operator|->
name|isWindow
argument_list|()
operator|&&
name|widget
operator|->
name|parentWidget
argument_list|()
operator|)
condition|?
name|widget
operator|->
name|parentWidget
argument_list|()
operator|->
name|mapFromGlobal
argument_list|(
name|e
operator|->
name|globalPos
argument_list|()
argument_list|)
else|:
name|e
operator|->
name|globalPos
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
name|widget
operator|->
name|isWindow
argument_list|()
operator|&&
operator|!
name|widget
operator|->
name|parentWidget
argument_list|()
operator|->
name|rect
argument_list|()
operator|.
name|contains
argument_list|(
name|globalPos
argument_list|)
condition|)
block|{
if|if
condition|(
name|globalPos
operator|.
name|x
argument_list|()
operator|<
literal|0
condition|)
name|globalPos
operator|.
name|rx
argument_list|()
operator|=
literal|0
expr_stmt|;
if|if
condition|(
name|globalPos
operator|.
name|y
argument_list|()
operator|<
literal|0
condition|)
name|globalPos
operator|.
name|ry
argument_list|()
operator|=
literal|0
expr_stmt|;
if|if
condition|(
name|sizeprotect
operator|&&
name|globalPos
operator|.
name|x
argument_list|()
operator|>
name|widget
operator|->
name|parentWidget
argument_list|()
operator|->
name|width
argument_list|()
condition|)
name|globalPos
operator|.
name|rx
argument_list|()
operator|=
name|widget
operator|->
name|parentWidget
argument_list|()
operator|->
name|width
argument_list|()
expr_stmt|;
if|if
condition|(
name|sizeprotect
operator|&&
name|globalPos
operator|.
name|y
argument_list|()
operator|>
name|widget
operator|->
name|parentWidget
argument_list|()
operator|->
name|height
argument_list|()
condition|)
name|globalPos
operator|.
name|ry
argument_list|()
operator|=
name|widget
operator|->
name|parentWidget
argument_list|()
operator|->
name|height
argument_list|()
expr_stmt|;
block|}
name|QPoint
name|p
init|=
name|globalPos
operator|+
name|invertedMoveOffset
decl_stmt|;
name|QPoint
name|pp
init|=
name|globalPos
operator|-
name|moveOffset
decl_stmt|;
ifdef|#
directive|ifdef
name|Q_WS_X11
comment|// Workaround for window managers which refuse to move a tool window partially offscreen.
name|QRect
name|desktop
init|=
name|QApplication
operator|::
name|desktop
argument_list|()
operator|->
name|availableGeometry
argument_list|(
name|widget
argument_list|)
decl_stmt|;
name|pp
operator|.
name|rx
argument_list|()
operator|=
name|qMax
argument_list|(
name|pp
operator|.
name|x
argument_list|()
argument_list|,
name|desktop
operator|.
name|left
argument_list|()
argument_list|)
expr_stmt|;
name|pp
operator|.
name|ry
argument_list|()
operator|=
name|qMax
argument_list|(
name|pp
operator|.
name|y
argument_list|()
argument_list|,
name|desktop
operator|.
name|top
argument_list|()
argument_list|)
expr_stmt|;
name|p
operator|.
name|rx
argument_list|()
operator|=
name|qMin
argument_list|(
name|p
operator|.
name|x
argument_list|()
argument_list|,
name|desktop
operator|.
name|right
argument_list|()
argument_list|)
expr_stmt|;
name|p
operator|.
name|ry
argument_list|()
operator|=
name|qMin
argument_list|(
name|p
operator|.
name|y
argument_list|()
argument_list|,
name|desktop
operator|.
name|bottom
argument_list|()
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|QSize
name|ms
init|=
name|qSmartMinSize
argument_list|(
name|childWidget
argument_list|)
decl_stmt|;
name|int
name|mw
init|=
name|ms
operator|.
name|width
argument_list|()
decl_stmt|;
name|int
name|mh
init|=
name|ms
operator|.
name|height
argument_list|()
decl_stmt|;
if|if
condition|(
name|childWidget
operator|!=
name|widget
condition|)
block|{
name|mw
operator|+=
literal|2
operator|*
name|fw
expr_stmt|;
name|mh
operator|+=
literal|2
operator|*
name|fw
operator|+
name|extrahei
expr_stmt|;
block|}
name|QSize
name|maxsize
argument_list|(
name|childWidget
operator|->
name|maximumSize
argument_list|()
argument_list|)
decl_stmt|;
if|if
condition|(
name|childWidget
operator|!=
name|widget
condition|)
name|maxsize
operator|+=
name|QSize
argument_list|(
literal|2
operator|*
name|fw
argument_list|,
literal|2
operator|*
name|fw
operator|+
name|extrahei
argument_list|)
expr_stmt|;
name|QSize
name|mpsize
argument_list|(
name|widget
operator|->
name|geometry
argument_list|()
operator|.
name|right
argument_list|()
operator|-
name|pp
operator|.
name|x
argument_list|()
operator|+
literal|1
argument_list|,
name|widget
operator|->
name|geometry
argument_list|()
operator|.
name|bottom
argument_list|()
operator|-
name|pp
operator|.
name|y
argument_list|()
operator|+
literal|1
argument_list|)
decl_stmt|;
name|mpsize
operator|=
name|mpsize
operator|.
name|expandedTo
argument_list|(
name|widget
operator|->
name|minimumSize
argument_list|()
argument_list|)
operator|.
name|expandedTo
argument_list|(
name|QSize
argument_list|(
name|mw
argument_list|,
name|mh
argument_list|)
argument_list|)
operator|.
name|boundedTo
argument_list|(
name|maxsize
argument_list|)
expr_stmt|;
name|QPoint
name|mp
argument_list|(
name|widget
operator|->
name|geometry
argument_list|()
operator|.
name|right
argument_list|()
operator|-
name|mpsize
operator|.
name|width
argument_list|()
operator|+
literal|1
argument_list|,
name|widget
operator|->
name|geometry
argument_list|()
operator|.
name|bottom
argument_list|()
operator|-
name|mpsize
operator|.
name|height
argument_list|()
operator|+
literal|1
argument_list|)
decl_stmt|;
name|QRect
name|geom
init|=
name|widget
operator|->
name|geometry
argument_list|()
decl_stmt|;
switch|switch
condition|(
name|mode
condition|)
block|{
case|case
name|TopLeft
case|:
name|geom
operator|=
name|QRect
argument_list|(
name|mp
argument_list|,
name|widget
operator|->
name|geometry
argument_list|()
operator|.
name|bottomRight
argument_list|()
argument_list|)
expr_stmt|;
break|break;
case|case
name|BottomRight
case|:
name|geom
operator|=
name|QRect
argument_list|(
name|widget
operator|->
name|geometry
argument_list|()
operator|.
name|topLeft
argument_list|()
argument_list|,
name|p
argument_list|)
expr_stmt|;
break|break;
case|case
name|BottomLeft
case|:
name|geom
operator|=
name|QRect
argument_list|(
name|QPoint
argument_list|(
name|mp
operator|.
name|x
argument_list|()
argument_list|,
name|widget
operator|->
name|geometry
argument_list|()
operator|.
name|y
argument_list|()
argument_list|)
argument_list|,
name|QPoint
argument_list|(
name|widget
operator|->
name|geometry
argument_list|()
operator|.
name|right
argument_list|()
argument_list|,
name|p
operator|.
name|y
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
break|break;
case|case
name|TopRight
case|:
name|geom
operator|=
name|QRect
argument_list|(
name|QPoint
argument_list|(
name|widget
operator|->
name|geometry
argument_list|()
operator|.
name|x
argument_list|()
argument_list|,
name|mp
operator|.
name|y
argument_list|()
argument_list|)
argument_list|,
name|QPoint
argument_list|(
name|p
operator|.
name|x
argument_list|()
argument_list|,
name|widget
operator|->
name|geometry
argument_list|()
operator|.
name|bottom
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
break|break;
case|case
name|Top
case|:
name|geom
operator|=
name|QRect
argument_list|(
name|QPoint
argument_list|(
name|widget
operator|->
name|geometry
argument_list|()
operator|.
name|left
argument_list|()
argument_list|,
name|mp
operator|.
name|y
argument_list|()
argument_list|)
argument_list|,
name|widget
operator|->
name|geometry
argument_list|()
operator|.
name|bottomRight
argument_list|()
argument_list|)
expr_stmt|;
break|break;
case|case
name|Bottom
case|:
name|geom
operator|=
name|QRect
argument_list|(
name|widget
operator|->
name|geometry
argument_list|()
operator|.
name|topLeft
argument_list|()
argument_list|,
name|QPoint
argument_list|(
name|widget
operator|->
name|geometry
argument_list|()
operator|.
name|right
argument_list|()
argument_list|,
name|p
operator|.
name|y
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
break|break;
case|case
name|Left
case|:
name|geom
operator|=
name|QRect
argument_list|(
name|QPoint
argument_list|(
name|mp
operator|.
name|x
argument_list|()
argument_list|,
name|widget
operator|->
name|geometry
argument_list|()
operator|.
name|top
argument_list|()
argument_list|)
argument_list|,
name|widget
operator|->
name|geometry
argument_list|()
operator|.
name|bottomRight
argument_list|()
argument_list|)
expr_stmt|;
break|break;
case|case
name|Right
case|:
name|geom
operator|=
name|QRect
argument_list|(
name|widget
operator|->
name|geometry
argument_list|()
operator|.
name|topLeft
argument_list|()
argument_list|,
name|QPoint
argument_list|(
name|p
operator|.
name|x
argument_list|()
argument_list|,
name|widget
operator|->
name|geometry
argument_list|()
operator|.
name|bottom
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
break|break;
case|case
name|Center
case|:
name|geom
operator|.
name|moveTopLeft
argument_list|(
name|pp
argument_list|)
expr_stmt|;
break|break;
default|default:
break|break;
block|}
name|geom
operator|=
name|QRect
argument_list|(
name|geom
operator|.
name|topLeft
argument_list|()
argument_list|,
name|geom
operator|.
name|size
argument_list|()
operator|.
name|expandedTo
argument_list|(
name|widget
operator|->
name|minimumSize
argument_list|()
argument_list|)
operator|.
name|expandedTo
argument_list|(
name|QSize
argument_list|(
name|mw
argument_list|,
name|mh
argument_list|)
argument_list|)
operator|.
name|boundedTo
argument_list|(
name|maxsize
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|geom
operator|!=
name|widget
operator|->
name|geometry
argument_list|()
operator|&&
operator|(
name|widget
operator|->
name|isWindow
argument_list|()
operator|||
name|widget
operator|->
name|parentWidget
argument_list|()
operator|->
name|rect
argument_list|()
operator|.
name|intersects
argument_list|(
name|geom
argument_list|)
operator|)
condition|)
block|{
if|if
condition|(
name|mode
operator|==
name|Center
condition|)
name|widget
operator|->
name|move
argument_list|(
name|geom
operator|.
name|topLeft
argument_list|()
argument_list|)
expr_stmt|;
else|else
name|widget
operator|->
name|setGeometry
argument_list|(
name|geom
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|setMouseCursor
name|void
name|QWidgetResizeHandler
operator|::
name|setMouseCursor
parameter_list|(
name|MousePosition
name|m
parameter_list|)
block|{
ifdef|#
directive|ifdef
name|QT_NO_CURSOR
name|Q_UNUSED
argument_list|(
name|m
argument_list|)
expr_stmt|;
else|#
directive|else
name|QObjectList
name|children
init|=
name|widget
operator|->
name|children
argument_list|()
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
name|children
operator|.
name|size
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
if|if
condition|(
name|QWidget
modifier|*
name|w
init|=
name|qobject_cast
argument_list|<
name|QWidget
operator|*
argument_list|>
argument_list|(
name|children
operator|.
name|at
argument_list|(
name|i
argument_list|)
argument_list|)
condition|)
block|{
if|if
condition|(
operator|!
name|w
operator|->
name|testAttribute
argument_list|(
name|Qt
operator|::
name|WA_SetCursor
argument_list|)
operator|&&
operator|!
name|w
operator|->
name|inherits
argument_list|(
literal|"QWorkspaceTitleBar"
argument_list|)
condition|)
block|{
name|w
operator|->
name|setCursor
argument_list|(
name|Qt
operator|::
name|ArrowCursor
argument_list|)
expr_stmt|;
block|}
block|}
block|}
switch|switch
condition|(
name|m
condition|)
block|{
case|case
name|TopLeft
case|:
case|case
name|BottomRight
case|:
name|widget
operator|->
name|setCursor
argument_list|(
name|Qt
operator|::
name|SizeFDiagCursor
argument_list|)
expr_stmt|;
break|break;
case|case
name|BottomLeft
case|:
case|case
name|TopRight
case|:
name|widget
operator|->
name|setCursor
argument_list|(
name|Qt
operator|::
name|SizeBDiagCursor
argument_list|)
expr_stmt|;
break|break;
case|case
name|Top
case|:
case|case
name|Bottom
case|:
name|widget
operator|->
name|setCursor
argument_list|(
name|Qt
operator|::
name|SizeVerCursor
argument_list|)
expr_stmt|;
break|break;
case|case
name|Left
case|:
case|case
name|Right
case|:
name|widget
operator|->
name|setCursor
argument_list|(
name|Qt
operator|::
name|SizeHorCursor
argument_list|)
expr_stmt|;
break|break;
default|default:
name|widget
operator|->
name|setCursor
argument_list|(
name|Qt
operator|::
name|ArrowCursor
argument_list|)
expr_stmt|;
break|break;
block|}
endif|#
directive|endif
comment|// QT_NO_CURSOR
block|}
end_function
begin_function
DECL|function|keyPressEvent
name|void
name|QWidgetResizeHandler
operator|::
name|keyPressEvent
parameter_list|(
name|QKeyEvent
modifier|*
name|e
parameter_list|)
block|{
if|if
condition|(
operator|!
name|isMove
argument_list|()
operator|&&
operator|!
name|isResize
argument_list|()
condition|)
return|return;
name|bool
name|is_control
init|=
name|e
operator|->
name|modifiers
argument_list|()
operator|&
name|Qt
operator|::
name|ControlModifier
decl_stmt|;
name|int
name|delta
init|=
name|is_control
condition|?
literal|1
else|:
literal|8
decl_stmt|;
name|QPoint
name|pos
init|=
name|QCursor
operator|::
name|pos
argument_list|()
decl_stmt|;
switch|switch
condition|(
name|e
operator|->
name|key
argument_list|()
condition|)
block|{
case|case
name|Qt
operator|::
name|Key_Left
case|:
name|pos
operator|.
name|rx
argument_list|()
operator|-=
name|delta
expr_stmt|;
if|if
condition|(
name|pos
operator|.
name|x
argument_list|()
operator|<=
name|QApplication
operator|::
name|desktop
argument_list|()
operator|->
name|geometry
argument_list|()
operator|.
name|left
argument_list|()
condition|)
block|{
if|if
condition|(
name|mode
operator|==
name|TopLeft
operator|||
name|mode
operator|==
name|BottomLeft
condition|)
block|{
name|moveOffset
operator|.
name|rx
argument_list|()
operator|+=
name|delta
expr_stmt|;
name|invertedMoveOffset
operator|.
name|rx
argument_list|()
operator|+=
name|delta
expr_stmt|;
block|}
else|else
block|{
name|moveOffset
operator|.
name|rx
argument_list|()
operator|-=
name|delta
expr_stmt|;
name|invertedMoveOffset
operator|.
name|rx
argument_list|()
operator|-=
name|delta
expr_stmt|;
block|}
block|}
if|if
condition|(
name|isResize
argument_list|()
operator|&&
operator|!
name|resizeHorizontalDirectionFixed
condition|)
block|{
name|resizeHorizontalDirectionFixed
operator|=
literal|true
expr_stmt|;
if|if
condition|(
name|mode
operator|==
name|BottomRight
condition|)
name|mode
operator|=
name|BottomLeft
expr_stmt|;
elseif|else
if|if
condition|(
name|mode
operator|==
name|TopRight
condition|)
name|mode
operator|=
name|TopLeft
expr_stmt|;
ifndef|#
directive|ifndef
name|QT_NO_CURSOR
name|setMouseCursor
argument_list|(
name|mode
argument_list|)
expr_stmt|;
name|widget
operator|->
name|grabMouse
argument_list|(
name|widget
operator|->
name|cursor
argument_list|()
argument_list|)
expr_stmt|;
else|#
directive|else
name|widget
operator|->
name|grabMouse
argument_list|()
expr_stmt|;
endif|#
directive|endif
block|}
break|break;
case|case
name|Qt
operator|::
name|Key_Right
case|:
name|pos
operator|.
name|rx
argument_list|()
operator|+=
name|delta
expr_stmt|;
if|if
condition|(
name|pos
operator|.
name|x
argument_list|()
operator|>=
name|QApplication
operator|::
name|desktop
argument_list|()
operator|->
name|geometry
argument_list|()
operator|.
name|right
argument_list|()
condition|)
block|{
if|if
condition|(
name|mode
operator|==
name|TopRight
operator|||
name|mode
operator|==
name|BottomRight
condition|)
block|{
name|moveOffset
operator|.
name|rx
argument_list|()
operator|+=
name|delta
expr_stmt|;
name|invertedMoveOffset
operator|.
name|rx
argument_list|()
operator|+=
name|delta
expr_stmt|;
block|}
else|else
block|{
name|moveOffset
operator|.
name|rx
argument_list|()
operator|-=
name|delta
expr_stmt|;
name|invertedMoveOffset
operator|.
name|rx
argument_list|()
operator|-=
name|delta
expr_stmt|;
block|}
block|}
if|if
condition|(
name|isResize
argument_list|()
operator|&&
operator|!
name|resizeHorizontalDirectionFixed
condition|)
block|{
name|resizeHorizontalDirectionFixed
operator|=
literal|true
expr_stmt|;
if|if
condition|(
name|mode
operator|==
name|BottomLeft
condition|)
name|mode
operator|=
name|BottomRight
expr_stmt|;
elseif|else
if|if
condition|(
name|mode
operator|==
name|TopLeft
condition|)
name|mode
operator|=
name|TopRight
expr_stmt|;
ifndef|#
directive|ifndef
name|QT_NO_CURSOR
name|setMouseCursor
argument_list|(
name|mode
argument_list|)
expr_stmt|;
name|widget
operator|->
name|grabMouse
argument_list|(
name|widget
operator|->
name|cursor
argument_list|()
argument_list|)
expr_stmt|;
else|#
directive|else
name|widget
operator|->
name|grabMouse
argument_list|()
expr_stmt|;
endif|#
directive|endif
block|}
break|break;
case|case
name|Qt
operator|::
name|Key_Up
case|:
name|pos
operator|.
name|ry
argument_list|()
operator|-=
name|delta
expr_stmt|;
if|if
condition|(
name|pos
operator|.
name|y
argument_list|()
operator|<=
name|QApplication
operator|::
name|desktop
argument_list|()
operator|->
name|geometry
argument_list|()
operator|.
name|top
argument_list|()
condition|)
block|{
if|if
condition|(
name|mode
operator|==
name|TopLeft
operator|||
name|mode
operator|==
name|TopRight
condition|)
block|{
name|moveOffset
operator|.
name|ry
argument_list|()
operator|+=
name|delta
expr_stmt|;
name|invertedMoveOffset
operator|.
name|ry
argument_list|()
operator|+=
name|delta
expr_stmt|;
block|}
else|else
block|{
name|moveOffset
operator|.
name|ry
argument_list|()
operator|-=
name|delta
expr_stmt|;
name|invertedMoveOffset
operator|.
name|ry
argument_list|()
operator|-=
name|delta
expr_stmt|;
block|}
block|}
if|if
condition|(
name|isResize
argument_list|()
operator|&&
operator|!
name|resizeVerticalDirectionFixed
condition|)
block|{
name|resizeVerticalDirectionFixed
operator|=
literal|true
expr_stmt|;
if|if
condition|(
name|mode
operator|==
name|BottomLeft
condition|)
name|mode
operator|=
name|TopLeft
expr_stmt|;
elseif|else
if|if
condition|(
name|mode
operator|==
name|BottomRight
condition|)
name|mode
operator|=
name|TopRight
expr_stmt|;
ifndef|#
directive|ifndef
name|QT_NO_CURSOR
name|setMouseCursor
argument_list|(
name|mode
argument_list|)
expr_stmt|;
name|widget
operator|->
name|grabMouse
argument_list|(
name|widget
operator|->
name|cursor
argument_list|()
argument_list|)
expr_stmt|;
else|#
directive|else
name|widget
operator|->
name|grabMouse
argument_list|()
expr_stmt|;
endif|#
directive|endif
block|}
break|break;
case|case
name|Qt
operator|::
name|Key_Down
case|:
name|pos
operator|.
name|ry
argument_list|()
operator|+=
name|delta
expr_stmt|;
if|if
condition|(
name|pos
operator|.
name|y
argument_list|()
operator|>=
name|QApplication
operator|::
name|desktop
argument_list|()
operator|->
name|geometry
argument_list|()
operator|.
name|bottom
argument_list|()
condition|)
block|{
if|if
condition|(
name|mode
operator|==
name|BottomLeft
operator|||
name|mode
operator|==
name|BottomRight
condition|)
block|{
name|moveOffset
operator|.
name|ry
argument_list|()
operator|+=
name|delta
expr_stmt|;
name|invertedMoveOffset
operator|.
name|ry
argument_list|()
operator|+=
name|delta
expr_stmt|;
block|}
else|else
block|{
name|moveOffset
operator|.
name|ry
argument_list|()
operator|-=
name|delta
expr_stmt|;
name|invertedMoveOffset
operator|.
name|ry
argument_list|()
operator|-=
name|delta
expr_stmt|;
block|}
block|}
if|if
condition|(
name|isResize
argument_list|()
operator|&&
operator|!
name|resizeVerticalDirectionFixed
condition|)
block|{
name|resizeVerticalDirectionFixed
operator|=
literal|true
expr_stmt|;
if|if
condition|(
name|mode
operator|==
name|TopLeft
condition|)
name|mode
operator|=
name|BottomLeft
expr_stmt|;
elseif|else
if|if
condition|(
name|mode
operator|==
name|TopRight
condition|)
name|mode
operator|=
name|BottomRight
expr_stmt|;
ifndef|#
directive|ifndef
name|QT_NO_CURSOR
name|setMouseCursor
argument_list|(
name|mode
argument_list|)
expr_stmt|;
name|widget
operator|->
name|grabMouse
argument_list|(
name|widget
operator|->
name|cursor
argument_list|()
argument_list|)
expr_stmt|;
else|#
directive|else
name|widget
operator|->
name|grabMouse
argument_list|()
expr_stmt|;
endif|#
directive|endif
block|}
break|break;
case|case
name|Qt
operator|::
name|Key_Space
case|:
case|case
name|Qt
operator|::
name|Key_Return
case|:
case|case
name|Qt
operator|::
name|Key_Enter
case|:
case|case
name|Qt
operator|::
name|Key_Escape
case|:
name|moveResizeMode
operator|=
literal|false
expr_stmt|;
name|widget
operator|->
name|releaseMouse
argument_list|()
expr_stmt|;
name|widget
operator|->
name|releaseKeyboard
argument_list|()
expr_stmt|;
name|buttonDown
operator|=
literal|false
expr_stmt|;
break|break;
default|default:
return|return;
block|}
name|QCursor
operator|::
name|setPos
argument_list|(
name|pos
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|doResize
name|void
name|QWidgetResizeHandler
operator|::
name|doResize
parameter_list|()
block|{
if|if
condition|(
operator|!
name|activeForResize
condition|)
return|return;
name|moveResizeMode
operator|=
literal|true
expr_stmt|;
name|moveOffset
operator|=
name|widget
operator|->
name|mapFromGlobal
argument_list|(
name|QCursor
operator|::
name|pos
argument_list|()
argument_list|)
expr_stmt|;
if|if
condition|(
name|moveOffset
operator|.
name|x
argument_list|()
operator|<
name|widget
operator|->
name|width
argument_list|()
operator|/
literal|2
condition|)
block|{
if|if
condition|(
name|moveOffset
operator|.
name|y
argument_list|()
operator|<
name|widget
operator|->
name|height
argument_list|()
operator|/
literal|2
condition|)
name|mode
operator|=
name|TopLeft
expr_stmt|;
else|else
name|mode
operator|=
name|BottomLeft
expr_stmt|;
block|}
else|else
block|{
if|if
condition|(
name|moveOffset
operator|.
name|y
argument_list|()
operator|<
name|widget
operator|->
name|height
argument_list|()
operator|/
literal|2
condition|)
name|mode
operator|=
name|TopRight
expr_stmt|;
else|else
name|mode
operator|=
name|BottomRight
expr_stmt|;
block|}
name|invertedMoveOffset
operator|=
name|widget
operator|->
name|rect
argument_list|()
operator|.
name|bottomRight
argument_list|()
operator|-
name|moveOffset
expr_stmt|;
ifndef|#
directive|ifndef
name|QT_NO_CURSOR
name|setMouseCursor
argument_list|(
name|mode
argument_list|)
expr_stmt|;
name|widget
operator|->
name|grabMouse
argument_list|(
name|widget
operator|->
name|cursor
argument_list|()
argument_list|)
expr_stmt|;
else|#
directive|else
name|widget
operator|->
name|grabMouse
argument_list|()
expr_stmt|;
endif|#
directive|endif
name|widget
operator|->
name|grabKeyboard
argument_list|()
expr_stmt|;
name|resizeHorizontalDirectionFixed
operator|=
literal|false
expr_stmt|;
name|resizeVerticalDirectionFixed
operator|=
literal|false
expr_stmt|;
block|}
end_function
begin_function
DECL|function|doMove
name|void
name|QWidgetResizeHandler
operator|::
name|doMove
parameter_list|()
block|{
if|if
condition|(
operator|!
name|activeForMove
condition|)
return|return;
name|mode
operator|=
name|Center
expr_stmt|;
name|moveResizeMode
operator|=
literal|true
expr_stmt|;
name|moveOffset
operator|=
name|widget
operator|->
name|mapFromGlobal
argument_list|(
name|QCursor
operator|::
name|pos
argument_list|()
argument_list|)
expr_stmt|;
name|invertedMoveOffset
operator|=
name|widget
operator|->
name|rect
argument_list|()
operator|.
name|bottomRight
argument_list|()
operator|-
name|moveOffset
expr_stmt|;
ifndef|#
directive|ifndef
name|QT_NO_CURSOR
name|widget
operator|->
name|grabMouse
argument_list|(
name|Qt
operator|::
name|SizeAllCursor
argument_list|)
expr_stmt|;
else|#
directive|else
name|widget
operator|->
name|grabMouse
argument_list|()
expr_stmt|;
endif|#
directive|endif
name|widget
operator|->
name|grabKeyboard
argument_list|()
expr_stmt|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|//QT_NO_RESIZEHANDLER
end_comment
end_unit
