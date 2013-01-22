begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QINPUTMETHOD_H
end_ifndef
begin_define
DECL|macro|QINPUTMETHOD_H
define|#
directive|define
name|QINPUTMETHOD_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qobject.h>
end_include
begin_decl_stmt
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
DECL|variable|QInputMethodPrivate
name|class
name|QInputMethodPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QWindow
name|class
name|QWindow
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QRectF
name|class
name|QRectF
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QTransform
name|class
name|QTransform
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_GUI_EXPORT
name|QInputMethod
range|:
name|public
name|QObject
block|{
name|Q_OBJECT
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QInputMethod
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|QRectF cursorRectangle READ cursorRectangle NOTIFY cursorRectangleChanged
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|QRectF keyboardRectangle READ keyboardRectangle NOTIFY keyboardRectangleChanged
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|bool visible READ isVisible NOTIFY visibleChanged
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|bool animating READ isAnimating NOTIFY animatingChanged
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|QLocale locale READ locale NOTIFY localeChanged
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|Qt::LayoutDirection inputDirection READ inputDirection NOTIFY inputDirectionChanged
argument_list|)
name|Q_ENUMS
argument_list|(
argument|Action
argument_list|)
name|public
operator|:
name|QTransform
name|inputItemTransform
argument_list|()
specifier|const
block|;
name|void
name|setInputItemTransform
argument_list|(
specifier|const
name|QTransform
operator|&
name|transform
argument_list|)
block|;
comment|// in window coordinates
name|QRectF
name|cursorRectangle
argument_list|()
specifier|const
block|;
comment|// ### what if we have rotations for the item?
comment|// keyboard geometry in window coords
name|QRectF
name|keyboardRectangle
argument_list|()
specifier|const
block|;      enum
name|Action
block|{
name|Click
block|,
name|ContextMenu
block|}
block|;
name|bool
name|isVisible
argument_list|()
specifier|const
block|;
name|void
name|setVisible
argument_list|(
argument|bool visible
argument_list|)
block|;
name|bool
name|isAnimating
argument_list|()
specifier|const
block|;
name|QLocale
name|locale
argument_list|()
specifier|const
block|;
name|Qt
operator|::
name|LayoutDirection
name|inputDirection
argument_list|()
specifier|const
block|;
name|public
name|Q_SLOTS
operator|:
name|void
name|show
argument_list|()
block|;
name|void
name|hide
argument_list|()
block|;
name|void
name|update
argument_list|(
argument|Qt::InputMethodQueries queries
argument_list|)
block|;
name|void
name|reset
argument_list|()
block|;
name|void
name|commit
argument_list|()
block|;
name|void
name|invokeAction
argument_list|(
argument|Action a
argument_list|,
argument|int cursorPosition
argument_list|)
block|;
name|Q_SIGNALS
operator|:
name|void
name|cursorRectangleChanged
argument_list|()
block|;
name|void
name|keyboardRectangleChanged
argument_list|()
block|;
name|void
name|visibleChanged
argument_list|()
block|;
name|void
name|animatingChanged
argument_list|()
block|;
name|void
name|localeChanged
argument_list|()
block|;
name|void
name|inputDirectionChanged
argument_list|(
argument|Qt::LayoutDirection newDirection
argument_list|)
block|;
name|private
operator|:
name|friend
name|class
name|QGuiApplication
block|;
name|friend
name|class
name|QGuiApplicationPrivate
block|;
name|friend
name|class
name|QPlatformInputContext
block|;
name|QInputMethod
argument_list|()
block|;
operator|~
name|QInputMethod
argument_list|()
block|; }
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|QT_END_NAMESPACE
name|QT_END_HEADER
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
end_unit
