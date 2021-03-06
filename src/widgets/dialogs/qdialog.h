begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the QtWidgets module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QDIALOG_H
end_ifndef
begin_define
DECL|macro|QDIALOG_H
define|#
directive|define
name|QDIALOG_H
end_define
begin_include
include|#
directive|include
file|<QtWidgets/qwidget.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QPushButton
name|class
name|QPushButton
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QDialogPrivate
name|class
name|QDialogPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_WIDGETS_EXPORT
name|QDialog
range|:
name|public
name|QWidget
block|{
name|Q_OBJECT
name|friend
name|class
name|QPushButton
block|;
name|Q_PROPERTY
argument_list|(
argument|bool sizeGripEnabled READ isSizeGripEnabled WRITE setSizeGripEnabled
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|bool modal READ isModal WRITE setModal
argument_list|)
name|public
operator|:
name|explicit
name|QDialog
argument_list|(
argument|QWidget *parent = Q_NULLPTR
argument_list|,
argument|Qt::WindowFlags f = Qt::WindowFlags()
argument_list|)
block|;
operator|~
name|QDialog
argument_list|()
block|;      enum
name|DialogCode
block|{
name|Rejected
block|,
name|Accepted
block|}
block|;
name|int
name|result
argument_list|()
specifier|const
block|;
name|void
name|setVisible
argument_list|(
argument|bool visible
argument_list|)
block|;
name|void
name|setOrientation
argument_list|(
argument|Qt::Orientation orientation
argument_list|)
block|;
name|Qt
operator|::
name|Orientation
name|orientation
argument_list|()
specifier|const
block|;
name|void
name|setExtension
argument_list|(
name|QWidget
operator|*
name|extension
argument_list|)
block|;
name|QWidget
operator|*
name|extension
argument_list|()
specifier|const
block|;
name|QSize
name|sizeHint
argument_list|()
specifier|const
block|;
name|QSize
name|minimumSizeHint
argument_list|()
specifier|const
block|;
name|void
name|setSizeGripEnabled
argument_list|(
name|bool
argument_list|)
block|;
name|bool
name|isSizeGripEnabled
argument_list|()
specifier|const
block|;
name|void
name|setModal
argument_list|(
argument|bool modal
argument_list|)
block|;
name|void
name|setResult
argument_list|(
argument|int r
argument_list|)
block|;
name|Q_SIGNALS
operator|:
name|void
name|finished
argument_list|(
argument|int result
argument_list|)
block|;
name|void
name|accepted
argument_list|()
block|;
name|void
name|rejected
argument_list|()
block|;
name|public
name|Q_SLOTS
operator|:
name|virtual
name|void
name|open
argument_list|()
block|;
name|virtual
name|int
name|exec
argument_list|()
block|;
name|virtual
name|void
name|done
argument_list|(
name|int
argument_list|)
block|;
name|virtual
name|void
name|accept
argument_list|()
block|;
name|virtual
name|void
name|reject
argument_list|()
block|;
name|void
name|showExtension
argument_list|(
name|bool
argument_list|)
block|;
name|protected
operator|:
name|QDialog
argument_list|(
argument|QDialogPrivate&
argument_list|,
argument|QWidget *parent
argument_list|,
argument|Qt::WindowFlags f = Qt::WindowFlags()
argument_list|)
block|;
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_WINCE
argument_list|)
name|bool
name|event
argument_list|(
name|QEvent
operator|*
name|e
argument_list|)
block|;
endif|#
directive|endif
name|void
name|keyPressEvent
argument_list|(
name|QKeyEvent
operator|*
argument_list|)
block|;
name|void
name|closeEvent
argument_list|(
name|QCloseEvent
operator|*
argument_list|)
block|;
name|void
name|showEvent
argument_list|(
name|QShowEvent
operator|*
argument_list|)
block|;
name|void
name|resizeEvent
argument_list|(
name|QResizeEvent
operator|*
argument_list|)
block|;
ifndef|#
directive|ifndef
name|QT_NO_CONTEXTMENU
name|void
name|contextMenuEvent
argument_list|(
name|QContextMenuEvent
operator|*
argument_list|)
block|;
endif|#
directive|endif
name|bool
name|eventFilter
argument_list|(
name|QObject
operator|*
argument_list|,
name|QEvent
operator|*
argument_list|)
block|;
name|void
name|adjustPosition
argument_list|(
name|QWidget
operator|*
argument_list|)
block|;
name|private
operator|:
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QDialog
argument_list|)
name|Q_DISABLE_COPY
argument_list|(
argument|QDialog
argument_list|)
ifdef|#
directive|ifdef
name|Q_OS_WINCE_WM
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_doneAction()
argument_list|)
endif|#
directive|endif
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
comment|// QDIALOG_H
end_comment
end_unit
