begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** No Commercial Usage ** This file contains pre-release code and may not be distributed. ** You may use this file in accordance with the terms and conditions ** contained in the Technology Preview License Agreement accompanying ** this package. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights.  These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** If you have questions regarding the use of this file, please contact ** Nokia at qt-info@nokia.com. ** ** ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"shower.h"
end_include
begin_include
include|#
directive|include
file|"qengines.h"
end_include
begin_include
include|#
directive|include
file|<QApplication>
end_include
begin_include
include|#
directive|include
file|<QSvgRenderer>
end_include
begin_include
include|#
directive|include
file|<QPainter>
end_include
begin_include
include|#
directive|include
file|<QPaintEvent>
end_include
begin_include
include|#
directive|include
file|<QFile>
end_include
begin_include
include|#
directive|include
file|<QTextStream>
end_include
begin_include
include|#
directive|include
file|<QTemporaryFile>
end_include
begin_include
include|#
directive|include
file|<QDir>
end_include
begin_include
include|#
directive|include
file|<QtDebug>
end_include
begin_function
DECL|function|loadFile
specifier|static
name|QString
name|loadFile
parameter_list|(
specifier|const
name|QString
modifier|&
name|name
parameter_list|)
block|{
name|QFile
name|file
argument_list|(
name|name
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|file
operator|.
name|open
argument_list|(
name|QFile
operator|::
name|ReadOnly
argument_list|)
condition|)
block|{
name|qDebug
argument_list|(
literal|"Can't open file '%s'"
argument_list|,
name|qPrintable
argument_list|(
name|name
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|QString
argument_list|()
return|;
block|}
name|QTextStream
name|str
argument_list|(
operator|&
name|file
argument_list|)
decl_stmt|;
return|return
name|str
operator|.
name|readAll
argument_list|()
return|;
block|}
end_function
begin_constructor
DECL|function|Shower
name|Shower
operator|::
name|Shower
parameter_list|(
specifier|const
name|QString
modifier|&
name|file
parameter_list|,
specifier|const
name|QString
modifier|&
name|engineName
parameter_list|)
member_init_list|:
name|QWidget
argument_list|(
literal|0
argument_list|)
block|{
foreach|foreach
control|(
name|QEngine
modifier|*
name|qengine
decl|,
name|QtEngines
operator|::
name|self
argument_list|()
operator|->
name|engines
argument_list|()
control|)
block|{
if|if
condition|(
name|qengine
operator|->
name|name
argument_list|()
operator|==
name|engineName
condition|)
block|{
name|engine
operator|=
name|qengine
expr_stmt|;
break|break;
block|}
block|}
name|QFileInfo
name|fi
argument_list|(
name|file
argument_list|)
decl_stmt|;
name|baseDataDir
operator|=
name|fi
operator|.
name|absolutePath
argument_list|()
expr_stmt|;
if|if
condition|(
name|file
operator|.
name|endsWith
argument_list|(
literal|"svg"
argument_list|)
condition|)
block|{
name|renderer
operator|=
operator|new
name|QSvgRenderer
argument_list|(
name|this
argument_list|)
expr_stmt|;
name|renderer
operator|->
name|load
argument_list|(
name|file
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|qps
operator|=
name|QFileInfo
argument_list|(
name|file
argument_list|)
expr_stmt|;
name|QString
name|script
init|=
name|loadFile
argument_list|(
name|qps
operator|.
name|absoluteFilePath
argument_list|()
argument_list|)
decl_stmt|;
name|qpsScript
operator|=
name|script
operator|.
name|split
argument_list|(
literal|"\n"
argument_list|,
name|QString
operator|::
name|SkipEmptyParts
argument_list|)
expr_stmt|;
name|renderer
operator|=
literal|0
expr_stmt|;
if|if
condition|(
name|qpsScript
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|printf
argument_list|(
literal|"failed to read file: '%s'\n"
argument_list|,
name|qPrintable
argument_list|(
name|qps
operator|.
name|fileName
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
return|return;
block|}
block|}
block|}
end_constructor
begin_function
DECL|function|sizeHint
name|QSize
name|Shower
operator|::
name|sizeHint
parameter_list|()
specifier|const
block|{
return|return
name|QSize
argument_list|(
literal|600
argument_list|,
literal|600
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|paintEvent
name|void
name|Shower
operator|::
name|paintEvent
parameter_list|(
name|QPaintEvent
modifier|*
parameter_list|)
block|{
if|if
condition|(
name|buffer
operator|.
name|size
argument_list|()
operator|!=
name|size
argument_list|()
condition|)
block|{
name|buffer
operator|=
name|QImage
argument_list|(
name|size
argument_list|()
argument_list|,
name|QImage
operator|::
name|Format_ARGB32_Premultiplied
argument_list|)
expr_stmt|;
name|QPainter
name|p
argument_list|(
operator|&
name|buffer
argument_list|)
decl_stmt|;
name|p
operator|.
name|setViewport
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
name|width
argument_list|()
argument_list|,
name|height
argument_list|()
argument_list|)
expr_stmt|;
name|p
operator|.
name|eraseRect
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
name|width
argument_list|()
argument_list|,
name|height
argument_list|()
argument_list|)
expr_stmt|;
name|engine
operator|->
name|prepare
argument_list|(
name|size
argument_list|()
argument_list|)
expr_stmt|;
if|if
condition|(
name|renderer
condition|)
block|{
name|engine
operator|->
name|render
argument_list|(
name|renderer
argument_list|,
name|QString
argument_list|(
literal|"sample"
argument_list|)
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|engine
operator|->
name|render
argument_list|(
name|qpsScript
argument_list|,
name|qps
operator|.
name|absoluteFilePath
argument_list|()
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
operator|!
name|engine
operator|->
name|drawOnPainter
argument_list|(
operator|&
name|p
argument_list|)
condition|)
block|{
name|QString
name|tempFileName
init|=
name|QString
argument_list|(
literal|"%1sample.png"
argument_list|)
operator|.
name|arg
argument_list|(
name|QDir
operator|::
name|tempPath
argument_list|()
argument_list|)
decl_stmt|;
name|engine
operator|->
name|save
argument_list|(
name|tempFileName
argument_list|)
expr_stmt|;
name|QImage
name|img
argument_list|(
name|tempFileName
argument_list|)
decl_stmt|;
name|engine
operator|->
name|cleanup
argument_list|()
expr_stmt|;
name|QFile
operator|::
name|remove
argument_list|(
name|tempFileName
argument_list|)
expr_stmt|;
name|p
operator|.
name|drawImage
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
name|img
argument_list|)
expr_stmt|;
block|}
block|}
name|QPainter
name|pt
argument_list|(
name|this
argument_list|)
decl_stmt|;
name|pt
operator|.
name|drawImage
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
name|buffer
argument_list|)
expr_stmt|;
block|}
end_function
end_unit
