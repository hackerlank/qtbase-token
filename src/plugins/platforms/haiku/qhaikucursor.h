begin_unit
begin_comment
comment|/*************************************************************************** ** ** Copyright (C) 2015 KlarÃ¤lvdalens Datakonsult AB, a KDAB Group company, info@kdab.com, author Tobias Koenig<tobias.koenig@kdab.com> ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QHAIKUCURSOR_H
end_ifndef
begin_define
DECL|macro|QHAIKUCURSOR_H
define|#
directive|define
name|QHAIKUCURSOR_H
end_define
begin_include
include|#
directive|include
file|<qpa/qplatformcursor.h>
end_include
begin_include
include|#
directive|include
file|<Cursor.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
name|class
name|QHaikuCursor
range|:
name|public
name|QPlatformCursor
block|{
name|public
operator|:
name|QHaikuCursor
argument_list|()
block|;
ifndef|#
directive|ifndef
name|QT_NO_CURSOR
name|void
name|changeCursor
argument_list|(
argument|QCursor *windowCursor
argument_list|,
argument|QWindow *window
argument_list|)
name|Q_DECL_OVERRIDE
block|;
endif|#
directive|endif
name|private
operator|:
name|QHash
operator|<
name|Qt
operator|::
name|CursorShape
block|,
name|BCursorID
operator|>
name|m_cursorIds
block|;
name|QHash
operator|<
name|Qt
operator|::
name|CursorShape
block|,
name|BCursor
operator|*
operator|>
name|m_cursors
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
