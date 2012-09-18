begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtWidgets module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qsplashscreen.h"
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_SPLASHSCREEN
end_ifndef
begin_include
include|#
directive|include
file|"qapplication.h"
end_include
begin_include
include|#
directive|include
file|"qdesktopwidget.h"
end_include
begin_include
include|#
directive|include
file|"qpainter.h"
end_include
begin_include
include|#
directive|include
file|"qpixmap.h"
end_include
begin_include
include|#
directive|include
file|"qtextdocument.h"
end_include
begin_include
include|#
directive|include
file|"qtextcursor.h"
end_include
begin_include
include|#
directive|include
file|<QtGui/qwindow.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qdebug.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qelapsedtimer.h>
end_include
begin_include
include|#
directive|include
file|<private/qwidget_p.h>
end_include
begin_ifdef
ifdef|#
directive|ifdef
name|Q_OS_WIN
end_ifdef
begin_include
include|#
directive|include
file|<QtCore/qt_windows.h>
end_include
begin_else
else|#
directive|else
end_else
begin_include
include|#
directive|include
file|<time.h>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_class
DECL|class|QSplashScreenPrivate
class|class
name|QSplashScreenPrivate
super|:
specifier|public
name|QWidgetPrivate
block|{
name|Q_DECLARE_PUBLIC
parameter_list|(
name|QSplashScreen
parameter_list|)
specifier|public
private|:
DECL|member|pixmap
name|QPixmap
name|pixmap
decl_stmt|;
DECL|member|currStatus
name|QString
name|currStatus
decl_stmt|;
DECL|member|currColor
name|QColor
name|currColor
decl_stmt|;
DECL|member|currAlign
name|int
name|currAlign
decl_stmt|;
specifier|inline
name|QSplashScreenPrivate
parameter_list|()
constructor_decl|;
block|}
class|;
end_class
begin_comment
comment|/*!    \class QSplashScreen    \brief The QSplashScreen widget provides a splash screen that can    be shown during application startup.     \inmodule QtWidgets     A splash screen is a widget that is usually displayed when an    application is being started. Splash screens are often used for    applications that have long start up times (e.g. database or    networking applications that take time to establish connections) to    provide the user with feedback that the application is loading.     The splash screen appears in the center of the screen. It may be    useful to add the Qt::WindowStaysOnTopHint to the splash widget's    window flags if you want to keep it above all the other windows on    the desktop.     Some X11 window managers do not support the "stays on top" flag. A    solution is to set up a timer that periodically calls raise() on    the splash screen to simulate the "stays on top" effect.     The most common usage is to show a splash screen before the main    widget is displayed on the screen. This is illustrated in the    following code snippet in which a splash screen is displayed and    some initialization tasks are performed before the application's    main window is shown:     \snippet qsplashscreen/main.cpp 0    \dots    \snippet qsplashscreen/main.cpp 1     The user can hide the splash screen by clicking on it with the    mouse. Since the splash screen is typically displayed before the    event loop has started running, it is necessary to periodically    call QApplication::processEvents() to receive the mouse clicks.     It is sometimes useful to update the splash screen with messages,    for example, announcing connections established or modules loaded    as the application starts up:     \snippet code/src_gui_widgets_qsplashscreen.cpp 0     QSplashScreen supports this with the showMessage() function. If you    wish to do your own drawing you can get a pointer to the pixmap    used in the splash screen with pixmap().  Alternatively, you can    subclass QSplashScreen and reimplement drawContents(). */
end_comment
begin_comment
comment|/*!     Construct a splash screen that will display the \a pixmap.      There should be no need to set the widget flags, \a f, except     perhaps Qt::WindowStaysOnTopHint. */
end_comment
begin_constructor
DECL|function|QSplashScreen
name|QSplashScreen
operator|::
name|QSplashScreen
parameter_list|(
specifier|const
name|QPixmap
modifier|&
name|pixmap
parameter_list|,
name|Qt
operator|::
name|WindowFlags
name|f
parameter_list|)
member_init_list|:
name|QWidget
argument_list|(
operator|*
operator|(
operator|new
name|QSplashScreenPrivate
argument_list|()
operator|)
argument_list|,
literal|0
argument_list|,
name|Qt
operator|::
name|SplashScreen
operator||
name|Qt
operator|::
name|FramelessWindowHint
operator||
name|f
argument_list|)
block|{
name|setPixmap
argument_list|(
name|pixmap
argument_list|)
expr_stmt|;
comment|// Does an implicit repaint
block|}
end_constructor
begin_comment
comment|/*!     \overload      This function allows you to specify a parent for your splashscreen. The     typical use for this constructor is if you have a multiple screens and     prefer to have the splash screen on a different screen than your primary     one. In that case pass the proper desktop() as the \a parent. */
end_comment
begin_constructor
DECL|function|QSplashScreen
name|QSplashScreen
operator|::
name|QSplashScreen
parameter_list|(
name|QWidget
modifier|*
name|parent
parameter_list|,
specifier|const
name|QPixmap
modifier|&
name|pixmap
parameter_list|,
name|Qt
operator|::
name|WindowFlags
name|f
parameter_list|)
member_init_list|:
name|QWidget
argument_list|(
operator|*
operator|new
name|QSplashScreenPrivate
argument_list|,
name|parent
argument_list|,
name|Qt
operator|::
name|SplashScreen
operator||
name|f
argument_list|)
block|{
name|d_func
argument_list|()
operator|->
name|pixmap
operator|=
name|pixmap
expr_stmt|;
name|setPixmap
argument_list|(
name|d_func
argument_list|()
operator|->
name|pixmap
argument_list|)
expr_stmt|;
comment|// Does an implicit repaint
block|}
end_constructor
begin_comment
comment|/*!   Destructor. */
end_comment
begin_destructor
DECL|function|~QSplashScreen
name|QSplashScreen
operator|::
name|~
name|QSplashScreen
parameter_list|()
block|{ }
end_destructor
begin_comment
comment|/*!     \reimp */
end_comment
begin_function
DECL|function|mousePressEvent
name|void
name|QSplashScreen
operator|::
name|mousePressEvent
parameter_list|(
name|QMouseEvent
modifier|*
parameter_list|)
block|{
name|hide
argument_list|()
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     This overrides QWidget::repaint(). It differs from the standard     repaint function in that it also calls QApplication::flush() to     ensure the updates are displayed, even when there is no event loop     present. */
end_comment
begin_function
DECL|function|repaint
name|void
name|QSplashScreen
operator|::
name|repaint
parameter_list|()
block|{
name|QWidget
operator|::
name|repaint
argument_list|()
expr_stmt|;
name|QApplication
operator|::
name|flush
argument_list|()
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     \fn QSplashScreen::messageChanged(const QString&message)      This signal is emitted when the message on the splash screen     changes. \a message is the new message and is a null-string     when the message has been removed.      \sa showMessage(), clearMessage() */
end_comment
begin_comment
comment|/*!     Draws the \a message text onto the splash screen with color \a     color and aligns the text according to the flags in \a alignment.      To make sure the splash screen is repainted immediately, you can     call \l{QCoreApplication}'s     \l{QCoreApplication::}{processEvents()} after the call to     showMessage(). You usually want this to make sure that the message     is kept up to date with what your application is doing (e.g.,     loading files).      \sa Qt::Alignment, clearMessage(), message() */
end_comment
begin_function
DECL|function|showMessage
name|void
name|QSplashScreen
operator|::
name|showMessage
parameter_list|(
specifier|const
name|QString
modifier|&
name|message
parameter_list|,
name|int
name|alignment
parameter_list|,
specifier|const
name|QColor
modifier|&
name|color
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QSplashScreen
argument_list|)
expr_stmt|;
name|d
operator|->
name|currStatus
operator|=
name|message
expr_stmt|;
name|d
operator|->
name|currAlign
operator|=
name|alignment
expr_stmt|;
name|d
operator|->
name|currColor
operator|=
name|color
expr_stmt|;
emit|emit
name|messageChanged
argument_list|(
name|d
operator|->
name|currStatus
argument_list|)
emit|;
name|repaint
argument_list|()
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     \since 5.2      Returns the message that is currently displayed on the splash screen.      \sa showMessage(), clearMessage() */
end_comment
begin_function
DECL|function|message
name|QString
name|QSplashScreen
operator|::
name|message
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QSplashScreen
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|currStatus
return|;
block|}
end_function
begin_comment
comment|/*!     Removes the message being displayed on the splash screen      \sa showMessage()  */
end_comment
begin_function
DECL|function|clearMessage
name|void
name|QSplashScreen
operator|::
name|clearMessage
parameter_list|()
block|{
name|d_func
argument_list|()
operator|->
name|currStatus
operator|.
name|clear
argument_list|()
expr_stmt|;
emit|emit
name|messageChanged
argument_list|(
name|d_func
argument_list|()
operator|->
name|currStatus
argument_list|)
emit|;
name|repaint
argument_list|()
expr_stmt|;
block|}
end_function
begin_comment
comment|// A copy of Qt Test's qWaitForWindowExposed() and qSleep().
end_comment
begin_function
DECL|function|waitForWindowExposed
specifier|inline
specifier|static
name|bool
name|waitForWindowExposed
parameter_list|(
name|QWindow
modifier|*
name|window
parameter_list|,
name|int
name|timeout
init|=
literal|1000
parameter_list|)
block|{
enum|enum
block|{
name|TimeOutMs
init|=
literal|10
block|}
enum|;
name|QElapsedTimer
name|timer
decl_stmt|;
name|timer
operator|.
name|start
argument_list|()
expr_stmt|;
while|while
condition|(
operator|!
name|window
operator|->
name|isExposed
argument_list|()
condition|)
block|{
specifier|const
name|int
name|remaining
init|=
name|timeout
operator|-
name|int
argument_list|(
name|timer
operator|.
name|elapsed
argument_list|()
argument_list|)
decl_stmt|;
if|if
condition|(
name|remaining
operator|<=
literal|0
condition|)
break|break;
name|QCoreApplication
operator|::
name|processEvents
argument_list|(
name|QEventLoop
operator|::
name|AllEvents
argument_list|,
name|remaining
argument_list|)
expr_stmt|;
name|QCoreApplication
operator|::
name|sendPostedEvents
argument_list|(
literal|0
argument_list|,
name|QEvent
operator|::
name|DeferredDelete
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|Q_OS_WIN
name|Sleep
argument_list|(
name|uint
argument_list|(
name|TimeOutMs
argument_list|)
argument_list|)
expr_stmt|;
else|#
directive|else
name|struct
name|timespec
name|ts
init|=
block|{
name|TimeOutMs
operator|/
literal|1000
block|,
operator|(
name|TimeOutMs
operator|%
literal|1000
operator|)
operator|*
literal|1000
operator|*
literal|1000
block|}
decl_stmt|;
name|nanosleep
argument_list|(
operator|&
name|ts
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
return|return
name|window
operator|->
name|isExposed
argument_list|()
return|;
block|}
end_function
begin_comment
comment|/*!     Makes the splash screen wait until the widget \a mainWin is displayed     before calling close() on itself. */
end_comment
begin_function
DECL|function|finish
name|void
name|QSplashScreen
operator|::
name|finish
parameter_list|(
name|QWidget
modifier|*
name|mainWin
parameter_list|)
block|{
if|if
condition|(
name|mainWin
operator|&&
name|mainWin
operator|->
name|windowHandle
argument_list|()
condition|)
name|waitForWindowExposed
argument_list|(
name|mainWin
operator|->
name|windowHandle
argument_list|()
argument_list|)
expr_stmt|;
name|close
argument_list|()
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     Sets the pixmap that will be used as the splash screen's image to     \a pixmap. */
end_comment
begin_function
DECL|function|setPixmap
name|void
name|QSplashScreen
operator|::
name|setPixmap
parameter_list|(
specifier|const
name|QPixmap
modifier|&
name|pixmap
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QSplashScreen
argument_list|)
expr_stmt|;
name|d
operator|->
name|pixmap
operator|=
name|pixmap
expr_stmt|;
name|setAttribute
argument_list|(
name|Qt
operator|::
name|WA_TranslucentBackground
argument_list|,
name|pixmap
operator|.
name|hasAlpha
argument_list|()
argument_list|)
expr_stmt|;
name|QRect
name|r
argument_list|(
name|QPoint
argument_list|()
argument_list|,
name|d
operator|->
name|pixmap
operator|.
name|size
argument_list|()
argument_list|)
decl_stmt|;
name|resize
argument_list|(
name|r
operator|.
name|size
argument_list|()
argument_list|)
expr_stmt|;
name|move
argument_list|(
name|QApplication
operator|::
name|desktop
argument_list|()
operator|->
name|screenGeometry
argument_list|()
operator|.
name|center
argument_list|()
operator|-
name|r
operator|.
name|center
argument_list|()
argument_list|)
expr_stmt|;
if|if
condition|(
name|isVisible
argument_list|()
condition|)
name|repaint
argument_list|()
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     Returns the pixmap that is used in the splash screen. The image     does not have any of the text drawn by showMessage() calls. */
end_comment
begin_function
DECL|function|pixmap
specifier|const
name|QPixmap
name|QSplashScreen
operator|::
name|pixmap
parameter_list|()
specifier|const
block|{
return|return
name|d_func
argument_list|()
operator|->
name|pixmap
return|;
block|}
end_function
begin_comment
comment|/*!     \internal */
end_comment
begin_constructor
DECL|function|QSplashScreenPrivate
specifier|inline
name|QSplashScreenPrivate
operator|::
name|QSplashScreenPrivate
parameter_list|()
member_init_list|:
name|currAlign
argument_list|(
name|Qt
operator|::
name|AlignLeft
argument_list|)
block|{ }
end_constructor
begin_comment
comment|/*!     Draw the contents of the splash screen using painter \a painter.     The default implementation draws the message passed by showMessage().     Reimplement this function if you want to do your own drawing on     the splash screen. */
end_comment
begin_function
DECL|function|drawContents
name|void
name|QSplashScreen
operator|::
name|drawContents
parameter_list|(
name|QPainter
modifier|*
name|painter
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QSplashScreen
argument_list|)
expr_stmt|;
name|painter
operator|->
name|setPen
argument_list|(
name|d
operator|->
name|currColor
argument_list|)
expr_stmt|;
name|QRect
name|r
init|=
name|rect
argument_list|()
operator|.
name|adjusted
argument_list|(
literal|5
argument_list|,
literal|5
argument_list|,
operator|-
literal|5
argument_list|,
operator|-
literal|5
argument_list|)
decl_stmt|;
if|if
condition|(
name|Qt
operator|::
name|mightBeRichText
argument_list|(
name|d
operator|->
name|currStatus
argument_list|)
condition|)
block|{
name|QTextDocument
name|doc
decl_stmt|;
ifdef|#
directive|ifdef
name|QT_NO_TEXTHTMLPARSER
name|doc
operator|.
name|setPlainText
argument_list|(
name|d
operator|->
name|currStatus
argument_list|)
expr_stmt|;
else|#
directive|else
name|doc
operator|.
name|setHtml
argument_list|(
name|d
operator|->
name|currStatus
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|doc
operator|.
name|setTextWidth
argument_list|(
name|r
operator|.
name|width
argument_list|()
argument_list|)
expr_stmt|;
name|QTextCursor
name|cursor
argument_list|(
operator|&
name|doc
argument_list|)
decl_stmt|;
name|cursor
operator|.
name|select
argument_list|(
name|QTextCursor
operator|::
name|Document
argument_list|)
expr_stmt|;
name|QTextBlockFormat
name|fmt
decl_stmt|;
name|fmt
operator|.
name|setAlignment
argument_list|(
name|Qt
operator|::
name|Alignment
argument_list|(
name|d
operator|->
name|currAlign
argument_list|)
argument_list|)
expr_stmt|;
name|cursor
operator|.
name|mergeBlockFormat
argument_list|(
name|fmt
argument_list|)
expr_stmt|;
name|painter
operator|->
name|save
argument_list|()
expr_stmt|;
name|painter
operator|->
name|translate
argument_list|(
name|r
operator|.
name|topLeft
argument_list|()
argument_list|)
expr_stmt|;
name|doc
operator|.
name|drawContents
argument_list|(
name|painter
argument_list|)
expr_stmt|;
name|painter
operator|->
name|restore
argument_list|()
expr_stmt|;
block|}
else|else
block|{
name|painter
operator|->
name|drawText
argument_list|(
name|r
argument_list|,
name|d
operator|->
name|currAlign
argument_list|,
name|d
operator|->
name|currStatus
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_comment
comment|/*! \reimp */
end_comment
begin_function
DECL|function|event
name|bool
name|QSplashScreen
operator|::
name|event
parameter_list|(
name|QEvent
modifier|*
name|e
parameter_list|)
block|{
if|if
condition|(
name|e
operator|->
name|type
argument_list|()
operator|==
name|QEvent
operator|::
name|Paint
condition|)
block|{
name|Q_D
argument_list|(
name|QSplashScreen
argument_list|)
expr_stmt|;
name|QPainter
name|painter
argument_list|(
name|this
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|d
operator|->
name|pixmap
operator|.
name|isNull
argument_list|()
condition|)
name|painter
operator|.
name|drawPixmap
argument_list|(
name|QPoint
argument_list|()
argument_list|,
name|d
operator|->
name|pixmap
argument_list|)
expr_stmt|;
name|drawContents
argument_list|(
operator|&
name|painter
argument_list|)
expr_stmt|;
block|}
return|return
name|QWidget
operator|::
name|event
argument_list|(
name|e
argument_list|)
return|;
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
comment|//QT_NO_SPLASHSCREEN
end_comment
end_unit
