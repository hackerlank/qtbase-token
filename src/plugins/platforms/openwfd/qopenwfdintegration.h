begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QOPENWFDINTEGRATION_H
end_ifndef
begin_define
DECL|macro|QOPENWFDINTEGRATION_H
define|#
directive|define
name|QOPENWFDINTEGRATION_H
end_define
begin_include
include|#
directive|include
file|<qpa/qplatformintegration.h>
end_include
begin_include
include|#
directive|include
file|<qpa/qplatformscreen.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QOpenWFDDevice
name|class
name|QOpenWFDDevice
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QOpenWFDScreen
name|class
name|QOpenWFDScreen
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QOpenWFDIntegration
range|:
name|public
name|QPlatformIntegration
block|{
name|public
operator|:
name|QOpenWFDIntegration
argument_list|()
block|;
operator|~
name|QOpenWFDIntegration
argument_list|()
block|;
name|bool
name|hasCapability
argument_list|(
argument|Capability cap
argument_list|)
specifier|const
block|;
name|QPlatformWindow
operator|*
name|createPlatformWindow
argument_list|(
argument|QWindow *window
argument_list|)
specifier|const
block|;
name|QPlatformBackingStore
operator|*
name|createPlatformBackingStore
argument_list|(
argument|QWindow *window
argument_list|)
specifier|const
block|;
name|QPlatformOpenGLContext
operator|*
name|createPlatformOpenGLContext
argument_list|(
argument|QOpenGLContext *context
argument_list|)
specifier|const
block|;
comment|//This should not be a factory interface, but rather a accessor
name|QAbstractEventDispatcher
operator|*
name|createEventDispatcher
argument_list|()
specifier|const
block|;
name|QPlatformFontDatabase
operator|*
name|fontDatabase
argument_list|()
specifier|const
block|;
name|QPlatformNativeInterface
operator|*
name|nativeInterface
argument_list|()
specifier|const
block|;
name|QPlatformPrinterSupport
operator|*
name|printerSupport
argument_list|()
specifier|const
block|;
name|void
name|addScreen
argument_list|(
name|QOpenWFDScreen
operator|*
name|screen
argument_list|)
block|;
name|void
name|destroyScreen
argument_list|(
name|QOpenWFDScreen
operator|*
name|screen
argument_list|)
block|;
name|private
operator|:
name|QList
operator|<
name|QPlatformScreen
operator|*
operator|>
name|mScreens
block|;
name|QList
operator|<
name|QOpenWFDDevice
operator|*
operator|>
name|mDevices
block|;
name|QPlatformFontDatabase
operator|*
name|mFontDatabase
block|;
name|QPlatformNativeInterface
operator|*
name|mNativeInterface
block|;
name|QPlatformPrinterSupport
operator|*
name|mPrinterSupport
block|; }
decl_stmt|;
end_decl_stmt
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
end_unit
