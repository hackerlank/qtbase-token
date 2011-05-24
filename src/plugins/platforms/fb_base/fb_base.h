begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QLIGHTHOUSEGRAPHICSSCREEN_H
end_ifndef
begin_define
DECL|macro|QLIGHTHOUSEGRAPHICSSCREEN_H
define|#
directive|define
name|QLIGHTHOUSEGRAPHICSSCREEN_H
end_define
begin_include
include|#
directive|include
file|<qrect.h>
end_include
begin_include
include|#
directive|include
file|<qimage.h>
end_include
begin_include
include|#
directive|include
file|<qtimer.h>
end_include
begin_include
include|#
directive|include
file|<qpainter.h>
end_include
begin_include
include|#
directive|include
file|<QPlatformCursor>
end_include
begin_include
include|#
directive|include
file|<QPlatformScreen>
end_include
begin_include
include|#
directive|include
file|<QPlatformWindow>
end_include
begin_include
include|#
directive|include
file|<QtGui/private/qwindowsurface_p.h>
end_include
begin_decl_stmt
DECL|variable|QMouseEvent
name|class
name|QMouseEvent
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QSize
name|class
name|QSize
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QPainter
name|class
name|QPainter
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QFbScreen
name|class
name|QFbScreen
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QPlatformSoftwareCursor
range|:
name|public
name|QPlatformCursor
block|{
name|public
operator|:
name|QPlatformSoftwareCursor
argument_list|(
name|QPlatformScreen
operator|*
name|scr
argument_list|)
block|;
comment|// output methods
name|QRect
name|dirtyRect
argument_list|()
block|;
name|virtual
name|QRect
name|drawCursor
argument_list|(
name|QPainter
operator|&
name|painter
argument_list|)
block|;
comment|// input methods
name|virtual
name|void
name|pointerEvent
argument_list|(
specifier|const
name|QMouseEvent
operator|&
name|event
argument_list|)
block|;
name|virtual
name|void
name|changeCursor
argument_list|(
name|QCursor
operator|*
name|widgetCursor
argument_list|,
name|QWidget
operator|*
name|widget
argument_list|)
block|;
name|virtual
name|void
name|setDirty
argument_list|()
block|{
name|dirty
operator|=
name|true
block|;
name|screen
operator|->
name|setDirty
argument_list|(
name|QRect
argument_list|()
argument_list|)
block|; }
name|virtual
name|bool
name|isDirty
argument_list|()
block|{
return|return
name|dirty
return|;
block|}
name|virtual
name|bool
name|isOnScreen
argument_list|()
block|{
return|return
name|onScreen
return|;
block|}
name|virtual
name|QRect
name|lastPainted
argument_list|()
block|{
return|return
name|prevRect
return|;
block|}
name|protected
operator|:
name|QPlatformCursorImage
operator|*
name|graphic
block|;
name|private
operator|:
name|void
name|setCursor
argument_list|(
argument|const uchar *data
argument_list|,
argument|const uchar *mask
argument_list|,
argument|int width
argument_list|,
argument|int height
argument_list|,
argument|int hotX
argument_list|,
argument|int hotY
argument_list|)
block|;
name|void
name|setCursor
argument_list|(
argument|Qt::CursorShape shape
argument_list|)
block|;
name|void
name|setCursor
argument_list|(
argument|const QImage&image
argument_list|,
argument|int hotx
argument_list|,
argument|int hoty
argument_list|)
block|;
name|QRect
name|currentRect
block|;
comment|// next place to draw the cursor
name|QRect
name|prevRect
block|;
comment|// last place the cursor was drawn
name|QRect
name|getCurrentRect
argument_list|()
block|;
name|bool
name|dirty
block|;
name|bool
name|onScreen
block|; }
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QFbWindow
name|class
name|QFbWindow
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QFbWindowSurface
range|:
name|public
name|QWindowSurface
block|{
name|public
operator|:
name|QFbWindowSurface
argument_list|(
name|QFbScreen
operator|*
name|screen
argument_list|,
name|QWidget
operator|*
name|window
argument_list|)
block|;
operator|~
name|QFbWindowSurface
argument_list|()
block|;
name|virtual
name|QPaintDevice
operator|*
name|paintDevice
argument_list|()
block|{
return|return
operator|&
name|mImage
return|;
block|}
name|virtual
name|void
name|flush
argument_list|(
name|QWidget
operator|*
name|widget
argument_list|,
specifier|const
name|QRegion
operator|&
name|region
argument_list|,
specifier|const
name|QPoint
operator|&
name|offset
argument_list|)
block|;
name|virtual
name|bool
name|scroll
argument_list|(
argument|const QRegion&area
argument_list|,
argument|int dx
argument_list|,
argument|int dy
argument_list|)
block|;
name|virtual
name|void
name|beginPaint
argument_list|(
specifier|const
name|QRegion
operator|&
name|region
argument_list|)
block|;
name|virtual
name|void
name|endPaint
argument_list|(
specifier|const
name|QRegion
operator|&
name|region
argument_list|)
block|;
specifier|const
name|QImage
name|image
argument_list|()
block|{
return|return
name|mImage
return|;
block|}
name|void
name|resize
argument_list|(
specifier|const
name|QSize
operator|&
name|size
argument_list|)
block|;
name|protected
operator|:
name|friend
name|class
name|QFbWindow
block|;
name|QFbWindow
operator|*
name|platformWindow
block|;
name|QFbScreen
operator|*
name|mScreen
block|;
name|QImage
name|mImage
block|; }
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QFbWindow
range|:
name|public
name|QPlatformWindow
block|{
name|public
operator|:
name|QFbWindow
argument_list|(
name|QWidget
operator|*
name|window
argument_list|)
block|;
operator|~
name|QFbWindow
argument_list|()
block|;
name|virtual
name|void
name|setVisible
argument_list|(
argument|bool visible
argument_list|)
block|;
name|virtual
name|bool
name|visible
argument_list|()
block|{
return|return
name|visibleFlag
return|;
block|}
name|virtual
name|void
name|raise
argument_list|()
block|;
name|virtual
name|void
name|lower
argument_list|()
block|;
name|void
name|setGeometry
argument_list|(
specifier|const
name|QRect
operator|&
name|rect
argument_list|)
block|;
name|virtual
name|Qt
operator|::
name|WindowFlags
name|setWindowFlags
argument_list|(
argument|Qt::WindowFlags type
argument_list|)
block|;
name|virtual
name|Qt
operator|::
name|WindowFlags
name|windowFlags
argument_list|()
specifier|const
block|;
name|WId
name|winId
argument_list|()
specifier|const
block|{
return|return
name|windowId
return|;
block|}
name|virtual
name|void
name|repaint
argument_list|(
specifier|const
name|QRegion
operator|&
argument_list|)
block|;
name|protected
operator|:
name|friend
name|class
name|QFbWindowSurface
block|;
name|friend
name|class
name|QFbScreen
block|;
name|QFbWindowSurface
operator|*
name|surface
block|;
name|QList
operator|<
name|QFbScreen
operator|*
operator|>
name|mScreens
block|;
name|QRect
name|oldGeometry
block|;
name|bool
name|visibleFlag
block|;
name|Qt
operator|::
name|WindowFlags
name|flags
block|;
name|WId
name|windowId
block|; }
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QFbScreen
range|:
name|public
name|QPlatformScreen
block|{
name|Q_OBJECT
name|public
operator|:
name|QFbScreen
argument_list|()
block|;
operator|~
name|QFbScreen
argument_list|()
block|;
name|virtual
name|QRect
name|geometry
argument_list|()
specifier|const
block|{
return|return
name|mGeometry
return|;
block|}
name|virtual
name|int
name|depth
argument_list|()
specifier|const
block|{
return|return
name|mDepth
return|;
block|}
name|virtual
name|QImage
operator|::
name|Format
name|format
argument_list|()
specifier|const
block|{
return|return
name|mFormat
return|;
block|}
name|virtual
name|QSize
name|physicalSize
argument_list|()
specifier|const
block|{
return|return
name|mPhysicalSize
return|;
block|}
name|virtual
name|void
name|setGeometry
argument_list|(
argument|QRect rect
argument_list|)
block|;
name|virtual
name|void
name|setDepth
argument_list|(
argument|int depth
argument_list|)
block|;
name|virtual
name|void
name|setFormat
argument_list|(
argument|QImage::Format format
argument_list|)
block|;
name|virtual
name|void
name|setPhysicalSize
argument_list|(
argument|QSize size
argument_list|)
block|;
name|virtual
name|void
name|setDirty
argument_list|(
specifier|const
name|QRect
operator|&
name|rect
argument_list|)
block|;
name|virtual
name|void
name|removeWindow
argument_list|(
name|QFbWindow
operator|*
name|surface
argument_list|)
block|;
name|virtual
name|void
name|addWindow
argument_list|(
name|QFbWindow
operator|*
name|surface
argument_list|)
block|;
name|virtual
name|void
name|raise
argument_list|(
name|QPlatformWindow
operator|*
name|surface
argument_list|)
block|;
name|virtual
name|void
name|lower
argument_list|(
name|QPlatformWindow
operator|*
name|surface
argument_list|)
block|;
name|virtual
name|QWidget
operator|*
name|topLevelAt
argument_list|(
argument|const QPoint& p
argument_list|)
specifier|const
block|;
name|QImage
operator|*
name|image
argument_list|()
specifier|const
block|{
return|return
name|mScreenImage
return|;
block|}
name|QPaintDevice
operator|*
name|paintDevice
argument_list|()
specifier|const
block|{
return|return
name|mScreenImage
return|;
block|}
name|protected
operator|:
name|QList
operator|<
name|QFbWindow
operator|*
operator|>
name|windowStack
block|;
name|QRegion
name|repaintRegion
block|;
name|QPlatformSoftwareCursor
operator|*
name|cursor
block|;
name|QTimer
name|redrawTimer
block|;
name|protected
name|slots
operator|:
name|virtual
name|QRegion
name|doRedraw
argument_list|()
block|;
name|protected
operator|:
name|QRect
name|mGeometry
block|;
name|int
name|mDepth
block|;
name|QImage
operator|::
name|Format
name|mFormat
block|;
name|QSize
name|mPhysicalSize
block|;
name|QImage
operator|*
name|mScreenImage
block|;
name|private
operator|:
name|QPainter
operator|*
name|compositePainter
block|;
name|void
name|generateRects
argument_list|()
block|;
name|QList
operator|<
name|QPair
operator|<
name|QRect
block|,
name|int
operator|>
expr|>
name|cachedRects
block|;
name|void
name|invalidateRectCache
argument_list|()
block|{
name|isUpToDate
operator|=
name|false
block|; }
name|friend
name|class
name|QFbWindowSurface
block|;
name|friend
name|class
name|QFbWindow
block|;
name|bool
name|isUpToDate
block|; }
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QLIGHTHOUSEGRAPHICSSCREEN_H
end_comment
end_unit
