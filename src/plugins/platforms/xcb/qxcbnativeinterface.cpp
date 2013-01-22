begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qxcbnativeinterface.h"
end_include
begin_include
include|#
directive|include
file|"qxcbscreen.h"
end_include
begin_include
include|#
directive|include
file|<private/qguiapplication_p.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/QMap>
end_include
begin_include
include|#
directive|include
file|<QtCore/QDebug>
end_include
begin_include
include|#
directive|include
file|<QtGui/qopenglcontext.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/qscreen.h>
end_include
begin_if
if|#
directive|if
name|defined
argument_list|(
name|XCB_USE_EGL
argument_list|)
end_if
begin_include
include|#
directive|include
file|"QtPlatformSupport/private/qeglplatformcontext_p.h"
end_include
begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|XCB_USE_GLX
argument_list|)
end_elif
begin_include
include|#
directive|include
file|"qglxintegration.h"
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_class
DECL|class|QXcbResourceMap
class|class
name|QXcbResourceMap
super|:
specifier|public
name|QMap
argument_list|<
name|QByteArray
argument_list|,
name|QXcbNativeInterface
operator|::
name|ResourceType
argument_list|>
block|{
public|public:
DECL|function|QXcbResourceMap
name|QXcbResourceMap
parameter_list|()
member_init_list|:
name|QMap
argument_list|<
name|QByteArray
argument_list|,
name|QXcbNativeInterface
operator|::
name|ResourceType
argument_list|>
argument_list|()
block|{
name|insert
argument_list|(
literal|"display"
argument_list|,
name|QXcbNativeInterface
operator|::
name|Display
argument_list|)
expr_stmt|;
name|insert
argument_list|(
literal|"egldisplay"
argument_list|,
name|QXcbNativeInterface
operator|::
name|EglDisplay
argument_list|)
expr_stmt|;
name|insert
argument_list|(
literal|"connection"
argument_list|,
name|QXcbNativeInterface
operator|::
name|Connection
argument_list|)
expr_stmt|;
name|insert
argument_list|(
literal|"screen"
argument_list|,
name|QXcbNativeInterface
operator|::
name|Screen
argument_list|)
expr_stmt|;
name|insert
argument_list|(
literal|"eglcontext"
argument_list|,
name|QXcbNativeInterface
operator|::
name|EglContext
argument_list|)
expr_stmt|;
name|insert
argument_list|(
literal|"glxcontext"
argument_list|,
name|QXcbNativeInterface
operator|::
name|GLXContext
argument_list|)
expr_stmt|;
name|insert
argument_list|(
literal|"apptime"
argument_list|,
name|QXcbNativeInterface
operator|::
name|AppTime
argument_list|)
expr_stmt|;
name|insert
argument_list|(
literal|"appusertime"
argument_list|,
name|QXcbNativeInterface
operator|::
name|AppUserTime
argument_list|)
expr_stmt|;
block|}
block|}
class|;
end_class
begin_macro
name|Q_GLOBAL_STATIC
argument_list|(
argument|QXcbResourceMap
argument_list|,
argument|qXcbResourceMap
argument_list|)
end_macro
begin_constructor
DECL|function|QXcbNativeInterface
name|QXcbNativeInterface
operator|::
name|QXcbNativeInterface
parameter_list|()
member_init_list|:
name|m_genericEventFilterType
argument_list|(
name|QByteArrayLiteral
argument_list|(
literal|"xcb_generic_event_t"
argument_list|)
argument_list|)
block|{ }
end_constructor
begin_function
DECL|function|nativeResourceForContext
name|void
modifier|*
name|QXcbNativeInterface
operator|::
name|nativeResourceForContext
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|resourceString
parameter_list|,
name|QOpenGLContext
modifier|*
name|context
parameter_list|)
block|{
name|QByteArray
name|lowerCaseResource
init|=
name|resourceString
operator|.
name|toLower
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
name|qXcbResourceMap
argument_list|()
operator|->
name|contains
argument_list|(
name|lowerCaseResource
argument_list|)
condition|)
return|return
literal|0
return|;
name|ResourceType
name|resource
init|=
name|qXcbResourceMap
argument_list|()
operator|->
name|value
argument_list|(
name|lowerCaseResource
argument_list|)
decl_stmt|;
name|void
modifier|*
name|result
init|=
literal|0
decl_stmt|;
switch|switch
condition|(
name|resource
condition|)
block|{
case|case
name|EglContext
case|:
name|result
operator|=
name|eglContextForContext
argument_list|(
name|context
argument_list|)
expr_stmt|;
break|break;
case|case
name|GLXContext
case|:
name|result
operator|=
name|glxContextForContext
argument_list|(
name|context
argument_list|)
expr_stmt|;
break|break;
default|default:
break|break;
block|}
return|return
name|result
return|;
block|}
end_function
begin_function
DECL|function|nativeResourceForScreen
name|void
modifier|*
name|QXcbNativeInterface
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
specifier|const
name|QXcbResourceMap
operator|::
name|const_iterator
name|it
init|=
name|qXcbResourceMap
argument_list|()
operator|->
name|constFind
argument_list|(
name|resource
operator|.
name|toLower
argument_list|()
argument_list|)
decl_stmt|;
if|if
condition|(
name|it
operator|==
name|qXcbResourceMap
argument_list|()
operator|->
name|constEnd
argument_list|()
operator|||
operator|!
name|screen
operator|->
name|handle
argument_list|()
condition|)
return|return
literal|0
return|;
name|void
modifier|*
name|result
init|=
literal|0
decl_stmt|;
specifier|const
name|QXcbScreen
modifier|*
name|xcbScreen
init|=
cast|static_cast
argument_list|<
name|QXcbScreen
operator|*
argument_list|>
argument_list|(
name|screen
operator|->
name|handle
argument_list|()
argument_list|)
decl_stmt|;
switch|switch
condition|(
name|it
operator|.
name|value
argument_list|()
condition|)
block|{
case|case
name|Display
case|:
ifdef|#
directive|ifdef
name|XCB_USE_XLIB
name|result
operator|=
name|xcbScreen
operator|->
name|connection
argument_list|()
operator|->
name|xlib_display
argument_list|()
expr_stmt|;
endif|#
directive|endif
break|break;
case|case
name|AppTime
case|:
name|result
operator|=
name|appTime
argument_list|(
name|xcbScreen
argument_list|)
expr_stmt|;
break|break;
case|case
name|AppUserTime
case|:
name|result
operator|=
name|appUserTime
argument_list|(
name|xcbScreen
argument_list|)
expr_stmt|;
break|break;
default|default:
break|break;
block|}
return|return
name|result
return|;
block|}
end_function
begin_function
DECL|function|nativeResourceForWindow
name|void
modifier|*
name|QXcbNativeInterface
operator|::
name|nativeResourceForWindow
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|resourceString
parameter_list|,
name|QWindow
modifier|*
name|window
parameter_list|)
block|{
name|QByteArray
name|lowerCaseResource
init|=
name|resourceString
operator|.
name|toLower
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
name|qXcbResourceMap
argument_list|()
operator|->
name|contains
argument_list|(
name|lowerCaseResource
argument_list|)
condition|)
return|return
literal|0
return|;
name|ResourceType
name|resource
init|=
name|qXcbResourceMap
argument_list|()
operator|->
name|value
argument_list|(
name|lowerCaseResource
argument_list|)
decl_stmt|;
name|void
modifier|*
name|result
init|=
literal|0
decl_stmt|;
switch|switch
condition|(
name|resource
condition|)
block|{
case|case
name|Display
case|:
name|result
operator|=
name|displayForWindow
argument_list|(
name|window
argument_list|)
expr_stmt|;
break|break;
case|case
name|EglDisplay
case|:
name|result
operator|=
name|eglDisplayForWindow
argument_list|(
name|window
argument_list|)
expr_stmt|;
break|break;
case|case
name|Connection
case|:
name|result
operator|=
name|connectionForWindow
argument_list|(
name|window
argument_list|)
expr_stmt|;
break|break;
case|case
name|Screen
case|:
name|result
operator|=
name|qPlatformScreenForWindow
argument_list|(
name|window
argument_list|)
expr_stmt|;
break|break;
default|default:
break|break;
block|}
return|return
name|result
return|;
block|}
end_function
begin_function
DECL|function|nativeResourceFunctionForScreen
name|QPlatformNativeInterface
operator|::
name|NativeResourceForScreenFunction
name|QXcbNativeInterface
operator|::
name|nativeResourceFunctionForScreen
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|resource
parameter_list|)
block|{
specifier|const
name|QByteArray
name|lowerCaseResource
init|=
name|resource
operator|.
name|toLower
argument_list|()
decl_stmt|;
if|if
condition|(
name|lowerCaseResource
operator|==
literal|"setapptime"
condition|)
return|return
name|NativeResourceForScreenFunction
argument_list|(
name|setAppTime
argument_list|)
return|;
elseif|else
if|if
condition|(
name|lowerCaseResource
operator|==
literal|"setappusertime"
condition|)
return|return
name|NativeResourceForScreenFunction
argument_list|(
name|setAppUserTime
argument_list|)
return|;
return|return
literal|0
return|;
block|}
end_function
begin_function
DECL|function|appTime
name|void
modifier|*
name|QXcbNativeInterface
operator|::
name|appTime
parameter_list|(
specifier|const
name|QXcbScreen
modifier|*
name|screen
parameter_list|)
block|{
return|return
cast|reinterpret_cast
argument_list|<
name|void
operator|*
argument_list|>
argument_list|(
name|quintptr
argument_list|(
name|screen
operator|->
name|connection
argument_list|()
operator|->
name|time
argument_list|()
argument_list|)
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|appUserTime
name|void
modifier|*
name|QXcbNativeInterface
operator|::
name|appUserTime
parameter_list|(
specifier|const
name|QXcbScreen
modifier|*
name|screen
parameter_list|)
block|{
return|return
cast|reinterpret_cast
argument_list|<
name|void
operator|*
argument_list|>
argument_list|(
name|quintptr
argument_list|(
name|screen
operator|->
name|connection
argument_list|()
operator|->
name|netWmUserTime
argument_list|()
argument_list|)
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|setAppTime
name|void
name|QXcbNativeInterface
operator|::
name|setAppTime
parameter_list|(
name|QScreen
modifier|*
name|screen
parameter_list|,
name|xcb_timestamp_t
name|time
parameter_list|)
block|{
cast|static_cast
argument_list|<
name|QXcbScreen
operator|*
argument_list|>
argument_list|(
name|screen
operator|->
name|handle
argument_list|()
argument_list|)
operator|->
name|connection
argument_list|()
operator|->
name|setTime
argument_list|(
name|time
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|setAppUserTime
name|void
name|QXcbNativeInterface
operator|::
name|setAppUserTime
parameter_list|(
name|QScreen
modifier|*
name|screen
parameter_list|,
name|xcb_timestamp_t
name|time
parameter_list|)
block|{
cast|static_cast
argument_list|<
name|QXcbScreen
operator|*
argument_list|>
argument_list|(
name|screen
operator|->
name|handle
argument_list|()
argument_list|)
operator|->
name|connection
argument_list|()
operator|->
name|setNetWmUserTime
argument_list|(
name|time
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|nativeResourceFunctionForContext
name|QPlatformNativeInterface
operator|::
name|NativeResourceForContextFunction
name|QXcbNativeInterface
operator|::
name|nativeResourceFunctionForContext
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|resource
parameter_list|)
block|{
name|QByteArray
name|lowerCaseResource
init|=
name|resource
operator|.
name|toLower
argument_list|()
decl_stmt|;
if|if
condition|(
name|lowerCaseResource
operator|==
literal|"get_egl_context"
condition|)
block|{
return|return
name|eglContextForContext
return|;
block|}
return|return
literal|0
return|;
block|}
end_function
begin_function
DECL|function|qPlatformScreenForWindow
name|QXcbScreen
modifier|*
name|QXcbNativeInterface
operator|::
name|qPlatformScreenForWindow
parameter_list|(
name|QWindow
modifier|*
name|window
parameter_list|)
block|{
name|QXcbScreen
modifier|*
name|screen
decl_stmt|;
if|if
condition|(
name|window
condition|)
block|{
name|screen
operator|=
cast|static_cast
argument_list|<
name|QXcbScreen
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
expr_stmt|;
block|}
else|else
block|{
name|screen
operator|=
cast|static_cast
argument_list|<
name|QXcbScreen
operator|*
argument_list|>
argument_list|(
name|QGuiApplication
operator|::
name|primaryScreen
argument_list|()
operator|->
name|handle
argument_list|()
argument_list|)
expr_stmt|;
block|}
return|return
name|screen
return|;
block|}
end_function
begin_function
DECL|function|displayForWindow
name|void
modifier|*
name|QXcbNativeInterface
operator|::
name|displayForWindow
parameter_list|(
name|QWindow
modifier|*
name|window
parameter_list|)
block|{
if|#
directive|if
name|defined
argument_list|(
name|XCB_USE_XLIB
argument_list|)
name|QXcbScreen
modifier|*
name|screen
init|=
name|qPlatformScreenForWindow
argument_list|(
name|window
argument_list|)
decl_stmt|;
return|return
name|screen
operator|->
name|connection
argument_list|()
operator|->
name|xlib_display
argument_list|()
return|;
else|#
directive|else
name|Q_UNUSED
argument_list|(
name|window
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
endif|#
directive|endif
block|}
end_function
begin_function
DECL|function|eglDisplayForWindow
name|void
modifier|*
name|QXcbNativeInterface
operator|::
name|eglDisplayForWindow
parameter_list|(
name|QWindow
modifier|*
name|window
parameter_list|)
block|{
if|#
directive|if
name|defined
argument_list|(
name|XCB_USE_EGL
argument_list|)
name|QXcbScreen
modifier|*
name|screen
init|=
name|qPlatformScreenForWindow
argument_list|(
name|window
argument_list|)
decl_stmt|;
return|return
name|screen
operator|->
name|connection
argument_list|()
operator|->
name|egl_display
argument_list|()
return|;
else|#
directive|else
name|Q_UNUSED
argument_list|(
argument|window
argument_list|)
return|return
literal|0
return|;
endif|#
directive|endif
block|}
end_function
begin_function
DECL|function|connectionForWindow
name|void
modifier|*
name|QXcbNativeInterface
operator|::
name|connectionForWindow
parameter_list|(
name|QWindow
modifier|*
name|window
parameter_list|)
block|{
name|QXcbScreen
modifier|*
name|screen
init|=
name|qPlatformScreenForWindow
argument_list|(
name|window
argument_list|)
decl_stmt|;
return|return
name|screen
operator|->
name|xcb_connection
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|screenForWindow
name|void
modifier|*
name|QXcbNativeInterface
operator|::
name|screenForWindow
parameter_list|(
name|QWindow
modifier|*
name|window
parameter_list|)
block|{
name|QXcbScreen
modifier|*
name|screen
init|=
name|qPlatformScreenForWindow
argument_list|(
name|window
argument_list|)
decl_stmt|;
return|return
name|screen
operator|->
name|screen
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|eglContextForContext
name|void
modifier|*
name|QXcbNativeInterface
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
if|#
directive|if
name|defined
argument_list|(
name|XCB_USE_EGL
argument_list|)
name|QEGLPlatformContext
modifier|*
name|eglPlatformContext
init|=
cast|static_cast
argument_list|<
name|QEGLPlatformContext
operator|*
argument_list|>
argument_list|(
name|context
operator|->
name|handle
argument_list|()
argument_list|)
decl_stmt|;
return|return
name|eglPlatformContext
operator|->
name|eglContext
argument_list|()
return|;
else|#
directive|else
name|Q_UNUSED
argument_list|(
name|context
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
endif|#
directive|endif
block|}
end_function
begin_function
DECL|function|glxContextForContext
name|void
modifier|*
name|QXcbNativeInterface
operator|::
name|glxContextForContext
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
if|#
directive|if
name|defined
argument_list|(
name|XCB_USE_GLX
argument_list|)
name|QGLXContext
modifier|*
name|glxPlatformContext
init|=
cast|static_cast
argument_list|<
name|QGLXContext
operator|*
argument_list|>
argument_list|(
name|context
operator|->
name|handle
argument_list|()
argument_list|)
decl_stmt|;
return|return
name|glxPlatformContext
operator|->
name|glxContext
argument_list|()
return|;
else|#
directive|else
name|Q_UNUSED
argument_list|(
name|context
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
endif|#
directive|endif
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
