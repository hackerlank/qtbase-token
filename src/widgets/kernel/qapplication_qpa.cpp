begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qapplication_p.h"
end_include
begin_include
include|#
directive|include
file|"qcolormap.h"
end_include
begin_include
include|#
directive|include
file|"qpalette.h"
end_include
begin_include
include|#
directive|include
file|"qpixmapcache.h"
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_CURSOR
end_ifndef
begin_include
include|#
directive|include
file|"private/qcursor_p.h"
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_include
include|#
directive|include
file|"qscreen.h"
end_include
begin_include
include|#
directive|include
file|"private/qwidget_p.h"
end_include
begin_include
include|#
directive|include
file|"private/qevent_p.h"
end_include
begin_include
include|#
directive|include
file|"qgenericpluginfactory_qpa.h"
end_include
begin_include
include|#
directive|include
file|"private/qplatformintegrationfactory_qpa_p.h"
end_include
begin_include
include|#
directive|include
file|<qdesktopwidget.h>
end_include
begin_include
include|#
directive|include
file|<QPlatformCursor>
end_include
begin_include
include|#
directive|include
file|<QPlatformTheme>
end_include
begin_include
include|#
directive|include
file|<qdebug.h>
end_include
begin_include
include|#
directive|include
file|<QWindowSystemInterface>
end_include
begin_include
include|#
directive|include
file|"private/qwindowsysteminterface_qpa_p.h"
end_include
begin_include
include|#
directive|include
file|<QPlatformIntegration>
end_include
begin_include
include|#
directive|include
file|"qdesktopwidget_qpa_p.h"
end_include
begin_include
include|#
directive|include
file|"qwidgetwindow_qpa_p.h"
end_include
begin_include
include|#
directive|include
file|"qtooltip.h"
end_include
begin_ifdef
ifdef|#
directive|ifdef
name|Q_OS_WIN
end_ifdef
begin_include
include|#
directive|include
file|<QtCore/qt_windows.h>
end_include
begin_comment
comment|// for qt_win_display_dc()
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|appName
specifier|static
name|QString
name|appName
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|appFont
specifier|static
name|QString
name|appFont
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|popupGrabOk
specifier|static
name|bool
name|popupGrabOk
decl_stmt|;
end_decl_stmt
begin_decl_stmt
specifier|extern
name|bool
name|app_do_modal
decl_stmt|;
end_decl_stmt
begin_decl_stmt
specifier|extern
name|QWidgetList
modifier|*
name|qt_modal_stack
decl_stmt|;
end_decl_stmt
begin_decl_stmt
specifier|extern
name|QWidget
modifier|*
name|qt_button_down
decl_stmt|;
end_decl_stmt
begin_decl_stmt
specifier|extern
name|QWidget
modifier|*
name|qt_popup_down
decl_stmt|;
end_decl_stmt
begin_decl_stmt
specifier|extern
name|bool
name|qt_replay_popup_mouse_event
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|openPopupCount
name|int
name|openPopupCount
init|=
literal|0
decl_stmt|;
end_decl_stmt
begin_function
DECL|function|appName
name|QString
name|QApplicationPrivate
operator|::
name|appName
parameter_list|()
specifier|const
block|{
return|return
name|QT_PREPEND_NAMESPACE
argument_list|(
name|appName
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|createEventDispatcher
name|void
name|QApplicationPrivate
operator|::
name|createEventDispatcher
parameter_list|()
block|{
name|QGuiApplicationPrivate
operator|::
name|createEventDispatcher
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|qt_try_modal
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
block|{
name|QWidget
modifier|*
name|top
init|=
literal|0
decl_stmt|;
if|if
condition|(
name|QApplicationPrivate
operator|::
name|tryModalHelper
argument_list|(
name|widget
argument_list|,
operator|&
name|top
argument_list|)
condition|)
return|return
literal|true
return|;
name|bool
name|block_event
init|=
literal|false
decl_stmt|;
name|bool
name|paint_event
init|=
literal|false
decl_stmt|;
switch|switch
condition|(
name|type
condition|)
block|{
if|#
directive|if
literal|0
block|case QEvent::Focus:         if (!static_cast<QWSFocusEvent*>(event)->simpleData.get_focus)             break;
comment|// drop through
endif|#
directive|endif
case|case
name|QEvent
operator|::
name|MouseButtonPress
case|:
comment|// disallow mouse/key events
case|case
name|QEvent
operator|::
name|MouseButtonRelease
case|:
case|case
name|QEvent
operator|::
name|MouseMove
case|:
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
name|block_event
operator|=
literal|true
expr_stmt|;
break|break;
default|default:
break|break;
block|}
if|if
condition|(
operator|(
name|block_event
operator|||
name|paint_event
operator|)
operator|&&
name|top
operator|->
name|parentWidget
argument_list|()
operator|==
literal|0
condition|)
name|top
operator|->
name|raise
argument_list|()
expr_stmt|;
return|return
operator|!
name|block_event
return|;
block|}
end_function
begin_function
DECL|function|enterModal_sys
name|void
name|QApplicationPrivate
operator|::
name|enterModal_sys
parameter_list|(
name|QWidget
modifier|*
name|widget
parameter_list|)
block|{
if|if
condition|(
operator|!
name|qt_modal_stack
condition|)
name|qt_modal_stack
operator|=
operator|new
name|QWidgetList
expr_stmt|;
name|qt_modal_stack
operator|->
name|insert
argument_list|(
literal|0
argument_list|,
name|widget
argument_list|)
expr_stmt|;
name|app_do_modal
operator|=
literal|true
expr_stmt|;
block|}
end_function
begin_function
DECL|function|leaveModal_sys
name|void
name|QApplicationPrivate
operator|::
name|leaveModal_sys
parameter_list|(
name|QWidget
modifier|*
name|widget
parameter_list|)
block|{
if|if
condition|(
name|qt_modal_stack
operator|&&
name|qt_modal_stack
operator|->
name|removeAll
argument_list|(
name|widget
argument_list|)
condition|)
block|{
if|if
condition|(
name|qt_modal_stack
operator|->
name|isEmpty
argument_list|()
condition|)
block|{
operator|delete
name|qt_modal_stack
expr_stmt|;
name|qt_modal_stack
operator|=
literal|0
expr_stmt|;
block|}
block|}
name|app_do_modal
operator|=
name|qt_modal_stack
operator|!=
literal|0
expr_stmt|;
block|}
end_function
begin_function
DECL|function|modalState
name|bool
name|QApplicationPrivate
operator|::
name|modalState
parameter_list|()
block|{
return|return
name|app_do_modal
return|;
block|}
end_function
begin_function
DECL|function|qt_tlw_for_window
name|QWidget
modifier|*
name|qt_tlw_for_window
parameter_list|(
name|QWindow
modifier|*
name|wnd
parameter_list|)
block|{
if|if
condition|(
name|wnd
condition|)
foreach|foreach
control|(
name|QWidget
modifier|*
name|tlw
decl|,
name|qApp
operator|->
name|topLevelWidgets
argument_list|()
control|)
if|if
condition|(
name|tlw
operator|->
name|windowHandle
argument_list|()
operator|==
name|wnd
condition|)
return|return
name|tlw
return|;
return|return
literal|0
return|;
block|}
end_function
begin_function
DECL|function|notifyActiveWindowChange
name|void
name|QApplicationPrivate
operator|::
name|notifyActiveWindowChange
parameter_list|(
name|QWindow
modifier|*
name|previous
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
name|previous
argument_list|)
expr_stmt|;
name|Q_Q
argument_list|(
name|QApplication
argument_list|)
expr_stmt|;
name|QWindow
modifier|*
name|wnd
init|=
name|QGuiApplicationPrivate
operator|::
name|focus_window
decl_stmt|;
if|if
condition|(
name|inPopupMode
argument_list|()
condition|)
comment|// some delayed focus event to ignore
return|return;
name|QWidget
modifier|*
name|tlw
init|=
name|qt_tlw_for_window
argument_list|(
name|wnd
argument_list|)
decl_stmt|;
name|q
operator|->
name|setActiveWindow
argument_list|(
name|tlw
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|ungrabKeyboardForPopup
specifier|static
name|void
name|ungrabKeyboardForPopup
parameter_list|(
name|QWidget
modifier|*
name|popup
parameter_list|)
block|{
if|if
condition|(
name|QWidget
operator|::
name|keyboardGrabber
argument_list|()
condition|)
name|qt_widget_private
argument_list|(
name|QWidget
operator|::
name|keyboardGrabber
argument_list|()
argument_list|)
operator|->
name|stealKeyboardGrab
argument_list|(
literal|true
argument_list|)
expr_stmt|;
else|else
name|qt_widget_private
argument_list|(
name|popup
argument_list|)
operator|->
name|stealKeyboardGrab
argument_list|(
literal|false
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|ungrabMouseForPopup
specifier|static
name|void
name|ungrabMouseForPopup
parameter_list|(
name|QWidget
modifier|*
name|popup
parameter_list|)
block|{
if|if
condition|(
name|QWidget
operator|::
name|mouseGrabber
argument_list|()
condition|)
name|qt_widget_private
argument_list|(
name|QWidget
operator|::
name|mouseGrabber
argument_list|()
argument_list|)
operator|->
name|stealMouseGrab
argument_list|(
literal|true
argument_list|)
expr_stmt|;
else|else
name|qt_widget_private
argument_list|(
name|popup
argument_list|)
operator|->
name|stealMouseGrab
argument_list|(
literal|false
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|grabForPopup
specifier|static
name|void
name|grabForPopup
parameter_list|(
name|QWidget
modifier|*
name|popup
parameter_list|)
block|{
name|Q_ASSERT
argument_list|(
name|popup
operator|->
name|testAttribute
argument_list|(
name|Qt
operator|::
name|WA_WState_Created
argument_list|)
argument_list|)
expr_stmt|;
name|popupGrabOk
operator|=
name|qt_widget_private
argument_list|(
name|popup
argument_list|)
operator|->
name|stealKeyboardGrab
argument_list|(
literal|true
argument_list|)
expr_stmt|;
if|if
condition|(
name|popupGrabOk
condition|)
block|{
name|popupGrabOk
operator|=
name|qt_widget_private
argument_list|(
name|popup
argument_list|)
operator|->
name|stealMouseGrab
argument_list|(
literal|true
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|popupGrabOk
condition|)
block|{
comment|// transfer grab back to the keyboard grabber if any
name|ungrabKeyboardForPopup
argument_list|(
name|popup
argument_list|)
expr_stmt|;
block|}
block|}
block|}
end_function
begin_function
DECL|function|closePopup
name|void
name|QApplicationPrivate
operator|::
name|closePopup
parameter_list|(
name|QWidget
modifier|*
name|popup
parameter_list|)
block|{
name|Q_Q
argument_list|(
name|QApplication
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|popupWidgets
condition|)
return|return;
name|popupWidgets
operator|->
name|removeAll
argument_list|(
name|popup
argument_list|)
expr_stmt|;
if|if
condition|(
name|popup
operator|==
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
if|if
condition|(
name|QApplicationPrivate
operator|::
name|popupWidgets
operator|->
name|count
argument_list|()
operator|==
literal|0
condition|)
block|{
comment|// this was the last popup
operator|delete
name|QApplicationPrivate
operator|::
name|popupWidgets
expr_stmt|;
name|QApplicationPrivate
operator|::
name|popupWidgets
operator|=
literal|0
expr_stmt|;
if|if
condition|(
name|popupGrabOk
condition|)
block|{
name|popupGrabOk
operator|=
literal|false
expr_stmt|;
if|if
condition|(
name|popup
operator|->
name|geometry
argument_list|()
operator|.
name|contains
argument_list|(
name|QPoint
argument_list|(
name|QGuiApplicationPrivate
operator|::
name|mousePressX
argument_list|,
name|QGuiApplicationPrivate
operator|::
name|mousePressY
argument_list|)
argument_list|)
operator|||
name|popup
operator|->
name|testAttribute
argument_list|(
name|Qt
operator|::
name|WA_NoMouseReplay
argument_list|)
condition|)
block|{
comment|// mouse release event or inside
name|qt_replay_popup_mouse_event
operator|=
literal|false
expr_stmt|;
block|}
else|else
block|{
comment|// mouse press event
name|QGuiApplicationPrivate
operator|::
name|mousePressTime
operator|-=
literal|10000
expr_stmt|;
comment|// avoid double click
name|qt_replay_popup_mouse_event
operator|=
literal|true
expr_stmt|;
block|}
comment|// transfer grab back to mouse grabber if any, otherwise release the grab
name|ungrabMouseForPopup
argument_list|(
name|popup
argument_list|)
expr_stmt|;
comment|// transfer grab back to keyboard grabber if any, otherwise release the grab
name|ungrabKeyboardForPopup
argument_list|(
name|popup
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|active_window
condition|)
block|{
if|if
condition|(
name|QWidget
modifier|*
name|fw
init|=
name|active_window
operator|->
name|focusWidget
argument_list|()
condition|)
block|{
if|if
condition|(
name|fw
operator|!=
name|QApplication
operator|::
name|focusWidget
argument_list|()
condition|)
block|{
name|fw
operator|->
name|setFocus
argument_list|(
name|Qt
operator|::
name|PopupFocusReason
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|QFocusEvent
name|e
argument_list|(
name|QEvent
operator|::
name|FocusIn
argument_list|,
name|Qt
operator|::
name|PopupFocusReason
argument_list|)
decl_stmt|;
name|q
operator|->
name|sendEvent
argument_list|(
name|fw
argument_list|,
operator|&
name|e
argument_list|)
expr_stmt|;
block|}
block|}
block|}
block|}
else|else
block|{
comment|// A popup was closed, so the previous popup gets the focus.
name|QWidget
modifier|*
name|aw
init|=
name|QApplicationPrivate
operator|::
name|popupWidgets
operator|->
name|last
argument_list|()
decl_stmt|;
if|if
condition|(
name|QWidget
modifier|*
name|fw
init|=
name|aw
operator|->
name|focusWidget
argument_list|()
condition|)
name|fw
operator|->
name|setFocus
argument_list|(
name|Qt
operator|::
name|PopupFocusReason
argument_list|)
expr_stmt|;
if|if
condition|(
name|QApplicationPrivate
operator|::
name|popupWidgets
operator|->
name|count
argument_list|()
operator|==
literal|1
condition|)
comment|// grab mouse/keyboard
name|grabForPopup
argument_list|(
name|aw
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|openPopup
name|void
name|QApplicationPrivate
operator|::
name|openPopup
parameter_list|(
name|QWidget
modifier|*
name|popup
parameter_list|)
block|{
name|openPopupCount
operator|++
expr_stmt|;
if|if
condition|(
operator|!
name|popupWidgets
condition|)
comment|// create list
name|popupWidgets
operator|=
operator|new
name|QWidgetList
expr_stmt|;
name|popupWidgets
operator|->
name|append
argument_list|(
name|popup
argument_list|)
expr_stmt|;
comment|// add to end of list
if|if
condition|(
name|QApplicationPrivate
operator|::
name|popupWidgets
operator|->
name|count
argument_list|()
operator|==
literal|1
condition|)
comment|// grab mouse/keyboard
name|grabForPopup
argument_list|(
name|popup
argument_list|)
expr_stmt|;
comment|// popups are not focus-handled by the window system (the first
comment|// popup grabbed the keyboard), so we have to do that manually: A
comment|// new popup gets the focus
if|if
condition|(
name|popup
operator|->
name|focusWidget
argument_list|()
condition|)
block|{
name|popup
operator|->
name|focusWidget
argument_list|()
operator|->
name|setFocus
argument_list|(
name|Qt
operator|::
name|PopupFocusReason
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|popupWidgets
operator|->
name|count
argument_list|()
operator|==
literal|1
condition|)
block|{
comment|// this was the first popup
if|if
condition|(
name|QWidget
modifier|*
name|fw
init|=
name|QApplication
operator|::
name|focusWidget
argument_list|()
condition|)
block|{
name|QFocusEvent
name|e
argument_list|(
name|QEvent
operator|::
name|FocusOut
argument_list|,
name|Qt
operator|::
name|PopupFocusReason
argument_list|)
decl_stmt|;
name|QApplication
operator|::
name|sendEvent
argument_list|(
name|fw
argument_list|,
operator|&
name|e
argument_list|)
expr_stmt|;
block|}
block|}
block|}
end_function
begin_function
DECL|function|initializeMultitouch_sys
name|void
name|QApplicationPrivate
operator|::
name|initializeMultitouch_sys
parameter_list|()
block|{ }
end_function
begin_function
DECL|function|cleanupMultitouch_sys
name|void
name|QApplicationPrivate
operator|::
name|cleanupMultitouch_sys
parameter_list|()
block|{ }
end_function
begin_function
DECL|function|setPossiblePalette
specifier|static
name|void
name|setPossiblePalette
parameter_list|(
specifier|const
name|QPalette
modifier|*
name|palette
parameter_list|,
specifier|const
name|char
modifier|*
name|className
parameter_list|)
block|{
if|if
condition|(
name|palette
operator|==
literal|0
condition|)
return|return;
name|QApplicationPrivate
operator|::
name|setPalette_helper
argument_list|(
operator|*
name|palette
argument_list|,
name|className
argument_list|,
literal|false
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|initializeWidgetPaletteHash
name|void
name|QApplicationPrivate
operator|::
name|initializeWidgetPaletteHash
parameter_list|()
block|{
name|QPlatformTheme
modifier|*
name|platformTheme
init|=
name|QGuiApplicationPrivate
operator|::
name|platformTheme
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
name|platformTheme
condition|)
return|return;
name|setPossiblePalette
argument_list|(
name|platformTheme
operator|->
name|palette
argument_list|(
name|QPlatformTheme
operator|::
name|ToolButtonPalette
argument_list|)
argument_list|,
literal|"QToolButton"
argument_list|)
expr_stmt|;
name|setPossiblePalette
argument_list|(
name|platformTheme
operator|->
name|palette
argument_list|(
name|QPlatformTheme
operator|::
name|ButtonPalette
argument_list|)
argument_list|,
literal|"QAbstractButton"
argument_list|)
expr_stmt|;
name|setPossiblePalette
argument_list|(
name|platformTheme
operator|->
name|palette
argument_list|(
name|QPlatformTheme
operator|::
name|HeaderPalette
argument_list|)
argument_list|,
literal|"QHeaderView"
argument_list|)
expr_stmt|;
name|setPossiblePalette
argument_list|(
name|platformTheme
operator|->
name|palette
argument_list|(
name|QPlatformTheme
operator|::
name|HeaderPalette
argument_list|)
argument_list|,
literal|"Q3Header"
argument_list|)
expr_stmt|;
name|setPossiblePalette
argument_list|(
name|platformTheme
operator|->
name|palette
argument_list|(
name|QPlatformTheme
operator|::
name|ItemViewPalette
argument_list|)
argument_list|,
literal|"QAbstractItemView"
argument_list|)
expr_stmt|;
name|setPossiblePalette
argument_list|(
name|platformTheme
operator|->
name|palette
argument_list|(
name|QPlatformTheme
operator|::
name|MessageBoxLabelPelette
argument_list|)
argument_list|,
literal|"QMessageBoxLabel"
argument_list|)
expr_stmt|;
name|setPossiblePalette
argument_list|(
name|platformTheme
operator|->
name|palette
argument_list|(
name|QPlatformTheme
operator|::
name|TabBarPalette
argument_list|)
argument_list|,
literal|"QTabBar"
argument_list|)
expr_stmt|;
name|setPossiblePalette
argument_list|(
name|platformTheme
operator|->
name|palette
argument_list|(
name|QPlatformTheme
operator|::
name|LabelPalette
argument_list|)
argument_list|,
literal|"QLabel"
argument_list|)
expr_stmt|;
name|setPossiblePalette
argument_list|(
name|platformTheme
operator|->
name|palette
argument_list|(
name|QPlatformTheme
operator|::
name|GroupBoxPalette
argument_list|)
argument_list|,
literal|"QGroupBox"
argument_list|)
expr_stmt|;
name|setPossiblePalette
argument_list|(
name|platformTheme
operator|->
name|palette
argument_list|(
name|QPlatformTheme
operator|::
name|MenuPalette
argument_list|)
argument_list|,
literal|"QMenu"
argument_list|)
expr_stmt|;
name|setPossiblePalette
argument_list|(
name|platformTheme
operator|->
name|palette
argument_list|(
name|QPlatformTheme
operator|::
name|MenuBarPalette
argument_list|)
argument_list|,
literal|"QMenuBar"
argument_list|)
expr_stmt|;
name|setPossiblePalette
argument_list|(
name|platformTheme
operator|->
name|palette
argument_list|(
name|QPlatformTheme
operator|::
name|TextEditPalette
argument_list|)
argument_list|,
literal|"QTextEdit"
argument_list|)
expr_stmt|;
name|setPossiblePalette
argument_list|(
name|platformTheme
operator|->
name|palette
argument_list|(
name|QPlatformTheme
operator|::
name|TextEditPalette
argument_list|)
argument_list|,
literal|"QTextControl"
argument_list|)
expr_stmt|;
name|setPossiblePalette
argument_list|(
name|platformTheme
operator|->
name|palette
argument_list|(
name|QPlatformTheme
operator|::
name|TextLineEditPalette
argument_list|)
argument_list|,
literal|"QLineEdit"
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|initializeWidgetFontHash
name|void
name|QApplicationPrivate
operator|::
name|initializeWidgetFontHash
parameter_list|()
block|{
specifier|const
name|QPlatformTheme
modifier|*
name|theme
init|=
name|QGuiApplicationPrivate
operator|::
name|platformTheme
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
name|theme
condition|)
return|return;
name|FontHash
modifier|*
name|fontHash
init|=
name|qt_app_fonts_hash
argument_list|()
decl_stmt|;
if|if
condition|(
specifier|const
name|QFont
modifier|*
name|font
init|=
name|theme
operator|->
name|font
argument_list|(
name|QPlatformTheme
operator|::
name|MenuFont
argument_list|)
condition|)
name|fontHash
operator|->
name|insert
argument_list|(
name|QByteArrayLiteral
argument_list|(
literal|"QMenu"
argument_list|)
argument_list|,
operator|*
name|font
argument_list|)
expr_stmt|;
if|if
condition|(
specifier|const
name|QFont
modifier|*
name|font
init|=
name|theme
operator|->
name|font
argument_list|(
name|QPlatformTheme
operator|::
name|MenuBarFont
argument_list|)
condition|)
name|fontHash
operator|->
name|insert
argument_list|(
name|QByteArrayLiteral
argument_list|(
literal|"QMenuBar"
argument_list|)
argument_list|,
operator|*
name|font
argument_list|)
expr_stmt|;
if|if
condition|(
specifier|const
name|QFont
modifier|*
name|font
init|=
name|theme
operator|->
name|font
argument_list|(
name|QPlatformTheme
operator|::
name|MenuItemFont
argument_list|)
condition|)
name|fontHash
operator|->
name|insert
argument_list|(
name|QByteArrayLiteral
argument_list|(
literal|"QMenuItem"
argument_list|)
argument_list|,
operator|*
name|font
argument_list|)
expr_stmt|;
if|if
condition|(
specifier|const
name|QFont
modifier|*
name|font
init|=
name|theme
operator|->
name|font
argument_list|(
name|QPlatformTheme
operator|::
name|MessageBoxFont
argument_list|)
condition|)
name|fontHash
operator|->
name|insert
argument_list|(
name|QByteArrayLiteral
argument_list|(
literal|"QMessageBox"
argument_list|)
argument_list|,
operator|*
name|font
argument_list|)
expr_stmt|;
if|if
condition|(
specifier|const
name|QFont
modifier|*
name|font
init|=
name|theme
operator|->
name|font
argument_list|(
name|QPlatformTheme
operator|::
name|LabelFont
argument_list|)
condition|)
name|fontHash
operator|->
name|insert
argument_list|(
name|QByteArrayLiteral
argument_list|(
literal|"QLabel"
argument_list|)
argument_list|,
operator|*
name|font
argument_list|)
expr_stmt|;
if|if
condition|(
specifier|const
name|QFont
modifier|*
name|font
init|=
name|theme
operator|->
name|font
argument_list|(
name|QPlatformTheme
operator|::
name|TipLabelFont
argument_list|)
condition|)
name|fontHash
operator|->
name|insert
argument_list|(
name|QByteArrayLiteral
argument_list|(
literal|"QTipLabel"
argument_list|)
argument_list|,
operator|*
name|font
argument_list|)
expr_stmt|;
if|if
condition|(
specifier|const
name|QFont
modifier|*
name|font
init|=
name|theme
operator|->
name|font
argument_list|(
name|QPlatformTheme
operator|::
name|TitleBarFont
argument_list|)
condition|)
name|fontHash
operator|->
name|insert
argument_list|(
name|QByteArrayLiteral
argument_list|(
literal|"QTitleBar"
argument_list|)
argument_list|,
operator|*
name|font
argument_list|)
expr_stmt|;
if|if
condition|(
specifier|const
name|QFont
modifier|*
name|font
init|=
name|theme
operator|->
name|font
argument_list|(
name|QPlatformTheme
operator|::
name|StatusBarFont
argument_list|)
condition|)
name|fontHash
operator|->
name|insert
argument_list|(
name|QByteArrayLiteral
argument_list|(
literal|"QStatusBar"
argument_list|)
argument_list|,
operator|*
name|font
argument_list|)
expr_stmt|;
if|if
condition|(
specifier|const
name|QFont
modifier|*
name|font
init|=
name|theme
operator|->
name|font
argument_list|(
name|QPlatformTheme
operator|::
name|MdiSubWindowTitleFont
argument_list|)
condition|)
block|{
name|fontHash
operator|->
name|insert
argument_list|(
name|QByteArrayLiteral
argument_list|(
literal|"QWorkspaceTitleBar"
argument_list|)
argument_list|,
operator|*
name|font
argument_list|)
expr_stmt|;
name|fontHash
operator|->
name|insert
argument_list|(
name|QByteArrayLiteral
argument_list|(
literal|"QMdiSubWindowTitleBar"
argument_list|)
argument_list|,
operator|*
name|font
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
specifier|const
name|QFont
modifier|*
name|font
init|=
name|theme
operator|->
name|font
argument_list|(
name|QPlatformTheme
operator|::
name|DockWidgetTitleFont
argument_list|)
condition|)
name|fontHash
operator|->
name|insert
argument_list|(
name|QByteArrayLiteral
argument_list|(
literal|"QDockWidgetTitle"
argument_list|)
argument_list|,
operator|*
name|font
argument_list|)
expr_stmt|;
if|if
condition|(
specifier|const
name|QFont
modifier|*
name|font
init|=
name|theme
operator|->
name|font
argument_list|(
name|QPlatformTheme
operator|::
name|PushButtonFont
argument_list|)
condition|)
name|fontHash
operator|->
name|insert
argument_list|(
name|QByteArrayLiteral
argument_list|(
literal|"QPushButton"
argument_list|)
argument_list|,
operator|*
name|font
argument_list|)
expr_stmt|;
if|if
condition|(
specifier|const
name|QFont
modifier|*
name|font
init|=
name|theme
operator|->
name|font
argument_list|(
name|QPlatformTheme
operator|::
name|ToolButtonFont
argument_list|)
condition|)
name|fontHash
operator|->
name|insert
argument_list|(
name|QByteArrayLiteral
argument_list|(
literal|"QToolButton"
argument_list|)
argument_list|,
operator|*
name|font
argument_list|)
expr_stmt|;
if|if
condition|(
specifier|const
name|QFont
modifier|*
name|font
init|=
name|theme
operator|->
name|font
argument_list|(
name|QPlatformTheme
operator|::
name|ItemViewFont
argument_list|)
condition|)
name|fontHash
operator|->
name|insert
argument_list|(
name|QByteArrayLiteral
argument_list|(
literal|"QAbstractItemView"
argument_list|)
argument_list|,
operator|*
name|font
argument_list|)
expr_stmt|;
if|if
condition|(
specifier|const
name|QFont
modifier|*
name|font
init|=
name|theme
operator|->
name|font
argument_list|(
name|QPlatformTheme
operator|::
name|ListViewFont
argument_list|)
condition|)
name|fontHash
operator|->
name|insert
argument_list|(
name|QByteArrayLiteral
argument_list|(
literal|"QListViewFont"
argument_list|)
argument_list|,
operator|*
name|font
argument_list|)
expr_stmt|;
if|if
condition|(
specifier|const
name|QFont
modifier|*
name|font
init|=
name|theme
operator|->
name|font
argument_list|(
name|QPlatformTheme
operator|::
name|HeaderViewFont
argument_list|)
condition|)
block|{
name|fontHash
operator|->
name|insert
argument_list|(
name|QByteArrayLiteral
argument_list|(
literal|"QHeaderViewFont"
argument_list|)
argument_list|,
operator|*
name|font
argument_list|)
expr_stmt|;
name|fontHash
operator|->
name|insert
argument_list|(
name|QByteArrayLiteral
argument_list|(
literal|"Q3Header"
argument_list|)
argument_list|,
operator|*
name|font
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
specifier|const
name|QFont
modifier|*
name|font
init|=
name|theme
operator|->
name|font
argument_list|(
name|QPlatformTheme
operator|::
name|ListBoxFont
argument_list|)
condition|)
name|fontHash
operator|->
name|insert
argument_list|(
name|QByteArrayLiteral
argument_list|(
literal|"QListBox"
argument_list|)
argument_list|,
operator|*
name|font
argument_list|)
expr_stmt|;
if|if
condition|(
specifier|const
name|QFont
modifier|*
name|font
init|=
name|theme
operator|->
name|font
argument_list|(
name|QPlatformTheme
operator|::
name|ComboMenuItemFont
argument_list|)
condition|)
name|fontHash
operator|->
name|insert
argument_list|(
name|QByteArrayLiteral
argument_list|(
literal|"QComboMenuItemFont"
argument_list|)
argument_list|,
operator|*
name|font
argument_list|)
expr_stmt|;
if|if
condition|(
specifier|const
name|QFont
modifier|*
name|font
init|=
name|theme
operator|->
name|font
argument_list|(
name|QPlatformTheme
operator|::
name|ComboLineEditFont
argument_list|)
condition|)
name|fontHash
operator|->
name|insert
argument_list|(
name|QByteArrayLiteral
argument_list|(
literal|"QComboLineEditFont"
argument_list|)
argument_list|,
operator|*
name|font
argument_list|)
expr_stmt|;
if|if
condition|(
specifier|const
name|QFont
modifier|*
name|font
init|=
name|theme
operator|->
name|font
argument_list|(
name|QPlatformTheme
operator|::
name|SmallFont
argument_list|)
condition|)
name|fontHash
operator|->
name|insert
argument_list|(
name|QByteArrayLiteral
argument_list|(
literal|"QSmallFont"
argument_list|)
argument_list|,
operator|*
name|font
argument_list|)
expr_stmt|;
if|if
condition|(
specifier|const
name|QFont
modifier|*
name|font
init|=
name|theme
operator|->
name|font
argument_list|(
name|QPlatformTheme
operator|::
name|MiniFont
argument_list|)
condition|)
name|fontHash
operator|->
name|insert
argument_list|(
name|QByteArrayLiteral
argument_list|(
literal|"QMiniFont"
argument_list|)
argument_list|,
operator|*
name|font
argument_list|)
expr_stmt|;
block|}
end_function
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_WHEELEVENT
end_ifndef
begin_function
DECL|function|setWheelScrollLines
name|void
name|QApplication
operator|::
name|setWheelScrollLines
parameter_list|(
name|int
name|lines
parameter_list|)
block|{
name|QApplicationPrivate
operator|::
name|wheel_scroll_lines
operator|=
name|lines
expr_stmt|;
block|}
end_function
begin_function
DECL|function|wheelScrollLines
name|int
name|QApplication
operator|::
name|wheelScrollLines
parameter_list|()
block|{
return|return
name|QApplicationPrivate
operator|::
name|wheel_scroll_lines
return|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_function
DECL|function|setEffectEnabled
name|void
name|QApplication
operator|::
name|setEffectEnabled
parameter_list|(
name|Qt
operator|::
name|UIEffect
name|effect
parameter_list|,
name|bool
name|enable
parameter_list|)
block|{
switch|switch
condition|(
name|effect
condition|)
block|{
case|case
name|Qt
operator|::
name|UI_AnimateMenu
case|:
name|QApplicationPrivate
operator|::
name|animate_menu
operator|=
name|enable
expr_stmt|;
break|break;
case|case
name|Qt
operator|::
name|UI_FadeMenu
case|:
if|if
condition|(
name|enable
condition|)
name|QApplicationPrivate
operator|::
name|animate_menu
operator|=
literal|true
expr_stmt|;
name|QApplicationPrivate
operator|::
name|fade_menu
operator|=
name|enable
expr_stmt|;
break|break;
case|case
name|Qt
operator|::
name|UI_AnimateCombo
case|:
name|QApplicationPrivate
operator|::
name|animate_combo
operator|=
name|enable
expr_stmt|;
break|break;
case|case
name|Qt
operator|::
name|UI_AnimateTooltip
case|:
name|QApplicationPrivate
operator|::
name|animate_tooltip
operator|=
name|enable
expr_stmt|;
break|break;
case|case
name|Qt
operator|::
name|UI_FadeTooltip
case|:
if|if
condition|(
name|enable
condition|)
name|QApplicationPrivate
operator|::
name|animate_tooltip
operator|=
literal|true
expr_stmt|;
name|QApplicationPrivate
operator|::
name|fade_tooltip
operator|=
name|enable
expr_stmt|;
break|break;
case|case
name|Qt
operator|::
name|UI_AnimateToolBox
case|:
name|QApplicationPrivate
operator|::
name|animate_toolbox
operator|=
name|enable
expr_stmt|;
break|break;
default|default:
name|QApplicationPrivate
operator|::
name|animate_ui
operator|=
name|enable
expr_stmt|;
break|break;
block|}
block|}
end_function
begin_function
DECL|function|isEffectEnabled
name|bool
name|QApplication
operator|::
name|isEffectEnabled
parameter_list|(
name|Qt
operator|::
name|UIEffect
name|effect
parameter_list|)
block|{
if|if
condition|(
name|QColormap
operator|::
name|instance
argument_list|()
operator|.
name|depth
argument_list|()
operator|<
literal|16
operator|||
operator|!
name|QApplicationPrivate
operator|::
name|animate_ui
condition|)
return|return
literal|false
return|;
switch|switch
condition|(
name|effect
condition|)
block|{
case|case
name|Qt
operator|::
name|UI_AnimateMenu
case|:
return|return
name|QApplicationPrivate
operator|::
name|animate_menu
return|;
case|case
name|Qt
operator|::
name|UI_FadeMenu
case|:
return|return
name|QApplicationPrivate
operator|::
name|fade_menu
return|;
case|case
name|Qt
operator|::
name|UI_AnimateCombo
case|:
return|return
name|QApplicationPrivate
operator|::
name|animate_combo
return|;
case|case
name|Qt
operator|::
name|UI_AnimateTooltip
case|:
return|return
name|QApplicationPrivate
operator|::
name|animate_tooltip
return|;
case|case
name|Qt
operator|::
name|UI_FadeTooltip
case|:
return|return
name|QApplicationPrivate
operator|::
name|fade_tooltip
return|;
case|case
name|Qt
operator|::
name|UI_AnimateToolBox
case|:
return|return
name|QApplicationPrivate
operator|::
name|animate_toolbox
return|;
default|default:
return|return
name|QApplicationPrivate
operator|::
name|animate_ui
return|;
block|}
block|}
end_function
begin_function
DECL|function|topLevelAt
name|QWidget
modifier|*
name|QApplication
operator|::
name|topLevelAt
parameter_list|(
specifier|const
name|QPoint
modifier|&
name|pos
parameter_list|)
block|{
name|QList
argument_list|<
name|QScreen
modifier|*
argument_list|>
name|screens
init|=
name|QGuiApplication
operator|::
name|screens
argument_list|()
decl_stmt|;
name|QList
argument_list|<
name|QScreen
modifier|*
argument_list|>
operator|::
name|const_iterator
name|screen
init|=
name|screens
operator|.
name|constBegin
argument_list|()
decl_stmt|;
name|QList
argument_list|<
name|QScreen
modifier|*
argument_list|>
operator|::
name|const_iterator
name|end
init|=
name|screens
operator|.
name|constEnd
argument_list|()
decl_stmt|;
while|while
condition|(
name|screen
operator|!=
name|end
condition|)
block|{
if|if
condition|(
operator|(
operator|*
name|screen
operator|)
operator|->
name|geometry
argument_list|()
operator|.
name|contains
argument_list|(
name|pos
argument_list|)
condition|)
block|{
name|QWidgetWindow
modifier|*
name|w
init|=
name|qobject_cast
argument_list|<
name|QWidgetWindow
operator|*
argument_list|>
argument_list|(
operator|(
operator|*
name|screen
operator|)
operator|->
name|handle
argument_list|()
operator|->
name|topLevelAt
argument_list|(
name|pos
argument_list|)
argument_list|)
decl_stmt|;
return|return
name|w
condition|?
name|w
operator|->
name|widget
argument_list|()
else|:
literal|0
return|;
block|}
operator|++
name|screen
expr_stmt|;
block|}
return|return
literal|0
return|;
block|}
end_function
begin_function
DECL|function|beep
name|void
name|QApplication
operator|::
name|beep
parameter_list|()
block|{ }
end_function
begin_function
DECL|function|alert
name|void
name|QApplication
operator|::
name|alert
parameter_list|(
name|QWidget
modifier|*
parameter_list|,
name|int
parameter_list|)
block|{ }
end_function
begin_function
DECL|function|platformNativeInterface
name|QPlatformNativeInterface
modifier|*
name|QApplication
operator|::
name|platformNativeInterface
parameter_list|()
block|{
name|QPlatformIntegration
modifier|*
name|pi
init|=
name|QGuiApplicationPrivate
operator|::
name|platformIntegration
argument_list|()
decl_stmt|;
return|return
name|pi
operator|->
name|nativeInterface
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|qt_init
name|void
name|qt_init
parameter_list|(
name|QApplicationPrivate
modifier|*
name|priv
parameter_list|,
name|int
name|type
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
name|priv
argument_list|)
expr_stmt|;
name|Q_UNUSED
argument_list|(
name|type
argument_list|)
expr_stmt|;
name|qApp
operator|->
name|setAttribute
argument_list|(
name|Qt
operator|::
name|AA_DontCreateNativeWidgetSiblings
argument_list|)
expr_stmt|;
name|QColormap
operator|::
name|initialize
argument_list|()
expr_stmt|;
if|if
condition|(
specifier|const
name|QPalette
modifier|*
name|toolTipPalette
init|=
name|QGuiApplicationPrivate
operator|::
name|platformTheme
argument_list|()
operator|->
name|palette
argument_list|(
name|QPlatformTheme
operator|::
name|ToolTipPalette
argument_list|)
condition|)
name|QToolTip
operator|::
name|setPalette
argument_list|(
operator|*
name|toolTipPalette
argument_list|)
expr_stmt|;
name|QApplicationPrivate
operator|::
name|initializeWidgetFontHash
argument_list|()
expr_stmt|;
name|qApp
operator|->
name|setObjectName
argument_list|(
name|appName
argument_list|)
expr_stmt|;
block|}
end_function
begin_ifdef
ifdef|#
directive|ifdef
name|Q_OS_WIN
end_ifdef
begin_comment
comment|// #fixme: Remove.
end_comment
begin_decl_stmt
DECL|variable|displayDC
specifier|static
name|HDC
name|displayDC
init|=
literal|0
decl_stmt|;
end_decl_stmt
begin_comment
DECL|variable|displayDC
comment|// display device context
end_comment
begin_function
DECL|function|qt_win_display_dc
name|Q_WIDGETS_EXPORT
name|HDC
name|qt_win_display_dc
parameter_list|()
comment|// get display DC
block|{
name|Q_ASSERT
argument_list|(
name|qApp
operator|&&
name|qApp
operator|->
name|thread
argument_list|()
operator|==
name|QThread
operator|::
name|currentThread
argument_list|()
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|displayDC
condition|)
name|displayDC
operator|=
name|GetDC
argument_list|(
literal|0
argument_list|)
expr_stmt|;
return|return
name|displayDC
return|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_function
DECL|function|qt_cleanup
name|void
name|qt_cleanup
parameter_list|()
block|{
name|QPixmapCache
operator|::
name|clear
argument_list|()
expr_stmt|;
name|QColormap
operator|::
name|cleanup
argument_list|()
expr_stmt|;
name|QApplicationPrivate
operator|::
name|active_window
operator|=
literal|0
expr_stmt|;
comment|//### this should not be necessary
ifdef|#
directive|ifdef
name|Q_OS_WIN
if|if
condition|(
name|displayDC
condition|)
block|{
name|ReleaseDC
argument_list|(
literal|0
argument_list|,
name|displayDC
argument_list|)
expr_stmt|;
name|displayDC
operator|=
literal|0
expr_stmt|;
block|}
endif|#
directive|endif
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
