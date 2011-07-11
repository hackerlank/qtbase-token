begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtNetwork module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QSSLCERTIFICATE_P_H
end_ifndef
begin_define
DECL|macro|QSSLCERTIFICATE_P_H
define|#
directive|define
name|QSSLCERTIFICATE_P_H
end_define
begin_include
include|#
directive|include
file|"qsslcertificate.h"
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
comment|// of the QLibrary class.  This header file may change from
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
file|"qsslsocket_p.h"
end_include
begin_include
include|#
directive|include
file|<QtCore/qdatetime.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qmap.h>
end_include
begin_include
include|#
directive|include
file|<openssl/x509.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
name|class
name|QSslCertificatePrivate
block|{
name|public
label|:
name|QSslCertificatePrivate
argument_list|()
operator|:
name|null
argument_list|(
name|true
argument_list|)
operator|,
name|x509
argument_list|(
literal|0
argument_list|)
block|{
name|QSslSocketPrivate
operator|::
name|ensureInitialized
argument_list|()
block|;     }
operator|~
name|QSslCertificatePrivate
argument_list|()
block|{
if|if
condition|(
name|x509
condition|)
name|q_X509_free
argument_list|(
name|x509
argument_list|)
expr_stmt|;
block|}
name|bool
name|null
decl_stmt|;
name|QByteArray
name|versionString
decl_stmt|;
name|QByteArray
name|serialNumberString
decl_stmt|;
name|QMap
operator|<
name|QByteArray
operator|,
name|QString
operator|>
name|issuerInfo
expr_stmt|;
name|QMap
operator|<
name|QByteArray
operator|,
name|QString
operator|>
name|subjectInfo
expr_stmt|;
name|QDateTime
name|notValidAfter
decl_stmt|;
name|QDateTime
name|notValidBefore
decl_stmt|;
name|X509
modifier|*
name|x509
decl_stmt|;
name|void
name|init
argument_list|(
specifier|const
name|QByteArray
operator|&
name|data
argument_list|,
name|QSsl
operator|::
name|EncodingFormat
name|format
argument_list|)
decl_stmt|;
specifier|static
name|QByteArray
name|QByteArray_from_X509
argument_list|(
name|X509
operator|*
name|x509
argument_list|,
name|QSsl
operator|::
name|EncodingFormat
name|format
argument_list|)
decl_stmt|;
specifier|static
name|QByteArray
name|text_from_X509
parameter_list|(
name|X509
modifier|*
name|x509
parameter_list|)
function_decl|;
specifier|static
name|QSslCertificate
name|QSslCertificate_from_X509
parameter_list|(
name|X509
modifier|*
name|x509
parameter_list|)
function_decl|;
specifier|static
name|QList
operator|<
name|QSslCertificate
operator|>
name|certificatesFromPem
argument_list|(
argument|const QByteArray&pem
argument_list|,
argument|int count = -
literal|1
argument_list|)
expr_stmt|;
specifier|static
name|QList
operator|<
name|QSslCertificate
operator|>
name|certificatesFromDer
argument_list|(
argument|const QByteArray&der
argument_list|,
argument|int count = -
literal|1
argument_list|)
expr_stmt|;
specifier|static
name|bool
name|isBlacklisted
parameter_list|(
specifier|const
name|QSslCertificate
modifier|&
name|certificate
parameter_list|)
function_decl|;
name|friend
name|class
name|QSslSocketBackendPrivate
decl_stmt|;
name|QAtomicInt
name|ref
decl_stmt|;
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
end_unit
