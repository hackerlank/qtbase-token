begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtNetwork module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** No Commercial Usage ** This file contains pre-release code and may not be distributed. ** You may use this file in accordance with the terms and conditions ** contained in the Technology Preview License Agreement accompanying ** this package. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights.  These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** If you have questions regarding the use of this file, please contact ** Nokia at qt-info@nokia.com. ** ** ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QSSLCERTIFICATE_H
end_ifndef
begin_define
DECL|macro|QSSLCERTIFICATE_H
define|#
directive|define
name|QSSLCERTIFICATE_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qnamespace.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qbytearray.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qcryptographichash.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qregexp.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qsharedpointer.h>
end_include
begin_include
include|#
directive|include
file|<QtNetwork/qssl.h>
end_include
begin_typedef
DECL|typedef|X509
typedef|typedef
name|struct
name|x509_st
name|X509
typedef|;
end_typedef
begin_comment
DECL|typedef|X509
comment|// ### check if this works
end_comment
begin_decl_stmt
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
name|QT_MODULE
argument_list|(
name|Network
argument_list|)
ifndef|#
directive|ifndef
name|QT_NO_OPENSSL
name|class
name|QDateTime
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QIODevice
name|class
name|QIODevice
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QSslKey
name|class
name|QSslKey
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QStringList
name|class
name|QStringList
decl_stmt|;
end_decl_stmt
begin_expr_stmt
DECL|variable|T
DECL|variable|QMultiMap
name|template
operator|<
name|typename
name|T
operator|,
name|typename
name|U
operator|>
name|class
name|QMultiMap
expr_stmt|;
end_expr_stmt
begin_decl_stmt
DECL|variable|QSslCertificatePrivate
name|class
name|QSslCertificatePrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_NETWORK_EXPORT
name|QSslCertificate
block|{
name|public
label|:
enum|enum
name|SubjectInfo
block|{
name|Organization
block|,
name|CommonName
block|,
name|LocalityName
block|,
name|OrganizationalUnitName
block|,
name|CountryName
block|,
name|StateOrProvinceName
block|}
enum|;
name|QSslCertificate
argument_list|(
argument|QIODevice *device
argument_list|,
argument|QSsl::EncodingFormat format = QSsl::Pem
argument_list|)
empty_stmt|;
name|QSslCertificate
argument_list|(
comment|// ### s/encoded/data (to be consistent with signature in .cpp file) ?
argument|const QByteArray&encoded = QByteArray()
argument_list|,
argument|QSsl::EncodingFormat format = QSsl::Pem
argument_list|)
empty_stmt|;
name|QSslCertificate
argument_list|(
specifier|const
name|QSslCertificate
operator|&
name|other
argument_list|)
expr_stmt|;
operator|~
name|QSslCertificate
argument_list|()
expr_stmt|;
name|QSslCertificate
modifier|&
name|operator
init|=
operator|(
specifier|const
name|QSslCertificate
operator|&
name|other
operator|)
decl_stmt|;
name|bool
name|operator
operator|==
operator|(
specifier|const
name|QSslCertificate
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
name|QSslCertificate
operator|&
name|other
operator|)
specifier|const
block|{
return|return
operator|!
name|operator
operator|==
operator|(
name|other
operator|)
return|;
block|}
name|bool
name|isNull
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|isValid
argument_list|()
specifier|const
expr_stmt|;
name|void
name|clear
parameter_list|()
function_decl|;
comment|// Certificate info
name|QByteArray
name|version
argument_list|()
specifier|const
expr_stmt|;
name|QByteArray
name|serialNumber
argument_list|()
specifier|const
expr_stmt|;
name|QByteArray
name|digest
argument_list|(
name|QCryptographicHash
operator|::
name|Algorithm
name|algorithm
operator|=
name|QCryptographicHash
operator|::
name|Md5
argument_list|)
decl|const
decl_stmt|;
name|QString
name|issuerInfo
argument_list|(
name|SubjectInfo
name|info
argument_list|)
decl|const
decl_stmt|;
name|QString
name|issuerInfo
argument_list|(
specifier|const
name|QByteArray
operator|&
name|tag
argument_list|)
decl|const
decl_stmt|;
name|QString
name|subjectInfo
argument_list|(
name|SubjectInfo
name|info
argument_list|)
decl|const
decl_stmt|;
name|QString
name|subjectInfo
argument_list|(
specifier|const
name|QByteArray
operator|&
name|tag
argument_list|)
decl|const
decl_stmt|;
name|QMultiMap
operator|<
name|QSsl
operator|::
name|AlternateNameEntryType
operator|,
name|QString
operator|>
name|alternateSubjectNames
argument_list|()
specifier|const
expr_stmt|;
name|QDateTime
name|effectiveDate
argument_list|()
specifier|const
expr_stmt|;
name|QDateTime
name|expiryDate
argument_list|()
specifier|const
expr_stmt|;
name|QSslKey
name|publicKey
argument_list|()
specifier|const
expr_stmt|;
name|QByteArray
name|toPem
argument_list|()
specifier|const
expr_stmt|;
name|QByteArray
name|toDer
argument_list|()
specifier|const
expr_stmt|;
specifier|static
name|QList
operator|<
name|QSslCertificate
operator|>
name|fromPath
argument_list|(
argument|const QString&path
argument_list|,
argument|QSsl::EncodingFormat format = QSsl::Pem
argument_list|,
argument|QRegExp::PatternSyntax syntax = QRegExp::FixedString
argument_list|)
expr_stmt|;
specifier|static
name|QList
operator|<
name|QSslCertificate
operator|>
name|fromDevice
argument_list|(
argument|QIODevice *device
argument_list|,
argument|QSsl::EncodingFormat format = QSsl::Pem
argument_list|)
expr_stmt|;
specifier|static
name|QList
operator|<
name|QSslCertificate
operator|>
name|fromData
argument_list|(
argument|const QByteArray&data
argument_list|,
argument|QSsl::EncodingFormat format = QSsl::Pem
argument_list|)
expr_stmt|;
name|Qt
operator|::
name|HANDLE
name|handle
argument_list|()
specifier|const
expr_stmt|;
name|private
label|:
name|QExplicitlySharedDataPointer
operator|<
name|QSslCertificatePrivate
operator|>
name|d
expr_stmt|;
name|friend
name|class
name|QSslCertificatePrivate
decl_stmt|;
name|friend
name|class
name|QSslSocketBackendPrivate
decl_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_DEBUG_STREAM
end_ifndef
begin_decl_stmt
DECL|variable|QDebug
name|class
name|QDebug
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|Q_NETWORK_EXPORT
name|QDebug
name|operator
operator|<<
operator|(
name|QDebug
name|debug
operator|,
specifier|const
name|QSslCertificate
operator|&
name|certificate
operator|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|Q_NETWORK_EXPORT
name|QDebug
name|operator
operator|<<
operator|(
name|QDebug
name|debug
operator|,
name|QSslCertificate
operator|::
name|SubjectInfo
name|info
operator|)
expr_stmt|;
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_OPENSSL
end_comment
begin_expr_stmt
name|QT_END_NAMESPACE
name|QT_END_HEADER
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
end_unit
