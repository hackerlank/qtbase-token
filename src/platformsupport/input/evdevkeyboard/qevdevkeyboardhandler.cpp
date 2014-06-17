begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qevdevkeyboardhandler_p.h"
end_include
begin_include
include|#
directive|include
file|<qplatformdefs.h>
end_include
begin_include
include|#
directive|include
file|<QSocketNotifier>
end_include
begin_include
include|#
directive|include
file|<QStringList>
end_include
begin_include
include|#
directive|include
file|<qpa/qwindowsysteminterface.h>
end_include
begin_include
include|#
directive|include
file|<QCoreApplication>
end_include
begin_include
include|#
directive|include
file|<private/qcore_unix_p.h>
end_include
begin_include
include|#
directive|include
file|<linux/input.h>
end_include
begin_comment
comment|//#define QT_QPA_KEYMAP_DEBUG
end_comment
begin_ifdef
ifdef|#
directive|ifdef
name|QT_QPA_KEYMAP_DEBUG
end_ifdef
begin_include
include|#
directive|include
file|<qdebug.h>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_comment
comment|// simple builtin US keymap
end_comment
begin_include
include|#
directive|include
file|"qevdevkeyboard_defaultmap_p.h"
end_include
begin_constructor
DECL|function|QEvdevKeyboardHandler
name|QEvdevKeyboardHandler
operator|::
name|QEvdevKeyboardHandler
parameter_list|(
specifier|const
name|QString
modifier|&
name|device
parameter_list|,
name|int
name|fd
parameter_list|,
name|bool
name|disableZap
parameter_list|,
name|bool
name|enableCompose
parameter_list|,
specifier|const
name|QString
modifier|&
name|keymapFile
parameter_list|)
member_init_list|:
name|m_device
argument_list|(
name|device
argument_list|)
member_init_list|,
name|m_fd
argument_list|(
name|fd
argument_list|)
member_init_list|,
name|m_modifiers
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|m_composing
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|m_dead_unicode
argument_list|(
literal|0xffff
argument_list|)
member_init_list|,
name|m_no_zap
argument_list|(
name|disableZap
argument_list|)
member_init_list|,
name|m_do_compose
argument_list|(
name|enableCompose
argument_list|)
member_init_list|,
name|m_keymap
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|m_keymap_size
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|m_keycompose
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|m_keycompose_size
argument_list|(
literal|0
argument_list|)
block|{
ifdef|#
directive|ifdef
name|QT_QPA_KEYMAP_DEBUG
name|qWarning
argument_list|()
operator|<<
literal|"Create keyboard handler with for device"
operator|<<
name|device
expr_stmt|;
endif|#
directive|endif
name|setObjectName
argument_list|(
name|QLatin1String
argument_list|(
literal|"LinuxInput Keyboard Handler"
argument_list|)
argument_list|)
expr_stmt|;
name|memset
argument_list|(
name|m_locks
argument_list|,
literal|0
argument_list|,
sizeof|sizeof
argument_list|(
name|m_locks
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|keymapFile
operator|.
name|isEmpty
argument_list|()
operator|||
operator|!
name|loadKeymap
argument_list|(
name|keymapFile
argument_list|)
condition|)
name|unloadKeymap
argument_list|()
expr_stmt|;
comment|// socket notifier for events on the keyboard device
name|QSocketNotifier
modifier|*
name|notifier
decl_stmt|;
name|notifier
operator|=
operator|new
name|QSocketNotifier
argument_list|(
name|m_fd
argument_list|,
name|QSocketNotifier
operator|::
name|Read
argument_list|,
name|this
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|notifier
argument_list|,
name|SIGNAL
argument_list|(
name|activated
argument_list|(
name|int
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|readKeycode
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_destructor
DECL|function|~QEvdevKeyboardHandler
name|QEvdevKeyboardHandler
operator|::
name|~
name|QEvdevKeyboardHandler
parameter_list|()
block|{
name|unloadKeymap
argument_list|()
expr_stmt|;
if|if
condition|(
name|m_fd
operator|>=
literal|0
condition|)
name|qt_safe_close
argument_list|(
name|m_fd
argument_list|)
expr_stmt|;
block|}
end_destructor
begin_function
DECL|function|create
name|QEvdevKeyboardHandler
modifier|*
name|QEvdevKeyboardHandler
operator|::
name|create
parameter_list|(
specifier|const
name|QString
modifier|&
name|device
parameter_list|,
specifier|const
name|QString
modifier|&
name|specification
parameter_list|,
specifier|const
name|QString
modifier|&
name|defaultKeymapFile
parameter_list|)
block|{
ifdef|#
directive|ifdef
name|QT_QPA_KEYMAP_DEBUG
name|qWarning
argument_list|()
operator|<<
literal|"Try to create keyboard handler for"
operator|<<
name|device
operator|<<
name|specification
expr_stmt|;
endif|#
directive|endif
name|QString
name|keymapFile
init|=
name|defaultKeymapFile
decl_stmt|;
name|int
name|repeatDelay
init|=
literal|400
decl_stmt|;
name|int
name|repeatRate
init|=
literal|80
decl_stmt|;
name|bool
name|disableZap
init|=
literal|false
decl_stmt|;
name|bool
name|enableCompose
init|=
literal|false
decl_stmt|;
name|int
name|grab
init|=
literal|0
decl_stmt|;
name|QStringList
name|args
init|=
name|specification
operator|.
name|split
argument_list|(
name|QLatin1Char
argument_list|(
literal|':'
argument_list|)
argument_list|)
decl_stmt|;
foreach|foreach
control|(
specifier|const
name|QString
modifier|&
name|arg
decl|,
name|args
control|)
block|{
if|if
condition|(
name|arg
operator|.
name|startsWith
argument_list|(
name|QLatin1String
argument_list|(
literal|"keymap="
argument_list|)
argument_list|)
condition|)
name|keymapFile
operator|=
name|arg
operator|.
name|mid
argument_list|(
literal|7
argument_list|)
expr_stmt|;
elseif|else
if|if
condition|(
name|arg
operator|==
name|QLatin1String
argument_list|(
literal|"disable-zap"
argument_list|)
condition|)
name|disableZap
operator|=
literal|true
expr_stmt|;
elseif|else
if|if
condition|(
name|arg
operator|==
name|QLatin1String
argument_list|(
literal|"enable-compose"
argument_list|)
condition|)
name|enableCompose
operator|=
literal|true
expr_stmt|;
elseif|else
if|if
condition|(
name|arg
operator|.
name|startsWith
argument_list|(
name|QLatin1String
argument_list|(
literal|"repeat-delay="
argument_list|)
argument_list|)
condition|)
name|repeatDelay
operator|=
name|arg
operator|.
name|mid
argument_list|(
literal|13
argument_list|)
operator|.
name|toInt
argument_list|()
expr_stmt|;
elseif|else
if|if
condition|(
name|arg
operator|.
name|startsWith
argument_list|(
name|QLatin1String
argument_list|(
literal|"repeat-rate="
argument_list|)
argument_list|)
condition|)
name|repeatRate
operator|=
name|arg
operator|.
name|mid
argument_list|(
literal|12
argument_list|)
operator|.
name|toInt
argument_list|()
expr_stmt|;
elseif|else
if|if
condition|(
name|arg
operator|.
name|startsWith
argument_list|(
name|QLatin1String
argument_list|(
literal|"grab="
argument_list|)
argument_list|)
condition|)
name|grab
operator|=
name|arg
operator|.
name|mid
argument_list|(
literal|5
argument_list|)
operator|.
name|toInt
argument_list|()
expr_stmt|;
block|}
ifdef|#
directive|ifdef
name|QT_QPA_KEYMAP_DEBUG
name|qWarning
argument_list|()
operator|<<
literal|"Opening keyboard at"
operator|<<
name|device
expr_stmt|;
endif|#
directive|endif
name|int
name|fd
decl_stmt|;
name|fd
operator|=
name|qt_safe_open
argument_list|(
name|device
operator|.
name|toLocal8Bit
argument_list|()
operator|.
name|constData
argument_list|()
argument_list|,
name|O_RDONLY
operator||
name|O_NDELAY
argument_list|,
literal|0
argument_list|)
expr_stmt|;
if|if
condition|(
name|fd
operator|>=
literal|0
condition|)
block|{
operator|::
name|ioctl
argument_list|(
name|fd
argument_list|,
name|EVIOCGRAB
argument_list|,
name|grab
argument_list|)
expr_stmt|;
if|if
condition|(
name|repeatDelay
operator|>
literal|0
operator|&&
name|repeatRate
operator|>
literal|0
condition|)
block|{
name|int
name|kbdrep
index|[
literal|2
index|]
init|=
block|{
name|repeatDelay
block|,
name|repeatRate
block|}
decl_stmt|;
operator|::
name|ioctl
argument_list|(
name|fd
argument_list|,
name|EVIOCSREP
argument_list|,
name|kbdrep
argument_list|)
expr_stmt|;
block|}
return|return
operator|new
name|QEvdevKeyboardHandler
argument_list|(
name|device
argument_list|,
name|fd
argument_list|,
name|disableZap
argument_list|,
name|enableCompose
argument_list|,
name|keymapFile
argument_list|)
return|;
block|}
else|else
block|{
name|qWarning
argument_list|(
literal|"Cannot open keyboard input device '%s': %s"
argument_list|,
name|qPrintable
argument_list|(
name|device
argument_list|)
argument_list|,
name|strerror
argument_list|(
name|errno
argument_list|)
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
block|}
end_function
begin_function
DECL|function|switchLed
name|void
name|QEvdevKeyboardHandler
operator|::
name|switchLed
parameter_list|(
name|int
name|led
parameter_list|,
name|bool
name|state
parameter_list|)
block|{
ifdef|#
directive|ifdef
name|QT_QPA_KEYMAP_DEBUG
name|qWarning
argument_list|()
operator|<<
literal|"switchLed"
operator|<<
name|led
operator|<<
name|state
expr_stmt|;
endif|#
directive|endif
name|struct
operator|::
name|input_event
name|led_ie
decl_stmt|;
operator|::
name|gettimeofday
argument_list|(
operator|&
name|led_ie
operator|.
name|time
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|led_ie
operator|.
name|type
operator|=
name|EV_LED
expr_stmt|;
name|led_ie
operator|.
name|code
operator|=
name|led
expr_stmt|;
name|led_ie
operator|.
name|value
operator|=
name|state
expr_stmt|;
name|qt_safe_write
argument_list|(
name|m_fd
argument_list|,
operator|&
name|led_ie
argument_list|,
sizeof|sizeof
argument_list|(
name|led_ie
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|readKeycode
name|void
name|QEvdevKeyboardHandler
operator|::
name|readKeycode
parameter_list|()
block|{
ifdef|#
directive|ifdef
name|QT_QPA_KEYMAP_DEBUG
name|qWarning
argument_list|()
operator|<<
literal|"Read new keycode on"
operator|<<
name|m_device
expr_stmt|;
endif|#
directive|endif
name|struct
operator|::
name|input_event
name|buffer
index|[
literal|32
index|]
decl_stmt|;
name|int
name|n
init|=
literal|0
decl_stmt|;
forever|forever
block|{
name|int
name|result
init|=
name|qt_safe_read
argument_list|(
name|m_fd
argument_list|,
cast|reinterpret_cast
argument_list|<
name|char
operator|*
argument_list|>
argument_list|(
name|buffer
argument_list|)
operator|+
name|n
argument_list|,
sizeof|sizeof
argument_list|(
name|buffer
argument_list|)
operator|-
name|n
argument_list|)
decl_stmt|;
if|if
condition|(
name|result
operator|==
literal|0
condition|)
block|{
name|qWarning
argument_list|(
literal|"Got EOF from the input device."
argument_list|)
expr_stmt|;
return|return;
block|}
elseif|else
if|if
condition|(
name|result
operator|<
literal|0
condition|)
block|{
if|if
condition|(
name|errno
operator|!=
name|EINTR
operator|&&
name|errno
operator|!=
name|EAGAIN
condition|)
block|{
name|qWarning
argument_list|(
literal|"Could not read from input device: %s"
argument_list|,
name|strerror
argument_list|(
name|errno
argument_list|)
argument_list|)
expr_stmt|;
return|return;
block|}
block|}
else|else
block|{
name|n
operator|+=
name|result
expr_stmt|;
if|if
condition|(
name|n
operator|%
sizeof|sizeof
argument_list|(
name|buffer
index|[
literal|0
index|]
argument_list|)
operator|==
literal|0
condition|)
break|break;
block|}
block|}
name|n
operator|/=
sizeof|sizeof
argument_list|(
name|buffer
index|[
literal|0
index|]
argument_list|)
expr_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|n
condition|;
operator|++
name|i
control|)
block|{
if|if
condition|(
name|buffer
index|[
name|i
index|]
operator|.
name|type
operator|!=
name|EV_KEY
condition|)
continue|continue;
name|quint16
name|code
init|=
name|buffer
index|[
name|i
index|]
operator|.
name|code
decl_stmt|;
name|qint32
name|value
init|=
name|buffer
index|[
name|i
index|]
operator|.
name|value
decl_stmt|;
name|QEvdevKeyboardHandler
operator|::
name|KeycodeAction
name|ka
decl_stmt|;
name|ka
operator|=
name|processKeycode
argument_list|(
name|code
argument_list|,
name|value
operator|!=
literal|0
argument_list|,
name|value
operator|==
literal|2
argument_list|)
expr_stmt|;
switch|switch
condition|(
name|ka
condition|)
block|{
case|case
name|QEvdevKeyboardHandler
operator|::
name|CapsLockOn
case|:
case|case
name|QEvdevKeyboardHandler
operator|::
name|CapsLockOff
case|:
name|switchLed
argument_list|(
name|LED_CAPSL
argument_list|,
name|ka
operator|==
name|QEvdevKeyboardHandler
operator|::
name|CapsLockOn
argument_list|)
expr_stmt|;
break|break;
case|case
name|QEvdevKeyboardHandler
operator|::
name|NumLockOn
case|:
case|case
name|QEvdevKeyboardHandler
operator|::
name|NumLockOff
case|:
name|switchLed
argument_list|(
name|LED_NUML
argument_list|,
name|ka
operator|==
name|QEvdevKeyboardHandler
operator|::
name|NumLockOn
argument_list|)
expr_stmt|;
break|break;
case|case
name|QEvdevKeyboardHandler
operator|::
name|ScrollLockOn
case|:
case|case
name|QEvdevKeyboardHandler
operator|::
name|ScrollLockOff
case|:
name|switchLed
argument_list|(
name|LED_SCROLLL
argument_list|,
name|ka
operator|==
name|QEvdevKeyboardHandler
operator|::
name|ScrollLockOn
argument_list|)
expr_stmt|;
break|break;
default|default:
comment|// ignore console switching and reboot
break|break;
block|}
block|}
block|}
end_function
begin_function
DECL|function|processKeyEvent
name|void
name|QEvdevKeyboardHandler
operator|::
name|processKeyEvent
parameter_list|(
name|int
name|nativecode
parameter_list|,
name|int
name|unicode
parameter_list|,
name|int
name|qtcode
parameter_list|,
name|Qt
operator|::
name|KeyboardModifiers
name|modifiers
parameter_list|,
name|bool
name|isPress
parameter_list|,
name|bool
name|autoRepeat
parameter_list|)
block|{
name|QWindowSystemInterface
operator|::
name|handleExtendedKeyEvent
argument_list|(
literal|0
argument_list|,
operator|(
name|isPress
condition|?
name|QEvent
operator|::
name|KeyPress
else|:
name|QEvent
operator|::
name|KeyRelease
operator|)
argument_list|,
name|qtcode
argument_list|,
name|modifiers
argument_list|,
name|nativecode
operator|+
literal|8
argument_list|,
literal|0
argument_list|,
name|int
argument_list|(
name|modifiers
argument_list|)
argument_list|,
operator|(
name|unicode
operator|!=
literal|0xffff
operator|)
condition|?
name|QString
argument_list|(
name|unicode
argument_list|)
else|:
name|QString
argument_list|()
argument_list|,
name|autoRepeat
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|processKeycode
name|QEvdevKeyboardHandler
operator|::
name|KeycodeAction
name|QEvdevKeyboardHandler
operator|::
name|processKeycode
parameter_list|(
name|quint16
name|keycode
parameter_list|,
name|bool
name|pressed
parameter_list|,
name|bool
name|autorepeat
parameter_list|)
block|{
name|KeycodeAction
name|result
init|=
name|None
decl_stmt|;
name|bool
name|first_press
init|=
name|pressed
operator|&&
operator|!
name|autorepeat
decl_stmt|;
specifier|const
name|QEvdevKeyboardMap
operator|::
name|Mapping
modifier|*
name|map_plain
init|=
literal|0
decl_stmt|;
specifier|const
name|QEvdevKeyboardMap
operator|::
name|Mapping
modifier|*
name|map_withmod
init|=
literal|0
decl_stmt|;
name|quint8
name|modifiers
init|=
name|m_modifiers
decl_stmt|;
comment|// get a specific and plain mapping for the keycode and the current modifiers
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|m_keymap_size
operator|&&
operator|!
operator|(
name|map_plain
operator|&&
name|map_withmod
operator|)
condition|;
operator|++
name|i
control|)
block|{
specifier|const
name|QEvdevKeyboardMap
operator|::
name|Mapping
modifier|*
name|m
init|=
name|m_keymap
operator|+
name|i
decl_stmt|;
if|if
condition|(
name|m
operator|->
name|keycode
operator|==
name|keycode
condition|)
block|{
if|if
condition|(
name|m
operator|->
name|modifiers
operator|==
literal|0
condition|)
name|map_plain
operator|=
name|m
expr_stmt|;
name|quint8
name|testmods
init|=
name|m_modifiers
decl_stmt|;
if|if
condition|(
name|m_locks
index|[
literal|0
index|]
comment|/*CapsLock*/
operator|&&
operator|(
name|m
operator|->
name|flags
operator|&
name|QEvdevKeyboardMap
operator|::
name|IsLetter
operator|)
condition|)
name|testmods
operator|^=
name|QEvdevKeyboardMap
operator|::
name|ModShift
expr_stmt|;
if|if
condition|(
name|m
operator|->
name|modifiers
operator|==
name|testmods
condition|)
name|map_withmod
operator|=
name|m
expr_stmt|;
block|}
block|}
if|if
condition|(
name|m_locks
index|[
literal|0
index|]
comment|/*CapsLock*/
operator|&&
name|map_withmod
operator|&&
operator|(
name|map_withmod
operator|->
name|flags
operator|&
name|QEvdevKeyboardMap
operator|::
name|IsLetter
operator|)
condition|)
name|modifiers
operator|^=
name|QEvdevKeyboardMap
operator|::
name|ModShift
expr_stmt|;
ifdef|#
directive|ifdef
name|QT_QPA_KEYMAP_DEBUG
name|qWarning
argument_list|(
literal|"Processing key event: keycode=%3d, modifiers=%02x pressed=%d, autorepeat=%d  |  plain=%d, withmod=%d, size=%d"
argument_list|, \
name|keycode
argument_list|,
name|modifiers
argument_list|,
name|pressed
condition|?
literal|1
else|:
literal|0
argument_list|,
name|autorepeat
condition|?
literal|1
else|:
literal|0
argument_list|, \
name|map_plain
condition|?
name|map_plain
operator|-
name|m_keymap
else|:
operator|-
literal|1
argument_list|, \
name|map_withmod
condition|?
name|map_withmod
operator|-
name|m_keymap
else|:
operator|-
literal|1
argument_list|, \
name|m_keymap_size
argument_list|)
expr_stmt|;
endif|#
directive|endif
specifier|const
name|QEvdevKeyboardMap
operator|::
name|Mapping
modifier|*
name|it
init|=
name|map_withmod
condition|?
name|map_withmod
else|:
name|map_plain
decl_stmt|;
if|if
condition|(
operator|!
name|it
condition|)
block|{
ifdef|#
directive|ifdef
name|QT_QPA_KEYMAP_DEBUG
comment|// we couldn't even find a plain mapping
name|qWarning
argument_list|(
literal|"Could not find a suitable mapping for keycode: %3d, modifiers: %02x"
argument_list|,
name|keycode
argument_list|,
name|modifiers
argument_list|)
expr_stmt|;
endif|#
directive|endif
return|return
name|result
return|;
block|}
name|bool
name|skip
init|=
literal|false
decl_stmt|;
name|quint16
name|unicode
init|=
name|it
operator|->
name|unicode
decl_stmt|;
name|quint32
name|qtcode
init|=
name|it
operator|->
name|qtcode
decl_stmt|;
if|if
condition|(
operator|(
name|it
operator|->
name|flags
operator|&
name|QEvdevKeyboardMap
operator|::
name|IsModifier
operator|)
operator|&&
name|it
operator|->
name|special
condition|)
block|{
comment|// this is a modifier, i.e. Shift, Alt, ...
if|if
condition|(
name|pressed
condition|)
name|m_modifiers
operator||=
name|quint8
argument_list|(
name|it
operator|->
name|special
argument_list|)
expr_stmt|;
else|else
name|m_modifiers
operator|&=
operator|~
name|quint8
argument_list|(
name|it
operator|->
name|special
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|qtcode
operator|>=
name|Qt
operator|::
name|Key_CapsLock
operator|&&
name|qtcode
operator|<=
name|Qt
operator|::
name|Key_ScrollLock
condition|)
block|{
comment|// (Caps|Num|Scroll)Lock
if|if
condition|(
name|first_press
condition|)
block|{
name|quint8
modifier|&
name|lock
init|=
name|m_locks
index|[
name|qtcode
operator|-
name|Qt
operator|::
name|Key_CapsLock
index|]
decl_stmt|;
name|lock
operator|^=
literal|1
expr_stmt|;
switch|switch
condition|(
name|qtcode
condition|)
block|{
case|case
name|Qt
operator|::
name|Key_CapsLock
case|:
name|result
operator|=
name|lock
condition|?
name|CapsLockOn
else|:
name|CapsLockOff
expr_stmt|;
break|break;
case|case
name|Qt
operator|::
name|Key_NumLock
case|:
name|result
operator|=
name|lock
condition|?
name|NumLockOn
else|:
name|NumLockOff
expr_stmt|;
break|break;
case|case
name|Qt
operator|::
name|Key_ScrollLock
case|:
name|result
operator|=
name|lock
condition|?
name|ScrollLockOn
else|:
name|ScrollLockOff
expr_stmt|;
break|break;
default|default                :
break|break;
block|}
block|}
block|}
elseif|else
if|if
condition|(
operator|(
name|it
operator|->
name|flags
operator|&
name|QEvdevKeyboardMap
operator|::
name|IsSystem
operator|)
operator|&&
name|it
operator|->
name|special
operator|&&
name|first_press
condition|)
block|{
switch|switch
condition|(
name|it
operator|->
name|special
condition|)
block|{
case|case
name|QEvdevKeyboardMap
operator|::
name|SystemReboot
case|:
name|result
operator|=
name|Reboot
expr_stmt|;
break|break;
case|case
name|QEvdevKeyboardMap
operator|::
name|SystemZap
case|:
if|if
condition|(
operator|!
name|m_no_zap
condition|)
name|qApp
operator|->
name|quit
argument_list|()
expr_stmt|;
break|break;
case|case
name|QEvdevKeyboardMap
operator|::
name|SystemConsolePrevious
case|:
name|result
operator|=
name|PreviousConsole
expr_stmt|;
break|break;
case|case
name|QEvdevKeyboardMap
operator|::
name|SystemConsoleNext
case|:
name|result
operator|=
name|NextConsole
expr_stmt|;
break|break;
default|default:
if|if
condition|(
name|it
operator|->
name|special
operator|>=
name|QEvdevKeyboardMap
operator|::
name|SystemConsoleFirst
operator|&&
name|it
operator|->
name|special
operator|<=
name|QEvdevKeyboardMap
operator|::
name|SystemConsoleLast
condition|)
block|{
name|result
operator|=
name|KeycodeAction
argument_list|(
name|SwitchConsoleFirst
operator|+
operator|(
operator|(
name|it
operator|->
name|special
operator|&
name|QEvdevKeyboardMap
operator|::
name|SystemConsoleMask
operator|)
operator|&
name|SwitchConsoleMask
operator|)
argument_list|)
expr_stmt|;
block|}
break|break;
block|}
name|skip
operator|=
literal|true
expr_stmt|;
comment|// no need to tell Qt about it
block|}
elseif|else
if|if
condition|(
operator|(
name|qtcode
operator|==
name|Qt
operator|::
name|Key_Multi_key
operator|)
operator|&&
name|m_do_compose
condition|)
block|{
comment|// the Compose key was pressed
if|if
condition|(
name|first_press
condition|)
name|m_composing
operator|=
literal|2
expr_stmt|;
name|skip
operator|=
literal|true
expr_stmt|;
block|}
elseif|else
if|if
condition|(
operator|(
name|it
operator|->
name|flags
operator|&
name|QEvdevKeyboardMap
operator|::
name|IsDead
operator|)
operator|&&
name|m_do_compose
condition|)
block|{
comment|// a Dead key was pressed
if|if
condition|(
name|first_press
operator|&&
name|m_composing
operator|==
literal|1
operator|&&
name|m_dead_unicode
operator|==
name|unicode
condition|)
block|{
comment|// twice
name|m_composing
operator|=
literal|0
expr_stmt|;
name|qtcode
operator|=
name|Qt
operator|::
name|Key_unknown
expr_stmt|;
comment|// otherwise it would be Qt::Key_Dead...
block|}
elseif|else
if|if
condition|(
name|first_press
operator|&&
name|unicode
operator|!=
literal|0xffff
condition|)
block|{
name|m_dead_unicode
operator|=
name|unicode
expr_stmt|;
name|m_composing
operator|=
literal|1
expr_stmt|;
name|skip
operator|=
literal|true
expr_stmt|;
block|}
else|else
block|{
name|skip
operator|=
literal|true
expr_stmt|;
block|}
block|}
if|if
condition|(
operator|!
name|skip
condition|)
block|{
comment|// a normal key was pressed
specifier|const
name|int
name|modmask
init|=
name|Qt
operator|::
name|ShiftModifier
operator||
name|Qt
operator|::
name|ControlModifier
operator||
name|Qt
operator|::
name|AltModifier
operator||
name|Qt
operator|::
name|MetaModifier
operator||
name|Qt
operator|::
name|KeypadModifier
decl_stmt|;
comment|// we couldn't find a specific mapping for the current modifiers,
comment|// or that mapping didn't have special modifiers:
comment|// so just report the plain mapping with additional modifiers.
if|if
condition|(
operator|(
name|it
operator|==
name|map_plain
operator|&&
name|it
operator|!=
name|map_withmod
operator|)
operator|||
operator|(
name|map_withmod
operator|&&
operator|!
operator|(
name|map_withmod
operator|->
name|qtcode
operator|&
name|modmask
operator|)
operator|)
condition|)
block|{
name|qtcode
operator||=
name|QEvdevKeyboardHandler
operator|::
name|toQtModifiers
argument_list|(
name|modifiers
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|m_composing
operator|==
literal|2
operator|&&
name|first_press
operator|&&
operator|!
operator|(
name|it
operator|->
name|flags
operator|&
name|QEvdevKeyboardMap
operator|::
name|IsModifier
operator|)
condition|)
block|{
comment|// the last key press was the Compose key
if|if
condition|(
name|unicode
operator|!=
literal|0xffff
condition|)
block|{
name|int
name|idx
init|=
literal|0
decl_stmt|;
comment|// check if this code is in the compose table at all
for|for
control|(
init|;
name|idx
operator|<
name|m_keycompose_size
condition|;
operator|++
name|idx
control|)
block|{
if|if
condition|(
name|m_keycompose
index|[
name|idx
index|]
operator|.
name|first
operator|==
name|unicode
condition|)
break|break;
block|}
if|if
condition|(
name|idx
operator|<
name|m_keycompose_size
condition|)
block|{
comment|// found it -> simulate a Dead key press
name|m_dead_unicode
operator|=
name|unicode
expr_stmt|;
name|unicode
operator|=
literal|0xffff
expr_stmt|;
name|m_composing
operator|=
literal|1
expr_stmt|;
name|skip
operator|=
literal|true
expr_stmt|;
block|}
else|else
block|{
name|m_composing
operator|=
literal|0
expr_stmt|;
block|}
block|}
else|else
block|{
name|m_composing
operator|=
literal|0
expr_stmt|;
block|}
block|}
elseif|else
if|if
condition|(
name|m_composing
operator|==
literal|1
operator|&&
name|first_press
operator|&&
operator|!
operator|(
name|it
operator|->
name|flags
operator|&
name|QEvdevKeyboardMap
operator|::
name|IsModifier
operator|)
condition|)
block|{
comment|// the last key press was a Dead key
name|bool
name|valid
init|=
literal|false
decl_stmt|;
if|if
condition|(
name|unicode
operator|!=
literal|0xffff
condition|)
block|{
name|int
name|idx
init|=
literal|0
decl_stmt|;
comment|// check if this code is in the compose table at all
for|for
control|(
init|;
name|idx
operator|<
name|m_keycompose_size
condition|;
operator|++
name|idx
control|)
block|{
if|if
condition|(
name|m_keycompose
index|[
name|idx
index|]
operator|.
name|first
operator|==
name|m_dead_unicode
operator|&&
name|m_keycompose
index|[
name|idx
index|]
operator|.
name|second
operator|==
name|unicode
condition|)
break|break;
block|}
if|if
condition|(
name|idx
operator|<
name|m_keycompose_size
condition|)
block|{
name|quint16
name|composed
init|=
name|m_keycompose
index|[
name|idx
index|]
operator|.
name|result
decl_stmt|;
if|if
condition|(
name|composed
operator|!=
literal|0xffff
condition|)
block|{
name|unicode
operator|=
name|composed
expr_stmt|;
name|qtcode
operator|=
name|Qt
operator|::
name|Key_unknown
expr_stmt|;
name|valid
operator|=
literal|true
expr_stmt|;
block|}
block|}
block|}
if|if
condition|(
operator|!
name|valid
condition|)
block|{
name|unicode
operator|=
name|m_dead_unicode
expr_stmt|;
name|qtcode
operator|=
name|Qt
operator|::
name|Key_unknown
expr_stmt|;
block|}
name|m_composing
operator|=
literal|0
expr_stmt|;
block|}
if|if
condition|(
operator|!
name|skip
condition|)
block|{
ifdef|#
directive|ifdef
name|QT_QPA_KEYMAP_DEBUG
name|qWarning
argument_list|(
literal|"Processing: uni=%04x, qt=%08x, qtmod=%08x"
argument_list|,
name|unicode
argument_list|,
name|qtcode
operator|&
operator|~
name|modmask
argument_list|,
operator|(
name|qtcode
operator|&
name|modmask
operator|)
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|// send the result to the server
name|processKeyEvent
argument_list|(
name|keycode
argument_list|,
name|unicode
argument_list|,
name|qtcode
operator|&
operator|~
name|modmask
argument_list|,
name|Qt
operator|::
name|KeyboardModifiers
argument_list|(
name|qtcode
operator|&
name|modmask
argument_list|)
argument_list|,
name|pressed
argument_list|,
name|autorepeat
argument_list|)
expr_stmt|;
block|}
block|}
return|return
name|result
return|;
block|}
end_function
begin_function
DECL|function|unloadKeymap
name|void
name|QEvdevKeyboardHandler
operator|::
name|unloadKeymap
parameter_list|()
block|{
ifdef|#
directive|ifdef
name|QT_QPA_KEYMAP_DEBUG
name|qWarning
argument_list|()
operator|<<
literal|"Unload current keymap and restore built-in"
expr_stmt|;
endif|#
directive|endif
if|if
condition|(
name|m_keymap
operator|&&
name|m_keymap
operator|!=
name|s_keymap_default
condition|)
operator|delete
index|[]
name|m_keymap
expr_stmt|;
if|if
condition|(
name|m_keycompose
operator|&&
name|m_keycompose
operator|!=
name|s_keycompose_default
condition|)
operator|delete
index|[]
name|m_keycompose
expr_stmt|;
name|m_keymap
operator|=
name|s_keymap_default
expr_stmt|;
name|m_keymap_size
operator|=
sizeof|sizeof
argument_list|(
name|s_keymap_default
argument_list|)
operator|/
sizeof|sizeof
argument_list|(
name|s_keymap_default
index|[
literal|0
index|]
argument_list|)
expr_stmt|;
name|m_keycompose
operator|=
name|s_keycompose_default
expr_stmt|;
name|m_keycompose_size
operator|=
sizeof|sizeof
argument_list|(
name|s_keycompose_default
argument_list|)
operator|/
sizeof|sizeof
argument_list|(
name|s_keycompose_default
index|[
literal|0
index|]
argument_list|)
expr_stmt|;
comment|// reset state, so we could switch keymaps at runtime
name|m_modifiers
operator|=
literal|0
expr_stmt|;
name|memset
argument_list|(
name|m_locks
argument_list|,
literal|0
argument_list|,
sizeof|sizeof
argument_list|(
name|m_locks
argument_list|)
argument_list|)
expr_stmt|;
name|m_composing
operator|=
literal|0
expr_stmt|;
name|m_dead_unicode
operator|=
literal|0xffff
expr_stmt|;
block|}
end_function
begin_function
DECL|function|loadKeymap
name|bool
name|QEvdevKeyboardHandler
operator|::
name|loadKeymap
parameter_list|(
specifier|const
name|QString
modifier|&
name|file
parameter_list|)
block|{
ifdef|#
directive|ifdef
name|QT_QPA_KEYMAP_DEBUG
name|qWarning
argument_list|()
operator|<<
literal|"Load keymap"
operator|<<
name|file
expr_stmt|;
endif|#
directive|endif
name|QFile
name|f
argument_list|(
name|file
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|f
operator|.
name|open
argument_list|(
name|QIODevice
operator|::
name|ReadOnly
argument_list|)
condition|)
block|{
name|qWarning
argument_list|(
literal|"Could not open keymap file '%s'"
argument_list|,
name|qPrintable
argument_list|(
name|file
argument_list|)
argument_list|)
expr_stmt|;
return|return
literal|false
return|;
block|}
comment|// .qmap files have a very simple structure:
comment|// quint32 magic           (QKeyboard::FileMagic)
comment|// quint32 version         (1)
comment|// quint32 keymap_size     (# of struct QKeyboard::Mappings)
comment|// quint32 keycompose_size (# of struct QKeyboard::Composings)
comment|// all QKeyboard::Mappings via QDataStream::operator(<<|>>)
comment|// all QKeyboard::Composings via QDataStream::operator(<<|>>)
name|quint32
name|qmap_magic
decl_stmt|,
name|qmap_version
decl_stmt|,
name|qmap_keymap_size
decl_stmt|,
name|qmap_keycompose_size
decl_stmt|;
name|QDataStream
name|ds
argument_list|(
operator|&
name|f
argument_list|)
decl_stmt|;
name|ds
operator|>>
name|qmap_magic
operator|>>
name|qmap_version
operator|>>
name|qmap_keymap_size
operator|>>
name|qmap_keycompose_size
expr_stmt|;
if|if
condition|(
name|ds
operator|.
name|status
argument_list|()
operator|!=
name|QDataStream
operator|::
name|Ok
operator|||
name|qmap_magic
operator|!=
name|QEvdevKeyboardMap
operator|::
name|FileMagic
operator|||
name|qmap_version
operator|!=
literal|1
operator|||
name|qmap_keymap_size
operator|==
literal|0
condition|)
block|{
name|qWarning
argument_list|(
literal|"'%s' is ot a valid.qmap keymap file."
argument_list|,
name|qPrintable
argument_list|(
name|file
argument_list|)
argument_list|)
expr_stmt|;
return|return
literal|false
return|;
block|}
name|QEvdevKeyboardMap
operator|::
name|Mapping
modifier|*
name|qmap_keymap
init|=
operator|new
name|QEvdevKeyboardMap
operator|::
name|Mapping
index|[
name|qmap_keymap_size
index|]
decl_stmt|;
name|QEvdevKeyboardMap
operator|::
name|Composing
modifier|*
name|qmap_keycompose
init|=
name|qmap_keycompose_size
condition|?
operator|new
name|QEvdevKeyboardMap
operator|::
name|Composing
index|[
name|qmap_keycompose_size
index|]
else|:
literal|0
decl_stmt|;
for|for
control|(
name|quint32
name|i
init|=
literal|0
init|;
name|i
operator|<
name|qmap_keymap_size
condition|;
operator|++
name|i
control|)
name|ds
operator|>>
name|qmap_keymap
index|[
name|i
index|]
expr_stmt|;
for|for
control|(
name|quint32
name|i
init|=
literal|0
init|;
name|i
operator|<
name|qmap_keycompose_size
condition|;
operator|++
name|i
control|)
name|ds
operator|>>
name|qmap_keycompose
index|[
name|i
index|]
expr_stmt|;
if|if
condition|(
name|ds
operator|.
name|status
argument_list|()
operator|!=
name|QDataStream
operator|::
name|Ok
condition|)
block|{
operator|delete
index|[]
name|qmap_keymap
expr_stmt|;
operator|delete
index|[]
name|qmap_keycompose
expr_stmt|;
name|qWarning
argument_list|(
literal|"Keymap file '%s' can not be loaded."
argument_list|,
name|qPrintable
argument_list|(
name|file
argument_list|)
argument_list|)
expr_stmt|;
return|return
literal|false
return|;
block|}
comment|// unload currently active and clear state
name|unloadKeymap
argument_list|()
expr_stmt|;
name|m_keymap
operator|=
name|qmap_keymap
expr_stmt|;
name|m_keymap_size
operator|=
name|qmap_keymap_size
expr_stmt|;
name|m_keycompose
operator|=
name|qmap_keycompose
expr_stmt|;
name|m_keycompose_size
operator|=
name|qmap_keycompose_size
expr_stmt|;
name|m_do_compose
operator|=
literal|true
expr_stmt|;
return|return
literal|true
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
