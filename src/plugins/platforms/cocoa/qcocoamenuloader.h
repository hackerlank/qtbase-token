begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
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
begin_empty
empty|#import<AppKit/AppKit.h>
end_empty
begin_include
include|#
directive|include
file|<QtCore/private/qcore_mac_p.h>
end_include
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
operator|:
operator|(
name|NSInteger
operator|)
name|tag
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
name|qtDispatcherToQPAMenuItem
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
name|orderFrontCharacterPalette
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
name|BOOL
operator|)
name|validateMenuItem
operator|:
operator|(
name|NSMenuItem
operator|*
operator|)
name|menuItem
expr_stmt|;
end_expr_stmt
begin_expr_stmt
operator|-
operator|(
name|void
operator|)
name|qtTranslateApplicationMenu
expr_stmt|;
end_expr_stmt
begin_expr_stmt
operator|-
operator|(
name|NSArray
operator|*
operator|)
name|mergeable
expr_stmt|;
end_expr_stmt
begin_function_decl
unit|@
name|end
name|QT_NAMESPACE_ALIAS_OBJC_CLASS
parameter_list|(
name|QCocoaMenuLoader
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|QT_BEGIN_NAMESPACE
name|void
name|qt_mac_loadMenuNib
parameter_list|(
name|QCocoaMenuLoader
modifier|*
name|qtMenuLoader
parameter_list|)
function_decl|;
end_function_decl
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QCOCOAMENULOADER_P_H
end_comment
end_unit
