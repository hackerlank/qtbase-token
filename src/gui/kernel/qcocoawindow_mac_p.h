begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** No Commercial Usage ** This file contains pre-release code and may not be distributed. ** You may use this file in accordance with the terms and conditions ** contained in the Technology Preview License Agreement accompanying ** this package. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights.  These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** If you have questions regarding the use of this file, please contact ** Nokia at qt-info@nokia.com. ** ** ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
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
begin_ifndef
ifndef|#
directive|ifndef
name|QCOCOAWINDOW_MAC_P
end_ifndef
begin_define
DECL|macro|QCOCOAWINDOW_MAC_P
define|#
directive|define
name|QCOCOAWINDOW_MAC_P
end_define
begin_ifdef
ifdef|#
directive|ifdef
name|QT_MAC_USE_COCOA
end_ifdef
begin_include
include|#
directive|include
file|"qmacdefines_mac.h"
end_include
begin_empty
empty|#import<Cocoa/Cocoa.h>
end_empty
begin_include
include|#
directive|include
file|<private/qapplication_p.h>
end_include
begin_include
include|#
directive|include
file|<private/qbackingstore_p.h>
end_include
begin_enum
DECL|enumerator|QtMacCustomizeWindow
enum|enum
block|{
name|QtMacCustomizeWindow
init|=
literal|1
operator|<<
literal|21
block|}
enum|;
end_enum
begin_comment
DECL|enumerator|QtMacCustomizeWindow
comment|// This will one day be run over by
end_comment
begin_expr_stmt
DECL|variable|QWidget
name|QT_FORWARD_DECLARE_CLASS
argument_list|(
name|QWidget
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
DECL|variable|QStringList
name|QT_FORWARD_DECLARE_CLASS
argument_list|(
name|QStringList
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
DECL|variable|QCocoaDropData
name|QT_FORWARD_DECLARE_CLASS
argument_list|(
name|QCocoaDropData
argument_list|)
expr_stmt|;
end_expr_stmt
begin_decl_stmt
DECL|variable|QCocoaDropData
unit|@
name|interface
name|NSWindow
argument_list|(
name|QtCoverForHackWithCategory
argument_list|)
decl|+
argument_list|(
name|Class
argument_list|)
name|frameViewClassForStyleMask
range|:
operator|(
name|NSUInteger
operator|)
name|styleMask
decl_stmt|;
end_decl_stmt
begin_expr_stmt
unit|@
name|end
expr|@
name|interface
name|NSWindow
argument_list|(
name|QT_MANGLE_NAMESPACE
argument_list|(
name|QWidgetIntegration
argument_list|)
argument_list|)
operator|-
operator|(
name|id
operator|)
name|QT_MANGLE_NAMESPACE
argument_list|(
name|qt_initWithQWidget
argument_list|)
operator|:
operator|(
name|QWidget
operator|*
operator|)
name|widget
name|contentRect
operator|:
operator|(
name|NSRect
operator|)
name|rect
name|styleMask
operator|:
operator|(
name|NSUInteger
operator|)
name|mask
expr_stmt|;
end_expr_stmt
begin_expr_stmt
operator|-
operator|(
name|QWidget
operator|*
operator|)
name|QT_MANGLE_NAMESPACE
argument_list|(
name|qt_qwidget
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
unit|@
name|end
expr|@
name|interface
name|NSWindow
argument_list|(
name|QtIntegration
argument_list|)
operator|-
operator|(
name|NSDragOperation
operator|)
name|draggingEntered
operator|:
operator|(
name|id
operator|<
name|NSDraggingInfo
operator|>
operator|)
name|sender
expr_stmt|;
end_expr_stmt
begin_expr_stmt
operator|-
operator|(
name|NSDragOperation
operator|)
name|draggingUpdated
operator|:
operator|(
name|id
operator|<
name|NSDraggingInfo
operator|>
operator|)
name|sender
expr_stmt|;
end_expr_stmt
begin_expr_stmt
operator|-
operator|(
name|void
operator|)
name|draggingExited
operator|:
operator|(
name|id
operator|<
name|NSDraggingInfo
operator|>
operator|)
name|sender
expr_stmt|;
end_expr_stmt
begin_expr_stmt
operator|-
operator|(
name|BOOL
operator|)
name|performDragOperation
operator|:
operator|(
name|id
operator|<
name|NSDraggingInfo
operator|>
operator|)
name|sender
expr_stmt|;
end_expr_stmt
begin_expr_stmt
unit|@
name|end
expr|@
DECL|function|QT_MANGLE_NAMESPACE
name|interface
name|QT_MANGLE_NAMESPACE
argument_list|(
name|QCocoaWindow
argument_list|)
operator|:
name|NSWindow
block|{
name|QStringList
operator|*
name|currentCustomDragTypes
block|;
name|QCocoaDropData
operator|*
name|dropData
block|;
name|NSInteger
name|dragEnterSequence
block|; }
operator|+
operator|(
name|Class
operator|)
name|frameViewClassForStyleMask
operator|:
operator|(
name|NSUInteger
operator|)
name|styleMask
expr_stmt|;
end_expr_stmt
begin_expr_stmt
operator|-
operator|(
name|void
operator|)
name|registerDragTypes
expr_stmt|;
end_expr_stmt
begin_expr_stmt
operator|-
operator|(
name|void
operator|)
name|drawRectOriginal
operator|:
operator|(
name|NSRect
operator|)
name|rect
expr_stmt|;
end_expr_stmt
begin_macro
unit|@
name|end
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_endif
endif|#
directive|endif
end_endif
end_unit
