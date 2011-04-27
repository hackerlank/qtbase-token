begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtSql module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** No Commercial Usage ** This file contains pre-release code and may not be distributed. ** You may use this file in accordance with the terms and conditions ** contained in the Technology Preview License Agreement accompanying ** this package. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights.  These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** If you have questions regarding the use of this file, please contact ** Nokia at qt-info@nokia.com. ** ** ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qsqlindex.h"
end_include
begin_include
include|#
directive|include
file|"qsqlfield.h"
end_include
begin_include
include|#
directive|include
file|"qstringlist.h"
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_comment
comment|/*!     \class QSqlIndex     \brief The QSqlIndex class provides functions to manipulate and     describe database indexes.      \ingroup database     \inmodule QtSql      An \e index refers to a single table or view in a database.     Information about the fields that comprise the index can be used     to generate SQL statements. */
end_comment
begin_comment
comment|/*!     Constructs an empty index using the cursor name \a cursorname and     index name \a name. */
end_comment
begin_constructor
DECL|function|QSqlIndex
name|QSqlIndex
operator|::
name|QSqlIndex
parameter_list|(
specifier|const
name|QString
modifier|&
name|cursorname
parameter_list|,
specifier|const
name|QString
modifier|&
name|name
parameter_list|)
member_init_list|:
name|cursor
argument_list|(
name|cursorname
argument_list|)
member_init_list|,
name|nm
argument_list|(
name|name
argument_list|)
block|{ }
end_constructor
begin_comment
comment|/*!     Constructs a copy of \a other. */
end_comment
begin_constructor
DECL|function|QSqlIndex
name|QSqlIndex
operator|::
name|QSqlIndex
parameter_list|(
specifier|const
name|QSqlIndex
modifier|&
name|other
parameter_list|)
member_init_list|:
name|QSqlRecord
argument_list|(
name|other
argument_list|)
member_init_list|,
name|cursor
argument_list|(
name|other
operator|.
name|cursor
argument_list|)
member_init_list|,
name|nm
argument_list|(
name|other
operator|.
name|nm
argument_list|)
member_init_list|,
name|sorts
argument_list|(
name|other
operator|.
name|sorts
argument_list|)
block|{ }
end_constructor
begin_comment
comment|/*!     Sets the index equal to \a other. */
end_comment
begin_function
DECL|function|operator =
name|QSqlIndex
modifier|&
name|QSqlIndex
operator|::
name|operator
name|=
parameter_list|(
specifier|const
name|QSqlIndex
modifier|&
name|other
parameter_list|)
block|{
name|cursor
operator|=
name|other
operator|.
name|cursor
expr_stmt|;
name|nm
operator|=
name|other
operator|.
name|nm
expr_stmt|;
name|sorts
operator|=
name|other
operator|.
name|sorts
expr_stmt|;
name|QSqlRecord
operator|::
name|operator
name|=
parameter_list|(
name|other
parameter_list|)
function_decl|;
return|return
operator|*
name|this
return|;
block|}
end_function
begin_comment
comment|/*!     Destroys the object and frees any allocated resources. */
end_comment
begin_destructor
DECL|function|~QSqlIndex
name|QSqlIndex
operator|::
name|~
name|QSqlIndex
parameter_list|()
block|{  }
end_destructor
begin_comment
comment|/*!     Sets the name of the index to \a name. */
end_comment
begin_function
DECL|function|setName
name|void
name|QSqlIndex
operator|::
name|setName
parameter_list|(
specifier|const
name|QString
modifier|&
name|name
parameter_list|)
block|{
name|nm
operator|=
name|name
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     \fn QString QSqlIndex::name() const      Returns the name of the index. */
end_comment
begin_comment
comment|/*!     Appends the field \a field to the list of indexed fields. The     field is appended with an ascending sort order. */
end_comment
begin_function
DECL|function|append
name|void
name|QSqlIndex
operator|::
name|append
parameter_list|(
specifier|const
name|QSqlField
modifier|&
name|field
parameter_list|)
block|{
name|append
argument_list|(
name|field
argument_list|,
literal|false
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     \overload      Appends the field \a field to the list of indexed fields. The     field is appended with an ascending sort order, unless \a desc is     true. */
end_comment
begin_function
DECL|function|append
name|void
name|QSqlIndex
operator|::
name|append
parameter_list|(
specifier|const
name|QSqlField
modifier|&
name|field
parameter_list|,
name|bool
name|desc
parameter_list|)
block|{
name|sorts
operator|.
name|append
argument_list|(
name|desc
argument_list|)
expr_stmt|;
name|QSqlRecord
operator|::
name|append
argument_list|(
name|field
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     Returns true if field \a i in the index is sorted in descending     order; otherwise returns false. */
end_comment
begin_function
DECL|function|isDescending
name|bool
name|QSqlIndex
operator|::
name|isDescending
parameter_list|(
name|int
name|i
parameter_list|)
specifier|const
block|{
if|if
condition|(
name|i
operator|>=
literal|0
operator|&&
name|i
operator|<
name|sorts
operator|.
name|size
argument_list|()
condition|)
return|return
name|sorts
index|[
name|i
index|]
return|;
return|return
literal|false
return|;
block|}
end_function
begin_comment
comment|/*!     If \a desc is true, field \a i is sorted in descending order.     Otherwise, field \a i is sorted in ascending order (the default).     If the field does not exist, nothing happens. */
end_comment
begin_function
DECL|function|setDescending
name|void
name|QSqlIndex
operator|::
name|setDescending
parameter_list|(
name|int
name|i
parameter_list|,
name|bool
name|desc
parameter_list|)
block|{
if|if
condition|(
name|i
operator|>=
literal|0
operator|&&
name|i
operator|<
name|sorts
operator|.
name|size
argument_list|()
condition|)
name|sorts
index|[
name|i
index|]
operator|=
name|desc
expr_stmt|;
block|}
end_function
begin_ifdef
ifdef|#
directive|ifdef
name|QT3_SUPPORT
end_ifdef
begin_comment
comment|/*!     Returns a comma-separated list of all the index's field names as a     string. This string is suitable, for example, for generating a     SQL SELECT statement. Only generated fields are included in the     list (see \l{isGenerated()}). If a \a prefix is specified, e.g. a     table name, it is prepended before all field names in the form:      "\a{prefix}.<fieldname>"      If \a sep is specified, each field is separated by \a sep. If \a     verbose is true (the default), each field contains a suffix     indicating an ASCending or DESCending sort order. */
end_comment
begin_function
DECL|function|toString
name|QString
name|QSqlIndex
operator|::
name|toString
parameter_list|(
specifier|const
name|QString
modifier|&
name|prefix
parameter_list|,
specifier|const
name|QString
modifier|&
name|sep
parameter_list|,
name|bool
name|verbose
parameter_list|)
specifier|const
block|{
name|QString
name|s
decl_stmt|;
name|bool
name|comma
init|=
literal|false
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
name|count
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
if|if
condition|(
name|comma
condition|)
name|s
operator|+=
name|sep
operator|+
name|QLatin1Char
argument_list|(
literal|' '
argument_list|)
expr_stmt|;
name|s
operator|+=
name|createField
argument_list|(
name|i
argument_list|,
name|prefix
argument_list|,
name|verbose
argument_list|)
expr_stmt|;
name|comma
operator|=
literal|true
expr_stmt|;
block|}
return|return
name|s
return|;
block|}
end_function
begin_comment
comment|/*!     Returns a list of all the index's field names. Only generated     fields are included in the list (see \l{isGenerated()}). If a \a     prefix is specified, e.g. a table name, all fields are prefixed in     the form:      "\a{prefix}.<fieldname>"      If \a verbose is true (the default), each field contains a suffix     indicating an ASCending or DESCending sort order.      Note that if you want to iterate over the list, you should iterate     over a copy, e.g.     \snippet doc/src/snippets/code/src_sql_kernel_qsqlindex.cpp 0  */
end_comment
begin_function
DECL|function|toStringList
name|QStringList
name|QSqlIndex
operator|::
name|toStringList
parameter_list|(
specifier|const
name|QString
modifier|&
name|prefix
parameter_list|,
name|bool
name|verbose
parameter_list|)
specifier|const
block|{
name|QStringList
name|s
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
name|count
argument_list|()
condition|;
operator|++
name|i
control|)
name|s
operator|+=
name|createField
argument_list|(
name|i
argument_list|,
name|prefix
argument_list|,
name|verbose
argument_list|)
expr_stmt|;
return|return
name|s
return|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/*! \internal    Creates a string representing the field number \a i using prefix \a   prefix. If \a verbose is true, ASC or DESC is included in the field   description if the field is sorted in ASCending or DESCending order. */
end_comment
begin_function
DECL|function|createField
name|QString
name|QSqlIndex
operator|::
name|createField
parameter_list|(
name|int
name|i
parameter_list|,
specifier|const
name|QString
modifier|&
name|prefix
parameter_list|,
name|bool
name|verbose
parameter_list|)
specifier|const
block|{
name|QString
name|f
decl_stmt|;
if|if
condition|(
operator|!
name|prefix
operator|.
name|isEmpty
argument_list|()
condition|)
name|f
operator|+=
name|prefix
operator|+
name|QLatin1Char
argument_list|(
literal|'.'
argument_list|)
expr_stmt|;
name|f
operator|+=
name|field
argument_list|(
name|i
argument_list|)
operator|.
name|name
argument_list|()
expr_stmt|;
if|if
condition|(
name|verbose
condition|)
name|f
operator|+=
name|QLatin1Char
argument_list|(
literal|' '
argument_list|)
operator|+
name|QString
argument_list|(
operator|(
name|isDescending
argument_list|(
name|i
argument_list|)
condition|?
name|QLatin1String
argument_list|(
literal|"DESC"
argument_list|)
else|:
name|QLatin1String
argument_list|(
literal|"ASC"
argument_list|)
operator|)
argument_list|)
expr_stmt|;
return|return
name|f
return|;
block|}
end_function
begin_comment
comment|/*!     \fn QString QSqlIndex::cursorName() const      Returns the name of the cursor which the index is associated with. */
end_comment
begin_comment
comment|/*!     Sets the name of the cursor that the index is associated with to     \a cursorName. */
end_comment
begin_function
DECL|function|setCursorName
name|void
name|QSqlIndex
operator|::
name|setCursorName
parameter_list|(
specifier|const
name|QString
modifier|&
name|cursorName
parameter_list|)
block|{
name|cursor
operator|=
name|cursorName
expr_stmt|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
