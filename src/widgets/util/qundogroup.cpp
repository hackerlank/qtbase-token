begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qundogroup.h"
end_include
begin_include
include|#
directive|include
file|"qundostack.h"
end_include
begin_include
include|#
directive|include
file|"qundostack_p.h"
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_UNDOGROUP
end_ifndef
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_class
DECL|class|QUndoGroupPrivate
class|class
name|QUndoGroupPrivate
super|:
specifier|public
name|QObjectPrivate
block|{
name|Q_DECLARE_PUBLIC
parameter_list|(
name|QUndoGroup
parameter_list|)
specifier|public
private|:
DECL|function|QUndoGroupPrivate
name|QUndoGroupPrivate
parameter_list|()
member_init_list|:
name|active
argument_list|(
literal|0
argument_list|)
block|{}
DECL|member|active
name|QUndoStack
modifier|*
name|active
decl_stmt|;
DECL|member|stack_list
name|QList
argument_list|<
name|QUndoStack
modifier|*
argument_list|>
name|stack_list
decl_stmt|;
block|}
class|;
end_class
begin_comment
comment|/*!     \class QUndoGroup     \brief The QUndoGroup class is a group of QUndoStack objects.     \since 4.2     \inmodule QtWidgets      For an overview of the Qt's undo framework, see the     \link qundo.html overview\endlink.      An application often has multiple undo stacks, one for each opened document. At the     same time, an application usually has one undo action and one redo action, which     triggers undo or redo in the active document.      QUndoGroup is a group of QUndoStack objects, one of which may be active. It has     an undo() and redo() slot, which calls QUndoStack::undo() and QUndoStack::redo()     for the active stack. It also has the functions createUndoAction() and createRedoAction().     The actions returned by these functions behave in the same way as those returned by     QUndoStack::createUndoAction() and QUndoStack::createRedoAction() of the active     stack.      Stacks are added to a group with addStack() and removed with removeStack(). A stack     is implicitly added to a group when it is created with the group as its parent     QObject.      It is the programmer's responsibility to specify which stack is active by     calling QUndoStack::setActive(), usually when the associated document window receives focus.     The active stack may also be set with setActiveStack(), and is returned by activeStack().      When a stack is added to a group using addStack(), the group does not take ownership     of the stack. This means the stack has to be deleted separately from the group. When     a stack is deleted, it is automatically removed from a group. A stack may belong to     only one group. Adding it to another group will cause it to be removed from the previous     group.      A QUndoGroup is also useful in conjunction with QUndoView. If a QUndoView is     set to watch a group using QUndoView::setGroup(), it will update itself to display     the active stack. */
end_comment
begin_comment
comment|/*!     Creates an empty QUndoGroup object with parent \a parent.      \sa addStack() */
end_comment
begin_constructor
DECL|function|QUndoGroup
name|QUndoGroup
operator|::
name|QUndoGroup
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
name|QUndoGroupPrivate
argument_list|()
argument_list|,
name|parent
argument_list|)
block|{ }
end_constructor
begin_comment
comment|/*!     Destroys the QUndoGroup. */
end_comment
begin_destructor
DECL|function|~QUndoGroup
name|QUndoGroup
operator|::
name|~
name|QUndoGroup
parameter_list|()
block|{
comment|// Ensure all QUndoStacks no longer refer to this group.
name|Q_D
argument_list|(
name|QUndoGroup
argument_list|)
expr_stmt|;
name|QList
argument_list|<
name|QUndoStack
modifier|*
argument_list|>
operator|::
name|iterator
name|it
init|=
name|d
operator|->
name|stack_list
operator|.
name|begin
argument_list|()
decl_stmt|;
name|QList
argument_list|<
name|QUndoStack
modifier|*
argument_list|>
operator|::
name|iterator
name|end
init|=
name|d
operator|->
name|stack_list
operator|.
name|end
argument_list|()
decl_stmt|;
while|while
condition|(
name|it
operator|!=
name|end
condition|)
block|{
operator|(
operator|*
name|it
operator|)
operator|->
name|d_func
argument_list|()
operator|->
name|group
operator|=
literal|0
expr_stmt|;
operator|++
name|it
expr_stmt|;
block|}
block|}
end_destructor
begin_comment
comment|/*!     Adds \a stack to this group. The group does not take ownership of the stack. Another     way of adding a stack to a group is by specifying the group as the stack's parent     QObject in QUndoStack::QUndoStack(). In this case, the stack is deleted when the     group is deleted, in the usual manner of QObjects.      \sa removeStack() stacks() QUndoStack::QUndoStack() */
end_comment
begin_function
DECL|function|addStack
name|void
name|QUndoGroup
operator|::
name|addStack
parameter_list|(
name|QUndoStack
modifier|*
name|stack
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QUndoGroup
argument_list|)
expr_stmt|;
if|if
condition|(
name|d
operator|->
name|stack_list
operator|.
name|contains
argument_list|(
name|stack
argument_list|)
condition|)
return|return;
name|d
operator|->
name|stack_list
operator|.
name|append
argument_list|(
name|stack
argument_list|)
expr_stmt|;
if|if
condition|(
name|QUndoGroup
modifier|*
name|other
init|=
name|stack
operator|->
name|d_func
argument_list|()
operator|->
name|group
condition|)
name|other
operator|->
name|removeStack
argument_list|(
name|stack
argument_list|)
expr_stmt|;
name|stack
operator|->
name|d_func
argument_list|()
operator|->
name|group
operator|=
name|this
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     Removes \a stack from this group. If the stack was the active stack in the group,     the active stack becomes 0.      \sa addStack() stacks() QUndoStack::~QUndoStack() */
end_comment
begin_function
DECL|function|removeStack
name|void
name|QUndoGroup
operator|::
name|removeStack
parameter_list|(
name|QUndoStack
modifier|*
name|stack
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QUndoGroup
argument_list|)
expr_stmt|;
if|if
condition|(
name|d
operator|->
name|stack_list
operator|.
name|removeAll
argument_list|(
name|stack
argument_list|)
operator|==
literal|0
condition|)
return|return;
if|if
condition|(
name|stack
operator|==
name|d
operator|->
name|active
condition|)
name|setActiveStack
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|stack
operator|->
name|d_func
argument_list|()
operator|->
name|group
operator|=
literal|0
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     Returns a list of stacks in this group.      \sa addStack() removeStack() */
end_comment
begin_function
DECL|function|stacks
name|QList
argument_list|<
name|QUndoStack
modifier|*
argument_list|>
name|QUndoGroup
operator|::
name|stacks
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QUndoGroup
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|stack_list
return|;
block|}
end_function
begin_comment
comment|/*!     Sets the active stack of this group to \a stack.      If the stack is not a member of this group, this function does nothing.      Synonymous with calling QUndoStack::setActive() on \a stack.      The actions returned by createUndoAction() and createRedoAction() will now behave     in the same way as those returned by \a stack's QUndoStack::createUndoAction()     and QUndoStack::createRedoAction().      \sa QUndoStack::setActive() activeStack() */
end_comment
begin_function
DECL|function|setActiveStack
name|void
name|QUndoGroup
operator|::
name|setActiveStack
parameter_list|(
name|QUndoStack
modifier|*
name|stack
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QUndoGroup
argument_list|)
expr_stmt|;
if|if
condition|(
name|d
operator|->
name|active
operator|==
name|stack
condition|)
return|return;
if|if
condition|(
name|d
operator|->
name|active
operator|!=
literal|0
condition|)
block|{
name|disconnect
argument_list|(
name|d
operator|->
name|active
argument_list|,
name|SIGNAL
argument_list|(
name|canUndoChanged
argument_list|(
name|bool
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SIGNAL
argument_list|(
name|canUndoChanged
argument_list|(
name|bool
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|disconnect
argument_list|(
name|d
operator|->
name|active
argument_list|,
name|SIGNAL
argument_list|(
name|undoTextChanged
argument_list|(
name|QString
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SIGNAL
argument_list|(
name|undoTextChanged
argument_list|(
name|QString
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|disconnect
argument_list|(
name|d
operator|->
name|active
argument_list|,
name|SIGNAL
argument_list|(
name|canRedoChanged
argument_list|(
name|bool
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SIGNAL
argument_list|(
name|canRedoChanged
argument_list|(
name|bool
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|disconnect
argument_list|(
name|d
operator|->
name|active
argument_list|,
name|SIGNAL
argument_list|(
name|redoTextChanged
argument_list|(
name|QString
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SIGNAL
argument_list|(
name|redoTextChanged
argument_list|(
name|QString
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|disconnect
argument_list|(
name|d
operator|->
name|active
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
name|SIGNAL
argument_list|(
name|indexChanged
argument_list|(
name|int
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|disconnect
argument_list|(
name|d
operator|->
name|active
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
name|SIGNAL
argument_list|(
name|cleanChanged
argument_list|(
name|bool
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
block|}
name|d
operator|->
name|active
operator|=
name|stack
expr_stmt|;
if|if
condition|(
name|d
operator|->
name|active
operator|==
literal|0
condition|)
block|{
emit|emit
name|canUndoChanged
argument_list|(
literal|false
argument_list|)
emit|;
emit|emit
name|undoTextChanged
argument_list|(
name|QString
argument_list|()
argument_list|)
emit|;
emit|emit
name|canRedoChanged
argument_list|(
literal|false
argument_list|)
emit|;
emit|emit
name|redoTextChanged
argument_list|(
name|QString
argument_list|()
argument_list|)
emit|;
emit|emit
name|cleanChanged
argument_list|(
literal|true
argument_list|)
emit|;
emit|emit
name|indexChanged
argument_list|(
literal|0
argument_list|)
emit|;
block|}
else|else
block|{
name|connect
argument_list|(
name|d
operator|->
name|active
argument_list|,
name|SIGNAL
argument_list|(
name|canUndoChanged
argument_list|(
name|bool
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SIGNAL
argument_list|(
name|canUndoChanged
argument_list|(
name|bool
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|d
operator|->
name|active
argument_list|,
name|SIGNAL
argument_list|(
name|undoTextChanged
argument_list|(
name|QString
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SIGNAL
argument_list|(
name|undoTextChanged
argument_list|(
name|QString
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|d
operator|->
name|active
argument_list|,
name|SIGNAL
argument_list|(
name|canRedoChanged
argument_list|(
name|bool
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SIGNAL
argument_list|(
name|canRedoChanged
argument_list|(
name|bool
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|d
operator|->
name|active
argument_list|,
name|SIGNAL
argument_list|(
name|redoTextChanged
argument_list|(
name|QString
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SIGNAL
argument_list|(
name|redoTextChanged
argument_list|(
name|QString
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|d
operator|->
name|active
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
name|SIGNAL
argument_list|(
name|indexChanged
argument_list|(
name|int
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|d
operator|->
name|active
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
name|SIGNAL
argument_list|(
name|cleanChanged
argument_list|(
name|bool
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
emit|emit
name|canUndoChanged
argument_list|(
name|d
operator|->
name|active
operator|->
name|canUndo
argument_list|()
argument_list|)
emit|;
emit|emit
name|undoTextChanged
argument_list|(
name|d
operator|->
name|active
operator|->
name|undoText
argument_list|()
argument_list|)
emit|;
emit|emit
name|canRedoChanged
argument_list|(
name|d
operator|->
name|active
operator|->
name|canRedo
argument_list|()
argument_list|)
emit|;
emit|emit
name|redoTextChanged
argument_list|(
name|d
operator|->
name|active
operator|->
name|redoText
argument_list|()
argument_list|)
emit|;
emit|emit
name|cleanChanged
argument_list|(
name|d
operator|->
name|active
operator|->
name|isClean
argument_list|()
argument_list|)
emit|;
emit|emit
name|indexChanged
argument_list|(
name|d
operator|->
name|active
operator|->
name|index
argument_list|()
argument_list|)
emit|;
block|}
emit|emit
name|activeStackChanged
argument_list|(
name|d
operator|->
name|active
argument_list|)
emit|;
block|}
end_function
begin_comment
comment|/*!     Returns the active stack of this group.      If none of the stacks are active, or if the group is empty, this function     returns 0.      \sa setActiveStack() QUndoStack::setActive() */
end_comment
begin_function
DECL|function|activeStack
name|QUndoStack
modifier|*
name|QUndoGroup
operator|::
name|activeStack
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QUndoGroup
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|active
return|;
block|}
end_function
begin_comment
comment|/*!     Calls QUndoStack::undo() on the active stack.      If none of the stacks are active, or if the group is empty, this function     does nothing.      \sa redo() canUndo() setActiveStack() */
end_comment
begin_function
DECL|function|undo
name|void
name|QUndoGroup
operator|::
name|undo
parameter_list|()
block|{
name|Q_D
argument_list|(
name|QUndoGroup
argument_list|)
expr_stmt|;
if|if
condition|(
name|d
operator|->
name|active
operator|!=
literal|0
condition|)
name|d
operator|->
name|active
operator|->
name|undo
argument_list|()
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     Calls QUndoStack::redo() on the active stack.      If none of the stacks are active, or if the group is empty, this function     does nothing.      \sa undo() canRedo() setActiveStack() */
end_comment
begin_function
DECL|function|redo
name|void
name|QUndoGroup
operator|::
name|redo
parameter_list|()
block|{
name|Q_D
argument_list|(
name|QUndoGroup
argument_list|)
expr_stmt|;
if|if
condition|(
name|d
operator|->
name|active
operator|!=
literal|0
condition|)
name|d
operator|->
name|active
operator|->
name|redo
argument_list|()
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     Returns the value of the active stack's QUndoStack::canUndo().      If none of the stacks are active, or if the group is empty, this function     returns false.      \sa canRedo() setActiveStack() */
end_comment
begin_function
DECL|function|canUndo
name|bool
name|QUndoGroup
operator|::
name|canUndo
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QUndoGroup
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|active
operator|!=
literal|0
operator|&&
name|d
operator|->
name|active
operator|->
name|canUndo
argument_list|()
return|;
block|}
end_function
begin_comment
comment|/*!     Returns the value of the active stack's QUndoStack::canRedo().      If none of the stacks are active, or if the group is empty, this function     returns false.      \sa canUndo() setActiveStack() */
end_comment
begin_function
DECL|function|canRedo
name|bool
name|QUndoGroup
operator|::
name|canRedo
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QUndoGroup
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|active
operator|!=
literal|0
operator|&&
name|d
operator|->
name|active
operator|->
name|canRedo
argument_list|()
return|;
block|}
end_function
begin_comment
comment|/*!     Returns the value of the active stack's QUndoStack::undoText().      If none of the stacks are active, or if the group is empty, this function     returns an empty string.      \sa redoText() setActiveStack() */
end_comment
begin_function
DECL|function|undoText
name|QString
name|QUndoGroup
operator|::
name|undoText
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QUndoGroup
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|active
operator|==
literal|0
condition|?
name|QString
argument_list|()
else|:
name|d
operator|->
name|active
operator|->
name|undoText
argument_list|()
return|;
block|}
end_function
begin_comment
comment|/*!     Returns the value of the active stack's QUndoStack::redoText().      If none of the stacks are active, or if the group is empty, this function     returns an empty string.      \sa undoText() setActiveStack() */
end_comment
begin_function
DECL|function|redoText
name|QString
name|QUndoGroup
operator|::
name|redoText
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QUndoGroup
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|active
operator|==
literal|0
condition|?
name|QString
argument_list|()
else|:
name|d
operator|->
name|active
operator|->
name|redoText
argument_list|()
return|;
block|}
end_function
begin_comment
comment|/*!     Returns the value of the active stack's QUndoStack::isClean().      If none of the stacks are active, or if the group is empty, this function     returns true.      \sa setActiveStack() */
end_comment
begin_function
DECL|function|isClean
name|bool
name|QUndoGroup
operator|::
name|isClean
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QUndoGroup
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|active
operator|==
literal|0
operator|||
name|d
operator|->
name|active
operator|->
name|isClean
argument_list|()
return|;
block|}
end_function
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_ACTION
end_ifndef
begin_comment
comment|/*!     Creates an undo QAction object with parent \a parent.      Triggering this action will cause a call to QUndoStack::undo() on the active stack.     The text of this action will always be the text of the command which will be undone     in the next call to undo(), prefixed by \a prefix. If there is no command available     for undo, if the group is empty or if none of the stacks are active, this action will     be disabled.      If \a prefix is empty, the default template "Undo %1" is used instead of prefix.     Before Qt 4.8, the prefix "Undo" was used by default.      \sa createRedoAction() canUndo() QUndoCommand::text() */
end_comment
begin_function
DECL|function|createUndoAction
name|QAction
modifier|*
name|QUndoGroup
operator|::
name|createUndoAction
parameter_list|(
name|QObject
modifier|*
name|parent
parameter_list|,
specifier|const
name|QString
modifier|&
name|prefix
parameter_list|)
specifier|const
block|{
name|QUndoAction
modifier|*
name|result
init|=
operator|new
name|QUndoAction
argument_list|(
name|prefix
argument_list|,
name|parent
argument_list|)
decl_stmt|;
if|if
condition|(
name|prefix
operator|.
name|isEmpty
argument_list|()
condition|)
name|result
operator|->
name|setTextFormat
argument_list|(
name|tr
argument_list|(
literal|"Undo %1"
argument_list|)
argument_list|,
name|tr
argument_list|(
literal|"Undo"
argument_list|,
literal|"Default text for undo action"
argument_list|)
argument_list|)
expr_stmt|;
name|result
operator|->
name|setEnabled
argument_list|(
name|canUndo
argument_list|()
argument_list|)
expr_stmt|;
name|result
operator|->
name|setPrefixedText
argument_list|(
name|undoText
argument_list|()
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|this
argument_list|,
name|SIGNAL
argument_list|(
name|canUndoChanged
argument_list|(
name|bool
argument_list|)
argument_list|)
argument_list|,
name|result
argument_list|,
name|SLOT
argument_list|(
name|setEnabled
argument_list|(
name|bool
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|this
argument_list|,
name|SIGNAL
argument_list|(
name|undoTextChanged
argument_list|(
name|QString
argument_list|)
argument_list|)
argument_list|,
name|result
argument_list|,
name|SLOT
argument_list|(
name|setPrefixedText
argument_list|(
name|QString
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|result
argument_list|,
name|SIGNAL
argument_list|(
name|triggered
argument_list|()
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|undo
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|result
return|;
block|}
end_function
begin_comment
comment|/*!     Creates an redo QAction object with parent \a parent.      Triggering this action will cause a call to QUndoStack::redo() on the active stack.     The text of this action will always be the text of the command which will be redone     in the next call to redo(), prefixed by \a prefix. If there is no command available     for redo, if the group is empty or if none of the stacks are active, this action will     be disabled.      If \a prefix is empty, the default template "Redo %1" is used instead of prefix.     Before Qt 4.8, the prefix "Redo" was used by default.      \sa createUndoAction() canRedo() QUndoCommand::text() */
end_comment
begin_function
DECL|function|createRedoAction
name|QAction
modifier|*
name|QUndoGroup
operator|::
name|createRedoAction
parameter_list|(
name|QObject
modifier|*
name|parent
parameter_list|,
specifier|const
name|QString
modifier|&
name|prefix
parameter_list|)
specifier|const
block|{
name|QUndoAction
modifier|*
name|result
init|=
operator|new
name|QUndoAction
argument_list|(
name|prefix
argument_list|,
name|parent
argument_list|)
decl_stmt|;
if|if
condition|(
name|prefix
operator|.
name|isEmpty
argument_list|()
condition|)
name|result
operator|->
name|setTextFormat
argument_list|(
name|tr
argument_list|(
literal|"Redo %1"
argument_list|)
argument_list|,
name|tr
argument_list|(
literal|"Redo"
argument_list|,
literal|"Default text for redo action"
argument_list|)
argument_list|)
expr_stmt|;
name|result
operator|->
name|setEnabled
argument_list|(
name|canRedo
argument_list|()
argument_list|)
expr_stmt|;
name|result
operator|->
name|setPrefixedText
argument_list|(
name|redoText
argument_list|()
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|this
argument_list|,
name|SIGNAL
argument_list|(
name|canRedoChanged
argument_list|(
name|bool
argument_list|)
argument_list|)
argument_list|,
name|result
argument_list|,
name|SLOT
argument_list|(
name|setEnabled
argument_list|(
name|bool
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|this
argument_list|,
name|SIGNAL
argument_list|(
name|redoTextChanged
argument_list|(
name|QString
argument_list|)
argument_list|)
argument_list|,
name|result
argument_list|,
name|SLOT
argument_list|(
name|setPrefixedText
argument_list|(
name|QString
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|result
argument_list|,
name|SIGNAL
argument_list|(
name|triggered
argument_list|()
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|redo
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|result
return|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_ACTION
end_comment
begin_comment
comment|/*! \fn void QUndoGroup::activeStackChanged(QUndoStack *stack)      This signal is emitted whenever the active stack of the group changes. This can happen     when setActiveStack() or QUndoStack::setActive() is called, or when the active stack     is removed form the group. \a stack is the new active stack. If no stack is active,     \a stack is 0.      \sa setActiveStack() QUndoStack::setActive() */
end_comment
begin_comment
comment|/*! \fn void QUndoGroup::indexChanged(int idx)      This signal is emitted whenever the active stack emits QUndoStack::indexChanged()     or the active stack changes.      \a idx is the new current index, or 0 if the active stack is 0.      \sa QUndoStack::indexChanged() setActiveStack() */
end_comment
begin_comment
comment|/*! \fn void QUndoGroup::cleanChanged(bool clean)      This signal is emitted whenever the active stack emits QUndoStack::cleanChanged()     or the active stack changes.      \a clean is the new state, or true if the active stack is 0.      \sa QUndoStack::cleanChanged() setActiveStack() */
end_comment
begin_comment
comment|/*! \fn void QUndoGroup::canUndoChanged(bool canUndo)      This signal is emitted whenever the active stack emits QUndoStack::canUndoChanged()     or the active stack changes.      \a canUndo is the new state, or false if the active stack is 0.      \sa QUndoStack::canUndoChanged() setActiveStack() */
end_comment
begin_comment
comment|/*! \fn void QUndoGroup::canRedoChanged(bool canRedo)      This signal is emitted whenever the active stack emits QUndoStack::canRedoChanged()     or the active stack changes.      \a canRedo is the new state, or false if the active stack is 0.      \sa QUndoStack::canRedoChanged() setActiveStack() */
end_comment
begin_comment
comment|/*! \fn void QUndoGroup::undoTextChanged(const QString&undoText)      This signal is emitted whenever the active stack emits QUndoStack::undoTextChanged()     or the active stack changes.      \a undoText is the new state, or an empty string if the active stack is 0.      \sa QUndoStack::undoTextChanged() setActiveStack() */
end_comment
begin_comment
comment|/*! \fn void QUndoGroup::redoTextChanged(const QString&redoText)      This signal is emitted whenever the active stack emits QUndoStack::redoTextChanged()     or the active stack changes.      \a redoText is the new state, or an empty string if the active stack is 0.      \sa QUndoStack::redoTextChanged() setActiveStack() */
end_comment
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_UNDOGROUP
end_comment
end_unit
