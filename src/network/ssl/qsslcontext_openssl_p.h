begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2014 Digia Plc and/or its subsidiary(-ies). ** Copyright (C) 2014 BlackBerry Limited. All rights reserved. ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtNetwork module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia. For licensing terms and ** conditions see http://qt.digia.com/licensing. For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights. These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QSSLCONTEXT_OPENSSL_P_H
end_ifndef
begin_define
DECL|macro|QSSLCONTEXT_OPENSSL_P_H
define|#
directive|define
name|QSSLCONTEXT_OPENSSL_P_H
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
comment|// This file is not part of the Qt API.  It exists purely as an
end_comment
begin_comment
comment|// implementation detail.  This header file may change from version to
end_comment
begin_comment
comment|// version without notice, or even be removed.
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
file|<QtCore/qvariant.h>
end_include
begin_include
include|#
directive|include
file|<QtNetwork/qsslcertificate.h>
end_include
begin_include
include|#
directive|include
file|<QtNetwork/qsslconfiguration.h>
end_include
begin_include
include|#
directive|include
file|<openssl/ssl.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
ifndef|#
directive|ifndef
name|QT_NO_SSL
DECL|variable|QSslContextPrivate
name|class
name|QSslContextPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QSslContext
block|{
name|public
label|:
operator|~
name|QSslContext
argument_list|()
expr_stmt|;
specifier|static
name|QSslContext
modifier|*
name|fromConfiguration
argument_list|(
name|QSslSocket
operator|::
name|SslMode
name|mode
argument_list|,
specifier|const
name|QSslConfiguration
operator|&
name|configuration
argument_list|,
name|bool
name|allowRootCertOnDemandLoading
argument_list|)
decl_stmt|;
name|QSslError
operator|::
name|SslError
name|error
argument_list|()
specifier|const
expr_stmt|;
name|QString
name|errorString
argument_list|()
specifier|const
expr_stmt|;
name|SSL
modifier|*
name|createSsl
parameter_list|()
function_decl|;
name|bool
name|cacheSession
parameter_list|(
name|SSL
modifier|*
parameter_list|)
function_decl|;
comment|// should be called when handshake completed
name|QByteArray
name|sessionASN1
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setSessionASN1
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|sessionASN1
parameter_list|)
function_decl|;
name|int
name|sessionTicketLifeTimeHint
argument_list|()
specifier|const
decl_stmt|;
if|#
directive|if
name|OPENSSL_VERSION_NUMBER
operator|>=
literal|0x1000100fL
operator|&&
operator|!
name|defined
argument_list|(
name|OPENSSL_NO_NEXTPROTONEG
argument_list|)
comment|// must be public because we want to use it from an OpenSSL callback
struct|struct
name|NPNContext
block|{
name|NPNContext
argument_list|()
operator|:
name|data
argument_list|(
literal|0
argument_list|)
operator|,
name|len
argument_list|(
literal|0
argument_list|)
operator|,
name|status
argument_list|(
argument|QSslConfiguration::NextProtocolNegotiationNone
argument_list|)
block|{ }
name|unsigned
name|char
operator|*
name|data
expr_stmt|;
name|unsigned
name|short
name|len
decl_stmt|;
name|QSslConfiguration
operator|::
name|NextProtocolNegotiationStatus
name|status
expr_stmt|;
block|}
struct|;
name|NPNContext
name|npnContext
argument_list|()
specifier|const
expr_stmt|;
endif|#
directive|endif
comment|// OPENSSL_VERSION_NUMBER>= 0x1000100fL ...
name|protected
label|:
name|QSslContext
argument_list|()
expr_stmt|;
name|private
label|:
name|SSL_CTX
modifier|*
name|ctx
decl_stmt|;
name|EVP_PKEY
modifier|*
name|pkey
decl_stmt|;
name|SSL_SESSION
modifier|*
name|session
decl_stmt|;
name|QByteArray
name|m_sessionASN1
decl_stmt|;
name|int
name|m_sessionTicketLifeTimeHint
decl_stmt|;
name|QSslError
operator|::
name|SslError
name|errorCode
expr_stmt|;
name|QString
name|errorStr
decl_stmt|;
name|QSslConfiguration
name|sslConfiguration
decl_stmt|;
if|#
directive|if
name|OPENSSL_VERSION_NUMBER
operator|>=
literal|0x1000100fL
operator|&&
operator|!
name|defined
argument_list|(
name|OPENSSL_NO_NEXTPROTONEG
argument_list|)
name|QByteArray
name|m_supportedNPNVersions
decl_stmt|;
name|NPNContext
name|m_npnContext
decl_stmt|;
endif|#
directive|endif
comment|// OPENSSL_VERSION_NUMBER>= 0x1000100fL ...
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_SSL
end_comment
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QSSLCONTEXT_OPENSSL_P_H
end_comment
end_unit
