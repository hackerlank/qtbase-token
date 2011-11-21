begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QIBUSPLATFORMINPUTCONTEXT_H
end_ifndef
begin_define
DECL|macro|QIBUSPLATFORMINPUTCONTEXT_H
define|#
directive|define
name|QIBUSPLATFORMINPUTCONTEXT_H
end_define
begin_include
include|#
directive|include
file|<QPlatformInputContext>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QIBusPlatformInputContextPrivate
name|class
name|QIBusPlatformInputContextPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QDBusVariant
name|class
name|QDBusVariant
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QIBusPlatformInputContext
range|:
name|public
name|QPlatformInputContext
block|{
name|Q_OBJECT
name|public
operator|:
name|QIBusPlatformInputContext
argument_list|()
block|;
operator|~
name|QIBusPlatformInputContext
argument_list|()
block|;
name|bool
name|isValid
argument_list|()
specifier|const
block|;
name|void
name|invokeAction
argument_list|(
argument|QInputPanel::Action a
argument_list|,
argument|int x
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
name|update
argument_list|(
name|Qt
operator|::
name|InputMethodQueries
argument_list|)
block|;
name|Q_INVOKABLE
name|bool
name|x11FilterEvent
argument_list|(
argument|uint keyval
argument_list|,
argument|uint keycode
argument_list|,
argument|uint state
argument_list|,
argument|bool press
argument_list|)
block|;
name|public
name|Q_SLOTS
operator|:
name|void
name|commitText
argument_list|(
specifier|const
name|QDBusVariant
operator|&
name|text
argument_list|)
block|;
name|void
name|updatePreeditText
argument_list|(
argument|const QDBusVariant&text
argument_list|,
argument|uint cursor_pos
argument_list|,
argument|bool visible
argument_list|)
block|;
name|void
name|inputItemChanged
argument_list|()
block|;
name|void
name|cursorRectChanged
argument_list|()
block|;
name|private
operator|:
name|QIBusPlatformInputContextPrivate
operator|*
name|d
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
end_unit
