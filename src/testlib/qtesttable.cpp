begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtTest module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** No Commercial Usage ** This file contains pre-release code and may not be distributed. ** You may use this file in accordance with the terms and conditions ** contained in the Technology Preview License Agreement accompanying ** this package. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights.  These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** If you have questions regarding the use of this file, please contact ** Nokia at qt-info@nokia.com. ** ** ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"QtTest/private/qtesttable_p.h"
end_include
begin_include
include|#
directive|include
file|"QtTest/qtestdata.h"
end_include
begin_include
include|#
directive|include
file|<QtCore/qmetaobject.h>
end_include
begin_include
include|#
directive|include
file|<string.h>
end_include
begin_include
include|#
directive|include
file|"QtTest/qtestassert.h"
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_class
DECL|class|QTestTablePrivate
class|class
name|QTestTablePrivate
block|{
public|public:
DECL|struct|ElementList
struct|struct
name|ElementList
block|{
DECL|function|ElementList
name|ElementList
parameter_list|()
member_init_list|:
name|elementName
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|elementType
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|next
argument_list|(
literal|0
argument_list|)
block|{}
DECL|member|elementName
specifier|const
name|char
modifier|*
name|elementName
decl_stmt|;
DECL|member|elementType
name|int
name|elementType
decl_stmt|;
DECL|member|next
name|ElementList
modifier|*
name|next
decl_stmt|;
block|}
struct|;
DECL|struct|DataList
struct|struct
name|DataList
block|{
DECL|function|DataList
name|DataList
parameter_list|()
member_init_list|:
name|data
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|next
argument_list|(
literal|0
argument_list|)
block|{}
DECL|member|data
name|QTestData
modifier|*
name|data
decl_stmt|;
DECL|member|next
name|DataList
modifier|*
name|next
decl_stmt|;
block|}
struct|;
DECL|function|QTestTablePrivate
name|QTestTablePrivate
parameter_list|()
member_init_list|:
name|list
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|dataList
argument_list|(
literal|0
argument_list|)
block|{}
name|~
name|QTestTablePrivate
parameter_list|()
destructor_decl|;
DECL|member|list
name|ElementList
modifier|*
name|list
decl_stmt|;
DECL|member|dataList
name|DataList
modifier|*
name|dataList
decl_stmt|;
name|void
name|append
parameter_list|(
name|int
name|elemType
parameter_list|,
specifier|const
name|char
modifier|*
name|elemName
parameter_list|)
function_decl|;
name|void
name|append
parameter_list|(
name|QTestData
modifier|*
name|data
parameter_list|)
function_decl|;
name|ElementList
modifier|*
name|elementAt
parameter_list|(
name|int
name|index
parameter_list|)
function_decl|;
name|QTestData
modifier|*
name|dataAt
parameter_list|(
name|int
name|index
parameter_list|)
function_decl|;
DECL|member|currentTestTable
specifier|static
name|QTestTable
modifier|*
name|currentTestTable
decl_stmt|;
DECL|member|gTable
specifier|static
name|QTestTable
modifier|*
name|gTable
decl_stmt|;
block|}
class|;
end_class
begin_decl_stmt
DECL|member|currentTestTable
name|QTestTable
modifier|*
name|QTestTablePrivate
operator|::
name|currentTestTable
init|=
literal|0
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|member|gTable
name|QTestTable
modifier|*
name|QTestTablePrivate
operator|::
name|gTable
init|=
literal|0
decl_stmt|;
end_decl_stmt
begin_function
DECL|function|elementAt
name|QTestTablePrivate
operator|::
name|ElementList
modifier|*
name|QTestTablePrivate
operator|::
name|elementAt
parameter_list|(
name|int
name|index
parameter_list|)
block|{
name|ElementList
modifier|*
name|iter
init|=
name|list
decl_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|index
condition|;
operator|++
name|i
control|)
block|{
if|if
condition|(
operator|!
name|iter
condition|)
return|return
literal|0
return|;
name|iter
operator|=
name|iter
operator|->
name|next
expr_stmt|;
block|}
return|return
name|iter
return|;
block|}
end_function
begin_function
DECL|function|dataAt
name|QTestData
modifier|*
name|QTestTablePrivate
operator|::
name|dataAt
parameter_list|(
name|int
name|index
parameter_list|)
block|{
name|DataList
modifier|*
name|iter
init|=
name|dataList
decl_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|index
condition|;
operator|++
name|i
control|)
block|{
if|if
condition|(
operator|!
name|iter
condition|)
return|return
literal|0
return|;
name|iter
operator|=
name|iter
operator|->
name|next
expr_stmt|;
block|}
return|return
name|iter
condition|?
name|iter
operator|->
name|data
else|:
literal|0
return|;
block|}
end_function
begin_destructor
DECL|function|~QTestTablePrivate
name|QTestTablePrivate
operator|::
name|~
name|QTestTablePrivate
parameter_list|()
block|{
name|DataList
modifier|*
name|dit
init|=
name|dataList
decl_stmt|;
while|while
condition|(
name|dit
condition|)
block|{
name|DataList
modifier|*
name|next
init|=
name|dit
operator|->
name|next
decl_stmt|;
operator|delete
name|dit
operator|->
name|data
expr_stmt|;
operator|delete
name|dit
expr_stmt|;
name|dit
operator|=
name|next
expr_stmt|;
block|}
name|ElementList
modifier|*
name|iter
init|=
name|list
decl_stmt|;
while|while
condition|(
name|iter
condition|)
block|{
name|ElementList
modifier|*
name|next
init|=
name|iter
operator|->
name|next
decl_stmt|;
operator|delete
name|iter
expr_stmt|;
name|iter
operator|=
name|next
expr_stmt|;
block|}
block|}
end_destructor
begin_function
DECL|function|append
name|void
name|QTestTablePrivate
operator|::
name|append
parameter_list|(
name|int
name|elemType
parameter_list|,
specifier|const
name|char
modifier|*
name|elemName
parameter_list|)
block|{
name|ElementList
modifier|*
name|item
init|=
operator|new
name|ElementList
decl_stmt|;
name|item
operator|->
name|elementName
operator|=
name|elemName
expr_stmt|;
name|item
operator|->
name|elementType
operator|=
name|elemType
expr_stmt|;
if|if
condition|(
operator|!
name|list
condition|)
block|{
name|list
operator|=
name|item
expr_stmt|;
return|return;
block|}
name|ElementList
modifier|*
name|last
init|=
name|list
decl_stmt|;
while|while
condition|(
name|last
operator|->
name|next
operator|!=
literal|0
condition|)
name|last
operator|=
name|last
operator|->
name|next
expr_stmt|;
name|last
operator|->
name|next
operator|=
name|item
expr_stmt|;
block|}
end_function
begin_function
DECL|function|append
name|void
name|QTestTablePrivate
operator|::
name|append
parameter_list|(
name|QTestData
modifier|*
name|data
parameter_list|)
block|{
name|DataList
modifier|*
name|item
init|=
operator|new
name|DataList
decl_stmt|;
name|item
operator|->
name|data
operator|=
name|data
expr_stmt|;
if|if
condition|(
operator|!
name|dataList
condition|)
block|{
name|dataList
operator|=
name|item
expr_stmt|;
return|return;
block|}
name|DataList
modifier|*
name|last
init|=
name|dataList
decl_stmt|;
while|while
condition|(
name|last
operator|->
name|next
operator|!=
literal|0
condition|)
name|last
operator|=
name|last
operator|->
name|next
expr_stmt|;
name|last
operator|->
name|next
operator|=
name|item
expr_stmt|;
block|}
end_function
begin_function
DECL|function|addColumn
name|void
name|QTestTable
operator|::
name|addColumn
parameter_list|(
name|int
name|type
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|)
block|{
name|QTEST_ASSERT
argument_list|(
name|type
argument_list|)
expr_stmt|;
name|QTEST_ASSERT
argument_list|(
name|name
argument_list|)
expr_stmt|;
name|d
operator|->
name|append
argument_list|(
name|type
argument_list|,
name|name
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|elementCount
name|int
name|QTestTable
operator|::
name|elementCount
parameter_list|()
specifier|const
block|{
name|QTestTablePrivate
operator|::
name|ElementList
modifier|*
name|item
init|=
name|d
operator|->
name|list
decl_stmt|;
name|int
name|count
init|=
literal|0
decl_stmt|;
while|while
condition|(
name|item
condition|)
block|{
operator|++
name|count
expr_stmt|;
name|item
operator|=
name|item
operator|->
name|next
expr_stmt|;
block|}
return|return
name|count
return|;
block|}
end_function
begin_function
DECL|function|dataCount
name|int
name|QTestTable
operator|::
name|dataCount
parameter_list|()
specifier|const
block|{
name|QTestTablePrivate
operator|::
name|DataList
modifier|*
name|item
init|=
name|d
operator|->
name|dataList
decl_stmt|;
name|int
name|count
init|=
literal|0
decl_stmt|;
while|while
condition|(
name|item
condition|)
block|{
operator|++
name|count
expr_stmt|;
name|item
operator|=
name|item
operator|->
name|next
expr_stmt|;
block|}
return|return
name|count
return|;
block|}
end_function
begin_function
DECL|function|isEmpty
name|bool
name|QTestTable
operator|::
name|isEmpty
parameter_list|()
specifier|const
block|{
return|return
operator|!
name|d
operator|->
name|list
return|;
block|}
end_function
begin_function
DECL|function|newData
name|QTestData
modifier|*
name|QTestTable
operator|::
name|newData
parameter_list|(
specifier|const
name|char
modifier|*
name|tag
parameter_list|)
block|{
name|QTestData
modifier|*
name|dt
init|=
operator|new
name|QTestData
argument_list|(
name|tag
argument_list|,
name|this
argument_list|)
decl_stmt|;
name|d
operator|->
name|append
argument_list|(
name|dt
argument_list|)
expr_stmt|;
return|return
name|dt
return|;
block|}
end_function
begin_constructor
DECL|function|QTestTable
name|QTestTable
operator|::
name|QTestTable
parameter_list|()
block|{
name|d
operator|=
operator|new
name|QTestTablePrivate
expr_stmt|;
name|QTestTablePrivate
operator|::
name|currentTestTable
operator|=
name|this
expr_stmt|;
block|}
end_constructor
begin_destructor
DECL|function|~QTestTable
name|QTestTable
operator|::
name|~
name|QTestTable
parameter_list|()
block|{
name|QTestTablePrivate
operator|::
name|currentTestTable
operator|=
literal|0
expr_stmt|;
operator|delete
name|d
expr_stmt|;
block|}
end_destructor
begin_function
DECL|function|elementTypeId
name|int
name|QTestTable
operator|::
name|elementTypeId
parameter_list|(
name|int
name|index
parameter_list|)
specifier|const
block|{
name|QTestTablePrivate
operator|::
name|ElementList
modifier|*
name|item
init|=
name|d
operator|->
name|elementAt
argument_list|(
name|index
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|item
condition|)
return|return
operator|-
literal|1
return|;
return|return
name|item
operator|->
name|elementType
return|;
block|}
end_function
begin_function
DECL|function|dataTag
specifier|const
name|char
modifier|*
name|QTestTable
operator|::
name|dataTag
parameter_list|(
name|int
name|index
parameter_list|)
specifier|const
block|{
name|QTestTablePrivate
operator|::
name|ElementList
modifier|*
name|item
init|=
name|d
operator|->
name|elementAt
argument_list|(
name|index
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|item
condition|)
return|return
literal|0
return|;
return|return
name|item
operator|->
name|elementName
return|;
block|}
end_function
begin_function
DECL|function|testData
name|QTestData
modifier|*
name|QTestTable
operator|::
name|testData
parameter_list|(
name|int
name|index
parameter_list|)
specifier|const
block|{
return|return
name|d
operator|->
name|dataAt
argument_list|(
name|index
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|indexOf
name|int
name|QTestTable
operator|::
name|indexOf
parameter_list|(
specifier|const
name|char
modifier|*
name|elementName
parameter_list|)
specifier|const
block|{
name|QTEST_ASSERT
argument_list|(
name|elementName
argument_list|)
expr_stmt|;
name|QTestTablePrivate
operator|::
name|ElementList
modifier|*
name|item
init|=
name|d
operator|->
name|list
decl_stmt|;
name|int
name|i
init|=
literal|0
decl_stmt|;
while|while
condition|(
name|item
condition|)
block|{
if|if
condition|(
name|strcmp
argument_list|(
name|elementName
argument_list|,
name|item
operator|->
name|elementName
argument_list|)
operator|==
literal|0
condition|)
return|return
name|i
return|;
name|item
operator|=
name|item
operator|->
name|next
expr_stmt|;
operator|++
name|i
expr_stmt|;
block|}
return|return
operator|-
literal|1
return|;
block|}
end_function
begin_function
DECL|function|globalTestTable
name|QTestTable
modifier|*
name|QTestTable
operator|::
name|globalTestTable
parameter_list|()
block|{
if|if
condition|(
operator|!
name|QTestTablePrivate
operator|::
name|gTable
condition|)
name|QTestTablePrivate
operator|::
name|gTable
operator|=
operator|new
name|QTestTable
argument_list|()
expr_stmt|;
return|return
name|QTestTablePrivate
operator|::
name|gTable
return|;
block|}
end_function
begin_function
DECL|function|clearGlobalTestTable
name|void
name|QTestTable
operator|::
name|clearGlobalTestTable
parameter_list|()
block|{
operator|delete
name|QTestTablePrivate
operator|::
name|gTable
expr_stmt|;
name|QTestTablePrivate
operator|::
name|gTable
operator|=
literal|0
expr_stmt|;
block|}
end_function
begin_function
DECL|function|currentTestTable
name|QTestTable
modifier|*
name|QTestTable
operator|::
name|currentTestTable
parameter_list|()
block|{
return|return
name|QTestTablePrivate
operator|::
name|currentTestTable
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
