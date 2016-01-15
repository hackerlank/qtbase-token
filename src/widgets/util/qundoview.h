begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the QtWidgets module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QUNDOVIEW_H
end_ifndef
begin_define
DECL|macro|QUNDOVIEW_H
define|#
directive|define
name|QUNDOVIEW_H
end_define
begin_include
include|#
directive|include
file|<QtWidgets/qlistview.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qstring.h>
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_UNDOVIEW
end_ifndef
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QUndoViewPrivate
name|class
name|QUndoViewPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QUndoStack
name|class
name|QUndoStack
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QUndoGroup
name|class
name|QUndoGroup
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QIcon
name|class
name|QIcon
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_WIDGETS_EXPORT
name|QUndoView
range|:
name|public
name|QListView
block|{
name|Q_OBJECT
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QUndoView
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|QString emptyLabel READ emptyLabel WRITE setEmptyLabel
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|QIcon cleanIcon READ cleanIcon WRITE setCleanIcon
argument_list|)
name|public
operator|:
name|explicit
name|QUndoView
argument_list|(
name|QWidget
operator|*
name|parent
operator|=
name|Q_NULLPTR
argument_list|)
block|;
name|explicit
name|QUndoView
argument_list|(
name|QUndoStack
operator|*
name|stack
argument_list|,
name|QWidget
operator|*
name|parent
operator|=
name|Q_NULLPTR
argument_list|)
block|;
ifndef|#
directive|ifndef
name|QT_NO_UNDOGROUP
name|explicit
name|QUndoView
argument_list|(
name|QUndoGroup
operator|*
name|group
argument_list|,
name|QWidget
operator|*
name|parent
operator|=
name|Q_NULLPTR
argument_list|)
block|;
endif|#
directive|endif
operator|~
name|QUndoView
argument_list|()
block|;
name|QUndoStack
operator|*
name|stack
argument_list|()
specifier|const
block|;
ifndef|#
directive|ifndef
name|QT_NO_UNDOGROUP
name|QUndoGroup
operator|*
name|group
argument_list|()
specifier|const
block|;
endif|#
directive|endif
name|void
name|setEmptyLabel
argument_list|(
specifier|const
name|QString
operator|&
name|label
argument_list|)
block|;
name|QString
name|emptyLabel
argument_list|()
specifier|const
block|;
name|void
name|setCleanIcon
argument_list|(
specifier|const
name|QIcon
operator|&
name|icon
argument_list|)
block|;
name|QIcon
name|cleanIcon
argument_list|()
specifier|const
block|;
name|public
name|Q_SLOTS
operator|:
name|void
name|setStack
argument_list|(
name|QUndoStack
operator|*
name|stack
argument_list|)
block|;
ifndef|#
directive|ifndef
name|QT_NO_UNDOGROUP
name|void
name|setGroup
argument_list|(
name|QUndoGroup
operator|*
name|group
argument_list|)
block|;
endif|#
directive|endif
name|private
operator|:
name|Q_DISABLE_COPY
argument_list|(
argument|QUndoView
argument_list|)
block|}
decl_stmt|;
end_decl_stmt
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_UNDOVIEW
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QUNDOVIEW_H
end_comment
end_unit
