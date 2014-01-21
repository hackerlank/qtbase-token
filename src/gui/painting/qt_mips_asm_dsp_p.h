begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Imagination Technologies Limited, www.imgtec.com ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QT_MIPS_ASM_DSP_H
end_ifndef
begin_define
DECL|macro|QT_MIPS_ASM_DSP_H
define|#
directive|define
name|QT_MIPS_ASM_DSP_H
end_define
begin_comment
comment|//
end_comment
begin_comment
comment|//  W A R N I N G
end_comment
begin_comment
comment|//  -------------
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|// This file is not part of the Qt API.  It exists purely as an
end_comment
begin_comment
comment|// implementation detail.  This header file may change from version to
end_comment
begin_comment
comment|// version without notice, or even be removed.
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|// We mean it.
end_comment
begin_comment
comment|//
end_comment
begin_if
if|#
directive|if
literal|0
end_if
begin_pragma
pragma|#
directive|pragma
name|qt_sync_stop_processing
end_pragma
begin_endif
endif|#
directive|endif
end_endif
begin_define
DECL|macro|zero
define|#
directive|define
name|zero
value|$0
end_define
begin_define
DECL|macro|AT
define|#
directive|define
name|AT
value|$1
end_define
begin_define
DECL|macro|v0
define|#
directive|define
name|v0
value|$2
end_define
begin_define
DECL|macro|v1
define|#
directive|define
name|v1
value|$3
end_define
begin_define
DECL|macro|a0
define|#
directive|define
name|a0
value|$4
end_define
begin_define
DECL|macro|a1
define|#
directive|define
name|a1
value|$5
end_define
begin_define
DECL|macro|a2
define|#
directive|define
name|a2
value|$6
end_define
begin_define
DECL|macro|a3
define|#
directive|define
name|a3
value|$7
end_define
begin_define
DECL|macro|t0
define|#
directive|define
name|t0
value|$8
end_define
begin_define
DECL|macro|t1
define|#
directive|define
name|t1
value|$9
end_define
begin_define
DECL|macro|t2
define|#
directive|define
name|t2
value|$10
end_define
begin_define
DECL|macro|t3
define|#
directive|define
name|t3
value|$11
end_define
begin_define
DECL|macro|t4
define|#
directive|define
name|t4
value|$12
end_define
begin_define
DECL|macro|t5
define|#
directive|define
name|t5
value|$13
end_define
begin_define
DECL|macro|t6
define|#
directive|define
name|t6
value|$14
end_define
begin_define
DECL|macro|t7
define|#
directive|define
name|t7
value|$15
end_define
begin_define
DECL|macro|s0
define|#
directive|define
name|s0
value|$16
end_define
begin_define
DECL|macro|s1
define|#
directive|define
name|s1
value|$17
end_define
begin_define
DECL|macro|s2
define|#
directive|define
name|s2
value|$18
end_define
begin_define
DECL|macro|s3
define|#
directive|define
name|s3
value|$19
end_define
begin_define
DECL|macro|s4
define|#
directive|define
name|s4
value|$20
end_define
begin_define
DECL|macro|s5
define|#
directive|define
name|s5
value|$21
end_define
begin_define
DECL|macro|s6
define|#
directive|define
name|s6
value|$22
end_define
begin_define
DECL|macro|s7
define|#
directive|define
name|s7
value|$23
end_define
begin_define
DECL|macro|t8
define|#
directive|define
name|t8
value|$24
end_define
begin_define
DECL|macro|t9
define|#
directive|define
name|t9
value|$25
end_define
begin_define
DECL|macro|k0
define|#
directive|define
name|k0
value|$26
end_define
begin_define
DECL|macro|k1
define|#
directive|define
name|k1
value|$27
end_define
begin_define
DECL|macro|gp
define|#
directive|define
name|gp
value|$28
end_define
begin_define
DECL|macro|sp
define|#
directive|define
name|sp
value|$29
end_define
begin_define
DECL|macro|fp
define|#
directive|define
name|fp
value|$30
end_define
begin_define
DECL|macro|s8
define|#
directive|define
name|s8
value|$30
end_define
begin_define
DECL|macro|ra
define|#
directive|define
name|ra
value|$31
end_define
begin_comment
comment|/*  * LEAF_MIPS32R2 - declare leaf_mips32r2 routine  */
end_comment
begin_define
DECL|macro|LEAF_MIPS32R2
define|#
directive|define
name|LEAF_MIPS32R2
parameter_list|(
name|symbol
parameter_list|)
define|\
value|.globl  symbol;                         \                 .align  2;                              \                 .type   symbol,@function;               \                 .ent    symbol,0;                       \ symbol:         .frame  sp, 0, ra;                      \                 .set    arch=mips32r2;                  \                 .set    noreorder;
end_define
begin_comment
comment|/*  * LEAF_MIPS_DSP - declare leaf_mips_dsp routine  */
end_comment
begin_define
DECL|macro|LEAF_MIPS_DSP
define|#
directive|define
name|LEAF_MIPS_DSP
parameter_list|(
name|symbol
parameter_list|)
define|\
value|LEAF_MIPS32R2(symbol)                                   \                 .set    dsp;
end_define
begin_comment
comment|/*  * LEAF_MIPS_DSPR2 - declare leaf_mips_dspr2 routine  */
end_comment
begin_define
DECL|macro|LEAF_MIPS_DSPR2
define|#
directive|define
name|LEAF_MIPS_DSPR2
parameter_list|(
name|symbol
parameter_list|)
define|\
value|LEAF_MIPS32R2(symbol)                                   \                 .set   dspr2;
end_define
begin_comment
comment|/*  * END - mark end of function  */
end_comment
begin_define
DECL|macro|END
define|#
directive|define
name|END
parameter_list|(
name|function
parameter_list|)
define|\
value|.set    reorder;                        \                 .end    function;                       \                 .size   function,.-function
end_define
begin_comment
comment|/*  * BYTE_MUL operation on two pixels (in_1 and in_2) with two  * multiplicator bytes, repl_a1 and repl_a2, which should be  * prepered with:  *   replv.ph   repl_a1, a1  *   replv.ph   repl_a2, a2  * to became such as:  *   repl_a1 = | 00 | a1 | 00 | a1 |  *   repl_a2 = | 00 | a2 | 00 | a2 |  *  * rounding_factor must have following value:  *   li    rounding_factor, 0x00800080  *  * scratch(n) - temporary registers  *  * in_const: 1 -> (default) causes that in_1, in_2  *           registers will remain unchanged after usage  *           0 -> (or anything different then 1) causes  *           that registers repl_a1, repl_a2 remain  *           unchanged after usage  */
end_comment
begin_expr_stmt
DECL|variable|in_2
DECL|variable|out_1
operator|.
name|macro
name|BYTE_MUL_x2
name|in_1
operator|,
name|in_2
operator|,
name|out_1
operator|,
name|out_2
expr|\
DECL|variable|repl_a1
DECL|variable|repl_a2
DECL|variable|rounding_factor
name|repl_a1
operator|,
name|repl_a2
operator|,
name|rounding_factor
operator|,
expr_stmt|\
DECL|variable|scratch1
DECL|variable|scratch2
DECL|variable|scratch3
DECL|variable|scratch4
name|scratch1
operator|,
name|scratch2
operator|,
name|scratch3
operator|,
name|scratch4
operator|,
expr_stmt|\
DECL|variable|in_const
name|in_const
operator|=
literal|1
DECL|variable|in_1
name|muleu_s
operator|.
name|ph
operator|.
name|qbl
operator|\
name|scratch1
operator|,
operator|\
name|in_1
operator|,
operator|\
name|repl_a1
DECL|variable|in_1
name|muleu_s
operator|.
name|ph
operator|.
name|qbr
operator|\
name|scratch2
operator|,
operator|\
name|in_1
operator|,
operator|\
name|repl_a1
DECL|variable|in_2
name|muleu_s
operator|.
name|ph
operator|.
name|qbl
operator|\
name|scratch3
operator|,
operator|\
name|in_2
operator|,
operator|\
name|repl_a2
DECL|variable|in_2
name|muleu_s
operator|.
name|ph
operator|.
name|qbr
operator|\
name|scratch4
operator|,
operator|\
name|in_2
operator|,
operator|\
name|repl_a2
operator|.
expr|if
operator|\
name|in_const
operator|==
literal|1
name|preceu
operator|.
name|ph
operator|.
name|qbla
operator|\
name|repl_a1
operator|,
operator|\
name|scratch1
name|preceu
operator|.
name|ph
operator|.
name|qbla
operator|\
name|repl_a2
operator|,
operator|\
name|scratch2
name|preceu
operator|.
name|ph
operator|.
name|qbla
operator|\
name|out_1
operator|,
operator|\
name|scratch3
name|preceu
operator|.
name|ph
operator|.
name|qbla
operator|\
name|out_2
operator|,
operator|\
name|scratch4
DECL|variable|scratch1
DECL|variable|repl_a1
name|addu
operator|\
name|scratch1
operator|,
operator|\
name|repl_a1
operator|,
operator|\
name|scratch1
DECL|variable|scratch2
DECL|variable|repl_a2
name|addu
operator|\
name|scratch2
operator|,
operator|\
name|repl_a2
operator|,
operator|\
name|scratch2
operator|.
expr|else
name|preceu
operator|.
name|ph
operator|.
name|qbla
operator|\
name|in_1
operator|,
operator|\
name|scratch1
name|preceu
operator|.
name|ph
operator|.
name|qbla
operator|\
name|in_2
operator|,
operator|\
name|scratch2
name|preceu
operator|.
name|ph
operator|.
name|qbla
operator|\
name|out_1
operator|,
operator|\
name|scratch3
name|preceu
operator|.
name|ph
operator|.
name|qbla
operator|\
name|out_2
operator|,
operator|\
name|scratch4
DECL|variable|scratch1
DECL|variable|in_1
name|addu
operator|\
name|scratch1
operator|,
operator|\
name|in_1
operator|,
operator|\
name|scratch1
DECL|variable|scratch2
DECL|variable|in_2
name|addu
operator|\
name|scratch2
operator|,
operator|\
name|in_2
operator|,
operator|\
name|scratch2
operator|.
name|endif
DECL|variable|out_1
name|addu
operator|\
name|out_1
operator|,
operator|\
name|out_1
operator|,
operator|\
name|scratch3
DECL|variable|out_2
DECL|variable|out_2
name|addu
operator|\
name|out_2
operator|,
operator|\
name|out_2
operator|,
operator|\
name|scratch4
DECL|variable|scratch1
DECL|variable|scratch1
name|addu
operator|\
name|scratch1
operator|,
operator|\
name|scratch1
operator|,
operator|\
name|rounding_factor
DECL|variable|scratch2
DECL|variable|scratch2
name|addu
operator|\
name|scratch2
operator|,
operator|\
name|scratch2
operator|,
operator|\
name|rounding_factor
DECL|variable|scratch3
DECL|variable|out_1
name|addu
operator|\
name|scratch3
operator|,
operator|\
name|out_1
operator|,
operator|\
name|rounding_factor
DECL|variable|scratch4
DECL|variable|out_2
name|addu
operator|\
name|scratch4
operator|,
operator|\
name|out_2
operator|,
operator|\
name|rounding_factor
DECL|variable|scratch1
name|precrq
operator|.
name|qb
operator|.
name|ph
operator|\
name|out_1
operator|,
operator|\
name|scratch1
operator|,
operator|\
name|scratch2
DECL|variable|scratch3
name|precrq
operator|.
name|qb
operator|.
name|ph
operator|\
name|out_2
operator|,
operator|\
name|scratch3
operator|,
operator|\
name|scratch4
operator|.
name|endm
comment|/*  * BYTE_MUL operation on one pixel (in_1) with  * multiplicator byte, repl_a1, which should be  * prepered with:  *   replv.ph   repl_a1, a1  * to became such as:  *   repl_a1 = | 00 | a1 | 00 | a1 |  *  * rounding_factor must have following value:  *   li    rounding_factor, 0x00800080  *  * scratch(n) - temporary registers  */
DECL|variable|out_1
operator|.
name|macro
name|BYTE_MUL
name|in_1
operator|,
name|out_1
operator|,
expr_stmt|\
DECL|variable|repl_a1
DECL|variable|rounding_factor
name|repl_a1
operator|,
name|rounding_factor
operator|,
expr_stmt|\
DECL|variable|scratch1
DECL|variable|scratch2
DECL|variable|scratch3
name|scratch1
operator|,
name|scratch2
operator|,
name|scratch3
operator|,
name|scratch4
DECL|variable|in_1
name|muleu_s
operator|.
name|ph
operator|.
name|qbl
operator|\
name|scratch1
operator|,
operator|\
name|in_1
operator|,
operator|\
name|repl_a1
DECL|variable|in_1
name|muleu_s
operator|.
name|ph
operator|.
name|qbr
operator|\
name|scratch2
operator|,
operator|\
name|in_1
operator|,
operator|\
name|repl_a1
name|preceu
operator|.
name|ph
operator|.
name|qbla
operator|\
name|scratch3
operator|,
operator|\
name|scratch1
name|preceu
operator|.
name|ph
operator|.
name|qbla
operator|\
name|scratch4
operator|,
operator|\
name|scratch2
DECL|variable|scratch1
DECL|variable|scratch1
name|addu
operator|\
name|scratch1
operator|,
operator|\
name|scratch1
operator|,
operator|\
name|scratch3
DECL|variable|scratch1
DECL|variable|scratch1
name|addu
operator|\
name|scratch1
operator|,
operator|\
name|scratch1
operator|,
operator|\
name|rounding_factor
DECL|variable|scratch2
DECL|variable|scratch2
name|addu
operator|\
name|scratch2
operator|,
operator|\
name|scratch2
operator|,
operator|\
name|scratch4
DECL|variable|scratch2
DECL|variable|scratch2
name|addu
operator|\
name|scratch2
operator|,
operator|\
name|scratch2
operator|,
operator|\
name|rounding_factor
DECL|variable|scratch1
name|precrq
operator|.
name|qb
operator|.
name|ph
operator|\
name|out_1
operator|,
operator|\
name|scratch1
operator|,
operator|\
name|scratch2
operator|.
name|endm
comment|/*  * macro for INTERPOLATE_PIXEL_255 operation  * in_1 - First value to multiply  * mul_1 - Multiplicator byte for first value  * in_2 - Second value to multiply  * mul_2 - Multiplicator byte for second value  * rounding_factor and andi_factor should be prepared  * as:  *     li     rounding_factor, 0x00800080  *     li     andi_factor,     0xff00ff00  * scratch(n) - temporary registers  */
DECL|variable|mul_1
operator|.
name|macro
name|INTERPOLATE_PIXEL_255
name|in_1
operator|,
name|mul_1
operator|,
expr_stmt|\
DECL|variable|in_2
DECL|variable|mul_2
name|in_2
operator|,
name|mul_2
operator|,
expr_stmt|\
DECL|variable|out_1
name|out_1
operator|,
expr_stmt|\
DECL|variable|rounding_factor
name|rounding_factor
operator|,
name|andi_factor
expr|\
DECL|variable|scratch1
DECL|variable|scratch2
DECL|variable|scratch3
name|scratch1
operator|,
name|scratch2
operator|,
name|scratch3
operator|,
name|scratch4
empty|# x part
name|preceu
operator|.
name|ph
operator|.
name|qbra
operator|\
name|scratch1
operator|,
operator|\
name|in_1
name|preceu
operator|.
name|ph
operator|.
name|qbra
operator|\
name|scratch2
operator|,
operator|\
name|in_2
DECL|variable|scratch1
DECL|variable|scratch1
name|mul
operator|\
name|scratch1
operator|,
operator|\
name|scratch1
operator|,
operator|\
name|mul_1
DECL|variable|scratch2
DECL|variable|scratch2
name|mul
operator|\
name|scratch2
operator|,
operator|\
name|scratch2
operator|,
operator|\
name|mul_2
empty|# x>>8 part
name|preceu
operator|.
name|ph
operator|.
name|qbla
operator|\
name|scratch3
operator|,
operator|\
name|in_1
name|preceu
operator|.
name|ph
operator|.
name|qbla
operator|\
name|scratch4
operator|,
operator|\
name|in_2
DECL|variable|scratch3
DECL|variable|scratch3
name|mul
operator|\
name|scratch3
operator|,
operator|\
name|scratch3
operator|,
operator|\
name|mul_1
DECL|variable|scratch4
DECL|variable|scratch4
name|mul
operator|\
name|scratch4
operator|,
operator|\
name|scratch4
operator|,
operator|\
name|mul_2
empty|# x part
DECL|variable|scratch1
DECL|variable|scratch1
name|addu
operator|\
name|scratch1
operator|,
operator|\
name|scratch1
operator|,
operator|\
name|scratch2
name|preceu
operator|.
name|ph
operator|.
name|qbla
operator|\
name|scratch2
operator|,
operator|\
name|scratch1
DECL|variable|scratch1
DECL|variable|scratch1
name|addu
operator|\
name|scratch1
operator|,
operator|\
name|scratch1
operator|,
operator|\
name|scratch2
DECL|variable|scratch1
DECL|variable|scratch1
name|addu
operator|\
name|scratch1
operator|,
operator|\
name|scratch1
operator|,
operator|\
name|rounding_factor
name|preceu
operator|.
name|ph
operator|.
name|qbla
operator|\
name|scratch1
operator|,
operator|\
name|scratch1
empty|# x>>8 part
DECL|variable|scratch3
DECL|variable|scratch3
name|addu
operator|\
name|scratch3
operator|,
operator|\
name|scratch3
operator|,
operator|\
name|scratch4
name|preceu
operator|.
name|ph
operator|.
name|qbla
operator|\
name|scratch4
operator|,
operator|\
name|scratch3
DECL|variable|scratch3
DECL|variable|scratch3
name|addu
operator|\
name|scratch3
operator|,
operator|\
name|scratch3
operator|,
operator|\
name|scratch4
DECL|variable|scratch3
DECL|variable|scratch3
name|addu
operator|\
name|scratch3
operator|,
operator|\
name|scratch3
operator|,
operator|\
name|rounding_factor
DECL|variable|scratch3
DECL|variable|scratch3
name|and
operator|\
name|scratch3
operator|,
operator|\
name|scratch3
operator|,
operator|\
name|andi_factor
DECL|variable|out_1
DECL|variable|scratch1
name|or
operator|\
name|out_1
operator|,
operator|\
name|scratch1
operator|,
operator|\
name|scratch3
operator|.
name|endm
comment|/*  * Checks if stack offset is big enough for storing/restoring regs_num  * number of register to/from stack. Stack offset must be greater than  * or equal to the number of bytes needed for storing registers (regs_num*4).  * Since MIPS ABI allows usage of first 16 bytes of stack frame (this is  * preserved for input arguments of the functions, already stored in a0-a3),  * stack size can be further optimized by utilizing this space.  */
operator|.
name|macro
name|CHECK_STACK_OFFSET
name|regs_num
operator|,
name|stack_offset
operator|.
expr|if
operator|\
name|stack_offset
operator|<
operator|\
name|regs_num
operator|*
literal|4
operator|-
literal|16
operator|.
name|error
literal|"Stack offset too small."
operator|.
name|endif
operator|.
name|endm
comment|/*  * Saves set of registers on stack. Maximum number of registers that  * can be saved on stack is limitted to 14 (a0-a3, v0-v1 and s0-s7).  * Stack offset is number of bytes that are added to stack pointer (sp)  * before registers are pushed in order to provide enough space on stack  * (offset must be multiple of 4, and must be big enough, as described by  * CHECK_STACK_OFFSET macro). This macro is intended to be used in  * combination with RESTORE_REGS_FROM_STACK macro. Example:  *  SAVE_REGS_ON_STACK      4, v0, v1, s0, s1  *  RESTORE_REGS_FROM_STACK 4, v0, v1, s0, s1  */
DECL|variable|r1
operator|.
name|macro
name|SAVE_REGS_ON_STACK
name|stack_offset
operator|=
literal|0
operator|,
name|r1
operator|,
expr_stmt|\
DECL|variable|r2
DECL|variable|r3
DECL|variable|r4
name|r2
operator|=
literal|0
operator|,
name|r3
operator|=
literal|0
operator|,
name|r4
operator|=
literal|0
operator|,
expr_stmt|\
DECL|variable|r5
DECL|variable|r6
DECL|variable|r7
name|r5
operator|=
literal|0
operator|,
name|r6
operator|=
literal|0
operator|,
name|r7
operator|=
literal|0
operator|,
expr_stmt|\
DECL|variable|r8
DECL|variable|r9
DECL|variable|r10
name|r8
operator|=
literal|0
operator|,
name|r9
operator|=
literal|0
operator|,
name|r10
operator|=
literal|0
operator|,
expr_stmt|\
DECL|variable|r11
DECL|variable|r12
DECL|variable|r13
name|r11
operator|=
literal|0
operator|,
name|r12
operator|=
literal|0
operator|,
name|r13
operator|=
literal|0
operator|,
expr_stmt|\
DECL|variable|r14
name|r14
operator|=
literal|0
operator|.
end_expr_stmt
begin_if
if|if
condition|(
operator|\
name|stack_offset
operator|<
literal|0
condition|)
operator|||
operator|(
operator|\
name|stack_offset
operator|-
operator|(
operator|\
name|stack_offset
operator|/
literal|4
operator|)
operator|*
literal|4
operator|)
operator|.
name|error
literal|"Stack offset must be positive and multiple of 4."
operator|.
name|endif
operator|.
expr|if
operator|\
name|stack_offset
operator|!=
literal|0
DECL|variable|sp
name|addiu
name|sp
operator|,
name|sp
operator|,
operator|-
operator|\
name|stack_offset
operator|.
name|endif
name|sw
operator|\
name|r1
operator|,
literal|0
operator|(
name|sp
operator|)
operator|.
expr|if
operator|\
name|r2
operator|!=
literal|0
name|sw
operator|\
name|r2
operator|,
literal|4
operator|(
name|sp
operator|)
operator|.
name|endif
operator|.
expr|if
operator|\
name|r3
operator|!=
literal|0
name|sw
operator|\
name|r3
operator|,
literal|8
operator|(
name|sp
operator|)
operator|.
name|endif
operator|.
expr|if
operator|\
name|r4
operator|!=
literal|0
name|sw
operator|\
name|r4
operator|,
literal|12
operator|(
name|sp
operator|)
operator|.
name|endif
operator|.
expr|if
operator|\
name|r5
operator|!=
literal|0
name|CHECK_STACK_OFFSET
literal|5
operator|,
operator|\
name|stack_offset
DECL|variable|r5
name|sw
operator|\
name|r5
operator|,
literal|16
operator|(
name|sp
operator|)
operator|.
name|endif
operator|.
expr|if
operator|\
name|r6
operator|!=
literal|0
name|CHECK_STACK_OFFSET
literal|6
operator|,
operator|\
name|stack_offset
DECL|variable|r6
name|sw
operator|\
name|r6
operator|,
literal|20
operator|(
name|sp
operator|)
operator|.
name|endif
operator|.
expr|if
operator|\
name|r7
operator|!=
literal|0
name|CHECK_STACK_OFFSET
literal|7
operator|,
operator|\
name|stack_offset
DECL|variable|r7
name|sw
operator|\
name|r7
operator|,
literal|24
operator|(
name|sp
operator|)
operator|.
name|endif
operator|.
expr|if
operator|\
name|r8
operator|!=
literal|0
name|CHECK_STACK_OFFSET
literal|8
operator|,
operator|\
name|stack_offset
DECL|variable|r8
name|sw
operator|\
name|r8
operator|,
literal|28
operator|(
name|sp
operator|)
operator|.
name|endif
operator|.
expr|if
operator|\
name|r9
operator|!=
literal|0
name|CHECK_STACK_OFFSET
literal|9
operator|,
operator|\
name|stack_offset
DECL|variable|r9
name|sw
operator|\
name|r9
operator|,
literal|32
operator|(
name|sp
operator|)
operator|.
name|endif
operator|.
expr|if
operator|\
name|r10
operator|!=
literal|0
name|CHECK_STACK_OFFSET
literal|10
operator|,
operator|\
name|stack_offset
DECL|variable|r10
name|sw
operator|\
name|r10
operator|,
literal|36
operator|(
name|sp
operator|)
operator|.
name|endif
operator|.
expr|if
operator|\
name|r11
operator|!=
literal|0
name|CHECK_STACK_OFFSET
literal|11
operator|,
operator|\
name|stack_offset
DECL|variable|r11
name|sw
operator|\
name|r11
operator|,
literal|40
operator|(
name|sp
operator|)
operator|.
name|endif
operator|.
expr|if
operator|\
name|r12
operator|!=
literal|0
name|CHECK_STACK_OFFSET
literal|12
operator|,
operator|\
name|stack_offset
DECL|variable|r12
name|sw
operator|\
name|r12
operator|,
literal|44
operator|(
name|sp
operator|)
operator|.
name|endif
operator|.
expr|if
operator|\
name|r13
operator|!=
literal|0
name|CHECK_STACK_OFFSET
literal|13
operator|,
operator|\
name|stack_offset
DECL|variable|r13
name|sw
operator|\
name|r13
operator|,
literal|48
operator|(
name|sp
operator|)
operator|.
name|endif
operator|.
expr|if
operator|\
name|r14
operator|!=
literal|0
name|CHECK_STACK_OFFSET
literal|14
operator|,
operator|\
name|stack_offset
DECL|variable|r14
name|sw
operator|\
name|r14
operator|,
literal|52
operator|(
name|sp
operator|)
operator|.
name|endif
operator|.
name|endm
comment|/*  * Restores set of registers from stack. Maximum number of registers that  * can be restored from stack is limitted to 14 (a0-a3, v0-v1 and s0-s7).  * Stack offset is number of bytes that are added to stack pointer (sp)  * after registers are restored (offset must be multiple of 4, and must  * be big enough, as described by CHECK_STACK_OFFSET macro). This macro is  * intended to be used in combination with RESTORE_REGS_FROM_STACK macro.  * Example:  *  SAVE_REGS_ON_STACK      4, v0, v1, s0, s1  *  RESTORE_REGS_FROM_STACK 4, v0, v1, s0, s1  */
DECL|variable|r1
operator|.
name|macro
name|RESTORE_REGS_FROM_STACK
name|stack_offset
operator|=
literal|0
operator|,
name|r1
operator|,
expr_stmt|\
DECL|variable|r2
DECL|variable|r3
DECL|variable|r4
name|r2
operator|=
literal|0
operator|,
name|r3
operator|=
literal|0
operator|,
name|r4
operator|=
literal|0
operator|,
expr_stmt|\
DECL|variable|r5
DECL|variable|r6
DECL|variable|r7
name|r5
operator|=
literal|0
operator|,
name|r6
operator|=
literal|0
operator|,
name|r7
operator|=
literal|0
operator|,
expr_stmt|\
DECL|variable|r8
DECL|variable|r9
DECL|variable|r10
name|r8
operator|=
literal|0
operator|,
name|r9
operator|=
literal|0
operator|,
name|r10
operator|=
literal|0
operator|,
expr_stmt|\
DECL|variable|r11
DECL|variable|r12
DECL|variable|r13
name|r11
operator|=
literal|0
operator|,
name|r12
operator|=
literal|0
operator|,
name|r13
operator|=
literal|0
operator|,
expr_stmt|\
DECL|variable|r14
name|r14
operator|=
literal|0
operator|.
end_if
begin_if
if|if
condition|(
operator|\
name|stack_offset
operator|<
literal|0
condition|)
operator|||
operator|(
operator|\
name|stack_offset
operator|-
operator|(
operator|\
name|stack_offset
operator|/
literal|4
operator|)
operator|*
literal|4
operator|)
operator|.
name|error
literal|"Stack offset must be pozitive and multiple of 4."
operator|.
name|endif
name|lw
operator|\
name|r1
operator|,
literal|0
operator|(
name|sp
operator|)
operator|.
expr|if
operator|\
name|r2
operator|!=
literal|0
name|lw
operator|\
name|r2
operator|,
literal|4
operator|(
name|sp
operator|)
operator|.
name|endif
operator|.
expr|if
operator|\
name|r3
operator|!=
literal|0
name|lw
operator|\
name|r3
operator|,
literal|8
operator|(
name|sp
operator|)
operator|.
name|endif
operator|.
expr|if
operator|\
name|r4
operator|!=
literal|0
name|lw
operator|\
name|r4
operator|,
literal|12
operator|(
name|sp
operator|)
operator|.
name|endif
operator|.
expr|if
operator|\
name|r5
operator|!=
literal|0
name|CHECK_STACK_OFFSET
literal|5
operator|,
operator|\
name|stack_offset
DECL|variable|r5
name|lw
operator|\
name|r5
operator|,
literal|16
operator|(
name|sp
operator|)
operator|.
name|endif
operator|.
expr|if
operator|\
name|r6
operator|!=
literal|0
name|CHECK_STACK_OFFSET
literal|6
operator|,
operator|\
name|stack_offset
DECL|variable|r6
name|lw
operator|\
name|r6
operator|,
literal|20
operator|(
name|sp
operator|)
operator|.
name|endif
operator|.
expr|if
operator|\
name|r7
operator|!=
literal|0
name|CHECK_STACK_OFFSET
literal|7
operator|,
operator|\
name|stack_offset
DECL|variable|r7
name|lw
operator|\
name|r7
operator|,
literal|24
operator|(
name|sp
operator|)
operator|.
name|endif
operator|.
expr|if
operator|\
name|r8
operator|!=
literal|0
name|CHECK_STACK_OFFSET
literal|8
operator|,
operator|\
name|stack_offset
DECL|variable|r8
name|lw
operator|\
name|r8
operator|,
literal|28
operator|(
name|sp
operator|)
operator|.
name|endif
operator|.
expr|if
operator|\
name|r9
operator|!=
literal|0
name|CHECK_STACK_OFFSET
literal|9
operator|,
operator|\
name|stack_offset
DECL|variable|r9
name|lw
operator|\
name|r9
operator|,
literal|32
operator|(
name|sp
operator|)
operator|.
name|endif
operator|.
expr|if
operator|\
name|r10
operator|!=
literal|0
name|CHECK_STACK_OFFSET
literal|10
operator|,
operator|\
name|stack_offset
DECL|variable|r10
name|lw
operator|\
name|r10
operator|,
literal|36
operator|(
name|sp
operator|)
operator|.
name|endif
operator|.
expr|if
operator|\
name|r11
operator|!=
literal|0
name|CHECK_STACK_OFFSET
literal|11
operator|,
operator|\
name|stack_offset
DECL|variable|r11
name|lw
operator|\
name|r11
operator|,
literal|40
operator|(
name|sp
operator|)
operator|.
name|endif
operator|.
expr|if
operator|\
name|r12
operator|!=
literal|0
name|CHECK_STACK_OFFSET
literal|12
operator|,
operator|\
name|stack_offset
DECL|variable|r12
name|lw
operator|\
name|r12
operator|,
literal|44
operator|(
name|sp
operator|)
operator|.
name|endif
operator|.
expr|if
operator|\
name|r13
operator|!=
literal|0
name|CHECK_STACK_OFFSET
literal|13
operator|,
operator|\
name|stack_offset
DECL|variable|r13
name|lw
operator|\
name|r13
operator|,
literal|48
operator|(
name|sp
operator|)
operator|.
name|endif
operator|.
expr|if
operator|\
name|r14
operator|!=
literal|0
name|CHECK_STACK_OFFSET
literal|14
operator|,
operator|\
name|stack_offset
DECL|variable|r14
name|lw
operator|\
name|r14
operator|,
literal|52
operator|(
name|sp
operator|)
operator|.
name|endif
operator|.
expr|if
operator|\
name|stack_offset
operator|!=
literal|0
DECL|variable|sp
name|addiu
name|sp
operator|,
name|sp
operator|,
operator|\
name|stack_offset
operator|.
name|endif
operator|.
name|endm
end_if
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_MIPS_ASM_DSP_H
end_comment
end_unit
