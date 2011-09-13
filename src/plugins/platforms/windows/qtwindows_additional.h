begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (info@qt.nokia.com) ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QTWINDOWS_ADDITIONAL_H
end_ifndef
begin_define
DECL|macro|QTWINDOWS_ADDITIONAL_H
define|#
directive|define
name|QTWINDOWS_ADDITIONAL_H
end_define
begin_include
include|#
directive|include
file|<QtCore/QtGlobal>
end_include
begin_comment
comment|// get compiler define
end_comment
begin_include
include|#
directive|include
file|<QtCore/qt_windows.h>
end_include
begin_comment
comment|/* Complement the definitions and declarations missing  * when using MinGW or older Windows SDKs. */
end_comment
begin_if
if|#
directive|if
name|defined
argument_list|(
name|Q_CC_MINGW
argument_list|)
end_if
begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|ULW_ALPHA
argument_list|)
end_if
begin_define
DECL|macro|ULW_ALPHA
define|#
directive|define
name|ULW_ALPHA
value|0x00000002
end_define
begin_define
DECL|macro|LWA_ALPHA
define|#
directive|define
name|LWA_ALPHA
value|0x00000002
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// !defined(ULW_ALPHA)
end_comment
begin_define
DECL|macro|SPI_GETFONTSMOOTHINGTYPE
define|#
directive|define
name|SPI_GETFONTSMOOTHINGTYPE
value|0x200A
end_define
begin_define
DECL|macro|FE_FONTSMOOTHINGCLEARTYPE
define|#
directive|define
name|FE_FONTSMOOTHINGCLEARTYPE
value|0x0002
end_define
begin_define
DECL|macro|CLEARTYPE_QUALITY
define|#
directive|define
name|CLEARTYPE_QUALITY
value|5
end_define
begin_define
DECL|macro|CF_DIBV5
define|#
directive|define
name|CF_DIBV5
value|17
end_define
begin_define
DECL|macro|CO_E_NOT_SUPPORTED
define|#
directive|define
name|CO_E_NOT_SUPPORTED
value|_HRESULT_TYPEDEF_(0x80004021L)
end_define
begin_typedef
DECL|struct|tagUPDATELAYEREDWINDOWINFO
typedef|typedef
struct|struct
name|tagUPDATELAYEREDWINDOWINFO
block|{
DECL|member|cbSize
name|DWORD
name|cbSize
decl_stmt|;
DECL|member|hdcDst
name|HDC
name|hdcDst
decl_stmt|;
DECL|member|pptDst
specifier|const
name|POINT
modifier|*
name|pptDst
decl_stmt|;
DECL|member|psize
specifier|const
name|SIZE
modifier|*
name|psize
decl_stmt|;
DECL|member|hdcSrc
name|HDC
name|hdcSrc
decl_stmt|;
DECL|member|pptSrc
specifier|const
name|POINT
modifier|*
name|pptSrc
decl_stmt|;
DECL|member|crKey
name|COLORREF
name|crKey
decl_stmt|;
DECL|member|pblend
specifier|const
name|BLENDFUNCTION
modifier|*
name|pblend
decl_stmt|;
DECL|member|dwFlags
name|DWORD
name|dwFlags
decl_stmt|;
DECL|member|prcDirty
specifier|const
name|RECT
modifier|*
name|prcDirty
decl_stmt|;
block|}
DECL|typedef|UPDATELAYEREDWINDOWINFO
DECL|typedef|PUPDATELAYEREDWINDOWINFO
name|UPDATELAYEREDWINDOWINFO
operator|,
typedef|*
name|PUPDATELAYEREDWINDOWINFO
typedef|;
end_typedef
begin_comment
comment|// OpenGL Pixelformat flags.
end_comment
begin_define
DECL|macro|PFD_SUPPORT_DIRECTDRAW
define|#
directive|define
name|PFD_SUPPORT_DIRECTDRAW
value|0x00002000
end_define
begin_define
DECL|macro|PFD_DIRECT3D_ACCELERATED
define|#
directive|define
name|PFD_DIRECT3D_ACCELERATED
value|0x00004000
end_define
begin_define
DECL|macro|PFD_SUPPORT_COMPOSITION
define|#
directive|define
name|PFD_SUPPORT_COMPOSITION
value|0x00008000
end_define
begin_comment
comment|// IME.
end_comment
begin_define
DECL|macro|IMR_CONFIRMRECONVERTSTRING
define|#
directive|define
name|IMR_CONFIRMRECONVERTSTRING
value|0x0005
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// if defined(Q_CC_MINGW)
end_comment
begin_comment
comment|/* Touch is supported from Windows 7 onwards and data structures  * are present in the Windows SDK's, but not in older MSVC Express  * versions. */
end_comment
begin_if
if|#
directive|if
name|defined
argument_list|(
name|Q_CC_MINGW
argument_list|)
operator|||
operator|!
name|defined
argument_list|(
name|TOUCHEVENTF_MOVE
argument_list|)
end_if
begin_define
DECL|macro|WM_TOUCH
define|#
directive|define
name|WM_TOUCH
value|0x0240
end_define
begin_typedef
DECL|struct|tagTOUCHINPUT
typedef|typedef
struct|struct
name|tagTOUCHINPUT
block|{
DECL|member|x
name|LONG
name|x
decl_stmt|;
DECL|member|y
name|LONG
name|y
decl_stmt|;
DECL|member|hSource
name|HANDLE
name|hSource
decl_stmt|;
DECL|member|dwID
name|DWORD
name|dwID
decl_stmt|;
DECL|member|dwFlags
name|DWORD
name|dwFlags
decl_stmt|;
DECL|member|dwMask
name|DWORD
name|dwMask
decl_stmt|;
DECL|member|dwTime
name|DWORD
name|dwTime
decl_stmt|;
DECL|member|dwExtraInfo
name|ULONG_PTR
name|dwExtraInfo
decl_stmt|;
DECL|member|cxContact
name|DWORD
name|cxContact
decl_stmt|;
DECL|member|cyContact
name|DWORD
name|cyContact
decl_stmt|;
block|}
DECL|typedef|TOUCHINPUT
DECL|typedef|PTOUCHINPUT
name|TOUCHINPUT
operator|,
typedef|*
name|PTOUCHINPUT
typedef|;
end_typedef
begin_typedef
DECL|typedef|PCTOUCHINPUT
typedef|typedef
name|TOUCHINPUT
specifier|const
modifier|*
name|PCTOUCHINPUT
typedef|;
end_typedef
begin_define
DECL|macro|TOUCHEVENTF_MOVE
define|#
directive|define
name|TOUCHEVENTF_MOVE
value|0x0001
end_define
begin_define
DECL|macro|TOUCHEVENTF_DOWN
define|#
directive|define
name|TOUCHEVENTF_DOWN
value|0x0002
end_define
begin_define
DECL|macro|TOUCHEVENTF_UP
define|#
directive|define
name|TOUCHEVENTF_UP
value|0x0004
end_define
begin_define
DECL|macro|TOUCHEVENTF_INRANGE
define|#
directive|define
name|TOUCHEVENTF_INRANGE
value|0x0008
end_define
begin_define
DECL|macro|TOUCHEVENTF_PRIMARY
define|#
directive|define
name|TOUCHEVENTF_PRIMARY
value|0x0010
end_define
begin_define
DECL|macro|TOUCHEVENTF_NOCOALESCE
define|#
directive|define
name|TOUCHEVENTF_NOCOALESCE
value|0x0020
end_define
begin_define
DECL|macro|TOUCHEVENTF_PALM
define|#
directive|define
name|TOUCHEVENTF_PALM
value|0x0080
end_define
begin_define
DECL|macro|TOUCHINPUTMASKF_CONTACTAREA
define|#
directive|define
name|TOUCHINPUTMASKF_CONTACTAREA
value|0x0004
end_define
begin_define
DECL|macro|TOUCHINPUTMASKF_EXTRAINFO
define|#
directive|define
name|TOUCHINPUTMASKF_EXTRAINFO
value|0x0002
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// if defined(Q_CC_MINGW) || !defined(TOUCHEVENTF_MOVE)
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QTWINDOWS_ADDITIONAL_H
end_comment
end_unit
