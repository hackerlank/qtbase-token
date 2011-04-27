begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the demonstration applications of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** No Commercial Usage ** This file contains pre-release code and may not be distributed. ** You may use this file in accordance with the terms and conditions ** contained in the Technology Preview License Agreement accompanying ** this package. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights.  These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** If you have questions regarding the use of this file, please contact ** Nokia at qt-info@nokia.com. ** ** ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"roundedbox.h"
end_include
begin_comment
comment|//============================================================================//
end_comment
begin_comment
comment|//                                P3T2N3Vertex                                //
end_comment
begin_comment
comment|//============================================================================//
end_comment
begin_decl_stmt
DECL|member|description
name|VertexDescription
name|P3T2N3Vertex
operator|::
name|description
index|[]
init|=
block|{
block|{
name|VertexDescription
operator|::
name|Position
block|,
name|GL_FLOAT
block|,
name|SIZE_OF_MEMBER
argument_list|(
name|P3T2N3Vertex
argument_list|,
name|position
argument_list|)
operator|/
sizeof|sizeof
argument_list|(
name|float
argument_list|)
block|,
literal|0
block|,
literal|0
block|}
block|,
block|{
name|VertexDescription
operator|::
name|TexCoord
block|,
name|GL_FLOAT
block|,
name|SIZE_OF_MEMBER
argument_list|(
name|P3T2N3Vertex
argument_list|,
name|texCoord
argument_list|)
operator|/
sizeof|sizeof
argument_list|(
name|float
argument_list|)
block|,
sizeof|sizeof
argument_list|(
name|QVector3D
argument_list|)
block|,
literal|0
block|}
block|,
block|{
name|VertexDescription
operator|::
name|Normal
block|,
name|GL_FLOAT
block|,
name|SIZE_OF_MEMBER
argument_list|(
name|P3T2N3Vertex
argument_list|,
name|normal
argument_list|)
operator|/
sizeof|sizeof
argument_list|(
name|float
argument_list|)
block|,
sizeof|sizeof
argument_list|(
name|QVector3D
argument_list|)
operator|+
sizeof|sizeof
argument_list|(
name|QVector2D
argument_list|)
block|,
literal|0
block|}
block|,
block|{
name|VertexDescription
operator|::
name|Null
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|}
block|, }
decl_stmt|;
end_decl_stmt
begin_comment
comment|//============================================================================//
end_comment
begin_comment
comment|//                                GLRoundedBox                                //
end_comment
begin_comment
comment|//============================================================================//
end_comment
begin_function
DECL|function|lerp
name|float
name|lerp
parameter_list|(
name|float
name|a
parameter_list|,
name|float
name|b
parameter_list|,
name|float
name|t
parameter_list|)
block|{
return|return
name|a
operator|*
operator|(
literal|1.0f
operator|-
name|t
operator|)
operator|+
name|b
operator|*
name|t
return|;
block|}
end_function
begin_constructor
DECL|function|GLRoundedBox
name|GLRoundedBox
operator|::
name|GLRoundedBox
parameter_list|(
name|float
name|r
parameter_list|,
name|float
name|scale
parameter_list|,
name|int
name|n
parameter_list|)
member_init_list|:
name|GLTriangleMesh
argument_list|<
name|P3T2N3Vertex
argument_list|,
name|unsigned
name|short
argument_list|>
argument_list|(
operator|(
name|n
operator|+
literal|2
operator|)
operator|*
operator|(
name|n
operator|+
literal|3
operator|)
operator|*
literal|4
argument_list|,
operator|(
name|n
operator|+
literal|1
operator|)
operator|*
operator|(
name|n
operator|+
literal|1
operator|)
operator|*
literal|24
operator|+
literal|36
operator|+
literal|72
operator|*
operator|(
name|n
operator|+
literal|1
operator|)
argument_list|)
block|{
name|int
name|vidx
init|=
literal|0
decl_stmt|,
name|iidx
init|=
literal|0
decl_stmt|;
name|int
name|vertexCountPerCorner
init|=
operator|(
name|n
operator|+
literal|2
operator|)
operator|*
operator|(
name|n
operator|+
literal|3
operator|)
operator|/
literal|2
decl_stmt|;
name|P3T2N3Vertex
modifier|*
name|vp
init|=
name|m_vb
operator|.
name|lock
argument_list|()
decl_stmt|;
name|unsigned
name|short
modifier|*
name|ip
init|=
name|m_ib
operator|.
name|lock
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
name|vp
operator|||
operator|!
name|ip
condition|)
block|{
name|qWarning
argument_list|(
literal|"GLRoundedBox::GLRoundedBox: Failed to lock vertex buffer and/or index buffer."
argument_list|)
expr_stmt|;
name|m_ib
operator|.
name|unlock
argument_list|()
expr_stmt|;
name|m_vb
operator|.
name|unlock
argument_list|()
expr_stmt|;
return|return;
block|}
for|for
control|(
name|int
name|corner
init|=
literal|0
init|;
name|corner
operator|<
literal|8
condition|;
operator|++
name|corner
control|)
block|{
name|QVector3D
name|centre
argument_list|(
name|corner
operator|&
literal|1
condition|?
literal|1.0f
else|:
operator|-
literal|1.0f
argument_list|,
name|corner
operator|&
literal|2
condition|?
literal|1.0f
else|:
operator|-
literal|1.0f
argument_list|,
name|corner
operator|&
literal|4
condition|?
literal|1.0f
else|:
operator|-
literal|1.0f
argument_list|)
decl_stmt|;
name|int
name|winding
init|=
operator|(
name|corner
operator|&
literal|1
operator|)
operator|^
operator|(
operator|(
name|corner
operator|>>
literal|1
operator|)
operator|&
literal|1
operator|)
operator|^
operator|(
name|corner
operator|>>
literal|2
operator|)
decl_stmt|;
name|int
name|offsX
init|=
operator|(
operator|(
name|corner
operator|^
literal|1
operator|)
operator|-
name|corner
operator|)
operator|*
name|vertexCountPerCorner
decl_stmt|;
name|int
name|offsY
init|=
operator|(
operator|(
name|corner
operator|^
literal|2
operator|)
operator|-
name|corner
operator|)
operator|*
name|vertexCountPerCorner
decl_stmt|;
name|int
name|offsZ
init|=
operator|(
operator|(
name|corner
operator|^
literal|4
operator|)
operator|-
name|corner
operator|)
operator|*
name|vertexCountPerCorner
decl_stmt|;
comment|// Face polygons
if|if
condition|(
name|winding
condition|)
block|{
name|ip
index|[
name|iidx
operator|++
index|]
operator|=
name|vidx
expr_stmt|;
name|ip
index|[
name|iidx
operator|++
index|]
operator|=
name|vidx
operator|+
name|offsX
expr_stmt|;
name|ip
index|[
name|iidx
operator|++
index|]
operator|=
name|vidx
operator|+
name|offsY
expr_stmt|;
name|ip
index|[
name|iidx
operator|++
index|]
operator|=
name|vidx
operator|+
name|vertexCountPerCorner
operator|-
name|n
operator|-
literal|2
expr_stmt|;
name|ip
index|[
name|iidx
operator|++
index|]
operator|=
name|vidx
operator|+
name|vertexCountPerCorner
operator|-
name|n
operator|-
literal|2
operator|+
name|offsY
expr_stmt|;
name|ip
index|[
name|iidx
operator|++
index|]
operator|=
name|vidx
operator|+
name|vertexCountPerCorner
operator|-
name|n
operator|-
literal|2
operator|+
name|offsZ
expr_stmt|;
name|ip
index|[
name|iidx
operator|++
index|]
operator|=
name|vidx
operator|+
name|vertexCountPerCorner
operator|-
literal|1
expr_stmt|;
name|ip
index|[
name|iidx
operator|++
index|]
operator|=
name|vidx
operator|+
name|vertexCountPerCorner
operator|-
literal|1
operator|+
name|offsZ
expr_stmt|;
name|ip
index|[
name|iidx
operator|++
index|]
operator|=
name|vidx
operator|+
name|vertexCountPerCorner
operator|-
literal|1
operator|+
name|offsX
expr_stmt|;
block|}
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|n
operator|+
literal|2
condition|;
operator|++
name|i
control|)
block|{
comment|// Edge polygons
if|if
condition|(
name|winding
operator|&&
name|i
operator|<
name|n
operator|+
literal|1
condition|)
block|{
name|ip
index|[
name|iidx
operator|++
index|]
operator|=
name|vidx
operator|+
name|i
operator|+
literal|1
expr_stmt|;
name|ip
index|[
name|iidx
operator|++
index|]
operator|=
name|vidx
expr_stmt|;
name|ip
index|[
name|iidx
operator|++
index|]
operator|=
name|vidx
operator|+
name|offsY
operator|+
name|i
operator|+
literal|1
expr_stmt|;
name|ip
index|[
name|iidx
operator|++
index|]
operator|=
name|vidx
operator|+
name|offsY
expr_stmt|;
name|ip
index|[
name|iidx
operator|++
index|]
operator|=
name|vidx
operator|+
name|offsY
operator|+
name|i
operator|+
literal|1
expr_stmt|;
name|ip
index|[
name|iidx
operator|++
index|]
operator|=
name|vidx
expr_stmt|;
name|ip
index|[
name|iidx
operator|++
index|]
operator|=
name|vidx
operator|+
name|i
expr_stmt|;
name|ip
index|[
name|iidx
operator|++
index|]
operator|=
name|vidx
operator|+
literal|2
operator|*
name|i
operator|+
literal|2
expr_stmt|;
name|ip
index|[
name|iidx
operator|++
index|]
operator|=
name|vidx
operator|+
name|i
operator|+
name|offsX
expr_stmt|;
name|ip
index|[
name|iidx
operator|++
index|]
operator|=
name|vidx
operator|+
literal|2
operator|*
name|i
operator|+
name|offsX
operator|+
literal|2
expr_stmt|;
name|ip
index|[
name|iidx
operator|++
index|]
operator|=
name|vidx
operator|+
name|i
operator|+
name|offsX
expr_stmt|;
name|ip
index|[
name|iidx
operator|++
index|]
operator|=
name|vidx
operator|+
literal|2
operator|*
name|i
operator|+
literal|2
expr_stmt|;
name|ip
index|[
name|iidx
operator|++
index|]
operator|=
operator|(
name|corner
operator|+
literal|1
operator|)
operator|*
name|vertexCountPerCorner
operator|-
literal|1
operator|-
name|i
expr_stmt|;
name|ip
index|[
name|iidx
operator|++
index|]
operator|=
operator|(
name|corner
operator|+
literal|1
operator|)
operator|*
name|vertexCountPerCorner
operator|-
literal|2
operator|-
name|i
expr_stmt|;
name|ip
index|[
name|iidx
operator|++
index|]
operator|=
operator|(
name|corner
operator|+
literal|1
operator|)
operator|*
name|vertexCountPerCorner
operator|-
literal|1
operator|-
name|i
operator|+
name|offsZ
expr_stmt|;
name|ip
index|[
name|iidx
operator|++
index|]
operator|=
operator|(
name|corner
operator|+
literal|1
operator|)
operator|*
name|vertexCountPerCorner
operator|-
literal|2
operator|-
name|i
operator|+
name|offsZ
expr_stmt|;
name|ip
index|[
name|iidx
operator|++
index|]
operator|=
operator|(
name|corner
operator|+
literal|1
operator|)
operator|*
name|vertexCountPerCorner
operator|-
literal|1
operator|-
name|i
operator|+
name|offsZ
expr_stmt|;
name|ip
index|[
name|iidx
operator|++
index|]
operator|=
operator|(
name|corner
operator|+
literal|1
operator|)
operator|*
name|vertexCountPerCorner
operator|-
literal|2
operator|-
name|i
expr_stmt|;
block|}
for|for
control|(
name|int
name|j
init|=
literal|0
init|;
name|j
operator|<=
name|i
condition|;
operator|++
name|j
control|)
block|{
name|QVector3D
name|normal
init|=
name|QVector3D
argument_list|(
name|i
operator|-
name|j
argument_list|,
name|j
argument_list|,
name|n
operator|+
literal|1
operator|-
name|i
argument_list|)
operator|.
name|normalized
argument_list|()
decl_stmt|;
name|QVector3D
name|offset
argument_list|(
literal|0.5f
operator|-
name|r
argument_list|,
literal|0.5f
operator|-
name|r
argument_list|,
literal|0.5f
operator|-
name|r
argument_list|)
decl_stmt|;
name|QVector3D
name|pos
init|=
name|centre
operator|*
operator|(
name|offset
operator|+
name|r
operator|*
name|normal
operator|)
decl_stmt|;
name|vp
index|[
name|vidx
index|]
operator|.
name|position
operator|=
name|scale
operator|*
name|pos
expr_stmt|;
name|vp
index|[
name|vidx
index|]
operator|.
name|normal
operator|=
name|centre
operator|*
name|normal
expr_stmt|;
name|vp
index|[
name|vidx
index|]
operator|.
name|texCoord
operator|=
name|QVector2D
argument_list|(
name|pos
operator|.
name|x
argument_list|()
operator|+
literal|0.5f
argument_list|,
name|pos
operator|.
name|y
argument_list|()
operator|+
literal|0.5f
argument_list|)
expr_stmt|;
comment|// Corner polygons
if|if
condition|(
name|i
operator|<
name|n
operator|+
literal|1
condition|)
block|{
name|ip
index|[
name|iidx
operator|++
index|]
operator|=
name|vidx
expr_stmt|;
name|ip
index|[
name|iidx
operator|++
index|]
operator|=
name|vidx
operator|+
name|i
operator|+
literal|2
operator|-
name|winding
expr_stmt|;
name|ip
index|[
name|iidx
operator|++
index|]
operator|=
name|vidx
operator|+
name|i
operator|+
literal|1
operator|+
name|winding
expr_stmt|;
block|}
if|if
condition|(
name|i
operator|<
name|n
condition|)
block|{
name|ip
index|[
name|iidx
operator|++
index|]
operator|=
name|vidx
operator|+
name|i
operator|+
literal|1
operator|+
name|winding
expr_stmt|;
name|ip
index|[
name|iidx
operator|++
index|]
operator|=
name|vidx
operator|+
name|i
operator|+
literal|2
operator|-
name|winding
expr_stmt|;
name|ip
index|[
name|iidx
operator|++
index|]
operator|=
name|vidx
operator|+
literal|2
operator|*
name|i
operator|+
literal|4
expr_stmt|;
block|}
operator|++
name|vidx
expr_stmt|;
block|}
block|}
block|}
name|m_ib
operator|.
name|unlock
argument_list|()
expr_stmt|;
name|m_vb
operator|.
name|unlock
argument_list|()
expr_stmt|;
block|}
end_constructor
end_unit
