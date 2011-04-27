begin_unit
begin_comment
comment|/***************************************************************************/
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  t42objs.c                                                              */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*    Type 42 objects manager (body).                                      */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  Copyright 2002, 2003, 2004, 2005, 2006, 2007, 2008 by Roberto Alameda. */
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
file|"t42objs.h"
end_include
begin_include
include|#
directive|include
file|"t42parse.h"
end_include
begin_include
include|#
directive|include
file|"t42error.h"
end_include
begin_include
include|#
directive|include
include|FT_INTERNAL_DEBUG_H
end_include
begin_include
include|#
directive|include
include|FT_INTERNAL_STREAM_H
end_include
begin_include
include|#
directive|include
include|FT_LIST_H
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
value|trace_t42
end_define
begin_function
specifier|static
name|FT_Error
DECL|function|T42_Open_Face
name|T42_Open_Face
parameter_list|(
name|T42_Face
name|face
parameter_list|)
block|{
name|T42_LoaderRec
name|loader
decl_stmt|;
name|T42_Parser
name|parser
decl_stmt|;
name|T1_Font
name|type1
init|=
operator|&
name|face
operator|->
name|type1
decl_stmt|;
name|FT_Memory
name|memory
init|=
name|face
operator|->
name|root
operator|.
name|memory
decl_stmt|;
name|FT_Error
name|error
decl_stmt|;
name|PSAux_Service
name|psaux
init|=
operator|(
name|PSAux_Service
operator|)
name|face
operator|->
name|psaux
decl_stmt|;
name|t42_loader_init
argument_list|(
operator|&
name|loader
argument_list|,
name|face
argument_list|)
expr_stmt|;
name|parser
operator|=
operator|&
name|loader
operator|.
name|parser
expr_stmt|;
if|if
condition|(
name|FT_ALLOC
argument_list|(
name|face
operator|->
name|ttf_data
argument_list|,
literal|12
argument_list|)
condition|)
goto|goto
name|Exit
goto|;
name|error
operator|=
name|t42_parser_init
argument_list|(
name|parser
argument_list|,
name|face
operator|->
name|root
operator|.
name|stream
argument_list|,
name|memory
argument_list|,
name|psaux
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
name|t42_parse_dict
argument_list|(
name|face
argument_list|,
operator|&
name|loader
argument_list|,
name|parser
operator|->
name|base_dict
argument_list|,
name|parser
operator|->
name|base_len
argument_list|)
expr_stmt|;
if|if
condition|(
name|error
condition|)
goto|goto
name|Exit
goto|;
if|if
condition|(
name|type1
operator|->
name|font_type
operator|!=
literal|42
condition|)
block|{
name|error
operator|=
name|T42_Err_Unknown_File_Format
expr_stmt|;
goto|goto
name|Exit
goto|;
block|}
comment|/* now, propagate the charstrings and glyphnames tables */
comment|/* to the Type1 data                                    */
name|type1
operator|->
name|num_glyphs
operator|=
name|loader
operator|.
name|num_glyphs
expr_stmt|;
if|if
condition|(
operator|!
name|loader
operator|.
name|charstrings
operator|.
name|init
condition|)
block|{
name|FT_ERROR
argument_list|(
operator|(
literal|"T42_Open_Face: no charstrings array in face!\n"
operator|)
argument_list|)
expr_stmt|;
name|error
operator|=
name|T42_Err_Invalid_File_Format
expr_stmt|;
block|}
name|loader
operator|.
name|charstrings
operator|.
name|init
operator|=
literal|0
expr_stmt|;
name|type1
operator|->
name|charstrings_block
operator|=
name|loader
operator|.
name|charstrings
operator|.
name|block
expr_stmt|;
name|type1
operator|->
name|charstrings
operator|=
name|loader
operator|.
name|charstrings
operator|.
name|elements
expr_stmt|;
name|type1
operator|->
name|charstrings_len
operator|=
name|loader
operator|.
name|charstrings
operator|.
name|lengths
expr_stmt|;
comment|/* we copy the glyph names `block' and `elements' fields; */
comment|/* the `lengths' field must be released later             */
name|type1
operator|->
name|glyph_names_block
operator|=
name|loader
operator|.
name|glyph_names
operator|.
name|block
expr_stmt|;
name|type1
operator|->
name|glyph_names
operator|=
operator|(
name|FT_String
operator|*
operator|*
operator|)
name|loader
operator|.
name|glyph_names
operator|.
name|elements
expr_stmt|;
name|loader
operator|.
name|glyph_names
operator|.
name|block
operator|=
literal|0
expr_stmt|;
name|loader
operator|.
name|glyph_names
operator|.
name|elements
operator|=
literal|0
expr_stmt|;
comment|/* we must now build type1.encoding when we have a custom array */
if|if
condition|(
name|type1
operator|->
name|encoding_type
operator|==
name|T1_ENCODING_TYPE_ARRAY
condition|)
block|{
name|FT_Int
name|charcode
decl_stmt|,
name|idx
decl_stmt|,
name|min_char
decl_stmt|,
name|max_char
decl_stmt|;
name|FT_Byte
modifier|*
name|char_name
decl_stmt|;
name|FT_Byte
modifier|*
name|glyph_name
decl_stmt|;
comment|/* OK, we do the following: for each element in the encoding   */
comment|/* table, look up the index of the glyph having the same name  */
comment|/* as defined in the CharStrings array.                        */
comment|/* The index is then stored in type1.encoding.char_index, and  */
comment|/* the name in type1.encoding.char_name                        */
name|min_char
operator|=
operator|+
literal|32000
expr_stmt|;
name|max_char
operator|=
operator|-
literal|32000
expr_stmt|;
name|charcode
operator|=
literal|0
expr_stmt|;
for|for
control|(
init|;
name|charcode
operator|<
name|loader
operator|.
name|encoding_table
operator|.
name|max_elems
condition|;
name|charcode
operator|++
control|)
block|{
name|type1
operator|->
name|encoding
operator|.
name|char_index
index|[
name|charcode
index|]
operator|=
literal|0
expr_stmt|;
name|type1
operator|->
name|encoding
operator|.
name|char_name
index|[
name|charcode
index|]
operator|=
operator|(
name|char
operator|*
operator|)
literal|".notdef"
expr_stmt|;
name|char_name
operator|=
name|loader
operator|.
name|encoding_table
operator|.
name|elements
index|[
name|charcode
index|]
expr_stmt|;
if|if
condition|(
name|char_name
condition|)
for|for
control|(
name|idx
operator|=
literal|0
init|;
name|idx
operator|<
name|type1
operator|->
name|num_glyphs
condition|;
name|idx
operator|++
control|)
block|{
name|glyph_name
operator|=
operator|(
name|FT_Byte
operator|*
operator|)
name|type1
operator|->
name|glyph_names
index|[
name|idx
index|]
expr_stmt|;
if|if
condition|(
name|ft_strcmp
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|)
name|char_name
argument_list|,
operator|(
specifier|const
name|char
operator|*
operator|)
name|glyph_name
argument_list|)
operator|==
literal|0
condition|)
block|{
name|type1
operator|->
name|encoding
operator|.
name|char_index
index|[
name|charcode
index|]
operator|=
operator|(
name|FT_UShort
operator|)
name|idx
expr_stmt|;
name|type1
operator|->
name|encoding
operator|.
name|char_name
index|[
name|charcode
index|]
operator|=
operator|(
name|char
operator|*
operator|)
name|glyph_name
expr_stmt|;
comment|/* Change min/max encoded char only if glyph name is */
comment|/* not /.notdef                                      */
if|if
condition|(
name|ft_strcmp
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|)
literal|".notdef"
argument_list|,
operator|(
specifier|const
name|char
operator|*
operator|)
name|glyph_name
argument_list|)
operator|!=
literal|0
condition|)
block|{
if|if
condition|(
name|charcode
operator|<
name|min_char
condition|)
name|min_char
operator|=
name|charcode
expr_stmt|;
if|if
condition|(
name|charcode
operator|>
name|max_char
condition|)
name|max_char
operator|=
name|charcode
expr_stmt|;
block|}
break|break;
block|}
block|}
block|}
name|type1
operator|->
name|encoding
operator|.
name|code_first
operator|=
name|min_char
expr_stmt|;
name|type1
operator|->
name|encoding
operator|.
name|code_last
operator|=
name|max_char
expr_stmt|;
name|type1
operator|->
name|encoding
operator|.
name|num_chars
operator|=
name|loader
operator|.
name|num_chars
expr_stmt|;
block|}
name|Exit
label|:
name|t42_loader_done
argument_list|(
operator|&
name|loader
argument_list|)
expr_stmt|;
return|return
name|error
return|;
block|}
end_function
begin_comment
comment|/***************** Driver Functions *************/
end_comment
begin_macro
DECL|function|FT_LOCAL_DEF
name|FT_LOCAL_DEF
argument_list|(
argument|FT_Error
argument_list|)
end_macro
begin_macro
name|T42_Face_Init
argument_list|(
argument|FT_Stream      stream
argument_list|,
argument|T42_Face       face
argument_list|,
argument|FT_Int         face_index
argument_list|,
argument|FT_Int         num_params
argument_list|,
argument|FT_Parameter*  params
argument_list|)
end_macro
begin_block
block|{
name|FT_Error
name|error
decl_stmt|;
name|FT_Service_PsCMaps
name|psnames
decl_stmt|;
name|PSAux_Service
name|psaux
decl_stmt|;
name|FT_Face
name|root
init|=
operator|(
name|FT_Face
operator|)
operator|&
name|face
operator|->
name|root
decl_stmt|;
name|T1_Font
name|type1
init|=
operator|&
name|face
operator|->
name|type1
decl_stmt|;
name|PS_FontInfo
name|info
init|=
operator|&
name|type1
operator|->
name|font_info
decl_stmt|;
name|FT_UNUSED
argument_list|(
name|num_params
argument_list|)
expr_stmt|;
name|FT_UNUSED
argument_list|(
name|params
argument_list|)
expr_stmt|;
name|FT_UNUSED
argument_list|(
name|face_index
argument_list|)
expr_stmt|;
name|FT_UNUSED
argument_list|(
name|stream
argument_list|)
expr_stmt|;
name|face
operator|->
name|ttf_face
operator|=
name|NULL
expr_stmt|;
name|face
operator|->
name|root
operator|.
name|num_faces
operator|=
literal|1
expr_stmt|;
name|FT_FACE_FIND_GLOBAL_SERVICE
argument_list|(
name|face
argument_list|,
name|psnames
argument_list|,
name|POSTSCRIPT_CMAPS
argument_list|)
expr_stmt|;
name|face
operator|->
name|psnames
operator|=
name|psnames
expr_stmt|;
name|face
operator|->
name|psaux
operator|=
name|FT_Get_Module_Interface
argument_list|(
name|FT_FACE_LIBRARY
argument_list|(
name|face
argument_list|)
argument_list|,
literal|"psaux"
argument_list|)
expr_stmt|;
name|psaux
operator|=
operator|(
name|PSAux_Service
operator|)
name|face
operator|->
name|psaux
expr_stmt|;
comment|/* open the tokenizer, this will also check the font format */
name|error
operator|=
name|T42_Open_Face
argument_list|(
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
comment|/* if we just wanted to check the format, leave successfully now */
if|if
condition|(
name|face_index
operator|<
literal|0
condition|)
goto|goto
name|Exit
goto|;
comment|/* check the face index */
if|if
condition|(
name|face_index
operator|>
literal|0
condition|)
block|{
name|FT_ERROR
argument_list|(
operator|(
literal|"T42_Face_Init: invalid face index\n"
operator|)
argument_list|)
expr_stmt|;
name|error
operator|=
name|T42_Err_Invalid_Argument
expr_stmt|;
goto|goto
name|Exit
goto|;
block|}
comment|/* Now load the font program into the face object */
comment|/* Init the face object fields */
comment|/* Now set up root face fields */
name|root
operator|->
name|num_glyphs
operator|=
name|type1
operator|->
name|num_glyphs
expr_stmt|;
name|root
operator|->
name|num_charmaps
operator|=
literal|0
expr_stmt|;
name|root
operator|->
name|face_index
operator|=
literal|0
expr_stmt|;
name|root
operator|->
name|face_flags
operator|=
name|FT_FACE_FLAG_SCALABLE
operator||
name|FT_FACE_FLAG_HORIZONTAL
operator||
name|FT_FACE_FLAG_GLYPH_NAMES
expr_stmt|;
if|if
condition|(
name|info
operator|->
name|is_fixed_pitch
condition|)
name|root
operator|->
name|face_flags
operator||=
name|FT_FACE_FLAG_FIXED_WIDTH
expr_stmt|;
comment|/* We only set this flag if we have the patented bytecode interpreter. */
comment|/* There are no known `tricky' Type42 fonts that could be loaded with  */
comment|/* the unpatented interpreter.                                         */
ifdef|#
directive|ifdef
name|TT_CONFIG_OPTION_BYTECODE_INTERPRETER
name|root
operator|->
name|face_flags
operator||=
name|FT_FACE_FLAG_HINTER
expr_stmt|;
endif|#
directive|endif
comment|/* XXX: TODO -- add kerning with .afm support */
comment|/* get style name -- be careful, some broken fonts only */
comment|/* have a `/FontName' dictionary entry!                 */
name|root
operator|->
name|family_name
operator|=
name|info
operator|->
name|family_name
expr_stmt|;
comment|/* assume "Regular" style if we don't know better */
name|root
operator|->
name|style_name
operator|=
operator|(
name|char
operator|*
operator|)
literal|"Regular"
expr_stmt|;
if|if
condition|(
name|root
operator|->
name|family_name
condition|)
block|{
name|char
modifier|*
name|full
init|=
name|info
operator|->
name|full_name
decl_stmt|;
name|char
modifier|*
name|family
init|=
name|root
operator|->
name|family_name
decl_stmt|;
if|if
condition|(
name|full
condition|)
block|{
while|while
condition|(
operator|*
name|full
condition|)
block|{
if|if
condition|(
operator|*
name|full
operator|==
operator|*
name|family
condition|)
block|{
name|family
operator|++
expr_stmt|;
name|full
operator|++
expr_stmt|;
block|}
else|else
block|{
if|if
condition|(
operator|*
name|full
operator|==
literal|' '
operator|||
operator|*
name|full
operator|==
literal|'-'
condition|)
name|full
operator|++
expr_stmt|;
elseif|else
if|if
condition|(
operator|*
name|family
operator|==
literal|' '
operator|||
operator|*
name|family
operator|==
literal|'-'
condition|)
name|family
operator|++
expr_stmt|;
else|else
block|{
if|if
condition|(
operator|!
operator|*
name|family
condition|)
name|root
operator|->
name|style_name
operator|=
name|full
expr_stmt|;
break|break;
block|}
block|}
block|}
block|}
block|}
else|else
block|{
comment|/* do we have a `/FontName'? */
if|if
condition|(
name|type1
operator|->
name|font_name
condition|)
name|root
operator|->
name|family_name
operator|=
name|type1
operator|->
name|font_name
expr_stmt|;
block|}
comment|/* no embedded bitmap support */
name|root
operator|->
name|num_fixed_sizes
operator|=
literal|0
expr_stmt|;
name|root
operator|->
name|available_sizes
operator|=
literal|0
expr_stmt|;
comment|/* Load the TTF font embedded in the T42 font */
block|{
name|FT_Open_Args
name|args
decl_stmt|;
name|args
operator|.
name|flags
operator|=
name|FT_OPEN_MEMORY
expr_stmt|;
name|args
operator|.
name|memory_base
operator|=
name|face
operator|->
name|ttf_data
expr_stmt|;
name|args
operator|.
name|memory_size
operator|=
name|face
operator|->
name|ttf_size
expr_stmt|;
if|if
condition|(
name|num_params
condition|)
block|{
name|args
operator|.
name|flags
operator||=
name|FT_OPEN_PARAMS
expr_stmt|;
name|args
operator|.
name|num_params
operator|=
name|num_params
expr_stmt|;
name|args
operator|.
name|params
operator|=
name|params
expr_stmt|;
block|}
name|error
operator|=
name|FT_Open_Face
argument_list|(
name|FT_FACE_LIBRARY
argument_list|(
name|face
argument_list|)
argument_list|,
operator|&
name|args
argument_list|,
literal|0
argument_list|,
operator|&
name|face
operator|->
name|ttf_face
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|error
condition|)
goto|goto
name|Exit
goto|;
name|FT_Done_Size
argument_list|(
name|face
operator|->
name|ttf_face
operator|->
name|size
argument_list|)
expr_stmt|;
comment|/* Ignore info in FontInfo dictionary and use the info from the  */
comment|/* loaded TTF font.  The PostScript interpreter also ignores it. */
name|root
operator|->
name|bbox
operator|=
name|face
operator|->
name|ttf_face
operator|->
name|bbox
expr_stmt|;
name|root
operator|->
name|units_per_EM
operator|=
name|face
operator|->
name|ttf_face
operator|->
name|units_per_EM
expr_stmt|;
name|root
operator|->
name|ascender
operator|=
name|face
operator|->
name|ttf_face
operator|->
name|ascender
expr_stmt|;
name|root
operator|->
name|descender
operator|=
name|face
operator|->
name|ttf_face
operator|->
name|descender
expr_stmt|;
name|root
operator|->
name|height
operator|=
name|face
operator|->
name|ttf_face
operator|->
name|height
expr_stmt|;
name|root
operator|->
name|max_advance_width
operator|=
name|face
operator|->
name|ttf_face
operator|->
name|max_advance_width
expr_stmt|;
name|root
operator|->
name|max_advance_height
operator|=
name|face
operator|->
name|ttf_face
operator|->
name|max_advance_height
expr_stmt|;
name|root
operator|->
name|underline_position
operator|=
operator|(
name|FT_Short
operator|)
name|info
operator|->
name|underline_position
expr_stmt|;
name|root
operator|->
name|underline_thickness
operator|=
operator|(
name|FT_Short
operator|)
name|info
operator|->
name|underline_thickness
expr_stmt|;
comment|/* compute style flags */
name|root
operator|->
name|style_flags
operator|=
literal|0
expr_stmt|;
if|if
condition|(
name|info
operator|->
name|italic_angle
condition|)
name|root
operator|->
name|style_flags
operator||=
name|FT_STYLE_FLAG_ITALIC
expr_stmt|;
if|if
condition|(
name|face
operator|->
name|ttf_face
operator|->
name|style_flags
operator|&
name|FT_STYLE_FLAG_BOLD
condition|)
name|root
operator|->
name|style_flags
operator||=
name|FT_STYLE_FLAG_BOLD
expr_stmt|;
if|if
condition|(
name|face
operator|->
name|ttf_face
operator|->
name|face_flags
operator|&
name|FT_FACE_FLAG_VERTICAL
condition|)
name|root
operator|->
name|face_flags
operator||=
name|FT_FACE_FLAG_VERTICAL
expr_stmt|;
block|{
if|if
condition|(
name|psnames
operator|&&
name|psaux
condition|)
block|{
name|FT_CharMapRec
name|charmap
decl_stmt|;
name|T1_CMap_Classes
name|cmap_classes
init|=
name|psaux
operator|->
name|t1_cmap_classes
decl_stmt|;
name|FT_CMap_Class
name|clazz
decl_stmt|;
name|charmap
operator|.
name|face
operator|=
name|root
expr_stmt|;
comment|/* first of all, try to synthesize a Unicode charmap */
name|charmap
operator|.
name|platform_id
operator|=
literal|3
expr_stmt|;
name|charmap
operator|.
name|encoding_id
operator|=
literal|1
expr_stmt|;
name|charmap
operator|.
name|encoding
operator|=
name|FT_ENCODING_UNICODE
expr_stmt|;
name|FT_CMap_New
argument_list|(
name|cmap_classes
operator|->
name|unicode
argument_list|,
name|NULL
argument_list|,
operator|&
name|charmap
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
comment|/* now, generate an Adobe Standard encoding when appropriate */
name|charmap
operator|.
name|platform_id
operator|=
literal|7
expr_stmt|;
name|clazz
operator|=
name|NULL
expr_stmt|;
switch|switch
condition|(
name|type1
operator|->
name|encoding_type
condition|)
block|{
case|case
name|T1_ENCODING_TYPE_STANDARD
case|:
name|charmap
operator|.
name|encoding
operator|=
name|FT_ENCODING_ADOBE_STANDARD
expr_stmt|;
name|charmap
operator|.
name|encoding_id
operator|=
literal|0
expr_stmt|;
name|clazz
operator|=
name|cmap_classes
operator|->
name|standard
expr_stmt|;
break|break;
case|case
name|T1_ENCODING_TYPE_EXPERT
case|:
name|charmap
operator|.
name|encoding
operator|=
name|FT_ENCODING_ADOBE_EXPERT
expr_stmt|;
name|charmap
operator|.
name|encoding_id
operator|=
literal|1
expr_stmt|;
name|clazz
operator|=
name|cmap_classes
operator|->
name|expert
expr_stmt|;
break|break;
case|case
name|T1_ENCODING_TYPE_ARRAY
case|:
name|charmap
operator|.
name|encoding
operator|=
name|FT_ENCODING_ADOBE_CUSTOM
expr_stmt|;
name|charmap
operator|.
name|encoding_id
operator|=
literal|2
expr_stmt|;
name|clazz
operator|=
name|cmap_classes
operator|->
name|custom
expr_stmt|;
break|break;
case|case
name|T1_ENCODING_TYPE_ISOLATIN1
case|:
name|charmap
operator|.
name|encoding
operator|=
name|FT_ENCODING_ADOBE_LATIN_1
expr_stmt|;
name|charmap
operator|.
name|encoding_id
operator|=
literal|3
expr_stmt|;
name|clazz
operator|=
name|cmap_classes
operator|->
name|unicode
expr_stmt|;
break|break;
default|default:
empty_stmt|;
block|}
if|if
condition|(
name|clazz
condition|)
name|FT_CMap_New
argument_list|(
name|clazz
argument_list|,
name|NULL
argument_list|,
operator|&
name|charmap
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
if|#
directive|if
literal|0
comment|/* Select default charmap */
block|if ( root->num_charmaps )           root->charmap = root->charmaps[0];
endif|#
directive|endif
block|}
block|}
name|Exit
label|:
return|return
name|error
return|;
block|}
end_block
begin_macro
name|FT_LOCAL_DEF
argument_list|(
argument|void
argument_list|)
end_macro
begin_macro
DECL|function|T42_Face_Done
name|T42_Face_Done
argument_list|(
argument|T42_Face  face
argument_list|)
end_macro
begin_block
block|{
name|T1_Font
name|type1
decl_stmt|;
name|PS_FontInfo
name|info
decl_stmt|;
name|FT_Memory
name|memory
decl_stmt|;
if|if
condition|(
operator|!
name|face
condition|)
return|return;
name|type1
operator|=
operator|&
name|face
operator|->
name|type1
expr_stmt|;
name|info
operator|=
operator|&
name|type1
operator|->
name|font_info
expr_stmt|;
name|memory
operator|=
name|face
operator|->
name|root
operator|.
name|memory
expr_stmt|;
comment|/* delete internal ttf face prior to freeing face->ttf_data */
if|if
condition|(
name|face
operator|->
name|ttf_face
condition|)
name|FT_Done_Face
argument_list|(
name|face
operator|->
name|ttf_face
argument_list|)
expr_stmt|;
comment|/* release font info strings */
name|FT_FREE
argument_list|(
name|info
operator|->
name|version
argument_list|)
expr_stmt|;
name|FT_FREE
argument_list|(
name|info
operator|->
name|notice
argument_list|)
expr_stmt|;
name|FT_FREE
argument_list|(
name|info
operator|->
name|full_name
argument_list|)
expr_stmt|;
name|FT_FREE
argument_list|(
name|info
operator|->
name|family_name
argument_list|)
expr_stmt|;
name|FT_FREE
argument_list|(
name|info
operator|->
name|weight
argument_list|)
expr_stmt|;
comment|/* release top dictionary */
name|FT_FREE
argument_list|(
name|type1
operator|->
name|charstrings_len
argument_list|)
expr_stmt|;
name|FT_FREE
argument_list|(
name|type1
operator|->
name|charstrings
argument_list|)
expr_stmt|;
name|FT_FREE
argument_list|(
name|type1
operator|->
name|glyph_names
argument_list|)
expr_stmt|;
name|FT_FREE
argument_list|(
name|type1
operator|->
name|charstrings_block
argument_list|)
expr_stmt|;
name|FT_FREE
argument_list|(
name|type1
operator|->
name|glyph_names_block
argument_list|)
expr_stmt|;
name|FT_FREE
argument_list|(
name|type1
operator|->
name|encoding
operator|.
name|char_index
argument_list|)
expr_stmt|;
name|FT_FREE
argument_list|(
name|type1
operator|->
name|encoding
operator|.
name|char_name
argument_list|)
expr_stmt|;
name|FT_FREE
argument_list|(
name|type1
operator|->
name|font_name
argument_list|)
expr_stmt|;
name|FT_FREE
argument_list|(
name|face
operator|->
name|ttf_data
argument_list|)
expr_stmt|;
if|#
directive|if
literal|0
comment|/* release afm data if present */
block|if ( face->afm_data )       T1_Done_AFM( memory, (T1_AFM*)face->afm_data );
endif|#
directive|endif
comment|/* release unicode map, if any */
name|FT_FREE
argument_list|(
name|face
operator|->
name|unicode_map
operator|.
name|maps
argument_list|)
expr_stmt|;
name|face
operator|->
name|unicode_map
operator|.
name|num_maps
operator|=
literal|0
expr_stmt|;
name|face
operator|->
name|root
operator|.
name|family_name
operator|=
literal|0
expr_stmt|;
name|face
operator|->
name|root
operator|.
name|style_name
operator|=
literal|0
expr_stmt|;
block|}
end_block
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Function>                                                            */
end_comment
begin_comment
comment|/*    T42_Driver_Init                                                    */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    Initializes a given Type 42 driver object.                         */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Input>                                                               */
end_comment
begin_comment
comment|/*    driver :: A handle to the target driver object.                    */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Return>                                                              */
end_comment
begin_comment
comment|/*    FreeType error code.  0 means success.                             */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_macro
DECL|function|FT_LOCAL_DEF
name|FT_LOCAL_DEF
argument_list|(
argument|FT_Error
argument_list|)
end_macro
begin_macro
name|T42_Driver_Init
argument_list|(
argument|T42_Driver  driver
argument_list|)
end_macro
begin_block
block|{
name|FT_Module
name|ttmodule
decl_stmt|;
name|ttmodule
operator|=
name|FT_Get_Module
argument_list|(
name|FT_MODULE
argument_list|(
name|driver
argument_list|)
operator|->
name|library
argument_list|,
literal|"truetype"
argument_list|)
expr_stmt|;
name|driver
operator|->
name|ttclazz
operator|=
operator|(
name|FT_Driver_Class
operator|)
name|ttmodule
operator|->
name|clazz
expr_stmt|;
return|return
name|T42_Err_Ok
return|;
block|}
end_block
begin_macro
name|FT_LOCAL_DEF
argument_list|(
argument|void
argument_list|)
end_macro
begin_macro
DECL|function|T42_Driver_Done
name|T42_Driver_Done
argument_list|(
argument|T42_Driver  driver
argument_list|)
end_macro
begin_block
block|{
name|FT_UNUSED
argument_list|(
name|driver
argument_list|)
expr_stmt|;
block|}
end_block
begin_macro
DECL|function|FT_LOCAL_DEF
name|FT_LOCAL_DEF
argument_list|(
argument|FT_Error
argument_list|)
end_macro
begin_macro
name|T42_Size_Init
argument_list|(
argument|T42_Size  size
argument_list|)
end_macro
begin_block
block|{
name|FT_Face
name|face
init|=
name|size
operator|->
name|root
operator|.
name|face
decl_stmt|;
name|T42_Face
name|t42face
init|=
operator|(
name|T42_Face
operator|)
name|face
decl_stmt|;
name|FT_Size
name|ttsize
decl_stmt|;
name|FT_Error
name|error
init|=
name|T42_Err_Ok
decl_stmt|;
name|error
operator|=
name|FT_New_Size
argument_list|(
name|t42face
operator|->
name|ttf_face
argument_list|,
operator|&
name|ttsize
argument_list|)
expr_stmt|;
name|size
operator|->
name|ttsize
operator|=
name|ttsize
expr_stmt|;
name|FT_Activate_Size
argument_list|(
name|ttsize
argument_list|)
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
argument|FT_Error
argument_list|)
end_macro
begin_macro
name|T42_Size_Request
argument_list|(
argument|T42_Size         size
argument_list|,
argument|FT_Size_Request  req
argument_list|)
end_macro
begin_block
block|{
name|T42_Face
name|face
init|=
operator|(
name|T42_Face
operator|)
name|size
operator|->
name|root
operator|.
name|face
decl_stmt|;
name|FT_Error
name|error
decl_stmt|;
name|FT_Activate_Size
argument_list|(
name|size
operator|->
name|ttsize
argument_list|)
expr_stmt|;
name|error
operator|=
name|FT_Request_Size
argument_list|(
name|face
operator|->
name|ttf_face
argument_list|,
name|req
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|error
condition|)
operator|(
operator|(
name|FT_Size
operator|)
name|size
operator|)
operator|->
name|metrics
operator|=
name|face
operator|->
name|ttf_face
operator|->
name|size
operator|->
name|metrics
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
argument|FT_Error
argument_list|)
end_macro
begin_macro
name|T42_Size_Select
argument_list|(
argument|T42_Size  size
argument_list|,
argument|FT_ULong  strike_index
argument_list|)
end_macro
begin_block
block|{
name|T42_Face
name|face
init|=
operator|(
name|T42_Face
operator|)
name|size
operator|->
name|root
operator|.
name|face
decl_stmt|;
name|FT_Error
name|error
decl_stmt|;
name|FT_Activate_Size
argument_list|(
name|size
operator|->
name|ttsize
argument_list|)
expr_stmt|;
name|error
operator|=
name|FT_Select_Size
argument_list|(
name|face
operator|->
name|ttf_face
argument_list|,
operator|(
name|FT_Int
operator|)
name|strike_index
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|error
condition|)
operator|(
operator|(
name|FT_Size
operator|)
name|size
operator|)
operator|->
name|metrics
operator|=
name|face
operator|->
name|ttf_face
operator|->
name|size
operator|->
name|metrics
expr_stmt|;
return|return
name|error
return|;
block|}
end_block
begin_macro
name|FT_LOCAL_DEF
argument_list|(
argument|void
argument_list|)
end_macro
begin_macro
DECL|function|T42_Size_Done
name|T42_Size_Done
argument_list|(
argument|T42_Size  size
argument_list|)
end_macro
begin_block
block|{
name|FT_Face
name|face
init|=
name|size
operator|->
name|root
operator|.
name|face
decl_stmt|;
name|T42_Face
name|t42face
init|=
operator|(
name|T42_Face
operator|)
name|face
decl_stmt|;
name|FT_ListNode
name|node
decl_stmt|;
name|node
operator|=
name|FT_List_Find
argument_list|(
operator|&
name|t42face
operator|->
name|ttf_face
operator|->
name|sizes_list
argument_list|,
name|size
operator|->
name|ttsize
argument_list|)
expr_stmt|;
if|if
condition|(
name|node
condition|)
block|{
name|FT_Done_Size
argument_list|(
name|size
operator|->
name|ttsize
argument_list|)
expr_stmt|;
name|size
operator|->
name|ttsize
operator|=
name|NULL
expr_stmt|;
block|}
block|}
end_block
begin_macro
DECL|function|FT_LOCAL_DEF
name|FT_LOCAL_DEF
argument_list|(
argument|FT_Error
argument_list|)
end_macro
begin_macro
name|T42_GlyphSlot_Init
argument_list|(
argument|T42_GlyphSlot  slot
argument_list|)
end_macro
begin_block
block|{
name|FT_Face
name|face
init|=
name|slot
operator|->
name|root
operator|.
name|face
decl_stmt|;
name|T42_Face
name|t42face
init|=
operator|(
name|T42_Face
operator|)
name|face
decl_stmt|;
name|FT_GlyphSlot
name|ttslot
decl_stmt|;
name|FT_Error
name|error
init|=
name|T42_Err_Ok
decl_stmt|;
if|if
condition|(
name|face
operator|->
name|glyph
operator|==
name|NULL
condition|)
block|{
comment|/* First glyph slot for this face */
name|slot
operator|->
name|ttslot
operator|=
name|t42face
operator|->
name|ttf_face
operator|->
name|glyph
expr_stmt|;
block|}
else|else
block|{
name|error
operator|=
name|FT_New_GlyphSlot
argument_list|(
name|t42face
operator|->
name|ttf_face
argument_list|,
operator|&
name|ttslot
argument_list|)
expr_stmt|;
name|slot
operator|->
name|ttslot
operator|=
name|ttslot
expr_stmt|;
block|}
return|return
name|error
return|;
block|}
end_block
begin_macro
name|FT_LOCAL_DEF
argument_list|(
argument|void
argument_list|)
end_macro
begin_macro
DECL|function|T42_GlyphSlot_Done
name|T42_GlyphSlot_Done
argument_list|(
argument|T42_GlyphSlot slot
argument_list|)
end_macro
begin_block
block|{
name|FT_Done_GlyphSlot
argument_list|(
name|slot
operator|->
name|ttslot
argument_list|)
expr_stmt|;
block|}
end_block
begin_function
specifier|static
name|void
DECL|function|t42_glyphslot_clear
name|t42_glyphslot_clear
parameter_list|(
name|FT_GlyphSlot
name|slot
parameter_list|)
block|{
comment|/* free bitmap if needed */
name|ft_glyphslot_free_bitmap
argument_list|(
name|slot
argument_list|)
expr_stmt|;
comment|/* clear all public fields in the glyph slot */
name|FT_ZERO
argument_list|(
operator|&
name|slot
operator|->
name|metrics
argument_list|)
expr_stmt|;
name|FT_ZERO
argument_list|(
operator|&
name|slot
operator|->
name|outline
argument_list|)
expr_stmt|;
name|FT_ZERO
argument_list|(
operator|&
name|slot
operator|->
name|bitmap
argument_list|)
expr_stmt|;
name|slot
operator|->
name|bitmap_left
operator|=
literal|0
expr_stmt|;
name|slot
operator|->
name|bitmap_top
operator|=
literal|0
expr_stmt|;
name|slot
operator|->
name|num_subglyphs
operator|=
literal|0
expr_stmt|;
name|slot
operator|->
name|subglyphs
operator|=
literal|0
expr_stmt|;
name|slot
operator|->
name|control_data
operator|=
literal|0
expr_stmt|;
name|slot
operator|->
name|control_len
operator|=
literal|0
expr_stmt|;
name|slot
operator|->
name|other
operator|=
literal|0
expr_stmt|;
name|slot
operator|->
name|format
operator|=
name|FT_GLYPH_FORMAT_NONE
expr_stmt|;
name|slot
operator|->
name|linearHoriAdvance
operator|=
literal|0
expr_stmt|;
name|slot
operator|->
name|linearVertAdvance
operator|=
literal|0
expr_stmt|;
block|}
end_function
begin_macro
DECL|function|FT_LOCAL_DEF
name|FT_LOCAL_DEF
argument_list|(
argument|FT_Error
argument_list|)
end_macro
begin_macro
name|T42_GlyphSlot_Load
argument_list|(
argument|FT_GlyphSlot  glyph
argument_list|,
argument|FT_Size       size
argument_list|,
argument|FT_UInt       glyph_index
argument_list|,
argument|FT_Int32      load_flags
argument_list|)
end_macro
begin_block
block|{
name|FT_Error
name|error
decl_stmt|;
name|T42_GlyphSlot
name|t42slot
init|=
operator|(
name|T42_GlyphSlot
operator|)
name|glyph
decl_stmt|;
name|T42_Size
name|t42size
init|=
operator|(
name|T42_Size
operator|)
name|size
decl_stmt|;
name|FT_Driver_Class
name|ttclazz
init|=
operator|(
operator|(
name|T42_Driver
operator|)
name|glyph
operator|->
name|face
operator|->
name|driver
operator|)
operator|->
name|ttclazz
decl_stmt|;
name|t42_glyphslot_clear
argument_list|(
name|t42slot
operator|->
name|ttslot
argument_list|)
expr_stmt|;
name|error
operator|=
name|ttclazz
operator|->
name|load_glyph
argument_list|(
name|t42slot
operator|->
name|ttslot
argument_list|,
name|t42size
operator|->
name|ttsize
argument_list|,
name|glyph_index
argument_list|,
name|load_flags
operator||
name|FT_LOAD_NO_BITMAP
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|error
condition|)
block|{
name|glyph
operator|->
name|metrics
operator|=
name|t42slot
operator|->
name|ttslot
operator|->
name|metrics
expr_stmt|;
name|glyph
operator|->
name|linearHoriAdvance
operator|=
name|t42slot
operator|->
name|ttslot
operator|->
name|linearHoriAdvance
expr_stmt|;
name|glyph
operator|->
name|linearVertAdvance
operator|=
name|t42slot
operator|->
name|ttslot
operator|->
name|linearVertAdvance
expr_stmt|;
name|glyph
operator|->
name|format
operator|=
name|t42slot
operator|->
name|ttslot
operator|->
name|format
expr_stmt|;
name|glyph
operator|->
name|outline
operator|=
name|t42slot
operator|->
name|ttslot
operator|->
name|outline
expr_stmt|;
name|glyph
operator|->
name|bitmap
operator|=
name|t42slot
operator|->
name|ttslot
operator|->
name|bitmap
expr_stmt|;
name|glyph
operator|->
name|bitmap_left
operator|=
name|t42slot
operator|->
name|ttslot
operator|->
name|bitmap_left
expr_stmt|;
name|glyph
operator|->
name|bitmap_top
operator|=
name|t42slot
operator|->
name|ttslot
operator|->
name|bitmap_top
expr_stmt|;
name|glyph
operator|->
name|num_subglyphs
operator|=
name|t42slot
operator|->
name|ttslot
operator|->
name|num_subglyphs
expr_stmt|;
name|glyph
operator|->
name|subglyphs
operator|=
name|t42slot
operator|->
name|ttslot
operator|->
name|subglyphs
expr_stmt|;
name|glyph
operator|->
name|control_data
operator|=
name|t42slot
operator|->
name|ttslot
operator|->
name|control_data
expr_stmt|;
name|glyph
operator|->
name|control_len
operator|=
name|t42slot
operator|->
name|ttslot
operator|->
name|control_len
expr_stmt|;
block|}
return|return
name|error
return|;
block|}
end_block
begin_comment
comment|/* END */
end_comment
end_unit
