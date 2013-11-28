begin_unit
begin_comment
comment|/*************************************************************************** ** ** Copyright (C) 2012 Research In Motion ** Contact: http://www.qt-project.org/legal ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qqnxnativeinterface.h"
end_include
begin_include
include|#
directive|include
file|"qqnxglcontext.h"
end_include
begin_include
include|#
directive|include
file|"qqnxscreen.h"
end_include
begin_include
include|#
directive|include
file|"qqnxwindow.h"
end_include
begin_include
include|#
directive|include
file|<QtGui/QOpenGLContext>
end_include
begin_include
include|#
directive|include
file|<QtGui/QScreen>
end_include
begin_include
include|#
directive|include
file|<QtGui/QWindow>
end_include
begin_function
name|QT_BEGIN_NAMESPACE
DECL|function|nativeResourceForWindow
name|void
modifier|*
name|QQnxNativeInterface
operator|::
name|nativeResourceForWindow
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|resource
parameter_list|,
name|QWindow
modifier|*
name|window
parameter_list|)
block|{
if|if
condition|(
name|resource
operator|==
literal|"windowGroup"
operator|&&
name|window
operator|&&
name|window
operator|->
name|screen
argument_list|()
condition|)
block|{
name|QQnxScreen
modifier|*
specifier|const
name|screen
init|=
cast|static_cast
argument_list|<
name|QQnxScreen
operator|*
argument_list|>
argument_list|(
name|window
operator|->
name|screen
argument_list|()
operator|->
name|handle
argument_list|()
argument_list|)
decl_stmt|;
if|if
condition|(
name|screen
condition|)
block|{
name|screen_window_t
name|screenWindow
init|=
cast|reinterpret_cast
argument_list|<
name|screen_window_t
argument_list|>
argument_list|(
name|window
operator|->
name|winId
argument_list|()
argument_list|)
decl_stmt|;
name|QQnxWindow
modifier|*
name|qnxWindow
init|=
name|screen
operator|->
name|findWindow
argument_list|(
name|screenWindow
argument_list|)
decl_stmt|;
comment|// We can't just call data() instead of constData() here, since that would detach
comment|// and the lifetime of the char * would not be long enough. Therefore the const_cast.
return|return
name|qnxWindow
condition|?
cast|const_cast
argument_list|<
name|char
operator|*
argument_list|>
argument_list|(
name|qnxWindow
operator|->
name|groupName
argument_list|()
operator|.
name|constData
argument_list|()
argument_list|)
else|:
literal|0
return|;
block|}
block|}
return|return
literal|0
return|;
block|}
end_function
begin_function
DECL|function|nativeResourceForScreen
name|void
modifier|*
name|QQnxNativeInterface
operator|::
name|nativeResourceForScreen
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|resource
parameter_list|,
name|QScreen
modifier|*
name|screen
parameter_list|)
block|{
if|if
condition|(
name|resource
operator|==
literal|"QObject*"
operator|&&
name|screen
condition|)
return|return
cast|static_cast
argument_list|<
name|QObject
operator|*
argument_list|>
argument_list|(
cast|static_cast
argument_list|<
name|QQnxScreen
operator|*
argument_list|>
argument_list|(
name|screen
operator|->
name|handle
argument_list|()
argument_list|)
argument_list|)
return|;
return|return
literal|0
return|;
block|}
end_function
begin_function
DECL|function|nativeResourceForContext
name|void
modifier|*
name|QQnxNativeInterface
operator|::
name|nativeResourceForContext
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|resource
parameter_list|,
name|QOpenGLContext
modifier|*
name|context
parameter_list|)
block|{
if|if
condition|(
name|resource
operator|==
literal|"eglcontext"
operator|&&
name|context
condition|)
return|return
cast|static_cast
argument_list|<
name|QQnxGLContext
operator|*
argument_list|>
argument_list|(
name|context
operator|->
name|handle
argument_list|()
argument_list|)
operator|->
name|getEglContext
argument_list|()
return|;
return|return
literal|0
return|;
block|}
end_function
begin_function
DECL|function|setWindowProperty
name|void
name|QQnxNativeInterface
operator|::
name|setWindowProperty
parameter_list|(
name|QPlatformWindow
modifier|*
name|window
parameter_list|,
specifier|const
name|QString
modifier|&
name|name
parameter_list|,
specifier|const
name|QVariant
modifier|&
name|value
parameter_list|)
block|{
if|if
condition|(
name|name
operator|==
name|QStringLiteral
argument_list|(
literal|"mmRendererWindowName"
argument_list|)
condition|)
block|{
name|QQnxWindow
modifier|*
name|qnxWindow
init|=
cast|static_cast
argument_list|<
name|QQnxWindow
operator|*
argument_list|>
argument_list|(
name|window
argument_list|)
decl_stmt|;
name|qnxWindow
operator|->
name|setMMRendererWindowName
argument_list|(
name|value
operator|.
name|toString
argument_list|()
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
