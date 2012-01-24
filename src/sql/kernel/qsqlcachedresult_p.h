begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtSql module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QSQLCACHEDRESULT_P_H
end_ifndef
begin_define
DECL|macro|QSQLCACHEDRESULT_P_H
define|#
directive|define
name|QSQLCACHEDRESULT_P_H
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
comment|// This file is not part of the Qt API.  It exists for the convenience
end_comment
begin_comment
comment|// of other Qt classes.  This header file may change from version to
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
file|"QtSql/qsqlresult.h"
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QVariant
name|class
name|QVariant
decl_stmt|;
end_decl_stmt
begin_expr_stmt
DECL|variable|QVector
name|template
operator|<
name|typename
name|T
operator|>
name|class
name|QVector
expr_stmt|;
end_expr_stmt
begin_decl_stmt
DECL|variable|QSqlCachedResultPrivate
name|class
name|QSqlCachedResultPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_SQL_EXPORT
name|QSqlCachedResult
range|:
name|public
name|QSqlResult
block|{
name|public
operator|:
name|virtual
operator|~
name|QSqlCachedResult
argument_list|()
block|;
typedef|typedef
name|QVector
operator|<
name|QVariant
operator|>
name|ValueCache
expr_stmt|;
name|protected
operator|:
name|QSqlCachedResult
argument_list|(
specifier|const
name|QSqlDriver
operator|*
name|db
argument_list|)
decl_stmt|;
end_decl_stmt
begin_function_decl
name|void
name|init
parameter_list|(
name|int
name|colCount
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|cleanup
parameter_list|()
function_decl|;
end_function_decl
begin_function_decl
name|void
name|clearValues
parameter_list|()
function_decl|;
end_function_decl
begin_function_decl
name|virtual
name|bool
name|gotoNext
parameter_list|(
name|ValueCache
modifier|&
name|values
parameter_list|,
name|int
name|index
parameter_list|)
init|=
literal|0
function_decl|;
end_function_decl
begin_function_decl
name|QVariant
name|data
parameter_list|(
name|int
name|i
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|bool
name|isNull
parameter_list|(
name|int
name|i
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|bool
name|fetch
parameter_list|(
name|int
name|i
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|bool
name|fetchNext
parameter_list|()
function_decl|;
end_function_decl
begin_function_decl
name|bool
name|fetchPrevious
parameter_list|()
function_decl|;
end_function_decl
begin_function_decl
name|bool
name|fetchFirst
parameter_list|()
function_decl|;
end_function_decl
begin_function_decl
name|bool
name|fetchLast
parameter_list|()
function_decl|;
end_function_decl
begin_expr_stmt
name|int
name|colCount
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_function_decl
name|ValueCache
modifier|&
name|cache
parameter_list|()
function_decl|;
end_function_decl
begin_function_decl
name|void
name|virtual_hook
parameter_list|(
name|int
name|id
parameter_list|,
name|void
modifier|*
name|data
parameter_list|)
function_decl|;
end_function_decl
begin_label
name|private
label|:
end_label
begin_function_decl
name|bool
name|cacheNext
parameter_list|()
function_decl|;
end_function_decl
begin_decl_stmt
name|QSqlCachedResultPrivate
modifier|*
name|d
decl_stmt|;
end_decl_stmt
begin_macro
unit|};
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QSQLCACHEDRESULT_P_H
end_comment
end_unit
