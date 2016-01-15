begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Intel Corporation. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the configuration of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<immintrin.h>
end_include
begin_function
DECL|function|main
name|int
name|main
parameter_list|(
name|int
parameter_list|,
name|char
modifier|*
modifier|*
parameter_list|)
block|{
comment|/* AVX */
name|_mm256_zeroall
argument_list|()
expr_stmt|;
name|__m256i
name|a
init|=
name|_mm256_setzero_si256
argument_list|()
decl_stmt|;
comment|/* AVX2 */
name|__m256i
name|b
init|=
name|_mm256_and_si256
argument_list|(
name|a
argument_list|,
name|a
argument_list|)
decl_stmt|;
name|__m256i
name|result
init|=
name|_mm256_add_epi8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
decl_stmt|;
operator|(
name|void
operator|)
name|result
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function
end_unit
