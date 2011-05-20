begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** No Commercial Usage ** This file contains pre-release code and may not be distributed. ** You may use this file in accordance with the terms and conditions ** contained in the Technology Preview License Agreement accompanying ** this package. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights.  These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** If you have questions regarding the use of this file, please contact ** Nokia at qt-info@nokia.com. ** ** ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QGUIAPPLICATION_QPA_P_H
end_ifndef
begin_define
DECL|macro|QGUIAPPLICATION_QPA_P_H
define|#
directive|define
name|QGUIAPPLICATION_QPA_P_H
end_define
begin_include
include|#
directive|include
file|<QtGui/qguiapplication.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/private/qcoreapplication_p.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/private/qthread_p.h>
end_include
begin_include
include|#
directive|include
file|<QWindowSystemInterface>
end_include
begin_include
include|#
directive|include
file|"private/qwindowsysteminterface_qpa_p.h"
end_include
begin_include
include|#
directive|include
file|"QtGui/qplatformintegration_qpa.h"
end_include
begin_decl_stmt
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
name|QT_MODULE
argument_list|(
name|Gui
argument_list|)
name|class
name|QPlatformIntegration
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_GUI_EXPORT
name|QGuiApplicationPrivate
range|:
name|public
name|QCoreApplicationPrivate
block|{
name|Q_DECLARE_PUBLIC
argument_list|(
argument|QGuiApplication
argument_list|)
name|public
operator|:
name|QGuiApplicationPrivate
argument_list|(
argument|int&argc
argument_list|,
argument|char **argv
argument_list|,
argument|int flags
argument_list|)
block|;
operator|~
name|QGuiApplicationPrivate
argument_list|()
block|;
name|void
name|createEventDispatcher
argument_list|()
block|;
name|virtual
name|void
name|notifyLayoutDirectionChange
argument_list|()
block|;
specifier|static
name|int
name|keyboard_input_time
block|;
specifier|static
name|int
name|mouse_double_click_time
block|;
specifier|static
name|Qt
operator|::
name|KeyboardModifiers
name|modifier_buttons
block|;
specifier|static
name|Qt
operator|::
name|MouseButtons
name|mouse_buttons
block|;
specifier|static
name|QPlatformIntegration
operator|*
name|platform_integration
block|;
specifier|static
name|QPlatformIntegration
operator|*
name|platformIntegration
argument_list|()
block|{
return|return
name|platform_integration
return|;
block|}
expr|enum
name|KeyPlatform
block|{
name|KB_Win
operator|=
literal|1
block|,
name|KB_Mac
operator|=
literal|2
block|,
name|KB_X11
operator|=
literal|4
block|,
name|KB_KDE
operator|=
literal|8
block|,
name|KB_Gnome
operator|=
literal|16
block|,
name|KB_CDE
operator|=
literal|32
block|,
name|KB_S60
operator|=
literal|64
block|,
name|KB_All
operator|=
literal|0xffff
block|}
block|;
specifier|static
name|uint
name|currentKeyPlatform
argument_list|()
block|;
specifier|static
name|QAbstractEventDispatcher
operator|*
name|qt_qpa_core_dispatcher
argument_list|()
block|{
return|return
name|QCoreApplication
operator|::
name|instance
argument_list|()
operator|->
name|d_func
argument_list|()
operator|->
name|threadData
operator|->
name|eventDispatcher
return|;
block|}
specifier|static
name|void
name|processMouseEvent
argument_list|(
name|QWindowSystemInterfacePrivate
operator|::
name|MouseEvent
operator|*
name|e
argument_list|)
block|;
specifier|static
name|void
name|processKeyEvent
argument_list|(
name|QWindowSystemInterfacePrivate
operator|::
name|KeyEvent
operator|*
name|e
argument_list|)
block|;
specifier|static
name|void
name|processWheelEvent
argument_list|(
name|QWindowSystemInterfacePrivate
operator|::
name|WheelEvent
operator|*
name|e
argument_list|)
block|;
specifier|static
name|void
name|processTouchEvent
argument_list|(
name|QWindowSystemInterfacePrivate
operator|::
name|TouchEvent
operator|*
name|e
argument_list|)
block|;
specifier|static
name|void
name|processCloseEvent
argument_list|(
name|QWindowSystemInterfacePrivate
operator|::
name|CloseEvent
operator|*
name|e
argument_list|)
block|;
specifier|static
name|void
name|processGeometryChangeEvent
argument_list|(
name|QWindowSystemInterfacePrivate
operator|::
name|GeometryChangeEvent
operator|*
name|e
argument_list|)
block|;
specifier|static
name|void
name|processEnterEvent
argument_list|(
name|QWindowSystemInterfacePrivate
operator|::
name|EnterEvent
operator|*
name|e
argument_list|)
block|;
specifier|static
name|void
name|processLeaveEvent
argument_list|(
name|QWindowSystemInterfacePrivate
operator|::
name|LeaveEvent
operator|*
name|e
argument_list|)
block|;
specifier|static
name|void
name|processActivatedEvent
argument_list|(
name|QWindowSystemInterfacePrivate
operator|::
name|ActivatedWindowEvent
operator|*
name|e
argument_list|)
block|;
specifier|static
name|void
name|processWindowSystemEvent
argument_list|(
name|QWindowSystemInterfacePrivate
operator|::
name|WindowSystemEvent
operator|*
name|e
argument_list|)
block|;
specifier|static
name|void
name|reportScreenCount
argument_list|(
name|QWindowSystemInterfacePrivate
operator|::
name|ScreenCountEvent
operator|*
name|e
argument_list|)
block|;
specifier|static
name|void
name|reportGeometryChange
argument_list|(
name|QWindowSystemInterfacePrivate
operator|::
name|ScreenGeometryEvent
operator|*
name|e
argument_list|)
block|;
specifier|static
name|void
name|reportAvailableGeometryChange
argument_list|(
name|QWindowSystemInterfacePrivate
operator|::
name|ScreenAvailableGeometryEvent
operator|*
name|e
argument_list|)
block|;
specifier|static
specifier|inline
name|Qt
operator|::
name|Alignment
name|visualAlignment
argument_list|(
argument|Qt::LayoutDirection direction
argument_list|,
argument|Qt::Alignment alignment
argument_list|)
block|{
if|if
condition|(
operator|!
operator|(
name|alignment
operator|&
name|Qt
operator|::
name|AlignHorizontal_Mask
operator|)
condition|)
name|alignment
operator||=
name|Qt
operator|::
name|AlignLeft
expr_stmt|;
if|if
condition|(
operator|(
name|alignment
operator|&
name|Qt
operator|::
name|AlignAbsolute
operator|)
operator|==
literal|0
operator|&&
operator|(
name|alignment
operator|&
operator|(
name|Qt
operator|::
name|AlignLeft
operator||
name|Qt
operator|::
name|AlignRight
operator|)
operator|)
condition|)
block|{
if|if
condition|(
name|direction
operator|==
name|Qt
operator|::
name|RightToLeft
condition|)
name|alignment
operator|^=
operator|(
name|Qt
operator|::
name|AlignLeft
operator||
name|Qt
operator|::
name|AlignRight
operator|)
expr_stmt|;
name|alignment
operator||=
name|Qt
operator|::
name|AlignAbsolute
expr_stmt|;
block|}
return|return
name|alignment
return|;
block|}
end_decl_stmt
begin_decl_stmt
name|QPixmap
name|getPixmapCursor
argument_list|(
name|Qt
operator|::
name|CursorShape
name|cshape
argument_list|)
decl_stmt|;
end_decl_stmt
begin_function
specifier|static
name|QGuiApplicationPrivate
modifier|*
name|instance
parameter_list|()
block|{
return|return
name|self
return|;
block|}
end_function
begin_decl_stmt
specifier|static
name|bool
name|app_do_modal
decl_stmt|;
end_decl_stmt
begin_expr_stmt
specifier|static
name|Qt
operator|::
name|MouseButtons
name|buttons
expr_stmt|;
end_expr_stmt
begin_decl_stmt
specifier|static
name|ulong
name|mousePressTime
decl_stmt|;
end_decl_stmt
begin_expr_stmt
specifier|static
name|Qt
operator|::
name|MouseButton
name|mousePressButton
expr_stmt|;
end_expr_stmt
begin_decl_stmt
specifier|static
name|int
name|mousePressX
decl_stmt|;
end_decl_stmt
begin_decl_stmt
specifier|static
name|int
name|mousePressY
decl_stmt|;
end_decl_stmt
begin_decl_stmt
specifier|static
name|int
name|mouse_double_click_distance
decl_stmt|;
end_decl_stmt
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_CLIPBOARD
end_ifndef
begin_decl_stmt
specifier|static
name|QClipboard
modifier|*
name|qt_clipboard
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_decl_stmt
specifier|static
name|QPalette
modifier|*
name|app_pal
decl_stmt|;
end_decl_stmt
begin_decl_stmt
specifier|static
name|QWindowList
name|window_list
decl_stmt|;
end_decl_stmt
begin_decl_stmt
specifier|static
name|QWindow
modifier|*
name|active_window
decl_stmt|;
end_decl_stmt
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_CURSOR
end_ifndef
begin_expr_stmt
name|QList
operator|<
name|QCursor
operator|>
name|cursor_list
expr_stmt|;
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_decl_stmt
specifier|static
name|QFont
modifier|*
name|app_font
decl_stmt|;
end_decl_stmt
begin_label
name|private
label|:
end_label
begin_function_decl
name|void
name|init
parameter_list|()
function_decl|;
end_function_decl
begin_decl_stmt
specifier|static
name|QGuiApplicationPrivate
modifier|*
name|self
decl_stmt|;
end_decl_stmt
begin_expr_stmt
unit|};
name|QT_END_NAMESPACE
name|QT_END_HEADER
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QGUIAPPLICATION_QPA_P_H
end_comment
end_unit
