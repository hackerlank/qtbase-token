begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** BSD License Usage ** Alternatively, you may use this file under the terms of the BSD license ** as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of The Qt Company Ltd nor the names of its **     contributors may be used to endorse or promote products derived **     from this software without specific prior written permission. ** ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|CUBE_H
end_ifndef
begin_define
DECL|macro|CUBE_H
define|#
directive|define
name|CUBE_H
end_define
begin_include
include|#
directive|include
file|<QtOpenGL/qgl.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qvector.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qsequentialanimationgroup.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/qmatrix4x4.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/qvector3d.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/qvector2d.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QPropertyAnimation
name|class
name|QPropertyAnimation
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QT_END_NAMESPACE
name|class
name|Geometry
block|{
name|public
label|:
name|void
name|loadArrays
argument_list|()
specifier|const
expr_stmt|;
name|void
name|addQuad
argument_list|(
specifier|const
name|QVector3D
operator|&
name|a
argument_list|,
specifier|const
name|QVector3D
operator|&
name|b
argument_list|,
specifier|const
name|QVector3D
operator|&
name|c
argument_list|,
specifier|const
name|QVector3D
operator|&
name|d
argument_list|,
specifier|const
name|QVector
operator|<
name|QVector2D
operator|>
operator|&
name|tex
argument_list|)
decl_stmt|;
name|void
name|setColors
parameter_list|(
name|int
name|start
parameter_list|,
name|GLfloat
name|colors
index|[
literal|4
index|]
index|[
literal|4
index|]
parameter_list|)
function_decl|;
specifier|const
name|GLushort
operator|*
name|indices
argument_list|()
specifier|const
block|{
return|return
name|faces
operator|.
name|constData
argument_list|()
return|;
block|}
name|int
name|count
argument_list|()
specifier|const
block|{
return|return
name|faces
operator|.
name|count
argument_list|()
return|;
block|}
name|private
label|:
name|QVector
operator|<
name|GLushort
operator|>
name|faces
expr_stmt|;
name|QVector
operator|<
name|QVector3D
operator|>
name|vertices
expr_stmt|;
name|QVector
operator|<
name|QVector3D
operator|>
name|normals
expr_stmt|;
name|QVector
operator|<
name|QVector2D
operator|>
name|texCoords
expr_stmt|;
name|QVector
operator|<
name|QVector4D
operator|>
name|colors
expr_stmt|;
name|int
name|append
parameter_list|(
specifier|const
name|QVector3D
modifier|&
name|a
parameter_list|,
specifier|const
name|QVector3D
modifier|&
name|n
parameter_list|,
specifier|const
name|QVector2D
modifier|&
name|t
parameter_list|)
function_decl|;
name|void
name|addTri
parameter_list|(
specifier|const
name|QVector3D
modifier|&
name|a
parameter_list|,
specifier|const
name|QVector3D
modifier|&
name|b
parameter_list|,
specifier|const
name|QVector3D
modifier|&
name|c
parameter_list|,
specifier|const
name|QVector3D
modifier|&
name|n
parameter_list|)
function_decl|;
name|friend
name|class
name|Tile
decl_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_decl_stmt
name|class
name|Tile
block|{
name|public
label|:
name|void
name|draw
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setColors
parameter_list|(
name|GLfloat
index|[
literal|4
index|]
index|[
literal|4
index|]
parameter_list|)
function_decl|;
name|protected
label|:
name|Tile
argument_list|(
specifier|const
name|QVector3D
operator|&
name|loc
operator|=
name|QVector3D
argument_list|()
argument_list|)
expr_stmt|;
name|QVector3D
name|location
decl_stmt|;
name|QQuaternion
name|orientation
decl_stmt|;
name|private
label|:
name|int
name|start
decl_stmt|;
name|int
name|count
decl_stmt|;
name|bool
name|useFlatColor
decl_stmt|;
name|GLfloat
name|faceColor
index|[
literal|4
index|]
decl_stmt|;
name|Geometry
modifier|*
name|geom
decl_stmt|;
name|friend
name|class
name|TileBuilder
decl_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_decl_stmt
name|class
name|TileBuilder
block|{
name|public
label|:
enum|enum
block|{
name|bl
block|,
name|br
block|,
name|tr
block|,
name|tl
block|}
enum|;
name|explicit
name|TileBuilder
parameter_list|(
name|Geometry
modifier|*
parameter_list|,
name|qreal
name|depth
init|=
literal|0.0f
parameter_list|,
name|qreal
name|size
init|=
literal|1.0f
parameter_list|)
function_decl|;
name|Tile
modifier|*
name|newTile
argument_list|(
specifier|const
name|QVector3D
operator|&
name|loc
operator|=
name|QVector3D
argument_list|()
argument_list|)
decl|const
decl_stmt|;
name|void
name|setColor
parameter_list|(
name|QColor
name|c
parameter_list|)
block|{
name|color
operator|=
name|c
expr_stmt|;
block|}
name|protected
label|:
name|void
name|initialize
argument_list|(
name|Tile
operator|*
argument_list|)
decl|const
decl_stmt|;
name|QVector
operator|<
name|QVector3D
operator|>
name|verts
expr_stmt|;
name|QVector
operator|<
name|QVector2D
operator|>
name|tex
expr_stmt|;
name|int
name|start
decl_stmt|;
name|int
name|count
decl_stmt|;
name|Geometry
modifier|*
name|geom
decl_stmt|;
name|QColor
name|color
decl_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_decl_stmt
DECL|variable|QObject
name|class
name|Cube
range|:
name|public
name|QObject
decl_stmt|,
name|public
name|Tile
block|{
name|Q_OBJECT
name|Q_PROPERTY
argument_list|(
name|qreal
name|range
name|READ
name|range
name|WRITE
name|setRange
argument_list|)
name|Q_PROPERTY
argument_list|(
name|qreal
name|altitude
name|READ
name|altitude
name|WRITE
name|setAltitude
argument_list|)
name|Q_PROPERTY
argument_list|(
name|qreal
name|rotation
name|READ
name|rotation
name|WRITE
name|setRotation
argument_list|)
name|public
range|:
name|Cube
argument_list|(
specifier|const
name|QVector3D
operator|&
name|loc
operator|=
name|QVector3D
argument_list|()
argument_list|)
decl_stmt|;
operator|~
name|Cube
argument_list|()
expr_stmt|;
name|qreal
name|range
parameter_list|()
block|{
return|return
name|location
operator|.
name|x
argument_list|()
return|;
block|}
name|void
name|setRange
parameter_list|(
name|qreal
name|r
parameter_list|)
function_decl|;
name|qreal
name|altitude
parameter_list|()
block|{
return|return
name|location
operator|.
name|y
argument_list|()
return|;
block|}
name|void
name|setAltitude
parameter_list|(
name|qreal
name|a
parameter_list|)
function_decl|;
name|qreal
name|rotation
parameter_list|()
block|{
return|return
name|rot
return|;
block|}
name|void
name|setRotation
parameter_list|(
name|qreal
name|r
parameter_list|)
function_decl|;
name|void
name|removeBounce
parameter_list|()
function_decl|;
name|void
name|startAnimation
parameter_list|()
function_decl|;
name|void
name|setAnimationPaused
parameter_list|(
name|bool
name|paused
parameter_list|)
function_decl|;
name|signals
label|:
name|void
name|changed
parameter_list|()
function_decl|;
name|private
label|:
name|qreal
name|rot
decl_stmt|;
name|QPropertyAnimation
modifier|*
name|r
decl_stmt|;
name|QPropertyAnimation
modifier|*
name|rtn
decl_stmt|;
name|QSequentialAnimationGroup
modifier|*
name|animGroup
decl_stmt|;
name|qreal
name|startx
decl_stmt|;
name|friend
name|class
name|CubeBuilder
decl_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_decl_stmt
name|class
name|CubeBuilder
range|:
name|public
name|TileBuilder
block|{
name|public
operator|:
name|explicit
name|CubeBuilder
argument_list|(
argument|Geometry *
argument_list|,
argument|qreal depth =
literal|0.0f
argument_list|,
argument|qreal size =
literal|1.0f
argument_list|)
block|;
name|Cube
operator|*
name|newCube
argument_list|(
argument|const QVector3D&loc = QVector3D()
argument_list|)
specifier|const
block|;
name|private
operator|:
name|mutable
name|int
name|ix
block|; }
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// CUBE_H
end_comment
end_unit
