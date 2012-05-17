begin_unit
begin_comment
comment|/******************************************************************************** ** Form generated from reading UI file 'browserwidget.ui' ** ** Created: Fri Sep 4 10:17:12 2009 **      by: Qt User Interface Compiler version 4.6.0 ** ** WARNING! All changes made in this file will be lost when recompiling UI file! ********************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|BROWSERWIDGET_H
end_ifndef
begin_define
DECL|macro|BROWSERWIDGET_H
define|#
directive|define
name|BROWSERWIDGET_H
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
file|<QtWidgets/QSplitter>
end_include
begin_include
include|#
directive|include
file|<QtWidgets/QTableView>
end_include
begin_include
include|#
directive|include
file|<QtWidgets/QTextEdit>
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
file|"connectionwidget.h"
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
name|class
name|Ui_Browser
block|{
name|public
label|:
name|QAction
modifier|*
name|insertRowAction
decl_stmt|;
name|QAction
modifier|*
name|deleteRowAction
decl_stmt|;
name|QVBoxLayout
modifier|*
name|vboxLayout
decl_stmt|;
name|QSplitter
modifier|*
name|splitter_2
decl_stmt|;
name|ConnectionWidget
modifier|*
name|connectionWidget
decl_stmt|;
name|QTableView
modifier|*
name|table
decl_stmt|;
name|QGroupBox
modifier|*
name|groupBox
decl_stmt|;
name|QVBoxLayout
modifier|*
name|vboxLayout1
decl_stmt|;
name|QTextEdit
modifier|*
name|sqlEdit
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
name|clearButton
decl_stmt|;
name|QPushButton
modifier|*
name|submitButton
decl_stmt|;
name|void
name|setupUi
parameter_list|(
name|QWidget
modifier|*
name|Browser
parameter_list|)
block|{
if|if
condition|(
name|Browser
operator|->
name|objectName
argument_list|()
operator|.
name|isEmpty
argument_list|()
condition|)
name|Browser
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"Browser"
argument_list|)
argument_list|)
expr_stmt|;
name|Browser
operator|->
name|resize
argument_list|(
literal|765
argument_list|,
literal|515
argument_list|)
expr_stmt|;
name|insertRowAction
operator|=
name|new
name|QAction
argument_list|(
name|Browser
argument_list|)
expr_stmt|;
name|insertRowAction
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"insertRowAction"
argument_list|)
argument_list|)
expr_stmt|;
name|insertRowAction
operator|->
name|setEnabled
argument_list|(
name|false
argument_list|)
expr_stmt|;
name|deleteRowAction
operator|=
name|new
name|QAction
argument_list|(
name|Browser
argument_list|)
expr_stmt|;
name|deleteRowAction
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"deleteRowAction"
argument_list|)
argument_list|)
expr_stmt|;
name|deleteRowAction
operator|->
name|setEnabled
argument_list|(
name|false
argument_list|)
expr_stmt|;
name|vboxLayout
operator|=
name|new
name|QVBoxLayout
argument_list|(
name|Browser
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
literal|8
argument_list|,
literal|8
argument_list|,
literal|8
argument_list|,
literal|8
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
name|splitter_2
operator|=
name|new
name|QSplitter
argument_list|(
name|Browser
argument_list|)
expr_stmt|;
name|splitter_2
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"splitter_2"
argument_list|)
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
literal|7
operator|)
argument_list|,
name|static_cast
operator|<
name|QSizePolicy
operator|::
name|Policy
operator|>
operator|(
literal|7
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
name|splitter_2
operator|->
name|sizePolicy
argument_list|()
operator|.
name|hasHeightForWidth
argument_list|()
argument_list|)
expr_stmt|;
name|splitter_2
operator|->
name|setSizePolicy
argument_list|(
name|sizePolicy
argument_list|)
expr_stmt|;
name|splitter_2
operator|->
name|setOrientation
argument_list|(
name|Qt
operator|::
name|Horizontal
argument_list|)
expr_stmt|;
name|connectionWidget
operator|=
name|new
name|ConnectionWidget
argument_list|(
name|splitter_2
argument_list|)
expr_stmt|;
name|connectionWidget
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"connectionWidget"
argument_list|)
argument_list|)
expr_stmt|;
name|QSizePolicy
name|sizePolicy1
argument_list|(
name|static_cast
operator|<
name|QSizePolicy
operator|::
name|Policy
operator|>
operator|(
literal|13
operator|)
argument_list|,
name|static_cast
operator|<
name|QSizePolicy
operator|::
name|Policy
operator|>
operator|(
literal|7
operator|)
argument_list|)
decl_stmt|;
name|sizePolicy1
operator|.
name|setHorizontalStretch
argument_list|(
literal|1
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
name|connectionWidget
operator|->
name|sizePolicy
argument_list|()
operator|.
name|hasHeightForWidth
argument_list|()
argument_list|)
expr_stmt|;
name|connectionWidget
operator|->
name|setSizePolicy
argument_list|(
name|sizePolicy1
argument_list|)
expr_stmt|;
name|splitter_2
operator|->
name|addWidget
argument_list|(
name|connectionWidget
argument_list|)
expr_stmt|;
name|table
operator|=
name|new
name|QTableView
argument_list|(
name|splitter_2
argument_list|)
expr_stmt|;
name|table
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"table"
argument_list|)
argument_list|)
expr_stmt|;
name|QSizePolicy
name|sizePolicy2
argument_list|(
name|static_cast
operator|<
name|QSizePolicy
operator|::
name|Policy
operator|>
operator|(
literal|7
operator|)
argument_list|,
name|static_cast
operator|<
name|QSizePolicy
operator|::
name|Policy
operator|>
operator|(
literal|7
operator|)
argument_list|)
decl_stmt|;
name|sizePolicy2
operator|.
name|setHorizontalStretch
argument_list|(
literal|2
argument_list|)
expr_stmt|;
name|sizePolicy2
operator|.
name|setVerticalStretch
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|sizePolicy2
operator|.
name|setHeightForWidth
argument_list|(
name|table
operator|->
name|sizePolicy
argument_list|()
operator|.
name|hasHeightForWidth
argument_list|()
argument_list|)
expr_stmt|;
name|table
operator|->
name|setSizePolicy
argument_list|(
name|sizePolicy2
argument_list|)
expr_stmt|;
name|table
operator|->
name|setContextMenuPolicy
argument_list|(
name|Qt
operator|::
name|ActionsContextMenu
argument_list|)
expr_stmt|;
name|table
operator|->
name|setSelectionBehavior
argument_list|(
name|QAbstractItemView
operator|::
name|SelectRows
argument_list|)
expr_stmt|;
name|splitter_2
operator|->
name|addWidget
argument_list|(
name|table
argument_list|)
expr_stmt|;
name|vboxLayout
operator|->
name|addWidget
argument_list|(
name|splitter_2
argument_list|)
expr_stmt|;
name|groupBox
operator|=
name|new
name|QGroupBox
argument_list|(
name|Browser
argument_list|)
expr_stmt|;
name|groupBox
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"groupBox"
argument_list|)
argument_list|)
expr_stmt|;
name|QSizePolicy
name|sizePolicy3
argument_list|(
name|static_cast
operator|<
name|QSizePolicy
operator|::
name|Policy
operator|>
operator|(
literal|5
operator|)
argument_list|,
name|static_cast
operator|<
name|QSizePolicy
operator|::
name|Policy
operator|>
operator|(
literal|3
operator|)
argument_list|)
decl_stmt|;
name|sizePolicy3
operator|.
name|setHorizontalStretch
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|sizePolicy3
operator|.
name|setVerticalStretch
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|sizePolicy3
operator|.
name|setHeightForWidth
argument_list|(
name|groupBox
operator|->
name|sizePolicy
argument_list|()
operator|.
name|hasHeightForWidth
argument_list|()
argument_list|)
expr_stmt|;
name|groupBox
operator|->
name|setSizePolicy
argument_list|(
name|sizePolicy3
argument_list|)
expr_stmt|;
name|groupBox
operator|->
name|setMaximumSize
argument_list|(
name|QSize
argument_list|(
literal|16777215
argument_list|,
literal|180
argument_list|)
argument_list|)
expr_stmt|;
name|vboxLayout1
operator|=
name|new
name|QVBoxLayout
argument_list|(
name|groupBox
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
name|sqlEdit
operator|=
name|new
name|QTextEdit
argument_list|(
name|groupBox
argument_list|)
expr_stmt|;
name|sqlEdit
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"sqlEdit"
argument_list|)
argument_list|)
expr_stmt|;
name|QSizePolicy
name|sizePolicy4
argument_list|(
name|static_cast
operator|<
name|QSizePolicy
operator|::
name|Policy
operator|>
operator|(
literal|7
operator|)
argument_list|,
name|static_cast
operator|<
name|QSizePolicy
operator|::
name|Policy
operator|>
operator|(
literal|3
operator|)
argument_list|)
decl_stmt|;
name|sizePolicy4
operator|.
name|setHorizontalStretch
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|sizePolicy4
operator|.
name|setVerticalStretch
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|sizePolicy4
operator|.
name|setHeightForWidth
argument_list|(
name|sqlEdit
operator|->
name|sizePolicy
argument_list|()
operator|.
name|hasHeightForWidth
argument_list|()
argument_list|)
expr_stmt|;
name|sqlEdit
operator|->
name|setSizePolicy
argument_list|(
name|sizePolicy4
argument_list|)
expr_stmt|;
name|sqlEdit
operator|->
name|setMinimumSize
argument_list|(
name|QSize
argument_list|(
literal|0
argument_list|,
literal|18
argument_list|)
argument_list|)
expr_stmt|;
name|sqlEdit
operator|->
name|setBaseSize
argument_list|(
name|QSize
argument_list|(
literal|0
argument_list|,
literal|120
argument_list|)
argument_list|)
expr_stmt|;
name|vboxLayout1
operator|->
name|addWidget
argument_list|(
name|sqlEdit
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
literal|1
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|,
literal|1
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
name|hboxLayout
operator|->
name|addItem
argument_list|(
name|spacerItem
argument_list|)
expr_stmt|;
name|clearButton
operator|=
name|new
name|QPushButton
argument_list|(
name|groupBox
argument_list|)
expr_stmt|;
name|clearButton
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"clearButton"
argument_list|)
argument_list|)
expr_stmt|;
name|hboxLayout
operator|->
name|addWidget
argument_list|(
name|clearButton
argument_list|)
expr_stmt|;
name|submitButton
operator|=
name|new
name|QPushButton
argument_list|(
name|groupBox
argument_list|)
expr_stmt|;
name|submitButton
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"submitButton"
argument_list|)
argument_list|)
expr_stmt|;
name|hboxLayout
operator|->
name|addWidget
argument_list|(
name|submitButton
argument_list|)
expr_stmt|;
name|vboxLayout1
operator|->
name|addLayout
argument_list|(
name|hboxLayout
argument_list|)
expr_stmt|;
name|vboxLayout
operator|->
name|addWidget
argument_list|(
name|groupBox
argument_list|)
expr_stmt|;
name|QWidget
operator|::
name|setTabOrder
argument_list|(
name|sqlEdit
argument_list|,
name|clearButton
argument_list|)
expr_stmt|;
name|QWidget
operator|::
name|setTabOrder
argument_list|(
name|clearButton
argument_list|,
name|submitButton
argument_list|)
expr_stmt|;
name|QWidget
operator|::
name|setTabOrder
argument_list|(
name|submitButton
argument_list|,
name|connectionWidget
argument_list|)
expr_stmt|;
name|QWidget
operator|::
name|setTabOrder
argument_list|(
name|connectionWidget
argument_list|,
name|table
argument_list|)
expr_stmt|;
name|retranslateUi
argument_list|(
name|Browser
argument_list|)
expr_stmt|;
name|QMetaObject
operator|::
name|connectSlotsByName
argument_list|(
name|Browser
argument_list|)
expr_stmt|;
block|}
comment|// setupUi
name|void
name|retranslateUi
parameter_list|(
name|QWidget
modifier|*
name|Browser
parameter_list|)
block|{
name|Browser
operator|->
name|setWindowTitle
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"Browser"
argument_list|,
literal|"Qt SQL Browser"
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
name|insertRowAction
operator|->
name|setText
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"Browser"
argument_list|,
literal|"&Insert Row"
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
ifndef|#
directive|ifndef
name|QT_NO_STATUSTIP
name|insertRowAction
operator|->
name|setStatusTip
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"Browser"
argument_list|,
literal|"Inserts a new Row"
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|// QT_NO_STATUSTIP
name|deleteRowAction
operator|->
name|setText
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"Browser"
argument_list|,
literal|"&Delete Row"
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
ifndef|#
directive|ifndef
name|QT_NO_STATUSTIP
name|deleteRowAction
operator|->
name|setStatusTip
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"Browser"
argument_list|,
literal|"Deletes the current Row"
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|// QT_NO_STATUSTIP
name|groupBox
operator|->
name|setTitle
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"Browser"
argument_list|,
literal|"SQL Query"
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
name|clearButton
operator|->
name|setText
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"Browser"
argument_list|,
literal|"&Clear"
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
name|submitButton
operator|->
name|setText
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"Browser"
argument_list|,
literal|"&Submit"
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
name|Browser
range|:
name|public
name|Ui_Browser
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
comment|// BROWSERWIDGET_H
end_comment
end_unit
