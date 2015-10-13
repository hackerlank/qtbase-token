begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QStringList>
end_include
begin_include
include|#
directive|include
file|<QDebug>
end_include
begin_include
include|#
directive|include
file|"commandline.h"
end_include
begin_function
DECL|function|usage
specifier|static
name|void
name|usage
parameter_list|(
specifier|const
name|char
modifier|*
name|appname
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
name|appname
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|" GraphicsViewBenchmark related options:\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|" -h,-help,--help: This help\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|" -resolution    : UI resolution in format WxH where width and height are positive values\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|" -opengl        : Enables OpenGL usage. Building PRECONDITIONS: QT_NO_OPENGL is off.\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|" -manual        : Run test manually \n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"\n The following options are available in manual mode:\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|" -rotation      : UI rotation in degrees\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|" -subtree-cache : Enables usage of subtree caching method\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|" -fps           : Output FPS count to stdout during application execution\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|" -items         : Count of items created to the list\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"\n"
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|argumentOnlyAvailableInManualMode
specifier|static
specifier|inline
name|bool
name|argumentOnlyAvailableInManualMode
parameter_list|(
specifier|const
name|char
modifier|*
name|arg
parameter_list|)
block|{
return|return
operator|(
name|strcmp
argument_list|(
name|arg
argument_list|,
literal|"-rotation"
argument_list|)
operator|==
literal|0
operator|)
operator|||
operator|(
name|strcmp
argument_list|(
name|arg
argument_list|,
literal|"-subtree-cache"
argument_list|)
operator|==
literal|0
operator|)
operator|||
operator|(
name|strcmp
argument_list|(
name|arg
argument_list|,
literal|"-fps"
argument_list|)
operator|==
literal|0
operator|)
operator|||
operator|(
name|strcmp
argument_list|(
name|arg
argument_list|,
literal|"-items"
argument_list|)
operator|==
literal|0
operator|)
return|;
block|}
end_function
begin_function
DECL|function|readSettingsFromCommandLine
name|bool
name|readSettingsFromCommandLine
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
name|argv
index|[]
parameter_list|,
name|Settings
modifier|&
name|config
parameter_list|)
block|{
name|bool
name|builtWithOpenGL
init|=
literal|false
decl_stmt|;
name|Settings
operator|::
name|Options
name|options
decl_stmt|;
ifndef|#
directive|ifndef
name|QT_NO_OPENGL
name|builtWithOpenGL
operator|=
literal|true
expr_stmt|;
endif|#
directive|endif
for|for
control|(
name|int
name|i
init|=
literal|1
init|;
name|i
operator|<
name|argc
condition|;
operator|++
name|i
control|)
block|{
if|if
condition|(
name|strcmp
argument_list|(
name|argv
index|[
name|i
index|]
argument_list|,
literal|"-manual"
argument_list|)
operator|==
literal|0
condition|)
block|{
name|options
operator||=
name|Settings
operator|::
name|ManualTest
expr_stmt|;
name|argv
index|[
name|i
index|]
operator|=
literal|0
expr_stmt|;
break|break;
block|}
block|}
for|for
control|(
name|int
name|i
init|=
literal|1
init|;
name|i
operator|<
name|argc
condition|;
operator|++
name|i
control|)
block|{
if|if
condition|(
operator|!
name|argv
index|[
name|i
index|]
condition|)
continue|continue;
if|if
condition|(
name|strcmp
argument_list|(
name|argv
index|[
name|i
index|]
argument_list|,
literal|"-h"
argument_list|)
operator|==
literal|0
operator|||
name|strcmp
argument_list|(
name|argv
index|[
name|i
index|]
argument_list|,
literal|"-help"
argument_list|)
operator|==
literal|0
operator|||
name|strcmp
argument_list|(
name|argv
index|[
name|i
index|]
argument_list|,
literal|"--help"
argument_list|)
operator|==
literal|0
condition|)
block|{
name|usage
argument_list|(
name|argv
index|[
literal|0
index|]
argument_list|)
expr_stmt|;
return|return
literal|true
return|;
block|}
if|if
condition|(
name|strcmp
argument_list|(
name|argv
index|[
name|i
index|]
argument_list|,
literal|"-opengl"
argument_list|)
operator|==
literal|0
condition|)
block|{
if|if
condition|(
name|builtWithOpenGL
condition|)
block|{
name|options
operator||=
name|Settings
operator|::
name|UseOpenGL
expr_stmt|;
name|argv
index|[
name|i
index|]
operator|=
literal|0
expr_stmt|;
block|}
else|else
block|{
name|printf
argument_list|(
literal|"-opengl parameter can be used only with building PRECONDITIONS: QT_NO_OPENGL is off.\n"
argument_list|)
expr_stmt|;
name|usage
argument_list|(
name|argv
index|[
literal|0
index|]
argument_list|)
expr_stmt|;
return|return
literal|false
return|;
block|}
block|}
elseif|else
if|if
condition|(
name|strcmp
argument_list|(
name|argv
index|[
name|i
index|]
argument_list|,
literal|"-resolution"
argument_list|)
operator|==
literal|0
condition|)
block|{
if|if
condition|(
name|i
operator|+
literal|1
operator|>=
name|argc
condition|)
block|{
name|printf
argument_list|(
literal|"-resolution needs an extra parameter specifying the application UI resolution\n"
argument_list|)
expr_stmt|;
name|usage
argument_list|(
name|argv
index|[
literal|0
index|]
argument_list|)
expr_stmt|;
return|return
literal|false
return|;
block|}
else|else
block|{
name|QStringList
name|res
init|=
name|QString
argument_list|(
name|argv
index|[
name|i
operator|+
literal|1
index|]
argument_list|)
operator|.
name|split
argument_list|(
name|QLatin1Char
argument_list|(
literal|'x'
argument_list|)
argument_list|)
decl_stmt|;
if|if
condition|(
name|res
operator|.
name|count
argument_list|()
operator|!=
literal|2
condition|)
block|{
name|printf
argument_list|(
literal|"-resolution parameter UI resolution should be set in format WxH where width and height are positive values\n"
argument_list|)
expr_stmt|;
name|usage
argument_list|(
name|argv
index|[
literal|0
index|]
argument_list|)
expr_stmt|;
return|return
literal|false
return|;
block|}
name|int
name|width
init|=
name|res
operator|.
name|at
argument_list|(
literal|0
argument_list|)
operator|.
name|toInt
argument_list|()
decl_stmt|;
name|int
name|height
init|=
name|res
operator|.
name|at
argument_list|(
literal|1
argument_list|)
operator|.
name|toInt
argument_list|()
decl_stmt|;
name|config
operator|.
name|setSize
argument_list|(
name|QSize
argument_list|(
name|width
argument_list|,
name|height
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|width
operator|<=
literal|0
operator|||
name|height
operator|<=
literal|0
condition|)
block|{
name|printf
argument_list|(
literal|"-resolution parameter UI resolution should be set in format WxH where width and height are positive values\n"
argument_list|)
expr_stmt|;
name|usage
argument_list|(
name|argv
index|[
literal|0
index|]
argument_list|)
expr_stmt|;
return|return
literal|false
return|;
block|}
name|argv
index|[
name|i
index|]
operator|=
literal|0
expr_stmt|;
name|i
operator|++
expr_stmt|;
name|argv
index|[
name|i
index|]
operator|=
literal|0
expr_stmt|;
block|}
block|}
if|if
condition|(
operator|!
name|argv
index|[
name|i
index|]
condition|)
continue|continue;
if|if
condition|(
operator|!
operator|(
name|options
operator|&
name|Settings
operator|::
name|ManualTest
operator|)
condition|)
block|{
if|if
condition|(
name|argumentOnlyAvailableInManualMode
argument_list|(
name|argv
index|[
name|i
index|]
argument_list|)
condition|)
block|{
name|printf
argument_list|(
literal|"\nWrong option: '%s' is only available in manual mode\n\n"
argument_list|,
name|argv
index|[
name|i
index|]
argument_list|)
expr_stmt|;
name|usage
argument_list|(
name|argv
index|[
literal|0
index|]
argument_list|)
expr_stmt|;
return|return
literal|false
return|;
block|}
continue|continue;
block|}
if|if
condition|(
name|strcmp
argument_list|(
name|argv
index|[
name|i
index|]
argument_list|,
literal|"-rotation"
argument_list|)
operator|==
literal|0
condition|)
block|{
if|if
condition|(
name|i
operator|+
literal|1
operator|>=
name|argc
condition|)
block|{
name|printf
argument_list|(
literal|"-rotation needs an extra parameter specifying the application UI rotation in degrees\n"
argument_list|)
expr_stmt|;
name|usage
argument_list|(
name|argv
index|[
literal|0
index|]
argument_list|)
expr_stmt|;
return|return
literal|false
return|;
block|}
else|else
block|{
name|bool
name|ok
decl_stmt|;
name|int
name|angle
init|=
name|QString
argument_list|(
name|argv
index|[
name|i
operator|+
literal|1
index|]
argument_list|)
operator|.
name|toInt
argument_list|(
operator|&
name|ok
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|ok
condition|)
block|{
name|printf
argument_list|(
literal|"-rotation parameter should specify rotation angle in degrees\n"
argument_list|)
expr_stmt|;
name|usage
argument_list|(
name|argv
index|[
literal|0
index|]
argument_list|)
expr_stmt|;
return|return
literal|false
return|;
block|}
name|config
operator|.
name|setAngle
argument_list|(
name|angle
argument_list|)
expr_stmt|;
name|argv
index|[
name|i
index|]
operator|=
literal|0
expr_stmt|;
name|i
operator|++
expr_stmt|;
name|argv
index|[
name|i
index|]
operator|=
literal|0
expr_stmt|;
block|}
block|}
elseif|else
if|if
condition|(
name|strcmp
argument_list|(
name|argv
index|[
name|i
index|]
argument_list|,
literal|"-subtree-cache"
argument_list|)
operator|==
literal|0
condition|)
block|{
name|options
operator||=
name|Settings
operator|::
name|UseListItemCache
expr_stmt|;
name|argv
index|[
name|i
index|]
operator|=
literal|0
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|strcmp
argument_list|(
name|argv
index|[
name|i
index|]
argument_list|,
literal|"-fps"
argument_list|)
operator|==
literal|0
condition|)
block|{
name|options
operator||=
name|Settings
operator|::
name|OutputFps
expr_stmt|;
name|argv
index|[
name|i
index|]
operator|=
literal|0
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|strcmp
argument_list|(
name|argv
index|[
name|i
index|]
argument_list|,
literal|"-items"
argument_list|)
operator|==
literal|0
condition|)
block|{
if|if
condition|(
name|i
operator|+
literal|1
operator|>=
name|argc
condition|)
block|{
name|printf
argument_list|(
literal|"-items needs an extra parameter specifying amount of list items\n"
argument_list|)
expr_stmt|;
name|usage
argument_list|(
name|argv
index|[
literal|0
index|]
argument_list|)
expr_stmt|;
return|return
literal|false
return|;
block|}
else|else
block|{
name|bool
name|ok
decl_stmt|;
name|int
name|amount
init|=
name|QString
argument_list|(
name|argv
index|[
name|i
operator|+
literal|1
index|]
argument_list|)
operator|.
name|toInt
argument_list|(
operator|&
name|ok
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|ok
condition|)
block|{
name|printf
argument_list|(
literal|"-items needs an extra parameter specifying amount (integer) of list items\n"
argument_list|)
expr_stmt|;
name|usage
argument_list|(
name|argv
index|[
literal|0
index|]
argument_list|)
expr_stmt|;
return|return
literal|false
return|;
block|}
name|config
operator|.
name|setListItemCount
argument_list|(
name|amount
argument_list|)
expr_stmt|;
name|argv
index|[
name|i
index|]
operator|=
literal|0
expr_stmt|;
name|i
operator|++
expr_stmt|;
name|argv
index|[
name|i
index|]
operator|=
literal|0
expr_stmt|;
block|}
block|}
block|}
name|config
operator|.
name|setOptions
argument_list|(
name|options
argument_list|)
expr_stmt|;
return|return
literal|true
return|;
block|}
end_function
end_unit
