begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtWidgets module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QWINDOWSVISTASTYLE_P_P_H
end_ifndef
begin_define
DECL|macro|QWINDOWSVISTASTYLE_P_P_H
define|#
directive|define
name|QWINDOWSVISTASTYLE_P_P_H
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
file|"qwindowsvistastyle_p.h"
end_include
begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|QT_NO_STYLE_WINDOWSVISTA
argument_list|)
end_if
begin_include
include|#
directive|include
file|<private/qwindowsxpstyle_p_p.h>
end_include
begin_include
include|#
directive|include
file|<private/qstyleanimation_p.h>
end_include
begin_include
include|#
directive|include
file|<private/qpaintengine_raster_p.h>
end_include
begin_include
include|#
directive|include
file|<qlibrary.h>
end_include
begin_include
include|#
directive|include
file|<qpaintengine.h>
end_include
begin_include
include|#
directive|include
file|<qwidget.h>
end_include
begin_include
include|#
directive|include
file|<qapplication.h>
end_include
begin_include
include|#
directive|include
file|<qpixmapcache.h>
end_include
begin_include
include|#
directive|include
file|<qstyleoption.h>
end_include
begin_include
include|#
directive|include
file|<qpushbutton.h>
end_include
begin_include
include|#
directive|include
file|<qradiobutton.h>
end_include
begin_include
include|#
directive|include
file|<qcheckbox.h>
end_include
begin_include
include|#
directive|include
file|<qlineedit.h>
end_include
begin_include
include|#
directive|include
file|<qgroupbox.h>
end_include
begin_include
include|#
directive|include
file|<qtoolbutton.h>
end_include
begin_include
include|#
directive|include
file|<qspinbox.h>
end_include
begin_include
include|#
directive|include
file|<qtoolbar.h>
end_include
begin_include
include|#
directive|include
file|<qcombobox.h>
end_include
begin_include
include|#
directive|include
file|<qscrollbar.h>
end_include
begin_include
include|#
directive|include
file|<qprogressbar.h>
end_include
begin_include
include|#
directive|include
file|<qdockwidget.h>
end_include
begin_include
include|#
directive|include
file|<qlistview.h>
end_include
begin_include
include|#
directive|include
file|<qtreeview.h>
end_include
begin_include
include|#
directive|include
file|<qtextedit.h>
end_include
begin_include
include|#
directive|include
file|<qmessagebox.h>
end_include
begin_include
include|#
directive|include
file|<qdialogbuttonbox.h>
end_include
begin_include
include|#
directive|include
file|<qinputdialog.h>
end_include
begin_include
include|#
directive|include
file|<qtableview.h>
end_include
begin_include
include|#
directive|include
file|<qdatetime.h>
end_include
begin_include
include|#
directive|include
file|<qcommandlinkbutton.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
if|#
directive|if
operator|!
name|defined
argument_list|(
name|SCHEMA_VERIFY_VSSYM32
argument_list|)
DECL|macro|TMT_ANIMATIONDURATION
define|#
directive|define
name|TMT_ANIMATIONDURATION
value|5006
DECL|macro|TMT_TRANSITIONDURATIONS
define|#
directive|define
name|TMT_TRANSITIONDURATIONS
value|6000
DECL|macro|EP_EDITBORDER_NOSCROLL
define|#
directive|define
name|EP_EDITBORDER_NOSCROLL
value|6
DECL|macro|EP_EDITBORDER_HVSCROLL
define|#
directive|define
name|EP_EDITBORDER_HVSCROLL
value|9
DECL|macro|EP_BACKGROUND
define|#
directive|define
name|EP_BACKGROUND
value|3
DECL|macro|EBS_NORMAL
define|#
directive|define
name|EBS_NORMAL
value|1
DECL|macro|EBS_HOT
define|#
directive|define
name|EBS_HOT
value|2
DECL|macro|EBS_DISABLED
define|#
directive|define
name|EBS_DISABLED
value|3
DECL|macro|EBS_READONLY
define|#
directive|define
name|EBS_READONLY
value|5
DECL|macro|PBS_DEFAULTED_ANIMATING
define|#
directive|define
name|PBS_DEFAULTED_ANIMATING
value|6
DECL|macro|MBI_NORMAL
define|#
directive|define
name|MBI_NORMAL
value|1
DECL|macro|MBI_HOT
define|#
directive|define
name|MBI_HOT
value|2
DECL|macro|MBI_PUSHED
define|#
directive|define
name|MBI_PUSHED
value|3
DECL|macro|MBI_DISABLED
define|#
directive|define
name|MBI_DISABLED
value|4
DECL|macro|MB_ACTIVE
define|#
directive|define
name|MB_ACTIVE
value|1
DECL|macro|MB_INACTIVE
define|#
directive|define
name|MB_INACTIVE
value|2
DECL|macro|PP_FILL
define|#
directive|define
name|PP_FILL
value|5
DECL|macro|PP_FILLVERT
define|#
directive|define
name|PP_FILLVERT
value|6
DECL|macro|PP_MOVEOVERLAY
define|#
directive|define
name|PP_MOVEOVERLAY
value|8
DECL|macro|PP_MOVEOVERLAYVERT
define|#
directive|define
name|PP_MOVEOVERLAYVERT
value|10
DECL|macro|MENU_BARBACKGROUND
define|#
directive|define
name|MENU_BARBACKGROUND
value|7
DECL|macro|MENU_BARITEM
define|#
directive|define
name|MENU_BARITEM
value|8
DECL|macro|MENU_POPUPCHECK
define|#
directive|define
name|MENU_POPUPCHECK
value|11
DECL|macro|MENU_POPUPCHECKBACKGROUND
define|#
directive|define
name|MENU_POPUPCHECKBACKGROUND
value|12
DECL|macro|MENU_POPUPGUTTER
define|#
directive|define
name|MENU_POPUPGUTTER
value|13
DECL|macro|MENU_POPUPITEM
define|#
directive|define
name|MENU_POPUPITEM
value|14
DECL|macro|MENU_POPUPBORDERS
define|#
directive|define
name|MENU_POPUPBORDERS
value|10
DECL|macro|MENU_POPUPSEPARATOR
define|#
directive|define
name|MENU_POPUPSEPARATOR
value|15
DECL|macro|MC_CHECKMARKNORMAL
define|#
directive|define
name|MC_CHECKMARKNORMAL
value|1
DECL|macro|MC_CHECKMARKDISABLED
define|#
directive|define
name|MC_CHECKMARKDISABLED
value|2
DECL|macro|MC_BULLETNORMAL
define|#
directive|define
name|MC_BULLETNORMAL
value|3
DECL|macro|MC_BULLETDISABLED
define|#
directive|define
name|MC_BULLETDISABLED
value|4
DECL|macro|ABS_UPHOVER
define|#
directive|define
name|ABS_UPHOVER
value|17
DECL|macro|ABS_DOWNHOVER
define|#
directive|define
name|ABS_DOWNHOVER
value|18
DECL|macro|ABS_LEFTHOVER
define|#
directive|define
name|ABS_LEFTHOVER
value|19
DECL|macro|ABS_RIGHTHOVER
define|#
directive|define
name|ABS_RIGHTHOVER
value|20
DECL|macro|CP_DROPDOWNBUTTONRIGHT
define|#
directive|define
name|CP_DROPDOWNBUTTONRIGHT
value|6
DECL|macro|CP_DROPDOWNBUTTONLEFT
define|#
directive|define
name|CP_DROPDOWNBUTTONLEFT
value|7
DECL|macro|SCRBS_HOVER
define|#
directive|define
name|SCRBS_HOVER
value|5
DECL|macro|TVP_HOTGLYPH
define|#
directive|define
name|TVP_HOTGLYPH
value|4
DECL|macro|SPI_GETCLIENTAREAANIMATION
define|#
directive|define
name|SPI_GETCLIENTAREAANIMATION
value|0x1042
DECL|macro|TDLG_PRIMARYPANEL
define|#
directive|define
name|TDLG_PRIMARYPANEL
value|1
DECL|macro|TDLG_SECONDARYPANEL
define|#
directive|define
name|TDLG_SECONDARYPANEL
value|8
endif|#
directive|endif
name|class
name|QWindowsVistaAnimation
range|:
name|public
name|QBlendStyleAnimation
block|{
name|Q_OBJECT
name|public
operator|:
name|QWindowsVistaAnimation
argument_list|(
argument|Type type
argument_list|,
argument|QObject *target
argument_list|)
operator|:
name|QBlendStyleAnimation
argument_list|(
argument|type
argument_list|,
argument|target
argument_list|)
block|{ }
name|virtual
name|bool
name|isUpdateNeeded
argument_list|()
specifier|const
block|;
name|void
name|paint
argument_list|(
name|QPainter
operator|*
name|painter
argument_list|,
specifier|const
name|QStyleOption
operator|*
name|option
argument_list|)
block|; }
decl_stmt|;
end_decl_stmt
begin_comment
comment|// Handles state transition animations
end_comment
begin_decl_stmt
name|class
name|QWindowsVistaTransition
range|:
name|public
name|QWindowsVistaAnimation
block|{
name|Q_OBJECT
name|public
operator|:
name|QWindowsVistaTransition
argument_list|(
name|QObject
operator|*
name|target
argument_list|)
operator|:
name|QWindowsVistaAnimation
argument_list|(
argument|Transition
argument_list|,
argument|target
argument_list|)
block|{}
block|}
decl_stmt|;
end_decl_stmt
begin_comment
comment|// Handles pulse animations (default buttons)
end_comment
begin_decl_stmt
name|class
name|QWindowsVistaPulse
range|:
name|public
name|QWindowsVistaAnimation
block|{
name|Q_OBJECT
name|public
operator|:
name|QWindowsVistaPulse
argument_list|(
name|QObject
operator|*
name|target
argument_list|)
operator|:
name|QWindowsVistaAnimation
argument_list|(
argument|Pulse
argument_list|,
argument|target
argument_list|)
block|{}
block|}
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QWindowsVistaStylePrivate
range|:
name|public
name|QWindowsXPStylePrivate
block|{
name|Q_DECLARE_PUBLIC
argument_list|(
argument|QWindowsVistaStyle
argument_list|)
name|public
operator|:
name|QWindowsVistaStylePrivate
argument_list|()
block|;
operator|~
name|QWindowsVistaStylePrivate
argument_list|()
block|;
specifier|static
specifier|inline
name|bool
name|useVista
argument_list|()
block|;
name|bool
name|transitionsEnabled
argument_list|()
specifier|const
block|;
name|private
operator|:
name|bool
name|initTreeViewTheming
argument_list|()
block|;
name|void
name|cleanupTreeViewTheming
argument_list|()
block|;
name|HWND
name|m_treeViewHelper
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
comment|// QT_NO_STYLE_WINDOWSVISTA
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QWINDOWSVISTASTYLE_P_P_H
end_comment
end_unit
