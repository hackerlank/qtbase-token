begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QWINDOW_H
end_ifndef
begin_define
DECL|macro|QWINDOW_H
define|#
directive|define
name|QWINDOW_H
end_define
begin_include
include|#
directive|include
file|<QtCore/QObject>
end_include
begin_include
include|#
directive|include
file|<QtCore/QEvent>
end_include
begin_include
include|#
directive|include
file|<QtCore/QMargins>
end_include
begin_include
include|#
directive|include
file|<QtCore/QRect>
end_include
begin_include
include|#
directive|include
file|<QtCore/qnamespace.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/qsurface.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/qsurfaceformat.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/qwindowdefs.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/qicon.h>
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_CURSOR
end_ifndef
begin_include
include|#
directive|include
file|<QtGui/qcursor.h>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_decl_stmt
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
DECL|variable|QWindowPrivate
name|class
name|QWindowPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QExposeEvent
name|class
name|QExposeEvent
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QFocusEvent
name|class
name|QFocusEvent
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QMoveEvent
name|class
name|QMoveEvent
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QResizeEvent
name|class
name|QResizeEvent
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QShowEvent
name|class
name|QShowEvent
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QHideEvent
name|class
name|QHideEvent
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QKeyEvent
name|class
name|QKeyEvent
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QMouseEvent
name|class
name|QMouseEvent
decl_stmt|;
end_decl_stmt
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_WHEELEVENT
end_ifndef
begin_decl_stmt
DECL|variable|QWheelEvent
name|class
name|QWheelEvent
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_decl_stmt
DECL|variable|QTouchEvent
name|class
name|QTouchEvent
decl_stmt|;
end_decl_stmt
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_TABLETEVENT
end_ifndef
begin_decl_stmt
DECL|variable|QTabletEvent
name|class
name|QTabletEvent
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_decl_stmt
DECL|variable|QPlatformSurface
name|class
name|QPlatformSurface
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QPlatformWindow
name|class
name|QPlatformWindow
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QBackingStore
name|class
name|QBackingStore
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QScreen
name|class
name|QScreen
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QAccessibleInterface
name|class
name|QAccessibleInterface
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QObject
name|class
name|Q_GUI_EXPORT
name|QWindow
range|:
name|public
name|QObject
decl_stmt|,
name|public
name|QSurface
block|{
name|Q_OBJECT
name|Q_DECLARE_PRIVATE
argument_list|(
name|QWindow
argument_list|)
comment|// All properties which are declared here are inherited by QQuickWindow and therefore available in QML.
comment|// So please think carefully about what it does to the QML namespace if you add any new ones,
comment|// particularly the possible meanings these names might have in any specializations of Window.
comment|// For example "state" (meaning windowState) is not a good property to declare, because it has
comment|// a different meaning in QQuickItem, and users will tend to assume it is the same for Window.
name|Q_PROPERTY
argument_list|(
name|QString
name|title
name|READ
name|title
name|WRITE
name|setTitle
argument_list|)
name|Q_PROPERTY
argument_list|(
name|Qt
operator|::
name|WindowModality
name|modality
name|READ
name|modality
name|WRITE
name|setModality
name|NOTIFY
name|modalityChanged
argument_list|)
name|Q_PROPERTY
argument_list|(
name|Qt
operator|::
name|WindowFlags
name|flags
name|READ
name|flags
name|WRITE
name|setFlags
argument_list|)
name|Q_PROPERTY
argument_list|(
name|int
name|x
name|READ
name|x
name|WRITE
name|setX
name|NOTIFY
name|xChanged
argument_list|)
name|Q_PROPERTY
argument_list|(
name|int
name|y
name|READ
name|y
name|WRITE
name|setY
name|NOTIFY
name|yChanged
argument_list|)
name|Q_PROPERTY
argument_list|(
name|int
name|width
name|READ
name|width
name|WRITE
name|setWidth
name|NOTIFY
name|widthChanged
argument_list|)
name|Q_PROPERTY
argument_list|(
name|int
name|height
name|READ
name|height
name|WRITE
name|setHeight
name|NOTIFY
name|heightChanged
argument_list|)
name|Q_PROPERTY
argument_list|(
name|QPoint
name|pos
name|READ
name|pos
name|WRITE
name|setPos
argument_list|)
name|Q_PROPERTY
argument_list|(
name|QSize
name|size
name|READ
name|size
name|WRITE
name|resize
argument_list|)
name|Q_PROPERTY
argument_list|(
name|QRect
name|geometry
name|READ
name|geometry
name|WRITE
name|setGeometry
argument_list|)
name|Q_PROPERTY
argument_list|(
name|int
name|minimumWidth
name|READ
name|minimumWidth
name|WRITE
name|setMinimumWidth
name|NOTIFY
name|minimumWidthChanged
argument_list|)
name|Q_PROPERTY
argument_list|(
name|int
name|minimumHeight
name|READ
name|minimumHeight
name|WRITE
name|setMinimumHeight
name|NOTIFY
name|minimumHeightChanged
argument_list|)
name|Q_PROPERTY
argument_list|(
name|int
name|maximumWidth
name|READ
name|maximumWidth
name|WRITE
name|setMaximumWidth
name|NOTIFY
name|maximumWidthChanged
argument_list|)
name|Q_PROPERTY
argument_list|(
name|int
name|maximumHeight
name|READ
name|maximumHeight
name|WRITE
name|setMaximumHeight
name|NOTIFY
name|maximumHeightChanged
argument_list|)
name|Q_PROPERTY
argument_list|(
name|bool
name|visible
name|READ
name|isVisible
name|WRITE
name|setVisible
name|NOTIFY
name|visibleChanged
argument_list|)
name|Q_PROPERTY
argument_list|(
name|Qt
operator|::
name|ScreenOrientation
name|contentOrientation
name|READ
name|contentOrientation
name|WRITE
name|reportContentOrientationChange
name|NOTIFY
name|contentOrientationChanged
argument_list|)
comment|// ------------------------------------------------------------------------
comment|// Temporary backwards-compatibility properties to be removed ASAP
name|Q_PROPERTY
argument_list|(
name|QString
name|windowTitle
name|READ
name|windowTitle
name|WRITE
name|setWindowTitle
argument_list|)
name|Q_PROPERTY
argument_list|(
name|QString
name|windowFilePath
name|READ
name|windowFilePath
name|WRITE
name|setWindowFilePath
argument_list|)
name|Q_PROPERTY
argument_list|(
name|QIcon
name|windowIcon
name|READ
name|windowIcon
name|WRITE
name|setWindowIcon
argument_list|)
name|Q_PROPERTY
argument_list|(
name|Qt
operator|::
name|WindowModality
name|windowModality
name|READ
name|windowModality
name|WRITE
name|setWindowModality
name|NOTIFY
name|windowModalityChanged
argument_list|)
name|public
range|:
name|Qt
operator|::
name|WindowModality
name|windowModality
argument_list|()
specifier|const
block|{
return|return
name|modality
argument_list|()
return|;
block|}
name|void
name|setWindowModality
argument_list|(
name|Qt
operator|::
name|WindowModality
name|wm
argument_list|)
block|{
name|setModality
argument_list|(
name|wm
argument_list|)
expr_stmt|;
block|}
name|void
name|setWindowFlags
argument_list|(
name|Qt
operator|::
name|WindowFlags
name|f
argument_list|)
block|{
name|setFlags
argument_list|(
name|f
argument_list|)
expr_stmt|;
block|}
name|Qt
operator|::
name|WindowFlags
name|windowFlags
argument_list|()
specifier|const
block|{
return|return
name|flags
argument_list|()
return|;
block|}
name|Qt
operator|::
name|WindowType
name|windowType
argument_list|()
specifier|const
block|{
return|return
name|type
argument_list|()
return|;
block|}
name|QString
name|windowTitle
argument_list|()
specifier|const
block|{
return|return
name|title
argument_list|()
return|;
block|}
name|void
name|requestActivateWindow
parameter_list|()
block|{
name|requestActivate
argument_list|()
expr_stmt|;
block|}
name|bool
name|requestWindowOrientation
argument_list|(
name|Qt
operator|::
name|ScreenOrientation
name|o
argument_list|)
block|{
return|return
name|requestOrientation
argument_list|(
name|o
argument_list|)
return|;
block|}
name|Qt
operator|::
name|ScreenOrientation
name|windowOrientation
argument_list|()
specifier|const
block|{
return|return
name|orientation
argument_list|()
return|;
block|}
name|void
name|setWindowFilePath
parameter_list|(
specifier|const
name|QString
modifier|&
name|fp
parameter_list|)
block|{
name|setFilePath
argument_list|(
name|fp
argument_list|)
expr_stmt|;
block|}
name|QString
name|windowFilePath
argument_list|()
specifier|const
block|{
return|return
name|filePath
argument_list|()
return|;
block|}
name|void
name|setWindowIcon
parameter_list|(
specifier|const
name|QIcon
modifier|&
name|i
parameter_list|)
block|{
name|setIcon
argument_list|(
name|i
argument_list|)
expr_stmt|;
block|}
name|QIcon
name|windowIcon
argument_list|()
specifier|const
block|{
return|return
name|icon
argument_list|()
return|;
block|}
name|void
name|setWindowTitle
parameter_list|(
specifier|const
name|QString
modifier|&
name|t
parameter_list|)
block|{
name|setTitle
argument_list|(
name|t
argument_list|)
expr_stmt|;
block|}
name|Q_SIGNALS
label|:
name|void
name|windowModalityChanged
argument_list|(
name|Qt
operator|::
name|WindowModality
name|windowModality
argument_list|)
decl_stmt|;
comment|// End of temporary backwards-compatibility properties
comment|// ------------------------------------------------------------------------
name|public
label|:
name|explicit
name|QWindow
parameter_list|(
name|QScreen
modifier|*
name|screen
init|=
literal|0
parameter_list|)
function_decl|;
name|explicit
name|QWindow
parameter_list|(
name|QWindow
modifier|*
name|parent
parameter_list|)
function_decl|;
name|virtual
operator|~
name|QWindow
argument_list|()
expr_stmt|;
name|void
name|setSurfaceType
parameter_list|(
name|SurfaceType
name|surfaceType
parameter_list|)
function_decl|;
name|SurfaceType
name|surfaceType
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|isVisible
argument_list|()
specifier|const
expr_stmt|;
name|void
name|create
parameter_list|()
function_decl|;
name|WId
name|winId
argument_list|()
specifier|const
expr_stmt|;
name|QWindow
operator|*
name|parent
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setParent
parameter_list|(
name|QWindow
modifier|*
name|parent
parameter_list|)
function_decl|;
name|bool
name|isTopLevel
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|isModal
argument_list|()
specifier|const
expr_stmt|;
name|Qt
operator|::
name|WindowModality
name|modality
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setModality
argument_list|(
name|Qt
operator|::
name|WindowModality
name|modality
argument_list|)
decl_stmt|;
name|void
name|setFormat
parameter_list|(
specifier|const
name|QSurfaceFormat
modifier|&
name|format
parameter_list|)
function_decl|;
name|QSurfaceFormat
name|format
argument_list|()
specifier|const
expr_stmt|;
name|QSurfaceFormat
name|requestedFormat
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setFlags
argument_list|(
name|Qt
operator|::
name|WindowFlags
name|flags
argument_list|)
decl_stmt|;
name|Qt
operator|::
name|WindowFlags
name|flags
argument_list|()
specifier|const
expr_stmt|;
name|Qt
operator|::
name|WindowType
name|type
argument_list|()
specifier|const
expr_stmt|;
name|QString
name|title
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setOpacity
parameter_list|(
name|qreal
name|level
parameter_list|)
function_decl|;
name|void
name|requestActivate
parameter_list|()
function_decl|;
name|bool
name|isActive
argument_list|()
specifier|const
expr_stmt|;
name|void
name|reportContentOrientationChange
argument_list|(
name|Qt
operator|::
name|ScreenOrientation
name|orientation
argument_list|)
decl_stmt|;
name|Qt
operator|::
name|ScreenOrientation
name|contentOrientation
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|requestOrientation
argument_list|(
name|Qt
operator|::
name|ScreenOrientation
name|orientation
argument_list|)
decl_stmt|;
name|Qt
operator|::
name|ScreenOrientation
name|orientation
argument_list|()
specifier|const
expr_stmt|;
name|Qt
operator|::
name|WindowState
name|windowState
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setWindowState
argument_list|(
name|Qt
operator|::
name|WindowState
name|state
argument_list|)
decl_stmt|;
name|void
name|setTransientParent
parameter_list|(
name|QWindow
modifier|*
name|parent
parameter_list|)
function_decl|;
name|QWindow
operator|*
name|transientParent
argument_list|()
specifier|const
expr_stmt|;
enum|enum
name|AncestorMode
block|{
name|ExcludeTransients
block|,
name|IncludeTransients
block|}
enum|;
name|bool
name|isAncestorOf
argument_list|(
specifier|const
name|QWindow
operator|*
name|child
argument_list|,
name|AncestorMode
name|mode
operator|=
name|IncludeTransients
argument_list|)
decl|const
decl_stmt|;
name|bool
name|isExposed
argument_list|()
specifier|const
expr_stmt|;
name|int
name|minimumWidth
argument_list|()
specifier|const
block|{
return|return
name|minimumSize
argument_list|()
operator|.
name|width
argument_list|()
return|;
block|}
name|int
name|minimumHeight
argument_list|()
specifier|const
block|{
return|return
name|minimumSize
argument_list|()
operator|.
name|height
argument_list|()
return|;
block|}
name|int
name|maximumWidth
argument_list|()
specifier|const
block|{
return|return
name|maximumSize
argument_list|()
operator|.
name|width
argument_list|()
return|;
block|}
name|int
name|maximumHeight
argument_list|()
specifier|const
block|{
return|return
name|maximumSize
argument_list|()
operator|.
name|height
argument_list|()
return|;
block|}
name|QSize
name|minimumSize
argument_list|()
specifier|const
expr_stmt|;
name|QSize
name|maximumSize
argument_list|()
specifier|const
expr_stmt|;
name|QSize
name|baseSize
argument_list|()
specifier|const
expr_stmt|;
name|QSize
name|sizeIncrement
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setMinimumSize
parameter_list|(
specifier|const
name|QSize
modifier|&
name|size
parameter_list|)
function_decl|;
name|void
name|setMaximumSize
parameter_list|(
specifier|const
name|QSize
modifier|&
name|size
parameter_list|)
function_decl|;
name|void
name|setBaseSize
parameter_list|(
specifier|const
name|QSize
modifier|&
name|size
parameter_list|)
function_decl|;
name|void
name|setSizeIncrement
parameter_list|(
specifier|const
name|QSize
modifier|&
name|size
parameter_list|)
function_decl|;
name|void
name|setGeometry
parameter_list|(
name|int
name|posx
parameter_list|,
name|int
name|posy
parameter_list|,
name|int
name|w
parameter_list|,
name|int
name|h
parameter_list|)
block|{
name|setGeometry
argument_list|(
name|QRect
argument_list|(
name|posx
argument_list|,
name|posy
argument_list|,
name|w
argument_list|,
name|h
argument_list|)
argument_list|)
expr_stmt|;
block|}
name|void
name|setGeometry
parameter_list|(
specifier|const
name|QRect
modifier|&
name|rect
parameter_list|)
function_decl|;
name|QRect
name|geometry
argument_list|()
specifier|const
expr_stmt|;
name|QMargins
name|frameMargins
argument_list|()
specifier|const
expr_stmt|;
name|QRect
name|frameGeometry
argument_list|()
specifier|const
expr_stmt|;
name|QPoint
name|framePos
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setFramePos
parameter_list|(
specifier|const
name|QPoint
modifier|&
name|point
parameter_list|)
function_decl|;
specifier|inline
name|int
name|width
argument_list|()
specifier|const
block|{
return|return
name|geometry
argument_list|()
operator|.
name|width
argument_list|()
return|;
block|}
specifier|inline
name|int
name|height
argument_list|()
specifier|const
block|{
return|return
name|geometry
argument_list|()
operator|.
name|height
argument_list|()
return|;
block|}
specifier|inline
name|int
name|x
argument_list|()
specifier|const
block|{
return|return
name|geometry
argument_list|()
operator|.
name|x
argument_list|()
return|;
block|}
specifier|inline
name|int
name|y
argument_list|()
specifier|const
block|{
return|return
name|geometry
argument_list|()
operator|.
name|y
argument_list|()
return|;
block|}
specifier|inline
name|QSize
name|size
argument_list|()
specifier|const
block|{
return|return
name|geometry
argument_list|()
operator|.
name|size
argument_list|()
return|;
block|}
specifier|inline
name|QPoint
name|pos
argument_list|()
specifier|const
block|{
return|return
name|geometry
argument_list|()
operator|.
name|topLeft
argument_list|()
return|;
block|}
specifier|inline
name|void
name|setPos
parameter_list|(
specifier|const
name|QPoint
modifier|&
name|pt
parameter_list|)
block|{
name|setGeometry
argument_list|(
name|QRect
argument_list|(
name|pt
argument_list|,
name|size
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
block|}
specifier|inline
name|void
name|setPos
parameter_list|(
name|int
name|posx
parameter_list|,
name|int
name|posy
parameter_list|)
block|{
name|setPos
argument_list|(
name|QPoint
argument_list|(
name|posx
argument_list|,
name|posy
argument_list|)
argument_list|)
expr_stmt|;
block|}
name|void
name|resize
parameter_list|(
specifier|const
name|QSize
modifier|&
name|newSize
parameter_list|)
function_decl|;
specifier|inline
name|void
name|resize
parameter_list|(
name|int
name|w
parameter_list|,
name|int
name|h
parameter_list|)
block|{
name|resize
argument_list|(
name|QSize
argument_list|(
name|w
argument_list|,
name|h
argument_list|)
argument_list|)
expr_stmt|;
block|}
name|void
name|setFilePath
parameter_list|(
specifier|const
name|QString
modifier|&
name|filePath
parameter_list|)
function_decl|;
name|QString
name|filePath
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setIcon
parameter_list|(
specifier|const
name|QIcon
modifier|&
name|icon
parameter_list|)
function_decl|;
name|QIcon
name|icon
argument_list|()
specifier|const
expr_stmt|;
name|void
name|destroy
parameter_list|()
function_decl|;
name|QPlatformWindow
operator|*
name|handle
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|setKeyboardGrabEnabled
parameter_list|(
name|bool
name|grab
parameter_list|)
function_decl|;
name|bool
name|setMouseGrabEnabled
parameter_list|(
name|bool
name|grab
parameter_list|)
function_decl|;
name|QScreen
operator|*
name|screen
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setScreen
parameter_list|(
name|QScreen
modifier|*
name|screen
parameter_list|)
function_decl|;
name|virtual
name|QAccessibleInterface
operator|*
name|accessibleRoot
argument_list|()
specifier|const
expr_stmt|;
name|virtual
name|QObject
operator|*
name|focusObject
argument_list|()
specifier|const
expr_stmt|;
name|QPoint
name|mapToGlobal
argument_list|(
specifier|const
name|QPoint
operator|&
name|pos
argument_list|)
decl|const
decl_stmt|;
name|QPoint
name|mapFromGlobal
argument_list|(
specifier|const
name|QPoint
operator|&
name|pos
argument_list|)
decl|const
decl_stmt|;
ifndef|#
directive|ifndef
name|QT_NO_CURSOR
name|QCursor
name|cursor
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setCursor
parameter_list|(
specifier|const
name|QCursor
modifier|&
parameter_list|)
function_decl|;
name|void
name|unsetCursor
parameter_list|()
function_decl|;
endif|#
directive|endif
name|public
name|Q_SLOTS
range|:
name|void
name|setVisible
argument_list|(
argument|bool visible
argument_list|)
decl_stmt|;
name|void
name|show
parameter_list|()
function_decl|;
name|void
name|hide
parameter_list|()
function_decl|;
name|void
name|showMinimized
parameter_list|()
function_decl|;
name|void
name|showMaximized
parameter_list|()
function_decl|;
name|void
name|showFullScreen
parameter_list|()
function_decl|;
name|void
name|showNormal
parameter_list|()
function_decl|;
name|bool
name|close
parameter_list|()
function_decl|;
name|void
name|raise
parameter_list|()
function_decl|;
name|void
name|lower
parameter_list|()
function_decl|;
name|void
name|setTitle
parameter_list|(
specifier|const
name|QString
modifier|&
parameter_list|)
function_decl|;
name|void
name|setX
parameter_list|(
name|int
name|arg
parameter_list|)
block|{
if|if
condition|(
name|x
argument_list|()
operator|!=
name|arg
condition|)
name|setGeometry
argument_list|(
name|QRect
argument_list|(
name|arg
argument_list|,
name|y
argument_list|()
argument_list|,
name|width
argument_list|()
argument_list|,
name|height
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
block|}
name|void
name|setY
parameter_list|(
name|int
name|arg
parameter_list|)
block|{
if|if
condition|(
name|y
argument_list|()
operator|!=
name|arg
condition|)
name|setGeometry
argument_list|(
name|QRect
argument_list|(
name|x
argument_list|()
argument_list|,
name|arg
argument_list|,
name|width
argument_list|()
argument_list|,
name|height
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
block|}
name|void
name|setWidth
parameter_list|(
name|int
name|arg
parameter_list|)
block|{
if|if
condition|(
name|width
argument_list|()
operator|!=
name|arg
condition|)
name|setGeometry
argument_list|(
name|QRect
argument_list|(
name|x
argument_list|()
argument_list|,
name|y
argument_list|()
argument_list|,
name|arg
argument_list|,
name|height
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
block|}
name|void
name|setHeight
parameter_list|(
name|int
name|arg
parameter_list|)
block|{
if|if
condition|(
name|height
argument_list|()
operator|!=
name|arg
condition|)
name|setGeometry
argument_list|(
name|QRect
argument_list|(
name|x
argument_list|()
argument_list|,
name|y
argument_list|()
argument_list|,
name|width
argument_list|()
argument_list|,
name|arg
argument_list|)
argument_list|)
expr_stmt|;
block|}
name|void
name|setMinimumWidth
parameter_list|(
name|int
name|w
parameter_list|)
function_decl|;
name|void
name|setMinimumHeight
parameter_list|(
name|int
name|h
parameter_list|)
function_decl|;
name|void
name|setMaximumWidth
parameter_list|(
name|int
name|w
parameter_list|)
function_decl|;
name|void
name|setMaximumHeight
parameter_list|(
name|int
name|h
parameter_list|)
function_decl|;
name|Q_SIGNALS
label|:
name|void
name|screenChanged
parameter_list|(
name|QScreen
modifier|*
name|screen
parameter_list|)
function_decl|;
name|void
name|modalityChanged
argument_list|(
name|Qt
operator|::
name|WindowModality
name|modality
argument_list|)
decl_stmt|;
name|void
name|windowStateChanged
argument_list|(
name|Qt
operator|::
name|WindowState
name|windowState
argument_list|)
decl_stmt|;
name|void
name|xChanged
parameter_list|(
name|int
name|arg
parameter_list|)
function_decl|;
name|void
name|yChanged
parameter_list|(
name|int
name|arg
parameter_list|)
function_decl|;
name|void
name|widthChanged
parameter_list|(
name|int
name|arg
parameter_list|)
function_decl|;
name|void
name|heightChanged
parameter_list|(
name|int
name|arg
parameter_list|)
function_decl|;
name|void
name|minimumWidthChanged
parameter_list|(
name|int
name|arg
parameter_list|)
function_decl|;
name|void
name|minimumHeightChanged
parameter_list|(
name|int
name|arg
parameter_list|)
function_decl|;
name|void
name|maximumWidthChanged
parameter_list|(
name|int
name|arg
parameter_list|)
function_decl|;
name|void
name|maximumHeightChanged
parameter_list|(
name|int
name|arg
parameter_list|)
function_decl|;
name|void
name|visibleChanged
parameter_list|(
name|bool
name|arg
parameter_list|)
function_decl|;
name|void
name|contentOrientationChanged
argument_list|(
name|Qt
operator|::
name|ScreenOrientation
name|orientation
argument_list|)
decl_stmt|;
name|void
name|focusObjectChanged
parameter_list|(
name|QObject
modifier|*
name|object
parameter_list|)
function_decl|;
name|private
name|Q_SLOTS
range|:
name|void
name|screenDestroyed
argument_list|(
name|QObject
operator|*
name|screen
argument_list|)
decl_stmt|;
name|protected
label|:
name|virtual
name|void
name|exposeEvent
parameter_list|(
name|QExposeEvent
modifier|*
parameter_list|)
function_decl|;
name|virtual
name|void
name|resizeEvent
parameter_list|(
name|QResizeEvent
modifier|*
parameter_list|)
function_decl|;
name|virtual
name|void
name|moveEvent
parameter_list|(
name|QMoveEvent
modifier|*
parameter_list|)
function_decl|;
name|virtual
name|void
name|focusInEvent
parameter_list|(
name|QFocusEvent
modifier|*
parameter_list|)
function_decl|;
name|virtual
name|void
name|focusOutEvent
parameter_list|(
name|QFocusEvent
modifier|*
parameter_list|)
function_decl|;
name|virtual
name|void
name|showEvent
parameter_list|(
name|QShowEvent
modifier|*
parameter_list|)
function_decl|;
name|virtual
name|void
name|hideEvent
parameter_list|(
name|QHideEvent
modifier|*
parameter_list|)
function_decl|;
name|virtual
name|bool
name|event
parameter_list|(
name|QEvent
modifier|*
parameter_list|)
function_decl|;
name|virtual
name|void
name|keyPressEvent
parameter_list|(
name|QKeyEvent
modifier|*
parameter_list|)
function_decl|;
name|virtual
name|void
name|keyReleaseEvent
parameter_list|(
name|QKeyEvent
modifier|*
parameter_list|)
function_decl|;
name|virtual
name|void
name|mousePressEvent
parameter_list|(
name|QMouseEvent
modifier|*
parameter_list|)
function_decl|;
name|virtual
name|void
name|mouseReleaseEvent
parameter_list|(
name|QMouseEvent
modifier|*
parameter_list|)
function_decl|;
name|virtual
name|void
name|mouseDoubleClickEvent
parameter_list|(
name|QMouseEvent
modifier|*
parameter_list|)
function_decl|;
name|virtual
name|void
name|mouseMoveEvent
parameter_list|(
name|QMouseEvent
modifier|*
parameter_list|)
function_decl|;
ifndef|#
directive|ifndef
name|QT_NO_WHEELEVENT
name|virtual
name|void
name|wheelEvent
parameter_list|(
name|QWheelEvent
modifier|*
parameter_list|)
function_decl|;
endif|#
directive|endif
name|virtual
name|void
name|touchEvent
parameter_list|(
name|QTouchEvent
modifier|*
parameter_list|)
function_decl|;
ifndef|#
directive|ifndef
name|QT_NO_TABLETEVENT
name|virtual
name|void
name|tabletEvent
parameter_list|(
name|QTabletEvent
modifier|*
parameter_list|)
function_decl|;
endif|#
directive|endif
name|virtual
name|bool
name|nativeEvent
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|eventType
parameter_list|,
name|void
modifier|*
name|message
parameter_list|,
name|long
modifier|*
name|result
parameter_list|)
function_decl|;
name|QWindow
argument_list|(
name|QWindowPrivate
operator|&
name|dd
argument_list|,
name|QWindow
operator|*
name|parent
argument_list|)
expr_stmt|;
name|private
label|:
name|QPlatformSurface
operator|*
name|surfaceHandle
argument_list|()
specifier|const
expr_stmt|;
name|Q_DISABLE_COPY
argument_list|(
argument|QWindow
argument_list|)
name|friend
name|class
name|QGuiApplication
decl_stmt|;
name|friend
name|class
name|QGuiApplicationPrivate
decl_stmt|;
name|friend
name|Q_GUI_EXPORT
name|QWindowPrivate
modifier|*
name|qt_window_private
parameter_list|(
name|QWindow
modifier|*
name|window
parameter_list|)
function_decl|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_expr_stmt
name|QT_END_NAMESPACE
name|QT_END_HEADER
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QWINDOW_H
end_comment
end_unit
