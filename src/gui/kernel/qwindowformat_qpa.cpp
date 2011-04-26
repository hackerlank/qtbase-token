begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** No Commercial Usage ** This file contains pre-release code and may not be distributed. ** You may use this file in accordance with the terms and conditions ** contained in the Technology Preview License Agreement accompanying ** this package. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights.  These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** If you have questions regarding the use of this file, please contact ** Nokia at qt-info@nokia.com. ** ** ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qwindowformat_qpa.h"
end_include
begin_include
include|#
directive|include
file|<QtCore/QDebug>
end_include
begin_class
DECL|class|QWindowFormatPrivate
class|class
name|QWindowFormatPrivate
block|{
public|public:
DECL|function|QWindowFormatPrivate
name|QWindowFormatPrivate
parameter_list|()
member_init_list|:
name|ref
argument_list|(
literal|1
argument_list|)
member_init_list|,
name|opts
argument_list|(
name|QWindowFormat
operator|::
name|DoubleBuffer
operator||
name|QWindowFormat
operator|::
name|WindowSurface
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
name|colorFormat
argument_list|(
name|QWindowFormat
operator|::
name|RGB888
argument_list|)
member_init_list|,
name|numSamples
argument_list|(
operator|-
literal|1
argument_list|)
member_init_list|,
name|sharedContext
argument_list|(
literal|0
argument_list|)
block|{     }
DECL|function|QWindowFormatPrivate
name|QWindowFormatPrivate
parameter_list|(
specifier|const
name|QWindowFormatPrivate
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
name|colorFormat
argument_list|(
name|other
operator|->
name|colorFormat
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
name|sharedContext
argument_list|(
name|other
operator|->
name|sharedContext
argument_list|)
block|{     }
DECL|member|ref
name|QAtomicInt
name|ref
decl_stmt|;
DECL|member|opts
name|QWindowFormat
operator|::
name|FormatOptions
name|opts
decl_stmt|;
DECL|member|depthSize
name|int
name|depthSize
decl_stmt|;
DECL|member|stencilSize
name|int
name|stencilSize
decl_stmt|;
DECL|member|colorFormat
name|QWindowFormat
operator|::
name|ColorFormat
name|colorFormat
decl_stmt|;
DECL|member|swapBehavior
name|QWindowFormat
operator|::
name|SwapBehavior
name|swapBehavior
decl_stmt|;
DECL|member|numSamples
name|int
name|numSamples
decl_stmt|;
DECL|member|sharedContext
name|QPlatformGLContext
modifier|*
name|sharedContext
decl_stmt|;
block|}
class|;
end_class
begin_constructor
DECL|function|QWindowFormat
name|QWindowFormat
operator|::
name|QWindowFormat
parameter_list|()
block|{
name|d
operator|=
operator|new
name|QWindowFormatPrivate
expr_stmt|;
block|}
end_constructor
begin_constructor
DECL|function|QWindowFormat
name|QWindowFormat
operator|::
name|QWindowFormat
parameter_list|(
name|QWindowFormat
operator|::
name|FormatOptions
name|options
parameter_list|)
block|{
name|d
operator|=
operator|new
name|QWindowFormatPrivate
expr_stmt|;
name|d
operator|->
name|opts
operator|=
name|options
expr_stmt|;
block|}
end_constructor
begin_comment
comment|/*!     \internal */
end_comment
begin_function
DECL|function|detach
name|void
name|QWindowFormat
operator|::
name|detach
parameter_list|()
block|{
if|if
condition|(
name|d
operator|->
name|ref
operator|!=
literal|1
condition|)
block|{
name|QWindowFormatPrivate
modifier|*
name|newd
init|=
operator|new
name|QWindowFormatPrivate
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
DECL|function|QWindowFormat
name|QWindowFormat
operator|::
name|QWindowFormat
parameter_list|(
specifier|const
name|QWindowFormat
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
name|QWindowFormat
modifier|&
name|QWindowFormat
operator|::
name|operator
name|=
parameter_list|(
specifier|const
name|QWindowFormat
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
comment|/*!     Destroys the QWindowFormat. */
end_comment
begin_destructor
DECL|function|~QWindowFormat
name|QWindowFormat
operator|::
name|~
name|QWindowFormat
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
comment|/*!     \fn bool QWindowFormat::stereo() const      Returns true if stereo buffering is enabled; otherwise returns     false. Stereo buffering is disabled by default.      \sa setStereo() */
end_comment
begin_comment
comment|/*!     If \a enable is true enables stereo buffering; otherwise disables     stereo buffering.      Stereo buffering is disabled by default.      Stereo buffering provides extra color buffers to generate left-eye     and right-eye images.      \sa stereo() */
end_comment
begin_function
DECL|function|setStereo
name|void
name|QWindowFormat
operator|::
name|setStereo
parameter_list|(
name|bool
name|enable
parameter_list|)
block|{
if|if
condition|(
name|enable
condition|)
block|{
name|d
operator|->
name|opts
operator||=
name|QWindowFormat
operator|::
name|StereoBuffers
expr_stmt|;
block|}
else|else
block|{
name|d
operator|->
name|opts
operator|&=
operator|~
name|QWindowFormat
operator|::
name|StereoBuffers
expr_stmt|;
block|}
block|}
end_function
begin_comment
comment|/*!     Returns the number of samples per pixel when multisampling is     enabled. By default, the highest number of samples that is     available is used.      \sa setSampleBuffers(), sampleBuffers(), setSamples() */
end_comment
begin_function
DECL|function|samples
name|int
name|QWindowFormat
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
comment|/*!     Set the preferred number of samples per pixel when multisampling     is enabled to \a numSamples. By default, the highest number of     samples available is used.      \sa setSampleBuffers(), sampleBuffers(), samples() */
end_comment
begin_function
DECL|function|setSamples
name|void
name|QWindowFormat
operator|::
name|setSamples
parameter_list|(
name|int
name|numSamples
parameter_list|)
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
end_function
begin_function
DECL|function|setSharedContext
name|void
name|QWindowFormat
operator|::
name|setSharedContext
parameter_list|(
name|QPlatformGLContext
modifier|*
name|context
parameter_list|)
block|{
name|d
operator|->
name|sharedContext
operator|=
name|context
expr_stmt|;
block|}
end_function
begin_function
DECL|function|sharedGLContext
name|QPlatformGLContext
modifier|*
name|QWindowFormat
operator|::
name|sharedGLContext
parameter_list|()
specifier|const
block|{
return|return
name|d
operator|->
name|sharedContext
return|;
block|}
end_function
begin_comment
comment|/*!     \fn bool QWindowFormat::hasWindowSurface() const      Returns true if the corresponding widget has an instance of QWindowSurface.      Otherwise returns false.      WindowSurface is enabled by default.      \sa setOverlay() */
end_comment
begin_function
DECL|function|setWindowSurface
name|void
name|QWindowFormat
operator|::
name|setWindowSurface
parameter_list|(
name|bool
name|enable
parameter_list|)
block|{
if|if
condition|(
name|enable
condition|)
block|{
name|d
operator|->
name|opts
operator||=
name|QWindowFormat
operator|::
name|WindowSurface
expr_stmt|;
block|}
else|else
block|{
name|d
operator|->
name|opts
operator|&=
operator|~
name|QWindowFormat
operator|::
name|WindowSurface
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
name|QWindowFormat
operator|::
name|setOption
parameter_list|(
name|QWindowFormat
operator|::
name|FormatOptions
name|opt
parameter_list|)
block|{
name|detach
argument_list|()
expr_stmt|;
name|d
operator|->
name|opts
operator||=
name|opt
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     Returns true if format option \a opt is set; otherwise returns false.      \sa setOption() */
end_comment
begin_function
DECL|function|testOption
name|bool
name|QWindowFormat
operator|::
name|testOption
parameter_list|(
name|QWindowFormat
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
name|QWindowFormat
operator|::
name|setDepthBufferSize
parameter_list|(
name|int
name|size
parameter_list|)
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
end_function
begin_comment
comment|/*!     Returns the depth buffer size.      \sa depth(), setDepth(), setDepthBufferSize() */
end_comment
begin_function
DECL|function|depthBufferSize
name|int
name|QWindowFormat
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
begin_function
DECL|function|setColorFormat
name|void
name|QWindowFormat
operator|::
name|setColorFormat
parameter_list|(
name|ColorFormat
name|format
parameter_list|)
block|{
name|detach
argument_list|()
expr_stmt|;
name|d
operator|->
name|colorFormat
operator|=
name|format
expr_stmt|;
block|}
end_function
begin_function
DECL|function|colorFormat
name|QWindowFormat
operator|::
name|ColorFormat
name|QWindowFormat
operator|::
name|colorFormat
parameter_list|()
specifier|const
block|{
return|return
name|d
operator|->
name|colorFormat
return|;
block|}
end_function
begin_comment
comment|/*!     Set the preferred stencil buffer size to \a size.      \sa stencilBufferSize(), setStencil(), stencil() */
end_comment
begin_function
DECL|function|setStencilBufferSize
name|void
name|QWindowFormat
operator|::
name|setStencilBufferSize
parameter_list|(
name|int
name|size
parameter_list|)
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
end_function
begin_comment
comment|/*!     Returns the stencil buffer size.      \sa stencil(), setStencil(), setStencilBufferSize() */
end_comment
begin_function
DECL|function|stencilBufferSize
name|int
name|QWindowFormat
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
begin_function
DECL|function|operator ==
name|bool
name|operator
name|==
parameter_list|(
specifier|const
name|QWindowFormat
modifier|&
name|a
parameter_list|,
specifier|const
name|QWindowFormat
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
name|colorFormat
operator|==
name|b
operator|.
name|d
operator|->
name|colorFormat
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
name|sharedContext
operator|==
name|b
operator|.
name|d
operator|->
name|sharedContext
operator|)
return|;
block|}
end_function
begin_comment
comment|/*!     Returns false if all the options of the two QWindowFormat objects     \a a and \a b are equal; otherwise returns true.      \relates QWindowFormat */
end_comment
begin_function
DECL|function|operator !=
name|bool
name|operator
name|!=
parameter_list|(
specifier|const
name|QWindowFormat
modifier|&
name|a
parameter_list|,
specifier|const
name|QWindowFormat
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
name|QWindowFormat
modifier|&
name|f
parameter_list|)
block|{
specifier|const
name|QWindowFormatPrivate
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
literal|"QWindowFormat("
operator|<<
literal|"options "
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
literal|", stencilBufferSize "
operator|<<
name|d
operator|->
name|stencilSize
operator|<<
literal|", colorFormat "
operator|<<
name|d
operator|->
name|colorFormat
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
literal|", sharedContext "
operator|<<
name|d
operator|->
name|sharedContext
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
end_unit
