begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qdesktopwidget.h"
end_include
begin_include
include|#
directive|include
file|"qt_windows.h"
end_include
begin_include
include|#
directive|include
file|"qapplication_p.h"
end_include
begin_include
include|#
directive|include
file|<private/qsystemlibrary_p.h>
end_include
begin_include
include|#
directive|include
file|<qvector.h>
end_include
begin_include
include|#
directive|include
file|<limits.h>
end_include
begin_ifdef
ifdef|#
directive|ifdef
name|Q_WS_WINCE
end_ifdef
begin_include
include|#
directive|include
file|<sipapi.h>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_include
include|#
directive|include
file|"qwidget_p.h"
end_include
begin_include
include|#
directive|include
file|"qdebug.h"
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_class
DECL|class|QDesktopWidgetPrivate
class|class
name|QDesktopWidgetPrivate
super|:
specifier|public
name|QWidgetPrivate
block|{
public|public:
name|QDesktopWidgetPrivate
parameter_list|()
constructor_decl|;
name|~
name|QDesktopWidgetPrivate
parameter_list|()
destructor_decl|;
specifier|static
name|void
name|init
parameter_list|(
name|QDesktopWidget
modifier|*
name|that
parameter_list|)
function_decl|;
specifier|static
name|void
name|cleanup
parameter_list|()
function_decl|;
DECL|member|screenCount
specifier|static
name|int
name|screenCount
decl_stmt|;
DECL|member|primaryScreen
specifier|static
name|int
name|primaryScreen
decl_stmt|;
DECL|member|rects
specifier|static
name|QVector
argument_list|<
name|QRect
argument_list|>
modifier|*
name|rects
decl_stmt|;
DECL|member|workrects
specifier|static
name|QVector
argument_list|<
name|QRect
argument_list|>
modifier|*
name|workrects
decl_stmt|;
DECL|struct|MONITORINFO
struct|struct
name|MONITORINFO
block|{
DECL|member|cbSize
name|DWORD
name|cbSize
decl_stmt|;
DECL|member|rcMonitor
name|RECT
name|rcMonitor
decl_stmt|;
DECL|member|rcWork
name|RECT
name|rcWork
decl_stmt|;
DECL|member|dwFlags
name|DWORD
name|dwFlags
decl_stmt|;
block|}
struct|;
DECL|typedef|InfoFunc
typedef|typedef
name|BOOL
function_decl|(
name|WINAPI
modifier|*
name|InfoFunc
function_decl|)
parameter_list|(
name|HMONITOR
parameter_list|,
name|MONITORINFO
modifier|*
parameter_list|)
function_decl|;
DECL|typedef|EnumProc
typedef|typedef
name|BOOL
function_decl|(
name|QT_WIN_CALLBACK
modifier|*
name|EnumProc
function_decl|)
parameter_list|(
name|HMONITOR
parameter_list|,
name|HDC
parameter_list|,
name|LPRECT
parameter_list|,
name|LPARAM
parameter_list|)
function_decl|;
DECL|typedef|EnumFunc
typedef|typedef
name|BOOL
function_decl|(
name|WINAPI
modifier|*
name|EnumFunc
function_decl|)
parameter_list|(
name|HDC
parameter_list|,
name|LPCRECT
parameter_list|,
name|EnumProc
parameter_list|,
name|LPARAM
parameter_list|)
function_decl|;
DECL|member|enumDisplayMonitors
specifier|static
name|EnumFunc
name|enumDisplayMonitors
decl_stmt|;
DECL|member|getMonitorInfo
specifier|static
name|InfoFunc
name|getMonitorInfo
decl_stmt|;
DECL|member|refcount
specifier|static
name|int
name|refcount
decl_stmt|;
block|}
class|;
end_class
begin_decl_stmt
DECL|member|screenCount
name|int
name|QDesktopWidgetPrivate
operator|::
name|screenCount
init|=
literal|1
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|member|primaryScreen
name|int
name|QDesktopWidgetPrivate
operator|::
name|primaryScreen
init|=
literal|0
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|member|enumDisplayMonitors
name|QDesktopWidgetPrivate
operator|::
name|EnumFunc
name|QDesktopWidgetPrivate
operator|::
name|enumDisplayMonitors
init|=
literal|0
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|member|getMonitorInfo
name|QDesktopWidgetPrivate
operator|::
name|InfoFunc
name|QDesktopWidgetPrivate
operator|::
name|getMonitorInfo
init|=
literal|0
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|member|rects
name|QVector
argument_list|<
name|QRect
argument_list|>
modifier|*
name|QDesktopWidgetPrivate
operator|::
name|rects
init|=
literal|0
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|member|workrects
name|QVector
argument_list|<
name|QRect
argument_list|>
modifier|*
name|QDesktopWidgetPrivate
operator|::
name|workrects
init|=
literal|0
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|screen_number
specifier|static
name|int
name|screen_number
init|=
literal|0
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|member|refcount
name|int
name|QDesktopWidgetPrivate
operator|::
name|refcount
init|=
literal|0
decl_stmt|;
end_decl_stmt
begin_ifdef
ifdef|#
directive|ifdef
name|Q_WS_WINCE_WM
end_ifdef
begin_comment
comment|// Use SIP information, if available
end_comment
begin_comment
comment|// SipGetInfo is not supported by SSDK (no definition!).
end_comment
begin_function
DECL|function|qt_get_sip_info
specifier|static
specifier|inline
name|void
name|qt_get_sip_info
parameter_list|(
name|QRect
modifier|&
name|rect
parameter_list|)
block|{
name|SIPINFO
name|sip
decl_stmt|;
name|memset
argument_list|(
operator|&
name|sip
argument_list|,
literal|0
argument_list|,
sizeof|sizeof
argument_list|(
name|SIPINFO
argument_list|)
argument_list|)
expr_stmt|;
name|sip
operator|.
name|cbSize
operator|=
sizeof|sizeof
argument_list|(
name|SIPINFO
argument_list|)
expr_stmt|;
if|if
condition|(
name|SipGetInfo
argument_list|(
operator|&
name|sip
argument_list|)
condition|)
name|rect
operator|=
name|QRect
argument_list|(
name|QPoint
argument_list|(
name|sip
operator|.
name|rcVisibleDesktop
operator|.
name|left
argument_list|,
name|sip
operator|.
name|rcVisibleDesktop
operator|.
name|top
argument_list|)
argument_list|,
name|QPoint
argument_list|(
name|sip
operator|.
name|rcVisibleDesktop
operator|.
name|right
operator|-
literal|1
argument_list|,
name|sip
operator|.
name|rcVisibleDesktop
operator|.
name|bottom
operator|-
literal|1
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_function
DECL|function|enumCallback
name|BOOL
name|QT_WIN_CALLBACK
name|enumCallback
parameter_list|(
name|HMONITOR
name|hMonitor
parameter_list|,
name|HDC
parameter_list|,
name|LPRECT
parameter_list|,
name|LPARAM
parameter_list|)
block|{
name|QDesktopWidgetPrivate
operator|::
name|screenCount
operator|++
expr_stmt|;
name|QDesktopWidgetPrivate
operator|::
name|rects
operator|->
name|resize
argument_list|(
name|QDesktopWidgetPrivate
operator|::
name|screenCount
argument_list|)
expr_stmt|;
name|QDesktopWidgetPrivate
operator|::
name|workrects
operator|->
name|resize
argument_list|(
name|QDesktopWidgetPrivate
operator|::
name|screenCount
argument_list|)
expr_stmt|;
comment|// Get the MONITORINFO block
name|QDesktopWidgetPrivate
operator|::
name|MONITORINFO
name|info
decl_stmt|;
name|memset
argument_list|(
operator|&
name|info
argument_list|,
literal|0
argument_list|,
sizeof|sizeof
argument_list|(
name|QDesktopWidgetPrivate
operator|::
name|MONITORINFO
argument_list|)
argument_list|)
expr_stmt|;
name|info
operator|.
name|cbSize
operator|=
sizeof|sizeof
argument_list|(
name|QDesktopWidgetPrivate
operator|::
name|MONITORINFO
argument_list|)
expr_stmt|;
name|BOOL
name|res
init|=
name|QDesktopWidgetPrivate
operator|::
name|getMonitorInfo
argument_list|(
name|hMonitor
argument_list|,
operator|&
name|info
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|res
condition|)
block|{
operator|(
operator|*
name|QDesktopWidgetPrivate
operator|::
name|rects
operator|)
index|[
name|screen_number
index|]
operator|=
name|QRect
argument_list|()
expr_stmt|;
operator|(
operator|*
name|QDesktopWidgetPrivate
operator|::
name|workrects
operator|)
index|[
name|screen_number
index|]
operator|=
name|QRect
argument_list|()
expr_stmt|;
return|return
literal|true
return|;
block|}
comment|// Fill list of rects
name|RECT
name|r
init|=
name|info
operator|.
name|rcMonitor
decl_stmt|;
name|QRect
name|qr
argument_list|(
name|QPoint
argument_list|(
name|r
operator|.
name|left
argument_list|,
name|r
operator|.
name|top
argument_list|)
argument_list|,
name|QPoint
argument_list|(
name|r
operator|.
name|right
operator|-
literal|1
argument_list|,
name|r
operator|.
name|bottom
operator|-
literal|1
argument_list|)
argument_list|)
decl_stmt|;
operator|(
operator|*
name|QDesktopWidgetPrivate
operator|::
name|rects
operator|)
index|[
name|screen_number
index|]
operator|=
name|qr
expr_stmt|;
name|r
operator|=
name|info
operator|.
name|rcWork
expr_stmt|;
name|qr
operator|=
name|QRect
argument_list|(
name|QPoint
argument_list|(
name|r
operator|.
name|left
argument_list|,
name|r
operator|.
name|top
argument_list|)
argument_list|,
name|QPoint
argument_list|(
name|r
operator|.
name|right
operator|-
literal|1
argument_list|,
name|r
operator|.
name|bottom
operator|-
literal|1
argument_list|)
argument_list|)
expr_stmt|;
operator|(
operator|*
name|QDesktopWidgetPrivate
operator|::
name|workrects
operator|)
index|[
name|screen_number
index|]
operator|=
name|qr
expr_stmt|;
if|if
condition|(
name|info
operator|.
name|dwFlags
operator|&
literal|0x00000001
condition|)
comment|//MONITORINFOF_PRIMARY
name|QDesktopWidgetPrivate
operator|::
name|primaryScreen
operator|=
name|screen_number
expr_stmt|;
operator|++
name|screen_number
expr_stmt|;
comment|// Stop the enumeration if we have them all
return|return
literal|true
return|;
block|}
end_function
begin_constructor
DECL|function|QDesktopWidgetPrivate
name|QDesktopWidgetPrivate
operator|::
name|QDesktopWidgetPrivate
parameter_list|()
block|{
operator|++
name|refcount
expr_stmt|;
block|}
end_constructor
begin_function
DECL|function|init
name|void
name|QDesktopWidgetPrivate
operator|::
name|init
parameter_list|(
name|QDesktopWidget
modifier|*
name|that
parameter_list|)
block|{
if|if
condition|(
name|rects
condition|)
return|return;
name|rects
operator|=
operator|new
name|QVector
argument_list|<
name|QRect
argument_list|>
argument_list|()
expr_stmt|;
name|workrects
operator|=
operator|new
name|QVector
argument_list|<
name|QRect
argument_list|>
argument_list|()
expr_stmt|;
name|screenCount
operator|=
literal|0
expr_stmt|;
ifndef|#
directive|ifndef
name|Q_OS_WINCE
name|QSystemLibrary
name|user32Lib
argument_list|(
name|QLatin1String
argument_list|(
literal|"user32"
argument_list|)
argument_list|)
decl_stmt|;
name|enumDisplayMonitors
operator|=
operator|(
name|EnumFunc
operator|)
name|user32Lib
operator|.
name|resolve
argument_list|(
literal|"EnumDisplayMonitors"
argument_list|)
expr_stmt|;
name|getMonitorInfo
operator|=
operator|(
name|InfoFunc
operator|)
name|user32Lib
operator|.
name|resolve
argument_list|(
literal|"GetMonitorInfoW"
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|enumDisplayMonitors
operator|||
operator|!
name|getMonitorInfo
condition|)
block|{
name|screenCount
operator|=
name|GetSystemMetrics
argument_list|(
literal|80
argument_list|)
expr_stmt|;
comment|// SM_CMONITORS
name|rects
operator|->
name|resize
argument_list|(
name|screenCount
argument_list|)
expr_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|screenCount
condition|;
operator|++
name|i
control|)
name|rects
operator|->
name|replace
argument_list|(
name|i
argument_list|,
name|that
operator|->
name|rect
argument_list|()
argument_list|)
expr_stmt|;
return|return;
block|}
comment|// Calls enumCallback
name|enumDisplayMonitors
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
name|enumCallback
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|enumDisplayMonitors
operator|=
literal|0
expr_stmt|;
name|getMonitorInfo
operator|=
literal|0
expr_stmt|;
else|#
directive|else
name|QSystemLibrary
name|coreLib
argument_list|(
name|QLatin1String
argument_list|(
literal|"coredll"
argument_list|)
argument_list|)
decl_stmt|;
comment|// CE>= 4.0 case
name|enumDisplayMonitors
operator|=
operator|(
name|EnumFunc
operator|)
name|coreLib
operator|.
name|resolve
argument_list|(
literal|"EnumDisplayMonitors"
argument_list|)
expr_stmt|;
name|getMonitorInfo
operator|=
operator|(
name|InfoFunc
operator|)
name|coreLib
operator|.
name|resolve
argument_list|(
literal|"GetMonitorInfo"
argument_list|)
expr_stmt|;
if|if
condition|(
operator|(
operator|!
name|enumDisplayMonitors
operator|||
operator|!
name|getMonitorInfo
operator|)
condition|)
block|{
name|screenCount
operator|=
name|GetSystemMetrics
argument_list|(
name|SM_CMONITORS
argument_list|)
expr_stmt|;
return|return;
block|}
if|if
condition|(
operator|!
name|coreLib
operator|.
name|isLoaded
argument_list|()
operator|||
operator|!
name|enumDisplayMonitors
operator|||
operator|!
name|getMonitorInfo
condition|)
block|{
name|rects
operator|->
name|resize
argument_list|(
name|screenCount
argument_list|)
expr_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|screenCount
condition|;
operator|++
name|i
control|)
operator|(
operator|*
name|rects
operator|)
index|[
name|i
index|]
operator|=
name|that
operator|->
name|rect
argument_list|()
expr_stmt|;
name|RECT
name|r
decl_stmt|;
name|SystemParametersInfo
argument_list|(
name|SPI_GETWORKAREA
argument_list|,
literal|0
argument_list|,
operator|&
name|r
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|QRect
name|qr
init|=
name|QRect
argument_list|(
name|QPoint
argument_list|(
name|r
operator|.
name|left
argument_list|,
name|r
operator|.
name|top
argument_list|)
argument_list|,
name|QPoint
argument_list|(
name|r
operator|.
name|right
operator|-
literal|1
argument_list|,
name|r
operator|.
name|bottom
operator|-
literal|1
argument_list|)
argument_list|)
decl_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|Q_WS_WINCE_WM
argument_list|)
name|qt_get_sip_info
argument_list|(
name|qr
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|workrects
operator|->
name|resize
argument_list|(
name|screenCount
argument_list|)
expr_stmt|;
for|for
control|(
name|int
name|j
init|=
literal|0
init|;
name|j
operator|<
name|screenCount
condition|;
operator|++
name|j
control|)
operator|(
operator|*
name|workrects
operator|)
index|[
name|j
index|]
operator|=
name|qr
expr_stmt|;
return|return;
block|}
comment|// Calls enumCallback
name|enumDisplayMonitors
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
name|enumCallback
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|enumDisplayMonitors
operator|=
literal|0
expr_stmt|;
name|getMonitorInfo
operator|=
literal|0
expr_stmt|;
endif|#
directive|endif
comment|// Q_WS_WINCE
block|}
end_function
begin_destructor
DECL|function|~QDesktopWidgetPrivate
name|QDesktopWidgetPrivate
operator|::
name|~
name|QDesktopWidgetPrivate
parameter_list|()
block|{
if|if
condition|(
operator|!
operator|--
name|refcount
condition|)
name|cleanup
argument_list|()
expr_stmt|;
block|}
end_destructor
begin_function
DECL|function|cleanup
name|void
name|QDesktopWidgetPrivate
operator|::
name|cleanup
parameter_list|()
block|{
name|screen_number
operator|=
literal|0
expr_stmt|;
name|screenCount
operator|=
literal|1
expr_stmt|;
name|primaryScreen
operator|=
literal|0
expr_stmt|;
name|enumDisplayMonitors
operator|=
literal|0
expr_stmt|;
name|getMonitorInfo
operator|=
literal|0
expr_stmt|;
operator|delete
name|rects
expr_stmt|;
name|rects
operator|=
literal|0
expr_stmt|;
operator|delete
name|workrects
expr_stmt|;
name|workrects
operator|=
literal|0
expr_stmt|;
block|}
end_function
begin_comment
comment|/*     \omit     Function is commented out in header     \fn void *QDesktopWidget::handle(int screen) const      Returns the window system handle of the display device with the     index \a screen, for low-level access.  Using this function is not     portable.      The return type varies with platform; see qwindowdefs.h for details.      \sa x11Display(), QPaintDevice::handle()     \endomit */
end_comment
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
name|setObjectName
argument_list|(
name|QLatin1String
argument_list|(
literal|"desktop"
argument_list|)
argument_list|)
expr_stmt|;
name|QDesktopWidgetPrivate
operator|::
name|init
argument_list|(
name|this
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
literal|true
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
name|d_func
argument_list|()
operator|->
name|primaryScreen
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
name|d_func
argument_list|()
operator|->
name|screenCount
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
comment|/* screen */
parameter_list|)
block|{
comment|// It seems that a Qt::WType_Desktop cannot be moved?
return|return
name|this
return|;
block|}
end_function
begin_comment
comment|//
end_comment
begin_comment
comment|// MSVC 7.10 warns that d (the result of the expanded Q_D macro) as a local variable that is not referenced.
end_comment
begin_comment
comment|// Therefore, we ignore that warning with the following pragmas
end_comment
begin_comment
comment|// I've also tried to eliminate the macro, but to no use...
end_comment
begin_comment
comment|// We pop it further down
end_comment
begin_ifdef
ifdef|#
directive|ifdef
name|Q_CC_MSVC
end_ifdef
begin_pragma
pragma|#
directive|pragma
name|warning
name|(
name|push
name|)
end_pragma
begin_pragma
pragma|#
directive|pragma
name|warning
name|(
name|disable
name|:
name|4189
name|)
end_pragma
begin_endif
endif|#
directive|endif
end_endif
begin_function
DECL|function|availableGeometry
specifier|const
name|QRect
name|QDesktopWidget
operator|::
name|availableGeometry
parameter_list|(
name|int
name|screen
parameter_list|)
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QDesktopWidget
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|Q_WS_WINCE_WM
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|d
operator|->
name|workrects
operator|->
name|size
argument_list|()
condition|;
operator|++
name|i
control|)
name|qt_get_sip_info
argument_list|(
operator|(
operator|*
name|d
operator|->
name|workrects
operator|)
index|[
name|i
index|]
argument_list|)
expr_stmt|;
endif|#
directive|endif
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
name|screenCount
condition|)
name|screen
operator|=
name|d
operator|->
name|primaryScreen
expr_stmt|;
return|return
name|d
operator|->
name|workrects
operator|->
name|at
argument_list|(
name|screen
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
name|int
name|screen
parameter_list|)
specifier|const
block|{
specifier|const
name|QDesktopWidgetPrivate
modifier|*
name|d
init|=
name|d_func
argument_list|()
decl_stmt|;
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
name|screenCount
condition|)
name|screen
operator|=
name|d
operator|->
name|primaryScreen
expr_stmt|;
return|return
name|d
operator|->
name|rects
operator|->
name|at
argument_list|(
name|screen
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
name|QWidget
modifier|*
name|widget
parameter_list|)
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QDesktopWidget
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|widget
condition|)
return|return
name|d
operator|->
name|primaryScreen
return|;
name|QRect
name|frame
init|=
name|widget
operator|->
name|frameGeometry
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
name|widget
operator|->
name|isWindow
argument_list|()
condition|)
name|frame
operator|.
name|moveTopLeft
argument_list|(
name|widget
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
name|int
name|maxSize
init|=
operator|-
literal|1
decl_stmt|;
name|int
name|maxScreen
init|=
operator|-
literal|1
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
name|d
operator|->
name|screenCount
condition|;
operator|++
name|i
control|)
block|{
name|QRect
name|sect
init|=
name|d
operator|->
name|rects
operator|->
name|at
argument_list|(
name|i
argument_list|)
operator|.
name|intersected
argument_list|(
name|frame
argument_list|)
decl_stmt|;
name|int
name|size
init|=
name|sect
operator|.
name|width
argument_list|()
operator|*
name|sect
operator|.
name|height
argument_list|()
decl_stmt|;
if|if
condition|(
name|size
operator|>
name|maxSize
operator|&&
name|sect
operator|.
name|width
argument_list|()
operator|>
literal|0
operator|&&
name|sect
operator|.
name|height
argument_list|()
operator|>
literal|0
condition|)
block|{
name|maxSize
operator|=
name|size
expr_stmt|;
name|maxScreen
operator|=
name|i
expr_stmt|;
block|}
block|}
return|return
name|maxScreen
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
name|point
parameter_list|)
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QDesktopWidget
argument_list|)
expr_stmt|;
name|int
name|closestScreen
init|=
operator|-
literal|1
decl_stmt|;
name|int
name|shortestDistance
init|=
name|INT_MAX
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
name|d
operator|->
name|screenCount
condition|;
operator|++
name|i
control|)
block|{
name|int
name|thisDistance
init|=
name|d
operator|->
name|pointToRect
argument_list|(
name|point
argument_list|,
name|d
operator|->
name|rects
operator|->
name|at
argument_list|(
name|i
argument_list|)
argument_list|)
decl_stmt|;
if|if
condition|(
name|thisDistance
operator|<
name|shortestDistance
condition|)
block|{
name|shortestDistance
operator|=
name|thisDistance
expr_stmt|;
name|closestScreen
operator|=
name|i
expr_stmt|;
block|}
block|}
return|return
name|closestScreen
return|;
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
block|{
name|Q_D
argument_list|(
name|QDesktopWidget
argument_list|)
expr_stmt|;
specifier|const
name|QVector
argument_list|<
name|QRect
argument_list|>
name|oldrects
argument_list|(
operator|*
name|d
operator|->
name|rects
argument_list|)
decl_stmt|;
specifier|const
name|QVector
argument_list|<
name|QRect
argument_list|>
name|oldworkrects
argument_list|(
operator|*
name|d
operator|->
name|workrects
argument_list|)
decl_stmt|;
name|int
name|oldscreencount
init|=
name|d
operator|->
name|screenCount
decl_stmt|;
name|QDesktopWidgetPrivate
operator|::
name|cleanup
argument_list|()
expr_stmt|;
name|QDesktopWidgetPrivate
operator|::
name|init
argument_list|(
name|this
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|Q_WS_WINCE_WM
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|d
operator|->
name|workrects
operator|->
name|size
argument_list|()
condition|;
operator|++
name|i
control|)
name|qt_get_sip_info
argument_list|(
operator|(
operator|*
name|d
operator|->
name|workrects
operator|)
index|[
name|i
index|]
argument_list|)
expr_stmt|;
endif|#
directive|endif
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|qMin
argument_list|(
name|oldscreencount
argument_list|,
name|d
operator|->
name|screenCount
argument_list|)
condition|;
operator|++
name|i
control|)
block|{
specifier|const
name|QRect
name|oldrect
init|=
name|oldrects
index|[
name|i
index|]
decl_stmt|;
specifier|const
name|QRect
name|newrect
init|=
name|d
operator|->
name|rects
operator|->
name|at
argument_list|(
name|i
argument_list|)
decl_stmt|;
if|if
condition|(
name|oldrect
operator|!=
name|newrect
condition|)
emit|emit
name|resized
argument_list|(
name|i
argument_list|)
emit|;
block|}
for|for
control|(
name|int
name|j
init|=
literal|0
init|;
name|j
operator|<
name|qMin
argument_list|(
name|oldscreencount
argument_list|,
name|d
operator|->
name|screenCount
argument_list|)
condition|;
operator|++
name|j
control|)
block|{
specifier|const
name|QRect
name|oldrect
init|=
name|oldworkrects
index|[
name|j
index|]
decl_stmt|;
specifier|const
name|QRect
name|newrect
init|=
name|d
operator|->
name|workrects
operator|->
name|at
argument_list|(
name|j
argument_list|)
decl_stmt|;
if|if
condition|(
name|oldrect
operator|!=
name|newrect
condition|)
emit|emit
name|workAreaResized
argument_list|(
name|j
argument_list|)
emit|;
block|}
if|if
condition|(
name|oldscreencount
operator|!=
name|d
operator|->
name|screenCount
condition|)
block|{
emit|emit
name|screenCountChanged
argument_list|(
name|d
operator|->
name|screenCount
argument_list|)
emit|;
block|}
block|}
end_function
begin_ifdef
ifdef|#
directive|ifdef
name|Q_CC_MSVC
end_ifdef
begin_pragma
pragma|#
directive|pragma
name|warning
name|(
name|pop
name|)
end_pragma
begin_endif
endif|#
directive|endif
end_endif
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
