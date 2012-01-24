begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qsystemtrayicon_p.h"
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_SYSTEMTRAYICON
end_ifndef
begin_define
DECL|macro|_WIN32_IE
define|#
directive|define
name|_WIN32_IE
value|0x0600
end_define
begin_comment
DECL|macro|_WIN32_IE
comment|//required for NOTIFYICONDATA_V2_SIZE
end_comment
begin_include
include|#
directive|include
file|<qt_windows.h>
end_include
begin_include
include|#
directive|include
file|<shlwapi.h>
end_include
begin_include
include|#
directive|include
file|<QApplication>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|q_uNOTIFYICONID
specifier|static
specifier|const
name|UINT
name|q_uNOTIFYICONID
init|=
literal|13
decl_stmt|;
end_decl_stmt
begin_comment
DECL|variable|q_uNOTIFYICONID
comment|// IDs from 0 to 12 are reserved on WinCE.
end_comment
begin_define
DECL|macro|MYWM_NOTIFYICON
define|#
directive|define
name|MYWM_NOTIFYICON
value|(WM_APP+101)
end_define
begin_struct
DECL|struct|Q_NOTIFYICONIDENTIFIER
struct|struct
name|Q_NOTIFYICONIDENTIFIER
block|{
DECL|member|cbSize
name|DWORD
name|cbSize
decl_stmt|;
DECL|member|hWnd
name|HWND
name|hWnd
decl_stmt|;
DECL|member|uID
name|UINT
name|uID
decl_stmt|;
DECL|member|guidItem
name|GUID
name|guidItem
decl_stmt|;
block|}
struct|;
end_struct
begin_class
DECL|class|QSystemTrayIconSys
class|class
name|QSystemTrayIconSys
super|:
name|QWidget
block|{
public|public:
name|QSystemTrayIconSys
parameter_list|(
name|QSystemTrayIcon
modifier|*
name|object
parameter_list|)
constructor_decl|;
name|~
name|QSystemTrayIconSys
parameter_list|()
destructor_decl|;
name|bool
name|winEvent
parameter_list|(
name|MSG
modifier|*
name|m
parameter_list|,
name|long
modifier|*
name|result
parameter_list|)
function_decl|;
name|bool
name|trayMessage
parameter_list|(
name|DWORD
name|msg
parameter_list|)
function_decl|;
name|void
name|setIconContents
parameter_list|(
name|NOTIFYICONDATA
modifier|&
name|data
parameter_list|)
function_decl|;
name|void
name|createIcon
parameter_list|()
function_decl|;
name|QRect
name|findTrayGeometry
parameter_list|()
function_decl|;
DECL|member|hIcon
name|HICON
name|hIcon
decl_stmt|;
DECL|member|globalPos
name|QPoint
name|globalPos
decl_stmt|;
DECL|member|q
name|QSystemTrayIcon
modifier|*
name|q
decl_stmt|;
private|private:
DECL|member|notifyIconSize
name|uint
name|notifyIconSize
decl_stmt|;
DECL|member|maxTipLength
name|int
name|maxTipLength
decl_stmt|;
DECL|member|ignoreNextMouseRelease
name|bool
name|ignoreNextMouseRelease
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
name|object
parameter_list|)
member_init_list|:
name|hIcon
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|q
argument_list|(
name|object
argument_list|)
member_init_list|,
name|ignoreNextMouseRelease
argument_list|(
literal|false
argument_list|)
block|{
name|notifyIconSize
operator|=
name|FIELD_OFFSET
argument_list|(
name|NOTIFYICONDATA
argument_list|,
name|szTip
index|[
literal|64
index|]
argument_list|)
expr_stmt|;
comment|// NOTIFYICONDATAW_V1_SIZE;
name|maxTipLength
operator|=
literal|64
expr_stmt|;
block|}
end_constructor
begin_destructor
DECL|function|~QSystemTrayIconSys
name|QSystemTrayIconSys
operator|::
name|~
name|QSystemTrayIconSys
parameter_list|()
block|{
if|if
condition|(
name|hIcon
condition|)
name|DestroyIcon
argument_list|(
name|hIcon
argument_list|)
expr_stmt|;
block|}
end_destructor
begin_function
DECL|function|findTrayGeometry
name|QRect
name|QSystemTrayIconSys
operator|::
name|findTrayGeometry
parameter_list|()
block|{
comment|// Use lower right corner as fallback
name|QPoint
name|brCorner
init|=
name|qApp
operator|->
name|desktop
argument_list|()
operator|->
name|screenGeometry
argument_list|()
operator|.
name|bottomRight
argument_list|()
decl_stmt|;
name|QRect
name|ret
argument_list|(
name|brCorner
operator|.
name|x
argument_list|()
operator|-
literal|10
argument_list|,
name|brCorner
operator|.
name|y
argument_list|()
operator|-
literal|10
argument_list|,
literal|10
argument_list|,
literal|10
argument_list|)
decl_stmt|;
return|return
name|ret
return|;
block|}
end_function
begin_function
DECL|function|setIconContents
name|void
name|QSystemTrayIconSys
operator|::
name|setIconContents
parameter_list|(
name|NOTIFYICONDATA
modifier|&
name|tnd
parameter_list|)
block|{
name|tnd
operator|.
name|uFlags
operator|=
name|NIF_MESSAGE
operator||
name|NIF_ICON
operator||
name|NIF_TIP
expr_stmt|;
name|tnd
operator|.
name|uCallbackMessage
operator|=
name|MYWM_NOTIFYICON
expr_stmt|;
name|tnd
operator|.
name|hIcon
operator|=
name|hIcon
expr_stmt|;
name|QString
name|tip
init|=
name|q
operator|->
name|toolTip
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
name|tip
operator|.
name|isNull
argument_list|()
condition|)
block|{
name|tip
operator|=
name|tip
operator|.
name|left
argument_list|(
name|maxTipLength
operator|-
literal|1
argument_list|)
operator|+
name|QChar
argument_list|()
expr_stmt|;
name|memcpy
argument_list|(
name|tnd
operator|.
name|szTip
argument_list|,
name|tip
operator|.
name|utf16
argument_list|()
argument_list|,
name|qMin
argument_list|(
name|tip
operator|.
name|length
argument_list|()
operator|+
literal|1
argument_list|,
name|maxTipLength
argument_list|)
operator|*
sizeof|sizeof
argument_list|(
name|wchar_t
argument_list|)
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|trayMessage
name|bool
name|QSystemTrayIconSys
operator|::
name|trayMessage
parameter_list|(
name|DWORD
name|msg
parameter_list|)
block|{
name|NOTIFYICONDATA
name|tnd
decl_stmt|;
name|memset
argument_list|(
operator|&
name|tnd
argument_list|,
literal|0
argument_list|,
name|notifyIconSize
argument_list|)
expr_stmt|;
name|tnd
operator|.
name|uID
operator|=
name|q_uNOTIFYICONID
expr_stmt|;
name|tnd
operator|.
name|cbSize
operator|=
name|notifyIconSize
expr_stmt|;
name|tnd
operator|.
name|hWnd
operator|=
name|winId
argument_list|()
expr_stmt|;
name|Q_ASSERT
argument_list|(
name|testAttribute
argument_list|(
name|Qt
operator|::
name|WA_WState_Created
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|msg
operator|!=
name|NIM_DELETE
condition|)
block|{
name|setIconContents
argument_list|(
name|tnd
argument_list|)
expr_stmt|;
block|}
return|return
name|Shell_NotifyIcon
argument_list|(
name|msg
argument_list|,
operator|&
name|tnd
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|createIcon
name|void
name|QSystemTrayIconSys
operator|::
name|createIcon
parameter_list|()
block|{
name|hIcon
operator|=
literal|0
expr_stmt|;
name|QIcon
name|icon
init|=
name|q
operator|->
name|icon
argument_list|()
decl_stmt|;
if|if
condition|(
name|icon
operator|.
name|isNull
argument_list|()
condition|)
return|return;
comment|//const QSize preferredSize(GetSystemMetrics(SM_CXSMICON) * 2, GetSystemMetrics(SM_CYSMICON) * 2);
specifier|const
name|QSize
name|preferredSize
argument_list|(
name|GetSystemMetrics
argument_list|(
name|SM_CXICON
argument_list|)
argument_list|,
name|GetSystemMetrics
argument_list|(
name|SM_CYICON
argument_list|)
argument_list|)
decl_stmt|;
name|QPixmap
name|pm
init|=
name|icon
operator|.
name|pixmap
argument_list|(
name|preferredSize
argument_list|)
decl_stmt|;
if|if
condition|(
name|pm
operator|.
name|isNull
argument_list|()
condition|)
return|return;
name|hIcon
operator|=
name|pm
operator|.
name|toWinHICON
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|winEvent
name|bool
name|QSystemTrayIconSys
operator|::
name|winEvent
parameter_list|(
name|MSG
modifier|*
name|m
parameter_list|,
name|long
modifier|*
name|result
parameter_list|)
block|{
switch|switch
condition|(
name|m
operator|->
name|message
condition|)
block|{
case|case
name|WM_CREATE
case|:
name|SetWindowLong
argument_list|(
name|winId
argument_list|()
argument_list|,
name|GWL_USERDATA
argument_list|,
call|(
name|LONG
call|)
argument_list|(
operator|(
name|CREATESTRUCTW
operator|*
operator|)
name|m
operator|->
name|lParam
argument_list|)
operator|->
name|lpCreateParams
argument_list|)
expr_stmt|;
break|break;
case|case
name|MYWM_NOTIFYICON
case|:
block|{
name|QPoint
name|gpos
init|=
name|QCursor
operator|::
name|pos
argument_list|()
decl_stmt|;
switch|switch
condition|(
name|m
operator|->
name|lParam
condition|)
block|{
case|case
name|WM_LBUTTONUP
case|:
if|if
condition|(
name|ignoreNextMouseRelease
condition|)
name|ignoreNextMouseRelease
operator|=
literal|false
expr_stmt|;
else|else
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
break|break;
case|case
name|WM_LBUTTONDBLCLK
case|:
name|ignoreNextMouseRelease
operator|=
literal|true
expr_stmt|;
comment|// Since DBLCLICK Generates a second mouse
comment|// release we must ignore it
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
break|break;
case|case
name|WM_RBUTTONUP
case|:
if|if
condition|(
name|q
operator|->
name|contextMenu
argument_list|()
condition|)
block|{
name|q
operator|->
name|contextMenu
argument_list|()
operator|->
name|popup
argument_list|(
name|gpos
argument_list|)
expr_stmt|;
comment|// We must ensure that the popup menu doesn't show up behind the task bar.
name|QRect
name|desktopRect
init|=
name|qApp
operator|->
name|desktop
argument_list|()
operator|->
name|availableGeometry
argument_list|()
decl_stmt|;
name|int
name|maxY
init|=
name|desktopRect
operator|.
name|y
argument_list|()
operator|+
name|desktopRect
operator|.
name|height
argument_list|()
operator|-
name|q
operator|->
name|contextMenu
argument_list|()
operator|->
name|height
argument_list|()
decl_stmt|;
if|if
condition|(
name|gpos
operator|.
name|y
argument_list|()
operator|>
name|maxY
condition|)
block|{
name|gpos
operator|.
name|ry
argument_list|()
operator|=
name|maxY
expr_stmt|;
name|q
operator|->
name|contextMenu
argument_list|()
operator|->
name|move
argument_list|(
name|gpos
argument_list|)
expr_stmt|;
block|}
block|}
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
break|break;
case|case
name|WM_MBUTTONUP
case|:
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
break|break;
default|default:
break|break;
block|}
break|break;
block|}
default|default:
return|return
name|QWidget
operator|::
name|winEvent
argument_list|(
name|m
argument_list|,
name|result
argument_list|)
return|;
block|}
return|return
literal|0
return|;
block|}
end_function
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
condition|)
block|{
name|sys
operator|=
operator|new
name|QSystemTrayIconSys
argument_list|(
name|q
argument_list|)
expr_stmt|;
name|sys
operator|->
name|createIcon
argument_list|()
expr_stmt|;
name|sys
operator|->
name|trayMessage
argument_list|(
name|NIM_ADD
argument_list|)
expr_stmt|;
block|}
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
name|title
parameter_list|,
specifier|const
name|QString
modifier|&
name|message
parameter_list|,
name|QSystemTrayIcon
operator|::
name|MessageIcon
name|type
parameter_list|,
name|int
name|timeOut
parameter_list|)
block|{
if|if
condition|(
operator|!
name|sys
condition|)
return|return;
name|uint
name|uSecs
init|=
literal|0
decl_stmt|;
if|if
condition|(
name|timeOut
operator|<
literal|0
condition|)
name|uSecs
operator|=
literal|10000
expr_stmt|;
comment|//10 sec default
else|else
name|uSecs
operator|=
operator|(
name|int
operator|)
name|timeOut
expr_stmt|;
comment|//message is limited to 255 chars + NULL
name|QString
name|messageString
decl_stmt|;
if|if
condition|(
name|message
operator|.
name|isEmpty
argument_list|()
operator|&&
operator|!
name|title
operator|.
name|isEmpty
argument_list|()
condition|)
name|messageString
operator|=
name|QLatin1Char
argument_list|(
literal|' '
argument_list|)
expr_stmt|;
comment|//ensures that the message shows when only title is set
else|else
name|messageString
operator|=
name|message
operator|.
name|left
argument_list|(
literal|255
argument_list|)
operator|+
name|QChar
argument_list|()
expr_stmt|;
comment|//title is limited to 63 chars + NULL
name|QString
name|titleString
init|=
name|title
operator|.
name|left
argument_list|(
literal|63
argument_list|)
operator|+
name|QChar
argument_list|()
decl_stmt|;
comment|//show QBalloonTip
name|QRect
name|trayRect
init|=
name|sys
operator|->
name|findTrayGeometry
argument_list|()
decl_stmt|;
name|QBalloonTip
operator|::
name|showBalloon
argument_list|(
name|type
argument_list|,
name|title
argument_list|,
name|message
argument_list|,
name|sys
operator|->
name|q
argument_list|,
name|QPoint
argument_list|(
name|trayRect
operator|.
name|left
argument_list|()
argument_list|,
name|trayRect
operator|.
name|center
argument_list|()
operator|.
name|y
argument_list|()
argument_list|)
argument_list|,
name|uSecs
argument_list|,
literal|false
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
return|return
name|QRect
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
name|sys
operator|->
name|trayMessage
argument_list|(
name|NIM_DELETE
argument_list|)
expr_stmt|;
operator|delete
name|sys
expr_stmt|;
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
operator|!
name|sys
condition|)
return|return;
name|HICON
name|hIconToDestroy
init|=
name|sys
operator|->
name|hIcon
decl_stmt|;
name|sys
operator|->
name|createIcon
argument_list|()
expr_stmt|;
name|sys
operator|->
name|trayMessage
argument_list|(
name|NIM_MODIFY
argument_list|)
expr_stmt|;
if|if
condition|(
name|hIconToDestroy
condition|)
name|DestroyIcon
argument_list|(
name|hIconToDestroy
argument_list|)
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
comment|// Calling sys->trayMessage(NIM_MODIFY) on an existing icon is broken on Windows CE.
comment|// So we need to call updateIcon_sys() which creates a new icon handle.
name|updateIcon_sys
argument_list|()
expr_stmt|;
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
return|return
literal|true
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
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
end_unit
