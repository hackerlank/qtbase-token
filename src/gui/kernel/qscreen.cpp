begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qscreen.h"
end_include
begin_include
include|#
directive|include
file|"qscreen_p.h"
end_include
begin_include
include|#
directive|include
file|"qpixmap.h"
end_include
begin_include
include|#
directive|include
file|<qpa/qplatformscreen.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/private/qobject_p.h>
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_comment
comment|/*!     \class QScreen     \since 5.0     \brief The QScreen class is used to query screen properties.      A note on logical vs physical dots per inch: physical DPI is based on the     actual physical pixel sizes when available, and is useful for print preview     and other cases where it's desirable to know the exact physical dimensions     of screen displayed contents.      Logical dots per inch are used to convert font and user interface elements     from point sizes to pixel sizes, and might be different from the physical     dots per inch. The logical dots per inch are sometimes user-settable in the     desktop environment's settings panel, to let the user globally control UI     and font sizes in different applications.      \inmodule QtGui */
end_comment
begin_constructor
DECL|function|QScreen
name|QScreen
operator|::
name|QScreen
parameter_list|(
name|QPlatformScreen
modifier|*
name|screen
parameter_list|)
member_init_list|:
name|QObject
argument_list|(
operator|*
operator|new
name|QScreenPrivate
argument_list|(
name|screen
argument_list|)
argument_list|,
literal|0
argument_list|)
block|{ }
end_constructor
begin_comment
comment|/*!   Get the platform screen handle. */
end_comment
begin_function
DECL|function|handle
name|QPlatformScreen
modifier|*
name|QScreen
operator|::
name|handle
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QScreen
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|platformScreen
return|;
block|}
end_function
begin_comment
comment|/*!   \property QScreen::name   \brief a user presentable string representing the screen    For example, on X11 these correspond to the XRandr screen names,   typically "VGA1", "HDMI1", etc. */
end_comment
begin_function
DECL|function|name
name|QString
name|QScreen
operator|::
name|name
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QScreen
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|platformScreen
operator|->
name|name
argument_list|()
return|;
block|}
end_function
begin_comment
comment|/*!   \property QScreen::depth   \brief the color depth of the screen */
end_comment
begin_function
DECL|function|depth
name|int
name|QScreen
operator|::
name|depth
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QScreen
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|platformScreen
operator|->
name|depth
argument_list|()
return|;
block|}
end_function
begin_comment
comment|/*!   \property QScreen::size   \brief the pixel resolution of the screen */
end_comment
begin_function
DECL|function|size
name|QSize
name|QScreen
operator|::
name|size
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QScreen
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|geometry
operator|.
name|size
argument_list|()
return|;
block|}
end_function
begin_comment
comment|/*!   \property QScreen::physicalDotsPerInchX   \brief the number of physical dots or pixels per inch in the horizontal direction    This value represents the actual horizontal pixel density on the screen's display.   Depending on what information the underlying system provides the value might not be   entirely accurate.    \sa physicalDotsPerInchY() */
end_comment
begin_function
DECL|function|physicalDotsPerInchX
name|qreal
name|QScreen
operator|::
name|physicalDotsPerInchX
parameter_list|()
specifier|const
block|{
return|return
name|size
argument_list|()
operator|.
name|width
argument_list|()
operator|/
name|physicalSize
argument_list|()
operator|.
name|width
argument_list|()
operator|*
name|qreal
argument_list|(
literal|25.4
argument_list|)
return|;
block|}
end_function
begin_comment
comment|/*!   \property QScreen::physicalDotsPerInchY   \brief the number of physical dots or pixels per inch in the vertical direction    This value represents the actual vertical pixel density on the screen's display.   Depending on what information the underlying system provides the value might not be   entirely accurate.    \sa physicalDotsPerInchX() */
end_comment
begin_function
DECL|function|physicalDotsPerInchY
name|qreal
name|QScreen
operator|::
name|physicalDotsPerInchY
parameter_list|()
specifier|const
block|{
return|return
name|size
argument_list|()
operator|.
name|height
argument_list|()
operator|/
name|physicalSize
argument_list|()
operator|.
name|height
argument_list|()
operator|*
name|qreal
argument_list|(
literal|25.4
argument_list|)
return|;
block|}
end_function
begin_comment
comment|/*!   \property QScreen::physicalDotsPerInch   \brief the number of physical dots or pixels per inch    This value represents the pixel density on the screen's display.   Depending on what information the underlying system provides the value might not be   entirely accurate.    This is a convenience property that's simply the average of the physicalDotsPerInchX   and physicalDotsPerInchY properties.    \sa physicalDotsPerInchX()   \sa physicalDotsPerInchY() */
end_comment
begin_function
DECL|function|physicalDotsPerInch
name|qreal
name|QScreen
operator|::
name|physicalDotsPerInch
parameter_list|()
specifier|const
block|{
name|QSize
name|sz
init|=
name|size
argument_list|()
decl_stmt|;
name|QSizeF
name|psz
init|=
name|physicalSize
argument_list|()
decl_stmt|;
return|return
operator|(
operator|(
name|sz
operator|.
name|height
argument_list|()
operator|/
name|psz
operator|.
name|height
argument_list|()
operator|)
operator|+
operator|(
name|sz
operator|.
name|width
argument_list|()
operator|/
name|psz
operator|.
name|width
argument_list|()
operator|)
operator|)
operator|*
name|qreal
argument_list|(
literal|25.4
operator|*
literal|0.5
argument_list|)
return|;
block|}
end_function
begin_comment
comment|/*!   \property QScreen::logicalDotsPerInchX   \brief the number of logical dots or pixels per inch in the horizontal direction    This value is used to convert font point sizes to pixel sizes.    \sa logicalDotsPerInchY() */
end_comment
begin_function
DECL|function|logicalDotsPerInchX
name|qreal
name|QScreen
operator|::
name|logicalDotsPerInchX
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QScreen
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|logicalDpi
operator|.
name|first
return|;
block|}
end_function
begin_comment
comment|/*!   \property QScreen::logicalDotsPerInchY   \brief the number of logical dots or pixels per inch in the vertical direction    This value is used to convert font point sizes to pixel sizes.    \sa logicalDotsPerInchX() */
end_comment
begin_function
DECL|function|logicalDotsPerInchY
name|qreal
name|QScreen
operator|::
name|logicalDotsPerInchY
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QScreen
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|logicalDpi
operator|.
name|second
return|;
block|}
end_function
begin_comment
comment|/*!   \property QScreen::logicalDotsPerInch   \brief the number of logical dots or pixels per inch    This value can be used to convert font point sizes to pixel sizes.    This is a convenience property that's simply the average of the logicalDotsPerInchX   and logicalDotsPerInchY properties.    \sa logicalDotsPerInchX()   \sa logicalDotsPerInchY() */
end_comment
begin_function
DECL|function|logicalDotsPerInch
name|qreal
name|QScreen
operator|::
name|logicalDotsPerInch
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QScreen
argument_list|)
expr_stmt|;
name|QDpi
name|dpi
init|=
name|d
operator|->
name|logicalDpi
decl_stmt|;
return|return
operator|(
name|dpi
operator|.
name|first
operator|+
name|dpi
operator|.
name|second
operator|)
operator|*
name|qreal
argument_list|(
literal|0.5
argument_list|)
return|;
block|}
end_function
begin_comment
comment|/*!   \property QScreen::physicalSize   \brief the screen's physical size (in millimeters)    The physical size represents the actual physical dimensions of the   screen's display.    Depending on what information the underlying system provides the value   might not be entirely accurate. */
end_comment
begin_function
DECL|function|physicalSize
name|QSizeF
name|QScreen
operator|::
name|physicalSize
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QScreen
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|platformScreen
operator|->
name|physicalSize
argument_list|()
return|;
block|}
end_function
begin_comment
comment|/*!   \property QScreen::availableSize   \brief the screen's available size in pixels    The available size is the size excluding window manager reserved areas   such as task bars and system menus. */
end_comment
begin_function
DECL|function|availableSize
name|QSize
name|QScreen
operator|::
name|availableSize
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QScreen
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|availableGeometry
operator|.
name|size
argument_list|()
return|;
block|}
end_function
begin_comment
comment|/*!   \property QScreen::geometry   \brief the screen's geometry in pixels    As an example this might return QRect(0, 0, 1280, 1024), or in a   virtual desktop setting QRect(1280, 0, 1280, 1024). */
end_comment
begin_function
DECL|function|geometry
name|QRect
name|QScreen
operator|::
name|geometry
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QScreen
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|geometry
return|;
block|}
end_function
begin_comment
comment|/*!   \property QScreen::availableGeometry   \brief the screen's available geometry in pixels    The available geometry is the geometry excluding window manager reserved areas   such as task bars and system menus. */
end_comment
begin_function
DECL|function|availableGeometry
name|QRect
name|QScreen
operator|::
name|availableGeometry
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QScreen
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|availableGeometry
return|;
block|}
end_function
begin_comment
comment|/*!   Get the screen's virtual siblings.    The virtual siblings are the screen instances sharing the same virtual desktop.   They share a common coordinate system, and windows can freely be moved or   positioned across them without having to be re-created. */
end_comment
begin_function
DECL|function|virtualSiblings
name|QList
argument_list|<
name|QScreen
modifier|*
argument_list|>
name|QScreen
operator|::
name|virtualSiblings
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QScreen
argument_list|)
expr_stmt|;
name|QList
argument_list|<
name|QPlatformScreen
modifier|*
argument_list|>
name|platformScreens
init|=
name|d
operator|->
name|platformScreen
operator|->
name|virtualSiblings
argument_list|()
decl_stmt|;
name|QList
argument_list|<
name|QScreen
modifier|*
argument_list|>
name|screens
decl_stmt|;
foreach|foreach
control|(
name|QPlatformScreen
modifier|*
name|platformScreen
decl|,
name|platformScreens
control|)
name|screens
operator|<<
name|platformScreen
operator|->
name|screen
argument_list|()
expr_stmt|;
return|return
name|screens
return|;
block|}
end_function
begin_comment
comment|/*!   \property QScreen::virtualSize   \brief the pixel size of the virtual desktop corresponding to this screen    This is the combined size of the virtual siblings' individual geometries.    \sa virtualSiblings() */
end_comment
begin_function
DECL|function|virtualSize
name|QSize
name|QScreen
operator|::
name|virtualSize
parameter_list|()
specifier|const
block|{
return|return
name|virtualGeometry
argument_list|()
operator|.
name|size
argument_list|()
return|;
block|}
end_function
begin_comment
comment|/*!   \property QScreen::virtualGeometry   \brief the pixel geometry of the virtual desktop corresponding to this screen    This is the union of the virtual siblings' individual geometries.    \sa virtualSiblings() */
end_comment
begin_function
DECL|function|virtualGeometry
name|QRect
name|QScreen
operator|::
name|virtualGeometry
parameter_list|()
specifier|const
block|{
name|QRect
name|result
decl_stmt|;
foreach|foreach
control|(
name|QScreen
modifier|*
name|screen
decl|,
name|virtualSiblings
argument_list|()
control|)
name|result
operator||=
name|screen
operator|->
name|geometry
argument_list|()
expr_stmt|;
return|return
name|result
return|;
block|}
end_function
begin_comment
comment|/*!   \property QScreen::availableVirtualSize   \brief the available pixel size of the virtual desktop corresponding to this screen    This is the combined size of the virtual siblings' individual available geometries.    \sa availableSize()   \sa virtualSiblings() */
end_comment
begin_function
DECL|function|availableVirtualSize
name|QSize
name|QScreen
operator|::
name|availableVirtualSize
parameter_list|()
specifier|const
block|{
return|return
name|availableVirtualGeometry
argument_list|()
operator|.
name|size
argument_list|()
return|;
block|}
end_function
begin_comment
comment|/*!   \property QScreen::availableVirtualGeometry   \brief the available size of the virtual desktop corresponding to this screen    This is the union of the virtual siblings' individual available geometries.    \sa availableGeometry()   \sa virtualSiblings() */
end_comment
begin_function
DECL|function|availableVirtualGeometry
name|QRect
name|QScreen
operator|::
name|availableVirtualGeometry
parameter_list|()
specifier|const
block|{
name|QRect
name|result
decl_stmt|;
foreach|foreach
control|(
name|QScreen
modifier|*
name|screen
decl|,
name|virtualSiblings
argument_list|()
control|)
name|result
operator||=
name|screen
operator|->
name|availableGeometry
argument_list|()
expr_stmt|;
return|return
name|result
return|;
block|}
end_function
begin_comment
comment|/*!     \property QScreen::orientation     \brief the screen orientation      The screen orientation represents the physical orientation     of the display. For example, the screen orientation of a mobile device     will change based on the device is being held, and a desktop display     might be rotated so that it's in portrait mode.      Qt::PrimaryOrientation is never returned.      \sa primaryOrientation(), orientationChanged() */
end_comment
begin_function
DECL|function|orientation
name|Qt
operator|::
name|ScreenOrientation
name|QScreen
operator|::
name|orientation
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QScreen
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|orientation
operator|==
name|Qt
operator|::
name|PrimaryOrientation
condition|?
name|primaryOrientation
argument_list|()
else|:
name|d
operator|->
name|orientation
return|;
block|}
end_function
begin_comment
comment|/*!     \property QScreen::primaryOrientation     \brief the primary screen orientation      The primary screen orientation is Qt::LandscapeOrientation     if the screen geometry's width is greater than or equal to its     height, or Qt::PortraitOrientation otherwise.      \sa primaryOrientationChanged() */
end_comment
begin_function
DECL|function|primaryOrientation
name|Qt
operator|::
name|ScreenOrientation
name|QScreen
operator|::
name|primaryOrientation
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QScreen
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|primaryOrientation
return|;
block|}
end_function
begin_comment
comment|// i must be power of two
end_comment
begin_function
DECL|function|log2
specifier|static
name|int
name|log2
parameter_list|(
name|uint
name|i
parameter_list|)
block|{
if|if
condition|(
name|i
operator|==
literal|0
condition|)
return|return
operator|-
literal|1
return|;
name|int
name|result
init|=
literal|0
decl_stmt|;
while|while
condition|(
operator|!
operator|(
name|i
operator|&
literal|1
operator|)
condition|)
block|{
operator|++
name|result
expr_stmt|;
name|i
operator|>>=
literal|1
expr_stmt|;
block|}
return|return
name|result
return|;
block|}
end_function
begin_comment
comment|/*!     Convenience function to compute the angle of rotation to get from     rotation \a a to rotation \a b.      The result will be 0, 90, 180, or 270.      Qt::PrimaryOrientation is interpreted as the screen's primaryOrientation(). */
end_comment
begin_function
DECL|function|angleBetween
name|int
name|QScreen
operator|::
name|angleBetween
parameter_list|(
name|Qt
operator|::
name|ScreenOrientation
name|a
parameter_list|,
name|Qt
operator|::
name|ScreenOrientation
name|b
parameter_list|)
specifier|const
block|{
if|if
condition|(
name|a
operator|==
name|Qt
operator|::
name|PrimaryOrientation
condition|)
name|a
operator|=
name|primaryOrientation
argument_list|()
expr_stmt|;
if|if
condition|(
name|b
operator|==
name|Qt
operator|::
name|PrimaryOrientation
condition|)
name|b
operator|=
name|primaryOrientation
argument_list|()
expr_stmt|;
if|if
condition|(
name|a
operator|==
name|b
condition|)
return|return
literal|0
return|;
name|int
name|ia
init|=
name|log2
argument_list|(
name|uint
argument_list|(
name|a
argument_list|)
argument_list|)
decl_stmt|;
name|int
name|ib
init|=
name|log2
argument_list|(
name|uint
argument_list|(
name|b
argument_list|)
argument_list|)
decl_stmt|;
name|int
name|delta
init|=
name|ia
operator|-
name|ib
decl_stmt|;
if|if
condition|(
name|delta
operator|<
literal|0
condition|)
name|delta
operator|=
name|delta
operator|+
literal|4
expr_stmt|;
name|int
name|angles
index|[]
init|=
block|{
literal|0
block|,
literal|90
block|,
literal|180
block|,
literal|270
block|}
decl_stmt|;
return|return
name|angles
index|[
name|delta
index|]
return|;
block|}
end_function
begin_comment
comment|/*!     Convenience function to compute a transform that maps from the coordinate system     defined by orientation \a a into the coordinate system defined by orientation     \a b and target dimensions \a target.      Example, \a a is Qt::Landscape, \a b is Qt::Portrait, and \a target is QRect(0, 0, w, h)     the resulting transform will be such that the point QPoint(0, 0) is mapped to QPoint(0, w),     and QPoint(h, w) is mapped to QPoint(0, h). Thus, the landscape coordinate system QRect(0, 0, h, w)     is mapped (with a 90 degree rotation) into the portrait coordinate system QRect(0, 0, w, h).      Qt::PrimaryOrientation is interpreted as the screen's primaryOrientation(). */
end_comment
begin_function
DECL|function|transformBetween
name|QTransform
name|QScreen
operator|::
name|transformBetween
parameter_list|(
name|Qt
operator|::
name|ScreenOrientation
name|a
parameter_list|,
name|Qt
operator|::
name|ScreenOrientation
name|b
parameter_list|,
specifier|const
name|QRect
modifier|&
name|target
parameter_list|)
specifier|const
block|{
if|if
condition|(
name|a
operator|==
name|Qt
operator|::
name|PrimaryOrientation
condition|)
name|a
operator|=
name|primaryOrientation
argument_list|()
expr_stmt|;
if|if
condition|(
name|b
operator|==
name|Qt
operator|::
name|PrimaryOrientation
condition|)
name|b
operator|=
name|primaryOrientation
argument_list|()
expr_stmt|;
if|if
condition|(
name|a
operator|==
name|b
condition|)
return|return
name|QTransform
argument_list|()
return|;
name|int
name|angle
init|=
name|angleBetween
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
decl_stmt|;
name|QTransform
name|result
decl_stmt|;
switch|switch
condition|(
name|angle
condition|)
block|{
case|case
literal|90
case|:
name|result
operator|.
name|translate
argument_list|(
name|target
operator|.
name|width
argument_list|()
argument_list|,
literal|0
argument_list|)
expr_stmt|;
break|break;
case|case
literal|180
case|:
name|result
operator|.
name|translate
argument_list|(
name|target
operator|.
name|width
argument_list|()
argument_list|,
name|target
operator|.
name|height
argument_list|()
argument_list|)
expr_stmt|;
break|break;
case|case
literal|270
case|:
name|result
operator|.
name|translate
argument_list|(
literal|0
argument_list|,
name|target
operator|.
name|height
argument_list|()
argument_list|)
expr_stmt|;
break|break;
default|default:
name|Q_ASSERT
argument_list|(
literal|false
argument_list|)
expr_stmt|;
block|}
name|result
operator|.
name|rotate
argument_list|(
name|angle
argument_list|)
expr_stmt|;
return|return
name|result
return|;
block|}
end_function
begin_comment
comment|/*!     Maps the rect between two screen orientations.      This will flip the x and y dimensions of the rectangle if orientation \a is     Qt::PortraitOrientation or Qt::InvertedPortraitOrientation and orientation \b is     Qt::LandscapeOrientation or Qt::InvertedLandscapeOrientation, or vice versa.      Qt::PrimaryOrientation is interpreted as the screen's primaryOrientation(). */
end_comment
begin_function
DECL|function|mapBetween
name|QRect
name|QScreen
operator|::
name|mapBetween
parameter_list|(
name|Qt
operator|::
name|ScreenOrientation
name|a
parameter_list|,
name|Qt
operator|::
name|ScreenOrientation
name|b
parameter_list|,
specifier|const
name|QRect
modifier|&
name|rect
parameter_list|)
specifier|const
block|{
if|if
condition|(
name|a
operator|==
name|Qt
operator|::
name|PrimaryOrientation
condition|)
name|a
operator|=
name|primaryOrientation
argument_list|()
expr_stmt|;
if|if
condition|(
name|b
operator|==
name|Qt
operator|::
name|PrimaryOrientation
condition|)
name|b
operator|=
name|primaryOrientation
argument_list|()
expr_stmt|;
if|if
condition|(
name|a
operator|==
name|b
condition|)
return|return
name|rect
return|;
if|if
condition|(
operator|(
name|a
operator|==
name|Qt
operator|::
name|PortraitOrientation
operator|||
name|a
operator|==
name|Qt
operator|::
name|InvertedPortraitOrientation
operator|)
operator|!=
operator|(
name|b
operator|==
name|Qt
operator|::
name|PortraitOrientation
operator|||
name|b
operator|==
name|Qt
operator|::
name|InvertedPortraitOrientation
operator|)
condition|)
block|{
return|return
name|QRect
argument_list|(
name|rect
operator|.
name|y
argument_list|()
argument_list|,
name|rect
operator|.
name|x
argument_list|()
argument_list|,
name|rect
operator|.
name|height
argument_list|()
argument_list|,
name|rect
operator|.
name|width
argument_list|()
argument_list|)
return|;
block|}
return|return
name|rect
return|;
block|}
end_function
begin_comment
comment|/*!     Convenience function to check if a screen orientation is either portrait     or inverted portrait.      Qt::PrimaryOrientation is interpreted as the screen's primaryOrientation(). */
end_comment
begin_function
DECL|function|isPortrait
name|bool
name|QScreen
operator|::
name|isPortrait
parameter_list|(
name|Qt
operator|::
name|ScreenOrientation
name|o
parameter_list|)
specifier|const
block|{
return|return
name|o
operator|==
name|Qt
operator|::
name|PortraitOrientation
operator|||
name|o
operator|==
name|Qt
operator|::
name|InvertedPortraitOrientation
operator|||
operator|(
name|o
operator|==
name|Qt
operator|::
name|PrimaryOrientation
operator|&&
name|primaryOrientation
argument_list|()
operator|==
name|Qt
operator|::
name|PortraitOrientation
operator|)
return|;
block|}
end_function
begin_comment
comment|/*!     Convenience function to check if a screen orientation is either landscape     or inverted landscape.      Qt::PrimaryOrientation is interpreted as the screen's primaryOrientation(). */
end_comment
begin_function
DECL|function|isLandscape
name|bool
name|QScreen
operator|::
name|isLandscape
parameter_list|(
name|Qt
operator|::
name|ScreenOrientation
name|o
parameter_list|)
specifier|const
block|{
return|return
name|o
operator|==
name|Qt
operator|::
name|LandscapeOrientation
operator|||
name|o
operator|==
name|Qt
operator|::
name|InvertedLandscapeOrientation
operator|||
operator|(
name|o
operator|==
name|Qt
operator|::
name|PrimaryOrientation
operator|&&
name|primaryOrientation
argument_list|()
operator|==
name|Qt
operator|::
name|LandscapeOrientation
operator|)
return|;
block|}
end_function
begin_comment
comment|/*!     \fn QScreen::orientationChanged(Qt::ScreenOrientation orientation)      This signal is emitted when the orientation of the screen     changes.      \sa orientation() */
end_comment
begin_comment
comment|/*!     \fn QScreen::primaryOrientationChanged(Qt::ScreenOrientation orientation)      This signal is emitted when the primary orientation of the screen     changes.      \sa primaryOrientation() */
end_comment
begin_function
DECL|function|updatePrimaryOrientation
name|void
name|QScreenPrivate
operator|::
name|updatePrimaryOrientation
parameter_list|()
block|{
name|primaryOrientation
operator|=
name|geometry
operator|.
name|width
argument_list|()
operator|>=
name|geometry
operator|.
name|height
argument_list|()
condition|?
name|Qt
operator|::
name|LandscapeOrientation
else|:
name|Qt
operator|::
name|PortraitOrientation
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     Creates and returns a pixmap constructed by grabbing the contents     of the given \a window restricted by QRect(\a x, \a y, \a width,     \a height).      The arguments (\a{x}, \a{y}) specify the offset in the window,     whereas (\a{width}, \a{height}) specify the area to be copied.  If     \a width is negative, the function copies everything to the right     border of the window. If \a height is negative, the function     copies everything to the bottom of the window.      The window system identifier (\c WId) can be retrieved using the     QWidget::winId() function. The rationale for using a window     identifier and not a QWidget, is to enable grabbing of windows     that are not part of the application, window system frames, and so     on.      The grabWindow() function grabs pixels from the screen, not from     the window, i.e. if there is another window partially or entirely     over the one you grab, you get pixels from the overlying window,     too. The mouse cursor is generally not grabbed.      Note on X11 that if the given \a window doesn't have the same depth     as the root window, and another window partially or entirely     obscures the one you grab, you will \e not get pixels from the     overlying window.  The contents of the obscured areas in the     pixmap will be undefined and uninitialized.      On Windows Vista and above grabbing a layered window, which is     created by setting the Qt::WA_TranslucentBackground attribute, will     not work. Instead grabbing the desktop widget should work.      \warning In general, grabbing an area outside the screen is not     safe. This depends on the underlying window system. */
end_comment
begin_function
DECL|function|grabWindow
name|QPixmap
name|QScreen
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
name|w
parameter_list|,
name|int
name|h
parameter_list|)
block|{
specifier|const
name|QPlatformScreen
modifier|*
name|platformScreen
init|=
name|handle
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
name|platformScreen
condition|)
block|{
name|qWarning
argument_list|(
literal|"%s invoked with handle==0"
argument_list|,
name|Q_FUNC_INFO
argument_list|)
expr_stmt|;
return|return
name|QPixmap
argument_list|()
return|;
block|}
return|return
name|platformScreen
operator|->
name|grabWindow
argument_list|(
name|window
argument_list|,
name|x
argument_list|,
name|y
argument_list|,
name|w
argument_list|,
name|h
argument_list|)
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
