begin_unit
begin_comment
comment|/******************************************************************************** ** Form generated from reading UI file 'qtresourceeditordialog.ui' ** ** Created: Fri Sep 4 10:17:14 2009 **      by: Qt User Interface Compiler version 4.6.0 ** ** WARNING! All changes made in this file will be lost when recompiling UI file! ********************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QTRESOURCEEDITORDIALOG_H
end_ifndef
begin_define
DECL|macro|QTRESOURCEEDITORDIALOG_H
define|#
directive|define
name|QTRESOURCEEDITORDIALOG_H
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
file|<QtWidgets/QDialogButtonBox>
end_include
begin_include
include|#
directive|include
file|<QtWidgets/QGridLayout>
end_include
begin_include
include|#
directive|include
file|<QtWidgets/QHeaderView>
end_include
begin_include
include|#
directive|include
file|<QtWidgets/QListWidget>
end_include
begin_include
include|#
directive|include
file|<QtWidgets/QSpacerItem>
end_include
begin_include
include|#
directive|include
file|<QtWidgets/QSplitter>
end_include
begin_include
include|#
directive|include
file|<QtWidgets/QToolButton>
end_include
begin_include
include|#
directive|include
file|<QtWidgets/QTreeView>
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
name|Ui_QtResourceEditorDialog
block|{
name|public
label|:
name|QVBoxLayout
modifier|*
name|verticalLayout
decl_stmt|;
name|QSplitter
modifier|*
name|splitter
decl_stmt|;
name|QWidget
modifier|*
name|layoutWidget
decl_stmt|;
name|QGridLayout
modifier|*
name|gridLayout
decl_stmt|;
name|QListWidget
modifier|*
name|qrcFileList
decl_stmt|;
name|QToolButton
modifier|*
name|newQrcButton
decl_stmt|;
name|QToolButton
modifier|*
name|removeQrcButton
decl_stmt|;
name|QSpacerItem
modifier|*
name|spacerItem
decl_stmt|;
name|QToolButton
modifier|*
name|importQrcButton
decl_stmt|;
name|QWidget
modifier|*
name|widget
decl_stmt|;
name|QGridLayout
modifier|*
name|gridLayout1
decl_stmt|;
name|QTreeView
modifier|*
name|resourceTreeView
decl_stmt|;
name|QToolButton
modifier|*
name|newResourceButton
decl_stmt|;
name|QToolButton
modifier|*
name|addResourceButton
decl_stmt|;
name|QToolButton
modifier|*
name|removeResourceButton
decl_stmt|;
name|QSpacerItem
modifier|*
name|horizontalSpacer
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
name|QtResourceEditorDialog
parameter_list|)
block|{
if|if
condition|(
name|QtResourceEditorDialog
operator|->
name|objectName
argument_list|()
operator|.
name|isEmpty
argument_list|()
condition|)
name|QtResourceEditorDialog
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"QtResourceEditorDialog"
argument_list|)
argument_list|)
expr_stmt|;
name|QtResourceEditorDialog
operator|->
name|resize
argument_list|(
literal|469
argument_list|,
literal|317
argument_list|)
expr_stmt|;
name|verticalLayout
operator|=
name|new
name|QVBoxLayout
argument_list|(
name|QtResourceEditorDialog
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
name|splitter
operator|=
name|new
name|QSplitter
argument_list|(
name|QtResourceEditorDialog
argument_list|)
expr_stmt|;
name|splitter
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"splitter"
argument_list|)
argument_list|)
expr_stmt|;
name|splitter
operator|->
name|setOrientation
argument_list|(
name|Qt
operator|::
name|Horizontal
argument_list|)
expr_stmt|;
name|layoutWidget
operator|=
name|new
name|QWidget
argument_list|(
name|splitter
argument_list|)
expr_stmt|;
name|layoutWidget
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"layoutWidget"
argument_list|)
argument_list|)
expr_stmt|;
name|gridLayout
operator|=
name|new
name|QGridLayout
argument_list|(
name|layoutWidget
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
name|gridLayout
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
name|qrcFileList
operator|=
name|new
name|QListWidget
argument_list|(
name|layoutWidget
argument_list|)
expr_stmt|;
name|qrcFileList
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"qrcFileList"
argument_list|)
argument_list|)
expr_stmt|;
name|QSizePolicy
name|sizePolicy
argument_list|(
name|QSizePolicy
operator|::
name|Ignored
argument_list|,
name|QSizePolicy
operator|::
name|Expanding
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
name|qrcFileList
operator|->
name|sizePolicy
argument_list|()
operator|.
name|hasHeightForWidth
argument_list|()
argument_list|)
expr_stmt|;
name|qrcFileList
operator|->
name|setSizePolicy
argument_list|(
name|sizePolicy
argument_list|)
expr_stmt|;
name|gridLayout
operator|->
name|addWidget
argument_list|(
name|qrcFileList
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|1
argument_list|,
literal|4
argument_list|)
expr_stmt|;
name|newQrcButton
operator|=
name|new
name|QToolButton
argument_list|(
name|layoutWidget
argument_list|)
expr_stmt|;
name|newQrcButton
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"newQrcButton"
argument_list|)
argument_list|)
expr_stmt|;
name|gridLayout
operator|->
name|addWidget
argument_list|(
name|newQrcButton
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
name|removeQrcButton
operator|=
name|new
name|QToolButton
argument_list|(
name|layoutWidget
argument_list|)
expr_stmt|;
name|removeQrcButton
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"removeQrcButton"
argument_list|)
argument_list|)
expr_stmt|;
name|gridLayout
operator|->
name|addWidget
argument_list|(
name|removeQrcButton
argument_list|,
literal|1
argument_list|,
literal|2
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
literal|21
argument_list|,
literal|20
argument_list|,
name|QSizePolicy
operator|::
name|Ignored
argument_list|,
name|QSizePolicy
operator|::
name|Minimum
argument_list|)
expr_stmt|;
name|gridLayout
operator|->
name|addItem
argument_list|(
name|spacerItem
argument_list|,
literal|1
argument_list|,
literal|3
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|importQrcButton
operator|=
name|new
name|QToolButton
argument_list|(
name|layoutWidget
argument_list|)
expr_stmt|;
name|importQrcButton
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"importQrcButton"
argument_list|)
argument_list|)
expr_stmt|;
name|gridLayout
operator|->
name|addWidget
argument_list|(
name|importQrcButton
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
name|splitter
operator|->
name|addWidget
argument_list|(
name|layoutWidget
argument_list|)
expr_stmt|;
name|widget
operator|=
name|new
name|QWidget
argument_list|(
name|splitter
argument_list|)
expr_stmt|;
name|widget
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"widget"
argument_list|)
argument_list|)
expr_stmt|;
name|gridLayout1
operator|=
name|new
name|QGridLayout
argument_list|(
name|widget
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
name|gridLayout1
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
name|resourceTreeView
operator|=
name|new
name|QTreeView
argument_list|(
name|widget
argument_list|)
expr_stmt|;
name|resourceTreeView
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"resourceTreeView"
argument_list|)
argument_list|)
expr_stmt|;
name|gridLayout1
operator|->
name|addWidget
argument_list|(
name|resourceTreeView
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|1
argument_list|,
literal|4
argument_list|)
expr_stmt|;
name|newResourceButton
operator|=
name|new
name|QToolButton
argument_list|(
name|widget
argument_list|)
expr_stmt|;
name|newResourceButton
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"newResourceButton"
argument_list|)
argument_list|)
expr_stmt|;
name|gridLayout1
operator|->
name|addWidget
argument_list|(
name|newResourceButton
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
name|addResourceButton
operator|=
name|new
name|QToolButton
argument_list|(
name|widget
argument_list|)
expr_stmt|;
name|addResourceButton
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"addResourceButton"
argument_list|)
argument_list|)
expr_stmt|;
name|gridLayout1
operator|->
name|addWidget
argument_list|(
name|addResourceButton
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
name|removeResourceButton
operator|=
name|new
name|QToolButton
argument_list|(
name|widget
argument_list|)
expr_stmt|;
name|removeResourceButton
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"removeResourceButton"
argument_list|)
argument_list|)
expr_stmt|;
name|gridLayout1
operator|->
name|addWidget
argument_list|(
name|removeResourceButton
argument_list|,
literal|1
argument_list|,
literal|2
argument_list|,
literal|1
argument_list|,
literal|1
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
name|gridLayout1
operator|->
name|addItem
argument_list|(
name|horizontalSpacer
argument_list|,
literal|1
argument_list|,
literal|3
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|splitter
operator|->
name|addWidget
argument_list|(
name|widget
argument_list|)
expr_stmt|;
name|verticalLayout
operator|->
name|addWidget
argument_list|(
name|splitter
argument_list|)
expr_stmt|;
name|buttonBox
operator|=
name|new
name|QDialogButtonBox
argument_list|(
name|QtResourceEditorDialog
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
name|verticalLayout
operator|->
name|addWidget
argument_list|(
name|buttonBox
argument_list|)
expr_stmt|;
name|retranslateUi
argument_list|(
name|QtResourceEditorDialog
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
name|QtResourceEditorDialog
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
name|QtResourceEditorDialog
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
name|QtResourceEditorDialog
argument_list|)
expr_stmt|;
block|}
comment|// setupUi
name|void
name|retranslateUi
parameter_list|(
name|QDialog
modifier|*
name|QtResourceEditorDialog
parameter_list|)
block|{
name|QtResourceEditorDialog
operator|->
name|setWindowTitle
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"QtResourceEditorDialog"
argument_list|,
literal|"Dialog"
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
ifndef|#
directive|ifndef
name|QT_NO_TOOLTIP
name|newQrcButton
operator|->
name|setToolTip
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"QtResourceEditorDialog"
argument_list|,
literal|"New File"
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|// QT_NO_TOOLTIP
name|newQrcButton
operator|->
name|setText
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"QtResourceEditorDialog"
argument_list|,
literal|"N"
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
ifndef|#
directive|ifndef
name|QT_NO_TOOLTIP
name|removeQrcButton
operator|->
name|setToolTip
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"QtResourceEditorDialog"
argument_list|,
literal|"Remove File"
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|// QT_NO_TOOLTIP
name|removeQrcButton
operator|->
name|setText
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"QtResourceEditorDialog"
argument_list|,
literal|"R"
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
name|importQrcButton
operator|->
name|setText
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"QtResourceEditorDialog"
argument_list|,
literal|"I"
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
ifndef|#
directive|ifndef
name|QT_NO_TOOLTIP
name|newResourceButton
operator|->
name|setToolTip
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"QtResourceEditorDialog"
argument_list|,
literal|"New Resource"
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|// QT_NO_TOOLTIP
name|newResourceButton
operator|->
name|setText
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"QtResourceEditorDialog"
argument_list|,
literal|"N"
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
name|addResourceButton
operator|->
name|setText
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"QtResourceEditorDialog"
argument_list|,
literal|"A"
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
ifndef|#
directive|ifndef
name|QT_NO_TOOLTIP
name|removeResourceButton
operator|->
name|setToolTip
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"QtResourceEditorDialog"
argument_list|,
literal|"Remove Resource or File"
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|// QT_NO_TOOLTIP
name|removeResourceButton
operator|->
name|setText
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"QtResourceEditorDialog"
argument_list|,
literal|"R"
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
name|QtResourceEditorDialog
range|:
name|public
name|Ui_QtResourceEditorDialog
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
comment|// QTRESOURCEEDITORDIALOG_H
end_comment
end_unit
