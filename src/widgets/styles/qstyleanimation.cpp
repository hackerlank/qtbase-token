begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qstyleanimation_p.h"
end_include
begin_include
include|#
directive|include
file|<qcoreapplication.h>
end_include
begin_include
include|#
directive|include
file|<qprogressbar.h>
end_include
begin_include
include|#
directive|include
file|<qwidget.h>
end_include
begin_include
include|#
directive|include
file|<qevent.h>
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_constructor
DECL|function|QStyleAnimation
name|QStyleAnimation
operator|::
name|QStyleAnimation
parameter_list|(
name|QObject
modifier|*
name|target
parameter_list|)
member_init_list|:
name|QAbstractAnimation
argument_list|(
name|target
argument_list|)
member_init_list|,
name|_startTime
argument_list|(
name|QTime
operator|::
name|currentTime
argument_list|()
argument_list|)
block|{ }
end_constructor
begin_destructor
DECL|function|~QStyleAnimation
name|QStyleAnimation
operator|::
name|~
name|QStyleAnimation
parameter_list|()
block|{ }
end_destructor
begin_function
DECL|function|duration
name|int
name|QStyleAnimation
operator|::
name|duration
parameter_list|()
specifier|const
block|{
return|return
operator|-
literal|1
return|;
block|}
end_function
begin_function
DECL|function|target
name|QObject
modifier|*
name|QStyleAnimation
operator|::
name|target
parameter_list|()
specifier|const
block|{
return|return
name|parent
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|startTime
name|QTime
name|QStyleAnimation
operator|::
name|startTime
parameter_list|()
specifier|const
block|{
return|return
name|_startTime
return|;
block|}
end_function
begin_function
DECL|function|setStartTime
name|void
name|QStyleAnimation
operator|::
name|setStartTime
parameter_list|(
specifier|const
name|QTime
modifier|&
name|time
parameter_list|)
block|{
name|_startTime
operator|=
name|time
expr_stmt|;
block|}
end_function
begin_function
DECL|function|isUpdateNeeded
name|bool
name|QStyleAnimation
operator|::
name|isUpdateNeeded
parameter_list|()
specifier|const
block|{
return|return
literal|true
return|;
block|}
end_function
begin_function
DECL|function|updateCurrentTime
name|void
name|QStyleAnimation
operator|::
name|updateCurrentTime
parameter_list|(
name|int
parameter_list|)
block|{
if|if
condition|(
name|QObject
modifier|*
name|tgt
init|=
name|target
argument_list|()
condition|)
block|{
if|if
condition|(
name|tgt
operator|->
name|isWidgetType
argument_list|()
condition|)
block|{
name|QWidget
modifier|*
name|widget
init|=
cast|static_cast
argument_list|<
name|QWidget
operator|*
argument_list|>
argument_list|(
name|tgt
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|widget
operator|->
name|isVisible
argument_list|()
operator|||
name|widget
operator|->
name|window
argument_list|()
operator|->
name|isMinimized
argument_list|()
condition|)
name|stop
argument_list|()
expr_stmt|;
block|}
if|if
condition|(
name|isUpdateNeeded
argument_list|()
condition|)
block|{
name|QEvent
name|event
argument_list|(
name|QEvent
operator|::
name|StyleAnimationUpdate
argument_list|)
decl_stmt|;
name|QCoreApplication
operator|::
name|sendEvent
argument_list|(
name|tgt
argument_list|,
operator|&
name|event
argument_list|)
expr_stmt|;
block|}
block|}
block|}
end_function
begin_constructor
DECL|function|QProgressStyleAnimation
name|QProgressStyleAnimation
operator|::
name|QProgressStyleAnimation
parameter_list|(
name|int
name|speed
parameter_list|,
name|QObject
modifier|*
name|target
parameter_list|)
member_init_list|:
name|QStyleAnimation
argument_list|(
name|target
argument_list|)
member_init_list|,
name|_speed
argument_list|(
name|speed
argument_list|)
member_init_list|,
name|_step
argument_list|(
operator|-
literal|1
argument_list|)
block|{ }
end_constructor
begin_function
DECL|function|animationStep
name|int
name|QProgressStyleAnimation
operator|::
name|animationStep
parameter_list|()
specifier|const
block|{
return|return
name|currentTime
argument_list|()
operator|/
operator|(
literal|1000.0
operator|/
name|_speed
operator|)
return|;
block|}
end_function
begin_function
DECL|function|progressStep
name|int
name|QProgressStyleAnimation
operator|::
name|progressStep
parameter_list|(
name|int
name|width
parameter_list|)
specifier|const
block|{
name|int
name|step
init|=
name|animationStep
argument_list|()
decl_stmt|;
name|int
name|progress
init|=
operator|(
name|step
operator|*
name|width
operator|/
name|_speed
operator|)
operator|%
name|width
decl_stmt|;
if|if
condition|(
operator|(
operator|(
name|step
operator|*
name|width
operator|/
name|_speed
operator|)
operator|%
operator|(
literal|2
operator|*
name|width
operator|)
operator|)
operator|>=
name|width
condition|)
name|progress
operator|=
name|width
operator|-
name|progress
expr_stmt|;
return|return
name|progress
return|;
block|}
end_function
begin_function
DECL|function|speed
name|int
name|QProgressStyleAnimation
operator|::
name|speed
parameter_list|()
specifier|const
block|{
return|return
name|_speed
return|;
block|}
end_function
begin_function
DECL|function|setSpeed
name|void
name|QProgressStyleAnimation
operator|::
name|setSpeed
parameter_list|(
name|int
name|speed
parameter_list|)
block|{
name|_speed
operator|=
name|speed
expr_stmt|;
block|}
end_function
begin_function
DECL|function|isUpdateNeeded
name|bool
name|QProgressStyleAnimation
operator|::
name|isUpdateNeeded
parameter_list|()
specifier|const
block|{
name|int
name|current
init|=
name|animationStep
argument_list|()
decl_stmt|;
if|if
condition|(
name|_step
operator|==
operator|-
literal|1
operator|||
name|_step
operator|!=
name|current
condition|)
block|{
name|_step
operator|=
name|current
expr_stmt|;
return|return
literal|true
return|;
block|}
return|return
literal|false
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
