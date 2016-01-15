begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
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
begin_ifndef
ifndef|#
directive|ifndef
name|QOPENGLSHADERCACHE_P_H
end_ifndef
begin_define
DECL|macro|QOPENGLSHADERCACHE_P_H
define|#
directive|define
name|QOPENGLSHADERCACHE_P_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qglobal.h>
end_include
begin_if
if|#
directive|if
name|defined
argument_list|(
name|QT_MEEGO_EXPERIMENTAL_SHADERCACHE
argument_list|)
operator|&&
name|defined
argument_list|(
name|QT_OPENGL_ES_2
argument_list|)
end_if
begin_include
include|#
directive|include
file|"qopenglshadercache_meego_p.h"
end_include
begin_else
else|#
directive|else
end_else
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QOpenGLShaderProgram
name|class
name|QOpenGLShaderProgram
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QOpenGLContext
name|class
name|QOpenGLContext
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|CachedShader
block|{
name|public
label|:
specifier|inline
name|CachedShader
argument_list|(
argument|const QByteArray&
argument_list|,
argument|const QByteArray&
argument_list|)
block|{}
specifier|inline
name|bool
name|isCached
argument_list|()
block|{
return|return
name|false
return|;
block|}
specifier|inline
name|bool
name|load
parameter_list|(
name|QOpenGLShaderProgram
modifier|*
parameter_list|,
name|QOpenGLContext
modifier|*
parameter_list|)
block|{
return|return
name|false
return|;
block|}
specifier|inline
name|bool
name|store
parameter_list|(
name|QOpenGLShaderProgram
modifier|*
parameter_list|,
name|QOpenGLContext
modifier|*
parameter_list|)
block|{
return|return
name|false
return|;
block|}
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_endif
endif|#
directive|endif
end_endif
end_unit
