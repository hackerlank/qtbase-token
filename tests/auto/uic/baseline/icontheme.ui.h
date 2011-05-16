begin_unit
begin_comment
comment|/******************************************************************************** ** Form generated from reading UI file 'icontheme.ui' ** ** Created: Thu Sep 2 10:28:19 2010 **      by: Qt User Interface Compiler version 5.0.0 ** ** WARNING! All changes made in this file will be lost when recompiling UI file! ********************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|ICONTHEME_H
end_ifndef
begin_define
DECL|macro|ICONTHEME_H
define|#
directive|define
name|ICONTHEME_H
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
file|<QtGui/QHeaderView>
end_include
begin_include
include|#
directive|include
file|<QtGui/QPushButton>
end_include
begin_include
include|#
directive|include
file|<QtGui/QVBoxLayout>
end_include
begin_include
include|#
directive|include
file|<QtGui/QWidget>
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
name|verticalLayout
decl_stmt|;
name|QPushButton
modifier|*
name|fileicon
decl_stmt|;
name|QPushButton
modifier|*
name|fileandthemeicon
decl_stmt|;
name|QPushButton
modifier|*
name|themeicon
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
name|QString
operator|::
name|fromUtf8
argument_list|(
literal|"Form"
argument_list|)
argument_list|)
expr_stmt|;
name|Form
operator|->
name|resize
argument_list|(
literal|122
argument_list|,
literal|117
argument_list|)
expr_stmt|;
name|verticalLayout
operator|=
name|new
name|QVBoxLayout
argument_list|(
name|Form
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
name|fileicon
operator|=
name|new
name|QPushButton
argument_list|(
name|Form
argument_list|)
expr_stmt|;
name|fileicon
operator|->
name|setObjectName
argument_list|(
name|QString
operator|::
name|fromUtf8
argument_list|(
literal|"fileicon"
argument_list|)
argument_list|)
expr_stmt|;
name|QIcon
name|icon
decl_stmt|;
name|icon
operator|.
name|addFile
argument_list|(
name|QString
operator|::
name|fromUtf8
argument_list|(
literal|"image1.png"
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
name|fileicon
operator|->
name|setIcon
argument_list|(
name|icon
argument_list|)
expr_stmt|;
name|verticalLayout
operator|->
name|addWidget
argument_list|(
name|fileicon
argument_list|)
expr_stmt|;
name|fileandthemeicon
operator|=
name|new
name|QPushButton
argument_list|(
name|Form
argument_list|)
expr_stmt|;
name|fileandthemeicon
operator|->
name|setObjectName
argument_list|(
name|QString
operator|::
name|fromUtf8
argument_list|(
literal|"fileandthemeicon"
argument_list|)
argument_list|)
expr_stmt|;
name|QIcon
name|icon1
decl_stmt|;
name|QString
name|iconThemeName
init|=
name|QString
operator|::
name|fromUtf8
argument_list|(
literal|"edit-copy"
argument_list|)
decl_stmt|;
if|if
condition|(
name|QIcon
operator|::
name|hasThemeIcon
argument_list|(
name|iconThemeName
argument_list|)
condition|)
block|{
name|icon1
operator|=
name|QIcon
operator|::
name|fromTheme
argument_list|(
name|iconThemeName
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|icon1
operator|.
name|addFile
argument_list|(
name|QString
operator|::
name|fromUtf8
argument_list|(
literal|"image7.png"
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
block|}
name|fileandthemeicon
operator|->
name|setIcon
argument_list|(
name|icon1
argument_list|)
expr_stmt|;
name|verticalLayout
operator|->
name|addWidget
argument_list|(
name|fileandthemeicon
argument_list|)
expr_stmt|;
name|themeicon
operator|=
name|new
name|QPushButton
argument_list|(
name|Form
argument_list|)
expr_stmt|;
name|themeicon
operator|->
name|setObjectName
argument_list|(
name|QString
operator|::
name|fromUtf8
argument_list|(
literal|"themeicon"
argument_list|)
argument_list|)
expr_stmt|;
name|QIcon
name|icon2
decl_stmt|;
name|iconThemeName
operator|=
name|QString
operator|::
name|fromUtf8
argument_list|(
literal|"edit-copy"
argument_list|)
expr_stmt|;
if|if
condition|(
name|QIcon
operator|::
name|hasThemeIcon
argument_list|(
name|iconThemeName
argument_list|)
condition|)
block|{
name|icon2
operator|=
name|QIcon
operator|::
name|fromTheme
argument_list|(
name|iconThemeName
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|icon2
operator|.
name|addFile
argument_list|(
name|QString
operator|::
name|fromUtf8
argument_list|(
literal|""
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
block|}
name|themeicon
operator|->
name|setIcon
argument_list|(
name|icon2
argument_list|)
expr_stmt|;
name|verticalLayout
operator|->
name|addWidget
argument_list|(
name|themeicon
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
argument_list|,
name|QApplication
operator|::
name|UnicodeUTF8
argument_list|)
argument_list|)
expr_stmt|;
name|fileicon
operator|->
name|setText
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"Form"
argument_list|,
literal|"fileicon"
argument_list|,
literal|0
argument_list|,
name|QApplication
operator|::
name|UnicodeUTF8
argument_list|)
argument_list|)
expr_stmt|;
name|fileandthemeicon
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
argument_list|,
name|QApplication
operator|::
name|UnicodeUTF8
argument_list|)
argument_list|)
expr_stmt|;
name|themeicon
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
comment|// ICONTHEME_H
end_comment
end_unit
