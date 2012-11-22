begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of Digia Plc and its Subsidiary(-ies) nor the names **     of its contributors may be used to endorse or promote products derived **     from this software without specific prior written permission. ** ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"window.h"
end_include
begin_include
include|#
directive|include
file|<QtWidgets>
end_include
begin_comment
comment|//! [Set up widgets]
end_comment
begin_constructor
DECL|function|Window
name|Window
operator|::
name|Window
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
name|setupModel
argument_list|()
expr_stmt|;
name|nameLabel
operator|=
operator|new
name|QLabel
argument_list|(
name|tr
argument_list|(
literal|"Na&me:"
argument_list|)
argument_list|)
expr_stmt|;
name|nameEdit
operator|=
operator|new
name|QLineEdit
argument_list|()
expr_stmt|;
name|addressLabel
operator|=
operator|new
name|QLabel
argument_list|(
name|tr
argument_list|(
literal|"&Address:"
argument_list|)
argument_list|)
expr_stmt|;
name|addressEdit
operator|=
operator|new
name|QTextEdit
argument_list|()
expr_stmt|;
name|ageLabel
operator|=
operator|new
name|QLabel
argument_list|(
name|tr
argument_list|(
literal|"A&ge (in years):"
argument_list|)
argument_list|)
expr_stmt|;
name|ageSpinBox
operator|=
operator|new
name|QSpinBox
argument_list|()
expr_stmt|;
name|nextButton
operator|=
operator|new
name|QPushButton
argument_list|(
name|tr
argument_list|(
literal|"&Next"
argument_list|)
argument_list|)
expr_stmt|;
name|previousButton
operator|=
operator|new
name|QPushButton
argument_list|(
name|tr
argument_list|(
literal|"&Previous"
argument_list|)
argument_list|)
expr_stmt|;
name|nameLabel
operator|->
name|setBuddy
argument_list|(
name|nameEdit
argument_list|)
expr_stmt|;
name|addressLabel
operator|->
name|setBuddy
argument_list|(
name|addressEdit
argument_list|)
expr_stmt|;
name|ageLabel
operator|->
name|setBuddy
argument_list|(
name|ageSpinBox
argument_list|)
expr_stmt|;
comment|//! [Set up widgets]
comment|//! [Set up the mapper]
name|mapper
operator|=
operator|new
name|QDataWidgetMapper
argument_list|(
name|this
argument_list|)
expr_stmt|;
name|mapper
operator|->
name|setModel
argument_list|(
name|model
argument_list|)
expr_stmt|;
name|mapper
operator|->
name|addMapping
argument_list|(
name|nameEdit
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|mapper
operator|->
name|addMapping
argument_list|(
name|addressEdit
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|mapper
operator|->
name|addMapping
argument_list|(
name|ageSpinBox
argument_list|,
literal|2
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|previousButton
argument_list|,
name|SIGNAL
argument_list|(
name|clicked
argument_list|()
argument_list|)
argument_list|,
name|mapper
argument_list|,
name|SLOT
argument_list|(
name|toPrevious
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|nextButton
argument_list|,
name|SIGNAL
argument_list|(
name|clicked
argument_list|()
argument_list|)
argument_list|,
name|mapper
argument_list|,
name|SLOT
argument_list|(
name|toNext
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|mapper
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
name|updateButtons
argument_list|(
name|int
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
comment|//! [Set up the mapper]
comment|//! [Set up the layout]
name|QGridLayout
modifier|*
name|layout
init|=
operator|new
name|QGridLayout
argument_list|()
decl_stmt|;
name|layout
operator|->
name|addWidget
argument_list|(
name|nameLabel
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|layout
operator|->
name|addWidget
argument_list|(
name|nameEdit
argument_list|,
literal|0
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|layout
operator|->
name|addWidget
argument_list|(
name|previousButton
argument_list|,
literal|0
argument_list|,
literal|2
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|layout
operator|->
name|addWidget
argument_list|(
name|addressLabel
argument_list|,
literal|1
argument_list|,
literal|0
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|layout
operator|->
name|addWidget
argument_list|(
name|addressEdit
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|,
literal|2
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|layout
operator|->
name|addWidget
argument_list|(
name|nextButton
argument_list|,
literal|1
argument_list|,
literal|2
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|layout
operator|->
name|addWidget
argument_list|(
name|ageLabel
argument_list|,
literal|3
argument_list|,
literal|0
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|layout
operator|->
name|addWidget
argument_list|(
name|ageSpinBox
argument_list|,
literal|3
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|,
literal|1
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
literal|"Simple Widget Mapper"
argument_list|)
argument_list|)
expr_stmt|;
name|mapper
operator|->
name|toFirst
argument_list|()
expr_stmt|;
block|}
end_constructor
begin_comment
comment|//! [Set up the layout]
end_comment
begin_comment
comment|//! [Set up the model]
end_comment
begin_function
DECL|function|setupModel
name|void
name|Window
operator|::
name|setupModel
parameter_list|()
block|{
name|model
operator|=
operator|new
name|QStandardItemModel
argument_list|(
literal|5
argument_list|,
literal|3
argument_list|,
name|this
argument_list|)
expr_stmt|;
name|QStringList
name|names
decl_stmt|;
name|names
operator|<<
literal|"Alice"
operator|<<
literal|"Bob"
operator|<<
literal|"Carol"
operator|<<
literal|"Donald"
operator|<<
literal|"Emma"
expr_stmt|;
name|QStringList
name|addresses
decl_stmt|;
name|addresses
operator|<<
literal|"<qt>123 Main Street<br/>Market Town</qt>"
operator|<<
literal|"<qt>PO Box 32<br/>Mail Handling Service"
literal|"<br/>Service City</qt>"
operator|<<
literal|"<qt>The Lighthouse<br/>Remote Island</qt>"
operator|<<
literal|"<qt>47338 Park Avenue<br/>Big City</qt>"
operator|<<
literal|"<qt>Research Station<br/>Base Camp<br/>Big Mountain</qt>"
expr_stmt|;
name|QStringList
name|ages
decl_stmt|;
name|ages
operator|<<
literal|"20"
operator|<<
literal|"31"
operator|<<
literal|"32"
operator|<<
literal|"19"
operator|<<
literal|"26"
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
literal|5
condition|;
operator|++
name|row
control|)
block|{
name|QStandardItem
modifier|*
name|item
init|=
operator|new
name|QStandardItem
argument_list|(
name|names
index|[
name|row
index|]
argument_list|)
decl_stmt|;
name|model
operator|->
name|setItem
argument_list|(
name|row
argument_list|,
literal|0
argument_list|,
name|item
argument_list|)
expr_stmt|;
name|item
operator|=
operator|new
name|QStandardItem
argument_list|(
name|addresses
index|[
name|row
index|]
argument_list|)
expr_stmt|;
name|model
operator|->
name|setItem
argument_list|(
name|row
argument_list|,
literal|1
argument_list|,
name|item
argument_list|)
expr_stmt|;
name|item
operator|=
operator|new
name|QStandardItem
argument_list|(
name|ages
index|[
name|row
index|]
argument_list|)
expr_stmt|;
name|model
operator|->
name|setItem
argument_list|(
name|row
argument_list|,
literal|2
argument_list|,
name|item
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_comment
comment|//! [Set up the model]
end_comment
begin_comment
comment|//! [Slot for updating the buttons]
end_comment
begin_function
DECL|function|updateButtons
name|void
name|Window
operator|::
name|updateButtons
parameter_list|(
name|int
name|row
parameter_list|)
block|{
name|previousButton
operator|->
name|setEnabled
argument_list|(
name|row
operator|>
literal|0
argument_list|)
expr_stmt|;
name|nextButton
operator|->
name|setEnabled
argument_list|(
name|row
operator|<
name|model
operator|->
name|rowCount
argument_list|()
operator|-
literal|1
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [Slot for updating the buttons]
end_comment
end_unit
