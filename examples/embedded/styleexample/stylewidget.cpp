begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the demonstration applications of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QApplication>
end_include
begin_include
include|#
directive|include
file|<QString>
end_include
begin_include
include|#
directive|include
file|<QFile>
end_include
begin_include
include|#
directive|include
file|"stylewidget.h"
end_include
begin_constructor
DECL|function|StyleWidget
name|StyleWidget
operator|::
name|StyleWidget
parameter_list|(
name|QWidget
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QFrame
argument_list|(
name|parent
argument_list|)
block|{
name|m_ui
operator|.
name|setupUi
argument_list|(
name|this
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_function
DECL|function|on_close_clicked
name|void
name|StyleWidget
operator|::
name|on_close_clicked
parameter_list|()
block|{
name|close
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|on_blueStyle_clicked
name|void
name|StyleWidget
operator|::
name|on_blueStyle_clicked
parameter_list|()
block|{
name|QFile
name|styleSheet
argument_list|(
literal|":/files/blue.qss"
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|styleSheet
operator|.
name|open
argument_list|(
name|QIODevice
operator|::
name|ReadOnly
argument_list|)
condition|)
block|{
name|qWarning
argument_list|(
literal|"Unable to open :/files/blue.qss"
argument_list|)
expr_stmt|;
return|return;
block|}
name|qApp
operator|->
name|setStyleSheet
argument_list|(
name|styleSheet
operator|.
name|readAll
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|on_khakiStyle_clicked
name|void
name|StyleWidget
operator|::
name|on_khakiStyle_clicked
parameter_list|()
block|{
name|QFile
name|styleSheet
argument_list|(
literal|":/files/khaki.qss"
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|styleSheet
operator|.
name|open
argument_list|(
name|QIODevice
operator|::
name|ReadOnly
argument_list|)
condition|)
block|{
name|qWarning
argument_list|(
literal|"Unable to open :/files/khaki.qss"
argument_list|)
expr_stmt|;
return|return;
block|}
name|qApp
operator|->
name|setStyleSheet
argument_list|(
name|styleSheet
operator|.
name|readAll
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|on_noStyle_clicked
name|void
name|StyleWidget
operator|::
name|on_noStyle_clicked
parameter_list|()
block|{
name|QFile
name|styleSheet
argument_list|(
literal|":/files/nostyle.qss"
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|styleSheet
operator|.
name|open
argument_list|(
name|QIODevice
operator|::
name|ReadOnly
argument_list|)
condition|)
block|{
name|qWarning
argument_list|(
literal|"Unable to open :/files/nostyle.qss"
argument_list|)
expr_stmt|;
return|return;
block|}
name|qApp
operator|->
name|setStyleSheet
argument_list|(
name|styleSheet
operator|.
name|readAll
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|on_transparentStyle_clicked
name|void
name|StyleWidget
operator|::
name|on_transparentStyle_clicked
parameter_list|()
block|{
name|QFile
name|styleSheet
argument_list|(
literal|":/files/transparent.qss"
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|styleSheet
operator|.
name|open
argument_list|(
name|QIODevice
operator|::
name|ReadOnly
argument_list|)
condition|)
block|{
name|qWarning
argument_list|(
literal|"Unable to open :/files/transparent.qss"
argument_list|)
expr_stmt|;
return|return;
block|}
name|qApp
operator|->
name|setStyleSheet
argument_list|(
name|styleSheet
operator|.
name|readAll
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
end_unit
