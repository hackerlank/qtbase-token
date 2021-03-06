begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the demonstration applications of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** BSD License Usage ** Alternatively, you may use this file under the terms of the BSD license ** as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of The Qt Company Ltd nor the names of its **     contributors may be used to endorse or promote products derived **     from this software without specific prior written permission. ** ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"toolbar.h"
end_include
begin_include
include|#
directive|include
file|<QMainWindow>
end_include
begin_include
include|#
directive|include
file|<QMenu>
end_include
begin_include
include|#
directive|include
file|<QPainter>
end_include
begin_include
include|#
directive|include
file|<QPainterPath>
end_include
begin_include
include|#
directive|include
file|<QSpinBox>
end_include
begin_include
include|#
directive|include
file|<QLabel>
end_include
begin_include
include|#
directive|include
file|<QToolTip>
end_include
begin_include
include|#
directive|include
file|<stdlib.h>
end_include
begin_function
DECL|function|genIcon
specifier|static
name|QPixmap
name|genIcon
parameter_list|(
specifier|const
name|QSize
modifier|&
name|iconSize
parameter_list|,
specifier|const
name|QString
modifier|&
parameter_list|,
specifier|const
name|QColor
modifier|&
name|color
parameter_list|)
block|{
name|int
name|w
init|=
name|iconSize
operator|.
name|width
argument_list|()
decl_stmt|;
name|int
name|h
init|=
name|iconSize
operator|.
name|height
argument_list|()
decl_stmt|;
name|QImage
name|image
argument_list|(
name|w
argument_list|,
name|h
argument_list|,
name|QImage
operator|::
name|Format_ARGB32_Premultiplied
argument_list|)
decl_stmt|;
name|image
operator|.
name|fill
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|QPainter
name|p
argument_list|(
operator|&
name|image
argument_list|)
decl_stmt|;
specifier|extern
name|void
name|render_qt_text
argument_list|(
name|QPainter
operator|*
argument_list|,
name|int
argument_list|,
name|int
argument_list|,
specifier|const
name|QColor
operator|&
argument_list|)
decl_stmt|;
name|render_qt_text
argument_list|(
operator|&
name|p
argument_list|,
name|w
argument_list|,
name|h
argument_list|,
name|color
argument_list|)
expr_stmt|;
return|return
name|QPixmap
operator|::
name|fromImage
argument_list|(
name|image
argument_list|,
name|Qt
operator|::
name|DiffuseDither
operator||
name|Qt
operator|::
name|DiffuseAlphaDither
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|genIcon
specifier|static
name|QPixmap
name|genIcon
parameter_list|(
specifier|const
name|QSize
modifier|&
name|iconSize
parameter_list|,
name|int
name|number
parameter_list|,
specifier|const
name|QColor
modifier|&
name|color
parameter_list|)
block|{
return|return
name|genIcon
argument_list|(
name|iconSize
argument_list|,
name|QString
operator|::
name|number
argument_list|(
name|number
argument_list|)
argument_list|,
name|color
argument_list|)
return|;
block|}
end_function
begin_constructor
DECL|function|ToolBar
name|ToolBar
operator|::
name|ToolBar
parameter_list|(
specifier|const
name|QString
modifier|&
name|title
parameter_list|,
name|QWidget
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QToolBar
argument_list|(
name|parent
argument_list|)
member_init_list|,
name|spinbox
argument_list|(
name|Q_NULLPTR
argument_list|)
member_init_list|,
name|spinboxAction
argument_list|(
name|Q_NULLPTR
argument_list|)
block|{
name|setWindowTitle
argument_list|(
name|title
argument_list|)
expr_stmt|;
name|setObjectName
argument_list|(
name|title
argument_list|)
expr_stmt|;
name|setIconSize
argument_list|(
name|QSize
argument_list|(
literal|32
argument_list|,
literal|32
argument_list|)
argument_list|)
expr_stmt|;
name|menu
operator|=
operator|new
name|QMenu
argument_list|(
literal|"One"
argument_list|,
name|this
argument_list|)
expr_stmt|;
name|menu
operator|->
name|setIcon
argument_list|(
name|genIcon
argument_list|(
name|iconSize
argument_list|()
argument_list|,
literal|1
argument_list|,
name|Qt
operator|::
name|black
argument_list|)
argument_list|)
expr_stmt|;
name|menu
operator|->
name|addAction
argument_list|(
name|genIcon
argument_list|(
name|iconSize
argument_list|()
argument_list|,
literal|"A"
argument_list|,
name|Qt
operator|::
name|blue
argument_list|)
argument_list|,
literal|"A"
argument_list|)
expr_stmt|;
name|menu
operator|->
name|addAction
argument_list|(
name|genIcon
argument_list|(
name|iconSize
argument_list|()
argument_list|,
literal|"B"
argument_list|,
name|Qt
operator|::
name|blue
argument_list|)
argument_list|,
literal|"B"
argument_list|)
expr_stmt|;
name|menu
operator|->
name|addAction
argument_list|(
name|genIcon
argument_list|(
name|iconSize
argument_list|()
argument_list|,
literal|"C"
argument_list|,
name|Qt
operator|::
name|blue
argument_list|)
argument_list|,
literal|"C"
argument_list|)
expr_stmt|;
name|addAction
argument_list|(
name|menu
operator|->
name|menuAction
argument_list|()
argument_list|)
expr_stmt|;
name|QAction
modifier|*
name|two
init|=
name|addAction
argument_list|(
name|genIcon
argument_list|(
name|iconSize
argument_list|()
argument_list|,
literal|2
argument_list|,
name|Qt
operator|::
name|white
argument_list|)
argument_list|,
literal|"Two"
argument_list|)
decl_stmt|;
name|QFont
name|boldFont
decl_stmt|;
name|boldFont
operator|.
name|setBold
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|two
operator|->
name|setFont
argument_list|(
name|boldFont
argument_list|)
expr_stmt|;
name|addAction
argument_list|(
name|genIcon
argument_list|(
name|iconSize
argument_list|()
argument_list|,
literal|3
argument_list|,
name|Qt
operator|::
name|red
argument_list|)
argument_list|,
literal|"Three"
argument_list|)
expr_stmt|;
name|addAction
argument_list|(
name|genIcon
argument_list|(
name|iconSize
argument_list|()
argument_list|,
literal|4
argument_list|,
name|Qt
operator|::
name|green
argument_list|)
argument_list|,
literal|"Four"
argument_list|)
expr_stmt|;
name|addAction
argument_list|(
name|genIcon
argument_list|(
name|iconSize
argument_list|()
argument_list|,
literal|5
argument_list|,
name|Qt
operator|::
name|blue
argument_list|)
argument_list|,
literal|"Five"
argument_list|)
expr_stmt|;
name|addAction
argument_list|(
name|genIcon
argument_list|(
name|iconSize
argument_list|()
argument_list|,
literal|6
argument_list|,
name|Qt
operator|::
name|yellow
argument_list|)
argument_list|,
literal|"Six"
argument_list|)
expr_stmt|;
name|orderAction
operator|=
operator|new
name|QAction
argument_list|(
name|this
argument_list|)
expr_stmt|;
name|orderAction
operator|->
name|setText
argument_list|(
name|tr
argument_list|(
literal|"Order Items in Tool Bar"
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|orderAction
argument_list|,
operator|&
name|QAction
operator|::
name|triggered
argument_list|,
name|this
argument_list|,
operator|&
name|ToolBar
operator|::
name|order
argument_list|)
expr_stmt|;
name|randomizeAction
operator|=
operator|new
name|QAction
argument_list|(
name|this
argument_list|)
expr_stmt|;
name|randomizeAction
operator|->
name|setText
argument_list|(
name|tr
argument_list|(
literal|"Randomize Items in Tool Bar"
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|randomizeAction
argument_list|,
operator|&
name|QAction
operator|::
name|triggered
argument_list|,
name|this
argument_list|,
operator|&
name|ToolBar
operator|::
name|randomize
argument_list|)
expr_stmt|;
name|addSpinBoxAction
operator|=
operator|new
name|QAction
argument_list|(
name|this
argument_list|)
expr_stmt|;
name|addSpinBoxAction
operator|->
name|setText
argument_list|(
name|tr
argument_list|(
literal|"Add Spin Box"
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|addSpinBoxAction
argument_list|,
operator|&
name|QAction
operator|::
name|triggered
argument_list|,
name|this
argument_list|,
operator|&
name|ToolBar
operator|::
name|addSpinBox
argument_list|)
expr_stmt|;
name|removeSpinBoxAction
operator|=
operator|new
name|QAction
argument_list|(
name|this
argument_list|)
expr_stmt|;
name|removeSpinBoxAction
operator|->
name|setText
argument_list|(
name|tr
argument_list|(
literal|"Remove Spin Box"
argument_list|)
argument_list|)
expr_stmt|;
name|removeSpinBoxAction
operator|->
name|setEnabled
argument_list|(
literal|false
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|removeSpinBoxAction
argument_list|,
operator|&
name|QAction
operator|::
name|triggered
argument_list|,
name|this
argument_list|,
operator|&
name|ToolBar
operator|::
name|removeSpinBox
argument_list|)
expr_stmt|;
name|movableAction
operator|=
operator|new
name|QAction
argument_list|(
name|tr
argument_list|(
literal|"Movable"
argument_list|)
argument_list|,
name|this
argument_list|)
expr_stmt|;
name|movableAction
operator|->
name|setCheckable
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|movableAction
argument_list|,
operator|&
name|QAction
operator|::
name|triggered
argument_list|,
name|this
argument_list|,
operator|&
name|ToolBar
operator|::
name|changeMovable
argument_list|)
expr_stmt|;
name|allowedAreasActions
operator|=
operator|new
name|QActionGroup
argument_list|(
name|this
argument_list|)
expr_stmt|;
name|allowedAreasActions
operator|->
name|setExclusive
argument_list|(
literal|false
argument_list|)
expr_stmt|;
name|allowLeftAction
operator|=
operator|new
name|QAction
argument_list|(
name|tr
argument_list|(
literal|"Allow on Left"
argument_list|)
argument_list|,
name|this
argument_list|)
expr_stmt|;
name|allowLeftAction
operator|->
name|setCheckable
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|allowLeftAction
argument_list|,
operator|&
name|QAction
operator|::
name|triggered
argument_list|,
name|this
argument_list|,
operator|&
name|ToolBar
operator|::
name|allowLeft
argument_list|)
expr_stmt|;
name|allowRightAction
operator|=
operator|new
name|QAction
argument_list|(
name|tr
argument_list|(
literal|"Allow on Right"
argument_list|)
argument_list|,
name|this
argument_list|)
expr_stmt|;
name|allowRightAction
operator|->
name|setCheckable
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|allowRightAction
argument_list|,
operator|&
name|QAction
operator|::
name|triggered
argument_list|,
name|this
argument_list|,
operator|&
name|ToolBar
operator|::
name|allowRight
argument_list|)
expr_stmt|;
name|allowTopAction
operator|=
operator|new
name|QAction
argument_list|(
name|tr
argument_list|(
literal|"Allow on Top"
argument_list|)
argument_list|,
name|this
argument_list|)
expr_stmt|;
name|allowTopAction
operator|->
name|setCheckable
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|allowTopAction
argument_list|,
operator|&
name|QAction
operator|::
name|triggered
argument_list|,
name|this
argument_list|,
operator|&
name|ToolBar
operator|::
name|allowTop
argument_list|)
expr_stmt|;
name|allowBottomAction
operator|=
operator|new
name|QAction
argument_list|(
name|tr
argument_list|(
literal|"Allow on Bottom"
argument_list|)
argument_list|,
name|this
argument_list|)
expr_stmt|;
name|allowBottomAction
operator|->
name|setCheckable
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|allowBottomAction
argument_list|,
operator|&
name|QAction
operator|::
name|triggered
argument_list|,
name|this
argument_list|,
operator|&
name|ToolBar
operator|::
name|allowBottom
argument_list|)
expr_stmt|;
name|allowedAreasActions
operator|->
name|addAction
argument_list|(
name|allowLeftAction
argument_list|)
expr_stmt|;
name|allowedAreasActions
operator|->
name|addAction
argument_list|(
name|allowRightAction
argument_list|)
expr_stmt|;
name|allowedAreasActions
operator|->
name|addAction
argument_list|(
name|allowTopAction
argument_list|)
expr_stmt|;
name|allowedAreasActions
operator|->
name|addAction
argument_list|(
name|allowBottomAction
argument_list|)
expr_stmt|;
name|areaActions
operator|=
operator|new
name|QActionGroup
argument_list|(
name|this
argument_list|)
expr_stmt|;
name|areaActions
operator|->
name|setExclusive
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|leftAction
operator|=
operator|new
name|QAction
argument_list|(
name|tr
argument_list|(
literal|"Place on Left"
argument_list|)
argument_list|,
name|this
argument_list|)
expr_stmt|;
name|leftAction
operator|->
name|setCheckable
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|leftAction
argument_list|,
operator|&
name|QAction
operator|::
name|triggered
argument_list|,
name|this
argument_list|,
operator|&
name|ToolBar
operator|::
name|placeLeft
argument_list|)
expr_stmt|;
name|rightAction
operator|=
operator|new
name|QAction
argument_list|(
name|tr
argument_list|(
literal|"Place on Right"
argument_list|)
argument_list|,
name|this
argument_list|)
expr_stmt|;
name|rightAction
operator|->
name|setCheckable
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|rightAction
argument_list|,
operator|&
name|QAction
operator|::
name|triggered
argument_list|,
name|this
argument_list|,
operator|&
name|ToolBar
operator|::
name|placeRight
argument_list|)
expr_stmt|;
name|topAction
operator|=
operator|new
name|QAction
argument_list|(
name|tr
argument_list|(
literal|"Place on Top"
argument_list|)
argument_list|,
name|this
argument_list|)
expr_stmt|;
name|topAction
operator|->
name|setCheckable
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|topAction
argument_list|,
operator|&
name|QAction
operator|::
name|triggered
argument_list|,
name|this
argument_list|,
operator|&
name|ToolBar
operator|::
name|placeTop
argument_list|)
expr_stmt|;
name|bottomAction
operator|=
operator|new
name|QAction
argument_list|(
name|tr
argument_list|(
literal|"Place on Bottom"
argument_list|)
argument_list|,
name|this
argument_list|)
expr_stmt|;
name|bottomAction
operator|->
name|setCheckable
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|bottomAction
argument_list|,
operator|&
name|QAction
operator|::
name|triggered
argument_list|,
name|this
argument_list|,
operator|&
name|ToolBar
operator|::
name|placeBottom
argument_list|)
expr_stmt|;
name|areaActions
operator|->
name|addAction
argument_list|(
name|leftAction
argument_list|)
expr_stmt|;
name|areaActions
operator|->
name|addAction
argument_list|(
name|rightAction
argument_list|)
expr_stmt|;
name|areaActions
operator|->
name|addAction
argument_list|(
name|topAction
argument_list|)
expr_stmt|;
name|areaActions
operator|->
name|addAction
argument_list|(
name|bottomAction
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|movableAction
argument_list|,
operator|&
name|QAction
operator|::
name|triggered
argument_list|,
name|areaActions
argument_list|,
operator|&
name|QActionGroup
operator|::
name|setEnabled
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|movableAction
argument_list|,
operator|&
name|QAction
operator|::
name|triggered
argument_list|,
name|allowedAreasActions
argument_list|,
operator|&
name|QActionGroup
operator|::
name|setEnabled
argument_list|)
expr_stmt|;
name|menu
operator|=
operator|new
name|QMenu
argument_list|(
name|title
argument_list|,
name|this
argument_list|)
expr_stmt|;
name|menu
operator|->
name|addAction
argument_list|(
name|toggleViewAction
argument_list|()
argument_list|)
expr_stmt|;
name|menu
operator|->
name|addSeparator
argument_list|()
expr_stmt|;
name|menu
operator|->
name|addAction
argument_list|(
name|orderAction
argument_list|)
expr_stmt|;
name|menu
operator|->
name|addAction
argument_list|(
name|randomizeAction
argument_list|)
expr_stmt|;
name|menu
operator|->
name|addSeparator
argument_list|()
expr_stmt|;
name|menu
operator|->
name|addAction
argument_list|(
name|addSpinBoxAction
argument_list|)
expr_stmt|;
name|menu
operator|->
name|addAction
argument_list|(
name|removeSpinBoxAction
argument_list|)
expr_stmt|;
name|menu
operator|->
name|addSeparator
argument_list|()
expr_stmt|;
name|menu
operator|->
name|addAction
argument_list|(
name|movableAction
argument_list|)
expr_stmt|;
name|menu
operator|->
name|addSeparator
argument_list|()
expr_stmt|;
name|menu
operator|->
name|addActions
argument_list|(
name|allowedAreasActions
operator|->
name|actions
argument_list|()
argument_list|)
expr_stmt|;
name|menu
operator|->
name|addSeparator
argument_list|()
expr_stmt|;
name|menu
operator|->
name|addActions
argument_list|(
name|areaActions
operator|->
name|actions
argument_list|()
argument_list|)
expr_stmt|;
name|menu
operator|->
name|addSeparator
argument_list|()
expr_stmt|;
name|menu
operator|->
name|addAction
argument_list|(
name|tr
argument_list|(
literal|"Insert break"
argument_list|)
argument_list|,
name|this
argument_list|,
operator|&
name|ToolBar
operator|::
name|insertToolBarBreak
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|menu
argument_list|,
operator|&
name|QMenu
operator|::
name|aboutToShow
argument_list|,
name|this
argument_list|,
operator|&
name|ToolBar
operator|::
name|updateMenu
argument_list|)
expr_stmt|;
name|randomize
argument_list|()
expr_stmt|;
block|}
end_constructor
begin_function
DECL|function|updateMenu
name|void
name|ToolBar
operator|::
name|updateMenu
parameter_list|()
block|{
name|QMainWindow
modifier|*
name|mainWindow
init|=
name|qobject_cast
argument_list|<
name|QMainWindow
operator|*
argument_list|>
argument_list|(
name|parentWidget
argument_list|()
argument_list|)
decl_stmt|;
name|Q_ASSERT
argument_list|(
name|mainWindow
operator|!=
literal|0
argument_list|)
expr_stmt|;
specifier|const
name|Qt
operator|::
name|ToolBarArea
name|area
init|=
name|mainWindow
operator|->
name|toolBarArea
argument_list|(
name|this
argument_list|)
decl_stmt|;
specifier|const
name|Qt
operator|::
name|ToolBarAreas
name|areas
init|=
name|allowedAreas
argument_list|()
decl_stmt|;
name|movableAction
operator|->
name|setChecked
argument_list|(
name|isMovable
argument_list|()
argument_list|)
expr_stmt|;
name|allowLeftAction
operator|->
name|setChecked
argument_list|(
name|isAreaAllowed
argument_list|(
name|Qt
operator|::
name|LeftToolBarArea
argument_list|)
argument_list|)
expr_stmt|;
name|allowRightAction
operator|->
name|setChecked
argument_list|(
name|isAreaAllowed
argument_list|(
name|Qt
operator|::
name|RightToolBarArea
argument_list|)
argument_list|)
expr_stmt|;
name|allowTopAction
operator|->
name|setChecked
argument_list|(
name|isAreaAllowed
argument_list|(
name|Qt
operator|::
name|TopToolBarArea
argument_list|)
argument_list|)
expr_stmt|;
name|allowBottomAction
operator|->
name|setChecked
argument_list|(
name|isAreaAllowed
argument_list|(
name|Qt
operator|::
name|BottomToolBarArea
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|allowedAreasActions
operator|->
name|isEnabled
argument_list|()
condition|)
block|{
name|allowLeftAction
operator|->
name|setEnabled
argument_list|(
name|area
operator|!=
name|Qt
operator|::
name|LeftToolBarArea
argument_list|)
expr_stmt|;
name|allowRightAction
operator|->
name|setEnabled
argument_list|(
name|area
operator|!=
name|Qt
operator|::
name|RightToolBarArea
argument_list|)
expr_stmt|;
name|allowTopAction
operator|->
name|setEnabled
argument_list|(
name|area
operator|!=
name|Qt
operator|::
name|TopToolBarArea
argument_list|)
expr_stmt|;
name|allowBottomAction
operator|->
name|setEnabled
argument_list|(
name|area
operator|!=
name|Qt
operator|::
name|BottomToolBarArea
argument_list|)
expr_stmt|;
block|}
name|leftAction
operator|->
name|setChecked
argument_list|(
name|area
operator|==
name|Qt
operator|::
name|LeftToolBarArea
argument_list|)
expr_stmt|;
name|rightAction
operator|->
name|setChecked
argument_list|(
name|area
operator|==
name|Qt
operator|::
name|RightToolBarArea
argument_list|)
expr_stmt|;
name|topAction
operator|->
name|setChecked
argument_list|(
name|area
operator|==
name|Qt
operator|::
name|TopToolBarArea
argument_list|)
expr_stmt|;
name|bottomAction
operator|->
name|setChecked
argument_list|(
name|area
operator|==
name|Qt
operator|::
name|BottomToolBarArea
argument_list|)
expr_stmt|;
if|if
condition|(
name|areaActions
operator|->
name|isEnabled
argument_list|()
condition|)
block|{
name|leftAction
operator|->
name|setEnabled
argument_list|(
name|areas
operator|&
name|Qt
operator|::
name|LeftToolBarArea
argument_list|)
expr_stmt|;
name|rightAction
operator|->
name|setEnabled
argument_list|(
name|areas
operator|&
name|Qt
operator|::
name|RightToolBarArea
argument_list|)
expr_stmt|;
name|topAction
operator|->
name|setEnabled
argument_list|(
name|areas
operator|&
name|Qt
operator|::
name|TopToolBarArea
argument_list|)
expr_stmt|;
name|bottomAction
operator|->
name|setEnabled
argument_list|(
name|areas
operator|&
name|Qt
operator|::
name|BottomToolBarArea
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|order
name|void
name|ToolBar
operator|::
name|order
parameter_list|()
block|{
name|QList
argument_list|<
name|QAction
modifier|*
argument_list|>
name|ordered
decl_stmt|;
name|QList
argument_list|<
name|QAction
modifier|*
argument_list|>
name|actions1
init|=
name|actions
argument_list|()
decl_stmt|;
foreach|foreach
control|(
name|QAction
modifier|*
name|action
decl|,
name|findChildren
argument_list|<
name|QAction
operator|*
argument_list|>
argument_list|()
control|)
block|{
if|if
condition|(
operator|!
name|actions1
operator|.
name|contains
argument_list|(
name|action
argument_list|)
condition|)
continue|continue;
name|actions1
operator|.
name|removeAll
argument_list|(
name|action
argument_list|)
expr_stmt|;
name|ordered
operator|.
name|append
argument_list|(
name|action
argument_list|)
expr_stmt|;
block|}
name|clear
argument_list|()
expr_stmt|;
name|addActions
argument_list|(
name|ordered
argument_list|)
expr_stmt|;
name|orderAction
operator|->
name|setEnabled
argument_list|(
literal|false
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|randomize
name|void
name|ToolBar
operator|::
name|randomize
parameter_list|()
block|{
name|QList
argument_list|<
name|QAction
modifier|*
argument_list|>
name|randomized
decl_stmt|;
name|QList
argument_list|<
name|QAction
modifier|*
argument_list|>
name|actions
init|=
name|this
operator|->
name|actions
argument_list|()
decl_stmt|;
while|while
condition|(
operator|!
name|actions
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|QAction
modifier|*
name|action
init|=
name|actions
operator|.
name|takeAt
argument_list|(
name|rand
argument_list|()
operator|%
name|actions
operator|.
name|size
argument_list|()
argument_list|)
decl_stmt|;
name|randomized
operator|.
name|append
argument_list|(
name|action
argument_list|)
expr_stmt|;
block|}
name|clear
argument_list|()
expr_stmt|;
name|addActions
argument_list|(
name|randomized
argument_list|)
expr_stmt|;
name|orderAction
operator|->
name|setEnabled
argument_list|(
literal|true
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|addSpinBox
name|void
name|ToolBar
operator|::
name|addSpinBox
parameter_list|()
block|{
if|if
condition|(
operator|!
name|spinbox
condition|)
name|spinbox
operator|=
operator|new
name|QSpinBox
argument_list|(
name|this
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|spinboxAction
condition|)
name|spinboxAction
operator|=
name|addWidget
argument_list|(
name|spinbox
argument_list|)
expr_stmt|;
else|else
name|addAction
argument_list|(
name|spinboxAction
argument_list|)
expr_stmt|;
name|addSpinBoxAction
operator|->
name|setEnabled
argument_list|(
literal|false
argument_list|)
expr_stmt|;
name|removeSpinBoxAction
operator|->
name|setEnabled
argument_list|(
literal|true
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|removeSpinBox
name|void
name|ToolBar
operator|::
name|removeSpinBox
parameter_list|()
block|{
if|if
condition|(
name|spinboxAction
condition|)
name|removeAction
argument_list|(
name|spinboxAction
argument_list|)
expr_stmt|;
name|addSpinBoxAction
operator|->
name|setEnabled
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|removeSpinBoxAction
operator|->
name|setEnabled
argument_list|(
literal|false
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|allow
name|void
name|ToolBar
operator|::
name|allow
parameter_list|(
name|Qt
operator|::
name|ToolBarArea
name|area
parameter_list|,
name|bool
name|a
parameter_list|)
block|{
name|Qt
operator|::
name|ToolBarAreas
name|areas
init|=
name|allowedAreas
argument_list|()
decl_stmt|;
name|areas
operator|=
name|a
condition|?
name|areas
operator||
name|area
else|:
name|areas
operator|&
operator|~
name|area
expr_stmt|;
name|setAllowedAreas
argument_list|(
name|areas
argument_list|)
expr_stmt|;
if|if
condition|(
name|areaActions
operator|->
name|isEnabled
argument_list|()
condition|)
block|{
name|leftAction
operator|->
name|setEnabled
argument_list|(
name|areas
operator|&
name|Qt
operator|::
name|LeftToolBarArea
argument_list|)
expr_stmt|;
name|rightAction
operator|->
name|setEnabled
argument_list|(
name|areas
operator|&
name|Qt
operator|::
name|RightToolBarArea
argument_list|)
expr_stmt|;
name|topAction
operator|->
name|setEnabled
argument_list|(
name|areas
operator|&
name|Qt
operator|::
name|TopToolBarArea
argument_list|)
expr_stmt|;
name|bottomAction
operator|->
name|setEnabled
argument_list|(
name|areas
operator|&
name|Qt
operator|::
name|BottomToolBarArea
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|place
name|void
name|ToolBar
operator|::
name|place
parameter_list|(
name|Qt
operator|::
name|ToolBarArea
name|area
parameter_list|,
name|bool
name|p
parameter_list|)
block|{
if|if
condition|(
operator|!
name|p
condition|)
return|return;
name|QMainWindow
modifier|*
name|mainWindow
init|=
name|qobject_cast
argument_list|<
name|QMainWindow
operator|*
argument_list|>
argument_list|(
name|parentWidget
argument_list|()
argument_list|)
decl_stmt|;
name|Q_ASSERT
argument_list|(
name|mainWindow
operator|!=
literal|0
argument_list|)
expr_stmt|;
name|mainWindow
operator|->
name|addToolBar
argument_list|(
name|area
argument_list|,
name|this
argument_list|)
expr_stmt|;
if|if
condition|(
name|allowedAreasActions
operator|->
name|isEnabled
argument_list|()
condition|)
block|{
name|allowLeftAction
operator|->
name|setEnabled
argument_list|(
name|area
operator|!=
name|Qt
operator|::
name|LeftToolBarArea
argument_list|)
expr_stmt|;
name|allowRightAction
operator|->
name|setEnabled
argument_list|(
name|area
operator|!=
name|Qt
operator|::
name|RightToolBarArea
argument_list|)
expr_stmt|;
name|allowTopAction
operator|->
name|setEnabled
argument_list|(
name|area
operator|!=
name|Qt
operator|::
name|TopToolBarArea
argument_list|)
expr_stmt|;
name|allowBottomAction
operator|->
name|setEnabled
argument_list|(
name|area
operator|!=
name|Qt
operator|::
name|BottomToolBarArea
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|changeMovable
name|void
name|ToolBar
operator|::
name|changeMovable
parameter_list|(
name|bool
name|movable
parameter_list|)
block|{
name|setMovable
argument_list|(
name|movable
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|allowLeft
name|void
name|ToolBar
operator|::
name|allowLeft
parameter_list|(
name|bool
name|a
parameter_list|)
block|{
name|allow
argument_list|(
name|Qt
operator|::
name|LeftToolBarArea
argument_list|,
name|a
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|allowRight
name|void
name|ToolBar
operator|::
name|allowRight
parameter_list|(
name|bool
name|a
parameter_list|)
block|{
name|allow
argument_list|(
name|Qt
operator|::
name|RightToolBarArea
argument_list|,
name|a
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|allowTop
name|void
name|ToolBar
operator|::
name|allowTop
parameter_list|(
name|bool
name|a
parameter_list|)
block|{
name|allow
argument_list|(
name|Qt
operator|::
name|TopToolBarArea
argument_list|,
name|a
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|allowBottom
name|void
name|ToolBar
operator|::
name|allowBottom
parameter_list|(
name|bool
name|a
parameter_list|)
block|{
name|allow
argument_list|(
name|Qt
operator|::
name|BottomToolBarArea
argument_list|,
name|a
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|placeLeft
name|void
name|ToolBar
operator|::
name|placeLeft
parameter_list|(
name|bool
name|p
parameter_list|)
block|{
name|place
argument_list|(
name|Qt
operator|::
name|LeftToolBarArea
argument_list|,
name|p
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|placeRight
name|void
name|ToolBar
operator|::
name|placeRight
parameter_list|(
name|bool
name|p
parameter_list|)
block|{
name|place
argument_list|(
name|Qt
operator|::
name|RightToolBarArea
argument_list|,
name|p
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|placeTop
name|void
name|ToolBar
operator|::
name|placeTop
parameter_list|(
name|bool
name|p
parameter_list|)
block|{
name|place
argument_list|(
name|Qt
operator|::
name|TopToolBarArea
argument_list|,
name|p
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|placeBottom
name|void
name|ToolBar
operator|::
name|placeBottom
parameter_list|(
name|bool
name|p
parameter_list|)
block|{
name|place
argument_list|(
name|Qt
operator|::
name|BottomToolBarArea
argument_list|,
name|p
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|insertToolBarBreak
name|void
name|ToolBar
operator|::
name|insertToolBarBreak
parameter_list|()
block|{
name|QMainWindow
modifier|*
name|mainWindow
init|=
name|qobject_cast
argument_list|<
name|QMainWindow
operator|*
argument_list|>
argument_list|(
name|parentWidget
argument_list|()
argument_list|)
decl_stmt|;
name|Q_ASSERT
argument_list|(
name|mainWindow
operator|!=
literal|0
argument_list|)
expr_stmt|;
name|mainWindow
operator|->
name|insertToolBarBreak
argument_list|(
name|this
argument_list|)
expr_stmt|;
block|}
end_function
end_unit
