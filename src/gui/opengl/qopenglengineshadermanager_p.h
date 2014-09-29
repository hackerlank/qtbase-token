begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2014 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia. For licensing terms and ** conditions see http://qt.digia.com/licensing. For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights. These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
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
begin_comment
comment|/*     VERTEX SHADERS     ==============      Vertex shaders are specified as multiple (partial) shaders. On desktop,     this works fine. On ES, QOpenGLShader& QOpenGLShaderProgram will make partial     shaders work by concatenating the source in each QOpenGLShader and compiling     it as a single shader. This is abstracted nicely by QOpenGLShaderProgram and     the GL2 engine doesn't need to worry about it.      Generally, there's two vertex shader objects. The position shaders are     the ones which set gl_Position. There's also two "main" vertex shaders,     one which just calls the position shader and another which also passes     through some texture coordinates from a vertex attribute array to a     varying. These texture coordinates are used for mask position in text     rendering and for the source coordinates in drawImage/drawPixmap. There's     also a "Simple" vertex shader for rendering a solid colour (used to render     into the stencil buffer where the actual colour value is discarded).      The position shaders for brushes look scary. This is because many of the     calculations which logically belong in the fragment shader have been moved     into the vertex shader to improve performance. This is why the position     calculation is in a separate shader. Not only does it calculate the     position, but it also calculates some data to be passed to the fragment     shader as a varying. It is optimal to move as much of the calculation as     possible into the vertex shader as this is executed less often.      The varyings passed to the fragment shaders are interpolated (which is     cheap). Unfortunately, GL will apply perspective correction to the     interpolation calusing errors. To get around this, the vertex shader must     apply perspective correction itself and set the w-value of gl_Position to     zero. That way, GL will be tricked into thinking it doesn't need to apply a     perspective correction and use linear interpolation instead (which is what     we want). Of course, if the brush transform is affeine, no perspective     correction is needed and a simpler vertex shader can be used instead.      So there are the following "main" vertex shaders:         qopenglslMainVertexShader         qopenglslMainWithTexCoordsVertexShader      And the following position vertex shaders:         qopenglslPositionOnlyVertexShader         qopenglslPositionWithTextureBrushVertexShader         qopenglslPositionWithPatternBrushVertexShader         qopenglslPositionWithLinearGradientBrushVertexShader         qopenglslPositionWithRadialGradientBrushVertexShader         qopenglslPositionWithConicalGradientBrushVertexShader         qopenglslAffinePositionWithTextureBrushVertexShader         qopenglslAffinePositionWithPatternBrushVertexShader         qopenglslAffinePositionWithLinearGradientBrushVertexShader         qopenglslAffinePositionWithRadialGradientBrushVertexShader         qopenglslAffinePositionWithConicalGradientBrushVertexShader      Leading to 23 possible vertex shaders       FRAGMENT SHADERS     ================      Fragment shaders are also specified as multiple (partial) shaders. The     different fragment shaders represent the different stages in Qt's fragment     pipeline. There are 1-3 stages in this pipeline: First stage is to get the     fragment's colour value. The next stage is to get the fragment's mask value     (coverage value for anti-aliasing) and the final stage is to blend the     incoming fragment with the background (for composition modes not supported     by GL).      Of these, the first stage will always be present. If Qt doesn't need to     apply anti-aliasing (because it's off or handled by multisampling) then     the coverage value doesn't need to be applied. (Note: There are two types     of mask, one for regular anti-aliasing and one for sub-pixel anti-     aliasing.) If the composition mode is one which GL supports natively then     the blending stage doesn't need to be applied.      As eash stage can have multiple implementations, they are abstracted as     GLSL function calls with the following signatures:      Brushes& image drawing are implementations of "qcolorp vec4 srcPixel()":         qopenglslImageSrcFragShader         qopenglslImageSrcWithPatternFragShader         qopenglslNonPremultipliedImageSrcFragShader         qopenglslSolidBrushSrcFragShader         qopenglslTextureBrushSrcFragShader         qopenglslTextureBrushWithPatternFragShader         qopenglslPatternBrushSrcFragShader         qopenglslLinearGradientBrushSrcFragShader         qopenglslRadialGradientBrushSrcFragShader         qopenglslConicalGradientBrushSrcFragShader     NOTE: It is assumed the colour returned by srcPixel() is pre-multiplied      Masks are implementations of "qcolorp vec4 applyMask(qcolorp vec4 src)":         qopenglslMaskFragmentShader         qopenglslRgbMaskFragmentShaderPass1         qopenglslRgbMaskFragmentShaderPass2         qopenglslRgbMaskWithGammaFragmentShader      Composition modes are "qcolorp vec4 compose(qcolorp vec4 src)":         qopenglslColorBurnCompositionModeFragmentShader         qopenglslColorDodgeCompositionModeFragmentShader         qopenglslDarkenCompositionModeFragmentShader         qopenglslDifferenceCompositionModeFragmentShader         qopenglslExclusionCompositionModeFragmentShader         qopenglslHardLightCompositionModeFragmentShader         qopenglslLightenCompositionModeFragmentShader         qopenglslMultiplyCompositionModeFragmentShader         qopenglslOverlayCompositionModeFragmentShader         qopenglslScreenCompositionModeFragmentShader         qopenglslSoftLightCompositionModeFragmentShader       Note: In the future, some GLSL compilers will support an extension allowing           a new 'color' precision specifier. To support this, qcolorp is used for           all color components so it can be defined to colorp or lowp depending upon           the implementation.      So there are differnt frament shader main functions, depending on the     number& type of pipelines the fragment needs to go through.      The choice of which main() fragment shader string to use depends on:         - Use of global opacity         - Brush style (some brushes apply opacity themselves)         - Use& type of mask (TODO: Need to support high quality anti-aliasing& text)         - Use of non-GL Composition mode      Leading to the following fragment shader main functions:         gl_FragColor = compose(applyMask(srcPixel()*globalOpacity));         gl_FragColor = compose(applyMask(srcPixel()));         gl_FragColor = applyMask(srcPixel()*globalOpacity);         gl_FragColor = applyMask(srcPixel());         gl_FragColor = compose(srcPixel()*globalOpacity);         gl_FragColor = compose(srcPixel());         gl_FragColor = srcPixel()*globalOpacity;         gl_FragColor = srcPixel();      Called:         qopenglslMainFragmentShader_CMO         qopenglslMainFragmentShader_CM         qopenglslMainFragmentShader_MO         qopenglslMainFragmentShader_M         qopenglslMainFragmentShader_CO         qopenglslMainFragmentShader_C         qopenglslMainFragmentShader_O         qopenglslMainFragmentShader      Where:         M = Mask         C = Composition         O = Global Opacity       CUSTOM SHADER CODE     ==================      The use of custom shader code is supported by the engine for drawImage and     drawPixmap calls. This is implemented via hooks in the fragment pipeline.      The custom shader is passed to the engine as a partial fragment shader     (QOpenGLCustomShaderStage). The shader will implement a pre-defined method name     which Qt's fragment pipeline will call:          lowp vec4 customShader(lowp sampler2d imageTexture, highp vec2 textureCoords)      The provided src and srcCoords parameters can be used to sample from the     source image.      Transformations, clipping, opacity, and composition modes set using QPainter     will be respected when using the custom shader hook. */
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QOPENGLENGINE_SHADER_MANAGER_H
end_ifndef
begin_define
DECL|macro|QOPENGLENGINE_SHADER_MANAGER_H
define|#
directive|define
name|QOPENGLENGINE_SHADER_MANAGER_H
end_define
begin_include
include|#
directive|include
file|<QOpenGLShader>
end_include
begin_include
include|#
directive|include
file|<QOpenGLShaderProgram>
end_include
begin_include
include|#
directive|include
file|<QPainter>
end_include
begin_include
include|#
directive|include
file|<private/qopenglcontext_p.h>
end_include
begin_include
include|#
directive|include
file|<private/qopenglcustomshaderstage_p.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
comment|/* struct QOpenGLEngineCachedShaderProg {     QOpenGLEngineCachedShaderProg(QOpenGLEngineShaderManager::ShaderName vertexMain,                               QOpenGLEngineShaderManager::ShaderName vertexPosition,                               QOpenGLEngineShaderManager::ShaderName fragMain,                               QOpenGLEngineShaderManager::ShaderName pixelSrc,                               QOpenGLEngineShaderManager::ShaderName mask,                               QOpenGLEngineShaderManager::ShaderName composition);      int cacheKey;     QOpenGLShaderProgram* program; } */
DECL|variable|QT_VERTEX_COORDS_ATTR
specifier|static
specifier|const
name|GLuint
name|QT_VERTEX_COORDS_ATTR
init|=
literal|0
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QT_TEXTURE_COORDS_ATTR
specifier|static
specifier|const
name|GLuint
name|QT_TEXTURE_COORDS_ATTR
init|=
literal|1
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QT_OPACITY_ATTR
specifier|static
specifier|const
name|GLuint
name|QT_OPACITY_ATTR
init|=
literal|2
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QT_PMV_MATRIX_1_ATTR
specifier|static
specifier|const
name|GLuint
name|QT_PMV_MATRIX_1_ATTR
init|=
literal|3
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QT_PMV_MATRIX_2_ATTR
specifier|static
specifier|const
name|GLuint
name|QT_PMV_MATRIX_2_ATTR
init|=
literal|4
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QT_PMV_MATRIX_3_ATTR
specifier|static
specifier|const
name|GLuint
name|QT_PMV_MATRIX_3_ATTR
init|=
literal|5
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QOpenGLEngineShaderProg
name|class
name|QOpenGLEngineShaderProg
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_GUI_EXPORT
name|QOpenGLEngineSharedShaders
block|{
name|Q_GADGET
name|public
range|:      enum
name|SnippetName
block|{
name|MainVertexShader
block|,
name|MainWithTexCoordsVertexShader
block|,
name|MainWithTexCoordsAndOpacityVertexShader
block|,
comment|// UntransformedPositionVertexShader must be first in the list:
name|UntransformedPositionVertexShader
block|,
name|PositionOnlyVertexShader
block|,
name|ComplexGeometryPositionOnlyVertexShader
block|,
name|PositionWithPatternBrushVertexShader
block|,
name|PositionWithLinearGradientBrushVertexShader
block|,
name|PositionWithConicalGradientBrushVertexShader
block|,
name|PositionWithRadialGradientBrushVertexShader
block|,
name|PositionWithTextureBrushVertexShader
block|,
name|AffinePositionWithPatternBrushVertexShader
block|,
name|AffinePositionWithLinearGradientBrushVertexShader
block|,
name|AffinePositionWithConicalGradientBrushVertexShader
block|,
name|AffinePositionWithRadialGradientBrushVertexShader
block|,
name|AffinePositionWithTextureBrushVertexShader
block|,
comment|// MainFragmentShader_CMO must be first in the list:
name|MainFragmentShader_CMO
block|,
name|MainFragmentShader_CM
block|,
name|MainFragmentShader_MO
block|,
name|MainFragmentShader_M
block|,
name|MainFragmentShader_CO
block|,
name|MainFragmentShader_C
block|,
name|MainFragmentShader_O
block|,
name|MainFragmentShader
block|,
name|MainFragmentShader_ImageArrays
block|,
comment|// ImageSrcFragmentShader must be first in the list::
name|ImageSrcFragmentShader
block|,
name|ImageSrcWithPatternFragmentShader
block|,
name|NonPremultipliedImageSrcFragmentShader
block|,
name|CustomImageSrcFragmentShader
block|,
name|SolidBrushSrcFragmentShader
block|,
name|TextureBrushSrcFragmentShader
block|,
name|TextureBrushSrcWithPatternFragmentShader
block|,
name|PatternBrushSrcFragmentShader
block|,
name|LinearGradientBrushSrcFragmentShader
block|,
name|RadialGradientBrushSrcFragmentShader
block|,
name|ConicalGradientBrushSrcFragmentShader
block|,
name|ShockingPinkSrcFragmentShader
block|,
comment|// NoMaskFragmentShader must be first in the list:
name|NoMaskFragmentShader
block|,
name|MaskFragmentShader
block|,
name|RgbMaskFragmentShaderPass1
block|,
name|RgbMaskFragmentShaderPass2
block|,
name|RgbMaskWithGammaFragmentShader
block|,
comment|// NoCompositionModeFragmentShader must be first in the list:
name|NoCompositionModeFragmentShader
block|,
name|MultiplyCompositionModeFragmentShader
block|,
name|ScreenCompositionModeFragmentShader
block|,
name|OverlayCompositionModeFragmentShader
block|,
name|DarkenCompositionModeFragmentShader
block|,
name|LightenCompositionModeFragmentShader
block|,
name|ColorDodgeCompositionModeFragmentShader
block|,
name|ColorBurnCompositionModeFragmentShader
block|,
name|HardLightCompositionModeFragmentShader
block|,
name|SoftLightCompositionModeFragmentShader
block|,
name|DifferenceCompositionModeFragmentShader
block|,
name|ExclusionCompositionModeFragmentShader
block|,
name|TotalSnippetCount
block|,
name|InvalidSnippetName
block|}
decl_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|QT_DEBUG
argument_list|)
name|Q_ENUMS
argument_list|(
argument|SnippetName
argument_list|)
specifier|static
name|QByteArray
name|snippetNameStr
parameter_list|(
name|SnippetName
name|snippetName
parameter_list|)
function_decl|;
endif|#
directive|endif
comment|/*     // These allow the ShaderName enum to be used as a cache key     const int mainVertexOffset = 0;     const int positionVertexOffset = (1<<2) - PositionOnlyVertexShader;     const int mainFragOffset = (1<<6) - MainFragmentShader_CMO;     const int srcPixelOffset = (1<<10) - ImageSrcFragmentShader;     const int maskOffset = (1<<14) - NoMaskShader;     const int compositionOffset = (1<< 16) - MultiplyCompositionModeFragmentShader; */
name|QOpenGLEngineSharedShaders
argument_list|(
name|QOpenGLContext
operator|*
name|context
argument_list|)
expr_stmt|;
operator|~
name|QOpenGLEngineSharedShaders
argument_list|()
expr_stmt|;
name|QOpenGLShaderProgram
modifier|*
name|simpleProgram
parameter_list|()
block|{
return|return
name|simpleShaderProg
return|;
block|}
name|QOpenGLShaderProgram
modifier|*
name|blitProgram
parameter_list|()
block|{
return|return
name|blitShaderProg
return|;
block|}
comment|// Compile the program if it's not already in the cache, return the item in the cache.
name|QOpenGLEngineShaderProg
modifier|*
name|findProgramInCache
parameter_list|(
specifier|const
name|QOpenGLEngineShaderProg
modifier|&
name|prog
parameter_list|)
function_decl|;
comment|// Compile the custom shader if it's not already in the cache, return the item in the cache.
specifier|static
name|QOpenGLEngineSharedShaders
modifier|*
name|shadersForContext
parameter_list|(
name|QOpenGLContext
modifier|*
name|context
parameter_list|)
function_decl|;
comment|// Ideally, this would be static and cleanup all programs in all contexts which
comment|// contain the custom code. Currently it is just a hint and we rely on deleted
comment|// custom shaders being cleaned up by being kicked out of the cache when it's
comment|// full.
name|void
name|cleanupCustomStage
parameter_list|(
name|QOpenGLCustomShaderStage
modifier|*
name|stage
parameter_list|)
function_decl|;
name|private
label|:
name|QOpenGLShaderProgram
modifier|*
name|blitShaderProg
decl_stmt|;
name|QOpenGLShaderProgram
modifier|*
name|simpleShaderProg
decl_stmt|;
name|QList
operator|<
name|QOpenGLEngineShaderProg
operator|*
operator|>
name|cachedPrograms
expr_stmt|;
name|QList
operator|<
name|QOpenGLShader
operator|*
operator|>
name|shaders
expr_stmt|;
specifier|static
specifier|const
name|char
modifier|*
name|qShaderSnippets
index|[
name|TotalSnippetCount
index|]
decl_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_decl_stmt
name|class
name|QOpenGLEngineShaderProg
block|{
name|public
label|:
name|QOpenGLEngineShaderProg
argument_list|()
operator|:
name|program
argument_list|(
literal|0
argument_list|)
block|{}
operator|~
name|QOpenGLEngineShaderProg
argument_list|()
block|{
if|if
condition|(
name|program
condition|)
name|delete
name|program
decl_stmt|;
block|}
name|QOpenGLEngineSharedShaders
operator|::
name|SnippetName
name|mainVertexShader
expr_stmt|;
name|QOpenGLEngineSharedShaders
operator|::
name|SnippetName
name|positionVertexShader
expr_stmt|;
name|QOpenGLEngineSharedShaders
operator|::
name|SnippetName
name|mainFragShader
expr_stmt|;
name|QOpenGLEngineSharedShaders
operator|::
name|SnippetName
name|srcPixelFragShader
expr_stmt|;
name|QOpenGLEngineSharedShaders
operator|::
name|SnippetName
name|maskFragShader
expr_stmt|;
name|QOpenGLEngineSharedShaders
operator|::
name|SnippetName
name|compositionFragShader
expr_stmt|;
name|QByteArray
name|customStageSource
decl_stmt|;
comment|//TODO: Decent cache key for custom stages
name|QOpenGLShaderProgram
modifier|*
name|program
decl_stmt|;
name|QVector
operator|<
name|uint
operator|>
name|uniformLocations
expr_stmt|;
name|bool
name|useTextureCoords
decl_stmt|;
name|bool
name|useOpacityAttribute
decl_stmt|;
name|bool
name|usePmvMatrixAttribute
decl_stmt|;
name|bool
name|operator
operator|==
operator|(
specifier|const
name|QOpenGLEngineShaderProg
operator|&
name|other
operator|)
specifier|const
block|{
comment|// We don't care about the program
return|return
operator|(
name|mainVertexShader
operator|==
name|other
operator|.
name|mainVertexShader
operator|&&
name|positionVertexShader
operator|==
name|other
operator|.
name|positionVertexShader
operator|&&
name|mainFragShader
operator|==
name|other
operator|.
name|mainFragShader
operator|&&
name|srcPixelFragShader
operator|==
name|other
operator|.
name|srcPixelFragShader
operator|&&
name|maskFragShader
operator|==
name|other
operator|.
name|maskFragShader
operator|&&
name|compositionFragShader
operator|==
name|other
operator|.
name|compositionFragShader
operator|&&
name|customStageSource
operator|==
name|other
operator|.
name|customStageSource
operator|)
return|;
block|}
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_decl_stmt
name|class
name|Q_GUI_EXPORT
name|QOpenGLEngineShaderManager
range|:
name|public
name|QObject
block|{
name|Q_OBJECT
name|public
operator|:
name|QOpenGLEngineShaderManager
argument_list|(
name|QOpenGLContext
operator|*
name|context
argument_list|)
block|;
operator|~
name|QOpenGLEngineShaderManager
argument_list|()
block|;      enum
name|MaskType
block|{
name|NoMask
block|,
name|PixelMask
block|,
name|SubPixelMaskPass1
block|,
name|SubPixelMaskPass2
block|,
name|SubPixelWithGammaMask
block|}
block|;     enum
name|PixelSrcType
block|{
name|ImageSrc
operator|=
name|Qt
operator|::
name|TexturePattern
operator|+
literal|1
block|,
name|NonPremultipliedImageSrc
operator|=
name|Qt
operator|::
name|TexturePattern
operator|+
literal|2
block|,
name|PatternSrc
operator|=
name|Qt
operator|::
name|TexturePattern
operator|+
literal|3
block|,
name|TextureSrcWithPattern
operator|=
name|Qt
operator|::
name|TexturePattern
operator|+
literal|4
block|}
block|;      enum
name|Uniform
block|{
name|ImageTexture
block|,
name|PatternColor
block|,
name|GlobalOpacity
block|,
name|Depth
block|,
name|MaskTexture
block|,
name|FragmentColor
block|,
name|LinearData
block|,
name|Angle
block|,
name|HalfViewportSize
block|,
name|Fmp
block|,
name|Fmp2MRadius2
block|,
name|Inverse2Fmp2MRadius2
block|,
name|SqrFr
block|,
name|BRadius
block|,
name|InvertedTextureSize
block|,
name|BrushTransform
block|,
name|BrushTexture
block|,
name|Matrix
block|,
name|NumUniforms
block|}
block|;      enum
name|OpacityMode
block|{
name|NoOpacity
block|,
name|UniformOpacity
block|,
name|AttributeOpacity
block|}
block|;
comment|// There are optimizations we can do, depending on the brush transform:
comment|//    1) May not have to apply perspective-correction
comment|//    2) Can use lower precision for matrix
name|void
name|optimiseForBrushTransform
argument_list|(
argument|QTransform::TransformationType transformType
argument_list|)
block|;
name|void
name|setSrcPixelType
argument_list|(
name|Qt
operator|::
name|BrushStyle
argument_list|)
block|;
name|void
name|setSrcPixelType
argument_list|(
name|PixelSrcType
argument_list|)
block|;
comment|// For non-brush sources, like pixmaps& images
name|void
name|setOpacityMode
argument_list|(
name|OpacityMode
argument_list|)
block|;
name|void
name|setMaskType
argument_list|(
name|MaskType
argument_list|)
block|;
name|void
name|setCompositionMode
argument_list|(
name|QPainter
operator|::
name|CompositionMode
argument_list|)
block|;
name|void
name|setCustomStage
argument_list|(
name|QOpenGLCustomShaderStage
operator|*
name|stage
argument_list|)
block|;
name|void
name|removeCustomStage
argument_list|()
block|;
name|GLuint
name|getUniformLocation
argument_list|(
argument|Uniform id
argument_list|)
block|;
name|void
name|setDirty
argument_list|()
block|;
comment|// someone has manually changed the current shader program
name|bool
name|useCorrectShaderProg
argument_list|()
block|;
comment|// returns true if the shader program needed to be changed
name|void
name|useSimpleProgram
argument_list|()
block|;
name|void
name|useBlitProgram
argument_list|()
block|;
name|void
name|setHasComplexGeometry
argument_list|(
argument|bool hasComplexGeometry
argument_list|)
block|{
name|complexGeometry
operator|=
name|hasComplexGeometry
block|;
name|shaderProgNeedsChanging
operator|=
name|true
block|;     }
name|bool
name|hasComplexGeometry
argument_list|()
specifier|const
block|{
return|return
name|complexGeometry
return|;
block|}
name|QOpenGLShaderProgram
operator|*
name|currentProgram
argument_list|()
block|;
comment|// Returns pointer to the shader the manager has chosen
name|QOpenGLShaderProgram
operator|*
name|simpleProgram
argument_list|()
block|;
comment|// Used to draw into e.g. stencil buffers
name|QOpenGLShaderProgram
operator|*
name|blitProgram
argument_list|()
block|;
comment|// Used to blit a texture into the framebuffer
name|QOpenGLEngineSharedShaders
operator|*
name|sharedShaders
block|;
name|private
operator|:
name|QOpenGLContext
operator|*
name|ctx
block|;
name|bool
name|shaderProgNeedsChanging
block|;
name|bool
name|complexGeometry
block|;
comment|// Current state variables which influence the choice of shader:
name|QTransform
name|brushTransform
block|;
name|int
name|srcPixelType
block|;
name|OpacityMode
name|opacityMode
block|;
name|MaskType
name|maskType
block|;
name|QPainter
operator|::
name|CompositionMode
name|compositionMode
block|;
name|QOpenGLCustomShaderStage
operator|*
name|customSrcStage
block|;
name|QOpenGLEngineShaderProg
operator|*
name|currentShaderProg
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
comment|//QOPENGLENGINE_SHADER_MANAGER_H
end_comment
end_unit
