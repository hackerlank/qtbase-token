begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtWidgets module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QUNDOSTACK_H
end_ifndef
begin_define
DECL|macro|QUNDOSTACK_H
define|#
directive|define
name|QUNDOSTACK_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qobject.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qstring.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QAction
name|class
name|QAction
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QUndoCommandPrivate
name|class
name|QUndoCommandPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QUndoStackPrivate
name|class
name|QUndoStackPrivate
decl_stmt|;
end_decl_stmt
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_UNDOCOMMAND
end_ifndef
begin_decl_stmt
name|class
name|Q_WIDGETS_EXPORT
name|QUndoCommand
block|{
name|QUndoCommandPrivate
modifier|*
name|d
decl_stmt|;
name|public
label|:
name|explicit
name|QUndoCommand
parameter_list|(
name|QUndoCommand
modifier|*
name|parent
init|=
literal|0
parameter_list|)
function_decl|;
name|explicit
name|QUndoCommand
parameter_list|(
specifier|const
name|QString
modifier|&
name|text
parameter_list|,
name|QUndoCommand
modifier|*
name|parent
init|=
literal|0
parameter_list|)
function_decl|;
name|virtual
operator|~
name|QUndoCommand
argument_list|()
expr_stmt|;
name|virtual
name|void
name|undo
parameter_list|()
function_decl|;
name|virtual
name|void
name|redo
parameter_list|()
function_decl|;
name|QString
name|text
argument_list|()
specifier|const
expr_stmt|;
name|QString
name|actionText
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setText
parameter_list|(
specifier|const
name|QString
modifier|&
name|text
parameter_list|)
function_decl|;
name|virtual
name|int
name|id
argument_list|()
specifier|const
expr_stmt|;
name|virtual
name|bool
name|mergeWith
parameter_list|(
specifier|const
name|QUndoCommand
modifier|*
name|other
parameter_list|)
function_decl|;
name|int
name|childCount
argument_list|()
specifier|const
expr_stmt|;
specifier|const
name|QUndoCommand
modifier|*
name|child
argument_list|(
name|int
name|index
argument_list|)
decl|const
decl_stmt|;
name|private
label|:
name|Q_DISABLE_COPY
argument_list|(
argument|QUndoCommand
argument_list|)
name|friend
name|class
name|QUndoStack
decl_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_UNDOCOMMAND
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_UNDOSTACK
end_ifndef
begin_decl_stmt
name|class
name|Q_WIDGETS_EXPORT
name|QUndoStack
range|:
name|public
name|QObject
block|{
name|Q_OBJECT
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QUndoStack
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|bool active READ isActive WRITE setActive
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|int undoLimit READ undoLimit WRITE setUndoLimit
argument_list|)
name|public
operator|:
name|explicit
name|QUndoStack
argument_list|(
name|QObject
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
operator|~
name|QUndoStack
argument_list|()
block|;
name|void
name|clear
argument_list|()
block|;
name|void
name|push
argument_list|(
name|QUndoCommand
operator|*
name|cmd
argument_list|)
block|;
name|bool
name|canUndo
argument_list|()
specifier|const
block|;
name|bool
name|canRedo
argument_list|()
specifier|const
block|;
name|QString
name|undoText
argument_list|()
specifier|const
block|;
name|QString
name|redoText
argument_list|()
specifier|const
block|;
name|int
name|count
argument_list|()
specifier|const
block|;
name|int
name|index
argument_list|()
specifier|const
block|;
name|QString
name|text
argument_list|(
argument|int idx
argument_list|)
specifier|const
block|;
ifndef|#
directive|ifndef
name|QT_NO_ACTION
name|QAction
operator|*
name|createUndoAction
argument_list|(
argument|QObject *parent
argument_list|,
argument|const QString&prefix = QString()
argument_list|)
specifier|const
block|;
name|QAction
operator|*
name|createRedoAction
argument_list|(
argument|QObject *parent
argument_list|,
argument|const QString&prefix = QString()
argument_list|)
specifier|const
block|;
endif|#
directive|endif
comment|// QT_NO_ACTION
name|bool
name|isActive
argument_list|()
specifier|const
block|;
name|bool
name|isClean
argument_list|()
specifier|const
block|;
name|int
name|cleanIndex
argument_list|()
specifier|const
block|;
name|void
name|beginMacro
argument_list|(
specifier|const
name|QString
operator|&
name|text
argument_list|)
block|;
name|void
name|endMacro
argument_list|()
block|;
name|void
name|setUndoLimit
argument_list|(
argument|int limit
argument_list|)
block|;
name|int
name|undoLimit
argument_list|()
specifier|const
block|;
specifier|const
name|QUndoCommand
operator|*
name|command
argument_list|(
argument|int index
argument_list|)
specifier|const
block|;
name|public
name|Q_SLOTS
operator|:
name|void
name|setClean
argument_list|()
block|;
name|void
name|setIndex
argument_list|(
argument|int idx
argument_list|)
block|;
name|void
name|undo
argument_list|()
block|;
name|void
name|redo
argument_list|()
block|;
name|void
name|setActive
argument_list|(
argument|bool active = true
argument_list|)
block|;
name|Q_SIGNALS
operator|:
name|void
name|indexChanged
argument_list|(
argument|int idx
argument_list|)
block|;
name|void
name|cleanChanged
argument_list|(
argument|bool clean
argument_list|)
block|;
name|void
name|canUndoChanged
argument_list|(
argument|bool canUndo
argument_list|)
block|;
name|void
name|canRedoChanged
argument_list|(
argument|bool canRedo
argument_list|)
block|;
name|void
name|undoTextChanged
argument_list|(
specifier|const
name|QString
operator|&
name|undoText
argument_list|)
block|;
name|void
name|redoTextChanged
argument_list|(
specifier|const
name|QString
operator|&
name|redoText
argument_list|)
block|;
name|private
operator|:
name|Q_DISABLE_COPY
argument_list|(
argument|QUndoStack
argument_list|)
name|friend
name|class
name|QUndoGroup
block|; }
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_UNDOSTACK
end_comment
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QUNDOSTACK_H
end_comment
end_unit
