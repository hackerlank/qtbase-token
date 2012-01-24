begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qtoolbarseparator_p.h"
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_TOOLBAR
end_ifndef
begin_include
include|#
directive|include
file|<qstyle.h>
end_include
begin_include
include|#
directive|include
file|<qstyleoption.h>
end_include
begin_include
include|#
directive|include
file|<qtoolbar.h>
end_include
begin_include
include|#
directive|include
file|<qpainter.h>
end_include
begin_function
name|QT_BEGIN_NAMESPACE
DECL|function|initStyleOption
name|void
name|QToolBarSeparator
operator|::
name|initStyleOption
parameter_list|(
name|QStyleOption
modifier|*
name|option
parameter_list|)
specifier|const
block|{
name|option
operator|->
name|initFrom
argument_list|(
name|this
argument_list|)
expr_stmt|;
if|if
condition|(
name|orientation
argument_list|()
operator|==
name|Qt
operator|::
name|Horizontal
condition|)
name|option
operator|->
name|state
operator||=
name|QStyle
operator|::
name|State_Horizontal
expr_stmt|;
block|}
end_function
begin_constructor
DECL|function|QToolBarSeparator
name|QToolBarSeparator
operator|::
name|QToolBarSeparator
parameter_list|(
name|QToolBar
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QWidget
argument_list|(
name|parent
argument_list|)
member_init_list|,
name|orient
argument_list|(
name|parent
operator|->
name|orientation
argument_list|()
argument_list|)
block|{
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
block|}
end_constructor
begin_function
DECL|function|setOrientation
name|void
name|QToolBarSeparator
operator|::
name|setOrientation
parameter_list|(
name|Qt
operator|::
name|Orientation
name|orientation
parameter_list|)
block|{
name|orient
operator|=
name|orientation
expr_stmt|;
name|update
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|orientation
name|Qt
operator|::
name|Orientation
name|QToolBarSeparator
operator|::
name|orientation
parameter_list|()
specifier|const
block|{
return|return
name|orient
return|;
block|}
end_function
begin_function
DECL|function|sizeHint
name|QSize
name|QToolBarSeparator
operator|::
name|sizeHint
parameter_list|()
specifier|const
block|{
name|QStyleOption
name|opt
decl_stmt|;
name|initStyleOption
argument_list|(
operator|&
name|opt
argument_list|)
expr_stmt|;
specifier|const
name|int
name|extent
init|=
name|style
argument_list|()
operator|->
name|pixelMetric
argument_list|(
name|QStyle
operator|::
name|PM_ToolBarSeparatorExtent
argument_list|,
operator|&
name|opt
argument_list|,
name|parentWidget
argument_list|()
argument_list|)
decl_stmt|;
return|return
name|QSize
argument_list|(
name|extent
argument_list|,
name|extent
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|paintEvent
name|void
name|QToolBarSeparator
operator|::
name|paintEvent
parameter_list|(
name|QPaintEvent
modifier|*
parameter_list|)
block|{
name|QPainter
name|p
argument_list|(
name|this
argument_list|)
decl_stmt|;
name|QStyleOption
name|opt
decl_stmt|;
name|initStyleOption
argument_list|(
operator|&
name|opt
argument_list|)
expr_stmt|;
name|style
argument_list|()
operator|->
name|drawPrimitive
argument_list|(
name|QStyle
operator|::
name|PE_IndicatorToolBarSeparator
argument_list|,
operator|&
name|opt
argument_list|,
operator|&
name|p
argument_list|,
name|parentWidget
argument_list|()
argument_list|)
expr_stmt|;
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
comment|// QT_NO_TOOLBAR
end_comment
end_unit
