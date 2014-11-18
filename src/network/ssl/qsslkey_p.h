begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2014 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtNetwork module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia. For licensing terms and ** conditions see http://qt.digia.com/licensing. For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights. These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QSSLKEY_OPENSSL_P_H
end_ifndef
begin_define
DECL|macro|QSSLKEY_OPENSSL_P_H
define|#
directive|define
name|QSSLKEY_OPENSSL_P_H
end_define
begin_include
include|#
directive|include
file|"qsslkey.h"
end_include
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
comment|// of qsslcertificate.cpp.  This header file may change from version to version
end_comment
begin_comment
comment|// without notice, or even be removed.
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
file|"qsslsocket_p.h"
end_include
begin_comment
comment|// includes wincrypt.h
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_OPENSSL
end_ifndef
begin_include
include|#
directive|include
file|<openssl/rsa.h>
end_include
begin_include
include|#
directive|include
file|<openssl/dsa.h>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
name|class
name|QSslKeyPrivate
block|{
name|public
label|:
specifier|inline
name|QSslKeyPrivate
argument_list|()
operator|:
name|opaque
argument_list|(
literal|0
argument_list|)
ifndef|#
directive|ifndef
name|QT_NO_OPENSSL
operator|,
name|rsa
argument_list|(
literal|0
argument_list|)
operator|,
name|dsa
argument_list|(
literal|0
argument_list|)
ifndef|#
directive|ifndef
name|OPENSSL_NO_EC
operator|,
name|ec
argument_list|(
literal|0
argument_list|)
endif|#
directive|endif
endif|#
directive|endif
block|{
name|clear
argument_list|()
block|;     }
specifier|inline
operator|~
name|QSslKeyPrivate
argument_list|()
block|{
name|clear
argument_list|()
block|; }
name|void
name|clear
argument_list|(
argument|bool deep = true
argument_list|)
expr_stmt|;
ifndef|#
directive|ifndef
name|QT_NO_OPENSSL
name|bool
name|fromEVP_PKEY
parameter_list|(
name|EVP_PKEY
modifier|*
name|pkey
parameter_list|)
function_decl|;
endif|#
directive|endif
name|void
name|decodeDer
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|der
parameter_list|,
name|bool
name|deepClear
init|=
name|true
parameter_list|)
function_decl|;
name|void
name|decodePem
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|pem
parameter_list|,
specifier|const
name|QByteArray
modifier|&
name|passPhrase
parameter_list|,
name|bool
name|deepClear
init|=
name|true
parameter_list|)
function_decl|;
name|QByteArray
name|pemHeader
argument_list|()
specifier|const
expr_stmt|;
name|QByteArray
name|pemFooter
argument_list|()
specifier|const
expr_stmt|;
name|QByteArray
name|pemFromDer
argument_list|(
specifier|const
name|QByteArray
operator|&
name|der
argument_list|,
specifier|const
name|QMap
operator|<
name|QByteArray
argument_list|,
name|QByteArray
operator|>
operator|&
name|headers
argument_list|)
decl|const
decl_stmt|;
name|QByteArray
name|derFromPem
argument_list|(
specifier|const
name|QByteArray
operator|&
name|pem
argument_list|,
name|QMap
operator|<
name|QByteArray
argument_list|,
name|QByteArray
operator|>
operator|*
name|headers
argument_list|)
decl|const
decl_stmt|;
name|int
name|length
argument_list|()
specifier|const
expr_stmt|;
name|QByteArray
name|toPem
argument_list|(
specifier|const
name|QByteArray
operator|&
name|passPhrase
argument_list|)
decl|const
decl_stmt|;
name|Qt
operator|::
name|HANDLE
name|handle
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|isNull
decl_stmt|;
name|QSsl
operator|::
name|KeyType
name|type
expr_stmt|;
name|QSsl
operator|::
name|KeyAlgorithm
name|algorithm
expr_stmt|;
ifndef|#
directive|ifndef
name|QT_NO_OPENSSL
name|EVP_PKEY
modifier|*
name|opaque
decl_stmt|;
name|RSA
modifier|*
name|rsa
decl_stmt|;
name|DSA
modifier|*
name|dsa
decl_stmt|;
ifndef|#
directive|ifndef
name|OPENSSL_NO_EC
name|EC_KEY
modifier|*
name|ec
decl_stmt|;
endif|#
directive|endif
else|#
directive|else
enum|enum
name|Cipher
block|{
name|DesCbc
block|,
name|DesEde3Cbc
block|,
name|Rc2Cbc
block|}
enum|;
name|Q_AUTOTEST_EXPORT
specifier|static
name|QByteArray
name|decrypt
parameter_list|(
name|Cipher
name|cipher
parameter_list|,
specifier|const
name|QByteArray
modifier|&
name|data
parameter_list|,
specifier|const
name|QByteArray
modifier|&
name|key
parameter_list|,
specifier|const
name|QByteArray
modifier|&
name|iv
parameter_list|)
function_decl|;
name|Q_AUTOTEST_EXPORT
specifier|static
name|QByteArray
name|encrypt
parameter_list|(
name|Cipher
name|cipher
parameter_list|,
specifier|const
name|QByteArray
modifier|&
name|data
parameter_list|,
specifier|const
name|QByteArray
modifier|&
name|key
parameter_list|,
specifier|const
name|QByteArray
modifier|&
name|iv
parameter_list|)
function_decl|;
name|Qt
operator|::
name|HANDLE
name|opaque
expr_stmt|;
name|QByteArray
name|derData
decl_stmt|;
name|int
name|keyLength
decl_stmt|;
endif|#
directive|endif
name|QAtomicInt
name|ref
decl_stmt|;
name|private
label|:
name|Q_DISABLE_COPY
argument_list|(
argument|QSslKeyPrivate
argument_list|)
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QSSLKEY_OPENSSL_P_H
end_comment
end_unit
