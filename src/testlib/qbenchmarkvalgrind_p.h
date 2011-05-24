begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtTest module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QBENCHMARKVALGRIND_P_H
end_ifndef
begin_define
DECL|macro|QBENCHMARKVALGRIND_P_H
define|#
directive|define
name|QBENCHMARKVALGRIND_P_H
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
comment|// This file is not part of the Qt API.  It exists purely as an
end_comment
begin_comment
comment|// implementation detail.  This header file may change from version to
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
file|"QtTest/private/qbenchmarkmeasurement_p.h"
end_include
begin_include
include|#
directive|include
file|"QtTest/private/qbenchmarkmetric_p.h"
end_include
begin_include
include|#
directive|include
file|<QtCore/qmap.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qstring.h>
end_include
begin_decl_stmt
DECL|variable|QStringList
name|class
name|QStringList
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
name|class
name|QBenchmarkValgrindUtils
block|{
name|public
label|:
specifier|static
name|bool
name|haveValgrind
parameter_list|()
function_decl|;
specifier|static
name|bool
name|rerunThroughCallgrind
parameter_list|(
specifier|const
name|QStringList
modifier|&
name|origAppArgs
parameter_list|,
name|int
modifier|&
name|exitCode
parameter_list|)
function_decl|;
specifier|static
name|bool
name|runCallgrindSubProcess
parameter_list|(
specifier|const
name|QStringList
modifier|&
name|origAppArgs
parameter_list|,
name|int
modifier|&
name|exitCode
parameter_list|)
function_decl|;
specifier|static
name|qint64
name|extractResult
parameter_list|(
specifier|const
name|QString
modifier|&
name|fileName
parameter_list|)
function_decl|;
specifier|static
name|QString
name|getNewestFileName
parameter_list|()
function_decl|;
specifier|static
name|qint64
name|extractLastResult
parameter_list|()
function_decl|;
specifier|static
name|void
name|cleanup
parameter_list|()
function_decl|;
specifier|static
name|QString
name|outFileBase
parameter_list|(
name|qint64
name|pid
init|=
operator|-
literal|1
parameter_list|)
function_decl|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_decl_stmt
name|class
name|QBenchmarkCallgrindMeasurer
range|:
name|public
name|QBenchmarkMeasurerBase
block|{
name|public
operator|:
name|void
name|start
argument_list|()
block|;
name|qint64
name|checkpoint
argument_list|()
block|;
name|qint64
name|stop
argument_list|()
block|;
name|bool
name|isMeasurementAccepted
argument_list|(
argument|qint64 measurement
argument_list|)
block|;
name|int
name|adjustIterationCount
argument_list|(
name|int
argument_list|)
block|;
name|int
name|adjustMedianCount
argument_list|(
name|int
argument_list|)
block|;
name|bool
name|needsWarmupIteration
argument_list|()
block|;
name|QTest
operator|::
name|QBenchmarkMetric
name|metricType
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
comment|// QBENCHMARKVALGRIND_H
end_comment
end_unit
