begin_unit
begin_comment
comment|/***************************************************************************/
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  pshints.h                                                              */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*    Interface to Postscript-specific (Type 1 and Type 2) hints           */
end_comment
begin_comment
comment|/*    recorders (specification only).  These are used to support native    */
end_comment
begin_comment
comment|/*    T1/T2 hints in the `type1', `cid', and `cff' font drivers.           */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  Copyright 2001-2015 by                                                 */
end_comment
begin_comment
comment|/*  David Turner, Robert Wilhelm, and Werner Lemberg.                      */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  This file is part of the FreeType project, and may only be used,       */
end_comment
begin_comment
comment|/*  modified, and distributed under the terms of the FreeType project      */
end_comment
begin_comment
comment|/*  license, LICENSE.TXT.  By continuing to use, modify, or distribute     */
end_comment
begin_comment
comment|/*  this file you indicate that you have read the license and              */
end_comment
begin_comment
comment|/*  understand and accept it fully.                                        */
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
name|__PSHINTS_H__
end_ifndef
begin_define
DECL|macro|__PSHINTS_H__
define|#
directive|define
name|__PSHINTS_H__
end_define
begin_include
include|#
directive|include
file|<ft2build.h>
end_include
begin_include
include|#
directive|include
include|FT_FREETYPE_H
end_include
begin_include
include|#
directive|include
include|FT_TYPE1_TABLES_H
end_include
begin_macro
name|FT_BEGIN_HEADER
end_macro
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*****                                                               *****/
end_comment
begin_comment
comment|/*****               INTERNAL REPRESENTATION OF GLOBALS              *****/
end_comment
begin_comment
comment|/*****                                                               *****/
end_comment
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*************************************************************************/
end_comment
begin_typedef
DECL|typedef|PSH_Globals
typedef|typedef
name|struct
name|PSH_GlobalsRec_
modifier|*
name|PSH_Globals
typedef|;
end_typedef
begin_typedef
typedef|typedef
name|FT_Error
function_decl|(
DECL|typedef|PSH_Globals_NewFunc
modifier|*
name|PSH_Globals_NewFunc
function_decl|)
parameter_list|(
name|FT_Memory
name|memory
parameter_list|,
name|T1_Private
modifier|*
name|private_dict
parameter_list|,
name|PSH_Globals
modifier|*
name|aglobals
parameter_list|)
function_decl|;
end_typedef
begin_typedef
typedef|typedef
name|void
function_decl|(
DECL|typedef|PSH_Globals_SetScaleFunc
modifier|*
name|PSH_Globals_SetScaleFunc
function_decl|)
parameter_list|(
name|PSH_Globals
name|globals
parameter_list|,
name|FT_Fixed
name|x_scale
parameter_list|,
name|FT_Fixed
name|y_scale
parameter_list|,
name|FT_Fixed
name|x_delta
parameter_list|,
name|FT_Fixed
name|y_delta
parameter_list|)
function_decl|;
end_typedef
begin_typedef
typedef|typedef
name|void
function_decl|(
DECL|typedef|PSH_Globals_DestroyFunc
modifier|*
name|PSH_Globals_DestroyFunc
function_decl|)
parameter_list|(
name|PSH_Globals
name|globals
parameter_list|)
function_decl|;
end_typedef
begin_typedef
DECL|struct|PSH_Globals_FuncsRec_
typedef|typedef
struct|struct
name|PSH_Globals_FuncsRec_
block|{
DECL|member|create
name|PSH_Globals_NewFunc
name|create
decl_stmt|;
DECL|member|set_scale
name|PSH_Globals_SetScaleFunc
name|set_scale
decl_stmt|;
DECL|member|destroy
name|PSH_Globals_DestroyFunc
name|destroy
decl_stmt|;
block|}
DECL|typedef|PSH_Globals_FuncsRec
DECL|typedef|PSH_Globals_Funcs
name|PSH_Globals_FuncsRec
operator|,
typedef|*
name|PSH_Globals_Funcs
typedef|;
end_typedef
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*****                                                               *****/
end_comment
begin_comment
comment|/*****                  PUBLIC TYPE 1 HINTS RECORDER                 *****/
end_comment
begin_comment
comment|/*****                                                               *****/
end_comment
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*************************************************************************    *    * @type:    *   T1_Hints    *    * @description:    *   This is a handle to an opaque structure used to record glyph hints    *   from a Type 1 character glyph character string.    *    *   The methods used to operate on this object are defined by the    *   @T1_Hints_FuncsRec structure.  Recording glyph hints is normally    *   achieved through the following scheme:    *    *   - Open a new hint recording session by calling the `open' method.    *     This rewinds the recorder and prepare it for new input.    *    *   - For each hint found in the glyph charstring, call the corresponding    *     method (`stem', `stem3', or `reset').  Note that these functions do    *     not return an error code.    *    *   - Close the recording session by calling the `close' method.  It    *     returns an error code if the hints were invalid or something    *     strange happened (e.g., memory shortage).    *    *   The hints accumulated in the object can later be used by the    *   PostScript hinter.    *    */
end_comment
begin_typedef
DECL|typedef|T1_Hints
typedef|typedef
name|struct
name|T1_HintsRec_
modifier|*
name|T1_Hints
typedef|;
end_typedef
begin_comment
comment|/*************************************************************************    *    * @type:    *   T1_Hints_Funcs    *    * @description:    *   A pointer to the @T1_Hints_FuncsRec structure that defines the API of    *   a given @T1_Hints object.    *    */
end_comment
begin_typedef
DECL|typedef|T1_Hints_Funcs
typedef|typedef
specifier|const
name|struct
name|T1_Hints_FuncsRec_
modifier|*
name|T1_Hints_Funcs
typedef|;
end_typedef
begin_comment
comment|/*************************************************************************    *    * @functype:    *   T1_Hints_OpenFunc    *    * @description:    *   A method of the @T1_Hints class used to prepare it for a new Type 1    *   hints recording session.    *    * @input:    *   hints ::    *     A handle to the Type 1 hints recorder.    *    * @note:    *   You should always call the @T1_Hints_CloseFunc method in order to    *   close an opened recording session.    *    */
end_comment
begin_typedef
typedef|typedef
name|void
function_decl|(
DECL|typedef|T1_Hints_OpenFunc
modifier|*
name|T1_Hints_OpenFunc
function_decl|)
parameter_list|(
name|T1_Hints
name|hints
parameter_list|)
function_decl|;
end_typedef
begin_comment
comment|/*************************************************************************    *    * @functype:    *   T1_Hints_SetStemFunc    *    * @description:    *   A method of the @T1_Hints class used to record a new horizontal or    *   vertical stem.  This corresponds to the Type 1 `hstem' and `vstem'    *   operators.    *    * @input:    *   hints ::    *     A handle to the Type 1 hints recorder.    *    *   dimension ::    *     0 for horizontal stems (hstem), 1 for vertical ones (vstem).    *    *   coords ::    *     Array of 2 coordinates in 16.16 format, used as (position,length)    *     stem descriptor.    *    * @note:    *   Use vertical coordinates (y) for horizontal stems (dim=0).  Use    *   horizontal coordinates (x) for vertical stems (dim=1).    *    *   `coords[0]' is the absolute stem position (lowest coordinate);    *   `coords[1]' is the length.    *    *   The length can be negative, in which case it must be either -20 or    *   -21.  It is interpreted as a `ghost' stem, according to the Type 1    *   specification.    *    *   If the length is -21 (corresponding to a bottom ghost stem), then    *   the real stem position is `coords[0]+coords[1]'.    *    */
end_comment
begin_typedef
typedef|typedef
name|void
function_decl|(
DECL|typedef|T1_Hints_SetStemFunc
modifier|*
name|T1_Hints_SetStemFunc
function_decl|)
parameter_list|(
name|T1_Hints
name|hints
parameter_list|,
name|FT_UInt
name|dimension
parameter_list|,
name|FT_Fixed
modifier|*
name|coords
parameter_list|)
function_decl|;
end_typedef
begin_comment
comment|/*************************************************************************    *    * @functype:    *   T1_Hints_SetStem3Func    *    * @description:    *   A method of the @T1_Hints class used to record three    *   counter-controlled horizontal or vertical stems at once.    *    * @input:    *   hints ::    *     A handle to the Type 1 hints recorder.    *    *   dimension ::    *     0 for horizontal stems, 1 for vertical ones.    *    *   coords ::    *     An array of 6 values in 16.16 format, holding 3 (position,length)    *     pairs for the counter-controlled stems.    *    * @note:    *   Use vertical coordinates (y) for horizontal stems (dim=0).  Use    *   horizontal coordinates (x) for vertical stems (dim=1).    *    *   The lengths cannot be negative (ghost stems are never    *   counter-controlled).    *    */
end_comment
begin_typedef
typedef|typedef
name|void
function_decl|(
DECL|typedef|T1_Hints_SetStem3Func
modifier|*
name|T1_Hints_SetStem3Func
function_decl|)
parameter_list|(
name|T1_Hints
name|hints
parameter_list|,
name|FT_UInt
name|dimension
parameter_list|,
name|FT_Fixed
modifier|*
name|coords
parameter_list|)
function_decl|;
end_typedef
begin_comment
comment|/*************************************************************************    *    * @functype:    *   T1_Hints_ResetFunc    *    * @description:    *   A method of the @T1_Hints class used to reset the stems hints in a    *   recording session.    *    * @input:    *   hints ::    *     A handle to the Type 1 hints recorder.    *    *   end_point ::    *     The index of the last point in the input glyph in which the    *     previously defined hints apply.    *    */
end_comment
begin_typedef
typedef|typedef
name|void
function_decl|(
DECL|typedef|T1_Hints_ResetFunc
modifier|*
name|T1_Hints_ResetFunc
function_decl|)
parameter_list|(
name|T1_Hints
name|hints
parameter_list|,
name|FT_UInt
name|end_point
parameter_list|)
function_decl|;
end_typedef
begin_comment
comment|/*************************************************************************    *    * @functype:    *   T1_Hints_CloseFunc    *    * @description:    *   A method of the @T1_Hints class used to close a hint recording    *   session.    *    * @input:    *   hints ::    *     A handle to the Type 1 hints recorder.    *    *   end_point ::    *     The index of the last point in the input glyph.    *    * @return:    *   FreeType error code.  0 means success.    *    * @note:    *   The error code is set to indicate that an error occurred during the    *   recording session.    *    */
end_comment
begin_typedef
typedef|typedef
name|FT_Error
function_decl|(
DECL|typedef|T1_Hints_CloseFunc
modifier|*
name|T1_Hints_CloseFunc
function_decl|)
parameter_list|(
name|T1_Hints
name|hints
parameter_list|,
name|FT_UInt
name|end_point
parameter_list|)
function_decl|;
end_typedef
begin_comment
comment|/*************************************************************************    *    * @functype:    *   T1_Hints_ApplyFunc    *    * @description:    *   A method of the @T1_Hints class used to apply hints to the    *   corresponding glyph outline.  Must be called once all hints have been    *   recorded.    *    * @input:    *   hints ::    *     A handle to the Type 1 hints recorder.    *    *   outline ::    *     A pointer to the target outline descriptor.    *    *   globals ::    *     The hinter globals for this font.    *    *   hint_mode ::    *     Hinting information.    *    * @return:    *   FreeType error code.  0 means success.    *    * @note:    *   On input, all points within the outline are in font coordinates. On    *   output, they are in 1/64th of pixels.    *    *   The scaling transformation is taken from the `globals' object which    *   must correspond to the same font as the glyph.    *    */
end_comment
begin_typedef
typedef|typedef
name|FT_Error
function_decl|(
DECL|typedef|T1_Hints_ApplyFunc
modifier|*
name|T1_Hints_ApplyFunc
function_decl|)
parameter_list|(
name|T1_Hints
name|hints
parameter_list|,
name|FT_Outline
modifier|*
name|outline
parameter_list|,
name|PSH_Globals
name|globals
parameter_list|,
name|FT_Render_Mode
name|hint_mode
parameter_list|)
function_decl|;
end_typedef
begin_comment
comment|/*************************************************************************    *    * @struct:    *   T1_Hints_FuncsRec    *    * @description:    *   The structure used to provide the API to @T1_Hints objects.    *    * @fields:    *   hints ::    *     A handle to the T1 Hints recorder.    *    *   open ::    *     The function to open a recording session.    *    *   close ::    *     The function to close a recording session.    *    *   stem ::    *     The function to set a simple stem.    *    *   stem3 ::    *     The function to set counter-controlled stems.    *    *   reset ::    *     The function to reset stem hints.    *    *   apply ::    *     The function to apply the hints to the corresponding glyph outline.    *    */
end_comment
begin_typedef
DECL|struct|T1_Hints_FuncsRec_
typedef|typedef
struct|struct
name|T1_Hints_FuncsRec_
block|{
DECL|member|hints
name|T1_Hints
name|hints
decl_stmt|;
DECL|member|open
name|T1_Hints_OpenFunc
name|open
decl_stmt|;
DECL|member|close
name|T1_Hints_CloseFunc
name|close
decl_stmt|;
DECL|member|stem
name|T1_Hints_SetStemFunc
name|stem
decl_stmt|;
DECL|member|stem3
name|T1_Hints_SetStem3Func
name|stem3
decl_stmt|;
DECL|member|reset
name|T1_Hints_ResetFunc
name|reset
decl_stmt|;
DECL|member|apply
name|T1_Hints_ApplyFunc
name|apply
decl_stmt|;
block|}
DECL|typedef|T1_Hints_FuncsRec
name|T1_Hints_FuncsRec
typedef|;
end_typedef
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*****                                                               *****/
end_comment
begin_comment
comment|/*****                  PUBLIC TYPE 2 HINTS RECORDER                 *****/
end_comment
begin_comment
comment|/*****                                                               *****/
end_comment
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*************************************************************************    *    * @type:    *   T2_Hints    *    * @description:    *   This is a handle to an opaque structure used to record glyph hints    *   from a Type 2 character glyph character string.    *    *   The methods used to operate on this object are defined by the    *   @T2_Hints_FuncsRec structure.  Recording glyph hints is normally    *   achieved through the following scheme:    *    *   - Open a new hint recording session by calling the `open' method.    *     This rewinds the recorder and prepare it for new input.    *    *   - For each hint found in the glyph charstring, call the corresponding    *     method (`stems', `hintmask', `counters').  Note that these    *     functions do not return an error code.    *    *   - Close the recording session by calling the `close' method.  It    *     returns an error code if the hints were invalid or something    *     strange happened (e.g., memory shortage).    *    *   The hints accumulated in the object can later be used by the    *   Postscript hinter.    *    */
end_comment
begin_typedef
DECL|typedef|T2_Hints
typedef|typedef
name|struct
name|T2_HintsRec_
modifier|*
name|T2_Hints
typedef|;
end_typedef
begin_comment
comment|/*************************************************************************    *    * @type:    *   T2_Hints_Funcs    *    * @description:    *   A pointer to the @T2_Hints_FuncsRec structure that defines the API of    *   a given @T2_Hints object.    *    */
end_comment
begin_typedef
DECL|typedef|T2_Hints_Funcs
typedef|typedef
specifier|const
name|struct
name|T2_Hints_FuncsRec_
modifier|*
name|T2_Hints_Funcs
typedef|;
end_typedef
begin_comment
comment|/*************************************************************************    *    * @functype:    *   T2_Hints_OpenFunc    *    * @description:    *   A method of the @T2_Hints class used to prepare it for a new Type 2    *   hints recording session.    *    * @input:    *   hints ::    *     A handle to the Type 2 hints recorder.    *    * @note:    *   You should always call the @T2_Hints_CloseFunc method in order to    *   close an opened recording session.    *    */
end_comment
begin_typedef
typedef|typedef
name|void
function_decl|(
DECL|typedef|T2_Hints_OpenFunc
modifier|*
name|T2_Hints_OpenFunc
function_decl|)
parameter_list|(
name|T2_Hints
name|hints
parameter_list|)
function_decl|;
end_typedef
begin_comment
comment|/*************************************************************************    *    * @functype:    *   T2_Hints_StemsFunc    *    * @description:    *   A method of the @T2_Hints class used to set the table of stems in    *   either the vertical or horizontal dimension.  Equivalent to the    *   `hstem', `vstem', `hstemhm', and `vstemhm' Type 2 operators.    *    * @input:    *   hints ::    *     A handle to the Type 2 hints recorder.    *    *   dimension ::    *     0 for horizontal stems (hstem), 1 for vertical ones (vstem).    *    *   count ::    *     The number of stems.    *    *   coords ::    *     An array of `count' (position,length) pairs in 16.16 format.    *    * @note:    *   Use vertical coordinates (y) for horizontal stems (dim=0).  Use    *   horizontal coordinates (x) for vertical stems (dim=1).    *    *   There are `2*count' elements in the `coords' array.  Each even    *   element is an absolute position in font units, each odd element is a    *   length in font units.    *    *   A length can be negative, in which case it must be either -20 or    *   -21.  It is interpreted as a `ghost' stem, according to the Type 1    *   specification.    *    */
end_comment
begin_typedef
typedef|typedef
name|void
function_decl|(
DECL|typedef|T2_Hints_StemsFunc
modifier|*
name|T2_Hints_StemsFunc
function_decl|)
parameter_list|(
name|T2_Hints
name|hints
parameter_list|,
name|FT_UInt
name|dimension
parameter_list|,
name|FT_Int
name|count
parameter_list|,
name|FT_Fixed
modifier|*
name|coordinates
parameter_list|)
function_decl|;
end_typedef
begin_comment
comment|/*************************************************************************    *    * @functype:    *   T2_Hints_MaskFunc    *    * @description:    *   A method of the @T2_Hints class used to set a given hintmask (this    *   corresponds to the `hintmask' Type 2 operator).    *    * @input:    *   hints ::    *     A handle to the Type 2 hints recorder.    *    *   end_point ::    *     The glyph index of the last point to which the previously defined    *     or activated hints apply.    *    *   bit_count ::    *     The number of bits in the hint mask.    *    *   bytes ::    *     An array of bytes modelling the hint mask.    *    * @note:    *   If the hintmask starts the charstring (before any glyph point    *   definition), the value of `end_point' should be 0.    *    *   `bit_count' is the number of meaningful bits in the `bytes' array; it    *   must be equal to the total number of hints defined so far (i.e.,    *   horizontal+verticals).    *    *   The `bytes' array can come directly from the Type 2 charstring and    *   respects the same format.    *    */
end_comment
begin_typedef
typedef|typedef
name|void
function_decl|(
DECL|typedef|T2_Hints_MaskFunc
modifier|*
name|T2_Hints_MaskFunc
function_decl|)
parameter_list|(
name|T2_Hints
name|hints
parameter_list|,
name|FT_UInt
name|end_point
parameter_list|,
name|FT_UInt
name|bit_count
parameter_list|,
specifier|const
name|FT_Byte
modifier|*
name|bytes
parameter_list|)
function_decl|;
end_typedef
begin_comment
comment|/*************************************************************************    *    * @functype:    *   T2_Hints_CounterFunc    *    * @description:    *   A method of the @T2_Hints class used to set a given counter mask    *   (this corresponds to the `hintmask' Type 2 operator).    *    * @input:    *   hints ::    *     A handle to the Type 2 hints recorder.    *    *   end_point ::    *     A glyph index of the last point to which the previously defined or    *     active hints apply.    *    *   bit_count ::    *     The number of bits in the hint mask.    *    *   bytes ::    *     An array of bytes modelling the hint mask.    *    * @note:    *   If the hintmask starts the charstring (before any glyph point    *   definition), the value of `end_point' should be 0.    *    *   `bit_count' is the number of meaningful bits in the `bytes' array; it    *   must be equal to the total number of hints defined so far (i.e.,    *   horizontal+verticals).    *    *    The `bytes' array can come directly from the Type 2 charstring and    *    respects the same format.    *    */
end_comment
begin_typedef
typedef|typedef
name|void
function_decl|(
DECL|typedef|T2_Hints_CounterFunc
modifier|*
name|T2_Hints_CounterFunc
function_decl|)
parameter_list|(
name|T2_Hints
name|hints
parameter_list|,
name|FT_UInt
name|bit_count
parameter_list|,
specifier|const
name|FT_Byte
modifier|*
name|bytes
parameter_list|)
function_decl|;
end_typedef
begin_comment
comment|/*************************************************************************    *    * @functype:    *   T2_Hints_CloseFunc    *    * @description:    *   A method of the @T2_Hints class used to close a hint recording    *   session.    *    * @input:    *   hints ::    *     A handle to the Type 2 hints recorder.    *    *   end_point ::    *     The index of the last point in the input glyph.    *    * @return:    *   FreeType error code.  0 means success.    *    * @note:    *   The error code is set to indicate that an error occurred during the    *   recording session.    *    */
end_comment
begin_typedef
typedef|typedef
name|FT_Error
function_decl|(
DECL|typedef|T2_Hints_CloseFunc
modifier|*
name|T2_Hints_CloseFunc
function_decl|)
parameter_list|(
name|T2_Hints
name|hints
parameter_list|,
name|FT_UInt
name|end_point
parameter_list|)
function_decl|;
end_typedef
begin_comment
comment|/*************************************************************************    *    * @functype:    *   T2_Hints_ApplyFunc    *    * @description:    *   A method of the @T2_Hints class used to apply hints to the    *   corresponding glyph outline.  Must be called after the `close'    *   method.    *    * @input:    *   hints ::    *     A handle to the Type 2 hints recorder.    *    *   outline ::    *     A pointer to the target outline descriptor.    *    *   globals ::    *     The hinter globals for this font.    *    *   hint_mode ::    *     Hinting information.    *    * @return:    *   FreeType error code.  0 means success.    *    * @note:    *   On input, all points within the outline are in font coordinates. On    *   output, they are in 1/64th of pixels.    *    *   The scaling transformation is taken from the `globals' object which    *   must correspond to the same font than the glyph.    *    */
end_comment
begin_typedef
typedef|typedef
name|FT_Error
function_decl|(
DECL|typedef|T2_Hints_ApplyFunc
modifier|*
name|T2_Hints_ApplyFunc
function_decl|)
parameter_list|(
name|T2_Hints
name|hints
parameter_list|,
name|FT_Outline
modifier|*
name|outline
parameter_list|,
name|PSH_Globals
name|globals
parameter_list|,
name|FT_Render_Mode
name|hint_mode
parameter_list|)
function_decl|;
end_typedef
begin_comment
comment|/*************************************************************************    *    * @struct:    *   T2_Hints_FuncsRec    *    * @description:    *   The structure used to provide the API to @T2_Hints objects.    *    * @fields:    *   hints ::    *     A handle to the T2 hints recorder object.    *    *   open ::    *     The function to open a recording session.    *    *   close ::    *     The function to close a recording session.    *    *   stems ::    *     The function to set the dimension's stems table.    *    *   hintmask ::    *     The function to set hint masks.    *    *   counter ::    *     The function to set counter masks.    *    *   apply ::    *     The function to apply the hints on the corresponding glyph outline.    *    */
end_comment
begin_typedef
DECL|struct|T2_Hints_FuncsRec_
typedef|typedef
struct|struct
name|T2_Hints_FuncsRec_
block|{
DECL|member|hints
name|T2_Hints
name|hints
decl_stmt|;
DECL|member|open
name|T2_Hints_OpenFunc
name|open
decl_stmt|;
DECL|member|close
name|T2_Hints_CloseFunc
name|close
decl_stmt|;
DECL|member|stems
name|T2_Hints_StemsFunc
name|stems
decl_stmt|;
DECL|member|hintmask
name|T2_Hints_MaskFunc
name|hintmask
decl_stmt|;
DECL|member|counter
name|T2_Hints_CounterFunc
name|counter
decl_stmt|;
DECL|member|apply
name|T2_Hints_ApplyFunc
name|apply
decl_stmt|;
block|}
DECL|typedef|T2_Hints_FuncsRec
name|T2_Hints_FuncsRec
typedef|;
end_typedef
begin_comment
comment|/* */
end_comment
begin_typedef
DECL|struct|PSHinter_Interface_
typedef|typedef
struct|struct
name|PSHinter_Interface_
block|{
DECL|member|get_globals_funcs
name|PSH_Globals_Funcs
function_decl|(
modifier|*
name|get_globals_funcs
function_decl|)
parameter_list|(
name|FT_Module
name|module
parameter_list|)
function_decl|;
DECL|member|get_t1_funcs
name|T1_Hints_Funcs
function_decl|(
modifier|*
name|get_t1_funcs
function_decl|)
parameter_list|(
name|FT_Module
name|module
parameter_list|)
function_decl|;
DECL|member|get_t2_funcs
name|T2_Hints_Funcs
function_decl|(
modifier|*
name|get_t2_funcs
function_decl|)
parameter_list|(
name|FT_Module
name|module
parameter_list|)
function_decl|;
block|}
DECL|typedef|PSHinter_Interface
name|PSHinter_Interface
typedef|;
end_typedef
begin_typedef
DECL|typedef|PSHinter_Service
typedef|typedef
name|PSHinter_Interface
modifier|*
name|PSHinter_Service
typedef|;
end_typedef
begin_ifndef
ifndef|#
directive|ifndef
name|FT_CONFIG_OPTION_PIC
end_ifndef
begin_define
DECL|macro|FT_DEFINE_PSHINTER_INTERFACE
define|#
directive|define
name|FT_DEFINE_PSHINTER_INTERFACE
parameter_list|(        \
name|class_
parameter_list|,                            \
name|get_globals_funcs_
parameter_list|,                \
name|get_t1_funcs_
parameter_list|,                     \
name|get_t2_funcs_
parameter_list|)
define|\
value|static const PSHinter_Interface  class_ =  \   {                                          \     get_globals_funcs_,                      \     get_t1_funcs_,                           \     get_t2_funcs_                            \   };
end_define
begin_else
else|#
directive|else
end_else
begin_comment
comment|/* FT_CONFIG_OPTION_PIC */
end_comment
begin_define
DECL|macro|FT_DEFINE_PSHINTER_INTERFACE
define|#
directive|define
name|FT_DEFINE_PSHINTER_INTERFACE
parameter_list|(                      \
name|class_
parameter_list|,                                          \
name|get_globals_funcs_
parameter_list|,                              \
name|get_t1_funcs_
parameter_list|,                                   \
name|get_t2_funcs_
parameter_list|)
define|\
value|void                                                     \   FT_Init_Class_ ## class_( FT_Library           library,  \                             PSHinter_Interface*  clazz )   \   {                                                        \     FT_UNUSED( library );                                  \                                                            \     clazz->get_globals_funcs = get_globals_funcs_;         \     clazz->get_t1_funcs      = get_t1_funcs_;              \     clazz->get_t2_funcs      = get_t2_funcs_;              \   }
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* FT_CONFIG_OPTION_PIC */
end_comment
begin_macro
name|FT_END_HEADER
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* __PSHINTS_H__ */
end_comment
begin_comment
comment|/* END */
end_comment
end_unit
