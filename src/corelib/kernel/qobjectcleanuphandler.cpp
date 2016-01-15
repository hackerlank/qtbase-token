begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qobjectcleanuphandler.h"
end_include
begin_function
name|QT_BEGIN_NAMESPACE
comment|/*!     \class QObjectCleanupHandler     \inmodule QtCore     \brief The QObjectCleanupHandler class watches the lifetime of multiple QObjects.      \ingroup objectmodel      A QObjectCleanupHandler is useful whenever you need to know when a     number of \l{QObject}s that are owned by someone else have been     deleted. This is important, for example, when referencing memory     in an application that has been allocated in a shared library.      To keep track of some \l{QObject}s, create a     QObjectCleanupHandler, and add() the objects you are interested     in. If you are no longer interested in tracking a particular     object, use remove() to remove it from the cleanup handler. If an     object being tracked by the cleanup handler gets deleted by     someone else it will automatically be removed from the cleanup     handler. You can delete all the objects in the cleanup handler     with clear(), or by destroying the cleanup handler. isEmpty()     returns \c true if the QObjectCleanupHandler has no objects to keep     track of.      \sa QPointer */
comment|/*!     Constructs an empty QObjectCleanupHandler. */
DECL|function|QObjectCleanupHandler
name|QObjectCleanupHandler
operator|::
name|QObjectCleanupHandler
parameter_list|()
block|{ }
end_function
begin_comment
comment|/*!     Destroys the cleanup handler. All objects in this cleanup handler     will be deleted.      \sa clear() */
end_comment
begin_destructor
DECL|function|~QObjectCleanupHandler
name|QObjectCleanupHandler
operator|::
name|~
name|QObjectCleanupHandler
parameter_list|()
block|{
name|clear
argument_list|()
expr_stmt|;
block|}
end_destructor
begin_comment
comment|/*!     Adds \a object to this cleanup handler and returns the pointer to     the object.      \sa remove() */
end_comment
begin_function
DECL|function|add
name|QObject
modifier|*
name|QObjectCleanupHandler
operator|::
name|add
parameter_list|(
name|QObject
modifier|*
name|object
parameter_list|)
block|{
if|if
condition|(
operator|!
name|object
condition|)
return|return
literal|0
return|;
name|connect
argument_list|(
name|object
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
name|objectDestroyed
argument_list|(
name|QObject
operator|*
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|cleanupObjects
operator|.
name|insert
argument_list|(
literal|0
argument_list|,
name|object
argument_list|)
expr_stmt|;
return|return
name|object
return|;
block|}
end_function
begin_comment
comment|/*!     Removes the \a object from this cleanup handler. The object will     not be destroyed.      \sa add() */
end_comment
begin_function
DECL|function|remove
name|void
name|QObjectCleanupHandler
operator|::
name|remove
parameter_list|(
name|QObject
modifier|*
name|object
parameter_list|)
block|{
name|int
name|index
decl_stmt|;
if|if
condition|(
operator|(
name|index
operator|=
name|cleanupObjects
operator|.
name|indexOf
argument_list|(
name|object
argument_list|)
operator|)
operator|!=
operator|-
literal|1
condition|)
block|{
name|cleanupObjects
operator|.
name|removeAt
argument_list|(
name|index
argument_list|)
expr_stmt|;
name|disconnect
argument_list|(
name|object
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
name|objectDestroyed
argument_list|(
name|QObject
operator|*
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_comment
comment|/*!     Returns \c true if this cleanup handler is empty or if all objects in     this cleanup handler have been destroyed; otherwise return false.      \sa add(), remove(), clear() */
end_comment
begin_function
DECL|function|isEmpty
name|bool
name|QObjectCleanupHandler
operator|::
name|isEmpty
parameter_list|()
specifier|const
block|{
return|return
name|cleanupObjects
operator|.
name|isEmpty
argument_list|()
return|;
block|}
end_function
begin_comment
comment|/*!     Deletes all objects in this cleanup handler. The cleanup handler     becomes empty.      \sa isEmpty() */
end_comment
begin_function
DECL|function|clear
name|void
name|QObjectCleanupHandler
operator|::
name|clear
parameter_list|()
block|{
while|while
condition|(
operator|!
name|cleanupObjects
operator|.
name|isEmpty
argument_list|()
condition|)
operator|delete
name|cleanupObjects
operator|.
name|takeFirst
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|objectDestroyed
name|void
name|QObjectCleanupHandler
operator|::
name|objectDestroyed
parameter_list|(
name|QObject
modifier|*
name|object
parameter_list|)
block|{
name|remove
argument_list|(
name|object
argument_list|)
expr_stmt|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
