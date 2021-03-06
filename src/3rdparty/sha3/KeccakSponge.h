begin_unit
begin_comment
comment|/* The Keccak sponge function, designed by Guido Bertoni, Joan Daemen, MichaÃ«l Peeters and Gilles Van Assche. For more information, feedback or questions, please refer to our website: http://keccak.noekeon.org/  Implementation by the designers, hereby denoted as "the implementer".  To the extent possible under law, the implementer has waived all copyright and related or neighboring rights to the source code in this file. http://creativecommons.org/publicdomain/zero/1.0/ */
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|_KeccakSponge_h_
end_ifndef
begin_define
DECL|macro|_KeccakSponge_h_
define|#
directive|define
name|_KeccakSponge_h_
end_define
begin_define
DECL|macro|KeccakPermutationSize
define|#
directive|define
name|KeccakPermutationSize
value|1600
end_define
begin_define
DECL|macro|KeccakPermutationSizeInBytes
define|#
directive|define
name|KeccakPermutationSizeInBytes
value|(KeccakPermutationSize/8)
end_define
begin_define
DECL|macro|KeccakMaximumRate
define|#
directive|define
name|KeccakMaximumRate
value|1536
end_define
begin_define
DECL|macro|KeccakMaximumRateInBytes
define|#
directive|define
name|KeccakMaximumRateInBytes
value|(KeccakMaximumRate/8)
end_define
begin_if
if|#
directive|if
name|defined
argument_list|(
name|UseSSE
argument_list|)
operator|||
name|defined
argument_list|(
name|UseXOP
argument_list|)
end_if
begin_if
if|#
directive|if
name|defined
argument_list|(
name|__GNUC__
argument_list|)
end_if
begin_define
DECL|macro|ALIGN
define|#
directive|define
name|ALIGN
value|__attribute__ ((aligned(32)))
end_define
begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|_MSC_VER
argument_list|)
end_elif
begin_define
DECL|macro|ALIGN
define|#
directive|define
name|ALIGN
value|__declspec(align(32))
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|ALIGN
end_ifndef
begin_define
DECL|macro|ALIGN
define|#
directive|define
name|ALIGN
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_macro
DECL|struct|spongeStateStruct
name|ALIGN
end_macro
begin_typedef
DECL|struct|spongeStateStruct
typedef|typedef
struct|struct
name|spongeStateStruct
block|{
DECL|member|state
name|ALIGN
name|unsigned
name|char
name|state
index|[
name|KeccakPermutationSizeInBytes
index|]
decl_stmt|;
DECL|member|dataQueue
name|ALIGN
name|unsigned
name|char
name|dataQueue
index|[
name|KeccakMaximumRateInBytes
index|]
decl_stmt|;
DECL|member|rate
name|unsigned
name|int
name|rate
decl_stmt|;
DECL|member|capacity
name|unsigned
name|int
name|capacity
decl_stmt|;
DECL|member|bitsInQueue
name|unsigned
name|int
name|bitsInQueue
decl_stmt|;
DECL|member|fixedOutputLength
name|unsigned
name|int
name|fixedOutputLength
decl_stmt|;
DECL|member|squeezing
name|int
name|squeezing
decl_stmt|;
DECL|member|bitsAvailableForSqueezing
name|unsigned
name|int
name|bitsAvailableForSqueezing
decl_stmt|;
block|}
DECL|typedef|spongeState
name|spongeState
typedef|;
end_typedef
begin_comment
comment|/**   * Function to initialize the state of the Keccak[r, c] sponge function.   * The sponge function is set to the absorbing phase.   * @param  state       Pointer to the state of the sponge function to be initialized.   * @param  rate        The value of the rate r.   * @param  capacity    The value of the capacity c.   * @pre    One must have r+c=1600 and the rate a multiple of 64 bits in this implementation.   * @return Zero if successful, 1 otherwise.   */
end_comment
begin_function_decl
specifier|static
name|int
name|InitSponge
parameter_list|(
name|spongeState
modifier|*
name|state
parameter_list|,
name|unsigned
name|int
name|rate
parameter_list|,
name|unsigned
name|int
name|capacity
parameter_list|)
function_decl|;
end_function_decl
begin_comment
comment|/**   * Function to give input data for the sponge function to absorb.   * @param  state       Pointer to the state of the sponge function initialized by InitSponge().   * @param  data        Pointer to the input data.    *                     When @a databitLen is not a multiple of 8, the last bits of data must be   *                     in the least significant bits of the last byte.   * @param  databitLen  The number of input bits provided in the input data.   * @pre    In the previous call to Absorb(), databitLen was a multiple of 8.   * @pre    The sponge function must be in the absorbing phase,   *         i.e., Squeeze() must not have been called before.   * @return Zero if successful, 1 otherwise.   */
end_comment
begin_function_decl
specifier|static
name|int
name|Absorb
parameter_list|(
name|spongeState
modifier|*
name|state
parameter_list|,
specifier|const
name|unsigned
name|char
modifier|*
name|data
parameter_list|,
name|unsigned
name|long
name|long
name|databitlen
parameter_list|)
function_decl|;
end_function_decl
begin_comment
comment|/**   * Function to squeeze output data from the sponge function.   * If the sponge function was in the absorbing phase, this function    * switches it to the squeezing phase.   * @param  state       Pointer to the state of the sponge function initialized by InitSponge().   * @param  output      Pointer to the buffer where to store the output data.   * @param  outputLength    The number of output bits desired.   *                     It must be a multiple of 8.   * @return Zero if successful, 1 otherwise.   */
end_comment
begin_function_decl
specifier|static
name|int
name|Squeeze
parameter_list|(
name|spongeState
modifier|*
name|state
parameter_list|,
name|unsigned
name|char
modifier|*
name|output
parameter_list|,
name|unsigned
name|long
name|long
name|outputLength
parameter_list|)
function_decl|;
end_function_decl
begin_endif
endif|#
directive|endif
end_endif
end_unit
