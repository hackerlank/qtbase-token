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
begin_ifndef
ifndef|#
directive|ifndef
name|_WIN32_WINNT
end_ifndef
begin_define
DECL|macro|_WIN32_WINNT
define|#
directive|define
name|_WIN32_WINNT
value|0x0600
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|_WIN32_IE
end_ifndef
begin_define
DECL|macro|_WIN32_IE
define|#
directive|define
name|_WIN32_IE
value|0x600
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_include
include|#
directive|include
file|<private/qsystemlibrary_p.h>
end_include
begin_include
include|#
directive|include
file|<private/qguiapplication_p.h>
end_include
begin_include
include|#
directive|include
file|<qpa/qplatformnativeinterface.h>
end_include
begin_include
include|#
directive|include
file|<QSettings>
end_include
begin_include
include|#
directive|include
file|<QDebug>
end_include
begin_include
include|#
directive|include
file|<QHash>
end_include
begin_include
include|#
directive|include
file|<qt_windows.h>
end_include
begin_include
include|#
directive|include
file|<commctrl.h>
end_include
begin_include
include|#
directive|include
file|<windowsx.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|q_uNOTIFYICONID
specifier|static
specifier|const
name|UINT
name|q_uNOTIFYICONID
init|=
literal|0
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|MYWM_TASKBARCREATED
specifier|static
name|uint
name|MYWM_TASKBARCREATED
init|=
literal|0
decl_stmt|;
end_decl_stmt
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
begin_ifdef
ifdef|#
directive|ifdef
name|Q_CC_MINGW
end_ifdef
begin_define
DECL|macro|NIN_SELECT
define|#
directive|define
name|NIN_SELECT
value|(WM_USER + 0)
end_define
begin_define
DECL|macro|NIN_KEYSELECT
define|#
directive|define
name|NIN_KEYSELECT
value|(WM_USER + 1)
end_define
begin_define
DECL|macro|NIN_BALLOONTIMEOUT
define|#
directive|define
name|NIN_BALLOONTIMEOUT
value|(WM_USER + 4)
end_define
begin_define
DECL|macro|NIN_BALLOONUSERCLICK
define|#
directive|define
name|NIN_BALLOONUSERCLICK
value|(WM_USER + 5)
end_define
begin_define
DECL|macro|NIF_SHOWTIP
define|#
directive|define
name|NIF_SHOWTIP
value|0x00000080
end_define
begin_define
DECL|macro|NOTIFYICON_VERSION_4
define|#
directive|define
name|NOTIFYICON_VERSION_4
value|4
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_define
DECL|macro|Q_MSGFLT_ALLOW
define|#
directive|define
name|Q_MSGFLT_ALLOW
value|1
end_define
begin_typedef
DECL|typedef|PtrShell_NotifyIconGetRect
typedef|typedef
name|HRESULT
function_decl|(
name|WINAPI
modifier|*
name|PtrShell_NotifyIconGetRect
function_decl|)
parameter_list|(
specifier|const
name|Q_NOTIFYICONIDENTIFIER
modifier|*
name|identifier
parameter_list|,
name|RECT
modifier|*
name|iconLocation
parameter_list|)
function_decl|;
end_typedef
begin_typedef
DECL|typedef|PtrChangeWindowMessageFilter
typedef|typedef
name|BOOL
function_decl|(
name|WINAPI
modifier|*
name|PtrChangeWindowMessageFilter
function_decl|)
parameter_list|(
name|UINT
name|message
parameter_list|,
name|DWORD
name|dwFlag
parameter_list|)
function_decl|;
end_typedef
begin_typedef
DECL|typedef|PtrChangeWindowMessageFilterEx
typedef|typedef
name|BOOL
function_decl|(
name|WINAPI
modifier|*
name|PtrChangeWindowMessageFilterEx
function_decl|)
parameter_list|(
name|HWND
name|hWnd
parameter_list|,
name|UINT
name|message
parameter_list|,
name|DWORD
name|action
parameter_list|,
name|void
modifier|*
name|pChangeFilterStruct
parameter_list|)
function_decl|;
end_typedef
begin_comment
comment|// Copy QString data to a limited wchar_t array including \0.
end_comment
begin_function
DECL|function|qStringToLimitedWCharArray
specifier|static
specifier|inline
name|void
name|qStringToLimitedWCharArray
parameter_list|(
name|QString
name|in
parameter_list|,
name|wchar_t
modifier|*
name|target
parameter_list|,
name|int
name|maxLength
parameter_list|)
block|{
specifier|const
name|int
name|length
init|=
name|qMin
argument_list|(
name|maxLength
operator|-
literal|1
argument_list|,
name|in
operator|.
name|size
argument_list|()
argument_list|)
decl_stmt|;
if|if
condition|(
name|length
operator|<
name|in
operator|.
name|size
argument_list|()
condition|)
name|in
operator|.
name|truncate
argument_list|(
name|length
argument_list|)
expr_stmt|;
name|in
operator|.
name|toWCharArray
argument_list|(
name|target
argument_list|)
expr_stmt|;
name|target
index|[
name|length
index|]
operator|=
name|wchar_t
argument_list|(
literal|0
argument_list|)
expr_stmt|;
block|}
end_function
begin_class
DECL|class|QSystemTrayIconSys
class|class
name|QSystemTrayIconSys
block|{
public|public:
name|QSystemTrayIconSys
parameter_list|(
name|HWND
name|hwnd
parameter_list|,
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
name|bool
name|showMessage
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
name|uint
name|uSecs
parameter_list|)
function_decl|;
name|QRect
name|findIconGeometry
parameter_list|(
specifier|const
name|int
name|a_iButtonID
parameter_list|)
function_decl|;
name|HICON
name|createIcon
parameter_list|()
function_decl|;
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
private|private:
DECL|member|m_hwnd
specifier|const
name|HWND
name|m_hwnd
decl_stmt|;
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
DECL|member|notifyIconSize
name|uint
name|notifyIconSize
decl_stmt|;
DECL|member|version
name|int
name|version
decl_stmt|;
DECL|member|ignoreNextMouseRelease
name|bool
name|ignoreNextMouseRelease
decl_stmt|;
block|}
class|;
end_class
begin_function
DECL|function|allowsMessages
specifier|static
name|bool
name|allowsMessages
parameter_list|()
block|{
ifndef|#
directive|ifndef
name|QT_NO_SETTINGS
specifier|const
name|QString
name|key
init|=
name|QStringLiteral
argument_list|(
literal|"HKEY_CURRENT_USER\\Software\\Microsoft\\Windows\\CurrentVersion\\Explorer\\Advanced"
argument_list|)
decl_stmt|;
specifier|const
name|QSettings
name|settings
argument_list|(
name|key
argument_list|,
name|QSettings
operator|::
name|NativeFormat
argument_list|)
decl_stmt|;
return|return
name|settings
operator|.
name|value
argument_list|(
name|QStringLiteral
argument_list|(
literal|"EnableBalloonTips"
argument_list|)
argument_list|,
literal|true
argument_list|)
operator|.
name|toBool
argument_list|()
return|;
else|#
directive|else
return|return
literal|false
return|;
endif|#
directive|endif
block|}
end_function
begin_typedef
DECL|typedef|HandleTrayIconHash
typedef|typedef
name|QHash
argument_list|<
name|HWND
argument_list|,
name|QSystemTrayIconSys
modifier|*
argument_list|>
name|HandleTrayIconHash
typedef|;
end_typedef
begin_macro
name|Q_GLOBAL_STATIC
argument_list|(
argument|HandleTrayIconHash
argument_list|,
argument|handleTrayIconHash
argument_list|)
end_macro
begin_extern
DECL|function|qWindowsTrayconWndProc
extern|extern
literal|"C"
name|LRESULT
name|QT_WIN_CALLBACK
name|qWindowsTrayconWndProc
parameter_list|(
name|HWND
name|hwnd
parameter_list|,
name|UINT
name|message
parameter_list|,
name|WPARAM
name|wParam
parameter_list|,
name|LPARAM
name|lParam
parameter_list|)
block|{
if|if
condition|(
name|message
operator|==
name|MYWM_TASKBARCREATED
operator|||
name|message
operator|==
name|MYWM_NOTIFYICON
condition|)
block|{
if|if
condition|(
name|QSystemTrayIconSys
modifier|*
name|trayIcon
init|=
name|handleTrayIconHash
argument_list|()
operator|->
name|value
argument_list|(
name|hwnd
argument_list|)
condition|)
block|{
name|MSG
name|msg
decl_stmt|;
name|msg
operator|.
name|hwnd
operator|=
name|hwnd
expr_stmt|;
comment|// re-create MSG structure
name|msg
operator|.
name|message
operator|=
name|message
expr_stmt|;
comment|// time and pt fields ignored
name|msg
operator|.
name|wParam
operator|=
name|wParam
expr_stmt|;
name|msg
operator|.
name|lParam
operator|=
name|lParam
expr_stmt|;
name|msg
operator|.
name|pt
operator|.
name|x
operator|=
name|GET_X_LPARAM
argument_list|(
name|lParam
argument_list|)
expr_stmt|;
name|msg
operator|.
name|pt
operator|.
name|y
operator|=
name|GET_Y_LPARAM
argument_list|(
name|lParam
argument_list|)
expr_stmt|;
name|long
name|result
init|=
literal|0
decl_stmt|;
if|if
condition|(
name|trayIcon
operator|->
name|winEvent
argument_list|(
operator|&
name|msg
argument_list|,
operator|&
name|result
argument_list|)
condition|)
return|return
name|result
return|;
block|}
block|}
return|return
name|DefWindowProc
argument_list|(
name|hwnd
argument_list|,
name|message
argument_list|,
name|wParam
argument_list|,
name|lParam
argument_list|)
return|;
block|}
end_extern
begin_comment
comment|// Invoke a service of the native Windows interface to create
end_comment
begin_comment
comment|// a non-visible message window.
end_comment
begin_function
DECL|function|createTrayIconMessageWindow
specifier|static
specifier|inline
name|HWND
name|createTrayIconMessageWindow
parameter_list|()
block|{
if|if
condition|(
name|QPlatformNativeInterface
modifier|*
name|ni
init|=
name|QGuiApplication
operator|::
name|platformNativeInterface
argument_list|()
condition|)
block|{
name|void
modifier|*
name|hwnd
init|=
literal|0
decl_stmt|;
name|void
modifier|*
name|wndProc
init|=
cast|reinterpret_cast
argument_list|<
name|void
operator|*
argument_list|>
argument_list|(
name|qWindowsTrayconWndProc
argument_list|)
decl_stmt|;
if|if
condition|(
name|QMetaObject
operator|::
name|invokeMethod
argument_list|(
name|ni
argument_list|,
literal|"createMessageWindow"
argument_list|,
name|Qt
operator|::
name|DirectConnection
argument_list|,
name|Q_RETURN_ARG
argument_list|(
name|void
operator|*
argument_list|,
name|hwnd
argument_list|)
argument_list|,
name|Q_ARG
argument_list|(
name|QString
argument_list|,
name|QStringLiteral
argument_list|(
literal|"QTrayIconMessageWindowClass"
argument_list|)
argument_list|)
argument_list|,
name|Q_ARG
argument_list|(
name|QString
argument_list|,
name|QStringLiteral
argument_list|(
literal|"QTrayIconMessageWindow"
argument_list|)
argument_list|)
argument_list|,
name|Q_ARG
argument_list|(
name|void
operator|*
argument_list|,
name|wndProc
argument_list|)
argument_list|)
operator|&&
name|hwnd
condition|)
block|{
return|return
cast|reinterpret_cast
argument_list|<
name|HWND
argument_list|>
argument_list|(
name|hwnd
argument_list|)
return|;
block|}
block|}
return|return
literal|0
return|;
block|}
end_function
begin_constructor
DECL|function|QSystemTrayIconSys
name|QSystemTrayIconSys
operator|::
name|QSystemTrayIconSys
parameter_list|(
name|HWND
name|hwnd
parameter_list|,
name|QSystemTrayIcon
modifier|*
name|object
parameter_list|)
member_init_list|:
name|m_hwnd
argument_list|(
name|hwnd
argument_list|)
member_init_list|,
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
name|notifyIconSize
argument_list|(
name|NOTIFYICONDATA_V2_SIZE
argument_list|)
member_init_list|,
name|version
argument_list|(
name|NOTIFYICON_VERSION
argument_list|)
member_init_list|,
name|ignoreNextMouseRelease
argument_list|(
literal|false
argument_list|)
block|{
name|handleTrayIconHash
argument_list|()
operator|->
name|insert
argument_list|(
name|m_hwnd
argument_list|,
name|this
argument_list|)
expr_stmt|;
if|if
condition|(
name|QSysInfo
operator|::
name|windowsVersion
argument_list|()
operator|<
name|QSysInfo
operator|::
name|WV_VISTA
condition|)
block|{
name|notifyIconSize
operator|=
name|NOTIFYICONDATA_V2_SIZE
expr_stmt|;
name|version
operator|=
name|NOTIFYICON_VERSION
expr_stmt|;
block|}
comment|// For restoring the tray icon after explorer crashes
if|if
condition|(
operator|!
name|MYWM_TASKBARCREATED
condition|)
block|{
name|MYWM_TASKBARCREATED
operator|=
name|RegisterWindowMessage
argument_list|(
literal|L"TaskbarCreated"
argument_list|)
expr_stmt|;
block|}
comment|// Allow the WM_TASKBARCREATED message through the UIPI filter on Windows Vista and higher
specifier|static
name|PtrChangeWindowMessageFilterEx
name|pChangeWindowMessageFilterEx
init|=
operator|(
name|PtrChangeWindowMessageFilterEx
operator|)
name|QSystemLibrary
operator|::
name|resolve
argument_list|(
name|QLatin1String
argument_list|(
literal|"user32"
argument_list|)
argument_list|,
literal|"ChangeWindowMessageFilterEx"
argument_list|)
decl_stmt|;
if|if
condition|(
name|pChangeWindowMessageFilterEx
condition|)
block|{
comment|// Call the safer ChangeWindowMessageFilterEx API if available (Windows 7 onwards)
name|pChangeWindowMessageFilterEx
argument_list|(
name|m_hwnd
argument_list|,
name|MYWM_TASKBARCREATED
argument_list|,
name|Q_MSGFLT_ALLOW
argument_list|,
literal|0
argument_list|)
expr_stmt|;
block|}
else|else
block|{
specifier|static
name|PtrChangeWindowMessageFilter
name|pChangeWindowMessageFilter
init|=
operator|(
name|PtrChangeWindowMessageFilter
operator|)
name|QSystemLibrary
operator|::
name|resolve
argument_list|(
name|QLatin1String
argument_list|(
literal|"user32"
argument_list|)
argument_list|,
literal|"ChangeWindowMessageFilter"
argument_list|)
decl_stmt|;
if|if
condition|(
name|pChangeWindowMessageFilter
condition|)
block|{
comment|// Call the deprecated ChangeWindowMessageFilter API otherwise
name|pChangeWindowMessageFilter
argument_list|(
name|MYWM_TASKBARCREATED
argument_list|,
name|Q_MSGFLT_ALLOW
argument_list|)
expr_stmt|;
block|}
block|}
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
name|handleTrayIconHash
argument_list|()
operator|->
name|remove
argument_list|(
name|m_hwnd
argument_list|)
expr_stmt|;
if|if
condition|(
name|hIcon
condition|)
name|DestroyIcon
argument_list|(
name|hIcon
argument_list|)
expr_stmt|;
name|DestroyWindow
argument_list|(
name|m_hwnd
argument_list|)
expr_stmt|;
block|}
end_destructor
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
operator||=
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
specifier|const
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
name|qStringToLimitedWCharArray
argument_list|(
name|tip
argument_list|,
name|tnd
operator|.
name|szTip
argument_list|,
literal|64
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|iconFlag
specifier|static
name|int
name|iconFlag
parameter_list|(
name|QSystemTrayIcon
operator|::
name|MessageIcon
name|icon
parameter_list|)
block|{
switch|switch
condition|(
name|icon
condition|)
block|{
case|case
name|QSystemTrayIcon
operator|::
name|Information
case|:
return|return
name|NIIF_INFO
return|;
case|case
name|QSystemTrayIcon
operator|::
name|Warning
case|:
return|return
name|NIIF_WARNING
return|;
case|case
name|QSystemTrayIcon
operator|::
name|Critical
case|:
return|return
name|NIIF_ERROR
return|;
case|case
name|QSystemTrayIcon
operator|::
name|NoIcon
case|:
return|return
name|NIIF_NONE
return|;
default|default:
name|Q_ASSERT_X
argument_list|(
literal|false
argument_list|,
literal|"QSystemTrayIconSys::showMessage"
argument_list|,
literal|"Invalid QSystemTrayIcon::MessageIcon value"
argument_list|)
expr_stmt|;
return|return
name|NIIF_NONE
return|;
block|}
block|}
end_function
begin_function
DECL|function|showMessage
name|bool
name|QSystemTrayIconSys
operator|::
name|showMessage
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
name|uint
name|uSecs
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
name|qStringToLimitedWCharArray
argument_list|(
name|message
argument_list|,
name|tnd
operator|.
name|szInfo
argument_list|,
literal|256
argument_list|)
expr_stmt|;
name|qStringToLimitedWCharArray
argument_list|(
name|title
argument_list|,
name|tnd
operator|.
name|szInfoTitle
argument_list|,
literal|64
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
name|dwInfoFlags
operator|=
name|iconFlag
argument_list|(
name|type
argument_list|)
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
name|m_hwnd
expr_stmt|;
name|tnd
operator|.
name|uTimeout
operator|=
name|uSecs
expr_stmt|;
name|tnd
operator|.
name|uFlags
operator|=
name|NIF_INFO
operator||
name|NIF_SHOWTIP
expr_stmt|;
return|return
name|Shell_NotifyIcon
argument_list|(
name|NIM_MODIFY
argument_list|,
operator|&
name|tnd
argument_list|)
return|;
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
name|m_hwnd
expr_stmt|;
name|tnd
operator|.
name|uFlags
operator|=
name|NIF_SHOWTIP
expr_stmt|;
name|tnd
operator|.
name|uVersion
operator|=
name|version
expr_stmt|;
if|if
condition|(
name|msg
operator|==
name|NIM_ADD
operator|||
name|msg
operator|==
name|NIM_MODIFY
condition|)
block|{
name|setIconContents
argument_list|(
name|tnd
argument_list|)
expr_stmt|;
block|}
name|bool
name|success
init|=
name|Shell_NotifyIcon
argument_list|(
name|msg
argument_list|,
operator|&
name|tnd
argument_list|)
decl_stmt|;
if|if
condition|(
name|msg
operator|==
name|NIM_ADD
condition|)
return|return
name|success
operator|&&
name|Shell_NotifyIcon
argument_list|(
name|NIM_SETVERSION
argument_list|,
operator|&
name|tnd
argument_list|)
return|;
else|else
return|return
name|success
return|;
block|}
end_function
begin_function_decl
name|Q_GUI_EXPORT
name|HICON
name|qt_pixmapToWinHICON
parameter_list|(
specifier|const
name|QPixmap
modifier|&
parameter_list|)
function_decl|;
end_function_decl
begin_function
DECL|function|createIcon
name|HICON
name|QSystemTrayIconSys
operator|::
name|createIcon
parameter_list|()
block|{
specifier|const
name|HICON
name|oldIcon
init|=
name|hIcon
decl_stmt|;
name|hIcon
operator|=
literal|0
expr_stmt|;
specifier|const
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
return|return
name|oldIcon
return|;
specifier|const
name|int
name|iconSizeX
init|=
name|GetSystemMetrics
argument_list|(
name|SM_CXSMICON
argument_list|)
decl_stmt|;
specifier|const
name|int
name|iconSizeY
init|=
name|GetSystemMetrics
argument_list|(
name|SM_CYSMICON
argument_list|)
decl_stmt|;
specifier|const
name|QSize
name|size
init|=
name|icon
operator|.
name|actualSize
argument_list|(
name|QSize
argument_list|(
name|iconSizeX
argument_list|,
name|iconSizeY
argument_list|)
argument_list|)
decl_stmt|;
specifier|const
name|QPixmap
name|pm
init|=
name|icon
operator|.
name|pixmap
argument_list|(
name|size
argument_list|)
decl_stmt|;
if|if
condition|(
name|pm
operator|.
name|isNull
argument_list|()
condition|)
return|return
name|oldIcon
return|;
name|hIcon
operator|=
name|qt_pixmapToWinHICON
argument_list|(
name|pm
argument_list|)
expr_stmt|;
return|return
name|oldIcon
return|;
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
operator|*
name|result
operator|=
literal|0
expr_stmt|;
switch|switch
condition|(
name|m
operator|->
name|message
condition|)
block|{
case|case
name|MYWM_NOTIFYICON
case|:
block|{
name|int
name|message
init|=
literal|0
decl_stmt|;
name|QPoint
name|gpos
decl_stmt|;
if|if
condition|(
name|version
operator|==
name|NOTIFYICON_VERSION_4
condition|)
block|{
name|Q_ASSERT
argument_list|(
name|q_uNOTIFYICONID
operator|==
name|HIWORD
argument_list|(
name|m
operator|->
name|lParam
argument_list|)
argument_list|)
expr_stmt|;
name|message
operator|=
name|LOWORD
argument_list|(
name|m
operator|->
name|lParam
argument_list|)
expr_stmt|;
name|gpos
operator|=
name|QPoint
argument_list|(
name|GET_X_LPARAM
argument_list|(
name|m
operator|->
name|wParam
argument_list|)
argument_list|,
name|GET_Y_LPARAM
argument_list|(
name|m
operator|->
name|wParam
argument_list|)
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|Q_ASSERT
argument_list|(
name|q_uNOTIFYICONID
operator|==
name|m
operator|->
name|wParam
argument_list|)
expr_stmt|;
name|message
operator|=
name|m
operator|->
name|lParam
expr_stmt|;
name|gpos
operator|=
name|QCursor
operator|::
name|pos
argument_list|()
expr_stmt|;
block|}
switch|switch
condition|(
name|message
condition|)
block|{
case|case
name|NIN_SELECT
case|:
case|case
name|NIN_KEYSELECT
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
name|WM_CONTEXTMENU
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
name|q
operator|->
name|contextMenu
argument_list|()
operator|->
name|activateWindow
argument_list|()
expr_stmt|;
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
name|NIN_BALLOONUSERCLICK
case|:
emit|emit
name|q
operator|->
name|messageClicked
argument_list|()
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
if|if
condition|(
name|m
operator|->
name|message
operator|==
name|MYWM_TASKBARCREATED
condition|)
comment|// self-registered message id.
name|trayMessage
argument_list|(
name|NIM_ADD
argument_list|)
expr_stmt|;
break|break;
block|}
return|return
literal|false
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
if|if
condition|(
specifier|const
name|HWND
name|hwnd
init|=
name|createTrayIconMessageWindow
argument_list|()
condition|)
block|{
name|sys
operator|=
operator|new
name|QSystemTrayIconSys
argument_list|(
name|hwnd
argument_list|,
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
else|else
block|{
name|qWarning
argument_list|(
literal|"%s: The platform plugin failed to create a message window."
argument_list|,
name|Q_FUNC_INFO
argument_list|)
expr_stmt|;
block|}
block|}
block|}
end_function
begin_comment
comment|/* * This function tries to determine the icon geometry from the tray * * If it fails an invalid rect is returned. */
end_comment
begin_function
DECL|function|findIconGeometry
name|QRect
name|QSystemTrayIconSys
operator|::
name|findIconGeometry
parameter_list|(
specifier|const
name|int
name|iconId
parameter_list|)
block|{
specifier|static
name|PtrShell_NotifyIconGetRect
name|Shell_NotifyIconGetRect
init|=
operator|(
name|PtrShell_NotifyIconGetRect
operator|)
name|QSystemLibrary
operator|::
name|resolve
argument_list|(
name|QLatin1String
argument_list|(
literal|"shell32"
argument_list|)
argument_list|,
literal|"Shell_NotifyIconGetRect"
argument_list|)
decl_stmt|;
if|if
condition|(
name|Shell_NotifyIconGetRect
condition|)
block|{
name|Q_NOTIFYICONIDENTIFIER
name|nid
decl_stmt|;
name|memset
argument_list|(
operator|&
name|nid
argument_list|,
literal|0
argument_list|,
sizeof|sizeof
argument_list|(
name|nid
argument_list|)
argument_list|)
expr_stmt|;
name|nid
operator|.
name|cbSize
operator|=
sizeof|sizeof
argument_list|(
name|nid
argument_list|)
expr_stmt|;
name|nid
operator|.
name|hWnd
operator|=
name|m_hwnd
expr_stmt|;
name|nid
operator|.
name|uID
operator|=
name|iconId
expr_stmt|;
name|RECT
name|rect
decl_stmt|;
name|HRESULT
name|hr
init|=
name|Shell_NotifyIconGetRect
argument_list|(
operator|&
name|nid
argument_list|,
operator|&
name|rect
argument_list|)
decl_stmt|;
if|if
condition|(
name|SUCCEEDED
argument_list|(
name|hr
argument_list|)
condition|)
block|{
return|return
name|QRect
argument_list|(
name|rect
operator|.
name|left
argument_list|,
name|rect
operator|.
name|top
argument_list|,
name|rect
operator|.
name|right
operator|-
name|rect
operator|.
name|left
argument_list|,
name|rect
operator|.
name|bottom
operator|-
name|rect
operator|.
name|top
argument_list|)
return|;
block|}
block|}
name|QRect
name|ret
decl_stmt|;
name|TBBUTTON
name|buttonData
decl_stmt|;
name|DWORD
name|processID
init|=
literal|0
decl_stmt|;
name|HWND
name|trayHandle
init|=
name|FindWindow
argument_list|(
literal|L"Shell_TrayWnd"
argument_list|,
name|NULL
argument_list|)
decl_stmt|;
comment|//find the toolbar used in the notification area
if|if
condition|(
name|trayHandle
condition|)
block|{
name|trayHandle
operator|=
name|FindWindowEx
argument_list|(
name|trayHandle
argument_list|,
name|NULL
argument_list|,
literal|L"TrayNotifyWnd"
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
if|if
condition|(
name|trayHandle
condition|)
block|{
name|HWND
name|hwnd
init|=
name|FindWindowEx
argument_list|(
name|trayHandle
argument_list|,
name|NULL
argument_list|,
literal|L"SysPager"
argument_list|,
name|NULL
argument_list|)
decl_stmt|;
if|if
condition|(
name|hwnd
condition|)
block|{
name|hwnd
operator|=
name|FindWindowEx
argument_list|(
name|hwnd
argument_list|,
name|NULL
argument_list|,
literal|L"ToolbarWindow32"
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
if|if
condition|(
name|hwnd
condition|)
name|trayHandle
operator|=
name|hwnd
expr_stmt|;
block|}
block|}
block|}
if|if
condition|(
operator|!
name|trayHandle
condition|)
return|return
name|ret
return|;
name|GetWindowThreadProcessId
argument_list|(
name|trayHandle
argument_list|,
operator|&
name|processID
argument_list|)
expr_stmt|;
if|if
condition|(
name|processID
operator|<=
literal|0
condition|)
return|return
name|ret
return|;
name|HANDLE
name|trayProcess
init|=
name|OpenProcess
argument_list|(
name|PROCESS_VM_OPERATION
operator||
name|PROCESS_VM_READ
argument_list|,
literal|0
argument_list|,
name|processID
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|trayProcess
condition|)
return|return
name|ret
return|;
name|int
name|buttonCount
init|=
name|SendMessage
argument_list|(
name|trayHandle
argument_list|,
name|TB_BUTTONCOUNT
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
decl_stmt|;
name|LPVOID
name|data
init|=
name|VirtualAllocEx
argument_list|(
name|trayProcess
argument_list|,
name|NULL
argument_list|,
sizeof|sizeof
argument_list|(
name|TBBUTTON
argument_list|)
argument_list|,
name|MEM_COMMIT
argument_list|,
name|PAGE_READWRITE
argument_list|)
decl_stmt|;
if|if
condition|(
name|buttonCount
operator|<
literal|1
operator|||
operator|!
name|data
condition|)
block|{
name|CloseHandle
argument_list|(
name|trayProcess
argument_list|)
expr_stmt|;
return|return
name|ret
return|;
block|}
comment|//search for our icon among all toolbar buttons
for|for
control|(
name|int
name|toolbarButton
init|=
literal|0
init|;
name|toolbarButton
operator|<
name|buttonCount
condition|;
operator|++
name|toolbarButton
control|)
block|{
name|SIZE_T
name|numBytes
init|=
literal|0
decl_stmt|;
name|DWORD
name|appData
index|[
literal|2
index|]
init|=
block|{
literal|0
block|,
literal|0
block|}
decl_stmt|;
name|SendMessage
argument_list|(
name|trayHandle
argument_list|,
name|TB_GETBUTTON
argument_list|,
name|toolbarButton
argument_list|,
operator|(
name|LPARAM
operator|)
name|data
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|ReadProcessMemory
argument_list|(
name|trayProcess
argument_list|,
name|data
argument_list|,
operator|&
name|buttonData
argument_list|,
sizeof|sizeof
argument_list|(
name|TBBUTTON
argument_list|)
argument_list|,
operator|&
name|numBytes
argument_list|)
condition|)
continue|continue;
if|if
condition|(
operator|!
name|ReadProcessMemory
argument_list|(
name|trayProcess
argument_list|,
operator|(
name|LPVOID
operator|)
name|buttonData
operator|.
name|dwData
argument_list|,
name|appData
argument_list|,
sizeof|sizeof
argument_list|(
name|appData
argument_list|)
argument_list|,
operator|&
name|numBytes
argument_list|)
condition|)
continue|continue;
name|int
name|currentIconId
init|=
name|appData
index|[
literal|1
index|]
decl_stmt|;
name|HWND
name|currentIconHandle
init|=
operator|(
name|HWND
operator|)
name|appData
index|[
literal|0
index|]
decl_stmt|;
name|bool
name|isHidden
init|=
name|buttonData
operator|.
name|fsState
operator|&
name|TBSTATE_HIDDEN
decl_stmt|;
if|if
condition|(
name|currentIconHandle
operator|==
name|m_hwnd
operator|&&
name|currentIconId
operator|==
name|iconId
operator|&&
operator|!
name|isHidden
condition|)
block|{
name|SendMessage
argument_list|(
name|trayHandle
argument_list|,
name|TB_GETITEMRECT
argument_list|,
name|toolbarButton
argument_list|,
operator|(
name|LPARAM
operator|)
name|data
argument_list|)
expr_stmt|;
name|RECT
name|iconRect
init|=
block|{
literal|0
block|,
literal|0
block|}
decl_stmt|;
if|if
condition|(
name|ReadProcessMemory
argument_list|(
name|trayProcess
argument_list|,
name|data
argument_list|,
operator|&
name|iconRect
argument_list|,
sizeof|sizeof
argument_list|(
name|RECT
argument_list|)
argument_list|,
operator|&
name|numBytes
argument_list|)
condition|)
block|{
name|MapWindowPoints
argument_list|(
name|trayHandle
argument_list|,
name|NULL
argument_list|,
operator|(
name|LPPOINT
operator|)
operator|&
name|iconRect
argument_list|,
literal|2
argument_list|)
expr_stmt|;
name|QRect
name|geometry
argument_list|(
name|iconRect
operator|.
name|left
operator|+
literal|1
argument_list|,
name|iconRect
operator|.
name|top
operator|+
literal|1
argument_list|,
name|iconRect
operator|.
name|right
operator|-
name|iconRect
operator|.
name|left
operator|-
literal|2
argument_list|,
name|iconRect
operator|.
name|bottom
operator|-
name|iconRect
operator|.
name|top
operator|-
literal|2
argument_list|)
decl_stmt|;
if|if
condition|(
name|geometry
operator|.
name|isValid
argument_list|()
condition|)
name|ret
operator|=
name|geometry
expr_stmt|;
break|break;
block|}
block|}
block|}
name|VirtualFreeEx
argument_list|(
name|trayProcess
argument_list|,
name|data
argument_list|,
literal|0
argument_list|,
name|MEM_RELEASE
argument_list|)
expr_stmt|;
name|CloseHandle
argument_list|(
name|trayProcess
argument_list|)
expr_stmt|;
return|return
name|ret
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
name|title
parameter_list|,
specifier|const
name|QString
modifier|&
name|messageIn
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
operator|||
operator|!
name|allowsMessages
argument_list|()
condition|)
return|return;
comment|// 10 sec default
specifier|const
name|uint
name|uSecs
init|=
name|timeOut
operator|<
literal|0
condition|?
name|uint
argument_list|(
literal|10000
argument_list|)
else|:
name|uint
argument_list|(
name|timeOut
argument_list|)
decl_stmt|;
comment|// For empty messages, ensures that they show when only title is set
name|QString
name|message
init|=
name|messageIn
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
name|message
operator|.
name|append
argument_list|(
name|QLatin1Char
argument_list|(
literal|' '
argument_list|)
argument_list|)
expr_stmt|;
name|sys
operator|->
name|showMessage
argument_list|(
name|title
argument_list|,
name|message
argument_list|,
name|type
argument_list|,
name|uSecs
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
name|findIconGeometry
argument_list|(
name|q_uNOTIFYICONID
argument_list|)
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
specifier|const
name|HICON
name|hIconToDestroy
init|=
name|sys
operator|->
name|createIcon
argument_list|()
decl_stmt|;
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
name|NIM_MODIFY
argument_list|)
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
name|allowsMessages
argument_list|()
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
