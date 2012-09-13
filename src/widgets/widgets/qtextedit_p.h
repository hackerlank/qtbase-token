begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QTEXTEDIT_P_H
end_ifndef
begin_define
DECL|macro|QTEXTEDIT_P_H
define|#
directive|define
name|QTEXTEDIT_P_H
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
file|"private/qabstractscrollarea_p.h"
end_include
begin_include
include|#
directive|include
file|"QtGui/qtextdocumentfragment.h"
end_include
begin_include
include|#
directive|include
file|"QtWidgets/qscrollbar.h"
end_include
begin_include
include|#
directive|include
file|"QtGui/qtextcursor.h"
end_include
begin_include
include|#
directive|include
file|"QtGui/qtextformat.h"
end_include
begin_include
include|#
directive|include
file|"QtWidgets/qmenu.h"
end_include
begin_include
include|#
directive|include
file|"QtGui/qabstracttextdocumentlayout.h"
end_include
begin_include
include|#
directive|include
file|"QtCore/qbasictimer.h"
end_include
begin_include
include|#
directive|include
file|"QtCore/qurl.h"
end_include
begin_include
include|#
directive|include
file|"private/qwidgettextcontrol_p.h"
end_include
begin_include
include|#
directive|include
file|"qtextedit.h"
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
ifndef|#
directive|ifndef
name|QT_NO_TEXTEDIT
DECL|variable|QMimeData
name|class
name|QMimeData
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QTextEditPrivate
range|:
name|public
name|QAbstractScrollAreaPrivate
block|{
name|Q_DECLARE_PUBLIC
argument_list|(
argument|QTextEdit
argument_list|)
name|public
operator|:
name|QTextEditPrivate
argument_list|()
block|;
name|void
name|init
argument_list|(
specifier|const
name|QString
operator|&
name|html
operator|=
name|QString
argument_list|()
argument_list|)
block|;
name|void
name|paint
argument_list|(
name|QPainter
operator|*
name|p
argument_list|,
name|QPaintEvent
operator|*
name|e
argument_list|)
block|;
name|void
name|_q_repaintContents
argument_list|(
specifier|const
name|QRectF
operator|&
name|contentsRect
argument_list|)
block|;
specifier|inline
name|QPoint
name|mapToContents
argument_list|(
argument|const QPoint&point
argument_list|)
specifier|const
block|{
return|return
name|QPoint
argument_list|(
name|point
operator|.
name|x
argument_list|()
operator|+
name|horizontalOffset
argument_list|()
argument_list|,
name|point
operator|.
name|y
argument_list|()
operator|+
name|verticalOffset
argument_list|()
argument_list|)
return|;
block|}
name|void
name|_q_adjustScrollbars
argument_list|()
block|;
name|void
name|_q_ensureVisible
argument_list|(
specifier|const
name|QRectF
operator|&
name|rect
argument_list|)
block|;
name|void
name|relayoutDocument
argument_list|()
block|;
name|void
name|createAutoBulletList
argument_list|()
block|;
name|void
name|pageUpDown
argument_list|(
argument|QTextCursor::MoveOperation op
argument_list|,
argument|QTextCursor::MoveMode moveMode
argument_list|)
block|;
specifier|inline
name|int
name|horizontalOffset
argument_list|()
specifier|const
block|{
return|return
name|q_func
argument_list|()
operator|->
name|isRightToLeft
argument_list|()
operator|?
operator|(
name|hbar
operator|->
name|maximum
argument_list|()
operator|-
name|hbar
operator|->
name|value
argument_list|()
operator|)
operator|:
name|hbar
operator|->
name|value
argument_list|()
return|;
block|}
specifier|inline
name|int
name|verticalOffset
argument_list|()
specifier|const
block|{
return|return
name|vbar
operator|->
name|value
argument_list|()
return|;
block|}
specifier|inline
name|void
name|sendControlEvent
argument_list|(
argument|QEvent *e
argument_list|)
block|{
name|control
operator|->
name|processEvent
argument_list|(
name|e
argument_list|,
name|QPointF
argument_list|(
name|horizontalOffset
argument_list|()
argument_list|,
name|verticalOffset
argument_list|()
argument_list|)
argument_list|,
name|viewport
argument_list|)
block|; }
name|void
name|_q_currentCharFormatChanged
argument_list|(
specifier|const
name|QTextCharFormat
operator|&
name|format
argument_list|)
block|;
name|void
name|_q_cursorPositionChanged
argument_list|()
block|;
name|void
name|updateDefaultTextOption
argument_list|()
block|;
comment|// re-implemented by QTextBrowser, called by QTextDocument::loadResource
name|virtual
name|QUrl
name|resolveUrl
argument_list|(
argument|const QUrl&url
argument_list|)
specifier|const
block|{
return|return
name|url
return|;
block|}
name|QWidgetTextControl
operator|*
name|control
block|;
name|QTextEdit
operator|::
name|AutoFormatting
name|autoFormatting
block|;
name|bool
name|tabChangesFocus
block|;
name|QBasicTimer
name|autoScrollTimer
block|;
name|QPoint
name|autoScrollDragPos
block|;
name|QTextEdit
operator|::
name|LineWrapMode
name|lineWrap
block|;
name|int
name|lineWrapColumnOrWidth
block|;
name|QTextOption
operator|::
name|WrapMode
name|wordWrap
block|;
name|uint
name|ignoreAutomaticScrollbarAdjustment
operator|:
literal|1
block|;
name|uint
name|preferRichText
operator|:
literal|1
block|;
name|uint
name|showCursorOnInitialShow
operator|:
literal|1
block|;
name|uint
name|inDrag
operator|:
literal|1
block|;
name|uint
name|clickCausedFocus
operator|:
literal|1
block|;
comment|// Qt3 COMPAT only, for setText
name|Qt
operator|::
name|TextFormat
name|textFormat
block|;
name|QString
name|anchorToScrollToWhenVisible
block|;
ifdef|#
directive|ifdef
name|QT_KEYPAD_NAVIGATION
name|QBasicTimer
name|deleteAllTimer
block|;
endif|#
directive|endif
block|}
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_TEXTEDIT
end_comment
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QTEXTEDIT_P_H
end_comment
end_unit
