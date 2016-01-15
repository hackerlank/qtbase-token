begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_comment
comment|/*!     \class QPauseAnimation     \inmodule QtCore     \brief The QPauseAnimation class provides a pause for QSequentialAnimationGroup.     \since 4.6     \ingroup animation      If you wish to introduce a delay between animations in a     QSequentialAnimationGroup, you can insert a QPauseAnimation. This     class does not animate anything, but does not     \l{QAbstractAnimation::finished()}{finish} before a specified     number of milliseconds have elapsed from when it was started. You     specify the duration of the pause in the constructor. It can also     be set directly with setDuration().      It is not necessary to construct a QPauseAnimation yourself.     QSequentialAnimationGroup provides the convenience functions     \l{QSequentialAnimationGroup::}{addPause()} and     \l{QSequentialAnimationGroup::}{insertPause()}. These functions     simply take the number of milliseconds the pause should last.      \sa QSequentialAnimationGroup */
end_comment
begin_include
include|#
directive|include
file|"qpauseanimation.h"
end_include
begin_include
include|#
directive|include
file|"qabstractanimation_p.h"
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_ANIMATION
end_ifndef
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_class
DECL|class|QPauseAnimationPrivate
class|class
name|QPauseAnimationPrivate
super|:
specifier|public
name|QAbstractAnimationPrivate
block|{
public|public:
DECL|function|QPauseAnimationPrivate
name|QPauseAnimationPrivate
parameter_list|()
member_init_list|:
name|QAbstractAnimationPrivate
argument_list|()
member_init_list|,
name|duration
argument_list|(
literal|250
argument_list|)
block|{
name|isPause
operator|=
literal|true
expr_stmt|;
block|}
DECL|member|duration
name|int
name|duration
decl_stmt|;
block|}
class|;
end_class
begin_comment
comment|/*!     Constructs a QPauseAnimation.     \a parent is passed to QObject's constructor.     The default duration is 0. */
end_comment
begin_constructor
DECL|function|QPauseAnimation
name|QPauseAnimation
operator|::
name|QPauseAnimation
parameter_list|(
name|QObject
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QAbstractAnimation
argument_list|(
operator|*
operator|new
name|QPauseAnimationPrivate
argument_list|,
name|parent
argument_list|)
block|{ }
end_constructor
begin_comment
comment|/*!     Constructs a QPauseAnimation.     \a msecs is the duration of the pause.     \a parent is passed to QObject's constructor. */
end_comment
begin_constructor
DECL|function|QPauseAnimation
name|QPauseAnimation
operator|::
name|QPauseAnimation
parameter_list|(
name|int
name|msecs
parameter_list|,
name|QObject
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QAbstractAnimation
argument_list|(
operator|*
operator|new
name|QPauseAnimationPrivate
argument_list|,
name|parent
argument_list|)
block|{
name|setDuration
argument_list|(
name|msecs
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_comment
comment|/*!     Destroys the pause animation. */
end_comment
begin_destructor
DECL|function|~QPauseAnimation
name|QPauseAnimation
operator|::
name|~
name|QPauseAnimation
parameter_list|()
block|{ }
end_destructor
begin_comment
comment|/*!     \property QPauseAnimation::duration     \brief the duration of the pause.      The duration of the pause. The duration should not be negative.     The default duration is 250 milliseconds. */
end_comment
begin_function
DECL|function|duration
name|int
name|QPauseAnimation
operator|::
name|duration
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QPauseAnimation
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|duration
return|;
block|}
end_function
begin_function
DECL|function|setDuration
name|void
name|QPauseAnimation
operator|::
name|setDuration
parameter_list|(
name|int
name|msecs
parameter_list|)
block|{
if|if
condition|(
name|msecs
operator|<
literal|0
condition|)
block|{
name|qWarning
argument_list|(
literal|"QPauseAnimation::setDuration: cannot set a negative duration"
argument_list|)
expr_stmt|;
return|return;
block|}
name|Q_D
argument_list|(
name|QPauseAnimation
argument_list|)
expr_stmt|;
name|d
operator|->
name|duration
operator|=
name|msecs
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     \reimp  */
end_comment
begin_function
DECL|function|event
name|bool
name|QPauseAnimation
operator|::
name|event
parameter_list|(
name|QEvent
modifier|*
name|e
parameter_list|)
block|{
return|return
name|QAbstractAnimation
operator|::
name|event
argument_list|(
name|e
argument_list|)
return|;
block|}
end_function
begin_comment
comment|/*!     \reimp  */
end_comment
begin_function
DECL|function|updateCurrentTime
name|void
name|QPauseAnimation
operator|::
name|updateCurrentTime
parameter_list|(
name|int
parameter_list|)
block|{ }
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_include
include|#
directive|include
file|"moc_qpauseanimation.cpp"
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|//QT_NO_ANIMATION
end_comment
end_unit
