begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QTWINDOWSGLOBAL_H
end_ifndef
begin_define
DECL|macro|QTWINDOWSGLOBAL_H
define|#
directive|define
name|QTWINDOWSGLOBAL_H
end_define
begin_include
include|#
directive|include
file|"qtwindows_additional.h"
end_include
begin_include
include|#
directive|include
file|<QtCore/qnamespace.h>
end_include
begin_ifdef
ifdef|#
directive|ifdef
name|Q_OS_WINCE
end_ifdef
begin_include
include|#
directive|include
file|"qplatformfunctions_wince.h"
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
name|namespace
name|QtWindows
block|{
enum|enum
block|{
name|WindowEventFlag
init|=
literal|0x10000
block|,
name|MouseEventFlag
init|=
literal|0x20000
block|,
name|NonClientEventFlag
init|=
literal|0x40000
block|,
name|InputMethodEventFlag
init|=
literal|0x80000
block|,
name|KeyEventFlag
init|=
literal|0x100000
block|,
name|KeyDownEventFlag
init|=
literal|0x200000
block|,
name|TouchEventFlag
init|=
literal|0x400000
block|,
name|ClipboardEventFlag
init|=
literal|0x800000
block|,
name|ApplicationEventFlag
init|=
literal|0x1000000
block|,
name|ThemingEventFlag
init|=
literal|0x2000000
block|}
enum|;
enum|enum
name|WindowsEventType
comment|// Simplify event types
block|{
name|ExposeEvent
init|=
name|WindowEventFlag
operator|+
literal|1
block|,
name|ActivateWindowEvent
init|=
name|WindowEventFlag
operator|+
literal|2
block|,
name|DeactivateWindowEvent
init|=
name|WindowEventFlag
operator|+
literal|3
block|,
name|LeaveEvent
init|=
name|WindowEventFlag
operator|+
literal|5
block|,
name|CloseEvent
init|=
name|WindowEventFlag
operator|+
literal|6
block|,
name|ShowEvent
init|=
name|WindowEventFlag
operator|+
literal|7
block|,
name|HideEvent
init|=
name|WindowEventFlag
operator|+
literal|8
block|,
name|DestroyEvent
init|=
name|WindowEventFlag
operator|+
literal|9
block|,
name|MoveEvent
init|=
name|WindowEventFlag
operator|+
literal|10
block|,
name|ResizeEvent
init|=
name|WindowEventFlag
operator|+
literal|12
block|,
name|QuerySizeHints
init|=
name|WindowEventFlag
operator|+
literal|15
block|,
name|CalculateSize
init|=
name|WindowEventFlag
operator|+
literal|16
block|,
name|FocusInEvent
init|=
name|WindowEventFlag
operator|+
literal|17
block|,
name|FocusOutEvent
init|=
name|WindowEventFlag
operator|+
literal|18
block|,
name|WhatsThisEvent
init|=
name|WindowEventFlag
operator|+
literal|19
block|,
name|MouseEvent
init|=
name|MouseEventFlag
operator|+
literal|1
block|,
name|MouseWheelEvent
init|=
name|MouseEventFlag
operator|+
literal|2
block|,
name|CursorEvent
init|=
name|MouseEventFlag
operator|+
literal|3
block|,
name|TouchEvent
init|=
name|TouchEventFlag
operator|+
literal|1
block|,
name|NonClientMouseEvent
init|=
name|NonClientEventFlag
operator|+
name|MouseEventFlag
operator|+
literal|1
block|,
name|KeyEvent
init|=
name|KeyEventFlag
operator|+
literal|1
block|,
name|KeyDownEvent
init|=
name|KeyEventFlag
operator|+
name|KeyDownEventFlag
operator|+
literal|1
block|,
name|InputMethodKeyEvent
init|=
name|InputMethodEventFlag
operator|+
name|KeyEventFlag
operator|+
literal|1
block|,
name|InputMethodKeyDownEvent
init|=
name|InputMethodEventFlag
operator|+
name|KeyEventFlag
operator|+
name|KeyDownEventFlag
operator|+
literal|1
block|,
name|ClipboardEvent
init|=
name|ClipboardEventFlag
operator|+
literal|1
block|,
name|ActivateApplicationEvent
init|=
name|ApplicationEventFlag
operator|+
literal|1
block|,
name|DeactivateApplicationEvent
init|=
name|ApplicationEventFlag
operator|+
literal|2
block|,
name|AccessibleObjectFromWindowRequest
init|=
name|ApplicationEventFlag
operator|+
literal|3
block|,
name|InputMethodStartCompositionEvent
init|=
name|InputMethodEventFlag
operator|+
literal|1
block|,
name|InputMethodCompositionEvent
init|=
name|InputMethodEventFlag
operator|+
literal|2
block|,
name|InputMethodEndCompositionEvent
init|=
name|InputMethodEventFlag
operator|+
literal|3
block|,
name|InputMethodOpenCandidateWindowEvent
init|=
name|InputMethodEventFlag
operator|+
literal|4
block|,
name|InputMethodCloseCandidateWindowEvent
init|=
name|InputMethodEventFlag
operator|+
literal|5
block|,
name|InputMethodRequest
init|=
name|InputMethodEventFlag
operator|+
literal|6
block|,
name|ThemeChanged
init|=
name|ThemingEventFlag
operator|+
literal|1
block|,
name|DisplayChangedEvent
init|=
literal|437
block|,
name|SettingChangedEvent
init|=
name|DisplayChangedEvent
operator|+
literal|1
block|,
name|ContextMenu
init|=
literal|123
block|,
name|UnknownEvent
init|=
literal|542
block|}
enum|;
block|}
end_decl_stmt
begin_comment
comment|// namespace QtWindows
end_comment
begin_expr_stmt
DECL|function|windowsEventType
specifier|inline
name|QtWindows
operator|::
name|WindowsEventType
name|windowsEventType
argument_list|(
argument|UINT message
argument_list|,
argument|WPARAM wParamIn
argument_list|)
block|{
switch|switch
condition|(
name|message
condition|)
block|{
case|case
name|WM_PAINT
case|:
case|case
name|WM_ERASEBKGND
case|:
return|return
name|QtWindows
operator|::
name|ExposeEvent
return|;
case|case
name|WM_CLOSE
case|:
return|return
name|QtWindows
operator|::
name|CloseEvent
return|;
case|case
name|WM_DESTROY
case|:
return|return
name|QtWindows
operator|::
name|DestroyEvent
return|;
case|case
name|WM_ACTIVATEAPP
case|:
return|return
operator|(
name|int
operator|)
name|wParamIn
condition|?
name|QtWindows
operator|::
name|ActivateApplicationEvent
else|:
name|QtWindows
operator|::
name|DeactivateApplicationEvent
return|;
case|case
name|WM_ACTIVATE
case|:
return|return
name|LOWORD
argument_list|(
name|wParamIn
argument_list|)
operator|==
name|WA_INACTIVE
condition|?
name|QtWindows
operator|::
name|DeactivateWindowEvent
else|:
name|QtWindows
operator|::
name|ActivateWindowEvent
return|;
case|case
name|WM_SETCURSOR
case|:
return|return
name|QtWindows
operator|::
name|CursorEvent
return|;
case|case
name|WM_MOUSELEAVE
case|:
return|return
name|QtWindows
operator|::
name|MouseEvent
return|;
case|case
name|WM_MOUSEWHEEL
case|:
case|case
name|WM_MOUSEHWHEEL
case|:
return|return
name|QtWindows
operator|::
name|MouseWheelEvent
return|;
case|case
name|WM_MOVE
case|:
return|return
name|QtWindows
operator|::
name|MoveEvent
return|;
case|case
name|WM_SHOWWINDOW
case|:
return|return
name|wParamIn
condition|?
name|QtWindows
operator|::
name|ShowEvent
else|:
name|QtWindows
operator|::
name|HideEvent
return|;
case|case
name|WM_SIZE
case|:
return|return
name|QtWindows
operator|::
name|ResizeEvent
return|;
case|case
name|WM_NCCALCSIZE
case|:
return|return
name|QtWindows
operator|::
name|CalculateSize
return|;
case|case
name|WM_GETMINMAXINFO
case|:
return|return
name|QtWindows
operator|::
name|QuerySizeHints
return|;
case|case
name|WM_KEYDOWN
case|:
comment|// keyboard event
case|case
name|WM_SYSKEYDOWN
case|:
return|return
name|QtWindows
operator|::
name|KeyDownEvent
return|;
case|case
name|WM_KEYUP
case|:
case|case
name|WM_SYSKEYUP
case|:
case|case
name|WM_CHAR
case|:
return|return
name|QtWindows
operator|::
name|KeyEvent
return|;
case|case
name|WM_IME_CHAR
case|:
return|return
name|QtWindows
operator|::
name|InputMethodKeyEvent
return|;
case|case
name|WM_IME_KEYDOWN
case|:
return|return
name|QtWindows
operator|::
name|InputMethodKeyDownEvent
return|;
case|case
name|WM_TOUCH
case|:
return|return
name|QtWindows
operator|::
name|TouchEvent
return|;
case|case
name|WM_CHANGECBCHAIN
case|:
case|case
name|WM_DRAWCLIPBOARD
case|:
case|case
name|WM_RENDERFORMAT
case|:
case|case
name|WM_RENDERALLFORMATS
case|:
case|case
name|WM_DESTROYCLIPBOARD
case|:
return|return
name|QtWindows
operator|::
name|ClipboardEvent
return|;
case|case
name|WM_IME_STARTCOMPOSITION
case|:
return|return
name|QtWindows
operator|::
name|InputMethodStartCompositionEvent
return|;
case|case
name|WM_IME_ENDCOMPOSITION
case|:
return|return
name|QtWindows
operator|::
name|InputMethodEndCompositionEvent
return|;
case|case
name|WM_IME_COMPOSITION
case|:
return|return
name|QtWindows
operator|::
name|InputMethodCompositionEvent
return|;
case|case
name|WM_IME_REQUEST
case|:
return|return
name|QtWindows
operator|::
name|InputMethodRequest
return|;
case|case
name|WM_IME_NOTIFY
case|:
switch|switch
condition|(
name|int
argument_list|(
name|wParamIn
argument_list|)
condition|)
block|{
case|case
name|IMN_OPENCANDIDATE
case|:
return|return
name|QtWindows
operator|::
name|InputMethodOpenCandidateWindowEvent
return|;
case|case
name|IMN_CLOSECANDIDATE
case|:
return|return
name|QtWindows
operator|::
name|InputMethodCloseCandidateWindowEvent
return|;
default|default:
break|break;
block|}
end_expr_stmt
begin_case
case|case
name|WM_GETOBJECT
case|:
end_case
begin_return
return|return
name|QtWindows
operator|::
name|AccessibleObjectFromWindowRequest
return|;
end_return
begin_case
case|case
name|WM_SETFOCUS
case|:
end_case
begin_return
return|return
name|QtWindows
operator|::
name|FocusInEvent
return|;
end_return
begin_case
case|case
name|WM_KILLFOCUS
case|:
end_case
begin_return
return|return
name|QtWindows
operator|::
name|FocusOutEvent
return|;
end_return
begin_comment
comment|// Among other things, WM_SETTINGCHANGE happens when the taskbar is moved
end_comment
begin_comment
comment|// and therefore the "working area" changes.
end_comment
begin_comment
comment|// http://msdn.microsoft.com/en-us/library/ms695534(v=vs.85).aspx
end_comment
begin_case
case|case
name|WM_SETTINGCHANGE
case|:
end_case
begin_return
return|return
name|QtWindows
operator|::
name|SettingChangedEvent
return|;
end_return
begin_case
case|case
name|WM_DISPLAYCHANGE
case|:
end_case
begin_return
return|return
name|QtWindows
operator|::
name|DisplayChangedEvent
return|;
end_return
begin_case
case|case
name|WM_THEMECHANGED
case|:
end_case
begin_return
return|return
name|QtWindows
operator|::
name|ThemeChanged
return|;
end_return
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_CONTEXTMENU
end_ifndef
begin_case
case|case
name|WM_CONTEXTMENU
case|:
end_case
begin_return
return|return
name|QtWindows
operator|::
name|ContextMenu
return|;
end_return
begin_endif
endif|#
directive|endif
end_endif
begin_case
case|case
name|WM_SYSCOMMAND
case|:
end_case
begin_ifndef
ifndef|#
directive|ifndef
name|Q_OS_WINCE
end_ifndef
begin_if
if|if
condition|(
operator|(
name|wParamIn
operator|&
literal|0xfff0
operator|)
operator|==
name|SC_CONTEXTHELP
condition|)
return|return
name|QtWindows
operator|::
name|WhatsThisEvent
return|;
end_if
begin_endif
endif|#
directive|endif
end_endif
begin_break
break|break;
end_break
begin_default
default|default:
end_default
begin_break
break|break;
end_break
begin_expr_stmt
unit|}     if
operator|(
name|message
operator|>=
name|WM_NCMOUSEMOVE
operator|&&
name|message
operator|<=
name|WM_NCMBUTTONDBLCLK
operator|)
end_expr_stmt
begin_return
return|return
name|QtWindows
operator|::
name|NonClientMouseEvent
return|;
end_return
begin_comment
comment|//
end_comment
begin_if
if|if
condition|(
operator|(
name|message
operator|>=
name|WM_MOUSEFIRST
operator|&&
name|message
operator|<=
name|WM_MOUSELAST
operator|)
operator|||
operator|(
name|message
operator|>=
name|WM_XBUTTONDOWN
operator|&&
name|message
operator|<=
name|WM_XBUTTONDBLCLK
operator|)
condition|)
return|return
name|QtWindows
operator|::
name|MouseEvent
return|;
end_if
begin_return
return|return
name|QtWindows
operator|::
name|UnknownEvent
return|;
end_return
begin_endif
unit|}  QT_END_NAMESPACE
endif|#
directive|endif
end_endif
begin_comment
comment|// QTWINDOWSGLOBAL_H
end_comment
end_unit
