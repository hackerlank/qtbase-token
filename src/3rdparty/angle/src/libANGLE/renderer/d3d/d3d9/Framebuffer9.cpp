begin_unit
begin_comment
comment|//
end_comment
begin_comment
comment|// Copyright 2014 The ANGLE Project Authors. All rights reserved.
end_comment
begin_comment
comment|// Use of this source code is governed by a BSD-style license that can be
end_comment
begin_comment
comment|// found in the LICENSE file.
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|// Framebuffer9.cpp: Implements the Framebuffer9 class.
end_comment
begin_include
include|#
directive|include
file|"libANGLE/renderer/d3d/d3d9/Framebuffer9.h"
end_include
begin_include
include|#
directive|include
file|"libANGLE/renderer/d3d/d3d9/formatutils9.h"
end_include
begin_include
include|#
directive|include
file|"libANGLE/renderer/d3d/d3d9/TextureStorage9.h"
end_include
begin_include
include|#
directive|include
file|"libANGLE/renderer/d3d/d3d9/Renderer9.h"
end_include
begin_include
include|#
directive|include
file|"libANGLE/renderer/d3d/d3d9/renderer9_utils.h"
end_include
begin_include
include|#
directive|include
file|"libANGLE/renderer/d3d/d3d9/RenderTarget9.h"
end_include
begin_include
include|#
directive|include
file|"libANGLE/renderer/d3d/TextureD3D.h"
end_include
begin_include
include|#
directive|include
file|"libANGLE/formatutils.h"
end_include
begin_include
include|#
directive|include
file|"libANGLE/Framebuffer.h"
end_include
begin_include
include|#
directive|include
file|"libANGLE/FramebufferAttachment.h"
end_include
begin_include
include|#
directive|include
file|"libANGLE/Texture.h"
end_include
begin_namespace
DECL|namespace|rx
namespace|namespace
name|rx
block|{
DECL|function|Framebuffer9
name|Framebuffer9
operator|::
name|Framebuffer9
parameter_list|(
specifier|const
name|gl
operator|::
name|Framebuffer
operator|::
name|Data
modifier|&
name|data
parameter_list|,
name|Renderer9
modifier|*
name|renderer
parameter_list|)
member_init_list|:
name|FramebufferD3D
argument_list|(
name|data
argument_list|,
name|renderer
argument_list|)
member_init_list|,
name|mRenderer
argument_list|(
name|renderer
argument_list|)
block|{
name|ASSERT
argument_list|(
name|mRenderer
operator|!=
literal|nullptr
argument_list|)
expr_stmt|;
block|}
DECL|function|~Framebuffer9
name|Framebuffer9
operator|::
name|~
name|Framebuffer9
parameter_list|()
block|{ }
DECL|function|clear
name|gl
operator|::
name|Error
name|Framebuffer9
operator|::
name|clear
parameter_list|(
specifier|const
name|gl
operator|::
name|State
modifier|&
name|state
parameter_list|,
specifier|const
name|ClearParameters
modifier|&
name|clearParams
parameter_list|)
block|{
specifier|const
name|gl
operator|::
name|FramebufferAttachment
modifier|*
name|colorAttachment
init|=
name|mData
operator|.
name|mColorAttachments
index|[
literal|0
index|]
decl_stmt|;
specifier|const
name|gl
operator|::
name|FramebufferAttachment
modifier|*
name|depthStencilAttachment
init|=
name|mData
operator|.
name|getDepthOrStencilAttachment
argument_list|()
decl_stmt|;
name|gl
operator|::
name|Error
name|error
init|=
name|mRenderer
operator|->
name|applyRenderTarget
argument_list|(
name|colorAttachment
argument_list|,
name|depthStencilAttachment
argument_list|)
decl_stmt|;
if|if
condition|(
name|error
operator|.
name|isError
argument_list|()
condition|)
block|{
return|return
name|error
return|;
block|}
name|float
name|nearZ
decl_stmt|,
name|farZ
decl_stmt|;
name|state
operator|.
name|getDepthRange
argument_list|(
operator|&
name|nearZ
argument_list|,
operator|&
name|farZ
argument_list|)
expr_stmt|;
name|mRenderer
operator|->
name|setViewport
argument_list|(
name|state
operator|.
name|getViewport
argument_list|()
argument_list|,
name|nearZ
argument_list|,
name|farZ
argument_list|,
name|GL_TRIANGLES
argument_list|,
name|state
operator|.
name|getRasterizerState
argument_list|()
operator|.
name|frontFace
argument_list|,
literal|true
argument_list|)
expr_stmt|;
name|mRenderer
operator|->
name|setScissorRectangle
argument_list|(
name|state
operator|.
name|getScissor
argument_list|()
argument_list|,
name|state
operator|.
name|isScissorTestEnabled
argument_list|()
argument_list|)
expr_stmt|;
return|return
name|mRenderer
operator|->
name|clear
argument_list|(
name|clearParams
argument_list|,
name|colorAttachment
argument_list|,
name|depthStencilAttachment
argument_list|)
return|;
block|}
DECL|function|readPixels
name|gl
operator|::
name|Error
name|Framebuffer9
operator|::
name|readPixels
parameter_list|(
specifier|const
name|gl
operator|::
name|Rectangle
modifier|&
name|area
parameter_list|,
name|GLenum
name|format
parameter_list|,
name|GLenum
name|type
parameter_list|,
name|size_t
name|outputPitch
parameter_list|,
specifier|const
name|gl
operator|::
name|PixelPackState
modifier|&
name|pack
parameter_list|,
name|uint8_t
modifier|*
name|pixels
parameter_list|)
specifier|const
block|{
name|ASSERT
argument_list|(
name|pack
operator|.
name|pixelBuffer
operator|.
name|get
argument_list|()
operator|==
name|NULL
argument_list|)
expr_stmt|;
specifier|const
name|gl
operator|::
name|FramebufferAttachment
modifier|*
name|colorbuffer
init|=
name|mData
operator|.
name|mColorAttachments
index|[
literal|0
index|]
decl_stmt|;
name|ASSERT
argument_list|(
name|colorbuffer
argument_list|)
expr_stmt|;
name|RenderTarget9
modifier|*
name|renderTarget
init|=
name|NULL
decl_stmt|;
name|gl
operator|::
name|Error
name|error
init|=
name|d3d9
operator|::
name|GetAttachmentRenderTarget
argument_list|(
name|colorbuffer
argument_list|,
operator|&
name|renderTarget
argument_list|)
decl_stmt|;
if|if
condition|(
name|error
operator|.
name|isError
argument_list|()
condition|)
block|{
return|return
name|error
return|;
block|}
name|ASSERT
argument_list|(
name|renderTarget
argument_list|)
expr_stmt|;
name|IDirect3DSurface9
modifier|*
name|surface
init|=
name|renderTarget
operator|->
name|getSurface
argument_list|()
decl_stmt|;
name|ASSERT
argument_list|(
name|surface
argument_list|)
expr_stmt|;
name|D3DSURFACE_DESC
name|desc
decl_stmt|;
name|surface
operator|->
name|GetDesc
argument_list|(
operator|&
name|desc
argument_list|)
expr_stmt|;
if|if
condition|(
name|desc
operator|.
name|MultiSampleType
operator|!=
name|D3DMULTISAMPLE_NONE
condition|)
block|{
name|UNIMPLEMENTED
argument_list|()
expr_stmt|;
comment|// FIXME: Requires resolve using StretchRect into non-multisampled render target
name|SafeRelease
argument_list|(
name|surface
argument_list|)
expr_stmt|;
return|return
name|gl
operator|::
name|Error
argument_list|(
name|GL_OUT_OF_MEMORY
argument_list|,
literal|"ReadPixels is unimplemented for multisampled framebuffer attachments."
argument_list|)
return|;
block|}
name|IDirect3DDevice9
modifier|*
name|device
init|=
name|mRenderer
operator|->
name|getDevice
argument_list|()
decl_stmt|;
name|ASSERT
argument_list|(
name|device
argument_list|)
expr_stmt|;
name|HRESULT
name|result
decl_stmt|;
name|IDirect3DSurface9
modifier|*
name|systemSurface
init|=
name|NULL
decl_stmt|;
name|bool
name|directToPixels
init|=
operator|!
name|pack
operator|.
name|reverseRowOrder
operator|&&
name|pack
operator|.
name|alignment
operator|<=
literal|4
operator|&&
name|mRenderer
operator|->
name|getShareHandleSupport
argument_list|()
operator|&&
name|area
operator|.
name|x
operator|==
literal|0
operator|&&
name|area
operator|.
name|y
operator|==
literal|0
operator|&&
cast|static_cast
argument_list|<
name|UINT
argument_list|>
argument_list|(
name|area
operator|.
name|width
argument_list|)
operator|==
name|desc
operator|.
name|Width
operator|&&
cast|static_cast
argument_list|<
name|UINT
argument_list|>
argument_list|(
name|area
operator|.
name|height
argument_list|)
operator|==
name|desc
operator|.
name|Height
operator|&&
name|desc
operator|.
name|Format
operator|==
name|D3DFMT_A8R8G8B8
operator|&&
name|format
operator|==
name|GL_BGRA_EXT
operator|&&
name|type
operator|==
name|GL_UNSIGNED_BYTE
decl_stmt|;
if|if
condition|(
name|directToPixels
condition|)
block|{
comment|// Use the pixels ptr as a shared handle to write directly into client's memory
name|result
operator|=
name|device
operator|->
name|CreateOffscreenPlainSurface
argument_list|(
name|desc
operator|.
name|Width
argument_list|,
name|desc
operator|.
name|Height
argument_list|,
name|desc
operator|.
name|Format
argument_list|,
name|D3DPOOL_SYSTEMMEM
argument_list|,
operator|&
name|systemSurface
argument_list|,
cast|reinterpret_cast
argument_list|<
name|void
operator|*
operator|*
argument_list|>
argument_list|(
operator|&
name|pixels
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|FAILED
argument_list|(
name|result
argument_list|)
condition|)
block|{
comment|// Try again without the shared handle
name|directToPixels
operator|=
literal|false
expr_stmt|;
block|}
block|}
if|if
condition|(
operator|!
name|directToPixels
condition|)
block|{
name|result
operator|=
name|device
operator|->
name|CreateOffscreenPlainSurface
argument_list|(
name|desc
operator|.
name|Width
argument_list|,
name|desc
operator|.
name|Height
argument_list|,
name|desc
operator|.
name|Format
argument_list|,
name|D3DPOOL_SYSTEMMEM
argument_list|,
operator|&
name|systemSurface
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
if|if
condition|(
name|FAILED
argument_list|(
name|result
argument_list|)
condition|)
block|{
name|ASSERT
argument_list|(
name|result
operator|==
name|D3DERR_OUTOFVIDEOMEMORY
operator|||
name|result
operator|==
name|E_OUTOFMEMORY
argument_list|)
expr_stmt|;
name|SafeRelease
argument_list|(
name|surface
argument_list|)
expr_stmt|;
return|return
name|gl
operator|::
name|Error
argument_list|(
name|GL_OUT_OF_MEMORY
argument_list|,
literal|"Failed to allocate internal texture for ReadPixels."
argument_list|)
return|;
block|}
block|}
name|result
operator|=
name|device
operator|->
name|GetRenderTargetData
argument_list|(
name|surface
argument_list|,
name|systemSurface
argument_list|)
expr_stmt|;
name|SafeRelease
argument_list|(
name|surface
argument_list|)
expr_stmt|;
if|if
condition|(
name|FAILED
argument_list|(
name|result
argument_list|)
condition|)
block|{
name|SafeRelease
argument_list|(
name|systemSurface
argument_list|)
expr_stmt|;
comment|// It turns out that D3D will sometimes produce more error
comment|// codes than those documented.
if|if
condition|(
name|d3d9
operator|::
name|isDeviceLostError
argument_list|(
name|result
argument_list|)
condition|)
block|{
name|mRenderer
operator|->
name|notifyDeviceLost
argument_list|()
expr_stmt|;
block|}
else|else
block|{
name|UNREACHABLE
argument_list|()
expr_stmt|;
block|}
return|return
name|gl
operator|::
name|Error
argument_list|(
name|GL_OUT_OF_MEMORY
argument_list|,
literal|"Failed to read internal render target data."
argument_list|)
return|;
block|}
if|if
condition|(
name|directToPixels
condition|)
block|{
name|SafeRelease
argument_list|(
name|systemSurface
argument_list|)
expr_stmt|;
return|return
name|gl
operator|::
name|Error
argument_list|(
name|GL_NO_ERROR
argument_list|)
return|;
block|}
name|RECT
name|rect
decl_stmt|;
name|rect
operator|.
name|left
operator|=
name|gl
operator|::
name|clamp
argument_list|(
name|area
operator|.
name|x
argument_list|,
literal|0L
argument_list|,
cast|static_cast
argument_list|<
name|LONG
argument_list|>
argument_list|(
name|desc
operator|.
name|Width
argument_list|)
argument_list|)
expr_stmt|;
name|rect
operator|.
name|top
operator|=
name|gl
operator|::
name|clamp
argument_list|(
name|area
operator|.
name|y
argument_list|,
literal|0L
argument_list|,
cast|static_cast
argument_list|<
name|LONG
argument_list|>
argument_list|(
name|desc
operator|.
name|Height
argument_list|)
argument_list|)
expr_stmt|;
name|rect
operator|.
name|right
operator|=
name|gl
operator|::
name|clamp
argument_list|(
name|area
operator|.
name|x
operator|+
name|area
operator|.
name|width
argument_list|,
literal|0L
argument_list|,
cast|static_cast
argument_list|<
name|LONG
argument_list|>
argument_list|(
name|desc
operator|.
name|Width
argument_list|)
argument_list|)
expr_stmt|;
name|rect
operator|.
name|bottom
operator|=
name|gl
operator|::
name|clamp
argument_list|(
name|area
operator|.
name|y
operator|+
name|area
operator|.
name|height
argument_list|,
literal|0L
argument_list|,
cast|static_cast
argument_list|<
name|LONG
argument_list|>
argument_list|(
name|desc
operator|.
name|Height
argument_list|)
argument_list|)
expr_stmt|;
name|D3DLOCKED_RECT
name|lock
decl_stmt|;
name|result
operator|=
name|systemSurface
operator|->
name|LockRect
argument_list|(
operator|&
name|lock
argument_list|,
operator|&
name|rect
argument_list|,
name|D3DLOCK_READONLY
argument_list|)
expr_stmt|;
if|if
condition|(
name|FAILED
argument_list|(
name|result
argument_list|)
condition|)
block|{
name|UNREACHABLE
argument_list|()
expr_stmt|;
name|SafeRelease
argument_list|(
name|systemSurface
argument_list|)
expr_stmt|;
return|return
name|gl
operator|::
name|Error
argument_list|(
name|GL_OUT_OF_MEMORY
argument_list|,
literal|"Failed to lock internal render target."
argument_list|)
return|;
block|}
name|uint8_t
modifier|*
name|source
decl_stmt|;
name|int
name|inputPitch
decl_stmt|;
if|if
condition|(
name|pack
operator|.
name|reverseRowOrder
condition|)
block|{
name|source
operator|=
cast|reinterpret_cast
argument_list|<
name|uint8_t
operator|*
argument_list|>
argument_list|(
name|lock
operator|.
name|pBits
argument_list|)
operator|+
name|lock
operator|.
name|Pitch
operator|*
operator|(
name|rect
operator|.
name|bottom
operator|-
name|rect
operator|.
name|top
operator|-
literal|1
operator|)
expr_stmt|;
name|inputPitch
operator|=
operator|-
name|lock
operator|.
name|Pitch
expr_stmt|;
block|}
else|else
block|{
name|source
operator|=
cast|reinterpret_cast
argument_list|<
name|uint8_t
operator|*
argument_list|>
argument_list|(
name|lock
operator|.
name|pBits
argument_list|)
expr_stmt|;
name|inputPitch
operator|=
name|lock
operator|.
name|Pitch
expr_stmt|;
block|}
specifier|const
name|d3d9
operator|::
name|D3DFormat
modifier|&
name|d3dFormatInfo
init|=
name|d3d9
operator|::
name|GetD3DFormatInfo
argument_list|(
name|desc
operator|.
name|Format
argument_list|)
decl_stmt|;
specifier|const
name|gl
operator|::
name|InternalFormat
modifier|&
name|sourceFormatInfo
init|=
name|gl
operator|::
name|GetInternalFormatInfo
argument_list|(
name|d3dFormatInfo
operator|.
name|internalFormat
argument_list|)
decl_stmt|;
if|if
condition|(
name|sourceFormatInfo
operator|.
name|format
operator|==
name|format
operator|&&
name|sourceFormatInfo
operator|.
name|type
operator|==
name|type
condition|)
block|{
comment|// Direct copy possible
for|for
control|(
name|int
name|y
init|=
literal|0
init|;
name|y
operator|<
name|rect
operator|.
name|bottom
operator|-
name|rect
operator|.
name|top
condition|;
name|y
operator|++
control|)
block|{
name|memcpy
argument_list|(
name|pixels
operator|+
name|y
operator|*
name|outputPitch
argument_list|,
name|source
operator|+
name|y
operator|*
name|inputPitch
argument_list|,
operator|(
name|rect
operator|.
name|right
operator|-
name|rect
operator|.
name|left
operator|)
operator|*
name|sourceFormatInfo
operator|.
name|pixelBytes
argument_list|)
expr_stmt|;
block|}
block|}
else|else
block|{
specifier|const
name|d3d9
operator|::
name|D3DFormat
modifier|&
name|sourceD3DFormatInfo
init|=
name|d3d9
operator|::
name|GetD3DFormatInfo
argument_list|(
name|desc
operator|.
name|Format
argument_list|)
decl_stmt|;
name|ColorCopyFunction
name|fastCopyFunc
init|=
name|sourceD3DFormatInfo
operator|.
name|getFastCopyFunction
argument_list|(
name|format
argument_list|,
name|type
argument_list|)
decl_stmt|;
name|GLenum
name|sizedDestInternalFormat
init|=
name|gl
operator|::
name|GetSizedInternalFormat
argument_list|(
name|format
argument_list|,
name|type
argument_list|)
decl_stmt|;
specifier|const
name|gl
operator|::
name|InternalFormat
modifier|&
name|destFormatInfo
init|=
name|gl
operator|::
name|GetInternalFormatInfo
argument_list|(
name|sizedDestInternalFormat
argument_list|)
decl_stmt|;
if|if
condition|(
name|fastCopyFunc
condition|)
block|{
comment|// Fast copy is possible through some special function
for|for
control|(
name|int
name|y
init|=
literal|0
init|;
name|y
operator|<
name|rect
operator|.
name|bottom
operator|-
name|rect
operator|.
name|top
condition|;
name|y
operator|++
control|)
block|{
for|for
control|(
name|int
name|x
init|=
literal|0
init|;
name|x
operator|<
name|rect
operator|.
name|right
operator|-
name|rect
operator|.
name|left
condition|;
name|x
operator|++
control|)
block|{
name|uint8_t
modifier|*
name|dest
init|=
name|pixels
operator|+
name|y
operator|*
name|outputPitch
operator|+
name|x
operator|*
name|destFormatInfo
operator|.
name|pixelBytes
decl_stmt|;
specifier|const
name|uint8_t
modifier|*
name|src
init|=
name|source
operator|+
name|y
operator|*
name|inputPitch
operator|+
name|x
operator|*
name|sourceFormatInfo
operator|.
name|pixelBytes
decl_stmt|;
name|fastCopyFunc
argument_list|(
name|src
argument_list|,
name|dest
argument_list|)
expr_stmt|;
block|}
block|}
block|}
else|else
block|{
name|ColorReadFunction
name|colorReadFunction
init|=
name|sourceD3DFormatInfo
operator|.
name|colorReadFunction
decl_stmt|;
name|ColorWriteFunction
name|colorWriteFunction
init|=
name|GetColorWriteFunction
argument_list|(
name|format
argument_list|,
name|type
argument_list|)
decl_stmt|;
name|uint8_t
name|temp
index|[
sizeof|sizeof
argument_list|(
name|gl
operator|::
name|ColorF
argument_list|)
index|]
decl_stmt|;
for|for
control|(
name|int
name|y
init|=
literal|0
init|;
name|y
operator|<
name|rect
operator|.
name|bottom
operator|-
name|rect
operator|.
name|top
condition|;
name|y
operator|++
control|)
block|{
for|for
control|(
name|int
name|x
init|=
literal|0
init|;
name|x
operator|<
name|rect
operator|.
name|right
operator|-
name|rect
operator|.
name|left
condition|;
name|x
operator|++
control|)
block|{
name|uint8_t
modifier|*
name|dest
init|=
name|pixels
operator|+
name|y
operator|*
name|outputPitch
operator|+
name|x
operator|*
name|destFormatInfo
operator|.
name|pixelBytes
decl_stmt|;
specifier|const
name|uint8_t
modifier|*
name|src
init|=
name|source
operator|+
name|y
operator|*
name|inputPitch
operator|+
name|x
operator|*
name|sourceFormatInfo
operator|.
name|pixelBytes
decl_stmt|;
comment|// readFunc and writeFunc will be using the same type of color, CopyTexImage
comment|// will not allow the copy otherwise.
name|colorReadFunction
argument_list|(
name|src
argument_list|,
name|temp
argument_list|)
expr_stmt|;
name|colorWriteFunction
argument_list|(
name|temp
argument_list|,
name|dest
argument_list|)
expr_stmt|;
block|}
block|}
block|}
block|}
name|systemSurface
operator|->
name|UnlockRect
argument_list|()
expr_stmt|;
name|SafeRelease
argument_list|(
name|systemSurface
argument_list|)
expr_stmt|;
return|return
name|gl
operator|::
name|Error
argument_list|(
name|GL_NO_ERROR
argument_list|)
return|;
block|}
DECL|function|blit
name|gl
operator|::
name|Error
name|Framebuffer9
operator|::
name|blit
parameter_list|(
specifier|const
name|gl
operator|::
name|Rectangle
modifier|&
name|sourceArea
parameter_list|,
specifier|const
name|gl
operator|::
name|Rectangle
modifier|&
name|destArea
parameter_list|,
specifier|const
name|gl
operator|::
name|Rectangle
modifier|*
name|scissor
parameter_list|,
name|bool
name|blitRenderTarget
parameter_list|,
name|bool
name|blitDepth
parameter_list|,
name|bool
name|blitStencil
parameter_list|,
name|GLenum
name|filter
parameter_list|,
specifier|const
name|gl
operator|::
name|Framebuffer
modifier|*
name|sourceFramebuffer
parameter_list|)
block|{
name|ASSERT
argument_list|(
name|filter
operator|==
name|GL_NEAREST
argument_list|)
expr_stmt|;
name|IDirect3DDevice9
modifier|*
name|device
init|=
name|mRenderer
operator|->
name|getDevice
argument_list|()
decl_stmt|;
name|ASSERT
argument_list|(
name|device
argument_list|)
expr_stmt|;
name|mRenderer
operator|->
name|endScene
argument_list|()
expr_stmt|;
if|if
condition|(
name|blitRenderTarget
condition|)
block|{
specifier|const
name|gl
operator|::
name|FramebufferAttachment
modifier|*
name|readBuffer
init|=
name|sourceFramebuffer
operator|->
name|getColorbuffer
argument_list|(
literal|0
argument_list|)
decl_stmt|;
name|ASSERT
argument_list|(
name|readBuffer
argument_list|)
expr_stmt|;
name|RenderTarget9
modifier|*
name|readRenderTarget
init|=
name|NULL
decl_stmt|;
name|gl
operator|::
name|Error
name|error
init|=
name|d3d9
operator|::
name|GetAttachmentRenderTarget
argument_list|(
name|readBuffer
argument_list|,
operator|&
name|readRenderTarget
argument_list|)
decl_stmt|;
if|if
condition|(
name|error
operator|.
name|isError
argument_list|()
condition|)
block|{
return|return
name|error
return|;
block|}
name|ASSERT
argument_list|(
name|readRenderTarget
argument_list|)
expr_stmt|;
specifier|const
name|gl
operator|::
name|FramebufferAttachment
modifier|*
name|drawBuffer
init|=
name|mData
operator|.
name|mColorAttachments
index|[
literal|0
index|]
decl_stmt|;
name|ASSERT
argument_list|(
name|drawBuffer
argument_list|)
expr_stmt|;
name|RenderTarget9
modifier|*
name|drawRenderTarget
init|=
name|NULL
decl_stmt|;
name|error
operator|=
name|d3d9
operator|::
name|GetAttachmentRenderTarget
argument_list|(
name|drawBuffer
argument_list|,
operator|&
name|drawRenderTarget
argument_list|)
expr_stmt|;
if|if
condition|(
name|error
operator|.
name|isError
argument_list|()
condition|)
block|{
return|return
name|error
return|;
block|}
name|ASSERT
argument_list|(
name|drawRenderTarget
argument_list|)
expr_stmt|;
comment|// The getSurface calls do an AddRef so save them until after no errors are possible
name|IDirect3DSurface9
modifier|*
name|readSurface
init|=
name|readRenderTarget
operator|->
name|getSurface
argument_list|()
decl_stmt|;
name|ASSERT
argument_list|(
name|readSurface
argument_list|)
expr_stmt|;
name|IDirect3DSurface9
modifier|*
name|drawSurface
init|=
name|drawRenderTarget
operator|->
name|getSurface
argument_list|()
decl_stmt|;
name|ASSERT
argument_list|(
name|drawSurface
argument_list|)
expr_stmt|;
name|gl
operator|::
name|Extents
name|srcSize
argument_list|(
name|readRenderTarget
operator|->
name|getWidth
argument_list|()
argument_list|,
name|readRenderTarget
operator|->
name|getHeight
argument_list|()
argument_list|,
literal|1
argument_list|)
decl_stmt|;
name|gl
operator|::
name|Extents
name|dstSize
argument_list|(
name|drawRenderTarget
operator|->
name|getWidth
argument_list|()
argument_list|,
name|drawRenderTarget
operator|->
name|getHeight
argument_list|()
argument_list|,
literal|1
argument_list|)
decl_stmt|;
name|RECT
name|srcRect
decl_stmt|;
name|srcRect
operator|.
name|left
operator|=
name|sourceArea
operator|.
name|x
expr_stmt|;
name|srcRect
operator|.
name|right
operator|=
name|sourceArea
operator|.
name|x
operator|+
name|sourceArea
operator|.
name|width
expr_stmt|;
name|srcRect
operator|.
name|top
operator|=
name|sourceArea
operator|.
name|y
expr_stmt|;
name|srcRect
operator|.
name|bottom
operator|=
name|sourceArea
operator|.
name|y
operator|+
name|sourceArea
operator|.
name|height
expr_stmt|;
name|RECT
name|dstRect
decl_stmt|;
name|dstRect
operator|.
name|left
operator|=
name|destArea
operator|.
name|x
expr_stmt|;
name|dstRect
operator|.
name|right
operator|=
name|destArea
operator|.
name|x
operator|+
name|destArea
operator|.
name|width
expr_stmt|;
name|dstRect
operator|.
name|top
operator|=
name|destArea
operator|.
name|y
expr_stmt|;
name|dstRect
operator|.
name|bottom
operator|=
name|destArea
operator|.
name|y
operator|+
name|destArea
operator|.
name|height
expr_stmt|;
comment|// Clip the rectangles to the scissor rectangle
if|if
condition|(
name|scissor
condition|)
block|{
if|if
condition|(
name|dstRect
operator|.
name|left
operator|<
name|scissor
operator|->
name|x
condition|)
block|{
name|srcRect
operator|.
name|left
operator|+=
operator|(
name|scissor
operator|->
name|x
operator|-
name|dstRect
operator|.
name|left
operator|)
expr_stmt|;
name|dstRect
operator|.
name|left
operator|=
name|scissor
operator|->
name|x
expr_stmt|;
block|}
if|if
condition|(
name|dstRect
operator|.
name|top
operator|<
name|scissor
operator|->
name|y
condition|)
block|{
name|srcRect
operator|.
name|top
operator|+=
operator|(
name|scissor
operator|->
name|y
operator|-
name|dstRect
operator|.
name|top
operator|)
expr_stmt|;
name|dstRect
operator|.
name|top
operator|=
name|scissor
operator|->
name|y
expr_stmt|;
block|}
if|if
condition|(
name|dstRect
operator|.
name|right
operator|>
name|scissor
operator|->
name|x
operator|+
name|scissor
operator|->
name|width
condition|)
block|{
name|srcRect
operator|.
name|right
operator|-=
operator|(
name|dstRect
operator|.
name|right
operator|-
operator|(
name|scissor
operator|->
name|x
operator|+
name|scissor
operator|->
name|width
operator|)
operator|)
expr_stmt|;
name|dstRect
operator|.
name|right
operator|=
name|scissor
operator|->
name|x
operator|+
name|scissor
operator|->
name|width
expr_stmt|;
block|}
if|if
condition|(
name|dstRect
operator|.
name|bottom
operator|>
name|scissor
operator|->
name|y
operator|+
name|scissor
operator|->
name|height
condition|)
block|{
name|srcRect
operator|.
name|bottom
operator|-=
operator|(
name|dstRect
operator|.
name|bottom
operator|-
operator|(
name|scissor
operator|->
name|y
operator|+
name|scissor
operator|->
name|height
operator|)
operator|)
expr_stmt|;
name|dstRect
operator|.
name|bottom
operator|=
name|scissor
operator|->
name|y
operator|+
name|scissor
operator|->
name|height
expr_stmt|;
block|}
block|}
comment|// Clip the rectangles to the destination size
if|if
condition|(
name|dstRect
operator|.
name|left
operator|<
literal|0
condition|)
block|{
name|srcRect
operator|.
name|left
operator|+=
operator|-
name|dstRect
operator|.
name|left
expr_stmt|;
name|dstRect
operator|.
name|left
operator|=
literal|0
expr_stmt|;
block|}
if|if
condition|(
name|dstRect
operator|.
name|right
operator|>
name|dstSize
operator|.
name|width
condition|)
block|{
name|srcRect
operator|.
name|right
operator|-=
operator|(
name|dstRect
operator|.
name|right
operator|-
name|dstSize
operator|.
name|width
operator|)
expr_stmt|;
name|dstRect
operator|.
name|right
operator|=
name|dstSize
operator|.
name|width
expr_stmt|;
block|}
if|if
condition|(
name|dstRect
operator|.
name|top
operator|<
literal|0
condition|)
block|{
name|srcRect
operator|.
name|top
operator|+=
operator|-
name|dstRect
operator|.
name|top
expr_stmt|;
name|dstRect
operator|.
name|top
operator|=
literal|0
expr_stmt|;
block|}
if|if
condition|(
name|dstRect
operator|.
name|bottom
operator|>
name|dstSize
operator|.
name|height
condition|)
block|{
name|srcRect
operator|.
name|bottom
operator|-=
operator|(
name|dstRect
operator|.
name|bottom
operator|-
name|dstSize
operator|.
name|height
operator|)
expr_stmt|;
name|dstRect
operator|.
name|bottom
operator|=
name|dstSize
operator|.
name|height
expr_stmt|;
block|}
comment|// Clip the rectangles to the source size
if|if
condition|(
name|srcRect
operator|.
name|left
operator|<
literal|0
condition|)
block|{
name|dstRect
operator|.
name|left
operator|+=
operator|-
name|srcRect
operator|.
name|left
expr_stmt|;
name|srcRect
operator|.
name|left
operator|=
literal|0
expr_stmt|;
block|}
if|if
condition|(
name|srcRect
operator|.
name|right
operator|>
name|srcSize
operator|.
name|width
condition|)
block|{
name|dstRect
operator|.
name|right
operator|-=
operator|(
name|srcRect
operator|.
name|right
operator|-
name|srcSize
operator|.
name|width
operator|)
expr_stmt|;
name|srcRect
operator|.
name|right
operator|=
name|srcSize
operator|.
name|width
expr_stmt|;
block|}
if|if
condition|(
name|srcRect
operator|.
name|top
operator|<
literal|0
condition|)
block|{
name|dstRect
operator|.
name|top
operator|+=
operator|-
name|srcRect
operator|.
name|top
expr_stmt|;
name|srcRect
operator|.
name|top
operator|=
literal|0
expr_stmt|;
block|}
if|if
condition|(
name|srcRect
operator|.
name|bottom
operator|>
name|srcSize
operator|.
name|height
condition|)
block|{
name|dstRect
operator|.
name|bottom
operator|-=
operator|(
name|srcRect
operator|.
name|bottom
operator|-
name|srcSize
operator|.
name|height
operator|)
expr_stmt|;
name|srcRect
operator|.
name|bottom
operator|=
name|srcSize
operator|.
name|height
expr_stmt|;
block|}
name|HRESULT
name|result
init|=
name|device
operator|->
name|StretchRect
argument_list|(
name|readSurface
argument_list|,
operator|&
name|srcRect
argument_list|,
name|drawSurface
argument_list|,
operator|&
name|dstRect
argument_list|,
name|D3DTEXF_NONE
argument_list|)
decl_stmt|;
name|SafeRelease
argument_list|(
name|readSurface
argument_list|)
expr_stmt|;
name|SafeRelease
argument_list|(
name|drawSurface
argument_list|)
expr_stmt|;
if|if
condition|(
name|FAILED
argument_list|(
name|result
argument_list|)
condition|)
block|{
return|return
name|gl
operator|::
name|Error
argument_list|(
name|GL_OUT_OF_MEMORY
argument_list|,
literal|"Internal blit failed, StretchRect returned 0x%X."
argument_list|,
name|result
argument_list|)
return|;
block|}
block|}
if|if
condition|(
name|blitDepth
operator|||
name|blitStencil
condition|)
block|{
specifier|const
name|gl
operator|::
name|FramebufferAttachment
modifier|*
name|readBuffer
init|=
name|sourceFramebuffer
operator|->
name|getDepthOrStencilbuffer
argument_list|()
decl_stmt|;
name|ASSERT
argument_list|(
name|readBuffer
argument_list|)
expr_stmt|;
name|RenderTarget9
modifier|*
name|readDepthStencil
init|=
name|NULL
decl_stmt|;
name|gl
operator|::
name|Error
name|error
init|=
name|d3d9
operator|::
name|GetAttachmentRenderTarget
argument_list|(
name|readBuffer
argument_list|,
operator|&
name|readDepthStencil
argument_list|)
decl_stmt|;
if|if
condition|(
name|error
operator|.
name|isError
argument_list|()
condition|)
block|{
return|return
name|error
return|;
block|}
name|ASSERT
argument_list|(
name|readDepthStencil
argument_list|)
expr_stmt|;
specifier|const
name|gl
operator|::
name|FramebufferAttachment
modifier|*
name|drawBuffer
init|=
name|mData
operator|.
name|getDepthOrStencilAttachment
argument_list|()
decl_stmt|;
name|ASSERT
argument_list|(
name|drawBuffer
argument_list|)
expr_stmt|;
name|RenderTarget9
modifier|*
name|drawDepthStencil
init|=
name|NULL
decl_stmt|;
name|error
operator|=
name|d3d9
operator|::
name|GetAttachmentRenderTarget
argument_list|(
name|drawBuffer
argument_list|,
operator|&
name|drawDepthStencil
argument_list|)
expr_stmt|;
if|if
condition|(
name|error
operator|.
name|isError
argument_list|()
condition|)
block|{
return|return
name|error
return|;
block|}
name|ASSERT
argument_list|(
name|drawDepthStencil
argument_list|)
expr_stmt|;
comment|// The getSurface calls do an AddRef so save them until after no errors are possible
name|IDirect3DSurface9
modifier|*
name|readSurface
init|=
name|readDepthStencil
operator|->
name|getSurface
argument_list|()
decl_stmt|;
name|ASSERT
argument_list|(
name|readDepthStencil
argument_list|)
expr_stmt|;
name|IDirect3DSurface9
modifier|*
name|drawSurface
init|=
name|drawDepthStencil
operator|->
name|getSurface
argument_list|()
decl_stmt|;
name|ASSERT
argument_list|(
name|drawDepthStencil
argument_list|)
expr_stmt|;
name|HRESULT
name|result
init|=
name|device
operator|->
name|StretchRect
argument_list|(
name|readSurface
argument_list|,
name|NULL
argument_list|,
name|drawSurface
argument_list|,
name|NULL
argument_list|,
name|D3DTEXF_NONE
argument_list|)
decl_stmt|;
name|SafeRelease
argument_list|(
name|readSurface
argument_list|)
expr_stmt|;
name|SafeRelease
argument_list|(
name|drawSurface
argument_list|)
expr_stmt|;
if|if
condition|(
name|FAILED
argument_list|(
name|result
argument_list|)
condition|)
block|{
return|return
name|gl
operator|::
name|Error
argument_list|(
name|GL_OUT_OF_MEMORY
argument_list|,
literal|"Internal blit failed, StretchRect returned 0x%X."
argument_list|,
name|result
argument_list|)
return|;
block|}
block|}
return|return
name|gl
operator|::
name|Error
argument_list|(
name|GL_NO_ERROR
argument_list|)
return|;
block|}
DECL|function|getRenderTargetImplementationFormat
name|GLenum
name|Framebuffer9
operator|::
name|getRenderTargetImplementationFormat
parameter_list|(
name|RenderTargetD3D
modifier|*
name|renderTarget
parameter_list|)
specifier|const
block|{
name|RenderTarget9
modifier|*
name|renderTarget9
init|=
name|RenderTarget9
operator|::
name|makeRenderTarget9
argument_list|(
name|renderTarget
argument_list|)
decl_stmt|;
specifier|const
name|d3d9
operator|::
name|D3DFormat
modifier|&
name|d3dFormatInfo
init|=
name|d3d9
operator|::
name|GetD3DFormatInfo
argument_list|(
name|renderTarget9
operator|->
name|getD3DFormat
argument_list|()
argument_list|)
decl_stmt|;
return|return
name|d3dFormatInfo
operator|.
name|internalFormat
return|;
block|}
block|}
end_namespace
end_unit
