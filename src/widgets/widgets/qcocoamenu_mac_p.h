begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
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
file|"qmacdefines_mac.h"
end_include
begin_empty
empty|#import<Cocoa/Cocoa.h>
end_empty
begin_macro
name|QT_FORWARD_DECLARE_CLASS
argument_list|(
argument|QMenu
argument_list|)
end_macro
begin_expr_stmt
name|QT_FORWARD_DECLARE_CLASS
argument_list|(
name|QAction
argument_list|)
if|#
directive|if
name|MAC_OS_X_VERSION_MAX_ALLOWED
operator|<=
name|MAC_OS_X_VERSION_10_5
expr|@
name|protocol
name|NSMenuDelegate
operator|<
name|NSObject
operator|>
operator|-
operator|(
name|void
operator|)
name|menu
operator|:
operator|(
name|NSMenu
operator|*
operator|)
name|menu
name|willHighlightItem
operator|:
operator|(
name|NSMenuItem
operator|*
operator|)
name|item
expr_stmt|;
end_expr_stmt
begin_expr_stmt
operator|-
operator|(
name|void
operator|)
name|menuWillOpen
operator|:
operator|(
name|NSMenu
operator|*
operator|)
name|menu
expr_stmt|;
end_expr_stmt
begin_expr_stmt
operator|-
operator|(
name|void
operator|)
name|menuDidClose
operator|:
operator|(
name|NSMenu
operator|*
operator|)
name|menu
expr_stmt|;
end_expr_stmt
begin_expr_stmt
operator|-
operator|(
name|BOOL
operator|)
name|hasShortcut
operator|:
operator|(
name|NSMenu
operator|*
operator|)
name|menu
name|forKey
operator|:
operator|(
name|NSString
operator|*
operator|)
name|key
name|forModifiers
operator|:
operator|(
name|NSUInteger
operator|)
name|modifier
name|whichItem
operator|:
operator|(
name|NSMenuItem
operator|*
operator|*
operator|)
name|outItem
expr_stmt|;
end_expr_stmt
begin_expr_stmt
unit|@
name|end
endif|#
directive|endif
expr|@
name|interface
name|QT_MANGLE_NAMESPACE
argument_list|(
name|QCocoaMenu
argument_list|)
operator|:
name|NSMenu
operator|<
name|NSMenuDelegate
operator|>
block|{
name|QMenu
operator|*
name|qmenu
block|;
name|QAction
operator|*
name|previousAction
block|; }
operator|-
operator|(
name|id
operator|)
name|initWithQMenu
operator|:
operator|(
name|QMenu
operator|*
operator|)
name|menu
expr_stmt|;
end_expr_stmt
begin_expr_stmt
operator|-
operator|(
name|BOOL
operator|)
name|menuHasKeyEquivalent
operator|:
operator|(
name|NSMenu
operator|*
operator|)
name|menu
name|forEvent
operator|:
operator|(
name|NSEvent
operator|*
operator|)
name|event
name|target
operator|:
operator|(
name|id
operator|*
operator|)
name|target
name|action
operator|:
operator|(
name|SEL
operator|*
operator|)
name|action
expr_stmt|;
end_expr_stmt
begin_expr_stmt
operator|-
operator|(
name|NSInteger
operator|)
name|indexOfItemWithTarget
operator|:
operator|(
name|id
operator|)
name|anObject
name|andAction
operator|:
operator|(
name|SEL
operator|)
name|actionSelector
expr_stmt|;
end_expr_stmt
begin_macro
unit|@
name|end
end_macro
end_unit
