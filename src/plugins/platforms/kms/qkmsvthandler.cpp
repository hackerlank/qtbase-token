begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<qkmsvthandler.h>
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
begin_include
include|#
directive|include
file|<sys/ioctl.h>
end_include
begin_include
include|#
directive|include
file|<linux/vt.h>
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
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|member|self
name|QKmsVTHandler
modifier|*
name|QKmsVTHandler
operator|::
name|self
init|=
literal|0
decl_stmt|;
end_decl_stmt
begin_constructor
DECL|function|QKmsVTHandler
name|QKmsVTHandler
operator|::
name|QKmsVTHandler
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
name|qgetenv
argument_list|(
literal|"QT_KMS_TTYKBD"
argument_list|)
operator|.
name|toInt
argument_list|()
condition|)
block|{
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
block|}
end_constructor
begin_destructor
DECL|function|~QKmsVTHandler
name|QKmsVTHandler
operator|::
name|~
name|QKmsVTHandler
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
name|QKmsVTHandler
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
name|ioctl
argument_list|(
name|m_tty
argument_list|,
name|KDSKBMODE
argument_list|,
name|m_oldKbdMode
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|crashHandler
name|void
name|QKmsVTHandler
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
