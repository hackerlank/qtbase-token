begin_unit
begin_comment
comment|/* ********************************************************************* ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the autotests of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ********************************************************************* */
end_comment
begin_comment
comment|/******************************************************************************** ** Form generated from reading UI file 'previewwidget.ui' ** ** Created by: Qt User Interface Compiler version 5.0.0 ** ** WARNING! All changes made in this file will be lost when recompiling UI file! ********************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|PREVIEWWIDGET_H
end_ifndef
begin_define
DECL|macro|PREVIEWWIDGET_H
define|#
directive|define
name|PREVIEWWIDGET_H
end_define
begin_include
include|#
directive|include
file|<QtCore/QVariant>
end_include
begin_include
include|#
directive|include
file|<QtWidgets/QAction>
end_include
begin_include
include|#
directive|include
file|<QtWidgets/QApplication>
end_include
begin_include
include|#
directive|include
file|<QtWidgets/QButtonGroup>
end_include
begin_include
include|#
directive|include
file|<QtWidgets/QCheckBox>
end_include
begin_include
include|#
directive|include
file|<QtWidgets/QComboBox>
end_include
begin_include
include|#
directive|include
file|<QtWidgets/QGridLayout>
end_include
begin_include
include|#
directive|include
file|<QtWidgets/QGroupBox>
end_include
begin_include
include|#
directive|include
file|<QtWidgets/QHBoxLayout>
end_include
begin_include
include|#
directive|include
file|<QtWidgets/QHeaderView>
end_include
begin_include
include|#
directive|include
file|<QtWidgets/QLineEdit>
end_include
begin_include
include|#
directive|include
file|<QtWidgets/QListWidget>
end_include
begin_include
include|#
directive|include
file|<QtWidgets/QProgressBar>
end_include
begin_include
include|#
directive|include
file|<QtWidgets/QPushButton>
end_include
begin_include
include|#
directive|include
file|<QtWidgets/QRadioButton>
end_include
begin_include
include|#
directive|include
file|<QtWidgets/QScrollBar>
end_include
begin_include
include|#
directive|include
file|<QtWidgets/QSlider>
end_include
begin_include
include|#
directive|include
file|<QtWidgets/QSpacerItem>
end_include
begin_include
include|#
directive|include
file|<QtWidgets/QSpinBox>
end_include
begin_include
include|#
directive|include
file|<QtWidgets/QVBoxLayout>
end_include
begin_include
include|#
directive|include
file|<QtWidgets/QWidget>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
name|namespace
name|qdesigner_internal
block|{
name|class
name|Ui_PreviewWidget
block|{
name|public
label|:
name|QGridLayout
modifier|*
name|gridLayout
decl_stmt|;
name|QVBoxLayout
modifier|*
name|vboxLayout
decl_stmt|;
name|QLineEdit
modifier|*
name|LineEdit1
decl_stmt|;
name|QComboBox
modifier|*
name|ComboBox1
decl_stmt|;
name|QHBoxLayout
modifier|*
name|hboxLayout
decl_stmt|;
name|QSpinBox
modifier|*
name|SpinBox1
decl_stmt|;
name|QPushButton
modifier|*
name|PushButton1
decl_stmt|;
name|QScrollBar
modifier|*
name|ScrollBar1
decl_stmt|;
name|QSlider
modifier|*
name|Slider1
decl_stmt|;
name|QListWidget
modifier|*
name|listWidget
decl_stmt|;
name|QSpacerItem
modifier|*
name|spacerItem
decl_stmt|;
name|QProgressBar
modifier|*
name|ProgressBar1
decl_stmt|;
name|QGroupBox
modifier|*
name|ButtonGroup2
decl_stmt|;
name|QVBoxLayout
modifier|*
name|vboxLayout1
decl_stmt|;
name|QCheckBox
modifier|*
name|CheckBox1
decl_stmt|;
name|QCheckBox
modifier|*
name|CheckBox2
decl_stmt|;
name|QGroupBox
modifier|*
name|ButtonGroup1
decl_stmt|;
name|QVBoxLayout
modifier|*
name|vboxLayout2
decl_stmt|;
name|QRadioButton
modifier|*
name|RadioButton1
decl_stmt|;
name|QRadioButton
modifier|*
name|RadioButton2
decl_stmt|;
name|QRadioButton
modifier|*
name|RadioButton3
decl_stmt|;
name|void
name|setupUi
parameter_list|(
name|QWidget
modifier|*
name|qdesigner_internal__PreviewWidget
parameter_list|)
block|{
if|if
condition|(
name|qdesigner_internal__PreviewWidget
operator|->
name|objectName
argument_list|()
operator|.
name|isEmpty
argument_list|()
condition|)
name|qdesigner_internal__PreviewWidget
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"qdesigner_internal__PreviewWidget"
argument_list|)
argument_list|)
expr_stmt|;
name|qdesigner_internal__PreviewWidget
operator|->
name|resize
argument_list|(
literal|471
argument_list|,
literal|251
argument_list|)
expr_stmt|;
name|QSizePolicy
name|sizePolicy
argument_list|(
name|static_cast
operator|<
name|QSizePolicy
operator|::
name|Policy
operator|>
operator|(
literal|1
operator|)
argument_list|,
name|static_cast
operator|<
name|QSizePolicy
operator|::
name|Policy
operator|>
operator|(
literal|1
operator|)
argument_list|)
decl_stmt|;
name|sizePolicy
operator|.
name|setHorizontalStretch
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|sizePolicy
operator|.
name|setVerticalStretch
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|sizePolicy
operator|.
name|setHeightForWidth
argument_list|(
name|qdesigner_internal__PreviewWidget
operator|->
name|sizePolicy
argument_list|()
operator|.
name|hasHeightForWidth
argument_list|()
argument_list|)
expr_stmt|;
name|qdesigner_internal__PreviewWidget
operator|->
name|setSizePolicy
argument_list|(
name|sizePolicy
argument_list|)
expr_stmt|;
name|gridLayout
operator|=
name|new
name|QGridLayout
argument_list|(
name|qdesigner_internal__PreviewWidget
argument_list|)
expr_stmt|;
ifndef|#
directive|ifndef
name|Q_OS_MAC
name|gridLayout
operator|->
name|setSpacing
argument_list|(
literal|6
argument_list|)
expr_stmt|;
endif|#
directive|endif
ifndef|#
directive|ifndef
name|Q_OS_MAC
name|gridLayout
operator|->
name|setContentsMargins
argument_list|(
literal|9
argument_list|,
literal|9
argument_list|,
literal|9
argument_list|,
literal|9
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|gridLayout
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"gridLayout"
argument_list|)
argument_list|)
expr_stmt|;
name|vboxLayout
operator|=
name|new
name|QVBoxLayout
argument_list|()
expr_stmt|;
ifndef|#
directive|ifndef
name|Q_OS_MAC
name|vboxLayout
operator|->
name|setSpacing
argument_list|(
literal|6
argument_list|)
expr_stmt|;
endif|#
directive|endif
ifndef|#
directive|ifndef
name|Q_OS_MAC
name|vboxLayout
operator|->
name|setContentsMargins
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|vboxLayout
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"vboxLayout"
argument_list|)
argument_list|)
expr_stmt|;
name|LineEdit1
operator|=
name|new
name|QLineEdit
argument_list|(
name|qdesigner_internal__PreviewWidget
argument_list|)
expr_stmt|;
name|LineEdit1
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"LineEdit1"
argument_list|)
argument_list|)
expr_stmt|;
name|vboxLayout
operator|->
name|addWidget
argument_list|(
name|LineEdit1
argument_list|)
expr_stmt|;
name|ComboBox1
operator|=
name|new
name|QComboBox
argument_list|(
name|qdesigner_internal__PreviewWidget
argument_list|)
expr_stmt|;
name|ComboBox1
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"ComboBox1"
argument_list|)
argument_list|)
expr_stmt|;
name|vboxLayout
operator|->
name|addWidget
argument_list|(
name|ComboBox1
argument_list|)
expr_stmt|;
name|hboxLayout
operator|=
name|new
name|QHBoxLayout
argument_list|()
expr_stmt|;
ifndef|#
directive|ifndef
name|Q_OS_MAC
name|hboxLayout
operator|->
name|setSpacing
argument_list|(
literal|6
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|hboxLayout
operator|->
name|setContentsMargins
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|hboxLayout
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"hboxLayout"
argument_list|)
argument_list|)
expr_stmt|;
name|SpinBox1
operator|=
name|new
name|QSpinBox
argument_list|(
name|qdesigner_internal__PreviewWidget
argument_list|)
expr_stmt|;
name|SpinBox1
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"SpinBox1"
argument_list|)
argument_list|)
expr_stmt|;
name|hboxLayout
operator|->
name|addWidget
argument_list|(
name|SpinBox1
argument_list|)
expr_stmt|;
name|PushButton1
operator|=
name|new
name|QPushButton
argument_list|(
name|qdesigner_internal__PreviewWidget
argument_list|)
expr_stmt|;
name|PushButton1
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"PushButton1"
argument_list|)
argument_list|)
expr_stmt|;
name|hboxLayout
operator|->
name|addWidget
argument_list|(
name|PushButton1
argument_list|)
expr_stmt|;
name|vboxLayout
operator|->
name|addLayout
argument_list|(
name|hboxLayout
argument_list|)
expr_stmt|;
name|ScrollBar1
operator|=
name|new
name|QScrollBar
argument_list|(
name|qdesigner_internal__PreviewWidget
argument_list|)
expr_stmt|;
name|ScrollBar1
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"ScrollBar1"
argument_list|)
argument_list|)
expr_stmt|;
name|ScrollBar1
operator|->
name|setOrientation
argument_list|(
name|Qt
operator|::
name|Horizontal
argument_list|)
expr_stmt|;
name|vboxLayout
operator|->
name|addWidget
argument_list|(
name|ScrollBar1
argument_list|)
expr_stmt|;
name|Slider1
operator|=
name|new
name|QSlider
argument_list|(
name|qdesigner_internal__PreviewWidget
argument_list|)
expr_stmt|;
name|Slider1
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"Slider1"
argument_list|)
argument_list|)
expr_stmt|;
name|Slider1
operator|->
name|setOrientation
argument_list|(
name|Qt
operator|::
name|Horizontal
argument_list|)
expr_stmt|;
name|vboxLayout
operator|->
name|addWidget
argument_list|(
name|Slider1
argument_list|)
expr_stmt|;
name|listWidget
operator|=
name|new
name|QListWidget
argument_list|(
name|qdesigner_internal__PreviewWidget
argument_list|)
expr_stmt|;
name|listWidget
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"listWidget"
argument_list|)
argument_list|)
expr_stmt|;
name|listWidget
operator|->
name|setMaximumSize
argument_list|(
name|QSize
argument_list|(
literal|32767
argument_list|,
literal|50
argument_list|)
argument_list|)
expr_stmt|;
name|vboxLayout
operator|->
name|addWidget
argument_list|(
name|listWidget
argument_list|)
expr_stmt|;
name|gridLayout
operator|->
name|addLayout
argument_list|(
name|vboxLayout
argument_list|,
literal|0
argument_list|,
literal|1
argument_list|,
literal|3
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|spacerItem
operator|=
name|new
name|QSpacerItem
argument_list|(
literal|20
argument_list|,
literal|20
argument_list|,
name|QSizePolicy
operator|::
name|Minimum
argument_list|,
name|QSizePolicy
operator|::
name|Expanding
argument_list|)
expr_stmt|;
name|gridLayout
operator|->
name|addItem
argument_list|(
name|spacerItem
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
name|ProgressBar1
operator|=
name|new
name|QProgressBar
argument_list|(
name|qdesigner_internal__PreviewWidget
argument_list|)
expr_stmt|;
name|ProgressBar1
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"ProgressBar1"
argument_list|)
argument_list|)
expr_stmt|;
name|ProgressBar1
operator|->
name|setOrientation
argument_list|(
name|Qt
operator|::
name|Horizontal
argument_list|)
expr_stmt|;
name|gridLayout
operator|->
name|addWidget
argument_list|(
name|ProgressBar1
argument_list|,
literal|2
argument_list|,
literal|0
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|ButtonGroup2
operator|=
name|new
name|QGroupBox
argument_list|(
name|qdesigner_internal__PreviewWidget
argument_list|)
expr_stmt|;
name|ButtonGroup2
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"ButtonGroup2"
argument_list|)
argument_list|)
expr_stmt|;
name|vboxLayout1
operator|=
name|new
name|QVBoxLayout
argument_list|(
name|ButtonGroup2
argument_list|)
expr_stmt|;
ifndef|#
directive|ifndef
name|Q_OS_MAC
name|vboxLayout1
operator|->
name|setSpacing
argument_list|(
literal|6
argument_list|)
expr_stmt|;
endif|#
directive|endif
ifndef|#
directive|ifndef
name|Q_OS_MAC
name|vboxLayout1
operator|->
name|setContentsMargins
argument_list|(
literal|9
argument_list|,
literal|9
argument_list|,
literal|9
argument_list|,
literal|9
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|vboxLayout1
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"vboxLayout1"
argument_list|)
argument_list|)
expr_stmt|;
name|CheckBox1
operator|=
name|new
name|QCheckBox
argument_list|(
name|ButtonGroup2
argument_list|)
expr_stmt|;
name|CheckBox1
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"CheckBox1"
argument_list|)
argument_list|)
expr_stmt|;
name|CheckBox1
operator|->
name|setChecked
argument_list|(
name|true
argument_list|)
expr_stmt|;
name|vboxLayout1
operator|->
name|addWidget
argument_list|(
name|CheckBox1
argument_list|)
expr_stmt|;
name|CheckBox2
operator|=
name|new
name|QCheckBox
argument_list|(
name|ButtonGroup2
argument_list|)
expr_stmt|;
name|CheckBox2
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"CheckBox2"
argument_list|)
argument_list|)
expr_stmt|;
name|vboxLayout1
operator|->
name|addWidget
argument_list|(
name|CheckBox2
argument_list|)
expr_stmt|;
name|gridLayout
operator|->
name|addWidget
argument_list|(
name|ButtonGroup2
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
name|ButtonGroup1
operator|=
name|new
name|QGroupBox
argument_list|(
name|qdesigner_internal__PreviewWidget
argument_list|)
expr_stmt|;
name|ButtonGroup1
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"ButtonGroup1"
argument_list|)
argument_list|)
expr_stmt|;
name|vboxLayout2
operator|=
name|new
name|QVBoxLayout
argument_list|(
name|ButtonGroup1
argument_list|)
expr_stmt|;
ifndef|#
directive|ifndef
name|Q_OS_MAC
name|vboxLayout2
operator|->
name|setSpacing
argument_list|(
literal|6
argument_list|)
expr_stmt|;
endif|#
directive|endif
ifndef|#
directive|ifndef
name|Q_OS_MAC
name|vboxLayout2
operator|->
name|setContentsMargins
argument_list|(
literal|9
argument_list|,
literal|9
argument_list|,
literal|9
argument_list|,
literal|9
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|vboxLayout2
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"vboxLayout2"
argument_list|)
argument_list|)
expr_stmt|;
name|RadioButton1
operator|=
name|new
name|QRadioButton
argument_list|(
name|ButtonGroup1
argument_list|)
expr_stmt|;
name|RadioButton1
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"RadioButton1"
argument_list|)
argument_list|)
expr_stmt|;
name|RadioButton1
operator|->
name|setChecked
argument_list|(
name|true
argument_list|)
expr_stmt|;
name|vboxLayout2
operator|->
name|addWidget
argument_list|(
name|RadioButton1
argument_list|)
expr_stmt|;
name|RadioButton2
operator|=
name|new
name|QRadioButton
argument_list|(
name|ButtonGroup1
argument_list|)
expr_stmt|;
name|RadioButton2
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"RadioButton2"
argument_list|)
argument_list|)
expr_stmt|;
name|vboxLayout2
operator|->
name|addWidget
argument_list|(
name|RadioButton2
argument_list|)
expr_stmt|;
name|RadioButton3
operator|=
name|new
name|QRadioButton
argument_list|(
name|ButtonGroup1
argument_list|)
expr_stmt|;
name|RadioButton3
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"RadioButton3"
argument_list|)
argument_list|)
expr_stmt|;
name|vboxLayout2
operator|->
name|addWidget
argument_list|(
name|RadioButton3
argument_list|)
expr_stmt|;
name|gridLayout
operator|->
name|addWidget
argument_list|(
name|ButtonGroup1
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
name|retranslateUi
argument_list|(
name|qdesigner_internal__PreviewWidget
argument_list|)
expr_stmt|;
name|QMetaObject
operator|::
name|connectSlotsByName
argument_list|(
name|qdesigner_internal__PreviewWidget
argument_list|)
expr_stmt|;
block|}
comment|// setupUi
name|void
name|retranslateUi
parameter_list|(
name|QWidget
modifier|*
name|qdesigner_internal__PreviewWidget
parameter_list|)
block|{
name|qdesigner_internal__PreviewWidget
operator|->
name|setWindowTitle
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"qdesigner_internal::PreviewWidget"
argument_list|,
literal|"Preview Window"
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
name|LineEdit1
operator|->
name|setText
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"qdesigner_internal::PreviewWidget"
argument_list|,
literal|"LineEdit"
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
name|ComboBox1
operator|->
name|clear
argument_list|()
expr_stmt|;
name|ComboBox1
operator|->
name|insertItems
argument_list|(
literal|0
argument_list|,
name|QStringList
argument_list|()
operator|<<
name|QApplication
operator|::
name|translate
argument_list|(
literal|"qdesigner_internal::PreviewWidget"
argument_list|,
literal|"ComboBox"
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
name|PushButton1
operator|->
name|setText
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"qdesigner_internal::PreviewWidget"
argument_list|,
literal|"PushButton"
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
name|ButtonGroup2
operator|->
name|setTitle
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"qdesigner_internal::PreviewWidget"
argument_list|,
literal|"ButtonGroup2"
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
name|CheckBox1
operator|->
name|setText
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"qdesigner_internal::PreviewWidget"
argument_list|,
literal|"CheckBox1"
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
name|CheckBox2
operator|->
name|setText
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"qdesigner_internal::PreviewWidget"
argument_list|,
literal|"CheckBox2"
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
name|ButtonGroup1
operator|->
name|setTitle
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"qdesigner_internal::PreviewWidget"
argument_list|,
literal|"ButtonGroup"
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
name|RadioButton1
operator|->
name|setText
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"qdesigner_internal::PreviewWidget"
argument_list|,
literal|"RadioButton1"
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
name|RadioButton2
operator|->
name|setText
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"qdesigner_internal::PreviewWidget"
argument_list|,
literal|"RadioButton2"
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
name|RadioButton3
operator|->
name|setText
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"qdesigner_internal::PreviewWidget"
argument_list|,
literal|"RadioButton3"
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
block|}
comment|// retranslateUi
block|}
empty_stmt|;
block|}
end_decl_stmt
begin_comment
comment|// namespace qdesigner_internal
end_comment
begin_decl_stmt
name|namespace
name|qdesigner_internal
block|{
name|namespace
name|Ui
block|{
name|class
name|PreviewWidget
range|:
name|public
name|Ui_PreviewWidget
block|{}
decl_stmt|;
block|}
comment|// namespace Ui
block|}
end_decl_stmt
begin_comment
comment|// namespace qdesigner_internal
end_comment
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// PREVIEWWIDGET_H
end_comment
end_unit
