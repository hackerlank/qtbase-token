begin_unit
begin_comment
comment|/*************************************************************************** ** ** Copyright (C) 2011 - 2012 Research In Motion ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QQNXKEYTRANSLATOR_H
end_ifndef
begin_define
DECL|macro|QQNXKEYTRANSLATOR_H
define|#
directive|define
name|QQNXKEYTRANSLATOR_H
end_define
begin_include
include|#
directive|include
file|<sys/keycodes.h>
end_include
begin_if
if|#
directive|if
name|defined
argument_list|(
name|QQNXEVENTTHREAD_DEBUG
argument_list|)
end_if
begin_include
include|#
directive|include
file|<QtCore/QDebug>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_expr_stmt
name|QT_BEGIN_NAMESPACE
DECL|function|keyTranslator
name|Qt
operator|::
name|Key
name|keyTranslator
argument_list|(
argument|int key
argument_list|)
block|{
switch|switch
condition|(
name|key
condition|)
block|{
case|case
name|KEYCODE_PAUSE
case|:
return|return
name|Qt
operator|::
name|Key_Pause
return|;
case|case
name|KEYCODE_SCROLL_LOCK
case|:
return|return
name|Qt
operator|::
name|Key_ScrollLock
return|;
case|case
name|KEYCODE_PRINT
case|:
return|return
name|Qt
operator|::
name|Key_Print
return|;
case|case
name|KEYCODE_SYSREQ
case|:
return|return
name|Qt
operator|::
name|Key_SysReq
return|;
comment|//    case KEYCODE_BREAK:
case|case
name|KEYCODE_ESCAPE
case|:
return|return
name|Qt
operator|::
name|Key_Escape
return|;
case|case
name|KEYCODE_BACKSPACE
case|:
return|return
name|Qt
operator|::
name|Key_Backspace
return|;
case|case
name|KEYCODE_TAB
case|:
return|return
name|Qt
operator|::
name|Key_Tab
return|;
case|case
name|KEYCODE_BACK_TAB
case|:
return|return
name|Qt
operator|::
name|Key_Backtab
return|;
case|case
name|KEYCODE_RETURN
case|:
return|return
name|Qt
operator|::
name|Key_Return
return|;
case|case
name|KEYCODE_CAPS_LOCK
case|:
return|return
name|Qt
operator|::
name|Key_CapsLock
return|;
case|case
name|KEYCODE_LEFT_SHIFT
case|:
case|case
name|KEYCODE_RIGHT_SHIFT
case|:
return|return
name|Qt
operator|::
name|Key_Shift
return|;
case|case
name|KEYCODE_LEFT_CTRL
case|:
case|case
name|KEYCODE_RIGHT_CTRL
case|:
return|return
name|Qt
operator|::
name|Key_Control
return|;
case|case
name|KEYCODE_LEFT_ALT
case|:
case|case
name|KEYCODE_RIGHT_ALT
case|:
return|return
name|Qt
operator|::
name|Key_Alt
return|;
case|case
name|KEYCODE_MENU
case|:
return|return
name|Qt
operator|::
name|Key_Menu
return|;
case|case
name|KEYCODE_LEFT_HYPER
case|:
return|return
name|Qt
operator|::
name|Key_Hyper_L
return|;
case|case
name|KEYCODE_RIGHT_HYPER
case|:
return|return
name|Qt
operator|::
name|Key_Hyper_R
return|;
case|case
name|KEYCODE_INSERT
case|:
return|return
name|Qt
operator|::
name|Key_Insert
return|;
case|case
name|KEYCODE_HOME
case|:
return|return
name|Qt
operator|::
name|Key_Home
return|;
case|case
name|KEYCODE_PG_UP
case|:
return|return
name|Qt
operator|::
name|Key_PageUp
return|;
case|case
name|KEYCODE_DELETE
case|:
return|return
name|Qt
operator|::
name|Key_Delete
return|;
case|case
name|KEYCODE_END
case|:
return|return
name|Qt
operator|::
name|Key_End
return|;
case|case
name|KEYCODE_PG_DOWN
case|:
return|return
name|Qt
operator|::
name|Key_PageDown
return|;
case|case
name|KEYCODE_LEFT
case|:
return|return
name|Qt
operator|::
name|Key_Left
return|;
case|case
name|KEYCODE_RIGHT
case|:
return|return
name|Qt
operator|::
name|Key_Right
return|;
case|case
name|KEYCODE_UP
case|:
return|return
name|Qt
operator|::
name|Key_Up
return|;
case|case
name|KEYCODE_DOWN
case|:
return|return
name|Qt
operator|::
name|Key_Down
return|;
case|case
name|KEYCODE_NUM_LOCK
case|:
return|return
name|Qt
operator|::
name|Key_NumLock
return|;
case|case
name|KEYCODE_KP_PLUS
case|:
return|return
name|Qt
operator|::
name|Key_Plus
return|;
case|case
name|KEYCODE_KP_MINUS
case|:
return|return
name|Qt
operator|::
name|Key_Minus
return|;
case|case
name|KEYCODE_KP_MULTIPLY
case|:
return|return
name|Qt
operator|::
name|Key_Asterisk
return|;
case|case
name|KEYCODE_KP_DIVIDE
case|:
return|return
name|Qt
operator|::
name|Key_Slash
return|;
case|case
name|KEYCODE_KP_ENTER
case|:
return|return
name|Qt
operator|::
name|Key_Enter
return|;
case|case
name|KEYCODE_KP_HOME
case|:
return|return
name|Qt
operator|::
name|Key_Home
return|;
case|case
name|KEYCODE_KP_UP
case|:
return|return
name|Qt
operator|::
name|Key_Up
return|;
case|case
name|KEYCODE_KP_PG_UP
case|:
return|return
name|Qt
operator|::
name|Key_PageUp
return|;
case|case
name|KEYCODE_KP_LEFT
case|:
return|return
name|Qt
operator|::
name|Key_Left
return|;
comment|// Is this right?
case|case
name|KEYCODE_KP_FIVE
case|:
return|return
name|Qt
operator|::
name|Key_5
return|;
case|case
name|KEYCODE_KP_RIGHT
case|:
return|return
name|Qt
operator|::
name|Key_Right
return|;
case|case
name|KEYCODE_KP_END
case|:
return|return
name|Qt
operator|::
name|Key_End
return|;
case|case
name|KEYCODE_KP_DOWN
case|:
return|return
name|Qt
operator|::
name|Key_Down
return|;
case|case
name|KEYCODE_KP_PG_DOWN
case|:
return|return
name|Qt
operator|::
name|Key_PageDown
return|;
case|case
name|KEYCODE_KP_INSERT
case|:
return|return
name|Qt
operator|::
name|Key_Insert
return|;
case|case
name|KEYCODE_KP_DELETE
case|:
return|return
name|Qt
operator|::
name|Key_Delete
return|;
case|case
name|KEYCODE_F1
case|:
return|return
name|Qt
operator|::
name|Key_F1
return|;
case|case
name|KEYCODE_F2
case|:
return|return
name|Qt
operator|::
name|Key_F2
return|;
case|case
name|KEYCODE_F3
case|:
return|return
name|Qt
operator|::
name|Key_F3
return|;
case|case
name|KEYCODE_F4
case|:
return|return
name|Qt
operator|::
name|Key_F4
return|;
case|case
name|KEYCODE_F5
case|:
return|return
name|Qt
operator|::
name|Key_F5
return|;
case|case
name|KEYCODE_F6
case|:
return|return
name|Qt
operator|::
name|Key_F6
return|;
case|case
name|KEYCODE_F7
case|:
return|return
name|Qt
operator|::
name|Key_F7
return|;
case|case
name|KEYCODE_F8
case|:
return|return
name|Qt
operator|::
name|Key_F8
return|;
case|case
name|KEYCODE_F9
case|:
return|return
name|Qt
operator|::
name|Key_F9
return|;
case|case
name|KEYCODE_F10
case|:
return|return
name|Qt
operator|::
name|Key_F10
return|;
case|case
name|KEYCODE_F11
case|:
return|return
name|Qt
operator|::
name|Key_F11
return|;
case|case
name|KEYCODE_F12
case|:
return|return
name|Qt
operator|::
name|Key_F12
return|;
comment|// See keycodes.h for more, but these are all the basics. And printables are already included.
default|default:
if|#
directive|if
name|defined
argument_list|(
name|QQNXEVENTTHREAD_DEBUG
argument_list|)
name|qDebug
argument_list|()
operator|<<
literal|"QQNX: unknown key for translation:"
operator|<<
name|key
expr_stmt|;
endif|#
directive|endif
break|break;
block|}
end_expr_stmt
begin_return
return|return
name|Qt
operator|::
name|Key_Escape
return|;
end_return
begin_macro
unit|}  bool
DECL|function|isKeypadKey
name|isKeypadKey
argument_list|(
argument|int key
argument_list|)
end_macro
begin_block
block|{
switch|switch
condition|(
name|key
condition|)
block|{
case|case
name|KEYCODE_KP_PLUS
case|:
case|case
name|KEYCODE_KP_MINUS
case|:
case|case
name|KEYCODE_KP_MULTIPLY
case|:
case|case
name|KEYCODE_KP_DIVIDE
case|:
case|case
name|KEYCODE_KP_ENTER
case|:
case|case
name|KEYCODE_KP_HOME
case|:
case|case
name|KEYCODE_KP_UP
case|:
case|case
name|KEYCODE_KP_PG_UP
case|:
case|case
name|KEYCODE_KP_LEFT
case|:
case|case
name|KEYCODE_KP_FIVE
case|:
case|case
name|KEYCODE_KP_RIGHT
case|:
case|case
name|KEYCODE_KP_END
case|:
case|case
name|KEYCODE_KP_DOWN
case|:
case|case
name|KEYCODE_KP_PG_DOWN
case|:
case|case
name|KEYCODE_KP_INSERT
case|:
case|case
name|KEYCODE_KP_DELETE
case|:
return|return
name|true
return|;
default|default:
break|break;
block|}
return|return
name|false
return|;
block|}
end_block
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QQNXKEYTRANSLATOR_H
end_comment
end_unit
