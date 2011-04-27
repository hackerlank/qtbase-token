begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtTest module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** No Commercial Usage ** This file contains pre-release code and may not be distributed. ** You may use this file in accordance with the terms and conditions ** contained in the Technology Preview License Agreement accompanying ** this package. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights.  These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** If you have questions regarding the use of this file, please contact ** Nokia at qt-info@nokia.com. ** ** ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"QtTest/private/qbenchmarkevent_p.h"
end_include
begin_include
include|#
directive|include
file|"QtTest/private/qbenchmark_p.h"
end_include
begin_include
include|#
directive|include
file|"QtTest/private/qbenchmarkmetric_p.h"
end_include
begin_include
include|#
directive|include
file|<qdebug.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|oldEventFilter
name|QAbstractEventDispatcher
operator|::
name|EventFilter
name|oldEventFilter
init|=
literal|0
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|member|eventCounter
name|qint64
name|QBenchmarkEvent
operator|::
name|eventCounter
init|=
literal|0
decl_stmt|;
end_decl_stmt
begin_destructor
DECL|function|~QBenchmarkEvent
name|QBenchmarkEvent
operator|::
name|~
name|QBenchmarkEvent
parameter_list|()
block|{ }
end_destructor
begin_function
DECL|function|start
name|void
name|QBenchmarkEvent
operator|::
name|start
parameter_list|()
block|{
name|QBenchmarkEvent
operator|::
name|eventCounter
operator|=
literal|0
expr_stmt|;
name|QAbstractEventDispatcher
modifier|*
name|parent
init|=
name|QAbstractEventDispatcher
operator|::
name|instance
argument_list|()
decl_stmt|;
name|oldEventFilter
operator|=
name|parent
operator|->
name|setEventFilter
argument_list|(
name|QBenchmarkEvent
operator|::
name|eventCountingMechanism
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|checkpoint
name|qint64
name|QBenchmarkEvent
operator|::
name|checkpoint
parameter_list|()
block|{
return|return
name|QBenchmarkEvent
operator|::
name|eventCounter
return|;
block|}
end_function
begin_function
DECL|function|stop
name|qint64
name|QBenchmarkEvent
operator|::
name|stop
parameter_list|()
block|{
name|QAbstractEventDispatcher
modifier|*
name|parent
init|=
name|QAbstractEventDispatcher
operator|::
name|instance
argument_list|()
decl_stmt|;
name|parent
operator|->
name|setEventFilter
argument_list|(
name|oldEventFilter
argument_list|)
expr_stmt|;
return|return
name|QBenchmarkEvent
operator|::
name|eventCounter
return|;
block|}
end_function
begin_comment
comment|// It's very tempting to simply reject a measurement if 0 events
end_comment
begin_comment
comment|// where counted, however that is a possible situation and returning
end_comment
begin_comment
comment|// false here will create a infinite loop. Do not change this.
end_comment
begin_function
DECL|function|isMeasurementAccepted
name|bool
name|QBenchmarkEvent
operator|::
name|isMeasurementAccepted
parameter_list|(
name|qint64
name|measurement
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
name|measurement
argument_list|)
expr_stmt|;
return|return
literal|true
return|;
block|}
end_function
begin_function
DECL|function|adjustIterationCount
name|int
name|QBenchmarkEvent
operator|::
name|adjustIterationCount
parameter_list|(
name|int
name|suggestion
parameter_list|)
block|{
return|return
name|suggestion
return|;
block|}
end_function
begin_function
DECL|function|adjustMedianCount
name|int
name|QBenchmarkEvent
operator|::
name|adjustMedianCount
parameter_list|(
name|int
name|suggestion
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
name|suggestion
argument_list|)
expr_stmt|;
return|return
literal|1
return|;
block|}
end_function
begin_function
DECL|function|metricType
name|QTest
operator|::
name|QBenchmarkMetric
name|QBenchmarkEvent
operator|::
name|metricType
parameter_list|()
block|{
return|return
name|QTest
operator|::
name|Events
return|;
block|}
end_function
begin_comment
comment|// This could be done in a much better way, this is just the beginning.
end_comment
begin_function
DECL|function|eventCountingMechanism
name|bool
name|QBenchmarkEvent
operator|::
name|eventCountingMechanism
parameter_list|(
name|void
modifier|*
name|message
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
name|message
argument_list|)
expr_stmt|;
name|QBenchmarkEvent
operator|::
name|eventCounter
operator|++
expr_stmt|;
return|return
literal|false
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
