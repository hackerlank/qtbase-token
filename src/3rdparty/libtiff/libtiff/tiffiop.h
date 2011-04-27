begin_unit
begin_comment
comment|/* $Id: tiffiop.h,v 1.51.2.1 2009-01-06 19:08:09 bfriesen Exp $ */
end_comment
begin_comment
comment|/*  * Copyright (c) 1988-1997 Sam Leffler  * Copyright (c) 1991-1997 Silicon Graphics, Inc.  *  * Permission to use, copy, modify, distribute, and sell this software and   * its documentation for any purpose is hereby granted without fee, provided  * that (i) the above copyright notices and this permission notice appear in  * all copies of the software and related documentation, and (ii) the names of  * Sam Leffler and Silicon Graphics may not be used in any advertising or  * publicity relating to the software without the specific, prior written  * permission of Sam Leffler and Silicon Graphics.  *   * THE SOFTWARE IS PROVIDED "AS-IS" AND WITHOUT WARRANTY OF ANY KIND,   * EXPRESS, IMPLIED OR OTHERWISE, INCLUDING WITHOUT LIMITATION, ANY   * WARRANTY OF MERCHANTABILITY OR FITNESS FOR A PARTICULAR PURPOSE.    *   * IN NO EVENT SHALL SAM LEFFLER OR SILICON GRAPHICS BE LIABLE FOR  * ANY SPECIAL, INCIDENTAL, INDIRECT OR CONSEQUENTIAL DAMAGES OF ANY KIND,  * OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS,  * WHETHER OR NOT ADVISED OF THE POSSIBILITY OF DAMAGE, AND ON ANY THEORY OF   * LIABILITY, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE   * OF THIS SOFTWARE.  */
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|_TIFFIOP_
end_ifndef
begin_define
DECL|macro|_TIFFIOP_
define|#
directive|define
name|_TIFFIOP_
end_define
begin_comment
comment|/*  * ``Library-private'' definitions.  */
end_comment
begin_include
include|#
directive|include
file|"tif_config.h"
end_include
begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_FCNTL_H
end_ifdef
begin_include
include|#
directive|include
file|<fcntl.h>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SYS_TYPES_H
end_ifdef
begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|Q_OS_WINCE
argument_list|)
end_if
begin_include
include|#
directive|include
file|<sys/types.h>
end_include
begin_else
else|#
directive|else
end_else
begin_include
include|#
directive|include
file|<windows.h>
end_include
begin_include
include|#
directive|include
file|<types.h>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_endif
endif|#
directive|endif
end_endif
begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_STRING_H
end_ifdef
begin_include
include|#
directive|include
file|<string.h>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_ASSERT_H
end_ifdef
begin_include
include|#
directive|include
file|<assert.h>
end_include
begin_else
else|#
directive|else
end_else
begin_define
DECL|macro|assert
define|#
directive|define
name|assert
parameter_list|(
name|x
parameter_list|)
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SEARCH_H
end_ifdef
begin_include
include|#
directive|include
file|<search.h>
end_include
begin_else
else|#
directive|else
end_else
begin_function_decl
specifier|extern
name|void
modifier|*
name|lfind
parameter_list|(
specifier|const
name|void
modifier|*
parameter_list|,
specifier|const
name|void
modifier|*
parameter_list|,
name|size_t
modifier|*
parameter_list|,
name|size_t
parameter_list|,
name|int
function_decl|(
modifier|*
function_decl|)
parameter_list|(
specifier|const
name|void
modifier|*
parameter_list|,
specifier|const
name|void
modifier|*
parameter_list|)
parameter_list|)
function_decl|;
end_function_decl
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/*   Libtiff itself does not require a 64-bit type, but bundled TIFF   utilities may use it. */
end_comment
begin_typedef
DECL|typedef|int64
typedef|typedef
name|TIFF_INT64_T
name|int64
typedef|;
end_typedef
begin_typedef
DECL|typedef|uint64
typedef|typedef
name|TIFF_UINT64_T
name|uint64
typedef|;
end_typedef
begin_include
include|#
directive|include
file|"tiffio.h"
end_include
begin_include
include|#
directive|include
file|"tif_dir.h"
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|STRIP_SIZE_DEFAULT
end_ifndef
begin_define
DECL|macro|STRIP_SIZE_DEFAULT
define|#
directive|define
name|STRIP_SIZE_DEFAULT
value|8192
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_define
DECL|macro|streq
define|#
directive|define
name|streq
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|(strcmp(a,b) == 0)
end_define
begin_ifndef
ifndef|#
directive|ifndef
name|TRUE
end_ifndef
begin_define
DECL|macro|TRUE
define|#
directive|define
name|TRUE
value|1
end_define
begin_define
DECL|macro|FALSE
define|#
directive|define
name|FALSE
value|0
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_typedef
DECL|struct|client_info
typedef|typedef
struct|struct
name|client_info
block|{
DECL|member|next
name|struct
name|client_info
modifier|*
name|next
decl_stmt|;
DECL|member|data
name|void
modifier|*
name|data
decl_stmt|;
DECL|member|name
name|char
modifier|*
name|name
decl_stmt|;
block|}
DECL|typedef|TIFFClientInfoLink
name|TIFFClientInfoLink
typedef|;
end_typedef
begin_comment
comment|/*  * Typedefs for ``method pointers'' used internally.  */
end_comment
begin_typedef
DECL|typedef|tidataval_t
typedef|typedef
name|unsigned
name|char
name|tidataval_t
typedef|;
end_typedef
begin_comment
DECL|typedef|tidataval_t
comment|/* internal image data value type */
end_comment
begin_typedef
DECL|typedef|tidata_t
typedef|typedef
name|tidataval_t
modifier|*
name|tidata_t
typedef|;
end_typedef
begin_comment
DECL|typedef|tidata_t
comment|/* reference to internal image data */
end_comment
begin_typedef
DECL|typedef|TIFFVoidMethod
typedef|typedef
name|void
function_decl|(
modifier|*
name|TIFFVoidMethod
function_decl|)
parameter_list|(
name|TIFF
modifier|*
parameter_list|)
function_decl|;
end_typedef
begin_typedef
DECL|typedef|TIFFBoolMethod
typedef|typedef
name|int
function_decl|(
modifier|*
name|TIFFBoolMethod
function_decl|)
parameter_list|(
name|TIFF
modifier|*
parameter_list|)
function_decl|;
end_typedef
begin_typedef
DECL|typedef|TIFFPreMethod
typedef|typedef
name|int
function_decl|(
modifier|*
name|TIFFPreMethod
function_decl|)
parameter_list|(
name|TIFF
modifier|*
parameter_list|,
name|tsample_t
parameter_list|)
function_decl|;
end_typedef
begin_typedef
DECL|typedef|TIFFCodeMethod
typedef|typedef
name|int
function_decl|(
modifier|*
name|TIFFCodeMethod
function_decl|)
parameter_list|(
name|TIFF
modifier|*
parameter_list|,
name|tidata_t
parameter_list|,
name|tsize_t
parameter_list|,
name|tsample_t
parameter_list|)
function_decl|;
end_typedef
begin_typedef
DECL|typedef|TIFFSeekMethod
typedef|typedef
name|int
function_decl|(
modifier|*
name|TIFFSeekMethod
function_decl|)
parameter_list|(
name|TIFF
modifier|*
parameter_list|,
name|uint32
parameter_list|)
function_decl|;
end_typedef
begin_typedef
DECL|typedef|TIFFPostMethod
typedef|typedef
name|void
function_decl|(
modifier|*
name|TIFFPostMethod
function_decl|)
parameter_list|(
name|TIFF
modifier|*
parameter_list|,
name|tidata_t
parameter_list|,
name|tsize_t
parameter_list|)
function_decl|;
end_typedef
begin_typedef
DECL|typedef|TIFFStripMethod
typedef|typedef
name|uint32
function_decl|(
modifier|*
name|TIFFStripMethod
function_decl|)
parameter_list|(
name|TIFF
modifier|*
parameter_list|,
name|uint32
parameter_list|)
function_decl|;
end_typedef
begin_typedef
DECL|typedef|TIFFTileMethod
typedef|typedef
name|void
function_decl|(
modifier|*
name|TIFFTileMethod
function_decl|)
parameter_list|(
name|TIFF
modifier|*
parameter_list|,
name|uint32
modifier|*
parameter_list|,
name|uint32
modifier|*
parameter_list|)
function_decl|;
end_typedef
begin_struct
DECL|struct|tiff
struct|struct
name|tiff
block|{
DECL|member|tif_name
name|char
modifier|*
name|tif_name
decl_stmt|;
comment|/* name of open file */
DECL|member|tif_fd
name|int
name|tif_fd
decl_stmt|;
comment|/* open file descriptor */
DECL|member|tif_mode
name|int
name|tif_mode
decl_stmt|;
comment|/* open mode (O_*) */
DECL|member|tif_flags
name|uint32
name|tif_flags
decl_stmt|;
DECL|macro|TIFF_FILLORDER
define|#
directive|define
name|TIFF_FILLORDER
value|0x00003
comment|/* natural bit fill order for machine */
DECL|macro|TIFF_DIRTYHEADER
define|#
directive|define
name|TIFF_DIRTYHEADER
value|0x00004
comment|/* header must be written on close */
DECL|macro|TIFF_DIRTYDIRECT
define|#
directive|define
name|TIFF_DIRTYDIRECT
value|0x00008
comment|/* current directory must be written */
DECL|macro|TIFF_BUFFERSETUP
define|#
directive|define
name|TIFF_BUFFERSETUP
value|0x00010
comment|/* data buffers setup */
DECL|macro|TIFF_CODERSETUP
define|#
directive|define
name|TIFF_CODERSETUP
value|0x00020
comment|/* encoder/decoder setup done */
DECL|macro|TIFF_BEENWRITING
define|#
directive|define
name|TIFF_BEENWRITING
value|0x00040
comment|/* written 1+ scanlines to file */
DECL|macro|TIFF_SWAB
define|#
directive|define
name|TIFF_SWAB
value|0x00080
comment|/* byte swap file information */
DECL|macro|TIFF_NOBITREV
define|#
directive|define
name|TIFF_NOBITREV
value|0x00100
comment|/* inhibit bit reversal logic */
DECL|macro|TIFF_MYBUFFER
define|#
directive|define
name|TIFF_MYBUFFER
value|0x00200
comment|/* my raw data buffer; free on close */
DECL|macro|TIFF_ISTILED
define|#
directive|define
name|TIFF_ISTILED
value|0x00400
comment|/* file is tile, not strip- based */
DECL|macro|TIFF_MAPPED
define|#
directive|define
name|TIFF_MAPPED
value|0x00800
comment|/* file is mapped into memory */
DECL|macro|TIFF_POSTENCODE
define|#
directive|define
name|TIFF_POSTENCODE
value|0x01000
comment|/* need call to postencode routine */
DECL|macro|TIFF_INSUBIFD
define|#
directive|define
name|TIFF_INSUBIFD
value|0x02000
comment|/* currently writing a subifd */
DECL|macro|TIFF_UPSAMPLED
define|#
directive|define
name|TIFF_UPSAMPLED
value|0x04000
comment|/* library is doing data up-sampling */
DECL|macro|TIFF_STRIPCHOP
define|#
directive|define
name|TIFF_STRIPCHOP
value|0x08000
comment|/* enable strip chopping support */
DECL|macro|TIFF_HEADERONLY
define|#
directive|define
name|TIFF_HEADERONLY
value|0x10000
comment|/* read header only, do not process */
comment|/* the first directory */
DECL|macro|TIFF_NOREADRAW
define|#
directive|define
name|TIFF_NOREADRAW
value|0x20000
comment|/* skip reading of raw uncompressed */
comment|/* image data */
DECL|macro|TIFF_INCUSTOMIFD
define|#
directive|define
name|TIFF_INCUSTOMIFD
value|0x40000
comment|/* currently writing a custom IFD */
DECL|member|tif_diroff
name|toff_t
name|tif_diroff
decl_stmt|;
comment|/* file offset of current directory */
DECL|member|tif_nextdiroff
name|toff_t
name|tif_nextdiroff
decl_stmt|;
comment|/* file offset of following directory */
DECL|member|tif_dirlist
name|toff_t
modifier|*
name|tif_dirlist
decl_stmt|;
comment|/* list of offsets to already seen */
comment|/* directories to prevent IFD looping */
DECL|member|tif_dirlistsize
name|tsize_t
name|tif_dirlistsize
decl_stmt|;
comment|/* number of entires in offset list */
DECL|member|tif_dirnumber
name|uint16
name|tif_dirnumber
decl_stmt|;
comment|/* number of already seen directories */
DECL|member|tif_dir
name|TIFFDirectory
name|tif_dir
decl_stmt|;
comment|/* internal rep of current directory */
DECL|member|tif_customdir
name|TIFFDirectory
name|tif_customdir
decl_stmt|;
comment|/* custom IFDs are separated from 					   the main ones */
DECL|member|tif_header
name|TIFFHeader
name|tif_header
decl_stmt|;
comment|/* file's header block */
DECL|member|tif_typeshift
specifier|const
name|int
modifier|*
name|tif_typeshift
decl_stmt|;
comment|/* data type shift counts */
DECL|member|tif_typemask
specifier|const
name|long
modifier|*
name|tif_typemask
decl_stmt|;
comment|/* data type masks */
DECL|member|tif_row
name|uint32
name|tif_row
decl_stmt|;
comment|/* current scanline */
DECL|member|tif_curdir
name|tdir_t
name|tif_curdir
decl_stmt|;
comment|/* current directory (index) */
DECL|member|tif_curstrip
name|tstrip_t
name|tif_curstrip
decl_stmt|;
comment|/* current strip for read/write */
DECL|member|tif_curoff
name|toff_t
name|tif_curoff
decl_stmt|;
comment|/* current offset for read/write */
DECL|member|tif_dataoff
name|toff_t
name|tif_dataoff
decl_stmt|;
comment|/* current offset for writing dir */
comment|/* SubIFD support */
DECL|member|tif_nsubifd
name|uint16
name|tif_nsubifd
decl_stmt|;
comment|/* remaining subifds to write */
DECL|member|tif_subifdoff
name|toff_t
name|tif_subifdoff
decl_stmt|;
comment|/* offset for patching SubIFD link */
comment|/* tiling support */
DECL|member|tif_col
name|uint32
name|tif_col
decl_stmt|;
comment|/* current column (offset by row too) */
DECL|member|tif_curtile
name|ttile_t
name|tif_curtile
decl_stmt|;
comment|/* current tile for read/write */
DECL|member|tif_tilesize
name|tsize_t
name|tif_tilesize
decl_stmt|;
comment|/* # of bytes in a tile */
comment|/* compression scheme hooks */
DECL|member|tif_decodestatus
name|int
name|tif_decodestatus
decl_stmt|;
DECL|member|tif_setupdecode
name|TIFFBoolMethod
name|tif_setupdecode
decl_stmt|;
comment|/* called once before predecode */
DECL|member|tif_predecode
name|TIFFPreMethod
name|tif_predecode
decl_stmt|;
comment|/* pre- row/strip/tile decoding */
DECL|member|tif_setupencode
name|TIFFBoolMethod
name|tif_setupencode
decl_stmt|;
comment|/* called once before preencode */
DECL|member|tif_encodestatus
name|int
name|tif_encodestatus
decl_stmt|;
DECL|member|tif_preencode
name|TIFFPreMethod
name|tif_preencode
decl_stmt|;
comment|/* pre- row/strip/tile encoding */
DECL|member|tif_postencode
name|TIFFBoolMethod
name|tif_postencode
decl_stmt|;
comment|/* post- row/strip/tile encoding */
DECL|member|tif_decoderow
name|TIFFCodeMethod
name|tif_decoderow
decl_stmt|;
comment|/* scanline decoding routine */
DECL|member|tif_encoderow
name|TIFFCodeMethod
name|tif_encoderow
decl_stmt|;
comment|/* scanline encoding routine */
DECL|member|tif_decodestrip
name|TIFFCodeMethod
name|tif_decodestrip
decl_stmt|;
comment|/* strip decoding routine */
DECL|member|tif_encodestrip
name|TIFFCodeMethod
name|tif_encodestrip
decl_stmt|;
comment|/* strip encoding routine */
DECL|member|tif_decodetile
name|TIFFCodeMethod
name|tif_decodetile
decl_stmt|;
comment|/* tile decoding routine */
DECL|member|tif_encodetile
name|TIFFCodeMethod
name|tif_encodetile
decl_stmt|;
comment|/* tile encoding routine */
DECL|member|tif_close
name|TIFFVoidMethod
name|tif_close
decl_stmt|;
comment|/* cleanup-on-close routine */
DECL|member|tif_seek
name|TIFFSeekMethod
name|tif_seek
decl_stmt|;
comment|/* position within a strip routine */
DECL|member|tif_cleanup
name|TIFFVoidMethod
name|tif_cleanup
decl_stmt|;
comment|/* cleanup state routine */
DECL|member|tif_defstripsize
name|TIFFStripMethod
name|tif_defstripsize
decl_stmt|;
comment|/* calculate/constrain strip size */
DECL|member|tif_deftilesize
name|TIFFTileMethod
name|tif_deftilesize
decl_stmt|;
comment|/* calculate/constrain tile size */
DECL|member|tif_data
name|tidata_t
name|tif_data
decl_stmt|;
comment|/* compression scheme private data */
comment|/* input/output buffering */
DECL|member|tif_scanlinesize
name|tsize_t
name|tif_scanlinesize
decl_stmt|;
comment|/* # of bytes in a scanline */
DECL|member|tif_scanlineskew
name|tsize_t
name|tif_scanlineskew
decl_stmt|;
comment|/* scanline skew for reading strips */
DECL|member|tif_rawdata
name|tidata_t
name|tif_rawdata
decl_stmt|;
comment|/* raw data buffer */
DECL|member|tif_rawdatasize
name|tsize_t
name|tif_rawdatasize
decl_stmt|;
comment|/* # of bytes in raw data buffer */
DECL|member|tif_rawcp
name|tidata_t
name|tif_rawcp
decl_stmt|;
comment|/* current spot in raw buffer */
DECL|member|tif_rawcc
name|tsize_t
name|tif_rawcc
decl_stmt|;
comment|/* bytes unread from raw buffer */
comment|/* memory-mapped file support */
DECL|member|tif_base
name|tidata_t
name|tif_base
decl_stmt|;
comment|/* base of mapped file */
DECL|member|tif_size
name|toff_t
name|tif_size
decl_stmt|;
comment|/* size of mapped file region (bytes) 					   FIXME: it should be tsize_t */
DECL|member|tif_mapproc
name|TIFFMapFileProc
name|tif_mapproc
decl_stmt|;
comment|/* map file method */
DECL|member|tif_unmapproc
name|TIFFUnmapFileProc
name|tif_unmapproc
decl_stmt|;
comment|/* unmap file method */
comment|/* input/output callback methods */
DECL|member|tif_clientdata
name|thandle_t
name|tif_clientdata
decl_stmt|;
comment|/* callback parameter */
DECL|member|tif_readproc
name|TIFFReadWriteProc
name|tif_readproc
decl_stmt|;
comment|/* read method */
DECL|member|tif_writeproc
name|TIFFReadWriteProc
name|tif_writeproc
decl_stmt|;
comment|/* write method */
DECL|member|tif_seekproc
name|TIFFSeekProc
name|tif_seekproc
decl_stmt|;
comment|/* lseek method */
DECL|member|tif_closeproc
name|TIFFCloseProc
name|tif_closeproc
decl_stmt|;
comment|/* close method */
DECL|member|tif_sizeproc
name|TIFFSizeProc
name|tif_sizeproc
decl_stmt|;
comment|/* filesize method */
comment|/* post-decoding support */
DECL|member|tif_postdecode
name|TIFFPostMethod
name|tif_postdecode
decl_stmt|;
comment|/* post decoding routine */
comment|/* tag support */
DECL|member|tif_fieldinfo
name|TIFFFieldInfo
modifier|*
modifier|*
name|tif_fieldinfo
decl_stmt|;
comment|/* sorted table of registered tags */
DECL|member|tif_nfields
name|size_t
name|tif_nfields
decl_stmt|;
comment|/* # entries in registered tag table */
DECL|member|tif_foundfield
specifier|const
name|TIFFFieldInfo
modifier|*
name|tif_foundfield
decl_stmt|;
comment|/* cached pointer to already found tag */
DECL|member|tif_tagmethods
name|TIFFTagMethods
name|tif_tagmethods
decl_stmt|;
comment|/* tag get/set/print routines */
DECL|member|tif_clientinfo
name|TIFFClientInfoLink
modifier|*
name|tif_clientinfo
decl_stmt|;
comment|/* extra client information. */
block|}
struct|;
end_struct
begin_define
DECL|macro|isPseudoTag
define|#
directive|define
name|isPseudoTag
parameter_list|(
name|t
parameter_list|)
value|(t> 0xffff)
end_define
begin_comment
DECL|macro|isPseudoTag
comment|/* is tag value normal or pseudo */
end_comment
begin_define
DECL|macro|isTiled
define|#
directive|define
name|isTiled
parameter_list|(
name|tif
parameter_list|)
value|(((tif)->tif_flags& TIFF_ISTILED) != 0)
end_define
begin_define
DECL|macro|isMapped
define|#
directive|define
name|isMapped
parameter_list|(
name|tif
parameter_list|)
value|(((tif)->tif_flags& TIFF_MAPPED) != 0)
end_define
begin_define
DECL|macro|isFillOrder
define|#
directive|define
name|isFillOrder
parameter_list|(
name|tif
parameter_list|,
name|o
parameter_list|)
value|(((tif)->tif_flags& (o)) != 0)
end_define
begin_define
DECL|macro|isUpSampled
define|#
directive|define
name|isUpSampled
parameter_list|(
name|tif
parameter_list|)
value|(((tif)->tif_flags& TIFF_UPSAMPLED) != 0)
end_define
begin_define
DECL|macro|TIFFReadFile
define|#
directive|define
name|TIFFReadFile
parameter_list|(
name|tif
parameter_list|,
name|buf
parameter_list|,
name|size
parameter_list|)
define|\
value|((*(tif)->tif_readproc)((tif)->tif_clientdata,buf,size))
end_define
begin_define
DECL|macro|TIFFWriteFile
define|#
directive|define
name|TIFFWriteFile
parameter_list|(
name|tif
parameter_list|,
name|buf
parameter_list|,
name|size
parameter_list|)
define|\
value|((*(tif)->tif_writeproc)((tif)->tif_clientdata,buf,size))
end_define
begin_define
DECL|macro|TIFFSeekFile
define|#
directive|define
name|TIFFSeekFile
parameter_list|(
name|tif
parameter_list|,
name|off
parameter_list|,
name|whence
parameter_list|)
define|\
value|((*(tif)->tif_seekproc)((tif)->tif_clientdata,(toff_t)(off),whence))
end_define
begin_define
DECL|macro|TIFFCloseFile
define|#
directive|define
name|TIFFCloseFile
parameter_list|(
name|tif
parameter_list|)
define|\
value|((*(tif)->tif_closeproc)((tif)->tif_clientdata))
end_define
begin_define
DECL|macro|TIFFGetFileSize
define|#
directive|define
name|TIFFGetFileSize
parameter_list|(
name|tif
parameter_list|)
define|\
value|((*(tif)->tif_sizeproc)((tif)->tif_clientdata))
end_define
begin_define
DECL|macro|TIFFMapFileContents
define|#
directive|define
name|TIFFMapFileContents
parameter_list|(
name|tif
parameter_list|,
name|paddr
parameter_list|,
name|psize
parameter_list|)
define|\
value|((*(tif)->tif_mapproc)((tif)->tif_clientdata,paddr,psize))
end_define
begin_define
DECL|macro|TIFFUnmapFileContents
define|#
directive|define
name|TIFFUnmapFileContents
parameter_list|(
name|tif
parameter_list|,
name|addr
parameter_list|,
name|size
parameter_list|)
define|\
value|((*(tif)->tif_unmapproc)((tif)->tif_clientdata,addr,size))
end_define
begin_comment
comment|/*  * Default Read/Seek/Write definitions.  */
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|ReadOK
end_ifndef
begin_define
DECL|macro|ReadOK
define|#
directive|define
name|ReadOK
parameter_list|(
name|tif
parameter_list|,
name|buf
parameter_list|,
name|size
parameter_list|)
define|\
value|(TIFFReadFile(tif, (tdata_t) buf, (tsize_t)(size)) == (tsize_t)(size))
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|SeekOK
end_ifndef
begin_define
DECL|macro|SeekOK
define|#
directive|define
name|SeekOK
parameter_list|(
name|tif
parameter_list|,
name|off
parameter_list|)
define|\
value|(TIFFSeekFile(tif, (toff_t) off, SEEK_SET) == (toff_t) off)
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|WriteOK
end_ifndef
begin_define
DECL|macro|WriteOK
define|#
directive|define
name|WriteOK
parameter_list|(
name|tif
parameter_list|,
name|buf
parameter_list|,
name|size
parameter_list|)
define|\
value|(TIFFWriteFile(tif, (tdata_t) buf, (tsize_t) size) == (tsize_t) size)
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* NB: the uint32 casts are to silence certain ANSI-C compilers */
end_comment
begin_define
DECL|macro|TIFFhowmany
define|#
directive|define
name|TIFFhowmany
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|((((uint32)(x))+(((uint32)(y))-1))/((uint32)(y)))
end_define
begin_define
DECL|macro|TIFFhowmany8
define|#
directive|define
name|TIFFhowmany8
parameter_list|(
name|x
parameter_list|)
value|(((x)&0x07)?((uint32)(x)>>3)+1:(uint32)(x)>>3)
end_define
begin_define
DECL|macro|TIFFroundup
define|#
directive|define
name|TIFFroundup
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|(TIFFhowmany(x,y)*(y))
end_define
begin_define
DECL|macro|TIFFmax
define|#
directive|define
name|TIFFmax
parameter_list|(
name|A
parameter_list|,
name|B
parameter_list|)
value|((A)>(B)?(A):(B))
end_define
begin_define
DECL|macro|TIFFmin
define|#
directive|define
name|TIFFmin
parameter_list|(
name|A
parameter_list|,
name|B
parameter_list|)
value|((A)<(B)?(A):(B))
end_define
begin_define
DECL|macro|TIFFArrayCount
define|#
directive|define
name|TIFFArrayCount
parameter_list|(
name|a
parameter_list|)
value|(sizeof (a) / sizeof ((a)[0]))
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
name|int
name|_TIFFgetMode
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
specifier|extern
name|int
name|_TIFFNoRowEncode
parameter_list|(
name|TIFF
modifier|*
parameter_list|,
name|tidata_t
parameter_list|,
name|tsize_t
parameter_list|,
name|tsample_t
parameter_list|)
function_decl|;
specifier|extern
name|int
name|_TIFFNoStripEncode
parameter_list|(
name|TIFF
modifier|*
parameter_list|,
name|tidata_t
parameter_list|,
name|tsize_t
parameter_list|,
name|tsample_t
parameter_list|)
function_decl|;
specifier|extern
name|int
name|_TIFFNoTileEncode
parameter_list|(
name|TIFF
modifier|*
parameter_list|,
name|tidata_t
parameter_list|,
name|tsize_t
parameter_list|,
name|tsample_t
parameter_list|)
function_decl|;
specifier|extern
name|int
name|_TIFFNoRowDecode
parameter_list|(
name|TIFF
modifier|*
parameter_list|,
name|tidata_t
parameter_list|,
name|tsize_t
parameter_list|,
name|tsample_t
parameter_list|)
function_decl|;
specifier|extern
name|int
name|_TIFFNoStripDecode
parameter_list|(
name|TIFF
modifier|*
parameter_list|,
name|tidata_t
parameter_list|,
name|tsize_t
parameter_list|,
name|tsample_t
parameter_list|)
function_decl|;
specifier|extern
name|int
name|_TIFFNoTileDecode
parameter_list|(
name|TIFF
modifier|*
parameter_list|,
name|tidata_t
parameter_list|,
name|tsize_t
parameter_list|,
name|tsample_t
parameter_list|)
function_decl|;
specifier|extern
name|void
name|_TIFFNoPostDecode
parameter_list|(
name|TIFF
modifier|*
parameter_list|,
name|tidata_t
parameter_list|,
name|tsize_t
parameter_list|)
function_decl|;
specifier|extern
name|int
name|_TIFFNoPreCode
parameter_list|(
name|TIFF
modifier|*
parameter_list|,
name|tsample_t
parameter_list|)
function_decl|;
specifier|extern
name|int
name|_TIFFNoSeek
parameter_list|(
name|TIFF
modifier|*
parameter_list|,
name|uint32
parameter_list|)
function_decl|;
specifier|extern
name|void
name|_TIFFSwab16BitData
parameter_list|(
name|TIFF
modifier|*
parameter_list|,
name|tidata_t
parameter_list|,
name|tsize_t
parameter_list|)
function_decl|;
specifier|extern
name|void
name|_TIFFSwab24BitData
parameter_list|(
name|TIFF
modifier|*
parameter_list|,
name|tidata_t
parameter_list|,
name|tsize_t
parameter_list|)
function_decl|;
specifier|extern
name|void
name|_TIFFSwab32BitData
parameter_list|(
name|TIFF
modifier|*
parameter_list|,
name|tidata_t
parameter_list|,
name|tsize_t
parameter_list|)
function_decl|;
specifier|extern
name|void
name|_TIFFSwab64BitData
parameter_list|(
name|TIFF
modifier|*
parameter_list|,
name|tidata_t
parameter_list|,
name|tsize_t
parameter_list|)
function_decl|;
specifier|extern
name|int
name|TIFFFlushData1
parameter_list|(
name|TIFF
modifier|*
parameter_list|)
function_decl|;
specifier|extern
name|int
name|TIFFDefaultDirectory
parameter_list|(
name|TIFF
modifier|*
parameter_list|)
function_decl|;
specifier|extern
name|void
name|_TIFFSetDefaultCompressionState
parameter_list|(
name|TIFF
modifier|*
parameter_list|)
function_decl|;
specifier|extern
name|int
name|TIFFSetCompressionScheme
parameter_list|(
name|TIFF
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
specifier|extern
name|int
name|TIFFSetDefaultCompressionState
parameter_list|(
name|TIFF
modifier|*
parameter_list|)
function_decl|;
specifier|extern
name|uint32
name|_TIFFDefaultStripSize
parameter_list|(
name|TIFF
modifier|*
parameter_list|,
name|uint32
parameter_list|)
function_decl|;
specifier|extern
name|void
name|_TIFFDefaultTileSize
parameter_list|(
name|TIFF
modifier|*
parameter_list|,
name|uint32
modifier|*
parameter_list|,
name|uint32
modifier|*
parameter_list|)
function_decl|;
specifier|extern
name|int
name|_TIFFDataSize
parameter_list|(
name|TIFFDataType
parameter_list|)
function_decl|;
specifier|extern
name|void
name|_TIFFsetByteArray
parameter_list|(
name|void
modifier|*
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
name|uint32
parameter_list|)
function_decl|;
specifier|extern
name|void
name|_TIFFsetString
parameter_list|(
name|char
modifier|*
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
specifier|extern
name|void
name|_TIFFsetShortArray
parameter_list|(
name|uint16
modifier|*
modifier|*
parameter_list|,
name|uint16
modifier|*
parameter_list|,
name|uint32
parameter_list|)
function_decl|;
specifier|extern
name|void
name|_TIFFsetLongArray
parameter_list|(
name|uint32
modifier|*
modifier|*
parameter_list|,
name|uint32
modifier|*
parameter_list|,
name|uint32
parameter_list|)
function_decl|;
specifier|extern
name|void
name|_TIFFsetFloatArray
parameter_list|(
name|float
modifier|*
modifier|*
parameter_list|,
name|float
modifier|*
parameter_list|,
name|uint32
parameter_list|)
function_decl|;
specifier|extern
name|void
name|_TIFFsetDoubleArray
parameter_list|(
name|double
modifier|*
modifier|*
parameter_list|,
name|double
modifier|*
parameter_list|,
name|uint32
parameter_list|)
function_decl|;
specifier|extern
name|void
name|_TIFFprintAscii
parameter_list|(
name|FILE
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
specifier|extern
name|void
name|_TIFFprintAsciiTag
parameter_list|(
name|FILE
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
specifier|extern
name|TIFFErrorHandler
name|_TIFFwarningHandler
decl_stmt|;
specifier|extern
name|TIFFErrorHandler
name|_TIFFerrorHandler
decl_stmt|;
specifier|extern
name|TIFFErrorHandlerExt
name|_TIFFwarningHandlerExt
decl_stmt|;
specifier|extern
name|TIFFErrorHandlerExt
name|_TIFFerrorHandlerExt
decl_stmt|;
specifier|extern
name|tdata_t
name|_TIFFCheckMalloc
parameter_list|(
name|TIFF
modifier|*
parameter_list|,
name|size_t
parameter_list|,
name|size_t
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
specifier|extern
name|tdata_t
name|_TIFFCheckRealloc
parameter_list|(
name|TIFF
modifier|*
parameter_list|,
name|tdata_t
parameter_list|,
name|size_t
parameter_list|,
name|size_t
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
specifier|extern
name|int
name|TIFFInitDumpMode
parameter_list|(
name|TIFF
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
ifdef|#
directive|ifdef
name|PACKBITS_SUPPORT
specifier|extern
name|int
name|TIFFInitPackBits
parameter_list|(
name|TIFF
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|CCITT_SUPPORT
specifier|extern
name|int
name|TIFFInitCCITTRLE
argument_list|(
name|TIFF
operator|*
argument_list|,
name|int
argument_list|)
decl_stmt|,
name|TIFFInitCCITTRLEW
argument_list|(
name|TIFF
operator|*
argument_list|,
name|int
argument_list|)
decl_stmt|;
specifier|extern
name|int
name|TIFFInitCCITTFax3
argument_list|(
name|TIFF
operator|*
argument_list|,
name|int
argument_list|)
decl_stmt|,
name|TIFFInitCCITTFax4
argument_list|(
name|TIFF
operator|*
argument_list|,
name|int
argument_list|)
decl_stmt|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|THUNDER_SUPPORT
specifier|extern
name|int
name|TIFFInitThunderScan
parameter_list|(
name|TIFF
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|NEXT_SUPPORT
specifier|extern
name|int
name|TIFFInitNeXT
parameter_list|(
name|TIFF
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|LZW_SUPPORT
specifier|extern
name|int
name|TIFFInitLZW
parameter_list|(
name|TIFF
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|OJPEG_SUPPORT
specifier|extern
name|int
name|TIFFInitOJPEG
parameter_list|(
name|TIFF
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|JPEG_SUPPORT
specifier|extern
name|int
name|TIFFInitJPEG
parameter_list|(
name|TIFF
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|JBIG_SUPPORT
specifier|extern
name|int
name|TIFFInitJBIG
parameter_list|(
name|TIFF
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|ZIP_SUPPORT
specifier|extern
name|int
name|TIFFInitZIP
parameter_list|(
name|TIFF
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|PIXARLOG_SUPPORT
specifier|extern
name|int
name|TIFFInitPixarLog
parameter_list|(
name|TIFF
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|LOGLUV_SUPPORT
specifier|extern
name|int
name|TIFFInitSGILog
parameter_list|(
name|TIFF
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|VMS
specifier|extern
specifier|const
name|TIFFCodec
name|_TIFFBuiltinCODECS
index|[]
decl_stmt|;
else|#
directive|else
specifier|extern
name|TIFFCodec
name|_TIFFBuiltinCODECS
index|[]
decl_stmt|;
endif|#
directive|endif
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
comment|/* _TIFFIOP_ */
end_comment
begin_comment
comment|/* vim: set ts=8 sts=8 sw=8 noet: */
end_comment
end_unit
