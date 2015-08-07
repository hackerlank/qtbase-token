begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2014-2015 Canonical, Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL3$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPLv3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or later as published by the Free ** Software Foundation and appearing in the file LICENSE.GPL included in ** the packaging of this file. Please review the following information to ** ensure the GNU General Public License version 2.0 requirements will be ** met: http://www.gnu.org/licenses/gpl-2.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QMIRCLIENTINPUT_H
end_ifndef
begin_define
DECL|macro|QMIRCLIENTINPUT_H
define|#
directive|define
name|QMIRCLIENTINPUT_H
end_define
begin_comment
comment|// Qt
end_comment
begin_include
include|#
directive|include
file|<qpa/qwindowsysteminterface.h>
end_include
begin_include
include|#
directive|include
file|<mir_toolkit/mir_client_library.h>
end_include
begin_decl_stmt
DECL|variable|QMirClientClientIntegration
name|class
name|QMirClientClientIntegration
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QMirClientWindow
name|class
name|QMirClientWindow
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QMirClientInput
range|:
name|public
name|QObject
block|{
name|Q_OBJECT
name|public
operator|:
name|QMirClientInput
argument_list|(
name|QMirClientClientIntegration
operator|*
name|integration
argument_list|)
block|;
name|virtual
operator|~
name|QMirClientInput
argument_list|()
block|;
comment|// QObject methods.
name|void
name|customEvent
argument_list|(
argument|QEvent* event
argument_list|)
name|override
block|;
name|void
name|postEvent
argument_list|(
name|QMirClientWindow
operator|*
name|window
argument_list|,
specifier|const
name|MirEvent
operator|*
name|event
argument_list|)
block|;
name|QMirClientClientIntegration
operator|*
name|integration
argument_list|()
specifier|const
block|{
return|return
name|mIntegration
return|;
block|}
name|protected
operator|:
name|void
name|dispatchKeyEvent
argument_list|(
name|QWindow
operator|*
name|window
argument_list|,
specifier|const
name|MirInputEvent
operator|*
name|event
argument_list|)
block|;
name|void
name|dispatchPointerEvent
argument_list|(
name|QWindow
operator|*
name|window
argument_list|,
specifier|const
name|MirInputEvent
operator|*
name|event
argument_list|)
block|;
name|void
name|dispatchTouchEvent
argument_list|(
name|QWindow
operator|*
name|window
argument_list|,
specifier|const
name|MirInputEvent
operator|*
name|event
argument_list|)
block|;
name|void
name|dispatchInputEvent
argument_list|(
name|QWindow
operator|*
name|window
argument_list|,
specifier|const
name|MirInputEvent
operator|*
name|event
argument_list|)
block|;
name|void
name|dispatchOrientationEvent
argument_list|(
name|QWindow
operator|*
name|window
argument_list|,
specifier|const
name|MirOrientationEvent
operator|*
name|event
argument_list|)
block|;
name|private
operator|:
name|QMirClientClientIntegration
operator|*
name|mIntegration
block|;
name|QTouchDevice
operator|*
name|mTouchDevice
block|;
specifier|const
name|QByteArray
name|mEventFilterType
block|;
specifier|const
name|QEvent
operator|::
name|Type
name|mEventType
block|; }
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QMIRCLIENTINPUT_H
end_comment
end_unit
