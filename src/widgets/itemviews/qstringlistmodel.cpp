begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_comment
comment|/*     A simple model that uses a QStringList as its data source. */
end_comment
begin_include
include|#
directive|include
file|"qstringlistmodel.h"
end_include
begin_include
include|#
directive|include
file|<QtCore/qvector.h>
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_STRINGLISTMODEL
end_ifndef
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_comment
comment|/*!     \class QStringListModel     \brief The QStringListModel class provides a model that supplies strings to views.      \ingroup model-view     \inmodule QtWidgets      QStringListModel is an editable model that can be used for simple     cases where you need to display a number of strings in a view     widget, such as a QListView or a QComboBox.      The model provides all the standard functions of an editable     model, representing the data in the string list as a model with     one column and a number of rows equal to the number of items in     the list.      Model indexes corresponding to items are obtained with the     \l{QAbstractListModel::index()}{index()} function, and item flags     are obtained with flags().  Item data is read with the data()     function and written with setData().  The number of rows (and     number of items in the string list) can be found with the     rowCount() function.      The model can be constructed with an existing string list, or     strings can be set later with the setStringList() convenience     function. Strings can also be inserted in the usual way with the     insertRows() function, and removed with removeRows(). The contents     of the string list can be retrieved with the stringList()     convenience function.      An example usage of QStringListModel:      \snippet doc/src/snippets/qstringlistmodel/main.cpp 0      \sa QAbstractListModel, QAbstractItemModel, {Model Classes} */
end_comment
begin_comment
comment|/*!     Constructs a string list model with the given \a parent. */
end_comment
begin_constructor
DECL|function|QStringListModel
name|QStringListModel
operator|::
name|QStringListModel
parameter_list|(
name|QObject
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QAbstractListModel
argument_list|(
name|parent
argument_list|)
block|{ }
end_constructor
begin_comment
comment|/*!     Constructs a string list model containing the specified \a strings     with the given \a parent. */
end_comment
begin_constructor
DECL|function|QStringListModel
name|QStringListModel
operator|::
name|QStringListModel
parameter_list|(
specifier|const
name|QStringList
modifier|&
name|strings
parameter_list|,
name|QObject
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QAbstractListModel
argument_list|(
name|parent
argument_list|)
member_init_list|,
name|lst
argument_list|(
name|strings
argument_list|)
block|{ }
end_constructor
begin_comment
comment|/*!     Returns the number of rows in the model. This value corresponds to the     number of items in the model's internal string list.      The optional \a parent argument is in most models used to specify     the parent of the rows to be counted. Because this is a list if a     valid parent is specified, the result will always be 0.      \sa insertRows(), removeRows(), QAbstractItemModel::rowCount() */
end_comment
begin_function
DECL|function|rowCount
name|int
name|QStringListModel
operator|::
name|rowCount
parameter_list|(
specifier|const
name|QModelIndex
modifier|&
name|parent
parameter_list|)
specifier|const
block|{
if|if
condition|(
name|parent
operator|.
name|isValid
argument_list|()
condition|)
return|return
literal|0
return|;
return|return
name|lst
operator|.
name|count
argument_list|()
return|;
block|}
end_function
begin_comment
comment|/*!     Returns data for the specified \a role, from the item with the     given \a index.      If the view requests an invalid index, an invalid variant is returned.      \sa setData() */
end_comment
begin_function
DECL|function|data
name|QVariant
name|QStringListModel
operator|::
name|data
parameter_list|(
specifier|const
name|QModelIndex
modifier|&
name|index
parameter_list|,
name|int
name|role
parameter_list|)
specifier|const
block|{
if|if
condition|(
name|index
operator|.
name|row
argument_list|()
operator|<
literal|0
operator|||
name|index
operator|.
name|row
argument_list|()
operator|>=
name|lst
operator|.
name|size
argument_list|()
condition|)
return|return
name|QVariant
argument_list|()
return|;
if|if
condition|(
name|role
operator|==
name|Qt
operator|::
name|DisplayRole
operator|||
name|role
operator|==
name|Qt
operator|::
name|EditRole
condition|)
return|return
name|lst
operator|.
name|at
argument_list|(
name|index
operator|.
name|row
argument_list|()
argument_list|)
return|;
return|return
name|QVariant
argument_list|()
return|;
block|}
end_function
begin_comment
comment|/*!     Returns the flags for the item with the given \a index.      Valid items are enabled, selectable, editable, drag enabled and drop enabled.      \sa QAbstractItemModel::flags() */
end_comment
begin_function
DECL|function|flags
name|Qt
operator|::
name|ItemFlags
name|QStringListModel
operator|::
name|flags
parameter_list|(
specifier|const
name|QModelIndex
modifier|&
name|index
parameter_list|)
specifier|const
block|{
if|if
condition|(
operator|!
name|index
operator|.
name|isValid
argument_list|()
condition|)
return|return
name|QAbstractItemModel
operator|::
name|flags
argument_list|(
name|index
argument_list|)
operator||
name|Qt
operator|::
name|ItemIsDropEnabled
return|;
return|return
name|QAbstractItemModel
operator|::
name|flags
argument_list|(
name|index
argument_list|)
operator||
name|Qt
operator|::
name|ItemIsEditable
operator||
name|Qt
operator|::
name|ItemIsDragEnabled
operator||
name|Qt
operator|::
name|ItemIsDropEnabled
return|;
block|}
end_function
begin_comment
comment|/*!     Sets the data for the specified \a role in the item with the given     \a index in the model, to the provided \a value.      The dataChanged() signal is emitted if the item is changed.      \sa Qt::ItemDataRole, data() */
end_comment
begin_function
DECL|function|setData
name|bool
name|QStringListModel
operator|::
name|setData
parameter_list|(
specifier|const
name|QModelIndex
modifier|&
name|index
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
if|if
condition|(
name|index
operator|.
name|row
argument_list|()
operator|>=
literal|0
operator|&&
name|index
operator|.
name|row
argument_list|()
operator|<
name|lst
operator|.
name|size
argument_list|()
operator|&&
operator|(
name|role
operator|==
name|Qt
operator|::
name|EditRole
operator|||
name|role
operator|==
name|Qt
operator|::
name|DisplayRole
operator|)
condition|)
block|{
name|lst
operator|.
name|replace
argument_list|(
name|index
operator|.
name|row
argument_list|()
argument_list|,
name|value
operator|.
name|toString
argument_list|()
argument_list|)
expr_stmt|;
emit|emit
name|dataChanged
argument_list|(
name|index
argument_list|,
name|index
argument_list|)
emit|;
return|return
literal|true
return|;
block|}
return|return
literal|false
return|;
block|}
end_function
begin_comment
comment|/*!     Inserts \a count rows into the model, beginning at the given \a row.      The \a parent index of the rows is optional and is only used for     consistency with QAbstractItemModel. By default, a null index is     specified, indicating that the rows are inserted in the top level of     the model.      \sa QAbstractItemModel::insertRows() */
end_comment
begin_function
DECL|function|insertRows
name|bool
name|QStringListModel
operator|::
name|insertRows
parameter_list|(
name|int
name|row
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
if|if
condition|(
name|count
operator|<
literal|1
operator|||
name|row
argument_list|<
literal|0
operator|||
name|row
argument_list|>
name|rowCount
argument_list|(
name|parent
argument_list|)
condition|)
return|return
literal|false
return|;
name|beginInsertRows
argument_list|(
name|QModelIndex
argument_list|()
argument_list|,
name|row
argument_list|,
name|row
operator|+
name|count
operator|-
literal|1
argument_list|)
expr_stmt|;
for|for
control|(
name|int
name|r
init|=
literal|0
init|;
name|r
operator|<
name|count
condition|;
operator|++
name|r
control|)
name|lst
operator|.
name|insert
argument_list|(
name|row
argument_list|,
name|QString
argument_list|()
argument_list|)
expr_stmt|;
name|endInsertRows
argument_list|()
expr_stmt|;
return|return
literal|true
return|;
block|}
end_function
begin_comment
comment|/*!     Removes \a count rows from the model, beginning at the given \a row.      The \a parent index of the rows is optional and is only used for     consistency with QAbstractItemModel. By default, a null index is     specified, indicating that the rows are removed in the top level of     the model.      \sa QAbstractItemModel::removeRows() */
end_comment
begin_function
DECL|function|removeRows
name|bool
name|QStringListModel
operator|::
name|removeRows
parameter_list|(
name|int
name|row
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
if|if
condition|(
name|count
operator|<=
literal|0
operator|||
name|row
argument_list|<
literal|0
operator|||
operator|(
name|row
operator|+
name|count
operator|)
argument_list|>
name|rowCount
argument_list|(
name|parent
argument_list|)
condition|)
return|return
literal|false
return|;
name|beginRemoveRows
argument_list|(
name|QModelIndex
argument_list|()
argument_list|,
name|row
argument_list|,
name|row
operator|+
name|count
operator|-
literal|1
argument_list|)
expr_stmt|;
for|for
control|(
name|int
name|r
init|=
literal|0
init|;
name|r
operator|<
name|count
condition|;
operator|++
name|r
control|)
name|lst
operator|.
name|removeAt
argument_list|(
name|row
argument_list|)
expr_stmt|;
name|endRemoveRows
argument_list|()
expr_stmt|;
return|return
literal|true
return|;
block|}
end_function
begin_function
DECL|function|ascendingLessThan
specifier|static
name|bool
name|ascendingLessThan
parameter_list|(
specifier|const
name|QPair
argument_list|<
name|QString
argument_list|,
name|int
argument_list|>
modifier|&
name|s1
parameter_list|,
specifier|const
name|QPair
argument_list|<
name|QString
argument_list|,
name|int
argument_list|>
modifier|&
name|s2
parameter_list|)
block|{
return|return
name|s1
operator|.
name|first
operator|<
name|s2
operator|.
name|first
return|;
block|}
end_function
begin_function
DECL|function|decendingLessThan
specifier|static
name|bool
name|decendingLessThan
parameter_list|(
specifier|const
name|QPair
argument_list|<
name|QString
argument_list|,
name|int
argument_list|>
modifier|&
name|s1
parameter_list|,
specifier|const
name|QPair
argument_list|<
name|QString
argument_list|,
name|int
argument_list|>
modifier|&
name|s2
parameter_list|)
block|{
return|return
name|s1
operator|.
name|first
operator|>
name|s2
operator|.
name|first
return|;
block|}
end_function
begin_comment
comment|/*!   \reimp */
end_comment
begin_function
DECL|function|sort
name|void
name|QStringListModel
operator|::
name|sort
parameter_list|(
name|int
parameter_list|,
name|Qt
operator|::
name|SortOrder
name|order
parameter_list|)
block|{
emit|emit
name|layoutAboutToBeChanged
argument_list|()
emit|;
name|QList
argument_list|<
name|QPair
argument_list|<
name|QString
argument_list|,
name|int
argument_list|>
argument_list|>
name|list
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
name|lst
operator|.
name|count
argument_list|()
condition|;
operator|++
name|i
control|)
name|list
operator|.
name|append
argument_list|(
name|QPair
argument_list|<
name|QString
argument_list|,
name|int
argument_list|>
argument_list|(
name|lst
operator|.
name|at
argument_list|(
name|i
argument_list|)
argument_list|,
name|i
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|order
operator|==
name|Qt
operator|::
name|AscendingOrder
condition|)
name|qSort
argument_list|(
name|list
operator|.
name|begin
argument_list|()
argument_list|,
name|list
operator|.
name|end
argument_list|()
argument_list|,
name|ascendingLessThan
argument_list|)
expr_stmt|;
else|else
name|qSort
argument_list|(
name|list
operator|.
name|begin
argument_list|()
argument_list|,
name|list
operator|.
name|end
argument_list|()
argument_list|,
name|decendingLessThan
argument_list|)
expr_stmt|;
name|lst
operator|.
name|clear
argument_list|()
expr_stmt|;
name|QVector
argument_list|<
name|int
argument_list|>
name|forwarding
argument_list|(
name|list
operator|.
name|count
argument_list|()
argument_list|)
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
name|list
operator|.
name|count
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
name|lst
operator|.
name|append
argument_list|(
name|list
operator|.
name|at
argument_list|(
name|i
argument_list|)
operator|.
name|first
argument_list|)
expr_stmt|;
name|forwarding
index|[
name|list
operator|.
name|at
argument_list|(
name|i
argument_list|)
operator|.
name|second
index|]
operator|=
name|i
expr_stmt|;
block|}
name|QModelIndexList
name|oldList
init|=
name|persistentIndexList
argument_list|()
decl_stmt|;
name|QModelIndexList
name|newList
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
name|oldList
operator|.
name|count
argument_list|()
condition|;
operator|++
name|i
control|)
name|newList
operator|.
name|append
argument_list|(
name|index
argument_list|(
name|forwarding
operator|.
name|at
argument_list|(
name|oldList
operator|.
name|at
argument_list|(
name|i
argument_list|)
operator|.
name|row
argument_list|()
argument_list|)
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
name|changePersistentIndexList
argument_list|(
name|oldList
argument_list|,
name|newList
argument_list|)
expr_stmt|;
emit|emit
name|layoutChanged
argument_list|()
emit|;
block|}
end_function
begin_comment
comment|/*!     Returns the string list used by the model to store data. */
end_comment
begin_function
DECL|function|stringList
name|QStringList
name|QStringListModel
operator|::
name|stringList
parameter_list|()
specifier|const
block|{
return|return
name|lst
return|;
block|}
end_function
begin_comment
comment|/*!     Sets the model's internal string list to \a strings. The model will     notify any attached views that its underlying data has changed.      \sa dataChanged() */
end_comment
begin_function
DECL|function|setStringList
name|void
name|QStringListModel
operator|::
name|setStringList
parameter_list|(
specifier|const
name|QStringList
modifier|&
name|strings
parameter_list|)
block|{
emit|emit
name|beginResetModel
argument_list|()
emit|;
name|lst
operator|=
name|strings
expr_stmt|;
emit|emit
name|endResetModel
argument_list|()
emit|;
block|}
end_function
begin_comment
comment|/*!   \reimp */
end_comment
begin_function
DECL|function|supportedDropActions
name|Qt
operator|::
name|DropActions
name|QStringListModel
operator|::
name|supportedDropActions
parameter_list|()
specifier|const
block|{
return|return
name|QAbstractItemModel
operator|::
name|supportedDropActions
argument_list|()
operator||
name|Qt
operator|::
name|MoveAction
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_STRINGLISTMODEL
end_comment
end_unit
