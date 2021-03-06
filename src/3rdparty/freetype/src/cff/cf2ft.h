begin_unit
begin_comment
comment|/***************************************************************************/
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  cf2ft.h                                                                */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*    FreeType Glue Component to Adobe's Interpreter (specification).      */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  Copyright 2013 Adobe Systems Incorporated.                             */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  This software, and all works of authorship, whether in source or       */
end_comment
begin_comment
comment|/*  object code form as indicated by the copyright notice(s) included      */
end_comment
begin_comment
comment|/*  herein (collectively, the "Work") is made available, and may only be   */
end_comment
begin_comment
comment|/*  used, modified, and distributed under the FreeType Project License,    */
end_comment
begin_comment
comment|/*  LICENSE.TXT.  Additionally, subject to the terms and conditions of the */
end_comment
begin_comment
comment|/*  FreeType Project License, each contributor to the Work hereby grants   */
end_comment
begin_comment
comment|/*  to any individual or legal entity exercising permissions granted by    */
end_comment
begin_comment
comment|/*  the FreeType Project License and this section (hereafter, "You" or     */
end_comment
begin_comment
comment|/*  "Your") a perpetual, worldwide, non-exclusive, no-charge,              */
end_comment
begin_comment
comment|/*  royalty-free, irrevocable (except as stated in this section) patent    */
end_comment
begin_comment
comment|/*  license to make, have made, use, offer to sell, sell, import, and      */
end_comment
begin_comment
comment|/*  otherwise transfer the Work, where such license applies only to those  */
end_comment
begin_comment
comment|/*  patent claims licensable by such contributor that are necessarily      */
end_comment
begin_comment
comment|/*  infringed by their contribution(s) alone or by combination of their    */
end_comment
begin_comment
comment|/*  contribution(s) with the Work to which such contribution(s) was        */
end_comment
begin_comment
comment|/*  submitted.  If You institute patent litigation against any entity      */
end_comment
begin_comment
comment|/*  (including a cross-claim or counterclaim in a lawsuit) alleging that   */
end_comment
begin_comment
comment|/*  the Work or a contribution incorporated within the Work constitutes    */
end_comment
begin_comment
comment|/*  direct or contributory patent infringement, then any patent licenses   */
end_comment
begin_comment
comment|/*  granted to You under this License for that Work shall terminate as of  */
end_comment
begin_comment
comment|/*  the date such litigation is filed.                                     */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  By using, modifying, or distributing the Work you indicate that you    */
end_comment
begin_comment
comment|/*  have read and understood the terms and conditions of the               */
end_comment
begin_comment
comment|/*  FreeType Project License as well as those provided in this section,    */
end_comment
begin_comment
comment|/*  and you accept them fully.                                             */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/***************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|__CF2FT_H__
end_ifndef
begin_define
DECL|macro|__CF2FT_H__
define|#
directive|define
name|__CF2FT_H__
end_define
begin_include
include|#
directive|include
file|"cf2types.h"
end_include
begin_comment
comment|/* TODO: disable asserts for now */
end_comment
begin_define
DECL|macro|CF2_NDEBUG
define|#
directive|define
name|CF2_NDEBUG
end_define
begin_include
include|#
directive|include
include|FT_SYSTEM_H
end_include
begin_include
include|#
directive|include
file|"cf2glue.h"
end_include
begin_include
include|#
directive|include
file|"cffgload.h"
end_include
begin_comment
comment|/* for CFF_Decoder */
end_comment
begin_function_decl
name|FT_BEGIN_HEADER
name|FT_LOCAL
parameter_list|(
name|FT_Error
parameter_list|)
function_decl|cf2_decoder_parse_charstrings
parameter_list|(
name|CFF_Decoder
modifier|*
name|decoder
parameter_list|,
name|FT_Byte
modifier|*
name|charstring_base
parameter_list|,
name|FT_ULong
name|charstring_len
parameter_list|)
function_decl|;
end_function_decl
begin_macro
name|FT_LOCAL
argument_list|(
argument|CFF_SubFont
argument_list|)
end_macro
begin_expr_stmt
DECL|variable|cf2_getSubfont
name|cf2_getSubfont
argument_list|(
name|CFF_Decoder
operator|*
name|decoder
argument_list|)
expr_stmt|;
end_expr_stmt
begin_macro
name|FT_LOCAL
argument_list|(
argument|CF2_Fixed
argument_list|)
end_macro
begin_expr_stmt
name|cf2_getPpemY
argument_list|(
name|CFF_Decoder
operator|*
name|decoder
argument_list|)
expr_stmt|;
end_expr_stmt
begin_macro
name|FT_LOCAL
argument_list|(
argument|CF2_Fixed
argument_list|)
end_macro
begin_expr_stmt
DECL|variable|cf2_getStdVW
name|cf2_getStdVW
argument_list|(
name|CFF_Decoder
operator|*
name|decoder
argument_list|)
expr_stmt|;
end_expr_stmt
begin_macro
name|FT_LOCAL
argument_list|(
argument|CF2_Fixed
argument_list|)
end_macro
begin_expr_stmt
name|cf2_getStdHW
argument_list|(
name|CFF_Decoder
operator|*
name|decoder
argument_list|)
expr_stmt|;
end_expr_stmt
begin_macro
name|FT_LOCAL
argument_list|(
argument|void
argument_list|)
end_macro
begin_expr_stmt
DECL|variable|cf2_getBlueMetrics
name|cf2_getBlueMetrics
argument_list|(
name|CFF_Decoder
operator|*
name|decoder
argument_list|,
name|CF2_Fixed
operator|*
name|blueScale
argument_list|,
name|CF2_Fixed
operator|*
name|blueShift
argument_list|,
name|CF2_Fixed
operator|*
name|blueFuzz
argument_list|)
expr_stmt|;
end_expr_stmt
begin_macro
name|FT_LOCAL
argument_list|(
argument|void
argument_list|)
end_macro
begin_expr_stmt
name|cf2_getBlueValues
argument_list|(
name|CFF_Decoder
operator|*
name|decoder
argument_list|,
name|size_t
operator|*
name|count
argument_list|,
name|FT_Pos
operator|*
operator|*
name|data
argument_list|)
expr_stmt|;
end_expr_stmt
begin_macro
name|FT_LOCAL
argument_list|(
argument|void
argument_list|)
end_macro
begin_expr_stmt
name|cf2_getOtherBlues
argument_list|(
name|CFF_Decoder
operator|*
name|decoder
argument_list|,
name|size_t
operator|*
name|count
argument_list|,
name|FT_Pos
operator|*
operator|*
name|data
argument_list|)
expr_stmt|;
end_expr_stmt
begin_macro
name|FT_LOCAL
argument_list|(
argument|void
argument_list|)
end_macro
begin_expr_stmt
name|cf2_getFamilyBlues
argument_list|(
name|CFF_Decoder
operator|*
name|decoder
argument_list|,
name|size_t
operator|*
name|count
argument_list|,
name|FT_Pos
operator|*
operator|*
name|data
argument_list|)
expr_stmt|;
end_expr_stmt
begin_macro
name|FT_LOCAL
argument_list|(
argument|void
argument_list|)
end_macro
begin_expr_stmt
name|cf2_getFamilyOtherBlues
argument_list|(
name|CFF_Decoder
operator|*
name|decoder
argument_list|,
name|size_t
operator|*
name|count
argument_list|,
name|FT_Pos
operator|*
operator|*
name|data
argument_list|)
expr_stmt|;
end_expr_stmt
begin_macro
name|FT_LOCAL
argument_list|(
argument|CF2_Int
argument_list|)
end_macro
begin_expr_stmt
name|cf2_getLanguageGroup
argument_list|(
name|CFF_Decoder
operator|*
name|decoder
argument_list|)
expr_stmt|;
end_expr_stmt
begin_macro
name|FT_LOCAL
argument_list|(
argument|CF2_Int
argument_list|)
end_macro
begin_macro
DECL|variable|cf2_initGlobalRegionBuffer
name|cf2_initGlobalRegionBuffer
argument_list|(
argument|CFF_Decoder*  decoder
argument_list|,
argument|CF2_UInt      idx
argument_list|,
argument|CF2_Buffer    buf
argument_list|)
end_macro
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_macro
name|FT_LOCAL
argument_list|(
argument|FT_Error
argument_list|)
end_macro
begin_macro
name|cf2_getSeacComponent
argument_list|(
argument|CFF_Decoder*  decoder
argument_list|,
argument|CF2_Int       code
argument_list|,
argument|CF2_Buffer    buf
argument_list|)
end_macro
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_macro
name|FT_LOCAL
argument_list|(
argument|void
argument_list|)
end_macro
begin_macro
DECL|variable|cf2_freeSeacComponent
name|cf2_freeSeacComponent
argument_list|(
argument|CFF_Decoder*  decoder
argument_list|,
argument|CF2_Buffer    buf
argument_list|)
end_macro
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_macro
name|FT_LOCAL
argument_list|(
argument|CF2_Int
argument_list|)
end_macro
begin_macro
name|cf2_initLocalRegionBuffer
argument_list|(
argument|CFF_Decoder*  decoder
argument_list|,
argument|CF2_UInt      idx
argument_list|,
argument|CF2_Buffer    buf
argument_list|)
end_macro
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_macro
name|FT_LOCAL
argument_list|(
argument|CF2_Fixed
argument_list|)
end_macro
begin_expr_stmt
DECL|variable|cf2_getDefaultWidthX
name|cf2_getDefaultWidthX
argument_list|(
name|CFF_Decoder
operator|*
name|decoder
argument_list|)
expr_stmt|;
end_expr_stmt
begin_macro
name|FT_LOCAL
argument_list|(
argument|CF2_Fixed
argument_list|)
end_macro
begin_expr_stmt
name|cf2_getNominalWidthX
argument_list|(
name|CFF_Decoder
operator|*
name|decoder
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|/*    * FreeType client outline    *    * process output from the charstring interpreter    */
end_comment
begin_typedef
DECL|struct|CF2_OutlineRec_
typedef|typedef
struct|struct
name|CF2_OutlineRec_
block|{
DECL|member|root
name|CF2_OutlineCallbacksRec
name|root
decl_stmt|;
comment|/* base class must be first */
DECL|member|decoder
name|CFF_Decoder
modifier|*
name|decoder
decl_stmt|;
block|}
DECL|typedef|CF2_OutlineRec
DECL|typedef|CF2_Outline
name|CF2_OutlineRec
operator|,
typedef|*
name|CF2_Outline
typedef|;
end_typedef
begin_macro
name|FT_LOCAL
argument_list|(
argument|void
argument_list|)
end_macro
begin_macro
DECL|variable|outline
name|cf2_outline_reset
argument_list|(
argument|CF2_Outline  outline
argument_list|)
end_macro
begin_empty_stmt
DECL|variable|outline
empty_stmt|;
end_empty_stmt
begin_macro
name|FT_LOCAL
argument_list|(
argument|void
argument_list|)
end_macro
begin_macro
DECL|variable|outline
name|cf2_outline_close
argument_list|(
argument|CF2_Outline  outline
argument_list|)
end_macro
begin_empty_stmt
DECL|variable|outline
empty_stmt|;
end_empty_stmt
begin_macro
name|FT_END_HEADER
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* __CF2FT_H__ */
end_comment
begin_comment
comment|/* END */
end_comment
end_unit
