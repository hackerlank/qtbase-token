begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** No Commercial Usage ** This file contains pre-release code and may not be distributed. ** You may use this file in accordance with the terms and conditions ** contained in the Technology Preview License Agreement accompanying ** this package. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights.  These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** If you have questions regarding the use of this file, please contact ** Nokia at qt-info@nokia.com. ** ** ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtCore/QtCore>
end_include
begin_class
DECL|class|Class
class|class
name|Class
block|{
public|public:
DECL|function|~Class
name|~
name|Class
parameter_list|()
block|{
comment|// trigger creation of a new QThreadStorage, after the previous QThreadStorage from main() was destructed
specifier|static
name|QThreadStorage
argument_list|<
name|int
modifier|*
argument_list|>
name|threadstorage
decl_stmt|;
name|threadstorage
operator|.
name|setLocalData
argument_list|(
operator|new
name|int
argument_list|)
expr_stmt|;
name|threadstorage
operator|.
name|setLocalData
argument_list|(
operator|new
name|int
argument_list|)
expr_stmt|;
block|}
block|}
class|;
end_class
begin_function
DECL|function|main
name|int
name|main
parameter_list|()
block|{
comment|// instantiate the class that will use QThreadStorage from its destructor, it's destructor will be run last
specifier|static
name|Class
name|instance
decl_stmt|;
comment|// instantiate QThreadStorage, it's destructor (and the global destructors for QThreadStorages internals) will run first
specifier|static
name|QThreadStorage
argument_list|<
name|int
modifier|*
argument_list|>
name|threadstorage
decl_stmt|;
name|threadstorage
operator|.
name|setLocalData
argument_list|(
operator|new
name|int
argument_list|)
expr_stmt|;
name|threadstorage
operator|.
name|setLocalData
argument_list|(
operator|new
name|int
argument_list|)
expr_stmt|;
block|}
end_function
end_unit
