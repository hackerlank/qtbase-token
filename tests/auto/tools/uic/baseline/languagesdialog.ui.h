begin_unit
begin_comment
comment|/******************************************************************************** ** Form generated from reading UI file 'languagesdialog.ui' ** ** Created by: Qt User Interface Compiler version 5.0.0 ** ** WARNING! All changes made in this file will be lost when recompiling UI file! ********************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|LANGUAGESDIALOG_H
end_ifndef
begin_define
DECL|macro|LANGUAGESDIALOG_H
define|#
directive|define
name|LANGUAGESDIALOG_H
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
file|<QtWidgets/QVBoxLayout>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
name|class
name|Ui_LanguagesDialog
block|{
name|public
label|:
name|QVBoxLayout
modifier|*
name|verticalLayout
decl_stmt|;
name|QTreeWidget
modifier|*
name|languagesList
decl_stmt|;
name|QHBoxLayout
modifier|*
name|hboxLayout
decl_stmt|;
name|QToolButton
modifier|*
name|upButton
decl_stmt|;
name|QToolButton
modifier|*
name|downButton
decl_stmt|;
name|QToolButton
modifier|*
name|removeButton
decl_stmt|;
name|QToolButton
modifier|*
name|openFileButton
decl_stmt|;
name|QSpacerItem
modifier|*
name|spacerItem
decl_stmt|;
name|QPushButton
modifier|*
name|okButton
decl_stmt|;
name|void
name|setupUi
parameter_list|(
name|QDialog
modifier|*
name|LanguagesDialog
parameter_list|)
block|{
if|if
condition|(
name|LanguagesDialog
operator|->
name|objectName
argument_list|()
operator|.
name|isEmpty
argument_list|()
condition|)
name|LanguagesDialog
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"LanguagesDialog"
argument_list|)
argument_list|)
expr_stmt|;
name|LanguagesDialog
operator|->
name|resize
argument_list|(
literal|400
argument_list|,
literal|300
argument_list|)
expr_stmt|;
name|verticalLayout
operator|=
name|new
name|QVBoxLayout
argument_list|(
name|LanguagesDialog
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
name|languagesList
operator|=
name|new
name|QTreeWidget
argument_list|(
name|LanguagesDialog
argument_list|)
expr_stmt|;
name|languagesList
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"languagesList"
argument_list|)
argument_list|)
expr_stmt|;
name|languagesList
operator|->
name|setIndentation
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|verticalLayout
operator|->
name|addWidget
argument_list|(
name|languagesList
argument_list|)
expr_stmt|;
name|hboxLayout
operator|=
name|new
name|QHBoxLayout
argument_list|()
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
name|upButton
operator|=
name|new
name|QToolButton
argument_list|(
name|LanguagesDialog
argument_list|)
expr_stmt|;
name|upButton
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"upButton"
argument_list|)
argument_list|)
expr_stmt|;
name|upButton
operator|->
name|setEnabled
argument_list|(
name|false
argument_list|)
expr_stmt|;
name|QIcon
name|icon
decl_stmt|;
name|icon
operator|.
name|addFile
argument_list|(
name|QStringLiteral
argument_list|(
literal|":/images/up.png"
argument_list|)
argument_list|,
name|QSize
argument_list|()
argument_list|,
name|QIcon
operator|::
name|Normal
argument_list|,
name|QIcon
operator|::
name|Off
argument_list|)
expr_stmt|;
name|upButton
operator|->
name|setIcon
argument_list|(
name|icon
argument_list|)
expr_stmt|;
name|hboxLayout
operator|->
name|addWidget
argument_list|(
name|upButton
argument_list|)
expr_stmt|;
name|downButton
operator|=
name|new
name|QToolButton
argument_list|(
name|LanguagesDialog
argument_list|)
expr_stmt|;
name|downButton
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"downButton"
argument_list|)
argument_list|)
expr_stmt|;
name|downButton
operator|->
name|setEnabled
argument_list|(
name|false
argument_list|)
expr_stmt|;
name|QIcon
name|icon1
decl_stmt|;
name|icon1
operator|.
name|addFile
argument_list|(
name|QStringLiteral
argument_list|(
literal|":/images/down.png"
argument_list|)
argument_list|,
name|QSize
argument_list|()
argument_list|,
name|QIcon
operator|::
name|Normal
argument_list|,
name|QIcon
operator|::
name|Off
argument_list|)
expr_stmt|;
name|downButton
operator|->
name|setIcon
argument_list|(
name|icon1
argument_list|)
expr_stmt|;
name|hboxLayout
operator|->
name|addWidget
argument_list|(
name|downButton
argument_list|)
expr_stmt|;
name|removeButton
operator|=
name|new
name|QToolButton
argument_list|(
name|LanguagesDialog
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
name|removeButton
operator|->
name|setEnabled
argument_list|(
name|false
argument_list|)
expr_stmt|;
name|QIcon
name|icon2
decl_stmt|;
name|icon2
operator|.
name|addFile
argument_list|(
name|QStringLiteral
argument_list|(
literal|":/images/editdelete.png"
argument_list|)
argument_list|,
name|QSize
argument_list|()
argument_list|,
name|QIcon
operator|::
name|Normal
argument_list|,
name|QIcon
operator|::
name|Off
argument_list|)
expr_stmt|;
name|removeButton
operator|->
name|setIcon
argument_list|(
name|icon2
argument_list|)
expr_stmt|;
name|hboxLayout
operator|->
name|addWidget
argument_list|(
name|removeButton
argument_list|)
expr_stmt|;
name|openFileButton
operator|=
name|new
name|QToolButton
argument_list|(
name|LanguagesDialog
argument_list|)
expr_stmt|;
name|openFileButton
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"openFileButton"
argument_list|)
argument_list|)
expr_stmt|;
name|openFileButton
operator|->
name|setEnabled
argument_list|(
name|true
argument_list|)
expr_stmt|;
name|QIcon
name|icon3
decl_stmt|;
name|icon3
operator|.
name|addFile
argument_list|(
name|QStringLiteral
argument_list|(
literal|":/images/mac/fileopen.png"
argument_list|)
argument_list|,
name|QSize
argument_list|()
argument_list|,
name|QIcon
operator|::
name|Normal
argument_list|,
name|QIcon
operator|::
name|Off
argument_list|)
expr_stmt|;
name|openFileButton
operator|->
name|setIcon
argument_list|(
name|icon3
argument_list|)
expr_stmt|;
name|hboxLayout
operator|->
name|addWidget
argument_list|(
name|openFileButton
argument_list|)
expr_stmt|;
name|spacerItem
operator|=
name|new
name|QSpacerItem
argument_list|(
literal|121
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
name|okButton
operator|=
name|new
name|QPushButton
argument_list|(
name|LanguagesDialog
argument_list|)
expr_stmt|;
name|okButton
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"okButton"
argument_list|)
argument_list|)
expr_stmt|;
name|hboxLayout
operator|->
name|addWidget
argument_list|(
name|okButton
argument_list|)
expr_stmt|;
name|verticalLayout
operator|->
name|addLayout
argument_list|(
name|hboxLayout
argument_list|)
expr_stmt|;
name|retranslateUi
argument_list|(
name|LanguagesDialog
argument_list|)
expr_stmt|;
name|QObject
operator|::
name|connect
argument_list|(
name|okButton
argument_list|,
name|SIGNAL
argument_list|(
name|clicked
argument_list|()
argument_list|)
argument_list|,
name|LanguagesDialog
argument_list|,
name|SLOT
argument_list|(
name|accept
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|QMetaObject
operator|::
name|connectSlotsByName
argument_list|(
name|LanguagesDialog
argument_list|)
expr_stmt|;
block|}
comment|// setupUi
name|void
name|retranslateUi
parameter_list|(
name|QDialog
modifier|*
name|LanguagesDialog
parameter_list|)
block|{
name|LanguagesDialog
operator|->
name|setWindowTitle
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"LanguagesDialog"
argument_list|,
literal|"Auxiliary Languages"
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
name|QTreeWidgetItem
modifier|*
name|___qtreewidgetitem
init|=
name|languagesList
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
literal|"LanguagesDialog"
argument_list|,
literal|"File"
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
literal|"LanguagesDialog"
argument_list|,
literal|"Locale"
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
ifndef|#
directive|ifndef
name|QT_NO_TOOLTIP
name|upButton
operator|->
name|setToolTip
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"LanguagesDialog"
argument_list|,
literal|"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
literal|"p, li { white-space: pre-wrap; }\n"
literal|"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
literal|"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Move selected language up</p></body></html>"
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|// QT_NO_TOOLTIP
name|upButton
operator|->
name|setText
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"LanguagesDialog"
argument_list|,
literal|"up"
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
ifndef|#
directive|ifndef
name|QT_NO_TOOLTIP
name|downButton
operator|->
name|setToolTip
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"LanguagesDialog"
argument_list|,
literal|"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
literal|"p, li { white-space: pre-wrap; }\n"
literal|"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
literal|"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:8pt;\">Move selected language down</p></body></html>"
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|// QT_NO_TOOLTIP
name|downButton
operator|->
name|setText
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"LanguagesDialog"
argument_list|,
literal|"down"
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
ifndef|#
directive|ifndef
name|QT_NO_TOOLTIP
name|removeButton
operator|->
name|setToolTip
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"LanguagesDialog"
argument_list|,
literal|"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
literal|"p, li { white-space: pre-wrap; }\n"
literal|"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
literal|"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Remove selected language</p></body></html>"
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|// QT_NO_TOOLTIP
name|removeButton
operator|->
name|setText
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"LanguagesDialog"
argument_list|,
literal|"remove"
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
ifndef|#
directive|ifndef
name|QT_NO_TOOLTIP
name|openFileButton
operator|->
name|setToolTip
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"LanguagesDialog"
argument_list|,
literal|"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
literal|"p, li { white-space: pre-wrap; }\n"
literal|"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
literal|"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Open auxiliary language files</p></body></html>"
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|// QT_NO_TOOLTIP
name|openFileButton
operator|->
name|setText
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"LanguagesDialog"
argument_list|,
literal|"..."
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
name|okButton
operator|->
name|setText
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"LanguagesDialog"
argument_list|,
literal|"OK"
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
name|LanguagesDialog
range|:
name|public
name|Ui_LanguagesDialog
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
comment|// LANGUAGESDIALOG_H
end_comment
end_unit
