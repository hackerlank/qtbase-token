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
comment|// Buffer11.h: Defines the rx::Buffer11 class which implements rx::BufferImpl via rx::BufferD3D.
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|LIBGLESV2_RENDERER_BUFFER11_H_
end_ifndef
begin_define
DECL|macro|LIBGLESV2_RENDERER_BUFFER11_H_
define|#
directive|define
name|LIBGLESV2_RENDERER_BUFFER11_H_
end_define
begin_include
include|#
directive|include
file|"libGLESv2/renderer/d3d/BufferD3D.h"
end_include
begin_include
include|#
directive|include
file|"libGLESv2/renderer/d3d/MemoryBuffer.h"
end_include
begin_include
include|#
directive|include
file|"libGLESv2/angletypes.h"
end_include
begin_decl_stmt
name|namespace
name|rx
block|{
name|class
name|Renderer11
decl_stmt|;
enum|enum
name|BufferUsage
block|{
name|BUFFER_USAGE_STAGING
block|,
name|BUFFER_USAGE_VERTEX_OR_TRANSFORM_FEEDBACK
block|,
name|BUFFER_USAGE_INDEX
block|,
name|BUFFER_USAGE_PIXEL_UNPACK
block|,
name|BUFFER_USAGE_PIXEL_PACK
block|,
name|BUFFER_USAGE_UNIFORM
block|, }
enum|;
struct|struct
name|PackPixelsParams
block|{
name|PackPixelsParams
argument_list|()
expr_stmt|;
name|PackPixelsParams
argument_list|(
argument|const gl::Rectangle&area
argument_list|,
argument|GLenum format
argument_list|,
argument|GLenum type
argument_list|,
argument|GLuint outputPitch
argument_list|,
argument|const gl::PixelPackState&pack
argument_list|,
argument|ptrdiff_t offset
argument_list|)
empty_stmt|;
name|gl
operator|::
name|Rectangle
name|area
expr_stmt|;
name|GLenum
name|format
decl_stmt|;
name|GLenum
name|type
decl_stmt|;
name|GLuint
name|outputPitch
decl_stmt|;
name|gl
operator|::
name|Buffer
operator|*
name|packBuffer
expr_stmt|;
name|gl
operator|::
name|PixelPackState
name|pack
expr_stmt|;
name|ptrdiff_t
name|offset
decl_stmt|;
block|}
struct|;
typedef|typedef
name|size_t
name|DataRevision
typedef|;
name|class
name|Buffer11
range|:
name|public
name|BufferD3D
block|{
name|public
operator|:
name|Buffer11
argument_list|(
name|rx
operator|::
name|Renderer11
operator|*
name|renderer
argument_list|)
block|;
name|virtual
operator|~
name|Buffer11
argument_list|()
block|;
specifier|static
name|Buffer11
operator|*
name|makeBuffer11
argument_list|(
name|BufferImpl
operator|*
name|buffer
argument_list|)
block|;
name|ID3D11Buffer
operator|*
name|getBuffer
argument_list|(
argument|BufferUsage usage
argument_list|)
block|;
name|ID3D11ShaderResourceView
operator|*
name|getSRV
argument_list|(
argument|DXGI_FORMAT srvFormat
argument_list|)
block|;
name|bool
name|isMapped
argument_list|()
specifier|const
block|{
return|return
name|mMappedStorage
operator|!=
name|NULL
return|;
block|}
name|void
name|packPixels
argument_list|(
argument|ID3D11Texture2D *srcTexure
argument_list|,
argument|UINT srcSubresource
argument_list|,
argument|const PackPixelsParams&params
argument_list|)
block|;
comment|// BufferD3D implementation
name|virtual
name|size_t
name|getSize
argument_list|()
specifier|const
block|{
return|return
name|mSize
return|;
block|}
name|virtual
name|void
name|clear
argument_list|()
block|;
name|virtual
name|bool
name|supportsDirectBinding
argument_list|()
specifier|const
block|{
return|return
name|true
return|;
block|}
name|virtual
name|Renderer
operator|*
name|getRenderer
argument_list|()
block|;
comment|// BufferImpl implementation
name|virtual
name|void
name|setData
argument_list|(
argument|const void* data
argument_list|,
argument|size_t size
argument_list|,
argument|GLenum usage
argument_list|)
block|;
name|virtual
name|void
operator|*
name|getData
argument_list|()
block|;
name|virtual
name|void
name|setSubData
argument_list|(
argument|const void* data
argument_list|,
argument|size_t size
argument_list|,
argument|size_t offset
argument_list|)
block|;
name|virtual
name|void
name|copySubData
argument_list|(
argument|BufferImpl* source
argument_list|,
argument|GLintptr sourceOffset
argument_list|,
argument|GLintptr destOffset
argument_list|,
argument|GLsizeiptr size
argument_list|)
block|;
name|virtual
name|GLvoid
operator|*
name|map
argument_list|(
argument|size_t offset
argument_list|,
argument|size_t length
argument_list|,
argument|GLbitfield access
argument_list|)
block|;
name|virtual
name|void
name|unmap
argument_list|()
block|;
name|virtual
name|void
name|markTransformFeedbackUsage
argument_list|()
block|;
name|private
operator|:
name|DISALLOW_COPY_AND_ASSIGN
argument_list|(
name|Buffer11
argument_list|)
block|;
name|class
name|BufferStorage11
block|;
name|class
name|NativeBuffer11
block|;
name|class
name|PackStorage11
block|;
name|rx
operator|::
name|Renderer11
operator|*
name|mRenderer
block|;
name|size_t
name|mSize
block|;
name|BufferStorage11
operator|*
name|mMappedStorage
block|;
name|std
operator|::
name|map
operator|<
name|BufferUsage
block|,
name|BufferStorage11
operator|*
operator|>
name|mBufferStorages
block|;
typedef|typedef
name|std
operator|::
name|pair
operator|<
name|ID3D11Buffer
operator|*
operator|,
name|ID3D11ShaderResourceView
operator|*
operator|>
name|BufferSRVPair
expr_stmt|;
name|std
operator|::
name|map
operator|<
name|DXGI_FORMAT
block|,
name|BufferSRVPair
operator|>
name|mBufferResourceViews
decl_stmt|;
name|MemoryBuffer
name|mResolvedData
decl_stmt|;
name|DataRevision
name|mResolvedDataRevision
decl_stmt|;
name|unsigned
name|int
name|mReadUsageCount
decl_stmt|;
name|void
name|markBufferUsage
parameter_list|()
function_decl|;
name|NativeBuffer11
modifier|*
name|getStagingBuffer
parameter_list|()
function_decl|;
name|PackStorage11
modifier|*
name|getPackStorage
parameter_list|()
function_decl|;
name|BufferStorage11
modifier|*
name|getBufferStorage
parameter_list|(
name|BufferUsage
name|usage
parameter_list|)
function_decl|;
name|BufferStorage11
operator|*
name|getLatestBufferStorage
argument_list|()
specifier|const
expr_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_endif
unit|}
endif|#
directive|endif
end_endif
begin_comment
comment|// LIBGLESV2_RENDERER_BUFFER11_H_
end_comment
end_unit