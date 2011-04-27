begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of Nokia Corporation and its Subsidiary(-ies) nor **     the names of its contributors may be used to endorse or promote **     products derived from this software without specific prior written **     permission. ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"mainwindow.h"
end_include
begin_include
include|#
directive|include
file|"dialog.h"
end_include
begin_include
include|#
directive|include
file|<QtGui>
end_include
begin_include
include|#
directive|include
file|<QtSql>
end_include
begin_include
include|#
directive|include
file|<QtXml>
end_include
begin_decl_stmt
specifier|extern
name|int
name|uniqueAlbumId
decl_stmt|;
end_decl_stmt
begin_decl_stmt
specifier|extern
name|int
name|uniqueArtistId
decl_stmt|;
end_decl_stmt
begin_constructor
DECL|function|MainWindow
name|MainWindow
operator|::
name|MainWindow
parameter_list|(
specifier|const
name|QString
modifier|&
name|artistTable
parameter_list|,
specifier|const
name|QString
modifier|&
name|albumTable
parameter_list|,
name|QFile
modifier|*
name|albumDetails
parameter_list|,
name|QWidget
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QMainWindow
argument_list|(
name|parent
argument_list|)
block|{
name|file
operator|=
name|albumDetails
expr_stmt|;
name|readAlbumData
argument_list|()
expr_stmt|;
name|model
operator|=
operator|new
name|QSqlRelationalTableModel
argument_list|(
name|this
argument_list|)
expr_stmt|;
name|model
operator|->
name|setTable
argument_list|(
name|albumTable
argument_list|)
expr_stmt|;
name|model
operator|->
name|setRelation
argument_list|(
literal|2
argument_list|,
name|QSqlRelation
argument_list|(
name|artistTable
argument_list|,
literal|"id"
argument_list|,
literal|"artist"
argument_list|)
argument_list|)
expr_stmt|;
name|model
operator|->
name|select
argument_list|()
expr_stmt|;
name|QGroupBox
modifier|*
name|artists
init|=
name|createArtistGroupBox
argument_list|()
decl_stmt|;
name|QGroupBox
modifier|*
name|albums
init|=
name|createAlbumGroupBox
argument_list|()
decl_stmt|;
name|QGroupBox
modifier|*
name|details
init|=
name|createDetailsGroupBox
argument_list|()
decl_stmt|;
name|artistView
operator|->
name|setCurrentIndex
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|uniqueAlbumId
operator|=
name|model
operator|->
name|rowCount
argument_list|()
expr_stmt|;
name|uniqueArtistId
operator|=
name|artistView
operator|->
name|count
argument_list|()
expr_stmt|;
name|connect
argument_list|(
name|model
argument_list|,
name|SIGNAL
argument_list|(
name|rowsInserted
argument_list|(
name|QModelIndex
argument_list|,
name|int
argument_list|,
name|int
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|updateHeader
argument_list|(
name|QModelIndex
argument_list|,
name|int
argument_list|,
name|int
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|model
argument_list|,
name|SIGNAL
argument_list|(
name|rowsRemoved
argument_list|(
name|QModelIndex
argument_list|,
name|int
argument_list|,
name|int
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|updateHeader
argument_list|(
name|QModelIndex
argument_list|,
name|int
argument_list|,
name|int
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|QGridLayout
modifier|*
name|layout
init|=
operator|new
name|QGridLayout
decl_stmt|;
name|layout
operator|->
name|addWidget
argument_list|(
name|artists
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|layout
operator|->
name|addWidget
argument_list|(
name|albums
argument_list|,
literal|1
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|layout
operator|->
name|addWidget
argument_list|(
name|details
argument_list|,
literal|0
argument_list|,
literal|1
argument_list|,
literal|2
argument_list|,
literal|1
argument_list|)
expr_stmt|;
if|#
directive|if
operator|!
name|defined
argument_list|(
name|Q_OS_SYMBIAN
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|Q_WS_MAEMO_5
argument_list|)
name|layout
operator|->
name|setColumnStretch
argument_list|(
literal|1
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|layout
operator|->
name|setColumnMinimumWidth
argument_list|(
literal|0
argument_list|,
literal|500
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|QWidget
modifier|*
name|widget
init|=
operator|new
name|QWidget
decl_stmt|;
name|widget
operator|->
name|setLayout
argument_list|(
name|layout
argument_list|)
expr_stmt|;
name|setCentralWidget
argument_list|(
name|widget
argument_list|)
expr_stmt|;
name|createMenuBar
argument_list|()
expr_stmt|;
name|showImageLabel
argument_list|()
expr_stmt|;
if|#
directive|if
operator|!
name|defined
argument_list|(
name|Q_OS_SYMBIAN
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|Q_WS_MAEMO_5
argument_list|)
name|resize
argument_list|(
literal|850
argument_list|,
literal|400
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|setWindowTitle
argument_list|(
name|tr
argument_list|(
literal|"Music Archive"
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_function
DECL|function|changeArtist
name|void
name|MainWindow
operator|::
name|changeArtist
parameter_list|(
name|int
name|row
parameter_list|)
block|{
if|if
condition|(
name|row
operator|>
literal|0
condition|)
block|{
name|QModelIndex
name|index
init|=
name|model
operator|->
name|relationModel
argument_list|(
literal|2
argument_list|)
operator|->
name|index
argument_list|(
name|row
argument_list|,
literal|1
argument_list|)
decl_stmt|;
name|model
operator|->
name|setFilter
argument_list|(
literal|"artist = '"
operator|+
name|index
operator|.
name|data
argument_list|()
operator|.
name|toString
argument_list|()
operator|+
literal|'\''
argument_list|)
expr_stmt|;
name|showArtistProfile
argument_list|(
name|index
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|row
operator|==
literal|0
condition|)
block|{
name|model
operator|->
name|setFilter
argument_list|(
name|QString
argument_list|()
argument_list|)
expr_stmt|;
name|showImageLabel
argument_list|()
expr_stmt|;
block|}
else|else
block|{
return|return;
block|}
block|}
end_function
begin_function
DECL|function|showArtistProfile
name|void
name|MainWindow
operator|::
name|showArtistProfile
parameter_list|(
name|QModelIndex
name|index
parameter_list|)
block|{
name|QSqlRecord
name|record
init|=
name|model
operator|->
name|relationModel
argument_list|(
literal|2
argument_list|)
operator|->
name|record
argument_list|(
name|index
operator|.
name|row
argument_list|()
argument_list|)
decl_stmt|;
name|QString
name|name
init|=
name|record
operator|.
name|value
argument_list|(
literal|"artist"
argument_list|)
operator|.
name|toString
argument_list|()
decl_stmt|;
name|QString
name|count
init|=
name|record
operator|.
name|value
argument_list|(
literal|"albumcount"
argument_list|)
operator|.
name|toString
argument_list|()
decl_stmt|;
name|profileLabel
operator|->
name|setText
argument_list|(
name|tr
argument_list|(
literal|"Artist : %1 \n"
expr|\
literal|"Number of Albums: %2"
argument_list|)
operator|.
name|arg
argument_list|(
name|name
argument_list|)
operator|.
name|arg
argument_list|(
name|count
argument_list|)
argument_list|)
expr_stmt|;
name|profileLabel
operator|->
name|show
argument_list|()
expr_stmt|;
name|iconLabel
operator|->
name|show
argument_list|()
expr_stmt|;
name|titleLabel
operator|->
name|hide
argument_list|()
expr_stmt|;
name|trackList
operator|->
name|hide
argument_list|()
expr_stmt|;
name|imageLabel
operator|->
name|hide
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|showAlbumDetails
name|void
name|MainWindow
operator|::
name|showAlbumDetails
parameter_list|(
name|QModelIndex
name|index
parameter_list|)
block|{
name|QSqlRecord
name|record
init|=
name|model
operator|->
name|record
argument_list|(
name|index
operator|.
name|row
argument_list|()
argument_list|)
decl_stmt|;
name|QString
name|artist
init|=
name|record
operator|.
name|value
argument_list|(
literal|"artist"
argument_list|)
operator|.
name|toString
argument_list|()
decl_stmt|;
name|QString
name|title
init|=
name|record
operator|.
name|value
argument_list|(
literal|"title"
argument_list|)
operator|.
name|toString
argument_list|()
decl_stmt|;
name|QString
name|year
init|=
name|record
operator|.
name|value
argument_list|(
literal|"year"
argument_list|)
operator|.
name|toString
argument_list|()
decl_stmt|;
name|QString
name|albumId
init|=
name|record
operator|.
name|value
argument_list|(
literal|"albumid"
argument_list|)
operator|.
name|toString
argument_list|()
decl_stmt|;
name|showArtistProfile
argument_list|(
name|indexOfArtist
argument_list|(
name|artist
argument_list|)
argument_list|)
expr_stmt|;
name|titleLabel
operator|->
name|setText
argument_list|(
name|tr
argument_list|(
literal|"Title: %1 (%2)"
argument_list|)
operator|.
name|arg
argument_list|(
name|title
argument_list|)
operator|.
name|arg
argument_list|(
name|year
argument_list|)
argument_list|)
expr_stmt|;
name|titleLabel
operator|->
name|show
argument_list|()
expr_stmt|;
name|QDomNodeList
name|albums
init|=
name|albumData
operator|.
name|elementsByTagName
argument_list|(
literal|"album"
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
name|albums
operator|.
name|count
argument_list|()
condition|;
name|i
operator|++
control|)
block|{
name|QDomNode
name|album
init|=
name|albums
operator|.
name|item
argument_list|(
name|i
argument_list|)
decl_stmt|;
if|if
condition|(
name|album
operator|.
name|toElement
argument_list|()
operator|.
name|attribute
argument_list|(
literal|"id"
argument_list|)
operator|==
name|albumId
condition|)
block|{
name|getTrackList
argument_list|(
name|album
operator|.
name|toElement
argument_list|()
argument_list|)
expr_stmt|;
break|break;
block|}
block|}
if|if
condition|(
operator|!
name|trackList
operator|->
name|count
argument_list|()
operator|==
literal|0
condition|)
name|trackList
operator|->
name|show
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|getTrackList
name|void
name|MainWindow
operator|::
name|getTrackList
parameter_list|(
name|QDomNode
name|album
parameter_list|)
block|{
name|trackList
operator|->
name|clear
argument_list|()
expr_stmt|;
name|QDomNodeList
name|tracks
init|=
name|album
operator|.
name|childNodes
argument_list|()
decl_stmt|;
name|QDomNode
name|track
decl_stmt|;
name|QString
name|trackNumber
decl_stmt|;
for|for
control|(
name|int
name|j
init|=
literal|0
init|;
name|j
operator|<
name|tracks
operator|.
name|count
argument_list|()
condition|;
name|j
operator|++
control|)
block|{
name|track
operator|=
name|tracks
operator|.
name|item
argument_list|(
name|j
argument_list|)
expr_stmt|;
name|trackNumber
operator|=
name|track
operator|.
name|toElement
argument_list|()
operator|.
name|attribute
argument_list|(
literal|"number"
argument_list|)
expr_stmt|;
name|QListWidgetItem
modifier|*
name|item
init|=
operator|new
name|QListWidgetItem
argument_list|(
name|trackList
argument_list|)
decl_stmt|;
name|item
operator|->
name|setText
argument_list|(
name|trackNumber
operator|+
literal|": "
operator|+
name|track
operator|.
name|toElement
argument_list|()
operator|.
name|text
argument_list|()
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|addAlbum
name|void
name|MainWindow
operator|::
name|addAlbum
parameter_list|()
block|{
name|Dialog
modifier|*
name|dialog
init|=
operator|new
name|Dialog
argument_list|(
name|model
argument_list|,
name|albumData
argument_list|,
name|file
argument_list|,
name|this
argument_list|)
decl_stmt|;
name|int
name|accepted
init|=
name|dialog
operator|->
name|exec
argument_list|()
decl_stmt|;
if|if
condition|(
name|accepted
operator|==
literal|1
condition|)
block|{
name|int
name|lastRow
init|=
name|model
operator|->
name|rowCount
argument_list|()
operator|-
literal|1
decl_stmt|;
name|albumView
operator|->
name|selectRow
argument_list|(
name|lastRow
argument_list|)
expr_stmt|;
name|albumView
operator|->
name|scrollToBottom
argument_list|()
expr_stmt|;
name|showAlbumDetails
argument_list|(
name|model
operator|->
name|index
argument_list|(
name|lastRow
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|deleteAlbum
name|void
name|MainWindow
operator|::
name|deleteAlbum
parameter_list|()
block|{
name|QModelIndexList
name|selection
init|=
name|albumView
operator|->
name|selectionModel
argument_list|()
operator|->
name|selectedRows
argument_list|(
literal|0
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|selection
operator|.
name|empty
argument_list|()
condition|)
block|{
name|QModelIndex
name|idIndex
init|=
name|selection
operator|.
name|at
argument_list|(
literal|0
argument_list|)
decl_stmt|;
name|int
name|id
init|=
name|idIndex
operator|.
name|data
argument_list|()
operator|.
name|toInt
argument_list|()
decl_stmt|;
name|QString
name|title
init|=
name|idIndex
operator|.
name|sibling
argument_list|(
name|idIndex
operator|.
name|row
argument_list|()
argument_list|,
literal|1
argument_list|)
operator|.
name|data
argument_list|()
operator|.
name|toString
argument_list|()
decl_stmt|;
name|QString
name|artist
init|=
name|idIndex
operator|.
name|sibling
argument_list|(
name|idIndex
operator|.
name|row
argument_list|()
argument_list|,
literal|2
argument_list|)
operator|.
name|data
argument_list|()
operator|.
name|toString
argument_list|()
decl_stmt|;
name|QMessageBox
operator|::
name|StandardButton
name|button
decl_stmt|;
name|button
operator|=
name|QMessageBox
operator|::
name|question
argument_list|(
name|this
argument_list|,
name|tr
argument_list|(
literal|"Delete Album"
argument_list|)
argument_list|,
name|tr
argument_list|(
literal|"Are you sure you want to "
literal|"delete '%1' by '%2'?"
argument_list|)
operator|.
name|arg
argument_list|(
name|title
argument_list|,
name|artist
argument_list|)
argument_list|,
name|QMessageBox
operator|::
name|Yes
operator||
name|QMessageBox
operator|::
name|No
argument_list|)
expr_stmt|;
if|if
condition|(
name|button
operator|==
name|QMessageBox
operator|::
name|Yes
condition|)
block|{
name|removeAlbumFromFile
argument_list|(
name|id
argument_list|)
expr_stmt|;
name|removeAlbumFromDatabase
argument_list|(
name|idIndex
argument_list|)
expr_stmt|;
name|decreaseAlbumCount
argument_list|(
name|indexOfArtist
argument_list|(
name|artist
argument_list|)
argument_list|)
expr_stmt|;
name|showImageLabel
argument_list|()
expr_stmt|;
block|}
block|}
else|else
block|{
name|QMessageBox
operator|::
name|information
argument_list|(
name|this
argument_list|,
name|tr
argument_list|(
literal|"Delete Album"
argument_list|)
argument_list|,
name|tr
argument_list|(
literal|"Select the album you want to delete."
argument_list|)
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|removeAlbumFromFile
name|void
name|MainWindow
operator|::
name|removeAlbumFromFile
parameter_list|(
name|int
name|id
parameter_list|)
block|{
name|QDomNodeList
name|albums
init|=
name|albumData
operator|.
name|elementsByTagName
argument_list|(
literal|"album"
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
name|albums
operator|.
name|count
argument_list|()
condition|;
name|i
operator|++
control|)
block|{
name|QDomNode
name|node
init|=
name|albums
operator|.
name|item
argument_list|(
name|i
argument_list|)
decl_stmt|;
if|if
condition|(
name|node
operator|.
name|toElement
argument_list|()
operator|.
name|attribute
argument_list|(
literal|"id"
argument_list|)
operator|.
name|toInt
argument_list|()
operator|==
name|id
condition|)
block|{
name|albumData
operator|.
name|elementsByTagName
argument_list|(
literal|"archive"
argument_list|)
operator|.
name|item
argument_list|(
literal|0
argument_list|)
operator|.
name|removeChild
argument_list|(
name|node
argument_list|)
expr_stmt|;
break|break;
block|}
block|}
comment|/*     The following code is commented out since the example uses an in     memory database, i.e., altering the XML file will bring the data     out of sync.      if (!file->open(QIODevice::WriteOnly)) {         return;     } else {         QTextStream stream(file);         albumData.elementsByTagName("archive").item(0).save(stream, 4);         file->close();     } */
block|}
end_function
begin_function
DECL|function|removeAlbumFromDatabase
name|void
name|MainWindow
operator|::
name|removeAlbumFromDatabase
parameter_list|(
name|QModelIndex
name|index
parameter_list|)
block|{
name|model
operator|->
name|removeRow
argument_list|(
name|index
operator|.
name|row
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|decreaseAlbumCount
name|void
name|MainWindow
operator|::
name|decreaseAlbumCount
parameter_list|(
name|QModelIndex
name|artistIndex
parameter_list|)
block|{
name|int
name|row
init|=
name|artistIndex
operator|.
name|row
argument_list|()
decl_stmt|;
name|QModelIndex
name|albumCountIndex
init|=
name|artistIndex
operator|.
name|sibling
argument_list|(
name|row
argument_list|,
literal|2
argument_list|)
decl_stmt|;
name|int
name|albumCount
init|=
name|albumCountIndex
operator|.
name|data
argument_list|()
operator|.
name|toInt
argument_list|()
decl_stmt|;
name|QSqlTableModel
modifier|*
name|artists
init|=
name|model
operator|->
name|relationModel
argument_list|(
literal|2
argument_list|)
decl_stmt|;
if|if
condition|(
name|albumCount
operator|==
literal|1
condition|)
block|{
name|artists
operator|->
name|removeRow
argument_list|(
name|row
argument_list|)
expr_stmt|;
name|showImageLabel
argument_list|()
expr_stmt|;
block|}
else|else
block|{
name|artists
operator|->
name|setData
argument_list|(
name|albumCountIndex
argument_list|,
name|QVariant
argument_list|(
name|albumCount
operator|-
literal|1
argument_list|)
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|readAlbumData
name|void
name|MainWindow
operator|::
name|readAlbumData
parameter_list|()
block|{
if|if
condition|(
operator|!
name|file
operator|->
name|open
argument_list|(
name|QIODevice
operator|::
name|ReadOnly
argument_list|)
condition|)
return|return;
if|if
condition|(
operator|!
name|albumData
operator|.
name|setContent
argument_list|(
name|file
argument_list|)
condition|)
block|{
name|file
operator|->
name|close
argument_list|()
expr_stmt|;
return|return;
block|}
name|file
operator|->
name|close
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|createArtistGroupBox
name|QGroupBox
modifier|*
name|MainWindow
operator|::
name|createArtistGroupBox
parameter_list|()
block|{
name|artistView
operator|=
operator|new
name|QComboBox
expr_stmt|;
name|artistView
operator|->
name|setModel
argument_list|(
name|model
operator|->
name|relationModel
argument_list|(
literal|2
argument_list|)
argument_list|)
expr_stmt|;
name|artistView
operator|->
name|setModelColumn
argument_list|(
literal|1
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|artistView
argument_list|,
name|SIGNAL
argument_list|(
name|currentIndexChanged
argument_list|(
name|int
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|changeArtist
argument_list|(
name|int
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|QGroupBox
modifier|*
name|box
init|=
operator|new
name|QGroupBox
argument_list|(
name|tr
argument_list|(
literal|"Artist"
argument_list|)
argument_list|)
decl_stmt|;
name|QGridLayout
modifier|*
name|layout
init|=
operator|new
name|QGridLayout
decl_stmt|;
name|layout
operator|->
name|addWidget
argument_list|(
name|artistView
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|box
operator|->
name|setLayout
argument_list|(
name|layout
argument_list|)
expr_stmt|;
return|return
name|box
return|;
block|}
end_function
begin_function
DECL|function|createAlbumGroupBox
name|QGroupBox
modifier|*
name|MainWindow
operator|::
name|createAlbumGroupBox
parameter_list|()
block|{
name|QGroupBox
modifier|*
name|box
init|=
operator|new
name|QGroupBox
argument_list|(
name|tr
argument_list|(
literal|"Album"
argument_list|)
argument_list|)
decl_stmt|;
name|albumView
operator|=
operator|new
name|QTableView
expr_stmt|;
name|albumView
operator|->
name|setEditTriggers
argument_list|(
name|QAbstractItemView
operator|::
name|NoEditTriggers
argument_list|)
expr_stmt|;
name|albumView
operator|->
name|setSortingEnabled
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|albumView
operator|->
name|setSelectionBehavior
argument_list|(
name|QAbstractItemView
operator|::
name|SelectRows
argument_list|)
expr_stmt|;
name|albumView
operator|->
name|setSelectionMode
argument_list|(
name|QAbstractItemView
operator|::
name|SingleSelection
argument_list|)
expr_stmt|;
name|albumView
operator|->
name|setShowGrid
argument_list|(
literal|false
argument_list|)
expr_stmt|;
name|albumView
operator|->
name|verticalHeader
argument_list|()
operator|->
name|hide
argument_list|()
expr_stmt|;
name|albumView
operator|->
name|setAlternatingRowColors
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|albumView
operator|->
name|setModel
argument_list|(
name|model
argument_list|)
expr_stmt|;
name|adjustHeader
argument_list|()
expr_stmt|;
name|QLocale
name|locale
init|=
name|albumView
operator|->
name|locale
argument_list|()
decl_stmt|;
name|locale
operator|.
name|setNumberOptions
argument_list|(
name|QLocale
operator|::
name|OmitGroupSeparator
argument_list|)
expr_stmt|;
name|albumView
operator|->
name|setLocale
argument_list|(
name|locale
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|albumView
argument_list|,
name|SIGNAL
argument_list|(
name|clicked
argument_list|(
name|QModelIndex
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|showAlbumDetails
argument_list|(
name|QModelIndex
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|albumView
argument_list|,
name|SIGNAL
argument_list|(
name|activated
argument_list|(
name|QModelIndex
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|showAlbumDetails
argument_list|(
name|QModelIndex
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|QVBoxLayout
modifier|*
name|layout
init|=
operator|new
name|QVBoxLayout
decl_stmt|;
name|layout
operator|->
name|addWidget
argument_list|(
name|albumView
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|box
operator|->
name|setLayout
argument_list|(
name|layout
argument_list|)
expr_stmt|;
return|return
name|box
return|;
block|}
end_function
begin_function
DECL|function|createDetailsGroupBox
name|QGroupBox
modifier|*
name|MainWindow
operator|::
name|createDetailsGroupBox
parameter_list|()
block|{
name|QGroupBox
modifier|*
name|box
init|=
operator|new
name|QGroupBox
argument_list|(
name|tr
argument_list|(
literal|"Details"
argument_list|)
argument_list|)
decl_stmt|;
name|profileLabel
operator|=
operator|new
name|QLabel
expr_stmt|;
name|profileLabel
operator|->
name|setWordWrap
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|profileLabel
operator|->
name|setAlignment
argument_list|(
name|Qt
operator|::
name|AlignBottom
argument_list|)
expr_stmt|;
name|titleLabel
operator|=
operator|new
name|QLabel
expr_stmt|;
name|titleLabel
operator|->
name|setWordWrap
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|titleLabel
operator|->
name|setAlignment
argument_list|(
name|Qt
operator|::
name|AlignBottom
argument_list|)
expr_stmt|;
name|iconLabel
operator|=
operator|new
name|QLabel
argument_list|()
expr_stmt|;
name|iconLabel
operator|->
name|setAlignment
argument_list|(
name|Qt
operator|::
name|AlignBottom
operator||
name|Qt
operator|::
name|AlignRight
argument_list|)
expr_stmt|;
name|iconLabel
operator|->
name|setPixmap
argument_list|(
name|QPixmap
argument_list|(
literal|":/images/icon.png"
argument_list|)
argument_list|)
expr_stmt|;
name|imageLabel
operator|=
operator|new
name|QLabel
expr_stmt|;
name|imageLabel
operator|->
name|setWordWrap
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|imageLabel
operator|->
name|setAlignment
argument_list|(
name|Qt
operator|::
name|AlignCenter
argument_list|)
expr_stmt|;
name|imageLabel
operator|->
name|setPixmap
argument_list|(
name|QPixmap
argument_list|(
literal|":/images/image.png"
argument_list|)
argument_list|)
expr_stmt|;
name|trackList
operator|=
operator|new
name|QListWidget
expr_stmt|;
name|QGridLayout
modifier|*
name|layout
init|=
operator|new
name|QGridLayout
decl_stmt|;
name|layout
operator|->
name|addWidget
argument_list|(
name|imageLabel
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|3
argument_list|,
literal|2
argument_list|)
expr_stmt|;
name|layout
operator|->
name|addWidget
argument_list|(
name|profileLabel
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|layout
operator|->
name|addWidget
argument_list|(
name|iconLabel
argument_list|,
literal|0
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|layout
operator|->
name|addWidget
argument_list|(
name|titleLabel
argument_list|,
literal|1
argument_list|,
literal|0
argument_list|,
literal|1
argument_list|,
literal|2
argument_list|)
expr_stmt|;
name|layout
operator|->
name|addWidget
argument_list|(
name|trackList
argument_list|,
literal|2
argument_list|,
literal|0
argument_list|,
literal|1
argument_list|,
literal|2
argument_list|)
expr_stmt|;
name|layout
operator|->
name|setRowStretch
argument_list|(
literal|2
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|box
operator|->
name|setLayout
argument_list|(
name|layout
argument_list|)
expr_stmt|;
return|return
name|box
return|;
block|}
end_function
begin_function
DECL|function|createMenuBar
name|void
name|MainWindow
operator|::
name|createMenuBar
parameter_list|()
block|{
name|QAction
modifier|*
name|addAction
init|=
operator|new
name|QAction
argument_list|(
name|tr
argument_list|(
literal|"&Add album..."
argument_list|)
argument_list|,
name|this
argument_list|)
decl_stmt|;
name|QAction
modifier|*
name|deleteAction
init|=
operator|new
name|QAction
argument_list|(
name|tr
argument_list|(
literal|"&Delete album..."
argument_list|)
argument_list|,
name|this
argument_list|)
decl_stmt|;
name|QAction
modifier|*
name|quitAction
init|=
operator|new
name|QAction
argument_list|(
name|tr
argument_list|(
literal|"&Quit"
argument_list|)
argument_list|,
name|this
argument_list|)
decl_stmt|;
name|QAction
modifier|*
name|aboutAction
init|=
operator|new
name|QAction
argument_list|(
name|tr
argument_list|(
literal|"&About"
argument_list|)
argument_list|,
name|this
argument_list|)
decl_stmt|;
name|QAction
modifier|*
name|aboutQtAction
init|=
operator|new
name|QAction
argument_list|(
name|tr
argument_list|(
literal|"About&Qt"
argument_list|)
argument_list|,
name|this
argument_list|)
decl_stmt|;
name|addAction
operator|->
name|setShortcut
argument_list|(
name|tr
argument_list|(
literal|"Ctrl+A"
argument_list|)
argument_list|)
expr_stmt|;
name|deleteAction
operator|->
name|setShortcut
argument_list|(
name|tr
argument_list|(
literal|"Ctrl+D"
argument_list|)
argument_list|)
expr_stmt|;
name|quitAction
operator|->
name|setShortcuts
argument_list|(
name|QKeySequence
operator|::
name|Quit
argument_list|)
expr_stmt|;
name|QMenu
modifier|*
name|fileMenu
init|=
name|menuBar
argument_list|()
operator|->
name|addMenu
argument_list|(
name|tr
argument_list|(
literal|"&File"
argument_list|)
argument_list|)
decl_stmt|;
name|fileMenu
operator|->
name|addAction
argument_list|(
name|addAction
argument_list|)
expr_stmt|;
name|fileMenu
operator|->
name|addAction
argument_list|(
name|deleteAction
argument_list|)
expr_stmt|;
name|fileMenu
operator|->
name|addSeparator
argument_list|()
expr_stmt|;
name|fileMenu
operator|->
name|addAction
argument_list|(
name|quitAction
argument_list|)
expr_stmt|;
name|QMenu
modifier|*
name|helpMenu
init|=
name|menuBar
argument_list|()
operator|->
name|addMenu
argument_list|(
name|tr
argument_list|(
literal|"&Help"
argument_list|)
argument_list|)
decl_stmt|;
name|helpMenu
operator|->
name|addAction
argument_list|(
name|aboutAction
argument_list|)
expr_stmt|;
name|helpMenu
operator|->
name|addAction
argument_list|(
name|aboutQtAction
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|addAction
argument_list|,
name|SIGNAL
argument_list|(
name|triggered
argument_list|(
name|bool
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|addAlbum
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|deleteAction
argument_list|,
name|SIGNAL
argument_list|(
name|triggered
argument_list|(
name|bool
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|deleteAlbum
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|quitAction
argument_list|,
name|SIGNAL
argument_list|(
name|triggered
argument_list|(
name|bool
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|close
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|aboutAction
argument_list|,
name|SIGNAL
argument_list|(
name|triggered
argument_list|(
name|bool
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|about
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|aboutQtAction
argument_list|,
name|SIGNAL
argument_list|(
name|triggered
argument_list|(
name|bool
argument_list|)
argument_list|)
argument_list|,
name|qApp
argument_list|,
name|SLOT
argument_list|(
name|aboutQt
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|showImageLabel
name|void
name|MainWindow
operator|::
name|showImageLabel
parameter_list|()
block|{
name|profileLabel
operator|->
name|hide
argument_list|()
expr_stmt|;
name|titleLabel
operator|->
name|hide
argument_list|()
expr_stmt|;
name|iconLabel
operator|->
name|hide
argument_list|()
expr_stmt|;
name|trackList
operator|->
name|hide
argument_list|()
expr_stmt|;
name|imageLabel
operator|->
name|show
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|indexOfArtist
name|QModelIndex
name|MainWindow
operator|::
name|indexOfArtist
parameter_list|(
specifier|const
name|QString
modifier|&
name|artist
parameter_list|)
block|{
name|QSqlTableModel
modifier|*
name|artistModel
init|=
name|model
operator|->
name|relationModel
argument_list|(
literal|2
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
name|artistModel
operator|->
name|rowCount
argument_list|()
condition|;
name|i
operator|++
control|)
block|{
name|QSqlRecord
name|record
init|=
name|artistModel
operator|->
name|record
argument_list|(
name|i
argument_list|)
decl_stmt|;
if|if
condition|(
name|record
operator|.
name|value
argument_list|(
literal|"artist"
argument_list|)
operator|==
name|artist
condition|)
return|return
name|artistModel
operator|->
name|index
argument_list|(
name|i
argument_list|,
literal|1
argument_list|)
return|;
block|}
return|return
name|QModelIndex
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|updateHeader
name|void
name|MainWindow
operator|::
name|updateHeader
parameter_list|(
name|QModelIndex
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
block|{
name|adjustHeader
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|adjustHeader
name|void
name|MainWindow
operator|::
name|adjustHeader
parameter_list|()
block|{
name|albumView
operator|->
name|hideColumn
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|albumView
operator|->
name|horizontalHeader
argument_list|()
operator|->
name|setResizeMode
argument_list|(
literal|1
argument_list|,
name|QHeaderView
operator|::
name|Stretch
argument_list|)
expr_stmt|;
name|albumView
operator|->
name|resizeColumnToContents
argument_list|(
literal|2
argument_list|)
expr_stmt|;
name|albumView
operator|->
name|resizeColumnToContents
argument_list|(
literal|3
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|about
name|void
name|MainWindow
operator|::
name|about
parameter_list|()
block|{
name|QMessageBox
operator|::
name|about
argument_list|(
name|this
argument_list|,
name|tr
argument_list|(
literal|"About Music Archive"
argument_list|)
argument_list|,
name|tr
argument_list|(
literal|"<p>The<b>Music Archive</b> example shows how to present "
literal|"data from different data sources in the same application. "
literal|"The album titles, and the corresponding artists and release dates, "
literal|"are kept in a database, while each album's tracks are stored "
literal|"in an XML file.</p><p>The example also shows how to add as "
literal|"well as remove data from both the database and the "
literal|"associated XML file using the API provided by the QtSql and "
literal|"QtXml modules, respectively.</p>"
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
end_unit
