begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** No Commercial Usage ** This file contains pre-release code and may not be distributed. ** You may use this file in accordance with the terms and conditions ** contained in the Technology Preview License Agreement accompanying ** this package. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights.  These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** If you have questions regarding the use of this file, please contact ** Nokia at qt-info@nokia.com. ** ** ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|SERVEROBJECT_H
end_ifndef
begin_define
DECL|macro|SERVEROBJECT_H
define|#
directive|define
name|SERVEROBJECT_H
end_define
begin_include
include|#
directive|include
file|<QObject>
end_include
begin_include
include|#
directive|include
file|<QtDBus/QtDBus>
end_include
begin_decl_stmt
name|class
name|ServerObject
range|:
name|public
name|QObject
block|{
name|Q_OBJECT
name|Q_CLASSINFO
argument_list|(
literal|"D-Bus Interface"
argument_list|,
literal|"com.trolltech.autotests.Performance"
argument_list|)
name|public
operator|:
name|ServerObject
argument_list|(
argument|const QString&objectPath
argument_list|,
argument|QDBusConnection conn
argument_list|,
argument|QObject *parent =
literal|0
argument_list|)
operator|:
name|QObject
argument_list|(
argument|parent
argument_list|)
block|{
name|conn
operator|.
name|registerObject
argument_list|(
name|objectPath
argument_list|,
name|this
argument_list|,
name|QDBusConnection
operator|::
name|ExportAllSlots
argument_list|)
block|;     }
name|public
name|slots
operator|:
name|Q_NOREPLY
name|void
name|noReply
argument_list|(
argument|const QByteArray&
argument_list|)
block|{
comment|// black hole
block|}
name|Q_NOREPLY
name|void
name|noReply
argument_list|(
argument|const QString&
argument_list|)
block|{
comment|// black hole
block|}
name|Q_NOREPLY
name|void
name|noReply
argument_list|(
argument|const QDBusVariant&
argument_list|)
block|{
comment|// black hole
block|}
name|int
name|size
argument_list|(
argument|const QByteArray&data
argument_list|)
block|{
return|return
name|data
operator|.
name|size
argument_list|()
return|;
block|}
name|int
name|size
argument_list|(
argument|const QString&data
argument_list|)
block|{
return|return
name|data
operator|.
name|size
argument_list|()
return|;
block|}
name|int
name|size
argument_list|(
argument|const QDBusVariant&data
argument_list|)
block|{
name|QVariant
name|v
operator|=
name|data
operator|.
name|variant
argument_list|()
block|;
switch|switch
condition|(
name|v
operator|.
name|type
argument_list|()
condition|)
block|{
case|case
name|QVariant
operator|::
name|ByteArray
case|:
return|return
name|v
operator|.
name|toByteArray
argument_list|()
operator|.
name|size
argument_list|()
return|;
case|case
name|QVariant
operator|::
name|StringList
case|:
return|return
name|v
operator|.
name|toStringList
argument_list|()
operator|.
name|size
argument_list|()
return|;
case|case
name|QVariant
operator|::
name|String
case|:
default|default:
return|return
name|v
operator|.
name|toString
argument_list|()
operator|.
name|size
argument_list|()
return|;
block|}
block|}
name|QByteArray
name|echo
argument_list|(
argument|const QByteArray&data
argument_list|)
block|{
return|return
name|data
return|;
block|}
name|QString
name|echo
argument_list|(
argument|const QString&data
argument_list|)
block|{
return|return
name|data
return|;
block|}
name|QDBusVariant
name|echo
argument_list|(
argument|const QDBusVariant&data
argument_list|)
block|{
return|return
name|data
return|;
block|}
name|void
name|nothing
argument_list|()
block|{     }
expr|}
block|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
end_unit
