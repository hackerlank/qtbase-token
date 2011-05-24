begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
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
