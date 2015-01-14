begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2014 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qeglfskmsdevice.h"
end_include
begin_include
include|#
directive|include
file|"qeglfskmsscreen.h"
end_include
begin_include
include|#
directive|include
file|"qeglfsintegration.h"
end_include
begin_include
include|#
directive|include
file|<QtCore/QLoggingCategory>
end_include
begin_include
include|#
directive|include
file|<QtCore/private/qcore_unix_p.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/private/qguiapplication_p.h>
end_include
begin_define
DECL|macro|ARRAY_LENGTH
define|#
directive|define
name|ARRAY_LENGTH
parameter_list|(
name|a
parameter_list|)
value|(sizeof (a) / sizeof (a)[0])
end_define
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
name|Q_DECLARE_LOGGING_CATEGORY
argument_list|(
name|qLcEglfsKmsDebug
argument_list|)
decl|enum
DECL|enum|OutputConfiguration
name|OutputConfiguration
argument_list|{
DECL|enumerator|OutputConfigOff
name|OutputConfigOff
argument_list|,
DECL|enumerator|OutputConfigPreferred
name|OutputConfigPreferred
argument_list|,
DECL|enumerator|OutputConfigCurrent
name|OutputConfigCurrent
argument_list|,
DECL|enumerator|OutputConfigMode
name|OutputConfigMode
argument_list|,
DECL|enumerator|OutputConfigModeline
name|OutputConfigModeline
argument_list|}
decl_stmt|;
end_decl_stmt
begin_function
DECL|function|crtcForConnector
name|int
name|QEglFSKmsDevice
operator|::
name|crtcForConnector
parameter_list|(
name|drmModeResPtr
name|resources
parameter_list|,
name|drmModeConnectorPtr
name|connector
parameter_list|)
block|{
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|connector
operator|->
name|count_encoders
condition|;
name|i
operator|++
control|)
block|{
name|drmModeEncoderPtr
name|encoder
init|=
name|drmModeGetEncoder
argument_list|(
name|m_dri_fd
argument_list|,
name|connector
operator|->
name|encoders
index|[
name|i
index|]
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|encoder
condition|)
block|{
name|qWarning
argument_list|(
literal|"Failed to get encoder"
argument_list|)
expr_stmt|;
continue|continue;
block|}
name|quint32
name|possibleCrtcs
init|=
name|encoder
operator|->
name|possible_crtcs
decl_stmt|;
name|drmModeFreeEncoder
argument_list|(
name|encoder
argument_list|)
expr_stmt|;
for|for
control|(
name|int
name|j
init|=
literal|0
init|;
name|j
operator|<
name|resources
operator|->
name|count_crtcs
condition|;
name|j
operator|++
control|)
block|{
name|bool
name|isPossible
init|=
name|possibleCrtcs
operator|&
operator|(
literal|1
operator|<<
name|j
operator|)
decl_stmt|;
name|bool
name|isAvailable
init|=
operator|!
operator|(
name|m_crtc_allocator
operator|&
literal|1
operator|<<
name|resources
operator|->
name|crtcs
index|[
name|j
index|]
operator|)
decl_stmt|;
if|if
condition|(
name|isPossible
operator|&&
name|isAvailable
condition|)
return|return
name|j
return|;
block|}
block|}
return|return
operator|-
literal|1
return|;
block|}
end_function
begin_decl_stmt
DECL|variable|connector_type_names
specifier|static
specifier|const
name|char
modifier|*
specifier|const
name|connector_type_names
index|[]
init|=
block|{
literal|"None"
block|,
literal|"VGA"
block|,
literal|"DVI"
block|,
literal|"DVI"
block|,
literal|"DVI"
block|,
literal|"Composite"
block|,
literal|"TV"
block|,
literal|"LVDS"
block|,
literal|"CTV"
block|,
literal|"DIN"
block|,
literal|"DP"
block|,
literal|"HDMI"
block|,
literal|"HDMI"
block|,
literal|"TV"
block|,
literal|"eDP"
block|, }
decl_stmt|;
end_decl_stmt
begin_function
DECL|function|nameForConnector
specifier|static
name|QString
name|nameForConnector
parameter_list|(
specifier|const
name|drmModeConnectorPtr
name|connector
parameter_list|)
block|{
name|QString
name|connectorName
init|=
literal|"UNKNOWN"
decl_stmt|;
if|if
condition|(
name|connector
operator|->
name|connector_type
operator|<
name|ARRAY_LENGTH
argument_list|(
name|connector_type_names
argument_list|)
condition|)
name|connectorName
operator|=
name|connector_type_names
index|[
name|connector
operator|->
name|connector_type
index|]
expr_stmt|;
name|connectorName
operator|+=
name|QString
operator|::
name|number
argument_list|(
name|connector
operator|->
name|connector_type_id
argument_list|)
expr_stmt|;
return|return
name|connectorName
return|;
block|}
end_function
begin_function
DECL|function|parseModeline
specifier|static
name|bool
name|parseModeline
parameter_list|(
specifier|const
name|QString
modifier|&
name|s
parameter_list|,
name|drmModeModeInfoPtr
name|mode
parameter_list|)
block|{
name|char
name|hsync
index|[
literal|16
index|]
decl_stmt|;
name|char
name|vsync
index|[
literal|16
index|]
decl_stmt|;
name|float
name|fclock
decl_stmt|;
name|mode
operator|->
name|type
operator|=
name|DRM_MODE_TYPE_USERDEF
expr_stmt|;
name|mode
operator|->
name|hskew
operator|=
literal|0
expr_stmt|;
name|mode
operator|->
name|vscan
operator|=
literal|0
expr_stmt|;
name|mode
operator|->
name|vrefresh
operator|=
literal|0
expr_stmt|;
name|mode
operator|->
name|flags
operator|=
literal|0
expr_stmt|;
if|if
condition|(
name|sscanf
argument_list|(
name|qPrintable
argument_list|(
name|s
argument_list|)
argument_list|,
literal|"%f %hd %hd %hd %hd %hd %hd %hd %hd %15s %15s"
argument_list|,
operator|&
name|fclock
argument_list|,
operator|&
name|mode
operator|->
name|hdisplay
argument_list|,
operator|&
name|mode
operator|->
name|hsync_start
argument_list|,
operator|&
name|mode
operator|->
name|hsync_end
argument_list|,
operator|&
name|mode
operator|->
name|htotal
argument_list|,
operator|&
name|mode
operator|->
name|vdisplay
argument_list|,
operator|&
name|mode
operator|->
name|vsync_start
argument_list|,
operator|&
name|mode
operator|->
name|vsync_end
argument_list|,
operator|&
name|mode
operator|->
name|vtotal
argument_list|,
name|hsync
argument_list|,
name|vsync
argument_list|)
operator|!=
literal|11
condition|)
return|return
literal|false
return|;
name|mode
operator|->
name|clock
operator|=
name|fclock
operator|*
literal|1000
expr_stmt|;
if|if
condition|(
name|strcmp
argument_list|(
name|hsync
argument_list|,
literal|"+hsync"
argument_list|)
operator|==
literal|0
condition|)
name|mode
operator|->
name|flags
operator||=
name|DRM_MODE_FLAG_PHSYNC
expr_stmt|;
elseif|else
if|if
condition|(
name|strcmp
argument_list|(
name|hsync
argument_list|,
literal|"-hsync"
argument_list|)
operator|==
literal|0
condition|)
name|mode
operator|->
name|flags
operator||=
name|DRM_MODE_FLAG_NHSYNC
expr_stmt|;
else|else
return|return
literal|false
return|;
if|if
condition|(
name|strcmp
argument_list|(
name|vsync
argument_list|,
literal|"+vsync"
argument_list|)
operator|==
literal|0
condition|)
name|mode
operator|->
name|flags
operator||=
name|DRM_MODE_FLAG_PVSYNC
expr_stmt|;
elseif|else
if|if
condition|(
name|strcmp
argument_list|(
name|vsync
argument_list|,
literal|"-vsync"
argument_list|)
operator|==
literal|0
condition|)
name|mode
operator|->
name|flags
operator||=
name|DRM_MODE_FLAG_NVSYNC
expr_stmt|;
else|else
return|return
literal|false
return|;
return|return
literal|true
return|;
block|}
end_function
begin_function
DECL|function|screenForConnector
name|QEglFSKmsScreen
modifier|*
name|QEglFSKmsDevice
operator|::
name|screenForConnector
parameter_list|(
name|drmModeResPtr
name|resources
parameter_list|,
name|drmModeConnectorPtr
name|connector
parameter_list|,
name|QPoint
name|pos
parameter_list|)
block|{
specifier|const
name|QString
name|connectorName
init|=
name|nameForConnector
argument_list|(
name|connector
argument_list|)
decl_stmt|;
specifier|const
name|int
name|crtc
init|=
name|crtcForConnector
argument_list|(
name|resources
argument_list|,
name|connector
argument_list|)
decl_stmt|;
if|if
condition|(
name|crtc
operator|<
literal|0
condition|)
block|{
name|qWarning
argument_list|()
operator|<<
literal|"No usable crtc/encoder pair for connector"
operator|<<
name|connectorName
expr_stmt|;
return|return
name|Q_NULLPTR
return|;
block|}
name|OutputConfiguration
name|configuration
decl_stmt|;
name|QSize
name|configurationSize
decl_stmt|;
name|drmModeModeInfo
name|configurationModeline
decl_stmt|;
specifier|const
name|QString
name|mode
init|=
name|m_integration
operator|->
name|outputSettings
argument_list|()
operator|.
name|value
argument_list|(
name|connectorName
argument_list|)
operator|.
name|value
argument_list|(
literal|"mode"
argument_list|,
literal|"preferred"
argument_list|)
operator|.
name|toString
argument_list|()
operator|.
name|toLower
argument_list|()
decl_stmt|;
if|if
condition|(
name|mode
operator|==
literal|"off"
condition|)
block|{
name|configuration
operator|=
name|OutputConfigOff
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|mode
operator|==
literal|"preferred"
condition|)
block|{
name|configuration
operator|=
name|OutputConfigPreferred
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|mode
operator|==
literal|"current"
condition|)
block|{
name|configuration
operator|=
name|OutputConfigCurrent
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|sscanf
argument_list|(
name|qPrintable
argument_list|(
name|mode
argument_list|)
argument_list|,
literal|"%dx%d"
argument_list|,
operator|&
name|configurationSize
operator|.
name|rwidth
argument_list|()
argument_list|,
operator|&
name|configurationSize
operator|.
name|rheight
argument_list|()
argument_list|)
operator|==
literal|2
condition|)
block|{
name|configuration
operator|=
name|OutputConfigMode
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|parseModeline
argument_list|(
name|mode
argument_list|,
operator|&
name|configurationModeline
argument_list|)
condition|)
block|{
name|configuration
operator|=
name|OutputConfigModeline
expr_stmt|;
block|}
else|else
block|{
name|qWarning
argument_list|(
literal|"Invalid mode \"%s\" for output %s"
argument_list|,
name|qPrintable
argument_list|(
name|mode
argument_list|)
argument_list|,
name|qPrintable
argument_list|(
name|connectorName
argument_list|)
argument_list|)
expr_stmt|;
name|configuration
operator|=
name|OutputConfigPreferred
expr_stmt|;
block|}
specifier|const
name|uint32_t
name|crtc_id
init|=
name|resources
operator|->
name|crtcs
index|[
name|crtc
index|]
decl_stmt|;
if|if
condition|(
name|configuration
operator|==
name|OutputConfigOff
condition|)
block|{
name|qCDebug
argument_list|(
name|qLcEglfsKmsDebug
argument_list|)
operator|<<
literal|"Turning off output"
operator|<<
name|connectorName
expr_stmt|;
name|drmModeSetCrtc
argument_list|(
name|m_dri_fd
argument_list|,
name|crtc_id
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
name|Q_NULLPTR
argument_list|)
expr_stmt|;
return|return
name|Q_NULLPTR
return|;
block|}
comment|// Get the current mode on the current crtc
name|drmModeModeInfo
name|crtc_mode
decl_stmt|;
name|memset
argument_list|(
operator|&
name|crtc_mode
argument_list|,
literal|0
argument_list|,
sizeof|sizeof
name|crtc_mode
argument_list|)
expr_stmt|;
if|if
condition|(
name|drmModeEncoderPtr
name|encoder
init|=
name|drmModeGetEncoder
argument_list|(
name|m_dri_fd
argument_list|,
name|connector
operator|->
name|connector_id
argument_list|)
condition|)
block|{
name|drmModeCrtcPtr
name|crtc
init|=
name|drmModeGetCrtc
argument_list|(
name|m_dri_fd
argument_list|,
name|encoder
operator|->
name|crtc_id
argument_list|)
decl_stmt|;
name|drmModeFreeEncoder
argument_list|(
name|encoder
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|crtc
condition|)
return|return
name|Q_NULLPTR
return|;
if|if
condition|(
name|crtc
operator|->
name|mode_valid
condition|)
name|crtc_mode
operator|=
name|crtc
operator|->
name|mode
expr_stmt|;
name|drmModeFreeCrtc
argument_list|(
name|crtc
argument_list|)
expr_stmt|;
block|}
name|QList
argument_list|<
name|drmModeModeInfo
argument_list|>
name|modes
decl_stmt|;
name|qCDebug
argument_list|(
name|qLcEglfsKmsDebug
argument_list|)
operator|<<
name|connectorName
operator|<<
literal|"mode count:"
operator|<<
name|connector
operator|->
name|count_modes
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
name|connector
operator|->
name|count_modes
condition|;
name|i
operator|++
control|)
block|{
specifier|const
name|drmModeModeInfo
modifier|&
name|mode
init|=
name|connector
operator|->
name|modes
index|[
name|i
index|]
decl_stmt|;
name|qCDebug
argument_list|(
name|qLcEglfsKmsDebug
argument_list|)
operator|<<
literal|"mode"
operator|<<
name|i
operator|<<
name|mode
operator|.
name|hdisplay
operator|<<
literal|"x"
operator|<<
name|mode
operator|.
name|vdisplay
operator|<<
literal|"@"
operator|<<
name|mode
operator|.
name|vrefresh
operator|<<
literal|"hz"
expr_stmt|;
name|modes
operator|<<
name|connector
operator|->
name|modes
index|[
name|i
index|]
expr_stmt|;
block|}
name|int
name|preferred
init|=
operator|-
literal|1
decl_stmt|;
name|int
name|current
init|=
operator|-
literal|1
decl_stmt|;
name|int
name|configured
init|=
operator|-
literal|1
decl_stmt|;
name|int
name|best
init|=
operator|-
literal|1
decl_stmt|;
for|for
control|(
name|int
name|i
init|=
name|modes
operator|.
name|size
argument_list|()
operator|-
literal|1
init|;
name|i
operator|>=
literal|0
condition|;
name|i
operator|--
control|)
block|{
specifier|const
name|drmModeModeInfo
modifier|&
name|m
init|=
name|modes
operator|.
name|at
argument_list|(
name|i
argument_list|)
decl_stmt|;
if|if
condition|(
name|configuration
operator|==
name|OutputConfigMode
operator|&&
name|m
operator|.
name|hdisplay
operator|==
name|configurationSize
operator|.
name|width
argument_list|()
operator|&&
name|m
operator|.
name|vdisplay
operator|==
name|configurationSize
operator|.
name|height
argument_list|()
condition|)
block|{
name|configured
operator|=
name|i
expr_stmt|;
block|}
if|if
condition|(
operator|!
name|memcmp
argument_list|(
operator|&
name|crtc_mode
argument_list|,
operator|&
name|m
argument_list|,
sizeof|sizeof
name|m
argument_list|)
condition|)
name|current
operator|=
name|i
expr_stmt|;
if|if
condition|(
name|m
operator|.
name|type
operator|&
name|DRM_MODE_TYPE_PREFERRED
condition|)
name|preferred
operator|=
name|i
expr_stmt|;
name|best
operator|=
name|i
expr_stmt|;
block|}
if|if
condition|(
name|configuration
operator|==
name|OutputConfigModeline
condition|)
block|{
name|modes
operator|<<
name|configurationModeline
expr_stmt|;
name|configured
operator|=
name|modes
operator|.
name|size
argument_list|()
operator|-
literal|1
expr_stmt|;
block|}
if|if
condition|(
name|current
operator|<
literal|0
operator|&&
name|crtc_mode
operator|.
name|clock
operator|!=
literal|0
condition|)
block|{
name|modes
operator|<<
name|crtc_mode
expr_stmt|;
name|current
operator|=
name|mode
operator|.
name|size
argument_list|()
operator|-
literal|1
expr_stmt|;
block|}
if|if
condition|(
name|configuration
operator|==
name|OutputConfigCurrent
condition|)
name|configured
operator|=
name|current
expr_stmt|;
name|int
name|selected_mode
init|=
operator|-
literal|1
decl_stmt|;
if|if
condition|(
name|configured
operator|>=
literal|0
condition|)
name|selected_mode
operator|=
name|configured
expr_stmt|;
elseif|else
if|if
condition|(
name|preferred
operator|>=
literal|0
condition|)
name|selected_mode
operator|=
name|preferred
expr_stmt|;
elseif|else
if|if
condition|(
name|current
operator|>=
literal|0
condition|)
name|selected_mode
operator|=
name|current
expr_stmt|;
elseif|else
if|if
condition|(
name|best
operator|>=
literal|0
condition|)
name|selected_mode
operator|=
name|best
expr_stmt|;
if|if
condition|(
name|selected_mode
operator|<
literal|0
condition|)
block|{
name|qWarning
argument_list|()
operator|<<
literal|"No modes available for output"
operator|<<
name|connectorName
expr_stmt|;
return|return
name|Q_NULLPTR
return|;
block|}
else|else
block|{
name|int
name|width
init|=
name|modes
index|[
name|selected_mode
index|]
operator|.
name|hdisplay
decl_stmt|;
name|int
name|height
init|=
name|modes
index|[
name|selected_mode
index|]
operator|.
name|vdisplay
decl_stmt|;
name|int
name|refresh
init|=
name|modes
index|[
name|selected_mode
index|]
operator|.
name|vrefresh
decl_stmt|;
name|qCDebug
argument_list|(
name|qLcEglfsKmsDebug
argument_list|)
operator|<<
literal|"Selected mode"
operator|<<
name|selected_mode
operator|<<
literal|":"
operator|<<
name|width
operator|<<
literal|"x"
operator|<<
name|height
operator|<<
literal|"@"
operator|<<
name|refresh
operator|<<
literal|"hz for output"
operator|<<
name|connectorName
expr_stmt|;
block|}
name|QEglFSKmsOutput
name|output
init|=
block|{
name|connectorName
block|,
name|connector
operator|->
name|connector_id
block|,
name|crtc_id
block|,
name|QSizeF
argument_list|(
name|connector
operator|->
name|mmWidth
argument_list|,
name|connector
operator|->
name|mmHeight
argument_list|)
block|,
name|selected_mode
block|,
literal|false
block|,
name|drmModeGetCrtc
argument_list|(
name|m_dri_fd
argument_list|,
name|crtc_id
argument_list|)
block|,
name|modes
block|}
decl_stmt|;
name|m_crtc_allocator
operator||=
operator|(
literal|1
operator|<<
name|output
operator|.
name|crtc_id
operator|)
expr_stmt|;
name|m_connector_allocator
operator||=
operator|(
literal|1
operator|<<
name|output
operator|.
name|connector_id
operator|)
expr_stmt|;
return|return
operator|new
name|QEglFSKmsScreen
argument_list|(
name|m_integration
argument_list|,
name|this
argument_list|,
name|output
argument_list|,
name|pos
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|pageFlipHandler
name|void
name|QEglFSKmsDevice
operator|::
name|pageFlipHandler
parameter_list|(
name|int
name|fd
parameter_list|,
name|unsigned
name|int
name|sequence
parameter_list|,
name|unsigned
name|int
name|tv_sec
parameter_list|,
name|unsigned
name|int
name|tv_usec
parameter_list|,
name|void
modifier|*
name|user_data
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
name|fd
argument_list|)
expr_stmt|;
name|Q_UNUSED
argument_list|(
name|sequence
argument_list|)
expr_stmt|;
name|Q_UNUSED
argument_list|(
name|tv_sec
argument_list|)
expr_stmt|;
name|Q_UNUSED
argument_list|(
name|tv_usec
argument_list|)
expr_stmt|;
name|QEglFSKmsScreen
modifier|*
name|screen
init|=
cast|static_cast
argument_list|<
name|QEglFSKmsScreen
operator|*
argument_list|>
argument_list|(
name|user_data
argument_list|)
decl_stmt|;
name|screen
operator|->
name|flipFinished
argument_list|()
expr_stmt|;
block|}
end_function
begin_constructor
DECL|function|QEglFSKmsDevice
name|QEglFSKmsDevice
operator|::
name|QEglFSKmsDevice
parameter_list|(
name|QEglFSKmsIntegration
modifier|*
name|integration
parameter_list|,
specifier|const
name|QString
modifier|&
name|path
parameter_list|)
member_init_list|:
name|m_integration
argument_list|(
name|integration
argument_list|)
member_init_list|,
name|m_path
argument_list|(
name|path
argument_list|)
member_init_list|,
name|m_dri_fd
argument_list|(
operator|-
literal|1
argument_list|)
member_init_list|,
name|m_gbm_device
argument_list|(
name|Q_NULLPTR
argument_list|)
member_init_list|,
name|m_crtc_allocator
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|m_connector_allocator
argument_list|(
literal|0
argument_list|)
block|{ }
end_constructor
begin_function
DECL|function|open
name|bool
name|QEglFSKmsDevice
operator|::
name|open
parameter_list|()
block|{
name|Q_ASSERT
argument_list|(
name|m_dri_fd
operator|==
operator|-
literal|1
argument_list|)
expr_stmt|;
name|Q_ASSERT
argument_list|(
name|m_gbm_device
operator|==
name|Q_NULLPTR
argument_list|)
expr_stmt|;
name|qCDebug
argument_list|(
name|qLcEglfsKmsDebug
argument_list|)
operator|<<
literal|"Opening device"
operator|<<
name|m_path
expr_stmt|;
name|m_dri_fd
operator|=
name|qt_safe_open
argument_list|(
name|m_path
operator|.
name|toLocal8Bit
argument_list|()
operator|.
name|constData
argument_list|()
argument_list|,
name|O_RDWR
operator||
name|O_CLOEXEC
argument_list|)
expr_stmt|;
if|if
condition|(
name|m_dri_fd
operator|==
operator|-
literal|1
condition|)
block|{
name|qErrnoWarning
argument_list|(
literal|"Could not open DRM device %s"
argument_list|,
name|qPrintable
argument_list|(
name|m_path
argument_list|)
argument_list|)
expr_stmt|;
return|return
literal|false
return|;
block|}
name|qCDebug
argument_list|(
name|qLcEglfsKmsDebug
argument_list|)
operator|<<
literal|"Creating GBM device for file descriptor"
operator|<<
name|m_dri_fd
operator|<<
literal|"obtained from"
operator|<<
name|m_path
expr_stmt|;
name|m_gbm_device
operator|=
name|gbm_create_device
argument_list|(
name|m_dri_fd
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|m_gbm_device
condition|)
block|{
name|qErrnoWarning
argument_list|(
literal|"Could not create GBM device"
argument_list|)
expr_stmt|;
name|qt_safe_close
argument_list|(
name|m_dri_fd
argument_list|)
expr_stmt|;
name|m_dri_fd
operator|=
operator|-
literal|1
expr_stmt|;
return|return
literal|false
return|;
block|}
return|return
literal|true
return|;
block|}
end_function
begin_function
DECL|function|close
name|void
name|QEglFSKmsDevice
operator|::
name|close
parameter_list|()
block|{
if|if
condition|(
name|m_gbm_device
condition|)
block|{
name|gbm_device_destroy
argument_list|(
name|m_gbm_device
argument_list|)
expr_stmt|;
name|m_gbm_device
operator|=
name|Q_NULLPTR
expr_stmt|;
block|}
if|if
condition|(
name|m_dri_fd
operator|!=
operator|-
literal|1
condition|)
block|{
name|qt_safe_close
argument_list|(
name|m_dri_fd
argument_list|)
expr_stmt|;
name|m_dri_fd
operator|=
operator|-
literal|1
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|createScreens
name|void
name|QEglFSKmsDevice
operator|::
name|createScreens
parameter_list|()
block|{
name|drmModeResPtr
name|resources
init|=
name|drmModeGetResources
argument_list|(
name|m_dri_fd
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|resources
condition|)
block|{
name|qWarning
argument_list|(
literal|"drmModeGetResources failed"
argument_list|)
expr_stmt|;
return|return;
block|}
name|QPoint
name|pos
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
decl_stmt|;
name|QEglFSIntegration
modifier|*
name|integration
init|=
cast|static_cast
argument_list|<
name|QEglFSIntegration
operator|*
argument_list|>
argument_list|(
name|QGuiApplicationPrivate
operator|::
name|platformIntegration
argument_list|()
argument_list|)
decl_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|resources
operator|->
name|count_connectors
condition|;
name|i
operator|++
control|)
block|{
name|drmModeConnectorPtr
name|connector
init|=
name|drmModeGetConnector
argument_list|(
name|m_dri_fd
argument_list|,
name|resources
operator|->
name|connectors
index|[
name|i
index|]
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|connector
condition|)
continue|continue;
name|QEglFSKmsScreen
modifier|*
name|screen
init|=
name|screenForConnector
argument_list|(
name|resources
argument_list|,
name|connector
argument_list|,
name|pos
argument_list|)
decl_stmt|;
if|if
condition|(
name|screen
condition|)
block|{
name|integration
operator|->
name|addScreen
argument_list|(
name|screen
argument_list|)
expr_stmt|;
name|pos
operator|.
name|rx
argument_list|()
operator|+=
name|screen
operator|->
name|geometry
argument_list|()
operator|.
name|width
argument_list|()
expr_stmt|;
block|}
name|drmModeFreeConnector
argument_list|(
name|connector
argument_list|)
expr_stmt|;
block|}
name|drmModeFreeResources
argument_list|(
name|resources
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|device
name|gbm_device
modifier|*
name|QEglFSKmsDevice
operator|::
name|device
parameter_list|()
specifier|const
block|{
return|return
name|m_gbm_device
return|;
block|}
end_function
begin_function
DECL|function|fd
name|int
name|QEglFSKmsDevice
operator|::
name|fd
parameter_list|()
specifier|const
block|{
return|return
name|m_dri_fd
return|;
block|}
end_function
begin_function
DECL|function|handleDrmEvent
name|void
name|QEglFSKmsDevice
operator|::
name|handleDrmEvent
parameter_list|()
block|{
name|drmEventContext
name|drmEvent
init|=
block|{
name|DRM_EVENT_CONTEXT_VERSION
block|,
name|Q_NULLPTR
block|,
comment|// vblank handler
name|pageFlipHandler
comment|// page flip handler
block|}
decl_stmt|;
name|drmHandleEvent
argument_list|(
name|m_dri_fd
argument_list|,
operator|&
name|drmEvent
argument_list|)
expr_stmt|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
