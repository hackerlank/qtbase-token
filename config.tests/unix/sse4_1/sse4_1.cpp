begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the config.tests of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** No Commercial Usage ** This file contains pre-release code and may not be distributed. ** You may use this file in accordance with the terms and conditions ** contained in the Technology Preview License Agreement accompanying ** this package. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights.  These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** If you have questions regarding the use of this file, please contact ** Nokia at qt-info@nokia.com. ** ** ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<smmintrin.h>
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
specifier|volatile
name|__m128
name|a
init|=
name|_mm_setzero_ps
argument_list|()
decl_stmt|;
name|_mm_ceil_ps
argument_list|(
name|a
argument_list|)
expr_stmt|;
specifier|volatile
name|__m128i
name|result
init|=
name|_mm_mullo_epi32
argument_list|(
name|_mm_set1_epi32
argument_list|(
literal|42
argument_list|)
argument_list|,
name|_mm_set1_epi32
argument_list|(
literal|64
argument_list|)
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
