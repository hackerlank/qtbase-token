begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QMOVIE_H
end_ifndef
begin_define
DECL|macro|QMOVIE_H
define|#
directive|define
name|QMOVIE_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qobject.h>
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_MOVIE
end_ifndef
begin_include
include|#
directive|include
file|<QtCore/qbytearray.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qlist.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qobject.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/qimagereader.h>
end_include
begin_decl_stmt
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
name|QT_MODULE
argument_list|(
name|Gui
argument_list|)
name|class
name|QByteArray
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QColor
name|class
name|QColor
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QIODevice
name|class
name|QIODevice
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QImage
name|class
name|QImage
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QPixmap
name|class
name|QPixmap
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QRect
name|class
name|QRect
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QSize
name|class
name|QSize
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QMoviePrivate
name|class
name|QMoviePrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_GUI_EXPORT
name|QMovie
range|:
name|public
name|QObject
block|{
name|Q_OBJECT
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QMovie
argument_list|)
name|Q_ENUMS
argument_list|(
argument|MovieState CacheMode
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|int speed READ speed WRITE setSpeed
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|CacheMode cacheMode READ cacheMode WRITE setCacheMode
argument_list|)
name|public
operator|:
expr|enum
name|MovieState
block|{
name|NotRunning
block|,
name|Paused
block|,
name|Running
block|}
block|;     enum
name|CacheMode
block|{
name|CacheNone
block|,
name|CacheAll
block|}
block|;
name|QMovie
argument_list|(
name|QObject
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
name|explicit
name|QMovie
argument_list|(
name|QIODevice
operator|*
name|device
argument_list|,
specifier|const
name|QByteArray
operator|&
name|format
operator|=
name|QByteArray
argument_list|()
argument_list|,
name|QObject
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
name|explicit
name|QMovie
argument_list|(
specifier|const
name|QString
operator|&
name|fileName
argument_list|,
specifier|const
name|QByteArray
operator|&
name|format
operator|=
name|QByteArray
argument_list|()
argument_list|,
name|QObject
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
operator|~
name|QMovie
argument_list|()
block|;
specifier|static
name|QList
operator|<
name|QByteArray
operator|>
name|supportedFormats
argument_list|()
block|;
name|void
name|setDevice
argument_list|(
name|QIODevice
operator|*
name|device
argument_list|)
block|;
name|QIODevice
operator|*
name|device
argument_list|()
specifier|const
block|;
name|void
name|setFileName
argument_list|(
specifier|const
name|QString
operator|&
name|fileName
argument_list|)
block|;
name|QString
name|fileName
argument_list|()
specifier|const
block|;
name|void
name|setFormat
argument_list|(
specifier|const
name|QByteArray
operator|&
name|format
argument_list|)
block|;
name|QByteArray
name|format
argument_list|()
specifier|const
block|;
name|void
name|setBackgroundColor
argument_list|(
specifier|const
name|QColor
operator|&
name|color
argument_list|)
block|;
name|QColor
name|backgroundColor
argument_list|()
specifier|const
block|;
name|MovieState
name|state
argument_list|()
specifier|const
block|;
name|QRect
name|frameRect
argument_list|()
specifier|const
block|;
name|QImage
name|currentImage
argument_list|()
specifier|const
block|;
name|QPixmap
name|currentPixmap
argument_list|()
specifier|const
block|;
name|bool
name|isValid
argument_list|()
specifier|const
block|;
name|bool
name|jumpToFrame
argument_list|(
argument|int frameNumber
argument_list|)
block|;
name|int
name|loopCount
argument_list|()
specifier|const
block|;
name|int
name|frameCount
argument_list|()
specifier|const
block|;
name|int
name|nextFrameDelay
argument_list|()
specifier|const
block|;
name|int
name|currentFrameNumber
argument_list|()
specifier|const
block|;
name|int
name|speed
argument_list|()
specifier|const
block|;
name|QSize
name|scaledSize
argument_list|()
block|;
name|void
name|setScaledSize
argument_list|(
specifier|const
name|QSize
operator|&
name|size
argument_list|)
block|;
name|CacheMode
name|cacheMode
argument_list|()
specifier|const
block|;
name|void
name|setCacheMode
argument_list|(
argument|CacheMode mode
argument_list|)
block|;
name|CacheMode
name|cacheMode
argument_list|()
block|;
comment|// ### Qt 5: remove me
name|Q_SIGNALS
operator|:
name|void
name|started
argument_list|()
block|;
name|void
name|resized
argument_list|(
specifier|const
name|QSize
operator|&
name|size
argument_list|)
block|;
name|void
name|updated
argument_list|(
specifier|const
name|QRect
operator|&
name|rect
argument_list|)
block|;
name|void
name|stateChanged
argument_list|(
argument|QMovie::MovieState state
argument_list|)
block|;
name|void
name|error
argument_list|(
argument|QImageReader::ImageReaderError error
argument_list|)
block|;
name|void
name|finished
argument_list|()
block|;
name|void
name|frameChanged
argument_list|(
argument|int frameNumber
argument_list|)
block|;
name|public
name|Q_SLOTS
operator|:
name|void
name|start
argument_list|()
block|;
name|bool
name|jumpToNextFrame
argument_list|()
block|;
name|void
name|setPaused
argument_list|(
argument|bool paused
argument_list|)
block|;
name|void
name|stop
argument_list|()
block|;
name|void
name|setSpeed
argument_list|(
argument|int percentSpeed
argument_list|)
block|;
name|private
operator|:
name|Q_DISABLE_COPY
argument_list|(
argument|QMovie
argument_list|)
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_loadNextFrame()
argument_list|)
block|}
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
comment|// QT_NO_MOVIE
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QMOVIE_H
end_comment
end_unit
