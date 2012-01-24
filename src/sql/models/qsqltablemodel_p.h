begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtSql module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QSQLTABLEMODEL_P_H
end_ifndef
begin_define
DECL|macro|QSQLTABLEMODEL_P_H
define|#
directive|define
name|QSQLTABLEMODEL_P_H
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
comment|// of qsql*model.h .  This header file may change from version to version
end_comment
begin_comment
comment|// without notice, or even be removed.
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
file|"QtCore/qmap.h"
end_include
begin_include
include|#
directive|include
file|"private/qsqlquerymodel_p.h"
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
name|class
name|QSqlTableModelPrivate
range|:
name|public
name|QSqlQueryModelPrivate
block|{
name|Q_DECLARE_PUBLIC
argument_list|(
argument|QSqlTableModel
argument_list|)
name|public
operator|:
name|QSqlTableModelPrivate
argument_list|()
operator|:
name|editIndex
argument_list|(
operator|-
literal|1
argument_list|)
block|,
name|insertIndex
argument_list|(
operator|-
literal|1
argument_list|)
block|,
name|sortColumn
argument_list|(
operator|-
literal|1
argument_list|)
block|,
name|sortOrder
argument_list|(
name|Qt
operator|::
name|AscendingOrder
argument_list|)
block|,
name|strategy
argument_list|(
argument|QSqlTableModel::OnRowChange
argument_list|)
block|{}
name|void
name|clear
argument_list|()
block|;
name|QSqlRecord
name|primaryValues
argument_list|(
argument|int index
argument_list|)
block|;
name|virtual
name|void
name|clearEditBuffer
argument_list|()
block|;
name|virtual
name|void
name|clearCache
argument_list|()
block|;
specifier|static
name|void
name|clearGenerated
argument_list|(
name|QSqlRecord
operator|&
name|rec
argument_list|)
block|;
specifier|static
name|void
name|setGeneratedValue
argument_list|(
argument|QSqlRecord&rec
argument_list|,
argument|int c
argument_list|,
argument|QVariant v
argument_list|)
block|;
name|QSqlRecord
name|record
argument_list|(
argument|const QVector<QVariant>&values
argument_list|)
specifier|const
block|;
name|bool
name|exec
argument_list|(
argument|const QString&stmt
argument_list|,
argument|bool prepStatement
argument_list|,
argument|const QSqlRecord&rec
argument_list|,
argument|const QSqlRecord&whereValues
argument_list|)
block|;
name|virtual
name|void
name|revertCachedRow
argument_list|(
argument|int row
argument_list|)
block|;
name|void
name|revertInsertedRow
argument_list|()
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
name|int
name|nameToIndex
argument_list|(
argument|const QString&name
argument_list|)
specifier|const
block|;
name|void
name|initRecordAndPrimaryIndex
argument_list|()
block|;
name|QSqlDatabase
name|db
block|;
name|int
name|editIndex
block|;
name|int
name|insertIndex
block|;
name|int
name|sortColumn
block|;
name|Qt
operator|::
name|SortOrder
name|sortOrder
block|;
name|QSqlTableModel
operator|::
name|EditStrategy
name|strategy
block|;
name|QSqlQuery
name|editQuery
block|;
name|QSqlIndex
name|primaryIndex
block|;
name|QString
name|tableName
block|;
name|QString
name|filter
block|;      enum
name|Op
block|{
name|None
block|,
name|Insert
block|,
name|Update
block|,
name|Delete
block|}
block|;      struct
name|ModifiedRow
block|{
specifier|inline
name|ModifiedRow
argument_list|(
argument|Op o = None
argument_list|,
argument|const QSqlRecord&r = QSqlRecord()
argument_list|,
argument|const QSqlRecord&pVals = QSqlRecord()
argument_list|)
operator|:
name|op
argument_list|(
name|o
argument_list|)
block|,
name|rec
argument_list|(
name|r
argument_list|)
block|,
name|primaryValues
argument_list|(
argument|pVals
argument_list|)
block|{
name|clearGenerated
argument_list|(
name|rec
argument_list|)
block|; }
specifier|inline
name|void
name|setValue
argument_list|(
argument|int c
argument_list|,
argument|const QVariant&v
argument_list|)
block|{
name|rec
operator|.
name|setValue
argument_list|(
name|c
argument_list|,
name|v
argument_list|)
block|;
name|rec
operator|.
name|setGenerated
argument_list|(
name|c
argument_list|,
name|true
argument_list|)
block|;         }
name|Op
name|op
block|;
name|QSqlRecord
name|rec
block|;
name|QSqlRecord
name|primaryValues
block|;     }
block|;
name|QSqlRecord
name|editBuffer
block|;
typedef|typedef
name|QMap
operator|<
name|int
operator|,
name|ModifiedRow
operator|>
name|CacheMap
expr_stmt|;
name|CacheMap
name|cache
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
comment|// QSQLTABLEMODEL_P_H
end_comment
end_unit
