begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtSql module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QSQL_OCI_H
end_ifndef
begin_define
DECL|macro|QSQL_OCI_H
define|#
directive|define
name|QSQL_OCI_H
end_define
begin_include
include|#
directive|include
file|<QtSql/qsqlresult.h>
end_include
begin_include
include|#
directive|include
file|<QtSql/qsqldriver.h>
end_include
begin_include
include|#
directive|include
file|<QtSql/private/qsqlcachedresult_p.h>
end_include
begin_ifdef
ifdef|#
directive|ifdef
name|QT_PLUGIN
end_ifdef
begin_define
DECL|macro|Q_EXPORT_SQLDRIVER_OCI
define|#
directive|define
name|Q_EXPORT_SQLDRIVER_OCI
end_define
begin_else
else|#
directive|else
end_else
begin_define
DECL|macro|Q_EXPORT_SQLDRIVER_OCI
define|#
directive|define
name|Q_EXPORT_SQLDRIVER_OCI
value|Q_SQL_EXPORT
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_macro
name|QT_BEGIN_HEADER
end_macro
begin_typedef
DECL|typedef|OCIEnv
typedef|typedef
name|struct
name|OCIEnv
name|OCIEnv
typedef|;
end_typedef
begin_typedef
DECL|typedef|OCISvcCtx
typedef|typedef
name|struct
name|OCISvcCtx
name|OCISvcCtx
typedef|;
end_typedef
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QOCIDriver
name|class
name|QOCIDriver
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QOCICols
name|class
name|QOCICols
decl_stmt|;
end_decl_stmt
begin_struct_decl
struct_decl|struct
name|QOCIDriverPrivate
struct_decl|;
end_struct_decl
begin_struct_decl
struct_decl|struct
name|QOCIResultPrivate
struct_decl|;
end_struct_decl
begin_decl_stmt
name|class
name|Q_EXPORT_SQLDRIVER_OCI
name|QOCIResult
range|:
name|public
name|QSqlCachedResult
block|{
name|friend
name|class
name|QOCIDriver
block|;
name|friend
expr|struct
name|QOCIResultPrivate
block|;
name|friend
name|class
name|QOCICols
block|;
name|public
operator|:
name|QOCIResult
argument_list|(
specifier|const
name|QOCIDriver
operator|*
name|db
argument_list|,
specifier|const
name|QOCIDriverPrivate
operator|*
name|p
argument_list|)
block|;
operator|~
name|QOCIResult
argument_list|()
block|;
name|bool
name|prepare
argument_list|(
specifier|const
name|QString
operator|&
name|query
argument_list|)
block|;
name|bool
name|exec
argument_list|()
block|;
name|QVariant
name|handle
argument_list|()
specifier|const
block|;
name|protected
operator|:
name|bool
name|gotoNext
argument_list|(
argument|ValueCache&values
argument_list|,
argument|int index
argument_list|)
block|;
name|bool
name|reset
argument_list|(
specifier|const
name|QString
operator|&
name|query
argument_list|)
block|;
name|int
name|size
argument_list|()
block|;
name|int
name|numRowsAffected
argument_list|()
block|;
name|QSqlRecord
name|record
argument_list|()
specifier|const
block|;
name|QVariant
name|lastInsertId
argument_list|()
specifier|const
block|;
name|bool
name|execBatch
argument_list|(
argument|bool arrayBind = false
argument_list|)
block|;
name|void
name|virtual_hook
argument_list|(
argument|int id
argument_list|,
argument|void *data
argument_list|)
block|;
name|private
operator|:
name|QOCIResultPrivate
operator|*
name|d
block|; }
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_EXPORT_SQLDRIVER_OCI
name|QOCIDriver
range|:
name|public
name|QSqlDriver
block|{
name|Q_OBJECT
name|friend
expr|struct
name|QOCIResultPrivate
block|;
name|friend
name|class
name|QOCIPrivate
block|;
name|public
operator|:
name|explicit
name|QOCIDriver
argument_list|(
name|QObject
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
name|QOCIDriver
argument_list|(
name|OCIEnv
operator|*
name|env
argument_list|,
name|OCISvcCtx
operator|*
name|ctx
argument_list|,
name|QObject
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
operator|~
name|QOCIDriver
argument_list|()
block|;
name|bool
name|hasFeature
argument_list|(
argument|DriverFeature f
argument_list|)
specifier|const
block|;
name|bool
name|open
argument_list|(
argument|const QString& db
argument_list|,
argument|const QString& user
argument_list|,
argument|const QString& password
argument_list|,
argument|const QString& host
argument_list|,
argument|int port
argument_list|,
argument|const QString& connOpts
argument_list|)
block|;
name|void
name|close
argument_list|()
block|;
name|QSqlResult
operator|*
name|createResult
argument_list|()
specifier|const
block|;
name|QStringList
name|tables
argument_list|(
argument|QSql::TableType
argument_list|)
specifier|const
block|;
name|QSqlRecord
name|record
argument_list|(
argument|const QString& tablename
argument_list|)
specifier|const
block|;
name|QSqlIndex
name|primaryIndex
argument_list|(
argument|const QString& tablename
argument_list|)
specifier|const
block|;
name|QString
name|formatValue
argument_list|(
argument|const QSqlField&field
argument_list|,
argument|bool trimStrings
argument_list|)
specifier|const
block|;
name|QVariant
name|handle
argument_list|()
specifier|const
block|;
name|QString
name|escapeIdentifier
argument_list|(
argument|const QString&identifier
argument_list|,
argument|IdentifierType
argument_list|)
specifier|const
block|;
name|protected
operator|:
name|bool
name|beginTransaction
argument_list|()
block|;
name|bool
name|commitTransaction
argument_list|()
block|;
name|bool
name|rollbackTransaction
argument_list|()
block|;
name|private
operator|:
name|QOCIDriverPrivate
operator|*
name|d
block|; }
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
begin_comment
comment|// QSQL_OCI_H
end_comment
end_unit
