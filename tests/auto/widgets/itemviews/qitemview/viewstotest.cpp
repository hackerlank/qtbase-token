begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2014 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia. For licensing terms and ** conditions see http://qt.digia.com/licensing. For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights. These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtTest/QtTest>
end_include
begin_include
include|#
directive|include
file|<QtCore/QtCore>
end_include
begin_include
include|#
directive|include
file|<QtGui/QtGui>
end_include
begin_include
include|#
directive|include
file|<QtWidgets/QtWidgets>
end_include
begin_comment
comment|/*     To add a view to be tested add the header file to the includes     and impliment what is needed in the functions below.      You can add more then one view, several Qt views are included as examples.      In tst_qitemview.cpp a new ViewsToTest object is created for each test.      When you have errors fix the first ones first.  Later tests depend upon them working */
end_comment
begin_class
DECL|class|ViewsToTest
class|class
name|ViewsToTest
block|{
public|public:
name|ViewsToTest
parameter_list|()
constructor_decl|;
name|QAbstractItemView
modifier|*
name|createView
parameter_list|(
specifier|const
name|QString
modifier|&
name|viewType
parameter_list|)
function_decl|;
name|void
name|hideIndexes
parameter_list|(
name|QAbstractItemView
modifier|*
name|view
parameter_list|)
function_decl|;
DECL|enum|Display
DECL|enumerator|DisplayNone
DECL|enumerator|DisplayRoot
enum|enum
name|Display
block|{
name|DisplayNone
block|,
name|DisplayRoot
block|}
enum|;
DECL|struct|test
struct|struct
name|test
block|{
DECL|function|test
name|test
parameter_list|(
name|QString
name|m
parameter_list|,
name|Display
name|d
parameter_list|)
member_init_list|:
name|viewType
argument_list|(
name|m
argument_list|)
member_init_list|,
name|display
argument_list|(
name|d
argument_list|)
block|{}
empty_stmt|;
DECL|member|viewType
name|QString
name|viewType
decl_stmt|;
DECL|member|display
name|Display
name|display
decl_stmt|;
block|}
struct|;
DECL|member|tests
name|QList
argument_list|<
name|test
argument_list|>
name|tests
decl_stmt|;
block|}
class|;
end_class
begin_comment
comment|/*!     Add new tests, they can be the same view, but in a different state.  */
end_comment
begin_constructor
DECL|function|ViewsToTest
name|ViewsToTest
operator|::
name|ViewsToTest
parameter_list|()
block|{
name|tests
operator|.
name|append
argument_list|(
name|test
argument_list|(
literal|"QTreeView_ScrollPerItem"
argument_list|,
name|DisplayRoot
argument_list|)
argument_list|)
expr_stmt|;
name|tests
operator|.
name|append
argument_list|(
name|test
argument_list|(
literal|"QTreeView_ScrollPerPixel"
argument_list|,
name|DisplayRoot
argument_list|)
argument_list|)
expr_stmt|;
name|tests
operator|.
name|append
argument_list|(
name|test
argument_list|(
literal|"QListView_ScrollPerItem"
argument_list|,
name|DisplayRoot
argument_list|)
argument_list|)
expr_stmt|;
name|tests
operator|.
name|append
argument_list|(
name|test
argument_list|(
literal|"QListView_ScrollPerPixel"
argument_list|,
name|DisplayRoot
argument_list|)
argument_list|)
expr_stmt|;
name|tests
operator|.
name|append
argument_list|(
name|test
argument_list|(
literal|"QHeaderViewHorizontal"
argument_list|,
name|DisplayNone
argument_list|)
argument_list|)
expr_stmt|;
name|tests
operator|.
name|append
argument_list|(
name|test
argument_list|(
literal|"QHeaderViewVertical"
argument_list|,
name|DisplayNone
argument_list|)
argument_list|)
expr_stmt|;
name|tests
operator|.
name|append
argument_list|(
name|test
argument_list|(
literal|"QTableView_ScrollPerItem"
argument_list|,
name|DisplayRoot
argument_list|)
argument_list|)
expr_stmt|;
name|tests
operator|.
name|append
argument_list|(
name|test
argument_list|(
literal|"QTableView_ScrollPerPixel"
argument_list|,
name|DisplayRoot
argument_list|)
argument_list|)
expr_stmt|;
name|tests
operator|.
name|append
argument_list|(
name|test
argument_list|(
literal|"QTableViewNoGrid"
argument_list|,
name|DisplayRoot
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_comment
comment|/*!     Return a new viewType.  */
end_comment
begin_function
DECL|function|createView
name|QAbstractItemView
modifier|*
name|ViewsToTest
operator|::
name|createView
parameter_list|(
specifier|const
name|QString
modifier|&
name|viewType
parameter_list|)
block|{
name|QAbstractItemView
modifier|*
name|view
init|=
literal|0
decl_stmt|;
if|if
condition|(
name|viewType
operator|==
literal|"QListView_ScrollPerItem"
condition|)
block|{
name|view
operator|=
operator|new
name|QListView
argument_list|()
expr_stmt|;
name|view
operator|->
name|setObjectName
argument_list|(
literal|"QListView"
argument_list|)
expr_stmt|;
name|view
operator|->
name|setHorizontalScrollMode
argument_list|(
name|QAbstractItemView
operator|::
name|ScrollPerItem
argument_list|)
expr_stmt|;
name|view
operator|->
name|setVerticalScrollMode
argument_list|(
name|QAbstractItemView
operator|::
name|ScrollPerItem
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|viewType
operator|==
literal|"QListView_ScrollPerPixel"
condition|)
block|{
name|view
operator|=
operator|new
name|QListView
argument_list|()
expr_stmt|;
name|view
operator|->
name|setObjectName
argument_list|(
literal|"QListView"
argument_list|)
expr_stmt|;
name|view
operator|->
name|setHorizontalScrollMode
argument_list|(
name|QAbstractItemView
operator|::
name|ScrollPerPixel
argument_list|)
expr_stmt|;
name|view
operator|->
name|setVerticalScrollMode
argument_list|(
name|QAbstractItemView
operator|::
name|ScrollPerPixel
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|viewType
operator|==
literal|"QHeaderViewHorizontal"
condition|)
block|{
name|view
operator|=
operator|new
name|QHeaderView
argument_list|(
name|Qt
operator|::
name|Horizontal
argument_list|)
expr_stmt|;
name|view
operator|->
name|setObjectName
argument_list|(
literal|"QHeaderView"
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|viewType
operator|==
literal|"QHeaderViewVertical"
condition|)
block|{
name|view
operator|=
operator|new
name|QHeaderView
argument_list|(
name|Qt
operator|::
name|Vertical
argument_list|)
expr_stmt|;
name|view
operator|->
name|setObjectName
argument_list|(
literal|"QHeaderView"
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|viewType
operator|==
literal|"QTableView_ScrollPerItem"
condition|)
block|{
name|view
operator|=
operator|new
name|QTableView
argument_list|()
expr_stmt|;
name|view
operator|->
name|setObjectName
argument_list|(
literal|"QTableView"
argument_list|)
expr_stmt|;
name|view
operator|->
name|setHorizontalScrollMode
argument_list|(
name|QAbstractItemView
operator|::
name|ScrollPerItem
argument_list|)
expr_stmt|;
name|view
operator|->
name|setVerticalScrollMode
argument_list|(
name|QAbstractItemView
operator|::
name|ScrollPerItem
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|viewType
operator|==
literal|"QTableView_ScrollPerPixel"
condition|)
block|{
name|view
operator|=
operator|new
name|QTableView
argument_list|()
expr_stmt|;
name|view
operator|->
name|setObjectName
argument_list|(
literal|"QTableView"
argument_list|)
expr_stmt|;
name|view
operator|->
name|setHorizontalScrollMode
argument_list|(
name|QAbstractItemView
operator|::
name|ScrollPerPixel
argument_list|)
expr_stmt|;
name|view
operator|->
name|setVerticalScrollMode
argument_list|(
name|QAbstractItemView
operator|::
name|ScrollPerPixel
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|viewType
operator|==
literal|"QTableViewNoGrid"
condition|)
block|{
name|QTableView
modifier|*
name|table
init|=
operator|new
name|QTableView
argument_list|()
decl_stmt|;
name|table
operator|->
name|setObjectName
argument_list|(
literal|"QTableView"
argument_list|)
expr_stmt|;
name|table
operator|->
name|setShowGrid
argument_list|(
literal|false
argument_list|)
expr_stmt|;
name|view
operator|=
name|table
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|viewType
operator|==
literal|"QTreeView_ScrollPerItem"
condition|)
block|{
name|view
operator|=
operator|new
name|QTreeView
argument_list|()
expr_stmt|;
name|view
operator|->
name|setObjectName
argument_list|(
literal|"QTreeView"
argument_list|)
expr_stmt|;
name|view
operator|->
name|setHorizontalScrollMode
argument_list|(
name|QAbstractItemView
operator|::
name|ScrollPerItem
argument_list|)
expr_stmt|;
name|view
operator|->
name|setVerticalScrollMode
argument_list|(
name|QAbstractItemView
operator|::
name|ScrollPerItem
argument_list|)
expr_stmt|;
name|view
operator|->
name|setSelectionBehavior
argument_list|(
name|QAbstractItemView
operator|::
name|SelectItems
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|viewType
operator|==
literal|"QTreeView_ScrollPerPixel"
condition|)
block|{
name|view
operator|=
operator|new
name|QTreeView
argument_list|()
expr_stmt|;
name|view
operator|->
name|setObjectName
argument_list|(
literal|"QTreeView"
argument_list|)
expr_stmt|;
name|view
operator|->
name|setHorizontalScrollMode
argument_list|(
name|QAbstractItemView
operator|::
name|ScrollPerPixel
argument_list|)
expr_stmt|;
name|view
operator|->
name|setVerticalScrollMode
argument_list|(
name|QAbstractItemView
operator|::
name|ScrollPerPixel
argument_list|)
expr_stmt|;
name|view
operator|->
name|setSelectionBehavior
argument_list|(
name|QAbstractItemView
operator|::
name|SelectItems
argument_list|)
expr_stmt|;
block|}
return|return
name|view
return|;
block|}
end_function
begin_function
DECL|function|hideIndexes
name|void
name|ViewsToTest
operator|::
name|hideIndexes
parameter_list|(
name|QAbstractItemView
modifier|*
name|view
parameter_list|)
block|{
if|if
condition|(
name|QTableView
modifier|*
name|tableView
init|=
name|qobject_cast
argument_list|<
name|QTableView
operator|*
argument_list|>
argument_list|(
name|view
argument_list|)
condition|)
block|{
name|tableView
operator|->
name|setColumnHidden
argument_list|(
literal|1
argument_list|,
literal|true
argument_list|)
expr_stmt|;
name|tableView
operator|->
name|setRowHidden
argument_list|(
literal|1
argument_list|,
literal|true
argument_list|)
expr_stmt|;
name|tableView
operator|->
name|setRowHidden
argument_list|(
name|tableView
operator|->
name|model
argument_list|()
operator|->
name|rowCount
argument_list|()
operator|-
literal|2
argument_list|,
literal|true
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|QTreeView
modifier|*
name|treeView
init|=
name|qobject_cast
argument_list|<
name|QTreeView
operator|*
argument_list|>
argument_list|(
name|view
argument_list|)
condition|)
block|{
name|treeView
operator|->
name|setColumnHidden
argument_list|(
literal|1
argument_list|,
literal|true
argument_list|)
expr_stmt|;
name|treeView
operator|->
name|setRowHidden
argument_list|(
literal|1
argument_list|,
name|QModelIndex
argument_list|()
argument_list|,
literal|true
argument_list|)
expr_stmt|;
name|treeView
operator|->
name|setRowHidden
argument_list|(
name|treeView
operator|->
name|model
argument_list|()
operator|->
name|rowCount
argument_list|()
operator|-
literal|2
argument_list|,
name|QModelIndex
argument_list|()
argument_list|,
literal|true
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|QListView
modifier|*
name|listView
init|=
name|qobject_cast
argument_list|<
name|QListView
operator|*
argument_list|>
argument_list|(
name|view
argument_list|)
condition|)
block|{
name|listView
operator|->
name|setRowHidden
argument_list|(
literal|1
argument_list|,
literal|true
argument_list|)
expr_stmt|;
name|listView
operator|->
name|setRowHidden
argument_list|(
name|listView
operator|->
name|model
argument_list|()
operator|->
name|rowCount
argument_list|()
operator|-
literal|2
argument_list|,
literal|true
argument_list|)
expr_stmt|;
block|}
block|}
end_function
end_unit
