begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of Nokia Corporation and its Subsidiary(-ies) nor **     the names of its contributors may be used to endorse or promote **     products derived from this software without specific prior written **     permission. ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtGui>
end_include
begin_include
include|#
directive|include
file|"dialog.h"
end_include
begin_define
DECL|macro|MESSAGE
define|#
directive|define
name|MESSAGE
define|\
value|Dialog::tr("<p>Message boxes have a caption, a text, " \                "and any number of buttons, each with standard or custom texts." \                "<p>Click a button to close the message box. Pressing the Esc button " \                "will activate the detected escape button (if any).")
end_define
begin_constructor
DECL|function|Dialog
name|Dialog
operator|::
name|Dialog
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
name|errorMessageDialog
operator|=
operator|new
name|QErrorMessage
argument_list|(
name|this
argument_list|)
expr_stmt|;
name|int
name|frameStyle
init|=
name|QFrame
operator|::
name|Sunken
operator||
name|QFrame
operator|::
name|Panel
decl_stmt|;
name|integerLabel
operator|=
operator|new
name|QLabel
expr_stmt|;
name|integerLabel
operator|->
name|setFrameStyle
argument_list|(
name|frameStyle
argument_list|)
expr_stmt|;
name|QPushButton
modifier|*
name|integerButton
init|=
operator|new
name|QPushButton
argument_list|(
name|tr
argument_list|(
literal|"QInputDialog::get&Int()"
argument_list|)
argument_list|)
decl_stmt|;
name|doubleLabel
operator|=
operator|new
name|QLabel
expr_stmt|;
name|doubleLabel
operator|->
name|setFrameStyle
argument_list|(
name|frameStyle
argument_list|)
expr_stmt|;
name|QPushButton
modifier|*
name|doubleButton
init|=
operator|new
name|QPushButton
argument_list|(
name|tr
argument_list|(
literal|"QInputDialog::get&Double()"
argument_list|)
argument_list|)
decl_stmt|;
name|itemLabel
operator|=
operator|new
name|QLabel
expr_stmt|;
name|itemLabel
operator|->
name|setFrameStyle
argument_list|(
name|frameStyle
argument_list|)
expr_stmt|;
name|QPushButton
modifier|*
name|itemButton
init|=
operator|new
name|QPushButton
argument_list|(
name|tr
argument_list|(
literal|"QInputDialog::getIte&m()"
argument_list|)
argument_list|)
decl_stmt|;
name|textLabel
operator|=
operator|new
name|QLabel
expr_stmt|;
name|textLabel
operator|->
name|setFrameStyle
argument_list|(
name|frameStyle
argument_list|)
expr_stmt|;
name|QPushButton
modifier|*
name|textButton
init|=
operator|new
name|QPushButton
argument_list|(
name|tr
argument_list|(
literal|"QInputDialog::get&Text()"
argument_list|)
argument_list|)
decl_stmt|;
name|colorLabel
operator|=
operator|new
name|QLabel
expr_stmt|;
name|colorLabel
operator|->
name|setFrameStyle
argument_list|(
name|frameStyle
argument_list|)
expr_stmt|;
name|QPushButton
modifier|*
name|colorButton
init|=
operator|new
name|QPushButton
argument_list|(
name|tr
argument_list|(
literal|"QColorDialog::get&Color()"
argument_list|)
argument_list|)
decl_stmt|;
name|fontLabel
operator|=
operator|new
name|QLabel
expr_stmt|;
name|fontLabel
operator|->
name|setFrameStyle
argument_list|(
name|frameStyle
argument_list|)
expr_stmt|;
name|QPushButton
modifier|*
name|fontButton
init|=
operator|new
name|QPushButton
argument_list|(
name|tr
argument_list|(
literal|"QFontDialog::get&Font()"
argument_list|)
argument_list|)
decl_stmt|;
name|directoryLabel
operator|=
operator|new
name|QLabel
expr_stmt|;
name|directoryLabel
operator|->
name|setFrameStyle
argument_list|(
name|frameStyle
argument_list|)
expr_stmt|;
name|QPushButton
modifier|*
name|directoryButton
init|=
operator|new
name|QPushButton
argument_list|(
name|tr
argument_list|(
literal|"QFileDialog::getE&xistingDirectory()"
argument_list|)
argument_list|)
decl_stmt|;
name|openFileNameLabel
operator|=
operator|new
name|QLabel
expr_stmt|;
name|openFileNameLabel
operator|->
name|setFrameStyle
argument_list|(
name|frameStyle
argument_list|)
expr_stmt|;
name|QPushButton
modifier|*
name|openFileNameButton
init|=
operator|new
name|QPushButton
argument_list|(
name|tr
argument_list|(
literal|"QFileDialog::get&OpenFileName()"
argument_list|)
argument_list|)
decl_stmt|;
name|openFileNamesLabel
operator|=
operator|new
name|QLabel
expr_stmt|;
name|openFileNamesLabel
operator|->
name|setFrameStyle
argument_list|(
name|frameStyle
argument_list|)
expr_stmt|;
name|QPushButton
modifier|*
name|openFileNamesButton
init|=
operator|new
name|QPushButton
argument_list|(
name|tr
argument_list|(
literal|"QFileDialog::&getOpenFileNames()"
argument_list|)
argument_list|)
decl_stmt|;
name|saveFileNameLabel
operator|=
operator|new
name|QLabel
expr_stmt|;
name|saveFileNameLabel
operator|->
name|setFrameStyle
argument_list|(
name|frameStyle
argument_list|)
expr_stmt|;
name|QPushButton
modifier|*
name|saveFileNameButton
init|=
operator|new
name|QPushButton
argument_list|(
name|tr
argument_list|(
literal|"QFileDialog::get&SaveFileName()"
argument_list|)
argument_list|)
decl_stmt|;
name|criticalLabel
operator|=
operator|new
name|QLabel
expr_stmt|;
name|criticalLabel
operator|->
name|setFrameStyle
argument_list|(
name|frameStyle
argument_list|)
expr_stmt|;
name|QPushButton
modifier|*
name|criticalButton
init|=
operator|new
name|QPushButton
argument_list|(
name|tr
argument_list|(
literal|"QMessageBox::critica&l()"
argument_list|)
argument_list|)
decl_stmt|;
name|informationLabel
operator|=
operator|new
name|QLabel
expr_stmt|;
name|informationLabel
operator|->
name|setFrameStyle
argument_list|(
name|frameStyle
argument_list|)
expr_stmt|;
name|QPushButton
modifier|*
name|informationButton
init|=
operator|new
name|QPushButton
argument_list|(
name|tr
argument_list|(
literal|"QMessageBox::i&nformation()"
argument_list|)
argument_list|)
decl_stmt|;
name|questionLabel
operator|=
operator|new
name|QLabel
expr_stmt|;
name|questionLabel
operator|->
name|setFrameStyle
argument_list|(
name|frameStyle
argument_list|)
expr_stmt|;
name|QPushButton
modifier|*
name|questionButton
init|=
operator|new
name|QPushButton
argument_list|(
name|tr
argument_list|(
literal|"QMessageBox::&question()"
argument_list|)
argument_list|)
decl_stmt|;
name|warningLabel
operator|=
operator|new
name|QLabel
expr_stmt|;
name|warningLabel
operator|->
name|setFrameStyle
argument_list|(
name|frameStyle
argument_list|)
expr_stmt|;
name|QPushButton
modifier|*
name|warningButton
init|=
operator|new
name|QPushButton
argument_list|(
name|tr
argument_list|(
literal|"QMessageBox::&warning()"
argument_list|)
argument_list|)
decl_stmt|;
name|errorLabel
operator|=
operator|new
name|QLabel
expr_stmt|;
name|errorLabel
operator|->
name|setFrameStyle
argument_list|(
name|frameStyle
argument_list|)
expr_stmt|;
name|QPushButton
modifier|*
name|errorButton
init|=
operator|new
name|QPushButton
argument_list|(
name|tr
argument_list|(
literal|"QErrorMessage::showM&essage()"
argument_list|)
argument_list|)
decl_stmt|;
name|connect
argument_list|(
name|integerButton
argument_list|,
name|SIGNAL
argument_list|(
name|clicked
argument_list|()
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|setInteger
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|doubleButton
argument_list|,
name|SIGNAL
argument_list|(
name|clicked
argument_list|()
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|setDouble
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|itemButton
argument_list|,
name|SIGNAL
argument_list|(
name|clicked
argument_list|()
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|setItem
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|textButton
argument_list|,
name|SIGNAL
argument_list|(
name|clicked
argument_list|()
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|setText
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|colorButton
argument_list|,
name|SIGNAL
argument_list|(
name|clicked
argument_list|()
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|setColor
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|fontButton
argument_list|,
name|SIGNAL
argument_list|(
name|clicked
argument_list|()
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|setFont
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|directoryButton
argument_list|,
name|SIGNAL
argument_list|(
name|clicked
argument_list|()
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|setExistingDirectory
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|openFileNameButton
argument_list|,
name|SIGNAL
argument_list|(
name|clicked
argument_list|()
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|setOpenFileName
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|openFileNamesButton
argument_list|,
name|SIGNAL
argument_list|(
name|clicked
argument_list|()
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|setOpenFileNames
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|saveFileNameButton
argument_list|,
name|SIGNAL
argument_list|(
name|clicked
argument_list|()
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|setSaveFileName
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|criticalButton
argument_list|,
name|SIGNAL
argument_list|(
name|clicked
argument_list|()
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|criticalMessage
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|informationButton
argument_list|,
name|SIGNAL
argument_list|(
name|clicked
argument_list|()
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|informationMessage
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|questionButton
argument_list|,
name|SIGNAL
argument_list|(
name|clicked
argument_list|()
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|questionMessage
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|warningButton
argument_list|,
name|SIGNAL
argument_list|(
name|clicked
argument_list|()
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|warningMessage
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|errorButton
argument_list|,
name|SIGNAL
argument_list|(
name|clicked
argument_list|()
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|errorMessage
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|native
operator|=
operator|new
name|QCheckBox
argument_list|(
name|this
argument_list|)
expr_stmt|;
name|native
operator|->
name|setText
argument_list|(
literal|"Use native file dialog."
argument_list|)
expr_stmt|;
name|native
operator|->
name|setChecked
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
literal|1
argument_list|,
literal|250
argument_list|)
expr_stmt|;
name|layout
operator|->
name|addWidget
argument_list|(
name|integerButton
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
name|integerLabel
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
name|doubleButton
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
name|doubleLabel
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
name|itemButton
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
name|itemLabel
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
name|textButton
argument_list|,
literal|3
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|layout
operator|->
name|addWidget
argument_list|(
name|textLabel
argument_list|,
literal|3
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|layout
operator|->
name|addWidget
argument_list|(
name|colorButton
argument_list|,
literal|4
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|layout
operator|->
name|addWidget
argument_list|(
name|colorLabel
argument_list|,
literal|4
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|layout
operator|->
name|addWidget
argument_list|(
name|fontButton
argument_list|,
literal|5
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|layout
operator|->
name|addWidget
argument_list|(
name|fontLabel
argument_list|,
literal|5
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|layout
operator|->
name|addWidget
argument_list|(
name|directoryButton
argument_list|,
literal|6
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|layout
operator|->
name|addWidget
argument_list|(
name|directoryLabel
argument_list|,
literal|6
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|layout
operator|->
name|addWidget
argument_list|(
name|openFileNameButton
argument_list|,
literal|7
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|layout
operator|->
name|addWidget
argument_list|(
name|openFileNameLabel
argument_list|,
literal|7
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|layout
operator|->
name|addWidget
argument_list|(
name|openFileNamesButton
argument_list|,
literal|8
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|layout
operator|->
name|addWidget
argument_list|(
name|openFileNamesLabel
argument_list|,
literal|8
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|layout
operator|->
name|addWidget
argument_list|(
name|saveFileNameButton
argument_list|,
literal|9
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|layout
operator|->
name|addWidget
argument_list|(
name|saveFileNameLabel
argument_list|,
literal|9
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|layout
operator|->
name|addWidget
argument_list|(
name|criticalButton
argument_list|,
literal|10
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|layout
operator|->
name|addWidget
argument_list|(
name|criticalLabel
argument_list|,
literal|10
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|layout
operator|->
name|addWidget
argument_list|(
name|informationButton
argument_list|,
literal|11
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|layout
operator|->
name|addWidget
argument_list|(
name|informationLabel
argument_list|,
literal|11
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|layout
operator|->
name|addWidget
argument_list|(
name|questionButton
argument_list|,
literal|12
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|layout
operator|->
name|addWidget
argument_list|(
name|questionLabel
argument_list|,
literal|12
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|layout
operator|->
name|addWidget
argument_list|(
name|warningButton
argument_list|,
literal|13
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|layout
operator|->
name|addWidget
argument_list|(
name|warningLabel
argument_list|,
literal|13
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|layout
operator|->
name|addWidget
argument_list|(
name|errorButton
argument_list|,
literal|14
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|layout
operator|->
name|addWidget
argument_list|(
name|errorLabel
argument_list|,
literal|14
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|layout
operator|->
name|addWidget
argument_list|(
name|native
argument_list|,
literal|15
argument_list|,
literal|0
argument_list|)
expr_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_SYMBIAN
argument_list|)
operator|||
name|defined
argument_list|(
name|Q_WS_MAEMO_5
argument_list|)
operator|||
name|defined
argument_list|(
name|Q_WS_SIMULATOR
argument_list|)
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
name|QScrollArea
modifier|*
name|scrollArea
init|=
operator|new
name|QScrollArea
argument_list|(
name|this
argument_list|)
decl_stmt|;
name|scrollArea
operator|->
name|setWidget
argument_list|(
name|widget
argument_list|)
expr_stmt|;
name|QHBoxLayout
modifier|*
name|mainLayout
init|=
operator|new
name|QHBoxLayout
decl_stmt|;
name|mainLayout
operator|->
name|addWidget
argument_list|(
name|scrollArea
argument_list|)
expr_stmt|;
name|setLayout
argument_list|(
name|mainLayout
argument_list|)
expr_stmt|;
else|#
directive|else
name|setLayout
argument_list|(
name|layout
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|setWindowTitle
argument_list|(
name|tr
argument_list|(
literal|"Standard Dialogs"
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_function
DECL|function|setInteger
name|void
name|Dialog
operator|::
name|setInteger
parameter_list|()
block|{
comment|//! [0]
name|bool
name|ok
decl_stmt|;
name|int
name|i
init|=
name|QInputDialog
operator|::
name|getInt
argument_list|(
name|this
argument_list|,
name|tr
argument_list|(
literal|"QInputDialog::getInteger()"
argument_list|)
argument_list|,
name|tr
argument_list|(
literal|"Percentage:"
argument_list|)
argument_list|,
literal|25
argument_list|,
literal|0
argument_list|,
literal|100
argument_list|,
literal|1
argument_list|,
operator|&
name|ok
argument_list|)
decl_stmt|;
if|if
condition|(
name|ok
condition|)
name|integerLabel
operator|->
name|setText
argument_list|(
name|tr
argument_list|(
literal|"%1%"
argument_list|)
operator|.
name|arg
argument_list|(
name|i
argument_list|)
argument_list|)
expr_stmt|;
comment|//! [0]
block|}
end_function
begin_function
DECL|function|setDouble
name|void
name|Dialog
operator|::
name|setDouble
parameter_list|()
block|{
comment|//! [1]
name|bool
name|ok
decl_stmt|;
name|double
name|d
init|=
name|QInputDialog
operator|::
name|getDouble
argument_list|(
name|this
argument_list|,
name|tr
argument_list|(
literal|"QInputDialog::getDouble()"
argument_list|)
argument_list|,
name|tr
argument_list|(
literal|"Amount:"
argument_list|)
argument_list|,
literal|37.56
argument_list|,
operator|-
literal|10000
argument_list|,
literal|10000
argument_list|,
literal|2
argument_list|,
operator|&
name|ok
argument_list|)
decl_stmt|;
if|if
condition|(
name|ok
condition|)
name|doubleLabel
operator|->
name|setText
argument_list|(
name|QString
argument_list|(
literal|"$%1"
argument_list|)
operator|.
name|arg
argument_list|(
name|d
argument_list|)
argument_list|)
expr_stmt|;
comment|//! [1]
block|}
end_function
begin_function
DECL|function|setItem
name|void
name|Dialog
operator|::
name|setItem
parameter_list|()
block|{
comment|//! [2]
name|QStringList
name|items
decl_stmt|;
name|items
operator|<<
name|tr
argument_list|(
literal|"Spring"
argument_list|)
operator|<<
name|tr
argument_list|(
literal|"Summer"
argument_list|)
operator|<<
name|tr
argument_list|(
literal|"Fall"
argument_list|)
operator|<<
name|tr
argument_list|(
literal|"Winter"
argument_list|)
expr_stmt|;
name|bool
name|ok
decl_stmt|;
name|QString
name|item
init|=
name|QInputDialog
operator|::
name|getItem
argument_list|(
name|this
argument_list|,
name|tr
argument_list|(
literal|"QInputDialog::getItem()"
argument_list|)
argument_list|,
name|tr
argument_list|(
literal|"Season:"
argument_list|)
argument_list|,
name|items
argument_list|,
literal|0
argument_list|,
literal|false
argument_list|,
operator|&
name|ok
argument_list|)
decl_stmt|;
if|if
condition|(
name|ok
operator|&&
operator|!
name|item
operator|.
name|isEmpty
argument_list|()
condition|)
name|itemLabel
operator|->
name|setText
argument_list|(
name|item
argument_list|)
expr_stmt|;
comment|//! [2]
block|}
end_function
begin_function
DECL|function|setText
name|void
name|Dialog
operator|::
name|setText
parameter_list|()
block|{
comment|//! [3]
name|bool
name|ok
decl_stmt|;
name|QString
name|text
init|=
name|QInputDialog
operator|::
name|getText
argument_list|(
name|this
argument_list|,
name|tr
argument_list|(
literal|"QInputDialog::getText()"
argument_list|)
argument_list|,
name|tr
argument_list|(
literal|"User name:"
argument_list|)
argument_list|,
name|QLineEdit
operator|::
name|Normal
argument_list|,
name|QDir
operator|::
name|home
argument_list|()
operator|.
name|dirName
argument_list|()
argument_list|,
operator|&
name|ok
argument_list|)
decl_stmt|;
if|if
condition|(
name|ok
operator|&&
operator|!
name|text
operator|.
name|isEmpty
argument_list|()
condition|)
name|textLabel
operator|->
name|setText
argument_list|(
name|text
argument_list|)
expr_stmt|;
comment|//! [3]
block|}
end_function
begin_function
DECL|function|setColor
name|void
name|Dialog
operator|::
name|setColor
parameter_list|()
block|{
name|QColor
name|color
decl_stmt|;
if|if
condition|(
name|native
operator|->
name|isChecked
argument_list|()
condition|)
name|color
operator|=
name|QColorDialog
operator|::
name|getColor
argument_list|(
name|Qt
operator|::
name|green
argument_list|,
name|this
argument_list|)
expr_stmt|;
else|else
name|color
operator|=
name|QColorDialog
operator|::
name|getColor
argument_list|(
name|Qt
operator|::
name|green
argument_list|,
name|this
argument_list|,
literal|"Select Color"
argument_list|,
name|QColorDialog
operator|::
name|DontUseNativeDialog
argument_list|)
expr_stmt|;
if|if
condition|(
name|color
operator|.
name|isValid
argument_list|()
condition|)
block|{
name|colorLabel
operator|->
name|setText
argument_list|(
name|color
operator|.
name|name
argument_list|()
argument_list|)
expr_stmt|;
name|colorLabel
operator|->
name|setPalette
argument_list|(
name|QPalette
argument_list|(
name|color
argument_list|)
argument_list|)
expr_stmt|;
name|colorLabel
operator|->
name|setAutoFillBackground
argument_list|(
literal|true
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|setFont
name|void
name|Dialog
operator|::
name|setFont
parameter_list|()
block|{
name|bool
name|ok
decl_stmt|;
name|QFont
name|font
init|=
name|QFontDialog
operator|::
name|getFont
argument_list|(
operator|&
name|ok
argument_list|,
name|QFont
argument_list|(
name|fontLabel
operator|->
name|text
argument_list|()
argument_list|)
argument_list|,
name|this
argument_list|)
decl_stmt|;
if|if
condition|(
name|ok
condition|)
block|{
name|fontLabel
operator|->
name|setText
argument_list|(
name|font
operator|.
name|key
argument_list|()
argument_list|)
expr_stmt|;
name|fontLabel
operator|->
name|setFont
argument_list|(
name|font
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|setExistingDirectory
name|void
name|Dialog
operator|::
name|setExistingDirectory
parameter_list|()
block|{
name|QFileDialog
operator|::
name|Options
name|options
init|=
name|QFileDialog
operator|::
name|DontResolveSymlinks
operator||
name|QFileDialog
operator|::
name|ShowDirsOnly
decl_stmt|;
if|if
condition|(
operator|!
name|native
operator|->
name|isChecked
argument_list|()
condition|)
name|options
operator||=
name|QFileDialog
operator|::
name|DontUseNativeDialog
expr_stmt|;
name|QString
name|directory
init|=
name|QFileDialog
operator|::
name|getExistingDirectory
argument_list|(
name|this
argument_list|,
name|tr
argument_list|(
literal|"QFileDialog::getExistingDirectory()"
argument_list|)
argument_list|,
name|directoryLabel
operator|->
name|text
argument_list|()
argument_list|,
name|options
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|directory
operator|.
name|isEmpty
argument_list|()
condition|)
name|directoryLabel
operator|->
name|setText
argument_list|(
name|directory
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|setOpenFileName
name|void
name|Dialog
operator|::
name|setOpenFileName
parameter_list|()
block|{
name|QFileDialog
operator|::
name|Options
name|options
decl_stmt|;
if|if
condition|(
operator|!
name|native
operator|->
name|isChecked
argument_list|()
condition|)
name|options
operator||=
name|QFileDialog
operator|::
name|DontUseNativeDialog
expr_stmt|;
name|QString
name|selectedFilter
decl_stmt|;
name|QString
name|fileName
init|=
name|QFileDialog
operator|::
name|getOpenFileName
argument_list|(
name|this
argument_list|,
name|tr
argument_list|(
literal|"QFileDialog::getOpenFileName()"
argument_list|)
argument_list|,
name|openFileNameLabel
operator|->
name|text
argument_list|()
argument_list|,
name|tr
argument_list|(
literal|"All Files (*);;Text Files (*.txt)"
argument_list|)
argument_list|,
operator|&
name|selectedFilter
argument_list|,
name|options
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|fileName
operator|.
name|isEmpty
argument_list|()
condition|)
name|openFileNameLabel
operator|->
name|setText
argument_list|(
name|fileName
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|setOpenFileNames
name|void
name|Dialog
operator|::
name|setOpenFileNames
parameter_list|()
block|{
name|QFileDialog
operator|::
name|Options
name|options
decl_stmt|;
if|if
condition|(
operator|!
name|native
operator|->
name|isChecked
argument_list|()
condition|)
name|options
operator||=
name|QFileDialog
operator|::
name|DontUseNativeDialog
expr_stmt|;
name|QString
name|selectedFilter
decl_stmt|;
name|QStringList
name|files
init|=
name|QFileDialog
operator|::
name|getOpenFileNames
argument_list|(
name|this
argument_list|,
name|tr
argument_list|(
literal|"QFileDialog::getOpenFileNames()"
argument_list|)
argument_list|,
name|openFilesPath
argument_list|,
name|tr
argument_list|(
literal|"All Files (*);;Text Files (*.txt)"
argument_list|)
argument_list|,
operator|&
name|selectedFilter
argument_list|,
name|options
argument_list|)
decl_stmt|;
if|if
condition|(
name|files
operator|.
name|count
argument_list|()
condition|)
block|{
name|openFilesPath
operator|=
name|files
index|[
literal|0
index|]
expr_stmt|;
name|openFileNamesLabel
operator|->
name|setText
argument_list|(
name|QString
argument_list|(
literal|"[%1]"
argument_list|)
operator|.
name|arg
argument_list|(
name|files
operator|.
name|join
argument_list|(
literal|", "
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|setSaveFileName
name|void
name|Dialog
operator|::
name|setSaveFileName
parameter_list|()
block|{
name|QFileDialog
operator|::
name|Options
name|options
decl_stmt|;
if|if
condition|(
operator|!
name|native
operator|->
name|isChecked
argument_list|()
condition|)
name|options
operator||=
name|QFileDialog
operator|::
name|DontUseNativeDialog
expr_stmt|;
name|QString
name|selectedFilter
decl_stmt|;
name|QString
name|fileName
init|=
name|QFileDialog
operator|::
name|getSaveFileName
argument_list|(
name|this
argument_list|,
name|tr
argument_list|(
literal|"QFileDialog::getSaveFileName()"
argument_list|)
argument_list|,
name|saveFileNameLabel
operator|->
name|text
argument_list|()
argument_list|,
name|tr
argument_list|(
literal|"All Files (*);;Text Files (*.txt)"
argument_list|)
argument_list|,
operator|&
name|selectedFilter
argument_list|,
name|options
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|fileName
operator|.
name|isEmpty
argument_list|()
condition|)
name|saveFileNameLabel
operator|->
name|setText
argument_list|(
name|fileName
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|criticalMessage
name|void
name|Dialog
operator|::
name|criticalMessage
parameter_list|()
block|{
name|QMessageBox
operator|::
name|StandardButton
name|reply
decl_stmt|;
name|reply
operator|=
name|QMessageBox
operator|::
name|critical
argument_list|(
name|this
argument_list|,
name|tr
argument_list|(
literal|"QMessageBox::critical()"
argument_list|)
argument_list|,
name|MESSAGE
argument_list|,
name|QMessageBox
operator|::
name|Abort
operator||
name|QMessageBox
operator|::
name|Retry
operator||
name|QMessageBox
operator|::
name|Ignore
argument_list|)
expr_stmt|;
if|if
condition|(
name|reply
operator|==
name|QMessageBox
operator|::
name|Abort
condition|)
name|criticalLabel
operator|->
name|setText
argument_list|(
name|tr
argument_list|(
literal|"Abort"
argument_list|)
argument_list|)
expr_stmt|;
elseif|else
if|if
condition|(
name|reply
operator|==
name|QMessageBox
operator|::
name|Retry
condition|)
name|criticalLabel
operator|->
name|setText
argument_list|(
name|tr
argument_list|(
literal|"Retry"
argument_list|)
argument_list|)
expr_stmt|;
else|else
name|criticalLabel
operator|->
name|setText
argument_list|(
name|tr
argument_list|(
literal|"Ignore"
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|informationMessage
name|void
name|Dialog
operator|::
name|informationMessage
parameter_list|()
block|{
name|QMessageBox
operator|::
name|StandardButton
name|reply
decl_stmt|;
name|reply
operator|=
name|QMessageBox
operator|::
name|information
argument_list|(
name|this
argument_list|,
name|tr
argument_list|(
literal|"QMessageBox::information()"
argument_list|)
argument_list|,
name|MESSAGE
argument_list|)
expr_stmt|;
if|if
condition|(
name|reply
operator|==
name|QMessageBox
operator|::
name|Ok
condition|)
name|informationLabel
operator|->
name|setText
argument_list|(
name|tr
argument_list|(
literal|"OK"
argument_list|)
argument_list|)
expr_stmt|;
else|else
name|informationLabel
operator|->
name|setText
argument_list|(
name|tr
argument_list|(
literal|"Escape"
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|questionMessage
name|void
name|Dialog
operator|::
name|questionMessage
parameter_list|()
block|{
name|QMessageBox
operator|::
name|StandardButton
name|reply
decl_stmt|;
name|reply
operator|=
name|QMessageBox
operator|::
name|question
argument_list|(
name|this
argument_list|,
name|tr
argument_list|(
literal|"QMessageBox::question()"
argument_list|)
argument_list|,
name|MESSAGE
argument_list|,
name|QMessageBox
operator|::
name|Yes
operator||
name|QMessageBox
operator|::
name|No
operator||
name|QMessageBox
operator|::
name|Cancel
argument_list|)
expr_stmt|;
if|if
condition|(
name|reply
operator|==
name|QMessageBox
operator|::
name|Yes
condition|)
name|questionLabel
operator|->
name|setText
argument_list|(
name|tr
argument_list|(
literal|"Yes"
argument_list|)
argument_list|)
expr_stmt|;
elseif|else
if|if
condition|(
name|reply
operator|==
name|QMessageBox
operator|::
name|No
condition|)
name|questionLabel
operator|->
name|setText
argument_list|(
name|tr
argument_list|(
literal|"No"
argument_list|)
argument_list|)
expr_stmt|;
else|else
name|questionLabel
operator|->
name|setText
argument_list|(
name|tr
argument_list|(
literal|"Cancel"
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|warningMessage
name|void
name|Dialog
operator|::
name|warningMessage
parameter_list|()
block|{
name|QMessageBox
name|msgBox
argument_list|(
name|QMessageBox
operator|::
name|Warning
argument_list|,
name|tr
argument_list|(
literal|"QMessageBox::warning()"
argument_list|)
argument_list|,
name|MESSAGE
argument_list|,
literal|0
argument_list|,
name|this
argument_list|)
decl_stmt|;
name|msgBox
operator|.
name|addButton
argument_list|(
name|tr
argument_list|(
literal|"Save&Again"
argument_list|)
argument_list|,
name|QMessageBox
operator|::
name|AcceptRole
argument_list|)
expr_stmt|;
name|msgBox
operator|.
name|addButton
argument_list|(
name|tr
argument_list|(
literal|"&Continue"
argument_list|)
argument_list|,
name|QMessageBox
operator|::
name|RejectRole
argument_list|)
expr_stmt|;
if|if
condition|(
name|msgBox
operator|.
name|exec
argument_list|()
operator|==
name|QMessageBox
operator|::
name|AcceptRole
condition|)
name|warningLabel
operator|->
name|setText
argument_list|(
name|tr
argument_list|(
literal|"Save Again"
argument_list|)
argument_list|)
expr_stmt|;
else|else
name|warningLabel
operator|->
name|setText
argument_list|(
name|tr
argument_list|(
literal|"Continue"
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|errorMessage
name|void
name|Dialog
operator|::
name|errorMessage
parameter_list|()
block|{
name|errorMessageDialog
operator|->
name|showMessage
argument_list|(
name|tr
argument_list|(
literal|"This dialog shows and remembers error messages. "
literal|"If the checkbox is checked (as it is by default), "
literal|"the shown message will be shown again, "
literal|"but if the user unchecks the box the message "
literal|"will not appear again if QErrorMessage::showMessage() "
literal|"is called with the same message."
argument_list|)
argument_list|)
expr_stmt|;
name|errorLabel
operator|->
name|setText
argument_list|(
name|tr
argument_list|(
literal|"If the box is unchecked, the message "
literal|"won't appear again."
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
end_unit
