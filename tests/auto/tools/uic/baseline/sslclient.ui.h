begin_unit
begin_comment
comment|/******************************************************************************** ** Form generated from reading UI file 'sslclient.ui' ** ** Created: Fri Sep 4 10:17:14 2009 **      by: Qt User Interface Compiler version 4.6.0 ** ** WARNING! All changes made in this file will be lost when recompiling UI file! ********************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|SSLCLIENT_H
end_ifndef
begin_define
DECL|macro|SSLCLIENT_H
define|#
directive|define
name|SSLCLIENT_H
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
file|<QtWidgets/QPushButton>
end_include
begin_include
include|#
directive|include
file|<QtWidgets/QSpinBox>
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
name|QGridLayout
modifier|*
name|gridLayout
decl_stmt|;
name|QLabel
modifier|*
name|hostNameLabel
decl_stmt|;
name|QLineEdit
modifier|*
name|hostNameEdit
decl_stmt|;
name|QLabel
modifier|*
name|portLabel
decl_stmt|;
name|QSpinBox
modifier|*
name|portBox
decl_stmt|;
name|QPushButton
modifier|*
name|connectButton
decl_stmt|;
name|QGroupBox
modifier|*
name|sessionBox
decl_stmt|;
name|QVBoxLayout
modifier|*
name|vboxLayout1
decl_stmt|;
name|QHBoxLayout
modifier|*
name|hboxLayout
decl_stmt|;
name|QLabel
modifier|*
name|cipherText
decl_stmt|;
name|QLabel
modifier|*
name|cipherLabel
decl_stmt|;
name|QTextEdit
modifier|*
name|sessionOutput
decl_stmt|;
name|QHBoxLayout
modifier|*
name|hboxLayout1
decl_stmt|;
name|QLabel
modifier|*
name|sessionInputLabel
decl_stmt|;
name|QLineEdit
modifier|*
name|sessionInput
decl_stmt|;
name|QPushButton
modifier|*
name|sendButton
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
literal|343
argument_list|,
literal|320
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
name|gridLayout
operator|=
name|new
name|QGridLayout
argument_list|()
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
name|hostNameLabel
operator|=
name|new
name|QLabel
argument_list|(
name|Form
argument_list|)
expr_stmt|;
name|hostNameLabel
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"hostNameLabel"
argument_list|)
argument_list|)
expr_stmt|;
name|gridLayout
operator|->
name|addWidget
argument_list|(
name|hostNameLabel
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
name|hostNameEdit
operator|=
name|new
name|QLineEdit
argument_list|(
name|Form
argument_list|)
expr_stmt|;
name|hostNameEdit
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"hostNameEdit"
argument_list|)
argument_list|)
expr_stmt|;
name|gridLayout
operator|->
name|addWidget
argument_list|(
name|hostNameEdit
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
name|portLabel
operator|=
name|new
name|QLabel
argument_list|(
name|Form
argument_list|)
expr_stmt|;
name|portLabel
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"portLabel"
argument_list|)
argument_list|)
expr_stmt|;
name|gridLayout
operator|->
name|addWidget
argument_list|(
name|portLabel
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
name|portBox
operator|=
name|new
name|QSpinBox
argument_list|(
name|Form
argument_list|)
expr_stmt|;
name|portBox
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"portBox"
argument_list|)
argument_list|)
expr_stmt|;
name|portBox
operator|->
name|setMinimum
argument_list|(
literal|1
argument_list|)
expr_stmt|;
name|portBox
operator|->
name|setMaximum
argument_list|(
literal|65535
argument_list|)
expr_stmt|;
name|portBox
operator|->
name|setValue
argument_list|(
literal|993
argument_list|)
expr_stmt|;
name|gridLayout
operator|->
name|addWidget
argument_list|(
name|portBox
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
name|vboxLayout
operator|->
name|addLayout
argument_list|(
name|gridLayout
argument_list|)
expr_stmt|;
name|connectButton
operator|=
name|new
name|QPushButton
argument_list|(
name|Form
argument_list|)
expr_stmt|;
name|connectButton
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"connectButton"
argument_list|)
argument_list|)
expr_stmt|;
name|connectButton
operator|->
name|setEnabled
argument_list|(
name|true
argument_list|)
expr_stmt|;
name|connectButton
operator|->
name|setDefault
argument_list|(
name|true
argument_list|)
expr_stmt|;
name|vboxLayout
operator|->
name|addWidget
argument_list|(
name|connectButton
argument_list|)
expr_stmt|;
name|sessionBox
operator|=
name|new
name|QGroupBox
argument_list|(
name|Form
argument_list|)
expr_stmt|;
name|sessionBox
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"sessionBox"
argument_list|)
argument_list|)
expr_stmt|;
name|sessionBox
operator|->
name|setEnabled
argument_list|(
name|false
argument_list|)
expr_stmt|;
name|vboxLayout1
operator|=
name|new
name|QVBoxLayout
argument_list|(
name|sessionBox
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
name|cipherText
operator|=
name|new
name|QLabel
argument_list|(
name|sessionBox
argument_list|)
expr_stmt|;
name|cipherText
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"cipherText"
argument_list|)
argument_list|)
expr_stmt|;
name|hboxLayout
operator|->
name|addWidget
argument_list|(
name|cipherText
argument_list|)
expr_stmt|;
name|cipherLabel
operator|=
name|new
name|QLabel
argument_list|(
name|sessionBox
argument_list|)
expr_stmt|;
name|cipherLabel
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"cipherLabel"
argument_list|)
argument_list|)
expr_stmt|;
name|cipherLabel
operator|->
name|setAlignment
argument_list|(
name|Qt
operator|::
name|AlignRight
operator||
name|Qt
operator|::
name|AlignTrailing
operator||
name|Qt
operator|::
name|AlignVCenter
argument_list|)
expr_stmt|;
name|hboxLayout
operator|->
name|addWidget
argument_list|(
name|cipherLabel
argument_list|)
expr_stmt|;
name|vboxLayout1
operator|->
name|addLayout
argument_list|(
name|hboxLayout
argument_list|)
expr_stmt|;
name|sessionOutput
operator|=
name|new
name|QTextEdit
argument_list|(
name|sessionBox
argument_list|)
expr_stmt|;
name|sessionOutput
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"sessionOutput"
argument_list|)
argument_list|)
expr_stmt|;
name|sessionOutput
operator|->
name|setEnabled
argument_list|(
name|false
argument_list|)
expr_stmt|;
name|sessionOutput
operator|->
name|setFocusPolicy
argument_list|(
name|Qt
operator|::
name|NoFocus
argument_list|)
expr_stmt|;
name|sessionOutput
operator|->
name|setReadOnly
argument_list|(
name|true
argument_list|)
expr_stmt|;
name|vboxLayout1
operator|->
name|addWidget
argument_list|(
name|sessionOutput
argument_list|)
expr_stmt|;
name|hboxLayout1
operator|=
name|new
name|QHBoxLayout
argument_list|()
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
name|sessionInputLabel
operator|=
name|new
name|QLabel
argument_list|(
name|sessionBox
argument_list|)
expr_stmt|;
name|sessionInputLabel
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"sessionInputLabel"
argument_list|)
argument_list|)
expr_stmt|;
name|hboxLayout1
operator|->
name|addWidget
argument_list|(
name|sessionInputLabel
argument_list|)
expr_stmt|;
name|sessionInput
operator|=
name|new
name|QLineEdit
argument_list|(
name|sessionBox
argument_list|)
expr_stmt|;
name|sessionInput
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"sessionInput"
argument_list|)
argument_list|)
expr_stmt|;
name|sessionInput
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
name|sessionInput
argument_list|)
expr_stmt|;
name|sendButton
operator|=
name|new
name|QPushButton
argument_list|(
name|sessionBox
argument_list|)
expr_stmt|;
name|sendButton
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"sendButton"
argument_list|)
argument_list|)
expr_stmt|;
name|sendButton
operator|->
name|setEnabled
argument_list|(
name|false
argument_list|)
expr_stmt|;
name|sendButton
operator|->
name|setFocusPolicy
argument_list|(
name|Qt
operator|::
name|TabFocus
argument_list|)
expr_stmt|;
name|sendButton
operator|->
name|setDefault
argument_list|(
name|true
argument_list|)
expr_stmt|;
name|hboxLayout1
operator|->
name|addWidget
argument_list|(
name|sendButton
argument_list|)
expr_stmt|;
name|vboxLayout1
operator|->
name|addLayout
argument_list|(
name|hboxLayout1
argument_list|)
expr_stmt|;
name|vboxLayout
operator|->
name|addWidget
argument_list|(
name|sessionBox
argument_list|)
expr_stmt|;
name|retranslateUi
argument_list|(
name|Form
argument_list|)
expr_stmt|;
name|QObject
operator|::
name|connect
argument_list|(
name|hostNameEdit
argument_list|,
name|SIGNAL
argument_list|(
name|returnPressed
argument_list|()
argument_list|)
argument_list|,
name|connectButton
argument_list|,
name|SLOT
argument_list|(
name|animateClick
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|QObject
operator|::
name|connect
argument_list|(
name|sessionInput
argument_list|,
name|SIGNAL
argument_list|(
name|returnPressed
argument_list|()
argument_list|)
argument_list|,
name|sendButton
argument_list|,
name|SLOT
argument_list|(
name|animateClick
argument_list|()
argument_list|)
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
literal|"Secure Socket Client"
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
name|hostNameLabel
operator|->
name|setText
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"Form"
argument_list|,
literal|"Host name:"
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
name|hostNameEdit
operator|->
name|setText
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"Form"
argument_list|,
literal|"imap.example.com"
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
name|portLabel
operator|->
name|setText
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"Form"
argument_list|,
literal|"Port:"
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
name|connectButton
operator|->
name|setText
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"Form"
argument_list|,
literal|"Connect to host"
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
name|sessionBox
operator|->
name|setTitle
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"Form"
argument_list|,
literal|"Active session"
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
name|cipherText
operator|->
name|setText
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"Form"
argument_list|,
literal|"Cryptographic Cipher:"
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
name|cipherLabel
operator|->
name|setText
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"Form"
argument_list|,
literal|"<none>"
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
name|sessionOutput
operator|->
name|setHtml
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"Form"
argument_list|,
literal|"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
literal|"p, li { white-space: pre-wrap; }\n"
literal|"</style></head><body style=\" font-family:'Sans Serif'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
literal|"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"></p></body></html>"
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
name|sessionInputLabel
operator|->
name|setText
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"Form"
argument_list|,
literal|"Input:"
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
name|sendButton
operator|->
name|setText
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"Form"
argument_list|,
literal|"&Send"
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
comment|// SSLCLIENT_H
end_comment
end_unit
