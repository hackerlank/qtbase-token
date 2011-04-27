begin_unit
begin_comment
comment|/***************************************************************************/
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  ftcmanag.c                                                             */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*    FreeType Cache Manager (body).                                       */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  Copyright 2000-2001, 2002, 2003, 2004, 2005, 2006, 2008, 2009 by       */
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
file|"ftcmanag.h"
end_include
begin_include
include|#
directive|include
include|FT_INTERNAL_OBJECTS_H
end_include
begin_include
include|#
directive|include
include|FT_INTERNAL_DEBUG_H
end_include
begin_include
include|#
directive|include
include|FT_SIZES_H
end_include
begin_include
include|#
directive|include
file|"ftccback.h"
end_include
begin_include
include|#
directive|include
file|"ftcerror.h"
end_include
begin_undef
DECL|macro|FT_COMPONENT
undef|#
directive|undef
name|FT_COMPONENT
end_undef
begin_define
DECL|macro|FT_COMPONENT
define|#
directive|define
name|FT_COMPONENT
value|trace_cache
end_define
begin_define
DECL|macro|FTC_LRU_GET_MANAGER
define|#
directive|define
name|FTC_LRU_GET_MANAGER
parameter_list|(
name|lru
parameter_list|)
value|( (FTC_Manager)(lru)->user_data )
end_define
begin_function
specifier|static
name|FT_Error
DECL|function|ftc_scaler_lookup_size
name|ftc_scaler_lookup_size
parameter_list|(
name|FTC_Manager
name|manager
parameter_list|,
name|FTC_Scaler
name|scaler
parameter_list|,
name|FT_Size
modifier|*
name|asize
parameter_list|)
block|{
name|FT_Face
name|face
decl_stmt|;
name|FT_Size
name|size
init|=
name|NULL
decl_stmt|;
name|FT_Error
name|error
decl_stmt|;
name|error
operator|=
name|FTC_Manager_LookupFace
argument_list|(
name|manager
argument_list|,
name|scaler
operator|->
name|face_id
argument_list|,
operator|&
name|face
argument_list|)
expr_stmt|;
if|if
condition|(
name|error
condition|)
goto|goto
name|Exit
goto|;
name|error
operator|=
name|FT_New_Size
argument_list|(
name|face
argument_list|,
operator|&
name|size
argument_list|)
expr_stmt|;
if|if
condition|(
name|error
condition|)
goto|goto
name|Exit
goto|;
name|FT_Activate_Size
argument_list|(
name|size
argument_list|)
expr_stmt|;
if|if
condition|(
name|scaler
operator|->
name|pixel
condition|)
name|error
operator|=
name|FT_Set_Pixel_Sizes
argument_list|(
name|face
argument_list|,
name|scaler
operator|->
name|width
argument_list|,
name|scaler
operator|->
name|height
argument_list|)
expr_stmt|;
else|else
name|error
operator|=
name|FT_Set_Char_Size
argument_list|(
name|face
argument_list|,
name|scaler
operator|->
name|width
argument_list|,
name|scaler
operator|->
name|height
argument_list|,
name|scaler
operator|->
name|x_res
argument_list|,
name|scaler
operator|->
name|y_res
argument_list|)
expr_stmt|;
if|if
condition|(
name|error
condition|)
block|{
name|FT_Done_Size
argument_list|(
name|size
argument_list|)
expr_stmt|;
name|size
operator|=
name|NULL
expr_stmt|;
block|}
name|Exit
label|:
operator|*
name|asize
operator|=
name|size
expr_stmt|;
return|return
name|error
return|;
block|}
end_function
begin_typedef
DECL|struct|FTC_SizeNodeRec_
typedef|typedef
struct|struct
name|FTC_SizeNodeRec_
block|{
DECL|member|node
name|FTC_MruNodeRec
name|node
decl_stmt|;
DECL|member|size
name|FT_Size
name|size
decl_stmt|;
DECL|member|scaler
name|FTC_ScalerRec
name|scaler
decl_stmt|;
block|}
DECL|typedef|FTC_SizeNodeRec
DECL|typedef|FTC_SizeNode
name|FTC_SizeNodeRec
operator|,
typedef|*
name|FTC_SizeNode
typedef|;
end_typedef
begin_macro
name|FT_CALLBACK_DEF
argument_list|(
argument|void
argument_list|)
end_macro
begin_macro
DECL|function|ftc_size_node_done
name|ftc_size_node_done
argument_list|(
argument|FTC_MruNode  ftcnode
argument_list|,
argument|FT_Pointer   data
argument_list|)
end_macro
begin_block
block|{
name|FTC_SizeNode
name|node
init|=
operator|(
name|FTC_SizeNode
operator|)
name|ftcnode
decl_stmt|;
name|FT_Size
name|size
init|=
name|node
operator|->
name|size
decl_stmt|;
name|FT_UNUSED
argument_list|(
name|data
argument_list|)
expr_stmt|;
if|if
condition|(
name|size
condition|)
name|FT_Done_Size
argument_list|(
name|size
argument_list|)
expr_stmt|;
block|}
end_block
begin_macro
DECL|function|FT_CALLBACK_DEF
name|FT_CALLBACK_DEF
argument_list|(
argument|FT_Bool
argument_list|)
end_macro
begin_macro
name|ftc_size_node_compare
argument_list|(
argument|FTC_MruNode  ftcnode
argument_list|,
argument|FT_Pointer   ftcscaler
argument_list|)
end_macro
begin_block
block|{
name|FTC_SizeNode
name|node
init|=
operator|(
name|FTC_SizeNode
operator|)
name|ftcnode
decl_stmt|;
name|FTC_Scaler
name|scaler
init|=
operator|(
name|FTC_Scaler
operator|)
name|ftcscaler
decl_stmt|;
name|FTC_Scaler
name|scaler0
init|=
operator|&
name|node
operator|->
name|scaler
decl_stmt|;
if|if
condition|(
name|FTC_SCALER_COMPARE
argument_list|(
name|scaler0
argument_list|,
name|scaler
argument_list|)
condition|)
block|{
name|FT_Activate_Size
argument_list|(
name|node
operator|->
name|size
argument_list|)
expr_stmt|;
return|return
literal|1
return|;
block|}
return|return
literal|0
return|;
block|}
end_block
begin_macro
DECL|function|FT_CALLBACK_DEF
name|FT_CALLBACK_DEF
argument_list|(
argument|FT_Error
argument_list|)
end_macro
begin_macro
name|ftc_size_node_init
argument_list|(
argument|FTC_MruNode  ftcnode
argument_list|,
argument|FT_Pointer   ftcscaler
argument_list|,
argument|FT_Pointer   ftcmanager
argument_list|)
end_macro
begin_block
block|{
name|FTC_SizeNode
name|node
init|=
operator|(
name|FTC_SizeNode
operator|)
name|ftcnode
decl_stmt|;
name|FTC_Scaler
name|scaler
init|=
operator|(
name|FTC_Scaler
operator|)
name|ftcscaler
decl_stmt|;
name|FTC_Manager
name|manager
init|=
operator|(
name|FTC_Manager
operator|)
name|ftcmanager
decl_stmt|;
name|node
operator|->
name|scaler
operator|=
name|scaler
index|[
literal|0
index|]
expr_stmt|;
return|return
name|ftc_scaler_lookup_size
argument_list|(
name|manager
argument_list|,
name|scaler
argument_list|,
operator|&
name|node
operator|->
name|size
argument_list|)
return|;
block|}
end_block
begin_macro
DECL|function|FT_CALLBACK_DEF
name|FT_CALLBACK_DEF
argument_list|(
argument|FT_Error
argument_list|)
end_macro
begin_macro
name|ftc_size_node_reset
argument_list|(
argument|FTC_MruNode  ftcnode
argument_list|,
argument|FT_Pointer   ftcscaler
argument_list|,
argument|FT_Pointer   ftcmanager
argument_list|)
end_macro
begin_block
block|{
name|FTC_SizeNode
name|node
init|=
operator|(
name|FTC_SizeNode
operator|)
name|ftcnode
decl_stmt|;
name|FTC_Scaler
name|scaler
init|=
operator|(
name|FTC_Scaler
operator|)
name|ftcscaler
decl_stmt|;
name|FTC_Manager
name|manager
init|=
operator|(
name|FTC_Manager
operator|)
name|ftcmanager
decl_stmt|;
name|FT_Done_Size
argument_list|(
name|node
operator|->
name|size
argument_list|)
expr_stmt|;
name|node
operator|->
name|scaler
operator|=
name|scaler
index|[
literal|0
index|]
expr_stmt|;
return|return
name|ftc_scaler_lookup_size
argument_list|(
name|manager
argument_list|,
name|scaler
argument_list|,
operator|&
name|node
operator|->
name|size
argument_list|)
return|;
block|}
end_block
begin_decl_stmt
name|FT_CALLBACK_TABLE_DEF
DECL|variable|ftc_size_list_class
specifier|const
name|FTC_MruListClassRec
name|ftc_size_list_class
init|=
block|{
sizeof|sizeof
argument_list|(
name|FTC_SizeNodeRec
argument_list|)
block|,
name|ftc_size_node_compare
block|,
name|ftc_size_node_init
block|,
name|ftc_size_node_reset
block|,
name|ftc_size_node_done
block|}
decl_stmt|;
end_decl_stmt
begin_comment
comment|/* helper function used by ftc_face_node_done */
end_comment
begin_function
specifier|static
name|FT_Bool
DECL|function|ftc_size_node_compare_faceid
name|ftc_size_node_compare_faceid
parameter_list|(
name|FTC_MruNode
name|ftcnode
parameter_list|,
name|FT_Pointer
name|ftcface_id
parameter_list|)
block|{
name|FTC_SizeNode
name|node
init|=
operator|(
name|FTC_SizeNode
operator|)
name|ftcnode
decl_stmt|;
name|FTC_FaceID
name|face_id
init|=
operator|(
name|FTC_FaceID
operator|)
name|ftcface_id
decl_stmt|;
return|return
name|FT_BOOL
argument_list|(
name|node
operator|->
name|scaler
operator|.
name|face_id
operator|==
name|face_id
argument_list|)
return|;
block|}
end_function
begin_comment
comment|/* documentation is in ftcache.h */
end_comment
begin_macro
DECL|function|FT_EXPORT_DEF
name|FT_EXPORT_DEF
argument_list|(
argument|FT_Error
argument_list|)
end_macro
begin_macro
name|FTC_Manager_LookupSize
argument_list|(
argument|FTC_Manager  manager
argument_list|,
argument|FTC_Scaler   scaler
argument_list|,
argument|FT_Size     *asize
argument_list|)
end_macro
begin_block
block|{
name|FT_Error
name|error
decl_stmt|;
name|FTC_SizeNode
name|node
decl_stmt|;
if|if
condition|(
name|asize
operator|==
name|NULL
condition|)
return|return
name|FTC_Err_Invalid_Argument
return|;
operator|*
name|asize
operator|=
name|NULL
expr_stmt|;
if|if
condition|(
operator|!
name|manager
condition|)
return|return
name|FTC_Err_Invalid_Cache_Handle
return|;
ifdef|#
directive|ifdef
name|FTC_INLINE
name|FTC_MRULIST_LOOKUP_CMP
argument_list|(
operator|&
name|manager
operator|->
name|sizes
argument_list|,
name|scaler
argument_list|,
name|ftc_size_node_compare
argument_list|,
name|node
argument_list|,
name|error
argument_list|)
expr_stmt|;
else|#
directive|else
name|error
operator|=
name|FTC_MruList_Lookup
argument_list|(
operator|&
name|manager
operator|->
name|sizes
argument_list|,
name|scaler
argument_list|,
operator|(
name|FTC_MruNode
operator|*
operator|)
operator|&
name|node
argument_list|)
expr_stmt|;
endif|#
directive|endif
if|if
condition|(
operator|!
name|error
condition|)
operator|*
name|asize
operator|=
name|node
operator|->
name|size
expr_stmt|;
return|return
name|error
return|;
block|}
end_block
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
comment|/*****                    FACE MRU IMPLEMENTATION                    *****/
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
DECL|struct|FTC_FaceNodeRec_
typedef|typedef
struct|struct
name|FTC_FaceNodeRec_
block|{
DECL|member|node
name|FTC_MruNodeRec
name|node
decl_stmt|;
DECL|member|face_id
name|FTC_FaceID
name|face_id
decl_stmt|;
DECL|member|face
name|FT_Face
name|face
decl_stmt|;
block|}
DECL|typedef|FTC_FaceNodeRec
DECL|typedef|FTC_FaceNode
name|FTC_FaceNodeRec
operator|,
typedef|*
name|FTC_FaceNode
typedef|;
end_typedef
begin_macro
DECL|function|FT_CALLBACK_DEF
name|FT_CALLBACK_DEF
argument_list|(
argument|FT_Error
argument_list|)
end_macro
begin_macro
name|ftc_face_node_init
argument_list|(
argument|FTC_MruNode  ftcnode
argument_list|,
argument|FT_Pointer   ftcface_id
argument_list|,
argument|FT_Pointer   ftcmanager
argument_list|)
end_macro
begin_block
block|{
name|FTC_FaceNode
name|node
init|=
operator|(
name|FTC_FaceNode
operator|)
name|ftcnode
decl_stmt|;
name|FTC_FaceID
name|face_id
init|=
operator|(
name|FTC_FaceID
operator|)
name|ftcface_id
decl_stmt|;
name|FTC_Manager
name|manager
init|=
operator|(
name|FTC_Manager
operator|)
name|ftcmanager
decl_stmt|;
name|FT_Error
name|error
decl_stmt|;
name|node
operator|->
name|face_id
operator|=
name|face_id
expr_stmt|;
name|error
operator|=
name|manager
operator|->
name|request_face
argument_list|(
name|face_id
argument_list|,
name|manager
operator|->
name|library
argument_list|,
name|manager
operator|->
name|request_data
argument_list|,
operator|&
name|node
operator|->
name|face
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|error
condition|)
block|{
comment|/* destroy initial size object; it will be re-created later */
if|if
condition|(
name|node
operator|->
name|face
operator|->
name|size
condition|)
name|FT_Done_Size
argument_list|(
name|node
operator|->
name|face
operator|->
name|size
argument_list|)
expr_stmt|;
block|}
return|return
name|error
return|;
block|}
end_block
begin_macro
name|FT_CALLBACK_DEF
argument_list|(
argument|void
argument_list|)
end_macro
begin_macro
DECL|function|ftc_face_node_done
name|ftc_face_node_done
argument_list|(
argument|FTC_MruNode  ftcnode
argument_list|,
argument|FT_Pointer   ftcmanager
argument_list|)
end_macro
begin_block
block|{
name|FTC_FaceNode
name|node
init|=
operator|(
name|FTC_FaceNode
operator|)
name|ftcnode
decl_stmt|;
name|FTC_Manager
name|manager
init|=
operator|(
name|FTC_Manager
operator|)
name|ftcmanager
decl_stmt|;
comment|/* we must begin by removing all scalers for the target face */
comment|/* from the manager's list                                   */
name|FTC_MruList_RemoveSelection
argument_list|(
operator|&
name|manager
operator|->
name|sizes
argument_list|,
name|ftc_size_node_compare_faceid
argument_list|,
name|node
operator|->
name|face_id
argument_list|)
expr_stmt|;
comment|/* all right, we can discard the face now */
name|FT_Done_Face
argument_list|(
name|node
operator|->
name|face
argument_list|)
expr_stmt|;
name|node
operator|->
name|face
operator|=
name|NULL
expr_stmt|;
name|node
operator|->
name|face_id
operator|=
name|NULL
expr_stmt|;
block|}
end_block
begin_macro
DECL|function|FT_CALLBACK_DEF
name|FT_CALLBACK_DEF
argument_list|(
argument|FT_Bool
argument_list|)
end_macro
begin_macro
name|ftc_face_node_compare
argument_list|(
argument|FTC_MruNode  ftcnode
argument_list|,
argument|FT_Pointer   ftcface_id
argument_list|)
end_macro
begin_block
block|{
name|FTC_FaceNode
name|node
init|=
operator|(
name|FTC_FaceNode
operator|)
name|ftcnode
decl_stmt|;
name|FTC_FaceID
name|face_id
init|=
operator|(
name|FTC_FaceID
operator|)
name|ftcface_id
decl_stmt|;
return|return
name|FT_BOOL
argument_list|(
name|node
operator|->
name|face_id
operator|==
name|face_id
argument_list|)
return|;
block|}
end_block
begin_decl_stmt
name|FT_CALLBACK_TABLE_DEF
DECL|variable|ftc_face_list_class
specifier|const
name|FTC_MruListClassRec
name|ftc_face_list_class
init|=
block|{
sizeof|sizeof
argument_list|(
name|FTC_FaceNodeRec
argument_list|)
block|,
name|ftc_face_node_compare
block|,
name|ftc_face_node_init
block|,
literal|0
block|,
comment|/* FTC_MruNode_ResetFunc */
name|ftc_face_node_done
block|}
decl_stmt|;
end_decl_stmt
begin_comment
comment|/* documentation is in ftcache.h */
end_comment
begin_macro
DECL|function|FT_EXPORT_DEF
name|FT_EXPORT_DEF
argument_list|(
argument|FT_Error
argument_list|)
end_macro
begin_macro
name|FTC_Manager_LookupFace
argument_list|(
argument|FTC_Manager  manager
argument_list|,
argument|FTC_FaceID   face_id
argument_list|,
argument|FT_Face     *aface
argument_list|)
end_macro
begin_block
block|{
name|FT_Error
name|error
decl_stmt|;
name|FTC_FaceNode
name|node
decl_stmt|;
if|if
condition|(
name|aface
operator|==
name|NULL
condition|)
return|return
name|FTC_Err_Invalid_Argument
return|;
operator|*
name|aface
operator|=
name|NULL
expr_stmt|;
if|if
condition|(
operator|!
name|manager
condition|)
return|return
name|FTC_Err_Invalid_Cache_Handle
return|;
comment|/* we break encapsulation for the sake of speed */
ifdef|#
directive|ifdef
name|FTC_INLINE
name|FTC_MRULIST_LOOKUP_CMP
argument_list|(
operator|&
name|manager
operator|->
name|faces
argument_list|,
name|face_id
argument_list|,
name|ftc_face_node_compare
argument_list|,
name|node
argument_list|,
name|error
argument_list|)
expr_stmt|;
else|#
directive|else
name|error
operator|=
name|FTC_MruList_Lookup
argument_list|(
operator|&
name|manager
operator|->
name|faces
argument_list|,
name|face_id
argument_list|,
operator|(
name|FTC_MruNode
operator|*
operator|)
operator|&
name|node
argument_list|)
expr_stmt|;
endif|#
directive|endif
if|if
condition|(
operator|!
name|error
condition|)
operator|*
name|aface
operator|=
name|node
operator|->
name|face
expr_stmt|;
return|return
name|error
return|;
block|}
end_block
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
comment|/*****                    CACHE MANAGER ROUTINES                     *****/
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
comment|/* documentation is in ftcache.h */
end_comment
begin_macro
DECL|function|FT_EXPORT_DEF
name|FT_EXPORT_DEF
argument_list|(
argument|FT_Error
argument_list|)
end_macro
begin_macro
name|FTC_Manager_New
argument_list|(
argument|FT_Library          library
argument_list|,
argument|FT_UInt             max_faces
argument_list|,
argument|FT_UInt             max_sizes
argument_list|,
argument|FT_ULong            max_bytes
argument_list|,
argument|FTC_Face_Requester  requester
argument_list|,
argument|FT_Pointer          req_data
argument_list|,
argument|FTC_Manager        *amanager
argument_list|)
end_macro
begin_block
block|{
name|FT_Error
name|error
decl_stmt|;
name|FT_Memory
name|memory
decl_stmt|;
name|FTC_Manager
name|manager
init|=
literal|0
decl_stmt|;
if|if
condition|(
operator|!
name|library
condition|)
return|return
name|FTC_Err_Invalid_Library_Handle
return|;
name|memory
operator|=
name|library
operator|->
name|memory
expr_stmt|;
if|if
condition|(
name|FT_NEW
argument_list|(
name|manager
argument_list|)
condition|)
goto|goto
name|Exit
goto|;
if|if
condition|(
name|max_faces
operator|==
literal|0
condition|)
name|max_faces
operator|=
name|FTC_MAX_FACES_DEFAULT
expr_stmt|;
if|if
condition|(
name|max_sizes
operator|==
literal|0
condition|)
name|max_sizes
operator|=
name|FTC_MAX_SIZES_DEFAULT
expr_stmt|;
if|if
condition|(
name|max_bytes
operator|==
literal|0
condition|)
name|max_bytes
operator|=
name|FTC_MAX_BYTES_DEFAULT
expr_stmt|;
name|manager
operator|->
name|library
operator|=
name|library
expr_stmt|;
name|manager
operator|->
name|memory
operator|=
name|memory
expr_stmt|;
name|manager
operator|->
name|max_weight
operator|=
name|max_bytes
expr_stmt|;
name|manager
operator|->
name|request_face
operator|=
name|requester
expr_stmt|;
name|manager
operator|->
name|request_data
operator|=
name|req_data
expr_stmt|;
name|FTC_MruList_Init
argument_list|(
operator|&
name|manager
operator|->
name|faces
argument_list|,
operator|&
name|ftc_face_list_class
argument_list|,
name|max_faces
argument_list|,
name|manager
argument_list|,
name|memory
argument_list|)
expr_stmt|;
name|FTC_MruList_Init
argument_list|(
operator|&
name|manager
operator|->
name|sizes
argument_list|,
operator|&
name|ftc_size_list_class
argument_list|,
name|max_sizes
argument_list|,
name|manager
argument_list|,
name|memory
argument_list|)
expr_stmt|;
operator|*
name|amanager
operator|=
name|manager
expr_stmt|;
name|Exit
label|:
return|return
name|error
return|;
block|}
end_block
begin_comment
comment|/* documentation is in ftcache.h */
end_comment
begin_macro
name|FT_EXPORT_DEF
argument_list|(
argument|void
argument_list|)
end_macro
begin_macro
DECL|function|FTC_Manager_Done
name|FTC_Manager_Done
argument_list|(
argument|FTC_Manager  manager
argument_list|)
end_macro
begin_block
block|{
name|FT_Memory
name|memory
decl_stmt|;
name|FT_UInt
name|idx
decl_stmt|;
if|if
condition|(
operator|!
name|manager
operator|||
operator|!
name|manager
operator|->
name|library
condition|)
return|return;
name|memory
operator|=
name|manager
operator|->
name|memory
expr_stmt|;
comment|/* now discard all caches */
for|for
control|(
name|idx
operator|=
name|manager
operator|->
name|num_caches
init|;
name|idx
operator|--
operator|>
literal|0
condition|;
control|)
block|{
name|FTC_Cache
name|cache
init|=
name|manager
operator|->
name|caches
index|[
name|idx
index|]
decl_stmt|;
if|if
condition|(
name|cache
condition|)
block|{
name|cache
operator|->
name|clazz
operator|.
name|cache_done
argument_list|(
name|cache
argument_list|)
expr_stmt|;
name|FT_FREE
argument_list|(
name|cache
argument_list|)
expr_stmt|;
name|manager
operator|->
name|caches
index|[
name|idx
index|]
operator|=
name|NULL
expr_stmt|;
block|}
block|}
name|manager
operator|->
name|num_caches
operator|=
literal|0
expr_stmt|;
comment|/* discard faces and sizes */
name|FTC_MruList_Done
argument_list|(
operator|&
name|manager
operator|->
name|sizes
argument_list|)
expr_stmt|;
name|FTC_MruList_Done
argument_list|(
operator|&
name|manager
operator|->
name|faces
argument_list|)
expr_stmt|;
name|manager
operator|->
name|library
operator|=
name|NULL
expr_stmt|;
name|manager
operator|->
name|memory
operator|=
name|NULL
expr_stmt|;
name|FT_FREE
argument_list|(
name|manager
argument_list|)
expr_stmt|;
block|}
end_block
begin_comment
comment|/* documentation is in ftcache.h */
end_comment
begin_macro
name|FT_EXPORT_DEF
argument_list|(
argument|void
argument_list|)
end_macro
begin_macro
DECL|function|FTC_Manager_Reset
name|FTC_Manager_Reset
argument_list|(
argument|FTC_Manager  manager
argument_list|)
end_macro
begin_block
block|{
if|if
condition|(
name|manager
condition|)
block|{
name|FTC_MruList_Reset
argument_list|(
operator|&
name|manager
operator|->
name|sizes
argument_list|)
expr_stmt|;
name|FTC_MruList_Reset
argument_list|(
operator|&
name|manager
operator|->
name|faces
argument_list|)
expr_stmt|;
block|}
comment|/* XXX: FIXME: flush the caches? */
block|}
end_block
begin_ifdef
ifdef|#
directive|ifdef
name|FT_DEBUG_ERROR
end_ifdef
begin_function
specifier|static
name|void
DECL|function|FTC_Manager_Check
name|FTC_Manager_Check
parameter_list|(
name|FTC_Manager
name|manager
parameter_list|)
block|{
name|FTC_Node
name|node
decl_stmt|,
name|first
decl_stmt|;
name|first
operator|=
name|manager
operator|->
name|nodes_list
expr_stmt|;
comment|/* check node weights */
if|if
condition|(
name|first
condition|)
block|{
name|FT_ULong
name|weight
init|=
literal|0
decl_stmt|;
name|node
operator|=
name|first
expr_stmt|;
do|do
block|{
name|FTC_Cache
name|cache
init|=
name|manager
operator|->
name|caches
index|[
name|node
operator|->
name|cache_index
index|]
decl_stmt|;
if|if
condition|(
operator|(
name|FT_UInt
operator|)
name|node
operator|->
name|cache_index
operator|>=
name|manager
operator|->
name|num_caches
condition|)
name|FT_ERROR
argument_list|(
operator|(
literal|"FTC_Manager_Check: invalid node (cache index = %ld\n"
operator|,
name|node
operator|->
name|cache_index
operator|)
argument_list|)
expr_stmt|;
else|else
name|weight
operator|+=
name|cache
operator|->
name|clazz
operator|.
name|node_weight
argument_list|(
name|node
argument_list|,
name|cache
argument_list|)
expr_stmt|;
name|node
operator|=
name|FTC_NODE__NEXT
argument_list|(
name|node
argument_list|)
expr_stmt|;
block|}
do|while
condition|(
name|node
operator|!=
name|first
condition|)
do|;
if|if
condition|(
name|weight
operator|!=
name|manager
operator|->
name|cur_weight
condition|)
name|FT_ERROR
argument_list|(
operator|(
literal|"FTC_Manager_Check: invalid weight %ld instead of %ld\n"
operator|,
name|manager
operator|->
name|cur_weight
operator|,
name|weight
operator|)
argument_list|)
expr_stmt|;
block|}
comment|/* check circular list */
if|if
condition|(
name|first
condition|)
block|{
name|FT_UFast
name|count
init|=
literal|0
decl_stmt|;
name|node
operator|=
name|first
expr_stmt|;
do|do
block|{
name|count
operator|++
expr_stmt|;
name|node
operator|=
name|FTC_NODE__NEXT
argument_list|(
name|node
argument_list|)
expr_stmt|;
block|}
do|while
condition|(
name|node
operator|!=
name|first
condition|)
do|;
if|if
condition|(
name|count
operator|!=
name|manager
operator|->
name|num_nodes
condition|)
name|FT_ERROR
argument_list|(
operator|(
literal|"FTC_Manager_Check: invalid cache node count %d instead of %d\n"
operator|,
name|manager
operator|->
name|num_nodes
operator|,
name|count
operator|)
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* FT_DEBUG_ERROR */
end_comment
begin_comment
comment|/* `Compress' the manager's data, i.e., get rid of old cache nodes */
end_comment
begin_comment
comment|/* that are not referenced anymore in order to limit the total     */
end_comment
begin_comment
comment|/* memory used by the cache.                                       */
end_comment
begin_comment
comment|/* documentation is in ftcmanag.h */
end_comment
begin_macro
name|FT_LOCAL_DEF
argument_list|(
argument|void
argument_list|)
end_macro
begin_macro
DECL|function|FTC_Manager_Compress
name|FTC_Manager_Compress
argument_list|(
argument|FTC_Manager  manager
argument_list|)
end_macro
begin_block
block|{
name|FTC_Node
name|node
decl_stmt|,
name|first
decl_stmt|;
if|if
condition|(
operator|!
name|manager
condition|)
return|return;
name|first
operator|=
name|manager
operator|->
name|nodes_list
expr_stmt|;
ifdef|#
directive|ifdef
name|FT_DEBUG_ERROR
name|FTC_Manager_Check
argument_list|(
name|manager
argument_list|)
expr_stmt|;
name|FT_ERROR
argument_list|(
operator|(
literal|"compressing, weight = %ld, max = %ld, nodes = %d\n"
operator|,
name|manager
operator|->
name|cur_weight
operator|,
name|manager
operator|->
name|max_weight
operator|,
name|manager
operator|->
name|num_nodes
operator|)
argument_list|)
expr_stmt|;
endif|#
directive|endif
if|if
condition|(
name|manager
operator|->
name|cur_weight
operator|<
name|manager
operator|->
name|max_weight
operator|||
name|first
operator|==
name|NULL
condition|)
return|return;
comment|/* go to last node -- it's a circular list */
name|node
operator|=
name|FTC_NODE__PREV
argument_list|(
name|first
argument_list|)
expr_stmt|;
do|do
block|{
name|FTC_Node
name|prev
decl_stmt|;
name|prev
operator|=
operator|(
name|node
operator|==
name|first
operator|)
condition|?
name|NULL
else|:
name|FTC_NODE__PREV
argument_list|(
name|node
argument_list|)
expr_stmt|;
if|if
condition|(
name|node
operator|->
name|ref_count
operator|<=
literal|0
condition|)
name|ftc_node_destroy
argument_list|(
name|node
argument_list|,
name|manager
argument_list|)
expr_stmt|;
name|node
operator|=
name|prev
expr_stmt|;
block|}
do|while
condition|(
name|node
operator|&&
name|manager
operator|->
name|cur_weight
operator|>
name|manager
operator|->
name|max_weight
condition|)
do|;
block|}
end_block
begin_comment
comment|/* documentation is in ftcmanag.h */
end_comment
begin_macro
DECL|function|FT_LOCAL_DEF
name|FT_LOCAL_DEF
argument_list|(
argument|FT_Error
argument_list|)
end_macro
begin_macro
name|FTC_Manager_RegisterCache
argument_list|(
argument|FTC_Manager      manager
argument_list|,
argument|FTC_CacheClass   clazz
argument_list|,
argument|FTC_Cache       *acache
argument_list|)
end_macro
begin_block
block|{
name|FT_Error
name|error
init|=
name|FTC_Err_Invalid_Argument
decl_stmt|;
name|FTC_Cache
name|cache
init|=
name|NULL
decl_stmt|;
if|if
condition|(
name|manager
operator|&&
name|clazz
operator|&&
name|acache
condition|)
block|{
name|FT_Memory
name|memory
init|=
name|manager
operator|->
name|memory
decl_stmt|;
if|if
condition|(
name|manager
operator|->
name|num_caches
operator|>=
name|FTC_MAX_CACHES
condition|)
block|{
name|error
operator|=
name|FTC_Err_Too_Many_Caches
expr_stmt|;
name|FT_ERROR
argument_list|(
operator|(
literal|"%s: too many registered caches\n"
operator|,
literal|"FTC_Manager_Register_Cache"
operator|)
argument_list|)
expr_stmt|;
goto|goto
name|Exit
goto|;
block|}
if|if
condition|(
operator|!
name|FT_ALLOC
argument_list|(
name|cache
argument_list|,
name|clazz
operator|->
name|cache_size
argument_list|)
condition|)
block|{
name|cache
operator|->
name|manager
operator|=
name|manager
expr_stmt|;
name|cache
operator|->
name|memory
operator|=
name|memory
expr_stmt|;
name|cache
operator|->
name|clazz
operator|=
name|clazz
index|[
literal|0
index|]
expr_stmt|;
name|cache
operator|->
name|org_class
operator|=
name|clazz
expr_stmt|;
comment|/* THIS IS VERY IMPORTANT!  IT WILL WRETCH THE MANAGER */
comment|/* IF IT IS NOT SET CORRECTLY                          */
name|cache
operator|->
name|index
operator|=
name|manager
operator|->
name|num_caches
expr_stmt|;
name|error
operator|=
name|clazz
operator|->
name|cache_init
argument_list|(
name|cache
argument_list|)
expr_stmt|;
if|if
condition|(
name|error
condition|)
block|{
name|clazz
operator|->
name|cache_done
argument_list|(
name|cache
argument_list|)
expr_stmt|;
name|FT_FREE
argument_list|(
name|cache
argument_list|)
expr_stmt|;
goto|goto
name|Exit
goto|;
block|}
name|manager
operator|->
name|caches
index|[
name|manager
operator|->
name|num_caches
operator|++
index|]
operator|=
name|cache
expr_stmt|;
block|}
block|}
name|Exit
label|:
if|if
condition|(
name|acache
condition|)
operator|*
name|acache
operator|=
name|cache
expr_stmt|;
return|return
name|error
return|;
block|}
end_block
begin_macro
DECL|function|FT_LOCAL_DEF
name|FT_LOCAL_DEF
argument_list|(
argument|FT_UInt
argument_list|)
end_macro
begin_macro
name|FTC_Manager_FlushN
argument_list|(
argument|FTC_Manager  manager
argument_list|,
argument|FT_UInt      count
argument_list|)
end_macro
begin_block
block|{
name|FTC_Node
name|first
init|=
name|manager
operator|->
name|nodes_list
decl_stmt|;
name|FTC_Node
name|node
decl_stmt|;
name|FT_UInt
name|result
decl_stmt|;
comment|/* try to remove `count' nodes from the list */
if|if
condition|(
name|first
operator|==
name|NULL
condition|)
comment|/* empty list! */
return|return
literal|0
return|;
comment|/* go to last node - it's a circular list */
name|node
operator|=
name|FTC_NODE__PREV
argument_list|(
name|first
argument_list|)
expr_stmt|;
for|for
control|(
name|result
operator|=
literal|0
init|;
name|result
operator|<
name|count
condition|;
control|)
block|{
name|FTC_Node
name|prev
init|=
name|FTC_NODE__PREV
argument_list|(
name|node
argument_list|)
decl_stmt|;
comment|/* don't touch locked nodes */
if|if
condition|(
name|node
operator|->
name|ref_count
operator|<=
literal|0
condition|)
block|{
name|ftc_node_destroy
argument_list|(
name|node
argument_list|,
name|manager
argument_list|)
expr_stmt|;
name|result
operator|++
expr_stmt|;
block|}
if|if
condition|(
name|node
operator|==
name|first
condition|)
break|break;
name|node
operator|=
name|prev
expr_stmt|;
block|}
return|return
name|result
return|;
block|}
end_block
begin_comment
comment|/* documentation is in ftcache.h */
end_comment
begin_macro
name|FT_EXPORT_DEF
argument_list|(
argument|void
argument_list|)
end_macro
begin_macro
DECL|function|FTC_Manager_RemoveFaceID
name|FTC_Manager_RemoveFaceID
argument_list|(
argument|FTC_Manager  manager
argument_list|,
argument|FTC_FaceID   face_id
argument_list|)
end_macro
begin_block
block|{
name|FT_UInt
name|nn
decl_stmt|;
comment|/* this will remove all FTC_SizeNode that correspond to      * the face_id as well      */
name|FTC_MruList_RemoveSelection
argument_list|(
operator|&
name|manager
operator|->
name|faces
argument_list|,
name|NULL
argument_list|,
name|face_id
argument_list|)
expr_stmt|;
for|for
control|(
name|nn
operator|=
literal|0
init|;
name|nn
operator|<
name|manager
operator|->
name|num_caches
condition|;
name|nn
operator|++
control|)
name|FTC_Cache_RemoveFaceID
argument_list|(
name|manager
operator|->
name|caches
index|[
name|nn
index|]
argument_list|,
name|face_id
argument_list|)
expr_stmt|;
block|}
end_block
begin_comment
comment|/* documentation is in ftcache.h */
end_comment
begin_macro
name|FT_EXPORT_DEF
argument_list|(
argument|void
argument_list|)
end_macro
begin_macro
DECL|function|FTC_Node_Unref
name|FTC_Node_Unref
argument_list|(
argument|FTC_Node     node
argument_list|,
argument|FTC_Manager  manager
argument_list|)
end_macro
begin_block
block|{
if|if
condition|(
name|node
operator|&&
operator|(
name|FT_UInt
operator|)
name|node
operator|->
name|cache_index
operator|<
name|manager
operator|->
name|num_caches
condition|)
name|node
operator|->
name|ref_count
operator|--
expr_stmt|;
block|}
end_block
begin_ifdef
ifdef|#
directive|ifdef
name|FT_CONFIG_OPTION_OLD_INTERNALS
end_ifdef
begin_macro
DECL|function|FT_EXPORT_DEF
name|FT_EXPORT_DEF
argument_list|(
argument|FT_Error
argument_list|)
end_macro
begin_macro
name|FTC_Manager_Lookup_Face
argument_list|(
argument|FTC_Manager  manager
argument_list|,
argument|FTC_FaceID   face_id
argument_list|,
argument|FT_Face     *aface
argument_list|)
end_macro
begin_block
block|{
return|return
name|FTC_Manager_LookupFace
argument_list|(
name|manager
argument_list|,
name|face_id
argument_list|,
name|aface
argument_list|)
return|;
block|}
end_block
begin_macro
DECL|function|FT_EXPORT
name|FT_EXPORT
argument_list|(
argument|FT_Error
argument_list|)
end_macro
begin_macro
name|FTC_Manager_Lookup_Size
argument_list|(
argument|FTC_Manager  manager
argument_list|,
argument|FTC_Font     font
argument_list|,
argument|FT_Face     *aface
argument_list|,
argument|FT_Size     *asize
argument_list|)
end_macro
begin_block
block|{
name|FTC_ScalerRec
name|scaler
decl_stmt|;
name|FT_Error
name|error
decl_stmt|;
name|FT_Size
name|size
decl_stmt|;
name|FT_Face
name|face
decl_stmt|;
name|scaler
operator|.
name|face_id
operator|=
name|font
operator|->
name|face_id
expr_stmt|;
name|scaler
operator|.
name|width
operator|=
name|font
operator|->
name|pix_width
expr_stmt|;
name|scaler
operator|.
name|height
operator|=
name|font
operator|->
name|pix_height
expr_stmt|;
name|scaler
operator|.
name|pixel
operator|=
name|TRUE
expr_stmt|;
name|scaler
operator|.
name|x_res
operator|=
literal|0
expr_stmt|;
name|scaler
operator|.
name|y_res
operator|=
literal|0
expr_stmt|;
name|error
operator|=
name|FTC_Manager_LookupSize
argument_list|(
name|manager
argument_list|,
operator|&
name|scaler
argument_list|,
operator|&
name|size
argument_list|)
expr_stmt|;
if|if
condition|(
name|error
condition|)
block|{
name|face
operator|=
name|NULL
expr_stmt|;
name|size
operator|=
name|NULL
expr_stmt|;
block|}
else|else
name|face
operator|=
name|size
operator|->
name|face
expr_stmt|;
if|if
condition|(
name|aface
condition|)
operator|*
name|aface
operator|=
name|face
expr_stmt|;
if|if
condition|(
name|asize
condition|)
operator|*
name|asize
operator|=
name|size
expr_stmt|;
return|return
name|error
return|;
block|}
end_block
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* FT_CONFIG_OPTION_OLD_INTERNALS */
end_comment
begin_comment
comment|/* END */
end_comment
end_unit
