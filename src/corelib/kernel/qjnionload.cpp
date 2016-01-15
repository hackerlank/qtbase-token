begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<jni.h>
end_include
begin_include
include|#
directive|include
file|"qjnihelpers_p.h"
end_include
begin_function
DECL|function|JNI_OnLoad
name|Q_CORE_EXPORT
name|jint
name|JNICALL
name|JNI_OnLoad
parameter_list|(
name|JavaVM
modifier|*
name|vm
parameter_list|,
name|void
modifier|*
name|reserved
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
argument|reserved
argument_list|)
typedef|typedef
union|union
block|{
name|JNIEnv
modifier|*
name|nenv
decl_stmt|;
name|void
modifier|*
name|venv
decl_stmt|;
block|}
name|_JNIEnv
typedef|;
name|_JNIEnv
name|uenv
decl_stmt|;
name|uenv
operator|.
name|venv
operator|=
name|Q_NULLPTR
expr_stmt|;
if|if
condition|(
name|vm
operator|->
name|GetEnv
argument_list|(
operator|&
name|uenv
operator|.
name|venv
argument_list|,
name|JNI_VERSION_1_6
argument_list|)
operator|!=
name|JNI_OK
condition|)
return|return
name|JNI_ERR
return|;
name|JNIEnv
modifier|*
name|env
init|=
name|uenv
operator|.
name|nenv
decl_stmt|;
specifier|const
name|jint
name|ret
init|=
name|QT_PREPEND_NAMESPACE
argument_list|(
name|QtAndroidPrivate
operator|::
name|initJNI
argument_list|(
name|vm
argument_list|,
name|env
argument_list|)
argument_list|)
decl_stmt|;
if|if
condition|(
name|ret
operator|!=
literal|0
condition|)
return|return
name|ret
return|;
return|return
name|JNI_VERSION_1_6
return|;
block|}
end_function
end_unit
