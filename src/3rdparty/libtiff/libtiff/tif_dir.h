begin_unit
begin_comment
comment|/* $Id: tif_dir.h,v 1.30.2.1 2007/04/07 14:58:30 dron Exp $ */
end_comment
begin_comment
comment|/*  * Copyright (c) 1988-1997 Sam Leffler  * Copyright (c) 1991-1997 Silicon Graphics, Inc.  *  * Permission to use, copy, modify, distribute, and sell this software and   * its documentation for any purpose is hereby granted without fee, provided  * that (i) the above copyright notices and this permission notice appear in  * all copies of the software and related documentation, and (ii) the names of  * Sam Leffler and Silicon Graphics may not be used in any advertising or  * publicity relating to the software without the specific, prior written  * permission of Sam Leffler and Silicon Graphics.  *   * THE SOFTWARE IS PROVIDED "AS-IS" AND WITHOUT WARRANTY OF ANY KIND,   * EXPRESS, IMPLIED OR OTHERWISE, INCLUDING WITHOUT LIMITATION, ANY   * WARRANTY OF MERCHANTABILITY OR FITNESS FOR A PARTICULAR PURPOSE.    *   * IN NO EVENT SHALL SAM LEFFLER OR SILICON GRAPHICS BE LIABLE FOR  * ANY SPECIAL, INCIDENTAL, INDIRECT OR CONSEQUENTIAL DAMAGES OF ANY KIND,  * OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS,  * WHETHER OR NOT ADVISED OF THE POSSIBILITY OF DAMAGE, AND ON ANY THEORY OF   * LIABILITY, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE   * OF THIS SOFTWARE.  */
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|_TIFFDIR_
end_ifndef
begin_define
DECL|macro|_TIFFDIR_
define|#
directive|define
name|_TIFFDIR_
end_define
begin_comment
comment|/*  * ``Library-private'' Directory-related Definitions.  */
end_comment
begin_comment
comment|/*  * Internal format of a TIFF directory entry.  */
end_comment
begin_typedef
typedef|typedef
struct|struct
block|{
DECL|macro|FIELD_SETLONGS
define|#
directive|define
name|FIELD_SETLONGS
value|4
comment|/* bit vector of fields that are set */
DECL|member|td_fieldsset
name|unsigned
name|long
name|td_fieldsset
index|[
name|FIELD_SETLONGS
index|]
decl_stmt|;
DECL|member|td_imagewidth
DECL|member|td_imagelength
DECL|member|td_imagedepth
name|uint32
name|td_imagewidth
decl_stmt|,
name|td_imagelength
decl_stmt|,
name|td_imagedepth
decl_stmt|;
DECL|member|td_tilewidth
DECL|member|td_tilelength
DECL|member|td_tiledepth
name|uint32
name|td_tilewidth
decl_stmt|,
name|td_tilelength
decl_stmt|,
name|td_tiledepth
decl_stmt|;
DECL|member|td_subfiletype
name|uint32
name|td_subfiletype
decl_stmt|;
DECL|member|td_bitspersample
name|uint16
name|td_bitspersample
decl_stmt|;
DECL|member|td_sampleformat
name|uint16
name|td_sampleformat
decl_stmt|;
DECL|member|td_compression
name|uint16
name|td_compression
decl_stmt|;
DECL|member|td_photometric
name|uint16
name|td_photometric
decl_stmt|;
DECL|member|td_threshholding
name|uint16
name|td_threshholding
decl_stmt|;
DECL|member|td_fillorder
name|uint16
name|td_fillorder
decl_stmt|;
DECL|member|td_orientation
name|uint16
name|td_orientation
decl_stmt|;
DECL|member|td_samplesperpixel
name|uint16
name|td_samplesperpixel
decl_stmt|;
DECL|member|td_rowsperstrip
name|uint32
name|td_rowsperstrip
decl_stmt|;
DECL|member|td_minsamplevalue
DECL|member|td_maxsamplevalue
name|uint16
name|td_minsamplevalue
decl_stmt|,
name|td_maxsamplevalue
decl_stmt|;
DECL|member|td_sminsamplevalue
DECL|member|td_smaxsamplevalue
name|double
name|td_sminsamplevalue
decl_stmt|,
name|td_smaxsamplevalue
decl_stmt|;
DECL|member|td_xresolution
DECL|member|td_yresolution
name|float
name|td_xresolution
decl_stmt|,
name|td_yresolution
decl_stmt|;
DECL|member|td_resolutionunit
name|uint16
name|td_resolutionunit
decl_stmt|;
DECL|member|td_planarconfig
name|uint16
name|td_planarconfig
decl_stmt|;
DECL|member|td_xposition
DECL|member|td_yposition
name|float
name|td_xposition
decl_stmt|,
name|td_yposition
decl_stmt|;
DECL|member|td_pagenumber
name|uint16
name|td_pagenumber
index|[
literal|2
index|]
decl_stmt|;
DECL|member|td_colormap
name|uint16
modifier|*
name|td_colormap
index|[
literal|3
index|]
decl_stmt|;
DECL|member|td_halftonehints
name|uint16
name|td_halftonehints
index|[
literal|2
index|]
decl_stmt|;
DECL|member|td_extrasamples
name|uint16
name|td_extrasamples
decl_stmt|;
DECL|member|td_sampleinfo
name|uint16
modifier|*
name|td_sampleinfo
decl_stmt|;
comment|/* even though the name is misleading, td_stripsperimage is the number 	 * of striles (=strips or tiles) per plane, and td_nstrips the total 	 * number of striles */
DECL|member|td_stripsperimage
name|tstrile_t
name|td_stripsperimage
decl_stmt|;
DECL|member|td_nstrips
name|tstrile_t
name|td_nstrips
decl_stmt|;
comment|/* size of offset& bytecount arrays */
DECL|member|td_stripoffset
name|toff_t
modifier|*
name|td_stripoffset
decl_stmt|;
DECL|member|td_stripbytecount
name|toff_t
modifier|*
name|td_stripbytecount
decl_stmt|;
comment|/* FIXME: it should be tsize_t array */
DECL|member|td_stripbytecountsorted
name|int
name|td_stripbytecountsorted
decl_stmt|;
comment|/* is the bytecount array sorted ascending? */
DECL|member|td_nsubifd
name|uint16
name|td_nsubifd
decl_stmt|;
DECL|member|td_subifd
name|uint32
modifier|*
name|td_subifd
decl_stmt|;
comment|/* YCbCr parameters */
DECL|member|td_ycbcrsubsampling
name|uint16
name|td_ycbcrsubsampling
index|[
literal|2
index|]
decl_stmt|;
DECL|member|td_ycbcrpositioning
name|uint16
name|td_ycbcrpositioning
decl_stmt|;
comment|/* Colorimetry parameters */
DECL|member|td_transferfunction
name|uint16
modifier|*
name|td_transferfunction
index|[
literal|3
index|]
decl_stmt|;
comment|/* CMYK parameters */
DECL|member|td_inknameslen
name|int
name|td_inknameslen
decl_stmt|;
DECL|member|td_inknames
name|char
modifier|*
name|td_inknames
decl_stmt|;
DECL|member|td_customValueCount
name|int
name|td_customValueCount
decl_stmt|;
DECL|member|td_customValues
name|TIFFTagValue
modifier|*
name|td_customValues
decl_stmt|;
block|}
DECL|typedef|TIFFDirectory
name|TIFFDirectory
typedef|;
end_typedef
begin_comment
comment|/*  * Field flags used to indicate fields that have  * been set in a directory, and to reference fields  * when manipulating a directory.  */
end_comment
begin_comment
comment|/*  * FIELD_IGNORE is used to signify tags that are to  * be processed but otherwise ignored.  This permits  * antiquated tags to be quietly read and discarded.  * Note that a bit *is* allocated for ignored tags;  * this is understood by the directory reading logic  * which uses this fact to avoid special-case handling  */
end_comment
begin_define
DECL|macro|FIELD_IGNORE
define|#
directive|define
name|FIELD_IGNORE
value|0
end_define
begin_comment
comment|/* multi-item fields */
end_comment
begin_define
DECL|macro|FIELD_IMAGEDIMENSIONS
define|#
directive|define
name|FIELD_IMAGEDIMENSIONS
value|1
end_define
begin_define
DECL|macro|FIELD_TILEDIMENSIONS
define|#
directive|define
name|FIELD_TILEDIMENSIONS
value|2
end_define
begin_define
DECL|macro|FIELD_RESOLUTION
define|#
directive|define
name|FIELD_RESOLUTION
value|3
end_define
begin_define
DECL|macro|FIELD_POSITION
define|#
directive|define
name|FIELD_POSITION
value|4
end_define
begin_comment
comment|/* single-item fields */
end_comment
begin_define
DECL|macro|FIELD_SUBFILETYPE
define|#
directive|define
name|FIELD_SUBFILETYPE
value|5
end_define
begin_define
DECL|macro|FIELD_BITSPERSAMPLE
define|#
directive|define
name|FIELD_BITSPERSAMPLE
value|6
end_define
begin_define
DECL|macro|FIELD_COMPRESSION
define|#
directive|define
name|FIELD_COMPRESSION
value|7
end_define
begin_define
DECL|macro|FIELD_PHOTOMETRIC
define|#
directive|define
name|FIELD_PHOTOMETRIC
value|8
end_define
begin_define
DECL|macro|FIELD_THRESHHOLDING
define|#
directive|define
name|FIELD_THRESHHOLDING
value|9
end_define
begin_define
DECL|macro|FIELD_FILLORDER
define|#
directive|define
name|FIELD_FILLORDER
value|10
end_define
begin_define
DECL|macro|FIELD_ORIENTATION
define|#
directive|define
name|FIELD_ORIENTATION
value|15
end_define
begin_define
DECL|macro|FIELD_SAMPLESPERPIXEL
define|#
directive|define
name|FIELD_SAMPLESPERPIXEL
value|16
end_define
begin_define
DECL|macro|FIELD_ROWSPERSTRIP
define|#
directive|define
name|FIELD_ROWSPERSTRIP
value|17
end_define
begin_define
DECL|macro|FIELD_MINSAMPLEVALUE
define|#
directive|define
name|FIELD_MINSAMPLEVALUE
value|18
end_define
begin_define
DECL|macro|FIELD_MAXSAMPLEVALUE
define|#
directive|define
name|FIELD_MAXSAMPLEVALUE
value|19
end_define
begin_define
DECL|macro|FIELD_PLANARCONFIG
define|#
directive|define
name|FIELD_PLANARCONFIG
value|20
end_define
begin_define
DECL|macro|FIELD_RESOLUTIONUNIT
define|#
directive|define
name|FIELD_RESOLUTIONUNIT
value|22
end_define
begin_define
DECL|macro|FIELD_PAGENUMBER
define|#
directive|define
name|FIELD_PAGENUMBER
value|23
end_define
begin_define
DECL|macro|FIELD_STRIPBYTECOUNTS
define|#
directive|define
name|FIELD_STRIPBYTECOUNTS
value|24
end_define
begin_define
DECL|macro|FIELD_STRIPOFFSETS
define|#
directive|define
name|FIELD_STRIPOFFSETS
value|25
end_define
begin_define
DECL|macro|FIELD_COLORMAP
define|#
directive|define
name|FIELD_COLORMAP
value|26
end_define
begin_define
DECL|macro|FIELD_EXTRASAMPLES
define|#
directive|define
name|FIELD_EXTRASAMPLES
value|31
end_define
begin_define
DECL|macro|FIELD_SAMPLEFORMAT
define|#
directive|define
name|FIELD_SAMPLEFORMAT
value|32
end_define
begin_define
DECL|macro|FIELD_SMINSAMPLEVALUE
define|#
directive|define
name|FIELD_SMINSAMPLEVALUE
value|33
end_define
begin_define
DECL|macro|FIELD_SMAXSAMPLEVALUE
define|#
directive|define
name|FIELD_SMAXSAMPLEVALUE
value|34
end_define
begin_define
DECL|macro|FIELD_IMAGEDEPTH
define|#
directive|define
name|FIELD_IMAGEDEPTH
value|35
end_define
begin_define
DECL|macro|FIELD_TILEDEPTH
define|#
directive|define
name|FIELD_TILEDEPTH
value|36
end_define
begin_define
DECL|macro|FIELD_HALFTONEHINTS
define|#
directive|define
name|FIELD_HALFTONEHINTS
value|37
end_define
begin_define
DECL|macro|FIELD_YCBCRSUBSAMPLING
define|#
directive|define
name|FIELD_YCBCRSUBSAMPLING
value|39
end_define
begin_define
DECL|macro|FIELD_YCBCRPOSITIONING
define|#
directive|define
name|FIELD_YCBCRPOSITIONING
value|40
end_define
begin_define
DECL|macro|FIELD_TRANSFERFUNCTION
define|#
directive|define
name|FIELD_TRANSFERFUNCTION
value|44
end_define
begin_define
DECL|macro|FIELD_INKNAMES
define|#
directive|define
name|FIELD_INKNAMES
value|46
end_define
begin_define
DECL|macro|FIELD_SUBIFD
define|#
directive|define
name|FIELD_SUBIFD
value|49
end_define
begin_comment
comment|/*      FIELD_CUSTOM (see tiffio.h)     65 */
end_comment
begin_comment
comment|/* end of support for well-known tags; codec-private tags follow */
end_comment
begin_define
DECL|macro|FIELD_CODEC
define|#
directive|define
name|FIELD_CODEC
value|66
end_define
begin_comment
DECL|macro|FIELD_CODEC
comment|/* base of codec-private tags */
end_comment
begin_comment
comment|/*  * Pseudo-tags don't normally need field bits since they  * are not written to an output file (by definition).  * The library also has express logic to always query a  * codec for a pseudo-tag so allocating a field bit for  * one is a waste.   If codec wants to promote the notion  * of a pseudo-tag being ``set'' or ``unset'' then it can  * do using internal state flags without polluting the  * field bit space defined for real tags.  */
end_comment
begin_define
DECL|macro|FIELD_PSEUDO
define|#
directive|define
name|FIELD_PSEUDO
value|0
end_define
begin_define
DECL|macro|FIELD_LAST
define|#
directive|define
name|FIELD_LAST
value|(32*FIELD_SETLONGS-1)
end_define
begin_define
DECL|macro|TIFFExtractData
define|#
directive|define
name|TIFFExtractData
parameter_list|(
name|tif
parameter_list|,
name|type
parameter_list|,
name|v
parameter_list|)
define|\
value|((uint32) ((tif)->tif_header.tiff_magic == TIFF_BIGENDIAN ? \         ((v)>> (tif)->tif_typeshift[type])& (tif)->tif_typemask[type] : \ 	(v)& (tif)->tif_typemask[type]))
end_define
begin_define
DECL|macro|TIFFInsertData
define|#
directive|define
name|TIFFInsertData
parameter_list|(
name|tif
parameter_list|,
name|type
parameter_list|,
name|v
parameter_list|)
define|\
value|((uint32) ((tif)->tif_header.tiff_magic == TIFF_BIGENDIAN ? \         ((v)& (tif)->tif_typemask[type])<< (tif)->tif_typeshift[type] : \ 	(v)& (tif)->tif_typemask[type]))
end_define
begin_define
DECL|macro|BITn
define|#
directive|define
name|BITn
parameter_list|(
name|n
parameter_list|)
value|(((unsigned long)1L)<<((n)&0x1f))
end_define
begin_define
DECL|macro|BITFIELDn
define|#
directive|define
name|BITFIELDn
parameter_list|(
name|tif
parameter_list|,
name|n
parameter_list|)
value|((tif)->tif_dir.td_fieldsset[(n)/32])
end_define
begin_define
DECL|macro|TIFFFieldSet
define|#
directive|define
name|TIFFFieldSet
parameter_list|(
name|tif
parameter_list|,
name|field
parameter_list|)
value|(BITFIELDn(tif, field)& BITn(field))
end_define
begin_define
DECL|macro|TIFFSetFieldBit
define|#
directive|define
name|TIFFSetFieldBit
parameter_list|(
name|tif
parameter_list|,
name|field
parameter_list|)
value|(BITFIELDn(tif, field) |= BITn(field))
end_define
begin_define
DECL|macro|TIFFClrFieldBit
define|#
directive|define
name|TIFFClrFieldBit
parameter_list|(
name|tif
parameter_list|,
name|field
parameter_list|)
value|(BITFIELDn(tif, field)&= ~BITn(field))
end_define
begin_define
DECL|macro|FieldSet
define|#
directive|define
name|FieldSet
parameter_list|(
name|fields
parameter_list|,
name|f
parameter_list|)
value|(fields[(f)/32]& BITn(f))
end_define
begin_define
DECL|macro|ResetFieldBit
define|#
directive|define
name|ResetFieldBit
parameter_list|(
name|fields
parameter_list|,
name|f
parameter_list|)
value|(fields[(f)/32]&= ~BITn(f))
end_define
begin_if
if|#
directive|if
name|defined
argument_list|(
name|__cplusplus
argument_list|)
end_if
begin_extern
extern|extern
literal|"C"
block|{
endif|#
directive|endif
specifier|extern
specifier|const
name|TIFFFieldInfo
modifier|*
name|_TIFFGetFieldInfo
parameter_list|(
name|size_t
modifier|*
parameter_list|)
function_decl|;
specifier|extern
specifier|const
name|TIFFFieldInfo
modifier|*
name|_TIFFGetExifFieldInfo
parameter_list|(
name|size_t
modifier|*
parameter_list|)
function_decl|;
specifier|extern
name|void
name|_TIFFSetupFieldInfo
parameter_list|(
name|TIFF
modifier|*
parameter_list|,
specifier|const
name|TIFFFieldInfo
index|[]
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
specifier|extern
name|int
name|_TIFFMergeFieldInfo
parameter_list|(
name|TIFF
modifier|*
parameter_list|,
specifier|const
name|TIFFFieldInfo
index|[]
parameter_list|,
name|int
parameter_list|)
function_decl|;
specifier|extern
name|void
name|_TIFFPrintFieldInfo
parameter_list|(
name|TIFF
modifier|*
parameter_list|,
name|FILE
modifier|*
parameter_list|)
function_decl|;
specifier|extern
name|TIFFDataType
name|_TIFFSampleToTagType
parameter_list|(
name|TIFF
modifier|*
parameter_list|)
function_decl|;
specifier|extern
specifier|const
name|TIFFFieldInfo
modifier|*
name|_TIFFFindOrRegisterFieldInfo
parameter_list|(
name|TIFF
modifier|*
name|tif
parameter_list|,
name|ttag_t
name|tag
parameter_list|,
name|TIFFDataType
name|dt
parameter_list|)
function_decl|;
specifier|extern
name|TIFFFieldInfo
modifier|*
name|_TIFFCreateAnonFieldInfo
parameter_list|(
name|TIFF
modifier|*
name|tif
parameter_list|,
name|ttag_t
name|tag
parameter_list|,
name|TIFFDataType
name|dt
parameter_list|)
function_decl|;
DECL|macro|_TIFFFindFieldInfo
define|#
directive|define
name|_TIFFFindFieldInfo
value|TIFFFindFieldInfo
DECL|macro|_TIFFFindFieldInfoByName
define|#
directive|define
name|_TIFFFindFieldInfoByName
value|TIFFFindFieldInfoByName
DECL|macro|_TIFFFieldWithTag
define|#
directive|define
name|_TIFFFieldWithTag
value|TIFFFieldWithTag
DECL|macro|_TIFFFieldWithName
define|#
directive|define
name|_TIFFFieldWithName
value|TIFFFieldWithName
if|#
directive|if
name|defined
argument_list|(
name|__cplusplus
argument_list|)
block|}
end_extern
begin_endif
endif|#
directive|endif
end_endif
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* _TIFFDIR_ */
end_comment
begin_comment
comment|/* vim: set ts=8 sts=8 sw=8 noet: */
end_comment
end_unit
