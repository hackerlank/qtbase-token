begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the QtWidgets module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qtoolbarextension_p.h"
end_include
begin_include
include|#
directive|include
file|<qpixmap.h>
end_include
begin_include
include|#
directive|include
file|<qstyle.h>
end_include
begin_include
include|#
directive|include
file|<qstylepainter.h>
end_include
begin_include
include|#
directive|include
file|<qstyleoption.h>
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_TOOLBUTTON
end_ifndef
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_constructor
DECL|function|QToolBarExtension
name|QToolBarExtension
operator|::
name|QToolBarExtension
parameter_list|(
name|QWidget
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QToolButton
argument_list|(
name|parent
argument_list|)
block|{
name|setObjectName
argument_list|(
name|QLatin1String
argument_list|(
literal|"qt_toolbar_ext_button"
argument_list|)
argument_list|)
expr_stmt|;
name|setAutoRaise
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|setOrientation
argument_list|(
name|Qt
operator|::
name|Horizontal
argument_list|)
expr_stmt|;
name|setSizePolicy
argument_list|(
name|QSizePolicy
operator|::
name|Minimum
argument_list|,
name|QSizePolicy
operator|::
name|Minimum
argument_list|)
expr_stmt|;
name|setCheckable
argument_list|(
literal|true
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_function
DECL|function|setOrientation
name|void
name|QToolBarExtension
operator|::
name|setOrientation
parameter_list|(
name|Qt
operator|::
name|Orientation
name|o
parameter_list|)
block|{
name|QStyleOption
name|opt
decl_stmt|;
name|opt
operator|.
name|init
argument_list|(
name|this
argument_list|)
expr_stmt|;
if|if
condition|(
name|o
operator|==
name|Qt
operator|::
name|Horizontal
condition|)
block|{
name|setIcon
argument_list|(
name|style
argument_list|()
operator|->
name|standardIcon
argument_list|(
name|QStyle
operator|::
name|SP_ToolBarHorizontalExtensionButton
argument_list|,
operator|&
name|opt
argument_list|)
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|setIcon
argument_list|(
name|style
argument_list|()
operator|->
name|standardIcon
argument_list|(
name|QStyle
operator|::
name|SP_ToolBarVerticalExtensionButton
argument_list|,
operator|&
name|opt
argument_list|)
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|paintEvent
name|void
name|QToolBarExtension
operator|::
name|paintEvent
parameter_list|(
name|QPaintEvent
modifier|*
parameter_list|)
block|{
name|QStylePainter
name|p
argument_list|(
name|this
argument_list|)
decl_stmt|;
name|QStyleOptionToolButton
name|opt
decl_stmt|;
name|initStyleOption
argument_list|(
operator|&
name|opt
argument_list|)
expr_stmt|;
comment|// We do not need to draw both extension arrows
name|opt
operator|.
name|features
operator|&=
operator|~
name|QStyleOptionToolButton
operator|::
name|HasMenu
expr_stmt|;
name|p
operator|.
name|drawComplexControl
argument_list|(
name|QStyle
operator|::
name|CC_ToolButton
argument_list|,
name|opt
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|sizeHint
name|QSize
name|QToolBarExtension
operator|::
name|sizeHint
parameter_list|()
specifier|const
block|{
name|int
name|ext
init|=
name|style
argument_list|()
operator|->
name|pixelMetric
argument_list|(
name|QStyle
operator|::
name|PM_ToolBarExtensionExtent
argument_list|)
decl_stmt|;
return|return
name|QSize
argument_list|(
name|ext
argument_list|,
name|ext
argument_list|)
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_TOOLBUTTON
end_comment
end_unit
