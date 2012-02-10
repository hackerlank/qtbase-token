begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qevdevkeyboardmanager.h"
end_include
begin_include
include|#
directive|include
file|<QStringList>
end_include
begin_include
include|#
directive|include
file|<QDebug>
end_include
begin_include
include|#
directive|include
file|<QCoreApplication>
end_include
begin_include
include|#
directive|include
file|<linux/input.h>
end_include
begin_include
include|#
directive|include
file|<linux/kd.h>
end_include
begin_comment
comment|//#define QT_QPA_KEYMAP_DEBUG
end_comment
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_constructor
DECL|function|QEvdevKeyboardManager
name|QEvdevKeyboardManager
operator|::
name|QEvdevKeyboardManager
parameter_list|(
specifier|const
name|QString
modifier|&
name|key
parameter_list|,
specifier|const
name|QString
modifier|&
name|specification
parameter_list|)
member_init_list|:
name|m_udev
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|m_udevMonitor
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|m_udevMonitorFileDescriptor
argument_list|(
operator|-
literal|1
argument_list|)
member_init_list|,
name|m_udevSocketNotifier
argument_list|(
literal|0
argument_list|)
block|{
name|Q_UNUSED
argument_list|(
name|key
argument_list|)
expr_stmt|;
name|bool
name|useUDev
init|=
literal|false
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
name|QStringList
name|devices
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
literal|"udev"
argument_list|)
operator|&&
operator|!
name|arg
operator|.
name|contains
argument_list|(
literal|"no"
argument_list|)
condition|)
block|{
name|useUDev
operator|=
literal|true
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|arg
operator|.
name|startsWith
argument_list|(
literal|"/dev/"
argument_list|)
condition|)
block|{
comment|// if device is specified try to use it
name|devices
operator|.
name|append
argument_list|(
name|arg
argument_list|)
expr_stmt|;
name|args
operator|.
name|removeAll
argument_list|(
name|arg
argument_list|)
expr_stmt|;
block|}
block|}
name|m_spec
operator|=
name|args
operator|.
name|join
argument_list|(
literal|":"
argument_list|)
expr_stmt|;
comment|// add all keyboards for devices specified in the argument list
foreach|foreach
control|(
specifier|const
name|QString
modifier|&
name|device
decl|,
name|devices
control|)
name|addKeyboard
argument_list|(
name|device
argument_list|)
expr_stmt|;
comment|// no udev and no devices specified, try a fallback
if|if
condition|(
operator|!
name|useUDev
operator|&&
name|devices
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|addKeyboard
argument_list|()
expr_stmt|;
return|return;
block|}
name|m_udev
operator|=
name|udev_new
argument_list|()
expr_stmt|;
if|if
condition|(
operator|!
name|m_udev
condition|)
block|{
name|qWarning
argument_list|()
operator|<<
literal|"Failed to read udev configuration. Try to open a keyboard without it"
expr_stmt|;
name|addKeyboard
argument_list|()
expr_stmt|;
block|}
else|else
block|{
comment|// Look for already attached devices:
name|parseConnectedDevices
argument_list|()
expr_stmt|;
comment|// Watch for device add/remove
name|startWatching
argument_list|()
expr_stmt|;
block|}
block|}
end_constructor
begin_destructor
DECL|function|~QEvdevKeyboardManager
name|QEvdevKeyboardManager
operator|::
name|~
name|QEvdevKeyboardManager
parameter_list|()
block|{
comment|// cleanup udev related resources
name|stopWatching
argument_list|()
expr_stmt|;
if|if
condition|(
name|m_udev
condition|)
name|udev_unref
argument_list|(
name|m_udev
argument_list|)
expr_stmt|;
comment|// cleanup all resources of connected keyboards
name|qDeleteAll
argument_list|(
name|m_keyboards
argument_list|)
expr_stmt|;
name|m_keyboards
operator|.
name|clear
argument_list|()
expr_stmt|;
block|}
end_destructor
begin_function
DECL|function|addKeyboard
name|void
name|QEvdevKeyboardManager
operator|::
name|addKeyboard
parameter_list|(
specifier|const
name|QString
modifier|&
name|devnode
parameter_list|)
block|{
name|QString
name|specification
init|=
name|m_spec
decl_stmt|;
name|QString
name|deviceString
init|=
name|devnode
decl_stmt|;
if|if
condition|(
operator|!
name|deviceString
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|specification
operator|.
name|append
argument_list|(
literal|":"
argument_list|)
expr_stmt|;
name|specification
operator|.
name|append
argument_list|(
name|deviceString
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|deviceString
operator|=
literal|"default"
expr_stmt|;
block|}
ifdef|#
directive|ifdef
name|QT_QPA_KEYMAP_DEBUG
name|qWarning
argument_list|()
operator|<<
literal|"Adding keyboard at"
operator|<<
name|deviceString
expr_stmt|;
endif|#
directive|endif
name|QEvdevKeyboardHandler
modifier|*
name|keyboard
decl_stmt|;
name|keyboard
operator|=
name|QEvdevKeyboardHandler
operator|::
name|createLinuxInputKeyboardHandler
argument_list|(
literal|"EvdevKeyboard"
argument_list|,
name|specification
argument_list|)
expr_stmt|;
if|if
condition|(
name|keyboard
condition|)
name|m_keyboards
operator|.
name|insert
argument_list|(
name|deviceString
argument_list|,
name|keyboard
argument_list|)
expr_stmt|;
else|else
name|qWarning
argument_list|()
operator|<<
literal|"Failed to open keyboard"
expr_stmt|;
block|}
end_function
begin_function
DECL|function|removeKeyboard
name|void
name|QEvdevKeyboardManager
operator|::
name|removeKeyboard
parameter_list|(
specifier|const
name|QString
modifier|&
name|devnode
parameter_list|)
block|{
if|if
condition|(
name|m_keyboards
operator|.
name|contains
argument_list|(
name|devnode
argument_list|)
condition|)
block|{
ifdef|#
directive|ifdef
name|QT_QPA_KEYMAP_DEBUG
name|qWarning
argument_list|()
operator|<<
literal|"Removing keyboard at"
operator|<<
name|devnode
expr_stmt|;
endif|#
directive|endif
name|QEvdevKeyboardHandler
modifier|*
name|keyboard
init|=
name|m_keyboards
operator|.
name|value
argument_list|(
name|devnode
argument_list|)
decl_stmt|;
name|m_keyboards
operator|.
name|remove
argument_list|(
name|devnode
argument_list|)
expr_stmt|;
operator|delete
name|keyboard
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|startWatching
name|void
name|QEvdevKeyboardManager
operator|::
name|startWatching
parameter_list|()
block|{
name|m_udevMonitor
operator|=
name|udev_monitor_new_from_netlink
argument_list|(
name|m_udev
argument_list|,
literal|"udev"
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|m_udevMonitor
condition|)
block|{
ifdef|#
directive|ifdef
name|QT_QPA_KEYMAP_DEBUG
name|qWarning
argument_list|(
literal|"Unable to create an Udev monitor. No devices can be detected."
argument_list|)
expr_stmt|;
endif|#
directive|endif
return|return;
block|}
name|udev_monitor_filter_add_match_subsystem_devtype
argument_list|(
name|m_udevMonitor
argument_list|,
literal|"input"
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
name|udev_monitor_enable_receiving
argument_list|(
name|m_udevMonitor
argument_list|)
expr_stmt|;
name|m_udevMonitorFileDescriptor
operator|=
name|udev_monitor_get_fd
argument_list|(
name|m_udevMonitor
argument_list|)
expr_stmt|;
name|m_udevSocketNotifier
operator|=
operator|new
name|QSocketNotifier
argument_list|(
name|m_udevMonitorFileDescriptor
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
name|m_udevSocketNotifier
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
name|deviceDetected
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|stopWatching
name|void
name|QEvdevKeyboardManager
operator|::
name|stopWatching
parameter_list|()
block|{
if|if
condition|(
name|m_udevSocketNotifier
condition|)
operator|delete
name|m_udevSocketNotifier
expr_stmt|;
if|if
condition|(
name|m_udevMonitor
condition|)
name|udev_monitor_unref
argument_list|(
name|m_udevMonitor
argument_list|)
expr_stmt|;
name|m_udevSocketNotifier
operator|=
literal|0
expr_stmt|;
name|m_udevMonitor
operator|=
literal|0
expr_stmt|;
name|m_udevMonitorFileDescriptor
operator|=
literal|0
expr_stmt|;
block|}
end_function
begin_function
DECL|function|deviceDetected
name|void
name|QEvdevKeyboardManager
operator|::
name|deviceDetected
parameter_list|()
block|{
if|if
condition|(
operator|!
name|m_udevMonitor
condition|)
return|return;
name|struct
name|udev_device
modifier|*
name|dev
decl_stmt|;
name|dev
operator|=
name|udev_monitor_receive_device
argument_list|(
name|m_udevMonitor
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|dev
condition|)
return|return;
if|if
condition|(
name|qstrcmp
argument_list|(
name|udev_device_get_action
argument_list|(
name|dev
argument_list|)
argument_list|,
literal|"add"
argument_list|)
operator|==
literal|0
condition|)
block|{
name|checkDevice
argument_list|(
name|dev
argument_list|)
expr_stmt|;
block|}
else|else
block|{
comment|// We can't determine what the device was, so we handle false positives outside of this class
name|QString
name|str
init|=
name|udev_device_get_devnode
argument_list|(
name|dev
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|str
operator|.
name|isEmpty
argument_list|()
condition|)
name|removeKeyboard
argument_list|(
name|str
argument_list|)
expr_stmt|;
block|}
name|udev_device_unref
argument_list|(
name|dev
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|parseConnectedDevices
name|void
name|QEvdevKeyboardManager
operator|::
name|parseConnectedDevices
parameter_list|()
block|{
name|struct
name|udev_enumerate
modifier|*
name|enumerate
decl_stmt|;
name|struct
name|udev_list_entry
modifier|*
name|devices
decl_stmt|;
name|struct
name|udev_list_entry
modifier|*
name|dev_list_entry
decl_stmt|;
name|struct
name|udev_device
modifier|*
name|dev
decl_stmt|;
specifier|const
name|char
modifier|*
name|str
decl_stmt|;
name|enumerate
operator|=
name|udev_enumerate_new
argument_list|(
name|m_udev
argument_list|)
expr_stmt|;
name|udev_enumerate_add_match_subsystem
argument_list|(
name|enumerate
argument_list|,
literal|"input"
argument_list|)
expr_stmt|;
name|udev_enumerate_scan_devices
argument_list|(
name|enumerate
argument_list|)
expr_stmt|;
name|devices
operator|=
name|udev_enumerate_get_list_entry
argument_list|(
name|enumerate
argument_list|)
expr_stmt|;
name|udev_list_entry_foreach
argument_list|(
argument|dev_list_entry
argument_list|,
argument|devices
argument_list|)
block|{
name|str
operator|=
name|udev_list_entry_get_name
argument_list|(
name|dev_list_entry
argument_list|)
expr_stmt|;
name|dev
operator|=
name|udev_device_new_from_syspath
argument_list|(
name|m_udev
argument_list|,
name|str
argument_list|)
expr_stmt|;
name|checkDevice
argument_list|(
name|dev
argument_list|)
expr_stmt|;
block|}
name|udev_enumerate_unref
argument_list|(
name|enumerate
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|checkDevice
name|void
name|QEvdevKeyboardManager
operator|::
name|checkDevice
parameter_list|(
name|udev_device
modifier|*
name|dev
parameter_list|)
block|{
specifier|const
name|char
modifier|*
name|str
decl_stmt|;
name|QString
name|devnode
decl_stmt|;
name|str
operator|=
name|udev_device_get_devnode
argument_list|(
name|dev
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|str
condition|)
return|return;
name|devnode
operator|=
name|str
expr_stmt|;
name|dev
operator|=
name|udev_device_get_parent_with_subsystem_devtype
argument_list|(
name|dev
argument_list|,
literal|"input"
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|dev
condition|)
return|return;
name|str
operator|=
name|udev_device_get_sysattr_value
argument_list|(
name|dev
argument_list|,
literal|"capabilities/key"
argument_list|)
expr_stmt|;
name|QStringList
name|val
init|=
name|QString
argument_list|(
name|str
argument_list|)
operator|.
name|split
argument_list|(
literal|' '
argument_list|,
name|QString
operator|::
name|SkipEmptyParts
argument_list|)
decl_stmt|;
name|bool
name|ok
decl_stmt|;
name|unsigned
name|long
name|long
name|keys
init|=
name|val
operator|.
name|last
argument_list|()
operator|.
name|toULongLong
argument_list|(
operator|&
name|ok
argument_list|,
literal|16
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|ok
condition|)
return|return;
comment|// Tests if the letter Q is valid for the device.  We may want to alter this test, but it seems mostly reliable.
name|bool
name|test
init|=
operator|(
name|keys
operator|>>
name|KEY_Q
operator|)
operator|&
literal|1
decl_stmt|;
if|if
condition|(
name|test
condition|)
block|{
name|addKeyboard
argument_list|(
name|devnode
argument_list|)
expr_stmt|;
return|return;
block|}
block|}
end_function
end_unit
