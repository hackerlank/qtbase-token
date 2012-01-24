begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of Nokia Corporation and its Subsidiary(-ies) nor **     the names of its contributors may be used to endorse or promote **     products derived from this software without specific prior written **     permission. ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"tablemodel.h"
end_include
begin_comment
comment|//! [0]
end_comment
begin_constructor
DECL|function|TableModel
name|TableModel
operator|::
name|TableModel
parameter_list|(
name|QObject
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QAbstractTableModel
argument_list|(
name|parent
argument_list|)
block|{ }
end_constructor
begin_constructor
DECL|function|TableModel
name|TableModel
operator|::
name|TableModel
parameter_list|(
name|QList
argument_list|<
name|QPair
argument_list|<
name|QString
argument_list|,
name|QString
argument_list|>
argument_list|>
name|pairs
parameter_list|,
name|QObject
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QAbstractTableModel
argument_list|(
name|parent
argument_list|)
block|{
name|listOfPairs
operator|=
name|pairs
expr_stmt|;
block|}
end_constructor
begin_comment
comment|//! [0]
end_comment
begin_comment
comment|//! [1]
end_comment
begin_function
DECL|function|rowCount
name|int
name|TableModel
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
name|Q_UNUSED
argument_list|(
name|parent
argument_list|)
expr_stmt|;
return|return
name|listOfPairs
operator|.
name|size
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|columnCount
name|int
name|TableModel
operator|::
name|columnCount
parameter_list|(
specifier|const
name|QModelIndex
modifier|&
name|parent
parameter_list|)
specifier|const
block|{
name|Q_UNUSED
argument_list|(
name|parent
argument_list|)
expr_stmt|;
return|return
literal|2
return|;
block|}
end_function
begin_comment
comment|//! [1]
end_comment
begin_comment
comment|//! [2]
end_comment
begin_function
DECL|function|data
name|QVariant
name|TableModel
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
operator|!
name|index
operator|.
name|isValid
argument_list|()
condition|)
return|return
name|QVariant
argument_list|()
return|;
if|if
condition|(
name|index
operator|.
name|row
argument_list|()
operator|>=
name|listOfPairs
operator|.
name|size
argument_list|()
operator|||
name|index
operator|.
name|row
argument_list|()
operator|<
literal|0
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
condition|)
block|{
name|QPair
argument_list|<
name|QString
argument_list|,
name|QString
argument_list|>
name|pair
init|=
name|listOfPairs
operator|.
name|at
argument_list|(
name|index
operator|.
name|row
argument_list|()
argument_list|)
decl_stmt|;
if|if
condition|(
name|index
operator|.
name|column
argument_list|()
operator|==
literal|0
condition|)
return|return
name|pair
operator|.
name|first
return|;
elseif|else
if|if
condition|(
name|index
operator|.
name|column
argument_list|()
operator|==
literal|1
condition|)
return|return
name|pair
operator|.
name|second
return|;
block|}
return|return
name|QVariant
argument_list|()
return|;
block|}
end_function
begin_comment
comment|//! [2]
end_comment
begin_comment
comment|//! [3]
end_comment
begin_function
DECL|function|headerData
name|QVariant
name|TableModel
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
if|if
condition|(
name|role
operator|!=
name|Qt
operator|::
name|DisplayRole
condition|)
return|return
name|QVariant
argument_list|()
return|;
if|if
condition|(
name|orientation
operator|==
name|Qt
operator|::
name|Horizontal
condition|)
block|{
switch|switch
condition|(
name|section
condition|)
block|{
case|case
literal|0
case|:
return|return
name|tr
argument_list|(
literal|"Name"
argument_list|)
return|;
case|case
literal|1
case|:
return|return
name|tr
argument_list|(
literal|"Address"
argument_list|)
return|;
default|default:
return|return
name|QVariant
argument_list|()
return|;
block|}
block|}
return|return
name|QVariant
argument_list|()
return|;
block|}
end_function
begin_comment
comment|//! [3]
end_comment
begin_comment
comment|//! [4]
end_comment
begin_function
DECL|function|insertRows
name|bool
name|TableModel
operator|::
name|insertRows
parameter_list|(
name|int
name|position
parameter_list|,
name|int
name|rows
parameter_list|,
specifier|const
name|QModelIndex
modifier|&
name|index
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
name|index
argument_list|)
expr_stmt|;
name|beginInsertRows
argument_list|(
name|QModelIndex
argument_list|()
argument_list|,
name|position
argument_list|,
name|position
operator|+
name|rows
operator|-
literal|1
argument_list|)
expr_stmt|;
for|for
control|(
name|int
name|row
init|=
literal|0
init|;
name|row
operator|<
name|rows
condition|;
name|row
operator|++
control|)
block|{
name|QPair
argument_list|<
name|QString
argument_list|,
name|QString
argument_list|>
name|pair
argument_list|(
literal|" "
argument_list|,
literal|" "
argument_list|)
decl_stmt|;
name|listOfPairs
operator|.
name|insert
argument_list|(
name|position
argument_list|,
name|pair
argument_list|)
expr_stmt|;
block|}
name|endInsertRows
argument_list|()
expr_stmt|;
return|return
literal|true
return|;
block|}
end_function
begin_comment
comment|//! [4]
end_comment
begin_comment
comment|//! [5]
end_comment
begin_function
DECL|function|removeRows
name|bool
name|TableModel
operator|::
name|removeRows
parameter_list|(
name|int
name|position
parameter_list|,
name|int
name|rows
parameter_list|,
specifier|const
name|QModelIndex
modifier|&
name|index
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
name|index
argument_list|)
expr_stmt|;
name|beginRemoveRows
argument_list|(
name|QModelIndex
argument_list|()
argument_list|,
name|position
argument_list|,
name|position
operator|+
name|rows
operator|-
literal|1
argument_list|)
expr_stmt|;
for|for
control|(
name|int
name|row
init|=
literal|0
init|;
name|row
operator|<
name|rows
condition|;
operator|++
name|row
control|)
block|{
name|listOfPairs
operator|.
name|removeAt
argument_list|(
name|position
argument_list|)
expr_stmt|;
block|}
name|endRemoveRows
argument_list|()
expr_stmt|;
return|return
literal|true
return|;
block|}
end_function
begin_comment
comment|//! [5]
end_comment
begin_comment
comment|//! [6]
end_comment
begin_function
DECL|function|setData
name|bool
name|TableModel
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
name|isValid
argument_list|()
operator|&&
name|role
operator|==
name|Qt
operator|::
name|EditRole
condition|)
block|{
name|int
name|row
init|=
name|index
operator|.
name|row
argument_list|()
decl_stmt|;
name|QPair
argument_list|<
name|QString
argument_list|,
name|QString
argument_list|>
name|p
init|=
name|listOfPairs
operator|.
name|value
argument_list|(
name|row
argument_list|)
decl_stmt|;
if|if
condition|(
name|index
operator|.
name|column
argument_list|()
operator|==
literal|0
condition|)
name|p
operator|.
name|first
operator|=
name|value
operator|.
name|toString
argument_list|()
expr_stmt|;
elseif|else
if|if
condition|(
name|index
operator|.
name|column
argument_list|()
operator|==
literal|1
condition|)
name|p
operator|.
name|second
operator|=
name|value
operator|.
name|toString
argument_list|()
expr_stmt|;
else|else
return|return
literal|false
return|;
name|listOfPairs
operator|.
name|replace
argument_list|(
name|row
argument_list|,
name|p
argument_list|)
expr_stmt|;
emit|emit
operator|(
name|dataChanged
argument_list|(
name|index
argument_list|,
name|index
argument_list|)
operator|)
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
comment|//! [6]
end_comment
begin_comment
comment|//! [7]
end_comment
begin_function
DECL|function|flags
name|Qt
operator|::
name|ItemFlags
name|TableModel
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
name|Qt
operator|::
name|ItemIsEnabled
return|;
return|return
name|QAbstractTableModel
operator|::
name|flags
argument_list|(
name|index
argument_list|)
operator||
name|Qt
operator|::
name|ItemIsEditable
return|;
block|}
end_function
begin_comment
comment|//! [7]
end_comment
begin_comment
comment|//! [8]
end_comment
begin_function
DECL|function|getList
name|QList
argument_list|<
name|QPair
argument_list|<
name|QString
argument_list|,
name|QString
argument_list|>
argument_list|>
name|TableModel
operator|::
name|getList
parameter_list|()
block|{
return|return
name|listOfPairs
return|;
block|}
end_function
begin_comment
comment|//! [8]
end_comment
end_unit
