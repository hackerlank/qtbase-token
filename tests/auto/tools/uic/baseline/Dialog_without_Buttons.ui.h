begin_unit
begin_comment
comment|/******************************************************************************** ** Form generated from reading UI file 'Dialog_without_Buttons.ui' ** ** Created: Fri Sep 4 10:17:13 2009 **      by: Qt User Interface Compiler version 4.6.0 ** ** WARNING! All changes made in this file will be lost when recompiling UI file! ********************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|DIALOG_WITHOUT_BUTTONS_H
end_ifndef
begin_define
DECL|macro|DIALOG_WITHOUT_BUTTONS_H
define|#
directive|define
name|DIALOG_WITHOUT_BUTTONS_H
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
file|<QtWidgets/QHeaderView>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
name|class
name|Ui_Dialog
block|{
name|public
label|:
name|void
name|setupUi
parameter_list|(
name|QDialog
modifier|*
name|Dialog
parameter_list|)
block|{
if|if
condition|(
name|Dialog
operator|->
name|objectName
argument_list|()
operator|.
name|isEmpty
argument_list|()
condition|)
name|Dialog
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"Dialog"
argument_list|)
argument_list|)
expr_stmt|;
name|Dialog
operator|->
name|resize
argument_list|(
literal|400
argument_list|,
literal|300
argument_list|)
expr_stmt|;
name|retranslateUi
argument_list|(
name|Dialog
argument_list|)
expr_stmt|;
name|QMetaObject
operator|::
name|connectSlotsByName
argument_list|(
name|Dialog
argument_list|)
expr_stmt|;
block|}
comment|// setupUi
name|void
name|retranslateUi
parameter_list|(
name|QDialog
modifier|*
name|Dialog
parameter_list|)
block|{
name|Dialog
operator|->
name|setWindowTitle
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"Dialog"
argument_list|,
literal|"Dialog"
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
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_decl_stmt
name|namespace
name|Ui
block|{
name|class
name|Dialog
range|:
name|public
name|Ui_Dialog
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
comment|// DIALOG_WITHOUT_BUTTONS_H
end_comment
end_unit
