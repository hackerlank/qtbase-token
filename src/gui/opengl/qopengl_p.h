begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QOPENGL_P_H
end_ifndef
begin_define
DECL|macro|QOPENGL_P_H
define|#
directive|define
name|QOPENGL_P_H
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
file|<qopengl.h>
end_include
begin_include
include|#
directive|include
file|<private/qopenglcontext_p.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qset.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qstring.h>
end_include
begin_include
include|#
directive|include
file|<private/qversionnumber_p.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QJsonDocument
name|class
name|QJsonDocument
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_GUI_EXPORT
name|QOpenGLExtensionMatcher
block|{
name|public
label|:
name|QOpenGLExtensionMatcher
argument_list|()
expr_stmt|;
name|bool
name|match
argument_list|(
specifier|const
name|QByteArray
operator|&
name|extension
argument_list|)
decl|const
block|{
return|return
name|m_extensions
operator|.
name|contains
argument_list|(
name|extension
argument_list|)
return|;
block|}
name|QSet
operator|<
name|QByteArray
operator|>
name|extensions
argument_list|()
specifier|const
block|{
return|return
name|m_extensions
return|;
block|}
name|private
label|:
name|QSet
operator|<
name|QByteArray
operator|>
name|m_extensions
expr_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_decl_stmt
name|class
name|Q_GUI_EXPORT
name|QOpenGLConfig
block|{
name|public
label|:
struct|struct
name|Gpu
block|{
name|Gpu
argument_list|()
operator|:
name|vendorId
argument_list|(
literal|0
argument_list|)
operator|,
name|deviceId
argument_list|(
literal|0
argument_list|)
block|{}
name|bool
name|isValid
argument_list|()
specifier|const
block|{
return|return
name|deviceId
return|;
block|}
name|bool
name|equals
argument_list|(
specifier|const
name|Gpu
operator|&
name|other
argument_list|)
decl|const
block|{
return|return
name|vendorId
operator|==
name|other
operator|.
name|vendorId
operator|&&
name|deviceId
operator|==
name|other
operator|.
name|deviceId
operator|&&
name|driverVersion
operator|==
name|other
operator|.
name|driverVersion
return|;
block|}
name|uint
name|vendorId
decl_stmt|;
name|uint
name|deviceId
decl_stmt|;
name|QVersionNumber
name|driverVersion
decl_stmt|;
block|}
struct|;
specifier|static
name|QSet
operator|<
name|QString
operator|>
name|gpuFeatures
argument_list|(
specifier|const
name|Gpu
operator|&
name|gpu
argument_list|,
specifier|const
name|QString
operator|&
name|osName
argument_list|,
specifier|const
name|QVersionNumber
operator|&
name|kernelVersion
argument_list|,
specifier|const
name|QJsonDocument
operator|&
name|doc
argument_list|)
expr_stmt|;
specifier|static
name|QSet
operator|<
name|QString
operator|>
name|gpuFeatures
argument_list|(
specifier|const
name|Gpu
operator|&
name|gpu
argument_list|,
specifier|const
name|QString
operator|&
name|osName
argument_list|,
specifier|const
name|QVersionNumber
operator|&
name|kernelVersion
argument_list|,
specifier|const
name|QString
operator|&
name|fileName
argument_list|)
expr_stmt|;
specifier|static
name|QSet
operator|<
name|QString
operator|>
name|gpuFeatures
argument_list|(
specifier|const
name|Gpu
operator|&
name|gpu
argument_list|,
specifier|const
name|QJsonDocument
operator|&
name|doc
argument_list|)
expr_stmt|;
specifier|static
name|QSet
operator|<
name|QString
operator|>
name|gpuFeatures
argument_list|(
specifier|const
name|Gpu
operator|&
name|gpu
argument_list|,
specifier|const
name|QString
operator|&
name|fileName
argument_list|)
expr_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_expr_stmt
DECL|function|operator
specifier|inline
name|bool
name|operator
operator|==
operator|(
specifier|const
name|QOpenGLConfig
operator|::
name|Gpu
operator|&
name|a
operator|,
specifier|const
name|QOpenGLConfig
operator|::
name|Gpu
operator|&
name|b
operator|)
block|{
return|return
name|a
operator|.
name|equals
argument_list|(
name|b
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|operator
specifier|inline
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|QOpenGLConfig
operator|::
name|Gpu
operator|&
name|a
operator|,
specifier|const
name|QOpenGLConfig
operator|::
name|Gpu
operator|&
name|b
operator|)
block|{
return|return
operator|!
name|a
operator|.
name|equals
argument_list|(
name|b
argument_list|)
return|;
block|}
end_expr_stmt
begin_decl_stmt
DECL|function|qHash
specifier|inline
name|uint
name|qHash
argument_list|(
specifier|const
name|QOpenGLConfig
operator|::
name|Gpu
operator|&
name|gpu
argument_list|)
block|{
return|return
name|qHash
argument_list|(
name|gpu
operator|.
name|vendorId
argument_list|)
operator|+
name|qHash
argument_list|(
name|gpu
operator|.
name|deviceId
argument_list|)
operator|+
name|qHash
argument_list|(
name|gpu
operator|.
name|driverVersion
argument_list|)
return|;
block|}
end_decl_stmt
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QOPENGL_H
end_comment
end_unit
