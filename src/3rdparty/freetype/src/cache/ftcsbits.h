begin_unit
begin_comment
comment|/***************************************************************************/
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  ftcsbits.h                                                             */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*    A small-bitmap cache (specification).                                */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  Copyright 2000-2001, 2002, 2003, 2006, 2011 by                         */
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
name|__FTCSBITS_H__
end_ifndef
begin_define
DECL|macro|__FTCSBITS_H__
define|#
directive|define
name|__FTCSBITS_H__
end_define
begin_include
include|#
directive|include
file|<ft2build.h>
end_include
begin_include
include|#
directive|include
include|FT_CACHE_H
end_include
begin_include
include|#
directive|include
file|"ftcglyph.h"
end_include
begin_macro
name|FT_BEGIN_HEADER
end_macro
begin_define
DECL|macro|FTC_SBIT_ITEMS_PER_NODE
define|#
directive|define
name|FTC_SBIT_ITEMS_PER_NODE
value|16
end_define
begin_typedef
DECL|struct|FTC_SNodeRec_
typedef|typedef
struct|struct
name|FTC_SNodeRec_
block|{
DECL|member|gnode
name|FTC_GNodeRec
name|gnode
decl_stmt|;
DECL|member|count
name|FT_UInt
name|count
decl_stmt|;
DECL|member|sbits
name|FTC_SBitRec
name|sbits
index|[
name|FTC_SBIT_ITEMS_PER_NODE
index|]
decl_stmt|;
block|}
DECL|typedef|FTC_SNodeRec
DECL|typedef|FTC_SNode
name|FTC_SNodeRec
operator|,
typedef|*
name|FTC_SNode
typedef|;
end_typedef
begin_define
DECL|macro|FTC_SNODE
define|#
directive|define
name|FTC_SNODE
parameter_list|(
name|x
parameter_list|)
value|( (FTC_SNode)( x ) )
end_define
begin_define
DECL|macro|FTC_SNODE_GINDEX
define|#
directive|define
name|FTC_SNODE_GINDEX
parameter_list|(
name|x
parameter_list|)
value|FTC_GNODE( x )->gindex
end_define
begin_define
DECL|macro|FTC_SNODE_FAMILY
define|#
directive|define
name|FTC_SNODE_FAMILY
parameter_list|(
name|x
parameter_list|)
value|FTC_GNODE( x )->family
end_define
begin_typedef
typedef|typedef
name|FT_UInt
function_decl|(
DECL|typedef|FTC_SFamily_GetCountFunc
modifier|*
name|FTC_SFamily_GetCountFunc
function_decl|)
parameter_list|(
name|FTC_Family
name|family
parameter_list|,
name|FTC_Manager
name|manager
parameter_list|)
function_decl|;
end_typedef
begin_typedef
typedef|typedef
name|FT_Error
function_decl|(
DECL|typedef|FTC_SFamily_LoadGlyphFunc
modifier|*
name|FTC_SFamily_LoadGlyphFunc
function_decl|)
parameter_list|(
name|FTC_Family
name|family
parameter_list|,
name|FT_UInt
name|gindex
parameter_list|,
name|FTC_Manager
name|manager
parameter_list|,
name|FT_Face
modifier|*
name|aface
parameter_list|)
function_decl|;
end_typedef
begin_typedef
DECL|struct|FTC_SFamilyClassRec_
typedef|typedef
struct|struct
name|FTC_SFamilyClassRec_
block|{
DECL|member|clazz
name|FTC_MruListClassRec
name|clazz
decl_stmt|;
DECL|member|family_get_count
name|FTC_SFamily_GetCountFunc
name|family_get_count
decl_stmt|;
DECL|member|family_load_glyph
name|FTC_SFamily_LoadGlyphFunc
name|family_load_glyph
decl_stmt|;
block|}
DECL|typedef|FTC_SFamilyClassRec
name|FTC_SFamilyClassRec
typedef|;
end_typedef
begin_typedef
DECL|typedef|FTC_SFamilyClass
typedef|typedef
specifier|const
name|FTC_SFamilyClassRec
modifier|*
name|FTC_SFamilyClass
typedef|;
end_typedef
begin_define
DECL|macro|FTC_SFAMILY_CLASS
define|#
directive|define
name|FTC_SFAMILY_CLASS
parameter_list|(
name|x
parameter_list|)
value|((FTC_SFamilyClass)(x))
end_define
begin_define
DECL|macro|FTC_CACHE__SFAMILY_CLASS
define|#
directive|define
name|FTC_CACHE__SFAMILY_CLASS
parameter_list|(
name|x
parameter_list|)
define|\
value|FTC_SFAMILY_CLASS( FTC_CACHE__GCACHE_CLASS( x )->family_class )
end_define
begin_macro
name|FT_LOCAL
argument_list|(
argument|void
argument_list|)
end_macro
begin_macro
name|FTC_SNode_Free
argument_list|(
argument|FTC_SNode  snode
argument_list|,
argument|FTC_Cache  cache
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
name|FTC_SNode_New
argument_list|(
argument|FTC_SNode   *psnode
argument_list|,
argument|FTC_GQuery   gquery
argument_list|,
argument|FTC_Cache    cache
argument_list|)
end_macro
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_if
if|#
directive|if
literal|0
end_if
begin_endif
unit|FT_LOCAL( FT_ULong )   FTC_SNode_Weight( FTC_SNode  inode );
endif|#
directive|endif
end_endif
begin_ifdef
ifdef|#
directive|ifdef
name|FTC_INLINE
end_ifdef
begin_macro
name|FT_LOCAL
argument_list|(
argument|FT_Bool
argument_list|)
end_macro
begin_macro
DECL|variable|FTC_SNode_Compare
name|FTC_SNode_Compare
argument_list|(
argument|FTC_SNode   snode
argument_list|,
argument|FTC_GQuery  gquery
argument_list|,
argument|FTC_Cache   cache
argument_list|,
argument|FT_Bool*    list_changed
argument_list|)
end_macro
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* */
end_comment
begin_macro
name|FT_END_HEADER
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* __FTCSBITS_H__ */
end_comment
begin_comment
comment|/* END */
end_comment
end_unit
