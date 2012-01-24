begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of Nokia Corporation and its Subsidiary(-ies) nor **     the names of its contributors may be used to endorse or promote **     products derived from this software without specific prior written **     permission. ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtWidgets>
end_include
begin_include
include|#
directive|include
file|"norwegianwoodstyle.h"
end_include
begin_include
include|#
directive|include
file|"widgetgallery.h"
end_include
begin_comment
comment|//! [0]
end_comment
begin_constructor
DECL|function|WidgetGallery
name|WidgetGallery
operator|::
name|WidgetGallery
parameter_list|(
name|QWidget
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QDialog
argument_list|(
name|parent
argument_list|)
block|{
name|originalPalette
operator|=
name|QApplication
operator|::
name|palette
argument_list|()
expr_stmt|;
name|styleComboBox
operator|=
operator|new
name|QComboBox
expr_stmt|;
name|styleComboBox
operator|->
name|addItem
argument_list|(
literal|"NorwegianWood"
argument_list|)
expr_stmt|;
name|styleComboBox
operator|->
name|addItems
argument_list|(
name|QStyleFactory
operator|::
name|keys
argument_list|()
argument_list|)
expr_stmt|;
name|styleLabel
operator|=
operator|new
name|QLabel
argument_list|(
name|tr
argument_list|(
literal|"&Style:"
argument_list|)
argument_list|)
expr_stmt|;
name|styleLabel
operator|->
name|setBuddy
argument_list|(
name|styleComboBox
argument_list|)
expr_stmt|;
name|useStylePaletteCheckBox
operator|=
operator|new
name|QCheckBox
argument_list|(
name|tr
argument_list|(
literal|"&Use style's standard palette"
argument_list|)
argument_list|)
expr_stmt|;
name|useStylePaletteCheckBox
operator|->
name|setChecked
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|disableWidgetsCheckBox
operator|=
operator|new
name|QCheckBox
argument_list|(
name|tr
argument_list|(
literal|"&Disable widgets"
argument_list|)
argument_list|)
expr_stmt|;
name|createTopLeftGroupBox
argument_list|()
expr_stmt|;
name|createTopRightGroupBox
argument_list|()
expr_stmt|;
name|createBottomLeftTabWidget
argument_list|()
expr_stmt|;
name|createBottomRightGroupBox
argument_list|()
expr_stmt|;
name|createProgressBar
argument_list|()
expr_stmt|;
comment|//! [0]
comment|//! [1]
name|connect
argument_list|(
name|styleComboBox
argument_list|,
name|SIGNAL
argument_list|(
name|activated
argument_list|(
name|QString
argument_list|)
argument_list|)
argument_list|,
comment|//! [1] //! [2]
name|this
argument_list|,
name|SLOT
argument_list|(
name|changeStyle
argument_list|(
name|QString
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|useStylePaletteCheckBox
argument_list|,
name|SIGNAL
argument_list|(
name|toggled
argument_list|(
name|bool
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|changePalette
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|disableWidgetsCheckBox
argument_list|,
name|SIGNAL
argument_list|(
name|toggled
argument_list|(
name|bool
argument_list|)
argument_list|)
argument_list|,
name|topLeftGroupBox
argument_list|,
name|SLOT
argument_list|(
name|setDisabled
argument_list|(
name|bool
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|disableWidgetsCheckBox
argument_list|,
name|SIGNAL
argument_list|(
name|toggled
argument_list|(
name|bool
argument_list|)
argument_list|)
argument_list|,
name|topRightGroupBox
argument_list|,
name|SLOT
argument_list|(
name|setDisabled
argument_list|(
name|bool
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|disableWidgetsCheckBox
argument_list|,
name|SIGNAL
argument_list|(
name|toggled
argument_list|(
name|bool
argument_list|)
argument_list|)
argument_list|,
name|bottomLeftTabWidget
argument_list|,
name|SLOT
argument_list|(
name|setDisabled
argument_list|(
name|bool
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|disableWidgetsCheckBox
argument_list|,
name|SIGNAL
argument_list|(
name|toggled
argument_list|(
name|bool
argument_list|)
argument_list|)
argument_list|,
name|bottomRightGroupBox
argument_list|,
name|SLOT
argument_list|(
name|setDisabled
argument_list|(
name|bool
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
comment|//! [2]
comment|//! [3]
name|QHBoxLayout
modifier|*
name|topLayout
init|=
operator|new
name|QHBoxLayout
decl_stmt|;
comment|//! [3] //! [4]
name|topLayout
operator|->
name|addWidget
argument_list|(
name|styleLabel
argument_list|)
expr_stmt|;
name|topLayout
operator|->
name|addWidget
argument_list|(
name|styleComboBox
argument_list|)
expr_stmt|;
name|topLayout
operator|->
name|addStretch
argument_list|(
literal|1
argument_list|)
expr_stmt|;
name|topLayout
operator|->
name|addWidget
argument_list|(
name|useStylePaletteCheckBox
argument_list|)
expr_stmt|;
name|topLayout
operator|->
name|addWidget
argument_list|(
name|disableWidgetsCheckBox
argument_list|)
expr_stmt|;
name|QGridLayout
modifier|*
name|mainLayout
init|=
operator|new
name|QGridLayout
decl_stmt|;
name|mainLayout
operator|->
name|addLayout
argument_list|(
name|topLayout
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|1
argument_list|,
literal|2
argument_list|)
expr_stmt|;
name|mainLayout
operator|->
name|addWidget
argument_list|(
name|topLeftGroupBox
argument_list|,
literal|1
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|mainLayout
operator|->
name|addWidget
argument_list|(
name|topRightGroupBox
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|mainLayout
operator|->
name|addWidget
argument_list|(
name|bottomLeftTabWidget
argument_list|,
literal|2
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|mainLayout
operator|->
name|addWidget
argument_list|(
name|bottomRightGroupBox
argument_list|,
literal|2
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|mainLayout
operator|->
name|addWidget
argument_list|(
name|progressBar
argument_list|,
literal|3
argument_list|,
literal|0
argument_list|,
literal|1
argument_list|,
literal|2
argument_list|)
expr_stmt|;
name|mainLayout
operator|->
name|setRowStretch
argument_list|(
literal|1
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|mainLayout
operator|->
name|setRowStretch
argument_list|(
literal|2
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|mainLayout
operator|->
name|setColumnStretch
argument_list|(
literal|0
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|mainLayout
operator|->
name|setColumnStretch
argument_list|(
literal|1
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|setLayout
argument_list|(
name|mainLayout
argument_list|)
expr_stmt|;
name|setWindowTitle
argument_list|(
name|tr
argument_list|(
literal|"Styles"
argument_list|)
argument_list|)
expr_stmt|;
name|changeStyle
argument_list|(
literal|"NorwegianWood"
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_comment
comment|//! [4]
end_comment
begin_comment
comment|//! [5]
end_comment
begin_function
DECL|function|changeStyle
name|void
name|WidgetGallery
operator|::
name|changeStyle
parameter_list|(
specifier|const
name|QString
modifier|&
name|styleName
parameter_list|)
comment|//! [5] //! [6]
block|{
if|if
condition|(
name|styleName
operator|==
literal|"NorwegianWood"
condition|)
block|{
name|QApplication
operator|::
name|setStyle
argument_list|(
operator|new
name|NorwegianWoodStyle
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|QApplication
operator|::
name|setStyle
argument_list|(
name|QStyleFactory
operator|::
name|create
argument_list|(
name|styleName
argument_list|)
argument_list|)
expr_stmt|;
block|}
name|changePalette
argument_list|()
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [6]
end_comment
begin_comment
comment|//! [7]
end_comment
begin_function
DECL|function|changePalette
name|void
name|WidgetGallery
operator|::
name|changePalette
parameter_list|()
comment|//! [7] //! [8]
block|{
if|if
condition|(
name|useStylePaletteCheckBox
operator|->
name|isChecked
argument_list|()
condition|)
name|QApplication
operator|::
name|setPalette
argument_list|(
name|QApplication
operator|::
name|style
argument_list|()
operator|->
name|standardPalette
argument_list|()
argument_list|)
expr_stmt|;
else|else
name|QApplication
operator|::
name|setPalette
argument_list|(
name|originalPalette
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [8]
end_comment
begin_comment
comment|//! [9]
end_comment
begin_function
DECL|function|advanceProgressBar
name|void
name|WidgetGallery
operator|::
name|advanceProgressBar
parameter_list|()
comment|//! [9] //! [10]
block|{
name|int
name|curVal
init|=
name|progressBar
operator|->
name|value
argument_list|()
decl_stmt|;
name|int
name|maxVal
init|=
name|progressBar
operator|->
name|maximum
argument_list|()
decl_stmt|;
name|progressBar
operator|->
name|setValue
argument_list|(
name|curVal
operator|+
operator|(
name|maxVal
operator|-
name|curVal
operator|)
operator|/
literal|100
argument_list|)
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
DECL|function|createTopLeftGroupBox
name|void
name|WidgetGallery
operator|::
name|createTopLeftGroupBox
parameter_list|()
comment|//! [11] //! [12]
block|{
name|topLeftGroupBox
operator|=
operator|new
name|QGroupBox
argument_list|(
name|tr
argument_list|(
literal|"Group 1"
argument_list|)
argument_list|)
expr_stmt|;
name|radioButton1
operator|=
operator|new
name|QRadioButton
argument_list|(
name|tr
argument_list|(
literal|"Radio button 1"
argument_list|)
argument_list|)
expr_stmt|;
name|radioButton2
operator|=
operator|new
name|QRadioButton
argument_list|(
name|tr
argument_list|(
literal|"Radio button 2"
argument_list|)
argument_list|)
expr_stmt|;
name|radioButton3
operator|=
operator|new
name|QRadioButton
argument_list|(
name|tr
argument_list|(
literal|"Radio button 3"
argument_list|)
argument_list|)
expr_stmt|;
name|radioButton1
operator|->
name|setChecked
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|checkBox
operator|=
operator|new
name|QCheckBox
argument_list|(
name|tr
argument_list|(
literal|"Tri-state check box"
argument_list|)
argument_list|)
expr_stmt|;
name|checkBox
operator|->
name|setTristate
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|checkBox
operator|->
name|setCheckState
argument_list|(
name|Qt
operator|::
name|PartiallyChecked
argument_list|)
expr_stmt|;
name|QVBoxLayout
modifier|*
name|layout
init|=
operator|new
name|QVBoxLayout
decl_stmt|;
name|layout
operator|->
name|addWidget
argument_list|(
name|radioButton1
argument_list|)
expr_stmt|;
name|layout
operator|->
name|addWidget
argument_list|(
name|radioButton2
argument_list|)
expr_stmt|;
name|layout
operator|->
name|addWidget
argument_list|(
name|radioButton3
argument_list|)
expr_stmt|;
name|layout
operator|->
name|addWidget
argument_list|(
name|checkBox
argument_list|)
expr_stmt|;
name|layout
operator|->
name|addStretch
argument_list|(
literal|1
argument_list|)
expr_stmt|;
name|topLeftGroupBox
operator|->
name|setLayout
argument_list|(
name|layout
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [12]
end_comment
begin_function
DECL|function|createTopRightGroupBox
name|void
name|WidgetGallery
operator|::
name|createTopRightGroupBox
parameter_list|()
block|{
name|topRightGroupBox
operator|=
operator|new
name|QGroupBox
argument_list|(
name|tr
argument_list|(
literal|"Group 2"
argument_list|)
argument_list|)
expr_stmt|;
name|defaultPushButton
operator|=
operator|new
name|QPushButton
argument_list|(
name|tr
argument_list|(
literal|"Default Push Button"
argument_list|)
argument_list|)
expr_stmt|;
name|defaultPushButton
operator|->
name|setDefault
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|togglePushButton
operator|=
operator|new
name|QPushButton
argument_list|(
name|tr
argument_list|(
literal|"Toggle Push Button"
argument_list|)
argument_list|)
expr_stmt|;
name|togglePushButton
operator|->
name|setCheckable
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|togglePushButton
operator|->
name|setChecked
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|flatPushButton
operator|=
operator|new
name|QPushButton
argument_list|(
name|tr
argument_list|(
literal|"Flat Push Button"
argument_list|)
argument_list|)
expr_stmt|;
name|flatPushButton
operator|->
name|setFlat
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|QVBoxLayout
modifier|*
name|layout
init|=
operator|new
name|QVBoxLayout
decl_stmt|;
name|layout
operator|->
name|addWidget
argument_list|(
name|defaultPushButton
argument_list|)
expr_stmt|;
name|layout
operator|->
name|addWidget
argument_list|(
name|togglePushButton
argument_list|)
expr_stmt|;
name|layout
operator|->
name|addWidget
argument_list|(
name|flatPushButton
argument_list|)
expr_stmt|;
name|layout
operator|->
name|addStretch
argument_list|(
literal|1
argument_list|)
expr_stmt|;
name|topRightGroupBox
operator|->
name|setLayout
argument_list|(
name|layout
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|createBottomLeftTabWidget
name|void
name|WidgetGallery
operator|::
name|createBottomLeftTabWidget
parameter_list|()
block|{
name|bottomLeftTabWidget
operator|=
operator|new
name|QTabWidget
expr_stmt|;
name|bottomLeftTabWidget
operator|->
name|setSizePolicy
argument_list|(
name|QSizePolicy
operator|::
name|Preferred
argument_list|,
name|QSizePolicy
operator|::
name|Ignored
argument_list|)
expr_stmt|;
name|QWidget
modifier|*
name|tab1
init|=
operator|new
name|QWidget
decl_stmt|;
name|tableWidget
operator|=
operator|new
name|QTableWidget
argument_list|(
literal|10
argument_list|,
literal|10
argument_list|)
expr_stmt|;
name|QHBoxLayout
modifier|*
name|tab1hbox
init|=
operator|new
name|QHBoxLayout
decl_stmt|;
name|tab1hbox
operator|->
name|setMargin
argument_list|(
literal|5
argument_list|)
expr_stmt|;
name|tab1hbox
operator|->
name|addWidget
argument_list|(
name|tableWidget
argument_list|)
expr_stmt|;
name|tab1
operator|->
name|setLayout
argument_list|(
name|tab1hbox
argument_list|)
expr_stmt|;
name|QWidget
modifier|*
name|tab2
init|=
operator|new
name|QWidget
decl_stmt|;
name|textEdit
operator|=
operator|new
name|QTextEdit
expr_stmt|;
name|textEdit
operator|->
name|setPlainText
argument_list|(
name|tr
argument_list|(
literal|"Twinkle, twinkle, little star,\n"
literal|"How I wonder what you are.\n"
literal|"Up above the world so high,\n"
literal|"Like a diamond in the sky.\n"
literal|"Twinkle, twinkle, little star,\n"
literal|"How I wonder what you are!\n"
argument_list|)
argument_list|)
expr_stmt|;
name|QHBoxLayout
modifier|*
name|tab2hbox
init|=
operator|new
name|QHBoxLayout
decl_stmt|;
name|tab2hbox
operator|->
name|setMargin
argument_list|(
literal|5
argument_list|)
expr_stmt|;
name|tab2hbox
operator|->
name|addWidget
argument_list|(
name|textEdit
argument_list|)
expr_stmt|;
name|tab2
operator|->
name|setLayout
argument_list|(
name|tab2hbox
argument_list|)
expr_stmt|;
name|bottomLeftTabWidget
operator|->
name|addTab
argument_list|(
name|tab1
argument_list|,
name|tr
argument_list|(
literal|"&Table"
argument_list|)
argument_list|)
expr_stmt|;
name|bottomLeftTabWidget
operator|->
name|addTab
argument_list|(
name|tab2
argument_list|,
name|tr
argument_list|(
literal|"Text&Edit"
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|createBottomRightGroupBox
name|void
name|WidgetGallery
operator|::
name|createBottomRightGroupBox
parameter_list|()
block|{
name|bottomRightGroupBox
operator|=
operator|new
name|QGroupBox
argument_list|(
name|tr
argument_list|(
literal|"Group 3"
argument_list|)
argument_list|)
expr_stmt|;
name|bottomRightGroupBox
operator|->
name|setCheckable
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|bottomRightGroupBox
operator|->
name|setChecked
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|lineEdit
operator|=
operator|new
name|QLineEdit
argument_list|(
literal|"s3cRe7"
argument_list|)
expr_stmt|;
name|lineEdit
operator|->
name|setEchoMode
argument_list|(
name|QLineEdit
operator|::
name|Password
argument_list|)
expr_stmt|;
name|spinBox
operator|=
operator|new
name|QSpinBox
argument_list|(
name|bottomRightGroupBox
argument_list|)
expr_stmt|;
name|spinBox
operator|->
name|setValue
argument_list|(
literal|50
argument_list|)
expr_stmt|;
name|dateTimeEdit
operator|=
operator|new
name|QDateTimeEdit
argument_list|(
name|bottomRightGroupBox
argument_list|)
expr_stmt|;
name|dateTimeEdit
operator|->
name|setDateTime
argument_list|(
name|QDateTime
operator|::
name|currentDateTime
argument_list|()
argument_list|)
expr_stmt|;
name|slider
operator|=
operator|new
name|QSlider
argument_list|(
name|Qt
operator|::
name|Horizontal
argument_list|,
name|bottomRightGroupBox
argument_list|)
expr_stmt|;
name|slider
operator|->
name|setValue
argument_list|(
literal|40
argument_list|)
expr_stmt|;
name|scrollBar
operator|=
operator|new
name|QScrollBar
argument_list|(
name|Qt
operator|::
name|Horizontal
argument_list|,
name|bottomRightGroupBox
argument_list|)
expr_stmt|;
name|scrollBar
operator|->
name|setValue
argument_list|(
literal|60
argument_list|)
expr_stmt|;
name|dial
operator|=
operator|new
name|QDial
argument_list|(
name|bottomRightGroupBox
argument_list|)
expr_stmt|;
name|dial
operator|->
name|setValue
argument_list|(
literal|30
argument_list|)
expr_stmt|;
name|dial
operator|->
name|setNotchesVisible
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
name|lineEdit
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|1
argument_list|,
literal|2
argument_list|)
expr_stmt|;
name|layout
operator|->
name|addWidget
argument_list|(
name|spinBox
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
name|layout
operator|->
name|addWidget
argument_list|(
name|dateTimeEdit
argument_list|,
literal|2
argument_list|,
literal|0
argument_list|,
literal|1
argument_list|,
literal|2
argument_list|)
expr_stmt|;
name|layout
operator|->
name|addWidget
argument_list|(
name|slider
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
name|scrollBar
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
name|dial
argument_list|,
literal|3
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
name|setRowStretch
argument_list|(
literal|5
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|bottomRightGroupBox
operator|->
name|setLayout
argument_list|(
name|layout
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [13]
end_comment
begin_function
DECL|function|createProgressBar
name|void
name|WidgetGallery
operator|::
name|createProgressBar
parameter_list|()
block|{
name|progressBar
operator|=
operator|new
name|QProgressBar
expr_stmt|;
name|progressBar
operator|->
name|setRange
argument_list|(
literal|0
argument_list|,
literal|10000
argument_list|)
expr_stmt|;
name|progressBar
operator|->
name|setValue
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|QTimer
modifier|*
name|timer
init|=
operator|new
name|QTimer
argument_list|(
name|this
argument_list|)
decl_stmt|;
name|connect
argument_list|(
name|timer
argument_list|,
name|SIGNAL
argument_list|(
name|timeout
argument_list|()
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|advanceProgressBar
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|timer
operator|->
name|start
argument_list|(
literal|1000
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [13]
end_comment
end_unit
