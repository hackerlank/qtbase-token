begin_unit
begin_comment
comment|/******************************************************************************** ** Form generated from reading UI file 'filterpage.ui' ** ** Created: Fri Sep 4 10:17:13 2009 **      by: Qt User Interface Compiler version 4.6.0 ** ** WARNING! All changes made in this file will be lost when recompiling UI file! ********************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|FILTERPAGE_H
end_ifndef
begin_define
DECL|macro|FILTERPAGE_H
define|#
directive|define
name|FILTERPAGE_H
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
file|<QtWidgets/QTreeWidget>
end_include
begin_include
include|#
directive|include
file|<QtWidgets/QWidget>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
name|class
name|Ui_FilterPage
block|{
name|public
label|:
name|QGridLayout
modifier|*
name|gridLayout
decl_stmt|;
name|QLabel
modifier|*
name|label
decl_stmt|;
name|QLineEdit
modifier|*
name|filterLineEdit
decl_stmt|;
name|QGroupBox
modifier|*
name|groupBox
decl_stmt|;
name|QGridLayout
modifier|*
name|gridLayout1
decl_stmt|;
name|QTreeWidget
modifier|*
name|customFilterWidget
decl_stmt|;
name|QPushButton
modifier|*
name|addButton
decl_stmt|;
name|QPushButton
modifier|*
name|removeButton
decl_stmt|;
name|QSpacerItem
modifier|*
name|spacerItem
decl_stmt|;
name|QSpacerItem
modifier|*
name|spacerItem1
decl_stmt|;
name|QSpacerItem
modifier|*
name|spacerItem2
decl_stmt|;
name|QSpacerItem
modifier|*
name|spacerItem3
decl_stmt|;
name|void
name|setupUi
parameter_list|(
name|QWidget
modifier|*
name|FilterPage
parameter_list|)
block|{
if|if
condition|(
name|FilterPage
operator|->
name|objectName
argument_list|()
operator|.
name|isEmpty
argument_list|()
condition|)
name|FilterPage
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"FilterPage"
argument_list|)
argument_list|)
expr_stmt|;
name|FilterPage
operator|->
name|resize
argument_list|(
literal|419
argument_list|,
literal|243
argument_list|)
expr_stmt|;
name|gridLayout
operator|=
name|new
name|QGridLayout
argument_list|(
name|FilterPage
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
name|label
operator|=
name|new
name|QLabel
argument_list|(
name|FilterPage
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
name|gridLayout
operator|->
name|addWidget
argument_list|(
name|label
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
name|filterLineEdit
operator|=
name|new
name|QLineEdit
argument_list|(
name|FilterPage
argument_list|)
expr_stmt|;
name|filterLineEdit
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"filterLineEdit"
argument_list|)
argument_list|)
expr_stmt|;
name|gridLayout
operator|->
name|addWidget
argument_list|(
name|filterLineEdit
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
name|groupBox
operator|=
name|new
name|QGroupBox
argument_list|(
name|FilterPage
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
name|gridLayout1
operator|=
name|new
name|QGridLayout
argument_list|(
name|groupBox
argument_list|)
expr_stmt|;
name|gridLayout1
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"gridLayout1"
argument_list|)
argument_list|)
expr_stmt|;
name|customFilterWidget
operator|=
name|new
name|QTreeWidget
argument_list|(
name|groupBox
argument_list|)
expr_stmt|;
name|customFilterWidget
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"customFilterWidget"
argument_list|)
argument_list|)
expr_stmt|;
name|customFilterWidget
operator|->
name|setColumnCount
argument_list|(
literal|2
argument_list|)
expr_stmt|;
name|gridLayout1
operator|->
name|addWidget
argument_list|(
name|customFilterWidget
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|3
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|addButton
operator|=
name|new
name|QPushButton
argument_list|(
name|groupBox
argument_list|)
expr_stmt|;
name|addButton
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"addButton"
argument_list|)
argument_list|)
expr_stmt|;
name|gridLayout1
operator|->
name|addWidget
argument_list|(
name|addButton
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
name|removeButton
operator|=
name|new
name|QPushButton
argument_list|(
name|groupBox
argument_list|)
expr_stmt|;
name|removeButton
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"removeButton"
argument_list|)
argument_list|)
expr_stmt|;
name|gridLayout1
operator|->
name|addWidget
argument_list|(
name|removeButton
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|,
literal|1
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
literal|40
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
name|gridLayout1
operator|->
name|addItem
argument_list|(
name|spacerItem
argument_list|,
literal|2
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|gridLayout
operator|->
name|addWidget
argument_list|(
name|groupBox
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
name|spacerItem1
operator|=
name|new
name|QSpacerItem
argument_list|(
literal|20
argument_list|,
literal|40
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
name|spacerItem1
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
name|spacerItem2
operator|=
name|new
name|QSpacerItem
argument_list|(
literal|20
argument_list|,
literal|40
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
name|spacerItem2
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
name|spacerItem3
operator|=
name|new
name|QSpacerItem
argument_list|(
literal|20
argument_list|,
literal|10
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
name|spacerItem3
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
name|retranslateUi
argument_list|(
name|FilterPage
argument_list|)
expr_stmt|;
name|QMetaObject
operator|::
name|connectSlotsByName
argument_list|(
name|FilterPage
argument_list|)
expr_stmt|;
block|}
comment|// setupUi
name|void
name|retranslateUi
parameter_list|(
name|QWidget
modifier|*
name|FilterPage
parameter_list|)
block|{
name|FilterPage
operator|->
name|setWindowTitle
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"FilterPage"
argument_list|,
literal|"Form"
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
literal|"FilterPage"
argument_list|,
literal|"Filter attributes for current documentation (comma separated list):"
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
name|groupBox
operator|->
name|setTitle
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"FilterPage"
argument_list|,
literal|"Custom Filters"
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
name|QTreeWidgetItem
modifier|*
name|___qtreewidgetitem
init|=
name|customFilterWidget
operator|->
name|headerItem
argument_list|()
decl_stmt|;
name|___qtreewidgetitem
operator|->
name|setText
argument_list|(
literal|1
argument_list|,
name|QApplication
operator|::
name|translate
argument_list|(
literal|"FilterPage"
argument_list|,
literal|"2"
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
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
literal|"FilterPage"
argument_list|,
literal|"1"
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
name|addButton
operator|->
name|setText
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"FilterPage"
argument_list|,
literal|"Add"
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
name|removeButton
operator|->
name|setText
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"FilterPage"
argument_list|,
literal|"Remove"
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
name|FilterPage
range|:
name|public
name|Ui_FilterPage
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
comment|// FILTERPAGE_H
end_comment
end_unit
