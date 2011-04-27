begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** No Commercial Usage ** This file contains pre-release code and may not be distributed. ** You may use this file in accordance with the terms and conditions ** contained in the Technology Preview License Agreement accompanying ** this package. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights.  These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** If you have questions regarding the use of this file, please contact ** Nokia at qt-info@nokia.com. ** ** ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<qwidget.h>
end_include
begin_include
include|#
directive|include
file|<qdrag.h>
end_include
begin_include
include|#
directive|include
file|<qpixmap.h>
end_include
begin_include
include|#
directive|include
file|<qpoint.h>
end_include
begin_include
include|#
directive|include
file|"qdnd_p.h"
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_DRAGANDDROP
end_ifndef
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_comment
comment|/*!     \class QDrag     \brief The QDrag class provides support for MIME-based drag and drop data     transfer.      Drag and drop is an intuitive way for users to copy or move data around in an     application, and is used in many desktop environments as a mechanism for copying     data between applications. Drag and drop support in Qt is centered around the     QDrag class that handles most of the details of a drag and drop operation.      The data to be transferred by the drag and drop operation is contained in a     QMimeData object. This is specified with the setMimeData() function in the     following way:      \snippet doc/src/snippets/dragging/mainwindow.cpp 1      Note that setMimeData() assigns ownership of the QMimeData object to the     QDrag object. The QDrag must be constructed on the heap with a parent QWidget     to ensure that Qt can clean up after the drag and drop operation has been     completed.      A pixmap can be used to represent the data while the drag is in     progress, and will move with the cursor to the drop target. This     pixmap typically shows an icon that represents the MIME type of     the data being transferred, but any pixmap can be set with     setPixmap(). The cursor's hot spot can be given a position     relative to the top-left corner of the pixmap with the     setHotSpot() function. The following code positions the pixmap so     that the cursor's hot spot points to the center of its bottom     edge:      \snippet doc/src/snippets/separations/finalwidget.cpp 2      \note On X11, the pixmap may not be able to keep up with the mouse     movements if the hot spot causes the pixmap to be displayed     directly under the cursor.      The source and target widgets can be found with source() and target().     These functions are often used to determine whether drag and drop operations     started and finished at the same widget, so that special behavior can be     implemented.      QDrag only deals with the drag and drop operation itself. It is up to the     developer to decide when a drag operation begins, and how a QDrag object should     be constructed and used. For a given widget, it is often necessary to     reimplement \l{QWidget::mousePressEvent()}{mousePressEvent()} to determine     whether the user has pressed a mouse button, and reimplement     \l{QWidget::mouseMoveEvent()}{mouseMoveEvent()} to check whether a QDrag is     required.      \sa {Drag and Drop}, QClipboard, QMimeData, QWindowsMime, QMacPasteboardMime,         {Draggable Icons Example}, {Draggable Text Example}, {Drop Site Example}, 	    {Fridge Magnets Example} */
end_comment
begin_comment
comment|/*!     Constructs a new drag object for the widget specified by \a dragSource. */
end_comment
begin_constructor
DECL|function|QDrag
name|QDrag
operator|::
name|QDrag
parameter_list|(
name|QWidget
modifier|*
name|dragSource
parameter_list|)
member_init_list|:
name|QObject
argument_list|(
operator|*
operator|new
name|QDragPrivate
argument_list|,
name|dragSource
argument_list|)
block|{
name|Q_D
argument_list|(
name|QDrag
argument_list|)
expr_stmt|;
name|d
operator|->
name|source
operator|=
name|dragSource
expr_stmt|;
name|d
operator|->
name|target
operator|=
literal|0
expr_stmt|;
name|d
operator|->
name|data
operator|=
literal|0
expr_stmt|;
name|d
operator|->
name|hotspot
operator|=
name|QPoint
argument_list|(
operator|-
literal|10
argument_list|,
operator|-
literal|10
argument_list|)
expr_stmt|;
name|d
operator|->
name|possible_actions
operator|=
name|Qt
operator|::
name|CopyAction
expr_stmt|;
name|d
operator|->
name|executed_action
operator|=
name|Qt
operator|::
name|IgnoreAction
expr_stmt|;
name|d
operator|->
name|defaultDropAction
operator|=
name|Qt
operator|::
name|IgnoreAction
expr_stmt|;
block|}
end_constructor
begin_comment
comment|/*!     Destroys the drag object. */
end_comment
begin_destructor
DECL|function|~QDrag
name|QDrag
operator|::
name|~
name|QDrag
parameter_list|()
block|{
name|Q_D
argument_list|(
name|QDrag
argument_list|)
expr_stmt|;
operator|delete
name|d
operator|->
name|data
expr_stmt|;
name|QDragManager
modifier|*
name|manager
init|=
name|QDragManager
operator|::
name|self
argument_list|()
decl_stmt|;
if|if
condition|(
name|manager
operator|&&
name|manager
operator|->
name|object
operator|==
name|this
condition|)
name|manager
operator|->
name|cancel
argument_list|(
literal|false
argument_list|)
expr_stmt|;
block|}
end_destructor
begin_comment
comment|/*!     Sets the data to be sent to the given MIME \a data. Ownership of the data is     transferred to the QDrag object. */
end_comment
begin_function
DECL|function|setMimeData
name|void
name|QDrag
operator|::
name|setMimeData
parameter_list|(
name|QMimeData
modifier|*
name|data
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QDrag
argument_list|)
expr_stmt|;
if|if
condition|(
name|d
operator|->
name|data
operator|==
name|data
condition|)
return|return;
if|if
condition|(
name|d
operator|->
name|data
operator|!=
literal|0
condition|)
operator|delete
name|d
operator|->
name|data
expr_stmt|;
name|d
operator|->
name|data
operator|=
name|data
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     Returns the MIME data that is encapsulated by the drag object. */
end_comment
begin_function
DECL|function|mimeData
name|QMimeData
modifier|*
name|QDrag
operator|::
name|mimeData
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QDrag
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|data
return|;
block|}
end_function
begin_comment
comment|/*!     Sets \a pixmap as the pixmap used to represent the data in a drag     and drop operation. You can only set a pixmap before the drag is     started. */
end_comment
begin_function
DECL|function|setPixmap
name|void
name|QDrag
operator|::
name|setPixmap
parameter_list|(
specifier|const
name|QPixmap
modifier|&
name|pixmap
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QDrag
argument_list|)
expr_stmt|;
name|d
operator|->
name|pixmap
operator|=
name|pixmap
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     Returns the pixmap used to represent the data in a drag and drop operation. */
end_comment
begin_function
DECL|function|pixmap
name|QPixmap
name|QDrag
operator|::
name|pixmap
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QDrag
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|pixmap
return|;
block|}
end_function
begin_comment
comment|/*!     Sets the position of the hot spot relative to the top-left corner of the     pixmap used to the point specified by \a hotspot.      \bold{Note:} on X11, the pixmap may not be able to keep up with the mouse     movements if the hot spot causes the pixmap to be displayed     directly under the cursor. */
end_comment
begin_function
DECL|function|setHotSpot
name|void
name|QDrag
operator|::
name|setHotSpot
parameter_list|(
specifier|const
name|QPoint
modifier|&
name|hotspot
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QDrag
argument_list|)
expr_stmt|;
name|d
operator|->
name|hotspot
operator|=
name|hotspot
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     Returns the position of the hot spot relative to the top-left corner of the     cursor. */
end_comment
begin_function
DECL|function|hotSpot
name|QPoint
name|QDrag
operator|::
name|hotSpot
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QDrag
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|hotspot
return|;
block|}
end_function
begin_comment
comment|/*!     Returns the source of the drag object. This is the widget where the drag     and drop operation originated. */
end_comment
begin_function
DECL|function|source
name|QWidget
modifier|*
name|QDrag
operator|::
name|source
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QDrag
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|source
return|;
block|}
end_function
begin_comment
comment|/*!     Returns the target of the drag and drop operation. This is the widget where     the drag object was dropped. */
end_comment
begin_function
DECL|function|target
name|QWidget
modifier|*
name|QDrag
operator|::
name|target
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QDrag
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|target
return|;
block|}
end_function
begin_comment
comment|/*!     \since 4.3      Starts the drag and drop operation and returns a value indicating the requested     drop action when it is completed. The drop actions that the user can choose     from are specified in \a supportedActions. The default proposed action will be selected     among the allowed actions in the following order: Move, Copy and Link.      \bold{Note:} On Linux and Mac OS X, the drag and drop operation     can take some time, but this function does not block the event     loop. Other events are still delivered to the application while     the operation is performed. On Windows, the Qt event loop is     blocked while during the operation. */
end_comment
begin_function
DECL|function|exec
name|Qt
operator|::
name|DropAction
name|QDrag
operator|::
name|exec
parameter_list|(
name|Qt
operator|::
name|DropActions
name|supportedActions
parameter_list|)
block|{
return|return
name|exec
argument_list|(
name|supportedActions
argument_list|,
name|Qt
operator|::
name|IgnoreAction
argument_list|)
return|;
block|}
end_function
begin_comment
comment|/*!     \since 4.3      Starts the drag and drop operation and returns a value indicating the requested     drop action when it is completed. The drop actions that the user can choose     from are specified in \a supportedActions.      The \a defaultDropAction determines which action will be proposed when the user performs a     drag without using modifier keys.      \bold{Note:} On Linux and Mac OS X, the drag and drop operation     can take some time, but this function does not block the event     loop. Other events are still delivered to the application while     the operation is performed. On Windows, the Qt event loop is     blocked during the operation. However, QDrag::exec() on 	Windows causes processEvents() to be called frequently to keep the GUI responsive. 	If any loops or operations are called while a drag operation is active, it will block the drag operation. */
end_comment
begin_function
DECL|function|exec
name|Qt
operator|::
name|DropAction
name|QDrag
operator|::
name|exec
parameter_list|(
name|Qt
operator|::
name|DropActions
name|supportedActions
parameter_list|,
name|Qt
operator|::
name|DropAction
name|defaultDropAction
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QDrag
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|d
operator|->
name|data
condition|)
block|{
name|qWarning
argument_list|(
literal|"QDrag: No mimedata set before starting the drag"
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|executed_action
return|;
block|}
name|QDragManager
modifier|*
name|manager
init|=
name|QDragManager
operator|::
name|self
argument_list|()
decl_stmt|;
name|d
operator|->
name|defaultDropAction
operator|=
name|Qt
operator|::
name|IgnoreAction
expr_stmt|;
name|d
operator|->
name|possible_actions
operator|=
name|supportedActions
expr_stmt|;
if|if
condition|(
name|manager
condition|)
block|{
if|if
condition|(
name|defaultDropAction
operator|==
name|Qt
operator|::
name|IgnoreAction
condition|)
block|{
if|if
condition|(
name|supportedActions
operator|&
name|Qt
operator|::
name|MoveAction
condition|)
block|{
name|d
operator|->
name|defaultDropAction
operator|=
name|Qt
operator|::
name|MoveAction
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|supportedActions
operator|&
name|Qt
operator|::
name|CopyAction
condition|)
block|{
name|d
operator|->
name|defaultDropAction
operator|=
name|Qt
operator|::
name|CopyAction
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|supportedActions
operator|&
name|Qt
operator|::
name|LinkAction
condition|)
block|{
name|d
operator|->
name|defaultDropAction
operator|=
name|Qt
operator|::
name|LinkAction
expr_stmt|;
block|}
block|}
else|else
block|{
name|d
operator|->
name|defaultDropAction
operator|=
name|defaultDropAction
expr_stmt|;
block|}
name|d
operator|->
name|executed_action
operator|=
name|manager
operator|->
name|drag
argument_list|(
name|this
argument_list|)
expr_stmt|;
block|}
return|return
name|d
operator|->
name|executed_action
return|;
block|}
end_function
begin_comment
comment|/*!     \obsolete      \bold{Note:} It is recommended to use exec() instead of this function.      Starts the drag and drop operation and returns a value indicating the requested     drop action when it is completed. The drop actions that the user can choose     from are specified in \a request. Qt::CopyAction is always allowed.      \bold{Note:} Although the drag and drop operation can take some time, this function     does not block the event loop. Other events are still delivered to the application     while the operation is performed.      \sa exec() */
end_comment
begin_function
DECL|function|start
name|Qt
operator|::
name|DropAction
name|QDrag
operator|::
name|start
parameter_list|(
name|Qt
operator|::
name|DropActions
name|request
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QDrag
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|d
operator|->
name|data
condition|)
block|{
name|qWarning
argument_list|(
literal|"QDrag: No mimedata set before starting the drag"
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|executed_action
return|;
block|}
name|QDragManager
modifier|*
name|manager
init|=
name|QDragManager
operator|::
name|self
argument_list|()
decl_stmt|;
name|d
operator|->
name|defaultDropAction
operator|=
name|Qt
operator|::
name|IgnoreAction
expr_stmt|;
name|d
operator|->
name|possible_actions
operator|=
name|request
operator||
name|Qt
operator|::
name|CopyAction
expr_stmt|;
if|if
condition|(
name|manager
condition|)
name|d
operator|->
name|executed_action
operator|=
name|manager
operator|->
name|drag
argument_list|(
name|this
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|executed_action
return|;
block|}
end_function
begin_comment
comment|/*!     Sets the drag \a cursor for the \a action. This allows you     to override the default native cursors. To revert to using the     native cursor for \a action pass in a null QPixmap as \a cursor.      The \a action can only be CopyAction, MoveAction or LinkAction.     All other values of DropAction are ignored. */
end_comment
begin_function
DECL|function|setDragCursor
name|void
name|QDrag
operator|::
name|setDragCursor
parameter_list|(
specifier|const
name|QPixmap
modifier|&
name|cursor
parameter_list|,
name|Qt
operator|::
name|DropAction
name|action
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QDrag
argument_list|)
expr_stmt|;
if|if
condition|(
name|action
operator|!=
name|Qt
operator|::
name|CopyAction
operator|&&
name|action
operator|!=
name|Qt
operator|::
name|MoveAction
operator|&&
name|action
operator|!=
name|Qt
operator|::
name|LinkAction
condition|)
return|return;
if|if
condition|(
name|cursor
operator|.
name|isNull
argument_list|()
condition|)
name|d
operator|->
name|customCursors
operator|.
name|remove
argument_list|(
name|action
argument_list|)
expr_stmt|;
else|else
name|d
operator|->
name|customCursors
index|[
name|action
index|]
operator|=
name|cursor
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     \fn void QDrag::actionChanged(Qt::DropAction action)      This signal is emitted when the \a action associated with the     drag changes.      \sa targetChanged() */
end_comment
begin_comment
comment|/*!     \fn void QDrag::targetChanged(QWidget *newTarget)      This signal is emitted when the target of the drag and drop     operation changes, with \a newTarget the new target.      \sa target(), actionChanged() */
end_comment
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_DRAGANDDROP
end_comment
end_unit
