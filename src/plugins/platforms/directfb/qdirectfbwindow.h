begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QDIRECTFBWINDOW_H
end_ifndef
begin_define
DECL|macro|QDIRECTFBWINDOW_H
define|#
directive|define
name|QDIRECTFBWINDOW_H
end_define
begin_include
include|#
directive|include
file|<qpa/qplatformwindow.h>
end_include
begin_include
include|#
directive|include
file|"qdirectfbconvenience.h"
end_include
begin_include
include|#
directive|include
file|"qdirectfbinput.h"
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
name|class
name|QDirectFbWindow
range|:
name|public
name|QPlatformWindow
block|{
name|public
operator|:
name|QDirectFbWindow
argument_list|(
name|QWindow
operator|*
name|tlw
argument_list|,
name|QDirectFbInput
operator|*
name|inputhandler
argument_list|)
block|;
operator|~
name|QDirectFbWindow
argument_list|()
block|;
name|void
name|setGeometry
argument_list|(
specifier|const
name|QRect
operator|&
name|rect
argument_list|)
block|;
name|void
name|setOpacity
argument_list|(
argument|qreal level
argument_list|)
block|;
name|void
name|setVisible
argument_list|(
argument|bool visible
argument_list|)
block|;
name|void
name|setWindowFlags
argument_list|(
argument|Qt::WindowFlags flags
argument_list|)
block|;
name|bool
name|setKeyboardGrabEnabled
argument_list|(
argument|bool grab
argument_list|)
block|;
name|bool
name|setMouseGrabEnabled
argument_list|(
argument|bool grab
argument_list|)
block|;
name|void
name|raise
argument_list|()
block|;
name|void
name|lower
argument_list|()
block|;
name|WId
name|winId
argument_list|()
specifier|const
block|;
name|virtual
name|void
name|createDirectFBWindow
argument_list|()
block|;
name|IDirectFBWindow
operator|*
name|dfbWindow
argument_list|()
specifier|const
block|;
comment|// helper to get access to DirectFB types
name|IDirectFBSurface
operator|*
name|dfbSurface
argument_list|()
block|;
name|protected
operator|:
name|QDirectFBPointer
operator|<
name|IDirectFBSurface
operator|>
name|m_dfbSurface
block|;
name|QDirectFBPointer
operator|<
name|IDirectFBWindow
operator|>
name|m_dfbWindow
block|;
name|QDirectFbInput
operator|*
name|m_inputHandler
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
comment|// QDIRECTFBWINDOW_H
end_comment
end_unit
