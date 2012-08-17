begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QPLATFORMWINDOW_H
end_ifndef
begin_define
DECL|macro|QPLATFORMWINDOW_H
define|#
directive|define
name|QPLATFORMWINDOW_H
end_define
begin_comment
comment|//
end_comment
begin_comment
comment|//  W A R N I N G
end_comment
begin_comment
comment|//  -------------
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|// This file is part of the QPA API and is not meant to be used
end_comment
begin_comment
comment|// in applications. Usage of this API may make your code
end_comment
begin_comment
comment|// source and binary incompatible with future versions of Qt.
end_comment
begin_comment
comment|//
end_comment
begin_include
include|#
directive|include
file|<QtCore/qscopedpointer.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qrect.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qmargins.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qstring.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/qwindowdefs.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/qwindow.h>
end_include
begin_include
include|#
directive|include
file|<qpa/qplatformopenglcontext.h>
end_include
begin_include
include|#
directive|include
file|<qpa/qplatformsurface.h>
end_include
begin_decl_stmt
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
DECL|variable|QPlatformScreen
name|class
name|QPlatformScreen
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QPlatformWindowPrivate
name|class
name|QPlatformWindowPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QWindow
name|class
name|QWindow
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QIcon
name|class
name|QIcon
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QRegion
name|class
name|QRegion
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_GUI_EXPORT
name|QPlatformWindow
range|:
name|public
name|QPlatformSurface
block|{
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QPlatformWindow
argument_list|)
name|public
operator|:
name|explicit
name|QPlatformWindow
argument_list|(
name|QWindow
operator|*
name|window
argument_list|)
block|;
name|virtual
operator|~
name|QPlatformWindow
argument_list|()
block|;
name|QWindow
operator|*
name|window
argument_list|()
specifier|const
block|;
name|QPlatformWindow
operator|*
name|parent
argument_list|()
specifier|const
block|;
name|QPlatformScreen
operator|*
name|screen
argument_list|()
specifier|const
block|;
name|virtual
name|QSurfaceFormat
name|format
argument_list|()
specifier|const
block|;
name|virtual
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
name|QRect
name|geometry
argument_list|()
specifier|const
block|;
name|virtual
name|QMargins
name|frameMargins
argument_list|()
specifier|const
block|;
name|virtual
name|void
name|setVisible
argument_list|(
argument|bool visible
argument_list|)
block|;
name|virtual
name|Qt
operator|::
name|WindowFlags
name|setWindowFlags
argument_list|(
argument|Qt::WindowFlags flags
argument_list|)
block|;
name|virtual
name|Qt
operator|::
name|WindowState
name|setWindowState
argument_list|(
argument|Qt::WindowState state
argument_list|)
block|;
name|virtual
name|WId
name|winId
argument_list|()
specifier|const
block|;
name|virtual
name|void
name|setParent
argument_list|(
specifier|const
name|QPlatformWindow
operator|*
name|window
argument_list|)
block|;
name|virtual
name|void
name|setWindowTitle
argument_list|(
specifier|const
name|QString
operator|&
name|title
argument_list|)
block|;
name|virtual
name|void
name|setWindowIcon
argument_list|(
specifier|const
name|QIcon
operator|&
name|icon
argument_list|)
block|;
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
name|virtual
name|bool
name|isExposed
argument_list|()
specifier|const
block|;
name|virtual
name|bool
name|isActive
argument_list|()
specifier|const
block|;
name|virtual
name|bool
name|isEmbedded
argument_list|(
argument|const QPlatformWindow *parentWindow
argument_list|)
specifier|const
block|;
name|virtual
name|void
name|propagateSizeHints
argument_list|()
block|;
name|virtual
name|void
name|setOpacity
argument_list|(
argument|qreal level
argument_list|)
block|;
name|virtual
name|void
name|setMask
argument_list|(
specifier|const
name|QRegion
operator|&
name|region
argument_list|)
block|;
name|virtual
name|void
name|requestActivateWindow
argument_list|()
block|;
name|virtual
name|void
name|handleContentOrientationChange
argument_list|(
argument|Qt::ScreenOrientation orientation
argument_list|)
block|;
name|virtual
name|Qt
operator|::
name|ScreenOrientation
name|requestWindowOrientation
argument_list|(
argument|Qt::ScreenOrientation orientation
argument_list|)
block|;
name|virtual
name|bool
name|setKeyboardGrabEnabled
argument_list|(
argument|bool grab
argument_list|)
block|;
name|virtual
name|bool
name|setMouseGrabEnabled
argument_list|(
argument|bool grab
argument_list|)
block|;
name|virtual
name|bool
name|setWindowModified
argument_list|(
argument|bool modified
argument_list|)
block|;
name|virtual
name|void
name|windowEvent
argument_list|(
name|QEvent
operator|*
name|event
argument_list|)
block|;
name|virtual
name|bool
name|startSystemResize
argument_list|(
argument|const QPoint&pos
argument_list|,
argument|Qt::Corner corner
argument_list|)
block|;
name|virtual
name|void
name|setFrameStrutEventsEnabled
argument_list|(
argument|bool enabled
argument_list|)
block|;
name|virtual
name|bool
name|frameStrutEventsEnabled
argument_list|()
specifier|const
block|;
name|protected
operator|:
name|QScopedPointer
operator|<
name|QPlatformWindowPrivate
operator|>
name|d_ptr
block|;
name|private
operator|:
name|Q_DISABLE_COPY
argument_list|(
argument|QPlatformWindow
argument_list|)
block|}
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|QT_END_NAMESPACE
name|QT_END_HEADER
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|//QPLATFORMWINDOW_H
end_comment
end_unit
