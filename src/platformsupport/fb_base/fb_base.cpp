begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"fb_base_p.h"
end_include
begin_include
include|#
directive|include
file|<qpainter.h>
end_include
begin_include
include|#
directive|include
file|<qdebug.h>
end_include
begin_include
include|#
directive|include
file|<qbitmap.h>
end_include
begin_include
include|#
directive|include
file|<QPlatformCursor>
end_include
begin_include
include|#
directive|include
file|<QWindowSystemInterface>
end_include
begin_constructor
DECL|function|QPlatformSoftwareCursor
name|QPlatformSoftwareCursor
operator|::
name|QPlatformSoftwareCursor
parameter_list|(
name|QPlatformScreen
modifier|*
name|scr
parameter_list|)
member_init_list|:
name|QPlatformCursor
argument_list|(
name|scr
argument_list|)
member_init_list|,
name|currentRect
argument_list|(
name|QRect
argument_list|()
argument_list|)
member_init_list|,
name|prevRect
argument_list|(
name|QRect
argument_list|()
argument_list|)
block|{
name|graphic
operator|=
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
expr_stmt|;
name|setCursor
argument_list|(
name|Qt
operator|::
name|ArrowCursor
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_function
DECL|function|getCurrentRect
name|QRect
name|QPlatformSoftwareCursor
operator|::
name|getCurrentRect
parameter_list|()
block|{
name|QRect
name|rect
init|=
name|graphic
operator|->
name|image
argument_list|()
operator|->
name|rect
argument_list|()
operator|.
name|translated
argument_list|(
operator|-
name|graphic
operator|->
name|hotspot
argument_list|()
operator|.
name|x
argument_list|()
argument_list|,
operator|-
name|graphic
operator|->
name|hotspot
argument_list|()
operator|.
name|y
argument_list|()
argument_list|)
decl_stmt|;
name|rect
operator|.
name|translate
argument_list|(
name|QCursor
operator|::
name|pos
argument_list|()
argument_list|)
expr_stmt|;
name|QPoint
name|screenOffset
init|=
name|screen
operator|->
name|geometry
argument_list|()
operator|.
name|topLeft
argument_list|()
decl_stmt|;
name|rect
operator|.
name|translate
argument_list|(
operator|-
name|screenOffset
argument_list|)
expr_stmt|;
comment|// global to local translation
return|return
name|rect
return|;
block|}
end_function
begin_function
DECL|function|pointerEvent
name|void
name|QPlatformSoftwareCursor
operator|::
name|pointerEvent
parameter_list|(
specifier|const
name|QMouseEvent
modifier|&
name|e
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
name|e
argument_list|)
expr_stmt|;
name|QPoint
name|screenOffset
init|=
name|screen
operator|->
name|geometry
argument_list|()
operator|.
name|topLeft
argument_list|()
decl_stmt|;
name|currentRect
operator|=
name|getCurrentRect
argument_list|()
expr_stmt|;
comment|// global to local translation
if|if
condition|(
name|onScreen
operator|||
name|screen
operator|->
name|geometry
argument_list|()
operator|.
name|intersects
argument_list|(
name|currentRect
operator|.
name|translated
argument_list|(
name|screenOffset
argument_list|)
argument_list|)
condition|)
block|{
name|setDirty
argument_list|()
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|drawCursor
name|QRect
name|QPlatformSoftwareCursor
operator|::
name|drawCursor
parameter_list|(
name|QPainter
modifier|&
name|painter
parameter_list|)
block|{
name|dirty
operator|=
literal|false
expr_stmt|;
if|if
condition|(
name|currentRect
operator|.
name|isNull
argument_list|()
condition|)
return|return
name|QRect
argument_list|()
return|;
comment|// We need this because the cursor might be dirty due to moving off screen
name|QPoint
name|screenOffset
init|=
name|screen
operator|->
name|geometry
argument_list|()
operator|.
name|topLeft
argument_list|()
decl_stmt|;
comment|// global to local translation
if|if
condition|(
operator|!
name|currentRect
operator|.
name|translated
argument_list|(
name|screenOffset
argument_list|)
operator|.
name|intersects
argument_list|(
name|screen
operator|->
name|geometry
argument_list|()
argument_list|)
condition|)
return|return
name|QRect
argument_list|()
return|;
name|prevRect
operator|=
name|currentRect
expr_stmt|;
name|painter
operator|.
name|drawImage
argument_list|(
name|prevRect
argument_list|,
operator|*
name|graphic
operator|->
name|image
argument_list|()
argument_list|)
expr_stmt|;
name|onScreen
operator|=
literal|true
expr_stmt|;
return|return
name|prevRect
return|;
block|}
end_function
begin_function
DECL|function|dirtyRect
name|QRect
name|QPlatformSoftwareCursor
operator|::
name|dirtyRect
parameter_list|()
block|{
if|if
condition|(
name|onScreen
condition|)
block|{
name|onScreen
operator|=
literal|false
expr_stmt|;
return|return
name|prevRect
return|;
block|}
return|return
name|QRect
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|setCursor
name|void
name|QPlatformSoftwareCursor
operator|::
name|setCursor
parameter_list|(
name|Qt
operator|::
name|CursorShape
name|shape
parameter_list|)
block|{
name|graphic
operator|->
name|set
argument_list|(
name|shape
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|setCursor
name|void
name|QPlatformSoftwareCursor
operator|::
name|setCursor
parameter_list|(
specifier|const
name|QImage
modifier|&
name|image
parameter_list|,
name|int
name|hotx
parameter_list|,
name|int
name|hoty
parameter_list|)
block|{
name|graphic
operator|->
name|set
argument_list|(
name|image
argument_list|,
name|hotx
argument_list|,
name|hoty
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|setCursor
name|void
name|QPlatformSoftwareCursor
operator|::
name|setCursor
parameter_list|(
specifier|const
name|uchar
modifier|*
name|data
parameter_list|,
specifier|const
name|uchar
modifier|*
name|mask
parameter_list|,
name|int
name|width
parameter_list|,
name|int
name|height
parameter_list|,
name|int
name|hotX
parameter_list|,
name|int
name|hotY
parameter_list|)
block|{
name|graphic
operator|->
name|set
argument_list|(
name|data
argument_list|,
name|mask
argument_list|,
name|width
argument_list|,
name|height
argument_list|,
name|hotX
argument_list|,
name|hotY
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|changeCursor
name|void
name|QPlatformSoftwareCursor
operator|::
name|changeCursor
parameter_list|(
name|QCursor
modifier|*
name|widgetCursor
parameter_list|,
name|QWidget
modifier|*
name|widget
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
name|widget
argument_list|)
expr_stmt|;
name|Qt
operator|::
name|CursorShape
name|shape
init|=
name|widgetCursor
operator|->
name|shape
argument_list|()
decl_stmt|;
if|if
condition|(
name|shape
operator|==
name|Qt
operator|::
name|BitmapCursor
condition|)
block|{
comment|// application supplied cursor
name|QPoint
name|spot
init|=
name|widgetCursor
operator|->
name|hotSpot
argument_list|()
decl_stmt|;
name|setCursor
argument_list|(
name|widgetCursor
operator|->
name|pixmap
argument_list|()
operator|.
name|toImage
argument_list|()
argument_list|,
name|spot
operator|.
name|x
argument_list|()
argument_list|,
name|spot
operator|.
name|y
argument_list|()
argument_list|)
expr_stmt|;
block|}
else|else
block|{
comment|// system cursor
name|setCursor
argument_list|(
name|shape
argument_list|)
expr_stmt|;
block|}
name|currentRect
operator|=
name|getCurrentRect
argument_list|()
expr_stmt|;
name|QPoint
name|screenOffset
init|=
name|screen
operator|->
name|geometry
argument_list|()
operator|.
name|topLeft
argument_list|()
decl_stmt|;
comment|// global to local translation
if|if
condition|(
name|onScreen
operator|||
name|screen
operator|->
name|geometry
argument_list|()
operator|.
name|intersects
argument_list|(
name|currentRect
operator|.
name|translated
argument_list|(
name|screenOffset
argument_list|)
argument_list|)
condition|)
name|setDirty
argument_list|()
expr_stmt|;
block|}
end_function
begin_constructor
DECL|function|QFbScreen
name|QFbScreen
operator|::
name|QFbScreen
parameter_list|()
member_init_list|:
name|cursor
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|mGeometry
argument_list|()
member_init_list|,
name|mDepth
argument_list|(
literal|16
argument_list|)
member_init_list|,
name|mFormat
argument_list|(
name|QImage
operator|::
name|Format_RGB16
argument_list|)
member_init_list|,
name|mScreenImage
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|compositePainter
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|isUpToDate
argument_list|(
literal|false
argument_list|)
block|{
name|mScreenImage
operator|=
operator|new
name|QImage
argument_list|(
name|mGeometry
operator|.
name|size
argument_list|()
argument_list|,
name|mFormat
argument_list|)
expr_stmt|;
name|redrawTimer
operator|.
name|setSingleShot
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|redrawTimer
operator|.
name|setInterval
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|QObject
operator|::
name|connect
argument_list|(
operator|&
name|redrawTimer
argument_list|,
name|SIGNAL
argument_list|(
name|timeout
argument_list|()
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|doRedraw
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_function
DECL|function|setGeometry
name|void
name|QFbScreen
operator|::
name|setGeometry
parameter_list|(
name|QRect
name|rect
parameter_list|)
block|{
operator|delete
name|mScreenImage
expr_stmt|;
name|mGeometry
operator|=
name|rect
expr_stmt|;
name|mScreenImage
operator|=
operator|new
name|QImage
argument_list|(
name|mGeometry
operator|.
name|size
argument_list|()
argument_list|,
name|mFormat
argument_list|)
expr_stmt|;
operator|delete
name|compositePainter
expr_stmt|;
name|compositePainter
operator|=
literal|0
expr_stmt|;
name|invalidateRectCache
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|setDepth
name|void
name|QFbScreen
operator|::
name|setDepth
parameter_list|(
name|int
name|depth
parameter_list|)
block|{
name|mDepth
operator|=
name|depth
expr_stmt|;
block|}
end_function
begin_function
DECL|function|setPhysicalSize
name|void
name|QFbScreen
operator|::
name|setPhysicalSize
parameter_list|(
name|QSize
name|size
parameter_list|)
block|{
name|mPhysicalSize
operator|=
name|size
expr_stmt|;
block|}
end_function
begin_function
DECL|function|setFormat
name|void
name|QFbScreen
operator|::
name|setFormat
parameter_list|(
name|QImage
operator|::
name|Format
name|format
parameter_list|)
block|{
name|mFormat
operator|=
name|format
expr_stmt|;
operator|delete
name|mScreenImage
expr_stmt|;
name|mScreenImage
operator|=
operator|new
name|QImage
argument_list|(
name|mGeometry
operator|.
name|size
argument_list|()
argument_list|,
name|mFormat
argument_list|)
expr_stmt|;
operator|delete
name|compositePainter
expr_stmt|;
name|compositePainter
operator|=
literal|0
expr_stmt|;
block|}
end_function
begin_destructor
DECL|function|~QFbScreen
name|QFbScreen
operator|::
name|~
name|QFbScreen
parameter_list|()
block|{
operator|delete
name|compositePainter
expr_stmt|;
operator|delete
name|mScreenImage
expr_stmt|;
block|}
end_destructor
begin_function
DECL|function|setDirty
name|void
name|QFbScreen
operator|::
name|setDirty
parameter_list|(
specifier|const
name|QRect
modifier|&
name|rect
parameter_list|)
block|{
name|QRect
name|intersection
init|=
name|rect
operator|.
name|intersected
argument_list|(
name|mGeometry
argument_list|)
decl_stmt|;
name|QPoint
name|screenOffset
init|=
name|mGeometry
operator|.
name|topLeft
argument_list|()
decl_stmt|;
name|repaintRegion
operator|+=
name|intersection
operator|.
name|translated
argument_list|(
operator|-
name|screenOffset
argument_list|)
expr_stmt|;
comment|// global to local translation
if|if
condition|(
operator|!
name|redrawTimer
operator|.
name|isActive
argument_list|()
condition|)
block|{
name|redrawTimer
operator|.
name|start
argument_list|()
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|generateRects
name|void
name|QFbScreen
operator|::
name|generateRects
parameter_list|()
block|{
name|cachedRects
operator|.
name|clear
argument_list|()
expr_stmt|;
name|QPoint
name|screenOffset
init|=
name|mGeometry
operator|.
name|topLeft
argument_list|()
decl_stmt|;
name|QRegion
name|remainingScreen
argument_list|(
name|mGeometry
operator|.
name|translated
argument_list|(
operator|-
name|screenOffset
argument_list|)
argument_list|)
decl_stmt|;
comment|// global to local translation
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|windowStack
operator|.
name|length
argument_list|()
condition|;
name|i
operator|++
control|)
block|{
if|if
condition|(
name|remainingScreen
operator|.
name|isEmpty
argument_list|()
condition|)
break|break;
if|if
condition|(
operator|!
name|windowStack
index|[
name|i
index|]
operator|->
name|visible
argument_list|()
condition|)
continue|continue;
if|if
condition|(
name|windowStack
index|[
name|i
index|]
operator|->
name|widget
argument_list|()
operator|->
name|isMinimized
argument_list|()
condition|)
continue|continue;
if|if
condition|(
operator|!
name|windowStack
index|[
name|i
index|]
operator|->
name|widget
argument_list|()
operator|->
name|testAttribute
argument_list|(
name|Qt
operator|::
name|WA_TranslucentBackground
argument_list|)
condition|)
block|{
name|QRect
name|localGeometry
init|=
name|windowStack
operator|.
name|at
argument_list|(
name|i
argument_list|)
operator|->
name|geometry
argument_list|()
operator|.
name|translated
argument_list|(
operator|-
name|screenOffset
argument_list|)
decl_stmt|;
comment|// global to local translation
name|remainingScreen
operator|-=
name|localGeometry
expr_stmt|;
name|QRegion
name|windowRegion
argument_list|(
name|localGeometry
argument_list|)
decl_stmt|;
name|windowRegion
operator|-=
name|remainingScreen
expr_stmt|;
foreach|foreach
control|(
name|QRect
name|rect
decl|,
name|windowRegion
operator|.
name|rects
argument_list|()
control|)
block|{
name|cachedRects
operator|+=
name|QPair
argument_list|<
name|QRect
argument_list|,
name|int
argument_list|>
argument_list|(
name|rect
argument_list|,
name|i
argument_list|)
expr_stmt|;
block|}
block|}
block|}
foreach|foreach
control|(
name|QRect
name|rect
decl|,
name|remainingScreen
operator|.
name|rects
argument_list|()
control|)
name|cachedRects
operator|+=
name|QPair
argument_list|<
name|QRect
argument_list|,
name|int
argument_list|>
argument_list|(
name|rect
argument_list|,
operator|-
literal|1
argument_list|)
expr_stmt|;
name|isUpToDate
operator|=
literal|true
expr_stmt|;
return|return;
block|}
end_function
begin_function
DECL|function|doRedraw
name|QRegion
name|QFbScreen
operator|::
name|doRedraw
parameter_list|()
block|{
name|QPoint
name|screenOffset
init|=
name|mGeometry
operator|.
name|topLeft
argument_list|()
decl_stmt|;
name|QRegion
name|touchedRegion
decl_stmt|;
if|if
condition|(
name|cursor
operator|&&
name|cursor
operator|->
name|isDirty
argument_list|()
operator|&&
name|cursor
operator|->
name|isOnScreen
argument_list|()
condition|)
block|{
name|QRect
name|lastCursor
init|=
name|cursor
operator|->
name|dirtyRect
argument_list|()
decl_stmt|;
name|repaintRegion
operator|+=
name|lastCursor
expr_stmt|;
block|}
if|if
condition|(
name|repaintRegion
operator|.
name|isEmpty
argument_list|()
operator|&&
operator|(
operator|!
name|cursor
operator|||
operator|!
name|cursor
operator|->
name|isDirty
argument_list|()
operator|)
condition|)
block|{
return|return
name|touchedRegion
return|;
block|}
name|QVector
argument_list|<
name|QRect
argument_list|>
name|rects
init|=
name|repaintRegion
operator|.
name|rects
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
name|isUpToDate
condition|)
name|generateRects
argument_list|()
expr_stmt|;
if|if
condition|(
operator|!
name|compositePainter
condition|)
name|compositePainter
operator|=
operator|new
name|QPainter
argument_list|(
name|mScreenImage
argument_list|)
expr_stmt|;
for|for
control|(
name|int
name|rectIndex
init|=
literal|0
init|;
name|rectIndex
operator|<
name|repaintRegion
operator|.
name|numRects
argument_list|()
condition|;
name|rectIndex
operator|++
control|)
block|{
name|QRegion
name|rectRegion
init|=
name|rects
index|[
name|rectIndex
index|]
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
name|cachedRects
operator|.
name|length
argument_list|()
condition|;
name|i
operator|++
control|)
block|{
name|QRect
name|screenSubRect
init|=
name|cachedRects
index|[
name|i
index|]
operator|.
name|first
decl_stmt|;
name|int
name|layer
init|=
name|cachedRects
index|[
name|i
index|]
operator|.
name|second
decl_stmt|;
name|QRegion
name|intersect
init|=
name|rectRegion
operator|.
name|intersected
argument_list|(
name|screenSubRect
argument_list|)
decl_stmt|;
if|if
condition|(
name|intersect
operator|.
name|isEmpty
argument_list|()
condition|)
continue|continue;
name|rectRegion
operator|-=
name|intersect
expr_stmt|;
comment|// we only expect one rectangle, but defensive coding...
foreach|foreach
control|(
name|QRect
name|rect
decl|,
name|intersect
operator|.
name|rects
argument_list|()
control|)
block|{
name|bool
name|firstLayer
init|=
literal|true
decl_stmt|;
if|if
condition|(
name|layer
operator|==
operator|-
literal|1
condition|)
block|{
name|compositePainter
operator|->
name|fillRect
argument_list|(
name|rect
argument_list|,
name|Qt
operator|::
name|black
argument_list|)
expr_stmt|;
name|firstLayer
operator|=
literal|false
expr_stmt|;
name|layer
operator|=
name|windowStack
operator|.
name|size
argument_list|()
operator|-
literal|1
expr_stmt|;
block|}
for|for
control|(
name|int
name|layerIndex
init|=
name|layer
init|;
name|layerIndex
operator|!=
operator|-
literal|1
condition|;
name|layerIndex
operator|--
control|)
block|{
if|if
condition|(
operator|!
name|windowStack
index|[
name|layerIndex
index|]
operator|->
name|visible
argument_list|()
condition|)
continue|continue;
if|if
condition|(
name|windowStack
index|[
name|layerIndex
index|]
operator|->
name|widget
argument_list|()
operator|->
name|isMinimized
argument_list|()
condition|)
continue|continue;
name|QRect
name|windowRect
init|=
name|windowStack
index|[
name|layerIndex
index|]
operator|->
name|geometry
argument_list|()
operator|.
name|translated
argument_list|(
operator|-
name|screenOffset
argument_list|)
decl_stmt|;
name|QRect
name|windowIntersect
init|=
name|rect
operator|.
name|translated
argument_list|(
operator|-
name|windowRect
operator|.
name|left
argument_list|()
argument_list|,
operator|-
name|windowRect
operator|.
name|top
argument_list|()
argument_list|)
decl_stmt|;
name|compositePainter
operator|->
name|drawImage
argument_list|(
name|rect
argument_list|,
name|windowStack
index|[
name|layerIndex
index|]
operator|->
name|surface
operator|->
name|image
argument_list|()
argument_list|,
name|windowIntersect
argument_list|)
expr_stmt|;
if|if
condition|(
name|firstLayer
condition|)
block|{
name|firstLayer
operator|=
literal|false
expr_stmt|;
block|}
block|}
block|}
block|}
block|}
name|QRect
name|cursorRect
decl_stmt|;
if|if
condition|(
name|cursor
operator|&&
operator|(
name|cursor
operator|->
name|isDirty
argument_list|()
operator|||
name|repaintRegion
operator|.
name|intersects
argument_list|(
name|cursor
operator|->
name|lastPainted
argument_list|()
argument_list|)
operator|)
condition|)
block|{
name|cursorRect
operator|=
name|cursor
operator|->
name|drawCursor
argument_list|(
operator|*
name|compositePainter
argument_list|)
expr_stmt|;
name|touchedRegion
operator|+=
name|cursorRect
expr_stmt|;
block|}
name|touchedRegion
operator|+=
name|repaintRegion
expr_stmt|;
name|repaintRegion
operator|=
name|QRegion
argument_list|()
expr_stmt|;
comment|//    qDebug()<< "QFbScreen::doRedraw"<< windowStack.size()<< mScreenImage->size()<< touchedRegion;
return|return
name|touchedRegion
return|;
block|}
end_function
begin_function
DECL|function|addWindow
name|void
name|QFbScreen
operator|::
name|addWindow
parameter_list|(
name|QFbWindow
modifier|*
name|surface
parameter_list|)
block|{
name|windowStack
operator|.
name|prepend
argument_list|(
name|surface
argument_list|)
expr_stmt|;
name|surface
operator|->
name|mScreens
operator|.
name|append
argument_list|(
name|this
argument_list|)
expr_stmt|;
name|invalidateRectCache
argument_list|()
expr_stmt|;
name|setDirty
argument_list|(
name|surface
operator|->
name|geometry
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|removeWindow
name|void
name|QFbScreen
operator|::
name|removeWindow
parameter_list|(
name|QFbWindow
modifier|*
name|surface
parameter_list|)
block|{
name|windowStack
operator|.
name|removeOne
argument_list|(
name|surface
argument_list|)
expr_stmt|;
name|surface
operator|->
name|mScreens
operator|.
name|removeOne
argument_list|(
name|this
argument_list|)
expr_stmt|;
name|invalidateRectCache
argument_list|()
expr_stmt|;
name|setDirty
argument_list|(
name|surface
operator|->
name|geometry
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|raise
name|void
name|QFbWindow
operator|::
name|raise
parameter_list|()
block|{
name|QList
argument_list|<
name|QFbScreen
modifier|*
argument_list|>
operator|::
name|const_iterator
name|i
init|=
name|mScreens
operator|.
name|constBegin
argument_list|()
decl_stmt|;
name|QList
argument_list|<
name|QFbScreen
modifier|*
argument_list|>
operator|::
name|const_iterator
name|end
init|=
name|mScreens
operator|.
name|constEnd
argument_list|()
decl_stmt|;
while|while
condition|(
name|i
operator|!=
name|end
condition|)
block|{
operator|(
operator|*
name|i
operator|)
operator|->
name|raise
argument_list|(
name|this
argument_list|)
expr_stmt|;
operator|++
name|i
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|raise
name|void
name|QFbScreen
operator|::
name|raise
parameter_list|(
name|QPlatformWindow
modifier|*
name|surface
parameter_list|)
block|{
name|QFbWindow
modifier|*
name|s
init|=
cast|static_cast
argument_list|<
name|QFbWindow
operator|*
argument_list|>
argument_list|(
name|surface
argument_list|)
decl_stmt|;
name|int
name|index
init|=
name|windowStack
operator|.
name|indexOf
argument_list|(
name|s
argument_list|)
decl_stmt|;
if|if
condition|(
name|index
operator|<=
literal|0
condition|)
return|return;
name|windowStack
operator|.
name|move
argument_list|(
name|index
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|invalidateRectCache
argument_list|()
expr_stmt|;
name|setDirty
argument_list|(
name|s
operator|->
name|geometry
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|lower
name|void
name|QFbWindow
operator|::
name|lower
parameter_list|()
block|{
name|QList
argument_list|<
name|QFbScreen
modifier|*
argument_list|>
operator|::
name|const_iterator
name|i
init|=
name|mScreens
operator|.
name|constBegin
argument_list|()
decl_stmt|;
name|QList
argument_list|<
name|QFbScreen
modifier|*
argument_list|>
operator|::
name|const_iterator
name|end
init|=
name|mScreens
operator|.
name|constEnd
argument_list|()
decl_stmt|;
while|while
condition|(
name|i
operator|!=
name|end
condition|)
block|{
operator|(
operator|*
name|i
operator|)
operator|->
name|lower
argument_list|(
name|this
argument_list|)
expr_stmt|;
operator|++
name|i
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|lower
name|void
name|QFbScreen
operator|::
name|lower
parameter_list|(
name|QPlatformWindow
modifier|*
name|surface
parameter_list|)
block|{
name|QFbWindow
modifier|*
name|s
init|=
cast|static_cast
argument_list|<
name|QFbWindow
operator|*
argument_list|>
argument_list|(
name|surface
argument_list|)
decl_stmt|;
name|int
name|index
init|=
name|windowStack
operator|.
name|indexOf
argument_list|(
name|s
argument_list|)
decl_stmt|;
if|if
condition|(
name|index
operator|==
operator|-
literal|1
operator|||
name|index
operator|==
operator|(
name|windowStack
operator|.
name|size
argument_list|()
operator|-
literal|1
operator|)
condition|)
return|return;
name|windowStack
operator|.
name|move
argument_list|(
name|index
argument_list|,
name|windowStack
operator|.
name|size
argument_list|()
operator|-
literal|1
argument_list|)
expr_stmt|;
name|invalidateRectCache
argument_list|()
expr_stmt|;
name|setDirty
argument_list|(
name|s
operator|->
name|geometry
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|topLevelAt
name|QWidget
modifier|*
name|QFbScreen
operator|::
name|topLevelAt
parameter_list|(
specifier|const
name|QPoint
modifier|&
name|p
parameter_list|)
specifier|const
block|{
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|windowStack
operator|.
name|size
argument_list|()
condition|;
name|i
operator|++
control|)
block|{
if|if
condition|(
name|windowStack
index|[
name|i
index|]
operator|->
name|geometry
argument_list|()
operator|.
name|contains
argument_list|(
name|p
argument_list|,
literal|false
argument_list|)
operator|&&
name|windowStack
index|[
name|i
index|]
operator|->
name|visible
argument_list|()
operator|&&
operator|!
name|windowStack
index|[
name|i
index|]
operator|->
name|widget
argument_list|()
operator|->
name|isMinimized
argument_list|()
condition|)
block|{
return|return
name|windowStack
index|[
name|i
index|]
operator|->
name|widget
argument_list|()
return|;
block|}
block|}
return|return
literal|0
return|;
block|}
end_function
begin_constructor
DECL|function|QFbWindow
name|QFbWindow
operator|::
name|QFbWindow
parameter_list|(
name|QWidget
modifier|*
name|window
parameter_list|)
member_init_list|:
name|QPlatformWindow
argument_list|(
name|window
argument_list|)
member_init_list|,
name|visibleFlag
argument_list|(
literal|false
argument_list|)
block|{
specifier|static
name|QAtomicInt
name|winIdGenerator
argument_list|(
literal|1
argument_list|)
decl_stmt|;
name|windowId
operator|=
name|winIdGenerator
operator|.
name|fetchAndAddRelaxed
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_destructor
DECL|function|~QFbWindow
name|QFbWindow
operator|::
name|~
name|QFbWindow
parameter_list|()
block|{
name|QList
argument_list|<
name|QFbScreen
modifier|*
argument_list|>
operator|::
name|const_iterator
name|i
init|=
name|mScreens
operator|.
name|constBegin
argument_list|()
decl_stmt|;
name|QList
argument_list|<
name|QFbScreen
modifier|*
argument_list|>
operator|::
name|const_iterator
name|end
init|=
name|mScreens
operator|.
name|constEnd
argument_list|()
decl_stmt|;
while|while
condition|(
name|i
operator|!=
name|end
condition|)
block|{
operator|(
operator|*
name|i
operator|)
operator|->
name|removeWindow
argument_list|(
name|this
argument_list|)
expr_stmt|;
operator|++
name|i
expr_stmt|;
block|}
block|}
end_destructor
begin_constructor
DECL|function|QFbWindowSurface
name|QFbWindowSurface
operator|::
name|QFbWindowSurface
parameter_list|(
name|QFbScreen
modifier|*
name|screen
parameter_list|,
name|QWidget
modifier|*
name|window
parameter_list|)
member_init_list|:
name|QWindowSurface
argument_list|(
name|window
argument_list|)
member_init_list|,
name|mScreen
argument_list|(
name|screen
argument_list|)
block|{
name|mImage
operator|=
name|QImage
argument_list|(
name|window
operator|->
name|size
argument_list|()
argument_list|,
name|mScreen
operator|->
name|format
argument_list|()
argument_list|)
expr_stmt|;
name|platformWindow
operator|=
cast|static_cast
argument_list|<
name|QFbWindow
operator|*
argument_list|>
argument_list|(
name|window
operator|->
name|platformWindow
argument_list|()
argument_list|)
expr_stmt|;
name|platformWindow
operator|->
name|surface
operator|=
name|this
expr_stmt|;
block|}
end_constructor
begin_destructor
DECL|function|~QFbWindowSurface
name|QFbWindowSurface
operator|::
name|~
name|QFbWindowSurface
parameter_list|()
block|{ }
end_destructor
begin_function
DECL|function|flush
name|void
name|QFbWindowSurface
operator|::
name|flush
parameter_list|(
name|QWidget
modifier|*
name|widget
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
name|widget
argument_list|)
expr_stmt|;
name|Q_UNUSED
argument_list|(
name|offset
argument_list|)
expr_stmt|;
comment|//    qDebug()<< "QFbWindowSurface::flush"<< region;
name|platformWindow
operator|->
name|repaint
argument_list|(
name|region
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|repaint
name|void
name|QFbWindow
operator|::
name|repaint
parameter_list|(
specifier|const
name|QRegion
modifier|&
name|region
parameter_list|)
block|{
name|QRect
name|currentGeometry
init|=
name|geometry
argument_list|()
decl_stmt|;
name|QRect
name|dirtyClient
init|=
name|region
operator|.
name|boundingRect
argument_list|()
decl_stmt|;
name|QRect
name|dirtyRegion
argument_list|(
name|currentGeometry
operator|.
name|left
argument_list|()
operator|+
name|dirtyClient
operator|.
name|left
argument_list|()
argument_list|,
name|currentGeometry
operator|.
name|top
argument_list|()
operator|+
name|dirtyClient
operator|.
name|top
argument_list|()
argument_list|,
name|dirtyClient
operator|.
name|width
argument_list|()
argument_list|,
name|dirtyClient
operator|.
name|height
argument_list|()
argument_list|)
decl_stmt|;
name|QList
argument_list|<
name|QFbScreen
modifier|*
argument_list|>
operator|::
name|const_iterator
name|i
init|=
name|mScreens
operator|.
name|constBegin
argument_list|()
decl_stmt|;
name|QList
argument_list|<
name|QFbScreen
modifier|*
argument_list|>
operator|::
name|const_iterator
name|end
init|=
name|mScreens
operator|.
name|constEnd
argument_list|()
decl_stmt|;
name|QRect
name|oldGeometryLocal
init|=
name|oldGeometry
decl_stmt|;
name|oldGeometry
operator|=
name|currentGeometry
expr_stmt|;
while|while
condition|(
name|i
operator|!=
name|end
condition|)
block|{
comment|// If this is a move, redraw the previous location
if|if
condition|(
name|oldGeometryLocal
operator|!=
name|currentGeometry
condition|)
block|{
operator|(
operator|*
name|i
operator|)
operator|->
name|setDirty
argument_list|(
name|oldGeometryLocal
argument_list|)
expr_stmt|;
block|}
operator|(
operator|*
name|i
operator|)
operator|->
name|setDirty
argument_list|(
name|dirtyRegion
argument_list|)
expr_stmt|;
operator|++
name|i
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|resize
name|void
name|QFbWindowSurface
operator|::
name|resize
parameter_list|(
specifier|const
name|QSize
modifier|&
name|size
parameter_list|)
block|{
comment|// change the widget's QImage if this is a resize
if|if
condition|(
name|mImage
operator|.
name|size
argument_list|()
operator|!=
name|size
condition|)
name|mImage
operator|=
name|QImage
argument_list|(
name|size
argument_list|,
name|mScreen
operator|->
name|format
argument_list|()
argument_list|)
expr_stmt|;
name|QWindowSurface
operator|::
name|resize
argument_list|(
name|size
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|setGeometry
name|void
name|QFbWindow
operator|::
name|setGeometry
parameter_list|(
specifier|const
name|QRect
modifier|&
name|rect
parameter_list|)
block|{
comment|// store previous geometry for screen update
name|oldGeometry
operator|=
name|geometry
argument_list|()
expr_stmt|;
name|QList
argument_list|<
name|QFbScreen
modifier|*
argument_list|>
operator|::
name|const_iterator
name|i
init|=
name|mScreens
operator|.
name|constBegin
argument_list|()
decl_stmt|;
name|QList
argument_list|<
name|QFbScreen
modifier|*
argument_list|>
operator|::
name|const_iterator
name|end
init|=
name|mScreens
operator|.
name|constEnd
argument_list|()
decl_stmt|;
while|while
condition|(
name|i
operator|!=
name|end
condition|)
block|{
operator|(
operator|*
name|i
operator|)
operator|->
name|invalidateRectCache
argument_list|()
expr_stmt|;
operator|++
name|i
expr_stmt|;
block|}
comment|//###    QWindowSystemInterface::handleGeometryChange(window(), rect);
name|QPlatformWindow
operator|::
name|setGeometry
argument_list|(
name|rect
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|scroll
name|bool
name|QFbWindowSurface
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
return|return
name|QWindowSurface
operator|::
name|scroll
argument_list|(
name|area
argument_list|,
name|dx
argument_list|,
name|dy
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|beginPaint
name|void
name|QFbWindowSurface
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
block|}
end_function
begin_function
DECL|function|endPaint
name|void
name|QFbWindowSurface
operator|::
name|endPaint
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
block|}
end_function
begin_function
DECL|function|setVisible
name|void
name|QFbWindow
operator|::
name|setVisible
parameter_list|(
name|bool
name|visible
parameter_list|)
block|{
name|visibleFlag
operator|=
name|visible
expr_stmt|;
name|QList
argument_list|<
name|QFbScreen
modifier|*
argument_list|>
operator|::
name|const_iterator
name|i
init|=
name|mScreens
operator|.
name|constBegin
argument_list|()
decl_stmt|;
name|QList
argument_list|<
name|QFbScreen
modifier|*
argument_list|>
operator|::
name|const_iterator
name|end
init|=
name|mScreens
operator|.
name|constEnd
argument_list|()
decl_stmt|;
while|while
condition|(
name|i
operator|!=
name|end
condition|)
block|{
operator|(
operator|*
name|i
operator|)
operator|->
name|invalidateRectCache
argument_list|()
expr_stmt|;
operator|(
operator|*
name|i
operator|)
operator|->
name|setDirty
argument_list|(
name|geometry
argument_list|()
argument_list|)
expr_stmt|;
operator|++
name|i
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|setWindowFlags
name|Qt
operator|::
name|WindowFlags
name|QFbWindow
operator|::
name|setWindowFlags
parameter_list|(
name|Qt
operator|::
name|WindowFlags
name|type
parameter_list|)
block|{
name|flags
operator|=
name|type
expr_stmt|;
name|QList
argument_list|<
name|QFbScreen
modifier|*
argument_list|>
operator|::
name|const_iterator
name|i
init|=
name|mScreens
operator|.
name|constBegin
argument_list|()
decl_stmt|;
name|QList
argument_list|<
name|QFbScreen
modifier|*
argument_list|>
operator|::
name|const_iterator
name|end
init|=
name|mScreens
operator|.
name|constEnd
argument_list|()
decl_stmt|;
while|while
condition|(
name|i
operator|!=
name|end
condition|)
block|{
operator|(
operator|*
name|i
operator|)
operator|->
name|invalidateRectCache
argument_list|()
expr_stmt|;
operator|++
name|i
expr_stmt|;
block|}
return|return
name|flags
return|;
block|}
end_function
begin_function
DECL|function|windowFlags
name|Qt
operator|::
name|WindowFlags
name|QFbWindow
operator|::
name|windowFlags
parameter_list|()
specifier|const
block|{
return|return
name|flags
return|;
block|}
end_function
end_unit
