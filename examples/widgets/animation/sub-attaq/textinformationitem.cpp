begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2014 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia. For licensing terms and ** conditions see http://qt.digia.com/licensing. For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights. These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"textinformationitem.h"
end_include
begin_include
include|#
directive|include
file|"pixmapitem.h"
end_include
begin_constructor
DECL|function|TextInformationItem
name|TextInformationItem
operator|::
name|TextInformationItem
parameter_list|(
name|QGraphicsItem
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QGraphicsTextItem
argument_list|(
name|parent
argument_list|)
block|{
name|setFont
argument_list|(
name|QFont
argument_list|(
literal|"Comic Sans MS"
argument_list|,
literal|15
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_include
include|#
directive|include
file|<QDebug>
end_include
begin_function
DECL|function|setMessage
name|void
name|TextInformationItem
operator|::
name|setMessage
parameter_list|(
specifier|const
name|QString
modifier|&
name|text
parameter_list|)
block|{
name|setHtml
argument_list|(
name|text
argument_list|)
expr_stmt|;
name|setPos
argument_list|(
name|parentItem
argument_list|()
operator|->
name|boundingRect
argument_list|()
operator|.
name|center
argument_list|()
operator|.
name|x
argument_list|()
operator|-
name|boundingRect
argument_list|()
operator|.
name|size
argument_list|()
operator|.
name|width
argument_list|()
operator|/
literal|2
argument_list|,
name|parentItem
argument_list|()
operator|->
name|boundingRect
argument_list|()
operator|.
name|center
argument_list|()
operator|.
name|y
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
end_unit
