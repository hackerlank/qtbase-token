begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QOPENWFDDEVICE_H
end_ifndef
begin_define
DECL|macro|QOPENWFDDEVICE_H
define|#
directive|define
name|QOPENWFDDEVICE_H
end_define
begin_include
include|#
directive|include
file|"qopenwfdintegration.h"
end_include
begin_include
include|#
directive|include
file|<QtCore/QList>
end_include
begin_include
include|#
directive|include
file|<QtCore/QSet>
end_include
begin_include
include|#
directive|include
file|<QtCore/QSocketNotifier>
end_include
begin_include
include|#
directive|include
file|<WF/wfd.h>
end_include
begin_include
include|#
directive|include
file|<gbm.h>
end_include
begin_include
include|#
directive|include
file|<EGL/egl.h>
end_include
begin_include
include|#
directive|include
file|<EGL/eglext.h>
end_include
begin_include
include|#
directive|include
file|<GLES2/gl2.h>
end_include
begin_include
include|#
directive|include
file|<GLES2/gl2ext.h>
end_include
begin_decl_stmt
DECL|variable|QOpenWFDPort
name|class
name|QOpenWFDPort
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QOpenWFDDevice
range|:
name|public
name|QObject
block|{
name|Q_OBJECT
name|public
operator|:
name|QOpenWFDDevice
argument_list|(
argument|QOpenWFDIntegration *integration
argument_list|,
argument|WFDint handle
argument_list|)
block|;
operator|~
name|QOpenWFDDevice
argument_list|()
block|;
name|WFDDevice
name|handle
argument_list|()
specifier|const
block|;
name|QOpenWFDIntegration
operator|*
name|integration
argument_list|()
specifier|const
block|;
name|bool
name|isPipelineUsed
argument_list|(
argument|WFDint pipelineId
argument_list|)
block|;
name|void
name|addToUsedPipelineSet
argument_list|(
argument|WFDint pipelineId
argument_list|,
argument|QOpenWFDPort *port
argument_list|)
block|;
name|void
name|removeFromUsedPipelineSet
argument_list|(
argument|WFDint pipelineId
argument_list|)
block|;
name|gbm_device
operator|*
name|gbmDevice
argument_list|()
specifier|const
block|;
name|EGLDisplay
name|eglDisplay
argument_list|()
specifier|const
block|;
name|EGLContext
name|eglContext
argument_list|()
specifier|const
block|;
name|PFNEGLCREATEIMAGEKHRPROC
name|eglCreateImage
block|;
name|PFNEGLDESTROYIMAGEKHRPROC
name|eglDestroyImage
block|;
name|PFNGLEGLIMAGETARGETRENDERBUFFERSTORAGEOESPROC
name|glEglImageTargetRenderBufferStorage
block|;
name|void
name|commit
argument_list|(
argument|WFDCommitType type
argument_list|,
argument|WFDHandle handle
argument_list|)
block|;
name|bool
name|isDeviceInitializedAndCommited
argument_list|()
specifier|const
block|{
return|return
name|mCommitedDevice
return|;
block|}
name|void
name|waitForPipelineBindSourceCompleteEvent
argument_list|()
block|;
name|public
name|slots
operator|:
name|void
name|readEvents
argument_list|(
argument|WFDtime wait =
literal|0
argument_list|)
block|;
name|private
operator|:
name|void
name|initializeGbmAndEgl
argument_list|()
block|;
name|void
name|handlePortAttachDetach
argument_list|()
block|;
name|void
name|handlePipelineBindSourceComplete
argument_list|()
block|;
name|QOpenWFDIntegration
operator|*
name|mIntegration
block|;
name|WFDint
name|mDeviceEnum
block|;
name|WFDDevice
name|mDevice
block|;
name|WFDEvent
name|mEvent
block|;
name|QSocketNotifier
operator|*
name|mEventSocketNotifier
block|;
name|QList
operator|<
name|QOpenWFDPort
operator|*
operator|>
name|mPorts
block|;
name|QMap
operator|<
name|WFDint
block|,
name|QOpenWFDPort
operator|*
operator|>
name|mUsedPipelines
block|;      struct
name|gbm_device
operator|*
name|mGbmDevice
block|;
name|EGLDisplay
name|mEglDisplay
block|;
name|EGLContext
name|mEglContext
block|;
name|bool
name|mCommitedDevice
block|;
name|bool
name|mWaitingForBindSourceEvent
block|; }
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QOPENWFDDEVICE_H
end_comment
end_unit
