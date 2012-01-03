begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Richard J. Moore<rich@kde.org> ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtNetwork module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QSSLCERTIFICATEEXTENSION_H
end_ifndef
begin_define
DECL|macro|QSSLCERTIFICATEEXTENSION_H
define|#
directive|define
name|QSSLCERTIFICATEEXTENSION_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qnamespace.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qshareddata.h>
end_include
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
ifndef|#
directive|ifndef
name|QT_NO_SSL
name|class
name|QSslCertificateExtensionPrivate
decl_stmt|;
name|class
name|Q_NETWORK_EXPORT
name|QSslCertificateExtension
decl_stmt|{ public:     QSslCertificateExtension(
end_function
begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt
begin_expr_stmt
name|QSslCertificateExtension
argument_list|(
specifier|const
name|QSslCertificateExtension
operator|&
name|other
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
operator|~
name|QSslCertificateExtension
argument_list|()
expr_stmt|;
end_expr_stmt
begin_decl_stmt
name|QSslCertificateExtension
modifier|&
name|operator
init|=
operator|(
specifier|const
name|QSslCertificateExtension
operator|&
name|other
operator|)
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|QString
name|oid
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|QString
name|name
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|QVariant
name|value
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|bool
name|isCritical
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|bool
name|isSupported
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_label
name|private
label|:
end_label
begin_decl_stmt
name|friend
name|class
name|QSslCertificatePrivate
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|QSharedDataPointer
operator|<
name|QSslCertificateExtensionPrivate
operator|>
name|d
expr_stmt|;
end_expr_stmt
begin_endif
unit|};
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_SSL
end_comment
begin_expr_stmt
name|QT_END_NAMESPACE
name|QT_END_HEADER
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QSSLCERTIFICATEEXTENSION_H
end_comment
end_unit
