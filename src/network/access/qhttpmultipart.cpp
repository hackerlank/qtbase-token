begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtNetwork module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qhttpmultipart.h"
end_include
begin_include
include|#
directive|include
file|"qhttpmultipart_p.h"
end_include
begin_include
include|#
directive|include
file|"QtCore/qdatetime.h"
end_include
begin_comment
comment|// for initializing the random number generator with QTime
end_comment
begin_include
include|#
directive|include
file|"QtCore/qmutex.h"
end_include
begin_include
include|#
directive|include
file|"QtCore/qthreadstorage.h"
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_comment
comment|/*!     \class QHttpPart     \brief The QHttpPart class holds a body part to be used inside a            HTTP multipart MIME message.     \since 4.8      \ingroup network     \inmodule QtNetwork      The QHttpPart class holds a body part to be used inside a HTTP     multipart MIME message (which is represented by the QHttpMultiPart class).     A QHttpPart consists of a header block     and a data block, which are separated by each other by two     consecutive new lines. An example for one part would be:      \snippet code/src_network_access_qhttppart.cpp 0      For setting headers, use setHeader() and setRawHeader(), which behave     exactly like QNetworkRequest::setHeader() and QNetworkRequest::setRawHeader().      For reading small pieces of data, use setBody(); for larger data blocks     like e.g. images, use setBodyDevice(). The latter method saves memory by     not copying the data internally, but reading directly from the device.     This means that the device must be opened and readable at the moment when     the multipart message containing the body part is sent on the network via     QNetworkAccessManager::post().      To construct a QHttpPart with a small body, consider the following snippet     (this produces the data shown in the example above):      \snippet code/src_network_access_qhttppart.cpp 1      To construct a QHttpPart reading from a device (e.g. a file), the following     can be applied:      \snippet code/src_network_access_qhttppart.cpp 2      Be aware that QHttpPart does not take ownership of the device when set, so     it is the developer's responsibility to destroy it when it is not needed anymore.     A good idea might be to set the multipart message as parent object for the device,     as documented at the documentation for QHttpMultiPart.      \sa QHttpMultiPart, QNetworkAccessManager */
end_comment
begin_comment
comment|/*!     Constructs an empty QHttpPart object. */
end_comment
begin_constructor
DECL|function|QHttpPart
name|QHttpPart
operator|::
name|QHttpPart
parameter_list|()
member_init_list|:
name|d
argument_list|(
operator|new
name|QHttpPartPrivate
argument_list|)
block|{ }
end_constructor
begin_comment
comment|/*!     Creates a copy of \a other. */
end_comment
begin_constructor
DECL|function|QHttpPart
name|QHttpPart
operator|::
name|QHttpPart
parameter_list|(
specifier|const
name|QHttpPart
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
comment|/*!     Destroys this QHttpPart. */
end_comment
begin_destructor
DECL|function|~QHttpPart
name|QHttpPart
operator|::
name|~
name|QHttpPart
parameter_list|()
block|{
name|d
operator|=
literal|0
expr_stmt|;
block|}
end_destructor
begin_comment
comment|/*!     Creates a copy of \a other. */
end_comment
begin_function
DECL|function|operator =
name|QHttpPart
modifier|&
name|QHttpPart
operator|::
name|operator
name|=
parameter_list|(
specifier|const
name|QHttpPart
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
comment|/*!     Returns true if this object is the same as \a other (i.e., if they     have the same headers and body).      \sa operator!=() */
end_comment
begin_function
DECL|function|operator ==
name|bool
name|QHttpPart
operator|::
name|operator
name|==
parameter_list|(
specifier|const
name|QHttpPart
modifier|&
name|other
parameter_list|)
specifier|const
block|{
return|return
name|d
operator|==
name|other
operator|.
name|d
operator|||
operator|*
name|d
operator|==
operator|*
name|other
operator|.
name|d
return|;
block|}
end_function
begin_comment
comment|/*!     \fn bool QHttpPart::operator!=(const QHttpPart&other) const      Returns true if this object is not the same as \a other.      \sa operator==() */
end_comment
begin_comment
comment|/*!     Sets the value of the known header \a header to be \a value,     overriding any previously set headers.      \sa QNetworkRequest::KnownHeaders, setRawHeader(), QNetworkRequest::setHeader() */
end_comment
begin_function
DECL|function|setHeader
name|void
name|QHttpPart
operator|::
name|setHeader
parameter_list|(
name|QNetworkRequest
operator|::
name|KnownHeaders
name|header
parameter_list|,
specifier|const
name|QVariant
modifier|&
name|value
parameter_list|)
block|{
name|d
operator|->
name|setCookedHeader
argument_list|(
name|header
argument_list|,
name|value
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     Sets the header \a headerName to be of value \a headerValue. If \a     headerName corresponds to a known header (see     QNetworkRequest::KnownHeaders), the raw format will be parsed and     the corresponding "cooked" header will be set as well.      Note: setting the same header twice overrides the previous     setting. To accomplish the behaviour of multiple HTTP headers of     the same name, you should concatenate the two values, separating     them with a comma (",") and set one single raw header.      \sa QNetworkRequest::KnownHeaders, setHeader(), QNetworkRequest::setRawHeader() */
end_comment
begin_function
DECL|function|setRawHeader
name|void
name|QHttpPart
operator|::
name|setRawHeader
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|headerName
parameter_list|,
specifier|const
name|QByteArray
modifier|&
name|headerValue
parameter_list|)
block|{
name|d
operator|->
name|setRawHeader
argument_list|(
name|headerName
argument_list|,
name|headerValue
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     Sets the body of this MIME part to \a body. The body set with this method     will be used unless the device is set via setBodyDevice(). For a large     amount of data (e.g. an image), use setBodyDevice(), which will not copy     the data internally.      \sa setBodyDevice() */
end_comment
begin_function
DECL|function|setBody
name|void
name|QHttpPart
operator|::
name|setBody
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|body
parameter_list|)
block|{
name|d
operator|->
name|setBody
argument_list|(
name|body
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!   Sets the device to read the content from to \a device. For large amounts of data   this method should be preferred over setBody(),   because the content is not copied when using this method, but read   directly from the device.   \a device must be open and readable. QHttpPart does not take ownership   of \a device, i.e. the device must be closed and destroyed if necessary.   if \a device is sequential (e.g. sockets, but not files),   QNetworkAccessManager::post() should be called after \a device has   emitted finished().   For unsetting the device and using data set via setBody(), use   "setBodyDevice(0)".    \sa setBody(), QNetworkAccessManager::post()   */
end_comment
begin_function
DECL|function|setBodyDevice
name|void
name|QHttpPart
operator|::
name|setBodyDevice
parameter_list|(
name|QIODevice
modifier|*
name|device
parameter_list|)
block|{
name|d
operator|->
name|setBodyDevice
argument_list|(
name|device
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     \class QHttpMultiPart     \brief The QHttpMultiPart class resembles a MIME multipart message to be sent over HTTP.     \since 4.8      \ingroup network     \inmodule QtNetwork      The QHttpMultiPart resembles a MIME multipart message, as described in RFC 2046,     which is to be sent over HTTP.     A multipart message consists of an arbitrary number of body parts (see QHttpPart),     which are separated by a unique boundary. The boundary of the QHttpMultiPart is     constructed with the string "boundary_.oOo._" followed by random characters,     and provides enough uniqueness to make sure it does not occur inside the parts itself.     If desired, the boundary can still be set via setBoundary().      As an example, consider the following code snippet, which constructs a multipart     message containing a text part followed by an image part:      \snippet code/src_network_access_qhttpmultipart.cpp 0      \sa QHttpPart, QNetworkAccessManager::post() */
end_comment
begin_comment
comment|/*!     \enum QHttpMultiPart::ContentType      List of known content types for a multipart subtype as described     in RFC 2046 and others.      \value MixedType    corresponds to the "multipart/mixed" subtype,     meaning the body parts are independent of each other, as described     in RFC 2046.      \value RelatedType  corresponds to the "multipart/related" subtype,     meaning the body parts are related to each other, as described in RFC 2387.      \value FormDataType       corresponds to the "multipart/form-data"     subtype, meaning the body parts contain form elements, as described in RFC 2388.      \value AlternativeType   corresponds to the "multipart/alternative"     subtype, meaning the body parts are alternative representations of     the same information, as described in RFC 2046.      \sa setContentType() */
end_comment
begin_comment
comment|/*!     Constructs a QHttpMultiPart with content type MixedType and sets     \a parent as the parent object.      \sa QHttpMultiPart::ContentType */
end_comment
begin_constructor
DECL|function|QHttpMultiPart
name|QHttpMultiPart
operator|::
name|QHttpMultiPart
parameter_list|(
name|QObject
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QObject
argument_list|(
operator|*
operator|new
name|QHttpMultiPartPrivate
argument_list|,
name|parent
argument_list|)
block|{
name|Q_D
argument_list|(
name|QHttpMultiPart
argument_list|)
expr_stmt|;
name|d
operator|->
name|contentType
operator|=
name|MixedType
expr_stmt|;
block|}
end_constructor
begin_comment
comment|/*!     Constructs a QHttpMultiPart with content type \a contentType and     sets parent as the parent object.      \sa QHttpMultiPart::ContentType */
end_comment
begin_constructor
DECL|function|QHttpMultiPart
name|QHttpMultiPart
operator|::
name|QHttpMultiPart
parameter_list|(
name|QHttpMultiPart
operator|::
name|ContentType
name|contentType
parameter_list|,
name|QObject
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QObject
argument_list|(
operator|*
operator|new
name|QHttpMultiPartPrivate
argument_list|,
name|parent
argument_list|)
block|{
name|Q_D
argument_list|(
name|QHttpMultiPart
argument_list|)
expr_stmt|;
name|d
operator|->
name|contentType
operator|=
name|contentType
expr_stmt|;
block|}
end_constructor
begin_comment
comment|/*!     Destroys the multipart. */
end_comment
begin_destructor
DECL|function|~QHttpMultiPart
name|QHttpMultiPart
operator|::
name|~
name|QHttpMultiPart
parameter_list|()
block|{ }
end_destructor
begin_comment
comment|/*!     Appends \a httpPart to this multipart. */
end_comment
begin_function
DECL|function|append
name|void
name|QHttpMultiPart
operator|::
name|append
parameter_list|(
specifier|const
name|QHttpPart
modifier|&
name|httpPart
parameter_list|)
block|{
name|d_func
argument_list|()
operator|->
name|parts
operator|.
name|append
argument_list|(
name|httpPart
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     Sets the content type to \a contentType. The content type will be used     in the HTTP header section when sending the multipart message via     QNetworkAccessManager::post().     In case you want to use a multipart subtype not contained in     QHttpMultiPart::ContentType,     you can add the "Content-Type" header field to the QNetworkRequest     by hand, and then use this request together with the multipart     message for posting.      \sa QHttpMultiPart::ContentType, QNetworkAccessManager::post() */
end_comment
begin_function
DECL|function|setContentType
name|void
name|QHttpMultiPart
operator|::
name|setContentType
parameter_list|(
name|QHttpMultiPart
operator|::
name|ContentType
name|contentType
parameter_list|)
block|{
name|d_func
argument_list|()
operator|->
name|contentType
operator|=
name|contentType
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     returns the boundary.      \sa setBoundary() */
end_comment
begin_function
DECL|function|boundary
name|QByteArray
name|QHttpMultiPart
operator|::
name|boundary
parameter_list|()
specifier|const
block|{
return|return
name|d_func
argument_list|()
operator|->
name|boundary
return|;
block|}
end_function
begin_comment
comment|/*!     Sets the boundary to \a boundary.      Usually, you do not need to generate a boundary yourself; upon construction     the boundary is initiated with the string "boundary_.oOo._" followed by random     characters, and provides enough uniqueness to make sure it does not occur     inside the parts itself.      \sa boundary() */
end_comment
begin_function
DECL|function|setBoundary
name|void
name|QHttpMultiPart
operator|::
name|setBoundary
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|boundary
parameter_list|)
block|{
name|d_func
argument_list|()
operator|->
name|boundary
operator|=
name|boundary
expr_stmt|;
block|}
end_function
begin_comment
comment|// ------------------------------------------------------------------
end_comment
begin_comment
comment|// ----------- implementations of private classes: ------------------
end_comment
begin_comment
comment|// ------------------------------------------------------------------
end_comment
begin_function
DECL|function|bytesAvailable
name|qint64
name|QHttpPartPrivate
operator|::
name|bytesAvailable
parameter_list|()
specifier|const
block|{
name|checkHeaderCreated
argument_list|()
expr_stmt|;
name|qint64
name|bytesAvailable
init|=
name|header
operator|.
name|count
argument_list|()
decl_stmt|;
if|if
condition|(
name|bodyDevice
condition|)
block|{
name|bytesAvailable
operator|+=
name|bodyDevice
operator|->
name|bytesAvailable
argument_list|()
operator|-
name|readPointer
expr_stmt|;
block|}
else|else
block|{
name|bytesAvailable
operator|+=
name|body
operator|.
name|count
argument_list|()
operator|-
name|readPointer
expr_stmt|;
block|}
comment|// the device might have closed etc., so make sure we do not return a negative value
return|return
name|qMax
argument_list|(
name|bytesAvailable
argument_list|,
operator|(
name|qint64
operator|)
literal|0
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|readData
name|qint64
name|QHttpPartPrivate
operator|::
name|readData
parameter_list|(
name|char
modifier|*
name|data
parameter_list|,
name|qint64
name|maxSize
parameter_list|)
block|{
name|checkHeaderCreated
argument_list|()
expr_stmt|;
name|qint64
name|bytesRead
init|=
literal|0
decl_stmt|;
name|qint64
name|headerDataCount
init|=
name|header
operator|.
name|count
argument_list|()
decl_stmt|;
comment|// read header if it has not been read yet
if|if
condition|(
name|readPointer
operator|<
name|headerDataCount
condition|)
block|{
name|bytesRead
operator|=
name|qMin
argument_list|(
name|headerDataCount
operator|-
name|readPointer
argument_list|,
name|maxSize
argument_list|)
expr_stmt|;
specifier|const
name|char
modifier|*
name|headerData
init|=
name|header
operator|.
name|constData
argument_list|()
decl_stmt|;
name|memcpy
argument_list|(
name|data
argument_list|,
name|headerData
operator|+
name|readPointer
argument_list|,
name|bytesRead
argument_list|)
expr_stmt|;
name|readPointer
operator|+=
name|bytesRead
expr_stmt|;
block|}
comment|// read content if there is still space
if|if
condition|(
name|bytesRead
operator|<
name|maxSize
condition|)
block|{
if|if
condition|(
name|bodyDevice
condition|)
block|{
name|qint64
name|dataBytesRead
init|=
name|bodyDevice
operator|->
name|read
argument_list|(
name|data
operator|+
name|bytesRead
argument_list|,
name|maxSize
operator|-
name|bytesRead
argument_list|)
decl_stmt|;
if|if
condition|(
name|dataBytesRead
operator|==
operator|-
literal|1
condition|)
return|return
operator|-
literal|1
return|;
name|bytesRead
operator|+=
name|dataBytesRead
expr_stmt|;
name|readPointer
operator|+=
name|dataBytesRead
expr_stmt|;
block|}
else|else
block|{
name|qint64
name|contentBytesRead
init|=
name|qMin
argument_list|(
name|body
operator|.
name|count
argument_list|()
operator|-
name|readPointer
operator|+
name|headerDataCount
argument_list|,
name|maxSize
operator|-
name|bytesRead
argument_list|)
decl_stmt|;
specifier|const
name|char
modifier|*
name|contentData
init|=
name|body
operator|.
name|constData
argument_list|()
decl_stmt|;
comment|// if this method is called several times, we need to find the
comment|// right offset in the content ourselves:
name|memcpy
argument_list|(
name|data
operator|+
name|bytesRead
argument_list|,
name|contentData
operator|+
name|readPointer
operator|-
name|headerDataCount
argument_list|,
name|contentBytesRead
argument_list|)
expr_stmt|;
name|bytesRead
operator|+=
name|contentBytesRead
expr_stmt|;
name|readPointer
operator|+=
name|contentBytesRead
expr_stmt|;
block|}
block|}
return|return
name|bytesRead
return|;
block|}
end_function
begin_function
DECL|function|size
name|qint64
name|QHttpPartPrivate
operator|::
name|size
parameter_list|()
specifier|const
block|{
name|checkHeaderCreated
argument_list|()
expr_stmt|;
name|qint64
name|size
init|=
name|header
operator|.
name|count
argument_list|()
decl_stmt|;
if|if
condition|(
name|bodyDevice
condition|)
block|{
name|size
operator|+=
name|bodyDevice
operator|->
name|size
argument_list|()
expr_stmt|;
block|}
else|else
block|{
name|size
operator|+=
name|body
operator|.
name|count
argument_list|()
expr_stmt|;
block|}
return|return
name|size
return|;
block|}
end_function
begin_function
DECL|function|reset
name|bool
name|QHttpPartPrivate
operator|::
name|reset
parameter_list|()
block|{
name|bool
name|ret
init|=
literal|true
decl_stmt|;
if|if
condition|(
name|bodyDevice
condition|)
if|if
condition|(
operator|!
name|bodyDevice
operator|->
name|reset
argument_list|()
condition|)
name|ret
operator|=
literal|false
expr_stmt|;
name|readPointer
operator|=
literal|0
expr_stmt|;
return|return
name|ret
return|;
block|}
end_function
begin_function
DECL|function|checkHeaderCreated
name|void
name|QHttpPartPrivate
operator|::
name|checkHeaderCreated
parameter_list|()
specifier|const
block|{
if|if
condition|(
operator|!
name|headerCreated
condition|)
block|{
comment|// copied from QHttpNetworkRequestPrivate::header() and adapted
name|QList
argument_list|<
name|QPair
argument_list|<
name|QByteArray
argument_list|,
name|QByteArray
argument_list|>
argument_list|>
name|fields
init|=
name|allRawHeaders
argument_list|()
decl_stmt|;
name|QList
argument_list|<
name|QPair
argument_list|<
name|QByteArray
argument_list|,
name|QByteArray
argument_list|>
argument_list|>
operator|::
name|const_iterator
name|it
init|=
name|fields
operator|.
name|constBegin
argument_list|()
decl_stmt|;
for|for
control|(
init|;
name|it
operator|!=
name|fields
operator|.
name|constEnd
argument_list|()
condition|;
operator|++
name|it
control|)
name|header
operator|+=
name|it
operator|->
name|first
operator|+
literal|": "
operator|+
name|it
operator|->
name|second
operator|+
literal|"\r\n"
expr_stmt|;
name|header
operator|+=
literal|"\r\n"
expr_stmt|;
name|headerCreated
operator|=
literal|true
expr_stmt|;
block|}
block|}
end_function
begin_expr_stmt
name|Q_GLOBAL_STATIC
argument_list|(
name|QThreadStorage
argument_list|<
name|bool
operator|*
argument_list|>
argument_list|,
name|seedCreatedStorage
argument_list|)
expr_stmt|;
end_expr_stmt
begin_constructor
DECL|function|QHttpMultiPartPrivate
name|QHttpMultiPartPrivate
operator|::
name|QHttpMultiPartPrivate
parameter_list|()
member_init_list|:
name|contentType
argument_list|(
name|QHttpMultiPart
operator|::
name|MixedType
argument_list|)
member_init_list|,
name|device
argument_list|(
operator|new
name|QHttpMultiPartIODevice
argument_list|(
name|this
argument_list|)
argument_list|)
block|{
if|if
condition|(
operator|!
name|seedCreatedStorage
argument_list|()
operator|->
name|hasLocalData
argument_list|()
condition|)
block|{
name|qsrand
argument_list|(
name|QTime
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
operator|.
name|msecsTo
argument_list|(
name|QTime
operator|::
name|currentTime
argument_list|()
argument_list|)
operator|^
cast|reinterpret_cast
argument_list|<
name|quintptr
argument_list|>
argument_list|(
name|this
argument_list|)
argument_list|)
expr_stmt|;
name|seedCreatedStorage
argument_list|()
operator|->
name|setLocalData
argument_list|(
operator|new
name|bool
argument_list|(
literal|true
argument_list|)
argument_list|)
expr_stmt|;
block|}
name|boundary
operator|=
name|QByteArray
argument_list|(
literal|"boundary_.oOo._"
argument_list|)
operator|+
name|QByteArray
operator|::
name|number
argument_list|(
name|qrand
argument_list|()
argument_list|)
operator|.
name|toBase64
argument_list|()
operator|+
name|QByteArray
operator|::
name|number
argument_list|(
name|qrand
argument_list|()
argument_list|)
operator|.
name|toBase64
argument_list|()
operator|+
name|QByteArray
operator|::
name|number
argument_list|(
name|qrand
argument_list|()
argument_list|)
operator|.
name|toBase64
argument_list|()
expr_stmt|;
comment|// boundary must not be longer than 70 characters, see RFC 2046, section 5.1.1
if|if
condition|(
name|boundary
operator|.
name|count
argument_list|()
operator|>
literal|70
condition|)
name|boundary
operator|=
name|boundary
operator|.
name|left
argument_list|(
literal|70
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_function
DECL|function|size
name|qint64
name|QHttpMultiPartIODevice
operator|::
name|size
parameter_list|()
specifier|const
block|{
comment|// if not done yet, we calculate the size and the offsets of each part,
comment|// including boundary (needed later in readData)
if|if
condition|(
name|deviceSize
operator|==
operator|-
literal|1
condition|)
block|{
name|qint64
name|currentSize
init|=
literal|0
decl_stmt|;
name|qint64
name|boundaryCount
init|=
name|multiPart
operator|->
name|boundary
operator|.
name|count
argument_list|()
decl_stmt|;
for|for
control|(
name|int
name|a
init|=
literal|0
init|;
name|a
operator|<
name|multiPart
operator|->
name|parts
operator|.
name|count
argument_list|()
condition|;
name|a
operator|++
control|)
block|{
name|partOffsets
operator|.
name|append
argument_list|(
name|currentSize
argument_list|)
expr_stmt|;
comment|// 4 additional bytes for the "--" before and the "\r\n" after the boundary,
comment|// and 2 bytes for the "\r\n" after the content
name|currentSize
operator|+=
name|boundaryCount
operator|+
literal|4
operator|+
name|multiPart
operator|->
name|parts
operator|.
name|at
argument_list|(
name|a
argument_list|)
operator|.
name|d
operator|->
name|size
argument_list|()
operator|+
literal|2
expr_stmt|;
block|}
name|currentSize
operator|+=
name|boundaryCount
operator|+
literal|6
expr_stmt|;
comment|// size for ending boundary, 2 beginning and ending dashes and "\r\n"
name|deviceSize
operator|=
name|currentSize
expr_stmt|;
block|}
return|return
name|deviceSize
return|;
block|}
end_function
begin_function
DECL|function|isSequential
name|bool
name|QHttpMultiPartIODevice
operator|::
name|isSequential
parameter_list|()
specifier|const
block|{
for|for
control|(
name|int
name|a
init|=
literal|0
init|;
name|a
operator|<
name|multiPart
operator|->
name|parts
operator|.
name|count
argument_list|()
condition|;
name|a
operator|++
control|)
block|{
name|QIODevice
modifier|*
name|device
init|=
name|multiPart
operator|->
name|parts
operator|.
name|at
argument_list|(
name|a
argument_list|)
operator|.
name|d
operator|->
name|bodyDevice
decl_stmt|;
comment|// we are sequential if any of the bodyDevices of our parts are sequential;
comment|// when reading from a byte array, we are not sequential
if|if
condition|(
name|device
operator|&&
name|device
operator|->
name|isSequential
argument_list|()
condition|)
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
DECL|function|reset
name|bool
name|QHttpMultiPartIODevice
operator|::
name|reset
parameter_list|()
block|{
for|for
control|(
name|int
name|a
init|=
literal|0
init|;
name|a
operator|<
name|multiPart
operator|->
name|parts
operator|.
name|count
argument_list|()
condition|;
name|a
operator|++
control|)
if|if
condition|(
operator|!
name|multiPart
operator|->
name|parts
index|[
name|a
index|]
operator|.
name|d
operator|->
name|reset
argument_list|()
condition|)
return|return
literal|false
return|;
return|return
literal|true
return|;
block|}
end_function
begin_function
DECL|function|readData
name|qint64
name|QHttpMultiPartIODevice
operator|::
name|readData
parameter_list|(
name|char
modifier|*
name|data
parameter_list|,
name|qint64
name|maxSize
parameter_list|)
block|{
name|qint64
name|bytesRead
init|=
literal|0
decl_stmt|,
name|index
init|=
literal|0
decl_stmt|;
comment|// skip the parts we have already read
while|while
condition|(
name|index
operator|<
name|multiPart
operator|->
name|parts
operator|.
name|count
argument_list|()
operator|&&
name|readPointer
operator|>=
name|partOffsets
operator|.
name|at
argument_list|(
name|index
argument_list|)
operator|+
name|multiPart
operator|->
name|parts
operator|.
name|at
argument_list|(
name|index
argument_list|)
operator|.
name|d
operator|->
name|size
argument_list|()
condition|)
name|index
operator|++
expr_stmt|;
comment|// read the data
while|while
condition|(
name|bytesRead
operator|<
name|maxSize
operator|&&
name|index
operator|<
name|multiPart
operator|->
name|parts
operator|.
name|count
argument_list|()
condition|)
block|{
comment|// check whether we need to read the boundary of the current part
name|QByteArray
name|boundaryData
init|=
literal|"--"
operator|+
name|multiPart
operator|->
name|boundary
operator|+
literal|"\r\n"
decl_stmt|;
name|qint64
name|boundaryCount
init|=
name|boundaryData
operator|.
name|count
argument_list|()
decl_stmt|;
name|qint64
name|partIndex
init|=
name|readPointer
operator|-
name|partOffsets
operator|.
name|at
argument_list|(
name|index
argument_list|)
decl_stmt|;
if|if
condition|(
name|partIndex
operator|<
name|boundaryCount
condition|)
block|{
name|qint64
name|boundaryBytesRead
init|=
name|qMin
argument_list|(
name|boundaryCount
operator|-
name|partIndex
argument_list|,
name|maxSize
operator|-
name|bytesRead
argument_list|)
decl_stmt|;
name|memcpy
argument_list|(
name|data
operator|+
name|bytesRead
argument_list|,
name|boundaryData
operator|.
name|constData
argument_list|()
operator|+
name|partIndex
argument_list|,
name|boundaryBytesRead
argument_list|)
expr_stmt|;
name|bytesRead
operator|+=
name|boundaryBytesRead
expr_stmt|;
name|readPointer
operator|+=
name|boundaryBytesRead
expr_stmt|;
name|partIndex
operator|+=
name|boundaryBytesRead
expr_stmt|;
block|}
comment|// check whether we need to read the data of the current part
if|if
condition|(
name|bytesRead
operator|<
name|maxSize
operator|&&
name|partIndex
operator|>=
name|boundaryCount
operator|&&
name|partIndex
operator|<
name|boundaryCount
operator|+
name|multiPart
operator|->
name|parts
operator|.
name|at
argument_list|(
name|index
argument_list|)
operator|.
name|d
operator|->
name|size
argument_list|()
condition|)
block|{
name|qint64
name|dataBytesRead
init|=
name|multiPart
operator|->
name|parts
index|[
name|index
index|]
operator|.
name|d
operator|->
name|readData
argument_list|(
name|data
operator|+
name|bytesRead
argument_list|,
name|maxSize
operator|-
name|bytesRead
argument_list|)
decl_stmt|;
if|if
condition|(
name|dataBytesRead
operator|==
operator|-
literal|1
condition|)
return|return
operator|-
literal|1
return|;
name|bytesRead
operator|+=
name|dataBytesRead
expr_stmt|;
name|readPointer
operator|+=
name|dataBytesRead
expr_stmt|;
name|partIndex
operator|+=
name|dataBytesRead
expr_stmt|;
block|}
comment|// check whether we need to read the ending CRLF of the current part
if|if
condition|(
name|bytesRead
operator|<
name|maxSize
operator|&&
name|partIndex
operator|>=
name|boundaryCount
operator|+
name|multiPart
operator|->
name|parts
operator|.
name|at
argument_list|(
name|index
argument_list|)
operator|.
name|d
operator|->
name|size
argument_list|()
condition|)
block|{
if|if
condition|(
name|bytesRead
operator|==
name|maxSize
operator|-
literal|1
condition|)
return|return
name|bytesRead
return|;
name|memcpy
argument_list|(
name|data
operator|+
name|bytesRead
argument_list|,
literal|"\r\n"
argument_list|,
literal|2
argument_list|)
expr_stmt|;
name|bytesRead
operator|+=
literal|2
expr_stmt|;
name|readPointer
operator|+=
literal|2
expr_stmt|;
name|index
operator|++
expr_stmt|;
block|}
block|}
comment|// check whether we need to return the final boundary
if|if
condition|(
name|bytesRead
operator|<
name|maxSize
operator|&&
name|index
operator|==
name|multiPart
operator|->
name|parts
operator|.
name|count
argument_list|()
condition|)
block|{
name|QByteArray
name|finalBoundary
init|=
literal|"--"
operator|+
name|multiPart
operator|->
name|boundary
operator|+
literal|"--\r\n"
decl_stmt|;
name|qint64
name|boundaryIndex
init|=
name|readPointer
operator|+
name|finalBoundary
operator|.
name|count
argument_list|()
operator|-
name|size
argument_list|()
decl_stmt|;
name|qint64
name|lastBoundaryBytesRead
init|=
name|qMin
argument_list|(
name|finalBoundary
operator|.
name|count
argument_list|()
operator|-
name|boundaryIndex
argument_list|,
name|maxSize
operator|-
name|bytesRead
argument_list|)
decl_stmt|;
name|memcpy
argument_list|(
name|data
operator|+
name|bytesRead
argument_list|,
name|finalBoundary
operator|.
name|constData
argument_list|()
operator|+
name|boundaryIndex
argument_list|,
name|lastBoundaryBytesRead
argument_list|)
expr_stmt|;
name|bytesRead
operator|+=
name|lastBoundaryBytesRead
expr_stmt|;
name|readPointer
operator|+=
name|lastBoundaryBytesRead
expr_stmt|;
block|}
return|return
name|bytesRead
return|;
block|}
end_function
begin_function
DECL|function|writeData
name|qint64
name|QHttpMultiPartIODevice
operator|::
name|writeData
parameter_list|(
specifier|const
name|char
modifier|*
name|data
parameter_list|,
name|qint64
name|maxSize
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
name|data
argument_list|)
expr_stmt|;
name|Q_UNUSED
argument_list|(
name|maxSize
argument_list|)
expr_stmt|;
return|return
operator|-
literal|1
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
