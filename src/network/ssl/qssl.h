begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the QtNetwork module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QSSL_H
end_ifndef
begin_define
DECL|macro|QSSL_H
define|#
directive|define
name|QSSL_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qglobal.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/QFlags>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
name|namespace
name|QSsl
block|{
enum|enum
name|KeyType
block|{
name|PrivateKey
block|,
name|PublicKey
block|}
enum|;
enum|enum
name|EncodingFormat
block|{
name|Pem
block|,
name|Der
block|}
enum|;
enum|enum
name|KeyAlgorithm
block|{
name|Opaque
block|,
name|Rsa
block|,
name|Dsa
block|,
name|Ec
block|}
enum|;
enum|enum
name|AlternativeNameEntryType
block|{
name|EmailEntry
block|,
name|DnsEntry
block|}
enum|;
if|#
directive|if
name|QT_DEPRECATED_SINCE
argument_list|(
literal|5
operator|,
literal|0
argument_list|)
typedef|typedef
name|AlternativeNameEntryType
name|AlternateNameEntryType
typedef|;
endif|#
directive|endif
enum|enum
name|SslProtocol
block|{
name|SslV3
block|,
name|SslV2
block|,
name|TlsV1_0
block|,
if|#
directive|if
name|QT_DEPRECATED_SINCE
argument_list|(
literal|5
operator|,
literal|0
argument_list|)
name|TlsV1
init|=
name|TlsV1_0
block|,
endif|#
directive|endif
name|TlsV1_1
block|,
name|TlsV1_2
block|,
name|AnyProtocol
block|,
name|TlsV1SslV3
block|,
name|SecureProtocols
block|,
name|TlsV1_0OrLater
block|,
name|TlsV1_1OrLater
block|,
name|TlsV1_2OrLater
block|,
name|UnknownProtocol
init|=
operator|-
literal|1
block|}
enum|;
enum|enum
name|SslOption
block|{
name|SslOptionDisableEmptyFragments
init|=
literal|0x01
block|,
name|SslOptionDisableSessionTickets
init|=
literal|0x02
block|,
name|SslOptionDisableCompression
init|=
literal|0x04
block|,
name|SslOptionDisableServerNameIndication
init|=
literal|0x08
block|,
name|SslOptionDisableLegacyRenegotiation
init|=
literal|0x10
block|,
name|SslOptionDisableSessionSharing
init|=
literal|0x20
block|,
name|SslOptionDisableSessionPersistence
init|=
literal|0x40
block|}
enum|;
name|Q_DECLARE_FLAGS
argument_list|(
argument|SslOptions
argument_list|,
argument|SslOption
argument_list|)
block|}
end_decl_stmt
begin_macro
name|Q_DECLARE_OPERATORS_FOR_FLAGS
argument_list|(
argument|QSsl::SslOptions
argument_list|)
end_macro
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QSSL_H
end_comment
end_unit
