begin_unit
begin_comment
comment|/*  * Copyright (C) 2005 The Android Open Source Project  *  * Licensed under the Apache License, Version 2.0 (the "License");  * you may not use this file except in compliance with the License.  * You may obtain a copy of the License at  *  *      http://www.apache.org/licenses/LICENSE-2.0  *  * Unless required by applicable law or agreed to in writing, software  * distributed under the License is distributed on an "AS IS" BASIS,  * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.  * See the License for the specific language governing permissions and  * limitations under the License.  */
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|EXTRACT_H
end_ifndef
begin_define
DECL|macro|EXTRACT_H
define|#
directive|define
name|EXTRACT_H
end_define
begin_include
include|#
directive|include
file|<cstdint>
end_include
begin_include
include|#
directive|include
file|<cstring>
end_include
begin_comment
comment|// shamelessly stolen from ResourceTypes.h Android's sources
end_comment
begin_comment
comment|/**  * This chunk specifies how to split an image into segments for  * scaling.  *  * There are J horizontal and K vertical segments.  These segments divide  * the image into J*K regions as follows (where J=4 and K=3):  *  *      F0   S0    F1     S1  *   +-----+----+------+-------+  * S2|  0  |  1 |  2   |   3   |  *   +-----+----+------+-------+  *   |     |    |      |       |  *   |     |    |      |       |  * F2|  4  |  5 |  6   |   7   |  *   |     |    |      |       |  *   |     |    |      |       |  *   +-----+----+------+-------+  * S3|  8  |  9 |  10  |   11  |  *   +-----+----+------+-------+  *  * Each horizontal and vertical segment is considered to by either  * stretchable (marked by the Sx labels) or fixed (marked by the Fy  * labels), in the horizontal or vertical axis, respectively. In the  * above example, the first is horizontal segment (F0) is fixed, the  * next is stretchable and then they continue to alternate. Note that  * the segment list for each axis can begin or end with a stretchable  * or fixed segment.  *  * The relative sizes of the stretchy segments indicates the relative  * amount of stretchiness of the regions bordered by the segments.  For  * example, regions 3, 7 and 11 above will take up more horizontal space  * than regions 1, 5 and 9 since the horizontal segment associated with  * the first set of regions is larger than the other set of regions.  The  * ratios of the amount of horizontal (or vertical) space taken by any  * two stretchable slices is exactly the ratio of their corresponding  * segment lengths.  *  * xDivs and yDivs point to arrays of horizontal and vertical pixel  * indices.  The first pair of Divs (in either array) indicate the  * starting and ending points of the first stretchable segment in that  * axis. The next pair specifies the next stretchable segment, etc. So  * in the above example xDiv[0] and xDiv[1] specify the horizontal  * coordinates for the regions labeled 1, 5 and 9.  xDiv[2] and  * xDiv[3] specify the coordinates for regions 3, 7 and 11. Note that  * the leftmost slices always start at x=0 and the rightmost slices  * always end at the end of the image. So, for example, the regions 0,  * 4 and 8 (which are fixed along the X axis) start at x value 0 and  * go to xDiv[0] and slices 2, 6 and 10 start at xDiv[1] and end at  * xDiv[2].  *  * The array pointed to by the colors field lists contains hints for  * each of the regions.  They are ordered according left-to-right and  * top-to-bottom as indicated above. For each segment that is a solid  * color the array entry will contain that color value; otherwise it  * will contain NO_COLOR.  Segments that are completely transparent  * will always have the value TRANSPARENT_COLOR.  *  * The PNG chunk type is "npTc".  */
end_comment
begin_struct
DECL|struct|Res_png_9patch
struct|struct
name|Res_png_9patch
block|{
DECL|function|Res_png_9patch
name|Res_png_9patch
argument_list|()
operator|:
name|wasDeserialized
argument_list|(
name|false
argument_list|)
operator|,
name|xDivs
argument_list|(
name|NULL
argument_list|)
operator|,
name|yDivs
argument_list|(
name|NULL
argument_list|)
operator|,
name|colors
argument_list|(
argument|NULL
argument_list|)
block|{ }
DECL|member|wasDeserialized
name|int8_t
name|wasDeserialized
expr_stmt|;
DECL|member|numXDivs
name|int8_t
name|numXDivs
decl_stmt|;
DECL|member|numYDivs
name|int8_t
name|numYDivs
decl_stmt|;
DECL|member|numColors
name|int8_t
name|numColors
decl_stmt|;
comment|// These tell where the next section of a patch starts.
comment|// For example, the first patch includes the pixels from
comment|// 0 to xDivs[0]-1 and the second patch includes the pixels
comment|// from xDivs[0] to xDivs[1]-1.
comment|// Note: allocation/free of these pointers is left to the caller.
DECL|member|xDivs
name|int32_t
modifier|*
name|xDivs
decl_stmt|;
DECL|member|yDivs
name|int32_t
modifier|*
name|yDivs
decl_stmt|;
DECL|member|paddingLeft
DECL|member|paddingRight
name|int32_t
name|paddingLeft
decl_stmt|,
name|paddingRight
decl_stmt|;
DECL|member|paddingTop
DECL|member|paddingBottom
name|int32_t
name|paddingTop
decl_stmt|,
name|paddingBottom
decl_stmt|;
enum|enum
block|{
comment|// The 9 patch segment is not a solid color.
DECL|enumerator|NO_COLOR
name|NO_COLOR
init|=
literal|0x00000001
block|,
comment|// The 9 patch segment is completely transparent.
DECL|enumerator|TRANSPARENT_COLOR
name|TRANSPARENT_COLOR
init|=
literal|0x00000000
block|}
enum|;
comment|// Note: allocation/free of this pointer is left to the caller.
DECL|member|colors
name|uint32_t
modifier|*
name|colors
decl_stmt|;
comment|// Deserialize/Unmarshall the patch data
specifier|static
name|Res_png_9patch
modifier|*
name|deserialize
parameter_list|(
specifier|const
name|void
modifier|*
name|data
parameter_list|)
function_decl|;
block|}
struct|;
end_struct
begin_endif
endif|#
directive|endif
end_endif
end_unit
