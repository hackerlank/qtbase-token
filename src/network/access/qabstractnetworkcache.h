begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtNetwork module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QABSTRACTNETWORKCACHE_H
end_ifndef
begin_define
DECL|macro|QABSTRACTNETWORKCACHE_H
define|#
directive|define
name|QABSTRACTNETWORKCACHE_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qobject.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qshareddata.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qpair.h>
end_include
begin_include
include|#
directive|include
file|<QtNetwork/qnetworkrequest.h>
end_include
begin_decl_stmt
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
DECL|variable|QIODevice
name|class
name|QIODevice
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QDateTime
name|class
name|QDateTime
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QUrl
name|class
name|QUrl
decl_stmt|;
end_decl_stmt
begin_expr_stmt
DECL|variable|QList
name|template
operator|<
name|class
name|T
operator|>
name|class
name|QList
expr_stmt|;
end_expr_stmt
begin_decl_stmt
DECL|variable|QNetworkCacheMetaDataPrivate
name|class
name|QNetworkCacheMetaDataPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_NETWORK_EXPORT
name|QNetworkCacheMetaData
block|{
name|public
label|:
typedef|typedef
name|QPair
operator|<
name|QByteArray
operator|,
name|QByteArray
operator|>
name|RawHeader
expr_stmt|;
typedef|typedef
name|QList
operator|<
name|RawHeader
operator|>
name|RawHeaderList
expr_stmt|;
typedef|typedef
name|QHash
operator|<
name|QNetworkRequest
operator|::
name|Attribute
operator|,
name|QVariant
operator|>
name|AttributesMap
expr_stmt|;
name|QNetworkCacheMetaData
argument_list|()
expr_stmt|;
name|QNetworkCacheMetaData
argument_list|(
specifier|const
name|QNetworkCacheMetaData
operator|&
name|other
argument_list|)
expr_stmt|;
operator|~
name|QNetworkCacheMetaData
argument_list|()
expr_stmt|;
name|QNetworkCacheMetaData
modifier|&
name|operator
init|=
operator|(
specifier|const
name|QNetworkCacheMetaData
operator|&
name|other
operator|)
decl_stmt|;
name|void
name|swap
parameter_list|(
name|QNetworkCacheMetaData
modifier|&
name|other
parameter_list|)
block|{
name|qSwap
argument_list|(
name|d
argument_list|,
name|other
operator|.
name|d
argument_list|)
expr_stmt|;
block|}
name|bool
name|operator
operator|==
operator|(
specifier|const
name|QNetworkCacheMetaData
operator|&
name|other
operator|)
specifier|const
expr_stmt|;
specifier|inline
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|QNetworkCacheMetaData
operator|&
name|other
operator|)
specifier|const
block|{
return|return
operator|!
operator|(
operator|*
name|this
operator|==
name|other
operator|)
return|;
block|}
name|bool
name|isValid
argument_list|()
specifier|const
expr_stmt|;
name|QUrl
name|url
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setUrl
parameter_list|(
specifier|const
name|QUrl
modifier|&
name|url
parameter_list|)
function_decl|;
name|RawHeaderList
name|rawHeaders
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setRawHeaders
parameter_list|(
specifier|const
name|RawHeaderList
modifier|&
name|headers
parameter_list|)
function_decl|;
name|QDateTime
name|lastModified
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setLastModified
parameter_list|(
specifier|const
name|QDateTime
modifier|&
name|dateTime
parameter_list|)
function_decl|;
name|QDateTime
name|expirationDate
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setExpirationDate
parameter_list|(
specifier|const
name|QDateTime
modifier|&
name|dateTime
parameter_list|)
function_decl|;
name|bool
name|saveToDisk
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setSaveToDisk
parameter_list|(
name|bool
name|allow
parameter_list|)
function_decl|;
name|AttributesMap
name|attributes
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setAttributes
parameter_list|(
specifier|const
name|AttributesMap
modifier|&
name|attributes
parameter_list|)
function_decl|;
name|private
label|:
name|friend
name|class
name|QNetworkCacheMetaDataPrivate
decl_stmt|;
name|QSharedDataPointer
operator|<
name|QNetworkCacheMetaDataPrivate
operator|>
name|d
expr_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_macro
name|Q_DECLARE_SHARED
argument_list|(
argument|QNetworkCacheMetaData
argument_list|)
end_macro
begin_expr_stmt
name|Q_NETWORK_EXPORT
name|QDataStream
operator|&
name|operator
operator|<<
operator|(
name|QDataStream
operator|&
operator|,
specifier|const
name|QNetworkCacheMetaData
operator|&
operator|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
DECL|variable|operator
name|Q_NETWORK_EXPORT
name|QDataStream
operator|&
name|operator
operator|>>
operator|(
name|QDataStream
operator|&
operator|,
name|QNetworkCacheMetaData
operator|&
operator|)
expr_stmt|;
end_expr_stmt
begin_decl_stmt
DECL|variable|QAbstractNetworkCachePrivate
name|class
name|QAbstractNetworkCachePrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_NETWORK_EXPORT
name|QAbstractNetworkCache
range|:
name|public
name|QObject
block|{
name|Q_OBJECT
name|public
operator|:
name|virtual
operator|~
name|QAbstractNetworkCache
argument_list|()
block|;
name|virtual
name|QNetworkCacheMetaData
name|metaData
argument_list|(
specifier|const
name|QUrl
operator|&
name|url
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|void
name|updateMetaData
argument_list|(
specifier|const
name|QNetworkCacheMetaData
operator|&
name|metaData
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|QIODevice
operator|*
name|data
argument_list|(
specifier|const
name|QUrl
operator|&
name|url
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|bool
name|remove
argument_list|(
specifier|const
name|QUrl
operator|&
name|url
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|qint64
name|cacheSize
argument_list|()
specifier|const
operator|=
literal|0
block|;
name|virtual
name|QIODevice
operator|*
name|prepare
argument_list|(
specifier|const
name|QNetworkCacheMetaData
operator|&
name|metaData
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|void
name|insert
argument_list|(
name|QIODevice
operator|*
name|device
argument_list|)
operator|=
literal|0
block|;
name|public
name|Q_SLOTS
operator|:
name|virtual
name|void
name|clear
argument_list|()
operator|=
literal|0
block|;
name|protected
operator|:
name|explicit
name|QAbstractNetworkCache
argument_list|(
name|QObject
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
name|QAbstractNetworkCache
argument_list|(
name|QAbstractNetworkCachePrivate
operator|&
name|dd
argument_list|,
name|QObject
operator|*
name|parent
argument_list|)
block|;
name|private
operator|:
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QAbstractNetworkCache
argument_list|)
name|Q_DISABLE_COPY
argument_list|(
argument|QAbstractNetworkCache
argument_list|)
block|}
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|QT_END_NAMESPACE
name|QT_END_HEADER
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
end_unit
