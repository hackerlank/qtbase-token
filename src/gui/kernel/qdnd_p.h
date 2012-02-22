begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QDND_P_H
end_ifndef
begin_define
DECL|macro|QDND_P_H
define|#
directive|define
name|QDND_P_H
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
comment|// This file is not part of the Qt API.  It exists for the convenience
end_comment
begin_comment
comment|// of other Qt classes.  This header file may change from version to
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
file|"QtCore/qobject.h"
end_include
begin_include
include|#
directive|include
file|"QtCore/qmap.h"
end_include
begin_include
include|#
directive|include
file|"QtCore/qmimedata.h"
end_include
begin_include
include|#
directive|include
file|"QtGui/qdrag.h"
end_include
begin_include
include|#
directive|include
file|"QtGui/qpixmap.h"
end_include
begin_include
include|#
directive|include
file|"QtGui/qcursor.h"
end_include
begin_include
include|#
directive|include
file|"QtGui/qwindow.h"
end_include
begin_include
include|#
directive|include
file|"QtCore/qpoint.h"
end_include
begin_include
include|#
directive|include
file|"private/qobject_p.h"
end_include
begin_include
include|#
directive|include
file|"QtGui/qbackingstore.h"
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QEventLoop
name|class
name|QEventLoop
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QMouseEvent
name|class
name|QMouseEvent
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QPlatformDrag
name|class
name|QPlatformDrag
decl_stmt|;
end_decl_stmt
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_DRAGANDDROP
end_ifndef
begin_decl_stmt
name|class
name|Q_GUI_EXPORT
name|QInternalMimeData
range|:
name|public
name|QMimeData
block|{
name|Q_OBJECT
name|public
operator|:
name|QInternalMimeData
argument_list|()
block|;
operator|~
name|QInternalMimeData
argument_list|()
block|;
name|bool
name|hasFormat
argument_list|(
argument|const QString&mimeType
argument_list|)
specifier|const
block|;
name|QStringList
name|formats
argument_list|()
specifier|const
block|;
specifier|static
name|bool
name|canReadData
argument_list|(
specifier|const
name|QString
operator|&
name|mimeType
argument_list|)
block|;
specifier|static
name|QStringList
name|formatsHelper
argument_list|(
specifier|const
name|QMimeData
operator|*
name|data
argument_list|)
block|;
specifier|static
name|bool
name|hasFormatHelper
argument_list|(
specifier|const
name|QString
operator|&
name|mimeType
argument_list|,
specifier|const
name|QMimeData
operator|*
name|data
argument_list|)
block|;
specifier|static
name|QByteArray
name|renderDataHelper
argument_list|(
specifier|const
name|QString
operator|&
name|mimeType
argument_list|,
specifier|const
name|QMimeData
operator|*
name|data
argument_list|)
block|;
name|protected
operator|:
name|QVariant
name|retrieveData
argument_list|(
argument|const QString&mimeType
argument_list|,
argument|QVariant::Type type
argument_list|)
specifier|const
block|;
name|virtual
name|bool
name|hasFormat_sys
argument_list|(
argument|const QString&mimeType
argument_list|)
specifier|const
operator|=
literal|0
block|;
name|virtual
name|QStringList
name|formats_sys
argument_list|()
specifier|const
operator|=
literal|0
block|;
name|virtual
name|QVariant
name|retrieveData_sys
argument_list|(
argument|const QString&mimeType
argument_list|,
argument|QVariant::Type type
argument_list|)
specifier|const
operator|=
literal|0
block|; }
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QDragPrivate
range|:
name|public
name|QObjectPrivate
block|{
name|public
operator|:
name|QDragPrivate
argument_list|()
operator|:
name|source
argument_list|(
literal|0
argument_list|)
block|,
name|target
argument_list|(
literal|0
argument_list|)
block|,
name|data
argument_list|(
literal|0
argument_list|)
block|{ }
name|QObject
operator|*
name|source
block|;
name|QObject
operator|*
name|target
block|;
name|QMimeData
operator|*
name|data
block|;
name|QPixmap
name|pixmap
block|;
name|QPoint
name|hotspot
block|;
name|Qt
operator|::
name|DropAction
name|executed_action
block|;
name|Qt
operator|::
name|DropActions
name|supported_actions
block|;
name|Qt
operator|::
name|DropAction
name|default_action
block|;
name|QMap
operator|<
name|Qt
operator|::
name|DropAction
block|,
name|QPixmap
operator|>
name|customCursors
block|; }
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_GUI_EXPORT
name|QDragManager
range|:
name|public
name|QObject
block|{
name|Q_OBJECT
name|public
operator|:
name|QDragManager
argument_list|()
block|;
operator|~
name|QDragManager
argument_list|()
block|;
specifier|static
name|QDragManager
operator|*
name|self
argument_list|()
block|;
name|Qt
operator|::
name|DropAction
name|drag
argument_list|(
name|QDrag
operator|*
argument_list|)
block|;
name|void
name|setCurrentTarget
argument_list|(
argument|QObject *target
argument_list|,
argument|bool dropped = false
argument_list|)
block|;
name|QObject
operator|*
name|currentTarget
argument_list|()
specifier|const
block|;
name|QDrag
operator|*
name|object
argument_list|()
specifier|const
block|{
return|return
name|m_object
return|;
block|}
name|QObject
operator|*
name|source
argument_list|()
specifier|const
block|;
name|private
operator|:
name|QMimeData
operator|*
name|m_platformDropData
block|;
name|QObject
operator|*
name|m_currentDropTarget
block|;
name|QPlatformDrag
operator|*
name|m_platformDrag
block|;
name|QDrag
operator|*
name|m_object
block|;
specifier|static
name|QDragManager
operator|*
name|m_instance
block|;
name|Q_DISABLE_COPY
argument_list|(
argument|QDragManager
argument_list|)
block|}
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// !QT_NO_DRAGANDDROP
end_comment
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QDND_P_H
end_comment
end_unit
