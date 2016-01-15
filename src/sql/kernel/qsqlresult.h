begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the QtSql module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QSQLRESULT_H
end_ifndef
begin_define
DECL|macro|QSQLRESULT_H
define|#
directive|define
name|QSQLRESULT_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qvariant.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qvector.h>
end_include
begin_include
include|#
directive|include
file|<QtSql/qsql.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QString
name|class
name|QString
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QSqlRecord
name|class
name|QSqlRecord
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
DECL|variable|QSqlResultPrivate
name|class
name|QSqlResultPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_SQL_EXPORT
name|QSqlResult
block|{
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QSqlResult
argument_list|)
name|friend
name|class
name|QSqlQuery
decl_stmt|;
name|friend
name|class
name|QSqlTableModelPrivate
decl_stmt|;
name|public
label|:
name|virtual
operator|~
name|QSqlResult
argument_list|()
expr_stmt|;
name|virtual
name|QVariant
name|handle
argument_list|()
specifier|const
expr_stmt|;
name|protected
label|:
enum|enum
name|BindingSyntax
block|{
name|PositionalBinding
block|,
name|NamedBinding
block|}
enum|;
name|explicit
name|QSqlResult
parameter_list|(
specifier|const
name|QSqlDriver
modifier|*
name|db
parameter_list|)
function_decl|;
name|QSqlResult
argument_list|(
name|QSqlResultPrivate
operator|&
name|dd
argument_list|)
expr_stmt|;
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
name|QSqlError
name|lastError
argument_list|()
specifier|const
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
name|isSelect
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|isForwardOnly
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
name|virtual
name|void
name|setAt
parameter_list|(
name|int
name|at
parameter_list|)
function_decl|;
name|virtual
name|void
name|setActive
parameter_list|(
name|bool
name|a
parameter_list|)
function_decl|;
name|virtual
name|void
name|setLastError
parameter_list|(
specifier|const
name|QSqlError
modifier|&
name|e
parameter_list|)
function_decl|;
name|virtual
name|void
name|setQuery
parameter_list|(
specifier|const
name|QString
modifier|&
name|query
parameter_list|)
function_decl|;
name|virtual
name|void
name|setSelect
parameter_list|(
name|bool
name|s
parameter_list|)
function_decl|;
name|virtual
name|void
name|setForwardOnly
parameter_list|(
name|bool
name|forward
parameter_list|)
function_decl|;
comment|// prepared query support
name|virtual
name|bool
name|exec
parameter_list|()
function_decl|;
name|virtual
name|bool
name|prepare
parameter_list|(
specifier|const
name|QString
modifier|&
name|query
parameter_list|)
function_decl|;
name|virtual
name|bool
name|savePrepare
parameter_list|(
specifier|const
name|QString
modifier|&
name|sqlquery
parameter_list|)
function_decl|;
name|virtual
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
argument_list|)
decl_stmt|;
name|virtual
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
name|QSql
operator|::
name|ParamType
name|bindValueType
argument_list|(
argument|const QString& placeholder
argument_list|)
specifier|const
expr_stmt|;
name|QSql
operator|::
name|ParamType
name|bindValueType
argument_list|(
argument|int pos
argument_list|)
specifier|const
expr_stmt|;
name|int
name|boundValueCount
argument_list|()
specifier|const
expr_stmt|;
name|QVector
operator|<
name|QVariant
operator|>
operator|&
name|boundValues
argument_list|()
specifier|const
expr_stmt|;
name|QString
name|executedQuery
argument_list|()
specifier|const
expr_stmt|;
name|QString
name|boundValueName
argument_list|(
name|int
name|pos
argument_list|)
decl|const
decl_stmt|;
name|void
name|clear
parameter_list|()
function_decl|;
name|bool
name|hasOutValues
argument_list|()
specifier|const
expr_stmt|;
name|BindingSyntax
name|bindingSyntax
argument_list|()
specifier|const
expr_stmt|;
name|virtual
name|QVariant
name|data
parameter_list|(
name|int
name|i
parameter_list|)
init|=
literal|0
function_decl|;
name|virtual
name|bool
name|isNull
parameter_list|(
name|int
name|i
parameter_list|)
init|=
literal|0
function_decl|;
name|virtual
name|bool
name|reset
parameter_list|(
specifier|const
name|QString
modifier|&
name|sqlquery
parameter_list|)
init|=
literal|0
function_decl|;
name|virtual
name|bool
name|fetch
parameter_list|(
name|int
name|i
parameter_list|)
init|=
literal|0
function_decl|;
name|virtual
name|bool
name|fetchNext
parameter_list|()
function_decl|;
name|virtual
name|bool
name|fetchPrevious
parameter_list|()
function_decl|;
name|virtual
name|bool
name|fetchFirst
parameter_list|()
init|=
literal|0
function_decl|;
name|virtual
name|bool
name|fetchLast
parameter_list|()
init|=
literal|0
function_decl|;
name|virtual
name|int
name|size
parameter_list|()
init|=
literal|0
function_decl|;
name|virtual
name|int
name|numRowsAffected
parameter_list|()
init|=
literal|0
function_decl|;
name|virtual
name|QSqlRecord
name|record
argument_list|()
specifier|const
expr_stmt|;
name|virtual
name|QVariant
name|lastInsertId
argument_list|()
specifier|const
expr_stmt|;
enum|enum
name|VirtualHookOperation
block|{ }
enum|;
name|virtual
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
name|virtual
name|bool
name|execBatch
parameter_list|(
name|bool
name|arrayBind
init|=
name|false
parameter_list|)
function_decl|;
name|virtual
name|void
name|detachFromResultSet
parameter_list|()
function_decl|;
name|virtual
name|void
name|setNumericalPrecisionPolicy
argument_list|(
name|QSql
operator|::
name|NumericalPrecisionPolicy
name|policy
argument_list|)
decl_stmt|;
name|QSql
operator|::
name|NumericalPrecisionPolicy
name|numericalPrecisionPolicy
argument_list|()
specifier|const
expr_stmt|;
name|virtual
name|bool
name|nextResult
parameter_list|()
function_decl|;
name|void
name|resetBindCount
parameter_list|()
function_decl|;
comment|// HACK
name|QSqlResultPrivate
modifier|*
name|d_ptr
decl_stmt|;
name|private
label|:
name|Q_DISABLE_COPY
argument_list|(
argument|QSqlResult
argument_list|)
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
comment|// QSQLRESULT_H
end_comment
end_unit
