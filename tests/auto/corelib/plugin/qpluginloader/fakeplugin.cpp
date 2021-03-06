begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 Intel Corporation. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:GPL-EXCEPT$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3 as published by the Free Software ** Foundation with exceptions as appearing in the file LICENSE.GPL3-EXCEPT ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtCore/qplugin.h>
end_include
begin_if
if|#
directive|if
name|QT_POINTER_SIZE
operator|==
literal|8
end_if
begin_decl_stmt
DECL|variable|pluginSection
name|QT_PLUGIN_METADATA_SECTION
name|void
modifier|*
specifier|const
name|pluginSection
init|=
operator|(
name|void
operator|*
operator|)
operator|(
literal|0xc0ffeec0ffeeL
operator|)
decl_stmt|;
end_decl_stmt
begin_else
else|#
directive|else
end_else
begin_decl_stmt
DECL|variable|pluginSection
name|QT_PLUGIN_METADATA_SECTION
name|void
modifier|*
specifier|const
name|pluginSection
init|=
operator|(
name|void
operator|*
operator|)
literal|0xc0ffee
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_decl_stmt
DECL|variable|message
name|QT_PLUGIN_METADATA_SECTION
specifier|const
name|char
name|message
index|[]
init|=
literal|"QTMETADATA"
decl_stmt|;
end_decl_stmt
end_unit
