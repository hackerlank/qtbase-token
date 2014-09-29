begin_unit
begin_comment
comment|/*************************************************************************** ** ** Copyright (C) 2011 - 2012 Research In Motion ** Contact: http://www.qt-project.org/legal ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia. For licensing terms and ** conditions see http://qt.digia.com/licensing. For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights. These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QQNXNAVIGATOREVENTNOTIFIER_H
end_ifndef
begin_define
DECL|macro|QQNXNAVIGATOREVENTNOTIFIER_H
define|#
directive|define
name|QQNXNAVIGATOREVENTNOTIFIER_H
end_define
begin_include
include|#
directive|include
file|<QObject>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QQnxNavigatorEventHandler
name|class
name|QQnxNavigatorEventHandler
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QSocketNotifier
name|class
name|QSocketNotifier
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QQnxNavigatorEventNotifier
range|:
name|public
name|QObject
block|{
name|Q_OBJECT
name|public
operator|:
name|explicit
name|QQnxNavigatorEventNotifier
argument_list|(
name|QQnxNavigatorEventHandler
operator|*
name|eventHandler
argument_list|,
name|QObject
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
operator|~
name|QQnxNavigatorEventNotifier
argument_list|()
block|;
name|public
name|Q_SLOTS
operator|:
name|void
name|start
argument_list|()
block|;
name|private
name|Q_SLOTS
operator|:
name|void
name|readData
argument_list|()
block|;
name|private
operator|:
name|void
name|parsePPS
argument_list|(
specifier|const
name|QByteArray
operator|&
name|ppsData
argument_list|,
name|QByteArray
operator|&
name|msg
argument_list|,
name|QByteArray
operator|&
name|dat
argument_list|,
name|QByteArray
operator|&
name|id
argument_list|)
block|;
name|void
name|replyPPS
argument_list|(
specifier|const
name|QByteArray
operator|&
name|res
argument_list|,
specifier|const
name|QByteArray
operator|&
name|id
argument_list|,
specifier|const
name|QByteArray
operator|&
name|dat
argument_list|)
block|;
name|void
name|handleMessage
argument_list|(
specifier|const
name|QByteArray
operator|&
name|msg
argument_list|,
specifier|const
name|QByteArray
operator|&
name|dat
argument_list|,
specifier|const
name|QByteArray
operator|&
name|id
argument_list|)
block|;
name|int
name|m_fd
block|;
name|QSocketNotifier
operator|*
name|m_readNotifier
block|;
name|QQnxNavigatorEventHandler
operator|*
name|m_eventHandler
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
comment|// QQNXNAVIGATOREVENTNOTIFIER_H
end_comment
end_unit
