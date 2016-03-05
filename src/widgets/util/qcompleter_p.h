begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the QtWidgets module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QCOMPLETER_P_H
end_ifndef
begin_define
DECL|macro|QCOMPLETER_P_H
define|#
directive|define
name|QCOMPLETER_P_H
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
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_COMPLETER
end_ifndef
begin_include
include|#
directive|include
file|"QtWidgets/qtreeview.h"
end_include
begin_include
include|#
directive|include
file|"QtCore/qabstractproxymodel.h"
end_include
begin_include
include|#
directive|include
file|"qcompleter.h"
end_include
begin_include
include|#
directive|include
file|"QtWidgets/qitemdelegate.h"
end_include
begin_include
include|#
directive|include
file|"QtGui/qpainter.h"
end_include
begin_include
include|#
directive|include
file|"private/qabstractproxymodel_p.h"
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QCompletionModel
name|class
name|QCompletionModel
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QCompleterPrivate
range|:
name|public
name|QObjectPrivate
block|{
name|Q_DECLARE_PUBLIC
argument_list|(
argument|QCompleter
argument_list|)
name|public
operator|:
name|QCompleterPrivate
argument_list|()
block|;
operator|~
name|QCompleterPrivate
argument_list|()
block|{
name|delete
name|popup
block|; }
name|void
name|init
argument_list|(
name|QAbstractItemModel
operator|*
name|model
operator|=
literal|0
argument_list|)
block|;
name|QPointer
operator|<
name|QWidget
operator|>
name|widget
block|;
name|QCompletionModel
operator|*
name|proxy
block|;
name|QAbstractItemView
operator|*
name|popup
block|;
name|QCompleter
operator|::
name|CompletionMode
name|mode
block|;
name|Qt
operator|::
name|MatchFlags
name|filterMode
block|;
name|QString
name|prefix
block|;
name|Qt
operator|::
name|CaseSensitivity
name|cs
block|;
name|int
name|role
block|;
name|int
name|column
block|;
name|int
name|maxVisibleItems
block|;
name|QCompleter
operator|::
name|ModelSorting
name|sorting
block|;
name|bool
name|wrap
block|;
name|bool
name|eatFocusOut
block|;
name|QRect
name|popupRect
block|;
name|bool
name|hiddenBecauseNoMatch
block|;
name|void
name|showPopup
argument_list|(
specifier|const
name|QRect
operator|&
argument_list|)
block|;
name|void
name|_q_complete
argument_list|(
name|QModelIndex
argument_list|,
name|bool
operator|=
name|false
argument_list|)
block|;
name|void
name|_q_completionSelected
argument_list|(
specifier|const
name|QItemSelection
operator|&
argument_list|)
block|;
name|void
name|_q_autoResizePopup
argument_list|()
block|;
name|void
name|_q_fileSystemModelDirectoryLoaded
argument_list|(
specifier|const
name|QString
operator|&
name|path
argument_list|)
block|;
name|void
name|setCurrentIndex
argument_list|(
name|QModelIndex
argument_list|,
name|bool
operator|=
name|true
argument_list|)
block|; }
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QIndexMapper
block|{
name|public
label|:
name|QIndexMapper
argument_list|()
operator|:
name|v
argument_list|(
name|false
argument_list|)
operator|,
name|f
argument_list|(
literal|0
argument_list|)
operator|,
name|t
argument_list|(
argument|-
literal|1
argument_list|)
block|{ }
name|QIndexMapper
argument_list|(
argument|int f
argument_list|,
argument|int t
argument_list|)
operator|:
name|v
argument_list|(
name|false
argument_list|)
operator|,
name|f
argument_list|(
name|f
argument_list|)
operator|,
name|t
argument_list|(
argument|t
argument_list|)
block|{ }
name|QIndexMapper
argument_list|(
specifier|const
name|QVector
operator|<
name|int
operator|>
operator|&
name|vec
argument_list|)
operator|:
name|v
argument_list|(
name|true
argument_list|)
operator|,
name|vector
argument_list|(
name|vec
argument_list|)
operator|,
name|f
argument_list|(
operator|-
literal|1
argument_list|)
operator|,
name|t
argument_list|(
argument|-
literal|1
argument_list|)
block|{ }
specifier|inline
name|int
name|count
argument_list|()
specifier|const
block|{
return|return
name|v
operator|?
name|vector
operator|.
name|count
argument_list|()
operator|:
name|t
operator|-
name|f
operator|+
literal|1
return|;
block|}
specifier|inline
name|int
name|operator
index|[]
argument_list|(
name|int
name|index
argument_list|)
decl|const
block|{
return|return
name|v
condition|?
name|vector
index|[
name|index
index|]
else|:
name|f
operator|+
name|index
return|;
block|}
specifier|inline
name|int
name|indexOf
argument_list|(
name|int
name|x
argument_list|)
decl|const
block|{
return|return
name|v
condition|?
name|vector
operator|.
name|indexOf
argument_list|(
name|x
argument_list|)
else|:
operator|(
operator|(
name|t
operator|<
name|f
operator|)
condition|?
operator|-
literal|1
else|:
name|x
operator|-
name|f
operator|)
return|;
block|}
specifier|inline
name|bool
name|isValid
argument_list|()
specifier|const
block|{
return|return
operator|!
name|isEmpty
argument_list|()
return|;
block|}
specifier|inline
name|bool
name|isEmpty
argument_list|()
specifier|const
block|{
return|return
name|v
operator|?
name|vector
operator|.
name|isEmpty
argument_list|()
operator|:
operator|(
name|t
operator|<
name|f
operator|)
return|;
block|}
specifier|inline
name|void
name|append
parameter_list|(
name|int
name|x
parameter_list|)
block|{
name|Q_ASSERT
argument_list|(
name|v
argument_list|)
expr_stmt|;
name|vector
operator|.
name|append
argument_list|(
name|x
argument_list|)
expr_stmt|;
block|}
specifier|inline
name|int
name|first
argument_list|()
specifier|const
block|{
return|return
name|v
operator|?
name|vector
operator|.
name|first
argument_list|()
operator|:
name|f
return|;
block|}
specifier|inline
name|int
name|last
argument_list|()
specifier|const
block|{
return|return
name|v
operator|?
name|vector
operator|.
name|last
argument_list|()
operator|:
name|t
return|;
block|}
specifier|inline
name|int
name|from
argument_list|()
specifier|const
block|{
name|Q_ASSERT
argument_list|(
operator|!
name|v
argument_list|)
block|;
return|return
name|f
return|;
block|}
specifier|inline
name|int
name|to
argument_list|()
specifier|const
block|{
name|Q_ASSERT
argument_list|(
operator|!
name|v
argument_list|)
block|;
return|return
name|t
return|;
block|}
specifier|inline
name|int
name|cost
argument_list|()
specifier|const
block|{
return|return
name|vector
operator|.
name|count
argument_list|()
operator|+
literal|2
return|;
block|}
name|private
label|:
name|bool
name|v
decl_stmt|;
name|QVector
operator|<
name|int
operator|>
name|vector
expr_stmt|;
name|int
name|f
decl_stmt|,
name|t
decl_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_struct
DECL|struct|QMatchData
struct|struct
name|QMatchData
block|{
DECL|function|QMatchData
name|QMatchData
argument_list|()
operator|:
name|exactMatchIndex
argument_list|(
operator|-
literal|1
argument_list|)
operator|,
name|partial
argument_list|(
argument|false
argument_list|)
block|{ }
DECL|function|QMatchData
name|QMatchData
argument_list|(
argument|const QIndexMapper& indices
argument_list|,
argument|int em
argument_list|,
argument|bool p
argument_list|)
operator|:
name|indices
argument_list|(
name|indices
argument_list|)
operator|,
name|exactMatchIndex
argument_list|(
name|em
argument_list|)
operator|,
name|partial
argument_list|(
argument|p
argument_list|)
block|{ }
DECL|member|indices
name|QIndexMapper
name|indices
expr_stmt|;
DECL|function|isValid
specifier|inline
name|bool
name|isValid
argument_list|()
specifier|const
block|{
return|return
name|indices
operator|.
name|isValid
argument_list|()
return|;
block|}
DECL|member|exactMatchIndex
name|int
name|exactMatchIndex
decl_stmt|;
DECL|member|partial
name|bool
name|partial
decl_stmt|;
block|}
struct|;
end_struct
begin_decl_stmt
name|class
name|QCompletionEngine
block|{
name|public
label|:
typedef|typedef
name|QMap
operator|<
name|QString
operator|,
name|QMatchData
operator|>
name|CacheItem
expr_stmt|;
typedef|typedef
name|QMap
operator|<
name|QModelIndex
operator|,
name|CacheItem
operator|>
name|Cache
expr_stmt|;
name|QCompletionEngine
argument_list|(
name|QCompleterPrivate
operator|*
name|c
argument_list|)
operator|:
name|c
argument_list|(
name|c
argument_list|)
operator|,
name|curRow
argument_list|(
operator|-
literal|1
argument_list|)
operator|,
name|cost
argument_list|(
literal|0
argument_list|)
block|{ }
name|virtual
operator|~
name|QCompletionEngine
argument_list|()
block|{ }
name|void
name|filter
argument_list|(
specifier|const
name|QStringList
operator|&
name|parts
argument_list|)
expr_stmt|;
name|QMatchData
name|filterHistory
parameter_list|()
function_decl|;
name|bool
name|matchHint
parameter_list|(
name|QString
parameter_list|,
specifier|const
name|QModelIndex
modifier|&
parameter_list|,
name|QMatchData
modifier|*
parameter_list|)
function_decl|;
name|void
name|saveInCache
parameter_list|(
name|QString
parameter_list|,
specifier|const
name|QModelIndex
modifier|&
parameter_list|,
specifier|const
name|QMatchData
modifier|&
parameter_list|)
function_decl|;
name|bool
name|lookupCache
parameter_list|(
name|QString
name|part
parameter_list|,
specifier|const
name|QModelIndex
modifier|&
name|parent
parameter_list|,
name|QMatchData
modifier|*
name|m
parameter_list|)
function_decl|;
name|virtual
name|void
name|filterOnDemand
parameter_list|(
name|int
parameter_list|)
block|{ }
name|virtual
name|QMatchData
name|filter
parameter_list|(
specifier|const
name|QString
modifier|&
parameter_list|,
specifier|const
name|QModelIndex
modifier|&
parameter_list|,
name|int
parameter_list|)
init|=
literal|0
function_decl|;
name|int
name|matchCount
argument_list|()
specifier|const
block|{
return|return
name|curMatch
operator|.
name|indices
operator|.
name|count
argument_list|()
operator|+
name|historyMatch
operator|.
name|indices
operator|.
name|count
argument_list|()
return|;
block|}
name|QMatchData
name|curMatch
decl_stmt|,
name|historyMatch
decl_stmt|;
name|QCompleterPrivate
modifier|*
name|c
decl_stmt|;
name|QStringList
name|curParts
decl_stmt|;
name|QModelIndex
name|curParent
decl_stmt|;
name|int
name|curRow
decl_stmt|;
name|Cache
name|cache
decl_stmt|;
name|int
name|cost
decl_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_decl_stmt
name|class
name|QSortedModelEngine
range|:
name|public
name|QCompletionEngine
block|{
name|public
operator|:
name|QSortedModelEngine
argument_list|(
name|QCompleterPrivate
operator|*
name|c
argument_list|)
operator|:
name|QCompletionEngine
argument_list|(
argument|c
argument_list|)
block|{ }
name|QMatchData
name|filter
argument_list|(
argument|const QString&
argument_list|,
argument|const QModelIndex&
argument_list|,
argument|int
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|QIndexMapper
name|indexHint
argument_list|(
name|QString
argument_list|,
specifier|const
name|QModelIndex
operator|&
argument_list|,
name|Qt
operator|::
name|SortOrder
argument_list|)
block|;
name|Qt
operator|::
name|SortOrder
name|sortOrder
argument_list|(
argument|const QModelIndex&
argument_list|)
specifier|const
block|; }
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QUnsortedModelEngine
range|:
name|public
name|QCompletionEngine
block|{
name|public
operator|:
name|QUnsortedModelEngine
argument_list|(
name|QCompleterPrivate
operator|*
name|c
argument_list|)
operator|:
name|QCompletionEngine
argument_list|(
argument|c
argument_list|)
block|{ }
name|void
name|filterOnDemand
argument_list|(
argument|int
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|QMatchData
name|filter
argument_list|(
argument|const QString&
argument_list|,
argument|const QModelIndex&
argument_list|,
argument|int
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|private
operator|:
name|int
name|buildIndices
argument_list|(
argument|const QString& str
argument_list|,
argument|const QModelIndex& parent
argument_list|,
argument|int n
argument_list|,
argument|const QIndexMapper& iv
argument_list|,
argument|QMatchData* m
argument_list|)
block|; }
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QCompleterItemDelegate
range|:
name|public
name|QItemDelegate
block|{
name|public
operator|:
name|QCompleterItemDelegate
argument_list|(
name|QAbstractItemView
operator|*
name|view
argument_list|)
operator|:
name|QItemDelegate
argument_list|(
name|view
argument_list|)
block|,
name|view
argument_list|(
argument|view
argument_list|)
block|{ }
name|void
name|paint
argument_list|(
argument|QPainter *p
argument_list|,
argument|const QStyleOptionViewItem& opt
argument_list|,
argument|const QModelIndex& idx
argument_list|)
specifier|const
name|Q_DECL_OVERRIDE
block|{
name|QStyleOptionViewItem
name|optCopy
operator|=
name|opt
block|;
name|optCopy
operator|.
name|showDecorationSelected
operator|=
name|true
block|;
if|if
condition|(
name|view
operator|->
name|currentIndex
argument_list|()
operator|==
name|idx
condition|)
name|optCopy
operator|.
name|state
operator||=
name|QStyle
operator|::
name|State_HasFocus
expr_stmt|;
name|QItemDelegate
operator|::
name|paint
argument_list|(
name|p
argument_list|,
name|optCopy
argument_list|,
name|idx
argument_list|)
block|;     }
name|private
operator|:
name|QAbstractItemView
operator|*
name|view
decl_stmt|;
end_decl_stmt
begin_decl_stmt
unit|};
DECL|variable|QCompletionModelPrivate
name|class
name|QCompletionModelPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QCompletionModel
range|:
name|public
name|QAbstractProxyModel
block|{
name|Q_OBJECT
name|public
operator|:
name|QCompletionModel
argument_list|(
name|QCompleterPrivate
operator|*
name|c
argument_list|,
name|QObject
operator|*
name|parent
argument_list|)
block|;
name|void
name|createEngine
argument_list|()
block|;
name|void
name|setFiltered
argument_list|(
name|bool
argument_list|)
block|;
name|void
name|filter
argument_list|(
specifier|const
name|QStringList
operator|&
name|parts
argument_list|)
block|;
name|int
name|completionCount
argument_list|()
specifier|const
block|;
name|int
name|currentRow
argument_list|()
specifier|const
block|{
return|return
name|engine
operator|->
name|curRow
return|;
block|}
name|bool
name|setCurrentRow
argument_list|(
argument|int row
argument_list|)
block|;
name|QModelIndex
name|currentIndex
argument_list|(
argument|bool
argument_list|)
specifier|const
block|;
name|QModelIndex
name|index
argument_list|(
argument|int row
argument_list|,
argument|int column
argument_list|,
argument|const QModelIndex& = QModelIndex()
argument_list|)
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|int
name|rowCount
argument_list|(
argument|const QModelIndex&index = QModelIndex()
argument_list|)
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|int
name|columnCount
argument_list|(
argument|const QModelIndex&index = QModelIndex()
argument_list|)
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|bool
name|hasChildren
argument_list|(
argument|const QModelIndex&parent = QModelIndex()
argument_list|)
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|QModelIndex
name|parent
argument_list|(
argument|const QModelIndex& = QModelIndex()
argument_list|)
specifier|const
name|Q_DECL_OVERRIDE
block|{
return|return
name|QModelIndex
argument_list|()
return|;
block|}
name|QVariant
name|data
argument_list|(
argument|const QModelIndex& index
argument_list|,
argument|int role = Qt::DisplayRole
argument_list|)
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|void
name|setSourceModel
argument_list|(
argument|QAbstractItemModel *sourceModel
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|QModelIndex
name|mapToSource
argument_list|(
argument|const QModelIndex& proxyIndex
argument_list|)
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|QModelIndex
name|mapFromSource
argument_list|(
argument|const QModelIndex& sourceIndex
argument_list|)
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|QCompleterPrivate
operator|*
name|c
block|;
name|QScopedPointer
operator|<
name|QCompletionEngine
operator|>
name|engine
block|;
name|bool
name|showAll
block|;
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QCompletionModel
argument_list|)
name|signals
operator|:
name|void
name|rowsAdded
argument_list|()
block|;
name|public
name|Q_SLOTS
operator|:
name|void
name|invalidate
argument_list|()
block|;
name|void
name|rowsInserted
argument_list|()
block|;
name|void
name|modelDestroyed
argument_list|()
block|; }
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QCompletionModelPrivate
range|:
name|public
name|QAbstractProxyModelPrivate
block|{
name|Q_DECLARE_PUBLIC
argument_list|(
argument|QCompletionModel
argument_list|)
block|}
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
comment|// QT_NO_COMPLETER
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QCOMPLETER_P_H
end_comment
end_unit
