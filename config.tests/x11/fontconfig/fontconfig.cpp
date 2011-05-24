begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the config.tests of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<ft2build.h>
end_include
begin_include
include|#
directive|include
include|FT_FREETYPE_H
end_include
begin_include
include|#
directive|include
file|<fontconfig/fontconfig.h>
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|FC_RGBA_UNKNOWN
end_ifndef
begin_error
error|#
directive|error
literal|"This version of fontconfig is tool old, it is missing the FC_RGBA_UNKNOWN define"
end_error
begin_endif
endif|#
directive|endif
end_endif
begin_if
if|#
directive|if
operator|(
operator|(
name|FREETYPE_MAJOR
operator|*
literal|10000
operator|+
name|FREETYPE_MINOR
operator|*
literal|100
operator|+
name|FREETYPE_PATCH
operator|)
operator|<
literal|20103
operator|)
end_if
begin_error
error|#
directive|error
literal|"This version of freetype is too old."
end_error
begin_endif
endif|#
directive|endif
end_endif
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
name|FT_Face
name|face
decl_stmt|;
name|face
operator|=
literal|0
expr_stmt|;
name|FcPattern
modifier|*
name|pattern
decl_stmt|;
name|pattern
operator|=
literal|0
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function
end_unit
