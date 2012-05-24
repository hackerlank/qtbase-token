begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the tools applications of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_comment
comment|/*   editdistance.cpp */
end_comment
begin_include
include|#
directive|include
file|"editdistance.h"
end_include
begin_function
name|QT_BEGIN_NAMESPACE
DECL|function|editDistance
name|int
name|editDistance
parameter_list|(
specifier|const
name|QString
modifier|&
name|s
parameter_list|,
specifier|const
name|QString
modifier|&
name|t
parameter_list|)
block|{
DECL|macro|D
define|#
directive|define
name|D
parameter_list|(
name|i
parameter_list|,
name|j
parameter_list|)
value|d[(i) * n + (j)]
name|int
name|i
decl_stmt|;
name|int
name|j
decl_stmt|;
name|int
name|m
init|=
name|s
operator|.
name|length
argument_list|()
operator|+
literal|1
decl_stmt|;
name|int
name|n
init|=
name|t
operator|.
name|length
argument_list|()
operator|+
literal|1
decl_stmt|;
name|int
modifier|*
name|d
init|=
operator|new
name|int
index|[
name|m
operator|*
name|n
index|]
decl_stmt|;
name|int
name|result
decl_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|m
condition|;
name|i
operator|++
control|)
name|D
argument_list|(
name|i
argument_list|,
literal|0
argument_list|)
operator|=
name|i
expr_stmt|;
for|for
control|(
name|j
operator|=
literal|0
init|;
name|j
operator|<
name|n
condition|;
name|j
operator|++
control|)
name|D
argument_list|(
literal|0
argument_list|,
name|j
argument_list|)
operator|=
name|j
expr_stmt|;
for|for
control|(
name|i
operator|=
literal|1
init|;
name|i
operator|<
name|m
condition|;
name|i
operator|++
control|)
block|{
for|for
control|(
name|j
operator|=
literal|1
init|;
name|j
operator|<
name|n
condition|;
name|j
operator|++
control|)
block|{
if|if
condition|(
name|s
index|[
name|i
operator|-
literal|1
index|]
operator|==
name|t
index|[
name|j
operator|-
literal|1
index|]
condition|)
block|{
name|D
argument_list|(
name|i
argument_list|,
name|j
argument_list|)
operator|=
name|D
argument_list|(
name|i
operator|-
literal|1
argument_list|,
name|j
operator|-
literal|1
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|int
name|x
init|=
name|D
argument_list|(
name|i
operator|-
literal|1
argument_list|,
name|j
argument_list|)
decl_stmt|;
name|int
name|y
init|=
name|D
argument_list|(
name|i
operator|-
literal|1
argument_list|,
name|j
operator|-
literal|1
argument_list|)
decl_stmt|;
name|int
name|z
init|=
name|D
argument_list|(
name|i
argument_list|,
name|j
operator|-
literal|1
argument_list|)
decl_stmt|;
name|D
argument_list|(
name|i
argument_list|,
name|j
argument_list|)
operator|=
literal|1
operator|+
name|qMin
argument_list|(
name|qMin
argument_list|(
name|x
argument_list|,
name|y
argument_list|)
argument_list|,
name|z
argument_list|)
expr_stmt|;
block|}
block|}
block|}
name|result
operator|=
name|D
argument_list|(
name|m
operator|-
literal|1
argument_list|,
name|n
operator|-
literal|1
argument_list|)
expr_stmt|;
operator|delete
index|[]
name|d
expr_stmt|;
return|return
name|result
return|;
DECL|macro|D
undef|#
directive|undef
name|D
block|}
end_function
begin_function
DECL|function|nearestName
name|QString
name|nearestName
parameter_list|(
specifier|const
name|QString
modifier|&
name|actual
parameter_list|,
specifier|const
name|QSet
argument_list|<
name|QString
argument_list|>
modifier|&
name|candidates
parameter_list|)
block|{
if|if
condition|(
name|actual
operator|.
name|isEmpty
argument_list|()
condition|)
return|return
name|QString
argument_list|()
return|;
name|int
name|deltaBest
init|=
literal|10000
decl_stmt|;
name|int
name|numBest
init|=
literal|0
decl_stmt|;
name|QString
name|best
decl_stmt|;
name|QSet
argument_list|<
name|QString
argument_list|>
operator|::
name|ConstIterator
name|c
init|=
name|candidates
operator|.
name|constBegin
argument_list|()
decl_stmt|;
while|while
condition|(
name|c
operator|!=
name|candidates
operator|.
name|constEnd
argument_list|()
condition|)
block|{
if|if
condition|(
operator|(
operator|*
name|c
operator|)
index|[
literal|0
index|]
operator|==
name|actual
index|[
literal|0
index|]
condition|)
block|{
name|int
name|delta
init|=
name|editDistance
argument_list|(
name|actual
argument_list|,
operator|*
name|c
argument_list|)
decl_stmt|;
if|if
condition|(
name|delta
operator|<
name|deltaBest
condition|)
block|{
name|deltaBest
operator|=
name|delta
expr_stmt|;
name|numBest
operator|=
literal|1
expr_stmt|;
name|best
operator|=
operator|*
name|c
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|delta
operator|==
name|deltaBest
condition|)
block|{
name|numBest
operator|++
expr_stmt|;
block|}
block|}
operator|++
name|c
expr_stmt|;
block|}
if|if
condition|(
name|numBest
operator|==
literal|1
operator|&&
name|deltaBest
operator|<=
literal|2
operator|&&
name|actual
operator|.
name|length
argument_list|()
operator|+
name|best
operator|.
name|length
argument_list|()
operator|>=
literal|5
condition|)
block|{
return|return
name|best
return|;
block|}
else|else
block|{
return|return
name|QString
argument_list|()
return|;
block|}
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
