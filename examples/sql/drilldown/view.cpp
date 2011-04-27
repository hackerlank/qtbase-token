begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of Nokia Corporation and its Subsidiary(-ies) nor **     the names of its contributors may be used to endorse or promote **     products derived from this software without specific prior written **     permission. ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"informationwindow.h"
end_include
begin_include
include|#
directive|include
file|"imageitem.h"
end_include
begin_include
include|#
directive|include
file|"view.h"
end_include
begin_comment
comment|//! [0]
end_comment
begin_constructor
DECL|function|View
name|View
operator|::
name|View
parameter_list|(
specifier|const
name|QString
modifier|&
name|offices
parameter_list|,
specifier|const
name|QString
modifier|&
name|images
parameter_list|,
name|QWidget
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QGraphicsView
argument_list|(
name|parent
argument_list|)
block|{
name|officeTable
operator|=
operator|new
name|QSqlRelationalTableModel
argument_list|(
name|this
argument_list|)
expr_stmt|;
name|officeTable
operator|->
name|setTable
argument_list|(
name|offices
argument_list|)
expr_stmt|;
name|officeTable
operator|->
name|setRelation
argument_list|(
literal|1
argument_list|,
name|QSqlRelation
argument_list|(
name|images
argument_list|,
literal|"locationid"
argument_list|,
literal|"file"
argument_list|)
argument_list|)
expr_stmt|;
name|officeTable
operator|->
name|select
argument_list|()
expr_stmt|;
comment|//! [0]
comment|//! [1]
name|scene
operator|=
operator|new
name|QGraphicsScene
argument_list|(
name|this
argument_list|)
expr_stmt|;
name|scene
operator|->
name|setSceneRect
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|465
argument_list|,
literal|615
argument_list|)
expr_stmt|;
name|setScene
argument_list|(
name|scene
argument_list|)
expr_stmt|;
name|addItems
argument_list|()
expr_stmt|;
name|QGraphicsPixmapItem
modifier|*
name|logo
init|=
name|scene
operator|->
name|addPixmap
argument_list|(
name|QPixmap
argument_list|(
literal|":/logo.png"
argument_list|)
argument_list|)
decl_stmt|;
name|logo
operator|->
name|setPos
argument_list|(
literal|30
argument_list|,
literal|515
argument_list|)
expr_stmt|;
ifndef|#
directive|ifndef
name|Q_OS_SYMBIAN
name|setMinimumSize
argument_list|(
literal|470
argument_list|,
literal|620
argument_list|)
expr_stmt|;
name|setMaximumSize
argument_list|(
literal|470
argument_list|,
literal|620
argument_list|)
expr_stmt|;
else|#
directive|else
name|setDragMode
argument_list|(
name|QGraphicsView
operator|::
name|ScrollHandDrag
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|setWindowTitle
argument_list|(
name|tr
argument_list|(
literal|"Offices World Wide"
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_comment
comment|//! [1]
end_comment
begin_comment
comment|//! [3]
end_comment
begin_function
DECL|function|addItems
name|void
name|View
operator|::
name|addItems
parameter_list|()
block|{
name|int
name|officeCount
init|=
name|officeTable
operator|->
name|rowCount
argument_list|()
decl_stmt|;
name|int
name|imageOffset
init|=
literal|150
decl_stmt|;
name|int
name|leftMargin
init|=
literal|70
decl_stmt|;
name|int
name|topMargin
init|=
literal|40
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
name|officeCount
condition|;
name|i
operator|++
control|)
block|{
name|ImageItem
modifier|*
name|image
decl_stmt|;
name|QGraphicsTextItem
modifier|*
name|label
decl_stmt|;
name|QSqlRecord
name|record
init|=
name|officeTable
operator|->
name|record
argument_list|(
name|i
argument_list|)
decl_stmt|;
name|int
name|id
init|=
name|record
operator|.
name|value
argument_list|(
literal|"id"
argument_list|)
operator|.
name|toInt
argument_list|()
decl_stmt|;
name|QString
name|file
init|=
name|record
operator|.
name|value
argument_list|(
literal|"file"
argument_list|)
operator|.
name|toString
argument_list|()
decl_stmt|;
name|QString
name|location
init|=
name|record
operator|.
name|value
argument_list|(
literal|"location"
argument_list|)
operator|.
name|toString
argument_list|()
decl_stmt|;
name|int
name|columnOffset
init|=
operator|(
operator|(
name|i
operator|/
literal|3
operator|)
operator|*
literal|37
operator|)
decl_stmt|;
name|int
name|x
init|=
operator|(
operator|(
name|i
operator|/
literal|3
operator|)
operator|*
name|imageOffset
operator|)
operator|+
name|leftMargin
operator|+
name|columnOffset
decl_stmt|;
name|int
name|y
init|=
operator|(
operator|(
name|i
operator|%
literal|3
operator|)
operator|*
name|imageOffset
operator|)
operator|+
name|topMargin
decl_stmt|;
name|image
operator|=
operator|new
name|ImageItem
argument_list|(
name|id
argument_list|,
name|QPixmap
argument_list|(
literal|":/"
operator|+
name|file
argument_list|)
argument_list|)
expr_stmt|;
name|image
operator|->
name|setData
argument_list|(
literal|0
argument_list|,
name|i
argument_list|)
expr_stmt|;
name|image
operator|->
name|setPos
argument_list|(
name|x
argument_list|,
name|y
argument_list|)
expr_stmt|;
name|scene
operator|->
name|addItem
argument_list|(
name|image
argument_list|)
expr_stmt|;
name|label
operator|=
name|scene
operator|->
name|addText
argument_list|(
name|location
argument_list|)
expr_stmt|;
name|QPointF
name|labelOffset
argument_list|(
operator|(
literal|150
operator|-
name|label
operator|->
name|boundingRect
argument_list|()
operator|.
name|width
argument_list|()
operator|)
operator|/
literal|2
argument_list|,
literal|120.0
argument_list|)
decl_stmt|;
name|label
operator|->
name|setPos
argument_list|(
name|QPointF
argument_list|(
name|x
argument_list|,
name|y
argument_list|)
operator|+
name|labelOffset
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_comment
comment|//! [3]
end_comment
begin_comment
comment|//! [5]
end_comment
begin_function
DECL|function|mouseReleaseEvent
name|void
name|View
operator|::
name|mouseReleaseEvent
parameter_list|(
name|QMouseEvent
modifier|*
name|event
parameter_list|)
block|{
if|if
condition|(
name|QGraphicsItem
modifier|*
name|item
init|=
name|itemAt
argument_list|(
name|event
operator|->
name|pos
argument_list|()
argument_list|)
condition|)
block|{
if|if
condition|(
name|ImageItem
modifier|*
name|image
init|=
name|qgraphicsitem_cast
argument_list|<
name|ImageItem
operator|*
argument_list|>
argument_list|(
name|item
argument_list|)
condition|)
name|showInformation
argument_list|(
name|image
argument_list|)
expr_stmt|;
block|}
name|QGraphicsView
operator|::
name|mouseReleaseEvent
argument_list|(
name|event
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [5]
end_comment
begin_comment
comment|//! [6]
end_comment
begin_function
DECL|function|showInformation
name|void
name|View
operator|::
name|showInformation
parameter_list|(
name|ImageItem
modifier|*
name|image
parameter_list|)
block|{
name|int
name|id
init|=
name|image
operator|->
name|id
argument_list|()
decl_stmt|;
if|if
condition|(
name|id
operator|<
literal|0
operator|||
name|id
operator|>=
name|officeTable
operator|->
name|rowCount
argument_list|()
condition|)
return|return;
name|InformationWindow
modifier|*
name|window
init|=
name|findWindow
argument_list|(
name|id
argument_list|)
decl_stmt|;
if|if
condition|(
name|window
operator|&&
name|window
operator|->
name|isVisible
argument_list|()
condition|)
block|{
name|window
operator|->
name|raise
argument_list|()
expr_stmt|;
name|window
operator|->
name|activateWindow
argument_list|()
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|window
operator|&&
operator|!
name|window
operator|->
name|isVisible
argument_list|()
condition|)
block|{
ifndef|#
directive|ifndef
name|Q_OS_SYMBIAN
name|window
operator|->
name|show
argument_list|()
expr_stmt|;
else|#
directive|else
name|window
operator|->
name|showMaximized
argument_list|()
expr_stmt|;
endif|#
directive|endif
block|}
else|else
block|{
name|InformationWindow
modifier|*
name|window
decl_stmt|;
name|window
operator|=
operator|new
name|InformationWindow
argument_list|(
name|id
argument_list|,
name|officeTable
argument_list|,
name|this
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|window
argument_list|,
name|SIGNAL
argument_list|(
name|imageChanged
argument_list|(
name|int
argument_list|,
name|QString
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|updateImage
argument_list|(
name|int
argument_list|,
name|QString
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
ifndef|#
directive|ifndef
name|Q_OS_SYMBIAN
name|window
operator|->
name|move
argument_list|(
name|pos
argument_list|()
operator|+
name|QPoint
argument_list|(
literal|20
argument_list|,
literal|40
argument_list|)
argument_list|)
expr_stmt|;
name|window
operator|->
name|show
argument_list|()
expr_stmt|;
else|#
directive|else
name|window
operator|->
name|showMaximized
argument_list|()
expr_stmt|;
endif|#
directive|endif
name|informationWindows
operator|.
name|append
argument_list|(
name|window
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_comment
comment|//! [6]
end_comment
begin_comment
comment|//! [7]
end_comment
begin_function
DECL|function|updateImage
name|void
name|View
operator|::
name|updateImage
parameter_list|(
name|int
name|id
parameter_list|,
specifier|const
name|QString
modifier|&
name|fileName
parameter_list|)
block|{
name|QList
argument_list|<
name|QGraphicsItem
modifier|*
argument_list|>
name|items
init|=
name|scene
operator|->
name|items
argument_list|()
decl_stmt|;
while|while
condition|(
operator|!
name|items
operator|.
name|empty
argument_list|()
condition|)
block|{
name|QGraphicsItem
modifier|*
name|item
init|=
name|items
operator|.
name|takeFirst
argument_list|()
decl_stmt|;
if|if
condition|(
name|ImageItem
modifier|*
name|image
init|=
name|qgraphicsitem_cast
argument_list|<
name|ImageItem
operator|*
argument_list|>
argument_list|(
name|item
argument_list|)
condition|)
block|{
if|if
condition|(
name|image
operator|->
name|id
argument_list|()
operator|==
name|id
condition|)
block|{
name|image
operator|->
name|setPixmap
argument_list|(
name|QPixmap
argument_list|(
literal|":/"
operator|+
name|fileName
argument_list|)
argument_list|)
expr_stmt|;
name|image
operator|->
name|adjust
argument_list|()
expr_stmt|;
break|break;
block|}
block|}
block|}
block|}
end_function
begin_comment
comment|//! [7]
end_comment
begin_comment
comment|//! [8]
end_comment
begin_function
DECL|function|findWindow
name|InformationWindow
modifier|*
name|View
operator|::
name|findWindow
parameter_list|(
name|int
name|id
parameter_list|)
block|{
name|QList
argument_list|<
name|InformationWindow
modifier|*
argument_list|>
operator|::
name|iterator
name|i
decl_stmt|,
name|beginning
decl_stmt|,
name|end
decl_stmt|;
name|beginning
operator|=
name|informationWindows
operator|.
name|begin
argument_list|()
expr_stmt|;
name|end
operator|=
name|informationWindows
operator|.
name|end
argument_list|()
expr_stmt|;
for|for
control|(
name|i
operator|=
name|beginning
init|;
name|i
operator|!=
name|end
condition|;
operator|++
name|i
control|)
block|{
name|InformationWindow
modifier|*
name|window
init|=
operator|(
operator|*
name|i
operator|)
decl_stmt|;
if|if
condition|(
name|window
operator|&&
operator|(
name|window
operator|->
name|id
argument_list|()
operator|==
name|id
operator|)
condition|)
return|return
name|window
return|;
block|}
return|return
literal|0
return|;
block|}
end_function
begin_comment
comment|//! [8]
end_comment
end_unit
