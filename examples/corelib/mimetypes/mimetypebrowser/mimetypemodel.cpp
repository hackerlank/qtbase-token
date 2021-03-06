begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of The Qt Company Ltd nor the names of its **     contributors may be used to endorse or promote products derived **     from this software without specific prior written permission. ** ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"mimetypemodel.h"
end_include
begin_include
include|#
directive|include
file|<QIcon>
end_include
begin_include
include|#
directive|include
file|<QDebug>
end_include
begin_include
include|#
directive|include
file|<QMimeDatabase>
end_include
begin_include
include|#
directive|include
file|<QTextStream>
end_include
begin_include
include|#
directive|include
file|<QVariant>
end_include
begin_include
include|#
directive|include
file|<algorithm>
end_include
begin_macro
name|Q_DECLARE_METATYPE
argument_list|(
argument|QMimeType
argument_list|)
end_macro
begin_typedef
DECL|typedef|StandardItemList
typedef|typedef
name|QList
argument_list|<
name|QStandardItem
modifier|*
argument_list|>
name|StandardItemList
typedef|;
end_typedef
begin_enum
DECL|enumerator|mimeTypeRole
DECL|enumerator|iconQueriedRole
enum|enum
block|{
name|mimeTypeRole
init|=
name|Qt
operator|::
name|UserRole
operator|+
literal|1
block|,
name|iconQueriedRole
init|=
name|Qt
operator|::
name|UserRole
operator|+
literal|2
block|}
enum|;
end_enum
begin_function
name|QT_BEGIN_NAMESPACE
DECL|function|operator <
name|bool
name|operator
name|<
parameter_list|(
specifier|const
name|QMimeType
modifier|&
name|t1
parameter_list|,
specifier|const
name|QMimeType
modifier|&
name|t2
parameter_list|)
block|{
return|return
name|t1
operator|.
name|name
argument_list|()
operator|<
name|t2
operator|.
name|name
argument_list|()
return|;
block|}
end_function
begin_function
name|QT_END_NAMESPACE
DECL|function|createRow
specifier|static
name|StandardItemList
name|createRow
parameter_list|(
specifier|const
name|QMimeType
modifier|&
name|t
parameter_list|)
block|{
specifier|const
name|QVariant
name|v
init|=
name|QVariant
operator|::
name|fromValue
argument_list|(
name|t
argument_list|)
decl_stmt|;
name|QStandardItem
modifier|*
name|nameItem
init|=
operator|new
name|QStandardItem
argument_list|(
name|t
operator|.
name|name
argument_list|()
argument_list|)
decl_stmt|;
specifier|const
name|Qt
operator|::
name|ItemFlags
name|flags
init|=
name|Qt
operator|::
name|ItemIsSelectable
operator||
name|Qt
operator|::
name|ItemIsEnabled
decl_stmt|;
name|nameItem
operator|->
name|setData
argument_list|(
name|v
argument_list|,
name|mimeTypeRole
argument_list|)
expr_stmt|;
name|nameItem
operator|->
name|setData
argument_list|(
name|QVariant
argument_list|(
literal|false
argument_list|)
argument_list|,
name|iconQueriedRole
argument_list|)
expr_stmt|;
name|nameItem
operator|->
name|setFlags
argument_list|(
name|flags
argument_list|)
expr_stmt|;
name|nameItem
operator|->
name|setToolTip
argument_list|(
name|t
operator|.
name|comment
argument_list|()
argument_list|)
expr_stmt|;
return|return
name|StandardItemList
block|{
name|nameItem
block|}
return|;
block|}
end_function
begin_constructor
DECL|function|MimetypeModel
name|MimetypeModel
operator|::
name|MimetypeModel
parameter_list|(
name|QObject
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QStandardItemModel
argument_list|(
literal|0
argument_list|,
name|ColumnCount
argument_list|,
name|parent
argument_list|)
block|{
name|setHorizontalHeaderLabels
argument_list|(
name|QStringList
block|{
name|tr
argument_list|(
literal|"Name"
argument_list|)
block|}
argument_list|)
expr_stmt|;
name|populate
argument_list|()
expr_stmt|;
block|}
end_constructor
begin_function
DECL|function|data
name|QVariant
name|MimetypeModel
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
name|role
operator|!=
name|Qt
operator|::
name|DecorationRole
operator|||
operator|!
name|index
operator|.
name|isValid
argument_list|()
operator|||
name|index
operator|.
name|data
argument_list|(
name|iconQueriedRole
argument_list|)
operator|.
name|toBool
argument_list|()
condition|)
return|return
name|QStandardItemModel
operator|::
name|data
argument_list|(
name|index
argument_list|,
name|role
argument_list|)
return|;
name|QStandardItem
modifier|*
name|item
init|=
name|itemFromIndex
argument_list|(
name|index
argument_list|)
decl_stmt|;
specifier|const
name|QString
name|iconName
init|=
name|item
operator|->
name|data
argument_list|(
name|mimeTypeRole
argument_list|)
operator|.
name|value
argument_list|<
name|QMimeType
argument_list|>
argument_list|()
operator|.
name|iconName
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
name|iconName
operator|.
name|isEmpty
argument_list|()
condition|)
name|item
operator|->
name|setIcon
argument_list|(
name|QIcon
operator|::
name|fromTheme
argument_list|(
name|iconName
argument_list|)
argument_list|)
expr_stmt|;
name|item
operator|->
name|setData
argument_list|(
name|QVariant
argument_list|(
literal|true
argument_list|)
argument_list|,
name|iconQueriedRole
argument_list|)
expr_stmt|;
return|return
name|item
operator|->
name|icon
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|mimeType
name|QMimeType
name|MimetypeModel
operator|::
name|mimeType
parameter_list|(
specifier|const
name|QModelIndex
modifier|&
name|index
parameter_list|)
specifier|const
block|{
return|return
name|index
operator|.
name|data
argument_list|(
name|mimeTypeRole
argument_list|)
operator|.
name|value
argument_list|<
name|QMimeType
argument_list|>
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|populate
name|void
name|MimetypeModel
operator|::
name|populate
parameter_list|()
block|{
typedef|typedef
name|QList
argument_list|<
name|QMimeType
argument_list|>
operator|::
name|Iterator
name|Iterator
typedef|;
name|QMimeDatabase
name|mimeDatabase
decl_stmt|;
name|QList
argument_list|<
name|QMimeType
argument_list|>
name|allTypes
init|=
name|mimeDatabase
operator|.
name|allMimeTypes
argument_list|()
decl_stmt|;
comment|// Move top level types to rear end of list, sort this partition,
comment|// create top level items and truncate the list.
name|Iterator
name|end
init|=
name|allTypes
operator|.
name|end
argument_list|()
decl_stmt|;
specifier|const
name|Iterator
name|topLevelStart
init|=
name|std
operator|::
name|stable_partition
argument_list|(
name|allTypes
operator|.
name|begin
argument_list|()
argument_list|,
name|end
argument_list|,
capture|[]
parameter_list|(
specifier|const
name|QMimeType
modifier|&
name|t
parameter_list|)
block|{
return|return
operator|!
name|t
operator|.
name|parentMimeTypes
argument_list|()
operator|.
name|isEmpty
argument_list|()
return|;
block|}
argument_list|)
decl_stmt|;
name|std
operator|::
name|stable_sort
argument_list|(
name|topLevelStart
argument_list|,
name|end
argument_list|)
expr_stmt|;
for|for
control|(
name|Iterator
name|it
init|=
name|topLevelStart
init|;
name|it
operator|!=
name|end
condition|;
operator|++
name|it
control|)
block|{
specifier|const
name|StandardItemList
name|row
init|=
name|createRow
argument_list|(
operator|*
name|it
argument_list|)
decl_stmt|;
name|appendRow
argument_list|(
name|row
argument_list|)
expr_stmt|;
name|m_nameIndexHash
operator|.
name|insert
argument_list|(
name|it
operator|->
name|name
argument_list|()
argument_list|,
name|indexFromItem
argument_list|(
name|row
operator|.
name|constFirst
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
block|}
name|allTypes
operator|.
name|erase
argument_list|(
name|topLevelStart
argument_list|,
name|end
argument_list|)
expr_stmt|;
while|while
condition|(
operator|!
name|allTypes
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
comment|// Find a type inheriting one that is already in the model.
name|end
operator|=
name|allTypes
operator|.
name|end
argument_list|()
expr_stmt|;
name|auto
name|nameIndexIt
init|=
name|m_nameIndexHash
operator|.
name|constEnd
argument_list|()
decl_stmt|;
for|for
control|(
name|Iterator
name|it
init|=
name|allTypes
operator|.
name|begin
argument_list|()
init|;
name|it
operator|!=
name|end
condition|;
operator|++
name|it
control|)
block|{
name|nameIndexIt
operator|=
name|m_nameIndexHash
operator|.
name|constFind
argument_list|(
name|it
operator|->
name|parentMimeTypes
argument_list|()
operator|.
name|constFirst
argument_list|()
argument_list|)
expr_stmt|;
if|if
condition|(
name|nameIndexIt
operator|!=
name|m_nameIndexHash
operator|.
name|constEnd
argument_list|()
condition|)
break|break;
block|}
if|if
condition|(
name|nameIndexIt
operator|==
name|m_nameIndexHash
operator|.
name|constEnd
argument_list|()
condition|)
block|{
name|qWarning
argument_list|()
operator|<<
literal|"Orphaned mime types:"
operator|<<
name|allTypes
expr_stmt|;
break|break;
block|}
comment|// Move types inheriting the parent type to rear end of list, sort this partition,
comment|// append the items to parent and truncate the list.
specifier|const
name|QString
modifier|&
name|parentName
init|=
name|nameIndexIt
operator|.
name|key
argument_list|()
decl_stmt|;
specifier|const
name|Iterator
name|start
init|=
name|std
operator|::
name|stable_partition
argument_list|(
name|allTypes
operator|.
name|begin
argument_list|()
argument_list|,
name|end
argument_list|,
capture|[
name|parentName
capture|]
parameter_list|(
specifier|const
name|QMimeType
modifier|&
name|t
parameter_list|)
block|{
return|return
operator|!
name|t
operator|.
name|parentMimeTypes
argument_list|()
operator|.
name|contains
argument_list|(
name|parentName
argument_list|)
return|;
block|}
argument_list|)
decl_stmt|;
name|std
operator|::
name|stable_sort
argument_list|(
name|start
argument_list|,
name|end
argument_list|)
expr_stmt|;
name|QStandardItem
modifier|*
name|parentItem
init|=
name|itemFromIndex
argument_list|(
name|nameIndexIt
operator|.
name|value
argument_list|()
argument_list|)
decl_stmt|;
for|for
control|(
name|Iterator
name|it
init|=
name|start
init|;
name|it
operator|!=
name|end
condition|;
operator|++
name|it
control|)
block|{
specifier|const
name|StandardItemList
name|row
init|=
name|createRow
argument_list|(
operator|*
name|it
argument_list|)
decl_stmt|;
name|parentItem
operator|->
name|appendRow
argument_list|(
name|row
argument_list|)
expr_stmt|;
name|m_nameIndexHash
operator|.
name|insert
argument_list|(
name|it
operator|->
name|name
argument_list|()
argument_list|,
name|indexFromItem
argument_list|(
name|row
operator|.
name|constFirst
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
block|}
name|allTypes
operator|.
name|erase
argument_list|(
name|start
argument_list|,
name|end
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|operator <<
name|QTextStream
modifier|&
name|operator
name|<<
parameter_list|(
name|QTextStream
modifier|&
name|stream
parameter_list|,
specifier|const
name|QStringList
modifier|&
name|list
parameter_list|)
block|{
for|for
control|(
name|int
name|i
init|=
literal|0
init|,
name|size
init|=
name|list
operator|.
name|size
argument_list|()
init|;
name|i
operator|<
name|size
condition|;
operator|++
name|i
control|)
block|{
if|if
condition|(
name|i
condition|)
name|stream
operator|<<
literal|", "
expr_stmt|;
name|stream
operator|<<
name|list
operator|.
name|at
argument_list|(
name|i
argument_list|)
expr_stmt|;
block|}
return|return
name|stream
return|;
block|}
end_function
begin_function
DECL|function|formatMimeTypeInfo
name|QString
name|MimetypeModel
operator|::
name|formatMimeTypeInfo
parameter_list|(
specifier|const
name|QMimeType
modifier|&
name|t
parameter_list|)
block|{
name|QString
name|result
decl_stmt|;
name|QTextStream
name|str
argument_list|(
operator|&
name|result
argument_list|)
decl_stmt|;
name|str
operator|<<
literal|"<html><head/><body><h3><center>"
operator|<<
name|t
operator|.
name|name
argument_list|()
operator|<<
literal|"</center></h3><br><table>"
expr_stmt|;
specifier|const
name|QStringList
modifier|&
name|aliases
init|=
name|t
operator|.
name|aliases
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
name|aliases
operator|.
name|isEmpty
argument_list|()
condition|)
name|str
operator|<<
literal|"<tr><td>Aliases:</td><td>"
operator|<<
literal|" ("
operator|<<
name|aliases
operator|<<
literal|')'
expr_stmt|;
name|str
operator|<<
literal|"</td></tr>"
operator|<<
literal|"<tr><td>Comment:</td><td>"
operator|<<
name|t
operator|.
name|comment
argument_list|()
operator|<<
literal|"</td></tr>"
operator|<<
literal|"<tr><td>Icon name:</td><td>"
operator|<<
name|t
operator|.
name|iconName
argument_list|()
operator|<<
literal|"</td></tr>"
expr_stmt|;
specifier|const
name|QString
modifier|&
name|filter
init|=
name|t
operator|.
name|filterString
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
name|filter
operator|.
name|isEmpty
argument_list|()
condition|)
name|str
operator|<<
literal|"<tr><td>Filter:</td><td>"
operator|<<
name|t
operator|.
name|filterString
argument_list|()
operator|<<
literal|"</td></tr>"
expr_stmt|;
specifier|const
name|QStringList
modifier|&
name|patterns
init|=
name|t
operator|.
name|globPatterns
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
name|patterns
operator|.
name|isEmpty
argument_list|()
condition|)
name|str
operator|<<
literal|"<tr><td>Glob patterns:</td><td>"
operator|<<
name|patterns
operator|<<
literal|"</td></tr>"
expr_stmt|;
specifier|const
name|QStringList
modifier|&
name|parentMimeTypes
init|=
name|t
operator|.
name|parentMimeTypes
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
name|parentMimeTypes
operator|.
name|isEmpty
argument_list|()
condition|)
name|str
operator|<<
literal|"<tr><td>Parent types:</td><td>"
operator|<<
name|t
operator|.
name|parentMimeTypes
argument_list|()
operator|<<
literal|"</td></tr>"
expr_stmt|;
name|QStringList
name|suffixes
init|=
name|t
operator|.
name|suffixes
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
name|suffixes
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|str
operator|<<
literal|"<tr><td>Suffixes:</td><td>"
expr_stmt|;
specifier|const
name|QString
modifier|&
name|preferredSuffix
init|=
name|t
operator|.
name|preferredSuffix
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
name|preferredSuffix
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|suffixes
operator|.
name|removeOne
argument_list|(
name|preferredSuffix
argument_list|)
expr_stmt|;
name|str
operator|<<
literal|"<b>"
operator|<<
name|preferredSuffix
operator|<<
literal|"</b> "
expr_stmt|;
block|}
name|str
operator|<<
name|suffixes
operator|<<
literal|"</td></tr>"
expr_stmt|;
block|}
name|str
operator|<<
literal|"</table></body></html>"
expr_stmt|;
return|return
name|result
return|;
block|}
end_function
end_unit
