begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the QtNetwork module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qsslcertificate.h"
end_include
begin_include
include|#
directive|include
file|"qsslcertificate_p.h"
end_include
begin_include
include|#
directive|include
file|"qssl_p.h"
end_include
begin_include
include|#
directive|include
file|"qsslkey.h"
end_include
begin_include
include|#
directive|include
file|"qsslkey_p.h"
end_include
begin_include
include|#
directive|include
file|"qsslcertificateextension.h"
end_include
begin_include
include|#
directive|include
file|"qsslcertificateextension_p.h"
end_include
begin_include
include|#
directive|include
file|"qasn1element_p.h"
end_include
begin_include
include|#
directive|include
file|<QtCore/qdatastream.h>
end_include
begin_function
name|QT_BEGIN_NAMESPACE
DECL|function|operator ==
name|bool
name|QSslCertificate
operator|::
name|operator
name|==
parameter_list|(
specifier|const
name|QSslCertificate
modifier|&
name|other
parameter_list|)
specifier|const
block|{
if|if
condition|(
name|d
operator|==
name|other
operator|.
name|d
condition|)
return|return
literal|true
return|;
if|if
condition|(
name|d
operator|->
name|null
operator|&&
name|other
operator|.
name|d
operator|->
name|null
condition|)
return|return
literal|true
return|;
return|return
name|d
operator|->
name|derData
operator|==
name|other
operator|.
name|d
operator|->
name|derData
return|;
block|}
end_function
begin_function
name|uint
name|qHash
parameter_list|(
specifier|const
name|QSslCertificate
modifier|&
name|key
parameter_list|,
name|uint
name|seed
parameter_list|)
name|Q_DECL_NOTHROW
block|{
comment|// DER is the native encoding here, so toDer() is just "return d->derData":
return|return
name|qHash
argument_list|(
name|key
operator|.
name|toDer
argument_list|()
argument_list|,
name|seed
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|isNull
name|bool
name|QSslCertificate
operator|::
name|isNull
parameter_list|()
specifier|const
block|{
return|return
name|d
operator|->
name|null
return|;
block|}
end_function
begin_function
DECL|function|isSelfSigned
name|bool
name|QSslCertificate
operator|::
name|isSelfSigned
parameter_list|()
specifier|const
block|{
if|if
condition|(
name|d
operator|->
name|null
condition|)
return|return
literal|false
return|;
name|qCWarning
argument_list|(
name|lcSsl
argument_list|,
literal|"QSslCertificate::isSelfSigned: This function does not check, whether the certificate "
literal|"is actually signed. It just checks whether issuer and subject are identical"
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|subjectMatchesIssuer
return|;
block|}
end_function
begin_function
DECL|function|version
name|QByteArray
name|QSslCertificate
operator|::
name|version
parameter_list|()
specifier|const
block|{
return|return
name|d
operator|->
name|versionString
return|;
block|}
end_function
begin_function
DECL|function|serialNumber
name|QByteArray
name|QSslCertificate
operator|::
name|serialNumber
parameter_list|()
specifier|const
block|{
return|return
name|d
operator|->
name|serialNumberString
return|;
block|}
end_function
begin_function
DECL|function|issuerInfo
name|QStringList
name|QSslCertificate
operator|::
name|issuerInfo
parameter_list|(
name|SubjectInfo
name|info
parameter_list|)
specifier|const
block|{
return|return
name|issuerInfo
argument_list|(
name|QSslCertificatePrivate
operator|::
name|subjectInfoToString
argument_list|(
name|info
argument_list|)
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|issuerInfo
name|QStringList
name|QSslCertificate
operator|::
name|issuerInfo
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|attribute
parameter_list|)
specifier|const
block|{
return|return
name|d
operator|->
name|issuerInfo
operator|.
name|values
argument_list|(
name|attribute
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|subjectInfo
name|QStringList
name|QSslCertificate
operator|::
name|subjectInfo
parameter_list|(
name|SubjectInfo
name|info
parameter_list|)
specifier|const
block|{
return|return
name|subjectInfo
argument_list|(
name|QSslCertificatePrivate
operator|::
name|subjectInfoToString
argument_list|(
name|info
argument_list|)
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|subjectInfo
name|QStringList
name|QSslCertificate
operator|::
name|subjectInfo
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|attribute
parameter_list|)
specifier|const
block|{
return|return
name|d
operator|->
name|subjectInfo
operator|.
name|values
argument_list|(
name|attribute
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|subjectInfoAttributes
name|QList
argument_list|<
name|QByteArray
argument_list|>
name|QSslCertificate
operator|::
name|subjectInfoAttributes
parameter_list|()
specifier|const
block|{
return|return
name|d
operator|->
name|subjectInfo
operator|.
name|uniqueKeys
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|issuerInfoAttributes
name|QList
argument_list|<
name|QByteArray
argument_list|>
name|QSslCertificate
operator|::
name|issuerInfoAttributes
parameter_list|()
specifier|const
block|{
return|return
name|d
operator|->
name|issuerInfo
operator|.
name|uniqueKeys
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|subjectAlternativeNames
name|QMultiMap
argument_list|<
name|QSsl
operator|::
name|AlternativeNameEntryType
argument_list|,
name|QString
argument_list|>
name|QSslCertificate
operator|::
name|subjectAlternativeNames
parameter_list|()
specifier|const
block|{
return|return
name|d
operator|->
name|subjectAlternativeNames
return|;
block|}
end_function
begin_function
DECL|function|effectiveDate
name|QDateTime
name|QSslCertificate
operator|::
name|effectiveDate
parameter_list|()
specifier|const
block|{
return|return
name|d
operator|->
name|notValidBefore
return|;
block|}
end_function
begin_function
DECL|function|expiryDate
name|QDateTime
name|QSslCertificate
operator|::
name|expiryDate
parameter_list|()
specifier|const
block|{
return|return
name|d
operator|->
name|notValidAfter
return|;
block|}
end_function
begin_ifndef
ifndef|#
directive|ifndef
name|Q_OS_WINRT
end_ifndef
begin_comment
comment|// implemented in qsslcertificate_winrt.cpp
end_comment
begin_function
DECL|function|handle
name|Qt
operator|::
name|HANDLE
name|QSslCertificate
operator|::
name|handle
parameter_list|()
specifier|const
block|{
name|Q_UNIMPLEMENTED
argument_list|()
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_function
DECL|function|publicKey
name|QSslKey
name|QSslCertificate
operator|::
name|publicKey
parameter_list|()
specifier|const
block|{
name|QSslKey
name|key
decl_stmt|;
name|key
operator|.
name|d
operator|->
name|type
operator|=
name|QSsl
operator|::
name|PublicKey
expr_stmt|;
if|if
condition|(
name|d
operator|->
name|publicKeyAlgorithm
operator|!=
name|QSsl
operator|::
name|Opaque
condition|)
block|{
name|key
operator|.
name|d
operator|->
name|algorithm
operator|=
name|d
operator|->
name|publicKeyAlgorithm
expr_stmt|;
name|key
operator|.
name|d
operator|->
name|decodeDer
argument_list|(
name|d
operator|->
name|publicKeyDerData
argument_list|)
expr_stmt|;
block|}
return|return
name|key
return|;
block|}
end_function
begin_function
DECL|function|extensions
name|QList
argument_list|<
name|QSslCertificateExtension
argument_list|>
name|QSslCertificate
operator|::
name|extensions
parameter_list|()
specifier|const
block|{
return|return
name|d
operator|->
name|extensions
return|;
block|}
end_function
begin_define
DECL|macro|BEGINCERTSTRING
define|#
directive|define
name|BEGINCERTSTRING
value|"-----BEGIN CERTIFICATE-----"
end_define
begin_define
DECL|macro|ENDCERTSTRING
define|#
directive|define
name|ENDCERTSTRING
value|"-----END CERTIFICATE-----"
end_define
begin_function
DECL|function|toPem
name|QByteArray
name|QSslCertificate
operator|::
name|toPem
parameter_list|()
specifier|const
block|{
name|QByteArray
name|array
init|=
name|toDer
argument_list|()
decl_stmt|;
comment|// Convert to Base64 - wrap at 64 characters.
name|array
operator|=
name|array
operator|.
name|toBase64
argument_list|()
expr_stmt|;
name|QByteArray
name|tmp
decl_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<=
name|array
operator|.
name|size
argument_list|()
operator|-
literal|64
condition|;
name|i
operator|+=
literal|64
control|)
block|{
name|tmp
operator|+=
name|QByteArray
operator|::
name|fromRawData
argument_list|(
name|array
operator|.
name|data
argument_list|()
operator|+
name|i
argument_list|,
literal|64
argument_list|)
expr_stmt|;
name|tmp
operator|+=
literal|'\n'
expr_stmt|;
block|}
if|if
condition|(
name|int
name|remainder
init|=
name|array
operator|.
name|size
argument_list|()
operator|%
literal|64
condition|)
block|{
name|tmp
operator|+=
name|QByteArray
operator|::
name|fromRawData
argument_list|(
name|array
operator|.
name|data
argument_list|()
operator|+
name|array
operator|.
name|size
argument_list|()
operator|-
name|remainder
argument_list|,
name|remainder
argument_list|)
expr_stmt|;
name|tmp
operator|+=
literal|'\n'
expr_stmt|;
block|}
return|return
name|BEGINCERTSTRING
literal|"\n"
operator|+
name|tmp
operator|+
name|ENDCERTSTRING
literal|"\n"
return|;
block|}
end_function
begin_function
DECL|function|toDer
name|QByteArray
name|QSslCertificate
operator|::
name|toDer
parameter_list|()
specifier|const
block|{
return|return
name|d
operator|->
name|derData
return|;
block|}
end_function
begin_function
DECL|function|toText
name|QString
name|QSslCertificate
operator|::
name|toText
parameter_list|()
specifier|const
block|{
name|Q_UNIMPLEMENTED
argument_list|()
expr_stmt|;
return|return
name|QString
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|init
name|void
name|QSslCertificatePrivate
operator|::
name|init
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|data
parameter_list|,
name|QSsl
operator|::
name|EncodingFormat
name|format
parameter_list|)
block|{
if|if
condition|(
operator|!
name|data
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
specifier|const
name|QList
argument_list|<
name|QSslCertificate
argument_list|>
name|certs
init|=
operator|(
name|format
operator|==
name|QSsl
operator|::
name|Pem
operator|)
condition|?
name|certificatesFromPem
argument_list|(
name|data
argument_list|,
literal|1
argument_list|)
else|:
name|certificatesFromDer
argument_list|(
name|data
argument_list|,
literal|1
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|certs
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
operator|*
name|this
operator|=
operator|*
name|certs
operator|.
name|first
argument_list|()
operator|.
name|d
expr_stmt|;
block|}
block|}
block|}
end_function
begin_function
DECL|function|matchLineFeed
specifier|static
name|bool
name|matchLineFeed
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|pem
parameter_list|,
name|int
modifier|*
name|offset
parameter_list|)
block|{
name|char
name|ch
init|=
literal|0
decl_stmt|;
comment|// ignore extra whitespace at the end of the line
while|while
condition|(
operator|*
name|offset
operator|<
name|pem
operator|.
name|size
argument_list|()
operator|&&
operator|(
name|ch
operator|=
name|pem
operator|.
name|at
argument_list|(
operator|*
name|offset
argument_list|)
operator|)
operator|==
literal|' '
condition|)
operator|++
operator|*
name|offset
expr_stmt|;
if|if
condition|(
name|ch
operator|==
literal|'\n'
condition|)
block|{
operator|*
name|offset
operator|+=
literal|1
expr_stmt|;
return|return
literal|true
return|;
block|}
if|if
condition|(
name|ch
operator|==
literal|'\r'
operator|&&
name|pem
operator|.
name|size
argument_list|()
operator|>
operator|(
operator|*
name|offset
operator|+
literal|1
operator|)
operator|&&
name|pem
operator|.
name|at
argument_list|(
operator|*
name|offset
operator|+
literal|1
argument_list|)
operator|==
literal|'\n'
condition|)
block|{
operator|*
name|offset
operator|+=
literal|2
expr_stmt|;
return|return
literal|true
return|;
block|}
return|return
literal|false
return|;
block|}
end_function
begin_function
DECL|function|certificatesFromPem
name|QList
argument_list|<
name|QSslCertificate
argument_list|>
name|QSslCertificatePrivate
operator|::
name|certificatesFromPem
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|pem
parameter_list|,
name|int
name|count
parameter_list|)
block|{
name|QList
argument_list|<
name|QSslCertificate
argument_list|>
name|certificates
decl_stmt|;
name|int
name|offset
init|=
literal|0
decl_stmt|;
while|while
condition|(
name|count
operator|==
operator|-
literal|1
operator|||
name|certificates
operator|.
name|size
argument_list|()
operator|<
name|count
condition|)
block|{
name|int
name|startPos
init|=
name|pem
operator|.
name|indexOf
argument_list|(
name|BEGINCERTSTRING
argument_list|,
name|offset
argument_list|)
decl_stmt|;
if|if
condition|(
name|startPos
operator|==
operator|-
literal|1
condition|)
break|break;
name|startPos
operator|+=
sizeof|sizeof
argument_list|(
name|BEGINCERTSTRING
argument_list|)
operator|-
literal|1
expr_stmt|;
if|if
condition|(
operator|!
name|matchLineFeed
argument_list|(
name|pem
argument_list|,
operator|&
name|startPos
argument_list|)
condition|)
break|break;
name|int
name|endPos
init|=
name|pem
operator|.
name|indexOf
argument_list|(
name|ENDCERTSTRING
argument_list|,
name|startPos
argument_list|)
decl_stmt|;
if|if
condition|(
name|endPos
operator|==
operator|-
literal|1
condition|)
break|break;
name|offset
operator|=
name|endPos
operator|+
sizeof|sizeof
argument_list|(
name|ENDCERTSTRING
argument_list|)
operator|-
literal|1
expr_stmt|;
if|if
condition|(
name|offset
operator|<
name|pem
operator|.
name|size
argument_list|()
operator|&&
operator|!
name|matchLineFeed
argument_list|(
name|pem
argument_list|,
operator|&
name|offset
argument_list|)
condition|)
break|break;
name|QByteArray
name|decoded
init|=
name|QByteArray
operator|::
name|fromBase64
argument_list|(
name|QByteArray
operator|::
name|fromRawData
argument_list|(
name|pem
operator|.
name|data
argument_list|()
operator|+
name|startPos
argument_list|,
name|endPos
operator|-
name|startPos
argument_list|)
argument_list|)
decl_stmt|;
name|certificates
operator|<<
name|certificatesFromDer
argument_list|(
name|decoded
argument_list|,
literal|1
argument_list|)
expr_stmt|;
empty_stmt|;
block|}
return|return
name|certificates
return|;
block|}
end_function
begin_function
DECL|function|certificatesFromDer
name|QList
argument_list|<
name|QSslCertificate
argument_list|>
name|QSslCertificatePrivate
operator|::
name|certificatesFromDer
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|der
parameter_list|,
name|int
name|count
parameter_list|)
block|{
name|QList
argument_list|<
name|QSslCertificate
argument_list|>
name|certificates
decl_stmt|;
name|QByteArray
name|data
init|=
name|der
decl_stmt|;
while|while
condition|(
name|count
operator|==
operator|-
literal|1
operator|||
name|certificates
operator|.
name|size
argument_list|()
operator|<
name|count
condition|)
block|{
name|QSslCertificate
name|cert
decl_stmt|;
if|if
condition|(
operator|!
name|cert
operator|.
name|d
operator|->
name|parse
argument_list|(
name|data
argument_list|)
condition|)
break|break;
name|certificates
operator|<<
name|cert
expr_stmt|;
name|data
operator|.
name|remove
argument_list|(
literal|0
argument_list|,
name|cert
operator|.
name|d
operator|->
name|derData
operator|.
name|size
argument_list|()
argument_list|)
expr_stmt|;
block|}
return|return
name|certificates
return|;
block|}
end_function
begin_function
DECL|function|colonSeparatedHex
specifier|static
name|QByteArray
name|colonSeparatedHex
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|value
parameter_list|)
block|{
name|QByteArray
name|hexString
decl_stmt|;
name|hexString
operator|.
name|reserve
argument_list|(
name|value
operator|.
name|size
argument_list|()
operator|*
literal|3
argument_list|)
expr_stmt|;
for|for
control|(
name|int
name|a
init|=
literal|0
init|;
name|a
operator|<
name|value
operator|.
name|size
argument_list|()
condition|;
operator|++
name|a
control|)
block|{
specifier|const
name|quint8
name|b
init|=
name|value
operator|.
name|at
argument_list|(
name|a
argument_list|)
decl_stmt|;
if|if
condition|(
name|b
operator|||
operator|!
name|hexString
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
comment|// skip leading zeros
name|hexString
operator|+=
name|QByteArray
operator|::
name|number
argument_list|(
name|b
argument_list|,
literal|16
argument_list|)
operator|.
name|rightJustified
argument_list|(
literal|2
argument_list|,
literal|'0'
argument_list|)
expr_stmt|;
name|hexString
operator|+=
literal|':'
expr_stmt|;
block|}
block|}
name|hexString
operator|.
name|chop
argument_list|(
literal|1
argument_list|)
expr_stmt|;
return|return
name|hexString
return|;
block|}
end_function
begin_function
DECL|function|parse
name|bool
name|QSslCertificatePrivate
operator|::
name|parse
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|data
parameter_list|)
block|{
name|QAsn1Element
name|root
decl_stmt|;
name|QDataStream
name|dataStream
argument_list|(
name|data
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|root
operator|.
name|read
argument_list|(
name|dataStream
argument_list|)
operator|||
name|root
operator|.
name|type
argument_list|()
operator|!=
name|QAsn1Element
operator|::
name|SequenceType
condition|)
return|return
literal|false
return|;
name|QDataStream
name|rootStream
argument_list|(
name|root
operator|.
name|value
argument_list|()
argument_list|)
decl_stmt|;
name|QAsn1Element
name|cert
decl_stmt|;
if|if
condition|(
operator|!
name|cert
operator|.
name|read
argument_list|(
name|rootStream
argument_list|)
operator|||
name|cert
operator|.
name|type
argument_list|()
operator|!=
name|QAsn1Element
operator|::
name|SequenceType
condition|)
return|return
literal|false
return|;
comment|// version or serial number
name|QAsn1Element
name|elem
decl_stmt|;
name|QDataStream
name|certStream
argument_list|(
name|cert
operator|.
name|value
argument_list|()
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|elem
operator|.
name|read
argument_list|(
name|certStream
argument_list|)
condition|)
return|return
literal|false
return|;
if|if
condition|(
name|elem
operator|.
name|type
argument_list|()
operator|==
name|QAsn1Element
operator|::
name|Context0Type
condition|)
block|{
name|QDataStream
name|versionStream
argument_list|(
name|elem
operator|.
name|value
argument_list|()
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|elem
operator|.
name|read
argument_list|(
name|versionStream
argument_list|)
operator|||
name|elem
operator|.
name|type
argument_list|()
operator|!=
name|QAsn1Element
operator|::
name|IntegerType
condition|)
return|return
literal|false
return|;
name|versionString
operator|=
name|QByteArray
operator|::
name|number
argument_list|(
name|elem
operator|.
name|value
argument_list|()
operator|.
name|at
argument_list|(
literal|0
argument_list|)
operator|+
literal|1
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|elem
operator|.
name|read
argument_list|(
name|certStream
argument_list|)
condition|)
return|return
literal|false
return|;
block|}
else|else
block|{
name|versionString
operator|=
name|QByteArray
operator|::
name|number
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
comment|// serial number
if|if
condition|(
name|elem
operator|.
name|type
argument_list|()
operator|!=
name|QAsn1Element
operator|::
name|IntegerType
condition|)
return|return
literal|false
return|;
name|serialNumberString
operator|=
name|colonSeparatedHex
argument_list|(
name|elem
operator|.
name|value
argument_list|()
argument_list|)
expr_stmt|;
comment|// algorithm ID
if|if
condition|(
operator|!
name|elem
operator|.
name|read
argument_list|(
name|certStream
argument_list|)
operator|||
name|elem
operator|.
name|type
argument_list|()
operator|!=
name|QAsn1Element
operator|::
name|SequenceType
condition|)
return|return
literal|false
return|;
comment|// issuer info
if|if
condition|(
operator|!
name|elem
operator|.
name|read
argument_list|(
name|certStream
argument_list|)
operator|||
name|elem
operator|.
name|type
argument_list|()
operator|!=
name|QAsn1Element
operator|::
name|SequenceType
condition|)
return|return
literal|false
return|;
name|QByteArray
name|issuerDer
init|=
name|data
operator|.
name|mid
argument_list|(
name|dataStream
operator|.
name|device
argument_list|()
operator|->
name|pos
argument_list|()
operator|-
name|elem
operator|.
name|value
argument_list|()
operator|.
name|length
argument_list|()
argument_list|,
name|elem
operator|.
name|value
argument_list|()
operator|.
name|length
argument_list|()
argument_list|)
decl_stmt|;
name|issuerInfo
operator|=
name|elem
operator|.
name|toInfo
argument_list|()
expr_stmt|;
comment|// validity period
if|if
condition|(
operator|!
name|elem
operator|.
name|read
argument_list|(
name|certStream
argument_list|)
operator|||
name|elem
operator|.
name|type
argument_list|()
operator|!=
name|QAsn1Element
operator|::
name|SequenceType
condition|)
return|return
literal|false
return|;
name|QDataStream
name|validityStream
argument_list|(
name|elem
operator|.
name|value
argument_list|()
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|elem
operator|.
name|read
argument_list|(
name|validityStream
argument_list|)
operator|||
operator|(
name|elem
operator|.
name|type
argument_list|()
operator|!=
name|QAsn1Element
operator|::
name|UtcTimeType
operator|&&
name|elem
operator|.
name|type
argument_list|()
operator|!=
name|QAsn1Element
operator|::
name|GeneralizedTimeType
operator|)
condition|)
return|return
literal|false
return|;
name|notValidBefore
operator|=
name|elem
operator|.
name|toDateTime
argument_list|()
expr_stmt|;
if|if
condition|(
operator|!
name|elem
operator|.
name|read
argument_list|(
name|validityStream
argument_list|)
operator|||
operator|(
name|elem
operator|.
name|type
argument_list|()
operator|!=
name|QAsn1Element
operator|::
name|UtcTimeType
operator|&&
name|elem
operator|.
name|type
argument_list|()
operator|!=
name|QAsn1Element
operator|::
name|GeneralizedTimeType
operator|)
condition|)
return|return
literal|false
return|;
name|notValidAfter
operator|=
name|elem
operator|.
name|toDateTime
argument_list|()
expr_stmt|;
comment|// subject name
if|if
condition|(
operator|!
name|elem
operator|.
name|read
argument_list|(
name|certStream
argument_list|)
operator|||
name|elem
operator|.
name|type
argument_list|()
operator|!=
name|QAsn1Element
operator|::
name|SequenceType
condition|)
return|return
literal|false
return|;
name|QByteArray
name|subjectDer
init|=
name|data
operator|.
name|mid
argument_list|(
name|dataStream
operator|.
name|device
argument_list|()
operator|->
name|pos
argument_list|()
operator|-
name|elem
operator|.
name|value
argument_list|()
operator|.
name|length
argument_list|()
argument_list|,
name|elem
operator|.
name|value
argument_list|()
operator|.
name|length
argument_list|()
argument_list|)
decl_stmt|;
name|subjectInfo
operator|=
name|elem
operator|.
name|toInfo
argument_list|()
expr_stmt|;
name|subjectMatchesIssuer
operator|=
name|issuerDer
operator|==
name|subjectDer
expr_stmt|;
comment|// public key
name|qint64
name|keyStart
init|=
name|certStream
operator|.
name|device
argument_list|()
operator|->
name|pos
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
name|elem
operator|.
name|read
argument_list|(
name|certStream
argument_list|)
operator|||
name|elem
operator|.
name|type
argument_list|()
operator|!=
name|QAsn1Element
operator|::
name|SequenceType
condition|)
return|return
literal|false
return|;
name|publicKeyDerData
operator|.
name|resize
argument_list|(
name|certStream
operator|.
name|device
argument_list|()
operator|->
name|pos
argument_list|()
operator|-
name|keyStart
argument_list|)
expr_stmt|;
name|QDataStream
name|keyStream
argument_list|(
name|elem
operator|.
name|value
argument_list|()
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|elem
operator|.
name|read
argument_list|(
name|keyStream
argument_list|)
operator|||
name|elem
operator|.
name|type
argument_list|()
operator|!=
name|QAsn1Element
operator|::
name|SequenceType
condition|)
return|return
literal|false
return|;
comment|// key algorithm
if|if
condition|(
operator|!
name|elem
operator|.
name|read
argument_list|(
name|elem
operator|.
name|value
argument_list|()
argument_list|)
operator|||
name|elem
operator|.
name|type
argument_list|()
operator|!=
name|QAsn1Element
operator|::
name|ObjectIdentifierType
condition|)
return|return
literal|false
return|;
specifier|const
name|QByteArray
name|oid
init|=
name|elem
operator|.
name|toObjectId
argument_list|()
decl_stmt|;
if|if
condition|(
name|oid
operator|==
name|RSA_ENCRYPTION_OID
condition|)
name|publicKeyAlgorithm
operator|=
name|QSsl
operator|::
name|Rsa
expr_stmt|;
elseif|else
if|if
condition|(
name|oid
operator|==
name|DSA_ENCRYPTION_OID
condition|)
name|publicKeyAlgorithm
operator|=
name|QSsl
operator|::
name|Dsa
expr_stmt|;
elseif|else
if|if
condition|(
name|oid
operator|==
name|EC_ENCRYPTION_OID
condition|)
name|publicKeyAlgorithm
operator|=
name|QSsl
operator|::
name|Ec
expr_stmt|;
else|else
name|publicKeyAlgorithm
operator|=
name|QSsl
operator|::
name|Opaque
expr_stmt|;
name|certStream
operator|.
name|device
argument_list|()
operator|->
name|seek
argument_list|(
name|keyStart
argument_list|)
expr_stmt|;
name|certStream
operator|.
name|readRawData
argument_list|(
name|publicKeyDerData
operator|.
name|data
argument_list|()
argument_list|,
name|publicKeyDerData
operator|.
name|size
argument_list|()
argument_list|)
expr_stmt|;
comment|// extensions
while|while
condition|(
name|elem
operator|.
name|read
argument_list|(
name|certStream
argument_list|)
condition|)
block|{
if|if
condition|(
name|elem
operator|.
name|type
argument_list|()
operator|==
name|QAsn1Element
operator|::
name|Context3Type
condition|)
block|{
if|if
condition|(
name|elem
operator|.
name|read
argument_list|(
name|elem
operator|.
name|value
argument_list|()
argument_list|)
operator|&&
name|elem
operator|.
name|type
argument_list|()
operator|==
name|QAsn1Element
operator|::
name|SequenceType
condition|)
block|{
name|QDataStream
name|extStream
argument_list|(
name|elem
operator|.
name|value
argument_list|()
argument_list|)
decl_stmt|;
while|while
condition|(
name|elem
operator|.
name|read
argument_list|(
name|extStream
argument_list|)
operator|&&
name|elem
operator|.
name|type
argument_list|()
operator|==
name|QAsn1Element
operator|::
name|SequenceType
condition|)
block|{
name|QSslCertificateExtension
name|extension
decl_stmt|;
if|if
condition|(
operator|!
name|parseExtension
argument_list|(
name|elem
operator|.
name|value
argument_list|()
argument_list|,
operator|&
name|extension
argument_list|)
condition|)
return|return
literal|false
return|;
name|extensions
operator|<<
name|extension
expr_stmt|;
if|if
condition|(
name|extension
operator|.
name|oid
argument_list|()
operator|==
name|QLatin1String
argument_list|(
literal|"2.5.29.17"
argument_list|)
condition|)
block|{
comment|// subjectAltName
name|QAsn1Element
name|sanElem
decl_stmt|;
if|if
condition|(
name|sanElem
operator|.
name|read
argument_list|(
name|extension
operator|.
name|value
argument_list|()
operator|.
name|toByteArray
argument_list|()
argument_list|)
operator|&&
name|sanElem
operator|.
name|type
argument_list|()
operator|==
name|QAsn1Element
operator|::
name|SequenceType
condition|)
block|{
name|QDataStream
name|nameStream
argument_list|(
name|sanElem
operator|.
name|value
argument_list|()
argument_list|)
decl_stmt|;
name|QAsn1Element
name|nameElem
decl_stmt|;
while|while
condition|(
name|nameElem
operator|.
name|read
argument_list|(
name|nameStream
argument_list|)
condition|)
block|{
if|if
condition|(
name|nameElem
operator|.
name|type
argument_list|()
operator|==
name|QAsn1Element
operator|::
name|Rfc822NameType
condition|)
block|{
name|subjectAlternativeNames
operator|.
name|insert
argument_list|(
name|QSsl
operator|::
name|EmailEntry
argument_list|,
name|nameElem
operator|.
name|toString
argument_list|()
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|nameElem
operator|.
name|type
argument_list|()
operator|==
name|QAsn1Element
operator|::
name|DnsNameType
condition|)
block|{
name|subjectAlternativeNames
operator|.
name|insert
argument_list|(
name|QSsl
operator|::
name|DnsEntry
argument_list|,
name|nameElem
operator|.
name|toString
argument_list|()
argument_list|)
expr_stmt|;
block|}
block|}
block|}
block|}
block|}
block|}
block|}
block|}
name|derData
operator|=
name|data
operator|.
name|left
argument_list|(
name|dataStream
operator|.
name|device
argument_list|()
operator|->
name|pos
argument_list|()
argument_list|)
expr_stmt|;
name|null
operator|=
literal|false
expr_stmt|;
return|return
literal|true
return|;
block|}
end_function
begin_function
DECL|function|parseExtension
name|bool
name|QSslCertificatePrivate
operator|::
name|parseExtension
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|data
parameter_list|,
name|QSslCertificateExtension
modifier|*
name|extension
parameter_list|)
block|{
name|bool
name|ok
decl_stmt|;
name|bool
name|critical
init|=
literal|false
decl_stmt|;
name|QAsn1Element
name|oidElem
decl_stmt|,
name|valElem
decl_stmt|;
name|QDataStream
name|seqStream
argument_list|(
name|data
argument_list|)
decl_stmt|;
comment|// oid
if|if
condition|(
operator|!
name|oidElem
operator|.
name|read
argument_list|(
name|seqStream
argument_list|)
operator|||
name|oidElem
operator|.
name|type
argument_list|()
operator|!=
name|QAsn1Element
operator|::
name|ObjectIdentifierType
condition|)
return|return
literal|false
return|;
specifier|const
name|QByteArray
name|oid
init|=
name|oidElem
operator|.
name|toObjectId
argument_list|()
decl_stmt|;
comment|// critical and value
if|if
condition|(
operator|!
name|valElem
operator|.
name|read
argument_list|(
name|seqStream
argument_list|)
condition|)
return|return
literal|false
return|;
if|if
condition|(
name|valElem
operator|.
name|type
argument_list|()
operator|==
name|QAsn1Element
operator|::
name|BooleanType
condition|)
block|{
name|critical
operator|=
name|valElem
operator|.
name|toBool
argument_list|(
operator|&
name|ok
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|ok
operator|||
operator|!
name|valElem
operator|.
name|read
argument_list|(
name|seqStream
argument_list|)
condition|)
return|return
literal|false
return|;
block|}
if|if
condition|(
name|valElem
operator|.
name|type
argument_list|()
operator|!=
name|QAsn1Element
operator|::
name|OctetStringType
condition|)
return|return
literal|false
return|;
comment|// interpret value
name|QAsn1Element
name|val
decl_stmt|;
name|bool
name|supported
init|=
literal|true
decl_stmt|;
name|QVariant
name|value
decl_stmt|;
if|if
condition|(
name|oid
operator|==
literal|"1.3.6.1.5.5.7.1.1"
condition|)
block|{
comment|// authorityInfoAccess
if|if
condition|(
operator|!
name|val
operator|.
name|read
argument_list|(
name|valElem
operator|.
name|value
argument_list|()
argument_list|)
operator|||
name|val
operator|.
name|type
argument_list|()
operator|!=
name|QAsn1Element
operator|::
name|SequenceType
condition|)
return|return
literal|false
return|;
name|QVariantMap
name|result
decl_stmt|;
specifier|const
specifier|auto
name|elems
init|=
name|val
operator|.
name|toVector
argument_list|()
decl_stmt|;
for|for
control|(
specifier|const
name|QAsn1Element
modifier|&
name|el
range|:
name|elems
control|)
block|{
name|QVector
argument_list|<
name|QAsn1Element
argument_list|>
name|items
init|=
name|el
operator|.
name|toVector
argument_list|()
decl_stmt|;
if|if
condition|(
name|items
operator|.
name|size
argument_list|()
operator|!=
literal|2
condition|)
return|return
literal|false
return|;
specifier|const
name|QString
name|key
init|=
name|QString
operator|::
name|fromLatin1
argument_list|(
name|items
operator|.
name|at
argument_list|(
literal|0
argument_list|)
operator|.
name|toObjectName
argument_list|()
argument_list|)
decl_stmt|;
switch|switch
condition|(
name|items
operator|.
name|at
argument_list|(
literal|1
argument_list|)
operator|.
name|type
argument_list|()
condition|)
block|{
case|case
name|QAsn1Element
operator|::
name|Rfc822NameType
case|:
case|case
name|QAsn1Element
operator|::
name|DnsNameType
case|:
case|case
name|QAsn1Element
operator|::
name|UniformResourceIdentifierType
case|:
name|result
index|[
name|key
index|]
operator|=
name|items
operator|.
name|at
argument_list|(
literal|1
argument_list|)
operator|.
name|toString
argument_list|()
expr_stmt|;
break|break;
block|}
block|}
name|value
operator|=
name|result
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|oid
operator|==
literal|"2.5.29.14"
condition|)
block|{
comment|// subjectKeyIdentifier
if|if
condition|(
operator|!
name|val
operator|.
name|read
argument_list|(
name|valElem
operator|.
name|value
argument_list|()
argument_list|)
operator|||
name|val
operator|.
name|type
argument_list|()
operator|!=
name|QAsn1Element
operator|::
name|OctetStringType
condition|)
return|return
literal|false
return|;
name|value
operator|=
name|colonSeparatedHex
argument_list|(
name|val
operator|.
name|value
argument_list|()
argument_list|)
operator|.
name|toUpper
argument_list|()
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|oid
operator|==
literal|"2.5.29.19"
condition|)
block|{
comment|// basicConstraints
if|if
condition|(
operator|!
name|val
operator|.
name|read
argument_list|(
name|valElem
operator|.
name|value
argument_list|()
argument_list|)
operator|||
name|val
operator|.
name|type
argument_list|()
operator|!=
name|QAsn1Element
operator|::
name|SequenceType
condition|)
return|return
literal|false
return|;
name|QVariantMap
name|result
decl_stmt|;
name|QVector
argument_list|<
name|QAsn1Element
argument_list|>
name|items
init|=
name|val
operator|.
name|toVector
argument_list|()
decl_stmt|;
if|if
condition|(
name|items
operator|.
name|size
argument_list|()
operator|>
literal|0
condition|)
block|{
name|result
index|[
name|QStringLiteral
argument_list|(
literal|"ca"
argument_list|)
index|]
operator|=
name|items
operator|.
name|at
argument_list|(
literal|0
argument_list|)
operator|.
name|toBool
argument_list|(
operator|&
name|ok
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|ok
condition|)
return|return
literal|false
return|;
block|}
else|else
block|{
name|result
index|[
name|QStringLiteral
argument_list|(
literal|"ca"
argument_list|)
index|]
operator|=
literal|false
expr_stmt|;
block|}
if|if
condition|(
name|items
operator|.
name|size
argument_list|()
operator|>
literal|1
condition|)
block|{
name|result
index|[
name|QStringLiteral
argument_list|(
literal|"pathLenConstraint"
argument_list|)
index|]
operator|=
name|items
operator|.
name|at
argument_list|(
literal|1
argument_list|)
operator|.
name|toInteger
argument_list|(
operator|&
name|ok
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|ok
condition|)
return|return
literal|false
return|;
block|}
name|value
operator|=
name|result
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|oid
operator|==
literal|"2.5.29.35"
condition|)
block|{
comment|// authorityKeyIdentifier
if|if
condition|(
operator|!
name|val
operator|.
name|read
argument_list|(
name|valElem
operator|.
name|value
argument_list|()
argument_list|)
operator|||
name|val
operator|.
name|type
argument_list|()
operator|!=
name|QAsn1Element
operator|::
name|SequenceType
condition|)
return|return
literal|false
return|;
name|QVariantMap
name|result
decl_stmt|;
specifier|const
specifier|auto
name|elems
init|=
name|val
operator|.
name|toVector
argument_list|()
decl_stmt|;
for|for
control|(
specifier|const
name|QAsn1Element
modifier|&
name|el
range|:
name|elems
control|)
block|{
if|if
condition|(
name|el
operator|.
name|type
argument_list|()
operator|==
literal|0x80
condition|)
block|{
name|result
index|[
name|QStringLiteral
argument_list|(
literal|"keyid"
argument_list|)
index|]
operator|=
name|el
operator|.
name|value
argument_list|()
operator|.
name|toHex
argument_list|()
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|el
operator|.
name|type
argument_list|()
operator|==
literal|0x82
condition|)
block|{
name|result
index|[
name|QStringLiteral
argument_list|(
literal|"serial"
argument_list|)
index|]
operator|=
name|colonSeparatedHex
argument_list|(
name|el
operator|.
name|value
argument_list|()
argument_list|)
expr_stmt|;
block|}
block|}
name|value
operator|=
name|result
expr_stmt|;
block|}
else|else
block|{
name|supported
operator|=
literal|false
expr_stmt|;
name|value
operator|=
name|valElem
operator|.
name|value
argument_list|()
expr_stmt|;
block|}
name|extension
operator|->
name|d
operator|->
name|critical
operator|=
name|critical
expr_stmt|;
name|extension
operator|->
name|d
operator|->
name|supported
operator|=
name|supported
expr_stmt|;
name|extension
operator|->
name|d
operator|->
name|oid
operator|=
name|QString
operator|::
name|fromLatin1
argument_list|(
name|oid
argument_list|)
expr_stmt|;
name|extension
operator|->
name|d
operator|->
name|name
operator|=
name|QString
operator|::
name|fromLatin1
argument_list|(
name|oidElem
operator|.
name|toObjectName
argument_list|()
argument_list|)
expr_stmt|;
name|extension
operator|->
name|d
operator|->
name|value
operator|=
name|value
expr_stmt|;
return|return
literal|true
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
