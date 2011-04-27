begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtDBus module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** No Commercial Usage ** This file contains pre-release code and may not be distributed. ** You may use this file in accordance with the terms and conditions ** contained in the Technology Preview License Agreement accompanying ** this package. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights.  These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** If you have questions regarding the use of this file, please contact ** Nokia at qt-info@nokia.com. ** ** ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_comment
comment|/*  * This file was generated by qdbusxml2cpp version 0.7  * Command line was: qdbusxml2cpp -i interface.h -p pinger com.trolltech.QtDBus.Pinger.xml  *  * qdbusxml2cpp is Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies).  *  * This is an auto-generated file.  * Do not edit! All changes made to it will be lost.  */
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|PINGER_H_1246463415
end_ifndef
begin_define
DECL|macro|PINGER_H_1246463415
define|#
directive|define
name|PINGER_H_1246463415
end_define
begin_include
include|#
directive|include
file|<QtCore/QObject>
end_include
begin_include
include|#
directive|include
file|<QtCore/QByteArray>
end_include
begin_include
include|#
directive|include
file|<QtCore/QList>
end_include
begin_include
include|#
directive|include
file|<QtCore/QMap>
end_include
begin_include
include|#
directive|include
file|<QtCore/QString>
end_include
begin_include
include|#
directive|include
file|<QtCore/QStringList>
end_include
begin_include
include|#
directive|include
file|<QtCore/QVariant>
end_include
begin_include
include|#
directive|include
file|<QtDBus/QtDBus>
end_include
begin_include
include|#
directive|include
file|"interface.h"
end_include
begin_comment
comment|/*  * Proxy class for interface com.trolltech.QtDBus.Pinger  */
end_comment
begin_decl_stmt
name|class
name|ComTrolltechQtDBusPingerInterface
range|:
name|public
name|QDBusAbstractInterface
block|{
name|Q_OBJECT
name|public
operator|:
specifier|static
specifier|inline
specifier|const
name|char
operator|*
name|staticInterfaceName
argument_list|()
block|{
return|return
literal|"com.trolltech.QtDBus.Pinger"
return|;
block|}
name|public
operator|:
name|ComTrolltechQtDBusPingerInterface
argument_list|(
specifier|const
name|QString
operator|&
name|service
argument_list|,
specifier|const
name|QString
operator|&
name|path
argument_list|,
specifier|const
name|QDBusConnection
operator|&
name|connection
argument_list|,
name|QObject
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
operator|~
name|ComTrolltechQtDBusPingerInterface
argument_list|()
block|;
name|Q_PROPERTY
argument_list|(
argument|RegisteredType complexProp READ complexProp WRITE setComplexProp
argument_list|)
specifier|inline
name|RegisteredType
name|complexProp
argument_list|()
specifier|const
block|{
return|return
name|qvariant_cast
operator|<
name|RegisteredType
operator|>
operator|(
name|property
argument_list|(
literal|"complexProp"
argument_list|)
operator|)
return|;
block|}
specifier|inline
name|void
name|setComplexProp
argument_list|(
argument|RegisteredType value
argument_list|)
block|{
name|setProperty
argument_list|(
literal|"complexProp"
argument_list|,
name|qVariantFromValue
argument_list|(
name|value
argument_list|)
argument_list|)
block|; }
name|Q_PROPERTY
argument_list|(
argument|QString stringProp READ stringProp WRITE setStringProp
argument_list|)
specifier|inline
name|QString
name|stringProp
argument_list|()
specifier|const
block|{
return|return
name|qvariant_cast
operator|<
name|QString
operator|>
operator|(
name|property
argument_list|(
literal|"stringProp"
argument_list|)
operator|)
return|;
block|}
specifier|inline
name|void
name|setStringProp
argument_list|(
argument|const QString&value
argument_list|)
block|{
name|setProperty
argument_list|(
literal|"stringProp"
argument_list|,
name|qVariantFromValue
argument_list|(
name|value
argument_list|)
argument_list|)
block|; }
name|Q_PROPERTY
argument_list|(
argument|QDBusVariant variantProp READ variantProp WRITE setVariantProp
argument_list|)
specifier|inline
name|QDBusVariant
name|variantProp
argument_list|()
specifier|const
block|{
return|return
name|qvariant_cast
operator|<
name|QDBusVariant
operator|>
operator|(
name|property
argument_list|(
literal|"variantProp"
argument_list|)
operator|)
return|;
block|}
specifier|inline
name|void
name|setVariantProp
argument_list|(
argument|const QDBusVariant&value
argument_list|)
block|{
name|setProperty
argument_list|(
literal|"variantProp"
argument_list|,
name|qVariantFromValue
argument_list|(
name|value
argument_list|)
argument_list|)
block|; }
name|public
name|Q_SLOTS
operator|:
comment|// METHODS
specifier|inline
name|QDBusPendingReply
operator|<
name|RegisteredType
operator|>
name|complexMethod
argument_list|()
block|{
name|QList
operator|<
name|QVariant
operator|>
name|argumentList
block|;
return|return
name|asyncCallWithArgumentList
argument_list|(
name|QLatin1String
argument_list|(
literal|"complexMethod"
argument_list|)
argument_list|,
name|argumentList
argument_list|)
return|;
block|}
specifier|inline
name|QDBusPendingReply
operator|<
name|QString
block|,
name|int
operator|>
name|multiOutMethod
argument_list|()
block|{
name|QList
operator|<
name|QVariant
operator|>
name|argumentList
block|;
return|return
name|asyncCallWithArgumentList
argument_list|(
name|QLatin1String
argument_list|(
literal|"multiOutMethod"
argument_list|)
argument_list|,
name|argumentList
argument_list|)
return|;
block|}
specifier|inline
name|QDBusReply
operator|<
name|QString
operator|>
name|multiOutMethod
argument_list|(
argument|int&out1
argument_list|)
block|{
name|QList
operator|<
name|QVariant
operator|>
name|argumentList
block|;
name|QDBusMessage
name|reply
operator|=
name|callWithArgumentList
argument_list|(
name|QDBus
operator|::
name|Block
argument_list|,
name|QLatin1String
argument_list|(
literal|"multiOutMethod"
argument_list|)
argument_list|,
name|argumentList
argument_list|)
block|;
if|if
condition|(
name|reply
operator|.
name|type
argument_list|()
operator|==
name|QDBusMessage
operator|::
name|ReplyMessage
operator|&&
name|reply
operator|.
name|arguments
argument_list|()
operator|.
name|count
argument_list|()
operator|==
literal|2
condition|)
block|{
name|out1
operator|=
name|qdbus_cast
operator|<
name|int
operator|>
operator|(
name|reply
operator|.
name|arguments
argument_list|()
operator|.
name|at
argument_list|(
literal|1
argument_list|)
operator|)
expr_stmt|;
block|}
return|return
name|reply
return|;
block|}
specifier|inline
name|QDBusPendingReply
operator|<
name|QString
operator|>
name|stringMethod
argument_list|()
block|{
name|QList
operator|<
name|QVariant
operator|>
name|argumentList
block|;
return|return
name|asyncCallWithArgumentList
argument_list|(
name|QLatin1String
argument_list|(
literal|"stringMethod"
argument_list|)
argument_list|,
name|argumentList
argument_list|)
return|;
block|}
specifier|inline
name|QDBusPendingReply
operator|<
operator|>
name|voidMethod
argument_list|()
block|{
name|QList
operator|<
name|QVariant
operator|>
name|argumentList
block|;
return|return
name|asyncCallWithArgumentList
argument_list|(
name|QLatin1String
argument_list|(
literal|"voidMethod"
argument_list|)
argument_list|,
name|argumentList
argument_list|)
return|;
block|}
name|Q_SIGNALS
operator|:
comment|// SIGNALS
name|void
name|complexSignal
argument_list|(
argument|RegisteredType in0
argument_list|)
block|;
name|void
name|stringSignal
argument_list|(
specifier|const
name|QString
operator|&
name|in0
argument_list|)
block|;
name|void
name|voidSignal
argument_list|()
block|; }
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|namespace
name|com
block|{
name|namespace
name|trolltech
block|{
name|namespace
name|QtDBus
block|{
typedef|typedef
operator|::
name|ComTrolltechQtDBusPingerInterface
name|Pinger
expr_stmt|;
block|}
block|}
block|}
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
end_unit
