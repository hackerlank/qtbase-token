begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** BSD License Usage ** Alternatively, you may use this file under the terms of the BSD license ** as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of The Qt Company Ltd nor the names of its **     contributors may be used to endorse or promote products derived **     from this software without specific prior written permission. ** ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtWidgets>
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_PRINTER
end_ifndef
begin_include
include|#
directive|include
file|<QPrintDialog>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_include
include|#
directive|include
file|"imageviewer.h"
end_include
begin_comment
comment|//! [0]
end_comment
begin_constructor
DECL|function|ImageViewer
name|ImageViewer
operator|::
name|ImageViewer
parameter_list|()
member_init_list|:
name|imageLabel
argument_list|(
operator|new
name|QLabel
argument_list|)
member_init_list|,
name|scrollArea
argument_list|(
operator|new
name|QScrollArea
argument_list|)
member_init_list|,
name|scaleFactor
argument_list|(
literal|1
argument_list|)
block|{
name|imageLabel
operator|->
name|setBackgroundRole
argument_list|(
name|QPalette
operator|::
name|Base
argument_list|)
expr_stmt|;
name|imageLabel
operator|->
name|setSizePolicy
argument_list|(
name|QSizePolicy
operator|::
name|Ignored
argument_list|,
name|QSizePolicy
operator|::
name|Ignored
argument_list|)
expr_stmt|;
name|imageLabel
operator|->
name|setScaledContents
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|scrollArea
operator|->
name|setBackgroundRole
argument_list|(
name|QPalette
operator|::
name|Dark
argument_list|)
expr_stmt|;
name|scrollArea
operator|->
name|setWidget
argument_list|(
name|imageLabel
argument_list|)
expr_stmt|;
name|scrollArea
operator|->
name|setVisible
argument_list|(
literal|false
argument_list|)
expr_stmt|;
name|setCentralWidget
argument_list|(
name|scrollArea
argument_list|)
expr_stmt|;
name|createActions
argument_list|()
expr_stmt|;
name|resize
argument_list|(
name|QGuiApplication
operator|::
name|primaryScreen
argument_list|()
operator|->
name|availableSize
argument_list|()
operator|*
literal|3
operator|/
literal|5
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_comment
comment|//! [0]
end_comment
begin_comment
comment|//! [2]
end_comment
begin_function
DECL|function|loadFile
name|bool
name|ImageViewer
operator|::
name|loadFile
parameter_list|(
specifier|const
name|QString
modifier|&
name|fileName
parameter_list|)
block|{
name|QImageReader
name|reader
argument_list|(
name|fileName
argument_list|)
decl_stmt|;
name|reader
operator|.
name|setAutoTransform
argument_list|(
literal|true
argument_list|)
expr_stmt|;
specifier|const
name|QImage
name|newImage
init|=
name|reader
operator|.
name|read
argument_list|()
decl_stmt|;
if|if
condition|(
name|newImage
operator|.
name|isNull
argument_list|()
condition|)
block|{
name|QMessageBox
operator|::
name|information
argument_list|(
name|this
argument_list|,
name|QGuiApplication
operator|::
name|applicationDisplayName
argument_list|()
argument_list|,
name|tr
argument_list|(
literal|"Cannot load %1: %2"
argument_list|)
operator|.
name|arg
argument_list|(
name|QDir
operator|::
name|toNativeSeparators
argument_list|(
name|fileName
argument_list|)
argument_list|,
name|reader
operator|.
name|errorString
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
return|return
literal|false
return|;
block|}
comment|//! [2]
name|setImage
argument_list|(
name|newImage
argument_list|)
expr_stmt|;
name|setWindowFilePath
argument_list|(
name|fileName
argument_list|)
expr_stmt|;
specifier|const
name|QString
name|message
init|=
name|tr
argument_list|(
literal|"Opened \"%1\", %2x%3, Depth: %4"
argument_list|)
operator|.
name|arg
argument_list|(
name|QDir
operator|::
name|toNativeSeparators
argument_list|(
name|fileName
argument_list|)
argument_list|)
operator|.
name|arg
argument_list|(
name|image
operator|.
name|width
argument_list|()
argument_list|)
operator|.
name|arg
argument_list|(
name|image
operator|.
name|height
argument_list|()
argument_list|)
operator|.
name|arg
argument_list|(
name|image
operator|.
name|depth
argument_list|()
argument_list|)
decl_stmt|;
name|statusBar
argument_list|()
operator|->
name|showMessage
argument_list|(
name|message
argument_list|)
expr_stmt|;
return|return
literal|true
return|;
block|}
end_function
begin_function
DECL|function|setImage
name|void
name|ImageViewer
operator|::
name|setImage
parameter_list|(
specifier|const
name|QImage
modifier|&
name|newImage
parameter_list|)
block|{
name|image
operator|=
name|newImage
expr_stmt|;
name|imageLabel
operator|->
name|setPixmap
argument_list|(
name|QPixmap
operator|::
name|fromImage
argument_list|(
name|image
argument_list|)
argument_list|)
expr_stmt|;
comment|//! [4]
name|scaleFactor
operator|=
literal|1.0
expr_stmt|;
name|scrollArea
operator|->
name|setVisible
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|printAct
operator|->
name|setEnabled
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|fitToWindowAct
operator|->
name|setEnabled
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|updateActions
argument_list|()
expr_stmt|;
if|if
condition|(
operator|!
name|fitToWindowAct
operator|->
name|isChecked
argument_list|()
condition|)
name|imageLabel
operator|->
name|adjustSize
argument_list|()
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [4]
end_comment
begin_function
DECL|function|saveFile
name|bool
name|ImageViewer
operator|::
name|saveFile
parameter_list|(
specifier|const
name|QString
modifier|&
name|fileName
parameter_list|)
block|{
name|QImageWriter
name|writer
argument_list|(
name|fileName
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|writer
operator|.
name|write
argument_list|(
name|image
argument_list|)
condition|)
block|{
name|QMessageBox
operator|::
name|information
argument_list|(
name|this
argument_list|,
name|QGuiApplication
operator|::
name|applicationDisplayName
argument_list|()
argument_list|,
name|tr
argument_list|(
literal|"Cannot write %1: %2"
argument_list|)
operator|.
name|arg
argument_list|(
name|QDir
operator|::
name|toNativeSeparators
argument_list|(
name|fileName
argument_list|)
argument_list|)
argument_list|,
name|writer
operator|.
name|errorString
argument_list|()
argument_list|)
expr_stmt|;
return|return
literal|false
return|;
block|}
specifier|const
name|QString
name|message
init|=
name|tr
argument_list|(
literal|"Wrote \"%1\""
argument_list|)
operator|.
name|arg
argument_list|(
name|QDir
operator|::
name|toNativeSeparators
argument_list|(
name|fileName
argument_list|)
argument_list|)
decl_stmt|;
name|statusBar
argument_list|()
operator|->
name|showMessage
argument_list|(
name|message
argument_list|)
expr_stmt|;
return|return
literal|true
return|;
block|}
end_function
begin_comment
comment|//! [1]
end_comment
begin_function
DECL|function|initializeImageFileDialog
specifier|static
name|void
name|initializeImageFileDialog
parameter_list|(
name|QFileDialog
modifier|&
name|dialog
parameter_list|,
name|QFileDialog
operator|::
name|AcceptMode
name|acceptMode
parameter_list|)
block|{
specifier|static
name|bool
name|firstDialog
init|=
literal|true
decl_stmt|;
if|if
condition|(
name|firstDialog
condition|)
block|{
name|firstDialog
operator|=
literal|false
expr_stmt|;
specifier|const
name|QStringList
name|picturesLocations
init|=
name|QStandardPaths
operator|::
name|standardLocations
argument_list|(
name|QStandardPaths
operator|::
name|PicturesLocation
argument_list|)
decl_stmt|;
name|dialog
operator|.
name|setDirectory
argument_list|(
name|picturesLocations
operator|.
name|isEmpty
argument_list|()
condition|?
name|QDir
operator|::
name|currentPath
argument_list|()
else|:
name|picturesLocations
operator|.
name|last
argument_list|()
argument_list|)
expr_stmt|;
block|}
name|QStringList
name|mimeTypeFilters
decl_stmt|;
specifier|const
name|QByteArrayList
name|supportedMimeTypes
init|=
name|acceptMode
operator|==
name|QFileDialog
operator|::
name|AcceptOpen
condition|?
name|QImageReader
operator|::
name|supportedMimeTypes
argument_list|()
else|:
name|QImageWriter
operator|::
name|supportedMimeTypes
argument_list|()
decl_stmt|;
foreach|foreach
control|(
specifier|const
name|QByteArray
modifier|&
name|mimeTypeName
decl|,
name|supportedMimeTypes
control|)
name|mimeTypeFilters
operator|.
name|append
argument_list|(
name|mimeTypeName
argument_list|)
expr_stmt|;
name|mimeTypeFilters
operator|.
name|sort
argument_list|()
expr_stmt|;
name|dialog
operator|.
name|setMimeTypeFilters
argument_list|(
name|mimeTypeFilters
argument_list|)
expr_stmt|;
name|dialog
operator|.
name|selectMimeTypeFilter
argument_list|(
literal|"image/jpeg"
argument_list|)
expr_stmt|;
if|if
condition|(
name|acceptMode
operator|==
name|QFileDialog
operator|::
name|AcceptSave
condition|)
name|dialog
operator|.
name|setDefaultSuffix
argument_list|(
literal|"jpg"
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|open
name|void
name|ImageViewer
operator|::
name|open
parameter_list|()
block|{
name|QFileDialog
name|dialog
argument_list|(
name|this
argument_list|,
name|tr
argument_list|(
literal|"Open File"
argument_list|)
argument_list|)
decl_stmt|;
name|initializeImageFileDialog
argument_list|(
name|dialog
argument_list|,
name|QFileDialog
operator|::
name|AcceptOpen
argument_list|)
expr_stmt|;
while|while
condition|(
name|dialog
operator|.
name|exec
argument_list|()
operator|==
name|QDialog
operator|::
name|Accepted
operator|&&
operator|!
name|loadFile
argument_list|(
name|dialog
operator|.
name|selectedFiles
argument_list|()
operator|.
name|first
argument_list|()
argument_list|)
condition|)
block|{}
block|}
end_function
begin_comment
comment|//! [1]
end_comment
begin_function
DECL|function|saveAs
name|void
name|ImageViewer
operator|::
name|saveAs
parameter_list|()
block|{
name|QFileDialog
name|dialog
argument_list|(
name|this
argument_list|,
name|tr
argument_list|(
literal|"Save File As"
argument_list|)
argument_list|)
decl_stmt|;
name|initializeImageFileDialog
argument_list|(
name|dialog
argument_list|,
name|QFileDialog
operator|::
name|AcceptSave
argument_list|)
expr_stmt|;
while|while
condition|(
name|dialog
operator|.
name|exec
argument_list|()
operator|==
name|QDialog
operator|::
name|Accepted
operator|&&
operator|!
name|saveFile
argument_list|(
name|dialog
operator|.
name|selectedFiles
argument_list|()
operator|.
name|first
argument_list|()
argument_list|)
condition|)
block|{}
block|}
end_function
begin_comment
comment|//! [5]
end_comment
begin_function
DECL|function|print
name|void
name|ImageViewer
operator|::
name|print
parameter_list|()
comment|//! [5] //! [6]
block|{
name|Q_ASSERT
argument_list|(
name|imageLabel
operator|->
name|pixmap
argument_list|()
argument_list|)
expr_stmt|;
if|#
directive|if
operator|!
name|defined
argument_list|(
name|QT_NO_PRINTER
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|QT_NO_PRINTDIALOG
argument_list|)
comment|//! [6] //! [7]
name|QPrintDialog
name|dialog
argument_list|(
operator|&
name|printer
argument_list|,
name|this
argument_list|)
decl_stmt|;
comment|//! [7] //! [8]
if|if
condition|(
name|dialog
operator|.
name|exec
argument_list|()
condition|)
block|{
name|QPainter
name|painter
argument_list|(
operator|&
name|printer
argument_list|)
decl_stmt|;
name|QRect
name|rect
init|=
name|painter
operator|.
name|viewport
argument_list|()
decl_stmt|;
name|QSize
name|size
init|=
name|imageLabel
operator|->
name|pixmap
argument_list|()
operator|->
name|size
argument_list|()
decl_stmt|;
name|size
operator|.
name|scale
argument_list|(
name|rect
operator|.
name|size
argument_list|()
argument_list|,
name|Qt
operator|::
name|KeepAspectRatio
argument_list|)
expr_stmt|;
name|painter
operator|.
name|setViewport
argument_list|(
name|rect
operator|.
name|x
argument_list|()
argument_list|,
name|rect
operator|.
name|y
argument_list|()
argument_list|,
name|size
operator|.
name|width
argument_list|()
argument_list|,
name|size
operator|.
name|height
argument_list|()
argument_list|)
expr_stmt|;
name|painter
operator|.
name|setWindow
argument_list|(
name|imageLabel
operator|->
name|pixmap
argument_list|()
operator|->
name|rect
argument_list|()
argument_list|)
expr_stmt|;
name|painter
operator|.
name|drawPixmap
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
operator|*
name|imageLabel
operator|->
name|pixmap
argument_list|()
argument_list|)
expr_stmt|;
block|}
endif|#
directive|endif
block|}
end_function
begin_comment
comment|//! [8]
end_comment
begin_function
DECL|function|copy
name|void
name|ImageViewer
operator|::
name|copy
parameter_list|()
block|{
ifndef|#
directive|ifndef
name|QT_NO_CLIPBOARD
name|QGuiApplication
operator|::
name|clipboard
argument_list|()
operator|->
name|setImage
argument_list|(
name|image
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|// !QT_NO_CLIPBOARD
block|}
end_function
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_CLIPBOARD
end_ifndef
begin_function
DECL|function|clipboardImage
specifier|static
name|QImage
name|clipboardImage
parameter_list|()
block|{
if|if
condition|(
specifier|const
name|QMimeData
modifier|*
name|mimeData
init|=
name|QGuiApplication
operator|::
name|clipboard
argument_list|()
operator|->
name|mimeData
argument_list|()
condition|)
block|{
if|if
condition|(
name|mimeData
operator|->
name|hasImage
argument_list|()
condition|)
block|{
specifier|const
name|QImage
name|image
init|=
name|qvariant_cast
argument_list|<
name|QImage
argument_list|>
argument_list|(
name|mimeData
operator|->
name|imageData
argument_list|()
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|image
operator|.
name|isNull
argument_list|()
condition|)
return|return
name|image
return|;
block|}
block|}
return|return
name|QImage
argument_list|()
return|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// !QT_NO_CLIPBOARD
end_comment
begin_function
DECL|function|paste
name|void
name|ImageViewer
operator|::
name|paste
parameter_list|()
block|{
ifndef|#
directive|ifndef
name|QT_NO_CLIPBOARD
specifier|const
name|QImage
name|newImage
init|=
name|clipboardImage
argument_list|()
decl_stmt|;
if|if
condition|(
name|newImage
operator|.
name|isNull
argument_list|()
condition|)
block|{
name|statusBar
argument_list|()
operator|->
name|showMessage
argument_list|(
name|tr
argument_list|(
literal|"No image in clipboard"
argument_list|)
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|setImage
argument_list|(
name|newImage
argument_list|)
expr_stmt|;
name|setWindowFilePath
argument_list|(
name|QString
argument_list|()
argument_list|)
expr_stmt|;
specifier|const
name|QString
name|message
init|=
name|tr
argument_list|(
literal|"Obtained image from clipboard, %1x%2, Depth: %3"
argument_list|)
operator|.
name|arg
argument_list|(
name|newImage
operator|.
name|width
argument_list|()
argument_list|)
operator|.
name|arg
argument_list|(
name|newImage
operator|.
name|height
argument_list|()
argument_list|)
operator|.
name|arg
argument_list|(
name|newImage
operator|.
name|depth
argument_list|()
argument_list|)
decl_stmt|;
name|statusBar
argument_list|()
operator|->
name|showMessage
argument_list|(
name|message
argument_list|)
expr_stmt|;
block|}
endif|#
directive|endif
comment|// !QT_NO_CLIPBOARD
block|}
end_function
begin_comment
comment|//! [9]
end_comment
begin_function
DECL|function|zoomIn
name|void
name|ImageViewer
operator|::
name|zoomIn
parameter_list|()
comment|//! [9] //! [10]
block|{
name|scaleImage
argument_list|(
literal|1.25
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|zoomOut
name|void
name|ImageViewer
operator|::
name|zoomOut
parameter_list|()
block|{
name|scaleImage
argument_list|(
literal|0.8
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [10] //! [11]
end_comment
begin_function
DECL|function|normalSize
name|void
name|ImageViewer
operator|::
name|normalSize
parameter_list|()
comment|//! [11] //! [12]
block|{
name|imageLabel
operator|->
name|adjustSize
argument_list|()
expr_stmt|;
name|scaleFactor
operator|=
literal|1.0
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [12]
end_comment
begin_comment
comment|//! [13]
end_comment
begin_function
DECL|function|fitToWindow
name|void
name|ImageViewer
operator|::
name|fitToWindow
parameter_list|()
comment|//! [13] //! [14]
block|{
name|bool
name|fitToWindow
init|=
name|fitToWindowAct
operator|->
name|isChecked
argument_list|()
decl_stmt|;
name|scrollArea
operator|->
name|setWidgetResizable
argument_list|(
name|fitToWindow
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|fitToWindow
condition|)
name|normalSize
argument_list|()
expr_stmt|;
name|updateActions
argument_list|()
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [14]
end_comment
begin_comment
comment|//! [15]
end_comment
begin_function
DECL|function|about
name|void
name|ImageViewer
operator|::
name|about
parameter_list|()
comment|//! [15] //! [16]
block|{
name|QMessageBox
operator|::
name|about
argument_list|(
name|this
argument_list|,
name|tr
argument_list|(
literal|"About Image Viewer"
argument_list|)
argument_list|,
name|tr
argument_list|(
literal|"<p>The<b>Image Viewer</b> example shows how to combine QLabel "
literal|"and QScrollArea to display an image. QLabel is typically used "
literal|"for displaying a text, but it can also display an image. "
literal|"QScrollArea provides a scrolling view around another widget. "
literal|"If the child widget exceeds the size of the frame, QScrollArea "
literal|"automatically provides scroll bars.</p><p>The example "
literal|"demonstrates how QLabel's ability to scale its contents "
literal|"(QLabel::scaledContents), and QScrollArea's ability to "
literal|"automatically resize its contents "
literal|"(QScrollArea::widgetResizable), can be used to implement "
literal|"zooming and scaling features.</p><p>In addition the example "
literal|"shows how to use QPainter to print an image.</p>"
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [16]
end_comment
begin_comment
comment|//! [17]
end_comment
begin_function
DECL|function|createActions
name|void
name|ImageViewer
operator|::
name|createActions
parameter_list|()
comment|//! [17] //! [18]
block|{
name|QMenu
modifier|*
name|fileMenu
init|=
name|menuBar
argument_list|()
operator|->
name|addMenu
argument_list|(
name|tr
argument_list|(
literal|"&File"
argument_list|)
argument_list|)
decl_stmt|;
name|QAction
modifier|*
name|openAct
init|=
name|fileMenu
operator|->
name|addAction
argument_list|(
name|tr
argument_list|(
literal|"&Open..."
argument_list|)
argument_list|,
name|this
argument_list|,
operator|&
name|ImageViewer
operator|::
name|open
argument_list|)
decl_stmt|;
name|openAct
operator|->
name|setShortcut
argument_list|(
name|QKeySequence
operator|::
name|Open
argument_list|)
expr_stmt|;
name|saveAsAct
operator|=
name|fileMenu
operator|->
name|addAction
argument_list|(
name|tr
argument_list|(
literal|"&Save As..."
argument_list|)
argument_list|,
name|this
argument_list|,
operator|&
name|ImageViewer
operator|::
name|saveAs
argument_list|)
expr_stmt|;
name|saveAsAct
operator|->
name|setEnabled
argument_list|(
literal|false
argument_list|)
expr_stmt|;
name|printAct
operator|=
name|fileMenu
operator|->
name|addAction
argument_list|(
name|tr
argument_list|(
literal|"&Print..."
argument_list|)
argument_list|,
name|this
argument_list|,
operator|&
name|ImageViewer
operator|::
name|print
argument_list|)
expr_stmt|;
name|printAct
operator|->
name|setShortcut
argument_list|(
name|QKeySequence
operator|::
name|Print
argument_list|)
expr_stmt|;
name|printAct
operator|->
name|setEnabled
argument_list|(
literal|false
argument_list|)
expr_stmt|;
name|fileMenu
operator|->
name|addSeparator
argument_list|()
expr_stmt|;
name|QAction
modifier|*
name|exitAct
init|=
name|fileMenu
operator|->
name|addAction
argument_list|(
name|tr
argument_list|(
literal|"E&xit"
argument_list|)
argument_list|,
name|this
argument_list|,
operator|&
name|QWidget
operator|::
name|close
argument_list|)
decl_stmt|;
name|exitAct
operator|->
name|setShortcut
argument_list|(
name|tr
argument_list|(
literal|"Ctrl+Q"
argument_list|)
argument_list|)
expr_stmt|;
name|QMenu
modifier|*
name|editMenu
init|=
name|menuBar
argument_list|()
operator|->
name|addMenu
argument_list|(
name|tr
argument_list|(
literal|"&Edit"
argument_list|)
argument_list|)
decl_stmt|;
name|copyAct
operator|=
name|editMenu
operator|->
name|addAction
argument_list|(
name|tr
argument_list|(
literal|"&Copy"
argument_list|)
argument_list|,
name|this
argument_list|,
operator|&
name|ImageViewer
operator|::
name|copy
argument_list|)
expr_stmt|;
name|copyAct
operator|->
name|setShortcut
argument_list|(
name|QKeySequence
operator|::
name|Copy
argument_list|)
expr_stmt|;
name|copyAct
operator|->
name|setEnabled
argument_list|(
literal|false
argument_list|)
expr_stmt|;
name|QAction
modifier|*
name|pasteAct
init|=
name|editMenu
operator|->
name|addAction
argument_list|(
name|tr
argument_list|(
literal|"&Paste"
argument_list|)
argument_list|,
name|this
argument_list|,
operator|&
name|ImageViewer
operator|::
name|paste
argument_list|)
decl_stmt|;
name|pasteAct
operator|->
name|setShortcut
argument_list|(
name|QKeySequence
operator|::
name|Paste
argument_list|)
expr_stmt|;
name|QMenu
modifier|*
name|viewMenu
init|=
name|menuBar
argument_list|()
operator|->
name|addMenu
argument_list|(
name|tr
argument_list|(
literal|"&View"
argument_list|)
argument_list|)
decl_stmt|;
name|zoomInAct
operator|=
name|viewMenu
operator|->
name|addAction
argument_list|(
name|tr
argument_list|(
literal|"Zoom&In (25%)"
argument_list|)
argument_list|,
name|this
argument_list|,
operator|&
name|ImageViewer
operator|::
name|zoomIn
argument_list|)
expr_stmt|;
name|zoomInAct
operator|->
name|setShortcut
argument_list|(
name|QKeySequence
operator|::
name|ZoomIn
argument_list|)
expr_stmt|;
name|zoomInAct
operator|->
name|setEnabled
argument_list|(
literal|false
argument_list|)
expr_stmt|;
name|zoomOutAct
operator|=
name|viewMenu
operator|->
name|addAction
argument_list|(
name|tr
argument_list|(
literal|"Zoom&Out (25%)"
argument_list|)
argument_list|,
name|this
argument_list|,
operator|&
name|ImageViewer
operator|::
name|zoomOut
argument_list|)
expr_stmt|;
name|zoomOutAct
operator|->
name|setShortcut
argument_list|(
name|QKeySequence
operator|::
name|ZoomOut
argument_list|)
expr_stmt|;
name|zoomOutAct
operator|->
name|setEnabled
argument_list|(
literal|false
argument_list|)
expr_stmt|;
name|normalSizeAct
operator|=
name|viewMenu
operator|->
name|addAction
argument_list|(
name|tr
argument_list|(
literal|"&Normal Size"
argument_list|)
argument_list|,
name|this
argument_list|,
operator|&
name|ImageViewer
operator|::
name|normalSize
argument_list|)
expr_stmt|;
name|normalSizeAct
operator|->
name|setShortcut
argument_list|(
name|tr
argument_list|(
literal|"Ctrl+S"
argument_list|)
argument_list|)
expr_stmt|;
name|normalSizeAct
operator|->
name|setEnabled
argument_list|(
literal|false
argument_list|)
expr_stmt|;
name|viewMenu
operator|->
name|addSeparator
argument_list|()
expr_stmt|;
name|fitToWindowAct
operator|=
name|viewMenu
operator|->
name|addAction
argument_list|(
name|tr
argument_list|(
literal|"&Fit to Window"
argument_list|)
argument_list|,
name|this
argument_list|,
operator|&
name|ImageViewer
operator|::
name|fitToWindow
argument_list|)
expr_stmt|;
name|fitToWindowAct
operator|->
name|setEnabled
argument_list|(
literal|false
argument_list|)
expr_stmt|;
name|fitToWindowAct
operator|->
name|setCheckable
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|fitToWindowAct
operator|->
name|setShortcut
argument_list|(
name|tr
argument_list|(
literal|"Ctrl+F"
argument_list|)
argument_list|)
expr_stmt|;
name|QMenu
modifier|*
name|helpMenu
init|=
name|menuBar
argument_list|()
operator|->
name|addMenu
argument_list|(
name|tr
argument_list|(
literal|"&Help"
argument_list|)
argument_list|)
decl_stmt|;
name|helpMenu
operator|->
name|addAction
argument_list|(
name|tr
argument_list|(
literal|"&About"
argument_list|)
argument_list|,
name|this
argument_list|,
operator|&
name|ImageViewer
operator|::
name|about
argument_list|)
expr_stmt|;
name|helpMenu
operator|->
name|addAction
argument_list|(
name|tr
argument_list|(
literal|"About&Qt"
argument_list|)
argument_list|,
operator|&
name|QApplication
operator|::
name|aboutQt
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [18]
end_comment
begin_comment
comment|//! [21]
end_comment
begin_function
DECL|function|updateActions
name|void
name|ImageViewer
operator|::
name|updateActions
parameter_list|()
comment|//! [21] //! [22]
block|{
name|saveAsAct
operator|->
name|setEnabled
argument_list|(
operator|!
name|image
operator|.
name|isNull
argument_list|()
argument_list|)
expr_stmt|;
name|copyAct
operator|->
name|setEnabled
argument_list|(
operator|!
name|image
operator|.
name|isNull
argument_list|()
argument_list|)
expr_stmt|;
name|zoomInAct
operator|->
name|setEnabled
argument_list|(
operator|!
name|fitToWindowAct
operator|->
name|isChecked
argument_list|()
argument_list|)
expr_stmt|;
name|zoomOutAct
operator|->
name|setEnabled
argument_list|(
operator|!
name|fitToWindowAct
operator|->
name|isChecked
argument_list|()
argument_list|)
expr_stmt|;
name|normalSizeAct
operator|->
name|setEnabled
argument_list|(
operator|!
name|fitToWindowAct
operator|->
name|isChecked
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [22]
end_comment
begin_comment
comment|//! [23]
end_comment
begin_function
DECL|function|scaleImage
name|void
name|ImageViewer
operator|::
name|scaleImage
parameter_list|(
name|double
name|factor
parameter_list|)
comment|//! [23] //! [24]
block|{
name|Q_ASSERT
argument_list|(
name|imageLabel
operator|->
name|pixmap
argument_list|()
argument_list|)
expr_stmt|;
name|scaleFactor
operator|*=
name|factor
expr_stmt|;
name|imageLabel
operator|->
name|resize
argument_list|(
name|scaleFactor
operator|*
name|imageLabel
operator|->
name|pixmap
argument_list|()
operator|->
name|size
argument_list|()
argument_list|)
expr_stmt|;
name|adjustScrollBar
argument_list|(
name|scrollArea
operator|->
name|horizontalScrollBar
argument_list|()
argument_list|,
name|factor
argument_list|)
expr_stmt|;
name|adjustScrollBar
argument_list|(
name|scrollArea
operator|->
name|verticalScrollBar
argument_list|()
argument_list|,
name|factor
argument_list|)
expr_stmt|;
name|zoomInAct
operator|->
name|setEnabled
argument_list|(
name|scaleFactor
operator|<
literal|3.0
argument_list|)
expr_stmt|;
name|zoomOutAct
operator|->
name|setEnabled
argument_list|(
name|scaleFactor
operator|>
literal|0.333
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [24]
end_comment
begin_comment
comment|//! [25]
end_comment
begin_function
DECL|function|adjustScrollBar
name|void
name|ImageViewer
operator|::
name|adjustScrollBar
parameter_list|(
name|QScrollBar
modifier|*
name|scrollBar
parameter_list|,
name|double
name|factor
parameter_list|)
comment|//! [25] //! [26]
block|{
name|scrollBar
operator|->
name|setValue
argument_list|(
name|int
argument_list|(
name|factor
operator|*
name|scrollBar
operator|->
name|value
argument_list|()
operator|+
operator|(
operator|(
name|factor
operator|-
literal|1
operator|)
operator|*
name|scrollBar
operator|->
name|pageStep
argument_list|()
operator|/
literal|2
operator|)
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [26]
end_comment
end_unit
