begin_unit
begin_comment
comment|/******************************************************************************** ** Form generated from reading UI file 'newdynamicpropertydialog.ui' ** ** Created: Fri Sep 4 10:17:14 2009 **      by: Qt User Interface Compiler version 4.6.0 ** ** WARNING! All changes made in this file will be lost when recompiling UI file! ********************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|NEWDYNAMICPROPERTYDIALOG_H
end_ifndef
begin_define
DECL|macro|NEWDYNAMICPROPERTYDIALOG_H
define|#
directive|define
name|NEWDYNAMICPROPERTYDIALOG_H
end_define
begin_include
include|#
directive|include
file|<QtCore/QVariant>
end_include
begin_include
include|#
directive|include
file|<QtGui/QAction>
end_include
begin_include
include|#
directive|include
file|<QtGui/QApplication>
end_include
begin_include
include|#
directive|include
file|<QtGui/QButtonGroup>
end_include
begin_include
include|#
directive|include
file|<QtGui/QComboBox>
end_include
begin_include
include|#
directive|include
file|<QtGui/QDialog>
end_include
begin_include
include|#
directive|include
file|<QtGui/QDialogButtonBox>
end_include
begin_include
include|#
directive|include
file|<QtGui/QFormLayout>
end_include
begin_include
include|#
directive|include
file|<QtGui/QHBoxLayout>
end_include
begin_include
include|#
directive|include
file|<QtGui/QHeaderView>
end_include
begin_include
include|#
directive|include
file|<QtGui/QLabel>
end_include
begin_include
include|#
directive|include
file|<QtGui/QLineEdit>
end_include
begin_include
include|#
directive|include
file|<QtGui/QSpacerItem>
end_include
begin_include
include|#
directive|include
file|<QtGui/QVBoxLayout>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
name|namespace
name|qdesigner_internal
block|{
name|class
name|Ui_NewDynamicPropertyDialog
block|{
name|public
label|:
name|QVBoxLayout
modifier|*
name|verticalLayout
decl_stmt|;
name|QFormLayout
modifier|*
name|formLayout
decl_stmt|;
name|QLineEdit
modifier|*
name|m_lineEdit
decl_stmt|;
name|QLabel
modifier|*
name|label
decl_stmt|;
name|QHBoxLayout
modifier|*
name|horizontalLayout
decl_stmt|;
name|QComboBox
modifier|*
name|m_comboBox
decl_stmt|;
name|QSpacerItem
modifier|*
name|horizontalSpacer
decl_stmt|;
name|QLabel
modifier|*
name|label_2
decl_stmt|;
name|QSpacerItem
modifier|*
name|spacerItem
decl_stmt|;
name|QDialogButtonBox
modifier|*
name|m_buttonBox
decl_stmt|;
name|void
name|setupUi
parameter_list|(
name|QDialog
modifier|*
name|qdesigner_internal__NewDynamicPropertyDialog
parameter_list|)
block|{
if|if
condition|(
name|qdesigner_internal__NewDynamicPropertyDialog
operator|->
name|objectName
argument_list|()
operator|.
name|isEmpty
argument_list|()
condition|)
name|qdesigner_internal__NewDynamicPropertyDialog
operator|->
name|setObjectName
argument_list|(
name|QString
operator|::
name|fromUtf8
argument_list|(
literal|"qdesigner_internal__NewDynamicPropertyDialog"
argument_list|)
argument_list|)
expr_stmt|;
name|qdesigner_internal__NewDynamicPropertyDialog
operator|->
name|resize
argument_list|(
literal|340
argument_list|,
literal|118
argument_list|)
expr_stmt|;
name|verticalLayout
operator|=
name|new
name|QVBoxLayout
argument_list|(
name|qdesigner_internal__NewDynamicPropertyDialog
argument_list|)
expr_stmt|;
name|verticalLayout
operator|->
name|setObjectName
argument_list|(
name|QString
operator|::
name|fromUtf8
argument_list|(
literal|"verticalLayout"
argument_list|)
argument_list|)
expr_stmt|;
name|formLayout
operator|=
name|new
name|QFormLayout
argument_list|()
expr_stmt|;
name|formLayout
operator|->
name|setObjectName
argument_list|(
name|QString
operator|::
name|fromUtf8
argument_list|(
literal|"formLayout"
argument_list|)
argument_list|)
expr_stmt|;
name|m_lineEdit
operator|=
name|new
name|QLineEdit
argument_list|(
name|qdesigner_internal__NewDynamicPropertyDialog
argument_list|)
expr_stmt|;
name|m_lineEdit
operator|->
name|setObjectName
argument_list|(
name|QString
operator|::
name|fromUtf8
argument_list|(
literal|"m_lineEdit"
argument_list|)
argument_list|)
expr_stmt|;
name|m_lineEdit
operator|->
name|setMinimumSize
argument_list|(
name|QSize
argument_list|(
literal|220
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
name|formLayout
operator|->
name|setWidget
argument_list|(
literal|0
argument_list|,
name|QFormLayout
operator|::
name|FieldRole
argument_list|,
name|m_lineEdit
argument_list|)
expr_stmt|;
name|label
operator|=
name|new
name|QLabel
argument_list|(
name|qdesigner_internal__NewDynamicPropertyDialog
argument_list|)
expr_stmt|;
name|label
operator|->
name|setObjectName
argument_list|(
name|QString
operator|::
name|fromUtf8
argument_list|(
literal|"label"
argument_list|)
argument_list|)
expr_stmt|;
name|QSizePolicy
name|sizePolicy
argument_list|(
name|QSizePolicy
operator|::
name|Preferred
argument_list|,
name|QSizePolicy
operator|::
name|Fixed
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
name|label
operator|->
name|sizePolicy
argument_list|()
operator|.
name|hasHeightForWidth
argument_list|()
argument_list|)
expr_stmt|;
name|label
operator|->
name|setSizePolicy
argument_list|(
name|sizePolicy
argument_list|)
expr_stmt|;
name|formLayout
operator|->
name|setWidget
argument_list|(
literal|0
argument_list|,
name|QFormLayout
operator|::
name|LabelRole
argument_list|,
name|label
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
name|QString
operator|::
name|fromUtf8
argument_list|(
literal|"horizontalLayout"
argument_list|)
argument_list|)
expr_stmt|;
name|m_comboBox
operator|=
name|new
name|QComboBox
argument_list|(
name|qdesigner_internal__NewDynamicPropertyDialog
argument_list|)
expr_stmt|;
name|m_comboBox
operator|->
name|setObjectName
argument_list|(
name|QString
operator|::
name|fromUtf8
argument_list|(
literal|"m_comboBox"
argument_list|)
argument_list|)
expr_stmt|;
name|horizontalLayout
operator|->
name|addWidget
argument_list|(
name|m_comboBox
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
name|horizontalLayout
operator|->
name|addItem
argument_list|(
name|horizontalSpacer
argument_list|)
expr_stmt|;
name|formLayout
operator|->
name|setLayout
argument_list|(
literal|1
argument_list|,
name|QFormLayout
operator|::
name|FieldRole
argument_list|,
name|horizontalLayout
argument_list|)
expr_stmt|;
name|label_2
operator|=
name|new
name|QLabel
argument_list|(
name|qdesigner_internal__NewDynamicPropertyDialog
argument_list|)
expr_stmt|;
name|label_2
operator|->
name|setObjectName
argument_list|(
name|QString
operator|::
name|fromUtf8
argument_list|(
literal|"label_2"
argument_list|)
argument_list|)
expr_stmt|;
name|sizePolicy
operator|.
name|setHeightForWidth
argument_list|(
name|label_2
operator|->
name|sizePolicy
argument_list|()
operator|.
name|hasHeightForWidth
argument_list|()
argument_list|)
expr_stmt|;
name|label_2
operator|->
name|setSizePolicy
argument_list|(
name|sizePolicy
argument_list|)
expr_stmt|;
name|formLayout
operator|->
name|setWidget
argument_list|(
literal|1
argument_list|,
name|QFormLayout
operator|::
name|LabelRole
argument_list|,
name|label_2
argument_list|)
expr_stmt|;
name|verticalLayout
operator|->
name|addLayout
argument_list|(
name|formLayout
argument_list|)
expr_stmt|;
name|spacerItem
operator|=
name|new
name|QSpacerItem
argument_list|(
name|QSizePolicy
operator|::
name|Minimum
argument_list|,
name|QSizePolicy
operator|::
name|Expanding
argument_list|)
expr_stmt|;
name|verticalLayout
operator|->
name|addItem
argument_list|(
name|spacerItem
argument_list|)
expr_stmt|;
name|m_buttonBox
operator|=
name|new
name|QDialogButtonBox
argument_list|(
name|qdesigner_internal__NewDynamicPropertyDialog
argument_list|)
expr_stmt|;
name|m_buttonBox
operator|->
name|setObjectName
argument_list|(
name|QString
operator|::
name|fromUtf8
argument_list|(
literal|"m_buttonBox"
argument_list|)
argument_list|)
expr_stmt|;
name|m_buttonBox
operator|->
name|setOrientation
argument_list|(
name|Qt
operator|::
name|Horizontal
argument_list|)
expr_stmt|;
name|m_buttonBox
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
name|m_buttonBox
operator|->
name|setCenterButtons
argument_list|(
name|false
argument_list|)
expr_stmt|;
name|verticalLayout
operator|->
name|addWidget
argument_list|(
name|m_buttonBox
argument_list|)
expr_stmt|;
name|retranslateUi
argument_list|(
name|qdesigner_internal__NewDynamicPropertyDialog
argument_list|)
expr_stmt|;
name|QMetaObject
operator|::
name|connectSlotsByName
argument_list|(
name|qdesigner_internal__NewDynamicPropertyDialog
argument_list|)
expr_stmt|;
block|}
comment|// setupUi
name|void
name|retranslateUi
parameter_list|(
name|QDialog
modifier|*
name|qdesigner_internal__NewDynamicPropertyDialog
parameter_list|)
block|{
name|qdesigner_internal__NewDynamicPropertyDialog
operator|->
name|setWindowTitle
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"qdesigner_internal::NewDynamicPropertyDialog"
argument_list|,
literal|"Create Dynamic Property"
argument_list|,
literal|0
argument_list|,
name|QApplication
operator|::
name|UnicodeUTF8
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
literal|"qdesigner_internal::NewDynamicPropertyDialog"
argument_list|,
literal|"Property Name"
argument_list|,
literal|0
argument_list|,
name|QApplication
operator|::
name|UnicodeUTF8
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
literal|"qdesigner_internal::NewDynamicPropertyDialog"
argument_list|,
literal|"Property Type"
argument_list|,
literal|0
argument_list|,
name|QApplication
operator|::
name|UnicodeUTF8
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
name|NewDynamicPropertyDialog
range|:
name|public
name|Ui_NewDynamicPropertyDialog
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
comment|// NEWDYNAMICPROPERTYDIALOG_H
end_comment
end_unit
