begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** No Commercial Usage ** This file contains pre-release code and may not be distributed. ** You may use this file in accordance with the terms and conditions ** contained in the Technology Preview License Agreement accompanying ** this package. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights.  These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** If you have questions regarding the use of this file, please contact ** Nokia at qt-info@nokia.com. ** ** ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QLINEEDIT_P_H
end_ifndef
begin_define
DECL|macro|QLINEEDIT_P_H
define|#
directive|define
name|QLINEEDIT_P_H
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
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_LINEEDIT
end_ifndef
begin_include
include|#
directive|include
file|"private/qwidget_p.h"
end_include
begin_include
include|#
directive|include
file|"QtGui/qlineedit.h"
end_include
begin_include
include|#
directive|include
file|"QtGui/qtextlayout.h"
end_include
begin_include
include|#
directive|include
file|"QtGui/qstyleoption.h"
end_include
begin_include
include|#
directive|include
file|"QtCore/qbasictimer.h"
end_include
begin_include
include|#
directive|include
file|"QtGui/qcompleter.h"
end_include
begin_include
include|#
directive|include
file|"QtCore/qpointer.h"
end_include
begin_include
include|#
directive|include
file|"QtGui/qlineedit.h"
end_include
begin_include
include|#
directive|include
file|"private/qlinecontrol_p.h"
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
name|class
name|QLineEditPrivate
range|:
name|public
name|QWidgetPrivate
block|{
name|Q_DECLARE_PUBLIC
argument_list|(
argument|QLineEdit
argument_list|)
name|public
operator|:
name|QLineEditPrivate
argument_list|()
operator|:
name|control
argument_list|(
literal|0
argument_list|)
block|,
name|frame
argument_list|(
literal|1
argument_list|)
block|,
name|contextMenuEnabled
argument_list|(
literal|1
argument_list|)
block|,
name|cursorVisible
argument_list|(
literal|0
argument_list|)
block|,
name|dragEnabled
argument_list|(
literal|0
argument_list|)
block|,
name|clickCausedFocus
argument_list|(
literal|0
argument_list|)
block|,
name|hscroll
argument_list|(
literal|0
argument_list|)
block|,
name|vscroll
argument_list|(
literal|0
argument_list|)
block|,
name|alignment
argument_list|(
name|Qt
operator|::
name|AlignLeading
operator||
name|Qt
operator|::
name|AlignVCenter
argument_list|)
block|,
name|leftTextMargin
argument_list|(
literal|0
argument_list|)
block|,
name|topTextMargin
argument_list|(
literal|0
argument_list|)
block|,
name|rightTextMargin
argument_list|(
literal|0
argument_list|)
block|,
name|bottomTextMargin
argument_list|(
literal|0
argument_list|)
block|{     }
operator|~
name|QLineEditPrivate
argument_list|()
block|{
name|delete
name|control
block|;     }
name|QLineControl
operator|*
name|control
block|;
ifndef|#
directive|ifndef
name|QT_NO_CONTEXTMENU
name|QPointer
operator|<
name|QAction
operator|>
name|selectAllAction
block|;
endif|#
directive|endif
name|void
name|init
argument_list|(
specifier|const
name|QString
operator|&
argument_list|)
block|;
name|QRect
name|adjustedControlRect
argument_list|(
argument|const QRect&
argument_list|)
specifier|const
block|;
name|int
name|xToPos
argument_list|(
argument|int x
argument_list|,
argument|QTextLine::CursorPosition = QTextLine::CursorBetweenCharacters
argument_list|)
specifier|const
block|;
name|QRect
name|cursorRect
argument_list|()
specifier|const
block|;
name|void
name|setCursorVisible
argument_list|(
argument|bool visible
argument_list|)
block|;
name|void
name|updatePasswordEchoEditing
argument_list|(
name|bool
argument_list|)
block|;
specifier|inline
name|bool
name|shouldEnableInputMethod
argument_list|()
specifier|const
block|{
return|return
operator|!
name|control
operator|->
name|isReadOnly
argument_list|()
return|;
block|}
name|QPoint
name|tripleClick
block|;
name|QBasicTimer
name|tripleClickTimer
block|;
name|uint
name|frame
operator|:
literal|1
block|;
name|uint
name|contextMenuEnabled
operator|:
literal|1
block|;
name|uint
name|cursorVisible
operator|:
literal|1
block|;
name|uint
name|dragEnabled
operator|:
literal|1
block|;
name|uint
name|clickCausedFocus
operator|:
literal|1
block|;
name|int
name|hscroll
block|;
name|int
name|vscroll
block|;
name|uint
name|alignment
block|;
specifier|static
specifier|const
name|int
name|verticalMargin
block|;
specifier|static
specifier|const
name|int
name|horizontalMargin
block|;
name|bool
name|sendMouseEventToInputContext
argument_list|(
name|QMouseEvent
operator|*
name|e
argument_list|)
block|;
name|QRect
name|adjustedContentsRect
argument_list|()
specifier|const
block|;
name|void
name|_q_handleWindowActivate
argument_list|()
block|;
name|void
name|_q_textEdited
argument_list|(
specifier|const
name|QString
operator|&
argument_list|)
block|;
name|void
name|_q_cursorPositionChanged
argument_list|(
name|int
argument_list|,
name|int
argument_list|)
block|;
ifdef|#
directive|ifdef
name|QT_KEYPAD_NAVIGATION
name|void
name|_q_editFocusChange
argument_list|(
name|bool
argument_list|)
block|;
endif|#
directive|endif
name|void
name|_q_selectionChanged
argument_list|()
block|;
name|void
name|_q_updateNeeded
argument_list|(
specifier|const
name|QRect
operator|&
argument_list|)
block|;
ifndef|#
directive|ifndef
name|QT_NO_COMPLETER
name|void
name|_q_completionHighlighted
argument_list|(
name|QString
argument_list|)
block|;
endif|#
directive|endif
ifndef|#
directive|ifndef
name|QT_NO_DRAGANDDROP
name|QPoint
name|dndPos
block|;
name|QBasicTimer
name|dndTimer
block|;
name|void
name|drag
argument_list|()
block|;
endif|#
directive|endif
name|int
name|leftTextMargin
block|;
name|int
name|topTextMargin
block|;
name|int
name|rightTextMargin
block|;
name|int
name|bottomTextMargin
block|;
name|QString
name|placeholderText
block|; }
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
comment|// QLINEEDIT_P_H
end_comment
end_unit
