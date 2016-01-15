begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the QtWidgets module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QLINEEDIT_H
end_ifndef
begin_define
DECL|macro|QLINEEDIT_H
define|#
directive|define
name|QLINEEDIT_H
end_define
begin_include
include|#
directive|include
file|<QtWidgets/qframe.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/qtextcursor.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qstring.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qmargins.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
ifndef|#
directive|ifndef
name|QT_NO_LINEEDIT
DECL|variable|QValidator
name|class
name|QValidator
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QMenu
name|class
name|QMenu
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QLineEditPrivate
name|class
name|QLineEditPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QCompleter
name|class
name|QCompleter
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QStyleOptionFrame
name|class
name|QStyleOptionFrame
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QAbstractSpinBox
name|class
name|QAbstractSpinBox
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QDateTimeEdit
name|class
name|QDateTimeEdit
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QIcon
name|class
name|QIcon
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QToolButton
name|class
name|QToolButton
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_WIDGETS_EXPORT
name|QLineEdit
range|:
name|public
name|QWidget
block|{
name|Q_OBJECT
name|Q_PROPERTY
argument_list|(
argument|QString inputMask READ inputMask WRITE setInputMask
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|QString text READ text WRITE setText NOTIFY textChanged USER true
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|int maxLength READ maxLength WRITE setMaxLength
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|bool frame READ hasFrame WRITE setFrame
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|EchoMode echoMode READ echoMode WRITE setEchoMode
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|QString displayText READ displayText
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|int cursorPosition READ cursorPosition WRITE setCursorPosition
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|Qt::Alignment alignment READ alignment WRITE setAlignment
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|bool modified READ isModified WRITE setModified DESIGNABLE false
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|bool hasSelectedText READ hasSelectedText
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|QString selectedText READ selectedText
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|bool dragEnabled READ dragEnabled WRITE setDragEnabled
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|bool readOnly READ isReadOnly WRITE setReadOnly
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|bool undoAvailable READ isUndoAvailable
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|bool redoAvailable READ isRedoAvailable
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|bool acceptableInput READ hasAcceptableInput
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|QString placeholderText READ placeholderText WRITE setPlaceholderText
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|Qt::CursorMoveStyle cursorMoveStyle READ cursorMoveStyle WRITE setCursorMoveStyle
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|bool clearButtonEnabled READ isClearButtonEnabled WRITE setClearButtonEnabled
argument_list|)
name|public
operator|:
expr|enum
name|ActionPosition
block|{
name|LeadingPosition
block|,
name|TrailingPosition
block|}
block|;
name|Q_ENUM
argument_list|(
argument|ActionPosition
argument_list|)
name|explicit
name|QLineEdit
argument_list|(
name|QWidget
operator|*
name|parent
operator|=
name|Q_NULLPTR
argument_list|)
block|;
name|explicit
name|QLineEdit
argument_list|(
specifier|const
name|QString
operator|&
argument_list|,
name|QWidget
operator|*
name|parent
operator|=
name|Q_NULLPTR
argument_list|)
block|;
operator|~
name|QLineEdit
argument_list|()
block|;
name|QString
name|text
argument_list|()
specifier|const
block|;
name|QString
name|displayText
argument_list|()
specifier|const
block|;
name|QString
name|placeholderText
argument_list|()
specifier|const
block|;
name|void
name|setPlaceholderText
argument_list|(
specifier|const
name|QString
operator|&
argument_list|)
block|;
name|int
name|maxLength
argument_list|()
specifier|const
block|;
name|void
name|setMaxLength
argument_list|(
name|int
argument_list|)
block|;
name|void
name|setFrame
argument_list|(
name|bool
argument_list|)
block|;
name|bool
name|hasFrame
argument_list|()
specifier|const
block|;
name|void
name|setClearButtonEnabled
argument_list|(
argument|bool enable
argument_list|)
block|;
name|bool
name|isClearButtonEnabled
argument_list|()
specifier|const
block|;      enum
name|EchoMode
block|{
name|Normal
block|,
name|NoEcho
block|,
name|Password
block|,
name|PasswordEchoOnEdit
block|}
block|;
name|Q_ENUM
argument_list|(
argument|EchoMode
argument_list|)
name|EchoMode
name|echoMode
argument_list|()
specifier|const
block|;
name|void
name|setEchoMode
argument_list|(
name|EchoMode
argument_list|)
block|;
name|bool
name|isReadOnly
argument_list|()
specifier|const
block|;
name|void
name|setReadOnly
argument_list|(
name|bool
argument_list|)
block|;
ifndef|#
directive|ifndef
name|QT_NO_VALIDATOR
name|void
name|setValidator
argument_list|(
specifier|const
name|QValidator
operator|*
argument_list|)
block|;
specifier|const
name|QValidator
operator|*
name|validator
argument_list|()
specifier|const
block|;
endif|#
directive|endif
ifndef|#
directive|ifndef
name|QT_NO_COMPLETER
name|void
name|setCompleter
argument_list|(
name|QCompleter
operator|*
name|completer
argument_list|)
block|;
name|QCompleter
operator|*
name|completer
argument_list|()
specifier|const
block|;
endif|#
directive|endif
name|QSize
name|sizeHint
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|QSize
name|minimumSizeHint
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|int
name|cursorPosition
argument_list|()
specifier|const
block|;
name|void
name|setCursorPosition
argument_list|(
name|int
argument_list|)
block|;
name|int
name|cursorPositionAt
argument_list|(
specifier|const
name|QPoint
operator|&
name|pos
argument_list|)
block|;
name|void
name|setAlignment
argument_list|(
argument|Qt::Alignment flag
argument_list|)
block|;
name|Qt
operator|::
name|Alignment
name|alignment
argument_list|()
specifier|const
block|;
name|void
name|cursorForward
argument_list|(
argument|bool mark
argument_list|,
argument|int steps =
literal|1
argument_list|)
block|;
name|void
name|cursorBackward
argument_list|(
argument|bool mark
argument_list|,
argument|int steps =
literal|1
argument_list|)
block|;
name|void
name|cursorWordForward
argument_list|(
argument|bool mark
argument_list|)
block|;
name|void
name|cursorWordBackward
argument_list|(
argument|bool mark
argument_list|)
block|;
name|void
name|backspace
argument_list|()
block|;
name|void
name|del
argument_list|()
block|;
name|void
name|home
argument_list|(
argument|bool mark
argument_list|)
block|;
name|void
name|end
argument_list|(
argument|bool mark
argument_list|)
block|;
name|bool
name|isModified
argument_list|()
specifier|const
block|;
name|void
name|setModified
argument_list|(
name|bool
argument_list|)
block|;
name|void
name|setSelection
argument_list|(
name|int
argument_list|,
name|int
argument_list|)
block|;
name|bool
name|hasSelectedText
argument_list|()
specifier|const
block|;
name|QString
name|selectedText
argument_list|()
specifier|const
block|;
name|int
name|selectionStart
argument_list|()
specifier|const
block|;
name|bool
name|isUndoAvailable
argument_list|()
specifier|const
block|;
name|bool
name|isRedoAvailable
argument_list|()
specifier|const
block|;
name|void
name|setDragEnabled
argument_list|(
argument|bool b
argument_list|)
block|;
name|bool
name|dragEnabled
argument_list|()
specifier|const
block|;
name|void
name|setCursorMoveStyle
argument_list|(
argument|Qt::CursorMoveStyle style
argument_list|)
block|;
name|Qt
operator|::
name|CursorMoveStyle
name|cursorMoveStyle
argument_list|()
specifier|const
block|;
name|QString
name|inputMask
argument_list|()
specifier|const
block|;
name|void
name|setInputMask
argument_list|(
specifier|const
name|QString
operator|&
name|inputMask
argument_list|)
block|;
name|bool
name|hasAcceptableInput
argument_list|()
specifier|const
block|;
name|void
name|setTextMargins
argument_list|(
argument|int left
argument_list|,
argument|int top
argument_list|,
argument|int right
argument_list|,
argument|int bottom
argument_list|)
block|;
name|void
name|setTextMargins
argument_list|(
specifier|const
name|QMargins
operator|&
name|margins
argument_list|)
block|;
name|void
name|getTextMargins
argument_list|(
argument|int *left
argument_list|,
argument|int *top
argument_list|,
argument|int *right
argument_list|,
argument|int *bottom
argument_list|)
specifier|const
block|;
name|QMargins
name|textMargins
argument_list|()
specifier|const
block|;
name|using
name|QWidget
operator|::
name|addAction
block|;
name|void
name|addAction
argument_list|(
argument|QAction *action
argument_list|,
argument|ActionPosition position
argument_list|)
block|;
name|QAction
operator|*
name|addAction
argument_list|(
argument|const QIcon&icon
argument_list|,
argument|ActionPosition position
argument_list|)
block|;
name|public
name|Q_SLOTS
operator|:
name|void
name|setText
argument_list|(
specifier|const
name|QString
operator|&
argument_list|)
block|;
name|void
name|clear
argument_list|()
block|;
name|void
name|selectAll
argument_list|()
block|;
name|void
name|undo
argument_list|()
block|;
name|void
name|redo
argument_list|()
block|;
ifndef|#
directive|ifndef
name|QT_NO_CLIPBOARD
name|void
name|cut
argument_list|()
block|;
name|void
name|copy
argument_list|()
specifier|const
block|;
name|void
name|paste
argument_list|()
block|;
endif|#
directive|endif
name|public
operator|:
name|void
name|deselect
argument_list|()
block|;
name|void
name|insert
argument_list|(
specifier|const
name|QString
operator|&
argument_list|)
block|;
ifndef|#
directive|ifndef
name|QT_NO_CONTEXTMENU
name|QMenu
operator|*
name|createStandardContextMenu
argument_list|()
block|;
endif|#
directive|endif
name|Q_SIGNALS
operator|:
name|void
name|textChanged
argument_list|(
specifier|const
name|QString
operator|&
argument_list|)
block|;
name|void
name|textEdited
argument_list|(
specifier|const
name|QString
operator|&
argument_list|)
block|;
name|void
name|cursorPositionChanged
argument_list|(
name|int
argument_list|,
name|int
argument_list|)
block|;
name|void
name|returnPressed
argument_list|()
block|;
name|void
name|editingFinished
argument_list|()
block|;
name|void
name|selectionChanged
argument_list|()
block|;
name|protected
operator|:
name|void
name|mousePressEvent
argument_list|(
argument|QMouseEvent *
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|void
name|mouseMoveEvent
argument_list|(
argument|QMouseEvent *
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|void
name|mouseReleaseEvent
argument_list|(
argument|QMouseEvent *
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|void
name|mouseDoubleClickEvent
argument_list|(
argument|QMouseEvent *
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|void
name|keyPressEvent
argument_list|(
argument|QKeyEvent *
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|void
name|focusInEvent
argument_list|(
argument|QFocusEvent *
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|void
name|focusOutEvent
argument_list|(
argument|QFocusEvent *
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|void
name|paintEvent
argument_list|(
argument|QPaintEvent *
argument_list|)
name|Q_DECL_OVERRIDE
block|;
ifndef|#
directive|ifndef
name|QT_NO_DRAGANDDROP
name|void
name|dragEnterEvent
argument_list|(
argument|QDragEnterEvent *
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|void
name|dragMoveEvent
argument_list|(
argument|QDragMoveEvent *e
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|void
name|dragLeaveEvent
argument_list|(
argument|QDragLeaveEvent *e
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|void
name|dropEvent
argument_list|(
argument|QDropEvent *
argument_list|)
name|Q_DECL_OVERRIDE
block|;
endif|#
directive|endif
name|void
name|changeEvent
argument_list|(
argument|QEvent *
argument_list|)
name|Q_DECL_OVERRIDE
block|;
ifndef|#
directive|ifndef
name|QT_NO_CONTEXTMENU
name|void
name|contextMenuEvent
argument_list|(
argument|QContextMenuEvent *
argument_list|)
name|Q_DECL_OVERRIDE
block|;
endif|#
directive|endif
name|void
name|inputMethodEvent
argument_list|(
argument|QInputMethodEvent *
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|void
name|initStyleOption
argument_list|(
argument|QStyleOptionFrame *option
argument_list|)
specifier|const
block|;
name|public
operator|:
name|QVariant
name|inputMethodQuery
argument_list|(
argument|Qt::InputMethodQuery
argument_list|)
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|bool
name|event
argument_list|(
argument|QEvent *
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|protected
operator|:
name|QRect
name|cursorRect
argument_list|()
specifier|const
block|;
name|public
operator|:
name|private
operator|:
name|friend
name|class
name|QAbstractSpinBox
block|;
name|friend
name|class
name|QAccessibleLineEdit
block|;
ifdef|#
directive|ifdef
name|QT_KEYPAD_NAVIGATION
name|friend
name|class
name|QDateTimeEdit
block|;
endif|#
directive|endif
name|Q_DISABLE_COPY
argument_list|(
argument|QLineEdit
argument_list|)
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QLineEdit
argument_list|)
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_handleWindowActivate()
argument_list|)
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_textEdited(const QString&)
argument_list|)
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_cursorPositionChanged(int, int)
argument_list|)
ifndef|#
directive|ifndef
name|QT_NO_COMPLETER
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_completionHighlighted(const QString&)
argument_list|)
endif|#
directive|endif
ifdef|#
directive|ifdef
name|QT_KEYPAD_NAVIGATION
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_editFocusChange(bool)
argument_list|)
endif|#
directive|endif
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_selectionChanged()
argument_list|)
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_updateNeeded(const QRect&)
argument_list|)
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_textChanged(const QString&)
argument_list|)
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_clearButtonClicked()
argument_list|)
block|}
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_LINEEDIT
end_comment
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QLINEEDIT_H
end_comment
end_unit
