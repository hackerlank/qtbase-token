begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qminimalintegration.h"
end_include
begin_include
include|#
directive|include
file|"qminimalbackingstore.h"
end_include
begin_include
include|#
directive|include
file|<QtGui/private/qpixmap_raster_p.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/private/qguiapplication_p.h>
end_include
begin_include
include|#
directive|include
file|<qpa/qplatformwindow.h>
end_include
begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|Q_OS_WIN
argument_list|)
end_if
begin_include
include|#
directive|include
file|<QtPlatformSupport/private/qgenericunixeventdispatcher_p.h>
end_include
begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|Q_OS_WINRT
argument_list|)
end_elif
begin_include
include|#
directive|include
file|<QtCore/private/qeventdispatcher_winrt_p.h>
end_include
begin_else
else|#
directive|else
end_else
begin_include
include|#
directive|include
file|<QtCore/private/qeventdispatcher_win_p.h>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_function
name|QT_BEGIN_NAMESPACE
DECL|function|QMinimalIntegration
name|QMinimalIntegration
operator|::
name|QMinimalIntegration
parameter_list|()
block|{
name|QMinimalScreen
modifier|*
name|mPrimaryScreen
init|=
operator|new
name|QMinimalScreen
argument_list|()
decl_stmt|;
name|mPrimaryScreen
operator|->
name|mGeometry
operator|=
name|QRect
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|240
argument_list|,
literal|320
argument_list|)
expr_stmt|;
name|mPrimaryScreen
operator|->
name|mDepth
operator|=
literal|32
expr_stmt|;
name|mPrimaryScreen
operator|->
name|mFormat
operator|=
name|QImage
operator|::
name|Format_ARGB32_Premultiplied
expr_stmt|;
name|screenAdded
argument_list|(
name|mPrimaryScreen
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|hasCapability
name|bool
name|QMinimalIntegration
operator|::
name|hasCapability
parameter_list|(
name|QPlatformIntegration
operator|::
name|Capability
name|cap
parameter_list|)
specifier|const
block|{
switch|switch
condition|(
name|cap
condition|)
block|{
case|case
name|ThreadedPixmaps
case|:
return|return
literal|true
return|;
case|case
name|MultipleWindows
case|:
return|return
literal|true
return|;
default|default:
return|return
name|QPlatformIntegration
operator|::
name|hasCapability
argument_list|(
name|cap
argument_list|)
return|;
block|}
block|}
end_function
begin_function
DECL|function|createPlatformWindow
name|QPlatformWindow
modifier|*
name|QMinimalIntegration
operator|::
name|createPlatformWindow
parameter_list|(
name|QWindow
modifier|*
name|window
parameter_list|)
specifier|const
block|{
name|Q_UNUSED
argument_list|(
name|window
argument_list|)
expr_stmt|;
name|QPlatformWindow
modifier|*
name|w
init|=
operator|new
name|QPlatformWindow
argument_list|(
name|window
argument_list|)
decl_stmt|;
name|w
operator|->
name|requestActivateWindow
argument_list|()
expr_stmt|;
return|return
name|w
return|;
block|}
end_function
begin_function
DECL|function|createPlatformBackingStore
name|QPlatformBackingStore
modifier|*
name|QMinimalIntegration
operator|::
name|createPlatformBackingStore
parameter_list|(
name|QWindow
modifier|*
name|window
parameter_list|)
specifier|const
block|{
return|return
operator|new
name|QMinimalBackingStore
argument_list|(
name|window
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|createEventDispatcher
name|QAbstractEventDispatcher
modifier|*
name|QMinimalIntegration
operator|::
name|createEventDispatcher
parameter_list|()
specifier|const
block|{
ifdef|#
directive|ifdef
name|Q_OS_WIN
ifndef|#
directive|ifndef
name|Q_OS_WINRT
return|return
operator|new
name|QEventDispatcherWin32
return|;
else|#
directive|else
comment|// !Q_OS_WINRT
return|return
operator|new
name|QEventDispatcherWinRT
return|;
endif|#
directive|endif
comment|// Q_OS_WINRT
else|#
directive|else
return|return
name|createUnixEventDispatcher
argument_list|()
return|;
endif|#
directive|endif
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
