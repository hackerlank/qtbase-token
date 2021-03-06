begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QABSTRACTANIMATION_P_H
end_ifndef
begin_define
DECL|macro|QABSTRACTANIMATION_P_H
define|#
directive|define
name|QABSTRACTANIMATION_P_H
end_define
begin_comment
comment|//
end_comment
begin_comment
comment|//  W A R N I N G
end_comment
begin_comment
comment|//  -------------
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|// This file is not part of the Qt API.
end_comment
begin_comment
comment|// This header file may change from version to
end_comment
begin_comment
comment|// version without notice, or even be removed.
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|// We mean it.
end_comment
begin_comment
comment|//
end_comment
begin_include
include|#
directive|include
file|<QtCore/qbasictimer.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qdatetime.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qtimer.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qelapsedtimer.h>
end_include
begin_include
include|#
directive|include
file|<private/qobject_p.h>
end_include
begin_include
include|#
directive|include
file|<qabstractanimation.h>
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_ANIMATION
end_ifndef
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QAnimationGroup
name|class
name|QAnimationGroup
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QAbstractAnimation
name|class
name|QAbstractAnimation
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QAbstractAnimationPrivate
range|:
name|public
name|QObjectPrivate
block|{
name|public
operator|:
name|QAbstractAnimationPrivate
argument_list|()
operator|:
name|state
argument_list|(
name|QAbstractAnimation
operator|::
name|Stopped
argument_list|)
block|,
name|direction
argument_list|(
name|QAbstractAnimation
operator|::
name|Forward
argument_list|)
block|,
name|totalCurrentTime
argument_list|(
literal|0
argument_list|)
block|,
name|currentTime
argument_list|(
literal|0
argument_list|)
block|,
name|loopCount
argument_list|(
literal|1
argument_list|)
block|,
name|currentLoop
argument_list|(
literal|0
argument_list|)
block|,
name|deleteWhenStopped
argument_list|(
name|false
argument_list|)
block|,
name|hasRegisteredTimer
argument_list|(
name|false
argument_list|)
block|,
name|isPause
argument_list|(
name|false
argument_list|)
block|,
name|isGroup
argument_list|(
name|false
argument_list|)
block|,
name|group
argument_list|(
literal|0
argument_list|)
block|{     }
name|virtual
operator|~
name|QAbstractAnimationPrivate
argument_list|()
block|{}
specifier|static
name|QAbstractAnimationPrivate
operator|*
name|get
argument_list|(
argument|QAbstractAnimation *q
argument_list|)
block|{
return|return
name|q
operator|->
name|d_func
argument_list|()
return|;
block|}
name|QAbstractAnimation
operator|::
name|State
name|state
block|;
name|QAbstractAnimation
operator|::
name|Direction
name|direction
block|;
name|void
name|setState
argument_list|(
argument|QAbstractAnimation::State state
argument_list|)
block|;
name|int
name|totalCurrentTime
block|;
name|int
name|currentTime
block|;
name|int
name|loopCount
block|;
name|int
name|currentLoop
block|;
name|bool
name|deleteWhenStopped
block|;
name|bool
name|hasRegisteredTimer
block|;
name|bool
name|isPause
block|;
name|bool
name|isGroup
block|;
name|QAnimationGroup
operator|*
name|group
block|;
name|private
operator|:
name|Q_DECLARE_PUBLIC
argument_list|(
argument|QAbstractAnimation
argument_list|)
block|}
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QUnifiedTimer
name|class
name|QUnifiedTimer
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QDefaultAnimationDriver
range|:
name|public
name|QAnimationDriver
block|{
name|Q_OBJECT
name|public
operator|:
name|QDefaultAnimationDriver
argument_list|(
name|QUnifiedTimer
operator|*
name|timer
argument_list|)
block|;
name|void
name|timerEvent
argument_list|(
argument|QTimerEvent *e
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|private
name|Q_SLOTS
operator|:
name|void
name|startTimer
argument_list|()
block|;
name|void
name|stopTimer
argument_list|()
block|;
name|private
operator|:
name|QBasicTimer
name|m_timer
block|;
name|QUnifiedTimer
operator|*
name|m_unified_timer
block|; }
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_CORE_EXPORT
name|QAnimationDriverPrivate
range|:
name|public
name|QObjectPrivate
block|{
name|public
operator|:
name|QAnimationDriverPrivate
argument_list|()
operator|:
name|running
argument_list|(
argument|false
argument_list|)
block|{}
name|QElapsedTimer
name|timer
block|;
name|bool
name|running
block|; }
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_CORE_EXPORT
name|QAbstractAnimationTimer
range|:
name|public
name|QObject
block|{
name|Q_OBJECT
name|public
operator|:
name|QAbstractAnimationTimer
argument_list|()
operator|:
name|isRegistered
argument_list|(
name|false
argument_list|)
block|,
name|isPaused
argument_list|(
name|false
argument_list|)
block|,
name|pauseDuration
argument_list|(
literal|0
argument_list|)
block|{}
name|virtual
name|void
name|updateAnimationsTime
argument_list|(
argument|qint64 delta
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|void
name|restartAnimationTimer
argument_list|()
operator|=
literal|0
block|;
name|virtual
name|int
name|runningAnimationCount
argument_list|()
operator|=
literal|0
block|;
name|bool
name|isRegistered
block|;
name|bool
name|isPaused
block|;
name|int
name|pauseDuration
block|; }
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_CORE_EXPORT
name|QUnifiedTimer
range|:
name|public
name|QObject
block|{
name|Q_OBJECT
name|private
operator|:
name|QUnifiedTimer
argument_list|()
block|;
name|public
operator|:
specifier|static
name|QUnifiedTimer
operator|*
name|instance
argument_list|()
block|;
specifier|static
name|QUnifiedTimer
operator|*
name|instance
argument_list|(
argument|bool create
argument_list|)
block|;
specifier|static
name|void
name|startAnimationTimer
argument_list|(
name|QAbstractAnimationTimer
operator|*
name|timer
argument_list|)
block|;
specifier|static
name|void
name|stopAnimationTimer
argument_list|(
name|QAbstractAnimationTimer
operator|*
name|timer
argument_list|)
block|;
specifier|static
name|void
name|pauseAnimationTimer
argument_list|(
argument|QAbstractAnimationTimer *timer
argument_list|,
argument|int duration
argument_list|)
block|;
specifier|static
name|void
name|resumeAnimationTimer
argument_list|(
name|QAbstractAnimationTimer
operator|*
name|timer
argument_list|)
block|;
comment|//defines the timing interval. Default is DEFAULT_TIMER_INTERVAL
name|void
name|setTimingInterval
argument_list|(
argument|int interval
argument_list|)
block|;
comment|/*        this allows to have a consistent timer interval at each tick from the timer        not taking the real time that passed into account.     */
name|void
name|setConsistentTiming
argument_list|(
argument|bool consistent
argument_list|)
block|{
name|consistentTiming
operator|=
name|consistent
block|; }
comment|//these facilitate fine-tuning of complex animations
name|void
name|setSlowModeEnabled
argument_list|(
argument|bool enabled
argument_list|)
block|{
name|slowMode
operator|=
name|enabled
block|; }
name|void
name|setSlowdownFactor
argument_list|(
argument|qreal factor
argument_list|)
block|{
name|slowdownFactor
operator|=
name|factor
block|; }
name|void
name|installAnimationDriver
argument_list|(
name|QAnimationDriver
operator|*
name|driver
argument_list|)
block|;
name|void
name|uninstallAnimationDriver
argument_list|(
name|QAnimationDriver
operator|*
name|driver
argument_list|)
block|;
name|bool
name|canUninstallAnimationDriver
argument_list|(
name|QAnimationDriver
operator|*
name|driver
argument_list|)
block|;
name|void
name|restart
argument_list|()
block|;
name|void
name|maybeUpdateAnimationsToCurrentTime
argument_list|()
block|;
name|void
name|updateAnimationTimers
argument_list|(
argument|qint64 currentTick
argument_list|)
block|;
comment|//useful for profiling/debugging
name|int
name|runningAnimationCount
argument_list|()
block|;
name|void
name|registerProfilerCallback
argument_list|(
name|void
argument_list|(
operator|*
name|cb
argument_list|)
argument_list|(
name|qint64
argument_list|)
argument_list|)
block|;
name|void
name|startAnimationDriver
argument_list|()
block|;
name|void
name|stopAnimationDriver
argument_list|()
block|;
name|qint64
name|elapsed
argument_list|()
specifier|const
block|;
name|protected
operator|:
name|void
name|timerEvent
argument_list|(
argument|QTimerEvent *
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|private
name|Q_SLOTS
operator|:
name|void
name|startTimers
argument_list|()
block|;
name|void
name|stopTimer
argument_list|()
block|;
name|private
operator|:
name|friend
name|class
name|QDefaultAnimationDriver
block|;
name|friend
name|class
name|QAnimationDriver
block|;
name|QAnimationDriver
operator|*
name|driver
block|;
name|QDefaultAnimationDriver
name|defaultDriver
block|;
name|QBasicTimer
name|pauseTimer
block|;
name|QElapsedTimer
name|time
block|;
name|qint64
name|lastTick
block|;
name|int
name|timingInterval
block|;
name|int
name|currentAnimationIdx
block|;
name|bool
name|insideTick
block|;
name|bool
name|insideRestart
block|;
name|bool
name|consistentTiming
block|;
name|bool
name|slowMode
block|;
name|bool
name|startTimersPending
block|;
name|bool
name|stopTimerPending
block|;
comment|// This factor will be used to divide the DEFAULT_TIMER_INTERVAL at each tick
comment|// when slowMode is enabled. Setting it to 0 or higher than DEFAULT_TIMER_INTERVAL (16)
comment|// stops all animations.
name|qreal
name|slowdownFactor
block|;
name|QList
operator|<
name|QAbstractAnimationTimer
operator|*
operator|>
name|animationTimers
block|,
name|animationTimersToStart
block|;
name|QList
operator|<
name|QAbstractAnimationTimer
operator|*
operator|>
name|pausedAnimationTimers
block|;
name|void
name|localRestart
argument_list|()
block|;
name|int
name|closestPausedAnimationTimerTimeToFinish
argument_list|()
block|;
name|void
argument_list|(
operator|*
name|profilerCallback
argument_list|)
argument_list|(
name|qint64
argument_list|)
block|;
name|qint64
name|driverStartTime
block|;
comment|// The time the animation driver was started
name|qint64
name|temporalDrift
block|;
comment|// The delta between animation driver time and wall time.
block|}
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QAnimationTimer
range|:
name|public
name|QAbstractAnimationTimer
block|{
name|Q_OBJECT
name|private
operator|:
name|QAnimationTimer
argument_list|()
block|;
name|public
operator|:
specifier|static
name|QAnimationTimer
operator|*
name|instance
argument_list|()
block|;
specifier|static
name|QAnimationTimer
operator|*
name|instance
argument_list|(
argument|bool create
argument_list|)
block|;
specifier|static
name|void
name|registerAnimation
argument_list|(
argument|QAbstractAnimation *animation
argument_list|,
argument|bool isTopLevel
argument_list|)
block|;
specifier|static
name|void
name|unregisterAnimation
argument_list|(
name|QAbstractAnimation
operator|*
name|animation
argument_list|)
block|;
comment|/*         this is used for updating the currentTime of all animations in case the pause         timer is active or, otherwise, only of the animation passed as parameter.     */
specifier|static
name|void
name|ensureTimerUpdate
argument_list|()
block|;
comment|/*         this will evaluate the need of restarting the pause timer in case there is still         some pause animations running.     */
specifier|static
name|void
name|updateAnimationTimer
argument_list|()
block|;
name|void
name|restartAnimationTimer
argument_list|()
name|Q_DECL_OVERRIDE
block|;
name|void
name|updateAnimationsTime
argument_list|(
argument|qint64 delta
argument_list|)
name|Q_DECL_OVERRIDE
block|;
comment|//useful for profiling/debugging
name|int
name|runningAnimationCount
argument_list|()
name|Q_DECL_OVERRIDE
block|{
return|return
name|animations
operator|.
name|count
argument_list|()
return|;
block|}
name|private
name|Q_SLOTS
operator|:
name|void
name|startAnimations
argument_list|()
block|;
name|void
name|stopTimer
argument_list|()
block|;
name|private
operator|:
name|qint64
name|lastTick
block|;
name|int
name|currentAnimationIdx
block|;
name|bool
name|insideTick
block|;
name|bool
name|startAnimationPending
block|;
name|bool
name|stopTimerPending
block|;
name|QList
operator|<
name|QAbstractAnimation
operator|*
operator|>
name|animations
block|,
name|animationsToStart
block|;
comment|// this is the count of running animations that are not a group neither a pause animation
name|int
name|runningLeafAnimations
block|;
name|QList
operator|<
name|QAbstractAnimation
operator|*
operator|>
name|runningPauseAnimations
block|;
name|void
name|registerRunningAnimation
argument_list|(
name|QAbstractAnimation
operator|*
name|animation
argument_list|)
block|;
name|void
name|unregisterRunningAnimation
argument_list|(
name|QAbstractAnimation
operator|*
name|animation
argument_list|)
block|;
name|int
name|closestPauseAnimationTimeToFinish
argument_list|()
block|; }
decl_stmt|;
end_decl_stmt
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|//QT_NO_ANIMATION
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|//QABSTRACTANIMATION_P_H
end_comment
end_unit
