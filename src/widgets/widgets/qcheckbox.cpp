begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qcheckbox.h"
end_include
begin_include
include|#
directive|include
file|"qapplication.h"
end_include
begin_include
include|#
directive|include
file|"qbitmap.h"
end_include
begin_include
include|#
directive|include
file|"qicon.h"
end_include
begin_include
include|#
directive|include
file|"qstylepainter.h"
end_include
begin_include
include|#
directive|include
file|"qstyle.h"
end_include
begin_include
include|#
directive|include
file|"qstyleoption.h"
end_include
begin_include
include|#
directive|include
file|"qevent.h"
end_include
begin_include
include|#
directive|include
file|"private/qabstractbutton_p.h"
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_class
DECL|class|QCheckBoxPrivate
class|class
name|QCheckBoxPrivate
super|:
specifier|public
name|QAbstractButtonPrivate
block|{
name|Q_DECLARE_PUBLIC
parameter_list|(
name|QCheckBox
parameter_list|)
specifier|public
private|:
DECL|function|QCheckBoxPrivate
name|QCheckBoxPrivate
parameter_list|()
member_init_list|:
name|QAbstractButtonPrivate
argument_list|(
name|QSizePolicy
operator|::
name|CheckBox
argument_list|)
member_init_list|,
name|tristate
argument_list|(
literal|false
argument_list|)
member_init_list|,
name|noChange
argument_list|(
literal|false
argument_list|)
member_init_list|,
name|hovering
argument_list|(
literal|true
argument_list|)
member_init_list|,
name|publishedState
argument_list|(
name|Qt
operator|::
name|Unchecked
argument_list|)
block|{}
name|uint
name|tristate
range|:
literal|1
decl_stmt|;
name|uint
name|noChange
range|:
literal|1
decl_stmt|;
name|uint
name|hovering
range|:
literal|1
decl_stmt|;
name|uint
name|publishedState
range|:
literal|2
decl_stmt|;
name|void
name|init
parameter_list|()
function_decl|;
block|}
class|;
end_class
begin_comment
comment|/*!     \class QCheckBox     \brief The QCheckBox widget provides a checkbox with a text label.      \ingroup basicwidgets     \inmodule QtWidgets      A QCheckBox is an option button that can be switched on (checked) or off     (unchecked). Checkboxes are typically used to represent features in an     application that can be enabled or disabled without affecting others.     Different types of behavior can be implemented. For example, a     QButtonGroup can be used to group check buttons logically, allowing     exclusive checkboxes. However, QButtonGroup does not provide any visual     representation.      The image below further illustrates the differences between exclusive and     non-exclusive checkboxes.      \table     \row \li \inlineimage checkboxes-exclusive.png          \li \inlineimage checkboxes-non-exclusive.png     \endtable      Whenever a checkbox is checked or cleared, it emits the signal     stateChanged(). Connect to this signal if you want to trigger an action     each time the checkbox changes state. You can use isChecked() to query     whether or not a checkbox is checked.      In addition to the usual checked and unchecked states, QCheckBox optionally     provides a third state to indicate "no change". This is useful whenever you     need to give the user the option of neither checking nor unchecking a     checkbox. If you need this third state, enable it with setTristate(), and     use checkState() to query the current toggle state.      Just like QPushButton, a checkbox displays text, and optionally a small     icon. The icon is set with setIcon(). The text can be set in the     constructor or with setText(). A shortcut key can be specified by preceding     the preferred character with an ampersand. For example:      \snippet code/src_gui_widgets_qcheckbox.cpp 0      In this example, the shortcut is \e{Alt+A}. See the \l{QShortcut#mnemonic}     {QShortcut} documentation for details. To display an actual ampersand,     use '&&'.      Important inherited functions: text(), setText(), text(), pixmap(),     setPixmap(), accel(), setAccel(), isToggleButton(), setDown(), isDown(),     isOn(), checkState(), autoRepeat(), isExclusiveToggle(), group(),     setAutoRepeat(), toggle(), pressed(), released(), clicked(), toggled(),     checkState(), and stateChanged().      \table 100%     \row         \li \inlineimage macintosh-checkbox.png Screenshot of a Macintosh style checkbox         \li A checkbox shown in the \l{Macintosh Style Widget Gallery}{Macintosh widget style}.     \row         \li \inlineimage windowsvista-checkbox.png Screenshot of a Windows Vista style checkbox         \li A checkbox shown in the \l{Windows Vista Style Widget Gallery}{Windows Vista widget style}.     \row         \li \inlineimage fusion-checkbox.png Screenshot of a Fusion style checkbox         \li A checkbox shown in the \l{Fusion Style Widget Gallery}{Fusion widget style}.     \endtable      \sa QAbstractButton, QRadioButton, {fowler}{GUI Design Handbook: Check Box} */
end_comment
begin_comment
comment|/*!     \fn void QCheckBox::stateChanged(int state)      This signal is emitted whenever the checkbox's state changes, i.e.,     whenever the user checks or unchecks it.      \a state contains the checkbox's new Qt::CheckState. */
end_comment
begin_comment
comment|/*!     \property QCheckBox::tristate     \brief whether the checkbox is a tri-state checkbox      The default is false, i.e., the checkbox has only two states. */
end_comment
begin_function
DECL|function|init
name|void
name|QCheckBoxPrivate
operator|::
name|init
parameter_list|()
block|{
name|Q_Q
argument_list|(
name|QCheckBox
argument_list|)
expr_stmt|;
name|q
operator|->
name|setCheckable
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|q
operator|->
name|setMouseTracking
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|q
operator|->
name|setForegroundRole
argument_list|(
name|QPalette
operator|::
name|WindowText
argument_list|)
expr_stmt|;
name|setLayoutItemMargins
argument_list|(
name|QStyle
operator|::
name|SE_CheckBoxLayoutItem
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     Initializes \a option with the values from this QCheckBox. This method is     useful for subclasses that require a QStyleOptionButton, but do not want     to fill in all the information themselves.      \sa QStyleOption::initFrom() */
end_comment
begin_function
DECL|function|initStyleOption
name|void
name|QCheckBox
operator|::
name|initStyleOption
parameter_list|(
name|QStyleOptionButton
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
name|QCheckBox
argument_list|)
expr_stmt|;
name|option
operator|->
name|initFrom
argument_list|(
name|this
argument_list|)
expr_stmt|;
if|if
condition|(
name|d
operator|->
name|down
condition|)
name|option
operator|->
name|state
operator||=
name|QStyle
operator|::
name|State_Sunken
expr_stmt|;
if|if
condition|(
name|d
operator|->
name|tristate
operator|&&
name|d
operator|->
name|noChange
condition|)
name|option
operator|->
name|state
operator||=
name|QStyle
operator|::
name|State_NoChange
expr_stmt|;
else|else
name|option
operator|->
name|state
operator||=
name|d
operator|->
name|checked
condition|?
name|QStyle
operator|::
name|State_On
else|:
name|QStyle
operator|::
name|State_Off
expr_stmt|;
if|if
condition|(
name|testAttribute
argument_list|(
name|Qt
operator|::
name|WA_Hover
argument_list|)
operator|&&
name|underMouse
argument_list|()
condition|)
block|{
if|if
condition|(
name|d
operator|->
name|hovering
condition|)
name|option
operator|->
name|state
operator||=
name|QStyle
operator|::
name|State_MouseOver
expr_stmt|;
else|else
name|option
operator|->
name|state
operator|&=
operator|~
name|QStyle
operator|::
name|State_MouseOver
expr_stmt|;
block|}
name|option
operator|->
name|text
operator|=
name|d
operator|->
name|text
expr_stmt|;
name|option
operator|->
name|icon
operator|=
name|d
operator|->
name|icon
expr_stmt|;
name|option
operator|->
name|iconSize
operator|=
name|iconSize
argument_list|()
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     Constructs a checkbox with the given \a parent, but with no text.      \a parent is passed on to the QAbstractButton constructor. */
end_comment
begin_constructor
DECL|function|QCheckBox
name|QCheckBox
operator|::
name|QCheckBox
parameter_list|(
name|QWidget
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QAbstractButton
argument_list|(
operator|*
operator|new
name|QCheckBoxPrivate
argument_list|,
name|parent
argument_list|)
block|{
name|Q_D
argument_list|(
name|QCheckBox
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
comment|/*!     Constructs a checkbox with the given \a parent and \a text.      \a parent is passed on to the QAbstractButton constructor. */
end_comment
begin_constructor
DECL|function|QCheckBox
name|QCheckBox
operator|::
name|QCheckBox
parameter_list|(
specifier|const
name|QString
modifier|&
name|text
parameter_list|,
name|QWidget
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QAbstractButton
argument_list|(
operator|*
operator|new
name|QCheckBoxPrivate
argument_list|,
name|parent
argument_list|)
block|{
name|Q_D
argument_list|(
name|QCheckBox
argument_list|)
expr_stmt|;
name|d
operator|->
name|init
argument_list|()
expr_stmt|;
name|setText
argument_list|(
name|text
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_comment
comment|/*!     Destructor. */
end_comment
begin_destructor
DECL|function|~QCheckBox
name|QCheckBox
operator|::
name|~
name|QCheckBox
parameter_list|()
block|{ }
end_destructor
begin_function
DECL|function|setTristate
name|void
name|QCheckBox
operator|::
name|setTristate
parameter_list|(
name|bool
name|y
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QCheckBox
argument_list|)
expr_stmt|;
name|d
operator|->
name|tristate
operator|=
name|y
expr_stmt|;
block|}
end_function
begin_function
DECL|function|isTristate
name|bool
name|QCheckBox
operator|::
name|isTristate
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QCheckBox
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|tristate
return|;
block|}
end_function
begin_comment
comment|/*!     Returns the checkbox's check state. If you do not need tristate support,     you can also use \l QAbstractButton::isChecked(), which returns a boolean.      \sa setCheckState(), Qt::CheckState */
end_comment
begin_function
DECL|function|checkState
name|Qt
operator|::
name|CheckState
name|QCheckBox
operator|::
name|checkState
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QCheckBox
argument_list|)
expr_stmt|;
if|if
condition|(
name|d
operator|->
name|tristate
operator|&&
name|d
operator|->
name|noChange
condition|)
return|return
name|Qt
operator|::
name|PartiallyChecked
return|;
return|return
name|d
operator|->
name|checked
condition|?
name|Qt
operator|::
name|Checked
else|:
name|Qt
operator|::
name|Unchecked
return|;
block|}
end_function
begin_comment
comment|/*!     Sets the checkbox's check state to \a state. If you do not need tristate     support, you can also use \l QAbstractButton::setChecked(), which takes a     boolean.      \sa checkState(), Qt::CheckState */
end_comment
begin_function
DECL|function|setCheckState
name|void
name|QCheckBox
operator|::
name|setCheckState
parameter_list|(
name|Qt
operator|::
name|CheckState
name|state
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QCheckBox
argument_list|)
expr_stmt|;
if|if
condition|(
name|state
operator|==
name|Qt
operator|::
name|PartiallyChecked
condition|)
block|{
name|d
operator|->
name|tristate
operator|=
literal|true
expr_stmt|;
name|d
operator|->
name|noChange
operator|=
literal|true
expr_stmt|;
block|}
else|else
block|{
name|d
operator|->
name|noChange
operator|=
literal|false
expr_stmt|;
block|}
name|d
operator|->
name|blockRefresh
operator|=
literal|true
expr_stmt|;
name|setChecked
argument_list|(
name|state
operator|!=
name|Qt
operator|::
name|Unchecked
argument_list|)
expr_stmt|;
name|d
operator|->
name|blockRefresh
operator|=
literal|false
expr_stmt|;
name|d
operator|->
name|refresh
argument_list|()
expr_stmt|;
if|if
condition|(
operator|(
name|uint
operator|)
name|state
operator|!=
name|d
operator|->
name|publishedState
condition|)
block|{
name|d
operator|->
name|publishedState
operator|=
name|state
expr_stmt|;
emit|emit
name|stateChanged
argument_list|(
name|state
argument_list|)
emit|;
block|}
block|}
end_function
begin_comment
comment|/*!     \reimp */
end_comment
begin_function
DECL|function|sizeHint
name|QSize
name|QCheckBox
operator|::
name|sizeHint
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QCheckBox
argument_list|)
expr_stmt|;
if|if
condition|(
name|d
operator|->
name|sizeHint
operator|.
name|isValid
argument_list|()
condition|)
return|return
name|d
operator|->
name|sizeHint
return|;
name|ensurePolished
argument_list|()
expr_stmt|;
name|QFontMetrics
name|fm
init|=
name|fontMetrics
argument_list|()
decl_stmt|;
name|QStyleOptionButton
name|opt
decl_stmt|;
name|initStyleOption
argument_list|(
operator|&
name|opt
argument_list|)
expr_stmt|;
name|QSize
name|sz
init|=
name|style
argument_list|()
operator|->
name|itemTextRect
argument_list|(
name|fm
argument_list|,
name|QRect
argument_list|()
argument_list|,
name|Qt
operator|::
name|TextShowMnemonic
argument_list|,
literal|false
argument_list|,
name|text
argument_list|()
argument_list|)
operator|.
name|size
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
name|opt
operator|.
name|icon
operator|.
name|isNull
argument_list|()
condition|)
name|sz
operator|=
name|QSize
argument_list|(
name|sz
operator|.
name|width
argument_list|()
operator|+
name|opt
operator|.
name|iconSize
operator|.
name|width
argument_list|()
operator|+
literal|4
argument_list|,
name|qMax
argument_list|(
name|sz
operator|.
name|height
argument_list|()
argument_list|,
name|opt
operator|.
name|iconSize
operator|.
name|height
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|d
operator|->
name|sizeHint
operator|=
operator|(
name|style
argument_list|()
operator|->
name|sizeFromContents
argument_list|(
name|QStyle
operator|::
name|CT_CheckBox
argument_list|,
operator|&
name|opt
argument_list|,
name|sz
argument_list|,
name|this
argument_list|)
operator|.
name|expandedTo
argument_list|(
name|QApplication
operator|::
name|globalStrut
argument_list|()
argument_list|)
operator|)
expr_stmt|;
return|return
name|d
operator|->
name|sizeHint
return|;
block|}
end_function
begin_comment
comment|/*!     \reimp */
end_comment
begin_function
DECL|function|minimumSizeHint
name|QSize
name|QCheckBox
operator|::
name|minimumSizeHint
parameter_list|()
specifier|const
block|{
return|return
name|sizeHint
argument_list|()
return|;
block|}
end_function
begin_comment
comment|/*!     \reimp */
end_comment
begin_function
DECL|function|paintEvent
name|void
name|QCheckBox
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
name|QStyleOptionButton
name|opt
decl_stmt|;
name|initStyleOption
argument_list|(
operator|&
name|opt
argument_list|)
expr_stmt|;
name|p
operator|.
name|drawControl
argument_list|(
name|QStyle
operator|::
name|CE_CheckBox
argument_list|,
name|opt
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     \reimp */
end_comment
begin_function
DECL|function|mouseMoveEvent
name|void
name|QCheckBox
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
name|QCheckBox
argument_list|)
expr_stmt|;
if|if
condition|(
name|testAttribute
argument_list|(
name|Qt
operator|::
name|WA_Hover
argument_list|)
condition|)
block|{
name|bool
name|hit
init|=
literal|false
decl_stmt|;
if|if
condition|(
name|underMouse
argument_list|()
condition|)
name|hit
operator|=
name|hitButton
argument_list|(
name|e
operator|->
name|pos
argument_list|()
argument_list|)
expr_stmt|;
if|if
condition|(
name|hit
operator|!=
name|d
operator|->
name|hovering
condition|)
block|{
name|update
argument_list|(
name|rect
argument_list|()
argument_list|)
expr_stmt|;
name|d
operator|->
name|hovering
operator|=
name|hit
expr_stmt|;
block|}
block|}
name|QAbstractButton
operator|::
name|mouseMoveEvent
argument_list|(
name|e
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     \reimp */
end_comment
begin_function
DECL|function|hitButton
name|bool
name|QCheckBox
operator|::
name|hitButton
parameter_list|(
specifier|const
name|QPoint
modifier|&
name|pos
parameter_list|)
specifier|const
block|{
name|QStyleOptionButton
name|opt
decl_stmt|;
name|initStyleOption
argument_list|(
operator|&
name|opt
argument_list|)
expr_stmt|;
return|return
name|style
argument_list|()
operator|->
name|subElementRect
argument_list|(
name|QStyle
operator|::
name|SE_CheckBoxClickRect
argument_list|,
operator|&
name|opt
argument_list|,
name|this
argument_list|)
operator|.
name|contains
argument_list|(
name|pos
argument_list|)
return|;
block|}
end_function
begin_comment
comment|/*!     \reimp */
end_comment
begin_function
DECL|function|checkStateSet
name|void
name|QCheckBox
operator|::
name|checkStateSet
parameter_list|()
block|{
name|Q_D
argument_list|(
name|QCheckBox
argument_list|)
expr_stmt|;
name|d
operator|->
name|noChange
operator|=
literal|false
expr_stmt|;
name|Qt
operator|::
name|CheckState
name|state
init|=
name|checkState
argument_list|()
decl_stmt|;
if|if
condition|(
operator|(
name|uint
operator|)
name|state
operator|!=
name|d
operator|->
name|publishedState
condition|)
block|{
name|d
operator|->
name|publishedState
operator|=
name|state
expr_stmt|;
emit|emit
name|stateChanged
argument_list|(
name|state
argument_list|)
emit|;
block|}
block|}
end_function
begin_comment
comment|/*!     \reimp */
end_comment
begin_function
DECL|function|nextCheckState
name|void
name|QCheckBox
operator|::
name|nextCheckState
parameter_list|()
block|{
name|Q_D
argument_list|(
name|QCheckBox
argument_list|)
expr_stmt|;
if|if
condition|(
name|d
operator|->
name|tristate
condition|)
name|setCheckState
argument_list|(
call|(
name|Qt
operator|::
name|CheckState
call|)
argument_list|(
operator|(
name|checkState
argument_list|()
operator|+
literal|1
operator|)
operator|%
literal|3
argument_list|)
argument_list|)
expr_stmt|;
else|else
block|{
name|QAbstractButton
operator|::
name|nextCheckState
argument_list|()
expr_stmt|;
name|QCheckBox
operator|::
name|checkStateSet
argument_list|()
expr_stmt|;
block|}
block|}
end_function
begin_comment
comment|/*!     \reimp */
end_comment
begin_function
DECL|function|event
name|bool
name|QCheckBox
operator|::
name|event
parameter_list|(
name|QEvent
modifier|*
name|e
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QCheckBox
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
name|StyleChange
ifdef|#
directive|ifdef
name|Q_OS_MAC
operator|||
name|e
operator|->
name|type
argument_list|()
operator|==
name|QEvent
operator|::
name|MacSizeChange
endif|#
directive|endif
condition|)
name|d
operator|->
name|setLayoutItemMargins
argument_list|(
name|QStyle
operator|::
name|SE_CheckBoxLayoutItem
argument_list|)
expr_stmt|;
return|return
name|QAbstractButton
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
end_unit
