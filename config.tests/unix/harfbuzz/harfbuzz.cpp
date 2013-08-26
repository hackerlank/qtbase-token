begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the config.tests of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<harfbuzz/hb.h>
end_include
begin_if
if|#
directive|if
operator|(
operator|(
name|HB_VERSION_MAJOR
operator|*
literal|10000
operator|+
name|HB_VERSION_MINOR
operator|*
literal|100
operator|+
name|HB_VERSION_MICRO
operator|)
operator|<
literal|912
operator|)
end_if
begin_error
error|#
directive|error
literal|"This version of harfbuzz is too old."
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
name|hb_buffer_t
modifier|*
name|buffer
init|=
name|hb_buffer_create
argument_list|()
decl_stmt|;
specifier|const
name|uint16_t
name|string
index|[]
init|=
block|{
literal|'A'
block|,
literal|'b'
block|,
literal|'c'
block|}
decl_stmt|;
name|hb_buffer_add_utf16
argument_list|(
name|buffer
argument_list|,
name|string
argument_list|,
literal|3
argument_list|,
literal|0
argument_list|,
literal|3
argument_list|)
expr_stmt|;
name|hb_buffer_guess_segment_properties
argument_list|(
name|buffer
argument_list|)
expr_stmt|;
name|hb_buffer_set_flags
argument_list|(
name|buffer
argument_list|,
name|hb_buffer_flags_t
argument_list|(
name|HB_BUFFER_FLAG_PRESERVE_DEFAULT_IGNORABLES
argument_list|)
argument_list|)
expr_stmt|;
name|hb_buffer_destroy
argument_list|(
name|buffer
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function
end_unit
