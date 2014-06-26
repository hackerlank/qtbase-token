begin_unit
begin_comment
comment|/*  * Copyright Â© 2014  Google, Inc.  *  *  This is part of HarfBuzz, a text shaping library.  *  * Permission is hereby granted, without written agreement and without  * license or royalty fees, to use, copy, modify, and distribute this  * software and its documentation for any purpose, provided that the  * above copyright notice and the following two paragraphs appear in  * all copies of this software.  *  * IN NO EVENT SHALL THE COPYRIGHT HOLDER BE LIABLE TO ANY PARTY FOR  * DIRECT, INDIRECT, SPECIAL, INCIDENTAL, OR CONSEQUENTIAL DAMAGES  * ARISING OUT OF THE USE OF THIS SOFTWARE AND ITS DOCUMENTATION, EVEN  * IF THE COPYRIGHT HOLDER HAS BEEN ADVISED OF THE POSSIBILITY OF SUCH  * DAMAGE.  *  * THE COPYRIGHT HOLDER SPECIFICALLY DISCLAIMS ANY WARRANTIES, INCLUDING,  * BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND  * FITNESS FOR A PARTICULAR PURPOSE.  THE SOFTWARE PROVIDED HEREUNDER IS  * ON AN "AS IS" BASIS, AND THE COPYRIGHT HOLDER HAS NO OBLIGATION TO  * PROVIDE MAINTENANCE, SUPPORT, UPDATES, ENHANCEMENTS, OR MODIFICATIONS.  *  * Google Author(s): Behdad Esfahbod, Roozbeh Pournader  */
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|HB_OT_FONT_H
end_ifndef
begin_define
DECL|macro|HB_OT_FONT_H
define|#
directive|define
name|HB_OT_FONT_H
end_define
begin_include
include|#
directive|include
file|"hb.h"
end_include
begin_function_decl
name|HB_BEGIN_DECLS
name|void
name|hb_ot_font_set_funcs
parameter_list|(
name|hb_font_t
modifier|*
name|font
parameter_list|)
function_decl|;
end_function_decl
begin_macro
name|HB_END_DECLS
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* HB_OT_FONT_H */
end_comment
end_unit