begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtNetwork module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QURLINFO_H
end_ifndef
begin_define
DECL|macro|QURLINFO_H
define|#
directive|define
name|QURLINFO_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qdatetime.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qstring.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qiodevice.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
ifndef|#
directive|ifndef
name|QT_NO_FTP
DECL|variable|QUrl
name|class
name|QUrl
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QUrlInfoPrivate
name|class
name|QUrlInfoPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_NETWORK_EXPORT
name|QUrlInfo
block|{
name|public
label|:
enum|enum
name|PermissionSpec
block|{
name|ReadOwner
init|=
literal|00400
block|,
name|WriteOwner
init|=
literal|00200
block|,
name|ExeOwner
init|=
literal|00100
block|,
name|ReadGroup
init|=
literal|00040
block|,
name|WriteGroup
init|=
literal|00020
block|,
name|ExeGroup
init|=
literal|00010
block|,
name|ReadOther
init|=
literal|00004
block|,
name|WriteOther
init|=
literal|00002
block|,
name|ExeOther
init|=
literal|00001
block|}
enum|;
name|QUrlInfo
argument_list|()
expr_stmt|;
name|QUrlInfo
argument_list|(
specifier|const
name|QUrlInfo
operator|&
name|ui
argument_list|)
expr_stmt|;
name|QUrlInfo
argument_list|(
argument|const QString&name
argument_list|,
argument|int permissions
argument_list|,
argument|const QString&owner
argument_list|,
argument|const QString&group
argument_list|,
argument|qint64 size
argument_list|,
argument|const QDateTime&lastModified
argument_list|,
argument|const QDateTime&lastRead
argument_list|,
argument|bool isDir
argument_list|,
argument|bool isFile
argument_list|,
argument|bool isSymLink
argument_list|,
argument|bool isWritable
argument_list|,
argument|bool isReadable
argument_list|,
argument|bool isExecutable
argument_list|)
empty_stmt|;
name|QUrlInfo
argument_list|(
argument|const QUrl&url
argument_list|,
argument|int permissions
argument_list|,
argument|const QString&owner
argument_list|,
argument|const QString&group
argument_list|,
argument|qint64 size
argument_list|,
argument|const QDateTime&lastModified
argument_list|,
argument|const QDateTime&lastRead
argument_list|,
argument|bool isDir
argument_list|,
argument|bool isFile
argument_list|,
argument|bool isSymLink
argument_list|,
argument|bool isWritable
argument_list|,
argument|bool isReadable
argument_list|,
argument|bool isExecutable
argument_list|)
empty_stmt|;
name|QUrlInfo
modifier|&
name|operator
init|=
operator|(
specifier|const
name|QUrlInfo
operator|&
name|ui
operator|)
decl_stmt|;
name|virtual
operator|~
name|QUrlInfo
argument_list|()
expr_stmt|;
name|virtual
name|void
name|setName
parameter_list|(
specifier|const
name|QString
modifier|&
name|name
parameter_list|)
function_decl|;
name|virtual
name|void
name|setDir
parameter_list|(
name|bool
name|b
parameter_list|)
function_decl|;
name|virtual
name|void
name|setFile
parameter_list|(
name|bool
name|b
parameter_list|)
function_decl|;
name|virtual
name|void
name|setSymLink
parameter_list|(
name|bool
name|b
parameter_list|)
function_decl|;
name|virtual
name|void
name|setOwner
parameter_list|(
specifier|const
name|QString
modifier|&
name|s
parameter_list|)
function_decl|;
name|virtual
name|void
name|setGroup
parameter_list|(
specifier|const
name|QString
modifier|&
name|s
parameter_list|)
function_decl|;
name|virtual
name|void
name|setSize
parameter_list|(
name|qint64
name|size
parameter_list|)
function_decl|;
name|virtual
name|void
name|setWritable
parameter_list|(
name|bool
name|b
parameter_list|)
function_decl|;
name|virtual
name|void
name|setReadable
parameter_list|(
name|bool
name|b
parameter_list|)
function_decl|;
name|virtual
name|void
name|setPermissions
parameter_list|(
name|int
name|p
parameter_list|)
function_decl|;
name|virtual
name|void
name|setLastModified
parameter_list|(
specifier|const
name|QDateTime
modifier|&
name|dt
parameter_list|)
function_decl|;
name|void
name|setLastRead
parameter_list|(
specifier|const
name|QDateTime
modifier|&
name|dt
parameter_list|)
function_decl|;
name|bool
name|isValid
argument_list|()
specifier|const
expr_stmt|;
name|QString
name|name
argument_list|()
specifier|const
expr_stmt|;
name|int
name|permissions
argument_list|()
specifier|const
expr_stmt|;
name|QString
name|owner
argument_list|()
specifier|const
expr_stmt|;
name|QString
name|group
argument_list|()
specifier|const
expr_stmt|;
name|qint64
name|size
argument_list|()
specifier|const
expr_stmt|;
name|QDateTime
name|lastModified
argument_list|()
specifier|const
expr_stmt|;
name|QDateTime
name|lastRead
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|isDir
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|isFile
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|isSymLink
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|isWritable
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|isReadable
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|isExecutable
argument_list|()
specifier|const
expr_stmt|;
specifier|static
name|bool
name|greaterThan
parameter_list|(
specifier|const
name|QUrlInfo
modifier|&
name|i1
parameter_list|,
specifier|const
name|QUrlInfo
modifier|&
name|i2
parameter_list|,
name|int
name|sortBy
parameter_list|)
function_decl|;
specifier|static
name|bool
name|lessThan
parameter_list|(
specifier|const
name|QUrlInfo
modifier|&
name|i1
parameter_list|,
specifier|const
name|QUrlInfo
modifier|&
name|i2
parameter_list|,
name|int
name|sortBy
parameter_list|)
function_decl|;
specifier|static
name|bool
name|equal
parameter_list|(
specifier|const
name|QUrlInfo
modifier|&
name|i1
parameter_list|,
specifier|const
name|QUrlInfo
modifier|&
name|i2
parameter_list|,
name|int
name|sortBy
parameter_list|)
function_decl|;
name|bool
name|operator
operator|==
operator|(
specifier|const
name|QUrlInfo
operator|&
name|i
operator|)
specifier|const
expr_stmt|;
specifier|inline
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|QUrlInfo
operator|&
name|i
operator|)
specifier|const
block|{
return|return
operator|!
name|operator
operator|==
operator|(
name|i
operator|)
return|;
block|}
name|private
label|:
name|QUrlInfoPrivate
modifier|*
name|d
decl_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_FTP
end_comment
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QURLINFO_H
end_comment
end_unit
