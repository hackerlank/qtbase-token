begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qvncintegration.h"
end_include
begin_include
include|#
directive|include
file|"../fb_base/fb_base.h"
end_include
begin_include
include|#
directive|include
file|<private/qapplication_p.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/private/qpixmap_raster_p.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qdebug.h>
end_include
begin_include
include|#
directive|include
file|<qvncserver.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/QPainter>
end_include
begin_include
include|#
directive|include
file|<QtCore/QTimer>
end_include
begin_include
include|#
directive|include
file|"qgenericunixfontdatabase.h"
end_include
begin_constructor
DECL|function|QVNCScreen
name|QVNCScreen
operator|::
name|QVNCScreen
parameter_list|(
name|QRect
name|screenSize
parameter_list|,
name|int
name|screenId
parameter_list|)
member_init_list|:
name|QFbScreen
operator|::
name|QFbScreen
argument_list|()
block|{
name|setGeometry
argument_list|(
name|screenSize
argument_list|)
expr_stmt|;
name|setDepth
argument_list|(
literal|32
argument_list|)
expr_stmt|;
name|setFormat
argument_list|(
name|QImage
operator|::
name|Format_RGB32
argument_list|)
expr_stmt|;
name|setPhysicalSize
argument_list|(
operator|(
name|geometry
argument_list|()
operator|.
name|size
argument_list|()
operator|*
literal|254
operator|)
operator|/
literal|720
argument_list|)
expr_stmt|;
name|d_ptr
operator|=
operator|new
name|QVNCScreenPrivate
argument_list|(
name|this
argument_list|,
name|screenId
argument_list|)
expr_stmt|;
name|cursor
operator|=
operator|new
name|QVNCCursor
argument_list|(
name|d_ptr
operator|->
name|vncServer
argument_list|,
name|this
argument_list|)
expr_stmt|;
name|d_ptr
operator|->
name|vncServer
operator|->
name|setCursor
argument_list|(
cast|static_cast
argument_list|<
name|QVNCCursor
operator|*
argument_list|>
argument_list|(
name|cursor
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_function
DECL|function|dirtyMap
name|QVNCDirtyMap
modifier|*
name|QVNCScreen
operator|::
name|dirtyMap
parameter_list|()
block|{
return|return
name|d_ptr
operator|->
name|dirty
return|;
block|}
end_function
begin_function
DECL|function|doRedraw
name|QRegion
name|QVNCScreen
operator|::
name|doRedraw
parameter_list|()
block|{
name|QRegion
name|touched
decl_stmt|;
name|touched
operator|=
name|QFbScreen
operator|::
name|doRedraw
argument_list|()
expr_stmt|;
name|QVector
argument_list|<
name|QRect
argument_list|>
name|rects
init|=
name|touched
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
name|i
operator|++
control|)
name|d_ptr
operator|->
name|setDirty
argument_list|(
name|rects
index|[
name|i
index|]
argument_list|)
expr_stmt|;
return|return
name|touched
return|;
block|}
end_function
begin_function
DECL|function|defaultWidth
specifier|static
specifier|inline
name|int
name|defaultWidth
parameter_list|()
block|{
return|return
literal|800
return|;
block|}
end_function
begin_function
DECL|function|defaultHeight
specifier|static
specifier|inline
name|int
name|defaultHeight
parameter_list|()
block|{
return|return
literal|600
return|;
block|}
end_function
begin_function
DECL|function|defaultDisplay
specifier|static
specifier|inline
name|int
name|defaultDisplay
parameter_list|()
block|{
return|return
literal|0
return|;
block|}
end_function
begin_function
DECL|function|usage
specifier|static
name|void
name|usage
parameter_list|()
block|{
name|qWarning
argument_list|()
operator|<<
literal|"VNC Platform Integration options:"
expr_stmt|;
name|qWarning
argument_list|()
operator|<<
literal|"    size=<Width>x<Height> - set the display width and height"
expr_stmt|;
name|qWarning
argument_list|()
operator|<<
literal|"         defaults to"
operator|<<
name|defaultWidth
argument_list|()
operator|<<
literal|"x"
operator|<<
name|defaultHeight
argument_list|()
expr_stmt|;
name|qWarning
argument_list|()
operator|<<
literal|"    display=<ID> - set the VNC display port to ID + 5900"
expr_stmt|;
name|qWarning
argument_list|()
operator|<<
literal|"         defaults to"
operator|<<
name|defaultDisplay
argument_list|()
expr_stmt|;
name|qWarning
argument_list|()
operator|<<
literal|"    offset=<X>x<Y> - set the current screens offset"
expr_stmt|;
name|qWarning
argument_list|()
operator|<<
literal|"    vnc - start configuration of a new screen"
expr_stmt|;
name|qWarning
argument_list|()
operator|<<
literal|"         size and offset are inherited from the previous screen if not set"
expr_stmt|;
name|qWarning
argument_list|()
operator|<<
literal|"         display id is incremented from the previous screen if not set"
expr_stmt|;
name|qWarning
argument_list|()
operator|<<
literal|"    virtual - manage the set of screens as a virtual desktop"
expr_stmt|;
block|}
end_function
begin_constructor
DECL|function|QVNCIntegration
name|QVNCIntegration
operator|::
name|QVNCIntegration
parameter_list|(
specifier|const
name|QStringList
modifier|&
name|paramList
parameter_list|)
member_init_list|:
name|virtualDesktop
argument_list|(
literal|false
argument_list|)
member_init_list|,
name|fontDb
argument_list|(
operator|new
name|QGenericUnixFontDatabase
argument_list|()
argument_list|)
block|{
name|int
name|sizeX
init|=
name|defaultWidth
argument_list|()
decl_stmt|;
name|int
name|sizeY
init|=
name|defaultHeight
argument_list|()
decl_stmt|;
name|int
name|offsetX
init|=
literal|0
decl_stmt|;
name|int
name|offsetY
init|=
literal|0
decl_stmt|;
name|int
name|display
init|=
name|defaultDisplay
argument_list|()
decl_stmt|;
name|bool
name|showUsage
init|=
literal|false
decl_stmt|;
foreach|foreach
control|(
name|QString
name|confString
decl|,
name|paramList
control|)
block|{
if|if
condition|(
name|confString
operator|.
name|startsWith
argument_list|(
name|QLatin1String
argument_list|(
literal|"size="
argument_list|)
argument_list|)
condition|)
block|{
name|QString
name|val
init|=
name|confString
operator|.
name|section
argument_list|(
name|QLatin1Char
argument_list|(
literal|'='
argument_list|)
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|)
decl_stmt|;
name|sizeX
operator|=
name|val
operator|.
name|section
argument_list|(
name|QLatin1Char
argument_list|(
literal|'x'
argument_list|)
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
operator|.
name|toInt
argument_list|()
expr_stmt|;
name|sizeY
operator|=
name|val
operator|.
name|section
argument_list|(
name|QLatin1Char
argument_list|(
literal|'x'
argument_list|)
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|)
operator|.
name|toInt
argument_list|()
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|confString
operator|.
name|startsWith
argument_list|(
name|QLatin1String
argument_list|(
literal|"display="
argument_list|)
argument_list|)
condition|)
block|{
name|display
operator|=
name|confString
operator|.
name|section
argument_list|(
name|QLatin1Char
argument_list|(
literal|'='
argument_list|)
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|)
operator|.
name|toInt
argument_list|()
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|confString
operator|.
name|startsWith
argument_list|(
name|QLatin1String
argument_list|(
literal|"offset="
argument_list|)
argument_list|)
condition|)
block|{
name|QString
name|val
init|=
name|confString
operator|.
name|section
argument_list|(
name|QLatin1Char
argument_list|(
literal|'='
argument_list|)
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|)
decl_stmt|;
name|offsetX
operator|=
name|val
operator|.
name|section
argument_list|(
name|QLatin1Char
argument_list|(
literal|'x'
argument_list|)
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
operator|.
name|toInt
argument_list|()
expr_stmt|;
name|offsetY
operator|=
name|val
operator|.
name|section
argument_list|(
name|QLatin1Char
argument_list|(
literal|'x'
argument_list|)
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|)
operator|.
name|toInt
argument_list|()
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|confString
operator|==
name|QLatin1String
argument_list|(
literal|"vnc"
argument_list|)
condition|)
block|{
name|QRect
name|screenRect
argument_list|(
name|offsetX
argument_list|,
name|offsetY
argument_list|,
name|sizeX
argument_list|,
name|sizeY
argument_list|)
decl_stmt|;
name|QVNCScreen
modifier|*
name|screen
init|=
operator|new
name|QVNCScreen
argument_list|(
name|screenRect
argument_list|,
name|display
argument_list|)
decl_stmt|;
name|mScreens
operator|.
name|append
argument_list|(
name|screen
argument_list|)
expr_stmt|;
name|screen
operator|->
name|setObjectName
argument_list|(
name|QString
argument_list|(
literal|"screen %1"
argument_list|)
operator|.
name|arg
argument_list|(
name|display
argument_list|)
argument_list|)
expr_stmt|;
name|screen
operator|->
name|setDirty
argument_list|(
name|screenRect
argument_list|)
expr_stmt|;
operator|++
name|display
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|confString
operator|==
name|QLatin1String
argument_list|(
literal|"virtual"
argument_list|)
condition|)
block|{
name|virtualDesktop
operator|=
literal|true
expr_stmt|;
block|}
else|else
block|{
name|qWarning
argument_list|()
operator|<<
literal|"Unknown VNC option:"
operator|<<
name|confString
expr_stmt|;
name|showUsage
operator|=
literal|true
expr_stmt|;
block|}
block|}
if|if
condition|(
name|showUsage
condition|)
name|usage
argument_list|()
expr_stmt|;
name|QRect
name|screenRect
argument_list|(
name|offsetX
argument_list|,
name|offsetY
argument_list|,
name|sizeX
argument_list|,
name|sizeY
argument_list|)
decl_stmt|;
name|QVNCScreen
modifier|*
name|screen
init|=
operator|new
name|QVNCScreen
argument_list|(
name|screenRect
argument_list|,
name|display
argument_list|)
decl_stmt|;
name|mScreens
operator|.
name|append
argument_list|(
name|screen
argument_list|)
expr_stmt|;
name|mPrimaryScreen
operator|=
name|qobject_cast
argument_list|<
name|QVNCScreen
operator|*
argument_list|>
argument_list|(
name|mScreens
operator|.
name|first
argument_list|()
argument_list|)
expr_stmt|;
name|screen
operator|->
name|setObjectName
argument_list|(
name|QString
argument_list|(
literal|"screen %1"
argument_list|)
operator|.
name|arg
argument_list|(
name|display
argument_list|)
argument_list|)
expr_stmt|;
name|screen
operator|->
name|setDirty
argument_list|(
name|screenRect
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_function
DECL|function|hasCapability
name|bool
name|QVNCIntegration
operator|::
name|hasCapability
parameter_list|(
name|QPlatformIntegration
operator|::
name|Capability
name|cap
parameter_list|)
specifier|const
block|{
switch|switch
condition|(
name|cap
condition|)
block|{
case|case
name|ThreadedPixmaps
case|:
return|return
literal|true
return|;
default|default:
return|return
name|QPlatformIntegration
operator|::
name|hasCapability
argument_list|(
name|cap
argument_list|)
return|;
block|}
block|}
end_function
begin_function
DECL|function|createPixmapData
name|QPixmapData
modifier|*
name|QVNCIntegration
operator|::
name|createPixmapData
parameter_list|(
name|QPixmapData
operator|::
name|PixelType
name|type
parameter_list|)
specifier|const
block|{
return|return
operator|new
name|QRasterPixmapData
argument_list|(
name|type
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|createWindowSurface
name|QWindowSurface
modifier|*
name|QVNCIntegration
operator|::
name|createWindowSurface
parameter_list|(
name|QWidget
modifier|*
name|widget
parameter_list|,
name|WId
parameter_list|)
specifier|const
block|{
name|QFbWindowSurface
modifier|*
name|surface
decl_stmt|;
name|surface
operator|=
operator|new
name|QFbWindowSurface
argument_list|(
name|mPrimaryScreen
argument_list|,
name|widget
argument_list|)
expr_stmt|;
return|return
name|surface
return|;
block|}
end_function
begin_function
DECL|function|createEventDispatcher
name|QAbstractEventDispatcher
modifier|*
name|QVFbIntegration
operator|::
name|createEventDispatcher
parameter_list|()
specifier|const
block|{
return|return
name|createUnixEventDispatcher
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|createPlatformWindow
name|QPlatformWindow
modifier|*
name|QVNCIntegration
operator|::
name|createPlatformWindow
parameter_list|(
name|QWidget
modifier|*
name|widget
parameter_list|,
name|WId
comment|/*winId*/
parameter_list|)
specifier|const
block|{
name|QFbWindow
modifier|*
name|w
init|=
operator|new
name|QFbWindow
argument_list|(
name|widget
argument_list|)
decl_stmt|;
if|if
condition|(
name|virtualDesktop
condition|)
block|{
name|QList
argument_list|<
name|QPlatformScreen
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
name|QPlatformScreen
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
name|QFbScreen
modifier|*
name|screen
decl_stmt|;
while|while
condition|(
name|i
operator|!=
name|end
condition|)
block|{
name|screen
operator|=
cast|static_cast
argument_list|<
name|QFbScreen
operator|*
argument_list|>
argument_list|(
operator|*
name|i
argument_list|)
expr_stmt|;
name|screen
operator|->
name|addWindow
argument_list|(
name|w
argument_list|)
expr_stmt|;
operator|++
name|i
expr_stmt|;
block|}
block|}
else|else
name|mPrimaryScreen
operator|->
name|addWindow
argument_list|(
name|w
argument_list|)
expr_stmt|;
return|return
name|w
return|;
block|}
end_function
begin_function
DECL|function|grabWindow
name|QPixmap
name|QVNCIntegration
operator|::
name|grabWindow
parameter_list|(
name|WId
name|window
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
comment|//    qDebug()<< "QVNCIntegration::grabWindow"<< window<< x<< y<< width<< height;
if|if
condition|(
name|window
operator|==
literal|0
condition|)
block|{
comment|//desktop
name|QImage
modifier|*
name|desktopImage
init|=
name|mPrimaryScreen
operator|->
name|image
argument_list|()
decl_stmt|;
if|if
condition|(
name|x
operator|==
literal|0
operator|&&
name|y
operator|==
literal|0
operator|&&
name|width
operator|<
literal|0
operator|&&
name|height
operator|<
literal|0
condition|)
block|{
return|return
name|QPixmap
operator|::
name|fromImage
argument_list|(
operator|*
name|desktopImage
argument_list|)
return|;
block|}
if|if
condition|(
name|width
operator|<
literal|0
condition|)
name|width
operator|=
name|desktopImage
operator|->
name|width
argument_list|()
operator|-
name|x
expr_stmt|;
if|if
condition|(
name|height
operator|<
literal|0
condition|)
name|height
operator|=
name|desktopImage
operator|->
name|height
argument_list|()
operator|-
name|y
expr_stmt|;
name|int
name|bytesPerPixel
init|=
name|desktopImage
operator|->
name|depth
argument_list|()
operator|/
literal|8
decl_stmt|;
comment|//We don't support 1, 2, or 4 bpp
name|QImage
name|img
argument_list|(
name|desktopImage
operator|->
name|scanLine
argument_list|(
name|y
argument_list|)
operator|+
name|bytesPerPixel
operator|*
name|x
argument_list|,
name|width
argument_list|,
name|height
argument_list|,
name|desktopImage
operator|->
name|bytesPerLine
argument_list|()
argument_list|,
name|desktopImage
operator|->
name|format
argument_list|()
argument_list|)
decl_stmt|;
return|return
name|QPixmap
operator|::
name|fromImage
argument_list|(
name|img
argument_list|)
return|;
block|}
name|QWidget
modifier|*
name|win
init|=
name|QWidget
operator|::
name|find
argument_list|(
name|window
argument_list|)
decl_stmt|;
if|if
condition|(
name|win
condition|)
block|{
name|QRect
name|r
init|=
name|win
operator|->
name|geometry
argument_list|()
decl_stmt|;
if|if
condition|(
name|width
operator|<
literal|0
condition|)
name|width
operator|=
name|r
operator|.
name|width
argument_list|()
operator|-
name|x
expr_stmt|;
if|if
condition|(
name|height
operator|<
literal|0
condition|)
name|height
operator|=
name|r
operator|.
name|height
argument_list|()
operator|-
name|y
expr_stmt|;
name|QImage
modifier|*
name|desktopImage
init|=
name|mPrimaryScreen
operator|->
name|image
argument_list|()
decl_stmt|;
name|int
name|bytesPerPixel
init|=
name|desktopImage
operator|->
name|depth
argument_list|()
operator|/
literal|8
decl_stmt|;
comment|//We don't support 1, 2, or 4 bpp
name|QImage
name|img
argument_list|(
name|desktopImage
operator|->
name|scanLine
argument_list|(
name|r
operator|.
name|top
argument_list|()
operator|+
name|y
argument_list|)
operator|+
name|bytesPerPixel
operator|*
operator|(
name|r
operator|.
name|left
argument_list|()
operator|+
name|x
operator|)
argument_list|,
name|width
argument_list|,
name|height
argument_list|,
name|desktopImage
operator|->
name|bytesPerLine
argument_list|()
argument_list|,
name|desktopImage
operator|->
name|format
argument_list|()
argument_list|)
decl_stmt|;
return|return
name|QPixmap
operator|::
name|fromImage
argument_list|(
name|img
argument_list|)
return|;
block|}
return|return
name|QPixmap
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|moveToScreen
name|void
name|QVNCIntegration
operator|::
name|moveToScreen
parameter_list|(
name|QWidget
modifier|*
name|window
parameter_list|,
name|int
name|screen
parameter_list|)
block|{
if|if
condition|(
name|virtualDesktop
condition|)
block|{
comment|// all windows exist on all screens in virtual desktop mode
return|return;
block|}
if|if
condition|(
name|screen
argument_list|<
literal|0
operator|||
name|screen
argument_list|>
name|mScreens
operator|.
name|size
argument_list|()
condition|)
return|return;
name|QVNCScreen
modifier|*
name|newScreen
init|=
name|qobject_cast
argument_list|<
name|QVNCScreen
operator|*
argument_list|>
argument_list|(
name|mScreens
operator|.
name|at
argument_list|(
name|screen
argument_list|)
argument_list|)
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
name|mScreens
operator|.
name|size
argument_list|()
condition|;
name|i
operator|++
control|)
block|{
name|QVNCScreen
modifier|*
name|oldScreen
init|=
name|qobject_cast
argument_list|<
name|QVNCScreen
operator|*
argument_list|>
argument_list|(
name|mScreens
operator|.
name|at
argument_list|(
name|i
argument_list|)
argument_list|)
decl_stmt|;
if|if
condition|(
name|oldScreen
operator|->
name|windowStack
operator|.
name|contains
argument_list|(
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
argument_list|)
condition|)
block|{
name|oldScreen
operator|->
name|removeWindow
argument_list|(
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
argument_list|)
expr_stmt|;
break|break;
block|}
block|}
name|window
operator|->
name|platformWindow
argument_list|()
operator|->
name|setGeometry
argument_list|(
name|window
operator|->
name|geometry
argument_list|()
argument_list|)
expr_stmt|;
comment|// this should be unified elsewhere
name|newScreen
operator|->
name|addWindow
argument_list|(
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
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|fontDatabase
name|QPlatformFontDatabase
modifier|*
name|QVNCIntegration
operator|::
name|fontDatabase
parameter_list|()
specifier|const
block|{
return|return
name|fontDb
return|;
block|}
end_function
end_unit
