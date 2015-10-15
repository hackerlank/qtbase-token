begin_unit
begin_comment
comment|// Copyright 2010 the V8 project authors. All rights reserved.
end_comment
begin_comment
comment|// Redistribution and use in source and binary forms, with or without
end_comment
begin_comment
comment|// modification, are permitted provided that the following conditions are
end_comment
begin_comment
comment|// met:
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|//     * Redistributions of source code must retain the above copyright
end_comment
begin_comment
comment|//       notice, this list of conditions and the following disclaimer.
end_comment
begin_comment
comment|//     * Redistributions in binary form must reproduce the above
end_comment
begin_comment
comment|//       copyright notice, this list of conditions and the following
end_comment
begin_comment
comment|//       disclaimer in the documentation and/or other materials provided
end_comment
begin_comment
comment|//       with the distribution.
end_comment
begin_comment
comment|//     * Neither the name of Google Inc. nor the names of its
end_comment
begin_comment
comment|//       contributors may be used to endorse or promote products derived
end_comment
begin_comment
comment|//       from this software without specific prior written permission.
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
end_comment
begin_comment
comment|// "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
end_comment
begin_comment
comment|// LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
end_comment
begin_comment
comment|// A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
end_comment
begin_comment
comment|// OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
end_comment
begin_comment
comment|// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
end_comment
begin_comment
comment|// LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
end_comment
begin_comment
comment|// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
end_comment
begin_comment
comment|// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
end_comment
begin_comment
comment|// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
end_comment
begin_comment
comment|// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|DOUBLE_CONVERSION_BIGNUM_H_
end_ifndef
begin_define
DECL|macro|DOUBLE_CONVERSION_BIGNUM_H_
define|#
directive|define
name|DOUBLE_CONVERSION_BIGNUM_H_
end_define
begin_include
include|#
directive|include
file|"utils.h"
end_include
begin_decl_stmt
name|namespace
name|double_conversion
block|{
name|class
name|Bignum
block|{
name|public
label|:
comment|// 3584 = 128 * 28. We can represent 2^3584> 10^1000 accurately.
comment|// This bignum can encode much bigger numbers, since it contains an
comment|// exponent.
specifier|static
specifier|const
name|int
name|kMaxSignificantBits
init|=
literal|3584
decl_stmt|;
name|Bignum
argument_list|()
expr_stmt|;
name|void
name|AssignUInt16
parameter_list|(
name|uint16_t
name|value
parameter_list|)
function_decl|;
name|void
name|AssignUInt64
parameter_list|(
name|uint64_t
name|value
parameter_list|)
function_decl|;
name|void
name|AssignBignum
parameter_list|(
specifier|const
name|Bignum
modifier|&
name|other
parameter_list|)
function_decl|;
name|void
name|AssignDecimalString
argument_list|(
name|Vector
operator|<
specifier|const
name|char
operator|>
name|value
argument_list|)
decl_stmt|;
name|void
name|AssignHexString
argument_list|(
name|Vector
operator|<
specifier|const
name|char
operator|>
name|value
argument_list|)
decl_stmt|;
name|void
name|AssignPowerUInt16
parameter_list|(
name|uint16_t
name|base
parameter_list|,
name|int
name|exponent
parameter_list|)
function_decl|;
name|void
name|AddUInt16
parameter_list|(
name|uint16_t
name|operand
parameter_list|)
function_decl|;
name|void
name|AddUInt64
parameter_list|(
name|uint64_t
name|operand
parameter_list|)
function_decl|;
name|void
name|AddBignum
parameter_list|(
specifier|const
name|Bignum
modifier|&
name|other
parameter_list|)
function_decl|;
comment|// Precondition: this>= other.
name|void
name|SubtractBignum
parameter_list|(
specifier|const
name|Bignum
modifier|&
name|other
parameter_list|)
function_decl|;
name|void
name|Square
parameter_list|()
function_decl|;
name|void
name|ShiftLeft
parameter_list|(
name|int
name|shift_amount
parameter_list|)
function_decl|;
name|void
name|MultiplyByUInt32
parameter_list|(
name|uint32_t
name|factor
parameter_list|)
function_decl|;
name|void
name|MultiplyByUInt64
parameter_list|(
name|uint64_t
name|factor
parameter_list|)
function_decl|;
name|void
name|MultiplyByPowerOfTen
parameter_list|(
name|int
name|exponent
parameter_list|)
function_decl|;
name|void
name|Times10
parameter_list|()
block|{
return|return
name|MultiplyByUInt32
argument_list|(
literal|10
argument_list|)
return|;
block|}
comment|// Pseudocode:
comment|//  int result = this / other;
comment|//  this = this % other;
comment|// In the worst case this function is in O(this/other).
name|uint16_t
name|DivideModuloIntBignum
parameter_list|(
specifier|const
name|Bignum
modifier|&
name|other
parameter_list|)
function_decl|;
name|bool
name|ToHexString
argument_list|(
name|char
operator|*
name|buffer
argument_list|,
name|int
name|buffer_size
argument_list|)
decl|const
decl_stmt|;
comment|// Returns
comment|//  -1 if a< b,
comment|//   0 if a == b, and
comment|//  +1 if a> b.
specifier|static
name|int
name|Compare
parameter_list|(
specifier|const
name|Bignum
modifier|&
name|a
parameter_list|,
specifier|const
name|Bignum
modifier|&
name|b
parameter_list|)
function_decl|;
specifier|static
name|bool
name|Equal
parameter_list|(
specifier|const
name|Bignum
modifier|&
name|a
parameter_list|,
specifier|const
name|Bignum
modifier|&
name|b
parameter_list|)
block|{
return|return
name|Compare
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
operator|==
literal|0
return|;
block|}
specifier|static
name|bool
name|LessEqual
parameter_list|(
specifier|const
name|Bignum
modifier|&
name|a
parameter_list|,
specifier|const
name|Bignum
modifier|&
name|b
parameter_list|)
block|{
return|return
name|Compare
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
operator|<=
literal|0
return|;
block|}
specifier|static
name|bool
name|Less
parameter_list|(
specifier|const
name|Bignum
modifier|&
name|a
parameter_list|,
specifier|const
name|Bignum
modifier|&
name|b
parameter_list|)
block|{
return|return
name|Compare
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
operator|<
literal|0
return|;
block|}
comment|// Returns Compare(a + b, c);
specifier|static
name|int
name|PlusCompare
parameter_list|(
specifier|const
name|Bignum
modifier|&
name|a
parameter_list|,
specifier|const
name|Bignum
modifier|&
name|b
parameter_list|,
specifier|const
name|Bignum
modifier|&
name|c
parameter_list|)
function_decl|;
comment|// Returns a + b == c
specifier|static
name|bool
name|PlusEqual
parameter_list|(
specifier|const
name|Bignum
modifier|&
name|a
parameter_list|,
specifier|const
name|Bignum
modifier|&
name|b
parameter_list|,
specifier|const
name|Bignum
modifier|&
name|c
parameter_list|)
block|{
return|return
name|PlusCompare
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
operator|==
literal|0
return|;
block|}
comment|// Returns a + b<= c
specifier|static
name|bool
name|PlusLessEqual
parameter_list|(
specifier|const
name|Bignum
modifier|&
name|a
parameter_list|,
specifier|const
name|Bignum
modifier|&
name|b
parameter_list|,
specifier|const
name|Bignum
modifier|&
name|c
parameter_list|)
block|{
return|return
name|PlusCompare
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
operator|<=
literal|0
return|;
block|}
comment|// Returns a + b< c
specifier|static
name|bool
name|PlusLess
parameter_list|(
specifier|const
name|Bignum
modifier|&
name|a
parameter_list|,
specifier|const
name|Bignum
modifier|&
name|b
parameter_list|,
specifier|const
name|Bignum
modifier|&
name|c
parameter_list|)
block|{
return|return
name|PlusCompare
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
operator|<
literal|0
return|;
block|}
name|private
label|:
typedef|typedef
name|uint32_t
name|Chunk
typedef|;
typedef|typedef
name|uint64_t
name|DoubleChunk
typedef|;
specifier|static
specifier|const
name|int
name|kChunkSize
init|=
sizeof|sizeof
argument_list|(
name|Chunk
argument_list|)
operator|*
literal|8
decl_stmt|;
specifier|static
specifier|const
name|int
name|kDoubleChunkSize
init|=
sizeof|sizeof
argument_list|(
name|DoubleChunk
argument_list|)
operator|*
literal|8
decl_stmt|;
comment|// With bigit size of 28 we loose some bits, but a double still fits easily
comment|// into two chunks, and more importantly we can use the Comba multiplication.
specifier|static
specifier|const
name|int
name|kBigitSize
init|=
literal|28
decl_stmt|;
specifier|static
specifier|const
name|Chunk
name|kBigitMask
init|=
operator|(
literal|1
operator|<<
name|kBigitSize
operator|)
operator|-
literal|1
decl_stmt|;
comment|// Every instance allocates kBigitLength chunks on the stack. Bignums cannot
comment|// grow. There are no checks if the stack-allocated space is sufficient.
specifier|static
specifier|const
name|int
name|kBigitCapacity
init|=
name|kMaxSignificantBits
operator|/
name|kBigitSize
decl_stmt|;
name|void
name|EnsureCapacity
parameter_list|(
name|int
name|size
parameter_list|)
block|{
if|if
condition|(
name|size
operator|>
name|kBigitCapacity
condition|)
block|{
name|UNREACHABLE
argument_list|()
expr_stmt|;
block|}
block|}
name|void
name|Align
parameter_list|(
specifier|const
name|Bignum
modifier|&
name|other
parameter_list|)
function_decl|;
name|void
name|Clamp
parameter_list|()
function_decl|;
name|bool
name|IsClamped
argument_list|()
specifier|const
expr_stmt|;
name|void
name|Zero
parameter_list|()
function_decl|;
comment|// Requires this to have enough capacity (no tests done).
comment|// Updates used_digits_ if necessary.
comment|// shift_amount must be< kBigitSize.
name|void
name|BigitsShiftLeft
parameter_list|(
name|int
name|shift_amount
parameter_list|)
function_decl|;
comment|// BigitLength includes the "hidden" digits encoded in the exponent.
name|int
name|BigitLength
argument_list|()
specifier|const
block|{
return|return
name|used_digits_
operator|+
name|exponent_
return|;
block|}
name|Chunk
name|BigitAt
argument_list|(
name|int
name|index
argument_list|)
decl|const
decl_stmt|;
name|void
name|SubtractTimes
parameter_list|(
specifier|const
name|Bignum
modifier|&
name|other
parameter_list|,
name|int
name|factor
parameter_list|)
function_decl|;
name|Chunk
name|bigits_buffer_
index|[
name|kBigitCapacity
index|]
decl_stmt|;
comment|// A vector backed by bigits_buffer_. This way accesses to the array are
comment|// checked for out-of-bounds errors.
name|Vector
operator|<
name|Chunk
operator|>
name|bigits_
expr_stmt|;
name|int
name|used_digits_
decl_stmt|;
comment|// The Bignum's value equals value(bigits_) * 2^(exponent_ * kBigitSize).
name|int
name|exponent_
decl_stmt|;
name|DISALLOW_COPY_AND_ASSIGN
argument_list|(
name|Bignum
argument_list|)
expr_stmt|;
block|}
empty_stmt|;
block|}
end_decl_stmt
begin_comment
comment|// namespace double_conversion
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// DOUBLE_CONVERSION_BIGNUM_H_
end_comment
end_unit
