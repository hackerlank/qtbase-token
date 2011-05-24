begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtNetwork module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QNETWORKDISKCACHE_H
end_ifndef
begin_define
DECL|macro|QNETWORKDISKCACHE_H
define|#
directive|define
name|QNETWORKDISKCACHE_H
end_define
begin_include
include|#
directive|include
file|<QtNetwork/qabstractnetworkcache.h>
end_include
begin_decl_stmt
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
name|QT_MODULE
argument_list|(
name|Network
argument_list|)
ifndef|#
directive|ifndef
name|QT_NO_NETWORKDISKCACHE
name|class
name|QNetworkDiskCachePrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_NETWORK_EXPORT
name|QNetworkDiskCache
range|:
name|public
name|QAbstractNetworkCache
block|{
name|Q_OBJECT
name|public
operator|:
name|explicit
name|QNetworkDiskCache
argument_list|(
name|QObject
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
operator|~
name|QNetworkDiskCache
argument_list|()
block|;
name|QString
name|cacheDirectory
argument_list|()
specifier|const
block|;
name|void
name|setCacheDirectory
argument_list|(
specifier|const
name|QString
operator|&
name|cacheDir
argument_list|)
block|;
name|qint64
name|maximumCacheSize
argument_list|()
specifier|const
block|;
name|void
name|setMaximumCacheSize
argument_list|(
argument|qint64 size
argument_list|)
block|;
name|qint64
name|cacheSize
argument_list|()
specifier|const
block|;
name|QNetworkCacheMetaData
name|metaData
argument_list|(
specifier|const
name|QUrl
operator|&
name|url
argument_list|)
block|;
name|void
name|updateMetaData
argument_list|(
specifier|const
name|QNetworkCacheMetaData
operator|&
name|metaData
argument_list|)
block|;
name|QIODevice
operator|*
name|data
argument_list|(
specifier|const
name|QUrl
operator|&
name|url
argument_list|)
block|;
name|bool
name|remove
argument_list|(
specifier|const
name|QUrl
operator|&
name|url
argument_list|)
block|;
name|QIODevice
operator|*
name|prepare
argument_list|(
specifier|const
name|QNetworkCacheMetaData
operator|&
name|metaData
argument_list|)
block|;
name|void
name|insert
argument_list|(
name|QIODevice
operator|*
name|device
argument_list|)
block|;
name|QNetworkCacheMetaData
name|fileMetaData
argument_list|(
argument|const QString&fileName
argument_list|)
specifier|const
block|;
name|public
name|Q_SLOTS
operator|:
name|void
name|clear
argument_list|()
block|;
name|protected
operator|:
name|virtual
name|qint64
name|expire
argument_list|()
block|;
name|private
operator|:
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QNetworkDiskCache
argument_list|)
name|Q_DISABLE_COPY
argument_list|(
argument|QNetworkDiskCache
argument_list|)
block|}
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_NETWORKDISKCACHE
end_comment
begin_expr_stmt
name|QT_END_NAMESPACE
name|QT_END_HEADER
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QNETWORKDISKCACHE_H
end_comment
end_unit
