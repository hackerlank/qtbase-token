begin_unit
begin_comment
comment|/*************************************************************************** ** ** Copyright (C) 2011 - 2012 Research In Motion ** Contact: http://www.qt-project.org/legal ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia. For licensing terms and ** conditions see http://qt.digia.com/licensing. For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights. These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qqnxcursor.h"
end_include
begin_include
include|#
directive|include
file|<QtCore/QDebug>
end_include
begin_if
if|#
directive|if
name|defined
argument_list|(
name|QQNXCURSOR_DEBUG
argument_list|)
end_if
begin_define
DECL|macro|qCursorDebug
define|#
directive|define
name|qCursorDebug
value|qDebug
end_define
begin_else
else|#
directive|else
end_else
begin_define
DECL|macro|qCursorDebug
define|#
directive|define
name|qCursorDebug
value|QT_NO_QDEBUG_MACRO
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_function
name|QT_BEGIN_NAMESPACE
DECL|function|QQnxCursor
name|QQnxCursor
operator|::
name|QQnxCursor
parameter_list|()
block|{ }
end_function
begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|QT_NO_CURSOR
argument_list|)
end_if
begin_function
DECL|function|changeCursor
name|void
name|QQnxCursor
operator|::
name|changeCursor
parameter_list|(
name|QCursor
modifier|*
name|windowCursor
parameter_list|,
name|QWindow
modifier|*
name|window
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
name|windowCursor
argument_list|)
expr_stmt|;
name|Q_UNUSED
argument_list|(
name|window
argument_list|)
expr_stmt|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_function
DECL|function|setPos
name|void
name|QQnxCursor
operator|::
name|setPos
parameter_list|(
specifier|const
name|QPoint
modifier|&
name|pos
parameter_list|)
block|{
name|qCursorDebug
argument_list|()
operator|<<
literal|"QQnxCursor::setPos -"
operator|<<
name|pos
expr_stmt|;
name|m_pos
operator|=
name|pos
expr_stmt|;
block|}
end_function
begin_function
DECL|function|pos
name|QPoint
name|QQnxCursor
operator|::
name|pos
parameter_list|()
specifier|const
block|{
name|qCursorDebug
argument_list|()
operator|<<
literal|"QQnxCursor::pos -"
operator|<<
name|m_pos
expr_stmt|;
return|return
name|m_pos
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
