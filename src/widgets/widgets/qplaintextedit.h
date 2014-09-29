begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2014 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtWidgets module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia. For licensing terms and ** conditions see http://qt.digia.com/licensing. For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights. These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QPLAINTEXTEDIT_H
end_ifndef
begin_define
DECL|macro|QPLAINTEXTEDIT_H
define|#
directive|define
name|QPLAINTEXTEDIT_H
end_define
begin_include
include|#
directive|include
file|<QtWidgets/qtextedit.h>
end_include
begin_include
include|#
directive|include
file|<QtWidgets/qabstractscrollarea.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/qtextdocument.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/qtextoption.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/qtextcursor.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/qtextformat.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/qabstracttextdocumentlayout.h>
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_TEXTEDIT
end_ifndef
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QStyleSheet
name|class
name|QStyleSheet
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QTextDocument
name|class
name|QTextDocument
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QMenu
name|class
name|QMenu
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QPlainTextEditPrivate
name|class
name|QPlainTextEditPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QMimeData
name|class
name|QMimeData
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QPagedPaintDevice
name|class
name|QPagedPaintDevice
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_WIDGETS_EXPORT
name|QPlainTextEdit
range|:
name|public
name|QAbstractScrollArea
block|{
name|Q_OBJECT
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QPlainTextEdit
argument_list|)
name|Q_ENUMS
argument_list|(
argument|LineWrapMode
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|bool tabChangesFocus READ tabChangesFocus WRITE setTabChangesFocus
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|QString documentTitle READ documentTitle WRITE setDocumentTitle
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|bool undoRedoEnabled READ isUndoRedoEnabled WRITE setUndoRedoEnabled
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|LineWrapMode lineWrapMode READ lineWrapMode WRITE setLineWrapMode
argument_list|)
name|QDOC_PROPERTY
argument_list|(
argument|QTextOption::WrapMode wordWrapMode READ wordWrapMode WRITE setWordWrapMode
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|bool readOnly READ isReadOnly WRITE setReadOnly
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|QString plainText READ toPlainText WRITE setPlainText NOTIFY textChanged USER true
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|bool overwriteMode READ overwriteMode WRITE setOverwriteMode
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|int tabStopWidth READ tabStopWidth WRITE setTabStopWidth
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|int cursorWidth READ cursorWidth WRITE setCursorWidth
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|Qt::TextInteractionFlags textInteractionFlags READ textInteractionFlags WRITE setTextInteractionFlags
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|int blockCount READ blockCount
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|int maximumBlockCount READ maximumBlockCount WRITE setMaximumBlockCount
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|bool backgroundVisible READ backgroundVisible WRITE setBackgroundVisible
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|bool centerOnScroll READ centerOnScroll WRITE setCenterOnScroll
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|QString placeholderText READ placeholderText WRITE setPlaceholderText
argument_list|)
name|public
operator|:
expr|enum
name|LineWrapMode
block|{
name|NoWrap
block|,
name|WidgetWidth
block|}
block|;
name|explicit
name|QPlainTextEdit
argument_list|(
name|QWidget
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
name|explicit
name|QPlainTextEdit
argument_list|(
specifier|const
name|QString
operator|&
name|text
argument_list|,
name|QWidget
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
name|virtual
operator|~
name|QPlainTextEdit
argument_list|()
block|;
name|void
name|setDocument
argument_list|(
name|QTextDocument
operator|*
name|document
argument_list|)
block|;
name|QTextDocument
operator|*
name|document
argument_list|()
specifier|const
block|;
name|void
name|setPlaceholderText
argument_list|(
specifier|const
name|QString
operator|&
name|placeholderText
argument_list|)
block|;
name|QString
name|placeholderText
argument_list|()
specifier|const
block|;
name|void
name|setTextCursor
argument_list|(
specifier|const
name|QTextCursor
operator|&
name|cursor
argument_list|)
block|;
name|QTextCursor
name|textCursor
argument_list|()
specifier|const
block|;
name|bool
name|isReadOnly
argument_list|()
specifier|const
block|;
name|void
name|setReadOnly
argument_list|(
argument|bool ro
argument_list|)
block|;
name|void
name|setTextInteractionFlags
argument_list|(
argument|Qt::TextInteractionFlags flags
argument_list|)
block|;
name|Qt
operator|::
name|TextInteractionFlags
name|textInteractionFlags
argument_list|()
specifier|const
block|;
name|void
name|mergeCurrentCharFormat
argument_list|(
specifier|const
name|QTextCharFormat
operator|&
name|modifier
argument_list|)
block|;
name|void
name|setCurrentCharFormat
argument_list|(
specifier|const
name|QTextCharFormat
operator|&
name|format
argument_list|)
block|;
name|QTextCharFormat
name|currentCharFormat
argument_list|()
specifier|const
block|;
name|bool
name|tabChangesFocus
argument_list|()
specifier|const
block|;
name|void
name|setTabChangesFocus
argument_list|(
argument|bool b
argument_list|)
block|;
specifier|inline
name|void
name|setDocumentTitle
argument_list|(
argument|const QString&title
argument_list|)
block|{
name|document
argument_list|()
operator|->
name|setMetaInformation
argument_list|(
name|QTextDocument
operator|::
name|DocumentTitle
argument_list|,
name|title
argument_list|)
block|; }
specifier|inline
name|QString
name|documentTitle
argument_list|()
specifier|const
block|{
return|return
name|document
argument_list|()
operator|->
name|metaInformation
argument_list|(
name|QTextDocument
operator|::
name|DocumentTitle
argument_list|)
return|;
block|}
specifier|inline
name|bool
name|isUndoRedoEnabled
argument_list|()
specifier|const
block|{
return|return
name|document
argument_list|()
operator|->
name|isUndoRedoEnabled
argument_list|()
return|;
block|}
specifier|inline
name|void
name|setUndoRedoEnabled
argument_list|(
argument|bool enable
argument_list|)
block|{
name|document
argument_list|()
operator|->
name|setUndoRedoEnabled
argument_list|(
name|enable
argument_list|)
block|; }
specifier|inline
name|void
name|setMaximumBlockCount
argument_list|(
argument|int maximum
argument_list|)
block|{
name|document
argument_list|()
operator|->
name|setMaximumBlockCount
argument_list|(
name|maximum
argument_list|)
block|; }
specifier|inline
name|int
name|maximumBlockCount
argument_list|()
specifier|const
block|{
return|return
name|document
argument_list|()
operator|->
name|maximumBlockCount
argument_list|()
return|;
block|}
name|LineWrapMode
name|lineWrapMode
argument_list|()
specifier|const
block|;
name|void
name|setLineWrapMode
argument_list|(
argument|LineWrapMode mode
argument_list|)
block|;
name|QTextOption
operator|::
name|WrapMode
name|wordWrapMode
argument_list|()
specifier|const
block|;
name|void
name|setWordWrapMode
argument_list|(
argument|QTextOption::WrapMode policy
argument_list|)
block|;
name|void
name|setBackgroundVisible
argument_list|(
argument|bool visible
argument_list|)
block|;
name|bool
name|backgroundVisible
argument_list|()
specifier|const
block|;
name|void
name|setCenterOnScroll
argument_list|(
argument|bool enabled
argument_list|)
block|;
name|bool
name|centerOnScroll
argument_list|()
specifier|const
block|;
name|bool
name|find
argument_list|(
argument|const QString&exp
argument_list|,
argument|QTextDocument::FindFlags options =
literal|0
argument_list|)
block|;
ifndef|#
directive|ifndef
name|QT_NO_REGEXP
name|bool
name|find
argument_list|(
argument|const QRegExp&exp
argument_list|,
argument|QTextDocument::FindFlags options =
literal|0
argument_list|)
block|;
endif|#
directive|endif
specifier|inline
name|QString
name|toPlainText
argument_list|()
specifier|const
block|{
return|return
name|document
argument_list|()
operator|->
name|toPlainText
argument_list|()
return|;
block|}
name|void
name|ensureCursorVisible
argument_list|()
block|;
name|virtual
name|QVariant
name|loadResource
argument_list|(
argument|int type
argument_list|,
argument|const QUrl&name
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
name|QTextCursor
name|cursorForPosition
argument_list|(
argument|const QPoint&pos
argument_list|)
specifier|const
block|;
name|QRect
name|cursorRect
argument_list|(
argument|const QTextCursor&cursor
argument_list|)
specifier|const
block|;
name|QRect
name|cursorRect
argument_list|()
specifier|const
block|;
name|QString
name|anchorAt
argument_list|(
argument|const QPoint&pos
argument_list|)
specifier|const
block|;
name|bool
name|overwriteMode
argument_list|()
specifier|const
block|;
name|void
name|setOverwriteMode
argument_list|(
argument|bool overwrite
argument_list|)
block|;
name|int
name|tabStopWidth
argument_list|()
specifier|const
block|;
name|void
name|setTabStopWidth
argument_list|(
argument|int width
argument_list|)
block|;
name|int
name|cursorWidth
argument_list|()
specifier|const
block|;
name|void
name|setCursorWidth
argument_list|(
argument|int width
argument_list|)
block|;
name|void
name|setExtraSelections
argument_list|(
specifier|const
name|QList
operator|<
name|QTextEdit
operator|::
name|ExtraSelection
operator|>
operator|&
name|selections
argument_list|)
block|;
name|QList
operator|<
name|QTextEdit
operator|::
name|ExtraSelection
operator|>
name|extraSelections
argument_list|()
specifier|const
block|;
name|void
name|moveCursor
argument_list|(
argument|QTextCursor::MoveOperation operation
argument_list|,
argument|QTextCursor::MoveMode mode = QTextCursor::MoveAnchor
argument_list|)
block|;
name|bool
name|canPaste
argument_list|()
specifier|const
block|;
name|void
name|print
argument_list|(
argument|QPagedPaintDevice *printer
argument_list|)
specifier|const
block|;
name|int
name|blockCount
argument_list|()
specifier|const
block|;
name|QVariant
name|inputMethodQuery
argument_list|(
argument|Qt::InputMethodQuery property
argument_list|)
specifier|const
block|;
name|Q_INVOKABLE
name|QVariant
name|inputMethodQuery
argument_list|(
argument|Qt::InputMethodQuery query
argument_list|,
argument|QVariant argument
argument_list|)
specifier|const
block|;
name|public
name|Q_SLOTS
operator|:
name|void
name|setPlainText
argument_list|(
specifier|const
name|QString
operator|&
name|text
argument_list|)
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
block|;
name|void
name|paste
argument_list|()
block|;
endif|#
directive|endif
name|void
name|undo
argument_list|()
block|;
name|void
name|redo
argument_list|()
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
name|insertPlainText
argument_list|(
specifier|const
name|QString
operator|&
name|text
argument_list|)
block|;
name|void
name|appendPlainText
argument_list|(
specifier|const
name|QString
operator|&
name|text
argument_list|)
block|;
name|void
name|appendHtml
argument_list|(
specifier|const
name|QString
operator|&
name|html
argument_list|)
block|;
name|void
name|centerCursor
argument_list|()
block|;
name|void
name|zoomIn
argument_list|(
argument|int range =
literal|1
argument_list|)
block|;
name|void
name|zoomOut
argument_list|(
argument|int range =
literal|1
argument_list|)
block|;
name|Q_SIGNALS
operator|:
name|void
name|textChanged
argument_list|()
block|;
name|void
name|undoAvailable
argument_list|(
argument|bool b
argument_list|)
block|;
name|void
name|redoAvailable
argument_list|(
argument|bool b
argument_list|)
block|;
name|void
name|copyAvailable
argument_list|(
argument|bool b
argument_list|)
block|;
name|void
name|selectionChanged
argument_list|()
block|;
name|void
name|cursorPositionChanged
argument_list|()
block|;
name|void
name|updateRequest
argument_list|(
argument|const QRect&rect
argument_list|,
argument|int dy
argument_list|)
block|;
name|void
name|blockCountChanged
argument_list|(
argument|int newBlockCount
argument_list|)
block|;
name|void
name|modificationChanged
argument_list|(
name|bool
argument_list|)
block|;
name|protected
operator|:
name|virtual
name|bool
name|event
argument_list|(
name|QEvent
operator|*
name|e
argument_list|)
block|;
name|virtual
name|void
name|timerEvent
argument_list|(
name|QTimerEvent
operator|*
name|e
argument_list|)
block|;
name|virtual
name|void
name|keyPressEvent
argument_list|(
name|QKeyEvent
operator|*
name|e
argument_list|)
block|;
name|virtual
name|void
name|keyReleaseEvent
argument_list|(
name|QKeyEvent
operator|*
name|e
argument_list|)
block|;
name|virtual
name|void
name|resizeEvent
argument_list|(
name|QResizeEvent
operator|*
name|e
argument_list|)
block|;
name|virtual
name|void
name|paintEvent
argument_list|(
name|QPaintEvent
operator|*
name|e
argument_list|)
block|;
name|virtual
name|void
name|mousePressEvent
argument_list|(
name|QMouseEvent
operator|*
name|e
argument_list|)
block|;
name|virtual
name|void
name|mouseMoveEvent
argument_list|(
name|QMouseEvent
operator|*
name|e
argument_list|)
block|;
name|virtual
name|void
name|mouseReleaseEvent
argument_list|(
name|QMouseEvent
operator|*
name|e
argument_list|)
block|;
name|virtual
name|void
name|mouseDoubleClickEvent
argument_list|(
name|QMouseEvent
operator|*
name|e
argument_list|)
block|;
name|virtual
name|bool
name|focusNextPrevChild
argument_list|(
argument|bool next
argument_list|)
block|;
ifndef|#
directive|ifndef
name|QT_NO_CONTEXTMENU
name|virtual
name|void
name|contextMenuEvent
argument_list|(
name|QContextMenuEvent
operator|*
name|e
argument_list|)
block|;
endif|#
directive|endif
ifndef|#
directive|ifndef
name|QT_NO_DRAGANDDROP
name|virtual
name|void
name|dragEnterEvent
argument_list|(
name|QDragEnterEvent
operator|*
name|e
argument_list|)
block|;
name|virtual
name|void
name|dragLeaveEvent
argument_list|(
name|QDragLeaveEvent
operator|*
name|e
argument_list|)
block|;
name|virtual
name|void
name|dragMoveEvent
argument_list|(
name|QDragMoveEvent
operator|*
name|e
argument_list|)
block|;
name|virtual
name|void
name|dropEvent
argument_list|(
name|QDropEvent
operator|*
name|e
argument_list|)
block|;
endif|#
directive|endif
name|virtual
name|void
name|focusInEvent
argument_list|(
name|QFocusEvent
operator|*
name|e
argument_list|)
block|;
name|virtual
name|void
name|focusOutEvent
argument_list|(
name|QFocusEvent
operator|*
name|e
argument_list|)
block|;
name|virtual
name|void
name|showEvent
argument_list|(
name|QShowEvent
operator|*
argument_list|)
block|;
name|virtual
name|void
name|changeEvent
argument_list|(
name|QEvent
operator|*
name|e
argument_list|)
block|;
ifndef|#
directive|ifndef
name|QT_NO_WHEELEVENT
name|virtual
name|void
name|wheelEvent
argument_list|(
name|QWheelEvent
operator|*
name|e
argument_list|)
block|;
endif|#
directive|endif
name|virtual
name|QMimeData
operator|*
name|createMimeDataFromSelection
argument_list|()
specifier|const
block|;
name|virtual
name|bool
name|canInsertFromMimeData
argument_list|(
argument|const QMimeData *source
argument_list|)
specifier|const
block|;
name|virtual
name|void
name|insertFromMimeData
argument_list|(
specifier|const
name|QMimeData
operator|*
name|source
argument_list|)
block|;
name|virtual
name|void
name|inputMethodEvent
argument_list|(
name|QInputMethodEvent
operator|*
argument_list|)
block|;
name|QPlainTextEdit
argument_list|(
name|QPlainTextEditPrivate
operator|&
name|dd
argument_list|,
name|QWidget
operator|*
name|parent
argument_list|)
block|;
name|virtual
name|void
name|scrollContentsBy
argument_list|(
argument|int dx
argument_list|,
argument|int dy
argument_list|)
block|;
name|virtual
name|void
name|doSetTextCursor
argument_list|(
specifier|const
name|QTextCursor
operator|&
name|cursor
argument_list|)
block|;
name|QTextBlock
name|firstVisibleBlock
argument_list|()
specifier|const
block|;
name|QPointF
name|contentOffset
argument_list|()
specifier|const
block|;
name|QRectF
name|blockBoundingRect
argument_list|(
argument|const QTextBlock&block
argument_list|)
specifier|const
block|;
name|QRectF
name|blockBoundingGeometry
argument_list|(
argument|const QTextBlock&block
argument_list|)
specifier|const
block|;
name|QAbstractTextDocumentLayout
operator|::
name|PaintContext
name|getPaintContext
argument_list|()
specifier|const
block|;
name|void
name|zoomInF
argument_list|(
argument|float range
argument_list|)
block|;
name|private
operator|:
name|Q_DISABLE_COPY
argument_list|(
argument|QPlainTextEdit
argument_list|)
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_repaintContents(const QRectF&r)
argument_list|)
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_adjustScrollbars()
argument_list|)
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_verticalScrollbarActionTriggered(int)
argument_list|)
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_cursorPositionChanged()
argument_list|)
name|friend
name|class
name|QPlainTextEditControl
block|; }
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QPlainTextDocumentLayoutPrivate
name|class
name|QPlainTextDocumentLayoutPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_WIDGETS_EXPORT
name|QPlainTextDocumentLayout
range|:
name|public
name|QAbstractTextDocumentLayout
block|{
name|Q_OBJECT
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QPlainTextDocumentLayout
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|int cursorWidth READ cursorWidth WRITE setCursorWidth
argument_list|)
name|public
operator|:
name|QPlainTextDocumentLayout
argument_list|(
name|QTextDocument
operator|*
name|document
argument_list|)
block|;
operator|~
name|QPlainTextDocumentLayout
argument_list|()
block|;
name|void
name|draw
argument_list|(
name|QPainter
operator|*
argument_list|,
specifier|const
name|PaintContext
operator|&
argument_list|)
block|;
name|int
name|hitTest
argument_list|(
argument|const QPointF&
argument_list|,
argument|Qt::HitTestAccuracy
argument_list|)
specifier|const
block|;
name|int
name|pageCount
argument_list|()
specifier|const
block|;
name|QSizeF
name|documentSize
argument_list|()
specifier|const
block|;
name|QRectF
name|frameBoundingRect
argument_list|(
argument|QTextFrame *
argument_list|)
specifier|const
block|;
name|QRectF
name|blockBoundingRect
argument_list|(
argument|const QTextBlock&block
argument_list|)
specifier|const
block|;
name|void
name|ensureBlockLayout
argument_list|(
argument|const QTextBlock&block
argument_list|)
specifier|const
block|;
name|void
name|setCursorWidth
argument_list|(
argument|int width
argument_list|)
block|;
name|int
name|cursorWidth
argument_list|()
specifier|const
block|;
name|void
name|requestUpdate
argument_list|()
block|;
name|protected
operator|:
name|void
name|documentChanged
argument_list|(
argument|int from
argument_list|,
argument|int
comment|/*charsRemoved*/
argument_list|,
argument|int charsAdded
argument_list|)
block|;
name|private
operator|:
name|void
name|setTextWidth
argument_list|(
argument|qreal newWidth
argument_list|)
block|;
name|qreal
name|textWidth
argument_list|()
specifier|const
block|;
name|void
name|layoutBlock
argument_list|(
specifier|const
name|QTextBlock
operator|&
name|block
argument_list|)
block|;
name|qreal
name|blockWidth
argument_list|(
specifier|const
name|QTextBlock
operator|&
name|block
argument_list|)
block|;
name|QPlainTextDocumentLayoutPrivate
operator|*
name|priv
argument_list|()
specifier|const
block|;
name|friend
name|class
name|QPlainTextEdit
block|;
name|friend
name|class
name|QPlainTextEditPrivate
block|; }
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
comment|// QT_NO_TEXTEDIT
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QPLAINTEXTEDIT_H
end_comment
end_unit
