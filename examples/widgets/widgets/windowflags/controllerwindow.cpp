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
file|"controllerwindow.h"
end_include
begin_comment
comment|//! [0]
end_comment
begin_constructor
DECL|function|ControllerWindow
name|ControllerWindow
operator|::
name|ControllerWindow
parameter_list|()
block|{
name|previewWindow
operator|=
operator|new
name|PreviewWindow
argument_list|(
name|this
argument_list|)
expr_stmt|;
name|createTypeGroupBox
argument_list|()
expr_stmt|;
name|createHintsGroupBox
argument_list|()
expr_stmt|;
name|quitButton
operator|=
operator|new
name|QPushButton
argument_list|(
name|tr
argument_list|(
literal|"&Quit"
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|quitButton
argument_list|,
name|SIGNAL
argument_list|(
name|clicked
argument_list|()
argument_list|)
argument_list|,
name|qApp
argument_list|,
name|SLOT
argument_list|(
name|quit
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|QHBoxLayout
modifier|*
name|bottomLayout
init|=
operator|new
name|QHBoxLayout
decl_stmt|;
name|bottomLayout
operator|->
name|addStretch
argument_list|()
expr_stmt|;
name|bottomLayout
operator|->
name|addWidget
argument_list|(
name|quitButton
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
name|typeGroupBox
argument_list|)
expr_stmt|;
name|mainLayout
operator|->
name|addWidget
argument_list|(
name|hintsGroupBox
argument_list|)
expr_stmt|;
name|mainLayout
operator|->
name|addLayout
argument_list|(
name|bottomLayout
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
literal|"Window Flags"
argument_list|)
argument_list|)
expr_stmt|;
name|updatePreview
argument_list|()
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
DECL|function|updatePreview
name|void
name|ControllerWindow
operator|::
name|updatePreview
parameter_list|()
block|{
name|Qt
operator|::
name|WindowFlags
name|flags
init|=
literal|0
decl_stmt|;
if|if
condition|(
name|windowRadioButton
operator|->
name|isChecked
argument_list|()
condition|)
block|{
name|flags
operator|=
name|Qt
operator|::
name|Window
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|dialogRadioButton
operator|->
name|isChecked
argument_list|()
condition|)
block|{
name|flags
operator|=
name|Qt
operator|::
name|Dialog
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|sheetRadioButton
operator|->
name|isChecked
argument_list|()
condition|)
block|{
name|flags
operator|=
name|Qt
operator|::
name|Sheet
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|drawerRadioButton
operator|->
name|isChecked
argument_list|()
condition|)
block|{
name|flags
operator|=
name|Qt
operator|::
name|Drawer
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|popupRadioButton
operator|->
name|isChecked
argument_list|()
condition|)
block|{
name|flags
operator|=
name|Qt
operator|::
name|Popup
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|toolRadioButton
operator|->
name|isChecked
argument_list|()
condition|)
block|{
name|flags
operator|=
name|Qt
operator|::
name|Tool
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|toolTipRadioButton
operator|->
name|isChecked
argument_list|()
condition|)
block|{
name|flags
operator|=
name|Qt
operator|::
name|ToolTip
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|splashScreenRadioButton
operator|->
name|isChecked
argument_list|()
condition|)
block|{
name|flags
operator|=
name|Qt
operator|::
name|SplashScreen
expr_stmt|;
comment|//! [1] //! [2]
block|}
comment|//! [2] //! [3]
if|if
condition|(
name|msWindowsFixedSizeDialogCheckBox
operator|->
name|isChecked
argument_list|()
condition|)
name|flags
operator||=
name|Qt
operator|::
name|MSWindowsFixedSizeDialogHint
expr_stmt|;
if|if
condition|(
name|x11BypassWindowManagerCheckBox
operator|->
name|isChecked
argument_list|()
condition|)
name|flags
operator||=
name|Qt
operator|::
name|X11BypassWindowManagerHint
expr_stmt|;
if|if
condition|(
name|framelessWindowCheckBox
operator|->
name|isChecked
argument_list|()
condition|)
name|flags
operator||=
name|Qt
operator|::
name|FramelessWindowHint
expr_stmt|;
if|if
condition|(
name|windowNoShadowCheckBox
operator|->
name|isChecked
argument_list|()
condition|)
name|flags
operator||=
name|Qt
operator|::
name|NoDropShadowWindowHint
expr_stmt|;
if|if
condition|(
name|windowTitleCheckBox
operator|->
name|isChecked
argument_list|()
condition|)
name|flags
operator||=
name|Qt
operator|::
name|WindowTitleHint
expr_stmt|;
if|if
condition|(
name|windowSystemMenuCheckBox
operator|->
name|isChecked
argument_list|()
condition|)
name|flags
operator||=
name|Qt
operator|::
name|WindowSystemMenuHint
expr_stmt|;
if|if
condition|(
name|windowMinimizeButtonCheckBox
operator|->
name|isChecked
argument_list|()
condition|)
name|flags
operator||=
name|Qt
operator|::
name|WindowMinimizeButtonHint
expr_stmt|;
if|if
condition|(
name|windowMaximizeButtonCheckBox
operator|->
name|isChecked
argument_list|()
condition|)
name|flags
operator||=
name|Qt
operator|::
name|WindowMaximizeButtonHint
expr_stmt|;
if|if
condition|(
name|windowCloseButtonCheckBox
operator|->
name|isChecked
argument_list|()
condition|)
name|flags
operator||=
name|Qt
operator|::
name|WindowCloseButtonHint
expr_stmt|;
if|if
condition|(
name|windowContextHelpButtonCheckBox
operator|->
name|isChecked
argument_list|()
condition|)
name|flags
operator||=
name|Qt
operator|::
name|WindowContextHelpButtonHint
expr_stmt|;
if|if
condition|(
name|windowShadeButtonCheckBox
operator|->
name|isChecked
argument_list|()
condition|)
name|flags
operator||=
name|Qt
operator|::
name|WindowShadeButtonHint
expr_stmt|;
if|if
condition|(
name|windowStaysOnTopCheckBox
operator|->
name|isChecked
argument_list|()
condition|)
name|flags
operator||=
name|Qt
operator|::
name|WindowStaysOnTopHint
expr_stmt|;
if|if
condition|(
name|windowStaysOnBottomCheckBox
operator|->
name|isChecked
argument_list|()
condition|)
name|flags
operator||=
name|Qt
operator|::
name|WindowStaysOnBottomHint
expr_stmt|;
if|if
condition|(
name|customizeWindowHintCheckBox
operator|->
name|isChecked
argument_list|()
condition|)
name|flags
operator||=
name|Qt
operator|::
name|CustomizeWindowHint
expr_stmt|;
name|previewWindow
operator|->
name|setWindowFlags
argument_list|(
name|flags
argument_list|)
expr_stmt|;
comment|//! [3] //! [4]
name|QPoint
name|pos
init|=
name|previewWindow
operator|->
name|pos
argument_list|()
decl_stmt|;
if|if
condition|(
name|pos
operator|.
name|x
argument_list|()
operator|<
literal|0
condition|)
name|pos
operator|.
name|setX
argument_list|(
literal|0
argument_list|)
expr_stmt|;
if|if
condition|(
name|pos
operator|.
name|y
argument_list|()
operator|<
literal|0
condition|)
name|pos
operator|.
name|setY
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|previewWindow
operator|->
name|move
argument_list|(
name|pos
argument_list|)
expr_stmt|;
name|previewWindow
operator|->
name|show
argument_list|()
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [4]
end_comment
begin_comment
comment|//! [5]
end_comment
begin_function
DECL|function|createTypeGroupBox
name|void
name|ControllerWindow
operator|::
name|createTypeGroupBox
parameter_list|()
block|{
name|typeGroupBox
operator|=
operator|new
name|QGroupBox
argument_list|(
name|tr
argument_list|(
literal|"Type"
argument_list|)
argument_list|)
expr_stmt|;
name|windowRadioButton
operator|=
name|createRadioButton
argument_list|(
name|tr
argument_list|(
literal|"Window"
argument_list|)
argument_list|)
expr_stmt|;
name|dialogRadioButton
operator|=
name|createRadioButton
argument_list|(
name|tr
argument_list|(
literal|"Dialog"
argument_list|)
argument_list|)
expr_stmt|;
name|sheetRadioButton
operator|=
name|createRadioButton
argument_list|(
name|tr
argument_list|(
literal|"Sheet"
argument_list|)
argument_list|)
expr_stmt|;
name|drawerRadioButton
operator|=
name|createRadioButton
argument_list|(
name|tr
argument_list|(
literal|"Drawer"
argument_list|)
argument_list|)
expr_stmt|;
name|popupRadioButton
operator|=
name|createRadioButton
argument_list|(
name|tr
argument_list|(
literal|"Popup"
argument_list|)
argument_list|)
expr_stmt|;
name|toolRadioButton
operator|=
name|createRadioButton
argument_list|(
name|tr
argument_list|(
literal|"Tool"
argument_list|)
argument_list|)
expr_stmt|;
name|toolTipRadioButton
operator|=
name|createRadioButton
argument_list|(
name|tr
argument_list|(
literal|"Tooltip"
argument_list|)
argument_list|)
expr_stmt|;
name|splashScreenRadioButton
operator|=
name|createRadioButton
argument_list|(
name|tr
argument_list|(
literal|"Splash screen"
argument_list|)
argument_list|)
expr_stmt|;
name|windowRadioButton
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
name|addWidget
argument_list|(
name|windowRadioButton
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
name|dialogRadioButton
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
name|sheetRadioButton
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
name|drawerRadioButton
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
name|popupRadioButton
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
name|toolRadioButton
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
name|toolTipRadioButton
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
name|splashScreenRadioButton
argument_list|,
literal|3
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|typeGroupBox
operator|->
name|setLayout
argument_list|(
name|layout
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [5]
end_comment
begin_comment
comment|//! [6]
end_comment
begin_function
DECL|function|createHintsGroupBox
name|void
name|ControllerWindow
operator|::
name|createHintsGroupBox
parameter_list|()
block|{
name|hintsGroupBox
operator|=
operator|new
name|QGroupBox
argument_list|(
name|tr
argument_list|(
literal|"Hints"
argument_list|)
argument_list|)
expr_stmt|;
name|msWindowsFixedSizeDialogCheckBox
operator|=
name|createCheckBox
argument_list|(
name|tr
argument_list|(
literal|"MS Windows fixed size dialog"
argument_list|)
argument_list|)
expr_stmt|;
name|x11BypassWindowManagerCheckBox
operator|=
name|createCheckBox
argument_list|(
name|tr
argument_list|(
literal|"X11 bypass window manager"
argument_list|)
argument_list|)
expr_stmt|;
name|framelessWindowCheckBox
operator|=
name|createCheckBox
argument_list|(
name|tr
argument_list|(
literal|"Frameless window"
argument_list|)
argument_list|)
expr_stmt|;
name|windowNoShadowCheckBox
operator|=
name|createCheckBox
argument_list|(
name|tr
argument_list|(
literal|"No drop shadow"
argument_list|)
argument_list|)
expr_stmt|;
name|windowTitleCheckBox
operator|=
name|createCheckBox
argument_list|(
name|tr
argument_list|(
literal|"Window title"
argument_list|)
argument_list|)
expr_stmt|;
name|windowSystemMenuCheckBox
operator|=
name|createCheckBox
argument_list|(
name|tr
argument_list|(
literal|"Window system menu"
argument_list|)
argument_list|)
expr_stmt|;
name|windowMinimizeButtonCheckBox
operator|=
name|createCheckBox
argument_list|(
name|tr
argument_list|(
literal|"Window minimize button"
argument_list|)
argument_list|)
expr_stmt|;
name|windowMaximizeButtonCheckBox
operator|=
name|createCheckBox
argument_list|(
name|tr
argument_list|(
literal|"Window maximize button"
argument_list|)
argument_list|)
expr_stmt|;
name|windowCloseButtonCheckBox
operator|=
name|createCheckBox
argument_list|(
name|tr
argument_list|(
literal|"Window close button"
argument_list|)
argument_list|)
expr_stmt|;
name|windowContextHelpButtonCheckBox
operator|=
name|createCheckBox
argument_list|(
name|tr
argument_list|(
literal|"Window context help button"
argument_list|)
argument_list|)
expr_stmt|;
name|windowShadeButtonCheckBox
operator|=
name|createCheckBox
argument_list|(
name|tr
argument_list|(
literal|"Window shade button"
argument_list|)
argument_list|)
expr_stmt|;
name|windowStaysOnTopCheckBox
operator|=
name|createCheckBox
argument_list|(
name|tr
argument_list|(
literal|"Window stays on top"
argument_list|)
argument_list|)
expr_stmt|;
name|windowStaysOnBottomCheckBox
operator|=
name|createCheckBox
argument_list|(
name|tr
argument_list|(
literal|"Window stays on bottom"
argument_list|)
argument_list|)
expr_stmt|;
name|customizeWindowHintCheckBox
operator|=
name|createCheckBox
argument_list|(
name|tr
argument_list|(
literal|"Customize window"
argument_list|)
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
name|msWindowsFixedSizeDialogCheckBox
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
name|x11BypassWindowManagerCheckBox
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
name|framelessWindowCheckBox
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
name|windowNoShadowCheckBox
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
name|windowTitleCheckBox
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
name|windowSystemMenuCheckBox
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
name|customizeWindowHintCheckBox
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
name|windowMinimizeButtonCheckBox
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
name|windowMaximizeButtonCheckBox
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
name|windowCloseButtonCheckBox
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
name|windowContextHelpButtonCheckBox
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
name|windowShadeButtonCheckBox
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
name|windowStaysOnTopCheckBox
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
name|windowStaysOnBottomCheckBox
argument_list|,
literal|6
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|hintsGroupBox
operator|->
name|setLayout
argument_list|(
name|layout
argument_list|)
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
DECL|function|createCheckBox
name|QCheckBox
modifier|*
name|ControllerWindow
operator|::
name|createCheckBox
parameter_list|(
specifier|const
name|QString
modifier|&
name|text
parameter_list|)
block|{
name|QCheckBox
modifier|*
name|checkBox
init|=
operator|new
name|QCheckBox
argument_list|(
name|text
argument_list|)
decl_stmt|;
name|connect
argument_list|(
name|checkBox
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
name|updatePreview
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|checkBox
return|;
block|}
end_function
begin_comment
comment|//! [7]
end_comment
begin_comment
comment|//! [8]
end_comment
begin_function
DECL|function|createRadioButton
name|QRadioButton
modifier|*
name|ControllerWindow
operator|::
name|createRadioButton
parameter_list|(
specifier|const
name|QString
modifier|&
name|text
parameter_list|)
block|{
name|QRadioButton
modifier|*
name|button
init|=
operator|new
name|QRadioButton
argument_list|(
name|text
argument_list|)
decl_stmt|;
name|connect
argument_list|(
name|button
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
name|updatePreview
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|button
return|;
block|}
end_function
begin_comment
comment|//! [8]
end_comment
end_unit
