begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtWidgets module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qlabel.h"
end_include
begin_include
include|#
directive|include
file|"qpainter.h"
end_include
begin_include
include|#
directive|include
file|"qpixmap.h"
end_include
begin_include
include|#
directive|include
file|"qbitmap.h"
end_include
begin_include
include|#
directive|include
file|"qevent.h"
end_include
begin_include
include|#
directive|include
file|"qapplication.h"
end_include
begin_include
include|#
directive|include
file|"qlist.h"
end_include
begin_include
include|#
directive|include
file|"qmenu.h"
end_include
begin_include
include|#
directive|include
file|"qtimer.h"
end_include
begin_include
include|#
directive|include
file|"qsystemtrayicon_p.h"
end_include
begin_include
include|#
directive|include
file|"qpaintengine.h"
end_include
begin_include
include|#
directive|include
file|<qwindow.h>
end_include
begin_include
include|#
directive|include
file|<qguiapplication.h>
end_include
begin_include
include|#
directive|include
file|<qscreen.h>
end_include
begin_include
include|#
directive|include
file|<qbackingstore.h>
end_include
begin_include
include|#
directive|include
file|<qpa/qplatformnativeinterface.h>
end_include
begin_include
include|#
directive|include
file|<qdebug.h>
end_include
begin_include
include|#
directive|include
file|<X11/Xlib.h>
end_include
begin_include
include|#
directive|include
file|<X11/Xutil.h>
end_include
begin_include
include|#
directive|include
file|<X11/Xos.h>
end_include
begin_include
include|#
directive|include
file|<X11/Xatom.h>
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_SYSTEMTRAYICON
end_ifndef
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
name|enum
type|{
DECL|enumerator|SYSTEM_TRAY_REQUEST_DOCK
name|SYSTEM_TRAY_REQUEST_DOCK
init|=
literal|0
decl_stmt|,
DECL|enumerator|SYSTEM_TRAY_BEGIN_MESSAGE
name|SYSTEM_TRAY_BEGIN_MESSAGE
init|=
literal|1
decl_stmt|,
DECL|enumerator|SYSTEM_TRAY_CANCEL_MESSAGE
name|SYSTEM_TRAY_CANCEL_MESSAGE
init|=
literal|2
end_decl_stmt
begin_comment
unit|};
comment|// ### fixme (15.3.2012): The following issues need to be resolved:
end_comment
begin_comment
comment|// - Tracking of the actual tray window for DestroyNotify and re-creation
end_comment
begin_comment
comment|//   of the icons on the new window should it change (see Qt 4.X).
end_comment
begin_comment
comment|// Global context for the X11 system tray containing a display for the primary
end_comment
begin_comment
comment|// screen and a selection atom from which the tray window can be determined.
end_comment
begin_class
DECL|class|QX11SystemTrayContext
class|class
name|QX11SystemTrayContext
block|{
public|public:
name|QX11SystemTrayContext
parameter_list|()
constructor_decl|;
name|~
name|QX11SystemTrayContext
parameter_list|()
destructor_decl|;
DECL|function|isValid
name|bool
name|isValid
parameter_list|()
specifier|const
block|{
return|return
name|m_systemTraySelection
operator|!=
literal|0
return|;
block|}
DECL|function|display
specifier|inline
name|Display
modifier|*
name|display
parameter_list|()
specifier|const
block|{
return|return
name|m_display
return|;
block|}
DECL|function|screenNumber
specifier|inline
name|int
name|screenNumber
parameter_list|()
specifier|const
block|{
return|return
name|m_screenNumber
return|;
block|}
name|Window
name|locateSystemTray
parameter_list|()
specifier|const
function_decl|;
private|private:
DECL|member|m_display
name|Display
modifier|*
name|m_display
decl_stmt|;
DECL|member|m_screenNumber
name|int
name|m_screenNumber
decl_stmt|;
DECL|member|m_systemTraySelection
name|Atom
name|m_systemTraySelection
decl_stmt|;
block|}
class|;
end_class
begin_constructor
DECL|function|QX11SystemTrayContext
name|QX11SystemTrayContext
operator|::
name|QX11SystemTrayContext
parameter_list|()
member_init_list|:
name|m_display
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|m_screenNumber
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|m_systemTraySelection
argument_list|(
literal|0
argument_list|)
block|{
name|QScreen
modifier|*
name|screen
init|=
name|QGuiApplication
operator|::
name|primaryScreen
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
name|screen
condition|)
block|{
name|qWarning
argument_list|(
literal|"%s: No screen."
argument_list|,
name|Q_FUNC_INFO
argument_list|)
expr_stmt|;
return|return;
block|}
name|void
modifier|*
name|displayV
init|=
name|QGuiApplication
operator|::
name|platformNativeInterface
argument_list|()
operator|->
name|nativeResourceForScreen
argument_list|(
name|QByteArrayLiteral
argument_list|(
literal|"display"
argument_list|)
argument_list|,
name|screen
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|displayV
condition|)
block|{
name|qWarning
argument_list|(
literal|"%s: Unable to obtain X11 display of primary screen."
argument_list|,
name|Q_FUNC_INFO
argument_list|)
expr_stmt|;
return|return;
block|}
name|m_display
operator|=
cast|static_cast
argument_list|<
name|Display
operator|*
argument_list|>
argument_list|(
name|displayV
argument_list|)
expr_stmt|;
specifier|const
name|QByteArray
name|netSysTray
init|=
literal|"_NET_SYSTEM_TRAY_S"
operator|+
name|QByteArray
operator|::
name|number
argument_list|(
name|m_screenNumber
argument_list|)
decl_stmt|;
name|m_systemTraySelection
operator|=
name|XInternAtom
argument_list|(
name|m_display
argument_list|,
name|netSysTray
operator|.
name|constData
argument_list|()
argument_list|,
name|False
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|m_systemTraySelection
condition|)
block|{
name|qWarning
argument_list|(
literal|"%s: Unable to retrieve atom '%s'."
argument_list|,
name|Q_FUNC_INFO
argument_list|,
name|netSysTray
operator|.
name|constData
argument_list|()
argument_list|)
expr_stmt|;
return|return;
block|}
block|}
end_constructor
begin_function
DECL|function|locateSystemTray
name|Window
name|QX11SystemTrayContext
operator|::
name|locateSystemTray
parameter_list|()
specifier|const
block|{
if|if
condition|(
name|isValid
argument_list|()
condition|)
return|return
name|XGetSelectionOwner
argument_list|(
name|m_display
argument_list|,
name|m_systemTraySelection
argument_list|)
return|;
return|return
literal|0
return|;
block|}
end_function
begin_destructor
DECL|function|~QX11SystemTrayContext
name|QX11SystemTrayContext
operator|::
name|~
name|QX11SystemTrayContext
parameter_list|()
block|{ }
end_destructor
begin_macro
name|Q_GLOBAL_STATIC
argument_list|(
argument|QX11SystemTrayContext
argument_list|,
argument|qX11SystemTrayContext
argument_list|)
end_macro
begin_comment
comment|// System tray widget. Could be replaced by a QWindow with
end_comment
begin_comment
comment|// a backing store if it did not need tooltip handling.
end_comment
begin_class
DECL|class|QSystemTrayIconSys
class|class
name|QSystemTrayIconSys
super|:
specifier|public
name|QWidget
block|{
public|public:
specifier|explicit
name|QSystemTrayIconSys
parameter_list|(
name|QSystemTrayIcon
modifier|*
name|q
parameter_list|)
constructor_decl|;
DECL|function|updateIcon
specifier|inline
name|void
name|updateIcon
parameter_list|()
block|{
name|update
argument_list|()
expr_stmt|;
block|}
DECL|function|systemTrayIcon
specifier|inline
name|QSystemTrayIcon
modifier|*
name|systemTrayIcon
parameter_list|()
specifier|const
block|{
return|return
name|q
return|;
block|}
name|QRect
name|globalGeometry
parameter_list|()
specifier|const
function_decl|;
protected|protected:
specifier|virtual
name|void
name|mousePressEvent
parameter_list|(
name|QMouseEvent
modifier|*
name|ev
parameter_list|)
function_decl|;
specifier|virtual
name|void
name|mouseDoubleClickEvent
parameter_list|(
name|QMouseEvent
modifier|*
name|ev
parameter_list|)
function_decl|;
specifier|virtual
name|bool
name|event
parameter_list|(
name|QEvent
modifier|*
parameter_list|)
function_decl|;
specifier|virtual
name|void
name|paintEvent
parameter_list|(
name|QPaintEvent
modifier|*
parameter_list|)
function_decl|;
private|private:
DECL|member|q
name|QSystemTrayIcon
modifier|*
name|q
decl_stmt|;
block|}
class|;
end_class
begin_constructor
DECL|function|QSystemTrayIconSys
name|QSystemTrayIconSys
operator|::
name|QSystemTrayIconSys
parameter_list|(
name|QSystemTrayIcon
modifier|*
name|qIn
parameter_list|)
member_init_list|:
name|QWidget
argument_list|(
literal|0
argument_list|,
name|Qt
operator|::
name|Window
operator||
name|Qt
operator|::
name|FramelessWindowHint
operator||
name|Qt
operator|::
name|BypassWindowManagerHint
argument_list|)
member_init_list|,
name|q
argument_list|(
name|qIn
argument_list|)
block|{
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"QSystemTrayIconSys"
argument_list|)
argument_list|)
expr_stmt|;
name|setToolTip
argument_list|(
name|q
operator|->
name|toolTip
argument_list|()
argument_list|)
expr_stmt|;
name|QX11SystemTrayContext
modifier|*
name|context
init|=
name|qX11SystemTrayContext
argument_list|()
decl_stmt|;
name|Q_ASSERT
argument_list|(
name|context
operator|->
name|isValid
argument_list|()
argument_list|)
expr_stmt|;
name|setAttribute
argument_list|(
name|Qt
operator|::
name|WA_AlwaysShowToolTips
argument_list|,
literal|true
argument_list|)
expr_stmt|;
name|setAttribute
argument_list|(
name|Qt
operator|::
name|WA_TranslucentBackground
argument_list|,
literal|true
argument_list|)
expr_stmt|;
name|setAttribute
argument_list|(
name|Qt
operator|::
name|WA_QuitOnClose
argument_list|,
literal|false
argument_list|)
expr_stmt|;
specifier|const
name|QSize
name|size
argument_list|(
literal|22
argument_list|,
literal|22
argument_list|)
decl_stmt|;
comment|// Gnome, standard size
name|setGeometry
argument_list|(
name|QRect
argument_list|(
name|QPoint
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
argument_list|,
name|size
argument_list|)
argument_list|)
expr_stmt|;
name|setMinimumSize
argument_list|(
name|size
argument_list|)
expr_stmt|;
name|createWinId
argument_list|()
expr_stmt|;
name|setMouseTracking
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|Display
modifier|*
name|display
init|=
name|context
operator|->
name|display
argument_list|()
decl_stmt|;
comment|// Request to be a tray window according to GNOME, NET WM Specification
specifier|static
name|Atom
name|netwm_tray_atom
init|=
name|XInternAtom
argument_list|(
name|display
argument_list|,
literal|"_NET_SYSTEM_TRAY_OPCODE"
argument_list|,
name|False
argument_list|)
decl_stmt|;
name|long
name|l
index|[
literal|5
index|]
init|=
block|{
name|CurrentTime
block|,
name|SYSTEM_TRAY_REQUEST_DOCK
block|,
cast|static_cast
argument_list|<
name|long
argument_list|>
argument_list|(
name|winId
argument_list|()
argument_list|)
block|,
literal|0
block|,
literal|0
block|}
decl_stmt|;
name|XEvent
name|ev
decl_stmt|;
name|memset
argument_list|(
operator|&
name|ev
argument_list|,
literal|0
argument_list|,
sizeof|sizeof
argument_list|(
name|ev
argument_list|)
argument_list|)
expr_stmt|;
name|ev
operator|.
name|xclient
operator|.
name|type
operator|=
name|ClientMessage
expr_stmt|;
name|ev
operator|.
name|xclient
operator|.
name|window
operator|=
name|context
operator|->
name|locateSystemTray
argument_list|()
expr_stmt|;
name|ev
operator|.
name|xclient
operator|.
name|message_type
operator|=
name|netwm_tray_atom
expr_stmt|;
name|ev
operator|.
name|xclient
operator|.
name|format
operator|=
literal|32
expr_stmt|;
name|memcpy
argument_list|(
operator|(
name|char
operator|*
operator|)
operator|&
name|ev
operator|.
name|xclient
operator|.
name|data
argument_list|,
operator|(
specifier|const
name|char
operator|*
operator|)
name|l
argument_list|,
sizeof|sizeof
argument_list|(
name|l
argument_list|)
argument_list|)
expr_stmt|;
name|XSendEvent
argument_list|(
name|display
argument_list|,
name|ev
operator|.
name|xclient
operator|.
name|window
argument_list|,
name|False
argument_list|,
literal|0
argument_list|,
operator|&
name|ev
argument_list|)
expr_stmt|;
name|show
argument_list|()
expr_stmt|;
block|}
end_constructor
begin_function
DECL|function|globalGeometry
name|QRect
name|QSystemTrayIconSys
operator|::
name|globalGeometry
parameter_list|()
specifier|const
block|{
name|QX11SystemTrayContext
modifier|*
name|context
init|=
name|qX11SystemTrayContext
argument_list|()
decl_stmt|;
operator|::
name|Window
name|dummy
decl_stmt|;
name|int
name|x
decl_stmt|,
name|y
decl_stmt|,
name|rootX
decl_stmt|,
name|rootY
decl_stmt|;
name|unsigned
name|int
name|width
decl_stmt|,
name|height
decl_stmt|,
name|border
decl_stmt|,
name|depth
decl_stmt|;
comment|// Use X11 API since we are parented on the tray, about which the QWindow does not know.
name|XGetGeometry
argument_list|(
name|context
operator|->
name|display
argument_list|()
argument_list|,
name|winId
argument_list|()
argument_list|,
operator|&
name|dummy
argument_list|,
operator|&
name|x
argument_list|,
operator|&
name|y
argument_list|,
operator|&
name|width
argument_list|,
operator|&
name|height
argument_list|,
operator|&
name|border
argument_list|,
operator|&
name|depth
argument_list|)
expr_stmt|;
name|XTranslateCoordinates
argument_list|(
name|context
operator|->
name|display
argument_list|()
argument_list|,
name|winId
argument_list|()
argument_list|,
name|XRootWindow
argument_list|(
name|context
operator|->
name|display
argument_list|()
argument_list|,
name|context
operator|->
name|screenNumber
argument_list|()
argument_list|)
argument_list|,
name|x
argument_list|,
name|y
argument_list|,
operator|&
name|rootX
argument_list|,
operator|&
name|rootY
argument_list|,
operator|&
name|dummy
argument_list|)
expr_stmt|;
return|return
name|QRect
argument_list|(
name|QPoint
argument_list|(
name|rootX
argument_list|,
name|rootY
argument_list|)
argument_list|,
name|QSize
argument_list|(
name|width
argument_list|,
name|height
argument_list|)
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|mousePressEvent
name|void
name|QSystemTrayIconSys
operator|::
name|mousePressEvent
parameter_list|(
name|QMouseEvent
modifier|*
name|ev
parameter_list|)
block|{
name|QPoint
name|globalPos
init|=
name|ev
operator|->
name|globalPos
argument_list|()
decl_stmt|;
ifndef|#
directive|ifndef
name|QT_NO_CONTEXTMENU
if|if
condition|(
name|ev
operator|->
name|button
argument_list|()
operator|==
name|Qt
operator|::
name|RightButton
operator|&&
name|q
operator|->
name|contextMenu
argument_list|()
condition|)
name|q
operator|->
name|contextMenu
argument_list|()
operator|->
name|popup
argument_list|(
name|globalPos
argument_list|)
expr_stmt|;
endif|#
directive|endif
if|if
condition|(
name|QBalloonTip
operator|::
name|isBalloonVisible
argument_list|()
condition|)
block|{
emit|emit
name|q
operator|->
name|messageClicked
argument_list|()
emit|;
name|QBalloonTip
operator|::
name|hideBalloon
argument_list|()
expr_stmt|;
block|}
if|if
condition|(
name|ev
operator|->
name|button
argument_list|()
operator|==
name|Qt
operator|::
name|LeftButton
condition|)
emit|emit
name|q
operator|->
name|activated
argument_list|(
name|QSystemTrayIcon
operator|::
name|Trigger
argument_list|)
emit|;
elseif|else
if|if
condition|(
name|ev
operator|->
name|button
argument_list|()
operator|==
name|Qt
operator|::
name|RightButton
condition|)
emit|emit
name|q
operator|->
name|activated
argument_list|(
name|QSystemTrayIcon
operator|::
name|Context
argument_list|)
emit|;
elseif|else
if|if
condition|(
name|ev
operator|->
name|button
argument_list|()
operator|==
name|Qt
operator|::
name|MidButton
condition|)
emit|emit
name|q
operator|->
name|activated
argument_list|(
name|QSystemTrayIcon
operator|::
name|MiddleClick
argument_list|)
emit|;
block|}
end_function
begin_function
DECL|function|mouseDoubleClickEvent
name|void
name|QSystemTrayIconSys
operator|::
name|mouseDoubleClickEvent
parameter_list|(
name|QMouseEvent
modifier|*
name|ev
parameter_list|)
block|{
if|if
condition|(
name|ev
operator|->
name|button
argument_list|()
operator|==
name|Qt
operator|::
name|LeftButton
condition|)
emit|emit
name|q
operator|->
name|activated
argument_list|(
name|QSystemTrayIcon
operator|::
name|DoubleClick
argument_list|)
emit|;
block|}
end_function
begin_function
DECL|function|event
name|bool
name|QSystemTrayIconSys
operator|::
name|event
parameter_list|(
name|QEvent
modifier|*
name|e
parameter_list|)
block|{
switch|switch
condition|(
name|e
operator|->
name|type
argument_list|()
condition|)
block|{
ifndef|#
directive|ifndef
name|QT_NO_WHEELEVENT
case|case
name|QEvent
operator|::
name|Wheel
case|:
return|return
name|QApplication
operator|::
name|sendEvent
argument_list|(
name|q
argument_list|,
name|e
argument_list|)
return|;
endif|#
directive|endif
default|default:
break|break;
block|}
return|return
name|QWidget
operator|::
name|event
argument_list|(
name|e
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|paintEvent
name|void
name|QSystemTrayIconSys
operator|::
name|paintEvent
parameter_list|(
name|QPaintEvent
modifier|*
parameter_list|)
block|{
comment|// Note: Transparent pixels require a particular Visual which XCB
comment|// currently does not support yet.
specifier|const
name|QRect
name|rect
argument_list|(
name|QPoint
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
argument_list|,
name|geometry
argument_list|()
operator|.
name|size
argument_list|()
argument_list|)
decl_stmt|;
name|QPainter
name|painter
argument_list|(
name|this
argument_list|)
decl_stmt|;
name|painter
operator|.
name|setCompositionMode
argument_list|(
name|QPainter
operator|::
name|CompositionMode_Source
argument_list|)
expr_stmt|;
name|painter
operator|.
name|fillRect
argument_list|(
name|rect
argument_list|,
name|Qt
operator|::
name|transparent
argument_list|)
expr_stmt|;
name|painter
operator|.
name|setCompositionMode
argument_list|(
name|QPainter
operator|::
name|CompositionMode_SourceOver
argument_list|)
expr_stmt|;
name|q
operator|->
name|icon
argument_list|()
operator|.
name|paint
argument_list|(
operator|&
name|painter
argument_list|,
name|rect
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|////////////////////////////////////////////////////////////////////////////
end_comment
begin_constructor
DECL|function|QSystemTrayIconPrivate
name|QSystemTrayIconPrivate
operator|::
name|QSystemTrayIconPrivate
parameter_list|()
member_init_list|:
name|sys
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|visible
argument_list|(
literal|false
argument_list|)
block|{ }
end_constructor
begin_destructor
DECL|function|~QSystemTrayIconPrivate
name|QSystemTrayIconPrivate
operator|::
name|~
name|QSystemTrayIconPrivate
parameter_list|()
block|{ }
end_destructor
begin_function
DECL|function|install_sys
name|void
name|QSystemTrayIconPrivate
operator|::
name|install_sys
parameter_list|()
block|{
name|Q_Q
argument_list|(
name|QSystemTrayIcon
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|sys
operator|&&
name|qX11SystemTrayContext
argument_list|()
operator|->
name|isValid
argument_list|()
condition|)
name|sys
operator|=
operator|new
name|QSystemTrayIconSys
argument_list|(
name|q
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|geometry_sys
name|QRect
name|QSystemTrayIconPrivate
operator|::
name|geometry_sys
parameter_list|()
specifier|const
block|{
if|if
condition|(
operator|!
name|sys
condition|)
return|return
name|QRect
argument_list|()
return|;
return|return
name|sys
operator|->
name|globalGeometry
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|remove_sys
name|void
name|QSystemTrayIconPrivate
operator|::
name|remove_sys
parameter_list|()
block|{
if|if
condition|(
operator|!
name|sys
condition|)
return|return;
name|QBalloonTip
operator|::
name|hideBalloon
argument_list|()
expr_stmt|;
name|sys
operator|->
name|hide
argument_list|()
expr_stmt|;
comment|// this should do the trick, but...
operator|delete
name|sys
expr_stmt|;
comment|// wm may resize system tray only for DestroyEvents
name|sys
operator|=
literal|0
expr_stmt|;
block|}
end_function
begin_function
DECL|function|updateIcon_sys
name|void
name|QSystemTrayIconPrivate
operator|::
name|updateIcon_sys
parameter_list|()
block|{
if|if
condition|(
name|sys
condition|)
name|sys
operator|->
name|updateIcon
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|updateMenu_sys
name|void
name|QSystemTrayIconPrivate
operator|::
name|updateMenu_sys
parameter_list|()
block|{  }
end_function
begin_function
DECL|function|updateToolTip_sys
name|void
name|QSystemTrayIconPrivate
operator|::
name|updateToolTip_sys
parameter_list|()
block|{
if|if
condition|(
operator|!
name|sys
condition|)
return|return;
ifndef|#
directive|ifndef
name|QT_NO_TOOLTIP
name|sys
operator|->
name|setToolTip
argument_list|(
name|toolTip
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
end_function
begin_function
DECL|function|isSystemTrayAvailable_sys
name|bool
name|QSystemTrayIconPrivate
operator|::
name|isSystemTrayAvailable_sys
parameter_list|()
block|{
specifier|const
name|QString
name|platform
init|=
name|QGuiApplication
operator|::
name|platformName
argument_list|()
decl_stmt|;
if|if
condition|(
name|platform
operator|.
name|compare
argument_list|(
name|QStringLiteral
argument_list|(
literal|"xcb"
argument_list|)
argument_list|,
name|Qt
operator|::
name|CaseInsensitive
argument_list|)
operator|==
literal|0
condition|)
return|return
name|qX11SystemTrayContext
argument_list|()
operator|->
name|locateSystemTray
argument_list|()
operator|!=
name|None
return|;
return|return
literal|false
return|;
block|}
end_function
begin_function
DECL|function|supportsMessages_sys
name|bool
name|QSystemTrayIconPrivate
operator|::
name|supportsMessages_sys
parameter_list|()
block|{
return|return
literal|true
return|;
block|}
end_function
begin_function
DECL|function|showMessage_sys
name|void
name|QSystemTrayIconPrivate
operator|::
name|showMessage_sys
parameter_list|(
specifier|const
name|QString
modifier|&
name|message
parameter_list|,
specifier|const
name|QString
modifier|&
name|title
parameter_list|,
name|QSystemTrayIcon
operator|::
name|MessageIcon
name|icon
parameter_list|,
name|int
name|msecs
parameter_list|)
block|{
if|if
condition|(
operator|!
name|sys
condition|)
return|return;
specifier|const
name|QPoint
name|g
init|=
name|sys
operator|->
name|globalGeometry
argument_list|()
operator|.
name|topLeft
argument_list|()
decl_stmt|;
name|QBalloonTip
operator|::
name|showBalloon
argument_list|(
name|icon
argument_list|,
name|message
argument_list|,
name|title
argument_list|,
name|sys
operator|->
name|systemTrayIcon
argument_list|()
argument_list|,
name|QPoint
argument_list|(
name|g
operator|.
name|x
argument_list|()
operator|+
name|sys
operator|->
name|width
argument_list|()
operator|/
literal|2
argument_list|,
name|g
operator|.
name|y
argument_list|()
operator|+
name|sys
operator|->
name|height
argument_list|()
operator|/
literal|2
argument_list|)
argument_list|,
name|msecs
argument_list|)
expr_stmt|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|//QT_NO_SYSTEMTRAYICON
end_comment
end_unit
