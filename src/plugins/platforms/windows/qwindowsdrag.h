begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QWINDOWSDRAG_H
end_ifndef
begin_define
DECL|macro|QWINDOWSDRAG_H
define|#
directive|define
name|QWINDOWSDRAG_H
end_define
begin_include
include|#
directive|include
file|"qwindowsinternalmimedata.h"
end_include
begin_include
include|#
directive|include
file|<qpa/qplatformdrag.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/QPixmap>
end_include
begin_struct_decl
struct_decl|struct
name|IDropTargetHelper
struct_decl|;
end_struct_decl
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
name|class
name|QWindowsDropMimeData
range|:
name|public
name|QWindowsInternalMimeData
block|{
name|public
operator|:
name|QWindowsDropMimeData
argument_list|()
block|{}
name|IDataObject
operator|*
name|retrieveDataObject
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|; }
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QWindowsOleDropTarget
range|:
name|public
name|IDropTarget
block|{
name|public
operator|:
name|explicit
name|QWindowsOleDropTarget
argument_list|(
name|QWindow
operator|*
name|w
argument_list|)
block|;
name|virtual
operator|~
name|QWindowsOleDropTarget
argument_list|()
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
comment|// IDropTarget methods
name|STDMETHOD
argument_list|(
argument|DragEnter
argument_list|)
operator|(
name|LPDATAOBJECT
name|pDataObj
expr|,
name|DWORD
name|grfKeyState
expr|,
name|POINTL
name|pt
expr|,
name|LPDWORD
name|pdwEffect
operator|)
block|;
name|STDMETHOD
argument_list|(
argument|DragOver
argument_list|)
operator|(
name|DWORD
name|grfKeyState
expr|,
name|POINTL
name|pt
expr|,
name|LPDWORD
name|pdwEffect
operator|)
block|;
name|STDMETHOD
argument_list|(
name|DragLeave
argument_list|)
argument_list|()
block|;
name|STDMETHOD
argument_list|(
argument|Drop
argument_list|)
operator|(
name|LPDATAOBJECT
name|pDataObj
expr|,
name|DWORD
name|grfKeyState
expr|,
name|POINTL
name|pt
expr|,
name|LPDWORD
name|pdwEffect
operator|)
block|;
name|private
operator|:
name|void
name|handleDrag
argument_list|(
argument|QWindow *window
argument_list|,
argument|DWORD grfKeyState
argument_list|,
argument|const QPoint&
argument_list|,
argument|LPDWORD pdwEffect
argument_list|)
block|;
name|ULONG
name|m_refs
block|;
name|QWindow
operator|*
specifier|const
name|m_window
block|;
name|QRect
name|m_answerRect
block|;
name|QPoint
name|m_lastPoint
block|;
name|DWORD
name|m_chosenEffect
block|;
name|DWORD
name|m_lastKeyState
block|; }
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QWindowsDrag
range|:
name|public
name|QPlatformDrag
block|{
name|public
operator|:
name|QWindowsDrag
argument_list|()
block|;
name|virtual
operator|~
name|QWindowsDrag
argument_list|()
block|;
name|QMimeData
operator|*
name|platformDropData
argument_list|()
name|Q_DECL_OVERRIDE
block|{
return|return
operator|&
name|m_dropData
return|;
block|}
name|Qt
operator|::
name|DropAction
name|drag
argument_list|(
argument|QDrag *drag
argument_list|)
name|Q_DECL_OVERRIDE
block|;
specifier|static
name|QWindowsDrag
operator|*
name|instance
argument_list|()
block|;
name|IDataObject
operator|*
name|dropDataObject
argument_list|()
specifier|const
block|{
return|return
name|m_dropDataObject
return|;
block|}
name|void
name|setDropDataObject
argument_list|(
argument|IDataObject *dataObject
argument_list|)
block|{
name|m_dropDataObject
operator|=
name|dataObject
block|; }
name|void
name|releaseDropDataObject
argument_list|()
block|;
name|QMimeData
operator|*
name|dropData
argument_list|()
block|;
name|IDropTargetHelper
operator|*
name|dropHelper
argument_list|()
block|;
name|QPixmap
name|defaultCursor
argument_list|(
argument|Qt::DropAction action
argument_list|)
specifier|const
block|;
name|private
operator|:
name|QWindowsDropMimeData
name|m_dropData
block|;
name|IDataObject
operator|*
name|m_dropDataObject
block|;
name|IDropTargetHelper
operator|*
name|m_cachedDropTargetHelper
block|;
name|mutable
name|QPixmap
name|m_copyDragCursor
block|;
name|mutable
name|QPixmap
name|m_moveDragCursor
block|;
name|mutable
name|QPixmap
name|m_linkDragCursor
block|;
name|mutable
name|QPixmap
name|m_ignoreDragCursor
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
comment|// QWINDOWSDRAG_H
end_comment
end_unit
