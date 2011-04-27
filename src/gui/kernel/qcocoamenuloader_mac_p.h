begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** No Commercial Usage ** This file contains pre-release code and may not be distributed. ** You may use this file in accordance with the terms and conditions ** contained in the Technology Preview License Agreement accompanying ** this package. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights.  These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** If you have questions regarding the use of this file, please contact ** Nokia at qt-info@nokia.com. ** ** ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QCOCOAMENULOADER_P_H
end_ifndef
begin_define
DECL|macro|QCOCOAMENULOADER_P_H
define|#
directive|define
name|QCOCOAMENULOADER_P_H
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
comment|// of qapplication_*.cpp, qwidget*.cpp and qfiledialog.cpp.  This header
end_comment
begin_comment
comment|// file may change from version to version without notice, or even be removed.
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
begin_ifdef
ifdef|#
directive|ifdef
name|QT_MAC_USE_COCOA
end_ifdef
begin_empty
empty|#import<Cocoa/Cocoa.h>
end_empty
begin_macro
unit|@
DECL|function|QT_MANGLE_NAMESPACE
name|interface
end_macro
begin_expr_stmt
DECL|function|QT_MANGLE_NAMESPACE
name|QT_MANGLE_NAMESPACE
argument_list|(
name|QCocoaMenuLoader
argument_list|)
operator|:
name|NSResponder
block|{
name|IBOutlet
name|NSMenu
operator|*
name|theMenu
block|;
name|IBOutlet
name|NSMenu
operator|*
name|appMenu
block|;
name|IBOutlet
name|NSMenuItem
operator|*
name|quitItem
block|;
name|IBOutlet
name|NSMenuItem
operator|*
name|preferencesItem
block|;
name|IBOutlet
name|NSMenuItem
operator|*
name|aboutItem
block|;
name|IBOutlet
name|NSMenuItem
operator|*
name|aboutQtItem
block|;
name|IBOutlet
name|NSMenuItem
operator|*
name|hideItem
block|;
name|NSMenuItem
operator|*
name|lastAppSpecificItem
block|;
name|NSMenuItem
operator|*
name|servicesItem
block|;
name|NSMenuItem
operator|*
name|hideAllOthersItem
block|;
name|NSMenuItem
operator|*
name|showAllItem
block|; }
operator|-
operator|(
name|void
operator|)
name|ensureAppMenuInMenu
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
name|removeActionsFromAppMenu
expr_stmt|;
end_expr_stmt
begin_expr_stmt
operator|-
operator|(
name|NSMenu
operator|*
operator|)
name|applicationMenu
expr_stmt|;
end_expr_stmt
begin_expr_stmt
operator|-
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
name|NSMenuItem
operator|*
operator|)
name|quitMenuItem
expr_stmt|;
end_expr_stmt
begin_expr_stmt
operator|-
operator|(
name|NSMenuItem
operator|*
operator|)
name|preferencesMenuItem
expr_stmt|;
end_expr_stmt
begin_expr_stmt
operator|-
operator|(
name|NSMenuItem
operator|*
operator|)
name|aboutMenuItem
expr_stmt|;
end_expr_stmt
begin_expr_stmt
operator|-
operator|(
name|NSMenuItem
operator|*
operator|)
name|aboutQtMenuItem
expr_stmt|;
end_expr_stmt
begin_expr_stmt
operator|-
operator|(
name|NSMenuItem
operator|*
operator|)
name|hideMenuItem
expr_stmt|;
end_expr_stmt
begin_expr_stmt
operator|-
operator|(
name|NSMenuItem
operator|*
operator|)
name|appSpecificMenuItem
expr_stmt|;
end_expr_stmt
begin_expr_stmt
operator|-
operator|(
name|IBAction
operator|)
name|terminate
operator|:
operator|(
name|id
operator|)
name|sender
expr_stmt|;
end_expr_stmt
begin_expr_stmt
operator|-
operator|(
name|IBAction
operator|)
name|orderFrontStandardAboutPanel
operator|:
operator|(
name|id
operator|)
name|sender
expr_stmt|;
end_expr_stmt
begin_expr_stmt
operator|-
operator|(
name|IBAction
operator|)
name|hideOtherApplications
operator|:
operator|(
name|id
operator|)
name|sender
expr_stmt|;
end_expr_stmt
begin_expr_stmt
operator|-
operator|(
name|IBAction
operator|)
name|unhideAllApplications
operator|:
operator|(
name|id
operator|)
name|sender
expr_stmt|;
end_expr_stmt
begin_expr_stmt
operator|-
operator|(
name|IBAction
operator|)
name|hide
operator|:
operator|(
name|id
operator|)
name|sender
expr_stmt|;
end_expr_stmt
begin_expr_stmt
operator|-
operator|(
name|IBAction
operator|)
name|qtDispatcherToQAction
operator|:
operator|(
name|id
operator|)
name|sender
expr_stmt|;
end_expr_stmt
begin_expr_stmt
operator|-
operator|(
name|void
operator|)
name|qtUpdateMenubar
expr_stmt|;
end_expr_stmt
begin_expr_stmt
operator|-
operator|(
name|void
operator|)
name|orderFrontCharacterPalette
operator|:
operator|(
name|id
operator|)
name|sender
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
begin_comment
comment|// QT_MAC_USE_COCOA
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QCOCOAMENULOADER_P_H
end_comment
end_unit
