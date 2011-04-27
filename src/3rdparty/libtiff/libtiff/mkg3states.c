begin_unit
begin_comment
comment|/* "$Id: mkg3states.c,v 1.10 2007/02/22 11:27:17 dron Exp $ */
end_comment
begin_comment
comment|/*  * Copyright (c) 1991-1997 Sam Leffler  * Copyright (c) 1991-1997 Silicon Graphics, Inc.  *  * Permission to use, copy, modify, distribute, and sell this software and   * its documentation for any purpose is hereby granted without fee, provided  * that (i) the above copyright notices and this permission notice appear in  * all copies of the software and related documentation, and (ii) the names of  * Sam Leffler and Silicon Graphics may not be used in any advertising or  * publicity relating to the software without the specific, prior written  * permission of Sam Leffler and Silicon Graphics.  *   * THE SOFTWARE IS PROVIDED "AS-IS" AND WITHOUT WARRANTY OF ANY KIND,   * EXPRESS, IMPLIED OR OTHERWISE, INCLUDING WITHOUT LIMITATION, ANY   * WARRANTY OF MERCHANTABILITY OR FITNESS FOR A PARTICULAR PURPOSE.    *   * IN NO EVENT SHALL SAM LEFFLER OR SILICON GRAPHICS BE LIABLE FOR  * ANY SPECIAL, INCIDENTAL, INDIRECT OR CONSEQUENTIAL DAMAGES OF ANY KIND,  * OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS,  * WHETHER OR NOT ADVISED OF THE POSSIBILITY OF DAMAGE, AND ON ANY THEORY OF   * LIABILITY, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE   * OF THIS SOFTWARE.  */
end_comment
begin_comment
comment|/* Initialise fax decoder tables  * Decoder support is derived, with permission, from the code  * in Frank Cringle's viewfax program;  *      Copyright (C) 1990, 1995  Frank D. Cringle.  */
end_comment
begin_include
include|#
directive|include
file|"tif_config.h"
end_include
begin_include
include|#
directive|include
file|<stdio.h>
end_include
begin_include
include|#
directive|include
file|<stdlib.h>
end_include
begin_include
include|#
directive|include
file|<string.h>
end_include
begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_UNISTD_H
end_ifdef
begin_include
include|#
directive|include
file|<unistd.h>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_include
include|#
directive|include
file|"tif_fax3.h"
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_GETOPT
end_ifndef
begin_function_decl
specifier|extern
name|int
name|getopt
parameter_list|(
name|int
parameter_list|,
name|char
modifier|*
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl
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
begin_comment
comment|/* NB: can't use names in tif_fax3.h 'cuz they are declared const */
end_comment
begin_decl_stmt
DECL|variable|MainTable
name|TIFFFaxTabEnt
name|MainTable
index|[
literal|128
index|]
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|WhiteTable
name|TIFFFaxTabEnt
name|WhiteTable
index|[
literal|4096
index|]
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|BlackTable
name|TIFFFaxTabEnt
name|BlackTable
index|[
literal|8192
index|]
decl_stmt|;
end_decl_stmt
begin_struct
DECL|struct|proto
struct|struct
name|proto
block|{
DECL|member|code
name|uint16
name|code
decl_stmt|;
comment|/* right justified, lsb-first, zero filled */
DECL|member|val
name|uint16
name|val
decl_stmt|;
comment|/* (pixel count)<<4 + code width  */
block|}
struct|;
end_struct
begin_decl_stmt
DECL|variable|Pass
specifier|static
name|struct
name|proto
name|Pass
index|[]
init|=
block|{
block|{
literal|0x0008
block|,
literal|4
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|Horiz
specifier|static
name|struct
name|proto
name|Horiz
index|[]
init|=
block|{
block|{
literal|0x0004
block|,
literal|3
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|V0
specifier|static
name|struct
name|proto
name|V0
index|[]
init|=
block|{
block|{
literal|0x0001
block|,
literal|1
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|VR
specifier|static
name|struct
name|proto
name|VR
index|[]
init|=
block|{
block|{
literal|0x0006
block|,
operator|(
literal|1
operator|<<
literal|4
operator|)
operator|+
literal|3
block|}
block|,
block|{
literal|0x0030
block|,
operator|(
literal|2
operator|<<
literal|4
operator|)
operator|+
literal|6
block|}
block|,
block|{
literal|0x0060
block|,
operator|(
literal|3
operator|<<
literal|4
operator|)
operator|+
literal|7
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|VL
specifier|static
name|struct
name|proto
name|VL
index|[]
init|=
block|{
block|{
literal|0x0002
block|,
operator|(
literal|1
operator|<<
literal|4
operator|)
operator|+
literal|3
block|}
block|,
block|{
literal|0x0010
block|,
operator|(
literal|2
operator|<<
literal|4
operator|)
operator|+
literal|6
block|}
block|,
block|{
literal|0x0020
block|,
operator|(
literal|3
operator|<<
literal|4
operator|)
operator|+
literal|7
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|Ext
specifier|static
name|struct
name|proto
name|Ext
index|[]
init|=
block|{
block|{
literal|0x0040
block|,
literal|7
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|EOLV
specifier|static
name|struct
name|proto
name|EOLV
index|[]
init|=
block|{
block|{
literal|0x0000
block|,
literal|7
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|MakeUpW
specifier|static
name|struct
name|proto
name|MakeUpW
index|[]
init|=
block|{
block|{
literal|0x001b
block|,
literal|1029
block|}
block|,
block|{
literal|0x0009
block|,
literal|2053
block|}
block|,
block|{
literal|0x003a
block|,
literal|3078
block|}
block|,
block|{
literal|0x0076
block|,
literal|4103
block|}
block|,
block|{
literal|0x006c
block|,
literal|5128
block|}
block|,
block|{
literal|0x00ec
block|,
literal|6152
block|}
block|,
block|{
literal|0x0026
block|,
literal|7176
block|}
block|,
block|{
literal|0x00a6
block|,
literal|8200
block|}
block|,
block|{
literal|0x0016
block|,
literal|9224
block|}
block|,
block|{
literal|0x00e6
block|,
literal|10248
block|}
block|,
block|{
literal|0x0066
block|,
literal|11273
block|}
block|,
block|{
literal|0x0166
block|,
literal|12297
block|}
block|,
block|{
literal|0x0096
block|,
literal|13321
block|}
block|,
block|{
literal|0x0196
block|,
literal|14345
block|}
block|,
block|{
literal|0x0056
block|,
literal|15369
block|}
block|,
block|{
literal|0x0156
block|,
literal|16393
block|}
block|,
block|{
literal|0x00d6
block|,
literal|17417
block|}
block|,
block|{
literal|0x01d6
block|,
literal|18441
block|}
block|,
block|{
literal|0x0036
block|,
literal|19465
block|}
block|,
block|{
literal|0x0136
block|,
literal|20489
block|}
block|,
block|{
literal|0x00b6
block|,
literal|21513
block|}
block|,
block|{
literal|0x01b6
block|,
literal|22537
block|}
block|,
block|{
literal|0x0032
block|,
literal|23561
block|}
block|,
block|{
literal|0x0132
block|,
literal|24585
block|}
block|,
block|{
literal|0x00b2
block|,
literal|25609
block|}
block|,
block|{
literal|0x0006
block|,
literal|26630
block|}
block|,
block|{
literal|0x01b2
block|,
literal|27657
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|MakeUpB
specifier|static
name|struct
name|proto
name|MakeUpB
index|[]
init|=
block|{
block|{
literal|0x03c0
block|,
literal|1034
block|}
block|,
block|{
literal|0x0130
block|,
literal|2060
block|}
block|,
block|{
literal|0x0930
block|,
literal|3084
block|}
block|,
block|{
literal|0x0da0
block|,
literal|4108
block|}
block|,
block|{
literal|0x0cc0
block|,
literal|5132
block|}
block|,
block|{
literal|0x02c0
block|,
literal|6156
block|}
block|,
block|{
literal|0x0ac0
block|,
literal|7180
block|}
block|,
block|{
literal|0x06c0
block|,
literal|8205
block|}
block|,
block|{
literal|0x16c0
block|,
literal|9229
block|}
block|,
block|{
literal|0x0a40
block|,
literal|10253
block|}
block|,
block|{
literal|0x1a40
block|,
literal|11277
block|}
block|,
block|{
literal|0x0640
block|,
literal|12301
block|}
block|,
block|{
literal|0x1640
block|,
literal|13325
block|}
block|,
block|{
literal|0x09c0
block|,
literal|14349
block|}
block|,
block|{
literal|0x19c0
block|,
literal|15373
block|}
block|,
block|{
literal|0x05c0
block|,
literal|16397
block|}
block|,
block|{
literal|0x15c0
block|,
literal|17421
block|}
block|,
block|{
literal|0x0dc0
block|,
literal|18445
block|}
block|,
block|{
literal|0x1dc0
block|,
literal|19469
block|}
block|,
block|{
literal|0x0940
block|,
literal|20493
block|}
block|,
block|{
literal|0x1940
block|,
literal|21517
block|}
block|,
block|{
literal|0x0540
block|,
literal|22541
block|}
block|,
block|{
literal|0x1540
block|,
literal|23565
block|}
block|,
block|{
literal|0x0b40
block|,
literal|24589
block|}
block|,
block|{
literal|0x1b40
block|,
literal|25613
block|}
block|,
block|{
literal|0x04c0
block|,
literal|26637
block|}
block|,
block|{
literal|0x14c0
block|,
literal|27661
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|MakeUp
specifier|static
name|struct
name|proto
name|MakeUp
index|[]
init|=
block|{
block|{
literal|0x0080
block|,
literal|28683
block|}
block|,
block|{
literal|0x0180
block|,
literal|29707
block|}
block|,
block|{
literal|0x0580
block|,
literal|30731
block|}
block|,
block|{
literal|0x0480
block|,
literal|31756
block|}
block|,
block|{
literal|0x0c80
block|,
literal|32780
block|}
block|,
block|{
literal|0x0280
block|,
literal|33804
block|}
block|,
block|{
literal|0x0a80
block|,
literal|34828
block|}
block|,
block|{
literal|0x0680
block|,
literal|35852
block|}
block|,
block|{
literal|0x0e80
block|,
literal|36876
block|}
block|,
block|{
literal|0x0380
block|,
literal|37900
block|}
block|,
block|{
literal|0x0b80
block|,
literal|38924
block|}
block|,
block|{
literal|0x0780
block|,
literal|39948
block|}
block|,
block|{
literal|0x0f80
block|,
literal|40972
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|TermW
specifier|static
name|struct
name|proto
name|TermW
index|[]
init|=
block|{
block|{
literal|0x00ac
block|,
literal|8
block|}
block|,
block|{
literal|0x0038
block|,
literal|22
block|}
block|,
block|{
literal|0x000e
block|,
literal|36
block|}
block|,
block|{
literal|0x0001
block|,
literal|52
block|}
block|,
block|{
literal|0x000d
block|,
literal|68
block|}
block|,
block|{
literal|0x0003
block|,
literal|84
block|}
block|,
block|{
literal|0x0007
block|,
literal|100
block|}
block|,
block|{
literal|0x000f
block|,
literal|116
block|}
block|,
block|{
literal|0x0019
block|,
literal|133
block|}
block|,
block|{
literal|0x0005
block|,
literal|149
block|}
block|,
block|{
literal|0x001c
block|,
literal|165
block|}
block|,
block|{
literal|0x0002
block|,
literal|181
block|}
block|,
block|{
literal|0x0004
block|,
literal|198
block|}
block|,
block|{
literal|0x0030
block|,
literal|214
block|}
block|,
block|{
literal|0x000b
block|,
literal|230
block|}
block|,
block|{
literal|0x002b
block|,
literal|246
block|}
block|,
block|{
literal|0x0015
block|,
literal|262
block|}
block|,
block|{
literal|0x0035
block|,
literal|278
block|}
block|,
block|{
literal|0x0072
block|,
literal|295
block|}
block|,
block|{
literal|0x0018
block|,
literal|311
block|}
block|,
block|{
literal|0x0008
block|,
literal|327
block|}
block|,
block|{
literal|0x0074
block|,
literal|343
block|}
block|,
block|{
literal|0x0060
block|,
literal|359
block|}
block|,
block|{
literal|0x0010
block|,
literal|375
block|}
block|,
block|{
literal|0x000a
block|,
literal|391
block|}
block|,
block|{
literal|0x006a
block|,
literal|407
block|}
block|,
block|{
literal|0x0064
block|,
literal|423
block|}
block|,
block|{
literal|0x0012
block|,
literal|439
block|}
block|,
block|{
literal|0x000c
block|,
literal|455
block|}
block|,
block|{
literal|0x0040
block|,
literal|472
block|}
block|,
block|{
literal|0x00c0
block|,
literal|488
block|}
block|,
block|{
literal|0x0058
block|,
literal|504
block|}
block|,
block|{
literal|0x00d8
block|,
literal|520
block|}
block|,
block|{
literal|0x0048
block|,
literal|536
block|}
block|,
block|{
literal|0x00c8
block|,
literal|552
block|}
block|,
block|{
literal|0x0028
block|,
literal|568
block|}
block|,
block|{
literal|0x00a8
block|,
literal|584
block|}
block|,
block|{
literal|0x0068
block|,
literal|600
block|}
block|,
block|{
literal|0x00e8
block|,
literal|616
block|}
block|,
block|{
literal|0x0014
block|,
literal|632
block|}
block|,
block|{
literal|0x0094
block|,
literal|648
block|}
block|,
block|{
literal|0x0054
block|,
literal|664
block|}
block|,
block|{
literal|0x00d4
block|,
literal|680
block|}
block|,
block|{
literal|0x0034
block|,
literal|696
block|}
block|,
block|{
literal|0x00b4
block|,
literal|712
block|}
block|,
block|{
literal|0x0020
block|,
literal|728
block|}
block|,
block|{
literal|0x00a0
block|,
literal|744
block|}
block|,
block|{
literal|0x0050
block|,
literal|760
block|}
block|,
block|{
literal|0x00d0
block|,
literal|776
block|}
block|,
block|{
literal|0x004a
block|,
literal|792
block|}
block|,
block|{
literal|0x00ca
block|,
literal|808
block|}
block|,
block|{
literal|0x002a
block|,
literal|824
block|}
block|,
block|{
literal|0x00aa
block|,
literal|840
block|}
block|,
block|{
literal|0x0024
block|,
literal|856
block|}
block|,
block|{
literal|0x00a4
block|,
literal|872
block|}
block|,
block|{
literal|0x001a
block|,
literal|888
block|}
block|,
block|{
literal|0x009a
block|,
literal|904
block|}
block|,
block|{
literal|0x005a
block|,
literal|920
block|}
block|,
block|{
literal|0x00da
block|,
literal|936
block|}
block|,
block|{
literal|0x0052
block|,
literal|952
block|}
block|,
block|{
literal|0x00d2
block|,
literal|968
block|}
block|,
block|{
literal|0x004c
block|,
literal|984
block|}
block|,
block|{
literal|0x00cc
block|,
literal|1000
block|}
block|,
block|{
literal|0x002c
block|,
literal|1016
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|TermB
specifier|static
name|struct
name|proto
name|TermB
index|[]
init|=
block|{
block|{
literal|0x03b0
block|,
literal|10
block|}
block|,
block|{
literal|0x0002
block|,
literal|19
block|}
block|,
block|{
literal|0x0003
block|,
literal|34
block|}
block|,
block|{
literal|0x0001
block|,
literal|50
block|}
block|,
block|{
literal|0x0006
block|,
literal|67
block|}
block|,
block|{
literal|0x000c
block|,
literal|84
block|}
block|,
block|{
literal|0x0004
block|,
literal|100
block|}
block|,
block|{
literal|0x0018
block|,
literal|117
block|}
block|,
block|{
literal|0x0028
block|,
literal|134
block|}
block|,
block|{
literal|0x0008
block|,
literal|150
block|}
block|,
block|{
literal|0x0010
block|,
literal|167
block|}
block|,
block|{
literal|0x0050
block|,
literal|183
block|}
block|,
block|{
literal|0x0070
block|,
literal|199
block|}
block|,
block|{
literal|0x0020
block|,
literal|216
block|}
block|,
block|{
literal|0x00e0
block|,
literal|232
block|}
block|,
block|{
literal|0x0030
block|,
literal|249
block|}
block|,
block|{
literal|0x03a0
block|,
literal|266
block|}
block|,
block|{
literal|0x0060
block|,
literal|282
block|}
block|,
block|{
literal|0x0040
block|,
literal|298
block|}
block|,
block|{
literal|0x0730
block|,
literal|315
block|}
block|,
block|{
literal|0x00b0
block|,
literal|331
block|}
block|,
block|{
literal|0x01b0
block|,
literal|347
block|}
block|,
block|{
literal|0x0760
block|,
literal|363
block|}
block|,
block|{
literal|0x00a0
block|,
literal|379
block|}
block|,
block|{
literal|0x0740
block|,
literal|395
block|}
block|,
block|{
literal|0x00c0
block|,
literal|411
block|}
block|,
block|{
literal|0x0530
block|,
literal|428
block|}
block|,
block|{
literal|0x0d30
block|,
literal|444
block|}
block|,
block|{
literal|0x0330
block|,
literal|460
block|}
block|,
block|{
literal|0x0b30
block|,
literal|476
block|}
block|,
block|{
literal|0x0160
block|,
literal|492
block|}
block|,
block|{
literal|0x0960
block|,
literal|508
block|}
block|,
block|{
literal|0x0560
block|,
literal|524
block|}
block|,
block|{
literal|0x0d60
block|,
literal|540
block|}
block|,
block|{
literal|0x04b0
block|,
literal|556
block|}
block|,
block|{
literal|0x0cb0
block|,
literal|572
block|}
block|,
block|{
literal|0x02b0
block|,
literal|588
block|}
block|,
block|{
literal|0x0ab0
block|,
literal|604
block|}
block|,
block|{
literal|0x06b0
block|,
literal|620
block|}
block|,
block|{
literal|0x0eb0
block|,
literal|636
block|}
block|,
block|{
literal|0x0360
block|,
literal|652
block|}
block|,
block|{
literal|0x0b60
block|,
literal|668
block|}
block|,
block|{
literal|0x05b0
block|,
literal|684
block|}
block|,
block|{
literal|0x0db0
block|,
literal|700
block|}
block|,
block|{
literal|0x02a0
block|,
literal|716
block|}
block|,
block|{
literal|0x0aa0
block|,
literal|732
block|}
block|,
block|{
literal|0x06a0
block|,
literal|748
block|}
block|,
block|{
literal|0x0ea0
block|,
literal|764
block|}
block|,
block|{
literal|0x0260
block|,
literal|780
block|}
block|,
block|{
literal|0x0a60
block|,
literal|796
block|}
block|,
block|{
literal|0x04a0
block|,
literal|812
block|}
block|,
block|{
literal|0x0ca0
block|,
literal|828
block|}
block|,
block|{
literal|0x0240
block|,
literal|844
block|}
block|,
block|{
literal|0x0ec0
block|,
literal|860
block|}
block|,
block|{
literal|0x01c0
block|,
literal|876
block|}
block|,
block|{
literal|0x0e40
block|,
literal|892
block|}
block|,
block|{
literal|0x0140
block|,
literal|908
block|}
block|,
block|{
literal|0x01a0
block|,
literal|924
block|}
block|,
block|{
literal|0x09a0
block|,
literal|940
block|}
block|,
block|{
literal|0x0d40
block|,
literal|956
block|}
block|,
block|{
literal|0x0340
block|,
literal|972
block|}
block|,
block|{
literal|0x05a0
block|,
literal|988
block|}
block|,
block|{
literal|0x0660
block|,
literal|1004
block|}
block|,
block|{
literal|0x0e60
block|,
literal|1020
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|EOLH
specifier|static
name|struct
name|proto
name|EOLH
index|[]
init|=
block|{
block|{
literal|0x0000
block|,
literal|11
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt
begin_function
specifier|static
name|void
DECL|function|FillTable
name|FillTable
parameter_list|(
name|TIFFFaxTabEnt
modifier|*
name|T
parameter_list|,
name|int
name|Size
parameter_list|,
name|struct
name|proto
modifier|*
name|P
parameter_list|,
name|int
name|State
parameter_list|)
block|{
name|int
name|limit
init|=
literal|1
operator|<<
name|Size
decl_stmt|;
while|while
condition|(
name|P
operator|->
name|val
condition|)
block|{
name|int
name|width
init|=
name|P
operator|->
name|val
operator|&
literal|15
decl_stmt|;
name|int
name|param
init|=
name|P
operator|->
name|val
operator|>>
literal|4
decl_stmt|;
name|int
name|incr
init|=
literal|1
operator|<<
name|width
decl_stmt|;
name|int
name|code
decl_stmt|;
for|for
control|(
name|code
operator|=
name|P
operator|->
name|code
init|;
name|code
operator|<
name|limit
condition|;
name|code
operator|+=
name|incr
control|)
block|{
name|TIFFFaxTabEnt
modifier|*
name|E
init|=
name|T
operator|+
name|code
decl_stmt|;
name|E
operator|->
name|State
operator|=
name|State
expr_stmt|;
name|E
operator|->
name|Width
operator|=
name|width
expr_stmt|;
name|E
operator|->
name|Param
operator|=
name|param
expr_stmt|;
block|}
name|P
operator|++
expr_stmt|;
block|}
block|}
end_function
begin_decl_stmt
DECL|variable|storage_class
specifier|static
name|char
modifier|*
name|storage_class
init|=
literal|""
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|const_class
specifier|static
name|char
modifier|*
name|const_class
init|=
literal|""
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|packoutput
specifier|static
name|int
name|packoutput
init|=
literal|1
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|prebrace
specifier|static
name|char
modifier|*
name|prebrace
init|=
literal|""
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|postbrace
specifier|static
name|char
modifier|*
name|postbrace
init|=
literal|""
decl_stmt|;
end_decl_stmt
begin_function
name|void
DECL|function|WriteTable
name|WriteTable
parameter_list|(
name|FILE
modifier|*
name|fd
parameter_list|,
specifier|const
name|TIFFFaxTabEnt
modifier|*
name|T
parameter_list|,
name|int
name|Size
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|)
block|{
name|int
name|i
decl_stmt|;
name|char
modifier|*
name|sep
decl_stmt|;
name|fprintf
argument_list|(
name|fd
argument_list|,
literal|"%s %s TIFFFaxTabEnt %s[%d] = {"
argument_list|,
name|storage_class
argument_list|,
name|const_class
argument_list|,
name|name
argument_list|,
name|Size
argument_list|)
expr_stmt|;
if|if
condition|(
name|packoutput
condition|)
block|{
name|sep
operator|=
literal|"\n"
expr_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|Size
condition|;
name|i
operator|++
control|)
block|{
name|fprintf
argument_list|(
name|fd
argument_list|,
literal|"%s%s%d,%d,%d%s"
argument_list|,
name|sep
argument_list|,
name|prebrace
argument_list|,
name|T
operator|->
name|State
argument_list|,
name|T
operator|->
name|Width
argument_list|,
operator|(
name|int
operator|)
name|T
operator|->
name|Param
argument_list|,
name|postbrace
argument_list|)
expr_stmt|;
if|if
condition|(
operator|(
operator|(
name|i
operator|+
literal|1
operator|)
operator|%
literal|10
operator|)
operator|==
literal|0
condition|)
name|sep
operator|=
literal|",\n"
expr_stmt|;
else|else
name|sep
operator|=
literal|","
expr_stmt|;
name|T
operator|++
expr_stmt|;
block|}
block|}
else|else
block|{
name|sep
operator|=
literal|"\n "
expr_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|Size
condition|;
name|i
operator|++
control|)
block|{
name|fprintf
argument_list|(
name|fd
argument_list|,
literal|"%s%s%3d,%3d,%4d%s"
argument_list|,
name|sep
argument_list|,
name|prebrace
argument_list|,
name|T
operator|->
name|State
argument_list|,
name|T
operator|->
name|Width
argument_list|,
operator|(
name|int
operator|)
name|T
operator|->
name|Param
argument_list|,
name|postbrace
argument_list|)
expr_stmt|;
if|if
condition|(
operator|(
operator|(
name|i
operator|+
literal|1
operator|)
operator|%
literal|6
operator|)
operator|==
literal|0
condition|)
name|sep
operator|=
literal|",\n "
expr_stmt|;
else|else
name|sep
operator|=
literal|","
expr_stmt|;
name|T
operator|++
expr_stmt|;
block|}
block|}
name|fprintf
argument_list|(
name|fd
argument_list|,
literal|"\n};\n"
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/* initialise the huffman code tables */
end_comment
begin_function
name|int
DECL|function|main
name|main
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
name|argv
index|[]
parameter_list|)
block|{
name|FILE
modifier|*
name|fd
decl_stmt|;
name|char
modifier|*
name|outputfile
decl_stmt|;
name|int
name|c
decl_stmt|;
specifier|extern
name|int
name|optind
decl_stmt|;
specifier|extern
name|char
modifier|*
name|optarg
decl_stmt|;
while|while
condition|(
operator|(
name|c
operator|=
name|getopt
argument_list|(
name|argc
argument_list|,
name|argv
argument_list|,
literal|"c:s:bp"
argument_list|)
operator|)
operator|!=
operator|-
literal|1
condition|)
switch|switch
condition|(
name|c
condition|)
block|{
case|case
literal|'c'
case|:
name|const_class
operator|=
name|optarg
expr_stmt|;
break|break;
case|case
literal|'s'
case|:
name|storage_class
operator|=
name|optarg
expr_stmt|;
break|break;
case|case
literal|'p'
case|:
name|packoutput
operator|=
literal|0
expr_stmt|;
break|break;
case|case
literal|'b'
case|:
name|prebrace
operator|=
literal|"{"
expr_stmt|;
name|postbrace
operator|=
literal|"}"
expr_stmt|;
break|break;
case|case
literal|'?'
case|:
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"usage: %s [-c const] [-s storage] [-p] [-b] file\n"
argument_list|,
name|argv
index|[
literal|0
index|]
argument_list|)
expr_stmt|;
return|return
operator|(
operator|-
literal|1
operator|)
return|;
block|}
name|outputfile
operator|=
name|optind
operator|<
name|argc
condition|?
name|argv
index|[
name|optind
index|]
else|:
literal|"g3states.h"
expr_stmt|;
name|fd
operator|=
name|fopen
argument_list|(
name|outputfile
argument_list|,
literal|"w"
argument_list|)
expr_stmt|;
if|if
condition|(
name|fd
operator|==
name|NULL
condition|)
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"%s: %s: Cannot create output file.\n"
argument_list|,
name|argv
index|[
literal|0
index|]
argument_list|,
name|outputfile
argument_list|)
expr_stmt|;
return|return
operator|(
operator|-
literal|2
operator|)
return|;
block|}
name|FillTable
argument_list|(
name|MainTable
argument_list|,
literal|7
argument_list|,
name|Pass
argument_list|,
name|S_Pass
argument_list|)
expr_stmt|;
name|FillTable
argument_list|(
name|MainTable
argument_list|,
literal|7
argument_list|,
name|Horiz
argument_list|,
name|S_Horiz
argument_list|)
expr_stmt|;
name|FillTable
argument_list|(
name|MainTable
argument_list|,
literal|7
argument_list|,
name|V0
argument_list|,
name|S_V0
argument_list|)
expr_stmt|;
name|FillTable
argument_list|(
name|MainTable
argument_list|,
literal|7
argument_list|,
name|VR
argument_list|,
name|S_VR
argument_list|)
expr_stmt|;
name|FillTable
argument_list|(
name|MainTable
argument_list|,
literal|7
argument_list|,
name|VL
argument_list|,
name|S_VL
argument_list|)
expr_stmt|;
name|FillTable
argument_list|(
name|MainTable
argument_list|,
literal|7
argument_list|,
name|Ext
argument_list|,
name|S_Ext
argument_list|)
expr_stmt|;
name|FillTable
argument_list|(
name|MainTable
argument_list|,
literal|7
argument_list|,
name|EOLV
argument_list|,
name|S_EOL
argument_list|)
expr_stmt|;
name|FillTable
argument_list|(
name|WhiteTable
argument_list|,
literal|12
argument_list|,
name|MakeUpW
argument_list|,
name|S_MakeUpW
argument_list|)
expr_stmt|;
name|FillTable
argument_list|(
name|WhiteTable
argument_list|,
literal|12
argument_list|,
name|MakeUp
argument_list|,
name|S_MakeUp
argument_list|)
expr_stmt|;
name|FillTable
argument_list|(
name|WhiteTable
argument_list|,
literal|12
argument_list|,
name|TermW
argument_list|,
name|S_TermW
argument_list|)
expr_stmt|;
name|FillTable
argument_list|(
name|WhiteTable
argument_list|,
literal|12
argument_list|,
name|EOLH
argument_list|,
name|S_EOL
argument_list|)
expr_stmt|;
name|FillTable
argument_list|(
name|BlackTable
argument_list|,
literal|13
argument_list|,
name|MakeUpB
argument_list|,
name|S_MakeUpB
argument_list|)
expr_stmt|;
name|FillTable
argument_list|(
name|BlackTable
argument_list|,
literal|13
argument_list|,
name|MakeUp
argument_list|,
name|S_MakeUp
argument_list|)
expr_stmt|;
name|FillTable
argument_list|(
name|BlackTable
argument_list|,
literal|13
argument_list|,
name|TermB
argument_list|,
name|S_TermB
argument_list|)
expr_stmt|;
name|FillTable
argument_list|(
name|BlackTable
argument_list|,
literal|13
argument_list|,
name|EOLH
argument_list|,
name|S_EOL
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|fd
argument_list|,
literal|"/* WARNING, this file was automatically generated by the\n"
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|fd
argument_list|,
literal|"    mkg3states program */\n"
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|fd
argument_list|,
literal|"#include \"tiff.h\"\n"
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|fd
argument_list|,
literal|"#include \"tif_fax3.h\"\n"
argument_list|)
expr_stmt|;
name|WriteTable
argument_list|(
name|fd
argument_list|,
name|MainTable
argument_list|,
literal|128
argument_list|,
literal|"TIFFFaxMainTable"
argument_list|)
expr_stmt|;
name|WriteTable
argument_list|(
name|fd
argument_list|,
name|WhiteTable
argument_list|,
literal|4096
argument_list|,
literal|"TIFFFaxWhiteTable"
argument_list|)
expr_stmt|;
name|WriteTable
argument_list|(
name|fd
argument_list|,
name|BlackTable
argument_list|,
literal|8192
argument_list|,
literal|"TIFFFaxBlackTable"
argument_list|)
expr_stmt|;
name|fclose
argument_list|(
name|fd
argument_list|)
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function
begin_comment
comment|/* vim: set ts=8 sts=8 sw=8 noet: */
end_comment
end_unit
