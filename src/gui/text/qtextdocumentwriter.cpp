begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qtextdocumentwriter.h"
end_include
begin_include
include|#
directive|include
file|<QtCore/qfile.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qbytearray.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qfileinfo.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qtextcodec.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qtextstream.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qdebug.h>
end_include
begin_include
include|#
directive|include
file|"qtextdocument.h"
end_include
begin_include
include|#
directive|include
file|"qtextdocumentfragment.h"
end_include
begin_include
include|#
directive|include
file|"qtextdocumentfragment_p.h"
end_include
begin_include
include|#
directive|include
file|"qtextodfwriter_p.h"
end_include
begin_include
include|#
directive|include
file|<algorithm>
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_class
DECL|class|QTextDocumentWriterPrivate
class|class
name|QTextDocumentWriterPrivate
block|{
public|public:
name|QTextDocumentWriterPrivate
parameter_list|(
name|QTextDocumentWriter
modifier|*
name|qq
parameter_list|)
constructor_decl|;
comment|// device
DECL|member|format
name|QByteArray
name|format
decl_stmt|;
DECL|member|device
name|QIODevice
modifier|*
name|device
decl_stmt|;
DECL|member|deleteDevice
name|bool
name|deleteDevice
decl_stmt|;
ifndef|#
directive|ifndef
name|QT_NO_TEXTCODEC
DECL|member|codec
name|QTextCodec
modifier|*
name|codec
decl_stmt|;
endif|#
directive|endif
DECL|member|q
name|QTextDocumentWriter
modifier|*
name|q
decl_stmt|;
block|}
class|;
end_class
begin_comment
comment|/*!     \since 4.5     \class QTextDocumentWriter      \brief The QTextDocumentWriter class provides a format-independent interface for writing a QTextDocument to files or other devices.     \inmodule QtGui      \ingroup richtext-processing     \ingroup io      To write a document, construct a QTextDocumentWriter object with either a     file name or a device object, and specify the document format to be     written. You can construct a writer and set the format using setFormat()     later.      Call write() to write the document to the device. If the document is     successfully written, this function returns \c true. However, if an error     occurs when writing the document, it will return false.      Call supportedDocumentFormats() for a list of formats that     QTextDocumentWriter can write.      Since the capabilities of the supported output formats vary considerably,     the writer simply outputs the appropriate subset of objects for each format.     This typically includes the formatted text and images contained in a     document. */
end_comment
begin_comment
comment|/*!     \internal */
end_comment
begin_constructor
DECL|function|QTextDocumentWriterPrivate
name|QTextDocumentWriterPrivate
operator|::
name|QTextDocumentWriterPrivate
parameter_list|(
name|QTextDocumentWriter
modifier|*
name|qq
parameter_list|)
member_init_list|:
name|device
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|deleteDevice
argument_list|(
literal|false
argument_list|)
member_init_list|,
ifndef|#
directive|ifndef
name|QT_NO_TEXTCODEC
name|codec
argument_list|(
name|QTextCodec
operator|::
name|codecForName
argument_list|(
literal|"utf-8"
argument_list|)
argument_list|)
member_init_list|,
endif|#
directive|endif
name|q
argument_list|(
name|qq
argument_list|)
block|{ }
end_constructor
begin_comment
comment|/*!     Constructs an empty QTextDocumentWriter object. Before writing, you must     call setFormat() to set a document format, then setDevice() or     setFileName(). */
end_comment
begin_constructor
DECL|function|QTextDocumentWriter
name|QTextDocumentWriter
operator|::
name|QTextDocumentWriter
parameter_list|()
member_init_list|:
name|d
argument_list|(
operator|new
name|QTextDocumentWriterPrivate
argument_list|(
name|this
argument_list|)
argument_list|)
block|{ }
end_constructor
begin_comment
comment|/*!     Constructs a QTextDocumentWriter object to write to the given \a device     in the document format specified by \a format. */
end_comment
begin_constructor
DECL|function|QTextDocumentWriter
name|QTextDocumentWriter
operator|::
name|QTextDocumentWriter
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
member_init_list|:
name|d
argument_list|(
operator|new
name|QTextDocumentWriterPrivate
argument_list|(
name|this
argument_list|)
argument_list|)
block|{
name|d
operator|->
name|device
operator|=
name|device
expr_stmt|;
name|d
operator|->
name|format
operator|=
name|format
expr_stmt|;
block|}
end_constructor
begin_comment
comment|/*!     Constructs an QTextDocumentWriter object that will write to a file with     the name \a fileName, using the document format specified by \a format.     If \a format is not provided, QTextDocumentWriter will detect the document     format by inspecting the extension of \a fileName. */
end_comment
begin_constructor
DECL|function|QTextDocumentWriter
name|QTextDocumentWriter
operator|::
name|QTextDocumentWriter
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
parameter_list|)
member_init_list|:
name|d
argument_list|(
operator|new
name|QTextDocumentWriterPrivate
argument_list|(
name|this
argument_list|)
argument_list|)
block|{
name|QFile
modifier|*
name|file
init|=
operator|new
name|QFile
argument_list|(
name|fileName
argument_list|)
decl_stmt|;
name|d
operator|->
name|device
operator|=
name|file
expr_stmt|;
name|d
operator|->
name|deleteDevice
operator|=
literal|true
expr_stmt|;
name|d
operator|->
name|format
operator|=
name|format
expr_stmt|;
block|}
end_constructor
begin_comment
comment|/*!     Destroys the QTextDocumentWriter object. */
end_comment
begin_destructor
DECL|function|~QTextDocumentWriter
name|QTextDocumentWriter
operator|::
name|~
name|QTextDocumentWriter
parameter_list|()
block|{
if|if
condition|(
name|d
operator|->
name|deleteDevice
condition|)
operator|delete
name|d
operator|->
name|device
expr_stmt|;
operator|delete
name|d
expr_stmt|;
block|}
end_destructor
begin_comment
comment|/*!     Sets the format used to write documents to the \a format specified.     \a format is a case insensitive text string. For example:      \snippet code/src_gui_text_qtextdocumentwriter.cpp 0      You can call supportedDocumentFormats() for the full list of formats     QTextDocumentWriter supports.      \sa format() */
end_comment
begin_function
DECL|function|setFormat
name|void
name|QTextDocumentWriter
operator|::
name|setFormat
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|format
parameter_list|)
block|{
name|d
operator|->
name|format
operator|=
name|format
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     Returns the format used for writing documents.      \sa setFormat() */
end_comment
begin_function
DECL|function|format
name|QByteArray
name|QTextDocumentWriter
operator|::
name|format
parameter_list|()
specifier|const
block|{
return|return
name|d
operator|->
name|format
return|;
block|}
end_function
begin_comment
comment|/*!     Sets the writer's device to the \a device specified. If a device has     already been set, the old device is removed but otherwise left     unchanged.      If the device is not already open, QTextDocumentWriter will attempt to     open the device in \l QIODevice::WriteOnly mode by calling open().      \note This will not work for certain devices, such as QProcess,     QTcpSocket and QUdpSocket, where some configuration is required before     the device can be opened.      \sa device(), setFileName() */
end_comment
begin_function
DECL|function|setDevice
name|void
name|QTextDocumentWriter
operator|::
name|setDevice
parameter_list|(
name|QIODevice
modifier|*
name|device
parameter_list|)
block|{
if|if
condition|(
name|d
operator|->
name|device
operator|&&
name|d
operator|->
name|deleteDevice
condition|)
operator|delete
name|d
operator|->
name|device
expr_stmt|;
name|d
operator|->
name|device
operator|=
name|device
expr_stmt|;
name|d
operator|->
name|deleteDevice
operator|=
literal|false
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     Returns the device currently assigned, or 0 if no device has been     assigned. */
end_comment
begin_function
DECL|function|device
name|QIODevice
modifier|*
name|QTextDocumentWriter
operator|::
name|device
parameter_list|()
specifier|const
block|{
return|return
name|d
operator|->
name|device
return|;
block|}
end_function
begin_comment
comment|/*!     Sets the name of the file to be written to \a fileName. Internally,     QTextDocumentWriter will create a QFile and open it in \l     QIODevice::WriteOnly mode, and use this file when writing the document.      \sa fileName(), setDevice() */
end_comment
begin_function
DECL|function|setFileName
name|void
name|QTextDocumentWriter
operator|::
name|setFileName
parameter_list|(
specifier|const
name|QString
modifier|&
name|fileName
parameter_list|)
block|{
name|setDevice
argument_list|(
operator|new
name|QFile
argument_list|(
name|fileName
argument_list|)
argument_list|)
expr_stmt|;
name|d
operator|->
name|deleteDevice
operator|=
literal|true
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     If the currently assigned device is a QFile, or if setFileName()     has been called, this function returns the name of the file     to be written to. In all other cases, it returns an empty string.      \sa setFileName(), setDevice() */
end_comment
begin_function
DECL|function|fileName
name|QString
name|QTextDocumentWriter
operator|::
name|fileName
parameter_list|()
specifier|const
block|{
name|QFile
modifier|*
name|file
init|=
name|qobject_cast
argument_list|<
name|QFile
operator|*
argument_list|>
argument_list|(
name|d
operator|->
name|device
argument_list|)
decl_stmt|;
return|return
name|file
condition|?
name|file
operator|->
name|fileName
argument_list|()
else|:
name|QString
argument_list|()
return|;
block|}
end_function
begin_comment
comment|/*!     Writes the given \a document to the assigned device or file and     returns \c true if successful; otherwise returns \c false. */
end_comment
begin_function
DECL|function|write
name|bool
name|QTextDocumentWriter
operator|::
name|write
parameter_list|(
specifier|const
name|QTextDocument
modifier|*
name|document
parameter_list|)
block|{
name|QByteArray
name|suffix
decl_stmt|;
if|if
condition|(
name|d
operator|->
name|device
operator|&&
name|d
operator|->
name|format
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
comment|// if there's no format, see if device is a file, and if so, find
comment|// the file suffix
if|if
condition|(
name|QFile
modifier|*
name|file
init|=
name|qobject_cast
argument_list|<
name|QFile
operator|*
argument_list|>
argument_list|(
name|d
operator|->
name|device
argument_list|)
condition|)
name|suffix
operator|=
name|QFileInfo
argument_list|(
name|file
operator|->
name|fileName
argument_list|()
argument_list|)
operator|.
name|suffix
argument_list|()
operator|.
name|toLower
argument_list|()
operator|.
name|toLatin1
argument_list|()
expr_stmt|;
block|}
name|QByteArray
name|format
init|=
operator|!
name|d
operator|->
name|format
operator|.
name|isEmpty
argument_list|()
condition|?
name|d
operator|->
name|format
operator|.
name|toLower
argument_list|()
else|:
name|suffix
decl_stmt|;
ifndef|#
directive|ifndef
name|QT_NO_TEXTODFWRITER
if|if
condition|(
name|format
operator|==
literal|"odf"
operator|||
name|format
operator|==
literal|"opendocumentformat"
operator|||
name|format
operator|==
literal|"odt"
condition|)
block|{
name|QTextOdfWriter
name|writer
argument_list|(
operator|*
name|document
argument_list|,
name|d
operator|->
name|device
argument_list|)
decl_stmt|;
ifndef|#
directive|ifndef
name|QT_NO_TEXTCODEC
name|writer
operator|.
name|setCodec
argument_list|(
name|d
operator|->
name|codec
argument_list|)
expr_stmt|;
endif|#
directive|endif
return|return
name|writer
operator|.
name|writeAll
argument_list|()
return|;
block|}
endif|#
directive|endif
comment|// QT_NO_TEXTODFWRITER
ifndef|#
directive|ifndef
name|QT_NO_TEXTHTMLPARSER
if|if
condition|(
name|format
operator|==
literal|"html"
operator|||
name|format
operator|==
literal|"htm"
condition|)
block|{
if|if
condition|(
operator|!
name|d
operator|->
name|device
operator|->
name|isWritable
argument_list|()
operator|&&
operator|!
name|d
operator|->
name|device
operator|->
name|open
argument_list|(
name|QIODevice
operator|::
name|WriteOnly
argument_list|)
condition|)
block|{
name|qWarning
argument_list|(
literal|"QTextDocumentWriter::write: the device can not be opened for writing"
argument_list|)
expr_stmt|;
return|return
literal|false
return|;
block|}
name|QTextStream
name|ts
argument_list|(
name|d
operator|->
name|device
argument_list|)
decl_stmt|;
ifndef|#
directive|ifndef
name|QT_NO_TEXTCODEC
name|ts
operator|.
name|setCodec
argument_list|(
name|d
operator|->
name|codec
argument_list|)
expr_stmt|;
name|ts
operator|<<
name|document
operator|->
name|toHtml
argument_list|(
name|d
operator|->
name|codec
operator|->
name|name
argument_list|()
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|d
operator|->
name|device
operator|->
name|close
argument_list|()
expr_stmt|;
return|return
literal|true
return|;
block|}
endif|#
directive|endif
if|if
condition|(
name|format
operator|==
literal|"txt"
operator|||
name|format
operator|==
literal|"plaintext"
condition|)
block|{
if|if
condition|(
operator|!
name|d
operator|->
name|device
operator|->
name|isWritable
argument_list|()
operator|&&
operator|!
name|d
operator|->
name|device
operator|->
name|open
argument_list|(
name|QIODevice
operator|::
name|WriteOnly
argument_list|)
condition|)
block|{
name|qWarning
argument_list|(
literal|"QTextDocumentWriter::write: the device can not be opened for writing"
argument_list|)
expr_stmt|;
return|return
literal|false
return|;
block|}
name|QTextStream
name|ts
argument_list|(
name|d
operator|->
name|device
argument_list|)
decl_stmt|;
ifndef|#
directive|ifndef
name|QT_NO_TEXTCODEC
name|ts
operator|.
name|setCodec
argument_list|(
name|d
operator|->
name|codec
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|ts
operator|<<
name|document
operator|->
name|toPlainText
argument_list|()
expr_stmt|;
name|d
operator|->
name|device
operator|->
name|close
argument_list|()
expr_stmt|;
return|return
literal|true
return|;
block|}
return|return
literal|false
return|;
block|}
end_function
begin_comment
comment|/*!     Writes the document fragment specified by \a fragment to the assigned device     or file and returns \c true if successful; otherwise returns \c false. */
end_comment
begin_function
DECL|function|write
name|bool
name|QTextDocumentWriter
operator|::
name|write
parameter_list|(
specifier|const
name|QTextDocumentFragment
modifier|&
name|fragment
parameter_list|)
block|{
if|if
condition|(
name|fragment
operator|.
name|d
operator|==
literal|0
condition|)
return|return
literal|false
return|;
comment|// invalid fragment.
name|QTextDocument
modifier|*
name|doc
init|=
name|fragment
operator|.
name|d
operator|->
name|doc
decl_stmt|;
if|if
condition|(
name|doc
condition|)
return|return
name|write
argument_list|(
name|doc
argument_list|)
return|;
return|return
literal|false
return|;
block|}
end_function
begin_comment
comment|/*!     Sets the codec for this stream to \a codec. The codec is used for     encoding any data that is written. By default, QTextDocumentWriter     uses UTF-8. */
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_TEXTCODEC
end_ifndef
begin_function
DECL|function|setCodec
name|void
name|QTextDocumentWriter
operator|::
name|setCodec
parameter_list|(
name|QTextCodec
modifier|*
name|codec
parameter_list|)
block|{
if|if
condition|(
name|codec
operator|==
literal|0
condition|)
name|codec
operator|=
name|QTextCodec
operator|::
name|codecForName
argument_list|(
literal|"UTF-8"
argument_list|)
expr_stmt|;
name|Q_ASSERT
argument_list|(
name|codec
argument_list|)
expr_stmt|;
name|d
operator|->
name|codec
operator|=
name|codec
expr_stmt|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/*!     Returns the codec that is currently assigned to the writer. */
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_TEXTCODEC
end_ifndef
begin_function
DECL|function|codec
name|QTextCodec
modifier|*
name|QTextDocumentWriter
operator|::
name|codec
parameter_list|()
specifier|const
block|{
return|return
name|d
operator|->
name|codec
return|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/*!     Returns the list of document formats supported by QTextDocumentWriter.      By default, Qt can write the following formats:      \table     \header \li Format    \li Description     \row    \li plaintext \li Plain text     \row    \li HTML      \li HyperText Markup Language     \row    \li ODF       \li OpenDocument Format     \endtable      \sa setFormat() */
end_comment
begin_function
DECL|function|supportedDocumentFormats
name|QList
argument_list|<
name|QByteArray
argument_list|>
name|QTextDocumentWriter
operator|::
name|supportedDocumentFormats
parameter_list|()
block|{
name|QList
argument_list|<
name|QByteArray
argument_list|>
name|answer
decl_stmt|;
name|answer
operator|<<
literal|"plaintext"
expr_stmt|;
ifndef|#
directive|ifndef
name|QT_NO_TEXTHTMLPARSER
name|answer
operator|<<
literal|"HTML"
expr_stmt|;
endif|#
directive|endif
ifndef|#
directive|ifndef
name|QT_NO_TEXTODFWRITER
name|answer
operator|<<
literal|"ODF"
expr_stmt|;
endif|#
directive|endif
comment|// QT_NO_TEXTODFWRITER
name|std
operator|::
name|sort
argument_list|(
name|answer
operator|.
name|begin
argument_list|()
argument_list|,
name|answer
operator|.
name|end
argument_list|()
argument_list|)
expr_stmt|;
return|return
name|answer
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
