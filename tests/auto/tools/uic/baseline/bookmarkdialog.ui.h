begin_unit
begin_comment
comment|/******************************************************************************** ** Form generated from reading UI file 'bookmarkdialog.ui' ** ** Created: Fri Sep 4 10:17:12 2009 **      by: Qt User Interface Compiler version 4.6.0 ** ** WARNING! All changes made in this file will be lost when recompiling UI file! ********************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|BOOKMARKDIALOG_H
end_ifndef
begin_define
DECL|macro|BOOKMARKDIALOG_H
define|#
directive|define
name|BOOKMARKDIALOG_H
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
file|<QtWidgets/QDialogButtonBox>
end_include
begin_include
include|#
directive|include
file|<QtWidgets/QFrame>
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
file|<QtWidgets/QToolButton>
end_include
begin_include
include|#
directive|include
file|<QtWidgets/QVBoxLayout>
end_include
begin_include
include|#
directive|include
file|"bookmarkwidget.h"
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
name|class
name|Ui_BookmarkDialog
block|{
name|public
label|:
name|QVBoxLayout
modifier|*
name|verticalLayout_3
decl_stmt|;
name|QHBoxLayout
modifier|*
name|horizontalLayout
decl_stmt|;
name|QVBoxLayout
modifier|*
name|verticalLayout_2
decl_stmt|;
name|QLabel
modifier|*
name|label
decl_stmt|;
name|QLabel
modifier|*
name|label_2
decl_stmt|;
name|QVBoxLayout
modifier|*
name|verticalLayout
decl_stmt|;
name|QLineEdit
modifier|*
name|bookmarkEdit
decl_stmt|;
name|QComboBox
modifier|*
name|bookmarkFolders
decl_stmt|;
name|QHBoxLayout
modifier|*
name|horizontalLayout_3
decl_stmt|;
name|QToolButton
modifier|*
name|toolButton
decl_stmt|;
name|QFrame
modifier|*
name|line
decl_stmt|;
name|BookmarkWidget
modifier|*
name|bookmarkWidget
decl_stmt|;
name|QHBoxLayout
modifier|*
name|horizontalLayout_4
decl_stmt|;
name|QPushButton
modifier|*
name|newFolderButton
decl_stmt|;
name|QDialogButtonBox
modifier|*
name|buttonBox
decl_stmt|;
name|void
name|setupUi
parameter_list|(
name|QDialog
modifier|*
name|BookmarkDialog
parameter_list|)
block|{
if|if
condition|(
name|BookmarkDialog
operator|->
name|objectName
argument_list|()
operator|.
name|isEmpty
argument_list|()
condition|)
name|BookmarkDialog
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"BookmarkDialog"
argument_list|)
argument_list|)
expr_stmt|;
name|BookmarkDialog
operator|->
name|resize
argument_list|(
literal|450
argument_list|,
literal|135
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
name|Preferred
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
name|BookmarkDialog
operator|->
name|sizePolicy
argument_list|()
operator|.
name|hasHeightForWidth
argument_list|()
argument_list|)
expr_stmt|;
name|BookmarkDialog
operator|->
name|setSizePolicy
argument_list|(
name|sizePolicy
argument_list|)
expr_stmt|;
name|verticalLayout_3
operator|=
name|new
name|QVBoxLayout
argument_list|(
name|BookmarkDialog
argument_list|)
expr_stmt|;
name|verticalLayout_3
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"verticalLayout_3"
argument_list|)
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
name|QStringLiteral
argument_list|(
literal|"horizontalLayout"
argument_list|)
argument_list|)
expr_stmt|;
name|verticalLayout_2
operator|=
name|new
name|QVBoxLayout
argument_list|()
expr_stmt|;
name|verticalLayout_2
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"verticalLayout_2"
argument_list|)
argument_list|)
expr_stmt|;
name|label
operator|=
name|new
name|QLabel
argument_list|(
name|BookmarkDialog
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
name|verticalLayout_2
operator|->
name|addWidget
argument_list|(
name|label
argument_list|)
expr_stmt|;
name|label_2
operator|=
name|new
name|QLabel
argument_list|(
name|BookmarkDialog
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
name|verticalLayout_2
operator|->
name|addWidget
argument_list|(
name|label_2
argument_list|)
expr_stmt|;
name|horizontalLayout
operator|->
name|addLayout
argument_list|(
name|verticalLayout_2
argument_list|)
expr_stmt|;
name|verticalLayout
operator|=
name|new
name|QVBoxLayout
argument_list|()
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
name|bookmarkEdit
operator|=
name|new
name|QLineEdit
argument_list|(
name|BookmarkDialog
argument_list|)
expr_stmt|;
name|bookmarkEdit
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"bookmarkEdit"
argument_list|)
argument_list|)
expr_stmt|;
name|verticalLayout
operator|->
name|addWidget
argument_list|(
name|bookmarkEdit
argument_list|)
expr_stmt|;
name|bookmarkFolders
operator|=
name|new
name|QComboBox
argument_list|(
name|BookmarkDialog
argument_list|)
expr_stmt|;
name|bookmarkFolders
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"bookmarkFolders"
argument_list|)
argument_list|)
expr_stmt|;
name|verticalLayout
operator|->
name|addWidget
argument_list|(
name|bookmarkFolders
argument_list|)
expr_stmt|;
name|horizontalLayout
operator|->
name|addLayout
argument_list|(
name|verticalLayout
argument_list|)
expr_stmt|;
name|verticalLayout_3
operator|->
name|addLayout
argument_list|(
name|horizontalLayout
argument_list|)
expr_stmt|;
name|horizontalLayout_3
operator|=
name|new
name|QHBoxLayout
argument_list|()
expr_stmt|;
name|horizontalLayout_3
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"horizontalLayout_3"
argument_list|)
argument_list|)
expr_stmt|;
name|toolButton
operator|=
name|new
name|QToolButton
argument_list|(
name|BookmarkDialog
argument_list|)
expr_stmt|;
name|toolButton
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"toolButton"
argument_list|)
argument_list|)
expr_stmt|;
name|toolButton
operator|->
name|setMinimumSize
argument_list|(
name|QSize
argument_list|(
literal|25
argument_list|,
literal|20
argument_list|)
argument_list|)
expr_stmt|;
name|horizontalLayout_3
operator|->
name|addWidget
argument_list|(
name|toolButton
argument_list|)
expr_stmt|;
name|line
operator|=
name|new
name|QFrame
argument_list|(
name|BookmarkDialog
argument_list|)
expr_stmt|;
name|line
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"line"
argument_list|)
argument_list|)
expr_stmt|;
name|line
operator|->
name|setFrameShape
argument_list|(
name|QFrame
operator|::
name|HLine
argument_list|)
expr_stmt|;
name|line
operator|->
name|setFrameShadow
argument_list|(
name|QFrame
operator|::
name|Sunken
argument_list|)
expr_stmt|;
name|horizontalLayout_3
operator|->
name|addWidget
argument_list|(
name|line
argument_list|)
expr_stmt|;
name|verticalLayout_3
operator|->
name|addLayout
argument_list|(
name|horizontalLayout_3
argument_list|)
expr_stmt|;
name|bookmarkWidget
operator|=
name|new
name|BookmarkWidget
argument_list|(
name|BookmarkDialog
argument_list|)
expr_stmt|;
name|bookmarkWidget
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"bookmarkWidget"
argument_list|)
argument_list|)
expr_stmt|;
name|bookmarkWidget
operator|->
name|setEnabled
argument_list|(
name|true
argument_list|)
expr_stmt|;
name|QSizePolicy
name|sizePolicy1
argument_list|(
name|QSizePolicy
operator|::
name|Expanding
argument_list|,
name|QSizePolicy
operator|::
name|Ignored
argument_list|)
decl_stmt|;
name|sizePolicy1
operator|.
name|setHorizontalStretch
argument_list|(
literal|0
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
name|bookmarkWidget
operator|->
name|sizePolicy
argument_list|()
operator|.
name|hasHeightForWidth
argument_list|()
argument_list|)
expr_stmt|;
name|bookmarkWidget
operator|->
name|setSizePolicy
argument_list|(
name|sizePolicy1
argument_list|)
expr_stmt|;
name|verticalLayout_3
operator|->
name|addWidget
argument_list|(
name|bookmarkWidget
argument_list|)
expr_stmt|;
name|horizontalLayout_4
operator|=
name|new
name|QHBoxLayout
argument_list|()
expr_stmt|;
name|horizontalLayout_4
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"horizontalLayout_4"
argument_list|)
argument_list|)
expr_stmt|;
name|newFolderButton
operator|=
name|new
name|QPushButton
argument_list|(
name|BookmarkDialog
argument_list|)
expr_stmt|;
name|newFolderButton
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"newFolderButton"
argument_list|)
argument_list|)
expr_stmt|;
name|horizontalLayout_4
operator|->
name|addWidget
argument_list|(
name|newFolderButton
argument_list|)
expr_stmt|;
name|buttonBox
operator|=
name|new
name|QDialogButtonBox
argument_list|(
name|BookmarkDialog
argument_list|)
expr_stmt|;
name|buttonBox
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"buttonBox"
argument_list|)
argument_list|)
expr_stmt|;
name|buttonBox
operator|->
name|setOrientation
argument_list|(
name|Qt
operator|::
name|Horizontal
argument_list|)
expr_stmt|;
name|buttonBox
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
name|horizontalLayout_4
operator|->
name|addWidget
argument_list|(
name|buttonBox
argument_list|)
expr_stmt|;
name|verticalLayout_3
operator|->
name|addLayout
argument_list|(
name|horizontalLayout_4
argument_list|)
expr_stmt|;
name|retranslateUi
argument_list|(
name|BookmarkDialog
argument_list|)
expr_stmt|;
name|QObject
operator|::
name|connect
argument_list|(
name|buttonBox
argument_list|,
name|SIGNAL
argument_list|(
name|accepted
argument_list|()
argument_list|)
argument_list|,
name|BookmarkDialog
argument_list|,
name|SLOT
argument_list|(
name|accept
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|QObject
operator|::
name|connect
argument_list|(
name|buttonBox
argument_list|,
name|SIGNAL
argument_list|(
name|rejected
argument_list|()
argument_list|)
argument_list|,
name|BookmarkDialog
argument_list|,
name|SLOT
argument_list|(
name|reject
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|QMetaObject
operator|::
name|connectSlotsByName
argument_list|(
name|BookmarkDialog
argument_list|)
expr_stmt|;
block|}
comment|// setupUi
name|void
name|retranslateUi
parameter_list|(
name|QDialog
modifier|*
name|BookmarkDialog
parameter_list|)
block|{
name|BookmarkDialog
operator|->
name|setWindowTitle
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"BookmarkDialog"
argument_list|,
literal|"Add Bookmark"
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
literal|"BookmarkDialog"
argument_list|,
literal|"Bookmark:"
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
literal|"BookmarkDialog"
argument_list|,
literal|"Add in Folder:"
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
name|toolButton
operator|->
name|setText
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"BookmarkDialog"
argument_list|,
literal|"+"
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
name|QTreeWidgetItem
modifier|*
name|___qtreewidgetitem
init|=
name|bookmarkWidget
operator|->
name|headerItem
argument_list|()
decl_stmt|;
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
literal|"BookmarkDialog"
argument_list|,
literal|"1"
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
name|newFolderButton
operator|->
name|setText
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"BookmarkDialog"
argument_list|,
literal|"New Folder"
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
name|BookmarkDialog
range|:
name|public
name|Ui_BookmarkDialog
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
comment|// BOOKMARKDIALOG_H
end_comment
end_unit
