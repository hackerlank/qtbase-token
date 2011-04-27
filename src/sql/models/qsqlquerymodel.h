begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtSql module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** No Commercial Usage ** This file contains pre-release code and may not be distributed. ** You may use this file in accordance with the terms and conditions ** contained in the Technology Preview License Agreement accompanying ** this package. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights.  These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** If you have questions regarding the use of this file, please contact ** Nokia at qt-info@nokia.com. ** ** ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QSQLQUERYMODEL_H
end_ifndef
begin_define
DECL|macro|QSQLQUERYMODEL_H
define|#
directive|define
name|QSQLQUERYMODEL_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qabstractitemmodel.h>
end_include
begin_include
include|#
directive|include
file|<QtSql/qsqldatabase.h>
end_include
begin_decl_stmt
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
name|QT_MODULE
argument_list|(
name|Sql
argument_list|)
name|class
name|QSqlQueryModelPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QSqlError
name|class
name|QSqlError
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
name|class
name|Q_SQL_EXPORT
name|QSqlQueryModel
range|:
name|public
name|QAbstractTableModel
block|{
name|Q_OBJECT
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QSqlQueryModel
argument_list|)
name|public
operator|:
name|explicit
name|QSqlQueryModel
argument_list|(
name|QObject
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
name|virtual
operator|~
name|QSqlQueryModel
argument_list|()
block|;
name|int
name|rowCount
argument_list|(
argument|const QModelIndex&parent = QModelIndex()
argument_list|)
specifier|const
block|;
name|int
name|columnCount
argument_list|(
argument|const QModelIndex&parent = QModelIndex()
argument_list|)
specifier|const
block|;
name|QSqlRecord
name|record
argument_list|(
argument|int row
argument_list|)
specifier|const
block|;
name|QSqlRecord
name|record
argument_list|()
specifier|const
block|;
name|QVariant
name|data
argument_list|(
argument|const QModelIndex&item
argument_list|,
argument|int role = Qt::DisplayRole
argument_list|)
specifier|const
block|;
name|QVariant
name|headerData
argument_list|(
argument|int section
argument_list|,
argument|Qt::Orientation orientation
argument_list|,
argument|int role = Qt::DisplayRole
argument_list|)
specifier|const
block|;
name|bool
name|setHeaderData
argument_list|(
argument|int section
argument_list|,
argument|Qt::Orientation orientation
argument_list|,
argument|const QVariant&value
argument_list|,
argument|int role = Qt::EditRole
argument_list|)
block|;
name|bool
name|insertColumns
argument_list|(
argument|int column
argument_list|,
argument|int count
argument_list|,
argument|const QModelIndex&parent = QModelIndex()
argument_list|)
block|;
name|bool
name|removeColumns
argument_list|(
argument|int column
argument_list|,
argument|int count
argument_list|,
argument|const QModelIndex&parent = QModelIndex()
argument_list|)
block|;
name|void
name|setQuery
argument_list|(
specifier|const
name|QSqlQuery
operator|&
name|query
argument_list|)
block|;
name|void
name|setQuery
argument_list|(
specifier|const
name|QString
operator|&
name|query
argument_list|,
specifier|const
name|QSqlDatabase
operator|&
name|db
operator|=
name|QSqlDatabase
argument_list|()
argument_list|)
block|;
name|QSqlQuery
name|query
argument_list|()
specifier|const
block|;
name|virtual
name|void
name|clear
argument_list|()
block|;
name|QSqlError
name|lastError
argument_list|()
specifier|const
block|;
name|void
name|fetchMore
argument_list|(
specifier|const
name|QModelIndex
operator|&
name|parent
operator|=
name|QModelIndex
argument_list|()
argument_list|)
block|;
name|bool
name|canFetchMore
argument_list|(
argument|const QModelIndex&parent = QModelIndex()
argument_list|)
specifier|const
block|;
name|protected
operator|:
name|virtual
name|void
name|queryChange
argument_list|()
block|;
name|QModelIndex
name|indexInQuery
argument_list|(
argument|const QModelIndex&item
argument_list|)
specifier|const
block|;
name|void
name|setLastError
argument_list|(
specifier|const
name|QSqlError
operator|&
name|error
argument_list|)
block|;
name|QSqlQueryModel
argument_list|(
name|QSqlQueryModelPrivate
operator|&
name|dd
argument_list|,
name|QObject
operator|*
name|parent
operator|=
literal|0
argument_list|)
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
comment|// QSQLQUERYMODEL_H
end_comment
end_unit
