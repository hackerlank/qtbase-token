begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of Digia Plc and its Subsidiary(-ies) nor the names **     of its contributors may be used to endorse or promote products derived **     from this software without specific prior written permission. ** ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QImage>
end_include
begin_include
include|#
directive|include
file|<QList>
end_include
begin_include
include|#
directive|include
file|<QThread>
end_include
begin_include
include|#
directive|include
file|<QDebug>
end_include
begin_include
include|#
directive|include
file|<QGuiApplication>
end_include
begin_include
include|#
directive|include
file|<qtconcurrentmap.h>
end_include
begin_function
DECL|function|scale
name|QImage
name|scale
parameter_list|(
specifier|const
name|QImage
modifier|&
name|image
parameter_list|)
block|{
name|qDebug
argument_list|()
operator|<<
literal|"Scaling image in thread"
operator|<<
name|QThread
operator|::
name|currentThread
argument_list|()
expr_stmt|;
return|return
name|image
operator|.
name|scaled
argument_list|(
name|QSize
argument_list|(
literal|100
argument_list|,
literal|100
argument_list|)
argument_list|,
name|Qt
operator|::
name|IgnoreAspectRatio
argument_list|,
name|Qt
operator|::
name|SmoothTransformation
argument_list|)
return|;
block|}
end_function
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
name|QGuiApplication
name|app
argument_list|(
name|argc
argument_list|,
name|argv
argument_list|)
decl_stmt|;
specifier|const
name|int
name|imageCount
init|=
literal|20
decl_stmt|;
comment|// Create a list containing imageCount images.
name|QList
argument_list|<
name|QImage
argument_list|>
name|images
decl_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|imageCount
condition|;
operator|++
name|i
control|)
name|images
operator|.
name|append
argument_list|(
name|QImage
argument_list|(
literal|1600
argument_list|,
literal|1200
argument_list|,
name|QImage
operator|::
name|Format_ARGB32_Premultiplied
argument_list|)
argument_list|)
expr_stmt|;
comment|// Use QtConcurrentBlocking::mapped to apply the scale function to all the
comment|// images in the list.
name|QList
argument_list|<
name|QImage
argument_list|>
name|thumbnails
init|=
name|QtConcurrent
operator|::
name|blockingMapped
argument_list|<
name|QList
argument_list|<
name|QImage
argument_list|>
argument_list|>
argument_list|(
name|images
argument_list|,
name|scale
argument_list|)
decl_stmt|;
return|return
literal|0
return|;
block|}
end_function
end_unit
