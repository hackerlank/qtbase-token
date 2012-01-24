begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the documentation of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of Nokia Corporation and its Subsidiary(-ies) nor **     the names of its contributors may be used to endorse or promote **     products derived from this software without specific prior written **     permission. ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtGui>
end_include
begin_decl_stmt
DECL|variable|win
name|QWidget
modifier|*
name|win
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|panel
name|QWidget
modifier|*
name|panel
decl_stmt|;
end_decl_stmt
begin_function
DECL|function|snippet_ctor1
name|void
name|snippet_ctor1
parameter_list|()
block|{
comment|//! [0]
name|QSettings
name|settings
argument_list|(
literal|"MySoft"
argument_list|,
literal|"Star Runner"
argument_list|)
decl_stmt|;
comment|//! [0]
block|}
end_function
begin_function
DECL|function|snippet_ctor2
name|void
name|snippet_ctor2
parameter_list|()
block|{
comment|//! [1]
name|QCoreApplication
operator|::
name|setOrganizationName
argument_list|(
literal|"MySoft"
argument_list|)
expr_stmt|;
comment|//! [1] //! [2]
name|QCoreApplication
operator|::
name|setOrganizationDomain
argument_list|(
literal|"mysoft.com"
argument_list|)
expr_stmt|;
comment|//! [2] //! [3]
name|QCoreApplication
operator|::
name|setApplicationName
argument_list|(
literal|"Star Runner"
argument_list|)
expr_stmt|;
comment|//! [3]
comment|//! [4]
name|QSettings
name|settings
decl_stmt|;
comment|//! [4]
comment|//! [5]
name|settings
operator|.
name|setValue
argument_list|(
literal|"editor/wrapMargin"
argument_list|,
literal|68
argument_list|)
expr_stmt|;
comment|//! [5] //! [6]
name|int
name|margin
init|=
name|settings
operator|.
name|value
argument_list|(
literal|"editor/wrapMargin"
argument_list|)
operator|.
name|toInt
argument_list|()
decl_stmt|;
comment|//! [6]
block|{
comment|//! [7]
name|int
name|margin
init|=
name|settings
operator|.
name|value
argument_list|(
literal|"editor/wrapMargin"
argument_list|,
literal|80
argument_list|)
operator|.
name|toInt
argument_list|()
decl_stmt|;
comment|//! [7]
block|}
comment|//! [8]
name|settings
operator|.
name|setValue
argument_list|(
literal|"mainwindow/size"
argument_list|,
name|win
operator|->
name|size
argument_list|()
argument_list|)
expr_stmt|;
comment|//! [8] //! [9]
name|settings
operator|.
name|setValue
argument_list|(
literal|"mainwindow/fullScreen"
argument_list|,
name|win
operator|->
name|isFullScreen
argument_list|()
argument_list|)
expr_stmt|;
comment|//! [9] //! [10]
name|settings
operator|.
name|setValue
argument_list|(
literal|"outputpanel/visible"
argument_list|,
name|panel
operator|->
name|isVisible
argument_list|()
argument_list|)
expr_stmt|;
comment|//! [10]
comment|//! [11]
name|settings
operator|.
name|beginGroup
argument_list|(
literal|"mainwindow"
argument_list|)
expr_stmt|;
name|settings
operator|.
name|setValue
argument_list|(
literal|"size"
argument_list|,
name|win
operator|->
name|size
argument_list|()
argument_list|)
expr_stmt|;
name|settings
operator|.
name|setValue
argument_list|(
literal|"fullScreen"
argument_list|,
name|win
operator|->
name|isFullScreen
argument_list|()
argument_list|)
expr_stmt|;
name|settings
operator|.
name|endGroup
argument_list|()
expr_stmt|;
comment|//! [11]
comment|//! [12]
name|settings
operator|.
name|beginGroup
argument_list|(
literal|"outputpanel"
argument_list|)
expr_stmt|;
name|settings
operator|.
name|setValue
argument_list|(
literal|"visible"
argument_list|,
name|panel
operator|->
name|isVisible
argument_list|()
argument_list|)
expr_stmt|;
name|settings
operator|.
name|endGroup
argument_list|()
expr_stmt|;
comment|//! [12]
block|}
end_function
begin_function
DECL|function|snippet_locations
name|void
name|snippet_locations
parameter_list|()
block|{
comment|//! [13]
name|QSettings
name|obj1
argument_list|(
literal|"MySoft"
argument_list|,
literal|"Star Runner"
argument_list|)
decl_stmt|;
comment|//! [13] //! [14]
name|QSettings
name|obj2
argument_list|(
literal|"MySoft"
argument_list|)
decl_stmt|;
name|QSettings
name|obj3
argument_list|(
name|QSettings
operator|::
name|SystemScope
argument_list|,
literal|"MySoft"
argument_list|,
literal|"Star Runner"
argument_list|)
decl_stmt|;
name|QSettings
name|obj4
argument_list|(
name|QSettings
operator|::
name|SystemScope
argument_list|,
literal|"MySoft"
argument_list|)
decl_stmt|;
comment|//! [14]
block|{
comment|//! [15]
name|QSettings
name|settings
argument_list|(
name|QSettings
operator|::
name|IniFormat
argument_list|,
name|QSettings
operator|::
name|UserScope
argument_list|,
literal|"MySoft"
argument_list|,
literal|"Star Runner"
argument_list|)
decl_stmt|;
comment|//! [15]
block|}
block|{
name|QSettings
name|settings
argument_list|(
literal|"starrunner.ini"
argument_list|,
name|QSettings
operator|::
name|IniFormat
argument_list|)
decl_stmt|;
block|}
block|{
name|QSettings
name|settings
argument_list|(
literal|"HKEY_CURRENT_USER\\Software\\Microsoft"
argument_list|,
name|QSettings
operator|::
name|NativeFormat
argument_list|)
decl_stmt|;
block|}
block|}
end_function
begin_class
DECL|class|MainWindow
class|class
name|MainWindow
super|:
specifier|public
name|QMainWindow
block|{
public|public:
name|MainWindow
parameter_list|()
constructor_decl|;
name|void
name|writeSettings
parameter_list|()
function_decl|;
name|void
name|readSettings
parameter_list|()
function_decl|;
protected|protected:
name|void
name|closeEvent
parameter_list|(
name|QCloseEvent
modifier|*
name|event
parameter_list|)
function_decl|;
block|}
class|;
end_class
begin_comment
comment|//! [16]
end_comment
begin_function
DECL|function|writeSettings
name|void
name|MainWindow
operator|::
name|writeSettings
parameter_list|()
block|{
name|QSettings
name|settings
argument_list|(
literal|"Moose Soft"
argument_list|,
literal|"Clipper"
argument_list|)
decl_stmt|;
name|settings
operator|.
name|beginGroup
argument_list|(
literal|"MainWindow"
argument_list|)
expr_stmt|;
name|settings
operator|.
name|setValue
argument_list|(
literal|"size"
argument_list|,
name|size
argument_list|()
argument_list|)
expr_stmt|;
name|settings
operator|.
name|setValue
argument_list|(
literal|"pos"
argument_list|,
name|pos
argument_list|()
argument_list|)
expr_stmt|;
name|settings
operator|.
name|endGroup
argument_list|()
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
DECL|function|readSettings
name|void
name|MainWindow
operator|::
name|readSettings
parameter_list|()
block|{
name|QSettings
name|settings
argument_list|(
literal|"Moose Soft"
argument_list|,
literal|"Clipper"
argument_list|)
decl_stmt|;
name|settings
operator|.
name|beginGroup
argument_list|(
literal|"MainWindow"
argument_list|)
expr_stmt|;
name|resize
argument_list|(
name|settings
operator|.
name|value
argument_list|(
literal|"size"
argument_list|,
name|QSize
argument_list|(
literal|400
argument_list|,
literal|400
argument_list|)
argument_list|)
operator|.
name|toSize
argument_list|()
argument_list|)
expr_stmt|;
name|move
argument_list|(
name|settings
operator|.
name|value
argument_list|(
literal|"pos"
argument_list|,
name|QPoint
argument_list|(
literal|200
argument_list|,
literal|200
argument_list|)
argument_list|)
operator|.
name|toPoint
argument_list|()
argument_list|)
expr_stmt|;
name|settings
operator|.
name|endGroup
argument_list|()
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [17]
end_comment
begin_comment
comment|//! [18]
end_comment
begin_constructor
DECL|function|MainWindow
name|MainWindow
operator|::
name|MainWindow
parameter_list|()
block|{
comment|//! [18] //! [19]
name|readSettings
argument_list|()
expr_stmt|;
comment|//! [19] //! [20]
block|}
end_constructor
begin_comment
comment|//! [20]
end_comment
begin_function
DECL|function|userReallyWantsToQuit
name|bool
name|userReallyWantsToQuit
parameter_list|()
block|{
return|return
literal|true
return|;
block|}
end_function
begin_comment
comment|//! [21]
end_comment
begin_function
DECL|function|closeEvent
name|void
name|MainWindow
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
name|userReallyWantsToQuit
argument_list|()
condition|)
block|{
name|writeSettings
argument_list|()
expr_stmt|;
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
begin_comment
comment|//! [21]
end_comment
end_unit
