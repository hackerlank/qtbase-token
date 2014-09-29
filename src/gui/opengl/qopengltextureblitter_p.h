begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2014 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia. For licensing terms and ** conditions see http://qt.digia.com/licensing. For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights. These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QOPENGLTEXTUREBLITTER_P_H
end_ifndef
begin_define
DECL|macro|QOPENGLTEXTUREBLITTER_P_H
define|#
directive|define
name|QOPENGLTEXTUREBLITTER_P_H
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
comment|// This file is not part of the Qt API.  It exists purely as an
end_comment
begin_comment
comment|// implementation detail.  This header file may change from version to
end_comment
begin_comment
comment|// version without notice, or even be removed.
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
file|<QtGui/qopengl.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/QMatrix3x3>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QOpenGLTextureBlitterPrivate
name|class
name|QOpenGLTextureBlitterPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_GUI_EXPORT
name|QOpenGLTextureBlitter
block|{
name|public
label|:
name|QOpenGLTextureBlitter
argument_list|()
expr_stmt|;
operator|~
name|QOpenGLTextureBlitter
argument_list|()
expr_stmt|;
enum|enum
name|Origin
block|{
name|OriginBottomLeft
block|,
name|OriginTopLeft
block|}
enum|;
name|bool
name|create
parameter_list|()
function_decl|;
name|bool
name|isCreated
argument_list|()
specifier|const
expr_stmt|;
name|void
name|destroy
parameter_list|()
function_decl|;
name|void
name|bind
parameter_list|()
function_decl|;
name|void
name|release
parameter_list|()
function_decl|;
name|void
name|setSwizzleRB
parameter_list|(
name|bool
name|swizzle
parameter_list|)
function_decl|;
name|void
name|setOpacity
parameter_list|(
name|float
name|opacity
parameter_list|)
function_decl|;
name|void
name|blit
parameter_list|(
name|GLuint
name|texture
parameter_list|,
specifier|const
name|QMatrix4x4
modifier|&
name|targetTransform
parameter_list|,
name|Origin
name|sourceOrigin
parameter_list|)
function_decl|;
name|void
name|blit
parameter_list|(
name|GLuint
name|texture
parameter_list|,
specifier|const
name|QMatrix4x4
modifier|&
name|targetTransform
parameter_list|,
specifier|const
name|QMatrix3x3
modifier|&
name|sourceTransform
parameter_list|)
function_decl|;
specifier|static
name|QMatrix4x4
name|targetTransform
parameter_list|(
specifier|const
name|QRectF
modifier|&
name|target
parameter_list|,
specifier|const
name|QRect
modifier|&
name|viewport
parameter_list|)
function_decl|;
specifier|static
name|QMatrix3x3
name|sourceTransform
parameter_list|(
specifier|const
name|QRectF
modifier|&
name|subTexture
parameter_list|,
specifier|const
name|QSize
modifier|&
name|textureSize
parameter_list|,
name|Origin
name|origin
parameter_list|)
function_decl|;
name|private
label|:
name|Q_DISABLE_COPY
argument_list|(
name|QOpenGLTextureBlitter
argument_list|)
expr_stmt|;
name|Q_DECLARE_PRIVATE
argument_list|(
name|QOpenGLTextureBlitter
argument_list|)
expr_stmt|;
name|QScopedPointer
operator|<
name|QOpenGLTextureBlitterPrivate
operator|>
name|d_ptr
expr_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|//QOPENGLTEXTUREBLITTER_P_H
end_comment
end_unit
