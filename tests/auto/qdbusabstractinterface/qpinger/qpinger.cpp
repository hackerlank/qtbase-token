begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** No Commercial Usage ** This file contains pre-release code and may not be distributed. ** You may use this file in accordance with the terms and conditions ** contained in the Technology Preview License Agreement accompanying ** this package. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights.  These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** If you have questions regarding the use of this file, please contact ** Nokia at qt-info@nokia.com. ** ** ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
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
literal|"com.trolltech.autotests.qpinger"
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
literal|"/com/trolltech/qpinger"
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
block|{
name|Q_OBJECT
name|Q_CLASSINFO
argument_list|(
literal|"D-Bus Interface"
argument_list|,
literal|"com.trolltech.autotests.qpinger"
argument_list|)
decl|public
range|:
DECL|function|PingerServer
name|PingerServer
argument_list|(
argument|QString addr =
literal|"unix:tmpdir=/tmp"
argument_list|,
argument|QObject* parent =
literal|0
argument_list|)
operator|:
name|QDBusServer
argument_list|(
name|addr
argument_list|,
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
specifier|const
name|QDBusConnection
operator|&
argument_list|)
argument_list|)
argument_list|,
name|SLOT
argument_list|(
name|handleConnection
argument_list|(
specifier|const
name|QDBusConnection
operator|&
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
parameter_list|()
specifier|const
block|{
return|return
name|m_conn
operator|.
name|isConnected
argument_list|()
return|;
block|}
DECL|function|reset
name|void
name|reset
parameter_list|()
block|{
name|targetObj
operator|.
name|m_stringProp
operator|=
literal|"This is a test"
expr_stmt|;
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
expr_stmt|;
name|targetObj
operator|.
name|m_complexProp
operator|=
name|RegisteredType
argument_list|(
literal|"This is a test"
argument_list|)
expr_stmt|;
block|}
DECL|function|voidSignal
name|void
name|voidSignal
parameter_list|()
block|{
emit|emit
name|targetObj
operator|.
name|voidSignal
argument_list|()
emit|;
block|}
DECL|function|stringSignal
name|void
name|stringSignal
parameter_list|(
specifier|const
name|QString
modifier|&
name|value
parameter_list|)
block|{
emit|emit
name|targetObj
operator|.
name|stringSignal
argument_list|(
name|value
argument_list|)
emit|;
block|}
DECL|function|complexSignal
name|void
name|complexSignal
parameter_list|(
specifier|const
name|QString
modifier|&
name|value
parameter_list|)
block|{
name|RegisteredType
name|reg
argument_list|(
name|value
argument_list|)
decl_stmt|;
emit|emit
name|targetObj
operator|.
name|complexSignal
argument_list|(
name|reg
argument_list|)
emit|;
block|}
private|private
name|slots
private|:
DECL|function|handleConnection
name|void
name|handleConnection
parameter_list|(
specifier|const
name|QDBusConnection
modifier|&
name|con
parameter_list|)
block|{
name|m_conn
operator|=
name|con
expr_stmt|;
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
expr_stmt|;
block|}
private|private:
DECL|member|targetObj
name|Interface
name|targetObj
decl_stmt|;
DECL|member|m_conn
name|QDBusConnection
name|m_conn
decl_stmt|;
block|}
class|;
end_class
begin_function
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
