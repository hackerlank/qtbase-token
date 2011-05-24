begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtTest module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QTESTCORELIST_H
end_ifndef
begin_define
DECL|macro|QTESTCORELIST_H
define|#
directive|define
name|QTESTCORELIST_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qglobal.h>
end_include
begin_decl_stmt
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
DECL|function|QT_MODULE
name|QT_MODULE
argument_list|(
name|Test
argument_list|)
name|template
decl|<
name|class
name|T
decl|>
name|class
name|QTestCoreList
block|{
name|public
label|:
name|QTestCoreList
argument_list|()
expr_stmt|;
name|virtual
operator|~
name|QTestCoreList
argument_list|()
expr_stmt|;
name|void
name|addToList
parameter_list|(
name|T
modifier|*
modifier|*
name|list
parameter_list|)
function_decl|;
name|T
modifier|*
name|nextElement
parameter_list|()
function_decl|;
name|T
modifier|*
name|previousElement
parameter_list|()
function_decl|;
name|int
name|count
parameter_list|(
name|T
modifier|*
name|list
parameter_list|)
function_decl|;
name|int
name|count
parameter_list|()
function_decl|;
name|private
label|:
name|T
modifier|*
name|next
decl_stmt|;
name|T
modifier|*
name|prev
decl_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_expr_stmt
name|template
operator|<
name|class
name|T
operator|>
DECL|function|QTestCoreList
name|QTestCoreList
operator|<
name|T
operator|>
operator|::
name|QTestCoreList
argument_list|()
operator|:
name|next
argument_list|(
literal|0
argument_list|)
operator|,
name|prev
argument_list|(
literal|0
argument_list|)
block|{ }
name|template
operator|<
name|class
name|T
operator|>
DECL|function|~QTestCoreList
name|QTestCoreList
operator|<
name|T
operator|>
operator|::
operator|~
name|QTestCoreList
argument_list|()
block|{
if|if
condition|(
name|prev
condition|)
block|{
name|prev
operator|->
name|next
operator|=
literal|0
expr_stmt|;
block|}
name|delete
name|prev
expr_stmt|;
end_expr_stmt
begin_if
if|if
condition|(
name|next
condition|)
block|{
name|next
operator|->
name|prev
operator|=
literal|0
expr_stmt|;
block|}
end_if
begin_decl_stmt
name|delete
name|next
decl_stmt|;
end_decl_stmt
begin_expr_stmt
unit|}  template
operator|<
name|class
name|T
operator|>
DECL|function|addToList
name|void
name|QTestCoreList
operator|<
name|T
operator|>
operator|::
name|addToList
argument_list|(
argument|T **list
argument_list|)
block|{
if|if
condition|(
name|next
condition|)
name|next
operator|->
name|addToList
argument_list|(
name|list
argument_list|)
expr_stmt|;
else|else
block|{
name|next
operator|=
operator|*
name|list
expr_stmt|;
if|if
condition|(
name|next
condition|)
name|next
operator|->
name|prev
operator|=
name|static_cast
operator|<
name|T
operator|*
operator|>
operator|(
name|this
operator|)
expr_stmt|;
block|}
operator|*
name|list
operator|=
name|static_cast
operator|<
name|T
operator|*
operator|>
operator|(
name|this
operator|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
unit|}  template
operator|<
name|class
name|T
operator|>
DECL|function|nextElement
name|T
operator|*
name|QTestCoreList
operator|<
name|T
operator|>
operator|::
name|nextElement
argument_list|()
block|{
return|return
name|next
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|template
operator|<
name|class
name|T
operator|>
DECL|function|previousElement
name|T
operator|*
name|QTestCoreList
operator|<
name|T
operator|>
operator|::
name|previousElement
argument_list|()
block|{
return|return
name|prev
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|template
operator|<
name|class
name|T
operator|>
DECL|function|count
name|int
name|QTestCoreList
operator|<
name|T
operator|>
operator|::
name|count
argument_list|()
block|{
name|int
name|numOfElements
operator|=
literal|0
block|;
name|T
operator|*
name|it
operator|=
name|next
block|;
while|while
condition|(
name|it
condition|)
block|{
operator|++
name|numOfElements
expr_stmt|;
name|it
operator|=
name|it
operator|->
name|nextElement
argument_list|()
expr_stmt|;
block|}
end_expr_stmt
begin_return
return|return
name|numOfElements
return|;
end_return
begin_macro
unit|}  QT_END_NAMESPACE
name|QT_END_HEADER
end_macro
begin_endif
endif|#
directive|endif
end_endif
end_unit
