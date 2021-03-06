begin_unit
begin_comment
comment|/***************************************************************************/
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  ftlzw.h                                                                */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*    LZW-compressed stream support.                                       */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  Copyright 2004-2015 by                                                 */
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
name|__FTLZW_H__
end_ifndef
begin_define
DECL|macro|__FTLZW_H__
define|#
directive|define
name|__FTLZW_H__
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
comment|/*    lzw                                                                */
comment|/*                                                                       */
comment|/*<Title>                                                               */
comment|/*    LZW Streams                                                        */
comment|/*                                                                       */
comment|/*<Abstract>                                                            */
comment|/*    Using LZW-compressed font files.                                   */
comment|/*                                                                       */
comment|/*<Description>                                                         */
comment|/*    This section contains the declaration of LZW-specific functions.   */
comment|/*                                                                       */
comment|/*************************************************************************/
comment|/************************************************************************   *   * @function:   *   FT_Stream_OpenLZW   *   * @description:   *   Open a new stream to parse LZW-compressed font files.  This is   *   mainly used to support the compressed `*.pcf.Z' fonts that come   *   with XFree86.   *   * @input:   *   stream :: The target embedding stream.   *   *   source :: The source stream.   *   * @return:   *   FreeType error code.  0~means success.   *   * @note:   *   The source stream must be opened _before_ calling this function.   *   *   Calling the internal function `FT_Stream_Close' on the new stream will   *   *not* call `FT_Stream_Close' on the source stream.  None of the stream   *   objects will be released to the heap.   *   *   The stream implementation is very basic and resets the decompression   *   process each time seeking backwards is needed within the stream   *   *   In certain builds of the library, LZW compression recognition is   *   automatically handled when calling @FT_New_Face or @FT_Open_Face.   *   This means that if no font driver is capable of handling the raw   *   compressed file, the library will try to open a LZW stream from it   *   and re-open the face with it.   *   *   This function may return `FT_Err_Unimplemented_Feature' if your build   *   of FreeType was not compiled with LZW support.   */
name|FT_EXPORT
parameter_list|(
name|FT_Error
parameter_list|)
function_decl|FT_Stream_OpenLZW
parameter_list|(
name|FT_Stream
name|stream
parameter_list|,
name|FT_Stream
name|source
parameter_list|)
function_decl|;
end_function_decl
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
comment|/* __FTLZW_H__ */
end_comment
begin_comment
comment|/* END */
end_comment
end_unit
