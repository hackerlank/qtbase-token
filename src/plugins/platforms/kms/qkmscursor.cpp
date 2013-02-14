begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_comment
comment|//#include<QDebug>
end_comment
begin_include
include|#
directive|include
file|"qkmscursor.h"
end_include
begin_include
include|#
directive|include
file|"qkmsscreen.h"
end_include
begin_include
include|#
directive|include
file|"qkmsdevice.h"
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_constructor
DECL|function|QKmsCursor
name|QKmsCursor
operator|::
name|QKmsCursor
parameter_list|(
name|QKmsScreen
modifier|*
name|screen
parameter_list|)
member_init_list|:
name|m_screen
argument_list|(
name|screen
argument_list|)
member_init_list|,
name|m_graphicsBufferManager
argument_list|(
name|screen
operator|->
name|device
argument_list|()
operator|->
name|gbmDevice
argument_list|()
argument_list|)
member_init_list|,
name|m_cursorBufferObject
argument_list|(
name|gbm_bo_create
argument_list|(
name|m_graphicsBufferManager
argument_list|,
literal|64
argument_list|,
literal|64
argument_list|,
name|GBM_FORMAT_ARGB8888
argument_list|,
name|GBM_BO_USE_CURSOR_64X64
operator||
name|GBM_BO_USE_WRITE
argument_list|)
argument_list|)
member_init_list|,
name|m_cursorImage
argument_list|(
operator|new
name|QPlatformCursorImage
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
argument_list|)
member_init_list|,
name|m_moved
argument_list|(
literal|false
argument_list|)
block|{ }
end_constructor
begin_destructor
DECL|function|~QKmsCursor
name|QKmsCursor
operator|::
name|~
name|QKmsCursor
parameter_list|()
block|{
name|drmModeSetCursor
argument_list|(
name|m_screen
operator|->
name|device
argument_list|()
operator|->
name|fd
argument_list|()
argument_list|,
name|m_screen
operator|->
name|crtcId
argument_list|()
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|gbm_bo_destroy
argument_list|(
name|m_cursorBufferObject
argument_list|)
expr_stmt|;
block|}
end_destructor
begin_function
DECL|function|pointerEvent
name|void
name|QKmsCursor
operator|::
name|pointerEvent
parameter_list|(
specifier|const
name|QMouseEvent
modifier|&
name|event
parameter_list|)
block|{
name|m_moved
operator|=
literal|true
expr_stmt|;
name|int
name|status
init|=
name|drmModeMoveCursor
argument_list|(
name|m_screen
operator|->
name|device
argument_list|()
operator|->
name|fd
argument_list|()
argument_list|,
name|m_screen
operator|->
name|crtcId
argument_list|()
argument_list|,
name|event
operator|.
name|globalX
argument_list|()
argument_list|,
name|event
operator|.
name|globalY
argument_list|()
argument_list|)
decl_stmt|;
if|if
condition|(
name|status
condition|)
block|{
name|qWarning
argument_list|(
literal|"failed to move cursor: %d"
argument_list|,
name|status
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|changeCursor
name|void
name|QKmsCursor
operator|::
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
block|{
name|Q_UNUSED
argument_list|(
argument|window
argument_list|)
if|if
condition|(
operator|!
name|m_moved
condition|)
name|drmModeMoveCursor
argument_list|(
name|m_screen
operator|->
name|device
argument_list|()
operator|->
name|fd
argument_list|()
argument_list|,
name|m_screen
operator|->
name|crtcId
argument_list|()
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
specifier|const
name|Qt
operator|::
name|CursorShape
name|newShape
init|=
name|windowCursor
condition|?
name|windowCursor
operator|->
name|shape
argument_list|()
else|:
name|Qt
operator|::
name|ArrowCursor
decl_stmt|;
if|if
condition|(
name|newShape
operator|!=
name|Qt
operator|::
name|BitmapCursor
condition|)
block|{
name|m_cursorImage
operator|->
name|set
argument_list|(
name|newShape
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|m_cursorImage
operator|->
name|set
argument_list|(
name|windowCursor
operator|->
name|pixmap
argument_list|()
operator|.
name|toImage
argument_list|()
argument_list|,
name|windowCursor
operator|->
name|hotSpot
argument_list|()
operator|.
name|x
argument_list|()
argument_list|,
name|windowCursor
operator|->
name|hotSpot
argument_list|()
operator|.
name|y
argument_list|()
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
operator|(
name|m_cursorImage
operator|->
name|image
argument_list|()
operator|->
name|width
argument_list|()
operator|>
literal|64
operator|)
operator|||
operator|(
name|m_cursorImage
operator|->
name|image
argument_list|()
operator|->
name|width
argument_list|()
operator|>
literal|64
operator|)
condition|)
name|qWarning
argument_list|(
literal|"Warning: cursor larger than 64x64; only 64x64 pixels will be shown."
argument_list|)
expr_stmt|;
name|QImage
name|cursorImage
init|=
name|m_cursorImage
operator|->
name|image
argument_list|()
operator|->
name|convertToFormat
argument_list|(
name|QImage
operator|::
name|Format_ARGB32
argument_list|)
operator|.
name|copy
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|64
argument_list|,
literal|64
argument_list|)
decl_stmt|;
name|gbm_bo_write
argument_list|(
name|m_cursorBufferObject
argument_list|,
name|cursorImage
operator|.
name|constBits
argument_list|()
argument_list|,
name|cursorImage
operator|.
name|byteCount
argument_list|()
argument_list|)
expr_stmt|;
name|quint32
name|handle
init|=
name|gbm_bo_get_handle
argument_list|(
name|m_cursorBufferObject
argument_list|)
operator|.
name|u32
decl_stmt|;
name|int
name|status
init|=
name|drmModeSetCursor
argument_list|(
name|m_screen
operator|->
name|device
argument_list|()
operator|->
name|fd
argument_list|()
argument_list|,
name|m_screen
operator|->
name|crtcId
argument_list|()
argument_list|,
name|handle
argument_list|,
literal|64
argument_list|,
literal|64
argument_list|)
decl_stmt|;
if|if
condition|(
name|status
condition|)
block|{
name|qWarning
argument_list|(
literal|"failed to set cursor: %d"
argument_list|,
name|status
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
