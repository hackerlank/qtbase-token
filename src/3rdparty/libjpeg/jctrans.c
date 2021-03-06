begin_unit
begin_comment
comment|/*  * jctrans.c  *  * Copyright (C) 1995-1998, Thomas G. Lane.  * Modified 2000-2009 by Guido Vollbeding.  * This file is part of the Independent JPEG Group's software.  * For conditions of distribution and use, see the accompanying README file.  *  * This file contains library routines for transcoding compression,  * that is, writing raw DCT coefficient arrays to an output JPEG file.  * The routines in jcapimin.c will also be needed by a transcoder.  */
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
comment|/* Forward declarations */
end_comment
begin_macro
name|LOCAL
argument_list|(
argument|void
argument_list|)
end_macro
begin_decl_stmt
name|transencode_master_selection
name|JPP
argument_list|(
operator|(
name|j_compress_ptr
name|cinfo
operator|,
name|jvirt_barray_ptr
operator|*
name|coef_arrays
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt
begin_macro
name|LOCAL
argument_list|(
argument|void
argument_list|)
end_macro
begin_decl_stmt
name|transencode_coef_controller
name|JPP
argument_list|(
operator|(
name|j_compress_ptr
name|cinfo
operator|,
name|jvirt_barray_ptr
operator|*
name|coef_arrays
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt
begin_comment
comment|/*  * Compression initialization for writing raw-coefficient data.  * Before calling this, all parameters and a data destination must be set up.  * Call jpeg_finish_compress() to actually write the data.  *  * The number of passed virtual arrays must match cinfo->num_components.  * Note that the virtual arrays need not be filled or even realized at  * the time write_coefficients is called; indeed, if the virtual arrays  * were requested from this compression object's memory manager, they  * typically will be realized during this routine and filled afterwards.  */
end_comment
begin_macro
name|GLOBAL
argument_list|(
argument|void
argument_list|)
end_macro
begin_macro
DECL|function|jpeg_write_coefficients
name|jpeg_write_coefficients
argument_list|(
argument|j_compress_ptr cinfo
argument_list|,
argument|jvirt_barray_ptr * coef_arrays
argument_list|)
end_macro
begin_block
block|{
if|if
condition|(
name|cinfo
operator|->
name|global_state
operator|!=
name|CSTATE_START
condition|)
name|ERREXIT1
argument_list|(
name|cinfo
argument_list|,
name|JERR_BAD_STATE
argument_list|,
name|cinfo
operator|->
name|global_state
argument_list|)
expr_stmt|;
comment|/* Mark all tables to be written */
name|jpeg_suppress_tables
argument_list|(
name|cinfo
argument_list|,
name|FALSE
argument_list|)
expr_stmt|;
comment|/* (Re)initialize error mgr and destination modules */
call|(
modifier|*
name|cinfo
operator|->
name|err
operator|->
name|reset_error_mgr
call|)
argument_list|(
operator|(
name|j_common_ptr
operator|)
name|cinfo
argument_list|)
expr_stmt|;
call|(
modifier|*
name|cinfo
operator|->
name|dest
operator|->
name|init_destination
call|)
argument_list|(
name|cinfo
argument_list|)
expr_stmt|;
comment|/* Perform master selection of active modules */
name|transencode_master_selection
argument_list|(
name|cinfo
argument_list|,
name|coef_arrays
argument_list|)
expr_stmt|;
comment|/* Wait for jpeg_finish_compress() call */
name|cinfo
operator|->
name|next_scanline
operator|=
literal|0
expr_stmt|;
comment|/* so jpeg_write_marker works */
name|cinfo
operator|->
name|global_state
operator|=
name|CSTATE_WRCOEFS
expr_stmt|;
block|}
end_block
begin_comment
comment|/*  * Initialize the compression object with default parameters,  * then copy from the source object all parameters needed for lossless  * transcoding.  Parameters that can be varied without loss (such as  * scan script and Huffman optimization) are left in their default states.  */
end_comment
begin_macro
name|GLOBAL
argument_list|(
argument|void
argument_list|)
end_macro
begin_macro
DECL|function|jpeg_copy_critical_parameters
name|jpeg_copy_critical_parameters
argument_list|(
argument|j_decompress_ptr srcinfo
argument_list|,
argument|j_compress_ptr dstinfo
argument_list|)
end_macro
begin_block
block|{
name|JQUANT_TBL
modifier|*
modifier|*
name|qtblptr
decl_stmt|;
name|jpeg_component_info
modifier|*
name|incomp
decl_stmt|,
modifier|*
name|outcomp
decl_stmt|;
name|JQUANT_TBL
modifier|*
name|c_quant
decl_stmt|,
modifier|*
name|slot_quant
decl_stmt|;
name|int
name|tblno
decl_stmt|,
name|ci
decl_stmt|,
name|coefi
decl_stmt|;
comment|/* Safety check to ensure start_compress not called yet. */
if|if
condition|(
name|dstinfo
operator|->
name|global_state
operator|!=
name|CSTATE_START
condition|)
name|ERREXIT1
argument_list|(
name|dstinfo
argument_list|,
name|JERR_BAD_STATE
argument_list|,
name|dstinfo
operator|->
name|global_state
argument_list|)
expr_stmt|;
comment|/* Copy fundamental image dimensions */
name|dstinfo
operator|->
name|image_width
operator|=
name|srcinfo
operator|->
name|image_width
expr_stmt|;
name|dstinfo
operator|->
name|image_height
operator|=
name|srcinfo
operator|->
name|image_height
expr_stmt|;
name|dstinfo
operator|->
name|input_components
operator|=
name|srcinfo
operator|->
name|num_components
expr_stmt|;
name|dstinfo
operator|->
name|in_color_space
operator|=
name|srcinfo
operator|->
name|jpeg_color_space
expr_stmt|;
name|dstinfo
operator|->
name|jpeg_width
operator|=
name|srcinfo
operator|->
name|output_width
expr_stmt|;
name|dstinfo
operator|->
name|jpeg_height
operator|=
name|srcinfo
operator|->
name|output_height
expr_stmt|;
name|dstinfo
operator|->
name|min_DCT_h_scaled_size
operator|=
name|srcinfo
operator|->
name|min_DCT_h_scaled_size
expr_stmt|;
name|dstinfo
operator|->
name|min_DCT_v_scaled_size
operator|=
name|srcinfo
operator|->
name|min_DCT_v_scaled_size
expr_stmt|;
comment|/* Initialize all parameters to default values */
name|jpeg_set_defaults
argument_list|(
name|dstinfo
argument_list|)
expr_stmt|;
comment|/* jpeg_set_defaults may choose wrong colorspace, eg YCbCr if input is RGB.    * Fix it to get the right header markers for the image colorspace.    */
name|jpeg_set_colorspace
argument_list|(
name|dstinfo
argument_list|,
name|srcinfo
operator|->
name|jpeg_color_space
argument_list|)
expr_stmt|;
name|dstinfo
operator|->
name|data_precision
operator|=
name|srcinfo
operator|->
name|data_precision
expr_stmt|;
name|dstinfo
operator|->
name|CCIR601_sampling
operator|=
name|srcinfo
operator|->
name|CCIR601_sampling
expr_stmt|;
comment|/* Copy the source's quantization tables. */
for|for
control|(
name|tblno
operator|=
literal|0
init|;
name|tblno
operator|<
name|NUM_QUANT_TBLS
condition|;
name|tblno
operator|++
control|)
block|{
if|if
condition|(
name|srcinfo
operator|->
name|quant_tbl_ptrs
index|[
name|tblno
index|]
operator|!=
name|NULL
condition|)
block|{
name|qtblptr
operator|=
operator|&
name|dstinfo
operator|->
name|quant_tbl_ptrs
index|[
name|tblno
index|]
expr_stmt|;
if|if
condition|(
operator|*
name|qtblptr
operator|==
name|NULL
condition|)
operator|*
name|qtblptr
operator|=
name|jpeg_alloc_quant_table
argument_list|(
operator|(
name|j_common_ptr
operator|)
name|dstinfo
argument_list|)
expr_stmt|;
name|MEMCOPY
argument_list|(
operator|(
operator|*
name|qtblptr
operator|)
operator|->
name|quantval
argument_list|,
name|srcinfo
operator|->
name|quant_tbl_ptrs
index|[
name|tblno
index|]
operator|->
name|quantval
argument_list|,
name|SIZEOF
argument_list|(
operator|(
operator|*
name|qtblptr
operator|)
operator|->
name|quantval
argument_list|)
argument_list|)
expr_stmt|;
operator|(
operator|*
name|qtblptr
operator|)
operator|->
name|sent_table
operator|=
name|FALSE
expr_stmt|;
block|}
block|}
comment|/* Copy the source's per-component info.    * Note we assume jpeg_set_defaults has allocated the dest comp_info array.    */
name|dstinfo
operator|->
name|num_components
operator|=
name|srcinfo
operator|->
name|num_components
expr_stmt|;
if|if
condition|(
name|dstinfo
operator|->
name|num_components
operator|<
literal|1
operator|||
name|dstinfo
operator|->
name|num_components
operator|>
name|MAX_COMPONENTS
condition|)
name|ERREXIT2
argument_list|(
name|dstinfo
argument_list|,
name|JERR_COMPONENT_COUNT
argument_list|,
name|dstinfo
operator|->
name|num_components
argument_list|,
name|MAX_COMPONENTS
argument_list|)
expr_stmt|;
for|for
control|(
name|ci
operator|=
literal|0
operator|,
name|incomp
operator|=
name|srcinfo
operator|->
name|comp_info
operator|,
name|outcomp
operator|=
name|dstinfo
operator|->
name|comp_info
init|;
name|ci
operator|<
name|dstinfo
operator|->
name|num_components
condition|;
name|ci
operator|++
operator|,
name|incomp
operator|++
operator|,
name|outcomp
operator|++
control|)
block|{
name|outcomp
operator|->
name|component_id
operator|=
name|incomp
operator|->
name|component_id
expr_stmt|;
name|outcomp
operator|->
name|h_samp_factor
operator|=
name|incomp
operator|->
name|h_samp_factor
expr_stmt|;
name|outcomp
operator|->
name|v_samp_factor
operator|=
name|incomp
operator|->
name|v_samp_factor
expr_stmt|;
name|outcomp
operator|->
name|quant_tbl_no
operator|=
name|incomp
operator|->
name|quant_tbl_no
expr_stmt|;
comment|/* Make sure saved quantization table for component matches the qtable      * slot.  If not, the input file re-used this qtable slot.      * IJG encoder currently cannot duplicate this.      */
name|tblno
operator|=
name|outcomp
operator|->
name|quant_tbl_no
expr_stmt|;
if|if
condition|(
name|tblno
operator|<
literal|0
operator|||
name|tblno
operator|>=
name|NUM_QUANT_TBLS
operator|||
name|srcinfo
operator|->
name|quant_tbl_ptrs
index|[
name|tblno
index|]
operator|==
name|NULL
condition|)
name|ERREXIT1
argument_list|(
name|dstinfo
argument_list|,
name|JERR_NO_QUANT_TABLE
argument_list|,
name|tblno
argument_list|)
expr_stmt|;
name|slot_quant
operator|=
name|srcinfo
operator|->
name|quant_tbl_ptrs
index|[
name|tblno
index|]
expr_stmt|;
name|c_quant
operator|=
name|incomp
operator|->
name|quant_table
expr_stmt|;
if|if
condition|(
name|c_quant
operator|!=
name|NULL
condition|)
block|{
for|for
control|(
name|coefi
operator|=
literal|0
init|;
name|coefi
operator|<
name|DCTSIZE2
condition|;
name|coefi
operator|++
control|)
block|{
if|if
condition|(
name|c_quant
operator|->
name|quantval
index|[
name|coefi
index|]
operator|!=
name|slot_quant
operator|->
name|quantval
index|[
name|coefi
index|]
condition|)
name|ERREXIT1
argument_list|(
name|dstinfo
argument_list|,
name|JERR_MISMATCHED_QUANT_TABLE
argument_list|,
name|tblno
argument_list|)
expr_stmt|;
block|}
block|}
comment|/* Note: we do not copy the source's Huffman table assignments;      * instead we rely on jpeg_set_colorspace to have made a suitable choice.      */
block|}
comment|/* Also copy JFIF version and resolution information, if available.    * Strictly speaking this isn't "critical" info, but it's nearly    * always appropriate to copy it if available.  In particular,    * if the application chooses to copy JFIF 1.02 extension markers from    * the source file, we need to copy the version to make sure we don't    * emit a file that has 1.02 extensions but a claimed version of 1.01.    * We will *not*, however, copy version info from mislabeled "2.01" files.    */
if|if
condition|(
name|srcinfo
operator|->
name|saw_JFIF_marker
condition|)
block|{
if|if
condition|(
name|srcinfo
operator|->
name|JFIF_major_version
operator|==
literal|1
condition|)
block|{
name|dstinfo
operator|->
name|JFIF_major_version
operator|=
name|srcinfo
operator|->
name|JFIF_major_version
expr_stmt|;
name|dstinfo
operator|->
name|JFIF_minor_version
operator|=
name|srcinfo
operator|->
name|JFIF_minor_version
expr_stmt|;
block|}
name|dstinfo
operator|->
name|density_unit
operator|=
name|srcinfo
operator|->
name|density_unit
expr_stmt|;
name|dstinfo
operator|->
name|X_density
operator|=
name|srcinfo
operator|->
name|X_density
expr_stmt|;
name|dstinfo
operator|->
name|Y_density
operator|=
name|srcinfo
operator|->
name|Y_density
expr_stmt|;
block|}
block|}
end_block
begin_comment
comment|/*  * Master selection of compression modules for transcoding.  * This substitutes for jcinit.c's initialization of the full compressor.  */
end_comment
begin_macro
name|LOCAL
argument_list|(
argument|void
argument_list|)
end_macro
begin_macro
DECL|function|transencode_master_selection
name|transencode_master_selection
argument_list|(
argument|j_compress_ptr cinfo
argument_list|,
argument|jvirt_barray_ptr * coef_arrays
argument_list|)
end_macro
begin_block
block|{
comment|/* Initialize master control (includes parameter checking/processing) */
name|jinit_c_master_control
argument_list|(
name|cinfo
argument_list|,
name|TRUE
comment|/* transcode only */
argument_list|)
expr_stmt|;
comment|/* Entropy encoding: either Huffman or arithmetic coding. */
if|if
condition|(
name|cinfo
operator|->
name|arith_code
condition|)
name|jinit_arith_encoder
argument_list|(
name|cinfo
argument_list|)
expr_stmt|;
else|else
block|{
name|jinit_huff_encoder
argument_list|(
name|cinfo
argument_list|)
expr_stmt|;
block|}
comment|/* We need a special coefficient buffer controller. */
name|transencode_coef_controller
argument_list|(
name|cinfo
argument_list|,
name|coef_arrays
argument_list|)
expr_stmt|;
name|jinit_marker_writer
argument_list|(
name|cinfo
argument_list|)
expr_stmt|;
comment|/* We can now tell the memory manager to allocate virtual arrays. */
call|(
modifier|*
name|cinfo
operator|->
name|mem
operator|->
name|realize_virt_arrays
call|)
argument_list|(
operator|(
name|j_common_ptr
operator|)
name|cinfo
argument_list|)
expr_stmt|;
comment|/* Write the datastream header (SOI, JFIF) immediately.    * Frame and scan headers are postponed till later.    * This lets application insert special markers after the SOI.    */
call|(
modifier|*
name|cinfo
operator|->
name|marker
operator|->
name|write_file_header
call|)
argument_list|(
name|cinfo
argument_list|)
expr_stmt|;
block|}
end_block
begin_comment
comment|/*  * The rest of this file is a special implementation of the coefficient  * buffer controller.  This is similar to jccoefct.c, but it handles only  * output from presupplied virtual arrays.  Furthermore, we generate any  * dummy padding blocks on-the-fly rather than expecting them to be present  * in the arrays.  */
end_comment
begin_comment
comment|/* Private buffer controller object */
end_comment
begin_typedef
typedef|typedef
struct|struct
block|{
DECL|member|pub
name|struct
name|jpeg_c_coef_controller
name|pub
decl_stmt|;
comment|/* public fields */
DECL|member|iMCU_row_num
name|JDIMENSION
name|iMCU_row_num
decl_stmt|;
comment|/* iMCU row # within image */
DECL|member|mcu_ctr
name|JDIMENSION
name|mcu_ctr
decl_stmt|;
comment|/* counts MCUs processed in current row */
DECL|member|MCU_vert_offset
name|int
name|MCU_vert_offset
decl_stmt|;
comment|/* counts MCU rows within iMCU row */
DECL|member|MCU_rows_per_iMCU_row
name|int
name|MCU_rows_per_iMCU_row
decl_stmt|;
comment|/* number of such rows needed */
comment|/* Virtual block array for each component. */
DECL|member|whole_image
name|jvirt_barray_ptr
modifier|*
name|whole_image
decl_stmt|;
comment|/* Workspace for constructing dummy blocks at right/bottom edges. */
DECL|member|dummy_buffer
name|JBLOCKROW
name|dummy_buffer
index|[
name|C_MAX_BLOCKS_IN_MCU
index|]
decl_stmt|;
block|}
DECL|typedef|my_coef_controller
name|my_coef_controller
typedef|;
end_typedef
begin_typedef
DECL|typedef|my_coef_ptr
typedef|typedef
name|my_coef_controller
modifier|*
name|my_coef_ptr
typedef|;
end_typedef
begin_macro
name|LOCAL
argument_list|(
argument|void
argument_list|)
end_macro
begin_macro
DECL|function|start_iMCU_row
name|start_iMCU_row
argument_list|(
argument|j_compress_ptr cinfo
argument_list|)
end_macro
begin_comment
comment|/* Reset within-iMCU-row counters for a new row */
end_comment
begin_block
block|{
name|my_coef_ptr
name|coef
init|=
operator|(
name|my_coef_ptr
operator|)
name|cinfo
operator|->
name|coef
decl_stmt|;
comment|/* In an interleaved scan, an MCU row is the same as an iMCU row.    * In a noninterleaved scan, an iMCU row has v_samp_factor MCU rows.    * But at the bottom of the image, process only what's left.    */
if|if
condition|(
name|cinfo
operator|->
name|comps_in_scan
operator|>
literal|1
condition|)
block|{
name|coef
operator|->
name|MCU_rows_per_iMCU_row
operator|=
literal|1
expr_stmt|;
block|}
else|else
block|{
if|if
condition|(
name|coef
operator|->
name|iMCU_row_num
operator|<
operator|(
name|cinfo
operator|->
name|total_iMCU_rows
operator|-
literal|1
operator|)
condition|)
name|coef
operator|->
name|MCU_rows_per_iMCU_row
operator|=
name|cinfo
operator|->
name|cur_comp_info
index|[
literal|0
index|]
operator|->
name|v_samp_factor
expr_stmt|;
else|else
name|coef
operator|->
name|MCU_rows_per_iMCU_row
operator|=
name|cinfo
operator|->
name|cur_comp_info
index|[
literal|0
index|]
operator|->
name|last_row_height
expr_stmt|;
block|}
name|coef
operator|->
name|mcu_ctr
operator|=
literal|0
expr_stmt|;
name|coef
operator|->
name|MCU_vert_offset
operator|=
literal|0
expr_stmt|;
block|}
end_block
begin_comment
comment|/*  * Initialize for a processing pass.  */
end_comment
begin_macro
name|METHODDEF
argument_list|(
argument|void
argument_list|)
end_macro
begin_macro
DECL|function|start_pass_coef
name|start_pass_coef
argument_list|(
argument|j_compress_ptr cinfo
argument_list|,
argument|J_BUF_MODE pass_mode
argument_list|)
end_macro
begin_block
block|{
name|my_coef_ptr
name|coef
init|=
operator|(
name|my_coef_ptr
operator|)
name|cinfo
operator|->
name|coef
decl_stmt|;
if|if
condition|(
name|pass_mode
operator|!=
name|JBUF_CRANK_DEST
condition|)
name|ERREXIT
argument_list|(
name|cinfo
argument_list|,
name|JERR_BAD_BUFFER_MODE
argument_list|)
expr_stmt|;
name|coef
operator|->
name|iMCU_row_num
operator|=
literal|0
expr_stmt|;
name|start_iMCU_row
argument_list|(
name|cinfo
argument_list|)
expr_stmt|;
block|}
end_block
begin_comment
comment|/*  * Process some data.  * We process the equivalent of one fully interleaved MCU row ("iMCU" row)  * per call, ie, v_samp_factor block rows for each component in the scan.  * The data is obtained from the virtual arrays and fed to the entropy coder.  * Returns TRUE if the iMCU row is completed, FALSE if suspended.  *  * NB: input_buf is ignored; it is likely to be a NULL pointer.  */
end_comment
begin_macro
DECL|function|METHODDEF
name|METHODDEF
argument_list|(
argument|boolean
argument_list|)
end_macro
begin_macro
name|compress_output
argument_list|(
argument|j_compress_ptr cinfo
argument_list|,
argument|JSAMPIMAGE input_buf
argument_list|)
end_macro
begin_block
block|{
name|my_coef_ptr
name|coef
init|=
operator|(
name|my_coef_ptr
operator|)
name|cinfo
operator|->
name|coef
decl_stmt|;
name|JDIMENSION
name|MCU_col_num
decl_stmt|;
comment|/* index of current MCU within row */
name|JDIMENSION
name|last_MCU_col
init|=
name|cinfo
operator|->
name|MCUs_per_row
operator|-
literal|1
decl_stmt|;
name|JDIMENSION
name|last_iMCU_row
init|=
name|cinfo
operator|->
name|total_iMCU_rows
operator|-
literal|1
decl_stmt|;
name|int
name|blkn
decl_stmt|,
name|ci
decl_stmt|,
name|xindex
decl_stmt|,
name|yindex
decl_stmt|,
name|yoffset
decl_stmt|,
name|blockcnt
decl_stmt|;
name|JDIMENSION
name|start_col
decl_stmt|;
name|JBLOCKARRAY
name|buffer
index|[
name|MAX_COMPS_IN_SCAN
index|]
decl_stmt|;
name|JBLOCKROW
name|MCU_buffer
index|[
name|C_MAX_BLOCKS_IN_MCU
index|]
decl_stmt|;
name|JBLOCKROW
name|buffer_ptr
decl_stmt|;
name|jpeg_component_info
modifier|*
name|compptr
decl_stmt|;
comment|/* Align the virtual buffers for the components used in this scan. */
for|for
control|(
name|ci
operator|=
literal|0
init|;
name|ci
operator|<
name|cinfo
operator|->
name|comps_in_scan
condition|;
name|ci
operator|++
control|)
block|{
name|compptr
operator|=
name|cinfo
operator|->
name|cur_comp_info
index|[
name|ci
index|]
expr_stmt|;
name|buffer
index|[
name|ci
index|]
operator|=
call|(
modifier|*
name|cinfo
operator|->
name|mem
operator|->
name|access_virt_barray
call|)
argument_list|(
operator|(
name|j_common_ptr
operator|)
name|cinfo
argument_list|,
name|coef
operator|->
name|whole_image
index|[
name|compptr
operator|->
name|component_index
index|]
argument_list|,
name|coef
operator|->
name|iMCU_row_num
operator|*
name|compptr
operator|->
name|v_samp_factor
argument_list|,
operator|(
name|JDIMENSION
operator|)
name|compptr
operator|->
name|v_samp_factor
argument_list|,
name|FALSE
argument_list|)
expr_stmt|;
block|}
comment|/* Loop to process one whole iMCU row */
for|for
control|(
name|yoffset
operator|=
name|coef
operator|->
name|MCU_vert_offset
init|;
name|yoffset
operator|<
name|coef
operator|->
name|MCU_rows_per_iMCU_row
condition|;
name|yoffset
operator|++
control|)
block|{
for|for
control|(
name|MCU_col_num
operator|=
name|coef
operator|->
name|mcu_ctr
init|;
name|MCU_col_num
operator|<
name|cinfo
operator|->
name|MCUs_per_row
condition|;
name|MCU_col_num
operator|++
control|)
block|{
comment|/* Construct list of pointers to DCT blocks belonging to this MCU */
name|blkn
operator|=
literal|0
expr_stmt|;
comment|/* index of current DCT block within MCU */
for|for
control|(
name|ci
operator|=
literal|0
init|;
name|ci
operator|<
name|cinfo
operator|->
name|comps_in_scan
condition|;
name|ci
operator|++
control|)
block|{
name|compptr
operator|=
name|cinfo
operator|->
name|cur_comp_info
index|[
name|ci
index|]
expr_stmt|;
name|start_col
operator|=
name|MCU_col_num
operator|*
name|compptr
operator|->
name|MCU_width
expr_stmt|;
name|blockcnt
operator|=
operator|(
name|MCU_col_num
operator|<
name|last_MCU_col
operator|)
condition|?
name|compptr
operator|->
name|MCU_width
else|:
name|compptr
operator|->
name|last_col_width
expr_stmt|;
for|for
control|(
name|yindex
operator|=
literal|0
init|;
name|yindex
operator|<
name|compptr
operator|->
name|MCU_height
condition|;
name|yindex
operator|++
control|)
block|{
if|if
condition|(
name|coef
operator|->
name|iMCU_row_num
operator|<
name|last_iMCU_row
operator|||
name|yindex
operator|+
name|yoffset
operator|<
name|compptr
operator|->
name|last_row_height
condition|)
block|{
comment|/* Fill in pointers to real blocks in this row */
name|buffer_ptr
operator|=
name|buffer
index|[
name|ci
index|]
index|[
name|yindex
operator|+
name|yoffset
index|]
operator|+
name|start_col
expr_stmt|;
for|for
control|(
name|xindex
operator|=
literal|0
init|;
name|xindex
operator|<
name|blockcnt
condition|;
name|xindex
operator|++
control|)
name|MCU_buffer
index|[
name|blkn
operator|++
index|]
operator|=
name|buffer_ptr
operator|++
expr_stmt|;
block|}
else|else
block|{
comment|/* At bottom of image, need a whole row of dummy blocks */
name|xindex
operator|=
literal|0
expr_stmt|;
block|}
comment|/* Fill in any dummy blocks needed in this row. 	   * Dummy blocks are filled in the same way as in jccoefct.c: 	   * all zeroes in the AC entries, DC entries equal to previous 	   * block's DC value.  The init routine has already zeroed the 	   * AC entries, so we need only set the DC entries correctly. 	   */
for|for
control|(
init|;
name|xindex
operator|<
name|compptr
operator|->
name|MCU_width
condition|;
name|xindex
operator|++
control|)
block|{
name|MCU_buffer
index|[
name|blkn
index|]
operator|=
name|coef
operator|->
name|dummy_buffer
index|[
name|blkn
index|]
expr_stmt|;
name|MCU_buffer
index|[
name|blkn
index|]
index|[
literal|0
index|]
index|[
literal|0
index|]
operator|=
name|MCU_buffer
index|[
name|blkn
operator|-
literal|1
index|]
index|[
literal|0
index|]
index|[
literal|0
index|]
expr_stmt|;
name|blkn
operator|++
expr_stmt|;
block|}
block|}
block|}
comment|/* Try to write the MCU. */
if|if
condition|(
operator|!
call|(
modifier|*
name|cinfo
operator|->
name|entropy
operator|->
name|encode_mcu
call|)
argument_list|(
name|cinfo
argument_list|,
name|MCU_buffer
argument_list|)
condition|)
block|{
comment|/* Suspension forced; update state counters and exit */
name|coef
operator|->
name|MCU_vert_offset
operator|=
name|yoffset
expr_stmt|;
name|coef
operator|->
name|mcu_ctr
operator|=
name|MCU_col_num
expr_stmt|;
return|return
name|FALSE
return|;
block|}
block|}
comment|/* Completed an MCU row, but perhaps not an iMCU row */
name|coef
operator|->
name|mcu_ctr
operator|=
literal|0
expr_stmt|;
block|}
comment|/* Completed the iMCU row, advance counters for next one */
name|coef
operator|->
name|iMCU_row_num
operator|++
expr_stmt|;
name|start_iMCU_row
argument_list|(
name|cinfo
argument_list|)
expr_stmt|;
return|return
name|TRUE
return|;
block|}
end_block
begin_comment
comment|/*  * Initialize coefficient buffer controller.  *  * Each passed coefficient array must be the right size for that  * coefficient: width_in_blocks wide and height_in_blocks high,  * with unitheight at least v_samp_factor.  */
end_comment
begin_macro
name|LOCAL
argument_list|(
argument|void
argument_list|)
end_macro
begin_macro
DECL|function|transencode_coef_controller
name|transencode_coef_controller
argument_list|(
argument|j_compress_ptr cinfo
argument_list|,
argument|jvirt_barray_ptr * coef_arrays
argument_list|)
end_macro
begin_block
block|{
name|my_coef_ptr
name|coef
decl_stmt|;
name|JBLOCKROW
name|buffer
decl_stmt|;
name|int
name|i
decl_stmt|;
name|coef
operator|=
call|(
name|my_coef_ptr
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
name|my_coef_controller
argument_list|)
argument_list|)
expr_stmt|;
name|cinfo
operator|->
name|coef
operator|=
operator|(
expr|struct
name|jpeg_c_coef_controller
operator|*
operator|)
name|coef
expr_stmt|;
name|coef
operator|->
name|pub
operator|.
name|start_pass
operator|=
name|start_pass_coef
expr_stmt|;
name|coef
operator|->
name|pub
operator|.
name|compress_data
operator|=
name|compress_output
expr_stmt|;
comment|/* Save pointer to virtual arrays */
name|coef
operator|->
name|whole_image
operator|=
name|coef_arrays
expr_stmt|;
comment|/* Allocate and pre-zero space for dummy DCT blocks. */
name|buffer
operator|=
call|(
name|JBLOCKROW
call|)
argument_list|(
operator|*
name|cinfo
operator|->
name|mem
operator|->
name|alloc_large
argument_list|)
argument_list|(
operator|(
name|j_common_ptr
operator|)
name|cinfo
argument_list|,
name|JPOOL_IMAGE
argument_list|,
name|C_MAX_BLOCKS_IN_MCU
operator|*
name|SIZEOF
argument_list|(
name|JBLOCK
argument_list|)
argument_list|)
expr_stmt|;
name|jzero_far
argument_list|(
operator|(
name|void
name|FAR
operator|*
operator|)
name|buffer
argument_list|,
name|C_MAX_BLOCKS_IN_MCU
operator|*
name|SIZEOF
argument_list|(
name|JBLOCK
argument_list|)
argument_list|)
expr_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|C_MAX_BLOCKS_IN_MCU
condition|;
name|i
operator|++
control|)
block|{
name|coef
operator|->
name|dummy_buffer
index|[
name|i
index|]
operator|=
name|buffer
operator|+
name|i
expr_stmt|;
block|}
block|}
end_block
end_unit
