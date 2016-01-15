begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QTEXTDOCUMENT_P_H
end_ifndef
begin_define
DECL|macro|QTEXTDOCUMENT_P_H
define|#
directive|define
name|QTEXTDOCUMENT_P_H
end_define
begin_comment
comment|//
end_comment
begin_comment
comment|//  W A R N I N G
end_comment
begin_comment
comment|//  -------------
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|// This file is not part of the Qt API.  It exists purely as an
end_comment
begin_comment
comment|// implementation detail.  This header file may change from version to
end_comment
begin_comment
comment|// version without notice, or even be removed.
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|// We mean it.
end_comment
begin_comment
comment|//
end_comment
begin_include
include|#
directive|include
file|"QtCore/qglobal.h"
end_include
begin_include
include|#
directive|include
file|"QtCore/qstring.h"
end_include
begin_include
include|#
directive|include
file|"QtCore/qvector.h"
end_include
begin_include
include|#
directive|include
file|"QtCore/qlist.h"
end_include
begin_include
include|#
directive|include
file|"private/qobject_p.h"
end_include
begin_include
include|#
directive|include
file|"private/qfragmentmap_p.h"
end_include
begin_include
include|#
directive|include
file|"QtGui/qtextlayout.h"
end_include
begin_include
include|#
directive|include
file|"QtGui/qtextoption.h"
end_include
begin_include
include|#
directive|include
file|"private/qtextformat_p.h"
end_include
begin_include
include|#
directive|include
file|"QtGui/qtextdocument.h"
end_include
begin_include
include|#
directive|include
file|"QtGui/qtextobject.h"
end_include
begin_include
include|#
directive|include
file|"QtGui/qtextcursor.h"
end_include
begin_include
include|#
directive|include
file|"QtCore/qmap.h"
end_include
begin_include
include|#
directive|include
file|"QtCore/qvariant.h"
end_include
begin_include
include|#
directive|include
file|"QtCore/qurl.h"
end_include
begin_include
include|#
directive|include
file|"private/qcssparser_p.h"
end_include
begin_comment
comment|// #define QT_QMAP_DEBUG
end_comment
begin_ifdef
ifdef|#
directive|ifdef
name|QT_QMAP_DEBUG
end_ifdef
begin_include
include|#
directive|include
file|<iostream>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QTextFormatCollection
name|class
name|QTextFormatCollection
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QTextFormat
name|class
name|QTextFormat
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QTextBlockFormat
name|class
name|QTextBlockFormat
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QTextCursorPrivate
name|class
name|QTextCursorPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QAbstractTextDocumentLayout
name|class
name|QAbstractTextDocumentLayout
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QTextDocument
name|class
name|QTextDocument
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QTextFrame
name|class
name|QTextFrame
decl_stmt|;
end_decl_stmt
begin_define
DECL|macro|QTextBeginningOfFrame
define|#
directive|define
name|QTextBeginningOfFrame
value|QChar(0xfdd0)
end_define
begin_define
DECL|macro|QTextEndOfFrame
define|#
directive|define
name|QTextEndOfFrame
value|QChar(0xfdd1)
end_define
begin_decl_stmt
name|class
name|QTextFragmentData
range|:
name|public
name|QFragment
operator|<
operator|>
block|{
name|public
operator|:
specifier|inline
name|void
name|initialize
argument_list|()
block|{}
specifier|inline
name|void
name|invalidate
argument_list|()
specifier|const
block|{}
specifier|inline
name|void
name|free
argument_list|()
block|{}
name|int
name|stringPosition
block|;
name|int
name|format
block|; }
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QTextBlockData
range|:
name|public
name|QFragment
operator|<
literal|3
operator|>
block|{
name|public
operator|:
specifier|inline
name|void
name|initialize
argument_list|()
block|{
name|layout
operator|=
literal|0
block|;
name|userData
operator|=
literal|0
block|;
name|userState
operator|=
operator|-
literal|1
block|;
name|revision
operator|=
literal|0
block|;
name|hidden
operator|=
literal|0
block|; }
name|void
name|invalidate
argument_list|()
specifier|const
block|;
specifier|inline
name|void
name|free
argument_list|()
block|{
name|delete
name|layout
block|;
name|layout
operator|=
literal|0
block|;
name|delete
name|userData
block|;
name|userData
operator|=
literal|0
block|; }
name|mutable
name|int
name|format
block|;
comment|// ##### probably store a QTextEngine * here!
name|mutable
name|QTextLayout
operator|*
name|layout
block|;
name|mutable
name|QTextBlockUserData
operator|*
name|userData
block|;
name|mutable
name|int
name|userState
block|;
name|mutable
name|int
name|revision
operator|:
literal|31
block|;
name|mutable
name|uint
name|hidden
operator|:
literal|1
block|; }
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QAbstractUndoItem
name|class
name|QAbstractUndoItem
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QTextUndoCommand
block|{
name|public
label|:
enum|enum
name|Command
block|{
name|Inserted
init|=
literal|0
block|,
name|Removed
init|=
literal|1
block|,
name|CharFormatChanged
init|=
literal|2
block|,
name|BlockFormatChanged
init|=
literal|3
block|,
name|BlockInserted
init|=
literal|4
block|,
name|BlockRemoved
init|=
literal|5
block|,
name|BlockAdded
init|=
literal|6
block|,
name|BlockDeleted
init|=
literal|7
block|,
name|GroupFormatChange
init|=
literal|8
block|,
name|CursorMoved
init|=
literal|9
block|,
name|Custom
init|=
literal|256
block|}
enum|;
enum|enum
name|Operation
block|{
name|KeepCursor
init|=
literal|0
block|,
name|MoveCursor
init|=
literal|1
block|}
enum|;
name|quint16
name|command
decl_stmt|;
name|uint
name|block_part
range|:
literal|1
decl_stmt|;
comment|// all commands that are part of an undo block (including the first and the last one) have this set to 1
name|uint
name|block_end
range|:
literal|1
decl_stmt|;
comment|// the last command in an undo block has this set to 1.
name|uint
name|block_padding
range|:
literal|6
decl_stmt|;
comment|// padding since block used to be a quint8
name|quint8
name|operation
decl_stmt|;
name|int
name|format
decl_stmt|;
name|quint32
name|strPos
decl_stmt|;
name|quint32
name|pos
decl_stmt|;
union|union
block|{
name|int
name|blockFormat
decl_stmt|;
name|quint32
name|length
decl_stmt|;
name|QAbstractUndoItem
modifier|*
name|custom
decl_stmt|;
name|int
name|objectIndex
decl_stmt|;
block|}
union|;
name|quint32
name|revision
decl_stmt|;
name|bool
name|tryMerge
parameter_list|(
specifier|const
name|QTextUndoCommand
modifier|&
name|other
parameter_list|)
function_decl|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_expr_stmt
name|Q_DECLARE_TYPEINFO
argument_list|(
name|QTextUndoCommand
argument_list|,
name|Q_PRIMITIVE_TYPE
argument_list|)
expr_stmt|;
end_expr_stmt
begin_decl_stmt
name|class
name|Q_AUTOTEST_EXPORT
name|QTextDocumentPrivate
range|:
name|public
name|QObjectPrivate
block|{
name|Q_DECLARE_PUBLIC
argument_list|(
argument|QTextDocument
argument_list|)
name|public
operator|:
typedef|typedef
name|QFragmentMap
operator|<
name|QTextFragmentData
operator|>
name|FragmentMap
expr_stmt|;
end_decl_stmt
begin_typedef
typedef|typedef
name|FragmentMap
operator|::
name|ConstIterator
name|FragmentIterator
expr_stmt|;
end_typedef
begin_typedef
typedef|typedef
name|QFragmentMap
operator|<
name|QTextBlockData
operator|>
name|BlockMap
expr_stmt|;
end_typedef
begin_expr_stmt
name|QTextDocumentPrivate
argument_list|()
expr_stmt|;
end_expr_stmt
begin_expr_stmt
operator|~
name|QTextDocumentPrivate
argument_list|()
expr_stmt|;
end_expr_stmt
begin_function_decl
name|void
name|init
parameter_list|()
function_decl|;
end_function_decl
begin_function_decl
name|void
name|clear
parameter_list|()
function_decl|;
end_function_decl
begin_function_decl
name|void
name|setLayout
parameter_list|(
name|QAbstractTextDocumentLayout
modifier|*
name|layout
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|insert
parameter_list|(
name|int
name|pos
parameter_list|,
specifier|const
name|QString
modifier|&
name|text
parameter_list|,
name|int
name|format
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|insert
parameter_list|(
name|int
name|pos
parameter_list|,
name|int
name|strPos
parameter_list|,
name|int
name|strLength
parameter_list|,
name|int
name|format
parameter_list|)
function_decl|;
end_function_decl
begin_decl_stmt
name|int
name|insertBlock
argument_list|(
name|int
name|pos
argument_list|,
name|int
name|blockFormat
argument_list|,
name|int
name|charFormat
argument_list|,
name|QTextUndoCommand
operator|::
name|Operation
operator|=
name|QTextUndoCommand
operator|::
name|MoveCursor
argument_list|)
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|int
name|insertBlock
argument_list|(
name|QChar
name|blockSeparator
argument_list|,
name|int
name|pos
argument_list|,
name|int
name|blockFormat
argument_list|,
name|int
name|charFormat
argument_list|,
name|QTextUndoCommand
operator|::
name|Operation
name|op
operator|=
name|QTextUndoCommand
operator|::
name|MoveCursor
argument_list|)
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|void
name|move
argument_list|(
name|int
name|from
argument_list|,
name|int
name|to
argument_list|,
name|int
name|length
argument_list|,
name|QTextUndoCommand
operator|::
name|Operation
operator|=
name|QTextUndoCommand
operator|::
name|MoveCursor
argument_list|)
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|void
name|remove
argument_list|(
name|int
name|pos
argument_list|,
name|int
name|length
argument_list|,
name|QTextUndoCommand
operator|::
name|Operation
operator|=
name|QTextUndoCommand
operator|::
name|MoveCursor
argument_list|)
decl_stmt|;
end_decl_stmt
begin_function_decl
name|void
name|aboutToRemoveCell
parameter_list|(
name|int
name|cursorFrom
parameter_list|,
name|int
name|cursorEnd
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|QTextFrame
modifier|*
name|insertFrame
parameter_list|(
name|int
name|start
parameter_list|,
name|int
name|end
parameter_list|,
specifier|const
name|QTextFrameFormat
modifier|&
name|format
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|removeFrame
parameter_list|(
name|QTextFrame
modifier|*
name|frame
parameter_list|)
function_decl|;
end_function_decl
begin_enum
enum|enum
name|FormatChangeMode
block|{
name|MergeFormat
block|,
name|SetFormat
block|,
name|SetFormatAndPreserveObjectIndices
block|}
enum|;
end_enum
begin_function_decl
name|void
name|setCharFormat
parameter_list|(
name|int
name|pos
parameter_list|,
name|int
name|length
parameter_list|,
specifier|const
name|QTextCharFormat
modifier|&
name|newFormat
parameter_list|,
name|FormatChangeMode
name|mode
init|=
name|SetFormat
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|setBlockFormat
parameter_list|(
specifier|const
name|QTextBlock
modifier|&
name|from
parameter_list|,
specifier|const
name|QTextBlock
modifier|&
name|to
parameter_list|,
specifier|const
name|QTextBlockFormat
modifier|&
name|newFormat
parameter_list|,
name|FormatChangeMode
name|mode
init|=
name|SetFormat
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|emitUndoAvailable
parameter_list|(
name|bool
name|available
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|emitRedoAvailable
parameter_list|(
name|bool
name|available
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|int
name|undoRedo
parameter_list|(
name|bool
name|undo
parameter_list|)
function_decl|;
end_function_decl
begin_function
specifier|inline
name|void
name|undo
parameter_list|()
block|{
name|undoRedo
argument_list|(
name|true
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
specifier|inline
name|void
name|redo
parameter_list|()
block|{
name|undoRedo
argument_list|(
name|false
argument_list|)
expr_stmt|;
block|}
end_function
begin_function_decl
name|void
name|appendUndoItem
parameter_list|(
name|QAbstractUndoItem
modifier|*
parameter_list|)
function_decl|;
end_function_decl
begin_function
specifier|inline
name|void
name|beginEditBlock
parameter_list|()
block|{
if|if
condition|(
literal|0
operator|==
name|editBlock
operator|++
condition|)
operator|++
name|revision
expr_stmt|;
block|}
end_function
begin_function_decl
name|void
name|joinPreviousEditBlock
parameter_list|()
function_decl|;
end_function_decl
begin_function_decl
name|void
name|endEditBlock
parameter_list|()
function_decl|;
end_function_decl
begin_function_decl
name|void
name|finishEdit
parameter_list|()
function_decl|;
end_function_decl
begin_expr_stmt
specifier|inline
name|bool
name|isInEditBlock
argument_list|()
specifier|const
block|{
return|return
name|editBlock
return|;
block|}
end_expr_stmt
begin_function_decl
name|void
name|enableUndoRedo
parameter_list|(
name|bool
name|enable
parameter_list|)
function_decl|;
end_function_decl
begin_expr_stmt
specifier|inline
name|bool
name|isUndoRedoEnabled
argument_list|()
specifier|const
block|{
return|return
name|undoEnabled
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
name|bool
name|isUndoAvailable
argument_list|()
specifier|const
block|{
return|return
name|undoEnabled
operator|&&
name|undoState
operator|>
literal|0
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
name|bool
name|isRedoAvailable
argument_list|()
specifier|const
block|{
return|return
name|undoEnabled
operator|&&
name|undoState
operator|<
name|undoStack
operator|.
name|size
argument_list|()
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
name|int
name|availableUndoSteps
argument_list|()
specifier|const
block|{
return|return
name|undoEnabled
operator|?
name|undoState
operator|:
literal|0
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
name|int
name|availableRedoSteps
argument_list|()
specifier|const
block|{
return|return
name|undoEnabled
operator|?
name|qMax
argument_list|(
name|undoStack
operator|.
name|size
argument_list|()
operator|-
name|undoState
operator|-
literal|1
argument_list|,
literal|0
argument_list|)
operator|:
literal|0
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
name|QString
name|buffer
argument_list|()
specifier|const
block|{
return|return
name|text
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|QString
name|plainText
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_expr_stmt
specifier|inline
name|int
name|length
argument_list|()
specifier|const
block|{
return|return
name|fragments
operator|.
name|length
argument_list|()
return|;
block|}
end_expr_stmt
begin_function
specifier|inline
name|QTextFormatCollection
modifier|*
name|formatCollection
parameter_list|()
block|{
return|return
operator|&
name|formats
return|;
block|}
end_function
begin_expr_stmt
specifier|inline
specifier|const
name|QTextFormatCollection
operator|*
name|formatCollection
argument_list|()
specifier|const
block|{
return|return
operator|&
name|formats
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
name|QAbstractTextDocumentLayout
operator|*
name|layout
argument_list|()
specifier|const
block|{
return|return
name|lout
return|;
block|}
end_expr_stmt
begin_decl_stmt
specifier|inline
name|FragmentIterator
name|find
argument_list|(
name|int
name|pos
argument_list|)
decl|const
block|{
return|return
name|fragments
operator|.
name|find
argument_list|(
name|pos
argument_list|)
return|;
block|}
end_decl_stmt
begin_expr_stmt
specifier|inline
name|FragmentIterator
name|begin
argument_list|()
specifier|const
block|{
return|return
name|fragments
operator|.
name|begin
argument_list|()
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
name|FragmentIterator
name|end
argument_list|()
specifier|const
block|{
return|return
name|fragments
operator|.
name|end
argument_list|()
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
name|QTextBlock
name|blocksBegin
argument_list|()
specifier|const
block|{
return|return
name|QTextBlock
argument_list|(
name|const_cast
operator|<
name|QTextDocumentPrivate
operator|*
operator|>
operator|(
name|this
operator|)
argument_list|,
name|blocks
operator|.
name|firstNode
argument_list|()
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
name|QTextBlock
name|blocksEnd
argument_list|()
specifier|const
block|{
return|return
name|QTextBlock
argument_list|(
name|const_cast
operator|<
name|QTextDocumentPrivate
operator|*
operator|>
operator|(
name|this
operator|)
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_expr_stmt
begin_decl_stmt
specifier|inline
name|QTextBlock
name|blocksFind
argument_list|(
name|int
name|pos
argument_list|)
decl|const
block|{
return|return
name|QTextBlock
argument_list|(
name|const_cast
operator|<
name|QTextDocumentPrivate
operator|*
operator|>
operator|(
name|this
operator|)
argument_list|,
name|blocks
operator|.
name|findNode
argument_list|(
name|pos
argument_list|)
argument_list|)
return|;
block|}
end_decl_stmt
begin_decl_stmt
name|int
name|blockCharFormatIndex
argument_list|(
name|int
name|node
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt
begin_expr_stmt
specifier|inline
name|int
name|numBlocks
argument_list|()
specifier|const
block|{
return|return
name|blocks
operator|.
name|numNodes
argument_list|()
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|const
name|BlockMap
operator|&
name|blockMap
argument_list|()
specifier|const
block|{
return|return
name|blocks
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|const
name|FragmentMap
operator|&
name|fragmentMap
argument_list|()
specifier|const
block|{
return|return
name|fragments
return|;
block|}
end_expr_stmt
begin_function
name|BlockMap
modifier|&
name|blockMap
parameter_list|()
block|{
return|return
name|blocks
return|;
block|}
end_function
begin_function
name|FragmentMap
modifier|&
name|fragmentMap
parameter_list|()
block|{
return|return
name|fragments
return|;
block|}
end_function
begin_function
specifier|static
specifier|const
name|QTextBlockData
modifier|*
name|block
parameter_list|(
specifier|const
name|QTextBlock
modifier|&
name|it
parameter_list|)
block|{
return|return
name|it
operator|.
name|p
operator|->
name|blocks
operator|.
name|fragment
argument_list|(
name|it
operator|.
name|n
argument_list|)
return|;
block|}
end_function
begin_decl_stmt
name|int
name|nextCursorPosition
argument_list|(
name|int
name|position
argument_list|,
name|QTextLayout
operator|::
name|CursorMode
name|mode
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|int
name|previousCursorPosition
argument_list|(
name|int
name|position
argument_list|,
name|QTextLayout
operator|::
name|CursorMode
name|mode
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|int
name|leftCursorPosition
argument_list|(
name|int
name|position
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|int
name|rightCursorPosition
argument_list|(
name|int
name|position
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt
begin_function_decl
name|void
name|changeObjectFormat
parameter_list|(
name|QTextObject
modifier|*
name|group
parameter_list|,
name|int
name|format
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|setModified
parameter_list|(
name|bool
name|m
parameter_list|)
function_decl|;
end_function_decl
begin_expr_stmt
specifier|inline
name|bool
name|isModified
argument_list|()
specifier|const
block|{
return|return
name|modified
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
name|QFont
name|defaultFont
argument_list|()
specifier|const
block|{
return|return
name|formats
operator|.
name|defaultFont
argument_list|()
return|;
block|}
end_expr_stmt
begin_function
specifier|inline
name|void
name|setDefaultFont
parameter_list|(
specifier|const
name|QFont
modifier|&
name|f
parameter_list|)
block|{
name|formats
operator|.
name|setDefaultFont
argument_list|(
name|f
argument_list|)
expr_stmt|;
block|}
end_function
begin_decl_stmt
name|void
name|clearUndoRedoStacks
argument_list|(
name|QTextDocument
operator|::
name|Stacks
name|stacksToClear
argument_list|,
name|bool
name|emitSignals
operator|=
name|false
argument_list|)
decl_stmt|;
end_decl_stmt
begin_label
name|private
label|:
end_label
begin_function_decl
name|bool
name|split
parameter_list|(
name|int
name|pos
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|bool
name|unite
parameter_list|(
name|uint
name|f
parameter_list|)
function_decl|;
end_function_decl
begin_decl_stmt
name|void
name|insert_string
argument_list|(
name|int
name|pos
argument_list|,
name|uint
name|strPos
argument_list|,
name|uint
name|length
argument_list|,
name|int
name|format
argument_list|,
name|QTextUndoCommand
operator|::
name|Operation
name|op
argument_list|)
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|int
name|insert_block
argument_list|(
name|int
name|pos
argument_list|,
name|uint
name|strPos
argument_list|,
name|int
name|format
argument_list|,
name|int
name|blockformat
argument_list|,
name|QTextUndoCommand
operator|::
name|Operation
name|op
argument_list|,
name|int
name|command
argument_list|)
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|int
name|remove_string
argument_list|(
name|int
name|pos
argument_list|,
name|uint
name|length
argument_list|,
name|QTextUndoCommand
operator|::
name|Operation
name|op
argument_list|)
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|int
name|remove_block
argument_list|(
name|int
name|pos
argument_list|,
name|int
operator|*
name|blockformat
argument_list|,
name|int
name|command
argument_list|,
name|QTextUndoCommand
operator|::
name|Operation
name|op
argument_list|)
decl_stmt|;
end_decl_stmt
begin_function_decl
name|void
name|insert_frame
parameter_list|(
name|QTextFrame
modifier|*
name|f
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|scan_frames
parameter_list|(
name|int
name|pos
parameter_list|,
name|int
name|charsRemoved
parameter_list|,
name|int
name|charsAdded
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
specifier|static
name|void
name|clearFrame
parameter_list|(
name|QTextFrame
modifier|*
name|f
parameter_list|)
function_decl|;
end_function_decl
begin_decl_stmt
name|void
name|adjustDocumentChangesAndCursors
argument_list|(
name|int
name|from
argument_list|,
name|int
name|addedOrRemoved
argument_list|,
name|QTextUndoCommand
operator|::
name|Operation
name|op
argument_list|)
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|bool
name|wasUndoAvailable
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|bool
name|wasRedoAvailable
decl_stmt|;
end_decl_stmt
begin_label
name|public
label|:
end_label
begin_function_decl
name|void
name|documentChange
parameter_list|(
name|int
name|from
parameter_list|,
name|int
name|length
parameter_list|)
function_decl|;
end_function_decl
begin_function
specifier|inline
name|void
name|addCursor
parameter_list|(
name|QTextCursorPrivate
modifier|*
name|c
parameter_list|)
block|{
name|cursors
operator|.
name|append
argument_list|(
name|c
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
specifier|inline
name|void
name|removeCursor
parameter_list|(
name|QTextCursorPrivate
modifier|*
name|c
parameter_list|)
block|{
name|cursors
operator|.
name|removeAll
argument_list|(
name|c
argument_list|)
expr_stmt|;
block|}
end_function
begin_decl_stmt
name|QTextFrame
modifier|*
name|frameAt
argument_list|(
name|int
name|pos
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|QTextFrame
operator|*
name|rootFrame
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_decl_stmt
name|QTextObject
modifier|*
name|objectForIndex
argument_list|(
name|int
name|objectIndex
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QTextObject
modifier|*
name|objectForFormat
argument_list|(
name|int
name|formatIndex
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QTextObject
modifier|*
name|objectForFormat
argument_list|(
specifier|const
name|QTextFormat
operator|&
name|f
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt
begin_function_decl
name|QTextObject
modifier|*
name|createObject
parameter_list|(
specifier|const
name|QTextFormat
modifier|&
name|newFormat
parameter_list|,
name|int
name|objectIndex
init|=
operator|-
literal|1
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|deleteObject
parameter_list|(
name|QTextObject
modifier|*
name|object
parameter_list|)
function_decl|;
end_function_decl
begin_function
name|QTextDocument
modifier|*
name|document
parameter_list|()
block|{
return|return
name|q_func
argument_list|()
return|;
block|}
end_function
begin_expr_stmt
specifier|const
name|QTextDocument
operator|*
name|document
argument_list|()
specifier|const
block|{
return|return
name|q_func
argument_list|()
return|;
block|}
end_expr_stmt
begin_function_decl
name|bool
name|ensureMaximumBlockCount
parameter_list|()
function_decl|;
end_function_decl
begin_label
name|private
label|:
end_label
begin_expr_stmt
name|QTextDocumentPrivate
argument_list|(
specifier|const
name|QTextDocumentPrivate
operator|&
name|m
argument_list|)
expr_stmt|;
end_expr_stmt
begin_decl_stmt
name|QTextDocumentPrivate
modifier|&
name|operator
init|=
operator|(
specifier|const
name|QTextDocumentPrivate
operator|&
name|m
operator|)
decl_stmt|;
end_decl_stmt
begin_function_decl
name|void
name|appendUndoItem
parameter_list|(
specifier|const
name|QTextUndoCommand
modifier|&
name|c
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|contentsChanged
parameter_list|()
function_decl|;
end_function_decl
begin_function_decl
name|void
name|compressPieceTable
parameter_list|()
function_decl|;
end_function_decl
begin_decl_stmt
name|QString
name|text
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|uint
name|unreachableCharacterCount
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|QVector
operator|<
name|QTextUndoCommand
operator|>
name|undoStack
expr_stmt|;
end_expr_stmt
begin_decl_stmt
name|bool
name|undoEnabled
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|int
name|undoState
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|int
name|revision
decl_stmt|;
end_decl_stmt
begin_comment
comment|// position in undo stack of the last setModified(false) call
end_comment
begin_decl_stmt
name|int
name|modifiedState
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|bool
name|modified
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|int
name|editBlock
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|int
name|editBlockCursorPosition
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|int
name|docChangeFrom
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|int
name|docChangeOldLength
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|int
name|docChangeLength
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|bool
name|framesDirty
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QTextFormatCollection
name|formats
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|mutable
name|QTextFrame
modifier|*
name|rtFrame
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QAbstractTextDocumentLayout
modifier|*
name|lout
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|FragmentMap
name|fragments
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|BlockMap
name|blocks
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|int
name|initialBlockCharFormatIndex
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|QList
operator|<
name|QTextCursorPrivate
operator|*
operator|>
name|cursors
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|QMap
operator|<
name|int
operator|,
name|QTextObject
operator|*
operator|>
name|objects
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|QMap
operator|<
name|QUrl
operator|,
name|QVariant
operator|>
name|resources
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|QMap
operator|<
name|QUrl
operator|,
name|QVariant
operator|>
name|cachedResources
expr_stmt|;
end_expr_stmt
begin_decl_stmt
name|QString
name|defaultStyleSheet
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|int
name|lastBlockCount
decl_stmt|;
end_decl_stmt
begin_label
name|public
label|:
end_label
begin_decl_stmt
name|QTextOption
name|defaultTextOption
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|Qt
operator|::
name|CursorMoveStyle
name|defaultCursorMoveStyle
expr_stmt|;
end_expr_stmt
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_CSSPARSER
end_ifndef
begin_expr_stmt
name|QCss
operator|::
name|StyleSheet
name|parsedDefaultStyleSheet
expr_stmt|;
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_decl_stmt
name|int
name|maximumBlockCount
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|uint
name|needsEnsureMaximumBlockCount
range|:
literal|1
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|uint
name|inContentsChange
range|:
literal|1
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|uint
name|blockCursorAdjustment
range|:
literal|1
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QSizeF
name|pageSize
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QString
name|title
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QString
name|url
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|qreal
name|indentWidth
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|qreal
name|documentMargin
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QUrl
name|baseUrl
decl_stmt|;
end_decl_stmt
begin_function_decl
name|void
name|mergeCachedResources
parameter_list|(
specifier|const
name|QTextDocumentPrivate
modifier|*
name|priv
parameter_list|)
function_decl|;
end_function_decl
begin_decl_stmt
name|friend
name|class
name|QTextHtmlExporter
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|friend
name|class
name|QTextCursor
decl_stmt|;
end_decl_stmt
begin_decl_stmt
unit|};
DECL|variable|QTextTable
name|class
name|QTextTable
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QTextHtmlExporter
block|{
name|public
label|:
name|QTextHtmlExporter
argument_list|(
specifier|const
name|QTextDocument
operator|*
name|_doc
argument_list|)
expr_stmt|;
enum|enum
name|ExportMode
block|{
name|ExportEntireDocument
block|,
name|ExportFragment
block|}
enum|;
name|QString
name|toHtml
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|encoding
parameter_list|,
name|ExportMode
name|mode
init|=
name|ExportEntireDocument
parameter_list|)
function_decl|;
name|private
label|:
enum|enum
name|StyleMode
block|{
name|EmitStyleTag
block|,
name|OmitStyleTag
block|}
enum|;
enum|enum
name|FrameType
block|{
name|TextFrame
block|,
name|TableFrame
block|,
name|RootFrame
block|}
enum|;
name|void
name|emitFrame
argument_list|(
name|QTextFrame
operator|::
name|Iterator
name|frameIt
argument_list|)
decl_stmt|;
name|void
name|emitTextFrame
parameter_list|(
specifier|const
name|QTextFrame
modifier|*
name|frame
parameter_list|)
function_decl|;
name|void
name|emitBlock
parameter_list|(
specifier|const
name|QTextBlock
modifier|&
name|block
parameter_list|)
function_decl|;
name|void
name|emitTable
parameter_list|(
specifier|const
name|QTextTable
modifier|*
name|table
parameter_list|)
function_decl|;
name|void
name|emitFragment
parameter_list|(
specifier|const
name|QTextFragment
modifier|&
name|fragment
parameter_list|)
function_decl|;
name|void
name|emitBlockAttributes
parameter_list|(
specifier|const
name|QTextBlock
modifier|&
name|block
parameter_list|)
function_decl|;
name|bool
name|emitCharFormatStyle
parameter_list|(
specifier|const
name|QTextCharFormat
modifier|&
name|format
parameter_list|)
function_decl|;
name|void
name|emitTextLength
parameter_list|(
specifier|const
name|char
modifier|*
name|attribute
parameter_list|,
specifier|const
name|QTextLength
modifier|&
name|length
parameter_list|)
function_decl|;
name|void
name|emitAlignment
argument_list|(
name|Qt
operator|::
name|Alignment
name|alignment
argument_list|)
decl_stmt|;
name|void
name|emitFloatStyle
argument_list|(
name|QTextFrameFormat
operator|::
name|Position
name|pos
argument_list|,
name|StyleMode
name|mode
operator|=
name|EmitStyleTag
argument_list|)
decl_stmt|;
name|void
name|emitMargins
parameter_list|(
specifier|const
name|QString
modifier|&
name|top
parameter_list|,
specifier|const
name|QString
modifier|&
name|bottom
parameter_list|,
specifier|const
name|QString
modifier|&
name|left
parameter_list|,
specifier|const
name|QString
modifier|&
name|right
parameter_list|)
function_decl|;
name|void
name|emitAttribute
parameter_list|(
specifier|const
name|char
modifier|*
name|attribute
parameter_list|,
specifier|const
name|QString
modifier|&
name|value
parameter_list|)
function_decl|;
name|void
name|emitFrameStyle
parameter_list|(
specifier|const
name|QTextFrameFormat
modifier|&
name|format
parameter_list|,
name|FrameType
name|frameType
parameter_list|)
function_decl|;
name|void
name|emitBorderStyle
argument_list|(
name|QTextFrameFormat
operator|::
name|BorderStyle
name|style
argument_list|)
decl_stmt|;
name|void
name|emitPageBreakPolicy
argument_list|(
name|QTextFormat
operator|::
name|PageBreakFlags
name|policy
argument_list|)
decl_stmt|;
name|void
name|emitFontFamily
parameter_list|(
specifier|const
name|QString
modifier|&
name|family
parameter_list|)
function_decl|;
name|void
name|emitBackgroundAttribute
parameter_list|(
specifier|const
name|QTextFormat
modifier|&
name|format
parameter_list|)
function_decl|;
name|QString
name|findUrlForImage
parameter_list|(
specifier|const
name|QTextDocument
modifier|*
name|doc
parameter_list|,
name|qint64
name|cacheKey
parameter_list|,
name|bool
name|isPixmap
parameter_list|)
function_decl|;
name|QString
name|html
decl_stmt|;
name|QTextCharFormat
name|defaultCharFormat
decl_stmt|;
specifier|const
name|QTextDocument
modifier|*
name|doc
decl_stmt|;
name|bool
name|fragmentMarkers
decl_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QTEXTDOCUMENT_P_H
end_comment
end_unit
