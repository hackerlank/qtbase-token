begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QOPENGLPAINTENGINE_P_H
end_ifndef
begin_define
DECL|macro|QOPENGLPAINTENGINE_P_H
define|#
directive|define
name|QOPENGLPAINTENGINE_P_H
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
file|<QDebug>
end_include
begin_include
include|#
directive|include
file|<qopenglpaintdevice.h>
end_include
begin_include
include|#
directive|include
file|<private/qpaintengineex_p.h>
end_include
begin_include
include|#
directive|include
file|<private/qopenglengineshadermanager_p.h>
end_include
begin_include
include|#
directive|include
file|<private/qopengl2pexvertexarray_p.h>
end_include
begin_include
include|#
directive|include
file|<private/qfontengine_p.h>
end_include
begin_include
include|#
directive|include
file|<private/qdatabuffer_p.h>
end_include
begin_include
include|#
directive|include
file|<private/qtriangulatingstroker_p.h>
end_include
begin_include
include|#
directive|include
file|<private/qopenglextensions_p.h>
end_include
begin_enum
DECL|enum|EngineMode
enum|enum
name|EngineMode
block|{
DECL|enumerator|ImageDrawingMode
name|ImageDrawingMode
block|,
DECL|enumerator|TextDrawingMode
name|TextDrawingMode
block|,
DECL|enumerator|BrushDrawingMode
name|BrushDrawingMode
block|,
DECL|enumerator|ImageArrayDrawingMode
name|ImageArrayDrawingMode
block|}
enum|;
end_enum
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|macro|GL_STENCIL_HIGH_BIT
define|#
directive|define
name|GL_STENCIL_HIGH_BIT
value|GLuint(0x80)
DECL|macro|QT_BRUSH_TEXTURE_UNIT
define|#
directive|define
name|QT_BRUSH_TEXTURE_UNIT
value|GLuint(0)
DECL|macro|QT_IMAGE_TEXTURE_UNIT
define|#
directive|define
name|QT_IMAGE_TEXTURE_UNIT
value|GLuint(0)
comment|//Can be the same as brush texture unit
DECL|macro|QT_MASK_TEXTURE_UNIT
define|#
directive|define
name|QT_MASK_TEXTURE_UNIT
value|GLuint(1)
DECL|macro|QT_BACKGROUND_TEXTURE_UNIT
define|#
directive|define
name|QT_BACKGROUND_TEXTURE_UNIT
value|GLuint(2)
DECL|variable|QOpenGL2PaintEngineExPrivate
name|class
name|QOpenGL2PaintEngineExPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QOpenGL2PaintEngineState
range|:
name|public
name|QPainterState
block|{
name|public
operator|:
name|QOpenGL2PaintEngineState
argument_list|(
name|QOpenGL2PaintEngineState
operator|&
name|other
argument_list|)
block|;
name|QOpenGL2PaintEngineState
argument_list|()
block|;
operator|~
name|QOpenGL2PaintEngineState
argument_list|()
block|;
name|uint
name|isNew
operator|:
literal|1
block|;
name|uint
name|needsClipBufferClear
operator|:
literal|1
block|;
name|uint
name|clipTestEnabled
operator|:
literal|1
block|;
name|uint
name|canRestoreClip
operator|:
literal|1
block|;
name|uint
name|matrixChanged
operator|:
literal|1
block|;
name|uint
name|compositionModeChanged
operator|:
literal|1
block|;
name|uint
name|opacityChanged
operator|:
literal|1
block|;
name|uint
name|renderHintsChanged
operator|:
literal|1
block|;
name|uint
name|clipChanged
operator|:
literal|1
block|;
name|uint
name|currentClip
operator|:
literal|8
block|;
name|QRect
name|rectangleClip
block|; }
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_GUI_EXPORT
name|QOpenGL2PaintEngineEx
range|:
name|public
name|QPaintEngineEx
block|{
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QOpenGL2PaintEngineEx
argument_list|)
name|public
operator|:
name|QOpenGL2PaintEngineEx
argument_list|()
block|;
operator|~
name|QOpenGL2PaintEngineEx
argument_list|()
block|;
name|bool
name|begin
argument_list|(
name|QPaintDevice
operator|*
name|device
argument_list|)
block|;
name|void
name|ensureActive
argument_list|()
block|;
name|bool
name|end
argument_list|()
block|;
name|virtual
name|void
name|clipEnabledChanged
argument_list|()
block|;
name|virtual
name|void
name|penChanged
argument_list|()
block|;
name|virtual
name|void
name|brushChanged
argument_list|()
block|;
name|virtual
name|void
name|brushOriginChanged
argument_list|()
block|;
name|virtual
name|void
name|opacityChanged
argument_list|()
block|;
name|virtual
name|void
name|compositionModeChanged
argument_list|()
block|;
name|virtual
name|void
name|renderHintsChanged
argument_list|()
block|;
name|virtual
name|void
name|transformChanged
argument_list|()
block|;
name|virtual
name|void
name|drawPixmap
argument_list|(
specifier|const
name|QRectF
operator|&
name|r
argument_list|,
specifier|const
name|QPixmap
operator|&
name|pm
argument_list|,
specifier|const
name|QRectF
operator|&
name|sr
argument_list|)
block|;
name|virtual
name|void
name|drawPixmapFragments
argument_list|(
argument|const QPainter::PixmapFragment *fragments
argument_list|,
argument|int fragmentCount
argument_list|,
argument|const QPixmap&pixmap
argument_list|,
argument|QPainter::PixmapFragmentHints hints
argument_list|)
block|;
name|virtual
name|void
name|drawImage
argument_list|(
argument|const QRectF&r
argument_list|,
argument|const QImage&pm
argument_list|,
argument|const QRectF&sr
argument_list|,
argument|Qt::ImageConversionFlags flags = Qt::AutoColor
argument_list|)
block|;
name|virtual
name|void
name|drawTextItem
argument_list|(
specifier|const
name|QPointF
operator|&
name|p
argument_list|,
specifier|const
name|QTextItem
operator|&
name|textItem
argument_list|)
block|;
name|virtual
name|void
name|fill
argument_list|(
specifier|const
name|QVectorPath
operator|&
name|path
argument_list|,
specifier|const
name|QBrush
operator|&
name|brush
argument_list|)
block|;
name|virtual
name|void
name|stroke
argument_list|(
specifier|const
name|QVectorPath
operator|&
name|path
argument_list|,
specifier|const
name|QPen
operator|&
name|pen
argument_list|)
block|;
name|virtual
name|void
name|clip
argument_list|(
argument|const QVectorPath&path
argument_list|,
argument|Qt::ClipOperation op
argument_list|)
block|;
name|virtual
name|void
name|drawStaticTextItem
argument_list|(
name|QStaticTextItem
operator|*
name|textItem
argument_list|)
block|;
name|bool
name|drawTexture
argument_list|(
argument|const QRectF&r
argument_list|,
argument|GLuint textureId
argument_list|,
argument|const QSize&size
argument_list|,
argument|const QRectF&sr
argument_list|)
block|;
name|Type
name|type
argument_list|()
specifier|const
block|{
return|return
name|OpenGL2
return|;
block|}
name|virtual
name|void
name|setState
argument_list|(
name|QPainterState
operator|*
name|s
argument_list|)
block|;
name|virtual
name|QPainterState
operator|*
name|createState
argument_list|(
argument|QPainterState *orig
argument_list|)
specifier|const
block|;
specifier|inline
name|QOpenGL2PaintEngineState
operator|*
name|state
argument_list|()
block|{
return|return
name|static_cast
operator|<
name|QOpenGL2PaintEngineState
operator|*
operator|>
operator|(
name|QPaintEngineEx
operator|::
name|state
argument_list|()
operator|)
return|;
block|}
specifier|inline
specifier|const
name|QOpenGL2PaintEngineState
operator|*
name|state
argument_list|()
specifier|const
block|{
return|return
name|static_cast
operator|<
specifier|const
name|QOpenGL2PaintEngineState
operator|*
operator|>
operator|(
name|QPaintEngineEx
operator|::
name|state
argument_list|()
operator|)
return|;
block|}
name|void
name|beginNativePainting
argument_list|()
block|;
name|void
name|endNativePainting
argument_list|()
block|;
name|void
name|invalidateState
argument_list|()
block|;
name|void
name|setRenderTextActive
argument_list|(
name|bool
argument_list|)
block|;
name|bool
name|isNativePaintingActive
argument_list|()
specifier|const
block|;
name|bool
name|requiresPretransformedGlyphPositions
argument_list|(
argument|QFontEngine *
argument_list|,
argument|const QTransform&
argument_list|)
specifier|const
block|{
return|return
name|false
return|;
block|}
name|bool
name|shouldDrawCachedGlyphs
argument_list|(
argument|QFontEngine *
argument_list|,
argument|const QTransform&
argument_list|)
specifier|const
block|;
name|private
operator|:
name|Q_DISABLE_COPY
argument_list|(
argument|QOpenGL2PaintEngineEx
argument_list|)
name|friend
name|class
name|QOpenGLEngineShaderManager
block|; }
decl_stmt|;
end_decl_stmt
begin_comment
comment|// This probably needs to grow to GL_MAX_VERTEX_ATTRIBS, but 3 is ok for now as that's
end_comment
begin_comment
comment|// all the GL2 engine uses:
end_comment
begin_define
DECL|macro|QT_GL_VERTEX_ARRAY_TRACKED_COUNT
define|#
directive|define
name|QT_GL_VERTEX_ARRAY_TRACKED_COUNT
value|3
end_define
begin_decl_stmt
name|class
name|QOpenGL2PaintEngineExPrivate
range|:
name|public
name|QPaintEngineExPrivate
block|{
name|Q_DECLARE_PUBLIC
argument_list|(
argument|QOpenGL2PaintEngineEx
argument_list|)
name|public
operator|:
expr|enum
name|StencilFillMode
block|{
name|OddEvenFillMode
block|,
name|WindingFillMode
block|,
name|TriStripStrokeFillMode
block|}
block|;
name|QOpenGL2PaintEngineExPrivate
argument_list|(
name|QOpenGL2PaintEngineEx
operator|*
name|q_ptr
argument_list|)
operator|:
name|q
argument_list|(
name|q_ptr
argument_list|)
block|,
name|shaderManager
argument_list|(
literal|0
argument_list|)
block|,
name|width
argument_list|(
literal|0
argument_list|)
block|,
name|height
argument_list|(
literal|0
argument_list|)
block|,
name|ctx
argument_list|(
literal|0
argument_list|)
block|,
name|useSystemClip
argument_list|(
name|true
argument_list|)
block|,
name|elementIndicesVBOId
argument_list|(
literal|0
argument_list|)
block|,
name|opacityArray
argument_list|(
literal|0
argument_list|)
block|,
name|snapToPixelGrid
argument_list|(
name|false
argument_list|)
block|,
name|nativePaintingActive
argument_list|(
name|false
argument_list|)
block|,
name|inverseScale
argument_list|(
literal|1
argument_list|)
block|,
name|lastMaskTextureUsed
argument_list|(
literal|0
argument_list|)
block|{ }
operator|~
name|QOpenGL2PaintEngineExPrivate
argument_list|()
block|;
name|void
name|updateBrushTexture
argument_list|()
block|;
name|void
name|updateBrushUniforms
argument_list|()
block|;
name|void
name|updateMatrix
argument_list|()
block|;
name|void
name|updateCompositionMode
argument_list|()
block|;
name|void
name|updateTextureFilter
argument_list|(
argument|GLenum target
argument_list|,
argument|GLenum wrapMode
argument_list|,
argument|bool smoothPixmapTransform
argument_list|,
argument|GLuint id = GLuint(-
literal|1
argument|)
argument_list|)
block|;
name|void
name|resetGLState
argument_list|()
block|;
comment|// fill, stroke, drawTexture, drawPixmaps& drawCachedGlyphs are the main rendering entry-points,
comment|// however writeClip can also be thought of as en entry point as it does similar things.
name|void
name|fill
argument_list|(
specifier|const
name|QVectorPath
operator|&
name|path
argument_list|)
block|;
name|void
name|stroke
argument_list|(
specifier|const
name|QVectorPath
operator|&
name|path
argument_list|,
specifier|const
name|QPen
operator|&
name|pen
argument_list|)
block|;
name|void
name|drawTexture
argument_list|(
argument|const QOpenGLRect& dest
argument_list|,
argument|const QOpenGLRect& src
argument_list|,
argument|const QSize&textureSize
argument_list|,
argument|bool opaque
argument_list|,
argument|bool pattern = false
argument_list|)
block|;
name|void
name|drawPixmapFragments
argument_list|(
argument|const QPainter::PixmapFragment *fragments
argument_list|,
argument|int fragmentCount
argument_list|,
argument|const QPixmap&pixmap
argument_list|,
argument|QPainter::PixmapFragmentHints hints
argument_list|)
block|;
name|void
name|drawCachedGlyphs
argument_list|(
argument|QFontEngineGlyphCache::Type glyphType
argument_list|,
argument|QStaticTextItem *staticTextItem
argument_list|)
block|;
comment|// Calls glVertexAttributePointer if the pointer has changed
specifier|inline
name|void
name|setVertexAttributePointer
argument_list|(
argument|unsigned int arrayIndex
argument_list|,
argument|const GLfloat *pointer
argument_list|)
block|;
comment|// draws whatever is in the vertex array:
name|void
name|drawVertexArrays
argument_list|(
argument|const float *data
argument_list|,
argument|int *stops
argument_list|,
argument|int stopCount
argument_list|,
argument|GLenum primitive
argument_list|)
block|;
name|void
name|drawVertexArrays
argument_list|(
argument|QOpenGL2PEXVertexArray&vertexArray
argument_list|,
argument|GLenum primitive
argument_list|)
block|{
name|drawVertexArrays
argument_list|(
operator|(
specifier|const
name|float
operator|*
operator|)
name|vertexArray
operator|.
name|data
argument_list|()
argument_list|,
name|vertexArray
operator|.
name|stops
argument_list|()
argument_list|,
name|vertexArray
operator|.
name|stopCount
argument_list|()
argument_list|,
name|primitive
argument_list|)
block|;     }
comment|// Composites the bounding rect onto dest buffer:
name|void
name|composite
argument_list|(
specifier|const
name|QOpenGLRect
operator|&
name|boundingRect
argument_list|)
block|;
comment|// Calls drawVertexArrays to render into stencil buffer:
name|void
name|fillStencilWithVertexArray
argument_list|(
argument|const float *data
argument_list|,
argument|int count
argument_list|,
argument|int *stops
argument_list|,
argument|int stopCount
argument_list|,
argument|const QOpenGLRect&bounds
argument_list|,
argument|StencilFillMode mode
argument_list|)
block|;
name|void
name|fillStencilWithVertexArray
argument_list|(
argument|QOpenGL2PEXVertexArray& vertexArray
argument_list|,
argument|bool useWindingFill
argument_list|)
block|{
name|fillStencilWithVertexArray
argument_list|(
operator|(
specifier|const
name|float
operator|*
operator|)
name|vertexArray
operator|.
name|data
argument_list|()
argument_list|,
literal|0
argument_list|,
name|vertexArray
operator|.
name|stops
argument_list|()
argument_list|,
name|vertexArray
operator|.
name|stopCount
argument_list|()
argument_list|,
name|vertexArray
operator|.
name|boundingRect
argument_list|()
argument_list|,
name|useWindingFill
operator|?
name|WindingFillMode
operator|:
name|OddEvenFillMode
argument_list|)
block|;     }
name|void
name|setBrush
argument_list|(
specifier|const
name|QBrush
operator|&
name|brush
argument_list|)
block|;
name|void
name|transferMode
argument_list|(
argument|EngineMode newMode
argument_list|)
block|;
name|bool
name|prepareForDraw
argument_list|(
argument|bool srcPixelsAreOpaque
argument_list|)
block|;
comment|// returns true if the program has changed
name|bool
name|prepareForCachedGlyphDraw
argument_list|(
specifier|const
name|QFontEngineGlyphCache
operator|&
name|cache
argument_list|)
block|;
specifier|inline
name|void
name|useSimpleShader
argument_list|()
block|;
specifier|inline
name|GLuint
name|location
argument_list|(
argument|const QOpenGLEngineShaderManager::Uniform uniform
argument_list|)
block|{
return|return
name|shaderManager
operator|->
name|getUniformLocation
argument_list|(
name|uniform
argument_list|)
return|;
block|}
name|void
name|clearClip
argument_list|(
argument|uint value
argument_list|)
block|;
name|void
name|writeClip
argument_list|(
argument|const QVectorPath&path
argument_list|,
argument|uint value
argument_list|)
block|;
name|void
name|resetClipIfNeeded
argument_list|()
block|;
name|void
name|updateClipScissorTest
argument_list|()
block|;
name|void
name|setScissor
argument_list|(
specifier|const
name|QRect
operator|&
name|rect
argument_list|)
block|;
name|void
name|regenerateClip
argument_list|()
block|;
name|void
name|systemStateChanged
argument_list|()
block|;
name|void
name|setVertexAttribArrayEnabled
argument_list|(
argument|int arrayIndex
argument_list|,
argument|bool enabled = true
argument_list|)
block|;
name|void
name|syncGlState
argument_list|()
block|;
specifier|static
name|QOpenGLEngineShaderManager
operator|*
name|shaderManagerForEngine
argument_list|(
argument|QOpenGL2PaintEngineEx *engine
argument_list|)
block|{
return|return
name|engine
operator|->
name|d_func
argument_list|()
operator|->
name|shaderManager
return|;
block|}
specifier|static
name|QOpenGL2PaintEngineExPrivate
operator|*
name|getData
argument_list|(
argument|QOpenGL2PaintEngineEx *engine
argument_list|)
block|{
return|return
name|engine
operator|->
name|d_func
argument_list|()
return|;
block|}
specifier|static
name|void
name|cleanupVectorPath
argument_list|(
name|QPaintEngineEx
operator|*
name|engine
argument_list|,
name|void
operator|*
name|data
argument_list|)
block|;
name|QOpenGLExtensions
name|funcs
block|;
name|QOpenGL2PaintEngineEx
operator|*
name|q
block|;
name|QOpenGLEngineShaderManager
operator|*
name|shaderManager
block|;
name|QOpenGLPaintDevice
operator|*
name|device
block|;
name|int
name|width
block|,
name|height
block|;
name|QOpenGLContext
operator|*
name|ctx
block|;
name|EngineMode
name|mode
block|;
name|QFontEngineGlyphCache
operator|::
name|Type
name|glyphCacheType
block|;
name|bool
name|vertexAttributeArraysEnabledState
index|[
name|QT_GL_VERTEX_ARRAY_TRACKED_COUNT
index|]
block|;
comment|// Dirty flags
name|bool
name|matrixDirty
block|;
comment|// Implies matrix uniforms are also dirty
name|bool
name|compositionModeDirty
block|;
name|bool
name|brushTextureDirty
block|;
name|bool
name|brushUniformsDirty
block|;
name|bool
name|opacityUniformDirty
block|;
name|bool
name|matrixUniformDirty
block|;
name|bool
name|stencilClean
block|;
comment|// Has the stencil not been used for clipping so far?
name|bool
name|useSystemClip
block|;
name|QRegion
name|dirtyStencilRegion
block|;
name|QRect
name|currentScissorBounds
block|;
name|uint
name|maxClip
block|;
name|QBrush
name|currentBrush
block|;
comment|// May not be the state's brush!
specifier|const
name|QBrush
name|noBrush
block|;
name|QPixmap
name|currentBrushPixmap
block|;
name|QOpenGL2PEXVertexArray
name|vertexCoordinateArray
block|;
name|QOpenGL2PEXVertexArray
name|textureCoordinateArray
block|;
name|QVector
operator|<
name|GLushort
operator|>
name|elementIndices
block|;
name|GLuint
name|elementIndicesVBOId
block|;
name|QDataBuffer
operator|<
name|GLfloat
operator|>
name|opacityArray
block|;
name|GLfloat
name|staticVertexCoordinateArray
index|[
literal|8
index|]
block|;
name|GLfloat
name|staticTextureCoordinateArray
index|[
literal|8
index|]
block|;
name|bool
name|snapToPixelGrid
block|;
name|bool
name|nativePaintingActive
block|;
name|GLfloat
name|pmvMatrix
index|[
literal|3
index|]
index|[
literal|3
index|]
block|;
name|GLfloat
name|inverseScale
block|;
name|GLuint
name|lastTextureUsed
block|;
name|GLuint
name|lastMaskTextureUsed
block|;
name|bool
name|needsSync
block|;
name|bool
name|multisamplingAlwaysEnabled
block|;
name|GLfloat
name|depthRange
index|[
literal|2
index|]
block|;
name|float
name|textureInvertedY
block|;
name|QTriangulatingStroker
name|stroker
block|;
name|QDashedStrokeProcessor
name|dasher
block|;
name|QSet
operator|<
name|QVectorPath
operator|::
name|CacheEntry
operator|*
operator|>
name|pathCaches
block|;
name|QVector
operator|<
name|GLuint
operator|>
name|unusedVBOSToClean
block|;
name|QVector
operator|<
name|GLuint
operator|>
name|unusedIBOSToClean
block|;
specifier|const
name|GLfloat
operator|*
name|vertexAttribPointers
index|[
literal|3
index|]
block|; }
decl_stmt|;
end_decl_stmt
begin_expr_stmt
DECL|function|setVertexAttributePointer
name|void
name|QOpenGL2PaintEngineExPrivate
operator|::
name|setVertexAttributePointer
argument_list|(
argument|unsigned int arrayIndex
argument_list|,
argument|const GLfloat *pointer
argument_list|)
block|{
name|Q_ASSERT
argument_list|(
name|arrayIndex
operator|<
literal|3
argument_list|)
block|;
if|if
condition|(
name|pointer
operator|==
name|vertexAttribPointers
index|[
name|arrayIndex
index|]
condition|)
return|return;
name|vertexAttribPointers
index|[
name|arrayIndex
index|]
operator|=
name|pointer
expr_stmt|;
end_expr_stmt
begin_if
if|if
condition|(
name|arrayIndex
operator|==
name|QT_OPACITY_ATTR
condition|)
name|funcs
operator|.
name|glVertexAttribPointer
argument_list|(
name|arrayIndex
argument_list|,
literal|1
argument_list|,
name|GL_FLOAT
argument_list|,
name|GL_FALSE
argument_list|,
literal|0
argument_list|,
name|pointer
argument_list|)
expr_stmt|;
else|else
name|funcs
operator|.
name|glVertexAttribPointer
argument_list|(
name|arrayIndex
argument_list|,
literal|2
argument_list|,
name|GL_FLOAT
argument_list|,
name|GL_FALSE
argument_list|,
literal|0
argument_list|,
name|pointer
argument_list|)
expr_stmt|;
end_if
begin_endif
unit|}  QT_END_NAMESPACE
endif|#
directive|endif
end_endif
end_unit
