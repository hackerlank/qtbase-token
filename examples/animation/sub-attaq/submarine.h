begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|__SUBMARINE__H__
end_ifndef
begin_define
DECL|macro|__SUBMARINE__H__
define|#
directive|define
name|__SUBMARINE__H__
end_define
begin_comment
comment|//Qt
end_comment
begin_include
include|#
directive|include
file|<QtWidgets/QGraphicsTransform>
end_include
begin_include
include|#
directive|include
file|"pixmapitem.h"
end_include
begin_decl_stmt
DECL|variable|Torpedo
name|class
name|Torpedo
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|SubMarine
range|:
name|public
name|PixmapItem
block|{
name|Q_OBJECT
name|public
operator|:
expr|enum
name|Movement
block|{
name|None
operator|=
literal|0
block|,
name|Left
block|,
name|Right
block|}
block|;     enum
block|{
name|Type
operator|=
name|UserType
operator|+
literal|1
block|}
block|;
name|SubMarine
argument_list|(
argument|int type
argument_list|,
argument|const QString&name
argument_list|,
argument|int points
argument_list|)
block|;
name|int
name|points
argument_list|()
specifier|const
block|;
name|void
name|setCurrentDirection
argument_list|(
argument|Movement direction
argument_list|)
block|;     enum
name|Movement
name|currentDirection
argument_list|()
specifier|const
block|;
name|void
name|setCurrentSpeed
argument_list|(
argument|int speed
argument_list|)
block|;
name|int
name|currentSpeed
argument_list|()
specifier|const
block|;
name|void
name|launchTorpedo
argument_list|(
argument|int speed
argument_list|)
block|;
name|void
name|destroy
argument_list|()
block|;
name|virtual
name|int
name|type
argument_list|()
specifier|const
block|;
name|QGraphicsRotation
operator|*
name|rotation
argument_list|()
specifier|const
block|{
return|return
name|graphicsRotation
return|;
block|}
name|signals
operator|:
name|void
name|subMarineDestroyed
argument_list|()
block|;
name|void
name|subMarineExecutionFinished
argument_list|()
block|;
name|void
name|subMarineStateChanged
argument_list|()
block|;
name|private
operator|:
name|int
name|subType
block|;
name|QString
name|subName
block|;
name|int
name|subPoints
block|;
name|int
name|speed
block|;
name|Movement
name|direction
block|;
name|QGraphicsRotation
operator|*
name|graphicsRotation
block|; }
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|//__SUBMARINE__H__
end_comment
end_unit
