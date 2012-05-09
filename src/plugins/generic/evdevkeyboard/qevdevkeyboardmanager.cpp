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
file|<QCoreApplication>
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
file|<QDebug>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_function
name|QT_BEGIN_NAMESPACE
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
block|{
name|Q_UNUSED
argument_list|(
name|key
argument_list|)
expr_stmt|;
ifndef|#
directive|ifndef
name|QT_NO_LIBUDEV
name|bool
name|useUDev
init|=
literal|true
decl_stmt|;
else|#
directive|else
name|bool
name|useUDev
init|=
literal|false
decl_stmt|;
endif|#
directive|endif
comment|// QT_NO_LIBUDEV
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
name|QLatin1String
argument_list|(
literal|"udev"
argument_list|)
argument_list|)
operator|&&
name|arg
operator|.
name|contains
argument_list|(
name|QLatin1String
argument_list|(
literal|"no"
argument_list|)
argument_list|)
condition|)
block|{
name|useUDev
operator|=
literal|false
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|arg
operator|.
name|startsWith
argument_list|(
name|QLatin1String
argument_list|(
literal|"/dev/"
argument_list|)
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
comment|// build new specification without /dev/ elements
name|m_spec
operator|=
name|args
operator|.
name|join
argument_list|(
name|QLatin1String
argument_list|(
literal|":"
argument_list|)
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
ifndef|#
directive|ifndef
name|QT_NO_LIBUDEV
if|if
condition|(
name|useUDev
condition|)
block|{
ifdef|#
directive|ifdef
name|QT_QPA_KEYMAP_DEBUG
name|qWarning
argument_list|()
operator|<<
literal|"Use UDev for device discovery"
expr_stmt|;
endif|#
directive|endif
name|m_udeviceHelper
operator|=
name|QUDeviceHelper
operator|::
name|createUDeviceHelper
argument_list|(
name|QUDeviceHelper
operator|::
name|UDev_Keyboard
argument_list|,
name|this
argument_list|)
expr_stmt|;
if|if
condition|(
name|m_udeviceHelper
condition|)
block|{
comment|// scan and add already connected keyboards
name|QStringList
name|devices
init|=
name|m_udeviceHelper
operator|->
name|scanConnectedDevices
argument_list|()
decl_stmt|;
foreach|foreach
control|(
name|QString
name|device
decl|,
name|devices
control|)
block|{
name|addKeyboard
argument_list|(
name|device
argument_list|)
expr_stmt|;
block|}
name|connect
argument_list|(
name|m_udeviceHelper
argument_list|,
name|SIGNAL
argument_list|(
name|deviceDetected
argument_list|(
name|QString
argument_list|,
name|QUDeviceTypes
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|addKeyboard
argument_list|(
name|QString
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|m_udeviceHelper
argument_list|,
name|SIGNAL
argument_list|(
name|deviceRemoved
argument_list|(
name|QString
argument_list|,
name|QUDeviceTypes
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|removeKeyboard
argument_list|(
name|QString
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
block|}
block|}
else|#
directive|else
name|Q_UNUSED
argument_list|(
argument|useUDev
argument_list|)
endif|#
directive|endif
comment|// QT_NO_LIBUDEV
block|}
end_function
begin_destructor
DECL|function|~QEvdevKeyboardManager
name|QEvdevKeyboardManager
operator|::
name|~
name|QEvdevKeyboardManager
parameter_list|()
block|{
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
name|deviceNode
parameter_list|)
block|{
ifdef|#
directive|ifdef
name|QT_QPA_KEYMAP_DEBUG
name|qWarning
argument_list|()
operator|<<
literal|"Adding keyboard at"
operator|<<
name|deviceNode
expr_stmt|;
endif|#
directive|endif
name|QString
name|specification
init|=
name|m_spec
decl_stmt|;
if|if
condition|(
operator|!
name|deviceNode
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|specification
operator|.
name|append
argument_list|(
name|QLatin1Char
argument_list|(
literal|':'
argument_list|)
argument_list|)
expr_stmt|;
name|specification
operator|.
name|append
argument_list|(
name|deviceNode
argument_list|)
expr_stmt|;
block|}
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
name|QLatin1String
argument_list|(
literal|"EvdevKeyboard"
argument_list|)
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
name|deviceNode
argument_list|,
name|keyboard
argument_list|)
expr_stmt|;
else|else
name|qWarning
argument_list|(
literal|"Failed to open keyboard"
argument_list|)
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
name|deviceNode
parameter_list|)
block|{
if|if
condition|(
name|m_keyboards
operator|.
name|contains
argument_list|(
name|deviceNode
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
name|deviceNode
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
name|deviceNode
argument_list|)
decl_stmt|;
name|m_keyboards
operator|.
name|remove
argument_list|(
name|deviceNode
argument_list|)
expr_stmt|;
operator|delete
name|keyboard
expr_stmt|;
block|}
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
