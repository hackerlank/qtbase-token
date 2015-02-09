begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QQUATERNION_H
end_ifndef
begin_define
DECL|macro|QQUATERNION_H
define|#
directive|define
name|QQUATERNION_H
end_define
begin_include
include|#
directive|include
file|<QtGui/qgenericmatrix.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/qvector3d.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/qvector4d.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
ifndef|#
directive|ifndef
name|QT_NO_QUATERNION
DECL|variable|QMatrix4x4
name|class
name|QMatrix4x4
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QVariant
name|class
name|QVariant
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_GUI_EXPORT
name|QQuaternion
block|{
name|public
label|:
name|QQuaternion
argument_list|()
expr_stmt|;
name|explicit
name|QQuaternion
argument_list|(
name|Qt
operator|::
name|Initialization
argument_list|)
block|{}
name|QQuaternion
argument_list|(
argument|float scalar
argument_list|,
argument|float xpos
argument_list|,
argument|float ypos
argument_list|,
argument|float zpos
argument_list|)
empty_stmt|;
ifndef|#
directive|ifndef
name|QT_NO_VECTOR3D
name|QQuaternion
argument_list|(
argument|float scalar
argument_list|,
argument|const QVector3D& vector
argument_list|)
empty_stmt|;
endif|#
directive|endif
ifndef|#
directive|ifndef
name|QT_NO_VECTOR4D
name|explicit
name|QQuaternion
parameter_list|(
specifier|const
name|QVector4D
modifier|&
name|vector
parameter_list|)
function_decl|;
endif|#
directive|endif
name|bool
name|isNull
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|isIdentity
argument_list|()
specifier|const
expr_stmt|;
ifndef|#
directive|ifndef
name|QT_NO_VECTOR3D
name|QVector3D
name|vector
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setVector
parameter_list|(
specifier|const
name|QVector3D
modifier|&
name|vector
parameter_list|)
function_decl|;
endif|#
directive|endif
name|void
name|setVector
parameter_list|(
name|float
name|x
parameter_list|,
name|float
name|y
parameter_list|,
name|float
name|z
parameter_list|)
function_decl|;
name|float
name|x
argument_list|()
specifier|const
expr_stmt|;
name|float
name|y
argument_list|()
specifier|const
expr_stmt|;
name|float
name|z
argument_list|()
specifier|const
expr_stmt|;
name|float
name|scalar
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setX
parameter_list|(
name|float
name|x
parameter_list|)
function_decl|;
name|void
name|setY
parameter_list|(
name|float
name|y
parameter_list|)
function_decl|;
name|void
name|setZ
parameter_list|(
name|float
name|z
parameter_list|)
function_decl|;
name|void
name|setScalar
parameter_list|(
name|float
name|scalar
parameter_list|)
function_decl|;
name|float
name|length
argument_list|()
specifier|const
expr_stmt|;
name|float
name|lengthSquared
argument_list|()
specifier|const
expr_stmt|;
name|QQuaternion
name|normalized
argument_list|()
specifier|const
expr_stmt|;
name|void
name|normalize
parameter_list|()
function_decl|;
specifier|inline
name|QQuaternion
name|inverted
argument_list|()
specifier|const
expr_stmt|;
name|QQuaternion
name|conjugate
argument_list|()
specifier|const
expr_stmt|;
name|QVector3D
name|rotatedVector
argument_list|(
specifier|const
name|QVector3D
operator|&
name|vector
argument_list|)
decl|const
decl_stmt|;
name|QQuaternion
operator|&
name|operator
operator|+=
operator|(
specifier|const
name|QQuaternion
operator|&
name|quaternion
operator|)
expr_stmt|;
name|QQuaternion
operator|&
name|operator
operator|-=
operator|(
specifier|const
name|QQuaternion
operator|&
name|quaternion
operator|)
expr_stmt|;
name|QQuaternion
operator|&
name|operator
operator|*=
operator|(
name|float
name|factor
operator|)
expr_stmt|;
name|QQuaternion
operator|&
name|operator
operator|*=
operator|(
specifier|const
name|QQuaternion
operator|&
name|quaternion
operator|)
expr_stmt|;
name|QQuaternion
operator|&
name|operator
operator|/=
operator|(
name|float
name|divisor
operator|)
expr_stmt|;
name|friend
specifier|inline
name|bool
name|operator
operator|==
operator|(
specifier|const
name|QQuaternion
operator|&
name|q1
operator|,
specifier|const
name|QQuaternion
operator|&
name|q2
operator|)
expr_stmt|;
name|friend
specifier|inline
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|QQuaternion
operator|&
name|q1
operator|,
specifier|const
name|QQuaternion
operator|&
name|q2
operator|)
expr_stmt|;
name|friend
specifier|inline
specifier|const
name|QQuaternion
name|operator
operator|+
operator|(
specifier|const
name|QQuaternion
operator|&
name|q1
operator|,
specifier|const
name|QQuaternion
operator|&
name|q2
operator|)
expr_stmt|;
name|friend
specifier|inline
specifier|const
name|QQuaternion
name|operator
operator|-
operator|(
specifier|const
name|QQuaternion
operator|&
name|q1
operator|,
specifier|const
name|QQuaternion
operator|&
name|q2
operator|)
expr_stmt|;
name|friend
specifier|inline
specifier|const
name|QQuaternion
name|operator
modifier|*
parameter_list|(
name|float
name|factor
parameter_list|,
specifier|const
name|QQuaternion
modifier|&
name|quaternion
parameter_list|)
function_decl|;
name|friend
specifier|inline
specifier|const
name|QQuaternion
name|operator
modifier|*
parameter_list|(
specifier|const
name|QQuaternion
modifier|&
name|quaternion
parameter_list|,
name|float
name|factor
parameter_list|)
function_decl|;
name|friend
specifier|inline
specifier|const
name|QQuaternion
name|operator
modifier|*
parameter_list|(
specifier|const
name|QQuaternion
modifier|&
name|q1
parameter_list|,
specifier|const
name|QQuaternion
modifier|&
name|q2
parameter_list|)
function_decl|;
name|friend
specifier|inline
specifier|const
name|QQuaternion
name|operator
operator|-
operator|(
specifier|const
name|QQuaternion
operator|&
name|quaternion
operator|)
expr_stmt|;
name|friend
specifier|inline
specifier|const
name|QQuaternion
name|operator
operator|/
operator|(
specifier|const
name|QQuaternion
operator|&
name|quaternion
operator|,
name|float
name|divisor
operator|)
expr_stmt|;
name|friend
specifier|inline
name|bool
name|qFuzzyCompare
parameter_list|(
specifier|const
name|QQuaternion
modifier|&
name|q1
parameter_list|,
specifier|const
name|QQuaternion
modifier|&
name|q2
parameter_list|)
function_decl|;
ifndef|#
directive|ifndef
name|QT_NO_VECTOR4D
name|QVector4D
name|toVector4D
argument_list|()
specifier|const
expr_stmt|;
endif|#
directive|endif
name|operator
name|QVariant
argument_list|()
specifier|const
expr_stmt|;
ifndef|#
directive|ifndef
name|QT_NO_VECTOR3D
specifier|inline
name|void
name|toAxisAndAngle
argument_list|(
name|QVector3D
operator|*
name|axis
argument_list|,
name|float
operator|*
name|angle
argument_list|)
decl|const
decl_stmt|;
specifier|static
name|QQuaternion
name|fromAxisAndAngle
parameter_list|(
specifier|const
name|QVector3D
modifier|&
name|axis
parameter_list|,
name|float
name|angle
parameter_list|)
function_decl|;
endif|#
directive|endif
name|void
name|toAxisAndAngle
argument_list|(
name|float
operator|*
name|x
argument_list|,
name|float
operator|*
name|y
argument_list|,
name|float
operator|*
name|z
argument_list|,
name|float
operator|*
name|angle
argument_list|)
decl|const
decl_stmt|;
specifier|static
name|QQuaternion
name|fromAxisAndAngle
parameter_list|(
name|float
name|x
parameter_list|,
name|float
name|y
parameter_list|,
name|float
name|z
parameter_list|,
name|float
name|angle
parameter_list|)
function_decl|;
ifndef|#
directive|ifndef
name|QT_NO_VECTOR3D
specifier|inline
name|QVector3D
name|toEulerAngles
argument_list|()
specifier|const
expr_stmt|;
specifier|static
specifier|inline
name|QQuaternion
name|fromEulerAngles
parameter_list|(
specifier|const
name|QVector3D
modifier|&
name|eulerAngles
parameter_list|)
function_decl|;
endif|#
directive|endif
name|void
name|toEulerAngles
argument_list|(
name|float
operator|*
name|pitch
argument_list|,
name|float
operator|*
name|yaw
argument_list|,
name|float
operator|*
name|roll
argument_list|)
decl|const
decl_stmt|;
specifier|static
name|QQuaternion
name|fromEulerAngles
parameter_list|(
name|float
name|pitch
parameter_list|,
name|float
name|yaw
parameter_list|,
name|float
name|roll
parameter_list|)
function_decl|;
name|QMatrix3x3
name|toRotationMatrix
argument_list|()
specifier|const
expr_stmt|;
specifier|static
name|QQuaternion
name|fromRotationMatrix
parameter_list|(
specifier|const
name|QMatrix3x3
modifier|&
name|rot3x3
parameter_list|)
function_decl|;
specifier|static
name|QQuaternion
name|slerp
parameter_list|(
specifier|const
name|QQuaternion
modifier|&
name|q1
parameter_list|,
specifier|const
name|QQuaternion
modifier|&
name|q2
parameter_list|,
name|float
name|t
parameter_list|)
function_decl|;
specifier|static
name|QQuaternion
name|nlerp
parameter_list|(
specifier|const
name|QQuaternion
modifier|&
name|q1
parameter_list|,
specifier|const
name|QQuaternion
modifier|&
name|q2
parameter_list|,
name|float
name|t
parameter_list|)
function_decl|;
name|private
label|:
name|float
name|wp
decl_stmt|,
name|xp
decl_stmt|,
name|yp
decl_stmt|,
name|zp
decl_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_expr_stmt
name|Q_DECLARE_TYPEINFO
argument_list|(
name|QQuaternion
argument_list|,
name|Q_MOVABLE_TYPE
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
DECL|function|QQuaternion
specifier|inline
name|QQuaternion
operator|::
name|QQuaternion
argument_list|()
operator|:
name|wp
argument_list|(
literal|1.0f
argument_list|)
operator|,
name|xp
argument_list|(
literal|0.0f
argument_list|)
operator|,
name|yp
argument_list|(
literal|0.0f
argument_list|)
operator|,
name|zp
argument_list|(
literal|0.0f
argument_list|)
block|{}
DECL|function|QQuaternion
specifier|inline
name|QQuaternion
operator|::
name|QQuaternion
argument_list|(
argument|float aScalar
argument_list|,
argument|float xpos
argument_list|,
argument|float ypos
argument_list|,
argument|float zpos
argument_list|)
operator|:
name|wp
argument_list|(
name|aScalar
argument_list|)
operator|,
name|xp
argument_list|(
name|xpos
argument_list|)
operator|,
name|yp
argument_list|(
name|ypos
argument_list|)
operator|,
name|zp
argument_list|(
argument|zpos
argument_list|)
block|{}
DECL|function|isNull
specifier|inline
name|bool
name|QQuaternion
operator|::
name|isNull
argument_list|()
specifier|const
block|{
return|return
name|qIsNull
argument_list|(
name|xp
argument_list|)
operator|&&
name|qIsNull
argument_list|(
name|yp
argument_list|)
operator|&&
name|qIsNull
argument_list|(
name|zp
argument_list|)
operator|&&
name|qIsNull
argument_list|(
name|wp
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|isIdentity
specifier|inline
name|bool
name|QQuaternion
operator|::
name|isIdentity
argument_list|()
specifier|const
block|{
return|return
name|qIsNull
argument_list|(
name|xp
argument_list|)
operator|&&
name|qIsNull
argument_list|(
name|yp
argument_list|)
operator|&&
name|qIsNull
argument_list|(
name|zp
argument_list|)
operator|&&
name|wp
operator|==
literal|1.0f
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|x
specifier|inline
name|float
name|QQuaternion
operator|::
name|x
argument_list|()
specifier|const
block|{
return|return
name|xp
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|y
specifier|inline
name|float
name|QQuaternion
operator|::
name|y
argument_list|()
specifier|const
block|{
return|return
name|yp
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|z
specifier|inline
name|float
name|QQuaternion
operator|::
name|z
argument_list|()
specifier|const
block|{
return|return
name|zp
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|scalar
specifier|inline
name|float
name|QQuaternion
operator|::
name|scalar
argument_list|()
specifier|const
block|{
return|return
name|wp
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|setX
specifier|inline
name|void
name|QQuaternion
operator|::
name|setX
argument_list|(
argument|float aX
argument_list|)
block|{
name|xp
operator|=
name|aX
block|; }
DECL|function|setY
specifier|inline
name|void
name|QQuaternion
operator|::
name|setY
argument_list|(
argument|float aY
argument_list|)
block|{
name|yp
operator|=
name|aY
block|; }
DECL|function|setZ
specifier|inline
name|void
name|QQuaternion
operator|::
name|setZ
argument_list|(
argument|float aZ
argument_list|)
block|{
name|zp
operator|=
name|aZ
block|; }
DECL|function|setScalar
specifier|inline
name|void
name|QQuaternion
operator|::
name|setScalar
argument_list|(
argument|float aScalar
argument_list|)
block|{
name|wp
operator|=
name|aScalar
block|; }
DECL|function|inverted
specifier|inline
name|QQuaternion
name|QQuaternion
operator|::
name|inverted
argument_list|()
specifier|const
block|{
comment|// Need some extra precision if the length is very small.
name|double
name|len
operator|=
name|double
argument_list|(
name|xp
argument_list|)
operator|*
name|double
argument_list|(
name|xp
argument_list|)
operator|+
name|double
argument_list|(
name|yp
argument_list|)
operator|*
name|double
argument_list|(
name|yp
argument_list|)
operator|+
name|double
argument_list|(
name|zp
argument_list|)
operator|*
name|double
argument_list|(
name|zp
argument_list|)
operator|+
name|double
argument_list|(
name|wp
argument_list|)
operator|*
name|double
argument_list|(
name|wp
argument_list|)
block|;
if|if
condition|(
operator|!
name|qFuzzyIsNull
argument_list|(
name|len
argument_list|)
condition|)
return|return
name|QQuaternion
argument_list|(
name|wp
operator|/
name|len
argument_list|,
operator|-
name|xp
operator|/
name|len
argument_list|,
operator|-
name|yp
operator|/
name|len
argument_list|,
operator|-
name|zp
operator|/
name|len
argument_list|)
return|;
end_expr_stmt
begin_return
return|return
name|QQuaternion
argument_list|(
literal|0.0f
argument_list|,
literal|0.0f
argument_list|,
literal|0.0f
argument_list|,
literal|0.0f
argument_list|)
return|;
end_return
begin_expr_stmt
unit|}  inline
DECL|function|conjugate
name|QQuaternion
name|QQuaternion
operator|::
name|conjugate
argument_list|()
specifier|const
block|{
return|return
name|QQuaternion
argument_list|(
name|wp
argument_list|,
operator|-
name|xp
argument_list|,
operator|-
name|yp
argument_list|,
operator|-
name|zp
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|member|operator
specifier|inline
name|QQuaternion
operator|&
name|QQuaternion
operator|::
name|operator
operator|+=
operator|(
specifier|const
name|QQuaternion
operator|&
name|quaternion
operator|)
block|{
name|xp
operator|+=
name|quaternion
operator|.
name|xp
block|;
name|yp
operator|+=
name|quaternion
operator|.
name|yp
block|;
name|zp
operator|+=
name|quaternion
operator|.
name|zp
block|;
name|wp
operator|+=
name|quaternion
operator|.
name|wp
block|;
return|return
operator|*
name|this
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
name|QQuaternion
operator|&
name|QQuaternion
operator|::
name|operator
operator|-=
operator|(
specifier|const
name|QQuaternion
operator|&
name|quaternion
operator|)
block|{
name|xp
operator|-=
name|quaternion
operator|.
name|xp
block|;
name|yp
operator|-=
name|quaternion
operator|.
name|yp
block|;
name|zp
operator|-=
name|quaternion
operator|.
name|zp
block|;
name|wp
operator|-=
name|quaternion
operator|.
name|wp
block|;
return|return
operator|*
name|this
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
name|QQuaternion
operator|&
name|QQuaternion
operator|::
name|operator
operator|*=
operator|(
name|float
name|factor
operator|)
block|{
name|xp
operator|*=
name|factor
block|;
name|yp
operator|*=
name|factor
block|;
name|zp
operator|*=
name|factor
block|;
name|wp
operator|*=
name|factor
block|;
return|return
operator|*
name|this
return|;
block|}
end_expr_stmt
begin_function
specifier|inline
specifier|const
name|QQuaternion
name|operator
modifier|*
parameter_list|(
specifier|const
name|QQuaternion
modifier|&
name|q1
parameter_list|,
specifier|const
name|QQuaternion
modifier|&
name|q2
parameter_list|)
block|{
name|float
name|ww
init|=
operator|(
name|q1
operator|.
name|zp
operator|+
name|q1
operator|.
name|xp
operator|)
operator|*
operator|(
name|q2
operator|.
name|xp
operator|+
name|q2
operator|.
name|yp
operator|)
decl_stmt|;
name|float
name|yy
init|=
operator|(
name|q1
operator|.
name|wp
operator|-
name|q1
operator|.
name|yp
operator|)
operator|*
operator|(
name|q2
operator|.
name|wp
operator|+
name|q2
operator|.
name|zp
operator|)
decl_stmt|;
name|float
name|zz
init|=
operator|(
name|q1
operator|.
name|wp
operator|+
name|q1
operator|.
name|yp
operator|)
operator|*
operator|(
name|q2
operator|.
name|wp
operator|-
name|q2
operator|.
name|zp
operator|)
decl_stmt|;
name|float
name|xx
init|=
name|ww
operator|+
name|yy
operator|+
name|zz
decl_stmt|;
name|float
name|qq
init|=
literal|0.5
operator|*
operator|(
name|xx
operator|+
operator|(
name|q1
operator|.
name|zp
operator|-
name|q1
operator|.
name|xp
operator|)
operator|*
operator|(
name|q2
operator|.
name|xp
operator|-
name|q2
operator|.
name|yp
operator|)
operator|)
decl_stmt|;
name|float
name|w
init|=
name|qq
operator|-
name|ww
operator|+
operator|(
name|q1
operator|.
name|zp
operator|-
name|q1
operator|.
name|yp
operator|)
operator|*
operator|(
name|q2
operator|.
name|yp
operator|-
name|q2
operator|.
name|zp
operator|)
decl_stmt|;
name|float
name|x
init|=
name|qq
operator|-
name|xx
operator|+
operator|(
name|q1
operator|.
name|xp
operator|+
name|q1
operator|.
name|wp
operator|)
operator|*
operator|(
name|q2
operator|.
name|xp
operator|+
name|q2
operator|.
name|wp
operator|)
decl_stmt|;
name|float
name|y
init|=
name|qq
operator|-
name|yy
operator|+
operator|(
name|q1
operator|.
name|wp
operator|-
name|q1
operator|.
name|xp
operator|)
operator|*
operator|(
name|q2
operator|.
name|yp
operator|+
name|q2
operator|.
name|zp
operator|)
decl_stmt|;
name|float
name|z
init|=
name|qq
operator|-
name|zz
operator|+
operator|(
name|q1
operator|.
name|zp
operator|+
name|q1
operator|.
name|yp
operator|)
operator|*
operator|(
name|q2
operator|.
name|wp
operator|-
name|q2
operator|.
name|xp
operator|)
decl_stmt|;
return|return
name|QQuaternion
argument_list|(
name|w
argument_list|,
name|x
argument_list|,
name|y
argument_list|,
name|z
argument_list|)
return|;
block|}
end_function
begin_expr_stmt
specifier|inline
name|QQuaternion
operator|&
name|QQuaternion
operator|::
name|operator
operator|*=
operator|(
specifier|const
name|QQuaternion
operator|&
name|quaternion
operator|)
block|{
operator|*
name|this
operator|=
operator|*
name|this
operator|*
name|quaternion
block|;
return|return
operator|*
name|this
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
name|QQuaternion
operator|&
name|QQuaternion
operator|::
name|operator
operator|/=
operator|(
name|float
name|divisor
operator|)
block|{
name|xp
operator|/=
name|divisor
block|;
name|yp
operator|/=
name|divisor
block|;
name|zp
operator|/=
name|divisor
block|;
name|wp
operator|/=
name|divisor
block|;
return|return
operator|*
name|this
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
name|bool
name|operator
operator|==
operator|(
specifier|const
name|QQuaternion
operator|&
name|q1
operator|,
specifier|const
name|QQuaternion
operator|&
name|q2
operator|)
block|{
return|return
name|q1
operator|.
name|xp
operator|==
name|q2
operator|.
name|xp
operator|&&
name|q1
operator|.
name|yp
operator|==
name|q2
operator|.
name|yp
operator|&&
name|q1
operator|.
name|zp
operator|==
name|q2
operator|.
name|zp
operator|&&
name|q1
operator|.
name|wp
operator|==
name|q2
operator|.
name|wp
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|QQuaternion
operator|&
name|q1
operator|,
specifier|const
name|QQuaternion
operator|&
name|q2
operator|)
block|{
return|return
name|q1
operator|.
name|xp
operator|!=
name|q2
operator|.
name|xp
operator|||
name|q1
operator|.
name|yp
operator|!=
name|q2
operator|.
name|yp
operator|||
name|q1
operator|.
name|zp
operator|!=
name|q2
operator|.
name|zp
operator|||
name|q1
operator|.
name|wp
operator|!=
name|q2
operator|.
name|wp
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
specifier|const
name|QQuaternion
name|operator
operator|+
operator|(
specifier|const
name|QQuaternion
operator|&
name|q1
operator|,
specifier|const
name|QQuaternion
operator|&
name|q2
operator|)
block|{
return|return
name|QQuaternion
argument_list|(
name|q1
operator|.
name|wp
operator|+
name|q2
operator|.
name|wp
argument_list|,
name|q1
operator|.
name|xp
operator|+
name|q2
operator|.
name|xp
argument_list|,
name|q1
operator|.
name|yp
operator|+
name|q2
operator|.
name|yp
argument_list|,
name|q1
operator|.
name|zp
operator|+
name|q2
operator|.
name|zp
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
specifier|const
name|QQuaternion
name|operator
operator|-
operator|(
specifier|const
name|QQuaternion
operator|&
name|q1
operator|,
specifier|const
name|QQuaternion
operator|&
name|q2
operator|)
block|{
return|return
name|QQuaternion
argument_list|(
name|q1
operator|.
name|wp
operator|-
name|q2
operator|.
name|wp
argument_list|,
name|q1
operator|.
name|xp
operator|-
name|q2
operator|.
name|xp
argument_list|,
name|q1
operator|.
name|yp
operator|-
name|q2
operator|.
name|yp
argument_list|,
name|q1
operator|.
name|zp
operator|-
name|q2
operator|.
name|zp
argument_list|)
return|;
block|}
end_expr_stmt
begin_function
specifier|inline
specifier|const
name|QQuaternion
name|operator
modifier|*
parameter_list|(
name|float
name|factor
parameter_list|,
specifier|const
name|QQuaternion
modifier|&
name|quaternion
parameter_list|)
block|{
return|return
name|QQuaternion
argument_list|(
name|quaternion
operator|.
name|wp
operator|*
name|factor
argument_list|,
name|quaternion
operator|.
name|xp
operator|*
name|factor
argument_list|,
name|quaternion
operator|.
name|yp
operator|*
name|factor
argument_list|,
name|quaternion
operator|.
name|zp
operator|*
name|factor
argument_list|)
return|;
block|}
end_function
begin_function
specifier|inline
specifier|const
name|QQuaternion
name|operator
modifier|*
parameter_list|(
specifier|const
name|QQuaternion
modifier|&
name|quaternion
parameter_list|,
name|float
name|factor
parameter_list|)
block|{
return|return
name|QQuaternion
argument_list|(
name|quaternion
operator|.
name|wp
operator|*
name|factor
argument_list|,
name|quaternion
operator|.
name|xp
operator|*
name|factor
argument_list|,
name|quaternion
operator|.
name|yp
operator|*
name|factor
argument_list|,
name|quaternion
operator|.
name|zp
operator|*
name|factor
argument_list|)
return|;
block|}
end_function
begin_expr_stmt
specifier|inline
specifier|const
name|QQuaternion
name|operator
operator|-
operator|(
specifier|const
name|QQuaternion
operator|&
name|quaternion
operator|)
block|{
return|return
name|QQuaternion
argument_list|(
operator|-
name|quaternion
operator|.
name|wp
argument_list|,
operator|-
name|quaternion
operator|.
name|xp
argument_list|,
operator|-
name|quaternion
operator|.
name|yp
argument_list|,
operator|-
name|quaternion
operator|.
name|zp
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
specifier|const
name|QQuaternion
name|operator
operator|/
operator|(
specifier|const
name|QQuaternion
operator|&
name|quaternion
operator|,
name|float
name|divisor
operator|)
block|{
return|return
name|QQuaternion
argument_list|(
name|quaternion
operator|.
name|wp
operator|/
name|divisor
argument_list|,
name|quaternion
operator|.
name|xp
operator|/
name|divisor
argument_list|,
name|quaternion
operator|.
name|yp
operator|/
name|divisor
argument_list|,
name|quaternion
operator|.
name|zp
operator|/
name|divisor
argument_list|)
return|;
block|}
end_expr_stmt
begin_function
specifier|inline
name|bool
name|qFuzzyCompare
parameter_list|(
specifier|const
name|QQuaternion
modifier|&
name|q1
parameter_list|,
specifier|const
name|QQuaternion
modifier|&
name|q2
parameter_list|)
block|{
return|return
name|qFuzzyCompare
argument_list|(
name|q1
operator|.
name|xp
argument_list|,
name|q2
operator|.
name|xp
argument_list|)
operator|&&
name|qFuzzyCompare
argument_list|(
name|q1
operator|.
name|yp
argument_list|,
name|q2
operator|.
name|yp
argument_list|)
operator|&&
name|qFuzzyCompare
argument_list|(
name|q1
operator|.
name|zp
argument_list|,
name|q2
operator|.
name|zp
argument_list|)
operator|&&
name|qFuzzyCompare
argument_list|(
name|q1
operator|.
name|wp
argument_list|,
name|q2
operator|.
name|wp
argument_list|)
return|;
block|}
end_function
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_VECTOR3D
end_ifndef
begin_expr_stmt
specifier|inline
name|QQuaternion
operator|::
name|QQuaternion
argument_list|(
argument|float aScalar
argument_list|,
argument|const QVector3D& aVector
argument_list|)
DECL|function|zp
operator|:
name|wp
argument_list|(
name|aScalar
argument_list|)
operator|,
name|xp
argument_list|(
name|aVector
operator|.
name|x
argument_list|()
argument_list|)
operator|,
name|yp
argument_list|(
name|aVector
operator|.
name|y
argument_list|()
argument_list|)
operator|,
name|zp
argument_list|(
argument|aVector.z()
argument_list|)
block|{}
DECL|function|setVector
specifier|inline
name|void
name|QQuaternion
operator|::
name|setVector
argument_list|(
argument|const QVector3D& aVector
argument_list|)
block|{
name|xp
operator|=
name|aVector
operator|.
name|x
argument_list|()
block|;
name|yp
operator|=
name|aVector
operator|.
name|y
argument_list|()
block|;
name|zp
operator|=
name|aVector
operator|.
name|z
argument_list|()
block|; }
DECL|function|vector
specifier|inline
name|QVector3D
name|QQuaternion
operator|::
name|vector
argument_list|()
specifier|const
block|{
return|return
name|QVector3D
argument_list|(
name|xp
argument_list|,
name|yp
argument_list|,
name|zp
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|toAxisAndAngle
specifier|inline
name|void
name|QQuaternion
operator|::
name|toAxisAndAngle
argument_list|(
argument|QVector3D *axis
argument_list|,
argument|float *angle
argument_list|)
specifier|const
block|{
name|float
name|aX
block|,
name|aY
block|,
name|aZ
block|;
name|toAxisAndAngle
argument_list|(
operator|&
name|aX
argument_list|,
operator|&
name|aY
argument_list|,
operator|&
name|aZ
argument_list|,
name|angle
argument_list|)
block|;
operator|*
name|axis
operator|=
name|QVector3D
argument_list|(
name|aX
argument_list|,
name|aY
argument_list|,
name|aZ
argument_list|)
block|; }
DECL|function|toEulerAngles
specifier|inline
name|QVector3D
name|QQuaternion
operator|::
name|toEulerAngles
argument_list|()
specifier|const
block|{
name|float
name|pitch
block|,
name|yaw
block|,
name|roll
block|;
name|toEulerAngles
argument_list|(
operator|&
name|pitch
argument_list|,
operator|&
name|yaw
argument_list|,
operator|&
name|roll
argument_list|)
block|;
return|return
name|QVector3D
argument_list|(
name|pitch
argument_list|,
name|yaw
argument_list|,
name|roll
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|fromEulerAngles
specifier|inline
name|QQuaternion
name|QQuaternion
operator|::
name|fromEulerAngles
argument_list|(
argument|const QVector3D&eulerAngles
argument_list|)
block|{
return|return
name|QQuaternion
operator|::
name|fromEulerAngles
argument_list|(
name|eulerAngles
operator|.
name|x
argument_list|()
argument_list|,
name|eulerAngles
operator|.
name|y
argument_list|()
argument_list|,
name|eulerAngles
operator|.
name|z
argument_list|()
argument_list|)
return|;
block|}
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_expr_stmt
DECL|function|setVector
specifier|inline
name|void
name|QQuaternion
operator|::
name|setVector
argument_list|(
argument|float aX
argument_list|,
argument|float aY
argument_list|,
argument|float aZ
argument_list|)
block|{
name|xp
operator|=
name|aX
block|;
name|yp
operator|=
name|aY
block|;
name|zp
operator|=
name|aZ
block|; }
ifndef|#
directive|ifndef
name|QT_NO_VECTOR4D
DECL|function|QQuaternion
specifier|inline
name|QQuaternion
operator|::
name|QQuaternion
argument_list|(
specifier|const
name|QVector4D
operator|&
name|aVector
argument_list|)
operator|:
name|wp
argument_list|(
name|aVector
operator|.
name|w
argument_list|()
argument_list|)
operator|,
name|xp
argument_list|(
name|aVector
operator|.
name|x
argument_list|()
argument_list|)
operator|,
name|yp
argument_list|(
name|aVector
operator|.
name|y
argument_list|()
argument_list|)
operator|,
name|zp
argument_list|(
argument|aVector.z()
argument_list|)
block|{}
DECL|function|toVector4D
specifier|inline
name|QVector4D
name|QQuaternion
operator|::
name|toVector4D
argument_list|()
specifier|const
block|{
return|return
name|QVector4D
argument_list|(
name|xp
argument_list|,
name|yp
argument_list|,
name|zp
argument_list|,
name|wp
argument_list|)
return|;
block|}
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_DEBUG_STREAM
end_ifndef
begin_expr_stmt
name|Q_GUI_EXPORT
name|QDebug
name|operator
operator|<<
operator|(
name|QDebug
name|dbg
operator|,
specifier|const
name|QQuaternion
operator|&
name|q
operator|)
expr_stmt|;
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_DATASTREAM
end_ifndef
begin_expr_stmt
name|Q_GUI_EXPORT
name|QDataStream
operator|&
name|operator
operator|<<
operator|(
name|QDataStream
operator|&
operator|,
specifier|const
name|QQuaternion
operator|&
operator|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|Q_GUI_EXPORT
name|QDataStream
operator|&
name|operator
operator|>>
operator|(
name|QDataStream
operator|&
operator|,
name|QQuaternion
operator|&
operator|)
expr_stmt|;
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_endif
endif|#
directive|endif
end_endif
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
end_unit
