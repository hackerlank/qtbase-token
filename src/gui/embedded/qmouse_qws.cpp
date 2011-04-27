begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** No Commercial Usage ** This file contains pre-release code and may not be distributed. ** You may use this file in accordance with the terms and conditions ** contained in the Technology Preview License Agreement accompanying ** this package. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights.  These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** If you have questions regarding the use of this file, please contact ** Nokia at qt-info@nokia.com. ** ** ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qmouse_qws.h"
end_include
begin_include
include|#
directive|include
file|"qwindowsystem_qws.h"
end_include
begin_include
include|#
directive|include
file|"qscreen_qws.h"
end_include
begin_include
include|#
directive|include
file|"qapplication.h"
end_include
begin_include
include|#
directive|include
file|"qtextstream.h"
end_include
begin_include
include|#
directive|include
file|"qfile.h"
end_include
begin_include
include|#
directive|include
file|"qdebug.h"
end_include
begin_include
include|#
directive|include
file|"qscreen_qws.h"
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_comment
comment|/*!     \class QWSPointerCalibrationData     \ingroup qws      \brief The QWSPointerCalibrationData class is a container for     mouse calibration data in Qt for Embedded Linux.      Note that this class is only available in \l{Qt for Embedded Linux}.      QWSPointerCalibrationData stores device and screen coordinates in     the devPoints and screenPoints variables, respectively.      A calibration program should create a QWSPointerCalibrationData     object, fill the devPoints and screenPoints variables with its     device and screen coordinates, and pass the object to the mouse     driver using the QWSMouseHandler::calibrate() function.      \sa QWSCalibratedMouseHandler, {Mouse Calibration Example} */
end_comment
begin_comment
comment|/*!     \variable QWSPointerCalibrationData::devPoints     \brief the raw device coordinates for each value of the Location enum. */
end_comment
begin_comment
comment|/*!     \variable QWSPointerCalibrationData::screenPoints     \brief the logical screen coordinates for each value of the Location enum. */
end_comment
begin_comment
comment|/*!     \enum QWSPointerCalibrationData::Location      This enum describes the various logical positions that can be     specified by the devPoints and screenPoints variables.      \value TopLeft           Index of the top left corner of the screen.     \value BottomLeft     Index of the bottom left corner of the screen.     \value BottomRight   Index of the bottom right corner of the screen.     \value TopRight         Index of the top right corner of the screen.     \value Center            Index of the center of the screen.     \value LastLocation   Last index in the pointer arrays. */
end_comment
begin_class
DECL|class|QWSMouseHandlerPrivate
class|class
name|QWSMouseHandlerPrivate
block|{
public|public:
DECL|function|QWSMouseHandlerPrivate
name|QWSMouseHandlerPrivate
parameter_list|()
member_init_list|:
name|screen
argument_list|(
name|qt_screen
argument_list|)
block|{}
DECL|member|screen
specifier|const
name|QScreen
modifier|*
name|screen
decl_stmt|;
block|}
class|;
end_class
begin_comment
comment|/*!     \class QWSMouseHandler     \ingroup qws      \brief The QWSMouseHandler class is a base class for mouse drivers in     Qt for Embedded Linux.      Note that this class is only available in \l{Qt for Embedded Linux}.      \l{Qt for Embedded Linux} provides ready-made drivers for several mouse     protocols, see the \l{Qt for Embedded Linux Pointer Handling}{pointer     handling} documentation for details. Custom mouse drivers can be     implemented by subclassing the QWSMouseHandler class and creating     a mouse driver plugin (derived from QMouseDriverPlugin).     The default implementation of the QMouseDriverFactory class     will automatically detect the plugin, and load the driver into the     server application at run-time using Qt's \l {How to Create Qt     Plugins}{plugin system}.      The mouse driver receives mouse events from the system device and     encapsulates each event with an instance of the QWSEvent class     which it then passes to the server application (the server is     responsible for propagating the event to the appropriate     client). To receive mouse events, a QWSMouseHandler object will     usually create a QSocketNotifier object for the given device. The     QSocketNotifier class provides support for monitoring activity on     a file descriptor. When the socket notifier receives data, it will     call the mouse driver's mouseChanged() function to send the event     to the \l{Qt for Embedded Linux} server application for relaying to     clients.      If you are creating a driver for a device that needs calibration     or noise reduction, such as a touchscreen, use the     QWSCalibratedMouseHandler subclass instead to take advantage of     the calibrate() and clearCalibration() functions. The \l     {qws/mousecalibration}{Mouse Calibration}     demonstrates how to write a simple program using the mechanisms     provided by the QWSMouseHandler class to calibrate a mouse driver.      Note that when deriving from the QWSMouseHandler class, the     resume() and suspend() functions must be reimplemented to control     the flow of mouse input, i.e., the default implementation does     nothing. Reimplementations of these functions typically call the     QSocketNotifier::setEnabled() function to enable or disable the     socket notifier, respectively.      In addition, QWSMouseHandler provides the setScreen() function     that allows you to specify a screen for your mouse driver and the     limitToScreen() function that ensures that a given position is     within this screen's boundaries (changing the position if     necessary). Finally, QWSMouseHandler provides the pos() function     returning the current mouse position.      \sa QMouseDriverPlugin, QMouseDriverFactory, {Qt for Embedded Linux Pointer     Handling} */
end_comment
begin_comment
comment|/*!     \fn void QWSMouseHandler::suspend()      Implement this function to suspend reading and handling of mouse     events, e.g., call the QSocketNotifier::setEnabled() function to     disable the socket notifier.      \sa resume() */
end_comment
begin_comment
comment|/*!     \fn void QWSMouseHandler::resume()      Implement this function to resume reading and handling mouse     events, e.g., call the QSocketNotifier::setEnabled() function to     enable the socket notifier.      \sa suspend() */
end_comment
begin_comment
comment|/*!     \fn const QPoint&QWSMouseHandler::pos() const      Returns the current mouse position.      \sa mouseChanged(), limitToScreen() */
end_comment
begin_comment
comment|/*!     Constructs a mouse driver. The \a driver and \a device arguments     are passed by the QWS_MOUSE_PROTO environment variable.      Call the QWSServer::setMouseHandler() function to make the newly     created mouse driver, the primary driver. Note that the primary     driver is controlled by the system, i.e., the system will delete     it upon exit. */
end_comment
begin_constructor
DECL|function|QWSMouseHandler
name|QWSMouseHandler
operator|::
name|QWSMouseHandler
parameter_list|(
specifier|const
name|QString
modifier|&
parameter_list|,
specifier|const
name|QString
modifier|&
parameter_list|)
member_init_list|:
name|mousePos
argument_list|(
name|QWSServer
operator|::
name|mousePosition
argument_list|)
member_init_list|,
name|d_ptr
argument_list|(
operator|new
name|QWSMouseHandlerPrivate
argument_list|)
block|{ }
end_constructor
begin_comment
comment|/*!     Destroys this mouse driver.      Do not call this function if this driver is the primary mouse     driver, i.e., if QWSServer::setMouseHandler() function has been     called passing this driver as argument. The primary mouse     driver is deleted by the system. */
end_comment
begin_destructor
DECL|function|~QWSMouseHandler
name|QWSMouseHandler
operator|::
name|~
name|QWSMouseHandler
parameter_list|()
block|{
operator|delete
name|d_ptr
expr_stmt|;
block|}
end_destructor
begin_comment
comment|/*!     Ensures that the given \a position is within the screen's     boundaries, changing the \a position if necessary.      \sa pos(), setScreen() */
end_comment
begin_function
DECL|function|limitToScreen
name|void
name|QWSMouseHandler
operator|::
name|limitToScreen
parameter_list|(
name|QPoint
modifier|&
name|position
parameter_list|)
block|{
name|position
operator|.
name|setX
argument_list|(
name|qMin
argument_list|(
name|d_ptr
operator|->
name|screen
operator|->
name|deviceWidth
argument_list|()
operator|-
literal|1
argument_list|,
name|qMax
argument_list|(
literal|0
argument_list|,
name|position
operator|.
name|x
argument_list|()
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|position
operator|.
name|setY
argument_list|(
name|qMin
argument_list|(
name|d_ptr
operator|->
name|screen
operator|->
name|deviceHeight
argument_list|()
operator|-
literal|1
argument_list|,
name|qMax
argument_list|(
literal|0
argument_list|,
name|position
operator|.
name|y
argument_list|()
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     \since 4.2      Sets the screen for this mouse driver to be the given \a screen.      \sa limitToScreen() */
end_comment
begin_function
DECL|function|setScreen
name|void
name|QWSMouseHandler
operator|::
name|setScreen
parameter_list|(
specifier|const
name|QScreen
modifier|*
name|screen
parameter_list|)
block|{
name|d_ptr
operator|->
name|screen
operator|=
operator|(
name|screen
condition|?
name|screen
else|:
name|qt_screen
operator|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     Notifies the system of a new mouse event.      This function updates the current mouse position and sends the     event to the \l{Qt for Embedded Linux} server application for     delivery to the correct widget. Note that a custom mouse driver must call     this function whenever it wants to deliver a new mouse event.      The given \a position is the global position of the mouse cursor.     The \a state parameter is a bitmask of the Qt::MouseButton enum's     values, indicating which mouse buttons are pressed. The \a wheel     parameter is the delta value of the mouse wheel as returned by     QWheelEvent::delta().      \sa pos() */
end_comment
begin_function
DECL|function|mouseChanged
name|void
name|QWSMouseHandler
operator|::
name|mouseChanged
parameter_list|(
specifier|const
name|QPoint
modifier|&
name|position
parameter_list|,
name|int
name|state
parameter_list|,
name|int
name|wheel
parameter_list|)
block|{
name|mousePos
operator|=
name|position
operator|+
name|d_ptr
operator|->
name|screen
operator|->
name|offset
argument_list|()
expr_stmt|;
name|QWSServer
operator|::
name|sendMouseEvent
argument_list|(
name|mousePos
argument_list|,
name|state
argument_list|,
name|wheel
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     \fn QWSMouseHandler::clearCalibration()      This virtual function allows subclasses of QWSMouseHandler to     clear the calibration information. Note that the default     implementation does nothing.      \sa QWSCalibratedMouseHandler::clearCalibration(), calibrate() */
end_comment
begin_comment
comment|/*!     \fn QWSMouseHandler::calibrate(const QWSPointerCalibrationData *data)      This virtual function allows subclasses of QWSMouseHandler to set     the calibration information passed in the given \a data. Note that     the default implementation does nothing.      \sa QWSCalibratedMouseHandler::calibrate(), clearCalibration() */
end_comment
begin_comment
comment|/*! \fn QWSMouseHandler::getCalibration(QWSPointerCalibrationData *data) const     This virtual function allows subclasses of QWSMouseHandler     to fill in the device coordinates in \a data with values     that correspond to screen coordinates that are already in     \a data. Note that the default implementation does nothing.  */
end_comment
begin_comment
comment|/*!     \class QWSCalibratedMouseHandler     \ingroup qws      \brief The QWSCalibratedMouseHandler class provides mouse     calibration and noise reduction in Qt for Embedded Linux.      Note that this class is only available in \l{Qt for Embedded Linux}.      \l{Qt for Embedded Linux} provides ready-made drivers for several mouse     protocols, see the \l{Qt for Embedded Linux Pointer Handling}{pointer     handling} documentation for details. In general, custom mouse     drivers can be implemented by subclassing the QWSMouseHandler     class. But when the system device does not have a fixed mapping     between device and screen coordinates and/or produces noisy events     (e.g., a touchscreen), you should derive from the     QWSCalibratedMouseHandler class instead to take advantage of its     calibration functionality. As always, you must also create a mouse     driver plugin (derived from QMouseDriverPlugin);     the implementation of the QMouseDriverFactory class will then     automatically detect the plugin, and load the driver into the     server application at run-time using Qt's     \l{How to Create Qt Plugins}{plugin system}.      QWSCalibratedMouseHandler provides an implementation of the     calibrate() function to update the calibration parameters based on     coordinate mapping of the given calibration data. The calibration     data is represented by an QWSPointerCalibrationData object. The     linear transformation between device coordinates and screen     coordinates is performed by calling the transform() function     explicitly on the points passed to the     QWSMouseHandler::mouseChanged() function. Use the     clearCalibration() function to make the mouse driver return mouse     events in raw device coordinates and not in screen coordinates.      The calibration parameters are recalculated whenever calibrate()     is called, and they can be stored using the writeCalibration()     function. Previously written parameters can be retrieved at any     time using the readCalibration() function (calibration parameters     are always read when the class is instantiated). Note that the     calibration parameters is written to and read from the file     currently specified by the POINTERCAL_FILE environment variable;     the default file is \c /etc/pointercal.      To achieve noise reduction, QWSCalibratedMouseHandler provides the     sendFiltered() function. Use this function instead of     mouseChanged() whenever a mouse event occurs. The filter's size     can be manipulated using the setFilterSize() function.      \sa QWSMouseHandler, QWSPointerCalibrationData,     {Mouse Calibration Example} */
end_comment
begin_comment
comment|/*!     \internal  */
end_comment
begin_constructor
DECL|function|QWSCalibratedMouseHandler
name|QWSCalibratedMouseHandler
operator|::
name|QWSCalibratedMouseHandler
parameter_list|(
specifier|const
name|QString
modifier|&
parameter_list|,
specifier|const
name|QString
modifier|&
parameter_list|)
member_init_list|:
name|samples
argument_list|(
literal|5
argument_list|)
member_init_list|,
name|currSample
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|numSamples
argument_list|(
literal|0
argument_list|)
block|{
name|clearCalibration
argument_list|()
expr_stmt|;
name|readCalibration
argument_list|()
expr_stmt|;
block|}
end_constructor
begin_comment
comment|/*!     Fills \a cd with the device coordinates corresponding to the given     screen coordinates.      \internal */
end_comment
begin_function
DECL|function|getCalibration
name|void
name|QWSCalibratedMouseHandler
operator|::
name|getCalibration
parameter_list|(
name|QWSPointerCalibrationData
modifier|*
name|cd
parameter_list|)
specifier|const
block|{
specifier|const
name|qint64
name|scale
init|=
name|qint64
argument_list|(
name|a
argument_list|)
operator|*
name|qint64
argument_list|(
name|e
argument_list|)
operator|-
name|qint64
argument_list|(
name|b
argument_list|)
operator|*
name|qint64
argument_list|(
name|d
argument_list|)
decl_stmt|;
specifier|const
name|qint64
name|xOff
init|=
name|qint64
argument_list|(
name|b
argument_list|)
operator|*
name|qint64
argument_list|(
name|f
argument_list|)
operator|-
name|qint64
argument_list|(
name|c
argument_list|)
operator|*
name|qint64
argument_list|(
name|e
argument_list|)
decl_stmt|;
specifier|const
name|qint64
name|yOff
init|=
name|qint64
argument_list|(
name|c
argument_list|)
operator|*
name|qint64
argument_list|(
name|d
argument_list|)
operator|-
name|qint64
argument_list|(
name|a
argument_list|)
operator|*
name|qint64
argument_list|(
name|f
argument_list|)
decl_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<=
name|QWSPointerCalibrationData
operator|::
name|LastLocation
condition|;
operator|++
name|i
control|)
block|{
specifier|const
name|qint64
name|sX
init|=
name|cd
operator|->
name|screenPoints
index|[
name|i
index|]
operator|.
name|x
argument_list|()
decl_stmt|;
specifier|const
name|qint64
name|sY
init|=
name|cd
operator|->
name|screenPoints
index|[
name|i
index|]
operator|.
name|y
argument_list|()
decl_stmt|;
specifier|const
name|qint64
name|dX
init|=
operator|(
name|s
operator|*
operator|(
name|e
operator|*
name|sX
operator|-
name|b
operator|*
name|sY
operator|)
operator|+
name|xOff
operator|)
operator|/
name|scale
decl_stmt|;
specifier|const
name|qint64
name|dY
init|=
operator|(
name|s
operator|*
operator|(
name|a
operator|*
name|sY
operator|-
name|d
operator|*
name|sX
operator|)
operator|+
name|yOff
operator|)
operator|/
name|scale
decl_stmt|;
name|cd
operator|->
name|devPoints
index|[
name|i
index|]
operator|=
name|QPoint
argument_list|(
name|dX
argument_list|,
name|dY
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_comment
comment|/*!     Clears the current calibration, i.e., makes the mouse     driver return mouse events in raw device coordinates instead of     screen coordinates.      \sa calibrate() */
end_comment
begin_function
DECL|function|clearCalibration
name|void
name|QWSCalibratedMouseHandler
operator|::
name|clearCalibration
parameter_list|()
block|{
name|a
operator|=
literal|1
expr_stmt|;
name|b
operator|=
literal|0
expr_stmt|;
name|c
operator|=
literal|0
expr_stmt|;
name|d
operator|=
literal|0
expr_stmt|;
name|e
operator|=
literal|1
expr_stmt|;
name|f
operator|=
literal|0
expr_stmt|;
name|s
operator|=
literal|1
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     Saves the current calibration parameters in \c /etc/pointercal     (separated by whitespace and in alphabetical order).      You can override the default \c /etc/pointercal by specifying     another file using the POINTERCAL_FILE environment variable.      \sa readCalibration() */
end_comment
begin_function
DECL|function|writeCalibration
name|void
name|QWSCalibratedMouseHandler
operator|::
name|writeCalibration
parameter_list|()
block|{
name|QString
name|calFile
decl_stmt|;
name|calFile
operator|=
name|QString
operator|::
name|fromLocal8Bit
argument_list|(
name|qgetenv
argument_list|(
literal|"POINTERCAL_FILE"
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|calFile
operator|.
name|isEmpty
argument_list|()
condition|)
name|calFile
operator|=
name|QLatin1String
argument_list|(
literal|"/etc/pointercal"
argument_list|)
expr_stmt|;
ifndef|#
directive|ifndef
name|QT_NO_TEXTSTREAM
name|QFile
name|file
argument_list|(
name|calFile
argument_list|)
decl_stmt|;
if|if
condition|(
name|file
operator|.
name|open
argument_list|(
name|QIODevice
operator|::
name|WriteOnly
argument_list|)
condition|)
block|{
name|QTextStream
name|t
argument_list|(
operator|&
name|file
argument_list|)
decl_stmt|;
name|t
operator|<<
name|a
operator|<<
literal|' '
operator|<<
name|b
operator|<<
literal|' '
operator|<<
name|c
operator|<<
literal|' '
expr_stmt|;
name|t
operator|<<
name|d
operator|<<
literal|' '
operator|<<
name|e
operator|<<
literal|' '
operator|<<
name|f
operator|<<
literal|' '
operator|<<
name|s
operator|<<
name|endl
expr_stmt|;
block|}
else|else
endif|#
directive|endif
block|{
name|qCritical
argument_list|(
literal|"QWSCalibratedMouseHandler::writeCalibration: "
literal|"Could not save calibration into %s"
argument_list|,
name|qPrintable
argument_list|(
name|calFile
argument_list|)
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_comment
comment|/*!     Reads previously written calibration parameters which are stored     in \c /etc/pointercal (separated by whitespace and in alphabetical     order).      You can override the default \c /etc/pointercal by specifying     another file using the POINTERCAL_FILE environment variable.       \sa writeCalibration() */
end_comment
begin_function
DECL|function|readCalibration
name|void
name|QWSCalibratedMouseHandler
operator|::
name|readCalibration
parameter_list|()
block|{
name|QString
name|calFile
init|=
name|QString
operator|::
name|fromLocal8Bit
argument_list|(
name|qgetenv
argument_list|(
literal|"POINTERCAL_FILE"
argument_list|)
argument_list|)
decl_stmt|;
if|if
condition|(
name|calFile
operator|.
name|isEmpty
argument_list|()
condition|)
name|calFile
operator|=
name|QLatin1String
argument_list|(
literal|"/etc/pointercal"
argument_list|)
expr_stmt|;
ifndef|#
directive|ifndef
name|QT_NO_TEXTSTREAM
name|QFile
name|file
argument_list|(
name|calFile
argument_list|)
decl_stmt|;
if|if
condition|(
name|file
operator|.
name|open
argument_list|(
name|QIODevice
operator|::
name|ReadOnly
argument_list|)
condition|)
block|{
name|QTextStream
name|t
argument_list|(
operator|&
name|file
argument_list|)
decl_stmt|;
name|t
operator|>>
name|a
operator|>>
name|b
operator|>>
name|c
operator|>>
name|d
operator|>>
name|e
operator|>>
name|f
operator|>>
name|s
expr_stmt|;
if|if
condition|(
name|s
operator|==
literal|0
operator|||
name|t
operator|.
name|status
argument_list|()
operator|!=
name|QTextStream
operator|::
name|Ok
condition|)
block|{
name|qCritical
argument_list|(
literal|"Corrupt calibration data"
argument_list|)
expr_stmt|;
name|clearCalibration
argument_list|()
expr_stmt|;
block|}
block|}
else|else
endif|#
directive|endif
block|{
name|qDebug
argument_list|()
operator|<<
literal|"Could not read calibration:"
operator|<<
name|calFile
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|ilog2
specifier|static
name|int
name|ilog2
parameter_list|(
name|quint32
name|n
parameter_list|)
block|{
name|int
name|result
init|=
literal|0
decl_stmt|;
if|if
condition|(
name|n
operator|&
literal|0xffff0000
condition|)
block|{
name|n
operator|>>=
literal|16
expr_stmt|;
name|result
operator|+=
literal|16
expr_stmt|;
block|}
if|if
condition|(
name|n
operator|&
literal|0xff00
condition|)
block|{
name|n
operator|>>=
literal|8
expr_stmt|;
name|result
operator|+=
literal|8
expr_stmt|;
block|}
if|if
condition|(
name|n
operator|&
literal|0xf0
condition|)
block|{
name|n
operator|>>=
literal|4
expr_stmt|;
name|result
operator|+=
literal|4
expr_stmt|;
block|}
if|if
condition|(
name|n
operator|&
literal|0xc
condition|)
block|{
name|n
operator|>>=
literal|2
expr_stmt|;
name|result
operator|+=
literal|2
expr_stmt|;
block|}
if|if
condition|(
name|n
operator|&
literal|0x2
condition|)
name|result
operator|+=
literal|1
expr_stmt|;
return|return
name|result
return|;
block|}
end_function
begin_comment
comment|/*!     Updates the calibration parameters based on coordinate mapping of     the given \a data.      Create an instance of the QWSPointerCalibrationData class, fill in     the device and screen coordinates and pass that object to the mouse     driver using this function.      \sa clearCalibration(), transform() */
end_comment
begin_function
DECL|function|calibrate
name|void
name|QWSCalibratedMouseHandler
operator|::
name|calibrate
parameter_list|(
specifier|const
name|QWSPointerCalibrationData
modifier|*
name|data
parameter_list|)
block|{
comment|// Algorithm derived from
comment|// "How To Calibrate Touch Screens" by Carlos E. Vidales,
comment|// printed in Embedded Systems Programming, Vol. 15 no 6, June 2002
comment|// URL: http://www.embedded.com/showArticle.jhtml?articleID=9900629
specifier|const
name|QPoint
name|pd0
init|=
name|data
operator|->
name|devPoints
index|[
name|QWSPointerCalibrationData
operator|::
name|TopLeft
index|]
decl_stmt|;
specifier|const
name|QPoint
name|pd1
init|=
name|data
operator|->
name|devPoints
index|[
name|QWSPointerCalibrationData
operator|::
name|TopRight
index|]
decl_stmt|;
specifier|const
name|QPoint
name|pd2
init|=
name|data
operator|->
name|devPoints
index|[
name|QWSPointerCalibrationData
operator|::
name|BottomRight
index|]
decl_stmt|;
specifier|const
name|QPoint
name|p0
init|=
name|data
operator|->
name|screenPoints
index|[
name|QWSPointerCalibrationData
operator|::
name|TopLeft
index|]
decl_stmt|;
specifier|const
name|QPoint
name|p1
init|=
name|data
operator|->
name|screenPoints
index|[
name|QWSPointerCalibrationData
operator|::
name|TopRight
index|]
decl_stmt|;
specifier|const
name|QPoint
name|p2
init|=
name|data
operator|->
name|screenPoints
index|[
name|QWSPointerCalibrationData
operator|::
name|BottomRight
index|]
decl_stmt|;
specifier|const
name|qint64
name|xd0
init|=
name|pd0
operator|.
name|x
argument_list|()
decl_stmt|;
specifier|const
name|qint64
name|xd1
init|=
name|pd1
operator|.
name|x
argument_list|()
decl_stmt|;
specifier|const
name|qint64
name|xd2
init|=
name|pd2
operator|.
name|x
argument_list|()
decl_stmt|;
specifier|const
name|qint64
name|yd0
init|=
name|pd0
operator|.
name|y
argument_list|()
decl_stmt|;
specifier|const
name|qint64
name|yd1
init|=
name|pd1
operator|.
name|y
argument_list|()
decl_stmt|;
specifier|const
name|qint64
name|yd2
init|=
name|pd2
operator|.
name|y
argument_list|()
decl_stmt|;
specifier|const
name|qint64
name|x0
init|=
name|p0
operator|.
name|x
argument_list|()
decl_stmt|;
specifier|const
name|qint64
name|x1
init|=
name|p1
operator|.
name|x
argument_list|()
decl_stmt|;
specifier|const
name|qint64
name|x2
init|=
name|p2
operator|.
name|x
argument_list|()
decl_stmt|;
specifier|const
name|qint64
name|y0
init|=
name|p0
operator|.
name|y
argument_list|()
decl_stmt|;
specifier|const
name|qint64
name|y1
init|=
name|p1
operator|.
name|y
argument_list|()
decl_stmt|;
specifier|const
name|qint64
name|y2
init|=
name|p2
operator|.
name|y
argument_list|()
decl_stmt|;
name|qint64
name|scale
init|=
operator|(
operator|(
name|xd0
operator|-
name|xd2
operator|)
operator|*
operator|(
name|yd1
operator|-
name|yd2
operator|)
operator|-
operator|(
name|xd1
operator|-
name|xd2
operator|)
operator|*
operator|(
name|yd0
operator|-
name|yd2
operator|)
operator|)
decl_stmt|;
name|int
name|shift
init|=
literal|0
decl_stmt|;
name|qint64
name|absScale
init|=
name|qAbs
argument_list|(
name|scale
argument_list|)
decl_stmt|;
comment|// use maximum 16 bit precision to reduce risk of integer overflow
if|if
condition|(
name|absScale
operator|>
operator|(
literal|1
operator|<<
literal|16
operator|)
condition|)
block|{
name|shift
operator|=
name|ilog2
argument_list|(
name|absScale
operator|>>
literal|16
argument_list|)
operator|+
literal|1
expr_stmt|;
name|scale
operator|>>=
name|shift
expr_stmt|;
block|}
name|s
operator|=
name|scale
expr_stmt|;
name|a
operator|=
operator|(
operator|(
name|x0
operator|-
name|x2
operator|)
operator|*
operator|(
name|yd1
operator|-
name|yd2
operator|)
operator|-
operator|(
name|x1
operator|-
name|x2
operator|)
operator|*
operator|(
name|yd0
operator|-
name|yd2
operator|)
operator|)
operator|>>
name|shift
expr_stmt|;
name|b
operator|=
operator|(
operator|(
name|xd0
operator|-
name|xd2
operator|)
operator|*
operator|(
name|x1
operator|-
name|x2
operator|)
operator|-
operator|(
name|x0
operator|-
name|x2
operator|)
operator|*
operator|(
name|xd1
operator|-
name|xd2
operator|)
operator|)
operator|>>
name|shift
expr_stmt|;
name|c
operator|=
operator|(
name|yd0
operator|*
operator|(
name|xd2
operator|*
name|x1
operator|-
name|xd1
operator|*
name|x2
operator|)
operator|+
name|yd1
operator|*
operator|(
name|xd0
operator|*
name|x2
operator|-
name|xd2
operator|*
name|x0
operator|)
operator|+
name|yd2
operator|*
operator|(
name|xd1
operator|*
name|x0
operator|-
name|xd0
operator|*
name|x1
operator|)
operator|)
operator|>>
name|shift
expr_stmt|;
name|d
operator|=
operator|(
operator|(
name|y0
operator|-
name|y2
operator|)
operator|*
operator|(
name|yd1
operator|-
name|yd2
operator|)
operator|-
operator|(
name|y1
operator|-
name|y2
operator|)
operator|*
operator|(
name|yd0
operator|-
name|yd2
operator|)
operator|)
operator|>>
name|shift
expr_stmt|;
name|e
operator|=
operator|(
operator|(
name|xd0
operator|-
name|xd2
operator|)
operator|*
operator|(
name|y1
operator|-
name|y2
operator|)
operator|-
operator|(
name|y0
operator|-
name|y2
operator|)
operator|*
operator|(
name|xd1
operator|-
name|xd2
operator|)
operator|)
operator|>>
name|shift
expr_stmt|;
name|f
operator|=
operator|(
name|yd0
operator|*
operator|(
name|xd2
operator|*
name|y1
operator|-
name|xd1
operator|*
name|y2
operator|)
operator|+
name|yd1
operator|*
operator|(
name|xd0
operator|*
name|y2
operator|-
name|xd2
operator|*
name|y0
operator|)
operator|+
name|yd2
operator|*
operator|(
name|xd1
operator|*
name|y0
operator|-
name|xd0
operator|*
name|y1
operator|)
operator|)
operator|>>
name|shift
expr_stmt|;
name|writeCalibration
argument_list|()
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     Transforms the given \a position from device coordinates to screen     coordinates, and returns the transformed position.      This function is typically called explicitly on the points passed     to the QWSMouseHandler::mouseChanged() function.      This implementation is a linear transformation using 7 parameters     (\c a, \c b, \c c, \c d, \c e, \c f and \c s) to transform the     device coordinates (\c Xd, \c Yd) into screen coordinates (\c Xs,     \c Ys) using the following equations:      \snippet doc/src/snippets/code/src_gui_embedded_qmouse_qws.cpp 0      \sa mouseChanged() */
end_comment
begin_function
DECL|function|transform
name|QPoint
name|QWSCalibratedMouseHandler
operator|::
name|transform
parameter_list|(
specifier|const
name|QPoint
modifier|&
name|position
parameter_list|)
block|{
name|QPoint
name|tp
decl_stmt|;
name|tp
operator|.
name|setX
argument_list|(
operator|(
name|a
operator|*
name|position
operator|.
name|x
argument_list|()
operator|+
name|b
operator|*
name|position
operator|.
name|y
argument_list|()
operator|+
name|c
operator|)
operator|/
name|s
argument_list|)
expr_stmt|;
name|tp
operator|.
name|setY
argument_list|(
operator|(
name|d
operator|*
name|position
operator|.
name|x
argument_list|()
operator|+
name|e
operator|*
name|position
operator|.
name|y
argument_list|()
operator|+
name|f
operator|)
operator|/
name|s
argument_list|)
expr_stmt|;
return|return
name|tp
return|;
block|}
end_function
begin_comment
comment|/*!     Sets the size of the filter used in noise reduction to the given     \a size.      The sendFiltered() function reduces noice by calculating an     average position from a collection of mouse event positions. The     filter size determines the number of positions that forms the     basis for these calculations.      \sa sendFiltered() */
end_comment
begin_function
DECL|function|setFilterSize
name|void
name|QWSCalibratedMouseHandler
operator|::
name|setFilterSize
parameter_list|(
name|int
name|size
parameter_list|)
block|{
name|samples
operator|.
name|resize
argument_list|(
name|qMax
argument_list|(
literal|1
argument_list|,
name|size
argument_list|)
argument_list|)
expr_stmt|;
name|numSamples
operator|=
literal|0
expr_stmt|;
name|currSample
operator|=
literal|0
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     \fn bool QWSCalibratedMouseHandler::sendFiltered(const QPoint&position, int state)      Notifies the system of a new mouse event \e after applying a noise     reduction filter. Returns true if the filtering process is     successful; otherwise returns false. Note that if the filtering     process failes, the system is not notified about the event.      The given \a position is the global position of the mouse. The \a     state parameter is a bitmask of the Qt::MouseButton enum's values     indicating which mouse buttons are pressed.      The noice is reduced by calculating an average position from a     collection of mouse event positions and then calling the     mouseChanged() function with the new position. The number of     positions that is used is determined by the filter size.      \sa mouseChanged(), setFilterSize() */
end_comment
begin_function
DECL|function|sendFiltered
name|bool
name|QWSCalibratedMouseHandler
operator|::
name|sendFiltered
parameter_list|(
specifier|const
name|QPoint
modifier|&
name|position
parameter_list|,
name|int
name|button
parameter_list|)
block|{
if|if
condition|(
operator|!
name|button
condition|)
block|{
if|if
condition|(
name|numSamples
operator|>=
name|samples
operator|.
name|count
argument_list|()
condition|)
name|mouseChanged
argument_list|(
name|transform
argument_list|(
name|position
argument_list|)
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|currSample
operator|=
literal|0
expr_stmt|;
name|numSamples
operator|=
literal|0
expr_stmt|;
return|return
literal|true
return|;
block|}
name|bool
name|sent
init|=
literal|false
decl_stmt|;
name|samples
index|[
name|currSample
index|]
operator|=
name|position
expr_stmt|;
name|numSamples
operator|++
expr_stmt|;
if|if
condition|(
name|numSamples
operator|>=
name|samples
operator|.
name|count
argument_list|()
condition|)
block|{
name|int
name|ignore
init|=
operator|-
literal|1
decl_stmt|;
if|if
condition|(
name|samples
operator|.
name|count
argument_list|()
operator|>
literal|2
condition|)
block|{
comment|// throw away the "worst" sample
name|int
name|maxd
init|=
literal|0
decl_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|samples
operator|.
name|count
argument_list|()
condition|;
name|i
operator|++
control|)
block|{
name|int
name|d
init|=
operator|(
name|mousePos
operator|-
name|samples
index|[
name|i
index|]
operator|)
operator|.
name|manhattanLength
argument_list|()
decl_stmt|;
if|if
condition|(
name|d
operator|>
name|maxd
condition|)
block|{
name|maxd
operator|=
name|d
expr_stmt|;
name|ignore
operator|=
name|i
expr_stmt|;
block|}
block|}
block|}
comment|// average the rest
name|QPoint
name|pos
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
decl_stmt|;
name|int
name|numAveraged
init|=
literal|0
decl_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|samples
operator|.
name|count
argument_list|()
condition|;
name|i
operator|++
control|)
block|{
if|if
condition|(
name|ignore
operator|==
name|i
condition|)
continue|continue;
name|pos
operator|+=
name|samples
index|[
name|i
index|]
expr_stmt|;
operator|++
name|numAveraged
expr_stmt|;
block|}
if|if
condition|(
name|numAveraged
condition|)
name|pos
operator|/=
name|numAveraged
expr_stmt|;
name|mouseChanged
argument_list|(
name|transform
argument_list|(
name|pos
argument_list|)
argument_list|,
name|button
argument_list|)
expr_stmt|;
name|sent
operator|=
literal|true
expr_stmt|;
block|}
name|currSample
operator|++
expr_stmt|;
if|if
condition|(
name|currSample
operator|>=
name|samples
operator|.
name|count
argument_list|()
condition|)
name|currSample
operator|=
literal|0
expr_stmt|;
return|return
name|sent
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
