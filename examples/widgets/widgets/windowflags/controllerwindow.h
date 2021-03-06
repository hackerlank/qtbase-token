begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** BSD License Usage ** Alternatively, you may use this file under the terms of the BSD license ** as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of The Qt Company Ltd nor the names of its **     contributors may be used to endorse or promote products derived **     from this software without specific prior written permission. ** ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|CONTROLLERWINDOW_H
end_ifndef
begin_define
DECL|macro|CONTROLLERWINDOW_H
define|#
directive|define
name|CONTROLLERWINDOW_H
end_define
begin_include
include|#
directive|include
file|<QWidget>
end_include
begin_include
include|#
directive|include
file|"previewwindow.h"
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QCheckBox
name|class
name|QCheckBox
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QGroupBox
name|class
name|QGroupBox
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QLabel
name|class
name|QLabel
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QPushButton
name|class
name|QPushButton
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QRadioButton
name|class
name|QRadioButton
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QT_END_NAMESPACE
comment|//! [0]
name|class
name|ControllerWindow
range|:
name|public
name|QWidget
block|{
name|Q_OBJECT
name|public
operator|:
name|ControllerWindow
argument_list|()
block|;
name|private
name|slots
operator|:
name|void
name|updatePreview
argument_list|()
block|;
name|private
operator|:
name|void
name|createTypeGroupBox
argument_list|()
block|;
name|void
name|createHintsGroupBox
argument_list|()
block|;
name|QCheckBox
operator|*
name|createCheckBox
argument_list|(
specifier|const
name|QString
operator|&
name|text
argument_list|)
block|;
name|QRadioButton
operator|*
name|createRadioButton
argument_list|(
specifier|const
name|QString
operator|&
name|text
argument_list|)
block|;
name|PreviewWindow
operator|*
name|previewWindow
block|;
name|QGroupBox
operator|*
name|typeGroupBox
block|;
name|QGroupBox
operator|*
name|hintsGroupBox
block|;
name|QPushButton
operator|*
name|quitButton
block|;
name|QRadioButton
operator|*
name|windowRadioButton
block|;
name|QRadioButton
operator|*
name|dialogRadioButton
block|;
name|QRadioButton
operator|*
name|sheetRadioButton
block|;
name|QRadioButton
operator|*
name|drawerRadioButton
block|;
name|QRadioButton
operator|*
name|popupRadioButton
block|;
name|QRadioButton
operator|*
name|toolRadioButton
block|;
name|QRadioButton
operator|*
name|toolTipRadioButton
block|;
name|QRadioButton
operator|*
name|splashScreenRadioButton
block|;
name|QCheckBox
operator|*
name|msWindowsFixedSizeDialogCheckBox
block|;
name|QCheckBox
operator|*
name|x11BypassWindowManagerCheckBox
block|;
name|QCheckBox
operator|*
name|framelessWindowCheckBox
block|;
name|QCheckBox
operator|*
name|windowNoShadowCheckBox
block|;
name|QCheckBox
operator|*
name|windowTitleCheckBox
block|;
name|QCheckBox
operator|*
name|windowSystemMenuCheckBox
block|;
name|QCheckBox
operator|*
name|windowMinimizeButtonCheckBox
block|;
name|QCheckBox
operator|*
name|windowMaximizeButtonCheckBox
block|;
name|QCheckBox
operator|*
name|windowCloseButtonCheckBox
block|;
name|QCheckBox
operator|*
name|windowContextHelpButtonCheckBox
block|;
name|QCheckBox
operator|*
name|windowShadeButtonCheckBox
block|;
name|QCheckBox
operator|*
name|windowStaysOnTopCheckBox
block|;
name|QCheckBox
operator|*
name|windowStaysOnBottomCheckBox
block|;
name|QCheckBox
operator|*
name|customizeWindowHintCheckBox
block|; }
decl_stmt|;
end_decl_stmt
begin_comment
comment|//! [0]
end_comment
begin_endif
endif|#
directive|endif
end_endif
end_unit
