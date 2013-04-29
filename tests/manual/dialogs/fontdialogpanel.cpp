begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"fontdialogpanel.h"
end_include
begin_include
include|#
directive|include
file|<QGroupBox>
end_include
begin_include
include|#
directive|include
file|<QCheckBox>
end_include
begin_include
include|#
directive|include
file|<QPushButton>
end_include
begin_include
include|#
directive|include
file|<QVBoxLayout>
end_include
begin_include
include|#
directive|include
file|<QHBoxLayout>
end_include
begin_include
include|#
directive|include
file|<QMessageBox>
end_include
begin_include
include|#
directive|include
file|<QFontComboBox>
end_include
begin_include
include|#
directive|include
file|<QDoubleSpinBox>
end_include
begin_include
include|#
directive|include
file|<QTimer>
end_include
begin_include
include|#
directive|include
file|<QDebug>
end_include
begin_function
DECL|function|addButton
specifier|static
specifier|inline
name|QPushButton
modifier|*
name|addButton
parameter_list|(
specifier|const
name|QString
modifier|&
name|description
parameter_list|,
name|QVBoxLayout
modifier|*
name|layout
parameter_list|,
name|QObject
modifier|*
name|receiver
parameter_list|,
specifier|const
name|char
modifier|*
name|slotFunc
parameter_list|)
block|{
name|QPushButton
modifier|*
name|button
init|=
operator|new
name|QPushButton
argument_list|(
name|description
argument_list|)
decl_stmt|;
name|QObject
operator|::
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
name|receiver
argument_list|,
name|slotFunc
argument_list|)
expr_stmt|;
name|layout
operator|->
name|addWidget
argument_list|(
name|button
argument_list|)
expr_stmt|;
return|return
name|button
return|;
block|}
end_function
begin_constructor
DECL|function|FontDialogPanel
name|FontDialogPanel
operator|::
name|FontDialogPanel
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
member_init_list|,
name|m_fontFamilyBox
argument_list|(
operator|new
name|QFontComboBox
argument_list|)
member_init_list|,
name|m_fontSizeBox
argument_list|(
operator|new
name|QDoubleSpinBox
argument_list|)
member_init_list|,
name|m_noButtons
argument_list|(
operator|new
name|QCheckBox
argument_list|(
name|tr
argument_list|(
literal|"Don't display OK/Cancel buttons"
argument_list|)
argument_list|)
argument_list|)
member_init_list|,
name|m_dontUseNativeDialog
argument_list|(
operator|new
name|QCheckBox
argument_list|(
name|tr
argument_list|(
literal|"Don't use native dialog"
argument_list|)
argument_list|)
argument_list|)
member_init_list|,
name|m_scalableFilter
argument_list|(
operator|new
name|QCheckBox
argument_list|(
name|tr
argument_list|(
literal|"Filter scalable fonts"
argument_list|)
argument_list|)
argument_list|)
member_init_list|,
name|m_nonScalableFilter
argument_list|(
operator|new
name|QCheckBox
argument_list|(
name|tr
argument_list|(
literal|"Filter non scalable fonts"
argument_list|)
argument_list|)
argument_list|)
member_init_list|,
name|m_monospacedFilter
argument_list|(
operator|new
name|QCheckBox
argument_list|(
name|tr
argument_list|(
literal|"Filter monospaced fonts"
argument_list|)
argument_list|)
argument_list|)
member_init_list|,
name|m_proportionalFilter
argument_list|(
operator|new
name|QCheckBox
argument_list|(
name|tr
argument_list|(
literal|"Filter proportional fonts"
argument_list|)
argument_list|)
argument_list|)
block|{
comment|// Options
name|QGroupBox
modifier|*
name|optionsGroupBox
init|=
operator|new
name|QGroupBox
argument_list|(
name|tr
argument_list|(
literal|"Options"
argument_list|)
argument_list|,
name|this
argument_list|)
decl_stmt|;
name|QVBoxLayout
modifier|*
name|optionsLayout
init|=
operator|new
name|QVBoxLayout
argument_list|(
name|optionsGroupBox
argument_list|)
decl_stmt|;
name|optionsLayout
operator|->
name|addWidget
argument_list|(
name|m_noButtons
argument_list|)
expr_stmt|;
name|optionsLayout
operator|->
name|addWidget
argument_list|(
name|m_dontUseNativeDialog
argument_list|)
expr_stmt|;
name|optionsLayout
operator|->
name|addWidget
argument_list|(
name|m_scalableFilter
argument_list|)
expr_stmt|;
name|optionsLayout
operator|->
name|addWidget
argument_list|(
name|m_nonScalableFilter
argument_list|)
expr_stmt|;
name|optionsLayout
operator|->
name|addWidget
argument_list|(
name|m_monospacedFilter
argument_list|)
expr_stmt|;
name|optionsLayout
operator|->
name|addWidget
argument_list|(
name|m_proportionalFilter
argument_list|)
expr_stmt|;
comment|// Font
name|QGroupBox
modifier|*
name|fontGroupBox
init|=
operator|new
name|QGroupBox
argument_list|(
name|tr
argument_list|(
literal|"Font"
argument_list|)
argument_list|,
name|this
argument_list|)
decl_stmt|;
name|QHBoxLayout
modifier|*
name|fontLayout
init|=
operator|new
name|QHBoxLayout
argument_list|(
name|fontGroupBox
argument_list|)
decl_stmt|;
name|fontLayout
operator|->
name|addWidget
argument_list|(
name|m_fontFamilyBox
argument_list|)
expr_stmt|;
name|fontLayout
operator|->
name|addWidget
argument_list|(
name|m_fontSizeBox
argument_list|)
expr_stmt|;
name|m_fontSizeBox
operator|->
name|setValue
argument_list|(
name|QFont
argument_list|()
operator|.
name|pointSizeF
argument_list|()
argument_list|)
expr_stmt|;
comment|// Buttons
name|QGroupBox
modifier|*
name|buttonsGroupBox
init|=
operator|new
name|QGroupBox
argument_list|(
name|tr
argument_list|(
literal|"Show"
argument_list|)
argument_list|)
decl_stmt|;
name|QVBoxLayout
modifier|*
name|buttonsLayout
init|=
operator|new
name|QVBoxLayout
argument_list|(
name|buttonsGroupBox
argument_list|)
decl_stmt|;
name|addButton
argument_list|(
name|tr
argument_list|(
literal|"Exec modal"
argument_list|)
argument_list|,
name|buttonsLayout
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|execModal
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|addButton
argument_list|(
name|tr
argument_list|(
literal|"Show modal"
argument_list|)
argument_list|,
name|buttonsLayout
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|showModal
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|m_deleteModalDialogButton
operator|=
name|addButton
argument_list|(
name|tr
argument_list|(
literal|"Delete modal"
argument_list|)
argument_list|,
name|buttonsLayout
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|deleteModalDialog
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|addButton
argument_list|(
name|tr
argument_list|(
literal|"Show non-modal"
argument_list|)
argument_list|,
name|buttonsLayout
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|showNonModal
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|m_deleteNonModalDialogButton
operator|=
name|addButton
argument_list|(
name|tr
argument_list|(
literal|"Delete non-modal"
argument_list|)
argument_list|,
name|buttonsLayout
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|deleteNonModalDialog
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|addButton
argument_list|(
name|tr
argument_list|(
literal|"Restore defaults"
argument_list|)
argument_list|,
name|buttonsLayout
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|restoreDefaults
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|buttonsLayout
operator|->
name|addStretch
argument_list|()
expr_stmt|;
comment|// Main layout
name|QHBoxLayout
modifier|*
name|mainLayout
init|=
operator|new
name|QHBoxLayout
argument_list|(
name|this
argument_list|)
decl_stmt|;
name|QVBoxLayout
modifier|*
name|leftLayout
init|=
operator|new
name|QVBoxLayout
decl_stmt|;
name|leftLayout
operator|->
name|addWidget
argument_list|(
name|optionsGroupBox
argument_list|)
expr_stmt|;
name|leftLayout
operator|->
name|addWidget
argument_list|(
name|fontGroupBox
argument_list|)
expr_stmt|;
name|leftLayout
operator|->
name|addStretch
argument_list|()
expr_stmt|;
name|mainLayout
operator|->
name|addLayout
argument_list|(
name|leftLayout
argument_list|)
expr_stmt|;
name|mainLayout
operator|->
name|addWidget
argument_list|(
name|buttonsGroupBox
argument_list|)
expr_stmt|;
name|enableDeleteModalDialogButton
argument_list|()
expr_stmt|;
name|enableDeleteNonModalDialogButton
argument_list|()
expr_stmt|;
name|restoreDefaults
argument_list|()
expr_stmt|;
block|}
end_constructor
begin_function
DECL|function|execModal
name|void
name|FontDialogPanel
operator|::
name|execModal
parameter_list|()
block|{
name|QFontDialog
name|dialog
argument_list|(
name|this
argument_list|)
decl_stmt|;
name|applySettings
argument_list|(
operator|&
name|dialog
argument_list|)
expr_stmt|;
name|connect
argument_list|(
operator|&
name|dialog
argument_list|,
name|SIGNAL
argument_list|(
name|accepted
argument_list|()
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|accepted
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|dialog
operator|.
name|setWindowTitle
argument_list|(
name|tr
argument_list|(
literal|"Modal Font Dialog Qt %1"
argument_list|)
operator|.
name|arg
argument_list|(
name|QLatin1String
argument_list|(
name|QT_VERSION_STR
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|dialog
operator|.
name|exec
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|showModal
name|void
name|FontDialogPanel
operator|::
name|showModal
parameter_list|()
block|{
if|if
condition|(
name|m_modalDialog
operator|.
name|isNull
argument_list|()
condition|)
block|{
specifier|static
name|int
name|n
init|=
literal|0
decl_stmt|;
name|m_modalDialog
operator|=
operator|new
name|QFontDialog
argument_list|(
name|this
argument_list|)
expr_stmt|;
name|m_modalDialog
operator|->
name|setModal
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|m_modalDialog
operator|.
name|data
argument_list|()
argument_list|,
name|SIGNAL
argument_list|(
name|accepted
argument_list|()
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|accepted
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|m_modalDialog
operator|->
name|setWindowTitle
argument_list|(
name|tr
argument_list|(
literal|"Modal Font Dialog #%1 Qt %2"
argument_list|)
operator|.
name|arg
argument_list|(
operator|++
name|n
argument_list|)
operator|.
name|arg
argument_list|(
name|QLatin1String
argument_list|(
name|QT_VERSION_STR
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|enableDeleteModalDialogButton
argument_list|()
expr_stmt|;
block|}
name|applySettings
argument_list|(
name|m_modalDialog
argument_list|)
expr_stmt|;
name|m_modalDialog
operator|->
name|show
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|showNonModal
name|void
name|FontDialogPanel
operator|::
name|showNonModal
parameter_list|()
block|{
if|if
condition|(
name|m_nonModalDialog
operator|.
name|isNull
argument_list|()
condition|)
block|{
specifier|static
name|int
name|n
init|=
literal|0
decl_stmt|;
name|m_nonModalDialog
operator|=
operator|new
name|QFontDialog
argument_list|(
name|this
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|m_nonModalDialog
operator|.
name|data
argument_list|()
argument_list|,
name|SIGNAL
argument_list|(
name|accepted
argument_list|()
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|accepted
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|m_nonModalDialog
operator|->
name|setWindowTitle
argument_list|(
name|tr
argument_list|(
literal|"Non-Modal Font Dialog #%1 Qt %2"
argument_list|)
operator|.
name|arg
argument_list|(
operator|++
name|n
argument_list|)
operator|.
name|arg
argument_list|(
name|QLatin1String
argument_list|(
name|QT_VERSION_STR
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|enableDeleteNonModalDialogButton
argument_list|()
expr_stmt|;
block|}
name|applySettings
argument_list|(
name|m_nonModalDialog
argument_list|)
expr_stmt|;
name|m_nonModalDialog
operator|->
name|show
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|deleteNonModalDialog
name|void
name|FontDialogPanel
operator|::
name|deleteNonModalDialog
parameter_list|()
block|{
if|if
condition|(
operator|!
name|m_nonModalDialog
operator|.
name|isNull
argument_list|()
condition|)
operator|delete
name|m_nonModalDialog
expr_stmt|;
name|enableDeleteNonModalDialogButton
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|deleteModalDialog
name|void
name|FontDialogPanel
operator|::
name|deleteModalDialog
parameter_list|()
block|{
if|if
condition|(
operator|!
name|m_modalDialog
operator|.
name|isNull
argument_list|()
condition|)
operator|delete
name|m_modalDialog
expr_stmt|;
name|enableDeleteModalDialogButton
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|accepted
name|void
name|FontDialogPanel
operator|::
name|accepted
parameter_list|()
block|{
specifier|const
name|QFontDialog
modifier|*
name|d
init|=
name|qobject_cast
argument_list|<
specifier|const
name|QFontDialog
operator|*
argument_list|>
argument_list|(
name|sender
argument_list|()
argument_list|)
decl_stmt|;
name|Q_ASSERT
argument_list|(
name|d
argument_list|)
expr_stmt|;
name|m_result
operator|.
name|clear
argument_list|()
expr_stmt|;
name|QDebug
argument_list|(
operator|&
name|m_result
argument_list|)
operator|.
name|nospace
argument_list|()
operator|<<
literal|"Current font: "
operator|<<
name|d
operator|->
name|currentFont
argument_list|()
operator|<<
literal|"\nSelected font: "
operator|<<
name|d
operator|->
name|selectedFont
argument_list|()
expr_stmt|;
name|QTimer
operator|::
name|singleShot
argument_list|(
literal|0
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|showAcceptedResult
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
comment|// Avoid problems with the closing (modal) dialog as parent.
block|}
end_function
begin_function
DECL|function|showAcceptedResult
name|void
name|FontDialogPanel
operator|::
name|showAcceptedResult
parameter_list|()
block|{
name|QMessageBox
operator|::
name|information
argument_list|(
name|this
argument_list|,
name|tr
argument_list|(
literal|"Color Dialog Accepted"
argument_list|)
argument_list|,
name|m_result
argument_list|,
name|QMessageBox
operator|::
name|Ok
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|restoreDefaults
name|void
name|FontDialogPanel
operator|::
name|restoreDefaults
parameter_list|()
block|{
name|QFontDialog
name|d
decl_stmt|;
name|m_noButtons
operator|->
name|setChecked
argument_list|(
name|d
operator|.
name|testOption
argument_list|(
name|QFontDialog
operator|::
name|NoButtons
argument_list|)
argument_list|)
expr_stmt|;
name|m_dontUseNativeDialog
operator|->
name|setChecked
argument_list|(
name|d
operator|.
name|testOption
argument_list|(
name|QFontDialog
operator|::
name|DontUseNativeDialog
argument_list|)
argument_list|)
expr_stmt|;
name|m_fontFamilyBox
operator|->
name|setCurrentFont
argument_list|(
name|QFont
argument_list|()
argument_list|)
expr_stmt|;
name|m_fontSizeBox
operator|->
name|setValue
argument_list|(
name|QFont
argument_list|()
operator|.
name|pointSizeF
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|enableDeleteNonModalDialogButton
name|void
name|FontDialogPanel
operator|::
name|enableDeleteNonModalDialogButton
parameter_list|()
block|{
name|m_deleteNonModalDialogButton
operator|->
name|setEnabled
argument_list|(
operator|!
name|m_nonModalDialog
operator|.
name|isNull
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|enableDeleteModalDialogButton
name|void
name|FontDialogPanel
operator|::
name|enableDeleteModalDialogButton
parameter_list|()
block|{
name|m_deleteModalDialogButton
operator|->
name|setEnabled
argument_list|(
operator|!
name|m_modalDialog
operator|.
name|isNull
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|applySettings
name|void
name|FontDialogPanel
operator|::
name|applySettings
parameter_list|(
name|QFontDialog
modifier|*
name|d
parameter_list|)
specifier|const
block|{
name|d
operator|->
name|setOption
argument_list|(
name|QFontDialog
operator|::
name|NoButtons
argument_list|,
name|m_noButtons
operator|->
name|isChecked
argument_list|()
argument_list|)
expr_stmt|;
name|d
operator|->
name|setOption
argument_list|(
name|QFontDialog
operator|::
name|DontUseNativeDialog
argument_list|,
name|m_dontUseNativeDialog
operator|->
name|isChecked
argument_list|()
argument_list|)
expr_stmt|;
name|d
operator|->
name|setOption
argument_list|(
name|QFontDialog
operator|::
name|ScalableFonts
argument_list|,
name|m_scalableFilter
operator|->
name|isChecked
argument_list|()
argument_list|)
expr_stmt|;
name|d
operator|->
name|setOption
argument_list|(
name|QFontDialog
operator|::
name|NonScalableFonts
argument_list|,
name|m_nonScalableFilter
operator|->
name|isChecked
argument_list|()
argument_list|)
expr_stmt|;
name|d
operator|->
name|setOption
argument_list|(
name|QFontDialog
operator|::
name|MonospacedFonts
argument_list|,
name|m_monospacedFilter
operator|->
name|isChecked
argument_list|()
argument_list|)
expr_stmt|;
name|d
operator|->
name|setOption
argument_list|(
name|QFontDialog
operator|::
name|ProportionalFonts
argument_list|,
name|m_proportionalFilter
operator|->
name|isChecked
argument_list|()
argument_list|)
expr_stmt|;
name|QFont
name|font
init|=
name|m_fontFamilyBox
operator|->
name|currentFont
argument_list|()
decl_stmt|;
name|font
operator|.
name|setPointSizeF
argument_list|(
name|m_fontSizeBox
operator|->
name|value
argument_list|()
argument_list|)
expr_stmt|;
name|d
operator|->
name|setCurrentFont
argument_list|(
name|font
argument_list|)
expr_stmt|;
block|}
end_function
end_unit
