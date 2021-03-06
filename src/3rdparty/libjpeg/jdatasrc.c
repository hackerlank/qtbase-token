begin_unit
begin_comment
comment|/*  * jdatasrc.c  *  * Copyright (C) 1994-1996, Thomas G. Lane.  * Modified 2009-2010 by Guido Vollbeding.  * This file is part of the Independent JPEG Group's software.  * For conditions of distribution and use, see the accompanying README file.  *  * This file contains decompression data source routines for the case of  * reading JPEG data from memory or from a file (or any stdio stream).  * While these routines are sufficient for most applications,  * some will want to use a different source manager.  * IMPORTANT: we assume that fread() will correctly transcribe an array of  * JOCTETs from 8-bit-wide elements on external storage.  If char is wider  * than 8 bits on your machine, you may need to do some tweaking.  */
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
begin_comment
comment|/* Expanded data source object for stdio input */
end_comment
begin_typedef
typedef|typedef
struct|struct
block|{
DECL|member|pub
name|struct
name|jpeg_source_mgr
name|pub
decl_stmt|;
comment|/* public fields */
DECL|member|infile
name|FILE
modifier|*
name|infile
decl_stmt|;
comment|/* source stream */
DECL|member|buffer
name|JOCTET
modifier|*
name|buffer
decl_stmt|;
comment|/* start of buffer */
DECL|member|start_of_file
name|boolean
name|start_of_file
decl_stmt|;
comment|/* have we gotten any data yet? */
block|}
DECL|typedef|my_source_mgr
name|my_source_mgr
typedef|;
end_typedef
begin_typedef
DECL|typedef|my_src_ptr
typedef|typedef
name|my_source_mgr
modifier|*
name|my_src_ptr
typedef|;
end_typedef
begin_define
DECL|macro|INPUT_BUF_SIZE
define|#
directive|define
name|INPUT_BUF_SIZE
value|4096
end_define
begin_comment
DECL|macro|INPUT_BUF_SIZE
comment|/* choose an efficiently fread'able size */
end_comment
begin_comment
comment|/*  * Initialize source --- called by jpeg_read_header  * before any data is actually read.  */
end_comment
begin_macro
name|METHODDEF
argument_list|(
argument|void
argument_list|)
end_macro
begin_macro
DECL|function|init_source
name|init_source
argument_list|(
argument|j_decompress_ptr cinfo
argument_list|)
end_macro
begin_block
block|{
name|my_src_ptr
name|src
init|=
operator|(
name|my_src_ptr
operator|)
name|cinfo
operator|->
name|src
decl_stmt|;
comment|/* We reset the empty-input-file flag for each image,    * but we don't clear the input buffer.    * This is correct behavior for reading a series of images from one source.    */
name|src
operator|->
name|start_of_file
operator|=
name|TRUE
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
DECL|function|init_mem_source
name|init_mem_source
argument_list|(
argument|j_decompress_ptr cinfo
argument_list|)
end_macro
begin_block
block|{
comment|/* no work necessary here */
block|}
end_block
begin_comment
comment|/*  * Fill the input buffer --- called whenever buffer is emptied.  *  * In typical applications, this should read fresh data into the buffer  * (ignoring the current state of next_input_byte& bytes_in_buffer),  * reset the pointer& count to the start of the buffer, and return TRUE  * indicating that the buffer has been reloaded.  It is not necessary to  * fill the buffer entirely, only to obtain at least one more byte.  *  * There is no such thing as an EOF return.  If the end of the file has been  * reached, the routine has a choice of ERREXIT() or inserting fake data into  * the buffer.  In most cases, generating a warning message and inserting a  * fake EOI marker is the best course of action --- this will allow the  * decompressor to output however much of the image is there.  However,  * the resulting error message is misleading if the real problem is an empty  * input file, so we handle that case specially.  *  * In applications that need to be able to suspend compression due to input  * not being available yet, a FALSE return indicates that no more data can be  * obtained right now, but more may be forthcoming later.  In this situation,  * the decompressor will return to its caller (with an indication of the  * number of scanlines it has read, if any).  The application should resume  * decompression after it has loaded more data into the input buffer.  Note  * that there are substantial restrictions on the use of suspension --- see  * the documentation.  *  * When suspending, the decompressor will back up to a convenient restart point  * (typically the start of the current MCU). next_input_byte& bytes_in_buffer  * indicate where the restart point will be if the current call returns FALSE.  * Data beyond this point must be rescanned after resumption, so move it to  * the front of the buffer rather than discarding it.  */
end_comment
begin_macro
DECL|function|METHODDEF
name|METHODDEF
argument_list|(
argument|boolean
argument_list|)
end_macro
begin_macro
name|fill_input_buffer
argument_list|(
argument|j_decompress_ptr cinfo
argument_list|)
end_macro
begin_block
block|{
name|my_src_ptr
name|src
init|=
operator|(
name|my_src_ptr
operator|)
name|cinfo
operator|->
name|src
decl_stmt|;
name|size_t
name|nbytes
decl_stmt|;
name|nbytes
operator|=
name|JFREAD
argument_list|(
name|src
operator|->
name|infile
argument_list|,
name|src
operator|->
name|buffer
argument_list|,
name|INPUT_BUF_SIZE
argument_list|)
expr_stmt|;
if|if
condition|(
name|nbytes
operator|<=
literal|0
condition|)
block|{
if|if
condition|(
name|src
operator|->
name|start_of_file
condition|)
comment|/* Treat empty input file as fatal error */
name|ERREXIT
argument_list|(
name|cinfo
argument_list|,
name|JERR_INPUT_EMPTY
argument_list|)
expr_stmt|;
name|WARNMS
argument_list|(
name|cinfo
argument_list|,
name|JWRN_JPEG_EOF
argument_list|)
expr_stmt|;
comment|/* Insert a fake EOI marker */
name|src
operator|->
name|buffer
index|[
literal|0
index|]
operator|=
operator|(
name|JOCTET
operator|)
literal|0xFF
expr_stmt|;
name|src
operator|->
name|buffer
index|[
literal|1
index|]
operator|=
operator|(
name|JOCTET
operator|)
name|JPEG_EOI
expr_stmt|;
name|nbytes
operator|=
literal|2
expr_stmt|;
block|}
name|src
operator|->
name|pub
operator|.
name|next_input_byte
operator|=
name|src
operator|->
name|buffer
expr_stmt|;
name|src
operator|->
name|pub
operator|.
name|bytes_in_buffer
operator|=
name|nbytes
expr_stmt|;
name|src
operator|->
name|start_of_file
operator|=
name|FALSE
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
name|fill_mem_input_buffer
argument_list|(
argument|j_decompress_ptr cinfo
argument_list|)
end_macro
begin_block
block|{
specifier|static
name|JOCTET
name|mybuffer
index|[
literal|4
index|]
decl_stmt|;
comment|/* The whole JPEG data is expected to reside in the supplied memory    * buffer, so any request for more data beyond the given buffer size    * is treated as an error.    */
name|WARNMS
argument_list|(
name|cinfo
argument_list|,
name|JWRN_JPEG_EOF
argument_list|)
expr_stmt|;
comment|/* Insert a fake EOI marker */
name|mybuffer
index|[
literal|0
index|]
operator|=
operator|(
name|JOCTET
operator|)
literal|0xFF
expr_stmt|;
name|mybuffer
index|[
literal|1
index|]
operator|=
operator|(
name|JOCTET
operator|)
name|JPEG_EOI
expr_stmt|;
name|cinfo
operator|->
name|src
operator|->
name|next_input_byte
operator|=
name|mybuffer
expr_stmt|;
name|cinfo
operator|->
name|src
operator|->
name|bytes_in_buffer
operator|=
literal|2
expr_stmt|;
return|return
name|TRUE
return|;
block|}
end_block
begin_comment
comment|/*  * Skip data --- used to skip over a potentially large amount of  * uninteresting data (such as an APPn marker).  *  * Writers of suspendable-input applications must note that skip_input_data  * is not granted the right to give a suspension return.  If the skip extends  * beyond the data currently in the buffer, the buffer can be marked empty so  * that the next read will cause a fill_input_buffer call that can suspend.  * Arranging for additional bytes to be discarded before reloading the input  * buffer is the application writer's problem.  */
end_comment
begin_macro
name|METHODDEF
argument_list|(
argument|void
argument_list|)
end_macro
begin_macro
DECL|function|skip_input_data
name|skip_input_data
argument_list|(
argument|j_decompress_ptr cinfo
argument_list|,
argument|long num_bytes
argument_list|)
end_macro
begin_block
block|{
name|struct
name|jpeg_source_mgr
modifier|*
name|src
init|=
name|cinfo
operator|->
name|src
decl_stmt|;
comment|/* Just a dumb implementation for now.  Could use fseek() except    * it doesn't work on pipes.  Not clear that being smart is worth    * any trouble anyway --- large skips are infrequent.    */
if|if
condition|(
name|num_bytes
operator|>
literal|0
condition|)
block|{
while|while
condition|(
name|num_bytes
operator|>
operator|(
name|long
operator|)
name|src
operator|->
name|bytes_in_buffer
condition|)
block|{
name|num_bytes
operator|-=
operator|(
name|long
operator|)
name|src
operator|->
name|bytes_in_buffer
expr_stmt|;
call|(
name|void
call|)
argument_list|(
operator|*
name|src
operator|->
name|fill_input_buffer
argument_list|)
argument_list|(
name|cinfo
argument_list|)
expr_stmt|;
comment|/* note we assume that fill_input_buffer will never return FALSE,        * so suspension need not be handled.        */
block|}
name|src
operator|->
name|next_input_byte
operator|+=
operator|(
name|size_t
operator|)
name|num_bytes
expr_stmt|;
name|src
operator|->
name|bytes_in_buffer
operator|-=
operator|(
name|size_t
operator|)
name|num_bytes
expr_stmt|;
block|}
block|}
end_block
begin_comment
comment|/*  * An additional method that can be provided by data source modules is the  * resync_to_restart method for error recovery in the presence of RST markers.  * For the moment, this source module just uses the default resync method  * provided by the JPEG library.  That method assumes that no backtracking  * is possible.  */
end_comment
begin_comment
comment|/*  * Terminate source --- called by jpeg_finish_decompress  * after all data has been read.  Often a no-op.  *  * NB: *not* called by jpeg_abort or jpeg_destroy; surrounding  * application must deal with any cleanup that should happen even  * for error exit.  */
end_comment
begin_macro
name|METHODDEF
argument_list|(
argument|void
argument_list|)
end_macro
begin_macro
DECL|function|term_source
name|term_source
argument_list|(
argument|j_decompress_ptr cinfo
argument_list|)
end_macro
begin_block
block|{
comment|/* no work necessary here */
block|}
end_block
begin_comment
comment|/*  * Prepare for input from a stdio stream.  * The caller must have already opened the stream, and is responsible  * for closing it after finishing decompression.  */
end_comment
begin_macro
name|GLOBAL
argument_list|(
argument|void
argument_list|)
end_macro
begin_macro
DECL|function|jpeg_stdio_src
name|jpeg_stdio_src
argument_list|(
argument|j_decompress_ptr cinfo
argument_list|,
argument|FILE * infile
argument_list|)
end_macro
begin_block
block|{
name|my_src_ptr
name|src
decl_stmt|;
comment|/* The source object and input buffer are made permanent so that a series    * of JPEG images can be read from the same file by calling jpeg_stdio_src    * only before the first one.  (If we discarded the buffer at the end of    * one image, we'd likely lose the start of the next one.)    * This makes it unsafe to use this manager and a different source    * manager serially with the same JPEG object.  Caveat programmer.    */
if|if
condition|(
name|cinfo
operator|->
name|src
operator|==
name|NULL
condition|)
block|{
comment|/* first time for this JPEG object? */
name|cinfo
operator|->
name|src
operator|=
operator|(
expr|struct
name|jpeg_source_mgr
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
name|my_source_mgr
argument_list|)
argument_list|)
expr_stmt|;
name|src
operator|=
operator|(
name|my_src_ptr
operator|)
name|cinfo
operator|->
name|src
expr_stmt|;
name|src
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
name|JPOOL_PERMANENT
argument_list|,
name|INPUT_BUF_SIZE
operator|*
name|SIZEOF
argument_list|(
name|JOCTET
argument_list|)
argument_list|)
expr_stmt|;
block|}
name|src
operator|=
operator|(
name|my_src_ptr
operator|)
name|cinfo
operator|->
name|src
expr_stmt|;
name|src
operator|->
name|pub
operator|.
name|init_source
operator|=
name|init_source
expr_stmt|;
name|src
operator|->
name|pub
operator|.
name|fill_input_buffer
operator|=
name|fill_input_buffer
expr_stmt|;
name|src
operator|->
name|pub
operator|.
name|skip_input_data
operator|=
name|skip_input_data
expr_stmt|;
name|src
operator|->
name|pub
operator|.
name|resync_to_restart
operator|=
name|jpeg_resync_to_restart
expr_stmt|;
comment|/* use default method */
name|src
operator|->
name|pub
operator|.
name|term_source
operator|=
name|term_source
expr_stmt|;
name|src
operator|->
name|infile
operator|=
name|infile
expr_stmt|;
name|src
operator|->
name|pub
operator|.
name|bytes_in_buffer
operator|=
literal|0
expr_stmt|;
comment|/* forces fill_input_buffer on first read */
name|src
operator|->
name|pub
operator|.
name|next_input_byte
operator|=
name|NULL
expr_stmt|;
comment|/* until buffer loaded */
block|}
end_block
begin_comment
comment|/*  * Prepare for input from a supplied memory buffer.  * The buffer must contain the whole JPEG data.  */
end_comment
begin_macro
name|GLOBAL
argument_list|(
argument|void
argument_list|)
end_macro
begin_macro
DECL|function|jpeg_mem_src
name|jpeg_mem_src
argument_list|(
argument|j_decompress_ptr cinfo
argument_list|,
argument|unsigned char * inbuffer
argument_list|,
argument|unsigned long insize
argument_list|)
end_macro
begin_block
block|{
name|struct
name|jpeg_source_mgr
modifier|*
name|src
decl_stmt|;
if|if
condition|(
name|inbuffer
operator|==
name|NULL
operator|||
name|insize
operator|==
literal|0
condition|)
comment|/* Treat empty input as fatal error */
name|ERREXIT
argument_list|(
name|cinfo
argument_list|,
name|JERR_INPUT_EMPTY
argument_list|)
expr_stmt|;
comment|/* The source object is made permanent so that a series of JPEG images    * can be read from the same buffer by calling jpeg_mem_src only before    * the first one.    */
if|if
condition|(
name|cinfo
operator|->
name|src
operator|==
name|NULL
condition|)
block|{
comment|/* first time for this JPEG object? */
name|cinfo
operator|->
name|src
operator|=
operator|(
expr|struct
name|jpeg_source_mgr
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
expr|struct
name|jpeg_source_mgr
argument_list|)
argument_list|)
expr_stmt|;
block|}
name|src
operator|=
name|cinfo
operator|->
name|src
expr_stmt|;
name|src
operator|->
name|init_source
operator|=
name|init_mem_source
expr_stmt|;
name|src
operator|->
name|fill_input_buffer
operator|=
name|fill_mem_input_buffer
expr_stmt|;
name|src
operator|->
name|skip_input_data
operator|=
name|skip_input_data
expr_stmt|;
name|src
operator|->
name|resync_to_restart
operator|=
name|jpeg_resync_to_restart
expr_stmt|;
comment|/* use default method */
name|src
operator|->
name|term_source
operator|=
name|term_source
expr_stmt|;
name|src
operator|->
name|bytes_in_buffer
operator|=
operator|(
name|size_t
operator|)
name|insize
expr_stmt|;
name|src
operator|->
name|next_input_byte
operator|=
operator|(
name|JOCTET
operator|*
operator|)
name|inbuffer
expr_stmt|;
block|}
end_block
end_unit
