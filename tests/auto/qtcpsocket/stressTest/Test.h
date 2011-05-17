begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** No Commercial Usage ** This file contains pre-release code and may not be distributed. ** You may use this file in accordance with the terms and conditions ** contained in the Technology Preview License Agreement accompanying ** this package. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights.  These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** If you have questions regarding the use of this file, please contact ** Nokia at qt-info@nokia.com. ** ** ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|TEST_H
end_ifndef
begin_define
DECL|macro|TEST_H
define|#
directive|define
name|TEST_H
end_define
begin_comment
comment|//------------------------------------------------------------------------------
end_comment
begin_include
include|#
directive|include
file|<QTcpServer>
end_include
begin_include
include|#
directive|include
file|<QTcpSocket>
end_include
begin_comment
comment|//------------------------------------------------------------------------------
end_comment
begin_decl_stmt
name|class
name|My4Socket
range|:
name|public
name|QTcpSocket
block|{
name|Q_OBJECT
name|public
operator|:
name|My4Socket
argument_list|(
name|QObject
operator|*
name|parent
argument_list|)
block|;
name|void
name|sendTest
argument_list|(
argument|quint32 num
argument_list|)
block|;
name|bool
name|safeShutDown
block|;
name|private
name|slots
operator|:
name|void
name|read
argument_list|()
block|;
name|void
name|closed
argument_list|()
block|; }
decl_stmt|;
end_decl_stmt
begin_comment
comment|//------------------------------------------------------------------------------
end_comment
begin_decl_stmt
name|class
name|My4Server
range|:
name|public
name|QTcpServer
block|{
name|Q_OBJECT
name|public
operator|:
name|My4Server
argument_list|(
name|QObject
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
name|protected
operator|:
name|void
name|incomingConnection
argument_list|(
argument|int socket
argument_list|)
block|;
name|private
name|slots
operator|:
name|void
name|stopServer
argument_list|()
block|;
name|private
operator|:
name|My4Socket
operator|*
name|m_socket
block|; }
decl_stmt|;
end_decl_stmt
begin_comment
comment|//------------------------------------------------------------------------------
end_comment
begin_decl_stmt
name|class
name|Test
range|:
name|public
name|QObject
block|{
name|Q_OBJECT
name|public
operator|:
expr|enum
name|Type
block|{
name|Qt4Client
block|,
name|Qt4Server
block|,     }
block|;
name|Test
argument_list|(
argument|Type type
argument_list|)
block|; }
decl_stmt|;
end_decl_stmt
begin_comment
comment|//------------------------------------------------------------------------------
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// TEST_H
end_comment
end_unit
