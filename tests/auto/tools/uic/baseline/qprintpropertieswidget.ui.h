begin_unit
begin_comment
comment|/******************************************************************************** ** Form generated from reading UI file 'qprintpropertieswidget.ui' ** ** Created by: Qt User Interface Compiler version 5.0.0 ** ** WARNING! All changes made in this file will be lost when recompiling UI file! ********************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QPRINTPROPERTIESWIDGET_H
end_ifndef
begin_define
DECL|macro|QPRINTPROPERTIESWIDGET_H
define|#
directive|define
name|QPRINTPROPERTIESWIDGET_H
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
file|<QtWidgets/QTabWidget>
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
begin_include
include|#
directive|include
file|"qpagesetupdialog_unix_p.h"
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
name|class
name|Ui_QPrintPropertiesWidget
block|{
name|public
label|:
name|QVBoxLayout
modifier|*
name|verticalLayout_4
decl_stmt|;
name|QTabWidget
modifier|*
name|tabs
decl_stmt|;
name|QWidget
modifier|*
name|tabPage
decl_stmt|;
name|QHBoxLayout
modifier|*
name|horizontalLayout
decl_stmt|;
name|QPageSetupWidget
modifier|*
name|pageSetup
decl_stmt|;
name|QWidget
modifier|*
name|cupsPropertiesPage
decl_stmt|;
name|QHBoxLayout
modifier|*
name|horizontalLayout_2
decl_stmt|;
name|QTreeView
modifier|*
name|treeView
decl_stmt|;
name|void
name|setupUi
parameter_list|(
name|QWidget
modifier|*
name|QPrintPropertiesWidget
parameter_list|)
block|{
if|if
condition|(
name|QPrintPropertiesWidget
operator|->
name|objectName
argument_list|()
operator|.
name|isEmpty
argument_list|()
condition|)
name|QPrintPropertiesWidget
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"QPrintPropertiesWidget"
argument_list|)
argument_list|)
expr_stmt|;
name|QPrintPropertiesWidget
operator|->
name|resize
argument_list|(
literal|396
argument_list|,
literal|288
argument_list|)
expr_stmt|;
name|verticalLayout_4
operator|=
name|new
name|QVBoxLayout
argument_list|(
name|QPrintPropertiesWidget
argument_list|)
expr_stmt|;
name|verticalLayout_4
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
name|verticalLayout_4
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"verticalLayout_4"
argument_list|)
argument_list|)
expr_stmt|;
name|tabs
operator|=
name|new
name|QTabWidget
argument_list|(
name|QPrintPropertiesWidget
argument_list|)
expr_stmt|;
name|tabs
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"tabs"
argument_list|)
argument_list|)
expr_stmt|;
name|tabPage
operator|=
name|new
name|QWidget
argument_list|()
expr_stmt|;
name|tabPage
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"tabPage"
argument_list|)
argument_list|)
expr_stmt|;
name|tabPage
operator|->
name|setGeometry
argument_list|(
name|QRect
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|392
argument_list|,
literal|261
argument_list|)
argument_list|)
expr_stmt|;
name|horizontalLayout
operator|=
name|new
name|QHBoxLayout
argument_list|(
name|tabPage
argument_list|)
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
name|pageSetup
operator|=
name|new
name|QPageSetupWidget
argument_list|(
name|tabPage
argument_list|)
expr_stmt|;
name|pageSetup
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"pageSetup"
argument_list|)
argument_list|)
expr_stmt|;
name|horizontalLayout
operator|->
name|addWidget
argument_list|(
name|pageSetup
argument_list|)
expr_stmt|;
name|tabs
operator|->
name|addTab
argument_list|(
name|tabPage
argument_list|,
name|QString
argument_list|()
argument_list|)
expr_stmt|;
name|cupsPropertiesPage
operator|=
name|new
name|QWidget
argument_list|()
expr_stmt|;
name|cupsPropertiesPage
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"cupsPropertiesPage"
argument_list|)
argument_list|)
expr_stmt|;
name|horizontalLayout_2
operator|=
name|new
name|QHBoxLayout
argument_list|(
name|cupsPropertiesPage
argument_list|)
expr_stmt|;
name|horizontalLayout_2
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"horizontalLayout_2"
argument_list|)
argument_list|)
expr_stmt|;
name|treeView
operator|=
name|new
name|QTreeView
argument_list|(
name|cupsPropertiesPage
argument_list|)
expr_stmt|;
name|treeView
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"treeView"
argument_list|)
argument_list|)
expr_stmt|;
name|treeView
operator|->
name|setAlternatingRowColors
argument_list|(
name|true
argument_list|)
expr_stmt|;
name|horizontalLayout_2
operator|->
name|addWidget
argument_list|(
name|treeView
argument_list|)
expr_stmt|;
name|tabs
operator|->
name|addTab
argument_list|(
name|cupsPropertiesPage
argument_list|,
name|QString
argument_list|()
argument_list|)
expr_stmt|;
name|verticalLayout_4
operator|->
name|addWidget
argument_list|(
name|tabs
argument_list|)
expr_stmt|;
name|retranslateUi
argument_list|(
name|QPrintPropertiesWidget
argument_list|)
expr_stmt|;
name|tabs
operator|->
name|setCurrentIndex
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|QMetaObject
operator|::
name|connectSlotsByName
argument_list|(
name|QPrintPropertiesWidget
argument_list|)
expr_stmt|;
block|}
comment|// setupUi
name|void
name|retranslateUi
parameter_list|(
name|QWidget
modifier|*
name|QPrintPropertiesWidget
parameter_list|)
block|{
name|QPrintPropertiesWidget
operator|->
name|setWindowTitle
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"QPrintPropertiesWidget"
argument_list|,
literal|"Form"
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
name|tabs
operator|->
name|setTabText
argument_list|(
name|tabs
operator|->
name|indexOf
argument_list|(
name|tabPage
argument_list|)
argument_list|,
name|QApplication
operator|::
name|translate
argument_list|(
literal|"QPrintPropertiesWidget"
argument_list|,
literal|"Page"
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
name|tabs
operator|->
name|setTabText
argument_list|(
name|tabs
operator|->
name|indexOf
argument_list|(
name|cupsPropertiesPage
argument_list|)
argument_list|,
name|QApplication
operator|::
name|translate
argument_list|(
literal|"QPrintPropertiesWidget"
argument_list|,
literal|"Advanced"
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
name|QPrintPropertiesWidget
range|:
name|public
name|Ui_QPrintPropertiesWidget
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
comment|// QPRINTPROPERTIESWIDGET_H
end_comment
end_unit
