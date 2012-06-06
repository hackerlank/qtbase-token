begin_unit
begin_comment
comment|/*************************************************************************** ** ** Copyright (C) 2011 - 2012 Research In Motion ** Contact: http://www.qt-project.org/ ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qqnxscreen.h"
end_include
begin_include
include|#
directive|include
file|"qqnxwindow.h"
end_include
begin_include
include|#
directive|include
file|<QtCore/QThread>
end_include
begin_include
include|#
directive|include
file|<QtCore/QDebug>
end_include
begin_include
include|#
directive|include
file|<QtGui/QWindowSystemInterface>
end_include
begin_include
include|#
directive|include
file|<errno.h>
end_include
begin_ifdef
ifdef|#
directive|ifdef
name|QQNXSCREEN_DEBUG
end_ifdef
begin_define
DECL|macro|qScreenDebug
define|#
directive|define
name|qScreenDebug
value|qDebug
end_define
begin_else
else|#
directive|else
end_else
begin_define
DECL|macro|qScreenDebug
define|#
directive|define
name|qScreenDebug
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
DECL|function|QQnxScreen
name|QQnxScreen
operator|::
name|QQnxScreen
parameter_list|(
name|screen_context_t
name|screenContext
parameter_list|,
name|screen_display_t
name|display
parameter_list|,
name|bool
name|primaryScreen
parameter_list|)
member_init_list|:
name|m_screenContext
argument_list|(
name|screenContext
argument_list|)
member_init_list|,
name|m_display
argument_list|(
name|display
argument_list|)
member_init_list|,
name|m_rootWindow
argument_list|()
member_init_list|,
name|m_primaryScreen
argument_list|(
name|primaryScreen
argument_list|)
member_init_list|,
name|m_posted
argument_list|(
literal|false
argument_list|)
member_init_list|,
name|m_keyboardHeight
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|m_nativeOrientation
argument_list|(
name|Qt
operator|::
name|PrimaryOrientation
argument_list|)
member_init_list|,
name|m_platformContext
argument_list|(
literal|0
argument_list|)
block|{
name|qScreenDebug
argument_list|()
operator|<<
name|Q_FUNC_INFO
expr_stmt|;
comment|// Cache initial orientation of this display
name|errno
operator|=
literal|0
expr_stmt|;
name|int
name|result
init|=
name|screen_get_display_property_iv
argument_list|(
name|m_display
argument_list|,
name|SCREEN_PROPERTY_ROTATION
argument_list|,
operator|&
name|m_initialRotation
argument_list|)
decl_stmt|;
if|if
condition|(
name|result
operator|!=
literal|0
condition|)
block|{
name|qFatal
argument_list|(
literal|"QQnxScreen: failed to query display rotation, errno=%d"
argument_list|,
name|errno
argument_list|)
expr_stmt|;
block|}
name|m_currentRotation
operator|=
name|m_initialRotation
expr_stmt|;
comment|// Cache size of this display in pixels
name|errno
operator|=
literal|0
expr_stmt|;
name|int
name|val
index|[
literal|2
index|]
decl_stmt|;
name|result
operator|=
name|screen_get_display_property_iv
argument_list|(
name|m_display
argument_list|,
name|SCREEN_PROPERTY_SIZE
argument_list|,
name|val
argument_list|)
expr_stmt|;
if|if
condition|(
name|result
operator|!=
literal|0
condition|)
block|{
name|qFatal
argument_list|(
literal|"QQnxScreen: failed to query display size, errno=%d"
argument_list|,
name|errno
argument_list|)
expr_stmt|;
block|}
name|m_currentGeometry
operator|=
name|m_initialGeometry
operator|=
name|QRect
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
name|val
index|[
literal|0
index|]
argument_list|,
name|val
index|[
literal|1
index|]
argument_list|)
expr_stmt|;
comment|// Cache size of this display in millimeters. We have to take care of the orientation.
comment|// libscreen always reports the physical size dimensions as width and height in the
comment|// native orientation. Contrary to this, QPlatformScreen::physicalSize() expects the
comment|// returned dimensions to follow the current orientation.
name|errno
operator|=
literal|0
expr_stmt|;
name|result
operator|=
name|screen_get_display_property_iv
argument_list|(
name|m_display
argument_list|,
name|SCREEN_PROPERTY_PHYSICAL_SIZE
argument_list|,
name|val
argument_list|)
expr_stmt|;
if|if
condition|(
name|result
operator|!=
literal|0
condition|)
block|{
name|qFatal
argument_list|(
literal|"QQnxScreen: failed to query display physical size, errno=%d"
argument_list|,
name|errno
argument_list|)
expr_stmt|;
block|}
name|m_nativeOrientation
operator|=
name|val
index|[
literal|0
index|]
operator|>=
name|val
index|[
literal|1
index|]
condition|?
name|Qt
operator|::
name|LandscapeOrientation
else|:
name|Qt
operator|::
name|PortraitOrientation
expr_stmt|;
specifier|const
name|int
name|angle
init|=
name|screen
argument_list|()
operator|->
name|angleBetween
argument_list|(
name|m_nativeOrientation
argument_list|,
name|orientation
argument_list|()
argument_list|)
decl_stmt|;
if|if
condition|(
name|angle
operator|==
literal|0
operator|||
name|angle
operator|==
literal|180
condition|)
name|m_currentPhysicalSize
operator|=
name|m_initialPhysicalSize
operator|=
name|QSize
argument_list|(
name|val
index|[
literal|0
index|]
argument_list|,
name|val
index|[
literal|1
index|]
argument_list|)
expr_stmt|;
else|else
name|m_currentPhysicalSize
operator|=
name|m_initialPhysicalSize
operator|=
name|QSize
argument_list|(
name|val
index|[
literal|1
index|]
argument_list|,
name|val
index|[
literal|0
index|]
argument_list|)
expr_stmt|;
comment|// We only create the root window if we are the primary display.
if|if
condition|(
name|primaryScreen
condition|)
name|m_rootWindow
operator|=
name|QSharedPointer
argument_list|<
name|QQnxRootWindow
argument_list|>
argument_list|(
operator|new
name|QQnxRootWindow
argument_list|(
name|this
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_destructor
DECL|function|~QQnxScreen
name|QQnxScreen
operator|::
name|~
name|QQnxScreen
parameter_list|()
block|{
name|qScreenDebug
argument_list|()
operator|<<
name|Q_FUNC_INFO
expr_stmt|;
block|}
end_destructor
begin_function
DECL|function|defaultDepth
specifier|static
name|int
name|defaultDepth
parameter_list|()
block|{
name|qScreenDebug
argument_list|()
operator|<<
name|Q_FUNC_INFO
expr_stmt|;
specifier|static
name|int
name|defaultDepth
init|=
literal|0
decl_stmt|;
if|if
condition|(
name|defaultDepth
operator|==
literal|0
condition|)
block|{
comment|// check if display depth was specified in environment variable;
comment|// use default value if no valid value found
name|defaultDepth
operator|=
name|qgetenv
argument_list|(
literal|"QQNX_DISPLAY_DEPTH"
argument_list|)
operator|.
name|toInt
argument_list|()
expr_stmt|;
if|if
condition|(
name|defaultDepth
operator|!=
literal|16
operator|&&
name|defaultDepth
operator|!=
literal|32
condition|)
block|{
name|defaultDepth
operator|=
literal|32
expr_stmt|;
block|}
block|}
return|return
name|defaultDepth
return|;
block|}
end_function
begin_function
DECL|function|availableGeometry
name|QRect
name|QQnxScreen
operator|::
name|availableGeometry
parameter_list|()
specifier|const
block|{
name|qScreenDebug
argument_list|()
operator|<<
name|Q_FUNC_INFO
expr_stmt|;
comment|// available geometry = total geometry - keyboard
return|return
name|QRect
argument_list|(
name|m_currentGeometry
operator|.
name|x
argument_list|()
argument_list|,
name|m_currentGeometry
operator|.
name|y
argument_list|()
argument_list|,
name|m_currentGeometry
operator|.
name|width
argument_list|()
argument_list|,
name|m_currentGeometry
operator|.
name|height
argument_list|()
operator|-
name|m_keyboardHeight
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|depth
name|int
name|QQnxScreen
operator|::
name|depth
parameter_list|()
specifier|const
block|{
return|return
name|defaultDepth
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|refreshRate
name|qreal
name|QQnxScreen
operator|::
name|refreshRate
parameter_list|()
specifier|const
block|{
name|screen_display_mode_t
name|displayMode
decl_stmt|;
name|int
name|result
init|=
name|screen_get_display_property_pv
argument_list|(
name|m_display
argument_list|,
name|SCREEN_PROPERTY_MODE
argument_list|,
cast|reinterpret_cast
argument_list|<
name|void
operator|*
operator|*
argument_list|>
argument_list|(
operator|&
name|displayMode
argument_list|)
argument_list|)
decl_stmt|;
if|if
condition|(
name|result
operator|!=
literal|0
condition|)
block|{
name|qWarning
argument_list|(
literal|"QQnxScreen: Failed to query screen mode. Using default value of 60Hz"
argument_list|)
expr_stmt|;
return|return
literal|60.0
return|;
block|}
name|qScreenDebug
argument_list|()
operator|<<
name|Q_FUNC_INFO
operator|<<
literal|"screen mode:"
operator|<<
name|endl
operator|<<
literal|"      width ="
operator|<<
name|displayMode
operator|.
name|width
operator|<<
name|endl
operator|<<
literal|"     height ="
operator|<<
name|displayMode
operator|.
name|height
operator|<<
name|endl
operator|<<
literal|"    refresh ="
operator|<<
name|displayMode
operator|.
name|refresh
operator|<<
name|endl
operator|<<
literal|" interlaced ="
operator|<<
name|displayMode
operator|.
name|interlaced
expr_stmt|;
return|return
cast|static_cast
argument_list|<
name|qreal
argument_list|>
argument_list|(
name|displayMode
operator|.
name|refresh
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|nativeOrientation
name|Qt
operator|::
name|ScreenOrientation
name|QQnxScreen
operator|::
name|nativeOrientation
parameter_list|()
specifier|const
block|{
return|return
name|m_nativeOrientation
return|;
block|}
end_function
begin_function
DECL|function|orientation
name|Qt
operator|::
name|ScreenOrientation
name|QQnxScreen
operator|::
name|orientation
parameter_list|()
specifier|const
block|{
name|Qt
operator|::
name|ScreenOrientation
name|orient
decl_stmt|;
if|if
condition|(
name|m_nativeOrientation
operator|==
name|Qt
operator|::
name|LandscapeOrientation
condition|)
block|{
comment|// Landscape devices e.g. PlayBook
if|if
condition|(
name|m_currentRotation
operator|==
literal|0
condition|)
name|orient
operator|=
name|Qt
operator|::
name|LandscapeOrientation
expr_stmt|;
elseif|else
if|if
condition|(
name|m_currentRotation
operator|==
literal|90
condition|)
name|orient
operator|=
name|Qt
operator|::
name|PortraitOrientation
expr_stmt|;
elseif|else
if|if
condition|(
name|m_currentRotation
operator|==
literal|180
condition|)
name|orient
operator|=
name|Qt
operator|::
name|InvertedLandscapeOrientation
expr_stmt|;
else|else
name|orient
operator|=
name|Qt
operator|::
name|InvertedPortraitOrientation
expr_stmt|;
block|}
else|else
block|{
comment|// Portrait devices e.g. Phones
comment|// ###TODO Check these on an actual phone device
if|if
condition|(
name|m_currentRotation
operator|==
literal|0
condition|)
name|orient
operator|=
name|Qt
operator|::
name|PortraitOrientation
expr_stmt|;
elseif|else
if|if
condition|(
name|m_currentRotation
operator|==
literal|90
condition|)
name|orient
operator|=
name|Qt
operator|::
name|LandscapeOrientation
expr_stmt|;
elseif|else
if|if
condition|(
name|m_currentRotation
operator|==
literal|180
condition|)
name|orient
operator|=
name|Qt
operator|::
name|InvertedPortraitOrientation
expr_stmt|;
else|else
name|orient
operator|=
name|Qt
operator|::
name|InvertedLandscapeOrientation
expr_stmt|;
block|}
name|qScreenDebug
argument_list|()
operator|<<
name|Q_FUNC_INFO
operator|<<
literal|"orientation ="
operator|<<
name|orient
expr_stmt|;
return|return
name|orient
return|;
block|}
end_function
begin_comment
comment|/*!     Check if the supplied angles are perpendicular to each other. */
end_comment
begin_function
DECL|function|isOrthogonal
specifier|static
name|bool
name|isOrthogonal
parameter_list|(
name|int
name|angle1
parameter_list|,
name|int
name|angle2
parameter_list|)
block|{
return|return
operator|(
operator|(
name|angle1
operator|-
name|angle2
operator|)
operator|%
literal|180
operator|)
operator|!=
literal|0
return|;
block|}
end_function
begin_function
DECL|function|setRotation
name|void
name|QQnxScreen
operator|::
name|setRotation
parameter_list|(
name|int
name|rotation
parameter_list|)
block|{
name|qScreenDebug
argument_list|()
operator|<<
name|Q_FUNC_INFO
operator|<<
literal|"orientation ="
operator|<<
name|rotation
expr_stmt|;
comment|// Check if rotation changed
if|if
condition|(
name|m_currentRotation
operator|!=
name|rotation
condition|)
block|{
comment|// Update rotation of root window
if|if
condition|(
name|m_rootWindow
condition|)
name|m_rootWindow
operator|->
name|setRotation
argument_list|(
name|rotation
argument_list|)
expr_stmt|;
comment|// Swap dimensions if we've rotated 90 or 270 from initial orientation
if|if
condition|(
name|isOrthogonal
argument_list|(
name|m_initialRotation
argument_list|,
name|rotation
argument_list|)
condition|)
block|{
name|m_currentGeometry
operator|=
name|QRect
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
name|m_initialGeometry
operator|.
name|height
argument_list|()
argument_list|,
name|m_initialGeometry
operator|.
name|width
argument_list|()
argument_list|)
expr_stmt|;
name|m_currentPhysicalSize
operator|=
name|QSize
argument_list|(
name|m_initialPhysicalSize
operator|.
name|height
argument_list|()
argument_list|,
name|m_initialPhysicalSize
operator|.
name|width
argument_list|()
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|m_currentGeometry
operator|=
name|QRect
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
name|m_initialGeometry
operator|.
name|width
argument_list|()
argument_list|,
name|m_initialGeometry
operator|.
name|height
argument_list|()
argument_list|)
expr_stmt|;
name|m_currentPhysicalSize
operator|=
name|m_initialPhysicalSize
expr_stmt|;
block|}
comment|// Resize root window if we've rotated 90 or 270 from previous orientation
if|if
condition|(
name|isOrthogonal
argument_list|(
name|m_currentRotation
argument_list|,
name|rotation
argument_list|)
condition|)
block|{
name|qScreenDebug
argument_list|()
operator|<<
name|Q_FUNC_INFO
operator|<<
literal|"resize, size ="
operator|<<
name|m_currentGeometry
operator|.
name|size
argument_list|()
expr_stmt|;
if|if
condition|(
name|m_rootWindow
condition|)
name|m_rootWindow
operator|->
name|resize
argument_list|(
name|m_currentGeometry
operator|.
name|size
argument_list|()
argument_list|)
expr_stmt|;
block|}
else|else
block|{
comment|// TODO: Find one global place to flush display updates
comment|// Force immediate display update if no geometry changes required
if|if
condition|(
name|m_rootWindow
condition|)
name|m_rootWindow
operator|->
name|flush
argument_list|()
expr_stmt|;
block|}
comment|// Save new rotation
name|m_currentRotation
operator|=
name|rotation
expr_stmt|;
comment|// TODO: check if other screens are supposed to rotate as well and/or whether this depends
comment|// on if clone mode is being used.
comment|// Rotating only the primary screen is what we had in the navigator event handler before refactoring
if|if
condition|(
name|m_primaryScreen
condition|)
block|{
name|QWindowSystemInterface
operator|::
name|handleScreenOrientationChange
argument_list|(
name|screen
argument_list|()
argument_list|,
name|orientation
argument_list|()
argument_list|)
expr_stmt|;
name|QWindowSystemInterface
operator|::
name|handleScreenGeometryChange
argument_list|(
name|screen
argument_list|()
argument_list|,
name|m_currentGeometry
argument_list|)
expr_stmt|;
name|resizeMaximizedWindows
argument_list|()
expr_stmt|;
block|}
block|}
block|}
end_function
begin_function
DECL|function|findWindow
name|QQnxWindow
modifier|*
name|QQnxScreen
operator|::
name|findWindow
parameter_list|(
name|screen_window_t
name|windowHandle
parameter_list|)
block|{
name|Q_FOREACH
argument_list|(
argument|QQnxWindow *window
argument_list|,
argument|m_childWindows
argument_list|)
block|{
name|QQnxWindow
modifier|*
specifier|const
name|result
init|=
name|window
operator|->
name|findWindow
argument_list|(
name|windowHandle
argument_list|)
decl_stmt|;
if|if
condition|(
name|result
condition|)
return|return
name|result
return|;
block|}
return|return
literal|0
return|;
block|}
end_function
begin_function
DECL|function|addWindow
name|void
name|QQnxScreen
operator|::
name|addWindow
parameter_list|(
name|QQnxWindow
modifier|*
name|window
parameter_list|)
block|{
name|qScreenDebug
argument_list|()
operator|<<
name|Q_FUNC_INFO
operator|<<
literal|"window ="
operator|<<
name|window
expr_stmt|;
if|if
condition|(
name|m_childWindows
operator|.
name|contains
argument_list|(
name|window
argument_list|)
condition|)
return|return;
comment|// Ensure that the desktop window is at the bottom of the zorder.
comment|// If we do not do this then we may end up activating the desktop
comment|// when the navigator service gets an event that our window group
comment|// has been activated (see QQnxScreen::activateWindowGroup()).
comment|// Such a situation would strangely break focus handling due to the
comment|// invisible desktop widget window being layered on top of normal
comment|// windows
if|if
condition|(
name|window
operator|->
name|window
argument_list|()
operator|->
name|windowType
argument_list|()
operator|==
name|Qt
operator|::
name|Desktop
condition|)
name|m_childWindows
operator|.
name|push_front
argument_list|(
name|window
argument_list|)
expr_stmt|;
else|else
name|m_childWindows
operator|.
name|push_back
argument_list|(
name|window
argument_list|)
expr_stmt|;
name|updateHierarchy
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|removeWindow
name|void
name|QQnxScreen
operator|::
name|removeWindow
parameter_list|(
name|QQnxWindow
modifier|*
name|window
parameter_list|)
block|{
name|qScreenDebug
argument_list|()
operator|<<
name|Q_FUNC_INFO
operator|<<
literal|"window ="
operator|<<
name|window
expr_stmt|;
specifier|const
name|int
name|numWindowsRemoved
init|=
name|m_childWindows
operator|.
name|removeAll
argument_list|(
name|window
argument_list|)
decl_stmt|;
if|if
condition|(
name|numWindowsRemoved
operator|>
literal|0
condition|)
name|updateHierarchy
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|raiseWindow
name|void
name|QQnxScreen
operator|::
name|raiseWindow
parameter_list|(
name|QQnxWindow
modifier|*
name|window
parameter_list|)
block|{
name|qScreenDebug
argument_list|()
operator|<<
name|Q_FUNC_INFO
operator|<<
literal|"window ="
operator|<<
name|window
expr_stmt|;
name|removeWindow
argument_list|(
name|window
argument_list|)
expr_stmt|;
name|m_childWindows
operator|.
name|push_back
argument_list|(
name|window
argument_list|)
expr_stmt|;
name|updateHierarchy
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|lowerWindow
name|void
name|QQnxScreen
operator|::
name|lowerWindow
parameter_list|(
name|QQnxWindow
modifier|*
name|window
parameter_list|)
block|{
name|qScreenDebug
argument_list|()
operator|<<
name|Q_FUNC_INFO
operator|<<
literal|"window ="
operator|<<
name|window
expr_stmt|;
name|removeWindow
argument_list|(
name|window
argument_list|)
expr_stmt|;
name|m_childWindows
operator|.
name|push_front
argument_list|(
name|window
argument_list|)
expr_stmt|;
name|updateHierarchy
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|updateHierarchy
name|void
name|QQnxScreen
operator|::
name|updateHierarchy
parameter_list|()
block|{
name|qScreenDebug
argument_list|()
operator|<<
name|Q_FUNC_INFO
expr_stmt|;
name|QList
argument_list|<
name|QQnxWindow
modifier|*
argument_list|>
operator|::
name|const_iterator
name|it
decl_stmt|;
name|int
name|topZorder
init|=
literal|1
decl_stmt|;
comment|// root window is z-order 0, all "top" level windows are "above" it
for|for
control|(
name|it
operator|=
name|m_childWindows
operator|.
name|constBegin
argument_list|()
init|;
name|it
operator|!=
name|m_childWindows
operator|.
name|constEnd
argument_list|()
condition|;
operator|++
name|it
control|)
operator|(
operator|*
name|it
operator|)
operator|->
name|updateZorder
argument_list|(
name|topZorder
argument_list|)
expr_stmt|;
name|topZorder
operator|++
expr_stmt|;
name|Q_FOREACH
argument_list|(
argument|screen_window_t overlay
argument_list|,
argument|m_overlays
argument_list|)
block|{
comment|// Do nothing when this fails. This can happen if we have stale windows in mOverlays,
comment|// which in turn can happen because a window was removed but we didn't get a notification
comment|// yet.
name|screen_set_window_property_iv
argument_list|(
name|overlay
argument_list|,
name|SCREEN_PROPERTY_ZORDER
argument_list|,
operator|&
name|topZorder
argument_list|)
expr_stmt|;
name|topZorder
operator|++
expr_stmt|;
block|}
comment|// After a hierarchy update, we need to force a flush on all screens.
comment|// Right now, all screens share a context.
name|screen_flush_context
argument_list|(
name|m_screenContext
argument_list|,
literal|0
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|onWindowPost
name|void
name|QQnxScreen
operator|::
name|onWindowPost
parameter_list|(
name|QQnxWindow
modifier|*
name|window
parameter_list|)
block|{
name|qScreenDebug
argument_list|()
operator|<<
name|Q_FUNC_INFO
expr_stmt|;
name|Q_UNUSED
argument_list|(
argument|window
argument_list|)
comment|// post app window (so navigator will show it) after first child window
comment|// has posted; this only needs to happen once as the app window's content
comment|// never changes
if|if
condition|(
operator|!
name|m_posted
operator|&&
name|m_rootWindow
condition|)
block|{
name|m_rootWindow
operator|->
name|post
argument_list|()
expr_stmt|;
name|m_posted
operator|=
literal|true
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|keyboardHeightChanged
name|void
name|QQnxScreen
operator|::
name|keyboardHeightChanged
parameter_list|(
name|int
name|height
parameter_list|)
block|{
if|if
condition|(
name|height
operator|==
name|m_keyboardHeight
condition|)
return|return;
name|m_keyboardHeight
operator|=
name|height
expr_stmt|;
name|QWindowSystemInterface
operator|::
name|handleScreenAvailableGeometryChange
argument_list|(
name|screen
argument_list|()
argument_list|,
name|availableGeometry
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|addOverlayWindow
name|void
name|QQnxScreen
operator|::
name|addOverlayWindow
parameter_list|(
name|screen_window_t
name|window
parameter_list|)
block|{
name|m_overlays
operator|.
name|append
argument_list|(
name|window
argument_list|)
expr_stmt|;
name|updateHierarchy
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|removeOverlayWindow
name|void
name|QQnxScreen
operator|::
name|removeOverlayWindow
parameter_list|(
name|screen_window_t
name|window
parameter_list|)
block|{
specifier|const
name|int
name|numOverlaysRemoved
init|=
name|m_overlays
operator|.
name|removeAll
argument_list|(
name|window
argument_list|)
decl_stmt|;
if|if
condition|(
name|numOverlaysRemoved
operator|>
literal|0
condition|)
name|updateHierarchy
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|newWindowCreated
name|void
name|QQnxScreen
operator|::
name|newWindowCreated
parameter_list|(
name|void
modifier|*
name|window
parameter_list|)
block|{
name|Q_ASSERT
argument_list|(
name|thread
argument_list|()
operator|==
name|QThread
operator|::
name|currentThread
argument_list|()
argument_list|)
expr_stmt|;
specifier|const
name|screen_window_t
name|windowHandle
init|=
cast|reinterpret_cast
argument_list|<
name|screen_window_t
argument_list|>
argument_list|(
name|window
argument_list|)
decl_stmt|;
name|screen_display_t
name|display
init|=
name|NULL
decl_stmt|;
if|if
condition|(
name|screen_get_window_property_pv
argument_list|(
name|windowHandle
argument_list|,
name|SCREEN_PROPERTY_DISPLAY
argument_list|,
operator|(
name|void
operator|*
operator|*
operator|)
operator|&
name|display
argument_list|)
operator|!=
literal|0
condition|)
block|{
name|qWarning
argument_list|(
literal|"QQnx: Failed to get screen for window, errno=%d"
argument_list|,
name|errno
argument_list|)
expr_stmt|;
return|return;
block|}
if|if
condition|(
name|display
operator|==
name|nativeDisplay
argument_list|()
condition|)
block|{
comment|// A window was created on this screen. If we don't know about this window yet, it means
comment|// it was not created by Qt, but by some foreign library like the multimedia renderer, which
comment|// creates an overlay window when playing a video.
comment|// Treat all foreign windows as overlays here.
if|if
condition|(
operator|!
name|findWindow
argument_list|(
name|windowHandle
argument_list|)
condition|)
name|addOverlayWindow
argument_list|(
name|windowHandle
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|windowClosed
name|void
name|QQnxScreen
operator|::
name|windowClosed
parameter_list|(
name|void
modifier|*
name|window
parameter_list|)
block|{
name|Q_ASSERT
argument_list|(
name|thread
argument_list|()
operator|==
name|QThread
operator|::
name|currentThread
argument_list|()
argument_list|)
expr_stmt|;
specifier|const
name|screen_window_t
name|windowHandle
init|=
cast|reinterpret_cast
argument_list|<
name|screen_window_t
argument_list|>
argument_list|(
name|window
argument_list|)
decl_stmt|;
name|removeOverlayWindow
argument_list|(
name|windowHandle
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|activateWindowGroup
name|void
name|QQnxScreen
operator|::
name|activateWindowGroup
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|id
parameter_list|)
block|{
name|qScreenDebug
argument_list|()
operator|<<
name|Q_FUNC_INFO
expr_stmt|;
if|if
condition|(
operator|!
name|rootWindow
argument_list|()
operator|||
name|id
operator|!=
name|rootWindow
argument_list|()
operator|->
name|groupName
argument_list|()
condition|)
return|return;
if|if
condition|(
operator|!
name|m_childWindows
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
comment|// We're picking up the last window of the list here
comment|// because this list is ordered by stacking order.
comment|// Last window is effectively the one on top.
name|QWindow
modifier|*
specifier|const
name|window
init|=
name|m_childWindows
operator|.
name|last
argument_list|()
operator|->
name|window
argument_list|()
decl_stmt|;
name|QWindowSystemInterface
operator|::
name|handleWindowActivated
argument_list|(
name|window
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|deactivateWindowGroup
name|void
name|QQnxScreen
operator|::
name|deactivateWindowGroup
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|id
parameter_list|)
block|{
name|qScreenDebug
argument_list|()
operator|<<
name|Q_FUNC_INFO
expr_stmt|;
if|if
condition|(
operator|!
name|rootWindow
argument_list|()
operator|||
name|id
operator|!=
name|rootWindow
argument_list|()
operator|->
name|groupName
argument_list|()
condition|)
return|return;
name|QWindowSystemInterface
operator|::
name|handleWindowActivated
argument_list|(
literal|0
argument_list|)
expr_stmt|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
