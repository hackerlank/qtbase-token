begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of Nokia Corporation and its Subsidiary(-ies) nor **     the names of its contributors may be used to endorse or promote **     products derived from this software without specific prior written **     permission. ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtGui>
end_include
begin_include
include|#
directive|include
file|"piecesmodel.h"
end_include
begin_constructor
DECL|function|PiecesModel
name|PiecesModel
operator|::
name|PiecesModel
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
begin_function
DECL|function|data
name|QVariant
name|PiecesModel
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
name|role
operator|==
name|Qt
operator|::
name|DecorationRole
condition|)
return|return
name|QIcon
argument_list|(
name|pixmaps
operator|.
name|value
argument_list|(
name|index
operator|.
name|row
argument_list|()
argument_list|)
operator|.
name|scaled
argument_list|(
literal|60
argument_list|,
literal|60
argument_list|,
name|Qt
operator|::
name|KeepAspectRatio
argument_list|,
name|Qt
operator|::
name|SmoothTransformation
argument_list|)
argument_list|)
return|;
elseif|else
if|if
condition|(
name|role
operator|==
name|Qt
operator|::
name|UserRole
condition|)
return|return
name|pixmaps
operator|.
name|value
argument_list|(
name|index
operator|.
name|row
argument_list|()
argument_list|)
return|;
elseif|else
if|if
condition|(
name|role
operator|==
name|Qt
operator|::
name|UserRole
operator|+
literal|1
condition|)
return|return
name|locations
operator|.
name|value
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
begin_function
DECL|function|addPiece
name|void
name|PiecesModel
operator|::
name|addPiece
parameter_list|(
specifier|const
name|QPixmap
modifier|&
name|pixmap
parameter_list|,
specifier|const
name|QPoint
modifier|&
name|location
parameter_list|)
block|{
name|int
name|row
decl_stmt|;
if|if
condition|(
name|int
argument_list|(
literal|2.0
operator|*
name|qrand
argument_list|()
operator|/
operator|(
name|RAND_MAX
operator|+
literal|1.0
operator|)
argument_list|)
operator|==
literal|1
condition|)
name|row
operator|=
literal|0
expr_stmt|;
else|else
name|row
operator|=
name|pixmaps
operator|.
name|size
argument_list|()
expr_stmt|;
name|beginInsertRows
argument_list|(
name|QModelIndex
argument_list|()
argument_list|,
name|row
argument_list|,
name|row
argument_list|)
expr_stmt|;
name|pixmaps
operator|.
name|insert
argument_list|(
name|row
argument_list|,
name|pixmap
argument_list|)
expr_stmt|;
name|locations
operator|.
name|insert
argument_list|(
name|row
argument_list|,
name|location
argument_list|)
expr_stmt|;
name|endInsertRows
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|flags
name|Qt
operator|::
name|ItemFlags
name|PiecesModel
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
name|index
operator|.
name|isValid
argument_list|()
condition|)
return|return
operator|(
name|Qt
operator|::
name|ItemIsEnabled
operator||
name|Qt
operator|::
name|ItemIsSelectable
operator||
name|Qt
operator|::
name|ItemIsDragEnabled
operator|)
return|;
return|return
name|Qt
operator|::
name|ItemIsDropEnabled
return|;
block|}
end_function
begin_function
DECL|function|removeRows
name|bool
name|PiecesModel
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
name|parent
operator|.
name|isValid
argument_list|()
condition|)
return|return
literal|false
return|;
if|if
condition|(
name|row
operator|>=
name|pixmaps
operator|.
name|size
argument_list|()
operator|||
name|row
operator|+
name|count
operator|<=
literal|0
condition|)
return|return
literal|false
return|;
name|int
name|beginRow
init|=
name|qMax
argument_list|(
literal|0
argument_list|,
name|row
argument_list|)
decl_stmt|;
name|int
name|endRow
init|=
name|qMin
argument_list|(
name|row
operator|+
name|count
operator|-
literal|1
argument_list|,
name|pixmaps
operator|.
name|size
argument_list|()
operator|-
literal|1
argument_list|)
decl_stmt|;
name|beginRemoveRows
argument_list|(
name|parent
argument_list|,
name|beginRow
argument_list|,
name|endRow
argument_list|)
expr_stmt|;
while|while
condition|(
name|beginRow
operator|<=
name|endRow
condition|)
block|{
name|pixmaps
operator|.
name|removeAt
argument_list|(
name|beginRow
argument_list|)
expr_stmt|;
name|locations
operator|.
name|removeAt
argument_list|(
name|beginRow
argument_list|)
expr_stmt|;
operator|++
name|beginRow
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
begin_function
DECL|function|mimeTypes
name|QStringList
name|PiecesModel
operator|::
name|mimeTypes
parameter_list|()
specifier|const
block|{
name|QStringList
name|types
decl_stmt|;
name|types
operator|<<
literal|"image/x-puzzle-piece"
expr_stmt|;
return|return
name|types
return|;
block|}
end_function
begin_function
DECL|function|mimeData
name|QMimeData
modifier|*
name|PiecesModel
operator|::
name|mimeData
parameter_list|(
specifier|const
name|QModelIndexList
modifier|&
name|indexes
parameter_list|)
specifier|const
block|{
name|QMimeData
modifier|*
name|mimeData
init|=
operator|new
name|QMimeData
argument_list|()
decl_stmt|;
name|QByteArray
name|encodedData
decl_stmt|;
name|QDataStream
name|stream
argument_list|(
operator|&
name|encodedData
argument_list|,
name|QIODevice
operator|::
name|WriteOnly
argument_list|)
decl_stmt|;
foreach|foreach
control|(
name|QModelIndex
name|index
decl|,
name|indexes
control|)
block|{
if|if
condition|(
name|index
operator|.
name|isValid
argument_list|()
condition|)
block|{
name|QPixmap
name|pixmap
init|=
name|qvariant_cast
argument_list|<
name|QPixmap
argument_list|>
argument_list|(
name|data
argument_list|(
name|index
argument_list|,
name|Qt
operator|::
name|UserRole
argument_list|)
argument_list|)
decl_stmt|;
name|QPoint
name|location
init|=
name|data
argument_list|(
name|index
argument_list|,
name|Qt
operator|::
name|UserRole
operator|+
literal|1
argument_list|)
operator|.
name|toPoint
argument_list|()
decl_stmt|;
name|stream
operator|<<
name|pixmap
operator|<<
name|location
expr_stmt|;
block|}
block|}
name|mimeData
operator|->
name|setData
argument_list|(
literal|"image/x-puzzle-piece"
argument_list|,
name|encodedData
argument_list|)
expr_stmt|;
return|return
name|mimeData
return|;
block|}
end_function
begin_function
DECL|function|dropMimeData
name|bool
name|PiecesModel
operator|::
name|dropMimeData
parameter_list|(
specifier|const
name|QMimeData
modifier|*
name|data
parameter_list|,
name|Qt
operator|::
name|DropAction
name|action
parameter_list|,
name|int
name|row
parameter_list|,
name|int
name|column
parameter_list|,
specifier|const
name|QModelIndex
modifier|&
name|parent
parameter_list|)
block|{
if|if
condition|(
operator|!
name|data
operator|->
name|hasFormat
argument_list|(
literal|"image/x-puzzle-piece"
argument_list|)
condition|)
return|return
literal|false
return|;
if|if
condition|(
name|action
operator|==
name|Qt
operator|::
name|IgnoreAction
condition|)
return|return
literal|true
return|;
if|if
condition|(
name|column
operator|>
literal|0
condition|)
return|return
literal|false
return|;
name|int
name|endRow
decl_stmt|;
if|if
condition|(
operator|!
name|parent
operator|.
name|isValid
argument_list|()
condition|)
block|{
if|if
condition|(
name|row
operator|<
literal|0
condition|)
name|endRow
operator|=
name|pixmaps
operator|.
name|size
argument_list|()
expr_stmt|;
else|else
name|endRow
operator|=
name|qMin
argument_list|(
name|row
argument_list|,
name|pixmaps
operator|.
name|size
argument_list|()
argument_list|)
expr_stmt|;
block|}
else|else
name|endRow
operator|=
name|parent
operator|.
name|row
argument_list|()
expr_stmt|;
name|QByteArray
name|encodedData
init|=
name|data
operator|->
name|data
argument_list|(
literal|"image/x-puzzle-piece"
argument_list|)
decl_stmt|;
name|QDataStream
name|stream
argument_list|(
operator|&
name|encodedData
argument_list|,
name|QIODevice
operator|::
name|ReadOnly
argument_list|)
decl_stmt|;
while|while
condition|(
operator|!
name|stream
operator|.
name|atEnd
argument_list|()
condition|)
block|{
name|QPixmap
name|pixmap
decl_stmt|;
name|QPoint
name|location
decl_stmt|;
name|stream
operator|>>
name|pixmap
operator|>>
name|location
expr_stmt|;
name|beginInsertRows
argument_list|(
name|QModelIndex
argument_list|()
argument_list|,
name|endRow
argument_list|,
name|endRow
argument_list|)
expr_stmt|;
name|pixmaps
operator|.
name|insert
argument_list|(
name|endRow
argument_list|,
name|pixmap
argument_list|)
expr_stmt|;
name|locations
operator|.
name|insert
argument_list|(
name|endRow
argument_list|,
name|location
argument_list|)
expr_stmt|;
name|endInsertRows
argument_list|()
expr_stmt|;
operator|++
name|endRow
expr_stmt|;
block|}
return|return
literal|true
return|;
block|}
end_function
begin_function
DECL|function|rowCount
name|int
name|PiecesModel
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
else|else
return|return
name|pixmaps
operator|.
name|size
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|supportedDropActions
name|Qt
operator|::
name|DropActions
name|PiecesModel
operator|::
name|supportedDropActions
parameter_list|()
specifier|const
block|{
return|return
name|Qt
operator|::
name|CopyAction
operator||
name|Qt
operator|::
name|MoveAction
return|;
block|}
end_function
begin_function
DECL|function|addPieces
name|void
name|PiecesModel
operator|::
name|addPieces
parameter_list|(
specifier|const
name|QPixmap
modifier|&
name|pixmap
parameter_list|)
block|{
name|beginRemoveRows
argument_list|(
name|QModelIndex
argument_list|()
argument_list|,
literal|0
argument_list|,
literal|24
argument_list|)
expr_stmt|;
name|pixmaps
operator|.
name|clear
argument_list|()
expr_stmt|;
name|locations
operator|.
name|clear
argument_list|()
expr_stmt|;
name|endRemoveRows
argument_list|()
expr_stmt|;
for|for
control|(
name|int
name|y
init|=
literal|0
init|;
name|y
operator|<
literal|5
condition|;
operator|++
name|y
control|)
block|{
for|for
control|(
name|int
name|x
init|=
literal|0
init|;
name|x
operator|<
literal|5
condition|;
operator|++
name|x
control|)
block|{
name|QPixmap
name|pieceImage
init|=
name|pixmap
operator|.
name|copy
argument_list|(
name|x
operator|*
literal|80
argument_list|,
name|y
operator|*
literal|80
argument_list|,
literal|80
argument_list|,
literal|80
argument_list|)
decl_stmt|;
name|addPiece
argument_list|(
name|pieceImage
argument_list|,
name|QPoint
argument_list|(
name|x
argument_list|,
name|y
argument_list|)
argument_list|)
expr_stmt|;
block|}
block|}
block|}
end_function
end_unit
