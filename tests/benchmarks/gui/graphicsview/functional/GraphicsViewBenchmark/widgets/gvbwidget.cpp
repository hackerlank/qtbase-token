begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** No Commercial Usage ** This file contains pre-release code and may not be distributed. ** You may use this file in accordance with the terms and conditions ** contained in the Technology Preview License Agreement accompanying ** this package. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights.  These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** If you have questions regarding the use of this file, please contact ** Nokia at qt-info@nokia.com. ** ** ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtGui>
end_include
begin_include
include|#
directive|include
file|"gvbwidget.h"
end_include
begin_constructor
DECL|function|GvbWidget
name|GvbWidget
operator|::
name|GvbWidget
parameter_list|(
name|QGraphicsItem
modifier|*
name|parent
parameter_list|,
name|Qt
operator|::
name|WindowFlags
name|wFlags
parameter_list|)
member_init_list|:
name|QGraphicsWidget
argument_list|(
name|parent
argument_list|,
name|wFlags
argument_list|)
block|{  }
end_constructor
begin_destructor
DECL|function|~GvbWidget
name|GvbWidget
operator|::
name|~
name|GvbWidget
parameter_list|()
block|{ }
end_destructor
begin_function
DECL|function|keyPressEvent
name|void
name|GvbWidget
operator|::
name|keyPressEvent
parameter_list|(
name|QKeyEvent
modifier|*
name|event
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
argument|event
argument_list|)
block|}
end_function
end_unit
