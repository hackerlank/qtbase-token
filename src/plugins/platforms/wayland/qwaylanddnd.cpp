begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qwaylanddnd.h"
end_include
begin_include
include|#
directive|include
file|"qwaylandinputdevice.h"
end_include
begin_include
include|#
directive|include
file|<QStringList>
end_include
begin_include
include|#
directive|include
file|<QFile>
end_include
begin_include
include|#
directive|include
file|<QtGui/private/qdnd_p.h>
end_include
begin_include
include|#
directive|include
file|<QGuiApplication>
end_include
begin_include
include|#
directive|include
file|<QSocketNotifier>
end_include
begin_include
include|#
directive|include
file|<sys/time.h>
end_include
begin_include
include|#
directive|include
file|<errno.h>
end_include
begin_include
include|#
directive|include
file|<unistd.h>
end_include
begin_include
include|#
directive|include
file|<fcntl.h>
end_include
begin_include
include|#
directive|include
file|<QDebug>
end_include
begin_include
include|#
directive|include
file|<QPlatformCursor>
end_include
begin_include
include|#
directive|include
file|"qwaylandcursor.h"
end_include
begin_class
DECL|class|QWaylandDragWrapper
class|class
name|QWaylandDragWrapper
block|{
public|public:
name|QWaylandDragWrapper
parameter_list|(
name|QWaylandDisplay
modifier|*
name|display
parameter_list|,
name|QMimeData
modifier|*
name|data
parameter_list|)
constructor_decl|;
name|~
name|QWaylandDragWrapper
parameter_list|()
destructor_decl|;
DECL|function|mimeData
name|QMimeData
modifier|*
name|mimeData
parameter_list|()
specifier|const
block|{
return|return
name|mData
return|;
block|}
private|private:
specifier|static
name|void
name|target
parameter_list|(
name|void
modifier|*
name|data
parameter_list|,
name|wl_drag
modifier|*
name|drag
parameter_list|,
specifier|const
name|char
modifier|*
name|mimeType
parameter_list|)
function_decl|;
specifier|static
name|void
name|finish
parameter_list|(
name|void
modifier|*
name|data
parameter_list|,
name|wl_drag
modifier|*
name|drag
parameter_list|,
name|int
name|fd
parameter_list|)
function_decl|;
specifier|static
name|void
name|reject
parameter_list|(
name|void
modifier|*
name|data
parameter_list|,
name|wl_drag
modifier|*
name|drag
parameter_list|)
function_decl|;
DECL|member|dragListener
specifier|static
specifier|const
name|wl_drag_listener
name|dragListener
decl_stmt|;
DECL|member|mDisplay
name|QWaylandDisplay
modifier|*
name|mDisplay
decl_stmt|;
DECL|member|mDrag
name|wl_drag
modifier|*
name|mDrag
decl_stmt|;
DECL|member|mData
name|QMimeData
modifier|*
name|mData
decl_stmt|;
DECL|member|mAcceptedType
name|QString
name|mAcceptedType
decl_stmt|;
block|}
class|;
end_class
begin_class
DECL|class|QWaylandDragOfferWrapper
class|class
name|QWaylandDragOfferWrapper
block|{
public|public:
name|QWaylandDragOfferWrapper
parameter_list|(
name|QWaylandDisplay
modifier|*
name|display
parameter_list|,
name|QMimeData
modifier|*
name|data
parameter_list|,
name|uint32_t
name|id
parameter_list|)
constructor_decl|;
name|~
name|QWaylandDragOfferWrapper
parameter_list|()
destructor_decl|;
private|private:
specifier|static
name|void
name|offer
parameter_list|(
name|void
modifier|*
name|data
parameter_list|,
name|struct
name|wl_drag_offer
modifier|*
name|offer
parameter_list|,
specifier|const
name|char
modifier|*
name|mimeType
parameter_list|)
function_decl|;
specifier|static
name|void
name|pointerFocus
parameter_list|(
name|void
modifier|*
name|data
parameter_list|,
name|struct
name|wl_drag_offer
modifier|*
name|offer
parameter_list|,
name|uint32_t
name|time
parameter_list|,
name|wl_surface
modifier|*
name|surface
parameter_list|,
name|int32_t
name|x
parameter_list|,
name|int32_t
name|y
parameter_list|,
name|int32_t
name|surfaceX
parameter_list|,
name|int32_t
name|surfaceY
parameter_list|)
function_decl|;
specifier|static
name|void
name|motion
parameter_list|(
name|void
modifier|*
name|data
parameter_list|,
name|struct
name|wl_drag_offer
modifier|*
name|offer
parameter_list|,
name|uint32_t
name|time
parameter_list|,
name|int32_t
name|x
parameter_list|,
name|int32_t
name|y
parameter_list|,
name|int32_t
name|surfaceX
parameter_list|,
name|int32_t
name|surfaceY
parameter_list|)
function_decl|;
specifier|static
name|void
name|drop
parameter_list|(
name|void
modifier|*
name|data
parameter_list|,
name|struct
name|wl_drag_offer
modifier|*
name|offer
parameter_list|)
function_decl|;
DECL|member|dragOfferListener
specifier|static
specifier|const
name|wl_drag_offer_listener
name|dragOfferListener
decl_stmt|;
name|void
name|sendEventToWindow
parameter_list|(
name|struct
name|wl_drag_offer
modifier|*
name|offer
parameter_list|,
name|uint32_t
name|time
parameter_list|,
name|wl_surface
modifier|*
name|surface
parameter_list|,
specifier|const
name|QPoint
modifier|&
name|pos
parameter_list|)
function_decl|;
DECL|member|mDisplay
name|QWaylandDisplay
modifier|*
name|mDisplay
decl_stmt|;
DECL|member|mData
name|QMimeData
modifier|*
name|mData
decl_stmt|;
DECL|member|mOffer
name|struct
name|wl_drag_offer
modifier|*
name|mOffer
decl_stmt|;
DECL|member|mOfferedTypes
name|QMimeData
name|mOfferedTypes
decl_stmt|;
comment|// no data in this one, just the formats
DECL|member|mFocusSurface
name|wl_surface
modifier|*
name|mFocusSurface
decl_stmt|;
DECL|member|mAccepted
name|bool
name|mAccepted
decl_stmt|;
DECL|member|mLastEventPos
name|QPoint
name|mLastEventPos
decl_stmt|;
friend|friend
class_decl|class
name|QWaylandDrag
class_decl|;
block|}
class|;
end_class
begin_decl_stmt
DECL|variable|dnd
specifier|static
name|QWaylandDrag
modifier|*
name|dnd
init|=
literal|0
decl_stmt|;
end_decl_stmt
begin_function
DECL|function|instance
name|QWaylandDrag
modifier|*
name|QWaylandDrag
operator|::
name|instance
parameter_list|(
name|QWaylandDisplay
modifier|*
name|display
parameter_list|)
block|{
if|if
condition|(
operator|!
name|dnd
condition|)
name|dnd
operator|=
operator|new
name|QWaylandDrag
argument_list|(
name|display
argument_list|)
expr_stmt|;
return|return
name|dnd
return|;
block|}
end_function
begin_constructor
DECL|function|QWaylandDrag
name|QWaylandDrag
operator|::
name|QWaylandDrag
parameter_list|(
name|QWaylandDisplay
modifier|*
name|display
parameter_list|)
member_init_list|:
name|mDisplay
argument_list|(
name|display
argument_list|)
member_init_list|,
name|mDropData
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|mCurrentDrag
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|mCurrentOffer
argument_list|(
literal|0
argument_list|)
block|{
name|mDropData
operator|=
operator|new
name|QMimeData
expr_stmt|;
block|}
end_constructor
begin_destructor
DECL|function|~QWaylandDrag
name|QWaylandDrag
operator|::
name|~
name|QWaylandDrag
parameter_list|()
block|{
operator|delete
name|mCurrentDrag
expr_stmt|;
operator|delete
name|mCurrentOffer
expr_stmt|;
operator|delete
name|mDropData
expr_stmt|;
block|}
end_destructor
begin_function
DECL|function|platformDropData
name|QMimeData
modifier|*
name|QWaylandDrag
operator|::
name|platformDropData
parameter_list|()
block|{
return|return
name|mDropData
return|;
block|}
end_function
begin_function
DECL|function|showDragPixmap
specifier|static
name|void
name|showDragPixmap
parameter_list|(
name|bool
name|show
parameter_list|)
block|{
name|QCursor
name|c
argument_list|(
name|QDragManager
operator|::
name|self
argument_list|()
operator|->
name|object
operator|->
name|pixmap
argument_list|()
argument_list|)
decl_stmt|;
name|QList
argument_list|<
name|QWeakPointer
argument_list|<
name|QPlatformCursor
argument_list|>
argument_list|>
name|cursors
init|=
name|QPlatformCursorPrivate
operator|::
name|getInstances
argument_list|()
decl_stmt|;
foreach|foreach
control|(
name|QWeakPointer
argument_list|<
name|QPlatformCursor
argument_list|>
name|cursor
decl|,
name|cursors
control|)
if|if
condition|(
name|cursor
condition|)
cast|static_cast
argument_list|<
name|QWaylandCursor
operator|*
argument_list|>
argument_list|(
name|cursor
operator|.
name|data
argument_list|()
argument_list|)
operator|->
name|setupPixmapCursor
argument_list|(
name|show
condition|?
operator|&
name|c
else|:
literal|0
argument_list|)
expr_stmt|;
block|}
end_function
begin_constructor
DECL|function|QWaylandDragWrapper
name|QWaylandDragWrapper
operator|::
name|QWaylandDragWrapper
parameter_list|(
name|QWaylandDisplay
modifier|*
name|display
parameter_list|,
name|QMimeData
modifier|*
name|data
parameter_list|)
member_init_list|:
name|mDisplay
argument_list|(
name|display
argument_list|)
member_init_list|,
name|mDrag
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|mData
argument_list|(
name|data
argument_list|)
block|{
name|QWaylandWindow
modifier|*
name|w
init|=
name|mDisplay
operator|->
name|inputDevices
argument_list|()
operator|.
name|at
argument_list|(
literal|0
argument_list|)
operator|->
name|pointerFocus
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
name|w
condition|)
block|{
name|qWarning
argument_list|(
literal|"QWaylandDragWrapper: No window with pointer focus?!"
argument_list|)
expr_stmt|;
return|return;
block|}
name|qDebug
argument_list|()
operator|<<
literal|"QWaylandDragWrapper"
operator|<<
name|data
operator|->
name|formats
argument_list|()
expr_stmt|;
name|struct
name|wl_shell
modifier|*
name|shell
init|=
name|display
operator|->
name|wl_shell
argument_list|()
decl_stmt|;
name|mDrag
operator|=
name|wl_shell_create_drag
argument_list|(
name|shell
argument_list|)
expr_stmt|;
name|wl_drag_add_listener
argument_list|(
name|mDrag
argument_list|,
operator|&
name|dragListener
argument_list|,
name|this
argument_list|)
expr_stmt|;
foreach|foreach
control|(
specifier|const
name|QString
modifier|&
name|format
decl|,
name|data
operator|->
name|formats
argument_list|()
control|)
name|wl_drag_offer
argument_list|(
name|mDrag
argument_list|,
name|format
operator|.
name|toLatin1
argument_list|()
operator|.
name|constData
argument_list|()
argument_list|)
expr_stmt|;
name|struct
name|timeval
name|tv
decl_stmt|;
name|gettimeofday
argument_list|(
operator|&
name|tv
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|wl_drag_activate
argument_list|(
name|mDrag
argument_list|,
name|w
operator|->
name|wl_surface
argument_list|()
argument_list|,
name|display
operator|->
name|inputDevices
argument_list|()
operator|.
name|at
argument_list|(
literal|0
argument_list|)
operator|->
name|wl_input_device
argument_list|()
argument_list|,
name|tv
operator|.
name|tv_sec
operator|*
literal|1000
operator|+
name|tv
operator|.
name|tv_usec
operator|/
literal|1000
argument_list|)
expr_stmt|;
name|showDragPixmap
argument_list|(
literal|true
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_destructor
DECL|function|~QWaylandDragWrapper
name|QWaylandDragWrapper
operator|::
name|~
name|QWaylandDragWrapper
parameter_list|()
block|{
name|QWaylandDrag
modifier|*
name|dragHandler
init|=
name|QWaylandDrag
operator|::
name|instance
argument_list|(
name|mDisplay
argument_list|)
decl_stmt|;
if|if
condition|(
name|dragHandler
operator|->
name|mCurrentDrag
operator|==
name|this
condition|)
name|dragHandler
operator|->
name|mCurrentDrag
operator|=
literal|0
expr_stmt|;
name|wl_drag_destroy
argument_list|(
name|mDrag
argument_list|)
expr_stmt|;
block|}
end_destructor
begin_decl_stmt
DECL|member|dragListener
specifier|const
name|wl_drag_listener
name|QWaylandDragWrapper
operator|::
name|dragListener
init|=
block|{
name|QWaylandDragWrapper
operator|::
name|target
block|,
name|QWaylandDragWrapper
operator|::
name|finish
block|,
name|QWaylandDragWrapper
operator|::
name|reject
block|}
decl_stmt|;
end_decl_stmt
begin_function
DECL|function|target
name|void
name|QWaylandDragWrapper
operator|::
name|target
parameter_list|(
name|void
modifier|*
name|data
parameter_list|,
name|wl_drag
modifier|*
name|drag
parameter_list|,
specifier|const
name|char
modifier|*
name|mimeType
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
name|drag
argument_list|)
expr_stmt|;
name|QWaylandDragWrapper
modifier|*
name|self
init|=
cast|static_cast
argument_list|<
name|QWaylandDragWrapper
operator|*
argument_list|>
argument_list|(
name|data
argument_list|)
decl_stmt|;
name|self
operator|->
name|mAcceptedType
operator|=
name|mimeType
condition|?
name|QString
operator|::
name|fromLatin1
argument_list|(
name|mimeType
argument_list|)
else|:
name|QString
argument_list|()
expr_stmt|;
name|qDebug
argument_list|()
operator|<<
literal|"target"
operator|<<
name|self
operator|->
name|mAcceptedType
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
name|mimeType
condition|)
name|manager
operator|->
name|global_accepted_action
operator|=
name|manager
operator|->
name|defaultAction
argument_list|(
name|manager
operator|->
name|possible_actions
argument_list|,
name|QGuiApplication
operator|::
name|keyboardModifiers
argument_list|()
argument_list|)
expr_stmt|;
else|else
name|manager
operator|->
name|global_accepted_action
operator|=
name|Qt
operator|::
name|IgnoreAction
expr_stmt|;
block|}
end_function
begin_function
DECL|function|finish
name|void
name|QWaylandDragWrapper
operator|::
name|finish
parameter_list|(
name|void
modifier|*
name|data
parameter_list|,
name|wl_drag
modifier|*
name|drag
parameter_list|,
name|int
name|fd
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
name|drag
argument_list|)
expr_stmt|;
name|QWaylandDragWrapper
modifier|*
name|self
init|=
cast|static_cast
argument_list|<
name|QWaylandDragWrapper
operator|*
argument_list|>
argument_list|(
name|data
argument_list|)
decl_stmt|;
name|qDebug
argument_list|()
operator|<<
literal|"finish"
operator|<<
name|self
operator|->
name|mAcceptedType
expr_stmt|;
if|if
condition|(
name|self
operator|->
name|mAcceptedType
operator|.
name|isEmpty
argument_list|()
condition|)
return|return;
comment|// no drag target was valid when the drag finished
name|QByteArray
name|content
init|=
name|self
operator|->
name|mData
operator|->
name|data
argument_list|(
name|self
operator|->
name|mAcceptedType
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|content
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|QFile
name|f
decl_stmt|;
if|if
condition|(
name|f
operator|.
name|open
argument_list|(
name|fd
argument_list|,
name|QIODevice
operator|::
name|WriteOnly
argument_list|)
condition|)
name|f
operator|.
name|write
argument_list|(
name|content
argument_list|)
expr_stmt|;
block|}
name|close
argument_list|(
name|fd
argument_list|)
expr_stmt|;
comment|// Drag finished on source side with drop.
name|QDragManager
operator|::
name|self
argument_list|()
operator|->
name|stopDrag
argument_list|()
expr_stmt|;
name|showDragPixmap
argument_list|(
literal|false
argument_list|)
expr_stmt|;
operator|delete
name|self
expr_stmt|;
name|qDebug
argument_list|()
operator|<<
literal|" *** DRAG OVER WITH DROP"
expr_stmt|;
block|}
end_function
begin_function
DECL|function|reject
name|void
name|QWaylandDragWrapper
operator|::
name|reject
parameter_list|(
name|void
modifier|*
name|data
parameter_list|,
name|wl_drag
modifier|*
name|drag
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
name|drag
argument_list|)
expr_stmt|;
name|QWaylandDragWrapper
modifier|*
name|self
init|=
cast|static_cast
argument_list|<
name|QWaylandDragWrapper
operator|*
argument_list|>
argument_list|(
name|data
argument_list|)
decl_stmt|;
name|self
operator|->
name|mAcceptedType
operator|=
name|QString
argument_list|()
expr_stmt|;
name|qDebug
argument_list|()
operator|<<
literal|"reject"
expr_stmt|;
name|QDragManager
operator|::
name|self
argument_list|()
operator|->
name|global_accepted_action
operator|=
name|Qt
operator|::
name|IgnoreAction
expr_stmt|;
block|}
end_function
begin_constructor
DECL|function|QWaylandDragOfferWrapper
name|QWaylandDragOfferWrapper
operator|::
name|QWaylandDragOfferWrapper
parameter_list|(
name|QWaylandDisplay
modifier|*
name|display
parameter_list|,
name|QMimeData
modifier|*
name|data
parameter_list|,
name|uint32_t
name|id
parameter_list|)
member_init_list|:
name|mDisplay
argument_list|(
name|display
argument_list|)
member_init_list|,
name|mData
argument_list|(
name|data
argument_list|)
member_init_list|,
name|mOffer
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|mFocusSurface
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|mAccepted
argument_list|(
literal|false
argument_list|)
block|{
name|mOffer
operator|=
name|wl_drag_offer_create
argument_list|(
name|mDisplay
operator|->
name|wl_display
argument_list|()
argument_list|,
name|id
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|wl_drag_offer_add_listener
argument_list|(
name|mOffer
argument_list|,
operator|&
name|dragOfferListener
argument_list|,
name|this
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_destructor
DECL|function|~QWaylandDragOfferWrapper
name|QWaylandDragOfferWrapper
operator|::
name|~
name|QWaylandDragOfferWrapper
parameter_list|()
block|{
name|QWaylandDrag
modifier|*
name|dragHandler
init|=
name|QWaylandDrag
operator|::
name|instance
argument_list|(
name|mDisplay
argument_list|)
decl_stmt|;
if|if
condition|(
name|dragHandler
operator|->
name|mCurrentOffer
operator|==
name|this
condition|)
name|dragHandler
operator|->
name|mCurrentOffer
operator|=
literal|0
expr_stmt|;
name|wl_drag_offer_destroy
argument_list|(
name|mOffer
argument_list|)
expr_stmt|;
block|}
end_destructor
begin_decl_stmt
DECL|member|dragOfferListener
specifier|const
name|wl_drag_offer_listener
name|QWaylandDragOfferWrapper
operator|::
name|dragOfferListener
init|=
block|{
name|QWaylandDragOfferWrapper
operator|::
name|offer
block|,
name|QWaylandDragOfferWrapper
operator|::
name|pointerFocus
block|,
name|QWaylandDragOfferWrapper
operator|::
name|motion
block|,
name|QWaylandDragOfferWrapper
operator|::
name|drop
block|}
decl_stmt|;
end_decl_stmt
begin_function
DECL|function|offer
name|void
name|QWaylandDragOfferWrapper
operator|::
name|offer
parameter_list|(
name|void
modifier|*
name|data
parameter_list|,
name|struct
name|wl_drag_offer
modifier|*
name|offer
parameter_list|,
specifier|const
name|char
modifier|*
name|mimeType
parameter_list|)
block|{
comment|// Called for each type before pointerFocus.
name|Q_UNUSED
argument_list|(
name|offer
argument_list|)
expr_stmt|;
name|QWaylandDragOfferWrapper
modifier|*
name|self
init|=
cast|static_cast
argument_list|<
name|QWaylandDragOfferWrapper
operator|*
argument_list|>
argument_list|(
name|data
argument_list|)
decl_stmt|;
name|self
operator|->
name|mOfferedTypes
operator|.
name|setData
argument_list|(
name|QString
operator|::
name|fromLatin1
argument_list|(
name|mimeType
argument_list|)
argument_list|,
name|QByteArray
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|pointerFocus
name|void
name|QWaylandDragOfferWrapper
operator|::
name|pointerFocus
parameter_list|(
name|void
modifier|*
name|data
parameter_list|,
name|struct
name|wl_drag_offer
modifier|*
name|offer
parameter_list|,
name|uint32_t
name|time
parameter_list|,
name|wl_surface
modifier|*
name|surface
parameter_list|,
name|int32_t
name|x
parameter_list|,
name|int32_t
name|y
parameter_list|,
name|int32_t
name|surfaceX
parameter_list|,
name|int32_t
name|surfaceY
parameter_list|)
block|{
name|qDebug
argument_list|()
operator|<<
literal|"pointerFocus"
operator|<<
name|surface
operator|<<
name|x
operator|<<
name|y
operator|<<
name|surfaceX
operator|<<
name|surfaceY
expr_stmt|;
name|QWaylandDragOfferWrapper
modifier|*
name|self
init|=
cast|static_cast
argument_list|<
name|QWaylandDragOfferWrapper
operator|*
argument_list|>
argument_list|(
name|data
argument_list|)
decl_stmt|;
name|QWaylandDrag
modifier|*
name|mgr
init|=
name|QWaylandDrag
operator|::
name|instance
argument_list|(
name|self
operator|->
name|mDisplay
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|surface
condition|)
block|{
if|if
condition|(
name|self
operator|->
name|mFocusSurface
condition|)
block|{
comment|// This is a DragLeave.
name|QWindow
modifier|*
name|window
init|=
cast|static_cast
argument_list|<
name|QWaylandWindow
operator|*
argument_list|>
argument_list|(
name|wl_surface_get_user_data
argument_list|(
name|self
operator|->
name|mFocusSurface
argument_list|)
argument_list|)
operator|->
name|window
argument_list|()
decl_stmt|;
name|QWindowSystemInterface
operator|::
name|handleDrag
argument_list|(
name|window
argument_list|,
literal|0
argument_list|,
name|QPoint
argument_list|()
argument_list|)
expr_stmt|;
if|if
condition|(
name|self
operator|->
name|mAccepted
condition|)
block|{
name|wl_drag_offer_reject
argument_list|(
name|offer
argument_list|)
expr_stmt|;
name|self
operator|->
name|mAccepted
operator|=
literal|false
expr_stmt|;
block|}
if|if
condition|(
operator|!
name|mgr
operator|->
name|mCurrentDrag
condition|)
comment|// no drag -> this is not the source side -> offer can be destroyed
operator|delete
name|mgr
operator|->
name|mCurrentOffer
expr_stmt|;
block|}
else|else
block|{
comment|// Drag finished on source side without drop.
name|QDragManager
operator|::
name|self
argument_list|()
operator|->
name|stopDrag
argument_list|()
expr_stmt|;
name|showDragPixmap
argument_list|(
literal|false
argument_list|)
expr_stmt|;
operator|delete
name|mgr
operator|->
name|mCurrentDrag
expr_stmt|;
name|qDebug
argument_list|()
operator|<<
literal|" *** DRAG OVER WITHOUT DROP"
expr_stmt|;
block|}
block|}
name|self
operator|->
name|mFocusSurface
operator|=
name|surface
expr_stmt|;
comment|// This is a DragMove or DragEnter+DragMove.
if|if
condition|(
name|surface
condition|)
name|self
operator|->
name|sendEventToWindow
argument_list|(
name|offer
argument_list|,
name|time
argument_list|,
name|surface
argument_list|,
name|QPoint
argument_list|(
name|surfaceX
argument_list|,
name|surfaceY
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|motion
name|void
name|QWaylandDragOfferWrapper
operator|::
name|motion
parameter_list|(
name|void
modifier|*
name|data
parameter_list|,
name|struct
name|wl_drag_offer
modifier|*
name|offer
parameter_list|,
name|uint32_t
name|time
parameter_list|,
name|int32_t
name|x
parameter_list|,
name|int32_t
name|y
parameter_list|,
name|int32_t
name|surfaceX
parameter_list|,
name|int32_t
name|surfaceY
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
name|x
argument_list|)
expr_stmt|;
name|Q_UNUSED
argument_list|(
name|y
argument_list|)
expr_stmt|;
name|QWaylandDragOfferWrapper
modifier|*
name|self
init|=
cast|static_cast
argument_list|<
name|QWaylandDragOfferWrapper
operator|*
argument_list|>
argument_list|(
name|data
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|self
operator|->
name|mFocusSurface
condition|)
return|return;
comment|//    qDebug()<< "motion"<< self->mFocusSurface<< x<< y<< surfaceX<< surfaceY;
name|self
operator|->
name|sendEventToWindow
argument_list|(
name|offer
argument_list|,
name|time
argument_list|,
name|self
operator|->
name|mFocusSurface
argument_list|,
name|QPoint
argument_list|(
name|surfaceX
argument_list|,
name|surfaceY
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|sendEventToWindow
name|void
name|QWaylandDragOfferWrapper
operator|::
name|sendEventToWindow
parameter_list|(
name|struct
name|wl_drag_offer
modifier|*
name|offer
parameter_list|,
name|uint32_t
name|time
parameter_list|,
name|wl_surface
modifier|*
name|surface
parameter_list|,
specifier|const
name|QPoint
modifier|&
name|pos
parameter_list|)
block|{
name|QWindow
modifier|*
name|window
init|=
cast|static_cast
argument_list|<
name|QWaylandWindow
operator|*
argument_list|>
argument_list|(
name|wl_surface_get_user_data
argument_list|(
name|surface
argument_list|)
argument_list|)
operator|->
name|window
argument_list|()
decl_stmt|;
name|Qt
operator|::
name|DropAction
name|action
init|=
name|QWindowSystemInterface
operator|::
name|handleDrag
argument_list|(
name|window
argument_list|,
operator|&
name|mOfferedTypes
argument_list|,
name|pos
argument_list|)
decl_stmt|;
name|bool
name|accepted
init|=
operator|(
name|action
operator|!=
name|Qt
operator|::
name|IgnoreAction
operator|&&
operator|!
name|mOfferedTypes
operator|.
name|formats
argument_list|()
operator|.
name|isEmpty
argument_list|()
operator|)
decl_stmt|;
if|if
condition|(
name|accepted
operator|!=
name|mAccepted
condition|)
block|{
name|mAccepted
operator|=
name|accepted
expr_stmt|;
if|if
condition|(
name|mAccepted
condition|)
block|{
comment|// What can we do, just accept the first type...
name|QByteArray
name|ba
init|=
name|mOfferedTypes
operator|.
name|formats
argument_list|()
operator|.
name|first
argument_list|()
operator|.
name|toLatin1
argument_list|()
decl_stmt|;
name|qDebug
argument_list|()
operator|<<
literal|"wl_drag_offer_accept"
operator|<<
name|ba
expr_stmt|;
name|wl_drag_offer_accept
argument_list|(
name|offer
argument_list|,
name|time
argument_list|,
name|ba
operator|.
name|constData
argument_list|()
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|qDebug
argument_list|()
operator|<<
literal|"wl_drag_offer_reject"
expr_stmt|;
name|wl_drag_offer_reject
argument_list|(
name|offer
argument_list|)
expr_stmt|;
block|}
block|}
name|mLastEventPos
operator|=
name|pos
expr_stmt|;
block|}
end_function
begin_function
DECL|function|drop
name|void
name|QWaylandDragOfferWrapper
operator|::
name|drop
parameter_list|(
name|void
modifier|*
name|data
parameter_list|,
name|struct
name|wl_drag_offer
modifier|*
name|offer
parameter_list|)
block|{
name|QWaylandDragOfferWrapper
modifier|*
name|self
init|=
cast|static_cast
argument_list|<
name|QWaylandDragOfferWrapper
operator|*
argument_list|>
argument_list|(
name|data
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|self
operator|->
name|mAccepted
condition|)
block|{
name|wl_drag_offer_reject
argument_list|(
name|offer
argument_list|)
expr_stmt|;
return|return;
block|}
name|QWaylandDrag
modifier|*
name|mgr
init|=
name|QWaylandDrag
operator|::
name|instance
argument_list|(
name|self
operator|->
name|mDisplay
argument_list|)
decl_stmt|;
name|QMimeData
modifier|*
name|mimeData
init|=
name|QWaylandDrag
operator|::
name|instance
argument_list|(
name|self
operator|->
name|mDisplay
argument_list|)
operator|->
name|platformDropData
argument_list|()
decl_stmt|;
name|mimeData
operator|->
name|clear
argument_list|()
expr_stmt|;
if|if
condition|(
name|mgr
operator|->
name|mCurrentDrag
condition|)
block|{
comment|// means this offer is the client's own
name|QMimeData
modifier|*
name|localData
init|=
name|mgr
operator|->
name|mCurrentDrag
operator|->
name|mimeData
argument_list|()
decl_stmt|;
foreach|foreach
control|(
specifier|const
name|QString
modifier|&
name|format
decl|,
name|localData
operator|->
name|formats
argument_list|()
control|)
name|mimeData
operator|->
name|setData
argument_list|(
name|format
argument_list|,
name|localData
operator|->
name|data
argument_list|(
name|format
argument_list|)
argument_list|)
expr_stmt|;
name|QWindow
modifier|*
name|window
init|=
cast|static_cast
argument_list|<
name|QWaylandWindow
operator|*
argument_list|>
argument_list|(
name|wl_surface_get_user_data
argument_list|(
name|self
operator|->
name|mFocusSurface
argument_list|)
argument_list|)
operator|->
name|window
argument_list|()
decl_stmt|;
name|QWindowSystemInterface
operator|::
name|handleDrop
argument_list|(
name|window
argument_list|,
name|mimeData
argument_list|,
name|self
operator|->
name|mLastEventPos
argument_list|)
expr_stmt|;
comment|// Drag finished with drop (source == target).
name|QDragManager
operator|::
name|self
argument_list|()
operator|->
name|stopDrag
argument_list|()
expr_stmt|;
name|showDragPixmap
argument_list|(
literal|false
argument_list|)
expr_stmt|;
operator|delete
name|mgr
operator|->
name|mCurrentOffer
expr_stmt|;
name|qDebug
argument_list|()
operator|<<
literal|" *** DRAG OVER WITH DROP, SOURCE == TARGET"
expr_stmt|;
block|}
else|else
block|{
comment|// ### TODO
comment|// This is a bit broken: The QMimeData will only contain the data for
comment|// the first type. The Wayland protocol and QDropEvents/QMimeData do not
comment|// match perfectly at the moment.
name|QString
name|format
init|=
name|self
operator|->
name|mOfferedTypes
operator|.
name|formats
argument_list|()
operator|.
name|first
argument_list|()
decl_stmt|;
name|QByteArray
name|mimeTypeBa
init|=
name|format
operator|.
name|toLatin1
argument_list|()
decl_stmt|;
name|int
name|pipefd
index|[
literal|2
index|]
decl_stmt|;
if|if
condition|(
name|pipe
argument_list|(
name|pipefd
argument_list|)
operator|==
operator|-
literal|1
condition|)
block|{
name|qWarning
argument_list|(
literal|"QWaylandDragOfferWrapper: pipe() failed"
argument_list|)
expr_stmt|;
return|return;
block|}
name|fcntl
argument_list|(
name|pipefd
index|[
literal|0
index|]
argument_list|,
name|F_SETFL
argument_list|,
name|fcntl
argument_list|(
name|pipefd
index|[
literal|0
index|]
argument_list|,
name|F_GETFL
argument_list|,
literal|0
argument_list|)
operator||
name|O_NONBLOCK
argument_list|)
expr_stmt|;
name|wl_drag_offer_receive
argument_list|(
name|offer
argument_list|,
name|pipefd
index|[
literal|1
index|]
argument_list|)
expr_stmt|;
name|mgr
operator|->
name|mPipeData
operator|.
name|clear
argument_list|()
expr_stmt|;
name|mgr
operator|->
name|mMimeFormat
operator|=
name|format
expr_stmt|;
name|mgr
operator|->
name|mPipeWriteEnd
operator|=
name|pipefd
index|[
literal|1
index|]
expr_stmt|;
name|mgr
operator|->
name|mPipeWatcher
operator|=
operator|new
name|QSocketNotifier
argument_list|(
name|pipefd
index|[
literal|0
index|]
argument_list|,
name|QSocketNotifier
operator|::
name|Read
argument_list|)
expr_stmt|;
name|QObject
operator|::
name|connect
argument_list|(
name|mgr
operator|->
name|mPipeWatcher
argument_list|,
name|SIGNAL
argument_list|(
name|activated
argument_list|(
name|int
argument_list|)
argument_list|)
argument_list|,
name|mgr
argument_list|,
name|SLOT
argument_list|(
name|pipeReadable
argument_list|(
name|int
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|pipeReadable
name|void
name|QWaylandDrag
operator|::
name|pipeReadable
parameter_list|(
name|int
name|fd
parameter_list|)
block|{
if|if
condition|(
name|mPipeWriteEnd
condition|)
block|{
name|close
argument_list|(
name|mPipeWriteEnd
argument_list|)
expr_stmt|;
name|mPipeWriteEnd
operator|=
literal|0
expr_stmt|;
block|}
name|char
name|buf
index|[
literal|256
index|]
decl_stmt|;
name|int
name|n
decl_stmt|;
while|while
condition|(
operator|(
name|n
operator|=
name|read
argument_list|(
name|fd
argument_list|,
operator|&
name|buf
argument_list|,
sizeof|sizeof
name|buf
argument_list|)
operator|)
operator|>
literal|0
operator|||
name|errno
operator|==
name|EINTR
condition|)
if|if
condition|(
name|n
operator|>
literal|0
condition|)
name|mPipeData
operator|.
name|append
argument_list|(
name|buf
argument_list|,
name|n
argument_list|)
expr_stmt|;
if|if
condition|(
name|n
operator|==
operator|-
literal|1
operator|&&
operator|(
name|errno
operator|==
name|EAGAIN
operator|||
name|errno
operator|==
name|EWOULDBLOCK
operator|)
condition|)
return|return;
operator|delete
name|mPipeWatcher
expr_stmt|;
name|close
argument_list|(
name|fd
argument_list|)
expr_stmt|;
name|QMimeData
modifier|*
name|mimeData
init|=
name|platformDropData
argument_list|()
decl_stmt|;
name|mimeData
operator|->
name|setData
argument_list|(
name|mMimeFormat
argument_list|,
name|mPipeData
argument_list|)
expr_stmt|;
foreach|foreach
control|(
specifier|const
name|QString
modifier|&
name|format
decl|,
name|mimeData
operator|->
name|formats
argument_list|()
control|)
name|qDebug
argument_list|()
operator|<<
literal|"  got type"
operator|<<
name|format
operator|<<
literal|"with data"
operator|<<
name|mimeData
operator|->
name|data
argument_list|(
name|format
argument_list|)
expr_stmt|;
name|QWindow
modifier|*
name|window
init|=
cast|static_cast
argument_list|<
name|QWaylandWindow
operator|*
argument_list|>
argument_list|(
name|wl_surface_get_user_data
argument_list|(
name|mCurrentOffer
operator|->
name|mFocusSurface
argument_list|)
argument_list|)
operator|->
name|window
argument_list|()
decl_stmt|;
name|QWindowSystemInterface
operator|::
name|handleDrop
argument_list|(
name|window
argument_list|,
name|mimeData
argument_list|,
name|mCurrentOffer
operator|->
name|mLastEventPos
argument_list|)
expr_stmt|;
comment|// Drag finished on target side with drop.
operator|delete
name|mCurrentOffer
expr_stmt|;
name|qDebug
argument_list|()
operator|<<
literal|" *** DRAG OVER ON TARGET WITH DROP"
expr_stmt|;
block|}
end_function
begin_function
DECL|function|createDragOffer
name|void
name|QWaylandDrag
operator|::
name|createDragOffer
parameter_list|(
name|uint32_t
name|id
parameter_list|)
block|{
operator|delete
name|mCurrentOffer
expr_stmt|;
name|mCurrentOffer
operator|=
operator|new
name|QWaylandDragOfferWrapper
argument_list|(
name|mDisplay
argument_list|,
name|mDropData
argument_list|,
name|id
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|startDrag
name|void
name|QWaylandDrag
operator|::
name|startDrag
parameter_list|()
block|{
name|QDragManager
modifier|*
name|manager
init|=
name|QDragManager
operator|::
name|self
argument_list|()
decl_stmt|;
comment|// No need for the traditional desktop-oriented event handling in QDragManager.
name|manager
operator|->
name|unmanageEvents
argument_list|()
expr_stmt|;
operator|delete
name|mCurrentDrag
expr_stmt|;
name|mCurrentDrag
operator|=
operator|new
name|QWaylandDragWrapper
argument_list|(
name|mDisplay
argument_list|,
name|manager
operator|->
name|dropData
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
end_unit
