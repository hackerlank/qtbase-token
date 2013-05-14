begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the documentation of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of Digia Plc and its Subsidiary(-ies) nor the names **     of its contributors may be used to endorse or promote products derived **     from this software without specific prior written permission. ** ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtGui>
end_include
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
file|<QPrinter>
end_include
begin_include
include|#
directive|include
file|<QPrintDialog>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_class
DECL|class|Window
class|class
name|Window
super|:
specifier|public
name|QWidget
block|{
name|Q_OBJECT
public|public:
DECL|function|Window
name|Window
parameter_list|()
block|{
name|myWidget
operator|=
operator|new
name|QPushButton
argument_list|(
literal|"Print Me"
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|myWidget
argument_list|,
name|SIGNAL
argument_list|(
name|clicked
argument_list|()
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|print
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|myWidget2
operator|=
operator|new
name|QPushButton
argument_list|(
literal|"Print Document"
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|myWidget2
argument_list|,
name|SIGNAL
argument_list|(
name|clicked
argument_list|()
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|printFile
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|editor
operator|=
operator|new
name|QTextEdit
argument_list|(
name|this
argument_list|)
expr_stmt|;
name|QVBoxLayout
modifier|*
name|layout
init|=
operator|new
name|QVBoxLayout
decl_stmt|;
name|layout
operator|->
name|addWidget
argument_list|(
name|myWidget
argument_list|)
expr_stmt|;
name|layout
operator|->
name|addWidget
argument_list|(
name|myWidget2
argument_list|)
expr_stmt|;
name|layout
operator|->
name|addWidget
argument_list|(
name|editor
argument_list|)
expr_stmt|;
name|setLayout
argument_list|(
name|layout
argument_list|)
expr_stmt|;
block|}
private|private
name|slots
private|:
DECL|function|print
name|void
name|print
parameter_list|()
block|{
if|#
directive|if
operator|!
name|defined
argument_list|(
name|QT_NO_PRINTER
argument_list|)
name|QPrinter
name|printer
argument_list|(
name|QPrinter
operator|::
name|HighResolution
argument_list|)
decl_stmt|;
name|printer
operator|.
name|setOutputFileName
argument_list|(
literal|"test.pdf"
argument_list|)
expr_stmt|;
comment|//! [0]
name|QPainter
name|painter
decl_stmt|;
name|painter
operator|.
name|begin
argument_list|(
operator|&
name|printer
argument_list|)
expr_stmt|;
name|double
name|xscale
init|=
name|printer
operator|.
name|pageRect
argument_list|()
operator|.
name|width
argument_list|()
operator|/
name|double
argument_list|(
name|myWidget
operator|->
name|width
argument_list|()
argument_list|)
decl_stmt|;
name|double
name|yscale
init|=
name|printer
operator|.
name|pageRect
argument_list|()
operator|.
name|height
argument_list|()
operator|/
name|double
argument_list|(
name|myWidget
operator|->
name|height
argument_list|()
argument_list|)
decl_stmt|;
name|double
name|scale
init|=
name|qMin
argument_list|(
name|xscale
argument_list|,
name|yscale
argument_list|)
decl_stmt|;
name|painter
operator|.
name|translate
argument_list|(
name|printer
operator|.
name|paperRect
argument_list|()
operator|.
name|x
argument_list|()
operator|+
name|printer
operator|.
name|pageRect
argument_list|()
operator|.
name|width
argument_list|()
operator|/
literal|2
argument_list|,
name|printer
operator|.
name|paperRect
argument_list|()
operator|.
name|y
argument_list|()
operator|+
name|printer
operator|.
name|pageRect
argument_list|()
operator|.
name|height
argument_list|()
operator|/
literal|2
argument_list|)
expr_stmt|;
name|painter
operator|.
name|scale
argument_list|(
name|scale
argument_list|,
name|scale
argument_list|)
expr_stmt|;
name|painter
operator|.
name|translate
argument_list|(
operator|-
name|width
argument_list|()
operator|/
literal|2
argument_list|,
operator|-
name|height
argument_list|()
operator|/
literal|2
argument_list|)
expr_stmt|;
name|myWidget
operator|->
name|render
argument_list|(
operator|&
name|painter
argument_list|)
expr_stmt|;
comment|//! [0]
endif|#
directive|endif
block|}
DECL|function|printFile
name|void
name|printFile
parameter_list|()
block|{
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
comment|//! [1]
name|QPrinter
name|printer
decl_stmt|;
name|QPrintDialog
name|dialog
argument_list|(
operator|&
name|printer
argument_list|,
name|this
argument_list|)
decl_stmt|;
name|dialog
operator|.
name|setWindowTitle
argument_list|(
name|tr
argument_list|(
literal|"Print Document"
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|editor
operator|->
name|textCursor
argument_list|()
operator|.
name|hasSelection
argument_list|()
condition|)
name|dialog
operator|.
name|addEnabledOption
argument_list|(
name|QAbstractPrintDialog
operator|::
name|PrintSelection
argument_list|)
expr_stmt|;
if|if
condition|(
name|dialog
operator|.
name|exec
argument_list|()
operator|!=
name|QDialog
operator|::
name|Accepted
condition|)
block|{
return|return;
block|}
comment|//! [1]
name|editor
operator|->
name|print
argument_list|(
operator|&
name|printer
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
private|private:
DECL|member|myWidget
name|QPushButton
modifier|*
name|myWidget
decl_stmt|;
DECL|member|myWidget2
name|QPushButton
modifier|*
name|myWidget2
decl_stmt|;
DECL|member|editor
name|QTextEdit
modifier|*
name|editor
decl_stmt|;
block|}
class|;
end_class
begin_include
include|#
directive|include
file|"main.moc"
end_include
begin_function
DECL|function|main
name|int
name|main
parameter_list|(
name|int
name|argv
parameter_list|,
name|char
modifier|*
modifier|*
name|args
parameter_list|)
block|{
name|QApplication
name|app
argument_list|(
name|argv
argument_list|,
name|args
argument_list|)
decl_stmt|;
name|Window
name|window
decl_stmt|;
name|window
operator|.
name|show
argument_list|()
expr_stmt|;
return|return
name|app
operator|.
name|exec
argument_list|()
return|;
block|}
end_function
end_unit
