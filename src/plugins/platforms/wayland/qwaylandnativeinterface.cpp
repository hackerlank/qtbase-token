begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qwaylandnativeinterface.h"
end_include
begin_include
include|#
directive|include
file|"qwaylanddisplay.h"
end_include
begin_include
include|#
directive|include
file|"qwaylandwindow.h"
end_include
begin_include
include|#
directive|include
file|"windowmanager_integration/qwaylandwindowmanagerintegration.h"
end_include
begin_include
include|#
directive|include
file|<QtGui/private/qapplication_p.h>
end_include
begin_include
include|#
directive|include
file|<QDebug>
end_include
begin_function
DECL|function|nativeResourceForWidget
name|void
modifier|*
name|QWaylandNativeInterface
operator|::
name|nativeResourceForWidget
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|resourceString
parameter_list|,
name|QWidget
modifier|*
name|widget
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
name|lowerCaseResource
operator|==
literal|"display"
condition|)
return|return
name|qPlatformScreenForWidget
argument_list|(
name|widget
argument_list|)
operator|->
name|display
argument_list|()
operator|->
name|wl_display
argument_list|()
return|;
if|if
condition|(
name|lowerCaseResource
operator|==
literal|"surface"
condition|)
block|{
return|return
operator|(
operator|(
name|QWaylandWindow
operator|*
operator|)
name|widget
operator|->
name|platformWindow
argument_list|()
operator|)
operator|->
name|wl_surface
argument_list|()
return|;
block|}
return|return
name|NULL
return|;
block|}
end_function
begin_function
DECL|function|qPlatformScreenForWidget
name|QWaylandScreen
modifier|*
name|QWaylandNativeInterface
operator|::
name|qPlatformScreenForWidget
parameter_list|(
name|QWidget
modifier|*
name|widget
parameter_list|)
block|{
name|QWaylandScreen
modifier|*
name|screen
decl_stmt|;
if|if
condition|(
name|widget
condition|)
block|{
name|screen
operator|=
cast|static_cast
argument_list|<
name|QWaylandScreen
operator|*
argument_list|>
argument_list|(
name|QPlatformScreen
operator|::
name|platformScreenForWidget
argument_list|(
name|widget
argument_list|)
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|screen
operator|=
cast|static_cast
argument_list|<
name|QWaylandScreen
operator|*
argument_list|>
argument_list|(
name|QApplicationPrivate
operator|::
name|platformIntegration
argument_list|()
operator|->
name|screens
argument_list|()
index|[
literal|0
index|]
argument_list|)
expr_stmt|;
block|}
return|return
name|screen
return|;
block|}
end_function
begin_function
DECL|function|windowProperties
name|QVariantMap
name|QWaylandNativeInterface
operator|::
name|windowProperties
parameter_list|(
name|QPlatformWindow
modifier|*
name|window
parameter_list|)
specifier|const
block|{
return|return
name|m_windowProperties
operator|.
name|value
argument_list|(
name|window
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|windowProperty
name|QVariant
name|QWaylandNativeInterface
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
specifier|const
name|QVariantMap
name|properties
init|=
name|m_windowProperties
operator|.
name|value
argument_list|(
name|window
argument_list|)
decl_stmt|;
return|return
name|properties
operator|.
name|value
argument_list|(
name|name
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|windowProperty
name|QVariant
name|QWaylandNativeInterface
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
name|QVariantMap
name|properties
init|=
name|m_windowProperties
operator|.
name|value
argument_list|(
name|window
argument_list|)
decl_stmt|;
return|return
name|properties
operator|.
name|value
argument_list|(
name|name
argument_list|,
name|defaultValue
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|setWindowProperty
name|void
name|QWaylandNativeInterface
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
name|QVariantMap
name|props
init|=
name|m_windowProperties
operator|.
name|value
argument_list|(
name|window
argument_list|)
decl_stmt|;
name|props
operator|.
name|insert
argument_list|(
name|name
argument_list|,
name|value
argument_list|)
expr_stmt|;
name|m_windowProperties
operator|.
name|insert
argument_list|(
name|window
argument_list|,
name|props
argument_list|)
expr_stmt|;
name|QWaylandWindow
modifier|*
name|wlWindow
init|=
cast|static_cast
argument_list|<
name|QWaylandWindow
operator|*
argument_list|>
argument_list|(
name|window
argument_list|)
decl_stmt|;
name|QWaylandWindowManagerIntegration
operator|::
name|instance
argument_list|()
operator|->
name|setWindowProperty
argument_list|(
name|wlWindow
argument_list|,
name|name
argument_list|,
name|value
argument_list|)
expr_stmt|;
emit|emit
name|windowPropertyChanged
argument_list|(
name|window
argument_list|,
name|name
argument_list|)
emit|;
block|}
end_function
end_unit
