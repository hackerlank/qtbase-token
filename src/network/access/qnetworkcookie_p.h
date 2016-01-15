begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the QtNetwork module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QNETWORKCOOKIE_P_H
end_ifndef
begin_define
DECL|macro|QNETWORKCOOKIE_P_H
define|#
directive|define
name|QNETWORKCOOKIE_P_H
end_define
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
comment|// of the Network Access framework.  This header file may change from
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
file|"QtCore/qdatetime.h"
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
name|class
name|QNetworkCookiePrivate
range|:
name|public
name|QSharedData
block|{
name|public
operator|:
specifier|inline
name|QNetworkCookiePrivate
argument_list|()
operator|:
name|secure
argument_list|(
name|false
argument_list|)
block|,
name|httpOnly
argument_list|(
argument|false
argument_list|)
block|{ }
specifier|static
name|QList
operator|<
name|QNetworkCookie
operator|>
name|parseSetCookieHeaderLine
argument_list|(
specifier|const
name|QByteArray
operator|&
name|cookieString
argument_list|)
block|;
name|QDateTime
name|expirationDate
block|;
name|QString
name|domain
block|;
name|QString
name|path
block|;
name|QString
name|comment
block|;
name|QByteArray
name|name
block|;
name|QByteArray
name|value
block|;
name|bool
name|secure
block|;
name|bool
name|httpOnly
block|; }
decl_stmt|;
end_decl_stmt
begin_function
DECL|function|isLWS
specifier|static
specifier|inline
name|bool
name|isLWS
parameter_list|(
name|char
name|c
parameter_list|)
block|{
return|return
name|c
operator|==
literal|' '
operator|||
name|c
operator|==
literal|'\t'
operator|||
name|c
operator|==
literal|'\r'
operator|||
name|c
operator|==
literal|'\n'
return|;
block|}
end_function
begin_function
DECL|function|nextNonWhitespace
specifier|static
name|int
name|nextNonWhitespace
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|text
parameter_list|,
name|int
name|from
parameter_list|)
block|{
comment|// RFC 2616 defines linear whitespace as:
comment|//  LWS = [CRLF] 1*( SP | HT )
comment|// We ignore the fact that CRLF must come as a pair at this point
comment|// It's an invalid HTTP header if that happens.
while|while
condition|(
name|from
operator|<
name|text
operator|.
name|length
argument_list|()
condition|)
block|{
if|if
condition|(
name|isLWS
argument_list|(
name|text
operator|.
name|at
argument_list|(
name|from
argument_list|)
argument_list|)
condition|)
operator|++
name|from
expr_stmt|;
else|else
return|return
name|from
return|;
comment|// non-whitespace
block|}
comment|// reached the end
return|return
name|text
operator|.
name|length
argument_list|()
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
end_unit
