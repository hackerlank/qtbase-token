begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QCOCOAWINDOW_H
end_ifndef
begin_define
DECL|macro|QCOCOAWINDOW_H
define|#
directive|define
name|QCOCOAWINDOW_H
end_define
begin_include
include|#
directive|include
file|<Cocoa/Cocoa.h>
end_include
begin_include
include|#
directive|include
file|<QPlatformWindow>
end_include
begin_include
include|#
directive|include
file|<QRect>
end_include
begin_include
include|#
directive|include
file|"qcocoaglcontext.h"
end_include
begin_include
include|#
directive|include
file|"qnsview.h"
end_include
begin_decl_stmt
unit|@
name|interface
name|QNSWindow
range|:
name|NSWindow
block|{  }
operator|-
operator|(
name|BOOL
operator|)
name|canBecomeKeyWindow
decl_stmt|;
end_decl_stmt
begin_expr_stmt
unit|@
name|end
expr|@
name|interface
name|QNSPanel
operator|:
name|NSPanel
block|{  }
operator|-
operator|(
name|BOOL
operator|)
name|canBecomeKeyWindow
expr_stmt|;
end_expr_stmt
begin_decl_stmt
unit|@
name|end
name|QT_BEGIN_NAMESPACE
comment|// QCocoaWindow
comment|//
comment|// QCocoaWindow is an NSView (not an NSWindow!) in the sense
comment|// that it relies on a NSView for all event handling and
comment|// graphics output and does not require a NSWindow, except for
comment|// for the window-related functions like setWindowTitle.
comment|//
comment|// As a consequence of this it is possible to embed the QCocoaWindow
comment|// in an NSView hierarchy by getting a pointer to the "backing"
comment|// NSView and not calling QCocoaWindow::show():
comment|//
comment|// QWindow *qtWindow = new MyWindow();
comment|// qtWindow->create();
comment|// QPlatformNativeInterface *platformNativeInterface = QGuiApplication::platformNativeInterface();
comment|// NSView *qtView = (NSView *)platformNativeInterface->nativeResourceForWindow("nsview", qtWindow);
comment|// [parentView addSubview:qtView];
comment|//
comment|// See the qt_on_cocoa manual tests for a working example, located
comment|// in tests/manual/cocoa at the time of writing.
name|class
name|QCocoaWindow
range|:
name|public
name|QPlatformWindow
block|{
name|public
operator|:
name|QCocoaWindow
argument_list|(
name|QWindow
operator|*
name|tlw
argument_list|)
block|;
operator|~
name|QCocoaWindow
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
name|void
name|setVisible
argument_list|(
argument|bool visible
argument_list|)
block|;
name|void
name|setWindowTitle
argument_list|(
specifier|const
name|QString
operator|&
name|title
argument_list|)
block|;
name|void
name|raise
argument_list|()
block|;
name|void
name|lower
argument_list|()
block|;
name|void
name|propagateSizeHints
argument_list|()
block|;
name|bool
name|setKeyboardGrabEnabled
argument_list|(
argument|bool grab
argument_list|)
block|;
name|bool
name|setMouseGrabEnabled
argument_list|(
argument|bool grab
argument_list|)
block|;
name|WId
name|winId
argument_list|()
specifier|const
block|;
name|NSView
operator|*
name|contentView
argument_list|()
specifier|const
block|;
name|void
name|windowDidMove
argument_list|()
block|;
name|void
name|windowDidResize
argument_list|()
block|;
name|void
name|windowWillClose
argument_list|()
block|;
name|void
name|setCurrentContext
argument_list|(
name|QCocoaGLContext
operator|*
name|context
argument_list|)
block|;
name|QCocoaGLContext
operator|*
name|currentContext
argument_list|()
specifier|const
block|;
name|protected
operator|:
name|void
name|determineWindowClass
argument_list|()
block|;
name|NSWindow
operator|*
name|createWindow
argument_list|()
block|;
name|QRect
name|windowGeometry
argument_list|()
specifier|const
block|;
name|QCocoaWindow
operator|*
name|parentCocoaWindow
argument_list|()
specifier|const
block|;
comment|// private:
name|public
operator|:
comment|// for QNSView
name|friend
name|class
name|QCocoaBackingStore
block|;
name|friend
name|class
name|QCocoaNativeInterface
block|;
name|QNSView
operator|*
name|m_contentView
block|;
name|QNSWindow
operator|*
name|m_nsWindow
block|;
name|quint32
name|m_windowAttributes
block|;
name|quint32
name|m_windowClass
block|;
name|bool
name|m_inConstructor
block|;
name|QCocoaGLContext
operator|*
name|m_glContext
block|; }
decl_stmt|;
end_decl_stmt
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QCOCOAWINDOW_H
end_comment
end_unit
