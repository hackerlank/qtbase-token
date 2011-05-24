begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qundostack.h"
end_include
begin_include
include|#
directive|include
file|"qundoview.h"
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_UNDOVIEW
end_ifndef
begin_include
include|#
directive|include
file|"qundogroup.h"
end_include
begin_include
include|#
directive|include
file|<QtCore/qabstractitemmodel.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qpointer.h>
end_include
begin_include
include|#
directive|include
file|<QtWidgets/qicon.h>
end_include
begin_include
include|#
directive|include
file|<private/qlistview_p.h>
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_class
DECL|class|QUndoModel
class|class
name|QUndoModel
super|:
specifier|public
name|QAbstractItemModel
block|{
name|Q_OBJECT
public|public:
name|QUndoModel
parameter_list|(
name|QObject
modifier|*
name|parent
init|=
literal|0
parameter_list|)
constructor_decl|;
name|QUndoStack
modifier|*
name|stack
parameter_list|()
specifier|const
function_decl|;
specifier|virtual
name|QModelIndex
name|index
parameter_list|(
name|int
name|row
parameter_list|,
name|int
name|column
parameter_list|,
specifier|const
name|QModelIndex
modifier|&
name|parent
init|=
name|QModelIndex
argument_list|()
parameter_list|)
specifier|const
function_decl|;
specifier|virtual
name|QModelIndex
name|parent
parameter_list|(
specifier|const
name|QModelIndex
modifier|&
name|child
parameter_list|)
specifier|const
function_decl|;
specifier|virtual
name|int
name|rowCount
parameter_list|(
specifier|const
name|QModelIndex
modifier|&
name|parent
init|=
name|QModelIndex
argument_list|()
parameter_list|)
specifier|const
function_decl|;
specifier|virtual
name|int
name|columnCount
parameter_list|(
specifier|const
name|QModelIndex
modifier|&
name|parent
init|=
name|QModelIndex
argument_list|()
parameter_list|)
specifier|const
function_decl|;
specifier|virtual
name|QVariant
name|data
parameter_list|(
specifier|const
name|QModelIndex
modifier|&
name|index
parameter_list|,
name|int
name|role
init|=
name|Qt
operator|::
name|DisplayRole
parameter_list|)
specifier|const
function_decl|;
name|QModelIndex
name|selectedIndex
parameter_list|()
specifier|const
function_decl|;
name|QItemSelectionModel
modifier|*
name|selectionModel
parameter_list|()
specifier|const
function_decl|;
name|QString
name|emptyLabel
parameter_list|()
specifier|const
function_decl|;
name|void
name|setEmptyLabel
parameter_list|(
specifier|const
name|QString
modifier|&
name|label
parameter_list|)
function_decl|;
name|void
name|setCleanIcon
parameter_list|(
specifier|const
name|QIcon
modifier|&
name|icon
parameter_list|)
function_decl|;
name|QIcon
name|cleanIcon
parameter_list|()
specifier|const
function_decl|;
public|public
name|slots
public|:
name|void
name|setStack
parameter_list|(
name|QUndoStack
modifier|*
name|stack
parameter_list|)
function_decl|;
private|private
name|slots
private|:
name|void
name|stackChanged
parameter_list|()
function_decl|;
name|void
name|stackDestroyed
parameter_list|(
name|QObject
modifier|*
name|obj
parameter_list|)
function_decl|;
name|void
name|setStackCurrentIndex
parameter_list|(
specifier|const
name|QModelIndex
modifier|&
name|index
parameter_list|)
function_decl|;
private|private:
DECL|member|m_stack
name|QUndoStack
modifier|*
name|m_stack
decl_stmt|;
DECL|member|m_sel_model
name|QItemSelectionModel
modifier|*
name|m_sel_model
decl_stmt|;
DECL|member|m_emty_label
name|QString
name|m_emty_label
decl_stmt|;
DECL|member|m_clean_icon
name|QIcon
name|m_clean_icon
decl_stmt|;
block|}
class|;
end_class
begin_constructor
DECL|function|QUndoModel
name|QUndoModel
operator|::
name|QUndoModel
parameter_list|(
name|QObject
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QAbstractItemModel
argument_list|(
name|parent
argument_list|)
block|{
name|m_stack
operator|=
literal|0
expr_stmt|;
name|m_sel_model
operator|=
operator|new
name|QItemSelectionModel
argument_list|(
name|this
argument_list|,
name|this
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|m_sel_model
argument_list|,
name|SIGNAL
argument_list|(
name|currentChanged
argument_list|(
name|QModelIndex
argument_list|,
name|QModelIndex
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|setStackCurrentIndex
argument_list|(
name|QModelIndex
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|m_emty_label
operator|=
name|tr
argument_list|(
literal|"<empty>"
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_function
DECL|function|selectionModel
name|QItemSelectionModel
modifier|*
name|QUndoModel
operator|::
name|selectionModel
parameter_list|()
specifier|const
block|{
return|return
name|m_sel_model
return|;
block|}
end_function
begin_function
DECL|function|stack
name|QUndoStack
modifier|*
name|QUndoModel
operator|::
name|stack
parameter_list|()
specifier|const
block|{
return|return
name|m_stack
return|;
block|}
end_function
begin_function
DECL|function|setStack
name|void
name|QUndoModel
operator|::
name|setStack
parameter_list|(
name|QUndoStack
modifier|*
name|stack
parameter_list|)
block|{
if|if
condition|(
name|m_stack
operator|==
name|stack
condition|)
return|return;
if|if
condition|(
name|m_stack
operator|!=
literal|0
condition|)
block|{
name|disconnect
argument_list|(
name|m_stack
argument_list|,
name|SIGNAL
argument_list|(
name|cleanChanged
argument_list|(
name|bool
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|stackChanged
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|disconnect
argument_list|(
name|m_stack
argument_list|,
name|SIGNAL
argument_list|(
name|indexChanged
argument_list|(
name|int
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|stackChanged
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|disconnect
argument_list|(
name|m_stack
argument_list|,
name|SIGNAL
argument_list|(
name|destroyed
argument_list|(
name|QObject
operator|*
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|stackDestroyed
argument_list|(
name|QObject
operator|*
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
block|}
name|m_stack
operator|=
name|stack
expr_stmt|;
if|if
condition|(
name|m_stack
operator|!=
literal|0
condition|)
block|{
name|connect
argument_list|(
name|m_stack
argument_list|,
name|SIGNAL
argument_list|(
name|cleanChanged
argument_list|(
name|bool
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|stackChanged
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|m_stack
argument_list|,
name|SIGNAL
argument_list|(
name|indexChanged
argument_list|(
name|int
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|stackChanged
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|m_stack
argument_list|,
name|SIGNAL
argument_list|(
name|destroyed
argument_list|(
name|QObject
operator|*
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|stackDestroyed
argument_list|(
name|QObject
operator|*
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
block|}
name|stackChanged
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|stackDestroyed
name|void
name|QUndoModel
operator|::
name|stackDestroyed
parameter_list|(
name|QObject
modifier|*
name|obj
parameter_list|)
block|{
if|if
condition|(
name|obj
operator|!=
name|m_stack
condition|)
return|return;
name|m_stack
operator|=
literal|0
expr_stmt|;
name|stackChanged
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|stackChanged
name|void
name|QUndoModel
operator|::
name|stackChanged
parameter_list|()
block|{
name|reset
argument_list|()
expr_stmt|;
name|m_sel_model
operator|->
name|setCurrentIndex
argument_list|(
name|selectedIndex
argument_list|()
argument_list|,
name|QItemSelectionModel
operator|::
name|ClearAndSelect
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|setStackCurrentIndex
name|void
name|QUndoModel
operator|::
name|setStackCurrentIndex
parameter_list|(
specifier|const
name|QModelIndex
modifier|&
name|index
parameter_list|)
block|{
if|if
condition|(
name|m_stack
operator|==
literal|0
condition|)
return|return;
if|if
condition|(
name|index
operator|==
name|selectedIndex
argument_list|()
condition|)
return|return;
if|if
condition|(
name|index
operator|.
name|column
argument_list|()
operator|!=
literal|0
condition|)
return|return;
name|m_stack
operator|->
name|setIndex
argument_list|(
name|index
operator|.
name|row
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|selectedIndex
name|QModelIndex
name|QUndoModel
operator|::
name|selectedIndex
parameter_list|()
specifier|const
block|{
return|return
name|m_stack
operator|==
literal|0
condition|?
name|QModelIndex
argument_list|()
else|:
name|createIndex
argument_list|(
name|m_stack
operator|->
name|index
argument_list|()
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|index
name|QModelIndex
name|QUndoModel
operator|::
name|index
parameter_list|(
name|int
name|row
parameter_list|,
name|int
name|column
parameter_list|,
specifier|const
name|QModelIndex
modifier|&
name|parent
parameter_list|)
specifier|const
block|{
if|if
condition|(
name|m_stack
operator|==
literal|0
condition|)
return|return
name|QModelIndex
argument_list|()
return|;
if|if
condition|(
name|parent
operator|.
name|isValid
argument_list|()
condition|)
return|return
name|QModelIndex
argument_list|()
return|;
if|if
condition|(
name|column
operator|!=
literal|0
condition|)
return|return
name|QModelIndex
argument_list|()
return|;
if|if
condition|(
name|row
argument_list|<
literal|0
operator|||
name|row
argument_list|>
name|m_stack
operator|->
name|count
argument_list|()
condition|)
return|return
name|QModelIndex
argument_list|()
return|;
return|return
name|createIndex
argument_list|(
name|row
argument_list|,
name|column
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|parent
name|QModelIndex
name|QUndoModel
operator|::
name|parent
parameter_list|(
specifier|const
name|QModelIndex
modifier|&
parameter_list|)
specifier|const
block|{
return|return
name|QModelIndex
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|rowCount
name|int
name|QUndoModel
operator|::
name|rowCount
parameter_list|(
specifier|const
name|QModelIndex
modifier|&
name|parent
parameter_list|)
specifier|const
block|{
if|if
condition|(
name|m_stack
operator|==
literal|0
condition|)
return|return
literal|0
return|;
if|if
condition|(
name|parent
operator|.
name|isValid
argument_list|()
condition|)
return|return
literal|0
return|;
return|return
name|m_stack
operator|->
name|count
argument_list|()
operator|+
literal|1
return|;
block|}
end_function
begin_function
DECL|function|columnCount
name|int
name|QUndoModel
operator|::
name|columnCount
parameter_list|(
specifier|const
name|QModelIndex
modifier|&
parameter_list|)
specifier|const
block|{
return|return
literal|1
return|;
block|}
end_function
begin_function
DECL|function|data
name|QVariant
name|QUndoModel
operator|::
name|data
parameter_list|(
specifier|const
name|QModelIndex
modifier|&
name|index
parameter_list|,
name|int
name|role
parameter_list|)
specifier|const
block|{
if|if
condition|(
name|m_stack
operator|==
literal|0
condition|)
return|return
name|QVariant
argument_list|()
return|;
if|if
condition|(
name|index
operator|.
name|column
argument_list|()
operator|!=
literal|0
condition|)
return|return
name|QVariant
argument_list|()
return|;
if|if
condition|(
name|index
operator|.
name|row
argument_list|()
operator|<
literal|0
operator|||
name|index
operator|.
name|row
argument_list|()
operator|>
name|m_stack
operator|->
name|count
argument_list|()
condition|)
return|return
name|QVariant
argument_list|()
return|;
if|if
condition|(
name|role
operator|==
name|Qt
operator|::
name|DisplayRole
condition|)
block|{
if|if
condition|(
name|index
operator|.
name|row
argument_list|()
operator|==
literal|0
condition|)
return|return
name|m_emty_label
return|;
return|return
name|m_stack
operator|->
name|text
argument_list|(
name|index
operator|.
name|row
argument_list|()
operator|-
literal|1
argument_list|)
return|;
block|}
elseif|else
if|if
condition|(
name|role
operator|==
name|Qt
operator|::
name|DecorationRole
condition|)
block|{
if|if
condition|(
name|index
operator|.
name|row
argument_list|()
operator|==
name|m_stack
operator|->
name|cleanIndex
argument_list|()
operator|&&
operator|!
name|m_clean_icon
operator|.
name|isNull
argument_list|()
condition|)
return|return
name|m_clean_icon
return|;
return|return
name|QVariant
argument_list|()
return|;
block|}
return|return
name|QVariant
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|emptyLabel
name|QString
name|QUndoModel
operator|::
name|emptyLabel
parameter_list|()
specifier|const
block|{
return|return
name|m_emty_label
return|;
block|}
end_function
begin_function
DECL|function|setEmptyLabel
name|void
name|QUndoModel
operator|::
name|setEmptyLabel
parameter_list|(
specifier|const
name|QString
modifier|&
name|label
parameter_list|)
block|{
name|m_emty_label
operator|=
name|label
expr_stmt|;
name|stackChanged
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|setCleanIcon
name|void
name|QUndoModel
operator|::
name|setCleanIcon
parameter_list|(
specifier|const
name|QIcon
modifier|&
name|icon
parameter_list|)
block|{
name|m_clean_icon
operator|=
name|icon
expr_stmt|;
name|stackChanged
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|cleanIcon
name|QIcon
name|QUndoModel
operator|::
name|cleanIcon
parameter_list|()
specifier|const
block|{
return|return
name|m_clean_icon
return|;
block|}
end_function
begin_comment
comment|/*!     \class QUndoView     \brief The QUndoView class displays the contents of a QUndoStack.     \since 4.2      \ingroup advanced      QUndoView is a QListView which displays the list of commands pushed on an undo stack.     The most recently executed command is always selected. Selecting a different command     results in a call to QUndoStack::setIndex(), rolling the state of the document     backwards or forward to the new command.      The stack can be set explicitly with setStack(). Alternatively, a QUndoGroup object can     be set with setGroup(). The view will then update itself automatically whenever the     active stack of the group changes.      \image qundoview.png */
end_comment
begin_class
DECL|class|QUndoViewPrivate
class|class
name|QUndoViewPrivate
super|:
specifier|public
name|QListViewPrivate
block|{
name|Q_DECLARE_PUBLIC
parameter_list|(
name|QUndoView
parameter_list|)
specifier|public
private|:
DECL|function|QUndoViewPrivate
name|QUndoViewPrivate
parameter_list|()
member_init_list|:
ifndef|#
directive|ifndef
name|QT_NO_UNDOGROUP
name|group
argument_list|(
literal|0
argument_list|)
member_init_list|,
endif|#
directive|endif
name|model
argument_list|(
literal|0
argument_list|)
block|{}
ifndef|#
directive|ifndef
name|QT_NO_UNDOGROUP
DECL|member|group
name|QPointer
argument_list|<
name|QUndoGroup
argument_list|>
name|group
decl_stmt|;
endif|#
directive|endif
DECL|member|model
name|QUndoModel
modifier|*
name|model
decl_stmt|;
name|void
name|init
parameter_list|()
function_decl|;
block|}
class|;
end_class
begin_function
DECL|function|init
name|void
name|QUndoViewPrivate
operator|::
name|init
parameter_list|()
block|{
name|Q_Q
argument_list|(
name|QUndoView
argument_list|)
expr_stmt|;
name|model
operator|=
operator|new
name|QUndoModel
argument_list|(
name|q
argument_list|)
expr_stmt|;
name|q
operator|->
name|setModel
argument_list|(
name|model
argument_list|)
expr_stmt|;
name|q
operator|->
name|setSelectionModel
argument_list|(
name|model
operator|->
name|selectionModel
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     Constructs a new view with parent \a parent. */
end_comment
begin_constructor
DECL|function|QUndoView
name|QUndoView
operator|::
name|QUndoView
parameter_list|(
name|QWidget
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QListView
argument_list|(
operator|*
operator|new
name|QUndoViewPrivate
argument_list|()
argument_list|,
name|parent
argument_list|)
block|{
name|Q_D
argument_list|(
name|QUndoView
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
comment|/*!     Constructs a new view with parent \a parent and sets the observed stack to \a stack. */
end_comment
begin_constructor
DECL|function|QUndoView
name|QUndoView
operator|::
name|QUndoView
parameter_list|(
name|QUndoStack
modifier|*
name|stack
parameter_list|,
name|QWidget
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QListView
argument_list|(
operator|*
operator|new
name|QUndoViewPrivate
argument_list|()
argument_list|,
name|parent
argument_list|)
block|{
name|Q_D
argument_list|(
name|QUndoView
argument_list|)
expr_stmt|;
name|d
operator|->
name|init
argument_list|()
expr_stmt|;
name|setStack
argument_list|(
name|stack
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_UNDOGROUP
end_ifndef
begin_comment
comment|/*!     Constructs a new view with parent \a parent and sets the observed group to \a group.      The view will update itself autmiatically whenever the active stack of the group changes. */
end_comment
begin_constructor
DECL|function|QUndoView
name|QUndoView
operator|::
name|QUndoView
parameter_list|(
name|QUndoGroup
modifier|*
name|group
parameter_list|,
name|QWidget
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QListView
argument_list|(
operator|*
operator|new
name|QUndoViewPrivate
argument_list|()
argument_list|,
name|parent
argument_list|)
block|{
name|Q_D
argument_list|(
name|QUndoView
argument_list|)
expr_stmt|;
name|d
operator|->
name|init
argument_list|()
expr_stmt|;
name|setGroup
argument_list|(
name|group
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_UNDOGROUP
end_comment
begin_comment
comment|/*!     Destroys this view. */
end_comment
begin_destructor
DECL|function|~QUndoView
name|QUndoView
operator|::
name|~
name|QUndoView
parameter_list|()
block|{ }
end_destructor
begin_comment
comment|/*!     Returns the stack currently displayed by this view. If the view is looking at a     QUndoGroup, this the group's active stack.      \sa setStack() setGroup() */
end_comment
begin_function
DECL|function|stack
name|QUndoStack
modifier|*
name|QUndoView
operator|::
name|stack
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QUndoView
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|model
operator|->
name|stack
argument_list|()
return|;
block|}
end_function
begin_comment
comment|/*!     Sets the stack displayed by this view to \a stack. If \a stack is 0, the view     will be empty.      If the view was previously looking at a QUndoGroup, the group is set to 0.      \sa stack() setGroup() */
end_comment
begin_function
DECL|function|setStack
name|void
name|QUndoView
operator|::
name|setStack
parameter_list|(
name|QUndoStack
modifier|*
name|stack
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QUndoView
argument_list|)
expr_stmt|;
ifndef|#
directive|ifndef
name|QT_NO_UNDOGROUP
name|setGroup
argument_list|(
literal|0
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|d
operator|->
name|model
operator|->
name|setStack
argument_list|(
name|stack
argument_list|)
expr_stmt|;
block|}
end_function
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_UNDOGROUP
end_ifndef
begin_comment
comment|/*!     Sets the group displayed by this view to \a group. If \a group is 0, the view will     be empty.      The view will update itself autmiatically whenever the active stack of the group changes.      \sa group() setStack() */
end_comment
begin_function
DECL|function|setGroup
name|void
name|QUndoView
operator|::
name|setGroup
parameter_list|(
name|QUndoGroup
modifier|*
name|group
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QUndoView
argument_list|)
expr_stmt|;
if|if
condition|(
name|d
operator|->
name|group
operator|==
name|group
condition|)
return|return;
if|if
condition|(
name|d
operator|->
name|group
operator|!=
literal|0
condition|)
block|{
name|disconnect
argument_list|(
name|d
operator|->
name|group
argument_list|,
name|SIGNAL
argument_list|(
name|activeStackChanged
argument_list|(
name|QUndoStack
operator|*
argument_list|)
argument_list|)
argument_list|,
name|d
operator|->
name|model
argument_list|,
name|SLOT
argument_list|(
name|setStack
argument_list|(
name|QUndoStack
operator|*
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
block|}
name|d
operator|->
name|group
operator|=
name|group
expr_stmt|;
if|if
condition|(
name|d
operator|->
name|group
operator|!=
literal|0
condition|)
block|{
name|connect
argument_list|(
name|d
operator|->
name|group
argument_list|,
name|SIGNAL
argument_list|(
name|activeStackChanged
argument_list|(
name|QUndoStack
operator|*
argument_list|)
argument_list|)
argument_list|,
name|d
operator|->
name|model
argument_list|,
name|SLOT
argument_list|(
name|setStack
argument_list|(
name|QUndoStack
operator|*
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|d
operator|->
name|model
operator|->
name|setStack
argument_list|(
name|d
operator|->
name|group
operator|->
name|activeStack
argument_list|()
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|d
operator|->
name|model
operator|->
name|setStack
argument_list|(
literal|0
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_comment
comment|/*!     Returns the group displayed by this view.      If the view is not looking at group, this function returns 0.      \sa setGroup() setStack() */
end_comment
begin_function
DECL|function|group
name|QUndoGroup
modifier|*
name|QUndoView
operator|::
name|group
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QUndoView
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|group
return|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_UNDOGROUP
end_comment
begin_comment
comment|/*!     \property QUndoView::emptyLabel     \brief the label used for the empty state.      The empty label is the topmost element in the list of commands, which represents     the state of the document before any commands were pushed on the stack. The default     is the string "<empty>". */
end_comment
begin_function
DECL|function|setEmptyLabel
name|void
name|QUndoView
operator|::
name|setEmptyLabel
parameter_list|(
specifier|const
name|QString
modifier|&
name|label
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QUndoView
argument_list|)
expr_stmt|;
name|d
operator|->
name|model
operator|->
name|setEmptyLabel
argument_list|(
name|label
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|emptyLabel
name|QString
name|QUndoView
operator|::
name|emptyLabel
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QUndoView
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|model
operator|->
name|emptyLabel
argument_list|()
return|;
block|}
end_function
begin_comment
comment|/*!     \property QUndoView::cleanIcon     \brief the icon used to represent the clean state.      A stack may have a clean state set with QUndoStack::setClean(). This is usually     the state of the document at the point it was saved. QUndoView can display an     icon in the list of commands to show the clean state. If this property is     a null icon, no icon is shown. The default value is the null icon. */
end_comment
begin_function
DECL|function|setCleanIcon
name|void
name|QUndoView
operator|::
name|setCleanIcon
parameter_list|(
specifier|const
name|QIcon
modifier|&
name|icon
parameter_list|)
block|{
name|Q_D
argument_list|(
specifier|const
name|QUndoView
argument_list|)
expr_stmt|;
name|d
operator|->
name|model
operator|->
name|setCleanIcon
argument_list|(
name|icon
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|cleanIcon
name|QIcon
name|QUndoView
operator|::
name|cleanIcon
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QUndoView
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|model
operator|->
name|cleanIcon
argument_list|()
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_include
include|#
directive|include
file|"qundoview.moc"
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_UNDOVIEW
end_comment
end_unit
