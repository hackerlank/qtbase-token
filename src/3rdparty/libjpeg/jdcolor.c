begin_unit
begin_comment
comment|/*  * jdcolor.c  *  * Copyright (C) 1991-1997, Thomas G. Lane.  * This file is part of the Independent JPEG Group's software.  * For conditions of distribution and use, see the accompanying README file.  *  * This file contains output colorspace conversion routines.  */
end_comment
begin_define
DECL|macro|JPEG_INTERNALS
define|#
directive|define
name|JPEG_INTERNALS
end_define
begin_include
include|#
directive|include
file|"jinclude.h"
end_include
begin_include
include|#
directive|include
file|"jpeglib.h"
end_include
begin_comment
comment|/* Private subobject */
end_comment
begin_typedef
typedef|typedef
struct|struct
block|{
DECL|member|pub
name|struct
name|jpeg_color_deconverter
name|pub
decl_stmt|;
comment|/* public fields */
comment|/* Private state for YCC->RGB conversion */
DECL|member|Cr_r_tab
name|int
modifier|*
name|Cr_r_tab
decl_stmt|;
comment|/* => table for Cr to R conversion */
DECL|member|Cb_b_tab
name|int
modifier|*
name|Cb_b_tab
decl_stmt|;
comment|/* => table for Cb to B conversion */
DECL|member|Cr_g_tab
name|INT32
modifier|*
name|Cr_g_tab
decl_stmt|;
comment|/* => table for Cr to G conversion */
DECL|member|Cb_g_tab
name|INT32
modifier|*
name|Cb_g_tab
decl_stmt|;
comment|/* => table for Cb to G conversion */
block|}
DECL|typedef|my_color_deconverter
name|my_color_deconverter
typedef|;
end_typedef
begin_typedef
DECL|typedef|my_cconvert_ptr
typedef|typedef
name|my_color_deconverter
modifier|*
name|my_cconvert_ptr
typedef|;
end_typedef
begin_comment
comment|/**************** YCbCr -> RGB conversion: most common case **************/
end_comment
begin_comment
comment|/*  * YCbCr is defined per CCIR 601-1, except that Cb and Cr are  * normalized to the range 0..MAXJSAMPLE rather than -0.5 .. 0.5.  * The conversion equations to be implemented are therefore  *	R = Y                + 1.40200 * Cr  *	G = Y - 0.34414 * Cb - 0.71414 * Cr  *	B = Y + 1.77200 * Cb  * where Cb and Cr represent the incoming values less CENTERJSAMPLE.  * (These numbers are derived from TIFF 6.0 section 21, dated 3-June-92.)  *  * To avoid floating-point arithmetic, we represent the fractional constants  * as integers scaled up by 2^16 (about 4 digits precision); we have to divide  * the products by 2^16, with appropriate rounding, to get the correct answer.  * Notice that Y, being an integral input, does not contribute any fraction  * so it need not participate in the rounding.  *  * For even more speed, we avoid doing any multiplications in the inner loop  * by precalculating the constants times Cb and Cr for all possible values.  * For 8-bit JSAMPLEs this is very reasonable (only 256 entries per table);  * for 12-bit samples it is still acceptable.  It's not very reasonable for  * 16-bit samples, but if you want lossless storage you shouldn't be changing  * colorspace anyway.  * The Cr=>R and Cb=>B values can be rounded to integers in advance; the  * values for the G calculation are left scaled up, since we must add them  * together before rounding.  */
end_comment
begin_define
DECL|macro|SCALEBITS
define|#
directive|define
name|SCALEBITS
value|16
end_define
begin_comment
DECL|macro|SCALEBITS
comment|/* speediest right-shift on some machines */
end_comment
begin_define
DECL|macro|ONE_HALF
define|#
directive|define
name|ONE_HALF
value|((INT32) 1<< (SCALEBITS-1))
end_define
begin_define
DECL|macro|FIX
define|#
directive|define
name|FIX
parameter_list|(
name|x
parameter_list|)
value|((INT32) ((x) * (1L<<SCALEBITS) + 0.5))
end_define
begin_comment
comment|/*  * Initialize tables for YCC->RGB colorspace conversion.  */
end_comment
begin_macro
name|LOCAL
argument_list|(
argument|void
argument_list|)
end_macro
begin_macro
DECL|function|build_ycc_rgb_table
name|build_ycc_rgb_table
argument_list|(
argument|j_decompress_ptr cinfo
argument_list|)
end_macro
begin_block
block|{
name|my_cconvert_ptr
name|cconvert
init|=
operator|(
name|my_cconvert_ptr
operator|)
name|cinfo
operator|->
name|cconvert
decl_stmt|;
name|int
name|i
decl_stmt|;
name|INT32
name|x
decl_stmt|;
name|SHIFT_TEMPS
name|cconvert
operator|->
name|Cr_r_tab
init|=
operator|(
name|int
operator|*
operator|)
call|(
modifier|*
name|cinfo
operator|->
name|mem
operator|->
name|alloc_small
call|)
argument_list|(
operator|(
name|j_common_ptr
operator|)
name|cinfo
argument_list|,
name|JPOOL_IMAGE
argument_list|,
operator|(
name|MAXJSAMPLE
operator|+
literal|1
operator|)
operator|*
name|SIZEOF
argument_list|(
name|int
argument_list|)
argument_list|)
decl_stmt|;
name|cconvert
operator|->
name|Cb_b_tab
operator|=
operator|(
name|int
operator|*
operator|)
call|(
modifier|*
name|cinfo
operator|->
name|mem
operator|->
name|alloc_small
call|)
argument_list|(
operator|(
name|j_common_ptr
operator|)
name|cinfo
argument_list|,
name|JPOOL_IMAGE
argument_list|,
operator|(
name|MAXJSAMPLE
operator|+
literal|1
operator|)
operator|*
name|SIZEOF
argument_list|(
name|int
argument_list|)
argument_list|)
expr_stmt|;
name|cconvert
operator|->
name|Cr_g_tab
operator|=
operator|(
name|INT32
operator|*
operator|)
call|(
modifier|*
name|cinfo
operator|->
name|mem
operator|->
name|alloc_small
call|)
argument_list|(
operator|(
name|j_common_ptr
operator|)
name|cinfo
argument_list|,
name|JPOOL_IMAGE
argument_list|,
operator|(
name|MAXJSAMPLE
operator|+
literal|1
operator|)
operator|*
name|SIZEOF
argument_list|(
name|INT32
argument_list|)
argument_list|)
expr_stmt|;
name|cconvert
operator|->
name|Cb_g_tab
operator|=
operator|(
name|INT32
operator|*
operator|)
call|(
modifier|*
name|cinfo
operator|->
name|mem
operator|->
name|alloc_small
call|)
argument_list|(
operator|(
name|j_common_ptr
operator|)
name|cinfo
argument_list|,
name|JPOOL_IMAGE
argument_list|,
operator|(
name|MAXJSAMPLE
operator|+
literal|1
operator|)
operator|*
name|SIZEOF
argument_list|(
name|INT32
argument_list|)
argument_list|)
expr_stmt|;
for|for
control|(
name|i
operator|=
literal|0
operator|,
name|x
operator|=
operator|-
name|CENTERJSAMPLE
init|;
name|i
operator|<=
name|MAXJSAMPLE
condition|;
name|i
operator|++
operator|,
name|x
operator|++
control|)
block|{
comment|/* i is the actual input pixel value, in the range 0..MAXJSAMPLE */
comment|/* The Cb or Cr value we are thinking of is x = i - CENTERJSAMPLE */
comment|/* Cr=>R value is nearest int to 1.40200 * x */
name|cconvert
operator|->
name|Cr_r_tab
index|[
name|i
index|]
operator|=
operator|(
name|int
operator|)
name|RIGHT_SHIFT
argument_list|(
name|FIX
argument_list|(
literal|1.40200
argument_list|)
operator|*
name|x
operator|+
name|ONE_HALF
argument_list|,
name|SCALEBITS
argument_list|)
expr_stmt|;
comment|/* Cb=>B value is nearest int to 1.77200 * x */
name|cconvert
operator|->
name|Cb_b_tab
index|[
name|i
index|]
operator|=
operator|(
name|int
operator|)
name|RIGHT_SHIFT
argument_list|(
name|FIX
argument_list|(
literal|1.77200
argument_list|)
operator|*
name|x
operator|+
name|ONE_HALF
argument_list|,
name|SCALEBITS
argument_list|)
expr_stmt|;
comment|/* Cr=>G value is scaled-up -0.71414 * x */
name|cconvert
operator|->
name|Cr_g_tab
index|[
name|i
index|]
operator|=
operator|(
operator|-
name|FIX
argument_list|(
literal|0.71414
argument_list|)
operator|)
operator|*
name|x
expr_stmt|;
comment|/* Cb=>G value is scaled-up -0.34414 * x */
comment|/* We also add in ONE_HALF so that need not do it in inner loop */
name|cconvert
operator|->
name|Cb_g_tab
index|[
name|i
index|]
operator|=
operator|(
operator|-
name|FIX
argument_list|(
literal|0.34414
argument_list|)
operator|)
operator|*
name|x
operator|+
name|ONE_HALF
expr_stmt|;
block|}
block|}
end_block
begin_comment
comment|/*  * Convert some rows of samples to the output colorspace.  *  * Note that we change from noninterleaved, one-plane-per-component format  * to interleaved-pixel format.  The output buffer is therefore three times  * as wide as the input buffer.  * A starting row offset is provided only for the input buffer.  The caller  * can easily adjust the passed output_buf value to accommodate any row  * offset required on that side.  */
end_comment
begin_macro
name|METHODDEF
argument_list|(
argument|void
argument_list|)
end_macro
begin_macro
DECL|function|ycc_rgb_convert
name|ycc_rgb_convert
argument_list|(
argument|j_decompress_ptr cinfo
argument_list|,
argument|JSAMPIMAGE input_buf
argument_list|,
argument|JDIMENSION input_row
argument_list|,
argument|JSAMPARRAY output_buf
argument_list|,
argument|int num_rows
argument_list|)
end_macro
begin_block
block|{
name|my_cconvert_ptr
name|cconvert
init|=
operator|(
name|my_cconvert_ptr
operator|)
name|cinfo
operator|->
name|cconvert
decl_stmt|;
specifier|register
name|int
name|y
decl_stmt|,
name|cb
decl_stmt|,
name|cr
decl_stmt|;
specifier|register
name|JSAMPROW
name|outptr
decl_stmt|;
specifier|register
name|JSAMPROW
name|inptr0
decl_stmt|,
name|inptr1
decl_stmt|,
name|inptr2
decl_stmt|;
specifier|register
name|JDIMENSION
name|col
decl_stmt|;
name|JDIMENSION
name|num_cols
init|=
name|cinfo
operator|->
name|output_width
decl_stmt|;
comment|/* copy these pointers into registers if possible */
specifier|register
name|JSAMPLE
modifier|*
name|range_limit
init|=
name|cinfo
operator|->
name|sample_range_limit
decl_stmt|;
specifier|register
name|int
modifier|*
name|Crrtab
init|=
name|cconvert
operator|->
name|Cr_r_tab
decl_stmt|;
specifier|register
name|int
modifier|*
name|Cbbtab
init|=
name|cconvert
operator|->
name|Cb_b_tab
decl_stmt|;
specifier|register
name|INT32
modifier|*
name|Crgtab
init|=
name|cconvert
operator|->
name|Cr_g_tab
decl_stmt|;
specifier|register
name|INT32
modifier|*
name|Cbgtab
init|=
name|cconvert
operator|->
name|Cb_g_tab
decl_stmt|;
name|SHIFT_TEMPS
while|while
condition|(
operator|--
name|num_rows
operator|>=
literal|0
condition|)
block|{
name|inptr0
operator|=
name|input_buf
index|[
literal|0
index|]
index|[
name|input_row
index|]
expr_stmt|;
name|inptr1
operator|=
name|input_buf
index|[
literal|1
index|]
index|[
name|input_row
index|]
expr_stmt|;
name|inptr2
operator|=
name|input_buf
index|[
literal|2
index|]
index|[
name|input_row
index|]
expr_stmt|;
name|input_row
operator|++
expr_stmt|;
name|outptr
operator|=
operator|*
name|output_buf
operator|++
expr_stmt|;
for|for
control|(
name|col
operator|=
literal|0
init|;
name|col
operator|<
name|num_cols
condition|;
name|col
operator|++
control|)
block|{
name|y
operator|=
name|GETJSAMPLE
argument_list|(
name|inptr0
index|[
name|col
index|]
argument_list|)
expr_stmt|;
name|cb
operator|=
name|GETJSAMPLE
argument_list|(
name|inptr1
index|[
name|col
index|]
argument_list|)
expr_stmt|;
name|cr
operator|=
name|GETJSAMPLE
argument_list|(
name|inptr2
index|[
name|col
index|]
argument_list|)
expr_stmt|;
comment|/* Range-limiting is essential due to noise introduced by DCT losses. */
name|outptr
index|[
name|RGB_RED
index|]
operator|=
name|range_limit
index|[
name|y
operator|+
name|Crrtab
index|[
name|cr
index|]
index|]
expr_stmt|;
name|outptr
index|[
name|RGB_GREEN
index|]
operator|=
name|range_limit
index|[
name|y
operator|+
operator|(
operator|(
name|int
operator|)
name|RIGHT_SHIFT
argument_list|(
name|Cbgtab
index|[
name|cb
index|]
operator|+
name|Crgtab
index|[
name|cr
index|]
argument_list|,
name|SCALEBITS
argument_list|)
operator|)
index|]
expr_stmt|;
name|outptr
index|[
name|RGB_BLUE
index|]
operator|=
name|range_limit
index|[
name|y
operator|+
name|Cbbtab
index|[
name|cb
index|]
index|]
expr_stmt|;
name|outptr
operator|+=
name|RGB_PIXELSIZE
expr_stmt|;
block|}
block|}
block|}
end_block
begin_comment
comment|/**************** Cases other than YCbCr -> RGB **************/
end_comment
begin_comment
comment|/*  * Color conversion for no colorspace change: just copy the data,  * converting from separate-planes to interleaved representation.  */
end_comment
begin_macro
name|METHODDEF
argument_list|(
argument|void
argument_list|)
end_macro
begin_macro
DECL|function|null_convert
name|null_convert
argument_list|(
argument|j_decompress_ptr cinfo
argument_list|,
argument|JSAMPIMAGE input_buf
argument_list|,
argument|JDIMENSION input_row
argument_list|,
argument|JSAMPARRAY output_buf
argument_list|,
argument|int num_rows
argument_list|)
end_macro
begin_block
block|{
specifier|register
name|JSAMPROW
name|inptr
decl_stmt|,
name|outptr
decl_stmt|;
specifier|register
name|JDIMENSION
name|count
decl_stmt|;
specifier|register
name|int
name|num_components
init|=
name|cinfo
operator|->
name|num_components
decl_stmt|;
name|JDIMENSION
name|num_cols
init|=
name|cinfo
operator|->
name|output_width
decl_stmt|;
name|int
name|ci
decl_stmt|;
while|while
condition|(
operator|--
name|num_rows
operator|>=
literal|0
condition|)
block|{
for|for
control|(
name|ci
operator|=
literal|0
init|;
name|ci
operator|<
name|num_components
condition|;
name|ci
operator|++
control|)
block|{
name|inptr
operator|=
name|input_buf
index|[
name|ci
index|]
index|[
name|input_row
index|]
expr_stmt|;
name|outptr
operator|=
name|output_buf
index|[
literal|0
index|]
operator|+
name|ci
expr_stmt|;
for|for
control|(
name|count
operator|=
name|num_cols
init|;
name|count
operator|>
literal|0
condition|;
name|count
operator|--
control|)
block|{
operator|*
name|outptr
operator|=
operator|*
name|inptr
operator|++
expr_stmt|;
comment|/* needn't bother with GETJSAMPLE() here */
name|outptr
operator|+=
name|num_components
expr_stmt|;
block|}
block|}
name|input_row
operator|++
expr_stmt|;
name|output_buf
operator|++
expr_stmt|;
block|}
block|}
end_block
begin_comment
comment|/*  * Color conversion for grayscale: just copy the data.  * This also works for YCbCr -> grayscale conversion, in which  * we just copy the Y (luminance) component and ignore chrominance.  */
end_comment
begin_macro
name|METHODDEF
argument_list|(
argument|void
argument_list|)
end_macro
begin_macro
DECL|function|grayscale_convert
name|grayscale_convert
argument_list|(
argument|j_decompress_ptr cinfo
argument_list|,
argument|JSAMPIMAGE input_buf
argument_list|,
argument|JDIMENSION input_row
argument_list|,
argument|JSAMPARRAY output_buf
argument_list|,
argument|int num_rows
argument_list|)
end_macro
begin_block
block|{
name|jcopy_sample_rows
argument_list|(
name|input_buf
index|[
literal|0
index|]
argument_list|,
operator|(
name|int
operator|)
name|input_row
argument_list|,
name|output_buf
argument_list|,
literal|0
argument_list|,
name|num_rows
argument_list|,
name|cinfo
operator|->
name|output_width
argument_list|)
expr_stmt|;
block|}
end_block
begin_comment
comment|/*  * Convert grayscale to RGB: just duplicate the graylevel three times.  * This is provided to support applications that don't want to cope  * with grayscale as a separate case.  */
end_comment
begin_macro
name|METHODDEF
argument_list|(
argument|void
argument_list|)
end_macro
begin_macro
DECL|function|gray_rgb_convert
name|gray_rgb_convert
argument_list|(
argument|j_decompress_ptr cinfo
argument_list|,
argument|JSAMPIMAGE input_buf
argument_list|,
argument|JDIMENSION input_row
argument_list|,
argument|JSAMPARRAY output_buf
argument_list|,
argument|int num_rows
argument_list|)
end_macro
begin_block
block|{
specifier|register
name|JSAMPROW
name|inptr
decl_stmt|,
name|outptr
decl_stmt|;
specifier|register
name|JDIMENSION
name|col
decl_stmt|;
name|JDIMENSION
name|num_cols
init|=
name|cinfo
operator|->
name|output_width
decl_stmt|;
while|while
condition|(
operator|--
name|num_rows
operator|>=
literal|0
condition|)
block|{
name|inptr
operator|=
name|input_buf
index|[
literal|0
index|]
index|[
name|input_row
operator|++
index|]
expr_stmt|;
name|outptr
operator|=
operator|*
name|output_buf
operator|++
expr_stmt|;
for|for
control|(
name|col
operator|=
literal|0
init|;
name|col
operator|<
name|num_cols
condition|;
name|col
operator|++
control|)
block|{
comment|/* We can dispense with GETJSAMPLE() here */
name|outptr
index|[
name|RGB_RED
index|]
operator|=
name|outptr
index|[
name|RGB_GREEN
index|]
operator|=
name|outptr
index|[
name|RGB_BLUE
index|]
operator|=
name|inptr
index|[
name|col
index|]
expr_stmt|;
name|outptr
operator|+=
name|RGB_PIXELSIZE
expr_stmt|;
block|}
block|}
block|}
end_block
begin_comment
comment|/*  * Adobe-style YCCK->CMYK conversion.  * We convert YCbCr to R=1-C, G=1-M, and B=1-Y using the same  * conversion as above, while passing K (black) unchanged.  * We assume build_ycc_rgb_table has been called.  */
end_comment
begin_macro
name|METHODDEF
argument_list|(
argument|void
argument_list|)
end_macro
begin_macro
DECL|function|ycck_cmyk_convert
name|ycck_cmyk_convert
argument_list|(
argument|j_decompress_ptr cinfo
argument_list|,
argument|JSAMPIMAGE input_buf
argument_list|,
argument|JDIMENSION input_row
argument_list|,
argument|JSAMPARRAY output_buf
argument_list|,
argument|int num_rows
argument_list|)
end_macro
begin_block
block|{
name|my_cconvert_ptr
name|cconvert
init|=
operator|(
name|my_cconvert_ptr
operator|)
name|cinfo
operator|->
name|cconvert
decl_stmt|;
specifier|register
name|int
name|y
decl_stmt|,
name|cb
decl_stmt|,
name|cr
decl_stmt|;
specifier|register
name|JSAMPROW
name|outptr
decl_stmt|;
specifier|register
name|JSAMPROW
name|inptr0
decl_stmt|,
name|inptr1
decl_stmt|,
name|inptr2
decl_stmt|,
name|inptr3
decl_stmt|;
specifier|register
name|JDIMENSION
name|col
decl_stmt|;
name|JDIMENSION
name|num_cols
init|=
name|cinfo
operator|->
name|output_width
decl_stmt|;
comment|/* copy these pointers into registers if possible */
specifier|register
name|JSAMPLE
modifier|*
name|range_limit
init|=
name|cinfo
operator|->
name|sample_range_limit
decl_stmt|;
specifier|register
name|int
modifier|*
name|Crrtab
init|=
name|cconvert
operator|->
name|Cr_r_tab
decl_stmt|;
specifier|register
name|int
modifier|*
name|Cbbtab
init|=
name|cconvert
operator|->
name|Cb_b_tab
decl_stmt|;
specifier|register
name|INT32
modifier|*
name|Crgtab
init|=
name|cconvert
operator|->
name|Cr_g_tab
decl_stmt|;
specifier|register
name|INT32
modifier|*
name|Cbgtab
init|=
name|cconvert
operator|->
name|Cb_g_tab
decl_stmt|;
name|SHIFT_TEMPS
while|while
condition|(
operator|--
name|num_rows
operator|>=
literal|0
condition|)
block|{
name|inptr0
operator|=
name|input_buf
index|[
literal|0
index|]
index|[
name|input_row
index|]
expr_stmt|;
name|inptr1
operator|=
name|input_buf
index|[
literal|1
index|]
index|[
name|input_row
index|]
expr_stmt|;
name|inptr2
operator|=
name|input_buf
index|[
literal|2
index|]
index|[
name|input_row
index|]
expr_stmt|;
name|inptr3
operator|=
name|input_buf
index|[
literal|3
index|]
index|[
name|input_row
index|]
expr_stmt|;
name|input_row
operator|++
expr_stmt|;
name|outptr
operator|=
operator|*
name|output_buf
operator|++
expr_stmt|;
for|for
control|(
name|col
operator|=
literal|0
init|;
name|col
operator|<
name|num_cols
condition|;
name|col
operator|++
control|)
block|{
name|y
operator|=
name|GETJSAMPLE
argument_list|(
name|inptr0
index|[
name|col
index|]
argument_list|)
expr_stmt|;
name|cb
operator|=
name|GETJSAMPLE
argument_list|(
name|inptr1
index|[
name|col
index|]
argument_list|)
expr_stmt|;
name|cr
operator|=
name|GETJSAMPLE
argument_list|(
name|inptr2
index|[
name|col
index|]
argument_list|)
expr_stmt|;
comment|/* Range-limiting is essential due to noise introduced by DCT losses. */
name|outptr
index|[
literal|0
index|]
operator|=
name|range_limit
index|[
name|MAXJSAMPLE
operator|-
operator|(
name|y
operator|+
name|Crrtab
index|[
name|cr
index|]
operator|)
index|]
expr_stmt|;
comment|/* red */
name|outptr
index|[
literal|1
index|]
operator|=
name|range_limit
index|[
name|MAXJSAMPLE
operator|-
operator|(
name|y
operator|+
comment|/* green */
operator|(
operator|(
name|int
operator|)
name|RIGHT_SHIFT
argument_list|(
name|Cbgtab
index|[
name|cb
index|]
operator|+
name|Crgtab
index|[
name|cr
index|]
argument_list|,
name|SCALEBITS
argument_list|)
operator|)
operator|)
index|]
expr_stmt|;
name|outptr
index|[
literal|2
index|]
operator|=
name|range_limit
index|[
name|MAXJSAMPLE
operator|-
operator|(
name|y
operator|+
name|Cbbtab
index|[
name|cb
index|]
operator|)
index|]
expr_stmt|;
comment|/* blue */
comment|/* K passes through unchanged */
name|outptr
index|[
literal|3
index|]
operator|=
name|inptr3
index|[
name|col
index|]
expr_stmt|;
comment|/* don't need GETJSAMPLE here */
name|outptr
operator|+=
literal|4
expr_stmt|;
block|}
block|}
block|}
end_block
begin_comment
comment|/*  * Empty method for start_pass.  */
end_comment
begin_macro
name|METHODDEF
argument_list|(
argument|void
argument_list|)
end_macro
begin_macro
DECL|function|start_pass_dcolor
name|start_pass_dcolor
argument_list|(
argument|j_decompress_ptr cinfo
argument_list|)
end_macro
begin_block
block|{
comment|/* no work needed */
block|}
end_block
begin_comment
comment|/*  * Module initialization routine for output colorspace conversion.  */
end_comment
begin_macro
name|GLOBAL
argument_list|(
argument|void
argument_list|)
end_macro
begin_macro
DECL|function|jinit_color_deconverter
name|jinit_color_deconverter
argument_list|(
argument|j_decompress_ptr cinfo
argument_list|)
end_macro
begin_block
block|{
name|my_cconvert_ptr
name|cconvert
decl_stmt|;
name|int
name|ci
decl_stmt|;
name|cconvert
operator|=
call|(
name|my_cconvert_ptr
call|)
argument_list|(
operator|*
name|cinfo
operator|->
name|mem
operator|->
name|alloc_small
argument_list|)
argument_list|(
operator|(
name|j_common_ptr
operator|)
name|cinfo
argument_list|,
name|JPOOL_IMAGE
argument_list|,
name|SIZEOF
argument_list|(
name|my_color_deconverter
argument_list|)
argument_list|)
expr_stmt|;
name|cinfo
operator|->
name|cconvert
operator|=
operator|(
expr|struct
name|jpeg_color_deconverter
operator|*
operator|)
name|cconvert
expr_stmt|;
name|cconvert
operator|->
name|pub
operator|.
name|start_pass
operator|=
name|start_pass_dcolor
expr_stmt|;
comment|/* Make sure num_components agrees with jpeg_color_space */
switch|switch
condition|(
name|cinfo
operator|->
name|jpeg_color_space
condition|)
block|{
case|case
name|JCS_GRAYSCALE
case|:
if|if
condition|(
name|cinfo
operator|->
name|num_components
operator|!=
literal|1
condition|)
name|ERREXIT
argument_list|(
name|cinfo
argument_list|,
name|JERR_BAD_J_COLORSPACE
argument_list|)
expr_stmt|;
break|break;
case|case
name|JCS_RGB
case|:
case|case
name|JCS_YCbCr
case|:
if|if
condition|(
name|cinfo
operator|->
name|num_components
operator|!=
literal|3
condition|)
name|ERREXIT
argument_list|(
name|cinfo
argument_list|,
name|JERR_BAD_J_COLORSPACE
argument_list|)
expr_stmt|;
break|break;
case|case
name|JCS_CMYK
case|:
case|case
name|JCS_YCCK
case|:
if|if
condition|(
name|cinfo
operator|->
name|num_components
operator|!=
literal|4
condition|)
name|ERREXIT
argument_list|(
name|cinfo
argument_list|,
name|JERR_BAD_J_COLORSPACE
argument_list|)
expr_stmt|;
break|break;
default|default:
comment|/* JCS_UNKNOWN can be anything */
if|if
condition|(
name|cinfo
operator|->
name|num_components
operator|<
literal|1
condition|)
name|ERREXIT
argument_list|(
name|cinfo
argument_list|,
name|JERR_BAD_J_COLORSPACE
argument_list|)
expr_stmt|;
break|break;
block|}
comment|/* Set out_color_components and conversion method based on requested space.    * Also clear the component_needed flags for any unused components,    * so that earlier pipeline stages can avoid useless computation.    */
switch|switch
condition|(
name|cinfo
operator|->
name|out_color_space
condition|)
block|{
case|case
name|JCS_GRAYSCALE
case|:
name|cinfo
operator|->
name|out_color_components
operator|=
literal|1
expr_stmt|;
if|if
condition|(
name|cinfo
operator|->
name|jpeg_color_space
operator|==
name|JCS_GRAYSCALE
operator|||
name|cinfo
operator|->
name|jpeg_color_space
operator|==
name|JCS_YCbCr
condition|)
block|{
name|cconvert
operator|->
name|pub
operator|.
name|color_convert
operator|=
name|grayscale_convert
expr_stmt|;
comment|/* For color->grayscale conversion, only the Y (0) component is needed */
for|for
control|(
name|ci
operator|=
literal|1
init|;
name|ci
operator|<
name|cinfo
operator|->
name|num_components
condition|;
name|ci
operator|++
control|)
name|cinfo
operator|->
name|comp_info
index|[
name|ci
index|]
operator|.
name|component_needed
operator|=
name|FALSE
expr_stmt|;
block|}
else|else
name|ERREXIT
argument_list|(
name|cinfo
argument_list|,
name|JERR_CONVERSION_NOTIMPL
argument_list|)
expr_stmt|;
break|break;
case|case
name|JCS_RGB
case|:
name|cinfo
operator|->
name|out_color_components
operator|=
name|RGB_PIXELSIZE
expr_stmt|;
if|if
condition|(
name|cinfo
operator|->
name|jpeg_color_space
operator|==
name|JCS_YCbCr
condition|)
block|{
name|cconvert
operator|->
name|pub
operator|.
name|color_convert
operator|=
name|ycc_rgb_convert
expr_stmt|;
name|build_ycc_rgb_table
argument_list|(
name|cinfo
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|cinfo
operator|->
name|jpeg_color_space
operator|==
name|JCS_GRAYSCALE
condition|)
block|{
name|cconvert
operator|->
name|pub
operator|.
name|color_convert
operator|=
name|gray_rgb_convert
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|cinfo
operator|->
name|jpeg_color_space
operator|==
name|JCS_RGB
operator|&&
name|RGB_PIXELSIZE
operator|==
literal|3
condition|)
block|{
name|cconvert
operator|->
name|pub
operator|.
name|color_convert
operator|=
name|null_convert
expr_stmt|;
block|}
else|else
name|ERREXIT
argument_list|(
name|cinfo
argument_list|,
name|JERR_CONVERSION_NOTIMPL
argument_list|)
expr_stmt|;
break|break;
case|case
name|JCS_CMYK
case|:
name|cinfo
operator|->
name|out_color_components
operator|=
literal|4
expr_stmt|;
if|if
condition|(
name|cinfo
operator|->
name|jpeg_color_space
operator|==
name|JCS_YCCK
condition|)
block|{
name|cconvert
operator|->
name|pub
operator|.
name|color_convert
operator|=
name|ycck_cmyk_convert
expr_stmt|;
name|build_ycc_rgb_table
argument_list|(
name|cinfo
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|cinfo
operator|->
name|jpeg_color_space
operator|==
name|JCS_CMYK
condition|)
block|{
name|cconvert
operator|->
name|pub
operator|.
name|color_convert
operator|=
name|null_convert
expr_stmt|;
block|}
else|else
name|ERREXIT
argument_list|(
name|cinfo
argument_list|,
name|JERR_CONVERSION_NOTIMPL
argument_list|)
expr_stmt|;
break|break;
default|default:
comment|/* Permit null conversion to same output space */
if|if
condition|(
name|cinfo
operator|->
name|out_color_space
operator|==
name|cinfo
operator|->
name|jpeg_color_space
condition|)
block|{
name|cinfo
operator|->
name|out_color_components
operator|=
name|cinfo
operator|->
name|num_components
expr_stmt|;
name|cconvert
operator|->
name|pub
operator|.
name|color_convert
operator|=
name|null_convert
expr_stmt|;
block|}
else|else
comment|/* unsupported non-null conversion */
name|ERREXIT
argument_list|(
name|cinfo
argument_list|,
name|JERR_CONVERSION_NOTIMPL
argument_list|)
expr_stmt|;
break|break;
block|}
if|if
condition|(
name|cinfo
operator|->
name|quantize_colors
condition|)
name|cinfo
operator|->
name|output_components
operator|=
literal|1
expr_stmt|;
comment|/* single colormapped output component */
else|else
name|cinfo
operator|->
name|output_components
operator|=
name|cinfo
operator|->
name|out_color_components
expr_stmt|;
block|}
end_block
end_unit
