begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<qcursor.h>
end_include
begin_include
include|#
directive|include
file|<qscreen.h>
end_include
begin_include
include|#
directive|include
file|<private/qcursor_p.h>
end_include
begin_include
include|#
directive|include
file|<qpa/qplatformcursor.h>
end_include
begin_include
include|#
directive|include
file|<private/qguiapplication_p.h>
end_include
begin_include
include|#
directive|include
file|<qbitmap.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
name|QT_USE_NAMESPACE
ifndef|#
directive|ifndef
name|QT_NO_CURSOR
DECL|variable|nextCursorId
specifier|static
name|int
name|nextCursorId
init|=
name|Qt
operator|::
name|BitmapCursor
decl_stmt|;
end_decl_stmt
begin_comment
comment|/*****************************************************************************   Internal QCursorData class  *****************************************************************************/
end_comment
begin_constructor
DECL|function|QCursorData
name|QCursorData
operator|::
name|QCursorData
parameter_list|(
name|Qt
operator|::
name|CursorShape
name|s
parameter_list|)
member_init_list|:
name|ref
argument_list|(
literal|1
argument_list|)
member_init_list|,
name|cshape
argument_list|(
name|s
argument_list|)
member_init_list|,
name|bm
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|bmm
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|hx
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|hy
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|id
argument_list|(
name|s
argument_list|)
block|{ }
end_constructor
begin_destructor
DECL|function|~QCursorData
name|QCursorData
operator|::
name|~
name|QCursorData
parameter_list|()
block|{
operator|delete
name|bm
expr_stmt|;
operator|delete
name|bmm
expr_stmt|;
block|}
end_destructor
begin_comment
comment|/*****************************************************************************   Global cursors  *****************************************************************************/
end_comment
begin_decl_stmt
specifier|extern
name|QCursorData
modifier|*
name|qt_cursorTable
index|[
name|Qt
operator|::
name|LastCursor
operator|+
literal|1
index|]
decl_stmt|;
end_decl_stmt
begin_comment
comment|// qcursor.cpp
end_comment
begin_function
DECL|function|handle
name|int
name|QCursor
operator|::
name|handle
parameter_list|()
specifier|const
block|{
return|return
name|d
operator|->
name|id
return|;
block|}
end_function
begin_function
DECL|function|setBitmap
name|QCursorData
modifier|*
name|QCursorData
operator|::
name|setBitmap
parameter_list|(
specifier|const
name|QBitmap
modifier|&
name|bitmap
parameter_list|,
specifier|const
name|QBitmap
modifier|&
name|mask
parameter_list|,
name|int
name|hotX
parameter_list|,
name|int
name|hotY
parameter_list|)
block|{
if|if
condition|(
operator|!
name|QCursorData
operator|::
name|initialized
condition|)
name|QCursorData
operator|::
name|initialize
argument_list|()
expr_stmt|;
if|if
condition|(
name|bitmap
operator|.
name|depth
argument_list|()
operator|!=
literal|1
operator|||
name|mask
operator|.
name|depth
argument_list|()
operator|!=
literal|1
operator|||
name|bitmap
operator|.
name|size
argument_list|()
operator|!=
name|mask
operator|.
name|size
argument_list|()
condition|)
block|{
name|qWarning
argument_list|(
literal|"QCursor: Cannot create bitmap cursor; invalid bitmap(s)"
argument_list|)
expr_stmt|;
name|QCursorData
modifier|*
name|c
init|=
name|qt_cursorTable
index|[
literal|0
index|]
decl_stmt|;
name|c
operator|->
name|ref
operator|.
name|ref
parameter_list|()
constructor_decl|;
return|return
name|c
return|;
block|}
name|QCursorData
modifier|*
name|d
init|=
operator|new
name|QCursorData
decl_stmt|;
name|d
operator|->
name|bm
operator|=
operator|new
name|QBitmap
argument_list|(
name|bitmap
argument_list|)
expr_stmt|;
name|d
operator|->
name|bmm
operator|=
operator|new
name|QBitmap
argument_list|(
name|mask
argument_list|)
expr_stmt|;
name|d
operator|->
name|cshape
operator|=
name|Qt
operator|::
name|BitmapCursor
expr_stmt|;
name|d
operator|->
name|id
operator|=
operator|++
name|nextCursorId
expr_stmt|;
name|d
operator|->
name|hx
operator|=
name|hotX
operator|>=
literal|0
condition|?
name|hotX
else|:
name|bitmap
operator|.
name|width
argument_list|()
operator|/
literal|2
expr_stmt|;
name|d
operator|->
name|hy
operator|=
name|hotY
operator|>=
literal|0
condition|?
name|hotY
else|:
name|bitmap
operator|.
name|height
argument_list|()
operator|/
literal|2
expr_stmt|;
return|return
name|d
return|;
block|}
end_function
begin_function
DECL|function|update
name|void
name|QCursorData
operator|::
name|update
parameter_list|()
block|{ }
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|//QT_NO_CURSOR
end_comment
begin_function
DECL|function|pos
name|QPoint
name|QCursor
operator|::
name|pos
parameter_list|()
block|{
return|return
name|QCursor
operator|::
name|pos
argument_list|(
name|QGuiApplication
operator|::
name|primaryScreen
argument_list|()
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|pos
name|QPoint
name|QCursor
operator|::
name|pos
parameter_list|(
specifier|const
name|QScreen
modifier|*
name|screen
parameter_list|)
block|{
if|if
condition|(
name|screen
condition|)
if|if
condition|(
specifier|const
name|QPlatformCursor
modifier|*
name|cursor
init|=
name|screen
operator|->
name|handle
argument_list|()
operator|->
name|cursor
argument_list|()
condition|)
return|return
name|cursor
operator|->
name|pos
argument_list|()
return|;
return|return
name|QGuiApplicationPrivate
operator|::
name|lastCursorPosition
operator|.
name|toPoint
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|setPos
name|void
name|QCursor
operator|::
name|setPos
parameter_list|(
name|QScreen
modifier|*
name|screen
parameter_list|,
name|int
name|x
parameter_list|,
name|int
name|y
parameter_list|)
block|{
if|if
condition|(
name|screen
condition|)
block|{
if|if
condition|(
name|QPlatformCursor
modifier|*
name|cursor
init|=
name|screen
operator|->
name|handle
argument_list|()
operator|->
name|cursor
argument_list|()
condition|)
block|{
specifier|const
name|QPoint
name|pos
init|=
name|QPoint
argument_list|(
name|x
argument_list|,
name|y
argument_list|)
decl_stmt|;
comment|// Need to check, since some X servers generate null mouse move
comment|// events, causing looping in applications which call setPos() on
comment|// every mouse move event.
if|if
condition|(
name|pos
operator|!=
name|cursor
operator|->
name|pos
argument_list|()
condition|)
name|cursor
operator|->
name|setPos
argument_list|(
name|pos
argument_list|)
expr_stmt|;
block|}
block|}
block|}
end_function
begin_function
DECL|function|setPos
name|void
name|QCursor
operator|::
name|setPos
parameter_list|(
name|int
name|x
parameter_list|,
name|int
name|y
parameter_list|)
block|{
name|QCursor
operator|::
name|setPos
argument_list|(
name|QGuiApplication
operator|::
name|primaryScreen
argument_list|()
argument_list|,
name|x
argument_list|,
name|y
argument_list|)
expr_stmt|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
