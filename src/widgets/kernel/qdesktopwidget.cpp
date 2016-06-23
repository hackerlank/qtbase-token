begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the QtWidgets module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qglobal.h"
end_include
begin_include
include|#
directive|include
file|"qdesktopwidget.h"
end_include
begin_include
include|#
directive|include
file|"qdesktopwidget_p.h"
end_include
begin_include
include|#
directive|include
file|"qscreen.h"
end_include
begin_include
include|#
directive|include
file|"qwidget_p.h"
end_include
begin_include
include|#
directive|include
file|"qwindow.h"
end_include
begin_include
include|#
directive|include
file|<private/qhighdpiscaling_p.h>
end_include
begin_include
include|#
directive|include
file|<qpa/qplatformscreen.h>
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_constructor
DECL|function|QDesktopScreenWidget
name|QDesktopScreenWidget
operator|::
name|QDesktopScreenWidget
parameter_list|(
name|QScreen
modifier|*
name|screen
parameter_list|,
specifier|const
name|QRect
modifier|&
name|geometry
parameter_list|)
member_init_list|:
name|QWidget
argument_list|(
name|Q_NULLPTR
argument_list|,
name|Qt
operator|::
name|Desktop
argument_list|)
member_init_list|,
name|m_screen
argument_list|(
name|screen
argument_list|)
block|{
name|setVisible
argument_list|(
literal|false
argument_list|)
expr_stmt|;
if|if
condition|(
name|QWindow
modifier|*
name|winHandle
init|=
name|windowHandle
argument_list|()
condition|)
name|winHandle
operator|->
name|setScreen
argument_list|(
name|screen
argument_list|)
expr_stmt|;
name|setScreenGeometry
argument_list|(
name|geometry
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_function
DECL|function|setScreenGeometry
name|void
name|QDesktopScreenWidget
operator|::
name|setScreenGeometry
parameter_list|(
specifier|const
name|QRect
modifier|&
name|geometry
parameter_list|)
block|{
name|m_geometry
operator|=
name|geometry
expr_stmt|;
name|setGeometry
argument_list|(
name|geometry
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|screenNumber
name|int
name|QDesktopScreenWidget
operator|::
name|screenNumber
parameter_list|()
specifier|const
block|{
specifier|const
name|QDesktopWidgetPrivate
modifier|*
name|desktopWidgetP
init|=
cast|static_cast
argument_list|<
specifier|const
name|QDesktopWidgetPrivate
operator|*
argument_list|>
argument_list|(
name|qt_widget_private
argument_list|(
name|QApplication
operator|::
name|desktop
argument_list|()
argument_list|)
argument_list|)
decl_stmt|;
return|return
name|desktopWidgetP
operator|->
name|screens
operator|.
name|indexOf
argument_list|(
cast|const_cast
argument_list|<
name|QDesktopScreenWidget
operator|*
argument_list|>
argument_list|(
name|this
argument_list|)
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|screenGeometry
specifier|const
name|QRect
name|QDesktopWidget
operator|::
name|screenGeometry
parameter_list|(
specifier|const
name|QWidget
modifier|*
name|widget
parameter_list|)
specifier|const
block|{
if|if
condition|(
name|Q_UNLIKELY
argument_list|(
operator|!
name|widget
argument_list|)
condition|)
block|{
name|qWarning
argument_list|(
literal|"QDesktopWidget::screenGeometry(): Attempt "
literal|"to get the screen geometry of a null widget"
argument_list|)
expr_stmt|;
return|return
name|QRect
argument_list|()
return|;
block|}
name|QRect
name|rect
init|=
name|QWidgetPrivate
operator|::
name|screenGeometry
argument_list|(
name|widget
argument_list|)
decl_stmt|;
if|if
condition|(
name|rect
operator|.
name|isNull
argument_list|()
condition|)
return|return
name|screenGeometry
argument_list|(
name|screenNumber
argument_list|(
name|widget
argument_list|)
argument_list|)
return|;
else|else
return|return
name|rect
return|;
block|}
end_function
begin_function
DECL|function|availableGeometry
specifier|const
name|QRect
name|QDesktopWidget
operator|::
name|availableGeometry
parameter_list|(
specifier|const
name|QWidget
modifier|*
name|widget
parameter_list|)
specifier|const
block|{
if|if
condition|(
name|Q_UNLIKELY
argument_list|(
operator|!
name|widget
argument_list|)
condition|)
block|{
name|qWarning
argument_list|(
literal|"QDesktopWidget::availableGeometry(): Attempt "
literal|"to get the available geometry of a null widget"
argument_list|)
expr_stmt|;
return|return
name|QRect
argument_list|()
return|;
block|}
name|QRect
name|rect
init|=
name|QWidgetPrivate
operator|::
name|screenGeometry
argument_list|(
name|widget
argument_list|)
decl_stmt|;
if|if
condition|(
name|rect
operator|.
name|isNull
argument_list|()
condition|)
return|return
name|availableGeometry
argument_list|(
name|screenNumber
argument_list|(
name|widget
argument_list|)
argument_list|)
return|;
else|else
return|return
name|rect
return|;
block|}
end_function
begin_function
DECL|function|widgetForScreen
name|QDesktopScreenWidget
modifier|*
name|QDesktopWidgetPrivate
operator|::
name|widgetForScreen
parameter_list|(
name|QScreen
modifier|*
name|qScreen
parameter_list|)
specifier|const
block|{
foreach|foreach
control|(
name|QDesktopScreenWidget
modifier|*
name|widget
decl|,
name|screens
control|)
block|{
if|if
condition|(
name|widget
operator|->
name|screen
argument_list|()
operator|==
name|qScreen
condition|)
return|return
name|widget
return|;
block|}
return|return
name|Q_NULLPTR
return|;
block|}
end_function
begin_function
DECL|function|_q_updateScreens
name|void
name|QDesktopWidgetPrivate
operator|::
name|_q_updateScreens
parameter_list|()
block|{
name|Q_Q
argument_list|(
name|QDesktopWidget
argument_list|)
expr_stmt|;
specifier|const
name|QList
argument_list|<
name|QScreen
modifier|*
argument_list|>
name|screenList
init|=
name|QGuiApplication
operator|::
name|screens
argument_list|()
decl_stmt|;
specifier|const
name|int
name|targetLength
init|=
name|screenList
operator|.
name|length
argument_list|()
decl_stmt|;
name|bool
name|screenCountChanged
init|=
literal|false
decl_stmt|;
comment|// Re-build our screens list. This is the easiest way to later compute which signals to emit.
comment|// Create new screen widgets as necessary. While iterating, keep the old list in place so
comment|// that widgetForScreen works.
comment|// Furthermore, we note which screens have changed, and compute the overall virtual geometry.
name|QList
argument_list|<
name|QDesktopScreenWidget
modifier|*
argument_list|>
name|newScreens
decl_stmt|;
name|QList
argument_list|<
name|int
argument_list|>
name|changedScreens
decl_stmt|;
name|QRegion
name|virtualGeometry
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
name|targetLength
condition|;
operator|++
name|i
control|)
block|{
name|QScreen
modifier|*
name|qScreen
init|=
name|screenList
operator|.
name|at
argument_list|(
name|i
argument_list|)
decl_stmt|;
specifier|const
name|QRect
name|screenGeometry
init|=
name|qScreen
operator|->
name|geometry
argument_list|()
decl_stmt|;
name|QDesktopScreenWidget
modifier|*
name|screenWidget
init|=
name|widgetForScreen
argument_list|(
name|qScreen
argument_list|)
decl_stmt|;
if|if
condition|(
name|screenWidget
condition|)
block|{
comment|// an old screen. update geometry and remember the index in the *new* list
if|if
condition|(
name|screenGeometry
operator|!=
name|screenWidget
operator|->
name|screenGeometry
argument_list|()
condition|)
block|{
name|screenWidget
operator|->
name|setScreenGeometry
argument_list|(
name|screenGeometry
argument_list|)
expr_stmt|;
name|changedScreens
operator|.
name|push_back
argument_list|(
name|i
argument_list|)
expr_stmt|;
block|}
block|}
else|else
block|{
comment|// a new screen, create a widget and connect the signals.
name|screenWidget
operator|=
operator|new
name|QDesktopScreenWidget
argument_list|(
name|qScreen
argument_list|,
name|screenGeometry
argument_list|)
expr_stmt|;
name|QObject
operator|::
name|connect
argument_list|(
name|qScreen
argument_list|,
name|SIGNAL
argument_list|(
name|geometryChanged
argument_list|(
name|QRect
argument_list|)
argument_list|)
argument_list|,
name|q
argument_list|,
name|SLOT
argument_list|(
name|_q_updateScreens
argument_list|()
argument_list|)
argument_list|,
name|Qt
operator|::
name|QueuedConnection
argument_list|)
expr_stmt|;
name|QObject
operator|::
name|connect
argument_list|(
name|qScreen
argument_list|,
name|SIGNAL
argument_list|(
name|availableGeometryChanged
argument_list|(
name|QRect
argument_list|)
argument_list|)
argument_list|,
name|q
argument_list|,
name|SLOT
argument_list|(
name|_q_availableGeometryChanged
argument_list|()
argument_list|)
argument_list|,
name|Qt
operator|::
name|QueuedConnection
argument_list|)
expr_stmt|;
name|QObject
operator|::
name|connect
argument_list|(
name|qScreen
argument_list|,
name|SIGNAL
argument_list|(
name|destroyed
argument_list|()
argument_list|)
argument_list|,
name|q
argument_list|,
name|SLOT
argument_list|(
name|_q_updateScreens
argument_list|()
argument_list|)
argument_list|,
name|Qt
operator|::
name|QueuedConnection
argument_list|)
expr_stmt|;
name|screenCountChanged
operator|=
literal|true
expr_stmt|;
block|}
comment|// record all the screens and the overall geometry.
name|newScreens
operator|.
name|push_back
argument_list|(
name|screenWidget
argument_list|)
expr_stmt|;
name|virtualGeometry
operator|+=
name|screenGeometry
expr_stmt|;
block|}
comment|// Now we apply the accumulated updates.
name|screens
operator|.
name|swap
argument_list|(
name|newScreens
argument_list|)
expr_stmt|;
comment|// now [newScreens] is the old screen list
name|Q_ASSERT
argument_list|(
name|screens
operator|.
name|size
argument_list|()
operator|==
name|targetLength
argument_list|)
expr_stmt|;
name|q
operator|->
name|setGeometry
argument_list|(
name|virtualGeometry
operator|.
name|boundingRect
argument_list|()
argument_list|)
expr_stmt|;
comment|// Delete the QDesktopScreenWidget that are not used any more.
foreach|foreach
control|(
name|QDesktopScreenWidget
modifier|*
name|screen
decl|,
name|newScreens
control|)
block|{
if|if
condition|(
operator|!
name|screens
operator|.
name|contains
argument_list|(
name|screen
argument_list|)
condition|)
block|{
operator|delete
name|screen
expr_stmt|;
name|screenCountChanged
operator|=
literal|true
expr_stmt|;
block|}
block|}
comment|// Finally, emit the signals.
if|if
condition|(
name|screenCountChanged
condition|)
block|{
comment|// Notice that we trigger screenCountChanged even if a screen was removed and another one added,
comment|// in which case the total number of screens did not change. This is the only way for applications
comment|// to notice that a screen was swapped out against another one.
emit|emit
name|q
operator|->
name|screenCountChanged
argument_list|(
name|targetLength
argument_list|)
emit|;
block|}
foreach|foreach
control|(
name|int
name|changedScreen
decl|,
name|changedScreens
control|)
emit|emit
name|q
operator|->
name|resized
argument_list|(
name|changedScreen
argument_list|)
emit|;
block|}
end_function
begin_function
DECL|function|_q_availableGeometryChanged
name|void
name|QDesktopWidgetPrivate
operator|::
name|_q_availableGeometryChanged
parameter_list|()
block|{
name|Q_Q
argument_list|(
name|QDesktopWidget
argument_list|)
expr_stmt|;
if|if
condition|(
name|QScreen
modifier|*
name|screen
init|=
name|qobject_cast
argument_list|<
name|QScreen
operator|*
argument_list|>
argument_list|(
name|q
operator|->
name|sender
argument_list|()
argument_list|)
condition|)
emit|emit
name|q
operator|->
name|workAreaResized
argument_list|(
name|QGuiApplication
operator|::
name|screens
argument_list|()
operator|.
name|indexOf
argument_list|(
name|screen
argument_list|)
argument_list|)
emit|;
block|}
end_function
begin_constructor
DECL|function|QDesktopWidget
name|QDesktopWidget
operator|::
name|QDesktopWidget
parameter_list|()
member_init_list|:
name|QWidget
argument_list|(
operator|*
operator|new
name|QDesktopWidgetPrivate
argument_list|,
literal|0
argument_list|,
name|Qt
operator|::
name|Desktop
argument_list|)
block|{
name|Q_D
argument_list|(
name|QDesktopWidget
argument_list|)
expr_stmt|;
name|setObjectName
argument_list|(
name|QLatin1String
argument_list|(
literal|"desktop"
argument_list|)
argument_list|)
expr_stmt|;
name|d
operator|->
name|_q_updateScreens
argument_list|()
expr_stmt|;
name|connect
argument_list|(
name|qApp
argument_list|,
name|SIGNAL
argument_list|(
name|screenAdded
argument_list|(
name|QScreen
operator|*
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|_q_updateScreens
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|qApp
argument_list|,
name|SIGNAL
argument_list|(
name|primaryScreenChanged
argument_list|(
name|QScreen
operator|*
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SIGNAL
argument_list|(
name|primaryScreenChanged
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_destructor
DECL|function|~QDesktopWidget
name|QDesktopWidget
operator|::
name|~
name|QDesktopWidget
parameter_list|()
block|{ }
end_destructor
begin_function
DECL|function|isVirtualDesktop
name|bool
name|QDesktopWidget
operator|::
name|isVirtualDesktop
parameter_list|()
specifier|const
block|{
return|return
name|QGuiApplication
operator|::
name|primaryScreen
argument_list|()
operator|->
name|virtualSiblings
argument_list|()
operator|.
name|size
argument_list|()
operator|>
literal|1
return|;
block|}
end_function
begin_function
DECL|function|primaryScreen
name|int
name|QDesktopWidget
operator|::
name|primaryScreen
parameter_list|()
specifier|const
block|{
return|return
literal|0
return|;
block|}
end_function
begin_function
DECL|function|numScreens
name|int
name|QDesktopWidget
operator|::
name|numScreens
parameter_list|()
specifier|const
block|{
return|return
name|qMax
argument_list|(
name|QGuiApplication
operator|::
name|screens
argument_list|()
operator|.
name|size
argument_list|()
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|screen
name|QWidget
modifier|*
name|QDesktopWidget
operator|::
name|screen
parameter_list|(
name|int
name|screen
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QDesktopWidget
argument_list|)
expr_stmt|;
if|if
condition|(
name|screen
operator|<
literal|0
operator|||
name|screen
operator|>=
name|d
operator|->
name|screens
operator|.
name|length
argument_list|()
condition|)
return|return
name|d
operator|->
name|screens
operator|.
name|at
argument_list|(
literal|0
argument_list|)
return|;
return|return
name|d
operator|->
name|screens
operator|.
name|at
argument_list|(
name|screen
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|availableGeometry
specifier|const
name|QRect
name|QDesktopWidget
operator|::
name|availableGeometry
parameter_list|(
name|int
name|screenNo
parameter_list|)
specifier|const
block|{
name|QList
argument_list|<
name|QScreen
modifier|*
argument_list|>
name|screens
init|=
name|QGuiApplication
operator|::
name|screens
argument_list|()
decl_stmt|;
if|if
condition|(
name|screenNo
operator|==
operator|-
literal|1
condition|)
name|screenNo
operator|=
literal|0
expr_stmt|;
if|if
condition|(
name|screenNo
operator|<
literal|0
operator|||
name|screenNo
operator|>=
name|screens
operator|.
name|size
argument_list|()
condition|)
return|return
name|QRect
argument_list|()
return|;
else|else
return|return
name|screens
operator|.
name|at
argument_list|(
name|screenNo
argument_list|)
operator|->
name|availableGeometry
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|screenGeometry
specifier|const
name|QRect
name|QDesktopWidget
operator|::
name|screenGeometry
parameter_list|(
name|int
name|screenNo
parameter_list|)
specifier|const
block|{
name|QList
argument_list|<
name|QScreen
modifier|*
argument_list|>
name|screens
init|=
name|QGuiApplication
operator|::
name|screens
argument_list|()
decl_stmt|;
if|if
condition|(
name|screenNo
operator|==
operator|-
literal|1
condition|)
name|screenNo
operator|=
literal|0
expr_stmt|;
if|if
condition|(
name|screenNo
operator|<
literal|0
operator|||
name|screenNo
operator|>=
name|screens
operator|.
name|size
argument_list|()
condition|)
return|return
name|QRect
argument_list|()
return|;
else|else
return|return
name|screens
operator|.
name|at
argument_list|(
name|screenNo
argument_list|)
operator|->
name|geometry
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|screenNumber
name|int
name|QDesktopWidget
operator|::
name|screenNumber
parameter_list|(
specifier|const
name|QWidget
modifier|*
name|w
parameter_list|)
specifier|const
block|{
if|if
condition|(
operator|!
name|w
condition|)
return|return
name|primaryScreen
argument_list|()
return|;
specifier|const
name|QList
argument_list|<
name|QScreen
modifier|*
argument_list|>
name|allScreens
init|=
name|QGuiApplication
operator|::
name|screens
argument_list|()
decl_stmt|;
name|QList
argument_list|<
name|QScreen
modifier|*
argument_list|>
name|screens
init|=
name|allScreens
decl_stmt|;
if|if
condition|(
name|screens
operator|.
name|isEmpty
argument_list|()
condition|)
comment|// This should never happen
return|return
name|primaryScreen
argument_list|()
return|;
specifier|const
name|QWindow
modifier|*
name|winHandle
init|=
name|w
operator|->
name|windowHandle
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
name|winHandle
condition|)
block|{
if|if
condition|(
specifier|const
name|QWidget
modifier|*
name|nativeParent
init|=
name|w
operator|->
name|nativeParentWidget
argument_list|()
condition|)
name|winHandle
operator|=
name|nativeParent
operator|->
name|windowHandle
argument_list|()
expr_stmt|;
block|}
comment|// If there is more than one virtual desktop
if|if
condition|(
name|screens
operator|.
name|count
argument_list|()
operator|!=
name|screens
operator|.
name|constFirst
argument_list|()
operator|->
name|virtualSiblings
argument_list|()
operator|.
name|count
argument_list|()
condition|)
block|{
comment|// Find the root widget, get a QScreen from it and use the
comment|// virtual siblings for checking the window position.
if|if
condition|(
name|winHandle
condition|)
block|{
if|if
condition|(
specifier|const
name|QScreen
modifier|*
name|winScreen
init|=
name|winHandle
operator|->
name|screen
argument_list|()
condition|)
name|screens
operator|=
name|winScreen
operator|->
name|virtualSiblings
argument_list|()
expr_stmt|;
block|}
block|}
comment|// Get the screen number from window position using screen geometry
comment|// and proper screens.
name|QRect
name|frame
init|=
name|w
operator|->
name|frameGeometry
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
name|w
operator|->
name|isWindow
argument_list|()
condition|)
name|frame
operator|.
name|moveTopLeft
argument_list|(
name|w
operator|->
name|mapToGlobal
argument_list|(
name|QPoint
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
specifier|const
name|QRect
name|nativeFrame
init|=
name|QHighDpi
operator|::
name|toNativePixels
argument_list|(
name|frame
argument_list|,
name|winHandle
argument_list|)
decl_stmt|;
name|QScreen
modifier|*
name|widgetScreen
init|=
name|Q_NULLPTR
decl_stmt|;
name|int
name|largestArea
init|=
literal|0
decl_stmt|;
foreach|foreach
control|(
name|QScreen
modifier|*
name|screen
decl|,
name|screens
control|)
block|{
specifier|const
name|QRect
name|intersected
init|=
name|screen
operator|->
name|handle
argument_list|()
operator|->
name|geometry
argument_list|()
operator|.
name|intersected
argument_list|(
name|nativeFrame
argument_list|)
decl_stmt|;
name|int
name|area
init|=
name|intersected
operator|.
name|width
argument_list|()
operator|*
name|intersected
operator|.
name|height
argument_list|()
decl_stmt|;
if|if
condition|(
name|largestArea
operator|<
name|area
condition|)
block|{
name|widgetScreen
operator|=
name|screen
expr_stmt|;
name|largestArea
operator|=
name|area
expr_stmt|;
block|}
block|}
return|return
name|allScreens
operator|.
name|indexOf
argument_list|(
name|widgetScreen
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|screenNumber
name|int
name|QDesktopWidget
operator|::
name|screenNumber
parameter_list|(
specifier|const
name|QPoint
modifier|&
name|p
parameter_list|)
specifier|const
block|{
specifier|const
name|QList
argument_list|<
name|QScreen
modifier|*
argument_list|>
name|screens
init|=
name|QGuiApplication
operator|::
name|screens
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
name|screens
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
specifier|const
name|QList
argument_list|<
name|QScreen
modifier|*
argument_list|>
name|primaryScreens
init|=
name|screens
operator|.
name|first
argument_list|()
operator|->
name|virtualSiblings
argument_list|()
decl_stmt|;
comment|// Find the screen index on the primary virtual desktop first
foreach|foreach
control|(
name|QScreen
modifier|*
name|screen
decl|,
name|primaryScreens
control|)
block|{
if|if
condition|(
name|screen
operator|->
name|geometry
argument_list|()
operator|.
name|contains
argument_list|(
name|p
argument_list|)
condition|)
return|return
name|screens
operator|.
name|indexOf
argument_list|(
name|screen
argument_list|)
return|;
block|}
comment|// If the screen index is not found on primary virtual desktop, find
comment|// the screen index on all screens except the first which was for
comment|// sure in the previous loop. Some other screens may repeat. Find
comment|// only when there is more than one virtual desktop.
if|if
condition|(
name|screens
operator|.
name|count
argument_list|()
operator|!=
name|primaryScreens
operator|.
name|count
argument_list|()
condition|)
block|{
for|for
control|(
name|int
name|i
init|=
literal|1
init|;
name|i
operator|<
name|screens
operator|.
name|size
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
if|if
condition|(
name|screens
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
argument_list|)
condition|)
return|return
name|i
return|;
block|}
block|}
block|}
return|return
name|primaryScreen
argument_list|()
return|;
comment|//even better would be closest screen
block|}
end_function
begin_function
DECL|function|resizeEvent
name|void
name|QDesktopWidget
operator|::
name|resizeEvent
parameter_list|(
name|QResizeEvent
modifier|*
parameter_list|)
block|{ }
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_include
include|#
directive|include
file|"moc_qdesktopwidget.cpp"
end_include
begin_include
include|#
directive|include
file|"moc_qdesktopwidget_p.cpp"
end_include
end_unit
