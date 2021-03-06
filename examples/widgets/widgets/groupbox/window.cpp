begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** BSD License Usage ** Alternatively, you may use this file under the terms of the BSD license ** as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of The Qt Company Ltd nor the names of its **     contributors may be used to endorse or promote products derived **     from this software without specific prior written permission. ** ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
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
begin_comment
comment|//! [0]
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
name|QGridLayout
modifier|*
name|grid
init|=
operator|new
name|QGridLayout
decl_stmt|;
name|grid
operator|->
name|addWidget
argument_list|(
name|createFirstExclusiveGroup
argument_list|()
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|grid
operator|->
name|addWidget
argument_list|(
name|createSecondExclusiveGroup
argument_list|()
argument_list|,
literal|1
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|grid
operator|->
name|addWidget
argument_list|(
name|createNonExclusiveGroup
argument_list|()
argument_list|,
literal|0
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|grid
operator|->
name|addWidget
argument_list|(
name|createPushButtonGroup
argument_list|()
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|setLayout
argument_list|(
name|grid
argument_list|)
expr_stmt|;
name|setWindowTitle
argument_list|(
name|tr
argument_list|(
literal|"Group Boxes"
argument_list|)
argument_list|)
expr_stmt|;
name|resize
argument_list|(
literal|480
argument_list|,
literal|320
argument_list|)
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
DECL|function|createFirstExclusiveGroup
name|QGroupBox
modifier|*
name|Window
operator|::
name|createFirstExclusiveGroup
parameter_list|()
block|{
comment|//! [2]
name|QGroupBox
modifier|*
name|groupBox
init|=
operator|new
name|QGroupBox
argument_list|(
name|tr
argument_list|(
literal|"Exclusive Radio Buttons"
argument_list|)
argument_list|)
decl_stmt|;
name|QRadioButton
modifier|*
name|radio1
init|=
operator|new
name|QRadioButton
argument_list|(
name|tr
argument_list|(
literal|"&Radio button 1"
argument_list|)
argument_list|)
decl_stmt|;
name|QRadioButton
modifier|*
name|radio2
init|=
operator|new
name|QRadioButton
argument_list|(
name|tr
argument_list|(
literal|"R&adio button 2"
argument_list|)
argument_list|)
decl_stmt|;
name|QRadioButton
modifier|*
name|radio3
init|=
operator|new
name|QRadioButton
argument_list|(
name|tr
argument_list|(
literal|"Ra&dio button 3"
argument_list|)
argument_list|)
decl_stmt|;
name|radio1
operator|->
name|setChecked
argument_list|(
literal|true
argument_list|)
expr_stmt|;
comment|//! [1] //! [3]
name|QVBoxLayout
modifier|*
name|vbox
init|=
operator|new
name|QVBoxLayout
decl_stmt|;
name|vbox
operator|->
name|addWidget
argument_list|(
name|radio1
argument_list|)
expr_stmt|;
name|vbox
operator|->
name|addWidget
argument_list|(
name|radio2
argument_list|)
expr_stmt|;
name|vbox
operator|->
name|addWidget
argument_list|(
name|radio3
argument_list|)
expr_stmt|;
name|vbox
operator|->
name|addStretch
argument_list|(
literal|1
argument_list|)
expr_stmt|;
name|groupBox
operator|->
name|setLayout
argument_list|(
name|vbox
argument_list|)
expr_stmt|;
comment|//! [2]
return|return
name|groupBox
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
DECL|function|createSecondExclusiveGroup
name|QGroupBox
modifier|*
name|Window
operator|::
name|createSecondExclusiveGroup
parameter_list|()
block|{
name|QGroupBox
modifier|*
name|groupBox
init|=
operator|new
name|QGroupBox
argument_list|(
name|tr
argument_list|(
literal|"E&xclusive Radio Buttons"
argument_list|)
argument_list|)
decl_stmt|;
name|groupBox
operator|->
name|setCheckable
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|groupBox
operator|->
name|setChecked
argument_list|(
literal|false
argument_list|)
expr_stmt|;
comment|//! [4]
comment|//! [5]
name|QRadioButton
modifier|*
name|radio1
init|=
operator|new
name|QRadioButton
argument_list|(
name|tr
argument_list|(
literal|"Rad&io button 1"
argument_list|)
argument_list|)
decl_stmt|;
name|QRadioButton
modifier|*
name|radio2
init|=
operator|new
name|QRadioButton
argument_list|(
name|tr
argument_list|(
literal|"Radi&o button 2"
argument_list|)
argument_list|)
decl_stmt|;
name|QRadioButton
modifier|*
name|radio3
init|=
operator|new
name|QRadioButton
argument_list|(
name|tr
argument_list|(
literal|"Radio&button 3"
argument_list|)
argument_list|)
decl_stmt|;
name|radio1
operator|->
name|setChecked
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|QCheckBox
modifier|*
name|checkBox
init|=
operator|new
name|QCheckBox
argument_list|(
name|tr
argument_list|(
literal|"Ind&ependent checkbox"
argument_list|)
argument_list|)
decl_stmt|;
name|checkBox
operator|->
name|setChecked
argument_list|(
literal|true
argument_list|)
expr_stmt|;
comment|//! [5]
comment|//! [6]
name|QVBoxLayout
modifier|*
name|vbox
init|=
operator|new
name|QVBoxLayout
decl_stmt|;
name|vbox
operator|->
name|addWidget
argument_list|(
name|radio1
argument_list|)
expr_stmt|;
name|vbox
operator|->
name|addWidget
argument_list|(
name|radio2
argument_list|)
expr_stmt|;
name|vbox
operator|->
name|addWidget
argument_list|(
name|radio3
argument_list|)
expr_stmt|;
name|vbox
operator|->
name|addWidget
argument_list|(
name|checkBox
argument_list|)
expr_stmt|;
name|vbox
operator|->
name|addStretch
argument_list|(
literal|1
argument_list|)
expr_stmt|;
name|groupBox
operator|->
name|setLayout
argument_list|(
name|vbox
argument_list|)
expr_stmt|;
return|return
name|groupBox
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
DECL|function|createNonExclusiveGroup
name|QGroupBox
modifier|*
name|Window
operator|::
name|createNonExclusiveGroup
parameter_list|()
block|{
name|QGroupBox
modifier|*
name|groupBox
init|=
operator|new
name|QGroupBox
argument_list|(
name|tr
argument_list|(
literal|"Non-Exclusive Checkboxes"
argument_list|)
argument_list|)
decl_stmt|;
name|groupBox
operator|->
name|setFlat
argument_list|(
literal|true
argument_list|)
expr_stmt|;
comment|//! [7]
comment|//! [8]
name|QCheckBox
modifier|*
name|checkBox1
init|=
operator|new
name|QCheckBox
argument_list|(
name|tr
argument_list|(
literal|"&Checkbox 1"
argument_list|)
argument_list|)
decl_stmt|;
name|QCheckBox
modifier|*
name|checkBox2
init|=
operator|new
name|QCheckBox
argument_list|(
name|tr
argument_list|(
literal|"C&heckbox 2"
argument_list|)
argument_list|)
decl_stmt|;
name|checkBox2
operator|->
name|setChecked
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|QCheckBox
modifier|*
name|tristateBox
init|=
operator|new
name|QCheckBox
argument_list|(
name|tr
argument_list|(
literal|"Tri-&state button"
argument_list|)
argument_list|)
decl_stmt|;
name|tristateBox
operator|->
name|setTristate
argument_list|(
literal|true
argument_list|)
expr_stmt|;
comment|//! [8]
name|tristateBox
operator|->
name|setCheckState
argument_list|(
name|Qt
operator|::
name|PartiallyChecked
argument_list|)
expr_stmt|;
comment|//! [9]
name|QVBoxLayout
modifier|*
name|vbox
init|=
operator|new
name|QVBoxLayout
decl_stmt|;
name|vbox
operator|->
name|addWidget
argument_list|(
name|checkBox1
argument_list|)
expr_stmt|;
name|vbox
operator|->
name|addWidget
argument_list|(
name|checkBox2
argument_list|)
expr_stmt|;
name|vbox
operator|->
name|addWidget
argument_list|(
name|tristateBox
argument_list|)
expr_stmt|;
name|vbox
operator|->
name|addStretch
argument_list|(
literal|1
argument_list|)
expr_stmt|;
name|groupBox
operator|->
name|setLayout
argument_list|(
name|vbox
argument_list|)
expr_stmt|;
return|return
name|groupBox
return|;
block|}
end_function
begin_comment
comment|//! [9]
end_comment
begin_comment
comment|//! [10]
end_comment
begin_function
DECL|function|createPushButtonGroup
name|QGroupBox
modifier|*
name|Window
operator|::
name|createPushButtonGroup
parameter_list|()
block|{
name|QGroupBox
modifier|*
name|groupBox
init|=
operator|new
name|QGroupBox
argument_list|(
name|tr
argument_list|(
literal|"&Push Buttons"
argument_list|)
argument_list|)
decl_stmt|;
name|groupBox
operator|->
name|setCheckable
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|groupBox
operator|->
name|setChecked
argument_list|(
literal|true
argument_list|)
expr_stmt|;
comment|//! [10]
comment|//! [11]
name|QPushButton
modifier|*
name|pushButton
init|=
operator|new
name|QPushButton
argument_list|(
name|tr
argument_list|(
literal|"&Normal Button"
argument_list|)
argument_list|)
decl_stmt|;
name|QPushButton
modifier|*
name|toggleButton
init|=
operator|new
name|QPushButton
argument_list|(
name|tr
argument_list|(
literal|"&Toggle Button"
argument_list|)
argument_list|)
decl_stmt|;
name|toggleButton
operator|->
name|setCheckable
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|toggleButton
operator|->
name|setChecked
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|QPushButton
modifier|*
name|flatButton
init|=
operator|new
name|QPushButton
argument_list|(
name|tr
argument_list|(
literal|"&Flat Button"
argument_list|)
argument_list|)
decl_stmt|;
name|flatButton
operator|->
name|setFlat
argument_list|(
literal|true
argument_list|)
expr_stmt|;
comment|//! [11]
comment|//! [12]
name|QPushButton
modifier|*
name|popupButton
init|=
operator|new
name|QPushButton
argument_list|(
name|tr
argument_list|(
literal|"Pop&up Button"
argument_list|)
argument_list|)
decl_stmt|;
name|QMenu
modifier|*
name|menu
init|=
operator|new
name|QMenu
argument_list|(
name|this
argument_list|)
decl_stmt|;
name|menu
operator|->
name|addAction
argument_list|(
name|tr
argument_list|(
literal|"&First Item"
argument_list|)
argument_list|)
expr_stmt|;
name|menu
operator|->
name|addAction
argument_list|(
name|tr
argument_list|(
literal|"&Second Item"
argument_list|)
argument_list|)
expr_stmt|;
name|menu
operator|->
name|addAction
argument_list|(
name|tr
argument_list|(
literal|"&Third Item"
argument_list|)
argument_list|)
expr_stmt|;
name|menu
operator|->
name|addAction
argument_list|(
name|tr
argument_list|(
literal|"F&ourth Item"
argument_list|)
argument_list|)
expr_stmt|;
name|popupButton
operator|->
name|setMenu
argument_list|(
name|menu
argument_list|)
expr_stmt|;
comment|//! [12]
name|QAction
modifier|*
name|newAction
init|=
name|menu
operator|->
name|addAction
argument_list|(
name|tr
argument_list|(
literal|"Submenu"
argument_list|)
argument_list|)
decl_stmt|;
name|QMenu
modifier|*
name|subMenu
init|=
operator|new
name|QMenu
argument_list|(
name|tr
argument_list|(
literal|"Popup Submenu"
argument_list|)
argument_list|)
decl_stmt|;
name|subMenu
operator|->
name|addAction
argument_list|(
name|tr
argument_list|(
literal|"Item 1"
argument_list|)
argument_list|)
expr_stmt|;
name|subMenu
operator|->
name|addAction
argument_list|(
name|tr
argument_list|(
literal|"Item 2"
argument_list|)
argument_list|)
expr_stmt|;
name|subMenu
operator|->
name|addAction
argument_list|(
name|tr
argument_list|(
literal|"Item 3"
argument_list|)
argument_list|)
expr_stmt|;
name|newAction
operator|->
name|setMenu
argument_list|(
name|subMenu
argument_list|)
expr_stmt|;
comment|//! [13]
name|QVBoxLayout
modifier|*
name|vbox
init|=
operator|new
name|QVBoxLayout
decl_stmt|;
name|vbox
operator|->
name|addWidget
argument_list|(
name|pushButton
argument_list|)
expr_stmt|;
name|vbox
operator|->
name|addWidget
argument_list|(
name|toggleButton
argument_list|)
expr_stmt|;
name|vbox
operator|->
name|addWidget
argument_list|(
name|flatButton
argument_list|)
expr_stmt|;
name|vbox
operator|->
name|addWidget
argument_list|(
name|popupButton
argument_list|)
expr_stmt|;
name|vbox
operator|->
name|addStretch
argument_list|(
literal|1
argument_list|)
expr_stmt|;
name|groupBox
operator|->
name|setLayout
argument_list|(
name|vbox
argument_list|)
expr_stmt|;
return|return
name|groupBox
return|;
block|}
end_function
begin_comment
comment|//! [13]
end_comment
end_unit
