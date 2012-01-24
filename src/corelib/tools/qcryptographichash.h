begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QCRYPTOGRAPHICSHASH_H
end_ifndef
begin_define
DECL|macro|QCRYPTOGRAPHICSHASH_H
define|#
directive|define
name|QCRYPTOGRAPHICSHASH_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qbytearray.h>
end_include
begin_decl_stmt
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
DECL|variable|QCryptographicHashPrivate
name|class
name|QCryptographicHashPrivate
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
name|QCryptographicHash
block|{
name|public
label|:
enum|enum
name|Algorithm
block|{
name|Md4
block|,
name|Md5
block|,
name|Sha1
block|}
enum|;
name|QCryptographicHash
argument_list|(
argument|Algorithm method
argument_list|)
empty_stmt|;
operator|~
name|QCryptographicHash
argument_list|()
expr_stmt|;
name|void
name|reset
parameter_list|()
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
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|data
parameter_list|,
name|Algorithm
name|method
parameter_list|)
function_decl|;
name|private
label|:
name|Q_DISABLE_COPY
argument_list|(
argument|QCryptographicHash
argument_list|)
name|QCryptographicHashPrivate
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
