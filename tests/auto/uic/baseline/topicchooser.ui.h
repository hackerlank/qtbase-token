begin_unit
begin_comment
comment|/******************************************************************************** ** Form generated from reading UI file 'topicchooser.ui' ** ** Created: Fri Sep 4 10:17:15 2009 **      by: Qt User Interface Compiler version 4.6.0 ** ** WARNING! All changes made in this file will be lost when recompiling UI file! ********************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|TOPICCHOOSER_H
end_ifndef
begin_define
DECL|macro|TOPICCHOOSER_H
define|#
directive|define
name|TOPICCHOOSER_H
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
file|<QtGui/QDialog>
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
file|<QtGui/QListWidget>
end_include
begin_include
include|#
directive|include
file|<QtGui/QPushButton>
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
begin_include
include|#
directive|include
file|<QtGui/QWidget>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
name|class
name|Ui_TopicChooser
block|{
name|public
label|:
name|QVBoxLayout
modifier|*
name|vboxLayout
decl_stmt|;
name|QLabel
modifier|*
name|label
decl_stmt|;
name|QListWidget
modifier|*
name|listWidget
decl_stmt|;
name|QWidget
modifier|*
name|Layout16
decl_stmt|;
name|QHBoxLayout
modifier|*
name|hboxLayout
decl_stmt|;
name|QSpacerItem
modifier|*
name|Horizontal_Spacing2
decl_stmt|;
name|QPushButton
modifier|*
name|buttonDisplay
decl_stmt|;
name|QPushButton
modifier|*
name|buttonCancel
decl_stmt|;
name|void
name|setupUi
parameter_list|(
name|QDialog
modifier|*
name|TopicChooser
parameter_list|)
block|{
if|if
condition|(
name|TopicChooser
operator|->
name|objectName
argument_list|()
operator|.
name|isEmpty
argument_list|()
condition|)
name|TopicChooser
operator|->
name|setObjectName
argument_list|(
name|QString
operator|::
name|fromUtf8
argument_list|(
literal|"TopicChooser"
argument_list|)
argument_list|)
expr_stmt|;
name|TopicChooser
operator|->
name|resize
argument_list|(
literal|391
argument_list|,
literal|223
argument_list|)
expr_stmt|;
name|TopicChooser
operator|->
name|setSizeGripEnabled
argument_list|(
name|true
argument_list|)
expr_stmt|;
name|vboxLayout
operator|=
name|new
name|QVBoxLayout
argument_list|(
name|TopicChooser
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
literal|11
argument_list|,
literal|11
argument_list|,
literal|11
argument_list|,
literal|11
argument_list|)
expr_stmt|;
name|vboxLayout
operator|->
name|setObjectName
argument_list|(
name|QString
operator|::
name|fromUtf8
argument_list|(
literal|"vboxLayout"
argument_list|)
argument_list|)
expr_stmt|;
name|vboxLayout
operator|->
name|setObjectName
argument_list|(
name|QString
operator|::
name|fromUtf8
argument_list|(
literal|"unnamed"
argument_list|)
argument_list|)
expr_stmt|;
name|label
operator|=
name|new
name|QLabel
argument_list|(
name|TopicChooser
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
name|vboxLayout
operator|->
name|addWidget
argument_list|(
name|label
argument_list|)
expr_stmt|;
name|listWidget
operator|=
name|new
name|QListWidget
argument_list|(
name|TopicChooser
argument_list|)
expr_stmt|;
name|listWidget
operator|->
name|setObjectName
argument_list|(
name|QString
operator|::
name|fromUtf8
argument_list|(
literal|"listWidget"
argument_list|)
argument_list|)
expr_stmt|;
name|vboxLayout
operator|->
name|addWidget
argument_list|(
name|listWidget
argument_list|)
expr_stmt|;
name|Layout16
operator|=
name|new
name|QWidget
argument_list|(
name|TopicChooser
argument_list|)
expr_stmt|;
name|Layout16
operator|->
name|setObjectName
argument_list|(
name|QString
operator|::
name|fromUtf8
argument_list|(
literal|"Layout16"
argument_list|)
argument_list|)
expr_stmt|;
name|hboxLayout
operator|=
name|new
name|QHBoxLayout
argument_list|(
name|Layout16
argument_list|)
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
name|QString
operator|::
name|fromUtf8
argument_list|(
literal|"hboxLayout"
argument_list|)
argument_list|)
expr_stmt|;
name|hboxLayout
operator|->
name|setObjectName
argument_list|(
name|QString
operator|::
name|fromUtf8
argument_list|(
literal|"unnamed"
argument_list|)
argument_list|)
expr_stmt|;
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
name|Horizontal_Spacing2
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
name|Horizontal_Spacing2
argument_list|)
expr_stmt|;
name|buttonDisplay
operator|=
name|new
name|QPushButton
argument_list|(
name|Layout16
argument_list|)
expr_stmt|;
name|buttonDisplay
operator|->
name|setObjectName
argument_list|(
name|QString
operator|::
name|fromUtf8
argument_list|(
literal|"buttonDisplay"
argument_list|)
argument_list|)
expr_stmt|;
name|buttonDisplay
operator|->
name|setAutoDefault
argument_list|(
name|true
argument_list|)
expr_stmt|;
name|buttonDisplay
operator|->
name|setDefault
argument_list|(
name|true
argument_list|)
expr_stmt|;
name|hboxLayout
operator|->
name|addWidget
argument_list|(
name|buttonDisplay
argument_list|)
expr_stmt|;
name|buttonCancel
operator|=
name|new
name|QPushButton
argument_list|(
name|Layout16
argument_list|)
expr_stmt|;
name|buttonCancel
operator|->
name|setObjectName
argument_list|(
name|QString
operator|::
name|fromUtf8
argument_list|(
literal|"buttonCancel"
argument_list|)
argument_list|)
expr_stmt|;
name|buttonCancel
operator|->
name|setAutoDefault
argument_list|(
name|true
argument_list|)
expr_stmt|;
name|hboxLayout
operator|->
name|addWidget
argument_list|(
name|buttonCancel
argument_list|)
expr_stmt|;
name|vboxLayout
operator|->
name|addWidget
argument_list|(
name|Layout16
argument_list|)
expr_stmt|;
ifndef|#
directive|ifndef
name|QT_NO_SHORTCUT
name|label
operator|->
name|setBuddy
argument_list|(
name|listWidget
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|// QT_NO_SHORTCUT
name|retranslateUi
argument_list|(
name|TopicChooser
argument_list|)
expr_stmt|;
name|QMetaObject
operator|::
name|connectSlotsByName
argument_list|(
name|TopicChooser
argument_list|)
expr_stmt|;
block|}
comment|// setupUi
name|void
name|retranslateUi
parameter_list|(
name|QDialog
modifier|*
name|TopicChooser
parameter_list|)
block|{
name|TopicChooser
operator|->
name|setWindowTitle
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"TopicChooser"
argument_list|,
literal|"Choose Topic"
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
literal|"TopicChooser"
argument_list|,
literal|"&Topics"
argument_list|,
literal|0
argument_list|,
name|QApplication
operator|::
name|UnicodeUTF8
argument_list|)
argument_list|)
expr_stmt|;
name|buttonDisplay
operator|->
name|setText
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"TopicChooser"
argument_list|,
literal|"&Display"
argument_list|,
literal|0
argument_list|,
name|QApplication
operator|::
name|UnicodeUTF8
argument_list|)
argument_list|)
expr_stmt|;
name|buttonCancel
operator|->
name|setText
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"TopicChooser"
argument_list|,
literal|"&Close"
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
name|TopicChooser
range|:
name|public
name|Ui_TopicChooser
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
comment|// TOPICCHOOSER_H
end_comment
end_unit
