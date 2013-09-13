begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QEGLFSBACKINGSTORE_H
end_ifndef
begin_define
DECL|macro|QEGLFSBACKINGSTORE_H
define|#
directive|define
name|QEGLFSBACKINGSTORE_H
end_define
begin_include
include|#
directive|include
file|<qpa/qplatformbackingstore.h>
end_include
begin_include
include|#
directive|include
file|<QImage>
end_include
begin_include
include|#
directive|include
file|<QRegion>
end_include
begin_include
include|#
directive|include
file|<QTimer>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QOpenGLContext
name|class
name|QOpenGLContext
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QOpenGLPaintDevice
name|class
name|QOpenGLPaintDevice
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QOpenGLShaderProgram
name|class
name|QOpenGLShaderProgram
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QEglFSWindow
name|class
name|QEglFSWindow
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QEglFSCompositor
range|:
name|public
name|QObject
block|{
name|Q_OBJECT
name|public
operator|:
name|QEglFSCompositor
argument_list|()
block|;
name|void
name|schedule
argument_list|(
name|QEglFSWindow
operator|*
name|rootWindow
argument_list|)
block|;
specifier|static
name|QEglFSCompositor
operator|*
name|instance
argument_list|()
block|;
name|private
name|slots
operator|:
name|void
name|renderAll
argument_list|()
block|;
name|private
operator|:
name|void
name|render
argument_list|(
name|QEglFSWindow
operator|*
name|window
argument_list|,
name|QEglFSWindow
operator|*
name|rootWindow
argument_list|)
block|;
name|QEglFSWindow
operator|*
name|m_rootWindow
block|;
name|QTimer
name|m_updateTimer
block|; }
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QEglFSBackingStore
range|:
name|public
name|QPlatformBackingStore
block|{
name|public
operator|:
name|QEglFSBackingStore
argument_list|(
name|QWindow
operator|*
name|window
argument_list|)
block|;
operator|~
name|QEglFSBackingStore
argument_list|()
block|;
name|QPaintDevice
operator|*
name|paintDevice
argument_list|()
block|;
name|void
name|beginPaint
argument_list|(
specifier|const
name|QRegion
operator|&
argument_list|)
block|;
name|void
name|flush
argument_list|(
name|QWindow
operator|*
name|window
argument_list|,
specifier|const
name|QRegion
operator|&
name|region
argument_list|,
specifier|const
name|QPoint
operator|&
name|offset
argument_list|)
block|;
name|void
name|resize
argument_list|(
specifier|const
name|QSize
operator|&
name|size
argument_list|,
specifier|const
name|QRegion
operator|&
name|staticContents
argument_list|)
block|;
name|private
operator|:
name|void
name|makeCurrent
argument_list|()
block|;
specifier|static
name|QOpenGLContext
operator|*
name|makeRootCurrent
argument_list|(
name|QEglFSWindow
operator|*
name|rootWin
argument_list|)
block|;
name|void
name|updateTexture
argument_list|()
block|;
name|QEglFSWindow
operator|*
name|m_window
block|;
name|QOpenGLContext
operator|*
name|m_context
block|;
name|QImage
name|m_image
block|;
name|uint
name|m_texture
block|;
name|QRegion
name|m_dirty
block|;
name|QOpenGLShaderProgram
operator|*
name|m_program
block|;
name|int
name|m_vertexCoordEntry
block|;
name|int
name|m_textureCoordEntry
block|;
name|friend
name|class
name|QEglFSCompositor
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
comment|// QEGLFSBACKINGSTORE_H
end_comment
end_unit
