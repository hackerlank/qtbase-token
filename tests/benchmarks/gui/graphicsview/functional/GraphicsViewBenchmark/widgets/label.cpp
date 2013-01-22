begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtGui>
end_include
begin_include
include|#
directive|include
file|"label.h"
end_include
begin_constructor
DECL|function|Label
name|Label
operator|::
name|Label
parameter_list|(
specifier|const
name|QString
modifier|&
name|text
parameter_list|,
name|QGraphicsItem
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|GvbWidget
argument_list|(
name|parent
argument_list|)
block|{
name|m_textItem
operator|=
operator|new
name|QGraphicsSimpleTextItem
argument_list|(
name|this
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
name|Fixed
argument_list|)
expr_stmt|;
name|setContentsMargins
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|setText
argument_list|(
name|text
argument_list|)
expr_stmt|;
comment|// This flag was introduced in Qt 4.6.
name|setFlag
argument_list|(
name|QGraphicsItem
operator|::
name|ItemHasNoContents
argument_list|,
literal|true
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_destructor
DECL|function|~Label
name|Label
operator|::
name|~
name|Label
parameter_list|()
block|{ }
end_destructor
begin_function
DECL|function|setText
name|void
name|Label
operator|::
name|setText
parameter_list|(
specifier|const
name|QString
modifier|&
name|text
parameter_list|)
block|{
name|m_textItem
operator|->
name|setText
argument_list|(
name|text
argument_list|)
expr_stmt|;
name|prepareGeometryChange
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|text
name|QString
name|Label
operator|::
name|text
parameter_list|()
specifier|const
block|{
return|return
name|m_textItem
operator|->
name|text
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|setFont
name|void
name|Label
operator|::
name|setFont
parameter_list|(
specifier|const
name|QFont
name|font
parameter_list|)
block|{
name|m_textItem
operator|->
name|setFont
argument_list|(
name|font
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|resizeEvent
name|void
name|Label
operator|::
name|resizeEvent
parameter_list|(
name|QGraphicsSceneResizeEvent
modifier|*
name|event
parameter_list|)
block|{
name|GvbWidget
operator|::
name|resizeEvent
argument_list|(
name|event
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|sizeHint
name|QSizeF
name|Label
operator|::
name|sizeHint
parameter_list|(
name|Qt
operator|::
name|SizeHint
name|which
parameter_list|,
specifier|const
name|QSizeF
modifier|&
name|constraint
parameter_list|)
specifier|const
block|{
switch|switch
condition|(
name|which
condition|)
block|{
case|case
name|Qt
operator|::
name|MinimumSize
case|:
comment|// fall thru
case|case
name|Qt
operator|::
name|PreferredSize
case|:
block|{
name|QFontMetricsF
name|fm
argument_list|(
name|m_textItem
operator|->
name|font
argument_list|()
argument_list|)
decl_stmt|;
return|return
name|QSizeF
argument_list|(
name|fm
operator|.
name|width
argument_list|(
name|m_textItem
operator|->
name|text
argument_list|()
argument_list|)
argument_list|,
name|fm
operator|.
name|height
argument_list|()
argument_list|)
return|;
block|}
default|default:
return|return
name|GvbWidget
operator|::
name|sizeHint
argument_list|(
name|which
argument_list|,
name|constraint
argument_list|)
return|;
block|}
block|}
end_function
end_unit
