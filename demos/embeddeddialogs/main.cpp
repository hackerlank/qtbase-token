begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the demonstration applications of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** No Commercial Usage ** This file contains pre-release code and may not be distributed. ** You may use this file in accordance with the terms and conditions ** contained in the Technology Preview License Agreement accompanying ** this package. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights.  These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** If you have questions regarding the use of this file, please contact ** Nokia at qt-info@nokia.com. ** ** ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"customproxy.h"
end_include
begin_include
include|#
directive|include
file|"embeddeddialog.h"
end_include
begin_include
include|#
directive|include
file|<QtGui>
end_include
begin_function
DECL|function|main
name|int
name|main
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
name|argv
index|[]
parameter_list|)
block|{
name|Q_INIT_RESOURCE
argument_list|(
name|embeddeddialogs
argument_list|)
expr_stmt|;
name|QApplication
name|app
argument_list|(
name|argc
argument_list|,
name|argv
argument_list|)
decl_stmt|;
name|QGraphicsScene
name|scene
decl_stmt|;
name|scene
operator|.
name|setStickyFocus
argument_list|(
literal|true
argument_list|)
expr_stmt|;
ifndef|#
directive|ifndef
name|Q_OS_WINCE
specifier|const
name|int
name|gridSize
init|=
literal|10
decl_stmt|;
else|#
directive|else
specifier|const
name|int
name|gridSize
init|=
literal|5
decl_stmt|;
endif|#
directive|endif
for|for
control|(
name|int
name|y
init|=
literal|0
init|;
name|y
operator|<
name|gridSize
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
name|gridSize
condition|;
operator|++
name|x
control|)
block|{
name|CustomProxy
modifier|*
name|proxy
init|=
operator|new
name|CustomProxy
argument_list|(
literal|0
argument_list|,
name|Qt
operator|::
name|Window
argument_list|)
decl_stmt|;
name|proxy
operator|->
name|setWidget
argument_list|(
operator|new
name|EmbeddedDialog
argument_list|)
expr_stmt|;
name|QRectF
name|rect
init|=
name|proxy
operator|->
name|boundingRect
argument_list|()
decl_stmt|;
name|proxy
operator|->
name|setPos
argument_list|(
name|x
operator|*
name|rect
operator|.
name|width
argument_list|()
operator|*
literal|1.05
argument_list|,
name|y
operator|*
name|rect
operator|.
name|height
argument_list|()
operator|*
literal|1.05
argument_list|)
expr_stmt|;
name|proxy
operator|->
name|setCacheMode
argument_list|(
name|QGraphicsItem
operator|::
name|DeviceCoordinateCache
argument_list|)
expr_stmt|;
name|scene
operator|.
name|addItem
argument_list|(
name|proxy
argument_list|)
expr_stmt|;
block|}
block|}
name|scene
operator|.
name|setSceneRect
argument_list|(
name|scene
operator|.
name|itemsBoundingRect
argument_list|()
argument_list|)
expr_stmt|;
name|QGraphicsView
name|view
argument_list|(
operator|&
name|scene
argument_list|)
decl_stmt|;
name|view
operator|.
name|scale
argument_list|(
literal|0.5
argument_list|,
literal|0.5
argument_list|)
expr_stmt|;
name|view
operator|.
name|setRenderHints
argument_list|(
name|view
operator|.
name|renderHints
argument_list|()
operator||
name|QPainter
operator|::
name|Antialiasing
operator||
name|QPainter
operator|::
name|SmoothPixmapTransform
argument_list|)
expr_stmt|;
name|view
operator|.
name|setBackgroundBrush
argument_list|(
name|QPixmap
argument_list|(
literal|":/No-Ones-Laughing-3.jpg"
argument_list|)
argument_list|)
expr_stmt|;
name|view
operator|.
name|setViewportUpdateMode
argument_list|(
name|QGraphicsView
operator|::
name|BoundingRectViewportUpdate
argument_list|)
expr_stmt|;
name|view
operator|.
name|show
argument_list|()
expr_stmt|;
name|view
operator|.
name|setWindowTitle
argument_list|(
literal|"Embedded Dialogs Demo"
argument_list|)
expr_stmt|;
return|return
name|app
operator|.
name|exec
argument_list|()
return|;
block|}
end_function
end_unit
