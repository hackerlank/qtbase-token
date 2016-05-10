begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 Pier Luigi Fiorini<pierluigi.fiorini@gmail.com> ** Copyright (C) 2016 The Qt Company Ltd. ** Copyright (C) 2016 Pelagicore AG ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QEGLFSKMSGBMDEVICE_H
end_ifndef
begin_define
DECL|macro|QEGLFSKMSGBMDEVICE_H
define|#
directive|define
name|QEGLFSKMSGBMDEVICE_H
end_define
begin_include
include|#
directive|include
file|"qeglfskmsgbmcursor.h"
end_include
begin_include
include|#
directive|include
file|"qeglfskmsdevice.h"
end_include
begin_include
include|#
directive|include
file|<gbm.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QEglFSKmsScreen
name|class
name|QEglFSKmsScreen
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QEglFSKmsGbmDevice
range|:
name|public
name|QEglFSKmsDevice
block|{
name|public
operator|:
name|QEglFSKmsGbmDevice
argument_list|(
name|QEglFSKmsIntegration
operator|*
name|integration
argument_list|,
specifier|const
name|QString
operator|&
name|path
argument_list|)
block|;
name|bool
name|open
argument_list|()
name|Q_DECL_OVERRIDE
block|;
name|void
name|close
argument_list|()
name|Q_DECL_OVERRIDE
block|;
name|EGLNativeDisplayType
name|nativeDisplay
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|gbm_device
operator|*
name|gbmDevice
argument_list|()
specifier|const
block|;
name|QPlatformCursor
operator|*
name|globalCursor
argument_list|()
specifier|const
block|;
name|void
name|handleDrmEvent
argument_list|()
block|;
name|virtual
name|QEglFSKmsScreen
operator|*
name|createScreen
argument_list|(
argument|QEglFSKmsIntegration *integration
argument_list|,
argument|QEglFSKmsDevice *device
argument_list|,
argument|QEglFSKmsOutput output
argument_list|,
argument|QPoint position
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|private
operator|:
name|Q_DISABLE_COPY
argument_list|(
argument|QEglFSKmsGbmDevice
argument_list|)
name|gbm_device
operator|*
name|m_gbm_device
block|;
name|QEglFSKmsGbmCursor
operator|*
name|m_globalCursor
block|;
specifier|static
name|void
name|pageFlipHandler
argument_list|(
argument|int fd
argument_list|,
argument|unsigned int sequence
argument_list|,
argument|unsigned int tv_sec
argument_list|,
argument|unsigned int tv_usec
argument_list|,
argument|void *user_data
argument_list|)
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
begin_comment
comment|// QEGLFSKMSGBMDEVICE_H
end_comment
end_unit
