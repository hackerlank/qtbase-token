begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qplatformdefs.h"
end_include
begin_include
include|#
directive|include
file|"qurl.h"
end_include
begin_include
include|#
directive|include
file|"private/qurltlds_p.h"
end_include
begin_include
include|#
directive|include
file|"private/qtldurl_p.h"
end_include
begin_include
include|#
directive|include
file|"QtCore/qstring.h"
end_include
begin_include
include|#
directive|include
file|"QtCore/qvector.h"
end_include
begin_function
name|QT_BEGIN_NAMESPACE
DECL|function|containsTLDEntry
specifier|static
name|bool
name|containsTLDEntry
parameter_list|(
specifier|const
name|QString
modifier|&
name|entry
parameter_list|)
block|{
name|int
name|index
init|=
name|qt_hash
argument_list|(
name|entry
argument_list|)
operator|%
name|tldCount
decl_stmt|;
comment|// select the right chunk from the big table
name|short
name|chunk
init|=
literal|0
decl_stmt|;
name|uint
name|chunkIndex
init|=
name|tldIndices
index|[
name|index
index|]
decl_stmt|,
name|offset
init|=
literal|0
decl_stmt|;
while|while
condition|(
name|chunk
operator|<
name|tldChunkCount
operator|&&
name|tldIndices
index|[
name|index
index|]
operator|>=
name|tldChunks
index|[
name|chunk
index|]
condition|)
block|{
name|chunkIndex
operator|-=
name|tldChunks
index|[
name|chunk
index|]
expr_stmt|;
name|offset
operator|+=
name|tldChunks
index|[
name|chunk
index|]
expr_stmt|;
name|chunk
operator|++
expr_stmt|;
block|}
comment|// check all the entries from the given index
while|while
condition|(
name|chunkIndex
operator|<
name|tldIndices
index|[
name|index
operator|+
literal|1
index|]
operator|-
name|offset
condition|)
block|{
name|QString
name|currentEntry
init|=
name|QString
operator|::
name|fromUtf8
argument_list|(
name|tldData
index|[
name|chunk
index|]
operator|+
name|chunkIndex
argument_list|)
decl_stmt|;
if|if
condition|(
name|currentEntry
operator|==
name|entry
condition|)
return|return
literal|true
return|;
name|chunkIndex
operator|+=
name|qstrlen
argument_list|(
name|tldData
index|[
name|chunk
index|]
operator|+
name|chunkIndex
argument_list|)
operator|+
literal|1
expr_stmt|;
comment|// +1 for the ending \0
block|}
return|return
literal|false
return|;
block|}
end_function
begin_comment
comment|/*!     \internal      Return the top-level-domain per Qt's copy of the Mozilla public suffix list of     \a domain. */
end_comment
begin_function
DECL|function|qTopLevelDomain
name|Q_CORE_EXPORT
name|QString
name|qTopLevelDomain
parameter_list|(
specifier|const
name|QString
modifier|&
name|domain
parameter_list|)
block|{
specifier|const
name|QString
name|domainLower
init|=
name|domain
operator|.
name|toLower
argument_list|()
decl_stmt|;
name|QVector
argument_list|<
name|QStringRef
argument_list|>
name|sections
init|=
name|domainLower
operator|.
name|splitRef
argument_list|(
name|QLatin1Char
argument_list|(
literal|'.'
argument_list|)
argument_list|,
name|QString
operator|::
name|SkipEmptyParts
argument_list|)
decl_stmt|;
if|if
condition|(
name|sections
operator|.
name|isEmpty
argument_list|()
condition|)
return|return
name|QString
argument_list|()
return|;
name|QString
name|level
decl_stmt|,
name|tld
decl_stmt|;
for|for
control|(
name|int
name|j
init|=
name|sections
operator|.
name|count
argument_list|()
operator|-
literal|1
init|;
name|j
operator|>=
literal|0
condition|;
operator|--
name|j
control|)
block|{
name|level
operator|.
name|prepend
argument_list|(
name|QLatin1Char
argument_list|(
literal|'.'
argument_list|)
operator|+
name|sections
operator|.
name|at
argument_list|(
name|j
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|qIsEffectiveTLD
argument_list|(
name|level
operator|.
name|right
argument_list|(
name|level
operator|.
name|size
argument_list|()
operator|-
literal|1
argument_list|)
argument_list|)
condition|)
name|tld
operator|=
name|level
expr_stmt|;
block|}
return|return
name|tld
return|;
block|}
end_function
begin_comment
comment|/*!     \internal      Return true if \a domain is a top-level-domain per Qt's copy of the Mozilla public suffix list. */
end_comment
begin_function
DECL|function|qIsEffectiveTLD
name|Q_CORE_EXPORT
name|bool
name|qIsEffectiveTLD
parameter_list|(
specifier|const
name|QString
modifier|&
name|domain
parameter_list|)
block|{
comment|// for domain 'foo.bar.com':
comment|// 1. return if TLD table contains 'foo.bar.com'
if|if
condition|(
name|containsTLDEntry
argument_list|(
name|domain
argument_list|)
condition|)
return|return
literal|true
return|;
specifier|const
name|int
name|dot
init|=
name|domain
operator|.
name|indexOf
argument_list|(
name|QLatin1Char
argument_list|(
literal|'.'
argument_list|)
argument_list|)
decl_stmt|;
if|if
condition|(
name|dot
operator|>=
literal|0
condition|)
block|{
name|int
name|count
init|=
name|domain
operator|.
name|size
argument_list|()
operator|-
name|dot
decl_stmt|;
name|QString
name|wildCardDomain
init|=
name|QLatin1Char
argument_list|(
literal|'*'
argument_list|)
operator|+
name|domain
operator|.
name|rightRef
argument_list|(
name|count
argument_list|)
decl_stmt|;
comment|// 2. if table contains '*.bar.com',
comment|// test if table contains '!foo.bar.com'
if|if
condition|(
name|containsTLDEntry
argument_list|(
name|wildCardDomain
argument_list|)
condition|)
block|{
name|QString
name|exceptionDomain
init|=
name|QLatin1Char
argument_list|(
literal|'!'
argument_list|)
operator|+
name|domain
decl_stmt|;
return|return
operator|(
operator|!
name|containsTLDEntry
argument_list|(
name|exceptionDomain
argument_list|)
operator|)
return|;
block|}
block|}
return|return
literal|false
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
