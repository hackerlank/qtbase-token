begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qtimer.h"
end_include
begin_include
include|#
directive|include
file|"qabstracteventdispatcher.h"
end_include
begin_include
include|#
directive|include
file|"qcoreapplication.h"
end_include
begin_include
include|#
directive|include
file|"qobject_p.h"
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
comment|/*!     \class QTimer     \brief The QTimer class provides repetitive and single-shot timers.      \ingroup events       The QTimer class provides a high-level programming interface for     timers. To use it, create a QTimer, connect its timeout() signal     to the appropriate slots, and call start(). From then on it will     emit the timeout() signal at constant intervals.      Example for a one second (1000 millisecond) timer (from the     \l{widgets/analogclock}{Analog Clock} example):      \snippet examples/widgets/analogclock/analogclock.cpp 4     \snippet examples/widgets/analogclock/analogclock.cpp 5     \snippet examples/widgets/analogclock/analogclock.cpp 6      From then on, the \c update() slot is called every second.      You can set a timer to time out only once by calling     setSingleShot(true). You can also use the static     QTimer::singleShot() function to call a slot after a specified     interval:      \snippet doc/src/snippets/timers/timers.cpp 3      In multithreaded applications, you can use QTimer in any thread     that has an event loop. To start an event loop from a non-GUI     thread, use QThread::exec(). Qt uses the timer's     \l{QObject::thread()}{thread affinity} to determine which thread     will emit the \l{QTimer::}{timeout()} signal. Because of this, you     must start and stop the timer in its thread; it is not possible to     start a timer from another thread.      As a special case, a QTimer with a timeout of 0 will time out as     soon as all the events in the window system's event queue have     been processed. This can be used to do heavy work while providing     a snappy user interface:      \snippet doc/src/snippets/timers/timers.cpp 4     \snippet doc/src/snippets/timers/timers.cpp 5     \snippet doc/src/snippets/timers/timers.cpp 6      \c processOneThing() will from then on be called repeatedly. It     should be written in such a way that it always returns quickly     (typically after processing one data item) so that Qt can deliver     events to widgets and stop the timer as soon as it has done all     its work. This is the traditional way of implementing heavy work     in GUI applications; multithreading is now becoming available on     more and more platforms, and we expect that zero-millisecond     QTimers will gradually be replaced by \l{QThread}s.      \section1 Accuracy and Timer Resolution      Timers will never time out earlier than the specified timeout value     and they are not guaranteed to time out at the exact value specified.     In many situations, they may time out late by a period of time that     depends on the accuracy of the system timers.      The accuracy of timers depends on the underlying operating system     and hardware. Most platforms support a resolution of 1 millisecond,     though the accuracy of the timer will not equal this resolution     in many real-world situations.      If Qt is unable to deliver the requested number of timer clicks,     it will silently discard some.      \section1 Alternatives to QTimer      An alternative to using QTimer is to call QObject::startTimer()     for your object and reimplement the QObject::timerEvent() event     handler in your class (which must inherit QObject). The     disadvantage is that timerEvent() does not support such     high-level features as single-shot timers or signals.      Another alternative to using QTimer is to use QBasicTimer. It is     typically less cumbersome than using QObject::startTimer()     directly. See \l{Timers} for an overview of all three approaches.      Some operating systems limit the number of timers that may be     used; Qt tries to work around these limitations.      \sa QBasicTimer, QTimerEvent, QObject::timerEvent(), Timers,         {Analog Clock Example}, {Wiggly Example} */
DECL|variable|INV_TIMER
specifier|static
specifier|const
name|int
name|INV_TIMER
init|=
operator|-
literal|1
decl_stmt|;
end_decl_stmt
begin_comment
DECL|variable|INV_TIMER
comment|// invalid timer id
end_comment
begin_comment
comment|/*!     Constructs a timer with the given \a parent. */
end_comment
begin_constructor
DECL|function|QTimer
name|QTimer
operator|::
name|QTimer
parameter_list|(
name|QObject
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QObject
argument_list|(
name|parent
argument_list|)
member_init_list|,
name|id
argument_list|(
name|INV_TIMER
argument_list|)
member_init_list|,
name|inter
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|del
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|single
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|nulltimer
argument_list|(
literal|0
argument_list|)
block|{ }
end_constructor
begin_ifdef
ifdef|#
directive|ifdef
name|QT3_SUPPORT
end_ifdef
begin_comment
comment|/*!     Constructs a timer called \a name, with a \a parent. */
end_comment
begin_constructor
DECL|function|QTimer
name|QTimer
operator|::
name|QTimer
parameter_list|(
name|QObject
modifier|*
name|parent
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|)
member_init_list|:
name|QObject
argument_list|(
name|parent
argument_list|)
member_init_list|,
name|id
argument_list|(
name|INV_TIMER
argument_list|)
member_init_list|,
name|single
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|nulltimer
argument_list|(
literal|0
argument_list|)
block|{
name|setObjectName
argument_list|(
name|QString
operator|::
name|fromAscii
argument_list|(
name|name
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/*!     Destroys the timer. */
end_comment
begin_destructor
DECL|function|~QTimer
name|QTimer
operator|::
name|~
name|QTimer
parameter_list|()
block|{
if|if
condition|(
name|id
operator|!=
name|INV_TIMER
condition|)
comment|// stop running timer
name|stop
argument_list|()
expr_stmt|;
block|}
end_destructor
begin_comment
comment|/*!     \fn void QTimer::timeout()      This signal is emitted when the timer times out.      \sa interval, start(), stop() */
end_comment
begin_comment
comment|/*!     \property QTimer::active     \since 4.3      This boolean property is true if the timer is running; otherwise     false. */
end_comment
begin_comment
comment|/*!     \fn bool QTimer::isActive() const      Returns true if the timer is running (pending); otherwise returns     false. */
end_comment
begin_comment
comment|/*!     \fn int QTimer::timerId() const      Returns the ID of the timer if the timer is running; otherwise returns     -1. */
end_comment
begin_comment
comment|/*! \overload start()      Starts or restarts the timer with the timeout specified in \l interval.      If the timer is already running, it will be     \l{QTimer::stop()}{stopped} and restarted.      If \l singleShot is true, the timer will be activated only once. */
end_comment
begin_function
DECL|function|start
name|void
name|QTimer
operator|::
name|start
parameter_list|()
block|{
if|if
condition|(
name|id
operator|!=
name|INV_TIMER
condition|)
comment|// stop running timer
name|stop
argument_list|()
expr_stmt|;
name|nulltimer
operator|=
operator|(
operator|!
name|inter
operator|&&
name|single
operator|)
expr_stmt|;
name|id
operator|=
name|QObject
operator|::
name|startTimer
argument_list|(
name|inter
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     Starts or restarts the timer with a timeout interval of \a msec     milliseconds.      If the timer is already running, it will be     \l{QTimer::stop()}{stopped} and restarted.      If \l singleShot is true, the timer will be activated only once.  */
end_comment
begin_function
DECL|function|start
name|void
name|QTimer
operator|::
name|start
parameter_list|(
name|int
name|msec
parameter_list|)
block|{
name|inter
operator|=
name|msec
expr_stmt|;
name|start
argument_list|()
expr_stmt|;
block|}
end_function
begin_ifdef
ifdef|#
directive|ifdef
name|QT3_SUPPORT
end_ifdef
begin_comment
comment|/*! \overload start()    Call setSingleShot(\a sshot) and start(\a msec) instead. */
end_comment
begin_function
DECL|function|start
name|int
name|QTimer
operator|::
name|start
parameter_list|(
name|int
name|msec
parameter_list|,
name|bool
name|sshot
parameter_list|)
block|{
if|if
condition|(
name|id
operator|>=
literal|0
operator|&&
name|nulltimer
operator|&&
operator|!
name|msec
operator|&&
name|sshot
condition|)
return|return
name|id
return|;
name|stop
argument_list|()
expr_stmt|;
name|setInterval
argument_list|(
name|msec
argument_list|)
expr_stmt|;
name|setSingleShot
argument_list|(
name|sshot
argument_list|)
expr_stmt|;
name|start
argument_list|()
expr_stmt|;
return|return
name|timerId
argument_list|()
return|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/*!     Stops the timer.      \sa start() */
end_comment
begin_function
DECL|function|stop
name|void
name|QTimer
operator|::
name|stop
parameter_list|()
block|{
if|if
condition|(
name|id
operator|!=
name|INV_TIMER
condition|)
block|{
name|QObject
operator|::
name|killTimer
argument_list|(
name|id
argument_list|)
expr_stmt|;
name|id
operator|=
name|INV_TIMER
expr_stmt|;
block|}
block|}
end_function
begin_comment
comment|/*!   \reimp */
end_comment
begin_function
DECL|function|timerEvent
name|void
name|QTimer
operator|::
name|timerEvent
parameter_list|(
name|QTimerEvent
modifier|*
name|e
parameter_list|)
block|{
if|if
condition|(
name|e
operator|->
name|timerId
argument_list|()
operator|==
name|id
condition|)
block|{
if|if
condition|(
name|single
condition|)
name|stop
argument_list|()
expr_stmt|;
emit|emit
name|timeout
argument_list|()
emit|;
block|}
block|}
end_function
begin_class
DECL|class|QSingleShotTimer
class|class
name|QSingleShotTimer
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
DECL|member|timerId
name|int
name|timerId
decl_stmt|;
public|public:
name|~
name|QSingleShotTimer
parameter_list|()
destructor_decl|;
name|QSingleShotTimer
parameter_list|(
name|int
name|msec
parameter_list|,
name|QObject
modifier|*
name|r
parameter_list|,
specifier|const
name|char
modifier|*
name|m
parameter_list|)
constructor_decl|;
name|Q_SIGNALS
label|:
name|void
name|timeout
parameter_list|()
function_decl|;
protected|protected:
name|void
name|timerEvent
parameter_list|(
name|QTimerEvent
modifier|*
parameter_list|)
function_decl|;
block|}
class|;
end_class
begin_constructor
DECL|function|QSingleShotTimer
name|QSingleShotTimer
operator|::
name|QSingleShotTimer
parameter_list|(
name|int
name|msec
parameter_list|,
name|QObject
modifier|*
name|receiver
parameter_list|,
specifier|const
name|char
modifier|*
name|member
parameter_list|)
member_init_list|:
name|QObject
argument_list|(
name|QAbstractEventDispatcher
operator|::
name|instance
argument_list|()
argument_list|)
block|{
name|connect
argument_list|(
name|this
argument_list|,
name|SIGNAL
argument_list|(
name|timeout
argument_list|()
argument_list|)
argument_list|,
name|receiver
argument_list|,
name|member
argument_list|)
expr_stmt|;
name|timerId
operator|=
name|startTimer
argument_list|(
name|msec
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_destructor
DECL|function|~QSingleShotTimer
name|QSingleShotTimer
operator|::
name|~
name|QSingleShotTimer
parameter_list|()
block|{
if|if
condition|(
name|timerId
operator|>
literal|0
condition|)
name|killTimer
argument_list|(
name|timerId
argument_list|)
expr_stmt|;
block|}
end_destructor
begin_function
DECL|function|timerEvent
name|void
name|QSingleShotTimer
operator|::
name|timerEvent
parameter_list|(
name|QTimerEvent
modifier|*
parameter_list|)
block|{
comment|// need to kill the timer _before_ we emit timeout() in case the
comment|// slot connected to timeout calls processEvents()
if|if
condition|(
name|timerId
operator|>
literal|0
condition|)
name|killTimer
argument_list|(
name|timerId
argument_list|)
expr_stmt|;
name|timerId
operator|=
operator|-
literal|1
expr_stmt|;
emit|emit
name|timeout
argument_list|()
emit|;
comment|// we would like to use delete later here, but it feels like a
comment|// waste to post a new event to handle this event, so we just unset the flag
comment|// and explicitly delete...
name|qDeleteInEventHandler
argument_list|(
name|this
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
name|QT_BEGIN_INCLUDE_NAMESPACE
include|#
directive|include
file|"qtimer.moc"
name|QT_END_INCLUDE_NAMESPACE
comment|/*!     \reentrant     This static function calls a slot after a given time interval.      It is very convenient to use this function because you do not need     to bother with a \link QObject::timerEvent() timerEvent\endlink or     create a local QTimer object.      Example:     \snippet doc/src/snippets/code/src_corelib_kernel_qtimer.cpp 0      This sample program automatically terminates after 10 minutes     (600,000 milliseconds).      The \a receiver is the receiving object and the \a member is the     slot. The time interval is \a msec milliseconds.      \sa start() */
DECL|function|singleShot
name|void
name|QTimer
operator|::
name|singleShot
parameter_list|(
name|int
name|msec
parameter_list|,
name|QObject
modifier|*
name|receiver
parameter_list|,
specifier|const
name|char
modifier|*
name|member
parameter_list|)
block|{
if|if
condition|(
name|receiver
operator|&&
name|member
condition|)
block|{
if|if
condition|(
name|msec
operator|==
literal|0
condition|)
block|{
comment|// special code shortpath for 0-timers
specifier|const
name|char
modifier|*
name|bracketPosition
init|=
name|strchr
argument_list|(
name|member
argument_list|,
literal|'('
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|bracketPosition
operator|||
operator|!
operator|(
name|member
index|[
literal|0
index|]
operator|>=
literal|'0'
operator|&&
name|member
index|[
literal|0
index|]
operator|<=
literal|'3'
operator|)
condition|)
block|{
name|qWarning
argument_list|(
literal|"QTimer::singleShot: Invalid slot specification"
argument_list|)
expr_stmt|;
return|return;
block|}
name|QByteArray
name|methodName
argument_list|(
name|member
operator|+
literal|1
argument_list|,
name|bracketPosition
operator|-
literal|1
operator|-
name|member
argument_list|)
decl_stmt|;
comment|// extract method name
name|QMetaObject
operator|::
name|invokeMethod
argument_list|(
name|receiver
argument_list|,
name|methodName
operator|.
name|constData
argument_list|()
argument_list|,
name|Qt
operator|::
name|QueuedConnection
argument_list|)
expr_stmt|;
return|return;
block|}
operator|(
name|void
operator|)
operator|new
name|QSingleShotTimer
argument_list|(
name|msec
argument_list|,
name|receiver
argument_list|,
name|member
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_comment
comment|/*!     \property QTimer::singleShot     \brief whether the timer is a single-shot timer      A single-shot timer fires only once, non-single-shot timers fire     every \l interval milliseconds.      \sa interval, singleShot() */
end_comment
begin_comment
comment|/*!     \property QTimer::interval     \brief the timeout interval in milliseconds      The default value for this property is 0.  A QTimer with a timeout     interval of 0 will time out as soon as all the events in the window     system's event queue have been processed.      Setting the interval of an active timer changes its timerId().      \sa singleShot */
end_comment
begin_function
DECL|function|setInterval
name|void
name|QTimer
operator|::
name|setInterval
parameter_list|(
name|int
name|msec
parameter_list|)
block|{
name|inter
operator|=
name|msec
expr_stmt|;
if|if
condition|(
name|id
operator|!=
name|INV_TIMER
condition|)
block|{
comment|// create new timer
name|QObject
operator|::
name|killTimer
argument_list|(
name|id
argument_list|)
expr_stmt|;
comment|// restart timer
name|id
operator|=
name|QObject
operator|::
name|startTimer
argument_list|(
name|msec
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_comment
comment|/*! \fn void QTimer::changeInterval(int msec)     Use setInterval(msec) or start(msec) instead. */
end_comment
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
