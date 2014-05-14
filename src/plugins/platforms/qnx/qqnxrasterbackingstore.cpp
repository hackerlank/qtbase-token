begin_unit
begin_comment
comment|/*************************************************************************** ** ** Copyright (C) 2011 - 2013 BlackBerry Limited. All rights reserved. ** Contact: http://www.qt-project.org/legal ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qqnxrasterbackingstore.h"
end_include
begin_include
include|#
directive|include
file|"qqnxrasterwindow.h"
end_include
begin_include
include|#
directive|include
file|"qqnxscreen.h"
end_include
begin_include
include|#
directive|include
file|"qqnxglobal.h"
end_include
begin_include
include|#
directive|include
file|<QtCore/QDebug>
end_include
begin_include
include|#
directive|include
file|<errno.h>
end_include
begin_if
if|#
directive|if
name|defined
argument_list|(
name|QQNXRASTERBACKINGSTORE_DEBUG
argument_list|)
end_if
begin_define
DECL|macro|qRasterBackingStoreDebug
define|#
directive|define
name|qRasterBackingStoreDebug
value|qDebug
end_define
begin_else
else|#
directive|else
end_else
begin_define
DECL|macro|qRasterBackingStoreDebug
define|#
directive|define
name|qRasterBackingStoreDebug
value|QT_NO_QDEBUG_MACRO
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_constructor
DECL|function|QQnxRasterBackingStore
name|QQnxRasterBackingStore
operator|::
name|QQnxRasterBackingStore
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
member_init_list|,
name|m_hasUnflushedPaintOperations
argument_list|(
literal|false
argument_list|)
block|{
name|qRasterBackingStoreDebug
argument_list|()
operator|<<
name|Q_FUNC_INFO
operator|<<
literal|"w ="
operator|<<
name|window
expr_stmt|;
name|m_window
operator|=
name|window
expr_stmt|;
block|}
end_constructor
begin_destructor
DECL|function|~QQnxRasterBackingStore
name|QQnxRasterBackingStore
operator|::
name|~
name|QQnxRasterBackingStore
parameter_list|()
block|{
name|qRasterBackingStoreDebug
argument_list|()
operator|<<
name|Q_FUNC_INFO
operator|<<
literal|"w ="
operator|<<
name|window
argument_list|()
expr_stmt|;
block|}
end_destructor
begin_function
DECL|function|paintDevice
name|QPaintDevice
modifier|*
name|QQnxRasterBackingStore
operator|::
name|paintDevice
parameter_list|()
block|{
if|if
condition|(
name|platformWindow
argument_list|()
operator|&&
name|platformWindow
argument_list|()
operator|->
name|hasBuffers
argument_list|()
condition|)
return|return
name|platformWindow
argument_list|()
operator|->
name|renderBuffer
argument_list|()
operator|.
name|image
argument_list|()
return|;
return|return
literal|0
return|;
block|}
end_function
begin_function
DECL|function|flush
name|void
name|QQnxRasterBackingStore
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
argument|offset
argument_list|)
name|qRasterBackingStoreDebug
argument_list|()
operator|<<
name|Q_FUNC_INFO
operator|<<
literal|"w ="
operator|<<
name|this
operator|->
name|window
argument_list|()
expr_stmt|;
comment|// Sometimes this method is called even though there is nothing to be
comment|// flushed, for instance, after an expose event directly follows a
comment|// geometry change event.
if|if
condition|(
operator|!
name|m_hasUnflushedPaintOperations
condition|)
return|return;
name|QQnxWindow
modifier|*
name|targetWindow
init|=
literal|0
decl_stmt|;
if|if
condition|(
name|window
condition|)
name|targetWindow
operator|=
cast|static_cast
argument_list|<
name|QQnxWindow
operator|*
argument_list|>
argument_list|(
name|window
operator|->
name|handle
argument_list|()
argument_list|)
expr_stmt|;
comment|// we only need to flush the platformWindow backing store, since this is
comment|// the buffer where all drawing operations of all windows, including the
comment|// child windows, are performed; conceptually ,child windows have no buffers
comment|// (actually they do have a 1x1 placeholder buffer due to libscreen limitations),
comment|// since Qt will only draw to the backing store of the top-level window.
if|if
condition|(
operator|!
name|targetWindow
operator|||
name|targetWindow
operator|==
name|platformWindow
argument_list|()
condition|)
block|{
comment|// visit all pending scroll operations
for|for
control|(
name|int
name|i
init|=
name|m_scrollOpList
operator|.
name|size
argument_list|()
operator|-
literal|1
init|;
name|i
operator|>=
literal|0
condition|;
name|i
operator|--
control|)
block|{
comment|// do the scroll operation
name|ScrollOp
modifier|&
name|op
init|=
name|m_scrollOpList
index|[
name|i
index|]
decl_stmt|;
name|QRegion
name|srcArea
init|=
name|op
operator|.
name|totalArea
operator|.
name|intersected
argument_list|(
name|op
operator|.
name|totalArea
operator|.
name|translated
argument_list|(
operator|-
name|op
operator|.
name|dx
argument_list|,
operator|-
name|op
operator|.
name|dy
argument_list|)
argument_list|)
decl_stmt|;
name|platformWindow
argument_list|()
operator|->
name|scroll
argument_list|(
name|srcArea
argument_list|,
name|op
operator|.
name|dx
argument_list|,
name|op
operator|.
name|dy
argument_list|)
expr_stmt|;
block|}
comment|// clear all pending scroll operations
name|m_scrollOpList
operator|.
name|clear
argument_list|()
expr_stmt|;
comment|// update the display with newly rendered content
name|platformWindow
argument_list|()
operator|->
name|post
argument_list|(
name|region
argument_list|)
expr_stmt|;
block|}
name|m_hasUnflushedPaintOperations
operator|=
literal|false
expr_stmt|;
block|}
end_function
begin_function
DECL|function|resize
name|void
name|QQnxRasterBackingStore
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
name|staticContents
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
name|size
argument_list|)
expr_stmt|;
name|Q_UNUSED
argument_list|(
name|staticContents
argument_list|)
expr_stmt|;
name|qRasterBackingStoreDebug
argument_list|()
operator|<<
name|Q_FUNC_INFO
operator|<<
literal|"w ="
operator|<<
name|window
argument_list|()
operator|<<
literal|", s ="
operator|<<
name|size
expr_stmt|;
comment|// NOTE: defer resizing window buffers until next paint as
comment|// resize() can be called multiple times before a paint occurs
block|}
end_function
begin_function
DECL|function|scroll
name|bool
name|QQnxRasterBackingStore
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
name|qRasterBackingStoreDebug
argument_list|()
operator|<<
name|Q_FUNC_INFO
operator|<<
literal|"w ="
operator|<<
name|window
argument_list|()
expr_stmt|;
comment|// calculate entire region affected by scroll operation (src + dst)
name|QRegion
name|totalArea
init|=
name|area
operator|.
name|translated
argument_list|(
name|dx
argument_list|,
name|dy
argument_list|)
decl_stmt|;
name|totalArea
operator|+=
name|area
expr_stmt|;
name|m_hasUnflushedPaintOperations
operator|=
literal|true
expr_stmt|;
comment|// visit all pending scroll operations
for|for
control|(
name|int
name|i
init|=
name|m_scrollOpList
operator|.
name|size
argument_list|()
operator|-
literal|1
init|;
name|i
operator|>=
literal|0
condition|;
name|i
operator|--
control|)
block|{
name|ScrollOp
modifier|&
name|op
init|=
name|m_scrollOpList
index|[
name|i
index|]
decl_stmt|;
if|if
condition|(
name|op
operator|.
name|totalArea
operator|==
name|totalArea
condition|)
block|{
comment|// same area is being scrolled again - update delta
name|op
operator|.
name|dx
operator|+=
name|dx
expr_stmt|;
name|op
operator|.
name|dy
operator|+=
name|dy
expr_stmt|;
return|return
literal|true
return|;
block|}
elseif|else
if|if
condition|(
name|op
operator|.
name|totalArea
operator|.
name|intersects
argument_list|(
name|totalArea
argument_list|)
condition|)
block|{
comment|// current scroll overlaps previous scroll but is
comment|// not equal in area - just paint everything
name|qWarning
argument_list|(
literal|"QQNX: pending scroll operations overlap but not equal"
argument_list|)
expr_stmt|;
return|return
literal|false
return|;
block|}
block|}
comment|// create new scroll operation
name|m_scrollOpList
operator|.
name|append
argument_list|(
name|ScrollOp
argument_list|(
name|totalArea
argument_list|,
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
DECL|function|beginPaint
name|void
name|QQnxRasterBackingStore
operator|::
name|beginPaint
parameter_list|(
specifier|const
name|QRegion
modifier|&
name|region
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
name|region
argument_list|)
expr_stmt|;
name|qRasterBackingStoreDebug
argument_list|()
operator|<<
name|Q_FUNC_INFO
operator|<<
literal|"w ="
operator|<<
name|window
argument_list|()
expr_stmt|;
name|m_hasUnflushedPaintOperations
operator|=
literal|true
expr_stmt|;
name|platformWindow
argument_list|()
operator|->
name|adjustBufferSize
argument_list|()
expr_stmt|;
if|if
condition|(
name|window
argument_list|()
operator|->
name|requestedFormat
argument_list|()
operator|.
name|alphaBufferSize
argument_list|()
operator|!=
literal|0
condition|)
block|{
foreach|foreach
control|(
specifier|const
name|QRect
modifier|&
name|r
decl|,
name|region
operator|.
name|rects
argument_list|()
control|)
block|{
comment|// Clear transparent regions
specifier|const
name|int
name|bg
index|[]
init|=
block|{
name|SCREEN_BLIT_COLOR
block|,
literal|0x00000000
block|,
name|SCREEN_BLIT_DESTINATION_X
block|,
name|r
operator|.
name|x
argument_list|()
block|,
name|SCREEN_BLIT_DESTINATION_Y
block|,
name|r
operator|.
name|y
argument_list|()
block|,
name|SCREEN_BLIT_DESTINATION_WIDTH
block|,
name|r
operator|.
name|width
argument_list|()
block|,
name|SCREEN_BLIT_DESTINATION_HEIGHT
block|,
name|r
operator|.
name|height
argument_list|()
block|,
name|SCREEN_BLIT_END
block|}
decl_stmt|;
name|Q_SCREEN_CHECKERROR
argument_list|(
name|screen_fill
argument_list|(
name|platformWindow
argument_list|()
operator|->
name|screen
argument_list|()
operator|->
name|nativeContext
argument_list|()
argument_list|,
name|platformWindow
argument_list|()
operator|->
name|renderBuffer
argument_list|()
operator|.
name|nativeBuffer
argument_list|()
argument_list|,
name|bg
argument_list|)
argument_list|,
literal|"failed to clear transparent regions"
argument_list|)
expr_stmt|;
block|}
name|Q_SCREEN_CHECKERROR
argument_list|(
name|screen_flush_blits
argument_list|(
name|platformWindow
argument_list|()
operator|->
name|screen
argument_list|()
operator|->
name|nativeContext
argument_list|()
argument_list|,
literal|0
argument_list|)
argument_list|,
literal|"failed to flush blits"
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|endPaint
name|void
name|QQnxRasterBackingStore
operator|::
name|endPaint
parameter_list|()
block|{
name|qRasterBackingStoreDebug
argument_list|()
operator|<<
name|Q_FUNC_INFO
operator|<<
literal|"w ="
operator|<<
name|window
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|platformWindow
name|QQnxRasterWindow
modifier|*
name|QQnxRasterBackingStore
operator|::
name|platformWindow
parameter_list|()
specifier|const
block|{
name|Q_ASSERT
argument_list|(
name|m_window
operator|->
name|handle
argument_list|()
argument_list|)
expr_stmt|;
return|return
cast|static_cast
argument_list|<
name|QQnxRasterWindow
operator|*
argument_list|>
argument_list|(
name|m_window
operator|->
name|handle
argument_list|()
argument_list|)
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
