begin_unit
begin_comment
comment|//
end_comment
begin_comment
comment|// Copyright (c) 2013 The ANGLE Project Authors. All rights reserved.
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
comment|// Fence9.h: Defines the rx::Fence9 class which implements rx::FenceImpl.
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|LIBGLESV2_RENDERER_FENCE9_H_
end_ifndef
begin_define
DECL|macro|LIBGLESV2_RENDERER_FENCE9_H_
define|#
directive|define
name|LIBGLESV2_RENDERER_FENCE9_H_
end_define
begin_include
include|#
directive|include
file|"libGLESv2/renderer/FenceImpl.h"
end_include
begin_decl_stmt
name|namespace
name|rx
block|{
name|class
name|Renderer9
decl_stmt|;
name|class
name|Fence9
range|:
name|public
name|FenceImpl
block|{
name|public
operator|:
name|explicit
name|Fence9
argument_list|(
name|rx
operator|::
name|Renderer9
operator|*
name|renderer
argument_list|)
block|;
name|virtual
operator|~
name|Fence9
argument_list|()
block|;
name|GLboolean
name|isFence
argument_list|()
block|;
name|void
name|setFence
argument_list|(
argument|GLenum condition
argument_list|)
block|;
name|GLboolean
name|testFence
argument_list|()
block|;
name|void
name|finishFence
argument_list|()
block|;
name|void
name|getFenceiv
argument_list|(
argument|GLenum pname
argument_list|,
argument|GLint *params
argument_list|)
block|;
name|private
operator|:
name|DISALLOW_COPY_AND_ASSIGN
argument_list|(
name|Fence9
argument_list|)
block|;
name|rx
operator|::
name|Renderer9
operator|*
name|mRenderer
block|;
name|IDirect3DQuery9
operator|*
name|mQuery
block|; }
decl_stmt|;
block|}
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// LIBGLESV2_RENDERER_FENCE9_H_
end_comment
end_unit
