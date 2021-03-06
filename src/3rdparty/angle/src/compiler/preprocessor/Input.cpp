begin_unit
begin_comment
comment|//
end_comment
begin_comment
comment|// Copyright (c) 2011 The ANGLE Project Authors. All rights reserved.
end_comment
begin_comment
comment|// Use of this source code is governed by a BSD-style license that can be
end_comment
begin_comment
comment|// found in the LICENSE file.
end_comment
begin_comment
comment|//
end_comment
begin_include
include|#
directive|include
file|"Input.h"
end_include
begin_include
include|#
directive|include
file|<algorithm>
end_include
begin_include
include|#
directive|include
file|<cassert>
end_include
begin_include
include|#
directive|include
file|<cstring>
end_include
begin_namespace
DECL|namespace|pp
namespace|namespace
name|pp
block|{
DECL|function|Input
name|Input
operator|::
name|Input
parameter_list|()
member_init_list|:
name|mCount
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|mString
argument_list|(
literal|0
argument_list|)
block|{ }
DECL|function|Input
name|Input
operator|::
name|Input
parameter_list|(
name|size_t
name|count
parameter_list|,
specifier|const
name|char
modifier|*
specifier|const
name|string
index|[]
parameter_list|,
specifier|const
name|int
name|length
index|[]
parameter_list|)
member_init_list|:
name|mCount
argument_list|(
name|count
argument_list|)
member_init_list|,
name|mString
argument_list|(
name|string
argument_list|)
block|{
name|mLength
operator|.
name|reserve
argument_list|(
name|mCount
argument_list|)
expr_stmt|;
for|for
control|(
name|size_t
name|i
init|=
literal|0
init|;
name|i
operator|<
name|mCount
condition|;
operator|++
name|i
control|)
block|{
name|int
name|len
init|=
name|length
condition|?
name|length
index|[
name|i
index|]
else|:
operator|-
literal|1
decl_stmt|;
name|mLength
operator|.
name|push_back
argument_list|(
name|len
operator|<
literal|0
condition|?
name|std
operator|::
name|strlen
argument_list|(
name|mString
index|[
name|i
index|]
argument_list|)
else|:
name|len
argument_list|)
expr_stmt|;
block|}
block|}
DECL|function|skipChar
specifier|const
name|char
modifier|*
name|Input
operator|::
name|skipChar
parameter_list|()
block|{
comment|// This function should only be called when there is a character to skip.
name|assert
argument_list|(
name|mReadLoc
operator|.
name|cIndex
operator|<
name|mLength
index|[
name|mReadLoc
operator|.
name|sIndex
index|]
argument_list|)
expr_stmt|;
operator|++
name|mReadLoc
operator|.
name|cIndex
expr_stmt|;
if|if
condition|(
name|mReadLoc
operator|.
name|cIndex
operator|==
name|mLength
index|[
name|mReadLoc
operator|.
name|sIndex
index|]
condition|)
block|{
operator|++
name|mReadLoc
operator|.
name|sIndex
expr_stmt|;
name|mReadLoc
operator|.
name|cIndex
operator|=
literal|0
expr_stmt|;
block|}
if|if
condition|(
name|mReadLoc
operator|.
name|sIndex
operator|>=
name|mCount
condition|)
block|{
return|return
literal|nullptr
return|;
block|}
return|return
name|mString
index|[
name|mReadLoc
operator|.
name|sIndex
index|]
operator|+
name|mReadLoc
operator|.
name|cIndex
return|;
block|}
DECL|function|read
name|size_t
name|Input
operator|::
name|read
parameter_list|(
name|char
modifier|*
name|buf
parameter_list|,
name|size_t
name|maxSize
parameter_list|,
name|int
modifier|*
name|lineNo
parameter_list|)
block|{
name|size_t
name|nRead
init|=
literal|0
decl_stmt|;
comment|// The previous call to read might have stopped copying the string when encountering a line
comment|// continuation. Check for this possibility first.
if|if
condition|(
name|mReadLoc
operator|.
name|sIndex
argument_list|<
name|mCount
operator|&&
name|maxSize
argument_list|>
literal|0
condition|)
block|{
specifier|const
name|char
modifier|*
name|c
init|=
name|mString
index|[
name|mReadLoc
operator|.
name|sIndex
index|]
operator|+
name|mReadLoc
operator|.
name|cIndex
decl_stmt|;
if|if
condition|(
operator|(
operator|*
name|c
operator|)
operator|==
literal|'\\'
condition|)
block|{
name|c
operator|=
name|skipChar
argument_list|()
expr_stmt|;
if|if
condition|(
name|c
operator|!=
literal|nullptr
operator|&&
operator|(
operator|*
name|c
operator|)
operator|==
literal|'\n'
condition|)
block|{
comment|// Line continuation of backslash + newline.
name|skipChar
argument_list|()
expr_stmt|;
operator|++
operator|(
operator|*
name|lineNo
operator|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|c
operator|!=
literal|nullptr
operator|&&
operator|(
operator|*
name|c
operator|)
operator|==
literal|'\r'
condition|)
block|{
comment|// Line continuation. Could be backslash + '\r\n' or just backslash + '\r'.
name|c
operator|=
name|skipChar
argument_list|()
expr_stmt|;
if|if
condition|(
name|c
operator|!=
literal|nullptr
operator|&&
operator|(
operator|*
name|c
operator|)
operator|==
literal|'\n'
condition|)
block|{
name|skipChar
argument_list|()
expr_stmt|;
block|}
operator|++
operator|(
operator|*
name|lineNo
operator|)
expr_stmt|;
block|}
else|else
block|{
comment|// Not line continuation, so write the skipped backslash to buf.
operator|*
name|buf
operator|=
literal|'\\'
expr_stmt|;
operator|++
name|nRead
expr_stmt|;
block|}
block|}
block|}
name|size_t
name|maxRead
init|=
name|maxSize
decl_stmt|;
while|while
condition|(
operator|(
name|nRead
operator|<
name|maxRead
operator|)
operator|&&
operator|(
name|mReadLoc
operator|.
name|sIndex
operator|<
name|mCount
operator|)
condition|)
block|{
name|size_t
name|size
init|=
name|mLength
index|[
name|mReadLoc
operator|.
name|sIndex
index|]
operator|-
name|mReadLoc
operator|.
name|cIndex
decl_stmt|;
name|size
operator|=
name|std
operator|::
name|min
argument_list|(
name|size
argument_list|,
name|maxSize
argument_list|)
expr_stmt|;
for|for
control|(
name|size_t
name|i
init|=
literal|0
init|;
name|i
operator|<
name|size
condition|;
operator|++
name|i
control|)
block|{
comment|// Stop if a possible line continuation is encountered.
comment|// It will be processed on the next call on input, which skips it
comment|// and increments line number if necessary.
if|if
condition|(
operator|*
operator|(
name|mString
index|[
name|mReadLoc
operator|.
name|sIndex
index|]
operator|+
name|mReadLoc
operator|.
name|cIndex
operator|+
name|i
operator|)
operator|==
literal|'\\'
condition|)
block|{
name|size
operator|=
name|i
expr_stmt|;
name|maxRead
operator|=
name|nRead
operator|+
name|size
expr_stmt|;
comment|// Stop reading right before the backslash.
block|}
block|}
name|std
operator|::
name|memcpy
argument_list|(
name|buf
operator|+
name|nRead
argument_list|,
name|mString
index|[
name|mReadLoc
operator|.
name|sIndex
index|]
operator|+
name|mReadLoc
operator|.
name|cIndex
argument_list|,
name|size
argument_list|)
expr_stmt|;
name|nRead
operator|+=
name|size
expr_stmt|;
name|mReadLoc
operator|.
name|cIndex
operator|+=
name|size
expr_stmt|;
comment|// Advance string if we reached the end of current string.
if|if
condition|(
name|mReadLoc
operator|.
name|cIndex
operator|==
name|mLength
index|[
name|mReadLoc
operator|.
name|sIndex
index|]
condition|)
block|{
operator|++
name|mReadLoc
operator|.
name|sIndex
expr_stmt|;
name|mReadLoc
operator|.
name|cIndex
operator|=
literal|0
expr_stmt|;
block|}
block|}
return|return
name|nRead
return|;
block|}
block|}
end_namespace
begin_comment
comment|// namespace pp
end_comment
end_unit
