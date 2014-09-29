begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2014 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtNetwork module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia. For licensing terms and ** conditions see http://qt.digia.com/licensing. For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights. These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QSSLCIPHER_H
end_ifndef
begin_define
DECL|macro|QSSLCIPHER_H
define|#
directive|define
name|QSSLCIPHER_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qstring.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qscopedpointer.h>
end_include
begin_include
include|#
directive|include
file|<QtNetwork/qssl.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
ifndef|#
directive|ifndef
name|QT_NO_SSL
DECL|variable|QSslCipherPrivate
name|class
name|QSslCipherPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_NETWORK_EXPORT
name|QSslCipher
block|{
name|public
label|:
name|QSslCipher
argument_list|()
expr_stmt|;
name|explicit
name|QSslCipher
parameter_list|(
specifier|const
name|QString
modifier|&
name|name
parameter_list|)
function_decl|;
name|QSslCipher
argument_list|(
argument|const QString&name
argument_list|,
argument|QSsl::SslProtocol protocol
argument_list|)
empty_stmt|;
name|QSslCipher
argument_list|(
specifier|const
name|QSslCipher
operator|&
name|other
argument_list|)
expr_stmt|;
operator|~
name|QSslCipher
argument_list|()
expr_stmt|;
name|QSslCipher
modifier|&
name|operator
init|=
operator|(
specifier|const
name|QSslCipher
operator|&
name|other
operator|)
decl_stmt|;
specifier|inline
name|void
name|swap
parameter_list|(
name|QSslCipher
modifier|&
name|other
parameter_list|)
block|{
name|qSwap
argument_list|(
name|d
argument_list|,
name|other
operator|.
name|d
argument_list|)
expr_stmt|;
block|}
name|bool
name|operator
operator|==
operator|(
specifier|const
name|QSslCipher
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
name|QSslCipher
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
name|QString
name|name
argument_list|()
specifier|const
expr_stmt|;
name|int
name|supportedBits
argument_list|()
specifier|const
expr_stmt|;
name|int
name|usedBits
argument_list|()
specifier|const
expr_stmt|;
name|QString
name|keyExchangeMethod
argument_list|()
specifier|const
expr_stmt|;
name|QString
name|authenticationMethod
argument_list|()
specifier|const
expr_stmt|;
name|QString
name|encryptionMethod
argument_list|()
specifier|const
expr_stmt|;
name|QString
name|protocolString
argument_list|()
specifier|const
expr_stmt|;
name|QSsl
operator|::
name|SslProtocol
name|protocol
argument_list|()
specifier|const
expr_stmt|;
name|private
label|:
name|QScopedPointer
operator|<
name|QSslCipherPrivate
operator|>
name|d
expr_stmt|;
name|friend
name|class
name|QSslSocketBackendPrivate
decl_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_macro
name|Q_DECLARE_SHARED
argument_list|(
argument|QSslCipher
argument_list|)
end_macro
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_DEBUG_STREAM
end_ifndef
begin_decl_stmt
name|class
name|QDebug
decl_stmt|;
end_decl_stmt
begin_expr_stmt
DECL|variable|operator
name|Q_NETWORK_EXPORT
name|QDebug
name|operator
operator|<<
operator|(
name|QDebug
name|debug
operator|,
specifier|const
name|QSslCipher
operator|&
name|cipher
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
comment|// QT_NO_SSL
end_comment
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
end_unit
