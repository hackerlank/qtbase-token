begin_unit
begin_comment
comment|/******************************************************************************** ** Form generated from reading UI file 'Widget.ui' ** ** Created by: Qt User Interface Compiler version 5.0.0 ** ** WARNING! All changes made in this file will be lost when recompiling UI file! ********************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|WIDGET_H
end_ifndef
begin_define
DECL|macro|WIDGET_H
define|#
directive|define
name|WIDGET_H
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
file|<QtWidgets/QPushButton>
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
name|Ui_Form
block|{
name|public
label|:
name|QVBoxLayout
modifier|*
name|vboxLayout
decl_stmt|;
name|QLabel
modifier|*
name|Alabel
decl_stmt|;
name|QGroupBox
modifier|*
name|groupBox
decl_stmt|;
name|QPushButton
modifier|*
name|pushButton
decl_stmt|;
name|void
name|setupUi
parameter_list|(
name|QWidget
modifier|*
name|Form
parameter_list|)
block|{
if|if
condition|(
name|Form
operator|->
name|objectName
argument_list|()
operator|.
name|isEmpty
argument_list|()
condition|)
name|Form
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"Form"
argument_list|)
argument_list|)
expr_stmt|;
name|Form
operator|->
name|resize
argument_list|(
literal|400
argument_list|,
literal|300
argument_list|)
expr_stmt|;
name|vboxLayout
operator|=
name|new
name|QVBoxLayout
argument_list|(
name|Form
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
name|Alabel
operator|=
name|new
name|QLabel
argument_list|(
name|Form
argument_list|)
expr_stmt|;
name|Alabel
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"Alabel"
argument_list|)
argument_list|)
expr_stmt|;
name|vboxLayout
operator|->
name|addWidget
argument_list|(
name|Alabel
argument_list|)
expr_stmt|;
name|groupBox
operator|=
name|new
name|QGroupBox
argument_list|(
name|Form
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
name|vboxLayout
operator|->
name|addWidget
argument_list|(
name|groupBox
argument_list|)
expr_stmt|;
name|pushButton
operator|=
name|new
name|QPushButton
argument_list|(
name|Form
argument_list|)
expr_stmt|;
name|pushButton
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"pushButton"
argument_list|)
argument_list|)
expr_stmt|;
name|vboxLayout
operator|->
name|addWidget
argument_list|(
name|pushButton
argument_list|)
expr_stmt|;
name|retranslateUi
argument_list|(
name|Form
argument_list|)
expr_stmt|;
name|QMetaObject
operator|::
name|connectSlotsByName
argument_list|(
name|Form
argument_list|)
expr_stmt|;
block|}
comment|// setupUi
name|void
name|retranslateUi
parameter_list|(
name|QWidget
modifier|*
name|Form
parameter_list|)
block|{
name|Form
operator|->
name|setWindowTitle
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"Form"
argument_list|,
literal|"Form"
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
name|Alabel
operator|->
name|setText
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"Form"
argument_list|,
literal|"A label.\n"
literal|"One new line.\n"
literal|"Another new line.\n"
literal|"Last line."
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
literal|"Form"
argument_list|,
literal|"A Group Box"
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
name|pushButton
operator|->
name|setText
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"Form"
argument_list|,
literal|"PushButton"
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
name|Form
range|:
name|public
name|Ui_Form
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
comment|// WIDGET_H
end_comment
end_unit
