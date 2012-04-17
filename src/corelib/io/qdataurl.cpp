begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
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
name|bool
name|qDecodeDataUrl
parameter_list|(
specifier|const
name|QUrl
modifier|&
name|uri
parameter_list|,
name|QString
modifier|&
name|mimeType
parameter_list|,
name|QByteArray
modifier|&
name|payload
parameter_list|)
block|{
if|if
condition|(
name|uri
operator|.
name|scheme
argument_list|()
operator|!=
name|QLatin1String
argument_list|(
literal|"data"
argument_list|)
operator|||
operator|!
name|uri
operator|.
name|host
argument_list|()
operator|.
name|isEmpty
argument_list|()
condition|)
return|return
literal|false
return|;
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
comment|//QByteArray data = QByteArray::fromPercentEncoding(uri.path(QUrl::PrettyDecoded).toLatin1());
name|QByteArray
name|data
init|=
name|QByteArray
operator|::
name|fromPercentEncoding
argument_list|(
name|uri
operator|.
name|url
argument_list|(
name|QUrl
operator|::
name|PrettyDecoded
operator||
name|QUrl
operator|::
name|RemoveScheme
argument_list|)
operator|.
name|toLatin1
argument_list|()
argument_list|)
decl_stmt|;
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
return|return
literal|true
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
