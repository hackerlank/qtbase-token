begin_unit
begin_comment
comment|/******************************************************************************** ** Form generated from reading UI file 'Main_Window.ui' ** ** Created by: Qt User Interface Compiler version 5.0.0 ** ** WARNING! All changes made in this file will be lost when recompiling UI file! ********************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|MAIN_WINDOW_H
end_ifndef
begin_define
DECL|macro|MAIN_WINDOW_H
define|#
directive|define
name|MAIN_WINDOW_H
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
file|<QtWidgets/QHeaderView>
end_include
begin_include
include|#
directive|include
file|<QtWidgets/QMainWindow>
end_include
begin_include
include|#
directive|include
file|<QtWidgets/QMenuBar>
end_include
begin_include
include|#
directive|include
file|<QtWidgets/QStatusBar>
end_include
begin_include
include|#
directive|include
file|<QtWidgets/QWidget>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
name|class
name|Ui_MainWindow
block|{
name|public
label|:
name|QMenuBar
modifier|*
name|menubar
decl_stmt|;
name|QWidget
modifier|*
name|centralwidget
decl_stmt|;
name|QStatusBar
modifier|*
name|statusbar
decl_stmt|;
name|void
name|setupUi
parameter_list|(
name|QMainWindow
modifier|*
name|MainWindow
parameter_list|)
block|{
if|if
condition|(
name|MainWindow
operator|->
name|objectName
argument_list|()
operator|.
name|isEmpty
argument_list|()
condition|)
name|MainWindow
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"MainWindow"
argument_list|)
argument_list|)
expr_stmt|;
name|MainWindow
operator|->
name|resize
argument_list|(
literal|800
argument_list|,
literal|600
argument_list|)
expr_stmt|;
name|menubar
operator|=
name|new
name|QMenuBar
argument_list|(
name|MainWindow
argument_list|)
expr_stmt|;
name|menubar
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"menubar"
argument_list|)
argument_list|)
expr_stmt|;
name|MainWindow
operator|->
name|setMenuBar
argument_list|(
name|menubar
argument_list|)
expr_stmt|;
name|centralwidget
operator|=
name|new
name|QWidget
argument_list|(
name|MainWindow
argument_list|)
expr_stmt|;
name|centralwidget
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"centralwidget"
argument_list|)
argument_list|)
expr_stmt|;
name|MainWindow
operator|->
name|setCentralWidget
argument_list|(
name|centralwidget
argument_list|)
expr_stmt|;
name|statusbar
operator|=
name|new
name|QStatusBar
argument_list|(
name|MainWindow
argument_list|)
expr_stmt|;
name|statusbar
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"statusbar"
argument_list|)
argument_list|)
expr_stmt|;
name|MainWindow
operator|->
name|setStatusBar
argument_list|(
name|statusbar
argument_list|)
expr_stmt|;
name|retranslateUi
argument_list|(
name|MainWindow
argument_list|)
expr_stmt|;
name|QMetaObject
operator|::
name|connectSlotsByName
argument_list|(
name|MainWindow
argument_list|)
expr_stmt|;
block|}
comment|// setupUi
name|void
name|retranslateUi
parameter_list|(
name|QMainWindow
modifier|*
name|MainWindow
parameter_list|)
block|{
name|MainWindow
operator|->
name|setWindowTitle
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"MainWindow"
argument_list|,
literal|"MainWindow"
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
name|MainWindow
range|:
name|public
name|Ui_MainWindow
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
comment|// MAIN_WINDOW_H
end_comment
end_unit
