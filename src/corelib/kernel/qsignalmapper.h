begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QSIGNALMAPPER_H
end_ifndef
begin_define
DECL|macro|QSIGNALMAPPER_H
define|#
directive|define
name|QSIGNALMAPPER_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qobject.h>
end_include
begin_decl_stmt
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
name|QT_MODULE
argument_list|(
name|Core
argument_list|)
ifndef|#
directive|ifndef
name|QT_NO_SIGNALMAPPER
name|class
name|QSignalMapperPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_CORE_EXPORT
name|QSignalMapper
range|:
name|public
name|QObject
block|{
name|Q_OBJECT
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QSignalMapper
argument_list|)
name|public
operator|:
name|explicit
name|QSignalMapper
argument_list|(
name|QObject
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
operator|~
name|QSignalMapper
argument_list|()
block|;
name|void
name|setMapping
argument_list|(
argument|QObject *sender
argument_list|,
argument|int id
argument_list|)
block|;
name|void
name|setMapping
argument_list|(
name|QObject
operator|*
name|sender
argument_list|,
specifier|const
name|QString
operator|&
name|text
argument_list|)
block|;
name|void
name|setMapping
argument_list|(
name|QObject
operator|*
name|sender
argument_list|,
name|QWidget
operator|*
name|widget
argument_list|)
block|;
name|void
name|setMapping
argument_list|(
name|QObject
operator|*
name|sender
argument_list|,
name|QObject
operator|*
name|object
argument_list|)
block|;
name|void
name|removeMappings
argument_list|(
name|QObject
operator|*
name|sender
argument_list|)
block|;
name|QObject
operator|*
name|mapping
argument_list|(
argument|int id
argument_list|)
specifier|const
block|;
name|QObject
operator|*
name|mapping
argument_list|(
argument|const QString&text
argument_list|)
specifier|const
block|;
name|QObject
operator|*
name|mapping
argument_list|(
argument|QWidget *widget
argument_list|)
specifier|const
block|;
name|QObject
operator|*
name|mapping
argument_list|(
argument|QObject *object
argument_list|)
specifier|const
block|;
name|Q_SIGNALS
operator|:
name|void
name|mapped
argument_list|(
name|int
argument_list|)
block|;
name|void
name|mapped
argument_list|(
specifier|const
name|QString
operator|&
argument_list|)
block|;
name|void
name|mapped
argument_list|(
name|QWidget
operator|*
argument_list|)
block|;
name|void
name|mapped
argument_list|(
name|QObject
operator|*
argument_list|)
block|;
name|public
name|Q_SLOTS
operator|:
name|void
name|map
argument_list|()
block|;
name|void
name|map
argument_list|(
name|QObject
operator|*
name|sender
argument_list|)
block|;
name|private
operator|:
name|Q_DISABLE_COPY
argument_list|(
argument|QSignalMapper
argument_list|)
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_senderDestroyed()
argument_list|)
ifdef|#
directive|ifdef
name|QT3_SUPPORT
name|public
operator|:
name|QT3_SUPPORT_CONSTRUCTOR
name|QSignalMapper
argument_list|(
name|QObject
operator|*
name|parent
argument_list|,
specifier|const
name|char
operator|*
name|name
argument_list|)
block|;
endif|#
directive|endif
block|}
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_SIGNALMAPPER
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
comment|// QSIGNALMAPPER_H
end_comment
end_unit
