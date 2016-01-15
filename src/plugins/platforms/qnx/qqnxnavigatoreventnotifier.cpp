begin_unit
begin_comment
comment|/*************************************************************************** ** ** Copyright (C) 2011 - 2012 Research In Motion ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qqnxnavigatoreventnotifier.h"
end_include
begin_include
include|#
directive|include
file|"qqnxnavigatoreventhandler.h"
end_include
begin_include
include|#
directive|include
file|<QtCore/QByteArray>
end_include
begin_include
include|#
directive|include
file|<QtCore/QDebug>
end_include
begin_include
include|#
directive|include
file|<QtCore/QList>
end_include
begin_include
include|#
directive|include
file|<QtCore/QSocketNotifier>
end_include
begin_include
include|#
directive|include
file|<QtCore/private/qcore_unix_p.h>
end_include
begin_include
include|#
directive|include
file|<errno.h>
end_include
begin_include
include|#
directive|include
file|<fcntl.h>
end_include
begin_include
include|#
directive|include
file|<unistd.h>
end_include
begin_include
include|#
directive|include
file|<sys/types.h>
end_include
begin_include
include|#
directive|include
file|<sys/stat.h>
end_include
begin_if
if|#
directive|if
name|defined
argument_list|(
name|QQNXNAVIGATOREVENTNOTIFIER_DEBUG
argument_list|)
end_if
begin_define
DECL|macro|qNavigatorEventNotifierDebug
define|#
directive|define
name|qNavigatorEventNotifierDebug
value|qDebug
end_define
begin_else
else|#
directive|else
end_else
begin_define
DECL|macro|qNavigatorEventNotifierDebug
define|#
directive|define
name|qNavigatorEventNotifierDebug
value|QT_NO_QDEBUG_MACRO
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_decl_stmt
DECL|variable|navigatorControlPath
specifier|static
specifier|const
name|char
modifier|*
name|navigatorControlPath
init|=
literal|"/pps/services/navigator/control"
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|ppsBufferSize
specifier|static
specifier|const
name|int
name|ppsBufferSize
init|=
literal|4096
decl_stmt|;
end_decl_stmt
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_constructor
DECL|function|QQnxNavigatorEventNotifier
name|QQnxNavigatorEventNotifier
operator|::
name|QQnxNavigatorEventNotifier
parameter_list|(
name|QQnxNavigatorEventHandler
modifier|*
name|eventHandler
parameter_list|,
name|QObject
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QObject
argument_list|(
name|parent
argument_list|)
member_init_list|,
name|m_fd
argument_list|(
operator|-
literal|1
argument_list|)
member_init_list|,
name|m_readNotifier
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|m_eventHandler
argument_list|(
name|eventHandler
argument_list|)
block|{ }
end_constructor
begin_destructor
DECL|function|~QQnxNavigatorEventNotifier
name|QQnxNavigatorEventNotifier
operator|::
name|~
name|QQnxNavigatorEventNotifier
parameter_list|()
block|{
operator|delete
name|m_readNotifier
expr_stmt|;
comment|// close connection to navigator
if|if
condition|(
name|m_fd
operator|!=
operator|-
literal|1
condition|)
name|close
argument_list|(
name|m_fd
argument_list|)
expr_stmt|;
name|qNavigatorEventNotifierDebug
argument_list|(
literal|"navigator event notifier stopped"
argument_list|)
expr_stmt|;
block|}
end_destructor
begin_function
DECL|function|start
name|void
name|QQnxNavigatorEventNotifier
operator|::
name|start
parameter_list|()
block|{
name|qNavigatorEventNotifierDebug
argument_list|(
literal|"navigator event notifier started"
argument_list|)
expr_stmt|;
comment|// open connection to navigator
name|errno
operator|=
literal|0
expr_stmt|;
name|m_fd
operator|=
name|open
argument_list|(
name|navigatorControlPath
argument_list|,
name|O_RDWR
argument_list|)
expr_stmt|;
if|if
condition|(
name|m_fd
operator|==
operator|-
literal|1
condition|)
block|{
name|qNavigatorEventNotifierDebug
argument_list|()
operator|<<
literal|"failed to open navigator pps:"
operator|<<
name|strerror
argument_list|(
name|errno
argument_list|)
expr_stmt|;
return|return;
block|}
name|m_readNotifier
operator|=
operator|new
name|QSocketNotifier
argument_list|(
name|m_fd
argument_list|,
name|QSocketNotifier
operator|::
name|Read
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|m_readNotifier
argument_list|,
name|SIGNAL
argument_list|(
name|activated
argument_list|(
name|int
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|readData
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|parsePPS
name|void
name|QQnxNavigatorEventNotifier
operator|::
name|parsePPS
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|ppsData
parameter_list|,
name|QByteArray
modifier|&
name|msg
parameter_list|,
name|QByteArray
modifier|&
name|dat
parameter_list|,
name|QByteArray
modifier|&
name|id
parameter_list|)
block|{
name|qNavigatorEventNotifierDebug
argument_list|()
operator|<<
literal|"data="
operator|<<
name|ppsData
expr_stmt|;
comment|// tokenize pps data into lines
name|QList
argument_list|<
name|QByteArray
argument_list|>
name|lines
init|=
name|ppsData
operator|.
name|split
argument_list|(
literal|'\n'
argument_list|)
decl_stmt|;
comment|// validate pps object
if|if
condition|(
name|Q_UNLIKELY
argument_list|(
name|lines
operator|.
name|empty
argument_list|()
operator|||
name|lines
operator|.
name|at
argument_list|(
literal|0
argument_list|)
operator|!=
literal|"@control"
argument_list|)
condition|)
name|qFatal
argument_list|(
literal|"QQNX: unrecognized pps object, data=%s"
argument_list|,
name|ppsData
operator|.
name|constData
argument_list|()
argument_list|)
expr_stmt|;
comment|// parse pps object attributes and extract values
for|for
control|(
name|int
name|i
init|=
literal|1
init|;
name|i
operator|<
name|lines
operator|.
name|size
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
comment|// tokenize current attribute
specifier|const
name|QByteArray
modifier|&
name|attr
init|=
name|lines
operator|.
name|at
argument_list|(
name|i
argument_list|)
decl_stmt|;
name|qNavigatorEventNotifierDebug
argument_list|()
operator|<<
literal|"attr="
operator|<<
name|attr
expr_stmt|;
name|int
name|firstColon
init|=
name|attr
operator|.
name|indexOf
argument_list|(
literal|':'
argument_list|)
decl_stmt|;
if|if
condition|(
name|firstColon
operator|==
operator|-
literal|1
condition|)
block|{
comment|// abort - malformed attribute
continue|continue;
block|}
name|int
name|secondColon
init|=
name|attr
operator|.
name|indexOf
argument_list|(
literal|':'
argument_list|,
name|firstColon
operator|+
literal|1
argument_list|)
decl_stmt|;
if|if
condition|(
name|secondColon
operator|==
operator|-
literal|1
condition|)
block|{
comment|// abort - malformed attribute
continue|continue;
block|}
name|QByteArray
name|key
init|=
name|attr
operator|.
name|left
argument_list|(
name|firstColon
argument_list|)
decl_stmt|;
name|QByteArray
name|value
init|=
name|attr
operator|.
name|mid
argument_list|(
name|secondColon
operator|+
literal|1
argument_list|)
decl_stmt|;
name|qNavigatorEventNotifierDebug
argument_list|()
operator|<<
literal|"key="
operator|<<
name|key
expr_stmt|;
name|qNavigatorEventNotifierDebug
argument_list|()
operator|<<
literal|"val="
operator|<<
name|value
expr_stmt|;
comment|// save attribute value
if|if
condition|(
name|key
operator|==
literal|"msg"
condition|)
name|msg
operator|=
name|value
expr_stmt|;
elseif|else
if|if
condition|(
name|key
operator|==
literal|"dat"
condition|)
name|dat
operator|=
name|value
expr_stmt|;
elseif|else
if|if
condition|(
name|key
operator|==
literal|"id"
condition|)
name|id
operator|=
name|value
expr_stmt|;
else|else
name|qFatal
argument_list|(
literal|"QQNX: unrecognized pps attribute, attr=%s"
argument_list|,
name|key
operator|.
name|constData
argument_list|()
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|replyPPS
name|void
name|QQnxNavigatorEventNotifier
operator|::
name|replyPPS
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|res
parameter_list|,
specifier|const
name|QByteArray
modifier|&
name|id
parameter_list|,
specifier|const
name|QByteArray
modifier|&
name|dat
parameter_list|)
block|{
comment|// construct pps message
name|QByteArray
name|ppsData
init|=
literal|"res::"
decl_stmt|;
name|ppsData
operator|+=
name|res
expr_stmt|;
name|ppsData
operator|+=
literal|"\nid::"
expr_stmt|;
name|ppsData
operator|+=
name|id
expr_stmt|;
if|if
condition|(
operator|!
name|dat
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|ppsData
operator|+=
literal|"\ndat::"
expr_stmt|;
name|ppsData
operator|+=
name|dat
expr_stmt|;
block|}
name|ppsData
operator|+=
literal|"\n"
expr_stmt|;
name|qNavigatorEventNotifierDebug
argument_list|()
operator|<<
literal|"reply="
operator|<<
name|ppsData
expr_stmt|;
comment|// send pps message to navigator
name|errno
operator|=
literal|0
expr_stmt|;
name|int
name|bytes
init|=
name|write
argument_list|(
name|m_fd
argument_list|,
name|ppsData
operator|.
name|constData
argument_list|()
argument_list|,
name|ppsData
operator|.
name|size
argument_list|()
argument_list|)
decl_stmt|;
if|if
condition|(
name|Q_UNLIKELY
argument_list|(
name|bytes
operator|==
operator|-
literal|1
argument_list|)
condition|)
name|qFatal
argument_list|(
literal|"QQNX: failed to write navigator pps, errno=%d"
argument_list|,
name|errno
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|handleMessage
name|void
name|QQnxNavigatorEventNotifier
operator|::
name|handleMessage
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|msg
parameter_list|,
specifier|const
name|QByteArray
modifier|&
name|dat
parameter_list|,
specifier|const
name|QByteArray
modifier|&
name|id
parameter_list|)
block|{
name|qNavigatorEventNotifierDebug
argument_list|()
operator|<<
literal|"msg="
operator|<<
name|msg
operator|<<
literal|", dat="
operator|<<
name|dat
operator|<<
literal|", id="
operator|<<
name|id
expr_stmt|;
comment|// check message type
if|if
condition|(
name|msg
operator|==
literal|"orientationCheck"
condition|)
block|{
specifier|const
name|bool
name|response
init|=
name|m_eventHandler
operator|->
name|handleOrientationCheck
argument_list|(
name|dat
operator|.
name|toInt
argument_list|()
argument_list|)
decl_stmt|;
comment|// reply to navigator that (any) orientation is acceptable
name|replyPPS
argument_list|(
name|msg
argument_list|,
name|id
argument_list|,
name|response
condition|?
literal|"true"
else|:
literal|"false"
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|msg
operator|==
literal|"orientation"
condition|)
block|{
name|m_eventHandler
operator|->
name|handleOrientationChange
argument_list|(
name|dat
operator|.
name|toInt
argument_list|()
argument_list|)
expr_stmt|;
name|replyPPS
argument_list|(
name|msg
argument_list|,
name|id
argument_list|,
literal|""
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|msg
operator|==
literal|"SWIPE_DOWN"
condition|)
block|{
name|m_eventHandler
operator|->
name|handleSwipeDown
argument_list|()
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|msg
operator|==
literal|"exit"
condition|)
block|{
name|m_eventHandler
operator|->
name|handleExit
argument_list|()
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|msg
operator|==
literal|"windowActive"
condition|)
block|{
name|m_eventHandler
operator|->
name|handleWindowGroupActivated
argument_list|(
name|dat
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|msg
operator|==
literal|"windowInactive"
condition|)
block|{
name|m_eventHandler
operator|->
name|handleWindowGroupDeactivated
argument_list|(
name|dat
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|readData
name|void
name|QQnxNavigatorEventNotifier
operator|::
name|readData
parameter_list|()
block|{
name|qNavigatorEventNotifierDebug
argument_list|(
literal|"reading navigator data"
argument_list|)
expr_stmt|;
comment|// allocate buffer for pps data
name|char
name|buffer
index|[
name|ppsBufferSize
index|]
decl_stmt|;
comment|// attempt to read pps data
name|errno
operator|=
literal|0
expr_stmt|;
name|int
name|bytes
init|=
name|qt_safe_read
argument_list|(
name|m_fd
argument_list|,
name|buffer
argument_list|,
name|ppsBufferSize
operator|-
literal|1
argument_list|)
decl_stmt|;
if|if
condition|(
name|Q_UNLIKELY
argument_list|(
name|bytes
operator|==
operator|-
literal|1
argument_list|)
condition|)
name|qFatal
argument_list|(
literal|"QQNX: failed to read navigator pps, errno=%d"
argument_list|,
name|errno
argument_list|)
expr_stmt|;
comment|// check if pps data was received
if|if
condition|(
name|bytes
operator|>
literal|0
condition|)
block|{
comment|// ensure data is null terminated
name|buffer
index|[
name|bytes
index|]
operator|=
literal|'\0'
expr_stmt|;
comment|// process received message
name|QByteArray
name|ppsData
argument_list|(
name|buffer
argument_list|)
decl_stmt|;
name|QByteArray
name|msg
decl_stmt|;
name|QByteArray
name|dat
decl_stmt|;
name|QByteArray
name|id
decl_stmt|;
name|parsePPS
argument_list|(
name|ppsData
argument_list|,
name|msg
argument_list|,
name|dat
argument_list|,
name|id
argument_list|)
expr_stmt|;
name|handleMessage
argument_list|(
name|msg
argument_list|,
name|dat
argument_list|,
name|id
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
