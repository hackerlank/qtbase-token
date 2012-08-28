begin_unit
begin_include
include|#
directive|include
file|"precompiled.h"
end_include
begin_comment
comment|//
end_comment
begin_comment
comment|// Copyright (c) 2012 The ANGLE Project Authors. All rights reserved.
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
comment|// renderer11_utils.cpp: Conversion functions and other utility routines
end_comment
begin_comment
comment|// specific to the D3D11 renderer.
end_comment
begin_include
include|#
directive|include
file|"libGLESv2/renderer/d3d11/renderer11_utils.h"
end_include
begin_include
include|#
directive|include
file|"common/debug.h"
end_include
begin_namespace
DECL|namespace|gl_d3d11
namespace|namespace
name|gl_d3d11
block|{
DECL|function|ConvertBlendFunc
name|D3D11_BLEND
name|ConvertBlendFunc
parameter_list|(
name|GLenum
name|glBlend
parameter_list|,
name|bool
name|isAlpha
parameter_list|)
block|{
name|D3D11_BLEND
name|d3dBlend
init|=
name|D3D11_BLEND_ZERO
decl_stmt|;
switch|switch
condition|(
name|glBlend
condition|)
block|{
case|case
name|GL_ZERO
case|:
name|d3dBlend
operator|=
name|D3D11_BLEND_ZERO
expr_stmt|;
break|break;
case|case
name|GL_ONE
case|:
name|d3dBlend
operator|=
name|D3D11_BLEND_ONE
expr_stmt|;
break|break;
case|case
name|GL_SRC_COLOR
case|:
name|d3dBlend
operator|=
operator|(
name|isAlpha
condition|?
name|D3D11_BLEND_SRC_ALPHA
else|:
name|D3D11_BLEND_SRC_COLOR
operator|)
expr_stmt|;
break|break;
case|case
name|GL_ONE_MINUS_SRC_COLOR
case|:
name|d3dBlend
operator|=
operator|(
name|isAlpha
condition|?
name|D3D11_BLEND_INV_SRC_ALPHA
else|:
name|D3D11_BLEND_INV_SRC_COLOR
operator|)
expr_stmt|;
break|break;
case|case
name|GL_DST_COLOR
case|:
name|d3dBlend
operator|=
operator|(
name|isAlpha
condition|?
name|D3D11_BLEND_DEST_ALPHA
else|:
name|D3D11_BLEND_DEST_COLOR
operator|)
expr_stmt|;
break|break;
case|case
name|GL_ONE_MINUS_DST_COLOR
case|:
name|d3dBlend
operator|=
operator|(
name|isAlpha
condition|?
name|D3D11_BLEND_INV_DEST_ALPHA
else|:
name|D3D11_BLEND_INV_DEST_COLOR
operator|)
expr_stmt|;
break|break;
case|case
name|GL_SRC_ALPHA
case|:
name|d3dBlend
operator|=
name|D3D11_BLEND_SRC_ALPHA
expr_stmt|;
break|break;
case|case
name|GL_ONE_MINUS_SRC_ALPHA
case|:
name|d3dBlend
operator|=
name|D3D11_BLEND_INV_SRC_ALPHA
expr_stmt|;
break|break;
case|case
name|GL_DST_ALPHA
case|:
name|d3dBlend
operator|=
name|D3D11_BLEND_DEST_ALPHA
expr_stmt|;
break|break;
case|case
name|GL_ONE_MINUS_DST_ALPHA
case|:
name|d3dBlend
operator|=
name|D3D11_BLEND_INV_DEST_ALPHA
expr_stmt|;
break|break;
case|case
name|GL_CONSTANT_COLOR
case|:
name|d3dBlend
operator|=
name|D3D11_BLEND_BLEND_FACTOR
expr_stmt|;
break|break;
case|case
name|GL_ONE_MINUS_CONSTANT_COLOR
case|:
name|d3dBlend
operator|=
name|D3D11_BLEND_INV_BLEND_FACTOR
expr_stmt|;
break|break;
case|case
name|GL_CONSTANT_ALPHA
case|:
name|d3dBlend
operator|=
name|D3D11_BLEND_BLEND_FACTOR
expr_stmt|;
break|break;
case|case
name|GL_ONE_MINUS_CONSTANT_ALPHA
case|:
name|d3dBlend
operator|=
name|D3D11_BLEND_INV_BLEND_FACTOR
expr_stmt|;
break|break;
case|case
name|GL_SRC_ALPHA_SATURATE
case|:
name|d3dBlend
operator|=
name|D3D11_BLEND_SRC_ALPHA_SAT
expr_stmt|;
break|break;
default|default:
name|UNREACHABLE
argument_list|()
expr_stmt|;
block|}
return|return
name|d3dBlend
return|;
block|}
DECL|function|ConvertBlendOp
name|D3D11_BLEND_OP
name|ConvertBlendOp
parameter_list|(
name|GLenum
name|glBlendOp
parameter_list|)
block|{
name|D3D11_BLEND_OP
name|d3dBlendOp
init|=
name|D3D11_BLEND_OP_ADD
decl_stmt|;
switch|switch
condition|(
name|glBlendOp
condition|)
block|{
case|case
name|GL_FUNC_ADD
case|:
name|d3dBlendOp
operator|=
name|D3D11_BLEND_OP_ADD
expr_stmt|;
break|break;
case|case
name|GL_FUNC_SUBTRACT
case|:
name|d3dBlendOp
operator|=
name|D3D11_BLEND_OP_SUBTRACT
expr_stmt|;
break|break;
case|case
name|GL_FUNC_REVERSE_SUBTRACT
case|:
name|d3dBlendOp
operator|=
name|D3D11_BLEND_OP_REV_SUBTRACT
expr_stmt|;
break|break;
default|default:
name|UNREACHABLE
argument_list|()
expr_stmt|;
block|}
return|return
name|d3dBlendOp
return|;
block|}
DECL|function|ConvertColorMask
name|UINT8
name|ConvertColorMask
parameter_list|(
name|bool
name|red
parameter_list|,
name|bool
name|green
parameter_list|,
name|bool
name|blue
parameter_list|,
name|bool
name|alpha
parameter_list|)
block|{
name|UINT8
name|mask
init|=
literal|0
decl_stmt|;
if|if
condition|(
name|red
condition|)
block|{
name|mask
operator||=
name|D3D11_COLOR_WRITE_ENABLE_RED
expr_stmt|;
block|}
if|if
condition|(
name|green
condition|)
block|{
name|mask
operator||=
name|D3D11_COLOR_WRITE_ENABLE_GREEN
expr_stmt|;
block|}
if|if
condition|(
name|blue
condition|)
block|{
name|mask
operator||=
name|D3D11_COLOR_WRITE_ENABLE_BLUE
expr_stmt|;
block|}
if|if
condition|(
name|alpha
condition|)
block|{
name|mask
operator||=
name|D3D11_COLOR_WRITE_ENABLE_ALPHA
expr_stmt|;
block|}
return|return
name|mask
return|;
block|}
DECL|function|ConvertCullMode
name|D3D11_CULL_MODE
name|ConvertCullMode
parameter_list|(
name|bool
name|cullEnabled
parameter_list|,
name|GLenum
name|cullMode
parameter_list|)
block|{
name|D3D11_CULL_MODE
name|cull
init|=
name|D3D11_CULL_NONE
decl_stmt|;
if|if
condition|(
name|cullEnabled
condition|)
block|{
switch|switch
condition|(
name|cullMode
condition|)
block|{
case|case
name|GL_FRONT
case|:
name|cull
operator|=
name|D3D11_CULL_FRONT
expr_stmt|;
break|break;
case|case
name|GL_BACK
case|:
name|cull
operator|=
name|D3D11_CULL_BACK
expr_stmt|;
break|break;
case|case
name|GL_FRONT_AND_BACK
case|:
name|cull
operator|=
name|D3D11_CULL_NONE
expr_stmt|;
break|break;
default|default:
name|UNREACHABLE
argument_list|()
expr_stmt|;
block|}
block|}
else|else
block|{
name|cull
operator|=
name|D3D11_CULL_NONE
expr_stmt|;
block|}
return|return
name|cull
return|;
block|}
DECL|function|ConvertComparison
name|D3D11_COMPARISON_FUNC
name|ConvertComparison
parameter_list|(
name|GLenum
name|comparison
parameter_list|)
block|{
name|D3D11_COMPARISON_FUNC
name|d3dComp
init|=
name|D3D11_COMPARISON_NEVER
decl_stmt|;
switch|switch
condition|(
name|comparison
condition|)
block|{
case|case
name|GL_NEVER
case|:
name|d3dComp
operator|=
name|D3D11_COMPARISON_NEVER
expr_stmt|;
break|break;
case|case
name|GL_ALWAYS
case|:
name|d3dComp
operator|=
name|D3D11_COMPARISON_ALWAYS
expr_stmt|;
break|break;
case|case
name|GL_LESS
case|:
name|d3dComp
operator|=
name|D3D11_COMPARISON_LESS
expr_stmt|;
break|break;
case|case
name|GL_LEQUAL
case|:
name|d3dComp
operator|=
name|D3D11_COMPARISON_LESS_EQUAL
expr_stmt|;
break|break;
case|case
name|GL_EQUAL
case|:
name|d3dComp
operator|=
name|D3D11_COMPARISON_EQUAL
expr_stmt|;
break|break;
case|case
name|GL_GREATER
case|:
name|d3dComp
operator|=
name|D3D11_COMPARISON_GREATER
expr_stmt|;
break|break;
case|case
name|GL_GEQUAL
case|:
name|d3dComp
operator|=
name|D3D11_COMPARISON_GREATER_EQUAL
expr_stmt|;
break|break;
case|case
name|GL_NOTEQUAL
case|:
name|d3dComp
operator|=
name|D3D11_COMPARISON_NOT_EQUAL
expr_stmt|;
break|break;
default|default:
name|UNREACHABLE
argument_list|()
expr_stmt|;
block|}
return|return
name|d3dComp
return|;
block|}
DECL|function|ConvertDepthMask
name|D3D11_DEPTH_WRITE_MASK
name|ConvertDepthMask
parameter_list|(
name|bool
name|depthWriteEnabled
parameter_list|)
block|{
return|return
name|depthWriteEnabled
condition|?
name|D3D11_DEPTH_WRITE_MASK_ALL
else|:
name|D3D11_DEPTH_WRITE_MASK_ZERO
return|;
block|}
DECL|function|ConvertStencilMask
name|UINT8
name|ConvertStencilMask
parameter_list|(
name|GLuint
name|stencilmask
parameter_list|)
block|{
return|return
cast|static_cast
argument_list|<
name|UINT8
argument_list|>
argument_list|(
name|stencilmask
argument_list|)
return|;
block|}
DECL|function|ConvertStencilOp
name|D3D11_STENCIL_OP
name|ConvertStencilOp
parameter_list|(
name|GLenum
name|stencilOp
parameter_list|)
block|{
name|D3D11_STENCIL_OP
name|d3dStencilOp
init|=
name|D3D11_STENCIL_OP_KEEP
decl_stmt|;
switch|switch
condition|(
name|stencilOp
condition|)
block|{
case|case
name|GL_ZERO
case|:
name|d3dStencilOp
operator|=
name|D3D11_STENCIL_OP_ZERO
expr_stmt|;
break|break;
case|case
name|GL_KEEP
case|:
name|d3dStencilOp
operator|=
name|D3D11_STENCIL_OP_KEEP
expr_stmt|;
break|break;
case|case
name|GL_REPLACE
case|:
name|d3dStencilOp
operator|=
name|D3D11_STENCIL_OP_REPLACE
expr_stmt|;
break|break;
case|case
name|GL_INCR
case|:
name|d3dStencilOp
operator|=
name|D3D11_STENCIL_OP_INCR_SAT
expr_stmt|;
break|break;
case|case
name|GL_DECR
case|:
name|d3dStencilOp
operator|=
name|D3D11_STENCIL_OP_DECR_SAT
expr_stmt|;
break|break;
case|case
name|GL_INVERT
case|:
name|d3dStencilOp
operator|=
name|D3D11_STENCIL_OP_INVERT
expr_stmt|;
break|break;
case|case
name|GL_INCR_WRAP
case|:
name|d3dStencilOp
operator|=
name|D3D11_STENCIL_OP_INCR
expr_stmt|;
break|break;
case|case
name|GL_DECR_WRAP
case|:
name|d3dStencilOp
operator|=
name|D3D11_STENCIL_OP_DECR
expr_stmt|;
break|break;
default|default:
name|UNREACHABLE
argument_list|()
expr_stmt|;
block|}
return|return
name|d3dStencilOp
return|;
block|}
DECL|function|ConvertFilter
name|D3D11_FILTER
name|ConvertFilter
parameter_list|(
name|GLenum
name|minFilter
parameter_list|,
name|GLenum
name|magFilter
parameter_list|,
name|float
name|maxAnisotropy
parameter_list|)
block|{
if|if
condition|(
name|maxAnisotropy
operator|>
literal|1.0f
condition|)
block|{
return|return
name|D3D11_ENCODE_ANISOTROPIC_FILTER
argument_list|(
literal|false
argument_list|)
return|;
block|}
else|else
block|{
name|D3D11_FILTER_TYPE
name|dxMin
init|=
name|D3D11_FILTER_TYPE_POINT
decl_stmt|;
name|D3D11_FILTER_TYPE
name|dxMip
init|=
name|D3D11_FILTER_TYPE_POINT
decl_stmt|;
switch|switch
condition|(
name|minFilter
condition|)
block|{
case|case
name|GL_NEAREST
case|:
name|dxMin
operator|=
name|D3D11_FILTER_TYPE_POINT
expr_stmt|;
name|dxMip
operator|=
name|D3D11_FILTER_TYPE_POINT
expr_stmt|;
break|break;
case|case
name|GL_LINEAR
case|:
name|dxMin
operator|=
name|D3D11_FILTER_TYPE_LINEAR
expr_stmt|;
name|dxMip
operator|=
name|D3D11_FILTER_TYPE_POINT
expr_stmt|;
break|break;
case|case
name|GL_NEAREST_MIPMAP_NEAREST
case|:
name|dxMin
operator|=
name|D3D11_FILTER_TYPE_POINT
expr_stmt|;
name|dxMip
operator|=
name|D3D11_FILTER_TYPE_POINT
expr_stmt|;
break|break;
case|case
name|GL_LINEAR_MIPMAP_NEAREST
case|:
name|dxMin
operator|=
name|D3D11_FILTER_TYPE_LINEAR
expr_stmt|;
name|dxMip
operator|=
name|D3D11_FILTER_TYPE_POINT
expr_stmt|;
break|break;
case|case
name|GL_NEAREST_MIPMAP_LINEAR
case|:
name|dxMin
operator|=
name|D3D11_FILTER_TYPE_POINT
expr_stmt|;
name|dxMip
operator|=
name|D3D11_FILTER_TYPE_LINEAR
expr_stmt|;
break|break;
case|case
name|GL_LINEAR_MIPMAP_LINEAR
case|:
name|dxMin
operator|=
name|D3D11_FILTER_TYPE_LINEAR
expr_stmt|;
name|dxMip
operator|=
name|D3D11_FILTER_TYPE_LINEAR
expr_stmt|;
break|break;
default|default:
name|UNREACHABLE
argument_list|()
expr_stmt|;
block|}
name|D3D11_FILTER_TYPE
name|dxMag
init|=
name|D3D11_FILTER_TYPE_POINT
decl_stmt|;
switch|switch
condition|(
name|magFilter
condition|)
block|{
case|case
name|GL_NEAREST
case|:
name|dxMag
operator|=
name|D3D11_FILTER_TYPE_POINT
expr_stmt|;
break|break;
case|case
name|GL_LINEAR
case|:
name|dxMag
operator|=
name|D3D11_FILTER_TYPE_LINEAR
expr_stmt|;
break|break;
default|default:
name|UNREACHABLE
argument_list|()
expr_stmt|;
block|}
return|return
name|D3D11_ENCODE_BASIC_FILTER
argument_list|(
name|dxMin
argument_list|,
name|dxMag
argument_list|,
name|dxMip
argument_list|,
literal|false
argument_list|)
return|;
block|}
block|}
DECL|function|ConvertTextureWrap
name|D3D11_TEXTURE_ADDRESS_MODE
name|ConvertTextureWrap
parameter_list|(
name|GLenum
name|wrap
parameter_list|)
block|{
switch|switch
condition|(
name|wrap
condition|)
block|{
case|case
name|GL_REPEAT
case|:
return|return
name|D3D11_TEXTURE_ADDRESS_WRAP
return|;
case|case
name|GL_CLAMP_TO_EDGE
case|:
return|return
name|D3D11_TEXTURE_ADDRESS_CLAMP
return|;
case|case
name|GL_MIRRORED_REPEAT
case|:
return|return
name|D3D11_TEXTURE_ADDRESS_MIRROR
return|;
default|default:
name|UNREACHABLE
argument_list|()
expr_stmt|;
block|}
return|return
name|D3D11_TEXTURE_ADDRESS_WRAP
return|;
block|}
DECL|function|ConvertMinLOD
name|FLOAT
name|ConvertMinLOD
parameter_list|(
name|GLenum
name|minFilter
parameter_list|,
name|unsigned
name|int
name|lodOffset
parameter_list|)
block|{
return|return
operator|(
name|minFilter
operator|==
name|GL_NEAREST
operator|||
name|minFilter
operator|==
name|GL_LINEAR
operator|)
condition|?
cast|static_cast
argument_list|<
name|float
argument_list|>
argument_list|(
name|lodOffset
argument_list|)
else|:
operator|-
name|FLT_MAX
return|;
block|}
DECL|function|ConvertMaxLOD
name|FLOAT
name|ConvertMaxLOD
parameter_list|(
name|GLenum
name|minFilter
parameter_list|,
name|unsigned
name|int
name|lodOffset
parameter_list|)
block|{
return|return
operator|(
name|minFilter
operator|==
name|GL_NEAREST
operator|||
name|minFilter
operator|==
name|GL_LINEAR
operator|)
condition|?
cast|static_cast
argument_list|<
name|float
argument_list|>
argument_list|(
name|lodOffset
argument_list|)
else|:
name|FLT_MAX
return|;
block|}
block|}
end_namespace
begin_namespace
DECL|namespace|d3d11_gl
namespace|namespace
name|d3d11_gl
block|{
DECL|function|ConvertBackBufferFormat
name|GLenum
name|ConvertBackBufferFormat
parameter_list|(
name|DXGI_FORMAT
name|format
parameter_list|)
block|{
switch|switch
condition|(
name|format
condition|)
block|{
case|case
name|DXGI_FORMAT_R8G8B8A8_UNORM
case|:
return|return
name|GL_RGBA8_OES
return|;
case|case
name|DXGI_FORMAT_B8G8R8A8_UNORM
case|:
return|return
name|GL_BGRA8_EXT
return|;
default|default:
name|UNREACHABLE
argument_list|()
expr_stmt|;
block|}
return|return
name|GL_RGBA8_OES
return|;
block|}
DECL|function|ConvertDepthStencilFormat
name|GLenum
name|ConvertDepthStencilFormat
parameter_list|(
name|DXGI_FORMAT
name|format
parameter_list|)
block|{
switch|switch
condition|(
name|format
condition|)
block|{
case|case
name|DXGI_FORMAT_UNKNOWN
case|:
return|return
name|GL_NONE
return|;
case|case
name|DXGI_FORMAT_D16_UNORM
case|:
return|return
name|GL_DEPTH_COMPONENT16
return|;
case|case
name|DXGI_FORMAT_D24_UNORM_S8_UINT
case|:
return|return
name|GL_DEPTH24_STENCIL8_OES
return|;
default|default:
name|UNREACHABLE
argument_list|()
expr_stmt|;
block|}
return|return
name|GL_DEPTH24_STENCIL8_OES
return|;
block|}
DECL|function|ConvertRenderbufferFormat
name|GLenum
name|ConvertRenderbufferFormat
parameter_list|(
name|DXGI_FORMAT
name|format
parameter_list|)
block|{
switch|switch
condition|(
name|format
condition|)
block|{
case|case
name|DXGI_FORMAT_B8G8R8A8_UNORM
case|:
return|return
name|GL_BGRA8_EXT
return|;
case|case
name|DXGI_FORMAT_R8G8B8A8_UNORM
case|:
return|return
name|GL_RGBA8_OES
return|;
case|case
name|DXGI_FORMAT_D16_UNORM
case|:
return|return
name|GL_DEPTH_COMPONENT16
return|;
case|case
name|DXGI_FORMAT_D24_UNORM_S8_UINT
case|:
return|return
name|GL_DEPTH24_STENCIL8_OES
return|;
default|default:
name|UNREACHABLE
argument_list|()
expr_stmt|;
block|}
return|return
name|GL_RGBA8_OES
return|;
block|}
DECL|function|ConvertTextureInternalFormat
name|GLenum
name|ConvertTextureInternalFormat
parameter_list|(
name|DXGI_FORMAT
name|format
parameter_list|)
block|{
switch|switch
condition|(
name|format
condition|)
block|{
case|case
name|DXGI_FORMAT_R8G8B8A8_UNORM
case|:
return|return
name|GL_RGBA8_OES
return|;
case|case
name|DXGI_FORMAT_A8_UNORM
case|:
return|return
name|GL_ALPHA8_EXT
return|;
case|case
name|DXGI_FORMAT_BC1_UNORM
case|:
return|return
name|GL_COMPRESSED_RGBA_S3TC_DXT1_EXT
return|;
case|case
name|DXGI_FORMAT_BC2_UNORM
case|:
return|return
name|GL_COMPRESSED_RGBA_S3TC_DXT3_ANGLE
return|;
case|case
name|DXGI_FORMAT_BC3_UNORM
case|:
return|return
name|GL_COMPRESSED_RGBA_S3TC_DXT5_ANGLE
return|;
case|case
name|DXGI_FORMAT_R32G32B32A32_FLOAT
case|:
return|return
name|GL_RGBA32F_EXT
return|;
case|case
name|DXGI_FORMAT_R32G32B32_FLOAT
case|:
return|return
name|GL_RGB32F_EXT
return|;
case|case
name|DXGI_FORMAT_R16G16B16A16_FLOAT
case|:
return|return
name|GL_RGBA16F_EXT
return|;
case|case
name|DXGI_FORMAT_B8G8R8A8_UNORM
case|:
return|return
name|GL_BGRA8_EXT
return|;
case|case
name|DXGI_FORMAT_R8_UNORM
case|:
return|return
name|GL_R8_EXT
return|;
case|case
name|DXGI_FORMAT_R8G8_UNORM
case|:
return|return
name|GL_RG8_EXT
return|;
case|case
name|DXGI_FORMAT_R16_FLOAT
case|:
return|return
name|GL_R16F_EXT
return|;
case|case
name|DXGI_FORMAT_R16G16_FLOAT
case|:
return|return
name|GL_RG16F_EXT
return|;
case|case
name|DXGI_FORMAT_D16_UNORM
case|:
return|return
name|GL_DEPTH_COMPONENT16
return|;
case|case
name|DXGI_FORMAT_D24_UNORM_S8_UINT
case|:
return|return
name|GL_DEPTH24_STENCIL8_OES
return|;
case|case
name|DXGI_FORMAT_UNKNOWN
case|:
return|return
name|GL_NONE
return|;
default|default:
name|UNREACHABLE
argument_list|()
expr_stmt|;
block|}
return|return
name|GL_RGBA8_OES
return|;
block|}
block|}
end_namespace
begin_namespace
DECL|namespace|gl_d3d11
namespace|namespace
name|gl_d3d11
block|{
DECL|function|ConvertRenderbufferFormat
name|DXGI_FORMAT
name|ConvertRenderbufferFormat
parameter_list|(
name|GLenum
name|format
parameter_list|)
block|{
switch|switch
condition|(
name|format
condition|)
block|{
case|case
name|GL_RGBA4
case|:
case|case
name|GL_RGB5_A1
case|:
case|case
name|GL_RGBA8_OES
case|:
case|case
name|GL_RGB565
case|:
case|case
name|GL_RGB8_OES
case|:
return|return
name|DXGI_FORMAT_R8G8B8A8_UNORM
return|;
case|case
name|GL_BGRA8_EXT
case|:
return|return
name|DXGI_FORMAT_B8G8R8A8_UNORM
return|;
case|case
name|GL_DEPTH_COMPONENT16
case|:
return|return
name|DXGI_FORMAT_D16_UNORM
return|;
case|case
name|GL_STENCIL_INDEX8
case|:
case|case
name|GL_DEPTH24_STENCIL8_OES
case|:
return|return
name|DXGI_FORMAT_D24_UNORM_S8_UINT
return|;
default|default:
name|UNREACHABLE
argument_list|()
expr_stmt|;
block|}
return|return
name|DXGI_FORMAT_R8G8B8A8_UNORM
return|;
block|}
DECL|function|ConvertTextureFormat
name|DXGI_FORMAT
name|ConvertTextureFormat
parameter_list|(
name|GLenum
name|internalformat
parameter_list|,
name|D3D_FEATURE_LEVEL
name|featureLevel
parameter_list|)
block|{
switch|switch
condition|(
name|internalformat
condition|)
block|{
case|case
name|GL_RGB565
case|:
case|case
name|GL_RGBA4
case|:
case|case
name|GL_RGB5_A1
case|:
case|case
name|GL_RGB8_OES
case|:
case|case
name|GL_RGBA8_OES
case|:
case|case
name|GL_LUMINANCE8_EXT
case|:
case|case
name|GL_LUMINANCE8_ALPHA8_EXT
case|:
return|return
name|DXGI_FORMAT_R8G8B8A8_UNORM
return|;
case|case
name|GL_ALPHA8_EXT
case|:
return|return
name|featureLevel
operator|>=
name|D3D_FEATURE_LEVEL_10_0
condition|?
name|DXGI_FORMAT_A8_UNORM
else|:
name|DXGI_FORMAT_B8G8R8A8_UNORM
return|;
case|case
name|GL_COMPRESSED_RGB_S3TC_DXT1_EXT
case|:
case|case
name|GL_COMPRESSED_RGBA_S3TC_DXT1_EXT
case|:
return|return
name|DXGI_FORMAT_BC1_UNORM
return|;
case|case
name|GL_COMPRESSED_RGBA_S3TC_DXT3_ANGLE
case|:
return|return
name|DXGI_FORMAT_BC2_UNORM
return|;
case|case
name|GL_COMPRESSED_RGBA_S3TC_DXT5_ANGLE
case|:
return|return
name|DXGI_FORMAT_BC3_UNORM
return|;
case|case
name|GL_RGBA32F_EXT
case|:
case|case
name|GL_ALPHA32F_EXT
case|:
case|case
name|GL_LUMINANCE_ALPHA32F_EXT
case|:
return|return
name|DXGI_FORMAT_R32G32B32A32_FLOAT
return|;
case|case
name|GL_RGB32F_EXT
case|:
case|case
name|GL_LUMINANCE32F_EXT
case|:
return|return
name|DXGI_FORMAT_R32G32B32A32_FLOAT
return|;
case|case
name|GL_RGBA16F_EXT
case|:
case|case
name|GL_ALPHA16F_EXT
case|:
case|case
name|GL_LUMINANCE_ALPHA16F_EXT
case|:
case|case
name|GL_RGB16F_EXT
case|:
case|case
name|GL_LUMINANCE16F_EXT
case|:
return|return
name|DXGI_FORMAT_R16G16B16A16_FLOAT
return|;
case|case
name|GL_BGRA8_EXT
case|:
return|return
name|DXGI_FORMAT_B8G8R8A8_UNORM
return|;
case|case
name|GL_R8_EXT
case|:
return|return
name|DXGI_FORMAT_R8_UNORM
return|;
case|case
name|GL_RG8_EXT
case|:
return|return
name|DXGI_FORMAT_R8G8_UNORM
return|;
case|case
name|GL_R16F_EXT
case|:
return|return
name|DXGI_FORMAT_R16_FLOAT
return|;
case|case
name|GL_RG16F_EXT
case|:
return|return
name|DXGI_FORMAT_R16G16_FLOAT
return|;
case|case
name|GL_DEPTH_COMPONENT16
case|:
return|return
name|DXGI_FORMAT_D16_UNORM
return|;
case|case
name|GL_DEPTH_COMPONENT32_OES
case|:
case|case
name|GL_DEPTH24_STENCIL8_OES
case|:
return|return
name|DXGI_FORMAT_D24_UNORM_S8_UINT
return|;
case|case
name|GL_NONE
case|:
return|return
name|DXGI_FORMAT_UNKNOWN
return|;
default|default:
name|UNREACHABLE
argument_list|()
expr_stmt|;
block|}
return|return
name|DXGI_FORMAT_R8G8B8A8_UNORM
return|;
block|}
block|}
end_namespace
begin_namespace
DECL|namespace|d3d11
namespace|namespace
name|d3d11
block|{
DECL|function|SetPositionTexCoordVertex
name|void
name|SetPositionTexCoordVertex
parameter_list|(
name|PositionTexCoordVertex
modifier|*
name|vertex
parameter_list|,
name|float
name|x
parameter_list|,
name|float
name|y
parameter_list|,
name|float
name|u
parameter_list|,
name|float
name|v
parameter_list|)
block|{
name|vertex
operator|->
name|x
operator|=
name|x
expr_stmt|;
name|vertex
operator|->
name|y
operator|=
name|y
expr_stmt|;
name|vertex
operator|->
name|u
operator|=
name|u
expr_stmt|;
name|vertex
operator|->
name|v
operator|=
name|v
expr_stmt|;
block|}
DECL|function|SetPositionDepthColorVertex
name|void
name|SetPositionDepthColorVertex
parameter_list|(
name|PositionDepthColorVertex
modifier|*
name|vertex
parameter_list|,
name|float
name|x
parameter_list|,
name|float
name|y
parameter_list|,
name|float
name|z
parameter_list|,
specifier|const
name|gl
operator|::
name|Color
modifier|&
name|color
parameter_list|)
block|{
name|vertex
operator|->
name|x
operator|=
name|x
expr_stmt|;
name|vertex
operator|->
name|y
operator|=
name|y
expr_stmt|;
name|vertex
operator|->
name|z
operator|=
name|z
expr_stmt|;
name|vertex
operator|->
name|r
operator|=
name|color
operator|.
name|red
expr_stmt|;
name|vertex
operator|->
name|g
operator|=
name|color
operator|.
name|green
expr_stmt|;
name|vertex
operator|->
name|b
operator|=
name|color
operator|.
name|blue
expr_stmt|;
name|vertex
operator|->
name|a
operator|=
name|color
operator|.
name|alpha
expr_stmt|;
block|}
DECL|function|ComputePixelSizeBits
name|size_t
name|ComputePixelSizeBits
parameter_list|(
name|DXGI_FORMAT
name|format
parameter_list|)
block|{
switch|switch
condition|(
name|format
condition|)
block|{
case|case
name|DXGI_FORMAT_R1_UNORM
case|:
return|return
literal|1
return|;
case|case
name|DXGI_FORMAT_A8_UNORM
case|:
case|case
name|DXGI_FORMAT_R8_SINT
case|:
case|case
name|DXGI_FORMAT_R8_SNORM
case|:
case|case
name|DXGI_FORMAT_R8_TYPELESS
case|:
case|case
name|DXGI_FORMAT_R8_UINT
case|:
case|case
name|DXGI_FORMAT_R8_UNORM
case|:
return|return
literal|8
return|;
case|case
name|DXGI_FORMAT_B5G5R5A1_UNORM
case|:
case|case
name|DXGI_FORMAT_B5G6R5_UNORM
case|:
case|case
name|DXGI_FORMAT_D16_UNORM
case|:
case|case
name|DXGI_FORMAT_R16_FLOAT
case|:
case|case
name|DXGI_FORMAT_R16_SINT
case|:
case|case
name|DXGI_FORMAT_R16_SNORM
case|:
case|case
name|DXGI_FORMAT_R16_TYPELESS
case|:
case|case
name|DXGI_FORMAT_R16_UINT
case|:
case|case
name|DXGI_FORMAT_R16_UNORM
case|:
case|case
name|DXGI_FORMAT_R8G8_SINT
case|:
case|case
name|DXGI_FORMAT_R8G8_SNORM
case|:
case|case
name|DXGI_FORMAT_R8G8_TYPELESS
case|:
case|case
name|DXGI_FORMAT_R8G8_UINT
case|:
case|case
name|DXGI_FORMAT_R8G8_UNORM
case|:
return|return
literal|16
return|;
case|case
name|DXGI_FORMAT_B8G8R8X8_TYPELESS
case|:
case|case
name|DXGI_FORMAT_B8G8R8X8_UNORM
case|:
case|case
name|DXGI_FORMAT_B8G8R8X8_UNORM_SRGB
case|:
case|case
name|DXGI_FORMAT_D24_UNORM_S8_UINT
case|:
case|case
name|DXGI_FORMAT_D32_FLOAT
case|:
case|case
name|DXGI_FORMAT_D32_FLOAT_S8X24_UINT
case|:
case|case
name|DXGI_FORMAT_G8R8_G8B8_UNORM
case|:
case|case
name|DXGI_FORMAT_R10G10B10_XR_BIAS_A2_UNORM
case|:
case|case
name|DXGI_FORMAT_R10G10B10A2_TYPELESS
case|:
case|case
name|DXGI_FORMAT_R10G10B10A2_UINT
case|:
case|case
name|DXGI_FORMAT_R10G10B10A2_UNORM
case|:
case|case
name|DXGI_FORMAT_R11G11B10_FLOAT
case|:
case|case
name|DXGI_FORMAT_R16G16_FLOAT
case|:
case|case
name|DXGI_FORMAT_R16G16_SINT
case|:
case|case
name|DXGI_FORMAT_R16G16_SNORM
case|:
case|case
name|DXGI_FORMAT_R16G16_TYPELESS
case|:
case|case
name|DXGI_FORMAT_R16G16_UINT
case|:
case|case
name|DXGI_FORMAT_R16G16_UNORM
case|:
case|case
name|DXGI_FORMAT_R24_UNORM_X8_TYPELESS
case|:
case|case
name|DXGI_FORMAT_R24G8_TYPELESS
case|:
case|case
name|DXGI_FORMAT_R32_FLOAT
case|:
case|case
name|DXGI_FORMAT_R32_FLOAT_X8X24_TYPELESS
case|:
case|case
name|DXGI_FORMAT_R32_SINT
case|:
case|case
name|DXGI_FORMAT_R32_TYPELESS
case|:
case|case
name|DXGI_FORMAT_R32_UINT
case|:
case|case
name|DXGI_FORMAT_R8G8_B8G8_UNORM
case|:
case|case
name|DXGI_FORMAT_R8G8B8A8_SINT
case|:
case|case
name|DXGI_FORMAT_R8G8B8A8_SNORM
case|:
case|case
name|DXGI_FORMAT_R8G8B8A8_TYPELESS
case|:
case|case
name|DXGI_FORMAT_R8G8B8A8_UINT
case|:
case|case
name|DXGI_FORMAT_R8G8B8A8_UNORM
case|:
case|case
name|DXGI_FORMAT_R8G8B8A8_UNORM_SRGB
case|:
case|case
name|DXGI_FORMAT_B8G8R8A8_TYPELESS
case|:
case|case
name|DXGI_FORMAT_B8G8R8A8_UNORM
case|:
case|case
name|DXGI_FORMAT_B8G8R8A8_UNORM_SRGB
case|:
case|case
name|DXGI_FORMAT_R9G9B9E5_SHAREDEXP
case|:
case|case
name|DXGI_FORMAT_X24_TYPELESS_G8_UINT
case|:
case|case
name|DXGI_FORMAT_X32_TYPELESS_G8X24_UINT
case|:
return|return
literal|32
return|;
case|case
name|DXGI_FORMAT_R16G16B16A16_FLOAT
case|:
case|case
name|DXGI_FORMAT_R16G16B16A16_SINT
case|:
case|case
name|DXGI_FORMAT_R16G16B16A16_SNORM
case|:
case|case
name|DXGI_FORMAT_R16G16B16A16_TYPELESS
case|:
case|case
name|DXGI_FORMAT_R16G16B16A16_UINT
case|:
case|case
name|DXGI_FORMAT_R16G16B16A16_UNORM
case|:
case|case
name|DXGI_FORMAT_R32G32_FLOAT
case|:
case|case
name|DXGI_FORMAT_R32G32_SINT
case|:
case|case
name|DXGI_FORMAT_R32G32_TYPELESS
case|:
case|case
name|DXGI_FORMAT_R32G32_UINT
case|:
case|case
name|DXGI_FORMAT_R32G8X24_TYPELESS
case|:
return|return
literal|64
return|;
case|case
name|DXGI_FORMAT_R32G32B32_FLOAT
case|:
case|case
name|DXGI_FORMAT_R32G32B32_SINT
case|:
case|case
name|DXGI_FORMAT_R32G32B32_TYPELESS
case|:
case|case
name|DXGI_FORMAT_R32G32B32_UINT
case|:
return|return
literal|96
return|;
case|case
name|DXGI_FORMAT_R32G32B32A32_FLOAT
case|:
case|case
name|DXGI_FORMAT_R32G32B32A32_SINT
case|:
case|case
name|DXGI_FORMAT_R32G32B32A32_TYPELESS
case|:
case|case
name|DXGI_FORMAT_R32G32B32A32_UINT
case|:
return|return
literal|128
return|;
case|case
name|DXGI_FORMAT_BC1_TYPELESS
case|:
case|case
name|DXGI_FORMAT_BC1_UNORM
case|:
case|case
name|DXGI_FORMAT_BC1_UNORM_SRGB
case|:
case|case
name|DXGI_FORMAT_BC4_SNORM
case|:
case|case
name|DXGI_FORMAT_BC4_TYPELESS
case|:
case|case
name|DXGI_FORMAT_BC4_UNORM
case|:
return|return
literal|4
return|;
case|case
name|DXGI_FORMAT_BC2_TYPELESS
case|:
case|case
name|DXGI_FORMAT_BC2_UNORM
case|:
case|case
name|DXGI_FORMAT_BC2_UNORM_SRGB
case|:
case|case
name|DXGI_FORMAT_BC3_TYPELESS
case|:
case|case
name|DXGI_FORMAT_BC3_UNORM
case|:
case|case
name|DXGI_FORMAT_BC3_UNORM_SRGB
case|:
case|case
name|DXGI_FORMAT_BC5_SNORM
case|:
case|case
name|DXGI_FORMAT_BC5_TYPELESS
case|:
case|case
name|DXGI_FORMAT_BC5_UNORM
case|:
case|case
name|DXGI_FORMAT_BC6H_SF16
case|:
case|case
name|DXGI_FORMAT_BC6H_TYPELESS
case|:
case|case
name|DXGI_FORMAT_BC6H_UF16
case|:
case|case
name|DXGI_FORMAT_BC7_TYPELESS
case|:
case|case
name|DXGI_FORMAT_BC7_UNORM
case|:
case|case
name|DXGI_FORMAT_BC7_UNORM_SRGB
case|:
return|return
literal|8
return|;
default|default:
return|return
literal|0
return|;
block|}
block|}
DECL|function|ComputeBlockSizeBits
name|size_t
name|ComputeBlockSizeBits
parameter_list|(
name|DXGI_FORMAT
name|format
parameter_list|)
block|{
switch|switch
condition|(
name|format
condition|)
block|{
case|case
name|DXGI_FORMAT_BC1_TYPELESS
case|:
case|case
name|DXGI_FORMAT_BC1_UNORM
case|:
case|case
name|DXGI_FORMAT_BC1_UNORM_SRGB
case|:
case|case
name|DXGI_FORMAT_BC4_SNORM
case|:
case|case
name|DXGI_FORMAT_BC4_TYPELESS
case|:
case|case
name|DXGI_FORMAT_BC4_UNORM
case|:
case|case
name|DXGI_FORMAT_BC2_TYPELESS
case|:
case|case
name|DXGI_FORMAT_BC2_UNORM
case|:
case|case
name|DXGI_FORMAT_BC2_UNORM_SRGB
case|:
case|case
name|DXGI_FORMAT_BC3_TYPELESS
case|:
case|case
name|DXGI_FORMAT_BC3_UNORM
case|:
case|case
name|DXGI_FORMAT_BC3_UNORM_SRGB
case|:
case|case
name|DXGI_FORMAT_BC5_SNORM
case|:
case|case
name|DXGI_FORMAT_BC5_TYPELESS
case|:
case|case
name|DXGI_FORMAT_BC5_UNORM
case|:
case|case
name|DXGI_FORMAT_BC6H_SF16
case|:
case|case
name|DXGI_FORMAT_BC6H_TYPELESS
case|:
case|case
name|DXGI_FORMAT_BC6H_UF16
case|:
case|case
name|DXGI_FORMAT_BC7_TYPELESS
case|:
case|case
name|DXGI_FORMAT_BC7_UNORM
case|:
case|case
name|DXGI_FORMAT_BC7_UNORM_SRGB
case|:
return|return
name|ComputePixelSizeBits
argument_list|(
name|format
argument_list|)
operator|*
literal|16
return|;
default|default:
name|UNREACHABLE
argument_list|()
expr_stmt|;
return|return
literal|0
return|;
block|}
block|}
DECL|function|IsCompressed
name|bool
name|IsCompressed
parameter_list|(
name|DXGI_FORMAT
name|format
parameter_list|)
block|{
switch|switch
condition|(
name|format
condition|)
block|{
case|case
name|DXGI_FORMAT_BC1_TYPELESS
case|:
case|case
name|DXGI_FORMAT_BC1_UNORM
case|:
case|case
name|DXGI_FORMAT_BC1_UNORM_SRGB
case|:
case|case
name|DXGI_FORMAT_BC4_SNORM
case|:
case|case
name|DXGI_FORMAT_BC4_TYPELESS
case|:
case|case
name|DXGI_FORMAT_BC4_UNORM
case|:
case|case
name|DXGI_FORMAT_BC2_TYPELESS
case|:
case|case
name|DXGI_FORMAT_BC2_UNORM
case|:
case|case
name|DXGI_FORMAT_BC2_UNORM_SRGB
case|:
case|case
name|DXGI_FORMAT_BC3_TYPELESS
case|:
case|case
name|DXGI_FORMAT_BC3_UNORM
case|:
case|case
name|DXGI_FORMAT_BC3_UNORM_SRGB
case|:
case|case
name|DXGI_FORMAT_BC5_SNORM
case|:
case|case
name|DXGI_FORMAT_BC5_TYPELESS
case|:
case|case
name|DXGI_FORMAT_BC5_UNORM
case|:
case|case
name|DXGI_FORMAT_BC6H_SF16
case|:
case|case
name|DXGI_FORMAT_BC6H_TYPELESS
case|:
case|case
name|DXGI_FORMAT_BC6H_UF16
case|:
case|case
name|DXGI_FORMAT_BC7_TYPELESS
case|:
case|case
name|DXGI_FORMAT_BC7_UNORM
case|:
case|case
name|DXGI_FORMAT_BC7_UNORM_SRGB
case|:
return|return
literal|true
return|;
case|case
name|DXGI_FORMAT_UNKNOWN
case|:
name|UNREACHABLE
argument_list|()
expr_stmt|;
return|return
literal|false
return|;
default|default:
return|return
literal|false
return|;
block|}
block|}
DECL|function|GetTextureFormatDimensionAlignment
name|unsigned
name|int
name|GetTextureFormatDimensionAlignment
parameter_list|(
name|DXGI_FORMAT
name|format
parameter_list|)
block|{
switch|switch
condition|(
name|format
condition|)
block|{
case|case
name|DXGI_FORMAT_BC1_TYPELESS
case|:
case|case
name|DXGI_FORMAT_BC1_UNORM
case|:
case|case
name|DXGI_FORMAT_BC1_UNORM_SRGB
case|:
case|case
name|DXGI_FORMAT_BC4_SNORM
case|:
case|case
name|DXGI_FORMAT_BC4_TYPELESS
case|:
case|case
name|DXGI_FORMAT_BC4_UNORM
case|:
case|case
name|DXGI_FORMAT_BC2_TYPELESS
case|:
case|case
name|DXGI_FORMAT_BC2_UNORM
case|:
case|case
name|DXGI_FORMAT_BC2_UNORM_SRGB
case|:
case|case
name|DXGI_FORMAT_BC3_TYPELESS
case|:
case|case
name|DXGI_FORMAT_BC3_UNORM
case|:
case|case
name|DXGI_FORMAT_BC3_UNORM_SRGB
case|:
case|case
name|DXGI_FORMAT_BC5_SNORM
case|:
case|case
name|DXGI_FORMAT_BC5_TYPELESS
case|:
case|case
name|DXGI_FORMAT_BC5_UNORM
case|:
case|case
name|DXGI_FORMAT_BC6H_SF16
case|:
case|case
name|DXGI_FORMAT_BC6H_TYPELESS
case|:
case|case
name|DXGI_FORMAT_BC6H_UF16
case|:
case|case
name|DXGI_FORMAT_BC7_TYPELESS
case|:
case|case
name|DXGI_FORMAT_BC7_UNORM
case|:
case|case
name|DXGI_FORMAT_BC7_UNORM_SRGB
case|:
return|return
literal|4
return|;
case|case
name|DXGI_FORMAT_UNKNOWN
case|:
name|UNREACHABLE
argument_list|()
expr_stmt|;
return|return
literal|1
return|;
default|default:
return|return
literal|1
return|;
block|}
block|}
DECL|function|IsDepthStencilFormat
name|bool
name|IsDepthStencilFormat
parameter_list|(
name|DXGI_FORMAT
name|format
parameter_list|)
block|{
switch|switch
condition|(
name|format
condition|)
block|{
case|case
name|DXGI_FORMAT_D32_FLOAT_S8X24_UINT
case|:
case|case
name|DXGI_FORMAT_D32_FLOAT
case|:
case|case
name|DXGI_FORMAT_D24_UNORM_S8_UINT
case|:
case|case
name|DXGI_FORMAT_D16_UNORM
case|:
return|return
literal|true
return|;
default|default:
return|return
literal|false
return|;
block|}
block|}
DECL|function|GetDepthTextureFormat
name|DXGI_FORMAT
name|GetDepthTextureFormat
parameter_list|(
name|DXGI_FORMAT
name|format
parameter_list|)
block|{
switch|switch
condition|(
name|format
condition|)
block|{
case|case
name|DXGI_FORMAT_D32_FLOAT_S8X24_UINT
case|:
return|return
name|DXGI_FORMAT_R32G8X24_TYPELESS
return|;
case|case
name|DXGI_FORMAT_D32_FLOAT
case|:
return|return
name|DXGI_FORMAT_R32_TYPELESS
return|;
case|case
name|DXGI_FORMAT_D24_UNORM_S8_UINT
case|:
return|return
name|DXGI_FORMAT_R24G8_TYPELESS
return|;
case|case
name|DXGI_FORMAT_D16_UNORM
case|:
return|return
name|DXGI_FORMAT_R16_TYPELESS
return|;
default|default:
name|UNREACHABLE
argument_list|()
expr_stmt|;
return|return
name|DXGI_FORMAT_UNKNOWN
return|;
block|}
block|}
DECL|function|GetDepthShaderResourceFormat
name|DXGI_FORMAT
name|GetDepthShaderResourceFormat
parameter_list|(
name|DXGI_FORMAT
name|format
parameter_list|)
block|{
switch|switch
condition|(
name|format
condition|)
block|{
case|case
name|DXGI_FORMAT_D32_FLOAT_S8X24_UINT
case|:
return|return
name|DXGI_FORMAT_R32_FLOAT_X8X24_TYPELESS
return|;
case|case
name|DXGI_FORMAT_D32_FLOAT
case|:
return|return
name|DXGI_FORMAT_R32_UINT
return|;
case|case
name|DXGI_FORMAT_D24_UNORM_S8_UINT
case|:
return|return
name|DXGI_FORMAT_R24_UNORM_X8_TYPELESS
return|;
case|case
name|DXGI_FORMAT_D16_UNORM
case|:
return|return
name|DXGI_FORMAT_R16_UNORM
return|;
default|default:
name|UNREACHABLE
argument_list|()
expr_stmt|;
return|return
name|DXGI_FORMAT_UNKNOWN
return|;
block|}
block|}
DECL|function|SetDebugName
name|HRESULT
name|SetDebugName
parameter_list|(
name|ID3D11DeviceChild
modifier|*
name|resource
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|)
block|{
if|#
directive|if
name|defined
argument_list|(
name|_DEBUG
argument_list|)
return|return
name|resource
operator|->
name|SetPrivateData
argument_list|(
name|WKPDID_D3DDebugObjectName
argument_list|,
name|strlen
argument_list|(
name|name
argument_list|)
argument_list|,
name|name
argument_list|)
return|;
else|#
directive|else
return|return
name|S_OK
return|;
endif|#
directive|endif
block|}
block|}
end_namespace
end_unit