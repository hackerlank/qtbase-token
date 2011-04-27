begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of Nokia Corporation and its Subsidiary(-ies) nor **     the names of its contributors may be used to endorse or promote **     products derived from this software without specific prior written **     permission. ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtGui>
end_include
begin_include
include|#
directive|include
file|"mainwindow.h"
end_include
begin_include
include|#
directive|include
file|"tabletcanvas.h"
end_include
begin_comment
comment|//! [0]
end_comment
begin_constructor
DECL|function|MainWindow
name|MainWindow
operator|::
name|MainWindow
parameter_list|(
name|TabletCanvas
modifier|*
name|canvas
parameter_list|)
block|{
name|myCanvas
operator|=
name|canvas
expr_stmt|;
name|createActions
argument_list|()
expr_stmt|;
name|createMenus
argument_list|()
expr_stmt|;
name|myCanvas
operator|->
name|setColor
argument_list|(
name|Qt
operator|::
name|red
argument_list|)
expr_stmt|;
name|myCanvas
operator|->
name|setLineWidthType
argument_list|(
name|TabletCanvas
operator|::
name|LineWidthPressure
argument_list|)
expr_stmt|;
name|myCanvas
operator|->
name|setAlphaChannelType
argument_list|(
name|TabletCanvas
operator|::
name|NoAlpha
argument_list|)
expr_stmt|;
name|myCanvas
operator|->
name|setColorSaturationType
argument_list|(
name|TabletCanvas
operator|::
name|NoSaturation
argument_list|)
expr_stmt|;
name|setWindowTitle
argument_list|(
name|tr
argument_list|(
literal|"Tablet Example"
argument_list|)
argument_list|)
expr_stmt|;
name|setCentralWidget
argument_list|(
name|myCanvas
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_comment
comment|//! [0]
end_comment
begin_comment
comment|//! [1]
end_comment
begin_function
DECL|function|brushColorAct
name|void
name|MainWindow
operator|::
name|brushColorAct
parameter_list|()
block|{
name|QColor
name|color
init|=
name|QColorDialog
operator|::
name|getColor
argument_list|(
name|myCanvas
operator|->
name|color
argument_list|()
argument_list|)
decl_stmt|;
if|if
condition|(
name|color
operator|.
name|isValid
argument_list|()
condition|)
name|myCanvas
operator|->
name|setColor
argument_list|(
name|color
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [1]
end_comment
begin_comment
comment|//! [2]
end_comment
begin_function
DECL|function|alphaActionTriggered
name|void
name|MainWindow
operator|::
name|alphaActionTriggered
parameter_list|(
name|QAction
modifier|*
name|action
parameter_list|)
block|{
if|if
condition|(
name|action
operator|==
name|alphaChannelPressureAction
condition|)
block|{
name|myCanvas
operator|->
name|setAlphaChannelType
argument_list|(
name|TabletCanvas
operator|::
name|AlphaPressure
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|action
operator|==
name|alphaChannelTiltAction
condition|)
block|{
name|myCanvas
operator|->
name|setAlphaChannelType
argument_list|(
name|TabletCanvas
operator|::
name|AlphaTilt
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|myCanvas
operator|->
name|setAlphaChannelType
argument_list|(
name|TabletCanvas
operator|::
name|NoAlpha
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_comment
comment|//! [2]
end_comment
begin_comment
comment|//! [3]
end_comment
begin_function
DECL|function|lineWidthActionTriggered
name|void
name|MainWindow
operator|::
name|lineWidthActionTriggered
parameter_list|(
name|QAction
modifier|*
name|action
parameter_list|)
block|{
if|if
condition|(
name|action
operator|==
name|lineWidthPressureAction
condition|)
block|{
name|myCanvas
operator|->
name|setLineWidthType
argument_list|(
name|TabletCanvas
operator|::
name|LineWidthPressure
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|action
operator|==
name|lineWidthTiltAction
condition|)
block|{
name|myCanvas
operator|->
name|setLineWidthType
argument_list|(
name|TabletCanvas
operator|::
name|LineWidthTilt
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|myCanvas
operator|->
name|setLineWidthType
argument_list|(
name|TabletCanvas
operator|::
name|NoLineWidth
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_comment
comment|//! [3]
end_comment
begin_comment
comment|//! [4]
end_comment
begin_function
DECL|function|saturationActionTriggered
name|void
name|MainWindow
operator|::
name|saturationActionTriggered
parameter_list|(
name|QAction
modifier|*
name|action
parameter_list|)
block|{
if|if
condition|(
name|action
operator|==
name|colorSaturationVTiltAction
condition|)
block|{
name|myCanvas
operator|->
name|setColorSaturationType
argument_list|(
name|TabletCanvas
operator|::
name|SaturationVTilt
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|action
operator|==
name|colorSaturationHTiltAction
condition|)
block|{
name|myCanvas
operator|->
name|setColorSaturationType
argument_list|(
name|TabletCanvas
operator|::
name|SaturationHTilt
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|action
operator|==
name|colorSaturationPressureAction
condition|)
block|{
name|myCanvas
operator|->
name|setColorSaturationType
argument_list|(
name|TabletCanvas
operator|::
name|SaturationPressure
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|myCanvas
operator|->
name|setColorSaturationType
argument_list|(
name|TabletCanvas
operator|::
name|NoSaturation
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_comment
comment|//! [4]
end_comment
begin_comment
comment|//! [5]
end_comment
begin_function
DECL|function|saveAct
name|void
name|MainWindow
operator|::
name|saveAct
parameter_list|()
block|{
name|QString
name|path
init|=
name|QDir
operator|::
name|currentPath
argument_list|()
operator|+
literal|"/untitled.png"
decl_stmt|;
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
literal|"Save Picture"
argument_list|)
argument_list|,
name|path
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|myCanvas
operator|->
name|saveImage
argument_list|(
name|fileName
argument_list|)
condition|)
name|QMessageBox
operator|::
name|information
argument_list|(
name|this
argument_list|,
literal|"Error Saving Picture"
argument_list|,
literal|"Could not save the image"
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [5]
end_comment
begin_comment
comment|//! [6]
end_comment
begin_function
DECL|function|loadAct
name|void
name|MainWindow
operator|::
name|loadAct
parameter_list|()
block|{
name|QString
name|fileName
init|=
name|QFileDialog
operator|::
name|getOpenFileName
argument_list|(
name|this
argument_list|,
name|tr
argument_list|(
literal|"Open Picture"
argument_list|)
argument_list|,
name|QDir
operator|::
name|currentPath
argument_list|()
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|myCanvas
operator|->
name|loadImage
argument_list|(
name|fileName
argument_list|)
condition|)
name|QMessageBox
operator|::
name|information
argument_list|(
name|this
argument_list|,
literal|"Error Opening Picture"
argument_list|,
literal|"Could not open picture"
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [6]
end_comment
begin_comment
comment|//! [7]
end_comment
begin_function
DECL|function|aboutAct
name|void
name|MainWindow
operator|::
name|aboutAct
parameter_list|()
block|{
name|QMessageBox
operator|::
name|about
argument_list|(
name|this
argument_list|,
name|tr
argument_list|(
literal|"About Tablet Example"
argument_list|)
argument_list|,
name|tr
argument_list|(
literal|"This example shows use of a Wacom tablet in Qt"
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [7]
end_comment
begin_comment
comment|//! [8]
end_comment
begin_function
DECL|function|createActions
name|void
name|MainWindow
operator|::
name|createActions
parameter_list|()
block|{
comment|//! [8]
name|brushColorAction
operator|=
operator|new
name|QAction
argument_list|(
name|tr
argument_list|(
literal|"&Brush Color..."
argument_list|)
argument_list|,
name|this
argument_list|)
expr_stmt|;
name|brushColorAction
operator|->
name|setShortcut
argument_list|(
name|tr
argument_list|(
literal|"Ctrl+C"
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|brushColorAction
argument_list|,
name|SIGNAL
argument_list|(
name|triggered
argument_list|()
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|brushColorAct
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
comment|//! [9]
name|alphaChannelPressureAction
operator|=
operator|new
name|QAction
argument_list|(
name|tr
argument_list|(
literal|"&Pressure"
argument_list|)
argument_list|,
name|this
argument_list|)
expr_stmt|;
name|alphaChannelPressureAction
operator|->
name|setCheckable
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|alphaChannelTiltAction
operator|=
operator|new
name|QAction
argument_list|(
name|tr
argument_list|(
literal|"&Tilt"
argument_list|)
argument_list|,
name|this
argument_list|)
expr_stmt|;
name|alphaChannelTiltAction
operator|->
name|setCheckable
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|noAlphaChannelAction
operator|=
operator|new
name|QAction
argument_list|(
name|tr
argument_list|(
literal|"No Alpha Channel"
argument_list|)
argument_list|,
name|this
argument_list|)
expr_stmt|;
name|noAlphaChannelAction
operator|->
name|setCheckable
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|noAlphaChannelAction
operator|->
name|setChecked
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|alphaChannelGroup
operator|=
operator|new
name|QActionGroup
argument_list|(
name|this
argument_list|)
expr_stmt|;
name|alphaChannelGroup
operator|->
name|addAction
argument_list|(
name|alphaChannelPressureAction
argument_list|)
expr_stmt|;
name|alphaChannelGroup
operator|->
name|addAction
argument_list|(
name|alphaChannelTiltAction
argument_list|)
expr_stmt|;
name|alphaChannelGroup
operator|->
name|addAction
argument_list|(
name|noAlphaChannelAction
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|alphaChannelGroup
argument_list|,
name|SIGNAL
argument_list|(
name|triggered
argument_list|(
name|QAction
operator|*
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|alphaActionTriggered
argument_list|(
name|QAction
operator|*
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
comment|//! [9]
name|colorSaturationVTiltAction
operator|=
operator|new
name|QAction
argument_list|(
name|tr
argument_list|(
literal|"&Vertical Tilt"
argument_list|)
argument_list|,
name|this
argument_list|)
expr_stmt|;
name|colorSaturationVTiltAction
operator|->
name|setCheckable
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|colorSaturationHTiltAction
operator|=
operator|new
name|QAction
argument_list|(
name|tr
argument_list|(
literal|"&Horizontal Tilt"
argument_list|)
argument_list|,
name|this
argument_list|)
expr_stmt|;
name|colorSaturationHTiltAction
operator|->
name|setCheckable
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|colorSaturationPressureAction
operator|=
operator|new
name|QAction
argument_list|(
name|tr
argument_list|(
literal|"&Pressure"
argument_list|)
argument_list|,
name|this
argument_list|)
expr_stmt|;
name|colorSaturationPressureAction
operator|->
name|setCheckable
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|noColorSaturationAction
operator|=
operator|new
name|QAction
argument_list|(
name|tr
argument_list|(
literal|"&No Color Saturation"
argument_list|)
argument_list|,
name|this
argument_list|)
expr_stmt|;
name|noColorSaturationAction
operator|->
name|setCheckable
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|noColorSaturationAction
operator|->
name|setChecked
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|colorSaturationGroup
operator|=
operator|new
name|QActionGroup
argument_list|(
name|this
argument_list|)
expr_stmt|;
name|colorSaturationGroup
operator|->
name|addAction
argument_list|(
name|colorSaturationVTiltAction
argument_list|)
expr_stmt|;
name|colorSaturationGroup
operator|->
name|addAction
argument_list|(
name|colorSaturationHTiltAction
argument_list|)
expr_stmt|;
name|colorSaturationGroup
operator|->
name|addAction
argument_list|(
name|colorSaturationPressureAction
argument_list|)
expr_stmt|;
name|colorSaturationGroup
operator|->
name|addAction
argument_list|(
name|noColorSaturationAction
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|colorSaturationGroup
argument_list|,
name|SIGNAL
argument_list|(
name|triggered
argument_list|(
name|QAction
operator|*
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|saturationActionTriggered
argument_list|(
name|QAction
operator|*
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|lineWidthPressureAction
operator|=
operator|new
name|QAction
argument_list|(
name|tr
argument_list|(
literal|"&Pressure"
argument_list|)
argument_list|,
name|this
argument_list|)
expr_stmt|;
name|lineWidthPressureAction
operator|->
name|setCheckable
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|lineWidthPressureAction
operator|->
name|setChecked
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|lineWidthTiltAction
operator|=
operator|new
name|QAction
argument_list|(
name|tr
argument_list|(
literal|"&Tilt"
argument_list|)
argument_list|,
name|this
argument_list|)
expr_stmt|;
name|lineWidthTiltAction
operator|->
name|setCheckable
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|lineWidthFixedAction
operator|=
operator|new
name|QAction
argument_list|(
name|tr
argument_list|(
literal|"&Fixed"
argument_list|)
argument_list|,
name|this
argument_list|)
expr_stmt|;
name|lineWidthFixedAction
operator|->
name|setCheckable
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|lineWidthGroup
operator|=
operator|new
name|QActionGroup
argument_list|(
name|this
argument_list|)
expr_stmt|;
name|lineWidthGroup
operator|->
name|addAction
argument_list|(
name|lineWidthPressureAction
argument_list|)
expr_stmt|;
name|lineWidthGroup
operator|->
name|addAction
argument_list|(
name|lineWidthTiltAction
argument_list|)
expr_stmt|;
name|lineWidthGroup
operator|->
name|addAction
argument_list|(
name|lineWidthFixedAction
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|lineWidthGroup
argument_list|,
name|SIGNAL
argument_list|(
name|triggered
argument_list|(
name|QAction
operator|*
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|lineWidthActionTriggered
argument_list|(
name|QAction
operator|*
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|exitAction
operator|=
operator|new
name|QAction
argument_list|(
name|tr
argument_list|(
literal|"E&xit"
argument_list|)
argument_list|,
name|this
argument_list|)
expr_stmt|;
name|exitAction
operator|->
name|setShortcuts
argument_list|(
name|QKeySequence
operator|::
name|Quit
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|exitAction
argument_list|,
name|SIGNAL
argument_list|(
name|triggered
argument_list|()
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
name|loadAction
operator|=
operator|new
name|QAction
argument_list|(
name|tr
argument_list|(
literal|"&Open..."
argument_list|)
argument_list|,
name|this
argument_list|)
expr_stmt|;
name|loadAction
operator|->
name|setShortcuts
argument_list|(
name|QKeySequence
operator|::
name|Open
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|loadAction
argument_list|,
name|SIGNAL
argument_list|(
name|triggered
argument_list|()
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|loadAct
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|saveAction
operator|=
operator|new
name|QAction
argument_list|(
name|tr
argument_list|(
literal|"&Save As..."
argument_list|)
argument_list|,
name|this
argument_list|)
expr_stmt|;
name|saveAction
operator|->
name|setShortcuts
argument_list|(
name|QKeySequence
operator|::
name|SaveAs
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|saveAction
argument_list|,
name|SIGNAL
argument_list|(
name|triggered
argument_list|()
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|saveAct
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|aboutAction
operator|=
operator|new
name|QAction
argument_list|(
name|tr
argument_list|(
literal|"A&bout"
argument_list|)
argument_list|,
name|this
argument_list|)
expr_stmt|;
name|aboutAction
operator|->
name|setShortcut
argument_list|(
name|tr
argument_list|(
literal|"Ctrl+B"
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|aboutAction
argument_list|,
name|SIGNAL
argument_list|(
name|triggered
argument_list|()
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|aboutAct
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|aboutQtAction
operator|=
operator|new
name|QAction
argument_list|(
name|tr
argument_list|(
literal|"About&Qt"
argument_list|)
argument_list|,
name|this
argument_list|)
expr_stmt|;
name|aboutQtAction
operator|->
name|setShortcut
argument_list|(
name|tr
argument_list|(
literal|"Ctrl+Q"
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|aboutQtAction
argument_list|,
name|SIGNAL
argument_list|(
name|triggered
argument_list|()
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
comment|//! [10]
block|}
end_function
begin_comment
comment|//! [10]
end_comment
begin_comment
comment|//! [11]
end_comment
begin_function
DECL|function|createMenus
name|void
name|MainWindow
operator|::
name|createMenus
parameter_list|()
block|{
name|fileMenu
operator|=
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
expr_stmt|;
name|fileMenu
operator|->
name|addAction
argument_list|(
name|loadAction
argument_list|)
expr_stmt|;
name|fileMenu
operator|->
name|addAction
argument_list|(
name|saveAction
argument_list|)
expr_stmt|;
name|fileMenu
operator|->
name|addSeparator
argument_list|()
expr_stmt|;
name|fileMenu
operator|->
name|addAction
argument_list|(
name|exitAction
argument_list|)
expr_stmt|;
name|brushMenu
operator|=
name|menuBar
argument_list|()
operator|->
name|addMenu
argument_list|(
name|tr
argument_list|(
literal|"&Brush"
argument_list|)
argument_list|)
expr_stmt|;
name|brushMenu
operator|->
name|addAction
argument_list|(
name|brushColorAction
argument_list|)
expr_stmt|;
name|tabletMenu
operator|=
name|menuBar
argument_list|()
operator|->
name|addMenu
argument_list|(
name|tr
argument_list|(
literal|"&Tablet"
argument_list|)
argument_list|)
expr_stmt|;
name|lineWidthMenu
operator|=
name|tabletMenu
operator|->
name|addMenu
argument_list|(
name|tr
argument_list|(
literal|"&Line Width"
argument_list|)
argument_list|)
expr_stmt|;
name|lineWidthMenu
operator|->
name|addAction
argument_list|(
name|lineWidthPressureAction
argument_list|)
expr_stmt|;
name|lineWidthMenu
operator|->
name|addAction
argument_list|(
name|lineWidthTiltAction
argument_list|)
expr_stmt|;
name|lineWidthMenu
operator|->
name|addAction
argument_list|(
name|lineWidthFixedAction
argument_list|)
expr_stmt|;
name|alphaChannelMenu
operator|=
name|tabletMenu
operator|->
name|addMenu
argument_list|(
name|tr
argument_list|(
literal|"&Alpha Channel"
argument_list|)
argument_list|)
expr_stmt|;
name|alphaChannelMenu
operator|->
name|addAction
argument_list|(
name|alphaChannelPressureAction
argument_list|)
expr_stmt|;
name|alphaChannelMenu
operator|->
name|addAction
argument_list|(
name|alphaChannelTiltAction
argument_list|)
expr_stmt|;
name|alphaChannelMenu
operator|->
name|addAction
argument_list|(
name|noAlphaChannelAction
argument_list|)
expr_stmt|;
name|colorSaturationMenu
operator|=
name|tabletMenu
operator|->
name|addMenu
argument_list|(
name|tr
argument_list|(
literal|"&Color Saturation"
argument_list|)
argument_list|)
expr_stmt|;
name|colorSaturationMenu
operator|->
name|addAction
argument_list|(
name|colorSaturationVTiltAction
argument_list|)
expr_stmt|;
name|colorSaturationMenu
operator|->
name|addAction
argument_list|(
name|colorSaturationHTiltAction
argument_list|)
expr_stmt|;
name|colorSaturationMenu
operator|->
name|addAction
argument_list|(
name|noColorSaturationAction
argument_list|)
expr_stmt|;
name|helpMenu
operator|=
name|menuBar
argument_list|()
operator|->
name|addMenu
argument_list|(
literal|"&Help"
argument_list|)
expr_stmt|;
name|helpMenu
operator|->
name|addAction
argument_list|(
name|aboutAction
argument_list|)
expr_stmt|;
name|helpMenu
operator|->
name|addAction
argument_list|(
name|aboutQtAction
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [11]
end_comment
end_unit
