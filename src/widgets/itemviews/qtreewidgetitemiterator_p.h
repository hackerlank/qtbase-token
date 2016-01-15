begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the QtWidgets module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QTREEWIDGETITEMITERATOR_P_H
end_ifndef
begin_define
DECL|macro|QTREEWIDGETITEMITERATOR_P_H
define|#
directive|define
name|QTREEWIDGETITEMITERATOR_P_H
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
file|<QtCore/qstack.h>
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_TREEWIDGET
end_ifndef
begin_include
include|#
directive|include
file|"qtreewidgetitemiterator.h"
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QTreeModel
name|class
name|QTreeModel
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QTreeWidgetItem
name|class
name|QTreeWidgetItem
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QTreeWidgetItemIteratorPrivate
block|{
name|Q_DECLARE_PUBLIC
argument_list|(
argument|QTreeWidgetItemIterator
argument_list|)
name|public
label|:
name|QTreeWidgetItemIteratorPrivate
argument_list|(
name|QTreeWidgetItemIterator
operator|*
name|q
argument_list|,
name|QTreeModel
operator|*
name|model
argument_list|)
operator|:
name|m_currentIndex
argument_list|(
literal|0
argument_list|)
operator|,
name|m_model
argument_list|(
name|model
argument_list|)
operator|,
name|q_ptr
argument_list|(
argument|q
argument_list|)
block|{      }
name|QTreeWidgetItemIteratorPrivate
argument_list|(
specifier|const
name|QTreeWidgetItemIteratorPrivate
operator|&
name|other
argument_list|)
operator|:
name|m_currentIndex
argument_list|(
name|other
operator|.
name|m_currentIndex
argument_list|)
operator|,
name|m_model
argument_list|(
name|other
operator|.
name|m_model
argument_list|)
operator|,
name|m_parentIndex
argument_list|(
name|other
operator|.
name|m_parentIndex
argument_list|)
operator|,
name|q_ptr
argument_list|(
argument|other.q_ptr
argument_list|)
block|{      }
name|QTreeWidgetItemIteratorPrivate
operator|&
name|operator
operator|=
operator|(
specifier|const
name|QTreeWidgetItemIteratorPrivate
operator|&
name|other
operator|)
block|{
name|m_currentIndex
operator|=
name|other
operator|.
name|m_currentIndex
block|;
name|m_parentIndex
operator|=
name|other
operator|.
name|m_parentIndex
block|;
name|m_model
operator|=
name|other
operator|.
name|m_model
block|;
return|return
operator|(
operator|*
name|this
operator|)
return|;
block|}
operator|~
name|QTreeWidgetItemIteratorPrivate
argument_list|()
block|{     }
name|QTreeWidgetItem
operator|*
name|nextSibling
argument_list|(
argument|const QTreeWidgetItem* item
argument_list|)
specifier|const
expr_stmt|;
name|void
name|ensureValidIterator
parameter_list|(
specifier|const
name|QTreeWidgetItem
modifier|*
name|itemToBeRemoved
parameter_list|)
function_decl|;
name|QTreeWidgetItem
modifier|*
name|next
parameter_list|(
specifier|const
name|QTreeWidgetItem
modifier|*
name|current
parameter_list|)
function_decl|;
name|QTreeWidgetItem
modifier|*
name|previous
parameter_list|(
specifier|const
name|QTreeWidgetItem
modifier|*
name|current
parameter_list|)
function_decl|;
name|private
label|:
name|int
name|m_currentIndex
decl_stmt|;
name|QTreeModel
modifier|*
name|m_model
decl_stmt|;
comment|// This iterator class should not have ownership of the model.
name|QStack
operator|<
name|int
operator|>
name|m_parentIndex
expr_stmt|;
name|QTreeWidgetItemIterator
modifier|*
name|q_ptr
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
begin_comment
comment|// QT_NO_TREEWIDGET
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|//QTREEWIDGETITEMITERATOR_P_H
end_comment
end_unit
