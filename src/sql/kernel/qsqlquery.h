begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the QtSql module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QSQLQUERY_H
end_ifndef
begin_define
DECL|macro|QSQLQUERY_H
define|#
directive|define
name|QSQLQUERY_H
end_define
begin_include
include|#
directive|include
file|<QtSql/qsql.h>
end_include
begin_include
include|#
directive|include
file|<QtSql/qsqldatabase.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qstring.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QVariant
name|class
name|QVariant
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QSqlDriver
name|class
name|QSqlDriver
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QSqlError
name|class
name|QSqlError
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QSqlResult
name|class
name|QSqlResult
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QSqlRecord
name|class
name|QSqlRecord
decl_stmt|;
end_decl_stmt
begin_expr_stmt
DECL|variable|Key
DECL|variable|QMap
name|template
operator|<
name|class
name|Key
operator|,
name|class
name|T
operator|>
name|class
name|QMap
expr_stmt|;
end_expr_stmt
begin_decl_stmt
DECL|variable|QSqlQueryPrivate
name|class
name|QSqlQueryPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_SQL_EXPORT
name|QSqlQuery
block|{
name|public
label|:
name|explicit
name|QSqlQuery
parameter_list|(
name|QSqlResult
modifier|*
name|r
parameter_list|)
function_decl|;
name|explicit
name|QSqlQuery
parameter_list|(
specifier|const
name|QString
modifier|&
name|query
init|=
name|QString
argument_list|()
parameter_list|,
name|QSqlDatabase
name|db
init|=
name|QSqlDatabase
argument_list|()
parameter_list|)
function_decl|;
name|explicit
name|QSqlQuery
parameter_list|(
name|QSqlDatabase
name|db
parameter_list|)
function_decl|;
name|QSqlQuery
argument_list|(
specifier|const
name|QSqlQuery
operator|&
name|other
argument_list|)
expr_stmt|;
name|QSqlQuery
modifier|&
name|operator
init|=
operator|(
specifier|const
name|QSqlQuery
operator|&
name|other
operator|)
decl_stmt|;
operator|~
name|QSqlQuery
argument_list|()
expr_stmt|;
name|bool
name|isValid
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|isActive
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|isNull
argument_list|(
name|int
name|field
argument_list|)
decl|const
decl_stmt|;
name|bool
name|isNull
argument_list|(
specifier|const
name|QString
operator|&
name|name
argument_list|)
decl|const
decl_stmt|;
name|int
name|at
argument_list|()
specifier|const
expr_stmt|;
name|QString
name|lastQuery
argument_list|()
specifier|const
expr_stmt|;
name|int
name|numRowsAffected
argument_list|()
specifier|const
expr_stmt|;
name|QSqlError
name|lastError
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|isSelect
argument_list|()
specifier|const
expr_stmt|;
name|int
name|size
argument_list|()
specifier|const
expr_stmt|;
specifier|const
name|QSqlDriver
operator|*
name|driver
argument_list|()
specifier|const
expr_stmt|;
specifier|const
name|QSqlResult
operator|*
name|result
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|isForwardOnly
argument_list|()
specifier|const
expr_stmt|;
name|QSqlRecord
name|record
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setForwardOnly
parameter_list|(
name|bool
name|forward
parameter_list|)
function_decl|;
name|bool
name|exec
parameter_list|(
specifier|const
name|QString
modifier|&
name|query
parameter_list|)
function_decl|;
name|QVariant
name|value
argument_list|(
name|int
name|i
argument_list|)
decl|const
decl_stmt|;
name|QVariant
name|value
argument_list|(
specifier|const
name|QString
operator|&
name|name
argument_list|)
decl|const
decl_stmt|;
name|void
name|setNumericalPrecisionPolicy
argument_list|(
name|QSql
operator|::
name|NumericalPrecisionPolicy
name|precisionPolicy
argument_list|)
decl_stmt|;
name|QSql
operator|::
name|NumericalPrecisionPolicy
name|numericalPrecisionPolicy
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|seek
parameter_list|(
name|int
name|i
parameter_list|,
name|bool
name|relative
init|=
name|false
parameter_list|)
function_decl|;
name|bool
name|next
parameter_list|()
function_decl|;
name|bool
name|previous
parameter_list|()
function_decl|;
name|bool
name|first
parameter_list|()
function_decl|;
name|bool
name|last
parameter_list|()
function_decl|;
name|void
name|clear
parameter_list|()
function_decl|;
comment|// prepared query support
name|bool
name|exec
parameter_list|()
function_decl|;
enum|enum
name|BatchExecutionMode
block|{
name|ValuesAsRows
block|,
name|ValuesAsColumns
block|}
enum|;
name|bool
name|execBatch
parameter_list|(
name|BatchExecutionMode
name|mode
init|=
name|ValuesAsRows
parameter_list|)
function_decl|;
name|bool
name|prepare
parameter_list|(
specifier|const
name|QString
modifier|&
name|query
parameter_list|)
function_decl|;
name|void
name|bindValue
argument_list|(
specifier|const
name|QString
operator|&
name|placeholder
argument_list|,
specifier|const
name|QVariant
operator|&
name|val
argument_list|,
name|QSql
operator|::
name|ParamType
name|type
operator|=
name|QSql
operator|::
name|In
argument_list|)
decl_stmt|;
name|void
name|bindValue
argument_list|(
name|int
name|pos
argument_list|,
specifier|const
name|QVariant
operator|&
name|val
argument_list|,
name|QSql
operator|::
name|ParamType
name|type
operator|=
name|QSql
operator|::
name|In
argument_list|)
decl_stmt|;
name|void
name|addBindValue
argument_list|(
specifier|const
name|QVariant
operator|&
name|val
argument_list|,
name|QSql
operator|::
name|ParamType
name|type
operator|=
name|QSql
operator|::
name|In
argument_list|)
decl_stmt|;
name|QVariant
name|boundValue
argument_list|(
specifier|const
name|QString
operator|&
name|placeholder
argument_list|)
decl|const
decl_stmt|;
name|QVariant
name|boundValue
argument_list|(
name|int
name|pos
argument_list|)
decl|const
decl_stmt|;
name|QMap
operator|<
name|QString
operator|,
name|QVariant
operator|>
name|boundValues
argument_list|()
specifier|const
expr_stmt|;
name|QString
name|executedQuery
argument_list|()
specifier|const
expr_stmt|;
name|QVariant
name|lastInsertId
argument_list|()
specifier|const
expr_stmt|;
name|void
name|finish
parameter_list|()
function_decl|;
name|bool
name|nextResult
parameter_list|()
function_decl|;
name|private
label|:
name|QSqlQueryPrivate
modifier|*
name|d
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
begin_comment
comment|// QSQLQUERY_H
end_comment
end_unit
