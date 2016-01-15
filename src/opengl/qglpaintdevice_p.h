begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the QtOpenGL module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QGLPAINTDEVICE_P_H
end_ifndef
begin_define
DECL|macro|QGLPAINTDEVICE_P_H
define|#
directive|define
name|QGLPAINTDEVICE_P_H
end_define
begin_comment
comment|//
end_comment
begin_comment
comment|//  W A R N I N G
end_comment
begin_comment
comment|//  -------------
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|// This file is not part of the Qt API.  It exists for the convenience
end_comment
begin_comment
comment|// of the Qt OpenGL module.  This header file may change from
end_comment
begin_comment
comment|// version to version without notice, or even be removed.
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|// We mean it.
end_comment
begin_comment
comment|//
end_comment
begin_include
include|#
directive|include
file|<qpaintdevice.h>
end_include
begin_include
include|#
directive|include
file|<QtOpenGL/qgl.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
name|class
name|Q_OPENGL_EXPORT
name|QGLPaintDevice
range|:
name|public
name|QPaintDevice
block|{
name|public
operator|:
name|QGLPaintDevice
argument_list|()
block|;
name|virtual
operator|~
name|QGLPaintDevice
argument_list|()
block|;
name|int
name|devType
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|{
return|return
name|QInternal
operator|::
name|OpenGL
return|;
block|}
name|virtual
name|void
name|beginPaint
argument_list|()
block|;
name|virtual
name|void
name|ensureActiveTarget
argument_list|()
block|;
name|virtual
name|void
name|endPaint
argument_list|()
block|;
name|virtual
name|QGLContext
operator|*
name|context
argument_list|()
specifier|const
operator|=
literal|0
block|;
name|virtual
name|QGLFormat
name|format
argument_list|()
specifier|const
block|;
name|virtual
name|QSize
name|size
argument_list|()
specifier|const
operator|=
literal|0
block|;
name|virtual
name|bool
name|alphaRequested
argument_list|()
specifier|const
block|;
name|virtual
name|bool
name|isFlipped
argument_list|()
specifier|const
block|;
comment|// returns the QGLPaintDevice for the given QPaintDevice
specifier|static
name|QGLPaintDevice
operator|*
name|getDevice
argument_list|(
name|QPaintDevice
operator|*
argument_list|)
block|;
name|protected
operator|:
name|int
name|metric
argument_list|(
argument|QPaintDevice::PaintDeviceMetric metric
argument_list|)
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|GLuint
name|m_previousFBO
block|;
name|GLuint
name|m_thisFBO
block|; }
decl_stmt|;
end_decl_stmt
begin_comment
comment|// Wraps a QGLWidget
end_comment
begin_decl_stmt
DECL|variable|QGLWidget
name|class
name|QGLWidget
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_OPENGL_EXPORT
name|QGLWidgetGLPaintDevice
range|:
name|public
name|QGLPaintDevice
block|{
name|public
operator|:
name|QGLWidgetGLPaintDevice
argument_list|()
block|;
name|virtual
name|QPaintEngine
operator|*
name|paintEngine
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
comment|// QGLWidgets need to do swapBufers in endPaint:
name|virtual
name|void
name|beginPaint
argument_list|()
name|Q_DECL_OVERRIDE
block|;
name|virtual
name|void
name|endPaint
argument_list|()
name|Q_DECL_OVERRIDE
block|;
name|virtual
name|QSize
name|size
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|virtual
name|QGLContext
operator|*
name|context
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|void
name|setWidget
argument_list|(
name|QGLWidget
operator|*
argument_list|)
block|;
name|private
operator|:
name|friend
name|class
name|QGLWidget
block|;
name|QGLWidget
operator|*
name|glWidget
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
comment|// QGLPAINTDEVICE_P_H
end_comment
end_unit
