begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2009 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** No Commercial Usage ** This file contains pre-release code and may not be distributed. ** You may use this file in accordance with the terms and conditions ** contained in the Technology Preview License Agreement accompanying ** this package. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights.  These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** If you have questions regarding the use of this file, please contact ** Nokia at qt-info@nokia.com. ** ** ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<qpixmap.h>
end_include
begin_include
include|#
directive|include
file|<private/qgraphicssystem_p.h>
end_include
begin_include
include|#
directive|include
file|<private/qapplication_p.h>
end_include
begin_function
DECL|function|grabWindow
name|QPixmap
name|QPixmap
operator|::
name|grabWindow
parameter_list|(
name|WId
name|window
parameter_list|,
name|int
name|x
parameter_list|,
name|int
name|y
parameter_list|,
name|int
name|w
parameter_list|,
name|int
name|h
parameter_list|)
block|{
return|return
name|QApplicationPrivate
operator|::
name|platformIntegration
argument_list|()
operator|->
name|grabWindow
argument_list|(
name|window
argument_list|,
name|x
argument_list|,
name|y
argument_list|,
name|w
argument_list|,
name|h
argument_list|)
return|;
block|}
end_function
end_unit
