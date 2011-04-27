begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** No Commercial Usage ** This file contains pre-release code and may not be distributed. ** You may use this file in accordance with the terms and conditions ** contained in the Technology Preview License Agreement accompanying ** this package. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights.  These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** If you have questions regarding the use of this file, please contact ** Nokia at qt-info@nokia.com. ** ** ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qaccessibleobject.h"
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_ACCESSIBILITY
end_ifndef
begin_include
include|#
directive|include
file|"qapplication.h"
end_include
begin_include
include|#
directive|include
file|"qwidget.h"
end_include
begin_include
include|#
directive|include
file|"qpointer.h"
end_include
begin_include
include|#
directive|include
file|"qmetaobject.h"
end_include
begin_include
include|#
directive|include
file|"qvarlengtharray.h"
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_class
DECL|class|QAccessibleObjectPrivate
class|class
name|QAccessibleObjectPrivate
block|{
public|public:
DECL|member|object
name|QPointer
argument_list|<
name|QObject
argument_list|>
name|object
decl_stmt|;
name|QList
argument_list|<
name|QByteArray
argument_list|>
name|actionList
parameter_list|()
specifier|const
function_decl|;
block|}
class|;
end_class
begin_function
DECL|function|actionList
name|QList
argument_list|<
name|QByteArray
argument_list|>
name|QAccessibleObjectPrivate
operator|::
name|actionList
parameter_list|()
specifier|const
block|{
name|QList
argument_list|<
name|QByteArray
argument_list|>
name|actionList
decl_stmt|;
if|if
condition|(
operator|!
name|object
condition|)
return|return
name|actionList
return|;
specifier|const
name|QMetaObject
modifier|*
name|mo
init|=
name|object
operator|->
name|metaObject
argument_list|()
decl_stmt|;
name|Q_ASSERT
argument_list|(
name|mo
argument_list|)
expr_stmt|;
name|QByteArray
name|defaultAction
init|=
name|QMetaObject
operator|::
name|normalizedSignature
argument_list|(
name|mo
operator|->
name|classInfo
argument_list|(
name|mo
operator|->
name|indexOfClassInfo
argument_list|(
literal|"DefaultSlot"
argument_list|)
argument_list|)
operator|.
name|value
argument_list|()
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
operator|<
name|mo
operator|->
name|methodCount
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
specifier|const
name|QMetaMethod
name|member
init|=
name|mo
operator|->
name|method
argument_list|(
name|i
argument_list|)
decl_stmt|;
if|if
condition|(
name|member
operator|.
name|methodType
argument_list|()
operator|!=
name|QMetaMethod
operator|::
name|Slot
operator|&&
name|member
operator|.
name|access
argument_list|()
operator|!=
name|QMetaMethod
operator|::
name|Public
condition|)
continue|continue;
if|if
condition|(
operator|!
name|qstrcmp
argument_list|(
name|member
operator|.
name|tag
argument_list|()
argument_list|,
literal|"QACCESSIBLE_SLOT"
argument_list|)
condition|)
block|{
if|if
condition|(
name|member
operator|.
name|signature
argument_list|()
operator|==
name|defaultAction
condition|)
name|actionList
operator|.
name|prepend
argument_list|(
name|defaultAction
argument_list|)
expr_stmt|;
else|else
name|actionList
operator|<<
name|member
operator|.
name|signature
argument_list|()
expr_stmt|;
block|}
block|}
return|return
name|actionList
return|;
block|}
end_function
begin_comment
comment|/*!     \class QAccessibleObject     \brief The QAccessibleObject class implements parts of the     QAccessibleInterface for QObjects.      \ingroup accessibility      This class is mainly provided for convenience. All subclasses of     the QAccessibleInterface that provide implementations of non-widget objects     should use this class as their base class.      \sa QAccessible, QAccessibleWidget */
end_comment
begin_comment
comment|/*!     Creates a QAccessibleObject for \a object. */
end_comment
begin_constructor
DECL|function|QAccessibleObject
name|QAccessibleObject
operator|::
name|QAccessibleObject
parameter_list|(
name|QObject
modifier|*
name|object
parameter_list|)
block|{
name|d
operator|=
operator|new
name|QAccessibleObjectPrivate
expr_stmt|;
name|d
operator|->
name|object
operator|=
name|object
expr_stmt|;
block|}
end_constructor
begin_comment
comment|/*!     Destroys the QAccessibleObject.      This only happens when a call to release() decrements the internal     reference counter to zero. */
end_comment
begin_destructor
DECL|function|~QAccessibleObject
name|QAccessibleObject
operator|::
name|~
name|QAccessibleObject
parameter_list|()
block|{
operator|delete
name|d
expr_stmt|;
block|}
end_destructor
begin_comment
comment|/*!     \reimp */
end_comment
begin_function
DECL|function|object
name|QObject
modifier|*
name|QAccessibleObject
operator|::
name|object
parameter_list|()
specifier|const
block|{
ifndef|#
directive|ifndef
name|QT_NO_DEBUG
if|if
condition|(
operator|!
name|d
operator|->
name|object
condition|)
name|qWarning
argument_list|(
literal|"QAccessibleInterface is invalid. Crash pending..."
argument_list|)
expr_stmt|;
endif|#
directive|endif
return|return
name|d
operator|->
name|object
return|;
block|}
end_function
begin_comment
comment|/*!     \reimp */
end_comment
begin_function
DECL|function|isValid
name|bool
name|QAccessibleObject
operator|::
name|isValid
parameter_list|()
specifier|const
block|{
return|return
operator|!
name|d
operator|->
name|object
operator|.
name|isNull
argument_list|()
return|;
block|}
end_function
begin_comment
comment|/*! \reimp */
end_comment
begin_function
DECL|function|rect
name|QRect
name|QAccessibleObject
operator|::
name|rect
parameter_list|(
name|int
parameter_list|)
specifier|const
block|{
return|return
name|QRect
argument_list|()
return|;
block|}
end_function
begin_comment
comment|/*! \reimp */
end_comment
begin_function
DECL|function|setText
name|void
name|QAccessibleObject
operator|::
name|setText
parameter_list|(
name|Text
parameter_list|,
name|int
parameter_list|,
specifier|const
name|QString
modifier|&
parameter_list|)
block|{ }
end_function
begin_comment
comment|/*! \reimp */
end_comment
begin_function
DECL|function|userActionCount
name|int
name|QAccessibleObject
operator|::
name|userActionCount
parameter_list|(
name|int
parameter_list|)
specifier|const
block|{
return|return
literal|0
return|;
block|}
end_function
begin_comment
comment|/*! \reimp */
end_comment
begin_function
DECL|function|doAction
name|bool
name|QAccessibleObject
operator|::
name|doAction
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|,
specifier|const
name|QVariantList
modifier|&
parameter_list|)
block|{
return|return
literal|false
return|;
block|}
end_function
begin_decl_stmt
DECL|variable|action_text
specifier|static
specifier|const
name|char
modifier|*
specifier|const
name|action_text
index|[]
index|[
literal|5
index|]
init|=
block|{
comment|// Name, Description, Value, Help, Accelerator
block|{
literal|"Press"
block|,
literal|""
block|,
literal|""
block|,
literal|""
block|,
literal|"Space"
block|}
block|,
block|{
literal|"SetFocus"
block|,
literal|"Passes focus to this widget"
block|,
literal|""
block|,
literal|""
block|,
literal|""
block|}
block|,
block|{
literal|"Increase"
block|,
literal|""
block|,
literal|""
block|,
literal|""
block|,
literal|""
block|}
block|,
block|{
literal|"Decrease"
block|,
literal|""
block|,
literal|""
block|,
literal|""
block|,
literal|""
block|}
block|,
block|{
literal|"Accept"
block|,
literal|""
block|,
literal|""
block|,
literal|""
block|,
literal|""
block|}
block|,
block|{
literal|"Cancel"
block|,
literal|""
block|,
literal|""
block|,
literal|""
block|,
literal|""
block|}
block|,
block|{
literal|"Select"
block|,
literal|""
block|,
literal|""
block|,
literal|""
block|,
literal|""
block|}
block|,
block|{
literal|"ClearSelection"
block|,
literal|""
block|,
literal|""
block|,
literal|""
block|,
literal|""
block|}
block|,
block|{
literal|"RemoveSelection"
block|,
literal|""
block|,
literal|""
block|,
literal|""
block|,
literal|""
block|}
block|,
block|{
literal|"ExtendSelection"
block|,
literal|""
block|,
literal|""
block|,
literal|""
block|,
literal|""
block|}
block|,
block|{
literal|"AddToSelection"
block|,
literal|""
block|,
literal|""
block|,
literal|""
block|,
literal|""
block|}
block|}
decl_stmt|;
end_decl_stmt
begin_comment
comment|/*! \reimp */
end_comment
begin_function
DECL|function|actionText
name|QString
name|QAccessibleObject
operator|::
name|actionText
parameter_list|(
name|int
name|action
parameter_list|,
name|Text
name|t
parameter_list|,
name|int
name|child
parameter_list|)
specifier|const
block|{
if|if
condition|(
name|child
operator|||
name|action
operator|>
name|FirstStandardAction
operator|||
name|action
argument_list|<
name|LastStandardAction
operator|||
name|t
argument_list|>
name|Accelerator
condition|)
return|return
name|QString
argument_list|()
return|;
return|return
name|QString
operator|::
name|fromLatin1
argument_list|(
name|action_text
index|[
operator|-
operator|(
name|action
operator|-
name|FirstStandardAction
operator|)
index|]
index|[
name|t
index|]
argument_list|)
return|;
block|}
end_function
begin_comment
comment|/*!     \class QAccessibleApplication     \brief The QAccessibleApplication class implements the QAccessibleInterface for QApplication.      \internal      \ingroup accessibility */
end_comment
begin_comment
comment|/*!     Creates a QAccessibleApplication for the QApplication object referenced by qApp. */
end_comment
begin_constructor
DECL|function|QAccessibleApplication
name|QAccessibleApplication
operator|::
name|QAccessibleApplication
parameter_list|()
member_init_list|:
name|QAccessibleObject
argument_list|(
name|qApp
argument_list|)
block|{ }
end_constructor
begin_comment
comment|// all toplevel widgets except popups and the desktop
end_comment
begin_function
DECL|function|topLevelWidgets
specifier|static
name|QWidgetList
name|topLevelWidgets
parameter_list|()
block|{
name|QWidgetList
name|list
decl_stmt|;
specifier|const
name|QWidgetList
name|tlw
argument_list|(
name|QApplication
operator|::
name|topLevelWidgets
argument_list|()
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
operator|<
name|tlw
operator|.
name|count
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
name|QWidget
modifier|*
name|w
init|=
name|tlw
operator|.
name|at
argument_list|(
name|i
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
operator|(
name|w
operator|->
name|windowType
argument_list|()
operator|==
name|Qt
operator|::
name|Popup
operator|)
operator|&&
operator|!
operator|(
name|w
operator|->
name|windowType
argument_list|()
operator|==
name|Qt
operator|::
name|Desktop
operator|)
condition|)
name|list
operator|.
name|append
argument_list|(
name|w
argument_list|)
expr_stmt|;
block|}
return|return
name|list
return|;
block|}
end_function
begin_comment
comment|/*! \reimp */
end_comment
begin_function
DECL|function|childCount
name|int
name|QAccessibleApplication
operator|::
name|childCount
parameter_list|()
specifier|const
block|{
return|return
name|topLevelWidgets
argument_list|()
operator|.
name|count
argument_list|()
return|;
block|}
end_function
begin_comment
comment|/*! \reimp */
end_comment
begin_function
DECL|function|indexOfChild
name|int
name|QAccessibleApplication
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
operator|->
name|object
argument_list|()
operator|->
name|isWidgetType
argument_list|()
condition|)
return|return
operator|-
literal|1
return|;
specifier|const
name|QWidgetList
name|tlw
argument_list|(
name|topLevelWidgets
argument_list|()
argument_list|)
decl_stmt|;
name|int
name|index
init|=
name|tlw
operator|.
name|indexOf
argument_list|(
cast|static_cast
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
decl_stmt|;
if|if
condition|(
name|index
operator|!=
operator|-
literal|1
condition|)
operator|++
name|index
expr_stmt|;
return|return
name|index
return|;
block|}
end_function
begin_comment
comment|/*! \reimp */
end_comment
begin_function
DECL|function|childAt
name|int
name|QAccessibleApplication
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
specifier|const
name|QWidgetList
name|tlw
argument_list|(
name|topLevelWidgets
argument_list|()
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
operator|<
name|tlw
operator|.
name|count
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
name|QWidget
modifier|*
name|w
init|=
name|tlw
operator|.
name|at
argument_list|(
name|i
argument_list|)
decl_stmt|;
if|if
condition|(
name|w
operator|->
name|frameGeometry
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
name|i
operator|+
literal|1
return|;
block|}
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
DECL|function|relationTo
name|QAccessible
operator|::
name|Relation
name|QAccessibleApplication
operator|::
name|relationTo
parameter_list|(
name|int
name|child
parameter_list|,
specifier|const
name|QAccessibleInterface
modifier|*
name|other
parameter_list|,
name|int
name|otherChild
parameter_list|)
specifier|const
block|{
name|QObject
modifier|*
name|o
init|=
name|other
condition|?
name|other
operator|->
name|object
argument_list|()
else|:
literal|0
decl_stmt|;
if|if
condition|(
operator|!
name|o
condition|)
return|return
name|Unrelated
return|;
if|if
condition|(
name|o
operator|==
name|object
argument_list|()
condition|)
block|{
if|if
condition|(
name|child
operator|&&
operator|!
name|otherChild
condition|)
return|return
name|Child
return|;
if|if
condition|(
operator|!
name|child
operator|&&
name|otherChild
condition|)
return|return
name|Ancestor
return|;
if|if
condition|(
operator|!
name|child
operator|&&
operator|!
name|otherChild
condition|)
return|return
name|Self
return|;
block|}
name|QWidgetList
name|tlw
argument_list|(
name|topLevelWidgets
argument_list|()
argument_list|)
decl_stmt|;
if|if
condition|(
name|tlw
operator|.
name|contains
argument_list|(
name|qobject_cast
argument_list|<
name|QWidget
operator|*
argument_list|>
argument_list|(
name|o
argument_list|)
argument_list|)
condition|)
return|return
name|Ancestor
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
name|tlw
operator|.
name|count
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
name|QWidget
modifier|*
name|w
init|=
name|tlw
operator|.
name|at
argument_list|(
name|i
argument_list|)
decl_stmt|;
name|QObjectList
name|cl
init|=
name|w
operator|->
name|findChildren
argument_list|<
name|QObject
operator|*
argument_list|>
argument_list|(
name|QString
argument_list|()
argument_list|)
decl_stmt|;
if|if
condition|(
name|cl
operator|.
name|contains
argument_list|(
name|o
argument_list|)
condition|)
return|return
name|Ancestor
return|;
block|}
return|return
name|Unrelated
return|;
block|}
end_function
begin_comment
comment|/*! \reimp */
end_comment
begin_function
DECL|function|navigate
name|int
name|QAccessibleApplication
operator|::
name|navigate
parameter_list|(
name|RelationFlag
name|relation
parameter_list|,
name|int
name|entry
parameter_list|,
name|QAccessibleInterface
modifier|*
modifier|*
name|target
parameter_list|)
specifier|const
block|{
if|if
condition|(
operator|!
name|target
condition|)
return|return
operator|-
literal|1
return|;
operator|*
name|target
operator|=
literal|0
expr_stmt|;
name|QObject
modifier|*
name|targetObject
init|=
literal|0
decl_stmt|;
switch|switch
condition|(
name|relation
condition|)
block|{
case|case
name|Self
case|:
name|targetObject
operator|=
name|object
argument_list|()
expr_stmt|;
break|break;
case|case
name|Child
case|:
if|if
condition|(
name|entry
operator|>
literal|0
operator|&&
name|entry
operator|<=
name|childCount
argument_list|()
condition|)
block|{
specifier|const
name|QWidgetList
name|tlw
argument_list|(
name|topLevelWidgets
argument_list|()
argument_list|)
decl_stmt|;
if|if
condition|(
name|tlw
operator|.
name|count
argument_list|()
operator|>=
name|entry
condition|)
name|targetObject
operator|=
name|tlw
operator|.
name|at
argument_list|(
name|entry
operator|-
literal|1
argument_list|)
expr_stmt|;
block|}
else|else
block|{
return|return
operator|-
literal|1
return|;
block|}
break|break;
case|case
name|FocusChild
case|:
name|targetObject
operator|=
name|QApplication
operator|::
name|activeWindow
argument_list|()
expr_stmt|;
break|break;
default|default:
break|break;
block|}
operator|*
name|target
operator|=
name|QAccessible
operator|::
name|queryAccessibleInterface
argument_list|(
name|targetObject
argument_list|)
expr_stmt|;
return|return
operator|*
name|target
condition|?
literal|0
else|:
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
name|QAccessibleApplication
operator|::
name|text
parameter_list|(
name|Text
name|t
parameter_list|,
name|int
parameter_list|)
specifier|const
block|{
switch|switch
condition|(
name|t
condition|)
block|{
case|case
name|Name
case|:
if|if
condition|(
name|QApplication
operator|::
name|activeWindow
argument_list|()
condition|)
return|return
name|QApplication
operator|::
name|activeWindow
argument_list|()
operator|->
name|windowTitle
argument_list|()
return|;
break|break;
case|case
name|Description
case|:
return|return
name|QApplication
operator|::
name|applicationFilePath
argument_list|()
return|;
default|default:
break|break;
block|}
return|return
name|QString
argument_list|()
return|;
block|}
end_function
begin_comment
comment|/*! \reimp */
end_comment
begin_function
DECL|function|role
name|QAccessible
operator|::
name|Role
name|QAccessibleApplication
operator|::
name|role
parameter_list|(
name|int
parameter_list|)
specifier|const
block|{
return|return
name|Application
return|;
block|}
end_function
begin_comment
comment|/*! \reimp */
end_comment
begin_function
DECL|function|state
name|QAccessible
operator|::
name|State
name|QAccessibleApplication
operator|::
name|state
parameter_list|(
name|int
parameter_list|)
specifier|const
block|{
return|return
name|QApplication
operator|::
name|activeWindow
argument_list|()
condition|?
name|Focused
else|:
name|Normal
return|;
block|}
end_function
begin_comment
comment|/*! \reimp */
end_comment
begin_function
DECL|function|userActionCount
name|int
name|QAccessibleApplication
operator|::
name|userActionCount
parameter_list|(
name|int
parameter_list|)
specifier|const
block|{
return|return
literal|1
return|;
block|}
end_function
begin_comment
comment|/*! \reimp */
end_comment
begin_function
DECL|function|doAction
name|bool
name|QAccessibleApplication
operator|::
name|doAction
parameter_list|(
name|int
name|action
parameter_list|,
name|int
name|child
parameter_list|,
specifier|const
name|QVariantList
modifier|&
name|param
parameter_list|)
block|{
if|if
condition|(
name|action
operator|==
literal|0
operator|||
name|action
operator|==
literal|1
condition|)
block|{
name|QWidget
modifier|*
name|w
init|=
literal|0
decl_stmt|;
name|w
operator|=
name|QApplication
operator|::
name|activeWindow
argument_list|()
expr_stmt|;
if|if
condition|(
operator|!
name|w
condition|)
name|w
operator|=
name|topLevelWidgets
argument_list|()
operator|.
name|at
argument_list|(
literal|0
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|w
condition|)
return|return
literal|false
return|;
name|w
operator|->
name|activateWindow
argument_list|()
expr_stmt|;
return|return
literal|true
return|;
block|}
return|return
name|QAccessibleObject
operator|::
name|doAction
argument_list|(
name|action
argument_list|,
name|child
argument_list|,
name|param
argument_list|)
return|;
block|}
end_function
begin_comment
comment|/*! \reimp */
end_comment
begin_function
DECL|function|actionText
name|QString
name|QAccessibleApplication
operator|::
name|actionText
parameter_list|(
name|int
name|action
parameter_list|,
name|Text
name|text
parameter_list|,
name|int
name|child
parameter_list|)
specifier|const
block|{
name|QString
name|str
decl_stmt|;
if|if
condition|(
operator|(
name|action
operator|==
literal|0
operator|||
name|action
operator|==
literal|1
operator|)
operator|&&
operator|!
name|child
condition|)
switch|switch
condition|(
name|text
condition|)
block|{
case|case
name|Name
case|:
return|return
name|QApplication
operator|::
name|tr
argument_list|(
literal|"Activate"
argument_list|)
return|;
case|case
name|Description
case|:
return|return
name|QApplication
operator|::
name|tr
argument_list|(
literal|"Activates the program's main window"
argument_list|)
return|;
default|default:
break|break;
block|}
return|return
name|QAccessibleObject
operator|::
name|actionText
argument_list|(
name|action
argument_list|,
name|text
argument_list|,
name|child
argument_list|)
return|;
block|}
end_function
begin_comment
comment|// ### Qt 5: remove me - binary compatibility hack
end_comment
begin_constructor
DECL|function|QAccessibleObjectEx
name|QAccessibleObjectEx
operator|::
name|QAccessibleObjectEx
parameter_list|(
name|QObject
modifier|*
name|object
parameter_list|)
block|{
name|d
operator|=
operator|new
name|QAccessibleObjectPrivate
expr_stmt|;
name|d
operator|->
name|object
operator|=
name|object
expr_stmt|;
block|}
end_constructor
begin_function
DECL|function|isValid
name|bool
name|QAccessibleObjectEx
operator|::
name|isValid
parameter_list|()
specifier|const
block|{
return|return
cast|reinterpret_cast
argument_list|<
specifier|const
name|QAccessibleObject
operator|*
argument_list|>
argument_list|(
name|this
argument_list|)
operator|->
name|QAccessibleObject
operator|::
name|isValid
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|object
name|QObject
modifier|*
name|QAccessibleObjectEx
operator|::
name|object
parameter_list|()
specifier|const
block|{
return|return
cast|reinterpret_cast
argument_list|<
specifier|const
name|QAccessibleObject
operator|*
argument_list|>
argument_list|(
name|this
argument_list|)
operator|->
name|QAccessibleObject
operator|::
name|object
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|rect
name|QRect
name|QAccessibleObjectEx
operator|::
name|rect
parameter_list|(
name|int
name|child
parameter_list|)
specifier|const
block|{
return|return
cast|reinterpret_cast
argument_list|<
specifier|const
name|QAccessibleObject
operator|*
argument_list|>
argument_list|(
name|this
argument_list|)
operator|->
name|QAccessibleObject
operator|::
name|rect
argument_list|(
name|child
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|setText
name|void
name|QAccessibleObjectEx
operator|::
name|setText
parameter_list|(
name|Text
name|t
parameter_list|,
name|int
name|child
parameter_list|,
specifier|const
name|QString
modifier|&
name|text
parameter_list|)
block|{
cast|reinterpret_cast
argument_list|<
name|QAccessibleObject
operator|*
argument_list|>
argument_list|(
name|this
argument_list|)
operator|->
name|QAccessibleObject
operator|::
name|setText
argument_list|(
name|t
argument_list|,
name|child
argument_list|,
name|text
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|userActionCount
name|int
name|QAccessibleObjectEx
operator|::
name|userActionCount
parameter_list|(
name|int
name|child
parameter_list|)
specifier|const
block|{
return|return
cast|reinterpret_cast
argument_list|<
specifier|const
name|QAccessibleObject
operator|*
argument_list|>
argument_list|(
name|this
argument_list|)
operator|->
name|QAccessibleObject
operator|::
name|userActionCount
argument_list|(
name|child
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|doAction
name|bool
name|QAccessibleObjectEx
operator|::
name|doAction
parameter_list|(
name|int
name|action
parameter_list|,
name|int
name|child
parameter_list|,
specifier|const
name|QVariantList
modifier|&
name|params
parameter_list|)
block|{
return|return
cast|reinterpret_cast
argument_list|<
name|QAccessibleObject
operator|*
argument_list|>
argument_list|(
name|this
argument_list|)
operator|->
name|QAccessibleObject
operator|::
name|doAction
argument_list|(
name|action
argument_list|,
name|child
argument_list|,
name|params
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|actionText
name|QString
name|QAccessibleObjectEx
operator|::
name|actionText
parameter_list|(
name|int
name|action
parameter_list|,
name|Text
name|t
parameter_list|,
name|int
name|child
parameter_list|)
specifier|const
block|{
return|return
cast|reinterpret_cast
argument_list|<
specifier|const
name|QAccessibleObject
operator|*
argument_list|>
argument_list|(
name|this
argument_list|)
operator|->
name|QAccessibleObject
operator|::
name|actionText
argument_list|(
name|action
argument_list|,
name|t
argument_list|,
name|child
argument_list|)
return|;
block|}
end_function
begin_destructor
DECL|function|~QAccessibleObjectEx
name|QAccessibleObjectEx
operator|::
name|~
name|QAccessibleObjectEx
parameter_list|()
block|{
operator|delete
name|d
expr_stmt|;
block|}
end_destructor
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|//QT_NO_ACCESSIBILITY
end_comment
end_unit
