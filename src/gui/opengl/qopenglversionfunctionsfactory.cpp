begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Klaralvdalens Datakonsult AB (KDAB) ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ** ** This file was generated by glgen version 0.1 ** Command line was: glgen ** ** glgen is Copyright (C) 2013 Klaralvdalens Datakonsult AB (KDAB) ** ** This is an auto-generated file. ** Do not edit! All changes made to it will be lost. ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qopenglversionfunctionsfactory_p.h"
end_include
begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|QT_OPENGL_ES_2
argument_list|)
end_if
begin_include
include|#
directive|include
file|"qopenglfunctions_4_5_core.h"
end_include
begin_include
include|#
directive|include
file|"qopenglfunctions_4_5_compatibility.h"
end_include
begin_include
include|#
directive|include
file|"qopenglfunctions_4_4_core.h"
end_include
begin_include
include|#
directive|include
file|"qopenglfunctions_4_4_compatibility.h"
end_include
begin_include
include|#
directive|include
file|"qopenglfunctions_4_3_core.h"
end_include
begin_include
include|#
directive|include
file|"qopenglfunctions_4_3_compatibility.h"
end_include
begin_include
include|#
directive|include
file|"qopenglfunctions_4_2_core.h"
end_include
begin_include
include|#
directive|include
file|"qopenglfunctions_4_2_compatibility.h"
end_include
begin_include
include|#
directive|include
file|"qopenglfunctions_4_1_core.h"
end_include
begin_include
include|#
directive|include
file|"qopenglfunctions_4_1_compatibility.h"
end_include
begin_include
include|#
directive|include
file|"qopenglfunctions_4_0_core.h"
end_include
begin_include
include|#
directive|include
file|"qopenglfunctions_4_0_compatibility.h"
end_include
begin_include
include|#
directive|include
file|"qopenglfunctions_3_3_core.h"
end_include
begin_include
include|#
directive|include
file|"qopenglfunctions_3_3_compatibility.h"
end_include
begin_include
include|#
directive|include
file|"qopenglfunctions_3_2_core.h"
end_include
begin_include
include|#
directive|include
file|"qopenglfunctions_3_2_compatibility.h"
end_include
begin_include
include|#
directive|include
file|"qopenglfunctions_3_1.h"
end_include
begin_include
include|#
directive|include
file|"qopenglfunctions_3_0.h"
end_include
begin_include
include|#
directive|include
file|"qopenglfunctions_2_1.h"
end_include
begin_include
include|#
directive|include
file|"qopenglfunctions_2_0.h"
end_include
begin_include
include|#
directive|include
file|"qopenglfunctions_1_5.h"
end_include
begin_include
include|#
directive|include
file|"qopenglfunctions_1_4.h"
end_include
begin_include
include|#
directive|include
file|"qopenglfunctions_1_3.h"
end_include
begin_include
include|#
directive|include
file|"qopenglfunctions_1_2.h"
end_include
begin_include
include|#
directive|include
file|"qopenglfunctions_1_1.h"
end_include
begin_include
include|#
directive|include
file|"qopenglfunctions_1_0.h"
end_include
begin_else
else|#
directive|else
end_else
begin_include
include|#
directive|include
file|"qopenglfunctions_es2.h"
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_function
name|QT_BEGIN_NAMESPACE
DECL|function|create
name|QAbstractOpenGLFunctions
modifier|*
name|QOpenGLVersionFunctionsFactory
operator|::
name|create
parameter_list|(
specifier|const
name|QOpenGLVersionProfile
modifier|&
name|versionProfile
parameter_list|)
block|{
if|#
directive|if
operator|!
name|defined
argument_list|(
name|QT_OPENGL_ES_2
argument_list|)
specifier|const
name|int
name|major
init|=
name|versionProfile
operator|.
name|version
argument_list|()
operator|.
name|first
decl_stmt|;
specifier|const
name|int
name|minor
init|=
name|versionProfile
operator|.
name|version
argument_list|()
operator|.
name|second
decl_stmt|;
if|if
condition|(
name|versionProfile
operator|.
name|hasProfiles
argument_list|()
condition|)
block|{
switch|switch
condition|(
name|versionProfile
operator|.
name|profile
argument_list|()
condition|)
block|{
case|case
name|QSurfaceFormat
operator|::
name|CoreProfile
case|:
if|if
condition|(
name|major
operator|==
literal|4
operator|&&
name|minor
operator|==
literal|5
condition|)
return|return
operator|new
name|QOpenGLFunctions_4_5_Core
return|;
elseif|else
if|if
condition|(
name|major
operator|==
literal|4
operator|&&
name|minor
operator|==
literal|4
condition|)
return|return
operator|new
name|QOpenGLFunctions_4_4_Core
return|;
elseif|else
if|if
condition|(
name|major
operator|==
literal|4
operator|&&
name|minor
operator|==
literal|3
condition|)
return|return
operator|new
name|QOpenGLFunctions_4_3_Core
return|;
elseif|else
if|if
condition|(
name|major
operator|==
literal|4
operator|&&
name|minor
operator|==
literal|2
condition|)
return|return
operator|new
name|QOpenGLFunctions_4_2_Core
return|;
elseif|else
if|if
condition|(
name|major
operator|==
literal|4
operator|&&
name|minor
operator|==
literal|1
condition|)
return|return
operator|new
name|QOpenGLFunctions_4_1_Core
return|;
elseif|else
if|if
condition|(
name|major
operator|==
literal|4
operator|&&
name|minor
operator|==
literal|0
condition|)
return|return
operator|new
name|QOpenGLFunctions_4_0_Core
return|;
elseif|else
if|if
condition|(
name|major
operator|==
literal|3
operator|&&
name|minor
operator|==
literal|3
condition|)
return|return
operator|new
name|QOpenGLFunctions_3_3_Core
return|;
elseif|else
if|if
condition|(
name|major
operator|==
literal|3
operator|&&
name|minor
operator|==
literal|2
condition|)
return|return
operator|new
name|QOpenGLFunctions_3_2_Core
return|;
break|break;
case|case
name|QSurfaceFormat
operator|::
name|CompatibilityProfile
case|:
if|if
condition|(
name|major
operator|==
literal|4
operator|&&
name|minor
operator|==
literal|5
condition|)
return|return
operator|new
name|QOpenGLFunctions_4_5_Compatibility
return|;
elseif|else
if|if
condition|(
name|major
operator|==
literal|4
operator|&&
name|minor
operator|==
literal|4
condition|)
return|return
operator|new
name|QOpenGLFunctions_4_4_Compatibility
return|;
elseif|else
if|if
condition|(
name|major
operator|==
literal|4
operator|&&
name|minor
operator|==
literal|3
condition|)
return|return
operator|new
name|QOpenGLFunctions_4_3_Compatibility
return|;
elseif|else
if|if
condition|(
name|major
operator|==
literal|4
operator|&&
name|minor
operator|==
literal|2
condition|)
return|return
operator|new
name|QOpenGLFunctions_4_2_Compatibility
return|;
elseif|else
if|if
condition|(
name|major
operator|==
literal|4
operator|&&
name|minor
operator|==
literal|1
condition|)
return|return
operator|new
name|QOpenGLFunctions_4_1_Compatibility
return|;
elseif|else
if|if
condition|(
name|major
operator|==
literal|4
operator|&&
name|minor
operator|==
literal|0
condition|)
return|return
operator|new
name|QOpenGLFunctions_4_0_Compatibility
return|;
elseif|else
if|if
condition|(
name|major
operator|==
literal|3
operator|&&
name|minor
operator|==
literal|3
condition|)
return|return
operator|new
name|QOpenGLFunctions_3_3_Compatibility
return|;
elseif|else
if|if
condition|(
name|major
operator|==
literal|3
operator|&&
name|minor
operator|==
literal|2
condition|)
return|return
operator|new
name|QOpenGLFunctions_3_2_Compatibility
return|;
break|break;
case|case
name|QSurfaceFormat
operator|::
name|NoProfile
case|:
default|default:
break|break;
block|}
empty_stmt|;
block|}
else|else
block|{
if|if
condition|(
name|major
operator|==
literal|3
operator|&&
name|minor
operator|==
literal|1
condition|)
return|return
operator|new
name|QOpenGLFunctions_3_1
return|;
elseif|else
if|if
condition|(
name|major
operator|==
literal|3
operator|&&
name|minor
operator|==
literal|0
condition|)
return|return
operator|new
name|QOpenGLFunctions_3_0
return|;
elseif|else
if|if
condition|(
name|major
operator|==
literal|2
operator|&&
name|minor
operator|==
literal|1
condition|)
return|return
operator|new
name|QOpenGLFunctions_2_1
return|;
elseif|else
if|if
condition|(
name|major
operator|==
literal|2
operator|&&
name|minor
operator|==
literal|0
condition|)
return|return
operator|new
name|QOpenGLFunctions_2_0
return|;
elseif|else
if|if
condition|(
name|major
operator|==
literal|1
operator|&&
name|minor
operator|==
literal|5
condition|)
return|return
operator|new
name|QOpenGLFunctions_1_5
return|;
elseif|else
if|if
condition|(
name|major
operator|==
literal|1
operator|&&
name|minor
operator|==
literal|4
condition|)
return|return
operator|new
name|QOpenGLFunctions_1_4
return|;
elseif|else
if|if
condition|(
name|major
operator|==
literal|1
operator|&&
name|minor
operator|==
literal|3
condition|)
return|return
operator|new
name|QOpenGLFunctions_1_3
return|;
elseif|else
if|if
condition|(
name|major
operator|==
literal|1
operator|&&
name|minor
operator|==
literal|2
condition|)
return|return
operator|new
name|QOpenGLFunctions_1_2
return|;
elseif|else
if|if
condition|(
name|major
operator|==
literal|1
operator|&&
name|minor
operator|==
literal|1
condition|)
return|return
operator|new
name|QOpenGLFunctions_1_1
return|;
elseif|else
if|if
condition|(
name|major
operator|==
literal|1
operator|&&
name|minor
operator|==
literal|0
condition|)
return|return
operator|new
name|QOpenGLFunctions_1_0
return|;
block|}
return|return
literal|0
return|;
else|#
directive|else
name|Q_UNUSED
argument_list|(
name|versionProfile
argument_list|)
expr_stmt|;
return|return
operator|new
name|QOpenGLFunctions_ES2
return|;
endif|#
directive|endif
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
