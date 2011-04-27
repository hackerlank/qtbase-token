begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtTest module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** No Commercial Usage ** This file contains pre-release code and may not be distributed. ** You may use this file in accordance with the terms and conditions ** contained in the Technology Preview License Agreement accompanying ** this package. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights.  These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** If you have questions regarding the use of this file, please contact ** Nokia at qt-info@nokia.com. ** ** ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtTest/private/qbenchmarkmetric_p.h>
end_include
begin_comment
comment|/*!   \enum QTest::QBenchmarkMetric   \since 4.7    This enum lists all the things that can be benchmarked.      \value FramesPerSecond        Frames per second   \value BitsPerSecond          Bits per second   \value BytesPerSecond         Bytes per second   \value WalltimeMilliseconds   Clock time in milliseconds   \value CPUTicks               CPU time   \value InstructionReads       Instruction reads   \value Events                 Event count    \sa QTest::benchmarkMetricName(), QTest::benchmarkMetricUnit()   */
end_comment
begin_comment
comment|/*!   \relates QTest   \since 4.7   Returns the enum value \a metric as a character string.  */
end_comment
begin_function
DECL|function|benchmarkMetricName
specifier|const
name|char
modifier|*
name|QTest
operator|::
name|benchmarkMetricName
parameter_list|(
name|QBenchmarkMetric
name|metric
parameter_list|)
block|{
switch|switch
condition|(
name|metric
condition|)
block|{
case|case
name|FramesPerSecond
case|:
return|return
literal|"FramesPerSecond"
return|;
case|case
name|BitsPerSecond
case|:
return|return
literal|"BitsPerSecond"
return|;
case|case
name|BytesPerSecond
case|:
return|return
literal|"BytesPerSecond"
return|;
case|case
name|WalltimeMilliseconds
case|:
return|return
literal|"WalltimeMilliseconds"
return|;
case|case
name|CPUTicks
case|:
return|return
literal|"CPUTicks"
return|;
case|case
name|InstructionReads
case|:
return|return
literal|"InstructionReads"
return|;
case|case
name|Events
case|:
return|return
literal|"Events"
return|;
default|default:
return|return
literal|""
return|;
block|}
block|}
end_function
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_comment
comment|/*!   \relates QTest   \since 4.7   Retuns the units of measure for the specified \a metric.  */
end_comment
begin_function
DECL|function|benchmarkMetricUnit
specifier|const
name|char
modifier|*
name|QTest
operator|::
name|benchmarkMetricUnit
parameter_list|(
name|QBenchmarkMetric
name|metric
parameter_list|)
block|{
switch|switch
condition|(
name|metric
condition|)
block|{
case|case
name|FramesPerSecond
case|:
return|return
literal|"fps"
return|;
case|case
name|BitsPerSecond
case|:
return|return
literal|"bits/s"
return|;
case|case
name|BytesPerSecond
case|:
return|return
literal|"bytes/s"
return|;
case|case
name|WalltimeMilliseconds
case|:
return|return
literal|"msecs"
return|;
case|case
name|CPUTicks
case|:
return|return
literal|"CPU ticks"
return|;
case|case
name|InstructionReads
case|:
return|return
literal|"instruction reads"
return|;
case|case
name|Events
case|:
return|return
literal|"events"
return|;
default|default:
return|return
literal|""
return|;
block|}
block|}
end_function
end_unit
