begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of Nokia Corporation and its Subsidiary(-ies) nor **     the names of its contributors may be used to endorse or promote **     products derived from this software without specific prior written **     permission. ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtWidgets>
end_include
begin_include
include|#
directive|include
file|"window.h"
end_include
begin_include
include|#
directive|include
file|"colorlisteditor.h"
end_include
begin_comment
comment|//! [0]
end_comment
begin_constructor
DECL|function|Window
name|Window
operator|::
name|Window
parameter_list|()
block|{
name|QItemEditorFactory
modifier|*
name|factory
init|=
operator|new
name|QItemEditorFactory
decl_stmt|;
name|QItemEditorCreatorBase
modifier|*
name|colorListCreator
init|=
operator|new
name|QStandardItemEditorCreator
argument_list|<
name|ColorListEditor
argument_list|>
argument_list|()
decl_stmt|;
name|factory
operator|->
name|registerEditor
argument_list|(
name|QVariant
operator|::
name|Color
argument_list|,
name|colorListCreator
argument_list|)
expr_stmt|;
name|QItemEditorFactory
operator|::
name|setDefaultFactory
argument_list|(
name|factory
argument_list|)
expr_stmt|;
name|createGUI
argument_list|()
expr_stmt|;
block|}
end_constructor
begin_comment
comment|//! [0]
end_comment
begin_function
DECL|function|createGUI
name|void
name|Window
operator|::
name|createGUI
parameter_list|()
block|{
name|QList
argument_list|<
name|QPair
argument_list|<
name|QString
argument_list|,
name|QColor
argument_list|>
argument_list|>
name|list
decl_stmt|;
name|list
operator|<<
name|QPair
argument_list|<
name|QString
argument_list|,
name|QColor
argument_list|>
argument_list|(
name|tr
argument_list|(
literal|"Alice"
argument_list|)
argument_list|,
name|QColor
argument_list|(
literal|"aliceblue"
argument_list|)
argument_list|)
operator|<<
name|QPair
argument_list|<
name|QString
argument_list|,
name|QColor
argument_list|>
argument_list|(
name|tr
argument_list|(
literal|"Neptun"
argument_list|)
argument_list|,
name|QColor
argument_list|(
literal|"aquamarine"
argument_list|)
argument_list|)
operator|<<
name|QPair
argument_list|<
name|QString
argument_list|,
name|QColor
argument_list|>
argument_list|(
name|tr
argument_list|(
literal|"Ferdinand"
argument_list|)
argument_list|,
name|QColor
argument_list|(
literal|"springgreen"
argument_list|)
argument_list|)
expr_stmt|;
name|QTableWidget
modifier|*
name|table
init|=
operator|new
name|QTableWidget
argument_list|(
literal|3
argument_list|,
literal|2
argument_list|)
decl_stmt|;
name|table
operator|->
name|setHorizontalHeaderLabels
argument_list|(
name|QStringList
argument_list|()
operator|<<
name|tr
argument_list|(
literal|"Name"
argument_list|)
operator|<<
name|tr
argument_list|(
literal|"Hair Color"
argument_list|)
argument_list|)
expr_stmt|;
name|table
operator|->
name|verticalHeader
argument_list|()
operator|->
name|setVisible
argument_list|(
literal|false
argument_list|)
expr_stmt|;
name|table
operator|->
name|resize
argument_list|(
literal|150
argument_list|,
literal|50
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
literal|3
condition|;
operator|++
name|i
control|)
block|{
name|QPair
argument_list|<
name|QString
argument_list|,
name|QColor
argument_list|>
name|pair
init|=
name|list
operator|.
name|at
argument_list|(
name|i
argument_list|)
decl_stmt|;
name|QTableWidgetItem
modifier|*
name|nameItem
init|=
operator|new
name|QTableWidgetItem
argument_list|(
name|pair
operator|.
name|first
argument_list|)
decl_stmt|;
name|QTableWidgetItem
modifier|*
name|colorItem
init|=
operator|new
name|QTableWidgetItem
decl_stmt|;
name|colorItem
operator|->
name|setData
argument_list|(
name|Qt
operator|::
name|DisplayRole
argument_list|,
name|pair
operator|.
name|second
argument_list|)
expr_stmt|;
name|table
operator|->
name|setItem
argument_list|(
name|i
argument_list|,
literal|0
argument_list|,
name|nameItem
argument_list|)
expr_stmt|;
name|table
operator|->
name|setItem
argument_list|(
name|i
argument_list|,
literal|1
argument_list|,
name|colorItem
argument_list|)
expr_stmt|;
block|}
name|table
operator|->
name|resizeColumnToContents
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|table
operator|->
name|horizontalHeader
argument_list|()
operator|->
name|setStretchLastSection
argument_list|(
literal|true
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
name|table
argument_list|,
literal|0
argument_list|,
literal|0
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
literal|"Color Editor Factory"
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
end_unit
