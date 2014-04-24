begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2014 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qwindowsnativeinterface.h"
end_include
begin_include
include|#
directive|include
file|"qwindowswindow.h"
end_include
begin_include
include|#
directive|include
file|"qwindowscontext.h"
end_include
begin_include
include|#
directive|include
file|"qwindowsopenglcontext.h"
end_include
begin_include
include|#
directive|include
file|"qwindowsintegration.h"
end_include
begin_include
include|#
directive|include
file|<QtGui/QWindow>
end_include
begin_include
include|#
directive|include
file|<QtGui/QOpenGLContext>
end_include
begin_function
name|QT_BEGIN_NAMESPACE
DECL|function|nativeResourceForWindow
name|void
modifier|*
name|QWindowsNativeInterface
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
operator|!
name|window
operator|||
operator|!
name|window
operator|->
name|handle
argument_list|()
condition|)
block|{
name|qWarning
argument_list|(
literal|"%s: '%s' requested for null window or window without handle."
argument_list|,
name|__FUNCTION__
argument_list|,
name|resource
operator|.
name|constData
argument_list|()
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
name|QWindowsWindow
modifier|*
name|bw
init|=
cast|static_cast
argument_list|<
name|QWindowsWindow
operator|*
argument_list|>
argument_list|(
name|window
operator|->
name|handle
argument_list|()
argument_list|)
decl_stmt|;
if|if
condition|(
name|resource
operator|==
literal|"handle"
condition|)
return|return
name|bw
operator|->
name|handle
argument_list|()
return|;
switch|switch
condition|(
name|window
operator|->
name|surfaceType
argument_list|()
condition|)
block|{
case|case
name|QWindow
operator|::
name|RasterSurface
case|:
case|case
name|QWindow
operator|::
name|RasterGLSurface
case|:
if|if
condition|(
name|resource
operator|==
literal|"getDC"
condition|)
return|return
name|bw
operator|->
name|getDC
argument_list|()
return|;
if|if
condition|(
name|resource
operator|==
literal|"releaseDC"
condition|)
block|{
name|bw
operator|->
name|releaseDC
argument_list|()
expr_stmt|;
return|return
literal|0
return|;
block|}
break|break;
case|case
name|QWindow
operator|::
name|OpenGLSurface
case|:
break|break;
block|}
name|qWarning
argument_list|(
literal|"%s: Invalid key '%s' requested."
argument_list|,
name|__FUNCTION__
argument_list|,
name|resource
operator|.
name|constData
argument_list|()
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function
begin_decl_stmt
DECL|variable|customMarginPropertyC
specifier|static
specifier|const
name|char
name|customMarginPropertyC
index|[]
init|=
literal|"WindowsCustomMargins"
decl_stmt|;
end_decl_stmt
begin_function
DECL|function|windowProperty
name|QVariant
name|QWindowsNativeInterface
operator|::
name|windowProperty
parameter_list|(
name|QPlatformWindow
modifier|*
name|window
parameter_list|,
specifier|const
name|QString
modifier|&
name|name
parameter_list|)
specifier|const
block|{
name|QWindowsWindow
modifier|*
name|platformWindow
init|=
cast|static_cast
argument_list|<
name|QWindowsWindow
operator|*
argument_list|>
argument_list|(
name|window
argument_list|)
decl_stmt|;
if|if
condition|(
name|name
operator|==
name|QLatin1String
argument_list|(
name|customMarginPropertyC
argument_list|)
condition|)
return|return
name|qVariantFromValue
argument_list|(
name|platformWindow
operator|->
name|customMargins
argument_list|()
argument_list|)
return|;
return|return
name|QVariant
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|windowProperty
name|QVariant
name|QWindowsNativeInterface
operator|::
name|windowProperty
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
name|defaultValue
parameter_list|)
specifier|const
block|{
specifier|const
name|QVariant
name|result
init|=
name|windowProperty
argument_list|(
name|window
argument_list|,
name|name
argument_list|)
decl_stmt|;
return|return
name|result
operator|.
name|isValid
argument_list|()
condition|?
name|result
else|:
name|defaultValue
return|;
block|}
end_function
begin_function
DECL|function|setWindowProperty
name|void
name|QWindowsNativeInterface
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
name|QWindowsWindow
modifier|*
name|platformWindow
init|=
cast|static_cast
argument_list|<
name|QWindowsWindow
operator|*
argument_list|>
argument_list|(
name|window
argument_list|)
decl_stmt|;
if|if
condition|(
name|name
operator|==
name|QLatin1String
argument_list|(
name|customMarginPropertyC
argument_list|)
condition|)
name|platformWindow
operator|->
name|setCustomMargins
argument_list|(
name|qvariant_cast
argument_list|<
name|QMargins
argument_list|>
argument_list|(
name|value
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|windowProperties
name|QVariantMap
name|QWindowsNativeInterface
operator|::
name|windowProperties
parameter_list|(
name|QPlatformWindow
modifier|*
name|window
parameter_list|)
specifier|const
block|{
name|QVariantMap
name|result
decl_stmt|;
specifier|const
name|QString
name|customMarginProperty
init|=
name|QLatin1String
argument_list|(
name|customMarginPropertyC
argument_list|)
decl_stmt|;
name|result
operator|.
name|insert
argument_list|(
name|customMarginProperty
argument_list|,
name|windowProperty
argument_list|(
name|window
argument_list|,
name|customMarginProperty
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|result
return|;
block|}
end_function
begin_function
DECL|function|nativeResourceForIntegration
name|void
modifier|*
name|QWindowsNativeInterface
operator|::
name|nativeResourceForIntegration
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|resource
parameter_list|)
block|{
ifndef|#
directive|ifndef
name|QT_NO_OPENGL
if|if
condition|(
name|resource
operator|==
name|QByteArrayLiteral
argument_list|(
literal|"glhandle"
argument_list|)
condition|)
return|return
name|QWindowsIntegration
operator|::
name|staticOpenGLContext
argument_list|()
operator|->
name|moduleHandle
argument_list|()
return|;
endif|#
directive|endif
return|return
literal|0
return|;
block|}
end_function
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_OPENGL
end_ifndef
begin_function
DECL|function|nativeResourceForContext
name|void
modifier|*
name|QWindowsNativeInterface
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
operator|!
name|context
operator|||
operator|!
name|context
operator|->
name|handle
argument_list|()
condition|)
block|{
name|qWarning
argument_list|(
literal|"%s: '%s' requested for null context or context without handle."
argument_list|,
name|__FUNCTION__
argument_list|,
name|resource
operator|.
name|constData
argument_list|()
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
name|QWindowsOpenGLContext
modifier|*
name|glcontext
init|=
cast|static_cast
argument_list|<
name|QWindowsOpenGLContext
operator|*
argument_list|>
argument_list|(
name|context
operator|->
name|handle
argument_list|()
argument_list|)
decl_stmt|;
if|if
condition|(
name|resource
operator|==
name|QByteArrayLiteral
argument_list|(
literal|"renderingContext"
argument_list|)
operator|||
name|resource
operator|==
name|QByteArrayLiteral
argument_list|(
literal|"eglContext"
argument_list|)
condition|)
return|return
name|glcontext
operator|->
name|nativeContext
argument_list|()
return|;
if|if
condition|(
name|resource
operator|==
name|QByteArrayLiteral
argument_list|(
literal|"eglDisplay"
argument_list|)
condition|)
return|return
name|glcontext
operator|->
name|nativeDisplay
argument_list|()
return|;
if|if
condition|(
name|resource
operator|==
name|QByteArrayLiteral
argument_list|(
literal|"eglConfig"
argument_list|)
condition|)
return|return
name|glcontext
operator|->
name|nativeConfig
argument_list|()
return|;
name|qWarning
argument_list|(
literal|"%s: Invalid key '%s' requested."
argument_list|,
name|__FUNCTION__
argument_list|,
name|resource
operator|.
name|constData
argument_list|()
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// !QT_NO_OPENGL
end_comment
begin_comment
comment|/*!     \brief Creates a non-visible window handle for filtering messages. */
end_comment
begin_function
DECL|function|createMessageWindow
name|void
modifier|*
name|QWindowsNativeInterface
operator|::
name|createMessageWindow
parameter_list|(
specifier|const
name|QString
modifier|&
name|classNameTemplate
parameter_list|,
specifier|const
name|QString
modifier|&
name|windowName
parameter_list|,
name|void
modifier|*
name|eventProc
parameter_list|)
specifier|const
block|{
name|QWindowsContext
modifier|*
name|ctx
init|=
name|QWindowsContext
operator|::
name|instance
argument_list|()
decl_stmt|;
specifier|const
name|HWND
name|hwnd
init|=
name|ctx
operator|->
name|createDummyWindow
argument_list|(
name|classNameTemplate
argument_list|,
operator|(
name|wchar_t
operator|*
operator|)
name|windowName
operator|.
name|utf16
argument_list|()
argument_list|,
operator|(
name|WNDPROC
operator|)
name|eventProc
argument_list|)
decl_stmt|;
return|return
name|hwnd
return|;
block|}
end_function
begin_comment
comment|/*!     \brief Registers a unique window class with a callback function based on \a classNameIn. */
end_comment
begin_function
DECL|function|registerWindowClass
name|QString
name|QWindowsNativeInterface
operator|::
name|registerWindowClass
parameter_list|(
specifier|const
name|QString
modifier|&
name|classNameIn
parameter_list|,
name|void
modifier|*
name|eventProc
parameter_list|)
specifier|const
block|{
return|return
name|QWindowsContext
operator|::
name|instance
argument_list|()
operator|->
name|registerWindowClass
argument_list|(
name|classNameIn
argument_list|,
operator|(
name|WNDPROC
operator|)
name|eventProc
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|asyncExpose
name|bool
name|QWindowsNativeInterface
operator|::
name|asyncExpose
parameter_list|()
specifier|const
block|{
return|return
name|QWindowsContext
operator|::
name|instance
argument_list|()
operator|->
name|asyncExpose
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|setAsyncExpose
name|void
name|QWindowsNativeInterface
operator|::
name|setAsyncExpose
parameter_list|(
name|bool
name|value
parameter_list|)
block|{
name|QWindowsContext
operator|::
name|instance
argument_list|()
operator|->
name|setAsyncExpose
argument_list|(
name|value
argument_list|)
expr_stmt|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
