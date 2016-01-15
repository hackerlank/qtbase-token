begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Ruslan Nigmatullin<euroelessar@yandex.ru> ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QMESSAGEAUTHENTICATIONCODE_H
end_ifndef
begin_define
DECL|macro|QMESSAGEAUTHENTICATIONCODE_H
define|#
directive|define
name|QMESSAGEAUTHENTICATIONCODE_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qcryptographichash.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QMessageAuthenticationCodePrivate
name|class
name|QMessageAuthenticationCodePrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QIODevice
name|class
name|QIODevice
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_CORE_EXPORT
name|QMessageAuthenticationCode
block|{
name|public
label|:
name|explicit
name|QMessageAuthenticationCode
argument_list|(
name|QCryptographicHash
operator|::
name|Algorithm
name|method
argument_list|,
specifier|const
name|QByteArray
operator|&
name|key
operator|=
name|QByteArray
argument_list|()
argument_list|)
decl_stmt|;
operator|~
name|QMessageAuthenticationCode
argument_list|()
expr_stmt|;
name|void
name|reset
parameter_list|()
function_decl|;
name|void
name|setKey
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|key
parameter_list|)
function_decl|;
name|void
name|addData
parameter_list|(
specifier|const
name|char
modifier|*
name|data
parameter_list|,
name|int
name|length
parameter_list|)
function_decl|;
name|void
name|addData
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|data
parameter_list|)
function_decl|;
name|bool
name|addData
parameter_list|(
name|QIODevice
modifier|*
name|device
parameter_list|)
function_decl|;
name|QByteArray
name|result
argument_list|()
specifier|const
expr_stmt|;
specifier|static
name|QByteArray
name|hash
argument_list|(
specifier|const
name|QByteArray
operator|&
name|message
argument_list|,
specifier|const
name|QByteArray
operator|&
name|key
argument_list|,
name|QCryptographicHash
operator|::
name|Algorithm
name|method
argument_list|)
decl_stmt|;
name|private
label|:
name|Q_DISABLE_COPY
argument_list|(
argument|QMessageAuthenticationCode
argument_list|)
name|QMessageAuthenticationCodePrivate
modifier|*
name|d
decl_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
end_unit
