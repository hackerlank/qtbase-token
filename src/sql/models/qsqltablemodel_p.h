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
name|QSqlTableModel
operator|::
name|OnRowChange
argument_list|)
block|,
name|busyInsertingRows
argument_list|(
argument|false
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
specifier|const
block|;
name|virtual
name|void
name|clearCache
argument_list|()
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
name|virtual
name|int
name|nameToIndex
argument_list|(
argument|const QString&name
argument_list|)
specifier|const
block|;
name|QString
name|strippedFieldName
argument_list|(
argument|const QString&name
argument_list|)
specifier|const
block|;
name|int
name|insertCount
argument_list|(
argument|int maxRow = -
literal|1
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
name|bool
name|busyInsertingRows
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
block|;
name|class
name|ModifiedRow
block|{
name|public
operator|:
specifier|inline
name|ModifiedRow
argument_list|(
argument|Op o = None
argument_list|,
argument|const QSqlRecord&r = QSqlRecord()
argument_list|)
operator|:
name|m_op
argument_list|(
name|None
argument_list|)
block|,
name|m_db_values
argument_list|(
name|r
argument_list|)
block|,
name|m_insert
argument_list|(
argument|o == Insert
argument_list|)
block|{
name|setOp
argument_list|(
name|o
argument_list|)
block|; }
specifier|inline
name|Op
name|op
argument_list|()
specifier|const
block|{
return|return
name|m_op
return|;
block|}
specifier|inline
name|void
name|setOp
argument_list|(
argument|Op o
argument_list|)
block|{
if|if
condition|(
name|o
operator|==
name|None
condition|)
name|m_submitted
operator|=
name|true
expr_stmt|;
if|if
condition|(
name|o
operator|==
name|m_op
condition|)
return|return;
name|m_submitted
operator|=
operator|(
name|o
operator|!=
name|Insert
operator|&&
name|o
operator|!=
name|Delete
operator|)
block|;
name|m_op
operator|=
name|o
block|;
name|m_rec
operator|=
name|m_db_values
block|;
name|setGenerated
argument_list|(
name|m_rec
argument_list|,
name|m_op
operator|==
name|Delete
argument_list|)
block|;         }
specifier|inline
name|QSqlRecord
name|rec
argument_list|()
specifier|const
block|{
return|return
name|m_rec
return|;
block|}
end_decl_stmt
begin_function
specifier|inline
name|QSqlRecord
modifier|&
name|recRef
parameter_list|()
block|{
return|return
name|m_rec
return|;
block|}
end_function
begin_function
specifier|inline
name|void
name|setValue
parameter_list|(
name|int
name|c
parameter_list|,
specifier|const
name|QVariant
modifier|&
name|v
parameter_list|)
block|{
name|m_submitted
operator|=
name|false
expr_stmt|;
name|m_rec
operator|.
name|setValue
argument_list|(
name|c
argument_list|,
name|v
argument_list|)
expr_stmt|;
name|m_rec
operator|.
name|setGenerated
argument_list|(
name|c
argument_list|,
name|true
argument_list|)
expr_stmt|;
block|}
end_function
begin_expr_stmt
specifier|inline
name|bool
name|submitted
argument_list|()
specifier|const
block|{
return|return
name|m_submitted
return|;
block|}
end_expr_stmt
begin_function
specifier|inline
name|void
name|setSubmitted
parameter_list|()
block|{
name|m_submitted
operator|=
name|true
expr_stmt|;
name|setGenerated
argument_list|(
name|m_rec
argument_list|,
name|false
argument_list|)
expr_stmt|;
if|if
condition|(
name|m_op
operator|==
name|Delete
condition|)
block|{
name|m_rec
operator|.
name|clearValues
argument_list|()
expr_stmt|;
block|}
else|else
block|{
name|m_op
operator|=
name|Update
expr_stmt|;
name|m_db_values
operator|=
name|m_rec
expr_stmt|;
name|setGenerated
argument_list|(
name|m_db_values
argument_list|,
name|true
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
specifier|inline
name|void
name|refresh
parameter_list|(
name|bool
name|exists
parameter_list|,
specifier|const
name|QSqlRecord
modifier|&
name|newvals
parameter_list|)
block|{
name|m_submitted
operator|=
name|true
expr_stmt|;
if|if
condition|(
name|exists
condition|)
block|{
name|m_op
operator|=
name|Update
expr_stmt|;
name|m_db_values
operator|=
name|newvals
expr_stmt|;
name|m_rec
operator|=
name|newvals
expr_stmt|;
name|setGenerated
argument_list|(
name|m_rec
argument_list|,
name|false
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|m_op
operator|=
name|Delete
expr_stmt|;
name|m_rec
operator|.
name|clear
argument_list|()
expr_stmt|;
name|m_db_values
operator|.
name|clear
argument_list|()
expr_stmt|;
block|}
block|}
end_function
begin_expr_stmt
specifier|inline
name|bool
name|insert
argument_list|()
specifier|const
block|{
return|return
name|m_insert
return|;
block|}
end_expr_stmt
begin_function
specifier|inline
name|void
name|revert
parameter_list|()
block|{
if|if
condition|(
name|m_submitted
condition|)
return|return;
if|if
condition|(
name|m_op
operator|==
name|Delete
condition|)
name|m_op
operator|=
name|Update
expr_stmt|;
name|m_rec
operator|=
name|m_db_values
expr_stmt|;
name|setGenerated
argument_list|(
name|m_rec
argument_list|,
name|false
argument_list|)
expr_stmt|;
name|m_submitted
operator|=
name|true
expr_stmt|;
block|}
end_function
begin_decl_stmt
specifier|inline
name|QSqlRecord
name|primaryValues
argument_list|(
specifier|const
name|QSqlRecord
operator|&
name|pi
argument_list|)
decl|const
block|{
if|if
condition|(
name|m_op
operator|==
name|None
operator|||
name|m_op
operator|==
name|Insert
condition|)
return|return
name|QSqlRecord
argument_list|()
return|;
name|QSqlRecord
name|values
parameter_list|(
name|pi
parameter_list|)
function_decl|;
for|for
control|(
name|int
name|i
init|=
name|values
operator|.
name|count
argument_list|()
operator|-
literal|1
init|;
name|i
operator|>=
literal|0
condition|;
operator|--
name|i
control|)
name|values
operator|.
name|setValue
argument_list|(
name|i
argument_list|,
name|m_db_values
operator|.
name|value
argument_list|(
name|values
operator|.
name|fieldName
argument_list|(
name|i
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|values
return|;
block|}
end_decl_stmt
begin_label
name|private
label|:
end_label
begin_function
specifier|inline
specifier|static
name|void
name|setGenerated
parameter_list|(
name|QSqlRecord
modifier|&
name|r
parameter_list|,
name|bool
name|g
parameter_list|)
block|{
for|for
control|(
name|int
name|i
init|=
name|r
operator|.
name|count
argument_list|()
operator|-
literal|1
init|;
name|i
operator|>=
literal|0
condition|;
operator|--
name|i
control|)
name|r
operator|.
name|setGenerated
argument_list|(
name|i
argument_list|,
name|g
argument_list|)
expr_stmt|;
block|}
end_function
begin_decl_stmt
name|Op
name|m_op
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QSqlRecord
name|m_rec
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QSqlRecord
name|m_db_values
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|bool
name|m_submitted
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|bool
name|m_insert
decl_stmt|;
end_decl_stmt
begin_typedef
unit|};
typedef|typedef
name|QMap
operator|<
name|int
operator|,
name|ModifiedRow
operator|>
name|CacheMap
expr_stmt|;
end_typedef
begin_decl_stmt
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
