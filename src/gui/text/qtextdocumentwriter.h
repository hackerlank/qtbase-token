begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** No Commercial Usage ** This file contains pre-release code and may not be distributed. ** You may use this file in accordance with the terms and conditions ** contained in the Technology Preview License Agreement accompanying ** this package. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights.  These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** If you have questions regarding the use of this file, please contact ** Nokia at qt-info@nokia.com. ** ** ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QTEXTDOCUMENTWRITER_H
end_ifndef
begin_define
DECL|macro|QTEXTDOCUMENTWRITER_H
define|#
directive|define
name|QTEXTDOCUMENTWRITER_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qstring.h>
end_include
begin_function
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
name|QT_MODULE
parameter_list|(
name|Gui
parameter_list|)
name|class
name|QTextDocumentWriterPrivate
decl_stmt|;
DECL|variable|QIODevice
name|class
name|QIODevice
decl_stmt|;
DECL|variable|QByteArray
name|class
name|QByteArray
decl_stmt|;
DECL|variable|QTextDocument
name|class
name|QTextDocument
decl_stmt|;
DECL|variable|QTextDocumentFragment
name|class
name|QTextDocumentFragment
decl_stmt|;
name|class
name|Q_GUI_EXPORT
name|QTextDocumentWriter
decl_stmt|{ public:     QTextDocumentWriter(
end_function
begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt
begin_expr_stmt
name|QTextDocumentWriter
argument_list|(
name|QIODevice
operator|*
name|device
argument_list|,
specifier|const
name|QByteArray
operator|&
name|format
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|QTextDocumentWriter
argument_list|(
specifier|const
name|QString
operator|&
name|fileName
argument_list|,
specifier|const
name|QByteArray
operator|&
name|format
operator|=
name|QByteArray
argument_list|()
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
operator|~
name|QTextDocumentWriter
argument_list|()
expr_stmt|;
end_expr_stmt
begin_function_decl
name|void
name|setFormat
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|format
parameter_list|)
function_decl|;
end_function_decl
begin_expr_stmt
name|QByteArray
name|format
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_function_decl
name|void
name|setDevice
parameter_list|(
name|QIODevice
modifier|*
name|device
parameter_list|)
function_decl|;
end_function_decl
begin_expr_stmt
name|QIODevice
operator|*
name|device
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_function_decl
name|void
name|setFileName
parameter_list|(
specifier|const
name|QString
modifier|&
name|fileName
parameter_list|)
function_decl|;
end_function_decl
begin_expr_stmt
name|QString
name|fileName
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_function_decl
name|bool
name|write
parameter_list|(
specifier|const
name|QTextDocument
modifier|*
name|document
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|bool
name|write
parameter_list|(
specifier|const
name|QTextDocumentFragment
modifier|&
name|fragment
parameter_list|)
function_decl|;
end_function_decl
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_TEXTCODEC
end_ifndef
begin_function_decl
name|void
name|setCodec
parameter_list|(
name|QTextCodec
modifier|*
name|codec
parameter_list|)
function_decl|;
end_function_decl
begin_expr_stmt
name|QTextCodec
operator|*
name|codec
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_expr_stmt
specifier|static
name|QList
operator|<
name|QByteArray
operator|>
name|supportedDocumentFormats
argument_list|()
expr_stmt|;
end_expr_stmt
begin_label
name|private
label|:
end_label
begin_macro
name|Q_DISABLE_COPY
argument_list|(
argument|QTextDocumentWriter
argument_list|)
end_macro
begin_decl_stmt
name|QTextDocumentWriterPrivate
modifier|*
name|d
decl_stmt|;
end_decl_stmt
begin_expr_stmt
unit|};
name|QT_END_NAMESPACE
name|QT_END_HEADER
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
end_unit
