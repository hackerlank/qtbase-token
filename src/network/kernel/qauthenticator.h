begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtNetwork module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QAUTHENTICATOR_H
end_ifndef
begin_define
DECL|macro|QAUTHENTICATOR_H
define|#
directive|define
name|QAUTHENTICATOR_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qstring.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qvariant.h>
end_include
begin_decl_stmt
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
DECL|variable|QAuthenticatorPrivate
name|class
name|QAuthenticatorPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QUrl
name|class
name|QUrl
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_NETWORK_EXPORT
name|QAuthenticator
block|{
name|public
label|:
name|QAuthenticator
argument_list|()
expr_stmt|;
operator|~
name|QAuthenticator
argument_list|()
expr_stmt|;
name|QAuthenticator
argument_list|(
specifier|const
name|QAuthenticator
operator|&
name|other
argument_list|)
expr_stmt|;
name|QAuthenticator
modifier|&
name|operator
init|=
operator|(
specifier|const
name|QAuthenticator
operator|&
name|other
operator|)
decl_stmt|;
name|bool
name|operator
operator|==
operator|(
specifier|const
name|QAuthenticator
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
name|QAuthenticator
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
name|QString
name|user
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setUser
parameter_list|(
specifier|const
name|QString
modifier|&
name|user
parameter_list|)
function_decl|;
name|QString
name|password
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setPassword
parameter_list|(
specifier|const
name|QString
modifier|&
name|password
parameter_list|)
function_decl|;
name|QString
name|realm
argument_list|()
specifier|const
expr_stmt|;
name|QVariant
name|option
argument_list|(
specifier|const
name|QString
operator|&
name|opt
argument_list|)
decl|const
decl_stmt|;
name|QVariantHash
name|options
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setOption
parameter_list|(
specifier|const
name|QString
modifier|&
name|opt
parameter_list|,
specifier|const
name|QVariant
modifier|&
name|value
parameter_list|)
function_decl|;
name|bool
name|isNull
argument_list|()
specifier|const
expr_stmt|;
name|void
name|detach
parameter_list|()
function_decl|;
name|private
label|:
name|friend
name|class
name|QAuthenticatorPrivate
decl_stmt|;
name|QAuthenticatorPrivate
modifier|*
name|d
decl_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_expr_stmt
name|QT_END_NAMESPACE
name|QT_END_HEADER
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
end_unit
