begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QEVENTDISPATCHER_GLIB_QPA_P_H
end_ifndef
begin_define
DECL|macro|QEVENTDISPATCHER_GLIB_QPA_P_H
define|#
directive|define
name|QEVENTDISPATCHER_GLIB_QPA_P_H
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
comment|// of the QLibrary class.  This header file may change from
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
file|<QtCore/private/qeventdispatcher_glib_p.h>
end_include
begin_typedef
DECL|typedef|GMainContext
typedef|typedef
name|struct
name|_GMainContext
name|GMainContext
typedef|;
end_typedef
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QPAEventDispatcherGlibPrivate
name|class
name|QPAEventDispatcherGlibPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QPAEventDispatcherGlib
range|:
name|public
name|QEventDispatcherGlib
block|{
name|Q_OBJECT
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QPAEventDispatcherGlib
argument_list|)
name|public
operator|:
name|explicit
name|QPAEventDispatcherGlib
argument_list|(
name|QObject
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
operator|~
name|QPAEventDispatcherGlib
argument_list|()
block|; }
decl_stmt|;
end_decl_stmt
begin_struct_decl
struct_decl|struct
name|GUserEventSource
struct_decl|;
end_struct_decl
begin_decl_stmt
name|class
name|QPAEventDispatcherGlibPrivate
range|:
name|public
name|QEventDispatcherGlibPrivate
block|{
name|Q_DECLARE_PUBLIC
argument_list|(
argument|QPAEventDispatcherGlib
argument_list|)
name|public
operator|:
name|QPAEventDispatcherGlibPrivate
argument_list|(
name|GMainContext
operator|*
name|context
operator|=
literal|0
argument_list|)
block|;
name|GUserEventSource
operator|*
name|userEventSource
block|; }
decl_stmt|;
end_decl_stmt
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QEVENTDISPATCHER_GLIB_QPA_P_H
end_comment
end_unit
