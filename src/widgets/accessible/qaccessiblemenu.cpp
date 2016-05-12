begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qaccessiblemenu_p.h"
end_include
begin_include
include|#
directive|include
file|<qmenu.h>
end_include
begin_include
include|#
directive|include
file|<qmenubar.h>
end_include
begin_include
include|#
directive|include
file|<QtWidgets/QAction>
end_include
begin_include
include|#
directive|include
file|<qstyle.h>
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_ACCESSIBILITY
end_ifndef
begin_function_decl
name|QT_BEGIN_NAMESPACE
ifndef|#
directive|ifndef
name|QT_NO_MENU
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
begin_function_decl
name|QString
name|qt_accHotKey
parameter_list|(
specifier|const
name|QString
modifier|&
name|text
parameter_list|)
function_decl|;
end_function_decl
begin_function
DECL|function|getOrCreateMenu
name|QAccessibleInterface
modifier|*
name|getOrCreateMenu
parameter_list|(
name|QWidget
modifier|*
name|menu
parameter_list|,
name|QAction
modifier|*
name|action
parameter_list|)
block|{
name|QAccessibleInterface
modifier|*
name|iface
init|=
name|QAccessible
operator|::
name|queryAccessibleInterface
argument_list|(
name|action
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|iface
condition|)
block|{
name|iface
operator|=
operator|new
name|QAccessibleMenuItem
argument_list|(
name|menu
argument_list|,
name|action
argument_list|)
expr_stmt|;
name|QAccessible
operator|::
name|registerAccessibleInterface
argument_list|(
name|iface
argument_list|)
expr_stmt|;
block|}
return|return
name|iface
return|;
block|}
end_function
begin_constructor
DECL|function|QAccessibleMenu
name|QAccessibleMenu
operator|::
name|QAccessibleMenu
parameter_list|(
name|QWidget
modifier|*
name|w
parameter_list|)
member_init_list|:
name|QAccessibleWidget
argument_list|(
name|w
argument_list|)
block|{
name|Q_ASSERT
argument_list|(
name|menu
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_function
DECL|function|menu
name|QMenu
modifier|*
name|QAccessibleMenu
operator|::
name|menu
parameter_list|()
specifier|const
block|{
return|return
name|qobject_cast
argument_list|<
name|QMenu
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
DECL|function|childCount
name|int
name|QAccessibleMenu
operator|::
name|childCount
parameter_list|()
specifier|const
block|{
return|return
name|menu
argument_list|()
operator|->
name|actions
argument_list|()
operator|.
name|count
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|childAt
name|QAccessibleInterface
modifier|*
name|QAccessibleMenu
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
name|QAction
modifier|*
name|act
init|=
name|menu
argument_list|()
operator|->
name|actionAt
argument_list|(
name|menu
argument_list|()
operator|->
name|mapFromGlobal
argument_list|(
name|QPoint
argument_list|(
name|x
argument_list|,
name|y
argument_list|)
argument_list|)
argument_list|)
decl_stmt|;
if|if
condition|(
name|act
operator|&&
name|act
operator|->
name|isSeparator
argument_list|()
condition|)
name|act
operator|=
literal|0
expr_stmt|;
return|return
name|act
condition|?
name|getOrCreateMenu
argument_list|(
name|menu
argument_list|()
argument_list|,
name|act
argument_list|)
else|:
literal|0
return|;
block|}
end_function
begin_function
DECL|function|text
name|QString
name|QAccessibleMenu
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
name|tx
init|=
name|QAccessibleWidget
operator|::
name|text
argument_list|(
name|t
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|tx
operator|.
name|isEmpty
argument_list|()
condition|)
return|return
name|tx
return|;
if|if
condition|(
name|t
operator|==
name|QAccessible
operator|::
name|Name
condition|)
return|return
name|menu
argument_list|()
operator|->
name|windowTitle
argument_list|()
return|;
return|return
name|tx
return|;
block|}
end_function
begin_function
DECL|function|role
name|QAccessible
operator|::
name|Role
name|QAccessibleMenu
operator|::
name|role
parameter_list|()
specifier|const
block|{
return|return
name|QAccessible
operator|::
name|PopupMenu
return|;
block|}
end_function
begin_function
DECL|function|child
name|QAccessibleInterface
modifier|*
name|QAccessibleMenu
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
operator|<
name|childCount
argument_list|()
condition|)
return|return
name|getOrCreateMenu
argument_list|(
name|menu
argument_list|()
argument_list|,
name|menu
argument_list|()
operator|->
name|actions
argument_list|()
operator|.
name|at
argument_list|(
name|index
argument_list|)
argument_list|)
return|;
return|return
literal|0
return|;
block|}
end_function
begin_function
DECL|function|parent
name|QAccessibleInterface
modifier|*
name|QAccessibleMenu
operator|::
name|parent
parameter_list|()
specifier|const
block|{
if|if
condition|(
name|QAction
modifier|*
name|menuAction
init|=
name|menu
argument_list|()
operator|->
name|menuAction
argument_list|()
condition|)
block|{
name|QList
argument_list|<
name|QWidget
modifier|*
argument_list|>
name|parentCandidates
decl_stmt|;
name|parentCandidates
operator|<<
name|menu
argument_list|()
operator|->
name|parentWidget
argument_list|()
expr_stmt|;
name|parentCandidates
operator|<<
name|menuAction
operator|->
name|associatedWidgets
argument_list|()
expr_stmt|;
foreach|foreach
control|(
name|QWidget
modifier|*
name|w
decl|,
name|parentCandidates
control|)
block|{
if|if
condition|(
name|qobject_cast
argument_list|<
name|QMenu
operator|*
argument_list|>
argument_list|(
name|w
argument_list|)
operator|||
name|qobject_cast
argument_list|<
name|QMenuBar
operator|*
argument_list|>
argument_list|(
name|w
argument_list|)
condition|)
block|{
if|if
condition|(
name|w
operator|->
name|actions
argument_list|()
operator|.
name|indexOf
argument_list|(
name|menuAction
argument_list|)
operator|!=
operator|-
literal|1
condition|)
return|return
name|getOrCreateMenu
argument_list|(
name|w
argument_list|,
name|menuAction
argument_list|)
return|;
block|}
block|}
block|}
return|return
name|QAccessibleWidget
operator|::
name|parent
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|indexOfChild
name|int
name|QAccessibleMenu
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
name|QAccessible
operator|::
name|Role
name|r
init|=
name|child
operator|->
name|role
argument_list|()
decl_stmt|;
if|if
condition|(
operator|(
name|r
operator|==
name|QAccessible
operator|::
name|MenuItem
operator|||
name|r
operator|==
name|QAccessible
operator|::
name|Separator
operator|)
operator|&&
name|menu
argument_list|()
condition|)
block|{
return|return
name|menu
argument_list|()
operator|->
name|actions
argument_list|()
operator|.
name|indexOf
argument_list|(
name|qobject_cast
argument_list|<
name|QAction
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
return|return
operator|-
literal|1
return|;
block|}
end_function
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_MENUBAR
end_ifndef
begin_constructor
DECL|function|QAccessibleMenuBar
name|QAccessibleMenuBar
operator|::
name|QAccessibleMenuBar
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
name|MenuBar
argument_list|)
block|{
name|Q_ASSERT
argument_list|(
name|menuBar
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_function
DECL|function|menuBar
name|QMenuBar
modifier|*
name|QAccessibleMenuBar
operator|::
name|menuBar
parameter_list|()
specifier|const
block|{
return|return
name|qobject_cast
argument_list|<
name|QMenuBar
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
DECL|function|childCount
name|int
name|QAccessibleMenuBar
operator|::
name|childCount
parameter_list|()
specifier|const
block|{
return|return
name|menuBar
argument_list|()
operator|->
name|actions
argument_list|()
operator|.
name|count
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|child
name|QAccessibleInterface
modifier|*
name|QAccessibleMenuBar
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
operator|<
name|childCount
argument_list|()
condition|)
block|{
return|return
name|getOrCreateMenu
argument_list|(
name|menuBar
argument_list|()
argument_list|,
name|menuBar
argument_list|()
operator|->
name|actions
argument_list|()
operator|.
name|at
argument_list|(
name|index
argument_list|)
argument_list|)
return|;
block|}
return|return
literal|0
return|;
block|}
end_function
begin_function
DECL|function|indexOfChild
name|int
name|QAccessibleMenuBar
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
name|QAccessible
operator|::
name|Role
name|r
init|=
name|child
operator|->
name|role
argument_list|()
decl_stmt|;
if|if
condition|(
operator|(
name|r
operator|==
name|QAccessible
operator|::
name|MenuItem
operator|||
name|r
operator|==
name|QAccessible
operator|::
name|Separator
operator|)
operator|&&
name|menuBar
argument_list|()
condition|)
block|{
return|return
name|menuBar
argument_list|()
operator|->
name|actions
argument_list|()
operator|.
name|indexOf
argument_list|(
name|qobject_cast
argument_list|<
name|QAction
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
return|return
operator|-
literal|1
return|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_MENUBAR
end_comment
begin_constructor
DECL|function|QAccessibleMenuItem
name|QAccessibleMenuItem
operator|::
name|QAccessibleMenuItem
parameter_list|(
name|QWidget
modifier|*
name|owner
parameter_list|,
name|QAction
modifier|*
name|action
parameter_list|)
member_init_list|:
name|m_action
argument_list|(
name|action
argument_list|)
member_init_list|,
name|m_owner
argument_list|(
name|owner
argument_list|)
block|{ }
end_constructor
begin_destructor
DECL|function|~QAccessibleMenuItem
name|QAccessibleMenuItem
operator|::
name|~
name|QAccessibleMenuItem
parameter_list|()
block|{}
end_destructor
begin_function
DECL|function|childAt
name|QAccessibleInterface
modifier|*
name|QAccessibleMenuItem
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
for|for
control|(
name|int
name|i
init|=
name|childCount
argument_list|()
operator|-
literal|1
init|;
name|i
operator|>=
literal|0
condition|;
operator|--
name|i
control|)
block|{
name|QAccessibleInterface
modifier|*
name|childInterface
init|=
name|child
argument_list|(
name|i
argument_list|)
decl_stmt|;
if|if
condition|(
name|childInterface
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
block|{
return|return
name|childInterface
return|;
block|}
block|}
return|return
literal|0
return|;
block|}
end_function
begin_function
DECL|function|childCount
name|int
name|QAccessibleMenuItem
operator|::
name|childCount
parameter_list|()
specifier|const
block|{
return|return
name|m_action
operator|->
name|menu
argument_list|()
condition|?
literal|1
else|:
literal|0
return|;
block|}
end_function
begin_function
DECL|function|indexOfChild
name|int
name|QAccessibleMenuItem
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
operator|&&
name|child
operator|->
name|role
argument_list|()
operator|==
name|QAccessible
operator|::
name|PopupMenu
operator|&&
name|child
operator|->
name|object
argument_list|()
operator|==
name|m_action
operator|->
name|menu
argument_list|()
condition|)
return|return
literal|0
return|;
return|return
operator|-
literal|1
return|;
block|}
end_function
begin_function
DECL|function|isValid
name|bool
name|QAccessibleMenuItem
operator|::
name|isValid
parameter_list|()
specifier|const
block|{
return|return
name|m_action
operator|&&
name|m_owner
return|;
block|}
end_function
begin_function
DECL|function|parent
name|QAccessibleInterface
modifier|*
name|QAccessibleMenuItem
operator|::
name|parent
parameter_list|()
specifier|const
block|{
return|return
name|QAccessible
operator|::
name|queryAccessibleInterface
argument_list|(
name|owner
argument_list|()
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|child
name|QAccessibleInterface
modifier|*
name|QAccessibleMenuItem
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
operator|&&
name|action
argument_list|()
operator|->
name|menu
argument_list|()
condition|)
return|return
name|QAccessible
operator|::
name|queryAccessibleInterface
argument_list|(
name|action
argument_list|()
operator|->
name|menu
argument_list|()
argument_list|)
return|;
return|return
literal|0
return|;
block|}
end_function
begin_function
DECL|function|interface_cast
name|void
modifier|*
name|QAccessibleMenuItem
operator|::
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
return|return
literal|0
return|;
block|}
end_function
begin_function
DECL|function|object
name|QObject
modifier|*
name|QAccessibleMenuItem
operator|::
name|object
parameter_list|()
specifier|const
block|{
return|return
name|m_action
return|;
block|}
end_function
begin_comment
comment|/*! \reimp */
end_comment
begin_function
DECL|function|window
name|QWindow
modifier|*
name|QAccessibleMenuItem
operator|::
name|window
parameter_list|()
specifier|const
block|{
name|QWindow
modifier|*
name|result
init|=
name|Q_NULLPTR
decl_stmt|;
if|if
condition|(
operator|!
name|m_owner
operator|.
name|isNull
argument_list|()
condition|)
block|{
name|result
operator|=
name|m_owner
operator|->
name|windowHandle
argument_list|()
expr_stmt|;
if|if
condition|(
operator|!
name|result
condition|)
block|{
if|if
condition|(
specifier|const
name|QWidget
modifier|*
name|nativeParent
init|=
name|m_owner
operator|->
name|nativeParentWidget
argument_list|()
condition|)
name|result
operator|=
name|nativeParent
operator|->
name|windowHandle
argument_list|()
expr_stmt|;
block|}
block|}
return|return
name|result
return|;
block|}
end_function
begin_function
DECL|function|rect
name|QRect
name|QAccessibleMenuItem
operator|::
name|rect
parameter_list|()
specifier|const
block|{
name|QRect
name|rect
decl_stmt|;
name|QWidget
modifier|*
name|own
init|=
name|owner
argument_list|()
decl_stmt|;
ifndef|#
directive|ifndef
name|QT_NO_MENUBAR
if|if
condition|(
name|QMenuBar
modifier|*
name|menuBar
init|=
name|qobject_cast
argument_list|<
name|QMenuBar
operator|*
argument_list|>
argument_list|(
name|own
argument_list|)
condition|)
block|{
name|rect
operator|=
name|menuBar
operator|->
name|actionGeometry
argument_list|(
name|m_action
argument_list|)
expr_stmt|;
name|QPoint
name|globalPos
init|=
name|menuBar
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
name|rect
operator|=
name|rect
operator|.
name|translated
argument_list|(
name|globalPos
argument_list|)
expr_stmt|;
block|}
elseif|else
endif|#
directive|endif
comment|// QT_NO_MENUBAR
if|if
condition|(
name|QMenu
modifier|*
name|menu
init|=
name|qobject_cast
argument_list|<
name|QMenu
operator|*
argument_list|>
argument_list|(
name|own
argument_list|)
condition|)
block|{
name|rect
operator|=
name|menu
operator|->
name|actionGeometry
argument_list|(
name|m_action
argument_list|)
expr_stmt|;
name|QPoint
name|globalPos
init|=
name|menu
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
name|rect
operator|=
name|rect
operator|.
name|translated
argument_list|(
name|globalPos
argument_list|)
expr_stmt|;
block|}
return|return
name|rect
return|;
block|}
end_function
begin_function
DECL|function|role
name|QAccessible
operator|::
name|Role
name|QAccessibleMenuItem
operator|::
name|role
parameter_list|()
specifier|const
block|{
return|return
name|m_action
operator|->
name|isSeparator
argument_list|()
condition|?
name|QAccessible
operator|::
name|Separator
else|:
name|QAccessible
operator|::
name|MenuItem
return|;
block|}
end_function
begin_function
DECL|function|setText
name|void
name|QAccessibleMenuItem
operator|::
name|setText
parameter_list|(
name|QAccessible
operator|::
name|Text
comment|/*t*/
parameter_list|,
specifier|const
name|QString
modifier|&
comment|/*text */
parameter_list|)
block|{ }
end_function
begin_function
DECL|function|state
name|QAccessible
operator|::
name|State
name|QAccessibleMenuItem
operator|::
name|state
parameter_list|()
specifier|const
block|{
name|QAccessible
operator|::
name|State
name|s
decl_stmt|;
name|QWidget
modifier|*
name|own
init|=
name|owner
argument_list|()
decl_stmt|;
if|if
condition|(
name|own
operator|&&
operator|(
name|own
operator|->
name|testAttribute
argument_list|(
name|Qt
operator|::
name|WA_WState_Visible
argument_list|)
operator|==
literal|false
operator|||
name|m_action
operator|->
name|isVisible
argument_list|()
operator|==
literal|false
operator|)
condition|)
block|{
name|s
operator|.
name|invisible
operator|=
literal|true
expr_stmt|;
block|}
if|if
condition|(
name|QMenu
modifier|*
name|menu
init|=
name|qobject_cast
argument_list|<
name|QMenu
operator|*
argument_list|>
argument_list|(
name|own
argument_list|)
condition|)
block|{
if|if
condition|(
name|menu
operator|->
name|activeAction
argument_list|()
operator|==
name|m_action
condition|)
name|s
operator|.
name|focused
operator|=
literal|true
expr_stmt|;
ifndef|#
directive|ifndef
name|QT_NO_MENUBAR
block|}
elseif|else
if|if
condition|(
name|QMenuBar
modifier|*
name|menuBar
init|=
name|qobject_cast
argument_list|<
name|QMenuBar
operator|*
argument_list|>
argument_list|(
name|own
argument_list|)
condition|)
block|{
if|if
condition|(
name|menuBar
operator|->
name|activeAction
argument_list|()
operator|==
name|m_action
condition|)
name|s
operator|.
name|focused
operator|=
literal|true
expr_stmt|;
endif|#
directive|endif
block|}
if|if
condition|(
name|own
operator|&&
name|own
operator|->
name|style
argument_list|()
operator|->
name|styleHint
argument_list|(
name|QStyle
operator|::
name|SH_Menu_MouseTracking
argument_list|)
condition|)
name|s
operator|.
name|hotTracked
operator|=
literal|true
expr_stmt|;
if|if
condition|(
name|m_action
operator|->
name|isSeparator
argument_list|()
operator|||
operator|!
name|m_action
operator|->
name|isEnabled
argument_list|()
condition|)
name|s
operator|.
name|disabled
operator|=
literal|true
expr_stmt|;
if|if
condition|(
name|m_action
operator|->
name|isChecked
argument_list|()
condition|)
name|s
operator|.
name|checked
operator|=
literal|true
expr_stmt|;
return|return
name|s
return|;
block|}
end_function
begin_function
DECL|function|text
name|QString
name|QAccessibleMenuItem
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
name|str
operator|=
name|qt_accStripAmp
argument_list|(
name|m_action
operator|->
name|text
argument_list|()
argument_list|)
expr_stmt|;
break|break;
case|case
name|QAccessible
operator|::
name|Accelerator
case|:
block|{
ifndef|#
directive|ifndef
name|QT_NO_SHORTCUT
name|QKeySequence
name|key
init|=
name|m_action
operator|->
name|shortcut
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
name|key
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|str
operator|=
name|key
operator|.
name|toString
argument_list|()
expr_stmt|;
block|}
else|else
endif|#
directive|endif
block|{
name|str
operator|=
name|qt_accHotKey
argument_list|(
name|m_action
operator|->
name|text
argument_list|()
argument_list|)
expr_stmt|;
block|}
break|break;
block|}
default|default:
break|break;
block|}
return|return
name|str
return|;
block|}
end_function
begin_function
DECL|function|actionNames
name|QStringList
name|QAccessibleMenuItem
operator|::
name|actionNames
parameter_list|()
specifier|const
block|{
name|QStringList
name|actions
decl_stmt|;
if|if
condition|(
operator|!
name|m_action
operator|||
name|m_action
operator|->
name|isSeparator
argument_list|()
condition|)
return|return
name|actions
return|;
if|if
condition|(
name|m_action
operator|->
name|menu
argument_list|()
condition|)
block|{
name|actions
operator|<<
name|showMenuAction
argument_list|()
expr_stmt|;
block|}
else|else
block|{
name|actions
operator|<<
name|pressAction
argument_list|()
expr_stmt|;
block|}
return|return
name|actions
return|;
block|}
end_function
begin_function
DECL|function|doAction
name|void
name|QAccessibleMenuItem
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
operator|!
name|m_action
operator|->
name|isEnabled
argument_list|()
condition|)
return|return;
if|if
condition|(
name|actionName
operator|==
name|pressAction
argument_list|()
condition|)
block|{
name|m_action
operator|->
name|trigger
argument_list|()
expr_stmt|;
block|}
elseif|else
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
name|QMenuBar
modifier|*
name|bar
init|=
name|qobject_cast
argument_list|<
name|QMenuBar
operator|*
argument_list|>
argument_list|(
name|owner
argument_list|()
argument_list|)
condition|)
block|{
if|if
condition|(
name|m_action
operator|->
name|menu
argument_list|()
operator|&&
name|m_action
operator|->
name|menu
argument_list|()
operator|->
name|isVisible
argument_list|()
condition|)
block|{
name|m_action
operator|->
name|menu
argument_list|()
operator|->
name|hide
argument_list|()
expr_stmt|;
block|}
else|else
block|{
name|bar
operator|->
name|setActiveAction
argument_list|(
name|m_action
argument_list|)
expr_stmt|;
block|}
block|}
elseif|else
if|if
condition|(
name|QMenu
modifier|*
name|menu
init|=
name|qobject_cast
argument_list|<
name|QMenu
operator|*
argument_list|>
argument_list|(
name|owner
argument_list|()
argument_list|)
condition|)
block|{
if|if
condition|(
name|m_action
operator|->
name|menu
argument_list|()
operator|&&
name|m_action
operator|->
name|menu
argument_list|()
operator|->
name|isVisible
argument_list|()
condition|)
block|{
name|m_action
operator|->
name|menu
argument_list|()
operator|->
name|hide
argument_list|()
expr_stmt|;
block|}
else|else
block|{
name|menu
operator|->
name|setActiveAction
argument_list|(
name|m_action
argument_list|)
expr_stmt|;
block|}
block|}
block|}
block|}
end_function
begin_function
DECL|function|keyBindingsForAction
name|QStringList
name|QAccessibleMenuItem
operator|::
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
end_function
begin_function
DECL|function|action
name|QAction
modifier|*
name|QAccessibleMenuItem
operator|::
name|action
parameter_list|()
specifier|const
block|{
return|return
name|m_action
return|;
block|}
end_function
begin_function
DECL|function|owner
name|QWidget
modifier|*
name|QAccessibleMenuItem
operator|::
name|owner
parameter_list|()
specifier|const
block|{
return|return
name|m_owner
return|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_MENU
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
