begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qwinrtclipboard.h"
end_include
begin_include
include|#
directive|include
file|<QtCore/QCoreApplication>
end_include
begin_include
include|#
directive|include
file|<QtCore/qfunctions_winrt.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/private/qeventdispatcher_winrt_p.h>
end_include
begin_include
include|#
directive|include
file|<Windows.ApplicationModel.datatransfer.h>
end_include
begin_include
include|#
directive|include
file|<functional>
end_include
begin_using
using|using
namespace|namespace
name|ABI
operator|::
name|Windows
operator|::
name|ApplicationModel
operator|::
name|DataTransfer
namespace|;
end_using
begin_using
using|using
namespace|namespace
name|ABI
operator|::
name|Windows
operator|::
name|Foundation
namespace|;
end_using
begin_using
using|using
namespace|namespace
name|Microsoft
operator|::
name|WRL
namespace|;
end_using
begin_using
using|using
namespace|namespace
name|Microsoft
operator|::
name|WRL
operator|::
name|Wrappers
namespace|;
end_using
begin_typedef
DECL|typedef|ContentChangedHandler
typedef|typedef
name|IEventHandler
argument_list|<
name|IInspectable
modifier|*
argument_list|>
name|ContentChangedHandler
typedef|;
end_typedef
begin_define
DECL|macro|RETURN_NULLPTR_IF_FAILED
define|#
directive|define
name|RETURN_NULLPTR_IF_FAILED
parameter_list|(
name|msg
parameter_list|)
value|RETURN_IF_FAILED(msg, return nullptr)
end_define
begin_function
name|QT_BEGIN_NAMESPACE
DECL|function|QWinRTClipboard
name|QWinRTClipboard
operator|::
name|QWinRTClipboard
parameter_list|()
block|{
ifndef|#
directive|ifndef
name|Q_OS_WINPHONE
name|QEventDispatcherWinRT
operator|::
name|runOnXamlThread
argument_list|(
capture|[
name|this
capture|]
parameter_list|()
block|{
name|HRESULT
name|hr
decl_stmt|;
name|hr
operator|=
name|GetActivationFactory
argument_list|(
name|HString
operator|::
name|MakeReference
argument_list|(
name|RuntimeClass_Windows_ApplicationModel_DataTransfer_Clipboard
argument_list|)
operator|.
name|Get
argument_list|()
argument_list|,
operator|&
name|m_nativeClipBoard
argument_list|)
expr_stmt|;
name|Q_ASSERT_SUCCEEDED
argument_list|(
name|hr
argument_list|)
expr_stmt|;
name|EventRegistrationToken
name|tok
decl_stmt|;
name|hr
operator|=
name|m_nativeClipBoard
operator|->
name|add_ContentChanged
argument_list|(
name|Callback
argument_list|<
name|ContentChangedHandler
argument_list|>
argument_list|(
name|this
argument_list|,
operator|&
name|QWinRTClipboard
operator|::
name|onContentChanged
argument_list|)
operator|.
name|Get
argument_list|()
argument_list|,
operator|&
name|tok
argument_list|)
expr_stmt|;
name|Q_ASSERT_SUCCEEDED
argument_list|(
name|hr
argument_list|)
expr_stmt|;
return|return
name|hr
return|;
block|}
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|// !Q_OS_WINPHONE
block|}
end_function
begin_function
DECL|function|mimeData
name|QMimeData
modifier|*
name|QWinRTClipboard
operator|::
name|mimeData
parameter_list|(
name|QClipboard
operator|::
name|Mode
name|mode
parameter_list|)
block|{
if|if
condition|(
operator|!
name|supportsMode
argument_list|(
name|mode
argument_list|)
condition|)
return|return
literal|nullptr
return|;
ifndef|#
directive|ifndef
name|Q_OS_WINPHONE
name|ComPtr
argument_list|<
name|IDataPackageView
argument_list|>
name|view
decl_stmt|;
name|HRESULT
name|hr
decl_stmt|;
name|hr
operator|=
name|m_nativeClipBoard
operator|->
name|GetContent
argument_list|(
operator|&
name|view
argument_list|)
expr_stmt|;
name|RETURN_NULLPTR_IF_FAILED
argument_list|(
literal|"Could not get clipboard content."
argument_list|)
expr_stmt|;
name|ComPtr
argument_list|<
name|IAsyncOperation
argument_list|<
name|HSTRING
argument_list|>
argument_list|>
name|op
decl_stmt|;
name|HString
name|result
decl_stmt|;
comment|// This throws a security exception (WinRT originate error / 0x40080201.
comment|// Unfortunately there seems to be no way to avoid this, neither
comment|// running on the XAML thread, nor some other way. Stack Overflow
comment|// confirms this problem since Windows (Phone) 8.0.
name|hr
operator|=
name|view
operator|->
name|GetTextAsync
argument_list|(
operator|&
name|op
argument_list|)
expr_stmt|;
name|RETURN_NULLPTR_IF_FAILED
argument_list|(
literal|"Could not get clipboard text."
argument_list|)
expr_stmt|;
name|hr
operator|=
name|QWinRTFunctions
operator|::
name|await
argument_list|(
name|op
argument_list|,
name|result
operator|.
name|GetAddressOf
argument_list|()
argument_list|)
expr_stmt|;
name|RETURN_NULLPTR_IF_FAILED
argument_list|(
literal|"Could not get clipboard text content"
argument_list|)
expr_stmt|;
name|quint32
name|size
decl_stmt|;
specifier|const
name|wchar_t
modifier|*
name|textStr
init|=
name|result
operator|.
name|GetRawBuffer
argument_list|(
operator|&
name|size
argument_list|)
decl_stmt|;
name|QString
name|text
init|=
name|QString
operator|::
name|fromWCharArray
argument_list|(
name|textStr
argument_list|,
name|size
argument_list|)
decl_stmt|;
name|text
operator|.
name|replace
argument_list|(
name|QLatin1String
argument_list|(
literal|"\r\n"
argument_list|)
argument_list|,
name|QLatin1String
argument_list|(
literal|"\n"
argument_list|)
argument_list|)
expr_stmt|;
name|m_mimeData
operator|.
name|setText
argument_list|(
name|text
argument_list|)
expr_stmt|;
return|return
operator|&
name|m_mimeData
return|;
else|#
directive|else
comment|// Q_OS_WINPHONE
return|return
name|QPlatformClipboard
operator|::
name|mimeData
argument_list|(
name|mode
argument_list|)
return|;
endif|#
directive|endif
comment|// Q_OS_WINPHONE
block|}
end_function
begin_comment
comment|// Inspired by QWindowsMimeText::convertFromMime
end_comment
begin_function
DECL|function|convertToWindowsLineEnding
specifier|inline
name|QString
name|convertToWindowsLineEnding
parameter_list|(
specifier|const
name|QString
modifier|&
name|text
parameter_list|)
block|{
specifier|const
name|QChar
modifier|*
name|u
init|=
name|text
operator|.
name|unicode
argument_list|()
decl_stmt|;
name|QString
name|res
decl_stmt|;
specifier|const
name|int
name|s
init|=
name|text
operator|.
name|length
argument_list|()
decl_stmt|;
name|int
name|maxsize
init|=
name|s
operator|+
name|s
operator|/
literal|40
operator|+
literal|3
decl_stmt|;
name|res
operator|.
name|resize
argument_list|(
name|maxsize
argument_list|)
expr_stmt|;
name|int
name|ri
init|=
literal|0
decl_stmt|;
name|bool
name|cr
init|=
literal|false
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
name|s
condition|;
operator|++
name|i
control|)
block|{
if|if
condition|(
operator|*
name|u
operator|==
name|QLatin1Char
argument_list|(
literal|'\r'
argument_list|)
condition|)
name|cr
operator|=
literal|true
expr_stmt|;
else|else
block|{
if|if
condition|(
operator|*
name|u
operator|==
name|QLatin1Char
argument_list|(
literal|'\n'
argument_list|)
operator|&&
operator|!
name|cr
condition|)
name|res
index|[
name|ri
operator|++
index|]
operator|=
name|QLatin1Char
argument_list|(
literal|'\r'
argument_list|)
expr_stmt|;
name|cr
operator|=
literal|false
expr_stmt|;
block|}
name|res
index|[
name|ri
operator|++
index|]
operator|=
operator|*
name|u
expr_stmt|;
if|if
condition|(
name|ri
operator|+
literal|3
operator|>=
name|maxsize
condition|)
block|{
name|maxsize
operator|+=
name|maxsize
operator|/
literal|4
expr_stmt|;
name|res
operator|.
name|resize
argument_list|(
name|maxsize
argument_list|)
expr_stmt|;
block|}
operator|++
name|u
expr_stmt|;
block|}
name|res
operator|.
name|truncate
argument_list|(
name|ri
argument_list|)
expr_stmt|;
return|return
name|res
return|;
block|}
end_function
begin_function
DECL|function|setMimeData
name|void
name|QWinRTClipboard
operator|::
name|setMimeData
parameter_list|(
name|QMimeData
modifier|*
name|data
parameter_list|,
name|QClipboard
operator|::
name|Mode
name|mode
parameter_list|)
block|{
if|if
condition|(
operator|!
name|supportsMode
argument_list|(
name|mode
argument_list|)
condition|)
return|return;
ifndef|#
directive|ifndef
name|Q_OS_WINPHONE
specifier|const
name|QString
name|text
init|=
name|data
operator|->
name|text
argument_list|()
decl_stmt|;
name|HRESULT
name|hr
init|=
name|QEventDispatcherWinRT
operator|::
name|runOnXamlThread
argument_list|(
capture|[
name|this
capture|,
name|text
capture|]
parameter_list|()
block|{
name|HRESULT
name|hr
decl_stmt|;
name|ComPtr
argument_list|<
name|IDataPackage
argument_list|>
name|package
decl_stmt|;
name|hr
operator|=
name|RoActivateInstance
argument_list|(
name|HString
operator|::
name|MakeReference
argument_list|(
name|RuntimeClass_Windows_ApplicationModel_DataTransfer_DataPackage
argument_list|)
operator|.
name|Get
argument_list|()
argument_list|,
operator|&
name|package
argument_list|)
expr_stmt|;
specifier|const
name|QString
name|nativeString
type|=
name|convertToWindowsLineEnding
type|(
name|text
decl_stmt|);
name|HStringReference
name|textRef
type|(reinterpret_cast
type|<
name|LPCWSTR
type|>(
name|nativeString
operator|.
name|utf16
type|(
decl_stmt|)
block|)
argument_list|,
name|nativeString
operator|.
name|length
argument_list|()
argument_list|)
decl_stmt|;
name|hr
operator|=
name|package
operator|->
name|SetText
argument_list|(
name|textRef
operator|.
name|Get
argument_list|()
argument_list|)
expr_stmt|;
name|RETURN_HR_IF_FAILED
argument_list|(
literal|"Could not set text to clipboard data package."
argument_list|)
expr_stmt|;
name|hr
operator|=
name|m_nativeClipBoard
operator|->
name|SetContent
argument_list|(
name|package
operator|.
name|Get
argument_list|()
argument_list|)
expr_stmt|;
name|RETURN_HR_IF_FAILED
argument_list|(
literal|"Could not set clipboard content."
argument_list|)
expr_stmt|;
return|return
name|S_OK
return|;
block|}
end_function
begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt
begin_expr_stmt
name|RETURN_VOID_IF_FAILED
argument_list|(
literal|"Could not set clipboard text."
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|emitChanged
argument_list|(
name|mode
argument_list|)
expr_stmt|;
end_expr_stmt
begin_else
else|#
directive|else
end_else
begin_comment
comment|// Q_OS_WINPHONE
end_comment
begin_expr_stmt
name|QPlatformClipboard
operator|::
name|setMimeData
argument_list|(
name|data
argument_list|,
name|mode
argument_list|)
expr_stmt|;
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// Q_OS_WINPHONE
end_comment
begin_macro
unit|}  bool
DECL|function|supportsMode
name|QWinRTClipboard
end_macro
begin_expr_stmt
DECL|function|supportsMode
operator|::
name|supportsMode
operator|(
name|QClipboard
operator|::
name|Mode
name|mode
operator|)
specifier|const
block|{
ifndef|#
directive|ifndef
name|Q_OS_WINPHONE
return|return
name|mode
operator|==
name|QClipboard
operator|::
name|Clipboard
return|;
end_expr_stmt
begin_else
else|#
directive|else
end_else
begin_return
return|return
name|QPlatformClipboard
operator|::
name|supportsMode
argument_list|(
name|mode
argument_list|)
return|;
end_return
begin_endif
endif|#
directive|endif
end_endif
begin_macro
unit|}  HRESULT
DECL|function|onContentChanged
name|QWinRTClipboard
end_macro
begin_expr_stmt
DECL|function|onContentChanged
operator|::
name|onContentChanged
operator|(
name|IInspectable
operator|*
operator|,
name|IInspectable
operator|*
operator|)
block|{
name|emitChanged
argument_list|(
name|QClipboard
operator|::
name|Clipboard
argument_list|)
block|;
return|return
name|S_OK
return|;
block|}
end_expr_stmt
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
