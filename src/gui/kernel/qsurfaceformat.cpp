begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qsurfaceformat.h"
end_include
begin_include
include|#
directive|include
file|<QtCore/qatomic.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/QDebug>
end_include
begin_ifdef
ifdef|#
directive|ifdef
name|major
end_ifdef
begin_undef
DECL|macro|major
undef|#
directive|undef
name|major
end_undef
begin_endif
endif|#
directive|endif
end_endif
begin_ifdef
ifdef|#
directive|ifdef
name|minor
end_ifdef
begin_undef
DECL|macro|minor
undef|#
directive|undef
name|minor
end_undef
begin_endif
endif|#
directive|endif
end_endif
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_class
DECL|class|QSurfaceFormatPrivate
class|class
name|QSurfaceFormatPrivate
block|{
public|public:
DECL|function|QSurfaceFormatPrivate
specifier|explicit
name|QSurfaceFormatPrivate
parameter_list|(
name|QSurfaceFormat
operator|::
name|FormatOptions
name|_opts
init|=
literal|0
parameter_list|)
member_init_list|:
name|ref
argument_list|(
literal|1
argument_list|)
member_init_list|,
name|opts
argument_list|(
name|_opts
argument_list|)
member_init_list|,
name|redBufferSize
argument_list|(
operator|-
literal|1
argument_list|)
member_init_list|,
name|greenBufferSize
argument_list|(
operator|-
literal|1
argument_list|)
member_init_list|,
name|blueBufferSize
argument_list|(
operator|-
literal|1
argument_list|)
member_init_list|,
name|alphaBufferSize
argument_list|(
operator|-
literal|1
argument_list|)
member_init_list|,
name|depthSize
argument_list|(
operator|-
literal|1
argument_list|)
member_init_list|,
name|stencilSize
argument_list|(
operator|-
literal|1
argument_list|)
member_init_list|,
name|swapBehavior
argument_list|(
name|QSurfaceFormat
operator|::
name|DefaultSwapBehavior
argument_list|)
member_init_list|,
name|numSamples
argument_list|(
operator|-
literal|1
argument_list|)
member_init_list|,
name|renderableType
argument_list|(
name|QSurfaceFormat
operator|::
name|DefaultRenderableType
argument_list|)
member_init_list|,
name|profile
argument_list|(
name|QSurfaceFormat
operator|::
name|NoProfile
argument_list|)
member_init_list|,
name|major
argument_list|(
literal|2
argument_list|)
member_init_list|,
name|minor
argument_list|(
literal|0
argument_list|)
block|{     }
DECL|function|QSurfaceFormatPrivate
name|QSurfaceFormatPrivate
parameter_list|(
specifier|const
name|QSurfaceFormatPrivate
modifier|*
name|other
parameter_list|)
member_init_list|:
name|ref
argument_list|(
literal|1
argument_list|)
member_init_list|,
name|opts
argument_list|(
name|other
operator|->
name|opts
argument_list|)
member_init_list|,
name|redBufferSize
argument_list|(
name|other
operator|->
name|redBufferSize
argument_list|)
member_init_list|,
name|greenBufferSize
argument_list|(
name|other
operator|->
name|greenBufferSize
argument_list|)
member_init_list|,
name|blueBufferSize
argument_list|(
name|other
operator|->
name|blueBufferSize
argument_list|)
member_init_list|,
name|alphaBufferSize
argument_list|(
name|other
operator|->
name|alphaBufferSize
argument_list|)
member_init_list|,
name|depthSize
argument_list|(
name|other
operator|->
name|depthSize
argument_list|)
member_init_list|,
name|stencilSize
argument_list|(
name|other
operator|->
name|stencilSize
argument_list|)
member_init_list|,
name|swapBehavior
argument_list|(
name|other
operator|->
name|swapBehavior
argument_list|)
member_init_list|,
name|numSamples
argument_list|(
name|other
operator|->
name|numSamples
argument_list|)
member_init_list|,
name|renderableType
argument_list|(
name|other
operator|->
name|renderableType
argument_list|)
member_init_list|,
name|profile
argument_list|(
name|other
operator|->
name|profile
argument_list|)
member_init_list|,
name|major
argument_list|(
name|other
operator|->
name|major
argument_list|)
member_init_list|,
name|minor
argument_list|(
name|other
operator|->
name|minor
argument_list|)
block|{     }
DECL|member|ref
name|QAtomicInt
name|ref
decl_stmt|;
DECL|member|opts
name|QSurfaceFormat
operator|::
name|FormatOptions
name|opts
decl_stmt|;
DECL|member|redBufferSize
name|int
name|redBufferSize
decl_stmt|;
DECL|member|greenBufferSize
name|int
name|greenBufferSize
decl_stmt|;
DECL|member|blueBufferSize
name|int
name|blueBufferSize
decl_stmt|;
DECL|member|alphaBufferSize
name|int
name|alphaBufferSize
decl_stmt|;
DECL|member|depthSize
name|int
name|depthSize
decl_stmt|;
DECL|member|stencilSize
name|int
name|stencilSize
decl_stmt|;
DECL|member|swapBehavior
name|QSurfaceFormat
operator|::
name|SwapBehavior
name|swapBehavior
decl_stmt|;
DECL|member|numSamples
name|int
name|numSamples
decl_stmt|;
DECL|member|renderableType
name|QSurfaceFormat
operator|::
name|RenderableType
name|renderableType
decl_stmt|;
DECL|member|profile
name|QSurfaceFormat
operator|::
name|OpenGLContextProfile
name|profile
decl_stmt|;
DECL|member|major
name|int
name|major
decl_stmt|;
DECL|member|minor
name|int
name|minor
decl_stmt|;
block|}
class|;
end_class
begin_comment
comment|/*!     \class QSurfaceFormat     \since 5.0     \brief The QSurfaceFormat class represents the format of a QSurface.     \inmodule QtGui      The format includes the size of the color buffers, red, green, and blue;     the size of the alpha buffer; the size of the depth and stencil buffers;     and number of samples per pixel for multisampling. In addition, the format     contains surface configuration parameters such as OpenGL profile and     version for rendering, whether or not enable stereo buffers, and swap     behaviour. */
end_comment
begin_comment
comment|/*!     \enum QSurfaceFormat::FormatOption      This enum contains format options for use with QSurfaceFormat.      \value StereoBuffers Used to request stereo buffers in the surface format.     \value DebugContext Used to request a debug context with extra debugging information.         This requires OpenGL version 3.0 or higher.     \value DeprecatedFunctions Used to request that deprecated functions be included         in the OpenGL context profile. If not specified, you should get a forward compatible context         without support functionality marked as deprecated. This requires OpenGL version 3.0 or higher. */
end_comment
begin_comment
comment|/*!     \enum QSurfaceFormat::SwapBehavior      This enum is used by QSurfaceFormat to specify the swap behaviour of a surface. The swap behaviour     is mostly transparent to the application, but it affects factors such as rendering latency and     throughput.      \value DefaultSwapBehavior The default, unspecified swap behaviour of the platform.     \value SingleBuffer Used to request single buffering, which might result in flickering         when OpenGL rendering is done directly to screen without an intermediate offscreen         buffer.     \value DoubleBuffer This is typically the default swap behaviour on desktop platforms,         consisting of one back buffer and one front buffer. Rendering is done to the back         buffer, and then the back buffer and front buffer are swapped, or the contents of         the back buffer are copied to the front buffer, depending on the implementation.     \value TripleBuffer This swap behaviour is sometimes used in order to decrease the         risk of skipping a frame when the rendering rate is just barely keeping up with         the screen refresh rate. Depending on the platform it might also lead to slightly         more efficient use of the GPU due to improved pipelining behaviour. Triple buffering         comes at the cost of an extra frame of memory usage and latency, and might not be         supported depending on the underlying platform. */
end_comment
begin_comment
comment|/*!     \enum QSurfaceFormat::OpenGLContextProfile      This enum is used to specify the OpenGL context profile, in     conjunction with QSurfaceFormat::setMajorVersion() and     QSurfaceFormat::setMinorVersion().      Profiles are exposed in OpenGL 3.2 and above, and are used     to choose between a restricted core profile, and a compatibility     profile which might contain deprecated support functionality.      Note that the core profile might still contain functionality that     is deprecated and scheduled for removal in a higher version. To     get access to the deprecated functionality for the core profile     in the set OpenGL version you can use the QSurfaceFormat format option     QSurfaceFormat::DeprecatedFunctions.      \value NoProfile            OpenGL version is lower than 3.2.     \value CoreProfile          Functionality deprecated in OpenGL version 3.0 is not available.     \value CompatibilityProfile Functionality from earlier OpenGL versions is available. */
end_comment
begin_comment
comment|/*!     Constructs a default initialized QSurfaceFormat. */
end_comment
begin_constructor
DECL|function|QSurfaceFormat
name|QSurfaceFormat
operator|::
name|QSurfaceFormat
parameter_list|()
member_init_list|:
name|d
argument_list|(
operator|new
name|QSurfaceFormatPrivate
argument_list|)
block|{ }
end_constructor
begin_comment
comment|/*!     Constructs a QSurfaceFormat with the given format \a options. */
end_comment
begin_constructor
DECL|function|QSurfaceFormat
name|QSurfaceFormat
operator|::
name|QSurfaceFormat
parameter_list|(
name|QSurfaceFormat
operator|::
name|FormatOptions
name|options
parameter_list|)
member_init_list|:
name|d
argument_list|(
operator|new
name|QSurfaceFormatPrivate
argument_list|(
name|options
argument_list|)
argument_list|)
block|{ }
end_constructor
begin_comment
comment|/*!     \internal */
end_comment
begin_function
DECL|function|detach
name|void
name|QSurfaceFormat
operator|::
name|detach
parameter_list|()
block|{
if|if
condition|(
name|d
operator|->
name|ref
operator|.
name|load
argument_list|()
operator|!=
literal|1
condition|)
block|{
name|QSurfaceFormatPrivate
modifier|*
name|newd
init|=
operator|new
name|QSurfaceFormatPrivate
argument_list|(
name|d
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|d
operator|->
name|ref
operator|.
name|deref
argument_list|()
condition|)
operator|delete
name|d
expr_stmt|;
name|d
operator|=
name|newd
expr_stmt|;
block|}
block|}
end_function
begin_comment
comment|/*!     Constructs a copy of \a other. */
end_comment
begin_constructor
DECL|function|QSurfaceFormat
name|QSurfaceFormat
operator|::
name|QSurfaceFormat
parameter_list|(
specifier|const
name|QSurfaceFormat
modifier|&
name|other
parameter_list|)
block|{
name|d
operator|=
name|other
operator|.
name|d
expr_stmt|;
name|d
operator|->
name|ref
operator|.
name|ref
parameter_list|()
constructor_decl|;
block|}
end_constructor
begin_comment
comment|/*!     Assigns \a other to this object. */
end_comment
begin_function
DECL|function|operator =
name|QSurfaceFormat
modifier|&
name|QSurfaceFormat
operator|::
name|operator
name|=
parameter_list|(
specifier|const
name|QSurfaceFormat
modifier|&
name|other
parameter_list|)
block|{
if|if
condition|(
name|d
operator|!=
name|other
operator|.
name|d
condition|)
block|{
name|other
operator|.
name|d
operator|->
name|ref
operator|.
name|ref
parameter_list|()
constructor_decl|;
if|if
condition|(
operator|!
name|d
operator|->
name|ref
operator|.
name|deref
argument_list|()
condition|)
operator|delete
name|d
expr_stmt|;
name|d
operator|=
name|other
operator|.
name|d
expr_stmt|;
block|}
return|return
operator|*
name|this
return|;
block|}
end_function
begin_comment
comment|/*!     Destroys the QSurfaceFormat. */
end_comment
begin_destructor
DECL|function|~QSurfaceFormat
name|QSurfaceFormat
operator|::
name|~
name|QSurfaceFormat
parameter_list|()
block|{
if|if
condition|(
operator|!
name|d
operator|->
name|ref
operator|.
name|deref
argument_list|()
condition|)
operator|delete
name|d
expr_stmt|;
block|}
end_destructor
begin_comment
comment|/*!     \fn bool QSurfaceFormat::stereo() const      Returns true if stereo buffering is enabled; otherwise returns     false. Stereo buffering is disabled by default.      \sa setStereo() */
end_comment
begin_comment
comment|/*!     If \a enable is true enables stereo buffering; otherwise disables     stereo buffering.      Stereo buffering is disabled by default.      Stereo buffering provides extra color buffers to generate left-eye     and right-eye images.      \sa stereo() */
end_comment
begin_function
DECL|function|setStereo
name|void
name|QSurfaceFormat
operator|::
name|setStereo
parameter_list|(
name|bool
name|enable
parameter_list|)
block|{
name|QSurfaceFormat
operator|::
name|FormatOptions
name|newOptions
init|=
name|d
operator|->
name|opts
decl_stmt|;
if|if
condition|(
name|enable
condition|)
block|{
name|newOptions
operator||=
name|QSurfaceFormat
operator|::
name|StereoBuffers
expr_stmt|;
block|}
else|else
block|{
name|newOptions
operator|&=
operator|~
name|QSurfaceFormat
operator|::
name|StereoBuffers
expr_stmt|;
block|}
if|if
condition|(
name|int
argument_list|(
name|newOptions
argument_list|)
operator|!=
name|int
argument_list|(
name|d
operator|->
name|opts
argument_list|)
condition|)
block|{
name|detach
argument_list|()
expr_stmt|;
name|d
operator|->
name|opts
operator|=
name|newOptions
expr_stmt|;
block|}
block|}
end_function
begin_comment
comment|/*!     Returns the number of samples per pixel when multisampling is     enabled. By default, multisampling is disabled.      \sa setSampleBuffers(), sampleBuffers(), setSamples() */
end_comment
begin_function
DECL|function|samples
name|int
name|QSurfaceFormat
operator|::
name|samples
parameter_list|()
specifier|const
block|{
return|return
name|d
operator|->
name|numSamples
return|;
block|}
end_function
begin_comment
comment|/*!     Set the preferred number of samples per pixel when multisampling     is enabled to \a numSamples. By default, multisampling is disabled.      \sa setSampleBuffers(), sampleBuffers(), samples() */
end_comment
begin_function
DECL|function|setSamples
name|void
name|QSurfaceFormat
operator|::
name|setSamples
parameter_list|(
name|int
name|numSamples
parameter_list|)
block|{
if|if
condition|(
name|d
operator|->
name|numSamples
operator|!=
name|numSamples
condition|)
block|{
name|detach
argument_list|()
expr_stmt|;
name|d
operator|->
name|numSamples
operator|=
name|numSamples
expr_stmt|;
block|}
block|}
end_function
begin_comment
comment|/*!     Sets the format option to \a opt.      \sa testOption() */
end_comment
begin_function
DECL|function|setOption
name|void
name|QSurfaceFormat
operator|::
name|setOption
parameter_list|(
name|QSurfaceFormat
operator|::
name|FormatOptions
name|opt
parameter_list|)
block|{
specifier|const
name|QSurfaceFormat
operator|::
name|FormatOptions
name|newOptions
init|=
name|d
operator|->
name|opts
operator||
name|opt
decl_stmt|;
if|if
condition|(
name|int
argument_list|(
name|newOptions
argument_list|)
operator|!=
name|int
argument_list|(
name|d
operator|->
name|opts
argument_list|)
condition|)
block|{
name|detach
argument_list|()
expr_stmt|;
name|d
operator|->
name|opts
operator|=
name|newOptions
expr_stmt|;
block|}
block|}
end_function
begin_comment
comment|/*!     Returns true if format option \a opt is set; otherwise returns false.      \sa setOption() */
end_comment
begin_function
DECL|function|testOption
name|bool
name|QSurfaceFormat
operator|::
name|testOption
parameter_list|(
name|QSurfaceFormat
operator|::
name|FormatOptions
name|opt
parameter_list|)
specifier|const
block|{
return|return
name|d
operator|->
name|opts
operator|&
name|opt
return|;
block|}
end_function
begin_comment
comment|/*!     Set the minimum depth buffer size to \a size.      \sa depthBufferSize(), setDepth(), depth() */
end_comment
begin_function
DECL|function|setDepthBufferSize
name|void
name|QSurfaceFormat
operator|::
name|setDepthBufferSize
parameter_list|(
name|int
name|size
parameter_list|)
block|{
if|if
condition|(
name|d
operator|->
name|depthSize
operator|!=
name|size
condition|)
block|{
name|detach
argument_list|()
expr_stmt|;
name|d
operator|->
name|depthSize
operator|=
name|size
expr_stmt|;
block|}
block|}
end_function
begin_comment
comment|/*!     Returns the depth buffer size.      \sa depth(), setDepth(), setDepthBufferSize() */
end_comment
begin_function
DECL|function|depthBufferSize
name|int
name|QSurfaceFormat
operator|::
name|depthBufferSize
parameter_list|()
specifier|const
block|{
return|return
name|d
operator|->
name|depthSize
return|;
block|}
end_function
begin_comment
comment|/*!     Set the swap behaviour of the surface.      The swap behaviour specifies whether single, double, or triple     buffering is desired. The default, SwapBehavior::DefaultSwapBehavior,     gives the default swap behavior of the platform. */
end_comment
begin_function
DECL|function|setSwapBehavior
name|void
name|QSurfaceFormat
operator|::
name|setSwapBehavior
parameter_list|(
name|SwapBehavior
name|behavior
parameter_list|)
block|{
if|if
condition|(
name|d
operator|->
name|swapBehavior
operator|!=
name|behavior
condition|)
block|{
name|detach
argument_list|()
expr_stmt|;
name|d
operator|->
name|swapBehavior
operator|=
name|behavior
expr_stmt|;
block|}
block|}
end_function
begin_comment
comment|/*!     Returns the configured swap behaviour.      \sa setSwapBehavior() */
end_comment
begin_function
DECL|function|swapBehavior
name|QSurfaceFormat
operator|::
name|SwapBehavior
name|QSurfaceFormat
operator|::
name|swapBehavior
parameter_list|()
specifier|const
block|{
return|return
name|d
operator|->
name|swapBehavior
return|;
block|}
end_function
begin_comment
comment|/*!     Returns true if the alpha buffer size is greater than zero.      This means that the surface might be used with per pixel     translucency effects. */
end_comment
begin_function
DECL|function|hasAlpha
name|bool
name|QSurfaceFormat
operator|::
name|hasAlpha
parameter_list|()
specifier|const
block|{
return|return
name|d
operator|->
name|alphaBufferSize
operator|>
literal|0
return|;
block|}
end_function
begin_comment
comment|/*!     Set the preferred stencil buffer size to \a size bits.      \sa stencilBufferSize(), setStencil(), stencil() */
end_comment
begin_function
DECL|function|setStencilBufferSize
name|void
name|QSurfaceFormat
operator|::
name|setStencilBufferSize
parameter_list|(
name|int
name|size
parameter_list|)
block|{
if|if
condition|(
name|d
operator|->
name|stencilSize
operator|!=
name|size
condition|)
block|{
name|detach
argument_list|()
expr_stmt|;
name|d
operator|->
name|stencilSize
operator|=
name|size
expr_stmt|;
block|}
block|}
end_function
begin_comment
comment|/*!     Returns the stencil buffer size in bits.      \sa stencil(), setStencil(), setStencilBufferSize() */
end_comment
begin_function
DECL|function|stencilBufferSize
name|int
name|QSurfaceFormat
operator|::
name|stencilBufferSize
parameter_list|()
specifier|const
block|{
return|return
name|d
operator|->
name|stencilSize
return|;
block|}
end_function
begin_comment
comment|/*!     Get the size in bits of the red channel of the color buffer. */
end_comment
begin_function
DECL|function|redBufferSize
name|int
name|QSurfaceFormat
operator|::
name|redBufferSize
parameter_list|()
specifier|const
block|{
return|return
name|d
operator|->
name|redBufferSize
return|;
block|}
end_function
begin_comment
comment|/*!     Get the size in bits of the green channel of the color buffer. */
end_comment
begin_function
DECL|function|greenBufferSize
name|int
name|QSurfaceFormat
operator|::
name|greenBufferSize
parameter_list|()
specifier|const
block|{
return|return
name|d
operator|->
name|greenBufferSize
return|;
block|}
end_function
begin_comment
comment|/*!     Get the size in bits of the blue channel of the color buffer. */
end_comment
begin_function
DECL|function|blueBufferSize
name|int
name|QSurfaceFormat
operator|::
name|blueBufferSize
parameter_list|()
specifier|const
block|{
return|return
name|d
operator|->
name|blueBufferSize
return|;
block|}
end_function
begin_comment
comment|/*!     Get the size in bits of the alpha channel of the color buffer. */
end_comment
begin_function
DECL|function|alphaBufferSize
name|int
name|QSurfaceFormat
operator|::
name|alphaBufferSize
parameter_list|()
specifier|const
block|{
return|return
name|d
operator|->
name|alphaBufferSize
return|;
block|}
end_function
begin_comment
comment|/*!     Set the desired size in bits of the red channel of the color buffer. */
end_comment
begin_function
DECL|function|setRedBufferSize
name|void
name|QSurfaceFormat
operator|::
name|setRedBufferSize
parameter_list|(
name|int
name|size
parameter_list|)
block|{
if|if
condition|(
name|d
operator|->
name|redBufferSize
operator|!=
name|size
condition|)
block|{
name|detach
argument_list|()
expr_stmt|;
name|d
operator|->
name|redBufferSize
operator|=
name|size
expr_stmt|;
block|}
block|}
end_function
begin_comment
comment|/*!     Set the desired size in bits of the green channel of the color buffer. */
end_comment
begin_function
DECL|function|setGreenBufferSize
name|void
name|QSurfaceFormat
operator|::
name|setGreenBufferSize
parameter_list|(
name|int
name|size
parameter_list|)
block|{
if|if
condition|(
name|d
operator|->
name|greenBufferSize
operator|!=
name|size
condition|)
block|{
name|detach
argument_list|()
expr_stmt|;
name|d
operator|->
name|greenBufferSize
operator|=
name|size
expr_stmt|;
block|}
block|}
end_function
begin_comment
comment|/*!     Set the desired size in bits of the blue channel of the color buffer. */
end_comment
begin_function
DECL|function|setBlueBufferSize
name|void
name|QSurfaceFormat
operator|::
name|setBlueBufferSize
parameter_list|(
name|int
name|size
parameter_list|)
block|{
if|if
condition|(
name|d
operator|->
name|blueBufferSize
operator|!=
name|size
condition|)
block|{
name|detach
argument_list|()
expr_stmt|;
name|d
operator|->
name|blueBufferSize
operator|=
name|size
expr_stmt|;
block|}
block|}
end_function
begin_comment
comment|/*!     Set the desired size in bits of the alpha channel of the color buffer. */
end_comment
begin_function
DECL|function|setAlphaBufferSize
name|void
name|QSurfaceFormat
operator|::
name|setAlphaBufferSize
parameter_list|(
name|int
name|size
parameter_list|)
block|{
if|if
condition|(
name|d
operator|->
name|alphaBufferSize
operator|!=
name|size
condition|)
block|{
name|detach
argument_list|()
expr_stmt|;
name|d
operator|->
name|alphaBufferSize
operator|=
name|size
expr_stmt|;
block|}
block|}
end_function
begin_comment
comment|/*!     Sets the desired renderable type.      Chooses between desktop OpenGL, OpenGL ES, and OpenVG. */
end_comment
begin_function
DECL|function|setRenderableType
name|void
name|QSurfaceFormat
operator|::
name|setRenderableType
parameter_list|(
name|RenderableType
name|type
parameter_list|)
block|{
if|if
condition|(
name|d
operator|->
name|renderableType
operator|!=
name|type
condition|)
block|{
name|detach
argument_list|()
expr_stmt|;
name|d
operator|->
name|renderableType
operator|=
name|type
expr_stmt|;
block|}
block|}
end_function
begin_comment
comment|/*!     Gets the renderable type.      Chooses between desktop OpenGL, OpenGL ES, and OpenVG. */
end_comment
begin_function
DECL|function|renderableType
name|QSurfaceFormat
operator|::
name|RenderableType
name|QSurfaceFormat
operator|::
name|renderableType
parameter_list|()
specifier|const
block|{
return|return
name|d
operator|->
name|renderableType
return|;
block|}
end_function
begin_comment
comment|/*!     Sets the desired OpenGL context profile.      This setting is ignored if the requested OpenGL version is     less than 3.2. */
end_comment
begin_function
DECL|function|setProfile
name|void
name|QSurfaceFormat
operator|::
name|setProfile
parameter_list|(
name|OpenGLContextProfile
name|profile
parameter_list|)
block|{
if|if
condition|(
name|d
operator|->
name|profile
operator|!=
name|profile
condition|)
block|{
name|detach
argument_list|()
expr_stmt|;
name|d
operator|->
name|profile
operator|=
name|profile
expr_stmt|;
block|}
block|}
end_function
begin_comment
comment|/*!     Get the configured OpenGL context profile.      This setting is ignored if the requested OpenGL version is     less than 3.2. */
end_comment
begin_function
DECL|function|profile
name|QSurfaceFormat
operator|::
name|OpenGLContextProfile
name|QSurfaceFormat
operator|::
name|profile
parameter_list|()
specifier|const
block|{
return|return
name|d
operator|->
name|profile
return|;
block|}
end_function
begin_comment
comment|/*!     Sets the desired major OpenGL version. */
end_comment
begin_function
DECL|function|setMajorVersion
name|void
name|QSurfaceFormat
operator|::
name|setMajorVersion
parameter_list|(
name|int
name|major
parameter_list|)
block|{
if|if
condition|(
name|d
operator|->
name|major
operator|!=
name|major
condition|)
block|{
name|detach
argument_list|()
expr_stmt|;
name|d
operator|->
name|major
operator|=
name|major
expr_stmt|;
block|}
block|}
end_function
begin_comment
comment|/*!     Returns the major OpenGL version.      The default version is 2.0. */
end_comment
begin_function
DECL|function|majorVersion
name|int
name|QSurfaceFormat
operator|::
name|majorVersion
parameter_list|()
specifier|const
block|{
return|return
name|d
operator|->
name|major
return|;
block|}
end_function
begin_comment
comment|/*!     Sets the desired minor OpenGL version.      The default version is 2.0. */
end_comment
begin_function
DECL|function|setMinorVersion
name|void
name|QSurfaceFormat
operator|::
name|setMinorVersion
parameter_list|(
name|int
name|minor
parameter_list|)
block|{
if|if
condition|(
name|d
operator|->
name|minor
operator|!=
name|minor
condition|)
block|{
name|detach
argument_list|()
expr_stmt|;
name|d
operator|->
name|minor
operator|=
name|minor
expr_stmt|;
block|}
block|}
end_function
begin_comment
comment|/*!     Returns the minor OpenGL version. */
end_comment
begin_function
DECL|function|minorVersion
name|int
name|QSurfaceFormat
operator|::
name|minorVersion
parameter_list|()
specifier|const
block|{
return|return
name|d
operator|->
name|minor
return|;
block|}
end_function
begin_comment
comment|/*!     Returns true if all the options of the two QSurfaceFormat objects     are equal.      \relates QSurfaceFormat */
end_comment
begin_function
DECL|function|operator ==
name|bool
name|operator
name|==
parameter_list|(
specifier|const
name|QSurfaceFormat
modifier|&
name|a
parameter_list|,
specifier|const
name|QSurfaceFormat
modifier|&
name|b
parameter_list|)
block|{
return|return
operator|(
name|a
operator|.
name|d
operator|==
name|b
operator|.
name|d
operator|)
operator|||
operator|(
operator|(
name|int
operator|)
name|a
operator|.
name|d
operator|->
name|opts
operator|==
operator|(
name|int
operator|)
name|b
operator|.
name|d
operator|->
name|opts
operator|&&
name|a
operator|.
name|d
operator|->
name|stencilSize
operator|==
name|b
operator|.
name|d
operator|->
name|stencilSize
operator|&&
name|a
operator|.
name|d
operator|->
name|redBufferSize
operator|==
name|b
operator|.
name|d
operator|->
name|redBufferSize
operator|&&
name|a
operator|.
name|d
operator|->
name|greenBufferSize
operator|==
name|b
operator|.
name|d
operator|->
name|greenBufferSize
operator|&&
name|a
operator|.
name|d
operator|->
name|blueBufferSize
operator|==
name|b
operator|.
name|d
operator|->
name|blueBufferSize
operator|&&
name|a
operator|.
name|d
operator|->
name|alphaBufferSize
operator|==
name|b
operator|.
name|d
operator|->
name|alphaBufferSize
operator|&&
name|a
operator|.
name|d
operator|->
name|depthSize
operator|==
name|b
operator|.
name|d
operator|->
name|depthSize
operator|&&
name|a
operator|.
name|d
operator|->
name|numSamples
operator|==
name|b
operator|.
name|d
operator|->
name|numSamples
operator|&&
name|a
operator|.
name|d
operator|->
name|swapBehavior
operator|==
name|b
operator|.
name|d
operator|->
name|swapBehavior
operator|&&
name|a
operator|.
name|d
operator|->
name|profile
operator|==
name|b
operator|.
name|d
operator|->
name|profile
operator|&&
name|a
operator|.
name|d
operator|->
name|major
operator|==
name|b
operator|.
name|d
operator|->
name|major
operator|&&
name|a
operator|.
name|d
operator|->
name|minor
operator|==
name|b
operator|.
name|d
operator|->
name|minor
operator|)
return|;
block|}
end_function
begin_comment
comment|/*!     Returns false if all the options of the two QSurfaceFormat objects     \a a and \a b are equal; otherwise returns true.      \relates QSurfaceFormat */
end_comment
begin_function
DECL|function|operator !=
name|bool
name|operator
name|!=
parameter_list|(
specifier|const
name|QSurfaceFormat
modifier|&
name|a
parameter_list|,
specifier|const
name|QSurfaceFormat
modifier|&
name|b
parameter_list|)
block|{
return|return
operator|!
operator|(
name|a
operator|==
name|b
operator|)
return|;
block|}
end_function
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_DEBUG_STREAM
end_ifndef
begin_function
DECL|function|operator <<
name|QDebug
name|operator
name|<<
parameter_list|(
name|QDebug
name|dbg
parameter_list|,
specifier|const
name|QSurfaceFormat
modifier|&
name|f
parameter_list|)
block|{
specifier|const
name|QSurfaceFormatPrivate
modifier|*
specifier|const
name|d
init|=
name|f
operator|.
name|d
decl_stmt|;
name|dbg
operator|.
name|nospace
argument_list|()
operator|<<
literal|"QSurfaceFormat("
operator|<<
literal|"version "
operator|<<
name|d
operator|->
name|major
operator|<<
literal|'.'
operator|<<
name|d
operator|->
name|minor
operator|<<
literal|", options "
operator|<<
name|d
operator|->
name|opts
operator|<<
literal|", depthBufferSize "
operator|<<
name|d
operator|->
name|depthSize
operator|<<
literal|", redBufferSize "
operator|<<
name|d
operator|->
name|redBufferSize
operator|<<
literal|", greenBufferSize "
operator|<<
name|d
operator|->
name|greenBufferSize
operator|<<
literal|", blueBufferSize "
operator|<<
name|d
operator|->
name|blueBufferSize
operator|<<
literal|", alphaBufferSize "
operator|<<
name|d
operator|->
name|alphaBufferSize
operator|<<
literal|", stencilBufferSize "
operator|<<
name|d
operator|->
name|stencilSize
operator|<<
literal|", samples "
operator|<<
name|d
operator|->
name|numSamples
operator|<<
literal|", swapBehavior "
operator|<<
name|d
operator|->
name|swapBehavior
operator|<<
literal|", profile  "
operator|<<
name|d
operator|->
name|profile
operator|<<
literal|')'
expr_stmt|;
return|return
name|dbg
operator|.
name|space
argument_list|()
return|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
