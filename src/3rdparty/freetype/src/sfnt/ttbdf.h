begin_unit
begin_comment
comment|/***************************************************************************/
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  ttbdf.h                                                                */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*    TrueType and OpenType embedded BDF properties (specification).       */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  Copyright 2005-2015 by                                                 */
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
name|__TTBDF_H__
end_ifndef
begin_define
DECL|macro|__TTBDF_H__
define|#
directive|define
name|__TTBDF_H__
end_define
begin_include
include|#
directive|include
file|<ft2build.h>
end_include
begin_include
include|#
directive|include
file|"ttload.h"
end_include
begin_include
include|#
directive|include
include|FT_BDF_H
end_include
begin_function_decl
name|FT_BEGIN_HEADER
name|FT_LOCAL
parameter_list|(
name|void
parameter_list|)
function_decl|tt_face_free_bdf_props
DECL|variable|face
parameter_list|(
name|TT_Face
name|face
parameter_list|)
function_decl|;
end_function_decl
begin_macro
name|FT_LOCAL
argument_list|(
argument|FT_Error
argument_list|)
end_macro
begin_macro
name|tt_face_find_bdf_prop
argument_list|(
argument|TT_Face           face
argument_list|,
argument|const char*       property_name
argument_list|,
argument|BDF_PropertyRec  *aprop
argument_list|)
end_macro
begin_empty_stmt
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
comment|/* __TTBDF_H__ */
end_comment
begin_comment
comment|/* END */
end_comment
end_unit
