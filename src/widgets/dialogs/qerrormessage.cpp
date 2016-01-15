begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the QtWidgets module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qerrormessage.h"
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_ERRORMESSAGE
end_ifndef
begin_include
include|#
directive|include
file|"qapplication.h"
end_include
begin_include
include|#
directive|include
file|"qcheckbox.h"
end_include
begin_include
include|#
directive|include
file|"qlabel.h"
end_include
begin_include
include|#
directive|include
file|"qlayout.h"
end_include
begin_include
include|#
directive|include
file|"qmessagebox.h"
end_include
begin_include
include|#
directive|include
file|"qpushbutton.h"
end_include
begin_include
include|#
directive|include
file|"qstringlist.h"
end_include
begin_include
include|#
directive|include
file|"qtextedit.h"
end_include
begin_include
include|#
directive|include
file|"qdialog_p.h"
end_include
begin_include
include|#
directive|include
file|"qpixmap.h"
end_include
begin_include
include|#
directive|include
file|"qmetaobject.h"
end_include
begin_include
include|#
directive|include
file|"qthread.h"
end_include
begin_include
include|#
directive|include
file|"qset.h"
end_include
begin_include
include|#
directive|include
file|<queue>
end_include
begin_include
include|#
directive|include
file|<stdio.h>
end_include
begin_include
include|#
directive|include
file|<stdlib.h>
end_include
begin_ifdef
ifdef|#
directive|ifdef
name|Q_OS_WINCE
end_ifdef
begin_function_decl
specifier|extern
name|bool
name|qt_wince_is_mobile
parameter_list|()
function_decl|;
end_function_decl
begin_comment
comment|//defined in qguifunctions_wince.cpp
end_comment
begin_function_decl
specifier|extern
name|bool
name|qt_wince_is_high_dpi
parameter_list|()
function_decl|;
end_function_decl
begin_comment
comment|//defined in qguifunctions_wince.cpp
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_class
DECL|class|QErrorMessagePrivate
class|class
name|QErrorMessagePrivate
super|:
specifier|public
name|QDialogPrivate
block|{
name|Q_DECLARE_PUBLIC
parameter_list|(
name|QErrorMessage
parameter_list|)
specifier|public
private|:
DECL|member|ok
name|QPushButton
modifier|*
name|ok
decl_stmt|;
DECL|member|again
name|QCheckBox
modifier|*
name|again
decl_stmt|;
DECL|member|errors
name|QTextEdit
modifier|*
name|errors
decl_stmt|;
DECL|member|icon
name|QLabel
modifier|*
name|icon
decl_stmt|;
DECL|member|pending
name|std
operator|::
name|queue
argument_list|<
name|QPair
argument_list|<
name|QString
argument_list|,
name|QString
argument_list|>
argument_list|>
name|pending
decl_stmt|;
DECL|member|doNotShow
name|QSet
argument_list|<
name|QString
argument_list|>
name|doNotShow
decl_stmt|;
DECL|member|doNotShowType
name|QSet
argument_list|<
name|QString
argument_list|>
name|doNotShowType
decl_stmt|;
DECL|member|currentMessage
name|QString
name|currentMessage
decl_stmt|;
DECL|member|currentType
name|QString
name|currentType
decl_stmt|;
name|bool
name|isMessageToBeShown
parameter_list|(
specifier|const
name|QString
modifier|&
name|message
parameter_list|,
specifier|const
name|QString
modifier|&
name|type
parameter_list|)
specifier|const
function_decl|;
name|bool
name|nextPending
parameter_list|()
function_decl|;
name|void
name|retranslateStrings
parameter_list|()
function_decl|;
block|}
class|;
end_class
begin_namespace
namespace|namespace
block|{
DECL|class|QErrorMessageTextView
class|class
name|QErrorMessageTextView
super|:
specifier|public
name|QTextEdit
block|{
public|public:
DECL|function|QErrorMessageTextView
name|QErrorMessageTextView
parameter_list|(
name|QWidget
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QTextEdit
argument_list|(
name|parent
argument_list|)
block|{
name|setReadOnly
argument_list|(
literal|true
argument_list|)
expr_stmt|;
block|}
DECL|member|Q_DECL_OVERRIDE
specifier|virtual
name|QSize
name|minimumSizeHint
parameter_list|()
specifier|const
name|Q_DECL_OVERRIDE
function_decl|;
DECL|member|Q_DECL_OVERRIDE
specifier|virtual
name|QSize
name|sizeHint
parameter_list|()
specifier|const
name|Q_DECL_OVERRIDE
function_decl|;
block|}
class|;
block|}
end_namespace
begin_comment
comment|// unnamed namespace
end_comment
begin_function
DECL|function|minimumSizeHint
name|QSize
name|QErrorMessageTextView
operator|::
name|minimumSizeHint
parameter_list|()
specifier|const
block|{
ifdef|#
directive|ifdef
name|Q_OS_WINCE
if|if
condition|(
name|qt_wince_is_mobile
argument_list|()
condition|)
if|if
condition|(
name|qt_wince_is_high_dpi
argument_list|()
condition|)
return|return
name|QSize
argument_list|(
literal|200
argument_list|,
literal|200
argument_list|)
return|;
else|else
return|return
name|QSize
argument_list|(
literal|100
argument_list|,
literal|100
argument_list|)
return|;
else|else
return|return
name|QSize
argument_list|(
literal|70
argument_list|,
literal|70
argument_list|)
return|;
else|#
directive|else
return|return
name|QSize
argument_list|(
literal|50
argument_list|,
literal|50
argument_list|)
return|;
endif|#
directive|endif
block|}
end_function
begin_function
DECL|function|sizeHint
name|QSize
name|QErrorMessageTextView
operator|::
name|sizeHint
parameter_list|()
specifier|const
block|{
ifdef|#
directive|ifdef
name|Q_OS_WINCE
if|if
condition|(
name|qt_wince_is_mobile
argument_list|()
condition|)
if|if
condition|(
name|qt_wince_is_high_dpi
argument_list|()
condition|)
return|return
name|QSize
argument_list|(
literal|400
argument_list|,
literal|200
argument_list|)
return|;
else|else
return|return
name|QSize
argument_list|(
literal|320
argument_list|,
literal|120
argument_list|)
return|;
else|else
return|return
name|QSize
argument_list|(
literal|300
argument_list|,
literal|100
argument_list|)
return|;
else|#
directive|else
return|return
name|QSize
argument_list|(
literal|250
argument_list|,
literal|75
argument_list|)
return|;
endif|#
directive|endif
comment|//Q_OS_WINCE
block|}
end_function
begin_comment
comment|/*!     \class QErrorMessage      \brief The QErrorMessage class provides an error message display dialog.      \ingroup standard-dialog     \inmodule QtWidgets      An error message widget consists of a text label and a checkbox. The     checkbox lets the user control whether the same error message will be     displayed again in the future, typically displaying the text,     "Show this message again" translated into the appropriate local     language.      For production applications, the class can be used to display messages which     the user only needs to see once. To use QErrorMessage like this, you create     the dialog in the usual way, and show it by calling the showMessage() slot or     connecting signals to it.      The static qtHandler() function installs a message handler     using qInstallMessageHandler() and creates a QErrorMessage that displays     qDebug(), qWarning() and qFatal() messages. This is most useful in     environments where no console is available to display warnings and     error messages.      In both cases QErrorMessage will queue pending messages and display     them in order, with each new message being shown as soon as the user     has accepted the previous message. Once the user has specified that a     message is not to be shown again it is automatically skipped, and the     dialog will show the next appropriate message in the queue.      The \l{dialogs/standarddialogs}{Standard Dialogs} example shows     how to use QErrorMessage as well as other built-in Qt dialogs.      \image qerrormessage.png      \sa QMessageBox, QStatusBar::showMessage(), {Standard Dialogs Example} */
end_comment
begin_decl_stmt
DECL|variable|qtMessageHandler
specifier|static
name|QErrorMessage
modifier|*
name|qtMessageHandler
init|=
literal|0
decl_stmt|;
end_decl_stmt
begin_function
DECL|function|deleteStaticcQErrorMessage
specifier|static
name|void
name|deleteStaticcQErrorMessage
parameter_list|()
comment|// post-routine
block|{
if|if
condition|(
name|qtMessageHandler
condition|)
block|{
operator|delete
name|qtMessageHandler
expr_stmt|;
name|qtMessageHandler
operator|=
literal|0
expr_stmt|;
block|}
block|}
end_function
begin_decl_stmt
DECL|variable|metFatal
specifier|static
name|bool
name|metFatal
init|=
literal|false
decl_stmt|;
end_decl_stmt
begin_function
DECL|function|jump
specifier|static
name|void
name|jump
parameter_list|(
name|QtMsgType
name|t
parameter_list|,
specifier|const
name|QMessageLogContext
modifier|&
comment|/*context*/
parameter_list|,
specifier|const
name|QString
modifier|&
name|m
parameter_list|)
block|{
if|if
condition|(
operator|!
name|qtMessageHandler
condition|)
return|return;
name|QString
name|rich
decl_stmt|;
switch|switch
condition|(
name|t
condition|)
block|{
case|case
name|QtDebugMsg
case|:
default|default:
name|rich
operator|=
name|QErrorMessage
operator|::
name|tr
argument_list|(
literal|"Debug Message:"
argument_list|)
expr_stmt|;
break|break;
case|case
name|QtWarningMsg
case|:
name|rich
operator|=
name|QErrorMessage
operator|::
name|tr
argument_list|(
literal|"Warning:"
argument_list|)
expr_stmt|;
break|break;
case|case
name|QtFatalMsg
case|:
name|rich
operator|=
name|QErrorMessage
operator|::
name|tr
argument_list|(
literal|"Fatal Error:"
argument_list|)
expr_stmt|;
block|}
name|rich
operator|=
name|QString
operator|::
name|fromLatin1
argument_list|(
literal|"<p><b>%1</b></p>"
argument_list|)
operator|.
name|arg
argument_list|(
name|rich
argument_list|)
expr_stmt|;
name|rich
operator|+=
name|Qt
operator|::
name|convertFromPlainText
argument_list|(
name|m
argument_list|,
name|Qt
operator|::
name|WhiteSpaceNormal
argument_list|)
expr_stmt|;
comment|// ### work around text engine quirk
if|if
condition|(
name|rich
operator|.
name|endsWith
argument_list|(
name|QLatin1String
argument_list|(
literal|"</p>"
argument_list|)
argument_list|)
condition|)
name|rich
operator|.
name|chop
argument_list|(
literal|4
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|metFatal
condition|)
block|{
if|if
condition|(
name|QThread
operator|::
name|currentThread
argument_list|()
operator|==
name|qApp
operator|->
name|thread
argument_list|()
condition|)
block|{
name|qtMessageHandler
operator|->
name|showMessage
argument_list|(
name|rich
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|QMetaObject
operator|::
name|invokeMethod
argument_list|(
name|qtMessageHandler
argument_list|,
literal|"showMessage"
argument_list|,
name|Qt
operator|::
name|QueuedConnection
argument_list|,
name|Q_ARG
argument_list|(
name|QString
argument_list|,
name|rich
argument_list|)
argument_list|)
expr_stmt|;
block|}
name|metFatal
operator|=
operator|(
name|t
operator|==
name|QtFatalMsg
operator|)
expr_stmt|;
block|}
block|}
end_function
begin_comment
comment|/*!     Constructs and installs an error handler window with the given \a     parent. */
end_comment
begin_constructor
DECL|function|QErrorMessage
name|QErrorMessage
operator|::
name|QErrorMessage
parameter_list|(
name|QWidget
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QDialog
argument_list|(
operator|*
operator|new
name|QErrorMessagePrivate
argument_list|,
name|parent
argument_list|)
block|{
name|Q_D
argument_list|(
name|QErrorMessage
argument_list|)
expr_stmt|;
name|d
operator|->
name|icon
operator|=
operator|new
name|QLabel
argument_list|(
name|this
argument_list|)
expr_stmt|;
name|d
operator|->
name|errors
operator|=
operator|new
name|QErrorMessageTextView
argument_list|(
name|this
argument_list|)
expr_stmt|;
name|d
operator|->
name|again
operator|=
operator|new
name|QCheckBox
argument_list|(
name|this
argument_list|)
expr_stmt|;
name|d
operator|->
name|ok
operator|=
operator|new
name|QPushButton
argument_list|(
name|this
argument_list|)
expr_stmt|;
name|QGridLayout
modifier|*
name|grid
init|=
operator|new
name|QGridLayout
argument_list|(
name|this
argument_list|)
decl_stmt|;
name|connect
argument_list|(
name|d
operator|->
name|ok
argument_list|,
name|SIGNAL
argument_list|(
name|clicked
argument_list|()
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|accept
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|grid
operator|->
name|addWidget
argument_list|(
name|d
operator|->
name|icon
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
name|Qt
operator|::
name|AlignTop
argument_list|)
expr_stmt|;
name|grid
operator|->
name|addWidget
argument_list|(
name|d
operator|->
name|errors
argument_list|,
literal|0
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|grid
operator|->
name|addWidget
argument_list|(
name|d
operator|->
name|again
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|,
name|Qt
operator|::
name|AlignTop
argument_list|)
expr_stmt|;
name|grid
operator|->
name|addWidget
argument_list|(
name|d
operator|->
name|ok
argument_list|,
literal|2
argument_list|,
literal|0
argument_list|,
literal|1
argument_list|,
literal|2
argument_list|,
name|Qt
operator|::
name|AlignCenter
argument_list|)
expr_stmt|;
name|grid
operator|->
name|setColumnStretch
argument_list|(
literal|1
argument_list|,
literal|42
argument_list|)
expr_stmt|;
name|grid
operator|->
name|setRowStretch
argument_list|(
literal|0
argument_list|,
literal|42
argument_list|)
expr_stmt|;
ifndef|#
directive|ifndef
name|QT_NO_MESSAGEBOX
name|d
operator|->
name|icon
operator|->
name|setPixmap
argument_list|(
name|QMessageBox
operator|::
name|standardIcon
argument_list|(
name|QMessageBox
operator|::
name|Information
argument_list|)
argument_list|)
expr_stmt|;
name|d
operator|->
name|icon
operator|->
name|setAlignment
argument_list|(
name|Qt
operator|::
name|AlignHCenter
operator||
name|Qt
operator|::
name|AlignTop
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|d
operator|->
name|again
operator|->
name|setChecked
argument_list|(
literal|true
argument_list|)
expr_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_WINCE
argument_list|)
name|d
operator|->
name|ok
operator|->
name|setFixedSize
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|d
operator|->
name|ok
operator|->
name|setFocus
argument_list|()
expr_stmt|;
name|d
operator|->
name|retranslateStrings
argument_list|()
expr_stmt|;
block|}
end_constructor
begin_comment
comment|/*!     Destroys the error message dialog. */
end_comment
begin_destructor
DECL|function|~QErrorMessage
name|QErrorMessage
operator|::
name|~
name|QErrorMessage
parameter_list|()
block|{
if|if
condition|(
name|this
operator|==
name|qtMessageHandler
condition|)
block|{
name|qtMessageHandler
operator|=
literal|0
expr_stmt|;
name|QtMessageHandler
name|tmp
init|=
name|qInstallMessageHandler
argument_list|(
literal|0
argument_list|)
decl_stmt|;
comment|// in case someone else has later stuck in another...
if|if
condition|(
name|tmp
operator|!=
name|jump
condition|)
name|qInstallMessageHandler
argument_list|(
name|tmp
argument_list|)
expr_stmt|;
block|}
block|}
end_destructor
begin_comment
comment|/*! \reimp */
end_comment
begin_function
DECL|function|done
name|void
name|QErrorMessage
operator|::
name|done
parameter_list|(
name|int
name|a
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QErrorMessage
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|d
operator|->
name|again
operator|->
name|isChecked
argument_list|()
condition|)
block|{
if|if
condition|(
name|d
operator|->
name|currentType
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
if|if
condition|(
operator|!
name|d
operator|->
name|currentMessage
operator|.
name|isEmpty
argument_list|()
condition|)
name|d
operator|->
name|doNotShow
operator|.
name|insert
argument_list|(
name|d
operator|->
name|currentMessage
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|d
operator|->
name|doNotShowType
operator|.
name|insert
argument_list|(
name|d
operator|->
name|currentType
argument_list|)
expr_stmt|;
block|}
block|}
name|d
operator|->
name|currentMessage
operator|.
name|clear
argument_list|()
expr_stmt|;
name|d
operator|->
name|currentType
operator|.
name|clear
argument_list|()
expr_stmt|;
if|if
condition|(
operator|!
name|d
operator|->
name|nextPending
argument_list|()
condition|)
block|{
name|QDialog
operator|::
name|done
argument_list|(
name|a
argument_list|)
expr_stmt|;
if|if
condition|(
name|this
operator|==
name|qtMessageHandler
operator|&&
name|metFatal
condition|)
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_comment
comment|/*!     Returns a pointer to a QErrorMessage object that outputs the     default Qt messages. This function creates such an object, if there     isn't one already. */
end_comment
begin_function
DECL|function|qtHandler
name|QErrorMessage
modifier|*
name|QErrorMessage
operator|::
name|qtHandler
parameter_list|()
block|{
if|if
condition|(
operator|!
name|qtMessageHandler
condition|)
block|{
name|qtMessageHandler
operator|=
operator|new
name|QErrorMessage
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|qAddPostRoutine
argument_list|(
name|deleteStaticcQErrorMessage
argument_list|)
expr_stmt|;
comment|// clean up
name|qtMessageHandler
operator|->
name|setWindowTitle
argument_list|(
name|QApplication
operator|::
name|applicationName
argument_list|()
argument_list|)
expr_stmt|;
name|qInstallMessageHandler
argument_list|(
name|jump
argument_list|)
expr_stmt|;
block|}
return|return
name|qtMessageHandler
return|;
block|}
end_function
begin_comment
comment|/*! \internal */
end_comment
begin_function
DECL|function|isMessageToBeShown
name|bool
name|QErrorMessagePrivate
operator|::
name|isMessageToBeShown
parameter_list|(
specifier|const
name|QString
modifier|&
name|message
parameter_list|,
specifier|const
name|QString
modifier|&
name|type
parameter_list|)
specifier|const
block|{
return|return
operator|!
name|message
operator|.
name|isEmpty
argument_list|()
operator|&&
operator|(
name|type
operator|.
name|isEmpty
argument_list|()
condition|?
operator|!
name|doNotShow
operator|.
name|contains
argument_list|(
name|message
argument_list|)
else|:
operator|!
name|doNotShowType
operator|.
name|contains
argument_list|(
name|type
argument_list|)
operator|)
return|;
block|}
end_function
begin_function
DECL|function|nextPending
name|bool
name|QErrorMessagePrivate
operator|::
name|nextPending
parameter_list|()
block|{
while|while
condition|(
operator|!
name|pending
operator|.
name|empty
argument_list|()
condition|)
block|{
name|QPair
argument_list|<
name|QString
argument_list|,
name|QString
argument_list|>
modifier|&
name|pendingMessage
init|=
name|pending
operator|.
name|front
argument_list|()
decl_stmt|;
name|QString
name|message
init|=
name|qMove
argument_list|(
name|pendingMessage
operator|.
name|first
argument_list|)
decl_stmt|;
name|QString
name|type
init|=
name|qMove
argument_list|(
name|pendingMessage
operator|.
name|second
argument_list|)
decl_stmt|;
name|pending
operator|.
name|pop
argument_list|()
expr_stmt|;
if|if
condition|(
name|isMessageToBeShown
argument_list|(
name|message
argument_list|,
name|type
argument_list|)
condition|)
block|{
ifndef|#
directive|ifndef
name|QT_NO_TEXTHTMLPARSER
name|errors
operator|->
name|setHtml
argument_list|(
name|message
argument_list|)
expr_stmt|;
else|#
directive|else
name|errors
operator|->
name|setPlainText
argument_list|(
name|message
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|currentMessage
operator|=
name|qMove
argument_list|(
name|message
argument_list|)
expr_stmt|;
name|currentType
operator|=
name|qMove
argument_list|(
name|type
argument_list|)
expr_stmt|;
return|return
literal|true
return|;
block|}
block|}
return|return
literal|false
return|;
block|}
end_function
begin_comment
comment|/*!     Shows the given message, \a message, and returns immediately. If the user     has requested for the message not to be shown again, this function does     nothing.      Normally, the message is displayed immediately. However, if there are     pending messages, it will be queued to be displayed later. */
end_comment
begin_function
DECL|function|showMessage
name|void
name|QErrorMessage
operator|::
name|showMessage
parameter_list|(
specifier|const
name|QString
modifier|&
name|message
parameter_list|)
block|{
name|showMessage
argument_list|(
name|message
argument_list|,
name|QString
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     \since 4.5     \overload      Shows the given message, \a message, and returns immediately. If the user     has requested for messages of type, \a type, not to be shown again, this     function does nothing.      Normally, the message is displayed immediately. However, if there are     pending messages, it will be queued to be displayed later.      \sa showMessage() */
end_comment
begin_function
DECL|function|showMessage
name|void
name|QErrorMessage
operator|::
name|showMessage
parameter_list|(
specifier|const
name|QString
modifier|&
name|message
parameter_list|,
specifier|const
name|QString
modifier|&
name|type
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QErrorMessage
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|d
operator|->
name|isMessageToBeShown
argument_list|(
name|message
argument_list|,
name|type
argument_list|)
condition|)
return|return;
name|d
operator|->
name|pending
operator|.
name|push
argument_list|(
name|qMakePair
argument_list|(
name|message
argument_list|,
name|type
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|isVisible
argument_list|()
operator|&&
name|d
operator|->
name|nextPending
argument_list|()
condition|)
name|show
argument_list|()
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     \reimp */
end_comment
begin_function
DECL|function|changeEvent
name|void
name|QErrorMessage
operator|::
name|changeEvent
parameter_list|(
name|QEvent
modifier|*
name|e
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QErrorMessage
argument_list|)
expr_stmt|;
if|if
condition|(
name|e
operator|->
name|type
argument_list|()
operator|==
name|QEvent
operator|::
name|LanguageChange
condition|)
block|{
name|d
operator|->
name|retranslateStrings
argument_list|()
expr_stmt|;
block|}
name|QDialog
operator|::
name|changeEvent
argument_list|(
name|e
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|retranslateStrings
name|void
name|QErrorMessagePrivate
operator|::
name|retranslateStrings
parameter_list|()
block|{
name|again
operator|->
name|setText
argument_list|(
name|QErrorMessage
operator|::
name|tr
argument_list|(
literal|"&Show this message again"
argument_list|)
argument_list|)
expr_stmt|;
name|ok
operator|->
name|setText
argument_list|(
name|QErrorMessage
operator|::
name|tr
argument_list|(
literal|"&OK"
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_ERRORMESSAGE
end_comment
end_unit
