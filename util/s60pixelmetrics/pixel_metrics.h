begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the utility applications of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** No Commercial Usage ** This file contains pre-release code and may not be distributed. ** You may use this file in accordance with the terms and conditions ** contained in the Technology Preview License Agreement accompanying ** this package. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights.  These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** If you have questions regarding the use of this file, please contact ** Nokia at qt-info@nokia.com. ** ** ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|PIXELMETRICS_H
end_ifndef
begin_define
DECL|macro|PIXELMETRICS_H
define|#
directive|define
name|PIXELMETRICS_H
end_define
begin_include
include|#
directive|include
file|<e32base.h>
end_include
begin_define
DECL|macro|S60_Rnd_Env
define|#
directive|define
name|S60_Rnd_Env
end_define
begin_ifdef
ifdef|#
directive|ifdef
name|S60_Rnd_Env
end_ifdef
begin_pragma
pragma|#
directive|pragma
name|message
name|(
literal|"Building in supported environment"
name|)
end_pragma
begin_decl_stmt
DECL|variable|KUnknownBase
specifier|const
name|TInt
name|KUnknownBase
init|=
operator|-
literal|5000
decl_stmt|;
end_decl_stmt
begin_macro
DECL|function|NONSHARABLE_CLASS
name|NONSHARABLE_CLASS
argument_list|(
argument|QStyle
argument_list|)
end_macro
begin_block
block|{
name|public
label|:
enum|enum
name|PixelMetric
block|{
name|PM_ButtonMargin
block|,
name|PM_ButtonDefaultIndicator
block|,
name|PM_MenuButtonIndicator
block|,
name|PM_ButtonShiftHorizontal
block|,
name|PM_ButtonShiftVertical
block|,
name|PM_DefaultFrameWidth
block|,
name|PM_SpinBoxFrameWidth
block|,
name|PM_ComboBoxFrameWidth
block|,
name|PM_MaximumDragDistance
block|,
name|PM_ScrollBarExtent
block|,
name|PM_ScrollBarSliderMin
block|,
name|PM_SliderThickness
block|,
comment|// total slider thickness
name|PM_SliderControlThickness
block|,
comment|// thickness of the business part
name|PM_SliderLength
block|,
comment|// total length of slider
name|PM_SliderTickmarkOffset
block|,
comment|//
name|PM_SliderSpaceAvailable
block|,
comment|// available space for slider to move
name|PM_DockWidgetSeparatorExtent
block|,
name|PM_DockWidgetHandleExtent
block|,
name|PM_DockWidgetFrameWidth
block|,
name|PM_TabBarTabOverlap
block|,
name|PM_TabBarTabHSpace
block|,
name|PM_TabBarTabVSpace
block|,
name|PM_TabBarBaseHeight
block|,
name|PM_TabBarBaseOverlap
block|,
name|PM_ProgressBarChunkWidth
block|,
name|PM_SplitterWidth
block|,
name|PM_TitleBarHeight
block|,
name|PM_MenuScrollerHeight
block|,
name|PM_MenuHMargin
block|,
name|PM_MenuVMargin
block|,
name|PM_MenuPanelWidth
block|,
name|PM_MenuTearoffHeight
block|,
name|PM_MenuDesktopFrameWidth
block|,
name|PM_MenuBarPanelWidth
block|,
name|PM_MenuBarItemSpacing
block|,
name|PM_MenuBarVMargin
block|,
name|PM_MenuBarHMargin
block|,
name|PM_IndicatorWidth
block|,
name|PM_IndicatorHeight
block|,
name|PM_ExclusiveIndicatorWidth
block|,
name|PM_ExclusiveIndicatorHeight
block|,
name|PM_CheckListButtonSize
block|,
name|PM_CheckListControllerSize
block|,
name|PM_DialogButtonsSeparator
block|,
name|PM_DialogButtonsButtonWidth
block|,
name|PM_DialogButtonsButtonHeight
block|,
name|PM_MdiSubWindowFrameWidth
block|,
name|PM_MDIFrameWidth
init|=
name|PM_MdiSubWindowFrameWidth
block|,
comment|//obsolete
name|PM_MdiSubWindowMinimizedWidth
block|,
name|PM_MDIMinimizedWidth
init|=
name|PM_MdiSubWindowMinimizedWidth
block|,
comment|//obsolete
name|PM_HeaderMargin
block|,
name|PM_HeaderMarkSize
block|,
name|PM_HeaderGripMargin
block|,
name|PM_TabBarTabShiftHorizontal
block|,
name|PM_TabBarTabShiftVertical
block|,
name|PM_TabBarScrollButtonWidth
block|,
name|PM_ToolBarFrameWidth
block|,
name|PM_ToolBarHandleExtent
block|,
name|PM_ToolBarItemSpacing
block|,
name|PM_ToolBarItemMargin
block|,
name|PM_ToolBarSeparatorExtent
block|,
name|PM_ToolBarExtensionExtent
block|,
name|PM_SpinBoxSliderHeight
block|,
name|PM_DefaultTopLevelMargin
block|,
name|PM_DefaultChildMargin
block|,
name|PM_DefaultLayoutSpacing
block|,
name|PM_ToolBarIconSize
block|,
name|PM_ListViewIconSize
block|,
name|PM_IconViewIconSize
block|,
name|PM_SmallIconSize
block|,
name|PM_LargeIconSize
block|,
name|PM_FocusFrameVMargin
block|,
name|PM_FocusFrameHMargin
block|,
name|PM_ToolTipLabelFrameWidth
block|,
name|PM_CheckBoxLabelSpacing
block|,
name|PM_TabBarIconSize
block|,
name|PM_SizeGripSize
block|,
name|PM_DockWidgetTitleMargin
block|,
name|PM_MessageBoxIconSize
block|,
name|PM_ButtonIconSize
block|,
name|PM_DockWidgetTitleBarButtonMargin
block|,
name|PM_RadioButtonLabelSpacing
block|,
name|PM_LayoutLeftMargin
block|,
name|PM_LayoutTopMargin
block|,
name|PM_LayoutRightMargin
block|,
name|PM_LayoutBottomMargin
block|,
name|PM_LayoutHorizontalSpacing
block|,
name|PM_LayoutVerticalSpacing
block|,
name|PM_TabBar_ScrollButtonOverlap
block|,
name|PM_TextCursorWidth
block|,
name|PM_TabCloseIndicatorWidth
block|,
name|PM_TabCloseIndicatorHeight
block|,
name|PM_ScrollView_ScrollBarSpacing
block|,
name|PM_SubMenuOverlap
block|,
comment|// do not add any values below/greater than this
name|PM_CustomBase
init|=
literal|0xf0000000
block|,
comment|// The following are custom values needed to draw the S60Style according scalable UIs.
comment|// Width of 9-part frame-corner
name|PM_Custom_FrameCornerWidth
block|,
comment|// Height of 9-part frame corner
name|PM_Custom_FrameCornerHeight
block|,
comment|// Bold line width
name|PM_Custom_BoldLineWidth
block|,
comment|// Thin line width
name|PM_Custom_ThinLineWidth
block|,
comment|// Height of a popup info messagebox
name|PM_Custom_MessageBoxHeight
block|}
enum|;
block|}
end_block
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_else
else|#
directive|else
end_else
begin_pragma
pragma|#
directive|pragma
name|message
name|(
literal|"Building in non-supported environment, this probably fails"
name|)
end_pragma
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// Pixel metrics version information.
end_comment
begin_decl_stmt
name|class
name|TPixelMetricsVersion
block|{
name|public
label|:
name|TInt
name|majorVersion
decl_stmt|;
name|TInt
name|minorVersion
decl_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_macro
DECL|function|NONSHARABLE_CLASS
name|NONSHARABLE_CLASS
argument_list|(
argument|PixelMetrics
argument_list|)
end_macro
begin_block
block|{
name|public
label|:
specifier|static
name|TPixelMetricsVersion
name|Version
parameter_list|()
function_decl|;
specifier|static
name|TInt
name|PixelMetricValue
argument_list|(
name|QStyle
operator|::
name|PixelMetric
argument_list|)
decl_stmt|;
name|private
label|:
specifier|static
name|TInt
name|PixelMetricMenuValue
argument_list|(
name|QStyle
operator|::
name|PixelMetric
name|menuValue
argument_list|,
name|TRect
name|mainPaneRect
argument_list|)
decl_stmt|;
specifier|static
name|TInt
name|PixelMetricTabValue
argument_list|(
name|QStyle
operator|::
name|PixelMetric
name|tabValue
argument_list|,
name|TRect
name|appWindow
argument_list|,
name|TBool
name|landscape
argument_list|)
decl_stmt|;
block|}
end_block
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// PIXELMETRICS_H
end_comment
end_unit
