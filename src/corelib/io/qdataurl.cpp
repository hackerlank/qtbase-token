begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** No Commercial Usage ** This file contains pre-release code and may not be distributed. ** You may use this file in accordance with the terms and conditions ** contained in the Technology Preview License Agreement accompanying ** this package. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights.  These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** If you have questions regarding the use of this file, please contact ** Nokia at qt-info@nokia.com. ** ** ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qplatformdefs.h"
end_include
begin_include
include|#
directive|include
file|"qurl.h"
end_include
begin_include
include|#
directive|include
file|"private/qdataurl_p.h"
end_include
begin_function
name|QT_BEGIN_NAMESPACE
comment|/*!     \internal      Decode a data: URL into its mimetype and payload. Returns a null string if     the URL could not be decoded. */
DECL|function|qDecodeDataUrl
name|Q_CORE_EXPORT
name|QPair
argument_list|<
name|QString
argument_list|,
name|QByteArray
argument_list|>
name|qDecodeDataUrl
parameter_list|(
specifier|const
name|QUrl
modifier|&
name|uri
parameter_list|)
block|{
name|QString
name|mimeType
decl_stmt|;
name|QByteArray
name|payload
decl_stmt|;
if|if
condition|(
name|uri
operator|.
name|scheme
argument_list|()
operator|==
name|QLatin1String
argument_list|(
literal|"data"
argument_list|)
operator|&&
name|uri
operator|.
name|host
argument_list|()
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|mimeType
operator|=
name|QLatin1String
argument_list|(
literal|"text/plain;charset=US-ASCII"
argument_list|)
expr_stmt|;
comment|// the following would have been the correct thing, but
comment|// reality often differs from the specification. People have
comment|// data: URIs with ? and #
comment|//QByteArray data = QByteArray::fromPercentEncoding(uri.encodedPath());
name|QByteArray
name|data
init|=
name|QByteArray
operator|::
name|fromPercentEncoding
argument_list|(
name|uri
operator|.
name|toEncoded
argument_list|()
argument_list|)
decl_stmt|;
comment|// remove the data: scheme
name|data
operator|.
name|remove
argument_list|(
literal|0
argument_list|,
literal|5
argument_list|)
expr_stmt|;
comment|// parse it:
name|int
name|pos
init|=
name|data
operator|.
name|indexOf
argument_list|(
literal|','
argument_list|)
decl_stmt|;
if|if
condition|(
name|pos
operator|!=
operator|-
literal|1
condition|)
block|{
name|payload
operator|=
name|data
operator|.
name|mid
argument_list|(
name|pos
operator|+
literal|1
argument_list|)
expr_stmt|;
name|data
operator|.
name|truncate
argument_list|(
name|pos
argument_list|)
expr_stmt|;
name|data
operator|=
name|data
operator|.
name|trimmed
argument_list|()
expr_stmt|;
comment|// find out if the payload is encoded in Base64
if|if
condition|(
name|data
operator|.
name|endsWith
argument_list|(
literal|";base64"
argument_list|)
condition|)
block|{
name|payload
operator|=
name|QByteArray
operator|::
name|fromBase64
argument_list|(
name|payload
argument_list|)
expr_stmt|;
name|data
operator|.
name|chop
argument_list|(
literal|7
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|data
operator|.
name|toLower
argument_list|()
operator|.
name|startsWith
argument_list|(
literal|"charset"
argument_list|)
condition|)
block|{
name|int
name|i
init|=
literal|7
decl_stmt|;
comment|// strlen("charset")
while|while
condition|(
name|data
operator|.
name|at
argument_list|(
name|i
argument_list|)
operator|==
literal|' '
condition|)
operator|++
name|i
expr_stmt|;
if|if
condition|(
name|data
operator|.
name|at
argument_list|(
name|i
argument_list|)
operator|==
literal|'='
condition|)
name|data
operator|.
name|prepend
argument_list|(
literal|"text/plain;"
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
operator|!
name|data
operator|.
name|isEmpty
argument_list|()
condition|)
name|mimeType
operator|=
name|QLatin1String
argument_list|(
name|data
operator|.
name|trimmed
argument_list|()
argument_list|)
expr_stmt|;
block|}
block|}
return|return
name|QPair
argument_list|<
name|QString
argument_list|,
name|QByteArray
argument_list|>
argument_list|(
name|mimeType
argument_list|,
name|payload
argument_list|)
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
