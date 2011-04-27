begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of Nokia Corporation and its Subsidiary(-ies) nor **     the names of its contributors may be used to endorse or promote **     products derived from this software without specific prior written **     permission. ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"mainwindow.h"
end_include
begin_include
include|#
directive|include
file|<QApplication>
end_include
begin_include
include|#
directive|include
file|<QMenuBar>
end_include
begin_include
include|#
directive|include
file|<QGroupBox>
end_include
begin_include
include|#
directive|include
file|<QGridLayout>
end_include
begin_include
include|#
directive|include
file|<QSlider>
end_include
begin_include
include|#
directive|include
file|<QLabel>
end_include
begin_include
include|#
directive|include
file|<QTimer>
end_include
begin_include
include|#
directive|include
file|"glwidget.h"
end_include
begin_constructor
DECL|function|MainWindow
name|MainWindow
operator|::
name|MainWindow
parameter_list|()
block|{
name|GLWidget
modifier|*
name|glwidget
init|=
operator|new
name|GLWidget
argument_list|()
decl_stmt|;
name|QLabel
modifier|*
name|label
init|=
operator|new
name|QLabel
argument_list|(
name|this
argument_list|)
decl_stmt|;
name|QTimer
modifier|*
name|timer
init|=
operator|new
name|QTimer
argument_list|(
name|this
argument_list|)
decl_stmt|;
name|QSlider
modifier|*
name|slider
init|=
operator|new
name|QSlider
argument_list|(
name|this
argument_list|)
decl_stmt|;
name|slider
operator|->
name|setOrientation
argument_list|(
name|Qt
operator|::
name|Horizontal
argument_list|)
expr_stmt|;
name|slider
operator|->
name|setRange
argument_list|(
literal|0
argument_list|,
literal|100
argument_list|)
expr_stmt|;
name|slider
operator|->
name|setSliderPosition
argument_list|(
literal|50
argument_list|)
expr_stmt|;
name|timer
operator|->
name|setInterval
argument_list|(
literal|10
argument_list|)
expr_stmt|;
name|label
operator|->
name|setText
argument_list|(
literal|"A QGlWidget with OpenGl ES"
argument_list|)
expr_stmt|;
name|label
operator|->
name|setAlignment
argument_list|(
name|Qt
operator|::
name|AlignHCenter
argument_list|)
expr_stmt|;
name|QGroupBox
modifier|*
name|groupBox
init|=
operator|new
name|QGroupBox
argument_list|(
name|this
argument_list|)
decl_stmt|;
name|setCentralWidget
argument_list|(
name|groupBox
argument_list|)
expr_stmt|;
name|groupBox
operator|->
name|setTitle
argument_list|(
literal|"OpenGL ES Example"
argument_list|)
expr_stmt|;
name|QGridLayout
modifier|*
name|layout
init|=
operator|new
name|QGridLayout
argument_list|(
name|groupBox
argument_list|)
decl_stmt|;
name|layout
operator|->
name|addWidget
argument_list|(
name|glwidget
argument_list|,
literal|1
argument_list|,
literal|0
argument_list|,
literal|8
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|layout
operator|->
name|addWidget
argument_list|(
name|label
argument_list|,
literal|9
argument_list|,
literal|0
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|layout
operator|->
name|addWidget
argument_list|(
name|slider
argument_list|,
literal|11
argument_list|,
literal|0
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|groupBox
operator|->
name|setLayout
argument_list|(
name|layout
argument_list|)
expr_stmt|;
name|QMenu
modifier|*
name|fileMenu
init|=
operator|new
name|QMenu
argument_list|(
literal|"File"
argument_list|)
decl_stmt|;
name|QMenu
modifier|*
name|helpMenu
init|=
operator|new
name|QMenu
argument_list|(
literal|"Help"
argument_list|)
decl_stmt|;
name|QMenu
modifier|*
name|showMenu
init|=
operator|new
name|QMenu
argument_list|(
literal|"Show"
argument_list|)
decl_stmt|;
name|menuBar
argument_list|()
operator|->
name|addMenu
argument_list|(
name|fileMenu
argument_list|)
expr_stmt|;
name|menuBar
argument_list|()
operator|->
name|addMenu
argument_list|(
name|showMenu
argument_list|)
expr_stmt|;
name|menuBar
argument_list|()
operator|->
name|addMenu
argument_list|(
name|helpMenu
argument_list|)
expr_stmt|;
name|QAction
modifier|*
name|exit
init|=
operator|new
name|QAction
argument_list|(
literal|"Exit"
argument_list|,
name|fileMenu
argument_list|)
decl_stmt|;
name|QAction
modifier|*
name|aboutQt
init|=
operator|new
name|QAction
argument_list|(
literal|"AboutQt"
argument_list|,
name|helpMenu
argument_list|)
decl_stmt|;
name|QAction
modifier|*
name|showLogo
init|=
operator|new
name|QAction
argument_list|(
literal|"Show 3D Logo"
argument_list|,
name|showMenu
argument_list|)
decl_stmt|;
name|QAction
modifier|*
name|showTexture
init|=
operator|new
name|QAction
argument_list|(
literal|"Show 2D Texture"
argument_list|,
name|showMenu
argument_list|)
decl_stmt|;
name|QAction
modifier|*
name|showBubbles
init|=
operator|new
name|QAction
argument_list|(
literal|"Show bubbles"
argument_list|,
name|showMenu
argument_list|)
decl_stmt|;
name|showBubbles
operator|->
name|setCheckable
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|showBubbles
operator|->
name|setChecked
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|fileMenu
operator|->
name|addAction
argument_list|(
name|exit
argument_list|)
expr_stmt|;
name|helpMenu
operator|->
name|addAction
argument_list|(
name|aboutQt
argument_list|)
expr_stmt|;
name|showMenu
operator|->
name|addAction
argument_list|(
name|showLogo
argument_list|)
expr_stmt|;
name|showMenu
operator|->
name|addAction
argument_list|(
name|showTexture
argument_list|)
expr_stmt|;
name|showMenu
operator|->
name|addAction
argument_list|(
name|showBubbles
argument_list|)
expr_stmt|;
name|QObject
operator|::
name|connect
argument_list|(
name|timer
argument_list|,
name|SIGNAL
argument_list|(
name|timeout
argument_list|()
argument_list|)
argument_list|,
name|glwidget
argument_list|,
name|SLOT
argument_list|(
name|updateGL
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|QObject
operator|::
name|connect
argument_list|(
name|exit
argument_list|,
name|SIGNAL
argument_list|(
name|triggered
argument_list|(
name|bool
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|close
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|QObject
operator|::
name|connect
argument_list|(
name|aboutQt
argument_list|,
name|SIGNAL
argument_list|(
name|triggered
argument_list|(
name|bool
argument_list|)
argument_list|)
argument_list|,
name|qApp
argument_list|,
name|SLOT
argument_list|(
name|aboutQt
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|QObject
operator|::
name|connect
argument_list|(
name|showLogo
argument_list|,
name|SIGNAL
argument_list|(
name|triggered
argument_list|(
name|bool
argument_list|)
argument_list|)
argument_list|,
name|glwidget
argument_list|,
name|SLOT
argument_list|(
name|setLogo
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|QObject
operator|::
name|connect
argument_list|(
name|showTexture
argument_list|,
name|SIGNAL
argument_list|(
name|triggered
argument_list|(
name|bool
argument_list|)
argument_list|)
argument_list|,
name|glwidget
argument_list|,
name|SLOT
argument_list|(
name|setTexture
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|QObject
operator|::
name|connect
argument_list|(
name|showBubbles
argument_list|,
name|SIGNAL
argument_list|(
name|triggered
argument_list|(
name|bool
argument_list|)
argument_list|)
argument_list|,
name|glwidget
argument_list|,
name|SLOT
argument_list|(
name|showBubbles
argument_list|(
name|bool
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|QObject
operator|::
name|connect
argument_list|(
name|slider
argument_list|,
name|SIGNAL
argument_list|(
name|valueChanged
argument_list|(
name|int
argument_list|)
argument_list|)
argument_list|,
name|glwidget
argument_list|,
name|SLOT
argument_list|(
name|setScaling
argument_list|(
name|int
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|timer
operator|->
name|start
argument_list|()
expr_stmt|;
block|}
end_constructor
end_unit
