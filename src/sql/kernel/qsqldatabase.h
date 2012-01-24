begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtSql module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QSQLDATABASE_H
end_ifndef
begin_define
DECL|macro|QSQLDATABASE_H
define|#
directive|define
name|QSQLDATABASE_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qstring.h>
end_include
begin_include
include|#
directive|include
file|<QtSql/qsql.h>
end_include
begin_decl_stmt
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
DECL|variable|QSqlError
name|class
name|QSqlError
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QSqlDriver
name|class
name|QSqlDriver
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QSqlIndex
name|class
name|QSqlIndex
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QSqlRecord
name|class
name|QSqlRecord
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QSqlQuery
name|class
name|QSqlQuery
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QSqlDatabasePrivate
name|class
name|QSqlDatabasePrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_SQL_EXPORT
name|QSqlDriverCreatorBase
block|{
name|public
label|:
name|virtual
operator|~
name|QSqlDriverCreatorBase
argument_list|()
block|{}
name|virtual
name|QSqlDriver
operator|*
name|createObject
argument_list|()
specifier|const
operator|=
literal|0
expr_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_expr_stmt
name|template
operator|<
name|class
name|T
operator|>
name|class
name|QSqlDriverCreator
operator|:
name|public
name|QSqlDriverCreatorBase
block|{
name|public
operator|:
name|QSqlDriver
operator|*
name|createObject
argument_list|()
specifier|const
block|{
return|return
name|new
name|T
return|;
block|}
end_expr_stmt
begin_decl_stmt
unit|};
name|class
name|Q_SQL_EXPORT
name|QSqlDatabase
block|{
name|public
label|:
name|QSqlDatabase
argument_list|()
expr_stmt|;
name|QSqlDatabase
argument_list|(
specifier|const
name|QSqlDatabase
operator|&
name|other
argument_list|)
expr_stmt|;
operator|~
name|QSqlDatabase
argument_list|()
expr_stmt|;
name|QSqlDatabase
modifier|&
name|operator
init|=
operator|(
specifier|const
name|QSqlDatabase
operator|&
name|other
operator|)
decl_stmt|;
name|bool
name|open
parameter_list|()
function_decl|;
name|bool
name|open
parameter_list|(
specifier|const
name|QString
modifier|&
name|user
parameter_list|,
specifier|const
name|QString
modifier|&
name|password
parameter_list|)
function_decl|;
name|void
name|close
parameter_list|()
function_decl|;
name|bool
name|isOpen
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|isOpenError
argument_list|()
specifier|const
expr_stmt|;
name|QStringList
name|tables
argument_list|(
name|QSql
operator|::
name|TableType
name|type
operator|=
name|QSql
operator|::
name|Tables
argument_list|)
decl|const
decl_stmt|;
name|QSqlIndex
name|primaryIndex
argument_list|(
specifier|const
name|QString
operator|&
name|tablename
argument_list|)
decl|const
decl_stmt|;
name|QSqlRecord
name|record
argument_list|(
specifier|const
name|QString
operator|&
name|tablename
argument_list|)
decl|const
decl_stmt|;
name|QSqlQuery
name|exec
argument_list|(
specifier|const
name|QString
operator|&
name|query
operator|=
name|QString
argument_list|()
argument_list|)
decl|const
decl_stmt|;
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
name|transaction
parameter_list|()
function_decl|;
name|bool
name|commit
parameter_list|()
function_decl|;
name|bool
name|rollback
parameter_list|()
function_decl|;
name|void
name|setDatabaseName
parameter_list|(
specifier|const
name|QString
modifier|&
name|name
parameter_list|)
function_decl|;
name|void
name|setUserName
parameter_list|(
specifier|const
name|QString
modifier|&
name|name
parameter_list|)
function_decl|;
name|void
name|setPassword
parameter_list|(
specifier|const
name|QString
modifier|&
name|password
parameter_list|)
function_decl|;
name|void
name|setHostName
parameter_list|(
specifier|const
name|QString
modifier|&
name|host
parameter_list|)
function_decl|;
name|void
name|setPort
parameter_list|(
name|int
name|p
parameter_list|)
function_decl|;
name|void
name|setConnectOptions
parameter_list|(
specifier|const
name|QString
modifier|&
name|options
init|=
name|QString
argument_list|()
parameter_list|)
function_decl|;
name|QString
name|databaseName
argument_list|()
specifier|const
expr_stmt|;
name|QString
name|userName
argument_list|()
specifier|const
expr_stmt|;
name|QString
name|password
argument_list|()
specifier|const
expr_stmt|;
name|QString
name|hostName
argument_list|()
specifier|const
expr_stmt|;
name|QString
name|driverName
argument_list|()
specifier|const
expr_stmt|;
name|int
name|port
argument_list|()
specifier|const
expr_stmt|;
name|QString
name|connectOptions
argument_list|()
specifier|const
expr_stmt|;
name|QString
name|connectionName
argument_list|()
specifier|const
expr_stmt|;
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
name|QSqlDriver
operator|*
name|driver
argument_list|()
specifier|const
expr_stmt|;
name|QT_STATIC_CONST
name|char
modifier|*
name|defaultConnection
decl_stmt|;
specifier|static
name|QSqlDatabase
name|addDatabase
parameter_list|(
specifier|const
name|QString
modifier|&
name|type
parameter_list|,
specifier|const
name|QString
modifier|&
name|connectionName
init|=
name|QLatin1String
argument_list|(
name|defaultConnection
argument_list|)
parameter_list|)
function_decl|;
specifier|static
name|QSqlDatabase
name|addDatabase
parameter_list|(
name|QSqlDriver
modifier|*
name|driver
parameter_list|,
specifier|const
name|QString
modifier|&
name|connectionName
init|=
name|QLatin1String
argument_list|(
name|defaultConnection
argument_list|)
parameter_list|)
function_decl|;
specifier|static
name|QSqlDatabase
name|cloneDatabase
parameter_list|(
specifier|const
name|QSqlDatabase
modifier|&
name|other
parameter_list|,
specifier|const
name|QString
modifier|&
name|connectionName
parameter_list|)
function_decl|;
specifier|static
name|QSqlDatabase
name|database
parameter_list|(
specifier|const
name|QString
modifier|&
name|connectionName
init|=
name|QLatin1String
argument_list|(
name|defaultConnection
argument_list|)
parameter_list|,
name|bool
name|open
init|=
name|true
parameter_list|)
function_decl|;
specifier|static
name|void
name|removeDatabase
parameter_list|(
specifier|const
name|QString
modifier|&
name|connectionName
parameter_list|)
function_decl|;
specifier|static
name|bool
name|contains
parameter_list|(
specifier|const
name|QString
modifier|&
name|connectionName
init|=
name|QLatin1String
argument_list|(
name|defaultConnection
argument_list|)
parameter_list|)
function_decl|;
specifier|static
name|QStringList
name|drivers
parameter_list|()
function_decl|;
specifier|static
name|QStringList
name|connectionNames
parameter_list|()
function_decl|;
specifier|static
name|void
name|registerSqlDriver
parameter_list|(
specifier|const
name|QString
modifier|&
name|name
parameter_list|,
name|QSqlDriverCreatorBase
modifier|*
name|creator
parameter_list|)
function_decl|;
specifier|static
name|bool
name|isDriverAvailable
parameter_list|(
specifier|const
name|QString
modifier|&
name|name
parameter_list|)
function_decl|;
name|protected
label|:
name|explicit
name|QSqlDatabase
parameter_list|(
specifier|const
name|QString
modifier|&
name|type
parameter_list|)
function_decl|;
name|explicit
name|QSqlDatabase
parameter_list|(
name|QSqlDriver
modifier|*
name|driver
parameter_list|)
function_decl|;
name|private
label|:
name|friend
name|class
name|QSqlDatabasePrivate
decl_stmt|;
name|QSqlDatabasePrivate
modifier|*
name|d
decl_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_DEBUG_STREAM
end_ifndef
begin_expr_stmt
name|Q_SQL_EXPORT
name|QDebug
name|operator
operator|<<
operator|(
name|QDebug
operator|,
specifier|const
name|QSqlDatabase
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
begin_comment
comment|// QSQLDATABASE_H
end_comment
end_unit
