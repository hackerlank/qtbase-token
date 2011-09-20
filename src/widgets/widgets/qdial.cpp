begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qdial.h"
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_DIAL
end_ifndef
begin_include
include|#
directive|include
file|<qapplication.h>
end_include
begin_include
include|#
directive|include
file|<qbitmap.h>
end_include
begin_include
include|#
directive|include
file|<qcolor.h>
end_include
begin_include
include|#
directive|include
file|<qevent.h>
end_include
begin_include
include|#
directive|include
file|<qpainter.h>
end_include
begin_include
include|#
directive|include
file|<qpolygon.h>
end_include
begin_include
include|#
directive|include
file|<qregion.h>
end_include
begin_include
include|#
directive|include
file|<qstyle.h>
end_include
begin_include
include|#
directive|include
file|<qstylepainter.h>
end_include
begin_include
include|#
directive|include
file|<qstyleoption.h>
end_include
begin_include
include|#
directive|include
file|<qslider.h>
end_include
begin_include
include|#
directive|include
file|<private/qabstractslider_p.h>
end_include
begin_include
include|#
directive|include
file|<private/qmath_p.h>
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_ACCESSIBILITY
end_ifndef
begin_include
include|#
directive|include
file|"qaccessible.h"
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_include
include|#
directive|include
file|<qmath.h>
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_class
DECL|class|QDialPrivate
class|class
name|QDialPrivate
super|:
specifier|public
name|QAbstractSliderPrivate
block|{
name|Q_DECLARE_PUBLIC
parameter_list|(
name|QDial
parameter_list|)
specifier|public
private|:
DECL|function|QDialPrivate
name|QDialPrivate
parameter_list|()
block|{
name|wrapping
operator|=
literal|false
expr_stmt|;
name|tracking
operator|=
literal|true
expr_stmt|;
name|doNotEmit
operator|=
literal|false
expr_stmt|;
name|target
operator|=
name|qreal
argument_list|(
literal|3.7
argument_list|)
expr_stmt|;
block|}
DECL|member|target
name|qreal
name|target
decl_stmt|;
name|uint
name|showNotches
range|:
literal|1
decl_stmt|;
name|uint
name|wrapping
range|:
literal|1
decl_stmt|;
name|uint
name|doNotEmit
range|:
literal|1
decl_stmt|;
name|int
name|valueFromPoint
parameter_list|(
specifier|const
name|QPoint
modifier|&
parameter_list|)
specifier|const
function_decl|;
name|double
name|angle
parameter_list|(
specifier|const
name|QPoint
modifier|&
parameter_list|,
specifier|const
name|QPoint
modifier|&
parameter_list|)
specifier|const
function_decl|;
name|void
name|init
parameter_list|()
function_decl|;
specifier|virtual
name|int
name|bound
parameter_list|(
name|int
name|val
parameter_list|)
specifier|const
function_decl|;
block|}
class|;
end_class
begin_function
DECL|function|init
name|void
name|QDialPrivate
operator|::
name|init
parameter_list|()
block|{
name|Q_Q
argument_list|(
name|QDial
argument_list|)
expr_stmt|;
name|showNotches
operator|=
literal|false
expr_stmt|;
name|q
operator|->
name|setFocusPolicy
argument_list|(
name|Qt
operator|::
name|WheelFocus
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|bound
name|int
name|QDialPrivate
operator|::
name|bound
parameter_list|(
name|int
name|val
parameter_list|)
specifier|const
block|{
if|if
condition|(
name|wrapping
condition|)
block|{
if|if
condition|(
operator|(
name|val
operator|>=
name|minimum
operator|)
operator|&&
operator|(
name|val
operator|<=
name|maximum
operator|)
condition|)
return|return
name|val
return|;
name|val
operator|=
name|minimum
operator|+
operator|(
operator|(
name|val
operator|-
name|minimum
operator|)
operator|%
operator|(
name|maximum
operator|-
name|minimum
operator|)
operator|)
expr_stmt|;
if|if
condition|(
name|val
operator|<
name|minimum
condition|)
name|val
operator|+=
name|maximum
operator|-
name|minimum
expr_stmt|;
return|return
name|val
return|;
block|}
else|else
block|{
return|return
name|QAbstractSliderPrivate
operator|::
name|bound
argument_list|(
name|val
argument_list|)
return|;
block|}
block|}
end_function
begin_comment
comment|/*!     Initialize \a option with the values from this QDial. This method     is useful for subclasses when they need a QStyleOptionSlider, but don't want     to fill in all the information themselves.      \sa QStyleOption::initFrom() */
end_comment
begin_function
DECL|function|initStyleOption
name|void
name|QDial
operator|::
name|initStyleOption
parameter_list|(
name|QStyleOptionSlider
modifier|*
name|option
parameter_list|)
specifier|const
block|{
if|if
condition|(
operator|!
name|option
condition|)
return|return;
name|Q_D
argument_list|(
specifier|const
name|QDial
argument_list|)
expr_stmt|;
name|option
operator|->
name|initFrom
argument_list|(
name|this
argument_list|)
expr_stmt|;
name|option
operator|->
name|minimum
operator|=
name|d
operator|->
name|minimum
expr_stmt|;
name|option
operator|->
name|maximum
operator|=
name|d
operator|->
name|maximum
expr_stmt|;
name|option
operator|->
name|sliderPosition
operator|=
name|d
operator|->
name|position
expr_stmt|;
name|option
operator|->
name|sliderValue
operator|=
name|d
operator|->
name|value
expr_stmt|;
name|option
operator|->
name|singleStep
operator|=
name|d
operator|->
name|singleStep
expr_stmt|;
name|option
operator|->
name|pageStep
operator|=
name|d
operator|->
name|pageStep
expr_stmt|;
name|option
operator|->
name|upsideDown
operator|=
operator|!
name|d
operator|->
name|invertedAppearance
expr_stmt|;
name|option
operator|->
name|notchTarget
operator|=
name|d
operator|->
name|target
expr_stmt|;
name|option
operator|->
name|dialWrapping
operator|=
name|d
operator|->
name|wrapping
expr_stmt|;
name|option
operator|->
name|subControls
operator|=
name|QStyle
operator|::
name|SC_All
expr_stmt|;
name|option
operator|->
name|activeSubControls
operator|=
name|QStyle
operator|::
name|SC_None
expr_stmt|;
if|if
condition|(
operator|!
name|d
operator|->
name|showNotches
condition|)
block|{
name|option
operator|->
name|subControls
operator|&=
operator|~
name|QStyle
operator|::
name|SC_DialTickmarks
expr_stmt|;
name|option
operator|->
name|tickPosition
operator|=
name|QSlider
operator|::
name|TicksAbove
expr_stmt|;
block|}
else|else
block|{
name|option
operator|->
name|tickPosition
operator|=
name|QSlider
operator|::
name|NoTicks
expr_stmt|;
block|}
name|option
operator|->
name|tickInterval
operator|=
name|notchSize
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|valueFromPoint
name|int
name|QDialPrivate
operator|::
name|valueFromPoint
parameter_list|(
specifier|const
name|QPoint
modifier|&
name|p
parameter_list|)
specifier|const
block|{
name|Q_Q
argument_list|(
specifier|const
name|QDial
argument_list|)
expr_stmt|;
name|double
name|yy
init|=
operator|(
name|double
operator|)
name|q
operator|->
name|height
argument_list|()
operator|/
literal|2.0
operator|-
name|p
operator|.
name|y
argument_list|()
decl_stmt|;
name|double
name|xx
init|=
operator|(
name|double
operator|)
name|p
operator|.
name|x
argument_list|()
operator|-
name|q
operator|->
name|width
argument_list|()
operator|/
literal|2.0
decl_stmt|;
name|double
name|a
init|=
operator|(
name|xx
operator|||
name|yy
operator|)
condition|?
name|qAtan2
argument_list|(
name|yy
argument_list|,
name|xx
argument_list|)
else|:
literal|0
decl_stmt|;
if|if
condition|(
name|a
operator|<
name|Q_PI
operator|/
operator|-
literal|2
condition|)
name|a
operator|=
name|a
operator|+
name|Q_PI
operator|*
literal|2
expr_stmt|;
name|int
name|dist
init|=
literal|0
decl_stmt|;
name|int
name|minv
init|=
name|minimum
decl_stmt|,
name|maxv
init|=
name|maximum
decl_stmt|;
if|if
condition|(
name|minimum
operator|<
literal|0
condition|)
block|{
name|dist
operator|=
operator|-
name|minimum
expr_stmt|;
name|minv
operator|=
literal|0
expr_stmt|;
name|maxv
operator|=
name|maximum
operator|+
name|dist
expr_stmt|;
block|}
name|int
name|r
init|=
name|maxv
operator|-
name|minv
decl_stmt|;
name|int
name|v
decl_stmt|;
if|if
condition|(
name|wrapping
condition|)
name|v
operator|=
call|(
name|int
call|)
argument_list|(
literal|0.5
operator|+
name|minv
operator|+
name|r
operator|*
operator|(
name|Q_PI
operator|*
literal|3
operator|/
literal|2
operator|-
name|a
operator|)
operator|/
operator|(
literal|2
operator|*
name|Q_PI
operator|)
argument_list|)
expr_stmt|;
else|else
name|v
operator|=
call|(
name|int
call|)
argument_list|(
literal|0.5
operator|+
name|minv
operator|+
name|r
operator|*
operator|(
name|Q_PI
operator|*
literal|4
operator|/
literal|3
operator|-
name|a
operator|)
operator|/
operator|(
name|Q_PI
operator|*
literal|10
operator|/
literal|6
operator|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|dist
operator|>
literal|0
condition|)
name|v
operator|-=
name|dist
expr_stmt|;
return|return
operator|!
name|invertedAppearance
condition|?
name|bound
argument_list|(
name|v
argument_list|)
else|:
name|maximum
operator|-
name|bound
argument_list|(
name|v
argument_list|)
return|;
block|}
end_function
begin_comment
comment|/*!     \class QDial      \brief The QDial class provides a rounded range control (like a speedometer or potentiometer).      \ingroup basicwidgets     \inmodule QtWidgets      QDial is used when the user needs to control a value within a     program-definable range, and the range either wraps around     (for example, with angles measured from 0 to 359 degrees) or the     dialog layout needs a square widget.      Since QDial inherits from QAbstractSlider, the dial behaves in     a similar way to a \l{QSlider}{slider}. When wrapping() is false     (the default setting) there is no real difference between a slider     and a dial. They both share the same signals, slots and member     functions. Which one you use depends on the expectations of     your users and on the type of application.      The dial initially emits valueChanged() signals continuously while     the slider is being moved; you can make it emit the signal less     often by disabling the \l{QAbstractSlider::tracking} {tracking}     property. The sliderMoved() signal is emitted continuously even     when tracking is disabled.      The dial also emits sliderPressed() and sliderReleased() signals     when the mouse button is pressed and released. Note that the     dial's value can change without these signals being emitted since     the keyboard and wheel can also be used to change the value.      Unlike the slider, QDial attempts to draw a "nice" number of     notches rather than one per line step. If possible, the number of     notches drawn is one per line step, but if there aren't enough pixels     to draw every one, QDial will skip notches to try and draw a uniform     set (e.g. by drawing every second or third notch).      Like the slider, the dial makes the QAbstractSlider functions     setValue(), addLine(), subtractLine(), addPage() and     subtractPage() available as slots.      The dial's keyboard interface is fairly simple: The     \key{left}/\key{up} and \key{right}/\key{down} arrow keys adjust     the dial's \l {QAbstractSlider::value} {value} by the defined     \l {QAbstractSlider::singleStep} {singleStep}, \key{Page Up} and     \key{Page Down} by the defined \l {QAbstractSlider::pageStep}     {pageStep}, and the \key Home and \key End keys set the value to     the defined \l {QAbstractSlider::minimum} {minimum} and     \l {QAbstractSlider::maximum} {maximum} values.      If you are using the mouse wheel to adjust the dial, the increment     value is determined by the lesser value of     \l{QApplication::wheelScrollLines()} {wheelScrollLines} multipled     by \l {QAbstractSlider::singleStep} {singleStep}, and     \l {QAbstractSlider::pageStep} {pageStep}.      \table     \row \o \inlineimage plastique-dial.png Screenshot of a dial in the Plastique widget style     \o \inlineimage windowsxp-dial.png Screenshot of a dial in the Windows XP widget style     \o \inlineimage macintosh-dial.png Screenshot of a dial in the Macintosh widget style     \row \o {3,1} Dials shown in various widget styles (from left to right):          \l{Plastique Style Widget Gallery}{Plastique},          \l{Windows XP Style Widget Gallery}{Windows XP},          \l{Macintosh Style Widget Gallery}{Macintosh}.     \endtable      \sa QScrollBar, QSpinBox, QSlider, {fowler}{GUI Design Handbook: Slider}, {Sliders Example} */
end_comment
begin_comment
comment|/*!     Constructs a dial.      The \a parent argument is sent to the QAbstractSlider constructor. */
end_comment
begin_constructor
DECL|function|QDial
name|QDial
operator|::
name|QDial
parameter_list|(
name|QWidget
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QAbstractSlider
argument_list|(
operator|*
operator|new
name|QDialPrivate
argument_list|,
name|parent
argument_list|)
block|{
name|Q_D
argument_list|(
name|QDial
argument_list|)
expr_stmt|;
name|d
operator|->
name|init
argument_list|()
expr_stmt|;
block|}
end_constructor
begin_comment
comment|/*!     Destroys the dial. */
end_comment
begin_destructor
DECL|function|~QDial
name|QDial
operator|::
name|~
name|QDial
parameter_list|()
block|{ }
end_destructor
begin_comment
comment|/*! \reimp */
end_comment
begin_function
DECL|function|resizeEvent
name|void
name|QDial
operator|::
name|resizeEvent
parameter_list|(
name|QResizeEvent
modifier|*
name|e
parameter_list|)
block|{
name|QWidget
operator|::
name|resizeEvent
argument_list|(
name|e
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!   \reimp */
end_comment
begin_function
DECL|function|paintEvent
name|void
name|QDial
operator|::
name|paintEvent
parameter_list|(
name|QPaintEvent
modifier|*
parameter_list|)
block|{
name|QStylePainter
name|p
argument_list|(
name|this
argument_list|)
decl_stmt|;
name|QStyleOptionSlider
name|option
decl_stmt|;
name|initStyleOption
argument_list|(
operator|&
name|option
argument_list|)
expr_stmt|;
name|p
operator|.
name|drawComplexControl
argument_list|(
name|QStyle
operator|::
name|CC_Dial
argument_list|,
name|option
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!   \reimp */
end_comment
begin_function
DECL|function|mousePressEvent
name|void
name|QDial
operator|::
name|mousePressEvent
parameter_list|(
name|QMouseEvent
modifier|*
name|e
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QDial
argument_list|)
expr_stmt|;
if|if
condition|(
name|d
operator|->
name|maximum
operator|==
name|d
operator|->
name|minimum
operator|||
operator|(
name|e
operator|->
name|button
argument_list|()
operator|!=
name|Qt
operator|::
name|LeftButton
operator|)
operator|||
operator|(
name|e
operator|->
name|buttons
argument_list|()
operator|^
name|e
operator|->
name|button
argument_list|()
operator|)
condition|)
block|{
name|e
operator|->
name|ignore
argument_list|()
expr_stmt|;
return|return;
block|}
name|e
operator|->
name|accept
argument_list|()
expr_stmt|;
name|setSliderPosition
argument_list|(
name|d
operator|->
name|valueFromPoint
argument_list|(
name|e
operator|->
name|pos
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
comment|// ### This isn't quite right,
comment|// we should be doing a hit test and only setting this if it's
comment|// the actual dial thingie (similar to what QSlider does), but we have no
comment|// subControls for QDial.
name|setSliderDown
argument_list|(
literal|true
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!   \reimp */
end_comment
begin_function
DECL|function|mouseReleaseEvent
name|void
name|QDial
operator|::
name|mouseReleaseEvent
parameter_list|(
name|QMouseEvent
modifier|*
name|e
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QDial
argument_list|)
expr_stmt|;
if|if
condition|(
name|e
operator|->
name|buttons
argument_list|()
operator|&
operator|(
name|~
name|e
operator|->
name|button
argument_list|()
operator|)
operator|||
operator|(
name|e
operator|->
name|button
argument_list|()
operator|!=
name|Qt
operator|::
name|LeftButton
operator|)
condition|)
block|{
name|e
operator|->
name|ignore
argument_list|()
expr_stmt|;
return|return;
block|}
name|e
operator|->
name|accept
argument_list|()
expr_stmt|;
name|setValue
argument_list|(
name|d
operator|->
name|valueFromPoint
argument_list|(
name|e
operator|->
name|pos
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|setSliderDown
argument_list|(
literal|false
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!   \reimp */
end_comment
begin_function
DECL|function|mouseMoveEvent
name|void
name|QDial
operator|::
name|mouseMoveEvent
parameter_list|(
name|QMouseEvent
modifier|*
name|e
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QDial
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
operator|(
name|e
operator|->
name|buttons
argument_list|()
operator|&
name|Qt
operator|::
name|LeftButton
operator|)
condition|)
block|{
name|e
operator|->
name|ignore
argument_list|()
expr_stmt|;
return|return;
block|}
name|e
operator|->
name|accept
argument_list|()
expr_stmt|;
name|d
operator|->
name|doNotEmit
operator|=
literal|true
expr_stmt|;
name|setSliderPosition
argument_list|(
name|d
operator|->
name|valueFromPoint
argument_list|(
name|e
operator|->
name|pos
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|d
operator|->
name|doNotEmit
operator|=
literal|false
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     \reimp */
end_comment
begin_function
DECL|function|sliderChange
name|void
name|QDial
operator|::
name|sliderChange
parameter_list|(
name|SliderChange
name|change
parameter_list|)
block|{
name|QAbstractSlider
operator|::
name|sliderChange
argument_list|(
name|change
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|setWrapping
name|void
name|QDial
operator|::
name|setWrapping
parameter_list|(
name|bool
name|enable
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QDial
argument_list|)
expr_stmt|;
if|if
condition|(
name|d
operator|->
name|wrapping
operator|==
name|enable
condition|)
return|return;
name|d
operator|->
name|wrapping
operator|=
name|enable
expr_stmt|;
name|update
argument_list|()
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     \property QDial::wrapping     \brief whether wrapping is enabled      If true, wrapping is enabled; otherwise some space is inserted at the bottom     of the dial to separate the ends of the range of valid values.      If enabled, the arrow can be oriented at any angle on the dial. If disabled,     the arrow will be restricted to the upper part of the dial; if it is rotated     into the space at the bottom of the dial, it will be clamped to the closest     end of the valid range of values.      By default this property is false. */
end_comment
begin_function
DECL|function|wrapping
name|bool
name|QDial
operator|::
name|wrapping
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QDial
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|wrapping
return|;
block|}
end_function
begin_comment
comment|/*!     \property QDial::notchSize     \brief the current notch size      The notch size is in range control units, not pixels, and if     possible it is a multiple of singleStep() that results in an     on-screen notch size near notchTarget().      By default, this property has a value of 1.      \sa notchTarget(), singleStep() */
end_comment
begin_function
DECL|function|notchSize
name|int
name|QDial
operator|::
name|notchSize
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QDial
argument_list|)
expr_stmt|;
comment|// radius of the arc
name|int
name|r
init|=
name|qMin
argument_list|(
name|width
argument_list|()
argument_list|,
name|height
argument_list|()
argument_list|)
operator|/
literal|2
decl_stmt|;
comment|// length of the whole arc
name|int
name|l
init|=
call|(
name|int
call|)
argument_list|(
name|r
operator|*
operator|(
name|d
operator|->
name|wrapping
condition|?
literal|6
else|:
literal|5
operator|)
operator|*
name|Q_PI
operator|/
literal|6
argument_list|)
decl_stmt|;
comment|// length of the arc from minValue() to minValue()+pageStep()
if|if
condition|(
name|d
operator|->
name|maximum
operator|>
name|d
operator|->
name|minimum
operator|+
name|d
operator|->
name|pageStep
condition|)
name|l
operator|=
call|(
name|int
call|)
argument_list|(
literal|0.5
operator|+
name|l
operator|*
name|d
operator|->
name|pageStep
operator|/
operator|(
name|d
operator|->
name|maximum
operator|-
name|d
operator|->
name|minimum
operator|)
argument_list|)
expr_stmt|;
comment|// length of a singleStep arc
name|l
operator|=
name|l
operator|*
name|d
operator|->
name|singleStep
operator|/
operator|(
name|d
operator|->
name|pageStep
condition|?
name|d
operator|->
name|pageStep
else|:
literal|1
operator|)
expr_stmt|;
if|if
condition|(
name|l
operator|<
literal|1
condition|)
name|l
operator|=
literal|1
expr_stmt|;
comment|// how many times singleStep can be draw in d->target pixels
name|l
operator|=
call|(
name|int
call|)
argument_list|(
literal|0.5
operator|+
name|d
operator|->
name|target
operator|/
name|l
argument_list|)
expr_stmt|;
comment|// we want notchSize() to be a non-zero multiple of lineStep()
if|if
condition|(
operator|!
name|l
condition|)
name|l
operator|=
literal|1
expr_stmt|;
return|return
name|d
operator|->
name|singleStep
operator|*
name|l
return|;
block|}
end_function
begin_function
DECL|function|setNotchTarget
name|void
name|QDial
operator|::
name|setNotchTarget
parameter_list|(
name|double
name|target
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QDial
argument_list|)
expr_stmt|;
name|d
operator|->
name|target
operator|=
name|target
expr_stmt|;
name|update
argument_list|()
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     \property QDial::notchTarget     \brief the target number of pixels between notches      The notch target is the number of pixels QDial attempts to put     between each notch.      The actual size may differ from the target size.      The default notch target is 3.7 pixels. */
end_comment
begin_function
DECL|function|notchTarget
name|qreal
name|QDial
operator|::
name|notchTarget
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QDial
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|target
return|;
block|}
end_function
begin_function
DECL|function|setNotchesVisible
name|void
name|QDial
operator|::
name|setNotchesVisible
parameter_list|(
name|bool
name|visible
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QDial
argument_list|)
expr_stmt|;
name|d
operator|->
name|showNotches
operator|=
name|visible
expr_stmt|;
name|update
argument_list|()
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     \property QDial::notchesVisible     \brief whether the notches are shown      If the property is true, a series of notches are drawn around the dial     to indicate the range of values available; otherwise no notches are     shown.      By default, this property is disabled. */
end_comment
begin_function
DECL|function|notchesVisible
name|bool
name|QDial
operator|::
name|notchesVisible
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QDial
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|showNotches
return|;
block|}
end_function
begin_comment
comment|/*!   \reimp */
end_comment
begin_function
DECL|function|minimumSizeHint
name|QSize
name|QDial
operator|::
name|minimumSizeHint
parameter_list|()
specifier|const
block|{
return|return
name|QSize
argument_list|(
literal|50
argument_list|,
literal|50
argument_list|)
return|;
block|}
end_function
begin_comment
comment|/*!   \reimp */
end_comment
begin_function
DECL|function|sizeHint
name|QSize
name|QDial
operator|::
name|sizeHint
parameter_list|()
specifier|const
block|{
return|return
name|QSize
argument_list|(
literal|100
argument_list|,
literal|100
argument_list|)
operator|.
name|expandedTo
argument_list|(
name|QApplication
operator|::
name|globalStrut
argument_list|()
argument_list|)
return|;
block|}
end_function
begin_comment
comment|/*!   \reimp */
end_comment
begin_function
DECL|function|event
name|bool
name|QDial
operator|::
name|event
parameter_list|(
name|QEvent
modifier|*
name|e
parameter_list|)
block|{
return|return
name|QAbstractSlider
operator|::
name|event
argument_list|(
name|e
argument_list|)
return|;
block|}
end_function
begin_comment
comment|/*!     \fn void QDial::dialPressed();      Use QAbstractSlider::sliderPressed() instead. */
end_comment
begin_comment
comment|/*!     \fn void QDial::dialMoved(int value);      Use QAbstractSlider::sliderMoved() instead. */
end_comment
begin_comment
comment|/*!     \fn void QDial::dialReleased();      Use QAbstractSlider::sliderReleased() instead. */
end_comment
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_DIAL
end_comment
end_unit
