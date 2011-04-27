begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** No Commercial Usage ** This file contains pre-release code and may not be distributed. ** You may use this file in accordance with the terms and conditions ** contained in the Technology Preview License Agreement accompanying ** this package. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights.  These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** If you have questions regarding the use of this file, please contact ** Nokia at qt-info@nokia.com. ** ** ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QTIMER_H
end_ifndef
begin_define
DECL|macro|QTIMER_H
define|#
directive|define
name|QTIMER_H
end_define
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_QOBJECT
end_ifndef
begin_include
include|#
directive|include
file|<QtCore/qbasictimer.h>
end_include
begin_comment
comment|// conceptual inheritance
end_comment
begin_include
include|#
directive|include
file|<QtCore/qobject.h>
end_include
begin_decl_stmt
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
DECL|function|QT_MODULE
name|QT_MODULE
argument_list|(
name|Core
argument_list|)
name|class
name|Q_CORE_EXPORT
name|QTimer
range|:
name|public
name|QObject
block|{
name|Q_OBJECT
name|Q_PROPERTY
argument_list|(
argument|bool singleShot READ isSingleShot WRITE setSingleShot
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|int interval READ interval WRITE setInterval
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|bool active READ isActive
argument_list|)
name|public
operator|:
name|explicit
name|QTimer
argument_list|(
name|QObject
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
ifdef|#
directive|ifdef
name|QT3_SUPPORT
name|QT3_SUPPORT_CONSTRUCTOR
name|QTimer
argument_list|(
name|QObject
operator|*
name|parent
argument_list|,
specifier|const
name|char
operator|*
name|name
argument_list|)
block|;
endif|#
directive|endif
operator|~
name|QTimer
argument_list|()
block|;
specifier|inline
name|bool
name|isActive
argument_list|()
specifier|const
block|{
return|return
name|id
operator|>=
literal|0
return|;
block|}
name|int
name|timerId
argument_list|()
specifier|const
block|{
return|return
name|id
return|;
block|}
name|void
name|setInterval
argument_list|(
argument|int msec
argument_list|)
block|;
name|int
name|interval
argument_list|()
specifier|const
block|{
return|return
name|inter
return|;
block|}
specifier|inline
name|void
name|setSingleShot
argument_list|(
argument|bool singleShot
argument_list|)
block|;
specifier|inline
name|bool
name|isSingleShot
argument_list|()
specifier|const
block|{
return|return
name|single
return|;
block|}
specifier|static
name|void
name|singleShot
argument_list|(
argument|int msec
argument_list|,
argument|QObject *receiver
argument_list|,
argument|const char *member
argument_list|)
block|;
name|public
name|Q_SLOTS
operator|:
name|void
name|start
argument_list|(
argument|int msec
argument_list|)
block|;
name|void
name|start
argument_list|()
block|;
name|void
name|stop
argument_list|()
block|;
ifdef|#
directive|ifdef
name|QT3_SUPPORT
specifier|inline
name|QT_MOC_COMPAT
name|void
name|changeInterval
argument_list|(
argument|int msec
argument_list|)
block|{
name|start
argument_list|(
name|msec
argument_list|)
block|; }
name|QT_MOC_COMPAT
name|int
name|start
argument_list|(
argument|int msec
argument_list|,
argument|bool sshot
argument_list|)
block|;
endif|#
directive|endif
name|Q_SIGNALS
operator|:
name|void
name|timeout
argument_list|()
block|;
name|protected
operator|:
name|void
name|timerEvent
argument_list|(
name|QTimerEvent
operator|*
argument_list|)
block|;
name|private
operator|:
name|Q_DISABLE_COPY
argument_list|(
argument|QTimer
argument_list|)
specifier|inline
name|int
name|startTimer
argument_list|(
argument|int
argument_list|)
block|{
return|return
operator|-
literal|1
return|;
block|}
specifier|inline
name|void
name|killTimer
argument_list|(
argument|int
argument_list|)
block|{}
name|int
name|id
block|,
name|inter
block|,
name|del
block|;
name|uint
name|single
operator|:
literal|1
block|;
name|uint
name|nulltimer
operator|:
literal|1
block|; }
decl_stmt|;
end_decl_stmt
begin_expr_stmt
DECL|function|setSingleShot
specifier|inline
name|void
name|QTimer
operator|::
name|setSingleShot
argument_list|(
argument|bool asingleShot
argument_list|)
block|{
name|single
operator|=
name|asingleShot
block|; }
name|QT_END_NAMESPACE
name|QT_END_HEADER
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_QOBJECT
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QTIMER_H
end_comment
end_unit
