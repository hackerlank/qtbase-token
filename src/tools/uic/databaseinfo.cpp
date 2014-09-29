begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2014 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the tools applications of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia. For licensing terms and ** conditions see http://qt.digia.com/licensing. For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights. These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"databaseinfo.h"
end_include
begin_include
include|#
directive|include
file|"driver.h"
end_include
begin_include
include|#
directive|include
file|"ui4.h"
end_include
begin_include
include|#
directive|include
file|"utils.h"
end_include
begin_function
name|QT_BEGIN_NAMESPACE
DECL|function|DatabaseInfo
name|DatabaseInfo
operator|::
name|DatabaseInfo
parameter_list|()
block|{ }
end_function
begin_function
DECL|function|acceptUI
name|void
name|DatabaseInfo
operator|::
name|acceptUI
parameter_list|(
name|DomUI
modifier|*
name|node
parameter_list|)
block|{
name|m_connections
operator|.
name|clear
argument_list|()
expr_stmt|;
name|m_cursors
operator|.
name|clear
argument_list|()
expr_stmt|;
name|m_fields
operator|.
name|clear
argument_list|()
expr_stmt|;
name|TreeWalker
operator|::
name|acceptUI
argument_list|(
name|node
argument_list|)
expr_stmt|;
name|m_connections
operator|=
name|unique
argument_list|(
name|m_connections
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|acceptWidget
name|void
name|DatabaseInfo
operator|::
name|acceptWidget
parameter_list|(
name|DomWidget
modifier|*
name|node
parameter_list|)
block|{
name|QHash
argument_list|<
name|QString
argument_list|,
name|DomProperty
modifier|*
argument_list|>
name|properties
init|=
name|propertyMap
argument_list|(
name|node
operator|->
name|elementProperty
argument_list|()
argument_list|)
decl_stmt|;
name|DomProperty
modifier|*
name|frameworkCode
init|=
name|properties
operator|.
name|value
argument_list|(
name|QLatin1String
argument_list|(
literal|"frameworkCode"
argument_list|)
argument_list|,
literal|0
argument_list|)
decl_stmt|;
if|if
condition|(
name|frameworkCode
operator|&&
name|toBool
argument_list|(
name|frameworkCode
operator|->
name|elementBool
argument_list|()
argument_list|)
operator|==
literal|false
condition|)
return|return;
name|DomProperty
modifier|*
name|db
init|=
name|properties
operator|.
name|value
argument_list|(
name|QLatin1String
argument_list|(
literal|"database"
argument_list|)
argument_list|,
literal|0
argument_list|)
decl_stmt|;
if|if
condition|(
name|db
operator|&&
name|db
operator|->
name|elementStringList
argument_list|()
condition|)
block|{
name|QStringList
name|info
init|=
name|db
operator|->
name|elementStringList
argument_list|()
operator|->
name|elementString
argument_list|()
decl_stmt|;
name|QString
name|connection
init|=
name|info
operator|.
name|size
argument_list|()
operator|>
literal|0
condition|?
name|info
operator|.
name|at
argument_list|(
literal|0
argument_list|)
else|:
name|QString
argument_list|()
decl_stmt|;
if|if
condition|(
name|connection
operator|.
name|isEmpty
argument_list|()
condition|)
return|return;
name|m_connections
operator|.
name|append
argument_list|(
name|connection
argument_list|)
expr_stmt|;
name|QString
name|table
init|=
name|info
operator|.
name|size
argument_list|()
operator|>
literal|1
condition|?
name|info
operator|.
name|at
argument_list|(
literal|1
argument_list|)
else|:
name|QString
argument_list|()
decl_stmt|;
if|if
condition|(
name|table
operator|.
name|isEmpty
argument_list|()
condition|)
return|return;
name|m_cursors
index|[
name|connection
index|]
operator|.
name|append
argument_list|(
name|table
argument_list|)
expr_stmt|;
name|QString
name|field
init|=
name|info
operator|.
name|size
argument_list|()
operator|>
literal|2
condition|?
name|info
operator|.
name|at
argument_list|(
literal|2
argument_list|)
else|:
name|QString
argument_list|()
decl_stmt|;
if|if
condition|(
name|field
operator|.
name|isEmpty
argument_list|()
condition|)
return|return;
name|m_fields
index|[
name|connection
index|]
operator|.
name|append
argument_list|(
name|field
argument_list|)
expr_stmt|;
block|}
name|TreeWalker
operator|::
name|acceptWidget
argument_list|(
name|node
argument_list|)
expr_stmt|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
