begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"complexwidgets.h"
end_include
begin_include
include|#
directive|include
file|<qaccessible.h>
end_include
begin_include
include|#
directive|include
file|<qapplication.h>
end_include
begin_include
include|#
directive|include
file|<qabstractbutton.h>
end_include
begin_include
include|#
directive|include
file|<qevent.h>
end_include
begin_include
include|#
directive|include
file|<qheaderview.h>
end_include
begin_include
include|#
directive|include
file|<qtabbar.h>
end_include
begin_include
include|#
directive|include
file|<qcombobox.h>
end_include
begin_include
include|#
directive|include
file|<qlistview.h>
end_include
begin_include
include|#
directive|include
file|<qtableview.h>
end_include
begin_include
include|#
directive|include
file|<qlineedit.h>
end_include
begin_include
include|#
directive|include
file|<qstyle.h>
end_include
begin_include
include|#
directive|include
file|<qstyleoption.h>
end_include
begin_include
include|#
directive|include
file|<qtooltip.h>
end_include
begin_include
include|#
directive|include
file|<qwhatsthis.h>
end_include
begin_include
include|#
directive|include
file|<qtreeview.h>
end_include
begin_include
include|#
directive|include
file|<private/qtabbar_p.h>
end_include
begin_include
include|#
directive|include
file|<QAbstractScrollArea>
end_include
begin_include
include|#
directive|include
file|<QScrollArea>
end_include
begin_include
include|#
directive|include
file|<QScrollBar>
end_include
begin_include
include|#
directive|include
file|<QDebug>
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_ACCESSIBILITY
end_ifndef
begin_function_decl
name|QT_BEGIN_NAMESPACE
name|QString
name|qt_accStripAmp
parameter_list|(
specifier|const
name|QString
modifier|&
name|text
parameter_list|)
function_decl|;
end_function_decl
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_TABBAR
end_ifndef
begin_comment
comment|/*!   \class QAccessibleTabBar   \brief The QAccessibleTabBar class implements the QAccessibleInterface for tab bars.   \internal    \ingroup accessibility */
end_comment
begin_class
DECL|class|QAccessibleTabButton
class|class
name|QAccessibleTabButton
super|:
specifier|public
name|QAccessibleInterface
super|,
specifier|public
name|QAccessibleActionInterface
block|{
public|public:
DECL|function|QAccessibleTabButton
name|QAccessibleTabButton
parameter_list|(
name|QTabBar
modifier|*
name|parent
parameter_list|,
name|int
name|index
parameter_list|)
member_init_list|:
name|m_parent
argument_list|(
name|parent
argument_list|)
member_init_list|,
name|m_index
argument_list|(
name|index
argument_list|)
block|{}
DECL|function|interface_cast
name|void
modifier|*
name|interface_cast
parameter_list|(
name|QAccessible
operator|::
name|InterfaceType
name|t
parameter_list|)
block|{
if|if
condition|(
name|t
operator|==
name|QAccessible
operator|::
name|ActionInterface
condition|)
block|{
return|return
cast|static_cast
argument_list|<
name|QAccessibleActionInterface
operator|*
argument_list|>
argument_list|(
name|this
argument_list|)
return|;
block|}
return|return
literal|0
return|;
block|}
DECL|function|object
name|QObject
modifier|*
name|object
parameter_list|()
specifier|const
block|{
return|return
literal|0
return|;
block|}
DECL|function|role
name|QAccessible
operator|::
name|Role
name|role
parameter_list|()
specifier|const
block|{
return|return
name|QAccessible
operator|::
name|PageTab
return|;
block|}
DECL|function|state
name|QAccessible
operator|::
name|State
name|state
parameter_list|()
specifier|const
block|{
name|QAccessibleInterface
modifier|*
name|parentInterface
init|=
name|parent
argument_list|()
decl_stmt|;
name|QAccessible
operator|::
name|State
name|state
init|=
name|parentInterface
operator|->
name|state
argument_list|()
decl_stmt|;
return|return
name|state
return|;
block|}
DECL|function|rect
name|QRect
name|rect
parameter_list|()
specifier|const
block|{
if|if
condition|(
operator|!
name|isValid
argument_list|()
condition|)
return|return
name|QRect
argument_list|()
return|;
name|QPoint
name|tp
init|=
name|m_parent
operator|->
name|mapToGlobal
argument_list|(
name|QPoint
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
argument_list|)
decl_stmt|;
name|QRect
name|rec
init|=
name|m_parent
operator|->
name|tabRect
argument_list|(
name|m_index
argument_list|)
decl_stmt|;
name|rec
operator|=
name|QRect
argument_list|(
name|tp
operator|.
name|x
argument_list|()
operator|+
name|rec
operator|.
name|x
argument_list|()
argument_list|,
name|tp
operator|.
name|y
argument_list|()
operator|+
name|rec
operator|.
name|y
argument_list|()
argument_list|,
name|rec
operator|.
name|width
argument_list|()
argument_list|,
name|rec
operator|.
name|height
argument_list|()
argument_list|)
expr_stmt|;
return|return
name|rec
return|;
block|}
DECL|function|isValid
name|bool
name|isValid
parameter_list|()
specifier|const
block|{
return|return
literal|true
return|;
block|}
comment|// (!m_parent.isNull())&& m_parent->count()> m_index; }
DECL|function|childAt
name|QAccessibleInterface
modifier|*
name|childAt
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|)
specifier|const
block|{
return|return
literal|0
return|;
block|}
DECL|function|childCount
name|int
name|childCount
parameter_list|()
specifier|const
block|{
return|return
literal|0
return|;
block|}
DECL|function|indexOfChild
name|int
name|indexOfChild
parameter_list|(
specifier|const
name|QAccessibleInterface
modifier|*
parameter_list|)
specifier|const
block|{
return|return
operator|-
literal|1
return|;
block|}
DECL|function|text
name|QString
name|text
parameter_list|(
name|QAccessible
operator|::
name|Text
parameter_list|)
specifier|const
block|{
return|return
name|qt_accStripAmp
argument_list|(
name|m_parent
operator|->
name|tabText
argument_list|(
name|m_index
argument_list|)
argument_list|)
return|;
block|}
DECL|function|setText
name|void
name|setText
parameter_list|(
name|QAccessible
operator|::
name|Text
parameter_list|,
specifier|const
name|QString
modifier|&
parameter_list|)
block|{}
DECL|function|parent
name|QAccessibleInterface
modifier|*
name|parent
parameter_list|()
specifier|const
block|{
return|return
name|QAccessible
operator|::
name|queryAccessibleInterface
argument_list|(
name|m_parent
argument_list|)
return|;
block|}
DECL|function|child
name|QAccessibleInterface
modifier|*
name|child
parameter_list|(
name|int
parameter_list|)
specifier|const
block|{
return|return
literal|0
return|;
block|}
comment|// action interface
DECL|function|actionNames
name|QStringList
name|actionNames
parameter_list|()
specifier|const
block|{
return|return
name|QStringList
argument_list|(
name|pressAction
argument_list|()
argument_list|)
return|;
block|}
DECL|function|doAction
name|void
name|doAction
parameter_list|(
specifier|const
name|QString
modifier|&
name|actionName
parameter_list|)
block|{
if|if
condition|(
name|actionName
operator|==
name|pressAction
argument_list|()
condition|)
name|m_parent
operator|->
name|setCurrentIndex
argument_list|(
name|m_index
argument_list|)
expr_stmt|;
block|}
DECL|function|keyBindingsForAction
name|QStringList
name|keyBindingsForAction
parameter_list|(
specifier|const
name|QString
modifier|&
parameter_list|)
specifier|const
block|{
return|return
name|QStringList
argument_list|()
return|;
block|}
DECL|function|index
name|int
name|index
parameter_list|()
specifier|const
block|{
return|return
name|m_index
return|;
block|}
private|private:
DECL|member|m_parent
name|QPointer
argument_list|<
name|QTabBar
argument_list|>
name|m_parent
decl_stmt|;
DECL|member|m_index
name|int
name|m_index
decl_stmt|;
block|}
class|;
end_class
begin_comment
comment|/*!   Constructs a QAccessibleTabBar object for \a w. */
end_comment
begin_constructor
DECL|function|QAccessibleTabBar
name|QAccessibleTabBar
operator|::
name|QAccessibleTabBar
parameter_list|(
name|QWidget
modifier|*
name|w
parameter_list|)
member_init_list|:
name|QAccessibleWidget
argument_list|(
name|w
argument_list|,
name|QAccessible
operator|::
name|PageTabList
argument_list|)
block|{
name|Q_ASSERT
argument_list|(
name|tabBar
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_destructor
DECL|function|~QAccessibleTabBar
name|QAccessibleTabBar
operator|::
name|~
name|QAccessibleTabBar
parameter_list|()
block|{
foreach|foreach
control|(
name|QAccessible
operator|::
name|Id
name|id
decl|,
name|m_childInterfaces
operator|.
name|values
argument_list|()
control|)
name|QAccessible
operator|::
name|deleteAccessibleInterface
argument_list|(
name|id
argument_list|)
expr_stmt|;
block|}
end_destructor
begin_comment
comment|/*! Returns the QTabBar. */
end_comment
begin_function
DECL|function|tabBar
name|QTabBar
modifier|*
name|QAccessibleTabBar
operator|::
name|tabBar
parameter_list|()
specifier|const
block|{
return|return
name|qobject_cast
argument_list|<
name|QTabBar
operator|*
argument_list|>
argument_list|(
name|object
argument_list|()
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|child
name|QAccessibleInterface
modifier|*
name|QAccessibleTabBar
operator|::
name|child
parameter_list|(
name|int
name|index
parameter_list|)
specifier|const
block|{
if|if
condition|(
name|QAccessible
operator|::
name|Id
name|id
init|=
name|m_childInterfaces
operator|.
name|value
argument_list|(
name|index
argument_list|)
condition|)
return|return
name|QAccessible
operator|::
name|accessibleInterface
argument_list|(
name|id
argument_list|)
return|;
comment|// first the tabs, then 2 buttons
if|if
condition|(
name|index
operator|<
name|tabBar
argument_list|()
operator|->
name|count
argument_list|()
condition|)
block|{
name|QAccessibleTabButton
modifier|*
name|button
init|=
operator|new
name|QAccessibleTabButton
argument_list|(
name|tabBar
argument_list|()
argument_list|,
name|index
argument_list|)
decl_stmt|;
name|QAccessible
operator|::
name|registerAccessibleInterface
argument_list|(
name|button
argument_list|)
expr_stmt|;
name|m_childInterfaces
operator|.
name|insert
argument_list|(
name|index
argument_list|,
name|QAccessible
operator|::
name|uniqueId
argument_list|(
name|button
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|button
return|;
block|}
elseif|else
if|if
condition|(
name|index
operator|>=
name|tabBar
argument_list|()
operator|->
name|count
argument_list|()
condition|)
block|{
comment|// left button
if|if
condition|(
name|index
operator|-
name|tabBar
argument_list|()
operator|->
name|count
argument_list|()
operator|==
literal|0
condition|)
block|{
return|return
name|QAccessible
operator|::
name|queryAccessibleInterface
argument_list|(
name|tabBar
argument_list|()
operator|->
name|d_func
argument_list|()
operator|->
name|leftB
argument_list|)
return|;
block|}
comment|// right button
if|if
condition|(
name|index
operator|-
name|tabBar
argument_list|()
operator|->
name|count
argument_list|()
operator|==
literal|1
condition|)
block|{
return|return
name|QAccessible
operator|::
name|queryAccessibleInterface
argument_list|(
name|tabBar
argument_list|()
operator|->
name|d_func
argument_list|()
operator|->
name|rightB
argument_list|)
return|;
block|}
block|}
return|return
literal|0
return|;
block|}
end_function
begin_function
DECL|function|indexOfChild
name|int
name|QAccessibleTabBar
operator|::
name|indexOfChild
parameter_list|(
specifier|const
name|QAccessibleInterface
modifier|*
name|child
parameter_list|)
specifier|const
block|{
if|if
condition|(
name|child
operator|->
name|object
argument_list|()
operator|&&
name|child
operator|->
name|object
argument_list|()
operator|==
name|tabBar
argument_list|()
operator|->
name|d_func
argument_list|()
operator|->
name|leftB
condition|)
return|return
name|tabBar
argument_list|()
operator|->
name|count
argument_list|()
return|;
if|if
condition|(
name|child
operator|->
name|object
argument_list|()
operator|&&
name|child
operator|->
name|object
argument_list|()
operator|==
name|tabBar
argument_list|()
operator|->
name|d_func
argument_list|()
operator|->
name|rightB
condition|)
return|return
name|tabBar
argument_list|()
operator|->
name|count
argument_list|()
operator|+
literal|1
return|;
if|if
condition|(
name|child
operator|->
name|role
argument_list|()
operator|==
name|QAccessible
operator|::
name|PageTab
condition|)
block|{
name|QAccessibleInterface
modifier|*
name|parent
init|=
name|child
operator|->
name|parent
argument_list|()
decl_stmt|;
if|if
condition|(
name|parent
operator|==
name|this
condition|)
block|{
specifier|const
name|QAccessibleTabButton
modifier|*
name|tabButton
init|=
cast|static_cast
argument_list|<
specifier|const
name|QAccessibleTabButton
operator|*
argument_list|>
argument_list|(
name|child
argument_list|)
decl_stmt|;
return|return
name|tabButton
operator|->
name|index
argument_list|()
return|;
block|}
block|}
return|return
operator|-
literal|1
return|;
block|}
end_function
begin_function
DECL|function|childCount
name|int
name|QAccessibleTabBar
operator|::
name|childCount
parameter_list|()
specifier|const
block|{
comment|// tabs + scroll buttons
return|return
name|tabBar
argument_list|()
operator|->
name|count
argument_list|()
operator|+
literal|2
return|;
block|}
end_function
begin_function
DECL|function|text
name|QString
name|QAccessibleTabBar
operator|::
name|text
parameter_list|(
name|QAccessible
operator|::
name|Text
name|t
parameter_list|)
specifier|const
block|{
if|if
condition|(
name|t
operator|==
name|QAccessible
operator|::
name|Name
condition|)
block|{
return|return
name|qt_accStripAmp
argument_list|(
name|tabBar
argument_list|()
operator|->
name|tabText
argument_list|(
name|tabBar
argument_list|()
operator|->
name|currentIndex
argument_list|()
argument_list|)
argument_list|)
return|;
block|}
return|return
name|QString
argument_list|()
return|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_TABBAR
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_COMBOBOX
end_ifndef
begin_comment
comment|/*!   \class QAccessibleComboBox   \brief The QAccessibleComboBox class implements the QAccessibleInterface for editable and read-only combo boxes.   \internal    \ingroup accessibility */
end_comment
begin_comment
comment|/*!   Constructs a QAccessibleComboBox object for \a w. */
end_comment
begin_constructor
DECL|function|QAccessibleComboBox
name|QAccessibleComboBox
operator|::
name|QAccessibleComboBox
parameter_list|(
name|QWidget
modifier|*
name|w
parameter_list|)
member_init_list|:
name|QAccessibleWidget
argument_list|(
name|w
argument_list|,
name|QAccessible
operator|::
name|ComboBox
argument_list|)
block|{
name|Q_ASSERT
argument_list|(
name|comboBox
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_comment
comment|/*!   Returns the combobox. */
end_comment
begin_function
DECL|function|comboBox
name|QComboBox
modifier|*
name|QAccessibleComboBox
operator|::
name|comboBox
parameter_list|()
specifier|const
block|{
return|return
name|qobject_cast
argument_list|<
name|QComboBox
operator|*
argument_list|>
argument_list|(
name|object
argument_list|()
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|child
name|QAccessibleInterface
modifier|*
name|QAccessibleComboBox
operator|::
name|child
parameter_list|(
name|int
name|index
parameter_list|)
specifier|const
block|{
if|if
condition|(
name|index
operator|==
literal|0
condition|)
block|{
name|QAbstractItemView
modifier|*
name|view
init|=
name|comboBox
argument_list|()
operator|->
name|view
argument_list|()
decl_stmt|;
comment|//QWidget *parent = view ? view->parentWidget() : 0;
return|return
name|QAccessible
operator|::
name|queryAccessibleInterface
argument_list|(
name|view
argument_list|)
return|;
block|}
elseif|else
if|if
condition|(
name|index
operator|==
literal|1
operator|&&
name|comboBox
argument_list|()
operator|->
name|isEditable
argument_list|()
condition|)
block|{
return|return
name|QAccessible
operator|::
name|queryAccessibleInterface
argument_list|(
name|comboBox
argument_list|()
operator|->
name|lineEdit
argument_list|()
argument_list|)
return|;
block|}
return|return
literal|0
return|;
block|}
end_function
begin_function
DECL|function|childCount
name|int
name|QAccessibleComboBox
operator|::
name|childCount
parameter_list|()
specifier|const
block|{
comment|// list and text edit
return|return
name|comboBox
argument_list|()
operator|->
name|isEditable
argument_list|()
condition|?
literal|2
else|:
literal|1
return|;
block|}
end_function
begin_function
DECL|function|childAt
name|QAccessibleInterface
modifier|*
name|QAccessibleComboBox
operator|::
name|childAt
parameter_list|(
name|int
name|x
parameter_list|,
name|int
name|y
parameter_list|)
specifier|const
block|{
if|if
condition|(
name|comboBox
argument_list|()
operator|->
name|isEditable
argument_list|()
operator|&&
name|comboBox
argument_list|()
operator|->
name|lineEdit
argument_list|()
operator|->
name|rect
argument_list|()
operator|.
name|contains
argument_list|(
name|x
argument_list|,
name|y
argument_list|)
condition|)
return|return
name|child
argument_list|(
literal|1
argument_list|)
return|;
return|return
literal|0
return|;
block|}
end_function
begin_function
DECL|function|indexOfChild
name|int
name|QAccessibleComboBox
operator|::
name|indexOfChild
parameter_list|(
specifier|const
name|QAccessibleInterface
modifier|*
name|child
parameter_list|)
specifier|const
block|{
if|if
condition|(
name|comboBox
argument_list|()
operator|->
name|view
argument_list|()
operator|==
name|child
operator|->
name|object
argument_list|()
condition|)
return|return
literal|0
return|;
if|if
condition|(
name|comboBox
argument_list|()
operator|->
name|isEditable
argument_list|()
operator|&&
name|comboBox
argument_list|()
operator|->
name|lineEdit
argument_list|()
operator|==
name|child
operator|->
name|object
argument_list|()
condition|)
return|return
literal|1
return|;
return|return
operator|-
literal|1
return|;
block|}
end_function
begin_comment
comment|/*! \reimp */
end_comment
begin_function
DECL|function|text
name|QString
name|QAccessibleComboBox
operator|::
name|text
parameter_list|(
name|QAccessible
operator|::
name|Text
name|t
parameter_list|)
specifier|const
block|{
name|QString
name|str
decl_stmt|;
switch|switch
condition|(
name|t
condition|)
block|{
case|case
name|QAccessible
operator|::
name|Name
case|:
ifndef|#
directive|ifndef
name|Q_OS_UNIX
comment|// on Linux we use relations for this, name is text (fall through to Value)
name|str
operator|=
name|QAccessibleWidget
operator|::
name|text
argument_list|(
name|t
argument_list|)
expr_stmt|;
break|break;
endif|#
directive|endif
case|case
name|QAccessible
operator|::
name|Value
case|:
if|if
condition|(
name|comboBox
argument_list|()
operator|->
name|isEditable
argument_list|()
condition|)
name|str
operator|=
name|comboBox
argument_list|()
operator|->
name|lineEdit
argument_list|()
operator|->
name|text
argument_list|()
expr_stmt|;
else|else
name|str
operator|=
name|comboBox
argument_list|()
operator|->
name|currentText
argument_list|()
expr_stmt|;
break|break;
ifndef|#
directive|ifndef
name|QT_NO_SHORTCUT
case|case
name|QAccessible
operator|::
name|Accelerator
case|:
name|str
operator|=
name|QKeySequence
argument_list|(
name|Qt
operator|::
name|Key_Down
argument_list|)
operator|.
name|toString
argument_list|(
name|QKeySequence
operator|::
name|NativeText
argument_list|)
expr_stmt|;
break|break;
endif|#
directive|endif
default|default:
break|break;
block|}
if|if
condition|(
name|str
operator|.
name|isEmpty
argument_list|()
condition|)
name|str
operator|=
name|QAccessibleWidget
operator|::
name|text
argument_list|(
name|t
argument_list|)
expr_stmt|;
return|return
name|str
return|;
block|}
end_function
begin_function
DECL|function|actionNames
name|QStringList
name|QAccessibleComboBox
operator|::
name|actionNames
parameter_list|()
specifier|const
block|{
return|return
name|QStringList
argument_list|(
name|showMenuAction
argument_list|()
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|localizedActionDescription
name|QString
name|QAccessibleComboBox
operator|::
name|localizedActionDescription
parameter_list|(
specifier|const
name|QString
modifier|&
name|actionName
parameter_list|)
specifier|const
block|{
if|if
condition|(
name|actionName
operator|==
name|showMenuAction
argument_list|()
condition|)
return|return
name|QComboBox
operator|::
name|tr
argument_list|(
literal|"Open the combo box selection popup"
argument_list|)
return|;
return|return
name|QString
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|doAction
name|void
name|QAccessibleComboBox
operator|::
name|doAction
parameter_list|(
specifier|const
name|QString
modifier|&
name|actionName
parameter_list|)
block|{
if|if
condition|(
name|actionName
operator|==
name|showMenuAction
argument_list|()
condition|)
block|{
if|if
condition|(
name|comboBox
argument_list|()
operator|->
name|view
argument_list|()
operator|->
name|isVisible
argument_list|()
condition|)
block|{
name|comboBox
argument_list|()
operator|->
name|hidePopup
argument_list|()
expr_stmt|;
block|}
else|else
block|{
name|comboBox
argument_list|()
operator|->
name|showPopup
argument_list|()
expr_stmt|;
block|}
block|}
block|}
end_function
begin_function
DECL|function|keyBindingsForAction
name|QStringList
name|QAccessibleComboBox
operator|::
name|keyBindingsForAction
parameter_list|(
specifier|const
name|QString
modifier|&
comment|/*actionName*/
parameter_list|)
specifier|const
block|{
return|return
name|QStringList
argument_list|()
return|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_COMBOBOX
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_SCROLLAREA
end_ifndef
begin_comment
comment|// ======================= QAccessibleAbstractScrollArea =======================
end_comment
begin_constructor
DECL|function|QAccessibleAbstractScrollArea
name|QAccessibleAbstractScrollArea
operator|::
name|QAccessibleAbstractScrollArea
parameter_list|(
name|QWidget
modifier|*
name|widget
parameter_list|)
member_init_list|:
name|QAccessibleWidget
argument_list|(
name|widget
argument_list|,
name|QAccessible
operator|::
name|Client
argument_list|)
block|{
name|Q_ASSERT
argument_list|(
name|qobject_cast
argument_list|<
name|QAbstractScrollArea
operator|*
argument_list|>
argument_list|(
name|widget
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_function
DECL|function|child
name|QAccessibleInterface
modifier|*
name|QAccessibleAbstractScrollArea
operator|::
name|child
parameter_list|(
name|int
name|index
parameter_list|)
specifier|const
block|{
return|return
name|QAccessible
operator|::
name|queryAccessibleInterface
argument_list|(
name|accessibleChildren
argument_list|()
operator|.
name|at
argument_list|(
name|index
argument_list|)
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|childCount
name|int
name|QAccessibleAbstractScrollArea
operator|::
name|childCount
parameter_list|()
specifier|const
block|{
return|return
name|accessibleChildren
argument_list|()
operator|.
name|count
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|indexOfChild
name|int
name|QAccessibleAbstractScrollArea
operator|::
name|indexOfChild
parameter_list|(
specifier|const
name|QAccessibleInterface
modifier|*
name|child
parameter_list|)
specifier|const
block|{
if|if
condition|(
operator|!
name|child
operator|||
operator|!
name|child
operator|->
name|object
argument_list|()
condition|)
return|return
operator|-
literal|1
return|;
return|return
name|accessibleChildren
argument_list|()
operator|.
name|indexOf
argument_list|(
name|qobject_cast
argument_list|<
name|QWidget
operator|*
argument_list|>
argument_list|(
name|child
operator|->
name|object
argument_list|()
argument_list|)
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|isValid
name|bool
name|QAccessibleAbstractScrollArea
operator|::
name|isValid
parameter_list|()
specifier|const
block|{
return|return
operator|(
name|QAccessibleWidget
operator|::
name|isValid
argument_list|()
operator|&&
name|abstractScrollArea
argument_list|()
operator|&&
name|abstractScrollArea
argument_list|()
operator|->
name|viewport
argument_list|()
operator|)
return|;
block|}
end_function
begin_function
DECL|function|childAt
name|QAccessibleInterface
modifier|*
name|QAccessibleAbstractScrollArea
operator|::
name|childAt
parameter_list|(
name|int
name|x
parameter_list|,
name|int
name|y
parameter_list|)
specifier|const
block|{
if|if
condition|(
operator|!
name|abstractScrollArea
argument_list|()
operator|->
name|isVisible
argument_list|()
condition|)
return|return
literal|0
return|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|childCount
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
name|QPoint
name|wpos
init|=
name|accessibleChildren
argument_list|()
operator|.
name|at
argument_list|(
name|i
argument_list|)
operator|->
name|mapToGlobal
argument_list|(
name|QPoint
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
argument_list|)
decl_stmt|;
name|QRect
name|rect
init|=
name|QRect
argument_list|(
name|wpos
argument_list|,
name|accessibleChildren
argument_list|()
operator|.
name|at
argument_list|(
name|i
argument_list|)
operator|->
name|size
argument_list|()
argument_list|)
decl_stmt|;
if|if
condition|(
name|rect
operator|.
name|contains
argument_list|(
name|x
argument_list|,
name|y
argument_list|)
condition|)
return|return
name|child
argument_list|(
name|i
argument_list|)
return|;
block|}
return|return
literal|0
return|;
block|}
end_function
begin_function
DECL|function|abstractScrollArea
name|QAbstractScrollArea
modifier|*
name|QAccessibleAbstractScrollArea
operator|::
name|abstractScrollArea
parameter_list|()
specifier|const
block|{
return|return
cast|static_cast
argument_list|<
name|QAbstractScrollArea
operator|*
argument_list|>
argument_list|(
name|object
argument_list|()
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|accessibleChildren
name|QWidgetList
name|QAccessibleAbstractScrollArea
operator|::
name|accessibleChildren
parameter_list|()
specifier|const
block|{
name|QWidgetList
name|children
decl_stmt|;
comment|// Viewport.
name|QWidget
modifier|*
name|viewport
init|=
name|abstractScrollArea
argument_list|()
operator|->
name|viewport
argument_list|()
decl_stmt|;
if|if
condition|(
name|viewport
condition|)
name|children
operator|.
name|append
argument_list|(
name|viewport
argument_list|)
expr_stmt|;
comment|// Horizontal scrollBar container.
name|QScrollBar
modifier|*
name|horizontalScrollBar
init|=
name|abstractScrollArea
argument_list|()
operator|->
name|horizontalScrollBar
argument_list|()
decl_stmt|;
if|if
condition|(
name|horizontalScrollBar
operator|&&
name|horizontalScrollBar
operator|->
name|isVisible
argument_list|()
condition|)
block|{
name|children
operator|.
name|append
argument_list|(
name|horizontalScrollBar
operator|->
name|parentWidget
argument_list|()
argument_list|)
expr_stmt|;
block|}
comment|// Vertical scrollBar container.
name|QScrollBar
modifier|*
name|verticalScrollBar
init|=
name|abstractScrollArea
argument_list|()
operator|->
name|verticalScrollBar
argument_list|()
decl_stmt|;
if|if
condition|(
name|verticalScrollBar
operator|&&
name|verticalScrollBar
operator|->
name|isVisible
argument_list|()
condition|)
block|{
name|children
operator|.
name|append
argument_list|(
name|verticalScrollBar
operator|->
name|parentWidget
argument_list|()
argument_list|)
expr_stmt|;
block|}
comment|// CornerWidget.
name|QWidget
modifier|*
name|cornerWidget
init|=
name|abstractScrollArea
argument_list|()
operator|->
name|cornerWidget
argument_list|()
decl_stmt|;
if|if
condition|(
name|cornerWidget
operator|&&
name|cornerWidget
operator|->
name|isVisible
argument_list|()
condition|)
name|children
operator|.
name|append
argument_list|(
name|cornerWidget
argument_list|)
expr_stmt|;
return|return
name|children
return|;
block|}
end_function
begin_function
name|QAccessibleAbstractScrollArea
operator|::
name|AbstractScrollAreaElement
DECL|function|elementType
name|QAccessibleAbstractScrollArea
operator|::
name|elementType
parameter_list|(
name|QWidget
modifier|*
name|widget
parameter_list|)
specifier|const
block|{
if|if
condition|(
operator|!
name|widget
condition|)
return|return
name|Undefined
return|;
if|if
condition|(
name|widget
operator|==
name|abstractScrollArea
argument_list|()
condition|)
return|return
name|Self
return|;
if|if
condition|(
name|widget
operator|==
name|abstractScrollArea
argument_list|()
operator|->
name|viewport
argument_list|()
condition|)
return|return
name|Viewport
return|;
if|if
condition|(
name|widget
operator|->
name|objectName
argument_list|()
operator|==
name|QLatin1String
argument_list|(
literal|"qt_scrollarea_hcontainer"
argument_list|)
condition|)
return|return
name|HorizontalContainer
return|;
if|if
condition|(
name|widget
operator|->
name|objectName
argument_list|()
operator|==
name|QLatin1String
argument_list|(
literal|"qt_scrollarea_vcontainer"
argument_list|)
condition|)
return|return
name|VerticalContainer
return|;
if|if
condition|(
name|widget
operator|==
name|abstractScrollArea
argument_list|()
operator|->
name|cornerWidget
argument_list|()
condition|)
return|return
name|CornerWidget
return|;
return|return
name|Undefined
return|;
block|}
end_function
begin_function
DECL|function|isLeftToRight
name|bool
name|QAccessibleAbstractScrollArea
operator|::
name|isLeftToRight
parameter_list|()
specifier|const
block|{
return|return
name|abstractScrollArea
argument_list|()
operator|->
name|isLeftToRight
argument_list|()
return|;
block|}
end_function
begin_comment
comment|// ======================= QAccessibleScrollArea ===========================
end_comment
begin_constructor
DECL|function|QAccessibleScrollArea
name|QAccessibleScrollArea
operator|::
name|QAccessibleScrollArea
parameter_list|(
name|QWidget
modifier|*
name|widget
parameter_list|)
member_init_list|:
name|QAccessibleAbstractScrollArea
argument_list|(
name|widget
argument_list|)
block|{
name|Q_ASSERT
argument_list|(
name|qobject_cast
argument_list|<
name|QScrollArea
operator|*
argument_list|>
argument_list|(
name|widget
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
comment|// QT_NO_SCROLLAREA
end_comment
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_ACCESSIBILITY
end_comment
end_unit