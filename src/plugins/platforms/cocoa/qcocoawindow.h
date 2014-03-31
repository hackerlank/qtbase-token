begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
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
file|<qpa/qplatformwindow.h>
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
begin_expr_stmt
name|QT_FORWARD_DECLARE_CLASS
argument_list|(
name|QCocoaWindow
argument_list|)
expr|@
name|class
name|QNSWindowHelper
expr_stmt|;
end_expr_stmt
begin_expr_stmt
unit|@
name|protocol
name|QNSWindowProtocol
expr|@
DECL|variable|helper
name|property
argument_list|(
argument|nonatomic
argument_list|,
argument|readonly
argument_list|)
name|QNSWindowHelper
operator|*
name|helper
expr_stmt|;
end_expr_stmt
begin_expr_stmt
operator|-
operator|(
name|void
operator|)
name|superSendEvent
operator|:
operator|(
name|NSEvent
operator|*
operator|)
name|theEvent
expr_stmt|;
end_expr_stmt
begin_expr_stmt
operator|-
operator|(
name|void
operator|)
name|closeAndRelease
expr_stmt|;
end_expr_stmt
begin_macro
unit|@
name|end
end_macro
begin_typedef
DECL|typedef|QCocoaNSWindow
typedef|typedef
name|NSWindow
operator|<
name|QNSWindowProtocol
operator|>
name|QCocoaNSWindow
expr_stmt|;
end_typedef
begin_decl_stmt
DECL|typedef|QCocoaNSWindow
unit|@
name|interface
name|QNSWindowHelper
range|:
name|NSObject
block|{
name|QCocoaNSWindow
operator|*
name|_window
block|;
name|QCocoaWindow
operator|*
name|_platformWindow
block|;
name|BOOL
name|_grabbingMouse
block|;
name|BOOL
name|_releaseOnMouseUp
block|; }
expr|@
name|property
argument_list|(
argument|nonatomic
argument_list|,
argument|readonly
argument_list|)
name|QCocoaNSWindow
operator|*
name|window
decl_stmt|;
end_decl_stmt
begin_macro
unit|@
name|property
argument_list|(
argument|nonatomic
argument_list|,
argument|readonly
argument_list|)
end_macro
begin_decl_stmt
name|QCocoaWindow
modifier|*
name|platformWindow
decl_stmt|;
end_decl_stmt
begin_macro
unit|@
DECL|variable|grabbingMouse
name|property
argument_list|(
argument|nonatomic
argument_list|)
end_macro
begin_decl_stmt
DECL|variable|grabbingMouse
name|BOOL
name|grabbingMouse
decl_stmt|;
end_decl_stmt
begin_macro
DECL|variable|grabbingMouse
unit|@
name|property
argument_list|(
argument|nonatomic
argument_list|)
end_macro
begin_decl_stmt
name|BOOL
name|releaseOnMouseUp
decl_stmt|;
end_decl_stmt
begin_expr_stmt
operator|-
operator|(
name|id
operator|)
name|initWithNSWindow
operator|:
operator|(
name|QCocoaNSWindow
operator|*
operator|)
name|window
name|platformWindow
operator|:
operator|(
name|QCocoaWindow
operator|*
operator|)
name|platformWindow
expr_stmt|;
end_expr_stmt
begin_expr_stmt
operator|-
operator|(
name|void
operator|)
name|handleWindowEvent
operator|:
operator|(
name|NSEvent
operator|*
operator|)
name|theEvent
expr_stmt|;
end_expr_stmt
begin_expr_stmt
operator|-
operator|(
name|void
operator|)
name|clearWindow
expr_stmt|;
end_expr_stmt
begin_expr_stmt
unit|@
name|end
expr|@
name|interface
name|QNSWindow
operator|:
name|NSWindow
operator|<
name|QNSWindowProtocol
operator|>
block|{
name|QNSWindowHelper
operator|*
name|_helper
block|; }
expr|@
name|property
argument_list|(
argument|nonatomic
argument_list|,
argument|readonly
argument_list|)
name|QNSWindowHelper
operator|*
name|helper
expr_stmt|;
end_expr_stmt
begin_expr_stmt
operator|-
operator|(
name|id
operator|)
name|initWithContentRect
operator|:
operator|(
name|NSRect
operator|)
name|contentRect
name|styleMask
operator|:
operator|(
name|NSUInteger
operator|)
name|windowStyle
name|qPlatformWindow
operator|:
operator|(
name|QCocoaWindow
operator|*
operator|)
name|qpw
expr_stmt|;
end_expr_stmt
begin_expr_stmt
unit|@
name|end
expr|@
name|interface
name|QNSPanel
operator|:
name|NSPanel
operator|<
name|QNSWindowProtocol
operator|>
block|{
name|QNSWindowHelper
operator|*
name|_helper
block|; }
expr|@
name|property
argument_list|(
argument|nonatomic
argument_list|,
argument|readonly
argument_list|)
name|QNSWindowHelper
operator|*
name|helper
expr_stmt|;
end_expr_stmt
begin_expr_stmt
operator|-
operator|(
name|id
operator|)
name|initWithContentRect
operator|:
operator|(
name|NSRect
operator|)
name|contentRect
name|styleMask
operator|:
operator|(
name|NSUInteger
operator|)
name|windowStyle
name|qPlatformWindow
operator|:
operator|(
name|QCocoaWindow
operator|*
operator|)
name|qpw
expr_stmt|;
end_expr_stmt
begin_expr_stmt
unit|@
name|end
expr|@
DECL|variable|QNSWindowDelegate
name|class
name|QNSWindowDelegate
expr_stmt|;
end_expr_stmt
begin_decl_stmt
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
DECL|variable|QCocoaMenuBar
name|class
name|QCocoaMenuBar
decl_stmt|;
end_decl_stmt
begin_decl_stmt
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
name|QRect
name|geometry
argument_list|()
specifier|const
block|;
name|void
name|setCocoaGeometry
argument_list|(
specifier|const
name|QRect
operator|&
name|rect
argument_list|)
block|;
name|void
name|clipChildWindows
argument_list|()
block|;
name|void
name|clipWindow
argument_list|(
specifier|const
name|NSRect
operator|&
name|clipRect
argument_list|)
block|;
name|void
name|show
argument_list|(
argument|bool becauseOfAncestor = false
argument_list|)
block|;
name|void
name|hide
argument_list|(
argument|bool becauseOfAncestor = false
argument_list|)
block|;
name|void
name|setVisible
argument_list|(
argument|bool visible
argument_list|)
block|;
name|void
name|setWindowFlags
argument_list|(
argument|Qt::WindowFlags flags
argument_list|)
block|;
name|void
name|setWindowState
argument_list|(
argument|Qt::WindowState state
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
name|setWindowFilePath
argument_list|(
specifier|const
name|QString
operator|&
name|filePath
argument_list|)
block|;
name|void
name|setWindowIcon
argument_list|(
specifier|const
name|QIcon
operator|&
name|icon
argument_list|)
block|;
name|void
name|setAlertState
argument_list|(
argument|bool enabled
argument_list|)
block|;
name|bool
name|isAlertState
argument_list|()
specifier|const
block|;
name|void
name|raise
argument_list|()
block|;
name|void
name|lower
argument_list|()
block|;
name|bool
name|isExposed
argument_list|()
specifier|const
block|;
name|bool
name|isOpaque
argument_list|()
specifier|const
block|;
name|void
name|propagateSizeHints
argument_list|()
block|;
name|void
name|setOpacity
argument_list|(
argument|qreal level
argument_list|)
block|;
name|void
name|setMask
argument_list|(
specifier|const
name|QRegion
operator|&
name|region
argument_list|)
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
name|QMargins
name|frameMargins
argument_list|()
specifier|const
block|;
name|QSurfaceFormat
name|format
argument_list|()
specifier|const
block|;
name|void
name|requestActivateWindow
argument_list|()
block|;
name|WId
name|winId
argument_list|()
specifier|const
block|;
name|void
name|setParent
argument_list|(
specifier|const
name|QPlatformWindow
operator|*
name|window
argument_list|)
block|;
name|NSView
operator|*
name|contentView
argument_list|()
specifier|const
block|;
name|void
name|setContentView
argument_list|(
name|NSView
operator|*
name|contentView
argument_list|)
block|;
name|QNSView
operator|*
name|qtView
argument_list|()
specifier|const
block|;
name|NSWindow
operator|*
name|nativeWindow
argument_list|()
specifier|const
block|;
name|void
name|setEmbeddedInForeignView
argument_list|(
argument|bool subwindow
argument_list|)
block|;
name|void
name|windowWillMove
argument_list|()
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
name|windowDidEndLiveResize
argument_list|()
block|;
name|bool
name|windowShouldClose
argument_list|()
block|;
name|bool
name|windowIsPopupType
argument_list|(
argument|Qt::WindowType type = Qt::Widget
argument_list|)
specifier|const
block|;
name|void
name|setSynchedWindowStateFromWindow
argument_list|()
block|;
name|NSInteger
name|windowLevel
argument_list|(
argument|Qt::WindowFlags flags
argument_list|)
block|;
name|NSUInteger
name|windowStyleMask
argument_list|(
argument|Qt::WindowFlags flags
argument_list|)
block|;
name|void
name|setWindowShadow
argument_list|(
argument|Qt::WindowFlags flags
argument_list|)
block|;
name|void
name|setWindowZoomButton
argument_list|(
argument|Qt::WindowFlags flags
argument_list|)
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
name|bool
name|setWindowModified
argument_list|(
argument|bool modified
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|void
name|setFrameStrutEventsEnabled
argument_list|(
argument|bool enabled
argument_list|)
block|;
name|bool
name|frameStrutEventsEnabled
argument_list|()
specifier|const
block|{
return|return
name|m_frameStrutEventsEnabled
return|;
block|}
name|void
name|setMenubar
argument_list|(
name|QCocoaMenuBar
operator|*
name|mb
argument_list|)
block|;
name|QCocoaMenuBar
operator|*
name|menubar
argument_list|()
specifier|const
block|;
name|void
name|setWindowCursor
argument_list|(
name|NSCursor
operator|*
name|cursor
argument_list|)
block|;
name|void
name|registerTouch
argument_list|(
argument|bool enable
argument_list|)
block|;
name|void
name|setContentBorderThickness
argument_list|(
argument|int topThickness
argument_list|,
argument|int bottomThickness
argument_list|)
block|;
name|void
name|registerContentBorderArea
argument_list|(
argument|quintptr identifier
argument_list|,
argument|int upper
argument_list|,
argument|int lower
argument_list|)
block|;
name|void
name|setContentBorderAreaEnabled
argument_list|(
argument|quintptr identifier
argument_list|,
argument|bool enable
argument_list|)
block|;
name|void
name|setContentBorderEnabled
argument_list|(
argument|bool enable
argument_list|)
block|;
name|void
name|applyContentBorderThickness
argument_list|(
name|NSWindow
operator|*
name|window
argument_list|)
block|;
name|void
name|updateNSToolbar
argument_list|()
block|;
name|qreal
name|devicePixelRatio
argument_list|()
specifier|const
block|;
name|bool
name|isWindowExposable
argument_list|()
block|;
name|void
name|exposeWindow
argument_list|()
block|;
name|void
name|obscureWindow
argument_list|()
block|;
name|void
name|updateExposedGeometry
argument_list|()
block|;
name|QWindow
operator|*
name|childWindowAt
argument_list|(
argument|QPoint windowPoint
argument_list|)
block|;
name|protected
operator|:
name|void
name|recreateWindow
argument_list|(
specifier|const
name|QPlatformWindow
operator|*
name|parentWindow
argument_list|)
block|;
name|QCocoaNSWindow
operator|*
name|createNSWindow
argument_list|()
block|;
name|void
name|setNSWindow
argument_list|(
name|QCocoaNSWindow
operator|*
name|window
argument_list|)
block|;
name|bool
name|shouldUseNSPanel
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
name|void
name|syncWindowState
argument_list|(
argument|Qt::WindowState newState
argument_list|)
block|;
name|void
name|reinsertChildWindow
argument_list|(
name|QCocoaWindow
operator|*
name|child
argument_list|)
block|;
name|void
name|removeChildWindow
argument_list|(
name|QCocoaWindow
operator|*
name|child
argument_list|)
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
name|NSView
operator|*
name|m_contentView
block|;
name|QNSView
operator|*
name|m_qtView
block|;
name|QCocoaNSWindow
operator|*
name|m_nsWindow
block|;
name|QCocoaWindow
operator|*
name|m_forwardWindow
block|;
comment|// TODO merge to one variable if possible
name|bool
name|m_contentViewIsEmbedded
block|;
comment|// true if the m_contentView is actually embedded in a "foreign" NSView hiearchy
name|bool
name|m_contentViewIsToBeEmbedded
block|;
comment|// true if the m_contentView is intended to be embedded in a "foreign" NSView hiearchy
name|QCocoaWindow
operator|*
name|m_parentCocoaWindow
block|;
name|bool
name|m_isNSWindowChild
block|;
comment|// this window is a non-top level QWindow with a NSWindow.
name|QList
operator|<
name|QCocoaWindow
operator|*
operator|>
name|m_childWindows
block|;
name|Qt
operator|::
name|WindowFlags
name|m_windowFlags
block|;
name|bool
name|m_effectivelyMaximized
block|;
name|Qt
operator|::
name|WindowState
name|m_synchedWindowState
block|;
name|Qt
operator|::
name|WindowModality
name|m_windowModality
block|;
name|QPointer
operator|<
name|QWindow
operator|>
name|m_activePopupWindow
block|;
name|QPointer
operator|<
name|QWindow
operator|>
name|m_enterLeaveTargetWindow
block|;
name|bool
name|m_windowUnderMouse
block|;
name|bool
name|m_inConstructor
block|;
name|QCocoaGLContext
operator|*
name|m_glContext
block|;
name|QCocoaMenuBar
operator|*
name|m_menubar
block|;
name|NSCursor
operator|*
name|m_windowCursor
block|;
name|bool
name|m_hasModalSession
block|;
name|bool
name|m_frameStrutEventsEnabled
block|;
name|bool
name|m_geometryUpdateExposeAllowed
block|;
name|bool
name|m_isExposed
block|;
name|QRect
name|m_exposedGeometry
block|;
name|int
name|m_registerTouchCount
block|;
name|bool
name|m_resizableTransientParent
block|;
name|bool
name|m_hiddenByClipping
block|;
name|bool
name|m_hiddenByAncestor
block|;
specifier|static
specifier|const
name|int
name|NoAlertRequest
block|;
name|NSInteger
name|m_alertRequest
block|;
name|id
name|monitor
block|;
name|bool
name|m_drawContentBorderGradient
block|;
name|int
name|m_topContentBorderThickness
block|;
name|int
name|m_bottomContentBorderThickness
block|;
comment|// used by showFullScreen in fake mode
name|QRect
name|m_normalGeometry
block|;
name|Qt
operator|::
name|WindowFlags
name|m_oldWindowFlags
block|;
name|NSApplicationPresentationOptions
name|m_presentationOptions
block|;      struct
name|BorderRange
block|{
name|BorderRange
argument_list|(
argument|quintptr i
argument_list|,
argument|int u
argument_list|,
argument|int l
argument_list|)
operator|:
name|identifier
argument_list|(
name|i
argument_list|)
block|,
name|upper
argument_list|(
name|u
argument_list|)
block|,
name|lower
argument_list|(
argument|l
argument_list|)
block|{ }
name|quintptr
name|identifier
block|;
name|int
name|upper
block|;
name|int
name|lower
block|;
name|bool
name|operator
operator|<
operator|(
name|BorderRange
specifier|const
operator|&
name|right
operator|)
specifier|const
block|{
return|return
name|upper
operator|<
name|right
operator|.
name|upper
return|;
block|}
expr|}
block|;
name|QHash
operator|<
name|quintptr
block|,
name|BorderRange
operator|>
name|m_contentBorderAreas
block|;
comment|// identifer -> uppper/lower
name|QHash
operator|<
name|quintptr
block|,
name|bool
operator|>
name|m_enabledContentBorderAreas
block|;
comment|// identifer -> enabled state (true/false)
block|}
block|;
name|QT_END_NAMESPACE
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QCOCOAWINDOW_H
end_comment
end_unit
