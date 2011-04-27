begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtNetwork module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** No Commercial Usage ** This file contains pre-release code and may not be distributed. ** You may use this file in accordance with the terms and conditions ** contained in the Technology Preview License Agreement accompanying ** this package. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights.  These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** If you have questions regarding the use of this file, please contact ** Nokia at qt-info@nokia.com. ** ** ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
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
begin_function
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
name|QT_MODULE
parameter_list|(
name|Network
parameter_list|)
name|class
name|QAuthenticatorPrivate
decl_stmt|;
DECL|variable|QUrl
name|class
name|QUrl
decl_stmt|;
name|class
name|Q_NETWORK_EXPORT
name|QAuthenticator
decl_stmt|{ public:     QAuthenticator(
end_function
begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt
begin_expr_stmt
operator|~
name|QAuthenticator
argument_list|()
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|QAuthenticator
argument_list|(
specifier|const
name|QAuthenticator
operator|&
name|other
argument_list|)
expr_stmt|;
end_expr_stmt
begin_decl_stmt
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
end_decl_stmt
begin_expr_stmt
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
end_expr_stmt
begin_expr_stmt
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
end_expr_stmt
begin_expr_stmt
name|QString
name|user
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_function_decl
name|void
name|setUser
parameter_list|(
specifier|const
name|QString
modifier|&
name|user
parameter_list|)
function_decl|;
end_function_decl
begin_expr_stmt
name|QString
name|password
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_function_decl
name|void
name|setPassword
parameter_list|(
specifier|const
name|QString
modifier|&
name|password
parameter_list|)
function_decl|;
end_function_decl
begin_expr_stmt
name|QString
name|realm
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_decl_stmt
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
end_decl_stmt
begin_expr_stmt
name|QVariantHash
name|options
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_function_decl
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
end_function_decl
begin_expr_stmt
name|bool
name|isNull
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_function_decl
name|void
name|detach
parameter_list|()
function_decl|;
end_function_decl
begin_label
name|private
label|:
end_label
begin_decl_stmt
name|friend
name|class
name|QAuthenticatorPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QAuthenticatorPrivate
modifier|*
name|d
decl_stmt|;
end_decl_stmt
begin_expr_stmt
unit|};
name|QT_END_NAMESPACE
name|QT_END_HEADER
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
end_unit
