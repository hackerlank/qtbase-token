begin_unit
begin_comment
comment|//
end_comment
begin_comment
comment|// Copyright (c) 2002-2012 The ANGLE Project Authors. All rights reserved.
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
comment|// generatemip.h: Defines the GenerateMip function, templated on the format
end_comment
begin_comment
comment|// type of the image for which mip levels are being generated.
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|LIBGLESV2_RENDERER_GENERATEMIP_H_
end_ifndef
begin_define
DECL|macro|LIBGLESV2_RENDERER_GENERATEMIP_H_
define|#
directive|define
name|LIBGLESV2_RENDERER_GENERATEMIP_H_
end_define
begin_include
include|#
directive|include
file|"libGLESv2/mathutil.h"
end_include
begin_decl_stmt
name|namespace
name|rx
block|{
struct|struct
name|L8
block|{
name|unsigned
name|char
name|L
decl_stmt|;
specifier|static
name|void
name|average
parameter_list|(
name|L8
modifier|*
name|dst
parameter_list|,
specifier|const
name|L8
modifier|*
name|src1
parameter_list|,
specifier|const
name|L8
modifier|*
name|src2
parameter_list|)
block|{
name|dst
operator|->
name|L
operator|=
operator|(
operator|(
name|src1
operator|->
name|L
operator|^
name|src2
operator|->
name|L
operator|)
operator|>>
literal|1
operator|)
operator|+
operator|(
name|src1
operator|->
name|L
operator|&
name|src2
operator|->
name|L
operator|)
expr_stmt|;
block|}
block|}
struct|;
typedef|typedef
name|L8
name|R8
typedef|;
comment|// R8 type is functionally equivalent for mip purposes
typedef|typedef
name|L8
name|A8
typedef|;
comment|// A8 type is functionally equivalent for mip purposes
struct|struct
name|A8L8
block|{
name|unsigned
name|char
name|L
decl_stmt|;
name|unsigned
name|char
name|A
decl_stmt|;
specifier|static
name|void
name|average
parameter_list|(
name|A8L8
modifier|*
name|dst
parameter_list|,
specifier|const
name|A8L8
modifier|*
name|src1
parameter_list|,
specifier|const
name|A8L8
modifier|*
name|src2
parameter_list|)
block|{
operator|*
operator|(
name|unsigned
name|short
operator|*
operator|)
name|dst
operator|=
operator|(
operator|(
operator|(
operator|*
operator|(
name|unsigned
name|short
operator|*
operator|)
name|src1
operator|^
operator|*
operator|(
name|unsigned
name|short
operator|*
operator|)
name|src2
operator|)
operator|&
literal|0xFEFE
operator|)
operator|>>
literal|1
operator|)
operator|+
operator|(
operator|*
operator|(
name|unsigned
name|short
operator|*
operator|)
name|src1
operator|&
operator|*
operator|(
name|unsigned
name|short
operator|*
operator|)
name|src2
operator|)
expr_stmt|;
block|}
block|}
struct|;
typedef|typedef
name|A8L8
name|R8G8
typedef|;
comment|// R8G8 type is functionally equivalent for mip purposes
struct|struct
name|A8R8G8B8
block|{
name|unsigned
name|char
name|B
decl_stmt|;
name|unsigned
name|char
name|G
decl_stmt|;
name|unsigned
name|char
name|R
decl_stmt|;
name|unsigned
name|char
name|A
decl_stmt|;
specifier|static
name|void
name|average
parameter_list|(
name|A8R8G8B8
modifier|*
name|dst
parameter_list|,
specifier|const
name|A8R8G8B8
modifier|*
name|src1
parameter_list|,
specifier|const
name|A8R8G8B8
modifier|*
name|src2
parameter_list|)
block|{
operator|*
operator|(
name|unsigned
name|int
operator|*
operator|)
name|dst
operator|=
operator|(
operator|(
operator|(
operator|*
operator|(
name|unsigned
name|int
operator|*
operator|)
name|src1
operator|^
operator|*
operator|(
name|unsigned
name|int
operator|*
operator|)
name|src2
operator|)
operator|&
literal|0xFEFEFEFE
operator|)
operator|>>
literal|1
operator|)
operator|+
operator|(
operator|*
operator|(
name|unsigned
name|int
operator|*
operator|)
name|src1
operator|&
operator|*
operator|(
name|unsigned
name|int
operator|*
operator|)
name|src2
operator|)
expr_stmt|;
block|}
block|}
struct|;
typedef|typedef
name|A8R8G8B8
name|R8G8B8A8
typedef|;
comment|// R8G8B8A8 type is functionally equivalent for mip purposes
struct|struct
name|A16B16G16R16F
block|{
name|unsigned
name|short
name|R
decl_stmt|;
name|unsigned
name|short
name|G
decl_stmt|;
name|unsigned
name|short
name|B
decl_stmt|;
name|unsigned
name|short
name|A
decl_stmt|;
specifier|static
name|void
name|average
parameter_list|(
name|A16B16G16R16F
modifier|*
name|dst
parameter_list|,
specifier|const
name|A16B16G16R16F
modifier|*
name|src1
parameter_list|,
specifier|const
name|A16B16G16R16F
modifier|*
name|src2
parameter_list|)
block|{
name|dst
operator|->
name|R
operator|=
name|gl
operator|::
name|float32ToFloat16
argument_list|(
operator|(
name|gl
operator|::
name|float16ToFloat32
argument_list|(
name|src1
operator|->
name|R
argument_list|)
operator|+
name|gl
operator|::
name|float16ToFloat32
argument_list|(
name|src2
operator|->
name|R
argument_list|)
operator|)
operator|*
literal|0.5f
argument_list|)
expr_stmt|;
name|dst
operator|->
name|G
operator|=
name|gl
operator|::
name|float32ToFloat16
argument_list|(
operator|(
name|gl
operator|::
name|float16ToFloat32
argument_list|(
name|src1
operator|->
name|G
argument_list|)
operator|+
name|gl
operator|::
name|float16ToFloat32
argument_list|(
name|src2
operator|->
name|G
argument_list|)
operator|)
operator|*
literal|0.5f
argument_list|)
expr_stmt|;
name|dst
operator|->
name|B
operator|=
name|gl
operator|::
name|float32ToFloat16
argument_list|(
operator|(
name|gl
operator|::
name|float16ToFloat32
argument_list|(
name|src1
operator|->
name|B
argument_list|)
operator|+
name|gl
operator|::
name|float16ToFloat32
argument_list|(
name|src2
operator|->
name|B
argument_list|)
operator|)
operator|*
literal|0.5f
argument_list|)
expr_stmt|;
name|dst
operator|->
name|A
operator|=
name|gl
operator|::
name|float32ToFloat16
argument_list|(
operator|(
name|gl
operator|::
name|float16ToFloat32
argument_list|(
name|src1
operator|->
name|A
argument_list|)
operator|+
name|gl
operator|::
name|float16ToFloat32
argument_list|(
name|src2
operator|->
name|A
argument_list|)
operator|)
operator|*
literal|0.5f
argument_list|)
expr_stmt|;
block|}
block|}
struct|;
struct|struct
name|R16F
block|{
name|unsigned
name|short
name|R
decl_stmt|;
specifier|static
name|void
name|average
parameter_list|(
name|R16F
modifier|*
name|dst
parameter_list|,
specifier|const
name|R16F
modifier|*
name|src1
parameter_list|,
specifier|const
name|R16F
modifier|*
name|src2
parameter_list|)
block|{
name|dst
operator|->
name|R
operator|=
name|gl
operator|::
name|float32ToFloat16
argument_list|(
operator|(
name|gl
operator|::
name|float16ToFloat32
argument_list|(
name|src1
operator|->
name|R
argument_list|)
operator|+
name|gl
operator|::
name|float16ToFloat32
argument_list|(
name|src2
operator|->
name|R
argument_list|)
operator|)
operator|*
literal|0.5f
argument_list|)
expr_stmt|;
block|}
block|}
struct|;
struct|struct
name|R16G16F
block|{
name|unsigned
name|short
name|R
decl_stmt|;
name|unsigned
name|short
name|G
decl_stmt|;
specifier|static
name|void
name|average
parameter_list|(
name|R16G16F
modifier|*
name|dst
parameter_list|,
specifier|const
name|R16G16F
modifier|*
name|src1
parameter_list|,
specifier|const
name|R16G16F
modifier|*
name|src2
parameter_list|)
block|{
name|dst
operator|->
name|R
operator|=
name|gl
operator|::
name|float32ToFloat16
argument_list|(
operator|(
name|gl
operator|::
name|float16ToFloat32
argument_list|(
name|src1
operator|->
name|R
argument_list|)
operator|+
name|gl
operator|::
name|float16ToFloat32
argument_list|(
name|src2
operator|->
name|R
argument_list|)
operator|)
operator|*
literal|0.5f
argument_list|)
expr_stmt|;
name|dst
operator|->
name|G
operator|=
name|gl
operator|::
name|float32ToFloat16
argument_list|(
operator|(
name|gl
operator|::
name|float16ToFloat32
argument_list|(
name|src1
operator|->
name|G
argument_list|)
operator|+
name|gl
operator|::
name|float16ToFloat32
argument_list|(
name|src2
operator|->
name|G
argument_list|)
operator|)
operator|*
literal|0.5f
argument_list|)
expr_stmt|;
block|}
block|}
struct|;
struct|struct
name|A32B32G32R32F
block|{
name|float
name|R
decl_stmt|;
name|float
name|G
decl_stmt|;
name|float
name|B
decl_stmt|;
name|float
name|A
decl_stmt|;
specifier|static
name|void
name|average
parameter_list|(
name|A32B32G32R32F
modifier|*
name|dst
parameter_list|,
specifier|const
name|A32B32G32R32F
modifier|*
name|src1
parameter_list|,
specifier|const
name|A32B32G32R32F
modifier|*
name|src2
parameter_list|)
block|{
name|dst
operator|->
name|R
operator|=
operator|(
name|src1
operator|->
name|R
operator|+
name|src2
operator|->
name|R
operator|)
operator|*
literal|0.5f
expr_stmt|;
name|dst
operator|->
name|G
operator|=
operator|(
name|src1
operator|->
name|G
operator|+
name|src2
operator|->
name|G
operator|)
operator|*
literal|0.5f
expr_stmt|;
name|dst
operator|->
name|B
operator|=
operator|(
name|src1
operator|->
name|B
operator|+
name|src2
operator|->
name|B
operator|)
operator|*
literal|0.5f
expr_stmt|;
name|dst
operator|->
name|A
operator|=
operator|(
name|src1
operator|->
name|A
operator|+
name|src2
operator|->
name|A
operator|)
operator|*
literal|0.5f
expr_stmt|;
block|}
block|}
struct|;
struct|struct
name|R32F
block|{
name|float
name|R
decl_stmt|;
specifier|static
name|void
name|average
parameter_list|(
name|R32F
modifier|*
name|dst
parameter_list|,
specifier|const
name|R32F
modifier|*
name|src1
parameter_list|,
specifier|const
name|R32F
modifier|*
name|src2
parameter_list|)
block|{
name|dst
operator|->
name|R
operator|=
operator|(
name|src1
operator|->
name|R
operator|+
name|src2
operator|->
name|R
operator|)
operator|*
literal|0.5f
expr_stmt|;
block|}
block|}
struct|;
struct|struct
name|R32G32F
block|{
name|float
name|R
decl_stmt|;
name|float
name|G
decl_stmt|;
specifier|static
name|void
name|average
parameter_list|(
name|R32G32F
modifier|*
name|dst
parameter_list|,
specifier|const
name|R32G32F
modifier|*
name|src1
parameter_list|,
specifier|const
name|R32G32F
modifier|*
name|src2
parameter_list|)
block|{
name|dst
operator|->
name|R
operator|=
operator|(
name|src1
operator|->
name|R
operator|+
name|src2
operator|->
name|R
operator|)
operator|*
literal|0.5f
expr_stmt|;
name|dst
operator|->
name|G
operator|=
operator|(
name|src1
operator|->
name|G
operator|+
name|src2
operator|->
name|G
operator|)
operator|*
literal|0.5f
expr_stmt|;
block|}
block|}
struct|;
struct|struct
name|R32G32B32F
block|{
name|float
name|R
decl_stmt|;
name|float
name|G
decl_stmt|;
name|float
name|B
decl_stmt|;
specifier|static
name|void
name|average
parameter_list|(
name|R32G32B32F
modifier|*
name|dst
parameter_list|,
specifier|const
name|R32G32B32F
modifier|*
name|src1
parameter_list|,
specifier|const
name|R32G32B32F
modifier|*
name|src2
parameter_list|)
block|{
name|dst
operator|->
name|R
operator|=
operator|(
name|src1
operator|->
name|R
operator|+
name|src2
operator|->
name|R
operator|)
operator|*
literal|0.5f
expr_stmt|;
name|dst
operator|->
name|G
operator|=
operator|(
name|src1
operator|->
name|G
operator|+
name|src2
operator|->
name|G
operator|)
operator|*
literal|0.5f
expr_stmt|;
name|dst
operator|->
name|B
operator|=
operator|(
name|src1
operator|->
name|B
operator|+
name|src2
operator|->
name|B
operator|)
operator|*
literal|0.5f
expr_stmt|;
block|}
block|}
struct|;
name|template
operator|<
name|typename
name|T
operator|>
specifier|static
name|void
name|GenerateMip
argument_list|(
argument|unsigned int sourceWidth
argument_list|,
argument|unsigned int sourceHeight
argument_list|,
argument|const unsigned char *sourceData
argument_list|,
argument|int sourcePitch
argument_list|,
argument|unsigned char *destData
argument_list|,
argument|int destPitch
argument_list|)
block|{
name|unsigned
name|int
name|mipWidth
operator|=
name|std
operator|::
name|max
argument_list|(
literal|1U
argument_list|,
name|sourceWidth
operator|>>
literal|1
argument_list|)
block|;
name|unsigned
name|int
name|mipHeight
operator|=
name|std
operator|::
name|max
argument_list|(
literal|1U
argument_list|,
name|sourceHeight
operator|>>
literal|1
argument_list|)
block|;
if|if
condition|(
name|sourceHeight
operator|==
literal|1
condition|)
block|{
name|ASSERT
argument_list|(
name|sourceWidth
operator|!=
literal|1
argument_list|)
expr_stmt|;
specifier|const
name|T
modifier|*
name|src
init|=
operator|(
specifier|const
name|T
operator|*
operator|)
name|sourceData
decl_stmt|;
name|T
modifier|*
name|dst
init|=
operator|(
name|T
operator|*
operator|)
name|destData
decl_stmt|;
for|for
control|(
name|unsigned
name|int
name|x
init|=
literal|0
init|;
name|x
operator|<
name|mipWidth
condition|;
name|x
operator|++
control|)
block|{
name|T
operator|::
name|average
argument_list|(
operator|&
name|dst
index|[
name|x
index|]
argument_list|,
operator|&
name|src
index|[
name|x
operator|*
literal|2
index|]
argument_list|,
operator|&
name|src
index|[
name|x
operator|*
literal|2
operator|+
literal|1
index|]
argument_list|)
expr_stmt|;
block|}
block|}
elseif|else
if|if
condition|(
name|sourceWidth
operator|==
literal|1
condition|)
block|{
name|ASSERT
argument_list|(
name|sourceHeight
operator|!=
literal|1
argument_list|)
expr_stmt|;
for|for
control|(
name|unsigned
name|int
name|y
init|=
literal|0
init|;
name|y
operator|<
name|mipHeight
condition|;
name|y
operator|++
control|)
block|{
specifier|const
name|T
modifier|*
name|src0
init|=
operator|(
specifier|const
name|T
operator|*
operator|)
operator|(
name|sourceData
operator|+
name|y
operator|*
literal|2
operator|*
name|sourcePitch
operator|)
decl_stmt|;
specifier|const
name|T
modifier|*
name|src1
init|=
operator|(
specifier|const
name|T
operator|*
operator|)
operator|(
name|sourceData
operator|+
name|y
operator|*
literal|2
operator|*
name|sourcePitch
operator|+
name|sourcePitch
operator|)
decl_stmt|;
name|T
modifier|*
name|dst
init|=
operator|(
name|T
operator|*
operator|)
operator|(
name|destData
operator|+
name|y
operator|*
name|destPitch
operator|)
decl_stmt|;
name|T
operator|::
name|average
argument_list|(
name|dst
argument_list|,
name|src0
argument_list|,
name|src1
argument_list|)
expr_stmt|;
block|}
block|}
else|else
block|{
for|for
control|(
name|unsigned
name|int
name|y
init|=
literal|0
init|;
name|y
operator|<
name|mipHeight
condition|;
name|y
operator|++
control|)
block|{
specifier|const
name|T
modifier|*
name|src0
init|=
operator|(
specifier|const
name|T
operator|*
operator|)
operator|(
name|sourceData
operator|+
name|y
operator|*
literal|2
operator|*
name|sourcePitch
operator|)
decl_stmt|;
specifier|const
name|T
modifier|*
name|src1
init|=
operator|(
specifier|const
name|T
operator|*
operator|)
operator|(
name|sourceData
operator|+
name|y
operator|*
literal|2
operator|*
name|sourcePitch
operator|+
name|sourcePitch
operator|)
decl_stmt|;
name|T
modifier|*
name|dst
init|=
operator|(
name|T
operator|*
operator|)
operator|(
name|destData
operator|+
name|y
operator|*
name|destPitch
operator|)
decl_stmt|;
for|for
control|(
name|unsigned
name|int
name|x
init|=
literal|0
init|;
name|x
operator|<
name|mipWidth
condition|;
name|x
operator|++
control|)
block|{
name|T
name|tmp0
decl_stmt|;
name|T
name|tmp1
decl_stmt|;
name|T
operator|::
name|average
argument_list|(
operator|&
name|tmp0
argument_list|,
operator|&
name|src0
index|[
name|x
operator|*
literal|2
index|]
argument_list|,
operator|&
name|src0
index|[
name|x
operator|*
literal|2
operator|+
literal|1
index|]
argument_list|)
expr_stmt|;
name|T
operator|::
name|average
argument_list|(
operator|&
name|tmp1
argument_list|,
operator|&
name|src1
index|[
name|x
operator|*
literal|2
index|]
argument_list|,
operator|&
name|src1
index|[
name|x
operator|*
literal|2
operator|+
literal|1
index|]
argument_list|)
expr_stmt|;
name|T
operator|::
name|average
argument_list|(
operator|&
name|dst
index|[
name|x
index|]
argument_list|,
operator|&
name|tmp0
argument_list|,
operator|&
name|tmp1
argument_list|)
expr_stmt|;
block|}
block|}
block|}
block|}
block|}
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// LIBGLESV2_RENDERER_GENERATEMIP_H_
end_comment
end_unit
