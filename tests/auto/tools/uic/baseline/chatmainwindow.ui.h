begin_unit
begin_comment
comment|/******************************************************************************** ** Form generated from reading UI file 'chatmainwindow.ui' ** ** Created: Fri Sep 4 10:17:12 2009 **      by: Qt User Interface Compiler version 4.6.0 ** ** WARNING! All changes made in this file will be lost when recompiling UI file! ********************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|CHATMAINWINDOW_H
end_ifndef
begin_define
DECL|macro|CHATMAINWINDOW_H
define|#
directive|define
name|CHATMAINWINDOW_H
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
file|<QtWidgets/QMainWindow>
end_include
begin_include
include|#
directive|include
file|<QtWidgets/QMenu>
end_include
begin_include
include|#
directive|include
file|<QtWidgets/QMenuBar>
end_include
begin_include
include|#
directive|include
file|<QtWidgets/QPushButton>
end_include
begin_include
include|#
directive|include
file|<QtWidgets/QStatusBar>
end_include
begin_include
include|#
directive|include
file|<QtWidgets/QTextBrowser>
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
name|Ui_ChatMainWindow
block|{
name|public
label|:
name|QAction
modifier|*
name|actionQuit
decl_stmt|;
name|QAction
modifier|*
name|actionAboutQt
decl_stmt|;
name|QAction
modifier|*
name|actionChangeNickname
decl_stmt|;
name|QWidget
modifier|*
name|centralwidget
decl_stmt|;
name|QHBoxLayout
modifier|*
name|hboxLayout
decl_stmt|;
name|QVBoxLayout
modifier|*
name|vboxLayout
decl_stmt|;
name|QTextBrowser
modifier|*
name|chatHistory
decl_stmt|;
name|QHBoxLayout
modifier|*
name|hboxLayout1
decl_stmt|;
name|QLabel
modifier|*
name|label
decl_stmt|;
name|QLineEdit
modifier|*
name|messageLineEdit
decl_stmt|;
name|QPushButton
modifier|*
name|sendButton
decl_stmt|;
name|QMenuBar
modifier|*
name|menubar
decl_stmt|;
name|QMenu
modifier|*
name|menuQuit
decl_stmt|;
name|QMenu
modifier|*
name|menuFile
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
name|ChatMainWindow
parameter_list|)
block|{
if|if
condition|(
name|ChatMainWindow
operator|->
name|objectName
argument_list|()
operator|.
name|isEmpty
argument_list|()
condition|)
name|ChatMainWindow
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"ChatMainWindow"
argument_list|)
argument_list|)
expr_stmt|;
name|ChatMainWindow
operator|->
name|resize
argument_list|(
literal|800
argument_list|,
literal|600
argument_list|)
expr_stmt|;
name|actionQuit
operator|=
name|new
name|QAction
argument_list|(
name|ChatMainWindow
argument_list|)
expr_stmt|;
name|actionQuit
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"actionQuit"
argument_list|)
argument_list|)
expr_stmt|;
name|actionAboutQt
operator|=
name|new
name|QAction
argument_list|(
name|ChatMainWindow
argument_list|)
expr_stmt|;
name|actionAboutQt
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"actionAboutQt"
argument_list|)
argument_list|)
expr_stmt|;
name|actionChangeNickname
operator|=
name|new
name|QAction
argument_list|(
name|ChatMainWindow
argument_list|)
expr_stmt|;
name|actionChangeNickname
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"actionChangeNickname"
argument_list|)
argument_list|)
expr_stmt|;
name|centralwidget
operator|=
name|new
name|QWidget
argument_list|(
name|ChatMainWindow
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
name|hboxLayout
operator|=
name|new
name|QHBoxLayout
argument_list|(
name|centralwidget
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
ifndef|#
directive|ifndef
name|Q_OS_MAC
name|hboxLayout
operator|->
name|setContentsMargins
argument_list|(
literal|9
argument_list|,
literal|9
argument_list|,
literal|9
argument_list|,
literal|9
argument_list|)
expr_stmt|;
endif|#
directive|endif
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
name|vboxLayout
operator|=
name|new
name|QVBoxLayout
argument_list|()
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
ifndef|#
directive|ifndef
name|Q_OS_MAC
name|vboxLayout
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
endif|#
directive|endif
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
name|chatHistory
operator|=
name|new
name|QTextBrowser
argument_list|(
name|centralwidget
argument_list|)
expr_stmt|;
name|chatHistory
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"chatHistory"
argument_list|)
argument_list|)
expr_stmt|;
name|chatHistory
operator|->
name|setAcceptDrops
argument_list|(
name|false
argument_list|)
expr_stmt|;
name|chatHistory
operator|->
name|setAcceptRichText
argument_list|(
name|true
argument_list|)
expr_stmt|;
name|vboxLayout
operator|->
name|addWidget
argument_list|(
name|chatHistory
argument_list|)
expr_stmt|;
name|hboxLayout1
operator|=
name|new
name|QHBoxLayout
argument_list|()
expr_stmt|;
ifndef|#
directive|ifndef
name|Q_OS_MAC
name|hboxLayout1
operator|->
name|setSpacing
argument_list|(
literal|6
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|hboxLayout1
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
name|label
operator|=
name|new
name|QLabel
argument_list|(
name|centralwidget
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
name|hboxLayout1
operator|->
name|addWidget
argument_list|(
name|label
argument_list|)
expr_stmt|;
name|messageLineEdit
operator|=
name|new
name|QLineEdit
argument_list|(
name|centralwidget
argument_list|)
expr_stmt|;
name|messageLineEdit
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"messageLineEdit"
argument_list|)
argument_list|)
expr_stmt|;
name|hboxLayout1
operator|->
name|addWidget
argument_list|(
name|messageLineEdit
argument_list|)
expr_stmt|;
name|sendButton
operator|=
name|new
name|QPushButton
argument_list|(
name|centralwidget
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
name|QSizePolicy
name|sizePolicy
argument_list|(
name|static_cast
operator|<
name|QSizePolicy
operator|::
name|Policy
operator|>
operator|(
literal|1
operator|)
argument_list|,
name|static_cast
operator|<
name|QSizePolicy
operator|::
name|Policy
operator|>
operator|(
literal|0
operator|)
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
name|sendButton
operator|->
name|sizePolicy
argument_list|()
operator|.
name|hasHeightForWidth
argument_list|()
argument_list|)
expr_stmt|;
name|sendButton
operator|->
name|setSizePolicy
argument_list|(
name|sizePolicy
argument_list|)
expr_stmt|;
name|hboxLayout1
operator|->
name|addWidget
argument_list|(
name|sendButton
argument_list|)
expr_stmt|;
name|vboxLayout
operator|->
name|addLayout
argument_list|(
name|hboxLayout1
argument_list|)
expr_stmt|;
name|hboxLayout
operator|->
name|addLayout
argument_list|(
name|vboxLayout
argument_list|)
expr_stmt|;
name|ChatMainWindow
operator|->
name|setCentralWidget
argument_list|(
name|centralwidget
argument_list|)
expr_stmt|;
name|menubar
operator|=
name|new
name|QMenuBar
argument_list|(
name|ChatMainWindow
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
name|menubar
operator|->
name|setGeometry
argument_list|(
name|QRect
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|800
argument_list|,
literal|31
argument_list|)
argument_list|)
expr_stmt|;
name|menuQuit
operator|=
name|new
name|QMenu
argument_list|(
name|menubar
argument_list|)
expr_stmt|;
name|menuQuit
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"menuQuit"
argument_list|)
argument_list|)
expr_stmt|;
name|menuFile
operator|=
name|new
name|QMenu
argument_list|(
name|menubar
argument_list|)
expr_stmt|;
name|menuFile
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"menuFile"
argument_list|)
argument_list|)
expr_stmt|;
name|ChatMainWindow
operator|->
name|setMenuBar
argument_list|(
name|menubar
argument_list|)
expr_stmt|;
name|statusbar
operator|=
name|new
name|QStatusBar
argument_list|(
name|ChatMainWindow
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
name|ChatMainWindow
operator|->
name|setStatusBar
argument_list|(
name|statusbar
argument_list|)
expr_stmt|;
ifndef|#
directive|ifndef
name|QT_NO_SHORTCUT
name|label
operator|->
name|setBuddy
argument_list|(
name|messageLineEdit
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|// QT_NO_SHORTCUT
name|QWidget
operator|::
name|setTabOrder
argument_list|(
name|chatHistory
argument_list|,
name|messageLineEdit
argument_list|)
expr_stmt|;
name|QWidget
operator|::
name|setTabOrder
argument_list|(
name|messageLineEdit
argument_list|,
name|sendButton
argument_list|)
expr_stmt|;
name|menubar
operator|->
name|addAction
argument_list|(
name|menuFile
operator|->
name|menuAction
argument_list|()
argument_list|)
expr_stmt|;
name|menubar
operator|->
name|addAction
argument_list|(
name|menuQuit
operator|->
name|menuAction
argument_list|()
argument_list|)
expr_stmt|;
name|menuQuit
operator|->
name|addAction
argument_list|(
name|actionAboutQt
argument_list|)
expr_stmt|;
name|menuFile
operator|->
name|addAction
argument_list|(
name|actionChangeNickname
argument_list|)
expr_stmt|;
name|menuFile
operator|->
name|addSeparator
argument_list|()
expr_stmt|;
name|menuFile
operator|->
name|addAction
argument_list|(
name|actionQuit
argument_list|)
expr_stmt|;
name|retranslateUi
argument_list|(
name|ChatMainWindow
argument_list|)
expr_stmt|;
name|QObject
operator|::
name|connect
argument_list|(
name|messageLineEdit
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
name|QObject
operator|::
name|connect
argument_list|(
name|actionQuit
argument_list|,
name|SIGNAL
argument_list|(
name|triggered
argument_list|(
name|bool
argument_list|)
argument_list|)
argument_list|,
name|ChatMainWindow
argument_list|,
name|SLOT
argument_list|(
name|close
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|QMetaObject
operator|::
name|connectSlotsByName
argument_list|(
name|ChatMainWindow
argument_list|)
expr_stmt|;
block|}
comment|// setupUi
name|void
name|retranslateUi
parameter_list|(
name|QMainWindow
modifier|*
name|ChatMainWindow
parameter_list|)
block|{
name|ChatMainWindow
operator|->
name|setWindowTitle
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"ChatMainWindow"
argument_list|,
literal|"QtDBus Chat"
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
name|actionQuit
operator|->
name|setText
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"ChatMainWindow"
argument_list|,
literal|"Quit"
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
name|actionQuit
operator|->
name|setShortcut
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"ChatMainWindow"
argument_list|,
literal|"Ctrl+Q"
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
name|actionAboutQt
operator|->
name|setText
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"ChatMainWindow"
argument_list|,
literal|"About Qt..."
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
name|actionChangeNickname
operator|->
name|setText
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"ChatMainWindow"
argument_list|,
literal|"Change nickname..."
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
name|actionChangeNickname
operator|->
name|setShortcut
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"ChatMainWindow"
argument_list|,
literal|"Ctrl+N"
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
ifndef|#
directive|ifndef
name|QT_NO_TOOLTIP
name|chatHistory
operator|->
name|setToolTip
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"ChatMainWindow"
argument_list|,
literal|"Messages sent and received from other users"
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|// QT_NO_TOOLTIP
name|label
operator|->
name|setText
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"ChatMainWindow"
argument_list|,
literal|"Message:"
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
ifndef|#
directive|ifndef
name|QT_NO_TOOLTIP
name|sendButton
operator|->
name|setToolTip
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"ChatMainWindow"
argument_list|,
literal|"Sends a message to other people"
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|// QT_NO_TOOLTIP
ifndef|#
directive|ifndef
name|QT_NO_WHATSTHIS
name|sendButton
operator|->
name|setWhatsThis
argument_list|(
name|QString
argument_list|()
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|// QT_NO_WHATSTHIS
name|sendButton
operator|->
name|setText
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"ChatMainWindow"
argument_list|,
literal|"Send"
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
name|menuQuit
operator|->
name|setTitle
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"ChatMainWindow"
argument_list|,
literal|"Help"
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
name|menuFile
operator|->
name|setTitle
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"ChatMainWindow"
argument_list|,
literal|"File"
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
name|ChatMainWindow
range|:
name|public
name|Ui_ChatMainWindow
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
comment|// CHATMAINWINDOW_H
end_comment
end_unit
