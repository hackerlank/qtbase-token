begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 Pier Luigi Fiorini<pierluigi.fiorini@gmail.com> ** Copyright (C) 2016 The Qt Company Ltd. ** Copyright (C) 2016 Pelagicore AG ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qeglfskmsscreen.h"
end_include
begin_include
include|#
directive|include
file|"qeglfskmsdevice.h"
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
file|<QtGui/private/qguiapplication_p.h>
end_include
begin_include
include|#
directive|include
file|<QtPlatformSupport/private/qfbvthandler_p.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
name|Q_DECLARE_LOGGING_CATEGORY
argument_list|(
name|qLcEglfsKmsDebug
argument_list|)
DECL|class|QEglFSKmsInterruptHandler
name|class
name|QEglFSKmsInterruptHandler
range|:
specifier|public
name|QObject
block|{
specifier|public
operator|:
DECL|function|QEglFSKmsInterruptHandler
name|QEglFSKmsInterruptHandler
argument_list|(
name|QEglFSKmsScreen
operator|*
name|screen
argument_list|)
operator|:
name|m_screen
argument_list|(
argument|screen
argument_list|)
block|{
name|m_vtHandler
operator|=
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
operator|->
name|vtHandler
argument_list|()
block|;
name|connect
argument_list|(
name|m_vtHandler
argument_list|,
operator|&
name|QFbVtHandler
operator|::
name|interrupted
argument_list|,
name|this
argument_list|,
operator|&
name|QEglFSKmsInterruptHandler
operator|::
name|restoreVideoMode
argument_list|)
block|;
name|connect
argument_list|(
name|m_vtHandler
argument_list|,
operator|&
name|QFbVtHandler
operator|::
name|aboutToSuspend
argument_list|,
name|this
argument_list|,
operator|&
name|QEglFSKmsInterruptHandler
operator|::
name|restoreVideoMode
argument_list|)
block|;     }
specifier|public
name|slots
operator|:
DECL|function|restoreVideoMode
name|void
name|restoreVideoMode
argument_list|()
block|{
name|m_screen
operator|->
name|restoreMode
argument_list|()
block|; }
specifier|private
operator|:
DECL|member|m_vtHandler
name|QFbVtHandler
operator|*
name|m_vtHandler
block|;
DECL|member|m_screen
name|QEglFSKmsScreen
operator|*
name|m_screen
block|; }
decl_stmt|;
end_decl_stmt
begin_constructor
DECL|function|QEglFSKmsScreen
name|QEglFSKmsScreen
operator|::
name|QEglFSKmsScreen
parameter_list|(
name|QEglFSKmsIntegration
modifier|*
name|integration
parameter_list|,
name|QEglFSKmsDevice
modifier|*
name|device
parameter_list|,
name|QEglFSKmsOutput
name|output
parameter_list|,
name|QPoint
name|position
parameter_list|)
member_init_list|:
name|QEglFSScreen
argument_list|(
name|eglGetDisplay
argument_list|(
name|device
operator|->
name|nativeDisplay
argument_list|()
argument_list|)
argument_list|)
member_init_list|,
name|m_integration
argument_list|(
name|integration
argument_list|)
member_init_list|,
name|m_device
argument_list|(
name|device
argument_list|)
member_init_list|,
name|m_output
argument_list|(
name|output
argument_list|)
member_init_list|,
name|m_pos
argument_list|(
name|position
argument_list|)
member_init_list|,
name|m_powerState
argument_list|(
name|PowerStateOn
argument_list|)
member_init_list|,
name|m_interruptHandler
argument_list|(
operator|new
name|QEglFSKmsInterruptHandler
argument_list|(
name|this
argument_list|)
argument_list|)
block|{
name|m_siblings
operator|<<
name|this
expr_stmt|;
block|}
end_constructor
begin_destructor
DECL|function|~QEglFSKmsScreen
name|QEglFSKmsScreen
operator|::
name|~
name|QEglFSKmsScreen
parameter_list|()
block|{
if|if
condition|(
name|m_output
operator|.
name|dpms_prop
condition|)
block|{
name|drmModeFreeProperty
argument_list|(
name|m_output
operator|.
name|dpms_prop
argument_list|)
expr_stmt|;
name|m_output
operator|.
name|dpms_prop
operator|=
name|Q_NULLPTR
expr_stmt|;
block|}
name|restoreMode
argument_list|()
expr_stmt|;
if|if
condition|(
name|m_output
operator|.
name|saved_crtc
condition|)
block|{
name|drmModeFreeCrtc
argument_list|(
name|m_output
operator|.
name|saved_crtc
argument_list|)
expr_stmt|;
name|m_output
operator|.
name|saved_crtc
operator|=
name|Q_NULLPTR
expr_stmt|;
block|}
operator|delete
name|m_interruptHandler
expr_stmt|;
block|}
end_destructor
begin_function
DECL|function|geometry
name|QRect
name|QEglFSKmsScreen
operator|::
name|geometry
parameter_list|()
specifier|const
block|{
specifier|const
name|int
name|mode
init|=
name|m_output
operator|.
name|mode
decl_stmt|;
return|return
name|QRect
argument_list|(
name|m_pos
operator|.
name|x
argument_list|()
argument_list|,
name|m_pos
operator|.
name|y
argument_list|()
argument_list|,
name|m_output
operator|.
name|modes
index|[
name|mode
index|]
operator|.
name|hdisplay
argument_list|,
name|m_output
operator|.
name|modes
index|[
name|mode
index|]
operator|.
name|vdisplay
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|depth
name|int
name|QEglFSKmsScreen
operator|::
name|depth
parameter_list|()
specifier|const
block|{
return|return
literal|32
return|;
block|}
end_function
begin_function
DECL|function|format
name|QImage
operator|::
name|Format
name|QEglFSKmsScreen
operator|::
name|format
parameter_list|()
specifier|const
block|{
return|return
name|QImage
operator|::
name|Format_RGB32
return|;
block|}
end_function
begin_function
DECL|function|physicalSize
name|QSizeF
name|QEglFSKmsScreen
operator|::
name|physicalSize
parameter_list|()
specifier|const
block|{
return|return
name|m_output
operator|.
name|physical_size
return|;
block|}
end_function
begin_function
DECL|function|logicalDpi
name|QDpi
name|QEglFSKmsScreen
operator|::
name|logicalDpi
parameter_list|()
specifier|const
block|{
specifier|const
name|QSizeF
name|ps
init|=
name|physicalSize
argument_list|()
decl_stmt|;
specifier|const
name|QSize
name|s
init|=
name|geometry
argument_list|()
operator|.
name|size
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
name|ps
operator|.
name|isEmpty
argument_list|()
operator|&&
operator|!
name|s
operator|.
name|isEmpty
argument_list|()
condition|)
return|return
name|QDpi
argument_list|(
literal|25.4
operator|*
name|s
operator|.
name|width
argument_list|()
operator|/
name|ps
operator|.
name|width
argument_list|()
argument_list|,
literal|25.4
operator|*
name|s
operator|.
name|height
argument_list|()
operator|/
name|ps
operator|.
name|height
argument_list|()
argument_list|)
return|;
else|else
return|return
name|QDpi
argument_list|(
literal|100
argument_list|,
literal|100
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|nativeOrientation
name|Qt
operator|::
name|ScreenOrientation
name|QEglFSKmsScreen
operator|::
name|nativeOrientation
parameter_list|()
specifier|const
block|{
return|return
name|Qt
operator|::
name|PrimaryOrientation
return|;
block|}
end_function
begin_function
DECL|function|orientation
name|Qt
operator|::
name|ScreenOrientation
name|QEglFSKmsScreen
operator|::
name|orientation
parameter_list|()
specifier|const
block|{
return|return
name|Qt
operator|::
name|PrimaryOrientation
return|;
block|}
end_function
begin_function
DECL|function|name
name|QString
name|QEglFSKmsScreen
operator|::
name|name
parameter_list|()
specifier|const
block|{
return|return
name|m_output
operator|.
name|name
return|;
block|}
end_function
begin_function
DECL|function|destroySurface
name|void
name|QEglFSKmsScreen
operator|::
name|destroySurface
parameter_list|()
block|{ }
end_function
begin_function
DECL|function|waitForFlip
name|void
name|QEglFSKmsScreen
operator|::
name|waitForFlip
parameter_list|()
block|{ }
end_function
begin_function
DECL|function|flip
name|void
name|QEglFSKmsScreen
operator|::
name|flip
parameter_list|()
block|{ }
end_function
begin_function
DECL|function|flipFinished
name|void
name|QEglFSKmsScreen
operator|::
name|flipFinished
parameter_list|()
block|{ }
end_function
begin_function
DECL|function|restoreMode
name|void
name|QEglFSKmsScreen
operator|::
name|restoreMode
parameter_list|()
block|{
if|if
condition|(
name|m_output
operator|.
name|mode_set
operator|&&
name|m_output
operator|.
name|saved_crtc
condition|)
block|{
name|drmModeSetCrtc
argument_list|(
name|m_device
operator|->
name|fd
argument_list|()
argument_list|,
name|m_output
operator|.
name|saved_crtc
operator|->
name|crtc_id
argument_list|,
name|m_output
operator|.
name|saved_crtc
operator|->
name|buffer_id
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
operator|&
name|m_output
operator|.
name|connector_id
argument_list|,
literal|1
argument_list|,
operator|&
name|m_output
operator|.
name|saved_crtc
operator|->
name|mode
argument_list|)
expr_stmt|;
name|m_output
operator|.
name|mode_set
operator|=
literal|false
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|refreshRate
name|qreal
name|QEglFSKmsScreen
operator|::
name|refreshRate
parameter_list|()
specifier|const
block|{
name|quint32
name|refresh
init|=
name|m_output
operator|.
name|modes
index|[
name|m_output
operator|.
name|mode
index|]
operator|.
name|vrefresh
decl_stmt|;
return|return
name|refresh
operator|>
literal|0
condition|?
name|refresh
else|:
literal|60
return|;
block|}
end_function
begin_function
DECL|function|subpixelAntialiasingTypeHint
name|QPlatformScreen
operator|::
name|SubpixelAntialiasingType
name|QEglFSKmsScreen
operator|::
name|subpixelAntialiasingTypeHint
parameter_list|()
specifier|const
block|{
switch|switch
condition|(
name|m_output
operator|.
name|subpixel
condition|)
block|{
default|default:
case|case
name|DRM_MODE_SUBPIXEL_UNKNOWN
case|:
case|case
name|DRM_MODE_SUBPIXEL_NONE
case|:
return|return
name|Subpixel_None
return|;
case|case
name|DRM_MODE_SUBPIXEL_HORIZONTAL_RGB
case|:
return|return
name|Subpixel_RGB
return|;
case|case
name|DRM_MODE_SUBPIXEL_HORIZONTAL_BGR
case|:
return|return
name|Subpixel_BGR
return|;
case|case
name|DRM_MODE_SUBPIXEL_VERTICAL_RGB
case|:
return|return
name|Subpixel_VRGB
return|;
case|case
name|DRM_MODE_SUBPIXEL_VERTICAL_BGR
case|:
return|return
name|Subpixel_VBGR
return|;
block|}
block|}
end_function
begin_function
DECL|function|powerState
name|QPlatformScreen
operator|::
name|PowerState
name|QEglFSKmsScreen
operator|::
name|powerState
parameter_list|()
specifier|const
block|{
return|return
name|m_powerState
return|;
block|}
end_function
begin_function
DECL|function|setPowerState
name|void
name|QEglFSKmsScreen
operator|::
name|setPowerState
parameter_list|(
name|QPlatformScreen
operator|::
name|PowerState
name|state
parameter_list|)
block|{
if|if
condition|(
operator|!
name|m_output
operator|.
name|dpms_prop
condition|)
return|return;
name|drmModeConnectorSetProperty
argument_list|(
name|m_device
operator|->
name|fd
argument_list|()
argument_list|,
name|m_output
operator|.
name|connector_id
argument_list|,
name|m_output
operator|.
name|dpms_prop
operator|->
name|prop_id
argument_list|,
operator|(
name|int
operator|)
name|state
argument_list|)
expr_stmt|;
name|m_powerState
operator|=
name|state
expr_stmt|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
