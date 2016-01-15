begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the config.tests of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<pulse/pulseaudio.h>
end_include
begin_include
include|#
directive|include
file|<pulse/glib-mainloop.h>
end_include
begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|PA_API_VERSION
argument_list|)
operator|||
name|PA_API_VERSION
operator|-
literal|0
operator|!=
literal|12
end_if
begin_error
error|#
directive|error
literal|"Incompatible PulseAudio API version"
end_error
begin_endif
endif|#
directive|endif
end_endif
begin_if
if|#
directive|if
operator|!
name|PA_CHECK_VERSION
argument_list|(
literal|0
operator|,
literal|9
operator|,
literal|0
argument_list|)
end_if
begin_error
error|#
directive|error
literal|"PulseAudio version too old"
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
specifier|const
name|char
modifier|*
name|headers
init|=
name|pa_get_headers_version
argument_list|()
decl_stmt|;
specifier|const
name|char
modifier|*
name|library
init|=
name|pa_get_library_version
argument_list|()
decl_stmt|;
name|pa_glib_mainloop_new
argument_list|(
literal|0
argument_list|)
expr_stmt|;
return|return
operator|(
name|headers
operator|-
name|library
operator|)
operator|*
literal|0
return|;
block|}
end_function
end_unit
