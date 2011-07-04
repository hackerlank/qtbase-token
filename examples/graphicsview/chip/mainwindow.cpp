begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the demonstration applications of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"mainwindow.h"
end_include
begin_include
include|#
directive|include
file|"view.h"
end_include
begin_include
include|#
directive|include
file|"chip.h"
end_include
begin_include
include|#
directive|include
file|<QtGui>
end_include
begin_constructor
DECL|function|MainWindow
name|MainWindow
operator|::
name|MainWindow
parameter_list|(
name|QWidget
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QWidget
argument_list|(
name|parent
argument_list|)
block|{
name|populateScene
argument_list|()
expr_stmt|;
name|h1Splitter
operator|=
operator|new
name|QSplitter
expr_stmt|;
name|h2Splitter
operator|=
operator|new
name|QSplitter
expr_stmt|;
name|QSplitter
modifier|*
name|vSplitter
init|=
operator|new
name|QSplitter
decl_stmt|;
name|vSplitter
operator|->
name|setOrientation
argument_list|(
name|Qt
operator|::
name|Vertical
argument_list|)
expr_stmt|;
name|vSplitter
operator|->
name|addWidget
argument_list|(
name|h1Splitter
argument_list|)
expr_stmt|;
name|vSplitter
operator|->
name|addWidget
argument_list|(
name|h2Splitter
argument_list|)
expr_stmt|;
name|View
modifier|*
name|view
init|=
operator|new
name|View
argument_list|(
literal|"Top left view"
argument_list|)
decl_stmt|;
name|view
operator|->
name|view
argument_list|()
operator|->
name|setScene
argument_list|(
name|scene
argument_list|)
expr_stmt|;
name|h1Splitter
operator|->
name|addWidget
argument_list|(
name|view
argument_list|)
expr_stmt|;
name|view
operator|=
operator|new
name|View
argument_list|(
literal|"Top right view"
argument_list|)
expr_stmt|;
name|view
operator|->
name|view
argument_list|()
operator|->
name|setScene
argument_list|(
name|scene
argument_list|)
expr_stmt|;
name|h1Splitter
operator|->
name|addWidget
argument_list|(
name|view
argument_list|)
expr_stmt|;
name|view
operator|=
operator|new
name|View
argument_list|(
literal|"Bottom left view"
argument_list|)
expr_stmt|;
name|view
operator|->
name|view
argument_list|()
operator|->
name|setScene
argument_list|(
name|scene
argument_list|)
expr_stmt|;
name|h2Splitter
operator|->
name|addWidget
argument_list|(
name|view
argument_list|)
expr_stmt|;
name|view
operator|=
operator|new
name|View
argument_list|(
literal|"Bottom right view"
argument_list|)
expr_stmt|;
name|view
operator|->
name|view
argument_list|()
operator|->
name|setScene
argument_list|(
name|scene
argument_list|)
expr_stmt|;
name|h2Splitter
operator|->
name|addWidget
argument_list|(
name|view
argument_list|)
expr_stmt|;
name|QHBoxLayout
modifier|*
name|layout
init|=
operator|new
name|QHBoxLayout
decl_stmt|;
name|layout
operator|->
name|addWidget
argument_list|(
name|vSplitter
argument_list|)
expr_stmt|;
name|setLayout
argument_list|(
name|layout
argument_list|)
expr_stmt|;
name|setWindowTitle
argument_list|(
name|tr
argument_list|(
literal|"Chip Example"
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_function
DECL|function|populateScene
name|void
name|MainWindow
operator|::
name|populateScene
parameter_list|()
block|{
name|scene
operator|=
operator|new
name|QGraphicsScene
expr_stmt|;
name|QImage
name|image
argument_list|(
literal|":/qt4logo.png"
argument_list|)
decl_stmt|;
comment|// Populate scene
name|int
name|xx
init|=
literal|0
decl_stmt|;
name|int
name|nitems
init|=
literal|0
decl_stmt|;
for|for
control|(
name|int
name|i
init|=
operator|-
literal|11000
init|;
name|i
operator|<
literal|11000
condition|;
name|i
operator|+=
literal|110
control|)
block|{
operator|++
name|xx
expr_stmt|;
name|int
name|yy
init|=
literal|0
decl_stmt|;
for|for
control|(
name|int
name|j
init|=
operator|-
literal|7000
init|;
name|j
operator|<
literal|7000
condition|;
name|j
operator|+=
literal|70
control|)
block|{
operator|++
name|yy
expr_stmt|;
name|qreal
name|x
init|=
operator|(
name|i
operator|+
literal|11000
operator|)
operator|/
literal|22000.0
decl_stmt|;
name|qreal
name|y
init|=
operator|(
name|j
operator|+
literal|7000
operator|)
operator|/
literal|14000.0
decl_stmt|;
name|QColor
name|color
argument_list|(
name|image
operator|.
name|pixel
argument_list|(
name|int
argument_list|(
name|image
operator|.
name|width
argument_list|()
operator|*
name|x
argument_list|)
argument_list|,
name|int
argument_list|(
name|image
operator|.
name|height
argument_list|()
operator|*
name|y
argument_list|)
argument_list|)
argument_list|)
decl_stmt|;
name|QGraphicsItem
modifier|*
name|item
init|=
operator|new
name|Chip
argument_list|(
name|color
argument_list|,
name|xx
argument_list|,
name|yy
argument_list|)
decl_stmt|;
name|item
operator|->
name|setPos
argument_list|(
name|QPointF
argument_list|(
name|i
argument_list|,
name|j
argument_list|)
argument_list|)
expr_stmt|;
name|scene
operator|->
name|addItem
argument_list|(
name|item
argument_list|)
expr_stmt|;
operator|++
name|nitems
expr_stmt|;
block|}
block|}
block|}
end_function
end_unit
