begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** BSD License Usage ** Alternatively, you may use this file under the terms of the BSD license ** as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of The Qt Company Ltd nor the names of its **     contributors may be used to endorse or promote products derived **     from this software without specific prior written permission. ** ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"interfaces.h"
end_include
begin_include
include|#
directive|include
file|"plugindialog.h"
end_include
begin_include
include|#
directive|include
file|<QPluginLoader>
end_include
begin_include
include|#
directive|include
file|<QStringList>
end_include
begin_include
include|#
directive|include
file|<QDir>
end_include
begin_include
include|#
directive|include
file|<QLabel>
end_include
begin_include
include|#
directive|include
file|<QGridLayout>
end_include
begin_include
include|#
directive|include
file|<QPushButton>
end_include
begin_include
include|#
directive|include
file|<QTreeWidget>
end_include
begin_include
include|#
directive|include
file|<QTreeWidgetItem>
end_include
begin_include
include|#
directive|include
file|<QHeaderView>
end_include
begin_constructor
DECL|function|PluginDialog
name|PluginDialog
operator|::
name|PluginDialog
parameter_list|(
specifier|const
name|QString
modifier|&
name|path
parameter_list|,
specifier|const
name|QStringList
modifier|&
name|fileNames
parameter_list|,
name|QWidget
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QDialog
argument_list|(
name|parent
argument_list|)
member_init_list|,
name|label
argument_list|(
operator|new
name|QLabel
argument_list|)
member_init_list|,
name|treeWidget
argument_list|(
operator|new
name|QTreeWidget
argument_list|)
member_init_list|,
name|okButton
argument_list|(
operator|new
name|QPushButton
argument_list|(
name|tr
argument_list|(
literal|"OK"
argument_list|)
argument_list|)
argument_list|)
block|{
name|treeWidget
operator|->
name|setAlternatingRowColors
argument_list|(
literal|false
argument_list|)
expr_stmt|;
name|treeWidget
operator|->
name|setSelectionMode
argument_list|(
name|QAbstractItemView
operator|::
name|NoSelection
argument_list|)
expr_stmt|;
name|treeWidget
operator|->
name|setColumnCount
argument_list|(
literal|1
argument_list|)
expr_stmt|;
name|treeWidget
operator|->
name|header
argument_list|()
operator|->
name|hide
argument_list|()
expr_stmt|;
name|okButton
operator|->
name|setDefault
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|okButton
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
name|close
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|QGridLayout
modifier|*
name|mainLayout
init|=
operator|new
name|QGridLayout
decl_stmt|;
name|mainLayout
operator|->
name|setColumnStretch
argument_list|(
literal|0
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|mainLayout
operator|->
name|setColumnStretch
argument_list|(
literal|2
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|mainLayout
operator|->
name|addWidget
argument_list|(
name|label
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|1
argument_list|,
literal|3
argument_list|)
expr_stmt|;
name|mainLayout
operator|->
name|addWidget
argument_list|(
name|treeWidget
argument_list|,
literal|1
argument_list|,
literal|0
argument_list|,
literal|1
argument_list|,
literal|3
argument_list|)
expr_stmt|;
name|mainLayout
operator|->
name|addWidget
argument_list|(
name|okButton
argument_list|,
literal|2
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|setLayout
argument_list|(
name|mainLayout
argument_list|)
expr_stmt|;
name|interfaceIcon
operator|.
name|addPixmap
argument_list|(
name|style
argument_list|()
operator|->
name|standardPixmap
argument_list|(
name|QStyle
operator|::
name|SP_DirOpenIcon
argument_list|)
argument_list|,
name|QIcon
operator|::
name|Normal
argument_list|,
name|QIcon
operator|::
name|On
argument_list|)
expr_stmt|;
name|interfaceIcon
operator|.
name|addPixmap
argument_list|(
name|style
argument_list|()
operator|->
name|standardPixmap
argument_list|(
name|QStyle
operator|::
name|SP_DirClosedIcon
argument_list|)
argument_list|,
name|QIcon
operator|::
name|Normal
argument_list|,
name|QIcon
operator|::
name|Off
argument_list|)
expr_stmt|;
name|featureIcon
operator|.
name|addPixmap
argument_list|(
name|style
argument_list|()
operator|->
name|standardPixmap
argument_list|(
name|QStyle
operator|::
name|SP_FileIcon
argument_list|)
argument_list|)
expr_stmt|;
name|setWindowTitle
argument_list|(
name|tr
argument_list|(
literal|"Plugin Information"
argument_list|)
argument_list|)
expr_stmt|;
name|findPlugins
argument_list|(
name|path
argument_list|,
name|fileNames
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_comment
comment|//! [0]
end_comment
begin_function
DECL|function|findPlugins
name|void
name|PluginDialog
operator|::
name|findPlugins
parameter_list|(
specifier|const
name|QString
modifier|&
name|path
parameter_list|,
specifier|const
name|QStringList
modifier|&
name|fileNames
parameter_list|)
block|{
name|label
operator|->
name|setText
argument_list|(
name|tr
argument_list|(
literal|"Plug& Paint found the following plugins\n"
literal|"(looked in %1):"
argument_list|)
operator|.
name|arg
argument_list|(
name|QDir
operator|::
name|toNativeSeparators
argument_list|(
name|path
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
specifier|const
name|QDir
name|dir
argument_list|(
name|path
argument_list|)
decl_stmt|;
foreach|foreach
control|(
name|QObject
modifier|*
name|plugin
decl|,
name|QPluginLoader
operator|::
name|staticInstances
argument_list|()
control|)
name|populateTreeWidget
argument_list|(
name|plugin
argument_list|,
name|tr
argument_list|(
literal|"%1 (Static Plugin)"
argument_list|)
operator|.
name|arg
argument_list|(
name|plugin
operator|->
name|metaObject
argument_list|()
operator|->
name|className
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
foreach|foreach
control|(
name|QString
name|fileName
decl|,
name|fileNames
control|)
block|{
name|QPluginLoader
name|loader
argument_list|(
name|dir
operator|.
name|absoluteFilePath
argument_list|(
name|fileName
argument_list|)
argument_list|)
decl_stmt|;
name|QObject
modifier|*
name|plugin
init|=
name|loader
operator|.
name|instance
argument_list|()
decl_stmt|;
if|if
condition|(
name|plugin
condition|)
name|populateTreeWidget
argument_list|(
name|plugin
argument_list|,
name|fileName
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_comment
comment|//! [0]
end_comment
begin_comment
comment|//! [1]
end_comment
begin_function
DECL|function|populateTreeWidget
name|void
name|PluginDialog
operator|::
name|populateTreeWidget
parameter_list|(
name|QObject
modifier|*
name|plugin
parameter_list|,
specifier|const
name|QString
modifier|&
name|text
parameter_list|)
block|{
name|QTreeWidgetItem
modifier|*
name|pluginItem
init|=
operator|new
name|QTreeWidgetItem
argument_list|(
name|treeWidget
argument_list|)
decl_stmt|;
name|pluginItem
operator|->
name|setText
argument_list|(
literal|0
argument_list|,
name|text
argument_list|)
expr_stmt|;
name|treeWidget
operator|->
name|setItemExpanded
argument_list|(
name|pluginItem
argument_list|,
literal|true
argument_list|)
expr_stmt|;
name|QFont
name|boldFont
init|=
name|pluginItem
operator|->
name|font
argument_list|(
literal|0
argument_list|)
decl_stmt|;
name|boldFont
operator|.
name|setBold
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|pluginItem
operator|->
name|setFont
argument_list|(
literal|0
argument_list|,
name|boldFont
argument_list|)
expr_stmt|;
if|if
condition|(
name|plugin
condition|)
block|{
name|BrushInterface
modifier|*
name|iBrush
init|=
name|qobject_cast
argument_list|<
name|BrushInterface
operator|*
argument_list|>
argument_list|(
name|plugin
argument_list|)
decl_stmt|;
if|if
condition|(
name|iBrush
condition|)
name|addItems
argument_list|(
name|pluginItem
argument_list|,
literal|"BrushInterface"
argument_list|,
name|iBrush
operator|->
name|brushes
argument_list|()
argument_list|)
expr_stmt|;
name|ShapeInterface
modifier|*
name|iShape
init|=
name|qobject_cast
argument_list|<
name|ShapeInterface
operator|*
argument_list|>
argument_list|(
name|plugin
argument_list|)
decl_stmt|;
if|if
condition|(
name|iShape
condition|)
name|addItems
argument_list|(
name|pluginItem
argument_list|,
literal|"ShapeInterface"
argument_list|,
name|iShape
operator|->
name|shapes
argument_list|()
argument_list|)
expr_stmt|;
name|FilterInterface
modifier|*
name|iFilter
init|=
name|qobject_cast
argument_list|<
name|FilterInterface
operator|*
argument_list|>
argument_list|(
name|plugin
argument_list|)
decl_stmt|;
if|if
condition|(
name|iFilter
condition|)
name|addItems
argument_list|(
name|pluginItem
argument_list|,
literal|"FilterInterface"
argument_list|,
name|iFilter
operator|->
name|filters
argument_list|()
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_comment
comment|//! [1]
end_comment
begin_function
DECL|function|addItems
name|void
name|PluginDialog
operator|::
name|addItems
parameter_list|(
name|QTreeWidgetItem
modifier|*
name|pluginItem
parameter_list|,
specifier|const
name|char
modifier|*
name|interfaceName
parameter_list|,
specifier|const
name|QStringList
modifier|&
name|features
parameter_list|)
block|{
name|QTreeWidgetItem
modifier|*
name|interfaceItem
init|=
operator|new
name|QTreeWidgetItem
argument_list|(
name|pluginItem
argument_list|)
decl_stmt|;
name|interfaceItem
operator|->
name|setText
argument_list|(
literal|0
argument_list|,
name|interfaceName
argument_list|)
expr_stmt|;
name|interfaceItem
operator|->
name|setIcon
argument_list|(
literal|0
argument_list|,
name|interfaceIcon
argument_list|)
expr_stmt|;
foreach|foreach
control|(
name|QString
name|feature
decl|,
name|features
control|)
block|{
if|if
condition|(
name|feature
operator|.
name|endsWith
argument_list|(
literal|"..."
argument_list|)
condition|)
name|feature
operator|.
name|chop
argument_list|(
literal|3
argument_list|)
expr_stmt|;
name|QTreeWidgetItem
modifier|*
name|featureItem
init|=
operator|new
name|QTreeWidgetItem
argument_list|(
name|interfaceItem
argument_list|)
decl_stmt|;
name|featureItem
operator|->
name|setText
argument_list|(
literal|0
argument_list|,
name|feature
argument_list|)
expr_stmt|;
name|featureItem
operator|->
name|setIcon
argument_list|(
literal|0
argument_list|,
name|featureIcon
argument_list|)
expr_stmt|;
block|}
block|}
end_function
end_unit
