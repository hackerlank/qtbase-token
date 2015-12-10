begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 Canonical, Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL3$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPLv3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or later as published by the Free ** Software Foundation and appearing in the file LICENSE.GPL included in ** the packaging of this file. Please review the following information to ** ensure the GNU General Public License version 2.0 requirements will be ** met: http://www.gnu.org/licenses/gpl-2.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qmirclientcursor.h"
end_include
begin_include
include|#
directive|include
file|"qmirclientlogging.h"
end_include
begin_include
include|#
directive|include
file|"qmirclientwindow.h"
end_include
begin_include
include|#
directive|include
file|<mir_toolkit/mir_client_library.h>
end_include
begin_constructor
DECL|function|QMirClientCursor
name|QMirClientCursor
operator|::
name|QMirClientCursor
parameter_list|(
name|MirConnection
modifier|*
name|connection
parameter_list|)
member_init_list|:
name|mConnection
argument_list|(
name|connection
argument_list|)
block|{
name|mShapeToCursorName
index|[
name|Qt
operator|::
name|ArrowCursor
index|]
operator|=
literal|"left_ptr"
expr_stmt|;
name|mShapeToCursorName
index|[
name|Qt
operator|::
name|UpArrowCursor
index|]
operator|=
literal|"up_arrow"
expr_stmt|;
name|mShapeToCursorName
index|[
name|Qt
operator|::
name|CrossCursor
index|]
operator|=
literal|"cross"
expr_stmt|;
name|mShapeToCursorName
index|[
name|Qt
operator|::
name|WaitCursor
index|]
operator|=
literal|"watch"
expr_stmt|;
name|mShapeToCursorName
index|[
name|Qt
operator|::
name|IBeamCursor
index|]
operator|=
literal|"xterm"
expr_stmt|;
name|mShapeToCursorName
index|[
name|Qt
operator|::
name|SizeVerCursor
index|]
operator|=
literal|"size_ver"
expr_stmt|;
name|mShapeToCursorName
index|[
name|Qt
operator|::
name|SizeHorCursor
index|]
operator|=
literal|"size_hor"
expr_stmt|;
name|mShapeToCursorName
index|[
name|Qt
operator|::
name|SizeBDiagCursor
index|]
operator|=
literal|"size_bdiag"
expr_stmt|;
name|mShapeToCursorName
index|[
name|Qt
operator|::
name|SizeFDiagCursor
index|]
operator|=
literal|"size_fdiag"
expr_stmt|;
name|mShapeToCursorName
index|[
name|Qt
operator|::
name|SizeAllCursor
index|]
operator|=
literal|"size_all"
expr_stmt|;
name|mShapeToCursorName
index|[
name|Qt
operator|::
name|BlankCursor
index|]
operator|=
literal|"blank"
expr_stmt|;
name|mShapeToCursorName
index|[
name|Qt
operator|::
name|SplitVCursor
index|]
operator|=
literal|"split_v"
expr_stmt|;
name|mShapeToCursorName
index|[
name|Qt
operator|::
name|SplitHCursor
index|]
operator|=
literal|"split_h"
expr_stmt|;
name|mShapeToCursorName
index|[
name|Qt
operator|::
name|PointingHandCursor
index|]
operator|=
literal|"hand"
expr_stmt|;
name|mShapeToCursorName
index|[
name|Qt
operator|::
name|ForbiddenCursor
index|]
operator|=
literal|"forbidden"
expr_stmt|;
name|mShapeToCursorName
index|[
name|Qt
operator|::
name|WhatsThisCursor
index|]
operator|=
literal|"whats_this"
expr_stmt|;
name|mShapeToCursorName
index|[
name|Qt
operator|::
name|BusyCursor
index|]
operator|=
literal|"left_ptr_watch"
expr_stmt|;
name|mShapeToCursorName
index|[
name|Qt
operator|::
name|OpenHandCursor
index|]
operator|=
literal|"openhand"
expr_stmt|;
name|mShapeToCursorName
index|[
name|Qt
operator|::
name|ClosedHandCursor
index|]
operator|=
literal|"closedhand"
expr_stmt|;
name|mShapeToCursorName
index|[
name|Qt
operator|::
name|DragCopyCursor
index|]
operator|=
literal|"dnd-copy"
expr_stmt|;
name|mShapeToCursorName
index|[
name|Qt
operator|::
name|DragMoveCursor
index|]
operator|=
literal|"dnd-move"
expr_stmt|;
name|mShapeToCursorName
index|[
name|Qt
operator|::
name|DragLinkCursor
index|]
operator|=
literal|"dnd-link"
expr_stmt|;
block|}
end_constructor
begin_namespace
namespace|namespace
block|{
if|#
directive|if
operator|!
name|defined
argument_list|(
name|QT_NO_DEBUG
argument_list|)
DECL|function|qtCursorShapeToStr
specifier|const
name|char
modifier|*
name|qtCursorShapeToStr
parameter_list|(
name|Qt
operator|::
name|CursorShape
name|shape
parameter_list|)
block|{
switch|switch
condition|(
name|shape
condition|)
block|{
case|case
name|Qt
operator|::
name|ArrowCursor
case|:
return|return
literal|"Arrow"
return|;
case|case
name|Qt
operator|::
name|UpArrowCursor
case|:
return|return
literal|"UpArrow"
return|;
case|case
name|Qt
operator|::
name|CrossCursor
case|:
return|return
literal|"Cross"
return|;
case|case
name|Qt
operator|::
name|WaitCursor
case|:
return|return
literal|"Wait"
return|;
case|case
name|Qt
operator|::
name|IBeamCursor
case|:
return|return
literal|"IBeam"
return|;
case|case
name|Qt
operator|::
name|SizeVerCursor
case|:
return|return
literal|"SizeVer"
return|;
case|case
name|Qt
operator|::
name|SizeHorCursor
case|:
return|return
literal|"SizeHor"
return|;
case|case
name|Qt
operator|::
name|SizeBDiagCursor
case|:
return|return
literal|"SizeBDiag"
return|;
case|case
name|Qt
operator|::
name|SizeFDiagCursor
case|:
return|return
literal|"SizeFDiag"
return|;
case|case
name|Qt
operator|::
name|SizeAllCursor
case|:
return|return
literal|"SizeAll"
return|;
case|case
name|Qt
operator|::
name|BlankCursor
case|:
return|return
literal|"Blank"
return|;
case|case
name|Qt
operator|::
name|SplitVCursor
case|:
return|return
literal|"SplitV"
return|;
case|case
name|Qt
operator|::
name|SplitHCursor
case|:
return|return
literal|"SplitH"
return|;
case|case
name|Qt
operator|::
name|PointingHandCursor
case|:
return|return
literal|"PointingHand"
return|;
case|case
name|Qt
operator|::
name|ForbiddenCursor
case|:
return|return
literal|"Forbidden"
return|;
case|case
name|Qt
operator|::
name|WhatsThisCursor
case|:
return|return
literal|"WhatsThis"
return|;
case|case
name|Qt
operator|::
name|BusyCursor
case|:
return|return
literal|"Busy"
return|;
case|case
name|Qt
operator|::
name|OpenHandCursor
case|:
return|return
literal|"OpenHand"
return|;
case|case
name|Qt
operator|::
name|ClosedHandCursor
case|:
return|return
literal|"ClosedHand"
return|;
case|case
name|Qt
operator|::
name|DragCopyCursor
case|:
return|return
literal|"DragCopy"
return|;
case|case
name|Qt
operator|::
name|DragMoveCursor
case|:
return|return
literal|"DragMove"
return|;
case|case
name|Qt
operator|::
name|DragLinkCursor
case|:
return|return
literal|"DragLink"
return|;
case|case
name|Qt
operator|::
name|BitmapCursor
case|:
return|return
literal|"Bitmap"
return|;
default|default:
return|return
literal|"???"
return|;
block|}
block|}
endif|#
directive|endif
comment|// !defined(QT_NO_DEBUG)
block|}
end_namespace
begin_comment
comment|// anonymous namespace
end_comment
begin_function
DECL|function|changeCursor
name|void
name|QMirClientCursor
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
if|if
condition|(
operator|!
name|window
condition|)
block|{
return|return;
block|}
name|MirSurface
modifier|*
name|surface
init|=
cast|static_cast
argument_list|<
name|QMirClientWindow
operator|*
argument_list|>
argument_list|(
name|window
operator|->
name|handle
argument_list|()
argument_list|)
operator|->
name|mirSurface
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
name|surface
condition|)
block|{
return|return;
block|}
if|if
condition|(
name|windowCursor
condition|)
block|{
name|DLOG
argument_list|(
literal|"[ubuntumirclient QPA] changeCursor shape=%s, window=%p\n"
argument_list|,
name|qtCursorShapeToStr
argument_list|(
name|windowCursor
operator|->
name|shape
argument_list|()
argument_list|)
argument_list|,
name|window
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|windowCursor
operator|->
name|pixmap
argument_list|()
operator|.
name|isNull
argument_list|()
condition|)
block|{
name|configureMirCursorWithPixmapQCursor
argument_list|(
name|surface
argument_list|,
operator|*
name|windowCursor
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|windowCursor
operator|->
name|shape
argument_list|()
operator|==
name|Qt
operator|::
name|BitmapCursor
condition|)
block|{
comment|// TODO: Implement bitmap cursor support
name|applyDefaultCursorConfiguration
argument_list|(
name|surface
argument_list|)
expr_stmt|;
block|}
else|else
block|{
specifier|const
specifier|auto
modifier|&
name|cursorName
init|=
name|mShapeToCursorName
operator|.
name|value
argument_list|(
name|windowCursor
operator|->
name|shape
argument_list|()
argument_list|,
name|QByteArray
argument_list|(
literal|"left_ptr"
argument_list|)
argument_list|)
decl_stmt|;
name|auto
name|cursorConfiguration
init|=
name|mir_cursor_configuration_from_name
argument_list|(
name|cursorName
operator|.
name|data
argument_list|()
argument_list|)
decl_stmt|;
name|mir_surface_configure_cursor
argument_list|(
name|surface
argument_list|,
name|cursorConfiguration
argument_list|)
expr_stmt|;
name|mir_cursor_configuration_destroy
argument_list|(
name|cursorConfiguration
argument_list|)
expr_stmt|;
block|}
block|}
else|else
block|{
name|applyDefaultCursorConfiguration
argument_list|(
name|surface
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|configureMirCursorWithPixmapQCursor
name|void
name|QMirClientCursor
operator|::
name|configureMirCursorWithPixmapQCursor
parameter_list|(
name|MirSurface
modifier|*
name|surface
parameter_list|,
name|QCursor
modifier|&
name|cursor
parameter_list|)
block|{
name|QImage
name|image
init|=
name|cursor
operator|.
name|pixmap
argument_list|()
operator|.
name|toImage
argument_list|()
decl_stmt|;
if|if
condition|(
name|image
operator|.
name|format
argument_list|()
operator|!=
name|QImage
operator|::
name|Format_ARGB32
condition|)
block|{
name|image
operator|.
name|convertToFormat
argument_list|(
name|QImage
operator|::
name|Format_ARGB32
argument_list|)
expr_stmt|;
block|}
name|MirBufferStream
modifier|*
name|bufferStream
init|=
name|mir_connection_create_buffer_stream_sync
argument_list|(
name|mConnection
argument_list|,
name|image
operator|.
name|width
argument_list|()
argument_list|,
name|image
operator|.
name|height
argument_list|()
argument_list|,
name|mir_pixel_format_argb_8888
argument_list|,
name|mir_buffer_usage_software
argument_list|)
decl_stmt|;
block|{
name|MirGraphicsRegion
name|region
decl_stmt|;
name|mir_buffer_stream_get_graphics_region
argument_list|(
name|bufferStream
argument_list|,
operator|&
name|region
argument_list|)
expr_stmt|;
name|char
modifier|*
name|regionLine
init|=
name|region
operator|.
name|vaddr
decl_stmt|;
name|Q_ASSERT
argument_list|(
name|image
operator|.
name|bytesPerLine
argument_list|()
operator|<=
name|region
operator|.
name|stride
argument_list|)
expr_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|image
operator|.
name|height
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
name|memcpy
argument_list|(
name|regionLine
argument_list|,
name|image
operator|.
name|scanLine
argument_list|(
name|i
argument_list|)
argument_list|,
name|image
operator|.
name|bytesPerLine
argument_list|()
argument_list|)
expr_stmt|;
name|regionLine
operator|+=
name|region
operator|.
name|stride
expr_stmt|;
block|}
block|}
name|mir_buffer_stream_swap_buffers_sync
argument_list|(
name|bufferStream
argument_list|)
expr_stmt|;
block|{
name|auto
name|configuration
init|=
name|mir_cursor_configuration_from_buffer_stream
argument_list|(
name|bufferStream
argument_list|,
name|cursor
operator|.
name|hotSpot
argument_list|()
operator|.
name|x
argument_list|()
argument_list|,
name|cursor
operator|.
name|hotSpot
argument_list|()
operator|.
name|y
argument_list|()
argument_list|)
decl_stmt|;
name|mir_surface_configure_cursor
argument_list|(
name|surface
argument_list|,
name|configuration
argument_list|)
expr_stmt|;
name|mir_cursor_configuration_destroy
argument_list|(
name|configuration
argument_list|)
expr_stmt|;
block|}
name|mir_buffer_stream_release_sync
argument_list|(
name|bufferStream
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|applyDefaultCursorConfiguration
name|void
name|QMirClientCursor
operator|::
name|applyDefaultCursorConfiguration
parameter_list|(
name|MirSurface
modifier|*
name|surface
parameter_list|)
block|{
name|auto
name|cursorConfiguration
init|=
name|mir_cursor_configuration_from_name
argument_list|(
literal|"left_ptr"
argument_list|)
decl_stmt|;
name|mir_surface_configure_cursor
argument_list|(
name|surface
argument_list|,
name|cursorConfiguration
argument_list|)
expr_stmt|;
name|mir_cursor_configuration_destroy
argument_list|(
name|cursorConfiguration
argument_list|)
expr_stmt|;
block|}
end_function
end_unit
