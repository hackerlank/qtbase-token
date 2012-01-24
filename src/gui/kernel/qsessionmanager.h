begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QSESSIONMANAGER_H
end_ifndef
begin_define
DECL|macro|QSESSIONMANAGER_H
define|#
directive|define
name|QSESSIONMANAGER_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qobject.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/qwindowdefs.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qstring.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qstringlist.h>
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_SESSIONMANAGER
end_ifndef
begin_decl_stmt
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
DECL|variable|QGuiApplication
name|class
name|QGuiApplication
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QSessionManagerPrivate
name|class
name|QSessionManagerPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_GUI_EXPORT
name|QSessionManager
range|:
name|public
name|QObject
block|{
name|Q_OBJECT
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QSessionManager
argument_list|)
name|QSessionManager
argument_list|(
name|QGuiApplication
operator|*
name|app
argument_list|,
name|QString
operator|&
name|id
argument_list|,
name|QString
operator|&
name|key
argument_list|)
block|;
operator|~
name|QSessionManager
argument_list|()
block|;
name|public
operator|:
name|QString
name|sessionId
argument_list|()
specifier|const
block|;
name|QString
name|sessionKey
argument_list|()
specifier|const
block|;
name|bool
name|allowsInteraction
argument_list|()
block|;
name|bool
name|allowsErrorInteraction
argument_list|()
block|;
name|void
name|release
argument_list|()
block|;
name|void
name|cancel
argument_list|()
block|;      enum
name|RestartHint
block|{
name|RestartIfRunning
block|,
name|RestartAnyway
block|,
name|RestartImmediately
block|,
name|RestartNever
block|}
block|;
name|void
name|setRestartHint
argument_list|(
name|RestartHint
argument_list|)
block|;
name|RestartHint
name|restartHint
argument_list|()
specifier|const
block|;
name|void
name|setRestartCommand
argument_list|(
specifier|const
name|QStringList
operator|&
argument_list|)
block|;
name|QStringList
name|restartCommand
argument_list|()
specifier|const
block|;
name|void
name|setDiscardCommand
argument_list|(
specifier|const
name|QStringList
operator|&
argument_list|)
block|;
name|QStringList
name|discardCommand
argument_list|()
specifier|const
block|;
name|void
name|setManagerProperty
argument_list|(
specifier|const
name|QString
operator|&
name|name
argument_list|,
specifier|const
name|QString
operator|&
name|value
argument_list|)
block|;
name|void
name|setManagerProperty
argument_list|(
specifier|const
name|QString
operator|&
name|name
argument_list|,
specifier|const
name|QStringList
operator|&
name|value
argument_list|)
block|;
name|bool
name|isPhase2
argument_list|()
specifier|const
block|;
name|void
name|requestPhase2
argument_list|()
block|;
name|private
operator|:
name|friend
name|class
name|QApplication
block|;
name|friend
name|class
name|QApplicationPrivate
block|;
name|friend
name|class
name|QBaseApplication
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
begin_comment
comment|// QT_NO_SESSIONMANAGER
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QSESSIONMANAGER_H
end_comment
end_unit
