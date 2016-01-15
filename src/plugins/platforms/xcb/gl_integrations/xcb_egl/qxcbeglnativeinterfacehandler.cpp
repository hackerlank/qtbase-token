begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qxcbeglnativeinterfacehandler.h"
end_include
begin_include
include|#
directive|include
file|<QtGui/private/qguiapplication_p.h>
end_include
begin_include
include|#
directive|include
file|"qxcbeglwindow.h"
end_include
begin_include
include|#
directive|include
file|"qxcbintegration.h"
end_include
begin_include
include|#
directive|include
file|"qxcbeglintegration.h"
end_include
begin_include
include|#
directive|include
file|"qxcbeglcontext.h"
end_include
begin_function
name|QT_BEGIN_NAMESPACE
DECL|function|resourceType
specifier|static
name|int
name|resourceType
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|key
parameter_list|)
block|{
specifier|static
specifier|const
name|QByteArray
name|names
index|[]
init|=
block|{
comment|// match QXcbEglNativeInterfaceHandler::ResourceType
name|QByteArrayLiteral
argument_list|(
literal|"egldisplay"
argument_list|)
block|,
name|QByteArrayLiteral
argument_list|(
literal|"eglcontext"
argument_list|)
block|,
name|QByteArrayLiteral
argument_list|(
literal|"eglconfig"
argument_list|)
block|}
decl_stmt|;
for|for
control|(
name|size_t
name|i
init|=
literal|0
init|;
name|i
operator|<
sizeof|sizeof
argument_list|(
name|names
argument_list|)
operator|/
sizeof|sizeof
argument_list|(
name|names
index|[
literal|0
index|]
argument_list|)
condition|;
name|i
operator|++
control|)
block|{
if|if
condition|(
name|key
operator|==
name|names
index|[
name|i
index|]
condition|)
return|return
name|i
return|;
block|}
if|if
condition|(
name|key
operator|==
name|QByteArrayLiteral
argument_list|(
literal|"get_egl_context"
argument_list|)
condition|)
return|return
name|QXcbEglNativeInterfaceHandler
operator|::
name|EglContext
return|;
return|return
sizeof|sizeof
argument_list|(
name|names
argument_list|)
operator|/
sizeof|sizeof
argument_list|(
name|names
index|[
literal|0
index|]
argument_list|)
return|;
block|}
end_function
begin_constructor
DECL|function|QXcbEglNativeInterfaceHandler
name|QXcbEglNativeInterfaceHandler
operator|::
name|QXcbEglNativeInterfaceHandler
parameter_list|(
name|QXcbNativeInterface
modifier|*
name|nativeInterface
parameter_list|)
member_init_list|:
name|QXcbNativeInterfaceHandler
argument_list|(
name|nativeInterface
argument_list|)
block|{ }
end_constructor
begin_function
DECL|function|nativeResourceFunctionForIntegration
name|QPlatformNativeInterface
operator|::
name|NativeResourceForIntegrationFunction
name|QXcbEglNativeInterfaceHandler
operator|::
name|nativeResourceFunctionForIntegration
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|resource
parameter_list|)
specifier|const
block|{
switch|switch
condition|(
name|resourceType
argument_list|(
name|resource
argument_list|)
condition|)
block|{
case|case
name|EglDisplay
case|:
return|return
name|eglDisplay
return|;
default|default:
break|break;
block|}
return|return
name|Q_NULLPTR
return|;
block|}
end_function
begin_function
DECL|function|nativeResourceFunctionForContext
name|QPlatformNativeInterface
operator|::
name|NativeResourceForContextFunction
name|QXcbEglNativeInterfaceHandler
operator|::
name|nativeResourceFunctionForContext
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|resource
parameter_list|)
specifier|const
block|{
switch|switch
condition|(
name|resourceType
argument_list|(
name|resource
argument_list|)
condition|)
block|{
case|case
name|EglContext
case|:
return|return
name|eglContextForContext
return|;
case|case
name|EglConfig
case|:
return|return
name|eglConfigForContext
return|;
default|default:
break|break;
block|}
return|return
name|Q_NULLPTR
return|;
block|}
end_function
begin_function
DECL|function|nativeResourceFunctionForWindow
name|QPlatformNativeInterface
operator|::
name|NativeResourceForWindowFunction
name|QXcbEglNativeInterfaceHandler
operator|::
name|nativeResourceFunctionForWindow
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|resource
parameter_list|)
specifier|const
block|{
switch|switch
condition|(
name|resourceType
argument_list|(
name|resource
argument_list|)
condition|)
block|{
case|case
name|EglDisplay
case|:
return|return
name|eglDisplayForWindow
return|;
default|default:
break|break;
block|}
return|return
name|Q_NULLPTR
return|;
block|}
end_function
begin_function
DECL|function|eglDisplay
name|void
modifier|*
name|QXcbEglNativeInterfaceHandler
operator|::
name|eglDisplay
parameter_list|()
block|{
name|QXcbIntegration
modifier|*
name|integration
init|=
name|QXcbIntegration
operator|::
name|instance
argument_list|()
decl_stmt|;
name|QXcbEglIntegration
modifier|*
name|eglIntegration
init|=
cast|static_cast
argument_list|<
name|QXcbEglIntegration
operator|*
argument_list|>
argument_list|(
name|integration
operator|->
name|defaultConnection
argument_list|()
operator|->
name|glIntegration
argument_list|()
argument_list|)
decl_stmt|;
return|return
name|eglIntegration
operator|->
name|eglDisplay
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|eglDisplayForWindow
name|void
modifier|*
name|QXcbEglNativeInterfaceHandler
operator|::
name|eglDisplayForWindow
parameter_list|(
name|QWindow
modifier|*
name|window
parameter_list|)
block|{
name|Q_ASSERT
argument_list|(
name|window
argument_list|)
expr_stmt|;
if|if
condition|(
name|window
operator|->
name|supportsOpenGL
argument_list|()
operator|&&
name|window
operator|->
name|handle
argument_list|()
operator|==
name|Q_NULLPTR
condition|)
return|return
name|eglDisplay
argument_list|()
return|;
elseif|else
if|if
condition|(
name|window
operator|->
name|supportsOpenGL
argument_list|()
condition|)
return|return
cast|static_cast
argument_list|<
name|QXcbEglWindow
operator|*
argument_list|>
argument_list|(
name|window
operator|->
name|handle
argument_list|()
argument_list|)
operator|->
name|glIntegration
argument_list|()
operator|->
name|eglDisplay
argument_list|()
return|;
return|return
name|Q_NULLPTR
return|;
block|}
end_function
begin_function
DECL|function|eglContextForContext
name|void
modifier|*
name|QXcbEglNativeInterfaceHandler
operator|::
name|eglContextForContext
parameter_list|(
name|QOpenGLContext
modifier|*
name|context
parameter_list|)
block|{
name|Q_ASSERT
argument_list|(
name|context
argument_list|)
expr_stmt|;
name|Q_ASSERT
argument_list|(
name|context
operator|->
name|handle
argument_list|()
argument_list|)
expr_stmt|;
return|return
cast|static_cast
argument_list|<
name|QXcbEglContext
operator|*
argument_list|>
argument_list|(
name|context
operator|->
name|handle
argument_list|()
argument_list|)
operator|->
name|eglContext
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|eglConfigForContext
name|void
modifier|*
name|QXcbEglNativeInterfaceHandler
operator|::
name|eglConfigForContext
parameter_list|(
name|QOpenGLContext
modifier|*
name|context
parameter_list|)
block|{
name|Q_ASSERT
argument_list|(
name|context
argument_list|)
expr_stmt|;
name|Q_ASSERT
argument_list|(
name|context
operator|->
name|handle
argument_list|()
argument_list|)
expr_stmt|;
return|return
cast|static_cast
argument_list|<
name|QXcbEglContext
operator|*
argument_list|>
argument_list|(
name|context
operator|->
name|handle
argument_list|()
argument_list|)
operator|->
name|eglConfig
argument_list|()
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
