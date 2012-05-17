begin_unit
begin_comment
comment|/* ********************************************************************* ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the autotests of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ********************************************************************* */
end_comment
begin_comment
comment|/******************************************************************************** ** Form generated from reading UI file 'treewidgeteditor.ui' ** ** Created: Fri Sep 4 10:17:15 2009 **      by: Qt User Interface Compiler version 4.6.0 ** ** WARNING! All changes made in this file will be lost when recompiling UI file! ********************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|TREEWIDGETEDITOR_H
end_ifndef
begin_define
DECL|macro|TREEWIDGETEDITOR_H
define|#
directive|define
name|TREEWIDGETEDITOR_H
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
file|<QtWidgets/QToolButton>
end_include
begin_include
include|#
directive|include
file|<QtWidgets/QTreeWidget>
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
name|Ui_TreeWidgetEditor
block|{
name|public
label|:
name|QGridLayout
modifier|*
name|gridLayout_3
decl_stmt|;
name|QGroupBox
modifier|*
name|itemsBox
decl_stmt|;
name|QGridLayout
modifier|*
name|gridLayout
decl_stmt|;
name|QTreeWidget
modifier|*
name|treeWidget
decl_stmt|;
name|QHBoxLayout
modifier|*
name|horizontalLayout_4
decl_stmt|;
name|QToolButton
modifier|*
name|newItemButton
decl_stmt|;
name|QToolButton
modifier|*
name|newSubItemButton
decl_stmt|;
name|QToolButton
modifier|*
name|deleteItemButton
decl_stmt|;
name|QSpacerItem
modifier|*
name|spacerItem
decl_stmt|;
name|QToolButton
modifier|*
name|moveItemLeftButton
decl_stmt|;
name|QToolButton
modifier|*
name|moveItemRightButton
decl_stmt|;
name|QToolButton
modifier|*
name|moveItemUpButton
decl_stmt|;
name|QToolButton
modifier|*
name|moveItemDownButton
decl_stmt|;
name|QHBoxLayout
modifier|*
name|horizontalLayout_2
decl_stmt|;
name|QLabel
modifier|*
name|label_2
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
name|listWidget
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
name|spacerItem1
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
name|horizontalLayout
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
name|spacerItem2
decl_stmt|;
name|QDialogButtonBox
modifier|*
name|buttonBox
decl_stmt|;
name|void
name|setupUi
parameter_list|(
name|QDialog
modifier|*
name|qdesigner_internal__TreeWidgetEditor
parameter_list|)
block|{
if|if
condition|(
name|qdesigner_internal__TreeWidgetEditor
operator|->
name|objectName
argument_list|()
operator|.
name|isEmpty
argument_list|()
condition|)
name|qdesigner_internal__TreeWidgetEditor
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"qdesigner_internal__TreeWidgetEditor"
argument_list|)
argument_list|)
expr_stmt|;
name|qdesigner_internal__TreeWidgetEditor
operator|->
name|resize
argument_list|(
literal|619
argument_list|,
literal|321
argument_list|)
expr_stmt|;
name|gridLayout_3
operator|=
name|new
name|QGridLayout
argument_list|(
name|qdesigner_internal__TreeWidgetEditor
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
name|itemsBox
operator|=
name|new
name|QGroupBox
argument_list|(
name|qdesigner_internal__TreeWidgetEditor
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
name|treeWidget
operator|=
name|new
name|QTreeWidget
argument_list|(
name|itemsBox
argument_list|)
expr_stmt|;
name|treeWidget
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"treeWidget"
argument_list|)
argument_list|)
expr_stmt|;
name|treeWidget
operator|->
name|setFocusPolicy
argument_list|(
name|Qt
operator|::
name|TabFocus
argument_list|)
expr_stmt|;
name|gridLayout
operator|->
name|addWidget
argument_list|(
name|treeWidget
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
name|newItemButton
operator|=
name|new
name|QToolButton
argument_list|(
name|itemsBox
argument_list|)
expr_stmt|;
name|newItemButton
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"newItemButton"
argument_list|)
argument_list|)
expr_stmt|;
name|horizontalLayout_4
operator|->
name|addWidget
argument_list|(
name|newItemButton
argument_list|)
expr_stmt|;
name|newSubItemButton
operator|=
name|new
name|QToolButton
argument_list|(
name|itemsBox
argument_list|)
expr_stmt|;
name|newSubItemButton
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"newSubItemButton"
argument_list|)
argument_list|)
expr_stmt|;
name|horizontalLayout_4
operator|->
name|addWidget
argument_list|(
name|newSubItemButton
argument_list|)
expr_stmt|;
name|deleteItemButton
operator|=
name|new
name|QToolButton
argument_list|(
name|itemsBox
argument_list|)
expr_stmt|;
name|deleteItemButton
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"deleteItemButton"
argument_list|)
argument_list|)
expr_stmt|;
name|horizontalLayout_4
operator|->
name|addWidget
argument_list|(
name|deleteItemButton
argument_list|)
expr_stmt|;
name|spacerItem
operator|=
name|new
name|QSpacerItem
argument_list|(
literal|28
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
name|spacerItem
argument_list|)
expr_stmt|;
name|moveItemLeftButton
operator|=
name|new
name|QToolButton
argument_list|(
name|itemsBox
argument_list|)
expr_stmt|;
name|moveItemLeftButton
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"moveItemLeftButton"
argument_list|)
argument_list|)
expr_stmt|;
name|horizontalLayout_4
operator|->
name|addWidget
argument_list|(
name|moveItemLeftButton
argument_list|)
expr_stmt|;
name|moveItemRightButton
operator|=
name|new
name|QToolButton
argument_list|(
name|itemsBox
argument_list|)
expr_stmt|;
name|moveItemRightButton
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"moveItemRightButton"
argument_list|)
argument_list|)
expr_stmt|;
name|horizontalLayout_4
operator|->
name|addWidget
argument_list|(
name|moveItemRightButton
argument_list|)
expr_stmt|;
name|moveItemUpButton
operator|=
name|new
name|QToolButton
argument_list|(
name|itemsBox
argument_list|)
expr_stmt|;
name|moveItemUpButton
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"moveItemUpButton"
argument_list|)
argument_list|)
expr_stmt|;
name|horizontalLayout_4
operator|->
name|addWidget
argument_list|(
name|moveItemUpButton
argument_list|)
expr_stmt|;
name|moveItemDownButton
operator|=
name|new
name|QToolButton
argument_list|(
name|itemsBox
argument_list|)
expr_stmt|;
name|moveItemDownButton
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"moveItemDownButton"
argument_list|)
argument_list|)
expr_stmt|;
name|horizontalLayout_4
operator|->
name|addWidget
argument_list|(
name|moveItemDownButton
argument_list|)
expr_stmt|;
name|gridLayout
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
name|label_2
operator|=
name|new
name|QLabel
argument_list|(
name|itemsBox
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
name|horizontalLayout_2
operator|->
name|addWidget
argument_list|(
name|label_2
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
name|horizontalLayout_2
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
literal|288
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
name|horizontalSpacer
argument_list|)
expr_stmt|;
name|gridLayout
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
name|gridLayout_3
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
name|columnsBox
operator|=
name|new
name|QGroupBox
argument_list|(
name|qdesigner_internal__TreeWidgetEditor
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
name|columnsBox
operator|->
name|sizePolicy
argument_list|()
operator|.
name|hasHeightForWidth
argument_list|()
argument_list|)
expr_stmt|;
name|columnsBox
operator|->
name|setSizePolicy
argument_list|(
name|sizePolicy
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
name|listWidget
operator|=
name|new
name|QListWidget
argument_list|(
name|columnsBox
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
name|listWidget
operator|->
name|sizePolicy
argument_list|()
operator|.
name|hasHeightForWidth
argument_list|()
argument_list|)
expr_stmt|;
name|listWidget
operator|->
name|setSizePolicy
argument_list|(
name|sizePolicy1
argument_list|)
expr_stmt|;
name|listWidget
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
name|listWidget
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
name|spacerItem1
operator|=
name|new
name|QSpacerItem
argument_list|(
literal|13
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
name|spacerItem1
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
name|horizontalLayout
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
name|horizontalLayout
operator|->
name|addWidget
argument_list|(
name|columnIconSelector
argument_list|)
expr_stmt|;
name|spacerItem2
operator|=
name|new
name|QSpacerItem
argument_list|(
literal|0
argument_list|,
literal|10
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
name|spacerItem2
argument_list|)
expr_stmt|;
name|gridLayout_2
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
name|gridLayout_3
operator|->
name|addWidget
argument_list|(
name|columnsBox
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
name|buttonBox
operator|=
name|new
name|QDialogButtonBox
argument_list|(
name|qdesigner_internal__TreeWidgetEditor
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
name|gridLayout_3
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
name|QWidget
operator|::
name|setTabOrder
argument_list|(
name|treeWidget
argument_list|,
name|newItemButton
argument_list|)
expr_stmt|;
name|QWidget
operator|::
name|setTabOrder
argument_list|(
name|newItemButton
argument_list|,
name|newSubItemButton
argument_list|)
expr_stmt|;
name|QWidget
operator|::
name|setTabOrder
argument_list|(
name|newSubItemButton
argument_list|,
name|deleteItemButton
argument_list|)
expr_stmt|;
name|QWidget
operator|::
name|setTabOrder
argument_list|(
name|deleteItemButton
argument_list|,
name|moveItemLeftButton
argument_list|)
expr_stmt|;
name|QWidget
operator|::
name|setTabOrder
argument_list|(
name|moveItemLeftButton
argument_list|,
name|moveItemRightButton
argument_list|)
expr_stmt|;
name|QWidget
operator|::
name|setTabOrder
argument_list|(
name|moveItemRightButton
argument_list|,
name|moveItemUpButton
argument_list|)
expr_stmt|;
name|QWidget
operator|::
name|setTabOrder
argument_list|(
name|moveItemUpButton
argument_list|,
name|moveItemDownButton
argument_list|)
expr_stmt|;
name|QWidget
operator|::
name|setTabOrder
argument_list|(
name|moveItemDownButton
argument_list|,
name|listWidget
argument_list|)
expr_stmt|;
name|QWidget
operator|::
name|setTabOrder
argument_list|(
name|listWidget
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
name|retranslateUi
argument_list|(
name|qdesigner_internal__TreeWidgetEditor
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
name|qdesigner_internal__TreeWidgetEditor
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
name|qdesigner_internal__TreeWidgetEditor
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
name|qdesigner_internal__TreeWidgetEditor
argument_list|)
expr_stmt|;
block|}
comment|// setupUi
name|void
name|retranslateUi
parameter_list|(
name|QDialog
modifier|*
name|qdesigner_internal__TreeWidgetEditor
parameter_list|)
block|{
name|qdesigner_internal__TreeWidgetEditor
operator|->
name|setWindowTitle
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"qdesigner_internal::TreeWidgetEditor"
argument_list|,
literal|"Edit Tree Widget"
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
literal|"qdesigner_internal::TreeWidgetEditor"
argument_list|,
literal|"Tree Items"
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
name|QTreeWidgetItem
modifier|*
name|___qtreewidgetitem
init|=
name|treeWidget
operator|->
name|headerItem
argument_list|()
decl_stmt|;
name|___qtreewidgetitem
operator|->
name|setText
argument_list|(
literal|0
argument_list|,
name|QApplication
operator|::
name|translate
argument_list|(
literal|"qdesigner_internal::TreeWidgetEditor"
argument_list|,
literal|"1"
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
ifndef|#
directive|ifndef
name|QT_NO_TOOLTIP
name|treeWidget
operator|->
name|setToolTip
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"qdesigner_internal::TreeWidgetEditor"
argument_list|,
literal|"Tree Items"
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
name|newItemButton
operator|->
name|setToolTip
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"qdesigner_internal::TreeWidgetEditor"
argument_list|,
literal|"New Item"
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|// QT_NO_TOOLTIP
name|newItemButton
operator|->
name|setText
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"qdesigner_internal::TreeWidgetEditor"
argument_list|,
literal|"&New"
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
ifndef|#
directive|ifndef
name|QT_NO_TOOLTIP
name|newSubItemButton
operator|->
name|setToolTip
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"qdesigner_internal::TreeWidgetEditor"
argument_list|,
literal|"New Subitem"
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|// QT_NO_TOOLTIP
name|newSubItemButton
operator|->
name|setText
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"qdesigner_internal::TreeWidgetEditor"
argument_list|,
literal|"New&Subitem"
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
ifndef|#
directive|ifndef
name|QT_NO_TOOLTIP
name|deleteItemButton
operator|->
name|setToolTip
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"qdesigner_internal::TreeWidgetEditor"
argument_list|,
literal|"Delete Item"
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|// QT_NO_TOOLTIP
name|deleteItemButton
operator|->
name|setText
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"qdesigner_internal::TreeWidgetEditor"
argument_list|,
literal|"&Delete"
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
ifndef|#
directive|ifndef
name|QT_NO_TOOLTIP
name|moveItemLeftButton
operator|->
name|setToolTip
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"qdesigner_internal::TreeWidgetEditor"
argument_list|,
literal|"Move Item Left (before Parent Item)"
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|// QT_NO_TOOLTIP
name|moveItemLeftButton
operator|->
name|setText
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"qdesigner_internal::TreeWidgetEditor"
argument_list|,
literal|"L"
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
ifndef|#
directive|ifndef
name|QT_NO_TOOLTIP
name|moveItemRightButton
operator|->
name|setToolTip
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"qdesigner_internal::TreeWidgetEditor"
argument_list|,
literal|"Move Item Right (as a First Subitem of the Next Sibling Item)"
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|// QT_NO_TOOLTIP
name|moveItemRightButton
operator|->
name|setText
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"qdesigner_internal::TreeWidgetEditor"
argument_list|,
literal|"R"
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
ifndef|#
directive|ifndef
name|QT_NO_TOOLTIP
name|moveItemUpButton
operator|->
name|setToolTip
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"qdesigner_internal::TreeWidgetEditor"
argument_list|,
literal|"Move Item Up"
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|// QT_NO_TOOLTIP
name|moveItemUpButton
operator|->
name|setText
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"qdesigner_internal::TreeWidgetEditor"
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
name|moveItemDownButton
operator|->
name|setToolTip
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"qdesigner_internal::TreeWidgetEditor"
argument_list|,
literal|"Move Item Down"
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|// QT_NO_TOOLTIP
name|moveItemDownButton
operator|->
name|setText
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"qdesigner_internal::TreeWidgetEditor"
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
literal|"qdesigner_internal::TreeWidgetEditor"
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
literal|"qdesigner_internal::TreeWidgetEditor"
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
name|listWidget
operator|->
name|setToolTip
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"qdesigner_internal::TreeWidgetEditor"
argument_list|,
literal|"Tree Columns"
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
literal|"qdesigner_internal::TreeWidgetEditor"
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
literal|"qdesigner_internal::TreeWidgetEditor"
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
literal|"qdesigner_internal::TreeWidgetEditor"
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
literal|"qdesigner_internal::TreeWidgetEditor"
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
literal|"qdesigner_internal::TreeWidgetEditor"
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
literal|"qdesigner_internal::TreeWidgetEditor"
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
literal|"qdesigner_internal::TreeWidgetEditor"
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
literal|"qdesigner_internal::TreeWidgetEditor"
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
literal|"qdesigner_internal::TreeWidgetEditor"
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
name|TreeWidgetEditor
range|:
name|public
name|Ui_TreeWidgetEditor
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
comment|// TREEWIDGETEDITOR_H
end_comment
end_unit
