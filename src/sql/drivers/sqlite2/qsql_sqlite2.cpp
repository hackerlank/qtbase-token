begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtSql module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qsql_sqlite2.h"
end_include
begin_include
include|#
directive|include
file|<qcoreapplication.h>
end_include
begin_include
include|#
directive|include
file|<qvariant.h>
end_include
begin_include
include|#
directive|include
file|<qdatetime.h>
end_include
begin_include
include|#
directive|include
file|<qfile.h>
end_include
begin_include
include|#
directive|include
file|<qregexp.h>
end_include
begin_include
include|#
directive|include
file|<qsqlerror.h>
end_include
begin_include
include|#
directive|include
file|<qsqlfield.h>
end_include
begin_include
include|#
directive|include
file|<qsqlindex.h>
end_include
begin_include
include|#
directive|include
file|<qsqlquery.h>
end_include
begin_include
include|#
directive|include
file|<qstringlist.h>
end_include
begin_include
include|#
directive|include
file|<qvector.h>
end_include
begin_if
if|#
directive|if
operator|!
name|defined
name|Q_OS_WIN
end_if
begin_include
include|#
directive|include
file|<unistd.h>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_include
include|#
directive|include
file|<sqlite.h>
end_include
begin_typedef
DECL|typedef|sqlite_vm
typedef|typedef
name|struct
name|sqlite_vm
name|sqlite_vm
typedef|;
end_typedef
begin_macro
name|Q_DECLARE_OPAQUE_POINTER
argument_list|(
argument|sqlite_vm*
argument_list|)
end_macro
begin_macro
name|Q_DECLARE_METATYPE
argument_list|(
argument|sqlite_vm*
argument_list|)
end_macro
begin_macro
name|Q_DECLARE_OPAQUE_POINTER
argument_list|(
argument|sqlite*
argument_list|)
end_macro
begin_macro
name|Q_DECLARE_METATYPE
argument_list|(
argument|sqlite*
argument_list|)
end_macro
begin_function
name|QT_BEGIN_NAMESPACE
DECL|function|nameToType
specifier|static
name|QVariant
operator|::
name|Type
name|nameToType
parameter_list|(
specifier|const
name|QString
modifier|&
name|typeName
parameter_list|)
block|{
name|QString
name|tName
init|=
name|typeName
operator|.
name|toUpper
argument_list|()
decl_stmt|;
if|if
condition|(
name|tName
operator|.
name|startsWith
argument_list|(
name|QLatin1String
argument_list|(
literal|"INT"
argument_list|)
argument_list|)
condition|)
return|return
name|QVariant
operator|::
name|Int
return|;
if|if
condition|(
name|tName
operator|.
name|startsWith
argument_list|(
name|QLatin1String
argument_list|(
literal|"FLOAT"
argument_list|)
argument_list|)
operator|||
name|tName
operator|.
name|startsWith
argument_list|(
name|QLatin1String
argument_list|(
literal|"NUMERIC"
argument_list|)
argument_list|)
condition|)
return|return
name|QVariant
operator|::
name|Double
return|;
if|if
condition|(
name|tName
operator|.
name|startsWith
argument_list|(
name|QLatin1String
argument_list|(
literal|"BOOL"
argument_list|)
argument_list|)
condition|)
return|return
name|QVariant
operator|::
name|Bool
return|;
comment|// SQLite is typeless - consider everything else as string
return|return
name|QVariant
operator|::
name|String
return|;
block|}
end_function
begin_class
DECL|class|QSQLite2DriverPrivate
class|class
name|QSQLite2DriverPrivate
block|{
public|public:
name|QSQLite2DriverPrivate
parameter_list|()
constructor_decl|;
DECL|member|access
name|sqlite
modifier|*
name|access
decl_stmt|;
DECL|member|utf8
name|bool
name|utf8
decl_stmt|;
block|}
class|;
end_class
begin_constructor
DECL|function|QSQLite2DriverPrivate
name|QSQLite2DriverPrivate
operator|::
name|QSQLite2DriverPrivate
parameter_list|()
member_init_list|:
name|access
argument_list|(
literal|0
argument_list|)
block|{
name|utf8
operator|=
operator|(
name|qstrcmp
argument_list|(
name|sqlite_encoding
argument_list|,
literal|"UTF-8"
argument_list|)
operator|==
literal|0
operator|)
expr_stmt|;
block|}
end_constructor
begin_class
DECL|class|QSQLite2ResultPrivate
class|class
name|QSQLite2ResultPrivate
block|{
public|public:
name|QSQLite2ResultPrivate
parameter_list|(
name|QSQLite2Result
modifier|*
name|res
parameter_list|)
constructor_decl|;
name|void
name|cleanup
parameter_list|()
function_decl|;
name|bool
name|fetchNext
parameter_list|(
name|QSqlCachedResult
operator|::
name|ValueCache
modifier|&
name|values
parameter_list|,
name|int
name|idx
parameter_list|,
name|bool
name|initialFetch
parameter_list|)
function_decl|;
name|bool
name|isSelect
parameter_list|()
function_decl|;
comment|// initializes the recordInfo and the cache
name|void
name|init
parameter_list|(
specifier|const
name|char
modifier|*
modifier|*
name|cnames
parameter_list|,
name|int
name|numCols
parameter_list|)
function_decl|;
name|void
name|finalize
parameter_list|()
function_decl|;
DECL|member|q
name|QSQLite2Result
modifier|*
name|q
decl_stmt|;
DECL|member|access
name|sqlite
modifier|*
name|access
decl_stmt|;
comment|// and we have too keep our own struct for the data (sqlite works via
comment|// callback.
DECL|member|currentTail
specifier|const
name|char
modifier|*
name|currentTail
decl_stmt|;
DECL|member|currentMachine
name|sqlite_vm
modifier|*
name|currentMachine
decl_stmt|;
DECL|member|skippedStatus
name|bool
name|skippedStatus
decl_stmt|;
comment|// the status of the fetchNext() that's skipped
DECL|member|skipRow
name|bool
name|skipRow
decl_stmt|;
comment|// skip the next fetchNext()?
DECL|member|utf8
name|bool
name|utf8
decl_stmt|;
DECL|member|rInf
name|QSqlRecord
name|rInf
decl_stmt|;
DECL|member|firstRow
name|QVector
argument_list|<
name|QVariant
argument_list|>
name|firstRow
decl_stmt|;
block|}
class|;
end_class
begin_decl_stmt
DECL|variable|initial_cache_size
specifier|static
specifier|const
name|uint
name|initial_cache_size
init|=
literal|128
decl_stmt|;
end_decl_stmt
begin_constructor
DECL|function|QSQLite2ResultPrivate
name|QSQLite2ResultPrivate
operator|::
name|QSQLite2ResultPrivate
parameter_list|(
name|QSQLite2Result
modifier|*
name|res
parameter_list|)
member_init_list|:
name|q
argument_list|(
name|res
argument_list|)
member_init_list|,
name|access
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|currentTail
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|currentMachine
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|skippedStatus
argument_list|(
literal|false
argument_list|)
member_init_list|,
name|skipRow
argument_list|(
literal|false
argument_list|)
member_init_list|,
name|utf8
argument_list|(
literal|false
argument_list|)
block|{ }
end_constructor
begin_function
DECL|function|cleanup
name|void
name|QSQLite2ResultPrivate
operator|::
name|cleanup
parameter_list|()
block|{
name|finalize
argument_list|()
expr_stmt|;
name|rInf
operator|.
name|clear
argument_list|()
expr_stmt|;
name|currentTail
operator|=
literal|0
expr_stmt|;
name|currentMachine
operator|=
literal|0
expr_stmt|;
name|skippedStatus
operator|=
literal|false
expr_stmt|;
name|skipRow
operator|=
literal|false
expr_stmt|;
name|q
operator|->
name|setAt
argument_list|(
name|QSql
operator|::
name|BeforeFirstRow
argument_list|)
expr_stmt|;
name|q
operator|->
name|setActive
argument_list|(
literal|false
argument_list|)
expr_stmt|;
name|q
operator|->
name|cleanup
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|finalize
name|void
name|QSQLite2ResultPrivate
operator|::
name|finalize
parameter_list|()
block|{
if|if
condition|(
operator|!
name|currentMachine
condition|)
return|return;
name|char
modifier|*
name|err
init|=
literal|0
decl_stmt|;
name|int
name|res
init|=
name|sqlite_finalize
argument_list|(
name|currentMachine
argument_list|,
operator|&
name|err
argument_list|)
decl_stmt|;
if|if
condition|(
name|err
condition|)
block|{
name|q
operator|->
name|setLastError
argument_list|(
name|QSqlError
argument_list|(
name|QCoreApplication
operator|::
name|translate
argument_list|(
literal|"QSQLite2Result"
argument_list|,
literal|"Unable to fetch results"
argument_list|)
argument_list|,
name|QString
operator|::
name|fromLatin1
argument_list|(
name|err
argument_list|)
argument_list|,
name|QSqlError
operator|::
name|StatementError
argument_list|,
name|res
argument_list|)
argument_list|)
expr_stmt|;
name|sqlite_freemem
argument_list|(
name|err
argument_list|)
expr_stmt|;
block|}
name|currentMachine
operator|=
literal|0
expr_stmt|;
block|}
end_function
begin_comment
comment|// called on first fetch
end_comment
begin_function
DECL|function|init
name|void
name|QSQLite2ResultPrivate
operator|::
name|init
parameter_list|(
specifier|const
name|char
modifier|*
modifier|*
name|cnames
parameter_list|,
name|int
name|numCols
parameter_list|)
block|{
if|if
condition|(
operator|!
name|cnames
condition|)
return|return;
name|rInf
operator|.
name|clear
argument_list|()
expr_stmt|;
if|if
condition|(
name|numCols
operator|<=
literal|0
condition|)
return|return;
name|q
operator|->
name|init
argument_list|(
name|numCols
argument_list|)
expr_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|numCols
condition|;
operator|++
name|i
control|)
block|{
specifier|const
name|char
modifier|*
name|lastDot
init|=
name|strrchr
argument_list|(
name|cnames
index|[
name|i
index|]
argument_list|,
literal|'.'
argument_list|)
decl_stmt|;
specifier|const
name|char
modifier|*
name|fieldName
init|=
name|lastDot
condition|?
name|lastDot
operator|+
literal|1
else|:
name|cnames
index|[
name|i
index|]
decl_stmt|;
comment|//remove quotations around the field name if any
name|QString
name|fieldStr
init|=
name|QString
operator|::
name|fromLatin1
argument_list|(
name|fieldName
argument_list|)
decl_stmt|;
name|QLatin1Char
name|quote
argument_list|(
literal|'\"'
argument_list|)
decl_stmt|;
if|if
condition|(
name|fieldStr
operator|.
name|length
argument_list|()
operator|>
literal|2
operator|&&
name|fieldStr
operator|.
name|startsWith
argument_list|(
name|quote
argument_list|)
operator|&&
name|fieldStr
operator|.
name|endsWith
argument_list|(
name|quote
argument_list|)
condition|)
block|{
name|fieldStr
operator|=
name|fieldStr
operator|.
name|mid
argument_list|(
literal|1
argument_list|)
expr_stmt|;
name|fieldStr
operator|.
name|chop
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
name|rInf
operator|.
name|append
argument_list|(
name|QSqlField
argument_list|(
name|fieldStr
argument_list|,
name|nameToType
argument_list|(
name|QString
operator|::
name|fromLatin1
argument_list|(
name|cnames
index|[
name|i
operator|+
name|numCols
index|]
argument_list|)
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|fetchNext
name|bool
name|QSQLite2ResultPrivate
operator|::
name|fetchNext
parameter_list|(
name|QSqlCachedResult
operator|::
name|ValueCache
modifier|&
name|values
parameter_list|,
name|int
name|idx
parameter_list|,
name|bool
name|initialFetch
parameter_list|)
block|{
comment|// may be caching.
specifier|const
name|char
modifier|*
modifier|*
name|fvals
decl_stmt|;
specifier|const
name|char
modifier|*
modifier|*
name|cnames
decl_stmt|;
name|int
name|colNum
decl_stmt|;
name|int
name|res
decl_stmt|;
name|int
name|i
decl_stmt|;
if|if
condition|(
name|skipRow
condition|)
block|{
comment|// already fetched
name|Q_ASSERT
argument_list|(
operator|!
name|initialFetch
argument_list|)
expr_stmt|;
name|skipRow
operator|=
literal|false
expr_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|firstRow
operator|.
name|count
argument_list|()
condition|;
name|i
operator|++
control|)
name|values
index|[
name|i
index|]
operator|=
name|firstRow
index|[
name|i
index|]
expr_stmt|;
return|return
name|skippedStatus
return|;
block|}
name|skipRow
operator|=
name|initialFetch
expr_stmt|;
if|if
condition|(
operator|!
name|currentMachine
condition|)
return|return
literal|false
return|;
comment|// keep trying while busy, wish I could implement this better.
while|while
condition|(
operator|(
name|res
operator|=
name|sqlite_step
argument_list|(
name|currentMachine
argument_list|,
operator|&
name|colNum
argument_list|,
operator|&
name|fvals
argument_list|,
operator|&
name|cnames
argument_list|)
operator|)
operator|==
name|SQLITE_BUSY
condition|)
block|{
comment|// sleep instead requesting result again immidiately.
if|#
directive|if
name|defined
name|Q_OS_WIN
name|Sleep
argument_list|(
literal|1000
argument_list|)
expr_stmt|;
else|#
directive|else
name|sleep
argument_list|(
literal|1
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
if|if
condition|(
name|initialFetch
condition|)
block|{
name|firstRow
operator|.
name|clear
argument_list|()
expr_stmt|;
name|firstRow
operator|.
name|resize
argument_list|(
name|colNum
argument_list|)
expr_stmt|;
block|}
switch|switch
condition|(
name|res
condition|)
block|{
case|case
name|SQLITE_ROW
case|:
comment|// check to see if should fill out columns
if|if
condition|(
name|rInf
operator|.
name|isEmpty
argument_list|()
condition|)
comment|// must be first call.
name|init
argument_list|(
name|cnames
argument_list|,
name|colNum
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|fvals
condition|)
return|return
literal|false
return|;
if|if
condition|(
name|idx
operator|<
literal|0
operator|&&
operator|!
name|initialFetch
condition|)
return|return
literal|true
return|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|colNum
condition|;
operator|++
name|i
control|)
name|values
index|[
name|i
operator|+
name|idx
index|]
operator|=
name|utf8
condition|?
name|QString
operator|::
name|fromUtf8
argument_list|(
name|fvals
index|[
name|i
index|]
argument_list|)
else|:
name|QString
operator|::
name|fromLatin1
argument_list|(
name|fvals
index|[
name|i
index|]
argument_list|)
expr_stmt|;
return|return
literal|true
return|;
case|case
name|SQLITE_DONE
case|:
if|if
condition|(
name|rInf
operator|.
name|isEmpty
argument_list|()
condition|)
comment|// must be first call.
name|init
argument_list|(
name|cnames
argument_list|,
name|colNum
argument_list|)
expr_stmt|;
name|q
operator|->
name|setAt
argument_list|(
name|QSql
operator|::
name|AfterLastRow
argument_list|)
expr_stmt|;
return|return
literal|false
return|;
case|case
name|SQLITE_ERROR
case|:
case|case
name|SQLITE_MISUSE
case|:
default|default:
comment|// something wrong, don't get col info, but still return false
name|finalize
argument_list|()
expr_stmt|;
comment|// finalize to get the error message.
name|q
operator|->
name|setAt
argument_list|(
name|QSql
operator|::
name|AfterLastRow
argument_list|)
expr_stmt|;
return|return
literal|false
return|;
block|}
return|return
literal|false
return|;
block|}
end_function
begin_constructor
DECL|function|QSQLite2Result
name|QSQLite2Result
operator|::
name|QSQLite2Result
parameter_list|(
specifier|const
name|QSQLite2Driver
modifier|*
name|db
parameter_list|)
member_init_list|:
name|QSqlCachedResult
argument_list|(
name|db
argument_list|)
block|{
name|d
operator|=
operator|new
name|QSQLite2ResultPrivate
argument_list|(
name|this
argument_list|)
expr_stmt|;
name|d
operator|->
name|access
operator|=
name|db
operator|->
name|d
operator|->
name|access
expr_stmt|;
name|d
operator|->
name|utf8
operator|=
name|db
operator|->
name|d
operator|->
name|utf8
expr_stmt|;
block|}
end_constructor
begin_destructor
DECL|function|~QSQLite2Result
name|QSQLite2Result
operator|::
name|~
name|QSQLite2Result
parameter_list|()
block|{
name|d
operator|->
name|cleanup
argument_list|()
expr_stmt|;
operator|delete
name|d
expr_stmt|;
block|}
end_destructor
begin_function
DECL|function|virtual_hook
name|void
name|QSQLite2Result
operator|::
name|virtual_hook
parameter_list|(
name|int
name|id
parameter_list|,
name|void
modifier|*
name|data
parameter_list|)
block|{
switch|switch
condition|(
name|id
condition|)
block|{
default|default:
name|QSqlCachedResult
operator|::
name|virtual_hook
argument_list|(
name|id
argument_list|,
name|data
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_comment
comment|/*    Execute \a query. */
end_comment
begin_function
DECL|function|reset
name|bool
name|QSQLite2Result
operator|::
name|reset
parameter_list|(
specifier|const
name|QString
modifier|&
name|query
parameter_list|)
block|{
comment|// this is where we build a query.
if|if
condition|(
operator|!
name|driver
argument_list|()
condition|)
return|return
literal|false
return|;
if|if
condition|(
operator|!
name|driver
argument_list|()
operator|->
name|isOpen
argument_list|()
operator|||
name|driver
argument_list|()
operator|->
name|isOpenError
argument_list|()
condition|)
return|return
literal|false
return|;
name|d
operator|->
name|cleanup
argument_list|()
expr_stmt|;
comment|// Um, ok.  callback based so.... pass private static function for this.
name|setSelect
argument_list|(
literal|false
argument_list|)
expr_stmt|;
name|char
modifier|*
name|err
init|=
literal|0
decl_stmt|;
name|int
name|res
init|=
name|sqlite_compile
argument_list|(
name|d
operator|->
name|access
argument_list|,
name|d
operator|->
name|utf8
condition|?
name|query
operator|.
name|toUtf8
argument_list|()
operator|.
name|constData
argument_list|()
else|:
name|query
operator|.
name|toLatin1
argument_list|()
operator|.
name|constData
argument_list|()
argument_list|,
operator|&
operator|(
name|d
operator|->
name|currentTail
operator|)
argument_list|,
operator|&
operator|(
name|d
operator|->
name|currentMachine
operator|)
argument_list|,
operator|&
name|err
argument_list|)
decl_stmt|;
if|if
condition|(
name|res
operator|!=
name|SQLITE_OK
operator|||
name|err
condition|)
block|{
name|setLastError
argument_list|(
name|QSqlError
argument_list|(
name|QCoreApplication
operator|::
name|translate
argument_list|(
literal|"QSQLite2Result"
argument_list|,
literal|"Unable to execute statement"
argument_list|)
argument_list|,
name|QString
operator|::
name|fromLatin1
argument_list|(
name|err
argument_list|)
argument_list|,
name|QSqlError
operator|::
name|StatementError
argument_list|,
name|res
argument_list|)
argument_list|)
expr_stmt|;
name|sqlite_freemem
argument_list|(
name|err
argument_list|)
expr_stmt|;
block|}
comment|//if (*d->currentTail != '\000' then there is more sql to eval
if|if
condition|(
operator|!
name|d
operator|->
name|currentMachine
condition|)
block|{
name|setActive
argument_list|(
literal|false
argument_list|)
expr_stmt|;
return|return
literal|false
return|;
block|}
comment|// we have to fetch one row to find out about
comment|// the structure of the result set
name|d
operator|->
name|skippedStatus
operator|=
name|d
operator|->
name|fetchNext
argument_list|(
name|d
operator|->
name|firstRow
argument_list|,
literal|0
argument_list|,
literal|true
argument_list|)
expr_stmt|;
if|if
condition|(
name|lastError
argument_list|()
operator|.
name|isValid
argument_list|()
condition|)
block|{
name|setSelect
argument_list|(
literal|false
argument_list|)
expr_stmt|;
name|setActive
argument_list|(
literal|false
argument_list|)
expr_stmt|;
return|return
literal|false
return|;
block|}
name|setSelect
argument_list|(
operator|!
name|d
operator|->
name|rInf
operator|.
name|isEmpty
argument_list|()
argument_list|)
expr_stmt|;
name|setActive
argument_list|(
literal|true
argument_list|)
expr_stmt|;
return|return
literal|true
return|;
block|}
end_function
begin_function
DECL|function|gotoNext
name|bool
name|QSQLite2Result
operator|::
name|gotoNext
parameter_list|(
name|QSqlCachedResult
operator|::
name|ValueCache
modifier|&
name|row
parameter_list|,
name|int
name|idx
parameter_list|)
block|{
return|return
name|d
operator|->
name|fetchNext
argument_list|(
name|row
argument_list|,
name|idx
argument_list|,
literal|false
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|size
name|int
name|QSQLite2Result
operator|::
name|size
parameter_list|()
block|{
return|return
operator|-
literal|1
return|;
block|}
end_function
begin_function
DECL|function|numRowsAffected
name|int
name|QSQLite2Result
operator|::
name|numRowsAffected
parameter_list|()
block|{
return|return
name|sqlite_changes
argument_list|(
name|d
operator|->
name|access
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|record
name|QSqlRecord
name|QSQLite2Result
operator|::
name|record
parameter_list|()
specifier|const
block|{
if|if
condition|(
operator|!
name|isActive
argument_list|()
operator|||
operator|!
name|isSelect
argument_list|()
condition|)
return|return
name|QSqlRecord
argument_list|()
return|;
return|return
name|d
operator|->
name|rInf
return|;
block|}
end_function
begin_function
DECL|function|detachFromResultSet
name|void
name|QSQLite2Result
operator|::
name|detachFromResultSet
parameter_list|()
block|{
name|d
operator|->
name|finalize
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|handle
name|QVariant
name|QSQLite2Result
operator|::
name|handle
parameter_list|()
specifier|const
block|{
return|return
name|QVariant
operator|::
name|fromValue
argument_list|(
name|d
operator|->
name|currentMachine
argument_list|)
return|;
block|}
end_function
begin_comment
comment|/////////////////////////////////////////////////////////
end_comment
begin_constructor
DECL|function|QSQLite2Driver
name|QSQLite2Driver
operator|::
name|QSQLite2Driver
parameter_list|(
name|QObject
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QSqlDriver
argument_list|(
name|parent
argument_list|)
block|{
name|d
operator|=
operator|new
name|QSQLite2DriverPrivate
argument_list|()
expr_stmt|;
block|}
end_constructor
begin_constructor
DECL|function|QSQLite2Driver
name|QSQLite2Driver
operator|::
name|QSQLite2Driver
parameter_list|(
name|sqlite
modifier|*
name|connection
parameter_list|,
name|QObject
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QSqlDriver
argument_list|(
name|parent
argument_list|)
block|{
name|d
operator|=
operator|new
name|QSQLite2DriverPrivate
argument_list|()
expr_stmt|;
name|d
operator|->
name|access
operator|=
name|connection
expr_stmt|;
name|setOpen
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|setOpenError
argument_list|(
literal|false
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_destructor
DECL|function|~QSQLite2Driver
name|QSQLite2Driver
operator|::
name|~
name|QSQLite2Driver
parameter_list|()
block|{
operator|delete
name|d
expr_stmt|;
block|}
end_destructor
begin_function
DECL|function|hasFeature
name|bool
name|QSQLite2Driver
operator|::
name|hasFeature
parameter_list|(
name|DriverFeature
name|f
parameter_list|)
specifier|const
block|{
switch|switch
condition|(
name|f
condition|)
block|{
case|case
name|Transactions
case|:
case|case
name|SimpleLocking
case|:
return|return
literal|true
return|;
case|case
name|Unicode
case|:
return|return
name|d
operator|->
name|utf8
return|;
default|default:
return|return
literal|false
return|;
block|}
block|}
end_function
begin_comment
comment|/*    SQLite dbs have no user name, passwords, hosts or ports.    just file names. */
end_comment
begin_function
DECL|function|open
name|bool
name|QSQLite2Driver
operator|::
name|open
parameter_list|(
specifier|const
name|QString
modifier|&
name|db
parameter_list|,
specifier|const
name|QString
modifier|&
parameter_list|,
specifier|const
name|QString
modifier|&
parameter_list|,
specifier|const
name|QString
modifier|&
parameter_list|,
name|int
parameter_list|,
specifier|const
name|QString
modifier|&
parameter_list|)
block|{
if|if
condition|(
name|isOpen
argument_list|()
condition|)
name|close
argument_list|()
expr_stmt|;
if|if
condition|(
name|db
operator|.
name|isEmpty
argument_list|()
condition|)
return|return
literal|false
return|;
name|char
modifier|*
name|err
init|=
literal|0
decl_stmt|;
name|d
operator|->
name|access
operator|=
name|sqlite_open
argument_list|(
name|QFile
operator|::
name|encodeName
argument_list|(
name|db
argument_list|)
argument_list|,
literal|0
argument_list|,
operator|&
name|err
argument_list|)
expr_stmt|;
if|if
condition|(
name|err
condition|)
block|{
name|setLastError
argument_list|(
name|QSqlError
argument_list|(
name|tr
argument_list|(
literal|"Error opening database"
argument_list|)
argument_list|,
name|QString
operator|::
name|fromLatin1
argument_list|(
name|err
argument_list|)
argument_list|,
name|QSqlError
operator|::
name|ConnectionError
argument_list|)
argument_list|)
expr_stmt|;
name|sqlite_freemem
argument_list|(
name|err
argument_list|)
expr_stmt|;
name|err
operator|=
literal|0
expr_stmt|;
block|}
if|if
condition|(
name|d
operator|->
name|access
condition|)
block|{
name|setOpen
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|setOpenError
argument_list|(
literal|false
argument_list|)
expr_stmt|;
return|return
literal|true
return|;
block|}
name|setOpenError
argument_list|(
literal|true
argument_list|)
expr_stmt|;
return|return
literal|false
return|;
block|}
end_function
begin_function
DECL|function|close
name|void
name|QSQLite2Driver
operator|::
name|close
parameter_list|()
block|{
if|if
condition|(
name|isOpen
argument_list|()
condition|)
block|{
name|sqlite_close
argument_list|(
name|d
operator|->
name|access
argument_list|)
expr_stmt|;
name|d
operator|->
name|access
operator|=
literal|0
expr_stmt|;
name|setOpen
argument_list|(
literal|false
argument_list|)
expr_stmt|;
name|setOpenError
argument_list|(
literal|false
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|createResult
name|QSqlResult
modifier|*
name|QSQLite2Driver
operator|::
name|createResult
parameter_list|()
specifier|const
block|{
return|return
operator|new
name|QSQLite2Result
argument_list|(
name|this
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|beginTransaction
name|bool
name|QSQLite2Driver
operator|::
name|beginTransaction
parameter_list|()
block|{
if|if
condition|(
operator|!
name|isOpen
argument_list|()
operator|||
name|isOpenError
argument_list|()
condition|)
return|return
literal|false
return|;
name|char
modifier|*
name|err
decl_stmt|;
name|int
name|res
init|=
name|sqlite_exec
argument_list|(
name|d
operator|->
name|access
argument_list|,
literal|"BEGIN"
argument_list|,
literal|0
argument_list|,
name|this
argument_list|,
operator|&
name|err
argument_list|)
decl_stmt|;
if|if
condition|(
name|res
operator|==
name|SQLITE_OK
condition|)
return|return
literal|true
return|;
name|setLastError
argument_list|(
name|QSqlError
argument_list|(
name|tr
argument_list|(
literal|"Unable to begin transaction"
argument_list|)
argument_list|,
name|QString
operator|::
name|fromLatin1
argument_list|(
name|err
argument_list|)
argument_list|,
name|QSqlError
operator|::
name|TransactionError
argument_list|,
name|res
argument_list|)
argument_list|)
expr_stmt|;
name|sqlite_freemem
argument_list|(
name|err
argument_list|)
expr_stmt|;
return|return
literal|false
return|;
block|}
end_function
begin_function
DECL|function|commitTransaction
name|bool
name|QSQLite2Driver
operator|::
name|commitTransaction
parameter_list|()
block|{
if|if
condition|(
operator|!
name|isOpen
argument_list|()
operator|||
name|isOpenError
argument_list|()
condition|)
return|return
literal|false
return|;
name|char
modifier|*
name|err
decl_stmt|;
name|int
name|res
init|=
name|sqlite_exec
argument_list|(
name|d
operator|->
name|access
argument_list|,
literal|"COMMIT"
argument_list|,
literal|0
argument_list|,
name|this
argument_list|,
operator|&
name|err
argument_list|)
decl_stmt|;
if|if
condition|(
name|res
operator|==
name|SQLITE_OK
condition|)
return|return
literal|true
return|;
name|setLastError
argument_list|(
name|QSqlError
argument_list|(
name|tr
argument_list|(
literal|"Unable to commit transaction"
argument_list|)
argument_list|,
name|QString
operator|::
name|fromLatin1
argument_list|(
name|err
argument_list|)
argument_list|,
name|QSqlError
operator|::
name|TransactionError
argument_list|,
name|res
argument_list|)
argument_list|)
expr_stmt|;
name|sqlite_freemem
argument_list|(
name|err
argument_list|)
expr_stmt|;
return|return
literal|false
return|;
block|}
end_function
begin_function
DECL|function|rollbackTransaction
name|bool
name|QSQLite2Driver
operator|::
name|rollbackTransaction
parameter_list|()
block|{
if|if
condition|(
operator|!
name|isOpen
argument_list|()
operator|||
name|isOpenError
argument_list|()
condition|)
return|return
literal|false
return|;
name|char
modifier|*
name|err
decl_stmt|;
name|int
name|res
init|=
name|sqlite_exec
argument_list|(
name|d
operator|->
name|access
argument_list|,
literal|"ROLLBACK"
argument_list|,
literal|0
argument_list|,
name|this
argument_list|,
operator|&
name|err
argument_list|)
decl_stmt|;
if|if
condition|(
name|res
operator|==
name|SQLITE_OK
condition|)
return|return
literal|true
return|;
name|setLastError
argument_list|(
name|QSqlError
argument_list|(
name|tr
argument_list|(
literal|"Unable to rollback transaction"
argument_list|)
argument_list|,
name|QString
operator|::
name|fromLatin1
argument_list|(
name|err
argument_list|)
argument_list|,
name|QSqlError
operator|::
name|TransactionError
argument_list|,
name|res
argument_list|)
argument_list|)
expr_stmt|;
name|sqlite_freemem
argument_list|(
name|err
argument_list|)
expr_stmt|;
return|return
literal|false
return|;
block|}
end_function
begin_function
DECL|function|tables
name|QStringList
name|QSQLite2Driver
operator|::
name|tables
parameter_list|(
name|QSql
operator|::
name|TableType
name|type
parameter_list|)
specifier|const
block|{
name|QStringList
name|res
decl_stmt|;
if|if
condition|(
operator|!
name|isOpen
argument_list|()
condition|)
return|return
name|res
return|;
name|QSqlQuery
name|q
argument_list|(
name|createResult
argument_list|()
argument_list|)
decl_stmt|;
name|q
operator|.
name|setForwardOnly
argument_list|(
literal|true
argument_list|)
expr_stmt|;
if|if
condition|(
operator|(
name|type
operator|&
name|QSql
operator|::
name|Tables
operator|)
operator|&&
operator|(
name|type
operator|&
name|QSql
operator|::
name|Views
operator|)
condition|)
name|q
operator|.
name|exec
argument_list|(
name|QLatin1String
argument_list|(
literal|"SELECT name FROM sqlite_master WHERE type='table' OR type='view'"
argument_list|)
argument_list|)
expr_stmt|;
elseif|else
if|if
condition|(
name|type
operator|&
name|QSql
operator|::
name|Tables
condition|)
name|q
operator|.
name|exec
argument_list|(
name|QLatin1String
argument_list|(
literal|"SELECT name FROM sqlite_master WHERE type='table'"
argument_list|)
argument_list|)
expr_stmt|;
elseif|else
if|if
condition|(
name|type
operator|&
name|QSql
operator|::
name|Views
condition|)
name|q
operator|.
name|exec
argument_list|(
name|QLatin1String
argument_list|(
literal|"SELECT name FROM sqlite_master WHERE type='view'"
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|q
operator|.
name|isActive
argument_list|()
condition|)
block|{
while|while
condition|(
name|q
operator|.
name|next
argument_list|()
condition|)
name|res
operator|.
name|append
argument_list|(
name|q
operator|.
name|value
argument_list|(
literal|0
argument_list|)
operator|.
name|toString
argument_list|()
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|type
operator|&
name|QSql
operator|::
name|SystemTables
condition|)
block|{
comment|// there are no internal tables beside this one:
name|res
operator|.
name|append
argument_list|(
name|QLatin1String
argument_list|(
literal|"sqlite_master"
argument_list|)
argument_list|)
expr_stmt|;
block|}
return|return
name|res
return|;
block|}
end_function
begin_function
DECL|function|primaryIndex
name|QSqlIndex
name|QSQLite2Driver
operator|::
name|primaryIndex
parameter_list|(
specifier|const
name|QString
modifier|&
name|tblname
parameter_list|)
specifier|const
block|{
name|QSqlRecord
name|rec
argument_list|(
name|record
argument_list|(
name|tblname
argument_list|)
argument_list|)
decl_stmt|;
comment|// expensive :(
if|if
condition|(
operator|!
name|isOpen
argument_list|()
condition|)
return|return
name|QSqlIndex
argument_list|()
return|;
name|QSqlQuery
name|q
argument_list|(
name|createResult
argument_list|()
argument_list|)
decl_stmt|;
name|q
operator|.
name|setForwardOnly
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|QString
name|table
init|=
name|tblname
decl_stmt|;
if|if
condition|(
name|isIdentifierEscaped
argument_list|(
name|table
argument_list|,
name|QSqlDriver
operator|::
name|TableName
argument_list|)
condition|)
name|table
operator|=
name|stripDelimiters
argument_list|(
name|table
argument_list|,
name|QSqlDriver
operator|::
name|TableName
argument_list|)
expr_stmt|;
comment|// finrst find a UNIQUE INDEX
name|q
operator|.
name|exec
argument_list|(
name|QLatin1String
argument_list|(
literal|"PRAGMA index_list('"
argument_list|)
operator|+
name|table
operator|+
name|QLatin1String
argument_list|(
literal|"');"
argument_list|)
argument_list|)
expr_stmt|;
name|QString
name|indexname
decl_stmt|;
while|while
condition|(
name|q
operator|.
name|next
argument_list|()
condition|)
block|{
if|if
condition|(
name|q
operator|.
name|value
argument_list|(
literal|2
argument_list|)
operator|.
name|toInt
argument_list|()
operator|==
literal|1
condition|)
block|{
name|indexname
operator|=
name|q
operator|.
name|value
argument_list|(
literal|1
argument_list|)
operator|.
name|toString
argument_list|()
expr_stmt|;
break|break;
block|}
block|}
if|if
condition|(
name|indexname
operator|.
name|isEmpty
argument_list|()
condition|)
return|return
name|QSqlIndex
argument_list|()
return|;
name|q
operator|.
name|exec
argument_list|(
name|QLatin1String
argument_list|(
literal|"PRAGMA index_info('"
argument_list|)
operator|+
name|indexname
operator|+
name|QLatin1String
argument_list|(
literal|"');"
argument_list|)
argument_list|)
expr_stmt|;
name|QSqlIndex
name|index
argument_list|(
name|table
argument_list|,
name|indexname
argument_list|)
decl_stmt|;
while|while
condition|(
name|q
operator|.
name|next
argument_list|()
condition|)
block|{
name|QString
name|name
init|=
name|q
operator|.
name|value
argument_list|(
literal|2
argument_list|)
operator|.
name|toString
argument_list|()
decl_stmt|;
name|QVariant
operator|::
name|Type
name|type
init|=
name|QVariant
operator|::
name|Invalid
decl_stmt|;
if|if
condition|(
name|rec
operator|.
name|contains
argument_list|(
name|name
argument_list|)
condition|)
name|type
operator|=
name|rec
operator|.
name|field
argument_list|(
name|name
argument_list|)
operator|.
name|type
argument_list|()
expr_stmt|;
name|index
operator|.
name|append
argument_list|(
name|QSqlField
argument_list|(
name|name
argument_list|,
name|type
argument_list|)
argument_list|)
expr_stmt|;
block|}
return|return
name|index
return|;
block|}
end_function
begin_function
DECL|function|record
name|QSqlRecord
name|QSQLite2Driver
operator|::
name|record
parameter_list|(
specifier|const
name|QString
modifier|&
name|tbl
parameter_list|)
specifier|const
block|{
if|if
condition|(
operator|!
name|isOpen
argument_list|()
condition|)
return|return
name|QSqlRecord
argument_list|()
return|;
name|QString
name|table
init|=
name|tbl
decl_stmt|;
if|if
condition|(
name|isIdentifierEscaped
argument_list|(
name|tbl
argument_list|,
name|QSqlDriver
operator|::
name|TableName
argument_list|)
condition|)
name|table
operator|=
name|stripDelimiters
argument_list|(
name|table
argument_list|,
name|QSqlDriver
operator|::
name|TableName
argument_list|)
expr_stmt|;
name|QSqlQuery
name|q
argument_list|(
name|createResult
argument_list|()
argument_list|)
decl_stmt|;
name|q
operator|.
name|setForwardOnly
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|q
operator|.
name|exec
argument_list|(
name|QLatin1String
argument_list|(
literal|"SELECT * FROM "
argument_list|)
operator|+
name|tbl
operator|+
name|QLatin1String
argument_list|(
literal|" LIMIT 1"
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|q
operator|.
name|record
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|handle
name|QVariant
name|QSQLite2Driver
operator|::
name|handle
parameter_list|()
specifier|const
block|{
return|return
name|QVariant
operator|::
name|fromValue
argument_list|(
name|d
operator|->
name|access
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|escapeIdentifier
name|QString
name|QSQLite2Driver
operator|::
name|escapeIdentifier
parameter_list|(
specifier|const
name|QString
modifier|&
name|identifier
parameter_list|,
name|IdentifierType
comment|/*type*/
parameter_list|)
specifier|const
block|{
name|QString
name|res
init|=
name|identifier
decl_stmt|;
if|if
condition|(
operator|!
name|identifier
operator|.
name|isEmpty
argument_list|()
operator|&&
operator|!
name|identifier
operator|.
name|startsWith
argument_list|(
name|QLatin1Char
argument_list|(
literal|'"'
argument_list|)
argument_list|)
operator|&&
operator|!
name|identifier
operator|.
name|endsWith
argument_list|(
name|QLatin1Char
argument_list|(
literal|'"'
argument_list|)
argument_list|)
condition|)
block|{
name|res
operator|.
name|replace
argument_list|(
name|QLatin1Char
argument_list|(
literal|'"'
argument_list|)
argument_list|,
name|QLatin1String
argument_list|(
literal|"\"\""
argument_list|)
argument_list|)
expr_stmt|;
name|res
operator|.
name|prepend
argument_list|(
name|QLatin1Char
argument_list|(
literal|'"'
argument_list|)
argument_list|)
operator|.
name|append
argument_list|(
name|QLatin1Char
argument_list|(
literal|'"'
argument_list|)
argument_list|)
expr_stmt|;
name|res
operator|.
name|replace
argument_list|(
name|QLatin1Char
argument_list|(
literal|'.'
argument_list|)
argument_list|,
name|QLatin1String
argument_list|(
literal|"\".\""
argument_list|)
argument_list|)
expr_stmt|;
block|}
return|return
name|res
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
