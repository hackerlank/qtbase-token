begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the QtSql module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qsqlquerymodel.h"
end_include
begin_include
include|#
directive|include
file|"qsqlquerymodel_p.h"
end_include
begin_include
include|#
directive|include
file|<qdebug.h>
end_include
begin_include
include|#
directive|include
file|<qsqldriver.h>
end_include
begin_include
include|#
directive|include
file|<qsqlfield.h>
end_include
begin_function
name|QT_BEGIN_NAMESPACE
DECL|macro|QSQL_PREFETCH
define|#
directive|define
name|QSQL_PREFETCH
value|255
DECL|function|prefetch
name|void
name|QSqlQueryModelPrivate
operator|::
name|prefetch
parameter_list|(
name|int
name|limit
parameter_list|)
block|{
name|Q_Q
argument_list|(
name|QSqlQueryModel
argument_list|)
expr_stmt|;
if|if
condition|(
name|atEnd
operator|||
name|limit
operator|<=
name|bottom
operator|.
name|row
argument_list|()
operator|||
name|bottom
operator|.
name|column
argument_list|()
operator|==
operator|-
literal|1
condition|)
return|return;
name|QModelIndex
name|newBottom
decl_stmt|;
specifier|const
name|int
name|oldBottomRow
init|=
name|qMax
argument_list|(
name|bottom
operator|.
name|row
argument_list|()
argument_list|,
literal|0
argument_list|)
decl_stmt|;
comment|// try to seek directly
if|if
condition|(
name|query
operator|.
name|seek
argument_list|(
name|limit
argument_list|)
condition|)
block|{
name|newBottom
operator|=
name|q
operator|->
name|createIndex
argument_list|(
name|limit
argument_list|,
name|bottom
operator|.
name|column
argument_list|()
argument_list|)
expr_stmt|;
block|}
else|else
block|{
comment|// have to seek back to our old position for MS Access
name|int
name|i
init|=
name|oldBottomRow
decl_stmt|;
if|if
condition|(
name|query
operator|.
name|seek
argument_list|(
name|i
argument_list|)
condition|)
block|{
while|while
condition|(
name|query
operator|.
name|next
argument_list|()
condition|)
operator|++
name|i
expr_stmt|;
name|newBottom
operator|=
name|q
operator|->
name|createIndex
argument_list|(
name|i
argument_list|,
name|bottom
operator|.
name|column
argument_list|()
argument_list|)
expr_stmt|;
block|}
else|else
block|{
comment|// empty or invalid query
name|newBottom
operator|=
name|q
operator|->
name|createIndex
argument_list|(
operator|-
literal|1
argument_list|,
name|bottom
operator|.
name|column
argument_list|()
argument_list|)
expr_stmt|;
block|}
name|atEnd
operator|=
literal|true
expr_stmt|;
comment|// this is the end.
block|}
if|if
condition|(
name|newBottom
operator|.
name|row
argument_list|()
operator|>=
literal|0
operator|&&
name|newBottom
operator|.
name|row
argument_list|()
operator|>
name|bottom
operator|.
name|row
argument_list|()
condition|)
block|{
name|q
operator|->
name|beginInsertRows
argument_list|(
name|QModelIndex
argument_list|()
argument_list|,
name|bottom
operator|.
name|row
argument_list|()
operator|+
literal|1
argument_list|,
name|newBottom
operator|.
name|row
argument_list|()
argument_list|)
expr_stmt|;
name|bottom
operator|=
name|newBottom
expr_stmt|;
name|q
operator|->
name|endInsertRows
argument_list|()
expr_stmt|;
block|}
else|else
block|{
name|bottom
operator|=
name|newBottom
expr_stmt|;
block|}
block|}
end_function
begin_destructor
DECL|function|~QSqlQueryModelPrivate
name|QSqlQueryModelPrivate
operator|::
name|~
name|QSqlQueryModelPrivate
parameter_list|()
block|{ }
end_destructor
begin_function
DECL|function|initColOffsets
name|void
name|QSqlQueryModelPrivate
operator|::
name|initColOffsets
parameter_list|(
name|int
name|size
parameter_list|)
block|{
name|colOffsets
operator|.
name|resize
argument_list|(
name|size
argument_list|)
expr_stmt|;
name|memset
argument_list|(
name|colOffsets
operator|.
name|data
argument_list|()
argument_list|,
literal|0
argument_list|,
name|colOffsets
operator|.
name|size
argument_list|()
operator|*
sizeof|sizeof
argument_list|(
name|int
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|columnInQuery
name|int
name|QSqlQueryModelPrivate
operator|::
name|columnInQuery
parameter_list|(
name|int
name|modelColumn
parameter_list|)
specifier|const
block|{
if|if
condition|(
name|modelColumn
operator|<
literal|0
operator|||
name|modelColumn
operator|>=
name|rec
operator|.
name|count
argument_list|()
operator|||
operator|!
name|rec
operator|.
name|isGenerated
argument_list|(
name|modelColumn
argument_list|)
operator|||
name|modelColumn
operator|>=
name|colOffsets
operator|.
name|size
argument_list|()
condition|)
return|return
operator|-
literal|1
return|;
return|return
name|modelColumn
operator|-
name|colOffsets
index|[
name|modelColumn
index|]
return|;
block|}
end_function
begin_comment
comment|/*!     \class QSqlQueryModel     \brief The QSqlQueryModel class provides a read-only data model for SQL     result sets.      \ingroup database     \inmodule QtSql      QSqlQueryModel is a high-level interface for executing SQL     statements and traversing the result set. It is built on top of     the lower-level QSqlQuery and can be used to provide data to     view classes such as QTableView. For example:      \snippet sqldatabase/sqldatabase.cpp 16      We set the model's query, then we set up the labels displayed in     the view header.      QSqlQueryModel can also be used to access a database     programmatically, without binding it to a view:      \snippet sqldatabase/sqldatabase.cpp 21      The code snippet above extracts the \c salary field from record 4 in     the result set of the query \c{SELECT * from employee}. Assuming     that \c salary is column 2, we can rewrite the last line as follows:      \snippet sqldatabase/sqldatabase.cpp 22      The model is read-only by default. To make it read-write, you     must subclass it and reimplement setData() and flags(). Another     option is to use QSqlTableModel, which provides a read-write     model based on a single database table.      The \l{querymodel} example illustrates how to use     QSqlQueryModel to display the result of a query. It also shows     how to subclass QSqlQueryModel to customize the contents of the     data before showing it to the user, and how to create a     read-write model based on QSqlQueryModel.      If the database doesn't return the number of selected rows in     a query, the model will fetch rows incrementally.     See fetchMore() for more information.      \sa QSqlTableModel, QSqlRelationalTableModel, QSqlQuery,         {Model/View Programming}, {Query Model Example} */
end_comment
begin_comment
comment|/*!     Creates an empty QSqlQueryModel with the given \a parent.  */
end_comment
begin_constructor
DECL|function|QSqlQueryModel
name|QSqlQueryModel
operator|::
name|QSqlQueryModel
parameter_list|(
name|QObject
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QAbstractTableModel
argument_list|(
operator|*
operator|new
name|QSqlQueryModelPrivate
argument_list|,
name|parent
argument_list|)
block|{ }
end_constructor
begin_comment
comment|/*! \internal  */
end_comment
begin_constructor
DECL|function|QSqlQueryModel
name|QSqlQueryModel
operator|::
name|QSqlQueryModel
parameter_list|(
name|QSqlQueryModelPrivate
modifier|&
name|dd
parameter_list|,
name|QObject
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QAbstractTableModel
argument_list|(
name|dd
argument_list|,
name|parent
argument_list|)
block|{ }
end_constructor
begin_comment
comment|/*!     Destroys the object and frees any allocated resources.      \sa clear() */
end_comment
begin_destructor
DECL|function|~QSqlQueryModel
name|QSqlQueryModel
operator|::
name|~
name|QSqlQueryModel
parameter_list|()
block|{ }
end_destructor
begin_comment
comment|/*!     \since 4.1      Fetches more rows from a database.     This only affects databases that don't report back the size of a query     (see QSqlDriver::hasFeature()).      To force fetching of the entire result set, you can use the following:      \snippet code/src_sql_models_qsqlquerymodel.cpp 0      \a parent should always be an invalid QModelIndex.      \sa canFetchMore() */
end_comment
begin_function
DECL|function|fetchMore
name|void
name|QSqlQueryModel
operator|::
name|fetchMore
parameter_list|(
specifier|const
name|QModelIndex
modifier|&
name|parent
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QSqlQueryModel
argument_list|)
expr_stmt|;
if|if
condition|(
name|parent
operator|.
name|isValid
argument_list|()
condition|)
return|return;
name|d
operator|->
name|prefetch
argument_list|(
name|qMax
argument_list|(
name|d
operator|->
name|bottom
operator|.
name|row
argument_list|()
argument_list|,
literal|0
argument_list|)
operator|+
name|QSQL_PREFETCH
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     \since 4.1      Returns \c true if it is possible to read more rows from the database.     This only affects databases that don't report back the size of a query     (see QSqlDriver::hasFeature()).      \a parent should always be an invalid QModelIndex.      \sa fetchMore()  */
end_comment
begin_function
DECL|function|canFetchMore
name|bool
name|QSqlQueryModel
operator|::
name|canFetchMore
parameter_list|(
specifier|const
name|QModelIndex
modifier|&
name|parent
parameter_list|)
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QSqlQueryModel
argument_list|)
expr_stmt|;
return|return
operator|(
operator|!
name|parent
operator|.
name|isValid
argument_list|()
operator|&&
operator|!
name|d
operator|->
name|atEnd
operator|)
return|;
block|}
end_function
begin_comment
comment|/*! \internal  */
end_comment
begin_function
DECL|function|beginInsertRows
name|void
name|QSqlQueryModel
operator|::
name|beginInsertRows
parameter_list|(
specifier|const
name|QModelIndex
modifier|&
name|parent
parameter_list|,
name|int
name|first
parameter_list|,
name|int
name|last
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QSqlQueryModel
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|d
operator|->
name|nestedResetLevel
condition|)
name|QAbstractTableModel
operator|::
name|beginInsertRows
argument_list|(
name|parent
argument_list|,
name|first
argument_list|,
name|last
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*! \internal  */
end_comment
begin_function
DECL|function|endInsertRows
name|void
name|QSqlQueryModel
operator|::
name|endInsertRows
parameter_list|()
block|{
name|Q_D
argument_list|(
name|QSqlQueryModel
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|d
operator|->
name|nestedResetLevel
condition|)
name|QAbstractTableModel
operator|::
name|endInsertRows
argument_list|()
expr_stmt|;
block|}
end_function
begin_comment
comment|/*! \internal  */
end_comment
begin_function
DECL|function|beginRemoveRows
name|void
name|QSqlQueryModel
operator|::
name|beginRemoveRows
parameter_list|(
specifier|const
name|QModelIndex
modifier|&
name|parent
parameter_list|,
name|int
name|first
parameter_list|,
name|int
name|last
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QSqlQueryModel
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|d
operator|->
name|nestedResetLevel
condition|)
name|QAbstractTableModel
operator|::
name|beginRemoveRows
argument_list|(
name|parent
argument_list|,
name|first
argument_list|,
name|last
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*! \internal  */
end_comment
begin_function
DECL|function|endRemoveRows
name|void
name|QSqlQueryModel
operator|::
name|endRemoveRows
parameter_list|()
block|{
name|Q_D
argument_list|(
name|QSqlQueryModel
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|d
operator|->
name|nestedResetLevel
condition|)
name|QAbstractTableModel
operator|::
name|endRemoveRows
argument_list|()
expr_stmt|;
block|}
end_function
begin_comment
comment|/*! \internal  */
end_comment
begin_function
DECL|function|beginInsertColumns
name|void
name|QSqlQueryModel
operator|::
name|beginInsertColumns
parameter_list|(
specifier|const
name|QModelIndex
modifier|&
name|parent
parameter_list|,
name|int
name|first
parameter_list|,
name|int
name|last
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QSqlQueryModel
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|d
operator|->
name|nestedResetLevel
condition|)
name|QAbstractTableModel
operator|::
name|beginInsertColumns
argument_list|(
name|parent
argument_list|,
name|first
argument_list|,
name|last
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*! \internal  */
end_comment
begin_function
DECL|function|endInsertColumns
name|void
name|QSqlQueryModel
operator|::
name|endInsertColumns
parameter_list|()
block|{
name|Q_D
argument_list|(
name|QSqlQueryModel
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|d
operator|->
name|nestedResetLevel
condition|)
name|QAbstractTableModel
operator|::
name|endInsertColumns
argument_list|()
expr_stmt|;
block|}
end_function
begin_comment
comment|/*! \internal  */
end_comment
begin_function
DECL|function|beginRemoveColumns
name|void
name|QSqlQueryModel
operator|::
name|beginRemoveColumns
parameter_list|(
specifier|const
name|QModelIndex
modifier|&
name|parent
parameter_list|,
name|int
name|first
parameter_list|,
name|int
name|last
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QSqlQueryModel
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|d
operator|->
name|nestedResetLevel
condition|)
name|QAbstractTableModel
operator|::
name|beginRemoveColumns
argument_list|(
name|parent
argument_list|,
name|first
argument_list|,
name|last
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*! \internal  */
end_comment
begin_function
DECL|function|endRemoveColumns
name|void
name|QSqlQueryModel
operator|::
name|endRemoveColumns
parameter_list|()
block|{
name|Q_D
argument_list|(
name|QSqlQueryModel
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|d
operator|->
name|nestedResetLevel
condition|)
name|QAbstractTableModel
operator|::
name|endRemoveColumns
argument_list|()
expr_stmt|;
block|}
end_function
begin_comment
comment|/*! \internal  */
end_comment
begin_function
DECL|function|beginResetModel
name|void
name|QSqlQueryModel
operator|::
name|beginResetModel
parameter_list|()
block|{
name|Q_D
argument_list|(
name|QSqlQueryModel
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|d
operator|->
name|nestedResetLevel
condition|)
name|QAbstractTableModel
operator|::
name|beginResetModel
argument_list|()
expr_stmt|;
operator|++
name|d
operator|->
name|nestedResetLevel
expr_stmt|;
block|}
end_function
begin_comment
comment|/*! \internal  */
end_comment
begin_function
DECL|function|endResetModel
name|void
name|QSqlQueryModel
operator|::
name|endResetModel
parameter_list|()
block|{
name|Q_D
argument_list|(
name|QSqlQueryModel
argument_list|)
expr_stmt|;
operator|--
name|d
operator|->
name|nestedResetLevel
expr_stmt|;
if|if
condition|(
operator|!
name|d
operator|->
name|nestedResetLevel
condition|)
name|QAbstractTableModel
operator|::
name|endResetModel
argument_list|()
expr_stmt|;
block|}
end_function
begin_comment
comment|/*! \fn int QSqlQueryModel::rowCount(const QModelIndex&parent) const     \since 4.1      If the database supports returning the size of a query     (see QSqlDriver::hasFeature()), the number of rows of the current     query is returned. Otherwise, returns the number of rows     currently cached on the client.      \a parent should always be an invalid QModelIndex.      \sa canFetchMore(), QSqlDriver::hasFeature()  */
end_comment
begin_function
DECL|function|rowCount
name|int
name|QSqlQueryModel
operator|::
name|rowCount
parameter_list|(
specifier|const
name|QModelIndex
modifier|&
name|index
parameter_list|)
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QSqlQueryModel
argument_list|)
expr_stmt|;
return|return
name|index
operator|.
name|isValid
argument_list|()
condition|?
literal|0
else|:
name|d
operator|->
name|bottom
operator|.
name|row
argument_list|()
operator|+
literal|1
return|;
block|}
end_function
begin_comment
comment|/*! \reimp  */
end_comment
begin_function
DECL|function|columnCount
name|int
name|QSqlQueryModel
operator|::
name|columnCount
parameter_list|(
specifier|const
name|QModelIndex
modifier|&
name|index
parameter_list|)
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QSqlQueryModel
argument_list|)
expr_stmt|;
return|return
name|index
operator|.
name|isValid
argument_list|()
condition|?
literal|0
else|:
name|d
operator|->
name|rec
operator|.
name|count
argument_list|()
return|;
block|}
end_function
begin_comment
comment|/*!     Returns the value for the specified \a item and \a role.      If \a item is out of bounds or if an error occurred, an invalid     QVariant is returned.      \sa lastError() */
end_comment
begin_function
DECL|function|data
name|QVariant
name|QSqlQueryModel
operator|::
name|data
parameter_list|(
specifier|const
name|QModelIndex
modifier|&
name|item
parameter_list|,
name|int
name|role
parameter_list|)
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QSqlQueryModel
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|item
operator|.
name|isValid
argument_list|()
condition|)
return|return
name|QVariant
argument_list|()
return|;
name|QVariant
name|v
decl_stmt|;
if|if
condition|(
name|role
operator|&
operator|~
operator|(
name|Qt
operator|::
name|DisplayRole
operator||
name|Qt
operator|::
name|EditRole
operator|)
condition|)
return|return
name|v
return|;
if|if
condition|(
operator|!
name|d
operator|->
name|rec
operator|.
name|isGenerated
argument_list|(
name|item
operator|.
name|column
argument_list|()
argument_list|)
condition|)
return|return
name|v
return|;
name|QModelIndex
name|dItem
init|=
name|indexInQuery
argument_list|(
name|item
argument_list|)
decl_stmt|;
if|if
condition|(
name|dItem
operator|.
name|row
argument_list|()
operator|>
name|d
operator|->
name|bottom
operator|.
name|row
argument_list|()
condition|)
cast|const_cast
argument_list|<
name|QSqlQueryModelPrivate
operator|*
argument_list|>
argument_list|(
name|d
argument_list|)
operator|->
name|prefetch
argument_list|(
name|dItem
operator|.
name|row
argument_list|()
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|d
operator|->
name|query
operator|.
name|seek
argument_list|(
name|dItem
operator|.
name|row
argument_list|()
argument_list|)
condition|)
block|{
name|d
operator|->
name|error
operator|=
name|d
operator|->
name|query
operator|.
name|lastError
argument_list|()
expr_stmt|;
return|return
name|v
return|;
block|}
return|return
name|d
operator|->
name|query
operator|.
name|value
argument_list|(
name|dItem
operator|.
name|column
argument_list|()
argument_list|)
return|;
block|}
end_function
begin_comment
comment|/*!     Returns the header data for the given \a role in the \a section     of the header with the specified \a orientation. */
end_comment
begin_function
DECL|function|headerData
name|QVariant
name|QSqlQueryModel
operator|::
name|headerData
parameter_list|(
name|int
name|section
parameter_list|,
name|Qt
operator|::
name|Orientation
name|orientation
parameter_list|,
name|int
name|role
parameter_list|)
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QSqlQueryModel
argument_list|)
expr_stmt|;
if|if
condition|(
name|orientation
operator|==
name|Qt
operator|::
name|Horizontal
condition|)
block|{
name|QVariant
name|val
init|=
name|d
operator|->
name|headers
operator|.
name|value
argument_list|(
name|section
argument_list|)
operator|.
name|value
argument_list|(
name|role
argument_list|)
decl_stmt|;
if|if
condition|(
name|role
operator|==
name|Qt
operator|::
name|DisplayRole
operator|&&
operator|!
name|val
operator|.
name|isValid
argument_list|()
condition|)
name|val
operator|=
name|d
operator|->
name|headers
operator|.
name|value
argument_list|(
name|section
argument_list|)
operator|.
name|value
argument_list|(
name|Qt
operator|::
name|EditRole
argument_list|)
expr_stmt|;
if|if
condition|(
name|val
operator|.
name|isValid
argument_list|()
condition|)
return|return
name|val
return|;
if|if
condition|(
name|role
operator|==
name|Qt
operator|::
name|DisplayRole
operator|&&
name|d
operator|->
name|rec
operator|.
name|count
argument_list|()
operator|>
name|section
operator|&&
name|d
operator|->
name|columnInQuery
argument_list|(
name|section
argument_list|)
operator|!=
operator|-
literal|1
condition|)
return|return
name|d
operator|->
name|rec
operator|.
name|fieldName
argument_list|(
name|section
argument_list|)
return|;
block|}
return|return
name|QAbstractItemModel
operator|::
name|headerData
argument_list|(
name|section
argument_list|,
name|orientation
argument_list|,
name|role
argument_list|)
return|;
block|}
end_function
begin_comment
comment|/*!     This virtual function is called whenever the query changes. The     default implementation does nothing.      query() returns the new query.      \sa query(), setQuery()  */
end_comment
begin_function
DECL|function|queryChange
name|void
name|QSqlQueryModel
operator|::
name|queryChange
parameter_list|()
block|{
comment|// do nothing
block|}
end_function
begin_comment
comment|/*!     Resets the model and sets the data provider to be the given \a     query. Note that the query must be active and must not be     isForwardOnly().      lastError() can be used to retrieve verbose information if there     was an error setting the query.      \note Calling setQuery() will remove any inserted columns.      \sa query(), QSqlQuery::isActive(), QSqlQuery::setForwardOnly(), lastError() */
end_comment
begin_function
DECL|function|setQuery
name|void
name|QSqlQueryModel
operator|::
name|setQuery
parameter_list|(
specifier|const
name|QSqlQuery
modifier|&
name|query
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QSqlQueryModel
argument_list|)
expr_stmt|;
name|beginResetModel
argument_list|()
expr_stmt|;
name|QSqlRecord
name|newRec
init|=
name|query
operator|.
name|record
argument_list|()
decl_stmt|;
name|bool
name|columnsChanged
init|=
operator|(
name|newRec
operator|!=
name|d
operator|->
name|rec
operator|)
decl_stmt|;
if|if
condition|(
name|d
operator|->
name|colOffsets
operator|.
name|size
argument_list|()
operator|!=
name|newRec
operator|.
name|count
argument_list|()
operator|||
name|columnsChanged
condition|)
name|d
operator|->
name|initColOffsets
argument_list|(
name|newRec
operator|.
name|count
argument_list|()
argument_list|)
expr_stmt|;
name|d
operator|->
name|bottom
operator|=
name|QModelIndex
argument_list|()
expr_stmt|;
name|d
operator|->
name|error
operator|=
name|QSqlError
argument_list|()
expr_stmt|;
name|d
operator|->
name|query
operator|=
name|query
expr_stmt|;
name|d
operator|->
name|rec
operator|=
name|newRec
expr_stmt|;
name|d
operator|->
name|atEnd
operator|=
literal|true
expr_stmt|;
if|if
condition|(
name|query
operator|.
name|isForwardOnly
argument_list|()
condition|)
block|{
name|d
operator|->
name|error
operator|=
name|QSqlError
argument_list|(
name|QLatin1String
argument_list|(
literal|"Forward-only queries "
literal|"cannot be used in a data model"
argument_list|)
argument_list|,
name|QString
argument_list|()
argument_list|,
name|QSqlError
operator|::
name|ConnectionError
argument_list|)
expr_stmt|;
name|endResetModel
argument_list|()
expr_stmt|;
return|return;
block|}
if|if
condition|(
operator|!
name|query
operator|.
name|isActive
argument_list|()
condition|)
block|{
name|d
operator|->
name|error
operator|=
name|query
operator|.
name|lastError
argument_list|()
expr_stmt|;
name|endResetModel
argument_list|()
expr_stmt|;
return|return;
block|}
if|if
condition|(
name|query
operator|.
name|driver
argument_list|()
operator|->
name|hasFeature
argument_list|(
name|QSqlDriver
operator|::
name|QuerySize
argument_list|)
operator|&&
name|d
operator|->
name|query
operator|.
name|size
argument_list|()
operator|>
literal|0
condition|)
block|{
name|d
operator|->
name|bottom
operator|=
name|createIndex
argument_list|(
name|d
operator|->
name|query
operator|.
name|size
argument_list|()
operator|-
literal|1
argument_list|,
name|d
operator|->
name|rec
operator|.
name|count
argument_list|()
operator|-
literal|1
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|d
operator|->
name|bottom
operator|=
name|createIndex
argument_list|(
operator|-
literal|1
argument_list|,
name|d
operator|->
name|rec
operator|.
name|count
argument_list|()
operator|-
literal|1
argument_list|)
expr_stmt|;
name|d
operator|->
name|atEnd
operator|=
literal|false
expr_stmt|;
block|}
comment|// fetchMore does the rowsInserted stuff for incremental models
name|fetchMore
argument_list|()
expr_stmt|;
name|endResetModel
argument_list|()
expr_stmt|;
name|queryChange
argument_list|()
expr_stmt|;
block|}
end_function
begin_comment
comment|/*! \overload      Executes the query \a query for the given database connection \a     db. If no database (or an invalid database) is specified, the     default connection is used.      lastError() can be used to retrieve verbose information if there     was an error setting the query.      Example:     \snippet code/src_sql_models_qsqlquerymodel.cpp 1      \sa query(), queryChange(), lastError() */
end_comment
begin_function
DECL|function|setQuery
name|void
name|QSqlQueryModel
operator|::
name|setQuery
parameter_list|(
specifier|const
name|QString
modifier|&
name|query
parameter_list|,
specifier|const
name|QSqlDatabase
modifier|&
name|db
parameter_list|)
block|{
name|setQuery
argument_list|(
name|QSqlQuery
argument_list|(
name|query
argument_list|,
name|db
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     Clears the model and releases any acquired resource. */
end_comment
begin_function
DECL|function|clear
name|void
name|QSqlQueryModel
operator|::
name|clear
parameter_list|()
block|{
name|Q_D
argument_list|(
name|QSqlQueryModel
argument_list|)
expr_stmt|;
name|beginResetModel
argument_list|()
expr_stmt|;
name|d
operator|->
name|error
operator|=
name|QSqlError
argument_list|()
expr_stmt|;
name|d
operator|->
name|atEnd
operator|=
literal|true
expr_stmt|;
name|d
operator|->
name|query
operator|.
name|clear
argument_list|()
expr_stmt|;
name|d
operator|->
name|rec
operator|.
name|clear
argument_list|()
expr_stmt|;
name|d
operator|->
name|colOffsets
operator|.
name|clear
argument_list|()
expr_stmt|;
name|d
operator|->
name|bottom
operator|=
name|QModelIndex
argument_list|()
expr_stmt|;
name|d
operator|->
name|headers
operator|.
name|clear
argument_list|()
expr_stmt|;
name|endResetModel
argument_list|()
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     Sets the caption for a horizontal header for the specified \a role to     \a value. This is useful if the model is used to     display data in a view (e.g., QTableView).      Returns \c true if \a orientation is Qt::Horizontal and     the \a section refers to a valid section; otherwise returns     false.      Note that this function cannot be used to modify values in the     database since the model is read-only.      \sa data()  */
end_comment
begin_function
DECL|function|setHeaderData
name|bool
name|QSqlQueryModel
operator|::
name|setHeaderData
parameter_list|(
name|int
name|section
parameter_list|,
name|Qt
operator|::
name|Orientation
name|orientation
parameter_list|,
specifier|const
name|QVariant
modifier|&
name|value
parameter_list|,
name|int
name|role
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QSqlQueryModel
argument_list|)
expr_stmt|;
if|if
condition|(
name|orientation
operator|!=
name|Qt
operator|::
name|Horizontal
operator|||
name|section
operator|<
literal|0
operator|||
name|columnCount
argument_list|()
operator|<=
name|section
condition|)
return|return
literal|false
return|;
if|if
condition|(
name|d
operator|->
name|headers
operator|.
name|size
argument_list|()
operator|<=
name|section
condition|)
name|d
operator|->
name|headers
operator|.
name|resize
argument_list|(
name|qMax
argument_list|(
name|section
operator|+
literal|1
argument_list|,
literal|16
argument_list|)
argument_list|)
expr_stmt|;
name|d
operator|->
name|headers
index|[
name|section
index|]
index|[
name|role
index|]
operator|=
name|value
expr_stmt|;
emit|emit
name|headerDataChanged
argument_list|(
name|orientation
argument_list|,
name|section
argument_list|,
name|section
argument_list|)
emit|;
return|return
literal|true
return|;
block|}
end_function
begin_comment
comment|/*!     Returns the QSqlQuery associated with this model.      \sa setQuery() */
end_comment
begin_function
DECL|function|query
name|QSqlQuery
name|QSqlQueryModel
operator|::
name|query
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QSqlQueryModel
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|query
return|;
block|}
end_function
begin_comment
comment|/*!     Returns information about the last error that occurred on the     database.      \sa query() */
end_comment
begin_function
DECL|function|lastError
name|QSqlError
name|QSqlQueryModel
operator|::
name|lastError
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QSqlQueryModel
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|error
return|;
block|}
end_function
begin_comment
comment|/*!    Protected function which allows derived classes to set the value of    the last error that occurred on the database to \a error.     \sa lastError() */
end_comment
begin_function
DECL|function|setLastError
name|void
name|QSqlQueryModel
operator|::
name|setLastError
parameter_list|(
specifier|const
name|QSqlError
modifier|&
name|error
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QSqlQueryModel
argument_list|)
expr_stmt|;
name|d
operator|->
name|error
operator|=
name|error
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     Returns the record containing information about the fields of the     current query. If \a row is the index of a valid row, the record     will be populated with values from that row.      If the model is not initialized, an empty record will be     returned.      \sa QSqlRecord::isEmpty() */
end_comment
begin_function
DECL|function|record
name|QSqlRecord
name|QSqlQueryModel
operator|::
name|record
parameter_list|(
name|int
name|row
parameter_list|)
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QSqlQueryModel
argument_list|)
expr_stmt|;
if|if
condition|(
name|row
operator|<
literal|0
condition|)
return|return
name|d
operator|->
name|rec
return|;
name|QSqlRecord
name|rec
init|=
name|d
operator|->
name|rec
decl_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|rec
operator|.
name|count
argument_list|()
condition|;
operator|++
name|i
control|)
name|rec
operator|.
name|setValue
argument_list|(
name|i
argument_list|,
name|data
argument_list|(
name|createIndex
argument_list|(
name|row
argument_list|,
name|i
argument_list|)
argument_list|,
name|Qt
operator|::
name|EditRole
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|rec
return|;
block|}
end_function
begin_comment
comment|/*! \overload      Returns an empty record containing information about the fields     of the current query.      If the model is not initialized, an empty record will be     returned.      \sa QSqlRecord::isEmpty()  */
end_comment
begin_function
DECL|function|record
name|QSqlRecord
name|QSqlQueryModel
operator|::
name|record
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QSqlQueryModel
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|rec
return|;
block|}
end_function
begin_comment
comment|/*!     Inserts \a count columns into the model at position \a column. The     \a parent parameter must always be an invalid QModelIndex, since     the model does not support parent-child relationships.      Returns \c true if \a column is within bounds; otherwise returns \c false.      By default, inserted columns are empty. To fill them with data,     reimplement data() and handle any inserted column separately:      \snippet sqldatabase/sqldatabase.cpp 23      \sa removeColumns() */
end_comment
begin_function
DECL|function|insertColumns
name|bool
name|QSqlQueryModel
operator|::
name|insertColumns
parameter_list|(
name|int
name|column
parameter_list|,
name|int
name|count
parameter_list|,
specifier|const
name|QModelIndex
modifier|&
name|parent
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QSqlQueryModel
argument_list|)
expr_stmt|;
if|if
condition|(
name|count
operator|<=
literal|0
operator|||
name|parent
operator|.
name|isValid
argument_list|()
operator|||
name|column
argument_list|<
literal|0
operator|||
name|column
argument_list|>
name|d
operator|->
name|rec
operator|.
name|count
argument_list|()
condition|)
return|return
literal|false
return|;
name|beginInsertColumns
argument_list|(
name|parent
argument_list|,
name|column
argument_list|,
name|column
operator|+
name|count
operator|-
literal|1
argument_list|)
expr_stmt|;
for|for
control|(
name|int
name|c
init|=
literal|0
init|;
name|c
operator|<
name|count
condition|;
operator|++
name|c
control|)
block|{
name|QSqlField
name|field
decl_stmt|;
name|field
operator|.
name|setReadOnly
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|field
operator|.
name|setGenerated
argument_list|(
literal|false
argument_list|)
expr_stmt|;
name|d
operator|->
name|rec
operator|.
name|insert
argument_list|(
name|column
argument_list|,
name|field
argument_list|)
expr_stmt|;
if|if
condition|(
name|d
operator|->
name|colOffsets
operator|.
name|size
argument_list|()
operator|<
name|d
operator|->
name|rec
operator|.
name|count
argument_list|()
condition|)
block|{
name|int
name|nVal
init|=
name|d
operator|->
name|colOffsets
operator|.
name|isEmpty
argument_list|()
condition|?
literal|0
else|:
name|d
operator|->
name|colOffsets
index|[
name|d
operator|->
name|colOffsets
operator|.
name|size
argument_list|()
operator|-
literal|1
index|]
decl_stmt|;
name|d
operator|->
name|colOffsets
operator|.
name|append
argument_list|(
name|nVal
argument_list|)
expr_stmt|;
name|Q_ASSERT
argument_list|(
name|d
operator|->
name|colOffsets
operator|.
name|size
argument_list|()
operator|>=
name|d
operator|->
name|rec
operator|.
name|count
argument_list|()
argument_list|)
expr_stmt|;
block|}
for|for
control|(
name|int
name|i
init|=
name|column
operator|+
literal|1
init|;
name|i
operator|<
name|d
operator|->
name|colOffsets
operator|.
name|count
argument_list|()
condition|;
operator|++
name|i
control|)
operator|++
name|d
operator|->
name|colOffsets
index|[
name|i
index|]
expr_stmt|;
block|}
name|endInsertColumns
argument_list|()
expr_stmt|;
return|return
literal|true
return|;
block|}
end_function
begin_comment
comment|/*!     Removes \a count columns from the model starting from position \a     column. The \a parent parameter must always be an invalid     QModelIndex, since the model does not support parent-child     relationships.      Removing columns effectively hides them. It does not affect the     underlying QSqlQuery.      Returns \c true if the columns were removed; otherwise returns \c false.  */
end_comment
begin_function
DECL|function|removeColumns
name|bool
name|QSqlQueryModel
operator|::
name|removeColumns
parameter_list|(
name|int
name|column
parameter_list|,
name|int
name|count
parameter_list|,
specifier|const
name|QModelIndex
modifier|&
name|parent
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QSqlQueryModel
argument_list|)
expr_stmt|;
if|if
condition|(
name|count
operator|<=
literal|0
operator|||
name|parent
operator|.
name|isValid
argument_list|()
operator|||
name|column
operator|<
literal|0
operator|||
name|column
operator|>=
name|d
operator|->
name|rec
operator|.
name|count
argument_list|()
condition|)
return|return
literal|false
return|;
name|beginRemoveColumns
argument_list|(
name|parent
argument_list|,
name|column
argument_list|,
name|column
operator|+
name|count
operator|-
literal|1
argument_list|)
expr_stmt|;
name|int
name|i
decl_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|count
condition|;
operator|++
name|i
control|)
name|d
operator|->
name|rec
operator|.
name|remove
argument_list|(
name|column
argument_list|)
expr_stmt|;
for|for
control|(
name|i
operator|=
name|column
init|;
name|i
operator|<
name|d
operator|->
name|colOffsets
operator|.
name|count
argument_list|()
condition|;
operator|++
name|i
control|)
name|d
operator|->
name|colOffsets
index|[
name|i
index|]
operator|-=
name|count
expr_stmt|;
name|endRemoveColumns
argument_list|()
expr_stmt|;
return|return
literal|true
return|;
block|}
end_function
begin_comment
comment|/*!     Returns the index of the value in the database result set for the     given \a item in the model.      The return value is identical to \a item if no columns or rows     have been inserted, removed, or moved around.      Returns an invalid model index if \a item is out of bounds or if     \a item does not point to a value in the result set.      \sa QSqlTableModel::indexInQuery(), insertColumns(), removeColumns() */
end_comment
begin_function
DECL|function|indexInQuery
name|QModelIndex
name|QSqlQueryModel
operator|::
name|indexInQuery
parameter_list|(
specifier|const
name|QModelIndex
modifier|&
name|item
parameter_list|)
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QSqlQueryModel
argument_list|)
expr_stmt|;
name|int
name|modelColumn
init|=
name|d
operator|->
name|columnInQuery
argument_list|(
name|item
operator|.
name|column
argument_list|()
argument_list|)
decl_stmt|;
if|if
condition|(
name|modelColumn
operator|<
literal|0
condition|)
return|return
name|QModelIndex
argument_list|()
return|;
return|return
name|createIndex
argument_list|(
name|item
operator|.
name|row
argument_list|()
argument_list|,
name|modelColumn
argument_list|,
name|item
operator|.
name|internalPointer
argument_list|()
argument_list|)
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
