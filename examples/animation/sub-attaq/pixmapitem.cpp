begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_comment
comment|//Own
end_comment
begin_include
include|#
directive|include
file|"pixmapitem.h"
end_include
begin_comment
comment|//Qt
end_comment
begin_include
include|#
directive|include
file|<QPainter>
end_include
begin_constructor
DECL|function|PixmapItem
name|PixmapItem
operator|::
name|PixmapItem
parameter_list|(
specifier|const
name|QString
modifier|&
name|fileName
parameter_list|,
name|GraphicsScene
operator|::
name|Mode
name|mode
parameter_list|,
name|QGraphicsItem
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QGraphicsObject
argument_list|(
name|parent
argument_list|)
block|{
if|if
condition|(
name|mode
operator|==
name|GraphicsScene
operator|::
name|Big
condition|)
name|pix
operator|=
literal|":/big/"
operator|+
name|fileName
expr_stmt|;
else|else
name|pix
operator|=
literal|":/small/"
operator|+
name|fileName
expr_stmt|;
block|}
end_constructor
begin_constructor
DECL|function|PixmapItem
name|PixmapItem
operator|::
name|PixmapItem
parameter_list|(
specifier|const
name|QString
modifier|&
name|fileName
parameter_list|,
name|QGraphicsScene
modifier|*
name|scene
parameter_list|)
member_init_list|:
name|QGraphicsObject
argument_list|()
member_init_list|,
name|pix
argument_list|(
name|fileName
argument_list|)
block|{
name|scene
operator|->
name|addItem
argument_list|(
name|this
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_function
DECL|function|size
name|QSizeF
name|PixmapItem
operator|::
name|size
parameter_list|()
specifier|const
block|{
return|return
name|pix
operator|.
name|size
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|boundingRect
name|QRectF
name|PixmapItem
operator|::
name|boundingRect
parameter_list|()
specifier|const
block|{
return|return
name|QRectF
argument_list|(
name|QPointF
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
argument_list|,
name|pix
operator|.
name|size
argument_list|()
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|paint
name|void
name|PixmapItem
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
parameter_list|,
name|QWidget
modifier|*
parameter_list|)
block|{
name|painter
operator|->
name|drawPixmap
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
name|pix
argument_list|)
expr_stmt|;
block|}
end_function
end_unit
