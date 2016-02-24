begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the QtNetwork module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
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
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_comment
comment|/*!     \fn void QSslKeyPrivate::clear(bool deep)     \internal  */
end_comment
begin_comment
comment|/*!     \fn void QSslKeyPrivate::decodePem(const QByteArray&pem, const QByteArray&passPhrase,                                bool deepClear)     \internal      Allocates a new rsa or dsa struct and decodes \a pem into it     according to the current algorithm and type.      If \a deepClear is true, the rsa/dsa struct is freed if it is was     already allocated, otherwise we "leak" memory (which is exactly     what we want for copy construction).      If \a passPhrase is non-empty, it will be used for decrypting     \a pem. */
end_comment
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
if|if
condition|(
name|type
operator|==
name|QSsl
operator|::
name|PublicKey
condition|)
return|return
name|QByteArrayLiteral
argument_list|(
literal|"-----BEGIN PUBLIC KEY-----"
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
name|QByteArrayLiteral
argument_list|(
literal|"-----BEGIN RSA PRIVATE KEY-----"
argument_list|)
return|;
elseif|else
if|if
condition|(
name|algorithm
operator|==
name|QSsl
operator|::
name|Dsa
condition|)
return|return
name|QByteArrayLiteral
argument_list|(
literal|"-----BEGIN DSA PRIVATE KEY-----"
argument_list|)
return|;
elseif|else
if|if
condition|(
name|algorithm
operator|==
name|QSsl
operator|::
name|Ec
condition|)
return|return
name|QByteArrayLiteral
argument_list|(
literal|"-----BEGIN EC PRIVATE KEY-----"
argument_list|)
return|;
name|Q_UNREACHABLE
argument_list|()
expr_stmt|;
return|return
name|QByteArray
argument_list|()
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
if|if
condition|(
name|type
operator|==
name|QSsl
operator|::
name|PublicKey
condition|)
return|return
name|QByteArrayLiteral
argument_list|(
literal|"-----END PUBLIC KEY-----"
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
name|QByteArrayLiteral
argument_list|(
literal|"-----END RSA PRIVATE KEY-----"
argument_list|)
return|;
elseif|else
if|if
condition|(
name|algorithm
operator|==
name|QSsl
operator|::
name|Dsa
condition|)
return|return
name|QByteArrayLiteral
argument_list|(
literal|"-----END DSA PRIVATE KEY-----"
argument_list|)
return|;
elseif|else
if|if
condition|(
name|algorithm
operator|==
name|QSsl
operator|::
name|Ec
condition|)
return|return
name|QByteArrayLiteral
argument_list|(
literal|"-----END EC PRIVATE KEY-----"
argument_list|)
return|;
name|Q_UNREACHABLE
argument_list|()
expr_stmt|;
return|return
name|QByteArray
argument_list|()
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
parameter_list|,
specifier|const
name|QMap
argument_list|<
name|QByteArray
argument_list|,
name|QByteArray
argument_list|>
modifier|&
name|headers
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
name|QByteArray
name|extra
decl_stmt|;
if|if
condition|(
operator|!
name|headers
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|QMap
argument_list|<
name|QByteArray
argument_list|,
name|QByteArray
argument_list|>
operator|::
name|const_iterator
name|it
init|=
name|headers
operator|.
name|constEnd
argument_list|()
decl_stmt|;
do|do
block|{
operator|--
name|it
expr_stmt|;
name|extra
operator|+=
name|it
operator|.
name|key
argument_list|()
operator|+
literal|": "
operator|+
name|it
operator|.
name|value
argument_list|()
operator|+
literal|'\n'
expr_stmt|;
block|}
do|while
condition|(
name|it
operator|!=
name|headers
operator|.
name|constBegin
argument_list|()
condition|)
do|;
name|extra
operator|+=
literal|'\n'
expr_stmt|;
block|}
name|pem
operator|.
name|prepend
argument_list|(
name|pemHeader
argument_list|()
operator|+
literal|'\n'
operator|+
name|extra
argument_list|)
expr_stmt|;
name|pem
operator|.
name|append
argument_list|(
name|pemFooter
argument_list|()
operator|+
literal|'\n'
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
parameter_list|,
name|QMap
argument_list|<
name|QByteArray
argument_list|,
name|QByteArray
argument_list|>
modifier|*
name|headers
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
if|if
condition|(
name|der
operator|.
name|contains
argument_list|(
literal|"Proc-Type:"
argument_list|)
condition|)
block|{
comment|// taken from QHttpNetworkReplyPrivate::parseHeader
name|int
name|i
init|=
literal|0
decl_stmt|;
while|while
condition|(
name|i
operator|<
name|der
operator|.
name|count
argument_list|()
condition|)
block|{
name|int
name|j
init|=
name|der
operator|.
name|indexOf
argument_list|(
literal|':'
argument_list|,
name|i
argument_list|)
decl_stmt|;
comment|// field-name
if|if
condition|(
name|j
operator|==
operator|-
literal|1
condition|)
break|break;
specifier|const
name|QByteArray
name|field
init|=
name|der
operator|.
name|mid
argument_list|(
name|i
argument_list|,
name|j
operator|-
name|i
argument_list|)
operator|.
name|trimmed
argument_list|()
decl_stmt|;
name|j
operator|++
expr_stmt|;
comment|// any number of LWS is allowed before and after the value
name|QByteArray
name|value
decl_stmt|;
do|do
block|{
name|i
operator|=
name|der
operator|.
name|indexOf
argument_list|(
literal|'\n'
argument_list|,
name|j
argument_list|)
expr_stmt|;
if|if
condition|(
name|i
operator|==
operator|-
literal|1
condition|)
break|break;
if|if
condition|(
operator|!
name|value
operator|.
name|isEmpty
argument_list|()
condition|)
name|value
operator|+=
literal|' '
expr_stmt|;
comment|// check if we have CRLF or only LF
name|bool
name|hasCR
init|=
operator|(
name|i
operator|&&
name|der
index|[
name|i
operator|-
literal|1
index|]
operator|==
literal|'\r'
operator|)
decl_stmt|;
name|int
name|length
init|=
name|i
operator|-
operator|(
name|hasCR
condition|?
literal|1
else|:
literal|0
operator|)
operator|-
name|j
decl_stmt|;
name|value
operator|+=
name|der
operator|.
name|mid
argument_list|(
name|j
argument_list|,
name|length
argument_list|)
operator|.
name|trimmed
argument_list|()
expr_stmt|;
name|j
operator|=
operator|++
name|i
expr_stmt|;
block|}
do|while
condition|(
name|i
operator|<
name|der
operator|.
name|count
argument_list|()
operator|&&
operator|(
name|der
operator|.
name|at
argument_list|(
name|i
argument_list|)
operator|==
literal|' '
operator|||
name|der
operator|.
name|at
argument_list|(
name|i
argument_list|)
operator|==
literal|'\t'
operator|)
condition|)
do|;
if|if
condition|(
name|i
operator|==
operator|-
literal|1
condition|)
break|break;
comment|// something is wrong
name|headers
operator|->
name|insert
argument_list|(
name|field
argument_list|,
name|value
argument_list|)
expr_stmt|;
block|}
name|der
operator|=
name|der
operator|.
name|mid
argument_list|(
name|i
argument_list|)
expr_stmt|;
block|}
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
comment|/*!     Constructs a QSslKey by decoding the string in the byte array     \a encoded using a specified \a algorithm and \a encoding format.     \a type specifies whether the key is public or private.      If the key is encoded as PEM and encrypted, \a passPhrase is used     to decrypt it.      After construction, use isNull() to check if \a encoded contained     a valid key. */
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
if|if
condition|(
name|encoding
operator|==
name|QSsl
operator|::
name|Der
condition|)
name|d
operator|->
name|decodeDer
argument_list|(
name|encoded
argument_list|)
expr_stmt|;
else|else
name|d
operator|->
name|decodePem
argument_list|(
name|encoded
argument_list|,
name|passPhrase
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_comment
comment|/*!     Constructs a QSslKey by reading and decoding data from a     \a device using a specified \a algorithm and \a encoding format.     \a type specifies whether the key is public or private.      If the key is encoded as PEM and encrypted, \a passPhrase is used     to decrypt it.      After construction, use isNull() to check if \a device provided     a valid key. */
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
if|if
condition|(
name|encoding
operator|==
name|QSsl
operator|::
name|Der
condition|)
name|d
operator|->
name|decodeDer
argument_list|(
name|encoded
argument_list|)
expr_stmt|;
else|else
name|d
operator|->
name|decodePem
argument_list|(
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
ifndef|#
directive|ifndef
name|QT_NO_OPENSSL
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
else|#
directive|else
name|d
operator|->
name|opaque
operator|=
name|handle
expr_stmt|;
endif|#
directive|endif
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
comment|/*!     Returns \c true if this is a null key; otherwise false.      \sa clear() */
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
return|return
name|d
operator|->
name|length
argument_list|()
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
comment|/*!   Returns the key in DER encoding.    The \a passPhrase argument should be omitted as DER cannot be   encrypted. It will be removed in a future version of Qt. */
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
comment|// Encrypted DER is nonsense, see QTBUG-41038.
if|if
condition|(
name|d
operator|->
name|type
operator|==
name|QSsl
operator|::
name|PrivateKey
operator|&&
operator|!
name|passPhrase
operator|.
name|isEmpty
argument_list|()
condition|)
return|return
name|QByteArray
argument_list|()
return|;
ifndef|#
directive|ifndef
name|QT_NO_OPENSSL
name|QMap
argument_list|<
name|QByteArray
argument_list|,
name|QByteArray
argument_list|>
name|headers
decl_stmt|;
return|return
name|d
operator|->
name|derFromPem
argument_list|(
name|toPem
argument_list|(
name|passPhrase
argument_list|)
argument_list|,
operator|&
name|headers
argument_list|)
return|;
else|#
directive|else
return|return
name|d
operator|->
name|derData
return|;
endif|#
directive|endif
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
return|return
name|d
operator|->
name|toPem
argument_list|(
name|passPhrase
argument_list|)
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
return|return
name|d
operator|->
name|handle
argument_list|()
return|;
block|}
end_function
begin_comment
comment|/*!     Returns \c true if this key is equal to \a other; otherwise returns \c false. */
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
comment|/*! \fn bool QSslKey::operator!=(const QSslKey&other) const    Returns \c true if this key is not equal to key \a other; otherwise   returns \c false. */
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_DEBUG_STREAM
end_ifndef
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
name|QDebugStateSaver
name|saver
argument_list|(
name|debug
argument_list|)
decl_stmt|;
name|debug
operator|.
name|resetFormat
argument_list|()
operator|.
name|nospace
argument_list|()
expr_stmt|;
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
operator|(
operator|(
name|key
operator|.
name|algorithm
argument_list|()
operator|==
name|QSsl
operator|::
name|Dsa
operator|)
condition|?
literal|"DSA"
else|:
literal|"EC"
operator|)
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
