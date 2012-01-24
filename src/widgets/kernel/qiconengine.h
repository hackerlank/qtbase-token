begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QICONENGINE_H
end_ifndef
begin_define
DECL|macro|QICONENGINE_H
define|#
directive|define
name|QICONENGINE_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qglobal.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qlist.h>
end_include
begin_include
include|#
directive|include
file|<QtWidgets/qicon.h>
end_include
begin_decl_stmt
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
name|class
name|Q_WIDGETS_EXPORT
name|QIconEngine
block|{
name|public
label|:
name|virtual
operator|~
name|QIconEngine
argument_list|()
expr_stmt|;
name|virtual
name|void
name|paint
argument_list|(
name|QPainter
operator|*
name|painter
argument_list|,
specifier|const
name|QRect
operator|&
name|rect
argument_list|,
name|QIcon
operator|::
name|Mode
name|mode
argument_list|,
name|QIcon
operator|::
name|State
name|state
argument_list|)
init|=
literal|0
decl_stmt|;
name|virtual
name|QSize
name|actualSize
argument_list|(
specifier|const
name|QSize
operator|&
name|size
argument_list|,
name|QIcon
operator|::
name|Mode
name|mode
argument_list|,
name|QIcon
operator|::
name|State
name|state
argument_list|)
decl_stmt|;
name|virtual
name|QPixmap
name|pixmap
argument_list|(
specifier|const
name|QSize
operator|&
name|size
argument_list|,
name|QIcon
operator|::
name|Mode
name|mode
argument_list|,
name|QIcon
operator|::
name|State
name|state
argument_list|)
decl_stmt|;
name|virtual
name|void
name|addPixmap
argument_list|(
specifier|const
name|QPixmap
operator|&
name|pixmap
argument_list|,
name|QIcon
operator|::
name|Mode
name|mode
argument_list|,
name|QIcon
operator|::
name|State
name|state
argument_list|)
decl_stmt|;
name|virtual
name|void
name|addFile
argument_list|(
specifier|const
name|QString
operator|&
name|fileName
argument_list|,
specifier|const
name|QSize
operator|&
name|size
argument_list|,
name|QIcon
operator|::
name|Mode
name|mode
argument_list|,
name|QIcon
operator|::
name|State
name|state
argument_list|)
decl_stmt|;
if|#
directive|if
literal|0
block|virtual int frameCount(QIcon::Mode fromMode, QIcon::State fromState, QIcon::Mode toMode, QIcon::State toState);     virtual void paintFrame(QPainter *painter, const QRect&rect, int frameNumber, QIcon::Mode fromMode, QIcon::State fromState, QIcon::Mode toMode, QIcon::State toState);
endif|#
directive|endif
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_comment
comment|// ### Qt 5: move the below into QIconEngine
end_comment
begin_decl_stmt
name|class
name|Q_WIDGETS_EXPORT
name|QIconEngineV2
range|:
name|public
name|QIconEngine
block|{
name|public
operator|:
name|virtual
name|QString
name|key
argument_list|()
specifier|const
block|;
name|virtual
name|QIconEngineV2
operator|*
name|clone
argument_list|()
specifier|const
block|;
name|virtual
name|bool
name|read
argument_list|(
name|QDataStream
operator|&
name|in
argument_list|)
block|;
name|virtual
name|bool
name|write
argument_list|(
argument|QDataStream&out
argument_list|)
specifier|const
block|;
name|virtual
name|void
name|virtual_hook
argument_list|(
argument|int id
argument_list|,
argument|void *data
argument_list|)
block|;
name|public
operator|:
expr|enum
name|IconEngineHook
block|{
name|AvailableSizesHook
operator|=
literal|1
block|,
name|IconNameHook
block|}
block|;      struct
name|AvailableSizesArgument
block|{
name|QIcon
operator|::
name|Mode
name|mode
block|;
name|QIcon
operator|::
name|State
name|state
block|;
name|QList
operator|<
name|QSize
operator|>
name|sizes
block|;     }
block|;
comment|// ### Qt 5: make this function const and virtual.
name|QList
operator|<
name|QSize
operator|>
name|availableSizes
argument_list|(
argument|QIcon::Mode mode = QIcon::Normal
argument_list|,
argument|QIcon::State state = QIcon::Off
argument_list|)
block|;
comment|// ### Qt 5: make this function const and virtual.
name|QString
name|iconName
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
begin_comment
comment|// QICONENGINE_H
end_comment
end_unit
