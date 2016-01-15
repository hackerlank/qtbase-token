begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qoffscreencommon.h"
end_include
begin_include
include|#
directive|include
file|"qoffscreenwindow.h"
end_include
begin_include
include|#
directive|include
file|<QtGui/private/qpixmap_raster_p.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/private/qguiapplication_p.h>
end_include
begin_include
include|#
directive|include
file|<qpa/qplatformcursor.h>
end_include
begin_include
include|#
directive|include
file|<qpa/qplatformwindow.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|member|windowContainingCursor
name|QPlatformWindow
modifier|*
name|QOffscreenScreen
operator|::
name|windowContainingCursor
init|=
literal|0
decl_stmt|;
end_decl_stmt
begin_class
DECL|class|QOffscreenCursor
class|class
name|QOffscreenCursor
super|:
specifier|public
name|QPlatformCursor
block|{
public|public:
DECL|function|QOffscreenCursor
name|QOffscreenCursor
parameter_list|()
member_init_list|:
name|m_pos
argument_list|(
literal|10
argument_list|,
literal|10
argument_list|)
block|{}
name|QPoint
name|pos
parameter_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|{
return|return
name|m_pos
return|;
block|}
name|void
name|setPos
parameter_list|(
specifier|const
name|QPoint
modifier|&
name|pos
parameter_list|)
name|Q_DECL_OVERRIDE
block|{
name|m_pos
operator|=
name|pos
expr_stmt|;
name|QWindowList
name|wl
init|=
name|QGuiApplication
operator|::
name|topLevelWindows
argument_list|()
decl_stmt|;
name|QWindow
modifier|*
name|containing
init|=
literal|0
decl_stmt|;
foreach|foreach
control|(
name|QWindow
modifier|*
name|w
decl|,
name|wl
control|)
block|{
if|if
condition|(
name|w
operator|->
name|type
argument_list|()
operator|!=
name|Qt
operator|::
name|Desktop
operator|&&
name|w
operator|->
name|isExposed
argument_list|()
operator|&&
name|w
operator|->
name|geometry
argument_list|()
operator|.
name|contains
argument_list|(
name|pos
argument_list|)
condition|)
block|{
name|containing
operator|=
name|w
expr_stmt|;
break|break;
block|}
block|}
name|QPoint
name|local
init|=
name|pos
decl_stmt|;
if|if
condition|(
name|containing
condition|)
name|local
operator|-=
name|containing
operator|->
name|position
argument_list|()
expr_stmt|;
name|QWindow
modifier|*
name|previous
init|=
name|QOffscreenScreen
operator|::
name|windowContainingCursor
condition|?
name|QOffscreenScreen
operator|::
name|windowContainingCursor
operator|->
name|window
argument_list|()
else|:
literal|0
decl_stmt|;
if|if
condition|(
name|containing
operator|!=
name|previous
condition|)
name|QWindowSystemInterface
operator|::
name|handleEnterLeaveEvent
argument_list|(
name|containing
argument_list|,
name|previous
argument_list|,
name|local
argument_list|,
name|pos
argument_list|)
expr_stmt|;
name|QWindowSystemInterface
operator|::
name|handleMouseEvent
argument_list|(
name|containing
argument_list|,
name|local
argument_list|,
name|pos
argument_list|,
name|QGuiApplication
operator|::
name|mouseButtons
argument_list|()
argument_list|,
name|QGuiApplication
operator|::
name|keyboardModifiers
argument_list|()
argument_list|)
expr_stmt|;
name|QOffscreenScreen
operator|::
name|windowContainingCursor
operator|=
name|containing
condition|?
name|containing
operator|->
name|handle
argument_list|()
else|:
literal|0
expr_stmt|;
block|}
ifndef|#
directive|ifndef
name|QT_NO_CURSOR
name|void
name|changeCursor
parameter_list|(
name|QCursor
modifier|*
name|windowCursor
parameter_list|,
name|QWindow
modifier|*
name|window
parameter_list|)
name|Q_DECL_OVERRIDE
block|{
name|Q_UNUSED
argument_list|(
name|windowCursor
argument_list|)
expr_stmt|;
name|Q_UNUSED
argument_list|(
name|window
argument_list|)
expr_stmt|;
block|}
endif|#
directive|endif
private|private:
DECL|member|m_pos
name|QPoint
name|m_pos
decl_stmt|;
block|}
class|;
end_class
begin_constructor
DECL|function|QOffscreenScreen
name|QOffscreenScreen
operator|::
name|QOffscreenScreen
parameter_list|()
member_init_list|:
name|m_geometry
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|800
argument_list|,
literal|600
argument_list|)
member_init_list|,
name|m_cursor
argument_list|(
operator|new
name|QOffscreenCursor
argument_list|)
block|{ }
end_constructor
begin_function
DECL|function|grabWindow
name|QPixmap
name|QOffscreenScreen
operator|::
name|grabWindow
parameter_list|(
name|WId
name|id
parameter_list|,
name|int
name|x
parameter_list|,
name|int
name|y
parameter_list|,
name|int
name|width
parameter_list|,
name|int
name|height
parameter_list|)
specifier|const
block|{
name|QRect
name|rect
argument_list|(
name|x
argument_list|,
name|y
argument_list|,
name|width
argument_list|,
name|height
argument_list|)
decl_stmt|;
name|QOffscreenWindow
modifier|*
name|window
init|=
name|QOffscreenWindow
operator|::
name|windowForWinId
argument_list|(
name|id
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|window
operator|||
name|window
operator|->
name|window
argument_list|()
operator|->
name|type
argument_list|()
operator|==
name|Qt
operator|::
name|Desktop
condition|)
block|{
name|QWindowList
name|wl
init|=
name|QGuiApplication
operator|::
name|topLevelWindows
argument_list|()
decl_stmt|;
name|QWindow
modifier|*
name|containing
init|=
literal|0
decl_stmt|;
foreach|foreach
control|(
name|QWindow
modifier|*
name|w
decl|,
name|wl
control|)
block|{
if|if
condition|(
name|w
operator|->
name|type
argument_list|()
operator|!=
name|Qt
operator|::
name|Desktop
operator|&&
name|w
operator|->
name|isExposed
argument_list|()
operator|&&
name|w
operator|->
name|geometry
argument_list|()
operator|.
name|contains
argument_list|(
name|rect
argument_list|)
condition|)
block|{
name|containing
operator|=
name|w
expr_stmt|;
break|break;
block|}
block|}
if|if
condition|(
operator|!
name|containing
condition|)
return|return
name|QPixmap
argument_list|()
return|;
name|id
operator|=
name|containing
operator|->
name|winId
argument_list|()
expr_stmt|;
name|rect
operator|=
name|rect
operator|.
name|translated
argument_list|(
operator|-
name|containing
operator|->
name|geometry
argument_list|()
operator|.
name|topLeft
argument_list|()
argument_list|)
expr_stmt|;
block|}
name|QOffscreenBackingStore
modifier|*
name|store
init|=
name|QOffscreenBackingStore
operator|::
name|backingStoreForWinId
argument_list|(
name|id
argument_list|)
decl_stmt|;
if|if
condition|(
name|store
condition|)
return|return
name|store
operator|->
name|grabWindow
argument_list|(
name|id
argument_list|,
name|rect
argument_list|)
return|;
return|return
name|QPixmap
argument_list|()
return|;
block|}
end_function
begin_constructor
DECL|function|QOffscreenBackingStore
name|QOffscreenBackingStore
operator|::
name|QOffscreenBackingStore
parameter_list|(
name|QWindow
modifier|*
name|window
parameter_list|)
member_init_list|:
name|QPlatformBackingStore
argument_list|(
name|window
argument_list|)
block|{ }
end_constructor
begin_destructor
DECL|function|~QOffscreenBackingStore
name|QOffscreenBackingStore
operator|::
name|~
name|QOffscreenBackingStore
parameter_list|()
block|{
name|clearHash
argument_list|()
expr_stmt|;
block|}
end_destructor
begin_function
DECL|function|paintDevice
name|QPaintDevice
modifier|*
name|QOffscreenBackingStore
operator|::
name|paintDevice
parameter_list|()
block|{
return|return
operator|&
name|m_image
return|;
block|}
end_function
begin_function
DECL|function|flush
name|void
name|QOffscreenBackingStore
operator|::
name|flush
parameter_list|(
name|QWindow
modifier|*
name|window
parameter_list|,
specifier|const
name|QRegion
modifier|&
name|region
parameter_list|,
specifier|const
name|QPoint
modifier|&
name|offset
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
name|region
argument_list|)
expr_stmt|;
if|if
condition|(
name|m_image
operator|.
name|size
argument_list|()
operator|.
name|isEmpty
argument_list|()
condition|)
return|return;
name|QSize
name|imageSize
init|=
name|m_image
operator|.
name|size
argument_list|()
decl_stmt|;
name|QRegion
name|clipped
init|=
name|QRect
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
name|window
operator|->
name|width
argument_list|()
argument_list|,
name|window
operator|->
name|height
argument_list|()
argument_list|)
decl_stmt|;
name|clipped
operator|&=
name|QRect
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
name|imageSize
operator|.
name|width
argument_list|()
argument_list|,
name|imageSize
operator|.
name|height
argument_list|()
argument_list|)
operator|.
name|translated
argument_list|(
operator|-
name|offset
argument_list|)
expr_stmt|;
name|QRect
name|bounds
init|=
name|clipped
operator|.
name|boundingRect
argument_list|()
operator|.
name|translated
argument_list|(
name|offset
argument_list|)
decl_stmt|;
if|if
condition|(
name|bounds
operator|.
name|isNull
argument_list|()
condition|)
return|return;
name|WId
name|id
init|=
name|window
operator|->
name|winId
argument_list|()
decl_stmt|;
name|m_windowAreaHash
index|[
name|id
index|]
operator|=
name|bounds
expr_stmt|;
name|m_backingStoreForWinIdHash
index|[
name|id
index|]
operator|=
name|this
expr_stmt|;
block|}
end_function
begin_function
DECL|function|resize
name|void
name|QOffscreenBackingStore
operator|::
name|resize
parameter_list|(
specifier|const
name|QSize
modifier|&
name|size
parameter_list|,
specifier|const
name|QRegion
modifier|&
parameter_list|)
block|{
name|QImage
operator|::
name|Format
name|format
init|=
name|QGuiApplication
operator|::
name|primaryScreen
argument_list|()
operator|->
name|handle
argument_list|()
operator|->
name|format
argument_list|()
decl_stmt|;
if|if
condition|(
name|m_image
operator|.
name|size
argument_list|()
operator|!=
name|size
condition|)
name|m_image
operator|=
name|QImage
argument_list|(
name|size
argument_list|,
name|format
argument_list|)
expr_stmt|;
name|clearHash
argument_list|()
expr_stmt|;
block|}
end_function
begin_function_decl
specifier|extern
name|void
name|qt_scrollRectInImage
parameter_list|(
name|QImage
modifier|&
name|img
parameter_list|,
specifier|const
name|QRect
modifier|&
name|rect
parameter_list|,
specifier|const
name|QPoint
modifier|&
name|offset
parameter_list|)
function_decl|;
end_function_decl
begin_function
DECL|function|scroll
name|bool
name|QOffscreenBackingStore
operator|::
name|scroll
parameter_list|(
specifier|const
name|QRegion
modifier|&
name|area
parameter_list|,
name|int
name|dx
parameter_list|,
name|int
name|dy
parameter_list|)
block|{
if|if
condition|(
name|m_image
operator|.
name|isNull
argument_list|()
condition|)
return|return
literal|false
return|;
specifier|const
name|QVector
argument_list|<
name|QRect
argument_list|>
name|rects
init|=
name|area
operator|.
name|rects
argument_list|()
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
name|rects
operator|.
name|size
argument_list|()
condition|;
operator|++
name|i
control|)
name|qt_scrollRectInImage
argument_list|(
name|m_image
argument_list|,
name|rects
operator|.
name|at
argument_list|(
name|i
argument_list|)
argument_list|,
name|QPoint
argument_list|(
name|dx
argument_list|,
name|dy
argument_list|)
argument_list|)
expr_stmt|;
return|return
literal|true
return|;
block|}
end_function
begin_function
DECL|function|grabWindow
name|QPixmap
name|QOffscreenBackingStore
operator|::
name|grabWindow
parameter_list|(
name|WId
name|window
parameter_list|,
specifier|const
name|QRect
modifier|&
name|rect
parameter_list|)
specifier|const
block|{
name|QRect
name|area
init|=
name|m_windowAreaHash
operator|.
name|value
argument_list|(
name|window
argument_list|,
name|QRect
argument_list|()
argument_list|)
decl_stmt|;
if|if
condition|(
name|area
operator|.
name|isNull
argument_list|()
condition|)
return|return
name|QPixmap
argument_list|()
return|;
name|QRect
name|adjusted
init|=
name|rect
decl_stmt|;
if|if
condition|(
name|adjusted
operator|.
name|width
argument_list|()
operator|<=
literal|0
condition|)
name|adjusted
operator|.
name|setWidth
argument_list|(
name|area
operator|.
name|width
argument_list|()
argument_list|)
expr_stmt|;
if|if
condition|(
name|adjusted
operator|.
name|height
argument_list|()
operator|<=
literal|0
condition|)
name|adjusted
operator|.
name|setHeight
argument_list|(
name|area
operator|.
name|height
argument_list|()
argument_list|)
expr_stmt|;
name|adjusted
operator|=
name|adjusted
operator|.
name|translated
argument_list|(
name|area
operator|.
name|topLeft
argument_list|()
argument_list|)
operator|&
name|area
expr_stmt|;
if|if
condition|(
name|adjusted
operator|.
name|isEmpty
argument_list|()
condition|)
return|return
name|QPixmap
argument_list|()
return|;
return|return
name|QPixmap
operator|::
name|fromImage
argument_list|(
name|m_image
operator|.
name|copy
argument_list|(
name|adjusted
argument_list|)
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|backingStoreForWinId
name|QOffscreenBackingStore
modifier|*
name|QOffscreenBackingStore
operator|::
name|backingStoreForWinId
parameter_list|(
name|WId
name|id
parameter_list|)
block|{
return|return
name|m_backingStoreForWinIdHash
operator|.
name|value
argument_list|(
name|id
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|clearHash
name|void
name|QOffscreenBackingStore
operator|::
name|clearHash
parameter_list|()
block|{
name|QList
argument_list|<
name|WId
argument_list|>
name|ids
init|=
name|m_windowAreaHash
operator|.
name|keys
argument_list|()
decl_stmt|;
foreach|foreach
control|(
name|WId
name|id
decl|,
name|ids
control|)
block|{
name|QHash
argument_list|<
name|WId
argument_list|,
name|QOffscreenBackingStore
modifier|*
argument_list|>
operator|::
name|iterator
name|it
init|=
name|m_backingStoreForWinIdHash
operator|.
name|find
argument_list|(
name|id
argument_list|)
decl_stmt|;
if|if
condition|(
name|it
operator|.
name|value
argument_list|()
operator|==
name|this
condition|)
name|m_backingStoreForWinIdHash
operator|.
name|remove
argument_list|(
name|id
argument_list|)
expr_stmt|;
block|}
name|m_windowAreaHash
operator|.
name|clear
argument_list|()
expr_stmt|;
block|}
end_function
begin_decl_stmt
DECL|member|m_backingStoreForWinIdHash
name|QHash
argument_list|<
name|WId
argument_list|,
name|QOffscreenBackingStore
modifier|*
argument_list|>
name|QOffscreenBackingStore
operator|::
name|m_backingStoreForWinIdHash
decl_stmt|;
end_decl_stmt
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
