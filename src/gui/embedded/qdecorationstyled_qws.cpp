begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** No Commercial Usage ** This file contains pre-release code and may not be distributed. ** You may use this file in accordance with the terms and conditions ** contained in the Technology Preview License Agreement accompanying ** this package. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights.  These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** If you have questions regarding the use of this file, please contact ** Nokia at qt-info@nokia.com. ** ** ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<qapplication.h>
end_include
begin_include
include|#
directive|include
file|<qwidget.h>
end_include
begin_include
include|#
directive|include
file|<qpainter.h>
end_include
begin_include
include|#
directive|include
file|<qdrawutil.h>
end_include
begin_include
include|#
directive|include
file|"qdecorationstyled_qws.h"
end_include
begin_include
include|#
directive|include
file|"qstyle.h"
end_include
begin_include
include|#
directive|include
file|"qstyleoption.h"
end_include
begin_include
include|#
directive|include
file|"qpaintengine.h"
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|QT_NO_QWS_DECORATION_STYLED
argument_list|)
operator|||
name|defined
argument_list|(
name|QT_PLUGIN
argument_list|)
end_if
begin_constructor
DECL|function|QDecorationStyled
name|QDecorationStyled
operator|::
name|QDecorationStyled
parameter_list|()
member_init_list|:
name|QDecorationDefault
argument_list|()
block|{ }
end_constructor
begin_destructor
DECL|function|~QDecorationStyled
name|QDecorationStyled
operator|::
name|~
name|QDecorationStyled
parameter_list|()
block|{ }
end_destructor
begin_function
DECL|function|titleBarHeight
name|int
name|QDecorationStyled
operator|::
name|titleBarHeight
parameter_list|(
specifier|const
name|QWidget
modifier|*
name|widget
parameter_list|)
block|{
name|QStyleOptionTitleBar
name|opt
decl_stmt|;
name|opt
operator|.
name|subControls
operator|=
name|QStyle
operator|::
name|SC_TitleBarLabel
operator||
name|QStyle
operator|::
name|SC_TitleBarSysMenu
operator||
name|QStyle
operator|::
name|SC_TitleBarNormalButton
operator||
name|QStyle
operator|::
name|SC_TitleBarContextHelpButton
operator||
name|QStyle
operator|::
name|SC_TitleBarMinButton
operator||
name|QStyle
operator|::
name|SC_TitleBarMaxButton
operator||
name|QStyle
operator|::
name|SC_TitleBarCloseButton
expr_stmt|;
name|opt
operator|.
name|titleBarFlags
operator|=
name|widget
operator|->
name|windowFlags
argument_list|()
expr_stmt|;
name|opt
operator|.
name|direction
operator|=
name|QApplication
operator|::
name|layoutDirection
argument_list|()
expr_stmt|;
name|opt
operator|.
name|text
operator|=
name|windowTitleFor
argument_list|(
name|widget
argument_list|)
expr_stmt|;
name|opt
operator|.
name|icon
operator|=
name|widget
operator|->
name|windowIcon
argument_list|()
expr_stmt|;
name|opt
operator|.
name|rect
operator|=
name|widget
operator|->
name|rect
argument_list|()
expr_stmt|;
name|QStyle
modifier|*
name|style
init|=
name|QApplication
operator|::
name|style
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
name|style
condition|)
return|return
literal|18
return|;
return|return
name|style
operator|->
name|pixelMetric
argument_list|(
name|QStyle
operator|::
name|PM_TitleBarHeight
argument_list|,
operator|&
name|opt
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|paint
name|bool
name|QDecorationStyled
operator|::
name|paint
parameter_list|(
name|QPainter
modifier|*
name|painter
parameter_list|,
specifier|const
name|QWidget
modifier|*
name|widget
parameter_list|,
name|int
name|decorationRegion
parameter_list|,
name|DecorationState
name|state
parameter_list|)
block|{
if|if
condition|(
name|decorationRegion
operator|==
name|None
condition|)
return|return
literal|false
return|;
name|bool
name|isActive
init|=
operator|(
name|widget
operator|==
name|qApp
operator|->
name|activeWindow
argument_list|()
operator|)
decl_stmt|;
name|QPalette
name|pal
init|=
name|qApp
operator|->
name|palette
argument_list|()
decl_stmt|;
comment|//ideally, the difference between Active and Inactive should be enough, so we shouldn't need to test this
if|if
condition|(
operator|!
name|isActive
condition|)
block|{
comment|//pal.setCurrentColorGroup(QPalette::Disabled); //Can't do this either, because of palette limitations
comment|//copied from Q3TitleBar:
name|pal
operator|.
name|setColor
argument_list|(
name|QPalette
operator|::
name|Inactive
argument_list|,
name|QPalette
operator|::
name|Highlight
argument_list|,
name|pal
operator|.
name|color
argument_list|(
name|QPalette
operator|::
name|Inactive
argument_list|,
name|QPalette
operator|::
name|Dark
argument_list|)
argument_list|)
expr_stmt|;
name|pal
operator|.
name|setColor
argument_list|(
name|QPalette
operator|::
name|Inactive
argument_list|,
name|QPalette
operator|::
name|Base
argument_list|,
name|pal
operator|.
name|color
argument_list|(
name|QPalette
operator|::
name|Inactive
argument_list|,
name|QPalette
operator|::
name|Dark
argument_list|)
argument_list|)
expr_stmt|;
name|pal
operator|.
name|setColor
argument_list|(
name|QPalette
operator|::
name|Inactive
argument_list|,
name|QPalette
operator|::
name|HighlightedText
argument_list|,
name|pal
operator|.
name|color
argument_list|(
name|QPalette
operator|::
name|Inactive
argument_list|,
name|QPalette
operator|::
name|Window
argument_list|)
argument_list|)
expr_stmt|;
block|}
name|Qt
operator|::
name|WindowFlags
name|flags
init|=
name|widget
operator|->
name|windowFlags
argument_list|()
decl_stmt|;
name|bool
name|hasBorder
init|=
operator|!
name|widget
operator|->
name|isMaximized
argument_list|()
decl_stmt|;
name|bool
name|hasTitle
init|=
name|flags
operator|&
name|Qt
operator|::
name|WindowTitleHint
decl_stmt|;
name|bool
name|hasSysMenu
init|=
name|flags
operator|&
name|Qt
operator|::
name|WindowSystemMenuHint
decl_stmt|;
name|bool
name|hasContextHelp
init|=
name|flags
operator|&
name|Qt
operator|::
name|WindowContextHelpButtonHint
decl_stmt|;
name|bool
name|hasMinimize
init|=
name|flags
operator|&
name|Qt
operator|::
name|WindowMinimizeButtonHint
decl_stmt|;
name|bool
name|hasMaximize
init|=
name|flags
operator|&
name|Qt
operator|::
name|WindowMaximizeButtonHint
decl_stmt|;
name|bool
name|paintAll
init|=
operator|(
name|DecorationRegion
argument_list|(
name|decorationRegion
argument_list|)
operator|==
name|All
operator|)
decl_stmt|;
name|bool
name|handled
init|=
literal|false
decl_stmt|;
name|QStyle
modifier|*
name|style
init|=
name|QApplication
operator|::
name|style
argument_list|()
decl_stmt|;
comment|// In the case of a borderless title bar, the title bar must be expanded one
comment|// borderWidth to the left, right and up.
name|bool
name|noTitleBorder
init|=
name|style
operator|->
name|styleHint
argument_list|(
name|QStyle
operator|::
name|SH_TitleBar_NoBorder
argument_list|,
literal|0
argument_list|,
name|widget
argument_list|)
decl_stmt|;
name|int
name|borderWidth
init|=
name|style
operator|->
name|pixelMetric
argument_list|(
name|QStyle
operator|::
name|PM_MDIFrameWidth
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
decl_stmt|;
name|int
name|titleHeight
init|=
name|titleBarHeight
argument_list|(
name|widget
argument_list|)
operator|+
operator|(
name|noTitleBorder
condition|?
name|borderWidth
else|:
literal|0
operator|)
decl_stmt|;
name|int
name|titleExtra
init|=
name|noTitleBorder
condition|?
name|borderWidth
else|:
literal|0
decl_stmt|;
if|if
condition|(
operator|(
name|paintAll
operator|||
name|decorationRegion
operator|&
name|Borders
operator|)
operator|&&
name|state
operator|==
name|Normal
operator|&&
name|hasBorder
condition|)
block|{
name|QRegion
name|newClip
init|=
name|painter
operator|->
name|clipRegion
argument_list|()
decl_stmt|;
if|if
condition|(
name|hasTitle
condition|)
block|{
comment|// reduce flicker
name|QRect
name|rect
argument_list|(
name|widget
operator|->
name|rect
argument_list|()
argument_list|)
decl_stmt|;
name|QRect
name|r
argument_list|(
name|rect
operator|.
name|left
argument_list|()
operator|-
name|titleExtra
argument_list|,
name|rect
operator|.
name|top
argument_list|()
operator|-
name|titleHeight
argument_list|,
name|rect
operator|.
name|width
argument_list|()
operator|+
literal|2
operator|*
name|titleExtra
argument_list|,
name|titleHeight
argument_list|)
decl_stmt|;
name|newClip
operator|-=
name|r
expr_stmt|;
block|}
if|if
condition|(
operator|!
name|newClip
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|QRect
name|br
init|=
name|QDecoration
operator|::
name|region
argument_list|(
name|widget
argument_list|)
operator|.
name|boundingRect
argument_list|()
decl_stmt|;
name|painter
operator|->
name|save
argument_list|()
expr_stmt|;
name|painter
operator|->
name|setClipRegion
argument_list|(
name|newClip
argument_list|)
expr_stmt|;
name|QStyleOptionFrame
name|opt
decl_stmt|;
name|opt
operator|.
name|palette
operator|=
name|pal
expr_stmt|;
name|opt
operator|.
name|rect
operator|=
name|br
expr_stmt|;
name|opt
operator|.
name|lineWidth
operator|=
name|borderWidth
expr_stmt|;
if|if
condition|(
name|isActive
condition|)
name|opt
operator|.
name|state
operator||=
name|QStyle
operator|::
name|State_Active
expr_stmt|;
name|bool
name|porterDuff
init|=
name|painter
operator|->
name|paintEngine
argument_list|()
operator|->
name|hasFeature
argument_list|(
name|QPaintEngine
operator|::
name|PorterDuff
argument_list|)
decl_stmt|;
if|if
condition|(
name|porterDuff
condition|)
name|painter
operator|->
name|setCompositionMode
argument_list|(
name|QPainter
operator|::
name|CompositionMode_Source
argument_list|)
expr_stmt|;
name|painter
operator|->
name|fillRect
argument_list|(
name|br
argument_list|,
name|pal
operator|.
name|window
argument_list|()
argument_list|)
expr_stmt|;
if|if
condition|(
name|porterDuff
condition|)
name|painter
operator|->
name|setCompositionMode
argument_list|(
name|QPainter
operator|::
name|CompositionMode_SourceOver
argument_list|)
expr_stmt|;
name|style
operator|->
name|drawPrimitive
argument_list|(
name|QStyle
operator|::
name|PE_FrameWindow
argument_list|,
operator|&
name|opt
argument_list|,
name|painter
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|painter
operator|->
name|restore
argument_list|()
expr_stmt|;
name|decorationRegion
operator|&=
operator|(
operator|~
name|Borders
operator|)
expr_stmt|;
name|handled
operator||=
literal|true
expr_stmt|;
block|}
block|}
if|if
condition|(
name|hasTitle
condition|)
block|{
name|painter
operator|->
name|save
argument_list|()
expr_stmt|;
name|QStyleOptionTitleBar
name|opt
decl_stmt|;
name|opt
operator|.
name|subControls
operator|=
operator|(
name|decorationRegion
operator|&
name|Title
condition|?
name|QStyle
operator|::
name|SC_TitleBarLabel
else|:
name|QStyle
operator|::
name|SubControl
argument_list|(
literal|0
argument_list|)
operator|)
operator||
operator|(
name|decorationRegion
operator|&
name|Menu
condition|?
name|QStyle
operator|::
name|SC_TitleBarSysMenu
else|:
name|QStyle
operator|::
name|SubControl
argument_list|(
literal|0
argument_list|)
operator|)
operator||
operator|(
name|decorationRegion
operator|&
name|Help
condition|?
name|QStyle
operator|::
name|SC_TitleBarContextHelpButton
else|:
name|QStyle
operator|::
name|SubControl
argument_list|(
literal|0
argument_list|)
operator|)
operator||
operator|(
name|decorationRegion
operator|&
name|Minimize
condition|?
name|QStyle
operator|::
name|SC_TitleBarMinButton
else|:
name|QStyle
operator|::
name|SubControl
argument_list|(
literal|0
argument_list|)
operator|)
operator||
operator|(
name|decorationRegion
operator|&
name|Maximize
condition|?
name|QStyle
operator|::
name|SC_TitleBarMaxButton
else|:
name|QStyle
operator|::
name|SubControl
argument_list|(
literal|0
argument_list|)
operator|)
operator||
operator|(
name|decorationRegion
operator|&
operator|(
name|Minimize
operator||
name|Maximize
operator|)
condition|?
name|QStyle
operator|::
name|SC_TitleBarNormalButton
else|:
name|QStyle
operator|::
name|SubControl
argument_list|(
literal|0
argument_list|)
operator|)
operator||
operator|(
name|decorationRegion
operator|&
name|Close
condition|?
name|QStyle
operator|::
name|SC_TitleBarCloseButton
else|:
name|QStyle
operator|::
name|SubControl
argument_list|(
literal|0
argument_list|)
operator|)
expr_stmt|;
name|opt
operator|.
name|titleBarFlags
operator|=
name|widget
operator|->
name|windowFlags
argument_list|()
expr_stmt|;
name|opt
operator|.
name|titleBarState
operator|=
name|widget
operator|->
name|windowState
argument_list|()
expr_stmt|;
if|if
condition|(
name|isActive
condition|)
name|opt
operator|.
name|titleBarState
operator||=
name|QStyle
operator|::
name|State_Active
expr_stmt|;
name|opt
operator|.
name|text
operator|=
name|windowTitleFor
argument_list|(
name|widget
argument_list|)
expr_stmt|;
name|opt
operator|.
name|icon
operator|=
name|widget
operator|->
name|windowIcon
argument_list|()
expr_stmt|;
name|opt
operator|.
name|palette
operator|=
name|pal
expr_stmt|;
name|opt
operator|.
name|rect
operator|=
name|QRect
argument_list|(
name|widget
operator|->
name|rect
argument_list|()
operator|.
name|x
argument_list|()
operator|-
name|titleExtra
argument_list|,
operator|-
name|titleHeight
argument_list|,
name|widget
operator|->
name|rect
argument_list|()
operator|.
name|width
argument_list|()
operator|+
literal|2
operator|*
name|titleExtra
argument_list|,
name|titleHeight
argument_list|)
expr_stmt|;
if|if
condition|(
name|paintAll
condition|)
block|{
name|painter
operator|->
name|setClipRegion
argument_list|(
name|opt
operator|.
name|rect
argument_list|)
expr_stmt|;
block|}
else|else
block|{
specifier|const
name|QRect
name|widgetRect
init|=
name|widget
operator|->
name|rect
argument_list|()
decl_stmt|;
name|QRegion
name|newClip
init|=
name|opt
operator|.
name|rect
decl_stmt|;
if|if
condition|(
operator|!
operator|(
name|decorationRegion
operator|&
name|Menu
operator|)
operator|&&
name|hasSysMenu
condition|)
name|newClip
operator|-=
name|region
argument_list|(
name|widget
argument_list|,
name|widgetRect
argument_list|,
name|Menu
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
operator|(
name|decorationRegion
operator|&
name|Title
operator|)
operator|&&
name|hasTitle
condition|)
name|newClip
operator|-=
name|region
argument_list|(
name|widget
argument_list|,
name|widgetRect
argument_list|,
name|Title
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
operator|(
name|decorationRegion
operator|&
name|Help
operator|)
operator|&&
name|hasContextHelp
condition|)
name|newClip
operator|-=
name|region
argument_list|(
name|widget
argument_list|,
name|widgetRect
argument_list|,
name|Help
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
operator|(
name|decorationRegion
operator|&
name|Minimize
operator|)
operator|&&
name|hasMinimize
condition|)
name|newClip
operator|-=
name|region
argument_list|(
name|widget
argument_list|,
name|widgetRect
argument_list|,
name|Minimize
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
operator|(
name|decorationRegion
operator|&
name|Maximize
operator|)
operator|&&
name|hasMaximize
condition|)
name|newClip
operator|-=
name|region
argument_list|(
name|widget
argument_list|,
name|widgetRect
argument_list|,
name|Maximize
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
operator|(
name|decorationRegion
operator|&
operator|(
name|Minimize
operator||
name|Maximize
operator|)
operator|)
operator|&&
operator|(
name|hasMaximize
operator||
name|hasMinimize
operator|)
condition|)
name|newClip
operator|-=
name|region
argument_list|(
name|widget
argument_list|,
name|widgetRect
argument_list|,
name|Normal
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
operator|(
name|decorationRegion
operator|&
name|Close
operator|)
condition|)
name|newClip
operator|-=
name|region
argument_list|(
name|widget
argument_list|,
name|widgetRect
argument_list|,
name|Close
argument_list|)
expr_stmt|;
name|painter
operator|->
name|setClipRegion
argument_list|(
name|newClip
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|state
operator|==
name|Pressed
condition|)
name|opt
operator|.
name|activeSubControls
operator|=
name|opt
operator|.
name|subControls
expr_stmt|;
name|style
operator|->
name|drawComplexControl
argument_list|(
name|QStyle
operator|::
name|CC_TitleBar
argument_list|,
operator|&
name|opt
argument_list|,
name|painter
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|painter
operator|->
name|restore
argument_list|()
expr_stmt|;
name|decorationRegion
operator|&=
operator|~
operator|(
name|Title
operator||
name|Menu
operator||
name|Help
operator||
name|Normalize
operator||
name|Minimize
operator||
name|Maximize
operator||
name|Close
operator|)
expr_stmt|;
name|handled
operator||=
literal|true
expr_stmt|;
block|}
return|return
name|handled
return|;
block|}
end_function
begin_function
DECL|function|region
name|QRegion
name|QDecorationStyled
operator|::
name|region
parameter_list|(
specifier|const
name|QWidget
modifier|*
name|widget
parameter_list|,
specifier|const
name|QRect
modifier|&
name|rect
parameter_list|,
name|int
name|decorationRegion
parameter_list|)
block|{
name|QStyle
modifier|*
name|style
init|=
name|QApplication
operator|::
name|style
argument_list|()
decl_stmt|;
comment|// In the case of a borderless title bar, the title bar must be expanded one
comment|// borderWidth to the left, right and up.
name|bool
name|noTitleBorder
init|=
name|style
operator|->
name|styleHint
argument_list|(
name|QStyle
operator|::
name|SH_TitleBar_NoBorder
argument_list|,
literal|0
argument_list|,
name|widget
argument_list|)
decl_stmt|;
name|int
name|borderWidth
init|=
name|style
operator|->
name|pixelMetric
argument_list|(
name|QStyle
operator|::
name|PM_MDIFrameWidth
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
decl_stmt|;
name|int
name|titleHeight
init|=
name|titleBarHeight
argument_list|(
name|widget
argument_list|)
operator|+
operator|(
name|noTitleBorder
condition|?
name|borderWidth
else|:
literal|0
operator|)
decl_stmt|;
name|int
name|titleExtra
init|=
name|noTitleBorder
condition|?
name|borderWidth
else|:
literal|0
decl_stmt|;
name|QRect
name|inside
init|=
name|QRect
argument_list|(
name|rect
operator|.
name|x
argument_list|()
operator|-
name|titleExtra
argument_list|,
name|rect
operator|.
name|top
argument_list|()
operator|-
name|titleHeight
argument_list|,
name|rect
operator|.
name|width
argument_list|()
operator|+
literal|2
operator|*
name|titleExtra
argument_list|,
name|titleHeight
argument_list|)
decl_stmt|;
name|Qt
operator|::
name|WindowFlags
name|flags
init|=
name|widget
operator|->
name|windowFlags
argument_list|()
decl_stmt|;
name|bool
name|hasSysMenu
init|=
name|flags
operator|&
name|Qt
operator|::
name|WindowSystemMenuHint
decl_stmt|;
name|bool
name|hasContextHelp
init|=
name|flags
operator|&
name|Qt
operator|::
name|WindowContextHelpButtonHint
decl_stmt|;
name|bool
name|hasMinimize
init|=
name|flags
operator|&
name|Qt
operator|::
name|WindowMinimizeButtonHint
decl_stmt|;
name|bool
name|hasMaximize
init|=
name|flags
operator|&
name|Qt
operator|::
name|WindowMaximizeButtonHint
decl_stmt|;
name|QStyleOptionTitleBar
name|opt
decl_stmt|;
name|opt
operator|.
name|subControls
operator|=
name|QStyle
operator|::
name|SC_TitleBarLabel
operator||
name|QStyle
operator|::
name|SC_TitleBarSysMenu
operator||
name|QStyle
operator|::
name|SC_TitleBarNormalButton
operator||
name|QStyle
operator|::
name|SC_TitleBarMinButton
operator||
name|QStyle
operator|::
name|SC_TitleBarMaxButton
operator||
name|QStyle
operator|::
name|SC_TitleBarCloseButton
expr_stmt|;
name|opt
operator|.
name|titleBarFlags
operator|=
name|widget
operator|->
name|windowFlags
argument_list|()
expr_stmt|;
name|opt
operator|.
name|direction
operator|=
name|QApplication
operator|::
name|layoutDirection
argument_list|()
expr_stmt|;
name|opt
operator|.
name|text
operator|=
name|windowTitleFor
argument_list|(
name|widget
argument_list|)
expr_stmt|;
name|opt
operator|.
name|icon
operator|=
name|widget
operator|->
name|windowIcon
argument_list|()
expr_stmt|;
name|opt
operator|.
name|rect
operator|=
name|inside
expr_stmt|;
name|QRegion
name|region
decl_stmt|;
switch|switch
condition|(
name|decorationRegion
condition|)
block|{
case|case
name|Title
case|:
name|region
operator|=
name|style
operator|->
name|subControlRect
argument_list|(
name|QStyle
operator|::
name|CC_TitleBar
argument_list|,
operator|&
name|opt
argument_list|,
name|QStyle
operator|::
name|SC_TitleBarLabel
argument_list|,
literal|0
argument_list|)
expr_stmt|;
break|break;
case|case
name|Menu
case|:
if|if
condition|(
name|hasSysMenu
condition|)
name|region
operator|=
name|style
operator|->
name|subControlRect
argument_list|(
name|QStyle
operator|::
name|CC_TitleBar
argument_list|,
operator|&
name|opt
argument_list|,
name|QStyle
operator|::
name|SC_TitleBarSysMenu
argument_list|,
literal|0
argument_list|)
expr_stmt|;
break|break;
case|case
name|Help
case|:
if|if
condition|(
name|hasContextHelp
condition|)
name|region
operator|=
name|style
operator|->
name|subControlRect
argument_list|(
name|QStyle
operator|::
name|CC_TitleBar
argument_list|,
operator|&
name|opt
argument_list|,
name|QStyle
operator|::
name|SC_TitleBarContextHelpButton
argument_list|,
literal|0
argument_list|)
expr_stmt|;
break|break;
case|case
name|Normalize
case|:
if|if
condition|(
name|hasMaximize
operator||
name|hasMinimize
condition|)
name|region
operator|=
name|style
operator|->
name|subControlRect
argument_list|(
name|QStyle
operator|::
name|CC_TitleBar
argument_list|,
operator|&
name|opt
argument_list|,
name|QStyle
operator|::
name|SC_TitleBarNormalButton
argument_list|,
literal|0
argument_list|)
expr_stmt|;
break|break;
case|case
name|Minimize
case|:
if|if
condition|(
name|hasMinimize
condition|)
name|region
operator|=
name|style
operator|->
name|subControlRect
argument_list|(
name|QStyle
operator|::
name|CC_TitleBar
argument_list|,
operator|&
name|opt
argument_list|,
name|QStyle
operator|::
name|SC_TitleBarMinButton
argument_list|,
literal|0
argument_list|)
expr_stmt|;
break|break;
case|case
name|Maximize
case|:
if|if
condition|(
name|hasMaximize
condition|)
name|region
operator|=
name|style
operator|->
name|subControlRect
argument_list|(
name|QStyle
operator|::
name|CC_TitleBar
argument_list|,
operator|&
name|opt
argument_list|,
name|QStyle
operator|::
name|SC_TitleBarMaxButton
argument_list|,
literal|0
argument_list|)
expr_stmt|;
break|break;
case|case
name|Close
case|:
name|region
operator|=
name|style
operator|->
name|subControlRect
argument_list|(
name|QStyle
operator|::
name|CC_TitleBar
argument_list|,
operator|&
name|opt
argument_list|,
name|QStyle
operator|::
name|SC_TitleBarCloseButton
argument_list|,
literal|0
argument_list|)
expr_stmt|;
break|break;
default|default:
name|region
operator|=
name|QDecorationDefault
operator|::
name|region
argument_list|(
name|widget
argument_list|,
name|rect
argument_list|,
name|decorationRegion
argument_list|)
expr_stmt|;
block|}
name|opt
operator|.
name|rect
operator|=
name|QRect
argument_list|(
name|rect
operator|.
name|x
argument_list|()
operator|-
name|titleExtra
argument_list|,
name|rect
operator|.
name|top
argument_list|()
operator|-
name|titleHeight
argument_list|,
name|rect
operator|.
name|width
argument_list|()
operator|+
literal|2
operator|*
name|titleExtra
argument_list|,
name|rect
operator|.
name|height
argument_list|()
operator|+
name|titleHeight
operator|+
name|titleExtra
argument_list|)
expr_stmt|;
name|QStyleHintReturnMask
name|mask
decl_stmt|;
name|style
operator|->
name|styleHint
argument_list|(
name|QStyle
operator|::
name|SH_WindowFrame_Mask
argument_list|,
operator|&
name|opt
argument_list|,
literal|0
argument_list|,
operator|&
name|mask
argument_list|)
expr_stmt|;
return|return
operator|(
name|mask
operator|.
name|region
operator|.
name|isEmpty
argument_list|()
condition|?
name|region
else|:
operator|(
name|region
operator|&
name|mask
operator|.
name|region
operator|)
operator|)
return|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_QWS_DECORATION_STYLED
end_comment
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
