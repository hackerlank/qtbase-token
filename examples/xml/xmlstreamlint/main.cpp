begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of Digia Plc and its Subsidiary(-ies) nor the names **     of its contributors may be used to endorse or promote products derived **     from this software without specific prior written permission. ** ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QCoreApplication>
end_include
begin_include
include|#
directive|include
file|<QFile>
end_include
begin_include
include|#
directive|include
file|<QStringList>
end_include
begin_include
include|#
directive|include
file|<QTextStream>
end_include
begin_include
include|#
directive|include
file|<QXmlStreamReader>
end_include
begin_comment
comment|/*  This class exists for the sole purpose of creating a translation context. */
end_comment
begin_class
DECL|class|XmlStreamLint
class|class
name|XmlStreamLint
block|{
public|public:
name|Q_DECLARE_TR_FUNCTIONS
argument_list|(
argument|XmlStreamLint
argument_list|)
block|}
class|;
end_class
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
name|argv
index|[]
parameter_list|)
block|{
enum|enum
name|ExitCode
block|{
name|Success
block|,
name|ParseFailure
block|,
name|ArgumentError
block|,
name|WriteError
block|,
name|FileFailure
block|}
enum|;
name|QCoreApplication
name|app
argument_list|(
name|argc
argument_list|,
name|argv
argument_list|)
decl_stmt|;
name|QTextStream
name|errorStream
argument_list|(
name|stderr
argument_list|)
decl_stmt|;
if|if
condition|(
name|argc
operator|!=
literal|2
condition|)
block|{
name|errorStream
operator|<<
name|XmlStreamLint
operator|::
name|tr
argument_list|(
literal|"Usage: xmlstreamlint<path to XML file>\n"
argument_list|)
expr_stmt|;
return|return
name|ArgumentError
return|;
block|}
name|QString
name|inputFilePath
argument_list|(
name|QCoreApplication
operator|::
name|arguments
argument_list|()
operator|.
name|at
argument_list|(
literal|1
argument_list|)
argument_list|)
decl_stmt|;
name|QFile
name|inputFile
argument_list|(
name|inputFilePath
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|QFile
operator|::
name|exists
argument_list|(
name|inputFilePath
argument_list|)
condition|)
block|{
name|errorStream
operator|<<
name|XmlStreamLint
operator|::
name|tr
argument_list|(
literal|"File %1 does not exist.\n"
argument_list|)
operator|.
name|arg
argument_list|(
name|inputFilePath
argument_list|)
expr_stmt|;
return|return
name|FileFailure
return|;
block|}
elseif|else
if|if
condition|(
operator|!
name|inputFile
operator|.
name|open
argument_list|(
name|QIODevice
operator|::
name|ReadOnly
argument_list|)
condition|)
block|{
name|errorStream
operator|<<
name|XmlStreamLint
operator|::
name|tr
argument_list|(
literal|"Failed to open file %1.\n"
argument_list|)
operator|.
name|arg
argument_list|(
name|inputFilePath
argument_list|)
expr_stmt|;
return|return
name|FileFailure
return|;
block|}
name|QFile
name|outputFile
decl_stmt|;
if|if
condition|(
operator|!
name|outputFile
operator|.
name|open
argument_list|(
name|stdout
argument_list|,
name|QIODevice
operator|::
name|WriteOnly
argument_list|)
condition|)
block|{
name|errorStream
operator|<<
name|XmlStreamLint
operator|::
name|tr
argument_list|(
literal|"Failed to open stdout."
argument_list|)
expr_stmt|;
return|return
name|WriteError
return|;
block|}
comment|//! [0]
name|QXmlStreamReader
name|reader
argument_list|(
operator|&
name|inputFile
argument_list|)
decl_stmt|;
name|QXmlStreamWriter
name|writer
argument_list|(
operator|&
name|outputFile
argument_list|)
decl_stmt|;
comment|//! [0]
comment|//! [1]
while|while
condition|(
operator|!
name|reader
operator|.
name|atEnd
argument_list|()
condition|)
block|{
name|reader
operator|.
name|readNext
argument_list|()
expr_stmt|;
if|if
condition|(
name|reader
operator|.
name|error
argument_list|()
condition|)
block|{
name|errorStream
operator|<<
name|XmlStreamLint
operator|::
name|tr
argument_list|(
literal|"Error: %1 in file %2 at line %3, column %4.\n"
argument_list|)
operator|.
name|arg
argument_list|(
name|reader
operator|.
name|errorString
argument_list|()
argument_list|,
name|inputFilePath
argument_list|,
name|QString
operator|::
name|number
argument_list|(
name|reader
operator|.
name|lineNumber
argument_list|()
argument_list|)
argument_list|,
name|QString
operator|::
name|number
argument_list|(
name|reader
operator|.
name|columnNumber
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|ParseFailure
return|;
comment|//! [1]
comment|//! [2]
block|}
else|else
name|writer
operator|.
name|writeCurrentToken
argument_list|(
name|reader
argument_list|)
expr_stmt|;
block|}
comment|//! [2]
return|return
name|Success
return|;
block|}
end_function
end_unit
