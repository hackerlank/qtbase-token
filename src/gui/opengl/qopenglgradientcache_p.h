begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QOPENGLGRADIENTCACHE_P_H
end_ifndef
begin_define
DECL|macro|QOPENGLGRADIENTCACHE_P_H
define|#
directive|define
name|QOPENGLGRADIENTCACHE_P_H
end_define
begin_comment
comment|//
end_comment
begin_comment
comment|//  W A R N I N G
end_comment
begin_comment
comment|//  -------------
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|// This file is not part of the Qt API.  It exists purely as an
end_comment
begin_comment
comment|// implementation detail.  This header file may change from version to
end_comment
begin_comment
comment|// version without notice, or even be removed.
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|// We mean it.
end_comment
begin_comment
comment|//
end_comment
begin_include
include|#
directive|include
file|<QMultiHash>
end_include
begin_include
include|#
directive|include
file|<QObject>
end_include
begin_include
include|#
directive|include
file|<private/qopenglcontext_p.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qmutex.h>
end_include
begin_include
include|#
directive|include
file|<QGradient>
end_include
begin_include
include|#
directive|include
file|<qrgba64.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
name|class
name|QOpenGL2GradientCache
range|:
name|public
name|QOpenGLSharedResource
block|{     struct
name|CacheInfo
block|{
specifier|inline
name|CacheInfo
argument_list|(
argument|QGradientStops s
argument_list|,
argument|qreal op
argument_list|,
argument|QGradient::InterpolationMode mode
argument_list|)
operator|:
name|stops
argument_list|(
name|qMove
argument_list|(
name|s
argument_list|)
argument_list|)
block|,
name|opacity
argument_list|(
name|op
argument_list|)
block|,
name|interpolationMode
argument_list|(
argument|mode
argument_list|)
block|{}
name|GLuint
name|texId
block|;
name|QGradientStops
name|stops
block|;
name|qreal
name|opacity
block|;
name|QGradient
operator|::
name|InterpolationMode
name|interpolationMode
block|;     }
block|;
typedef|typedef
name|QMultiHash
operator|<
name|quint64
operator|,
name|CacheInfo
operator|>
name|QOpenGLGradientColorTableHash
expr_stmt|;
name|public
operator|:
specifier|static
name|QOpenGL2GradientCache
operator|*
name|cacheForContext
argument_list|(
name|QOpenGLContext
operator|*
name|context
argument_list|)
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|QOpenGL2GradientCache
argument_list|(
name|QOpenGLContext
operator|*
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
operator|~
name|QOpenGL2GradientCache
argument_list|()
expr_stmt|;
end_expr_stmt
begin_function_decl
name|GLuint
name|getBuffer
parameter_list|(
specifier|const
name|QGradient
modifier|&
name|gradient
parameter_list|,
name|qreal
name|opacity
parameter_list|)
function_decl|;
end_function_decl
begin_expr_stmt
specifier|inline
name|int
name|paletteSize
argument_list|()
specifier|const
block|{
return|return
literal|1024
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|void
name|invalidateResource
argument_list|()
name|Q_DECL_OVERRIDE
expr_stmt|;
end_expr_stmt
begin_decl_stmt
name|void
name|freeResource
argument_list|(
name|QOpenGLContext
operator|*
name|ctx
argument_list|)
name|Q_DECL_OVERRIDE
decl_stmt|;
end_decl_stmt
begin_label
name|private
label|:
end_label
begin_expr_stmt
specifier|inline
name|int
name|maxCacheSize
argument_list|()
specifier|const
block|{
return|return
literal|60
return|;
block|}
end_expr_stmt
begin_decl_stmt
specifier|inline
name|void
name|generateGradientColorTable
argument_list|(
specifier|const
name|QGradient
operator|&
name|gradient
argument_list|,
name|QRgba64
operator|*
name|colorTable
argument_list|,
name|int
name|size
argument_list|,
name|qreal
name|opacity
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt
begin_decl_stmt
specifier|inline
name|void
name|generateGradientColorTable
argument_list|(
specifier|const
name|QGradient
operator|&
name|gradient
argument_list|,
name|uint
operator|*
name|colorTable
argument_list|,
name|int
name|size
argument_list|,
name|qreal
name|opacity
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt
begin_function_decl
name|GLuint
name|addCacheElement
parameter_list|(
name|quint64
name|hash_val
parameter_list|,
specifier|const
name|QGradient
modifier|&
name|gradient
parameter_list|,
name|qreal
name|opacity
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|cleanCache
parameter_list|()
function_decl|;
end_function_decl
begin_decl_stmt
name|QOpenGLGradientColorTableHash
name|cache
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QMutex
name|m_mutex
decl_stmt|;
end_decl_stmt
begin_macro
unit|};
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QOPENGLGRADIENTCACHE_P_H
end_comment
end_unit
