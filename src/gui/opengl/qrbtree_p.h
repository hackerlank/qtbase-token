begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QRBTREE_P_H
end_ifndef
begin_define
DECL|macro|QRBTREE_P_H
define|#
directive|define
name|QRBTREE_P_H
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
file|<QtCore/qglobal.h>
end_include
begin_expr_stmt
name|QT_BEGIN_NAMESPACE
name|template
operator|<
name|class
name|T
operator|>
expr|struct
DECL|struct|QRBTree
name|QRBTree
block|{     struct
DECL|struct|Node
name|Node
block|{
DECL|function|Node
specifier|inline
name|Node
argument_list|()
operator|:
name|parent
argument_list|(
literal|0
argument_list|)
block|,
name|left
argument_list|(
literal|0
argument_list|)
block|,
name|right
argument_list|(
literal|0
argument_list|)
block|,
name|red
argument_list|(
argument|true
argument_list|)
block|{ }
DECL|function|~Node
specifier|inline
operator|~
name|Node
argument_list|()
block|{
if|if
condition|(
name|left
condition|)
name|delete
name|left
decl_stmt|;
if|if
condition|(
name|right
condition|)
name|delete
name|right
decl_stmt|;
block|}
DECL|member|data
name|T
name|data
expr_stmt|;
end_expr_stmt
begin_decl_stmt
DECL|member|parent
name|Node
modifier|*
name|parent
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|member|left
name|Node
modifier|*
name|left
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|member|right
name|Node
modifier|*
name|right
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|member|red
name|bool
name|red
decl_stmt|;
end_decl_stmt
begin_expr_stmt
DECL|member|red
unit|};
DECL|function|QRBTree
specifier|inline
name|QRBTree
argument_list|()
operator|:
name|root
argument_list|(
literal|0
argument_list|)
operator|,
name|freeList
argument_list|(
literal|0
argument_list|)
block|{ }
specifier|inline
operator|~
name|QRBTree
argument_list|()
expr_stmt|;
end_expr_stmt
begin_function_decl
specifier|inline
name|void
name|clear
parameter_list|()
function_decl|;
end_function_decl
begin_function_decl
name|void
name|attachBefore
parameter_list|(
name|Node
modifier|*
name|parent
parameter_list|,
name|Node
modifier|*
name|child
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|attachAfter
parameter_list|(
name|Node
modifier|*
name|parent
parameter_list|,
name|Node
modifier|*
name|child
parameter_list|)
function_decl|;
end_function_decl
begin_decl_stmt
specifier|inline
name|Node
modifier|*
name|front
argument_list|(
name|Node
operator|*
name|node
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt
begin_decl_stmt
specifier|inline
name|Node
modifier|*
name|back
argument_list|(
name|Node
operator|*
name|node
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|Node
modifier|*
name|next
argument_list|(
name|Node
operator|*
name|node
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|Node
modifier|*
name|previous
argument_list|(
name|Node
operator|*
name|node
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt
begin_function_decl
specifier|inline
name|void
name|deleteNode
parameter_list|(
name|Node
modifier|*
modifier|&
name|node
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
specifier|inline
name|Node
modifier|*
name|newNode
parameter_list|()
function_decl|;
end_function_decl
begin_comment
comment|// Return 1 if 'left' comes after 'right', 0 if equal, and -1 otherwise.
end_comment
begin_comment
comment|// 'left' and 'right' cannot be null.
end_comment
begin_function_decl
name|int
name|order
parameter_list|(
name|Node
modifier|*
name|left
parameter_list|,
name|Node
modifier|*
name|right
parameter_list|)
function_decl|;
end_function_decl
begin_expr_stmt
specifier|inline
name|bool
name|validate
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_label
DECL|member|private
name|private
label|:
end_label
begin_function_decl
name|void
name|rotateLeft
parameter_list|(
name|Node
modifier|*
name|node
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|rotateRight
parameter_list|(
name|Node
modifier|*
name|node
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|update
parameter_list|(
name|Node
modifier|*
name|node
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
specifier|inline
name|void
name|attachLeft
parameter_list|(
name|Node
modifier|*
name|parent
parameter_list|,
name|Node
modifier|*
name|child
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
specifier|inline
name|void
name|attachRight
parameter_list|(
name|Node
modifier|*
name|parent
parameter_list|,
name|Node
modifier|*
name|child
parameter_list|)
function_decl|;
end_function_decl
begin_decl_stmt
name|int
name|blackDepth
argument_list|(
name|Node
operator|*
name|top
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|bool
name|checkRedBlackProperty
argument_list|(
name|Node
operator|*
name|top
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt
begin_function_decl
name|void
name|swapNodes
parameter_list|(
name|Node
modifier|*
name|n1
parameter_list|,
name|Node
modifier|*
name|n2
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|detach
parameter_list|(
name|Node
modifier|*
name|node
parameter_list|)
function_decl|;
end_function_decl
begin_comment
comment|// 'node' must be black. rebalance will reduce the depth of black nodes by one in the sibling tree.
end_comment
begin_function_decl
name|void
name|rebalance
parameter_list|(
name|Node
modifier|*
name|node
parameter_list|)
function_decl|;
end_function_decl
begin_label
DECL|member|public
name|public
label|:
end_label
begin_decl_stmt
name|Node
modifier|*
name|root
decl_stmt|;
end_decl_stmt
begin_label
DECL|member|private
name|private
label|:
end_label
begin_decl_stmt
name|Node
modifier|*
name|freeList
decl_stmt|;
end_decl_stmt
begin_expr_stmt
unit|};
name|template
operator|<
name|class
name|T
operator|>
DECL|function|~QRBTree
specifier|inline
name|QRBTree
operator|<
name|T
operator|>
operator|::
operator|~
name|QRBTree
argument_list|()
block|{
name|clear
argument_list|()
block|;
while|while
condition|(
name|freeList
condition|)
block|{
comment|// Avoid recursively calling the destructor, as this list may become large.
name|Node
modifier|*
name|next
init|=
name|freeList
operator|->
name|right
decl_stmt|;
name|freeList
operator|->
name|right
operator|=
literal|0
expr_stmt|;
name|delete
name|freeList
decl_stmt|;
name|freeList
operator|=
name|next
expr_stmt|;
block|}
end_expr_stmt
begin_expr_stmt
unit|}  template
operator|<
name|class
name|T
operator|>
DECL|function|clear
specifier|inline
name|void
name|QRBTree
operator|<
name|T
operator|>
operator|::
name|clear
argument_list|()
block|{
if|if
condition|(
name|root
condition|)
name|delete
name|root
decl_stmt|;
name|root
operator|=
literal|0
expr_stmt|;
end_expr_stmt
begin_expr_stmt
unit|}  template
operator|<
name|class
name|T
operator|>
DECL|function|rotateLeft
name|void
name|QRBTree
operator|<
name|T
operator|>
operator|::
name|rotateLeft
argument_list|(
argument|Node *node
argument_list|)
block|{
comment|//   |            |      //
comment|//   N            B      //
comment|//  / \          / \     //
comment|// A   B  --->  N   D    //
comment|//    / \      / \       //
comment|//   C   D    A   C      //
name|Node
operator|*
operator|&
name|ref
operator|=
operator|(
name|node
operator|->
name|parent
operator|?
operator|(
name|node
operator|==
name|node
operator|->
name|parent
operator|->
name|left
operator|?
name|node
operator|->
name|parent
operator|->
name|left
operator|:
name|node
operator|->
name|parent
operator|->
name|right
operator|)
operator|:
name|root
operator|)
block|;
name|ref
operator|=
name|node
operator|->
name|right
block|;
name|node
operator|->
name|right
operator|->
name|parent
operator|=
name|node
operator|->
name|parent
block|;
comment|//   :        //
comment|//   N        //
comment|//  / :|      //
comment|// A   B      //
comment|//    / \     //
comment|//   C   D    //
name|node
operator|->
name|right
operator|=
name|ref
operator|->
name|left
block|;
if|if
condition|(
name|ref
operator|->
name|left
condition|)
name|ref
operator|->
name|left
operator|->
name|parent
operator|=
name|node
expr_stmt|;
comment|//   :   |     //
comment|//   N   B     //
comment|//  / \ : \    //
comment|// A   C   D   //
name|ref
operator|->
name|left
operator|=
name|node
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|node
operator|->
name|parent
operator|=
name|ref
expr_stmt|;
end_expr_stmt
begin_comment
comment|//     |       //
end_comment
begin_comment
comment|//     B       //
end_comment
begin_comment
comment|//    / \      //
end_comment
begin_comment
comment|//   N   D     //
end_comment
begin_comment
comment|//  / \        //
end_comment
begin_comment
comment|// A   C       //
end_comment
begin_expr_stmt
unit|}  template
operator|<
name|class
name|T
operator|>
DECL|function|rotateRight
name|void
name|QRBTree
operator|<
name|T
operator|>
operator|::
name|rotateRight
argument_list|(
argument|Node *node
argument_list|)
block|{
comment|//     |            |        //
comment|//     N            A        //
comment|//    / \          / \       //
comment|//   A   B  --->  C   N      //
comment|//  / \              / \     //
comment|// C   D            D   B    //
name|Node
operator|*
operator|&
name|ref
operator|=
operator|(
name|node
operator|->
name|parent
operator|?
operator|(
name|node
operator|==
name|node
operator|->
name|parent
operator|->
name|left
operator|?
name|node
operator|->
name|parent
operator|->
name|left
operator|:
name|node
operator|->
name|parent
operator|->
name|right
operator|)
operator|:
name|root
operator|)
block|;
name|ref
operator|=
name|node
operator|->
name|left
block|;
name|node
operator|->
name|left
operator|->
name|parent
operator|=
name|node
operator|->
name|parent
block|;
name|node
operator|->
name|left
operator|=
name|ref
operator|->
name|right
block|;
if|if
condition|(
name|ref
operator|->
name|right
condition|)
name|ref
operator|->
name|right
operator|->
name|parent
operator|=
name|node
expr_stmt|;
name|ref
operator|->
name|right
operator|=
name|node
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|node
operator|->
name|parent
operator|=
name|ref
expr_stmt|;
end_expr_stmt
begin_expr_stmt
unit|}  template
operator|<
name|class
name|T
operator|>
DECL|function|update
name|void
name|QRBTree
operator|<
name|T
operator|>
operator|::
name|update
argument_list|(
argument|Node *node
argument_list|)
comment|// call this after inserting a node
block|{
for|for
control|(
init|;
condition|;
control|)
block|{
name|Node
modifier|*
name|parent
init|=
name|node
operator|->
name|parent
decl_stmt|;
comment|// if the node is the root, color it black
if|if
condition|(
operator|!
name|parent
condition|)
block|{
name|node
operator|->
name|red
operator|=
name|false
expr_stmt|;
return|return;
block|}
end_expr_stmt
begin_comment
comment|// if the parent is black, the node can be left red
end_comment
begin_if
if|if
condition|(
operator|!
name|parent
operator|->
name|red
condition|)
return|return;
end_if
begin_comment
comment|// at this point, the parent is red and cannot be the root
end_comment
begin_decl_stmt
name|Node
modifier|*
name|grandpa
init|=
name|parent
operator|->
name|parent
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|Q_ASSERT
argument_list|(
name|grandpa
argument_list|)
expr_stmt|;
end_expr_stmt
begin_decl_stmt
name|Node
modifier|*
name|uncle
init|=
operator|(
name|parent
operator|==
name|grandpa
operator|->
name|left
condition|?
name|grandpa
operator|->
name|right
else|:
name|grandpa
operator|->
name|left
operator|)
decl_stmt|;
end_decl_stmt
begin_if
if|if
condition|(
name|uncle
operator|&&
name|uncle
operator|->
name|red
condition|)
block|{
comment|// grandpa's black, parent and uncle are red.
comment|// let parent and uncle be black, grandpa red and recursively update grandpa.
name|Q_ASSERT
argument_list|(
operator|!
name|grandpa
operator|->
name|red
argument_list|)
expr_stmt|;
name|parent
operator|->
name|red
operator|=
name|false
expr_stmt|;
name|uncle
operator|->
name|red
operator|=
name|false
expr_stmt|;
name|grandpa
operator|->
name|red
operator|=
name|true
expr_stmt|;
name|node
operator|=
name|grandpa
expr_stmt|;
continue|continue;
block|}
end_if
begin_comment
comment|// at this point, uncle is black
end_comment
begin_if
if|if
condition|(
name|node
operator|==
name|parent
operator|->
name|right
operator|&&
name|parent
operator|==
name|grandpa
operator|->
name|left
condition|)
name|rotateLeft
argument_list|(
name|node
operator|=
name|parent
argument_list|)
expr_stmt|;
elseif|else
if|if
condition|(
name|node
operator|==
name|parent
operator|->
name|left
operator|&&
name|parent
operator|==
name|grandpa
operator|->
name|right
condition|)
name|rotateRight
argument_list|(
name|node
operator|=
name|parent
argument_list|)
expr_stmt|;
end_if
begin_expr_stmt
name|parent
operator|=
name|node
operator|->
name|parent
expr_stmt|;
end_expr_stmt
begin_if
if|if
condition|(
name|parent
operator|==
name|grandpa
operator|->
name|left
condition|)
block|{
name|rotateRight
argument_list|(
name|grandpa
argument_list|)
expr_stmt|;
name|parent
operator|->
name|red
operator|=
name|false
expr_stmt|;
name|grandpa
operator|->
name|red
operator|=
name|true
expr_stmt|;
block|}
else|else
block|{
name|rotateLeft
argument_list|(
name|grandpa
argument_list|)
expr_stmt|;
name|parent
operator|->
name|red
operator|=
name|false
expr_stmt|;
name|grandpa
operator|->
name|red
operator|=
name|true
expr_stmt|;
block|}
end_if
begin_return
return|return;
end_return
begin_expr_stmt
unit|} }
name|template
operator|<
name|class
name|T
operator|>
DECL|function|attachLeft
specifier|inline
name|void
name|QRBTree
operator|<
name|T
operator|>
operator|::
name|attachLeft
argument_list|(
argument|Node *parent
argument_list|,
argument|Node *child
argument_list|)
block|{
name|Q_ASSERT
argument_list|(
operator|!
name|parent
operator|->
name|left
argument_list|)
block|;
name|parent
operator|->
name|left
operator|=
name|child
block|;
name|child
operator|->
name|parent
operator|=
name|parent
block|;
name|update
argument_list|(
name|child
argument_list|)
block|; }
name|template
operator|<
name|class
name|T
operator|>
DECL|function|attachRight
specifier|inline
name|void
name|QRBTree
operator|<
name|T
operator|>
operator|::
name|attachRight
argument_list|(
argument|Node *parent
argument_list|,
argument|Node *child
argument_list|)
block|{
name|Q_ASSERT
argument_list|(
operator|!
name|parent
operator|->
name|right
argument_list|)
block|;
name|parent
operator|->
name|right
operator|=
name|child
block|;
name|child
operator|->
name|parent
operator|=
name|parent
block|;
name|update
argument_list|(
name|child
argument_list|)
block|; }
name|template
operator|<
name|class
name|T
operator|>
DECL|function|attachBefore
name|void
name|QRBTree
operator|<
name|T
operator|>
operator|::
name|attachBefore
argument_list|(
argument|Node *parent
argument_list|,
argument|Node *child
argument_list|)
block|{
if|if
condition|(
operator|!
name|root
condition|)
name|update
argument_list|(
name|root
operator|=
name|child
argument_list|)
expr_stmt|;
elseif|else
if|if
condition|(
operator|!
name|parent
condition|)
name|attachRight
argument_list|(
name|back
argument_list|(
name|root
argument_list|)
argument_list|,
name|child
argument_list|)
expr_stmt|;
elseif|else
if|if
condition|(
name|parent
operator|->
name|left
condition|)
name|attachRight
argument_list|(
name|back
argument_list|(
name|parent
operator|->
name|left
argument_list|)
argument_list|,
name|child
argument_list|)
expr_stmt|;
else|else
name|attachLeft
argument_list|(
name|parent
argument_list|,
name|child
argument_list|)
expr_stmt|;
block|}
end_expr_stmt
begin_expr_stmt
name|template
operator|<
name|class
name|T
operator|>
DECL|function|attachAfter
name|void
name|QRBTree
operator|<
name|T
operator|>
operator|::
name|attachAfter
argument_list|(
argument|Node *parent
argument_list|,
argument|Node *child
argument_list|)
block|{
if|if
condition|(
operator|!
name|root
condition|)
name|update
argument_list|(
name|root
operator|=
name|child
argument_list|)
expr_stmt|;
elseif|else
if|if
condition|(
operator|!
name|parent
condition|)
name|attachLeft
argument_list|(
name|front
argument_list|(
name|root
argument_list|)
argument_list|,
name|child
argument_list|)
expr_stmt|;
elseif|else
if|if
condition|(
name|parent
operator|->
name|right
condition|)
name|attachLeft
argument_list|(
name|front
argument_list|(
name|parent
operator|->
name|right
argument_list|)
argument_list|,
name|child
argument_list|)
expr_stmt|;
else|else
name|attachRight
argument_list|(
name|parent
argument_list|,
name|child
argument_list|)
expr_stmt|;
block|}
end_expr_stmt
begin_expr_stmt
name|template
operator|<
name|class
name|T
operator|>
DECL|function|swapNodes
name|void
name|QRBTree
operator|<
name|T
operator|>
operator|::
name|swapNodes
argument_list|(
argument|Node *n1
argument_list|,
argument|Node *n2
argument_list|)
block|{
comment|// Since iterators must not be invalidated, it is not sufficient to only swap the data.
if|if
condition|(
name|n1
operator|->
name|parent
operator|==
name|n2
condition|)
block|{
name|n1
operator|->
name|parent
operator|=
name|n2
operator|->
name|parent
expr_stmt|;
name|n2
operator|->
name|parent
operator|=
name|n1
expr_stmt|;
block|}
end_expr_stmt
begin_elseif
elseif|else
if|if
condition|(
name|n2
operator|->
name|parent
operator|==
name|n1
condition|)
block|{
name|n2
operator|->
name|parent
operator|=
name|n1
operator|->
name|parent
expr_stmt|;
name|n1
operator|->
name|parent
operator|=
name|n2
expr_stmt|;
block|}
end_elseif
begin_else
else|else
block|{
name|qSwap
argument_list|(
name|n1
operator|->
name|parent
argument_list|,
name|n2
operator|->
name|parent
argument_list|)
expr_stmt|;
block|}
end_else
begin_expr_stmt
name|qSwap
argument_list|(
name|n1
operator|->
name|left
argument_list|,
name|n2
operator|->
name|left
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|qSwap
argument_list|(
name|n1
operator|->
name|right
argument_list|,
name|n2
operator|->
name|right
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|qSwap
argument_list|(
name|n1
operator|->
name|red
argument_list|,
name|n2
operator|->
name|red
argument_list|)
expr_stmt|;
end_expr_stmt
begin_if
if|if
condition|(
name|n1
operator|->
name|parent
condition|)
block|{
if|if
condition|(
name|n1
operator|->
name|parent
operator|->
name|left
operator|==
name|n2
condition|)
name|n1
operator|->
name|parent
operator|->
name|left
operator|=
name|n1
expr_stmt|;
else|else
name|n1
operator|->
name|parent
operator|->
name|right
operator|=
name|n1
expr_stmt|;
block|}
else|else
block|{
name|root
operator|=
name|n1
expr_stmt|;
block|}
end_if
begin_if
if|if
condition|(
name|n2
operator|->
name|parent
condition|)
block|{
if|if
condition|(
name|n2
operator|->
name|parent
operator|->
name|left
operator|==
name|n1
condition|)
name|n2
operator|->
name|parent
operator|->
name|left
operator|=
name|n2
expr_stmt|;
else|else
name|n2
operator|->
name|parent
operator|->
name|right
operator|=
name|n2
expr_stmt|;
block|}
else|else
block|{
name|root
operator|=
name|n2
expr_stmt|;
block|}
end_if
begin_if
if|if
condition|(
name|n1
operator|->
name|left
condition|)
name|n1
operator|->
name|left
operator|->
name|parent
operator|=
name|n1
expr_stmt|;
end_if
begin_if
if|if
condition|(
name|n1
operator|->
name|right
condition|)
name|n1
operator|->
name|right
operator|->
name|parent
operator|=
name|n1
expr_stmt|;
end_if
begin_if
if|if
condition|(
name|n2
operator|->
name|left
condition|)
name|n2
operator|->
name|left
operator|->
name|parent
operator|=
name|n2
expr_stmt|;
end_if
begin_if
if|if
condition|(
name|n2
operator|->
name|right
condition|)
name|n2
operator|->
name|right
operator|->
name|parent
operator|=
name|n2
expr_stmt|;
end_if
begin_expr_stmt
unit|}  template
operator|<
name|class
name|T
operator|>
DECL|function|detach
name|void
name|QRBTree
operator|<
name|T
operator|>
operator|::
name|detach
argument_list|(
argument|Node *node
argument_list|)
comment|// call this before removing a node.
block|{
if|if
condition|(
name|node
operator|->
name|right
condition|)
name|swapNodes
argument_list|(
name|node
argument_list|,
name|front
argument_list|(
name|node
operator|->
name|right
argument_list|)
argument_list|)
expr_stmt|;
name|Node
operator|*
name|child
operator|=
operator|(
name|node
operator|->
name|left
condition|?
name|node
operator|->
name|left
else|:
name|node
operator|->
name|right
operator|)
expr_stmt|;
end_expr_stmt
begin_if
if|if
condition|(
operator|!
name|node
operator|->
name|red
condition|)
block|{
if|if
condition|(
name|child
operator|&&
name|child
operator|->
name|red
condition|)
name|child
operator|->
name|red
operator|=
name|false
expr_stmt|;
else|else
name|rebalance
argument_list|(
name|node
argument_list|)
expr_stmt|;
block|}
end_if
begin_decl_stmt
name|Node
modifier|*
modifier|&
name|ref
init|=
operator|(
name|node
operator|->
name|parent
condition|?
operator|(
name|node
operator|==
name|node
operator|->
name|parent
operator|->
name|left
condition|?
name|node
operator|->
name|parent
operator|->
name|left
else|:
name|node
operator|->
name|parent
operator|->
name|right
operator|)
else|:
name|root
operator|)
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|ref
operator|=
name|child
expr_stmt|;
end_expr_stmt
begin_if
if|if
condition|(
name|child
condition|)
name|child
operator|->
name|parent
operator|=
name|node
operator|->
name|parent
expr_stmt|;
end_if
begin_expr_stmt
name|node
operator|->
name|left
operator|=
name|node
operator|->
name|right
operator|=
name|node
operator|->
name|parent
operator|=
literal|0
expr_stmt|;
end_expr_stmt
begin_comment
unit|}
comment|// 'node' must be black. rebalance will reduce the depth of black nodes by one in the sibling tree.
end_comment
begin_expr_stmt
unit|template
operator|<
name|class
name|T
operator|>
DECL|function|rebalance
name|void
name|QRBTree
operator|<
name|T
operator|>
operator|::
name|rebalance
argument_list|(
argument|Node *node
argument_list|)
block|{
name|Q_ASSERT
argument_list|(
operator|!
name|node
operator|->
name|red
argument_list|)
block|;
for|for
control|(
init|;
condition|;
control|)
block|{
if|if
condition|(
operator|!
name|node
operator|->
name|parent
condition|)
return|return;
comment|// at this point, node is not a parent, it is black, thus it must have a sibling.
name|Node
modifier|*
name|sibling
init|=
operator|(
name|node
operator|==
name|node
operator|->
name|parent
operator|->
name|left
condition|?
name|node
operator|->
name|parent
operator|->
name|right
else|:
name|node
operator|->
name|parent
operator|->
name|left
operator|)
decl_stmt|;
name|Q_ASSERT
argument_list|(
name|sibling
argument_list|)
expr_stmt|;
if|if
condition|(
name|sibling
operator|->
name|red
condition|)
block|{
name|sibling
operator|->
name|red
operator|=
name|false
expr_stmt|;
name|node
operator|->
name|parent
operator|->
name|red
operator|=
name|true
expr_stmt|;
if|if
condition|(
name|node
operator|==
name|node
operator|->
name|parent
operator|->
name|left
condition|)
name|rotateLeft
argument_list|(
name|node
operator|->
name|parent
argument_list|)
expr_stmt|;
else|else
name|rotateRight
argument_list|(
name|node
operator|->
name|parent
argument_list|)
expr_stmt|;
name|sibling
operator|=
operator|(
name|node
operator|==
name|node
operator|->
name|parent
operator|->
name|left
condition|?
name|node
operator|->
name|parent
operator|->
name|right
else|:
name|node
operator|->
name|parent
operator|->
name|left
operator|)
expr_stmt|;
name|Q_ASSERT
argument_list|(
name|sibling
argument_list|)
expr_stmt|;
block|}
comment|// at this point, the sibling is black.
name|Q_ASSERT
argument_list|(
operator|!
name|sibling
operator|->
name|red
argument_list|)
expr_stmt|;
end_expr_stmt
begin_if
if|if
condition|(
operator|(
operator|!
name|sibling
operator|->
name|left
operator|||
operator|!
name|sibling
operator|->
name|left
operator|->
name|red
operator|)
operator|&&
operator|(
operator|!
name|sibling
operator|->
name|right
operator|||
operator|!
name|sibling
operator|->
name|right
operator|->
name|red
operator|)
condition|)
block|{
name|bool
name|parentWasRed
init|=
name|node
operator|->
name|parent
operator|->
name|red
decl_stmt|;
name|sibling
operator|->
name|red
operator|=
name|true
expr_stmt|;
name|node
operator|->
name|parent
operator|->
name|red
operator|=
name|false
expr_stmt|;
if|if
condition|(
name|parentWasRed
condition|)
return|return;
name|node
operator|=
name|node
operator|->
name|parent
expr_stmt|;
continue|continue;
block|}
end_if
begin_comment
comment|// at this point, at least one of the sibling's children is red.
end_comment
begin_if
if|if
condition|(
name|node
operator|==
name|node
operator|->
name|parent
operator|->
name|left
condition|)
block|{
if|if
condition|(
operator|!
name|sibling
operator|->
name|right
operator|||
operator|!
name|sibling
operator|->
name|right
operator|->
name|red
condition|)
block|{
name|Q_ASSERT
argument_list|(
name|sibling
operator|->
name|left
argument_list|)
expr_stmt|;
name|sibling
operator|->
name|red
operator|=
name|true
expr_stmt|;
name|sibling
operator|->
name|left
operator|->
name|red
operator|=
name|false
expr_stmt|;
name|rotateRight
argument_list|(
name|sibling
argument_list|)
expr_stmt|;
name|sibling
operator|=
name|sibling
operator|->
name|parent
expr_stmt|;
name|Q_ASSERT
argument_list|(
name|sibling
argument_list|)
expr_stmt|;
block|}
name|sibling
operator|->
name|red
operator|=
name|node
operator|->
name|parent
operator|->
name|red
expr_stmt|;
name|node
operator|->
name|parent
operator|->
name|red
operator|=
name|false
expr_stmt|;
name|Q_ASSERT
argument_list|(
name|sibling
operator|->
name|right
operator|->
name|red
argument_list|)
expr_stmt|;
name|sibling
operator|->
name|right
operator|->
name|red
operator|=
name|false
expr_stmt|;
name|rotateLeft
argument_list|(
name|node
operator|->
name|parent
argument_list|)
expr_stmt|;
block|}
else|else
block|{
if|if
condition|(
operator|!
name|sibling
operator|->
name|left
operator|||
operator|!
name|sibling
operator|->
name|left
operator|->
name|red
condition|)
block|{
name|Q_ASSERT
argument_list|(
name|sibling
operator|->
name|right
argument_list|)
expr_stmt|;
name|sibling
operator|->
name|red
operator|=
name|true
expr_stmt|;
name|sibling
operator|->
name|right
operator|->
name|red
operator|=
name|false
expr_stmt|;
name|rotateLeft
argument_list|(
name|sibling
argument_list|)
expr_stmt|;
name|sibling
operator|=
name|sibling
operator|->
name|parent
expr_stmt|;
name|Q_ASSERT
argument_list|(
name|sibling
argument_list|)
expr_stmt|;
block|}
name|sibling
operator|->
name|red
operator|=
name|node
operator|->
name|parent
operator|->
name|red
expr_stmt|;
name|node
operator|->
name|parent
operator|->
name|red
operator|=
name|false
expr_stmt|;
name|Q_ASSERT
argument_list|(
name|sibling
operator|->
name|left
operator|->
name|red
argument_list|)
expr_stmt|;
name|sibling
operator|->
name|left
operator|->
name|red
operator|=
name|false
expr_stmt|;
name|rotateRight
argument_list|(
name|node
operator|->
name|parent
argument_list|)
expr_stmt|;
block|}
end_if
begin_return
return|return;
end_return
begin_expr_stmt
unit|} }
name|template
operator|<
name|class
name|T
operator|>
DECL|function|front
specifier|inline
name|typename
name|QRBTree
operator|<
name|T
operator|>
operator|::
name|Node
operator|*
name|QRBTree
operator|<
name|T
operator|>
operator|::
name|front
argument_list|(
argument|Node *node
argument_list|)
specifier|const
block|{
while|while
condition|(
name|node
operator|->
name|left
condition|)
name|node
operator|=
name|node
operator|->
name|left
expr_stmt|;
end_expr_stmt
begin_return
return|return
name|node
return|;
end_return
begin_expr_stmt
unit|}  template
operator|<
name|class
name|T
operator|>
DECL|function|back
specifier|inline
name|typename
name|QRBTree
operator|<
name|T
operator|>
operator|::
name|Node
operator|*
name|QRBTree
operator|<
name|T
operator|>
operator|::
name|back
argument_list|(
argument|Node *node
argument_list|)
specifier|const
block|{
while|while
condition|(
name|node
operator|->
name|right
condition|)
name|node
operator|=
name|node
operator|->
name|right
expr_stmt|;
end_expr_stmt
begin_return
return|return
name|node
return|;
end_return
begin_expr_stmt
unit|}  template
operator|<
name|class
name|T
operator|>
DECL|function|next
name|typename
name|QRBTree
operator|<
name|T
operator|>
operator|::
name|Node
operator|*
name|QRBTree
operator|<
name|T
operator|>
operator|::
name|next
argument_list|(
argument|Node *node
argument_list|)
specifier|const
block|{
if|if
condition|(
name|node
operator|->
name|right
condition|)
return|return
name|front
argument_list|(
name|node
operator|->
name|right
argument_list|)
return|;
end_expr_stmt
begin_while
while|while
condition|(
name|node
operator|->
name|parent
operator|&&
name|node
operator|==
name|node
operator|->
name|parent
operator|->
name|right
condition|)
name|node
operator|=
name|node
operator|->
name|parent
expr_stmt|;
end_while
begin_return
return|return
name|node
operator|->
name|parent
return|;
end_return
begin_expr_stmt
unit|}  template
operator|<
name|class
name|T
operator|>
DECL|function|previous
name|typename
name|QRBTree
operator|<
name|T
operator|>
operator|::
name|Node
operator|*
name|QRBTree
operator|<
name|T
operator|>
operator|::
name|previous
argument_list|(
argument|Node *node
argument_list|)
specifier|const
block|{
if|if
condition|(
name|node
operator|->
name|left
condition|)
return|return
name|back
argument_list|(
name|node
operator|->
name|left
argument_list|)
return|;
end_expr_stmt
begin_while
while|while
condition|(
name|node
operator|->
name|parent
operator|&&
name|node
operator|==
name|node
operator|->
name|parent
operator|->
name|left
condition|)
name|node
operator|=
name|node
operator|->
name|parent
expr_stmt|;
end_while
begin_return
return|return
name|node
operator|->
name|parent
return|;
end_return
begin_expr_stmt
unit|}  template
operator|<
name|class
name|T
operator|>
DECL|function|blackDepth
name|int
name|QRBTree
operator|<
name|T
operator|>
operator|::
name|blackDepth
argument_list|(
argument|Node *top
argument_list|)
specifier|const
block|{
if|if
condition|(
operator|!
name|top
condition|)
return|return
literal|0
return|;
name|int
name|leftDepth
operator|=
name|blackDepth
argument_list|(
name|top
operator|->
name|left
argument_list|)
expr_stmt|;
end_expr_stmt
begin_decl_stmt
name|int
name|rightDepth
init|=
name|blackDepth
argument_list|(
name|top
operator|->
name|right
argument_list|)
decl_stmt|;
end_decl_stmt
begin_if
if|if
condition|(
name|leftDepth
operator|!=
name|rightDepth
condition|)
return|return
operator|-
literal|1
return|;
end_if
begin_if
if|if
condition|(
operator|!
name|top
operator|->
name|red
condition|)
operator|++
name|leftDepth
expr_stmt|;
end_if
begin_return
return|return
name|leftDepth
return|;
end_return
begin_expr_stmt
unit|}  template
operator|<
name|class
name|T
operator|>
DECL|function|checkRedBlackProperty
name|bool
name|QRBTree
operator|<
name|T
operator|>
operator|::
name|checkRedBlackProperty
argument_list|(
argument|Node *top
argument_list|)
specifier|const
block|{
if|if
condition|(
operator|!
name|top
condition|)
return|return
name|true
return|;
end_expr_stmt
begin_if
if|if
condition|(
name|top
operator|->
name|left
operator|&&
operator|!
name|checkRedBlackProperty
argument_list|(
name|top
operator|->
name|left
argument_list|)
condition|)
return|return
name|false
return|;
end_if
begin_if
if|if
condition|(
name|top
operator|->
name|right
operator|&&
operator|!
name|checkRedBlackProperty
argument_list|(
name|top
operator|->
name|right
argument_list|)
condition|)
return|return
name|false
return|;
end_if
begin_return
return|return
operator|!
operator|(
name|top
operator|->
name|red
operator|&&
operator|(
operator|(
name|top
operator|->
name|left
operator|&&
name|top
operator|->
name|left
operator|->
name|red
operator|)
operator|||
operator|(
name|top
operator|->
name|right
operator|&&
name|top
operator|->
name|right
operator|->
name|red
operator|)
operator|)
operator|)
return|;
end_return
begin_expr_stmt
unit|}  template
operator|<
name|class
name|T
operator|>
DECL|function|validate
specifier|inline
name|bool
name|QRBTree
operator|<
name|T
operator|>
operator|::
name|validate
argument_list|()
specifier|const
block|{
return|return
name|checkRedBlackProperty
argument_list|(
name|root
argument_list|)
operator|&&
name|blackDepth
argument_list|(
name|root
argument_list|)
operator|!=
operator|-
literal|1
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|template
operator|<
name|class
name|T
operator|>
DECL|function|deleteNode
specifier|inline
name|void
name|QRBTree
operator|<
name|T
operator|>
operator|::
name|deleteNode
argument_list|(
argument|Node *&node
argument_list|)
block|{
name|Q_ASSERT
argument_list|(
name|node
argument_list|)
block|;
name|detach
argument_list|(
name|node
argument_list|)
block|;
name|node
operator|->
name|right
operator|=
name|freeList
block|;
name|freeList
operator|=
name|node
block|;
name|node
operator|=
literal|0
block|; }
name|template
operator|<
name|class
name|T
operator|>
DECL|function|newNode
specifier|inline
name|typename
name|QRBTree
operator|<
name|T
operator|>
operator|::
name|Node
operator|*
name|QRBTree
operator|<
name|T
operator|>
operator|::
name|newNode
argument_list|()
block|{
if|if
condition|(
name|freeList
condition|)
block|{
name|Node
modifier|*
name|node
init|=
name|freeList
decl_stmt|;
name|freeList
operator|=
name|freeList
operator|->
name|right
expr_stmt|;
name|node
operator|->
name|parent
operator|=
name|node
operator|->
name|left
operator|=
name|node
operator|->
name|right
operator|=
literal|0
expr_stmt|;
name|node
operator|->
name|red
operator|=
name|true
expr_stmt|;
return|return
name|node
return|;
block|}
end_expr_stmt
begin_return
return|return
name|new
name|Node
return|;
end_return
begin_comment
unit|}
comment|// Return 1 if 'left' comes after 'right', 0 if equal, and -1 otherwise.
end_comment
begin_comment
comment|// 'left' and 'right' cannot be null.
end_comment
begin_expr_stmt
unit|template
operator|<
name|class
name|T
operator|>
DECL|function|order
name|int
name|QRBTree
operator|<
name|T
operator|>
operator|::
name|order
argument_list|(
argument|Node *left
argument_list|,
argument|Node *right
argument_list|)
block|{
name|Q_ASSERT
argument_list|(
name|left
operator|&&
name|right
argument_list|)
block|;
if|if
condition|(
name|left
operator|==
name|right
condition|)
return|return
literal|0
return|;
name|QVector
operator|<
name|Node
operator|*
operator|>
name|leftAncestors
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|QVector
operator|<
name|Node
operator|*
operator|>
name|rightAncestors
expr_stmt|;
end_expr_stmt
begin_while
while|while
condition|(
name|left
condition|)
block|{
name|leftAncestors
operator|.
name|push_back
argument_list|(
name|left
argument_list|)
expr_stmt|;
name|left
operator|=
name|left
operator|->
name|parent
expr_stmt|;
block|}
end_while
begin_while
while|while
condition|(
name|right
condition|)
block|{
name|rightAncestors
operator|.
name|push_back
argument_list|(
name|right
argument_list|)
expr_stmt|;
name|right
operator|=
name|right
operator|->
name|parent
expr_stmt|;
block|}
end_while
begin_expr_stmt
name|Q_ASSERT
argument_list|(
name|leftAncestors
operator|.
name|back
argument_list|()
operator|==
name|root
operator|&&
name|rightAncestors
operator|.
name|back
argument_list|()
operator|==
name|root
argument_list|)
expr_stmt|;
end_expr_stmt
begin_while
while|while
condition|(
operator|!
name|leftAncestors
operator|.
name|empty
argument_list|()
operator|&&
operator|!
name|rightAncestors
operator|.
name|empty
argument_list|()
operator|&&
name|leftAncestors
operator|.
name|back
argument_list|()
operator|==
name|rightAncestors
operator|.
name|back
argument_list|()
condition|)
block|{
name|leftAncestors
operator|.
name|pop_back
argument_list|()
expr_stmt|;
name|rightAncestors
operator|.
name|pop_back
argument_list|()
expr_stmt|;
block|}
end_while
begin_if
if|if
condition|(
operator|!
name|leftAncestors
operator|.
name|empty
argument_list|()
condition|)
return|return
operator|(
name|leftAncestors
operator|.
name|back
argument_list|()
operator|==
name|leftAncestors
operator|.
name|back
argument_list|()
operator|->
name|parent
operator|->
name|left
condition|?
operator|-
literal|1
else|:
literal|1
operator|)
return|;
end_if
begin_if
if|if
condition|(
operator|!
name|rightAncestors
operator|.
name|empty
argument_list|()
condition|)
return|return
operator|(
name|rightAncestors
operator|.
name|back
argument_list|()
operator|==
name|rightAncestors
operator|.
name|back
argument_list|()
operator|->
name|parent
operator|->
name|right
condition|?
operator|-
literal|1
else|:
literal|1
operator|)
return|;
end_if
begin_comment
comment|// The code should never reach this point.
end_comment
begin_expr_stmt
name|Q_ASSERT
argument_list|(
operator|!
name|leftAncestors
operator|.
name|empty
argument_list|()
operator|||
operator|!
name|rightAncestors
operator|.
name|empty
argument_list|()
argument_list|)
expr_stmt|;
end_expr_stmt
begin_return
return|return
literal|0
return|;
end_return
begin_endif
unit|}  QT_END_NAMESPACE
endif|#
directive|endif
end_endif
end_unit
