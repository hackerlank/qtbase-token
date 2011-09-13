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
file|"slidersgroup.h"
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
name|horizontalSliders
operator|=
operator|new
name|SlidersGroup
argument_list|(
name|Qt
operator|::
name|Horizontal
argument_list|,
name|tr
argument_list|(
literal|"Horizontal"
argument_list|)
argument_list|)
expr_stmt|;
name|verticalSliders
operator|=
operator|new
name|SlidersGroup
argument_list|(
name|Qt
operator|::
name|Vertical
argument_list|,
name|tr
argument_list|(
literal|"Vertical"
argument_list|)
argument_list|)
expr_stmt|;
name|stackedWidget
operator|=
operator|new
name|QStackedWidget
expr_stmt|;
name|stackedWidget
operator|->
name|addWidget
argument_list|(
name|horizontalSliders
argument_list|)
expr_stmt|;
name|stackedWidget
operator|->
name|addWidget
argument_list|(
name|verticalSliders
argument_list|)
expr_stmt|;
name|createControls
argument_list|(
name|tr
argument_list|(
literal|"Controls"
argument_list|)
argument_list|)
expr_stmt|;
comment|//! [0]
comment|//! [1]
name|connect
argument_list|(
name|horizontalSliders
argument_list|,
name|SIGNAL
argument_list|(
name|valueChanged
argument_list|(
name|int
argument_list|)
argument_list|)
argument_list|,
comment|//! [1] //! [2]
name|verticalSliders
argument_list|,
name|SLOT
argument_list|(
name|setValue
argument_list|(
name|int
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|verticalSliders
argument_list|,
name|SIGNAL
argument_list|(
name|valueChanged
argument_list|(
name|int
argument_list|)
argument_list|)
argument_list|,
name|valueSpinBox
argument_list|,
name|SLOT
argument_list|(
name|setValue
argument_list|(
name|int
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|valueSpinBox
argument_list|,
name|SIGNAL
argument_list|(
name|valueChanged
argument_list|(
name|int
argument_list|)
argument_list|)
argument_list|,
name|horizontalSliders
argument_list|,
name|SLOT
argument_list|(
name|setValue
argument_list|(
name|int
argument_list|)
argument_list|)
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
name|controlsGroup
argument_list|)
expr_stmt|;
name|layout
operator|->
name|addWidget
argument_list|(
name|stackedWidget
argument_list|)
expr_stmt|;
name|setLayout
argument_list|(
name|layout
argument_list|)
expr_stmt|;
name|minimumSpinBox
operator|->
name|setValue
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|maximumSpinBox
operator|->
name|setValue
argument_list|(
literal|20
argument_list|)
expr_stmt|;
name|valueSpinBox
operator|->
name|setValue
argument_list|(
literal|5
argument_list|)
expr_stmt|;
name|setWindowTitle
argument_list|(
name|tr
argument_list|(
literal|"Sliders"
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_comment
comment|//! [2]
end_comment
begin_comment
comment|//! [3]
end_comment
begin_function
DECL|function|createControls
name|void
name|Window
operator|::
name|createControls
parameter_list|(
specifier|const
name|QString
modifier|&
name|title
parameter_list|)
comment|//! [3] //! [4]
block|{
name|controlsGroup
operator|=
operator|new
name|QGroupBox
argument_list|(
name|title
argument_list|)
expr_stmt|;
name|minimumLabel
operator|=
operator|new
name|QLabel
argument_list|(
name|tr
argument_list|(
literal|"Minimum value:"
argument_list|)
argument_list|)
expr_stmt|;
name|maximumLabel
operator|=
operator|new
name|QLabel
argument_list|(
name|tr
argument_list|(
literal|"Maximum value:"
argument_list|)
argument_list|)
expr_stmt|;
name|valueLabel
operator|=
operator|new
name|QLabel
argument_list|(
name|tr
argument_list|(
literal|"Current value:"
argument_list|)
argument_list|)
expr_stmt|;
name|invertedAppearance
operator|=
operator|new
name|QCheckBox
argument_list|(
name|tr
argument_list|(
literal|"Inverted appearance"
argument_list|)
argument_list|)
expr_stmt|;
name|invertedKeyBindings
operator|=
operator|new
name|QCheckBox
argument_list|(
name|tr
argument_list|(
literal|"Inverted key bindings"
argument_list|)
argument_list|)
expr_stmt|;
comment|//! [4] //! [5]
name|minimumSpinBox
operator|=
operator|new
name|QSpinBox
expr_stmt|;
comment|//! [5] //! [6]
name|minimumSpinBox
operator|->
name|setRange
argument_list|(
operator|-
literal|100
argument_list|,
literal|100
argument_list|)
expr_stmt|;
name|minimumSpinBox
operator|->
name|setSingleStep
argument_list|(
literal|1
argument_list|)
expr_stmt|;
name|maximumSpinBox
operator|=
operator|new
name|QSpinBox
expr_stmt|;
name|maximumSpinBox
operator|->
name|setRange
argument_list|(
operator|-
literal|100
argument_list|,
literal|100
argument_list|)
expr_stmt|;
name|maximumSpinBox
operator|->
name|setSingleStep
argument_list|(
literal|1
argument_list|)
expr_stmt|;
name|valueSpinBox
operator|=
operator|new
name|QSpinBox
expr_stmt|;
name|valueSpinBox
operator|->
name|setRange
argument_list|(
operator|-
literal|100
argument_list|,
literal|100
argument_list|)
expr_stmt|;
name|valueSpinBox
operator|->
name|setSingleStep
argument_list|(
literal|1
argument_list|)
expr_stmt|;
name|orientationCombo
operator|=
operator|new
name|QComboBox
expr_stmt|;
name|orientationCombo
operator|->
name|addItem
argument_list|(
name|tr
argument_list|(
literal|"Horizontal slider-like widgets"
argument_list|)
argument_list|)
expr_stmt|;
name|orientationCombo
operator|->
name|addItem
argument_list|(
name|tr
argument_list|(
literal|"Vertical slider-like widgets"
argument_list|)
argument_list|)
expr_stmt|;
comment|//! [6] //! [7]
name|connect
argument_list|(
name|orientationCombo
argument_list|,
name|SIGNAL
argument_list|(
name|activated
argument_list|(
name|int
argument_list|)
argument_list|)
argument_list|,
comment|//! [7] //! [8]
name|stackedWidget
argument_list|,
name|SLOT
argument_list|(
name|setCurrentIndex
argument_list|(
name|int
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|minimumSpinBox
argument_list|,
name|SIGNAL
argument_list|(
name|valueChanged
argument_list|(
name|int
argument_list|)
argument_list|)
argument_list|,
name|horizontalSliders
argument_list|,
name|SLOT
argument_list|(
name|setMinimum
argument_list|(
name|int
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|minimumSpinBox
argument_list|,
name|SIGNAL
argument_list|(
name|valueChanged
argument_list|(
name|int
argument_list|)
argument_list|)
argument_list|,
name|verticalSliders
argument_list|,
name|SLOT
argument_list|(
name|setMinimum
argument_list|(
name|int
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|maximumSpinBox
argument_list|,
name|SIGNAL
argument_list|(
name|valueChanged
argument_list|(
name|int
argument_list|)
argument_list|)
argument_list|,
name|horizontalSliders
argument_list|,
name|SLOT
argument_list|(
name|setMaximum
argument_list|(
name|int
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|maximumSpinBox
argument_list|,
name|SIGNAL
argument_list|(
name|valueChanged
argument_list|(
name|int
argument_list|)
argument_list|)
argument_list|,
name|verticalSliders
argument_list|,
name|SLOT
argument_list|(
name|setMaximum
argument_list|(
name|int
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|invertedAppearance
argument_list|,
name|SIGNAL
argument_list|(
name|toggled
argument_list|(
name|bool
argument_list|)
argument_list|)
argument_list|,
name|horizontalSliders
argument_list|,
name|SLOT
argument_list|(
name|invertAppearance
argument_list|(
name|bool
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|invertedAppearance
argument_list|,
name|SIGNAL
argument_list|(
name|toggled
argument_list|(
name|bool
argument_list|)
argument_list|)
argument_list|,
name|verticalSliders
argument_list|,
name|SLOT
argument_list|(
name|invertAppearance
argument_list|(
name|bool
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|invertedKeyBindings
argument_list|,
name|SIGNAL
argument_list|(
name|toggled
argument_list|(
name|bool
argument_list|)
argument_list|)
argument_list|,
name|horizontalSliders
argument_list|,
name|SLOT
argument_list|(
name|invertKeyBindings
argument_list|(
name|bool
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|invertedKeyBindings
argument_list|,
name|SIGNAL
argument_list|(
name|toggled
argument_list|(
name|bool
argument_list|)
argument_list|)
argument_list|,
name|verticalSliders
argument_list|,
name|SLOT
argument_list|(
name|invertKeyBindings
argument_list|(
name|bool
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|QGridLayout
modifier|*
name|controlsLayout
init|=
operator|new
name|QGridLayout
decl_stmt|;
name|controlsLayout
operator|->
name|addWidget
argument_list|(
name|minimumLabel
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|controlsLayout
operator|->
name|addWidget
argument_list|(
name|maximumLabel
argument_list|,
literal|1
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|controlsLayout
operator|->
name|addWidget
argument_list|(
name|valueLabel
argument_list|,
literal|2
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|controlsLayout
operator|->
name|addWidget
argument_list|(
name|minimumSpinBox
argument_list|,
literal|0
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|controlsLayout
operator|->
name|addWidget
argument_list|(
name|maximumSpinBox
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|controlsLayout
operator|->
name|addWidget
argument_list|(
name|valueSpinBox
argument_list|,
literal|2
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|controlsLayout
operator|->
name|addWidget
argument_list|(
name|invertedAppearance
argument_list|,
literal|0
argument_list|,
literal|2
argument_list|)
expr_stmt|;
name|controlsLayout
operator|->
name|addWidget
argument_list|(
name|invertedKeyBindings
argument_list|,
literal|1
argument_list|,
literal|2
argument_list|)
expr_stmt|;
name|controlsLayout
operator|->
name|addWidget
argument_list|(
name|orientationCombo
argument_list|,
literal|3
argument_list|,
literal|0
argument_list|,
literal|1
argument_list|,
literal|3
argument_list|)
expr_stmt|;
name|controlsGroup
operator|->
name|setLayout
argument_list|(
name|controlsLayout
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [8]
end_comment
end_unit
