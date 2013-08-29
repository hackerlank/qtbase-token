begin_unit
begin_comment
comment|/*  * Copyright Â© 2009  Red Hat, Inc.  *  *  This is part of HarfBuzz, a text shaping library.  *  * Permission is hereby granted, without written agreement and without  * license or royalty fees, to use, copy, modify, and distribute this  * software and its documentation for any purpose, provided that the  * above copyright notice and the following two paragraphs appear in  * all copies of this software.  *  * IN NO EVENT SHALL THE COPYRIGHT HOLDER BE LIABLE TO ANY PARTY FOR  * DIRECT, INDIRECT, SPECIAL, INCIDENTAL, OR CONSEQUENTIAL DAMAGES  * ARISING OUT OF THE USE OF THIS SOFTWARE AND ITS DOCUMENTATION, EVEN  * IF THE COPYRIGHT HOLDER HAS BEEN ADVISED OF THE POSSIBILITY OF SUCH  * DAMAGE.  *  * THE COPYRIGHT HOLDER SPECIFICALLY DISCLAIMS ANY WARRANTIES, INCLUDING,  * BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND  * FITNESS FOR A PARTICULAR PURPOSE.  THE SOFTWARE PROVIDED HEREUNDER IS  * ON AN "AS IS" BASIS, AND THE COPYRIGHT HOLDER HAS NO OBLIGATION TO  * PROVIDE MAINTENANCE, SUPPORT, UPDATES, ENHANCEMENTS, OR MODIFICATIONS.  *  * Red Hat Author(s): Behdad Esfahbod  */
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|HB_H
end_ifndef
begin_define
DECL|macro|HB_H
define|#
directive|define
name|HB_H
end_define
begin_define
DECL|macro|HB_H_IN
define|#
directive|define
name|HB_H_IN
end_define
begin_include
include|#
directive|include
file|"hb-blob.h"
end_include
begin_include
include|#
directive|include
file|"hb-buffer.h"
end_include
begin_include
include|#
directive|include
file|"hb-common.h"
end_include
begin_include
include|#
directive|include
file|"hb-deprecated.h"
end_include
begin_include
include|#
directive|include
file|"hb-face.h"
end_include
begin_include
include|#
directive|include
file|"hb-font.h"
end_include
begin_include
include|#
directive|include
file|"hb-set.h"
end_include
begin_include
include|#
directive|include
file|"hb-shape.h"
end_include
begin_include
include|#
directive|include
file|"hb-shape-plan.h"
end_include
begin_include
include|#
directive|include
file|"hb-unicode.h"
end_include
begin_include
include|#
directive|include
file|"hb-version.h"
end_include
begin_expr_stmt
name|HB_BEGIN_DECLS
name|HB_END_DECLS
end_expr_stmt
begin_undef
DECL|macro|HB_H_IN
undef|#
directive|undef
name|HB_H_IN
end_undef
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* HB_H */
end_comment
end_unit
