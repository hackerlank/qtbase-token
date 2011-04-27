begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** No Commercial Usage ** This file contains pre-release code and may not be distributed. ** You may use this file in accordance with the terms and conditions ** contained in the Technology Preview License Agreement accompanying ** this package. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights.  These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** If you have questions regarding the use of this file, please contact ** Nokia at qt-info@nokia.com. ** ** ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qguifunctions_wince.h"
end_include
begin_include
include|#
directive|include
file|<shellapi.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qlibrary.h>
end_include
begin_macro
name|QT_USE_NAMESPACE
end_macro
begin_struct
DECL|struct|AygSHINITDLGINFO
struct|struct
name|AygSHINITDLGINFO
block|{
DECL|member|dwMask
name|DWORD
name|dwMask
decl_stmt|;
DECL|member|hDlg
name|HWND
name|hDlg
decl_stmt|;
DECL|member|dwFlags
name|DWORD
name|dwFlags
decl_stmt|;
block|}
struct|;
end_struct
begin_struct
DECL|struct|AygSIPINFO
struct|struct
name|AygSIPINFO
block|{
DECL|member|cbSize
name|DWORD
name|cbSize
decl_stmt|;
DECL|member|fdwFlags
name|DWORD
name|fdwFlags
decl_stmt|;
DECL|member|rcVisibleDesktop
name|RECT
name|rcVisibleDesktop
decl_stmt|;
DECL|member|rcSipRect
name|RECT
name|rcSipRect
decl_stmt|;
DECL|member|dwImDataSize
name|DWORD
name|dwImDataSize
decl_stmt|;
DECL|member|pvImData
name|void
modifier|*
name|pvImData
decl_stmt|;
block|}
struct|;
end_struct
begin_ifndef
ifndef|#
directive|ifndef
name|SHIDIF_CANCELBUTTON
end_ifndef
begin_define
DECL|macro|SHIDIF_CANCELBUTTON
define|#
directive|define
name|SHIDIF_CANCELBUTTON
value|0x0080
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|SHIDIM_FLAGS
end_ifndef
begin_define
DECL|macro|SHIDIM_FLAGS
define|#
directive|define
name|SHIDIM_FLAGS
value|0x0001
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|SHIDIF_DONEBUTTON
end_ifndef
begin_define
DECL|macro|SHIDIF_DONEBUTTON
define|#
directive|define
name|SHIDIF_DONEBUTTON
value|0x0001
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|SHIDIF_SIZEDLGFULLSCREEN
end_ifndef
begin_define
DECL|macro|SHIDIF_SIZEDLGFULLSCREEN
define|#
directive|define
name|SHIDIF_SIZEDLGFULLSCREEN
value|0x0004
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|SHDB_HIDE
end_ifndef
begin_define
DECL|macro|SHDB_HIDE
define|#
directive|define
name|SHDB_HIDE
value|0x0002
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|SHFS_SHOWTASKBAR
end_ifndef
begin_define
DECL|macro|SHFS_SHOWTASKBAR
define|#
directive|define
name|SHFS_SHOWTASKBAR
value|0x0001
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|SHFS_HIDETASKBAR
end_ifndef
begin_define
DECL|macro|SHFS_HIDETASKBAR
define|#
directive|define
name|SHFS_HIDETASKBAR
value|0x0002
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|SHFS_SHOWSIPBUTTON
end_ifndef
begin_define
DECL|macro|SHFS_SHOWSIPBUTTON
define|#
directive|define
name|SHFS_SHOWSIPBUTTON
value|0x0004
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|SHFS_HIDESIPBUTTON
end_ifndef
begin_define
DECL|macro|SHFS_HIDESIPBUTTON
define|#
directive|define
name|SHFS_HIDESIPBUTTON
value|0x0008
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|SHFS_SHOWSTARTICON
end_ifndef
begin_define
DECL|macro|SHFS_SHOWSTARTICON
define|#
directive|define
name|SHFS_SHOWSTARTICON
value|0x0010
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|SHFS_HIDESTARTICON
end_ifndef
begin_define
DECL|macro|SHFS_HIDESTARTICON
define|#
directive|define
name|SHFS_HIDESTARTICON
value|0x0020
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|SIPF_OFF
end_ifndef
begin_define
DECL|macro|SIPF_OFF
define|#
directive|define
name|SIPF_OFF
value|0x00000000
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|SIPF_ON
end_ifndef
begin_define
DECL|macro|SIPF_ON
define|#
directive|define
name|SIPF_ON
value|0x00000001
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|SPI_SETSIPINFO
end_ifndef
begin_define
DECL|macro|SPI_SETSIPINFO
define|#
directive|define
name|SPI_SETSIPINFO
value|224
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|SPI_GETSIPINFO
end_ifndef
begin_define
DECL|macro|SPI_GETSIPINFO
define|#
directive|define
name|SPI_GETSIPINFO
value|225
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|SPI_GETPLATFORMTYPE
end_ifndef
begin_define
DECL|macro|SPI_GETPLATFORMTYPE
define|#
directive|define
name|SPI_GETPLATFORMTYPE
value|257
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_typedef
DECL|typedef|AygInitDialog
typedef|typedef
name|BOOL
function_decl|(
modifier|*
name|AygInitDialog
function_decl|)
parameter_list|(
name|AygSHINITDLGINFO
modifier|*
parameter_list|)
function_decl|;
end_typedef
begin_typedef
DECL|typedef|AygFullScreen
typedef|typedef
name|BOOL
function_decl|(
modifier|*
name|AygFullScreen
function_decl|)
parameter_list|(
name|HWND
parameter_list|,
name|DWORD
parameter_list|)
function_decl|;
end_typedef
begin_typedef
DECL|typedef|AygSHSipInfo
typedef|typedef
name|BOOL
function_decl|(
modifier|*
name|AygSHSipInfo
function_decl|)
parameter_list|(
name|UINT
parameter_list|,
name|UINT
parameter_list|,
name|PVOID
parameter_list|,
name|UINT
parameter_list|)
function_decl|;
end_typedef
begin_typedef
DECL|typedef|AygSHDoneButton
typedef|typedef
name|BOOL
function_decl|(
modifier|*
name|AygSHDoneButton
function_decl|)
parameter_list|(
name|HWND
parameter_list|,
name|DWORD
parameter_list|)
function_decl|;
end_typedef
begin_decl_stmt
DECL|variable|ptrAygInitDialog
specifier|static
name|AygInitDialog
name|ptrAygInitDialog
init|=
literal|0
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|ptrAygFullScreen
specifier|static
name|AygFullScreen
name|ptrAygFullScreen
init|=
literal|0
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|ptrAygSHSipInfo
specifier|static
name|AygSHSipInfo
name|ptrAygSHSipInfo
init|=
literal|0
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|ptrAygSHDoneButton
specifier|static
name|AygSHDoneButton
name|ptrAygSHDoneButton
init|=
literal|0
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|aygResolved
specifier|static
name|bool
name|aygResolved
init|=
literal|false
decl_stmt|;
end_decl_stmt
begin_function
DECL|function|resolveAygLibs
specifier|static
name|void
name|resolveAygLibs
parameter_list|()
block|{
if|if
condition|(
operator|!
name|aygResolved
condition|)
block|{
name|aygResolved
operator|=
literal|true
expr_stmt|;
name|QLibrary
name|ayglib
argument_list|(
name|QLatin1String
argument_list|(
literal|"aygshell"
argument_list|)
argument_list|)
decl_stmt|;
name|ptrAygInitDialog
operator|=
operator|(
name|AygInitDialog
operator|)
name|ayglib
operator|.
name|resolve
argument_list|(
literal|"SHInitDialog"
argument_list|)
expr_stmt|;
name|ptrAygFullScreen
operator|=
operator|(
name|AygFullScreen
operator|)
name|ayglib
operator|.
name|resolve
argument_list|(
literal|"SHFullScreen"
argument_list|)
expr_stmt|;
name|ptrAygSHSipInfo
operator|=
operator|(
name|AygSHSipInfo
operator|)
name|ayglib
operator|.
name|resolve
argument_list|(
literal|"SHSipInfo"
argument_list|)
expr_stmt|;
name|ptrAygSHDoneButton
operator|=
operator|(
name|AygSHDoneButton
operator|)
name|ayglib
operator|.
name|resolve
argument_list|(
literal|"SHDoneButton"
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|qt_wince_GetDIBits
name|int
name|qt_wince_GetDIBits
parameter_list|(
name|HDC
comment|/*hdc*/
parameter_list|,
name|HBITMAP
name|hSourceBitmap
parameter_list|,
name|uint
parameter_list|,
name|uint
parameter_list|,
name|LPVOID
name|lpvBits
parameter_list|,
name|LPBITMAPINFO
parameter_list|,
name|uint
parameter_list|)
block|{
if|if
condition|(
operator|!
name|lpvBits
condition|)
block|{
name|qWarning
argument_list|(
literal|"::GetDIBits(), lpvBits NULL"
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
name|BITMAP
name|bm
decl_stmt|;
name|GetObject
argument_list|(
name|hSourceBitmap
argument_list|,
sizeof|sizeof
argument_list|(
name|BITMAP
argument_list|)
argument_list|,
operator|&
name|bm
argument_list|)
expr_stmt|;
name|bm
operator|.
name|bmHeight
operator|=
name|qAbs
argument_list|(
name|bm
operator|.
name|bmHeight
argument_list|)
expr_stmt|;
name|HBITMAP
name|hTargetBitmap
decl_stmt|;
name|void
modifier|*
name|pixels
decl_stmt|;
name|BITMAPINFO
name|dibInfo
decl_stmt|;
name|memset
argument_list|(
operator|&
name|dibInfo
argument_list|,
literal|0
argument_list|,
sizeof|sizeof
argument_list|(
name|dibInfo
argument_list|)
argument_list|)
expr_stmt|;
name|dibInfo
operator|.
name|bmiHeader
operator|.
name|biBitCount
operator|=
literal|32
expr_stmt|;
name|dibInfo
operator|.
name|bmiHeader
operator|.
name|biClrImportant
operator|=
literal|0
expr_stmt|;
name|dibInfo
operator|.
name|bmiHeader
operator|.
name|biClrUsed
operator|=
literal|0
expr_stmt|;
name|dibInfo
operator|.
name|bmiHeader
operator|.
name|biCompression
operator|=
name|BI_RGB
expr_stmt|;
empty_stmt|;
name|dibInfo
operator|.
name|bmiHeader
operator|.
name|biHeight
operator|=
operator|-
name|bm
operator|.
name|bmHeight
expr_stmt|;
name|dibInfo
operator|.
name|bmiHeader
operator|.
name|biWidth
operator|=
name|bm
operator|.
name|bmWidth
expr_stmt|;
name|dibInfo
operator|.
name|bmiHeader
operator|.
name|biPlanes
operator|=
literal|1
expr_stmt|;
name|dibInfo
operator|.
name|bmiHeader
operator|.
name|biSize
operator|=
sizeof|sizeof
argument_list|(
name|BITMAPINFOHEADER
argument_list|)
expr_stmt|;
name|dibInfo
operator|.
name|bmiHeader
operator|.
name|biSizeImage
operator|=
name|bm
operator|.
name|bmWidth
operator|*
name|bm
operator|.
name|bmHeight
operator|*
literal|4
expr_stmt|;
name|HDC
name|displayDC
init|=
name|GetDC
argument_list|(
name|NULL
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|displayDC
condition|)
block|{
name|qWarning
argument_list|(
literal|"::GetDIBits(), failed to GetDC"
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
name|int
name|ret
init|=
name|bm
operator|.
name|bmHeight
decl_stmt|;
name|hTargetBitmap
operator|=
name|CreateDIBSection
argument_list|(
name|displayDC
argument_list|,
operator|(
specifier|const
name|BITMAPINFO
operator|*
operator|)
operator|&
name|dibInfo
argument_list|,
name|DIB_RGB_COLORS
argument_list|,
operator|(
name|void
operator|*
operator|*
operator|)
operator|&
name|pixels
argument_list|,
name|NULL
argument_list|,
literal|0
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|hTargetBitmap
condition|)
block|{
name|qWarning
argument_list|(
literal|"::GetDIBits(), failed to CreateDIBSection"
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
name|HDC
name|hdcSrc
init|=
name|CreateCompatibleDC
argument_list|(
name|displayDC
argument_list|)
decl_stmt|;
name|HDC
name|hdcDst
init|=
name|CreateCompatibleDC
argument_list|(
name|displayDC
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
operator|(
name|hdcDst
operator|&&
name|hdcSrc
operator|)
condition|)
block|{
name|qWarning
argument_list|(
literal|"::GetDIBits(), failed to CreateCompatibleDC"
argument_list|)
expr_stmt|;
name|ret
operator|=
literal|0
expr_stmt|;
block|}
name|HBITMAP
name|hOldBitmap1
init|=
operator|(
name|HBITMAP
operator|)
name|SelectObject
argument_list|(
name|hdcSrc
argument_list|,
name|hSourceBitmap
argument_list|)
decl_stmt|;
name|HBITMAP
name|hOldBitmap2
init|=
operator|(
name|HBITMAP
operator|)
name|SelectObject
argument_list|(
name|hdcDst
argument_list|,
name|hTargetBitmap
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
operator|(
name|hOldBitmap1
operator|&&
name|hOldBitmap2
operator|)
condition|)
block|{
name|qWarning
argument_list|(
literal|"::GetDIBits(), failed to SelectObject for bitmaps"
argument_list|)
expr_stmt|;
name|ret
operator|=
literal|0
expr_stmt|;
block|}
if|if
condition|(
operator|!
name|BitBlt
argument_list|(
name|hdcDst
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
name|bm
operator|.
name|bmWidth
argument_list|,
name|bm
operator|.
name|bmHeight
argument_list|,
name|hdcSrc
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
name|SRCCOPY
argument_list|)
condition|)
block|{
name|qWarning
argument_list|(
literal|"::GetDIBits(), BitBlt failed"
argument_list|)
expr_stmt|;
name|ret
operator|=
literal|0
expr_stmt|;
block|}
name|SelectObject
argument_list|(
name|hdcSrc
argument_list|,
name|hOldBitmap1
argument_list|)
expr_stmt|;
name|SelectObject
argument_list|(
name|hdcDst
argument_list|,
name|hOldBitmap2
argument_list|)
expr_stmt|;
name|DeleteDC
argument_list|(
name|hdcSrc
argument_list|)
expr_stmt|;
name|DeleteDC
argument_list|(
name|hdcDst
argument_list|)
expr_stmt|;
name|ReleaseDC
argument_list|(
name|NULL
argument_list|,
name|displayDC
argument_list|)
expr_stmt|;
name|memcpy
argument_list|(
name|lpvBits
argument_list|,
name|pixels
argument_list|,
name|dibInfo
operator|.
name|bmiHeader
operator|.
name|biSizeImage
argument_list|)
expr_stmt|;
name|DeleteObject
argument_list|(
name|hTargetBitmap
argument_list|)
expr_stmt|;
return|return
name|ret
return|;
block|}
end_function
begin_function
DECL|function|qt_wince_ShellExecute
name|HINSTANCE
name|qt_wince_ShellExecute
parameter_list|(
name|HWND
name|hwnd
parameter_list|,
name|LPCWSTR
parameter_list|,
name|LPCWSTR
name|file
parameter_list|,
name|LPCWSTR
name|params
parameter_list|,
name|LPCWSTR
name|dir
parameter_list|,
name|int
name|showCmd
parameter_list|)
block|{
name|SHELLEXECUTEINFO
name|info
decl_stmt|;
name|info
operator|.
name|hwnd
operator|=
name|hwnd
expr_stmt|;
name|info
operator|.
name|lpVerb
operator|=
literal|L"Open"
expr_stmt|;
name|info
operator|.
name|lpFile
operator|=
name|file
expr_stmt|;
name|info
operator|.
name|lpParameters
operator|=
name|params
expr_stmt|;
name|info
operator|.
name|lpDirectory
operator|=
name|dir
expr_stmt|;
name|info
operator|.
name|nShow
operator|=
name|showCmd
expr_stmt|;
name|info
operator|.
name|cbSize
operator|=
sizeof|sizeof
argument_list|(
name|info
argument_list|)
expr_stmt|;
name|ShellExecuteEx
argument_list|(
operator|&
name|info
argument_list|)
expr_stmt|;
return|return
name|info
operator|.
name|hInstApp
return|;
block|}
end_function
begin_comment
comment|// Clipboard --------------------------------------------------------
end_comment
begin_function
DECL|function|qt_wince_ChangeClipboardChain
name|BOOL
name|qt_wince_ChangeClipboardChain
parameter_list|(
name|HWND
comment|/*hWndRemove*/
parameter_list|,
name|HWND
comment|/*hWndNewNext*/
parameter_list|)
block|{
return|return
name|FALSE
return|;
block|}
end_function
begin_function
DECL|function|qt_wince_SetClipboardViewer
name|HWND
name|qt_wince_SetClipboardViewer
parameter_list|(
name|HWND
comment|/*hWndNewViewer*/
parameter_list|)
block|{
return|return
name|NULL
return|;
block|}
end_function
begin_comment
comment|// Graphics ---------------------------------------------------------
end_comment
begin_function
DECL|function|qt_wince_PALETTEINDEX
name|COLORREF
name|qt_wince_PALETTEINDEX
parameter_list|(
name|WORD
comment|/*wPaletteIndex*/
parameter_list|)
block|{
return|return
literal|0
return|;
block|}
end_function
begin_comment
comment|// Internal Qt -----------------------------------------------------
end_comment
begin_function
DECL|function|qt_wince_is_platform
name|bool
name|qt_wince_is_platform
parameter_list|(
specifier|const
name|QString
modifier|&
name|platformString
parameter_list|)
block|{
name|wchar_t
name|tszPlatform
index|[
literal|64
index|]
decl_stmt|;
if|if
condition|(
name|SystemParametersInfo
argument_list|(
name|SPI_GETPLATFORMTYPE
argument_list|,
sizeof|sizeof
argument_list|(
name|tszPlatform
argument_list|)
operator|/
sizeof|sizeof
argument_list|(
name|wchar_t
argument_list|)
argument_list|,
name|tszPlatform
argument_list|,
literal|0
argument_list|)
condition|)
if|if
condition|(
literal|0
operator|==
name|_tcsicmp
argument_list|(
cast|reinterpret_cast
argument_list|<
specifier|const
name|wchar_t
operator|*
argument_list|>
argument_list|(
name|platformString
operator|.
name|utf16
argument_list|()
argument_list|)
argument_list|,
name|tszPlatform
argument_list|)
condition|)
return|return
literal|true
return|;
return|return
literal|false
return|;
block|}
end_function
begin_function
DECL|function|qt_wince_get_build
name|int
name|qt_wince_get_build
parameter_list|()
block|{
name|OSVERSIONINFO
name|osvi
decl_stmt|;
name|osvi
operator|.
name|dwOSVersionInfoSize
operator|=
sizeof|sizeof
argument_list|(
name|osvi
argument_list|)
expr_stmt|;
if|if
condition|(
name|GetVersionEx
argument_list|(
operator|&
name|osvi
argument_list|)
condition|)
block|{
return|return
name|osvi
operator|.
name|dwBuildNumber
return|;
block|}
return|return
literal|0
return|;
block|}
end_function
begin_function
DECL|function|qt_wince_get_version
name|int
name|qt_wince_get_version
parameter_list|()
block|{
name|OSVERSIONINFO
name|osvi
decl_stmt|;
name|osvi
operator|.
name|dwOSVersionInfoSize
operator|=
sizeof|sizeof
argument_list|(
name|osvi
argument_list|)
expr_stmt|;
if|if
condition|(
name|GetVersionEx
argument_list|(
operator|&
name|osvi
argument_list|)
condition|)
block|{
return|return
operator|(
name|osvi
operator|.
name|dwMajorVersion
operator|*
literal|10
operator|+
name|osvi
operator|.
name|dwMinorVersion
operator|)
return|;
block|}
return|return
literal|0
return|;
block|}
end_function
begin_function
DECL|function|qt_wince_is_windows_mobile_65
name|bool
name|qt_wince_is_windows_mobile_65
parameter_list|()
block|{
specifier|const
name|DWORD
name|dwFirstWM65BuildNumber
init|=
literal|21139
decl_stmt|;
name|OSVERSIONINFO
name|osvi
decl_stmt|;
name|osvi
operator|.
name|dwOSVersionInfoSize
operator|=
sizeof|sizeof
argument_list|(
name|osvi
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|GetVersionEx
argument_list|(
operator|&
name|osvi
argument_list|)
condition|)
return|return
literal|false
return|;
return|return
name|osvi
operator|.
name|dwMajorVersion
operator|>
literal|5
operator|||
operator|(
name|osvi
operator|.
name|dwMajorVersion
operator|==
literal|5
operator|&&
operator|(
name|osvi
operator|.
name|dwMinorVersion
operator|>
literal|2
operator|||
operator|(
name|osvi
operator|.
name|dwMinorVersion
operator|==
literal|2
operator|&&
name|osvi
operator|.
name|dwBuildNumber
operator|>=
name|dwFirstWM65BuildNumber
operator|)
operator|)
operator|)
return|;
block|}
end_function
begin_function
DECL|function|qt_wince_is_pocket_pc
name|bool
name|qt_wince_is_pocket_pc
parameter_list|()
block|{
return|return
name|qt_wince_is_platform
argument_list|(
name|QString
operator|::
name|fromLatin1
argument_list|(
literal|"PocketPC"
argument_list|)
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|qt_wince_is_smartphone
name|bool
name|qt_wince_is_smartphone
parameter_list|()
block|{
return|return
name|qt_wince_is_platform
argument_list|(
name|QString
operator|::
name|fromLatin1
argument_list|(
literal|"Smartphone"
argument_list|)
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|qt_wince_is_mobile
name|bool
name|qt_wince_is_mobile
parameter_list|()
block|{
return|return
operator|(
name|qt_wince_is_smartphone
argument_list|()
operator|||
name|qt_wince_is_pocket_pc
argument_list|()
operator|)
return|;
block|}
end_function
begin_function
DECL|function|qt_wince_is_high_dpi
name|bool
name|qt_wince_is_high_dpi
parameter_list|()
block|{
if|if
condition|(
operator|!
name|qt_wince_is_pocket_pc
argument_list|()
condition|)
return|return
literal|false
return|;
name|HDC
name|deviceContext
init|=
name|GetDC
argument_list|(
literal|0
argument_list|)
decl_stmt|;
name|int
name|dpi
init|=
name|GetDeviceCaps
argument_list|(
name|deviceContext
argument_list|,
name|LOGPIXELSX
argument_list|)
decl_stmt|;
name|ReleaseDC
argument_list|(
literal|0
argument_list|,
name|deviceContext
argument_list|)
expr_stmt|;
if|if
condition|(
operator|(
name|dpi
operator|<
literal|1000
operator|)
operator|&&
operator|(
name|dpi
operator|>
literal|0
operator|)
condition|)
return|return
name|dpi
operator|>
literal|96
return|;
else|else
return|return
literal|false
return|;
block|}
end_function
begin_function
DECL|function|qt_wince_maximize
name|void
name|qt_wince_maximize
parameter_list|(
name|QWidget
modifier|*
name|widget
parameter_list|)
block|{
name|HWND
name|hwnd
init|=
name|widget
operator|->
name|winId
argument_list|()
decl_stmt|;
if|if
condition|(
name|qt_wince_is_mobile
argument_list|()
condition|)
block|{
name|AygSHINITDLGINFO
name|shidi
decl_stmt|;
name|shidi
operator|.
name|dwMask
operator|=
name|SHIDIM_FLAGS
expr_stmt|;
name|shidi
operator|.
name|hDlg
operator|=
name|hwnd
expr_stmt|;
name|shidi
operator|.
name|dwFlags
operator|=
name|SHIDIF_SIZEDLGFULLSCREEN
expr_stmt|;
if|if
condition|(
name|widget
operator|->
name|windowFlags
argument_list|()
operator|&
name|Qt
operator|::
name|WindowCancelButtonHint
condition|)
name|shidi
operator|.
name|dwFlags
operator||=
name|SHIDIF_CANCELBUTTON
expr_stmt|;
if|if
condition|(
name|widget
operator|->
name|windowFlags
argument_list|()
operator|&
name|Qt
operator|::
name|WindowOkButtonHint
condition|)
name|shidi
operator|.
name|dwFlags
operator||=
name|SHIDIF_DONEBUTTON
expr_stmt|;
if|if
condition|(
operator|!
operator|(
name|widget
operator|->
name|windowFlags
argument_list|()
operator|&
operator|(
name|Qt
operator|::
name|WindowCancelButtonHint
operator||
name|Qt
operator|::
name|WindowOkButtonHint
operator|)
operator|)
condition|)
name|shidi
operator|.
name|dwFlags
operator||=
name|SHIDIF_CANCELBUTTON
expr_stmt|;
name|resolveAygLibs
argument_list|()
expr_stmt|;
if|if
condition|(
name|ptrAygInitDialog
condition|)
name|ptrAygInitDialog
argument_list|(
operator|&
name|shidi
argument_list|)
expr_stmt|;
block|}
else|else
block|{
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
name|MoveWindow
argument_list|(
name|hwnd
argument_list|,
name|r
operator|.
name|top
argument_list|,
name|r
operator|.
name|left
argument_list|,
name|r
operator|.
name|right
operator|-
name|r
operator|.
name|left
argument_list|,
name|r
operator|.
name|bottom
operator|-
name|r
operator|.
name|top
argument_list|,
literal|true
argument_list|)
expr_stmt|;
name|SetWindowLong
argument_list|(
name|hwnd
argument_list|,
name|GWL_EXSTYLE
argument_list|,
name|GetWindowLong
argument_list|(
name|hwnd
argument_list|,
name|GWL_EXSTYLE
argument_list|)
operator||
name|WS_EX_NODRAG
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|qt_wince_unmaximize
name|void
name|qt_wince_unmaximize
parameter_list|(
name|QWidget
modifier|*
name|widget
parameter_list|)
block|{
if|if
condition|(
name|ptrAygSHDoneButton
operator|&&
name|qt_wince_is_mobile
argument_list|()
operator|&&
operator|!
operator|(
name|widget
operator|->
name|windowFlags
argument_list|()
operator|&
operator|(
name|Qt
operator|::
name|WindowCancelButtonHint
operator||
name|Qt
operator|::
name|WindowOkButtonHint
operator|)
operator|)
condition|)
block|{
comment|// Hide the [X] button, we've added in qt_wince_maximize.
name|ptrAygSHDoneButton
argument_list|(
name|widget
operator|->
name|winId
argument_list|()
argument_list|,
name|SHDB_HIDE
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|qt_wince_minimize
name|void
name|qt_wince_minimize
parameter_list|(
name|HWND
name|hwnd
parameter_list|)
block|{
ifdef|#
directive|ifdef
name|Q_OS_WINCE_WM
name|ShowWindow
argument_list|(
name|hwnd
argument_list|,
name|SW_HIDE
argument_list|)
expr_stmt|;
else|#
directive|else
if|if
condition|(
operator|!
name|IsWindowVisible
argument_list|(
name|hwnd
argument_list|)
condition|)
block|{
comment|// Hack for an initial showMinimized.
comment|// Without it, our widget doesn't appear in the task bar.
name|ShowWindow
argument_list|(
name|hwnd
argument_list|,
name|SW_SHOW
argument_list|)
expr_stmt|;
block|}
name|ShowWindow
argument_list|(
name|hwnd
argument_list|,
name|SW_MINIMIZE
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
end_function
begin_function
DECL|function|qt_wince_hide_taskbar
name|void
name|qt_wince_hide_taskbar
parameter_list|(
name|HWND
name|hwnd
parameter_list|)
block|{
if|if
condition|(
name|ptrAygFullScreen
condition|)
name|ptrAygFullScreen
argument_list|(
name|hwnd
argument_list|,
name|SHFS_HIDETASKBAR
operator||
name|SHFS_HIDESIPBUTTON
operator||
name|SHFS_HIDESTARTICON
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|qt_wince_full_screen
name|void
name|qt_wince_full_screen
parameter_list|(
name|HWND
name|hwnd
parameter_list|,
name|bool
name|fullScreen
parameter_list|,
name|UINT
name|swpf
parameter_list|)
block|{
name|resolveAygLibs
argument_list|()
expr_stmt|;
if|if
condition|(
name|fullScreen
condition|)
block|{
name|QRect
name|r
init|=
name|qApp
operator|->
name|desktop
argument_list|()
operator|->
name|screenGeometry
argument_list|(
name|QWidget
operator|::
name|find
argument_list|(
name|hwnd
argument_list|)
argument_list|)
decl_stmt|;
name|SetWindowPos
argument_list|(
name|hwnd
argument_list|,
name|HWND_TOP
argument_list|,
name|r
operator|.
name|left
argument_list|()
argument_list|,
name|r
operator|.
name|top
argument_list|()
argument_list|,
name|r
operator|.
name|width
argument_list|()
argument_list|,
name|r
operator|.
name|height
argument_list|()
argument_list|,
name|swpf
argument_list|)
expr_stmt|;
if|if
condition|(
name|ptrAygFullScreen
condition|)
name|ptrAygFullScreen
argument_list|(
name|hwnd
argument_list|,
name|SHFS_HIDETASKBAR
operator||
name|SHFS_HIDESIPBUTTON
operator||
name|SHFS_HIDESTARTICON
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|qt_wince_is_mobile
argument_list|()
condition|)
block|{
name|HWND
name|handle
init|=
name|FindWindow
argument_list|(
literal|L"HHTaskBar"
argument_list|,
literal|L""
argument_list|)
decl_stmt|;
if|if
condition|(
name|handle
condition|)
block|{
name|ShowWindow
argument_list|(
name|handle
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|EnableWindow
argument_list|(
name|handle
argument_list|,
literal|false
argument_list|)
expr_stmt|;
block|}
block|}
block|}
else|else
block|{
if|if
condition|(
name|ptrAygFullScreen
condition|)
name|ptrAygFullScreen
argument_list|(
name|hwnd
argument_list|,
name|SHFS_SHOWTASKBAR
operator||
name|SHFS_SHOWSIPBUTTON
operator||
name|SHFS_SHOWSTARTICON
argument_list|)
expr_stmt|;
name|SetWindowPos
argument_list|(
name|hwnd
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
name|swpf
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|qt_wince_is_mobile
argument_list|()
condition|)
block|{
name|HWND
name|handle
init|=
name|FindWindow
argument_list|(
literal|L"HHTaskBar"
argument_list|,
literal|L""
argument_list|)
decl_stmt|;
if|if
condition|(
name|handle
condition|)
block|{
name|ShowWindow
argument_list|(
name|handle
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|EnableWindow
argument_list|(
name|handle
argument_list|,
literal|true
argument_list|)
expr_stmt|;
block|}
block|}
block|}
block|}
end_function
begin_function
DECL|function|qt_wince_show_SIP
name|void
name|qt_wince_show_SIP
parameter_list|(
name|bool
name|show
parameter_list|)
block|{
name|resolveAygLibs
argument_list|()
expr_stmt|;
if|if
condition|(
operator|!
name|ptrAygSHSipInfo
condition|)
return|return;
name|AygSIPINFO
name|si
decl_stmt|;
name|memset
argument_list|(
operator|&
name|si
argument_list|,
literal|0
argument_list|,
sizeof|sizeof
argument_list|(
name|si
argument_list|)
argument_list|)
expr_stmt|;
name|si
operator|.
name|cbSize
operator|=
sizeof|sizeof
argument_list|(
name|si
argument_list|)
expr_stmt|;
name|ptrAygSHSipInfo
argument_list|(
name|SPI_GETSIPINFO
argument_list|,
literal|0
argument_list|,
operator|&
name|si
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|si
operator|.
name|cbSize
operator|=
sizeof|sizeof
argument_list|(
name|si
argument_list|)
expr_stmt|;
name|si
operator|.
name|fdwFlags
operator|=
operator|(
name|show
condition|?
name|SIPF_ON
else|:
name|SIPF_OFF
operator|)
expr_stmt|;
name|ptrAygSHSipInfo
argument_list|(
name|SPI_SETSIPINFO
argument_list|,
literal|0
argument_list|,
operator|&
name|si
argument_list|,
literal|0
argument_list|)
expr_stmt|;
block|}
end_function
end_unit
