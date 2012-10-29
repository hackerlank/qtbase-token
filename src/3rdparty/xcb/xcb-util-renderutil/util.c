begin_unit
begin_comment
comment|/* Copyright Â© 2000 Keith Packard  *  * Permission to use, copy, modify, distribute, and sell this software and its  * documentation for any purpose is hereby granted without fee, provided that  * the above copyright notice appear in all copies and that both that  * copyright notice and this permission notice appear in supporting  * documentation, and that the name of Keith Packard not be used in  * advertising or publicity pertaining to distribution of the software without  * specific, written prior permission.  Keith Packard makes no  * representations about the suitability of this software for any purpose.  It  * is provided "as is" without express or implied warranty.  *  * KEITH PACKARD DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE,  * INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS, IN NO  * EVENT SHALL KEITH PACKARD BE LIABLE FOR ANY SPECIAL, INDIRECT OR  * CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE,  * DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER  * TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR  * PERFORMANCE OF THIS SOFTWARE.  */
end_comment
begin_include
include|#
directive|include
file|"xcb_renderutil.h"
end_include
begin_function
name|xcb_render_pictvisual_t
modifier|*
DECL|function|xcb_render_util_find_visual_format
name|xcb_render_util_find_visual_format
parameter_list|(
specifier|const
name|xcb_render_query_pict_formats_reply_t
modifier|*
name|formats
parameter_list|,
specifier|const
name|xcb_visualid_t
name|visual
parameter_list|)
block|{
name|xcb_render_pictscreen_iterator_t
name|screens
decl_stmt|;
name|xcb_render_pictdepth_iterator_t
name|depths
decl_stmt|;
name|xcb_render_pictvisual_iterator_t
name|visuals
decl_stmt|;
if|if
condition|(
operator|!
name|formats
condition|)
return|return
literal|0
return|;
for|for
control|(
name|screens
operator|=
name|xcb_render_query_pict_formats_screens_iterator
argument_list|(
name|formats
argument_list|)
init|;
name|screens
operator|.
name|rem
condition|;
name|xcb_render_pictscreen_next
argument_list|(
operator|&
name|screens
argument_list|)
control|)
for|for
control|(
name|depths
operator|=
name|xcb_render_pictscreen_depths_iterator
argument_list|(
name|screens
operator|.
name|data
argument_list|)
init|;
name|depths
operator|.
name|rem
condition|;
name|xcb_render_pictdepth_next
argument_list|(
operator|&
name|depths
argument_list|)
control|)
for|for
control|(
name|visuals
operator|=
name|xcb_render_pictdepth_visuals_iterator
argument_list|(
name|depths
operator|.
name|data
argument_list|)
init|;
name|visuals
operator|.
name|rem
condition|;
name|xcb_render_pictvisual_next
argument_list|(
operator|&
name|visuals
argument_list|)
control|)
if|if
condition|(
name|visuals
operator|.
name|data
operator|->
name|visual
operator|==
name|visual
condition|)
return|return
name|visuals
operator|.
name|data
return|;
return|return
literal|0
return|;
block|}
end_function
begin_function
name|xcb_render_pictforminfo_t
modifier|*
DECL|function|xcb_render_util_find_format
name|xcb_render_util_find_format
parameter_list|(
specifier|const
name|xcb_render_query_pict_formats_reply_t
modifier|*
name|formats
parameter_list|,
name|unsigned
name|long
name|mask
parameter_list|,
specifier|const
name|xcb_render_pictforminfo_t
modifier|*
name|template
parameter_list|,
name|int
name|count
parameter_list|)
block|{
name|xcb_render_pictforminfo_iterator_t
name|i
decl_stmt|;
if|if
condition|(
operator|!
name|formats
condition|)
return|return
literal|0
return|;
for|for
control|(
name|i
operator|=
name|xcb_render_query_pict_formats_formats_iterator
argument_list|(
name|formats
argument_list|)
init|;
name|i
operator|.
name|rem
condition|;
name|xcb_render_pictforminfo_next
argument_list|(
operator|&
name|i
argument_list|)
control|)
block|{
if|if
condition|(
name|mask
operator|&
name|XCB_PICT_FORMAT_ID
condition|)
if|if
condition|(
name|template
operator|->
name|id
operator|!=
name|i
operator|.
name|data
operator|->
name|id
condition|)
continue|continue;
if|if
condition|(
name|mask
operator|&
name|XCB_PICT_FORMAT_TYPE
condition|)
if|if
condition|(
name|template
operator|->
name|type
operator|!=
name|i
operator|.
name|data
operator|->
name|type
condition|)
continue|continue;
if|if
condition|(
name|mask
operator|&
name|XCB_PICT_FORMAT_DEPTH
condition|)
if|if
condition|(
name|template
operator|->
name|depth
operator|!=
name|i
operator|.
name|data
operator|->
name|depth
condition|)
continue|continue;
if|if
condition|(
name|mask
operator|&
name|XCB_PICT_FORMAT_RED
condition|)
if|if
condition|(
name|template
operator|->
name|direct
operator|.
name|red_shift
operator|!=
name|i
operator|.
name|data
operator|->
name|direct
operator|.
name|red_shift
condition|)
continue|continue;
if|if
condition|(
name|mask
operator|&
name|XCB_PICT_FORMAT_RED_MASK
condition|)
if|if
condition|(
name|template
operator|->
name|direct
operator|.
name|red_mask
operator|!=
name|i
operator|.
name|data
operator|->
name|direct
operator|.
name|red_mask
condition|)
continue|continue;
if|if
condition|(
name|mask
operator|&
name|XCB_PICT_FORMAT_GREEN
condition|)
if|if
condition|(
name|template
operator|->
name|direct
operator|.
name|green_shift
operator|!=
name|i
operator|.
name|data
operator|->
name|direct
operator|.
name|green_shift
condition|)
continue|continue;
if|if
condition|(
name|mask
operator|&
name|XCB_PICT_FORMAT_GREEN_MASK
condition|)
if|if
condition|(
name|template
operator|->
name|direct
operator|.
name|green_mask
operator|!=
name|i
operator|.
name|data
operator|->
name|direct
operator|.
name|green_mask
condition|)
continue|continue;
if|if
condition|(
name|mask
operator|&
name|XCB_PICT_FORMAT_BLUE
condition|)
if|if
condition|(
name|template
operator|->
name|direct
operator|.
name|blue_shift
operator|!=
name|i
operator|.
name|data
operator|->
name|direct
operator|.
name|blue_shift
condition|)
continue|continue;
if|if
condition|(
name|mask
operator|&
name|XCB_PICT_FORMAT_BLUE_MASK
condition|)
if|if
condition|(
name|template
operator|->
name|direct
operator|.
name|blue_mask
operator|!=
name|i
operator|.
name|data
operator|->
name|direct
operator|.
name|blue_mask
condition|)
continue|continue;
if|if
condition|(
name|mask
operator|&
name|XCB_PICT_FORMAT_ALPHA
condition|)
if|if
condition|(
name|template
operator|->
name|direct
operator|.
name|alpha_shift
operator|!=
name|i
operator|.
name|data
operator|->
name|direct
operator|.
name|alpha_shift
condition|)
continue|continue;
if|if
condition|(
name|mask
operator|&
name|XCB_PICT_FORMAT_ALPHA_MASK
condition|)
if|if
condition|(
name|template
operator|->
name|direct
operator|.
name|alpha_mask
operator|!=
name|i
operator|.
name|data
operator|->
name|direct
operator|.
name|alpha_mask
condition|)
continue|continue;
if|if
condition|(
name|mask
operator|&
name|XCB_PICT_FORMAT_COLORMAP
condition|)
if|if
condition|(
name|template
operator|->
name|colormap
operator|!=
name|i
operator|.
name|data
operator|->
name|colormap
condition|)
continue|continue;
if|if
condition|(
name|count
operator|--
operator|==
literal|0
condition|)
return|return
name|i
operator|.
name|data
return|;
block|}
return|return
literal|0
return|;
block|}
end_function
begin_function
name|xcb_render_pictforminfo_t
modifier|*
DECL|function|xcb_render_util_find_standard_format
name|xcb_render_util_find_standard_format
parameter_list|(
specifier|const
name|xcb_render_query_pict_formats_reply_t
modifier|*
name|formats
parameter_list|,
name|xcb_pict_standard_t
name|format
parameter_list|)
block|{
specifier|static
specifier|const
struct|struct
block|{
name|xcb_render_pictforminfo_t
name|templ
decl_stmt|;
name|unsigned
name|long
name|mask
decl_stmt|;
block|}
name|standardFormats
index|[]
init|=
block|{
comment|/* XCB_PICT_STANDARD_ARGB_32 */
block|{
block|{
literal|0
block|,
comment|/* id */
name|XCB_RENDER_PICT_TYPE_DIRECT
block|,
comment|/* type */
literal|32
block|,
comment|/* depth */
block|{
literal|0
block|}
block|,
comment|/* pad */
block|{
comment|/* direct */
literal|16
block|,
comment|/* direct.red */
literal|0xff
block|,
comment|/* direct.red_mask */
literal|8
block|,
comment|/* direct.green */
literal|0xff
block|,
comment|/* direct.green_mask */
literal|0
block|,
comment|/* direct.blue */
literal|0xff
block|,
comment|/* direct.blue_mask */
literal|24
block|,
comment|/* direct.alpha */
literal|0xff
block|,
comment|/* direct.alpha_mask */
block|}
block|,
literal|0
block|,
comment|/* colormap */
block|}
block|,
name|XCB_PICT_FORMAT_TYPE
operator||
name|XCB_PICT_FORMAT_DEPTH
operator||
name|XCB_PICT_FORMAT_RED
operator||
name|XCB_PICT_FORMAT_RED_MASK
operator||
name|XCB_PICT_FORMAT_GREEN
operator||
name|XCB_PICT_FORMAT_GREEN_MASK
operator||
name|XCB_PICT_FORMAT_BLUE
operator||
name|XCB_PICT_FORMAT_BLUE_MASK
operator||
name|XCB_PICT_FORMAT_ALPHA
operator||
name|XCB_PICT_FORMAT_ALPHA_MASK
block|, 	}
block|,
comment|/* XCB_PICT_STANDARD_RGB_24 */
block|{
block|{
literal|0
block|,
comment|/* id */
name|XCB_RENDER_PICT_TYPE_DIRECT
block|,
comment|/* type */
literal|24
block|,
comment|/* depth */
block|{
literal|0
block|}
block|,
comment|/* pad */
block|{
comment|/* direct */
literal|16
block|,
comment|/* direct.red */
literal|0xff
block|,
comment|/* direct.red_MASK */
literal|8
block|,
comment|/* direct.green */
literal|0xff
block|,
comment|/* direct.green_MASK */
literal|0
block|,
comment|/* direct.blue */
literal|0xff
block|,
comment|/* direct.blue_MASK */
literal|0
block|,
comment|/* direct.alpha */
literal|0x00
block|,
comment|/* direct.alpha_MASK */
block|}
block|,
literal|0
block|,
comment|/* colormap */
block|}
block|,
name|XCB_PICT_FORMAT_TYPE
operator||
name|XCB_PICT_FORMAT_DEPTH
operator||
name|XCB_PICT_FORMAT_RED
operator||
name|XCB_PICT_FORMAT_RED_MASK
operator||
name|XCB_PICT_FORMAT_GREEN
operator||
name|XCB_PICT_FORMAT_GREEN_MASK
operator||
name|XCB_PICT_FORMAT_BLUE
operator||
name|XCB_PICT_FORMAT_BLUE_MASK
operator||
name|XCB_PICT_FORMAT_ALPHA_MASK
block|, 	}
block|,
comment|/* XCB_PICT_STANDARD_A_8 */
block|{
block|{
literal|0
block|,
comment|/* id */
name|XCB_RENDER_PICT_TYPE_DIRECT
block|,
comment|/* type */
literal|8
block|,
comment|/* depth */
block|{
literal|0
block|}
block|,
comment|/* pad */
block|{
comment|/* direct */
literal|0
block|,
comment|/* direct.red */
literal|0x00
block|,
comment|/* direct.red_MASK */
literal|0
block|,
comment|/* direct.green */
literal|0x00
block|,
comment|/* direct.green_MASK */
literal|0
block|,
comment|/* direct.blue */
literal|0x00
block|,
comment|/* direct.blue_MASK */
literal|0
block|,
comment|/* direct.alpha */
literal|0xff
block|,
comment|/* direct.alpha_MASK */
block|}
block|,
literal|0
block|,
comment|/* colormap */
block|}
block|,
name|XCB_PICT_FORMAT_TYPE
operator||
name|XCB_PICT_FORMAT_DEPTH
operator||
name|XCB_PICT_FORMAT_RED_MASK
operator||
name|XCB_PICT_FORMAT_GREEN_MASK
operator||
name|XCB_PICT_FORMAT_BLUE_MASK
operator||
name|XCB_PICT_FORMAT_ALPHA
operator||
name|XCB_PICT_FORMAT_ALPHA_MASK
block|, 	}
block|,
comment|/* XCB_PICT_STANDARD_A_4 */
block|{
block|{
literal|0
block|,
comment|/* id */
name|XCB_RENDER_PICT_TYPE_DIRECT
block|,
comment|/* type */
literal|4
block|,
comment|/* depth */
block|{
literal|0
block|}
block|,
comment|/* pad */
block|{
comment|/* direct */
literal|0
block|,
comment|/* direct.red */
literal|0x00
block|,
comment|/* direct.red_MASK */
literal|0
block|,
comment|/* direct.green */
literal|0x00
block|,
comment|/* direct.green_MASK */
literal|0
block|,
comment|/* direct.blue */
literal|0x00
block|,
comment|/* direct.blue_MASK */
literal|0
block|,
comment|/* direct.alpha */
literal|0x0f
block|,
comment|/* direct.alpha_MASK */
block|}
block|,
literal|0
block|,
comment|/* colormap */
block|}
block|,
name|XCB_PICT_FORMAT_TYPE
operator||
name|XCB_PICT_FORMAT_DEPTH
operator||
name|XCB_PICT_FORMAT_RED_MASK
operator||
name|XCB_PICT_FORMAT_GREEN_MASK
operator||
name|XCB_PICT_FORMAT_BLUE_MASK
operator||
name|XCB_PICT_FORMAT_ALPHA
operator||
name|XCB_PICT_FORMAT_ALPHA_MASK
block|, 	}
block|,
comment|/* XCB_PICT_STANDARD_A_1 */
block|{
block|{
literal|0
block|,
comment|/* id */
name|XCB_RENDER_PICT_TYPE_DIRECT
block|,
comment|/* type */
literal|1
block|,
comment|/* depth */
block|{
literal|0
block|}
block|,
comment|/* pad */
block|{
comment|/* direct */
literal|0
block|,
comment|/* direct.red */
literal|0x00
block|,
comment|/* direct.red_MASK */
literal|0
block|,
comment|/* direct.green */
literal|0x00
block|,
comment|/* direct.green_MASK */
literal|0
block|,
comment|/* direct.blue */
literal|0x00
block|,
comment|/* direct.blue_MASK */
literal|0
block|,
comment|/* direct.alpha */
literal|0x01
block|,
comment|/* direct.alpha_MASK */
block|}
block|,
literal|0
block|,
comment|/* colormap */
block|}
block|,
name|XCB_PICT_FORMAT_TYPE
operator||
name|XCB_PICT_FORMAT_DEPTH
operator||
name|XCB_PICT_FORMAT_RED_MASK
operator||
name|XCB_PICT_FORMAT_GREEN_MASK
operator||
name|XCB_PICT_FORMAT_BLUE_MASK
operator||
name|XCB_PICT_FORMAT_ALPHA
operator||
name|XCB_PICT_FORMAT_ALPHA_MASK
block|, 	}
block|,     }
struct|;
if|if
condition|(
name|format
operator|<
literal|0
operator|||
name|format
operator|>=
sizeof|sizeof
argument_list|(
name|standardFormats
argument_list|)
operator|/
sizeof|sizeof
argument_list|(
operator|*
name|standardFormats
argument_list|)
condition|)
return|return
literal|0
return|;
return|return
name|xcb_render_util_find_format
argument_list|(
name|formats
argument_list|,
name|standardFormats
index|[
name|format
index|]
operator|.
name|mask
argument_list|,
operator|&
name|standardFormats
index|[
name|format
index|]
operator|.
name|templ
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function
end_unit
