begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 BogDan Vatra<bogdan@kde.org> ** Contact: http://www.qt-project.org/legal ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qandroidplatformservices.h"
end_include
begin_include
include|#
directive|include
file|<QUrl>
end_include
begin_include
include|#
directive|include
file|<QDir>
end_include
begin_include
include|#
directive|include
file|<QDebug>
end_include
begin_function
name|QT_BEGIN_NAMESPACE
DECL|function|QAndroidPlatformServices
name|QAndroidPlatformServices
operator|::
name|QAndroidPlatformServices
parameter_list|()
block|{
name|QtAndroid
operator|::
name|AttachedJNIEnv
name|env
decl_stmt|;
if|if
condition|(
operator|!
name|env
operator|.
name|jniEnv
condition|)
return|return;
name|m_openURIMethodID
operator|=
name|env
operator|.
name|jniEnv
operator|->
name|GetStaticMethodID
argument_list|(
name|QtAndroid
operator|::
name|applicationClass
argument_list|()
argument_list|,
literal|"openURL"
argument_list|,
literal|"(Ljava/lang/String;)V"
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|openUrl
name|bool
name|QAndroidPlatformServices
operator|::
name|openUrl
parameter_list|(
specifier|const
name|QUrl
modifier|&
name|url
parameter_list|)
block|{
name|QtAndroid
operator|::
name|AttachedJNIEnv
name|env
decl_stmt|;
if|if
condition|(
operator|!
name|env
operator|.
name|jniEnv
condition|)
return|return
literal|false
return|;
name|jstring
name|string
init|=
name|env
operator|.
name|jniEnv
operator|->
name|NewString
argument_list|(
cast|reinterpret_cast
argument_list|<
specifier|const
name|jchar
operator|*
argument_list|>
argument_list|(
name|url
operator|.
name|toString
argument_list|()
operator|.
name|constData
argument_list|()
argument_list|)
argument_list|,
name|url
operator|.
name|toString
argument_list|()
operator|.
name|length
argument_list|()
argument_list|)
decl_stmt|;
name|env
operator|.
name|jniEnv
operator|->
name|CallStaticVoidMethod
argument_list|(
name|QtAndroid
operator|::
name|applicationClass
argument_list|()
argument_list|,
name|m_openURIMethodID
argument_list|,
name|string
argument_list|)
expr_stmt|;
name|env
operator|.
name|jniEnv
operator|->
name|DeleteLocalRef
argument_list|(
name|string
argument_list|)
expr_stmt|;
return|return
literal|true
return|;
block|}
end_function
begin_function
DECL|function|openDocument
name|bool
name|QAndroidPlatformServices
operator|::
name|openDocument
parameter_list|(
specifier|const
name|QUrl
modifier|&
name|url
parameter_list|)
block|{
return|return
name|openUrl
argument_list|(
name|url
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|desktopEnvironment
name|QByteArray
name|QAndroidPlatformServices
operator|::
name|desktopEnvironment
parameter_list|()
specifier|const
block|{
return|return
name|QByteArray
argument_list|(
literal|"Android"
argument_list|)
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
