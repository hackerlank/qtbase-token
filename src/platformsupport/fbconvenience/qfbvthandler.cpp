begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2014 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia. For licensing terms and ** conditions see http://qt.digia.com/licensing. For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights. These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qfbvthandler_p.h"
end_include
begin_include
include|#
directive|include
file|<QtCore/private/qcrashhandler_p.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/private/qguiapplication_p.h>
end_include
begin_if
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_LINUX
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|QT_NO_EVDEV
argument_list|)
end_if
begin_define
DECL|macro|HAS_VT
define|#
directive|define
name|HAS_VT
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_ifdef
ifdef|#
directive|ifdef
name|HAS_VT
end_ifdef
begin_include
include|#
directive|include
file|<sys/ioctl.h>
end_include
begin_include
include|#
directive|include
file|<linux/kd.h>
end_include
begin_ifdef
ifdef|#
directive|ifdef
name|K_OFF
end_ifdef
begin_define
DECL|macro|KBD_OFF_MODE
define|#
directive|define
name|KBD_OFF_MODE
value|K_OFF
end_define
begin_else
else|#
directive|else
end_else
begin_define
DECL|macro|KBD_OFF_MODE
define|#
directive|define
name|KBD_OFF_MODE
value|K_RAW
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// HAS_VT
end_comment
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|member|self
name|QFbVtHandler
modifier|*
name|QFbVtHandler
operator|::
name|self
init|=
literal|0
decl_stmt|;
end_decl_stmt
begin_constructor
DECL|function|QFbVtHandler
name|QFbVtHandler
operator|::
name|QFbVtHandler
parameter_list|(
name|QObject
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QObject
argument_list|(
name|parent
argument_list|)
member_init_list|,
name|m_tty
argument_list|(
operator|-
literal|1
argument_list|)
block|{
name|Q_ASSERT
argument_list|(
operator|!
name|self
argument_list|)
expr_stmt|;
name|self
operator|=
name|this
expr_stmt|;
ifdef|#
directive|ifdef
name|HAS_VT
if|if
condition|(
operator|!
name|isatty
argument_list|(
literal|0
argument_list|)
condition|)
return|return;
name|m_tty
operator|=
literal|0
expr_stmt|;
operator|::
name|ioctl
argument_list|(
name|m_tty
argument_list|,
name|KDGKBMODE
argument_list|,
operator|&
name|m_oldKbdMode
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|qEnvironmentVariableIntValue
argument_list|(
literal|"QT_QPA_ENABLE_TERMINAL_KEYBOARD"
argument_list|)
condition|)
block|{
operator|::
name|ioctl
argument_list|(
name|m_tty
argument_list|,
name|KDSKBMODE
argument_list|,
name|KBD_OFF_MODE
argument_list|)
expr_stmt|;
name|QGuiApplicationPrivate
modifier|*
name|appd
init|=
name|QGuiApplicationPrivate
operator|::
name|instance
argument_list|()
decl_stmt|;
name|Q_ASSERT
argument_list|(
name|appd
argument_list|)
expr_stmt|;
name|QSegfaultHandler
operator|::
name|initialize
argument_list|(
name|appd
operator|->
name|argv
argument_list|,
name|appd
operator|->
name|argc
argument_list|)
expr_stmt|;
name|QSegfaultHandler
operator|::
name|installCrashHandler
argument_list|(
name|crashHandler
argument_list|)
expr_stmt|;
block|}
endif|#
directive|endif
block|}
end_constructor
begin_destructor
DECL|function|~QFbVtHandler
name|QFbVtHandler
operator|::
name|~
name|QFbVtHandler
parameter_list|()
block|{
name|self
operator|->
name|cleanup
argument_list|()
expr_stmt|;
name|self
operator|=
literal|0
expr_stmt|;
block|}
end_destructor
begin_function
DECL|function|cleanup
name|void
name|QFbVtHandler
operator|::
name|cleanup
parameter_list|()
block|{
if|if
condition|(
name|m_tty
operator|==
operator|-
literal|1
condition|)
return|return;
ifdef|#
directive|ifdef
name|HAS_VT
operator|::
name|ioctl
argument_list|(
name|m_tty
argument_list|,
name|KDSKBMODE
argument_list|,
name|m_oldKbdMode
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
end_function
begin_function
DECL|function|crashHandler
name|void
name|QFbVtHandler
operator|::
name|crashHandler
parameter_list|()
block|{
name|Q_ASSERT
argument_list|(
name|self
argument_list|)
expr_stmt|;
name|self
operator|->
name|cleanup
argument_list|()
expr_stmt|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
