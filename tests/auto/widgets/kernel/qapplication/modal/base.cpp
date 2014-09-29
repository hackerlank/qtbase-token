begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2014 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia. For licensing terms and ** conditions see http://qt.digia.com/licensing. For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights. These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"base.h"
end_include
begin_constructor
DECL|function|base
name|base
operator|::
name|base
parameter_list|(
name|QWidget
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QWidget
argument_list|(
name|parent
argument_list|)
block|{
name|m_timer
operator|=
operator|new
name|QTimer
argument_list|(
name|this
argument_list|)
expr_stmt|;
name|m_modalStarted
operator|=
literal|false
expr_stmt|;
name|m_timer
operator|->
name|setSingleShot
argument_list|(
literal|false
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|m_timer
argument_list|,
name|SIGNAL
argument_list|(
name|timeout
argument_list|()
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|periodicTimer
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|m_timer
operator|->
name|start
argument_list|(
literal|5000
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_function
DECL|function|periodicTimer
name|void
name|base
operator|::
name|periodicTimer
parameter_list|()
block|{
if|if
condition|(
name|m_modalStarted
condition|)
name|exit
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|m_modalDialog
operator|=
operator|new
name|QDialog
argument_list|(
name|this
argument_list|)
expr_stmt|;
name|m_modalDialog
operator|->
name|setModal
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|m_modalDialog
operator|->
name|show
argument_list|()
expr_stmt|;
name|m_modalStarted
operator|=
literal|true
expr_stmt|;
block|}
end_function
end_unit
