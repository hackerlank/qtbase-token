begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of Nokia Corporation and its Subsidiary(-ies) nor **     the names of its contributors may be used to endorse or promote **     products derived from this software without specific prior written **     permission. ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtWidgets>
end_include
begin_include
include|#
directive|include
file|"mdichild.h"
end_include
begin_constructor
DECL|function|MdiChild
name|MdiChild
operator|::
name|MdiChild
parameter_list|()
block|{
name|setAttribute
argument_list|(
name|Qt
operator|::
name|WA_DeleteOnClose
argument_list|)
expr_stmt|;
name|isUntitled
operator|=
literal|true
expr_stmt|;
block|}
end_constructor
begin_function
DECL|function|newFile
name|void
name|MdiChild
operator|::
name|newFile
parameter_list|()
block|{
specifier|static
name|int
name|sequenceNumber
init|=
literal|1
decl_stmt|;
name|isUntitled
operator|=
literal|true
expr_stmt|;
name|curFile
operator|=
name|tr
argument_list|(
literal|"document%1.txt"
argument_list|)
operator|.
name|arg
argument_list|(
name|sequenceNumber
operator|++
argument_list|)
expr_stmt|;
name|setWindowTitle
argument_list|(
name|curFile
operator|+
literal|"[*]"
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|document
argument_list|()
argument_list|,
name|SIGNAL
argument_list|(
name|contentsChanged
argument_list|()
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|documentWasModified
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|loadFile
name|bool
name|MdiChild
operator|::
name|loadFile
parameter_list|(
specifier|const
name|QString
modifier|&
name|fileName
parameter_list|)
block|{
name|QFile
name|file
argument_list|(
name|fileName
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
operator||
name|QFile
operator|::
name|Text
argument_list|)
condition|)
block|{
name|QMessageBox
operator|::
name|warning
argument_list|(
name|this
argument_list|,
name|tr
argument_list|(
literal|"MDI"
argument_list|)
argument_list|,
name|tr
argument_list|(
literal|"Cannot read file %1:\n%2."
argument_list|)
operator|.
name|arg
argument_list|(
name|fileName
argument_list|)
operator|.
name|arg
argument_list|(
name|file
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
name|QTextStream
name|in
argument_list|(
operator|&
name|file
argument_list|)
decl_stmt|;
name|QApplication
operator|::
name|setOverrideCursor
argument_list|(
name|Qt
operator|::
name|WaitCursor
argument_list|)
expr_stmt|;
name|setPlainText
argument_list|(
name|in
operator|.
name|readAll
argument_list|()
argument_list|)
expr_stmt|;
name|QApplication
operator|::
name|restoreOverrideCursor
argument_list|()
expr_stmt|;
name|setCurrentFile
argument_list|(
name|fileName
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|document
argument_list|()
argument_list|,
name|SIGNAL
argument_list|(
name|contentsChanged
argument_list|()
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|documentWasModified
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
return|return
literal|true
return|;
block|}
end_function
begin_function
DECL|function|save
name|bool
name|MdiChild
operator|::
name|save
parameter_list|()
block|{
if|if
condition|(
name|isUntitled
condition|)
block|{
return|return
name|saveAs
argument_list|()
return|;
block|}
else|else
block|{
return|return
name|saveFile
argument_list|(
name|curFile
argument_list|)
return|;
block|}
block|}
end_function
begin_function
DECL|function|saveAs
name|bool
name|MdiChild
operator|::
name|saveAs
parameter_list|()
block|{
name|QString
name|fileName
init|=
name|QFileDialog
operator|::
name|getSaveFileName
argument_list|(
name|this
argument_list|,
name|tr
argument_list|(
literal|"Save As"
argument_list|)
argument_list|,
name|curFile
argument_list|)
decl_stmt|;
if|if
condition|(
name|fileName
operator|.
name|isEmpty
argument_list|()
condition|)
return|return
literal|false
return|;
return|return
name|saveFile
argument_list|(
name|fileName
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|saveFile
name|bool
name|MdiChild
operator|::
name|saveFile
parameter_list|(
specifier|const
name|QString
modifier|&
name|fileName
parameter_list|)
block|{
name|QFile
name|file
argument_list|(
name|fileName
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
name|WriteOnly
operator||
name|QFile
operator|::
name|Text
argument_list|)
condition|)
block|{
name|QMessageBox
operator|::
name|warning
argument_list|(
name|this
argument_list|,
name|tr
argument_list|(
literal|"MDI"
argument_list|)
argument_list|,
name|tr
argument_list|(
literal|"Cannot write file %1:\n%2."
argument_list|)
operator|.
name|arg
argument_list|(
name|fileName
argument_list|)
operator|.
name|arg
argument_list|(
name|file
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
name|QTextStream
name|out
argument_list|(
operator|&
name|file
argument_list|)
decl_stmt|;
name|QApplication
operator|::
name|setOverrideCursor
argument_list|(
name|Qt
operator|::
name|WaitCursor
argument_list|)
expr_stmt|;
name|out
operator|<<
name|toPlainText
argument_list|()
expr_stmt|;
name|QApplication
operator|::
name|restoreOverrideCursor
argument_list|()
expr_stmt|;
name|setCurrentFile
argument_list|(
name|fileName
argument_list|)
expr_stmt|;
return|return
literal|true
return|;
block|}
end_function
begin_function
DECL|function|userFriendlyCurrentFile
name|QString
name|MdiChild
operator|::
name|userFriendlyCurrentFile
parameter_list|()
block|{
return|return
name|strippedName
argument_list|(
name|curFile
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|closeEvent
name|void
name|MdiChild
operator|::
name|closeEvent
parameter_list|(
name|QCloseEvent
modifier|*
name|event
parameter_list|)
block|{
if|if
condition|(
name|maybeSave
argument_list|()
condition|)
block|{
name|event
operator|->
name|accept
argument_list|()
expr_stmt|;
block|}
else|else
block|{
name|event
operator|->
name|ignore
argument_list|()
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|documentWasModified
name|void
name|MdiChild
operator|::
name|documentWasModified
parameter_list|()
block|{
name|setWindowModified
argument_list|(
name|document
argument_list|()
operator|->
name|isModified
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|maybeSave
name|bool
name|MdiChild
operator|::
name|maybeSave
parameter_list|()
block|{
if|if
condition|(
name|document
argument_list|()
operator|->
name|isModified
argument_list|()
condition|)
block|{
name|QMessageBox
operator|::
name|StandardButton
name|ret
decl_stmt|;
name|ret
operator|=
name|QMessageBox
operator|::
name|warning
argument_list|(
name|this
argument_list|,
name|tr
argument_list|(
literal|"MDI"
argument_list|)
argument_list|,
name|tr
argument_list|(
literal|"'%1' has been modified.\n"
literal|"Do you want to save your changes?"
argument_list|)
operator|.
name|arg
argument_list|(
name|userFriendlyCurrentFile
argument_list|()
argument_list|)
argument_list|,
name|QMessageBox
operator|::
name|Save
operator||
name|QMessageBox
operator|::
name|Discard
operator||
name|QMessageBox
operator|::
name|Cancel
argument_list|)
expr_stmt|;
if|if
condition|(
name|ret
operator|==
name|QMessageBox
operator|::
name|Save
condition|)
return|return
name|save
argument_list|()
return|;
elseif|else
if|if
condition|(
name|ret
operator|==
name|QMessageBox
operator|::
name|Cancel
condition|)
return|return
literal|false
return|;
block|}
return|return
literal|true
return|;
block|}
end_function
begin_function
DECL|function|setCurrentFile
name|void
name|MdiChild
operator|::
name|setCurrentFile
parameter_list|(
specifier|const
name|QString
modifier|&
name|fileName
parameter_list|)
block|{
name|curFile
operator|=
name|QFileInfo
argument_list|(
name|fileName
argument_list|)
operator|.
name|canonicalFilePath
argument_list|()
expr_stmt|;
name|isUntitled
operator|=
literal|false
expr_stmt|;
name|document
argument_list|()
operator|->
name|setModified
argument_list|(
literal|false
argument_list|)
expr_stmt|;
name|setWindowModified
argument_list|(
literal|false
argument_list|)
expr_stmt|;
name|setWindowTitle
argument_list|(
name|userFriendlyCurrentFile
argument_list|()
operator|+
literal|"[*]"
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|strippedName
name|QString
name|MdiChild
operator|::
name|strippedName
parameter_list|(
specifier|const
name|QString
modifier|&
name|fullFileName
parameter_list|)
block|{
return|return
name|QFileInfo
argument_list|(
name|fullFileName
argument_list|)
operator|.
name|fileName
argument_list|()
return|;
block|}
end_function
end_unit
