begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QDEVICEDISCOVERY_H
end_ifndef
begin_define
DECL|macro|QDEVICEDISCOVERY_H
define|#
directive|define
name|QDEVICEDISCOVERY_H
end_define
begin_comment
comment|//
end_comment
begin_comment
comment|//  W A R N I N G
end_comment
begin_comment
comment|//  -------------
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|// This file is not part of the Qt API.  It exists purely as an
end_comment
begin_comment
comment|// implementation detail.  This header file may change from version to
end_comment
begin_comment
comment|// version without notice, or even be removed.
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|// We mean it.
end_comment
begin_comment
comment|//
end_comment
begin_include
include|#
directive|include
file|<QObject>
end_include
begin_include
include|#
directive|include
file|<QSocketNotifier>
end_include
begin_include
include|#
directive|include
file|<QStringList>
end_include
begin_define
DECL|macro|QT_EVDEV_DEVICE_PATH
define|#
directive|define
name|QT_EVDEV_DEVICE_PATH
value|"/dev/input/"
end_define
begin_define
DECL|macro|QT_EVDEV_DEVICE_PREFIX
define|#
directive|define
name|QT_EVDEV_DEVICE_PREFIX
value|"event"
end_define
begin_define
DECL|macro|QT_EVDEV_DEVICE
define|#
directive|define
name|QT_EVDEV_DEVICE
value|QT_EVDEV_DEVICE_PATH QT_EVDEV_DEVICE_PREFIX
end_define
begin_define
DECL|macro|QT_DRM_DEVICE_PATH
define|#
directive|define
name|QT_DRM_DEVICE_PATH
value|"/dev/dri/"
end_define
begin_define
DECL|macro|QT_DRM_DEVICE_PREFIX
define|#
directive|define
name|QT_DRM_DEVICE_PREFIX
value|"card"
end_define
begin_define
DECL|macro|QT_DRM_DEVICE
define|#
directive|define
name|QT_DRM_DEVICE
value|QT_DRM_DEVICE_PATH QT_DRM_DEVICE_PREFIX
end_define
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
name|class
name|QDeviceDiscovery
range|:
name|public
name|QObject
block|{
name|Q_OBJECT
name|Q_ENUMS
argument_list|(
argument|QDeviceType
argument_list|)
name|public
operator|:
expr|enum
name|QDeviceType
block|{
name|Device_Unknown
operator|=
literal|0x00
block|,
name|Device_Mouse
operator|=
literal|0x01
block|,
name|Device_Touchpad
operator|=
literal|0x02
block|,
name|Device_Touchscreen
operator|=
literal|0x04
block|,
name|Device_Keyboard
operator|=
literal|0x08
block|,
name|Device_DRM
operator|=
literal|0x10
block|,
name|Device_DRM_PrimaryGPU
operator|=
literal|0x20
block|,
name|Device_Tablet
operator|=
literal|0x40
block|,
name|Device_Joystick
operator|=
literal|0x80
block|,
name|Device_InputMask
operator|=
name|Device_Mouse
operator||
name|Device_Touchpad
operator||
name|Device_Touchscreen
operator||
name|Device_Keyboard
operator||
name|Device_Tablet
operator||
name|Device_Joystick
block|,
name|Device_VideoMask
operator|=
name|Device_DRM
block|}
block|;
name|Q_DECLARE_FLAGS
argument_list|(
argument|QDeviceTypes
argument_list|,
argument|QDeviceType
argument_list|)
specifier|static
name|QDeviceDiscovery
operator|*
name|create
argument_list|(
argument|QDeviceTypes type
argument_list|,
argument|QObject *parent =
literal|0
argument_list|)
block|;
name|virtual
name|QStringList
name|scanConnectedDevices
argument_list|()
operator|=
literal|0
block|;
name|signals
operator|:
name|void
name|deviceDetected
argument_list|(
specifier|const
name|QString
operator|&
name|deviceNode
argument_list|)
block|;
name|void
name|deviceRemoved
argument_list|(
specifier|const
name|QString
operator|&
name|deviceNode
argument_list|)
block|;
name|protected
operator|:
name|QDeviceDiscovery
argument_list|(
argument|QDeviceTypes types
argument_list|,
argument|QObject *parent
argument_list|)
operator|:
name|QObject
argument_list|(
name|parent
argument_list|)
block|,
name|m_types
argument_list|(
argument|types
argument_list|)
block|{ }
name|Q_DISABLE_COPY
argument_list|(
argument|QDeviceDiscovery
argument_list|)
name|QDeviceTypes
name|m_types
block|; }
decl_stmt|;
end_decl_stmt
begin_macro
name|Q_DECLARE_OPERATORS_FOR_FLAGS
argument_list|(
argument|QDeviceDiscovery::QDeviceTypes
argument_list|)
end_macro
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QDEVICEDISCOVERY_H
end_comment
end_unit
