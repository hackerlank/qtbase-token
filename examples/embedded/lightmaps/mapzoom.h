begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the demonstration applications of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|MAPZOOM_H
end_ifndef
begin_define
DECL|macro|MAPZOOM_H
define|#
directive|define
name|MAPZOOM_H
end_define
begin_include
include|#
directive|include
file|<QMainWindow>
end_include
begin_decl_stmt
DECL|variable|QNetworkSession
name|class
name|QNetworkSession
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|LightMaps
name|class
name|LightMaps
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|MapZoom
range|:
name|public
name|QMainWindow
block|{
name|Q_OBJECT
name|public
operator|:
name|MapZoom
argument_list|()
block|;
name|private
name|slots
operator|:
name|void
name|sessionOpened
argument_list|()
block|;
name|void
name|chooseOslo
argument_list|()
block|;
name|void
name|chooseBerlin
argument_list|()
block|;
name|void
name|chooseJakarta
argument_list|()
block|;
name|void
name|aboutOsm
argument_list|()
block|;
name|private
operator|:
name|LightMaps
operator|*
name|map
block|;
name|QNetworkSession
operator|*
name|networkSession
block|; }
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
end_unit
