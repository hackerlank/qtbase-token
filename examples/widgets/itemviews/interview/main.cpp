begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the demonstration applications of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"model.h"
end_include
begin_include
include|#
directive|include
file|<QApplication>
end_include
begin_include
include|#
directive|include
file|<QHeaderView>
end_include
begin_include
include|#
directive|include
file|<QListView>
end_include
begin_include
include|#
directive|include
file|<QSplitter>
end_include
begin_include
include|#
directive|include
file|<QTableView>
end_include
begin_include
include|#
directive|include
file|<QTreeView>
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
name|interview
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
name|QSplitter
name|page
decl_stmt|;
name|QAbstractItemModel
modifier|*
name|data
init|=
operator|new
name|Model
argument_list|(
literal|1000
argument_list|,
literal|10
argument_list|,
operator|&
name|page
argument_list|)
decl_stmt|;
name|QItemSelectionModel
modifier|*
name|selections
init|=
operator|new
name|QItemSelectionModel
argument_list|(
name|data
argument_list|)
decl_stmt|;
name|QTableView
modifier|*
name|table
init|=
operator|new
name|QTableView
decl_stmt|;
name|table
operator|->
name|setModel
argument_list|(
name|data
argument_list|)
expr_stmt|;
name|table
operator|->
name|setSelectionModel
argument_list|(
name|selections
argument_list|)
expr_stmt|;
name|table
operator|->
name|horizontalHeader
argument_list|()
operator|->
name|setSectionsMovable
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|table
operator|->
name|verticalHeader
argument_list|()
operator|->
name|setSectionsMovable
argument_list|(
literal|true
argument_list|)
expr_stmt|;
comment|// Set StaticContents to enable minimal repaints on resizes.
name|table
operator|->
name|viewport
argument_list|()
operator|->
name|setAttribute
argument_list|(
name|Qt
operator|::
name|WA_StaticContents
argument_list|)
expr_stmt|;
name|page
operator|.
name|addWidget
argument_list|(
name|table
argument_list|)
expr_stmt|;
name|QTreeView
modifier|*
name|tree
init|=
operator|new
name|QTreeView
decl_stmt|;
name|tree
operator|->
name|setModel
argument_list|(
name|data
argument_list|)
expr_stmt|;
name|tree
operator|->
name|setSelectionModel
argument_list|(
name|selections
argument_list|)
expr_stmt|;
name|tree
operator|->
name|setUniformRowHeights
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|tree
operator|->
name|header
argument_list|()
operator|->
name|setStretchLastSection
argument_list|(
literal|false
argument_list|)
expr_stmt|;
name|tree
operator|->
name|viewport
argument_list|()
operator|->
name|setAttribute
argument_list|(
name|Qt
operator|::
name|WA_StaticContents
argument_list|)
expr_stmt|;
comment|// Disable the focus rect to get minimal repaints when scrolling on Mac.
name|tree
operator|->
name|setAttribute
argument_list|(
name|Qt
operator|::
name|WA_MacShowFocusRect
argument_list|,
literal|false
argument_list|)
expr_stmt|;
name|page
operator|.
name|addWidget
argument_list|(
name|tree
argument_list|)
expr_stmt|;
name|QListView
modifier|*
name|list
init|=
operator|new
name|QListView
decl_stmt|;
name|list
operator|->
name|setModel
argument_list|(
name|data
argument_list|)
expr_stmt|;
name|list
operator|->
name|setSelectionModel
argument_list|(
name|selections
argument_list|)
expr_stmt|;
name|list
operator|->
name|setViewMode
argument_list|(
name|QListView
operator|::
name|IconMode
argument_list|)
expr_stmt|;
name|list
operator|->
name|setSelectionMode
argument_list|(
name|QAbstractItemView
operator|::
name|ExtendedSelection
argument_list|)
expr_stmt|;
name|list
operator|->
name|setAlternatingRowColors
argument_list|(
literal|false
argument_list|)
expr_stmt|;
name|list
operator|->
name|viewport
argument_list|()
operator|->
name|setAttribute
argument_list|(
name|Qt
operator|::
name|WA_StaticContents
argument_list|)
expr_stmt|;
name|list
operator|->
name|setAttribute
argument_list|(
name|Qt
operator|::
name|WA_MacShowFocusRect
argument_list|,
literal|false
argument_list|)
expr_stmt|;
name|page
operator|.
name|addWidget
argument_list|(
name|list
argument_list|)
expr_stmt|;
name|page
operator|.
name|setWindowIcon
argument_list|(
name|QPixmap
argument_list|(
literal|":/images/interview.png"
argument_list|)
argument_list|)
expr_stmt|;
name|page
operator|.
name|setWindowTitle
argument_list|(
literal|"Interview"
argument_list|)
expr_stmt|;
name|page
operator|.
name|show
argument_list|()
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
