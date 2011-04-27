begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtTest module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** No Commercial Usage ** This file contains pre-release code and may not be distributed. ** You may use this file in accordance with the terms and conditions ** contained in the Technology Preview License Agreement accompanying ** this package. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights.  These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** If you have questions regarding the use of this file, please contact ** Nokia at qt-info@nokia.com. ** ** ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qtestbasicstreamer.h"
end_include
begin_include
include|#
directive|include
file|"qtestlogger_p.h"
end_include
begin_include
include|#
directive|include
file|"qtestelement.h"
end_include
begin_include
include|#
directive|include
file|"qtestelementattribute.h"
end_include
begin_include
include|#
directive|include
file|"QtTest/private/qtestlog_p.h"
end_include
begin_include
include|#
directive|include
file|"qtestassert.h"
end_include
begin_include
include|#
directive|include
file|<stdio.h>
end_include
begin_include
include|#
directive|include
file|<stdlib.h>
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|Q_OS_WIN
end_ifndef
begin_include
include|#
directive|include
file|<unistd.h>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_namespace
DECL|namespace|QTest
namespace|namespace
name|QTest
block|{
DECL|member|stream
specifier|static
name|FILE
modifier|*
name|stream
init|=
literal|0
decl_stmt|;
block|}
end_namespace
begin_constructor
DECL|function|QTestBasicStreamer
name|QTestBasicStreamer
operator|::
name|QTestBasicStreamer
parameter_list|()
member_init_list|:
name|testLogger
argument_list|(
literal|0
argument_list|)
block|{ }
end_constructor
begin_destructor
DECL|function|~QTestBasicStreamer
name|QTestBasicStreamer
operator|::
name|~
name|QTestBasicStreamer
parameter_list|()
block|{}
end_destructor
begin_function
DECL|function|formatStart
name|void
name|QTestBasicStreamer
operator|::
name|formatStart
parameter_list|(
specifier|const
name|QTestElement
modifier|*
name|element
parameter_list|,
name|QTestCharBuffer
modifier|*
name|formatted
parameter_list|)
specifier|const
block|{
if|if
condition|(
operator|!
name|element
operator|||
operator|!
name|formatted
condition|)
return|return;
name|formatted
operator|->
name|data
argument_list|()
index|[
literal|0
index|]
operator|=
literal|'\0'
expr_stmt|;
block|}
end_function
begin_function
DECL|function|formatEnd
name|void
name|QTestBasicStreamer
operator|::
name|formatEnd
parameter_list|(
specifier|const
name|QTestElement
modifier|*
name|element
parameter_list|,
name|QTestCharBuffer
modifier|*
name|formatted
parameter_list|)
specifier|const
block|{
if|if
condition|(
operator|!
name|element
operator|||
operator|!
name|formatted
condition|)
return|return;
name|formatted
operator|->
name|data
argument_list|()
index|[
literal|0
index|]
operator|=
literal|'\0'
expr_stmt|;
block|}
end_function
begin_function
DECL|function|formatBeforeAttributes
name|void
name|QTestBasicStreamer
operator|::
name|formatBeforeAttributes
parameter_list|(
specifier|const
name|QTestElement
modifier|*
name|element
parameter_list|,
name|QTestCharBuffer
modifier|*
name|formatted
parameter_list|)
specifier|const
block|{
if|if
condition|(
operator|!
name|element
operator|||
operator|!
name|formatted
condition|)
return|return;
name|formatted
operator|->
name|data
argument_list|()
index|[
literal|0
index|]
operator|=
literal|'\0'
expr_stmt|;
block|}
end_function
begin_function
DECL|function|formatAfterAttributes
name|void
name|QTestBasicStreamer
operator|::
name|formatAfterAttributes
parameter_list|(
specifier|const
name|QTestElement
modifier|*
name|element
parameter_list|,
name|QTestCharBuffer
modifier|*
name|formatted
parameter_list|)
specifier|const
block|{
if|if
condition|(
operator|!
name|element
operator|||
operator|!
name|formatted
condition|)
return|return;
name|formatted
operator|->
name|data
argument_list|()
index|[
literal|0
index|]
operator|=
literal|'\0'
expr_stmt|;
block|}
end_function
begin_function
DECL|function|formatAttributes
name|void
name|QTestBasicStreamer
operator|::
name|formatAttributes
parameter_list|(
specifier|const
name|QTestElement
modifier|*
parameter_list|,
specifier|const
name|QTestElementAttribute
modifier|*
name|attribute
parameter_list|,
name|QTestCharBuffer
modifier|*
name|formatted
parameter_list|)
specifier|const
block|{
if|if
condition|(
operator|!
name|attribute
operator|||
operator|!
name|formatted
condition|)
return|return;
name|formatted
operator|->
name|data
argument_list|()
index|[
literal|0
index|]
operator|=
literal|'\0'
expr_stmt|;
block|}
end_function
begin_function
DECL|function|output
name|void
name|QTestBasicStreamer
operator|::
name|output
parameter_list|(
name|QTestElement
modifier|*
name|element
parameter_list|)
specifier|const
block|{
if|if
condition|(
operator|!
name|element
condition|)
return|return;
name|outputElements
argument_list|(
name|element
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|outputElements
name|void
name|QTestBasicStreamer
operator|::
name|outputElements
parameter_list|(
name|QTestElement
modifier|*
name|element
parameter_list|,
name|bool
parameter_list|)
specifier|const
block|{
name|QTestCharBuffer
name|buf
decl_stmt|;
name|bool
name|hasChildren
decl_stmt|;
comment|/*         Elements are in reverse order of occurrence, so start from the end and work         our way backwards.     */
while|while
condition|(
name|element
operator|&&
name|element
operator|->
name|nextElement
argument_list|()
condition|)
block|{
name|element
operator|=
name|element
operator|->
name|nextElement
argument_list|()
expr_stmt|;
block|}
while|while
condition|(
name|element
condition|)
block|{
name|hasChildren
operator|=
name|element
operator|->
name|childElements
argument_list|()
expr_stmt|;
name|formatStart
argument_list|(
name|element
argument_list|,
operator|&
name|buf
argument_list|)
expr_stmt|;
name|outputString
argument_list|(
name|buf
operator|.
name|data
argument_list|()
argument_list|)
expr_stmt|;
name|formatBeforeAttributes
argument_list|(
name|element
argument_list|,
operator|&
name|buf
argument_list|)
expr_stmt|;
name|outputString
argument_list|(
name|buf
operator|.
name|data
argument_list|()
argument_list|)
expr_stmt|;
name|outputElementAttributes
argument_list|(
name|element
argument_list|,
name|element
operator|->
name|attributes
argument_list|()
argument_list|)
expr_stmt|;
name|formatAfterAttributes
argument_list|(
name|element
argument_list|,
operator|&
name|buf
argument_list|)
expr_stmt|;
name|outputString
argument_list|(
name|buf
operator|.
name|data
argument_list|()
argument_list|)
expr_stmt|;
if|if
condition|(
name|hasChildren
condition|)
name|outputElements
argument_list|(
name|element
operator|->
name|childElements
argument_list|()
argument_list|,
literal|true
argument_list|)
expr_stmt|;
name|formatEnd
argument_list|(
name|element
argument_list|,
operator|&
name|buf
argument_list|)
expr_stmt|;
name|outputString
argument_list|(
name|buf
operator|.
name|data
argument_list|()
argument_list|)
expr_stmt|;
name|element
operator|=
name|element
operator|->
name|previousElement
argument_list|()
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|outputElementAttributes
name|void
name|QTestBasicStreamer
operator|::
name|outputElementAttributes
parameter_list|(
specifier|const
name|QTestElement
modifier|*
name|element
parameter_list|,
name|QTestElementAttribute
modifier|*
name|attribute
parameter_list|)
specifier|const
block|{
name|QTestCharBuffer
name|buf
decl_stmt|;
while|while
condition|(
name|attribute
condition|)
block|{
name|formatAttributes
argument_list|(
name|element
argument_list|,
name|attribute
argument_list|,
operator|&
name|buf
argument_list|)
expr_stmt|;
name|outputString
argument_list|(
name|buf
operator|.
name|data
argument_list|()
argument_list|)
expr_stmt|;
name|attribute
operator|=
name|attribute
operator|->
name|nextElement
argument_list|()
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|outputString
name|void
name|QTestBasicStreamer
operator|::
name|outputString
parameter_list|(
specifier|const
name|char
modifier|*
name|msg
parameter_list|)
specifier|const
block|{
name|QTEST_ASSERT
argument_list|(
name|QTest
operator|::
name|stream
argument_list|)
expr_stmt|;
operator|::
name|fputs
argument_list|(
name|msg
argument_list|,
name|QTest
operator|::
name|stream
argument_list|)
expr_stmt|;
operator|::
name|fflush
argument_list|(
name|QTest
operator|::
name|stream
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|startStreaming
name|void
name|QTestBasicStreamer
operator|::
name|startStreaming
parameter_list|()
block|{
name|QTEST_ASSERT
argument_list|(
operator|!
name|QTest
operator|::
name|stream
argument_list|)
expr_stmt|;
specifier|const
name|char
modifier|*
name|out
init|=
name|QTestLog
operator|::
name|outputFileName
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
name|out
condition|)
block|{
name|QTest
operator|::
name|stream
operator|=
name|stdout
expr_stmt|;
return|return;
block|}
if|#
directive|if
name|defined
argument_list|(
name|_MSC_VER
argument_list|)
operator|&&
name|_MSC_VER
operator|>=
literal|1400
operator|&&
operator|!
name|defined
argument_list|(
name|Q_OS_WINCE
argument_list|)
if|if
condition|(
operator|::
name|fopen_s
argument_list|(
operator|&
name|QTest
operator|::
name|stream
argument_list|,
name|out
argument_list|,
literal|"wt"
argument_list|)
condition|)
block|{
else|#
directive|else
name|QTest
operator|::
name|stream
operator|=
operator|::
name|fopen
argument_list|(
name|out
argument_list|,
literal|"wt"
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|QTest
operator|::
name|stream
condition|)
block|{
endif|#
directive|endif
name|printf
argument_list|(
literal|"Unable to open file for logging: %s"
argument_list|,
name|out
argument_list|)
expr_stmt|;
operator|::
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
block|}
DECL|function|isTtyOutput
name|bool
name|QTestBasicStreamer
operator|::
name|isTtyOutput
parameter_list|()
block|{
name|QTEST_ASSERT
argument_list|(
name|QTest
operator|::
name|stream
argument_list|)
expr_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_WIN
argument_list|)
operator|||
name|defined
argument_list|(
name|Q_OS_INTEGRITY
argument_list|)
return|return
literal|true
return|;
else|#
directive|else
specifier|static
name|bool
name|ttyoutput
init|=
name|isatty
argument_list|(
name|fileno
argument_list|(
name|QTest
operator|::
name|stream
argument_list|)
argument_list|)
decl_stmt|;
return|return
name|ttyoutput
return|;
endif|#
directive|endif
block|}
DECL|function|stopStreaming
name|void
name|QTestBasicStreamer
operator|::
name|stopStreaming
parameter_list|()
block|{
name|QTEST_ASSERT
argument_list|(
name|QTest
operator|::
name|stream
argument_list|)
expr_stmt|;
if|if
condition|(
name|QTest
operator|::
name|stream
operator|!=
name|stdout
condition|)
name|fclose
argument_list|(
name|QTest
operator|::
name|stream
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|stream
operator|=
literal|0
expr_stmt|;
block|}
DECL|function|setLogger
name|void
name|QTestBasicStreamer
operator|::
name|setLogger
parameter_list|(
specifier|const
name|QTestLogger
modifier|*
name|tstLogger
parameter_list|)
block|{
name|testLogger
operator|=
name|tstLogger
expr_stmt|;
block|}
DECL|function|logger
specifier|const
name|QTestLogger
modifier|*
name|QTestBasicStreamer
operator|::
name|logger
parameter_list|()
specifier|const
block|{
return|return
name|testLogger
return|;
block|}
name|QT_END_NAMESPACE
end_function
end_unit
