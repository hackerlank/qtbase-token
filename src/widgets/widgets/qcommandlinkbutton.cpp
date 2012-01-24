begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qcommandlinkbutton.h"
end_include
begin_include
include|#
directive|include
file|"qstylepainter.h"
end_include
begin_include
include|#
directive|include
file|"qstyleoption.h"
end_include
begin_include
include|#
directive|include
file|"qtextdocument.h"
end_include
begin_include
include|#
directive|include
file|"qtextlayout.h"
end_include
begin_include
include|#
directive|include
file|"qcolor.h"
end_include
begin_include
include|#
directive|include
file|"qfont.h"
end_include
begin_include
include|#
directive|include
file|<qmath.h>
end_include
begin_include
include|#
directive|include
file|"private/qpushbutton_p.h"
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_comment
comment|/*!     \class QCommandLinkButton     \since 4.4     \brief The QCommandLinkButton widget provides a Vista style command link button.      \ingroup basicwidgets     \inmodule QtWidgets      The command link is a new control that was introduced by Windows Vista. It's     intended use is similar to that of a radio button in that it is used to choose     between a set of mutually exclusive options. Command link buttons should not     be used by themselves but rather as an alternative to radio buttons in     Wizards and dialogs and makes pressing the "next" button redundant.     The appearance is generally similar to that of a flat pushbutton, but     it allows for a descriptive text in addition to the normal button text.     By default it will also carry an arrow icon, indicating that pressing the     control will open another window or page.      \sa QPushButton QRadioButton */
end_comment
begin_comment
comment|/*!     \property QCommandLinkButton::description     \brief A descriptive label to complement the button text      Setting this property will set a descriptive text on the     button, complementing the text label. This will usually     be displayed in a smaller font than the primary text. */
end_comment
begin_comment
comment|/*!     \property QCommandLinkButton::flat     \brief This property determines whether the button is displayed as a flat     panel or with a border.      By default, this property is set to false.      \sa QPushButton::flat */
end_comment
begin_class
DECL|class|QCommandLinkButtonPrivate
class|class
name|QCommandLinkButtonPrivate
super|:
specifier|public
name|QPushButtonPrivate
block|{
name|Q_DECLARE_PUBLIC
parameter_list|(
name|QCommandLinkButton
parameter_list|)
specifier|public
private|:
DECL|function|QCommandLinkButtonPrivate
name|QCommandLinkButtonPrivate
parameter_list|()
member_init_list|:
name|QPushButtonPrivate
argument_list|()
block|{}
name|void
name|init
parameter_list|()
function_decl|;
name|qreal
name|titleSize
parameter_list|()
specifier|const
function_decl|;
name|bool
name|usingVistaStyle
parameter_list|()
specifier|const
function_decl|;
name|QFont
name|titleFont
parameter_list|()
specifier|const
function_decl|;
name|QFont
name|descriptionFont
parameter_list|()
specifier|const
function_decl|;
name|QRect
name|titleRect
parameter_list|()
specifier|const
function_decl|;
name|QRect
name|descriptionRect
parameter_list|()
specifier|const
function_decl|;
name|int
name|textOffset
parameter_list|()
specifier|const
function_decl|;
name|int
name|descriptionOffset
parameter_list|()
specifier|const
function_decl|;
name|int
name|descriptionHeight
parameter_list|(
name|int
name|width
parameter_list|)
specifier|const
function_decl|;
name|QColor
name|mergedColors
parameter_list|(
specifier|const
name|QColor
modifier|&
name|a
parameter_list|,
specifier|const
name|QColor
modifier|&
name|b
parameter_list|,
name|int
name|value
parameter_list|)
specifier|const
function_decl|;
DECL|function|topMargin
name|int
name|topMargin
parameter_list|()
specifier|const
block|{
return|return
literal|10
return|;
block|}
DECL|function|leftMargin
name|int
name|leftMargin
parameter_list|()
specifier|const
block|{
return|return
literal|7
return|;
block|}
DECL|function|rightMargin
name|int
name|rightMargin
parameter_list|()
specifier|const
block|{
return|return
literal|4
return|;
block|}
DECL|function|bottomMargin
name|int
name|bottomMargin
parameter_list|()
specifier|const
block|{
return|return
literal|10
return|;
block|}
DECL|member|description
name|QString
name|description
decl_stmt|;
DECL|member|currentColor
name|QColor
name|currentColor
decl_stmt|;
block|}
class|;
end_class
begin_comment
comment|// Mix colors a and b with a ratio in the range [0-255]
end_comment
begin_function
DECL|function|mergedColors
name|QColor
name|QCommandLinkButtonPrivate
operator|::
name|mergedColors
parameter_list|(
specifier|const
name|QColor
modifier|&
name|a
parameter_list|,
specifier|const
name|QColor
modifier|&
name|b
parameter_list|,
name|int
name|value
init|=
literal|50
parameter_list|)
specifier|const
block|{
name|Q_ASSERT
argument_list|(
name|value
operator|>=
literal|0
argument_list|)
expr_stmt|;
name|Q_ASSERT
argument_list|(
name|value
operator|<=
literal|255
argument_list|)
expr_stmt|;
name|QColor
name|tmp
init|=
name|a
decl_stmt|;
name|tmp
operator|.
name|setRed
argument_list|(
operator|(
name|tmp
operator|.
name|red
argument_list|()
operator|*
name|value
operator|)
operator|/
literal|255
operator|+
operator|(
name|b
operator|.
name|red
argument_list|()
operator|*
operator|(
literal|255
operator|-
name|value
operator|)
operator|)
operator|/
literal|255
argument_list|)
expr_stmt|;
name|tmp
operator|.
name|setGreen
argument_list|(
operator|(
name|tmp
operator|.
name|green
argument_list|()
operator|*
name|value
operator|)
operator|/
literal|255
operator|+
operator|(
name|b
operator|.
name|green
argument_list|()
operator|*
operator|(
literal|255
operator|-
name|value
operator|)
operator|)
operator|/
literal|255
argument_list|)
expr_stmt|;
name|tmp
operator|.
name|setBlue
argument_list|(
operator|(
name|tmp
operator|.
name|blue
argument_list|()
operator|*
name|value
operator|)
operator|/
literal|255
operator|+
operator|(
name|b
operator|.
name|blue
argument_list|()
operator|*
operator|(
literal|255
operator|-
name|value
operator|)
operator|)
operator|/
literal|255
argument_list|)
expr_stmt|;
return|return
name|tmp
return|;
block|}
end_function
begin_function
DECL|function|titleFont
name|QFont
name|QCommandLinkButtonPrivate
operator|::
name|titleFont
parameter_list|()
specifier|const
block|{
name|Q_Q
argument_list|(
specifier|const
name|QCommandLinkButton
argument_list|)
expr_stmt|;
name|QFont
name|font
init|=
name|q
operator|->
name|font
argument_list|()
decl_stmt|;
if|if
condition|(
name|usingVistaStyle
argument_list|()
condition|)
block|{
name|font
operator|.
name|setPointSizeF
argument_list|(
literal|12.0
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|font
operator|.
name|setBold
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|font
operator|.
name|setPointSizeF
argument_list|(
literal|9.0
argument_list|)
expr_stmt|;
block|}
comment|// Note the font will be resolved against
comment|// QPainters font, so we need to restore the mask
name|int
name|resolve_mask
init|=
name|font
operator|.
name|resolve_mask
decl_stmt|;
name|QFont
name|modifiedFont
init|=
name|q
operator|->
name|font
argument_list|()
operator|.
name|resolve
argument_list|(
name|font
argument_list|)
decl_stmt|;
name|modifiedFont
operator|.
name|detach
argument_list|()
expr_stmt|;
name|modifiedFont
operator|.
name|resolve_mask
operator|=
name|resolve_mask
expr_stmt|;
return|return
name|modifiedFont
return|;
block|}
end_function
begin_function
DECL|function|descriptionFont
name|QFont
name|QCommandLinkButtonPrivate
operator|::
name|descriptionFont
parameter_list|()
specifier|const
block|{
name|Q_Q
argument_list|(
specifier|const
name|QCommandLinkButton
argument_list|)
expr_stmt|;
name|QFont
name|font
init|=
name|q
operator|->
name|font
argument_list|()
decl_stmt|;
name|font
operator|.
name|setPointSizeF
argument_list|(
literal|9.0
argument_list|)
expr_stmt|;
comment|// Note the font will be resolved against
comment|// QPainters font, so we need to restore the mask
name|int
name|resolve_mask
init|=
name|font
operator|.
name|resolve_mask
decl_stmt|;
name|QFont
name|modifiedFont
init|=
name|q
operator|->
name|font
argument_list|()
operator|.
name|resolve
argument_list|(
name|font
argument_list|)
decl_stmt|;
name|modifiedFont
operator|.
name|detach
argument_list|()
expr_stmt|;
name|modifiedFont
operator|.
name|resolve_mask
operator|=
name|resolve_mask
expr_stmt|;
return|return
name|modifiedFont
return|;
block|}
end_function
begin_function
DECL|function|titleRect
name|QRect
name|QCommandLinkButtonPrivate
operator|::
name|titleRect
parameter_list|()
specifier|const
block|{
name|Q_Q
argument_list|(
specifier|const
name|QCommandLinkButton
argument_list|)
expr_stmt|;
name|QRect
name|r
init|=
name|q
operator|->
name|rect
argument_list|()
operator|.
name|adjusted
argument_list|(
name|textOffset
argument_list|()
argument_list|,
name|topMargin
argument_list|()
argument_list|,
operator|-
name|rightMargin
argument_list|()
argument_list|,
literal|0
argument_list|)
decl_stmt|;
if|if
condition|(
name|description
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|QFontMetrics
name|fm
argument_list|(
name|titleFont
argument_list|()
argument_list|)
decl_stmt|;
name|r
operator|.
name|setTop
argument_list|(
name|r
operator|.
name|top
argument_list|()
operator|+
name|qMax
argument_list|(
literal|0
argument_list|,
operator|(
name|q
operator|->
name|icon
argument_list|()
operator|.
name|actualSize
argument_list|(
name|q
operator|->
name|iconSize
argument_list|()
argument_list|)
operator|.
name|height
argument_list|()
operator|-
name|fm
operator|.
name|height
argument_list|()
operator|)
operator|/
literal|2
argument_list|)
argument_list|)
expr_stmt|;
block|}
return|return
name|r
return|;
block|}
end_function
begin_function
DECL|function|descriptionRect
name|QRect
name|QCommandLinkButtonPrivate
operator|::
name|descriptionRect
parameter_list|()
specifier|const
block|{
name|Q_Q
argument_list|(
specifier|const
name|QCommandLinkButton
argument_list|)
expr_stmt|;
return|return
name|q
operator|->
name|rect
argument_list|()
operator|.
name|adjusted
argument_list|(
name|textOffset
argument_list|()
argument_list|,
name|descriptionOffset
argument_list|()
argument_list|,
operator|-
name|rightMargin
argument_list|()
argument_list|,
operator|-
name|bottomMargin
argument_list|()
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|textOffset
name|int
name|QCommandLinkButtonPrivate
operator|::
name|textOffset
parameter_list|()
specifier|const
block|{
name|Q_Q
argument_list|(
specifier|const
name|QCommandLinkButton
argument_list|)
expr_stmt|;
return|return
name|q
operator|->
name|icon
argument_list|()
operator|.
name|actualSize
argument_list|(
name|q
operator|->
name|iconSize
argument_list|()
argument_list|)
operator|.
name|width
argument_list|()
operator|+
name|leftMargin
argument_list|()
operator|+
literal|6
return|;
block|}
end_function
begin_function
DECL|function|descriptionOffset
name|int
name|QCommandLinkButtonPrivate
operator|::
name|descriptionOffset
parameter_list|()
specifier|const
block|{
name|QFontMetrics
name|fm
argument_list|(
name|titleFont
argument_list|()
argument_list|)
decl_stmt|;
return|return
name|topMargin
argument_list|()
operator|+
name|fm
operator|.
name|height
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|usingVistaStyle
name|bool
name|QCommandLinkButtonPrivate
operator|::
name|usingVistaStyle
parameter_list|()
specifier|const
block|{
name|Q_Q
argument_list|(
specifier|const
name|QCommandLinkButton
argument_list|)
expr_stmt|;
comment|//### This is a hack to detect if we are indeed running Vista style themed and not in classic
comment|// When we add api to query for this, we should change this implementation to use it.
return|return
name|q
operator|->
name|style
argument_list|()
operator|->
name|inherits
argument_list|(
literal|"QWindowsVistaStyle"
argument_list|)
operator|&&
operator|!
name|q
operator|->
name|style
argument_list|()
operator|->
name|pixelMetric
argument_list|(
name|QStyle
operator|::
name|PM_ButtonShiftHorizontal
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|init
name|void
name|QCommandLinkButtonPrivate
operator|::
name|init
parameter_list|()
block|{
name|Q_Q
argument_list|(
name|QCommandLinkButton
argument_list|)
expr_stmt|;
name|QPushButtonPrivate
operator|::
name|init
argument_list|()
expr_stmt|;
name|q
operator|->
name|setAttribute
argument_list|(
name|Qt
operator|::
name|WA_Hover
argument_list|)
expr_stmt|;
name|QSizePolicy
name|policy
argument_list|(
name|QSizePolicy
operator|::
name|Preferred
argument_list|,
name|QSizePolicy
operator|::
name|Preferred
argument_list|,
name|QSizePolicy
operator|::
name|PushButton
argument_list|)
decl_stmt|;
name|policy
operator|.
name|setHeightForWidth
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|q
operator|->
name|setSizePolicy
argument_list|(
name|policy
argument_list|)
expr_stmt|;
name|q
operator|->
name|setIconSize
argument_list|(
name|QSize
argument_list|(
literal|20
argument_list|,
literal|20
argument_list|)
argument_list|)
expr_stmt|;
name|QStyleOptionButton
name|opt
decl_stmt|;
name|q
operator|->
name|initStyleOption
argument_list|(
operator|&
name|opt
argument_list|)
expr_stmt|;
name|q
operator|->
name|setIcon
argument_list|(
name|q
operator|->
name|style
argument_list|()
operator|->
name|standardIcon
argument_list|(
name|QStyle
operator|::
name|SP_CommandLink
argument_list|,
operator|&
name|opt
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|// Calculates the height of the description text based on widget width
end_comment
begin_function
DECL|function|descriptionHeight
name|int
name|QCommandLinkButtonPrivate
operator|::
name|descriptionHeight
parameter_list|(
name|int
name|widgetWidth
parameter_list|)
specifier|const
block|{
comment|// Calc width of actual paragraph
name|int
name|lineWidth
init|=
name|widgetWidth
operator|-
name|textOffset
argument_list|()
operator|-
name|rightMargin
argument_list|()
decl_stmt|;
name|qreal
name|descriptionheight
init|=
literal|0
decl_stmt|;
if|if
condition|(
operator|!
name|description
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|QTextLayout
name|layout
argument_list|(
name|description
argument_list|)
decl_stmt|;
name|layout
operator|.
name|setFont
argument_list|(
name|descriptionFont
argument_list|()
argument_list|)
expr_stmt|;
name|layout
operator|.
name|beginLayout
argument_list|()
expr_stmt|;
while|while
condition|(
literal|true
condition|)
block|{
name|QTextLine
name|line
init|=
name|layout
operator|.
name|createLine
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
name|line
operator|.
name|isValid
argument_list|()
condition|)
break|break;
name|line
operator|.
name|setLineWidth
argument_list|(
name|lineWidth
argument_list|)
expr_stmt|;
name|line
operator|.
name|setPosition
argument_list|(
name|QPointF
argument_list|(
literal|0
argument_list|,
name|descriptionheight
argument_list|)
argument_list|)
expr_stmt|;
name|descriptionheight
operator|+=
name|line
operator|.
name|height
argument_list|()
expr_stmt|;
block|}
name|layout
operator|.
name|endLayout
argument_list|()
expr_stmt|;
block|}
return|return
name|qCeil
argument_list|(
name|descriptionheight
argument_list|)
return|;
block|}
end_function
begin_comment
comment|/*!     \reimp  */
end_comment
begin_function
DECL|function|minimumSizeHint
name|QSize
name|QCommandLinkButton
operator|::
name|minimumSizeHint
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QCommandLinkButton
argument_list|)
expr_stmt|;
name|QSize
name|size
init|=
name|sizeHint
argument_list|()
decl_stmt|;
name|int
name|minimumHeight
init|=
name|qMax
argument_list|(
name|d
operator|->
name|descriptionOffset
argument_list|()
operator|+
name|d
operator|->
name|bottomMargin
argument_list|()
argument_list|,
name|icon
argument_list|()
operator|.
name|actualSize
argument_list|(
name|iconSize
argument_list|()
argument_list|)
operator|.
name|height
argument_list|()
operator|+
name|d
operator|->
name|topMargin
argument_list|()
argument_list|)
decl_stmt|;
name|size
operator|.
name|setHeight
argument_list|(
name|minimumHeight
argument_list|)
expr_stmt|;
return|return
name|size
return|;
block|}
end_function
begin_comment
comment|/*!     Constructs a command link with no text and a \a parent. */
end_comment
begin_constructor
DECL|function|QCommandLinkButton
name|QCommandLinkButton
operator|::
name|QCommandLinkButton
parameter_list|(
name|QWidget
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QPushButton
argument_list|(
operator|*
operator|new
name|QCommandLinkButtonPrivate
argument_list|,
name|parent
argument_list|)
block|{
name|Q_D
argument_list|(
name|QCommandLinkButton
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
comment|/*!     Constructs a command link with the parent \a parent and the text \a     text. */
end_comment
begin_constructor
DECL|function|QCommandLinkButton
name|QCommandLinkButton
operator|::
name|QCommandLinkButton
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
name|QPushButton
argument_list|(
operator|*
operator|new
name|QCommandLinkButtonPrivate
argument_list|,
name|parent
argument_list|)
block|{
name|Q_D
argument_list|(
name|QCommandLinkButton
argument_list|)
expr_stmt|;
name|setText
argument_list|(
name|text
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
comment|/*!     Constructs a command link with a \a text, a \a description, and a \a parent. */
end_comment
begin_constructor
DECL|function|QCommandLinkButton
name|QCommandLinkButton
operator|::
name|QCommandLinkButton
parameter_list|(
specifier|const
name|QString
modifier|&
name|text
parameter_list|,
specifier|const
name|QString
modifier|&
name|description
parameter_list|,
name|QWidget
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QPushButton
argument_list|(
operator|*
operator|new
name|QCommandLinkButtonPrivate
argument_list|,
name|parent
argument_list|)
block|{
name|Q_D
argument_list|(
name|QCommandLinkButton
argument_list|)
expr_stmt|;
name|setText
argument_list|(
name|text
argument_list|)
expr_stmt|;
name|setDescription
argument_list|(
name|description
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
comment|/*! \reimp */
end_comment
begin_function
DECL|function|event
name|bool
name|QCommandLinkButton
operator|::
name|event
parameter_list|(
name|QEvent
modifier|*
name|e
parameter_list|)
block|{
return|return
name|QPushButton
operator|::
name|event
argument_list|(
name|e
argument_list|)
return|;
block|}
end_function
begin_comment
comment|/*! \reimp */
end_comment
begin_function
DECL|function|sizeHint
name|QSize
name|QCommandLinkButton
operator|::
name|sizeHint
parameter_list|()
specifier|const
block|{
comment|//  Standard size hints from UI specs
comment|//  Without note: 135, 41
comment|//  With note: 135, 60
name|Q_D
argument_list|(
specifier|const
name|QCommandLinkButton
argument_list|)
expr_stmt|;
name|QSize
name|size
init|=
name|QPushButton
operator|::
name|sizeHint
argument_list|()
decl_stmt|;
name|QFontMetrics
name|fm
argument_list|(
name|d
operator|->
name|titleFont
argument_list|()
argument_list|)
decl_stmt|;
name|int
name|textWidth
init|=
name|qMax
argument_list|(
name|fm
operator|.
name|width
argument_list|(
name|text
argument_list|()
argument_list|)
argument_list|,
literal|135
argument_list|)
decl_stmt|;
name|int
name|buttonWidth
init|=
name|textWidth
operator|+
name|d
operator|->
name|textOffset
argument_list|()
operator|+
name|d
operator|->
name|rightMargin
argument_list|()
decl_stmt|;
name|int
name|heightWithoutDescription
init|=
name|d
operator|->
name|descriptionOffset
argument_list|()
operator|+
name|d
operator|->
name|bottomMargin
argument_list|()
decl_stmt|;
name|size
operator|.
name|setWidth
argument_list|(
name|qMax
argument_list|(
name|size
operator|.
name|width
argument_list|()
argument_list|,
name|buttonWidth
argument_list|)
argument_list|)
expr_stmt|;
name|size
operator|.
name|setHeight
argument_list|(
name|qMax
argument_list|(
name|d
operator|->
name|description
operator|.
name|isEmpty
argument_list|()
condition|?
literal|41
else|:
literal|60
argument_list|,
name|heightWithoutDescription
operator|+
name|d
operator|->
name|descriptionHeight
argument_list|(
name|buttonWidth
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|size
return|;
block|}
end_function
begin_comment
comment|/*! \reimp */
end_comment
begin_function
DECL|function|heightForWidth
name|int
name|QCommandLinkButton
operator|::
name|heightForWidth
parameter_list|(
name|int
name|width
parameter_list|)
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QCommandLinkButton
argument_list|)
expr_stmt|;
name|int
name|heightWithoutDescription
init|=
name|d
operator|->
name|descriptionOffset
argument_list|()
operator|+
name|d
operator|->
name|bottomMargin
argument_list|()
decl_stmt|;
comment|// find the width available for the description area
return|return
name|qMax
argument_list|(
name|heightWithoutDescription
operator|+
name|d
operator|->
name|descriptionHeight
argument_list|(
name|width
argument_list|)
argument_list|,
name|icon
argument_list|()
operator|.
name|actualSize
argument_list|(
name|iconSize
argument_list|()
argument_list|)
operator|.
name|height
argument_list|()
operator|+
name|d
operator|->
name|topMargin
argument_list|()
operator|+
name|d
operator|->
name|bottomMargin
argument_list|()
argument_list|)
return|;
block|}
end_function
begin_comment
comment|/*! \reimp */
end_comment
begin_function
DECL|function|paintEvent
name|void
name|QCommandLinkButton
operator|::
name|paintEvent
parameter_list|(
name|QPaintEvent
modifier|*
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QCommandLinkButton
argument_list|)
expr_stmt|;
name|QStylePainter
name|p
argument_list|(
name|this
argument_list|)
decl_stmt|;
name|p
operator|.
name|save
argument_list|()
expr_stmt|;
name|QStyleOptionButton
name|option
decl_stmt|;
name|initStyleOption
argument_list|(
operator|&
name|option
argument_list|)
expr_stmt|;
comment|//Enable command link appearance on Vista
name|option
operator|.
name|features
operator||=
name|QStyleOptionButton
operator|::
name|CommandLinkButton
expr_stmt|;
name|option
operator|.
name|text
operator|=
name|QString
argument_list|()
expr_stmt|;
name|option
operator|.
name|icon
operator|=
name|QIcon
argument_list|()
expr_stmt|;
comment|//we draw this ourselves
name|QSize
name|pixmapSize
init|=
name|icon
argument_list|()
operator|.
name|actualSize
argument_list|(
name|iconSize
argument_list|()
argument_list|)
decl_stmt|;
name|int
name|vOffset
init|=
name|isDown
argument_list|()
condition|?
name|style
argument_list|()
operator|->
name|pixelMetric
argument_list|(
name|QStyle
operator|::
name|PM_ButtonShiftVertical
argument_list|)
else|:
literal|0
decl_stmt|;
name|int
name|hOffset
init|=
name|isDown
argument_list|()
condition|?
name|style
argument_list|()
operator|->
name|pixelMetric
argument_list|(
name|QStyle
operator|::
name|PM_ButtonShiftHorizontal
argument_list|)
else|:
literal|0
decl_stmt|;
comment|//Draw icon
name|p
operator|.
name|drawControl
argument_list|(
name|QStyle
operator|::
name|CE_PushButton
argument_list|,
name|option
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|icon
argument_list|()
operator|.
name|isNull
argument_list|()
condition|)
name|p
operator|.
name|drawPixmap
argument_list|(
name|d
operator|->
name|leftMargin
argument_list|()
operator|+
name|hOffset
argument_list|,
name|d
operator|->
name|topMargin
argument_list|()
operator|+
name|vOffset
argument_list|,
name|icon
argument_list|()
operator|.
name|pixmap
argument_list|(
name|pixmapSize
argument_list|,
name|isEnabled
argument_list|()
condition|?
name|QIcon
operator|::
name|Normal
else|:
name|QIcon
operator|::
name|Disabled
argument_list|,
name|isChecked
argument_list|()
condition|?
name|QIcon
operator|::
name|On
else|:
name|QIcon
operator|::
name|Off
argument_list|)
argument_list|)
expr_stmt|;
comment|//Draw title
name|QColor
name|textColor
init|=
name|palette
argument_list|()
operator|.
name|buttonText
argument_list|()
operator|.
name|color
argument_list|()
decl_stmt|;
if|if
condition|(
name|isEnabled
argument_list|()
operator|&&
name|d
operator|->
name|usingVistaStyle
argument_list|()
condition|)
block|{
name|textColor
operator|=
name|QColor
argument_list|(
literal|21
argument_list|,
literal|28
argument_list|,
literal|85
argument_list|)
expr_stmt|;
if|if
condition|(
name|underMouse
argument_list|()
operator|&&
operator|!
name|isDown
argument_list|()
condition|)
name|textColor
operator|=
name|QColor
argument_list|(
literal|7
argument_list|,
literal|64
argument_list|,
literal|229
argument_list|)
expr_stmt|;
comment|//A simple text color transition
name|d
operator|->
name|currentColor
operator|=
name|d
operator|->
name|mergedColors
argument_list|(
name|textColor
argument_list|,
name|d
operator|->
name|currentColor
argument_list|,
literal|60
argument_list|)
expr_stmt|;
name|option
operator|.
name|palette
operator|.
name|setColor
argument_list|(
name|QPalette
operator|::
name|ButtonText
argument_list|,
name|d
operator|->
name|currentColor
argument_list|)
expr_stmt|;
block|}
name|int
name|textflags
init|=
name|Qt
operator|::
name|TextShowMnemonic
decl_stmt|;
if|if
condition|(
operator|!
name|style
argument_list|()
operator|->
name|styleHint
argument_list|(
name|QStyle
operator|::
name|SH_UnderlineShortcut
argument_list|,
operator|&
name|option
argument_list|,
name|this
argument_list|)
condition|)
name|textflags
operator||=
name|Qt
operator|::
name|TextHideMnemonic
expr_stmt|;
name|p
operator|.
name|setFont
argument_list|(
name|d
operator|->
name|titleFont
argument_list|()
argument_list|)
expr_stmt|;
name|p
operator|.
name|drawItemText
argument_list|(
name|d
operator|->
name|titleRect
argument_list|()
operator|.
name|translated
argument_list|(
name|hOffset
argument_list|,
name|vOffset
argument_list|)
argument_list|,
name|textflags
argument_list|,
name|option
operator|.
name|palette
argument_list|,
name|isEnabled
argument_list|()
argument_list|,
name|text
argument_list|()
argument_list|,
name|QPalette
operator|::
name|ButtonText
argument_list|)
expr_stmt|;
comment|//Draw description
name|textflags
operator||=
name|Qt
operator|::
name|TextWordWrap
operator||
name|Qt
operator|::
name|ElideRight
expr_stmt|;
name|p
operator|.
name|setFont
argument_list|(
name|d
operator|->
name|descriptionFont
argument_list|()
argument_list|)
expr_stmt|;
name|p
operator|.
name|drawItemText
argument_list|(
name|d
operator|->
name|descriptionRect
argument_list|()
operator|.
name|translated
argument_list|(
name|hOffset
argument_list|,
name|vOffset
argument_list|)
argument_list|,
name|textflags
argument_list|,
name|option
operator|.
name|palette
argument_list|,
name|isEnabled
argument_list|()
argument_list|,
name|description
argument_list|()
argument_list|,
name|QPalette
operator|::
name|ButtonText
argument_list|)
expr_stmt|;
name|p
operator|.
name|restore
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|setDescription
name|void
name|QCommandLinkButton
operator|::
name|setDescription
parameter_list|(
specifier|const
name|QString
modifier|&
name|description
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QCommandLinkButton
argument_list|)
expr_stmt|;
name|d
operator|->
name|description
operator|=
name|description
expr_stmt|;
name|updateGeometry
argument_list|()
expr_stmt|;
name|update
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|description
name|QString
name|QCommandLinkButton
operator|::
name|description
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QCommandLinkButton
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|description
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
