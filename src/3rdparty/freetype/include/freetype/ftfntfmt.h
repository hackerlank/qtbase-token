begin_unit
begin_comment
comment|/***************************************************************************/
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  ftfntfmt.h                                                             */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*    Support functions for font formats.                                  */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  Copyright 2002-2015 by                                                 */
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
name|__FTFNTFMT_H__
end_ifndef
begin_define
DECL|macro|__FTFNTFMT_H__
define|#
directive|define
name|__FTFNTFMT_H__
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
begin_ifdef
ifdef|#
directive|ifdef
name|FREETYPE_H
end_ifdef
begin_error
error|#
directive|error
literal|"freetype.h of FreeType 1 has been loaded!"
end_error
begin_error
error|#
directive|error
literal|"Please fix the directory search order for header files"
end_error
begin_error
error|#
directive|error
literal|"so that freetype.h of FreeType 2 is found first."
end_error
begin_endif
endif|#
directive|endif
end_endif
begin_function_decl
name|FT_BEGIN_HEADER
comment|/*************************************************************************/
comment|/*                                                                       */
comment|/*<Section>                                                             */
comment|/*   font_formats                                                        */
comment|/*                                                                       */
comment|/*<Title>                                                               */
comment|/*   Font Formats                                                        */
comment|/*                                                                       */
comment|/*<Abstract>                                                            */
comment|/*   Getting the font format.                                            */
comment|/*                                                                       */
comment|/*<Description>                                                         */
comment|/*   The single function in this section can be used to get the font     */
comment|/*   format.  Note that this information is not needed normally;         */
comment|/*   however, there are special cases (like in PDF devices) where it is  */
comment|/*   important to differentiate, in spite of FreeType's uniform API.     */
comment|/*                                                                       */
comment|/*************************************************************************/
comment|/*************************************************************************/
comment|/*                                                                       */
comment|/*<Function>                                                            */
comment|/*   FT_Get_Font_Format                                                  */
comment|/*                                                                       */
comment|/*<Description>                                                         */
comment|/*   Return a string describing the format of a given face.  Possible    */
comment|/*   values are `TrueType', `Type~1', `BDF', `PCF', `Type~42',           */
comment|/*   `CID~Type~1', `CFF', `PFR', and `Windows~FNT'.                      */
comment|/*                                                                       */
comment|/*   The return value is suitable to be used as an X11 FONT_PROPERTY.    */
comment|/*                                                                       */
comment|/*<Input>                                                               */
comment|/*   face ::                                                             */
comment|/*     Input face handle.                                                */
comment|/*                                                                       */
comment|/*<Return>                                                              */
comment|/*   Font format string.  NULL in case of error.                         */
comment|/*                                                                       */
comment|/*<Note>                                                                */
comment|/*   A deprecated name for the same function is                          */
comment|/*   `FT_Get_X11_Font_Format'.                                           */
comment|/*                                                                       */
name|FT_EXPORT
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|FT_Get_Font_Format
DECL|variable|face
parameter_list|(
name|FT_Face
name|face
parameter_list|)
function_decl|;
end_function_decl
begin_comment
comment|/* deprecated */
end_comment
begin_macro
name|FT_EXPORT
argument_list|(
argument|const char*
argument_list|)
end_macro
begin_macro
DECL|variable|face
name|FT_Get_X11_Font_Format
argument_list|(
argument|FT_Face  face
argument_list|)
end_macro
begin_empty_stmt
DECL|variable|face
empty_stmt|;
end_empty_stmt
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
comment|/* __FTFNTFMT_H__ */
end_comment
end_unit
