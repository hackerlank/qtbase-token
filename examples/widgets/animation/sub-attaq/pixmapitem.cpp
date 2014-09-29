begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2014 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia. For licensing terms and ** conditions see http://qt.digia.com/licensing. For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights. These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
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
name|QPixmap
argument_list|(
name|QStringLiteral
argument_list|(
literal|":/big/"
argument_list|)
operator|+
name|fileName
argument_list|)
expr_stmt|;
else|else
name|pix
operator|=
name|QPixmap
argument_list|(
name|QStringLiteral
argument_list|(
literal|":/small/"
argument_list|)
operator|+
name|fileName
argument_list|)
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
