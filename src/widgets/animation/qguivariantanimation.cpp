begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtCore/qvariantanimation.h>
end_include
begin_include
include|#
directive|include
file|<private/qvariantanimation_p.h>
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_ANIMATION
end_ifndef
begin_include
include|#
directive|include
file|<QtGui/qcolor.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/qvector2d.h>
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
begin_include
include|#
directive|include
file|<QtGui/qquaternion.h>
end_include
begin_function
name|QT_BEGIN_NAMESPACE
DECL|function|_q_interpolate
specifier|template
type|<>
name|Q_INLINE_TEMPLATE
name|QColor
name|_q_interpolate
parameter_list|(
specifier|const
name|QColor
modifier|&
name|f
parameter_list|,
specifier|const
name|QColor
modifier|&
name|t
parameter_list|,
name|qreal
name|progress
parameter_list|)
block|{
return|return
name|QColor
argument_list|(
name|qBound
argument_list|(
literal|0
argument_list|,
name|_q_interpolate
argument_list|(
name|f
operator|.
name|red
argument_list|()
argument_list|,
name|t
operator|.
name|red
argument_list|()
argument_list|,
name|progress
argument_list|)
argument_list|,
literal|255
argument_list|)
argument_list|,
name|qBound
argument_list|(
literal|0
argument_list|,
name|_q_interpolate
argument_list|(
name|f
operator|.
name|green
argument_list|()
argument_list|,
name|t
operator|.
name|green
argument_list|()
argument_list|,
name|progress
argument_list|)
argument_list|,
literal|255
argument_list|)
argument_list|,
name|qBound
argument_list|(
literal|0
argument_list|,
name|_q_interpolate
argument_list|(
name|f
operator|.
name|blue
argument_list|()
argument_list|,
name|t
operator|.
name|blue
argument_list|()
argument_list|,
name|progress
argument_list|)
argument_list|,
literal|255
argument_list|)
argument_list|,
name|qBound
argument_list|(
literal|0
argument_list|,
name|_q_interpolate
argument_list|(
name|f
operator|.
name|alpha
argument_list|()
argument_list|,
name|t
operator|.
name|alpha
argument_list|()
argument_list|,
name|progress
argument_list|)
argument_list|,
literal|255
argument_list|)
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|_q_interpolate
template|template
parameter_list|<>
name|Q_INLINE_TEMPLATE
name|QQuaternion
name|_q_interpolate
parameter_list|(
specifier|const
name|QQuaternion
modifier|&
name|f
parameter_list|,
specifier|const
name|QQuaternion
modifier|&
name|t
parameter_list|,
name|qreal
name|progress
parameter_list|)
block|{
return|return
name|QQuaternion
operator|::
name|slerp
argument_list|(
name|f
argument_list|,
name|t
argument_list|,
name|progress
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|qRegisterGuiGetInterpolator
specifier|static
name|void
name|qRegisterGuiGetInterpolator
parameter_list|()
block|{
name|qRegisterAnimationInterpolator
argument_list|<
name|QColor
argument_list|>
argument_list|(
name|_q_interpolateVariant
argument_list|<
name|QColor
argument_list|>
argument_list|)
expr_stmt|;
name|qRegisterAnimationInterpolator
argument_list|<
name|QVector2D
argument_list|>
argument_list|(
name|_q_interpolateVariant
argument_list|<
name|QVector2D
argument_list|>
argument_list|)
expr_stmt|;
name|qRegisterAnimationInterpolator
argument_list|<
name|QVector3D
argument_list|>
argument_list|(
name|_q_interpolateVariant
argument_list|<
name|QVector3D
argument_list|>
argument_list|)
expr_stmt|;
name|qRegisterAnimationInterpolator
argument_list|<
name|QVector4D
argument_list|>
argument_list|(
name|_q_interpolateVariant
argument_list|<
name|QVector4D
argument_list|>
argument_list|)
expr_stmt|;
name|qRegisterAnimationInterpolator
argument_list|<
name|QQuaternion
argument_list|>
argument_list|(
name|_q_interpolateVariant
argument_list|<
name|QQuaternion
argument_list|>
argument_list|)
expr_stmt|;
block|}
end_function
begin_macro
name|Q_CONSTRUCTOR_FUNCTION
argument_list|(
argument|qRegisterGuiGetInterpolator
argument_list|)
end_macro
begin_function
DECL|function|qUnregisterGuiGetInterpolator
specifier|static
name|void
name|qUnregisterGuiGetInterpolator
parameter_list|()
block|{
comment|// casts required by Sun CC 5.5
name|qRegisterAnimationInterpolator
argument_list|<
name|QColor
argument_list|>
argument_list|(
operator|(
name|QVariant
argument_list|(
operator|*
argument_list|)
argument_list|(
specifier|const
name|QColor
operator|&
argument_list|,
specifier|const
name|QColor
operator|&
argument_list|,
name|qreal
argument_list|)
operator|)
literal|0
argument_list|)
expr_stmt|;
name|qRegisterAnimationInterpolator
argument_list|<
name|QVector2D
argument_list|>
argument_list|(
operator|(
name|QVariant
argument_list|(
operator|*
argument_list|)
argument_list|(
specifier|const
name|QVector2D
operator|&
argument_list|,
specifier|const
name|QVector2D
operator|&
argument_list|,
name|qreal
argument_list|)
operator|)
literal|0
argument_list|)
expr_stmt|;
name|qRegisterAnimationInterpolator
argument_list|<
name|QVector3D
argument_list|>
argument_list|(
operator|(
name|QVariant
argument_list|(
operator|*
argument_list|)
argument_list|(
specifier|const
name|QVector3D
operator|&
argument_list|,
specifier|const
name|QVector3D
operator|&
argument_list|,
name|qreal
argument_list|)
operator|)
literal|0
argument_list|)
expr_stmt|;
name|qRegisterAnimationInterpolator
argument_list|<
name|QVector4D
argument_list|>
argument_list|(
operator|(
name|QVariant
argument_list|(
operator|*
argument_list|)
argument_list|(
specifier|const
name|QVector4D
operator|&
argument_list|,
specifier|const
name|QVector4D
operator|&
argument_list|,
name|qreal
argument_list|)
operator|)
literal|0
argument_list|)
expr_stmt|;
name|qRegisterAnimationInterpolator
argument_list|<
name|QQuaternion
argument_list|>
argument_list|(
operator|(
name|QVariant
argument_list|(
operator|*
argument_list|)
argument_list|(
specifier|const
name|QQuaternion
operator|&
argument_list|,
specifier|const
name|QQuaternion
operator|&
argument_list|,
name|qreal
argument_list|)
operator|)
literal|0
argument_list|)
expr_stmt|;
block|}
end_function
begin_macro
name|Q_DESTRUCTOR_FUNCTION
argument_list|(
argument|qUnregisterGuiGetInterpolator
argument_list|)
end_macro
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|//QT_NO_ANIMATION
end_comment
end_unit
