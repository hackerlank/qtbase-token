begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the QtWidgets module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QUNDOGROUP_H
end_ifndef
begin_define
DECL|macro|QUNDOGROUP_H
define|#
directive|define
name|QUNDOGROUP_H
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
DECL|variable|QUndoGroupPrivate
name|class
name|QUndoGroupPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QUndoStack
name|class
name|QUndoStack
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QAction
name|class
name|QAction
decl_stmt|;
end_decl_stmt
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_UNDOGROUP
end_ifndef
begin_decl_stmt
name|class
name|Q_WIDGETS_EXPORT
name|QUndoGroup
range|:
name|public
name|QObject
block|{
name|Q_OBJECT
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QUndoGroup
argument_list|)
name|public
operator|:
name|explicit
name|QUndoGroup
argument_list|(
name|QObject
operator|*
name|parent
operator|=
name|Q_NULLPTR
argument_list|)
block|;
operator|~
name|QUndoGroup
argument_list|()
block|;
name|void
name|addStack
argument_list|(
name|QUndoStack
operator|*
name|stack
argument_list|)
block|;
name|void
name|removeStack
argument_list|(
name|QUndoStack
operator|*
name|stack
argument_list|)
block|;
name|QList
operator|<
name|QUndoStack
operator|*
operator|>
name|stacks
argument_list|()
specifier|const
block|;
name|QUndoStack
operator|*
name|activeStack
argument_list|()
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
name|bool
name|isClean
argument_list|()
specifier|const
block|;
name|public
name|Q_SLOTS
operator|:
name|void
name|undo
argument_list|()
block|;
name|void
name|redo
argument_list|()
block|;
name|void
name|setActiveStack
argument_list|(
name|QUndoStack
operator|*
name|stack
argument_list|)
block|;
name|Q_SIGNALS
operator|:
name|void
name|activeStackChanged
argument_list|(
name|QUndoStack
operator|*
name|stack
argument_list|)
block|;
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
argument|QUndoGroup
argument_list|)
block|}
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_UNDOGROUP
end_comment
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QUNDOGROUP_H
end_comment
end_unit
