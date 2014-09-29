begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2014 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia. For licensing terms and ** conditions see http://qt.digia.com/licensing. For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights. These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|INTERACTIVEWIDGET_H
end_ifndef
begin_define
DECL|macro|INTERACTIVEWIDGET_H
define|#
directive|define
name|INTERACTIVEWIDGET_H
end_define
begin_include
include|#
directive|include
file|"widgets.h"
end_include
begin_include
include|#
directive|include
file|"paintcommands.h"
end_include
begin_include
include|#
directive|include
file|<QMainWindow>
end_include
begin_include
include|#
directive|include
file|<private/qmath_p.h>
end_include
begin_macro
DECL|function|QT_FORWARD_DECLARE_CLASS
name|QT_FORWARD_DECLARE_CLASS
argument_list|(
argument|QToolBox
argument_list|)
end_macro
begin_decl_stmt
name|class
name|InteractiveWidget
range|:
name|public
name|QMainWindow
block|{
name|Q_OBJECT
name|public
operator|:
name|InteractiveWidget
argument_list|()
block|;
name|public
name|slots
operator|:
name|void
name|run
argument_list|()
block|;
name|void
name|load
argument_list|()
block|;
name|void
name|load
argument_list|(
specifier|const
name|QString
operator|&
name|fname
argument_list|)
block|;
name|void
name|save
argument_list|()
block|;
name|protected
operator|:
name|bool
name|eventFilter
argument_list|(
name|QObject
operator|*
name|o
argument_list|,
name|QEvent
operator|*
name|e
argument_list|)
block|;
name|protected
name|slots
operator|:
name|void
name|cmdSelected
argument_list|(
name|QListWidgetItem
operator|*
name|item
argument_list|)
block|;
name|void
name|enumSelected
argument_list|(
name|QListWidgetItem
operator|*
name|item
argument_list|)
block|;
name|private
operator|:
name|QToolBox
operator|*
name|m_commandsToolBox
block|;
name|QToolBox
operator|*
name|m_enumsToolBox
block|;
name|OnScreenWidget
operator|<
name|QWidget
operator|>
operator|*
name|m_onScreenWidget
block|;
name|QTextEdit
operator|*
name|ui_textEdit
block|;
name|QString
name|m_filename
block|; }
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
end_unit
