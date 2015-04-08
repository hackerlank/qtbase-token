begin_unit
begin_comment
comment|//
end_comment
begin_comment
comment|// Copyright (c) 2002-2013 The ANGLE Project Authors. All rights reserved.
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
comment|// utilities.cpp: Conversion functions and other utility routines.
end_comment
begin_include
include|#
directive|include
file|"common/utilities.h"
end_include
begin_include
include|#
directive|include
file|"common/mathutil.h"
end_include
begin_include
include|#
directive|include
file|"common/platform.h"
end_include
begin_include
include|#
directive|include
file|<set>
end_include
begin_if
if|#
directive|if
name|defined
argument_list|(
name|ANGLE_ENABLE_WINDOWS_STORE
argument_list|)
end_if
begin_include
include|#
directive|include
file|<wrl.h>
end_include
begin_include
include|#
directive|include
file|<wrl/wrappers/corewrappers.h>
end_include
begin_include
include|#
directive|include
file|<windows.applicationmodel.core.h>
end_include
begin_include
include|#
directive|include
file|<windows.graphics.display.h>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_namespace
DECL|namespace|gl
namespace|namespace
name|gl
block|{
DECL|function|VariableComponentCount
name|int
name|VariableComponentCount
parameter_list|(
name|GLenum
name|type
parameter_list|)
block|{
return|return
name|VariableRowCount
argument_list|(
name|type
argument_list|)
operator|*
name|VariableColumnCount
argument_list|(
name|type
argument_list|)
return|;
block|}
DECL|function|VariableComponentType
name|GLenum
name|VariableComponentType
parameter_list|(
name|GLenum
name|type
parameter_list|)
block|{
switch|switch
condition|(
name|type
condition|)
block|{
case|case
name|GL_BOOL
case|:
case|case
name|GL_BOOL_VEC2
case|:
case|case
name|GL_BOOL_VEC3
case|:
case|case
name|GL_BOOL_VEC4
case|:
return|return
name|GL_BOOL
return|;
case|case
name|GL_FLOAT
case|:
case|case
name|GL_FLOAT_VEC2
case|:
case|case
name|GL_FLOAT_VEC3
case|:
case|case
name|GL_FLOAT_VEC4
case|:
case|case
name|GL_FLOAT_MAT2
case|:
case|case
name|GL_FLOAT_MAT3
case|:
case|case
name|GL_FLOAT_MAT4
case|:
case|case
name|GL_FLOAT_MAT2x3
case|:
case|case
name|GL_FLOAT_MAT3x2
case|:
case|case
name|GL_FLOAT_MAT2x4
case|:
case|case
name|GL_FLOAT_MAT4x2
case|:
case|case
name|GL_FLOAT_MAT3x4
case|:
case|case
name|GL_FLOAT_MAT4x3
case|:
return|return
name|GL_FLOAT
return|;
case|case
name|GL_INT
case|:
case|case
name|GL_SAMPLER_2D
case|:
case|case
name|GL_SAMPLER_3D
case|:
case|case
name|GL_SAMPLER_CUBE
case|:
case|case
name|GL_SAMPLER_2D_ARRAY
case|:
case|case
name|GL_INT_SAMPLER_2D
case|:
case|case
name|GL_INT_SAMPLER_3D
case|:
case|case
name|GL_INT_SAMPLER_CUBE
case|:
case|case
name|GL_INT_SAMPLER_2D_ARRAY
case|:
case|case
name|GL_UNSIGNED_INT_SAMPLER_2D
case|:
case|case
name|GL_UNSIGNED_INT_SAMPLER_3D
case|:
case|case
name|GL_UNSIGNED_INT_SAMPLER_CUBE
case|:
case|case
name|GL_UNSIGNED_INT_SAMPLER_2D_ARRAY
case|:
case|case
name|GL_SAMPLER_2D_SHADOW
case|:
case|case
name|GL_SAMPLER_CUBE_SHADOW
case|:
case|case
name|GL_SAMPLER_2D_ARRAY_SHADOW
case|:
case|case
name|GL_INT_VEC2
case|:
case|case
name|GL_INT_VEC3
case|:
case|case
name|GL_INT_VEC4
case|:
return|return
name|GL_INT
return|;
case|case
name|GL_UNSIGNED_INT
case|:
case|case
name|GL_UNSIGNED_INT_VEC2
case|:
case|case
name|GL_UNSIGNED_INT_VEC3
case|:
case|case
name|GL_UNSIGNED_INT_VEC4
case|:
return|return
name|GL_UNSIGNED_INT
return|;
default|default:
name|UNREACHABLE
argument_list|()
expr_stmt|;
block|}
return|return
name|GL_NONE
return|;
block|}
DECL|function|VariableComponentSize
name|size_t
name|VariableComponentSize
parameter_list|(
name|GLenum
name|type
parameter_list|)
block|{
switch|switch
condition|(
name|type
condition|)
block|{
case|case
name|GL_BOOL
case|:
return|return
sizeof|sizeof
argument_list|(
name|GLint
argument_list|)
return|;
case|case
name|GL_FLOAT
case|:
return|return
sizeof|sizeof
argument_list|(
name|GLfloat
argument_list|)
return|;
case|case
name|GL_INT
case|:
return|return
sizeof|sizeof
argument_list|(
name|GLint
argument_list|)
return|;
case|case
name|GL_UNSIGNED_INT
case|:
return|return
sizeof|sizeof
argument_list|(
name|GLuint
argument_list|)
return|;
default|default:
name|UNREACHABLE
argument_list|()
expr_stmt|;
block|}
return|return
literal|0
return|;
block|}
DECL|function|VariableInternalSize
name|size_t
name|VariableInternalSize
parameter_list|(
name|GLenum
name|type
parameter_list|)
block|{
comment|// Expanded to 4-element vectors
return|return
name|VariableComponentSize
argument_list|(
name|VariableComponentType
argument_list|(
name|type
argument_list|)
argument_list|)
operator|*
name|VariableRowCount
argument_list|(
name|type
argument_list|)
operator|*
literal|4
return|;
block|}
DECL|function|VariableExternalSize
name|size_t
name|VariableExternalSize
parameter_list|(
name|GLenum
name|type
parameter_list|)
block|{
return|return
name|VariableComponentSize
argument_list|(
name|VariableComponentType
argument_list|(
name|type
argument_list|)
argument_list|)
operator|*
name|VariableComponentCount
argument_list|(
name|type
argument_list|)
return|;
block|}
DECL|function|VariableBoolVectorType
name|GLenum
name|VariableBoolVectorType
parameter_list|(
name|GLenum
name|type
parameter_list|)
block|{
switch|switch
condition|(
name|type
condition|)
block|{
case|case
name|GL_FLOAT
case|:
case|case
name|GL_INT
case|:
case|case
name|GL_UNSIGNED_INT
case|:
return|return
name|GL_BOOL
return|;
case|case
name|GL_FLOAT_VEC2
case|:
case|case
name|GL_INT_VEC2
case|:
case|case
name|GL_UNSIGNED_INT_VEC2
case|:
return|return
name|GL_BOOL_VEC2
return|;
case|case
name|GL_FLOAT_VEC3
case|:
case|case
name|GL_INT_VEC3
case|:
case|case
name|GL_UNSIGNED_INT_VEC3
case|:
return|return
name|GL_BOOL_VEC3
return|;
case|case
name|GL_FLOAT_VEC4
case|:
case|case
name|GL_INT_VEC4
case|:
case|case
name|GL_UNSIGNED_INT_VEC4
case|:
return|return
name|GL_BOOL_VEC4
return|;
default|default:
name|UNREACHABLE
argument_list|()
expr_stmt|;
return|return
name|GL_NONE
return|;
block|}
block|}
DECL|function|VariableRowCount
name|int
name|VariableRowCount
parameter_list|(
name|GLenum
name|type
parameter_list|)
block|{
switch|switch
condition|(
name|type
condition|)
block|{
case|case
name|GL_NONE
case|:
case|case
name|GL_STRUCT_ANGLEX
case|:
return|return
literal|0
return|;
case|case
name|GL_BOOL
case|:
case|case
name|GL_FLOAT
case|:
case|case
name|GL_INT
case|:
case|case
name|GL_UNSIGNED_INT
case|:
case|case
name|GL_BOOL_VEC2
case|:
case|case
name|GL_FLOAT_VEC2
case|:
case|case
name|GL_INT_VEC2
case|:
case|case
name|GL_UNSIGNED_INT_VEC2
case|:
case|case
name|GL_BOOL_VEC3
case|:
case|case
name|GL_FLOAT_VEC3
case|:
case|case
name|GL_INT_VEC3
case|:
case|case
name|GL_UNSIGNED_INT_VEC3
case|:
case|case
name|GL_BOOL_VEC4
case|:
case|case
name|GL_FLOAT_VEC4
case|:
case|case
name|GL_INT_VEC4
case|:
case|case
name|GL_UNSIGNED_INT_VEC4
case|:
case|case
name|GL_SAMPLER_2D
case|:
case|case
name|GL_SAMPLER_3D
case|:
case|case
name|GL_SAMPLER_CUBE
case|:
case|case
name|GL_SAMPLER_2D_ARRAY
case|:
case|case
name|GL_SAMPLER_EXTERNAL_OES
case|:
case|case
name|GL_SAMPLER_2D_RECT_ARB
case|:
case|case
name|GL_INT_SAMPLER_2D
case|:
case|case
name|GL_INT_SAMPLER_3D
case|:
case|case
name|GL_INT_SAMPLER_CUBE
case|:
case|case
name|GL_INT_SAMPLER_2D_ARRAY
case|:
case|case
name|GL_UNSIGNED_INT_SAMPLER_2D
case|:
case|case
name|GL_UNSIGNED_INT_SAMPLER_3D
case|:
case|case
name|GL_UNSIGNED_INT_SAMPLER_CUBE
case|:
case|case
name|GL_UNSIGNED_INT_SAMPLER_2D_ARRAY
case|:
case|case
name|GL_SAMPLER_2D_SHADOW
case|:
case|case
name|GL_SAMPLER_CUBE_SHADOW
case|:
case|case
name|GL_SAMPLER_2D_ARRAY_SHADOW
case|:
return|return
literal|1
return|;
case|case
name|GL_FLOAT_MAT2
case|:
case|case
name|GL_FLOAT_MAT3x2
case|:
case|case
name|GL_FLOAT_MAT4x2
case|:
return|return
literal|2
return|;
case|case
name|GL_FLOAT_MAT3
case|:
case|case
name|GL_FLOAT_MAT2x3
case|:
case|case
name|GL_FLOAT_MAT4x3
case|:
return|return
literal|3
return|;
case|case
name|GL_FLOAT_MAT4
case|:
case|case
name|GL_FLOAT_MAT2x4
case|:
case|case
name|GL_FLOAT_MAT3x4
case|:
return|return
literal|4
return|;
default|default:
name|UNREACHABLE
argument_list|()
expr_stmt|;
block|}
return|return
literal|0
return|;
block|}
DECL|function|VariableColumnCount
name|int
name|VariableColumnCount
parameter_list|(
name|GLenum
name|type
parameter_list|)
block|{
switch|switch
condition|(
name|type
condition|)
block|{
case|case
name|GL_NONE
case|:
case|case
name|GL_STRUCT_ANGLEX
case|:
return|return
literal|0
return|;
case|case
name|GL_BOOL
case|:
case|case
name|GL_FLOAT
case|:
case|case
name|GL_INT
case|:
case|case
name|GL_UNSIGNED_INT
case|:
case|case
name|GL_SAMPLER_2D
case|:
case|case
name|GL_SAMPLER_3D
case|:
case|case
name|GL_SAMPLER_CUBE
case|:
case|case
name|GL_SAMPLER_2D_ARRAY
case|:
case|case
name|GL_INT_SAMPLER_2D
case|:
case|case
name|GL_INT_SAMPLER_3D
case|:
case|case
name|GL_INT_SAMPLER_CUBE
case|:
case|case
name|GL_INT_SAMPLER_2D_ARRAY
case|:
case|case
name|GL_SAMPLER_EXTERNAL_OES
case|:
case|case
name|GL_SAMPLER_2D_RECT_ARB
case|:
case|case
name|GL_UNSIGNED_INT_SAMPLER_2D
case|:
case|case
name|GL_UNSIGNED_INT_SAMPLER_3D
case|:
case|case
name|GL_UNSIGNED_INT_SAMPLER_CUBE
case|:
case|case
name|GL_UNSIGNED_INT_SAMPLER_2D_ARRAY
case|:
case|case
name|GL_SAMPLER_2D_SHADOW
case|:
case|case
name|GL_SAMPLER_CUBE_SHADOW
case|:
case|case
name|GL_SAMPLER_2D_ARRAY_SHADOW
case|:
return|return
literal|1
return|;
case|case
name|GL_BOOL_VEC2
case|:
case|case
name|GL_FLOAT_VEC2
case|:
case|case
name|GL_INT_VEC2
case|:
case|case
name|GL_UNSIGNED_INT_VEC2
case|:
case|case
name|GL_FLOAT_MAT2
case|:
case|case
name|GL_FLOAT_MAT2x3
case|:
case|case
name|GL_FLOAT_MAT2x4
case|:
return|return
literal|2
return|;
case|case
name|GL_BOOL_VEC3
case|:
case|case
name|GL_FLOAT_VEC3
case|:
case|case
name|GL_INT_VEC3
case|:
case|case
name|GL_UNSIGNED_INT_VEC3
case|:
case|case
name|GL_FLOAT_MAT3
case|:
case|case
name|GL_FLOAT_MAT3x2
case|:
case|case
name|GL_FLOAT_MAT3x4
case|:
return|return
literal|3
return|;
case|case
name|GL_BOOL_VEC4
case|:
case|case
name|GL_FLOAT_VEC4
case|:
case|case
name|GL_INT_VEC4
case|:
case|case
name|GL_UNSIGNED_INT_VEC4
case|:
case|case
name|GL_FLOAT_MAT4
case|:
case|case
name|GL_FLOAT_MAT4x2
case|:
case|case
name|GL_FLOAT_MAT4x3
case|:
return|return
literal|4
return|;
default|default:
name|UNREACHABLE
argument_list|()
expr_stmt|;
block|}
return|return
literal|0
return|;
block|}
DECL|function|IsSamplerType
name|bool
name|IsSamplerType
parameter_list|(
name|GLenum
name|type
parameter_list|)
block|{
switch|switch
condition|(
name|type
condition|)
block|{
case|case
name|GL_SAMPLER_2D
case|:
case|case
name|GL_SAMPLER_3D
case|:
case|case
name|GL_SAMPLER_CUBE
case|:
case|case
name|GL_SAMPLER_2D_ARRAY
case|:
case|case
name|GL_INT_SAMPLER_2D
case|:
case|case
name|GL_INT_SAMPLER_3D
case|:
case|case
name|GL_INT_SAMPLER_CUBE
case|:
case|case
name|GL_INT_SAMPLER_2D_ARRAY
case|:
case|case
name|GL_UNSIGNED_INT_SAMPLER_2D
case|:
case|case
name|GL_UNSIGNED_INT_SAMPLER_3D
case|:
case|case
name|GL_UNSIGNED_INT_SAMPLER_CUBE
case|:
case|case
name|GL_UNSIGNED_INT_SAMPLER_2D_ARRAY
case|:
case|case
name|GL_SAMPLER_2D_SHADOW
case|:
case|case
name|GL_SAMPLER_CUBE_SHADOW
case|:
case|case
name|GL_SAMPLER_2D_ARRAY_SHADOW
case|:
return|return
literal|true
return|;
block|}
return|return
literal|false
return|;
block|}
DECL|function|IsMatrixType
name|bool
name|IsMatrixType
parameter_list|(
name|GLenum
name|type
parameter_list|)
block|{
return|return
name|VariableRowCount
argument_list|(
name|type
argument_list|)
operator|>
literal|1
return|;
block|}
DECL|function|TransposeMatrixType
name|GLenum
name|TransposeMatrixType
parameter_list|(
name|GLenum
name|type
parameter_list|)
block|{
if|if
condition|(
operator|!
name|IsMatrixType
argument_list|(
name|type
argument_list|)
condition|)
block|{
return|return
name|type
return|;
block|}
switch|switch
condition|(
name|type
condition|)
block|{
case|case
name|GL_FLOAT_MAT2
case|:
return|return
name|GL_FLOAT_MAT2
return|;
case|case
name|GL_FLOAT_MAT3
case|:
return|return
name|GL_FLOAT_MAT3
return|;
case|case
name|GL_FLOAT_MAT4
case|:
return|return
name|GL_FLOAT_MAT4
return|;
case|case
name|GL_FLOAT_MAT2x3
case|:
return|return
name|GL_FLOAT_MAT3x2
return|;
case|case
name|GL_FLOAT_MAT3x2
case|:
return|return
name|GL_FLOAT_MAT2x3
return|;
case|case
name|GL_FLOAT_MAT2x4
case|:
return|return
name|GL_FLOAT_MAT4x2
return|;
case|case
name|GL_FLOAT_MAT4x2
case|:
return|return
name|GL_FLOAT_MAT2x4
return|;
case|case
name|GL_FLOAT_MAT3x4
case|:
return|return
name|GL_FLOAT_MAT4x3
return|;
case|case
name|GL_FLOAT_MAT4x3
case|:
return|return
name|GL_FLOAT_MAT3x4
return|;
default|default:
name|UNREACHABLE
argument_list|()
expr_stmt|;
return|return
name|GL_NONE
return|;
block|}
block|}
DECL|function|MatrixRegisterCount
name|int
name|MatrixRegisterCount
parameter_list|(
name|GLenum
name|type
parameter_list|,
name|bool
name|isRowMajorMatrix
parameter_list|)
block|{
name|ASSERT
argument_list|(
name|IsMatrixType
argument_list|(
name|type
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|isRowMajorMatrix
condition|?
name|VariableRowCount
argument_list|(
name|type
argument_list|)
else|:
name|VariableColumnCount
argument_list|(
name|type
argument_list|)
return|;
block|}
DECL|function|MatrixComponentCount
name|int
name|MatrixComponentCount
parameter_list|(
name|GLenum
name|type
parameter_list|,
name|bool
name|isRowMajorMatrix
parameter_list|)
block|{
name|ASSERT
argument_list|(
name|IsMatrixType
argument_list|(
name|type
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|isRowMajorMatrix
condition|?
name|VariableColumnCount
argument_list|(
name|type
argument_list|)
else|:
name|VariableRowCount
argument_list|(
name|type
argument_list|)
return|;
block|}
DECL|function|VariableRegisterCount
name|int
name|VariableRegisterCount
parameter_list|(
name|GLenum
name|type
parameter_list|)
block|{
return|return
name|IsMatrixType
argument_list|(
name|type
argument_list|)
condition|?
name|VariableColumnCount
argument_list|(
name|type
argument_list|)
else|:
literal|1
return|;
block|}
DECL|function|AllocateFirstFreeBits
name|int
name|AllocateFirstFreeBits
parameter_list|(
name|unsigned
name|int
modifier|*
name|bits
parameter_list|,
name|unsigned
name|int
name|allocationSize
parameter_list|,
name|unsigned
name|int
name|bitsSize
parameter_list|)
block|{
name|ASSERT
argument_list|(
name|allocationSize
operator|<=
name|bitsSize
argument_list|)
expr_stmt|;
name|unsigned
name|int
name|mask
init|=
name|std
operator|::
name|numeric_limits
argument_list|<
name|unsigned
name|int
argument_list|>
operator|::
name|max
argument_list|()
operator|>>
operator|(
name|std
operator|::
name|numeric_limits
argument_list|<
name|unsigned
name|int
argument_list|>
operator|::
name|digits
operator|-
name|allocationSize
operator|)
decl_stmt|;
for|for
control|(
name|unsigned
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|bitsSize
operator|-
name|allocationSize
operator|+
literal|1
condition|;
name|i
operator|++
control|)
block|{
if|if
condition|(
operator|(
operator|*
name|bits
operator|&
name|mask
operator|)
operator|==
literal|0
condition|)
block|{
operator|*
name|bits
operator||=
name|mask
expr_stmt|;
return|return
name|i
return|;
block|}
name|mask
operator|<<=
literal|1
expr_stmt|;
block|}
return|return
operator|-
literal|1
return|;
block|}
assert|static_assert
argument_list|(
name|GL_TEXTURE_CUBE_MAP_NEGATIVE_X
operator|-
name|GL_TEXTURE_CUBE_MAP_POSITIVE_X
operator|==
literal|1
argument_list|,
literal|"Unexpected GL cube map enum value."
argument_list|)
assert|;
assert|static_assert
argument_list|(
name|GL_TEXTURE_CUBE_MAP_POSITIVE_Y
operator|-
name|GL_TEXTURE_CUBE_MAP_POSITIVE_X
operator|==
literal|2
argument_list|,
literal|"Unexpected GL cube map enum value."
argument_list|)
assert|;
assert|static_assert
argument_list|(
name|GL_TEXTURE_CUBE_MAP_NEGATIVE_Y
operator|-
name|GL_TEXTURE_CUBE_MAP_POSITIVE_X
operator|==
literal|3
argument_list|,
literal|"Unexpected GL cube map enum value."
argument_list|)
assert|;
assert|static_assert
argument_list|(
name|GL_TEXTURE_CUBE_MAP_POSITIVE_Z
operator|-
name|GL_TEXTURE_CUBE_MAP_POSITIVE_X
operator|==
literal|4
argument_list|,
literal|"Unexpected GL cube map enum value."
argument_list|)
assert|;
assert|static_assert
argument_list|(
name|GL_TEXTURE_CUBE_MAP_NEGATIVE_Z
operator|-
name|GL_TEXTURE_CUBE_MAP_POSITIVE_X
operator|==
literal|5
argument_list|,
literal|"Unexpected GL cube map enum value."
argument_list|)
assert|;
DECL|function|IsCubeMapTextureTarget
name|bool
name|IsCubeMapTextureTarget
parameter_list|(
name|GLenum
name|target
parameter_list|)
block|{
return|return
operator|(
name|target
operator|>=
name|FirstCubeMapTextureTarget
operator|&&
name|target
operator|<=
name|LastCubeMapTextureTarget
operator|)
return|;
block|}
DECL|function|CubeMapTextureTargetToLayerIndex
name|size_t
name|CubeMapTextureTargetToLayerIndex
parameter_list|(
name|GLenum
name|target
parameter_list|)
block|{
name|ASSERT
argument_list|(
name|IsCubeMapTextureTarget
argument_list|(
name|target
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|target
operator|-
cast|static_cast
argument_list|<
name|size_t
argument_list|>
argument_list|(
name|FirstCubeMapTextureTarget
argument_list|)
return|;
block|}
DECL|function|LayerIndexToCubeMapTextureTarget
name|GLenum
name|LayerIndexToCubeMapTextureTarget
parameter_list|(
name|size_t
name|index
parameter_list|)
block|{
name|ASSERT
argument_list|(
name|index
operator|<=
operator|(
name|LastCubeMapTextureTarget
operator|-
name|FirstCubeMapTextureTarget
operator|)
argument_list|)
expr_stmt|;
return|return
name|FirstCubeMapTextureTarget
operator|+
cast|static_cast
argument_list|<
name|GLenum
argument_list|>
argument_list|(
name|index
argument_list|)
return|;
block|}
DECL|function|IsTriangleMode
name|bool
name|IsTriangleMode
parameter_list|(
name|GLenum
name|drawMode
parameter_list|)
block|{
switch|switch
condition|(
name|drawMode
condition|)
block|{
case|case
name|GL_TRIANGLES
case|:
case|case
name|GL_TRIANGLE_FAN
case|:
case|case
name|GL_TRIANGLE_STRIP
case|:
return|return
literal|true
return|;
case|case
name|GL_POINTS
case|:
case|case
name|GL_LINES
case|:
case|case
name|GL_LINE_LOOP
case|:
case|case
name|GL_LINE_STRIP
case|:
return|return
literal|false
return|;
default|default:
name|UNREACHABLE
argument_list|()
expr_stmt|;
block|}
return|return
literal|false
return|;
block|}
comment|// [OpenGL ES SL 3.00.4] Section 11 p. 120
comment|// Vertex Outs/Fragment Ins packing priorities
DECL|function|VariableSortOrder
name|int
name|VariableSortOrder
parameter_list|(
name|GLenum
name|type
parameter_list|)
block|{
switch|switch
condition|(
name|type
condition|)
block|{
comment|// 1. Arrays of mat4 and mat4
comment|// Non-square matrices of type matCxR consume the same space as a square
comment|// matrix of type matN where N is the greater of C and R
case|case
name|GL_FLOAT_MAT4
case|:
case|case
name|GL_FLOAT_MAT2x4
case|:
case|case
name|GL_FLOAT_MAT3x4
case|:
case|case
name|GL_FLOAT_MAT4x2
case|:
case|case
name|GL_FLOAT_MAT4x3
case|:
return|return
literal|0
return|;
comment|// 2. Arrays of mat2 and mat2 (since they occupy full rows)
case|case
name|GL_FLOAT_MAT2
case|:
return|return
literal|1
return|;
comment|// 3. Arrays of vec4 and vec4
case|case
name|GL_FLOAT_VEC4
case|:
case|case
name|GL_INT_VEC4
case|:
case|case
name|GL_BOOL_VEC4
case|:
case|case
name|GL_UNSIGNED_INT_VEC4
case|:
return|return
literal|2
return|;
comment|// 4. Arrays of mat3 and mat3
case|case
name|GL_FLOAT_MAT3
case|:
case|case
name|GL_FLOAT_MAT2x3
case|:
case|case
name|GL_FLOAT_MAT3x2
case|:
return|return
literal|3
return|;
comment|// 5. Arrays of vec3 and vec3
case|case
name|GL_FLOAT_VEC3
case|:
case|case
name|GL_INT_VEC3
case|:
case|case
name|GL_BOOL_VEC3
case|:
case|case
name|GL_UNSIGNED_INT_VEC3
case|:
return|return
literal|4
return|;
comment|// 6. Arrays of vec2 and vec2
case|case
name|GL_FLOAT_VEC2
case|:
case|case
name|GL_INT_VEC2
case|:
case|case
name|GL_BOOL_VEC2
case|:
case|case
name|GL_UNSIGNED_INT_VEC2
case|:
return|return
literal|5
return|;
comment|// 7. Single component types
case|case
name|GL_FLOAT
case|:
case|case
name|GL_INT
case|:
case|case
name|GL_BOOL
case|:
case|case
name|GL_UNSIGNED_INT
case|:
case|case
name|GL_SAMPLER_2D
case|:
case|case
name|GL_SAMPLER_CUBE
case|:
case|case
name|GL_SAMPLER_EXTERNAL_OES
case|:
case|case
name|GL_SAMPLER_2D_RECT_ARB
case|:
case|case
name|GL_SAMPLER_2D_ARRAY
case|:
case|case
name|GL_SAMPLER_3D
case|:
case|case
name|GL_INT_SAMPLER_2D
case|:
case|case
name|GL_INT_SAMPLER_3D
case|:
case|case
name|GL_INT_SAMPLER_CUBE
case|:
case|case
name|GL_INT_SAMPLER_2D_ARRAY
case|:
case|case
name|GL_UNSIGNED_INT_SAMPLER_2D
case|:
case|case
name|GL_UNSIGNED_INT_SAMPLER_3D
case|:
case|case
name|GL_UNSIGNED_INT_SAMPLER_CUBE
case|:
case|case
name|GL_UNSIGNED_INT_SAMPLER_2D_ARRAY
case|:
case|case
name|GL_SAMPLER_2D_SHADOW
case|:
case|case
name|GL_SAMPLER_2D_ARRAY_SHADOW
case|:
case|case
name|GL_SAMPLER_CUBE_SHADOW
case|:
return|return
literal|6
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
block|}
end_namespace
begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|ANGLE_ENABLE_WINDOWS_STORE
argument_list|)
end_if
begin_function
DECL|function|getTempPath
name|std
operator|::
name|string
name|getTempPath
parameter_list|()
block|{
ifdef|#
directive|ifdef
name|ANGLE_PLATFORM_WINDOWS
name|char
name|path
index|[
name|MAX_PATH
index|]
decl_stmt|;
name|DWORD
name|pathLen
init|=
name|GetTempPathA
argument_list|(
sizeof|sizeof
argument_list|(
name|path
argument_list|)
operator|/
sizeof|sizeof
argument_list|(
name|path
index|[
literal|0
index|]
argument_list|)
argument_list|,
name|path
argument_list|)
decl_stmt|;
if|if
condition|(
name|pathLen
operator|==
literal|0
condition|)
block|{
name|UNREACHABLE
argument_list|()
expr_stmt|;
return|return
name|std
operator|::
name|string
argument_list|()
return|;
block|}
name|UINT
name|unique
init|=
name|GetTempFileNameA
argument_list|(
name|path
argument_list|,
literal|"sh"
argument_list|,
literal|0
argument_list|,
name|path
argument_list|)
decl_stmt|;
if|if
condition|(
name|unique
operator|==
literal|0
condition|)
block|{
name|UNREACHABLE
argument_list|()
expr_stmt|;
return|return
name|std
operator|::
name|string
argument_list|()
return|;
block|}
return|return
name|path
return|;
else|#
directive|else
name|UNIMPLEMENTED
argument_list|()
expr_stmt|;
return|return
literal|""
return|;
endif|#
directive|endif
block|}
end_function
begin_function
DECL|function|writeFile
name|void
name|writeFile
parameter_list|(
specifier|const
name|char
modifier|*
name|path
parameter_list|,
specifier|const
name|void
modifier|*
name|content
parameter_list|,
name|size_t
name|size
parameter_list|)
block|{
name|FILE
modifier|*
name|file
init|=
name|fopen
argument_list|(
name|path
argument_list|,
literal|"w"
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|file
condition|)
block|{
name|UNREACHABLE
argument_list|()
expr_stmt|;
return|return;
block|}
name|fwrite
argument_list|(
name|content
argument_list|,
sizeof|sizeof
argument_list|(
name|char
argument_list|)
argument_list|,
name|size
argument_list|,
name|file
argument_list|)
expr_stmt|;
name|fclose
argument_list|(
name|file
argument_list|)
expr_stmt|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// !ANGLE_ENABLE_WINDOWS_STORE
end_comment
begin_if
if|#
directive|if
name|defined
argument_list|(
name|ANGLE_PLATFORM_WINDOWS
argument_list|)
end_if
begin_comment
comment|// Causes the thread to relinquish the remainder of its time slice to any
end_comment
begin_comment
comment|// other thread that is ready to run.If there are no other threads ready
end_comment
begin_comment
comment|// to run, the function returns immediately, and the thread continues execution.
end_comment
begin_function
DECL|function|ScheduleYield
name|void
name|ScheduleYield
parameter_list|()
block|{
if|#
directive|if
name|defined
argument_list|(
name|ANGLE_ENABLE_WINDOWS_STORE
argument_list|)
comment|// This implementation of Sleep exists because it is not available prior to Update 4.
specifier|static
name|HANDLE
name|singletonEvent
init|=
literal|nullptr
decl_stmt|;
name|HANDLE
name|sleepEvent
init|=
name|singletonEvent
decl_stmt|;
if|if
condition|(
operator|!
name|sleepEvent
condition|)
block|{
name|sleepEvent
operator|=
name|CreateEventEx
argument_list|(
literal|nullptr
argument_list|,
literal|nullptr
argument_list|,
name|CREATE_EVENT_MANUAL_RESET
argument_list|,
name|EVENT_ALL_ACCESS
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|sleepEvent
condition|)
return|return;
name|HANDLE
name|previousEvent
init|=
name|InterlockedCompareExchangePointerRelease
argument_list|(
operator|&
name|singletonEvent
argument_list|,
name|sleepEvent
argument_list|,
literal|nullptr
argument_list|)
decl_stmt|;
if|if
condition|(
name|previousEvent
condition|)
block|{
comment|// Back out if multiple threads try to demand create at the same time.
name|CloseHandle
argument_list|(
name|sleepEvent
argument_list|)
expr_stmt|;
name|sleepEvent
operator|=
name|previousEvent
expr_stmt|;
block|}
block|}
comment|// Emulate sleep by waiting with timeout on an event that is never signalled.
name|WaitForSingleObjectEx
argument_list|(
name|sleepEvent
argument_list|,
literal|0
argument_list|,
literal|false
argument_list|)
expr_stmt|;
else|#
directive|else
name|Sleep
argument_list|(
literal|0
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
end_unit
