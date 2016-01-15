begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qopenglcustomshaderstage_p.h"
end_include
begin_include
include|#
directive|include
file|"qopenglengineshadermanager_p.h"
end_include
begin_include
include|#
directive|include
file|"qopenglpaintengine_p.h"
end_include
begin_include
include|#
directive|include
file|<private/qpainter_p.h>
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_class
DECL|class|QOpenGLCustomShaderStagePrivate
class|class
name|QOpenGLCustomShaderStagePrivate
block|{
public|public:
DECL|function|QOpenGLCustomShaderStagePrivate
name|QOpenGLCustomShaderStagePrivate
parameter_list|()
member_init_list|:
name|m_manager
argument_list|(
literal|0
argument_list|)
block|{}
DECL|member|m_manager
name|QPointer
argument_list|<
name|QOpenGLEngineShaderManager
argument_list|>
name|m_manager
decl_stmt|;
DECL|member|m_source
name|QByteArray
name|m_source
decl_stmt|;
block|}
class|;
end_class
begin_constructor
DECL|function|QOpenGLCustomShaderStage
name|QOpenGLCustomShaderStage
operator|::
name|QOpenGLCustomShaderStage
parameter_list|()
member_init_list|:
name|d_ptr
argument_list|(
operator|new
name|QOpenGLCustomShaderStagePrivate
argument_list|)
block|{ }
end_constructor
begin_destructor
DECL|function|~QOpenGLCustomShaderStage
name|QOpenGLCustomShaderStage
operator|::
name|~
name|QOpenGLCustomShaderStage
parameter_list|()
block|{
name|Q_D
argument_list|(
name|QOpenGLCustomShaderStage
argument_list|)
expr_stmt|;
if|if
condition|(
name|d
operator|->
name|m_manager
condition|)
block|{
name|d
operator|->
name|m_manager
operator|->
name|removeCustomStage
argument_list|()
expr_stmt|;
name|d
operator|->
name|m_manager
operator|->
name|sharedShaders
operator|->
name|cleanupCustomStage
argument_list|(
name|this
argument_list|)
expr_stmt|;
block|}
block|}
end_destructor
begin_function
DECL|function|setUniformsDirty
name|void
name|QOpenGLCustomShaderStage
operator|::
name|setUniformsDirty
parameter_list|()
block|{
name|Q_D
argument_list|(
name|QOpenGLCustomShaderStage
argument_list|)
expr_stmt|;
if|if
condition|(
name|d
operator|->
name|m_manager
condition|)
name|d
operator|->
name|m_manager
operator|->
name|setDirty
argument_list|()
expr_stmt|;
comment|// ### Probably a bit overkill!
block|}
end_function
begin_function
DECL|function|setOnPainter
name|bool
name|QOpenGLCustomShaderStage
operator|::
name|setOnPainter
parameter_list|(
name|QPainter
modifier|*
name|p
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QOpenGLCustomShaderStage
argument_list|)
expr_stmt|;
if|if
condition|(
name|p
operator|->
name|paintEngine
argument_list|()
operator|->
name|type
argument_list|()
operator|!=
name|QPaintEngine
operator|::
name|OpenGL2
condition|)
block|{
name|qWarning
argument_list|(
literal|"QOpenGLCustomShaderStage::setOnPainter() - paint engine not OpenGL2"
argument_list|)
expr_stmt|;
return|return
literal|false
return|;
block|}
if|if
condition|(
name|d
operator|->
name|m_manager
condition|)
name|qWarning
argument_list|(
literal|"Custom shader is already set on a painter"
argument_list|)
expr_stmt|;
name|QOpenGL2PaintEngineEx
modifier|*
name|engine
init|=
cast|static_cast
argument_list|<
name|QOpenGL2PaintEngineEx
operator|*
argument_list|>
argument_list|(
name|p
operator|->
name|paintEngine
argument_list|()
argument_list|)
decl_stmt|;
name|d
operator|->
name|m_manager
operator|=
name|QOpenGL2PaintEngineExPrivate
operator|::
name|shaderManagerForEngine
argument_list|(
name|engine
argument_list|)
expr_stmt|;
name|Q_ASSERT
argument_list|(
name|d
operator|->
name|m_manager
argument_list|)
expr_stmt|;
name|d
operator|->
name|m_manager
operator|->
name|setCustomStage
argument_list|(
name|this
argument_list|)
expr_stmt|;
return|return
literal|true
return|;
block|}
end_function
begin_function
DECL|function|removeFromPainter
name|void
name|QOpenGLCustomShaderStage
operator|::
name|removeFromPainter
parameter_list|(
name|QPainter
modifier|*
name|p
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QOpenGLCustomShaderStage
argument_list|)
expr_stmt|;
if|if
condition|(
name|p
operator|->
name|paintEngine
argument_list|()
operator|->
name|type
argument_list|()
operator|!=
name|QPaintEngine
operator|::
name|OpenGL2
condition|)
return|return;
name|QOpenGL2PaintEngineEx
modifier|*
name|engine
init|=
cast|static_cast
argument_list|<
name|QOpenGL2PaintEngineEx
operator|*
argument_list|>
argument_list|(
name|p
operator|->
name|paintEngine
argument_list|()
argument_list|)
decl_stmt|;
name|d
operator|->
name|m_manager
operator|=
name|QOpenGL2PaintEngineExPrivate
operator|::
name|shaderManagerForEngine
argument_list|(
name|engine
argument_list|)
expr_stmt|;
name|Q_ASSERT
argument_list|(
name|d
operator|->
name|m_manager
argument_list|)
expr_stmt|;
comment|// Just set the stage to null, don't call removeCustomStage().
comment|// This should leave the program in a compiled/linked state
comment|// if the next custom shader stage is this one again.
name|d
operator|->
name|m_manager
operator|->
name|setCustomStage
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|d
operator|->
name|m_manager
operator|=
literal|0
expr_stmt|;
block|}
end_function
begin_function
DECL|function|source
name|QByteArray
name|QOpenGLCustomShaderStage
operator|::
name|source
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QOpenGLCustomShaderStage
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|m_source
return|;
block|}
end_function
begin_comment
comment|// Called by the shader manager if another custom shader is attached or
end_comment
begin_comment
comment|// the manager is deleted
end_comment
begin_function
DECL|function|setInactive
name|void
name|QOpenGLCustomShaderStage
operator|::
name|setInactive
parameter_list|()
block|{
name|Q_D
argument_list|(
name|QOpenGLCustomShaderStage
argument_list|)
expr_stmt|;
name|d
operator|->
name|m_manager
operator|=
literal|0
expr_stmt|;
block|}
end_function
begin_function
DECL|function|setSource
name|void
name|QOpenGLCustomShaderStage
operator|::
name|setSource
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|s
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QOpenGLCustomShaderStage
argument_list|)
expr_stmt|;
name|d
operator|->
name|m_source
operator|=
name|s
expr_stmt|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
