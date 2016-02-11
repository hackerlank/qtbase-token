begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtCore/QtConfig>
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_ACCESSIBILITY
end_ifndef
begin_include
include|#
directive|include
file|<private/qsystemlibrary_p.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qlocale.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qmap.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qpair.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qpointer.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qsettings.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/qaccessible.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/private/qguiapplication_p.h>
end_include
begin_include
include|#
directive|include
file|<qpa/qplatformnativeinterface.h>
end_include
begin_include
include|#
directive|include
file|<qpa/qplatformintegration.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/qwindow.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/qguiapplication.h>
end_include
begin_include
include|#
directive|include
file|"qwindowsaccessibility.h"
end_include
begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|Q_OS_WINCE
argument_list|)
end_if
begin_ifdef
ifdef|#
directive|ifdef
name|Q_CC_MINGW
end_ifdef
begin_include
include|#
directive|include
file|"qwindowsmsaaaccessible.h"
end_include
begin_else
else|#
directive|else
end_else
begin_include
include|#
directive|include
file|"iaccessible2.h"
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_endif
endif|#
directive|endif
end_endif
begin_include
include|#
directive|include
file|"comutils.h"
end_include
begin_include
include|#
directive|include
file|<oleacc.h>
end_include
begin_comment
comment|//#include<uiautomationcoreapi.h>
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|UiaRootObjectId
end_ifndef
begin_define
DECL|macro|UiaRootObjectId
define|#
directive|define
name|UiaRootObjectId
value|-25
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_include
include|#
directive|include
file|<winuser.h>
end_include
begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|WINABLEAPI
argument_list|)
end_if
begin_if
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_WINCE
argument_list|)
end_if
begin_include
include|#
directive|include
file|<bldver.h>
end_include
begin_else
else|#
directive|else
end_else
begin_include
include|#
directive|include
file|<winable.h>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_endif
endif|#
directive|endif
end_endif
begin_include
include|#
directive|include
file|<servprov.h>
end_include
begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|Q_CC_BOR
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|Q_CC_GNU
argument_list|)
end_if
begin_include
include|#
directive|include
file|<comdef.h>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_include
include|#
directive|include
file|"../qtwindows_additional.h"
end_include
begin_function
name|QT_BEGIN_NAMESPACE
comment|/*!     \!internal     \class QWindowsAccessibility      Implements QPlatformAccessibility  */
DECL|function|QWindowsAccessibility
name|QWindowsAccessibility
operator|::
name|QWindowsAccessibility
parameter_list|()
block|{ }
end_function
begin_comment
comment|// Retrieve sound name by checking the icon property of a message box
end_comment
begin_function
DECL|function|messageBoxAlertSound
specifier|static
specifier|inline
name|QString
name|messageBoxAlertSound
parameter_list|(
specifier|const
name|QObject
modifier|*
name|messageBox
parameter_list|)
block|{
enum|enum
name|MessageBoxIcon
block|{
comment|// Keep in sync with QMessageBox::Icon
name|Information
init|=
literal|1
block|,
name|Warning
init|=
literal|2
block|,
name|Critical
init|=
literal|3
block|}
enum|;
switch|switch
condition|(
name|messageBox
operator|->
name|property
argument_list|(
literal|"icon"
argument_list|)
operator|.
name|toInt
argument_list|()
condition|)
block|{
case|case
name|Information
case|:
return|return
name|QStringLiteral
argument_list|(
literal|"SystemAsterisk"
argument_list|)
return|;
case|case
name|Warning
case|:
return|return
name|QStringLiteral
argument_list|(
literal|"SystemExclamation"
argument_list|)
return|;
case|case
name|Critical
case|:
return|return
name|QStringLiteral
argument_list|(
literal|"SystemHand"
argument_list|)
return|;
block|}
return|return
name|QString
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|notifyAccessibilityUpdate
name|void
name|QWindowsAccessibility
operator|::
name|notifyAccessibilityUpdate
parameter_list|(
name|QAccessibleEvent
modifier|*
name|event
parameter_list|)
block|{
name|QString
name|soundName
decl_stmt|;
switch|switch
condition|(
name|event
operator|->
name|type
argument_list|()
condition|)
block|{
case|case
name|QAccessible
operator|::
name|PopupMenuStart
case|:
name|soundName
operator|=
name|QLatin1String
argument_list|(
literal|"MenuPopup"
argument_list|)
expr_stmt|;
break|break;
case|case
name|QAccessible
operator|::
name|MenuCommand
case|:
name|soundName
operator|=
name|QLatin1String
argument_list|(
literal|"MenuCommand"
argument_list|)
expr_stmt|;
break|break;
case|case
name|QAccessible
operator|::
name|Alert
case|:
name|soundName
operator|=
name|event
operator|->
name|object
argument_list|()
operator|->
name|inherits
argument_list|(
literal|"QMessageBox"
argument_list|)
condition|?
name|messageBoxAlertSound
argument_list|(
name|event
operator|->
name|object
argument_list|()
argument_list|)
else|:
name|QStringLiteral
argument_list|(
literal|"SystemAsterisk"
argument_list|)
expr_stmt|;
break|break;
default|default:
break|break;
block|}
if|if
condition|(
operator|!
name|soundName
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
ifndef|#
directive|ifndef
name|QT_NO_SETTINGS
name|QSettings
name|settings
argument_list|(
name|QLatin1String
argument_list|(
literal|"HKEY_CURRENT_USER\\AppEvents\\Schemes\\Apps\\.Default\\"
argument_list|)
operator|+
name|soundName
argument_list|,
name|QSettings
operator|::
name|NativeFormat
argument_list|)
decl_stmt|;
name|QString
name|file
init|=
name|settings
operator|.
name|value
argument_list|(
name|QLatin1String
argument_list|(
literal|".Current/."
argument_list|)
argument_list|)
operator|.
name|toString
argument_list|()
decl_stmt|;
else|#
directive|else
name|QString
name|file
decl_stmt|;
endif|#
directive|endif
if|if
condition|(
operator|!
name|file
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|PlaySound
argument_list|(
cast|reinterpret_cast
argument_list|<
specifier|const
name|wchar_t
operator|*
argument_list|>
argument_list|(
name|soundName
operator|.
name|utf16
argument_list|()
argument_list|)
argument_list|,
literal|0
argument_list|,
name|SND_ALIAS
operator||
name|SND_ASYNC
operator||
name|SND_NODEFAULT
operator||
name|SND_NOWAIT
argument_list|)
expr_stmt|;
block|}
block|}
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_WINCE
argument_list|)
comment|// ### TODO: check for NotifyWinEvent in CE 6.0
comment|// There is no user32.lib nor NotifyWinEvent for CE
return|return;
else|#
directive|else
comment|// An event has to be associated with a window,
comment|// so find the first parent that is a widget and that has a WId
name|QAccessibleInterface
modifier|*
name|iface
init|=
name|event
operator|->
name|accessibleInterface
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
name|isActive
argument_list|()
operator|||
operator|!
name|iface
operator|||
operator|!
name|iface
operator|->
name|isValid
argument_list|()
condition|)
return|return;
name|QWindow
modifier|*
name|window
init|=
name|QWindowsAccessibility
operator|::
name|windowHelper
argument_list|(
name|iface
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|window
condition|)
block|{
name|window
operator|=
name|QGuiApplication
operator|::
name|focusWindow
argument_list|()
expr_stmt|;
if|if
condition|(
operator|!
name|window
condition|)
return|return;
block|}
name|QPlatformNativeInterface
modifier|*
name|platform
init|=
name|QGuiApplication
operator|::
name|platformNativeInterface
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
name|window
operator|->
name|handle
argument_list|()
condition|)
comment|// Called before show(), no native window yet.
return|return;
name|HWND
name|hWnd
init|=
operator|(
name|HWND
operator|)
name|platform
operator|->
name|nativeResourceForWindow
argument_list|(
literal|"handle"
argument_list|,
name|window
argument_list|)
decl_stmt|;
if|if
condition|(
name|event
operator|->
name|type
argument_list|()
operator|!=
name|QAccessible
operator|::
name|MenuCommand
operator|&&
comment|// MenuCommand is faked
name|event
operator|->
name|type
argument_list|()
operator|!=
name|QAccessible
operator|::
name|ObjectDestroyed
condition|)
block|{
operator|::
name|NotifyWinEvent
argument_list|(
name|event
operator|->
name|type
argument_list|()
argument_list|,
name|hWnd
argument_list|,
name|OBJID_CLIENT
argument_list|,
name|QAccessible
operator|::
name|uniqueId
argument_list|(
name|iface
argument_list|)
argument_list|)
expr_stmt|;
block|}
endif|#
directive|endif
comment|// Q_OS_WINCE
block|}
end_function
begin_function
DECL|function|windowHelper
name|QWindow
modifier|*
name|QWindowsAccessibility
operator|::
name|windowHelper
parameter_list|(
specifier|const
name|QAccessibleInterface
modifier|*
name|iface
parameter_list|)
block|{
name|QWindow
modifier|*
name|window
init|=
name|iface
operator|->
name|window
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
name|window
condition|)
block|{
name|QAccessibleInterface
modifier|*
name|acc
init|=
name|iface
operator|->
name|parent
argument_list|()
decl_stmt|;
while|while
condition|(
name|acc
operator|&&
name|acc
operator|->
name|isValid
argument_list|()
operator|&&
operator|!
name|window
condition|)
block|{
name|window
operator|=
name|acc
operator|->
name|window
argument_list|()
expr_stmt|;
name|QAccessibleInterface
modifier|*
name|par
init|=
name|acc
operator|->
name|parent
argument_list|()
decl_stmt|;
name|acc
operator|=
name|par
expr_stmt|;
block|}
block|}
return|return
name|window
return|;
block|}
end_function
begin_comment
comment|/*!   \internal   helper to wrap a QAccessibleInterface inside a IAccessible* */
end_comment
begin_function
DECL|function|wrap
name|IAccessible
modifier|*
name|QWindowsAccessibility
operator|::
name|wrap
parameter_list|(
name|QAccessibleInterface
modifier|*
name|acc
parameter_list|)
block|{
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_WINCE
argument_list|)
name|Q_UNUSED
argument_list|(
name|acc
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
else|#
directive|else
if|if
condition|(
operator|!
name|acc
condition|)
return|return
literal|0
return|;
comment|// ### FIXME: maybe we should accept double insertions into the cache
if|if
condition|(
operator|!
name|QAccessible
operator|::
name|uniqueId
argument_list|(
name|acc
argument_list|)
condition|)
name|QAccessible
operator|::
name|registerAccessibleInterface
argument_list|(
name|acc
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|Q_CC_MINGW
name|QWindowsMsaaAccessible
modifier|*
name|wacc
init|=
operator|new
name|QWindowsMsaaAccessible
argument_list|(
name|acc
argument_list|)
decl_stmt|;
else|#
directive|else
name|QWindowsIA2Accessible
modifier|*
name|wacc
init|=
operator|new
name|QWindowsIA2Accessible
argument_list|(
name|acc
argument_list|)
decl_stmt|;
endif|#
directive|endif
name|IAccessible
modifier|*
name|iacc
init|=
literal|0
decl_stmt|;
name|wacc
operator|->
name|QueryInterface
argument_list|(
name|IID_IAccessible
argument_list|,
operator|(
name|void
operator|*
operator|*
operator|)
operator|&
name|iacc
argument_list|)
expr_stmt|;
return|return
name|iacc
return|;
endif|#
directive|endif
comment|// defined(Q_OS_WINCE)
block|}
end_function
begin_function
DECL|function|handleAccessibleObjectFromWindowRequest
name|bool
name|QWindowsAccessibility
operator|::
name|handleAccessibleObjectFromWindowRequest
parameter_list|(
name|HWND
name|hwnd
parameter_list|,
name|WPARAM
name|wParam
parameter_list|,
name|LPARAM
name|lParam
parameter_list|,
name|LRESULT
modifier|*
name|lResult
parameter_list|)
block|{
if|#
directive|if
operator|!
name|defined
argument_list|(
name|Q_OS_WINCE
argument_list|)
if|if
condition|(
cast|static_cast
argument_list|<
name|long
argument_list|>
argument_list|(
name|lParam
argument_list|)
operator|==
cast|static_cast
argument_list|<
name|long
argument_list|>
argument_list|(
name|UiaRootObjectId
argument_list|)
condition|)
block|{
comment|/* For UI Automation */
block|}
elseif|else
if|if
condition|(
operator|(
name|DWORD
operator|)
name|lParam
operator|==
name|DWORD
argument_list|(
name|OBJID_CLIENT
argument_list|)
condition|)
block|{
comment|// Start handling accessibility internally
name|QGuiApplicationPrivate
operator|::
name|platformIntegration
argument_list|()
operator|->
name|accessibility
argument_list|()
operator|->
name|setActive
argument_list|(
literal|true
argument_list|)
expr_stmt|;
comment|// Ignoring all requests while starting up
comment|// ### Maybe QPA takes care of this???
if|if
condition|(
name|QCoreApplication
operator|::
name|startingUp
argument_list|()
operator|||
name|QCoreApplication
operator|::
name|closingDown
argument_list|()
condition|)
return|return
literal|false
return|;
typedef|typedef
name|LRESULT
function_decl|(
name|WINAPI
modifier|*
name|PtrLresultFromObject
function_decl|)
parameter_list|(
name|REFIID
parameter_list|,
name|WPARAM
parameter_list|,
name|LPUNKNOWN
parameter_list|)
function_decl|;
specifier|static
name|PtrLresultFromObject
name|ptrLresultFromObject
init|=
literal|0
decl_stmt|;
specifier|static
name|bool
name|oleaccChecked
init|=
literal|false
decl_stmt|;
if|if
condition|(
operator|!
name|oleaccChecked
condition|)
block|{
name|oleaccChecked
operator|=
literal|true
expr_stmt|;
name|ptrLresultFromObject
operator|=
operator|(
name|PtrLresultFromObject
operator|)
name|QSystemLibrary
operator|::
name|resolve
argument_list|(
name|QLatin1String
argument_list|(
literal|"oleacc"
argument_list|)
argument_list|,
literal|"LresultFromObject"
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|ptrLresultFromObject
condition|)
block|{
name|QWindow
modifier|*
name|window
init|=
name|QWindowsContext
operator|::
name|instance
argument_list|()
operator|->
name|findWindow
argument_list|(
name|hwnd
argument_list|)
decl_stmt|;
if|if
condition|(
name|window
condition|)
block|{
name|QAccessibleInterface
modifier|*
name|acc
init|=
name|window
operator|->
name|accessibleRoot
argument_list|()
decl_stmt|;
if|if
condition|(
name|acc
condition|)
block|{
if|if
condition|(
name|IAccessible
modifier|*
name|iface
init|=
name|wrap
argument_list|(
name|acc
argument_list|)
condition|)
block|{
operator|*
name|lResult
operator|=
name|ptrLresultFromObject
argument_list|(
name|IID_IAccessible
argument_list|,
name|wParam
argument_list|,
name|iface
argument_list|)
expr_stmt|;
comment|// ref == 2
if|if
condition|(
operator|*
name|lResult
condition|)
block|{
name|iface
operator|->
name|Release
argument_list|()
expr_stmt|;
comment|// the client will release the object again, and then it will destroy itself
block|}
return|return
literal|true
return|;
block|}
block|}
block|}
block|}
block|}
else|#
directive|else
name|Q_UNUSED
argument_list|(
name|hwnd
argument_list|)
expr_stmt|;
name|Q_UNUSED
argument_list|(
name|wParam
argument_list|)
expr_stmt|;
name|Q_UNUSED
argument_list|(
name|lParam
argument_list|)
expr_stmt|;
name|Q_UNUSED
argument_list|(
name|lResult
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|// !defined(Q_OS_WINCE)
return|return
literal|false
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
begin_comment
comment|//QT_NO_ACCESSIBILITY
end_comment
end_unit
