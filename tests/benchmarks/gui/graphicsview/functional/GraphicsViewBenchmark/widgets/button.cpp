begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtGui>
end_include
begin_include
include|#
directive|include
file|"button.h"
end_include
begin_include
include|#
directive|include
file|"theme.h"
end_include
begin_decl_stmt
DECL|variable|MinTextWidthAsChars
specifier|static
specifier|const
name|int
name|MinTextWidthAsChars
init|=
literal|8
decl_stmt|;
end_decl_stmt
begin_class
DECL|class|ButtonPrivate
class|class
name|ButtonPrivate
block|{
name|Q_DECLARE_PUBLIC
parameter_list|(
name|Button
parameter_list|)
specifier|public
private|:
DECL|function|ButtonPrivate
name|ButtonPrivate
parameter_list|(
name|Button
modifier|*
name|button
parameter_list|)
member_init_list|:
name|down
argument_list|(
literal|false
argument_list|)
member_init_list|,
name|q_ptr
argument_list|(
name|button
argument_list|)
block|{
name|textItem
operator|=
operator|new
name|QGraphicsSimpleTextItem
argument_list|(
name|q_ptr
argument_list|)
expr_stmt|;
block|}
DECL|member|textItem
name|QGraphicsSimpleTextItem
modifier|*
name|textItem
decl_stmt|;
DECL|member|down
name|bool
name|down
decl_stmt|;
DECL|member|q_ptr
name|Button
modifier|*
name|q_ptr
decl_stmt|;
block|}
class|;
end_class
begin_constructor
DECL|function|Button
name|Button
operator|::
name|Button
parameter_list|(
specifier|const
name|QString
modifier|&
name|text
parameter_list|,
name|QGraphicsItem
modifier|*
name|parent
parameter_list|,
name|QSizeF
name|minimumSize
parameter_list|)
member_init_list|:
name|QGraphicsWidget
argument_list|(
name|parent
argument_list|)
member_init_list|,
name|d_ptr
argument_list|(
operator|new
name|ButtonPrivate
argument_list|(
name|this
argument_list|)
argument_list|)
member_init_list|,
name|m_background
argument_list|()
member_init_list|,
name|m_selected
argument_list|(
literal|false
argument_list|)
block|{
name|Q_D
argument_list|(
name|Button
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
comment|//setCacheMode(QGraphicsItem::ItemCoordinateCache);
if|if
condition|(
name|minimumSize
operator|.
name|isValid
argument_list|()
condition|)
name|setMinimumSize
argument_list|(
name|minimumSize
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
name|d
operator|->
name|textItem
operator|->
name|setText
argument_list|(
name|text
argument_list|)
expr_stmt|;
name|prepareGeometryChange
argument_list|()
expr_stmt|;
name|m_font
operator|=
name|Theme
operator|::
name|p
argument_list|()
operator|->
name|font
argument_list|(
name|Theme
operator|::
name|MenuItem
argument_list|)
expr_stmt|;
name|d
operator|->
name|textItem
operator|->
name|setFont
argument_list|(
name|m_font
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|Theme
operator|::
name|p
argument_list|()
argument_list|,
name|SIGNAL
argument_list|(
name|themeChanged
argument_list|()
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|themeChange
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_destructor
DECL|function|~Button
name|Button
operator|::
name|~
name|Button
parameter_list|()
block|{
operator|delete
name|d_ptr
expr_stmt|;
block|}
end_destructor
begin_function
DECL|function|isDown
name|bool
name|Button
operator|::
name|isDown
parameter_list|()
block|{
name|Q_D
argument_list|(
name|Button
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|down
return|;
block|}
end_function
begin_function
DECL|function|setText
name|void
name|Button
operator|::
name|setText
parameter_list|(
specifier|const
name|QString
modifier|&
name|text
parameter_list|)
block|{
name|Q_D
argument_list|(
name|Button
argument_list|)
expr_stmt|;
name|d
operator|->
name|textItem
operator|->
name|setText
argument_list|(
name|text
argument_list|)
expr_stmt|;
name|update
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|text
name|QString
name|Button
operator|::
name|text
parameter_list|()
block|{
name|Q_D
argument_list|(
name|Button
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|textItem
operator|->
name|text
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|paint
name|void
name|Button
operator|::
name|paint
parameter_list|(
name|QPainter
modifier|*
name|painter
parameter_list|,
specifier|const
name|QStyleOptionGraphicsItem
modifier|*
name|option
parameter_list|,
name|QWidget
modifier|*
name|widget
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
name|widget
argument_list|)
expr_stmt|;
name|Q_UNUSED
argument_list|(
name|option
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|m_background
operator|.
name|isNull
argument_list|()
condition|)
name|painter
operator|->
name|drawPixmap
argument_list|(
name|QPoint
argument_list|()
argument_list|,
name|m_background
argument_list|)
expr_stmt|;
if|if
condition|(
name|m_selected
condition|)
block|{
name|painter
operator|->
name|setBrush
argument_list|(
name|Qt
operator|::
name|black
argument_list|)
expr_stmt|;
name|painter
operator|->
name|setOpacity
argument_list|(
literal|0.2
argument_list|)
expr_stmt|;
name|painter
operator|->
name|drawRect
argument_list|(
name|boundingRect
argument_list|()
operator|.
name|toRect
argument_list|()
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|sizeHint
name|QSizeF
name|Button
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
name|Q_D
argument_list|(
specifier|const
name|Button
argument_list|)
expr_stmt|;
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
block|{
name|QFontMetricsF
name|fm
argument_list|(
name|d
operator|->
name|textItem
operator|->
name|font
argument_list|()
argument_list|)
decl_stmt|;
return|return
name|QSizeF
argument_list|(
name|MinTextWidthAsChars
operator|*
name|fm
operator|.
name|maxWidth
argument_list|()
argument_list|,
name|fm
operator|.
name|height
argument_list|()
argument_list|)
return|;
block|}
case|case
name|Qt
operator|::
name|PreferredSize
case|:
block|{
name|QFontMetricsF
name|fm
argument_list|(
name|d
operator|->
name|textItem
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
name|d
operator|->
name|textItem
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
name|QGraphicsWidget
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
begin_function
DECL|function|mousePressEvent
name|void
name|Button
operator|::
name|mousePressEvent
parameter_list|(
name|QGraphicsSceneMouseEvent
modifier|*
name|event
parameter_list|)
block|{
name|Q_D
argument_list|(
name|Button
argument_list|)
expr_stmt|;
if|if
condition|(
name|event
operator|->
name|button
argument_list|()
operator|!=
name|Qt
operator|::
name|LeftButton
operator|||
operator|!
name|sceneBoundingRect
argument_list|()
operator|.
name|contains
argument_list|(
name|event
operator|->
name|scenePos
argument_list|()
argument_list|)
condition|)
return|return;
name|d
operator|->
name|down
operator|=
literal|true
expr_stmt|;
name|prepareGeometryChange
argument_list|()
expr_stmt|;
emit|emit
name|pressed
argument_list|()
emit|;
block|}
end_function
begin_function
DECL|function|mouseReleaseEvent
name|void
name|Button
operator|::
name|mouseReleaseEvent
parameter_list|(
name|QGraphicsSceneMouseEvent
modifier|*
name|event
parameter_list|)
block|{
name|Q_D
argument_list|(
name|Button
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|d
operator|->
name|down
operator|||
name|event
operator|->
name|button
argument_list|()
operator|!=
name|Qt
operator|::
name|LeftButton
condition|)
return|return;
name|d
operator|->
name|down
operator|=
literal|false
expr_stmt|;
name|prepareGeometryChange
argument_list|()
expr_stmt|;
emit|emit
name|released
argument_list|()
emit|;
if|if
condition|(
name|sceneBoundingRect
argument_list|()
operator|.
name|contains
argument_list|(
name|event
operator|->
name|scenePos
argument_list|()
argument_list|)
condition|)
emit|emit
name|clicked
argument_list|()
emit|;
block|}
end_function
begin_function
DECL|function|mouseMoveEvent
name|void
name|Button
operator|::
name|mouseMoveEvent
parameter_list|(
name|QGraphicsSceneMouseEvent
modifier|*
name|event
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
name|event
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|resizeEvent
name|void
name|Button
operator|::
name|resizeEvent
parameter_list|(
name|QGraphicsSceneResizeEvent
modifier|*
name|event
parameter_list|)
block|{
name|Q_D
argument_list|(
name|Button
argument_list|)
expr_stmt|;
name|QGraphicsWidget
operator|::
name|resizeEvent
argument_list|(
name|event
argument_list|)
expr_stmt|;
name|QRectF
name|rect
init|=
name|d
operator|->
name|textItem
operator|->
name|boundingRect
argument_list|()
decl_stmt|;
name|QRectF
name|buttonrect
init|=
name|this
operator|->
name|boundingRect
argument_list|()
decl_stmt|;
name|d
operator|->
name|textItem
operator|->
name|setPos
argument_list|(
operator|(
name|buttonrect
operator|.
name|width
argument_list|()
operator|-
name|rect
operator|.
name|width
argument_list|()
operator|)
operator|/
literal|2
argument_list|,
operator|(
name|buttonrect
operator|.
name|height
argument_list|()
operator|-
name|rect
operator|.
name|height
argument_list|()
operator|)
operator|/
literal|2
argument_list|)
expr_stmt|;
name|QSize
name|currentSize
init|=
name|buttonrect
operator|.
name|size
argument_list|()
operator|.
name|toSize
argument_list|()
decl_stmt|;
if|if
condition|(
name|m_background
operator|.
name|size
argument_list|()
operator|!=
name|currentSize
operator|&&
operator|(
name|currentSize
operator|.
name|width
argument_list|()
operator|>
literal|0
operator|&&
name|currentSize
operator|.
name|height
argument_list|()
operator|>
literal|0
operator|)
condition|)
block|{
name|m_background
operator|=
name|Theme
operator|::
name|p
argument_list|()
operator|->
name|pixmap
argument_list|(
literal|"status_field_middle.svg"
argument_list|,
name|buttonrect
operator|.
name|size
argument_list|()
operator|.
name|toSize
argument_list|()
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|setBackground
name|void
name|Button
operator|::
name|setBackground
parameter_list|(
name|QPixmap
modifier|&
name|background
parameter_list|)
block|{
name|m_background
operator|=
name|background
expr_stmt|;
block|}
end_function
begin_function
DECL|function|themeChange
name|void
name|Button
operator|::
name|themeChange
parameter_list|()
block|{
name|Q_D
argument_list|(
name|Button
argument_list|)
expr_stmt|;
name|m_font
operator|=
name|Theme
operator|::
name|p
argument_list|()
operator|->
name|font
argument_list|(
name|Theme
operator|::
name|MenuItem
argument_list|)
expr_stmt|;
name|d
operator|->
name|textItem
operator|->
name|setFont
argument_list|(
name|m_font
argument_list|)
expr_stmt|;
block|}
end_function
end_unit
