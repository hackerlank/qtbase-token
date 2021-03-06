begin_unit
begin_comment
comment|/***************************************************************************/
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  t42types.h                                                             */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*    Type 42 font data types (specification only).                        */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  Copyright 2002-2015 by                                                 */
end_comment
begin_comment
comment|/*  Roberto Alameda.                                                       */
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
name|__T42TYPES_H__
end_ifndef
begin_define
DECL|macro|__T42TYPES_H__
define|#
directive|define
name|__T42TYPES_H__
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
begin_include
include|#
directive|include
include|FT_INTERNAL_TYPE1_TYPES_H
end_include
begin_include
include|#
directive|include
include|FT_INTERNAL_POSTSCRIPT_HINTS_H
end_include
begin_macro
name|FT_BEGIN_HEADER
end_macro
begin_typedef
DECL|struct|T42_FaceRec_
typedef|typedef
struct|struct
name|T42_FaceRec_
block|{
DECL|member|root
name|FT_FaceRec
name|root
decl_stmt|;
DECL|member|type1
name|T1_FontRec
name|type1
decl_stmt|;
DECL|member|psnames
specifier|const
name|void
modifier|*
name|psnames
decl_stmt|;
DECL|member|psaux
specifier|const
name|void
modifier|*
name|psaux
decl_stmt|;
if|#
directive|if
literal|0
block|const void*     afm_data;
endif|#
directive|endif
DECL|member|ttf_data
name|FT_Byte
modifier|*
name|ttf_data
decl_stmt|;
DECL|member|ttf_size
name|FT_Long
name|ttf_size
decl_stmt|;
DECL|member|ttf_face
name|FT_Face
name|ttf_face
decl_stmt|;
DECL|member|charmaprecs
name|FT_CharMapRec
name|charmaprecs
index|[
literal|2
index|]
decl_stmt|;
DECL|member|charmaps
name|FT_CharMap
name|charmaps
index|[
literal|2
index|]
decl_stmt|;
DECL|member|unicode_map
name|PS_UnicodesRec
name|unicode_map
decl_stmt|;
block|}
DECL|typedef|T42_FaceRec
DECL|typedef|T42_Face
name|T42_FaceRec
operator|,
typedef|*
name|T42_Face
typedef|;
end_typedef
begin_macro
name|FT_END_HEADER
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* __T42TYPES_H__ */
end_comment
begin_comment
comment|/* END */
end_comment
end_unit
