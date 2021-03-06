begin_unit
begin_comment
comment|/* ********************************************************************* ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the autotests of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:GPL-EXCEPT$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3 as published by the Free Software ** Foundation with exceptions as appearing in the file LICENSE.GPL3-EXCEPT ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ********************************************************************* */
end_comment
begin_comment
comment|/******************************************************************************** ** Form generated from reading UI file 'helpdialog.ui' ** ** Created by: Qt User Interface Compiler version 5.0.0 ** ** WARNING! All changes made in this file will be lost when recompiling UI file! ********************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|HELPDIALOG_H
end_ifndef
begin_define
DECL|macro|HELPDIALOG_H
define|#
directive|define
name|HELPDIALOG_H
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
file|<QtWidgets/QFrame>
end_include
begin_include
include|#
directive|include
file|<QtWidgets/QGridLayout>
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
file|<QtWidgets/QLineEdit>
end_include
begin_include
include|#
directive|include
file|<QtWidgets/QListView>
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
file|<QtWidgets/QSpacerItem>
end_include
begin_include
include|#
directive|include
file|<QtWidgets/QTabWidget>
end_include
begin_include
include|#
directive|include
file|<QtWidgets/QTreeWidget>
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
name|class
name|Ui_HelpDialog
block|{
name|public
label|:
name|QVBoxLayout
modifier|*
name|vboxLayout
decl_stmt|;
name|QTabWidget
modifier|*
name|tabWidget
decl_stmt|;
name|QWidget
modifier|*
name|contentPage
decl_stmt|;
name|QVBoxLayout
modifier|*
name|vboxLayout1
decl_stmt|;
name|QTreeWidget
modifier|*
name|listContents
decl_stmt|;
name|QWidget
modifier|*
name|indexPage
decl_stmt|;
name|QVBoxLayout
modifier|*
name|vboxLayout2
decl_stmt|;
name|QLabel
modifier|*
name|TextLabel1
decl_stmt|;
name|QLineEdit
modifier|*
name|editIndex
decl_stmt|;
name|QListView
modifier|*
name|listIndex
decl_stmt|;
name|QWidget
modifier|*
name|bookmarkPage
decl_stmt|;
name|QVBoxLayout
modifier|*
name|vboxLayout3
decl_stmt|;
name|QTreeWidget
modifier|*
name|listBookmarks
decl_stmt|;
name|QHBoxLayout
modifier|*
name|hboxLayout
decl_stmt|;
name|QSpacerItem
modifier|*
name|spacerItem
decl_stmt|;
name|QPushButton
modifier|*
name|buttonAdd
decl_stmt|;
name|QPushButton
modifier|*
name|buttonRemove
decl_stmt|;
name|QWidget
modifier|*
name|searchPage
decl_stmt|;
name|QGridLayout
modifier|*
name|gridLayout
decl_stmt|;
name|QSpacerItem
modifier|*
name|spacerItem1
decl_stmt|;
name|QLabel
modifier|*
name|TextLabel1_2
decl_stmt|;
name|QLineEdit
modifier|*
name|termsEdit
decl_stmt|;
name|QListWidget
modifier|*
name|resultBox
decl_stmt|;
name|QLabel
modifier|*
name|TextLabel2
decl_stmt|;
name|QHBoxLayout
modifier|*
name|hboxLayout1
decl_stmt|;
name|QPushButton
modifier|*
name|helpButton
decl_stmt|;
name|QSpacerItem
modifier|*
name|spacerItem2
decl_stmt|;
name|QPushButton
modifier|*
name|searchButton
decl_stmt|;
name|QFrame
modifier|*
name|framePrepare
decl_stmt|;
name|QHBoxLayout
modifier|*
name|hboxLayout2
decl_stmt|;
name|QLabel
modifier|*
name|labelPrepare
decl_stmt|;
name|QProgressBar
modifier|*
name|progressPrepare
decl_stmt|;
name|void
name|setupUi
parameter_list|(
name|QWidget
modifier|*
name|HelpDialog
parameter_list|)
block|{
if|if
condition|(
name|HelpDialog
operator|->
name|objectName
argument_list|()
operator|.
name|isEmpty
argument_list|()
condition|)
name|HelpDialog
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"HelpDialog"
argument_list|)
argument_list|)
expr_stmt|;
name|HelpDialog
operator|->
name|resize
argument_list|(
literal|274
argument_list|,
literal|417
argument_list|)
expr_stmt|;
name|vboxLayout
operator|=
name|new
name|QVBoxLayout
argument_list|(
name|HelpDialog
argument_list|)
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
name|tabWidget
operator|=
name|new
name|QTabWidget
argument_list|(
name|HelpDialog
argument_list|)
expr_stmt|;
name|tabWidget
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"tabWidget"
argument_list|)
argument_list|)
expr_stmt|;
name|contentPage
operator|=
name|new
name|QWidget
argument_list|()
expr_stmt|;
name|contentPage
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"contentPage"
argument_list|)
argument_list|)
expr_stmt|;
name|vboxLayout1
operator|=
name|new
name|QVBoxLayout
argument_list|(
name|contentPage
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
name|vboxLayout1
operator|->
name|setContentsMargins
argument_list|(
literal|5
argument_list|,
literal|5
argument_list|,
literal|5
argument_list|,
literal|5
argument_list|)
expr_stmt|;
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
name|listContents
operator|=
name|new
name|QTreeWidget
argument_list|(
name|contentPage
argument_list|)
expr_stmt|;
name|listContents
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"listContents"
argument_list|)
argument_list|)
expr_stmt|;
name|listContents
operator|->
name|setContextMenuPolicy
argument_list|(
name|Qt
operator|::
name|CustomContextMenu
argument_list|)
expr_stmt|;
name|listContents
operator|->
name|setRootIsDecorated
argument_list|(
name|true
argument_list|)
expr_stmt|;
name|listContents
operator|->
name|setUniformRowHeights
argument_list|(
name|true
argument_list|)
expr_stmt|;
name|vboxLayout1
operator|->
name|addWidget
argument_list|(
name|listContents
argument_list|)
expr_stmt|;
name|tabWidget
operator|->
name|addTab
argument_list|(
name|contentPage
argument_list|,
name|QString
argument_list|()
argument_list|)
expr_stmt|;
name|indexPage
operator|=
name|new
name|QWidget
argument_list|()
expr_stmt|;
name|indexPage
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"indexPage"
argument_list|)
argument_list|)
expr_stmt|;
name|vboxLayout2
operator|=
name|new
name|QVBoxLayout
argument_list|(
name|indexPage
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
name|vboxLayout2
operator|->
name|setContentsMargins
argument_list|(
literal|5
argument_list|,
literal|5
argument_list|,
literal|5
argument_list|,
literal|5
argument_list|)
expr_stmt|;
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
name|TextLabel1
operator|=
name|new
name|QLabel
argument_list|(
name|indexPage
argument_list|)
expr_stmt|;
name|TextLabel1
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"TextLabel1"
argument_list|)
argument_list|)
expr_stmt|;
name|vboxLayout2
operator|->
name|addWidget
argument_list|(
name|TextLabel1
argument_list|)
expr_stmt|;
name|editIndex
operator|=
name|new
name|QLineEdit
argument_list|(
name|indexPage
argument_list|)
expr_stmt|;
name|editIndex
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"editIndex"
argument_list|)
argument_list|)
expr_stmt|;
name|vboxLayout2
operator|->
name|addWidget
argument_list|(
name|editIndex
argument_list|)
expr_stmt|;
name|listIndex
operator|=
name|new
name|QListView
argument_list|(
name|indexPage
argument_list|)
expr_stmt|;
name|listIndex
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"listIndex"
argument_list|)
argument_list|)
expr_stmt|;
name|listIndex
operator|->
name|setContextMenuPolicy
argument_list|(
name|Qt
operator|::
name|CustomContextMenu
argument_list|)
expr_stmt|;
name|vboxLayout2
operator|->
name|addWidget
argument_list|(
name|listIndex
argument_list|)
expr_stmt|;
name|tabWidget
operator|->
name|addTab
argument_list|(
name|indexPage
argument_list|,
name|QString
argument_list|()
argument_list|)
expr_stmt|;
name|bookmarkPage
operator|=
name|new
name|QWidget
argument_list|()
expr_stmt|;
name|bookmarkPage
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"bookmarkPage"
argument_list|)
argument_list|)
expr_stmt|;
name|vboxLayout3
operator|=
name|new
name|QVBoxLayout
argument_list|(
name|bookmarkPage
argument_list|)
expr_stmt|;
ifndef|#
directive|ifndef
name|Q_OS_MAC
name|vboxLayout3
operator|->
name|setSpacing
argument_list|(
literal|6
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|vboxLayout3
operator|->
name|setContentsMargins
argument_list|(
literal|5
argument_list|,
literal|5
argument_list|,
literal|5
argument_list|,
literal|5
argument_list|)
expr_stmt|;
name|vboxLayout3
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"vboxLayout3"
argument_list|)
argument_list|)
expr_stmt|;
name|listBookmarks
operator|=
name|new
name|QTreeWidget
argument_list|(
name|bookmarkPage
argument_list|)
expr_stmt|;
name|listBookmarks
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"listBookmarks"
argument_list|)
argument_list|)
expr_stmt|;
name|listBookmarks
operator|->
name|setContextMenuPolicy
argument_list|(
name|Qt
operator|::
name|CustomContextMenu
argument_list|)
expr_stmt|;
name|listBookmarks
operator|->
name|setUniformRowHeights
argument_list|(
name|true
argument_list|)
expr_stmt|;
name|vboxLayout3
operator|->
name|addWidget
argument_list|(
name|listBookmarks
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
name|Expanding
argument_list|,
name|QSizePolicy
operator|::
name|Minimum
argument_list|)
expr_stmt|;
name|hboxLayout
operator|->
name|addItem
argument_list|(
name|spacerItem
argument_list|)
expr_stmt|;
name|buttonAdd
operator|=
name|new
name|QPushButton
argument_list|(
name|bookmarkPage
argument_list|)
expr_stmt|;
name|buttonAdd
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"buttonAdd"
argument_list|)
argument_list|)
expr_stmt|;
name|hboxLayout
operator|->
name|addWidget
argument_list|(
name|buttonAdd
argument_list|)
expr_stmt|;
name|buttonRemove
operator|=
name|new
name|QPushButton
argument_list|(
name|bookmarkPage
argument_list|)
expr_stmt|;
name|buttonRemove
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"buttonRemove"
argument_list|)
argument_list|)
expr_stmt|;
name|hboxLayout
operator|->
name|addWidget
argument_list|(
name|buttonRemove
argument_list|)
expr_stmt|;
name|vboxLayout3
operator|->
name|addLayout
argument_list|(
name|hboxLayout
argument_list|)
expr_stmt|;
name|tabWidget
operator|->
name|addTab
argument_list|(
name|bookmarkPage
argument_list|,
name|QString
argument_list|()
argument_list|)
expr_stmt|;
name|searchPage
operator|=
name|new
name|QWidget
argument_list|()
expr_stmt|;
name|searchPage
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"searchPage"
argument_list|)
argument_list|)
expr_stmt|;
name|gridLayout
operator|=
name|new
name|QGridLayout
argument_list|(
name|searchPage
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
name|gridLayout
operator|->
name|setContentsMargins
argument_list|(
literal|5
argument_list|,
literal|5
argument_list|,
literal|5
argument_list|,
literal|5
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
name|spacerItem1
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
name|Fixed
argument_list|)
expr_stmt|;
name|gridLayout
operator|->
name|addItem
argument_list|(
name|spacerItem1
argument_list|,
literal|3
argument_list|,
literal|0
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|TextLabel1_2
operator|=
name|new
name|QLabel
argument_list|(
name|searchPage
argument_list|)
expr_stmt|;
name|TextLabel1_2
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"TextLabel1_2"
argument_list|)
argument_list|)
expr_stmt|;
name|gridLayout
operator|->
name|addWidget
argument_list|(
name|TextLabel1_2
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
name|termsEdit
operator|=
name|new
name|QLineEdit
argument_list|(
name|searchPage
argument_list|)
expr_stmt|;
name|termsEdit
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"termsEdit"
argument_list|)
argument_list|)
expr_stmt|;
name|gridLayout
operator|->
name|addWidget
argument_list|(
name|termsEdit
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
name|resultBox
operator|=
name|new
name|QListWidget
argument_list|(
name|searchPage
argument_list|)
expr_stmt|;
name|resultBox
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"resultBox"
argument_list|)
argument_list|)
expr_stmt|;
name|resultBox
operator|->
name|setContextMenuPolicy
argument_list|(
name|Qt
operator|::
name|CustomContextMenu
argument_list|)
expr_stmt|;
name|gridLayout
operator|->
name|addWidget
argument_list|(
name|resultBox
argument_list|,
literal|5
argument_list|,
literal|0
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|TextLabel2
operator|=
name|new
name|QLabel
argument_list|(
name|searchPage
argument_list|)
expr_stmt|;
name|TextLabel2
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"TextLabel2"
argument_list|)
argument_list|)
expr_stmt|;
name|gridLayout
operator|->
name|addWidget
argument_list|(
name|TextLabel2
argument_list|,
literal|4
argument_list|,
literal|0
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|hboxLayout1
operator|=
name|new
name|QHBoxLayout
argument_list|()
expr_stmt|;
ifndef|#
directive|ifndef
name|Q_OS_MAC
name|hboxLayout1
operator|->
name|setSpacing
argument_list|(
literal|6
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|hboxLayout1
operator|->
name|setContentsMargins
argument_list|(
literal|1
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|hboxLayout1
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"hboxLayout1"
argument_list|)
argument_list|)
expr_stmt|;
name|helpButton
operator|=
name|new
name|QPushButton
argument_list|(
name|searchPage
argument_list|)
expr_stmt|;
name|helpButton
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"helpButton"
argument_list|)
argument_list|)
expr_stmt|;
name|hboxLayout1
operator|->
name|addWidget
argument_list|(
name|helpButton
argument_list|)
expr_stmt|;
name|spacerItem2
operator|=
name|new
name|QSpacerItem
argument_list|(
literal|61
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
name|hboxLayout1
operator|->
name|addItem
argument_list|(
name|spacerItem2
argument_list|)
expr_stmt|;
name|searchButton
operator|=
name|new
name|QPushButton
argument_list|(
name|searchPage
argument_list|)
expr_stmt|;
name|searchButton
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"searchButton"
argument_list|)
argument_list|)
expr_stmt|;
name|searchButton
operator|->
name|setEnabled
argument_list|(
name|false
argument_list|)
expr_stmt|;
name|hboxLayout1
operator|->
name|addWidget
argument_list|(
name|searchButton
argument_list|)
expr_stmt|;
name|gridLayout
operator|->
name|addLayout
argument_list|(
name|hboxLayout1
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
name|tabWidget
operator|->
name|addTab
argument_list|(
name|searchPage
argument_list|,
name|QString
argument_list|()
argument_list|)
expr_stmt|;
name|vboxLayout
operator|->
name|addWidget
argument_list|(
name|tabWidget
argument_list|)
expr_stmt|;
name|framePrepare
operator|=
name|new
name|QFrame
argument_list|(
name|HelpDialog
argument_list|)
expr_stmt|;
name|framePrepare
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"framePrepare"
argument_list|)
argument_list|)
expr_stmt|;
name|framePrepare
operator|->
name|setFrameShape
argument_list|(
name|QFrame
operator|::
name|StyledPanel
argument_list|)
expr_stmt|;
name|framePrepare
operator|->
name|setFrameShadow
argument_list|(
name|QFrame
operator|::
name|Raised
argument_list|)
expr_stmt|;
name|hboxLayout2
operator|=
name|new
name|QHBoxLayout
argument_list|(
name|framePrepare
argument_list|)
expr_stmt|;
ifndef|#
directive|ifndef
name|Q_OS_MAC
name|hboxLayout2
operator|->
name|setSpacing
argument_list|(
literal|6
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|hboxLayout2
operator|->
name|setContentsMargins
argument_list|(
literal|3
argument_list|,
literal|3
argument_list|,
literal|3
argument_list|,
literal|3
argument_list|)
expr_stmt|;
name|hboxLayout2
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"hboxLayout2"
argument_list|)
argument_list|)
expr_stmt|;
name|labelPrepare
operator|=
name|new
name|QLabel
argument_list|(
name|framePrepare
argument_list|)
expr_stmt|;
name|labelPrepare
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"labelPrepare"
argument_list|)
argument_list|)
expr_stmt|;
name|hboxLayout2
operator|->
name|addWidget
argument_list|(
name|labelPrepare
argument_list|)
expr_stmt|;
name|progressPrepare
operator|=
name|new
name|QProgressBar
argument_list|(
name|framePrepare
argument_list|)
expr_stmt|;
name|progressPrepare
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"progressPrepare"
argument_list|)
argument_list|)
expr_stmt|;
name|hboxLayout2
operator|->
name|addWidget
argument_list|(
name|progressPrepare
argument_list|)
expr_stmt|;
name|vboxLayout
operator|->
name|addWidget
argument_list|(
name|framePrepare
argument_list|)
expr_stmt|;
ifndef|#
directive|ifndef
name|QT_NO_SHORTCUT
name|TextLabel1
operator|->
name|setBuddy
argument_list|(
name|editIndex
argument_list|)
expr_stmt|;
name|TextLabel1_2
operator|->
name|setBuddy
argument_list|(
name|termsEdit
argument_list|)
expr_stmt|;
name|TextLabel2
operator|->
name|setBuddy
argument_list|(
name|resultBox
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|// QT_NO_SHORTCUT
name|QWidget
operator|::
name|setTabOrder
argument_list|(
name|tabWidget
argument_list|,
name|listContents
argument_list|)
expr_stmt|;
name|QWidget
operator|::
name|setTabOrder
argument_list|(
name|listContents
argument_list|,
name|editIndex
argument_list|)
expr_stmt|;
name|QWidget
operator|::
name|setTabOrder
argument_list|(
name|editIndex
argument_list|,
name|listIndex
argument_list|)
expr_stmt|;
name|QWidget
operator|::
name|setTabOrder
argument_list|(
name|listIndex
argument_list|,
name|listBookmarks
argument_list|)
expr_stmt|;
name|QWidget
operator|::
name|setTabOrder
argument_list|(
name|listBookmarks
argument_list|,
name|buttonAdd
argument_list|)
expr_stmt|;
name|QWidget
operator|::
name|setTabOrder
argument_list|(
name|buttonAdd
argument_list|,
name|buttonRemove
argument_list|)
expr_stmt|;
name|QWidget
operator|::
name|setTabOrder
argument_list|(
name|buttonRemove
argument_list|,
name|termsEdit
argument_list|)
expr_stmt|;
name|QWidget
operator|::
name|setTabOrder
argument_list|(
name|termsEdit
argument_list|,
name|searchButton
argument_list|)
expr_stmt|;
name|QWidget
operator|::
name|setTabOrder
argument_list|(
name|searchButton
argument_list|,
name|helpButton
argument_list|)
expr_stmt|;
name|QWidget
operator|::
name|setTabOrder
argument_list|(
name|helpButton
argument_list|,
name|resultBox
argument_list|)
expr_stmt|;
name|retranslateUi
argument_list|(
name|HelpDialog
argument_list|)
expr_stmt|;
name|QMetaObject
operator|::
name|connectSlotsByName
argument_list|(
name|HelpDialog
argument_list|)
expr_stmt|;
block|}
comment|// setupUi
name|void
name|retranslateUi
parameter_list|(
name|QWidget
modifier|*
name|HelpDialog
parameter_list|)
block|{
name|HelpDialog
operator|->
name|setWindowTitle
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"HelpDialog"
argument_list|,
literal|"Help"
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
ifndef|#
directive|ifndef
name|QT_NO_WHATSTHIS
name|HelpDialog
operator|->
name|setWhatsThis
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"HelpDialog"
argument_list|,
literal|"<b>Help</b><p>Choose the topic you want help on from the contents list, or search the index for keywords.</p>"
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|// QT_NO_WHATSTHIS
ifndef|#
directive|ifndef
name|QT_NO_WHATSTHIS
name|tabWidget
operator|->
name|setWhatsThis
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"HelpDialog"
argument_list|,
literal|"Displays help topics organized by category, index or bookmarks. Another tab inherits the full text search."
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|// QT_NO_WHATSTHIS
name|QTreeWidgetItem
modifier|*
name|___qtreewidgetitem
init|=
name|listContents
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
literal|"HelpDialog"
argument_list|,
literal|"column 1"
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
ifndef|#
directive|ifndef
name|QT_NO_WHATSTHIS
name|listContents
operator|->
name|setWhatsThis
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"HelpDialog"
argument_list|,
literal|"<b>Help topics organized by category.</b><p>Double-click an item to see the topics in that category. To view a topic, just double-click it.</p>"
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|// QT_NO_WHATSTHIS
name|tabWidget
operator|->
name|setTabText
argument_list|(
name|tabWidget
operator|->
name|indexOf
argument_list|(
name|contentPage
argument_list|)
argument_list|,
name|QApplication
operator|::
name|translate
argument_list|(
literal|"HelpDialog"
argument_list|,
literal|"Con&tents"
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
name|TextLabel1
operator|->
name|setText
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"HelpDialog"
argument_list|,
literal|"&Look For:"
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
ifndef|#
directive|ifndef
name|QT_NO_TOOLTIP
name|editIndex
operator|->
name|setToolTip
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"HelpDialog"
argument_list|,
literal|"Enter keyword"
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
name|QT_NO_WHATSTHIS
name|editIndex
operator|->
name|setWhatsThis
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"HelpDialog"
argument_list|,
literal|"<b>Enter a keyword.</b><p>The list will select an item that matches the entered string best.</p>"
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|// QT_NO_WHATSTHIS
ifndef|#
directive|ifndef
name|QT_NO_WHATSTHIS
name|listIndex
operator|->
name|setWhatsThis
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"HelpDialog"
argument_list|,
literal|"<b>List of available help topics.</b><p>Double-click on an item to open its help page. If more than one is found, you must specify which page you want.</p>"
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|// QT_NO_WHATSTHIS
name|tabWidget
operator|->
name|setTabText
argument_list|(
name|tabWidget
operator|->
name|indexOf
argument_list|(
name|indexPage
argument_list|)
argument_list|,
name|QApplication
operator|::
name|translate
argument_list|(
literal|"HelpDialog"
argument_list|,
literal|"&Index"
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
name|QTreeWidgetItem
modifier|*
name|___qtreewidgetitem1
init|=
name|listBookmarks
operator|->
name|headerItem
argument_list|()
decl_stmt|;
name|___qtreewidgetitem1
operator|->
name|setText
argument_list|(
literal|0
argument_list|,
name|QApplication
operator|::
name|translate
argument_list|(
literal|"HelpDialog"
argument_list|,
literal|"column 1"
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
ifndef|#
directive|ifndef
name|QT_NO_WHATSTHIS
name|listBookmarks
operator|->
name|setWhatsThis
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"HelpDialog"
argument_list|,
literal|"Displays the list of bookmarks."
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|// QT_NO_WHATSTHIS
ifndef|#
directive|ifndef
name|QT_NO_TOOLTIP
name|buttonAdd
operator|->
name|setToolTip
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"HelpDialog"
argument_list|,
literal|"Add new bookmark"
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
name|QT_NO_WHATSTHIS
name|buttonAdd
operator|->
name|setWhatsThis
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"HelpDialog"
argument_list|,
literal|"Add the currently displayed page as a new bookmark."
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|// QT_NO_WHATSTHIS
name|buttonAdd
operator|->
name|setText
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"HelpDialog"
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
name|buttonRemove
operator|->
name|setToolTip
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"HelpDialog"
argument_list|,
literal|"Delete bookmark"
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
name|QT_NO_WHATSTHIS
name|buttonRemove
operator|->
name|setWhatsThis
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"HelpDialog"
argument_list|,
literal|"Delete the selected bookmark."
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|// QT_NO_WHATSTHIS
name|buttonRemove
operator|->
name|setText
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"HelpDialog"
argument_list|,
literal|"&Delete"
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
name|tabWidget
operator|->
name|setTabText
argument_list|(
name|tabWidget
operator|->
name|indexOf
argument_list|(
name|bookmarkPage
argument_list|)
argument_list|,
name|QApplication
operator|::
name|translate
argument_list|(
literal|"HelpDialog"
argument_list|,
literal|"&Bookmarks"
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
name|TextLabel1_2
operator|->
name|setText
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"HelpDialog"
argument_list|,
literal|"Searching f&or:"
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
ifndef|#
directive|ifndef
name|QT_NO_TOOLTIP
name|termsEdit
operator|->
name|setToolTip
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"HelpDialog"
argument_list|,
literal|"Enter searchword(s)."
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
name|QT_NO_WHATSTHIS
name|termsEdit
operator|->
name|setWhatsThis
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"HelpDialog"
argument_list|,
literal|"<b>Enter search word(s).</b><p>Enter here the word(s) you are looking for. The words may contain wildcards (*). For a sequence of words quote them.</p>"
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|// QT_NO_WHATSTHIS
ifndef|#
directive|ifndef
name|QT_NO_WHATSTHIS
name|resultBox
operator|->
name|setWhatsThis
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"HelpDialog"
argument_list|,
literal|"<b>Found documents</b><p>This list contains all found documents from the last search. The documents are ordered, i.e. the first document has the most matches.</p>"
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|// QT_NO_WHATSTHIS
name|TextLabel2
operator|->
name|setText
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"HelpDialog"
argument_list|,
literal|"Found&Documents:"
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
ifndef|#
directive|ifndef
name|QT_NO_TOOLTIP
name|helpButton
operator|->
name|setToolTip
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"HelpDialog"
argument_list|,
literal|"Display the help page."
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
name|QT_NO_WHATSTHIS
name|helpButton
operator|->
name|setWhatsThis
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"HelpDialog"
argument_list|,
literal|"Display the help page for the full text search."
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|// QT_NO_WHATSTHIS
name|helpButton
operator|->
name|setText
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"HelpDialog"
argument_list|,
literal|"He&lp"
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
ifndef|#
directive|ifndef
name|QT_NO_TOOLTIP
name|searchButton
operator|->
name|setToolTip
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"HelpDialog"
argument_list|,
literal|"Start searching."
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
name|QT_NO_WHATSTHIS
name|searchButton
operator|->
name|setWhatsThis
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"HelpDialog"
argument_list|,
literal|"Pressing this button starts the search."
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|// QT_NO_WHATSTHIS
name|searchButton
operator|->
name|setText
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"HelpDialog"
argument_list|,
literal|"&Search"
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
name|tabWidget
operator|->
name|setTabText
argument_list|(
name|tabWidget
operator|->
name|indexOf
argument_list|(
name|searchPage
argument_list|)
argument_list|,
name|QApplication
operator|::
name|translate
argument_list|(
literal|"HelpDialog"
argument_list|,
literal|"&Search"
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
name|labelPrepare
operator|->
name|setText
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"HelpDialog"
argument_list|,
literal|"Preparing..."
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
block|}
comment|// retranslateUi
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_decl_stmt
name|namespace
name|Ui
block|{
name|class
name|HelpDialog
range|:
name|public
name|Ui_HelpDialog
block|{}
decl_stmt|;
block|}
end_decl_stmt
begin_comment
comment|// namespace Ui
end_comment
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// HELPDIALOG_H
end_comment
end_unit
