begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qopenwfdintegration.h"
end_include
begin_include
include|#
directive|include
file|"qopenwfdscreen.h"
end_include
begin_include
include|#
directive|include
file|"qopenwfdnativeinterface.h"
end_include
begin_include
include|#
directive|include
file|"qopenwfddevice.h"
end_include
begin_include
include|#
directive|include
file|"qopenwfdwindow.h"
end_include
begin_include
include|#
directive|include
file|"qopenwfdglcontext.h"
end_include
begin_include
include|#
directive|include
file|"qopenwfdbackingstore.h"
end_include
begin_include
include|#
directive|include
file|<QtPlatformSupport/private/qgenericunixprintersupport_p.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/private/qguiapplication_p.h>
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
file|<QtPlatformSupport/private/qgenericunixeventdispatcher_p.h>
end_include
begin_include
include|#
directive|include
file|<QtPlatformSupport/private/qgenericunixfontdatabase_p.h>
end_include
begin_include
include|#
directive|include
file|<stdio.h>
end_include
begin_include
include|#
directive|include
file|<WF/wfd.h>
end_include
begin_constructor
DECL|function|QOpenWFDIntegration
name|QOpenWFDIntegration
operator|::
name|QOpenWFDIntegration
parameter_list|()
member_init_list|:
name|QPlatformIntegration
argument_list|()
member_init_list|,
name|mPrinterSupport
argument_list|(
operator|new
name|QGenericUnixPrinterSupport
argument_list|)
block|{
name|int
name|numberOfDevices
init|=
name|wfdEnumerateDevices
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
decl_stmt|;
name|WFDint
name|devices
index|[
name|numberOfDevices
index|]
decl_stmt|;
name|int
name|actualNumberOfDevices
init|=
name|wfdEnumerateDevices
argument_list|(
name|devices
argument_list|,
name|numberOfDevices
argument_list|,
literal|0
argument_list|)
decl_stmt|;
name|Q_ASSERT
argument_list|(
name|actualNumberOfDevices
operator|==
name|numberOfDevices
argument_list|)
expr_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|actualNumberOfDevices
condition|;
name|i
operator|++
control|)
block|{
name|mDevices
operator|.
name|append
argument_list|(
operator|new
name|QOpenWFDDevice
argument_list|(
name|this
argument_list|,
name|devices
index|[
name|i
index|]
argument_list|)
argument_list|)
expr_stmt|;
block|}
name|mFontDatabase
operator|=
operator|new
name|QGenericUnixFontDatabase
argument_list|()
expr_stmt|;
name|mNativeInterface
operator|=
operator|new
name|QOpenWFDNativeInterface
expr_stmt|;
block|}
end_constructor
begin_destructor
DECL|function|~QOpenWFDIntegration
name|QOpenWFDIntegration
operator|::
name|~
name|QOpenWFDIntegration
parameter_list|()
block|{
comment|//don't delete screens since they are deleted by the devices
name|qDebug
argument_list|(
literal|"deleting platform integration"
argument_list|)
expr_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|mDevices
operator|.
name|size
argument_list|()
condition|;
name|i
operator|++
control|)
block|{
operator|delete
name|mDevices
index|[
name|i
index|]
expr_stmt|;
block|}
operator|delete
name|mFontDatabase
expr_stmt|;
operator|delete
name|mNativeInterface
expr_stmt|;
operator|delete
name|mPrinterSupport
expr_stmt|;
block|}
end_destructor
begin_function
DECL|function|hasCapability
name|bool
name|QOpenWFDIntegration
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
name|OpenGL
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
name|QOpenWFDIntegration
operator|::
name|createPlatformWindow
parameter_list|(
name|QWindow
modifier|*
name|window
parameter_list|)
specifier|const
block|{
return|return
operator|new
name|QOpenWFDWindow
argument_list|(
name|window
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|createPlatformOpenGLContext
name|QPlatformOpenGLContext
modifier|*
name|QOpenWFDIntegration
operator|::
name|createPlatformOpenGLContext
parameter_list|(
name|QOpenGLContext
modifier|*
name|context
parameter_list|)
specifier|const
block|{
name|QOpenWFDScreen
modifier|*
name|screen
init|=
cast|static_cast
argument_list|<
name|QOpenWFDScreen
operator|*
argument_list|>
argument_list|(
name|context
operator|->
name|screen
argument_list|()
operator|->
name|handle
argument_list|()
argument_list|)
decl_stmt|;
return|return
operator|new
name|QOpenWFDGLContext
argument_list|(
name|screen
operator|->
name|port
argument_list|()
operator|->
name|device
argument_list|()
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|createPlatformBackingStore
name|QPlatformBackingStore
modifier|*
name|QOpenWFDIntegration
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
name|QOpenWFDBackingStore
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
name|QOpenWFDIntegration
operator|::
name|createEventDispatcher
parameter_list|()
specifier|const
block|{
return|return
name|createUnixEventDispatcher
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|fontDatabase
name|QPlatformFontDatabase
modifier|*
name|QOpenWFDIntegration
operator|::
name|fontDatabase
parameter_list|()
specifier|const
block|{
return|return
name|mFontDatabase
return|;
block|}
end_function
begin_function
DECL|function|nativeInterface
name|QPlatformNativeInterface
modifier|*
name|QOpenWFDIntegration
operator|::
name|nativeInterface
parameter_list|()
specifier|const
block|{
return|return
name|mNativeInterface
return|;
block|}
end_function
begin_function
DECL|function|printerSupport
name|QPlatformPrinterSupport
modifier|*
name|QOpenWFDIntegration
operator|::
name|printerSupport
parameter_list|()
specifier|const
block|{
return|return
name|mPrinterSupport
return|;
block|}
end_function
begin_function
DECL|function|addScreen
name|void
name|QOpenWFDIntegration
operator|::
name|addScreen
parameter_list|(
name|QOpenWFDScreen
modifier|*
name|screen
parameter_list|)
block|{
name|screenAdded
argument_list|(
name|screen
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|destroyScreen
name|void
name|QOpenWFDIntegration
operator|::
name|destroyScreen
parameter_list|(
name|QOpenWFDScreen
modifier|*
name|screen
parameter_list|)
block|{
name|QPlatformIntegration
operator|::
name|destroyScreen
argument_list|(
name|screen
argument_list|)
expr_stmt|;
block|}
end_function
end_unit
