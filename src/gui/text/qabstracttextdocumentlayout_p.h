begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2014 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia. For licensing terms and ** conditions see http://qt.digia.com/licensing. For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights. These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QABSTRACTTEXTDOCUMENTLAYOUT_P_H
end_ifndef
begin_define
DECL|macro|QABSTRACTTEXTDOCUMENTLAYOUT_P_H
define|#
directive|define
name|QABSTRACTTEXTDOCUMENTLAYOUT_P_H
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
comment|// This file is not part of the Qt API.  It exists purely as an
end_comment
begin_comment
comment|// implementation detail.  This header file may change from version to
end_comment
begin_comment
comment|// version without notice, or even be removed.
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
file|"private/qobject_p.h"
end_include
begin_include
include|#
directive|include
file|"QtCore/qhash.h"
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_struct
DECL|struct|QTextObjectHandler
struct|struct
name|QTextObjectHandler
block|{
DECL|function|QTextObjectHandler
name|QTextObjectHandler
argument_list|()
operator|:
name|iface
argument_list|(
literal|0
argument_list|)
block|{}
DECL|member|iface
name|QTextObjectInterface
operator|*
name|iface
expr_stmt|;
DECL|member|component
name|QPointer
operator|<
name|QObject
operator|>
name|component
expr_stmt|;
block|}
struct|;
end_struct
begin_typedef
DECL|typedef|HandlerHash
typedef|typedef
name|QHash
operator|<
name|int
operator|,
name|QTextObjectHandler
operator|>
name|HandlerHash
expr_stmt|;
end_typedef
begin_decl_stmt
name|class
name|QAbstractTextDocumentLayoutPrivate
range|:
name|public
name|QObjectPrivate
block|{
name|public
operator|:
name|Q_DECLARE_PUBLIC
argument_list|(
argument|QAbstractTextDocumentLayout
argument_list|)
specifier|inline
name|QAbstractTextDocumentLayoutPrivate
argument_list|()
operator|:
name|paintDevice
argument_list|(
literal|0
argument_list|)
block|{}
specifier|inline
name|void
name|setDocument
argument_list|(
argument|QTextDocument *doc
argument_list|)
block|{
name|document
operator|=
name|doc
block|;
name|docPrivate
operator|=
literal|0
block|;
if|if
condition|(
name|doc
condition|)
name|docPrivate
operator|=
name|doc
operator|->
name|docHandle
argument_list|()
expr_stmt|;
block|}
specifier|inline
name|int
name|_q_dynamicPageCountSlot
argument_list|()
specifier|const
block|{
return|return
name|q_func
argument_list|()
operator|->
name|pageCount
argument_list|()
return|;
block|}
specifier|inline
name|QSizeF
name|_q_dynamicDocumentSizeSlot
argument_list|()
specifier|const
block|{
return|return
name|q_func
argument_list|()
operator|->
name|documentSize
argument_list|()
return|;
block|}
name|HandlerHash
name|handlers
block|;
name|void
name|_q_handlerDestroyed
argument_list|(
name|QObject
operator|*
name|obj
argument_list|)
block|;
name|QPaintDevice
operator|*
name|paintDevice
block|;
name|QTextDocument
operator|*
name|document
block|;
name|QTextDocumentPrivate
operator|*
name|docPrivate
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
comment|// QABSTRACTTEXTDOCUMENTLAYOUT_P_H
end_comment
end_unit
