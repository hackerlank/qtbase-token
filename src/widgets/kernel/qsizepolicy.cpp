begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the QtWidgets module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qsizepolicy.h"
end_include
begin_include
include|#
directive|include
file|<qdatastream.h>
end_include
begin_include
include|#
directive|include
file|<qdebug.h>
end_include
begin_include
include|#
directive|include
file|<qvariant.h>
end_include
begin_function
name|QT_BEGIN_NAMESPACE
comment|/*!     \class QSizePolicy     \brief The QSizePolicy class is a layout attribute describing horizontal     and vertical resizing policy.      \ingroup geomanagement     \inmodule QtWidgets      The size policy of a widget is an expression of its willingness to     be resized in various ways, and affects how the widget is treated     by the \l{Layout Management}{layout engine}. Each widget returns a     QSizePolicy that describes the horizontal and vertical resizing     policy it prefers when being laid out. You can change this for     a specific widget by changing its QWidget::sizePolicy property.      QSizePolicy contains two independent QSizePolicy::Policy values     and two stretch factors; one describes the widgets's horizontal     size policy, and the other describes its vertical size policy. It     also contains a flag to indicate whether the height and width of     its preferred size are related.      The horizontal and vertical policies can be set in the     constructor, and altered using the setHorizontalPolicy() and     setVerticalPolicy() functions. The stretch factors can be set     using the setHorizontalStretch() and setVerticalStretch()     functions. The flag indicating whether the widget's     \l{QWidget::sizeHint()}{sizeHint()} is width-dependent (such as a     menu bar or a word-wrapping label) can be set using the     setHeightForWidth() function.      The current size policies and stretch factors be retrieved using     the horizontalPolicy(), verticalPolicy(), horizontalStretch() and     verticalStretch() functions. Alternatively, use the transpose()     function to swap the horizontal and vertical policies and     stretches. The hasHeightForWidth() function returns the current     status of the flag indicating the size hint dependencies.      Use the expandingDirections() function to determine whether the     associated widget can make use of more space than its     \l{QWidget::sizeHint()}{sizeHint()} function indicates, as well as     find out in which directions it can expand.      Finally, the QSizePolicy class provides operators comparing this     size policy to a given policy, as well as a QVariant operator     storing this QSizePolicy as a QVariant object.      \sa QSize, QWidget::sizeHint(), QWidget::sizePolicy,     QLayoutItem::sizeHint() */
comment|/*!     \enum QSizePolicy::PolicyFlag      These flags are combined together to form the various \l{Policy}     values:      \value GrowFlag  The widget can grow beyond its size hint if necessary.     \value ExpandFlag  The widget should get as much space as possible.     \value ShrinkFlag  The widget can shrink below its size hint if necessary.     \value IgnoreFlag  The widget's size hint is ignored. The widget will get         as much space as possible.      \sa Policy */
comment|/*!     \enum QSizePolicy::Policy      This enum describes the various per-dimension sizing types used     when constructing a QSizePolicy.      \value Fixed  The QWidget::sizeHint() is the only acceptable         alternative, so the widget can never grow or shrink (e.g. the         vertical direction of a push button).      \value Minimum  The sizeHint() is minimal, and sufficient. The         widget can be expanded, but there is no advantage to it being         larger (e.g. the horizontal direction of a push button).         It cannot be smaller than the size provided by sizeHint().      \value Maximum  The sizeHint() is a maximum. The widget can be         shrunk any amount without detriment if other widgets need the         space (e.g. a separator line).         It cannot be larger than the size provided by sizeHint().      \value Preferred  The sizeHint() is best, but the widget can be         shrunk and still be useful. The widget can be expanded, but there         is no advantage to it being larger than sizeHint() (the default         QWidget policy).      \value Expanding  The sizeHint() is a sensible size, but the         widget can be shrunk and still be useful. The widget can make use         of extra space, so it should get as much space as possible (e.g.         the horizontal direction of a horizontal slider).      \value MinimumExpanding  The sizeHint() is minimal, and sufficient.         The widget can make use of extra space, so it should get as much         space as possible (e.g. the horizontal direction of a horizontal         slider).      \value Ignored  The sizeHint() is ignored. The widget will get as         much space as possible.      \sa PolicyFlag, setHorizontalPolicy(), setVerticalPolicy() */
comment|/*!     \fn QSizePolicy::QSizePolicy()      Constructs a QSizePolicy object with \l Fixed as its horizontal     and vertical policies.      The policies can be altered using the setHorizontalPolicy() and     setVerticalPolicy() functions. Use the setHeightForWidth()     function if the preferred height of the widget is dependent on the     width of the widget (for example, a QLabel with line wrapping).      \sa setHorizontalStretch(), setVerticalStretch() */
comment|/*!     \fn QSizePolicy::QSizePolicy(Policy horizontal, Policy vertical, ControlType type)     \since 4.3      Constructs a QSizePolicy object with the given \a horizontal and     \a vertical policies, and the specified control \a type.      Use setHeightForWidth() if the preferred height of the widget is     dependent on the width of the widget (for example, a QLabel with     line wrapping).      \sa setHorizontalStretch(), setVerticalStretch(), controlType() */
comment|/*!     \fn QSizePolicy::Policy QSizePolicy::horizontalPolicy() const      Returns the horizontal component of the size policy.      \sa setHorizontalPolicy(), verticalPolicy(), horizontalStretch() */
comment|/*!     \fn QSizePolicy::Policy QSizePolicy::verticalPolicy() const      Returns the vertical component of the size policy.      \sa setVerticalPolicy(), horizontalPolicy(), verticalStretch() */
comment|/*!     \fn void QSizePolicy::setHorizontalPolicy(Policy policy)      Sets the horizontal component to the given \a policy.      \sa horizontalPolicy(), setVerticalPolicy(), setHorizontalStretch() */
comment|/*!     \fn void QSizePolicy::setVerticalPolicy(Policy policy)      Sets the vertical component to the given \a policy.      \sa verticalPolicy(), setHorizontalPolicy(), setVerticalStretch() */
comment|/*!     \fn Qt::Orientations QSizePolicy::expandingDirections() const      Returns whether a widget can make use of more space than the     QWidget::sizeHint() function indicates.      A value of Qt::Horizontal or Qt::Vertical means that the widget     can grow horizontally or vertically (i.e., the horizontal or     vertical policy is \l Expanding or \l MinimumExpanding), whereas     Qt::Horizontal | Qt::Vertical means that it can grow in both     dimensions.      \sa horizontalPolicy(), verticalPolicy() */
comment|/*!     \since 4.3      Returns the control type associated with the widget for which     this size policy applies. */
DECL|function|controlType
name|QSizePolicy
operator|::
name|ControlType
name|QSizePolicy
operator|::
name|controlType
parameter_list|()
specifier|const
block|{
return|return
name|QSizePolicy
operator|::
name|ControlType
argument_list|(
literal|1
operator|<<
name|bits
operator|.
name|ctype
argument_list|)
return|;
block|}
end_function
begin_comment
comment|/*!     \since 4.3      Sets the control type associated with the widget for which this     size policy applies to \a type.      The control type specifies the type of the widget for which this     size policy applies. It is used by some styles, notably     QMacStyle, to insert proper spacing between widgets. For example,     the Mac OS X Aqua guidelines specify that push buttons should be     separated by 12 pixels, whereas vertically stacked radio buttons     only require 6 pixels.      \sa QStyle::layoutSpacing() */
end_comment
begin_function
DECL|function|setControlType
name|void
name|QSizePolicy
operator|::
name|setControlType
parameter_list|(
name|ControlType
name|type
parameter_list|)
block|{
comment|/*         The control type is a flag type, with values 0x1, 0x2, 0x4, 0x8, 0x10,         etc. In memory, we pack it onto the available bits (CTSize) in         setControlType(), and unpack it here.          Example:              0x00000001 maps to 0             0x00000002 maps to 1             0x00000004 maps to 2             0x00000008 maps to 3             etc.     */
name|int
name|i
init|=
literal|0
decl_stmt|;
while|while
condition|(
literal|true
condition|)
block|{
if|if
condition|(
name|type
operator|&
operator|(
literal|0x1
operator|<<
name|i
operator|)
condition|)
block|{
name|bits
operator|.
name|ctype
operator|=
name|i
expr_stmt|;
return|return;
block|}
operator|++
name|i
expr_stmt|;
block|}
block|}
end_function
begin_comment
comment|/*!     \fn void QSizePolicy::setHeightForWidth(bool dependent)      Sets the flag determining whether the widget's preferred height     depends on its width, to \a dependent.      \sa hasHeightForWidth(), setWidthForHeight() */
end_comment
begin_comment
comment|/*!     \fn bool QSizePolicy::hasHeightForWidth() const      Returns \c true if the widget's preferred height depends on its     width; otherwise returns \c false.      \sa setHeightForWidth() */
end_comment
begin_comment
comment|/*!     \fn void QSizePolicy::setWidthForHeight(bool dependent)      Sets the flag determining whether the widget's width     depends on its height, to \a dependent.      This is only supported for QGraphicsLayout's subclasses.     It is not possible to have a layout with both height-for-width     and width-for-height constraints at the same time.      \sa hasWidthForHeight(), setHeightForWidth() */
end_comment
begin_comment
comment|/*!     \fn bool QSizePolicy::hasWidthForHeight() const      Returns \c true if the widget's width depends on its     height; otherwise returns \c false.      \sa setWidthForHeight() */
end_comment
begin_comment
comment|/*!     \fn bool QSizePolicy::operator==(const QSizePolicy&other) const      Returns \c true if this policy is equal to \a other; otherwise     returns \c false.      \sa operator!=() */
end_comment
begin_comment
comment|/*!     \fn bool QSizePolicy::operator!=(const QSizePolicy&other) const      Returns \c true if this policy is different from \a other; otherwise     returns \c false.      \sa operator==() */
end_comment
begin_comment
comment|/*!     \fn uint qHash(QSizePolicy key, uint seed = 0)     \since 5.6     \relates QSizePolicy      Returns the hash value for \a key, using     \a seed to seed the calculation. */
end_comment
begin_comment
comment|/*!     \fn int QSizePolicy::horizontalStretch() const      Returns the horizontal stretch factor of the size policy.      \sa setHorizontalStretch(), verticalStretch(), horizontalPolicy() */
end_comment
begin_comment
comment|/*!     \fn int QSizePolicy::verticalStretch() const      Returns the vertical stretch factor of the size policy.      \sa setVerticalStretch(), horizontalStretch(), verticalPolicy() */
end_comment
begin_comment
comment|/*!     \fn void QSizePolicy::setHorizontalStretch(int stretchFactor)      Sets the horizontal stretch factor of the size policy to the given \a     stretchFactor. \a stretchFactor must be in the range [0,255].      When two widgets are adjacent to each other in a horizontal layout,     setting the horizontal stretch factor of the widget on the left to 2     and the factor of widget on the right to 1 will ensure that the widget     on the left will always be twice the size of the one on the right.      \sa horizontalStretch(), setVerticalStretch(), setHorizontalPolicy() */
end_comment
begin_comment
comment|/*!     \fn void QSizePolicy::setVerticalStretch(int stretchFactor)      Sets the vertical stretch factor of the size policy to the given     \a stretchFactor. \a stretchFactor must be in the range [0,255].      When two widgets are adjacent to each other in a vertical layout,     setting the vertical stretch factor of the widget on the top to 2     and the factor of widget on the bottom to 1 will ensure that     the widget on the top will always be twice the size of the one     on the bottom.      \sa verticalStretch(), setHorizontalStretch(), setVerticalPolicy() */
end_comment
begin_comment
comment|/*!     \fn void QSizePolicy::transpose()      Swaps the horizontal and vertical policies and stretches. */
end_comment
begin_comment
comment|/*!     \fn void QSizePolicy::retainSizeWhenHidden() const     \since 5.2      Returns whether the layout should retain the widget's size when it is hidden.     This is \c false by default.      \sa setRetainSizeWhenHidden() */
end_comment
begin_comment
comment|/*!    \fn void QSizePolicy::setRetainSizeWhenHidden(bool retainSize)    \since 5.2      Sets whether a layout should retain the widget's size when it is hidden.     If \a retainSize is \c true, the layout will not be changed by hiding the widget.      \sa retainSizeWhenHidden() */
end_comment
begin_comment
comment|/*!     \enum QSizePolicy::ControlType     \since 4.3      This enum specifies the different types of widgets in terms of     layout interaction:      \value DefaultType  The default type, when none is specified.     \value ButtonBox  A QDialogButtonBox instance.     \value CheckBox  A QCheckBox instance.     \value ComboBox  A QComboBox instance.     \value Frame  A QFrame instance.     \value GroupBox  A QGroupBox instance.     \value Label  A QLabel instance.     \value Line  A QFrame instance with QFrame::HLine or QFrame::VLine.     \value LineEdit  A QLineEdit instance.     \value PushButton  A QPushButton instance.     \value RadioButton  A QRadioButton instance.     \value Slider  A QAbstractSlider instance.     \value SpinBox  A QAbstractSpinBox instance.     \value TabWidget  A QTabWidget instance.     \value ToolButton  A QToolButton instance.      \sa setControlType(), controlType() */
end_comment
begin_comment
comment|/*!    Returns a QVariant storing this QSizePolicy. */
end_comment
begin_function
DECL|function|operator QVariant
name|QSizePolicy
operator|::
name|operator
name|QVariant
parameter_list|()
specifier|const
block|{
return|return
name|QVariant
argument_list|(
name|QVariant
operator|::
name|SizePolicy
argument_list|,
name|this
argument_list|)
return|;
block|}
end_function
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_DATASTREAM
end_ifndef
begin_comment
comment|/*!     \relates QSizePolicy     \since 4.2      Writes the size \a policy to the data stream \a stream.      \sa{Serializing Qt Data Types}{Format of the QDataStream operators} */
end_comment
begin_function
DECL|function|operator <<
name|QDataStream
modifier|&
name|operator
name|<<
parameter_list|(
name|QDataStream
modifier|&
name|stream
parameter_list|,
specifier|const
name|QSizePolicy
modifier|&
name|policy
parameter_list|)
block|{
comment|// The order here is for historical reasons. (compatibility with Qt4)
name|quint32
name|data
init|=
operator|(
name|policy
operator|.
name|bits
operator|.
name|horPolicy
operator||
comment|// [0, 3]
name|policy
operator|.
name|bits
operator|.
name|verPolicy
operator|<<
literal|4
operator||
comment|// [4, 7]
name|policy
operator|.
name|bits
operator|.
name|hfw
operator|<<
literal|8
operator||
comment|// [8]
name|policy
operator|.
name|bits
operator|.
name|ctype
operator|<<
literal|9
operator||
comment|// [9, 13]
name|policy
operator|.
name|bits
operator|.
name|wfh
operator|<<
literal|14
operator||
comment|// [14]
name|policy
operator|.
name|bits
operator|.
name|retainSizeWhenHidden
operator|<<
literal|15
operator||
comment|// [15]
name|policy
operator|.
name|bits
operator|.
name|verStretch
operator|<<
literal|16
operator||
comment|// [16, 23]
name|policy
operator|.
name|bits
operator|.
name|horStretch
operator|<<
literal|24
operator|)
decl_stmt|;
comment|// [24, 31]
return|return
name|stream
operator|<<
name|data
return|;
block|}
end_function
begin_define
DECL|macro|VALUE_OF_BITS
define|#
directive|define
name|VALUE_OF_BITS
parameter_list|(
name|data
parameter_list|,
name|bitstart
parameter_list|,
name|bitcount
parameter_list|)
value|((data>> bitstart)& ((1<< bitcount) -1))
end_define
begin_comment
comment|/*!     \relates QSizePolicy     \since 4.2      Reads the size \a policy from the data stream \a stream.      \sa{Serializing Qt Data Types}{Format of the QDataStream operators} */
end_comment
begin_function
DECL|function|operator >>
name|QDataStream
modifier|&
name|operator
name|>>
parameter_list|(
name|QDataStream
modifier|&
name|stream
parameter_list|,
name|QSizePolicy
modifier|&
name|policy
parameter_list|)
block|{
name|quint32
name|data
decl_stmt|;
name|stream
operator|>>
name|data
expr_stmt|;
name|policy
operator|.
name|bits
operator|.
name|horPolicy
operator|=
name|VALUE_OF_BITS
argument_list|(
name|data
argument_list|,
literal|0
argument_list|,
literal|4
argument_list|)
expr_stmt|;
name|policy
operator|.
name|bits
operator|.
name|verPolicy
operator|=
name|VALUE_OF_BITS
argument_list|(
name|data
argument_list|,
literal|4
argument_list|,
literal|4
argument_list|)
expr_stmt|;
name|policy
operator|.
name|bits
operator|.
name|hfw
operator|=
name|VALUE_OF_BITS
argument_list|(
name|data
argument_list|,
literal|8
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|policy
operator|.
name|bits
operator|.
name|ctype
operator|=
name|VALUE_OF_BITS
argument_list|(
name|data
argument_list|,
literal|9
argument_list|,
literal|5
argument_list|)
expr_stmt|;
name|policy
operator|.
name|bits
operator|.
name|wfh
operator|=
name|VALUE_OF_BITS
argument_list|(
name|data
argument_list|,
literal|14
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|policy
operator|.
name|bits
operator|.
name|retainSizeWhenHidden
operator|=
name|VALUE_OF_BITS
argument_list|(
name|data
argument_list|,
literal|15
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|policy
operator|.
name|bits
operator|.
name|verStretch
operator|=
name|VALUE_OF_BITS
argument_list|(
name|data
argument_list|,
literal|16
argument_list|,
literal|8
argument_list|)
expr_stmt|;
name|policy
operator|.
name|bits
operator|.
name|horStretch
operator|=
name|VALUE_OF_BITS
argument_list|(
name|data
argument_list|,
literal|24
argument_list|,
literal|8
argument_list|)
expr_stmt|;
return|return
name|stream
return|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_DATASTREAM
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_DEBUG_STREAM
end_ifndef
begin_function
DECL|function|operator <<
name|QDebug
name|operator
name|<<
parameter_list|(
name|QDebug
name|dbg
parameter_list|,
specifier|const
name|QSizePolicy
modifier|&
name|p
parameter_list|)
block|{
name|QDebugStateSaver
name|saver
argument_list|(
name|dbg
argument_list|)
decl_stmt|;
name|dbg
operator|.
name|nospace
argument_list|()
operator|<<
literal|"QSizePolicy(horizontalPolicy = "
operator|<<
name|p
operator|.
name|horizontalPolicy
argument_list|()
operator|<<
literal|", verticalPolicy = "
operator|<<
name|p
operator|.
name|verticalPolicy
argument_list|()
operator|<<
literal|')'
expr_stmt|;
return|return
name|dbg
return|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_include
include|#
directive|include
file|"moc_qsizepolicy.cpp"
end_include
end_unit
