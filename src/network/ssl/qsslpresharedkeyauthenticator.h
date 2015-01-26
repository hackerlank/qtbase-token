begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2014 Governikus GmbH& Co. KG. ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtNetwork module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QSSLPRESHAREDKEYAUTHENTICATOR_H
end_ifndef
begin_define
DECL|macro|QSSLPRESHAREDKEYAUTHENTICATOR_H
define|#
directive|define
name|QSSLPRESHAREDKEYAUTHENTICATOR_H
end_define
begin_include
include|#
directive|include
file|<QtCore/QtGlobal>
end_include
begin_include
include|#
directive|include
file|<QtCore/QString>
end_include
begin_include
include|#
directive|include
file|<QtCore/QSharedDataPointer>
end_include
begin_include
include|#
directive|include
file|<QtCore/QMetaType>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QSslPreSharedKeyAuthenticatorPrivate
name|class
name|QSslPreSharedKeyAuthenticatorPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_NETWORK_EXPORT
name|QSslPreSharedKeyAuthenticator
block|{
name|public
label|:
name|QSslPreSharedKeyAuthenticator
argument_list|()
expr_stmt|;
operator|~
name|QSslPreSharedKeyAuthenticator
argument_list|()
expr_stmt|;
name|QSslPreSharedKeyAuthenticator
argument_list|(
specifier|const
name|QSslPreSharedKeyAuthenticator
operator|&
name|authenticator
argument_list|)
expr_stmt|;
name|QSslPreSharedKeyAuthenticator
modifier|&
name|operator
init|=
operator|(
specifier|const
name|QSslPreSharedKeyAuthenticator
operator|&
name|authenticator
operator|)
decl_stmt|;
ifdef|#
directive|ifdef
name|Q_COMPILER_RVALUE_REFS
specifier|inline
name|QSslPreSharedKeyAuthenticator
modifier|&
name|operator
init|=
operator|(
name|QSslPreSharedKeyAuthenticator
operator|&&
name|authenticator
operator|)
block|{
name|d
operator|.
name|swap
argument_list|(
name|authenticator
operator|.
name|d
argument_list|)
block|;
return|return
operator|*
name|this
return|;
block|}
endif|#
directive|endif
name|void
name|swap
parameter_list|(
name|QSslPreSharedKeyAuthenticator
modifier|&
name|authenticator
parameter_list|)
block|{
name|d
operator|.
name|swap
argument_list|(
name|authenticator
operator|.
name|d
argument_list|)
expr_stmt|;
block|}
name|QByteArray
name|identityHint
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setIdentity
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|identity
parameter_list|)
function_decl|;
name|QByteArray
name|identity
argument_list|()
specifier|const
expr_stmt|;
name|int
name|maximumIdentityLength
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setPreSharedKey
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|preSharedKey
parameter_list|)
function_decl|;
name|QByteArray
name|preSharedKey
argument_list|()
specifier|const
expr_stmt|;
name|int
name|maximumPreSharedKeyLength
argument_list|()
specifier|const
expr_stmt|;
name|private
label|:
name|friend
name|Q_NETWORK_EXPORT
name|bool
name|operator
operator|==
operator|(
specifier|const
name|QSslPreSharedKeyAuthenticator
operator|&
name|lhs
operator|,
specifier|const
name|QSslPreSharedKeyAuthenticator
operator|&
name|rhs
operator|)
expr_stmt|;
name|friend
name|class
name|QSslSocketBackendPrivate
decl_stmt|;
name|QSharedDataPointer
operator|<
name|QSslPreSharedKeyAuthenticatorPrivate
operator|>
name|d
expr_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_expr_stmt
DECL|function|operator
specifier|inline
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|QSslPreSharedKeyAuthenticator
operator|&
name|lhs
operator|,
specifier|const
name|QSslPreSharedKeyAuthenticator
operator|&
name|rhs
operator|)
block|{
return|return
operator|!
name|operator
operator|==
operator|(
name|lhs
operator|,
name|rhs
operator|)
return|;
block|}
end_expr_stmt
begin_macro
name|Q_DECLARE_SHARED
argument_list|(
argument|QSslPreSharedKeyAuthenticator
argument_list|)
end_macro
begin_decl_stmt
name|QT_END_NAMESPACE
name|Q_DECLARE_METATYPE
argument_list|(
name|QSslPreSharedKeyAuthenticator
argument_list|)
name|Q_DECLARE_METATYPE
argument_list|(
name|QSslPreSharedKeyAuthenticator
operator|*
argument_list|)
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QSSLPRESHAREDKEYAUTHENTICATOR_H
end_comment
end_unit