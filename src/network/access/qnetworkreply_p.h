begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2014 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtNetwork module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia. For licensing terms and ** conditions see http://qt.digia.com/licensing. For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights. These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QNETWORKREPLY_P_H
end_ifndef
begin_define
DECL|macro|QNETWORKREPLY_P_H
define|#
directive|define
name|QNETWORKREPLY_P_H
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
comment|// This file is not part of the Qt API.  It exists for the convenience
end_comment
begin_comment
comment|// of the Network Access API.  This header file may change from
end_comment
begin_comment
comment|// version to version without notice, or even be removed.
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
file|"qnetworkrequest.h"
end_include
begin_include
include|#
directive|include
file|"qnetworkrequest_p.h"
end_include
begin_include
include|#
directive|include
file|"qnetworkreply.h"
end_include
begin_include
include|#
directive|include
file|"QtCore/qpointer.h"
end_include
begin_include
include|#
directive|include
file|<QtCore/QElapsedTimer>
end_include
begin_include
include|#
directive|include
file|"private/qiodevice_p.h"
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QIODevicePrivate
name|class
name|QNetworkReplyPrivate
range|:
name|public
name|QIODevicePrivate
decl_stmt|,
name|public
name|QNetworkHeadersPrivate
block|{
name|public
label|:
enum|enum
name|State
block|{
name|Idle
block|,
comment|// The reply is idle.
name|Buffering
block|,
comment|// The reply is buffering outgoing data.
name|Working
block|,
comment|// The reply is uploading/downloading data.
name|Finished
block|,
comment|// The reply has finished.
name|Aborted
block|,
comment|// The reply has been aborted.
name|WaitingForSession
block|,
comment|// The reply is waiting for the session to open before connecting.
name|Reconnecting
comment|// The reply will reconnect to once roaming has completed.
block|}
enum|;
name|QNetworkReplyPrivate
argument_list|()
expr_stmt|;
name|QNetworkRequest
name|request
decl_stmt|;
name|QUrl
name|url
decl_stmt|;
name|QPointer
operator|<
name|QNetworkAccessManager
operator|>
name|manager
expr_stmt|;
name|qint64
name|readBufferMaxSize
decl_stmt|;
name|QElapsedTimer
name|downloadProgressSignalChoke
decl_stmt|;
name|QElapsedTimer
name|uploadProgressSignalChoke
decl_stmt|;
specifier|const
specifier|static
name|int
name|progressSignalInterval
decl_stmt|;
name|QNetworkAccessManager
operator|::
name|Operation
name|operation
expr_stmt|;
name|QNetworkReply
operator|::
name|NetworkError
name|errorCode
expr_stmt|;
name|bool
name|isFinished
decl_stmt|;
specifier|static
specifier|inline
name|void
name|setManager
parameter_list|(
name|QNetworkReply
modifier|*
name|reply
parameter_list|,
name|QNetworkAccessManager
modifier|*
name|manager
parameter_list|)
block|{
name|reply
operator|->
name|d_func
argument_list|()
operator|->
name|manager
operator|=
name|manager
expr_stmt|;
block|}
name|Q_DECLARE_PUBLIC
argument_list|(
argument|QNetworkReply
argument_list|)
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
end_unit
