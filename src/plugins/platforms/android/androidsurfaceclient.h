begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2014 BogDan Vatra<bogdan@kde.org> ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|ANDROIDSURFACECLIENT_H
end_ifndef
begin_define
DECL|macro|ANDROIDSURFACECLIENT_H
define|#
directive|define
name|ANDROIDSURFACECLIENT_H
end_define
begin_include
include|#
directive|include
file|<QMutex>
end_include
begin_include
include|#
directive|include
file|<jni.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
name|class
name|AndroidSurfaceClient
block|{
name|public
label|:
name|virtual
name|void
name|surfaceChanged
parameter_list|(
name|JNIEnv
modifier|*
name|jniEnv
parameter_list|,
name|jobject
name|surface
parameter_list|,
name|int
name|w
parameter_list|,
name|int
name|h
parameter_list|)
init|=
literal|0
function_decl|;
name|void
name|lockSurface
parameter_list|()
block|{
name|m_surfaceMutex
operator|.
name|lock
argument_list|()
expr_stmt|;
block|}
name|void
name|unlockSurface
parameter_list|()
block|{
name|m_surfaceMutex
operator|.
name|unlock
argument_list|()
expr_stmt|;
block|}
name|protected
label|:
name|QMutex
name|m_surfaceMutex
decl_stmt|;
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
begin_comment
comment|// ANDROIDSURFACECLIENT_H
end_comment
end_unit
