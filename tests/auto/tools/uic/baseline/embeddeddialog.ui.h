begin_unit
begin_comment
comment|/******************************************************************************** ** Form generated from reading UI file 'embeddeddialog.ui' ** ** Created by: Qt User Interface Compiler version 5.0.0 ** ** WARNING! All changes made in this file will be lost when recompiling UI file! ********************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|EMBEDDEDDIALOG_H
end_ifndef
begin_define
DECL|macro|EMBEDDEDDIALOG_H
define|#
directive|define
name|EMBEDDEDDIALOG_H
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
file|<QtWidgets/QComboBox>
end_include
begin_include
include|#
directive|include
file|<QtWidgets/QDialog>
end_include
begin_include
include|#
directive|include
file|<QtWidgets/QFontComboBox>
end_include
begin_include
include|#
directive|include
file|<QtWidgets/QFormLayout>
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
file|<QtWidgets/QSlider>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
name|class
name|Ui_embeddedDialog
block|{
name|public
label|:
name|QFormLayout
modifier|*
name|formLayout
decl_stmt|;
name|QLabel
modifier|*
name|label
decl_stmt|;
name|QComboBox
modifier|*
name|layoutDirection
decl_stmt|;
name|QLabel
modifier|*
name|label_2
decl_stmt|;
name|QFontComboBox
modifier|*
name|fontComboBox
decl_stmt|;
name|QLabel
modifier|*
name|label_3
decl_stmt|;
name|QComboBox
modifier|*
name|style
decl_stmt|;
name|QLabel
modifier|*
name|label_4
decl_stmt|;
name|QSlider
modifier|*
name|spacing
decl_stmt|;
name|void
name|setupUi
parameter_list|(
name|QDialog
modifier|*
name|embeddedDialog
parameter_list|)
block|{
if|if
condition|(
name|embeddedDialog
operator|->
name|objectName
argument_list|()
operator|.
name|isEmpty
argument_list|()
condition|)
name|embeddedDialog
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"embeddedDialog"
argument_list|)
argument_list|)
expr_stmt|;
name|embeddedDialog
operator|->
name|resize
argument_list|(
literal|407
argument_list|,
literal|134
argument_list|)
expr_stmt|;
name|formLayout
operator|=
name|new
name|QFormLayout
argument_list|(
name|embeddedDialog
argument_list|)
expr_stmt|;
name|formLayout
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"formLayout"
argument_list|)
argument_list|)
expr_stmt|;
name|label
operator|=
name|new
name|QLabel
argument_list|(
name|embeddedDialog
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
name|layoutDirection
operator|=
name|new
name|QComboBox
argument_list|(
name|embeddedDialog
argument_list|)
expr_stmt|;
name|layoutDirection
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"layoutDirection"
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
name|layoutDirection
argument_list|)
expr_stmt|;
name|label_2
operator|=
name|new
name|QLabel
argument_list|(
name|embeddedDialog
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
name|fontComboBox
operator|=
name|new
name|QFontComboBox
argument_list|(
name|embeddedDialog
argument_list|)
expr_stmt|;
name|fontComboBox
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"fontComboBox"
argument_list|)
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
name|FieldRole
argument_list|,
name|fontComboBox
argument_list|)
expr_stmt|;
name|label_3
operator|=
name|new
name|QLabel
argument_list|(
name|embeddedDialog
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
name|formLayout
operator|->
name|setWidget
argument_list|(
literal|2
argument_list|,
name|QFormLayout
operator|::
name|LabelRole
argument_list|,
name|label_3
argument_list|)
expr_stmt|;
name|style
operator|=
name|new
name|QComboBox
argument_list|(
name|embeddedDialog
argument_list|)
expr_stmt|;
name|style
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"style"
argument_list|)
argument_list|)
expr_stmt|;
name|formLayout
operator|->
name|setWidget
argument_list|(
literal|2
argument_list|,
name|QFormLayout
operator|::
name|FieldRole
argument_list|,
name|style
argument_list|)
expr_stmt|;
name|label_4
operator|=
name|new
name|QLabel
argument_list|(
name|embeddedDialog
argument_list|)
expr_stmt|;
name|label_4
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"label_4"
argument_list|)
argument_list|)
expr_stmt|;
name|formLayout
operator|->
name|setWidget
argument_list|(
literal|3
argument_list|,
name|QFormLayout
operator|::
name|LabelRole
argument_list|,
name|label_4
argument_list|)
expr_stmt|;
name|spacing
operator|=
name|new
name|QSlider
argument_list|(
name|embeddedDialog
argument_list|)
expr_stmt|;
name|spacing
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"spacing"
argument_list|)
argument_list|)
expr_stmt|;
name|spacing
operator|->
name|setOrientation
argument_list|(
name|Qt
operator|::
name|Horizontal
argument_list|)
expr_stmt|;
name|formLayout
operator|->
name|setWidget
argument_list|(
literal|3
argument_list|,
name|QFormLayout
operator|::
name|FieldRole
argument_list|,
name|spacing
argument_list|)
expr_stmt|;
ifndef|#
directive|ifndef
name|QT_NO_SHORTCUT
name|label
operator|->
name|setBuddy
argument_list|(
name|layoutDirection
argument_list|)
expr_stmt|;
name|label_2
operator|->
name|setBuddy
argument_list|(
name|fontComboBox
argument_list|)
expr_stmt|;
name|label_3
operator|->
name|setBuddy
argument_list|(
name|style
argument_list|)
expr_stmt|;
name|label_4
operator|->
name|setBuddy
argument_list|(
name|spacing
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|// QT_NO_SHORTCUT
name|retranslateUi
argument_list|(
name|embeddedDialog
argument_list|)
expr_stmt|;
name|QMetaObject
operator|::
name|connectSlotsByName
argument_list|(
name|embeddedDialog
argument_list|)
expr_stmt|;
block|}
comment|// setupUi
name|void
name|retranslateUi
parameter_list|(
name|QDialog
modifier|*
name|embeddedDialog
parameter_list|)
block|{
name|embeddedDialog
operator|->
name|setWindowTitle
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"embeddedDialog"
argument_list|,
literal|"Embedded Dialog"
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
literal|"embeddedDialog"
argument_list|,
literal|"Layout Direction:"
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
name|layoutDirection
operator|->
name|clear
argument_list|()
expr_stmt|;
name|layoutDirection
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
literal|"embeddedDialog"
argument_list|,
literal|"Left to Right"
argument_list|,
literal|0
argument_list|)
operator|<<
name|QApplication
operator|::
name|translate
argument_list|(
literal|"embeddedDialog"
argument_list|,
literal|"Right to Left"
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
literal|"embeddedDialog"
argument_list|,
literal|"Select Font:"
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
name|label_3
operator|->
name|setText
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"embeddedDialog"
argument_list|,
literal|"Style:"
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
name|label_4
operator|->
name|setText
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"embeddedDialog"
argument_list|,
literal|"Layout spacing:"
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
name|embeddedDialog
range|:
name|public
name|Ui_embeddedDialog
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
comment|// EMBEDDEDDIALOG_H
end_comment
end_unit
