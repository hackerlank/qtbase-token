begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtOpenGL module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QGL_H
end_ifndef
begin_define
DECL|macro|QGL_H
define|#
directive|define
name|QGL_H
end_define
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_OPENGL
end_ifndef
begin_include
include|#
directive|include
file|<QtWidgets/qwidget.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/qpaintengine.h>
end_include
begin_include
include|#
directive|include
file|<QtOpenGL/qglcolormap.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qmap.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qscopedpointer.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/QSurfaceFormat>
end_include
begin_macro
name|QT_BEGIN_HEADER
end_macro
begin_if
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_WIN
argument_list|)
end_if
begin_include
include|#
directive|include
file|<QtCore/qt_windows.h>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_if
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_MAC
argument_list|)
end_if
begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|Q_OS_IOS
argument_list|)
end_if
begin_include
include|#
directive|include
file|<OpenGL/gl.h>
end_include
begin_else
else|#
directive|else
end_else
begin_if
if|#
directive|if
name|defined
argument_list|(
name|QT_OPENGL_ES_2
argument_list|)
end_if
begin_include
include|#
directive|include
file|<OpenGLES/ES2/gl.h>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_endif
endif|#
directive|endif
end_endif
begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|QT_OPENGL_ES_2
argument_list|)
end_elif
begin_include
include|#
directive|include
file|<GLES2/gl2.h>
end_include
begin_else
else|#
directive|else
end_else
begin_include
include|#
directive|include
file|<GL/gl.h>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_if
if|#
directive|if
name|defined
argument_list|(
name|QT_OPENGL_ES_2
argument_list|)
end_if
begin_ifndef
ifndef|#
directive|ifndef
name|GL_DOUBLE
end_ifndef
begin_define
DECL|macro|GL_DOUBLE
define|#
directive|define
name|GL_DOUBLE
value|GL_FLOAT
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|GLdouble
end_ifndef
begin_typedef
DECL|typedef|GLdouble
typedef|typedef
name|GLfloat
name|GLdouble
typedef|;
end_typedef
begin_endif
endif|#
directive|endif
end_endif
begin_endif
endif|#
directive|endif
end_endif
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QPixmap
name|class
name|QPixmap
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QGLWidgetPrivate
name|class
name|QGLWidgetPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QGLContextPrivate
name|class
name|QGLContextPrivate
decl_stmt|;
end_decl_stmt
begin_comment
comment|// Namespace class:
end_comment
begin_decl_stmt
name|namespace
name|QGL
block|{
enum|enum
name|FormatOption
block|{
name|DoubleBuffer
init|=
literal|0x0001
block|,
name|DepthBuffer
init|=
literal|0x0002
block|,
name|Rgba
init|=
literal|0x0004
block|,
name|AlphaChannel
init|=
literal|0x0008
block|,
name|AccumBuffer
init|=
literal|0x0010
block|,
name|StencilBuffer
init|=
literal|0x0020
block|,
name|StereoBuffers
init|=
literal|0x0040
block|,
name|DirectRendering
init|=
literal|0x0080
block|,
name|HasOverlay
init|=
literal|0x0100
block|,
name|SampleBuffers
init|=
literal|0x0200
block|,
name|DeprecatedFunctions
init|=
literal|0x0400
block|,
name|SingleBuffer
init|=
name|DoubleBuffer
operator|<<
literal|16
block|,
name|NoDepthBuffer
init|=
name|DepthBuffer
operator|<<
literal|16
block|,
name|ColorIndex
init|=
name|Rgba
operator|<<
literal|16
block|,
name|NoAlphaChannel
init|=
name|AlphaChannel
operator|<<
literal|16
block|,
name|NoAccumBuffer
init|=
name|AccumBuffer
operator|<<
literal|16
block|,
name|NoStencilBuffer
init|=
name|StencilBuffer
operator|<<
literal|16
block|,
name|NoStereoBuffers
init|=
name|StereoBuffers
operator|<<
literal|16
block|,
name|IndirectRendering
init|=
name|DirectRendering
operator|<<
literal|16
block|,
name|NoOverlay
init|=
name|HasOverlay
operator|<<
literal|16
block|,
name|NoSampleBuffers
init|=
name|SampleBuffers
operator|<<
literal|16
block|,
name|NoDeprecatedFunctions
init|=
name|DeprecatedFunctions
operator|<<
literal|16
block|}
enum|;
name|Q_DECLARE_FLAGS
argument_list|(
argument|FormatOptions
argument_list|,
argument|FormatOption
argument_list|)
block|}
end_decl_stmt
begin_macro
name|Q_DECLARE_OPERATORS_FOR_FLAGS
argument_list|(
argument|QGL::FormatOptions
argument_list|)
end_macro
begin_decl_stmt
DECL|variable|QGLFormatPrivate
name|class
name|QGLFormatPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_OPENGL_EXPORT
name|QGLFormat
block|{
name|public
label|:
name|QGLFormat
argument_list|()
expr_stmt|;
name|QGLFormat
argument_list|(
argument|QGL::FormatOptions options
argument_list|,
argument|int plane =
literal|0
argument_list|)
empty_stmt|;
name|QGLFormat
argument_list|(
specifier|const
name|QGLFormat
operator|&
name|other
argument_list|)
expr_stmt|;
name|QGLFormat
modifier|&
name|operator
init|=
operator|(
specifier|const
name|QGLFormat
operator|&
name|other
operator|)
decl_stmt|;
operator|~
name|QGLFormat
argument_list|()
expr_stmt|;
name|void
name|setDepthBufferSize
parameter_list|(
name|int
name|size
parameter_list|)
function_decl|;
name|int
name|depthBufferSize
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setAccumBufferSize
parameter_list|(
name|int
name|size
parameter_list|)
function_decl|;
name|int
name|accumBufferSize
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setRedBufferSize
parameter_list|(
name|int
name|size
parameter_list|)
function_decl|;
name|int
name|redBufferSize
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setGreenBufferSize
parameter_list|(
name|int
name|size
parameter_list|)
function_decl|;
name|int
name|greenBufferSize
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setBlueBufferSize
parameter_list|(
name|int
name|size
parameter_list|)
function_decl|;
name|int
name|blueBufferSize
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setAlphaBufferSize
parameter_list|(
name|int
name|size
parameter_list|)
function_decl|;
name|int
name|alphaBufferSize
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setStencilBufferSize
parameter_list|(
name|int
name|size
parameter_list|)
function_decl|;
name|int
name|stencilBufferSize
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setSampleBuffers
parameter_list|(
name|bool
name|enable
parameter_list|)
function_decl|;
name|bool
name|sampleBuffers
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setSamples
parameter_list|(
name|int
name|numSamples
parameter_list|)
function_decl|;
name|int
name|samples
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setSwapInterval
parameter_list|(
name|int
name|interval
parameter_list|)
function_decl|;
name|int
name|swapInterval
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|doubleBuffer
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setDoubleBuffer
parameter_list|(
name|bool
name|enable
parameter_list|)
function_decl|;
name|bool
name|depth
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setDepth
parameter_list|(
name|bool
name|enable
parameter_list|)
function_decl|;
name|bool
name|rgba
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setRgba
parameter_list|(
name|bool
name|enable
parameter_list|)
function_decl|;
name|bool
name|alpha
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setAlpha
parameter_list|(
name|bool
name|enable
parameter_list|)
function_decl|;
name|bool
name|accum
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setAccum
parameter_list|(
name|bool
name|enable
parameter_list|)
function_decl|;
name|bool
name|stencil
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setStencil
parameter_list|(
name|bool
name|enable
parameter_list|)
function_decl|;
name|bool
name|stereo
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setStereo
parameter_list|(
name|bool
name|enable
parameter_list|)
function_decl|;
name|bool
name|directRendering
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setDirectRendering
parameter_list|(
name|bool
name|enable
parameter_list|)
function_decl|;
name|bool
name|hasOverlay
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setOverlay
parameter_list|(
name|bool
name|enable
parameter_list|)
function_decl|;
name|int
name|plane
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setPlane
parameter_list|(
name|int
name|plane
parameter_list|)
function_decl|;
name|void
name|setOption
argument_list|(
name|QGL
operator|::
name|FormatOptions
name|opt
argument_list|)
decl_stmt|;
name|bool
name|testOption
argument_list|(
name|QGL
operator|::
name|FormatOptions
name|opt
argument_list|)
decl|const
decl_stmt|;
specifier|static
name|QGLFormat
name|defaultFormat
parameter_list|()
function_decl|;
specifier|static
name|void
name|setDefaultFormat
parameter_list|(
specifier|const
name|QGLFormat
modifier|&
name|f
parameter_list|)
function_decl|;
specifier|static
name|QGLFormat
name|defaultOverlayFormat
parameter_list|()
function_decl|;
specifier|static
name|void
name|setDefaultOverlayFormat
parameter_list|(
specifier|const
name|QGLFormat
modifier|&
name|f
parameter_list|)
function_decl|;
specifier|static
name|bool
name|hasOpenGL
parameter_list|()
function_decl|;
specifier|static
name|bool
name|hasOpenGLOverlays
parameter_list|()
function_decl|;
name|void
name|setVersion
parameter_list|(
name|int
name|major
parameter_list|,
name|int
name|minor
parameter_list|)
function_decl|;
name|int
name|majorVersion
argument_list|()
specifier|const
expr_stmt|;
name|int
name|minorVersion
argument_list|()
specifier|const
expr_stmt|;
enum|enum
name|OpenGLContextProfile
block|{
name|NoProfile
block|,
name|CoreProfile
block|,
name|CompatibilityProfile
block|}
enum|;
name|void
name|setProfile
parameter_list|(
name|OpenGLContextProfile
name|profile
parameter_list|)
function_decl|;
name|OpenGLContextProfile
name|profile
argument_list|()
specifier|const
expr_stmt|;
enum|enum
name|OpenGLVersionFlag
block|{
name|OpenGL_Version_None
init|=
literal|0x00000000
block|,
name|OpenGL_Version_1_1
init|=
literal|0x00000001
block|,
name|OpenGL_Version_1_2
init|=
literal|0x00000002
block|,
name|OpenGL_Version_1_3
init|=
literal|0x00000004
block|,
name|OpenGL_Version_1_4
init|=
literal|0x00000008
block|,
name|OpenGL_Version_1_5
init|=
literal|0x00000010
block|,
name|OpenGL_Version_2_0
init|=
literal|0x00000020
block|,
name|OpenGL_Version_2_1
init|=
literal|0x00000040
block|,
name|OpenGL_ES_Common_Version_1_0
init|=
literal|0x00000080
block|,
name|OpenGL_ES_CommonLite_Version_1_0
init|=
literal|0x00000100
block|,
name|OpenGL_ES_Common_Version_1_1
init|=
literal|0x00000200
block|,
name|OpenGL_ES_CommonLite_Version_1_1
init|=
literal|0x00000400
block|,
name|OpenGL_ES_Version_2_0
init|=
literal|0x00000800
block|,
name|OpenGL_Version_3_0
init|=
literal|0x00001000
block|,
name|OpenGL_Version_3_1
init|=
literal|0x00002000
block|,
name|OpenGL_Version_3_2
init|=
literal|0x00004000
block|,
name|OpenGL_Version_3_3
init|=
literal|0x00008000
block|,
name|OpenGL_Version_4_0
init|=
literal|0x00010000
block|}
enum|;
name|Q_DECLARE_FLAGS
argument_list|(
argument|OpenGLVersionFlags
argument_list|,
argument|OpenGLVersionFlag
argument_list|)
specifier|static
name|OpenGLVersionFlags
name|openGLVersionFlags
parameter_list|()
function_decl|;
specifier|static
name|QGLFormat
name|fromSurfaceFormat
parameter_list|(
specifier|const
name|QSurfaceFormat
modifier|&
name|format
parameter_list|)
function_decl|;
specifier|static
name|QSurfaceFormat
name|toSurfaceFormat
parameter_list|(
specifier|const
name|QGLFormat
modifier|&
name|format
parameter_list|)
function_decl|;
name|private
label|:
name|QGLFormatPrivate
modifier|*
name|d
decl_stmt|;
name|void
name|detach
parameter_list|()
function_decl|;
name|friend
name|Q_OPENGL_EXPORT
name|bool
name|operator
operator|==
operator|(
specifier|const
name|QGLFormat
operator|&
operator|,
specifier|const
name|QGLFormat
operator|&
operator|)
expr_stmt|;
name|friend
name|Q_OPENGL_EXPORT
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|QGLFormat
operator|&
operator|,
specifier|const
name|QGLFormat
operator|&
operator|)
expr_stmt|;
ifndef|#
directive|ifndef
name|QT_NO_DEBUG_STREAM
name|friend
name|Q_OPENGL_EXPORT
name|QDebug
name|operator
operator|<<
operator|(
name|QDebug
operator|,
specifier|const
name|QGLFormat
operator|&
operator|)
expr_stmt|;
endif|#
directive|endif
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_macro
name|Q_DECLARE_OPERATORS_FOR_FLAGS
argument_list|(
argument|QGLFormat::OpenGLVersionFlags
argument_list|)
end_macro
begin_expr_stmt
name|Q_OPENGL_EXPORT
name|bool
name|operator
operator|==
operator|(
specifier|const
name|QGLFormat
operator|&
operator|,
specifier|const
name|QGLFormat
operator|&
operator|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|Q_OPENGL_EXPORT
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|QGLFormat
operator|&
operator|,
specifier|const
name|QGLFormat
operator|&
operator|)
expr_stmt|;
end_expr_stmt
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_DEBUG_STREAM
end_ifndef
begin_expr_stmt
name|Q_OPENGL_EXPORT
name|QDebug
name|operator
operator|<<
operator|(
name|QDebug
operator|,
specifier|const
name|QGLFormat
operator|&
operator|)
expr_stmt|;
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_decl_stmt
DECL|variable|QGLFunctions
name|class
name|QGLFunctions
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_OPENGL_EXPORT
name|QGLContext
block|{
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QGLContext
argument_list|)
name|public
label|:
name|QGLContext
argument_list|(
specifier|const
name|QGLFormat
operator|&
name|format
argument_list|,
name|QPaintDevice
operator|*
name|device
argument_list|)
expr_stmt|;
name|QGLContext
argument_list|(
specifier|const
name|QGLFormat
operator|&
name|format
argument_list|)
expr_stmt|;
name|virtual
operator|~
name|QGLContext
argument_list|()
expr_stmt|;
name|virtual
name|bool
name|create
parameter_list|(
specifier|const
name|QGLContext
modifier|*
name|shareContext
init|=
literal|0
parameter_list|)
function_decl|;
name|bool
name|isValid
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|isSharing
argument_list|()
specifier|const
expr_stmt|;
name|void
name|reset
parameter_list|()
function_decl|;
specifier|static
name|bool
name|areSharing
parameter_list|(
specifier|const
name|QGLContext
modifier|*
name|context1
parameter_list|,
specifier|const
name|QGLContext
modifier|*
name|context2
parameter_list|)
function_decl|;
name|QGLFormat
name|format
argument_list|()
specifier|const
expr_stmt|;
name|QGLFormat
name|requestedFormat
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setFormat
parameter_list|(
specifier|const
name|QGLFormat
modifier|&
name|format
parameter_list|)
function_decl|;
name|virtual
name|void
name|makeCurrent
parameter_list|()
function_decl|;
name|virtual
name|void
name|doneCurrent
parameter_list|()
function_decl|;
name|virtual
name|void
name|swapBuffers
argument_list|()
specifier|const
expr_stmt|;
name|QGLFunctions
operator|*
name|functions
argument_list|()
specifier|const
expr_stmt|;
enum|enum
name|BindOption
block|{
name|NoBindOption
init|=
literal|0x0000
block|,
name|InvertedYBindOption
init|=
literal|0x0001
block|,
name|MipmapBindOption
init|=
literal|0x0002
block|,
name|PremultipliedAlphaBindOption
init|=
literal|0x0004
block|,
name|LinearFilteringBindOption
init|=
literal|0x0008
block|,
name|MemoryManagedBindOption
init|=
literal|0x0010
block|,
comment|// internal flag
name|CanFlipNativePixmapBindOption
init|=
literal|0x0020
block|,
comment|// internal flag
name|TemporarilyCachedBindOption
init|=
literal|0x0040
block|,
comment|// internal flag
name|DefaultBindOption
init|=
name|LinearFilteringBindOption
operator||
name|InvertedYBindOption
operator||
name|MipmapBindOption
block|,
name|InternalBindOption
init|=
name|MemoryManagedBindOption
operator||
name|PremultipliedAlphaBindOption
block|}
enum|;
name|Q_DECLARE_FLAGS
argument_list|(
argument|BindOptions
argument_list|,
argument|BindOption
argument_list|)
name|GLuint
name|bindTexture
parameter_list|(
specifier|const
name|QImage
modifier|&
name|image
parameter_list|,
name|GLenum
name|target
parameter_list|,
name|GLint
name|format
parameter_list|,
name|BindOptions
name|options
parameter_list|)
function_decl|;
name|GLuint
name|bindTexture
parameter_list|(
specifier|const
name|QPixmap
modifier|&
name|pixmap
parameter_list|,
name|GLenum
name|target
parameter_list|,
name|GLint
name|format
parameter_list|,
name|BindOptions
name|options
parameter_list|)
function_decl|;
name|GLuint
name|bindTexture
parameter_list|(
specifier|const
name|QImage
modifier|&
name|image
parameter_list|,
name|GLenum
name|target
init|=
name|GL_TEXTURE_2D
parameter_list|,
name|GLint
name|format
init|=
name|GL_RGBA
parameter_list|)
function_decl|;
name|GLuint
name|bindTexture
parameter_list|(
specifier|const
name|QPixmap
modifier|&
name|pixmap
parameter_list|,
name|GLenum
name|target
init|=
name|GL_TEXTURE_2D
parameter_list|,
name|GLint
name|format
init|=
name|GL_RGBA
parameter_list|)
function_decl|;
name|GLuint
name|bindTexture
parameter_list|(
specifier|const
name|QString
modifier|&
name|fileName
parameter_list|)
function_decl|;
name|void
name|deleteTexture
parameter_list|(
name|GLuint
name|tx_id
parameter_list|)
function_decl|;
name|void
name|drawTexture
parameter_list|(
specifier|const
name|QRectF
modifier|&
name|target
parameter_list|,
name|GLuint
name|textureId
parameter_list|,
name|GLenum
name|textureTarget
init|=
name|GL_TEXTURE_2D
parameter_list|)
function_decl|;
name|void
name|drawTexture
parameter_list|(
specifier|const
name|QPointF
modifier|&
name|point
parameter_list|,
name|GLuint
name|textureId
parameter_list|,
name|GLenum
name|textureTarget
init|=
name|GL_TEXTURE_2D
parameter_list|)
function_decl|;
specifier|static
name|void
name|setTextureCacheLimit
parameter_list|(
name|int
name|size
parameter_list|)
function_decl|;
specifier|static
name|int
name|textureCacheLimit
parameter_list|()
function_decl|;
name|QFunctionPointer
name|getProcAddress
argument_list|(
specifier|const
name|QString
operator|&
name|proc
argument_list|)
decl|const
decl_stmt|;
name|QPaintDevice
operator|*
name|device
argument_list|()
specifier|const
expr_stmt|;
name|QColor
name|overlayTransparentColor
argument_list|()
specifier|const
expr_stmt|;
specifier|static
specifier|const
name|QGLContext
modifier|*
name|currentContext
parameter_list|()
function_decl|;
specifier|static
name|QGLContext
modifier|*
name|fromOpenGLContext
parameter_list|(
name|QOpenGLContext
modifier|*
name|platformContext
parameter_list|)
function_decl|;
name|QOpenGLContext
operator|*
name|contextHandle
argument_list|()
specifier|const
expr_stmt|;
name|protected
label|:
name|virtual
name|bool
name|chooseContext
parameter_list|(
specifier|const
name|QGLContext
modifier|*
name|shareContext
init|=
literal|0
parameter_list|)
function_decl|;
name|bool
name|deviceIsPixmap
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|windowCreated
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setWindowCreated
parameter_list|(
name|bool
name|on
parameter_list|)
function_decl|;
name|bool
name|initialized
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setInitialized
parameter_list|(
name|bool
name|on
parameter_list|)
function_decl|;
name|void
name|generateFontDisplayLists
parameter_list|(
specifier|const
name|QFont
modifier|&
name|fnt
parameter_list|,
name|int
name|listBase
parameter_list|)
function_decl|;
name|uint
name|colorIndex
argument_list|(
specifier|const
name|QColor
operator|&
name|c
argument_list|)
decl|const
decl_stmt|;
name|void
name|setValid
parameter_list|(
name|bool
name|valid
parameter_list|)
function_decl|;
name|void
name|setDevice
parameter_list|(
name|QPaintDevice
modifier|*
name|pDev
parameter_list|)
function_decl|;
name|protected
label|:
specifier|static
name|QGLContext
modifier|*
name|currentCtx
decl_stmt|;
name|private
label|:
name|QGLContext
argument_list|(
name|QOpenGLContext
operator|*
name|windowContext
argument_list|)
expr_stmt|;
name|QScopedPointer
operator|<
name|QGLContextPrivate
operator|>
name|d_ptr
expr_stmt|;
name|friend
name|class
name|QGLPixelBuffer
decl_stmt|;
name|friend
name|class
name|QGLPixelBufferPrivate
decl_stmt|;
name|friend
name|class
name|QGLWidget
decl_stmt|;
name|friend
name|class
name|QGLWidgetPrivate
decl_stmt|;
name|friend
name|class
name|QGLGlyphCache
decl_stmt|;
name|friend
name|class
name|QGL2PaintEngineEx
decl_stmt|;
name|friend
name|class
name|QGL2PaintEngineExPrivate
decl_stmt|;
name|friend
name|class
name|QGLEngineShaderManager
decl_stmt|;
name|friend
name|class
name|QGLTextureGlyphCache
decl_stmt|;
name|friend
struct_decl|struct
name|QGLGlyphTexture
struct_decl|;
name|friend
name|class
name|QGLContextGroup
decl_stmt|;
name|friend
name|class
name|QGLPixmapBlurFilter
decl_stmt|;
name|friend
name|class
name|QGLExtensions
decl_stmt|;
name|friend
name|class
name|QGLTexture
decl_stmt|;
name|friend
name|QGLFormat
operator|::
name|OpenGLVersionFlags
name|QGLFormat
operator|::
name|openGLVersionFlags
argument_list|()
expr_stmt|;
name|friend
name|class
name|QGLFramebufferObject
decl_stmt|;
name|friend
name|class
name|QGLFramebufferObjectPrivate
decl_stmt|;
name|friend
name|class
name|QGLFBOGLPaintDevice
decl_stmt|;
name|friend
name|class
name|QGLPaintDevice
decl_stmt|;
name|friend
name|class
name|QGLWidgetGLPaintDevice
decl_stmt|;
name|friend
name|class
name|QX11GLSharedContexts
decl_stmt|;
name|friend
name|class
name|QGLContextResourceBase
decl_stmt|;
name|friend
name|class
name|QSGDistanceFieldGlyphCache
decl_stmt|;
name|private
label|:
name|Q_DISABLE_COPY
argument_list|(
argument|QGLContext
argument_list|)
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_macro
name|Q_DECLARE_OPERATORS_FOR_FLAGS
argument_list|(
argument|QGLContext::BindOptions
argument_list|)
end_macro
begin_decl_stmt
name|class
name|Q_OPENGL_EXPORT
name|QGLWidget
range|:
name|public
name|QWidget
block|{
name|Q_OBJECT
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QGLWidget
argument_list|)
name|public
operator|:
name|explicit
name|QGLWidget
argument_list|(
argument|QWidget* parent=
literal|0
argument_list|,
argument|const QGLWidget* shareWidget =
literal|0
argument_list|,
argument|Qt::WindowFlags f=
literal|0
argument_list|)
block|;
name|explicit
name|QGLWidget
argument_list|(
argument|QGLContext *context
argument_list|,
argument|QWidget* parent=
literal|0
argument_list|,
argument|const QGLWidget* shareWidget =
literal|0
argument_list|,
argument|Qt::WindowFlags f=
literal|0
argument_list|)
block|;
name|explicit
name|QGLWidget
argument_list|(
argument|const QGLFormat& format
argument_list|,
argument|QWidget* parent=
literal|0
argument_list|,
argument|const QGLWidget* shareWidget =
literal|0
argument_list|,
argument|Qt::WindowFlags f=
literal|0
argument_list|)
block|;
operator|~
name|QGLWidget
argument_list|()
block|;
name|void
name|qglColor
argument_list|(
argument|const QColor& c
argument_list|)
specifier|const
block|;
name|void
name|qglClearColor
argument_list|(
argument|const QColor& c
argument_list|)
specifier|const
block|;
name|bool
name|isValid
argument_list|()
specifier|const
block|;
name|bool
name|isSharing
argument_list|()
specifier|const
block|;
name|void
name|makeCurrent
argument_list|()
block|;
name|void
name|doneCurrent
argument_list|()
block|;
name|bool
name|doubleBuffer
argument_list|()
specifier|const
block|;
name|void
name|swapBuffers
argument_list|()
block|;
name|QGLFormat
name|format
argument_list|()
specifier|const
block|;
name|void
name|setFormat
argument_list|(
specifier|const
name|QGLFormat
operator|&
name|format
argument_list|)
block|;
specifier|const
name|QGLContext
operator|*
name|context
argument_list|()
specifier|const
block|;
name|void
name|setContext
argument_list|(
argument|QGLContext* context
argument_list|,
argument|const QGLContext* shareContext =
literal|0
argument_list|,
argument|bool deleteOldContext = true
argument_list|)
block|;
name|QPixmap
name|renderPixmap
argument_list|(
argument|int w =
literal|0
argument_list|,
argument|int h =
literal|0
argument_list|,
argument|bool useContext = false
argument_list|)
block|;
name|QImage
name|grabFrameBuffer
argument_list|(
argument|bool withAlpha = false
argument_list|)
block|;
name|void
name|makeOverlayCurrent
argument_list|()
block|;
specifier|const
name|QGLContext
operator|*
name|overlayContext
argument_list|()
specifier|const
block|;
specifier|static
name|QImage
name|convertToGLFormat
argument_list|(
specifier|const
name|QImage
operator|&
name|img
argument_list|)
block|;
name|void
name|setMouseTracking
argument_list|(
argument|bool enable
argument_list|)
block|;
specifier|const
name|QGLColormap
operator|&
name|colormap
argument_list|()
specifier|const
block|;
name|void
name|setColormap
argument_list|(
specifier|const
name|QGLColormap
operator|&
name|map
argument_list|)
block|;
name|void
name|renderText
argument_list|(
argument|int x
argument_list|,
argument|int y
argument_list|,
argument|const QString& str
argument_list|,
argument|const QFont& fnt = QFont()
argument_list|,
argument|int listBase =
literal|2000
argument_list|)
block|;
name|void
name|renderText
argument_list|(
argument|double x
argument_list|,
argument|double y
argument_list|,
argument|double z
argument_list|,
argument|const QString& str
argument_list|,
argument|const QFont& fnt = QFont()
argument_list|,
argument|int listBase =
literal|2000
argument_list|)
block|;
name|QPaintEngine
operator|*
name|paintEngine
argument_list|()
specifier|const
block|;
name|GLuint
name|bindTexture
argument_list|(
argument|const QImage&image
argument_list|,
argument|GLenum target
argument_list|,
argument|GLint format
argument_list|,
argument|QGLContext::BindOptions options
argument_list|)
block|;
name|GLuint
name|bindTexture
argument_list|(
argument|const QPixmap&pixmap
argument_list|,
argument|GLenum target
argument_list|,
argument|GLint format
argument_list|,
argument|QGLContext::BindOptions options
argument_list|)
block|;
name|GLuint
name|bindTexture
argument_list|(
argument|const QImage&image
argument_list|,
argument|GLenum target = GL_TEXTURE_2D
argument_list|,
argument|GLint format = GL_RGBA
argument_list|)
block|;
name|GLuint
name|bindTexture
argument_list|(
argument|const QPixmap&pixmap
argument_list|,
argument|GLenum target = GL_TEXTURE_2D
argument_list|,
argument|GLint format = GL_RGBA
argument_list|)
block|;
name|GLuint
name|bindTexture
argument_list|(
specifier|const
name|QString
operator|&
name|fileName
argument_list|)
block|;
name|void
name|deleteTexture
argument_list|(
argument|GLuint tx_id
argument_list|)
block|;
name|void
name|drawTexture
argument_list|(
argument|const QRectF&target
argument_list|,
argument|GLuint textureId
argument_list|,
argument|GLenum textureTarget = GL_TEXTURE_2D
argument_list|)
block|;
name|void
name|drawTexture
argument_list|(
argument|const QPointF&point
argument_list|,
argument|GLuint textureId
argument_list|,
argument|GLenum textureTarget = GL_TEXTURE_2D
argument_list|)
block|;
name|public
name|Q_SLOTS
operator|:
name|virtual
name|void
name|updateGL
argument_list|()
block|;
name|virtual
name|void
name|updateOverlayGL
argument_list|()
block|;
name|protected
operator|:
name|bool
name|event
argument_list|(
name|QEvent
operator|*
argument_list|)
block|;
name|virtual
name|void
name|initializeGL
argument_list|()
block|;
name|virtual
name|void
name|resizeGL
argument_list|(
argument|int w
argument_list|,
argument|int h
argument_list|)
block|;
name|virtual
name|void
name|paintGL
argument_list|()
block|;
name|virtual
name|void
name|initializeOverlayGL
argument_list|()
block|;
name|virtual
name|void
name|resizeOverlayGL
argument_list|(
argument|int w
argument_list|,
argument|int h
argument_list|)
block|;
name|virtual
name|void
name|paintOverlayGL
argument_list|()
block|;
name|void
name|setAutoBufferSwap
argument_list|(
argument|bool on
argument_list|)
block|;
name|bool
name|autoBufferSwap
argument_list|()
specifier|const
block|;
name|void
name|paintEvent
argument_list|(
name|QPaintEvent
operator|*
argument_list|)
block|;
name|void
name|resizeEvent
argument_list|(
name|QResizeEvent
operator|*
argument_list|)
block|;
name|virtual
name|void
name|glInit
argument_list|()
block|;
name|virtual
name|void
name|glDraw
argument_list|()
block|;
name|int
name|fontDisplayListBase
argument_list|(
argument|const QFont& fnt
argument_list|,
argument|int listBase =
literal|2000
argument_list|)
block|;
name|QGLWidget
argument_list|(
argument|QGLWidgetPrivate&dd
argument_list|,
argument|const QGLFormat&format = QGLFormat()
argument_list|,
argument|QWidget *parent =
literal|0
argument_list|,
argument|const QGLWidget* shareWidget =
literal|0
argument_list|,
argument|Qt::WindowFlags f =
literal|0
argument_list|)
block|;
name|private
operator|:
name|Q_DISABLE_COPY
argument_list|(
argument|QGLWidget
argument_list|)
name|friend
name|class
name|QGLDrawable
block|;
name|friend
name|class
name|QGLPixelBuffer
block|;
name|friend
name|class
name|QGLPixelBufferPrivate
block|;
name|friend
name|class
name|QGLContext
block|;
name|friend
name|class
name|QGLContextPrivate
block|;
name|friend
name|class
name|QGLOverlayWidget
block|;
name|friend
name|class
name|QGLPaintDevice
block|;
name|friend
name|class
name|QGLWidgetGLPaintDevice
block|; }
decl_stmt|;
end_decl_stmt
begin_comment
comment|//
end_comment
begin_comment
comment|// QGLFormat inline functions
end_comment
begin_comment
comment|//
end_comment
begin_expr_stmt
DECL|function|doubleBuffer
specifier|inline
name|bool
name|QGLFormat
operator|::
name|doubleBuffer
argument_list|()
specifier|const
block|{
return|return
name|testOption
argument_list|(
name|QGL
operator|::
name|DoubleBuffer
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|depth
specifier|inline
name|bool
name|QGLFormat
operator|::
name|depth
argument_list|()
specifier|const
block|{
return|return
name|testOption
argument_list|(
name|QGL
operator|::
name|DepthBuffer
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|rgba
specifier|inline
name|bool
name|QGLFormat
operator|::
name|rgba
argument_list|()
specifier|const
block|{
return|return
name|testOption
argument_list|(
name|QGL
operator|::
name|Rgba
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|alpha
specifier|inline
name|bool
name|QGLFormat
operator|::
name|alpha
argument_list|()
specifier|const
block|{
return|return
name|testOption
argument_list|(
name|QGL
operator|::
name|AlphaChannel
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|accum
specifier|inline
name|bool
name|QGLFormat
operator|::
name|accum
argument_list|()
specifier|const
block|{
return|return
name|testOption
argument_list|(
name|QGL
operator|::
name|AccumBuffer
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|stencil
specifier|inline
name|bool
name|QGLFormat
operator|::
name|stencil
argument_list|()
specifier|const
block|{
return|return
name|testOption
argument_list|(
name|QGL
operator|::
name|StencilBuffer
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|stereo
specifier|inline
name|bool
name|QGLFormat
operator|::
name|stereo
argument_list|()
specifier|const
block|{
return|return
name|testOption
argument_list|(
name|QGL
operator|::
name|StereoBuffers
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|directRendering
specifier|inline
name|bool
name|QGLFormat
operator|::
name|directRendering
argument_list|()
specifier|const
block|{
return|return
name|testOption
argument_list|(
name|QGL
operator|::
name|DirectRendering
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|hasOverlay
specifier|inline
name|bool
name|QGLFormat
operator|::
name|hasOverlay
argument_list|()
specifier|const
block|{
return|return
name|testOption
argument_list|(
name|QGL
operator|::
name|HasOverlay
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|sampleBuffers
specifier|inline
name|bool
name|QGLFormat
operator|::
name|sampleBuffers
argument_list|()
specifier|const
block|{
return|return
name|testOption
argument_list|(
name|QGL
operator|::
name|SampleBuffers
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|QT_END_NAMESPACE
name|QT_END_HEADER
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_OPENGL
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QGL_H
end_comment
end_unit
