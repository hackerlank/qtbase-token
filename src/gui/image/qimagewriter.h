begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QIMAGEWRITER_H
end_ifndef
begin_define
DECL|macro|QIMAGEWRITER_H
define|#
directive|define
name|QIMAGEWRITER_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qbytearray.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qlist.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/qimageiohandler.h>
end_include
begin_decl_stmt
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
DECL|variable|QIODevice
name|class
name|QIODevice
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QImage
name|class
name|QImage
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QImageWriterPrivate
name|class
name|QImageWriterPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_GUI_EXPORT
name|QImageWriter
block|{
name|public
label|:
enum|enum
name|ImageWriterError
block|{
name|UnknownError
block|,
name|DeviceError
block|,
name|UnsupportedFormatError
block|}
enum|;
name|QImageWriter
argument_list|()
expr_stmt|;
name|explicit
name|QImageWriter
parameter_list|(
name|QIODevice
modifier|*
name|device
parameter_list|,
specifier|const
name|QByteArray
modifier|&
name|format
parameter_list|)
function_decl|;
name|explicit
name|QImageWriter
parameter_list|(
specifier|const
name|QString
modifier|&
name|fileName
parameter_list|,
specifier|const
name|QByteArray
modifier|&
name|format
init|=
name|QByteArray
argument_list|()
parameter_list|)
function_decl|;
operator|~
name|QImageWriter
argument_list|()
expr_stmt|;
name|void
name|setFormat
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|format
parameter_list|)
function_decl|;
name|QByteArray
name|format
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setDevice
parameter_list|(
name|QIODevice
modifier|*
name|device
parameter_list|)
function_decl|;
name|QIODevice
operator|*
name|device
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setFileName
parameter_list|(
specifier|const
name|QString
modifier|&
name|fileName
parameter_list|)
function_decl|;
name|QString
name|fileName
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setQuality
parameter_list|(
name|int
name|quality
parameter_list|)
function_decl|;
name|int
name|quality
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setCompression
parameter_list|(
name|int
name|compression
parameter_list|)
function_decl|;
name|int
name|compression
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setGamma
parameter_list|(
name|float
name|gamma
parameter_list|)
function_decl|;
name|float
name|gamma
argument_list|()
specifier|const
expr_stmt|;
comment|// Obsolete as of 4.1
name|void
name|setDescription
parameter_list|(
specifier|const
name|QString
modifier|&
name|description
parameter_list|)
function_decl|;
name|QString
name|description
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setText
parameter_list|(
specifier|const
name|QString
modifier|&
name|key
parameter_list|,
specifier|const
name|QString
modifier|&
name|text
parameter_list|)
function_decl|;
name|bool
name|canWrite
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|write
parameter_list|(
specifier|const
name|QImage
modifier|&
name|image
parameter_list|)
function_decl|;
name|ImageWriterError
name|error
argument_list|()
specifier|const
expr_stmt|;
name|QString
name|errorString
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|supportsOption
argument_list|(
name|QImageIOHandler
operator|::
name|ImageOption
name|option
argument_list|)
decl|const
decl_stmt|;
specifier|static
name|QList
operator|<
name|QByteArray
operator|>
name|supportedImageFormats
argument_list|()
expr_stmt|;
name|private
label|:
name|Q_DISABLE_COPY
argument_list|(
argument|QImageWriter
argument_list|)
name|QImageWriterPrivate
modifier|*
name|d
decl_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_expr_stmt
name|QT_END_NAMESPACE
name|QT_END_HEADER
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QIMAGEWRITER_H
end_comment
end_unit
