begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** No Commercial Usage ** This file contains pre-release code and may not be distributed. ** You may use this file in accordance with the terms and conditions ** contained in the Technology Preview License Agreement accompanying ** this package. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights.  These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** If you have questions regarding the use of this file, please contact ** Nokia at qt-info@nokia.com. ** ** ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QTIMELINE_H
end_ifndef
begin_define
DECL|macro|QTIMELINE_H
define|#
directive|define
name|QTIMELINE_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qeasingcurve.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qobject.h>
end_include
begin_decl_stmt
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
name|QT_MODULE
argument_list|(
name|Core
argument_list|)
name|class
name|QTimeLinePrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_CORE_EXPORT
name|QTimeLine
range|:
name|public
name|QObject
block|{
name|Q_OBJECT
name|Q_PROPERTY
argument_list|(
argument|int duration READ duration WRITE setDuration
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|int updateInterval READ updateInterval WRITE setUpdateInterval
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|int currentTime READ currentTime WRITE setCurrentTime
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|Direction direction READ direction WRITE setDirection
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|int loopCount READ loopCount WRITE setLoopCount
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|CurveShape curveShape READ curveShape WRITE setCurveShape
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|QEasingCurve easingCurve READ easingCurve WRITE setEasingCurve
argument_list|)
name|public
operator|:
expr|enum
name|State
block|{
name|NotRunning
block|,
name|Paused
block|,
name|Running
block|}
block|;     enum
name|Direction
block|{
name|Forward
block|,
name|Backward
block|}
block|;     enum
name|CurveShape
block|{
name|EaseInCurve
block|,
name|EaseOutCurve
block|,
name|EaseInOutCurve
block|,
name|LinearCurve
block|,
name|SineCurve
block|,
name|CosineCurve
block|}
block|;
name|explicit
name|QTimeLine
argument_list|(
argument|int duration =
literal|1000
argument_list|,
argument|QObject *parent =
literal|0
argument_list|)
block|;
name|virtual
operator|~
name|QTimeLine
argument_list|()
block|;
name|State
name|state
argument_list|()
specifier|const
block|;
name|int
name|loopCount
argument_list|()
specifier|const
block|;
name|void
name|setLoopCount
argument_list|(
argument|int count
argument_list|)
block|;
name|Direction
name|direction
argument_list|()
specifier|const
block|;
name|void
name|setDirection
argument_list|(
argument|Direction direction
argument_list|)
block|;
name|int
name|duration
argument_list|()
specifier|const
block|;
name|void
name|setDuration
argument_list|(
argument|int duration
argument_list|)
block|;
name|int
name|startFrame
argument_list|()
specifier|const
block|;
name|void
name|setStartFrame
argument_list|(
argument|int frame
argument_list|)
block|;
name|int
name|endFrame
argument_list|()
specifier|const
block|;
name|void
name|setEndFrame
argument_list|(
argument|int frame
argument_list|)
block|;
name|void
name|setFrameRange
argument_list|(
argument|int startFrame
argument_list|,
argument|int endFrame
argument_list|)
block|;
name|int
name|updateInterval
argument_list|()
specifier|const
block|;
name|void
name|setUpdateInterval
argument_list|(
argument|int interval
argument_list|)
block|;
name|CurveShape
name|curveShape
argument_list|()
specifier|const
block|;
name|void
name|setCurveShape
argument_list|(
argument|CurveShape shape
argument_list|)
block|;
name|QEasingCurve
name|easingCurve
argument_list|()
specifier|const
block|;
name|void
name|setEasingCurve
argument_list|(
specifier|const
name|QEasingCurve
operator|&
name|curve
argument_list|)
block|;
name|int
name|currentTime
argument_list|()
specifier|const
block|;
name|int
name|currentFrame
argument_list|()
specifier|const
block|;
name|qreal
name|currentValue
argument_list|()
specifier|const
block|;
name|int
name|frameForTime
argument_list|(
argument|int msec
argument_list|)
specifier|const
block|;
name|virtual
name|qreal
name|valueForTime
argument_list|(
argument|int msec
argument_list|)
specifier|const
block|;
name|public
name|Q_SLOTS
operator|:
name|void
name|start
argument_list|()
block|;
name|void
name|resume
argument_list|()
block|;
name|void
name|stop
argument_list|()
block|;
name|void
name|setPaused
argument_list|(
argument|bool paused
argument_list|)
block|;
name|void
name|setCurrentTime
argument_list|(
argument|int msec
argument_list|)
block|;
name|void
name|toggleDirection
argument_list|()
block|;
name|Q_SIGNALS
operator|:
name|void
name|valueChanged
argument_list|(
argument|qreal x
argument_list|)
block|;
name|void
name|frameChanged
argument_list|(
name|int
argument_list|)
block|;
name|void
name|stateChanged
argument_list|(
argument|QTimeLine::State newState
argument_list|)
block|;
name|void
name|finished
argument_list|()
block|;
name|protected
operator|:
name|void
name|timerEvent
argument_list|(
name|QTimerEvent
operator|*
name|event
argument_list|)
block|;
name|private
operator|:
name|Q_DISABLE_COPY
argument_list|(
argument|QTimeLine
argument_list|)
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QTimeLine
argument_list|)
block|}
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|QT_END_NAMESPACE
name|QT_END_HEADER
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
end_unit
