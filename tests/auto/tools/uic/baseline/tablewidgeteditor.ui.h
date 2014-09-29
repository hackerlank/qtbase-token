begin_unit
begin_comment
comment|/* ********************************************************************* ** ** Copyright (C) 2014 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the autotests of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia. For licensing terms and ** conditions see http://qt.digia.com/licensing. For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights. These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ********************************************************************* */
end_comment
begin_comment
comment|/******************************************************************************** ** Form generated from reading UI file 'tablewidgeteditor.ui' ** ** Created by: Qt User Interface Compiler version 5.0.0 ** ** WARNING! All changes made in this file will be lost when recompiling UI file! ********************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|TABLEWIDGETEDITOR_H
end_ifndef
begin_define
DECL|macro|TABLEWIDGETEDITOR_H
define|#
directive|define
name|TABLEWIDGETEDITOR_H
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
file|<QtWidgets/QDialog>
end_include
begin_include
include|#
directive|include
file|<QtWidgets/QDialogButtonBox>
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
file|<QtWidgets/QLabel>
end_include
begin_include
include|#
directive|include
file|<QtWidgets/QListWidget>
end_include
begin_include
include|#
directive|include
file|<QtWidgets/QSpacerItem>
end_include
begin_include
include|#
directive|include
file|<QtWidgets/QTableWidget>
end_include
begin_include
include|#
directive|include
file|<QtWidgets/QToolButton>
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
begin_include
include|#
directive|include
file|"iconselector_p.h"
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
name|namespace
name|qdesigner_internal
block|{
name|class
name|Ui_TableWidgetEditor
block|{
name|public
label|:
name|QGridLayout
modifier|*
name|gridLayout_4
decl_stmt|;
name|QGroupBox
modifier|*
name|itemsBox
decl_stmt|;
name|QGridLayout
modifier|*
name|gridLayout
decl_stmt|;
name|QTableWidget
modifier|*
name|tableWidget
decl_stmt|;
name|QHBoxLayout
modifier|*
name|horizontalLayout_5
decl_stmt|;
name|QLabel
modifier|*
name|label_3
decl_stmt|;
name|qdesigner_internal
operator|::
name|IconSelector
operator|*
name|itemIconSelector
expr_stmt|;
name|QSpacerItem
modifier|*
name|horizontalSpacer
decl_stmt|;
name|QDialogButtonBox
modifier|*
name|buttonBox
decl_stmt|;
name|QWidget
modifier|*
name|widget
decl_stmt|;
name|QVBoxLayout
modifier|*
name|verticalLayout
decl_stmt|;
name|QGroupBox
modifier|*
name|columnsBox
decl_stmt|;
name|QGridLayout
modifier|*
name|gridLayout_2
decl_stmt|;
name|QListWidget
modifier|*
name|columnsListWidget
decl_stmt|;
name|QHBoxLayout
modifier|*
name|horizontalLayout_3
decl_stmt|;
name|QToolButton
modifier|*
name|newColumnButton
decl_stmt|;
name|QToolButton
modifier|*
name|deleteColumnButton
decl_stmt|;
name|QSpacerItem
modifier|*
name|spacerItem
decl_stmt|;
name|QToolButton
modifier|*
name|moveColumnUpButton
decl_stmt|;
name|QToolButton
modifier|*
name|moveColumnDownButton
decl_stmt|;
name|QHBoxLayout
modifier|*
name|horizontalLayout_2
decl_stmt|;
name|QLabel
modifier|*
name|label
decl_stmt|;
name|qdesigner_internal
operator|::
name|IconSelector
operator|*
name|columnIconSelector
expr_stmt|;
name|QSpacerItem
modifier|*
name|spacerItem1
decl_stmt|;
name|QGroupBox
modifier|*
name|rowsBox
decl_stmt|;
name|QGridLayout
modifier|*
name|gridLayout_3
decl_stmt|;
name|QListWidget
modifier|*
name|rowsListWidget
decl_stmt|;
name|QHBoxLayout
modifier|*
name|horizontalLayout_4
decl_stmt|;
name|QToolButton
modifier|*
name|newRowButton
decl_stmt|;
name|QToolButton
modifier|*
name|deleteRowButton
decl_stmt|;
name|QSpacerItem
modifier|*
name|spacerItem2
decl_stmt|;
name|QToolButton
modifier|*
name|moveRowUpButton
decl_stmt|;
name|QToolButton
modifier|*
name|moveRowDownButton
decl_stmt|;
name|QHBoxLayout
modifier|*
name|horizontalLayout
decl_stmt|;
name|QLabel
modifier|*
name|label_2
decl_stmt|;
name|qdesigner_internal
operator|::
name|IconSelector
operator|*
name|rowIconSelector
expr_stmt|;
name|QSpacerItem
modifier|*
name|spacerItem3
decl_stmt|;
name|void
name|setupUi
parameter_list|(
name|QDialog
modifier|*
name|qdesigner_internal__TableWidgetEditor
parameter_list|)
block|{
if|if
condition|(
name|qdesigner_internal__TableWidgetEditor
operator|->
name|objectName
argument_list|()
operator|.
name|isEmpty
argument_list|()
condition|)
name|qdesigner_internal__TableWidgetEditor
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"qdesigner_internal__TableWidgetEditor"
argument_list|)
argument_list|)
expr_stmt|;
name|qdesigner_internal__TableWidgetEditor
operator|->
name|resize
argument_list|(
literal|591
argument_list|,
literal|455
argument_list|)
expr_stmt|;
name|gridLayout_4
operator|=
name|new
name|QGridLayout
argument_list|(
name|qdesigner_internal__TableWidgetEditor
argument_list|)
expr_stmt|;
name|gridLayout_4
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"gridLayout_4"
argument_list|)
argument_list|)
expr_stmt|;
name|itemsBox
operator|=
name|new
name|QGroupBox
argument_list|(
name|qdesigner_internal__TableWidgetEditor
argument_list|)
expr_stmt|;
name|itemsBox
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"itemsBox"
argument_list|)
argument_list|)
expr_stmt|;
name|gridLayout
operator|=
name|new
name|QGridLayout
argument_list|(
name|itemsBox
argument_list|)
expr_stmt|;
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
name|tableWidget
operator|=
name|new
name|QTableWidget
argument_list|(
name|itemsBox
argument_list|)
expr_stmt|;
name|tableWidget
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"tableWidget"
argument_list|)
argument_list|)
expr_stmt|;
name|gridLayout
operator|->
name|addWidget
argument_list|(
name|tableWidget
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
name|horizontalLayout_5
operator|=
name|new
name|QHBoxLayout
argument_list|()
expr_stmt|;
name|horizontalLayout_5
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"horizontalLayout_5"
argument_list|)
argument_list|)
expr_stmt|;
name|label_3
operator|=
name|new
name|QLabel
argument_list|(
name|itemsBox
argument_list|)
expr_stmt|;
name|label_3
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"label_3"
argument_list|)
argument_list|)
expr_stmt|;
name|horizontalLayout_5
operator|->
name|addWidget
argument_list|(
name|label_3
argument_list|)
expr_stmt|;
name|itemIconSelector
operator|=
name|new
name|qdesigner_internal
operator|::
name|IconSelector
argument_list|(
name|itemsBox
argument_list|)
expr_stmt|;
name|itemIconSelector
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"itemIconSelector"
argument_list|)
argument_list|)
expr_stmt|;
name|horizontalLayout_5
operator|->
name|addWidget
argument_list|(
name|itemIconSelector
argument_list|)
expr_stmt|;
name|horizontalSpacer
operator|=
name|new
name|QSpacerItem
argument_list|(
literal|40
argument_list|,
literal|20
argument_list|,
name|QSizePolicy
operator|::
name|Expanding
argument_list|,
name|QSizePolicy
operator|::
name|Minimum
argument_list|)
expr_stmt|;
name|horizontalLayout_5
operator|->
name|addItem
argument_list|(
name|horizontalSpacer
argument_list|)
expr_stmt|;
name|gridLayout
operator|->
name|addLayout
argument_list|(
name|horizontalLayout_5
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
name|gridLayout_4
operator|->
name|addWidget
argument_list|(
name|itemsBox
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
name|buttonBox
operator|=
name|new
name|QDialogButtonBox
argument_list|(
name|qdesigner_internal__TableWidgetEditor
argument_list|)
expr_stmt|;
name|buttonBox
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"buttonBox"
argument_list|)
argument_list|)
expr_stmt|;
name|buttonBox
operator|->
name|setOrientation
argument_list|(
name|Qt
operator|::
name|Horizontal
argument_list|)
expr_stmt|;
name|buttonBox
operator|->
name|setStandardButtons
argument_list|(
name|QDialogButtonBox
operator|::
name|Cancel
operator||
name|QDialogButtonBox
operator|::
name|Ok
argument_list|)
expr_stmt|;
name|gridLayout_4
operator|->
name|addWidget
argument_list|(
name|buttonBox
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
name|widget
operator|=
name|new
name|QWidget
argument_list|(
name|qdesigner_internal__TableWidgetEditor
argument_list|)
expr_stmt|;
name|widget
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"widget"
argument_list|)
argument_list|)
expr_stmt|;
name|QSizePolicy
name|sizePolicy
argument_list|(
name|QSizePolicy
operator|::
name|Fixed
argument_list|,
name|QSizePolicy
operator|::
name|Preferred
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
name|widget
operator|->
name|sizePolicy
argument_list|()
operator|.
name|hasHeightForWidth
argument_list|()
argument_list|)
expr_stmt|;
name|widget
operator|->
name|setSizePolicy
argument_list|(
name|sizePolicy
argument_list|)
expr_stmt|;
name|verticalLayout
operator|=
name|new
name|QVBoxLayout
argument_list|(
name|widget
argument_list|)
expr_stmt|;
name|verticalLayout
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
name|verticalLayout
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"verticalLayout"
argument_list|)
argument_list|)
expr_stmt|;
name|columnsBox
operator|=
name|new
name|QGroupBox
argument_list|(
name|widget
argument_list|)
expr_stmt|;
name|columnsBox
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"columnsBox"
argument_list|)
argument_list|)
expr_stmt|;
name|gridLayout_2
operator|=
name|new
name|QGridLayout
argument_list|(
name|columnsBox
argument_list|)
expr_stmt|;
name|gridLayout_2
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"gridLayout_2"
argument_list|)
argument_list|)
expr_stmt|;
name|columnsListWidget
operator|=
name|new
name|QListWidget
argument_list|(
name|columnsBox
argument_list|)
expr_stmt|;
name|columnsListWidget
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"columnsListWidget"
argument_list|)
argument_list|)
expr_stmt|;
name|QSizePolicy
name|sizePolicy1
argument_list|(
name|QSizePolicy
operator|::
name|Ignored
argument_list|,
name|QSizePolicy
operator|::
name|Expanding
argument_list|)
decl_stmt|;
name|sizePolicy1
operator|.
name|setHorizontalStretch
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|sizePolicy1
operator|.
name|setVerticalStretch
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|sizePolicy1
operator|.
name|setHeightForWidth
argument_list|(
name|columnsListWidget
operator|->
name|sizePolicy
argument_list|()
operator|.
name|hasHeightForWidth
argument_list|()
argument_list|)
expr_stmt|;
name|columnsListWidget
operator|->
name|setSizePolicy
argument_list|(
name|sizePolicy1
argument_list|)
expr_stmt|;
name|columnsListWidget
operator|->
name|setFocusPolicy
argument_list|(
name|Qt
operator|::
name|TabFocus
argument_list|)
expr_stmt|;
name|gridLayout_2
operator|->
name|addWidget
argument_list|(
name|columnsListWidget
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
name|horizontalLayout_3
operator|=
name|new
name|QHBoxLayout
argument_list|()
expr_stmt|;
name|horizontalLayout_3
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"horizontalLayout_3"
argument_list|)
argument_list|)
expr_stmt|;
name|newColumnButton
operator|=
name|new
name|QToolButton
argument_list|(
name|columnsBox
argument_list|)
expr_stmt|;
name|newColumnButton
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"newColumnButton"
argument_list|)
argument_list|)
expr_stmt|;
name|horizontalLayout_3
operator|->
name|addWidget
argument_list|(
name|newColumnButton
argument_list|)
expr_stmt|;
name|deleteColumnButton
operator|=
name|new
name|QToolButton
argument_list|(
name|columnsBox
argument_list|)
expr_stmt|;
name|deleteColumnButton
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"deleteColumnButton"
argument_list|)
argument_list|)
expr_stmt|;
name|horizontalLayout_3
operator|->
name|addWidget
argument_list|(
name|deleteColumnButton
argument_list|)
expr_stmt|;
name|spacerItem
operator|=
name|new
name|QSpacerItem
argument_list|(
literal|0
argument_list|,
literal|23
argument_list|,
name|QSizePolicy
operator|::
name|Expanding
argument_list|,
name|QSizePolicy
operator|::
name|Minimum
argument_list|)
expr_stmt|;
name|horizontalLayout_3
operator|->
name|addItem
argument_list|(
name|spacerItem
argument_list|)
expr_stmt|;
name|moveColumnUpButton
operator|=
name|new
name|QToolButton
argument_list|(
name|columnsBox
argument_list|)
expr_stmt|;
name|moveColumnUpButton
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"moveColumnUpButton"
argument_list|)
argument_list|)
expr_stmt|;
name|horizontalLayout_3
operator|->
name|addWidget
argument_list|(
name|moveColumnUpButton
argument_list|)
expr_stmt|;
name|moveColumnDownButton
operator|=
name|new
name|QToolButton
argument_list|(
name|columnsBox
argument_list|)
expr_stmt|;
name|moveColumnDownButton
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"moveColumnDownButton"
argument_list|)
argument_list|)
expr_stmt|;
name|horizontalLayout_3
operator|->
name|addWidget
argument_list|(
name|moveColumnDownButton
argument_list|)
expr_stmt|;
name|gridLayout_2
operator|->
name|addLayout
argument_list|(
name|horizontalLayout_3
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
name|horizontalLayout_2
operator|=
name|new
name|QHBoxLayout
argument_list|()
expr_stmt|;
name|horizontalLayout_2
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"horizontalLayout_2"
argument_list|)
argument_list|)
expr_stmt|;
name|label
operator|=
name|new
name|QLabel
argument_list|(
name|columnsBox
argument_list|)
expr_stmt|;
name|label
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"label"
argument_list|)
argument_list|)
expr_stmt|;
name|horizontalLayout_2
operator|->
name|addWidget
argument_list|(
name|label
argument_list|)
expr_stmt|;
name|columnIconSelector
operator|=
name|new
name|qdesigner_internal
operator|::
name|IconSelector
argument_list|(
name|columnsBox
argument_list|)
expr_stmt|;
name|columnIconSelector
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"columnIconSelector"
argument_list|)
argument_list|)
expr_stmt|;
name|horizontalLayout_2
operator|->
name|addWidget
argument_list|(
name|columnIconSelector
argument_list|)
expr_stmt|;
name|spacerItem1
operator|=
name|new
name|QSpacerItem
argument_list|(
literal|0
argument_list|,
literal|21
argument_list|,
name|QSizePolicy
operator|::
name|Expanding
argument_list|,
name|QSizePolicy
operator|::
name|Minimum
argument_list|)
expr_stmt|;
name|horizontalLayout_2
operator|->
name|addItem
argument_list|(
name|spacerItem1
argument_list|)
expr_stmt|;
name|gridLayout_2
operator|->
name|addLayout
argument_list|(
name|horizontalLayout_2
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
name|verticalLayout
operator|->
name|addWidget
argument_list|(
name|columnsBox
argument_list|)
expr_stmt|;
name|rowsBox
operator|=
name|new
name|QGroupBox
argument_list|(
name|widget
argument_list|)
expr_stmt|;
name|rowsBox
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"rowsBox"
argument_list|)
argument_list|)
expr_stmt|;
name|gridLayout_3
operator|=
name|new
name|QGridLayout
argument_list|(
name|rowsBox
argument_list|)
expr_stmt|;
name|gridLayout_3
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"gridLayout_3"
argument_list|)
argument_list|)
expr_stmt|;
name|rowsListWidget
operator|=
name|new
name|QListWidget
argument_list|(
name|rowsBox
argument_list|)
expr_stmt|;
name|rowsListWidget
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"rowsListWidget"
argument_list|)
argument_list|)
expr_stmt|;
name|sizePolicy1
operator|.
name|setHeightForWidth
argument_list|(
name|rowsListWidget
operator|->
name|sizePolicy
argument_list|()
operator|.
name|hasHeightForWidth
argument_list|()
argument_list|)
expr_stmt|;
name|rowsListWidget
operator|->
name|setSizePolicy
argument_list|(
name|sizePolicy1
argument_list|)
expr_stmt|;
name|rowsListWidget
operator|->
name|setFocusPolicy
argument_list|(
name|Qt
operator|::
name|TabFocus
argument_list|)
expr_stmt|;
name|gridLayout_3
operator|->
name|addWidget
argument_list|(
name|rowsListWidget
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
name|horizontalLayout_4
operator|=
name|new
name|QHBoxLayout
argument_list|()
expr_stmt|;
name|horizontalLayout_4
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"horizontalLayout_4"
argument_list|)
argument_list|)
expr_stmt|;
name|newRowButton
operator|=
name|new
name|QToolButton
argument_list|(
name|rowsBox
argument_list|)
expr_stmt|;
name|newRowButton
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"newRowButton"
argument_list|)
argument_list|)
expr_stmt|;
name|horizontalLayout_4
operator|->
name|addWidget
argument_list|(
name|newRowButton
argument_list|)
expr_stmt|;
name|deleteRowButton
operator|=
name|new
name|QToolButton
argument_list|(
name|rowsBox
argument_list|)
expr_stmt|;
name|deleteRowButton
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"deleteRowButton"
argument_list|)
argument_list|)
expr_stmt|;
name|horizontalLayout_4
operator|->
name|addWidget
argument_list|(
name|deleteRowButton
argument_list|)
expr_stmt|;
name|spacerItem2
operator|=
name|new
name|QSpacerItem
argument_list|(
literal|0
argument_list|,
literal|23
argument_list|,
name|QSizePolicy
operator|::
name|Expanding
argument_list|,
name|QSizePolicy
operator|::
name|Minimum
argument_list|)
expr_stmt|;
name|horizontalLayout_4
operator|->
name|addItem
argument_list|(
name|spacerItem2
argument_list|)
expr_stmt|;
name|moveRowUpButton
operator|=
name|new
name|QToolButton
argument_list|(
name|rowsBox
argument_list|)
expr_stmt|;
name|moveRowUpButton
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"moveRowUpButton"
argument_list|)
argument_list|)
expr_stmt|;
name|horizontalLayout_4
operator|->
name|addWidget
argument_list|(
name|moveRowUpButton
argument_list|)
expr_stmt|;
name|moveRowDownButton
operator|=
name|new
name|QToolButton
argument_list|(
name|rowsBox
argument_list|)
expr_stmt|;
name|moveRowDownButton
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"moveRowDownButton"
argument_list|)
argument_list|)
expr_stmt|;
name|horizontalLayout_4
operator|->
name|addWidget
argument_list|(
name|moveRowDownButton
argument_list|)
expr_stmt|;
name|gridLayout_3
operator|->
name|addLayout
argument_list|(
name|horizontalLayout_4
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
name|horizontalLayout
operator|=
name|new
name|QHBoxLayout
argument_list|()
expr_stmt|;
name|horizontalLayout
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"horizontalLayout"
argument_list|)
argument_list|)
expr_stmt|;
name|label_2
operator|=
name|new
name|QLabel
argument_list|(
name|rowsBox
argument_list|)
expr_stmt|;
name|label_2
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"label_2"
argument_list|)
argument_list|)
expr_stmt|;
name|horizontalLayout
operator|->
name|addWidget
argument_list|(
name|label_2
argument_list|)
expr_stmt|;
name|rowIconSelector
operator|=
name|new
name|qdesigner_internal
operator|::
name|IconSelector
argument_list|(
name|rowsBox
argument_list|)
expr_stmt|;
name|rowIconSelector
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"rowIconSelector"
argument_list|)
argument_list|)
expr_stmt|;
name|horizontalLayout
operator|->
name|addWidget
argument_list|(
name|rowIconSelector
argument_list|)
expr_stmt|;
name|spacerItem3
operator|=
name|new
name|QSpacerItem
argument_list|(
literal|0
argument_list|,
literal|21
argument_list|,
name|QSizePolicy
operator|::
name|Expanding
argument_list|,
name|QSizePolicy
operator|::
name|Minimum
argument_list|)
expr_stmt|;
name|horizontalLayout
operator|->
name|addItem
argument_list|(
name|spacerItem3
argument_list|)
expr_stmt|;
name|gridLayout_3
operator|->
name|addLayout
argument_list|(
name|horizontalLayout
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
name|verticalLayout
operator|->
name|addWidget
argument_list|(
name|rowsBox
argument_list|)
expr_stmt|;
name|gridLayout_4
operator|->
name|addWidget
argument_list|(
name|widget
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
name|itemsBox
operator|->
name|raise
argument_list|()
expr_stmt|;
name|buttonBox
operator|->
name|raise
argument_list|()
expr_stmt|;
name|widget
operator|->
name|raise
argument_list|()
expr_stmt|;
name|QWidget
operator|::
name|setTabOrder
argument_list|(
name|tableWidget
argument_list|,
name|columnsListWidget
argument_list|)
expr_stmt|;
name|QWidget
operator|::
name|setTabOrder
argument_list|(
name|columnsListWidget
argument_list|,
name|newColumnButton
argument_list|)
expr_stmt|;
name|QWidget
operator|::
name|setTabOrder
argument_list|(
name|newColumnButton
argument_list|,
name|deleteColumnButton
argument_list|)
expr_stmt|;
name|QWidget
operator|::
name|setTabOrder
argument_list|(
name|deleteColumnButton
argument_list|,
name|moveColumnUpButton
argument_list|)
expr_stmt|;
name|QWidget
operator|::
name|setTabOrder
argument_list|(
name|moveColumnUpButton
argument_list|,
name|moveColumnDownButton
argument_list|)
expr_stmt|;
name|QWidget
operator|::
name|setTabOrder
argument_list|(
name|moveColumnDownButton
argument_list|,
name|rowsListWidget
argument_list|)
expr_stmt|;
name|QWidget
operator|::
name|setTabOrder
argument_list|(
name|rowsListWidget
argument_list|,
name|newRowButton
argument_list|)
expr_stmt|;
name|QWidget
operator|::
name|setTabOrder
argument_list|(
name|newRowButton
argument_list|,
name|deleteRowButton
argument_list|)
expr_stmt|;
name|QWidget
operator|::
name|setTabOrder
argument_list|(
name|deleteRowButton
argument_list|,
name|moveRowUpButton
argument_list|)
expr_stmt|;
name|QWidget
operator|::
name|setTabOrder
argument_list|(
name|moveRowUpButton
argument_list|,
name|moveRowDownButton
argument_list|)
expr_stmt|;
name|retranslateUi
argument_list|(
name|qdesigner_internal__TableWidgetEditor
argument_list|)
expr_stmt|;
name|QObject
operator|::
name|connect
argument_list|(
name|buttonBox
argument_list|,
name|SIGNAL
argument_list|(
name|accepted
argument_list|()
argument_list|)
argument_list|,
name|qdesigner_internal__TableWidgetEditor
argument_list|,
name|SLOT
argument_list|(
name|accept
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|QObject
operator|::
name|connect
argument_list|(
name|buttonBox
argument_list|,
name|SIGNAL
argument_list|(
name|rejected
argument_list|()
argument_list|)
argument_list|,
name|qdesigner_internal__TableWidgetEditor
argument_list|,
name|SLOT
argument_list|(
name|reject
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|QMetaObject
operator|::
name|connectSlotsByName
argument_list|(
name|qdesigner_internal__TableWidgetEditor
argument_list|)
expr_stmt|;
block|}
comment|// setupUi
name|void
name|retranslateUi
parameter_list|(
name|QDialog
modifier|*
name|qdesigner_internal__TableWidgetEditor
parameter_list|)
block|{
name|qdesigner_internal__TableWidgetEditor
operator|->
name|setWindowTitle
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"qdesigner_internal::TableWidgetEditor"
argument_list|,
literal|"Edit Table Widget"
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
name|itemsBox
operator|->
name|setTitle
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"qdesigner_internal::TableWidgetEditor"
argument_list|,
literal|"Table Items"
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
ifndef|#
directive|ifndef
name|QT_NO_TOOLTIP
name|tableWidget
operator|->
name|setToolTip
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"qdesigner_internal::TableWidgetEditor"
argument_list|,
literal|"Table Items"
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|// QT_NO_TOOLTIP
name|label_3
operator|->
name|setText
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"qdesigner_internal::TableWidgetEditor"
argument_list|,
literal|"Icon"
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
name|columnsBox
operator|->
name|setTitle
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"qdesigner_internal::TableWidgetEditor"
argument_list|,
literal|"Columns"
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
ifndef|#
directive|ifndef
name|QT_NO_TOOLTIP
name|columnsListWidget
operator|->
name|setToolTip
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"qdesigner_internal::TableWidgetEditor"
argument_list|,
literal|"Table Columns"
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|// QT_NO_TOOLTIP
ifndef|#
directive|ifndef
name|QT_NO_TOOLTIP
name|newColumnButton
operator|->
name|setToolTip
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"qdesigner_internal::TableWidgetEditor"
argument_list|,
literal|"New Column"
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|// QT_NO_TOOLTIP
name|newColumnButton
operator|->
name|setText
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"qdesigner_internal::TableWidgetEditor"
argument_list|,
literal|"New"
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
ifndef|#
directive|ifndef
name|QT_NO_TOOLTIP
name|deleteColumnButton
operator|->
name|setToolTip
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"qdesigner_internal::TableWidgetEditor"
argument_list|,
literal|"Delete Column"
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|// QT_NO_TOOLTIP
name|deleteColumnButton
operator|->
name|setText
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"qdesigner_internal::TableWidgetEditor"
argument_list|,
literal|"Delete"
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
ifndef|#
directive|ifndef
name|QT_NO_TOOLTIP
name|moveColumnUpButton
operator|->
name|setToolTip
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"qdesigner_internal::TableWidgetEditor"
argument_list|,
literal|"Move Column Up"
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|// QT_NO_TOOLTIP
name|moveColumnUpButton
operator|->
name|setText
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"qdesigner_internal::TableWidgetEditor"
argument_list|,
literal|"U"
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
ifndef|#
directive|ifndef
name|QT_NO_TOOLTIP
name|moveColumnDownButton
operator|->
name|setToolTip
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"qdesigner_internal::TableWidgetEditor"
argument_list|,
literal|"Move Column Down"
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|// QT_NO_TOOLTIP
name|moveColumnDownButton
operator|->
name|setText
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"qdesigner_internal::TableWidgetEditor"
argument_list|,
literal|"D"
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
name|label
operator|->
name|setText
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"qdesigner_internal::TableWidgetEditor"
argument_list|,
literal|"Icon"
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
name|rowsBox
operator|->
name|setTitle
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"qdesigner_internal::TableWidgetEditor"
argument_list|,
literal|"Rows"
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
ifndef|#
directive|ifndef
name|QT_NO_TOOLTIP
name|rowsListWidget
operator|->
name|setToolTip
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"qdesigner_internal::TableWidgetEditor"
argument_list|,
literal|"Table Rows"
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|// QT_NO_TOOLTIP
ifndef|#
directive|ifndef
name|QT_NO_TOOLTIP
name|newRowButton
operator|->
name|setToolTip
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"qdesigner_internal::TableWidgetEditor"
argument_list|,
literal|"New Row"
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|// QT_NO_TOOLTIP
name|newRowButton
operator|->
name|setText
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"qdesigner_internal::TableWidgetEditor"
argument_list|,
literal|"New"
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
ifndef|#
directive|ifndef
name|QT_NO_TOOLTIP
name|deleteRowButton
operator|->
name|setToolTip
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"qdesigner_internal::TableWidgetEditor"
argument_list|,
literal|"Delete Row"
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|// QT_NO_TOOLTIP
name|deleteRowButton
operator|->
name|setText
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"qdesigner_internal::TableWidgetEditor"
argument_list|,
literal|"Delete"
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
ifndef|#
directive|ifndef
name|QT_NO_TOOLTIP
name|moveRowUpButton
operator|->
name|setToolTip
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"qdesigner_internal::TableWidgetEditor"
argument_list|,
literal|"Move Row Up"
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|// QT_NO_TOOLTIP
name|moveRowUpButton
operator|->
name|setText
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"qdesigner_internal::TableWidgetEditor"
argument_list|,
literal|"U"
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
ifndef|#
directive|ifndef
name|QT_NO_TOOLTIP
name|moveRowDownButton
operator|->
name|setToolTip
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"qdesigner_internal::TableWidgetEditor"
argument_list|,
literal|"Move Row Down"
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|// QT_NO_TOOLTIP
name|moveRowDownButton
operator|->
name|setText
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"qdesigner_internal::TableWidgetEditor"
argument_list|,
literal|"D"
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
name|label_2
operator|->
name|setText
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"qdesigner_internal::TableWidgetEditor"
argument_list|,
literal|"Icon"
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
name|TableWidgetEditor
range|:
name|public
name|Ui_TableWidgetEditor
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
comment|// TABLEWIDGETEDITOR_H
end_comment
end_unit
