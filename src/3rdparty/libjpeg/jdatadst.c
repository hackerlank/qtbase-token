begin_unit
begin_comment
comment|/*  * jdatadst.c  *  * Copyright (C) 1994-1996, Thomas G. Lane.  * Modified 2009 by Guido Vollbeding.  * This file is part of the Independent JPEG Group's software.  * For conditions of distribution and use, see the accompanying README file.  *  * This file contains compression data destination routines for the case of  * emitting JPEG data to memory or to a file (or any stdio stream).  * While these routines are sufficient for most applications,  * some will want to use a different destination manager.  * IMPORTANT: we assume that fwrite() will correctly transcribe an array of  * JOCTETs into 8-bit-wide elements on external storage.  If char is wider  * than 8 bits on your machine, you may need to do some tweaking.  */
end_comment
begin_comment
comment|/* this is not a core library module, so it doesn't define JPEG_INTERNALS */
end_comment
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
begin_include
include|#
directive|include
file|"jerror.h"
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_STDLIB_H
end_ifndef
begin_comment
comment|/*<stdlib.h> should declare malloc(),free() */
end_comment
begin_decl_stmt
specifier|extern
name|void
modifier|*
name|malloc
name|JPP
argument_list|(
operator|(
name|size_t
name|size
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt
begin_decl_stmt
specifier|extern
name|void
name|free
name|JPP
argument_list|(
operator|(
name|void
operator|*
name|ptr
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* Expanded data destination object for stdio output */
end_comment
begin_typedef
typedef|typedef
struct|struct
block|{
DECL|member|pub
name|struct
name|jpeg_destination_mgr
name|pub
decl_stmt|;
comment|/* public fields */
DECL|member|outfile
name|FILE
modifier|*
name|outfile
decl_stmt|;
comment|/* target stream */
DECL|member|buffer
name|JOCTET
modifier|*
name|buffer
decl_stmt|;
comment|/* start of buffer */
block|}
DECL|typedef|my_destination_mgr
name|my_destination_mgr
typedef|;
end_typedef
begin_typedef
DECL|typedef|my_dest_ptr
typedef|typedef
name|my_destination_mgr
modifier|*
name|my_dest_ptr
typedef|;
end_typedef
begin_define
DECL|macro|OUTPUT_BUF_SIZE
define|#
directive|define
name|OUTPUT_BUF_SIZE
value|4096
end_define
begin_comment
DECL|macro|OUTPUT_BUF_SIZE
comment|/* choose an efficiently fwrite'able size */
end_comment
begin_comment
comment|/* Expanded data destination object for memory output */
end_comment
begin_typedef
typedef|typedef
struct|struct
block|{
DECL|member|pub
name|struct
name|jpeg_destination_mgr
name|pub
decl_stmt|;
comment|/* public fields */
DECL|member|outbuffer
name|unsigned
name|char
modifier|*
modifier|*
name|outbuffer
decl_stmt|;
comment|/* target buffer */
DECL|member|outsize
name|unsigned
name|long
modifier|*
name|outsize
decl_stmt|;
DECL|member|newbuffer
name|unsigned
name|char
modifier|*
name|newbuffer
decl_stmt|;
comment|/* newly allocated buffer */
DECL|member|buffer
name|JOCTET
modifier|*
name|buffer
decl_stmt|;
comment|/* start of buffer */
DECL|member|bufsize
name|size_t
name|bufsize
decl_stmt|;
block|}
DECL|typedef|my_mem_destination_mgr
name|my_mem_destination_mgr
typedef|;
end_typedef
begin_typedef
DECL|typedef|my_mem_dest_ptr
typedef|typedef
name|my_mem_destination_mgr
modifier|*
name|my_mem_dest_ptr
typedef|;
end_typedef
begin_comment
comment|/*  * Initialize destination --- called by jpeg_start_compress  * before any data is actually written.  */
end_comment
begin_macro
name|METHODDEF
argument_list|(
argument|void
argument_list|)
end_macro
begin_macro
DECL|function|init_destination
name|init_destination
argument_list|(
argument|j_compress_ptr cinfo
argument_list|)
end_macro
begin_block
block|{
name|my_dest_ptr
name|dest
init|=
operator|(
name|my_dest_ptr
operator|)
name|cinfo
operator|->
name|dest
decl_stmt|;
comment|/* Allocate the output buffer --- it will be released when done with image */
name|dest
operator|->
name|buffer
operator|=
operator|(
name|JOCTET
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
name|OUTPUT_BUF_SIZE
operator|*
name|SIZEOF
argument_list|(
name|JOCTET
argument_list|)
argument_list|)
expr_stmt|;
name|dest
operator|->
name|pub
operator|.
name|next_output_byte
operator|=
name|dest
operator|->
name|buffer
expr_stmt|;
name|dest
operator|->
name|pub
operator|.
name|free_in_buffer
operator|=
name|OUTPUT_BUF_SIZE
expr_stmt|;
block|}
end_block
begin_macro
name|METHODDEF
argument_list|(
argument|void
argument_list|)
end_macro
begin_macro
DECL|function|init_mem_destination
name|init_mem_destination
argument_list|(
argument|j_compress_ptr cinfo
argument_list|)
end_macro
begin_block
block|{
comment|/* no work necessary here */
block|}
end_block
begin_comment
comment|/*  * Empty the output buffer --- called whenever buffer fills up.  *  * In typical applications, this should write the entire output buffer  * (ignoring the current state of next_output_byte& free_in_buffer),  * reset the pointer& count to the start of the buffer, and return TRUE  * indicating that the buffer has been dumped.  *  * In applications that need to be able to suspend compression due to output  * overrun, a FALSE return indicates that the buffer cannot be emptied now.  * In this situation, the compressor will return to its caller (possibly with  * an indication that it has not accepted all the supplied scanlines).  The  * application should resume compression after it has made more room in the  * output buffer.  Note that there are substantial restrictions on the use of  * suspension --- see the documentation.  *  * When suspending, the compressor will back up to a convenient restart point  * (typically the start of the current MCU). next_output_byte& free_in_buffer  * indicate where the restart point will be if the current call returns FALSE.  * Data beyond this point will be regenerated after resumption, so do not  * write it out when emptying the buffer externally.  */
end_comment
begin_macro
DECL|function|METHODDEF
name|METHODDEF
argument_list|(
argument|boolean
argument_list|)
end_macro
begin_macro
name|empty_output_buffer
argument_list|(
argument|j_compress_ptr cinfo
argument_list|)
end_macro
begin_block
block|{
name|my_dest_ptr
name|dest
init|=
operator|(
name|my_dest_ptr
operator|)
name|cinfo
operator|->
name|dest
decl_stmt|;
if|if
condition|(
name|JFWRITE
argument_list|(
name|dest
operator|->
name|outfile
argument_list|,
name|dest
operator|->
name|buffer
argument_list|,
name|OUTPUT_BUF_SIZE
argument_list|)
operator|!=
operator|(
name|size_t
operator|)
name|OUTPUT_BUF_SIZE
condition|)
name|ERREXIT
argument_list|(
name|cinfo
argument_list|,
name|JERR_FILE_WRITE
argument_list|)
expr_stmt|;
name|dest
operator|->
name|pub
operator|.
name|next_output_byte
operator|=
name|dest
operator|->
name|buffer
expr_stmt|;
name|dest
operator|->
name|pub
operator|.
name|free_in_buffer
operator|=
name|OUTPUT_BUF_SIZE
expr_stmt|;
return|return
name|TRUE
return|;
block|}
end_block
begin_macro
DECL|function|METHODDEF
name|METHODDEF
argument_list|(
argument|boolean
argument_list|)
end_macro
begin_macro
name|empty_mem_output_buffer
argument_list|(
argument|j_compress_ptr cinfo
argument_list|)
end_macro
begin_block
block|{
name|size_t
name|nextsize
decl_stmt|;
name|JOCTET
modifier|*
name|nextbuffer
decl_stmt|;
name|my_mem_dest_ptr
name|dest
init|=
operator|(
name|my_mem_dest_ptr
operator|)
name|cinfo
operator|->
name|dest
decl_stmt|;
comment|/* Try to allocate new buffer with double size */
name|nextsize
operator|=
name|dest
operator|->
name|bufsize
operator|*
literal|2
expr_stmt|;
name|nextbuffer
operator|=
name|malloc
argument_list|(
name|nextsize
argument_list|)
expr_stmt|;
if|if
condition|(
name|nextbuffer
operator|==
name|NULL
condition|)
name|ERREXIT1
argument_list|(
name|cinfo
argument_list|,
name|JERR_OUT_OF_MEMORY
argument_list|,
literal|10
argument_list|)
expr_stmt|;
name|MEMCOPY
argument_list|(
name|nextbuffer
argument_list|,
name|dest
operator|->
name|buffer
argument_list|,
name|dest
operator|->
name|bufsize
argument_list|)
expr_stmt|;
if|if
condition|(
name|dest
operator|->
name|newbuffer
operator|!=
name|NULL
condition|)
name|free
argument_list|(
name|dest
operator|->
name|newbuffer
argument_list|)
expr_stmt|;
name|dest
operator|->
name|newbuffer
operator|=
name|nextbuffer
expr_stmt|;
name|dest
operator|->
name|pub
operator|.
name|next_output_byte
operator|=
name|nextbuffer
operator|+
name|dest
operator|->
name|bufsize
expr_stmt|;
name|dest
operator|->
name|pub
operator|.
name|free_in_buffer
operator|=
name|dest
operator|->
name|bufsize
expr_stmt|;
name|dest
operator|->
name|buffer
operator|=
name|nextbuffer
expr_stmt|;
name|dest
operator|->
name|bufsize
operator|=
name|nextsize
expr_stmt|;
return|return
name|TRUE
return|;
block|}
end_block
begin_comment
comment|/*  * Terminate destination --- called by jpeg_finish_compress  * after all data has been written.  Usually needs to flush buffer.  *  * NB: *not* called by jpeg_abort or jpeg_destroy; surrounding  * application must deal with any cleanup that should happen even  * for error exit.  */
end_comment
begin_macro
name|METHODDEF
argument_list|(
argument|void
argument_list|)
end_macro
begin_macro
DECL|function|term_destination
name|term_destination
argument_list|(
argument|j_compress_ptr cinfo
argument_list|)
end_macro
begin_block
block|{
name|my_dest_ptr
name|dest
init|=
operator|(
name|my_dest_ptr
operator|)
name|cinfo
operator|->
name|dest
decl_stmt|;
name|size_t
name|datacount
init|=
name|OUTPUT_BUF_SIZE
operator|-
name|dest
operator|->
name|pub
operator|.
name|free_in_buffer
decl_stmt|;
comment|/* Write any data remaining in the buffer */
if|if
condition|(
name|datacount
operator|>
literal|0
condition|)
block|{
if|if
condition|(
name|JFWRITE
argument_list|(
name|dest
operator|->
name|outfile
argument_list|,
name|dest
operator|->
name|buffer
argument_list|,
name|datacount
argument_list|)
operator|!=
name|datacount
condition|)
name|ERREXIT
argument_list|(
name|cinfo
argument_list|,
name|JERR_FILE_WRITE
argument_list|)
expr_stmt|;
block|}
name|fflush
argument_list|(
name|dest
operator|->
name|outfile
argument_list|)
expr_stmt|;
comment|/* Make sure we wrote the output file OK */
if|if
condition|(
name|ferror
argument_list|(
name|dest
operator|->
name|outfile
argument_list|)
condition|)
name|ERREXIT
argument_list|(
name|cinfo
argument_list|,
name|JERR_FILE_WRITE
argument_list|)
expr_stmt|;
block|}
end_block
begin_macro
name|METHODDEF
argument_list|(
argument|void
argument_list|)
end_macro
begin_macro
DECL|function|term_mem_destination
name|term_mem_destination
argument_list|(
argument|j_compress_ptr cinfo
argument_list|)
end_macro
begin_block
block|{
name|my_mem_dest_ptr
name|dest
init|=
operator|(
name|my_mem_dest_ptr
operator|)
name|cinfo
operator|->
name|dest
decl_stmt|;
operator|*
name|dest
operator|->
name|outbuffer
operator|=
name|dest
operator|->
name|buffer
expr_stmt|;
operator|*
name|dest
operator|->
name|outsize
operator|=
name|dest
operator|->
name|bufsize
operator|-
name|dest
operator|->
name|pub
operator|.
name|free_in_buffer
expr_stmt|;
block|}
end_block
begin_comment
comment|/*  * Prepare for output to a stdio stream.  * The caller must have already opened the stream, and is responsible  * for closing it after finishing compression.  */
end_comment
begin_macro
name|GLOBAL
argument_list|(
argument|void
argument_list|)
end_macro
begin_macro
DECL|function|jpeg_stdio_dest
name|jpeg_stdio_dest
argument_list|(
argument|j_compress_ptr cinfo
argument_list|,
argument|FILE * outfile
argument_list|)
end_macro
begin_block
block|{
name|my_dest_ptr
name|dest
decl_stmt|;
comment|/* The destination object is made permanent so that multiple JPEG images    * can be written to the same file without re-executing jpeg_stdio_dest.    * This makes it dangerous to use this manager and a different destination    * manager serially with the same JPEG object, because their private object    * sizes may be different.  Caveat programmer.    */
if|if
condition|(
name|cinfo
operator|->
name|dest
operator|==
name|NULL
condition|)
block|{
comment|/* first time for this JPEG object? */
name|cinfo
operator|->
name|dest
operator|=
operator|(
expr|struct
name|jpeg_destination_mgr
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
name|JPOOL_PERMANENT
argument_list|,
name|SIZEOF
argument_list|(
name|my_destination_mgr
argument_list|)
argument_list|)
expr_stmt|;
block|}
name|dest
operator|=
operator|(
name|my_dest_ptr
operator|)
name|cinfo
operator|->
name|dest
expr_stmt|;
name|dest
operator|->
name|pub
operator|.
name|init_destination
operator|=
name|init_destination
expr_stmt|;
name|dest
operator|->
name|pub
operator|.
name|empty_output_buffer
operator|=
name|empty_output_buffer
expr_stmt|;
name|dest
operator|->
name|pub
operator|.
name|term_destination
operator|=
name|term_destination
expr_stmt|;
name|dest
operator|->
name|outfile
operator|=
name|outfile
expr_stmt|;
block|}
end_block
begin_comment
comment|/*  * Prepare for output to a memory buffer.  * The caller may supply an own initial buffer with appropriate size.  * Otherwise, or when the actual data output exceeds the given size,  * the library adapts the buffer size as necessary.  * The standard library functions malloc/free are used for allocating  * larger memory, so the buffer is available to the application after  * finishing compression, and then the application is responsible for  * freeing the requested memory.  */
end_comment
begin_macro
name|GLOBAL
argument_list|(
argument|void
argument_list|)
end_macro
begin_macro
DECL|function|jpeg_mem_dest
name|jpeg_mem_dest
argument_list|(
argument|j_compress_ptr cinfo
argument_list|,
argument|unsigned char ** outbuffer
argument_list|,
argument|unsigned long * outsize
argument_list|)
end_macro
begin_block
block|{
name|my_mem_dest_ptr
name|dest
decl_stmt|;
if|if
condition|(
name|outbuffer
operator|==
name|NULL
operator|||
name|outsize
operator|==
name|NULL
condition|)
comment|/* sanity check */
name|ERREXIT
argument_list|(
name|cinfo
argument_list|,
name|JERR_BUFFER_SIZE
argument_list|)
expr_stmt|;
comment|/* The destination object is made permanent so that multiple JPEG images    * can be written to the same buffer without re-executing jpeg_mem_dest.    */
if|if
condition|(
name|cinfo
operator|->
name|dest
operator|==
name|NULL
condition|)
block|{
comment|/* first time for this JPEG object? */
name|cinfo
operator|->
name|dest
operator|=
operator|(
expr|struct
name|jpeg_destination_mgr
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
name|JPOOL_PERMANENT
argument_list|,
name|SIZEOF
argument_list|(
name|my_mem_destination_mgr
argument_list|)
argument_list|)
expr_stmt|;
block|}
name|dest
operator|=
operator|(
name|my_mem_dest_ptr
operator|)
name|cinfo
operator|->
name|dest
expr_stmt|;
name|dest
operator|->
name|pub
operator|.
name|init_destination
operator|=
name|init_mem_destination
expr_stmt|;
name|dest
operator|->
name|pub
operator|.
name|empty_output_buffer
operator|=
name|empty_mem_output_buffer
expr_stmt|;
name|dest
operator|->
name|pub
operator|.
name|term_destination
operator|=
name|term_mem_destination
expr_stmt|;
name|dest
operator|->
name|outbuffer
operator|=
name|outbuffer
expr_stmt|;
name|dest
operator|->
name|outsize
operator|=
name|outsize
expr_stmt|;
name|dest
operator|->
name|newbuffer
operator|=
name|NULL
expr_stmt|;
if|if
condition|(
operator|*
name|outbuffer
operator|==
name|NULL
operator|||
operator|*
name|outsize
operator|==
literal|0
condition|)
block|{
comment|/* Allocate initial buffer */
name|dest
operator|->
name|newbuffer
operator|=
operator|*
name|outbuffer
operator|=
name|malloc
argument_list|(
name|OUTPUT_BUF_SIZE
argument_list|)
expr_stmt|;
if|if
condition|(
name|dest
operator|->
name|newbuffer
operator|==
name|NULL
condition|)
name|ERREXIT1
argument_list|(
name|cinfo
argument_list|,
name|JERR_OUT_OF_MEMORY
argument_list|,
literal|10
argument_list|)
expr_stmt|;
operator|*
name|outsize
operator|=
name|OUTPUT_BUF_SIZE
expr_stmt|;
block|}
name|dest
operator|->
name|pub
operator|.
name|next_output_byte
operator|=
name|dest
operator|->
name|buffer
operator|=
operator|*
name|outbuffer
expr_stmt|;
name|dest
operator|->
name|pub
operator|.
name|free_in_buffer
operator|=
name|dest
operator|->
name|bufsize
operator|=
operator|*
name|outsize
expr_stmt|;
block|}
end_block
end_unit
