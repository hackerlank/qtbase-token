begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:GPL-EXCEPT$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3 as published by the Free Software ** Foundation with exceptions as appearing in the file LICENSE.GPL3-EXCEPT ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<stdlib.h>
end_include
begin_include
include|#
directive|include
file|<stdio.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/QCoreApplication>
end_include
begin_include
include|#
directive|include
file|<QtCore/QTextCodec>
end_include
begin_function
DECL|function|main
name|int
name|main
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
modifier|*
name|argv
parameter_list|)
block|{
name|qputenv
argument_list|(
literal|"LC_ALL"
argument_list|,
literal|"C"
argument_list|)
expr_stmt|;
name|QCoreApplication
name|app
argument_list|(
name|argc
argument_list|,
name|argv
argument_list|)
decl_stmt|;
name|QString
name|string
argument_list|(
name|QChar
argument_list|(
literal|0x410
argument_list|)
argument_list|)
decl_stmt|;
name|QTextCodec
modifier|*
name|locale
init|=
name|QTextCodec
operator|::
name|codecForLocale
argument_list|()
decl_stmt|;
name|QTextEncoder
modifier|*
name|encoder
init|=
name|locale
operator|->
name|makeEncoder
argument_list|()
decl_stmt|;
name|QByteArray
name|output
init|=
name|encoder
operator|->
name|fromUnicode
argument_list|(
name|string
argument_list|)
decl_stmt|;
name|printf
argument_list|(
literal|"%s\n"
argument_list|,
name|output
operator|.
name|data
argument_list|()
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function
end_unit
