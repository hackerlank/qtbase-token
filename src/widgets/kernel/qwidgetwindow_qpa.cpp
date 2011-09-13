begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** No Commercial Usage ** This file contains pre-release code and may not be distributed. ** You may use this file in accordance with the terms and conditions ** contained in the Technology Preview License Agreement accompanying ** this package. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights.  These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** If you have questions regarding the use of this file, please contact ** Nokia at qt-info@nokia.com. ** ** ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qwidgetwindow_qpa_p.h"
end_include
begin_include
include|#
directive|include
file|"private/qwidget_p.h"
end_include
begin_include
include|#
directive|include
file|"private/qapplication_p.h"
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|qt_button_down
name|QWidget
modifier|*
name|qt_button_down
init|=
literal|0
decl_stmt|;
end_decl_stmt
begin_comment
DECL|variable|qt_button_down
comment|// widget got last button-down
end_comment
begin_comment
comment|// popup control
end_comment
begin_decl_stmt
DECL|variable|qt_popup_down
name|QWidget
modifier|*
name|qt_popup_down
init|=
literal|0
decl_stmt|;
end_decl_stmt
begin_comment
DECL|variable|qt_popup_down
comment|// popup that contains the pressed widget
end_comment
begin_decl_stmt
specifier|extern
name|int
name|openPopupCount
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|qt_replay_popup_mouse_event
name|bool
name|qt_replay_popup_mouse_event
init|=
literal|false
decl_stmt|;
end_decl_stmt
begin_function_decl
specifier|extern
name|bool
name|qt_try_modal
parameter_list|(
name|QWidget
modifier|*
name|widget
parameter_list|,
name|QEvent
operator|::
name|Type
name|type
parameter_list|)
function_decl|;
end_function_decl
begin_constructor
DECL|function|QWidgetWindow
name|QWidgetWindow
operator|::
name|QWidgetWindow
parameter_list|(
name|QWidget
modifier|*
name|widget
parameter_list|)
member_init_list|:
name|m_widget
argument_list|(
name|widget
argument_list|)
block|{ }
end_constructor
begin_function
DECL|function|event
name|bool
name|QWidgetWindow
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
name|Close
case|:
name|handleCloseEvent
argument_list|(
cast|static_cast
argument_list|<
name|QCloseEvent
operator|*
argument_list|>
argument_list|(
name|event
argument_list|)
argument_list|)
expr_stmt|;
return|return
literal|true
return|;
case|case
name|QEvent
operator|::
name|Enter
case|:
case|case
name|QEvent
operator|::
name|Leave
case|:
name|handleEnterLeaveEvent
argument_list|(
name|event
argument_list|)
expr_stmt|;
return|return
literal|true
return|;
case|case
name|QEvent
operator|::
name|KeyPress
case|:
case|case
name|QEvent
operator|::
name|KeyRelease
case|:
name|handleKeyEvent
argument_list|(
cast|static_cast
argument_list|<
name|QKeyEvent
operator|*
argument_list|>
argument_list|(
name|event
argument_list|)
argument_list|)
expr_stmt|;
return|return
literal|true
return|;
case|case
name|QEvent
operator|::
name|MouseMove
case|:
case|case
name|QEvent
operator|::
name|MouseButtonPress
case|:
case|case
name|QEvent
operator|::
name|MouseButtonRelease
case|:
case|case
name|QEvent
operator|::
name|MouseButtonDblClick
case|:
name|handleMouseEvent
argument_list|(
cast|static_cast
argument_list|<
name|QMouseEvent
operator|*
argument_list|>
argument_list|(
name|event
argument_list|)
argument_list|)
expr_stmt|;
return|return
literal|true
return|;
case|case
name|QEvent
operator|::
name|TouchBegin
case|:
case|case
name|QEvent
operator|::
name|TouchUpdate
case|:
case|case
name|QEvent
operator|::
name|TouchEnd
case|:
name|handleTouchEvent
argument_list|(
cast|static_cast
argument_list|<
name|QTouchEvent
operator|*
argument_list|>
argument_list|(
name|event
argument_list|)
argument_list|)
expr_stmt|;
return|return
literal|true
return|;
case|case
name|QEvent
operator|::
name|Move
case|:
name|handleMoveEvent
argument_list|(
cast|static_cast
argument_list|<
name|QMoveEvent
operator|*
argument_list|>
argument_list|(
name|event
argument_list|)
argument_list|)
expr_stmt|;
return|return
literal|true
return|;
case|case
name|QEvent
operator|::
name|Resize
case|:
name|handleResizeEvent
argument_list|(
cast|static_cast
argument_list|<
name|QResizeEvent
operator|*
argument_list|>
argument_list|(
name|event
argument_list|)
argument_list|)
expr_stmt|;
return|return
literal|true
return|;
case|case
name|QEvent
operator|::
name|Wheel
case|:
name|handleWheelEvent
argument_list|(
cast|static_cast
argument_list|<
name|QWheelEvent
operator|*
argument_list|>
argument_list|(
name|event
argument_list|)
argument_list|)
expr_stmt|;
return|return
literal|true
return|;
case|case
name|QEvent
operator|::
name|DragEnter
case|:
case|case
name|QEvent
operator|::
name|DragLeave
case|:
case|case
name|QEvent
operator|::
name|DragMove
case|:
case|case
name|QEvent
operator|::
name|Drop
case|:
name|handleDragEvent
argument_list|(
name|event
argument_list|)
expr_stmt|;
break|break;
case|case
name|QEvent
operator|::
name|Map
case|:
name|m_widget
operator|->
name|setAttribute
argument_list|(
name|Qt
operator|::
name|WA_Mapped
argument_list|)
expr_stmt|;
return|return
literal|true
return|;
case|case
name|QEvent
operator|::
name|Unmap
case|:
name|m_widget
operator|->
name|setAttribute
argument_list|(
name|Qt
operator|::
name|WA_Mapped
argument_list|,
literal|false
argument_list|)
expr_stmt|;
return|return
literal|true
return|;
case|case
name|QEvent
operator|::
name|Expose
case|:
name|handleExposeEvent
argument_list|(
cast|static_cast
argument_list|<
name|QExposeEvent
operator|*
argument_list|>
argument_list|(
name|event
argument_list|)
argument_list|)
expr_stmt|;
return|return
literal|true
return|;
case|case
name|QEvent
operator|::
name|WindowStateChange
case|:
name|handleWindowStateChangedEvent
argument_list|(
cast|static_cast
argument_list|<
name|QWindowStateChangeEvent
operator|*
argument_list|>
argument_list|(
name|event
argument_list|)
argument_list|)
expr_stmt|;
return|return
literal|true
return|;
default|default:
break|break;
block|}
return|return
name|m_widget
operator|->
name|event
argument_list|(
name|event
argument_list|)
operator|||
name|QWindow
operator|::
name|event
argument_list|(
name|event
argument_list|)
return|;
block|}
end_function
begin_decl_stmt
DECL|variable|qt_last_mouse_receiver
name|QPointer
argument_list|<
name|QWidget
argument_list|>
name|qt_last_mouse_receiver
init|=
literal|0
decl_stmt|;
end_decl_stmt
begin_function
DECL|function|handleEnterLeaveEvent
name|void
name|QWidgetWindow
operator|::
name|handleEnterLeaveEvent
parameter_list|(
name|QEvent
modifier|*
name|event
parameter_list|)
block|{
if|if
condition|(
name|event
operator|->
name|type
argument_list|()
operator|==
name|QEvent
operator|::
name|Leave
condition|)
block|{
name|QWidget
modifier|*
name|leave
init|=
name|qt_last_mouse_receiver
condition|?
name|qt_last_mouse_receiver
operator|.
name|data
argument_list|()
else|:
name|m_widget
decl_stmt|;
name|QApplicationPrivate
operator|::
name|dispatchEnterLeave
argument_list|(
literal|0
argument_list|,
name|leave
argument_list|)
expr_stmt|;
name|qt_last_mouse_receiver
operator|=
literal|0
expr_stmt|;
block|}
else|else
block|{
name|QApplicationPrivate
operator|::
name|dispatchEnterLeave
argument_list|(
name|m_widget
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|qt_last_mouse_receiver
operator|=
name|m_widget
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|handleMouseEvent
name|void
name|QWidgetWindow
operator|::
name|handleMouseEvent
parameter_list|(
name|QMouseEvent
modifier|*
name|event
parameter_list|)
block|{
if|if
condition|(
name|qApp
operator|->
name|d_func
argument_list|()
operator|->
name|inPopupMode
argument_list|()
condition|)
block|{
name|QWidget
modifier|*
name|activePopupWidget
init|=
name|qApp
operator|->
name|activePopupWidget
argument_list|()
decl_stmt|;
name|QWidget
modifier|*
name|popup
init|=
name|activePopupWidget
decl_stmt|;
name|QPoint
name|mapped
init|=
name|event
operator|->
name|pos
argument_list|()
decl_stmt|;
if|if
condition|(
name|popup
operator|!=
name|m_widget
condition|)
name|mapped
operator|=
name|popup
operator|->
name|mapFromGlobal
argument_list|(
name|event
operator|->
name|globalPos
argument_list|()
argument_list|)
expr_stmt|;
name|bool
name|releaseAfter
init|=
literal|false
decl_stmt|;
name|QWidget
modifier|*
name|popupChild
init|=
name|popup
operator|->
name|childAt
argument_list|(
name|mapped
argument_list|)
decl_stmt|;
if|if
condition|(
name|popup
operator|!=
name|qt_popup_down
condition|)
block|{
name|qt_button_down
operator|=
literal|0
expr_stmt|;
name|qt_popup_down
operator|=
literal|0
expr_stmt|;
block|}
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
name|MouseButtonPress
case|:
case|case
name|QEvent
operator|::
name|MouseButtonDblClick
case|:
name|qt_button_down
operator|=
name|popupChild
expr_stmt|;
name|qt_popup_down
operator|=
name|popup
expr_stmt|;
break|break;
case|case
name|QEvent
operator|::
name|MouseButtonRelease
case|:
name|releaseAfter
operator|=
literal|true
expr_stmt|;
break|break;
default|default:
break|break;
comment|// nothing for mouse move
block|}
name|int
name|oldOpenPopupCount
init|=
name|openPopupCount
decl_stmt|;
if|if
condition|(
name|popup
operator|->
name|isEnabled
argument_list|()
condition|)
block|{
comment|// deliver event
name|qt_replay_popup_mouse_event
operator|=
literal|false
expr_stmt|;
name|QWidget
modifier|*
name|receiver
init|=
name|popup
decl_stmt|;
name|QPoint
name|widgetPos
init|=
name|mapped
decl_stmt|;
if|if
condition|(
name|qt_button_down
condition|)
name|receiver
operator|=
name|qt_button_down
expr_stmt|;
elseif|else
if|if
condition|(
name|popupChild
condition|)
name|receiver
operator|=
name|popupChild
expr_stmt|;
if|if
condition|(
name|receiver
operator|!=
name|popup
condition|)
name|widgetPos
operator|=
name|receiver
operator|->
name|mapFromGlobal
argument_list|(
name|event
operator|->
name|globalPos
argument_list|()
argument_list|)
expr_stmt|;
name|QWidget
modifier|*
name|alien
init|=
name|m_widget
operator|->
name|childAt
argument_list|(
name|m_widget
operator|->
name|mapFromGlobal
argument_list|(
name|event
operator|->
name|globalPos
argument_list|()
argument_list|)
argument_list|)
decl_stmt|;
name|QMouseEvent
name|e
argument_list|(
name|event
operator|->
name|type
argument_list|()
argument_list|,
name|widgetPos
argument_list|,
name|event
operator|->
name|windowPos
argument_list|()
argument_list|,
name|event
operator|->
name|screenPos
argument_list|()
argument_list|,
name|event
operator|->
name|button
argument_list|()
argument_list|,
name|event
operator|->
name|buttons
argument_list|()
argument_list|,
name|event
operator|->
name|modifiers
argument_list|()
argument_list|)
decl_stmt|;
name|e
operator|.
name|setTimestamp
argument_list|(
name|event
operator|->
name|timestamp
argument_list|()
argument_list|)
expr_stmt|;
name|QApplicationPrivate
operator|::
name|sendMouseEvent
argument_list|(
name|receiver
argument_list|,
operator|&
name|e
argument_list|,
name|alien
argument_list|,
name|m_widget
argument_list|,
operator|&
name|qt_button_down
argument_list|,
name|qt_last_mouse_receiver
argument_list|)
expr_stmt|;
block|}
else|else
block|{
comment|// close disabled popups when a mouse button is pressed or released
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
name|MouseButtonPress
case|:
case|case
name|QEvent
operator|::
name|MouseButtonDblClick
case|:
case|case
name|QEvent
operator|::
name|MouseButtonRelease
case|:
name|popup
operator|->
name|close
argument_list|()
expr_stmt|;
break|break;
default|default:
break|break;
block|}
block|}
if|if
condition|(
name|qApp
operator|->
name|activePopupWidget
argument_list|()
operator|!=
name|activePopupWidget
operator|&&
name|qt_replay_popup_mouse_event
condition|)
block|{
if|if
condition|(
name|m_widget
operator|->
name|windowType
argument_list|()
operator|!=
name|Qt
operator|::
name|Popup
condition|)
name|qt_button_down
operator|=
literal|0
expr_stmt|;
name|qt_replay_popup_mouse_event
operator|=
literal|false
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|event
operator|->
name|type
argument_list|()
operator|==
name|QEvent
operator|::
name|MouseButtonPress
operator|&&
name|event
operator|->
name|button
argument_list|()
operator|==
name|Qt
operator|::
name|RightButton
operator|&&
operator|(
name|openPopupCount
operator|==
name|oldOpenPopupCount
operator|)
condition|)
block|{
name|QWidget
modifier|*
name|popupEvent
init|=
name|popup
decl_stmt|;
if|if
condition|(
name|qt_button_down
condition|)
name|popupEvent
operator|=
name|qt_button_down
expr_stmt|;
elseif|else
if|if
condition|(
name|popupChild
condition|)
name|popupEvent
operator|=
name|popupChild
expr_stmt|;
name|QContextMenuEvent
name|e
argument_list|(
name|QContextMenuEvent
operator|::
name|Mouse
argument_list|,
name|mapped
argument_list|,
name|event
operator|->
name|globalPos
argument_list|()
argument_list|,
name|event
operator|->
name|modifiers
argument_list|()
argument_list|)
decl_stmt|;
name|QApplication
operator|::
name|sendSpontaneousEvent
argument_list|(
name|popupEvent
argument_list|,
operator|&
name|e
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|releaseAfter
condition|)
block|{
name|qt_button_down
operator|=
literal|0
expr_stmt|;
name|qt_popup_down
operator|=
literal|0
expr_stmt|;
block|}
return|return;
block|}
comment|// modal event handling
if|if
condition|(
name|QApplicationPrivate
operator|::
name|instance
argument_list|()
operator|->
name|modalState
argument_list|()
operator|&&
operator|!
name|qt_try_modal
argument_list|(
name|m_widget
argument_list|,
name|event
operator|->
name|type
argument_list|()
argument_list|)
condition|)
return|return;
comment|// which child should have it?
name|QWidget
modifier|*
name|widget
init|=
name|m_widget
operator|->
name|childAt
argument_list|(
name|event
operator|->
name|pos
argument_list|()
argument_list|)
decl_stmt|;
name|QPoint
name|mapped
init|=
name|event
operator|->
name|pos
argument_list|()
decl_stmt|;
if|if
condition|(
name|widget
condition|)
block|{
name|mapped
operator|=
name|widget
operator|->
name|mapFrom
argument_list|(
name|m_widget
argument_list|,
name|event
operator|->
name|pos
argument_list|()
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|widget
operator|=
name|m_widget
expr_stmt|;
block|}
if|if
condition|(
name|event
operator|->
name|type
argument_list|()
operator|==
name|QEvent
operator|::
name|MouseButtonPress
operator|&&
operator|!
name|qt_button_down
condition|)
name|qt_button_down
operator|=
name|widget
expr_stmt|;
name|QWidget
modifier|*
name|receiver
init|=
name|QApplicationPrivate
operator|::
name|pickMouseReceiver
argument_list|(
name|m_widget
argument_list|,
name|event
operator|->
name|globalPos
argument_list|()
argument_list|,
name|mapped
argument_list|,
name|event
operator|->
name|type
argument_list|()
argument_list|,
name|event
operator|->
name|buttons
argument_list|()
argument_list|,
name|qt_button_down
argument_list|,
name|widget
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|receiver
condition|)
block|{
if|if
condition|(
name|event
operator|->
name|type
argument_list|()
operator|==
name|QEvent
operator|::
name|MouseButtonRelease
condition|)
name|QApplicationPrivate
operator|::
name|mouse_buttons
operator|&=
operator|~
name|event
operator|->
name|button
argument_list|()
expr_stmt|;
return|return;
block|}
name|QMouseEvent
name|translated
argument_list|(
name|event
operator|->
name|type
argument_list|()
argument_list|,
name|mapped
argument_list|,
name|event
operator|->
name|windowPos
argument_list|()
argument_list|,
name|event
operator|->
name|screenPos
argument_list|()
argument_list|,
name|event
operator|->
name|button
argument_list|()
argument_list|,
name|event
operator|->
name|buttons
argument_list|()
argument_list|,
name|event
operator|->
name|modifiers
argument_list|()
argument_list|)
decl_stmt|;
name|translated
operator|.
name|setTimestamp
argument_list|(
name|event
operator|->
name|timestamp
argument_list|()
argument_list|)
expr_stmt|;
name|QApplicationPrivate
operator|::
name|sendMouseEvent
argument_list|(
name|receiver
argument_list|,
operator|&
name|translated
argument_list|,
name|widget
argument_list|,
name|m_widget
argument_list|,
operator|&
name|qt_button_down
argument_list|,
name|qt_last_mouse_receiver
argument_list|)
expr_stmt|;
if|if
condition|(
name|event
operator|->
name|type
argument_list|()
operator|==
name|QEvent
operator|::
name|MouseButtonPress
operator|&&
name|event
operator|->
name|button
argument_list|()
operator|==
name|Qt
operator|::
name|RightButton
condition|)
block|{
name|QContextMenuEvent
name|e
argument_list|(
name|QContextMenuEvent
operator|::
name|Mouse
argument_list|,
name|mapped
argument_list|,
name|event
operator|->
name|globalPos
argument_list|()
argument_list|,
name|event
operator|->
name|modifiers
argument_list|()
argument_list|)
decl_stmt|;
name|QGuiApplication
operator|::
name|sendSpontaneousEvent
argument_list|(
name|receiver
argument_list|,
operator|&
name|e
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|handleTouchEvent
name|void
name|QWidgetWindow
operator|::
name|handleTouchEvent
parameter_list|(
name|QTouchEvent
modifier|*
name|event
parameter_list|)
block|{
name|QApplicationPrivate
operator|::
name|translateRawTouchEvent
argument_list|(
name|m_widget
argument_list|,
name|event
operator|->
name|deviceType
argument_list|()
argument_list|,
name|event
operator|->
name|touchPoints
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|handleKeyEvent
name|void
name|QWidgetWindow
operator|::
name|handleKeyEvent
parameter_list|(
name|QKeyEvent
modifier|*
name|event
parameter_list|)
block|{
if|if
condition|(
name|QApplicationPrivate
operator|::
name|instance
argument_list|()
operator|->
name|modalState
argument_list|()
operator|&&
operator|!
name|qt_try_modal
argument_list|(
name|m_widget
argument_list|,
name|event
operator|->
name|type
argument_list|()
argument_list|)
condition|)
return|return;
name|QWidget
modifier|*
name|widget
init|=
name|m_widget
operator|->
name|focusWidget
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
name|widget
condition|)
name|widget
operator|=
name|m_widget
expr_stmt|;
name|QGuiApplication
operator|::
name|sendSpontaneousEvent
argument_list|(
name|widget
argument_list|,
name|event
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|updateGeometry
name|void
name|QWidgetWindow
operator|::
name|updateGeometry
parameter_list|()
block|{
if|if
condition|(
name|m_widget
operator|->
name|testAttribute
argument_list|(
name|Qt
operator|::
name|WA_OutsideWSRange
argument_list|)
condition|)
return|return;
name|QMargins
name|margins
init|=
name|frameMargins
argument_list|()
decl_stmt|;
name|m_widget
operator|->
name|data
operator|->
name|crect
operator|=
name|geometry
argument_list|()
expr_stmt|;
name|m_widget
operator|->
name|d_func
argument_list|()
operator|->
name|topData
argument_list|()
operator|->
name|frameStrut
operator|.
name|setCoords
argument_list|(
name|margins
operator|.
name|left
argument_list|()
argument_list|,
name|margins
operator|.
name|top
argument_list|()
argument_list|,
name|margins
operator|.
name|right
argument_list|()
argument_list|,
name|margins
operator|.
name|bottom
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|handleMoveEvent
name|void
name|QWidgetWindow
operator|::
name|handleMoveEvent
parameter_list|(
name|QMoveEvent
modifier|*
name|event
parameter_list|)
block|{
name|updateGeometry
argument_list|()
expr_stmt|;
name|QGuiApplication
operator|::
name|sendSpontaneousEvent
argument_list|(
name|m_widget
argument_list|,
name|event
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|handleResizeEvent
name|void
name|QWidgetWindow
operator|::
name|handleResizeEvent
parameter_list|(
name|QResizeEvent
modifier|*
name|event
parameter_list|)
block|{
name|QSize
name|oldSize
init|=
name|m_widget
operator|->
name|data
operator|->
name|crect
operator|.
name|size
argument_list|()
decl_stmt|;
name|updateGeometry
argument_list|()
expr_stmt|;
name|QGuiApplication
operator|::
name|sendSpontaneousEvent
argument_list|(
name|m_widget
argument_list|,
name|event
argument_list|)
expr_stmt|;
if|if
condition|(
name|m_widget
operator|->
name|d_func
argument_list|()
operator|->
name|paintOnScreen
argument_list|()
condition|)
block|{
name|QRegion
name|updateRegion
argument_list|(
name|geometry
argument_list|()
argument_list|)
decl_stmt|;
if|if
condition|(
name|m_widget
operator|->
name|testAttribute
argument_list|(
name|Qt
operator|::
name|WA_StaticContents
argument_list|)
condition|)
name|updateRegion
operator|-=
name|QRect
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
name|oldSize
operator|.
name|width
argument_list|()
argument_list|,
name|oldSize
operator|.
name|height
argument_list|()
argument_list|)
expr_stmt|;
name|m_widget
operator|->
name|d_func
argument_list|()
operator|->
name|syncBackingStore
argument_list|(
name|updateRegion
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|m_widget
operator|->
name|d_func
argument_list|()
operator|->
name|syncBackingStore
argument_list|()
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|handleCloseEvent
name|void
name|QWidgetWindow
operator|::
name|handleCloseEvent
parameter_list|(
name|QCloseEvent
modifier|*
parameter_list|)
block|{
name|m_widget
operator|->
name|d_func
argument_list|()
operator|->
name|close_helper
argument_list|(
name|QWidgetPrivate
operator|::
name|CloseWithSpontaneousEvent
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|handleWheelEvent
name|void
name|QWidgetWindow
operator|::
name|handleWheelEvent
parameter_list|(
name|QWheelEvent
modifier|*
name|event
parameter_list|)
block|{
if|if
condition|(
name|QApplicationPrivate
operator|::
name|instance
argument_list|()
operator|->
name|modalState
argument_list|()
operator|&&
operator|!
name|qt_try_modal
argument_list|(
name|m_widget
argument_list|,
name|event
operator|->
name|type
argument_list|()
argument_list|)
condition|)
return|return;
comment|// which child should have it?
name|QWidget
modifier|*
name|widget
init|=
name|m_widget
operator|->
name|childAt
argument_list|(
name|event
operator|->
name|pos
argument_list|()
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|widget
condition|)
name|widget
operator|=
name|m_widget
expr_stmt|;
name|QPoint
name|mapped
init|=
name|widget
operator|->
name|mapFrom
argument_list|(
name|m_widget
argument_list|,
name|event
operator|->
name|pos
argument_list|()
argument_list|)
decl_stmt|;
name|QWheelEvent
name|translated
argument_list|(
name|mapped
argument_list|,
name|event
operator|->
name|globalPos
argument_list|()
argument_list|,
name|event
operator|->
name|delta
argument_list|()
argument_list|,
name|event
operator|->
name|buttons
argument_list|()
argument_list|,
name|event
operator|->
name|modifiers
argument_list|()
argument_list|,
name|event
operator|->
name|orientation
argument_list|()
argument_list|)
decl_stmt|;
name|QGuiApplication
operator|::
name|sendSpontaneousEvent
argument_list|(
name|widget
argument_list|,
operator|&
name|translated
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|handleDragEvent
name|void
name|QWidgetWindow
operator|::
name|handleDragEvent
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
name|DragEnter
case|:
name|Q_ASSERT
argument_list|(
operator|!
name|m_dragTarget
argument_list|)
expr_stmt|;
comment|// fall through
case|case
name|QEvent
operator|::
name|DragMove
case|:
block|{
name|QDragMoveEvent
modifier|*
name|de
init|=
cast|static_cast
argument_list|<
name|QDragMoveEvent
operator|*
argument_list|>
argument_list|(
name|event
argument_list|)
decl_stmt|;
name|QWidget
modifier|*
name|widget
init|=
name|m_widget
operator|->
name|childAt
argument_list|(
name|de
operator|->
name|pos
argument_list|()
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|widget
condition|)
name|widget
operator|=
name|m_widget
expr_stmt|;
if|if
condition|(
name|widget
operator|!=
name|m_dragTarget
operator|.
name|data
argument_list|()
condition|)
block|{
if|if
condition|(
name|m_dragTarget
operator|.
name|data
argument_list|()
condition|)
block|{
name|QDragLeaveEvent
name|le
decl_stmt|;
name|QGuiApplication
operator|::
name|sendSpontaneousEvent
argument_list|(
name|m_dragTarget
operator|.
name|data
argument_list|()
argument_list|,
operator|&
name|le
argument_list|)
expr_stmt|;
block|}
name|m_dragTarget
operator|=
name|widget
expr_stmt|;
name|QPoint
name|mapped
init|=
name|widget
operator|->
name|mapFrom
argument_list|(
name|m_widget
argument_list|,
name|de
operator|->
name|pos
argument_list|()
argument_list|)
decl_stmt|;
name|QDragEnterEvent
name|translated
argument_list|(
name|mapped
argument_list|,
name|de
operator|->
name|possibleActions
argument_list|()
argument_list|,
name|de
operator|->
name|mimeData
argument_list|()
argument_list|,
name|de
operator|->
name|mouseButtons
argument_list|()
argument_list|,
name|de
operator|->
name|keyboardModifiers
argument_list|()
argument_list|)
decl_stmt|;
name|QGuiApplication
operator|::
name|sendSpontaneousEvent
argument_list|(
name|widget
argument_list|,
operator|&
name|translated
argument_list|)
expr_stmt|;
if|if
condition|(
name|translated
operator|.
name|isAccepted
argument_list|()
condition|)
name|event
operator|->
name|accept
argument_list|()
expr_stmt|;
name|de
operator|->
name|setDropAction
argument_list|(
name|translated
operator|.
name|dropAction
argument_list|()
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|Q_ASSERT
argument_list|(
name|event
operator|->
name|type
argument_list|()
operator|==
name|QEvent
operator|::
name|DragMove
argument_list|)
expr_stmt|;
name|QPoint
name|mapped
init|=
name|widget
operator|->
name|mapFrom
argument_list|(
name|m_widget
argument_list|,
name|de
operator|->
name|pos
argument_list|()
argument_list|)
decl_stmt|;
name|QDragMoveEvent
name|translated
argument_list|(
name|mapped
argument_list|,
name|de
operator|->
name|possibleActions
argument_list|()
argument_list|,
name|de
operator|->
name|mimeData
argument_list|()
argument_list|,
name|de
operator|->
name|mouseButtons
argument_list|()
argument_list|,
name|de
operator|->
name|keyboardModifiers
argument_list|()
argument_list|)
decl_stmt|;
name|translated
operator|.
name|setDropAction
argument_list|(
name|de
operator|->
name|dropAction
argument_list|()
argument_list|)
expr_stmt|;
name|QGuiApplication
operator|::
name|sendSpontaneousEvent
argument_list|(
name|widget
argument_list|,
operator|&
name|translated
argument_list|)
expr_stmt|;
if|if
condition|(
name|translated
operator|.
name|isAccepted
argument_list|()
condition|)
name|event
operator|->
name|accept
argument_list|()
expr_stmt|;
name|de
operator|->
name|setDropAction
argument_list|(
name|translated
operator|.
name|dropAction
argument_list|()
argument_list|)
expr_stmt|;
block|}
break|break;
block|}
case|case
name|QEvent
operator|::
name|DragLeave
case|:
if|if
condition|(
name|m_dragTarget
condition|)
name|QGuiApplication
operator|::
name|sendSpontaneousEvent
argument_list|(
name|m_dragTarget
operator|.
name|data
argument_list|()
argument_list|,
name|event
argument_list|)
expr_stmt|;
name|m_dragTarget
operator|=
operator|(
name|QWidget
operator|*
operator|)
literal|0
expr_stmt|;
break|break;
case|case
name|QEvent
operator|::
name|Drop
case|:
block|{
name|QDropEvent
modifier|*
name|de
init|=
cast|static_cast
argument_list|<
name|QDropEvent
operator|*
argument_list|>
argument_list|(
name|event
argument_list|)
decl_stmt|;
name|QPoint
name|mapped
init|=
name|m_dragTarget
operator|.
name|data
argument_list|()
operator|->
name|mapFrom
argument_list|(
name|m_widget
argument_list|,
name|de
operator|->
name|pos
argument_list|()
argument_list|)
decl_stmt|;
name|QDropEvent
name|translated
argument_list|(
name|mapped
argument_list|,
name|de
operator|->
name|possibleActions
argument_list|()
argument_list|,
name|de
operator|->
name|mimeData
argument_list|()
argument_list|,
name|de
operator|->
name|mouseButtons
argument_list|()
argument_list|,
name|de
operator|->
name|keyboardModifiers
argument_list|()
argument_list|)
decl_stmt|;
name|QGuiApplication
operator|::
name|sendSpontaneousEvent
argument_list|(
name|m_dragTarget
operator|.
name|data
argument_list|()
argument_list|,
operator|&
name|translated
argument_list|)
expr_stmt|;
if|if
condition|(
name|translated
operator|.
name|isAccepted
argument_list|()
condition|)
name|event
operator|->
name|accept
argument_list|()
expr_stmt|;
name|de
operator|->
name|setDropAction
argument_list|(
name|translated
operator|.
name|dropAction
argument_list|()
argument_list|)
expr_stmt|;
name|m_dragTarget
operator|=
operator|(
name|QWidget
operator|*
operator|)
literal|0
expr_stmt|;
block|}
default|default:
break|break;
block|}
block|}
end_function
begin_function
DECL|function|handleExposeEvent
name|void
name|QWidgetWindow
operator|::
name|handleExposeEvent
parameter_list|(
name|QExposeEvent
modifier|*
name|event
parameter_list|)
block|{
name|m_widget
operator|->
name|d_func
argument_list|()
operator|->
name|syncBackingStore
argument_list|(
name|event
operator|->
name|region
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|handleWindowStateChangedEvent
name|void
name|QWidgetWindow
operator|::
name|handleWindowStateChangedEvent
parameter_list|(
name|QWindowStateChangeEvent
modifier|*
name|event
parameter_list|)
block|{
comment|// QWindow does currently not know 'active'.
name|Qt
operator|::
name|WindowStates
name|eventState
init|=
name|event
operator|->
name|oldState
argument_list|()
decl_stmt|;
if|if
condition|(
name|m_widget
operator|->
name|windowState
argument_list|()
operator|&
name|Qt
operator|::
name|WindowActive
condition|)
name|eventState
operator||=
name|Qt
operator|::
name|WindowActive
expr_stmt|;
name|QWindowStateChangeEvent
name|widgetEvent
argument_list|(
name|eventState
argument_list|)
decl_stmt|;
name|QGuiApplication
operator|::
name|sendSpontaneousEvent
argument_list|(
name|m_widget
argument_list|,
operator|&
name|widgetEvent
argument_list|)
expr_stmt|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
