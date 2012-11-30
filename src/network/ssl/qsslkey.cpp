begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtNetwork module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_comment
comment|/*!     \class QSslKey     \brief The QSslKey class provides an interface for private and public keys.     \since 4.3      \reentrant     \ingroup network     \ingroup ssl     \ingroup shared     \inmodule QtNetwork      QSslKey provides a simple API for managing keys.      \sa QSslSocket, QSslCertificate, QSslCipher */
end_comment
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
file|"qsslsocket_openssl_symbols_p.h"
end_include
begin_include
include|#
directive|include
file|"qsslsocket.h"
end_include
begin_include
include|#
directive|include
file|"qsslsocket_p.h"
end_include
begin_include
include|#
directive|include
file|<QtCore/qatomic.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qbytearray.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qiodevice.h>
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_DEBUG_STREAM
end_ifndef
begin_include
include|#
directive|include
file|<QtCore/qdebug.h>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_function
name|QT_BEGIN_NAMESPACE
comment|/*!     \internal  */
DECL|function|clear
name|void
name|QSslKeyPrivate
operator|::
name|clear
parameter_list|(
name|bool
name|deep
parameter_list|)
block|{
name|isNull
operator|=
literal|true
expr_stmt|;
if|if
condition|(
operator|!
name|QSslSocket
operator|::
name|supportsSsl
argument_list|()
condition|)
return|return;
if|if
condition|(
name|rsa
condition|)
block|{
if|if
condition|(
name|deep
condition|)
name|q_RSA_free
argument_list|(
name|rsa
argument_list|)
expr_stmt|;
name|rsa
operator|=
literal|0
expr_stmt|;
block|}
if|if
condition|(
name|dsa
condition|)
block|{
if|if
condition|(
name|deep
condition|)
name|q_DSA_free
argument_list|(
name|dsa
argument_list|)
expr_stmt|;
name|dsa
operator|=
literal|0
expr_stmt|;
block|}
if|if
condition|(
name|opaque
condition|)
block|{
if|if
condition|(
name|deep
condition|)
name|q_EVP_PKEY_free
argument_list|(
name|opaque
argument_list|)
expr_stmt|;
name|opaque
operator|=
literal|0
expr_stmt|;
block|}
block|}
end_function
begin_comment
comment|/*!     \internal      Allocates a new rsa or dsa struct and decodes \a pem into it     according to the current algorithm and type.      If \a deepClear is true, the rsa/dsa struct is freed if it is was     already allocated, otherwise we "leak" memory (which is exactly     what we want for copy construction).      If \a passPhrase is non-empty, it will be used for decrypting     \a pem. */
end_comment
begin_function
DECL|function|decodePem
name|void
name|QSslKeyPrivate
operator|::
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
parameter_list|)
block|{
if|if
condition|(
name|pem
operator|.
name|isEmpty
argument_list|()
condition|)
return|return;
name|clear
argument_list|(
name|deepClear
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|QSslSocket
operator|::
name|supportsSsl
argument_list|()
condition|)
return|return;
name|BIO
modifier|*
name|bio
init|=
name|q_BIO_new_mem_buf
argument_list|(
cast|const_cast
argument_list|<
name|char
operator|*
argument_list|>
argument_list|(
name|pem
operator|.
name|data
argument_list|()
argument_list|)
argument_list|,
name|pem
operator|.
name|size
argument_list|()
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|bio
condition|)
return|return;
name|void
modifier|*
name|phrase
init|=
operator|(
name|void
operator|*
operator|)
name|passPhrase
operator|.
name|constData
argument_list|()
decl_stmt|;
if|if
condition|(
name|algorithm
operator|==
name|QSsl
operator|::
name|Rsa
condition|)
block|{
name|RSA
modifier|*
name|result
init|=
operator|(
name|type
operator|==
name|QSsl
operator|::
name|PublicKey
operator|)
condition|?
name|q_PEM_read_bio_RSA_PUBKEY
argument_list|(
name|bio
argument_list|,
operator|&
name|rsa
argument_list|,
literal|0
argument_list|,
name|phrase
argument_list|)
else|:
name|q_PEM_read_bio_RSAPrivateKey
argument_list|(
name|bio
argument_list|,
operator|&
name|rsa
argument_list|,
literal|0
argument_list|,
name|phrase
argument_list|)
decl_stmt|;
if|if
condition|(
name|rsa
operator|&&
name|rsa
operator|==
name|result
condition|)
name|isNull
operator|=
literal|false
expr_stmt|;
block|}
else|else
block|{
name|DSA
modifier|*
name|result
init|=
operator|(
name|type
operator|==
name|QSsl
operator|::
name|PublicKey
operator|)
condition|?
name|q_PEM_read_bio_DSA_PUBKEY
argument_list|(
name|bio
argument_list|,
operator|&
name|dsa
argument_list|,
literal|0
argument_list|,
name|phrase
argument_list|)
else|:
name|q_PEM_read_bio_DSAPrivateKey
argument_list|(
name|bio
argument_list|,
operator|&
name|dsa
argument_list|,
literal|0
argument_list|,
name|phrase
argument_list|)
decl_stmt|;
if|if
condition|(
name|dsa
operator|&&
name|dsa
operator|==
name|result
condition|)
name|isNull
operator|=
literal|false
expr_stmt|;
block|}
name|q_BIO_free
argument_list|(
name|bio
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     Constructs a null key.      \sa isNull() */
end_comment
begin_constructor
DECL|function|QSslKey
name|QSslKey
operator|::
name|QSslKey
parameter_list|()
member_init_list|:
name|d
argument_list|(
operator|new
name|QSslKeyPrivate
argument_list|)
block|{ }
end_constructor
begin_comment
comment|/*!     \internal */
end_comment
begin_function
DECL|function|pemHeader
name|QByteArray
name|QSslKeyPrivate
operator|::
name|pemHeader
parameter_list|()
specifier|const
block|{
comment|// ### use QByteArray::fromRawData() instead
if|if
condition|(
name|type
operator|==
name|QSsl
operator|::
name|PublicKey
condition|)
return|return
name|QByteArray
argument_list|(
literal|"-----BEGIN PUBLIC KEY-----\n"
argument_list|)
return|;
elseif|else
if|if
condition|(
name|algorithm
operator|==
name|QSsl
operator|::
name|Rsa
condition|)
return|return
name|QByteArray
argument_list|(
literal|"-----BEGIN RSA PRIVATE KEY-----\n"
argument_list|)
return|;
return|return
name|QByteArray
argument_list|(
literal|"-----BEGIN DSA PRIVATE KEY-----\n"
argument_list|)
return|;
block|}
end_function
begin_comment
comment|/*!     \internal */
end_comment
begin_function
DECL|function|pemFooter
name|QByteArray
name|QSslKeyPrivate
operator|::
name|pemFooter
parameter_list|()
specifier|const
block|{
comment|// ### use QByteArray::fromRawData() instead
if|if
condition|(
name|type
operator|==
name|QSsl
operator|::
name|PublicKey
condition|)
return|return
name|QByteArray
argument_list|(
literal|"-----END PUBLIC KEY-----\n"
argument_list|)
return|;
elseif|else
if|if
condition|(
name|algorithm
operator|==
name|QSsl
operator|::
name|Rsa
condition|)
return|return
name|QByteArray
argument_list|(
literal|"-----END RSA PRIVATE KEY-----\n"
argument_list|)
return|;
return|return
name|QByteArray
argument_list|(
literal|"-----END DSA PRIVATE KEY-----\n"
argument_list|)
return|;
block|}
end_function
begin_comment
comment|/*!     \internal      Returns a DER key formatted as PEM. */
end_comment
begin_function
DECL|function|pemFromDer
name|QByteArray
name|QSslKeyPrivate
operator|::
name|pemFromDer
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|der
parameter_list|)
specifier|const
block|{
name|QByteArray
name|pem
argument_list|(
name|der
operator|.
name|toBase64
argument_list|()
argument_list|)
decl_stmt|;
specifier|const
name|int
name|lineWidth
init|=
literal|64
decl_stmt|;
comment|// RFC 1421
specifier|const
name|int
name|newLines
init|=
name|pem
operator|.
name|size
argument_list|()
operator|/
name|lineWidth
decl_stmt|;
specifier|const
name|bool
name|rem
init|=
name|pem
operator|.
name|size
argument_list|()
operator|%
name|lineWidth
decl_stmt|;
comment|// ### optimize
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|newLines
condition|;
operator|++
name|i
control|)
name|pem
operator|.
name|insert
argument_list|(
operator|(
name|i
operator|+
literal|1
operator|)
operator|*
name|lineWidth
operator|+
name|i
argument_list|,
literal|'\n'
argument_list|)
expr_stmt|;
if|if
condition|(
name|rem
condition|)
name|pem
operator|.
name|append
argument_list|(
literal|'\n'
argument_list|)
expr_stmt|;
comment|// ###
name|pem
operator|.
name|prepend
argument_list|(
name|pemHeader
argument_list|()
argument_list|)
expr_stmt|;
name|pem
operator|.
name|append
argument_list|(
name|pemFooter
argument_list|()
argument_list|)
expr_stmt|;
return|return
name|pem
return|;
block|}
end_function
begin_comment
comment|/*!     \internal      Returns a PEM key formatted as DER. */
end_comment
begin_function
DECL|function|derFromPem
name|QByteArray
name|QSslKeyPrivate
operator|::
name|derFromPem
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|pem
parameter_list|)
specifier|const
block|{
specifier|const
name|QByteArray
name|header
init|=
name|pemHeader
argument_list|()
decl_stmt|;
specifier|const
name|QByteArray
name|footer
init|=
name|pemFooter
argument_list|()
decl_stmt|;
name|QByteArray
name|der
argument_list|(
name|pem
argument_list|)
decl_stmt|;
specifier|const
name|int
name|headerIndex
init|=
name|der
operator|.
name|indexOf
argument_list|(
name|header
argument_list|)
decl_stmt|;
specifier|const
name|int
name|footerIndex
init|=
name|der
operator|.
name|indexOf
argument_list|(
name|footer
argument_list|)
decl_stmt|;
if|if
condition|(
name|headerIndex
operator|==
operator|-
literal|1
operator|||
name|footerIndex
operator|==
operator|-
literal|1
condition|)
return|return
name|QByteArray
argument_list|()
return|;
name|der
operator|=
name|der
operator|.
name|mid
argument_list|(
name|headerIndex
operator|+
name|header
operator|.
name|size
argument_list|()
argument_list|,
name|footerIndex
operator|-
operator|(
name|headerIndex
operator|+
name|header
operator|.
name|size
argument_list|()
operator|)
argument_list|)
expr_stmt|;
return|return
name|QByteArray
operator|::
name|fromBase64
argument_list|(
name|der
argument_list|)
return|;
comment|// ignores newlines
block|}
end_function
begin_comment
comment|/*!     Constructs a QSslKey by decoding the string in the byte array     \a encoded using a specified \a algorithm and \a encoding format.     If the encoded key is encrypted, \a passPhrase is used to decrypt     it. \a type specifies whether the key is public or private.      After construction, use isNull() to check if \a encoded contained     a valid key. */
end_comment
begin_constructor
DECL|function|QSslKey
name|QSslKey
operator|::
name|QSslKey
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|encoded
parameter_list|,
name|QSsl
operator|::
name|KeyAlgorithm
name|algorithm
parameter_list|,
name|QSsl
operator|::
name|EncodingFormat
name|encoding
parameter_list|,
name|QSsl
operator|::
name|KeyType
name|type
parameter_list|,
specifier|const
name|QByteArray
modifier|&
name|passPhrase
parameter_list|)
member_init_list|:
name|d
argument_list|(
operator|new
name|QSslKeyPrivate
argument_list|)
block|{
name|d
operator|->
name|type
operator|=
name|type
expr_stmt|;
name|d
operator|->
name|algorithm
operator|=
name|algorithm
expr_stmt|;
name|d
operator|->
name|decodePem
argument_list|(
operator|(
name|encoding
operator|==
name|QSsl
operator|::
name|Der
operator|)
condition|?
name|d
operator|->
name|pemFromDer
argument_list|(
name|encoded
argument_list|)
else|:
name|encoded
argument_list|,
name|passPhrase
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_comment
comment|/*!     Constructs a QSslKey by reading and decoding data from a     \a device using a specified \a algorithm and \a encoding format.     If the encoded key is encrypted, \a passPhrase is used to decrypt     it. \a type specifies whether the key is public or private.      After construction, use isNull() to check if \a device provided     a valid key. */
end_comment
begin_constructor
DECL|function|QSslKey
name|QSslKey
operator|::
name|QSslKey
parameter_list|(
name|QIODevice
modifier|*
name|device
parameter_list|,
name|QSsl
operator|::
name|KeyAlgorithm
name|algorithm
parameter_list|,
name|QSsl
operator|::
name|EncodingFormat
name|encoding
parameter_list|,
name|QSsl
operator|::
name|KeyType
name|type
parameter_list|,
specifier|const
name|QByteArray
modifier|&
name|passPhrase
parameter_list|)
member_init_list|:
name|d
argument_list|(
operator|new
name|QSslKeyPrivate
argument_list|)
block|{
name|QByteArray
name|encoded
decl_stmt|;
if|if
condition|(
name|device
condition|)
name|encoded
operator|=
name|device
operator|->
name|readAll
argument_list|()
expr_stmt|;
name|d
operator|->
name|type
operator|=
name|type
expr_stmt|;
name|d
operator|->
name|algorithm
operator|=
name|algorithm
expr_stmt|;
name|d
operator|->
name|decodePem
argument_list|(
operator|(
name|encoding
operator|==
name|QSsl
operator|::
name|Der
operator|)
condition|?
name|d
operator|->
name|pemFromDer
argument_list|(
name|encoded
argument_list|)
else|:
name|encoded
argument_list|,
name|passPhrase
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_comment
comment|/*!     \since 5.0     Constructs a QSslKey from a valid native key \a handle.     \a type specifies whether the key is public or private.      QSslKey will take ownership for this key and you must not     free the key using the native library. The algorithm used     when creating a key from a handle will always be QSsl::Opaque. */
end_comment
begin_constructor
DECL|function|QSslKey
name|QSslKey
operator|::
name|QSslKey
parameter_list|(
name|Qt
operator|::
name|HANDLE
name|handle
parameter_list|,
name|QSsl
operator|::
name|KeyType
name|type
parameter_list|)
member_init_list|:
name|d
argument_list|(
operator|new
name|QSslKeyPrivate
argument_list|)
block|{
name|d
operator|->
name|opaque
operator|=
cast|reinterpret_cast
argument_list|<
name|EVP_PKEY
operator|*
argument_list|>
argument_list|(
name|handle
argument_list|)
expr_stmt|;
name|d
operator|->
name|algorithm
operator|=
name|QSsl
operator|::
name|Opaque
expr_stmt|;
name|d
operator|->
name|type
operator|=
name|type
expr_stmt|;
name|d
operator|->
name|isNull
operator|=
operator|!
name|d
operator|->
name|opaque
expr_stmt|;
block|}
end_constructor
begin_comment
comment|/*!     Constructs an identical copy of \a other. */
end_comment
begin_constructor
DECL|function|QSslKey
name|QSslKey
operator|::
name|QSslKey
parameter_list|(
specifier|const
name|QSslKey
modifier|&
name|other
parameter_list|)
member_init_list|:
name|d
argument_list|(
name|other
operator|.
name|d
argument_list|)
block|{ }
end_constructor
begin_comment
comment|/*!     Destroys the QSslKey object. */
end_comment
begin_destructor
DECL|function|~QSslKey
name|QSslKey
operator|::
name|~
name|QSslKey
parameter_list|()
block|{ }
end_destructor
begin_comment
comment|/*!     Copies the contents of \a other into this key, making the two keys     identical.      Returns a reference to this QSslKey. */
end_comment
begin_function
DECL|function|operator =
name|QSslKey
modifier|&
name|QSslKey
operator|::
name|operator
name|=
parameter_list|(
specifier|const
name|QSslKey
modifier|&
name|other
parameter_list|)
block|{
name|d
operator|=
name|other
operator|.
name|d
expr_stmt|;
return|return
operator|*
name|this
return|;
block|}
end_function
begin_comment
comment|/*!     \fn void QSslKey::swap(QSslKey&other)     \since 5.0      Swaps this ssl key with \a other. This function is very fast and     never fails. */
end_comment
begin_comment
comment|/*!     Returns true if this is a null key; otherwise false.      \sa clear() */
end_comment
begin_function
DECL|function|isNull
name|bool
name|QSslKey
operator|::
name|isNull
parameter_list|()
specifier|const
block|{
return|return
name|d
operator|->
name|isNull
return|;
block|}
end_function
begin_comment
comment|/*!     Clears the contents of this key, making it a null key.      \sa isNull() */
end_comment
begin_function
DECL|function|clear
name|void
name|QSslKey
operator|::
name|clear
parameter_list|()
block|{
name|d
operator|=
operator|new
name|QSslKeyPrivate
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     Returns the length of the key in bits, or -1 if the key is null. */
end_comment
begin_function
DECL|function|length
name|int
name|QSslKey
operator|::
name|length
parameter_list|()
specifier|const
block|{
if|if
condition|(
name|d
operator|->
name|isNull
operator|||
name|d
operator|->
name|algorithm
operator|==
name|QSsl
operator|::
name|Opaque
condition|)
return|return
operator|-
literal|1
return|;
return|return
operator|(
name|d
operator|->
name|algorithm
operator|==
name|QSsl
operator|::
name|Rsa
operator|)
condition|?
name|q_BN_num_bits
argument_list|(
name|d
operator|->
name|rsa
operator|->
name|n
argument_list|)
else|:
name|q_BN_num_bits
argument_list|(
name|d
operator|->
name|dsa
operator|->
name|p
argument_list|)
return|;
block|}
end_function
begin_comment
comment|/*!     Returns the type of the key (i.e., PublicKey or PrivateKey). */
end_comment
begin_function
DECL|function|type
name|QSsl
operator|::
name|KeyType
name|QSslKey
operator|::
name|type
parameter_list|()
specifier|const
block|{
return|return
name|d
operator|->
name|type
return|;
block|}
end_function
begin_comment
comment|/*!     Returns the key algorithm. */
end_comment
begin_function
DECL|function|algorithm
name|QSsl
operator|::
name|KeyAlgorithm
name|QSslKey
operator|::
name|algorithm
parameter_list|()
specifier|const
block|{
return|return
name|d
operator|->
name|algorithm
return|;
block|}
end_function
begin_comment
comment|/*!   Returns the key in DER encoding. The result is encrypted with   \a passPhrase if the key is a private key and \a passPhrase is   non-empty. */
end_comment
begin_comment
comment|// ### autotest failure for non-empty passPhrase and private key
end_comment
begin_function
DECL|function|toDer
name|QByteArray
name|QSslKey
operator|::
name|toDer
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|passPhrase
parameter_list|)
specifier|const
block|{
if|if
condition|(
name|d
operator|->
name|isNull
operator|||
name|d
operator|->
name|algorithm
operator|==
name|QSsl
operator|::
name|Opaque
condition|)
return|return
name|QByteArray
argument_list|()
return|;
return|return
name|d
operator|->
name|derFromPem
argument_list|(
name|toPem
argument_list|(
name|passPhrase
argument_list|)
argument_list|)
return|;
block|}
end_function
begin_comment
comment|/*!   Returns the key in PEM encoding. The result is encrypted with   \a passPhrase if the key is a private key and \a passPhrase is   non-empty. */
end_comment
begin_function
DECL|function|toPem
name|QByteArray
name|QSslKey
operator|::
name|toPem
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|passPhrase
parameter_list|)
specifier|const
block|{
if|if
condition|(
operator|!
name|QSslSocket
operator|::
name|supportsSsl
argument_list|()
operator|||
name|d
operator|->
name|isNull
operator|||
name|d
operator|->
name|algorithm
operator|==
name|QSsl
operator|::
name|Opaque
condition|)
return|return
name|QByteArray
argument_list|()
return|;
name|BIO
modifier|*
name|bio
init|=
name|q_BIO_new
argument_list|(
name|q_BIO_s_mem
argument_list|()
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|bio
condition|)
return|return
name|QByteArray
argument_list|()
return|;
name|bool
name|fail
init|=
literal|false
decl_stmt|;
if|if
condition|(
name|d
operator|->
name|algorithm
operator|==
name|QSsl
operator|::
name|Rsa
condition|)
block|{
if|if
condition|(
name|d
operator|->
name|type
operator|==
name|QSsl
operator|::
name|PublicKey
condition|)
block|{
if|if
condition|(
operator|!
name|q_PEM_write_bio_RSA_PUBKEY
argument_list|(
name|bio
argument_list|,
name|d
operator|->
name|rsa
argument_list|)
condition|)
name|fail
operator|=
literal|true
expr_stmt|;
block|}
else|else
block|{
if|if
condition|(
operator|!
name|q_PEM_write_bio_RSAPrivateKey
argument_list|(
name|bio
argument_list|,
name|d
operator|->
name|rsa
argument_list|,
comment|// ### the cipher should be selectable in the API:
name|passPhrase
operator|.
name|isEmpty
argument_list|()
condition|?
operator|(
specifier|const
name|EVP_CIPHER
operator|*
operator|)
literal|0
else|:
name|q_EVP_des_ede3_cbc
argument_list|()
argument_list|,
operator|(
name|uchar
operator|*
operator|)
name|passPhrase
operator|.
name|data
argument_list|()
argument_list|,
name|passPhrase
operator|.
name|size
argument_list|()
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
condition|)
block|{
name|fail
operator|=
literal|true
expr_stmt|;
block|}
block|}
block|}
else|else
block|{
if|if
condition|(
name|d
operator|->
name|type
operator|==
name|QSsl
operator|::
name|PublicKey
condition|)
block|{
if|if
condition|(
operator|!
name|q_PEM_write_bio_DSA_PUBKEY
argument_list|(
name|bio
argument_list|,
name|d
operator|->
name|dsa
argument_list|)
condition|)
name|fail
operator|=
literal|true
expr_stmt|;
block|}
else|else
block|{
if|if
condition|(
operator|!
name|q_PEM_write_bio_DSAPrivateKey
argument_list|(
name|bio
argument_list|,
name|d
operator|->
name|dsa
argument_list|,
comment|// ### the cipher should be selectable in the API:
name|passPhrase
operator|.
name|isEmpty
argument_list|()
condition|?
operator|(
specifier|const
name|EVP_CIPHER
operator|*
operator|)
literal|0
else|:
name|q_EVP_des_ede3_cbc
argument_list|()
argument_list|,
operator|(
name|uchar
operator|*
operator|)
name|passPhrase
operator|.
name|data
argument_list|()
argument_list|,
name|passPhrase
operator|.
name|size
argument_list|()
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
condition|)
block|{
name|fail
operator|=
literal|true
expr_stmt|;
block|}
block|}
block|}
name|QByteArray
name|pem
decl_stmt|;
if|if
condition|(
operator|!
name|fail
condition|)
block|{
name|char
modifier|*
name|data
decl_stmt|;
name|long
name|size
init|=
name|q_BIO_get_mem_data
argument_list|(
name|bio
argument_list|,
operator|&
name|data
argument_list|)
decl_stmt|;
name|pem
operator|=
name|QByteArray
argument_list|(
name|data
argument_list|,
name|size
argument_list|)
expr_stmt|;
block|}
name|q_BIO_free
argument_list|(
name|bio
argument_list|)
expr_stmt|;
return|return
name|pem
return|;
block|}
end_function
begin_comment
comment|/*!     Returns a pointer to the native key handle, if it is available;     otherwise a null pointer is returned.      You can use this handle together with the native API to access     extended information about the key.      \warning Use of this function has a high probability of being     non-portable, and its return value may vary across platforms, and     between minor Qt releases. */
end_comment
begin_function
DECL|function|handle
name|Qt
operator|::
name|HANDLE
name|QSslKey
operator|::
name|handle
parameter_list|()
specifier|const
block|{
switch|switch
condition|(
name|d
operator|->
name|algorithm
condition|)
block|{
case|case
name|QSsl
operator|::
name|Opaque
case|:
return|return
name|Qt
operator|::
name|HANDLE
argument_list|(
name|d
operator|->
name|opaque
argument_list|)
return|;
case|case
name|QSsl
operator|::
name|Rsa
case|:
return|return
name|Qt
operator|::
name|HANDLE
argument_list|(
name|d
operator|->
name|rsa
argument_list|)
return|;
case|case
name|QSsl
operator|::
name|Dsa
case|:
return|return
name|Qt
operator|::
name|HANDLE
argument_list|(
name|d
operator|->
name|dsa
argument_list|)
return|;
default|default:
return|return
name|Qt
operator|::
name|HANDLE
argument_list|(
name|NULL
argument_list|)
return|;
block|}
block|}
end_function
begin_comment
comment|/*!     Returns true if this key is equal to \a other; otherwise returns false. */
end_comment
begin_function
DECL|function|operator ==
name|bool
name|QSslKey
operator|::
name|operator
name|==
parameter_list|(
specifier|const
name|QSslKey
modifier|&
name|other
parameter_list|)
specifier|const
block|{
if|if
condition|(
name|isNull
argument_list|()
condition|)
return|return
name|other
operator|.
name|isNull
argument_list|()
return|;
if|if
condition|(
name|other
operator|.
name|isNull
argument_list|()
condition|)
return|return
name|isNull
argument_list|()
return|;
if|if
condition|(
name|algorithm
argument_list|()
operator|!=
name|other
operator|.
name|algorithm
argument_list|()
condition|)
return|return
literal|false
return|;
if|if
condition|(
name|type
argument_list|()
operator|!=
name|other
operator|.
name|type
argument_list|()
condition|)
return|return
literal|false
return|;
if|if
condition|(
name|length
argument_list|()
operator|!=
name|other
operator|.
name|length
argument_list|()
condition|)
return|return
literal|false
return|;
if|if
condition|(
name|algorithm
argument_list|()
operator|==
name|QSsl
operator|::
name|Opaque
condition|)
return|return
name|handle
argument_list|()
operator|==
name|other
operator|.
name|handle
argument_list|()
return|;
return|return
name|toDer
argument_list|()
operator|==
name|other
operator|.
name|toDer
argument_list|()
return|;
block|}
end_function
begin_comment
comment|/*! \fn bool QSslKey::operator!=(const QSslKey&other) const    Returns true if this key is not equal to key \a other; otherwise   returns false. */
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_DEBUG_STREAM
end_ifndef
begin_class_decl
class_decl|class
name|QDebug
class_decl|;
end_class_decl
begin_function
DECL|function|operator <<
name|QDebug
name|operator
name|<<
parameter_list|(
name|QDebug
name|debug
parameter_list|,
specifier|const
name|QSslKey
modifier|&
name|key
parameter_list|)
block|{
name|debug
operator|<<
literal|"QSslKey("
operator|<<
operator|(
name|key
operator|.
name|type
argument_list|()
operator|==
name|QSsl
operator|::
name|PublicKey
condition|?
literal|"PublicKey"
else|:
literal|"PrivateKey"
operator|)
operator|<<
literal|", "
operator|<<
operator|(
name|key
operator|.
name|algorithm
argument_list|()
operator|==
name|QSsl
operator|::
name|Opaque
condition|?
literal|"OPAQUE"
else|:
operator|(
name|key
operator|.
name|algorithm
argument_list|()
operator|==
name|QSsl
operator|::
name|Rsa
condition|?
literal|"RSA"
else|:
literal|"DSA"
operator|)
operator|)
operator|<<
literal|", "
operator|<<
name|key
operator|.
name|length
argument_list|()
operator|<<
literal|')'
expr_stmt|;
return|return
name|debug
return|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
