begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** No Commercial Usage ** This file contains pre-release code and may not be distributed. ** You may use this file in accordance with the terms and conditions ** contained in the Technology Preview License Agreement accompanying ** this package. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights.  These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** If you have questions regarding the use of this file, please contact ** Nokia at qt-info@nokia.com. ** ** ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QPALETTE_H
end_ifndef
begin_define
DECL|macro|QPALETTE_H
define|#
directive|define
name|QPALETTE_H
end_define
begin_include
include|#
directive|include
file|<QtGui/qwindowdefs.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/qcolor.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/qbrush.h>
end_include
begin_function
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
name|QT_MODULE
parameter_list|(
name|Gui
parameter_list|)
ifdef|#
directive|ifdef
name|QT3_SUPPORT
name|class
name|QColorGroup
decl_stmt|;
endif|#
directive|endif
DECL|variable|QPalettePrivate
name|class
name|QPalettePrivate
decl_stmt|;
DECL|variable|QVariant
name|class
name|QVariant
decl_stmt|;
name|class
name|Q_GUI_EXPORT
name|QPalette
decl_stmt|{     Q_GADGET     Q_ENUMS(ColorGroup ColorRole
end_function
begin_label
unit|)
name|public
label|:
end_label
begin_expr_stmt
name|QPalette
argument_list|()
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|QPalette
argument_list|(
specifier|const
name|QColor
operator|&
name|button
argument_list|)
expr_stmt|;
end_expr_stmt
begin_macro
name|QPalette
argument_list|(
argument|Qt::GlobalColor button
argument_list|)
end_macro
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_expr_stmt
name|QPalette
argument_list|(
specifier|const
name|QColor
operator|&
name|button
argument_list|,
specifier|const
name|QColor
operator|&
name|window
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|QPalette
argument_list|(
specifier|const
name|QBrush
operator|&
name|windowText
argument_list|,
specifier|const
name|QBrush
operator|&
name|button
argument_list|,
specifier|const
name|QBrush
operator|&
name|light
argument_list|,
specifier|const
name|QBrush
operator|&
name|dark
argument_list|,
specifier|const
name|QBrush
operator|&
name|mid
argument_list|,
specifier|const
name|QBrush
operator|&
name|text
argument_list|,
specifier|const
name|QBrush
operator|&
name|bright_text
argument_list|,
specifier|const
name|QBrush
operator|&
name|base
argument_list|,
specifier|const
name|QBrush
operator|&
name|window
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|QPalette
argument_list|(
specifier|const
name|QColor
operator|&
name|windowText
argument_list|,
specifier|const
name|QColor
operator|&
name|window
argument_list|,
specifier|const
name|QColor
operator|&
name|light
argument_list|,
specifier|const
name|QColor
operator|&
name|dark
argument_list|,
specifier|const
name|QColor
operator|&
name|mid
argument_list|,
specifier|const
name|QColor
operator|&
name|text
argument_list|,
specifier|const
name|QColor
operator|&
name|base
argument_list|)
expr_stmt|;
end_expr_stmt
begin_ifdef
ifdef|#
directive|ifdef
name|QT3_SUPPORT
end_ifdef
begin_function_decl
name|QT3_SUPPORT_CONSTRUCTOR
name|QPalette
parameter_list|(
specifier|const
name|QColorGroup
modifier|&
name|active
parameter_list|,
specifier|const
name|QColorGroup
modifier|&
name|disabled
parameter_list|,
specifier|const
name|QColorGroup
modifier|&
name|inactive
parameter_list|)
function_decl|;
end_function_decl
begin_endif
endif|#
directive|endif
end_endif
begin_expr_stmt
name|QPalette
argument_list|(
specifier|const
name|QPalette
operator|&
name|palette
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
operator|~
name|QPalette
argument_list|()
expr_stmt|;
end_expr_stmt
begin_decl_stmt
name|QPalette
modifier|&
name|operator
init|=
operator|(
specifier|const
name|QPalette
operator|&
name|palette
operator|)
decl_stmt|;
end_decl_stmt
begin_ifdef
ifdef|#
directive|ifdef
name|Q_COMPILER_RVALUE_REFS
end_ifdef
begin_decl_stmt
specifier|inline
name|QPalette
modifier|&
name|operator
init|=
operator|(
name|QPalette
operator|&&
name|other
operator|)
block|{
name|resolve_mask
operator|=
name|other
operator|.
name|resolve_mask
block|;
name|current_group
operator|=
name|other
operator|.
name|current_group
block|;
name|qSwap
argument_list|(
name|d
argument_list|,
name|other
operator|.
name|d
argument_list|)
block|;
return|return
operator|*
name|this
return|;
block|}
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_expr_stmt
name|operator
name|QVariant
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_comment
comment|// Do not change the order, the serialization format depends on it
end_comment
begin_enum
enum|enum
name|ColorGroup
block|{
name|Active
block|,
name|Disabled
block|,
name|Inactive
block|,
name|NColorGroups
block|,
name|Current
block|,
name|All
block|,
name|Normal
init|=
name|Active
block|}
enum|;
end_enum
begin_enum
enum|enum
name|ColorRole
block|{
name|WindowText
block|,
name|Button
block|,
name|Light
block|,
name|Midlight
block|,
name|Dark
block|,
name|Mid
block|,
name|Text
block|,
name|BrightText
block|,
name|ButtonText
block|,
name|Base
block|,
name|Window
block|,
name|Shadow
block|,
name|Highlight
block|,
name|HighlightedText
block|,
name|Link
block|,
name|LinkVisited
block|,
comment|// ### Qt 5: remove
name|AlternateBase
block|,
name|NoRole
block|,
comment|// ### Qt 5: value should be 0 or -1
name|ToolTipBase
block|,
name|ToolTipText
block|,
name|NColorRoles
init|=
name|ToolTipText
operator|+
literal|1
block|,
name|Foreground
init|=
name|WindowText
block|,
name|Background
init|=
name|Window
comment|// ### Qt 5: remove
block|}
enum|;
end_enum
begin_expr_stmt
specifier|inline
name|ColorGroup
name|currentColorGroup
argument_list|()
specifier|const
block|{
return|return
name|static_cast
operator|<
name|ColorGroup
operator|>
operator|(
name|current_group
operator|)
return|;
block|}
end_expr_stmt
begin_function
specifier|inline
name|void
name|setCurrentColorGroup
parameter_list|(
name|ColorGroup
name|cg
parameter_list|)
block|{
name|current_group
operator|=
name|cg
expr_stmt|;
block|}
end_function
begin_decl_stmt
specifier|inline
specifier|const
name|QColor
modifier|&
name|color
argument_list|(
name|ColorGroup
name|cg
argument_list|,
name|ColorRole
name|cr
argument_list|)
decl|const
block|{
return|return
name|brush
argument_list|(
name|cg
argument_list|,
name|cr
argument_list|)
operator|.
name|color
argument_list|()
return|;
block|}
end_decl_stmt
begin_decl_stmt
specifier|const
name|QBrush
modifier|&
name|brush
argument_list|(
name|ColorGroup
name|cg
argument_list|,
name|ColorRole
name|cr
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt
begin_function_decl
specifier|inline
name|void
name|setColor
parameter_list|(
name|ColorGroup
name|cg
parameter_list|,
name|ColorRole
name|cr
parameter_list|,
specifier|const
name|QColor
modifier|&
name|color
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
specifier|inline
name|void
name|setColor
parameter_list|(
name|ColorRole
name|cr
parameter_list|,
specifier|const
name|QColor
modifier|&
name|color
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
specifier|inline
name|void
name|setBrush
parameter_list|(
name|ColorRole
name|cr
parameter_list|,
specifier|const
name|QBrush
modifier|&
name|brush
parameter_list|)
function_decl|;
end_function_decl
begin_decl_stmt
name|bool
name|isBrushSet
argument_list|(
name|ColorGroup
name|cg
argument_list|,
name|ColorRole
name|cr
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt
begin_function_decl
name|void
name|setBrush
parameter_list|(
name|ColorGroup
name|cg
parameter_list|,
name|ColorRole
name|cr
parameter_list|,
specifier|const
name|QBrush
modifier|&
name|brush
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|setColorGroup
parameter_list|(
name|ColorGroup
name|cr
parameter_list|,
specifier|const
name|QBrush
modifier|&
name|windowText
parameter_list|,
specifier|const
name|QBrush
modifier|&
name|button
parameter_list|,
specifier|const
name|QBrush
modifier|&
name|light
parameter_list|,
specifier|const
name|QBrush
modifier|&
name|dark
parameter_list|,
specifier|const
name|QBrush
modifier|&
name|mid
parameter_list|,
specifier|const
name|QBrush
modifier|&
name|text
parameter_list|,
specifier|const
name|QBrush
modifier|&
name|bright_text
parameter_list|,
specifier|const
name|QBrush
modifier|&
name|base
parameter_list|,
specifier|const
name|QBrush
modifier|&
name|window
parameter_list|)
function_decl|;
end_function_decl
begin_decl_stmt
name|bool
name|isEqual
argument_list|(
name|ColorGroup
name|cr1
argument_list|,
name|ColorGroup
name|cr2
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt
begin_decl_stmt
specifier|inline
specifier|const
name|QColor
modifier|&
name|color
argument_list|(
name|ColorRole
name|cr
argument_list|)
decl|const
block|{
return|return
name|color
argument_list|(
name|Current
argument_list|,
name|cr
argument_list|)
return|;
block|}
end_decl_stmt
begin_decl_stmt
specifier|inline
specifier|const
name|QBrush
modifier|&
name|brush
argument_list|(
name|ColorRole
name|cr
argument_list|)
decl|const
block|{
return|return
name|brush
argument_list|(
name|Current
argument_list|,
name|cr
argument_list|)
return|;
block|}
end_decl_stmt
begin_expr_stmt
specifier|inline
specifier|const
name|QBrush
operator|&
name|foreground
argument_list|()
specifier|const
block|{
return|return
name|brush
argument_list|(
name|WindowText
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
specifier|const
name|QBrush
operator|&
name|windowText
argument_list|()
specifier|const
block|{
return|return
name|brush
argument_list|(
name|WindowText
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
specifier|const
name|QBrush
operator|&
name|button
argument_list|()
specifier|const
block|{
return|return
name|brush
argument_list|(
name|Button
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
specifier|const
name|QBrush
operator|&
name|light
argument_list|()
specifier|const
block|{
return|return
name|brush
argument_list|(
name|Light
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
specifier|const
name|QBrush
operator|&
name|dark
argument_list|()
specifier|const
block|{
return|return
name|brush
argument_list|(
name|Dark
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
specifier|const
name|QBrush
operator|&
name|mid
argument_list|()
specifier|const
block|{
return|return
name|brush
argument_list|(
name|Mid
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
specifier|const
name|QBrush
operator|&
name|text
argument_list|()
specifier|const
block|{
return|return
name|brush
argument_list|(
name|Text
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
specifier|const
name|QBrush
operator|&
name|base
argument_list|()
specifier|const
block|{
return|return
name|brush
argument_list|(
name|Base
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
specifier|const
name|QBrush
operator|&
name|alternateBase
argument_list|()
specifier|const
block|{
return|return
name|brush
argument_list|(
name|AlternateBase
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
specifier|const
name|QBrush
operator|&
name|toolTipBase
argument_list|()
specifier|const
block|{
return|return
name|brush
argument_list|(
name|ToolTipBase
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
specifier|const
name|QBrush
operator|&
name|toolTipText
argument_list|()
specifier|const
block|{
return|return
name|brush
argument_list|(
name|ToolTipText
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
specifier|const
name|QBrush
operator|&
name|background
argument_list|()
specifier|const
block|{
return|return
name|brush
argument_list|(
name|Window
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
specifier|const
name|QBrush
operator|&
name|window
argument_list|()
specifier|const
block|{
return|return
name|brush
argument_list|(
name|Window
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
specifier|const
name|QBrush
operator|&
name|midlight
argument_list|()
specifier|const
block|{
return|return
name|brush
argument_list|(
name|Midlight
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
specifier|const
name|QBrush
operator|&
name|brightText
argument_list|()
specifier|const
block|{
return|return
name|brush
argument_list|(
name|BrightText
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
specifier|const
name|QBrush
operator|&
name|buttonText
argument_list|()
specifier|const
block|{
return|return
name|brush
argument_list|(
name|ButtonText
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
specifier|const
name|QBrush
operator|&
name|shadow
argument_list|()
specifier|const
block|{
return|return
name|brush
argument_list|(
name|Shadow
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
specifier|const
name|QBrush
operator|&
name|highlight
argument_list|()
specifier|const
block|{
return|return
name|brush
argument_list|(
name|Highlight
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
specifier|const
name|QBrush
operator|&
name|highlightedText
argument_list|()
specifier|const
block|{
return|return
name|brush
argument_list|(
name|HighlightedText
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
specifier|const
name|QBrush
operator|&
name|link
argument_list|()
specifier|const
block|{
return|return
name|brush
argument_list|(
name|Link
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
specifier|const
name|QBrush
operator|&
name|linkVisited
argument_list|()
specifier|const
block|{
return|return
name|brush
argument_list|(
name|LinkVisited
argument_list|)
return|;
block|}
end_expr_stmt
begin_ifdef
ifdef|#
directive|ifdef
name|QT3_SUPPORT
end_ifdef
begin_expr_stmt
specifier|inline
name|QT3_SUPPORT
name|QPalette
name|copy
argument_list|()
specifier|const
block|{
name|QPalette
name|p
operator|=
operator|*
name|this
block|;
name|p
operator|.
name|detach
argument_list|()
block|;
return|return
name|p
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|QT3_SUPPORT
name|QColorGroup
name|normal
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_function
specifier|inline
name|QT3_SUPPORT
name|void
name|setNormal
parameter_list|(
specifier|const
name|QColorGroup
modifier|&
name|cg
parameter_list|)
block|{
name|setColorGroup
argument_list|(
name|Active
argument_list|,
name|cg
argument_list|)
expr_stmt|;
block|}
end_function
begin_expr_stmt
name|QT3_SUPPORT
name|QColorGroup
name|active
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|QT3_SUPPORT
name|QColorGroup
name|disabled
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|QT3_SUPPORT
name|QColorGroup
name|inactive
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_function
specifier|inline
name|QT3_SUPPORT
name|void
name|setActive
parameter_list|(
specifier|const
name|QColorGroup
modifier|&
name|cg
parameter_list|)
block|{
name|setColorGroup
argument_list|(
name|Active
argument_list|,
name|cg
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
specifier|inline
name|QT3_SUPPORT
name|void
name|setDisabled
parameter_list|(
specifier|const
name|QColorGroup
modifier|&
name|cg
parameter_list|)
block|{
name|setColorGroup
argument_list|(
name|Disabled
argument_list|,
name|cg
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
specifier|inline
name|QT3_SUPPORT
name|void
name|setInactive
parameter_list|(
specifier|const
name|QColorGroup
modifier|&
name|cg
parameter_list|)
block|{
name|setColorGroup
argument_list|(
name|Inactive
argument_list|,
name|cg
argument_list|)
expr_stmt|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_expr_stmt
name|bool
name|operator
operator|==
operator|(
specifier|const
name|QPalette
operator|&
name|p
operator|)
specifier|const
expr_stmt|;
end_expr_stmt
begin_expr_stmt
specifier|inline
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|QPalette
operator|&
name|p
operator|)
specifier|const
block|{
return|return
operator|!
operator|(
name|operator
operator|==
operator|(
name|p
operator|)
operator|)
return|;
block|}
end_expr_stmt
begin_decl_stmt
name|bool
name|isCopyOf
argument_list|(
specifier|const
name|QPalette
operator|&
name|p
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|int
name|serialNumber
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|qint64
name|cacheKey
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_decl_stmt
name|QPalette
name|resolve
argument_list|(
specifier|const
name|QPalette
operator|&
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt
begin_expr_stmt
specifier|inline
name|uint
name|resolve
argument_list|()
specifier|const
block|{
return|return
name|resolve_mask
return|;
block|}
end_expr_stmt
begin_function
specifier|inline
name|void
name|resolve
parameter_list|(
name|uint
name|mask
parameter_list|)
block|{
name|resolve_mask
operator|=
name|mask
expr_stmt|;
block|}
end_function
begin_label
name|private
label|:
end_label
begin_function_decl
name|void
name|setColorGroup
parameter_list|(
name|ColorGroup
name|cr
parameter_list|,
specifier|const
name|QBrush
modifier|&
name|windowText
parameter_list|,
specifier|const
name|QBrush
modifier|&
name|button
parameter_list|,
specifier|const
name|QBrush
modifier|&
name|light
parameter_list|,
specifier|const
name|QBrush
modifier|&
name|dark
parameter_list|,
specifier|const
name|QBrush
modifier|&
name|mid
parameter_list|,
specifier|const
name|QBrush
modifier|&
name|text
parameter_list|,
specifier|const
name|QBrush
modifier|&
name|bright_text
parameter_list|,
specifier|const
name|QBrush
modifier|&
name|base
parameter_list|,
specifier|const
name|QBrush
modifier|&
name|alternate_base
parameter_list|,
specifier|const
name|QBrush
modifier|&
name|window
parameter_list|,
specifier|const
name|QBrush
modifier|&
name|midlight
parameter_list|,
specifier|const
name|QBrush
modifier|&
name|button_text
parameter_list|,
specifier|const
name|QBrush
modifier|&
name|shadow
parameter_list|,
specifier|const
name|QBrush
modifier|&
name|highlight
parameter_list|,
specifier|const
name|QBrush
modifier|&
name|highlighted_text
parameter_list|,
specifier|const
name|QBrush
modifier|&
name|link
parameter_list|,
specifier|const
name|QBrush
modifier|&
name|link_visited
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|setColorGroup
parameter_list|(
name|ColorGroup
name|cr
parameter_list|,
specifier|const
name|QBrush
modifier|&
name|windowText
parameter_list|,
specifier|const
name|QBrush
modifier|&
name|button
parameter_list|,
specifier|const
name|QBrush
modifier|&
name|light
parameter_list|,
specifier|const
name|QBrush
modifier|&
name|dark
parameter_list|,
specifier|const
name|QBrush
modifier|&
name|mid
parameter_list|,
specifier|const
name|QBrush
modifier|&
name|text
parameter_list|,
specifier|const
name|QBrush
modifier|&
name|bright_text
parameter_list|,
specifier|const
name|QBrush
modifier|&
name|base
parameter_list|,
specifier|const
name|QBrush
modifier|&
name|alternate_base
parameter_list|,
specifier|const
name|QBrush
modifier|&
name|window
parameter_list|,
specifier|const
name|QBrush
modifier|&
name|midlight
parameter_list|,
specifier|const
name|QBrush
modifier|&
name|button_text
parameter_list|,
specifier|const
name|QBrush
modifier|&
name|shadow
parameter_list|,
specifier|const
name|QBrush
modifier|&
name|highlight
parameter_list|,
specifier|const
name|QBrush
modifier|&
name|highlighted_text
parameter_list|,
specifier|const
name|QBrush
modifier|&
name|link
parameter_list|,
specifier|const
name|QBrush
modifier|&
name|link_visited
parameter_list|,
specifier|const
name|QBrush
modifier|&
name|toolTipBase
parameter_list|,
specifier|const
name|QBrush
modifier|&
name|toolTipText
parameter_list|)
function_decl|;
end_function_decl
begin_ifdef
ifdef|#
directive|ifdef
name|QT3_SUPPORT
end_ifdef
begin_decl_stmt
name|friend
name|class
name|QColorGroup
decl_stmt|;
end_decl_stmt
begin_function_decl
name|void
name|setColorGroup
parameter_list|(
name|ColorGroup
parameter_list|,
specifier|const
name|QColorGroup
modifier|&
parameter_list|)
function_decl|;
end_function_decl
begin_decl_stmt
name|QColorGroup
name|createColorGroup
argument_list|(
name|ColorGroup
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_function_decl
name|void
name|init
parameter_list|()
function_decl|;
end_function_decl
begin_function_decl
name|void
name|detach
parameter_list|()
function_decl|;
end_function_decl
begin_decl_stmt
name|QPalettePrivate
modifier|*
name|d
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|uint
name|current_group
range|:
literal|4
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|uint
name|resolve_mask
range|:
literal|28
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|friend
name|Q_GUI_EXPORT
name|QDataStream
operator|&
name|operator
operator|<<
operator|(
name|QDataStream
operator|&
name|s
operator|,
specifier|const
name|QPalette
operator|&
name|p
operator|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
unit|};
DECL|function|setColor
specifier|inline
name|void
name|QPalette
operator|::
name|setColor
argument_list|(
argument|ColorGroup acg
argument_list|,
argument|ColorRole acr
argument_list|,
argument|const QColor&acolor
argument_list|)
block|{
name|setBrush
argument_list|(
name|acg
argument_list|,
name|acr
argument_list|,
name|QBrush
argument_list|(
name|acolor
argument_list|)
argument_list|)
block|; }
DECL|function|setColor
specifier|inline
name|void
name|QPalette
operator|::
name|setColor
argument_list|(
argument|ColorRole acr
argument_list|,
argument|const QColor&acolor
argument_list|)
block|{
name|setColor
argument_list|(
name|All
argument_list|,
name|acr
argument_list|,
name|acolor
argument_list|)
block|; }
DECL|function|setBrush
specifier|inline
name|void
name|QPalette
operator|::
name|setBrush
argument_list|(
argument|ColorRole acr
argument_list|,
argument|const QBrush&abrush
argument_list|)
block|{
name|setBrush
argument_list|(
name|All
argument_list|,
name|acr
argument_list|,
name|abrush
argument_list|)
block|; }
ifdef|#
directive|ifdef
name|QT3_SUPPORT
name|class
name|Q_GUI_EXPORT
name|QColorGroup
operator|:
name|public
name|QPalette
block|{
name|public
operator|:
specifier|inline
name|QColorGroup
argument_list|()
operator|:
name|QPalette
argument_list|()
block|{}
specifier|inline
name|QColorGroup
argument_list|(
specifier|const
name|QBrush
operator|&
name|foreground
argument_list|,
specifier|const
name|QBrush
operator|&
name|button
argument_list|,
specifier|const
name|QBrush
operator|&
name|light
argument_list|,
specifier|const
name|QBrush
operator|&
name|dark
argument_list|,
specifier|const
name|QBrush
operator|&
name|mid
argument_list|,
specifier|const
name|QBrush
operator|&
name|text
argument_list|,
specifier|const
name|QBrush
operator|&
name|bright_text
argument_list|,
specifier|const
name|QBrush
operator|&
name|base
argument_list|,
specifier|const
name|QBrush
operator|&
name|background
argument_list|)
operator|:
name|QPalette
argument_list|(
argument|foreground
argument_list|,
argument|button
argument_list|,
argument|light
argument_list|,
argument|dark
argument_list|,
argument|mid
argument_list|,
argument|text
argument_list|,
argument|bright_text
argument_list|,
argument|base
argument_list|,
argument|background
argument_list|)
block|{}
specifier|inline
name|QColorGroup
argument_list|(
specifier|const
name|QColor
operator|&
name|foreground
argument_list|,
specifier|const
name|QColor
operator|&
name|background
argument_list|,
specifier|const
name|QColor
operator|&
name|light
argument_list|,
specifier|const
name|QColor
operator|&
name|dark
argument_list|,
specifier|const
name|QColor
operator|&
name|mid
argument_list|,
specifier|const
name|QColor
operator|&
name|text
argument_list|,
specifier|const
name|QColor
operator|&
name|base
argument_list|)
operator|:
name|QPalette
argument_list|(
argument|foreground
argument_list|,
argument|background
argument_list|,
argument|light
argument_list|,
argument|dark
argument_list|,
argument|mid
argument_list|,
argument|text
argument_list|,
argument|base
argument_list|)
block|{}
specifier|inline
name|QColorGroup
argument_list|(
specifier|const
name|QColorGroup
operator|&
name|cg
argument_list|)
operator|:
name|QPalette
argument_list|(
argument|cg
argument_list|)
block|{}
specifier|inline
name|QColorGroup
argument_list|(
specifier|const
name|QPalette
operator|&
name|pal
argument_list|)
operator|:
name|QPalette
argument_list|(
argument|pal
argument_list|)
block|{}
name|bool
name|operator
operator|==
operator|(
specifier|const
name|QColorGroup
operator|&
name|other
operator|)
specifier|const
block|;
specifier|inline
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|QColorGroup
operator|&
name|other
operator|)
specifier|const
block|{
return|return
operator|!
operator|(
name|operator
operator|==
operator|(
name|other
operator|)
operator|)
return|;
block|}
name|operator
name|QVariant
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_expr_stmt
specifier|inline
name|QT3_SUPPORT
specifier|const
name|QColor
operator|&
name|foreground
argument_list|()
specifier|const
block|{
return|return
name|color
argument_list|(
name|WindowText
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
name|QT3_SUPPORT
specifier|const
name|QColor
operator|&
name|button
argument_list|()
specifier|const
block|{
return|return
name|color
argument_list|(
name|Button
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
name|QT3_SUPPORT
specifier|const
name|QColor
operator|&
name|light
argument_list|()
specifier|const
block|{
return|return
name|color
argument_list|(
name|Light
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
name|QT3_SUPPORT
specifier|const
name|QColor
operator|&
name|dark
argument_list|()
specifier|const
block|{
return|return
name|color
argument_list|(
name|Dark
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
name|QT3_SUPPORT
specifier|const
name|QColor
operator|&
name|mid
argument_list|()
specifier|const
block|{
return|return
name|color
argument_list|(
name|Mid
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
name|QT3_SUPPORT
specifier|const
name|QColor
operator|&
name|text
argument_list|()
specifier|const
block|{
return|return
name|color
argument_list|(
name|Text
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
name|QT3_SUPPORT
specifier|const
name|QColor
operator|&
name|base
argument_list|()
specifier|const
block|{
return|return
name|color
argument_list|(
name|Base
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
name|QT3_SUPPORT
specifier|const
name|QColor
operator|&
name|background
argument_list|()
specifier|const
block|{
return|return
name|color
argument_list|(
name|Window
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
name|QT3_SUPPORT
specifier|const
name|QColor
operator|&
name|midlight
argument_list|()
specifier|const
block|{
return|return
name|color
argument_list|(
name|Midlight
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
name|QT3_SUPPORT
specifier|const
name|QColor
operator|&
name|brightText
argument_list|()
specifier|const
block|{
return|return
name|color
argument_list|(
name|BrightText
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
name|QT3_SUPPORT
specifier|const
name|QColor
operator|&
name|buttonText
argument_list|()
specifier|const
block|{
return|return
name|color
argument_list|(
name|ButtonText
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
name|QT3_SUPPORT
specifier|const
name|QColor
operator|&
name|shadow
argument_list|()
specifier|const
block|{
return|return
name|color
argument_list|(
name|Shadow
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
name|QT3_SUPPORT
specifier|const
name|QColor
operator|&
name|highlight
argument_list|()
specifier|const
block|{
return|return
name|color
argument_list|(
name|Highlight
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
name|QT3_SUPPORT
specifier|const
name|QColor
operator|&
name|highlightedText
argument_list|()
specifier|const
block|{
return|return
name|color
argument_list|(
name|HighlightedText
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
name|QT3_SUPPORT
specifier|const
name|QColor
operator|&
name|link
argument_list|()
specifier|const
block|{
return|return
name|color
argument_list|(
name|Link
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
name|QT3_SUPPORT
specifier|const
name|QColor
operator|&
name|linkVisited
argument_list|()
specifier|const
block|{
return|return
name|color
argument_list|(
name|LinkVisited
argument_list|)
return|;
block|}
end_expr_stmt
begin_ifndef
unit|};
ifndef|#
directive|ifndef
name|QT_NO_DATASTREAM
end_ifndef
begin_expr_stmt
name|Q_GUI_EXPORT
name|QT3_SUPPORT
name|QDataStream
operator|&
name|operator
operator|<<
operator|(
name|QDataStream
operator|&
name|ds
operator|,
specifier|const
name|QColorGroup
operator|&
name|cg
operator|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|Q_GUI_EXPORT
name|QT3_SUPPORT
name|QDataStream
operator|&
name|operator
operator|>>
operator|(
name|QDataStream
operator|&
name|ds
operator|,
name|QColorGroup
operator|&
name|cg
operator|)
expr_stmt|;
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_expr_stmt
DECL|function|inactive
specifier|inline
name|QColorGroup
name|QPalette
operator|::
name|inactive
argument_list|()
specifier|const
block|{
return|return
name|createColorGroup
argument_list|(
name|Inactive
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|disabled
specifier|inline
name|QColorGroup
name|QPalette
operator|::
name|disabled
argument_list|()
specifier|const
block|{
return|return
name|createColorGroup
argument_list|(
name|Disabled
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|active
specifier|inline
name|QColorGroup
name|QPalette
operator|::
name|active
argument_list|()
specifier|const
block|{
return|return
name|createColorGroup
argument_list|(
name|Active
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|normal
specifier|inline
name|QColorGroup
name|QPalette
operator|::
name|normal
argument_list|()
specifier|const
block|{
return|return
name|createColorGroup
argument_list|(
name|Active
argument_list|)
return|;
block|}
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/*****************************************************************************   QPalette stream functions  *****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_DATASTREAM
end_ifndef
begin_expr_stmt
name|Q_GUI_EXPORT
name|QDataStream
operator|&
name|operator
operator|<<
operator|(
name|QDataStream
operator|&
name|ds
operator|,
specifier|const
name|QPalette
operator|&
name|p
operator|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|Q_GUI_EXPORT
name|QDataStream
operator|&
name|operator
operator|>>
operator|(
name|QDataStream
operator|&
name|ds
operator|,
name|QPalette
operator|&
name|p
operator|)
expr_stmt|;
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_DATASTREAM
end_comment
begin_expr_stmt
name|QT_END_NAMESPACE
name|QT_END_HEADER
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QPALETTE_H
end_comment
end_unit
