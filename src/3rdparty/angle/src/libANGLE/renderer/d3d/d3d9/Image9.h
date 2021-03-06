begin_unit
begin_comment
comment|//
end_comment
begin_comment
comment|// Copyright (c) 2002-2014 The ANGLE Project Authors. All rights reserved.
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
comment|// Image9.h: Defines the rx::Image9 class, which acts as the interface to
end_comment
begin_comment
comment|// the actual underlying surfaces of a Texture.
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|LIBANGLE_RENDERER_D3D_D3D9_IMAGE9_H_
end_ifndef
begin_define
DECL|macro|LIBANGLE_RENDERER_D3D_D3D9_IMAGE9_H_
define|#
directive|define
name|LIBANGLE_RENDERER_D3D_D3D9_IMAGE9_H_
end_define
begin_include
include|#
directive|include
file|"libANGLE/renderer/d3d/ImageD3D.h"
end_include
begin_include
include|#
directive|include
file|"common/debug.h"
end_include
begin_decl_stmt
name|namespace
name|gl
block|{
name|class
name|Framebuffer
decl_stmt|;
block|}
end_decl_stmt
begin_decl_stmt
name|namespace
name|rx
block|{
name|class
name|Renderer9
decl_stmt|;
name|class
name|Image9
range|:
name|public
name|ImageD3D
block|{
name|public
operator|:
name|Image9
argument_list|(
name|Renderer9
operator|*
name|renderer
argument_list|)
block|;
operator|~
name|Image9
argument_list|()
block|;
specifier|static
name|gl
operator|::
name|Error
name|generateMipmap
argument_list|(
name|Image9
operator|*
name|dest
argument_list|,
name|Image9
operator|*
name|source
argument_list|)
block|;
specifier|static
name|gl
operator|::
name|Error
name|generateMip
argument_list|(
name|IDirect3DSurface9
operator|*
name|destSurface
argument_list|,
name|IDirect3DSurface9
operator|*
name|sourceSurface
argument_list|)
block|;
specifier|static
name|gl
operator|::
name|Error
name|copyLockableSurfaces
argument_list|(
name|IDirect3DSurface9
operator|*
name|dest
argument_list|,
name|IDirect3DSurface9
operator|*
name|source
argument_list|)
block|;
name|bool
name|redefine
argument_list|(
argument|GLenum target
argument_list|,
argument|GLenum internalformat
argument_list|,
argument|const gl::Extents&size
argument_list|,
argument|bool forceRelease
argument_list|)
name|override
block|;
name|D3DFORMAT
name|getD3DFormat
argument_list|()
specifier|const
block|;
name|virtual
name|bool
name|isDirty
argument_list|()
specifier|const
block|;
name|virtual
name|gl
operator|::
name|Error
name|setManagedSurface2D
argument_list|(
argument|TextureStorage *storage
argument_list|,
argument|int level
argument_list|)
block|;
name|virtual
name|gl
operator|::
name|Error
name|setManagedSurfaceCube
argument_list|(
argument|TextureStorage *storage
argument_list|,
argument|int face
argument_list|,
argument|int level
argument_list|)
block|;
name|virtual
name|gl
operator|::
name|Error
name|copyToStorage
argument_list|(
name|TextureStorage
operator|*
name|storage
argument_list|,
specifier|const
name|gl
operator|::
name|ImageIndex
operator|&
name|index
argument_list|,
specifier|const
name|gl
operator|::
name|Box
operator|&
name|region
argument_list|)
block|;
name|virtual
name|gl
operator|::
name|Error
name|loadData
argument_list|(
argument|const gl::Box&area
argument_list|,
argument|const gl::PixelUnpackState&unpack
argument_list|,
argument|GLenum type
argument_list|,
argument|const void *input
argument_list|)
block|;
name|virtual
name|gl
operator|::
name|Error
name|loadCompressedData
argument_list|(
specifier|const
name|gl
operator|::
name|Box
operator|&
name|area
argument_list|,
specifier|const
name|void
operator|*
name|input
argument_list|)
block|;
name|gl
operator|::
name|Error
name|copyFromTexStorage
argument_list|(
argument|const gl::ImageIndex&imageIndex
argument_list|,
argument|TextureStorage *source
argument_list|)
name|override
block|;
name|gl
operator|::
name|Error
name|copyFromFramebuffer
argument_list|(
argument|const gl::Offset&destOffset
argument_list|,
argument|const gl::Rectangle&sourceArea
argument_list|,
argument|const gl::Framebuffer *source
argument_list|)
name|override
block|;
name|private
operator|:
name|gl
operator|::
name|Error
name|getSurface
argument_list|(
name|IDirect3DSurface9
operator|*
operator|*
name|outSurface
argument_list|)
block|;
name|gl
operator|::
name|Error
name|createSurface
argument_list|()
block|;
name|gl
operator|::
name|Error
name|setManagedSurface
argument_list|(
name|IDirect3DSurface9
operator|*
name|surface
argument_list|)
block|;
name|gl
operator|::
name|Error
name|copyToSurface
argument_list|(
name|IDirect3DSurface9
operator|*
name|dest
argument_list|,
specifier|const
name|gl
operator|::
name|Box
operator|&
name|area
argument_list|)
block|;
name|gl
operator|::
name|Error
name|lock
argument_list|(
name|D3DLOCKED_RECT
operator|*
name|lockedRect
argument_list|,
specifier|const
name|RECT
operator|&
name|rect
argument_list|)
block|;
name|void
name|unlock
argument_list|()
block|;
name|gl
operator|::
name|Error
name|copyFromRTInternal
argument_list|(
specifier|const
name|gl
operator|::
name|Offset
operator|&
name|destOffset
argument_list|,
specifier|const
name|gl
operator|::
name|Rectangle
operator|&
name|sourceArea
argument_list|,
name|RenderTargetD3D
operator|*
name|source
argument_list|)
block|;
name|Renderer9
operator|*
name|mRenderer
block|;
name|D3DPOOL
name|mD3DPool
block|;
comment|// can only be D3DPOOL_SYSTEMMEM or D3DPOOL_MANAGED since it needs to be lockable.
name|D3DFORMAT
name|mD3DFormat
block|;
name|IDirect3DSurface9
operator|*
name|mSurface
block|; }
decl_stmt|;
block|}
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// LIBANGLE_RENDERER_D3D_D3D9_IMAGE9_H_
end_comment
end_unit
