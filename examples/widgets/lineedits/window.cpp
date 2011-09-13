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
name|QGroupBox
modifier|*
name|echoGroup
init|=
operator|new
name|QGroupBox
argument_list|(
name|tr
argument_list|(
literal|"Echo"
argument_list|)
argument_list|)
decl_stmt|;
name|QLabel
modifier|*
name|echoLabel
init|=
operator|new
name|QLabel
argument_list|(
name|tr
argument_list|(
literal|"Mode:"
argument_list|)
argument_list|)
decl_stmt|;
name|QComboBox
modifier|*
name|echoComboBox
init|=
operator|new
name|QComboBox
decl_stmt|;
name|echoComboBox
operator|->
name|addItem
argument_list|(
name|tr
argument_list|(
literal|"Normal"
argument_list|)
argument_list|)
expr_stmt|;
name|echoComboBox
operator|->
name|addItem
argument_list|(
name|tr
argument_list|(
literal|"Password"
argument_list|)
argument_list|)
expr_stmt|;
name|echoComboBox
operator|->
name|addItem
argument_list|(
name|tr
argument_list|(
literal|"PasswordEchoOnEdit"
argument_list|)
argument_list|)
expr_stmt|;
name|echoComboBox
operator|->
name|addItem
argument_list|(
name|tr
argument_list|(
literal|"No Echo"
argument_list|)
argument_list|)
expr_stmt|;
name|echoLineEdit
operator|=
operator|new
name|QLineEdit
expr_stmt|;
name|echoLineEdit
operator|->
name|setFocus
argument_list|()
expr_stmt|;
comment|//! [0]
comment|//! [1]
name|QGroupBox
modifier|*
name|validatorGroup
init|=
operator|new
name|QGroupBox
argument_list|(
name|tr
argument_list|(
literal|"Validator"
argument_list|)
argument_list|)
decl_stmt|;
name|QLabel
modifier|*
name|validatorLabel
init|=
operator|new
name|QLabel
argument_list|(
name|tr
argument_list|(
literal|"Type:"
argument_list|)
argument_list|)
decl_stmt|;
name|QComboBox
modifier|*
name|validatorComboBox
init|=
operator|new
name|QComboBox
decl_stmt|;
name|validatorComboBox
operator|->
name|addItem
argument_list|(
name|tr
argument_list|(
literal|"No validator"
argument_list|)
argument_list|)
expr_stmt|;
name|validatorComboBox
operator|->
name|addItem
argument_list|(
name|tr
argument_list|(
literal|"Integer validator"
argument_list|)
argument_list|)
expr_stmt|;
name|validatorComboBox
operator|->
name|addItem
argument_list|(
name|tr
argument_list|(
literal|"Double validator"
argument_list|)
argument_list|)
expr_stmt|;
name|validatorLineEdit
operator|=
operator|new
name|QLineEdit
expr_stmt|;
comment|//! [1]
comment|//! [2]
name|QGroupBox
modifier|*
name|alignmentGroup
init|=
operator|new
name|QGroupBox
argument_list|(
name|tr
argument_list|(
literal|"Alignment"
argument_list|)
argument_list|)
decl_stmt|;
name|QLabel
modifier|*
name|alignmentLabel
init|=
operator|new
name|QLabel
argument_list|(
name|tr
argument_list|(
literal|"Type:"
argument_list|)
argument_list|)
decl_stmt|;
name|QComboBox
modifier|*
name|alignmentComboBox
init|=
operator|new
name|QComboBox
decl_stmt|;
name|alignmentComboBox
operator|->
name|addItem
argument_list|(
name|tr
argument_list|(
literal|"Left"
argument_list|)
argument_list|)
expr_stmt|;
name|alignmentComboBox
operator|->
name|addItem
argument_list|(
name|tr
argument_list|(
literal|"Centered"
argument_list|)
argument_list|)
expr_stmt|;
name|alignmentComboBox
operator|->
name|addItem
argument_list|(
name|tr
argument_list|(
literal|"Right"
argument_list|)
argument_list|)
expr_stmt|;
name|alignmentLineEdit
operator|=
operator|new
name|QLineEdit
expr_stmt|;
comment|//! [2]
comment|//! [3]
name|QGroupBox
modifier|*
name|inputMaskGroup
init|=
operator|new
name|QGroupBox
argument_list|(
name|tr
argument_list|(
literal|"Input mask"
argument_list|)
argument_list|)
decl_stmt|;
name|QLabel
modifier|*
name|inputMaskLabel
init|=
operator|new
name|QLabel
argument_list|(
name|tr
argument_list|(
literal|"Type:"
argument_list|)
argument_list|)
decl_stmt|;
name|QComboBox
modifier|*
name|inputMaskComboBox
init|=
operator|new
name|QComboBox
decl_stmt|;
name|inputMaskComboBox
operator|->
name|addItem
argument_list|(
name|tr
argument_list|(
literal|"No mask"
argument_list|)
argument_list|)
expr_stmt|;
name|inputMaskComboBox
operator|->
name|addItem
argument_list|(
name|tr
argument_list|(
literal|"Phone number"
argument_list|)
argument_list|)
expr_stmt|;
name|inputMaskComboBox
operator|->
name|addItem
argument_list|(
name|tr
argument_list|(
literal|"ISO date"
argument_list|)
argument_list|)
expr_stmt|;
name|inputMaskComboBox
operator|->
name|addItem
argument_list|(
name|tr
argument_list|(
literal|"License key"
argument_list|)
argument_list|)
expr_stmt|;
name|inputMaskLineEdit
operator|=
operator|new
name|QLineEdit
expr_stmt|;
comment|//! [3]
comment|//! [4]
name|QGroupBox
modifier|*
name|accessGroup
init|=
operator|new
name|QGroupBox
argument_list|(
name|tr
argument_list|(
literal|"Access"
argument_list|)
argument_list|)
decl_stmt|;
name|QLabel
modifier|*
name|accessLabel
init|=
operator|new
name|QLabel
argument_list|(
name|tr
argument_list|(
literal|"Read-only:"
argument_list|)
argument_list|)
decl_stmt|;
name|QComboBox
modifier|*
name|accessComboBox
init|=
operator|new
name|QComboBox
decl_stmt|;
name|accessComboBox
operator|->
name|addItem
argument_list|(
name|tr
argument_list|(
literal|"False"
argument_list|)
argument_list|)
expr_stmt|;
name|accessComboBox
operator|->
name|addItem
argument_list|(
name|tr
argument_list|(
literal|"True"
argument_list|)
argument_list|)
expr_stmt|;
name|accessLineEdit
operator|=
operator|new
name|QLineEdit
expr_stmt|;
comment|//! [4]
comment|//! [5]
name|connect
argument_list|(
name|echoComboBox
argument_list|,
name|SIGNAL
argument_list|(
name|activated
argument_list|(
name|int
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|echoChanged
argument_list|(
name|int
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|validatorComboBox
argument_list|,
name|SIGNAL
argument_list|(
name|activated
argument_list|(
name|int
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|validatorChanged
argument_list|(
name|int
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|alignmentComboBox
argument_list|,
name|SIGNAL
argument_list|(
name|activated
argument_list|(
name|int
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|alignmentChanged
argument_list|(
name|int
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|inputMaskComboBox
argument_list|,
name|SIGNAL
argument_list|(
name|activated
argument_list|(
name|int
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|inputMaskChanged
argument_list|(
name|int
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|accessComboBox
argument_list|,
name|SIGNAL
argument_list|(
name|activated
argument_list|(
name|int
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|accessChanged
argument_list|(
name|int
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
comment|//! [5]
comment|//! [6]
name|QGridLayout
modifier|*
name|echoLayout
init|=
operator|new
name|QGridLayout
decl_stmt|;
name|echoLayout
operator|->
name|addWidget
argument_list|(
name|echoLabel
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|echoLayout
operator|->
name|addWidget
argument_list|(
name|echoComboBox
argument_list|,
literal|0
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|echoLayout
operator|->
name|addWidget
argument_list|(
name|echoLineEdit
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
name|echoGroup
operator|->
name|setLayout
argument_list|(
name|echoLayout
argument_list|)
expr_stmt|;
comment|//! [6]
comment|//! [7]
name|QGridLayout
modifier|*
name|validatorLayout
init|=
operator|new
name|QGridLayout
decl_stmt|;
name|validatorLayout
operator|->
name|addWidget
argument_list|(
name|validatorLabel
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|validatorLayout
operator|->
name|addWidget
argument_list|(
name|validatorComboBox
argument_list|,
literal|0
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|validatorLayout
operator|->
name|addWidget
argument_list|(
name|validatorLineEdit
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
name|validatorGroup
operator|->
name|setLayout
argument_list|(
name|validatorLayout
argument_list|)
expr_stmt|;
name|QGridLayout
modifier|*
name|alignmentLayout
init|=
operator|new
name|QGridLayout
decl_stmt|;
name|alignmentLayout
operator|->
name|addWidget
argument_list|(
name|alignmentLabel
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|alignmentLayout
operator|->
name|addWidget
argument_list|(
name|alignmentComboBox
argument_list|,
literal|0
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|alignmentLayout
operator|->
name|addWidget
argument_list|(
name|alignmentLineEdit
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
name|alignmentGroup
operator|->
name|setLayout
argument_list|(
name|alignmentLayout
argument_list|)
expr_stmt|;
name|QGridLayout
modifier|*
name|inputMaskLayout
init|=
operator|new
name|QGridLayout
decl_stmt|;
name|inputMaskLayout
operator|->
name|addWidget
argument_list|(
name|inputMaskLabel
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|inputMaskLayout
operator|->
name|addWidget
argument_list|(
name|inputMaskComboBox
argument_list|,
literal|0
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|inputMaskLayout
operator|->
name|addWidget
argument_list|(
name|inputMaskLineEdit
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
name|inputMaskGroup
operator|->
name|setLayout
argument_list|(
name|inputMaskLayout
argument_list|)
expr_stmt|;
name|QGridLayout
modifier|*
name|accessLayout
init|=
operator|new
name|QGridLayout
decl_stmt|;
name|accessLayout
operator|->
name|addWidget
argument_list|(
name|accessLabel
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|accessLayout
operator|->
name|addWidget
argument_list|(
name|accessComboBox
argument_list|,
literal|0
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|accessLayout
operator|->
name|addWidget
argument_list|(
name|accessLineEdit
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
name|accessGroup
operator|->
name|setLayout
argument_list|(
name|accessLayout
argument_list|)
expr_stmt|;
comment|//! [7]
comment|//! [8]
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
name|echoGroup
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
name|validatorGroup
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
name|alignmentGroup
argument_list|,
literal|2
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|layout
operator|->
name|addWidget
argument_list|(
name|inputMaskGroup
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
name|accessGroup
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
literal|"Line Edits"
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_comment
comment|//! [8]
end_comment
begin_comment
comment|//! [9]
end_comment
begin_function
DECL|function|echoChanged
name|void
name|Window
operator|::
name|echoChanged
parameter_list|(
name|int
name|index
parameter_list|)
block|{
switch|switch
condition|(
name|index
condition|)
block|{
case|case
literal|0
case|:
name|echoLineEdit
operator|->
name|setEchoMode
argument_list|(
name|QLineEdit
operator|::
name|Normal
argument_list|)
expr_stmt|;
break|break;
case|case
literal|1
case|:
name|echoLineEdit
operator|->
name|setEchoMode
argument_list|(
name|QLineEdit
operator|::
name|Password
argument_list|)
expr_stmt|;
break|break;
case|case
literal|2
case|:
name|echoLineEdit
operator|->
name|setEchoMode
argument_list|(
name|QLineEdit
operator|::
name|PasswordEchoOnEdit
argument_list|)
expr_stmt|;
break|break;
case|case
literal|3
case|:
name|echoLineEdit
operator|->
name|setEchoMode
argument_list|(
name|QLineEdit
operator|::
name|NoEcho
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_comment
comment|//! [9]
end_comment
begin_comment
comment|//! [10]
end_comment
begin_function
DECL|function|validatorChanged
name|void
name|Window
operator|::
name|validatorChanged
parameter_list|(
name|int
name|index
parameter_list|)
block|{
switch|switch
condition|(
name|index
condition|)
block|{
case|case
literal|0
case|:
name|validatorLineEdit
operator|->
name|setValidator
argument_list|(
literal|0
argument_list|)
expr_stmt|;
break|break;
case|case
literal|1
case|:
name|validatorLineEdit
operator|->
name|setValidator
argument_list|(
operator|new
name|QIntValidator
argument_list|(
name|validatorLineEdit
argument_list|)
argument_list|)
expr_stmt|;
break|break;
case|case
literal|2
case|:
name|validatorLineEdit
operator|->
name|setValidator
argument_list|(
operator|new
name|QDoubleValidator
argument_list|(
operator|-
literal|999.0
argument_list|,
literal|999.0
argument_list|,
literal|2
argument_list|,
name|validatorLineEdit
argument_list|)
argument_list|)
expr_stmt|;
block|}
name|validatorLineEdit
operator|->
name|clear
argument_list|()
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [10]
end_comment
begin_comment
comment|//! [11]
end_comment
begin_function
DECL|function|alignmentChanged
name|void
name|Window
operator|::
name|alignmentChanged
parameter_list|(
name|int
name|index
parameter_list|)
block|{
switch|switch
condition|(
name|index
condition|)
block|{
case|case
literal|0
case|:
name|alignmentLineEdit
operator|->
name|setAlignment
argument_list|(
name|Qt
operator|::
name|AlignLeft
argument_list|)
expr_stmt|;
break|break;
case|case
literal|1
case|:
name|alignmentLineEdit
operator|->
name|setAlignment
argument_list|(
name|Qt
operator|::
name|AlignCenter
argument_list|)
expr_stmt|;
break|break;
case|case
literal|2
case|:
name|alignmentLineEdit
operator|->
name|setAlignment
argument_list|(
name|Qt
operator|::
name|AlignRight
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_comment
comment|//! [11]
end_comment
begin_comment
comment|//! [12]
end_comment
begin_function
DECL|function|inputMaskChanged
name|void
name|Window
operator|::
name|inputMaskChanged
parameter_list|(
name|int
name|index
parameter_list|)
block|{
switch|switch
condition|(
name|index
condition|)
block|{
case|case
literal|0
case|:
name|inputMaskLineEdit
operator|->
name|setInputMask
argument_list|(
literal|""
argument_list|)
expr_stmt|;
break|break;
case|case
literal|1
case|:
name|inputMaskLineEdit
operator|->
name|setInputMask
argument_list|(
literal|"+99 99 99 99 99;_"
argument_list|)
expr_stmt|;
break|break;
case|case
literal|2
case|:
name|inputMaskLineEdit
operator|->
name|setInputMask
argument_list|(
literal|"0000-00-00"
argument_list|)
expr_stmt|;
name|inputMaskLineEdit
operator|->
name|setText
argument_list|(
literal|"00000000"
argument_list|)
expr_stmt|;
name|inputMaskLineEdit
operator|->
name|setCursorPosition
argument_list|(
literal|0
argument_list|)
expr_stmt|;
break|break;
case|case
literal|3
case|:
name|inputMaskLineEdit
operator|->
name|setInputMask
argument_list|(
literal|">AAAAA-AAAAA-AAAAA-AAAAA-AAAAA;#"
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_comment
comment|//! [12]
end_comment
begin_comment
comment|//! [13]
end_comment
begin_function
DECL|function|accessChanged
name|void
name|Window
operator|::
name|accessChanged
parameter_list|(
name|int
name|index
parameter_list|)
block|{
switch|switch
condition|(
name|index
condition|)
block|{
case|case
literal|0
case|:
name|accessLineEdit
operator|->
name|setReadOnly
argument_list|(
literal|false
argument_list|)
expr_stmt|;
break|break;
case|case
literal|1
case|:
name|accessLineEdit
operator|->
name|setReadOnly
argument_list|(
literal|true
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_comment
comment|//! [13]
end_comment
end_unit
