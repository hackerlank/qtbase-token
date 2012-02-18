begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QEASINGCURVE_H
end_ifndef
begin_define
DECL|macro|QEASINGCURVE_H
define|#
directive|define
name|QEASINGCURVE_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qglobal.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qobjectdefs.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qvector.h>
end_include
begin_if
if|#
directive|if
name|QT_DEPRECATED_SINCE
argument_list|(
literal|5
operator|,
literal|0
argument_list|)
end_if
begin_include
include|#
directive|include
file|<QtCore/qlist.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qpoint.h>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_decl_stmt
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
DECL|variable|QEasingCurvePrivate
name|class
name|QEasingCurvePrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QPointF
name|class
name|QPointF
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_CORE_EXPORT
name|QEasingCurve
block|{
name|Q_GADGET
name|Q_ENUMS
argument_list|(
name|Type
argument_list|)
name|public
range|:     enum
name|Type
block|{
name|Linear
block|,
name|InQuad
block|,
name|OutQuad
block|,
name|InOutQuad
block|,
name|OutInQuad
block|,
name|InCubic
block|,
name|OutCubic
block|,
name|InOutCubic
block|,
name|OutInCubic
block|,
name|InQuart
block|,
name|OutQuart
block|,
name|InOutQuart
block|,
name|OutInQuart
block|,
name|InQuint
block|,
name|OutQuint
block|,
name|InOutQuint
block|,
name|OutInQuint
block|,
name|InSine
block|,
name|OutSine
block|,
name|InOutSine
block|,
name|OutInSine
block|,
name|InExpo
block|,
name|OutExpo
block|,
name|InOutExpo
block|,
name|OutInExpo
block|,
name|InCirc
block|,
name|OutCirc
block|,
name|InOutCirc
block|,
name|OutInCirc
block|,
name|InElastic
block|,
name|OutElastic
block|,
name|InOutElastic
block|,
name|OutInElastic
block|,
name|InBack
block|,
name|OutBack
block|,
name|InOutBack
block|,
name|OutInBack
block|,
name|InBounce
block|,
name|OutBounce
block|,
name|InOutBounce
block|,
name|OutInBounce
block|,
name|InCurve
block|,
name|OutCurve
block|,
name|SineCurve
block|,
name|CosineCurve
block|,
name|BezierSpline
block|,
name|TCBSpline
block|,
name|Custom
block|,
name|NCurveTypes
block|}
decl_stmt|;
name|QEasingCurve
argument_list|(
argument|Type type = Linear
argument_list|)
empty_stmt|;
name|QEasingCurve
argument_list|(
specifier|const
name|QEasingCurve
operator|&
name|other
argument_list|)
expr_stmt|;
operator|~
name|QEasingCurve
argument_list|()
expr_stmt|;
name|QEasingCurve
modifier|&
name|operator
init|=
operator|(
specifier|const
name|QEasingCurve
operator|&
name|other
operator|)
decl_stmt|;
ifdef|#
directive|ifdef
name|Q_COMPILER_RVALUE_REFS
name|QEasingCurve
argument_list|(
name|QEasingCurve
operator|&&
name|other
argument_list|)
operator|:
name|d_ptr
argument_list|(
argument|other.d_ptr
argument_list|)
block|{
name|other
operator|.
name|d_ptr
operator|=
literal|0
block|; }
name|QEasingCurve
operator|&
name|operator
operator|=
operator|(
name|QEasingCurve
operator|&&
name|other
operator|)
block|{
name|qSwap
argument_list|(
name|d_ptr
argument_list|,
name|other
operator|.
name|d_ptr
argument_list|)
block|;
return|return
operator|*
name|this
return|;
block|}
endif|#
directive|endif
specifier|inline
name|void
name|swap
parameter_list|(
name|QEasingCurve
modifier|&
name|other
parameter_list|)
block|{
name|qSwap
argument_list|(
name|d_ptr
argument_list|,
name|other
operator|.
name|d_ptr
argument_list|)
expr_stmt|;
block|}
name|bool
name|operator
operator|==
operator|(
specifier|const
name|QEasingCurve
operator|&
name|other
operator|)
specifier|const
expr_stmt|;
specifier|inline
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|QEasingCurve
operator|&
name|other
operator|)
specifier|const
block|{
return|return
operator|!
operator|(
name|this
operator|->
name|operator
operator|==
operator|(
name|other
operator|)
operator|)
return|;
block|}
name|qreal
name|amplitude
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setAmplitude
parameter_list|(
name|qreal
name|amplitude
parameter_list|)
function_decl|;
name|qreal
name|period
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setPeriod
parameter_list|(
name|qreal
name|period
parameter_list|)
function_decl|;
name|qreal
name|overshoot
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setOvershoot
parameter_list|(
name|qreal
name|overshoot
parameter_list|)
function_decl|;
name|void
name|addCubicBezierSegment
parameter_list|(
specifier|const
name|QPointF
modifier|&
name|c1
parameter_list|,
specifier|const
name|QPointF
modifier|&
name|c2
parameter_list|,
specifier|const
name|QPointF
modifier|&
name|endPoint
parameter_list|)
function_decl|;
name|void
name|addTCBSegment
parameter_list|(
specifier|const
name|QPointF
modifier|&
name|nextPoint
parameter_list|,
name|qreal
name|t
parameter_list|,
name|qreal
name|c
parameter_list|,
name|qreal
name|b
parameter_list|)
function_decl|;
name|QVector
operator|<
name|QPointF
operator|>
name|toCubicSpline
argument_list|()
specifier|const
expr_stmt|;
if|#
directive|if
name|QT_DEPRECATED_SINCE
argument_list|(
literal|5
operator|,
literal|0
argument_list|)
name|QT_DEPRECATED
name|QList
operator|<
name|QPointF
operator|>
name|cubicBezierSpline
argument_list|()
specifier|const
block|{
return|return
name|toCubicSpline
argument_list|()
operator|.
name|toList
argument_list|()
return|;
block|}
endif|#
directive|endif
name|Type
name|type
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setType
parameter_list|(
name|Type
name|type
parameter_list|)
function_decl|;
typedef|typedef
name|qreal
function_decl|(
modifier|*
name|EasingFunction
function_decl|)
parameter_list|(
name|qreal
name|progress
parameter_list|)
function_decl|;
name|void
name|setCustomType
parameter_list|(
name|EasingFunction
name|func
parameter_list|)
function_decl|;
name|EasingFunction
name|customType
argument_list|()
specifier|const
expr_stmt|;
name|qreal
name|valueForProgress
argument_list|(
name|qreal
name|progress
argument_list|)
decl|const
decl_stmt|;
name|private
label|:
name|QEasingCurvePrivate
modifier|*
name|d_ptr
decl_stmt|;
ifndef|#
directive|ifndef
name|QT_NO_DEBUG_STREAM
name|friend
name|Q_CORE_EXPORT
name|QDebug
name|operator
operator|<<
operator|(
name|QDebug
name|debug
operator|,
specifier|const
name|QEasingCurve
operator|&
name|item
operator|)
expr_stmt|;
endif|#
directive|endif
ifndef|#
directive|ifndef
name|QT_NO_DATASTREAM
name|friend
name|Q_CORE_EXPORT
name|QDataStream
operator|&
name|operator
operator|<<
operator|(
name|QDataStream
operator|&
operator|,
specifier|const
name|QEasingCurve
operator|&
operator|)
expr_stmt|;
name|friend
name|Q_CORE_EXPORT
name|QDataStream
operator|&
name|operator
operator|>>
operator|(
name|QDataStream
operator|&
operator|,
name|QEasingCurve
operator|&
operator|)
expr_stmt|;
endif|#
directive|endif
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_expr_stmt
name|Q_DECLARE_TYPEINFO
argument_list|(
name|QEasingCurve
argument_list|,
name|Q_MOVABLE_TYPE
argument_list|)
expr_stmt|;
end_expr_stmt
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_DEBUG_STREAM
end_ifndef
begin_expr_stmt
name|Q_CORE_EXPORT
name|QDebug
name|operator
operator|<<
operator|(
name|QDebug
name|debug
operator|,
specifier|const
name|QEasingCurve
operator|&
name|item
operator|)
expr_stmt|;
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_DATASTREAM
end_ifndef
begin_expr_stmt
name|Q_CORE_EXPORT
name|QDataStream
operator|&
name|operator
operator|<<
operator|(
name|QDataStream
operator|&
operator|,
specifier|const
name|QEasingCurve
operator|&
operator|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|Q_CORE_EXPORT
name|QDataStream
operator|&
name|operator
operator|>>
operator|(
name|QDataStream
operator|&
operator|,
name|QEasingCurve
operator|&
operator|)
expr_stmt|;
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_expr_stmt
name|QT_END_NAMESPACE
name|QT_END_HEADER
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
end_unit
