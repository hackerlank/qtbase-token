begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** No Commercial Usage ** This file contains pre-release code and may not be distributed. ** You may use this file in accordance with the terms and conditions ** contained in the Technology Preview License Agreement accompanying ** this package. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights.  These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** If you have questions regarding the use of this file, please contact ** Nokia at qt-info@nokia.com. ** ** ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qgesture.h"
end_include
begin_include
include|#
directive|include
file|"private/qgesture_p.h"
end_include
begin_include
include|#
directive|include
file|"private/qstandardgestures_p.h"
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_GESTURES
end_ifndef
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_comment
comment|/*!     \class QGesture     \since 4.6     \ingroup gestures      \brief The QGesture class represents a gesture, containing properties that     describe the corresponding user input.      Gesture objects are not constructed directly by developers. They are created by     the QGestureRecognizer object that is registered with the application; see     QGestureRecognizer::registerRecognizer().      For an overview of gesture handling in Qt and information on using gestures     in your applications, see the \l{Gestures Programming} document.      \section1 Gesture Properties      The class has a list of properties that can be queried by the user to get     some gesture-specific arguments. For example, the pinch gesture has a scale     factor that is exposed as a property.      Developers of custom gesture recognizers can add additional properties in     order to provide additional information about a gesture. This can be done     by adding new dynamic properties to a QGesture object, or by subclassing     the QGesture class (or one of its subclasses).      \section1 Lifecycle of a Gesture Object      A QGesture instance is implicitly created when needed and is owned by Qt.     Developers should never destroy them or store them for later use as Qt may     destroy particular instances of them and create new ones to replace them.      The registered gesture recognizer monitors the input events for the target     object via its \l{QGestureRecognizer::}{recognize()} function, updating the     properties of the gesture object as required.      The gesture object may be delivered to the target object in a QGestureEvent if     the corresponding gesture is active or has just been canceled. Each event that     is delivered contains a list of gesture objects, since support for more than     one gesture may be enabled for the target object. Due to the way events are     handled in Qt, gesture events may be filtered by other objects.      \sa QGestureEvent, QGestureRecognizer */
end_comment
begin_comment
comment|/*!     Constructs a new gesture object with the given \a parent.      QGesture objects are created by gesture recognizers in the     QGestureRecognizer::create() function. */
end_comment
begin_constructor
DECL|function|QGesture
name|QGesture
operator|::
name|QGesture
parameter_list|(
name|QObject
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QObject
argument_list|(
operator|*
operator|new
name|QGesturePrivate
argument_list|,
name|parent
argument_list|)
block|{
name|d_func
argument_list|()
operator|->
name|gestureType
operator|=
name|Qt
operator|::
name|CustomGesture
expr_stmt|;
block|}
end_constructor
begin_comment
comment|/*!     \internal */
end_comment
begin_constructor
DECL|function|QGesture
name|QGesture
operator|::
name|QGesture
parameter_list|(
name|QGesturePrivate
modifier|&
name|dd
parameter_list|,
name|QObject
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QObject
argument_list|(
name|dd
argument_list|,
name|parent
argument_list|)
block|{ }
end_constructor
begin_comment
comment|/*!     Destroys the gesture object. */
end_comment
begin_destructor
DECL|function|~QGesture
name|QGesture
operator|::
name|~
name|QGesture
parameter_list|()
block|{ }
end_destructor
begin_comment
comment|/*!     \property QGesture::state     \brief the current state of the gesture */
end_comment
begin_comment
comment|/*!     \property QGesture::gestureType     \brief the type of the gesture */
end_comment
begin_comment
comment|/*!     \property QGesture::hotSpot      \brief The point that is used to find the receiver for the gesture event.      The hot-spot is a point in the global coordinate system, use     QWidget::mapFromGlobal() or QGestureEvent::mapToGraphicsScene() to get a     local hot-spot.      The hot-spot should be set by the gesture recognizer to allow gesture event     delivery to a QGraphicsObject. */
end_comment
begin_comment
comment|/*!     \property QGesture::hasHotSpot     \brief whether the gesture has a hot-spot */
end_comment
begin_function
DECL|function|gestureType
name|Qt
operator|::
name|GestureType
name|QGesture
operator|::
name|gestureType
parameter_list|()
specifier|const
block|{
return|return
name|d_func
argument_list|()
operator|->
name|gestureType
return|;
block|}
end_function
begin_function
DECL|function|state
name|Qt
operator|::
name|GestureState
name|QGesture
operator|::
name|state
parameter_list|()
specifier|const
block|{
return|return
name|d_func
argument_list|()
operator|->
name|state
return|;
block|}
end_function
begin_function
DECL|function|hotSpot
name|QPointF
name|QGesture
operator|::
name|hotSpot
parameter_list|()
specifier|const
block|{
return|return
name|d_func
argument_list|()
operator|->
name|hotSpot
return|;
block|}
end_function
begin_function
DECL|function|setHotSpot
name|void
name|QGesture
operator|::
name|setHotSpot
parameter_list|(
specifier|const
name|QPointF
modifier|&
name|value
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QGesture
argument_list|)
expr_stmt|;
name|d
operator|->
name|hotSpot
operator|=
name|value
expr_stmt|;
name|d
operator|->
name|isHotSpotSet
operator|=
literal|true
expr_stmt|;
block|}
end_function
begin_function
DECL|function|hasHotSpot
name|bool
name|QGesture
operator|::
name|hasHotSpot
parameter_list|()
specifier|const
block|{
return|return
name|d_func
argument_list|()
operator|->
name|isHotSpotSet
return|;
block|}
end_function
begin_function
DECL|function|unsetHotSpot
name|void
name|QGesture
operator|::
name|unsetHotSpot
parameter_list|()
block|{
name|d_func
argument_list|()
operator|->
name|isHotSpotSet
operator|=
literal|false
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     \property QGesture::gestureCancelPolicy     \brief the policy for deciding what happens on accepting a gesture      On accepting one gesture Qt can automatically cancel other gestures     that belong to other targets. The policy is normally set to not cancel     any other gestures and can be set to cancel all active gestures in the     context. For example for all child widgets. */
end_comment
begin_comment
comment|/*!     \enum QGesture::GestureCancelPolicy      This enum describes how accepting a gesture can cancel other gestures     automatically.      \value CancelNone On accepting this gesture no other gestures will be affected.      \value CancelAllInContext On accepting this gesture all gestures that are     active in the context (respecting the Qt::GestureFlag that were specified     when subscribed to the gesture) will be cancelled. */
end_comment
begin_function
DECL|function|setGestureCancelPolicy
name|void
name|QGesture
operator|::
name|setGestureCancelPolicy
parameter_list|(
name|GestureCancelPolicy
name|policy
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QGesture
argument_list|)
expr_stmt|;
name|d
operator|->
name|gestureCancelPolicy
operator|=
cast|static_cast
argument_list|<
name|uint
argument_list|>
argument_list|(
name|policy
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|gestureCancelPolicy
name|QGesture
operator|::
name|GestureCancelPolicy
name|QGesture
operator|::
name|gestureCancelPolicy
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QGesture
argument_list|)
expr_stmt|;
return|return
cast|static_cast
argument_list|<
name|GestureCancelPolicy
argument_list|>
argument_list|(
name|d
operator|->
name|gestureCancelPolicy
argument_list|)
return|;
block|}
end_function
begin_comment
comment|/*!     \class QPanGesture     \since 4.6     \brief The QPanGesture class describes a panning gesture made by the user.     \ingroup gestures      \image pangesture.png      For an overview of gesture handling in Qt and information on using gestures     in your applications, see the \l{Gestures Programming} document.      \sa QPinchGesture, QSwipeGesture */
end_comment
begin_comment
comment|/*!     \property QPanGesture::lastOffset     \brief the last offset recorded for this gesture      The last offset contains the change in position of the user's input as     reported in the \l offset property when a previous gesture event was     delivered for this gesture.      If no previous event was delivered with information about this gesture     (i.e., this gesture object contains information about the first movement     in the gesture) then this property contains a zero size. */
end_comment
begin_comment
comment|/*!     \property QPanGesture::offset     \brief the total offset from the first input position to the current input     position      The offset measures the total change in position of the user's input     covered by the gesture on the input device. */
end_comment
begin_comment
comment|/*!     \property QPanGesture::delta     \brief the offset from the previous input position to the current input      This is essentially the same as the difference between offset() and     lastOffset(). */
end_comment
begin_comment
comment|/*!     \property QPanGesture::acceleration     \brief the acceleration in the motion of the touch point for this gesture */
end_comment
begin_comment
comment|/*!     \property QPanGesture::horizontalVelocity     \brief the horizontal component of the motion of the touch point for this     gesture     \since 4.7.1     \internal      \sa verticalVelocity, acceleration */
end_comment
begin_comment
comment|/*!     \property QPanGesture::verticalVelocity     \brief the vertical component of the motion of the touch point for this     gesture     \since 4.7.1     \internal      \sa horizontalVelocity, acceleration */
end_comment
begin_comment
comment|/*!     \internal */
end_comment
begin_constructor
DECL|function|QPanGesture
name|QPanGesture
operator|::
name|QPanGesture
parameter_list|(
name|QObject
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QGesture
argument_list|(
operator|*
operator|new
name|QPanGesturePrivate
argument_list|,
name|parent
argument_list|)
block|{
name|d_func
argument_list|()
operator|->
name|gestureType
operator|=
name|Qt
operator|::
name|PanGesture
expr_stmt|;
block|}
end_constructor
begin_function
DECL|function|lastOffset
name|QPointF
name|QPanGesture
operator|::
name|lastOffset
parameter_list|()
specifier|const
block|{
return|return
name|d_func
argument_list|()
operator|->
name|lastOffset
return|;
block|}
end_function
begin_function
DECL|function|offset
name|QPointF
name|QPanGesture
operator|::
name|offset
parameter_list|()
specifier|const
block|{
return|return
name|d_func
argument_list|()
operator|->
name|offset
return|;
block|}
end_function
begin_function
DECL|function|delta
name|QPointF
name|QPanGesture
operator|::
name|delta
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QPanGesture
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|offset
operator|-
name|d
operator|->
name|lastOffset
return|;
block|}
end_function
begin_function
DECL|function|acceleration
name|qreal
name|QPanGesture
operator|::
name|acceleration
parameter_list|()
specifier|const
block|{
return|return
name|d_func
argument_list|()
operator|->
name|acceleration
return|;
block|}
end_function
begin_function
DECL|function|setLastOffset
name|void
name|QPanGesture
operator|::
name|setLastOffset
parameter_list|(
specifier|const
name|QPointF
modifier|&
name|value
parameter_list|)
block|{
name|d_func
argument_list|()
operator|->
name|lastOffset
operator|=
name|value
expr_stmt|;
block|}
end_function
begin_function
DECL|function|setOffset
name|void
name|QPanGesture
operator|::
name|setOffset
parameter_list|(
specifier|const
name|QPointF
modifier|&
name|value
parameter_list|)
block|{
name|d_func
argument_list|()
operator|->
name|offset
operator|=
name|value
expr_stmt|;
block|}
end_function
begin_function
DECL|function|setAcceleration
name|void
name|QPanGesture
operator|::
name|setAcceleration
parameter_list|(
name|qreal
name|value
parameter_list|)
block|{
name|d_func
argument_list|()
operator|->
name|acceleration
operator|=
name|value
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     \class QPinchGesture     \since 4.6     \brief The QPinchGesture class describes a pinch gesture made by the user.     \ingroup touch     \ingroup gestures      A pinch gesture is a form of touch user input in which the user typically     touches two points on the input device with a thumb and finger, before moving     them closer together or further apart to change the scale factor, zoom, or level     of detail of the user interface.      For an overview of gesture handling in Qt and information on using gestures     in your applications, see the \l{Gestures Programming} document.      \image pinchgesture.png      Instead of repeatedly applying the same pinching gesture, the user may     continue to touch the input device in one place, and apply a second touch     to a new point, continuing the gesture. When this occurs, gesture events     will continue to be delivered to the target object, containing an instance     of QPinchGesture in the Qt::GestureUpdated state.      \sa QPanGesture, QSwipeGesture */
end_comment
begin_comment
comment|/*!     \enum QPinchGesture::ChangeFlag          This enum describes the changes that can occur to the properties of     the gesture object.      \value ScaleFactorChanged The scale factor held by scaleFactor changed.     \value RotationAngleChanged The rotation angle held by rotationAngle changed.     \value CenterPointChanged The center point held by centerPoint changed.      \sa changeFlags, totalChangeFlags */
end_comment
begin_comment
comment|/*!     \property QPinchGesture::totalChangeFlags     \brief the property of the gesture that has change      This property indicates which of the other properties has changed since the     gesture has started. You can use this information to determine which aspect     of your user interface needs to be updated.      \sa changeFlags, scaleFactor, rotationAngle, centerPoint */
end_comment
begin_comment
comment|/*!     \property QPinchGesture::changeFlags     \brief the property of the gesture that has changed in the current step      This property indicates which of the other properties has changed since     the previous gesture event included information about this gesture. You     can use this information to determine which aspect of your user interface     needs to be updated.      \sa totalChangeFlags, scaleFactor, rotationAngle, centerPoint */
end_comment
begin_comment
comment|/*!     \property QPinchGesture::totalScaleFactor     \brief the total scale factor      The total scale factor measures the total change in scale factor from the     original value to the current scale factor.      \sa scaleFactor, lastScaleFactor */
end_comment
begin_comment
comment|/*!     \property QPinchGesture::lastScaleFactor     \brief the last scale factor recorded for this gesture      The last scale factor contains the scale factor reported in the     \l scaleFactor property when a previous gesture event included     information about this gesture.      If no previous event was delivered with information about this gesture     (i.e., this gesture object contains information about the first movement     in the gesture) then this property contains zero.      \sa scaleFactor, totalScaleFactor */
end_comment
begin_comment
comment|/*!     \property QPinchGesture::scaleFactor     \brief the current scale factor      The scale factor measures the scale factor associated with the distance     between two of the user's inputs on a touch device.      \sa totalScaleFactor, lastScaleFactor */
end_comment
begin_comment
comment|/*!     \property QPinchGesture::totalRotationAngle     \brief the total angle covered by the gesture      This total angle measures the complete angle covered by the gesture. Usually, this     is equal to the value held by the \l rotationAngle property, except in the case where     the user performs multiple rotations by removing and repositioning one of the touch     points, as described above. In this case, the total angle will be the sum of the     rotation angles for the multiple stages of the gesture.      \sa rotationAngle, lastRotationAngle */
end_comment
begin_comment
comment|/*!     \property QPinchGesture::lastRotationAngle     \brief the last reported angle covered by the gesture motion      The last rotation angle is the angle as reported in the \l rotationAngle property     when a previous gesture event was delivered for this gesture.      \sa rotationAngle, totalRotationAngle */
end_comment
begin_comment
comment|/*!     \property QPinchGesture::rotationAngle     \brief the angle covered by the gesture motion      \sa totalRotationAngle, lastRotationAngle */
end_comment
begin_comment
comment|/*!     \property QPinchGesture::startCenterPoint     \brief the starting position of the center point      \sa centerPoint, lastCenterPoint */
end_comment
begin_comment
comment|/*!     \property QPinchGesture::lastCenterPoint     \brief the last position of the center point recorded for this gesture      \sa centerPoint, startCenterPoint */
end_comment
begin_comment
comment|/*!     \property QPinchGesture::centerPoint     \brief the current center point      The center point is the midpoint between the two input points in the gesture.      \sa startCenterPoint, lastCenterPoint */
end_comment
begin_comment
comment|/*!     \internal */
end_comment
begin_constructor
DECL|function|QPinchGesture
name|QPinchGesture
operator|::
name|QPinchGesture
parameter_list|(
name|QObject
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QGesture
argument_list|(
operator|*
operator|new
name|QPinchGesturePrivate
argument_list|,
name|parent
argument_list|)
block|{
name|d_func
argument_list|()
operator|->
name|gestureType
operator|=
name|Qt
operator|::
name|PinchGesture
expr_stmt|;
block|}
end_constructor
begin_function
DECL|function|totalChangeFlags
name|QPinchGesture
operator|::
name|ChangeFlags
name|QPinchGesture
operator|::
name|totalChangeFlags
parameter_list|()
specifier|const
block|{
return|return
name|d_func
argument_list|()
operator|->
name|totalChangeFlags
return|;
block|}
end_function
begin_function
DECL|function|setTotalChangeFlags
name|void
name|QPinchGesture
operator|::
name|setTotalChangeFlags
parameter_list|(
name|QPinchGesture
operator|::
name|ChangeFlags
name|value
parameter_list|)
block|{
name|d_func
argument_list|()
operator|->
name|totalChangeFlags
operator|=
name|value
expr_stmt|;
block|}
end_function
begin_function
DECL|function|changeFlags
name|QPinchGesture
operator|::
name|ChangeFlags
name|QPinchGesture
operator|::
name|changeFlags
parameter_list|()
specifier|const
block|{
return|return
name|d_func
argument_list|()
operator|->
name|changeFlags
return|;
block|}
end_function
begin_function
DECL|function|setChangeFlags
name|void
name|QPinchGesture
operator|::
name|setChangeFlags
parameter_list|(
name|QPinchGesture
operator|::
name|ChangeFlags
name|value
parameter_list|)
block|{
name|d_func
argument_list|()
operator|->
name|changeFlags
operator|=
name|value
expr_stmt|;
block|}
end_function
begin_function
DECL|function|startCenterPoint
name|QPointF
name|QPinchGesture
operator|::
name|startCenterPoint
parameter_list|()
specifier|const
block|{
return|return
name|d_func
argument_list|()
operator|->
name|startCenterPoint
return|;
block|}
end_function
begin_function
DECL|function|lastCenterPoint
name|QPointF
name|QPinchGesture
operator|::
name|lastCenterPoint
parameter_list|()
specifier|const
block|{
return|return
name|d_func
argument_list|()
operator|->
name|lastCenterPoint
return|;
block|}
end_function
begin_function
DECL|function|centerPoint
name|QPointF
name|QPinchGesture
operator|::
name|centerPoint
parameter_list|()
specifier|const
block|{
return|return
name|d_func
argument_list|()
operator|->
name|centerPoint
return|;
block|}
end_function
begin_function
DECL|function|setStartCenterPoint
name|void
name|QPinchGesture
operator|::
name|setStartCenterPoint
parameter_list|(
specifier|const
name|QPointF
modifier|&
name|value
parameter_list|)
block|{
name|d_func
argument_list|()
operator|->
name|startCenterPoint
operator|=
name|value
expr_stmt|;
block|}
end_function
begin_function
DECL|function|setLastCenterPoint
name|void
name|QPinchGesture
operator|::
name|setLastCenterPoint
parameter_list|(
specifier|const
name|QPointF
modifier|&
name|value
parameter_list|)
block|{
name|d_func
argument_list|()
operator|->
name|lastCenterPoint
operator|=
name|value
expr_stmt|;
block|}
end_function
begin_function
DECL|function|setCenterPoint
name|void
name|QPinchGesture
operator|::
name|setCenterPoint
parameter_list|(
specifier|const
name|QPointF
modifier|&
name|value
parameter_list|)
block|{
name|d_func
argument_list|()
operator|->
name|centerPoint
operator|=
name|value
expr_stmt|;
block|}
end_function
begin_function
DECL|function|totalScaleFactor
name|qreal
name|QPinchGesture
operator|::
name|totalScaleFactor
parameter_list|()
specifier|const
block|{
return|return
name|d_func
argument_list|()
operator|->
name|totalScaleFactor
return|;
block|}
end_function
begin_function
DECL|function|lastScaleFactor
name|qreal
name|QPinchGesture
operator|::
name|lastScaleFactor
parameter_list|()
specifier|const
block|{
return|return
name|d_func
argument_list|()
operator|->
name|lastScaleFactor
return|;
block|}
end_function
begin_function
DECL|function|scaleFactor
name|qreal
name|QPinchGesture
operator|::
name|scaleFactor
parameter_list|()
specifier|const
block|{
return|return
name|d_func
argument_list|()
operator|->
name|scaleFactor
return|;
block|}
end_function
begin_function
DECL|function|setTotalScaleFactor
name|void
name|QPinchGesture
operator|::
name|setTotalScaleFactor
parameter_list|(
name|qreal
name|value
parameter_list|)
block|{
name|d_func
argument_list|()
operator|->
name|totalScaleFactor
operator|=
name|value
expr_stmt|;
block|}
end_function
begin_function
DECL|function|setLastScaleFactor
name|void
name|QPinchGesture
operator|::
name|setLastScaleFactor
parameter_list|(
name|qreal
name|value
parameter_list|)
block|{
name|d_func
argument_list|()
operator|->
name|lastScaleFactor
operator|=
name|value
expr_stmt|;
block|}
end_function
begin_function
DECL|function|setScaleFactor
name|void
name|QPinchGesture
operator|::
name|setScaleFactor
parameter_list|(
name|qreal
name|value
parameter_list|)
block|{
name|d_func
argument_list|()
operator|->
name|scaleFactor
operator|=
name|value
expr_stmt|;
block|}
end_function
begin_function
DECL|function|totalRotationAngle
name|qreal
name|QPinchGesture
operator|::
name|totalRotationAngle
parameter_list|()
specifier|const
block|{
return|return
name|d_func
argument_list|()
operator|->
name|totalRotationAngle
return|;
block|}
end_function
begin_function
DECL|function|lastRotationAngle
name|qreal
name|QPinchGesture
operator|::
name|lastRotationAngle
parameter_list|()
specifier|const
block|{
return|return
name|d_func
argument_list|()
operator|->
name|lastRotationAngle
return|;
block|}
end_function
begin_function
DECL|function|rotationAngle
name|qreal
name|QPinchGesture
operator|::
name|rotationAngle
parameter_list|()
specifier|const
block|{
return|return
name|d_func
argument_list|()
operator|->
name|rotationAngle
return|;
block|}
end_function
begin_function
DECL|function|setTotalRotationAngle
name|void
name|QPinchGesture
operator|::
name|setTotalRotationAngle
parameter_list|(
name|qreal
name|value
parameter_list|)
block|{
name|d_func
argument_list|()
operator|->
name|totalRotationAngle
operator|=
name|value
expr_stmt|;
block|}
end_function
begin_function
DECL|function|setLastRotationAngle
name|void
name|QPinchGesture
operator|::
name|setLastRotationAngle
parameter_list|(
name|qreal
name|value
parameter_list|)
block|{
name|d_func
argument_list|()
operator|->
name|lastRotationAngle
operator|=
name|value
expr_stmt|;
block|}
end_function
begin_function
DECL|function|setRotationAngle
name|void
name|QPinchGesture
operator|::
name|setRotationAngle
parameter_list|(
name|qreal
name|value
parameter_list|)
block|{
name|d_func
argument_list|()
operator|->
name|rotationAngle
operator|=
name|value
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     \class QSwipeGesture     \since 4.6     \brief The QSwipeGesture class describes a swipe gesture made by the user.     \ingroup gestures      \image swipegesture.png      For an overview of gesture handling in Qt and information on using gestures     in your applications, see the \l{Gestures Programming} document.      \sa QPanGesture, QPinchGesture */
end_comment
begin_comment
comment|/*!     \enum QSwipeGesture::SwipeDirection      This enum describes the possible directions for the gesture's motion     along the horizontal and vertical axes.      \value NoDirection The gesture had no motion associated with it on a particular axis.     \value Left     The gesture involved a horizontal motion to the left.     \value Right    The gesture involved a horizontal motion to the right.     \value Up       The gesture involved an upward vertical motion.     \value Down     The gesture involved a downward vertical motion. */
end_comment
begin_comment
comment|/*!     \property QSwipeGesture::horizontalDirection     \brief the horizontal direction of the gesture      If the gesture has a horizontal component, the horizontal direction     is either Left or Right; otherwise, it is NoDirection.      \sa verticalDirection, swipeAngle */
end_comment
begin_comment
comment|/*!     \property QSwipeGesture::verticalDirection     \brief the vertical direction of the gesture      If the gesture has a vertical component, the vertical direction     is either Up or Down; otherwise, it is NoDirection.      \sa horizontalDirection, swipeAngle */
end_comment
begin_comment
comment|/*!     \property QSwipeGesture::swipeAngle     \brief the angle of the motion associated with the gesture      If the gesture has either a horizontal or vertical component, the     swipe angle describes the angle between the direction of motion and the     x-axis as defined using the standard widget     \l{Coordinate System}{coordinate system}.      \sa horizontalDirection, verticalDirection */
end_comment
begin_comment
comment|/*!     \property QSwipeGesture::velocity     \since 4.7.1     \internal */
end_comment
begin_comment
comment|/*!     \internal */
end_comment
begin_constructor
DECL|function|QSwipeGesture
name|QSwipeGesture
operator|::
name|QSwipeGesture
parameter_list|(
name|QObject
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QGesture
argument_list|(
operator|*
operator|new
name|QSwipeGesturePrivate
argument_list|,
name|parent
argument_list|)
block|{
name|d_func
argument_list|()
operator|->
name|gestureType
operator|=
name|Qt
operator|::
name|SwipeGesture
expr_stmt|;
block|}
end_constructor
begin_function
DECL|function|horizontalDirection
name|QSwipeGesture
operator|::
name|SwipeDirection
name|QSwipeGesture
operator|::
name|horizontalDirection
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QSwipeGesture
argument_list|)
expr_stmt|;
if|if
condition|(
name|d
operator|->
name|swipeAngle
operator|<
literal|0
operator|||
name|d
operator|->
name|swipeAngle
operator|==
literal|90
operator|||
name|d
operator|->
name|swipeAngle
operator|==
literal|270
condition|)
return|return
name|QSwipeGesture
operator|::
name|NoDirection
return|;
elseif|else
if|if
condition|(
name|d
operator|->
name|swipeAngle
argument_list|<
literal|90
operator|||
name|d
operator|->
name|swipeAngle
argument_list|>
literal|270
condition|)
return|return
name|QSwipeGesture
operator|::
name|Right
return|;
else|else
return|return
name|QSwipeGesture
operator|::
name|Left
return|;
block|}
end_function
begin_function
DECL|function|verticalDirection
name|QSwipeGesture
operator|::
name|SwipeDirection
name|QSwipeGesture
operator|::
name|verticalDirection
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QSwipeGesture
argument_list|)
expr_stmt|;
if|if
condition|(
name|d
operator|->
name|swipeAngle
operator|<=
literal|0
operator|||
name|d
operator|->
name|swipeAngle
operator|==
literal|180
condition|)
return|return
name|QSwipeGesture
operator|::
name|NoDirection
return|;
elseif|else
if|if
condition|(
name|d
operator|->
name|swipeAngle
operator|<
literal|180
condition|)
return|return
name|QSwipeGesture
operator|::
name|Up
return|;
else|else
return|return
name|QSwipeGesture
operator|::
name|Down
return|;
block|}
end_function
begin_function
DECL|function|swipeAngle
name|qreal
name|QSwipeGesture
operator|::
name|swipeAngle
parameter_list|()
specifier|const
block|{
return|return
name|d_func
argument_list|()
operator|->
name|swipeAngle
return|;
block|}
end_function
begin_function
DECL|function|setSwipeAngle
name|void
name|QSwipeGesture
operator|::
name|setSwipeAngle
parameter_list|(
name|qreal
name|value
parameter_list|)
block|{
name|d_func
argument_list|()
operator|->
name|swipeAngle
operator|=
name|value
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     \class QTapGesture     \since 4.6     \brief The QTapGesture class describes a tap gesture made by the user.     \ingroup gestures      For an overview of gesture handling in Qt and information on using gestures     in your applications, see the \l{Gestures Programming} document.      \sa QPanGesture, QPinchGesture */
end_comment
begin_comment
comment|/*!     \property QTapGesture::position     \brief the position of the tap */
end_comment
begin_comment
comment|/*!     \internal */
end_comment
begin_constructor
DECL|function|QTapGesture
name|QTapGesture
operator|::
name|QTapGesture
parameter_list|(
name|QObject
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QGesture
argument_list|(
operator|*
operator|new
name|QTapGesturePrivate
argument_list|,
name|parent
argument_list|)
block|{
name|d_func
argument_list|()
operator|->
name|gestureType
operator|=
name|Qt
operator|::
name|TapGesture
expr_stmt|;
block|}
end_constructor
begin_function
DECL|function|position
name|QPointF
name|QTapGesture
operator|::
name|position
parameter_list|()
specifier|const
block|{
return|return
name|d_func
argument_list|()
operator|->
name|position
return|;
block|}
end_function
begin_function
DECL|function|setPosition
name|void
name|QTapGesture
operator|::
name|setPosition
parameter_list|(
specifier|const
name|QPointF
modifier|&
name|value
parameter_list|)
block|{
name|d_func
argument_list|()
operator|->
name|position
operator|=
name|value
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     \class QTapAndHoldGesture     \since 4.6     \brief The QTapAndHoldGesture class describes a tap-and-hold (aka LongTap)     gesture made by the user.     \ingroup gestures      For an overview of gesture handling in Qt and information on using gestures     in your applications, see the \l{Gestures Programming} document.      \sa QPanGesture, QPinchGesture */
end_comment
begin_comment
comment|/*!     \property QTapAndHoldGesture::position     \brief the position of the tap */
end_comment
begin_comment
comment|/*!     \internal */
end_comment
begin_constructor
DECL|function|QTapAndHoldGesture
name|QTapAndHoldGesture
operator|::
name|QTapAndHoldGesture
parameter_list|(
name|QObject
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QGesture
argument_list|(
operator|*
operator|new
name|QTapAndHoldGesturePrivate
argument_list|,
name|parent
argument_list|)
block|{
name|d_func
argument_list|()
operator|->
name|gestureType
operator|=
name|Qt
operator|::
name|TapAndHoldGesture
expr_stmt|;
block|}
end_constructor
begin_function
DECL|function|position
name|QPointF
name|QTapAndHoldGesture
operator|::
name|position
parameter_list|()
specifier|const
block|{
return|return
name|d_func
argument_list|()
operator|->
name|position
return|;
block|}
end_function
begin_function
DECL|function|setPosition
name|void
name|QTapAndHoldGesture
operator|::
name|setPosition
parameter_list|(
specifier|const
name|QPointF
modifier|&
name|value
parameter_list|)
block|{
name|d_func
argument_list|()
operator|->
name|position
operator|=
name|value
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     Set the timeout, in milliseconds, before the gesture triggers.      The recognizer will detect a touch down and and if \a msecs     later the touch is still down, it will trigger the QTapAndHoldGesture.     The default value is 700 milliseconds. */
end_comment
begin_comment
comment|// static
end_comment
begin_function
DECL|function|setTimeout
name|void
name|QTapAndHoldGesture
operator|::
name|setTimeout
parameter_list|(
name|int
name|msecs
parameter_list|)
block|{
name|QTapAndHoldGesturePrivate
operator|::
name|Timeout
operator|=
name|msecs
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     Gets the timeout, in milliseconds, before the gesture triggers.      The recognizer will detect a touch down and and if timeout()     later the touch is still down, it will trigger the QTapAndHoldGesture.     The default value is 700 milliseconds. */
end_comment
begin_comment
comment|// static
end_comment
begin_function
DECL|function|timeout
name|int
name|QTapAndHoldGesture
operator|::
name|timeout
parameter_list|()
block|{
return|return
name|QTapAndHoldGesturePrivate
operator|::
name|Timeout
return|;
block|}
end_function
begin_decl_stmt
DECL|member|Timeout
name|int
name|QTapAndHoldGesturePrivate
operator|::
name|Timeout
init|=
literal|700
decl_stmt|;
end_decl_stmt
begin_comment
DECL|member|Timeout
comment|// in ms
end_comment
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_include
include|#
directive|include
file|<moc_qgesture.cpp>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_GESTURES
end_comment
end_unit
