begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QWINDOWSOLE_H
end_ifndef
begin_define
DECL|macro|QWINDOWSOLE_H
define|#
directive|define
name|QWINDOWSOLE_H
end_define
begin_include
include|#
directive|include
file|"qtwindows_additional.h"
end_include
begin_include
include|#
directive|include
file|<QtCore/QObject>
end_include
begin_include
include|#
directive|include
file|<QtCore/QMap>
end_include
begin_include
include|#
directive|include
file|<QtCore/QPoint>
end_include
begin_include
include|#
directive|include
file|<QtCore/QPointer>
end_include
begin_include
include|#
directive|include
file|<QtCore/QVector>
end_include
begin_include
include|#
directive|include
file|<QtCore/QRect>
end_include
begin_include
include|#
directive|include
file|<objidl.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QMimeData
name|class
name|QMimeData
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QWindow
name|class
name|QWindow
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QWindowsOleDataObject
range|:
name|public
name|IDataObject
block|{
name|public
operator|:
name|explicit
name|QWindowsOleDataObject
argument_list|(
name|QMimeData
operator|*
name|mimeData
argument_list|)
block|;
name|virtual
operator|~
name|QWindowsOleDataObject
argument_list|()
block|;
name|void
name|releaseQt
argument_list|()
block|;
name|QMimeData
operator|*
name|mimeData
argument_list|()
specifier|const
block|;
name|DWORD
name|reportedPerformedEffect
argument_list|()
specifier|const
block|;
comment|// IUnknown methods
name|STDMETHOD
argument_list|(
argument|QueryInterface
argument_list|)
operator|(
name|REFIID
name|riid
expr|,
name|void
name|FAR
operator|*
name|FAR
operator|*
name|ppvObj
operator|)
block|;
name|STDMETHOD_
argument_list|(
name|ULONG
argument_list|,
name|AddRef
argument_list|)
argument_list|(
name|void
argument_list|)
block|;
name|STDMETHOD_
argument_list|(
name|ULONG
argument_list|,
name|Release
argument_list|)
argument_list|(
name|void
argument_list|)
block|;
comment|// IDataObject methods
name|STDMETHOD
argument_list|(
argument|GetData
argument_list|)
operator|(
name|LPFORMATETC
name|pformatetcIn
expr|,
name|LPSTGMEDIUM
name|pmedium
operator|)
block|;
name|STDMETHOD
argument_list|(
argument|GetDataHere
argument_list|)
operator|(
name|LPFORMATETC
name|pformatetc
expr|,
name|LPSTGMEDIUM
name|pmedium
operator|)
block|;
name|STDMETHOD
argument_list|(
argument|QueryGetData
argument_list|)
operator|(
name|LPFORMATETC
name|pformatetc
operator|)
block|;
name|STDMETHOD
argument_list|(
argument|GetCanonicalFormatEtc
argument_list|)
operator|(
name|LPFORMATETC
name|pformatetc
expr|,
name|LPFORMATETC
name|pformatetcOut
operator|)
block|;
name|STDMETHOD
argument_list|(
argument|SetData
argument_list|)
operator|(
name|LPFORMATETC
name|pformatetc
expr|,
name|STGMEDIUM
name|FAR
operator|*
name|pmedium
expr|,
name|BOOL
name|fRelease
operator|)
block|;
name|STDMETHOD
argument_list|(
argument|EnumFormatEtc
argument_list|)
operator|(
name|DWORD
name|dwDirection
expr|,
name|LPENUMFORMATETC
name|FAR
operator|*
name|ppenumFormatEtc
operator|)
block|;
name|STDMETHOD
argument_list|(
argument|DAdvise
argument_list|)
operator|(
name|FORMATETC
name|FAR
operator|*
name|pFormatetc
expr|,
name|DWORD
name|advf
expr|,
name|LPADVISESINK
name|pAdvSink
expr|,
name|DWORD
name|FAR
operator|*
name|pdwConnection
operator|)
block|;
name|STDMETHOD
argument_list|(
argument|DUnadvise
argument_list|)
operator|(
name|DWORD
name|dwConnection
operator|)
block|;
name|STDMETHOD
argument_list|(
argument|EnumDAdvise
argument_list|)
operator|(
name|LPENUMSTATDATA
name|FAR
operator|*
name|ppenumAdvise
operator|)
block|;
name|private
operator|:
name|ULONG
name|m_refs
block|;
name|QPointer
operator|<
name|QMimeData
operator|>
name|data
block|;
name|int
name|CF_PERFORMEDDROPEFFECT
block|;
name|DWORD
name|performedEffect
block|; }
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QWindowsOleEnumFmtEtc
range|:
name|public
name|IEnumFORMATETC
block|{
name|public
operator|:
name|explicit
name|QWindowsOleEnumFmtEtc
argument_list|(
specifier|const
name|QVector
operator|<
name|FORMATETC
operator|>
operator|&
name|fmtetcs
argument_list|)
block|;
name|explicit
name|QWindowsOleEnumFmtEtc
argument_list|(
specifier|const
name|QVector
operator|<
name|LPFORMATETC
operator|>
operator|&
name|lpfmtetcs
argument_list|)
block|;
name|virtual
operator|~
name|QWindowsOleEnumFmtEtc
argument_list|()
block|;
name|bool
name|isNull
argument_list|()
specifier|const
block|;
comment|// IUnknown methods
name|STDMETHOD
argument_list|(
argument|QueryInterface
argument_list|)
operator|(
name|REFIID
name|riid
expr|,
name|void
name|FAR
operator|*
name|FAR
operator|*
name|ppvObj
operator|)
block|;
name|STDMETHOD_
argument_list|(
name|ULONG
argument_list|,
name|AddRef
argument_list|)
argument_list|(
name|void
argument_list|)
block|;
name|STDMETHOD_
argument_list|(
name|ULONG
argument_list|,
name|Release
argument_list|)
argument_list|(
name|void
argument_list|)
block|;
comment|// IEnumFORMATETC methods
name|STDMETHOD
argument_list|(
argument|Next
argument_list|)
operator|(
name|ULONG
name|celt
expr|,
name|LPFORMATETC
name|rgelt
expr|,
name|ULONG
name|FAR
operator|*
name|pceltFetched
operator|)
block|;
name|STDMETHOD
argument_list|(
argument|Skip
argument_list|)
operator|(
name|ULONG
name|celt
operator|)
block|;
name|STDMETHOD
argument_list|(
name|Reset
argument_list|)
argument_list|(
name|void
argument_list|)
block|;
name|STDMETHOD
argument_list|(
argument|Clone
argument_list|)
operator|(
name|LPENUMFORMATETC
name|FAR
operator|*
name|newEnum
operator|)
block|;
name|private
operator|:
name|bool
name|copyFormatEtc
argument_list|(
argument|LPFORMATETC dest
argument_list|,
argument|LPFORMATETC src
argument_list|)
specifier|const
block|;
name|ULONG
name|m_dwRefs
block|;
name|ULONG
name|m_nIndex
block|;
name|QVector
operator|<
name|LPFORMATETC
operator|>
name|m_lpfmtetcs
block|;
name|bool
name|m_isNull
block|; }
decl_stmt|;
end_decl_stmt
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QWINDOWSOLE_H
end_comment
end_unit
