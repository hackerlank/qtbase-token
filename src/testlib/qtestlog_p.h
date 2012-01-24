begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtTest module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QTESTLOG_P_H
end_ifndef
begin_define
DECL|macro|QTESTLOG_P_H
define|#
directive|define
name|QTESTLOG_P_H
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
file|<QtTest/qtest_global.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QBenchmarkResult
name|class
name|QBenchmarkResult
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_TESTLIB_EXPORT
name|QTestLog
block|{
name|public
label|:
enum|enum
name|LogMode
block|{
name|Plain
init|=
literal|0
block|,
name|XML
block|,
name|LightXML
block|,
name|XunitXML
block|}
enum|;
specifier|static
name|void
name|enterTestFunction
parameter_list|(
specifier|const
name|char
modifier|*
name|function
parameter_list|)
function_decl|;
specifier|static
name|void
name|leaveTestFunction
parameter_list|()
function_decl|;
specifier|static
name|void
name|addPass
parameter_list|(
specifier|const
name|char
modifier|*
name|msg
parameter_list|)
function_decl|;
specifier|static
name|void
name|addFail
parameter_list|(
specifier|const
name|char
modifier|*
name|msg
parameter_list|,
specifier|const
name|char
modifier|*
name|file
parameter_list|,
name|int
name|line
parameter_list|)
function_decl|;
specifier|static
name|void
name|addXFail
parameter_list|(
specifier|const
name|char
modifier|*
name|msg
parameter_list|,
specifier|const
name|char
modifier|*
name|file
parameter_list|,
name|int
name|line
parameter_list|)
function_decl|;
specifier|static
name|void
name|addXPass
parameter_list|(
specifier|const
name|char
modifier|*
name|msg
parameter_list|,
specifier|const
name|char
modifier|*
name|file
parameter_list|,
name|int
name|line
parameter_list|)
function_decl|;
specifier|static
name|void
name|addSkip
parameter_list|(
specifier|const
name|char
modifier|*
name|msg
parameter_list|,
specifier|const
name|char
modifier|*
name|file
parameter_list|,
name|int
name|line
parameter_list|)
function_decl|;
specifier|static
name|void
name|addBenchmarkResult
parameter_list|(
specifier|const
name|QBenchmarkResult
modifier|&
name|result
parameter_list|)
function_decl|;
specifier|static
name|void
name|ignoreMessage
parameter_list|(
name|QtMsgType
name|type
parameter_list|,
specifier|const
name|char
modifier|*
name|msg
parameter_list|)
function_decl|;
specifier|static
name|int
name|unhandledIgnoreMessages
parameter_list|()
function_decl|;
specifier|static
name|void
name|printUnhandledIgnoreMessages
parameter_list|()
function_decl|;
specifier|static
name|void
name|warn
parameter_list|(
specifier|const
name|char
modifier|*
name|msg
parameter_list|,
specifier|const
name|char
modifier|*
name|file
parameter_list|,
name|int
name|line
parameter_list|)
function_decl|;
specifier|static
name|void
name|info
parameter_list|(
specifier|const
name|char
modifier|*
name|msg
parameter_list|,
specifier|const
name|char
modifier|*
name|file
parameter_list|,
name|int
name|line
parameter_list|)
function_decl|;
specifier|static
name|void
name|startLogging
parameter_list|()
function_decl|;
specifier|static
name|void
name|stopLogging
parameter_list|()
function_decl|;
specifier|static
name|void
name|addLogger
parameter_list|(
name|LogMode
name|mode
parameter_list|,
specifier|const
name|char
modifier|*
name|filename
parameter_list|)
function_decl|;
specifier|static
name|int
name|loggerCount
parameter_list|()
function_decl|;
specifier|static
name|bool
name|loggerUsingStdout
parameter_list|()
function_decl|;
specifier|static
name|void
name|setVerboseLevel
parameter_list|(
name|int
name|level
parameter_list|)
function_decl|;
specifier|static
name|int
name|verboseLevel
parameter_list|()
function_decl|;
specifier|static
name|void
name|setMaxWarnings
parameter_list|(
name|int
name|max
parameter_list|)
function_decl|;
specifier|static
name|void
name|setPrintAvailableTagsMode
parameter_list|()
function_decl|;
specifier|static
name|int
name|passCount
parameter_list|()
function_decl|;
specifier|static
name|int
name|failCount
parameter_list|()
function_decl|;
specifier|static
name|int
name|skipCount
parameter_list|()
function_decl|;
specifier|static
name|void
name|resetCounters
parameter_list|()
function_decl|;
name|private
label|:
name|QTestLog
argument_list|()
expr_stmt|;
operator|~
name|QTestLog
argument_list|()
expr_stmt|;
specifier|static
name|bool
name|printAvailableTags
decl_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
end_unit
