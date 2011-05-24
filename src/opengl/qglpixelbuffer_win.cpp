begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtOpenGL module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<qglpixelbuffer.h>
end_include
begin_include
include|#
directive|include
file|<qgl.h>
end_include
begin_include
include|#
directive|include
file|<private/qgl_p.h>
end_include
begin_include
include|#
directive|include
file|<private/qglpixelbuffer_p.h>
end_include
begin_include
include|#
directive|include
file|<qimage.h>
end_include
begin_include
include|#
directive|include
file|<qdebug.h>
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_comment
comment|/* WGL_WGLEXT_PROTOTYPES */
end_comment
begin_typedef
DECL|typedef|PFNWGLGETEXTENSIONSSTRINGARBPROC
typedef|typedef
specifier|const
name|char
modifier|*
function_decl|(
name|WINAPI
modifier|*
name|PFNWGLGETEXTENSIONSSTRINGARBPROC
function_decl|)
parameter_list|(
name|HDC
name|hdc
parameter_list|)
function_decl|;
end_typedef
begin_typedef
DECL|typedef|PFNWGLCREATEPBUFFERARBPROC
typedef|typedef
name|HPBUFFERARB
function_decl|(
name|WINAPI
modifier|*
name|PFNWGLCREATEPBUFFERARBPROC
function_decl|)
parameter_list|(
name|HDC
name|hDC
parameter_list|,
name|int
name|iPixelFormat
parameter_list|,
name|int
name|iWidth
parameter_list|,
name|int
name|iHeight
parameter_list|,
specifier|const
name|int
modifier|*
name|piAttribList
parameter_list|)
function_decl|;
end_typedef
begin_typedef
DECL|typedef|PFNWGLGETPBUFFERDCARBPROC
typedef|typedef
name|HDC
function_decl|(
name|WINAPI
modifier|*
name|PFNWGLGETPBUFFERDCARBPROC
function_decl|)
parameter_list|(
name|HPBUFFERARB
name|hPbuffer
parameter_list|)
function_decl|;
end_typedef
begin_typedef
DECL|typedef|PFNWGLRELEASEPBUFFERDCARBPROC
typedef|typedef
name|int
function_decl|(
name|WINAPI
modifier|*
name|PFNWGLRELEASEPBUFFERDCARBPROC
function_decl|)
parameter_list|(
name|HPBUFFERARB
name|hPbuffer
parameter_list|,
name|HDC
name|hDC
parameter_list|)
function_decl|;
end_typedef
begin_typedef
DECL|typedef|PFNWGLDESTROYPBUFFERARBPROC
typedef|typedef
name|BOOL
function_decl|(
name|WINAPI
modifier|*
name|PFNWGLDESTROYPBUFFERARBPROC
function_decl|)
parameter_list|(
name|HPBUFFERARB
name|hPbuffer
parameter_list|)
function_decl|;
end_typedef
begin_typedef
DECL|typedef|PFNWGLQUERYPBUFFERARBPROC
typedef|typedef
name|BOOL
function_decl|(
name|WINAPI
modifier|*
name|PFNWGLQUERYPBUFFERARBPROC
function_decl|)
parameter_list|(
name|HPBUFFERARB
name|hPbuffer
parameter_list|,
name|int
name|iAttribute
parameter_list|,
name|int
modifier|*
name|piValue
parameter_list|)
function_decl|;
end_typedef
begin_typedef
DECL|typedef|PFNWGLGETPIXELFORMATATTRIBIVARBPROC
typedef|typedef
name|BOOL
function_decl|(
name|WINAPI
modifier|*
name|PFNWGLGETPIXELFORMATATTRIBIVARBPROC
function_decl|)
parameter_list|(
name|HDC
name|hdc
parameter_list|,
name|int
name|iPixelFormat
parameter_list|,
name|int
name|iLayerPlane
parameter_list|,
name|UINT
name|nAttributes
parameter_list|,
specifier|const
name|int
modifier|*
name|piAttributes
parameter_list|,
name|int
modifier|*
name|piValues
parameter_list|)
function_decl|;
end_typedef
begin_typedef
DECL|typedef|PFNWGLGETPIXELFORMATATTRIBFVARBPROC
typedef|typedef
name|BOOL
function_decl|(
name|WINAPI
modifier|*
name|PFNWGLGETPIXELFORMATATTRIBFVARBPROC
function_decl|)
parameter_list|(
name|HDC
name|hdc
parameter_list|,
name|int
name|iPixelFormat
parameter_list|,
name|int
name|iLayerPlane
parameter_list|,
name|UINT
name|nAttributes
parameter_list|,
specifier|const
name|int
modifier|*
name|piAttributes
parameter_list|,
name|FLOAT
modifier|*
name|pfValues
parameter_list|)
function_decl|;
end_typedef
begin_typedef
DECL|typedef|PFNWGLCHOOSEPIXELFORMATARBPROC
typedef|typedef
name|BOOL
function_decl|(
name|WINAPI
modifier|*
name|PFNWGLCHOOSEPIXELFORMATARBPROC
function_decl|)
parameter_list|(
name|HDC
name|hdc
parameter_list|,
specifier|const
name|int
modifier|*
name|piAttribIList
parameter_list|,
specifier|const
name|FLOAT
modifier|*
name|pfAttribFList
parameter_list|,
name|UINT
name|nMaxFormats
parameter_list|,
name|int
modifier|*
name|piFormats
parameter_list|,
name|UINT
modifier|*
name|nNumFormats
parameter_list|)
function_decl|;
end_typedef
begin_typedef
DECL|typedef|PFNWGLBINDTEXIMAGEARBPROC
typedef|typedef
name|BOOL
function_decl|(
name|WINAPI
modifier|*
name|PFNWGLBINDTEXIMAGEARBPROC
function_decl|)
parameter_list|(
name|HPBUFFERARB
name|hPbuffer
parameter_list|,
name|int
name|iBuffer
parameter_list|)
function_decl|;
end_typedef
begin_typedef
DECL|typedef|PFNWGLRELEASETEXIMAGEARBPROC
typedef|typedef
name|BOOL
function_decl|(
name|WINAPI
modifier|*
name|PFNWGLRELEASETEXIMAGEARBPROC
function_decl|)
parameter_list|(
name|HPBUFFERARB
name|hPbuffer
parameter_list|,
name|int
name|iBuffer
parameter_list|)
function_decl|;
end_typedef
begin_typedef
DECL|typedef|PFNWGLSETPBUFFERATTRIBARBPROC
typedef|typedef
name|BOOL
function_decl|(
name|WINAPI
modifier|*
name|PFNWGLSETPBUFFERATTRIBARBPROC
function_decl|)
parameter_list|(
name|HPBUFFERARB
name|hPbuffer
parameter_list|,
specifier|const
name|int
modifier|*
name|piAttribList
parameter_list|)
function_decl|;
end_typedef
begin_ifndef
ifndef|#
directive|ifndef
name|WGL_ARB_pbuffer
end_ifndef
begin_define
DECL|macro|WGL_DRAW_TO_PBUFFER_ARB
define|#
directive|define
name|WGL_DRAW_TO_PBUFFER_ARB
value|0x202D
end_define
begin_define
DECL|macro|WGL_MAX_PBUFFER_PIXELS_ARB
define|#
directive|define
name|WGL_MAX_PBUFFER_PIXELS_ARB
value|0x202E
end_define
begin_define
DECL|macro|WGL_MAX_PBUFFER_WIDTH_ARB
define|#
directive|define
name|WGL_MAX_PBUFFER_WIDTH_ARB
value|0x202F
end_define
begin_define
DECL|macro|WGL_MAX_PBUFFER_HEIGHT_ARB
define|#
directive|define
name|WGL_MAX_PBUFFER_HEIGHT_ARB
value|0x2030
end_define
begin_define
DECL|macro|WGL_PBUFFER_LARGEST_ARB
define|#
directive|define
name|WGL_PBUFFER_LARGEST_ARB
value|0x2033
end_define
begin_define
DECL|macro|WGL_PBUFFER_WIDTH_ARB
define|#
directive|define
name|WGL_PBUFFER_WIDTH_ARB
value|0x2034
end_define
begin_define
DECL|macro|WGL_PBUFFER_HEIGHT_ARB
define|#
directive|define
name|WGL_PBUFFER_HEIGHT_ARB
value|0x2035
end_define
begin_define
DECL|macro|WGL_PBUFFER_LOST_ARB
define|#
directive|define
name|WGL_PBUFFER_LOST_ARB
value|0x2036
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|WGL_ARB_pixel_format
end_ifndef
begin_define
DECL|macro|WGL_NUMBER_PIXEL_FORMATS_ARB
define|#
directive|define
name|WGL_NUMBER_PIXEL_FORMATS_ARB
value|0x2000
end_define
begin_define
DECL|macro|WGL_DRAW_TO_WINDOW_ARB
define|#
directive|define
name|WGL_DRAW_TO_WINDOW_ARB
value|0x2001
end_define
begin_define
DECL|macro|WGL_DRAW_TO_BITMAP_ARB
define|#
directive|define
name|WGL_DRAW_TO_BITMAP_ARB
value|0x2002
end_define
begin_define
DECL|macro|WGL_ACCELERATION_ARB
define|#
directive|define
name|WGL_ACCELERATION_ARB
value|0x2003
end_define
begin_define
DECL|macro|WGL_NEED_PALETTE_ARB
define|#
directive|define
name|WGL_NEED_PALETTE_ARB
value|0x2004
end_define
begin_define
DECL|macro|WGL_NEED_SYSTEM_PALETTE_ARB
define|#
directive|define
name|WGL_NEED_SYSTEM_PALETTE_ARB
value|0x2005
end_define
begin_define
DECL|macro|WGL_SWAP_LAYER_BUFFERS_ARB
define|#
directive|define
name|WGL_SWAP_LAYER_BUFFERS_ARB
value|0x2006
end_define
begin_define
DECL|macro|WGL_SWAP_METHOD_ARB
define|#
directive|define
name|WGL_SWAP_METHOD_ARB
value|0x2007
end_define
begin_define
DECL|macro|WGL_NUMBER_OVERLAYS_ARB
define|#
directive|define
name|WGL_NUMBER_OVERLAYS_ARB
value|0x2008
end_define
begin_define
DECL|macro|WGL_NUMBER_UNDERLAYS_ARB
define|#
directive|define
name|WGL_NUMBER_UNDERLAYS_ARB
value|0x2009
end_define
begin_define
DECL|macro|WGL_TRANSPARENT_ARB
define|#
directive|define
name|WGL_TRANSPARENT_ARB
value|0x200A
end_define
begin_define
DECL|macro|WGL_TRANSPARENT_RED_VALUE_ARB
define|#
directive|define
name|WGL_TRANSPARENT_RED_VALUE_ARB
value|0x2037
end_define
begin_define
DECL|macro|WGL_TRANSPARENT_GREEN_VALUE_ARB
define|#
directive|define
name|WGL_TRANSPARENT_GREEN_VALUE_ARB
value|0x2038
end_define
begin_define
DECL|macro|WGL_TRANSPARENT_BLUE_VALUE_ARB
define|#
directive|define
name|WGL_TRANSPARENT_BLUE_VALUE_ARB
value|0x2039
end_define
begin_define
DECL|macro|WGL_TRANSPARENT_ALPHA_VALUE_ARB
define|#
directive|define
name|WGL_TRANSPARENT_ALPHA_VALUE_ARB
value|0x203A
end_define
begin_define
DECL|macro|WGL_TRANSPARENT_INDEX_VALUE_ARB
define|#
directive|define
name|WGL_TRANSPARENT_INDEX_VALUE_ARB
value|0x203B
end_define
begin_define
DECL|macro|WGL_SHARE_DEPTH_ARB
define|#
directive|define
name|WGL_SHARE_DEPTH_ARB
value|0x200C
end_define
begin_define
DECL|macro|WGL_SHARE_STENCIL_ARB
define|#
directive|define
name|WGL_SHARE_STENCIL_ARB
value|0x200D
end_define
begin_define
DECL|macro|WGL_SHARE_ACCUM_ARB
define|#
directive|define
name|WGL_SHARE_ACCUM_ARB
value|0x200E
end_define
begin_define
DECL|macro|WGL_SUPPORT_GDI_ARB
define|#
directive|define
name|WGL_SUPPORT_GDI_ARB
value|0x200F
end_define
begin_define
DECL|macro|WGL_SUPPORT_OPENGL_ARB
define|#
directive|define
name|WGL_SUPPORT_OPENGL_ARB
value|0x2010
end_define
begin_define
DECL|macro|WGL_DOUBLE_BUFFER_ARB
define|#
directive|define
name|WGL_DOUBLE_BUFFER_ARB
value|0x2011
end_define
begin_define
DECL|macro|WGL_STEREO_ARB
define|#
directive|define
name|WGL_STEREO_ARB
value|0x2012
end_define
begin_define
DECL|macro|WGL_PIXEL_TYPE_ARB
define|#
directive|define
name|WGL_PIXEL_TYPE_ARB
value|0x2013
end_define
begin_define
DECL|macro|WGL_COLOR_BITS_ARB
define|#
directive|define
name|WGL_COLOR_BITS_ARB
value|0x2014
end_define
begin_define
DECL|macro|WGL_RED_BITS_ARB
define|#
directive|define
name|WGL_RED_BITS_ARB
value|0x2015
end_define
begin_define
DECL|macro|WGL_RED_SHIFT_ARB
define|#
directive|define
name|WGL_RED_SHIFT_ARB
value|0x2016
end_define
begin_define
DECL|macro|WGL_GREEN_BITS_ARB
define|#
directive|define
name|WGL_GREEN_BITS_ARB
value|0x2017
end_define
begin_define
DECL|macro|WGL_GREEN_SHIFT_ARB
define|#
directive|define
name|WGL_GREEN_SHIFT_ARB
value|0x2018
end_define
begin_define
DECL|macro|WGL_BLUE_BITS_ARB
define|#
directive|define
name|WGL_BLUE_BITS_ARB
value|0x2019
end_define
begin_define
DECL|macro|WGL_BLUE_SHIFT_ARB
define|#
directive|define
name|WGL_BLUE_SHIFT_ARB
value|0x201A
end_define
begin_define
DECL|macro|WGL_ALPHA_BITS_ARB
define|#
directive|define
name|WGL_ALPHA_BITS_ARB
value|0x201B
end_define
begin_define
DECL|macro|WGL_ALPHA_SHIFT_ARB
define|#
directive|define
name|WGL_ALPHA_SHIFT_ARB
value|0x201C
end_define
begin_define
DECL|macro|WGL_ACCUM_BITS_ARB
define|#
directive|define
name|WGL_ACCUM_BITS_ARB
value|0x201D
end_define
begin_define
DECL|macro|WGL_ACCUM_RED_BITS_ARB
define|#
directive|define
name|WGL_ACCUM_RED_BITS_ARB
value|0x201E
end_define
begin_define
DECL|macro|WGL_ACCUM_GREEN_BITS_ARB
define|#
directive|define
name|WGL_ACCUM_GREEN_BITS_ARB
value|0x201F
end_define
begin_define
DECL|macro|WGL_ACCUM_BLUE_BITS_ARB
define|#
directive|define
name|WGL_ACCUM_BLUE_BITS_ARB
value|0x2020
end_define
begin_define
DECL|macro|WGL_ACCUM_ALPHA_BITS_ARB
define|#
directive|define
name|WGL_ACCUM_ALPHA_BITS_ARB
value|0x2021
end_define
begin_define
DECL|macro|WGL_DEPTH_BITS_ARB
define|#
directive|define
name|WGL_DEPTH_BITS_ARB
value|0x2022
end_define
begin_define
DECL|macro|WGL_STENCIL_BITS_ARB
define|#
directive|define
name|WGL_STENCIL_BITS_ARB
value|0x2023
end_define
begin_define
DECL|macro|WGL_AUX_BUFFERS_ARB
define|#
directive|define
name|WGL_AUX_BUFFERS_ARB
value|0x2024
end_define
begin_define
DECL|macro|WGL_NO_ACCELERATION_ARB
define|#
directive|define
name|WGL_NO_ACCELERATION_ARB
value|0x2025
end_define
begin_define
DECL|macro|WGL_GENERIC_ACCELERATION_ARB
define|#
directive|define
name|WGL_GENERIC_ACCELERATION_ARB
value|0x2026
end_define
begin_define
DECL|macro|WGL_FULL_ACCELERATION_ARB
define|#
directive|define
name|WGL_FULL_ACCELERATION_ARB
value|0x2027
end_define
begin_define
DECL|macro|WGL_SWAP_EXCHANGE_ARB
define|#
directive|define
name|WGL_SWAP_EXCHANGE_ARB
value|0x2028
end_define
begin_define
DECL|macro|WGL_SWAP_COPY_ARB
define|#
directive|define
name|WGL_SWAP_COPY_ARB
value|0x2029
end_define
begin_define
DECL|macro|WGL_SWAP_UNDEFINED_ARB
define|#
directive|define
name|WGL_SWAP_UNDEFINED_ARB
value|0x202A
end_define
begin_define
DECL|macro|WGL_TYPE_RGBA_ARB
define|#
directive|define
name|WGL_TYPE_RGBA_ARB
value|0x202B
end_define
begin_define
DECL|macro|WGL_TYPE_COLORINDEX_ARB
define|#
directive|define
name|WGL_TYPE_COLORINDEX_ARB
value|0x202C
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|WGL_ARB_render_texture
end_ifndef
begin_define
DECL|macro|WGL_BIND_TO_TEXTURE_RGB_ARB
define|#
directive|define
name|WGL_BIND_TO_TEXTURE_RGB_ARB
value|0x2070
end_define
begin_define
DECL|macro|WGL_BIND_TO_TEXTURE_RGBA_ARB
define|#
directive|define
name|WGL_BIND_TO_TEXTURE_RGBA_ARB
value|0x2071
end_define
begin_define
DECL|macro|WGL_TEXTURE_FORMAT_ARB
define|#
directive|define
name|WGL_TEXTURE_FORMAT_ARB
value|0x2072
end_define
begin_define
DECL|macro|WGL_TEXTURE_TARGET_ARB
define|#
directive|define
name|WGL_TEXTURE_TARGET_ARB
value|0x2073
end_define
begin_define
DECL|macro|WGL_MIPMAP_TEXTURE_ARB
define|#
directive|define
name|WGL_MIPMAP_TEXTURE_ARB
value|0x2074
end_define
begin_define
DECL|macro|WGL_TEXTURE_RGB_ARB
define|#
directive|define
name|WGL_TEXTURE_RGB_ARB
value|0x2075
end_define
begin_define
DECL|macro|WGL_TEXTURE_RGBA_ARB
define|#
directive|define
name|WGL_TEXTURE_RGBA_ARB
value|0x2076
end_define
begin_define
DECL|macro|WGL_NO_TEXTURE_ARB
define|#
directive|define
name|WGL_NO_TEXTURE_ARB
value|0x2077
end_define
begin_define
DECL|macro|WGL_TEXTURE_CUBE_MAP_ARB
define|#
directive|define
name|WGL_TEXTURE_CUBE_MAP_ARB
value|0x2078
end_define
begin_define
DECL|macro|WGL_TEXTURE_1D_ARB
define|#
directive|define
name|WGL_TEXTURE_1D_ARB
value|0x2079
end_define
begin_define
DECL|macro|WGL_TEXTURE_2D_ARB
define|#
directive|define
name|WGL_TEXTURE_2D_ARB
value|0x207A
end_define
begin_define
DECL|macro|WGL_MIPMAP_LEVEL_ARB
define|#
directive|define
name|WGL_MIPMAP_LEVEL_ARB
value|0x207B
end_define
begin_define
DECL|macro|WGL_CUBE_MAP_FACE_ARB
define|#
directive|define
name|WGL_CUBE_MAP_FACE_ARB
value|0x207C
end_define
begin_define
DECL|macro|WGL_TEXTURE_CUBE_MAP_POSITIVE_X_ARB
define|#
directive|define
name|WGL_TEXTURE_CUBE_MAP_POSITIVE_X_ARB
value|0x207D
end_define
begin_define
DECL|macro|WGL_TEXTURE_CUBE_MAP_NEGATIVE_X_ARB
define|#
directive|define
name|WGL_TEXTURE_CUBE_MAP_NEGATIVE_X_ARB
value|0x207E
end_define
begin_define
DECL|macro|WGL_TEXTURE_CUBE_MAP_POSITIVE_Y_ARB
define|#
directive|define
name|WGL_TEXTURE_CUBE_MAP_POSITIVE_Y_ARB
value|0x207F
end_define
begin_define
DECL|macro|WGL_TEXTURE_CUBE_MAP_NEGATIVE_Y_ARB
define|#
directive|define
name|WGL_TEXTURE_CUBE_MAP_NEGATIVE_Y_ARB
value|0x2080
end_define
begin_define
DECL|macro|WGL_TEXTURE_CUBE_MAP_POSITIVE_Z_ARB
define|#
directive|define
name|WGL_TEXTURE_CUBE_MAP_POSITIVE_Z_ARB
value|0x2081
end_define
begin_define
DECL|macro|WGL_TEXTURE_CUBE_MAP_NEGATIVE_Z_ARB
define|#
directive|define
name|WGL_TEXTURE_CUBE_MAP_NEGATIVE_Z_ARB
value|0x2082
end_define
begin_define
DECL|macro|WGL_FRONT_LEFT_ARB
define|#
directive|define
name|WGL_FRONT_LEFT_ARB
value|0x2083
end_define
begin_define
DECL|macro|WGL_FRONT_RIGHT_ARB
define|#
directive|define
name|WGL_FRONT_RIGHT_ARB
value|0x2084
end_define
begin_define
DECL|macro|WGL_BACK_LEFT_ARB
define|#
directive|define
name|WGL_BACK_LEFT_ARB
value|0x2085
end_define
begin_define
DECL|macro|WGL_BACK_RIGHT_ARB
define|#
directive|define
name|WGL_BACK_RIGHT_ARB
value|0x2086
end_define
begin_define
DECL|macro|WGL_AUX0_ARB
define|#
directive|define
name|WGL_AUX0_ARB
value|0x2087
end_define
begin_define
DECL|macro|WGL_AUX1_ARB
define|#
directive|define
name|WGL_AUX1_ARB
value|0x2088
end_define
begin_define
DECL|macro|WGL_AUX2_ARB
define|#
directive|define
name|WGL_AUX2_ARB
value|0x2089
end_define
begin_define
DECL|macro|WGL_AUX3_ARB
define|#
directive|define
name|WGL_AUX3_ARB
value|0x208A
end_define
begin_define
DECL|macro|WGL_AUX4_ARB
define|#
directive|define
name|WGL_AUX4_ARB
value|0x208B
end_define
begin_define
DECL|macro|WGL_AUX5_ARB
define|#
directive|define
name|WGL_AUX5_ARB
value|0x208C
end_define
begin_define
DECL|macro|WGL_AUX6_ARB
define|#
directive|define
name|WGL_AUX6_ARB
value|0x208D
end_define
begin_define
DECL|macro|WGL_AUX7_ARB
define|#
directive|define
name|WGL_AUX7_ARB
value|0x208E
end_define
begin_define
DECL|macro|WGL_AUX8_ARB
define|#
directive|define
name|WGL_AUX8_ARB
value|0x208F
end_define
begin_define
DECL|macro|WGL_AUX9_ARB
define|#
directive|define
name|WGL_AUX9_ARB
value|0x2090
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|WGL_FLOAT_COMPONENTS_NV
end_ifndef
begin_define
DECL|macro|WGL_FLOAT_COMPONENTS_NV
define|#
directive|define
name|WGL_FLOAT_COMPONENTS_NV
value|0x20B0
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|WGL_ARB_multisample
end_ifndef
begin_define
DECL|macro|WGL_SAMPLE_BUFFERS_ARB
define|#
directive|define
name|WGL_SAMPLE_BUFFERS_ARB
value|0x2041
end_define
begin_define
DECL|macro|WGL_SAMPLES_ARB
define|#
directive|define
name|WGL_SAMPLES_ARB
value|0x2042
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|GL_SAMPLES_ARB
end_ifndef
begin_define
DECL|macro|GL_SAMPLES_ARB
define|#
directive|define
name|GL_SAMPLES_ARB
value|0x80A9
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_function_decl
name|QGLFormat
name|pfiToQGLFormat
parameter_list|(
name|HDC
name|hdc
parameter_list|,
name|int
name|pfi
parameter_list|)
function_decl|;
end_function_decl
begin_function
DECL|function|qt_format_to_attrib_list
specifier|static
name|void
name|qt_format_to_attrib_list
parameter_list|(
name|bool
name|has_render_texture
parameter_list|,
specifier|const
name|QGLFormat
modifier|&
name|f
parameter_list|,
name|int
name|attribs
index|[]
parameter_list|)
block|{
name|int
name|i
init|=
literal|0
decl_stmt|;
name|attribs
index|[
name|i
operator|++
index|]
operator|=
name|WGL_SUPPORT_OPENGL_ARB
expr_stmt|;
name|attribs
index|[
name|i
operator|++
index|]
operator|=
name|TRUE
expr_stmt|;
name|attribs
index|[
name|i
operator|++
index|]
operator|=
name|WGL_DRAW_TO_PBUFFER_ARB
expr_stmt|;
name|attribs
index|[
name|i
operator|++
index|]
operator|=
name|TRUE
expr_stmt|;
if|if
condition|(
name|has_render_texture
condition|)
block|{
name|attribs
index|[
name|i
operator|++
index|]
operator|=
name|WGL_BIND_TO_TEXTURE_RGBA_ARB
expr_stmt|;
name|attribs
index|[
name|i
operator|++
index|]
operator|=
name|TRUE
expr_stmt|;
block|}
name|attribs
index|[
name|i
operator|++
index|]
operator|=
name|WGL_COLOR_BITS_ARB
expr_stmt|;
name|attribs
index|[
name|i
operator|++
index|]
operator|=
literal|32
expr_stmt|;
name|attribs
index|[
name|i
operator|++
index|]
operator|=
name|WGL_DOUBLE_BUFFER_ARB
expr_stmt|;
name|attribs
index|[
name|i
operator|++
index|]
operator|=
name|FALSE
expr_stmt|;
if|if
condition|(
name|f
operator|.
name|stereo
argument_list|()
condition|)
block|{
name|attribs
index|[
name|i
operator|++
index|]
operator|=
name|WGL_STEREO_ARB
expr_stmt|;
name|attribs
index|[
name|i
operator|++
index|]
operator|=
name|TRUE
expr_stmt|;
block|}
if|if
condition|(
name|f
operator|.
name|depth
argument_list|()
condition|)
block|{
name|attribs
index|[
name|i
operator|++
index|]
operator|=
name|WGL_DEPTH_BITS_ARB
expr_stmt|;
name|attribs
index|[
name|i
operator|++
index|]
operator|=
name|f
operator|.
name|depthBufferSize
argument_list|()
operator|==
operator|-
literal|1
condition|?
literal|24
else|:
name|f
operator|.
name|depthBufferSize
argument_list|()
expr_stmt|;
block|}
if|if
condition|(
name|f
operator|.
name|redBufferSize
argument_list|()
operator|!=
operator|-
literal|1
condition|)
block|{
name|attribs
index|[
name|i
operator|++
index|]
operator|=
name|WGL_RED_BITS_ARB
expr_stmt|;
name|attribs
index|[
name|i
operator|++
index|]
operator|=
name|f
operator|.
name|redBufferSize
argument_list|()
expr_stmt|;
block|}
if|if
condition|(
name|f
operator|.
name|greenBufferSize
argument_list|()
operator|!=
operator|-
literal|1
condition|)
block|{
name|attribs
index|[
name|i
operator|++
index|]
operator|=
name|WGL_GREEN_BITS_ARB
expr_stmt|;
name|attribs
index|[
name|i
operator|++
index|]
operator|=
name|f
operator|.
name|greenBufferSize
argument_list|()
expr_stmt|;
block|}
if|if
condition|(
name|f
operator|.
name|blueBufferSize
argument_list|()
operator|!=
operator|-
literal|1
condition|)
block|{
name|attribs
index|[
name|i
operator|++
index|]
operator|=
name|WGL_BLUE_BITS_ARB
expr_stmt|;
name|attribs
index|[
name|i
operator|++
index|]
operator|=
name|f
operator|.
name|blueBufferSize
argument_list|()
expr_stmt|;
block|}
if|if
condition|(
name|f
operator|.
name|alpha
argument_list|()
condition|)
block|{
name|attribs
index|[
name|i
operator|++
index|]
operator|=
name|WGL_ALPHA_BITS_ARB
expr_stmt|;
name|attribs
index|[
name|i
operator|++
index|]
operator|=
name|f
operator|.
name|alphaBufferSize
argument_list|()
operator|==
operator|-
literal|1
condition|?
literal|8
else|:
name|f
operator|.
name|alphaBufferSize
argument_list|()
expr_stmt|;
block|}
if|if
condition|(
name|f
operator|.
name|accum
argument_list|()
condition|)
block|{
name|attribs
index|[
name|i
operator|++
index|]
operator|=
name|WGL_ACCUM_BITS_ARB
expr_stmt|;
name|attribs
index|[
name|i
operator|++
index|]
operator|=
name|f
operator|.
name|accumBufferSize
argument_list|()
operator|==
operator|-
literal|1
condition|?
literal|16
else|:
name|f
operator|.
name|accumBufferSize
argument_list|()
expr_stmt|;
block|}
if|if
condition|(
name|f
operator|.
name|stencil
argument_list|()
condition|)
block|{
name|attribs
index|[
name|i
operator|++
index|]
operator|=
name|WGL_STENCIL_BITS_ARB
expr_stmt|;
name|attribs
index|[
name|i
operator|++
index|]
operator|=
name|f
operator|.
name|stencilBufferSize
argument_list|()
operator|==
operator|-
literal|1
condition|?
literal|8
else|:
name|f
operator|.
name|stencilBufferSize
argument_list|()
expr_stmt|;
block|}
if|if
condition|(
operator|(
name|f
operator|.
name|redBufferSize
argument_list|()
operator|>
literal|8
operator|||
name|f
operator|.
name|greenBufferSize
argument_list|()
operator|>
literal|8
operator|||
name|f
operator|.
name|blueBufferSize
argument_list|()
operator|>
literal|8
operator|||
name|f
operator|.
name|alphaBufferSize
argument_list|()
operator|>
literal|8
operator|)
operator|&&
operator|(
name|QGLExtensions
operator|::
name|glExtensions
argument_list|()
operator|&
name|QGLExtensions
operator|::
name|NVFloatBuffer
operator|)
condition|)
block|{
name|attribs
index|[
name|i
operator|++
index|]
operator|=
name|WGL_FLOAT_COMPONENTS_NV
expr_stmt|;
name|attribs
index|[
name|i
operator|++
index|]
operator|=
name|TRUE
expr_stmt|;
block|}
if|if
condition|(
name|f
operator|.
name|sampleBuffers
argument_list|()
condition|)
block|{
name|attribs
index|[
name|i
operator|++
index|]
operator|=
name|WGL_SAMPLE_BUFFERS_ARB
expr_stmt|;
name|attribs
index|[
name|i
operator|++
index|]
operator|=
literal|1
expr_stmt|;
name|attribs
index|[
name|i
operator|++
index|]
operator|=
name|WGL_SAMPLES_ARB
expr_stmt|;
name|attribs
index|[
name|i
operator|++
index|]
operator|=
name|f
operator|.
name|samples
argument_list|()
operator|==
operator|-
literal|1
condition|?
literal|16
else|:
name|f
operator|.
name|samples
argument_list|()
expr_stmt|;
block|}
name|attribs
index|[
name|i
index|]
operator|=
literal|0
expr_stmt|;
block|}
end_function
begin_function
DECL|function|init
name|bool
name|QGLPixelBufferPrivate
operator|::
name|init
parameter_list|(
specifier|const
name|QSize
modifier|&
name|size
parameter_list|,
specifier|const
name|QGLFormat
modifier|&
name|f
parameter_list|,
name|QGLWidget
modifier|*
name|shareWidget
parameter_list|)
block|{
name|QGLTemporaryContext
name|tempContext
decl_stmt|;
name|PFNWGLCREATEPBUFFERARBPROC
name|wglCreatePbufferARB
init|=
operator|(
name|PFNWGLCREATEPBUFFERARBPROC
operator|)
name|wglGetProcAddress
argument_list|(
literal|"wglCreatePbufferARB"
argument_list|)
decl_stmt|;
name|PFNWGLGETPBUFFERDCARBPROC
name|wglGetPbufferDCARB
init|=
operator|(
name|PFNWGLGETPBUFFERDCARBPROC
operator|)
name|wglGetProcAddress
argument_list|(
literal|"wglGetPbufferDCARB"
argument_list|)
decl_stmt|;
name|PFNWGLQUERYPBUFFERARBPROC
name|wglQueryPbufferARB
init|=
operator|(
name|PFNWGLQUERYPBUFFERARBPROC
operator|)
name|wglGetProcAddress
argument_list|(
literal|"wglQueryPbufferARB"
argument_list|)
decl_stmt|;
name|PFNWGLCHOOSEPIXELFORMATARBPROC
name|wglChoosePixelFormatARB
init|=
operator|(
name|PFNWGLCHOOSEPIXELFORMATARBPROC
operator|)
name|wglGetProcAddress
argument_list|(
literal|"wglChoosePixelFormatARB"
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|wglCreatePbufferARB
condition|)
comment|// assumes that if one can be resolved, all of them can
return|return
literal|false
return|;
name|dc
operator|=
name|wglGetCurrentDC
argument_list|()
expr_stmt|;
name|Q_ASSERT
argument_list|(
name|dc
argument_list|)
expr_stmt|;
name|has_render_texture
operator|=
literal|false
expr_stmt|;
comment|// sample buffers doesn't work in conjunction with the render_texture extension
if|if
condition|(
operator|!
name|f
operator|.
name|sampleBuffers
argument_list|()
condition|)
block|{
name|PFNWGLGETEXTENSIONSSTRINGARBPROC
name|wglGetExtensionsStringARB
init|=
operator|(
name|PFNWGLGETEXTENSIONSSTRINGARBPROC
operator|)
name|wglGetProcAddress
argument_list|(
literal|"wglGetExtensionsStringARB"
argument_list|)
decl_stmt|;
if|if
condition|(
name|wglGetExtensionsStringARB
condition|)
block|{
name|QString
name|extensions
argument_list|(
name|QLatin1String
argument_list|(
name|wglGetExtensionsStringARB
argument_list|(
name|dc
argument_list|)
argument_list|)
argument_list|)
decl_stmt|;
name|has_render_texture
operator|=
name|extensions
operator|.
name|contains
argument_list|(
name|QLatin1String
argument_list|(
literal|"WGL_ARB_render_texture"
argument_list|)
argument_list|)
expr_stmt|;
block|}
block|}
name|int
name|attribs
index|[
literal|40
index|]
decl_stmt|;
name|qt_format_to_attrib_list
argument_list|(
name|has_render_texture
argument_list|,
name|f
argument_list|,
name|attribs
argument_list|)
expr_stmt|;
comment|// Find pbuffer capable pixel format.
name|unsigned
name|int
name|num_formats
init|=
literal|0
decl_stmt|;
name|int
name|pixel_format
decl_stmt|;
name|wglChoosePixelFormatARB
argument_list|(
name|dc
argument_list|,
name|attribs
argument_list|,
literal|0
argument_list|,
literal|1
argument_list|,
operator|&
name|pixel_format
argument_list|,
operator|&
name|num_formats
argument_list|)
expr_stmt|;
comment|// some GL implementations don't support pbuffers with accum
comment|// buffers, so try that before we give up
if|if
condition|(
name|num_formats
operator|==
literal|0
operator|&&
name|f
operator|.
name|accum
argument_list|()
condition|)
block|{
name|QGLFormat
name|tmp
init|=
name|f
decl_stmt|;
name|tmp
operator|.
name|setAccum
argument_list|(
literal|false
argument_list|)
expr_stmt|;
name|qt_format_to_attrib_list
argument_list|(
name|has_render_texture
argument_list|,
name|tmp
argument_list|,
name|attribs
argument_list|)
expr_stmt|;
name|wglChoosePixelFormatARB
argument_list|(
name|dc
argument_list|,
name|attribs
argument_list|,
literal|0
argument_list|,
literal|1
argument_list|,
operator|&
name|pixel_format
argument_list|,
operator|&
name|num_formats
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|num_formats
operator|==
literal|0
condition|)
block|{
name|qWarning
argument_list|(
literal|"QGLPixelBuffer: Unable to find a pixel format with pbuffer  - giving up."
argument_list|)
expr_stmt|;
return|return
literal|false
return|;
block|}
name|format
operator|=
name|pfiToQGLFormat
argument_list|(
name|dc
argument_list|,
name|pixel_format
argument_list|)
expr_stmt|;
comment|// NB! The below ONLY works if the width/height are powers of 2.
comment|// Set some pBuffer attributes so that we can use this pBuffer as
comment|// a 2D RGBA texture target.
name|int
name|pb_attribs
index|[]
init|=
block|{
name|WGL_TEXTURE_FORMAT_ARB
block|,
name|WGL_TEXTURE_RGBA_ARB
block|,
name|WGL_TEXTURE_TARGET_ARB
block|,
name|WGL_TEXTURE_2D_ARB
block|,
literal|0
block|}
decl_stmt|;
name|pbuf
operator|=
name|wglCreatePbufferARB
argument_list|(
name|dc
argument_list|,
name|pixel_format
argument_list|,
name|size
operator|.
name|width
argument_list|()
argument_list|,
name|size
operator|.
name|height
argument_list|()
argument_list|,
name|has_render_texture
condition|?
name|pb_attribs
else|:
literal|0
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|pbuf
condition|)
block|{
comment|// try again without the render_texture extension
name|pbuf
operator|=
name|wglCreatePbufferARB
argument_list|(
name|dc
argument_list|,
name|pixel_format
argument_list|,
name|size
operator|.
name|width
argument_list|()
argument_list|,
name|size
operator|.
name|height
argument_list|()
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|has_render_texture
operator|=
literal|false
expr_stmt|;
if|if
condition|(
operator|!
name|pbuf
condition|)
block|{
name|qWarning
argument_list|(
literal|"QGLPixelBuffer: Unable to create pbuffer [w=%d, h=%d] - giving up."
argument_list|,
name|size
operator|.
name|width
argument_list|()
argument_list|,
name|size
operator|.
name|height
argument_list|()
argument_list|)
expr_stmt|;
return|return
literal|false
return|;
block|}
block|}
name|dc
operator|=
name|wglGetPbufferDCARB
argument_list|(
name|pbuf
argument_list|)
expr_stmt|;
name|ctx
operator|=
name|wglCreateContext
argument_list|(
name|dc
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|dc
operator|||
operator|!
name|ctx
condition|)
block|{
name|qWarning
argument_list|(
literal|"QGLPixelBuffer: Unable to create pbuffer context - giving up."
argument_list|)
expr_stmt|;
return|return
literal|false
return|;
block|}
comment|// Explicitly disable the render_texture extension if we have a
comment|// multi-sampled pbuffer context. This seems to be a problem only with
comment|// ATI cards if multi-sampling is forced globally in the driver.
name|wglMakeCurrent
argument_list|(
name|dc
argument_list|,
name|ctx
argument_list|)
expr_stmt|;
name|GLint
name|samples
init|=
literal|0
decl_stmt|;
name|glGetIntegerv
argument_list|(
name|GL_SAMPLES_ARB
argument_list|,
operator|&
name|samples
argument_list|)
expr_stmt|;
if|if
condition|(
name|has_render_texture
operator|&&
name|samples
operator|!=
literal|0
condition|)
name|has_render_texture
operator|=
literal|false
expr_stmt|;
name|HGLRC
name|share_ctx
init|=
name|shareWidget
condition|?
name|shareWidget
operator|->
name|d_func
argument_list|()
operator|->
name|glcx
operator|->
name|d_func
argument_list|()
operator|->
name|rc
else|:
literal|0
decl_stmt|;
if|if
condition|(
name|share_ctx
operator|&&
operator|!
name|wglShareLists
argument_list|(
name|share_ctx
argument_list|,
name|ctx
argument_list|)
condition|)
name|qWarning
argument_list|(
literal|"QGLPixelBuffer: Unable to share display lists - with share widget."
argument_list|)
expr_stmt|;
name|int
name|width
decl_stmt|,
name|height
decl_stmt|;
name|wglQueryPbufferARB
argument_list|(
name|pbuf
argument_list|,
name|WGL_PBUFFER_WIDTH_ARB
argument_list|,
operator|&
name|width
argument_list|)
expr_stmt|;
name|wglQueryPbufferARB
argument_list|(
name|pbuf
argument_list|,
name|WGL_PBUFFER_HEIGHT_ARB
argument_list|,
operator|&
name|height
argument_list|)
expr_stmt|;
return|return
literal|true
return|;
block|}
end_function
begin_function
DECL|function|cleanup
name|bool
name|QGLPixelBufferPrivate
operator|::
name|cleanup
parameter_list|()
block|{
name|PFNWGLRELEASEPBUFFERDCARBPROC
name|wglReleasePbufferDCARB
init|=
operator|(
name|PFNWGLRELEASEPBUFFERDCARBPROC
operator|)
name|wglGetProcAddress
argument_list|(
literal|"wglReleasePbufferDCARB"
argument_list|)
decl_stmt|;
name|PFNWGLDESTROYPBUFFERARBPROC
name|wglDestroyPbufferARB
init|=
operator|(
name|PFNWGLDESTROYPBUFFERARBPROC
operator|)
name|wglGetProcAddress
argument_list|(
literal|"wglDestroyPbufferARB"
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|invalid
operator|&&
name|wglReleasePbufferDCARB
operator|&&
name|wglDestroyPbufferARB
condition|)
block|{
name|wglReleasePbufferDCARB
argument_list|(
name|pbuf
argument_list|,
name|dc
argument_list|)
expr_stmt|;
name|wglDestroyPbufferARB
argument_list|(
name|pbuf
argument_list|)
expr_stmt|;
block|}
return|return
literal|true
return|;
block|}
end_function
begin_function
DECL|function|bindToDynamicTexture
name|bool
name|QGLPixelBuffer
operator|::
name|bindToDynamicTexture
parameter_list|(
name|GLuint
name|texture_id
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QGLPixelBuffer
argument_list|)
expr_stmt|;
if|if
condition|(
name|d
operator|->
name|invalid
operator|||
operator|!
name|d
operator|->
name|has_render_texture
condition|)
return|return
literal|false
return|;
name|PFNWGLBINDTEXIMAGEARBPROC
name|wglBindTexImageARB
init|=
operator|(
name|PFNWGLBINDTEXIMAGEARBPROC
operator|)
name|wglGetProcAddress
argument_list|(
literal|"wglBindTexImageARB"
argument_list|)
decl_stmt|;
if|if
condition|(
name|wglBindTexImageARB
condition|)
block|{
name|glBindTexture
argument_list|(
name|GL_TEXTURE_2D
argument_list|,
name|texture_id
argument_list|)
expr_stmt|;
return|return
name|wglBindTexImageARB
argument_list|(
name|d
operator|->
name|pbuf
argument_list|,
name|WGL_FRONT_LEFT_ARB
argument_list|)
return|;
block|}
return|return
literal|false
return|;
block|}
end_function
begin_function
DECL|function|releaseFromDynamicTexture
name|void
name|QGLPixelBuffer
operator|::
name|releaseFromDynamicTexture
parameter_list|()
block|{
name|Q_D
argument_list|(
name|QGLPixelBuffer
argument_list|)
expr_stmt|;
if|if
condition|(
name|d
operator|->
name|invalid
operator|||
operator|!
name|d
operator|->
name|has_render_texture
condition|)
return|return;
name|PFNWGLRELEASETEXIMAGEARBPROC
name|wglReleaseTexImageARB
init|=
operator|(
name|PFNWGLRELEASETEXIMAGEARBPROC
operator|)
name|wglGetProcAddress
argument_list|(
literal|"wglReleaseTexImageARB"
argument_list|)
decl_stmt|;
if|if
condition|(
name|wglReleaseTexImageARB
condition|)
name|wglReleaseTexImageARB
argument_list|(
name|d
operator|->
name|pbuf
argument_list|,
name|WGL_FRONT_LEFT_ARB
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|hasOpenGLPbuffers
name|bool
name|QGLPixelBuffer
operator|::
name|hasOpenGLPbuffers
parameter_list|()
block|{
name|bool
name|ret
init|=
literal|false
decl_stmt|;
name|QGLTemporaryContext
modifier|*
name|tmpContext
init|=
literal|0
decl_stmt|;
if|if
condition|(
operator|!
name|QGLContext
operator|::
name|currentContext
argument_list|()
condition|)
name|tmpContext
operator|=
operator|new
name|QGLTemporaryContext
expr_stmt|;
name|PFNWGLGETEXTENSIONSSTRINGARBPROC
name|wglGetExtensionsStringARB
init|=
operator|(
name|PFNWGLGETEXTENSIONSSTRINGARBPROC
operator|)
name|wglGetProcAddress
argument_list|(
literal|"wglGetExtensionsStringARB"
argument_list|)
decl_stmt|;
if|if
condition|(
name|wglGetExtensionsStringARB
condition|)
block|{
name|QString
name|extensions
argument_list|(
name|QLatin1String
argument_list|(
name|wglGetExtensionsStringARB
argument_list|(
name|wglGetCurrentDC
argument_list|()
argument_list|)
argument_list|)
argument_list|)
decl_stmt|;
if|if
condition|(
name|extensions
operator|.
name|contains
argument_list|(
name|QLatin1String
argument_list|(
literal|"WGL_ARB_pbuffer"
argument_list|)
argument_list|)
operator|&&
name|extensions
operator|.
name|contains
argument_list|(
name|QLatin1String
argument_list|(
literal|"WGL_ARB_pixel_format"
argument_list|)
argument_list|)
condition|)
block|{
name|ret
operator|=
literal|true
expr_stmt|;
block|}
block|}
if|if
condition|(
name|tmpContext
condition|)
operator|delete
name|tmpContext
expr_stmt|;
return|return
name|ret
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
