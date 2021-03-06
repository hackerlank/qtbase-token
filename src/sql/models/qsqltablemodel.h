begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the QtSql module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QSQLTABLEMODEL_H
end_ifndef
begin_define
DECL|macro|QSQLTABLEMODEL_H
define|#
directive|define
name|QSQLTABLEMODEL_H
end_define
begin_include
include|#
directive|include
file|<QtSql/qsqldatabase.h>
end_include
begin_include
include|#
directive|include
file|<QtSql/qsqlquerymodel.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QSqlTableModelPrivate
name|class
name|QSqlTableModelPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QSqlRecord
name|class
name|QSqlRecord
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QSqlField
name|class
name|QSqlField
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QSqlIndex
name|class
name|QSqlIndex
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_SQL_EXPORT
name|QSqlTableModel
range|:
name|public
name|QSqlQueryModel
block|{
name|Q_OBJECT
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QSqlTableModel
argument_list|)
name|public
operator|:
expr|enum
name|EditStrategy
block|{
name|OnFieldChange
block|,
name|OnRowChange
block|,
name|OnManualSubmit
block|}
block|;
name|explicit
name|QSqlTableModel
argument_list|(
argument|QObject *parent = Q_NULLPTR
argument_list|,
argument|QSqlDatabase db = QSqlDatabase()
argument_list|)
block|;
name|virtual
operator|~
name|QSqlTableModel
argument_list|()
block|;
name|virtual
name|void
name|setTable
argument_list|(
specifier|const
name|QString
operator|&
name|tableName
argument_list|)
block|;
name|QString
name|tableName
argument_list|()
specifier|const
block|;
name|Qt
operator|::
name|ItemFlags
name|flags
argument_list|(
argument|const QModelIndex&index
argument_list|)
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|QSqlRecord
name|record
argument_list|()
specifier|const
block|;
name|QSqlRecord
name|record
argument_list|(
argument|int row
argument_list|)
specifier|const
block|;
name|QVariant
name|data
argument_list|(
argument|const QModelIndex&idx
argument_list|,
argument|int role = Qt::DisplayRole
argument_list|)
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|bool
name|setData
argument_list|(
argument|const QModelIndex&index
argument_list|,
argument|const QVariant&value
argument_list|,
argument|int role = Qt::EditRole
argument_list|)
name|Q_DECL_OVERRIDE
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
name|Q_DECL_OVERRIDE
block|;
name|bool
name|isDirty
argument_list|()
specifier|const
block|;
name|bool
name|isDirty
argument_list|(
argument|const QModelIndex&index
argument_list|)
specifier|const
block|;
name|void
name|clear
argument_list|()
name|Q_DECL_OVERRIDE
block|;
name|virtual
name|void
name|setEditStrategy
argument_list|(
argument|EditStrategy strategy
argument_list|)
block|;
name|EditStrategy
name|editStrategy
argument_list|()
specifier|const
block|;
name|QSqlIndex
name|primaryKey
argument_list|()
specifier|const
block|;
name|QSqlDatabase
name|database
argument_list|()
specifier|const
block|;
name|int
name|fieldIndex
argument_list|(
argument|const QString&fieldName
argument_list|)
specifier|const
block|;
name|void
name|sort
argument_list|(
argument|int column
argument_list|,
argument|Qt::SortOrder order
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|virtual
name|void
name|setSort
argument_list|(
argument|int column
argument_list|,
argument|Qt::SortOrder order
argument_list|)
block|;
name|QString
name|filter
argument_list|()
specifier|const
block|;
name|virtual
name|void
name|setFilter
argument_list|(
specifier|const
name|QString
operator|&
name|filter
argument_list|)
block|;
name|int
name|rowCount
argument_list|(
argument|const QModelIndex&parent = QModelIndex()
argument_list|)
specifier|const
name|Q_DECL_OVERRIDE
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
name|Q_DECL_OVERRIDE
block|;
name|bool
name|removeRows
argument_list|(
argument|int row
argument_list|,
argument|int count
argument_list|,
argument|const QModelIndex&parent = QModelIndex()
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|bool
name|insertRows
argument_list|(
argument|int row
argument_list|,
argument|int count
argument_list|,
argument|const QModelIndex&parent = QModelIndex()
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|bool
name|insertRecord
argument_list|(
argument|int row
argument_list|,
argument|const QSqlRecord&record
argument_list|)
block|;
name|bool
name|setRecord
argument_list|(
argument|int row
argument_list|,
argument|const QSqlRecord&record
argument_list|)
block|;
name|virtual
name|void
name|revertRow
argument_list|(
argument|int row
argument_list|)
block|;
name|public
name|Q_SLOTS
operator|:
name|virtual
name|bool
name|select
argument_list|()
block|;
name|virtual
name|bool
name|selectRow
argument_list|(
argument|int row
argument_list|)
block|;
name|bool
name|submit
argument_list|()
name|Q_DECL_OVERRIDE
block|;
name|void
name|revert
argument_list|()
name|Q_DECL_OVERRIDE
block|;
name|bool
name|submitAll
argument_list|()
block|;
name|void
name|revertAll
argument_list|()
block|;
name|Q_SIGNALS
operator|:
name|void
name|primeInsert
argument_list|(
argument|int row
argument_list|,
argument|QSqlRecord&record
argument_list|)
block|;
name|void
name|beforeInsert
argument_list|(
name|QSqlRecord
operator|&
name|record
argument_list|)
block|;
name|void
name|beforeUpdate
argument_list|(
argument|int row
argument_list|,
argument|QSqlRecord&record
argument_list|)
block|;
name|void
name|beforeDelete
argument_list|(
argument|int row
argument_list|)
block|;
name|protected
operator|:
name|QSqlTableModel
argument_list|(
argument|QSqlTableModelPrivate&dd
argument_list|,
argument|QObject *parent = Q_NULLPTR
argument_list|,
argument|QSqlDatabase db = QSqlDatabase()
argument_list|)
block|;
name|virtual
name|bool
name|updateRowInTable
argument_list|(
argument|int row
argument_list|,
argument|const QSqlRecord&values
argument_list|)
block|;
name|virtual
name|bool
name|insertRowIntoTable
argument_list|(
specifier|const
name|QSqlRecord
operator|&
name|values
argument_list|)
block|;
name|virtual
name|bool
name|deleteRowFromTable
argument_list|(
argument|int row
argument_list|)
block|;
name|virtual
name|QString
name|orderByClause
argument_list|()
specifier|const
block|;
name|virtual
name|QString
name|selectStatement
argument_list|()
specifier|const
block|;
name|void
name|setPrimaryKey
argument_list|(
specifier|const
name|QSqlIndex
operator|&
name|key
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
name|QModelIndex
name|indexInQuery
argument_list|(
argument|const QModelIndex&item
argument_list|)
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|QSqlRecord
name|primaryValues
argument_list|(
argument|int row
argument_list|)
specifier|const
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
comment|// QSQLTABLEMODEL_H
end_comment
end_unit
