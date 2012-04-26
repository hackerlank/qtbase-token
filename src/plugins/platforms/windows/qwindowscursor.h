begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QWINDOWSCURSOR_H
end_ifndef
begin_define
DECL|macro|QWINDOWSCURSOR_H
define|#
directive|define
name|QWINDOWSCURSOR_H
end_define
begin_include
include|#
directive|include
file|"qtwindows_additional.h"
end_include
begin_include
include|#
directive|include
file|<qpa/qplatformcursor.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/QSharedDataPointer>
end_include
begin_include
include|#
directive|include
file|<QtCore/QHash>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QWindowsWindowCursorData
name|class
name|QWindowsWindowCursorData
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QWindowsWindowCursor
block|{
name|public
label|:
name|explicit
name|QWindowsWindowCursor
parameter_list|(
specifier|const
name|QCursor
modifier|&
name|c
parameter_list|)
function_decl|;
operator|~
name|QWindowsWindowCursor
argument_list|()
expr_stmt|;
name|QWindowsWindowCursor
argument_list|(
specifier|const
name|QWindowsWindowCursor
operator|&
name|c
argument_list|)
expr_stmt|;
name|QWindowsWindowCursor
modifier|&
name|operator
init|=
operator|(
specifier|const
name|QWindowsWindowCursor
operator|&
name|c
operator|)
decl_stmt|;
name|QCursor
name|cursor
argument_list|()
specifier|const
expr_stmt|;
name|HCURSOR
name|handle
argument_list|()
specifier|const
expr_stmt|;
name|private
label|:
name|QSharedDataPointer
operator|<
name|QWindowsWindowCursorData
operator|>
name|m_data
expr_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_decl_stmt
name|class
name|QWindowsCursor
range|:
name|public
name|QPlatformCursor
block|{
name|public
operator|:
name|QWindowsCursor
argument_list|()
block|{}
name|virtual
name|void
name|changeCursor
argument_list|(
name|QCursor
operator|*
name|widgetCursor
argument_list|,
name|QWindow
operator|*
name|widget
argument_list|)
block|;
name|virtual
name|QPoint
name|pos
argument_list|()
specifier|const
block|{
return|return
name|mousePosition
argument_list|()
return|;
block|}
name|virtual
name|void
name|setPos
argument_list|(
specifier|const
name|QPoint
operator|&
name|pos
argument_list|)
block|;
specifier|static
name|HCURSOR
name|createPixmapCursor
argument_list|(
argument|const QPixmap&pixmap
argument_list|,
argument|int hotX
argument_list|,
argument|int hotY
argument_list|)
block|;
specifier|static
name|HCURSOR
name|createSystemCursor
argument_list|(
specifier|const
name|QCursor
operator|&
name|c
argument_list|)
block|;
specifier|static
name|QPoint
name|mousePosition
argument_list|()
block|;
name|QWindowsWindowCursor
name|standardWindowCursor
argument_list|(
argument|Qt::CursorShape s = Qt::ArrowCursor
argument_list|)
block|;
name|private
operator|:
typedef|typedef
name|QHash
operator|<
name|Qt
operator|::
name|CursorShape
operator|,
name|QWindowsWindowCursor
operator|>
name|StandardCursorCache
expr_stmt|;
name|StandardCursorCache
name|m_standardCursorCache
decl_stmt|;
end_decl_stmt
begin_macro
unit|};
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QWINDOWSCURSOR_H
end_comment
end_unit
