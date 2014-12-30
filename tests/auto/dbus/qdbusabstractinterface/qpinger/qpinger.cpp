begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2014 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia. For licensing terms and ** conditions see http://qt.digia.com/licensing. For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights. These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtCore/QtCore>
end_include
begin_include
include|#
directive|include
file|<QtDBus/QtDBus>
end_include
begin_include
include|#
directive|include
file|"../interface.h"
end_include
begin_decl_stmt
DECL|variable|serviceName
specifier|static
specifier|const
name|char
name|serviceName
index|[]
init|=
literal|"org.qtproject.autotests.qpinger"
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|objectPath
specifier|static
specifier|const
name|char
name|objectPath
index|[]
init|=
literal|"/org/qtproject/qpinger"
decl_stmt|;
end_decl_stmt
begin_comment
comment|//static const char *interfaceName = serviceName;
end_comment
begin_class
DECL|class|PingerServer
class|class
name|PingerServer
super|:
specifier|public
name|QDBusServer
super|,
specifier|protected
name|QDBusContext
block|{
name|Q_OBJECT
name|Q_CLASSINFO
argument_list|(
literal|"D-Bus Interface"
argument_list|,
literal|"org.qtproject.autotests.qpinger"
argument_list|)
decl|public
range|:
DECL|function|PingerServer
name|PingerServer
argument_list|(
name|QObject
operator|*
name|parent
operator|=
literal|0
argument_list|)
operator|:
name|QDBusServer
argument_list|(
name|parent
argument_list|)
decl_stmt|,
name|m_conn
argument_list|(
literal|"none"
argument_list|)
argument_list|{
name|connect
argument_list|(
name|this
argument_list|,
name|SIGNAL
argument_list|(
name|newConnection
argument_list|(
name|QDBusConnection
argument_list|)
argument_list|)
argument_list|,
name|SLOT
argument_list|(
name|handleConnection
argument_list|(
name|QDBusConnection
argument_list|)
argument_list|)
argument_list|)
argument_list|;
name|reset
argument_list|()
argument_list|;     }
decl|public
name|slots
range|:
DECL|function|address
name|QString
name|address
argument_list|()
specifier|const
block|{
if|if
condition|(
operator|!
name|QDBusServer
operator|::
name|isConnected
argument_list|()
condition|)
name|sendErrorReply
argument_list|(
name|QDBusServer
operator|::
name|lastError
argument_list|()
operator|.
name|name
argument_list|()
argument_list|,
name|QDBusServer
operator|::
name|lastError
argument_list|()
operator|.
name|message
argument_list|()
argument_list|)
expr_stmt|;
return|return
name|QDBusServer
operator|::
name|address
argument_list|()
return|;
block|}
DECL|function|isConnected
name|bool
name|isConnected
argument_list|()
decl|const
argument_list|{         return
name|m_conn
operator|.
name|isConnected
argument_list|()
argument_list|;     }
DECL|function|reset
name|void
name|reset
argument_list|()
argument_list|{
name|targetObj
operator|.
name|m_stringProp
operator|=
literal|"This is a test"
argument_list|;
name|targetObj
operator|.
name|m_variantProp
operator|=
name|QDBusVariant
argument_list|(
name|QVariant
argument_list|(
literal|42
argument_list|)
argument_list|)
argument_list|;
name|targetObj
operator|.
name|m_complexProp
operator|=
name|RegisteredType
argument_list|(
literal|"This is a test"
argument_list|)
argument_list|;     }
DECL|function|voidSignal
name|void
name|voidSignal
argument_list|()
argument_list|{         emit
name|targetObj
operator|.
name|voidSignal
argument_list|()
argument_list|;     }
DECL|function|stringSignal
name|void
name|stringSignal
argument_list|(
specifier|const
name|QString
operator|&
name|value
argument_list|)
argument_list|{         emit
name|targetObj
operator|.
name|stringSignal
argument_list|(
name|value
argument_list|)
argument_list|;     }
DECL|function|complexSignal
name|void
name|complexSignal
argument_list|(
specifier|const
name|QString
operator|&
name|value
argument_list|)
argument_list|{
name|RegisteredType
name|reg
argument_list|(
name|value
argument_list|)
argument_list|;         emit
name|targetObj
operator|.
name|complexSignal
argument_list|(
name|reg
argument_list|)
argument_list|;     }
decl|private
name|slots
range|:
DECL|function|handleConnection
name|void
name|handleConnection
argument_list|(
argument|const QDBusConnection& con
argument_list|)
block|{
name|m_conn
operator|=
name|con
block|;
name|m_conn
operator|.
name|registerObject
argument_list|(
literal|"/"
argument_list|,
operator|&
name|targetObj
argument_list|,
name|QDBusConnection
operator|::
name|ExportScriptableContents
argument_list|)
block|;     }
specifier|private
operator|:
DECL|member|targetObj
name|Interface
name|targetObj
class|;
end_class
begin_decl_stmt
DECL|member|m_conn
name|QDBusConnection
name|m_conn
decl_stmt|;
end_decl_stmt
begin_function
DECL|member|m_conn
unit|};
DECL|function|main
name|int
name|main
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
name|argv
index|[]
parameter_list|)
block|{
name|QCoreApplication
name|app
argument_list|(
name|argc
argument_list|,
name|argv
argument_list|)
decl_stmt|;
comment|// register the meta types
name|qDBusRegisterMetaType
argument_list|<
name|RegisteredType
argument_list|>
argument_list|()
expr_stmt|;
name|qRegisterMetaType
argument_list|<
name|UnregisteredType
argument_list|>
argument_list|()
expr_stmt|;
name|QDBusConnection
name|con
init|=
name|QDBusConnection
operator|::
name|sessionBus
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
name|con
operator|.
name|isConnected
argument_list|()
condition|)
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|con
operator|.
name|registerService
argument_list|(
name|serviceName
argument_list|)
condition|)
name|exit
argument_list|(
literal|2
argument_list|)
expr_stmt|;
name|PingerServer
name|server
decl_stmt|;
name|con
operator|.
name|registerObject
argument_list|(
name|objectPath
argument_list|,
operator|&
name|server
argument_list|,
name|QDBusConnection
operator|::
name|ExportAllSlots
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"ready.\n"
argument_list|)
expr_stmt|;
name|fflush
argument_list|(
name|stdout
argument_list|)
expr_stmt|;
return|return
name|app
operator|.
name|exec
argument_list|()
return|;
block|}
end_function
begin_include
include|#
directive|include
file|"qpinger.moc"
end_include
end_unit
