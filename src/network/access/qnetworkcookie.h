begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2014 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtNetwork module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia. For licensing terms and ** conditions see http://qt.digia.com/licensing. For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights. These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QNETWORKCOOKIE_H
end_ifndef
begin_define
DECL|macro|QNETWORKCOOKIE_H
define|#
directive|define
name|QNETWORKCOOKIE_H
end_define
begin_include
include|#
directive|include
file|<QtCore/QSharedDataPointer>
end_include
begin_include
include|#
directive|include
file|<QtCore/QList>
end_include
begin_include
include|#
directive|include
file|<QtCore/QMetaType>
end_include
begin_include
include|#
directive|include
file|<QtCore/QObject>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QByteArray
name|class
name|QByteArray
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QDateTime
name|class
name|QDateTime
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QString
name|class
name|QString
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QUrl
name|class
name|QUrl
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QNetworkCookiePrivate
name|class
name|QNetworkCookiePrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_NETWORK_EXPORT
name|QNetworkCookie
block|{
name|public
label|:
enum|enum
name|RawForm
block|{
name|NameAndValueOnly
block|,
name|Full
block|}
enum|;
name|explicit
name|QNetworkCookie
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|name
init|=
name|QByteArray
argument_list|()
parameter_list|,
specifier|const
name|QByteArray
modifier|&
name|value
init|=
name|QByteArray
argument_list|()
parameter_list|)
function_decl|;
name|QNetworkCookie
argument_list|(
specifier|const
name|QNetworkCookie
operator|&
name|other
argument_list|)
expr_stmt|;
operator|~
name|QNetworkCookie
argument_list|()
expr_stmt|;
name|QNetworkCookie
modifier|&
name|operator
init|=
operator|(
specifier|const
name|QNetworkCookie
operator|&
name|other
operator|)
decl_stmt|;
name|void
name|swap
parameter_list|(
name|QNetworkCookie
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
name|QNetworkCookie
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
name|QNetworkCookie
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
name|isSecure
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setSecure
parameter_list|(
name|bool
name|enable
parameter_list|)
function_decl|;
name|bool
name|isHttpOnly
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setHttpOnly
parameter_list|(
name|bool
name|enable
parameter_list|)
function_decl|;
name|bool
name|isSessionCookie
argument_list|()
specifier|const
expr_stmt|;
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
name|date
parameter_list|)
function_decl|;
name|QString
name|domain
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setDomain
parameter_list|(
specifier|const
name|QString
modifier|&
name|domain
parameter_list|)
function_decl|;
name|QString
name|path
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setPath
parameter_list|(
specifier|const
name|QString
modifier|&
name|path
parameter_list|)
function_decl|;
name|QByteArray
name|name
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setName
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|cookieName
parameter_list|)
function_decl|;
name|QByteArray
name|value
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setValue
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|value
parameter_list|)
function_decl|;
name|QByteArray
name|toRawForm
argument_list|(
name|RawForm
name|form
operator|=
name|Full
argument_list|)
decl|const
decl_stmt|;
name|bool
name|hasSameIdentifier
argument_list|(
specifier|const
name|QNetworkCookie
operator|&
name|other
argument_list|)
decl|const
decl_stmt|;
name|void
name|normalize
parameter_list|(
specifier|const
name|QUrl
modifier|&
name|url
parameter_list|)
function_decl|;
specifier|static
name|QList
operator|<
name|QNetworkCookie
operator|>
name|parseCookies
argument_list|(
specifier|const
name|QByteArray
operator|&
name|cookieString
argument_list|)
expr_stmt|;
name|private
label|:
name|QSharedDataPointer
operator|<
name|QNetworkCookiePrivate
operator|>
name|d
expr_stmt|;
name|friend
name|class
name|QNetworkCookiePrivate
decl_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_macro
name|Q_DECLARE_SHARED
argument_list|(
argument|QNetworkCookie
argument_list|)
end_macro
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_DEBUG_STREAM
end_ifndef
begin_decl_stmt
name|class
name|QDebug
decl_stmt|;
end_decl_stmt
begin_expr_stmt
DECL|variable|operator
name|Q_NETWORK_EXPORT
name|QDebug
name|operator
operator|<<
operator|(
name|QDebug
operator|,
specifier|const
name|QNetworkCookie
operator|&
operator|)
expr_stmt|;
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_decl_stmt
name|QT_END_NAMESPACE
name|Q_DECLARE_METATYPE
argument_list|(
name|QNetworkCookie
argument_list|)
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
end_unit
