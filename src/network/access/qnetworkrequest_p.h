begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtNetwork module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** No Commercial Usage ** This file contains pre-release code and may not be distributed. ** You may use this file in accordance with the terms and conditions ** contained in the Technology Preview License Agreement accompanying ** this package. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights.  These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** If you have questions regarding the use of this file, please contact ** Nokia at qt-info@nokia.com. ** ** ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QNETWORKREQUEST_P_H
end_ifndef
begin_define
DECL|macro|QNETWORKREQUEST_P_H
define|#
directive|define
name|QNETWORKREQUEST_P_H
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
file|"QtCore/qbytearray.h"
end_include
begin_include
include|#
directive|include
file|"QtCore/qlist.h"
end_include
begin_include
include|#
directive|include
file|"QtCore/qhash.h"
end_include
begin_include
include|#
directive|include
file|"QtCore/qshareddata.h"
end_include
begin_include
include|#
directive|include
file|"QtCore/qsharedpointer.h"
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
comment|// this is the common part between QNetworkRequestPrivate, QNetworkReplyPrivate and QHttpPartPrivate
name|class
name|QNetworkHeadersPrivate
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
name|RawHeaderPair
expr_stmt|;
typedef|typedef
name|QList
operator|<
name|RawHeaderPair
operator|>
name|RawHeadersList
expr_stmt|;
typedef|typedef
name|QHash
operator|<
name|QNetworkRequest
operator|::
name|KnownHeaders
operator|,
name|QVariant
operator|>
name|CookedHeadersMap
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
name|RawHeadersList
name|rawHeaders
decl_stmt|;
name|CookedHeadersMap
name|cookedHeaders
decl_stmt|;
name|AttributesMap
name|attributes
decl_stmt|;
name|QWeakPointer
operator|<
name|QObject
operator|>
name|originatingObject
expr_stmt|;
name|RawHeadersList
operator|::
name|ConstIterator
name|findRawHeader
argument_list|(
argument|const QByteArray&key
argument_list|)
specifier|const
expr_stmt|;
name|RawHeadersList
name|allRawHeaders
argument_list|()
specifier|const
expr_stmt|;
name|QList
operator|<
name|QByteArray
operator|>
name|rawHeadersKeys
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setRawHeader
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|key
parameter_list|,
specifier|const
name|QByteArray
modifier|&
name|value
parameter_list|)
function_decl|;
name|void
name|setAllRawHeaders
parameter_list|(
specifier|const
name|RawHeadersList
modifier|&
name|list
parameter_list|)
function_decl|;
name|void
name|setCookedHeader
argument_list|(
name|QNetworkRequest
operator|::
name|KnownHeaders
name|header
argument_list|,
specifier|const
name|QVariant
operator|&
name|value
argument_list|)
decl_stmt|;
specifier|static
name|QDateTime
name|fromHttpDate
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|value
parameter_list|)
function_decl|;
specifier|static
name|QByteArray
name|toHttpDate
parameter_list|(
specifier|const
name|QDateTime
modifier|&
name|dt
parameter_list|)
function_decl|;
name|private
label|:
name|void
name|setRawHeaderInternal
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|key
parameter_list|,
specifier|const
name|QByteArray
modifier|&
name|value
parameter_list|)
function_decl|;
name|void
name|parseAndSetHeader
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|key
parameter_list|,
specifier|const
name|QByteArray
modifier|&
name|value
parameter_list|)
function_decl|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_expr_stmt
name|Q_DECLARE_TYPEINFO
argument_list|(
name|QNetworkHeadersPrivate
operator|::
name|RawHeaderPair
argument_list|,
name|Q_MOVABLE_TYPE
argument_list|)
expr_stmt|;
end_expr_stmt
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
end_unit
